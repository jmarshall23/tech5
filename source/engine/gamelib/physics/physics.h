#pragma once

#include "cm/jobs/collisionresults.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"

#include <cstddef>
#include <cstdint>

class idBounds;
class idClip;
class idClipModel;
class idCmdArgs;
class idPhysics;
class idPhysicsCallbacks;
class idRotation;

enum bindFlags_t : int;

enum physicsType_t : int {
    PHYSICS_INVALID = 0,
    PHYSICS_STATIC = 1,
    PHYSICS_STATICMULTI = 2,
    PHYSICS_AI = 3,
    PHYSICS_PLAYER = 4,
    PHYSICS_PARAMETRIC = 5,
    PHYSICS_RIGIDBODY = 6,
    PHYSICS_RIGIDBODY3DOF = 7,
    PHYSICS_AF = 8,
    PHYSICS_ROBOT = 9
};

struct impactInfo_t {
    float invMass;
    idMat3 invInertiaTensor;
    idVec3 position;
    idVec3 velocity;

    // Materialized in the authoritative physics.h dump.
    void Zero() {
        invMass = 0.0f;
        invInertiaTensor[0].Zero();
        invInertiaTensor[1].Zero();
        invInertiaTensor[2].Zero();
        position.Zero();
        velocity.Zero();
    }
};

#ifndef ID_RESIDENCY_QUERY_DEFINED
#define ID_RESIDENCY_QUERY_DEFINED
struct idResidencyQuery { std::uint64_t index; };
#endif

class alignas(8) idPhysics {
public:
    enum residency_t : int {
        RESIDENCY_NOT_TESTED = 0,
        RESIDENCY_YES = 1,
        RESIDENCY_NO = 2
    };

    idPhysics();
    virtual ~idPhysics();

