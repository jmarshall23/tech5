#include "aianimwebstate.h"

// Retail symbol: ?GetMoveStateString@idAIAnimWebState@@MAAXPBVidAI2@@AAVidStr@@W4posture_t@@@Z
// EA: 0x82A62618, RVA: 0x00A62618
void idAIAnimWebState::GetMoveStateString(const idAI2* const ai,
        idStr& moveState, const posture_t) {
    moveState = ai != nullptr
        ? Tungsten_GetAIWalkStateName(Tungsten_GetAIWalkState(*ai)) : "";
}

// Retail symbol: ?VerifyFloorTrace@idAIAnimWebState@@QAA_NPBVidAI2@@@Z
// EA: 0x82A62670, RVA: 0x00A62670
bool idAIAnimWebState::VerifyFloorTrace(const idAI2* const ai) {
    if (ai == nullptr || !Verify()) {
        return false;
    }
    idVec3 animationDelta(0.0f, 0.0f, 0.0f);
    idMat3 deltaAxis;
    const idDeclMD6* const model = GetModel(0);
    if (!GetAnimDelta(model, 0, animationDelta, deltaAxis)) {
        return false;
    }
    idMat3 modelAxis;
    idVec3 origin;
    if (!Tungsten_GetAIAnimModelAxis(*ai, modelAxis)
        || !Tungsten_GetAIAnimOrigin(*ai, origin)) {
        return false;
    }
    const idVec3 destination = origin + modelAxis * animationDelta;
    return Tungsten_IsAIAnimLineInNavGraph(*ai, origin, destination);
}

// Retail symbol: ?VerifyPointOutsideAnimRange@idAIAnimWebState@@QAA_NPBVidAI2@@ABVidVec3@@@Z
// EA: 0x82A62828, RVA: 0x00A62828
bool idAIAnimWebState::VerifyPointOutsideAnimRange(
        const idAI2* const ai, const idVec3& point) {
    if (ai == nullptr || !Verify()) {
        return false;
    }
    idVec3 animationDelta(0.0f, 0.0f, 0.0f);
    idMat3 deltaAxis;
    const idDeclMD6* const model = GetModel(0);
    idVec3 origin;
    if (!GetAnimDelta(model, 0, animationDelta, deltaAxis)
        || !Tungsten_GetAIAnimOrigin(*ai, origin)) {
        return false;
    }
    return (point - origin).LengthSqr() > animationDelta.LengthSqr();
}

// Retail symbol: ?GetTurnStateString@idAIAnimWebState@@MAAXPBVidAI2@@AAVidStr@@@Z
// EA: 0x82A62948, RVA: 0x00A62948
void idAIAnimWebState::GetTurnStateString(
        const idAI2* const ai, idStr& turnState) {
    const int direction = ai != nullptr
        ? Tungsten_GetAICurrentTurnDirection(*ai) : 0;
    turnState = direction == 1 ? "turn_left"
        : direction == 2 ? "turn_right" : "";
}

// Retail symbol: ??0idAIAnimWebState@@QAA@PBVidAI2@@PBD1@Z
// EA: 0x82A629C0, RVA: 0x00A629C0
idAIAnimWebState::idAIAnimWebState(const idAI2* const ai,
        const char* const subWebName, const char* const stateName) {
    if (ai == nullptr) {
        return;
    }
    Init(Tungsten_GetAIAnimWebDeclaration(*ai),
        Tungsten_GetAIResolvedSubWebName(*ai, subWebName), stateName);
}

// Retail symbol: ??0idAIAnimWebState_Transition@@QAA@PBVidAI2@@AAUtransitionQueryResult_t@idAnimWebTransitions@@_N2@Z
// EA: 0x82A62AC0, RVA: 0x00A62AC0
idAIAnimWebState_Transition::idAIAnimWebState_Transition(
        const idAI2* const ai,
        idAnimWebTransitions::transitionQueryResult_t& result,
        const bool skipTrace,
        const bool skipVerifyPointOutsideAnimRange) {
    if (ai == nullptr) {
        return;
    }
    Init(Tungsten_GetAIAnimWebDeclaration(*ai), result.via.node);
    idVec3 nextPoint;
    if ((!skipVerifyPointOutsideAnimRange
            && (!Tungsten_GetAIAnimNextMovePoint(*ai, nextPoint)
                || !VerifyPointOutsideAnimRange(ai, nextPoint)))
        || (!skipTrace && !VerifyFloorTrace(ai))) {
        Clear();
    }
}

// Retail symbol: ??0idAIAnimWebState_Current@@QAA@PBVidAI2@@@Z
// EA: 0x82A62BC8, RVA: 0x00A62BC8
idAIAnimWebState_Current::idAIAnimWebState_Current(
        const idAI2* const ai) {
    if (ai != nullptr) {
        Init(Tungsten_GetAIAnimWebDeclaration(*ai),
            idAnimWebNodeIndex(Tungsten_GetAIAnimCurrentNode(*ai)));
    }
}

