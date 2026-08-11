#include "behaviortree.h"

#include "../../../../engine/gamelib/class.h"

#include <algorithm>
#include <cstdio>
#include <numeric>

namespace {
idBehaviorTreeServices* g_services = nullptr;
std::uint32_t g_fallbackRandomSeed = 0U;

int RandomInt(const int minimum, const int maximum) {
    if (maximum <= minimum) {
        return minimum;
    }
    if (g_services != nullptr) {
        return g_services->RandomInt(minimum, maximum);
    }
    g_fallbackRandomSeed = 1664525U * g_fallbackRandomSeed + 1013904223U;
    const unsigned int value = (g_fallbackRandomSeed >> 10U) & 0x7FFFU;
    return minimum + static_cast<int>(
        value % static_cast<unsigned int>(maximum - minimum + 1));
}

bool SameOrDerivedType(const idBehaviorState& state,
        const idTypeInfo& requested) {
    const idTypeInfo* const actual = state.GetType();
    return actual != nullptr && actual->typeNum >= requested.typeNum
        && actual->typeNum <= requested.lastChild;
}
} // namespace

void Tungsten_SetBehaviorTreeServices(
        idBehaviorTreeServices* const services) {
    g_services = services;
}

// Retail symbol: ??1idBehaviorAction@@UAA@XZ
// EA: 0x82B3A548, RVA: 0x00B3A548
idBehaviorAction::~idBehaviorAction() = default;

// Retail symbol: ?InternalProcessEvent@idBehaviorState@@MAAXPAVidBot@@HPBVidBehaviorStateEvent@@@Z
// EA: 0x82B3A558, RVA: 0x00B3A558
void idBehaviorState::InternalProcessEvent(idBot* const bot,
        const int currentTime, const idBehaviorStateEvent* const eventInfo) {
    ProcessEvent(bot, currentTime, eventInfo);
}

// Retail symbol: ?CheckStateFlag@idBehaviorState@@IBA_NH@Z
// EA: 0x82B3A568, RVA: 0x00B3A568
bool idBehaviorState::CheckStateFlag(const int flag) const {
    return (stateFlags & flag) != 0;
}

// Retail symbol: ?InternalInit@idBehaviorDecorator@@MAAXPAVidBot@@H@Z
// EA: 0x82B3A580, RVA: 0x00B3A580
void idBehaviorDecorator::InternalInit(
        idBot* const bot, const int currentTime) {
    Init(bot, currentTime);
    if (child != nullptr) {
        child->InternalInit(bot, currentTime);
    }
}

// Retail symbol: ?GetDebugString@idBehaviorSelector@@UBAXAAVidStr@@@Z
// EA: 0x82B3A5D8, RVA: 0x00B3A5D8
void idBehaviorSelector::GetDebugString(idStr& text) const {
    text = currentState != nullptr ? currentState->GetClassName() : "";
}

// Retail symbol: ?GetDebugString@idBehaviorSequence@@UBAXAAVidStr@@@Z
// EA: 0x82B3A628, RVA: 0x00B3A628
void idBehaviorSequence::GetDebugString(idStr& text) const {
    text = currentState != nullptr ? currentState->GetClassName() : "";
}

// Retail symbol: ?RootInit@idBehaviorTree@@QAAXPAVidBot@@H@Z
// EA: 0x82B3A678, RVA: 0x00B3A678
void idBehaviorTree::RootInit(idBot* const bot, const int currentTime) {
    InternalInit(bot, currentTime);
}

// Retail symbol: ??0idBehaviorState@@QAA@XZ
// EA: 0x82B3A688, RVA: 0x00B3A688
idBehaviorState::idBehaviorState()
    : stateStartTime(0), stateFlags(BEHAVIOR_STATE_ENABLED),
      nextStateUseTime(0), lastPriorityUpdateTime(0),
      lastStateUpdateTime(0), stateUpdateDelay(0),
      stateUseCooldownTime(0), stateFailedUseCooldownTime(0),
      lastStateRunTime(0), lastPriority(BEHAVIOR_PRIORITY_NULL),
      stateGoalTypeFlags(static_cast<int>(0x80000000U)) {
}

// Retail symbol: ?GetDebugString@idBehaviorState@@MBAXAAVidStr@@@Z
// EA: 0x82B3A768, RVA: 0x00B3A768
void idBehaviorState::GetDebugString(idStr& text) const {
    text.Clear();
}

// Retail symbol: ?InternalEnter@idBehaviorState@@MAAXPAVidBot@@H@Z
// EA: 0x82B3A7B8, RVA: 0x00B3A7B8
void idBehaviorState::InternalEnter(
        idBot* const bot, const int currentTime) {
    Enter(bot, currentTime);
    stateStartTime = currentTime;
    stateFlags = (stateFlags & ~(
        BEHAVIOR_STATE_ACTIVE | BEHAVIOR_STATE_ERROR))
        | BEHAVIOR_STATE_ACTIVE;
}

