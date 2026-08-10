#include "ai2.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>

namespace {

idAI2CoreServices* Services(idAI2& ai) {
    return ai.core.services;
}

const idAI2CoreServices* Services(const idAI2& ai) {
    return ai.core.services;
}

int EventFlags(const idAIEvent::aiEventClass_t flags) {
    return static_cast<int>(flags);
}

bool EqualsIgnoreCase(const char* left, const char* right) {
    if (left == nullptr || right == nullptr) {
        return left == right;
    }
    while (*left != '\0' && *right != '\0') {
        if (std::tolower(static_cast<unsigned char>(*left))
                != std::tolower(static_cast<unsigned char>(*right))) {
            return false;
        }
        ++left;
        ++right;
    }
    return *left == *right;
}

} // namespace

// Retail symbol: ?GetEntranceAnim@idAI2@@QBA?AW4overrideAnim_t@@XZ
// EA: 0x829EFC28, RVA: 0x009EFC28
overrideAnim_t idAI2::GetEntranceAnim() const {
    return core.entranceAnim;
}

// Retail symbol: ?ApplyDamage@idAI2@@UAAXHHPBVidDeclDamage@@@Z
// EA: 0x829EFC30, RVA: 0x009EFC30
void idAI2::ApplyDamage(const int physId, const int bodyId,
        const idDeclDamage* const damageDecl) {
    if (damageDecl != nullptr && Services(*this) != nullptr) {
        Services(*this)->ApplyDamage(
            *this, physId, bodyId, *damageDecl, 1.0f);
    }
}

// Retail symbol: ?SetModelByName@idAI2@@UAAXPBD@Z
// EA: 0x829EFCA8, RVA: 0x009EFCA8
void idAI2::SetModelByName(const char* const modelName) {
    if (Services(*this) == nullptr) {
        return;
    }
    SetModel(Services(*this)->AllocRenderModel(modelName));
}

// Retail symbol: ?PerceptionFlagIsSet@idAI2@@QBA_NH@Z
// EA: 0x829EFD10, RVA: 0x009EFD10
bool idAI2::PerceptionFlagIsSet(const int flags) const {
    return (core.perceptionFlags & flags) != 0;
}

// Retail symbol: ?SaveFSM@idAI2@@QBAXAAVidFile_String@@PBD1@Z
// EA: 0x829EFD28, RVA: 0x009EFD28
void idAI2::SaveFSM(idFile_String& file, const char* const fsmName,
        const char* const indent) const {
    const idAI2CoreServices* const services = Services(*this);
    if (services == nullptr) {
        return;
    }
    if (!services->SaveFSM(*this, file, fsmName, indent)) {
        char message[256];
        std::snprintf(message, sizeof(message),
            "No FSM named '%s' was found.\n",
            fsmName != nullptr ? fsmName : "");
        services->Print(message);
    }
}

// Retail symbol: ?StartDeathFade@idAI2@@QAAXXZ
// EA: 0x829EFD98, RVA: 0x009EFD98
void idAI2::StartDeathFade() {
    core.deathFadeOutTime = core.bodyFadeTime;
}

// Retail symbol: ?ActivateItemsOnDeath@idAI2@@QAAXXZ
// EA: 0x829EFDA8, RVA: 0x009EFDA8
void idAI2::ActivateItemsOnDeath() {
    if (Services(*this) != nullptr) {
        Services(*this)->ActivateItemsOnDeath(*this);
    }
}

// Retail symbol: ?GetValidMeleeTypes@idAI2@@QBAHH@Z
// EA: 0x829EFDF0, RVA: 0x009EFDF0
int idAI2::GetValidMeleeTypes(const int mask) const {
    return (core.crouching ? core.crouchingMeleeTypes
                           : core.standingMeleeTypes) & mask;
}

// Retail symbol: ?GetCrosshairIconDistance@idAI2@@UBAMXZ
// EA: 0x829EFE48, RVA: 0x009EFE48
float idAI2::GetCrosshairIconDistance() const {
    return 160.0f;
}

// Retail symbol: ?CanReceiveAIEvents@idAI2@@UBA_NH@Z
// EA: 0x829EFE58, RVA: 0x009EFE58
bool idAI2::CanReceiveAIEvents(const int currentTime) const {
    return !core.relaxedChatter && currentTime >= core.nextAIEventTime;
}

// Retail symbol: ?GetEventResponseFlags@idAI2@@UBAHXZ
// EA: 0x829EFEC0, RVA: 0x009EFEC0
int idAI2::GetEventResponseFlags() const {
    return (core.eventOverloadEnableFlags | core.eventFlags)
        & ~core.eventOverloadDisableFlags;
}

// Retail symbol: ?RespondsToAIEvent@idAI2@@UBA_NPBVidAIEvent@@@Z
// EA: 0x829EFEF0, RVA: 0x009EFEF0
bool idAI2::RespondsToAIEvent(const idAIEvent* const event) const {
    return event != nullptr && Services(*this) != nullptr
        && (GetEventResponseFlags()
            & Services(*this)->GetAIEventClass(*event)) != 0;
}

// Retail symbol: ?DeactivateExtendedClipModel@idAI2@@QAAXXZ
// EA: 0x829EFF48, RVA: 0x009EFF48
void idAI2::DeactivateExtendedClipModel() {
    void* const model = core.extendedClipModel;
    core.extendedClipModelStatus = 0;
    core.extendedClipModelEndTime = 0;
    if (model != nullptr && Services(*this) != nullptr) {
        Services(*this)->DeleteClipModel(*this, model);
    }
    core.extendedClipModel = nullptr;
}

// Retail symbol: ?ShouldAimAtEnemyWhileMoving@idAI2@@QAA_NXZ
// EA: 0x829EFFA8, RVA: 0x009EFFA8
bool idAI2::ShouldAimAtEnemyWhileMoving() const {
    return core.useMoveFSM;
}

// Retail symbol: ?BestDiveOrDodge@idAI2@@QBA?AW4aiTransCode_t@idAIStateTransition@@_N000000@Z
// EA: 0x829EFFB8, RVA: 0x009EFFB8
int idAI2::BestDiveOrDodge(const bool leftDodge,
        const bool leftDive, const bool rightDodge,
        const bool rightDive, const bool forwardDive,
        const bool backwardDive, const bool preferLeft) const {
    if (leftDodge || rightDodge) {
        if (leftDodge && rightDodge) {
            return preferLeft ? 300 : 301;
        }
        return leftDodge ? 300 : 301;
    }
    if (leftDive || rightDive) {
        if (leftDive && rightDive) {
            return preferLeft ? 302 : 303;
        }
        return leftDive ? 302 : 303;
    }
    if (forwardDive) {
        return 304;
    }
    return backwardDive ? 305 : 0;
}

// Retail symbol: ?SetMovePushStatus@idAI2@@QAAXW4aiMovePushStatus_t@@H@Z
// EA: 0x829F0088, RVA: 0x009F0088
void idAI2::SetMovePushStatus(const aiMovePushStatus_t newStatus,
        const int frameCount) {
    const int status = static_cast<int>(newStatus);
    core.movePushStatus = status;
    core.movePushEndTime = status == 0 ? 0
        : core.currentTime + frameCount * core.millisecondsPerFrame;
    const bool pushesPlayers = status == 2 || status == 3;
    const int playerBit = 0x8000;
    core.physicsClipMasks[0] = pushesPlayers
        ? core.physicsClipMasks[0] & ~playerBit
        : core.physicsClipMasks[0] | playerBit;
    core.configuredClipMask = pushesPlayers
        ? core.configuredClipMask & ~playerBit
        : core.configuredClipMask | playerBit;
}

