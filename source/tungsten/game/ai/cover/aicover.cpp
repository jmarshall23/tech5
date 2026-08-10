#include "aicover.h"

#include "../aibehaviors.h"
#include "../../gamesys/eventarg.h"

#include <algorithm>
#include <cmath>

namespace {

constexpr int INVALID_SPAWN_ID = 0x1FFF;

const idVec3& ZeroVector() {
    static const idVec3 zero(0.0f, 0.0f, 0.0f);
    return zero;
}

float ClampUnit(const float value) {
    return std::max(-1.0f, std::min(1.0f, value));
}

} // namespace

// Header-origin retail symbol: ?Init@idCoverActions@@QAAXABUaas2Cover_t@@@Z
// EA: 0x82A887C0, RVA: 0x00A887C0
void idCoverActions::Init(const aas2Cover_t& cover) {
    Clear();
    actionBits = static_cast<std::uint8_t>(actionBits
        | ((cover.flags & 0x20) != 0 ? 0x80u : 0u)
        | ((cover.flags & 0x140) != 0 ? 0x40u : 0u)
        | ((cover.flags & 0x100) != 0 ? 0x20u : 0u)
        | ((cover.flags & 0x280) != 0 ? 0x10u : 0u)
        | ((cover.flags & 0x200) != 0 ? 0x08u : 0u));
}

// Retail symbol: ??4idAICover@@QAAAAV0@ABV0@@Z
// EA: 0x82A88730, RVA: 0x00A88730
idAICover& idAICover::operator=(const idAICover& other) {
    if (this != &other) {
        aas = other.aas;
        spawnId = other.spawnId;
        coverIndex = other.coverIndex;
    }
    return *this;
}

// Retail symbol: ?Init@idAICover@@QAAXPBVidEntity@@PBVidAAS2@@H@Z
// EA: 0x82A88758, RVA: 0x00A88758
void idAICover::Init(const idEntity* const entity,
        const idAAS2* const newAas, const int index) {
    aas = newAas;
    spawnId = Tungsten_GetEntitySpawnId(entity);
    coverIndex = static_cast<short>(index);
}

// Header-origin retail helper used by GetEntity.  Entity event arguments
// store the complete spawn handle in the union's four-byte handle member.
idSpawnId idEventArg::GetEntitySpawnId() const {
    return type == D_EVENT_ENTITY
        ? idSpawnId(static_cast<int>(value.h)) : idSpawnId();
}

// Retail symbol: ?GetEntity@idEventArg@@QBAPBVidEntity@@XZ
// EA: 0x82A887A0, RVA: 0x00A887A0
const idEntity* idEventArg::GetEntity() const {
    return Tungsten_ResolveEntitySpawnId(GetEntitySpawnId().value);
}

// Retail symbol: ??8idAICover@@QBA_NABV0@@Z
// EA: 0x82A88888, RVA: 0x00A88888
bool idAICover::operator==(const idAICover& other) const {
    return spawnId == other.spawnId && aas == other.aas
        && coverIndex == other.coverIndex;
}

// Retail symbol: ??0idAICover@@QAA@PBVidAAS2@@H@Z
// EA: 0x82A888C8, RVA: 0x00A888C8
idAICover::idAICover(const idAAS2* const newAas, const int index)
    : aas(newAas)
    , spawnId(INVALID_SPAWN_ID)
    , coverIndex(static_cast<short>(index)) {
}

// Retail symbol: ?GetCoverPoint@idAICover@@QBAPBUaas2Cover_t@@XZ
// EA: 0x82A888E0, RVA: 0x00A888E0
const aas2Cover_t* idAICover::GetCoverPoint() const {
    if (coverIndex < 0 || aas == nullptr) {
        return nullptr;
    }
    if (spawnId.value == INVALID_SPAWN_ID) {
        return Tungsten_GetStaticAICoverPoint(*aas, coverIndex);
    }
    const idEntity* const entity =
        Tungsten_ResolveEntitySpawnId(spawnId.value);
    return entity != nullptr
        ? Tungsten_GetDynamicAICoverPoint(*entity, *aas, coverIndex)
        : nullptr;
}

