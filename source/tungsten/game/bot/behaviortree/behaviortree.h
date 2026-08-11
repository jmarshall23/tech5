#pragma once

#include "../bot_movecmd.h"
#include "../../../../shared/idlib/text/str.h"

#include <cstdint>
#include <vector>

class idBot;
class idGuiListBox;
class idTypeInfo;

enum behaviorPriority_t : int {
    BEHAVIOR_PRIORITY_NULL = 0,
    BEHAVIOR_PRIORITY_LOW = 1,
    BEHAVIOR_PRIORITY_NORMAL = 2,
    BEHAVIOR_PRIORITY_HIGH = 3
};

enum behaviorStatus_t : int {
    BEHAVIOR_STATUS_ERROR = -1,
    BEHAVIOR_STATUS_FINISHED = 0,
    BEHAVIOR_STATUS_RUNNING = 1,
    BEHAVIOR_STATUS_FAILURE = BEHAVIOR_STATUS_ERROR,
    BEHAVIOR_STATUS_SUCCESS = BEHAVIOR_STATUS_FINISHED
};

enum behaviorStateFlag_t : int {
    BEHAVIOR_STATE_ACTIVE = 0x01,
    BEHAVIOR_STATE_NON_INTERRUPTIBLE = 0x02,
    BEHAVIOR_STATE_NON_INTERRUPTIBLE_ALT = 0x04,
    BEHAVIOR_STATE_ENABLED = 0x08,
    BEHAVIOR_STATE_ERROR = 0x10,
    BEHAVIOR_STATE_SEQUENCE_COMPLETE = 0x20
};

struct idBehaviorStateEvent {
    int type = 0;
};

class idBehaviorState;

class idBehaviorTreeServices {
public:
    virtual ~idBehaviorTreeServices() = default;
    virtual int GetScaledGameTime() const = 0;
    virtual bool SupportsGoalType(const idBot&, int goalFlags) const = 0;
    virtual int RandomInt(int minimum, int maximum) = 0;
    virtual void AddDebugRow(idGuiListBox&, int indent,
        const char* className, const char* debugText,
        bool usable, bool active) = 0;
};

void Tungsten_SetBehaviorTreeServices(idBehaviorTreeServices* services);

class idBehaviorState {
public:
    idBehaviorState();
    virtual ~idBehaviorState() = default;

    virtual idTypeInfo* GetType() const { return nullptr; }
    virtual const char* GetClassName() const { return "idBehaviorState"; }
    virtual void Init(idBot*, int) {}
    virtual behaviorPriority_t GetPriority(idBot*, int) {
        return BEHAVIOR_PRIORITY_NORMAL;
    }
    virtual void Enter(idBot*, int) {}
    virtual void Exit(idBot*, int) {}
    virtual behaviorStatus_t Think(idBot*, int) {
        return BEHAVIOR_STATUS_RUNNING;
    }
    virtual void ProcessEvent(idBot*, int, const idBehaviorStateEvent*) {}
    virtual void DebugRenderGui(const idBot*, idGuiListBox*, int);
    virtual void GetDebugString(idStr&) const;
    virtual idBehaviorState* FindState(const idTypeInfo& type);
    virtual int GetStateIndex(const idBehaviorState*) const { return -1; }
    virtual bool IsInterruptable() const;

    virtual void InternalInit(idBot*, int);
    virtual void InternalEnter(idBot*, int);
    virtual void InternalExit(idBot*, int);
    virtual behaviorStatus_t InternalThink(idBot*, int);
    virtual void InternalProcessEvent(idBot*, int,
        const idBehaviorStateEvent*);
    virtual behaviorPriority_t InternalGetPriority(idBot*, int);

    bool CheckStateFlag(int flag) const;
    bool IsUseAble(const idBot*) const;
    bool IsActive() const { return CheckStateFlag(BEHAVIOR_STATE_ACTIVE); }

