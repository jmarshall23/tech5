#pragma once

#include "gamelib/physics/afconstraint.h"
#include "gamelib/physics/aftree.h"
#include "gamelib/physics/physics_dynamicbase.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/fader.h"
#include "idlib/math/lcp.h"

class idSerializer;

struct AFPState_t {
    bool atRest;
    float noMoveTime;
    float activateTime;
    idVec6 pushVelocity;
    idVec6 auxVelocity;
};

class idPhysics_AF : public idPhysics_DynamicBase {
public:
    struct noclipBodyInfo_t {
        int bodyId;
        int originalClipMask;
        idClipQuery query;
    };

    idPhysics_AF();
    ~idPhysics_AF() override;

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
    void SetPushed(int) override;
    idVec3* GetPushedLinearVelocity(idVec3*, int) override;
    idVec3* GetPushedAngularVelocity(idVec3*, int) override;
    void SetMaster(bool, const idVec3*, const idMat3*,
        bindFlags_t) override;
    void SetLocalOrigin(const idVec3*, int) override;
    void SetLocalAxis(const idMat3*, int) override;
    int GetBlockingEntityNum() override;
    int GetLinearEndTime() override;
    int GetAngularEndTime() override;

    void Serialize(idSerializer*);
    void Shutdown();
    void SetSuspendTime(float minTime, float maxTime);
    void SetSuspendTolerance(float translation, float rotation,
        float noMoveTime_);
    void SetSuspendSpeed(const idVec2& velocity,
        const idVec2& acceleration);
    void SetTimeScaleRamp(float start, float end);
    void SetJointFrictionDent(float dent, float start, float end);
    void SetContactFrictionDent(float dent, float start, float end);
    void SetDefaultFriction(float linear, float angular, float contact);
    float GetJointFrictionScale() const;
    float GetContactFrictionScale() const;
    void SetAuxAngularVelocity(const idVec3&);
    void ForceBodyId(idAFBody*, int newId);
    int GetBodyId(const idAFBody*) const;
    idAFBody* GetBody(const char* name) const;
    idAFBody* GetBody(int id) const;
    idAFConstraint* GetConstraint(const char* name) const;
    idAFConstraint* GetConstraint(int id) const;
    // Retail inline accessor emitted into decljob.cpp (EA 0x82BC5BD8).
    int GetNumConstraints() const { return constraints.Num(); }
    int AddBody(idAFBody*);
    void DeleteBody(int);
    void AddConstraint(idAFConstraint*);
    void DeleteConstraint(int);
    void DeleteConstraint(const char* name);
    void AddFrameConstraint(idAFConstraint*);
    int AddNoclipBody(int bodyId);

    void ApplyFriction(float timeStep, float endTimeMSec);
    void PrimaryFactor();
    void PrimaryForces(float timeStep);
    void AuxiliaryForces(float timeStep);
    void AddGravity();
    void UpdateClipModels();
    bool TestIfAtRest(float timeStep);
    void EvaluateBodies(float timeStep);
    void EvaluateConstraints(float timeStep);
    void CollisionImpulse(idAFBody*, const trace_t&, float timeStep);
    void IssueCollisionQueries();
    void ResolveCollisions(float timeStep);
    void AddFrameConstraints();
    void RemoveFrameConstraints();
    void SetupContactConstraints(float timeStep);
    void AddContacts(idAFBody*, const contactsResult_t&);
    void TestNoclipBodies();
    void Evolve(float timeStep);
    void BuildTrees();
    void DebugDraw();

    float GetLcpEpsilon(float timeStep) const;
    float GetErrorReduction(float timeStep) const;
    float GetErrorReductionMax(float timeStep) const;
    float GetLimitErrorReduction(float timeStep) const;
    float GetLimitErrorReductionMax(float timeStep) const;
    float GetLimitLcpEpsilon(float timeStep) const;
    float GetContactErrorReduction(float timeStep) const;
    float GetContactErrorReductionMax(float timeStep) const;
    float GetContactLcpEpsilon(float timeStep) const;
    float GetUniversalErrorReduction(float timeStep) const;
    float GetUniversalTorsionLcpEpsilon(float timeStep) const;

    idList<idAFTree*, 71> trees;
    idList<idAFBody*, 71> bodies;
    idList<idAFConstraint*, 71> constraints;
    idList<idAFConstraint*, 71> primaryConstraints;
    idList<idAFConstraint*, 71> auxiliaryConstraints;
    idList<idAFConstraint*, 71> frameConstraints;
    idList<idAFConstraint_Contact*, 71> contactConstraints;
    idList<int, 71> contactBodies;
    idStaticList<noclipBodyInfo_t, 8> noclipBodies;
    bool changedAF;
    float linearFriction;
    float angularFriction;
    float contactFriction;
    float bouncyness;
    float totalMass;
    idVec2 suspendVelocity;
    idVec2 suspendAcceleration;
    float noMoveTime;
    float noMoveTranslation;
    float noMoveRotation;
    float minMoveTime;
    float maxMoveTime;
    float impulseThreshold;
    float timeScale;
    float timeScaleRampStart;
    float timeScaleRampEnd;
    float jointFrictionScale;
    float jointFrictionDent;
    float jointFrictionDentStart;
    float jointFrictionDentEnd;
    float jointFrictionDentScale;
    float contactFrictionScale;
    float contactFrictionDent;
    float contactFrictionDentStart;
    float contactFrictionDentEnd;
    float contactFrictionDentScale;
    idFader errorReduction;
    idFader errorReductionMax;
    idFader lcpEpsilon;
    idFader limitErrorReduction;
    idFader limitErrorReductionMax;
    idFader limitLcpEpsilon;
    idFader contactErrorReduction;
    idFader contactErrorReductionMax;
    idFader contactLcpEpsilon;
    idFader universalErrorReduction;
    idFader universalErrorReductionMax;
    idFader universalTorsionLcpEpsilon;
    int passEntityNum;
    bool selfCollision;
    bool comeToRest;
    bool linearTime;
    bool noImpact;
    bool worldConstraintsLocked;
    bool forcePushable;
    bool addContactConstraints;
    bool addGravity;
    idAFBody* masterBody;
    AFPState_t current;
    AFPState_t saved;
    float lastTimeStep;
    int endTime;
    float timeStep;
    idVec3 lastImpulse;
    idLCP* lcp;
};

static_assert(sizeof(AFPState_t) == 60,
    "Recovered articulated-figure physics state ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_AF) == 912,
    "Recovered idPhysics_AF ABI changed");
#endif