// Retail symbol: ?InternalExit@idBehaviorState@@MAAXPAVidBot@@H@Z
// EA: 0x82B3A818, RVA: 0x00B3A818
void idBehaviorState::InternalExit(
        idBot* const bot, const int currentTime) {
    Exit(bot, currentTime);
    const int oldFlags = stateFlags;
    const int cooldown = (oldFlags & BEHAVIOR_STATE_ERROR) != 0
        ? stateFailedUseCooldownTime : stateUseCooldownTime;
    lastStateRunTime = currentTime;
    nextStateUseTime = currentTime + cooldown;
    stateFlags = oldFlags & ~(BEHAVIOR_STATE_ACTIVE
        | BEHAVIOR_STATE_NON_INTERRUPTIBLE_ALT | BEHAVIOR_STATE_ERROR);
}

// Retail symbol: ?IsUseAble@idBehaviorState@@IBA_NPBVidBot@@@Z
// EA: 0x82B3A898, RVA: 0x00B3A898
bool idBehaviorState::IsUseAble(const idBot* const bot) const {
    const int gameTime = g_services != nullptr
        ? g_services->GetScaledGameTime() : 0;
    if ((stateFlags & BEHAVIOR_STATE_ENABLED) == 0
            || nextStateUseTime > gameTime) {
        return false;
    }
    if (stateGoalTypeFlags < 0) {
        return true;
    }
    return bot != nullptr && g_services != nullptr
        && g_services->SupportsGoalType(*bot, stateGoalTypeFlags);
}

// Retail symbol: ??0idBehaviorAction@@QAA@XZ
// EA: 0x82B3A938, RVA: 0x00B3A938
idBehaviorAction::idBehaviorAction() = default;

// Retail symbol: ?FindState@idBehaviorComposite@@UAAPAVidBehaviorState@@ABVidTypeInfo@@@Z
// EA: 0x82B3A978, RVA: 0x00B3A978
idBehaviorState* idBehaviorComposite::FindState(const idTypeInfo& type) {
    if (SameOrDerivedType(*this, type)) {
        return this;
    }
    for (idBehaviorState* const state : children) {
        if (state != nullptr) {
            idBehaviorState* const found = state->FindState(type);
            if (found != nullptr) {
                return found;
            }
        }
    }
    return nullptr;
}

// Retail symbol: ?GetStateIndex@idBehaviorComposite@@UBAHPBVidBehaviorState@@@Z
// EA: 0x82B3AA30, RVA: 0x00B3AA30
int idBehaviorComposite::GetStateIndex(
        const idBehaviorState* const state) const {
    if (state == nullptr) {
        return -1;
    }
    const auto found = std::find(children.begin(), children.end(), state);
    return found == children.end()
        ? -1 : static_cast<int>(found - children.begin());
}

// Retail symbol: ?IsInterruptable@idBehaviorComposite@@UBA_NXZ
// EA: 0x82B3AA80, RVA: 0x00B3AA80
bool idBehaviorComposite::IsInterruptable() const {
    for (const idBehaviorState* const state : children) {
        if (state != nullptr && state->IsActive()
                && !state->IsInterruptable()) {
            return false;
        }
    }
    return idBehaviorState::IsInterruptable();
}

// Retail symbol: ?HasActiveChildren@idBehaviorComposite@@QBA_NXZ
// EA: 0x82B3AB28, RVA: 0x00B3AB28
bool idBehaviorComposite::HasActiveChildren() const {
    for (const idBehaviorState* const state : children) {
        if (state != nullptr && state->IsActive()) {
            return true;
        }
    }
    return false;
}

// Retail symbol: ?InternalInit@idBehaviorComposite@@MAAXPAVidBot@@H@Z
// EA: 0x82B3AB78, RVA: 0x00B3AB78
void idBehaviorComposite::InternalInit(
        idBot* const bot, const int currentTime) {
    Init(bot, currentTime);
    for (idBehaviorState* const state : children) {
        if (state != nullptr) {
            state->InternalInit(bot, currentTime);
        }
    }
}

// Retail symbol: ?InternalProcessEvent@idBehaviorComposite@@MAAXPAVidBot@@HPBVidBehaviorStateEvent@@@Z
// EA: 0x82B3ABF0, RVA: 0x00B3ABF0
void idBehaviorComposite::InternalProcessEvent(idBot* const bot,
        const int currentTime,
        const idBehaviorStateEvent* const eventInfo) {
    ProcessEvent(bot, currentTime, eventInfo);
    for (idBehaviorState* const state : children) {
        if (state != nullptr) {
            state->InternalProcessEvent(bot, currentTime, eventInfo);
        }
    }
}

// Retail symbol: ?InternalExit@idBehaviorComposite@@MAAXPAVidBot@@H@Z
// EA: 0x82B3AC70, RVA: 0x00B3AC70
void idBehaviorComposite::InternalExit(
        idBot* const bot, const int currentTime) {
    for (idBehaviorState* const state : children) {
        if (state != nullptr && state->IsActive()) {
            state->InternalExit(bot, currentTime);
        }
    }
    if (IsActive()) {
        idBehaviorState::InternalExit(bot, currentTime);
    }
}

// Retail symbol: ??0idBehaviorDecorator@@QAA@XZ
// EA: 0x82B3AD50, RVA: 0x00B3AD50
idBehaviorDecorator::idBehaviorDecorator() : child(nullptr) {
}

