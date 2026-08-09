#pragma once

#include "gamelib/animstack/animator_base.h"

class idAnimatorParms_Pause;

class idAnimator_Paused : public idAnimator_Base {
public:
    idAnimator_Paused();
    ~idAnimator_Paused() override;

    void SetAnim(const idMD6Anim* animation);
    const idMD6Anim* GetAnim() const { return anim; }
    void SetFrame(float frame);
    float GetFrame() const;
    void SetNormalizedFrame(float normalizedFrame);

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    bool InternalIsContributing() const override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    idMD6LeafPause* leaf;
    idMD6Branch* mergeBranch;
    const idMD6Anim* anim;
};

class idAnimatorParms_Pause : public idAnimatorParms_Base {
public:
    idAnimatorParms_Pause(const idMD6Anim* animation, float startFrame_,
        float normalizedStartFrame_, idAnimStack* stack, const char* name_,
        int blendOp_, int originBlend_, md6WeightGroup_t weightGroup_,
        md6WeightGroup_t filterGroup_, float alpha_)
        : idAnimatorParms_Base()
        , anim(animation)
        , startFrame(startFrame_)
        , normalizedStartFrame(normalizedStartFrame_) {
        animStack = stack;
        name = name_;
        blendOp = blendOp_;
        originBlend = originBlend_;
        weightGroup = weightGroup_;
        filterGroup = filterGroup_;
        alpha = alpha_;
    }

    const idMD6Anim* anim;
    float startFrame;
    float normalizedStartFrame;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Paused) == 52,
    "Recovered idAnimator_Paused ABI changed");
static_assert(sizeof(idAnimatorParms_Pause) == 68,
    "Recovered idAnimatorParms_Pause ABI changed");
#endif
