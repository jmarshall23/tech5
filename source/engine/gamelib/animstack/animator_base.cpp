#include "gamelib/animstack/animator_base.h"

#include "idlib/lib_print.h"

#include <cmath>

// idAnimStack and idGameTimeManager are not yet safe to materialize from the
// generated declarations. These named boundaries preserve every recovered
// animator-base call while their authoritative translation units are ported.
int GameLib_GetAnimatorIndex(const idAnimStack* stack,
    const idAnimator_Base* animator);
void GameLib_AddAnimator(idAnimStack* stack, idAnimator_Base* animator);
void GameLib_RemoveAnimator(idAnimStack* stack, idAnimator_Base* animator);
void GameLib_SetAnimatorFlag(idAnimStack* stack, idAnimator_Base* animator,
    int flag);
void GameLib_ClearAnimatorFlag(idAnimStack* stack, idAnimator_Base* animator,
    int flag);
bool GameLib_IsAnimatorFlagSet(const idAnimStack* stack,
    const idAnimator_Base* animator, int flag);
int GameLib_ConvertRealMillisecondsToGameTime(
    const idGameTimeManager* gameTimeManager, int milliseconds);
int GameLib_GetGameTicksPerSecond();
bool GameLib_IsMD6NodeValid(const idMD6Node* node);
void GameLib_SerializeAnimatorBase(idSerializer* serializer,
    idAnimator_Base& animator);

namespace {

enum animatorFlag_t {
    ANIMATORFLAG_INITIALIZED = 0x01,
    ANIMATORFLAG_ENABLED = 0x02,
    ANIMATORFLAG_SERIALIZE = 0x08
};

bool IsBlendFinished(const idMD6Branch& branch) {
    return branch.alphaRate == 0.0f ||
        branch.currentAlpha == branch.targetAlpha;
}

bool IsBlendingOut(const idMD6Branch& branch) {
    return branch.currentAlpha > 0.0f &&
        branch.targetAlpha == 0.0f && branch.alphaRate != 0.0f;
}

bool IsBlendingIn(const idMD6Branch& branch) {
    return branch.currentAlpha < 1.0f &&
        branch.targetAlpha >= 1.0f && branch.alphaRate != 0.0f;
}

idTypesafeNumber<int, gameTimeUnique_t> ConvertBlendTime(
    const idGameTimeManager* gameTimeManager, const int milliseconds) {
    return idTypesafeNumber<int, gameTimeUnique_t>(
        GameLib_ConvertRealMillisecondsToGameTime(
            gameTimeManager, milliseconds));
}

} // namespace

idAnimator_Base::idAnimator_Base()
    : gametimeManager{nullptr}
    , weightGroup(MD6_WEIGHTGROUP_ALL)
    , filterGroup(MD6_WEIGHTGROUP_ALL)
    , serializeProps{{nullptr, nullptr}, nullptr, nullptr, false}
    , initialized(false) {
}

idAnimator_Base::~idAnimator_Base() = default;

idAnimator_Base::priority_t idAnimator_Base::GetStackPriority() {
    return PRIORITY_WEB;
}

serializeType_t idAnimator_Base::GetSerializeType() {
    return STYPE_GENERIC;
}

void idAnimator_Base::SerializeSnapshot(idSerializer* const serializer) {
    if (serializer != nullptr) {
        GameLib_SerializeAnimatorBase(serializer, *this);
    }
}

void idAnimator_Base::PreBlendSnapshot(idAnimStack* const stack,
        const int currentTime, const int ticksPerSecond, float) {
    InternalPreBlendTree(stack, currentTime, ticksPerSecond);
    InternalPostBlendTree(stack, currentTime);
}

bool idAnimator_Base::InternalInit(const idAnimatorParms_Base&) {
    return true;
}

void idAnimator_Base::InternalShutdown(idAnimStack*) {
}

void idAnimator_Base::InternalPreBlendTree(const idAnimStack*, int, int) {
}

void idAnimator_Base::InternalPostBlendTree(const idAnimStack*, int) {
}

void idAnimator_Base::InternalStart(const idAnimStack*, int,
        idTypesafeNumber<int, gameTimeUnique_t>) {
}