// Retail symbol: ?SetWorldCollision@idAI2@@QAAX_N@Z
// EA: 0x829F0140, RVA: 0x009F0140
void idAI2::SetWorldCollision(const bool collideWithWorld) {
    if (core.physicsClipModelCount == 1) {
        core.physicsClipMasks[0] = collideWithWorld
            ? core.configuredClipMask : 0;
    } else if (core.physicsClipModelCount == 2) {
        core.physicsClipMasks[0] = collideWithWorld
            ? core.configuredClipMask : 0;
        core.physicsClipMasks[1] = 0;
    }
}

// Retail symbol: ?CalcTurnRadius@idAI2@@QBAMMM@Z
// EA: 0x829F0258, RVA: 0x009F0258
float idAI2::CalcTurnRadius(const float speed,
        const float turnRate) const {
    constexpr float kTwoPi = 6.2831853071795864769f;
    return turnRate == 0.0f ? 0.0f
        : (360.0f / turnRate) * speed / kTwoPi;
}

// Retail symbol: ?GetFacialAnimationSet@idAI2@@EAAPBVidDeclFacialAnimationSet@@XZ
// EA: 0x829F0288, RVA: 0x009F0288
const idDeclFacialAnimationSet* idAI2::GetFacialAnimationSet() const {
    return core.currentFacialAnimationSet != nullptr
        ? core.currentFacialAnimationSet
        : core.defaultFacialAnimationSet;
}

// Retail symbol: ?SetInteracting@idAI2@@QAAX_N@Z
// EA: 0x829F02A0, RVA: 0x009F02A0
void idAI2::SetInteracting(const bool interacting) {
    core.interacting = interacting;
    if (Services(*this) != nullptr) {
        Services(*this)->ResetSpecifiedInteractAI(*this);
    }
}

// Retail symbol: ?Draw@idAI2@@UAA_NPAVidPlayer@@@Z
// EA: 0x829F02C8, RVA: 0x009F02C8
bool idAI2::Draw(idEntity* const player) {
    if (Services(*this) != nullptr) {
        Services(*this)->DrawControlCamera(*this, player);
    }
    return true;
}

// Retail symbol: ?AlertCycleToSubWeb@idAI2@@QBA?AW4aiSubWeb_t@@W4alertCycle_t@@@Z
// EA: 0x829F02F8, RVA: 0x009F02F8
aiSubWeb_t idAI2::AlertCycleToSubWeb(
        const alertCycle_t cycle) const {
    // The retail table is indexed by the complete 0..10 alert-cycle range.
    static const int map[11] = {
        0, 0, 3, 1, 4, 8, 8, 9, 0, 19, 0
    };
    const int index = static_cast<int>(cycle);
    return static_cast<aiSubWeb_t>(
        index >= 0 && index < 11 ? map[index] : 0);
}

// Retail symbol: ?GetAlertCycleFSM@idAI2@@QBAPBVidFiniteStateMachine@@XZ
// EA: 0x829F0320, RVA: 0x009F0320
const idFiniteStateMachine* idAI2::GetAlertCycleFSM() const {
    return Services(*this) != nullptr
        ? Services(*this)->GetAlertCycleFSM(
            const_cast<idAI2&>(*this))
        : nullptr;
}

// Retail symbol: ?GetAlertCycleFSM@idAI2@@QAAPAVidFiniteStateMachine@@XZ
// EA: 0x829F0340, RVA: 0x009F0340
idFiniteStateMachine* idAI2::GetAlertCycleFSM() {
    return Services(*this) != nullptr
        ? Services(*this)->GetAlertCycleFSM(*this) : nullptr;
}

// Retail symbol: ?SetEventOverloadEnableFlags@idAI2@@UAAXW4aiEventClass_t@idAIEvent@@@Z
// EA: 0x829F0360, RVA: 0x009F0360
void idAI2::SetEventOverloadEnableFlags(
        const idAIEvent::aiEventClass_t flags) {
    core.eventOverloadEnableFlags = EventFlags(flags);
}

// Retail symbol: ?SetEventOverloadDisableFlags@idAI2@@UAAXW4aiEventClass_t@idAIEvent@@@Z
// EA: 0x829F0370, RVA: 0x009F0370
void idAI2::SetEventOverloadDisableFlags(
        const idAIEvent::aiEventClass_t flags) {
    core.eventOverloadDisableFlags = EventFlags(flags);
}

// Retail symbol: ?EnableAIEventResponse@idAI2@@UAAXW4aiEventClass_t@idAIEvent@@@Z
// EA: 0x829F0380, RVA: 0x009F0380
void idAI2::EnableAIEventResponse(
        const idAIEvent::aiEventClass_t flags) {
    core.eventFlags |= EventFlags(flags);
}

// Retail symbol: ?DisableAIEventResponse@idAI2@@UAAXW4aiEventClass_t@idAIEvent@@@Z
// EA: 0x829F0398, RVA: 0x009F0398
void idAI2::DisableAIEventResponse(
        const idAIEvent::aiEventClass_t flags) {
    core.eventFlags &= ~EventFlags(flags);
}

// Retail symbol: ?IsFSMActive@idAI2@@QBA_NABVidTypeInfo@@@Z
// EA: 0x829F03B0, RVA: 0x009F03B0
bool idAI2::IsFSMActive(const idTypeInfo& fsmType) const {
    const idFiniteStateMachine* const fsm = GetAlertCycleFSM();
    return fsm != nullptr && Services(*this) != nullptr
        && Services(*this)->IsChildFSMActive(*fsm, fsmType);
}

// Retail symbol: ?GetEnableHeadTracking@idAI2@@QBA_NXZ
// EA: 0x829F0420, RVA: 0x009F0420
bool idAI2::GetEnableHeadTracking() const {
    return core.enableHeadTracking;
}

// Retail symbol: ?SetCoverAction@idAI2@@QAAXW4coverAction_t@@@Z
// EA: 0x829F0428, RVA: 0x009F0428
void idAI2::SetCoverAction(const coverAction_t action) {
    core.coverAction = action;
}

// Retail symbol: ?RememberCoverActionToAvoid@idAI2@@QAAXW4coverAction_t@@@Z
// EA: 0x829F0438, RVA: 0x009F0438
void idAI2::RememberCoverActionToAvoid(
        const coverAction_t action) {
    switch (action) {
    case COVERACTION_BLINDFIRE_LEFT:
    case COVERACTION_FIRE_LEAN_LEFT:
    case COVERACTION_PEEK_LEFT:
    case COVERACTION_FIRE_STEP_LEFT:
        core.coverActionToAvoid = COVERACTION_FIRE_LEAN_LEFT;
        break;
    case COVERACTION_BLINDFIRE_RIGHT:
    case COVERACTION_FIRE_LEAN_RIGHT:
    case COVERACTION_PEEK_RIGHT:
    case COVERACTION_FIRE_STEP_RIGHT:
        core.coverActionToAvoid = COVERACTION_FIRE_LEAN_RIGHT;
        break;
    case COVERACTION_BLINDFIRE_OVER:
    case COVERACTION_FIRE_OVER:
    case COVERACTION_PEEK_OVER:
        core.coverActionToAvoid = COVERACTION_FIRE_OVER;
        break;
    default:
        break;
    }
}

