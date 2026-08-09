#pragma once

#include "idlib/math/random.h"
#include "models/rendermodel.h"

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

    idRenderModelDecal();
    ~idRenderModelDecal() override = default;
    static void SetUpdateCallback(UpdateCallback callback);
    bool UpdateInView(const idRenderView* currentView,
        const idRenderView* nextView,
        idRenderModelUpdateTools* tools) override;

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
    static UpdateCallback updateCallback;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idRenderModelDecal::decalInfo_t) == 100,
    "Recovered decal-information ABI changed");
static_assert(sizeof(idRenderModelDecal::tireDecalInfo_t) == 124,
    "Recovered tire-decal information ABI changed");
#endif