// Retail symbol: ?InternalProcessEvent@idBehaviorDecorator@@MAAXPAVidBot@@HPBVidBehaviorStateEvent@@@Z
// EA: 0x82B3AD98, RVA: 0x00B3AD98
void idBehaviorDecorator::InternalProcessEvent(idBot* const bot,
        const int currentTime,
        const idBehaviorStateEvent* const eventInfo) {
    ProcessEvent(bot, currentTime, eventInfo);
    if (child != nullptr) {
        child->InternalProcessEvent(bot, currentTime, eventInfo);
    }
}

// Retail symbol: ?InternalExit@idBehaviorDecorator@@MAAXPAVidBot@@H@Z
// EA: 0x82B3ADF8, RVA: 0x00B3ADF8
void idBehaviorDecorator::InternalExit(
        idBot* const bot, const int currentTime) {
    if (child != nullptr && child->IsActive()) {
        child->InternalExit(bot, currentTime);
    }
    if (IsActive()) {
        idBehaviorState::InternalExit(bot, currentTime);
    }
}

// Retail symbol: ?GetDebugString@idBehaviorParallel@@UBAXAAVidStr@@@Z
// EA: 0x82B3AE68, RVA: 0x00B3AE68
void idBehaviorParallel::GetDebugString(idStr& text) const {
    int activeCount = 0;
    for (const idBehaviorState* const state : children) {
        if (state != nullptr && state->IsActive()) {
            ++activeCount;
        }
    }
    text.Format("%d states active", activeCount);
}

// Retail symbol: ?InternalEnter@idBehaviorSelector@@MAAXPAVidBot@@H@Z
// EA: 0x82B3AEB8, RVA: 0x00B3AEB8
void idBehaviorSelector::InternalEnter(
        idBot* const bot, const int currentTime) {
    idBehaviorState::InternalEnter(bot, currentTime);
    if (currentState != nullptr) {
        currentState->InternalEnter(bot, currentTime);
    }
}

// Retail symbol: ?InternalExit@idBehaviorSelector@@MAAXPAVidBot@@H@Z
// EA: 0x82B3AF20, RVA: 0x00B3AF20
void idBehaviorSelector::InternalExit(
        idBot* const bot, const int currentTime) {
    if (currentState != nullptr && currentState->IsActive()) {
        currentState->InternalExit(bot, currentTime);
    }
    currentState = nullptr;
    idBehaviorComposite::InternalExit(bot, currentTime);
}

// Retail symbol: ?InternalEnter@idBehaviorSequence@@MAAXPAVidBot@@H@Z
// EA: 0x82B3AF88, RVA: 0x00B3AF88
void idBehaviorSequence::InternalEnter(
        idBot* const bot, const int currentTime) {
    idBehaviorState::InternalEnter(bot, currentTime);
    if (currentState != nullptr) {
        currentState->InternalEnter(bot, currentTime);
    }
}

// Retail symbol: ?InternalExit@idBehaviorSequence@@MAAXPAVidBot@@H@Z
// EA: 0x82B3AFF0, RVA: 0x00B3AFF0
void idBehaviorSequence::InternalExit(
        idBot* const bot, const int currentTime) {
    if (currentState != nullptr && currentState->IsActive()) {
        currentState->InternalExit(bot, currentTime);
    }
    currentState = nullptr;
    currentStateIndex = -1;
    idBehaviorComposite::InternalExit(bot, currentTime);
}

// Retail symbol: ?RootThink@idBehaviorTree@@QAAXPAVidBot@@H@Z
// EA: 0x82B3B058, RVA: 0x00B3B058
void idBehaviorTree::RootThink(idBot* const bot, const int currentTime) {
    InternalThink(bot, currentTime);
    if (HasActiveChildren()) {
        numFramesWithNoActiveChildren = 0;
    } else {
        ++numFramesWithNoActiveChildren;
    }
}

// Retail symbol: ?InternalThink@idBehaviorState@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3B0C0, RVA: 0x00B3B0C0
behaviorStatus_t idBehaviorState::InternalThink(
        idBot* const bot, const int currentTime) {
    if (stateUpdateDelay + lastStateUpdateTime > currentTime) {
        return BEHAVIOR_STATUS_RUNNING;
    }
    lastStateUpdateTime = currentTime;
    const behaviorStatus_t result = Think(bot, currentTime);
    if (result == BEHAVIOR_STATUS_ERROR) {
        stateFlags |= BEHAVIOR_STATE_ERROR;
    } else {
        stateFlags &= ~BEHAVIOR_STATE_ERROR;
    }
    return result;
}

// Retail symbol: ?InternalGetPriority@idBehaviorState@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3B148, RVA: 0x00B3B148
behaviorPriority_t idBehaviorState::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (!IsUseAble(bot)) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if ((!IsActive()
            || stateUpdateDelay + lastStateUpdateTime <= currentTime)
            && lastPriorityUpdateTime < currentTime) {
        lastPriorityUpdateTime = currentTime;
        lastPriority = GetPriority(bot, currentTime);
    }
    return lastPriority;
}

// Retail symbol: ?InternalThink@idBehaviorDecorator@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3B1E0, RVA: 0x00B3B1E0
behaviorStatus_t idBehaviorDecorator::InternalThink(
        idBot* const bot, const int currentTime) {
    return idBehaviorState::InternalThink(bot, currentTime);
}

