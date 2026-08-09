#pragma once

#include "gamelib/physics/clip.h"
#include "gamelib/physics/physics_dynamicbase.h"

#include <cstdint>

struct rigidBodyPState_t {
    int atRest;
    idVec3 localOrigin;
    idMat3 localAxis;
    idVec3 worldOrigin;
    idMat3 worldAxis;
    idVec6 spatialVelocity;
    idVec6 externalForce;
    idVec6 pushVelocity;
};

class idPhysics_RigidBody : public idPhysics_DynamicBase {
public:
    struct rigidBodyFlags_t {
        int noPushMask;
        std::uint8_t reserved : 3;
        std::uint8_t isOrientated : 1;
        std::uint8_t hasMaster : 1;
        std::uint8_t noImpact : 1;
        std::uint8_t testSolid : 1;
        std::uint8_t dropToFloor : 1;
        std::uint8_t pad[3];
    };

    idPhysics_RigidBody();
    ~idPhysics_RigidBody() override;

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
    void ClipRotation(trace_t*, const idRotation*, const idClipModel*) override;
    int ClipContents(const idClipModel*, int) override;
    void DisableClip() override;
    void EnableClip() override;
    void UnlinkClip() override;
    void LinkClip() override;
    bool EvaluateContacts() override;
    bool IsGroundClipModel(int, int) override;
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
    void SetBouncyness(float bouncyness_);
    void SetInertiaScale(const idVec3& scale);
    void CapVelocity();
    bool TestIfAtRest();
    void Evolve(float timeStep, trace_t* collision = nullptr,
        contactsResult_t* contacts = nullptr);
    void ResolveCollisions(const trace_t* collision = nullptr,
        const contactsResult_t* contacts = nullptr);
    void DropToFloorAndRest();

    idClipModel* clipModel;
    float linearFriction;
    float angularFriction;
    float contactFriction;
    float linearFrictionWater;
    float angularFrictionWater;
    float bouncyness;
    idVec3 inertiaScale;
    float mass;
    float inverseMass;
    idVec3 centerOfMass;
    idMat3 inertiaTensor;
    idMat3 inverseInertiaTensor;
    rigidBodyFlags_t fl;
    rigidBodyPState_t current;
    rigidBodyPState_t saved;
    idClipQuery motionQuery;
    float lastTimeStep;
};

static_assert(sizeof(rigidBodyPState_t) == 172,
    "Recovered rigid-body state ABI changed");
static_assert(sizeof(idPhysics_RigidBody::rigidBodyFlags_t) == 8,
    "Recovered rigid-body flags ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_RigidBody) == 624,
    "Recovered idPhysics_RigidBody ABI changed");
#endif
