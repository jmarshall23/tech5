#pragma once

#include "idlib/math/vector.h"

#include <cstdint>

class idAnimWebPath;
class idDeclInventory;
class idDeclVoiceOver;
class idEntity;

#ifndef TUNGSTEN_EVENT_VOID_DEFINED
#define TUNGSTEN_EVENT_VOID_DEFINED
struct eventVoid {};
#endif

enum aiAccuracy_t : int;
enum aiActionBool_t : int;
enum aiActionScriptFlags_t : std::uint32_t;
enum aiAnimWait_t : int;
enum aiAnimWeb_t : int;
enum aiArrivalAction_t : int;
enum aiDirection_t : int;
enum aiFireMode_t : int;
enum aiIdleTurn_t : int;
enum aiMovementMode_t : int;
enum aiMovePushStatus_t : int;
enum aiPerceptionFlags_t : int;
enum aiPlayer_t : int;
enum aiSubWeb_t : int;
enum aiVarOp_t : int;
enum aiVarType_t : int;
enum aimPoint_t : int;
enum alertCycle_t : int;
enum coverAction_t : int;
enum equipSlot_t : int;
enum moveToScenePointFlags_t : int;
enum overrideAnim_t : int;
enum painType_t : int;
enum posture_t : int;
enum runIndexType_t : int;
enum sitState_t : int;
enum standState_t : int;
enum walkState_t : int;