// Retail symbol: ?Init@idAICover@@QAAXPBVidAAS2@@H@Z
// EA: 0x82A889C0, RVA: 0x00A889C0
void idAICover::Init(const idAAS2* const newAas, const int index) {
    aas = newAas;
    spawnId = INVALID_SPAWN_ID;
    coverIndex = static_cast<short>(index);
}

// Retail symbol: ?IsValid@idAICover@@QBA_NXZ
// EA: 0x82A889F8, RVA: 0x00A889F8
bool idAICover::IsValid() const {
    if (spawnId.value == INVALID_SPAWN_ID) {
        return aas != nullptr && coverIndex > 0;
    }
    if (Tungsten_ResolveEntitySpawnId(spawnId.value) == nullptr) {
        return false;
    }
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr && (cover->flags & 0x2000) == 0;
}

// Retail symbol: ?GetCoverPosture@idAICover@@QBA?AW4posture_t@@XZ
// EA: 0x82A88AC8, RVA: 0x00A88AC8
posture_t idAICover::GetCoverPosture() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr && (cover->flags & 0x1) != 0
        ? POSTURE_CROUCHED : POSTURE_STANDING;
}

// Retail symbol: ?GetAreaNum@idAICover@@QBAHXZ
// EA: 0x82A88B20, RVA: 0x00A88B20
int idAICover::GetAreaNum() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr ? cover->areaNum : 0;
}

// Retail symbol: ?GetOrigin@idAICover@@QBAABVidVec3@@XZ
// EA: 0x82A88B60, RVA: 0x00A88B60
const idVec3& idAICover::GetOrigin() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr ? cover->origin : ZeroVector();
}

// Retail symbol: ?GetDir@idAICover@@QBAABVidVec3@@XZ
// EA: 0x82A88B90, RVA: 0x00A88B90
const idVec3& idAICover::GetDir() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr ? cover->dir : ZeroVector();
}

// Retail symbol: ?GetAxis@idAICover@@QBAXAAVidMat3@@@Z
// EA: 0x82A88BD8, RVA: 0x00A88BD8
void idAICover::GetAxis(idMat3& axis) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    if (cover == nullptr || aas == nullptr) {
        axis = idMat3(1.0f);
        return;
    }
    axis[0] = cover->dir;
    axis[2] = Tungsten_GetAICoverGravityDirection(*aas);
    if (axis[2].NormalizeFast() == 0.0f) {
        axis[2].Set(0.0f, 0.0f, -1.0f);
    }
    axis[1] = axis[2].Cross(axis[0]);
    if (axis[1].NormalizeFast() == 0.0f) {
        axis[1].Set(0.0f, 1.0f, 0.0f);
    }
}

// Retail symbol: ?IsPartiallyExposed@idAICover@@QBA_NXZ
// EA: 0x82A88DE8, RVA: 0x00A88DE8
bool idAICover::IsPartiallyExposed() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover == nullptr || (cover->flags & 0x400) != 0;
}

// Retail symbol: ?IsFullyExposed@idAICover@@QBA_NXZ
// EA: 0x82A88E30, RVA: 0x00A88E30
bool idAICover::IsFullyExposed() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover == nullptr || (cover->flags & 0x3E0) == 0;
}

// Retail symbol: ?IsReserved@idAICover@@QBA_NXZ
// EA: 0x82A88E80, RVA: 0x00A88E80
bool idAICover::IsReserved() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr && cover->reservedBy != INVALID_SPAWN_ID;
}

