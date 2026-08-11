#pragma once

#include "game/ai/aiactionscript.h"

#include <cstdint>
#include <string>
#include <vector>

class idEntity;
class idEventDef;

enum timelineEventArgType_t {
    TIMELINE_ARG_NONE,
    TIMELINE_ARG_INTEGER,
    TIMELINE_ARG_BOOLEAN,
    TIMELINE_ARG_FLOAT,
    TIMELINE_ARG_VECTOR,
    TIMELINE_ARG_ANGLES,
    TIMELINE_ARG_STRING,
    TIMELINE_ARG_ATOMIC_STRING,
    TIMELINE_ARG_ENTITY,
    TIMELINE_ARG_DECL
};

enum timelineEventBehavior_t : std::uint32_t {
    TIMELINE_EVENT_NORMAL = 0,
    TIMELINE_EVENT_ACTION = 1u << 0,
    TIMELINE_EVENT_MOVE_DEFAULT = 1u << 1,
    TIMELINE_EVENT_START_ANIM_DEFAULTS = 1u << 2,
    TIMELINE_EVENT_IDLE_DEFAULTS = 1u << 3,
    TIMELINE_EVENT_PLAYER_FOCUS_DEFAULTS = 1u << 4,
    TIMELINE_EVENT_TRIGGER = 1u << 5
};

struct idTimelineEventArg {
    timelineEventArgType_t type{TIMELINE_ARG_NONE};
    int integer{0};
    float scalar{0.0f};
    idVec3 vector{idVec3(0.0f, 0.0f, 0.0f)};
    std::string string;
    std::uint32_t spawnId{0x1FFFu};
    const void* declaration{nullptr};

    static idTimelineEventArg Integer(int value);
    static idTimelineEventArg Boolean(bool value);
    static idTimelineEventArg Float(float value);
    static idTimelineEventArg Vector(const idVec3& value);
    static idTimelineEventArg Angles(const idVec3& value);
    static idTimelineEventArg String(const std::string& value,
        bool atomic = false);
    static idTimelineEventArg Entity(std::uint32_t value);
    static idTimelineEventArg Decl(const void* value);
};

struct idTimelineEventCall {
    int eventNumber{-1};
    std::vector<idTimelineEventArg> arguments;
};

class idComponentTimeLineServices {
public:
    virtual ~idComponentTimeLineServices() = default;

    virtual int GetGameTime() const = 0;
    virtual std::uint32_t GetSpawnId(const idEntity* entity) const = 0;
    virtual idEntity* ResolveEntity(std::uint32_t spawnId) const = 0;
    virtual const char* GetEntityName(const idEntity* entity) const = 0;
    virtual const idEventDef* FindEvent(const char* name) const = 0;
    virtual const idEventDef* FindEvent(int eventNumber) const = 0;
    virtual int GetEventNumber(const idEventDef& event) const = 0;
    virtual const char* GetEventName(const idEventDef& event) const = 0;
    virtual int GetEventArgumentCount(const idEventDef& event) const = 0;
    virtual timelineEventArgType_t GetEventArgumentType(
        const idEventDef& event, int argumentIndex) const = 0;
    virtual std::uint32_t GetEventBehavior(const idEventDef& event) const = 0;
    virtual std::string GetActionEventName(const std::string& name) const = 0;
    virtual bool EntityRespondsTo(const idEntity* entity,
        const idEventDef& event) const = 0;
    virtual void ProcessEntityEvent(idEntity* entity,
        const idEventDef& event,
        const std::vector<idTimelineEventArg>& arguments) = 0;
    virtual void ProcessActionEvent(idEntity* entity,
        const idEventDef& event,
        const std::vector<idTimelineEventArg>& arguments) = 0;
    virtual bool IsActionWorking(const idEntity* entity) const = 0;
    virtual void ResetAction(idEntity* entity, int gameTime) = 0;
    virtual void ActionScriptFinished(idEntity* entity, int gameTime) = 0;
    virtual idEntity* ResolveEntityName(const std::string& name,
        idEntity* scriptExecutor, idEntity* activator,
        std::string& failureReason) const = 0;
    virtual void SetUnresolvedEntityName(std::uint32_t spawnId,
        const std::string& name) = 0;
    virtual void Warning(const std::string& message) = 0;
    virtual void Error(const std::string& message) = 0;
};

void Tungsten_SetComponentTimeLineServices(
    idComponentTimeLineServices* services);
idComponentTimeLineServices& Tungsten_ComponentTimeLineServices();

class idComponentTimeLine {
public:
    struct idTimeLineEvent {
        idTimeLineEvent();

        int eventTime;
        idTimelineEventCall eventCall;
    };

    struct idTimeLineEntity {
        idTimeLineEntity();

        std::uint32_t spawnId;
        std::vector<idTimeLineEvent> events;
    };

    idComponentTimeLine();
    virtual ~idComponentTimeLine();

    void Init();
    void Start();
    void Update();

    std::vector<idTimeLineEntity>& Timelines() { return entityEvents; }
    const std::vector<idTimeLineEntity>& Timelines() const {
        return entityEvents;
    }
    int GetStartTime() const { return startTime; }

protected:
    virtual int GetRelativeTime(int timelineIndex) const;
    virtual void ProcessTimelineEvent(idEntity* entity,
        const idEventDef& event,
        const std::vector<idTimelineEventArg>& arguments) const;
    virtual bool IsTimelineComplete(int timelineIndex) const;
    virtual void ResetTimeline(int timelineIndex);
    virtual void OnTimelineCompletion(int timelineIndex);

    std::vector<idTimeLineEntity> entityEvents;
    std::vector<int> nextEventIndices;
    int startTime;
};

class idComponentActionScript : public idComponentTimeLine {
public:
    idComponentActionScript();
    ~idComponentActionScript() override;

    int GetTimelineIndex(const idEntity* entity) const;
    bool RunningActionScript(const idEntity* entity) const;
    void ClearActionScript(const idEntity* entity);
    int NumScriptActions(const idEntity* entity) const;
    void SetActionScript(idEntity* entity, const aiActionScript_t& script,
        idEntity* scriptExecutor, idEntity* activator, bool tool);

protected:
    int GetRelativeTime(int timelineIndex) const override;
    void ProcessTimelineEvent(idEntity* entity,
        const idEventDef& event,
        const std::vector<idTimelineEventArg>& arguments) const override;
    bool IsTimelineComplete(int timelineIndex) const override;
    void ResetTimeline(int timelineIndex) override;
    void OnTimelineCompletion(int timelineIndex) override;
};

// The original symbol is the compiler-generated cleanup landing pad for the
// invalid-entity branch of SetActionScript. RAII makes it empty on this port.
void Tungsten_TimelineInvalidEntityCleanup();
