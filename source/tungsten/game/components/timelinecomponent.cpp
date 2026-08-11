#include "game/components/timelinecomponent.h"

#include <algorithm>
#include <sstream>
#include <stdexcept>

namespace {

class MissingTimeLineServices final : public idComponentTimeLineServices {
public:
    int GetGameTime() const override { return 0; }
    std::uint32_t GetSpawnId(const idEntity*) const override {
        return 0x1FFFu;
    }
    idEntity* ResolveEntity(std::uint32_t) const override { return nullptr; }
    const char* GetEntityName(const idEntity*) const override { return ""; }
    const idEventDef* FindEvent(const char*) const override { return nullptr; }
    const idEventDef* FindEvent(int) const override { return nullptr; }
    int GetEventNumber(const idEventDef&) const override { return -1; }
    const char* GetEventName(const idEventDef&) const override { return ""; }
    int GetEventArgumentCount(const idEventDef&) const override { return 0; }
    timelineEventArgType_t GetEventArgumentType(
        const idEventDef&, int) const override { return TIMELINE_ARG_NONE; }
    std::uint32_t GetEventBehavior(const idEventDef&) const override {
        return TIMELINE_EVENT_NORMAL;
    }
    std::string GetActionEventName(const std::string& name) const override {
        return name;
    }
    bool EntityRespondsTo(const idEntity*, const idEventDef&) const override {
        return false;
    }
    void ProcessEntityEvent(idEntity*, const idEventDef&,
        const std::vector<idTimelineEventArg>&) override {}
    void ProcessActionEvent(idEntity*, const idEventDef&,
        const std::vector<idTimelineEventArg>&) override {}
    bool IsActionWorking(const idEntity*) const override { return false; }
    void ResetAction(idEntity*, int) override {}
    void ActionScriptFinished(idEntity*, int) override {}
    idEntity* ResolveEntityName(const std::string&, idEntity*, idEntity*,
        std::string& failureReason) const override {
        failureReason = "timeline services are not installed";
        return nullptr;
    }
    void SetUnresolvedEntityName(std::uint32_t,
        const std::string&) override {}
    void Warning(const std::string&) override {}
    void Error(const std::string& message) override {
        throw std::runtime_error(message);
    }
};

MissingTimeLineServices missingServices;
idComponentTimeLineServices* timelineServices = &missingServices;

std::string DescribeAction(const char* prefix, const std::string& action) {
    std::ostringstream message;
    message << prefix << " '" << action << "'";
    return message.str();
}

bool IsCompatibleArgument(timelineEventArgType_t actual,
        timelineEventArgType_t expected) {
    return expected == TIMELINE_ARG_NONE || actual == expected;
}

bool IsEnumSubtype(idAIActionParm::subParm_t subType) {
    if (subType >= idAIActionParm::SP_ARRIVALACTION
            && subType <= idAIActionParm::SP_ACTIONBOOL) {
        return true;
    }
    return subType == idAIActionParm::SP_AIVAROP
        || subType == idAIActionParm::SP_AIVARTYPE
        || subType == idAIActionParm::SP_AIANIMWEB
        || subType == idAIActionParm::SP_AIACTIONSCRIPTFLAG
        || subType == idAIActionParm::SP_AIPERCEPTIONFLAG
        || subType == idAIActionParm::SP_SITSTATE
        || subType == idAIActionParm::SP_STANDSTATE
        || subType == idAIActionParm::SP_IDLESTATE
        || subType == idAIActionParm::SP_SETMOVEPUSHSTATUS
        || subType == idAIActionParm::SP_AIMOVEMENTMODE
        || subType == idAIActionParm::SP_AIANIMWAIT
        || subType == idAIActionParm::SP_AIIDLETURN
        || subType == idAIActionParm::SP_ACCURACY
        || subType == idAIActionParm::SP_AIMOVEREASON
        || subType == idAIActionParm::SP_MOVE_TO_SCENEPOINT_FLAGS
        || subType == idAIActionParm::SP_COMMAND_MOVE;
}

idTimelineEventArg ConvertParameter(const idAIActionParm& parm,
        idEntity* scriptExecutor, idEntity* activator, bool tool,
        bool triggerEvent, bool& valid) {
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    switch (parm.type) {
        case idAIActionParm::P_DISCRETE:
            if (parm.subType == idAIActionParm::SP_BOOL) {
                return idTimelineEventArg::Boolean(parm.intVal != 0);
            }
            if (parm.subType == idAIActionParm::SP_INTEGER
                    || IsEnumSubtype(parm.subType)) {
                return idTimelineEventArg::Integer(parm.intVal);
            }
            services.Warning("Action script parameter has unknown discrete sub-type");
            break;
        case idAIActionParm::P_FLOAT:
            if (parm.subType == idAIActionParm::SP_FLOAT) {
                return idTimelineEventArg::Float(parm.floatVal.x);
            }
            if (parm.subType == idAIActionParm::SP_VEC3) {
                return idTimelineEventArg::Vector(parm.floatVal);
            }
            if (parm.subType == idAIActionParm::SP_ANGLES) {
                return idTimelineEventArg::Angles(parm.floatVal);
            }
            services.Warning("Action script parameter has unknown float sub-type");
            break;
        case idAIActionParm::P_STRING:
            if (parm.subType == idAIActionParm::SP_ANIM_ALIAS) {
                services.Error("Anim Alias parameters are no longer allowed in action scripts due to resource dependencies");
                break;
            }
            if (parm.subType == idAIActionParm::SP_STRING) {
                return idTimelineEventArg::String(parm.strVal);
            }
            if (parm.subType == idAIActionParm::SP_ANIM_WEB_NODE) {
                return idTimelineEventArg::String(parm.strVal, true);
            }
            if (parm.subType == idAIActionParm::SP_ENTITY_NAME) {
                if (parm.strVal.empty() || parm.strVal == "ACTIONSCRIPT_NULL") {
                    return idTimelineEventArg::Entity(0x1FFFu);
                }
                std::string reason;
                idEntity* resolved = services.ResolveEntityName(parm.strVal,
                    scriptExecutor, activator, reason);
                if (resolved == nullptr) {
                    if (!triggerEvent) {
                        services.Error("Action script references invalid entity '"
                            + parm.strVal + "' - " + reason);
                        Tungsten_TimelineInvalidEntityCleanup();
                    }
                    return idTimelineEventArg::Entity(0x1FFFu);
                }
                const std::uint32_t spawnId = services.GetSpawnId(resolved);
                if (tool) {
                    services.SetUnresolvedEntityName(spawnId, parm.strVal);
                }
                return idTimelineEventArg::Entity(spawnId);
            }
            services.Warning("Action script parameter has unknown string sub-type");
            break;
        case idAIActionParm::P_DECL:
            if (parm.subType == idAIActionParm::SP_DECL_VOICEOVER
                    || parm.subType == idAIActionParm::SP_DECL_SOUND
                    || parm.subType == idAIActionParm::SP_DECL_AMMO
                    || parm.subType == idAIActionParm::SP_DECL_WEAPON
                    || parm.subType == idAIActionParm::SP_DECL_INVENTORY) {
                return idTimelineEventArg::Decl(parm.declVal);
            }
            services.Warning("Action script parameter has unknown decl sub-type");
            break;
        default:
            services.Warning("Action script parameter has unknown type");
            break;
    }
    valid = false;
    return idTimelineEventArg();
}

void AppendOptionalDefaults(const idEventDef& event,
        std::vector<idTimelineEventArg>& arguments) {
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    const int expected = services.GetEventArgumentCount(event);
    const std::uint32_t behavior = services.GetEventBehavior(event);
    while (static_cast<int>(arguments.size()) < expected) {
        const int missing = expected - static_cast<int>(arguments.size());
        if ((behavior & TIMELINE_EVENT_START_ANIM_DEFAULTS) != 0) {
            arguments.push_back(idTimelineEventArg::Integer(missing == 2 ? 0 : 1));
        } else if ((behavior & TIMELINE_EVENT_IDLE_DEFAULTS) != 0) {
            arguments.push_back(idTimelineEventArg::Integer(missing == 2 ? -1 : 1));
        } else if ((behavior & TIMELINE_EVENT_PLAYER_FOCUS_DEFAULTS) != 0) {
            arguments.push_back(idTimelineEventArg::Integer(1));
        } else {
            break;
        }
    }
}

} // namespace

