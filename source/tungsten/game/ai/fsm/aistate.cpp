#include "aistate.h"

#include <string>

namespace {

idAIFSM* AsAIFSM(idFiniteStateMachine* const fsm) {
    return reinterpret_cast<idAIFSM*>(fsm);
}

idAIState* AsAIState(idState* const state) {
    return static_cast<idAIState*>(state);
}

const char* SafeText(const char* const text, const char* const fallback) {
    return text != nullptr ? text : fallback;
}

} // namespace

// Retail symbol:
// ?Evaluate@idAIStateTransition@@UBAHPAVidFiniteStateMachine@@PAVidState@@H@Z
// EA: 0x82AB2360, RVA: 0x00AB2360
int idAIStateTransition::Evaluate(idFiniteStateMachine* const parentFSM,
        idState* const state, const int currentTime) {
    idAI2* const ai = parentFSM != nullptr
        ? Tungsten_GetAIFSMOwner(*parentFSM) : nullptr;
    return Evaluate(ai, AsAIFSM(parentFSM), AsAIState(state), currentTime);
}

// Retail symbol:
// ?NameForTransitionCode@idAIStateTransition@@SAPBDW4aiTransCode_t@1@@Z
// EA: 0x82AB23B0, RVA: 0x00AB23B0
const char* idAIStateTransition::NameForTransitionCode(
        const aiTransCode_t transitionCode) {
    return SafeText(Tungsten_GetAITransitionCodeName(transitionCode), "");
}

// Retail symbol: ?InternalCanUse@idAIState@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA: 0x82AB2470, RVA: 0x00AB2470
bool idAIState::InternalCanUse(idFiniteStateMachine* const fsm,
        const int currentTime) {
    idAI2* const ai = fsm != nullptr ? Tungsten_GetAIFSMOwner(*fsm) : nullptr;
    return AIState_CanUse(ai, AsAIFSM(fsm), currentTime);
}

// Retail symbol: ?InternalEnterState@idAIState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA: 0x82AB24B8, RVA: 0x00AB24B8
void idAIState::InternalEnterState(idFiniteStateMachine* const fsm,
        const int currentTime) {
    idAI2* const ai = fsm != nullptr ? Tungsten_GetAIFSMOwner(*fsm) : nullptr;
    AIState_EnterState(ai, AsAIFSM(fsm), currentTime);
}

// Retail symbol: ?InternalExitState@idAIState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA: 0x82AB2500, RVA: 0x00AB2500
void idAIState::InternalExitState(idFiniteStateMachine* const fsm,
        const int currentTime) {
    idAI2* const ai = fsm != nullptr ? Tungsten_GetAIFSMOwner(*fsm) : nullptr;
    AIState_ExitState(ai, AsAIFSM(fsm), currentTime);
}

// Retail symbol: ?InternalWork@idAIState@@UAAXPAVidFiniteStateMachine@@H@Z
// EA: 0x82AB2548, RVA: 0x00AB2548
void idAIState::InternalWork(idFiniteStateMachine* const fsm,
        const int currentTime) {
    idAI2* const ai = fsm != nullptr ? Tungsten_GetAIFSMOwner(*fsm) : nullptr;
    AIState_Work(ai, AsAIFSM(fsm), currentTime);
}

// Retail symbol:
// ?InternalReenterState@idAIState@@UAAXPAVidFiniteStateMachine@@HH@Z
// EA: 0x82AB2590, RVA: 0x00AB2590
void idAIState::InternalReenterState(idFiniteStateMachine* const fsm,
        const int transitionCode, const int currentTime) {
    idAI2* const ai = fsm != nullptr ? Tungsten_GetAIFSMOwner(*fsm) : nullptr;
    AIState_ReenterState(
        ai, AsAIFSM(fsm), transitionCode, currentTime);
}

// Retail symbol:
// ?InternalIsStateWaiting@idAIState@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA: 0x82AB25E0, RVA: 0x00AB25E0
bool idAIState::InternalIsStateWaiting(idFiniteStateMachine* const fsm,
        const int currentTime) {
    idAI2* const ai = fsm != nullptr ? Tungsten_GetAIFSMOwner(*fsm) : nullptr;
    return AIState_IsWaiting(ai, AsAIFSM(fsm), currentTime);
}

// Retail symbol:
// ?InternalSave@idAIStateTransitionStatic@@UBAXAAVidFile_String@@PBDABV?$idList@UtransDest_t@idStateTransition@@$04@@@Z
// EA: 0x82AB2628, RVA: 0x00AB2628
void idAIStateTransitionStatic::InternalSave(idFile_String& file,
        const char* const indent,
        const idList<transDest_t, 5>& destinations) {
    const char* const safeIndent = SafeText(indent, "");
    for (int index = 0; index < destinations.Num(); ++index) {
        const transDest_t& destination = destinations[index];
        const char* const className = SafeText(
            Tungsten_GetAIStateTypeClassname(destination.nextStateType),
            "NULL");

        std::string line = std::string(safeIndent) + "\tto \""
            + className + "\"";
        if (destination.transCode != 0) {
            line += " (";
            line += NameForTransitionCode(destination.transCode);
            line += ")";
        }
        line += "\n";
        Tungsten_AppendAIStateText(file, line.c_str());
    }
}

// Retail symbol: ?StartQueuedActions@idAIState@@QAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA: 0x82AB2760, RVA: 0x00AB2760
void idAIState::StartQueuedActions(idAI2* const ai,
        idAIFSM* const parentFSM, const int currentTime) {
    if (ai == nullptr) {
        return;
    }

    idFiniteStateMachine* const legsFSM = Tungsten_GetAILegsActionFSM(*ai);
    if (legsFSM != nullptr) {
        Tungsten_StartAILegsQueuedActions(*legsFSM);
    }
    if (childFSM != nullptr && childFSM != legsFSM && parentFSM != nullptr) {
        Tungsten_ExitAIChildStates(*childFSM, *parentFSM, currentTime);
    }
    if (parentFSM != nullptr) {
        Tungsten_SetAIStateChildFSM(*this, *parentFSM, legsFSM);
    }
}

// Retail symbol: ?ClearQueuedActions@idAIState@@QAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA: 0x82AB27E0, RVA: 0x00AB27E0
void idAIState::ClearQueuedActions(idAI2* const ai,
        idAIFSM* const parentFSM, const int currentTime) {
    if (ai == nullptr) {
        return;
    }

    idFiniteStateMachine* const legsFSM = Tungsten_GetAILegsActionFSM(*ai);
    if (legsFSM != nullptr) {
        Tungsten_ClearAILegsQueuedActions(*legsFSM);
    }
    if (childFSM != nullptr && childFSM != legsFSM && parentFSM != nullptr) {
        Tungsten_ExitAIChildStates(*childFSM, *parentFSM, currentTime);
    }
    if (parentFSM != nullptr) {
        Tungsten_SetAIStateChildFSM(*this, *parentFSM, nullptr);
    }
}
