#include "aigamestate.h"

#include <algorithm>
#include <cstring>
#include <limits>

namespace {

constexpr int kEntityNumberMask = 0x1FFF;
constexpr int kInvalidEntityNumber = 0x1FFF;
constexpr int kLatchContentsMask = 0x19E00;
constexpr int kGarbagePerFrame = 32;

std::int16_t AddCrouchDelta(const std::int16_t current,
        const int millisecondsPerFrame) {
    const int maximum = (std::numeric_limits<std::int16_t>::max)();
    if (millisecondsPerFrame <= 0) {
        return current;
    }
    return current < maximum - millisecondsPerFrame
        ? static_cast<std::int16_t>(current + millisecondsPerFrame)
        : current;
}

} // namespace

// Retail symbol: ?GetState@idAIGameState@@QBAPBUaiLatchedState_t@@ABVidSpawnId@@@Z
// EA: 0x82AFBF70, RVA: 0x00AFBF70
const aiLatchedState_t* idAIGameState::GetState(
        const idSpawnId& spawnId) const {
    const int entityNumber = spawnId.value & kEntityNumberMask;
    if (entityNumber == kInvalidEntityNumber) {
        return nullptr;
    }
    const aiLatchedState_t* const state = entStates[entityNumber];
    return state != nullptr && state->spawnId.value == spawnId.value
        ? state : nullptr;
}

// Retail symbol: ?GetStateForEntityNum@idAIGameState@@QBAPBUaiLatchedState_t@@H@Z
// EA: 0x82AFBFA8, RVA: 0x00AFBFA8
const aiLatchedState_t* idAIGameState::GetStateForEntityNum(
        const int entityNumber) const {
    if (entityNumber < 0 || entityNumber >= kInvalidEntityNumber) {
        return nullptr;
    }
    return entStates[entityNumber];
}

// Retail symbol:
// ?GetEvent@idAIGameState@@QBAPBUaiLatchedEvent_t@@ABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@@Z
// EA: 0x82AFBFC8, RVA: 0x00AFBFC8
const aiLatchedEvent_t* idAIGameState::GetEvent(
        const idAIGameEventHandle& handle) const {
    if (!handle.IsValid()) {
        return nullptr;
    }
    for (int index = 0; index < numEvents; ++index) {
        const aiLatchedEvent_t* const event = events[index];
        if (event != nullptr && event->eventHandle.value == handle.value) {
            return event;
        }
    }
    return nullptr;
}

// Retail symbol: ?Shutdown@idAIGameState@@QAAXXZ
// EA: 0x82AFC1C8, RVA: 0x00AFC1C8
void idAIGameState::Shutdown() {
    std::fill(entStates.begin(), entStates.end(), nullptr);
    std::fill(events.begin(), events.end(), nullptr);
    numEvents = 0;
    gameTime = -1;
    gameFrame = -1;
    garbageIndex = 0;
    stateAllocator.Shutdown();
    eventAllocator.Shutdown();
    forcedLatches.Clear();
}