// Retail symbol: ?SetIsRagdolling@idAI2@@QAAX_N@Z
// EA: 0x829F04D0, RVA: 0x009F04D0
void idAI2::SetIsRagdolling(const bool isRagdolling) {
    if (isRagdolling != core.ragdolling
            && Services(*this) != nullptr) {
        Services(*this)->SetDyingAI(*this, isRagdolling);
    }
    core.ragdolling = isRagdolling;
}

// Retail symbol: ?CheckForGoreByName@idAI2@@QAA_NABVidAtomicString@@@Z
// EA: 0x829F0558, RVA: 0x009F0558
bool idAI2::CheckForGoreByName(
        const idAtomicString& goreName) {
    return Services(*this) != nullptr
        && Services(*this)->CheckForGoreByName(*this, goreName);
}

// Retail symbol: ??0idAI2Patch1@@QAA@XZ
// EA: 0x829F0C98, RVA: 0x009F0C98
idAI2Patch1::idAI2Patch1()
    : bleedOutGroundQueryIndex(0), bleedOutHipQueryIndex(0),
      unclippedOffset(0.0f, 0.0f, 0.0f),
      aasPositionManagerConstructed(true), stuckStateConstructed(true) {
}

// Retail symbol: ?ApplyWaterEffects@idAI2@@UAAXHH@Z
// EA: 0x829F0DA0, RVA: 0x009F0DA0
void idAI2::ApplyWaterEffects(const int physId,
        const int bodyId) {
    idAI2CoreServices* const services = Services(*this);
    idAI2WaterEffectRuntime runtime;
    if (services == nullptr
            || !services->GetWaterEffectRuntime(
                *this, physId, runtime)
            || !runtime.valid) {
        return;
    }
    services->ApplyBaseWaterEffects(*this, physId, bodyId);
    idVec3 ripplePosition = runtime.ownerOrigin;
    ripplePosition.z = runtime.waterOrigin.z + runtime.waterTop;
    const float horizontalSpeed = std::sqrt(
        runtime.ownerVelocity.x * runtime.ownerVelocity.x
        + runtime.ownerVelocity.y * runtime.ownerVelocity.y);
    const float magnitude = -0.02f
        * std::min(horizontalSpeed, 1.0f);
    services->AddWaterRipple(ripplePosition, magnitude,
        runtime.ownerRadius * 0.5f);
}

// Retail symbol: ?InitEncounterGroup@idAI2@@AAAXXZ
// EA: 0x829F0F40, RVA: 0x009F0F40
void idAI2::InitEncounterGroup() {
    if (core.encounterGroupHandle != -1
            || Services(*this) == nullptr) {
        return;
    }
    const char* const name = core.encounterGroupName != nullptr
        && core.encounterGroupName[0] != '\0'
        ? core.encounterGroupName : core.entityName;
    core.encounterGroupHandle =
        Services(*this)->AddEncounterGroup(*this, name);
}

// Retail symbol: ?UsesScenePoints@idAI2@@QBA_NXZ
// EA: 0x829F0FD0, RVA: 0x009F0FD0
bool idAI2::UsesScenePoints() const {
    return core.usesScenePoints || core.behaviorUsesScenePoints;
}

// Retail symbol: ?Dropped@idAI2@@UAAXPAVidEntity@@PBVidDeclInventory@@@Z
// EA: 0x829F1010, RVA: 0x009F1010
void idAI2::Dropped(idEntity* const user,
        const idDeclInventory* const inventory) {
    core.inventoryDecl = inventory;
    if (Services(*this) != nullptr) {
        Services(*this)->AddDroppedStimulus(*this, user);
    }
}

// Retail symbol: ?GetModifiedSkill@idAI2@@QBA?AW4aiSkill_t@@XZ
// EA: 0x829F1098, RVA: 0x009F1098
aiSkill_t idAI2::GetModifiedSkill() const {
    return static_cast<aiSkill_t>(std::max(
        static_cast<int>(AISKILL_INCOMPETENT), std::min(
            static_cast<int>(AISKILL_LETHAL),
            core.gameDifficulty + core.skillOffset - 1)));
}

// Retail symbol: ?SetWalkState@idAI2@@UAAXW4walkState_t@@@Z
// EA: 0x829F1110, RVA: 0x009F1110
void idAI2::SetWalkState(const walkState_t state) {
    core.walkState = std::max(core.minimumWalkState,
        std::min(core.maximumWalkState, static_cast<int>(state)));
}

// Retail symbol: ?IsWeaponEquipped@idAI2@@QBA_NXZ
// EA: 0x829F1138, RVA: 0x009F1138
bool idAI2::IsWeaponEquipped() const {
    return core.equippedItems[2] != nullptr
            && core.equippedItemIsWeapon[2]
        || core.equippedItems[1] != nullptr
            && core.equippedItemIsWeapon[1];
}

// Retail symbol: ?FindWeaponToDraw@idAI2@@QBAPBVidWeapon@@XZ
// EA: 0x829F1240, RVA: 0x009F1240
const idWeapon* idAI2::FindWeaponToDraw() const {
    for (int slot = 14; slot >= 0; --slot) {
        if (core.equippedItems[slot] != nullptr
                && core.equippedItemIsWeapon[slot]
                && core.weaponHolsterSlots[slot] == slot) {
            return reinterpret_cast<const idWeapon*>(
                core.equippedItems[slot]);
        }
    }
    return nullptr;
}

// Retail symbol: ?GetEffectiveAccuracy@idAI2@@QBA?AW4aiAccuracy_t@@XZ
// EA: 0x829F12A8, RVA: 0x009F12A8
aiAccuracy_t idAI2::GetEffectiveAccuracy() const {
    if ((core.groupCondition & 0x2000) != 0) {
        return ACCURACY_PERFECT;
    }
    if (core.aimAccuracy != ACCURACY_FROMSKILL) {
        return core.aimAccuracy;
    }
    return core.skillAccuracy[GetModifiedSkill()];
}

// Retail symbol: ?SetModel@idAI2@@UAAXPAVidRenderModel@@@Z
// EA: 0x829F1330, RVA: 0x009F1330
void idAI2::SetModel(idRenderModel* const model) {
    idAI2CoreServices* const services = Services(*this);
    if (services == nullptr) {
        return;
    }
    services->PrepareModelChange(*this);
    idAI2ModelRuntime runtime = core.model;
    if (!services->SetActorModel(*this, model, runtime)) {
        return;
    }

    // Retail capability gates: mood=cap 4, lip-sync=cap 1,
    // gesture=cap 8, eye/blink setup=cap 2.
    const unsigned int requested = runtime.requestedCapabilities;
    const unsigned int available = runtime.modelCapabilities;
    unsigned int enabled = 0;
    if ((requested & 0x80u) != 0 && (available & 4u) != 0) {
        enabled |= 0x40u;
    }
    if ((requested & 0x40u) != 0 && (available & 1u) != 0) {
        enabled |= 0x20u;
    }
    if ((requested & 0x20u) != 0 && (available & 8u) != 0) {
        enabled |= 0x10u;
    }
    if ((requested & 0x10u) != 0 && (available & 2u) != 0) {
        enabled |= 0x08u;
    }
    if ((requested & 0x08u) != 0 && (available & 2u) != 0) {
        enabled |= 0x04u;
    }
    runtime.requestedCapabilities = enabled;
    core.model = runtime;
    services->ConfigureModelFocus(*this, core.model);
}