// Retail symbol: ?InternalGetPriority@idBehaviorParallel@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3B1E8, RVA: 0x00B3B1E8
behaviorPriority_t idBehaviorParallel::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (idBehaviorState::InternalGetPriority(bot, currentTime)
            == BEHAVIOR_PRIORITY_NULL) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    for (idBehaviorState* const state : children) {
        if (state != nullptr) {
            const behaviorPriority_t priority =
                state->InternalGetPriority(bot, currentTime);
            if (priority > BEHAVIOR_PRIORITY_NULL) {
                return priority;
            }
        }
    }
    return BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?InternalThink@idBehaviorParallel@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3B268, RVA: 0x00B3B268
behaviorStatus_t idBehaviorParallel::InternalThink(
        idBot* const bot, const int currentTime) {
    const behaviorStatus_t ownStatus =
        idBehaviorState::InternalThink(bot, currentTime);
    if (ownStatus == BEHAVIOR_STATUS_ERROR
            || ownStatus == BEHAVIOR_STATUS_FINISHED) {
        return ownStatus;
    }
    bool anyRunning = false;
    for (idBehaviorState* const state : children) {
        if (state == nullptr) {
            continue;
        }
        const behaviorPriority_t priority =
            state->InternalGetPriority(bot, currentTime);
        if (priority > BEHAVIOR_PRIORITY_NULL) {
            if (!state->IsActive()) {
                state->InternalEnter(bot, currentTime);
            }
            const behaviorStatus_t status =
                state->InternalThink(bot, currentTime);
            if (status == BEHAVIOR_STATUS_RUNNING) {
                anyRunning = true;
                continue;
            }
        }
        if (state->IsActive()) {
            state->InternalExit(bot, currentTime);
        }
    }
    return anyRunning
        ? BEHAVIOR_STATUS_RUNNING : BEHAVIOR_STATUS_FINISHED;
}

// Retail symbol: ?InternalThink@idBehaviorParallelUntilFail@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3B3A8, RVA: 0x00B3B3A8
behaviorStatus_t idBehaviorParallelUntilFail::InternalThink(
        idBot* const bot, const int currentTime) {
    const behaviorStatus_t ownStatus =
        idBehaviorState::InternalThink(bot, currentTime);
    if (ownStatus == BEHAVIOR_STATUS_ERROR
            || ownStatus == BEHAVIOR_STATUS_FINISHED) {
        return ownStatus;
    }
    bool anyRunning = false;
    for (idBehaviorState* const state : children) {
        if (state == nullptr) {
            continue;
        }
        const behaviorPriority_t priority =
            state->InternalGetPriority(bot, currentTime);
        if (priority > BEHAVIOR_PRIORITY_NULL) {
            if (!state->IsActive()) {
                state->InternalEnter(bot, currentTime);
            }
            const behaviorStatus_t status =
                state->InternalThink(bot, currentTime);
            if (status == BEHAVIOR_STATUS_ERROR) {
                state->InternalExit(bot, currentTime);
                return BEHAVIOR_STATUS_ERROR;
            }
            if (status == BEHAVIOR_STATUS_RUNNING) {
                anyRunning = true;
                continue;
            }
        }
        if (state->IsActive()) {
            state->InternalExit(bot, currentTime);
        }
    }
    return anyRunning
        ? BEHAVIOR_STATUS_RUNNING : BEHAVIOR_STATUS_FINISHED;
}

// Retail symbol: ?InternalGetPriority@idBehaviorSelector@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3B500, RVA: 0x00B3B500
behaviorPriority_t idBehaviorSelector::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (idBehaviorState::InternalGetPriority(bot, currentTime)
            == BEHAVIOR_PRIORITY_NULL) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (IsActive() && currentState != nullptr) {
        return currentState->InternalGetPriority(bot, currentTime);
    }
    currentState = nullptr;
    for (idBehaviorState* const state : children) {
        if (state != nullptr) {
            const behaviorPriority_t priority =
                state->InternalGetPriority(bot, currentTime);
            if (priority > BEHAVIOR_PRIORITY_NULL) {
                currentState = state;
                return priority;
            }
        }
    }
    return BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?InternalThink@idBehaviorSelector@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3B5C8, RVA: 0x00B3B5C8
behaviorStatus_t idBehaviorSelector::InternalThink(
        idBot* const bot, const int currentTime) {
    const behaviorStatus_t ownStatus =
        idBehaviorState::InternalThink(bot, currentTime);
    if (currentState == nullptr) {
        return ownStatus == BEHAVIOR_STATUS_ERROR
            ? BEHAVIOR_STATUS_ERROR : BEHAVIOR_STATUS_FINISHED;
    }
    if (ownStatus == BEHAVIOR_STATUS_ERROR
            || ownStatus == BEHAVIOR_STATUS_FINISHED) {
        if (currentState->IsActive()) {
            currentState->InternalExit(bot, currentTime);
        }
        return ownStatus;
    }
    const behaviorStatus_t childStatus =
        currentState->InternalThink(bot, currentTime);
    if (childStatus == BEHAVIOR_STATUS_ERROR
            || childStatus == BEHAVIOR_STATUS_FINISHED) {
        currentState->InternalExit(bot, currentTime);
    }
    return childStatus;
}

