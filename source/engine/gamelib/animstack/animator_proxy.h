#pragma once

#include "gamelib/animstack/animator_base.h"

class idAnimator_Proxy : public idAnimator_Base {
public:
    idAnimator_Proxy();
    ~idAnimator_Proxy() override;

    void SetTree(idMD6Node* tree);
    bool InternalInit(const idAnimatorParms_Base& parameters) override;
    void InternalShutdown(idAnimStack* stack) override;
    bool InternalIsContributing() const override;
    const idMD6Branch* InternalGetMergeBranch() const override {
        return mergeBranch;
    }
    idMD6Branch* InternalGetMergeBranch() override {
        return mergeBranch;
    }

    idMD6Branch* mergeBranch;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Proxy) == 44,
    "Recovered idAnimator_Proxy ABI changed");
#endif
