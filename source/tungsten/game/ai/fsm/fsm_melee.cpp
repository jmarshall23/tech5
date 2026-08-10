#include "fsm_melee.h"

namespace {

int Random15() {
    return static_cast<int>((Tungsten_NextMeleeRandom() >> 10) & 0x7FFFu);
}

int RandomInterval(const int minimum, const int maximum) {
    const int range = maximum - minimum;
    return minimum + (range != 0 ? Random15() % range : 0);
}

overrideAnim_t MeleeOverrideAnimation(const aiMelee_t type) {
    switch (type) {
    case AIMELEE_PUNCH: return ANIMOVERRIDE_MELEE_PUNCH;
    case AIMELEE_KICK: return ANIMOVERRIDE_MELEE_KICK;
    case AIMELEE_FORWARD: return ANIMOVERRIDE_MELEE_FORWARD;
    case AIMELEE_BACK: return ANIMOVERRIDE_MELEE_BACK;
    case AIMELEE_LEFT: return ANIMOVERRIDE_MELEE_LEFT;
    case AIMELEE_RIGHT: return ANIMOVERRIDE_MELEE_RIGHT;
    case AIMELEE_CROUCH_FORWARD: return ANIMOVERRIDE_MELEE_CROUCHED_FORWARD;
    case AIMELEE_MEDIUM: return ANIMOVERRIDE_MELEE_MEDIUM;
    case AIMELEE_LONG: return ANIMOVERRIDE_MELEE_LONG;
    case AIMELEE_RAGE: return ANIMOVERRIDE_RAGE_ATTACK;
    case AIMELEE_MOVING_FORWARD: return ANIMOVERRIDE_MELEE_MOVING_FORWARD;
    case AIMELEE_TAKEDOWN: return ANIMOVERRIDE_MELEE_TAKEDOWN;
    default: return ANIMOVERRIDE_NONE;
    }
}

bool TargetMovingTowardAI(const idMeleeBehaviorRuntime& behavior,
        const idMeleeTargetRuntime& target) {
    if (target.velocity.LengthSqr() == 0.0f) {
        return false;
    }
    const idVec3 relativeVelocity = behavior.velocity - target.velocity;
    return (behavior.origin - target.origin).Dot(relativeVelocity) <= 0.0f;
}

} // namespace

idMeleeStateBase::idMeleeStateBase(const idMeleeStateKind stateKind)
    : idAIState()
    , kind(stateKind)
    , enterFailed(false)
    , meleeStateOpaque{} {
}

// EA: 0x82ADA130
void idMelee_Default::InternalInitState(const idFiniteStateMachine* fsm) {
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_NO_TARGET, MELEE_STATE_DONE);
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_TARGET_OUT_OF_RANGE, MELEE_STATE_DONE);
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_REPOSITION, MELEE_STATE_REPOSITION);
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_ATTACK, MELEE_STATE_ATTACK);
}

// EA: 0x82ADA1B8
void idMelee_Default::AIState_EnterState(
        idAI2* ai, idAIFSM*, int) {
    Tungsten_SetMeleeHeadTracking(*ai, true);
}

// EA: 0x82ADA1C8
void idMelee_Attack::InternalInitState(const idFiniteStateMachine* fsm) {
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_ATTACK_DONE, MELEE_STATE_DEFAULT);
}

// EA: 0x82ADA1E0
idAIStateTransition::aiTransCode_t MELEE_RepositionFailed::Evaluate(
        idAI2* ai, idAIFSM*, idAIState* state, int) {
    int childStatus = 0;
    if (!Tungsten_GetMeleeChildFSMStatus(*state, childStatus)
        || Tungsten_GetMeleeMoveStatus(*ai) >= 2) {
        return TRANSCODE_MELEE_REPOSITION_FAILED;
    }
    return 0;
}

