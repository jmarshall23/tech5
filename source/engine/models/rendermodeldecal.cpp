#include "models/rendermodeldecal.h"
#include "idlib/geometry/rendermatrix.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <vector>

namespace {

constexpr int kTransientDecalCount = 2048;
constexpr int kPermanentDecalCount = 128;
constexpr int kTotalDecalCount = kTransientDecalCount +
    kPermanentDecalCount;
constexpr int kTireDecalCount = 512;
constexpr int kMaximumMaterialGroups = 32;

idVec3 Normalize(const idVec3& value, const idVec3& fallback) {
    const float lengthSquared = value.LengthSqr();
    return lengthSquared > 1.0e-30f
        ? value * (1.0f / std::sqrt(lengthSquared)) : fallback;
}

void MakeDecalAxis(const idVec3& direction, float angle, idMat3& axis) {
    const idVec3 normal = Normalize(direction, idVec3(0.0f, 0.0f, 1.0f));
    const idVec3 reference = std::fabs(normal.z) < 0.9f
        ? idVec3(0.0f, 0.0f, 1.0f) : idVec3(0.0f, 1.0f, 0.0f);
    const idVec3 right = Normalize(reference.Cross(normal),
        idVec3(1.0f, 0.0f, 0.0f));
    const idVec3 up = Normalize(normal.Cross(right),
        idVec3(0.0f, 1.0f, 0.0f));
    const float sine = std::sin(angle);
    const float cosine = std::cos(angle);
    axis[0] = right * cosine + up * sine;
    axis[1] = up * cosine - right * sine;
    axis[2] = normal;
}

std::uint8_t FadeByte(int now, int start, int life, int fadeIn,
        int fadeOutStart) {
    if (life == 0 || now < start) return 0;
    float fade = 1.0f;
    const int age = now - start;
    if (fadeIn > 0 && age < fadeIn)
        fade = (std::min)(fade, static_cast<float>(age) / fadeIn);
    if (life > 0 && fadeOutStart >= 0 && age > fadeOutStart) {
        const int fadeDuration = life - fadeOutStart;
        fade = fadeDuration > 0
            ? (std::min)(fade,
                static_cast<float>(life - age) / fadeDuration)
            : 0.0f;
    }
    fade = (std::max)(0.0f, (std::min)(1.0f, fade));
    return static_cast<std::uint8_t>(fade * 255.0f + 0.5f);
}

std::uint8_t FloatToByte(const float value) {
    return static_cast<std::uint8_t>((std::max)(0.0f,
        (std::min)(255.0f, value)));
}

void PackFloat(std::uint8_t packed[4], const float number) {
    float value = number * 0.001f;
    for (int component = 0; component < 4; ++component) {
        const float fraction = value - std::floor(value);
        packed[component] = FloatToByte(fraction * 255.0f);
        value *= 256.0f;
    }
}

constexpr float kCubeCorners[8][3] = {
    {-1.0f, -1.0f, -1.0f}, { 1.0f, -1.0f, -1.0f},
    {-1.0f,  1.0f, -1.0f}, { 1.0f,  1.0f, -1.0f},
    {-1.0f, -1.0f,  1.0f}, { 1.0f, -1.0f,  1.0f},
    {-1.0f,  1.0f,  1.0f}, { 1.0f,  1.0f,  1.0f}
};

constexpr float kQuadCorners[4][2] = {
    {-1.0f, -1.0f}, {1.0f, -1.0f},
    {1.0f, 1.0f}, {-1.0f, 1.0f}
};

void StorePackedProjectionVertex(idDrawVert& vertex,
        const idRenderModelDecal::decalInfo_t& decal,
        const idVec3& localPosition, const bool spherical,
        const std::uint8_t alpha) {
    std::memset(&vertex, 0, sizeof(vertex));
    const idVec3 worldOffset = decal.axis[0] * localPosition.x
        + decal.axis[1] * localPosition.y
        + decal.axis[2] * localPosition.z;
    vertex.xyz = decal.pos + worldOffset;
    vertex.st.x = decal.scaleBiasX;
    vertex.st.y = decal.scaleBiasY;

    if (spherical) {
        vertex.SetNormal(Normalize(localPosition,
            idVec3(0.0f, 0.0f, 1.0f)));
        vertex.SetTangent(decal.axis[0]);
        vertex.SetBiTangent(decal.axis[1]);
        vertex.tangent[3] = static_cast<std::uint8_t>(
            (localPosition.x > 0.0f ? 1 : 0)
            | (localPosition.y > 0.0f ? 2 : 0)
            | (localPosition.z > 0.0f ? 4 : 0));
        PackFloat(vertex.color, localPosition.Length());
        return;
    }

    vertex.SetNormal(decal.axis[2]);
    vertex.SetTangent(decal.axis[0]);
    vertex.SetBiTangent(decal.axis[1]);
    vertex.normal[3] = static_cast<std::uint8_t>(
        (worldOffset.x > 0.0f ? 1 : 0)
        | (worldOffset.y > 0.0f ? 2 : 0)
        | (worldOffset.z > 0.0f ? 4 : 0));
    vertex.color[0] = FloatToByte(std::fabs(worldOffset.x));
    vertex.color[1] = FloatToByte(std::fabs(worldOffset.y));
    vertex.color[2] = FloatToByte(std::fabs(worldOffset.z));
    vertex.color[3] = alpha;
}

void GenerateDecalVertices(const idRenderModelDecal::decalInfo_t& decal,
        idDrawVert* const vertices, const int currentTime,
        const bool spherical) {
    if (vertices == nullptr) return;
    const std::uint8_t alpha = FadeByte(currentTime, decal.startTime,
        decal.lifeTime, decal.fadeInTime, decal.fadeOutTime);
    if (decal.quad) {
        const float width = decal.size.x * decal.sizeScale;
        const float height = decal.size.y * decal.sizeScale;
        for (int index = 0; index < 4; ++index) {
            idDrawVert& vertex = vertices[index];
            std::memset(&vertex, 0, sizeof(vertex));
            vertex.xyz = decal.pos
                + decal.axis[0] * (kQuadCorners[index][0] * width)
                + decal.axis[1] * (kQuadCorners[index][1] * height);
            vertex.st.x = decal.scaleBiasX;
            vertex.st.y = decal.scaleBiasY;
            vertex.SetNormal(decal.axis[2]);
            vertex.SetTangent(decal.axis[0]);
            vertex.SetBiTangent(decal.axis[1]);
            vertex.color[0] = kQuadCorners[index][0] > 0.0f ? 255 : 0;
            vertex.color[1] = kQuadCorners[index][1] > 0.0f ? 255 : 0;
            vertex.color[2] = 0;
            vertex.color[3] = alpha;
        }
        return;
    }

    const float scale = decal.sizeScale;
    for (int index = 0; index < 8; ++index) {
        const float radius = decal.size.x;
        const idVec3 local(
            kCubeCorners[index][0] * (spherical ? radius
                : decal.size.x * scale),
            kCubeCorners[index][1] * (spherical ? radius
                : decal.size.y * scale),
            kCubeCorners[index][2] * (spherical ? radius : decal.depth));
        StorePackedProjectionVertex(vertices[index], decal, local,
            spherical, alpha);
    }
}

struct GeometryGroup {
    const idMaterial* material;
    std::vector<idDrawVert> vertices;
    std::vector<std::uint16_t> indices;
};

GeometryGroup* FindGroup(std::vector<GeometryGroup>& groups,
        const idMaterial* material) {
    for (GeometryGroup& group : groups)
        if (group.material == material) return &group;
    if (groups.size() >= kMaximumMaterialGroups) return nullptr;
    groups.push_back(GeometryGroup{material, {}, {}});
    return &groups.back();
}

void InitializeVertex(idDrawVert& vertex, const idVec3& position,
        const idVec3& normal, float s, float t, std::uint8_t alpha) {
    std::memset(&vertex, 0, sizeof(vertex));
    vertex.xyz = position;
    vertex.st.Set(s, t);
    vertex.SetNormal(normal);
    idVec3 tangent = std::fabs(normal.z) < 0.9f
        ? idVec3(0.0f, 0.0f, 1.0f).Cross(normal)
        : idVec3(0.0f, 1.0f, 0.0f).Cross(normal);
    tangent = Normalize(tangent, idVec3(1.0f, 0.0f, 0.0f));
    vertex.SetTangent(tangent);
    vertex.SetBiTangent(normal.Cross(tangent));
    vertex.color[0] = 255;
    vertex.color[1] = 255;
    vertex.color[2] = 255;
    vertex.color[3] = alpha;
}

void AppendDecalGeometry(GeometryGroup& group,
        const idRenderModelDecal::decalInfo_t& decal, int currentTime,
        const bool spherical) {
    const std::uint8_t alpha = FadeByte(currentTime, decal.startTime,
        decal.lifeTime, decal.fadeInTime, decal.fadeOutTime);
    if (alpha == 0) return;
    const int base = static_cast<int>(group.vertices.size());
    if (base + (decal.quad ? 4 : 8) > 65535) return;
    const int vertexCount = decal.quad ? 4 : 8;
    const std::size_t oldSize = group.vertices.size();
    group.vertices.resize(oldSize + vertexCount);
    GenerateDecalVertices(decal, group.vertices.data() + oldSize,
        currentTime, spherical);

    if (decal.quad) {
        const std::uint16_t local[6] = {0, 1, 2, 0, 2, 3};
        for (std::uint16_t index : local)
            group.indices.push_back(static_cast<std::uint16_t>(base + index));
        return;
    }

    const std::uint16_t box[36] = {
        0,2,3,0,3,1, 4,5,7,4,7,6,
        0,1,5,0,5,4, 2,6,7,2,7,3,
        0,4,6,0,6,2, 1,3,7,1,7,5
    };
    for (std::uint16_t index : box)
        group.indices.push_back(static_cast<std::uint16_t>(base + index));
}

void AppendTireGeometry(GeometryGroup& group,
        const idRenderModelDecal::tireDecalInfo_t& decal, int currentTime) {
    const std::uint8_t alpha = FadeByte(currentTime, decal.startTime,
        decal.lifeTime, 0, decal.fadeTime);
    if (alpha == 0 || group.vertices.size() + 8 > 65535) return;
    const int base = static_cast<int>(group.vertices.size());
    const idVec3 normal = Normalize(decal.dir, idVec3(0.0f, 0.0f, 1.0f));
    for (int layer = 0; layer < 2; ++layer) {
        for (int corner = 0; corner < 4; ++corner) {
            idDrawVert vertex;
            const idVec3 position = decal.pos + decal.corners[corner] +
                normal * (layer != 0 ? decal.depth : 0.0f);
            InitializeVertex(vertex, position, normal,
                (corner == 1 || corner == 2) ? 1.0f : 0.0f,
                corner >= 2 ? 1.0f : 0.0f, alpha);
            group.vertices.push_back(vertex);
        }
    }
    const std::uint16_t box[36] = {
        0,2,3,0,3,1, 4,5,7,4,7,6,
        0,1,5,0,5,4, 2,6,7,2,7,3,
        0,4,6,0,6,2, 1,3,7,1,7,5
    };
    for (std::uint16_t index : box)
        group.indices.push_back(static_cast<std::uint16_t>(base + index));
}

} // namespace

