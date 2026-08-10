#pragma once

#include "aianimwebtransitions_core.h"
#include "../aimoveparms.h"

class idAI2;

enum aiAnimWeb_t : int {
    AIANIMWEB_BODY = 0,
    AIANIMWEB_MAX = 1
};

enum walkState_t : int {
    WALKSTATE_NOCLIP = 0,
    WALKSTATE_WALKING = 1,
    WALKSTATE_RUNNING = 2,
    WALKSTATE_SPRINTING = 3,
    WALKSTATE_MAX = 4
};

enum equipSlot_t : int {
    EQUIP_NONE = 0,
    EQUIP_LEFT_HAND = 1,
    EQUIP_RIGHT_HAND = 2,
    EQUIP_HEAD = 3,
    EQUIP_TORSO = 4,
    EQUIP_HOLSTER_HIP_LEFT = 5,
    EQUIP_HOLSTER_HIP_RIGHT = 6,
    EQUIP_HOLSTER_BACK = 7,
    EQUIP_HOLSTER_SHOULDER = 8,
    EQUIP_HOLSTER_BELT_LEFT = 9,
    EQUIP_HOLSTER_BELT_RIGHT = 10,
    EQUIP_HOLSTER_BELT_BACK = 11,
    EQUIP_HOLSTER_BELT_FRONT = 12,
    EQUIP_VEHICLE = 13,
    EQUIP_VEHICLE_RAM = 14,
    EQUIP_MAX = 15
};

enum aiSubWeb_t : int {
    AISUBWEB_RELAXED = 0,
    AISUBWEB_COMBAT = 1,
    AISUBWEB_HOSTILE = 2,
    AISUBWEB_SEARCH = 3,
    AISUBWEB_PAIN = 4,
    AISUBWEB_PAIN_STAGGER = 5,
    AISUBWEB_PAIN_MOVING = 6,
    AISUBWEB_PAIN_SHOCK = 7,
    AISUBWEB_DYING = 8,
    AISUBWEB_ACTIONSCRIPT = 9,
    AISUBWEB_FCOVER = 10,
    AISUBWEB_MELEE = 11,
    AISUBWEB_SURPRISE = 12,
    AISUBWEB_DIVE = 13,
    AISUBWEB_DODGE = 14,
    AISUBWEB_GRENADE = 15,
    AISUBWEB_THROW = 16,
    AISUBWEB_OVERRIDE = 17,
    AISUBWEB_TURRET = 18,
    AISUBWEB_RCCONTROL = 19,
    AISUBWEB_TRAVERSAL = 20,
    AISUBWEB_ZIPLINE = 21,
    AISUBWEB_DROPSHIP_FALL = 22,
    AISUBWEB_MAX = 23
};

class idAIAnimWebState : public idAnimWebState {
public:
    idAIAnimWebState() = default;
    idAIAnimWebState(const idAI2* ai,
        const char* subWebName, const char* stateName);
    idAIAnimWebState(const idAI2* ai,
        aiSubWeb_t subWeb, const char* stateName);
    ~idAIAnimWebState() = default;

    virtual void GetMoveStateString(const idAI2* ai,
        idStr& moveState, posture_t overridePosture);
    virtual void GetTurnStateString(
        const idAI2* ai, idStr& turnState);

    bool VerifyFloorTrace(const idAI2* ai);
    bool VerifyPointOutsideAnimRange(
        const idAI2* ai, const idVec3& point);
    static void GetSubwebString(const idAI2* ai, idStr& output,
        aiSubWeb_t subWeb, posture_t posture,
        equipSlot_t weaponSlot);
};

class idAIAnimWebState_Transition : public idAIAnimWebState {
public:
    idAIAnimWebState_Transition(const idAI2* ai,
        idAnimWebTransitions::transitionQueryResult_t& result,
        bool skipTrace, bool skipVerifyPointOutsideAnimRange);
};

class idAIAnimWebState_Current : public idAIAnimWebState {
public:
    explicit idAIAnimWebState_Current(const idAI2* ai);
};

class idAIAnimWebState_Target : public idAIAnimWebState {
public:
    explicit idAIAnimWebState_Target(const idAI2* ai);
};

class idAIAnimWebState_Idle : public idAIAnimWebState {
public:
    idAIAnimWebState_Idle(const idAI2* ai,
        aiSubWeb_t subWeb = AISUBWEB_MAX,
        posture_t posture = POSTURE_MAX,
        equipSlot_t weaponSlot = EQUIP_MAX);
};

class idAIAnimWebState_Movement : public idAIAnimWebState {
public:
    idAIAnimWebState_Movement(const idAI2* ai,
        const char* postfix = nullptr,
        aiSubWeb_t subWeb = AISUBWEB_MAX,
        posture_t posture = POSTURE_MAX);
};

const idDeclAnimWeb* Tungsten_GetAIAnimWebDeclaration(const idAI2& ai);
walkState_t Tungsten_GetAIWalkState(const idAI2& ai);
const char* Tungsten_GetAIWalkStateName(walkState_t walkState);
int Tungsten_GetAICurrentTurnDirection(const idAI2& ai);
bool Tungsten_GetAIAnimModelAxis(const idAI2& ai, idMat3& axis);
bool Tungsten_GetAIAnimOrigin(const idAI2& ai, idVec3& origin);
bool Tungsten_GetAIAnimNextMovePoint(const idAI2& ai, idVec3& point);
bool Tungsten_IsAIAnimLineInNavGraph(const idAI2& ai,
    const idVec3& start, const idVec3& end);
const char* Tungsten_GetAIResolvedSubWebName(
    const idAI2& ai, const char* requestedName);
short Tungsten_GetAIAnimCurrentNode(const idAI2& ai);
short Tungsten_GetAIAnimTargetNode(const idAI2& ai);
aiSubWeb_t Tungsten_GetAIAnimationSubWeb(const idAI2& ai);
aiSubWeb_t Tungsten_AIAlertCycleToSubWeb(
    const idAI2& ai, int alertCycle);
posture_t Tungsten_GetAIPosture(const idAI2& ai);
const char* Tungsten_GetAISubWebName(aiSubWeb_t subWeb);
const char* Tungsten_GetAIAnimWeaponPrefix(
    const idAI2& ai, equipSlot_t weaponSlot);
const char* Tungsten_GetAIIdleStateName(const idAI2& ai);
