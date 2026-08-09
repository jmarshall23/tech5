#include "gamelib/animstack/animator_vehiclecar.h"

idTreeAnimator* GameLib_GetTreeAnimator(idAnimStack* stack);
void GameLib_InitVehicleAnimation(idAnimator_VehicleCar& vehicle);
void GameLib_EvaluateVehicleAnimation(idAnimator_VehicleCar& vehicle);
int GameLib_InitVehicleDialMeter(idAnimator_VehicleCar& vehicle,
    int definitionIndex, idAnimDialMeter& meter);
void GameLib_DeleteVehicleWheel(idAnimWheel& wheel);
void GameLib_SerializeVehicleAnimator(idSerializer* serializer,
    idAnimator_VehicleCar& vehicle);

idAnimator_VehicleCar::idAnimator_VehicleCar()
    : idAnimator_Base()
    , animator(nullptr)
    , vehicleProps(nullptr)
    , animWheels(16)
    , clip(nullptr)
    , entityNum(0x1FFF)
    , renderModel(nullptr)
    , dialMeters(16)
    , speedometer(-1)
    , tachometer(-1)
    , clipMask(0)
    , accelerating(false)
    , handBraking(false)
    , isReversing(false)
    , playerOccupant(false)
    , rotateSteeringWheel(false)
    , steeringWheelJoint()
    , steeringWheelAxis(0.0f, 0.0f, 0.0f)
    , steeringWheelJointQuat(0.0f, 0.0f, 0.0f, 1.0f)
    , steerAngle(0.0f)
    , lastSteerAngle(0.0f)
    , newSteerAngle(0.0f)
    , updateWheelAngle(false)
    , isOnElevator(false) {
}

idAnimator_VehicleCar::~idAnimator_VehicleCar() {
    DeleteAnimWheels();
    animator = nullptr;
    vehicleProps = nullptr;
    clip = nullptr;
    renderModel = nullptr;
}

void idAnimator_VehicleCar::SetPlayerOccupant(const bool occupied) {
    playerOccupant = occupied;
}

void idAnimator_VehicleCar::SetTireWobble(const int wheelIndex,
        const float wobble) {
    if (wheelIndex >= 0 && wheelIndex < animWheels.Num())
        animWheels[wheelIndex].wobbleFrac = wobble;
}

idJointIndex idAnimator_VehicleCar::InternalGetDialMeterJointIndex(
        const int meterIndex) const {
    return meterIndex >= 0 && meterIndex < dialMeters.Num()
        ? dialMeters[meterIndex].joint : idJointIndex();
}

void idAnimator_VehicleCar::SetSpeedometer(const float value) {
    if (speedometer >= 0 && speedometer < dialMeters.Num())
        dialMeters[speedometer].value = value;
}

void idAnimator_VehicleCar::SetTachometer(const float value) {
    if (tachometer >= 0 && tachometer < dialMeters.Num())
        dialMeters[tachometer].value = value;
}

void idAnimator_VehicleCar::Evaluate() {
    if (animator != nullptr && vehicleProps != nullptr)
        GameLib_EvaluateVehicleAnimation(*this);
}

void idAnimator_VehicleCar::DeleteAnimWheels() {
    for (int index = 0; index < animWheels.Num(); ++index)
        GameLib_DeleteVehicleWheel(animWheels[index]);
    animWheels.ClearFree();
}

int idAnimator_VehicleCar::InternalInitDialMeter(
        const int definitionIndex) {
    idAnimDialMeter meter{};
    const int result = GameLib_InitVehicleDialMeter(*this,
        definitionIndex, meter);
    if (result >= 0) dialMeters.Append(meter);
    return result;
}

void idAnimator_VehicleCar::InitVehicleAnimator(
        idGameTimeManager* const gameTimeManager,
        const idDeclVehicleProps* const properties, idAnimStack* const stack,
        idRenderModel* const model, const int entityNumber,
        idClip* const collisionClip) {
    animator = GameLib_GetTreeAnimator(stack);
    vehicleProps = properties;
    clip = collisionClip;
    entityNum = entityNumber;
    renderModel = model;
    GameLib_InitVehicleAnimation(*this);

    idAnimatorParms_Base parameters{};
    parameters.animStack = stack;
    parameters.name = "vehicleCar";
    parameters.blendOp = 1;
    parameters.originBlend = 0;
    parameters.weightGroup = MD6_WEIGHTGROUP_ALL;
    parameters.filterGroup = MD6_WEIGHTGROUP_ALL;
    parameters.alpha = 1.0f;
    Init(gameTimeManager, parameters);
}

void idAnimator_VehicleCar::InternalPreBlendTree(const idAnimStack*, int,
        int) {
    Evaluate();
}

void idAnimator_VehicleCar::SerializeSnapshot(
        idSerializer* const serializer) {
    if (serializer != nullptr)
        GameLib_SerializeVehicleAnimator(serializer, *this);
}
