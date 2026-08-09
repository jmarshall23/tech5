#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/math/random.h"

class idAnimator_Channel : public idAnimator_Base {
public:
    idAnimator_Channel();
    ~idAnimator_Channel() override;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    void InternalEnd(const idAnimStack* stack, int currentTime,
        idTypesafeNumber<int, gameTimeUnique_t> blendTime) override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    void ClearAnimator();
    idMD6LeafPlay* GetLastPlayedLeaf() const;
    bool IsDone(const idAnimStack* stack, int currentTime) const;
    bool IsDone(const idAnimStack* stack, int currentTime,
        bool clampIgnoreExtraFrame) const;
    bool IsAnimPlaying(const idAnimStack* stack,
        const idAnimAliasHandle& alias, int currentTime) const;
    bool PlayAnim(const idAnimStack* stack, const idMD6Anim* animation,
        int currentTime, float rateScale, const blendParms_t& blendParms,
        int blendOutDurationMS = -1,
        idMD6LeafPlay** leafStarted = nullptr);
    bool CycleAnim(const idAnimStack* stack, const idMD6Anim* animation,
        int currentTime, float rateScale, const blendParms_t& blendParms,
        idMD6LeafPlay** leafStarted = nullptr);
    bool PlayAnim(const idAnimStack* stack, const idAnimAliasHandle& alias,
        int currentTime, float rateScale, const blendParms_t& blendParms,
        int blendOutDurationMS = -1,
        idMD6LeafPlay** leafStarted = nullptr);
    bool CycleAnim(const idAnimStack* stack, const idAnimAliasHandle& alias,
        int currentTime, float rateScale, const blendParms_t& blendParms,
        idMD6LeafPlay** leafStarted = nullptr);

    idMD6LeafPlay* leaves[3];
    idMD6Branch* branches[2];
    idMD6Branch* mergeBranch;
    idMD6LeafPlay* freeLeaves[3];
    idMD6Branch* freeBranches[2];
    idRandom random;
    std::int16_t numFreeLeaves;
    std::int16_t numFreeBranches;
    std::int16_t blendOutDurationMS;
    std::uint8_t reserved : 6;
    std::uint8_t omitFreeLeafWarning : 1;
    std::uint8_t forceFree : 1;

protected:
    void ForceFreeLeaf();
    void FreeTree(idMD6Node* node);
    idMD6LeafPlay* AllocLeaf();
    bool StartNode(idMD6Node* node, int currentTime,
        idMD6Leaf::wrapMode_t wrap, const blendParms_t& blendParms,
        int blendOutDurationMS_);
    bool StartLeaf(const idMD6Anim* animation, int currentTime,
        float rateScale, idMD6Leaf::wrapMode_t wrap,
        const blendParms_t& blendParms, int blendOutDurationMS_,
        idMD6LeafPlay** leafStarted);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Channel) == 96,
    "Recovered idAnimator_Channel ABI changed");
#endif