// Retail symbol: ??0idAIAnimWebState_Target@@QAA@PBVidAI2@@@Z
// EA: 0x82A62C58, RVA: 0x00A62C58
idAIAnimWebState_Target::idAIAnimWebState_Target(
        const idAI2* const ai) {
    if (ai == nullptr) {
        return;
    }
    short targetNode = Tungsten_GetAIAnimTargetNode(*ai);
    if (targetNode < 0) {
        targetNode = Tungsten_GetAIAnimCurrentNode(*ai);
    }
    Init(Tungsten_GetAIAnimWebDeclaration(*ai),
        idAnimWebNodeIndex(targetNode));
}

// Retail symbol: ?GetSubwebString@idAIAnimWebState@@SAXPBVidAI2@@AAVidStr@@W4aiSubWeb_t@@W4posture_t@@W4equipSlot_t@@@Z
// EA: 0x82A62D40, RVA: 0x00A62D40
void idAIAnimWebState::GetSubwebString(const idAI2* const ai,
        idStr& output, aiSubWeb_t subWeb, const posture_t posture,
        const equipSlot_t weaponSlot) {
    if (subWeb == AISUBWEB_MAX && ai != nullptr) {
        subWeb = Tungsten_GetAIAnimationSubWeb(*ai);
    }
    if (posture == POSTURE_MAX && ai != nullptr) {
        Tungsten_GetAIPosture(*ai);
    }
    const char* const subWebName = Tungsten_GetAISubWebName(subWeb);
    if (subWeb == AISUBWEB_DYING) {
        output = subWebName != nullptr ? subWebName : "";
        return;
    }
    const char* prefix = ai != nullptr
        ? Tungsten_GetAIAnimWeaponPrefix(*ai, weaponSlot) : nullptr;
    if (prefix == nullptr) {
        prefix = "hands_";
    }
    output = prefix;
    output.Append(subWebName != nullptr ? subWebName : "");
}

// Retail symbol: ??0idAIAnimWebState_Idle@@QAA@PBVidAI2@@W4aiSubWeb_t@@W4posture_t@@W4equipSlot_t@@@Z
// EA: 0x82A62E58, RVA: 0x00A62E58
idAIAnimWebState_Idle::idAIAnimWebState_Idle(const idAI2* const ai,
        const aiSubWeb_t subWeb, const posture_t posture,
        const equipSlot_t weaponSlot) {
    if (ai == nullptr) {
        return;
    }
    idStr subWebName;
    GetSubwebString(ai, subWebName, subWeb, posture, weaponSlot);
    Init(Tungsten_GetAIAnimWebDeclaration(*ai), subWebName.c_str(),
        Tungsten_GetAIIdleStateName(*ai));
}

// Retail symbol: ??0idAIAnimWebState_Movement@@QAA@PBVidAI2@@PBDW4aiSubWeb_t@@W4posture_t@@@Z
// EA: 0x82A62FA8, RVA: 0x00A62FA8
idAIAnimWebState_Movement::idAIAnimWebState_Movement(
        const idAI2* const ai, const char* const postfix,
        aiSubWeb_t subWeb, const posture_t posture) {
    if (ai == nullptr) {
        return;
    }
    if (subWeb == AISUBWEB_MAX) {
        subWeb = Tungsten_GetAIAnimationSubWeb(*ai);
        if (subWeb >= AISUBWEB_HOSTILE && subWeb != AISUBWEB_MELEE) {
            subWeb = Tungsten_AIAlertCycleToSubWeb(*ai, 1);
        }
    }
    idStr subWebName;
    GetSubwebString(ai, subWebName, subWeb, posture, EQUIP_MAX);
    idStr stateName(Tungsten_GetAIWalkStateName(
        Tungsten_GetAIWalkState(*ai)));
    if (postfix != nullptr) {
        stateName.Append(postfix);
    }
    Init(Tungsten_GetAIAnimWebDeclaration(*ai),
        subWebName.c_str(), stateName.c_str());
}

// Retail symbol: ??0idAIAnimWebState@@QAA@PBVidAI2@@W4aiSubWeb_t@@PBD@Z
// EA: 0x82A631B8, RVA: 0x00A631B8
idAIAnimWebState::idAIAnimWebState(const idAI2* const ai,
        const aiSubWeb_t subWeb, const char* const stateName) {
    if (ai == nullptr) {
        return;
    }
    idStr subWebName;
    GetSubwebString(ai, subWebName, subWeb,
        POSTURE_MAX, EQUIP_MAX);
    Init(Tungsten_GetAIAnimWebDeclaration(*ai),
        subWebName.c_str(), stateName);
}