idTimelineEventArg idTimelineEventArg::Integer(int value) {
    idTimelineEventArg result;
    result.type = TIMELINE_ARG_INTEGER;
    result.integer = value;
    return result;
}

idTimelineEventArg idTimelineEventArg::Boolean(bool value) {
    idTimelineEventArg result = Integer(value ? 1 : 0);
    result.type = TIMELINE_ARG_BOOLEAN;
    return result;
}

idTimelineEventArg idTimelineEventArg::Float(float value) {
    idTimelineEventArg result;
    result.type = TIMELINE_ARG_FLOAT;
    result.scalar = value;
    return result;
}

idTimelineEventArg idTimelineEventArg::Vector(const idVec3& value) {
    idTimelineEventArg result;
    result.type = TIMELINE_ARG_VECTOR;
    result.vector = value;
    return result;
}

idTimelineEventArg idTimelineEventArg::Angles(const idVec3& value) {
    idTimelineEventArg result = Vector(value);
    result.type = TIMELINE_ARG_ANGLES;
    return result;
}

idTimelineEventArg idTimelineEventArg::String(const std::string& value,
        bool atomic) {
    idTimelineEventArg result;
    result.type = atomic ? TIMELINE_ARG_ATOMIC_STRING : TIMELINE_ARG_STRING;
    result.string = value;
    return result;
}

