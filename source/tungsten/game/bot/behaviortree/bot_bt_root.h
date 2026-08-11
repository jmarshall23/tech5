#pragma once

#include "bot_bt_highlevel.h"

class idBotRootServices {
public:
    virtual ~idBotRootServices() = default;
    virtual float GetHealth(const idBot&) const = 0;
    virtual unsigned int RandomPercent() = 0;
    virtual void SetUserCommandButtons(idBot&, unsigned int buttons) = 0;
};

void Tungsten_SetBotRootServices(idBotRootServices* services);

class idBotBehaviorHighLevel : public idBehaviorSelectorLooping {
public:
    idBotBehaviorHighLevel();
    void Init(idBot*, int currentTime) override;
    const char* GetClassName() const override {
        return "idBotBehaviorHighLevel";
    }
};

class idBotBehaviorLowLevel : public idBehaviorParallel {
public:
    idBotBehaviorLowLevel();
    const char* GetClassName() const override { return "idBotBehaviorLowLevel"; }
};

class idBotBehaviorMain : public idBehaviorParallel {
public:
    idBotBehaviorMain();
    void Init(idBot*, int currentTime) override;
    behaviorPriority_t GetPriority(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorMain"; }
};

class idBotBehaviorDead : public idBehaviorAction {
public:
    idBotBehaviorDead();
    behaviorPriority_t GetPriority(idBot*, int currentTime) override;
    void Enter(idBot*, int currentTime) override;
    behaviorStatus_t Think(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorDead"; }
    float GetTauntTime() const { return tauntTime; }
private:
    float tauntTime;
};

class idBotBehaviorRoot : public idBehaviorSelector {
public:
    idBotBehaviorRoot();
    void Init(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorRoot"; }
};
