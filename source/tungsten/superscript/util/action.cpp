#include "action.h"

#include "superscript/lib/sys.h"

namespace {

bool IsValid(const ssEntity& entity) {
    return entity.spawnId != 0
        && Tungsten_IsValidSuperScriptEntity(entity.spawnId);
}

} // namespace

// ?OnActivate@action_moveToGoalEntity@@UAAXVssEntity@@@Z
// (0x82EECFE0)
void action_moveToGoalEntity::OnActivate(const ssEntity activator) {
    (void)activator;
    Tungsten_SuperScriptPrint("Actor sent to goal\n");

    if (!IsValid(actor) || !IsValid(goal)) {
        Tungsten_SuperScriptPrint("Actor or goal is not valid\n");
        return;
    }

    Tungsten_SetSuperScriptAlertCycle(actor.spawnId, 3);
    Tungsten_SetSuperScriptWalkState(actor.spawnId, 2);
    Tungsten_SuperScriptWaitFrame();
    Tungsten_MoveSuperScriptEntityToGoal(
        actor.spawnId, goal.spawnId, false, 16.0f, false);

    if (IsValid(activationEntity)) {
        Tungsten_ActivateSuperScriptEntity(
            activationEntity.spawnId, self.spawnId);
    }

    for (int index = 0; index < activationList.Num(); ++index) {
        const ssEntity& target = activationList[index];
        if (IsValid(target)) {
            Tungsten_ActivateSuperScriptEntity(
                target.spawnId, actor.spawnId);
        }
    }

    Tungsten_SuperScriptPrint("Actor reached goal\n");
}