// Retail symbol: ?GetReserver@idAICover@@QBAPBVidEntity@@XZ
// EA: 0x82A88EC8, RVA: 0x00A88EC8
const idEntity* idAICover::GetReserver() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr
        ? Tungsten_ResolveEntitySpawnId(cover->reservedBy) : nullptr;
}

// Retail symbol: ?Reserve@idAICover@@QBAXPBVidEntity@@@Z
// EA: 0x82A88F20, RVA: 0x00A88F20
void idAICover::Reserve(const idEntity* const reserver) const {
    aas2Cover_t* const cover = const_cast<aas2Cover_t*>(GetCoverPoint());
    if (cover != nullptr) {
        cover->reservedBy = Tungsten_GetEntitySpawnId(reserver);
    }
}

// Retail symbol: ?Unreserve@idAICover@@QBAXXZ
// EA: 0x82A88F80, RVA: 0x00A88F80
void idAICover::Unreserve() const {
    aas2Cover_t* const cover = const_cast<aas2Cover_t*>(GetCoverPoint());
    if (cover != nullptr) {
        cover->reservedBy = INVALID_SPAWN_ID;
    }
}

// Retail symbol: ?GetCoverActions@idAICover@@QBAXAAVidCoverActions@@@Z
// EA: 0x82A88FB0, RVA: 0x00A88FB0
void idAICover::GetCoverActions(idCoverActions& actions) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    if (cover != nullptr) {
        actions.Init(*cover);
    }
}

// Retail symbol: ?GetOrientation@idAICover@@QBAXW4coverOrientation_t@@AAVidMat3@@@Z
// EA: 0x82A88FF0, RVA: 0x00A88FF0
void idAICover::GetOrientation(const coverOrientation_t orientation,
        idMat3& axis) const {
    GetAxis(axis);
    if (orientation == COVERORIENT_BACKWARD) {
        axis[0] = -axis[0];
        axis[1] = -axis[1];
    }
}

// Retail symbol: ?IsPointInFrontOf@idAICover@@QBA_NABVidVec3@@@Z
// EA: 0x82A89080, RVA: 0x00A89080
bool idAICover::IsPointInFrontOf(const idVec3& point) const {
    return (point - GetOrigin()).Dot(GetDir()) > 0.0f;
}

// Retail symbol: ?IsPointInArc@idAICover@@QBA_NABVidVec3@@M@Z
// EA: 0x82A89158, RVA: 0x00A89158
bool idAICover::IsPointInArc(const idVec3& point,
        const float arcCosine) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    if (cover == nullptr) {
        return false;
    }
    const idVec3 delta = point - cover->origin;
    const float horizontalDistanceSqr = delta.x * delta.x + delta.y * delta.y;
    if (horizontalDistanceSqr < cover->minRange * cover->minRange
        || (cover->maxRange != 0.0f
            && horizontalDistanceSqr > cover->maxRange * cover->maxRange)) {
        return false;
    }
    if (horizontalDistanceSqr <= 0.0f
        || delta.z * delta.z > horizontalDistanceSqr) {
        return false;
    }
    const float inverseHorizontalDistance =
        1.0f / std::sqrt(horizontalDistanceSqr);
    const float facing = cover->dir.x * delta.x * inverseHorizontalDistance
        + cover->dir.y * delta.y * inverseHorizontalDistance;
    return facing >= arcCosine;
}

// Retail symbol: ?IsPointOnLeanSide@idAICover@@QBA_NABVidVec3@@@Z
// EA: 0x82A892F0, RVA: 0x00A892F0
bool idAICover::IsPointOnLeanSide(const idVec3& point) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    if (cover == nullptr) {
        return false;
    }
    if ((cover->flags & 0x3C0) == 0) {
        return true;
    }
    const idVec3 lateral(cover->dir.y, -cover->dir.x, 0.0f);
    const float side = (point - cover->origin).Dot(lateral);
    return side <= 0.0f
        ? (cover->flags & 0x140) != 0
        : (cover->flags & 0x280) != 0;
}

