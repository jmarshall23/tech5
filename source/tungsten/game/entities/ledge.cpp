#include "game/entities/ledge.h"

#include <cmath>

namespace {
constexpr float LEDGE_PLAYER_WIDTH = 26.0f;
constexpr int LEDGE_DEBUG_LIFETIME = 100000;

idLedgeServices defaultLedgeServices;
idLedgeServices* ledgeServices = &defaultLedgeServices;

float DistanceSqr(const idVec3& left, const idVec3& right) {
    return (left - right).LengthSqr();
}

const char* BuiltInAlias(idContextualShimmyState_t state) {
    switch (state) {
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_0:
        return "shimmy/mount_0_left";
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_0:
        return "shimmy/mount_0_right";
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0:
        return "shimmy/mount_0_back";
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_90:
        return "shimmy/mount_90_left";
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_90:
        return "shimmy/mount_90_right";
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_LEFT_180:
        return "shimmy/mount_180_left";
    case CONTEXTUAL_SHIMMY_STATE_MOUNT_RIGHT_180:
        return "shimmy/mount_180_right";
    case CONTEXTUAL_SHIMMY_STATE_CLIMB_OUT:
        return "shimmy/insidesshq_climbout";
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT:
        return "shimmy/dismount_right";
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD:
        return "shimmy/dismount_forward";
    case CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT:
        return "shimmy/dismount_left";
    default:
        return nullptr;
    }
}

void DrawTurnArrow(const idLedge::idLedgeBit& bit, bool atFirst,
        bool outside, const idColor& color) {
    const idVec3 endpoint = atFirst ? bit.firstPoint : bit.secondPoint;
    const idVec3 along = (atFirst ? bit.direction * -1.0f : bit.direction)
        * 6.0f;
    const idVec3 across = bit.normal * (outside ? -6.0f : 2.0f);
    const idVec3 arrowStart = endpoint + along + across
        + idVec3(0.0f, 0.0f, -1.0f);
    const idVec3 arrowEnd = endpoint
        + (atFirst ? bit.direction * -2.0f : bit.direction * 2.0f)
        + bit.normal * 2.0f + idVec3(0.0f, 0.0f, -1.0f);
    idLedge::Services().DebugArrow(color, arrowStart, arrowEnd,
        1.0f, LEDGE_DEBUG_LIFETIME);
}
} // namespace

idPlayer* idLedgeServices::CastPlayer(idEntity*) const { return nullptr; }
bool idLedgeServices::IsPlayerInShimmy(const idPlayer*) const {
    return false;
}
int idLedgeServices::GetBaseUsableState(const idUseLedge& use,
        const idEntity* activator, const void* focusTrace) const {
    return use.idEntity::GetUsableState(activator, focusTrace);
}
idVec3 idLedgeServices::GetPlayerOrigin(const idPlayer*) const {
    return idVec3(0.0f, 0.0f, 0.0f);
}
idVec3 idLedgeServices::GetEntityOrigin(const idEntity* entity) const {
    return entity != nullptr ? entity->origin : idVec3(0.0f, 0.0f, 0.0f);
}
int idLedgeServices::LoadAnimationAlias(
        const idUseLedge&, const char*, bool) {
    return -1;
}
void idLedgeServices::MountPlayer(
        idPlayer&, idLedge&, int, const idVec3&, idUseLedge&) {}
void idLedgeServices::DebugLine(
        const idColor&, const idVec3&, const idVec3&, int) {}
void idLedgeServices::DebugArrow(
        const idColor&, const idVec3&, const idVec3&, float, int) {}

void idLedge::SetServices(idLedgeServices* services) {
    ledgeServices = services != nullptr ? services : &defaultLedgeServices;
}

idLedgeServices& idLedge::Services() { return *ledgeServices; }

idLedge::idLedgeBit::idLedgeBit()
    : firstPoint(0.0f, 0.0f, 0.0f),
      secondPoint(0.0f, 0.0f, 0.0f), direction(0.0f, 0.0f, 0.0f),
      normal(0.0f, 0.0f, 0.0f), length(0.0f), flags(CONNECTED_NONE) {}

// Retail: 0x82C68AD0
int idUseLedge::GetUsableState(const idEntity* activator,
        const void* focusTrace) const {
    idPlayer* const player = idLedge::Services().CastPlayer(
        const_cast<idEntity*>(activator));
    if (player == nullptr) return 0;
    const bool isDismount =
        mountType == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_RIGHT
        || mountType == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_FORWARD
        || mountType == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_LEFT
        || mountType == CONTEXTUAL_SHIMMY_STATE_DISMOUNT_CUSTOMANIM;
    if (idLedge::Services().IsPlayerInShimmy(player) && !isDismount) {
        return 0;
    }
    return idLedge::Services().GetBaseUsableState(
        *this, activator, focusTrace);
}

