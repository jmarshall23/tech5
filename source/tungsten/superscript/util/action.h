#pragma once

#include "superscript/lib/list.h"
#include "superscript/sys/ssobject_core.h"

bool Tungsten_IsValidSuperScriptEntity(int spawnId);
void Tungsten_SetSuperScriptAlertCycle(int actorSpawnId, int alertCycle);
void Tungsten_SetSuperScriptWalkState(int actorSpawnId, int walkState);
void Tungsten_MoveSuperScriptEntityToGoal(int actorSpawnId, int goalSpawnId,
    bool stopUponArrival, float reachedDistance, bool align);
void Tungsten_ActivateSuperScriptEntity(
    int targetSpawnId, int activatorSpawnId);

class action_moveToGoalEntity : public idSuperScriptObject {
public:
    void OnActivate(ssEntity activator) override;

    ssEntity actor;
    ssEntity goal;
    ssEntity activationEntity;
    ssList<ssEntity> activationList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(action_moveToGoalEntity) == 36,
    "Recovered move-to-goal action ABI changed");
#endif