// Retail symbol: ?InitNav@idAI2@@AAAXXZ
// EA: 0x829F1678, RVA: 0x009F1678
void idAI2::InitNav() {
    if (core.navPowerEnabled && !core.multiplayer
            && core.hasNavigationDeclaration
            && Services(*this) != nullptr) {
        Services(*this)->InitNavigation(*this);
    }
}

// Retail symbol: ?InitMovement@idAI2@@AAAXXZ
// EA: 0x829F1710, RVA: 0x009F1710
void idAI2::InitMovement() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitMovement(*this);
    }
    // The runtime boundary consumes defaultMovementMode, maximumMoveSpeed,
    // accelerationRate, and decelerationRate from the core snapshot and
    // establishes a stopped AIMOVESTATUS_DONE/animation-speed move state.
}

// Retail symbol: ?SetPerceptionFlags@idAI2@@QAAXH_N@Z
// EA: 0x829F1788, RVA: 0x009F1788
void idAI2::SetPerceptionFlags(const int flags,
        const bool setFlag) {
    if (setFlag) {
        core.perceptionFlags |= flags;
        if (Services(*this) != nullptr) {
            Services(*this)->SetHoldFire(*this);
        }
    } else {
        core.perceptionFlags &= ~flags;
    }
}

// Retail symbol: ?IsInAvoidFSM@idAI2@@QBA_NXZ
// EA: 0x829F17E0, RVA: 0x009F17E0
bool idAI2::IsInAvoidFSM() const {
    return GetAlertCycleFSM() != nullptr && Services(*this) != nullptr
        && Services(*this)->IsCoreChildFSMActive(
            *this, AI2_CORE_FSM_AVOID);
}

// Retail symbol: ?IsInPlayerInteractFSM@idAI2@@QBA_NXZ
// EA: 0x829F1848, RVA: 0x009F1848
bool idAI2::IsInPlayerInteractFSM() const {
    return GetAlertCycleFSM() != nullptr && Services(*this) != nullptr
        && Services(*this)->IsCoreChildFSMActive(
            *this, AI2_CORE_FSM_PLAYER_INTERACT);
}

// Retail symbol: ?JobSync@idAI2@@UAAXXZ
// EA: 0x829F18B0, RVA: 0x009F18B0
void idAI2::JobSync() {
    if (Services(*this) != nullptr) {
        Services(*this)->JobSync(*this, core.showTrajectories);
    }
}

// Retail symbol: ?ShouldLeaveDormancy@idAI2@@UAA_NXZ
// EA: 0x829F1918, RVA: 0x009F1918
bool idAI2::ShouldLeaveDormancy() const {
    return !core.dormancyEnabled || core.baseShouldLeaveDormancy
        || Services(*this) != nullptr
            && Services(*this)->BaseShouldLeaveDormancy(*this);
}

// Retail symbol: ?InternalCallEvent@idAI2@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA: 0x829F1938, RVA: 0x009F1938
idEventArg idAI2::InternalCallEvent(const idEventDef& event,
        const idEventArg* const args) {
    idEventArg result;
    if (event.type == EVENT_FSMEVENT) {
        if (Services(*this) != nullptr) {
            Services(*this)->ProcessFSMEvent(
                *this, result, event, args);
        }
    } else if (Services(*this) != nullptr) {
        Services(*this)->Print(
            "idAI2::InternalCallEvent() received a non-FSM event type.\n");
    }
    return result;
}

// Retail symbol: ?InternalRespondsTo@idAI2@@MBA_NABVidEventDef@@@Z
// EA: 0x829F19D8, RVA: 0x009F19D8
bool idAI2::InternalRespondsTo(const idEventDef& event) const {
    return event.type == EVENT_FSMEVENT && Services(*this) != nullptr
        && Services(*this)->ControllingFSMRespondsTo(*this, event);
}

// Retail symbol: ?CheckForOneShotKill@idAI2@@QAA_NPAVidEntity@@@Z
// EA: 0x829F1A50, RVA: 0x009F1A50
bool idAI2::CheckForOneShotKill(idEntity* const attacker) {
    if ((core.dropState != 1 && core.dropState != 2)
            || !core.torsoItemEquipped
            || core.ignoreDamageWhileDropping) {
        return false;
    }
    if (Services(*this) != nullptr
            && Services(*this)->IsPlayerEntity(attacker)) {
        return true;
    }
    core.randomSeed = core.randomSeed * 1664525u + 1013904223u;
    const float randomValue = static_cast<float>(
        (core.randomSeed >> 10) & 0x7FFFu) * 0.000030518509f;
    return randomValue < core.nonPlayerOneShotChance;
}

// Retail symbol: ?GetJointIndexFromTrace@idAI2@@UAA?AV?$idIndex@FW4invalidJointIndex_t@@@@Utrace_t@@@Z
// EA: 0x829F1B58, RVA: 0x009F1B58
idJointIndex idAI2::GetJointIndexFromTrace(
        const trace_t trace) const {
    return idJointIndex(Services(*this) != nullptr
        ? Services(*this)->JointIndexFromTrace(*this, trace) : -1);
}

// Retail symbol: ?ApplyFakeDamageImpulse@idAI2@@QAAXABVidVec3@@@Z
// EA: 0x829F1B90, RVA: 0x009F1B90
void idAI2::ApplyFakeDamageImpulse(const idVec3& impulse) {
    if (Services(*this) != nullptr) {
        Services(*this)->ApplyFakeDamageImpulse(
            *this, core.physicsOrigin, impulse);
    }
}

// Retail symbol: ?CheckPain@idAI2@@IAAXPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@2V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA: 0x829F1C30, RVA: 0x009F1C30
void idAI2::CheckPain(idEntity* const inflictor,
        idEntity* const attacker, const idDeclDamage* const damageDecl,
        const float damage, const idVec3& impactPoint,
        const idVec3& impactDirection, const idJointIndex jointIndex) {
    (void)inflictor;
    (void)damageDecl;
    (void)damage;
    (void)impactPoint;
    (void)impactDirection;
    (void)jointIndex;
    if (!core.actionScriptRunning && core.painStimulusEnabled
            && attacker != nullptr && Services(*this) != nullptr) {
        Services(*this)->AddPainStimulus(*this, attacker);
    }
}

// Retail symbol: ?DisableAnimatorsOnDeath@idAI2@@QAAXXZ
// EA: 0x829F1D58, RVA: 0x009F1D58
void idAI2::DisableAnimatorsOnDeath() {
    if (Services(*this) != nullptr) {
        Services(*this)->DisableAnimatorsOnDeath(*this);
    }
}