// EA: 0x82ADA248
void idMelee_Reposition::InternalInitState(const idFiniteStateMachine* fsm) {
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_NO_TARGET, MELEE_STATE_DONE);
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_REPOSITION_FAILED, MELEE_STATE_DEFAULT);
    Tungsten_AddMeleeStateTransition(*this, *fsm,
        MELEE_TRANSITION_REPOSITION_DONE, MELEE_STATE_DEFAULT);
}

// EA: 0x82ADA2B0
void idMeleeFSM::InitStates(const idFiniteStateMachineParams* params) {
    Tungsten_InitializeMeleeFSMStates(*this, params);
    Tungsten_AddMeleeFSMState(*this, stateDefault);
    Tungsten_AddMeleeFSMState(*this, stateReposition);
    Tungsten_AddMeleeFSMState(*this, stateAttack);
}

// EA: 0x82ADA328
idAIStateTransition::aiTransCode_t MELEE_Reposition::Evaluate(
        idAI2* ai, idAIFSM*, idAIState*, const int currentTime) {
    idMeleeBehaviorRuntime behavior{};
    if (!Tungsten_GetMeleeBehaviorRuntime(*ai, behavior)
        || behavior.nextDodgeTime > currentTime
        || Random15() % 100 > behavior.meleeDodgeChance) {
        return 0;
    }
    if (!behavior.hasAngryRage || !behavior.wantsAngryRage) {
        return TRANSCODE_MELEE_REPOSITION;
    }
    return 0;
}

// EA: 0x82ADA408
idAIStateTransition::aiTransCode_t COMBAT_MeleeDone::Evaluate(
        idAI2*, idAIFSM*, idAIState* state, int) {
    int childStatus = 0;
    return !Tungsten_GetMeleeChildFSMStatus(*state, childStatus)
        || childStatus == 0 ? TRANSCODE_COMBAT_MELEE_DONE : 0;
}

// EA: 0x82ADA450
idAIStateTransition::aiTransCode_t MELEE_RepositionDone::Evaluate(
        idAI2*, idAIFSM*, idAIState* state, int) {
    int childStatus = 0;
    return !Tungsten_GetMeleeChildFSMStatus(*state, childStatus)
        || childStatus == 0 ? TRANSCODE_MELEE_REPOSITION_DONE : 0;
}

// EA: 0x82ADA4A0
idMeleeFSM::idMeleeFSM()
    : idAIFSM()
    , meleeFSMBaseOpaque{}
    , stateDefault()
    , stateAttack()
    , stateReposition() {
    Tungsten_InitializeMeleeFSMBase(*this, "FSM_melee");
    Tungsten_SetMeleeFSMDefaultState(*this, stateDefault);
}

// EA: 0x82ADA610
idMeleeFSM::~idMeleeFSM() = default;

// EA: 0x82ADA758
idAIStateTransition::aiTransCode_t MELEE_NoTarget::Evaluate(
        idAI2* ai, idAIFSM*, idAIState*, int) {
    idMeleeTargetRuntime target{};
    if (!Tungsten_GetMeleeTargetRuntime(*ai, target)
        || !target.valid || target.dead) {
        return TRANSCODE_MELEE_NO_TARGET;
    }
    return 0;
}

// EA: 0x82ADA820
idAIStateTransition::aiTransCode_t MELEE_TargetOutOfRange::Evaluate(
        idAI2* ai, idAIFSM*, idAIState*, int) {
    idMeleeTargetRuntime target{};
    if (!Tungsten_GetMeleeTargetRuntime(*ai, target) || !target.valid) {
        return 0;
    }
    return target.selectedTypeInRange ? 0
        : TRANSCODE_MELEE_TARGET_OUT_OF_RANGE;
}

// EA: 0x82ADA930
idAIStateTransition::aiTransCode_t MELEE_Attack::Evaluate(
        idAI2* ai, idAIFSM*, idAIState*, int) {
    idMeleeBehaviorRuntime behavior{};
    idMeleeTargetRuntime target{};
    if (!Tungsten_GetMeleeBehaviorRuntime(*ai, behavior)
        || Tungsten_GetMeleeScaledGameMilliseconds()
            < behavior.nextCloseMeleeTime
        || !Tungsten_GetMeleeTargetRuntime(*ai, target)
        || !target.valid || !target.allTypesInRange) {
        return 0;
    }
    return TRANSCODE_MELEE_ATTACK;
}