void idAnimator_Base::InternalEnd(const idAnimStack*, int,
        idTypesafeNumber<int, gameTimeUnique_t>) {
}

void idAnimator_Base::InternalBlend(const idAnimStack*, int, float,
        idTypesafeNumber<int, gameTimeUnique_t>) {
}

bool idAnimator_Base::InternalIsContributing() const {
    return true;
}

const idMD6Branch* idAnimator_Base::InternalGetMergeBranch() const {
    return serializeProps.serializedTrees[0];
}

idMD6Branch* idAnimator_Base::InternalGetMergeBranch() {
    return serializeProps.serializedTrees[0];
}

void idAnimator_Base::InternalPause(const idAnimStack*,
        idTypesafeNumber<int, gameTimeUnique_t>) {
}

void idAnimator_Base::InternalUnpause(const idAnimStack*,
        idTypesafeNumber<int, gameTimeUnique_t>) {
}

const idMD6Branch* idAnimator_Base::InternalGetEndBranch() const {
    return serializeProps.serializedTrees[1] != nullptr
        ? serializeProps.serializedTrees[1]
        : InternalGetMergeBranch();
}

idMD6Branch* idAnimator_Base::InternalGetEndBranch() {
    return serializeProps.serializedTrees[1] != nullptr
        ? serializeProps.serializedTrees[1]
        : InternalGetMergeBranch();
}

bool idAnimator_Base::InternalPostInit(
    const idAnimatorParms_Base& parameters) {
    if (parameters.animStack == nullptr) {
        return false;
    }

    GameLib_SetAnimatorFlag(parameters.animStack, this,
        ANIMATORFLAG_SERIALIZE);
    return true;
}

void idAnimator_Base::Shutdown(idAnimStack* const stack) {
    InternalShutdown(stack);
    GameLib_ClearAnimatorFlag(stack, this, ANIMATORFLAG_INITIALIZED);
    GameLib_RemoveAnimator(stack, this);
}

bool idAnimator_Base::IsInitialized(idAnimStack* const stack) const {
    return stack != nullptr && GameLib_IsAnimatorFlagSet(
        stack, this, ANIMATORFLAG_INITIALIZED);
}

bool idAnimator_Base::IsEnabled(idAnimStack* const stack) const {
    return stack != nullptr && GameLib_IsAnimatorFlagSet(
        stack, this, ANIMATORFLAG_ENABLED);
}

void idAnimator_Base::SetEnabled(idAnimStack* const stack,
    const bool enabled) {
    if (enabled) {
        GameLib_SetAnimatorFlag(stack, this, ANIMATORFLAG_ENABLED);
    } else {
        GameLib_ClearAnimatorFlag(stack, this, ANIMATORFLAG_ENABLED);
    }
}

bool idAnimator_Base::Init(idGameTimeManager* const gameTimeManager,
    const idAnimatorParms_Base& parameters) {
    if (GameLib_GetAnimatorIndex(parameters.animStack, this) >= 0 &&
        initialized) {
        idLibPrint::Error("Attempted to add idAnimator %s twice.",
            parameters.name.c_str());
    }

    gametimeManager.gameTimeManager = gameTimeManager;
    weightGroup = parameters.weightGroup;
    filterGroup = parameters.filterGroup;

    if (!InternalInit(parameters)) {
        return false;
    }

    idMD6Branch* const branch = InternalGetMergeBranch();
    if (branch != nullptr) {
        branch->op = static_cast<std::uint8_t>(parameters.blendOp);
        branch->originBlend =
            static_cast<std::uint8_t>(parameters.originBlend);
        branch->currentAlpha = parameters.alpha;
        branch->targetAlpha = parameters.alpha;
        branch->alphaRate = 0.0f;
        branch->filterGroup =
            static_cast<std::uint8_t>(parameters.filterGroup);
    }

    GameLib_AddAnimator(parameters.animStack, this);
    GameLib_SetAnimatorFlag(parameters.animStack, this,
        ANIMATORFLAG_INITIALIZED);
    GameLib_SetAnimatorFlag(parameters.animStack, this,
        ANIMATORFLAG_ENABLED);
    initialized = true;
    return InternalPostInit(parameters);
}

