#pragma once

#include "gamelib/animstack/animator_af.h"

class idClipModel;
class idDeclReachIK;
class idDeclWalkIK;

struct tagData_t {
    idVec3 trans;
    idQuat rot;
    idJointHandle parentJoint;
};

class idAnimator_IK : public idAnimator_Base {
public:
    idAnimator_IK();
    ~idAnimator_IK() override;

    priority_t GetStackPriority() override { return PRIORITY_IK; }
    void PreBlendSnapshot(idAnimStack* stack, int currentTime,
        int ticksPerSecond, float fraction) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override {
        return enabled && ikInitialized && ik_activate;
    }
    virtual void Evaluate();

    bool SolveTwoBones(const idVec3& start, const idVec3& end,
        const idVec3& bendDirection, float firstLength,
        float secondLength, idVec3& jointPosition) const;
    float GetBoneAxis(const idVec3& start, const idVec3& end,
        const idVec3& bendDirection, idMat3& axis) const;

    bool enabled;
    bool ikInitialized;
    bool ik_activate;
    int entityNum;
    idTreeAnimator* animator;
    idClip* clip;
};

class idAnimatorParms_WalkIK : public idAnimatorParms_Base {
public:
    const idDeclWalkIK* declWalkIK;
    int entityNum;
    int clipMask;
    idClip* clip;
    idClipModel* clipModel;
    idVec3 upNormal;
};

class alignas(8) idAnimator_WalkIK : public idAnimator_IK {
public:
    idAnimator_WalkIK();
    ~idAnimator_WalkIK() override;

    serializeType_t GetSerializeType() override { return STYPE_WALK_IK; }
    void SerializeSnapshot(idSerializer* serializer) override;
    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    bool InternalIsContributing() const override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }
    void Evaluate() override;

    void EnableLeg(int leg);
    void DisableLeg(int leg);
    void EnableAll();
    void DisableAll();
    bool IsActive() const;
    int GetFootSurfaceType() const;

    const idDeclWalkIK* decl;
    idClipModel* clipModel;
    int clipMask;
    idVec3 upNormal;
    idClipModel* footModel;
    bool createdClipModel;
    int numLegs;
    int enabledLegs;
    idJointIndex footJoints[8];
    idJointIndex ankleJoints[8];
    idJointIndex kneeJoints[8];
    idJointIndex hipJoints[8];
    idJointIndex dirJoints[8];
    idJointIndex waistJointHandle;
    idVec3 hipForward[8];
    idVec3 kneeForward[8];
    float upperLegLength[8];
    float lowerLegLength[8];
    idMat3 upperLegToHipJoint[8];
    idMat3 lowerLegToKneeJoint[8];
    idMat3 kneeJointTransform[8];
    int pivotFoot;
    float pivotYaw;
    idVec3 pivotPos;
    bool onGround;
    bool onStairs;
    bool isDead;
    bool oldHeightsValid;
    float oldWaistHeight;
    float oldAnkleHeights[8];
    int oldGroundPhysicsId;
    idVec3 oldGroundPhysicsOrigin;
    int surfaceTypes[8];
    idClipQuery modelQuery;
    idClipQuery waistQuery;
    idClipQuery legQueries[8];
    idClipQuery footQueries[8];
    idVec3 lastModelSpaceFootOrigin[8];
    float groundTraceDist;
    float internalRadiusXY;
    idMD6LeafPause animLeaf;
    idMD6Branch* mergeBranch;
};

class idAnimatorParms_ReachIK : public idAnimatorParms_Base {
public:
    const idDeclReachIK* declReachIK;
    int entityNum;
    idClip* clip;
};

class idAnimator_ReachIK : public idAnimator_IK {
public:
    struct targetTransform_t {
        idVec3 origin;
        idMat3 axis;
        tagData_t selfTag;
        bool validOrigin;
        bool validAxis;
        bool validTag;
    };

    idAnimator_ReachIK();
    ~idAnimator_ReachIK() override;

    serializeType_t GetSerializeType() override { return STYPE_REACH_IK; }
    void SerializeSnapshot(idSerializer* serializer) override;
    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void Evaluate() override;
    void SetTargetOrigin(int arm, const idVec3& origin);
    void SetTargetAxis(int arm, const idMat3& axis);

    const idDeclReachIK* decl;
    int numArms;
    int enabledArms;
    idJointIndex handJoints[2];
    idJointIndex elbowJoints[2];
    idJointIndex shoulderJoints[2];
    targetTransform_t targetTransforms[2];
    idVec3 shoulderForward[2];
    idVec3 elbowForward[2];
    float upperArmLength[2];
    float lowerArmLength[2];
    idMat3 upperArmToShoulderJoint[2];
    idMat3 lowerArmToElbowJoint[2];
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(tagData_t) == 32,
    "Recovered animation tag-data ABI changed");
static_assert(sizeof(idAnimator_IK) == 56,
    "Recovered idAnimator_IK ABI changed");
static_assert(sizeof(idAnimator_WalkIK) == 1744,
    "Recovered idAnimator_WalkIK ABI changed");
static_assert(sizeof(idAnimator_ReachIK::targetTransform_t) == 84,
    "Recovered reach target-transform ABI changed");
static_assert(sizeof(idAnimator_ReachIK) == 456,
    "Recovered idAnimator_ReachIK ABI changed");
static_assert(sizeof(idAnimatorParms_WalkIK) == 88,
    "Recovered walk-IK parameters ABI changed");
static_assert(sizeof(idAnimatorParms_ReachIK) == 68,
    "Recovered reach-IK parameters ABI changed");
#endif
