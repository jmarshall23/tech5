#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"

class idAnimatorParms_EndAdditiveChannels : public idAnimatorParms_Base {
public:
    int maxChannels;
};

class idAnimator_EndAdditiveChannels : public idAnimator_Base {
public:
    idAnimator_EndAdditiveChannels();
    ~idAnimator_EndAdditiveChannels() override = default;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override {
        return numAddedChannels != 0;
    }
    const idMD6Branch* InternalGetMergeBranch() const override;
    idMD6Branch* InternalGetMergeBranch() override;
    const idMD6Branch* InternalGetEndBranch() const override;
    idMD6Branch* InternalGetEndBranch() override;

    void SetAnimHandlesAndWeights(idTreeAnimator* animator, int currentTime,
        const idAnimAliasHandle* handles, int animationCount,
        const float* weights, int weightCount);
    void SetExternalBlend(float targetAlpha, int blendMilliseconds);

    idList<idMD6LeafPlay, 5> leaves;
    idList<idMD6Branch, 5> branches;
    idList<float, 5> aliasWeights;
    idMD6Branch mergeBranch;
    idList<idAnimAliasHandle, 5> animAlias;
    int numAddedChannels;
    int numCurrentChannels;
    idMD6Leaf::wrapMode_t wrapMode;
    float currentExternalAlpha;
    float targetExternalAlpha;
    float externalAlphaRate;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_EndAdditiveChannels) == 168,
    "Recovered additive-channel animator ABI changed");
static_assert(sizeof(idAnimatorParms_EndAdditiveChannels) == 60,
    "Recovered additive-channel parameters ABI changed");
#endif