    void SetEnabled(bool enabled);
    void SetStateFlags(int flags) { stateFlags = flags; }
    int GetStateFlags() const { return stateFlags; }
    void SetGoalTypeFlags(int flags) { stateGoalTypeFlags = flags; }
    void SetStateUpdateDelay(int delay) { stateUpdateDelay = delay; }
    void SetUseCooldowns(int normal, int failed) {
        stateUseCooldownTime = normal;
        stateFailedUseCooldownTime = failed;
    }
    int GetStateStartTime() const { return stateStartTime; }
    int GetNextStateUseTime() const { return nextStateUseTime; }
    behaviorPriority_t GetCachedPriority() const { return lastPriority; }

protected:
    int stateStartTime;
    int stateFlags;
    int nextStateUseTime;
    int lastPriorityUpdateTime;
    int lastStateUpdateTime;
    int stateUpdateDelay;
    int stateUseCooldownTime;
    int stateFailedUseCooldownTime;
    int lastStateRunTime;
    behaviorPriority_t lastPriority;
    int stateGoalTypeFlags;
};

class idBehaviorAction : public idBehaviorState {
public:
    idBehaviorAction();
    ~idBehaviorAction() override;
    const char* GetClassName() const override { return "idBehaviorAction"; }

    virtual void MoveGoal_Started_CallBack(idBot*, int) {}
    virtual void MoveGoal_Reached_CallBack(idBot*, int) {}
    virtual void MoveGoal_Errored_CallBack(idBot*, int, botMoveStatus_t) {}
    virtual void MoveSubGoal_Started_CallBack(idBot*, int) {}
    virtual void MoveSubGoal_Reached_CallBack(idBot*, int) {}
    virtual void MoveSubGoal_Errored_CallBack(idBot*, int,
        botMoveStatus_t) {}
};

class idBehaviorComposite : public idBehaviorState {
public:
    idBehaviorComposite();
    ~idBehaviorComposite() override;
    const char* GetClassName() const override { return "idBehaviorComposite"; }

    idBehaviorState* FindState(const idTypeInfo& type) override;
    int GetStateIndex(const idBehaviorState* state) const override;
    bool IsInterruptable() const override;
    bool HasActiveChildren() const;
    void InternalInit(idBot*, int) override;
    void InternalProcessEvent(idBot*, int,
        const idBehaviorStateEvent*) override;
    void InternalExit(idBot*, int) override;
    void DebugRenderGui(const idBot*, idGuiListBox*, int) override;
    void AppendState(class idBehaviorTree* rootTree,
        idBehaviorState* newState);

    int NumChildren() const { return static_cast<int>(children.size()); }
    idBehaviorState* Child(int index) const;

protected:
    std::vector<idBehaviorState*> children;
};

class idBehaviorDecorator : public idBehaviorState {
public:
    idBehaviorDecorator();
    const char* GetClassName() const override { return "idBehaviorDecorator"; }
    void InternalInit(idBot*, int) override;
    behaviorStatus_t InternalThink(idBot*, int) override;
    void InternalProcessEvent(idBot*, int,
        const idBehaviorStateEvent*) override;
    void InternalExit(idBot*, int) override;
    void DebugRenderGui(const idBot*, idGuiListBox*, int) override;
    void SetChild(idBehaviorState* value) { child = value; }
    idBehaviorState* GetChild() const { return child; }
protected:
    idBehaviorState* child;
};

class idBehaviorParallel : public idBehaviorComposite {
public:
    idBehaviorParallel();
    const char* GetClassName() const override { return "idBehaviorParallel"; }
    void GetDebugString(idStr&) const override;
    behaviorPriority_t InternalGetPriority(idBot*, int) override;
    behaviorStatus_t InternalThink(idBot*, int) override;
};

class idBehaviorParallelUntilFail : public idBehaviorParallel {
public:
    idBehaviorParallelUntilFail();
    const char* GetClassName() const override {
        return "idBehaviorParallelUntilFail";
    }
    behaviorStatus_t InternalThink(idBot*, int) override;
};

