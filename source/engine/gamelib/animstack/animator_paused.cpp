#include "gamelib/animstack/animator_paused.h"

idMD6Branch* GameLib_AllocMD6Branch(idAnimStack* stack);
idMD6LeafPause* GameLib_AllocMD6LeafPause(idAnimStack* stack);
void GameLib_FreeMD6Branch(idAnimStack* stack, idMD6Branch* branch);
void GameLib_FreeMD6LeafPause(idAnimStack* stack, idMD6LeafPause* leaf);
int GameLib_GetMD6AnimNumFrames(const idMD6Anim* animation);

idAnimator_Paused::idAnimator_Paused()
    : idAnimator_Base()
    , leaf(nullptr)
    , mergeBranch(nullptr)
    , anim(nullptr) {
}

idAnimator_Paused::~idAnimator_Paused() {
    leaf = nullptr;
    mergeBranch = nullptr;
    anim = nullptr;
}

void idAnimator_Paused::SetAnim(const idMD6Anim* const animation) {
    anim = animation;
    if (animation != nullptr) {
        leaf->Init(animation, leaf->frame, leaf->wrapMode,
            MD6_WEIGHTGROUP_ALL);
    }
    leaf->anim = animation;
}

void idAnimator_Paused::SetFrame(const float animationFrame) {
    leaf->frame = animationFrame;
}

float idAnimator_Paused::GetFrame() const {
    return leaf->frame;
}

void idAnimator_Paused::SetNormalizedFrame(const float normalizedFrame) {
    leaf->frame = static_cast<float>(GameLib_GetMD6AnimNumFrames(leaf->anim) - 1) *
        normalizedFrame;
}

bool idAnimator_Paused::InternalInit(
    const idAnimatorParms_Base& parameters) {
    const idAnimatorParms_Pause& pauseParameters =
        static_cast<const idAnimatorParms_Pause&>(parameters);

    mergeBranch = GameLib_AllocMD6Branch(parameters.animStack);
    leaf = GameLib_AllocMD6LeafPause(parameters.animStack);
    mergeBranch->right = leaf;
    anim = pauseParameters.anim;
    if (anim != nullptr) {
        leaf->Init(anim, leaf->frame, leaf->wrapMode, MD6_WEIGHTGROUP_ALL);
    }
    leaf->anim = anim;

    if (pauseParameters.normalizedStartFrame < 0.0f) {
        leaf->frame = pauseParameters.startFrame;
    } else {
        SetNormalizedFrame(pauseParameters.normalizedStartFrame);
    }
    return true;
}

void idAnimator_Paused::InternalShutdown(idAnimStack* const stack) {
    if (mergeBranch != nullptr) {
        GameLib_FreeMD6Branch(stack, mergeBranch);
        mergeBranch = nullptr;
    }
    if (leaf != nullptr) {
        GameLib_FreeMD6LeafPause(stack, leaf);
        leaf = nullptr;
    }
}

bool idAnimator_Paused::InternalIsContributing() const {
    return leaf != nullptr && leaf->anim != nullptr;
}
