#pragma once

#include "../bot_goals.h"

#include <vector>

class idEntity;

class idBotGoalManagerServices : public idBotGoalServices {
public:
    virtual bool GetFollowPlayerSetting() const = 0;
    virtual idEntity* GetDebugPlayer() const = 0;
    virtual void GetBotEntities(std::vector<idEntity*>& entities) const = 0;
    virtual void GetPlayerEntities(std::vector<idEntity*>& entities) const = 0;
    virtual void GetActiveAI(std::vector<idEntity*>& entities) const = 0;
    virtual idBotGoal* GetBotGoal(idEntity& entity) const = 0;
    virtual const idEntity* ResolveEntitySpawnId(int spawnId) const = 0;
    virtual bool IsDead(const idEntity& entity) const = 0;
    virtual bool IsNoclip(const idEntity& entity) const = 0;
    virtual bool IsNoTarget(const idEntity& entity) const = 0;
    virtual bool IsExcludedTarget(const idEntity& entity) const = 0;
    virtual bool IsHostile(const idEntity& first,
        const idEntity& second) const = 0;
    virtual bool CanFollowDebugPlayer(const idEntity& bot,
        int currentTime) const = 0;
    virtual idVec3 GetEntityOrigin(const idEntity& entity) const = 0;
    virtual int RandomInt(int maximum) = 0;
};

void Tungsten_SetBotGoalManagerServices(
    idBotGoalManagerServices* services);

class idBotGoalManager {
public:
    idBotGoalManager() = default;
    virtual ~idBotGoalManager() = default;
    virtual void Think(int) {}
};

class idBotGoalManager_DM final : public idBotGoalManager {
public:
    idBotGoalManager_DM();
    void Think(int currentTime) override;
};

class idBotGoalManager_TDM final : public idBotGoalManager {
public:
    idBotGoalManager_TDM();
    void Think(int currentTime) override;
};

class idBotGoalManager_CTF final : public idBotGoalManager {
public:
    idBotGoalManager_CTF();
};

class idBotGoalManager_HORDE final : public idBotGoalManager {
public:
    idBotGoalManager_HORDE();
};

class idBotGoalManager_DOM final : public idBotGoalManager {
public:
    idBotGoalManager_DOM();
};