void idAnimator_Base::Blend(const idAnimStack* const stack,
    const int currentTime, const float targetAlpha,
    const int blendDurationMS, const bool reset) {
    idMD6Branch* const branch = InternalGetMergeBranch();
    branch->targetAlpha = targetAlpha;

    const idTypesafeNumber<int, gameTimeUnique_t> blendTime =
        ConvertBlendTime(gametimeManager.gameTimeManager, blendDurationMS);
    const bool alreadyBlending = targetAlpha <= branch->currentAlpha
        ? IsBlendingOut(*branch)
        : IsBlendingIn(*branch);

    if (blendTime.value <= 0) {
        branch->currentAlpha = targetAlpha;
        branch->alphaRate = 0.0f;
    } else if (reset || !alreadyBlending) {
        branch->alphaRate = std::fabs(targetAlpha - branch->currentAlpha) *
            (1000.0f / static_cast<float>(blendTime.value));
    }

    InternalBlend(stack, currentTime, targetAlpha, blendTime);
}

bool idAnimator_Base::IsContributing() const {
    const idMD6Branch* const branch = InternalGetMergeBranch();
    return branch != nullptr && branch->right != nullptr &&
        GameLib_IsMD6NodeValid(branch->right) &&
        (branch->currentAlpha > 0.0f || !IsBlendFinished(*branch)) &&
        InternalIsContributing();
}

md6WeightGroup_t idAnimator_Base::GetFilterGroup() const {
    return static_cast<md6WeightGroup_t>(
        InternalGetMergeBranch()->filterGroup);
}

float idAnimator_Base::GetAlpha() const {
    return InternalGetMergeBranch()->currentAlpha;
}

void idAnimator_Base::SetAlpha(const float alpha) {
    InternalGetMergeBranch()->currentAlpha = alpha;
}

void idAnimator_Base::Pause(const idAnimStack* const stack,
    const idTypesafeNumber<int, gameTimeUnique_t> currentTime) {
    InternalPause(stack, currentTime);
}

void idAnimator_Base::Unpause(const idAnimStack* const stack,
    const idTypesafeNumber<int, gameTimeUnique_t> currentTime) {
    InternalUnpause(stack, currentTime);
}

void idAnimator_Base::Start(const idAnimStack* const stack,
    const int currentTime, const int blendDurationMS, const bool reset) {
    idMD6Branch* const branch = InternalGetMergeBranch();
    const idTypesafeNumber<int, gameTimeUnique_t> blendTime =
        ConvertBlendTime(gametimeManager.gameTimeManager, blendDurationMS);

    if (blendTime.value <= 0) {
        branch->currentAlpha = 1.0f;
        branch->targetAlpha = 1.0f;
        branch->alphaRate = 0.0f;
    } else if (reset || !IsBlendingIn(*branch)) {
        branch->targetAlpha = 1.0f;
        branch->alphaRate = (1.0f - branch->currentAlpha) *
            (static_cast<float>(GameLib_GetGameTicksPerSecond()) /
                static_cast<float>(blendTime.value));
    }

    InternalStart(stack, currentTime, blendTime);
}

void idAnimator_Base::End(const idAnimStack* const stack,
    const int currentTime, const int blendDurationMS, const bool reset) {
    if (!initialized) {
        return;
    }

    idMD6Branch* const branch = InternalGetMergeBranch();
    branch->targetAlpha = 0.0f;
    const idTypesafeNumber<int, gameTimeUnique_t> blendTime =
        ConvertBlendTime(gametimeManager.gameTimeManager, blendDurationMS);

    if (blendTime.value <= 0) {
        branch->alphaRate = 0.0f;
        branch->currentAlpha = 0.0f;
    } else if (reset || !IsBlendingOut(*branch)) {
        branch->alphaRate = branch->currentAlpha *
            (static_cast<float>(GameLib_GetGameTicksPerSecond()) /
                static_cast<float>(blendTime.value));
    }

    InternalEnd(stack, currentTime, blendTime);
}

void idAnimator_Base::PreSerializeInit(idAnimStack* const stack,
    idClip* const clip, idGameTimeManager* const gameTimeManager) {
    serializeProps.animStack = stack;
    serializeProps.clip = clip;
    gametimeManager.gameTimeManager = gameTimeManager;
    serializeProps.createdThroughSerialization = true;
}