// Retail symbol: ?InternalGetPriority@idBehaviorSelectorLooping@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3B688, RVA: 0x00B3B688
behaviorPriority_t idBehaviorSelectorLooping::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (idBehaviorState::InternalGetPriority(bot, currentTime)
            == BEHAVIOR_PRIORITY_NULL) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (IsActive() && currentState != nullptr) {
        return currentState->InternalGetPriority(bot, currentTime);
    }
    currentState = nullptr;
    for (idBehaviorState* const state : children) {
        if (state != nullptr) {
            const behaviorPriority_t priority =
                state->InternalGetPriority(bot, currentTime);
            if (priority > BEHAVIOR_PRIORITY_NULL) {
                currentState = state;
                return priority;
            }
        }
    }
    return BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?InternalThink@idBehaviorSelectorLooping@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3B758, RVA: 0x00B3B758
behaviorStatus_t idBehaviorSelectorLooping::InternalThink(
        idBot* const bot, const int currentTime) {
    const behaviorStatus_t ownStatus =
        idBehaviorState::InternalThink(bot, currentTime);
    if (ownStatus == BEHAVIOR_STATUS_ERROR
            || ownStatus == BEHAVIOR_STATUS_FINISHED) {
        return ownStatus;
    }
    int excludedIndex = -1;
    if (currentState != nullptr
            && currentState->InternalGetPriority(bot, currentTime)
                == BEHAVIOR_PRIORITY_NULL) {
        excludedIndex = GetStateIndex(currentState);
        currentState = nullptr;
    }
    const bool maySelect = currentState == nullptr
        || currentState->CheckStateFlag(BEHAVIOR_STATE_ERROR)
        || currentState->IsInterruptable();
    if (maySelect) {
        for (int index = 0; index < NumChildren(); ++index) {
            if (index == excludedIndex) {
                continue;
            }
            idBehaviorState* const candidate = Child(index);
            if (candidate != nullptr
                    && candidate->InternalGetPriority(bot, currentTime)
                        > BEHAVIOR_PRIORITY_NULL) {
                currentState = candidate;
                break;
            }
        }
        if (currentState != nullptr) {
            for (idBehaviorState* const state : children) {
                if (state != nullptr && state != currentState
                        && state->IsActive()) {
                    state->InternalExit(bot, currentTime);
                }
            }
        }
    }
    if (currentState == nullptr) {
        return BEHAVIOR_STATUS_FINISHED;
    }
    if (!currentState->IsActive()) {
        currentState->InternalEnter(bot, currentTime);
    }
    const behaviorStatus_t childStatus =
        currentState->InternalThink(bot, currentTime);
    if (childStatus == BEHAVIOR_STATUS_ERROR) {
        currentState->InternalExit(bot, currentTime);
        return BEHAVIOR_STATUS_ERROR;
    }
    if (childStatus == BEHAVIOR_STATUS_FINISHED) {
        currentState->InternalExit(bot, currentTime);
        currentState = nullptr;
        return BEHAVIOR_STATUS_RUNNING;
    }
    return childStatus;
}

// Retail symbol: ?InternalGetPriority@idBehaviorSelectorBest@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3B9F0, RVA: 0x00B3B9F0
behaviorPriority_t idBehaviorSelectorBest::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (idBehaviorState::InternalGetPriority(bot, currentTime)
            == BEHAVIOR_PRIORITY_NULL) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (IsActive() && currentState != nullptr) {
        return currentState->InternalGetPriority(bot, currentTime);
    }
    behaviorPriority_t bestPriority = BEHAVIOR_PRIORITY_NULL;
    currentState = nullptr;
    for (idBehaviorState* const state : children) {
        if (state == nullptr) {
            continue;
        }
        const behaviorPriority_t priority =
            state->InternalGetPriority(bot, currentTime);
        if (priority > bestPriority) {
            bestPriority = priority;
            currentState = state;
        }
    }
    return bestPriority;
}

// Retail symbol: ?InternalThink@idBehaviorSelectorBestLooping@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3BAD8, RVA: 0x00B3BAD8
behaviorStatus_t idBehaviorSelectorBestLooping::InternalThink(
        idBot* const bot, const int currentTime) {
    const behaviorStatus_t ownStatus =
        idBehaviorState::InternalThink(bot, currentTime);
    if (ownStatus == BEHAVIOR_STATUS_ERROR
            || ownStatus == BEHAVIOR_STATUS_FINISHED) {
        return ownStatus;
    }
    int excludedIndex = -1;
    if (currentState != nullptr
            && currentState->InternalGetPriority(bot, currentTime)
                == BEHAVIOR_PRIORITY_NULL) {
        excludedIndex = GetStateIndex(currentState);
        currentState = nullptr;
    }
    const bool maySelect = currentState == nullptr
        || currentState->CheckStateFlag(BEHAVIOR_STATE_ERROR)
        || currentState->IsInterruptable();
    if (maySelect) {
        behaviorPriority_t bestPriority = BEHAVIOR_PRIORITY_NULL;
        for (int index = 0; index < NumChildren(); ++index) {
            if (index == excludedIndex) {
                continue;
            }
            idBehaviorState* const candidate = Child(index);
            if (candidate == nullptr) {
                continue;
            }
            const behaviorPriority_t priority =
                candidate->InternalGetPriority(bot, currentTime);
            if (priority > bestPriority) {
                bestPriority = priority;
                currentState = candidate;
            }
        }
        if (currentState != nullptr) {
            for (idBehaviorState* const state : children) {
                if (state != nullptr && state != currentState
                        && state->IsActive()) {
                    state->InternalExit(bot, currentTime);
                }
            }
        }
    }
    if (currentState == nullptr) {
        return BEHAVIOR_STATUS_FINISHED;
    }
    if (!currentState->IsActive()) {
        currentState->InternalEnter(bot, currentTime);
    }
    const behaviorStatus_t childStatus =
        currentState->InternalThink(bot, currentTime);
    if (childStatus == BEHAVIOR_STATUS_ERROR) {
        return BEHAVIOR_STATUS_ERROR;
    }
    if (childStatus == BEHAVIOR_STATUS_FINISHED) {
        currentState->InternalExit(bot, currentTime);
        currentState = nullptr;
        return BEHAVIOR_STATUS_RUNNING;
    }
    return BEHAVIOR_STATUS_RUNNING;
}

