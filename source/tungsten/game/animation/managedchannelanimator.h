#pragma once

#include "gamelib/animstack/animator_channel.h"
#include "idlib/containers/list.h"

// The retail translation unit contains only the compiler-generated lifetime
// helpers for these three CVars. Host builds expose their recovered defaults
// as ordinary configuration values; no handwritten routine is omitted.
extern int managedChannelAnimator_animBlendInMS;
extern int managedChannelAnimator_animIsDoneFrames;
extern int managedChannelAnimator_animBlendOutMS;

class idManagedChannelAnimator : public idAnimator_Channel {
public:
    struct queuedAnim_t {
        idAnimAliasHandle animAlias;
        bool loop;
        float targetAlpha;
        float alphaRate;
        int durationMS;
        blendParms_t blendParms;
    };

    idAnimAliasHandle curAliasHandle;
    int animEndTimeMS = -1;
    idList<queuedAnim_t, 5> queuedAnims;
    bool startBlendOut = false;
    int startTime = -1;
};
