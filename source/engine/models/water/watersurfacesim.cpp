#include "models/water/watersurfacesim.h"

#include <algorithm>
#include <cmath>
#include <cstring>

idWaterSurfaceSim::GlobalToLocalCallback
    idWaterSurfaceSim::globalToLocalCallback = nullptr;

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
    const float gridX = localPosition.x / spacing;
    const float gridY = localPosition.y / spacing;
    const int x = static_cast<int>(std::floor(gridX));
    const int y = static_cast<int>(std::floor(gridY));
    if (x < 0 || y < 0 || x + 1 >= static_cast<int>(width) ||
            y + 1 >= static_cast<int>(height)) {
        return false;
    }

    const idList<float, 54>& heights = waveHeight[currentDeferred ^ 1];
    const float h00 = heights[GridIndex(x, y)];
    const float h10 = heights[GridIndex(x + 1, y)];
    const float h01 = heights[GridIndex(x, y + 1)];
    const float h11 = heights[GridIndex(x + 1, y + 1)];
    const float fractionX = gridX - x;
    const float fractionY = gridY - y;
    const float lower = h00 + (h10 - h00) * fractionX;
    const float upper = h01 + (h11 - h01) * fractionX;
    surfaceHeight = lower + (upper - lower) * fractionY;
    position.z = origin.z + surfaceHeight;

    normal.Set(h00 - h10, h00 - h01, spacing);
    normal.NormalizeFast();
    return true;
}
