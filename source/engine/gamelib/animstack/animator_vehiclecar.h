#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"
#include "idlib/math/mat3x4.h"

class idClipModel;
class idDeclVehicleProps;
class idMaterial;
class idRenderModel;

struct wheelSlipInfo_t {
    bool enabled;
    float velocity;
    float slip;
};

struct idAnimSuspensionLever {
    idJointIndex jointIndex;
    idJointIndex alignToJointIndex;
    float invLength;
    idVec3 rotationAxis;
    idVec3 alignAxis;
    idQuat localJointQuat;
};

struct idAnimWheel {
    enum skidMode_t : int { SKID_NONE = 0, SKID_LEFT, SKID_RIGHT };
    struct tireMark_t {
        skidMode_t markMode;
        skidMode_t lastMarkMode;
        idVec3 lastOrigin;
        idVec3 corners[4];
        idVec3 left;
        float yBias;
        const idMaterial* material;
    };

    idList<idAnimSuspensionLever, 5> suspensionLever;
    idJointIndex wheelJointIndex;
    idClipModel* clipModel;
    idQuat localJointQuat;
    idVec4 localJointOrigin;
    tireMark_t skid;
    tireMark_t track;
    int ongroundTime;
    float hitgroundSpeed;
    int dustTime;
    idVec3 lastDustPrtDropPos;
    idVec3 lastDustPrtDropPos2;
    float wobbleFrac;
    idMat3x4 wheelSteeringAxis;
    idClipQuery collisionQuery;
    float traceFraction;
    float prevTraceFraction;
    int traceSurfaceType;
    unsigned char traceSurfaceColor[3];
    idVec3 lastWorldOrigin;
    float wheelAngle;
    float wheelVelocity;
    float wheelHeight;
    float wheelSlip;
    wheelSlipInfo_t wheelSlipInfo;
};

struct idAnimDialMeter {
    idJointIndex joint;
    idVec3 axis;
    idQuat rot;
    idVec3 pos;
    float value;
};

class idAnimator_VehicleCar : public idAnimator_Base {
public:
    idAnimator_VehicleCar();
    ~idAnimator_VehicleCar() override;

    void SerializeSnapshot(idSerializer* serializer) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override { return false; }

    void InitVehicleAnimator(idGameTimeManager* gameTimeManager,
        const idDeclVehicleProps* properties, idAnimStack* stack,
        idRenderModel* model, int entityNumber, idClip* collisionClip);
    void Evaluate();
    void SetPlayerOccupant(bool occupied);
    void SetTireWobble(int wheelIndex, float wobble);
    void SetSpeedometer(float value);
    void SetTachometer(float value);

    idTreeAnimator* animator;
    const idDeclVehicleProps* vehicleProps;
    idList<idAnimWheel, 5> animWheels;
    idClip* clip;
    int entityNum;
    idRenderModel* renderModel;
    idList<idAnimDialMeter, 5> dialMeters;
    int speedometer;
    int tachometer;
    int clipMask;
    bool accelerating;
    bool handBraking;
    bool isReversing;
    bool playerOccupant;
    bool rotateSteeringWheel;
    idJointIndex steeringWheelJoint;
    idVec3 steeringWheelAxis;
    idQuat steeringWheelJointQuat;
    float steerAngle;
    float lastSteerAngle;
    float newSteerAngle;
    bool updateWheelAngle;
    bool isOnElevator;

private:
    void DeleteAnimWheels();
    int InternalInitDialMeter(int definitionIndex);
    idJointIndex InternalGetDialMeterJointIndex(int meterIndex) const;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimSuspensionLever) == 48,
    "Recovered suspension-lever ABI changed");
static_assert(sizeof(idAnimWheel::tireMark_t) == 88,
    "Recovered tire-mark ABI changed");
static_assert(sizeof(idAnimWheel) == 384,
    "Recovered animation-wheel ABI changed");
static_assert(sizeof(idAnimDialMeter) == 48,
    "Recovered dial-meter ABI changed");
static_assert(sizeof(idAnimator_VehicleCar) == 156,
    "Recovered idAnimator_VehicleCar ABI changed");
#endif
