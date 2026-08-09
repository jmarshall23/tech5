#pragma once

#include "gamelib/physics/clip.h"
#include "gamelib/physics/physics_actor.h"

#include <cstdint>

struct aiPState_t {
    std::int16_t atRest;
    bool onGround;
    char pad;
    idVec3 localOrigin;
    idVec3 worldOrigin;
    idVec3 velocity;
    idVec3 pushVelocity;
};

class idPhysics_AI : public idPhysics_Actor {
public:
    enum aiMovement_t : int {
        AI_MOVE_WALKING = 0,
        AI_MOVE_FLYING = 1,
        AI_MOVE_DROPPING = 2,
        AI_MOVE_MAX = 3
    };

    idPhysics_AI();
    ~idPhysics_AI() override;

    void SetClipModel(idClipModel*, float, int, bool) override;
    void SetContents(int, int) override;
    void SetOrigin(const idVec3*, int) override;
    void SetAxis(const idMat3*, int) override;
    void Translate(const idVec3*, int) override;
    void Rotate(const idRotation*, int) override;
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
    void SaveState() override;
    void RestoreState() override;
    bool Evaluate(int, int) override;
    void UpdateTime(int) override;
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
    const idMat3* GetGravityAxis() override;
    void DisableClip(actorClipModel_t) override;
    void EnableClip(actorClipModel_t) override;
    void LinkClip(const idVec3&, const idMat3&) override;

    void Evolve(float timeStep);
    void ResolveCollisions();

    aiPState_t current;
    aiPState_t saved;
    idClipQuery stepMoveQuery;
    idClipQuery contactsQuery;
    idVec3 lastCollisionNormal;
    idVec3 lastCollisionPoint;
    idVec3 stuckCollisionNormal;
    idVec3 stuckCollisionPoint;
    idClipModel* clipModel_standing;
    idClipModel* clipModel_crouched;
    float maxStepHeight;
    float minFloorCosine;
    float maxDropVelocity;
    float heightCrouched;
    aiMovement_t movementType;
    bool noImpact;
    bool masterControlledVelocity;
    bool swimmer;
    bool crouched;
    bool canSetCrouchedPhysics;
};

static_assert(sizeof(aiPState_t) == 52,
    "Recovered AI physics state ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_AI) == 664,
    "Recovered idPhysics_AI ABI changed");
#endif