// EA: 0x82ADAA20
void idMelee_Attack::AIState_EnterState(
        idAI2* ai, idAIFSM* fsm, const int currentTime) {
    idMeleeBehaviorRuntime behavior{};
    if (!Tungsten_GetMeleeBehaviorRuntime(*ai, behavior)) {
        enterFailed = true;
        return;
    }
    Tungsten_SetMeleeNextCloseTime(*ai, currentTime + RandomInterval(
        behavior.minimumCloseMeleeInterval,
        behavior.maximumCloseMeleeInterval));
    Tungsten_SetMeleeHoldFire(*ai, false);

    idMeleeTargetRuntime target{};
    if (!Tungsten_GetMeleeTargetRuntime(*ai, target) || !target.valid
        || target.selectedType == AIMELEE_NONE
        || !target.selectedTypeInRange
        || (behavior.crouching
            && (target.selectedType & AIMELEE_CROUCH_TYPES) == 0)) {
        enterFailed = true;
        return;
    }

    const overrideAnim_t animation =
        MeleeOverrideAnimation(target.selectedType);
    if (animation != ANIMOVERRIDE_NONE) {
        Tungsten_EndMeleeActionScript(*ai);
        Tungsten_StartMeleeAttackAction(*ai, *fsm, *this, animation);
    }
    if (Random15() % 100
        < behavior.angryRageAfterMissingChance) {
        Tungsten_SetMeleeWantAngryRageTime(*ai,
            Tungsten_GetMeleeScaledGameMilliseconds(), "miss enemy");
    }
}

// EA: 0x82ADAD40
void idMelee_Reposition::AIState_EnterState(
        idAI2* ai, idAIFSM* fsm, const int currentTime) {
    idMeleeBehaviorRuntime behavior{};
    idMeleeTargetRuntime target{};
    if (!Tungsten_GetMeleeBehaviorRuntime(*ai, behavior)
        || !Tungsten_GetMeleeTargetRuntime(*ai, target) || !target.valid) {
        enterFailed = true;
        return;
    }

    Tungsten_SetMeleeNextDodgeTime(*ai, currentTime + RandomInterval(
        behavior.minimumMeleeDodgeInterval,
        behavior.maximumMeleeDodgeInterval));
    const float random = static_cast<float>(Random15()) * 0.000030518509f;
    const bool movingToward = TargetMovingTowardAI(behavior, target);
    int dodgeDirection = 1;
    if (target.direction == AIDIR_FRONT) {
        dodgeDirection = random > 0.5f ? 3 : 2;
    } else if (target.direction == AIDIR_FRONT_LEFT) {
        dodgeDirection = movingToward && random < 1.0f ? 4 : 3;
    } else if (target.direction == AIDIR_FRONT_RIGHT) {
        dodgeDirection = movingToward && random < 1.0f ? 4 : 2;
    }
    Tungsten_EndMeleeActionScript(*ai);
    Tungsten_StartMeleeDodgeAction(*ai, *fsm, *this, dodgeDirection);
}

// EA: 0x82ADB0B8
bool idMeleeFSM::CanUse(
        idFiniteStateMachine* fsm, int) const {
    idAI2* const ai = Tungsten_GetMeleeFSMOwner(*fsm);
    if (ai == nullptr) {
        return false;
    }
    idMeleeBehaviorRuntime behavior{};
    idMeleeTargetRuntime target{};
    return Tungsten_GetMeleeBehaviorRuntime(*ai, behavior)
        && behavior.meleeEnabled
        && behavior.validCloseMeleeTypes != 0
        && Tungsten_GetMeleeTargetRuntime(*ai, target)
        && target.valid
        && target.selectedType != AIMELEE_NONE
        && target.selectedTypeInRange;
}
