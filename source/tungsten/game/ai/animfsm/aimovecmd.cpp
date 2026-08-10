#include "aimovecmd.h"

#include <cstdio>

// Retail symbol: ??1idAIMoveCmd@@UAA@XZ
// EA: 0x82A68C38, RVA: 0x00A68C38
idAIMoveCmd::~idAIMoveCmd() = default;

// Retail symbol: ?SetArriveRadius@idAIMoveCmd@@QAAXMM@Z
// EA: 0x82A68C48, RVA: 0x00A68C48
void idAIMoveCmd::SetArriveRadius(const float radius, const float height) {
    arrivalRadius = radius;
    arrivalHeight = height;
}

// Retail symbol:
// ?SetArriveOrientation@idAIMoveCmd@@QAAXW4aiArrivalOrientation_t@@ABVidMat3@@@Z
// EA: 0x82A68CB0, RVA: 0x00A68CB0
void idAIMoveCmd::SetArriveOrientation(
        const aiArrivalOrientation_t orientation, const idMat3& axis) {
    arriveOrient = orientation;
    arriveAxis = axis;
}

// Retail symbol: ?SetDest@idAIMoveCmd@@QAAXABVidVec3@@W4destEntityType_t@1@@Z
// EA: 0x82A68D08, RVA: 0x00A68D08
void idAIMoveCmd::SetDest(const idVec3& destination,
        const destEntityType_t entityType) {
    destType = MOVE_POSITION;
    destPos = destination;
    destEntityType = entityType;
}

// Retail symbol: ??0idAIMoveInfo@@QAA@XZ
// EA: 0x82A68D30, RVA: 0x00A68D30
idAIMoveInfo::idAIMoveInfo()
    : destEntity()
    , destPosition(0.0f, 0.0f, 0.0f)
    , destOrientation(1.0f)
    , destNormal(0.0f, 0.0f, 1.0f)
    , useDestOrientation(false)
    , arrivalAction(AIARRIVAL_STOP)
    , arrivalRadius(0.0f)
    , moveFlags(0) {
}

// Retail symbol: ?Init@idAIMoveCmd@@QAAXXZ
// EA: 0x82A68DC0, RVA: 0x00A68DC0
void idAIMoveCmd::Init() {
    destType = MOVE_NONE;
    destEnt.Invalidate();
    destPos.Set(0.0f, 0.0f, 0.0f);
    destNormal.Set(0.0f, 0.0f, 1.0f);
    destAnimUpdateDistanceMinSqr = 0.0f;
    destAnim.Clear();
    useDestAnimAsIdle = false;
    destEntityType = DEST_ENT_NONE;
    arrivalAction = AIARRIVAL_STOP;
    arrivalRadius = 0.0f;
    arrivalHeight = -1.0f;
    arrivalBuffer = 0.0f;
    planeArrivalRadius = 0.0f;
    attemptArrivalAlign = false;
    arriveOrient = AIARRIVAL_ORIENT_NONE;
    arriveAxis = idMat3(1.0f);
    arriveOrientAngleTolerance = 30.0f;
    moveFlags = 0;
    startMoveEvent = nullptr;
    moveReason = AIMOVEREASON_UNKNOWN;
    allowStrafing = false;
    userString = nullptr;
}

// Retail symbol: ?Init@idAIMoveCmd@@QAAXPBD@Z
// EA: 0x82A68F00, RVA: 0x00A68F00
void idAIMoveCmd::Init(const char* const user) {
    Init();
    userString = user;
}

// Retail symbol: ?SetDest@idAIMoveCmd@@QAAXPBVidEntity@@W4destEntityType_t@1@@Z
// EA: 0x82A68F40, RVA: 0x00A68F40
void idAIMoveCmd::SetDest(const idEntity* const entity,
        const destEntityType_t entityType) {
    destType = MOVE_ENTITY;
    destEnt.SetSpawnId(entity != nullptr
        ? Tungsten_GetEntitySpawnId(entity) : 0x1FFF);
    destEntityType = entityType;
}

// Retail symbol: ?PrintDebugInfo@idAIMoveCmd@@QBAXAAVidGuiListBox@@@Z
// EA: 0x82A68F90, RVA: 0x00A68F90
void idAIMoveCmd::PrintDebugInfo(idGuiListBox& information) const {
    Tungsten_AppendAIMoveDebugRow(information, "MoveCmd User",
        userString != nullptr ? userString : "<unknown>");

    if (destType == MOVE_ENTITY) {
        const char* const entityName =
            Tungsten_GetAIMoveEntityName(destEnt.GetSpawnId());
        Tungsten_AppendAIMoveDebugRow(information, "MoveCmd Dest Ent",
            entityName != nullptr ? entityName : "<null entity>");
    } else if (destType == MOVE_POSITION) {
        char position[96];
        std::snprintf(position, sizeof(position), "%.1f %.1f %.1f",
            destPos.x, destPos.y, destPos.z);
        Tungsten_AppendAIMoveDebugRow(
            information, "MoveCmd Dest Pos", position);
    } else {
        Tungsten_AppendAIMoveDebugRow(information, "MoveCmd None", "");
    }

    const char* const actionName =
        Tungsten_GetAIArrivalActionName(arrivalAction);
    Tungsten_AppendAIMoveDebugRow(information, "MoveCmd Arrive Action",
        actionName != nullptr ? actionName : "<unknown>");
}

// Retail symbol: ?GetDestinationOrigin@idAIMoveCmd@@QBA?AVidVec3@@XZ
// EA: 0x82A69128, RVA: 0x00A69128
idVec3 idAIMoveCmd::GetDestinationOrigin() const {
    if (destType == MOVE_POSITION) {
        return destPos;
    }
    if (destType == MOVE_ENTITY) {
        idVec3 destination;
        if (Tungsten_GetAIMoveDestinationEntityOrigin(
                destEnt.GetSpawnId(), destination)) {
            return destination;
        }
    }
    return idVec3(0.0f, 0.0f, 0.0f);
}

// Retail symbol: ??0idAIMoveCmd@@QAA@PBD@Z
// EA: 0x82A69228, RVA: 0x00A69228
idAIMoveCmd::idAIMoveCmd(const char* const user)
    : destEnt()
    , destAnim() {
    Init();
    userString = user;
    if (user != nullptr) {
        for (const char* cursor = user; *cursor != '\0'; ++cursor) {
            if (*cursor == '\\') {
                userString = cursor + 1;
            }
        }
    }
}

// The compiler-generated static-lifetime block at 0x83368248 constructs this
// singleton with the exact source diagnostic embedded in retail.
idAIMoveCmd idAIMoveCmd::s_null(
    "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AIMoveCmd.cpp(17) : null");