// Retail: 0x82C68B50
void idLedge::DebugRender() {
    for (int index = 0; index < ledgeBits.Num(); ++index) {
        const idLedgeBit& bit = ledgeBits[index];
        Services().DebugLine(idColor::colorRed, bit.firstPoint,
            bit.secondPoint, LEDGE_DEBUG_LIFETIME);
        const idVec3 center = (bit.firstPoint + bit.secondPoint) * 0.5f;
        Services().DebugLine(idColor::colorGreen, center,
            center + bit.normal * 15.0f, LEDGE_DEBUG_LIFETIME);

        if ((bit.flags & (CONNECTED_FIRST_90_INLEFT
                | CONNECTED_FIRST_90_INRIGHT)) != 0) {
            DrawTurnArrow(bit, true, false,
                (bit.flags & CONNECTED_FIRST_90_INRIGHT) != 0
                    ? idColor::colorYellow : idColor::colorBlue);
        }
        if ((bit.flags & (CONNECTED_FIRST_90_OUTLEFT
                | CONNECTED_FIRST_90_OUTRIGHT)) != 0) {
            DrawTurnArrow(bit, true, true,
                (bit.flags & CONNECTED_FIRST_90_OUTRIGHT) != 0
                    ? idColor::colorYellow : idColor::colorBlue);
        }
        if ((bit.flags & (CONNECTED_SECOND_90_INLEFT
                | CONNECTED_SECOND_90_INRIGHT)) != 0) {
            DrawTurnArrow(bit, false, false,
                (bit.flags & CONNECTED_SECOND_90_INRIGHT) != 0
                    ? idColor::colorYellow : idColor::colorBlue);
        }
        if ((bit.flags & (CONNECTED_SECOND_90_OUTLEFT
                | CONNECTED_SECOND_90_OUTRIGHT)) != 0) {
            DrawTurnArrow(bit, false, true,
                (bit.flags & CONNECTED_SECOND_90_OUTRIGHT) != 0
                    ? idColor::colorYellow : idColor::colorBlue);
        }
    }
}

// Retail: 0x82C69360
int idLedge::GetClosestPoint(const idVec3& playerPosition,
        idVec3& point) const {
    int closestBit = -1;
    float closestDistance = 1.0e30f;
    point = playerPosition;
    for (int index = 0; index < ledgeBits.Num(); ++index) {
        const idLedgeBit& bit = ledgeBits[index];
        const float firstDistance = DistanceSqr(
            bit.firstPoint, playerPosition);
        if (firstDistance < closestDistance) {
            closestDistance = firstDistance;
            closestBit = index;
            point = bit.firstPoint;
        }
        const float secondDistance = DistanceSqr(
            bit.secondPoint, playerPosition);
        if (secondDistance < closestDistance) {
            closestDistance = secondDistance;
            closestBit = index;
            point = bit.secondPoint;
        }
    }
    return closestBit;
}

// Retail: 0x82C696B8
idLedge::ledgeEdgeType_t idLedge::idLedgeBit::GetPointOnLedge(
        const idPlayer* player, idVec3& pointOut, bool flipped) const {
    const idVec3 playerPosition = idLedge::Services().GetPlayerOrigin(player);
    const idVec3 ledgeStart = flipped ? secondPoint : firstPoint;
    const idVec3 ledgeDirection = flipped ? direction * -1.0f : direction;
    const float projectedDistance =
        (playerPosition - ledgeStart).Dot(ledgeDirection);
    pointOut = ledgeStart + ledgeDirection * projectedDistance;

    const int firstFlags = flipped ? 0xf0 : 0x0f;
    const int secondFlags = flipped ? 0x0f : 0xf0;
    if (projectedDistance - LEDGE_PLAYER_WIDTH < 0.0f) {
        return (flags & firstFlags) == 0
            ? EDGETYPE_LEFTEDGE : EDGETYPE_LEFTEDGE_HASTURN;
    }
    if (projectedDistance + LEDGE_PLAYER_WIDTH > length) {
        return (flags & secondFlags) == 0
            ? EDGETYPE_RIGHTEDGE : EDGETYPE_RIGHTEDGE_HASTURN;
    }
    return EDGETYPE_NONE;
}

