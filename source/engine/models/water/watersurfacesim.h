#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/random.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idRenderModel;
class idRenderModelWaterSurface;

enum waterDisturbanceType_t : int {
    WATER_DISTURBANCE_TYPE_WAVE = 0,
    WATER_DISTURBANCE_TYPE_RIPPLE = 1,
    WATER_DISTURBANCE_TYPE_FANCY_RIPPLE = 2,
    WATER_DISTURBANCE_TYPE_DROPLET = 3
};

struct alignas(16) waterDisturbanceParms_t {
    waterDisturbanceType_t type;
    int gridX;
    int gridY;
    idVec2 loc;
    idVec4 parms;
    float currentDistance;
    float radius;
    float padding;
};

class idWaterSurfaceSim {
public:
    using GlobalToLocalCallback = void (*)(const idRenderModel* model,
        const idVec3& globalPoint, idVec3& localPoint);

    idWaterSurfaceSim(const idBounds& bounds, float spacing, float damping,
        float speed, float timeStep);
    ~idWaterSurfaceSim() = default;

    static void SetGlobalToLocalCallback(GlobalToLocalCallback callback);

    float GetTimeStep() const;
    void Swap();
    void AddRipple(const idVec3& position, float magnitude, float radius,
        const idRenderModel* renderModel);
    void AddFancyRipple(const idVec3& position,
        const idRenderModel* renderModel, float amplitude, float frequency,
        float fadeStart, float fadeEnd, float currentDistance);
    void AddDrop(unsigned int x, unsigned int y, float radius,
        float magnitude);
    void AddWave(const idVec2& direction, float frequency, float phase,
        float amplitude, float waveExponent);
    void SetSimulationParms(unsigned int gridX, unsigned int gridY,
        const idVec4& parms);
    void ApplyRadiusEffect(const idVec3& position,
        const idRenderModel* renderModel, float radius, float fade);
    void ClearRadiusEffects();
    bool GetSurfacePositionAtPoint(idVec3& position,
        idRenderModelWaterSurface* renderModel, float& height,
        idVec3& normal) const;

    int GridIndex(int gridX, int gridY) const;

    unsigned int width;
    unsigned int height;
    float spacing;
    float damping;
    float speed;
    float timeStep;
    bool visible;
    idVec3 origin;
    idRandom2 rnd;
    int currentDeferred;
    int numDisturbances;
    int allocWidth;
    int allocHeight;
    int numBlocksX;
    int numBlocksY;
    idList<unsigned int, 54> simulateParms;
    idList<unsigned char, 54> vertGradient;
    idList<float, 54> waveHeight[2];
    idList<float, 54> dummyBlock;
    idList<waterDisturbanceParms_t, 54> waterDisturbances[2];

private:
    void GlobalToLocalPos(const idVec3& globalPosition,
        idVec3& localPosition, const idRenderModel* renderModel) const;
    void LocalToGridSpacePos(const idVec3& localPosition,
        int& x, int& y) const;
    waterDisturbanceParms_t* AllocateDisturbance();

    static GlobalToLocalCallback globalToLocalCallback;
};

static_assert(sizeof(waterDisturbanceParms_t) == 48,
    "Recovered water-disturbance ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idWaterSurfaceSim) == 180,
    "Recovered idWaterSurfaceSim ABI changed");
#endif