// Retail symbol: ?DoMeleeDamage@idAI2@@QAA_NV?$idIndex@FW4invalidJointIndex_t@@@@ABVidBounds@@PBVidDeclDamage@@PBVidDeclProjectileImpactEffect@@@Z
// EA: 0x829F1E50, RVA: 0x009F1E50
bool idAI2::DoMeleeDamage(const idJointIndex jointIndex,
        const idBounds& bounds, const idDeclDamage* const damageDecl,
        const idDeclProjectileImpactEffect* const impactEffect) {
    idAI2CoreServices* const services = Services(*this);
    idVec3 jointOrigin;
    if (services == nullptr
            || !services->GetMeleeJointOrigin(
                *this, jointIndex, jointOrigin)) {
        return false;
    }

    idBounds worldBounds = bounds;
    worldBounds[0] = worldBounds[0] + jointOrigin;
    worldBounds[1] = worldBounds[1] + jointOrigin;
    idEntity* targets[8] = {};
    const int targetCount = services->GetMeleeTargets(
        worldBounds, targets, 8);
    if (targetCount <= 0) {
        return false;
    }

    idVec3 impactDirection = jointOrigin - core.physicsOrigin;
    if (impactDirection.NormalizeFast() != 0.0f) {
        impactDirection = impactDirection
            - core.gravityNormal * impactDirection.Dot(core.gravityNormal);
        impactDirection.NormalizeFast();
    }
    for (int index = 0; index < targetCount && index < 8; ++index) {
        idEntity* const target = targets[index];
        if (target == nullptr
                || target == reinterpret_cast<idEntity*>(this)
                || services->IsDeadActor(*target)) {
            continue;
        }
        if (services->IsKickableDoor(*target)) {
            services->KickOpenDoor(*target, *this);
            continue;
        }
        if (impactEffect != nullptr) {
            const int materialId = core.actorClass == 2 ? 27 : 3;
            services->PlayMeleeImpact(*impactEffect, materialId,
                jointOrigin, -impactDirection, *target);
        }
        if (damageDecl != nullptr) {
            services->DamageMeleeTarget(
                *target, *this, *damageDecl, 1.0f);
        }
    }
    return true;
}

// Retail symbol: ?CanMelee@idAI2@@QBA_NXZ
// EA: 0x829F2228, RVA: 0x009F2228
bool idAI2::CanMelee() const {
    const int posture = core.crouching ? 1 : 0;
    return core.meleeDefinitionAvailable[posture]
        && core.behaviorCanMelee
        && (core.equippedItems[2] == nullptr
            || core.equippedWeaponFireIdle);
}

// Retail symbol: ?ExtrapolateMeleeTarget@idAI2@@QBAXABVidVec3@@0AAV2@@Z
// EA: 0x829F22D0, RVA: 0x009F22D0
void idAI2::ExtrapolateMeleeTarget(
        const idVec3& targetPosition, const idVec3& targetVelocity,
        idVec3& attackPosition) const {
    attackPosition = targetPosition
        + targetVelocity * core.meleeExtrapolate;
}

// Retail symbol: ?IsTargetInMeleeRange@idAI2@@QBA_NABVidVec3@@W4aiMelee_t@@@Z
// EA: 0x829F2318, RVA: 0x009F2318
bool idAI2::IsTargetInMeleeRange(
        const idVec3& targetPosition, const aiMelee_t meleeType) const {
    if (!core.behaviorCanMelee) {
        return false;
    }
    float maximumDistance = core.closeMeleeDistance;
    if ((meleeType & AIMELEE_LONG) != 0) {
        maximumDistance = std::max(
            maximumDistance, core.longMeleeDistance);
    }
    if ((meleeType & AIMELEE_MEDIUM) != 0) {
        maximumDistance = std::max(
            maximumDistance, core.mediumMeleeDistance);
    }
    if ((meleeType & AIMELEE_MOVING_FORWARD) != 0
            && (core.groupCondition & 8) == 0) {
        maximumDistance = std::max(
            maximumDistance, core.movingMeleeDistance);
    }
    const idVec3 offset = targetPosition - core.physicsOrigin;
    const float horizontalDistance = std::sqrt(
        offset.x * offset.x + offset.y * offset.y);
    return horizontalDistance <= maximumDistance
        && std::fabs(offset.z) < core.physicsBoundsHeight * 0.75f;
}

// Retail symbol: ?IsTargetInLeapAttackZone@idAI2@@QBA_NABVidVec3@@@Z
// EA: 0x829F24A0, RVA: 0x009F24A0
bool idAI2::IsTargetInLeapAttackZone(
        const idVec3& targetPosition) const {
    idVec3 direction = targetPosition - core.physicsOrigin;
    const float horizontalDistance = std::sqrt(
        direction.x * direction.x + direction.y * direction.y);
    if (horizontalDistance < core.minimumLeapAttackDistance
            || horizontalDistance > core.maximumLeapAttackDistance
            || direction.NormalizeFast() == 0.0f
            || std::fabs(direction.z) > 0.05f) {
        return false;
    }
    return core.bodyForward.Dot(direction) >= 0.95f;
}

// Retail symbol: ?MeleePreference@idAI2@@QBAHPBVidEntity@@@Z
// EA: 0x829F27E8, RVA: 0x009F27E8
int idAI2::MeleePreference(const idEntity* const target) const {
    if (Services(*this) == nullptr) {
        return 1;
    }
    const idAI2CoreTargetClass_t targetClass =
        Services(*this)->ClassifyTarget(target);
    return targetClass == AI2_CORE_TARGET_TURRET
            || targetClass == AI2_CORE_TARGET_ROBOT
        ? 32 : 1;
}

// Retail symbol: ?GetDesiredWalkStateForDistance@idAI2@@QBA?AW4walkState_t@@MW42@_N@Z
// EA: 0x829F2868, RVA: 0x009F2868
walkState_t idAI2::GetDesiredWalkStateForDistance(
        const float distance, const walkState_t maximumWalkState,
        const bool firedAt) const {
    const float crouchMaximum = (core.groupCondition & 8) != 0
        ? core.injuredCrouchMoveMaximum : core.crouchMoveMaximum;
    int desired = 1;
    if (core.sprintAllowed && distance > core.sprintMoveMinimum) {
        desired = 3;
    } else if (core.postureCrouched && distance < crouchMaximum) {
        desired = 1;
    } else if (distance > core.runMoveMinimum) {
        desired = 2;
    }
    if (firedAt && desired < 2 && core.runWhenFiredAt) {
        desired = 2;
    }
    if ((core.groupCondition & 8) != 0) {
        desired = 2;
    }
    return static_cast<walkState_t>(std::min(
        desired, static_cast<int>(maximumWalkState)));
}

// Retail symbol: ?HasTauntRage@idAI2@@QBA_NXZ
// EA: 0x829F2970, RVA: 0x009F2970
bool idAI2::HasTauntRage() const {
    for (const int chance : core.tauntRageChances) {
        if (chance > 0) {
            return true;
        }
    }
    return false;
}