// Retail: 0x82C69850
void idUseLedge::Event_PostSpawn() {
    if (!customLegsAnimation.IsEmpty()) {
        customLegsAnimationHandle = idLedge::Services().LoadAnimationAlias(
            *this, customLegsAnimation.c_str(), false);
    }
    if (!customHandsAnimation.IsEmpty()) {
        customHandsAnimationHandle = idLedge::Services().LoadAnimationAlias(
            *this, customHandsAnimation.c_str(), true);
    }
    const char* const builtIn = BuiltInAlias(mountType);
    if (builtIn != nullptr) {
        idLedge::Services().LoadAnimationAlias(*this, builtIn, false);
        if (mountType == CONTEXTUAL_SHIMMY_STATE_CLIMB_OUT) {
            idLedge::Services().LoadAnimationAlias(*this, builtIn, true);
        }
    }
}

// Retail: 0x82C69AF8
idUseLedge::idUseLedge()
    : mountType(CONTEXTUAL_SHIMMY_STATE_MOUNT_BACK_0),
      targetPositionEntity(nullptr), endPositionEntity(nullptr),
      customLegsAnimationHandle(-1), customHandsAnimationHandle(-1),
      useEnabled(true), hideAfterUse(false) {}

// Retail: 0x82C69CB0
idLedge::idLedge()
    : ledgeNormalHint(LEDGETYPE_CLOCKWISE), splineType(0),
      maxDeltaYaw(-1.0f), maxDeltaPitch(-1.0f), debugRender(false) {}

// Retail: 0x82C69D50
bool idUseLedge::Use(idEntity* activator, int usableState) {
    idPlayer* const player = idLedge::Services().CastPlayer(activator);
    if (!useEnabled || player == nullptr || targets.Num() < 1) return false;
    idLedge* const ledge = dynamic_cast<idLedge*>(targets[0]);
    if (ledge == nullptr) return false;

    idEntity::Use(activator, usableState);
    idVec3 point;
    int closestBit = -1;
    if (targetPositionEntity != nullptr) {
        const idVec3 targetPosition =
            idLedge::Services().GetEntityOrigin(targetPositionEntity);
        closestBit = ledge->GetClosestPoint(targetPosition, point);
    } else {
        const idVec3 playerPosition =
            idLedge::Services().GetPlayerOrigin(player);
        closestBit = ledge->GetClosestPoint(playerPosition, point);
        if (closestBit != -1) {
            ledge->ledgeBits[closestBit].GetPointOnLedge(
                player, point,
                ledge->ledgeNormalHint == idLedge::LEDGETYPE_CLOCKWISE);
        }
    }
    idLedge::Services().MountPlayer(
        *player, *ledge, closestBit, point, *this);
    if (hideAfterUse) Hide();
    return true;
}

// Retail: 0x82C69FA0
void idLedge::Spawn() {
    const int bitCount = controlPoints.Num() > 0
        ? controlPoints.Num() - 1 : 0;
    if (!ledgeBits.SetNum(bitCount)) return;

    for (int index = 0; index < bitCount; ++index) {
        idLedgeBit& bit = ledgeBits[index];
        const idLedgeBit* const previous = index > 0
            ? &ledgeBits[index - 1] : nullptr;
        bit.firstPoint = controlPoints[index];
        bit.secondPoint = controlPoints[index + 1];
        bit.direction = bit.secondPoint - bit.firstPoint;
        bit.length = bit.direction.Length();
        if (bit.length > 0.0f) {
            bit.direction = bit.direction * (1.0f / bit.length);
        }
        else bit.direction.Set(0.0f, 0.0f, 0.0f);
        bit.normal = ledgeNormalHint == LEDGETYPE_CLOCKWISE
            ? idVec3(bit.direction.y, -bit.direction.x, 0.0f)
            : idVec3(-bit.direction.y, bit.direction.x, 0.0f);
        bit.flags = CONNECTED_NONE;

        if (previous != nullptr) {
            idLedgeBit& mutablePrevious = ledgeBits[index - 1];
            const float turn = bit.direction.y * previous->direction.x
                - bit.direction.x * previous->direction.y;
            const float facing = bit.direction.Dot(previous->normal);
            if (turn > 0.0f) {
                if (facing <= 0.0f) {
                    mutablePrevious.flags |= CONNECTED_SECOND_90_OUTLEFT;
                    bit.flags |= CONNECTED_FIRST_90_OUTRIGHT;
                } else {
                    mutablePrevious.flags |= CONNECTED_SECOND_90_INLEFT;
                    bit.flags |= CONNECTED_FIRST_90_INRIGHT;
                }
            } else if (facing <= 0.0f) {
                mutablePrevious.flags |= CONNECTED_SECOND_90_OUTRIGHT;
                bit.flags |= CONNECTED_FIRST_90_OUTLEFT;
            } else {
                mutablePrevious.flags |= CONNECTED_SECOND_90_INRIGHT;
                bit.flags |= CONNECTED_FIRST_90_INLEFT;
            }
        }
    }
    if (debugRender) DebugRender();
}