enum idAI2ActionKind_t : int {
    AI2_ACTION_LEAP_ATTACK = 0,
    AI2_ACTION_MOVE_TO_POINT,
    AI2_ACTION_MOVE_TO_POINT_NO_FAIL,
    AI2_ACTION_MOVE_TO_ENTITY,
    AI2_ACTION_MOVE_TO_ENTITY_NO_FAIL,
    AI2_ACTION_MOVE_TO_PATH_POINT,
    AI2_ACTION_MOVE_TO_PATH_POINT_NO_FAIL,
    AI2_ACTION_MOVE_TO_COVER,
    AI2_ACTION_USE_ZIPLINE,
    AI2_ACTION_SET_MOVE_PUSH_STATUS,
    AI2_ACTION_IDLE,
    AI2_ACTION_PAIN,
    AI2_ACTION_STAND_TO_CROUCH,
    AI2_ACTION_CROUCH_TO_STAND,
    AI2_ACTION_PULL_TRIGGER_RIGHT,
    AI2_ACTION_RELEASE_TRIGGER_RIGHT,
    AI2_ACTION_PULL_TRIGGER_LEFT,
    AI2_ACTION_RELEASE_TRIGGER_LEFT,
    AI2_ACTION_WAIT_FOR_ANIM,
    AI2_ACTION_WAIT_FOR_ANIM_VIA,
    AI2_ACTION_LOOP_ANIM,
    AI2_ACTION_LOOP_ANIM_EXIT_AT_END,
    AI2_ACTION_START_ANIM,
    AI2_ACTION_WAIT_FOR_TRAVERSAL_ANIM,
    AI2_ACTION_CHANGE_ANIM_STATE,
    AI2_ACTION_CHANGE_ANIM_STATE_VIA,
    AI2_ACTION_FORCE_ANIM_STATE,
    AI2_ACTION_DODGE,
    AI2_ACTION_WAIT,
    AI2_ACTION_MELEE,
    AI2_ACTION_TURN_TO_POINT,
    AI2_ACTION_TURN_TO_ENTITY,
    AI2_ACTION_TURN_TO_ENTITY_WITH_OFFSET,
    AI2_ACTION_DIVE,
    AI2_ACTION_WAIT_FOR_ENTITY,
    AI2_ACTION_ENTER_VEHICLE,
    AI2_ACTION_PLAY_VOICE_OVER,
    AI2_ACTION_PLAY_INTERACTION_VOICE_OVER,
    AI2_ACTION_STOP_VOICE_OVER,
    AI2_ACTION_PLAY_OVERRIDE_ANIM,
    AI2_ACTION_PLAY_OVERRIDE_ANIM_INTERRUPT,
    AI2_ACTION_HOLSTER_WEAPON,
    AI2_ACTION_DRAW_WEAPON,
    AI2_ACTION_PERFORM_COVER_ACTION,
    AI2_ACTION_WAIT_FOR_PLAYER_INTERACTION,
    AI2_ACTION_WAIT_FOR_PLAYER_INTERACTION_DIST,
    AI2_ACTION_WAIT_FOR_AI_VAR,
    AI2_ACTION_SET_ALERT_CYCLE,
    AI2_ACTION_SET_SUB_WEB,
    AI2_ACTION_SET_FOCUS,
    AI2_ACTION_CLEAR_LOOK_FOCUS,
    AI2_ACTION_CLEAR_AIM_FOCUS,
    AI2_ACTION_SET_AIM_POINT,
    AI2_ACTION_SET_FIRE_MODE,
    AI2_ACTION_SET_SCRIPT_ABORT,
    AI2_ACTION_SET_POSTURE,
    AI2_ACTION_SET_WALK_STATE,
    AI2_ACTION_SET_SIT_STATE,
    AI2_ACTION_SET_STAND_STATE,
    AI2_ACTION_SET_IDLE_STATE,
    AI2_ACTION_IGNORE_PLAYER_APPROACH,
    AI2_ACTION_NOTICE_PLAYER_APPROACH,
    AI2_ACTION_GIVE_ITEM,
    AI2_ACTION_TAKE_ITEM,
    AI2_ACTION_SET_PLAYER_ENEMY,
    AI2_ACTION_SET_ENEMY,
    AI2_ACTION_SEARCH_TO_TARGET,
    AI2_ACTION_SET_PLAYER_FOCUS,
    AI2_ACTION_SET_ACTION_NODE_GROUP,
    AI2_ACTION_TRIGGER,
    AI2_ACTION_ENABLE_DAMAGE,
    AI2_ACTION_ENABLE_PAIN,
    AI2_ACTION_ENABLE_AUTO_FOCUS,
    AI2_ACTION_ENABLE_BODY_ROTATION,
    AI2_ACTION_ENABLE_WALK_IK,
    AI2_ACTION_ENABLE_HEAD_TRACKING,
    AI2_ACTION_FORCE_OPEN_COMBAT,
    AI2_ACTION_FORCE_AWARENESS_BY_DISTANCE,
    AI2_ACTION_FORCE_PLAYER_INTERACTION,
    AI2_ACTION_SET_AI_VAR,
    AI2_ACTION_SET_SCRIPT_FLAG,
    AI2_ACTION_CLEAR_SCRIPT_FLAG,
    AI2_ACTION_SET_PERCEPTION_FLAG,
    AI2_ACTION_CLEAR_PERCEPTION_FLAG,
    AI2_ACTION_CLEAR_WORLD_STATE,
    AI2_ACTION_SHOW_ATTACHMENT,
    AI2_ACTION_HIDE_ATTACHMENT,
    AI2_ACTION_DROP_ATTACHMENT,
    AI2_ACTION_SET_MOVE_MODE,
    AI2_ACTION_SET_ACCURACY,
    AI2_ACTION_SCRIPTED_ANIM_WEB,
    AI2_ACTION_MOVE_TO_SCENE_POINT,
    AI2_ACTION_RELOAD_WEAPON,
    AI2_ACTION_RELOAD_WEAPON_TORSO,
    AI2_ACTION_MAX
};

// Synchronous, non-owning argument envelope for the retail action-event
// forwarding layer. All pointed-to values remain valid for DispatchAIAction.
struct idAI2ActionCall {
    idAI2ActionKind_t kind;
    const char* actionName;
    const idEntity* entities[2];
    const void* objects[2];
    const idVec3* vectors[2];
    const idAnimWebPath* animWebPaths[2];
    const char* strings[2];
    int integers[4];
    float scalars[4];
    bool booleans[4];

    idAI2ActionCall(idAI2ActionKind_t kindValue,
            const char* actionNameValue)
        : kind(kindValue), actionName(actionNameValue), entities{},
          objects{}, vectors{}, animWebPaths{}, strings{}, integers{},
          scalars{}, booleans{} {
    }
};
