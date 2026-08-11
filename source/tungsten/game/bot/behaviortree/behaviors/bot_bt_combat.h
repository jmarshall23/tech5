#pragma once

#include "../behaviortree.h"

enum idBotCombatBehaviorKind : int {
    BOT_COMBAT_TARGET_VISIBLE,
    BOT_COMBAT_CLOSE_RANGE,
    BOT_COMBAT_CLOSE_MELEE,
    BOT_COMBAT_CLOSE_SMG,
    BOT_COMBAT_CLOSE_SHOTGUN,
    BOT_COMBAT_CLOSE_THROWN,
    BOT_COMBAT_CLOSE_SNIPER,
    BOT_COMBAT_LONG_RANGE,
    BOT_COMBAT_NON_VISIBLE
};

enum idBotCombatWeaponCategory : int {
    BOT_WEAPON_CATEGORY_UNKNOWN,
    BOT_WEAPON_CATEGORY_MELEE,
    BOT_WEAPON_CATEGORY_SMG,
    BOT_WEAPON_CATEGORY_SHOTGUN,
    BOT_WEAPON_CATEGORY_THROWN,
    BOT_WEAPON_CATEGORY_SNIPER
};

class idBotCombatServices {
public:
    virtual ~idBotCombatServices() = default;
    virtual int GetTargetLastVisibleTime(const idBot&) const = 0;
    virtual float GetTargetDistance(const idBot&) const = 0;
    virtual idBotCombatWeaponCategory GetWeaponCategory(
        const idBot&) const = 0;
    virtual void InitializeBehavior(idBotCombatBehaviorKind,
        idBot&, int currentTime) = 0;
    virtual void AddWeaponRequest(idBotCombatBehaviorKind, idBot&) = 0;
    virtual void AddAimRequest(idBotCombatBehaviorKind, idBot&) = 0;
    virtual void TouchNonVisibleTargetRecord(idBot&) = 0;
};

void Tungsten_SetBotCombatServices(idBotCombatServices* services);

class idBotBehaviorCombat_TargetVis : public idBehaviorSelectorLooping {
public:
    idBotBehaviorCombat_TargetVis();
    void Init(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis";
    }
};

class idBotBehaviorCombat_TargetVis_CloseRange
    : public idBehaviorSelectorLooping {
public:
    idBotBehaviorCombat_TargetVis_CloseRange();
    void Init(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis_CloseRange";
    }
};

class idBotBehaviorCombat_TargetVis_CloseRange_Melee
    : public idBehaviorSelectorRandom {
public:
    idBotBehaviorCombat_TargetVis_CloseRange_Melee();
    void Init(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis_CloseRange_Melee";
    }
};

class idBotBehaviorCombat_TargetVis_CloseRange_SMG
    : public idBehaviorSelectorRandom {
public:
    idBotBehaviorCombat_TargetVis_CloseRange_SMG();
    void Init(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis_CloseRange_SMG";
    }
};

class idBotBehaviorCombat_TargetVis_CloseRange_Shotgun
    : public idBehaviorSelectorRandom {
public:
    idBotBehaviorCombat_TargetVis_CloseRange_Shotgun();
    void Init(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis_CloseRange_Shotgun";
    }
};

class idBotBehaviorCombat_TargetVis_CloseRange_Thrown
    : public idBehaviorSelectorRandom {
public:
    idBotBehaviorCombat_TargetVis_CloseRange_Thrown();
    void Init(idBot* bot, int currentTime) override;
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis_CloseRange_Thrown";
    }
};

class idBotBehaviorCombat_TargetVis_CloseRange_Sniper
    : public idBehaviorSelectorRandom {
public:
    idBotBehaviorCombat_TargetVis_CloseRange_Sniper();
    void Init(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis_CloseRange_Sniper";
    }
};

class idBotBehaviorCombat_TargetVis_LongRange
    : public idBehaviorSelectorLooping {
public:
    idBotBehaviorCombat_TargetVis_LongRange();
    void Init(idBot* bot, int currentTime) override;
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    behaviorStatus_t Think(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_TargetVis_LongRange";
    }
};

class idBotBehaviorCombat_NonVisTarget : public idBehaviorSelector {
public:
    idBotBehaviorCombat_NonVisTarget();
    behaviorPriority_t GetPriority(idBot* bot, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorCombat_NonVisTarget";
    }
};
