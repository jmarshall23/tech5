#include "presentablemultiplayertrigger.h"

#include <cmath>

namespace {

idPresentableMultiplayerTriggerServices defaultTriggerServices;
idPresentableMultiplayerTriggerServices* triggerServices =
    &defaultTriggerServices;

} // namespace

void Tungsten_SetPresentableMultiplayerTriggerServices(
        idPresentableMultiplayerTriggerServices* services) {
    triggerServices = services != nullptr ? services
        : &defaultTriggerServices;
}

idMultiplayerTriggerStrategy_BoostPad::
idMultiplayerTriggerStrategy_BoostPad()
    : fxAxis(1.0f)
    , fxOrigin(0.0f, 0.0f, 0.0f)
    , targetOrigin(0.0f, 0.0f, 0.0f)
    , acceleration(0.0f)
    , time(1000)
    , boostTime(3000)
    , hasTarget(false) {
}

void idMultiplayerTriggerStrategy_BoostPad::Think(
        idPresentableMultiplayerTrigger& trigger) {
    trigger.UpdateFX(fxOrigin, fxAxis, 1.0f, 0.0f);
}

void idPresentableMultiplayerTrigger::ServerThink(int) {
    if (strategy != nullptr) {
        strategy->Think(*this);
    }
}

void idPresentableMultiplayerTrigger::ClientThink(int currentTime,
        float fraction, bool) {
    Interpolate(currentTime, fraction);
    ServerThink(currentTime);
    UpdateSound();
    Present();
}

void idMultiplayerTriggerStrategy_BoostPad::Boost(
        idPresentableVehicle& car, const idVec3& pushVelocity) const {
    triggerServices->SetVehicleAngularVelocity(car,
        idVec3(0.0f, 0.0f, 0.0f));
    triggerServices->SetVehicleLinearVelocity(car, pushVelocity);
    triggerServices->StartVehicleBoostFX(car);
    triggerServices->SetVehicleExternalBoostDuration(car, boostTime);
}

void idMultiplayerTriggerStrategy_BoostPad::BoostPadActivateFX(
        idPresentableMultiplayerTrigger& trigger) const {
    triggerServices->ActivateBoostPadFX(trigger, fxOrigin, fxAxis,
        triggerServices->GetScaledGameTime());
}

void idPresentableMultiplayerTrigger::Touch(idPresentableVehicle* car) {
    if (car == nullptr) {
        return;
    }
    idList<idPresentableMultiplayerTrigger*, 5> triggers;
    triggerServices->CollectTouchingTriggers(*car, triggers);
    for (int triggerNumber = 0; triggerNumber < triggers.Num();
            ++triggerNumber) {
        idPresentableMultiplayerTrigger* trigger = triggers[triggerNumber];
        if (trigger != nullptr && trigger->strategy != nullptr
                && triggerServices->VehicleTouchesTrigger(*car, *trigger)) {
            trigger->strategy->Touch(*trigger, *car);
        }
    }
}

void idMultiplayerTriggerStrategy_BoostPad::Serialize(
        idSerializer& serializer) {
    serializer.Serialize(fxAxis);
    serializer.Serialize(fxOrigin);
    SERIALIZE_BOOL(serializer, hasTarget);
    if (hasTarget) {
        serializer.Serialize(targetOrigin);
    } else {
        serializer.Serialize(acceleration);
        serializer.Serialize(time);
    }
}

void idMultiplayerTriggerStrategy_BoostPad::BoostToTarget(
        idPresentableVehicle& car) const {
    const idVec3 gravity = triggerServices->GetVehicleGravity(car);
    const idVec3 gravityNormal =
        triggerServices->GetVehicleGravityNormal(car);
    const idVec3 delta = targetOrigin
        - triggerServices->GetVehicleOrigin(car);
    const float gravityMagnitude = gravity.Length();
    if (gravityMagnitude <= 1.0e-20f) {
        return;
    }

    const float normalDistance = gravityNormal.Dot(delta);
    const float flightTimeSquared = -2.0f * normalDistance
        / gravityMagnitude;
    if (flightTimeSquared <= 0.0f) {
        return;
    }

    const float flightTime = std::sqrt(flightTimeSquared);
    const idVec3 planarDelta = delta - gravityNormal * normalDistance;
    const idVec3 pushVelocity = planarDelta * (1.0f / flightTime)
        - gravity * (flightTime * 0.5f);
    Boost(car, pushVelocity);
}

void idPresentableMultiplayerTrigger::AllocStrategy(
        mpTriggerType_t triggerType) {
    idMultiplayerTriggerStrategy* replacement = nullptr;
    if (triggerType == MP_TRIGGER_TYPE_BOOSTPAD) {
        replacement = new idMultiplayerTriggerStrategy_BoostPad();
    }
    delete strategy;
    strategy = replacement;
}

void idMultiplayerTriggerStrategy_BoostPad::Touch(
        idPresentableMultiplayerTrigger& trigger, idPresentable& other) {
    idPresentableVehicle* car = other.GetVehicleInterface();
    if (car == nullptr) {
        return;
    }
    if (hasTarget) {
        BoostToTarget(*car);
    } else {
        triggerServices->MegaBoost(*car, acceleration, time);
    }
    BoostPadActivateFX(trigger);
}

idPresentableMultiplayerTrigger::idPresentableMultiplayerTrigger()
    : strategy(nullptr)
    , triggerEntity(nullptr) {
}

idPresentableMultiplayerTrigger::idPresentableMultiplayerTrigger(
        idMultiplayerTrigger* entity_, idRenderModel* renderModel,
        int entityNumber_, const idDeclFX* fxDecl_,
        idMultiplayerTriggerStrategy* strategy_)
    : idPresentable(reinterpret_cast<idEntity*>(entity_), renderModel,
        entityNumber_, fxDecl_)
    , strategy(strategy_)
    , triggerEntity(reinterpret_cast<idEntity*>(entity_)) {
}

idPresentableMultiplayerTrigger::~idPresentableMultiplayerTrigger() {
    delete strategy;
    strategy = nullptr;
    oldTouching.Clear();
    touching.Clear();
}

void idPresentableMultiplayerTrigger::Serialize(idSerializer& serializer) {
    idPresentable::Serialize(serializer);
    int triggerType = strategy != nullptr
        ? static_cast<int>(strategy->GetTriggerType())
        : static_cast<int>(MP_TRIGGER_TYPE_NONE);
    serializer.SerializeUMax(triggerType, MP_TRIGGER_TYPE_BOOSTPAD);
    const mpTriggerType_t serializedType =
        static_cast<mpTriggerType_t>(triggerType);
    const mpTriggerType_t currentType = strategy != nullptr
        ? strategy->GetTriggerType() : MP_TRIGGER_TYPE_NONE;
    if (serializedType != currentType) {
        AllocStrategy(serializedType);
    }
    if (strategy != nullptr) {
        strategy->Serialize(serializer);
    }
}
