#include "models/water/watersurfacesim.h"

#include <algorithm>
#include <cmath>
#include <cstring>

idWaterSurfaceSim::GlobalToLocalCallback
    idWaterSurfaceSim::globalToLocalCallback = nullptr;
idWaterSurfaceSim::LocalToGlobalCallback
    idWaterSurfaceSim::localToGlobalCallback = nullptr;

namespace {

unsigned char ToByte(float value) {
    const int scaled = static_cast<int>(value * 255.0f);
    return static_cast<unsigned char>((std::max)(0, (std::min)(255, scaled)));
}

} // namespace

idWaterSurfaceSim::idWaterSurfaceSim(const idBounds& bounds,
        const float requestedSpacing, const float newDamping,
        const float newSpeed, const float newTimeStep)
    : width(0)
    , height(0)
    , spacing(requestedSpacing)
    , damping(newDamping)
    , speed(newSpeed)
    , timeStep(newTimeStep)
    , visible(false)
    , origin(0.0f, 0.0f, 0.0f)
    , rnd(0)
    , currentDeferred(0)
    , numDisturbances(0)
    , allocWidth(0)
    , allocHeight(0)
    , numBlocksX(0)
    , numBlocksY(0) {
    const float extentX = (std::max)(0.0f, bounds[1].x - bounds[0].x);
    const float extentY = (std::max)(0.0f, bounds[1].y - bounds[0].y);
    origin.Set(bounds[0].x, bounds[0].y, bounds[1].z);

    const float minimumSpacing = std::sqrt(extentX * extentY / 65536.0f);
    spacing = (std::max)(requestedSpacing, minimumSpacing);
    if (spacing <= 0.0f) {
        spacing = 1.0f;
    }

    width = static_cast<unsigned int>(std::floor(
        std::ceil(extentX) / spacing));
    height = static_cast<unsigned int>(std::floor(
        std::ceil(extentY) / spacing));
    width = (std::max)(2u, width);
    height = (std::max)(2u, height);
    allocWidth = (static_cast<int>(width) + 15) & ~15;
    allocHeight = (static_cast<int>(height) + 15) & ~15;
    numBlocksX = allocWidth >> 4;
    numBlocksY = allocHeight >> 4;
    const int cellCount = allocWidth * allocHeight;

    for (int buffer = 0; buffer < 2; ++buffer) {
        waveHeight[buffer].SetNum(cellCount);
        std::fill(waveHeight[buffer].Ptr(),
            waveHeight[buffer].Ptr() + cellCount, 0.0f);
        waterDisturbances[buffer].SetNum(100);
        std::memset(waterDisturbances[buffer].Ptr(), 0,
            sizeof(waterDisturbanceParms_t) * 100);
    }
    dummyBlock.SetNum(256);
    std::fill(dummyBlock.Ptr(), dummyBlock.Ptr() + dummyBlock.Num(), 0.0f);
    simulateParms.SetNum(cellCount);
    std::fill(simulateParms.Ptr(), simulateParms.Ptr() + cellCount, 0u);
    vertGradient.SetNum(cellCount);
    std::fill(vertGradient.Ptr(), vertGradient.Ptr() + cellCount,
        static_cast<unsigned char>(255));
}

void idWaterSurfaceSim::SetGlobalToLocalCallback(
        GlobalToLocalCallback callback) {
    globalToLocalCallback = callback;
}

void idWaterSurfaceSim::SetCoordinateTransformCallbacks(
        GlobalToLocalCallback globalToLocal,
        LocalToGlobalCallback localToGlobal) {
    globalToLocalCallback = globalToLocal;
    localToGlobalCallback = localToGlobal;
}

float idWaterSurfaceSim::GetTimeStep() const {
    return timeStep;
}

void idWaterSurfaceSim::Swap() {
    currentDeferred ^= 1;
    numDisturbances = 0;
}

void idWaterSurfaceSim::GlobalToLocalPos(const idVec3& globalPosition,
        idVec3& localPosition, const idRenderModel* renderModel) const {
    if (globalToLocalCallback != nullptr && renderModel != nullptr) {
        globalToLocalCallback(renderModel, globalPosition, localPosition);
    } else {
        localPosition = globalPosition;
    }
    localPosition = localPosition - origin;
}

void idWaterSurfaceSim::LocalToGridSpacePos(const idVec3& localPosition,
        int& x, int& y) const {
    x = static_cast<int>(std::floor(localPosition.x / spacing + 0.5f));
    y = static_cast<int>(std::floor(localPosition.y / spacing + 0.5f));
}