// Retail symbol: ?HasAngryRage@idAI2@@QBA_NXZ
// EA: 0x829F29B8, RVA: 0x009F29B8
bool idAI2::HasAngryRage() const {
    for (const float chanceOrDistance : core.angryRageChances) {
        if (chanceOrDistance > 0.0f) {
            return true;
        }
    }
    return false;
}

// Retail symbol: ?ProvidesFormationCover@idAI2@@QBA_NXZ
// EA: 0x829F2A08, RVA: 0x009F2A08
bool idAI2::ProvidesFormationCover() const {
    return core.providesFormationCover;
}

// Retail symbol: ?GetUsableDistance@idAI2@@UBAMXZ
// EA: 0x829F2A18, RVA: 0x009F2A18
float idAI2::GetUsableDistance() const {
    return core.hasPlayerInteraction
        ? core.interactionApproachRadius : 160.0f;
}

// Retail symbol: ?TakedownWindoIsOpen@idAI2@@QBA_NXZ
// EA: 0x829F2A40, RVA: 0x009F2A40
bool idAI2::TakedownWindoIsOpen() const {
    if (core.equippedItems[2] != nullptr
            && core.equippedWeaponReloading) {
        return true;
    }
    return core.takedownWindowMaximumTime == -1
        || core.takedownWindowClosed != -1
            && core.currentTime <= core.takedownWindowClosed;
}

// Retail symbol: ?SetTakeDownWindow@idAI2@@QAAX_N@Z
// EA: 0x829F2AF8, RVA: 0x009F2AF8
void idAI2::SetTakeDownWindow(const bool setOpen) {
    core.takedownWindowClosed = setOpen
        ? core.currentTime + core.takedownWindowMaximumTime : -1;
}

// Retail symbol: ?PassMerchantTestCondition@idAI2@@QBA_NABVmerchantCondition_t@idConditionalMerchantInventoryDef@idAIEditable@@PBVidPlayer@@@Z
// EA: 0x829F2B88, RVA: 0x009F2B88
bool idAI2::PassMerchantTestCondition(
        const idAIEditable::idConditionalMerchantInventoryDef::
            merchantCondition_t& condition,
        const idPlayer* const player) const {
    using definition_t =
        idAIEditable::idConditionalMerchantInventoryDef;
    if (condition.condition == definition_t::MERCHANTCONDITION_AVAILABLE) {
        return true;
    }
    if (player == nullptr || Services(*this) == nullptr) {
        return false;
    }
    if (condition.condition
            == definition_t::MERCHANTCONDITION_NOTININVENTORY) {
        return condition.testInventory == nullptr
            || Services(*this)->PlayerInventoryCount(
                *player, *condition.testInventory) <= 0;
    }
    if (condition.condition
            == definition_t::MERCHANTCONDITION_PLAYERINVENTORY) {
        return condition.testInventory != nullptr
            && Services(*this)->PlayerInventoryCount(
                *player, *condition.testInventory) >= 1;
    }
    const int status = Services(*this)->PlayerJobStatus(
        *player, condition.jobDeclaration);
    if (status <= 0) {
        return false;
    }
    if (condition.condition
            == definition_t::MERCHANTCONDITION_JOB_ACCEPTED) {
        return status >= 2;
    }
    if (condition.condition
            == definition_t::MERCHANTCONDITION_JOB_READY) {
        return status >= 3;
    }
    if (condition.condition
            == definition_t::MERCHANTCONDITION_JOB_COMPLETE) {
        return status >= 5;
    }
    return true;
}

// Retail symbol: ?AddConditionalGoodList@idAI2@@QAAXH@Z
// EA: 0x829F2D18, RVA: 0x009F2D18
void idAI2::AddConditionalGoodList(const int index) {
    if (index < 0
            || index >= static_cast<int>(
                core.conditionalMerchantLists.size())) {
        return;
    }
    idAI2ConditionalMerchantList& list =
        core.conditionalMerchantLists[index];
    list.listGiven = true;
    if (Services(*this) == nullptr) {
        return;
    }
    for (const idDeclInventory* const item : list.goods) {
        if (item != nullptr) {
            Services(*this)->GiveMerchantItem(*this, *item, true);
        }
    }
}

// Retail symbol: ?ShouldAddDynamicGood@idAI2@@QBA_NPBVidPlayer@@H@Z
// EA: 0x829F2DD0, RVA: 0x009F2DD0
bool idAI2::ShouldAddDynamicGood(const idPlayer* const player,
        const int index) const {
    if (player == nullptr || Services(*this) == nullptr || index < 0
            || index >= static_cast<int>(
                core.dynamicMerchantGoods.size())) {
        return false;
    }
    const idAI2DynamicMerchantGood& good =
        core.dynamicMerchantGoods[index];
    if (good.inventory == nullptr || good.itemGiven && good.giveOnce) {
        return false;
    }
    if (good.singular && Services(*this)->PlayerInventoryCount(
            *player, *good.inventory) > 0) {
        return false;
    }
    if (good.requiredCompletedJob != nullptr
            && good.requiredCompletedJob[0] != '\0'
            && Services(*this)->PlayerJobStatus(
                *player, good.requiredCompletedJob) != 5) {
        return false;
    }
    return good.expiredJob == nullptr || good.expiredJob[0] == '\0'
        || Services(*this)->PlayerJobStatus(*player, good.expiredJob) < 3;
}

// Retail symbol: ?EverHasGoodsToSell@idAI2@@QBA_NPBVidPlayer@@@Z
// EA: 0x829F2EB8, RVA: 0x009F2EB8
bool idAI2::EverHasGoodsToSell(const idPlayer* const player) const {
    if (!core.conditionalMerchantLists.empty()
            || !core.dynamicMerchantGoods.empty()
            || core.specialDynamicMerchantGoodCount > 0) {
        return true;
    }
    return Services(*this) != nullptr
        && Services(*this)->MerchantInventoryForSale(*this, player) > 0;
}

// Retail symbol: ?HasGoodsToSellPlayerNeeds@idAI2@@QBA_NPBVidPlayer@@@Z
// EA: 0x829F2F30, RVA: 0x009F2F30
bool idAI2::HasGoodsToSellPlayerNeeds(
        const idPlayer* const player) const {
    return player != nullptr && Services(*this) != nullptr
        && Services(*this)->MerchantHasNeededGoods(*this, *player);
}

// Retail symbol: ?SetupFakePosition@idAI2@@QAAXPBVidEntity@@ABVidVec3@@@Z
// EA: 0x829F2FD8, RVA: 0x009F2FD8
void idAI2::SetupFakePosition(const idEntity* const instigator,
        const idVec3& fakePosition) {
    if (Services(*this) != nullptr) {
        Services(*this)->AddFakePositionStimulus(
            *this, instigator, fakePosition);
    }
}

// Retail symbol: ?OnAIEvent_VehicleSound@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x829F3058, RVA: 0x009F3058
void idAI2::OnAIEvent_VehicleSound(
        const idAIEventSound* const event) {
    if (event == nullptr || Services(*this) == nullptr) {
        return;
    }
    const float amount = Services(*this)->GetVehicleSoundStimulus(
        *this, *event) * core.hearingStimulusScale;
    Services(*this)->AddEventStimulus(*this,
        *reinterpret_cast<const idAIEvent*>(event), amount);
}

