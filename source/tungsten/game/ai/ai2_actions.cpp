#include "ai2.h"

namespace {

eventVoid DispatchAction(idAI2& ai, const idAI2ActionCall& call) {
    if (ai.core.services != nullptr) {
        ai.core.services->DispatchAIAction(ai, call);
    }
    return eventVoid();
}

#define AI2_ACTION_NO_ARGS(methodName, actionKind) \
    eventVoid idAI2::methodName() { \
        const idAI2ActionCall call(actionKind, #methodName); \
        return DispatchAction(*this, call); \
    }

} // namespace

// Retail symbol: ?Action_LeapAttack@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA: 0x82A29C50, RVA: 0x00A29C50
eventVoid idAI2::Action_LeapAttack(const idVec3& leapTarget) {
    idAI2ActionCall call(AI2_ACTION_LEAP_ATTACK, "Action_LeapAttack");
    call.vectors[0] = &leapTarget;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToPoint@idAI2@@QAA?AVeventVoid@@ABVidVec3@@W4aiArrivalAction_t@@MW4aiActionBool_t@@0@Z
// EA: 0x82A29C60, RVA: 0x00A29C60
eventVoid idAI2::Action_MoveToPoint(const idVec3& destination,
        const aiArrivalAction_t arrivalAction, const float tolerance,
        const aiActionBool_t align, const idVec3& alignDirection) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_POINT,
        "Action_MoveToPoint");
    call.vectors[0] = &destination;
    call.vectors[1] = &alignDirection;
    call.integers[0] = static_cast<int>(arrivalAction);
    call.integers[1] = static_cast<int>(align);
    call.scalars[0] = tolerance;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToPointNoFail@idAI2@@QAA?AVeventVoid@@ABVidVec3@@W4aiArrivalAction_t@@MW4aiActionBool_t@@0PBVidDeclVoiceOver@@@Z
// EA: 0x82A29DB8, RVA: 0x00A29DB8
eventVoid idAI2::Action_MoveToPointNoFail(const idVec3& destination,
        const aiArrivalAction_t arrivalAction, const float tolerance,
        const aiActionBool_t align, const idVec3& alignDirection,
        const idDeclVoiceOver* const failureVoiceOver) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_POINT_NO_FAIL,
        "Action_MoveToPointNoFail");
    call.vectors[0] = &destination;
    call.vectors[1] = &alignDirection;
    call.objects[0] = failureVoiceOver;
    call.integers[0] = static_cast<int>(arrivalAction);
    call.integers[1] = static_cast<int>(align);
    call.scalars[0] = tolerance;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4aiArrivalAction_t@@MW4aiActionBool_t@@ABVidVec3@@@Z
// EA: 0x82A29F38, RVA: 0x00A29F38
eventVoid idAI2::Action_MoveToEntity(const idEntity* const entity,
        const aiArrivalAction_t arrivalAction, const float tolerance,
        const aiActionBool_t align, const idVec3& alignDirection) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_ENTITY,
        "Action_MoveToEntity");
    call.entities[0] = entity;
    call.vectors[0] = &alignDirection;
    call.integers[0] = static_cast<int>(arrivalAction);
    call.integers[1] = static_cast<int>(align);
    call.scalars[0] = tolerance;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToEntityNoFail@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4aiArrivalAction_t@@MW4aiActionBool_t@@ABVidVec3@@PBVidDeclVoiceOver@@@Z
// EA: 0x82A2A078, RVA: 0x00A2A078
eventVoid idAI2::Action_MoveToEntityNoFail(
        const idEntity* const entity,
        const aiArrivalAction_t arrivalAction, const float tolerance,
        const aiActionBool_t align, const idVec3& alignDirection,
        const idDeclVoiceOver* const failureVoiceOver) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_ENTITY_NO_FAIL,
        "Action_MoveToEntityNoFail");
    call.entities[0] = entity;
    call.vectors[0] = &alignDirection;
    call.objects[0] = failureVoiceOver;
    call.integers[0] = static_cast<int>(arrivalAction);
    call.integers[1] = static_cast<int>(align);
    call.scalars[0] = tolerance;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToPathPoint@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA: 0x82A2A1D8, RVA: 0x00A2A1D8
eventVoid idAI2::Action_MoveToPathPoint(
        const idEntity* const pathPoint) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_PATH_POINT,
        "Action_MoveToPathPoint");
    call.entities[0] = pathPoint;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToPathPointNoFail@idAI2@@QAA?AVeventVoid@@PBVidEntity@@PBVidDeclVoiceOver@@@Z
// EA: 0x82A2A2A0, RVA: 0x00A2A2A0
eventVoid idAI2::Action_MoveToPathPointNoFail(
        const idEntity* const pathPoint,
        const idDeclVoiceOver* const failureVoiceOver) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_PATH_POINT_NO_FAIL,
        "Action_MoveToPathPointNoFail");
    call.entities[0] = pathPoint;
    call.objects[0] = failureVoiceOver;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToCover@idAI2@@QAA?AVeventVoid@@ABVidVec3@@W4coverAction_t@@W4posture_t@@0@Z
// EA: 0x82A2A388, RVA: 0x00A2A388
eventVoid idAI2::Action_MoveToCover(const idVec3& position,
        const coverAction_t coverAction, const posture_t posture,
        const idVec3& direction) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_COVER,
        "Action_MoveToCover");
    call.vectors[0] = &position;
    call.vectors[1] = &direction;
    call.integers[0] = static_cast<int>(coverAction);
    call.integers[1] = static_cast<int>(posture);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_UseZipline@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA: 0x82A2A4C8, RVA: 0x00A2A4C8