// Retail symbol: ?InternalGetPriority@idBehaviorSequence@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3BD50, RVA: 0x00B3BD50
behaviorPriority_t idBehaviorSequence::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (idBehaviorState::InternalGetPriority(bot, currentTime)
            == BEHAVIOR_PRIORITY_NULL) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (IsActive() && currentState != nullptr) {
        return currentState->InternalGetPriority(bot, currentTime);
    }
    currentState = nullptr;
    currentStateIndex = -1;
    for (int index = 0; index < NumChildren(); ++index) {
        idBehaviorState* const state = Child(index);
        if (state == nullptr) {
            return BEHAVIOR_PRIORITY_NULL;
        }
        const behaviorPriority_t priority =
            state->InternalGetPriority(bot, currentTime);
        if (priority == BEHAVIOR_PRIORITY_NULL) {
            return BEHAVIOR_PRIORITY_NULL;
        }
        if (!state->CheckStateFlag(BEHAVIOR_STATE_SEQUENCE_COMPLETE)) {
            currentState = state;
            currentStateIndex = index;
            return priority;
        }
    }
    return BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?InternalThink@idBehaviorSequence@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3BE30, RVA: 0x00B3BE30
behaviorStatus_t idBehaviorSequence::InternalThink(
        idBot* const bot, const int currentTime) {
    const behaviorStatus_t ownStatus =
        idBehaviorState::InternalThink(bot, currentTime);
    if (ownStatus == BEHAVIOR_STATUS_ERROR
            || ownStatus == BEHAVIOR_STATUS_FINISHED) {
        return ownStatus;
    }
    if (currentState == nullptr) {
        return BEHAVIOR_STATUS_FINISHED;
    }
    if (!currentState->IsActive()) {
        currentState->InternalEnter(bot, currentTime);
    }
    const behaviorStatus_t childStatus =
        currentState->InternalThink(bot, currentTime);
    if (childStatus == BEHAVIOR_STATUS_ERROR) {
        return BEHAVIOR_STATUS_ERROR;
    }
    if (childStatus != BEHAVIOR_STATUS_FINISHED) {
        return childStatus;
    }
    currentState->InternalExit(bot, currentTime);
    currentState = nullptr;
    for (int index = currentStateIndex + 1; index < NumChildren(); ++index) {
        idBehaviorState* const candidate = Child(index);
        if (candidate == nullptr
                || candidate->InternalGetPriority(bot, currentTime)
                    == BEHAVIOR_PRIORITY_NULL) {
            return BEHAVIOR_STATUS_FINISHED;
        }
        if (!candidate->CheckStateFlag(BEHAVIOR_STATE_SEQUENCE_COMPLETE)) {
            currentState = candidate;
            currentStateIndex = index;
            return BEHAVIOR_STATUS_RUNNING;
        }
    }
    return BEHAVIOR_STATUS_FINISHED;
}

// Retail symbol: ?InternalGetPriority@idBehaviorSequenceRandom@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3BF90, RVA: 0x00B3BF90
behaviorPriority_t idBehaviorSequenceRandom::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (idBehaviorState::InternalGetPriority(bot, currentTime)
            == BEHAVIOR_PRIORITY_NULL) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (IsActive() && currentState != nullptr) {
        return currentState->InternalGetPriority(bot, currentTime);
    }
    if (runChildren.empty()) {
        ResetRunChildren();
    }
    while (!runChildren.empty()) {
        const int runIndex = RandomInt(0,
            static_cast<int>(runChildren.size()) - 1);
        const int childIndex = runChildren[runIndex];
        idBehaviorState* const candidate = Child(childIndex);
        runChildren[runIndex] = runChildren.back();
        runChildren.pop_back();
        if (candidate == nullptr) {
            continue;
        }
        const behaviorPriority_t priority =
            candidate->InternalGetPriority(bot, currentTime);
        if (priority > BEHAVIOR_PRIORITY_NULL) {
            currentState = candidate;
            currentStateIndex = childIndex;
            return priority;
        }
    }
    return BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ?InternalThink@idBehaviorSequenceRandom@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA: 0x82B3C060, RVA: 0x00B3C060
