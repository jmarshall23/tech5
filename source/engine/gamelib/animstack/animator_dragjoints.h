#pragma once

#include "gamelib/animstack/animator_base.h"
#include "gamelib/animstack/animweb/animwebeventhandler.h"
#include "idlib/containers/list.h"

class idAnimator_AnimWeb;
class idDeclDragJoints;

class idAnimatorParms_DragJoints : public idAnimatorParms_Base {
public:
    const idDeclDragJoints* declDragJoints;
};

class idAnimator_DragJoints : public idAnimator_Base {
public:
    struct idJoint {
        idJointIndex index;
        idVec3 position;
        float length;
        idMat3 originalRotation;
    };

    idAnimator_DragJoints();
    ~idAnimator_DragJoints() override;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override { return enabled; }
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    void SetAnimWeb(idAnimator_AnimWeb* web) { animweb = web; }
    void ReinitJoints();

    bool enabled;
    int blendFrame;
    int numBlendFrames;
    idAnimator_AnimWeb* animweb;
    idList<idAnimWebSubWebIndex, 5> subwebs;
    idJointIndex baseJoint;
    idList<idJoint, 5> joints;
    idTreeAnimator* animator;
    idMD6LeafPause animLeaf;
    idMD6Branch* mergeBranch;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_DragJoints::idJoint) == 56,
    "Recovered drag-joint ABI changed");
static_assert(sizeof(idAnimator_DragJoints) == 180,
    "Recovered idAnimator_DragJoints ABI changed");
static_assert(sizeof(idAnimatorParms_DragJoints) == 60,
    "Recovered drag-joint parameters ABI changed");
#endif