void idWaterSurfaceSim::SetupLocalPos(idVec3& result, const int gridX,
        const int gridY, const float* const previousHeightMap) const {
    result.x = static_cast<float>(gridX) * spacing;
    result.y = static_cast<float>(gridY) * spacing;
    const int index = GridIndex(gridX, gridY);
    result.z = index >= 0 && previousHeightMap != nullptr
        ? previousHeightMap[index] : 0.0f;
}

int idWaterSurfaceSim::GridIndex(const int gridX, const int gridY) const {
    if (gridX < 0 || gridY < 0 || gridX >= allocWidth ||
            gridY >= allocHeight) {
        return -1;
    }
    const int blockX = gridX >> 4;
    const int blockY = gridY >> 4;
    const int inBlockX = gridX & 15;
    const int inBlockY = gridY & 15;
    return ((blockY * numBlocksX + blockX) << 8) +
        (inBlockY << 4) + inBlockX;
}

waterDisturbanceParms_t* idWaterSurfaceSim::AllocateDisturbance() {
    if (!visible || numDisturbances >= 100) {
        return nullptr;
    }
    waterDisturbanceParms_t* disturbance =
        &waterDisturbances[currentDeferred][numDisturbances++];
    std::memset(disturbance, 0, sizeof(*disturbance));
    return disturbance;
}

void idWaterSurfaceSim::AddRipple(const idVec3& position,
        const float magnitude, const float rippleRadius,
        const idRenderModel* renderModel) {
    waterDisturbanceParms_t* disturbance = AllocateDisturbance();
    if (disturbance == nullptr) {
        return;
    }
    idVec3 localPosition;
    GlobalToLocalPos(position, localPosition, renderModel);
    LocalToGridSpacePos(localPosition, disturbance->gridX,
        disturbance->gridY);
    disturbance->type = WATER_DISTURBANCE_TYPE_RIPPLE;
    disturbance->loc.Set(localPosition.x, localPosition.y);
    disturbance->parms.x = magnitude;
    disturbance->radius = rippleRadius;
}

void idWaterSurfaceSim::AddFancyRipple(const idVec3& position,
        const idRenderModel* renderModel, const float amplitude,
        const float frequency, const float fadeStart, const float fadeEnd,
        const float currentDistance) {
    waterDisturbanceParms_t* disturbance = AllocateDisturbance();
    if (disturbance == nullptr) {
        return;
    }
    idVec3 localPosition;
    GlobalToLocalPos(position, localPosition, renderModel);
    disturbance->type = WATER_DISTURBANCE_TYPE_FANCY_RIPPLE;
    disturbance->loc.Set(localPosition.x, localPosition.y);
    disturbance->parms.Set(amplitude, frequency, fadeStart, fadeEnd);
    disturbance->currentDistance = currentDistance;
}

void idWaterSurfaceSim::AddDrop(const unsigned int x, const unsigned int y,
        const float dropRadius, const float magnitude) {
    waterDisturbanceParms_t* disturbance = AllocateDisturbance();
    if (disturbance == nullptr) {
        return;
    }
    disturbance->type = WATER_DISTURBANCE_TYPE_DROPLET;
    disturbance->gridX = static_cast<int>(x);
    disturbance->gridY = static_cast<int>(y);
    disturbance->parms.x = magnitude;
    disturbance->radius = dropRadius;
}

void idWaterSurfaceSim::AddWave(const idVec2& direction,
        const float frequency, const float phase, const float amplitude,
        const float waveExponent) {
    waterDisturbanceParms_t* disturbance = AllocateDisturbance();
    if (disturbance == nullptr) {
        return;
    }
    disturbance->type = WATER_DISTURBANCE_TYPE_WAVE;
    disturbance->loc = direction;
    disturbance->parms.Set(amplitude, frequency, phase, waveExponent);
}

void idWaterSurfaceSim::SetSimulationParms(const unsigned int gridX,
        const unsigned int gridY, const idVec4& parms) {
    const int index = GridIndex(static_cast<int>(gridX),
        static_cast<int>(gridY));
    if (index < 0) {
        return;
    }
    const unsigned int blue = ToByte(parms.z);
    const unsigned int red = ToByte(parms.x);
    const unsigned int green = ToByte(parms.y);
    const unsigned int alpha = ToByte(parms.w);
    simulateParms[index] = blue | (red << 8) | (green << 16) |
        (alpha << 24);
}