behaviorStatus_t idBehaviorSequenceRandom::InternalThink(
        idBot* const bot, const int currentTime) {
    const behaviorStatus_t ownStatus =
        idBehaviorState::InternalThink(bot, currentTime);
    if (ownStatus == BEHAVIOR_STATUS_ERROR
            || ownStatus == BEHAVIOR_STATUS_FINISHED) {
        return ownStatus;
    }
    if (currentState == nullptr) {
        return BEHAVIOR_STATUS_FINISHED;
    }
    if (!currentState->IsActive()) {
        currentState->InternalEnter(bot, currentTime);
    }
    const behaviorStatus_t childStatus =
        currentState->InternalThink(bot, currentTime);
    if (childStatus == BEHAVIOR_STATUS_ERROR) {
        return BEHAVIOR_STATUS_ERROR;
    }
    if (childStatus != BEHAVIOR_STATUS_FINISHED) {
        return childStatus;
    }
    currentState->InternalExit(bot, currentTime);
    currentState = nullptr;
    while (!runChildren.empty()) {
        const int runIndex = RandomInt(0,
            static_cast<int>(runChildren.size()) - 1);
        const int childIndex = runChildren[runIndex];
        runChildren[runIndex] = runChildren.back();
        runChildren.pop_back();
        idBehaviorState* const candidate = Child(childIndex);
        if (candidate != nullptr
                && candidate->InternalGetPriority(bot, currentTime)
                    > BEHAVIOR_PRIORITY_NULL) {
            currentState = candidate;
            currentStateIndex = childIndex;
            return BEHAVIOR_STATUS_RUNNING;
        }
    }
    return BEHAVIOR_STATUS_FINISHED;
}

// Retail symbol: ?InternalExit@idBehaviorSequenceRandom@@MAAXPAVidBot@@H@Z
// EA: 0x82B3C1F8, RVA: 0x00B3C1F8
void idBehaviorSequenceRandom::InternalExit(
        idBot* const bot, const int currentTime) {
    runChildren.clear();
    idBehaviorSequence::InternalExit(bot, currentTime);
}

// Retail symbol: ?DebugRenderGui@idBehaviorState@@MBAXPBVidBot@@AAVidGuiListBox@@H@Z
// EA: 0x82B3C278, RVA: 0x00B3C278
void idBehaviorState::DebugRenderGui(const idBot* const bot,
        idGuiListBox* const gui, const int indent) {
    if (gui == nullptr || g_services == nullptr) {
        return;
    }
    idStr debugText;
    GetDebugString(debugText);
    g_services->AddDebugRow(*gui, indent, GetClassName(),
        debugText.c_str(), IsUseAble(bot), IsActive());
}

// Retail symbol: ??0idBehaviorComposite@@QAA@XZ
// EA: 0x82B3C4B0, RVA: 0x00B3C4B0
idBehaviorComposite::idBehaviorComposite() = default;

// Retail symbol: ??1idBehaviorComposite@@UAA@XZ
// EA: 0x82B3C558, RVA: 0x00B3C558
idBehaviorComposite::~idBehaviorComposite() {
    children.clear();
}

// Retail symbol: ?DebugRenderGui@idBehaviorComposite@@UBAXPBVidBot@@AAVidGuiListBox@@H@Z
// EA: 0x82B3C600, RVA: 0x00B3C600
void idBehaviorComposite::DebugRenderGui(const idBot* const bot,
        idGuiListBox* const gui, const int indent) {
    idBehaviorState::DebugRenderGui(bot, gui, indent);
    for (idBehaviorState* const state : children) {
        if (state != nullptr) {
            state->DebugRenderGui(bot, gui, indent + 1);
        }
    }
}

// Retail symbol: ?DebugRenderGui@idBehaviorDecorator@@UBAXPBVidBot@@AAVidGuiListBox@@H@Z
// EA: 0x82B3C678, RVA: 0x00B3C678
void idBehaviorDecorator::DebugRenderGui(const idBot* const bot,
        idGuiListBox* const gui, const int indent) {
    idBehaviorState::DebugRenderGui(bot, gui, indent);
    if (child != nullptr && child->IsActive()) {
        child->DebugRenderGui(bot, gui, indent + 1);
    }
}

// Retail symbol: ??0idBehaviorParallel@@QAA@XZ
// EA: 0x82B3C6D8, RVA: 0x00B3C6D8
idBehaviorParallel::idBehaviorParallel() = default;

// Retail symbol: ??0idBehaviorParallelUntilFail@@QAA@XZ
// EA: 0x82B3C718, RVA: 0x00B3C718
idBehaviorParallelUntilFail::idBehaviorParallelUntilFail() = default;

// Retail symbol: ??0idBehaviorSelector@@QAA@XZ
// EA: 0x82B3C758, RVA: 0x00B3C758
idBehaviorSelector::idBehaviorSelector() : currentState(nullptr) {
}

// Retail symbol: ??1idBehaviorSelector@@UAA@XZ
// EA: 0x82B3C7A0, RVA: 0x00B3C7A0
idBehaviorSelector::~idBehaviorSelector() {
    currentState = nullptr;
}

// Retail symbol: ??0idBehaviorSelectorLooping@@QAA@XZ
// EA: 0x82B3C7B8, RVA: 0x00B3C7B8
idBehaviorSelectorLooping::idBehaviorSelectorLooping() = default;

