#include "gamelib/animstack/animator_pain.h"

void GameLib_ClearAnimatorFlag(idAnimStack* stack,
    idAnimator_Base* animator, int flag);

namespace {
constexpr int ANIMATORFLAG_SERIALIZE = 0x08;
constexpr int BOP_ADD_RIGHT = 4;
}

idAnimator_Pain::idAnimator_Pain() = default;
idAnimator_Pain::~idAnimator_Pain() = default;

bool idAnimator_Pain::InternalPostInit(
        const idAnimatorParms_Base& parameters) {
    if (parameters.animStack == nullptr) {
        return false;
    }
    GameLib_ClearAnimatorFlag(parameters.animStack, this,
        ANIMATORFLAG_SERIALIZE);
    return true;
}

void idAnimator_Pain::PreSerializeInit(idAnimStack* const stack,
        idClip* const clip, idGameTimeManager* const gameTimeManager) {
    idAnimator_Base::PreSerializeInit(stack, clip, gameTimeManager);

    idAnimatorParms_Base parameters{};
    parameters.animStack = stack;
    parameters.name = "pain";
    parameters.blendOp = BOP_ADD_RIGHT;
    parameters.originBlend = 0;
    parameters.weightGroup = MD6_WEIGHTGROUP_ALL;
    parameters.filterGroup = MD6_WEIGHTGROUP_ALL;
    parameters.alpha = 1.0f;
    Init(gameTimeManager, parameters);
    GameLib_ClearAnimatorFlag(stack, this, ANIMATORFLAG_SERIALIZE);
}
