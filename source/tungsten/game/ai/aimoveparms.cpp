#include "aimoveparms.h"

// Retail symbol: ?GetRelevantGoalOrigin@idAIMoveParms@@QBAABVidVec3@@PBVidAI2@@@Z
// EA: 0x82A54D98, RVA: 0x00A54D98
const idVec3& idAIMoveParms::GetRelevantGoalOrigin(const idAI2* const ai) const {
    const idEntity* const entity = Tungsten_ResolveAIMoveGoalEntity(
        goalEntity.GetSpawnId());
    if (entity == nullptr) {
        return goalOrigin;
    }
    const idVec3* const knownOrigin = Tungsten_GetKnownAIMoveGoalOrigin(
        ai, entity);
    return knownOrigin != nullptr
        ? *knownOrigin : Tungsten_GetAIMoveEntityOrigin(entity);
}

// Retail symbol: ??0idAIMoveParms@@QAA@XZ
// EA: 0x82A54E68, RVA: 0x00A54E68
idAIMoveParms::idAIMoveParms()
    : moveReason(AIMOVEREASON_UNKNOWN)
    , startOrigin(0.0f, 0.0f, 0.0f)
    , goalOrigin(0.0f, 0.0f, 0.0f)
    , goalEntity()
    , goalOrientation(0.0f, 0.0f, 0.0f, 1.0f)
    , goalScenePoint()
    , goalTolerance(0.1f)
    , intermediateTolerance(0.1f)
    , arrivalPosture(POSTURE_STANDING)
    , arrivalAction(AIARRIVAL_UNKNOWN)
    , flags(0)
    , sourceSubWeb()
    , sourceState()
    , destSubWeb()
    , destState() {
}

// Retail symbol:
// ?Init@idAIMoveParms@@QAAXW4aiMoveReason_t@@ABVidVec3@@1PBVidEntity@@ABVidQuat@@PBVidScenePoint@@MMW4aiArrivalAction_t@@W4posture_t@@HABV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@78@Z
// EA: 0x82A54F00, RVA: 0x00A54F00
void idAIMoveParms::Init(
        const aiMoveReason_t moveReasonValue,
        const idVec3& startOriginValue,
        const idVec3& goalOriginValue,
        const idEntity* const goalEntityValue,
        const idQuat& goalOrientationValue,
        const idScenePoint* const goalScenePointValue,
        const float goalToleranceValue,
        const float intermediateToleranceValue,
        const aiArrivalAction_t arrivalActionValue,
        const posture_t arrivalPostureValue,
        const int flagsValue,
        const animSubWebIndex_t& sourceSubWebValue,
        const animStateIndex_t& sourceStateValue,
        const animSubWebIndex_t& destSubWebValue,
        const animStateIndex_t& destStateValue) {
    moveReason = moveReasonValue;
    startOrigin = startOriginValue;
    goalOrigin = goalOriginValue;
    goalEntity.SetSpawnId(Tungsten_GetEntitySpawnId(goalEntityValue));
    goalOrientation = goalOrientationValue;
    goalScenePoint.SetSpawnId(
        Tungsten_GetScenePointSpawnId(goalScenePointValue));
    goalTolerance = goalToleranceValue;
    intermediateTolerance = intermediateToleranceValue;
    arrivalPosture = arrivalPostureValue;
    arrivalAction = arrivalActionValue;
    flags = flagsValue;
    sourceSubWeb = sourceSubWebValue;
    sourceState = sourceStateValue;
    destSubWeb = destSubWebValue;
    destState = destStateValue;
}