    virtual void SetClipModel(idClipModel*, float, int, bool) = 0;
    virtual idClipModel* GetClipModel(int) = 0;
    virtual int GetNumClipModels() = 0;
    virtual void SetMass(float, int) = 0;
    virtual float GetMass(int) = 0;
    virtual void SetContents(int, int) = 0;
    virtual int GetContents(int) = 0;
    virtual void SetClipMask(int, int) = 0;
    virtual int GetClipMask(int) = 0;
    virtual const idBounds* GetBounds(int) = 0;
    virtual const idBounds* GetAbsBounds(int) = 0;
    virtual void SetOrigin(const idVec3*, int) = 0;
    virtual void SetAxis(const idMat3*, int) = 0;
    virtual void Translate(const idVec3*, int) = 0;
    virtual void Rotate(const idRotation*, int) = 0;
    virtual const idVec3* GetOrigin(int) = 0;
    virtual const idMat3* GetAxis(int) = 0;
    virtual const idVec3* GetLocalOrigin(int) = 0;
    virtual const idMat3* GetLocalAxis(int) = 0;
    virtual void SetLinearVelocity(const idVec3*, int) = 0;
    virtual void SetAngularVelocity(const idVec3*, int) = 0;
    virtual idVec3* GetLinearVelocity(idVec3*, int) = 0;
    virtual idVec3* GetAngularVelocity(idVec3*, int) = 0;
    virtual void SetGravity(const idVec3*) = 0;
    virtual const idVec3* GetGravity() = 0;
    virtual const idVec3* GetGravityNormal() = 0;
    virtual void SetWaterLevel(float, int) = 0;
    virtual float GetWaterLevel(int) = 0;
    virtual void SetWaterViscosity(float, int) = 0;
    virtual float GetWaterViscosity(int) = 0;
    virtual void SetWaterEntNum(int) = 0;
    virtual int GetWaterEntNum() = 0;
    virtual void SetWaterSurfaceWrldHeight(float) = 0;
    virtual float GetWaterSurfaceWrldHeight() = 0;
    virtual void GetImpactInfo(int, const idVec3*, impactInfo_t*) = 0;
    virtual void ApplyImpulse(int, const idVec3*, const idVec3*) = 0;
    virtual void ApplyForce(int, const idVec3*, const idVec3*) = 0;
    virtual void Activate() = 0;
    virtual void PutToRest() = 0;
    virtual bool IsAtRest() = 0;
    virtual bool IsPushable(int) = 0;
    virtual void SaveState() = 0;
    virtual void RestoreState() = 0;
    virtual bool Evaluate(int, int) = 0;
    virtual void UpdateTime(int) = 0;
    virtual void ClipTranslation(trace_t*, const idVec3*, const idClipModel*) = 0;
    virtual void ClipRotation(trace_t*, const idRotation*, const idClipModel*) = 0;
    virtual int ClipContents(const idClipModel*, int) = 0;
    virtual void DisableClip() = 0;
    virtual void EnableClip() = 0;
    virtual void UnlinkClip() = 0;
    virtual void LinkClip() = 0;
    virtual bool EvaluateContacts() = 0;
    virtual int GetNumContacts() = 0;
    virtual const contactInfo_t* GetContact(int) = 0;
    virtual void ClearContacts() = 0;
    virtual void AddContactPhysics(idPhysics*) = 0;
    virtual void RemoveContactPhysics(idPhysics*) = 0;
    virtual int GetNumContactPhysics() = 0;
    virtual idPhysics* GetContactPhysics(int) = 0;
    virtual void ActivateContactPhysics() = 0;
    virtual bool HasGroundContacts() = 0;
    virtual bool IsGroundEntity(int) = 0;
    virtual bool IsGroundClipModel(int, int) = 0;
    virtual void SetPushed(int) = 0;
    virtual idVec3* GetPushedLinearVelocity(idVec3*, int) = 0;
    virtual idVec3* GetPushedAngularVelocity(idVec3*, int) = 0;
    virtual void SetMaster(bool, const idVec3*, const idMat3*, bindFlags_t) = 0;
    virtual void SetLocalOrigin(const idVec3*, int) = 0;
    virtual void SetLocalAxis(const idMat3*, int) = 0;
    virtual int GetBlockingEntityNum() = 0;
    virtual int GetLinearEndTime() = 0;
    virtual int GetAngularEndTime() = 0;
    virtual bool IsInNonResidentCollisionArea(bool assumeNonResident);

    void InitPhysics(idClip* clip_, idPhysicsCallbacks* callbacks_,
        int entityNumber_);

    static void ClearHash();
    static idPhysics* GetPhysicsForId(int physicsId_);

    physicsType_t GetType() const { return type; }
    int GetPhysicsId() const { return physicsId; }
    int GetEntityNumber() const { return entityNumber; }
    residency_t GetCollisionResidency() const { return collisionResidency; }

protected:
    void UpdateCollisionResidency(const contactInfo_t& contact);

private:
    void Link();
    void Unlink();

    static idPhysics* hash[1024];
    static int currentPhysicsId;

protected:

    alignas(8) physicsType_t type;
    int physicsId;
    int entityNumber;
    idPhysics* nextInHash;
    idClip* clip;
    idPhysicsCallbacks* callbacks;
    idResidencyQuery residencyQuery;
    residency_t collisionResidency;

    friend void OutputPhysicsHash_f(const idCmdArgs& args);
};

void OutputPhysicsHash_f(const idCmdArgs& args);

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(impactInfo_t) == 64,
    "Recovered impactInfo_t ABI changed");
static_assert(sizeof(contactInfo_t) == 76,
    "Recovered contactInfo_t ABI changed");
static_assert(sizeof(trace_t) == 128,
    "Recovered trace_t ABI changed");
static_assert(sizeof(idResidencyQuery) == 8,
    "Recovered idResidencyQuery ABI changed");
static_assert(sizeof(idPhysics) == 48,
    "Recovered idPhysics ABI changed");
#endif