eventVoid idAI2::Action_UseZipline(const idEntity* const zipline) {
    idAI2ActionCall call(AI2_ACTION_USE_ZIPLINE, "Action_UseZipline");
    call.entities[0] = zipline;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetMovePushStatus@idAI2@@QAA?AVeventVoid@@W4aiMovePushStatus_t@@@Z
// EA: 0x82A2A550, RVA: 0x00A2A550
eventVoid idAI2::Action_SetMovePushStatus(
        const aiMovePushStatus_t status) {
    idAI2ActionCall call(AI2_ACTION_SET_MOVE_PUSH_STATUS,
        "Action_SetMovePushStatus");
    call.integers[0] = static_cast<int>(status);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_Idle@idAI2@@QAA?AVeventVoid@@HW4aiIdleTurn_t@@@Z
// EA: 0x82A2A5D8, RVA: 0x00A2A5D8
eventVoid idAI2::Action_Idle(const int duration,
        const aiIdleTurn_t turnType) {
    idAI2ActionCall call(AI2_ACTION_IDLE, "Action_Idle");
    call.integers[0] = duration;
    call.integers[1] = static_cast<int>(turnType);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_Pain@idAI2@@QAA?AVeventVoid@@W4painType_t@@W4aiDirection_t@@MPBD@Z
// EA: 0x82A2A680, RVA: 0x00A2A680
eventVoid idAI2::Action_Pain(const painType_t painType,
        const aiDirection_t direction, const float strength,
        const char* const damageGroup) {
    idAI2ActionCall call(AI2_ACTION_PAIN, "Action_Pain");
    call.integers[0] = static_cast<int>(painType);
    call.integers[1] = static_cast<int>(direction);
    call.scalars[0] = strength;
    call.strings[0] = damageGroup;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_StandToCrouch@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2A700, RVA: 0x00A2A700
AI2_ACTION_NO_ARGS(Action_StandToCrouch, AI2_ACTION_STAND_TO_CROUCH)

// Retail symbol: ?Action_CrouchToStand@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2A780, RVA: 0x00A2A780
AI2_ACTION_NO_ARGS(Action_CrouchToStand, AI2_ACTION_CROUCH_TO_STAND)

// Retail symbol: ?Action_PullTriggerRight@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2A800, RVA: 0x00A2A800
AI2_ACTION_NO_ARGS(Action_PullTriggerRight, AI2_ACTION_PULL_TRIGGER_RIGHT)

// Retail symbol: ?Action_ReleaseTriggerRight@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2A880, RVA: 0x00A2A880
AI2_ACTION_NO_ARGS(Action_ReleaseTriggerRight,
    AI2_ACTION_RELEASE_TRIGGER_RIGHT)

// Retail symbol: ?Action_PullTriggerLeft@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2A900, RVA: 0x00A2A900
AI2_ACTION_NO_ARGS(Action_PullTriggerLeft, AI2_ACTION_PULL_TRIGGER_LEFT)

// Retail symbol: ?Action_ReleaseTriggerLeft@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2A980, RVA: 0x00A2A980
AI2_ACTION_NO_ARGS(Action_ReleaseTriggerLeft,
    AI2_ACTION_RELEASE_TRIGGER_LEFT)

// Retail symbol: ?Action_WaitForAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@@Z
// EA: 0x82A2AA00, RVA: 0x00A2AA00
eventVoid idAI2::Action_WaitForAnim(const idAnimWebPath& animation) {
    idAI2ActionCall call(AI2_ACTION_WAIT_FOR_ANIM,
        "Action_WaitForAnim");
    call.animWebPaths[0] = &animation;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_WaitForAnimVia@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@0@Z
// EA: 0x82A2AA88, RVA: 0x00A2AA88
eventVoid idAI2::Action_WaitForAnimVia(const idAnimWebPath& animation,
        const idAnimWebPath& viaAnimation) {
    idAI2ActionCall call(AI2_ACTION_WAIT_FOR_ANIM_VIA,
        "Action_WaitForAnimVia");
    call.animWebPaths[0] = &animation;
    call.animWebPaths[1] = &viaAnimation;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_LoopAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@H@Z
// EA: 0x82A2AB30, RVA: 0x00A2AB30
eventVoid idAI2::Action_LoopAnim(const idAnimWebPath& animation,
        const int count) {
    idAI2ActionCall call(AI2_ACTION_LOOP_ANIM, "Action_LoopAnim");
    call.animWebPaths[0] = &animation;
    call.integers[0] = count;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_LoopAnimExitAtEnd@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@HH@Z
// EA: 0x82A2ABD8, RVA: 0x00A2ABD8
eventVoid idAI2::Action_LoopAnimExitAtEnd(
        const idAnimWebPath& animation, const int count,
        const int exitAtEnd) {
    idAI2ActionCall call(AI2_ACTION_LOOP_ANIM_EXIT_AT_END,
        "Action_LoopAnimExitAtEnd");
    call.animWebPaths[0] = &animation;
    call.integers[0] = count;
    call.integers[1] = exitAtEnd;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_StartAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@W4aiActionBool_t@@1@Z
// EA: 0x82A2ACA0, RVA: 0x00A2ACA0
eventVoid idAI2::Action_StartAnim(const idAnimWebPath& animation,
        const aiActionBool_t interrupt, const aiActionBool_t wait) {
    idAI2ActionCall call(AI2_ACTION_START_ANIM, "Action_StartAnim");
    call.animWebPaths[0] = &animation;
    call.integers[0] = static_cast<int>(interrupt);
    call.integers[1] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_WaitForTraversalAnim@idAI2@@QAA?AVeventVoid@@ABVidAnimWebPath@@W4aiActionBool_t@@@Z
// EA: 0x82A2AD78, RVA: 0x00A2AD78
eventVoid idAI2::Action_WaitForTraversalAnim(
        const idAnimWebPath& animation, const aiActionBool_t wait) {
    idAI2ActionCall call(AI2_ACTION_WAIT_FOR_TRAVERSAL_ANIM,
        "Action_WaitForTraversalAnim");
    call.animWebPaths[0] = &animation;
    call.integers[0] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ChangeAnimState@idAI2@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@W4aiAnimWait_t@@@Z
// EA: 0x82A2AE28, RVA: 0x00A2AE28
eventVoid idAI2::Action_ChangeAnimState(const aiAnimWeb_t web,
        const idAnimWebPath& animation, const aiAnimWait_t wait) {
    idAI2ActionCall call(AI2_ACTION_CHANGE_ANIM_STATE,
        "Action_ChangeAnimState");
    call.animWebPaths[0] = &animation;
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ChangeAnimStateVia@idAI2@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@1W4aiAnimWait_t@@@Z
// EA: 0x82A2AEF0, RVA: 0x00A2AEF0
eventVoid idAI2::Action_ChangeAnimStateVia(const aiAnimWeb_t web,
        const idAnimWebPath& animation,
        const idAnimWebPath& viaAnimation, const aiAnimWait_t wait) {
    idAI2ActionCall call(AI2_ACTION_CHANGE_ANIM_STATE_VIA,
        "Action_ChangeAnimStateVia");
    call.animWebPaths[0] = &animation;
    call.animWebPaths[1] = &viaAnimation;
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ForceAnimState@idAI2@@QAA?AVeventVoid@@W4aiAnimWeb_t@@ABVidAnimWebPath@@HW4aiAnimWait_t@@@Z
// EA: 0x82A2AFD8, RVA: 0x00A2AFD8
eventVoid idAI2::Action_ForceAnimState(const aiAnimWeb_t web,
        const idAnimWebPath& animation, const int force,
        const aiAnimWait_t wait) {
    idAI2ActionCall call(AI2_ACTION_FORCE_ANIM_STATE,
        "Action_ForceAnimState");
    call.animWebPaths[0] = &animation;
    call.integers[0] = static_cast<int>(web);
    call.integers[1] = force;
    call.integers[2] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_Dodge@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA: 0x82A2B0C0, RVA: 0x00A2B0C0
eventVoid idAI2::Action_Dodge(const idVec3& direction) {
    idAI2ActionCall call(AI2_ACTION_DODGE, "Action_Dodge");
    call.vectors[0] = &direction;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_Wait@idAI2@@QAA?AVeventVoid@@H@Z
// EA: 0x82A2B0F8, RVA: 0x00A2B0F8
eventVoid idAI2::Action_Wait(const int duration) {
    idAI2ActionCall call(AI2_ACTION_WAIT, "Action_Wait");
    call.integers[0] = duration;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_Melee@idAI2@@QAA?AVeventVoid@@W4overrideAnim_t@@@Z
// EA: 0x82A2B180, RVA: 0x00A2B180
eventVoid idAI2::Action_Melee(const overrideAnim_t animation) {
    idAI2ActionCall call(AI2_ACTION_MELEE, "Action_Melee");
    call.integers[0] = static_cast<int>(animation);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_TurnToPoint@idAI2@@QAA?AVeventVoid@@ABVidVec3@@@Z
// EA: 0x82A2B260, RVA: 0x00A2B260
eventVoid idAI2::Action_TurnToPoint(const idVec3& point) {
    idAI2ActionCall call(AI2_ACTION_TURN_TO_POINT,
        "Action_TurnToPoint");
    call.vectors[0] = &point;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_TurnToEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA: 0x82A2B2F8, RVA: 0x00A2B2F8
eventVoid idAI2::Action_TurnToEntity(const idEntity* const entity) {
    idAI2ActionCall call(AI2_ACTION_TURN_TO_ENTITY,
        "Action_TurnToEntity");
    call.entities[0] = entity;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_TurnToEntityWithOffset@idAI2@@QAA?AVeventVoid@@PBVidEntity@@M@Z
// EA: 0x82A2B380, RVA: 0x00A2B380
eventVoid idAI2::Action_TurnToEntityWithOffset(
        const idEntity* const entity, const float offset) {
    idAI2ActionCall call(AI2_ACTION_TURN_TO_ENTITY_WITH_OFFSET,
        "Action_TurnToEntityWithOffset");
    call.entities[0] = entity;
    call.scalars[0] = offset;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_Dive@idAI2@@QAA?AVeventVoid@@MM@Z
// EA: 0x82A2B428, RVA: 0x00A2B428
eventVoid idAI2::Action_Dive(const float distance,
        const float duration) {
    idAI2ActionCall call(AI2_ACTION_DIVE, "Action_Dive");
    call.scalars[0] = distance;
    call.scalars[1] = duration;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_WaitForEntity@idAI2@@QAA?AVeventVoid@@PBVidEntity@@M@Z
// EA: 0x82A2B4F0, RVA: 0x00A2B4F0
eventVoid idAI2::Action_WaitForEntity(const idEntity* const entity,
        const float distance) {
    idAI2ActionCall call(AI2_ACTION_WAIT_FOR_ENTITY,
        "Action_WaitForEntity");
    call.entities[0] = entity;
    call.scalars[0] = distance;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_EnterVehicle@idAI2@@QAA?AVeventVoid@@PBVidEntity@@0@Z
// EA: 0x82A2B598, RVA: 0x00A2B598
eventVoid idAI2::Action_EnterVehicle(const idEntity* const vehicle,
        const idEntity* const seat) {
    idAI2ActionCall call(AI2_ACTION_ENTER_VEHICLE,
        "Action_EnterVehicle");
    call.entities[0] = vehicle;
    call.entities[1] = seat;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_PlayVoiceOver@idAI2@@QAA?AVeventVoid@@PBVidDeclVoiceOver@@W4aiActionBool_t@@@Z
// EA: 0x82A2B648, RVA: 0x00A2B648
eventVoid idAI2::Action_PlayVoiceOver(
        const idDeclVoiceOver* const voiceOver,
        const aiActionBool_t wait) {
    idAI2ActionCall call(AI2_ACTION_PLAY_VOICE_OVER,
        "Action_PlayVoiceOver");
    call.objects[0] = voiceOver;
    call.integers[0] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_PlayInteractionVoiceOver@idAI2@@QAA?AVeventVoid@@PBVidDeclVoiceOver@@PBVidEntity@@M_N@Z
// EA: 0x82A2B750, RVA: 0x00A2B750
eventVoid idAI2::Action_PlayInteractionVoiceOver(
        const idDeclVoiceOver* const voiceOver,
        const idEntity* const player, const float distance,
        const bool wait) {
    idAI2ActionCall call(AI2_ACTION_PLAY_INTERACTION_VOICE_OVER,
        "Action_PlayInteractionVoiceOver");
    call.objects[0] = voiceOver;
    call.entities[0] = player;
    call.scalars[0] = distance;
    call.booleans[0] = wait;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_StopVoiceOver@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2B8A8, RVA: 0x00A2B8A8
AI2_ACTION_NO_ARGS(Action_StopVoiceOver, AI2_ACTION_STOP_VOICE_OVER)

// Retail symbol: ?Action_PlayOverrideAnim@idAI2@@QAA?AVeventVoid@@W4overrideAnim_t@@W4aiActionBool_t@@@Z
// EA: 0x82A2B908, RVA: 0x00A2B908
eventVoid idAI2::Action_PlayOverrideAnim(
        const overrideAnim_t animation, const aiActionBool_t wait) {
    idAI2ActionCall call(AI2_ACTION_PLAY_OVERRIDE_ANIM,
        "Action_PlayOverrideAnim");
    call.integers[0] = static_cast<int>(animation);
    call.integers[1] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_PlayOverrideAnimInterrupt@idAI2@@QAA?AVeventVoid@@W4overrideAnim_t@@W4aiActionBool_t@@@Z
// EA: 0x82A2B990, RVA: 0x00A2B990
eventVoid idAI2::Action_PlayOverrideAnimInterrupt(
        const overrideAnim_t animation, const aiActionBool_t wait) {
    idAI2ActionCall call(AI2_ACTION_PLAY_OVERRIDE_ANIM_INTERRUPT,
        "Action_PlayOverrideAnimInterrupt");
    call.integers[0] = static_cast<int>(animation);
    call.integers[1] = static_cast<int>(wait);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_HolsterWeapon@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2BA18, RVA: 0x00A2BA18
AI2_ACTION_NO_ARGS(Action_HolsterWeapon, AI2_ACTION_HOLSTER_WEAPON)

// Retail symbol: ?Action_DrawWeapon@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2BA98, RVA: 0x00A2BA98
AI2_ACTION_NO_ARGS(Action_DrawWeapon, AI2_ACTION_DRAW_WEAPON)

// Retail symbol: ?Action_PerformCoverAction@idAI2@@QAA?AVeventVoid@@W4coverAction_t@@H@Z
// EA: 0x82A2BB18, RVA: 0x00A2BB18
eventVoid idAI2::Action_PerformCoverAction(const coverAction_t action,
        const int duration) {
    idAI2ActionCall call(AI2_ACTION_PERFORM_COVER_ACTION,
        "Action_PerformCoverAction");
    call.integers[0] = static_cast<int>(action);
    call.integers[1] = duration;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_WaitForPlayerInteraction@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2BBB8, RVA: 0x00A2BBB8
AI2_ACTION_NO_ARGS(Action_WaitForPlayerInteraction,
    AI2_ACTION_WAIT_FOR_PLAYER_INTERACTION)

// Retail symbol: ?Action_WaitForPlayerInteractionDist@idAI2@@QAA?AVeventVoid@@M@Z
// EA: 0x82A2BC48, RVA: 0x00A2BC48
eventVoid idAI2::Action_WaitForPlayerInteractionDist(
        const float distance) {
    idAI2ActionCall call(AI2_ACTION_WAIT_FOR_PLAYER_INTERACTION_DIST,
        "Action_WaitForPlayerInteractionDist");
    call.scalars[0] = distance;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_WaitForAIVar@idAI2@@QAA?AVeventVoid@@PBDW4aiVarOp_t@@0@Z
// EA: 0x82A2BCD0, RVA: 0x00A2BCD0
eventVoid idAI2::Action_WaitForAIVar(const char* const variable,
        const aiVarOp_t operation, const char* const value) {
    idAI2ActionCall call(AI2_ACTION_WAIT_FOR_AI_VAR,
        "Action_WaitForAIVar");
    call.strings[0] = variable;
    call.strings[1] = value;
    call.integers[0] = static_cast<int>(operation);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetAlertCycle@idAI2@@QAA?AVeventVoid@@W4alertCycle_t@@@Z
// EA: 0x82A2BD90, RVA: 0x00A2BD90
eventVoid idAI2::Action_SetAlertCycle(const alertCycle_t alertCycle) {
    idAI2ActionCall call(AI2_ACTION_SET_ALERT_CYCLE,
        "Action_SetAlertCycle");
    call.integers[0] = static_cast<int>(alertCycle);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetSubWeb@idAI2@@QAA?AVeventVoid@@W4aiSubWeb_t@@@Z
// EA: 0x82A2BE18, RVA: 0x00A2BE18
eventVoid idAI2::Action_SetSubWeb(const aiSubWeb_t subWeb) {
    idAI2ActionCall call(AI2_ACTION_SET_SUB_WEB, "Action_SetSubWeb");
    call.integers[0] = static_cast<int>(subWeb);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetFocus@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4aiActionBool_t@@11W4aimPoint_t@@@Z
// EA: 0x82A2BEA0, RVA: 0x00A2BEA0
eventVoid idAI2::Action_SetFocus(const idEntity* const entity,
        const aiActionBool_t look, const aiActionBool_t aim,
        const aiActionBool_t keepInView, const aimPoint_t aimPoint) {
    idAI2ActionCall call(AI2_ACTION_SET_FOCUS, "Action_SetFocus");
    call.entities[0] = entity;
    call.integers[0] = static_cast<int>(look);
    call.integers[1] = static_cast<int>(aim);
    call.integers[2] = static_cast<int>(keepInView);
    call.integers[3] = static_cast<int>(aimPoint);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ClearLookFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2BFB8, RVA: 0x00A2BFB8
AI2_ACTION_NO_ARGS(Action_ClearLookFocus, AI2_ACTION_CLEAR_LOOK_FOCUS)

// Retail symbol: ?Action_ClearAimFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2C038, RVA: 0x00A2C038
AI2_ACTION_NO_ARGS(Action_ClearAimFocus, AI2_ACTION_CLEAR_AIM_FOCUS)

// Retail symbol: ?Action_SetAimPoint@idAI2@@QAA?AVeventVoid@@W4aimPoint_t@@@Z
// EA: 0x82A2C0B8, RVA: 0x00A2C0B8
eventVoid idAI2::Action_SetAimPoint(const aimPoint_t aimPoint) {
    idAI2ActionCall call(AI2_ACTION_SET_AIM_POINT,
        "Action_SetAimPoint");
    call.integers[0] = static_cast<int>(aimPoint);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetFireMode@idAI2@@QAA?AVeventVoid@@W4aiFireMode_t@@@Z
// EA: 0x82A2C140, RVA: 0x00A2C140
eventVoid idAI2::Action_SetFireMode(const aiFireMode_t fireMode) {
    idAI2ActionCall call(AI2_ACTION_SET_FIRE_MODE,
        "Action_SetFireMode");
    call.integers[0] = static_cast<int>(fireMode);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetScriptAbort@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@0@Z
// EA: 0x82A2C1C8, RVA: 0x00A2C1C8
eventVoid idAI2::Action_SetScriptAbort(const aiActionBool_t abort,
        const aiActionBool_t finishCurrentAction) {
    idAI2ActionCall call(AI2_ACTION_SET_SCRIPT_ABORT,
        "Action_SetScriptAbort");
    call.integers[0] = static_cast<int>(abort);
    call.integers[1] = static_cast<int>(finishCurrentAction);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetPosture@idAI2@@QAA?AVeventVoid@@W4posture_t@@@Z
// EA: 0x82A2C280, RVA: 0x00A2C280
eventVoid idAI2::Action_SetPosture(const posture_t posture) {
    idAI2ActionCall call(AI2_ACTION_SET_POSTURE,
        "Action_SetPosture");
    call.integers[0] = static_cast<int>(posture);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetWalkState@idAI2@@QAA?AVeventVoid@@W4walkState_t@@@Z
// EA: 0x82A2C308, RVA: 0x00A2C308
eventVoid idAI2::Action_SetWalkState(const walkState_t walkState) {
    idAI2ActionCall call(AI2_ACTION_SET_WALK_STATE,
        "Action_SetWalkState");
    call.integers[0] = static_cast<int>(walkState);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetSitState@idAI2@@QAA?AVeventVoid@@W4sitState_t@@@Z
// EA: 0x82A2C390, RVA: 0x00A2C390
eventVoid idAI2::Action_SetSitState(const sitState_t sitState) {
    idAI2ActionCall call(AI2_ACTION_SET_SIT_STATE,
        "Action_SetSitState");
    call.integers[0] = static_cast<int>(sitState);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetStandState@idAI2@@QAA?AVeventVoid@@W4standState_t@@@Z
// EA: 0x82A2C418, RVA: 0x00A2C418
eventVoid idAI2::Action_SetStandState(const standState_t standState) {
    idAI2ActionCall call(AI2_ACTION_SET_STAND_STATE,
        "Action_SetStandState");
    call.integers[0] = static_cast<int>(standState);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetIdleState@idAI2@@QAA?AVeventVoid@@W4runIndexType_t@@@Z
// EA: 0x82A2C4A0, RVA: 0x00A2C4A0
eventVoid idAI2::Action_SetIdleState(const runIndexType_t idleState) {
    idAI2ActionCall call(AI2_ACTION_SET_IDLE_STATE,
        "Action_SetIdleState");
    call.integers[0] = static_cast<int>(idleState);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_IgnorePlayerApproach@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA: 0x82A2C528, RVA: 0x00A2C528
eventVoid idAI2::Action_IgnorePlayerApproach(
        const aiActionBool_t ignore) {
    idAI2ActionCall call(AI2_ACTION_IGNORE_PLAYER_APPROACH,
        "Action_IgnorePlayerApproach");
    call.integers[0] = static_cast<int>(ignore);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_NoticePlayerApproach@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA: 0x82A2C5B8, RVA: 0x00A2C5B8
eventVoid idAI2::Action_NoticePlayerApproach(
        const aiActionBool_t notice) {
    idAI2ActionCall call(AI2_ACTION_NOTICE_PLAYER_APPROACH,
        "Action_NoticePlayerApproach");
    call.integers[0] = static_cast<int>(notice);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_GiveItem@idAI2@@QAA?AVeventVoid@@PBVidEntity@@PBVidDeclInventory@@@Z
// EA: 0x82A2C648, RVA: 0x00A2C648
eventVoid idAI2::Action_GiveItem(const idEntity* const player,
        const idDeclInventory* const inventory) {
    idAI2ActionCall call(AI2_ACTION_GIVE_ITEM, "Action_GiveItem");
    call.entities[0] = player;
    call.objects[0] = inventory;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_TakeItem@idAI2@@QAA?AVeventVoid@@PBVidEntity@@PBVidDeclInventory@@@Z
// EA: 0x82A2C748, RVA: 0x00A2C748
eventVoid idAI2::Action_TakeItem(const idEntity* const player,
        const idDeclInventory* const inventory) {
    idAI2ActionCall call(AI2_ACTION_TAKE_ITEM, "Action_TakeItem");
    call.entities[0] = player;
    call.objects[0] = inventory;
    return DispatchAction(*this, call);
}

// Retail symbol: ?GetPlayerTarget@idAI2@@QBAPAVidPlayer@@W4aiPlayer_t@@@Z
// EA: 0x82A2C848, RVA: 0x00A2C848
idPlayer* idAI2::GetPlayerTarget(const aiPlayer_t player) const {
    return core.services != nullptr
        ? core.services->SelectAIPlayerTarget(
            *this, static_cast<int>(player))
        : nullptr;
}

// Retail symbol: ?Action_SetPlayerEnemy@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@@Z
// EA: 0x82A2CAD0, RVA: 0x00A2CAD0
eventVoid idAI2::Action_SetPlayerEnemy(const aiPlayer_t player) {
    idAI2ActionCall call(AI2_ACTION_SET_PLAYER_ENEMY,
        "Action_SetPlayerEnemy");
    call.integers[0] = static_cast<int>(player);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetEnemy@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA: 0x82A2CB58, RVA: 0x00A2CB58
eventVoid idAI2::Action_SetEnemy(const idEntity* const enemy) {
    idAI2ActionCall call(AI2_ACTION_SET_ENEMY, "Action_SetEnemy");
    call.entities[0] = enemy;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SearchToTarget@idAI2@@QAA?AVeventVoid@@PBVidEntity@@@Z
// EA: 0x82A2CBE0, RVA: 0x00A2CBE0
eventVoid idAI2::Action_SearchToTarget(const idEntity* const target) {
    idAI2ActionCall call(AI2_ACTION_SEARCH_TO_TARGET,
        "Action_SearchToTarget");
    call.entities[0] = target;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetPlayerFocus@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@W4aiActionBool_t@@1@Z
// EA: 0x82A2CC68, RVA: 0x00A2CC68
eventVoid idAI2::Action_SetPlayerFocus(const aiPlayer_t player,
        const aiActionBool_t look, const aiActionBool_t aim) {
    idAI2ActionCall call(AI2_ACTION_SET_PLAYER_FOCUS,
        "Action_SetPlayerFocus");
    call.integers[0] = static_cast<int>(player);
    call.integers[1] = static_cast<int>(look);
    call.integers[2] = static_cast<int>(aim);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetActionNodeGroup@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA: 0x82A2CD70, RVA: 0x00A2CD70
eventVoid idAI2::Action_SetActionNodeGroup(const char* const groupName) {
    idAI2ActionCall call(AI2_ACTION_SET_ACTION_NODE_GROUP,
        "Action_SetActionNodeGroup");
    call.strings[0] = groupName;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_Trigger@idAI2@@QAA?AVeventVoid@@PAVidEntity@@@Z
// EA: 0x82A2CDF8, RVA: 0x00A2CDF8
eventVoid idAI2::Action_Trigger(idEntity* const entity) {
    idAI2ActionCall call(AI2_ACTION_TRIGGER, "Action_Trigger");
    call.entities[0] = entity;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_EnableDamage@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@0@Z
// EA: 0x82A2CE80, RVA: 0x00A2CE80
eventVoid idAI2::Action_EnableDamage(const aiActionBool_t enable,
        const aiActionBool_t enableWhenDead) {
    idAI2ActionCall call(AI2_ACTION_ENABLE_DAMAGE,
        "Action_EnableDamage");
    call.integers[0] = static_cast<int>(enable);
    call.integers[1] = static_cast<int>(enableWhenDead);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_EnablePain@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA: 0x82A2CF30, RVA: 0x00A2CF30
eventVoid idAI2::Action_EnablePain(const aiActionBool_t enable) {
    idAI2ActionCall call(AI2_ACTION_ENABLE_PAIN,
        "Action_EnablePain");
    call.integers[0] = static_cast<int>(enable);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_EnableAutoFocus@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@0@Z
// EA: 0x82A2CFC0, RVA: 0x00A2CFC0
eventVoid idAI2::Action_EnableAutoFocus(const aiActionBool_t enable,
        const aiActionBool_t clearFocus) {
    idAI2ActionCall call(AI2_ACTION_ENABLE_AUTO_FOCUS,
        "Action_EnableAutoFocus");
    call.integers[0] = static_cast<int>(enable);
    call.integers[1] = static_cast<int>(clearFocus);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_EnableBodyRotation@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA: 0x82A2D070, RVA: 0x00A2D070
eventVoid idAI2::Action_EnableBodyRotation(
        const aiActionBool_t enable) {
    idAI2ActionCall call(AI2_ACTION_ENABLE_BODY_ROTATION,
        "Action_EnableBodyRotation");
    call.integers[0] = static_cast<int>(enable);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_EnableWalkIK@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA: 0x82A2D100, RVA: 0x00A2D100
eventVoid idAI2::Action_EnableWalkIK(const aiActionBool_t enable) {
    idAI2ActionCall call(AI2_ACTION_ENABLE_WALK_IK,
        "Action_EnableWalkIK");
    call.integers[0] = static_cast<int>(enable);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_EnableHeadTracking@idAI2@@QAA?AVeventVoid@@W4aiActionBool_t@@@Z
// EA: 0x82A2D190, RVA: 0x00A2D190
eventVoid idAI2::Action_EnableHeadTracking(
        const aiActionBool_t enable) {
    idAI2ActionCall call(AI2_ACTION_ENABLE_HEAD_TRACKING,
        "Action_EnableHeadTracking");
    call.integers[0] = static_cast<int>(enable);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ForceOpenCombat@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@@Z
// EA: 0x82A2D220, RVA: 0x00A2D220
eventVoid idAI2::Action_ForceOpenCombat(const aiPlayer_t player) {
    idAI2ActionCall call(AI2_ACTION_FORCE_OPEN_COMBAT,
        "Action_ForceOpenCombat");
    call.integers[0] = static_cast<int>(player);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ForceAwarenessByDistance@idAI2@@QAA?AVeventVoid@@M_N0@Z
// EA: 0x82A2D2A8, RVA: 0x00A2D2A8
eventVoid idAI2::Action_ForceAwarenessByDistance(const float distance,
        const bool includePlayers, const bool includeAI) {
    idAI2ActionCall call(AI2_ACTION_FORCE_AWARENESS_BY_DISTANCE,
        "Action_ForceAwarenessByDistance");
    call.scalars[0] = distance;
    call.booleans[0] = includePlayers;
    call.booleans[1] = includeAI;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ForcePlayerInteraction@idAI2@@QAA?AVeventVoid@@W4aiPlayer_t@@@Z
// EA: 0x82A2D370, RVA: 0x00A2D370
eventVoid idAI2::Action_ForcePlayerInteraction(const aiPlayer_t player) {
    idAI2ActionCall call(AI2_ACTION_FORCE_PLAYER_INTERACTION,
        "Action_ForcePlayerInteraction");
    call.integers[0] = static_cast<int>(player);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetAIVar@idAI2@@QAA?AVeventVoid@@PBDW4aiVarType_t@@0@Z
// EA: 0x82A2D3F8, RVA: 0x00A2D3F8
eventVoid idAI2::Action_SetAIVar(const char* const variable,
        const aiVarType_t type, const char* const value) {
    idAI2ActionCall call(AI2_ACTION_SET_AI_VAR, "Action_SetAIVar");
    call.strings[0] = variable;
    call.strings[1] = value;
    call.integers[0] = static_cast<int>(type);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetScriptFlag@idAI2@@QAA?AVeventVoid@@W4aiActionScriptFlags_t@@@Z
// EA: 0x82A2D4B8, RVA: 0x00A2D4B8
eventVoid idAI2::Action_SetScriptFlag(
        const aiActionScriptFlags_t flag) {
    idAI2ActionCall call(AI2_ACTION_SET_SCRIPT_FLAG,
        "Action_SetScriptFlag");
    call.integers[0] = static_cast<int>(flag);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ClearScriptFlag@idAI2@@QAA?AVeventVoid@@W4aiActionScriptFlags_t@@@Z
// EA: 0x82A2D540, RVA: 0x00A2D540
eventVoid idAI2::Action_ClearScriptFlag(
        const aiActionScriptFlags_t flag) {
    idAI2ActionCall call(AI2_ACTION_CLEAR_SCRIPT_FLAG,
        "Action_ClearScriptFlag");
    call.integers[0] = static_cast<int>(flag);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetPerceptionFlag@idAI2@@QAA?AVeventVoid@@W4aiPerceptionFlags_t@@@Z
// EA: 0x82A2D5C8, RVA: 0x00A2D5C8
eventVoid idAI2::Action_SetPerceptionFlag(
        const aiPerceptionFlags_t flag) {
    idAI2ActionCall call(AI2_ACTION_SET_PERCEPTION_FLAG,
        "Action_SetPerceptionFlag");
    call.integers[0] = static_cast<int>(flag);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ClearPerceptionFlag@idAI2@@QAA?AVeventVoid@@W4aiPerceptionFlags_t@@@Z
// EA: 0x82A2D650, RVA: 0x00A2D650
eventVoid idAI2::Action_ClearPerceptionFlag(
        const aiPerceptionFlags_t flag) {
    idAI2ActionCall call(AI2_ACTION_CLEAR_PERCEPTION_FLAG,
        "Action_ClearPerceptionFlag");
    call.integers[0] = static_cast<int>(flag);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ClearWorldState@idAI2@@QAA?AVeventVoid@@XZ
// EA: 0x82A2D6D8, RVA: 0x00A2D6D8
AI2_ACTION_NO_ARGS(Action_ClearWorldState, AI2_ACTION_CLEAR_WORLD_STATE)

// Retail symbol: ?Action_ShowAttachment@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA: 0x82A2D758, RVA: 0x00A2D758
eventVoid idAI2::Action_ShowAttachment(const char* const attachment) {
    idAI2ActionCall call(AI2_ACTION_SHOW_ATTACHMENT,
        "Action_ShowAttachment");
    call.strings[0] = attachment;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_HideAttachment@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA: 0x82A2D7E0, RVA: 0x00A2D7E0
eventVoid idAI2::Action_HideAttachment(const char* const attachment) {
    idAI2ActionCall call(AI2_ACTION_HIDE_ATTACHMENT,
        "Action_HideAttachment");
    call.strings[0] = attachment;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_DropAttachment@idAI2@@QAA?AVeventVoid@@PBD@Z
// EA: 0x82A2D868, RVA: 0x00A2D868
eventVoid idAI2::Action_DropAttachment(const char* const attachment) {
    idAI2ActionCall call(AI2_ACTION_DROP_ATTACHMENT,
        "Action_DropAttachment");
    call.strings[0] = attachment;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetMoveMode@idAI2@@QAA?AVeventVoid@@W4aiMovementMode_t@@@Z
// EA: 0x82A2D8F0, RVA: 0x00A2D8F0
eventVoid idAI2::Action_SetMoveMode(
        const aiMovementMode_t movementMode) {
    idAI2ActionCall call(AI2_ACTION_SET_MOVE_MODE,
        "Action_SetMoveMode");
    call.integers[0] = static_cast<int>(movementMode);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_SetAccuracy@idAI2@@QAA?AVeventVoid@@W4aiAccuracy_t@@@Z
// EA: 0x82A2D978, RVA: 0x00A2D978
eventVoid idAI2::Action_SetAccuracy(const aiAccuracy_t accuracy) {
    idAI2ActionCall call(AI2_ACTION_SET_ACCURACY,
        "Action_SetAccuracy");
    call.integers[0] = static_cast<int>(accuracy);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ScriptedAnimWeb@idAI2@@QAA?AVeventVoid@@PBVidEntity@@H@Z
// EA: 0x82A2DA00, RVA: 0x00A2DA00
eventVoid idAI2::Action_ScriptedAnimWeb(const idEntity* const entity,
        const int flags) {
    idAI2ActionCall call(AI2_ACTION_SCRIPTED_ANIM_WEB,
        "Action_ScriptedAnimWeb");
    call.entities[0] = entity;
    call.integers[0] = flags;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_MoveToScenePoint@idAI2@@QAA?AVeventVoid@@PBVidEntity@@W4moveToScenePointFlags_t@@@Z
// EA: 0x82A2DAA8, RVA: 0x00A2DAA8
eventVoid idAI2::Action_MoveToScenePoint(
        const idEntity* const scenePoint,
        const moveToScenePointFlags_t flags) {
    idAI2ActionCall call(AI2_ACTION_MOVE_TO_SCENE_POINT,
        "Action_MoveToScenePoint");
    call.entities[0] = scenePoint;
    call.integers[0] = static_cast<int>(flags);
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ReloadWeapon@idAI2@@QAA?AVeventVoid@@W4equipSlot_t@@PBD@Z
// EA: 0x82A2DB50, RVA: 0x00A2DB50
eventVoid idAI2::Action_ReloadWeapon(const equipSlot_t slot,
        const char* const ammoType) {
    idAI2ActionCall call(AI2_ACTION_RELOAD_WEAPON,
        "Action_ReloadWeapon");
    call.integers[0] = static_cast<int>(slot);
    call.strings[0] = ammoType;
    return DispatchAction(*this, call);
}

// Retail symbol: ?Action_ReloadWeaponTorso@idAI2@@QAA?AVeventVoid@@W4equipSlot_t@@PBD@Z
// EA: 0x82A2DC90, RVA: 0x00A2DC90
eventVoid idAI2::Action_ReloadWeaponTorso(const equipSlot_t slot,
        const char* const ammoType) {
    idAI2ActionCall call(AI2_ACTION_RELOAD_WEAPON_TORSO,
        "Action_ReloadWeaponTorso");
    call.integers[0] = static_cast<int>(slot);
    call.strings[0] = ammoType;
    return DispatchAction(*this, call);
}

#undef AI2_ACTION_NO_ARGS
