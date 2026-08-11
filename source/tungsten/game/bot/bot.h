#pragma once

#include "bot_goals.h"
#include "global/bot_debug.h"
#include "../../../shared/idlib/math/vector.h"

#include <cstdint>

class idBotAimState;
class idBotBehaviorTree;
class idBotMoveState;
class idBotWeaponState;
class idBotWorldState;
class idDeclBot;
class idEntity;
class idGuiListBox;
class idPlayer;

struct idBotUserCommand {
    unsigned int buttons;
    unsigned int buttons2;
    signed char forwardmove;
    signed char rightmove;
    signed char upmove;
    unsigned char commandFlags;
    float pos[3];
    short angles[3];
    int clientGameFrame;
    short yaw;
    short pitch;
    short roll;
    unsigned int predictionStateBits;
    signed char vehicleThrottle;
    int serverGameTime;
    int fireCount;
    short fireAngles[2];
    int firePos[3];
    float speed;
};

class idBot;

class idBotServices {
public:
    virtual ~idBotServices() = default;
    virtual bool BotSystemsInitialized() const = 0;
    virtual void ReportBotSystemsNotInitialized() = 0;
    virtual int GetScaledGameTime() const = 0;
    virtual int GetServerGameTime() const = 0;
    virtual bool IsOwnerDead(const idBot&) const = 0;
    virtual const char* GetDebugName(const idBot&) const = 0;

    virtual idBotAimState* CreateAimState(idBot&) = 0;
    virtual idBotWorldState* CreateWorldState(idBot&) = 0;
    virtual idBotMoveState* CreateMoveState(idBot&) = 0;
    virtual idBotWeaponState* CreateWeaponState(idBot&) = 0;
    virtual void DestroyAimState(idBotAimState*) = 0;
    virtual void DestroyWorldState(idBotWorldState*) = 0;
    virtual void DestroyMoveState(idBotMoveState*) = 0;
    virtual void DestroyWeaponState(idBotWeaponState*) = 0;

    virtual void ResetGoal(idBot&) = 0;
    virtual void ClearWorldVolatileData(idBot&) = 0;
    virtual void RecordDamage(idBot&, const idEntity*, int currentTime) = 0;
    virtual idAngles GetDesiredViewAngles(const idBot&) const = 0;
    virtual idAngles GetOwnerViewAngles(const idBot&) const = 0;
    virtual void ProjectTopDown(const idBot&, idVec3& point) const = 0;

    virtual bool WeaponsAllowed() const = 0;
    virtual bool HasValidGoalEnemy(const idBot&) const = 0;
    virtual unsigned int GetGoalEnemyTargetFlags(const idBot&) const = 0;
    virtual float GetGoalEnemyDot(const idBot&) const = 0;
    virtual float GetGoalEnemyHealth(const idBot&) const = 0;
    virtual unsigned int RandomPercent() = 0;

    virtual void RunDebugChecks(idBot&) = 0;
    virtual void UpdateBotDebugHud(const idBot&, idGuiListBox&) const = 0;
    virtual void RenderWorldInfo(const idBot&, idGuiListBox&) const = 0;
    virtual void UpdateWorldState(idBot&) = 0;
    virtual int GetGoalEnemyRecordIndex(const idBot&) const = 0;
    virtual void UpdateAimState(idBot&) = 0;
    virtual void UpdateWeaponState(idBot&) = 0;
    virtual void UpdateMoveState(idBot&) = 0;
    virtual void UpdateMoveCommands(idBot&, idBotUserCommand&) = 0;
    virtual void PostUpdateAimState(idBot&) = 0;
    virtual bool IsBotThinkingPaused() const = 0;
    virtual void SubmitUserCommand(const idBot&, const idBotUserCommand&) = 0;
};

void Tungsten_SetBotServices(idBotServices* services);

class idBot {
public:
    idBot(idPlayer* newOwner, const idDeclBot* botDef);
    virtual ~idBot();

    void OnDeath(const idEntity* killer);
    void OnTakeDamage(const idEntity* attacker);
    void SetupUcmdsForNewFrame();
    void HandleViewCmds();
    void InitBehaviorTree();
    void InitWeaponState();
    void InitWorldState();
    void InitMoveState();
    void InitAimState();
    void ProjectTopDown(idVec3& point) const;
    void HACK_CHECK_ATTACK_FUNC_NEEDS_REMOVED();
    void RunDebugChecks();
    void UpdateBotDebugHud(idGuiListBox& infoList) const;
    void UpdateBotGUI(idGuiListBox& infoList,
        botDebugGuiType_t debugType) const;
    void UpdateUcmd();
    void UpdateBehaviorTree();
    void UpdateWorldState();
    void UpdateAimState();
    void UpdateWeaponState();
    void UpdateMoveState();
    void Think();

    bool isControllingAFKPlayer;
    const char* debugName;
    idBotBehaviorTree* behaviorTree;
    idBotAimState* aimState;
    idBotWorldState* worldState;
    idBotMoveState* moveState;
    idBotWeaponState* weaponState;
    const idDeclBot* behaviorDef;
    idPlayer* owner;
    idBotGoal goalTask;
    idBotUserCommand usercmd;
};
