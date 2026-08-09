#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"

class idDeclRollBones;

class idAnimatorParms_RollBones : public idAnimatorParms_Base {
public:
    const idDeclRollBones* declRollBones;
};

class idAnimator_RollBones : public idAnimator_Base {
public:
    struct idRollInstance {
        idVec3 rollAxis;
        float rollAmount;
        idJointIndex rollSourceJoint;
        idJointIndex rollDestJoint;
    };

    idAnimator_RollBones();
    ~idAnimator_RollBones() override;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override { return enabled; }
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    bool enabled;
    idTreeAnimator* animator;
    idMD6LeafPause animLeaf;
    idMD6Branch* mergeBranch;
    idList<idRollInstance, 5> rollBones;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_RollBones::idRollInstance) == 20,
    "Recovered roll-bone instance ABI changed");
static_assert(sizeof(idAnimator_RollBones) == 148,
    "Recovered idAnimator_RollBones ABI changed");
static_assert(sizeof(idAnimatorParms_RollBones) == 60,
    "Recovered roll-bone parameters ABI changed");
#endif
