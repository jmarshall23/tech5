#include "aifsmmanager.h"

#include <algorithm>

namespace {

// This is the constructor order from the retail object.  Destruction is the
// exact reverse, which matters for the embedded FSMs' cross-references.
const idAIFSMKind kConstructionOrder[AIFSM_COUNT] = {
    AIFSM_ALERT_CYCLE,
    AIFSM_RELAXED,
    AIFSM_COMBAT,
    AIFSM_SEARCH,
    AIFSM_AVOID,
    AIFSM_TAKE_COVER,
    AIFSM_OPEN_COMBAT,
    AIFSM_MELEE,
    AIFSM_ADVANCE,
    AIFSM_IN_COVER,
    AIFSM_BACK_STAND,
    AIFSM_COMBAT_SCENE_POINT,
    AIFSM_SEARCH_SCENE_POINT,
    AIFSM_ROAM_SCENE_POINT,
    AIFSM_FOLLOW_FRIENDLY,
    AIFSM_PLAYER_INTERACT,
    AIFSM_IDLE_TRACK_FRIENDLY
};

// Init uses a different order in the executable: back-stand is registered
// before take-cover, while the three scene-point machines are registered
// after the friendly/player machines.
const idAIFSMKind kInitializationOrder[AIFSM_COUNT] = {
    AIFSM_ALERT_CYCLE,
    AIFSM_RELAXED,
    AIFSM_COMBAT,
    AIFSM_SEARCH,
    AIFSM_AVOID,
    AIFSM_BACK_STAND,
    AIFSM_TAKE_COVER,
    AIFSM_OPEN_COMBAT,
    AIFSM_MELEE,
    AIFSM_ADVANCE,
    AIFSM_IN_COVER,
    AIFSM_FOLLOW_FRIENDLY,
    AIFSM_PLAYER_INTERACT,
    AIFSM_IDLE_TRACK_FRIENDLY,
    AIFSM_COMBAT_SCENE_POINT,
    AIFSM_SEARCH_SCENE_POINT,
    AIFSM_ROAM_SCENE_POINT
};

} // namespace

// Retail symbol: ??0idAIFSMManager@@QAA@XZ
// EA: 0x82AB1820, RVA: 0x00AB1820
idAIFSMManager::idAIFSMManager()
    : fsms()
    , builtIn{} {
    owner.Invalidate();
    fsms.SetGranularity(16);
    for (const idAIFSMKind kind : kConstructionOrder) {
        builtIn[static_cast<int>(kind)] =
            Tungsten_ConstructBuiltInAIFSM(*this, kind);
    }
}

// Retail symbol: ??1idAIFSMManager@@UAA@XZ
// EA: 0x82AB1C48, RVA: 0x00AB1C48
idAIFSMManager::~idAIFSMManager() {
    fsms.Clear();
    for (int index = AIFSM_COUNT - 1; index >= 0; --index) {
        const idAIFSMKind kind = kConstructionOrder[index];
        idAIFSM*& fsm = builtIn[static_cast<int>(kind)];
        if (fsm != nullptr) {
            Tungsten_DestroyBuiltInAIFSM(*this, kind, fsm);
            fsm = nullptr;
        }
    }
}

// Retail symbol: ?Init@idAIFSMManager@@QAAXPAVidEntity@@@Z
// EA: 0x82AB20A8, RVA: 0x00AB20A8
void idAIFSMManager::Init(idEntity* const newOwner) {
    owner.SetSpawnId(newOwner != nullptr
        ? Tungsten_GetEntitySpawnId(newOwner) : 0x1FFF);
    fsms.Clear();
    for (const idAIFSMKind kind : kInitializationOrder) {
        idAIFSM* const fsm = builtIn[static_cast<int>(kind)];
        if (fsm == nullptr) {
            continue;
        }
        fsms.Append(fsm);
        Tungsten_InitBuiltInAIFSM(*this, kind, *fsm);
    }
}