// Retail symbol: ?OnAIEvent_Body@idAI2@@AAAXPBVidAIEventSphere@@@Z
// EA: 0x829F3118, RVA: 0x009F3118
void idAI2::OnAIEvent_Body(const idAIEventSphere* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->PostAlertCycleEvent(*this,
            *reinterpret_cast<const idAIEvent*>(event), core.currentTime);
    }
}

// Retail symbol: ?OnAIEvent_PlayerInteraction@idAI2@@AAAXPBVidAIEventSphere@@@Z
// EA: 0x829F3188, RVA: 0x009F3188
void idAI2::OnAIEvent_PlayerInteraction(
        const idAIEventSphere* const event) {
    if (event == nullptr || core.gameFrame <= 10
            || Services(*this) == nullptr) {
        return;
    }
    if (core.actorClass != 2) {
        Services(*this)->EnableInteractionFaceAnimation(
            *this, core.faceAnimationFlags);
    }
    Services(*this)->SignalPlayerInteracting(*this);
    Services(*this)->PostAlertCycleEvent(*this,
        *reinterpret_cast<const idAIEvent*>(event), core.currentTime);
}

// Retail symbol: ?ActivateExtendedClipModel@idAI2@@QAAPAVidClipModel@@W4aiExtendedClipModelStatus_t@@H@Z
// EA: 0x829F3308, RVA: 0x009F3308
idClipModel* idAI2::ActivateExtendedClipModel(
        const aiExtendedClipModelStatus_t status,
        const int frameCount) {
    if (status == AIEXTENDEDCLIPMODELSTATUS_NONE) {
        DeactivateExtendedClipModel();
        return nullptr;
    }
    core.extendedClipModelStatus = static_cast<int>(status);
    if (core.extendedClipModel == nullptr
            && Services(*this) != nullptr) {
        core.extendedClipModel =
            Services(*this)->CloneExtendedClipModel(*this);
        if (core.extendedClipModel != nullptr) {
            Services(*this)->ActivateExtendedClipModel(
                *this, core.extendedClipModel, 131096);
        }
    }
    core.extendedClipModelEndTime = core.currentTime
        + frameCount * core.millisecondsPerFrame;
    return reinterpret_cast<idClipModel*>(core.extendedClipModel);
}

// Retail symbol: ?AimDebug@idAI2@@QBAXPBDH@Z
// EA: 0x829F3448, RVA: 0x009F3448
void idAI2::AimDebug(const char* const text,
        const int level) const {
    if (core.aimDebugLevel >= level && core.debugLevel > 0
            && Services(*this) != nullptr) {
        Services(*this)->DrawAI2CoreDebugText(text,
            core.physicsOrigin + core.eyeOffset, false, 1);
    }
}

// Retail symbol: ?LookDebug@idAI2@@QBAXPBDHH@Z
// EA: 0x829F3550, RVA: 0x009F3550
void idAI2::LookDebug(const char* const text, const int level,
        const int duration) const {
    if (core.lookDebugLevel < level || core.debugLevel <= 0
            || Services(*this) == nullptr) {
        return;
    }
    Services(*this)->DrawAI2CoreDebugText(text,
        core.physicsOrigin + core.eyeOffset, true, duration);
    if (core.lookDebugLevel > level) {
        Services(*this)->PrintAI2CoreLookDebug(
            core.entityNumber, core.currentTime, text);
    }
}

