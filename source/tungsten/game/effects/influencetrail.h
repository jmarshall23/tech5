#pragma once

#include "game/effects/influencetrail_types.h"
#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/math/vector.h"

class idPresentable;
class idRenderModelTransparency;
class idSoundShader;

enum invalidInfluenceTrail_t : int {
    INVALID_INFLUENCE_TRAIL = -1
};

using idInfluenceTrailHandle =
    idHandle<int, invalidInfluenceTrail_t, -1>;

class idInfluenceTrail {
public:
    struct idInfluenceSphere {
        idVec3 center;
        int time;
    };

    idInfluenceTrail();
    void UpdatePosition(const idVec3& newPosition, int time);

    bool active;
    float trailDist;
    float innerRadius;
    float outerRadius;
    float angle;
    int trailFadeInTime;
    int trailFadeOutTime;
    idVec3 position;
    idVec3 lastPosition;
    idList<idInfluenceSphere, 5> trail;
    idPresentable* presentable;
    const idSoundShader* sndFoliage;
};

class idInfluenceTrailServices {
public:
    virtual ~idInfluenceTrailServices() = default;
    virtual idInfluenceTrailHandle GetHandle(idPresentable*) const {
        return {};
    }
    virtual void SetHandle(idPresentable*, idInfluenceTrailHandle) {}
    virtual bool IsFoliageSoundPlaying(idPresentable*) const { return false; }
    virtual void StartFoliageSound(idPresentable*, const idSoundShader*) {}
    virtual void AddInfluenceSphere(idRenderModelTransparency*,
        const idVec3&, float, float, float) {}
    virtual void ClearInfluenceSpheres(idRenderModelTransparency*) {}
    virtual void OutOfInfluenceTrails() {}
};

class idInfluenceTrailManager {
public:
    virtual ~idInfluenceTrailManager() = default;

    static void SetServices(idInfluenceTrailServices* services);
    static idInfluenceTrailServices& Services();

    idInfluenceTrailHandle AllocInfluenceTrail(float innerRadius,
        float outerRadius, float angle, float trailDistance,
        int fadeInTime, int fadeOutTime, idPresentable* presentable,
        const idSoundShader* foliageSound);
    void FreeInfluenceTrail(idPresentable& presentable);
    void ModifyAngle(const idInfluenceTrailHandle& trail, float angle);
    void AddInfluenceSpheresToModel(idRenderModelTransparency* model,
        int time);
    void Enable(idPresentable& presentable,
        const idEntityInfluenceTrail& trail,
        const idSoundShader* foliageSound);
    void UpdateInfluenceTrails(int time,
        idRenderModelTransparency* transparencyModel);
    void UpdatePosition(const idInfluenceTrailHandle& trail,
        const idVec3& position, int time);

    idInfluenceTrail influenceTrails[128];
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idInfluenceTrail::idInfluenceSphere) == 16,
    "Recovered influence sphere ABI changed");
static_assert(sizeof(idInfluenceTrail) == 76,
    "Recovered influence trail ABI changed");
static_assert(sizeof(idInfluenceTrailManager) == 9732,
    "Recovered influence trail manager ABI changed");
#endif
