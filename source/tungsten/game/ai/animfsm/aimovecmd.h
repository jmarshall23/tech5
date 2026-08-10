#pragma once

#include "animwebstate.h"
#include "../aimoveparms.h"
#include "../aiorientation.h"
#include "../../entities/entityptr.h"
#include "../../../../shared/idlib/math/vector.h"

class idEntity;
class idEventDef;
class idGuiListBox;

template<int commandId>
class idFSMCmd {};

class idAIMoveCmd : public idFSMCmd<44> {
public:
    enum destEntityType_t : int {
        DEST_ENT_NONE = 0,
        DEST_ENT_ENEMY = 1,
        DEST_POS_GOAL = 2,
        DEST_POS_ENEMY_CLOSEST_POSITION = 3
    };

    enum DestinationType : int {
        MOVE_NONE = 0,
        MOVE_ENTITY = 1,
        MOVE_POSITION = 2
    };

    explicit idAIMoveCmd(const char* user = nullptr);
    virtual ~idAIMoveCmd();

    void Init();
    void Init(const char* user);
    void SetArriveRadius(float radius, float height);
    void SetArriveOrientation(aiArrivalOrientation_t orientation,
        const idMat3& axis);
    void SetDest(const idVec3& destination, destEntityType_t entityType);
    void SetDest(const idEntity* entity, destEntityType_t entityType);
    void PrintDebugInfo(idGuiListBox& information) const;
    idVec3 GetDestinationOrigin() const;

    DestinationType destType;
    idEntityPtr<idEntity> destEnt;
    idVec3 destPos;
    idVec3 destNormal;
    float destAnimUpdateDistanceMinSqr;
    idAnimWebState destAnim;
    bool useDestAnimAsIdle;
    destEntityType_t destEntityType;
    aiArrivalAction_t arrivalAction;
    float arrivalRadius;
    float arrivalHeight;
    float arrivalBuffer;
    float planeArrivalRadius;
    bool attemptArrivalAlign;
    aiArrivalOrientation_t arriveOrient;
    idMat3 arriveAxis;
    float arriveOrientAngleTolerance;
    int moveFlags;
    const idEventDef* startMoveEvent;
    aiMoveReason_t moveReason;
    bool allowStrafing;
    const char* userString;

    static idAIMoveCmd s_null;
};

class idAIMoveInfo {
public:
    idAIMoveInfo();

    idEntityPtr<idEntity> destEntity;
    idVec3 destPosition;
    idMat3 destOrientation;
    idVec3 destNormal;
    bool useDestOrientation;
    aiArrivalAction_t arrivalAction;
    float arrivalRadius;
    int moveFlags;
};

const char* Tungsten_GetAIMoveEntityName(int spawnId);
bool Tungsten_GetAIMoveDestinationEntityOrigin(
    int spawnId, idVec3& destinationOrigin);
const char* Tungsten_GetAIArrivalActionName(aiArrivalAction_t action);
void Tungsten_AppendAIMoveDebugRow(idGuiListBox& information,
    const char* label, const char* value);
