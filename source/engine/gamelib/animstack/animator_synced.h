#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/staticlist.h"

class idAnimator_Synced : public idAnimator_Base {
public:
    idAnimator_Synced();
    ~idAnimator_Synced() override;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    void InternalEnd(const idAnimStack* stack, int currentTime,
        idTypesafeNumber<int, gameTimeUnique_t> blendTime) override;
    bool InternalIsContributing() const override { return anims.Num() != 0; }
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    void SetAnimHandle(idTreeAnimator* animator, int currentTime, int index,
        const idAnimAliasHandle& handle);
    void SetAnimHandlesAndWeights(idTreeAnimator* animator, int currentTime,
        const idAnimAliasHandle* handles, int animationCount,
        const float* weights, int weightCount);
    bool IsDone(const idAnimStack* stack, int currentTime) const;

    idMD6LeafPlay* leaves[8];
    idMD6Branch* branches[7];
    idMD6Branch* mergeBranch;
    idStaticList<const idMD6Anim*, 8> anims;
    idStaticList<idAnimAliasHandle, 8> aliasHandles;
    idStaticList<float, 8> aliasWeights;
    idStaticList<float, 8> alphaValues;
    idMD6Leaf::wrapMode_t wrapMode;
    float rateScale;

protected:
    void CalcAlphaValuesFromWeights();
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Synced) == 288,
    "Recovered idAnimator_Synced ABI changed");
#endif