idTimelineEventArg idTimelineEventArg::Entity(std::uint32_t value) {
    idTimelineEventArg result;
    result.type = TIMELINE_ARG_ENTITY;
    result.spawnId = value;
    return result;
}

idTimelineEventArg idTimelineEventArg::Decl(const void* value) {
    idTimelineEventArg result;
    result.type = TIMELINE_ARG_DECL;
    result.declaration = value;
    return result;
}

void Tungsten_SetComponentTimeLineServices(
        idComponentTimeLineServices* services) {
    timelineServices = services != nullptr ? services : &missingServices;
}

idComponentTimeLineServices& Tungsten_ComponentTimeLineServices() {
    return *timelineServices;
}

// EA 0x82BB84D0
int idComponentTimeLine::GetRelativeTime(int) const {
    return Tungsten_ComponentTimeLineServices().GetGameTime() - startTime;
}

// EA 0x82BB8578
void idComponentTimeLine::ProcessTimelineEvent(idEntity* entity,
        const idEventDef& event,
        const std::vector<idTimelineEventArg>& arguments) const {
    Tungsten_ComponentTimeLineServices().ProcessEntityEvent(
        entity, event, arguments);
}

// EA 0x82BB85A8
bool idComponentTimeLine::IsTimelineComplete(int timelineIndex) const {
    return startTime == -1
        || timelineIndex < 0
        || timelineIndex >= static_cast<int>(entityEvents.size())
        || nextEventIndices[timelineIndex]
            >= static_cast<int>(entityEvents[timelineIndex].events.size());
}

// EA 0x82BB85F0
void idComponentActionScript::ProcessTimelineEvent(idEntity* entity,
        const idEventDef& event,
        const std::vector<idTimelineEventArg>& arguments) const {
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    if ((services.GetEventBehavior(event) & TIMELINE_EVENT_ACTION) != 0) {
        services.ProcessActionEvent(entity, event, arguments);
    } else {
        services.ProcessEntityEvent(entity, event, arguments);
    }
}

// EA 0x82BB8AE0
idComponentTimeLine::idTimeLineEvent::idTimeLineEvent()
    : eventTime(0) {
}

// EA 0x82BB8B48
void idComponentTimeLine::Update() {
    if (startTime == -1) {
        return;
    }
    bool allComplete = true;
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    for (int timelineIndex = 0;
            timelineIndex < static_cast<int>(entityEvents.size());
            ++timelineIndex) {
        idTimeLineEntity& timeline = entityEvents[timelineIndex];
        idEntity* entity = services.ResolveEntity(timeline.spawnId);
        int& next = nextEventIndices[timelineIndex];
        for (;;) {
            if (next >= static_cast<int>(timeline.events.size())) {
                break;
            }
            const int relativeTime = GetRelativeTime(timelineIndex);
            if (relativeTime < 0
                    || timeline.events[next].eventTime > relativeTime) {
                break;
            }
            const idTimeLineEvent& queued = timeline.events[next];
            const idEventDef* event = services.FindEvent(
                queued.eventCall.eventNumber);
            ++next;
            if (entity != nullptr && event != nullptr) {
                ProcessTimelineEvent(entity, *event,
                    queued.eventCall.arguments);
            }
        }
        if (IsTimelineComplete(timelineIndex)) {
            OnTimelineCompletion(timelineIndex);
        } else {
            allComplete = false;
        }
    }
    if (allComplete) {
        startTime = -1;
    }
}

