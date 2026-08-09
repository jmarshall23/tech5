#pragma once

#include "gamelib/physics/clip.h"
#include "gamelib/physics/physics_dynamicbase.h"
#include "idlib/math/random.h"

#include <cstdint>

class idPhysics_RigidBody3DOF : public idPhysics_DynamicBase {
public:
    struct bodyIntState_t {
        idVec3 position;
        idMat3 orientation;
        idVec3 linearVelocity;
        idVec3 angularVelocity;
    };
    struct bodyState_t {
        int atRest;
        float lastTimeStep;
        idVec3 localOrigin;
        idMat3 localAxis;
        idVec3 linearPushVelocity;
        idVec3 angularPushVelocity;
        idVec3 externalForce;
        bodyIntState_t i;

        bodyState_t();
    };
    struct simpleBodyFlags_t {
        std::uint8_t reserved : 3;
        std::uint8_t noImpact : 1;
        std::uint8_t isOriented : 1;
        std::uint8_t hasMaster : 1;
        std::uint8_t testSolid : 1;
        std::uint8_t dropToFloor : 1;
    };

    idPhysics_RigidBody3DOF();
    ~idPhysics_RigidBody3DOF() override;

    void SetClipModel(idClipModel*, float, int, bool) override;
    idClipModel* GetClipModel(int) override;
    int GetNumClipModels() override;
    void SetMass(float, int) override;
    float GetMass(int) override;
    void SetContents(int, int) override;
    int GetContents(int) override;
    const idBounds* GetBounds(int) override;
    const idBounds* GetAbsBounds(int) override;
    void SetOrigin(const idVec3*, int) override;
    void SetAxis(const idMat3*, int) override;
    void Translate(const idVec3*, int) override;
    void Rotate(const idRotation*, int) override;
    const idVec3* GetOrigin(int) override;
    const idMat3* GetAxis(int) override;
    const idVec3* GetLocalOrigin(int) override;
    const idMat3* GetLocalAxis(int) override;
    void SetLinearVelocity(const idVec3*, int) override;
    void SetAngularVelocity(const idVec3*, int) override;
    idVec3* GetLinearVelocity(idVec3*, int) override;
    idVec3* GetAngularVelocity(idVec3*, int) override;
    void SetWaterEntNum(int) override;
    int GetWaterEntNum() override;
    void SetWaterSurfaceWrldHeight(float) override;
    float GetWaterSurfaceWrldHeight() override;
    void GetImpactInfo(int, const idVec3*, impactInfo_t*) override;
    void ApplyImpulse(int, const idVec3*, const idVec3*) override;
    void ApplyForce(int, const idVec3*, const idVec3*) override;
    void Activate() override;
    void PutToRest() override;
    bool IsAtRest() override;
    bool IsPushable(int) override;
    void SaveState() override;
    void RestoreState() override;
    bool Evaluate(int, int) override;
    void UpdateTime(int) override;
    void ClipTranslation(trace_t*, const idVec3*, const idClipModel*) override;
    void ClipRotation(trace_t*, const idRotation*, const idClipModel*) override;
    int ClipContents(const idClipModel*, int) override;
    void DisableClip() override;
    void EnableClip() override;
    void UnlinkClip() override;
    void LinkClip() override;
    bool EvaluateContacts() override;
    void SetPushed(int) override;
    idVec3* GetPushedLinearVelocity(idVec3*, int) override;
    idVec3* GetPushedAngularVelocity(idVec3*, int) override;
    void SetMaster(bool, const idVec3*, const idMat3*, bindFlags_t) override;
    void SetLocalOrigin(const idVec3*, int) override;
    void SetLocalAxis(const idMat3*, int) override;
    int GetBlockingEntityNum() override;
    int GetLinearEndTime() override;
    int GetAngularEndTime() override;

    bool IsOutsideWorld() override;

    void SetFriction(float linear, float angular, float contact);
    void SetWaterFriction(float linear, float angular);
    void SetCoefficientOfRestitution(float coefficient);
    void Integrate(float deltaTime, const bodyState_t& current,
        bodyState_t& next) const;
    bool CheckForCollisions(const bodyState_t& current,
        bodyState_t& next, trace_t& collision);
    bool CollisionImpulse(const trace_t& collision, float timeStep,
        bodyState_t& state, idVec3& impulse);

    idClipModel* clipModel;
    float mass;
    float inverseMass;
    float linearFriction;
    float angularFriction;
    float contactFriction;
    float linearFrictionWater;
    float angularFrictionWater;
    float coefficientOfRestitution;
    bodyState_t current;
    bodyState_t saved;
    idRandom random;
    idClipQuery translationQuery;
    simpleBodyFlags_t flags;
};

static_assert(sizeof(idPhysics_RigidBody3DOF::bodyIntState_t) == 72,
    "Recovered 3DOF integration state ABI changed");
static_assert(sizeof(idPhysics_RigidBody3DOF::bodyState_t) == 164,
    "Recovered 3DOF body state ABI changed");
static_assert(sizeof(idPhysics_RigidBody3DOF::simpleBodyFlags_t) == 1,
    "Recovered 3DOF flags ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_RigidBody3DOF) == 504,
    "Recovered idPhysics_RigidBody3DOF ABI changed");
#endif
