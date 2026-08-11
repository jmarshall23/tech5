#pragma once

#include "behaviortree.h"

class idBotHighLevelServices {
public:
    virtual ~idBotHighLevelServices() = default;
    virtual bool HasValidEnemyTarget(const idBot&) const = 0;
    virtual float GetEnemyDistance(const idBot&) const = 0;
    virtual float GetCombatMaximumRange(const idBot&) const = 0;
};

void Tungsten_SetBotHighLevelServices(idBotHighLevelServices* services);

class idBotBehaviorCombat : public idBehaviorSelectorLooping {
public:
    idBotBehaviorCombat();
    void Init(idBot*, int currentTime) override;
    behaviorPriority_t GetPriority(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorCombat"; }
};

class idBotBehaviorAlert : public idBehaviorSelectorLooping {
public:
    idBotBehaviorAlert();
    void Init(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorAlert"; }
};

class idBotBehaviorBehave : public idBehaviorSelectorLooping {
public:
    idBotBehaviorBehave();
    void Init(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorBehave"; }
};

class idBotBehaviorReact : public idBehaviorSelectorLooping {
public:
    idBotBehaviorReact();
    void Init(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorReact"; }
};