// EA 0x82BB8D00
int idComponentActionScript::GetRelativeTime(int timelineIndex) const {
    if (timelineIndex < 0
            || timelineIndex >= static_cast<int>(entityEvents.size())) {
        return -1;
    }
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    idEntity* entity = services.ResolveEntity(
        entityEvents[timelineIndex].spawnId);
    if (entity == nullptr || services.IsActionWorking(entity)) {
        return -1;
    }
    const int next = nextEventIndices[timelineIndex];
    if (next >= static_cast<int>(entityEvents[timelineIndex].events.size())) {
        return services.GetGameTime() - startTime;
    }
    return entityEvents[timelineIndex].events[next].eventTime;
}

// EA 0x82BB8DB8
void idComponentActionScript::ResetTimeline(int timelineIndex) {
    if (timelineIndex < 0
            || timelineIndex >= static_cast<int>(entityEvents.size())) {
        return;
    }
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    idEntity* entity = services.ResolveEntity(
        entityEvents[timelineIndex].spawnId);
    if (entity != nullptr) {
        services.ResetAction(entity, services.GetGameTime());
    }
}

// EA 0x82BB8E78
bool idComponentActionScript::IsTimelineComplete(int timelineIndex) const {
    if (!idComponentTimeLine::IsTimelineComplete(timelineIndex)) {
        return false;
    }
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    idEntity* entity = services.ResolveEntity(
        entityEvents[timelineIndex].spawnId);
    return entity == nullptr || !services.IsActionWorking(entity);
}

// EA 0x82BB8F20
void idComponentActionScript::OnTimelineCompletion(int timelineIndex) {
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    idEntity* entity = services.ResolveEntity(
        entityEvents[timelineIndex].spawnId);
    if (entity != nullptr) {
        services.ActionScriptFinished(entity, services.GetGameTime());
    }
}

// EA 0x82BB9010
idComponentTimeLine::idTimeLineEntity::idTimeLineEntity()
    : spawnId(0x1FFFu) {
}

// EA 0x82BB9078
void idComponentTimeLine::Init() {
    startTime = -1;
    nextEventIndices.assign(entityEvents.size(), 0);
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    for (idTimeLineEntity& timeline : entityEvents) {
        std::stable_sort(timeline.events.begin(), timeline.events.end(),
            [](const idTimeLineEvent& lhs, const idTimeLineEvent& rhs) {
                return lhs.eventTime < rhs.eventTime;
            });
        idEntity* entity = services.ResolveEntity(timeline.spawnId);
        if (entity == nullptr) {
            services.Warning("idComponentTimeLine references bad entity");
            continue;
        }
        for (const idTimeLineEvent& queued : timeline.events) {
            const idEventDef* event = services.FindEvent(
                queued.eventCall.eventNumber);
            if (event == nullptr) {
                services.Warning("idComponentTimeLine references bad event");
            } else if (!services.EntityRespondsTo(entity, *event)
                    && (services.GetEventBehavior(*event)
                        & TIMELINE_EVENT_ACTION) == 0) {
                std::ostringstream warning;
                warning << "idComponentTimeLine references entity '"
                    << services.GetEntityName(entity)
                    << "' that doesn't respond to event '"
                    << services.GetEventName(*event) << "'";
                services.Warning(warning.str());
            }
        }
    }
}

// EA 0x82BB9330
void idComponentTimeLine::Start() {
    startTime = Tungsten_ComponentTimeLineServices().GetGameTime();
    nextEventIndices.assign(entityEvents.size(), 0);
    for (int index = 0;
            index < static_cast<int>(entityEvents.size()); ++index) {
        ResetTimeline(index);
    }
    Update();
}

// EA 0x82BB93D0
int idComponentActionScript::GetTimelineIndex(const idEntity* entity) const {
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    const std::uint32_t spawnId = services.GetSpawnId(entity);
    for (int index = 0; index < static_cast<int>(entityEvents.size());
            ++index) {
        if (entityEvents[index].spawnId == spawnId
                || services.ResolveEntity(entityEvents[index].spawnId)
                    == entity) {
            return index;
        }
    }
    return -1;
}

// EA 0x82BB94E8
bool idComponentActionScript::RunningActionScript(const idEntity* entity) const {
    const int index = GetTimelineIndex(entity);
    return startTime != -1 && index >= 0 && !IsTimelineComplete(index);
}

// EA 0x82BB9558
void idComponentActionScript::ClearActionScript(const idEntity* entity) {
    const int index = GetTimelineIndex(entity);
    if (index < 0) {
        return;
    }
    startTime = -1;
    entityEvents[index].events.clear();
    if (index < static_cast<int>(nextEventIndices.size())) {
        nextEventIndices[index] = 0;
    }
}