// Retail symbol:
// ?GetPhysicalState@idAIGameState@@SA_NPBVidGameLocal@@PBVidEntity@@AAUaiPhysicalState_t@@@Z
// EA: 0x82AFC278, RVA: 0x00AFC278
bool idAIGameState::GetPhysicalState(const idGameLocal* const game,
        const idEntity* const entity, aiPhysicalState_t& physicalState) {
    if (game == nullptr || entity == nullptr) {
        return false;
    }

    idAIGameEntityRuntime runtime{};
    if (!Tungsten_GetAIGameEntityRuntime(*game, *entity, runtime)
        || !runtime.hasPhysics) {
        return false;
    }

    physicalState.origin = runtime.origin;
    physicalState.velocity = runtime.velocity;
    physicalState.rotation = runtime.rotation;
    physicalState.bounds.SetBounds(runtime.bounds);
    physicalState.viewfwd = runtime.viewForward;
    physicalState.eyePos = runtime.eyePosition;

    const bool wasCrouched =
        (physicalState.entFlags & AIPHYSICAL_CROUCHED) != 0;
    physicalState.entFlags = 0;
    if (runtime.dead) {
        physicalState.entFlags |= AIPHYSICAL_DEAD;
    }
    if (runtime.dying) {
        physicalState.entFlags |= AIPHYSICAL_DYING;
    }

    if (runtime.actor) {
        if (runtime.leanState == 1) {
            physicalState.entFlags |= AIPHYSICAL_LEAN_LEFT;
        } else if (runtime.leanState == 2) {
            physicalState.entFlags |= AIPHYSICAL_LEAN_RIGHT;
        }
        if (runtime.drivingVehicle) {
            physicalState.entFlags |= AIPHYSICAL_DRIVING;
        }

        const bool crouched = !runtime.dead && runtime.posture == 2;
        if (crouched) {
            physicalState.entFlags |= AIPHYSICAL_CROUCHED;
        }
        if (wasCrouched == crouched) {
            physicalState.crouchChangeDelta = AddCrouchDelta(
                physicalState.crouchChangeDelta,
                Tungsten_GetAIGameMillisecondsPerFrame(*game));
        } else {
            physicalState.crouchChangeDelta = 0;
        }
    } else {
        physicalState.crouchChangeDelta =
            (std::numeric_limits<std::int16_t>::max)();
    }

    if (runtime.noAIInteraction) {
        physicalState.entFlags |= AIPHYSICAL_NO_AI_INTERACTION;
    }
    return true;
}

// Retail symbol:
// ?LatchEntityState@idAIGameState@@AAAXPBVidGameLocal@@PBVidEntity@@_N@Z
// EA: 0x82AFC7F8, RVA: 0x00AFC7F8
void idAIGameState::LatchEntityState(const idGameLocal* const game,
        const idEntity* const entity, const bool force) {
    if (game == nullptr || entity == nullptr) {
        return;
    }

    idAIGameEntityRuntime runtime{};
    if (!Tungsten_GetAIGameEntityRuntime(*game, *entity, runtime)
        || !runtime.hasPhysics
        || (!force && (runtime.physicsContents & kLatchContentsMask) == 0)
        || runtime.entityNumber < 0
        || runtime.entityNumber >= kInvalidEntityNumber) {
        return;
    }

    aiLatchedState_t*& slot = entStates[runtime.entityNumber];
    if (slot != nullptr && slot->frameNum == gameFrame) {
        return;
    }
    if (slot == nullptr) {
        slot = stateAllocator.Alloc();
        if (slot == nullptr) {
            return;
        }
    }

    slot->frameNum = gameFrame;
    slot->spawnId = runtime.spawnId.value;
    slot->faction = runtime.faction;
    slot->groupHandle = runtime.groupHandle;
    slot->entityType = runtime.entityType;
    slot->masterId = runtime.masterSpawnId;
    GetPhysicalState(game, entity, slot->physical);
    slot->physical.viewfwd = runtime.viewForward;
    slot->horzFOV = runtime.entityType == 0
        ? runtime.aiHorizontalFov : runtime.horizontalFov;
    slot->vertFOV = runtime.verticalFov;
    slot->physical.stimScale =
        static_cast<std::uint8_t>(runtime.stimulusScale);
}

// Retail symbol: ??0idAIGameState@@QAA@XZ
// EA: 0x82AFCA00, RVA: 0x00AFCA00
idAIGameState::idAIGameState()
    : entStates{}
    , events{}
    , forcedLatches()
    , stateAllocator(false)
    , eventAllocator(false)
    , gameTime(-1)
    , gameFrame(-1)
    , numEvents(0)
    , garbageIndex(0) {
    std::fill(entStates.begin(), entStates.end(), nullptr);
    std::fill(events.begin(), events.end(), nullptr);
}

// Retail symbol: ??1idAIGameState@@QAA@XZ
// EA: 0x82AFCAF0, RVA: 0x00AFCAF0
idAIGameState::~idAIGameState() {
    Shutdown();
}