// Retail symbol: ??0idBehaviorSelectorBest@@QAA@XZ
// EA: 0x82B3C800, RVA: 0x00B3C800
idBehaviorSelectorBest::idBehaviorSelectorBest() = default;

// Retail symbol: ??0idBehaviorSelectorBestLooping@@QAA@XZ
// EA: 0x82B3C848, RVA: 0x00B3C848
idBehaviorSelectorBestLooping::idBehaviorSelectorBestLooping() = default;

// Retail symbol: ??0idBehaviorSelectorRandom@@QAA@XZ
// EA: 0x82B3C890, RVA: 0x00B3C890
idBehaviorSelectorRandom::idBehaviorSelectorRandom() = default;

// Retail symbol: ?InternalGetPriority@idBehaviorSelectorRandom@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA: 0x82B3C8E0, RVA: 0x00B3C8E0
behaviorPriority_t idBehaviorSelectorRandom::InternalGetPriority(
        idBot* const bot, const int currentTime) {
    if (idBehaviorState::InternalGetPriority(bot, currentTime)
            == BEHAVIOR_PRIORITY_NULL) {
        return BEHAVIOR_PRIORITY_NULL;
    }
    if (IsActive() && currentState != nullptr) {
        return currentState->InternalGetPriority(bot, currentTime);
    }
    std::vector<int> candidates(static_cast<std::size_t>(NumChildren()));
    std::iota(candidates.begin(), candidates.end(), 0);
    while (!candidates.empty()) {
        const int candidateIndex = RandomInt(
            0, static_cast<int>(candidates.size()) - 1);
        idBehaviorState* const candidate =
            Child(candidates[candidateIndex]);
        candidates[candidateIndex] = candidates.back();
        candidates.pop_back();
        if (candidate == nullptr) {
            continue;
        }
        const behaviorPriority_t priority =
            candidate->InternalGetPriority(bot, currentTime);
        if (priority > BEHAVIOR_PRIORITY_NULL) {
            currentState = candidate;
            return priority;
        }
    }
    return BEHAVIOR_PRIORITY_NULL;
}

// Retail symbol: ??0idBehaviorSequence@@QAA@XZ
// EA: 0x82B3CAB0, RVA: 0x00B3CAB0
idBehaviorSequence::idBehaviorSequence()
    : currentStateIndex(-1), currentState(nullptr) {
}

// Retail symbol: ??1idBehaviorSequence@@UAA@XZ
// EA: 0x82B3CB00, RVA: 0x00B3CB00
idBehaviorSequence::~idBehaviorSequence() {
    currentState = nullptr;
}

// Retail symbol: ??0idBehaviorSequenceRandom@@QAA@XZ
// EA: 0x82B3CB20, RVA: 0x00B3CB20
idBehaviorSequenceRandom::idBehaviorSequenceRandom() = default;

// Retail symbol: ??1idBehaviorSequenceRandom@@UAA@XZ
// EA: 0x82B3CBD0, RVA: 0x00B3CBD0
idBehaviorSequenceRandom::~idBehaviorSequenceRandom() {
    runChildren.clear();
    currentState = nullptr;
}

// Retail symbol: ??0idBehaviorTree@@QAA@XZ
// EA: 0x82B3CC50, RVA: 0x00B3CC50
idBehaviorTree::idBehaviorTree() : numFramesWithNoActiveChildren(0) {
}

// Retail symbol: ??1idBehaviorTree@@UAA@XZ
// EA: 0x82B3CC98, RVA: 0x00B3CC98
idBehaviorTree::~idBehaviorTree() = default;

// Retail symbol: ?AppendState@idBehaviorComposite@@QAAXPAVidBehaviorTree@@PAVidBehaviorState@@@Z
// EA: 0x82B3CD08, RVA: 0x00B3CD08
void idBehaviorComposite::AppendState(
        idBehaviorTree*, idBehaviorState* const newState) {
    if (newState != nullptr) {
        children.push_back(newState);
    }
}

void idBehaviorState::InternalInit(
        idBot* const bot, const int currentTime) {
    Init(bot, currentTime);
}

idBehaviorState* idBehaviorState::FindState(const idTypeInfo& type) {
    return SameOrDerivedType(*this, type) ? this : nullptr;
}

bool idBehaviorState::IsInterruptable() const {
    return (stateFlags & (BEHAVIOR_STATE_NON_INTERRUPTIBLE
        | BEHAVIOR_STATE_NON_INTERRUPTIBLE_ALT)) == 0;
}

void idBehaviorState::SetEnabled(const bool enabled) {
    if (enabled) {
        stateFlags |= BEHAVIOR_STATE_ENABLED;
    } else {
        stateFlags &= ~BEHAVIOR_STATE_ENABLED;
    }
}

idBehaviorState* idBehaviorComposite::Child(const int index) const {
    return index >= 0 && index < NumChildren()
        ? children[static_cast<std::size_t>(index)] : nullptr;
}

void idBehaviorSequenceRandom::ResetRunChildren() {
    runChildren.resize(static_cast<std::size_t>(NumChildren()));
    std::iota(runChildren.begin(), runChildren.end(), 0);
}