// EA 0x82BB95D0
int idComponentActionScript::NumScriptActions(const idEntity* entity) const {
    const int index = GetTimelineIndex(entity);
    return index >= 0
        ? static_cast<int>(entityEvents[index].events.size()) : 0;
}

// EA 0x82BB9960
idComponentTimeLine::idComponentTimeLine()
    : startTime(-1) {
}

// EA 0x82BB9A30
idComponentTimeLine::~idComponentTimeLine() = default;

// EA 0x82BB9AE8
idComponentActionScript::idComponentActionScript() = default;

// EA 0x82BB9B28
idComponentActionScript::~idComponentActionScript() = default;

// EA 0x82BB9C98
void idComponentActionScript::SetActionScript(idEntity* entity,
        const aiActionScript_t& script, idEntity* scriptExecutor,
        idEntity* activator, bool tool) {
    if (nextEventIndices.size() != entityEvents.size()) {
        return;
    }
    idComponentTimeLineServices& services =
        Tungsten_ComponentTimeLineServices();
    const std::uint32_t spawnId = services.GetSpawnId(entity);
    int timelineIndex = GetTimelineIndex(entity);
    if (timelineIndex < 0) {
        idTimeLineEntity timeline;
        timeline.spawnId = spawnId;
        entityEvents.push_back(timeline);
        nextEventIndices.push_back(0);
        timelineIndex = static_cast<int>(entityEvents.size()) - 1;
    }
    if (tool && entity != nullptr) {
        services.SetUnresolvedEntityName(spawnId,
            services.GetEntityName(entity));
    }
    ClearActionScript(entity);

    for (std::size_t actionIndex = 0; actionIndex < script.size();
            ++actionIndex) {
        const idScriptAction& action = script[actionIndex];
        const std::string eventName = services.GetActionEventName(
            action.eventName);
        const idEventDef* event = services.FindEvent(eventName.c_str());
        if (event == nullptr) {
            services.Warning(DescribeAction(
                "Script action event not found", action.eventName));
            continue;
        }
        const std::uint32_t behavior = services.GetEventBehavior(*event);
        std::vector<idTimelineEventArg> arguments;
        arguments.push_back(idTimelineEventArg::Entity(spawnId));
        if ((behavior & TIMELINE_EVENT_MOVE_DEFAULT) != 0) {
            arguments.push_back(idTimelineEventArg::Integer(33));
        }

        bool valid = true;
        const int expectedCount = services.GetEventArgumentCount(*event);
        if (static_cast<int>(arguments.size() + action.parms.size())
                > expectedCount) {
            valid = false;
        }
        for (const idAIActionParm& parm : action.parms) {
            idTimelineEventArg argument = ConvertParameter(parm,
                scriptExecutor, activator, tool,
                (behavior & TIMELINE_EVENT_TRIGGER) != 0, valid);
            const int argumentIndex = static_cast<int>(arguments.size());
            if (argumentIndex >= expectedCount
                    || !IsCompatibleArgument(argument.type,
                        services.GetEventArgumentType(*event,
                            argumentIndex))) {
                valid = false;
            }
            arguments.push_back(argument);
        }
        AppendOptionalDefaults(*event, arguments);
        if (static_cast<int>(arguments.size()) != expectedCount) {
            valid = false;
        }
        for (int argumentIndex = 0;
                argumentIndex < static_cast<int>(arguments.size())
                    && argumentIndex < expectedCount;
                ++argumentIndex) {
            if (!IsCompatibleArgument(arguments[argumentIndex].type,
                    services.GetEventArgumentType(*event,
                        argumentIndex))) {
                valid = false;
            }
        }
        if (!valid) {
            services.Warning(DescribeAction(
                "Script action not queued", action.eventName));
            continue;
        }

        idTimeLineEvent queued;
        queued.eventTime = static_cast<int>(actionIndex);
        queued.eventCall.eventNumber = services.GetEventNumber(*event);
        queued.eventCall.arguments = arguments;
        entityEvents[timelineIndex].events.push_back(queued);
    }
}

void idComponentTimeLine::ResetTimeline(int) {
}

void idComponentTimeLine::OnTimelineCompletion(int) {
}

// EA 0x82BBAB0C
void Tungsten_TimelineInvalidEntityCleanup() {
}