// Retail symbol: ?UpdateFromGame@idAIGameState@@QAAXPBVidGameLocal@@@Z
// EA: 0x82AFCBF0, RVA: 0x00AFCBF0
void idAIGameState::UpdateFromGame(const idGameLocal* const game) {
    if (game == nullptr) {
        return;
    }

    Tungsten_GetAIGameTimeAndFrame(*game, gameTime, gameFrame);

    const int activeCount = (std::max)(
        0, Tungsten_GetAIGameActiveEntityCount(*game));
    for (int index = 0; index < activeCount; ++index) {
        LatchEntityState(
            game, Tungsten_GetAIGameActiveEntity(*game, index), false);
    }

    const int forcedCount = forcedLatches.Num();
    for (int index = 0; index < forcedCount; ++index) {
        LatchEntityState(game, Tungsten_ResolveAIGameEntity(
            *game, forcedLatches[index].value), true);
    }
    forcedLatches.Clear();

    for (int offset = 0; offset < kGarbagePerFrame; ++offset) {
        const int entityNumber = (garbageIndex + offset) & kEntityNumberMask;
        aiLatchedState_t*& state = entStates[entityNumber];
        if (state != nullptr
            && Tungsten_GetAIGameEntitySpawnId(*game, entityNumber)
                != state->spawnId.value) {
            stateAllocator.Free(state);
            state = nullptr;
        }
    }
    garbageIndex = (garbageIndex + kGarbagePerFrame) & kEntityNumberMask;

    for (int index = 0; index < numEvents; ++index) {
        eventAllocator.Free(events[index]);
        events[index] = nullptr;
    }
    numEvents = 0;

    const int sourceEventCount = (std::max)(
        0, Tungsten_GetAIGameEventCount(*game));
    for (int index = 0; index < sourceEventCount; ++index) {
        idAIGameEventRuntime runtime{};
        if (!Tungsten_GetAIGameEventRuntime(*game, index, runtime)) {
            continue;
        }
        aiLatchedEvent_t* const event = eventAllocator.Alloc();
        if (event == nullptr) {
            Tungsten_WarnAIGameEventOverflow(sourceEventCount - index);
            break;
        }
        if (numEvents >= events.Num()) {
            Tungsten_WarnAIGameEventOverflow(sourceEventCount - index);
            break;
        }
        event->eventHandle = runtime.handle;
        event->eventTime = runtime.eventTime;
        event->origin = runtime.origin;
        event->creatorId = runtime.creatorSpawnId;
        event->relevantId = runtime.relevantSpawnId;
        event->priority = runtime.priority;
        event->flags = runtime.instigatorStimulus ? 1u : 0u;
        event->eventClass = runtime.eventClass;
        events[numEvents++] = event;

        LatchEntityState(game, Tungsten_ResolveAIGameEntity(
            *game, runtime.creatorSpawnId), true);
        LatchEntityState(game, Tungsten_ResolveAIGameEntity(
            *game, runtime.relevantSpawnId), true);
    }

    Tungsten_DebugAIGameState(
        activeCount, forcedCount, activeCount + forcedCount);
}

// Retail symbol: ?UpdateForcedLatches@idAIGameState@@QAAXPBVidGameLocal@@@Z
// EA: 0x82AFD1D0, RVA: 0x00AFD1D0
void idAIGameState::UpdateForcedLatches(const idGameLocal* const game) {
    if (game == nullptr) {
        return;
    }
    for (int index = 0; index < forcedLatches.Num(); ++index) {
        LatchEntityState(game, Tungsten_ResolveAIGameEntity(
            *game, forcedLatches[index].value), true);
    }
    forcedLatches.Clear();
}

// Retail symbol: ?ForceLatch@idAIGameState@@QAAXABVidSpawnId@@@Z
// EA: 0x82AFD2C8, RVA: 0x00AFD2C8
void idAIGameState::ForceLatch(const idSpawnId& spawnId) {
    if ((spawnId.value & kEntityNumberMask) != kInvalidEntityNumber) {
        forcedLatches.AddUnique(spawnId);
    }
}
