#pragma once

#include "../aimoveparms.h"
#include "coveractions.h"
#include "aas2file/aas2file.h"
#include "gamelib/effects/weapontracemanager.h"

class idAAS2;
class idActor;
class idEntity;
enum coverOrientation_t : int;

enum firePoint_t : int {
    FIREPOINT_START = 0,
    FIREPOINT_LEFT = 0,
    FIREPOINT_RIGHT = 1,
    FIREPOINT_OVER = 2,
    FIREPOINT_MAX = 3
};

enum aiCoverFlags_t : int {
    COVER_NONE = 0,
    COVER_POPIN_HURT = 1,
    COVER_POPIN_AIM = 2,
    COVER_POPIN_RELOAD = 4,
    COVER_POPOUT_NO_AIM = 8,
    COVER_POPOUT_HURT = 16,
    COVER_STAYOUT_SAFE = 32
};

// Compact identity for a cover point. Runtime queries through idAAS2 remain
// in the raw ledger; this slice restores the independently verifiable value
// semantics and exact Xbox 360/Win32 layout.
class idAICover {
public:
    idAICover();
    idAICover(const idAAS2* aas, int index);
    idAICover(const idAICover& other);

    idAICover& operator=(const idAICover& other);
    bool operator==(const idAICover& other) const;

    void Init(const idEntity* entity, const idAAS2* newAas, int index);
    void Init(const idAAS2* newAas, int index);

    const aas2Cover_t* GetCoverPoint() const;
    bool IsValid() const;
    posture_t GetCoverPosture() const;
    int GetAreaNum() const;
    const idVec3& GetOrigin() const;
    const idVec3& GetDir() const;
    void GetAxis(idMat3& axis) const;
    bool IsPartiallyExposed() const;
    bool IsFullyExposed() const;
    bool IsReserved() const;
    const idEntity* GetReserver() const;
    void Reserve(const idEntity* reserver) const;
    void Unreserve() const;
    void GetCoverActions(idCoverActions& actions) const;
    void GetOrientation(coverOrientation_t orientation, idMat3& axis) const;
    bool IsPointInFrontOf(const idVec3& point) const;
    bool IsPointInArc(const idVec3& point, float arcCosine) const;
    bool IsPointOnLeanSide(const idVec3& point) const;
    void GetEyePoint(const idActor* user, idVec3& eyePoint) const;
    bool GetFiringPoint(const idActor* user, firePoint_t firePointType,
        idVec3& firePoint) const;
    bool GetExposedPoint(firePoint_t firePointType,
        idVec3& exposedPoint) const;
    float VisibilityRatioFromFirePoints(const idActor* user,
        const idAAS2* visibilityAas, int areaNum) const;
    void MakeUnusable(int duration) const;
    bool IsUsable() const;
    bool ShouldAvoid() const;
    bool IsExplicit() const;
    bool IsExpired(int stayTime) const;
    float AngleToPoint(const idVec3& point, bool considerFireOver) const;

    const idAAS2* aas;
    idSpawnId spawnId;
    short coverIndex;
};

class idCoverBlocker {
public:
    void Spawn();
};

// Runtime owners that are still outside this recovered translation unit.
const aas2Cover_t* Tungsten_GetStaticAICoverPoint(
    const idAAS2& aas, int coverIndex);
const aas2Cover_t* Tungsten_GetDynamicAICoverPoint(
    const idEntity& entity, const idAAS2& aas, int coverIndex);
idVec3 Tungsten_GetAICoverGravityDirection(const idAAS2& aas);
idVec3 Tungsten_GetAICoverActorEyeOffset(
    const idActor& actor, posture_t posture);
float Tungsten_GetAICoverLateralFireOffset(
    const idAAS2& aas, const idVec3& lateralDirection);
float Tungsten_GetAICoverVisibilityRatio(
    const idVec3& eyePoint, const idAAS2& aas, int areaNum);
int Tungsten_GetAICoverGameMilliseconds();
void Tungsten_RegisterCoverBlocker(idCoverBlocker& blocker);

int Tungsten_GetEntitySpawnId(const idEntity* entity);
const idEntity* Tungsten_ResolveEntitySpawnId(int spawnId);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAICover) == 12,
    "Recovered AI cover identity ABI changed");
#endif