idRenderModelDecal::UpdateCallback idRenderModelDecal::updateCallback = nullptr;
idRenderModelDecal::AtlasScaleBiasCallback
    idRenderModelDecal::atlasScaleBiasCallback = nullptr;
idRenderModelDecal::ProjectionTypeCallback
    idRenderModelDecal::projectionTypeCallback = nullptr;
idRenderModelDecal::DebugDrawCallback
    idRenderModelDecal::debugDrawCallback = nullptr;
idRenderModelDecal::InverseVPCallback
    idRenderModelDecal::inverseVPCallback = nullptr;
bool idRenderModelDecal::initialized = false;

idRenderModelDecal::idRenderModelDecal()
    : decals(new decalInfo_t[kTotalDecalCount]),
      tireDecals(new tireDecalInfo_t[kTireDecalCount]), gameTime(0),
      random(0), latchedTime(0), usesPreAllocatedBuffer(false),
      triangles(new idTriangles[kMaximumMaterialGroups]) {
    if (!initialized) Init();
    std::memset(decals, 0, sizeof(decalInfo_t) * kTotalDecalCount);
    std::memset(tireDecals, 0,
        sizeof(tireDecalInfo_t) * kTireDecalCount);
    std::memset(triangles, 0,
        sizeof(idTriangles) * kMaximumMaterialGroups);
    std::memset(decalRange, 0, sizeof(decalRange));
    std::memset(tireDecalRange, 0, sizeof(tireDecalRange));
    std::memset(latchedDecalRange, 0, sizeof(latchedDecalRange));
    std::memset(latchedTireDecalRange, 0, sizeof(latchedTireDecalRange));
    std::memset(vertexBuffer, 0, sizeof(vertexBuffer));
    std::memset(&indexBufferBoxes, 0, sizeof(indexBufferBoxes));
    std::memset(&indexBufferQuads, 0, sizeof(indexBufferQuads));
    std::memset(parmPositionToLocalBoxSpace, 0,
        sizeof(parmPositionToLocalBoxSpace));
    g.axis = idMat3(1.0f);
    g.noShadow = 1;
    g.addAlways = 1;
}

