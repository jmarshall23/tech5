#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"

class idAnimator_ChannelWeight : public idAnimator_Base {
public:
    struct baseAnimation_t {
        const idMD6Anim* animation;
        idMD6LeafPause* leaf;
    };
    struct leafAnimation_t : public baseAnimation_t {
        idMD6Branch* branch;
    };

    idAnimator_ChannelWeight();
    ~idAnimator_ChannelWeight() override = default;

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    bool InternalIsContributing() const override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return mergeBranch; }

    void SetControlAnimation(const idMD6LeafPlay* animation,
        void* requestedLockOwner);

    idList<unsigned short, 5> userChannelToLeafMap;
    idList<leafAnimation_t, 5> leaves;
    baseAnimation_t baseAnimation;
    idMD6Branch* mergeBranch;
    const idMD6LeafPlay* controlAnimation;
    md6WeightGroup_t filterGroup;
    int entityNumber;
    void* lockOwner;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_ChannelWeight::baseAnimation_t) == 8,
    "Recovered channel-weight base animation ABI changed");
static_assert(sizeof(idAnimator_ChannelWeight::leafAnimation_t) == 12,
    "Recovered channel-weight leaf animation ABI changed");
static_assert(sizeof(idAnimator_ChannelWeight) == 100,
    "Recovered idAnimator_ChannelWeight ABI changed");
#endif