void idWaterSurfaceSim::ApplyRadiusEffect(const idVec3& position,
        const idRenderModel* renderModel, const float radius,
        const float fade) {
    if (radius <= 0.0f) {
        return;
    }
    idVec3 localPosition;
    GlobalToLocalPos(position, localPosition, renderModel);
    int centerX;
    int centerY;
    LocalToGridSpacePos(localPosition, centerX, centerY);
    const int gridRadius = static_cast<int>(std::floor(radius / spacing + 0.5f));
    const float radiusSquared = radius * radius;
    const int firstX = (std::max)(1, centerX - gridRadius);
    const int lastX = (std::min)(static_cast<int>(width) - 1,
        centerX + gridRadius);
    const int firstY = (std::max)(1, centerY - gridRadius);
    const int lastY = (std::min)(static_cast<int>(height) - 1,
        centerY + gridRadius);

    for (int y = firstY; y < lastY; ++y) {
        for (int x = firstX; x < lastX; ++x) {
            const float dx = x * spacing - localPosition.x;
            const float dy = y * spacing - localPosition.y;
            const float distanceSquared = dx * dx + dy * dy;
            if (distanceSquared >= radiusSquared) {
                continue;
            }
            const int index = GridIndex(x, y);
            const float oldValue = vertGradient[index] * (1.0f / 255.0f);
            const float falloff = (radiusSquared - distanceSquared) /
                radiusSquared;
            vertGradient[index] = ToByte(oldValue - falloff * fade);
        }
    }
}

void idWaterSurfaceSim::ClearRadiusEffects() {
    std::fill(vertGradient.Ptr(), vertGradient.Ptr() + vertGradient.Num(),
        static_cast<unsigned char>(255));
}

bool idWaterSurfaceSim::GetSurfacePositionAtPoint(idVec3& position,
        idRenderModelWaterSurface* renderModel, float& surfaceHeight,
        idVec3& normal) const {
    idVec3 localPosition;
    GlobalToLocalPos(position, localPosition,
        reinterpret_cast<const idRenderModel*>(renderModel));
    const float gridPositionX = localPosition.x / spacing;
    const float gridPositionY = localPosition.y / spacing;
    const int x0 = static_cast<int>(std::floor(gridPositionX));
    const int y0 = static_cast<int>(std::floor(gridPositionY));
    if (x0 < 0 || y0 < 0 || x0 + 1 >= static_cast<int>(width)
        || y0 + 1 >= static_cast<int>(height)) return false;
    const int x1 = x0 + 1;
    const int y1 = y0 + 1;
    const float fractionX = gridPositionX - static_cast<float>(x0);
    const float fractionY = gridPositionY - static_cast<float>(y0);
    const idList<float, 54>& heights = waveHeight[currentDeferred];

    idVec3 triangle[3];
    if (((x0 + y0) & 1) == 0) {
        SetupLocalPos(triangle[0], x0, y0, heights.Ptr());
        SetupLocalPos(triangle[1], x1, y1, heights.Ptr());
        if (fractionX <= fractionY)
            SetupLocalPos(triangle[2], x0, y1, heights.Ptr());
        else
            SetupLocalPos(triangle[2], x1, y0, heights.Ptr());
    } else {
        SetupLocalPos(triangle[0], x1, y0, heights.Ptr());
        SetupLocalPos(triangle[1], x0, y1, heights.Ptr());
        if (1.0f - fractionX > fractionY)
            SetupLocalPos(triangle[2], x0, y0, heights.Ptr());
        else
            SetupLocalPos(triangle[2], x1, y1, heights.Ptr());
    }
    normal = (triangle[0] - triangle[2]).Cross(
        triangle[1] - triangle[2]);
    if (normal.LengthSqr() <= 1.0e-30f) normal.Set(0.0f, 0.0f, 1.0f);
    else normal.NormalizeFast();
    if (normal.z < 0.0f) normal = -normal;
    if (std::fabs(normal.z) <= 1.0e-20f) return false;
    surfaceHeight = triangle[2].z
        - (normal.x * (localPosition.x - triangle[2].x)
            + normal.y * (localPosition.y - triangle[2].y)) / normal.z;
    const idVec3 modelPosition(localPosition.x + origin.x,
        localPosition.y + origin.y, surfaceHeight + origin.z);
    if (localToGlobalCallback != nullptr && renderModel != nullptr) {
        localToGlobalCallback(reinterpret_cast<const idRenderModel*>(
            renderModel), modelPosition, position);
    } else {
        position = modelPosition;
    }
    return true;
}
