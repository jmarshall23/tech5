#include "aiscriptedanimweb.h"

#include "aidefs.h"

idAI2* Tungsten_ResolveAIScriptedAnimWebAI(int spawnId);
idAI2* Tungsten_ResolveAIScriptedAnimWebSpawnedAI(int spawnId);
void Tungsten_StartAIScriptedAnimWebAction(
    idAI2* ai, const char* eventName, const char* scriptName,
    idAIScriptedAnimWeb* executor, idEntity* activator, int currentTime);
int Tungsten_GetAIGameMilliseconds();

// Retail symbol:
// ?SetcurrentState@animState_t@idAIScriptedAnimWeb@@QAAXH@Z
// EA: 0x82A60660, RVA: 0x00A60660
void idAIScriptedAnimWeb::animState_t::SetcurrentState(int state) {
    if (animWebStates == nullptr
            || !(state >= 0 || state == STATE_RANDOM || state == STATE_EXIT)
            || animWebStates->Num() <= state) {
        return;
    }
    if (state == STATE_RANDOM) {
        state = RandomInt(animWebStates->Num());
        if (currentState != -1 && currentState == state) {
            state = (state + 1) % animWebStates->Num();
        }
    }
    currentState = state;
}

idAIScriptedAnimWeb::idAIScriptedAnimWeb() = default;

// Retail symbol: ?Spawn@idAIScriptedAnimWeb@@QAAXXZ
// EA: 0x82A60650, RVA: 0x00A60650
void idAIScriptedAnimWeb::Spawn() {
    stateInfo.animWebStates = &animWebStates;
}

// Retail symbol:
// ?StartAIAction@idAIScriptedAnimWeb@@QAAXPAVidEntity@@@Z
// EA: 0x82A607F8, RVA: 0x00A607F8
void idAIScriptedAnimWeb::StartAIAction(idEntity* const activator) {
    for (int index = 0; index < targets.Num(); ++index) {
        const int spawnId = targets[index].GetSpawnId();
        idAI2* ai = Tungsten_ResolveAIScriptedAnimWebAI(spawnId);
        if (ai == nullptr) {
            ai = Tungsten_ResolveAIScriptedAnimWebSpawnedAI(spawnId);
        }
        if (ai != nullptr) {
            Tungsten_StartAIScriptedAnimWebAction(
                ai, "action_ScriptedAnimWeb", name.c_str(), this, activator,
                Tungsten_GetAIGameMilliseconds());
        }
    }
}

// Retail symbol: ?OnActivate@idAIScriptedAnimWeb@@UAAXPAVidEntity@@@Z
// EA: 0x82A60AE8, RVA: 0x00A60AE8
void idAIScriptedAnimWeb::OnActivate(idEntity* const activator) {
    if (stateInfo.animWebStates != nullptr
            && stateInfo.animWebStates->Num() > 0) {
        stateInfo.currentState = 0;
    }
    StartAIAction(activator);
}
