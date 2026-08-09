#pragma once

#include "gamelib/animstack/animator_channel.h"

class idAnimator_Pain : public idAnimator_Channel {
public:
    idAnimator_Pain();
    ~idAnimator_Pain() override;

    serializeType_t GetSerializeType() override { return STYPE_PAIN; }
    void PreSerializeInit(idAnimStack* stack, idClip* clip,
        idGameTimeManager* gameTimeManager) override;
    bool InternalPostInit(
        const idAnimatorParms_Base& parameters) override;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Pain) == 96,
    "Recovered idAnimator_Pain ABI changed");
#endif