// Retail symbol: ?GetDestination@idVisibilityObscurity@idAI2@@QBA?AVidVec3@@PBV2@W4obscurityTest_t@12@@Z
// EA: 0x829F36B0, RVA: 0x009F36B0
idVec3 idAI2::idVisibilityObscurity::GetDestination(
        const idAI2* const ai, const obscurityTest_t test) const {
    if (ai == nullptr) {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    const idAI2CoreRuntime& runtime = ai->core;
    switch (test) {
    case OBSCURITYTEST_MUZZLE_POS: {
        idVec3 destination = runtime.physicsOrigin
            + runtime.eyeOffset * 0.75f;
        idVec3 muzzle;
        if (runtime.equippedItems[2] != nullptr
                && runtime.rangedItemSelection != AIITEMSELECT_SCOOP_MUTANT
                && runtime.rangedItemSelection
                    != AIITEMSELECT_LARGE_RANGED_MUTANT
                && Services(*ai) != nullptr
                && Services(*ai)->GetCoreMuzzlePoint(*ai, muzzle)) {
            destination = muzzle;
            destination.z += runtime.muzzleTraceClearOffset;
        }
        return destination;
    }
    case OBSCURITYTEST_HALF_HEIGHT_FAR_LEFT:
        return runtime.physicsOrigin
            + runtime.bodyRight * runtime.diveDistance;
    case OBSCURITYTEST_HALF_HEIGHT_FAR_RIGHT:
        return runtime.physicsOrigin
            - runtime.bodyRight * runtime.diveDistance;
    case OBSCURITYTEST_HALF_HEIGHT_NEAR_LEFT:
        return runtime.physicsOrigin
            + runtime.bodyRight * runtime.sidestepDistance;
    case OBSCURITYTEST_HALF_HEIGHT_NEAR_RIGHT:
        return runtime.physicsOrigin
            - runtime.bodyRight * runtime.sidestepDistance;
    case OBSCURITYTEST_FULL_HEIGHT_FORWARD:
        return runtime.physicsOrigin
            + runtime.bodyForward * runtime.diveDistance;
    case OBSCURITYTEST_FULL_HEIGHT_BACK:
        return runtime.physicsOrigin
            - runtime.bodyForward * runtime.diveDistance;
    default:
        return idVec3(0.0f, 0.0f, 0.0f);
    }
}

// Retail symbol: ?DebugDodge@@YA?AW4aiTransCode_t@idAIStateTransition@@PBVidAI2@@PADW412@@Z
// EA: 0x829F3AB8, RVA: 0x009F3AB8
idAIStateTransition::aiTransCode_t DebugDodge(
        const idAI2* const ai, char* const text,
        const idAIStateTransition::aiTransCode_t transition) {
    if (ai != nullptr && ai->core.debugLevel > 0
            && ai->core.dodgeDebugLevel > 0
            && Services(*ai) != nullptr) {
        const bool succeeded = transition != idAIStateTransition::AITRANS_NONE;
        Services(*ai)->DrawDodgeDebug(*ai, text, succeeded);
        if (succeeded) {
            char message[320];
            std::snprintf(message, sizeof(message), "Dodge: %s\n",
                text != nullptr ? text : "");
            Services(*ai)->Print(message);
        }
    }
    return transition;
}

// Retail symbol: ?GetEncounterGroup@idAI2@@QAAPAVidEncounterGroup@@XZ
// EA: 0x829F3C20, RVA: 0x009F3C20
idEncounterGroup* idAI2::GetEncounterGroup() {
    return core.encounterGroupHandle == -1 || Services(*this) == nullptr
        ? nullptr
        : Services(*this)->EncounterGroupForHandle(
            core.encounterGroupHandle);
}

// Retail symbol: ?GetWalkState@idAI2@@UBA?AW4walkState_t@@XZ
// EA: 0x829F3C50, RVA: 0x009F3C50
walkState_t idAI2::GetWalkState() const {
    return static_cast<walkState_t>(
        core.forcedWalkState > 0 && core.forcedWalkState < 4
            ? core.forcedWalkState : core.walkState);
}

// Retail symbol: ?GetWalkModifier@idAI2@@UBA?AW4aiWalkModifier_t@@XZ
// EA: 0x829F3C80, RVA: 0x009F3C80
aiWalkModifier_t idAI2::GetWalkModifier() const {
    static const char* const names[AIWALKMOD_MAX] = {
        "default", "alt1", "alt2", "grouchy", "old", "slow",
        "armscrossed"
    };
    if (core.forcedWalkModifierName != nullptr
            && core.forcedWalkModifierName[0] != '\0') {
        for (int index = 0; index < AIWALKMOD_MAX; ++index) {
            if (EqualsIgnoreCase(
                    core.forcedWalkModifierName, names[index])) {
                return static_cast<aiWalkModifier_t>(index);
            }
        }
    }
    return core.walkModifier;
}

// Retail symbol: ?GetRunModifier@idAI2@@UBA?AW4aiWalkModifier_t@@XZ
// EA: 0x829F3CF8, RVA: 0x009F3CF8
aiWalkModifier_t idAI2::GetRunModifier() const {
    static const char* const names[AIWALKMOD_MAX] = {
        "default", "alt1", "alt2", "grouchy", "old", "slow",
        "armscrossed"
    };
    if (core.forcedRunModifierName != nullptr
            && core.forcedRunModifierName[0] != '\0') {
        for (int index = 0; index < AIWALKMOD_MAX; ++index) {
            if (EqualsIgnoreCase(
                    core.forcedRunModifierName, names[index])) {
                return static_cast<aiWalkModifier_t>(index);
            }
        }
    }
    return core.runModifier;
}

// Retail symbol: ?SetSolid@idAI2@@QAAX_N@Z
// EA: 0x829F3D70, RVA: 0x009F3D70
void idAI2::SetSolid(const bool isSolid) {
    core.solid = isSolid;
    if (isSolid) {
        core.physicsContents[0] = core.configuredContents;
        if (core.physicsClipModelCount == 2) {
            core.physicsContents[1] = 8;
        }
    } else {
        core.physicsContents[0] = 0;
        if (core.physicsClipModelCount == 2) {
            core.physicsContents[1] = 0;
        }
    }
    if (Services(*this) != nullptr) {
        Services(*this)->SetSolid(*this, isSolid,
            core.physicsContents[0], core.physicsContents[1]);
    }
}

// Retail symbol: ?SetAimFocusEntity@idAI2@@QAAXPBVidEntity@@_NW4aimPoint_t@@H@Z
// EA: 0x829F3EE8, RVA: 0x009F3EE8
void idAI2::SetAimFocusEntity(const idEntity* const entity,
        const bool keepInView, const aimPoint_t point,
        const int timeout) {
    core.aimFocusAimPoint = static_cast<int>(point);
    if (Services(*this) != nullptr) {
        Services(*this)->SetAimFocusEntity(*this, entity,
            keepInView, static_cast<int>(point), timeout);
    }
}

// Retail symbol: ?SetExplicitAimFocusPoint@idAI2@@QAAXABVidVec3@@_NHW4aiFocus_t@@@Z
// EA: 0x829F3F08, RVA: 0x009F3F08
void idAI2::SetExplicitAimFocusPoint(const idVec3& point,
        const bool keepInView, const int timeout,
        const aiFocus_t focusType) {
    if (Services(*this) != nullptr) {
        Services(*this)->SetExplicitAimFocusPoint(*this, point,
            keepInView, timeout, static_cast<int>(focusType));
    }
}

// Retail symbol: ?SetAimFocusAimPoint@idAI2@@QAAXW4aimPoint_t@@@Z
// EA: 0x829F3F28, RVA: 0x009F3F28
void idAI2::SetAimFocusAimPoint(const aimPoint_t point) {
    core.aimFocusAimPoint = static_cast<int>(point);
}

// Retail symbol: ?ReloadWeapon@idAI2@@QAAXPAVidWeapon@@@Z
// EA: 0x829F3F30, RVA: 0x009F3F30
void idAI2::ReloadWeapon(idWeapon* const weapon) {
    if (weapon != nullptr && core.equippedWeaponReloading
            && Services(*this) != nullptr) {
        Services(*this)->ReloadAIWeapon(*this, *weapon);
        Services(*this)->Print(
            "idAI2::ReloadWeapon was called - make sure a frame command is not missing on the reload animation!\n");
    }
}

// Retail symbol: ?GetRepullTriggerInterval@idAI2@@QBAXPBVidWeapon@@AAH1@Z
// EA: 0x829F3FC0, RVA: 0x009F3FC0
void idAI2::GetRepullTriggerInterval(const idWeapon* const weapon,
        int& minimum, int& maximum) const {
    minimum = maximum = 0;
    if (weapon != nullptr && Services(*this) != nullptr) {
        Services(*this)->GetWeaponSkillInterval(*weapon,
            GetModifiedSkill(), 0, minimum, maximum);
    }
}

// Retail symbol: ?GetBurstDuration@idAI2@@QBAXPBVidWeapon@@AAH1@Z
// EA: 0x829F4010, RVA: 0x009F4010
void idAI2::GetBurstDuration(const idWeapon* const weapon,
        int& minimum, int& maximum) const {
    minimum = maximum = 0;
    if (weapon != nullptr && Services(*this) != nullptr) {
        Services(*this)->GetWeaponSkillInterval(*weapon,
            GetModifiedSkill(), 1, minimum, maximum);
    }
}

// Retail symbol: ?GetFireAtLastKnownDuration@idAI2@@QAAXPBVidWeapon@@AAH1@Z
// EA: 0x829F4060, RVA: 0x009F4060
void idAI2::GetFireAtLastKnownDuration(const idWeapon* const weapon,
        int& minimum, int& maximum) {
    (void)weapon;
    const int skill = static_cast<int>(GetModifiedSkill());
    minimum = core.minFireAtLastKnownDuration[skill];
    maximum = core.maxFireAtLastKnownDuration[skill];
}

// Retail symbol: ?GetEyeOffset@idAI2@@UBA?BVidVec3@@XZ
// EA: 0x829F40C8, RVA: 0x009F40C8
idVec3 idAI2::GetEyeOffset() const {
    idVec3 result;
    if (Services(*this) != nullptr
            && Services(*this)->GetBlendedEyeOffset(*this, result)) {
        return result;
    }
    return core.eyeOffset;
}

// Retail symbol: ?OkToFocus@@YA_NABVidVec3@@00@Z
// EA: 0x829F4260, RVA: 0x009F4260
bool OkToFocus(const idVec3& target, const idVec3& origin,
        const idVec3& actualPosition) {
    idVec3 requestedDirection = target - origin;
    const float requestedDistance = requestedDirection.NormalizeFast();
    if (requestedDistance <= 16.0f) {
        return false;
    }
    idVec3 actualDirection = actualPosition - origin;
    if (actualDirection.NormalizeFast() == 0.0f) {
        return false;
    }
    return actualDirection.Dot(requestedDirection) > -0.000000050005699f;
}
