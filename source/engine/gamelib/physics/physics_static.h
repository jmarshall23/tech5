#pragma once

#include "gamelib/physics/physics.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"

struct staticPState_t {
    idVec3 worldOrigin;
    idMat3 worldAxis;
    idVec3 localOrigin;
    idMat3 localAxis;
};

class idPhysics_Static : public idPhysics {
public:
    idPhysics_Static();
    ~idPhysics_Static() override;

    void SetClipModel(idClipModel*, float, int, bool) override;
    idClipModel* GetClipModel(int) override;
    int GetNumClipModels() override;
    void SetMass(float, int) override;
    float GetMass(int) override;
    void SetContents(int, int) override;
    int GetContents(int) override;
    void SetClipMask(int, int) override;
    int GetClipMask(int) override;
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
    void SetGravity(const idVec3*) override;
    const idVec3* GetGravity() override;
    const idVec3* GetGravityNormal() override;
    void SetWaterLevel(float, int) override;
    float GetWaterLevel(int) override;
    void SetWaterViscosity(float, int) override;
    float GetWaterViscosity(int) override;
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
    void ClipTranslation(trace_t*, const idVec3*,
        const idClipModel*) override;
    void ClipRotation(trace_t*, const idRotation*,
        const idClipModel*) override;
    int ClipContents(const idClipModel*, int) override;
    void DisableClip() override;
    void EnableClip() override;
    void UnlinkClip() override;
    void LinkClip() override;
    bool EvaluateContacts() override;
    int GetNumContacts() override;
    const contactInfo_t* GetContact(int) override;
    void ClearContacts() override;
    void AddContactPhysics(idPhysics*) override;
    void RemoveContactPhysics(idPhysics*) override;
    int GetNumContactPhysics() override;
    idPhysics* GetContactPhysics(int) override;
    void ActivateContactPhysics() override;
    bool HasGroundContacts() override;
    bool IsGroundEntity(int) override;
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

    idClipModel* clipModel;
    idList<int, 77> contactPhysicsIds;
    std::uint8_t isOrientated : 1;
    std::uint8_t hasMaster : 1;
    std::uint8_t reservedFlags : 6;
    staticPState_t current;
};

static_assert(sizeof(staticPState_t) == 96,
    "Recovered static physics-state ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_Static) == 168,
    "Recovered idPhysics_Static ABI changed");
#endif
