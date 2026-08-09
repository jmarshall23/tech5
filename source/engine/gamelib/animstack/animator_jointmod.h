#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"
#include "idlib/math/matrix.h"

class idAnimatorParms_JointMod : public idAnimatorParms_Base {
public:
    idTreeAnimator* treeAnimator;
    animationPose_t poseToModify;
};

class idAnimator_JointMod : public idAnimator_Base {
public:
    idAnimator_JointMod();
    ~idAnimator_JointMod() override;

    serializeType_t GetSerializeType() override { return STYPE_JOINTMOD; }
    void PreSerializeInit(idAnimStack* stack, idClip* clip,
        idGameTimeManager* gameTimeManager) override;
    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    void InternalPostBlendTree(const idAnimStack* stack,
        int currentTime) override;

    void ClearJointMods();
    void SetJointMod(idJointIndex index, const idMat3& value);

    bool enabled;
    idList<idJointIndex, 5> jointIndex;
    idList<idMat3, 5> jointValue;
    idTreeAnimator* treeAnimator;
    animationPose_t poseToModify;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_JointMod) == 84,
    "Recovered idAnimator_JointMod ABI changed");
static_assert(sizeof(idAnimatorParms_JointMod) == 64,
    "Recovered joint-mod parameters ABI changed");
#endif
