#include "animfsm_humanoid.h"

idAIStateLite::idAIStateLite()
    : listenerList(nullptr)
    , listeningToList(nullptr)
    , subState(0) {
}

// Retail symbol: ?Reset@idAnimFSMHumanoid@@UAAXXZ
// EA: 0x82A7ED08, RVA: 0x00A7ED08
void idAnimFSMHumanoid::Reset() {
    Tungsten_ResetAnimFSMHumanoid(*this);
}

// Retail symbol:
// ?PrintDebugInfo@idAnimFSMHumanoid@@UAAXAAVidGuiListBox@@@Z
// EA: 0x82A7ED10, RVA: 0x00A7ED10
void idAnimFSMHumanoid::PrintDebugInfo(idGuiListBox& information) {
    Tungsten_PrintAnimFSMHumanoidDebug(*this, information);
}

// Retail symbol: ?GetState@idAnimFSMHumanoid@@MAAPAVidAIStateLite@@H@Z
// EA: 0x82A7ED18, RVA: 0x00A7ED18
idAIStateLite* idAnimFSMHumanoid::GetState(const int stateIndex) {
    switch (stateIndex) {
        case 0: return &stateIdle;
        case 1: return &stateMove;
        case 2: return &stateDead;
        default: return nullptr;
    }
}

// Retail symbol: ??1idAnimFSMHumanoid@@UAA@XZ
// EA: 0x82A7EED0, RVA: 0x00A7EED0
idAnimFSMHumanoid::~idAnimFSMHumanoid() {
    Tungsten_ShutdownHumanoidAnimState(*this, 2, stateDead);
    Tungsten_ShutdownHumanoidAnimState(*this, 1, stateMove);
    Tungsten_ShutdownHumanoidAnimState(*this, 0, stateIdle);
}

// Retail symbol: ??0idAnimFSMHumanoid@@QAA@XZ
// EA: 0x82A7EFC0, RVA: 0x00A7EFC0
idAnimFSMHumanoid::idAnimFSMHumanoid() {
    Tungsten_InitializeHumanoidAnimState(*this, 0, stateIdle);
    Tungsten_InitializeHumanoidAnimState(*this, 1, stateMove);
    Tungsten_InitializeHumanoidAnimState(*this, 2, stateDead);
    Reset();
}