idRenderModelDecal::~idRenderModelDecal() {
    ClearGeneratedGeometry();
    delete[] triangles;
    triangles = nullptr;
    delete[] tireDecals;
    delete[] decals;
}

void idRenderModelDecal::Init() {
    initialized = true;
}

void idRenderModelDecal::Shutdown() {
    initialized = false;
}

void idRenderModelDecal::SetUpdateCallback(UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelDecal::SetAtlasScaleBiasCallback(
        AtlasScaleBiasCallback callback) {
    atlasScaleBiasCallback = callback;
}

void idRenderModelDecal::SetProjectionTypeCallback(
        ProjectionTypeCallback callback) {
    projectionTypeCallback = callback;
}

void idRenderModelDecal::SetDebugDrawCallback(DebugDrawCallback callback) {
    debugDrawCallback = callback;
}

void idRenderModelDecal::SetInverseVPCallback(InverseVPCallback callback) {
    inverseVPCallback = callback;
}

void idRenderModelDecal::SetupInverseVPMatrix(
        idRenderMatrix& inverseViewProjection, const idRenderView* const view,
        const float zNear, const float zFar) const {
    if (inverseVPCallback == nullptr
        || !inverseVPCallback(this, inverseViewProjection, view,
            zNear, zFar))
        inverseViewProjection.Identity();
}

void idRenderModelDecal::GenDecalVerts(const decalInfo_t* const decal,
        idDrawVert* const vertices) const {
    if (decal != nullptr)
        GenerateDecalVertices(*decal, vertices, latchedTime, false);
}

void idRenderModelDecal::GenSphericalDecalVerts(
        const decalInfo_t* const decal, idDrawVert* const vertices) const {
    if (decal != nullptr)
        GenerateDecalVertices(*decal, vertices, latchedTime, true);
}

void idRenderModelDecal::DebugDrawDecals(const idVec3& position,
        const idMat3& axis, idDrawVert* const vertices,
        const int numVertices) const {
    if (debugDrawCallback != nullptr)
        debugDrawCallback(position, axis, vertices, numVertices);
}

void idRenderModelDecal::ClearGeneratedGeometry() {
    surfaces.Clear();
    if (triangles == nullptr) return;
    for (int index = 0; index < kMaximumMaterialGroups; ++index) {
        delete[] triangles[index].verts;
        delete[] triangles[index].indexes;
        triangles[index].verts = nullptr;
        triangles[index].indexes = nullptr;
        triangles[index].numVerts = 0;
        triangles[index].numIndexes = 0;
    }
}

void idRenderModelDecal::Update(int currentTime) {
    gameTime = currentTime;
    while (decalRange[0] < decalRange[1]) {
        const decalInfo_t& decal = decals[decalRange[0] & 0x7ff];
        if (decal.lifeTime < 0 ||
                currentTime - decal.startTime <= decal.lifeTime) break;
        ++decalRange[0];
    }
    decalRange[0] = (std::max)(decalRange[0],
        decalRange[1] - kTransientDecalCount);
    while (tireDecalRange[0] < tireDecalRange[1]) {
        const tireDecalInfo_t& decal =
            tireDecals[tireDecalRange[0] & 0x1ff];
        if (currentTime - decal.startTime <= decal.lifeTime) break;
        ++tireDecalRange[0];
    }
    tireDecalRange[0] = (std::max)(tireDecalRange[0],
        tireDecalRange[1] - kTireDecalCount);
    CommitThisFrame();
}

bool idRenderModelDecal::CommitSubclass() {
    latchedDecalRange[0] = decalRange[0];
    latchedDecalRange[1] = decalRange[1];
    latchedTireDecalRange[0] = tireDecalRange[0];
    latchedTireDecalRange[1] = tireDecalRange[1];
    latchedTime = gameTime;
    return false;
}

decalHandle_t idRenderModelDecal::AddDecalFromPoint(
        const decalParams_t* parms, int startTime, const idVec3& position,
        const idVec3& direction, idJointIndex) {
    if (parms == nullptr || parms->decalMat == nullptr)
        return decalHandle_t();
    int slot = -1;
    if (parms->lifeTime < 0) {
        for (int index = kTransientDecalCount;
                index < kTotalDecalCount; ++index) {
            if (decals[index].decalMtr == nullptr ||
                    decals[index].lifeTime == 0) {
                slot = index;
                break;
            }
        }
    } else if (decalRange[1] - latchedDecalRange[0] <
            kTransientDecalCount) {
        slot = decalRange[1]++ & 0x7ff;
    }
    if (slot < 0) return decalHandle_t();

    decalInfo_t& decal = decals[slot];
    std::memset(&decal, 0, sizeof(decal));
    decal.startTime = startTime;
    decal.lifeTime = parms->lifeTime;
    decal.decalMtr = parms->decalMat;
    decal.fadeOutTime = parms->fadeOutTime;
    decal.fadeInTime = parms->fadeInTime;
    decal.depth = parms->depth * 0.5f;
    decal.pos = position;
    decal.size.Set(parms->size.x * 0.5f, parms->size.y * 0.5f);
    decal.size.x = (std::min)(255.0f, decal.size.x);
    decal.size.y = (std::min)(255.0f, decal.size.y);
    decal.depth = (std::min)(255.0f, decal.depth);
    decal.sizeScale = 1.0f;
    decal.quad = parms->quad;
    decal.handle = slot;
    const float angle = parms->angle != 0.0f
        ? parms->angle : random.RandomFloat() * 6.2831853071795864769f;
    MakeDecalAxis(direction, angle, decal.axis);
    if (atlasScaleBiasCallback != nullptr)
        atlasScaleBiasCallback(decal.decalMtr,
            decal.scaleBiasX, decal.scaleBiasY);
    return decal.handle;
}

void idRenderModelDecal::AddDecalFromTireMark(
        const tireDecalParams_t* parms, int startTime,
        const idVec3& position, const idVec3& direction) {
    if (parms == nullptr || parms->decalMat == nullptr ||
            tireDecalRange[1] - latchedTireDecalRange[0] >=
                kTireDecalCount) {
        return;
    }
    tireDecalInfo_t& decal = tireDecals[tireDecalRange[1]++ & 0x1ff];
    std::memset(&decal, 0, sizeof(decal));
    decal.startTime = startTime;
    decal.lifeTime = parms->lifeTime;
    decal.decalMtr = parms->decalMat;
    decal.fadeTime = parms->fadeTime;
    decal.pos = position;
    decal.dir = direction;
    decal.depth = parms->depth;
    std::memcpy(decal.corners, parms->corners, sizeof(decal.corners));
    decal.left = parms->left;
    decal.halfWidth = parms->halfWidth;
    decal.halfHeight = parms->halfHeight;
    decal.markStart = parms->markStart;
    decal.markEnd = parms->markEnd;
    if (atlasScaleBiasCallback != nullptr)
        atlasScaleBiasCallback(decal.decalMtr,
            decal.scaleBiasX, decal.scaleBiasY);
}

idRenderModelDecal::decalInfo_t* idRenderModelDecal::GetDecalFromHandle(
        decalHandle_t handle) {
    const int index = handle.Get();
    if (index < 0 || index >= kTotalDecalCount) return nullptr;
    if (index >= kTransientDecalCount) return &decals[index];
    if (decalRange[0] >= decalRange[1]) return nullptr;
    const int first = decalRange[0] & (kTransientDecalCount - 1);
    const int last = (decalRange[1] - 1) & (kTransientDecalCount - 1);
    const bool inRange = last >= first
        ? index >= first && index <= last
        : index >= first || index <= last;
    if (!inRange) return nullptr;
    decalInfo_t& decal = decals[index];
    if (gameTime - decal.startTime > decal.lifeTime) return nullptr;
    return &decal;
}

const idRenderModelDecal::decalInfo_t*
idRenderModelDecal::GetDecalFromHandle(decalHandle_t handle) const {
    return const_cast<idRenderModelDecal*>(this)->GetDecalFromHandle(handle);
}

bool idRenderModelDecal::SetDecalPosition(decalHandle_t handle,
        const idVec3& worldPosition, const idMat3& worldAxis) {
    decalInfo_t* decal = GetDecalFromHandle(handle);
    if (decal == nullptr) return false;
    decal->pos = worldPosition;
    decal->axis = worldAxis;
    return true;
}

bool idRenderModelDecal::SetDecalAttributes(decalHandle_t handle,
        const idVec3& worldPosition, const idMat3& worldAxis,
        float sizeScale) {
    decalInfo_t* decal = GetDecalFromHandle(handle);
    if (decal == nullptr) return false;
    decal->pos = worldPosition;
    decal->axis = worldAxis;
    decal->sizeScale = sizeScale;
    return true;
}

bool idRenderModelDecal::GetDecalAxis(decalHandle_t handle,
        idMat3& axis) const {
    const decalInfo_t* decal = GetDecalFromHandle(handle);
    axis = decal != nullptr ? decal->axis : idMat3(1.0f);
    return decal != nullptr;
}

bool idRenderModelDecal::RemoveDecal(decalHandle_t handle) {
    decalInfo_t* decal = GetDecalFromHandle(handle);
    if (decal == nullptr) return false;
    decal->lifeTime = 0;
    return true;
}

void idRenderModelDecal::RemoveDecals() {
    std::memset(decals, 0, sizeof(decalInfo_t) * kTotalDecalCount);
    std::memset(tireDecals, 0,
        sizeof(tireDecalInfo_t) * kTireDecalCount);
    decalRange[0] = decalRange[1] = 0;
    tireDecalRange[0] = tireDecalRange[1] = 0;
    latchedDecalRange[0] = latchedDecalRange[1] = 0;
    latchedTireDecalRange[0] = latchedTireDecalRange[1] = 0;
    ClearGeneratedGeometry();
    idRenderModel::RemoveDecals();
}

bool idRenderModelDecal::UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView, idRenderModelUpdateTools* tools) {
    if (updateCallback != nullptr)
        return updateCallback(this, currentView, nextView, tools);
    std::vector<GeometryGroup> groups;
    groups.reserve(kMaximumMaterialGroups);
    for (int sequence = latchedDecalRange[0];
            sequence < latchedDecalRange[1]; ++sequence) {
        const decalInfo_t& decal = decals[sequence & 0x7ff];
        if (decal.decalMtr == nullptr) continue;
        GeometryGroup* group = FindGroup(groups, decal.decalMtr);
        if (group != nullptr)
            AppendDecalGeometry(*group, decal, latchedTime,
                projectionTypeCallback != nullptr
                    && projectionTypeCallback(decal.decalMtr));
    }
    for (int index = kTransientDecalCount;
            index < kTotalDecalCount; ++index) {
        const decalInfo_t& decal = decals[index];
        if (decal.decalMtr == nullptr || decal.lifeTime == 0) continue;
        GeometryGroup* group = FindGroup(groups, decal.decalMtr);
        if (group != nullptr)
            AppendDecalGeometry(*group, decal, latchedTime,
                projectionTypeCallback != nullptr
                    && projectionTypeCallback(decal.decalMtr));
    }
    for (int sequence = latchedTireDecalRange[0];
            sequence < latchedTireDecalRange[1]; ++sequence) {
        const tireDecalInfo_t& decal = tireDecals[sequence & 0x1ff];
        if (decal.decalMtr == nullptr) continue;
        GeometryGroup* group = FindGroup(groups, decal.decalMtr);
        if (group != nullptr)
            AppendTireGeometry(*group, decal, latchedTime);
    }

    ClearGeneratedGeometry();
    for (int groupIndex = 0;
            groupIndex < static_cast<int>(groups.size()); ++groupIndex) {
        GeometryGroup& group = groups[groupIndex];
        if (group.vertices.empty() || group.indices.empty()) continue;
        idTriangles& geometry = triangles[groupIndex];
        geometry.numVerts = static_cast<int>(group.vertices.size());
        geometry.numIndexes = static_cast<int>(group.indices.size());
        geometry.verts = new idDrawVert[geometry.numVerts];
        geometry.indexes = new std::uint16_t[geometry.numIndexes];
        std::memcpy(geometry.verts, group.vertices.data(),
            group.vertices.size() * sizeof(idDrawVert));
        std::memcpy(geometry.indexes, group.indices.data(),
            group.indices.size() * sizeof(std::uint16_t));
        geometry.vertexMask = geometry.cpuVertexMask = 0x1Fu;
        geometry.allowGpuHosting = true;
        geometry.bounds[0].Set(-99999.0f, -99999.0f, -99999.0f);
        geometry.bounds[1].Set(99999.0f, 99999.0f, 99999.0f);
        idRenderModelSurface surface{};
        surface.material = group.material;
        surface.geometry = &geometry;
        surface.geometryIsReference = true;
        AddSurface(surface);
    }
    return false;
}