// Retail symbol: ?GetEyePoint@idAICover@@QBAXPBVidActor@@AAVidVec3@@@Z
// EA: 0x82A89420, RVA: 0x00A89420
void idAICover::GetEyePoint(const idActor* const user,
        idVec3& eyePoint) const {
    const idVec3& origin = GetOrigin();
    if (user == nullptr) {
        eyePoint = origin;
        return;
    }
    eyePoint = origin + Tungsten_GetAICoverActorEyeOffset(
        *user, GetCoverPosture());
}

// Retail symbol: ?GetFiringPoint@idAICover@@QBA_NPBVidActor@@W4firePoint_t@@AAVidVec3@@@Z
// EA: 0x82A894F0, RVA: 0x00A894F0
bool idAICover::GetFiringPoint(const idActor* const user,
        const firePoint_t firePointType, idVec3& firePoint) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    if (cover == nullptr || aas == nullptr || user == nullptr) {
        firePoint.Zero();
        return false;
    }

    idMat3 axis;
    GetAxis(axis);
    const float lateralOffset =
        Tungsten_GetAICoverLateralFireOffset(*aas, axis[1]) + 4.0f;
    idCoverActions actions;
    actions.Init(*cover);
    GetEyePoint(user, firePoint);
    const posture_t posture = GetCoverPosture();

    switch (firePointType) {
        case FIREPOINT_LEFT:
            if ((posture == POSTURE_CROUCHED
                    && (actions.actionBits & 0x40u) == 0)
                || (actions.actionBits & 0x60u) == 0) {
                return false;
            }
            firePoint = firePoint - axis[1] * lateralOffset;
            return true;

        case FIREPOINT_RIGHT:
            if ((posture == POSTURE_CROUCHED
                    && (actions.actionBits & 0x10u) == 0)
                || (actions.actionBits & 0x18u) == 0) {
                return false;
            }
            firePoint = firePoint + axis[1] * lateralOffset;
            return true;

        case FIREPOINT_OVER:
            if (posture != POSTURE_CROUCHED
                || (actions.actionBits & 0x80u) == 0) {
                return false;
            }
            firePoint = cover->origin + Tungsten_GetAICoverActorEyeOffset(
                *user, POSTURE_STANDING);
            return true;

        default:
            return false;
    }
}

// Retail symbol: ?GetExposedPoint@idAICover@@QBA_NW4firePoint_t@@AAVidVec3@@@Z
// EA: 0x82A89830, RVA: 0x00A89830
bool idAICover::GetExposedPoint(const firePoint_t firePointType,
        idVec3& exposedPoint) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    if (cover == nullptr) {
        exposedPoint.Zero();
        return false;
    }
    idMat3 axis;
    GetAxis(axis);
    idCoverActions actions;
    actions.Init(*cover);
    const posture_t posture = GetCoverPosture();

    switch (firePointType) {
        case FIREPOINT_LEFT:
            if ((posture == POSTURE_CROUCHED
                    && (actions.actionBits & 0x40u) == 0)
                || (actions.actionBits & 0x60u) == 0) {
                return false;
            }
            exposedPoint = cover->origin - axis[1] * 50.0f;
            return true;

        case FIREPOINT_RIGHT:
            if ((posture == POSTURE_CROUCHED
                    && (actions.actionBits & 0x10u) == 0)
                || (actions.actionBits & 0x18u) == 0) {
                return false;
            }
            exposedPoint = cover->origin + axis[1] * 50.0f;
            return true;

        case FIREPOINT_OVER:
            if (posture != POSTURE_CROUCHED
                || (actions.actionBits & 0x80u) == 0) {
                return false;
            }
            exposedPoint = cover->origin;
            return true;

        default:
            return false;
    }
}