class idBehaviorSelector : public idBehaviorComposite {
public:
    idBehaviorSelector();
    ~idBehaviorSelector() override;
    const char* GetClassName() const override { return "idBehaviorSelector"; }
    void GetDebugString(idStr&) const override;
    void InternalEnter(idBot*, int) override;
    void InternalExit(idBot*, int) override;
    behaviorPriority_t InternalGetPriority(idBot*, int) override;
    behaviorStatus_t InternalThink(idBot*, int) override;
    idBehaviorState* GetCurrentState() const { return currentState; }
protected:
    idBehaviorState* currentState;
};

class idBehaviorSelectorLooping : public idBehaviorSelector {
public:
    idBehaviorSelectorLooping();
    const char* GetClassName() const override {
        return "idBehaviorSelectorLooping";
    }
    behaviorPriority_t InternalGetPriority(idBot*, int) override;
    behaviorStatus_t InternalThink(idBot*, int) override;
};

class idBehaviorSelectorBest : public idBehaviorSelector {
public:
    idBehaviorSelectorBest();
    const char* GetClassName() const override {
        return "idBehaviorSelectorBest";
    }
    behaviorPriority_t InternalGetPriority(idBot*, int) override;
};

class idBehaviorSelectorBestLooping : public idBehaviorSelectorBest {
public:
    idBehaviorSelectorBestLooping();
    const char* GetClassName() const override {
        return "idBehaviorSelectorBestLooping";
    }
    behaviorStatus_t InternalThink(idBot*, int) override;
};

class idBehaviorSelectorRandom : public idBehaviorSelector {
public:
    idBehaviorSelectorRandom();
    const char* GetClassName() const override {
        return "idBehaviorSelectorRandom";
    }
    behaviorPriority_t InternalGetPriority(idBot*, int) override;
};

class idBehaviorSequence : public idBehaviorComposite {
public:
    idBehaviorSequence();
    ~idBehaviorSequence() override;
    const char* GetClassName() const override { return "idBehaviorSequence"; }
    void GetDebugString(idStr&) const override;
    void InternalEnter(idBot*, int) override;
    void InternalExit(idBot*, int) override;
    behaviorPriority_t InternalGetPriority(idBot*, int) override;
    behaviorStatus_t InternalThink(idBot*, int) override;
    idBehaviorState* GetCurrentState() const { return currentState; }
    int GetCurrentStateIndex() const { return currentStateIndex; }
protected:
    int currentStateIndex;
    idBehaviorState* currentState;
};

class idBehaviorSequenceRandom : public idBehaviorSequence {
public:
    idBehaviorSequenceRandom();
    ~idBehaviorSequenceRandom() override;
    const char* GetClassName() const override {
        return "idBehaviorSequenceRandom";
    }
    behaviorPriority_t InternalGetPriority(idBot*, int) override;
    behaviorStatus_t InternalThink(idBot*, int) override;
    void InternalExit(idBot*, int) override;
    void ResetRunChildren();
private:
    std::vector<int> runChildren;
};

class idBehaviorTree : public idBehaviorParallel {
public:
    idBehaviorTree();
    ~idBehaviorTree() override;
    const char* GetClassName() const override { return "idBehaviorTree"; }
    void RootInit(idBot*, int);
    void RootThink(idBot*, int);
    int GetFramesWithNoActiveChildren() const {
        return numFramesWithNoActiveChildren;
    }
private:
    int numFramesWithNoActiveChildren;
};

class idBotBehaviorTree : public idBehaviorTree {
public:
    idBotBehaviorTree();
    void Init(idBot*, int currentTime) override;
    const char* GetClassName() const override { return "idBotBehaviorTree"; }
};

class idBehaviorTemp : public idBehaviorAction {
public:
    const char* GetClassName() const override { return "idBehaviorTemp"; }
};
