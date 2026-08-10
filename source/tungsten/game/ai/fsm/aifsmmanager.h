#pragma once

#include "game/entities/entityptr.h"
#include "idlib/containers/list.h"

class idAIFSM;
class idEntity;

class idFSMManager {
public:
    virtual ~idFSMManager() = default;

    idEntityPtr<idEntity> owner;
};

enum idAIFSMKind : int {
    AIFSM_ALERT_CYCLE = 0,
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
    AIFSM_IDLE_TRACK_FRIENDLY,
    AIFSM_COUNT
};

class idAIFSMManager : public idFSMManager {
public:
    idAIFSMManager();
    ~idAIFSMManager() override;

    void Init(idEntity* newOwner);
    const idAIFSM* FindFSM(const class idTypeInfo* type) const;

    idList<idAIFSM*, 92> fsms;
    idAIFSM* builtIn[AIFSM_COUNT];
};

// Each concrete FSM remains embedded in the retail manager.  These hooks
// preserve its construction, destruction and state initialization until the
// individual FSM class layouts have been recovered.
idAIFSM* Tungsten_ConstructBuiltInAIFSM(
    idAIFSMManager& manager, idAIFSMKind kind);
void Tungsten_DestroyBuiltInAIFSM(
    idAIFSMManager& manager, idAIFSMKind kind, idAIFSM* fsm);
void Tungsten_InitBuiltInAIFSM(
    idAIFSMManager& manager, idAIFSMKind kind, idAIFSM& fsm);
int Tungsten_GetEntitySpawnId(const idEntity* entity);