// Retail symbol: ?VisibilityRatioFromFirePoints@idAICover@@QBAMPBVidActor@@PBVidAAS2@@H@Z
// EA: 0x82A89A98, RVA: 0x00A89A98
float idAICover::VisibilityRatioFromFirePoints(const idActor* const user,
        const idAAS2* const visibilityAas, const int areaNum) const {
    if (visibilityAas == nullptr) {
        return 0.0f;
    }
    float maximumRatio = 0.0f;
    for (int index = FIREPOINT_START; index < FIREPOINT_MAX; ++index) {
        idVec3 firePoint;
        if (GetFiringPoint(user, static_cast<firePoint_t>(index), firePoint)) {
            maximumRatio = std::max(maximumRatio,
                Tungsten_GetAICoverVisibilityRatio(
                    firePoint, *visibilityAas, areaNum));
        }
    }
    return maximumRatio;
}

// Retail symbol: ?MakeUnusable@idAICover@@QBAXH@Z
// EA: 0x82A89E18, RVA: 0x00A89E18
void idAICover::MakeUnusable(const int duration) const {
    aas2Cover_t* const cover = const_cast<aas2Cover_t*>(GetCoverPoint());
    if (cover != nullptr) {
        cover->usableTime = Tungsten_GetAICoverGameMilliseconds() + duration;
    }
}

// Retail symbol: ?IsUsable@idAICover@@QBA_NXZ
// EA: 0x82A89E78, RVA: 0x00A89E78
bool idAICover::IsUsable() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr
        && (Tungsten_GetAICoverGameMilliseconds() >= cover->usableTime
            || (cover->flags & 0x400000) != 0);
}

// Retail symbol: ?ShouldAvoid@idAICover@@QBA_NXZ
// EA: 0x82A89F10, RVA: 0x00A89F10
bool idAICover::ShouldAvoid() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr
        && Tungsten_GetAICoverGameMilliseconds() <= cover->usableTime
        && (cover->flags & 0x400000) != 0;
}

// Retail symbol: ?IsExplicit@idAICover@@QBA_NXZ
// EA: 0x82A89FA8, RVA: 0x00A89FA8
bool idAICover::IsExplicit() const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr && (cover->flags & 0x800) != 0;
}

// Retail symbol: ?IsExpired@idAICover@@QBA_NH@Z
// EA: 0x82A89FE8, RVA: 0x00A89FE8
bool idAICover::IsExpired(const int stayTime) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    return cover != nullptr && cover->durationSec > 0.0f
        && static_cast<float>(stayTime) > cover->durationSec * 1000.0f;
}

// Retail symbol: ?Spawn@idCoverBlocker@@QAAXXZ
// EA: 0x82A8A060, RVA: 0x00A8A060
void idCoverBlocker::Spawn() {
    Tungsten_RegisterCoverBlocker(*this);
}

// Retail symbol: ?AngleToPoint@idAICover@@QBAMABVidVec3@@_N@Z
// EA: 0x82A8A0C8, RVA: 0x00A8A0C8
float idAICover::AngleToPoint(const idVec3& point,
        const bool considerFireOver) const {
    const aas2Cover_t* const cover = GetCoverPoint();
    if (cover == nullptr) {
        return 0.0f;
    }

    idVec3 delta = point - cover->origin;
    delta.z *= 0.5f;
    if (delta.NormalizeFast() == 0.0f) {
        return 0.0f;
    }
    float angle = std::acos(ClampUnit(delta.Dot(cover->dir)));
    if (!considerFireOver || (cover->flags & 0x20) == 0) {
        const idVec3 lateral(cover->dir.y, -cover->dir.x, 0.0f);
        const float side = delta.Dot(lateral);
        const bool canUseSide = side <= 0.0f
            ? (cover->flags & 0x140) != 0
            : (cover->flags & 0x280) != 0;
        if (!canUseSide) {
            angle = -angle;
        }
    }
    constexpr float radiansToDegrees = 57.29577951308232f;
    return angle * radiansToDegrees;
}
