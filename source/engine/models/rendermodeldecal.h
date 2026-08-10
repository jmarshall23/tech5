#pragma once

#include "idlib/math/random.h"
#include "models/rendermodel.h"

struct decalParams_t {
    const idMaterial* decalMat;
    int lifeTime;
    int fadeOutTime;
    int fadeInTime;
    idVec2 size;
    float depth;
    bool quad;
    float angle;
};

struct tireDecalParams_t {
    const idMaterial* decalMat;
    int lifeTime;
    int fadeTime;
    float depth;
    idVec3 corners[4];
    idVec3 left;
    float halfWidth;
    float halfHeight;
    bool markStart;
    bool markEnd;
};

class alignas(16) idRenderModelDecal : public idRenderModel {
public:
    struct decalInfo_t {
        int startTime;
        int lifeTime;
        const idMaterial* decalMtr;
        int fadeOutTime;
        int fadeInTime;
        float scaleBiasX;
        float scaleBiasY;
        float depth;
        idVec3 pos;
        idMat3 axis;
        idVec2 size;
        float sizeScale;
        bool quad;
        decalHandle_t handle;
    };

    struct alignas(4) tireDecalInfo_t {
        int startTime;
        int lifeTime;
        const idMaterial* decalMtr;
        int fadeTime;
        float scaleBiasX;
        float scaleBiasY;
        idVec3 pos;
        idVec3 dir;
        float depth;
        idVec3 corners[4];
        idVec3 left;
        float halfWidth;
        float halfHeight;
        bool markStart;
        bool markEnd;
    };

    using UpdateCallback = bool (*)(idRenderModelDecal* model,
        const idRenderView* currentView, const idRenderView* nextView,
        idRenderModelUpdateTools* tools);
    using AtlasScaleBiasCallback = bool (*)(const idMaterial* material,
        float& scaleBiasX, float& scaleBiasY);
    using ProjectionTypeCallback = bool (*)(const idMaterial* material);
    using DebugDrawCallback = void (*)(const idVec3& position,
        const idMat3& axis, const idDrawVert* vertices, int numVertices);
    using InverseVPCallback = bool (*)(const idRenderModelDecal* model,
        idRenderMatrix& inverseViewProjection, const idRenderView* view,
        float zNear, float zFar);
    using RenderParmResolver = const idDeclRenderParm* (*)(
        const char* name, bool makeDefault);

    idRenderModelDecal();
    ~idRenderModelDecal() override;

    static void Init();
    static void Shutdown();
    static void SetUpdateCallback(UpdateCallback callback);
    static void SetAtlasScaleBiasCallback(AtlasScaleBiasCallback callback);
    static void SetProjectionTypeCallback(ProjectionTypeCallback callback);
    static void SetDebugDrawCallback(DebugDrawCallback callback);
    static void SetInverseVPCallback(InverseVPCallback callback);
    static void SetRenderParmResolver(RenderParmResolver resolver);

    void Update(int currentTime);
    bool CommitSubclass() override;
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;
    decalHandle_t AddDecalFromPoint(const decalParams_t* parms,
        int startTime, const idVec3& position, const idVec3& direction,
        idJointIndex joint) override;
    void AddDecalFromTireMark(const tireDecalParams_t* parms,
        int startTime, const idVec3& position, const idVec3& direction);
    bool RemoveDecal(decalHandle_t handle) override;
    void RemoveDecals() override;
    bool SetDecalPosition(decalHandle_t handle,
        const idVec3& worldPosition, const idMat3& worldAxis);
    bool SetDecalAttributes(decalHandle_t handle,
        const idVec3& worldPosition, const idMat3& worldAxis,
        float sizeScale);
    bool GetDecalAxis(decalHandle_t handle, idMat3& axis) const;
    decalInfo_t* GetDecalFromHandle(decalHandle_t handle);
    const decalInfo_t* GetDecalFromHandle(decalHandle_t handle) const;

    decalInfo_t* decals;
    int decalRange[2];
    tireDecalInfo_t* tireDecals;
    int tireDecalRange[2];
    int gameTime;
    idRandom2 random;
    int latchedTime;
    int latchedDecalRange[2];
    int latchedTireDecalRange[2];
    idVertexBuffer vertexBuffer[2];
    idIndexBuffer indexBufferBoxes;
    idIndexBuffer indexBufferQuads;
    bool usesPreAllocatedBuffer;
    idTriangles* triangles;
    const idDeclRenderParm* parmPositionToLocalBoxSpace[4];

private:
    void ClearGeneratedGeometry();
    void SetupInverseVPMatrix(idRenderMatrix& inverseViewProjection,
        const idRenderView* view, float zNear, float zFar) const;
    void GenDecalVerts(const decalInfo_t* decal, idDrawVert* vertices) const;
    void GenSphericalDecalVerts(const decalInfo_t* decal,
        idDrawVert* vertices) const;
    void DebugDrawDecals(const idVec3& position, const idMat3& axis,
        idDrawVert* vertices, int numVertices) const;

    static UpdateCallback updateCallback;
    static AtlasScaleBiasCallback atlasScaleBiasCallback;
    static ProjectionTypeCallback projectionTypeCallback;
    static DebugDrawCallback debugDrawCallback;
    static InverseVPCallback inverseVPCallback;
    static RenderParmResolver renderParmResolver;
    static bool initialized;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idRenderModelDecal::decalInfo_t) == 100,
    "Recovered decal-information ABI changed");
static_assert(sizeof(idRenderModelDecal::tireDecalInfo_t) == 124,
    "Recovered tire-decal information ABI changed");
#endif
