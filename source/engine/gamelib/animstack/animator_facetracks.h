#pragma once

#include "gamelib/animstack/animator_base.h"
#include "idlib/containers/list.h"

class idDeclMD6;

class idAnimator_FaceTracks : public idAnimator_Base {
public:
    idAnimator_FaceTracks();
    ~idAnimator_FaceTracks() override = default;

    static bool HasFaceTracks(const idDeclMD6* declaration);
    void AddUserChannelMod(idUserChannelIndex userChannel, float value,
        int currentTime);

    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalPreBlendTree(const idAnimStack* stack, int currentTime,
        int ticksPerSecond) override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return &mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override { return &mergeBranch; }
    const idMD6Branch* InternalGetEndBranch() const override {
        return endBranch;
    }
    idMD6Branch* InternalGetEndBranch() override { return endBranch; }

    idList<idMD6LeafPause, 5> leaves;
    idList<idMD6Branch, 5> branches;
    idList<int, 5> leafAnimModsTime;
    idMD6Branch mergeBranch;
    idMD6Branch* endBranch;
    idAnimAliasHandle faceSetupAnimAlias;
    int animModsTime;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_FaceTracks) == 140,
    "Recovered idAnimator_FaceTracks ABI changed");
#endif
