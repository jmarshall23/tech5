#pragma once

#include "game/entities/entityptr.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"

class idAI2;
class idEntity;
class idScenePoint;

enum aiMoveReason_t : int {
    AIMOVEREASON_UNKNOWN = 0,
    AIMOVEREASON_OC_MOVE_TOWARD_ENEMY = 1
};

enum aiArrivalAction_t : int {
    AIARRIVAL_UNKNOWN = 0,
    AIARRIVAL_CONTINUE = 1,
    AIARRIVAL_STOP = 2
};

enum posture_t : int {
    POSTURE_NONE = 0,
    POSTURE_STANDING = 1,
    POSTURE_CROUCHED = 2,
    POSTURE_SITTING = 3,
    POSTURE_MAX = 4
};

struct invalidSubWebIndex_t {};
struct invalidAnimStateIndex_t {};
using animSubWebIndex_t = idIndex<short, invalidSubWebIndex_t>;
using animStateIndex_t = idIndex<short, invalidAnimStateIndex_t>;

int Tungsten_GetEntitySpawnId(const idEntity* entity);
int Tungsten_GetScenePointSpawnId(const idScenePoint* scenePoint);
const idEntity* Tungsten_ResolveAIMoveGoalEntity(int spawnId);
const idVec3* Tungsten_GetKnownAIMoveGoalOrigin(
    const idAI2* ai, const idEntity* entity);
const idVec3& Tungsten_GetAIMoveEntityOrigin(const idEntity* entity);

class idAIMoveParms {
public:
    enum flags_t : int {
        FLAG_USE_GOAL_ORIENTATION = 0x1,
        FLAG_ALLOW_START_TRANSITIONS = 0x2,
        FLAG_ALLOW_STOP_TRANSITIONS = 0x4,
        FLAG_ALLOW_SCRAMBLE_TRANSITIONS = 0x8,
        FLAG_ALLOW_TRANSITION_OVERSHOOT = 0x10,
        FLAG_PREVENT_STEP_AROUND_STARTS = 0x20,
        FLAG_USE_SMOOTH_TRANSITIONS = 0x40
    };

    idAIMoveParms();

    const idVec3& GetRelevantGoalOrigin(const idAI2* ai) const;
    void Init(aiMoveReason_t moveReason, const idVec3& startOrigin,
        const idVec3& goalOrigin, const idEntity* goalEntity,
        const idQuat& goalOrientation, const idScenePoint* goalScenePoint,
        float goalTolerance, float intermediateTolerance,
        aiArrivalAction_t arrivalAction, posture_t arrivalPosture, int flags,
        const animSubWebIndex_t& sourceSubWeb,
        const animStateIndex_t& sourceState,
        const animSubWebIndex_t& destSubWeb,
        const animStateIndex_t& destState);

    aiMoveReason_t moveReason;
    idVec3 startOrigin;
    idVec3 goalOrigin;
    idEntityPtr<idEntity> goalEntity;
    idQuat goalOrientation;
    idEntityPtr<const idScenePoint> goalScenePoint;
    float goalTolerance;
    float intermediateTolerance;
    posture_t arrivalPosture;
    aiArrivalAction_t arrivalAction;
    int flags;
    animSubWebIndex_t sourceSubWeb;
    animStateIndex_t sourceState;
    animSubWebIndex_t destSubWeb;
    animStateIndex_t destState;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIMoveParms) == 80,
    "Recovered AI move parameters ABI changed");
#endif
