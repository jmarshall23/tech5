#include "presentablecollisiontrigger.h"

namespace {

idPresentableCollisionTriggerServices defaultCollisionTriggerServices;
idPresentableCollisionTriggerServices* collisionTriggerServices =
    &defaultCollisionTriggerServices;

} // namespace

void Tungsten_SetPresentableCollisionTriggerServices(
        idPresentableCollisionTriggerServices* services) {
    collisionTriggerServices = services != nullptr ? services
                                                   : &defaultCollisionTriggerServices;
}

idPresentableCollisionTrigger::idPresentableCollisionTrigger()
    : targetPresentableSpawnId(0)
    , triggered(false) {
}

idPresentableCollisionTrigger::idPresentableCollisionTrigger(
        idEntity* newEntity, idRenderModel* renderModel,
        int newEntityNumber, const idDeclFX* declaration)
    : idPresentable(newEntity, renderModel, newEntityNumber, declaration)
    , targetPresentableSpawnId(0)
    , triggered(false) {
}

void idPresentableCollisionTrigger::Serialize(idSerializer& serializer) {
    idPresentable::Serialize(serializer);
    serializer.Serialize(targetPresentableSpawnId);
}

void idPresentableCollisionTrigger::PredictTouch(
        idPresentablePlayer* player) {
    if (triggered || player == nullptr || targetPresentableSpawnId == 0) {
        return;
    }
    idPresentable* target = collisionTriggerServices->ResolvePresentable(
        targetPresentableSpawnId);
    if (target != nullptr && target->spawnId == targetPresentableSpawnId) {
        target->ClientOverrideClipContents(1);
    }
}

