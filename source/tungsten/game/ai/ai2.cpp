#include "ai2.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

namespace {

std::vector<idAI2*> g_knownAI2Instances;

void RememberAI2Instance(idAI2& ai) {
    if (std::find(g_knownAI2Instances.begin(), g_knownAI2Instances.end(),
            &ai) == g_knownAI2Instances.end()) {
        g_knownAI2Instances.push_back(&ai);
    }
}

idAI2CoreServices* Services(idAI2& ai) {
    RememberAI2Instance(ai);
    return ai.core.services;
}

const idAI2CoreServices* Services(const idAI2& ai) {
    RememberAI2Instance(const_cast<idAI2&>(ai));
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
        const bool succeeded = transition != 0;
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

// Retail symbol: ?SetEnableAutoFocus@idAI2@@QAAX_N@Z
// EA: 0x829F43A0, RVA: 0x009F43A0
void idAI2::SetEnableAutoFocus(const bool enable) {
    if (enable && !core.enableAutoFocus) {
        core.lookFocusTimeout = core.currentTime;
    }
    core.enableAutoFocus = enable;
}

idCheckSurroundingsState::idCheckSurroundingsState()
    : services(nullptr), unitsPerInch(1.0f), velocityScale(1.0f),
      currentTime(0), directions{}, lookInterest{},
      lookedAtEntitySpawnIds{}, lookedAtEntityTimes{} {
    constexpr float diagonal = 0.7071067811865475f;
    directions = {{
        idVec3(1.0f, 0.0f, 0.0f),
        idVec3(diagonal, diagonal, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f),
        idVec3(-diagonal, diagonal, 0.0f),
        idVec3(-1.0f, 0.0f, 0.0f),
        idVec3(-diagonal, -diagonal, 0.0f),
        idVec3(0.0f, -1.0f, 0.0f),
        idVec3(diagonal, -diagonal, 0.0f)
    }};
    lookedAtEntitySpawnIds.fill(0x1FFF);
}

// Retail symbol: ?DistanceExponentToDistance@idCheckSurroundingsState@@ABAMH@Z
// EA: 0x829F4410, RVA: 0x009F4410
float idCheckSurroundingsState::DistanceExponentToDistance(
        const unsigned int distanceExponent) const {
    return std::pow(std::sqrt(2.0f),
        static_cast<float>(distanceExponent))
        * 10.0f * unitsPerInch * 12.0f;
}

// Retail symbol: ?FindNetDirectionInterest@idCheckSurroundingsState@@ABAMPBVidAI2@@ABVidVec3@@@Z
// EA: 0x829F4478, RVA: 0x009F4478
float idCheckSurroundingsState::FindNetDirectionInterest(
        const idAI2* const ai, const idVec3& testDirection) const {
    if (ai == nullptr) {
        return 0.0f;
    }
    float netInterest = 0.0f;
    const idVec3 scaledVelocity = ai->core.linearVelocity * velocityScale;
    for (int index = 0; index < 8; ++index) {
        const float alignment = testDirection.Dot(directions[index]);
        if (alignment > 0.0f) {
            const float directionalInterest = lookInterest[index]
                + scaledVelocity.Dot(directions[index]);
            netInterest += directionalInterest
                * alignment * alignment;
        }
    }
    return netInterest;
}

// Retail symbol: ?GetLookedAtElapsedTime@idCheckSurroundingsState@@QBAHPBVidEntity@@@Z
// EA: 0x829F4660, RVA: 0x009F4660
int idCheckSurroundingsState::GetLookedAtElapsedTime(
        const idEntity* const entity) const {
    const int spawnId = services != nullptr
        ? services->EntitySpawnId(entity) : 0x1FFF;
    for (int index = 0; index < 4; ++index) {
        if (lookedAtEntitySpawnIds[index] == spawnId) {
            return std::min(10000,
                currentTime - lookedAtEntityTimes[index]);
        }
    }
    return 10000;
}

// Retail symbol: ?SetLastLookedAtTime@idCheckSurroundingsState@@QAAXPBVidEntity@@H@Z
// EA: 0x829F4700, RVA: 0x009F4700
void idCheckSurroundingsState::SetLastLookedAtTime(
        const idEntity* const entity, const int setTime) {
    const int spawnId = services != nullptr
        ? services->EntitySpawnId(entity) : 0x1FFF;
    for (int index = 0; index < 4; ++index) {
        if (lookedAtEntitySpawnIds[index] == spawnId) {
            lookedAtEntityTimes[index] = setTime;
            return;
        }
    }
    int replace = 0;
    for (int index = 0; index < 4; ++index) {
        if (lookedAtEntitySpawnIds[index] == 0x1FFF) {
            replace = index;
            break;
        }
        if (lookedAtEntityTimes[index] < lookedAtEntityTimes[replace]) {
            replace = index;
        }
    }
    lookedAtEntitySpawnIds[replace] = spawnId;
    lookedAtEntityTimes[replace] = setTime;
}

// Retail symbol: `idAI2::FindClosestFocus'::`2'::idLookDebug::~idLookDebug
// EA: 0x829F47E8, RVA: 0x009F47E8
idAI2LookDebug::~idAI2LookDebug() {
    if (owner != nullptr && text != nullptr) {
        owner->LookDebug(text, 1, duration);
    }
}

// Retail symbol: ?SetSpeakingVO@idAI2@@QAAXXZ
// EA: 0x829F4808, RVA: 0x009F4808
void idAI2::SetSpeakingVO() {
    if (core.actorClass != 2 && Services(*this) != nullptr) {
        Services(*this)->EnableInteractionFaceAnimation(
            *this, core.faceAnimationFlags);
    }
}

// Retail symbol: ?SetActionScript@idAI2@@QAAXABV?$idList@VidScriptAction@@$04@@PAVidEntity@@1@Z
// EA: 0x829F4910, RVA: 0x009F4910
void idAI2::SetActionScript(
        const idList<idScriptAction, 5>& script,
        idEntity* const scriptExecutor, idEntity* const activator) {
    if (!core.dead && Services(*this) != nullptr) {
        Services(*this)->SetActionScript(
            *this, script, scriptExecutor, activator);
        core.actionScriptRunning = true;
    }
}

// Retail symbol: ?EndActionScript@idAI2@@QAAXXZ
// EA: 0x829F4970, RVA: 0x009F4970
void idAI2::EndActionScript() {
    if (Services(*this) != nullptr) {
        Services(*this)->ClearActionScript(*this);
    }
    core.actionScriptRunning = false;
}

// Retail symbol: ?OnActionScriptFinished@idAI2@@QAAXH@Z
// EA: 0x829F4980, RVA: 0x009F4980
void idAI2::OnActionScriptFinished(const int currentTime) {
    (void)currentTime;
    core.painStimulusEnabled = core.defaultPainStimulusEnabled;
}

// Retail symbol: ?SetActionScriptFlag@idAI2@@QAAXH_N@Z
// EA: 0x829F4998, RVA: 0x009F4998
void idAI2::SetActionScriptFlag(const int flags,
        const bool setFlag) {
    if (setFlag) {
        core.actionScriptFlags |= flags;
    } else {
        core.actionScriptFlags &= ~flags;
    }
}

// Retail symbol: ?ActionScriptFlagIsSet@idAI2@@QBA_NH@Z
// EA: 0x829F49C0, RVA: 0x009F49C0
bool idAI2::ActionScriptFlagIsSet(const int flags) const {
    return core.actionScriptRunning
        && (core.actionScriptFlags & flags) != 0;
}

// Retail symbol: ?GetActionFSM@idAI2@@QAAPAVidAIActionFSM@@XZ
// EA: 0x829F4A30, RVA: 0x009F4A30
idAIActionFSM* idAI2::GetActionFSM() {
    return Services(*this) != nullptr
        ? Services(*this)->GetActionFSM(*this) : nullptr;
}

// Retail symbol: ?GetCurrentAction@idAI2@@QBAPAVidAIAction@@XZ
// EA: 0x829F4A38, RVA: 0x009F4A38
idAIAction* idAI2::GetCurrentAction() const {
    return Services(*this) != nullptr
        ? Services(*this)->GetCurrentAction(*this) : nullptr;
}

// Retail symbol: ?GetActionStatus@idAI2@@QBA?AW4fsmStatus_t@idFiniteStateMachine@@XZ
// EA: 0x829F4A50, RVA: 0x009F4A50
idFiniteStateMachine::fsmStatus_t idAI2::GetActionStatus() const {
    return core.actionStatus;
}

// Retail symbol: ?IsIdling@idAI2@@QBA_NXZ
// EA: 0x829F4A58, RVA: 0x009F4A58
bool idAI2::IsIdling() const {
    return GetCurrentAction() != nullptr && core.currentActionIsIdle;
}

// Retail symbol: ?SetAlertCycle@idAI2@@QAAXW4alertCycle_t@@@Z
// EA: 0x829F4AA8, RVA: 0x009F4AA8
void idAI2::SetAlertCycle(const alertCycle_t alertCycle) {
    int nextCycle = static_cast<int>(alertCycle);
    if (core.alwaysInCombat && nextCycle != 5 && nextCycle != 6) {
        nextCycle = 3;
    }
    if (core.alertCycle != nextCycle) {
        core.previousAlertCycle = core.alertCycle;
    }
    core.alertCycle = nextCycle;
    if (nextCycle == 3) {
        core.highestAlertCycle = 3;
        if (core.previousAlertCycle != 3) {
            core.lastSurprisedTime = core.currentTime;
        }
    } else if (nextCycle == 2) {
        core.highestAlertCycle = std::max(core.highestAlertCycle, 2);
    }
    if (Services(*this) != nullptr) {
        const int subWeb = nextCycle >= 0 && nextCycle < 11
            ? static_cast<int>(AlertCycleToSubWeb(
                static_cast<alertCycle_t>(nextCycle))) : 0;
        Services(*this)->SetSubWeb(*this, subWeb);
    }
}

// Retail symbol: ??0idAIFSMCallback@@QAA@XZ
// EA: 0x829F4BC8, RVA: 0x009F4BC8
idAIFSMCallback::idAIFSMCallback() : log(64) {
}

// Retail symbol: ?OnTransition@idAIFSMCallback@@UAAXPBVidFiniteStateMachine@@PBVidTypeInfo@@11H@Z
// EA: 0x829F4C48, RVA: 0x009F4C48
void idAIFSMCallback::OnTransition(
        const idFiniteStateMachine* const fsm,
        const idTypeInfo* const fromStateType,
        const idTypeInfo* const toStateType,
        const idTypeInfo* const transitionType,
        const int transitionCode) {
    idFSMLogEntry* const entry = log.Alloc();
    if (entry == nullptr) {
        return;
    }
    entry->type = idFSMLogEntry::LOGENTRY_TRANSITION;
    entry->time = 0;
    entry->fsm = fsm;
    entry->curStateType = fromStateType;
    entry->nextStateType = toStateType;
    entry->transitionType = transitionType;
    entry->transCode = transitionCode;
}

// Retail symbol: ?OnRestart@idAIFSMCallback@@UAAXPBVidFiniteStateMachine@@PBVidTypeInfo@@@Z
// EA: 0x829F4CB8, RVA: 0x009F4CB8
void idAIFSMCallback::OnRestart(
        const idFiniteStateMachine* const fsm,
        const idTypeInfo* const currentStateType) {
    (void)currentStateType;
    idFSMLogEntry* const entry = log.Alloc();
    if (entry == nullptr) {
        return;
    }
    entry->type = idFSMLogEntry::LOGENTRY_RESTART;
    entry->time = 0;
    entry->fsm = fsm;
    entry->curStateType = nullptr;
    entry->nextStateType = nullptr;
    entry->transitionType = nullptr;
    entry->transCode = 0;
}

// Retail symbol: ?OnError@idAIFSMCallback@@UAAXPBVidFiniteStateMachine@@PBVidTypeInfo@@1H@Z
// EA: 0x829F4D30, RVA: 0x009F4D30
void idAIFSMCallback::OnError(
        const idFiniteStateMachine* const fsm,
        const idTypeInfo* const currentStateType,
        const idTypeInfo* const transitionType,
        const int transitionCode) {
    (void)currentStateType;
    idFSMLogEntry* const entry = log.Alloc();
    if (entry == nullptr) {
        return;
    }
    entry->type = idFSMLogEntry::LOGENTRY_ERROR;
    entry->time = 0;
    entry->fsm = fsm;
    entry->curStateType = nullptr;
    entry->nextStateType = nullptr;
    entry->transitionType = transitionType;
    entry->transCode = transitionCode;
}

// Retail symbol: ?SetIdealAimFocusPoint@idAI2@@QAAXABVidVec3@@HW4aiFocus_t@@@Z
// EA: 0x829F4D98, RVA: 0x009F4D98
void idAI2::SetIdealAimFocusPoint(const idVec3& point,
        const int timeout, const aiFocus_t focusType) {
    if (Services(*this) != nullptr) {
        Services(*this)->SetFocusPoint(*this, 0, point,
            timeout, static_cast<int>(focusType));
    }
}

// Retail symbol: ?SetIdealLookFocusPoint@idAI2@@QAAXABVidVec3@@HW4aiFocus_t@@@Z
// EA: 0x829F4DB8, RVA: 0x009F4DB8
void idAI2::SetIdealLookFocusPoint(const idVec3& point,
        const int timeout, const aiFocus_t focusType) {
    if (Services(*this) != nullptr) {
        Services(*this)->SetFocusPoint(*this, 1, point,
            timeout, static_cast<int>(focusType));
    }
}

// Retail symbol: ?ClearAimFocus@idAI2@@QAAXXZ
// EA: 0x829F4DD8, RVA: 0x009F4DD8
void idAI2::ClearAimFocus() {
    if (Services(*this) != nullptr) {
        Services(*this)->ClearFocus(*this, 0);
    }
}

// Retail symbol: ?ClearLookFocus@idAI2@@QAAXXZ
// EA: 0x829F4DE8, RVA: 0x009F4DE8
void idAI2::ClearLookFocus() {
    if (Services(*this) != nullptr) {
        Services(*this)->ClearFocus(*this, 1);
    }
}

// Retail symbol: ?SetEnableHeadTracking@idAI2@@QAAX_N@Z
// EA: 0x829F4DF8, RVA: 0x009F4DF8
void idAI2::SetEnableHeadTracking(const bool enable) {
    core.enableHeadTracking = enable;
    if (Services(*this) != nullptr) {
        Services(*this)->SetFocusTrackingEnabled(*this, 0, enable);
        Services(*this)->SetFocusTrackingEnabled(*this, 1, enable);
    }
}

// Retail symbol: ?SetSuppressHeadTracking@idAI2@@QAAX_N@Z
// EA: 0x829F4E40, RVA: 0x009F4E40
void idAI2::SetSuppressHeadTracking(const bool suppress) {
    core.suppressHeadTracking = suppress;
    if (Services(*this) != nullptr) {
        Services(*this)->SetFocusTrackingSuppressed(*this, 0, suppress);
        Services(*this)->SetFocusTrackingSuppressed(*this, 1, suppress);
    }
}

// Retail symbol: ?CoverApproachForDirection@@YA?AW4coverApproach_t@idAI2@@ABVidVec3@@_N1@Z
// EA: 0x829F4E80, RVA: 0x009F4E80
idAI2::coverApproach_t CoverApproachForDirection(
        const idVec3& relativePosition,
        const bool allowTurnAroundLeft,
        const bool allowTurnAroundRight) {
    if (relativePosition.y > 0.0f) {
        if (relativePosition.x > 0.0f) {
            if (relativePosition.x > relativePosition.y) {
                return idAI2::COVER_APPROACH_RIGHT;
            }
            if (allowTurnAroundRight) {
                return idAI2::COVER_APPROACH_TURN_AROUND_RIGHT;
            }
            if (allowTurnAroundLeft) {
                return idAI2::COVER_APPROACH_WRAP_AROUND_LEFT;
            }
            return idAI2::COVER_APPROACH_MAX;
        }
        if (-relativePosition.x <= relativePosition.y) {
            if (allowTurnAroundLeft) {
                return idAI2::COVER_APPROACH_TURN_AROUND_LEFT;
            }
            if (allowTurnAroundRight) {
                return idAI2::COVER_APPROACH_WRAP_AROUND_RIGHT;
            }
            return idAI2::COVER_APPROACH_MAX;
        }
        return idAI2::COVER_APPROACH_LEFT;
    }
    if (std::fabs(relativePosition.x) < -relativePosition.y) {
        return idAI2::COVER_APPROACH_FORWARD;
    }
    return relativePosition.x > 0.0f
        ? idAI2::COVER_APPROACH_RIGHT : idAI2::COVER_APPROACH_LEFT;
}

// Retail symbol: ?GetRunCycleIndexForType@idAI2@@QBAHW4runIndexType_t@@@Z
// EA: 0x829F4F40, RVA: 0x009F4F40
int idAI2::GetRunCycleIndexForType(
        const runIndexType_t type) const {
    const int index = static_cast<int>(type);
    if (index < 0 || index >= ANIMWEBAI_RUNINDEXTYPE_MAX) {
        return -1;
    }
    if (type == ANIMWEBAI_RUNINDEXTYPE_NORMAL) {
        return 0;
    }
    if (type == ANIMWEBAI_RUNINDEXTYPE_INJURED) {
        if (Services(*this) != nullptr) {
            Services(*this)->Print(
                "idAI2::GetRunCycleIndexForType cannot directly select the injured type.\n");
        }
        return -1;
    }
    return core.runCycleIndices[index];
}

// Retail symbol: ?GetIdleIndexForType@idAI2@@QBAHW4runIndexType_t@@@Z
// EA: 0x829F5048, RVA: 0x009F5048
int idAI2::GetIdleIndexForType(
        const runIndexType_t type) const {
    const int index = static_cast<int>(type);
    if (index < 0 || index >= ANIMWEBAI_RUNINDEXTYPE_MAX
            || type == ANIMWEBAI_RUNINDEXTYPE_NORMAL
            || type == ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE
            || type == ANIMWEBAI_RUNINDEXTYPE_FAR
            || type == ANIMWEBAI_RUNINDEXTYPE_UP_STAIRS
            || type == ANIMWEBAI_RUNINDEXTYPE_DOWN_STAIRS) {
        return 0;
    }
    if (type == ANIMWEBAI_RUNINDEXTYPE_INJURED) {
        if (Services(*this) != nullptr) {
            Services(*this)->Print(
                "idAI2::GetIdleIndexForType cannot directly select the injured type.\n");
        }
        return -1;
    }
    return core.idleIndices[index];
}

// Retail symbol: ?PlayAnimWebPathPerfect@idAI2@@QAAXABVidAnimWebPath@@ABVidVec3@@ABVidMat3@@_N3@Z
// EA: 0x829F5108, RVA: 0x009F5108
void idAI2::PlayAnimWebPathPerfect(const idAnimWebPath& path,
        const idVec3& position, const idMat3& axis,
        const bool forcedTransition, const bool perfectDestination) {
    if (Services(*this) != nullptr) {
        Services(*this)->PlayAnimWebPathPerfect(*this, path,
            position, axis, forcedTransition, perfectDestination);
    }
}

// Retail symbol: ?AllocPresentable@idAI2@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA: 0x829F5328, RVA: 0x009F5328
idPresentable* idAI2::AllocPresentable(
        idRenderModel* const renderModel) {
    return Services(*this) != nullptr
        ? Services(*this)->AllocAIPresentable(*this, renderModel)
        : nullptr;
}

// Retail symbol: ?UpdateInfluenceTrail@idAI2@@AAAXXZ
// EA: 0x829F5420, RVA: 0x009F5420
void idAI2::UpdateInfluenceTrail() {
    if (core.influenceTrailsEnabled && Services(*this) != nullptr) {
        Services(*this)->UpdateInfluenceTrail(
            *this, core.physicsOrigin, core.currentTime);
    }
}

// Retail symbol: ?IsOnElevator@idAI2@@QAA_NXZ
// EA: 0x829F54C8, RVA: 0x009F54C8
bool idAI2::IsOnElevator() {
    return !core.actionScriptRunning && Services(*this) != nullptr
        && Services(*this)->IsOnMovingElevator(*this);
}

// Retail symbol: ?StartRagdoll@idAI2@@UAA?AW4testSolidResult_t@idAnimator_AF@@ABVidRagdollInfo@@@Z
// EA: 0x829F56D0, RVA: 0x009F56D0
idAnimator_AF::testSolidResult_t idAI2::StartRagdoll(
        const idRagdollInfo& info) {
    if (core.ragdollStartBlockedInSolid) {
        return idAnimator_AF::TESTSOLID_IN_SOLID;
    }
    SetIsRagdolling(true);
    return Services(*this) != nullptr
        ? Services(*this)->StartAIRagdoll(*this, info)
        : idAnimator_AF::TESTSOLID_NOT_IN_SOLID;
}

// Retail symbol: ?StopRagdoll@idAI2@@UAAXXZ
// EA: 0x829F5738, RVA: 0x009F5738
void idAI2::StopRagdoll() {
    SetIsRagdolling(false);
    if (Services(*this) != nullptr) {
        Services(*this)->StopAIRagdoll(*this);
    }
}

// Retail symbol: ?GetMoveOrientation@idAI2@@QAAAAVidAIOrientation@@XZ
// EA: 0x829F5770, RVA: 0x009F5770
idAIOrientation& idAI2::GetMoveOrientation() {
    return *(core.animationMoveInterfaceActive
        ? core.animationMoveOrientation : core.physicsMoveOrientation);
}

// Retail symbol: ?GetBodyOrientation@idAI2@@QAAAAVidAIOrientation@@XZ
// EA: 0x829F57C8, RVA: 0x009F57C8
idAIOrientation& idAI2::GetBodyOrientation() {
    return *(core.animationMoveInterfaceActive
        ? core.animationBodyOrientation : core.focusBodyOrientation);
}

// Retail symbol: ?SetAxis@idAI2@@UAAXABVidMat3@@@Z
// EA: 0x829F5820, RVA: 0x009F5820
void idAI2::SetAxis(const idMat3& axis) {
    if (Services(*this) != nullptr) {
        Services(*this)->SetAIOrientationAxis(
            *this, axis, core.animationMoveInterfaceActive);
    }
}

// Retail symbol: ?IsMoveDone@idAI2@@QAA_N_N@Z
// EA: 0x829F5880, RVA: 0x009F5880
bool idAI2::IsMoveDone(const bool checkAlignment) {
    (void)checkAlignment;
    return core.animationMoveInterfaceActive
        ? core.animationMoveDone : core.physicsMoveDone;
}

// Retail symbol: ?GetMoveInterface@idAI2@@QAAAAVidAIMoveInterface@@XZ
// EA: 0x829F5900, RVA: 0x009F5900
idAIMoveInterface& idAI2::GetMoveInterface() {
    return *(core.animationMoveInterfaceActive
        ? core.animationMoveInterface : core.physicsMoveInterface);
}

// Retail symbol: ?PauseFiberTillActionCompletes@idAIScriptProxy@@AAAXV?$idHandle@HW4invalidFiberId_t@@$0A@@@@Z
// EA: 0x829F5968, RVA: 0x009F5968
void idAIScriptProxy::PauseFiberTillActionCompletes(
        const idFiberHandle fiberHandle) {
    if (owner == nullptr || owner->core.services == nullptr
            || !owner->core.services->IsScriptFiberValid(
                fiberHandle.value)) {
        return;
    }
    if (owner->core.waitActionFiberHandle != 0) {
        owner->core.services->Error(
            owner->core.services->IsScriptFiberValid(
                owner->core.waitActionFiberHandle)
            ? "Fiber tried to wait on action FSM, but it is already waiting on another fiber"
            : "Fiber tried to wait on action FSM, but it is already waiting on a dead fiber");
        return;
    }
    owner->core.waitActionFiberHandle = fiberHandle.value;
    owner->core.services->WaitFiberForActionFSM(fiberHandle.value);
}

// Retail symbol: ?PauseThreadTillActionCompletes@idAIScriptProxy@@AAAXPAVidThread@@@Z
// EA: 0x829F5A00, RVA: 0x009F5A00
void idAIScriptProxy::PauseThreadTillActionCompletes(
        idThread* const thread) {
    if (owner == nullptr || owner->core.services == nullptr
            || thread == nullptr) {
        return;
    }
    if (owner->core.waitActionThreadHandle != 0) {
        owner->core.services->Error(
            owner->core.services->IsScriptThreadAlive(
                owner->core.waitActionThreadHandle)
            ? "Thread tried to wait on action FSM, but it is already waiting on another thread"
            : "Thread tried to wait on action FSM, but it is already waiting on a dead thread");
        return;
    }
    owner->core.waitActionThreadHandle =
        owner->core.services->ScriptThreadHandle(*thread);
    owner->core.services->WaitThreadForActionFSM(*thread);
}

// Retail symbol: ?GetEntranceAnimWebPath@idAI2@@QBA?AVidAnimWebPath@@XZ
// EA: 0x829F66F8, RVA: 0x009F66F8
idAnimWebPath idAI2::GetEntranceAnimWebPath() const {
    return core.entranceAnimWebPath;
}

namespace {

void UpdateRobotBossHealth(idAI2RobotRuntime& robot) {
    if (robot.numStages <= 0 || robot.stageHealth <= 0.0f) {
        robot.bossHealth = 0.0f;
        return;
    }
    robot.bossHealth = (static_cast<float>(
        robot.numStages - robot.curStage - 1)
        + robot.curStageHealth / robot.stageHealth)
        / static_cast<float>(robot.numStages);
}

void BeginRobotRecharge(idAI2& ai) {
    idAI2RobotRuntime& robot = ai.core.robot;
    if (robot.triggerOnPowerOut != nullptr && Services(ai) != nullptr) {
        Services(ai)->ActivateRobotPowerOut(ai,
            *robot.triggerOnPowerOut);
    }
    robot.curStageHealth = robot.stageHealth * robot.chargeHealthFract;
    robot.chargeDoneTime = -1;
    robot.isCharging = true;
}

void DrainRobotFireHealth(idAI2RobotRuntime& robot,
        const int currentTime) {
    robot.curStageHealth -= static_cast<float>(
        currentTime - robot.lastShootTime) * robot.stageHealth
        * robot.shootHealthDrain * 0.001f;
}

} // namespace

// Retail symbol: ?CanFireRobot@idAI2@@QAA_NH@Z
// EA: 0x829F6730, RVA: 0x009F6730
bool idAI2::CanFireRobot(const int currentTime) {
    idAI2RobotRuntime& robot = core.robot;
    if (!robot.usesRobot) {
        return true;
    }
    if (robot.isCharging || robot.noFireTime >= currentTime) {
        robot.lastShootTime = -1;
        return false;
    }
    if (robot.shootHealthDrain <= 0.0f) {
        return true;
    }
    if (robot.lastShootTime <= 0) {
        robot.lastShootTime = currentTime;
        UpdateRobotBossHealth(robot);
        return true;
    }

    DrainRobotFireHealth(robot, currentTime);
    if (robot.stageHealth > 0.0f
            && robot.curStageHealth / robot.stageHealth
                > robot.chargeHealthFract) {
        robot.lastShootTime = currentTime;
        UpdateRobotBossHealth(robot);
        return true;
    }

    BeginRobotRecharge(*this);
    robot.lastShootTime = -1;
    UpdateRobotBossHealth(robot);
    return false;
}

// Retail symbol: ?StopFireRobot@idAI2@@QAAXH@Z
// EA: 0x829F6930, RVA: 0x009F6930
void idAI2::StopFireRobot(const int currentTime) {
    idAI2RobotRuntime& robot = core.robot;
    if (!robot.usesRobot) {
        return;
    }
    if (robot.lastShootTime > 0 && !robot.isCharging
            && robot.shootHealthDrain > 0.0f) {
        DrainRobotFireHealth(robot, currentTime);
        if (robot.stageHealth <= 0.0f
                || robot.curStageHealth / robot.stageHealth
                    <= robot.chargeHealthFract) {
            BeginRobotRecharge(*this);
        }
        UpdateRobotBossHealth(robot);
    }
    robot.lastShootTime = -1;
}

// Retail symbol: ?GetBossHudInfo@idAI2@@QAA?AVidHudBossInfo@@XZ
// EA: 0x829F6AA0, RVA: 0x009F6AA0
idHudBossInfo idAI2::GetBossHudInfo() {
    idHudBossInfo info;
    info.amount = core.robot.bossHealth;
    info.numBars = core.robot.numStages;
    info.visibleBars = std::max(0,
        core.robot.numStages - core.robot.curStage);
    return info;
}

// Retail symbol: ?SetAccuracy@idAI2@@QAAXW4aiAccuracy_t@@@Z
// EA: 0x829F6AC0, RVA: 0x009F6AC0
void idAI2::SetAccuracy(const aiAccuracy_t accuracy) {
    core.aimAccuracy = accuracy;
    if (Services(*this) != nullptr) {
        Services(*this)->SetAimTrackingParmsIndex(
            *this, GetEffectiveAccuracy());
    }
}

// Retail symbol: ?GetModelTransform@idAI2@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA: 0x829F6B00, RVA: 0x009F6B00
void idAI2::GetModelTransform(idVec3& modelOrigin,
        idMat3& modelAxis) const {
    if ((core.afActive || core.afClientAuthoritativeActive
            || core.afSyncing) && Services(*this) != nullptr) {
        Services(*this)->GetAFModelTransform(*this,
            modelOrigin, modelAxis);
        return;
    }

    modelAxis = core.bodyOrientationAxis * core.physicsAxis;
    modelOrigin.x = core.physicsOrigin.x
        + core.modelOffset.x * modelAxis[0].x
        + core.modelOffset.y * modelAxis[1].x
        + core.modelOffset.z * modelAxis[2].x;
    modelOrigin.y = core.physicsOrigin.y
        + core.modelOffset.x * modelAxis[0].y
        + core.modelOffset.y * modelAxis[1].y
        + core.modelOffset.z * modelAxis[2].y;
    modelOrigin.z = core.physicsOrigin.z
        + core.modelOffset.x * modelAxis[0].z
        + core.modelOffset.y * modelAxis[1].z
        + core.modelOffset.z * modelAxis[2].z;
}

// Retail symbol: ?UpdateDrop@idAI2@@QAAXXZ
// EA: 0x829F6CD0, RVA: 0x009F6CD0
void idAI2::UpdateDrop() {
    if (core.dropState != 1) {
        return;
    }
    if (core.dropQueryPending && Services(*this) != nullptr) {
        float fraction = 1.0f;
        if (Services(*this)->PollDropToGroundQuery(*this, fraction)) {
            core.dropQueryPending = false;
            core.dropQueryFraction = fraction;
            if (fraction < 1.0f) {
                core.dropState = 2;
            }
        }
    }
    if (core.dropState != 2 && Services(*this) != nullptr) {
        idVec3 end = core.physicsOrigin;
        end.z -= 290.0f;
        Services(*this)->SubmitDropToGroundQuery(*this,
            core.physicsOrigin, end, 106513);
        core.dropQueryPending = true;
    }
}

// Retail symbol: ?PlayAdditivePain@idAI2@@IAA_NPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@2V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA: 0x829F6E48, RVA: 0x009F6E48
bool idAI2::PlayAdditivePain(idEntity* const inflictor,
        idPlayer* const attacker, const idDeclDamage* const damageDecl,
        const float damage, const idVec3& impactPoint,
        const idVec3& impactDirection, const idJointIndex jointIndex) {
    if ((core.actionScriptRunning && (core.actionScriptFlags & 0x80) != 0)
            || !core.additivePainEnabled || core.maximumBaseHealth <= 0.0f) {
        return false;
    }

    const float damageFraction = damage / core.maximumBaseHealth;
    const bool moving = core.moveStatus == 1;
    const float threshold = moving
        ? (core.walkState >= 2 ? core.twitchThresholdRunning
                              : core.twitchThresholdWalking)
        : core.twitchThresholdStanding;
    if (damageFraction < threshold) {
        return false;
    }

    if (Services(*this) != nullptr) {
        Services(*this)->PlayAIAdditivePain(*this, inflictor, attacker,
            damageDecl, damage, impactPoint, impactDirection, jointIndex);
    }
    return true;
}

namespace {

float Dot(const idVec3& left, const idVec3& right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

float Length(const idVec3& value) {
    return std::sqrt(Dot(value, value));
}

idVec3 Normalized(const idVec3& value) {
    const float length = Length(value);
    return length > 0.000001f ? value * (1.0f / length)
                             : idVec3(0.0f, 0.0f, 0.0f);
}

idVec3 ProjectedDirection(const idVec3& value,
        const idVec3& planeNormal) {
    return Normalized(value - planeNormal * Dot(value, planeNormal));
}

int CoreRandomInt(const idAI2& ai, const int upperBound) {
    if (upperBound <= 1) {
        return 0;
    }
    ai.core.randomSeed = ai.core.randomSeed * 1664525u + 1013904223u;
    return static_cast<int>((ai.core.randomSeed >> 8)
        % static_cast<unsigned int>(upperBound));
}

} // namespace

// Retail symbol: ?UpdateDeathCollision@idAI2@@IAAXXZ
// EA: 0x829F72B0, RVA: 0x009F72B0
void idAI2::UpdateDeathCollision() {
    if (!core.dying || core.deathCollisionSuppressed
            || !core.deathCollisionPending || Services(*this) == nullptr) {
        return;
    }

    if (core.deathCollisionQueryPending) {
        int collisionCount = 0;
        if (Services(*this)->PollDeathCollisionQuery(
                *this, collisionCount)) {
            core.deathCollisionQueryPending = false;
            if (collisionCount > 0) {
                core.deathCollisionPending = false;
                Services(*this)->StartDeathCollisionRagdoll(*this);
                return;
            }
        }
    }

    // The engine service builds the padded trace model from the retail
    // death-joint set and submits the contents-one clip query.
    Services(*this)->SubmitDeathCollisionQuery(*this);
    core.deathCollisionQueryPending = true;
}

// Retail symbol: ?GetMeleeDirection@idAI2@@QBA?AW4aiDirection_t@@ABVidVec3@@0AA_N_N@Z
// EA: 0x829F76B0, RVA: 0x009F76B0
aiDirection_t idAI2::GetMeleeDirection(const idVec3& target,
        const idVec3& velocity, bool& narrowFront,
        const bool debug) const {
    narrowFront = false;
    const idVec3 predictedTarget = target
        + velocity * core.meleeExtrapolate;
    idVec3 direction = Normalized(predictedTarget - core.physicsOrigin);
    const idVec3 directDirection = Normalized(target - core.physicsOrigin);

    const float directHorizontal = std::sqrt(
        directDirection.x * directDirection.x
        + directDirection.y * directDirection.y);
    if (directHorizontal < 0.9f) {
        return AIDIR_FRONT;
    }
    if (Dot(directDirection, direction) < -0.5f) {
        direction = directDirection;
    }

    const idVec3 forward = core.bodyOrientationAxis[0];
    const idVec3 left = core.bodyOrientationAxis[1];
    const float sideDot = Dot(left, direction);
    const float frontDot = Dot(forward, direction);
    aiDirection_t result;
    if (sideDot >= 0.70710677f) {
        result = AIDIR_LEFT;
    } else if (sideDot < -0.70710677f) {
        result = AIDIR_RIGHT;
    } else if (frontDot <= 0.0f) {
        result = AIDIR_BEHIND;
    } else {
        result = AIDIR_FRONT;
        narrowFront = frontDot > 0.9238795f;
    }

    if (debug && Services(*this) != nullptr) {
        Services(*this)->DrawMeleeDirectionDebug(
            *this, target, directDirection, direction);
    }
    return result;
}

// Retail symbol: ?GetMeleeTypeForTarget@idAI2@@QBA?AW4aiMelee_t@@ABVidVec3@@0HH@Z
// EA: 0x829F7C70, RVA: 0x009F7C70
aiMelee_t idAI2::GetMeleeTypeForTarget(
        const idVec3& targetPosition, const idVec3& targetVelocity,
        const int meleeMask, const int preferredMask) const {
    bool narrowFront = false;
    const aiDirection_t direction = GetMeleeDirection(
        targetPosition, targetVelocity, narrowFront, false);
    if (direction >= AIDIR_MAX) {
        return AIMELEE_NONE;
    }

    const idVec3 targetDelta = targetPosition - core.physicsOrigin;
    const float distance = std::sqrt(targetDelta.x * targetDelta.x
        + targetDelta.y * targetDelta.y);
    int available = 0;
    bool movingTogether = false;
    if (distance < core.movingMeleeDistance
            && distance > core.movingMeleeDistance * 0.5f
            && narrowFront) {
        const float minimumSpeedSquared = core.movingPainSpeed
            * core.movingPainSpeed;
        const float ownerSpeedSquared = core.linearVelocity.x
                * core.linearVelocity.x
            + core.linearVelocity.y * core.linearVelocity.y;
        const float targetSpeedSquared = targetVelocity.x
                * targetVelocity.x
            + targetVelocity.y * targetVelocity.y;
        if (ownerSpeedSquared >= minimumSpeedSquared
                && targetSpeedSquared >= minimumSpeedSquared) {
            movingTogether = Dot(Normalized(targetVelocity),
                Normalized(core.linearVelocity)) > 0.70700002f;
        }
    }

    const int supported = core.crouching
        ? core.crouchingMeleeTypes : core.standingMeleeTypes;
    if ((supported & AIMELEE_MOVING_FORWARD) != 0
            && movingTogether && (core.groupCondition & 8) == 0) {
        available = AIMELEE_MOVING_FORWARD;
    } else if (distance < core.closeMeleeDistance) {
        if (narrowFront) {
            available = AIMELEE_KICK;
        }
        available |= AIMELEE_RAGE | AIMELEE_PUNCH | AIMELEE_FORWARD;
    }
    if (distance < core.mediumMeleeDistance) {
        available |= AIMELEE_MEDIUM;
    }
    if (distance < core.longMeleeDistance) {
        available |= AIMELEE_LONG;
    }

    static const int directionMasks[AIDIR_MAX] = {
        -1, 0, AIMELEE_LEFT, 0, AIMELEE_BACK, 0,
        AIMELEE_RIGHT, 0
    };
    int candidates = available & supported
        & directionMasks[direction] & meleeMask;
    if (candidates == 0) {
        return AIMELEE_NONE;
    }
    if ((candidates & preferredMask) != 0) {
        candidates &= preferredMask;
    }

    const int closeCandidates = candidates
        & (AIMELEE_KICK | AIMELEE_PUNCH | AIMELEE_FORWARD);
    if (closeCandidates != 0) {
        int choices[3];
        int choiceCount = 0;
        if ((closeCandidates & AIMELEE_KICK) != 0) {
            choices[choiceCount++] = AIMELEE_KICK;
        }
        if ((closeCandidates & AIMELEE_PUNCH) != 0) {
            choices[choiceCount++] = AIMELEE_PUNCH;
        }
        if ((closeCandidates & AIMELEE_FORWARD) != 0) {
            choices[choiceCount++] = AIMELEE_FORWARD;
        }
        const int selected = choices[CoreRandomInt(*this, choiceCount)];
        if (selected == AIMELEE_FORWARD
                && (candidates & AIMELEE_RAGE) != 0
                && core.baseHealthRatio < 1.0f
                && core.currentTime - core.lastDamageTime < 2000) {
            return AIMELEE_RAGE;
        }
        return static_cast<aiMelee_t>(selected);
    }
    if ((candidates & AIMELEE_MEDIUM) != 0) {
        return AIMELEE_MEDIUM;
    }
    if ((candidates & AIMELEE_LONG) != 0) {
        return AIMELEE_LONG;
    }
    return static_cast<aiMelee_t>(candidates);
}

// Retail symbol: ?GetDirectionTo@idAI2@@QBA?AW4aiDirection_t@@ABVidVec3@@@Z
// EA: 0x829F80A8, RVA: 0x009F80A8
aiDirection_t idAI2::GetDirectionTo(const idVec3& position) const {
    const idVec3 direction = Normalized(position - core.physicsOrigin);
    const idVec3 forward = ProjectedDirection(
        core.bodyOrientationAxis[0], core.gravityNormal);
    const idVec3 left = ProjectedDirection(
        core.bodyOrientationAxis[1], core.gravityNormal);
    const float frontDot = Dot(direction, forward);
    const float sideDot = Dot(direction, left);

    if (frontDot >= 0.0f) {
        if (frontDot > 0.9238795f) return AIDIR_FRONT;
        if (sideDot > 0.0f) {
            return frontDot > 0.3826834f
                ? AIDIR_FRONT_LEFT : AIDIR_LEFT;
        }
        return frontDot > 0.3826834f
            ? AIDIR_FRONT_RIGHT : AIDIR_RIGHT;
    }
    if (frontDot < -0.9238795f) return AIDIR_BEHIND;
    if (sideDot <= 0.0f) {
        return frontDot > -0.3826834f
            ? AIDIR_RIGHT : AIDIR_BEHIND_RIGHT;
    }
    return frontDot >= -0.3826834f
        ? AIDIR_LEFT : AIDIR_BEHIND_LEFT;
}

// Retail symbol: ?IsFacingMe@idAI2@@QBA_NPBVidEntity@@M@Z
// EA: 0x829F8318, RVA: 0x009F8318
bool idAI2::IsFacingMe(const idEntity* const entity,
        const float dotThreshold) const {
    if (entity == nullptr || Services(*this) == nullptr) {
        return false;
    }
    idVec3 entityOrigin;
    idVec3 entityForward;
    if (!Services(*this)->GetEntityPhysicalState(*this, entity,
            true, entityOrigin, entityForward)) {
        return false;
    }
    return Dot(Normalized(core.physicsOrigin - entityOrigin),
        entityForward) > dotThreshold;
}

// Retail symbol: ?AmIToEntitysLeft@idAI2@@QBA_NPBVidEntity@@@Z
// EA: 0x829F8440, RVA: 0x009F8440
bool idAI2::AmIToEntitysLeft(const idEntity* const entity) const {
    if (entity == nullptr || Services(*this) == nullptr) {
        return false;
    }
    idVec3 entityOrigin;
    idVec3 entityForward;
    if (!Services(*this)->GetEntityPhysicalState(*this, entity,
            false, entityOrigin, entityForward)) {
        return false;
    }
    const idVec3 delta = core.physicsOrigin - entityOrigin;
    return entityForward.y * delta.x - entityForward.x * delta.y > 0.0f;
}

// Retail symbol: ?StartReloading@idAI2@@QAA_NPAVidAIFSM@@PAVidAIState@@HW4equipSlot_t@@@Z
// EA: 0x829F8548, RVA: 0x009F8548
bool idAI2::StartReloading(idAIFSM* const fsm, idAIState* const state,
        const int currentTime, equipSlot_t reloadSlot) {
    if (fsm == nullptr || Services(*this) == nullptr) {
        return false;
    }
    int slot = static_cast<int>(reloadSlot);
    if (reloadSlot != EQUIP_NONE) {
        if (slot < 0 || slot >= EQUIP_MAX
                || !core.reloadWeaponPresent[slot]
                || (!core.reloadCurrentAmmoValid[slot]
                    && !core.reloadNextAmmoValid[slot])) {
            Services(*this)->Print(
                "idAI2::StartReloading - requested weapon cannot reload\n");
            return false;
        }
    } else {
        float lowestFill = 2.0f;
        slot = EQUIP_NONE;
        for (int candidate = EQUIP_LEFT_HAND;
                candidate < EQUIP_MAX; ++candidate) {
            if (!core.reloadWeaponPresent[candidate]
                    || (!core.reloadCurrentAmmoValid[candidate]
                        && !core.reloadNextAmmoValid[candidate])) {
                continue;
            }
            const int clipSize = core.reloadClipSize[candidate];
            if (clipSize <= 0) continue;
            const float fill = static_cast<float>(
                core.reloadAmmoInClip[candidate]) / clipSize;
            if (fill < lowestFill) {
                lowestFill = fill;
                slot = candidate;
            }
        }
        if (slot == EQUIP_NONE) {
            Services(*this)->Print(
                "idAI2::StartReloading - no weapons need reloading\n");
            return false;
        }
        reloadSlot = static_cast<equipSlot_t>(slot);
    }

    EndActionScript();
    Services(*this)->BeginReloadAction(*this, *fsm, state,
        currentTime, reloadSlot, core.reloadAmmoToken[slot]);
    return true;
}

// Retail symbol: ?GetTalkState@idAI2@@QBA?AW4talkState_t@@PBVidEntity@@@Z
// EA: 0x829F8828, RVA: 0x009F8828
talkState_t idAI2::GetTalkState(const idEntity* const activator) const {
    if (core.relaxedChatter || !core.hasPlayerInteraction) {
        return TALKSTATE_NONE;
    }
    const idPlayer* const player =
        reinterpret_cast<const idPlayer*>(activator);
    const bool hasContent = core.interactionHasJob
        || core.interactionHasMessageVoiceOver
        || core.interactionHasMessageTrigger
        || (player != nullptr && EverHasGoodsToSell(player))
        || (player != nullptr && Services(*this) != nullptr
            && Services(*this)->PlayerHasCompletedJobForAI(
                *player, *this));
    return hasContent ? TALKSTATE_AVAILABLE : TALKSTATE_NONE;
}

// Retail symbol: ?GetTakedownName@idAI2@@QAAXABV?$idList@VidStr@@$04@@AAVidStr@@@Z
// EA: 0x829F8908, RVA: 0x009F8908
void idAI2::GetTakedownName(const idList<idStr, 5>& takedowns,
        idStr& takedownName) {
    if (takedowns.Num() <= 0) {
        if (Services(*this) != nullptr) {
            Services(*this)->Print(" invalid takedown ID \n");
        }
        return;
    }
    const int index = core.takedownId < 0
        ? CoreRandomInt(*this, takedowns.Num())
        : std::max(0, std::min(core.takedownId, takedowns.Num() - 1));
    takedownName = takedowns[index];
}

// Retail symbol: ?GetUsableState@idAI2@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA: 0x829F8A20, RVA: 0x009F8A20
usableState_t idAI2::GetUsableState(const idEntity* const activator,
        const idFocusTrace& focusTrace) const {
    if (core.disassembleLootCount > 0) return USABLE_DISASSEMBLE;
    if ((core.dead && !core.dying) || core.deathLootOverride) {
        return core.lootable && (!core.looted || core.hasLootableItems)
            ? USABLE_LOOT : USABLE_NOT_USABLE;
    }
    if (core.taggableBehavior && core.passified) {
        return !core.hasMutantTag
            ? USABLE_AI_TAGGABLE : USABLE_NOT_USABLE;
    }
    if (activator == nullptr || Services(*this) == nullptr
            || Services(*this)->AttitudeToPlayer(*this,
                *reinterpret_cast<const idPlayer*>(activator)) < 3
            || !core.playerInteractionDeclarationAvailable) {
        return USABLE_NOT_USABLE;
    }
    return Services(*this)->FocusTraceDistance(focusTrace)
                <= GetUsableDistance()
            && core.interactionIsUsable
            && GetTalkState(activator) >= TALKSTATE_AVAILABLE
        ? USABLE_AI_TALK : USABLE_AI_TOWN;
}

// Retail symbol: ?GetOnlineUsableState@idAI2@@UBA?AW4usableState_t@@XZ
// EA: 0x829F8C18, RVA: 0x009F8C18
usableState_t idAI2::GetOnlineUsableState() const {
    if (core.disassembleLootCount > 0) return USABLE_DISASSEMBLE;
    if (core.dead && core.lootable
            && (!core.looted || core.hasLootableItems)
            && core.currentTime > core.deathTime
                + core.lootDelayMilliseconds) {
        return USABLE_LOOT;
    }
    if (!core.dead && core.taggableBehavior
            && core.passified && !core.hasMutantTag) {
        return USABLE_AI_TAGGABLE;
    }
    return USABLE_NOT_USABLE;
}

// Retail symbol: ?IsCrosshairSubdued@idAI2@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@@Z
// EA: 0x829F8D80, RVA: 0x009F8D80
bool idAI2::IsCrosshairSubdued(const idEntity* const activator,
        const idFocusTrace& focusTrace, const usableState_t usable) const {
    if (usable != USABLE_AI_TALK && usable != USABLE_AI_TOWN) {
        return false;
    }
    return GetTalkState(activator) < TALKSTATE_AVAILABLE
        || Services(*this) == nullptr
        || Services(*this)->FocusTraceDistance(focusTrace)
            > GetUsableDistance();
}

// Retail symbol: ?ShouldAddConditionalGoodList@idAI2@@QBA_NPBVidPlayer@@H@Z
// EA: 0x829F8E08, RVA: 0x009F8E08
bool idAI2::ShouldAddConditionalGoodList(
        const idPlayer* const player, const int index) const {
    if (index < 0
            || index >= static_cast<int>(core.conditionalMerchantLists.size())) {
        return false;
    }
    const idAI2ConditionalMerchantList& list =
        core.conditionalMerchantLists[index];
    if (list.listGiven) {
        return false;
    }
    for (const auto& condition : list.conditions) {
        if (!PassMerchantTestCondition(condition, player)) {
            return false;
        }
    }
    return true;
}

// Retail symbol: ?IsMerchant@idAI2@@QBA_NPBVidPlayer@@@Z
// EA: 0x829F8EA0, RVA: 0x009F8EA0
bool idAI2::IsMerchant(const idPlayer* const player) const {
    if (player == nullptr || Services(*this) == nullptr
            || Services(*this)->AttitudeToPlayer(*this, *player) < 3
            || core.forceNoMerchant
            || GetTalkState(reinterpret_cast<const idEntity*>(player))
                < TALKSTATE_AVAILABLE) {
        return false;
    }
    return EverHasGoodsToSell(player);
}

// Retail symbol: ?SetAnimWebEvent@idAI2@@QAAXW4aiAnimWeb_t@@W4priority_t@idAnimWebEvent@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4animWebEvent_t@@ABVidEventDef@@@Z
// EA: 0x829F8F48, RVA: 0x009F8F48
void idAI2::SetAnimWebEvent(const aiAnimWeb_t web,
        const idAnimWebEvent::priority_t priority,
        const idAnimWebSubWebIndex subWebIndex,
        const idAnimWebStateIndex stateIndex,
        const animWebEvent_t eventType,
        const idEventDef& eventDefinition) {
    if (Services(*this) != nullptr) {
        Services(*this)->SetAnimationWebEvent(*this, web, priority,
            subWebIndex, stateIndex, eventType, &eventDefinition);
    }
}

// Retail symbol: ?ClearAnimWebEvent@idAI2@@QAAXW4aiAnimWeb_t@@W4priority_t@idAnimWebEvent@@W4animWebEvent_t@@@Z
// EA: 0x829F8FA0, RVA: 0x009F8FA0
void idAI2::ClearAnimWebEvent(const aiAnimWeb_t web,
        const idAnimWebEvent::priority_t priority,
        const animWebEvent_t eventType) {
    (void)priority;
    if (Services(*this) != nullptr) {
        Services(*this)->ClearAnimationWebEvent(*this, web, eventType);
    }
}

// Retail symbol: ?ClearAllAnimWebEvents@idAI2@@QAAXW4aiAnimWeb_t@@W4priority_t@idAnimWebEvent@@@Z
// EA: 0x829F8FB8, RVA: 0x009F8FB8
void idAI2::ClearAllAnimWebEvents(const aiAnimWeb_t web,
        const idAnimWebEvent::priority_t priority) {
    (void)priority;
    if (Services(*this) != nullptr) {
        Services(*this)->ClearAllAnimationWebEvents(*this, web);
    }
}

// Retail symbol: ?ClearWaitForOverrideAnim@idAI2@@QAAXW4priority_t@idAnimWebEvent@@@Z
// EA: 0x829F8FD0, RVA: 0x009F8FD0
void idAI2::ClearWaitForOverrideAnim(
        const idAnimWebEvent::priority_t priority) {
    ClearAnimWebEvent(AIANIMWEB_BODY, priority,
        ANIMWEB_EVENT_START_BLEND_IN);
}

// Retail symbol: ?AnimEventReceived@idAI2@@QBA_NW4priority_t@idAnimWebEvent@@@Z
// EA: 0x829F8FE0, RVA: 0x009F8FE0
bool idAI2::AnimEventReceived(
        const idAnimWebEvent::priority_t priority) const {
    (void)priority;
    return Services(*this) == nullptr
        || !Services(*this)->IsAnyAnimationWebEventPending(
            *this, AIANIMWEB_BODY);
}

// Retail symbol: ?WaitForOverrideAnim@idAI2@@QAA_NW4priority_t@idAnimWebEvent@@W4overrideAnim_t@@W4animWebEvent_t@@_N@Z
// EA: 0x829F9020, RVA: 0x009F9020
bool idAI2::WaitForOverrideAnim(
        const idAnimWebEvent::priority_t priority,
        const overrideAnim_t overrideAnimation,
        const animWebEvent_t eventType, const bool force) {
    if (Services(*this) == nullptr) {
        return false;
    }
    return Services(*this)->WaitForOverrideAnimation(*this, priority,
        overrideAnimation, eventType, force, core.animAfterOverride);
}

namespace {

void SetWaitEvent(idAI2& ai, const aiAnimWeb_t web,
        const idAnimWebEvent::priority_t priority,
        const idAnimWebSubWebIndex subWeb,
        const idAnimWebStateIndex state,
        const animWebEvent_t eventType) {
    idAI2CoreServices* const services = Services(ai);
    if (services != nullptr) {
        services->SetAnimationWebEvent(ai, web, priority, subWeb,
            state, eventType, nullptr);
    }
}

} // namespace

// Retail symbol: ?WaitForAnimToEnd@idAI2@@QAA_NW4priority_t@idAnimWebEvent@@PBD1W4animWebEvent_t@@@Z
// EA: 0x829F9560, RVA: 0x009F9560
bool idAI2::WaitForAnimToEnd(
        const idAnimWebEvent::priority_t priority,
        const char* const subWebName, const char* const stateName,
        const animWebEvent_t eventType) {
    if (Services(*this) == nullptr) return false;
    idAnimWebSubWebIndex currentSubWeb;
    idAnimWebStateIndex currentState;
    idAnimWebSubWebIndex viaSubWeb;
    idAnimWebStateIndex viaState;
    Services(*this)->GetCurrentAnimationWebState(*this,
        AIANIMWEB_BODY, currentSubWeb, currentState);
    if (!Services(*this)->ResolveAnimationWebState(*this,
            AIANIMWEB_BODY, subWebName, stateName, viaSubWeb, viaState)) {
        Services(*this)->Print(
            "idAI2::WaitForAnimToEnd - animation state not found\n");
        return false;
    }
    const awPathResult_t result =
        Services(*this)->ChangeAnimationWebStateVia(*this,
            AIANIMWEB_BODY, currentSubWeb, currentState,
            viaSubWeb, viaState);
    if (result < AWPATH_OK) return false;
    if (result == AWPATH_OK) {
        SetWaitEvent(*this, AIANIMWEB_BODY, priority,
            viaSubWeb, viaState, eventType);
    }
    return true;
}

// Retail symbol: ?WaitForAnimToStart@idAI2@@QAA_NW4aiAnimWeb_t@@W4priority_t@idAnimWebEvent@@PBD2W4animWebEvent_t@@@Z
// EA: 0x829F9680, RVA: 0x009F9680
bool idAI2::WaitForAnimToStart(const aiAnimWeb_t web,
        const idAnimWebEvent::priority_t priority,
        const char* const subWebName, const char* const stateName,
        const animWebEvent_t eventType) {
    if (Services(*this) == nullptr) return false;
    idAnimWebSubWebIndex destinationSubWeb;
    idAnimWebStateIndex destinationState;
    if (!Services(*this)->ResolveAnimationWebState(*this, web,
            subWebName, stateName, destinationSubWeb, destinationState)) {
        return false;
    }
    const awPathResult_t result =
        Services(*this)->ChangeAnimationWebState(*this, web,
            destinationSubWeb, destinationState);
    if (result < AWPATH_OK) return false;
    if (result == AWPATH_OK) {
        SetWaitEvent(*this, web, priority, destinationSubWeb,
            destinationState, eventType);
    }
    return true;
}

// Retail symbol: ?WaitForAnimToStartVia@idAI2@@QAA_NW4aiAnimWeb_t@@W4priority_t@idAnimWebEvent@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@23W4animWebEvent_t@@@Z
// EA: 0x829F9730, RVA: 0x009F9730
bool idAI2::WaitForAnimToStartVia(const aiAnimWeb_t web,
        const idAnimWebEvent::priority_t priority,
        const idAnimWebSubWebIndex destinationSubWeb,
        const idAnimWebStateIndex destinationState,
        const idAnimWebSubWebIndex viaSubWeb,
        const idAnimWebStateIndex viaState,
        const animWebEvent_t eventType) {
    if (Services(*this) == nullptr) return false;
    const awPathResult_t result =
        Services(*this)->ChangeAnimationWebStateVia(*this, web,
            destinationSubWeb, destinationState, viaSubWeb, viaState);
    if (result < AWPATH_OK) return false;
    if (result == AWPATH_OK) {
        SetWaitEvent(*this, web, priority, destinationSubWeb,
            destinationState, eventType);
    }
    return true;
}

// Retail symbol: ?WaitForAnimToStartVia@idAI2@@QAA_NW4aiAnimWeb_t@@W4priority_t@idAnimWebEvent@@PBD222W4animWebEvent_t@@@Z
// EA: 0x829F97B8, RVA: 0x009F97B8
bool idAI2::WaitForAnimToStartVia(const aiAnimWeb_t web,
        const idAnimWebEvent::priority_t priority,
        const char* const subWebName, const char* const stateName,
        const char* const viaSubWebName, const char* const viaStateName,
        const animWebEvent_t eventType) {
    if (Services(*this) == nullptr) return false;
    idAnimWebSubWebIndex destinationSubWeb;
    idAnimWebStateIndex destinationState;
    idAnimWebSubWebIndex viaSubWeb;
    idAnimWebStateIndex viaState;
    if (!Services(*this)->ResolveAnimationWebState(*this, web,
            subWebName, stateName, destinationSubWeb, destinationState)
            || !Services(*this)->ResolveAnimationWebState(*this, web,
                viaSubWebName, viaStateName, viaSubWeb, viaState)) {
        return false;
    }
    return WaitForAnimToStartVia(web, priority, destinationSubWeb,
        destinationState, viaSubWeb, viaState, eventType);
}

// Retail symbol: ?UpdateAttachments@idAI2@@UAAXXZ
// EA: 0x829F98A8, RVA: 0x009F98A8
void idAI2::UpdateAttachments() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIAttachments(*this);
    }
}

// Retail symbol: ?GetTravelSpeeds@idAI2@@QBA?AVidAAS2TravelSpeeds@@XZ
// EA: 0x829F9D10, RVA: 0x009F9D10
idAAS2TravelSpeeds idAI2::GetTravelSpeeds() const {
    idAAS2TravelSpeeds speeds{};
    speeds.defaultSpeed = core.movementType == 1
        ? core.flyMoveMaximum : core.crouchMoveMaximum;
    speeds.crouchSpeed = speeds.defaultSpeed * 0.5f;
    return speeds;
}

// Retail symbol: ?UpdateExtendedClipModel@idAI2@@QAA_NXZ
// EA: 0x829F9D98, RVA: 0x009F9D98
bool idAI2::UpdateExtendedClipModel() {
    if (core.extendedClipModel == nullptr) return true;
    if (core.extendedClipModelEndTime != 0
            && core.currentTime >= core.extendedClipModelEndTime) {
        DeactivateExtendedClipModel();
        return true;
    }
    if (core.extendedClipModelStatus == AIEXTENDEDCLIPMODELSTATUS_HIPS
            && Services(*this) != nullptr) {
        Services(*this)->UpdateExtendedClipModelHips(
            *this, core.extendedClipModel);
    }
    return true;
}

// Retail symbol: ?ReleaseCover@idAI2@@QAAXXZ
// EA: 0x829F9F00, RVA: 0x009F9F00
void idAI2::ReleaseCover() {
    if (!core.currentCoverValid) return;
    core.lastCoverValid = true;
    if (Services(*this) != nullptr) {
        Services(*this)->ReleaseCurrentCover(*this);
    }
    core.currentCoverValid = false;
    core.memoryFlags &= ~1u;
}

// Retail symbol: ?Debug_ScenePoints@idAI2@@QAAXXZ
// EA: 0x829F9F80, RVA: 0x009F9F80
void idAI2::Debug_ScenePoints() {
    if (UsesScenePoints() && Services(*this) != nullptr) {
        Services(*this)->DebugScenePoints(*this);
    }
}

// Retail symbol: ?CoverAvoidanceOptions@idAI2@@QAA_NAA_N000000000000@Z
// EA: 0x829FA668, RVA: 0x009FA668
bool idAI2::CoverAvoidanceOptions(bool& dodgeRoomLeft,
        bool& diveRoomLeft, bool& dodgeCoverLeft,
        bool& diveCoverLeft, bool& dodgeRoomRight,
        bool& diveRoomRight, bool& dodgeCoverRight,
        bool& diveCoverRight, bool& diveRoomForward,
        bool& diveCoverForward, bool& diveRoomBack,
        bool& diveCoverBack, bool& coverByCrouching) const {
    dodgeRoomLeft = diveRoomLeft = dodgeCoverLeft = diveCoverLeft = false;
    dodgeRoomRight = diveRoomRight = dodgeCoverRight = false;
    diveCoverRight = diveRoomForward = diveCoverForward = false;
    diveRoomBack = diveCoverBack = coverByCrouching = false;
    if (!core.visibilityObscurityValid) return false;

    const auto hasRoom = [](const int value) { return value > 1; };
    const auto hasCover = [](const int value) { return value == 3; };
    dodgeRoomLeft = hasRoom(core.visibilityObscurity[3]);
    dodgeRoomRight = hasRoom(core.visibilityObscurity[4]);
    diveRoomLeft = hasRoom(core.visibilityObscurity[1]);
    diveRoomRight = hasRoom(core.visibilityObscurity[2]);
    dodgeCoverLeft = hasCover(core.visibilityObscurity[3]);
    dodgeCoverRight = hasCover(core.visibilityObscurity[4]);
    diveCoverLeft = hasCover(core.visibilityObscurity[1]);
    diveCoverRight = hasCover(core.visibilityObscurity[2]);
    diveRoomForward = hasRoom(core.visibilityObscurity[5]);
    diveCoverForward = hasCover(core.visibilityObscurity[5]);
    diveRoomBack = hasRoom(core.visibilityObscurity[6]);
    diveCoverBack = hasCover(core.visibilityObscurity[6]);
    coverByCrouching = hasCover(core.visibilityObscurity[0]);
    return dodgeRoomLeft || diveRoomLeft || dodgeCoverLeft
        || diveCoverLeft || dodgeRoomRight || diveRoomRight
        || dodgeCoverRight || diveCoverRight || diveRoomForward
        || diveCoverForward || diveRoomBack || diveCoverBack
        || coverByCrouching;
}

// Retail symbol: ?SetupDiveDodgeOrFlinchAction@idAI2@@QAAXW4aiMoveReason_t@@PAVidAIState@@PAVidAIFSM@@@Z
// EA: 0x829FA930, RVA: 0x009FA930
void idAI2::SetupDiveDodgeOrFlinchAction(
        const aiMoveReason_t moveReason, idAIState* const state,
        idAIFSM* const fsm) {
    const int intervalRange = std::max(1,
        core.maximumAimDodgeInterval - core.minimumAimDodgeInterval + 1);
    core.nextDodgeTime = core.currentTime + core.minimumAimDodgeInterval
        + CoreRandomInt(*this, intervalRange);

    if (core.transitionCode >= AI2_OC_DIVE_LEFT
            && core.transitionCode <= AI2_OC_DIVE_BACKWARD) {
        const float currentYaw = std::atan2(
            core.bodyOrientationAxis[0].y,
            core.bodyOrientationAxis[0].x) * 57.2957795131f;
        float destinationYaw = currentYaw;
        if (core.transitionCode == AI2_OC_DIVE_LEFT) {
            destinationYaw += 90.0f;
        } else if (core.transitionCode == AI2_OC_DIVE_RIGHT) {
            destinationYaw -= 90.0f;
        } else if (core.transitionCode == AI2_OC_DIVE_BACKWARD) {
            destinationYaw -= 180.0f;
        }
        EndActionScript();
        if (Services(*this) != nullptr) {
            Services(*this)->BeginDirectionalMoveAction(*this,
                moveReason, state, fsm, currentYaw, destinationYaw);
        }
        return;
    }

    if (core.transitionCode == AI2_OC_CROUCH) {
        core.nextMoveTime = core.currentTime
            + CoreRandomInt(*this, 2000) + 3000;
        return;
    }

    overrideAnim_t animation = ANIMOVERRIDE_NONE;
    switch (core.transitionCode) {
    case AI2_OC_DODGE_LEFT: animation = ANIMOVERRIDE_DODGE_LEFT; break;
    case AI2_OC_DODGE_RIGHT: animation = ANIMOVERRIDE_DODGE_RIGHT; break;
    case AI2_OC_FLINCH_LEFT: animation = ANIMOVERRIDE_FLINCH_LEFT; break;
    case AI2_OC_FLINCH_RIGHT: animation = ANIMOVERRIDE_FLINCH_RIGHT; break;
    default: return;
    }
    EndActionScript();
    if (Services(*this) != nullptr) {
        Services(*this)->BeginOverrideMoveAction(*this, moveReason,
            state, fsm, animation);
    }
}

// Retail symbol: ?CanHideHelmetGroupTest@idAI2@@QAA_NXZ
// EA: 0x829FACA8, RVA: 0x009FACA8
bool idAI2::CanHideHelmetGroupTest() const {
    if (!core.onlyCoverHideNoHelmet) return true;
    if (core.headArmor > 0.0f) return false;
    if (core.encounterGroupHandle < 0) return true;
    return core.encounterLivingMembers != 1;
}

// Retail symbol: ?GetVoiceController@idAI2@@QAAPAVidAIVoiceController@@W4voiceController_t@@@Z
// EA: 0x829FAD78, RVA: 0x009FAD78
idAIVoiceController* idAI2::GetVoiceController(
        const voiceController_t controller) {
    if (controller == VC_SELF) return core.selfVoiceController;
    if (Services(*this) == nullptr) return nullptr;
    if (controller == VC_GROUP && core.encounterGroupHandle >= 0) {
        return Services(*this)->GroupVoiceController(*this);
    }
    if (controller == VC_GLOBAL) {
        return Services(*this)->GlobalVoiceController();
    }
    return nullptr;
}

// Retail symbol: ?GetDefaultSpeedByCurrentWalkState@idAI2@@QBAMXZ
// EA: 0x829FAE28, RVA: 0x009FAE28
float idAI2::GetDefaultSpeedByCurrentWalkState() const {
    return core.walkState == WALKSTATE_RUNNING
        ? core.maximumMoveSpeed : core.minimumMoveSpeed;
}

// Retail symbol: ?GetViewTransform@idAI2@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA: 0x829FAE88, RVA: 0x009FAE88
void idAI2::GetViewTransform(idVec3& origin, idMat3& axis) const {
    if (Services(*this) != nullptr) {
        Services(*this)->GetAIViewTransform(*this,
            core.viewTagValid, core.eyeJointValid, origin, axis);
    } else {
        GetModelTransform(origin, axis);
    }
}

// Retail symbol: ?CalcMovementTurnRate@idAI2@@QBAMABVidVec3@@0@Z
// EA: 0x829FAF20, RVA: 0x009FAF20
float idAI2::CalcMovementTurnRate(const idVec3& idealDirection,
        const idVec3& currentDirection) const {
    (void)idealDirection;
    (void)currentDirection;
    const float speed = core.forcedMoveSpeed != 0.0f
        ? core.forcedMoveSpeed : Length(core.linearVelocity);
    const float speedRange = core.maximumMoveSpeed - core.minimumMoveSpeed;
    float interpolation = 0.0f;
    if (speedRange != 0.0f) {
        const float normalized = std::max(0.0f, std::min(1.0f,
            (speed - core.minimumMoveSpeed) / speedRange));
        interpolation = 1.0f - normalized;
    }
    const float minimumTurnRate = core.forceTurnRate
        ? core.forcedMinimumTurnRate : core.minimumMoveTurnRate;
    const float maximumTurnRate = core.forceTurnRate
        ? core.forcedMaximumTurnRate : core.maximumMoveTurnRate;
    return minimumTurnRate
        + (maximumTurnRate - minimumTurnRate) * interpolation;
}

// Retail symbol: ?Teleport@idAI2@@UAAXABVidVec3@@ABVidAngles@@@Z
// EA: 0x829FB060, RVA: 0x009FB060
void idAI2::Teleport(const idVec3& origin, const idAngles& angles) {
    const idMat3 axis = angles.ToMat3();
    core.physicsOrigin = origin;
    core.bodyOrientationAxis = axis;
    if (Services(*this) != nullptr) {
        Services(*this)->TeleportAI(*this, origin, angles, axis);
    }
}

// Retail symbol: ?RoleHintNodeScore@idAI2@@QBAMABVidVec3@@W4combatHintClass_t@idAICombatHint@@@Z
// EA: 0x829FB110, RVA: 0x009FB110
float idAI2::RoleHintNodeScore(const idVec3& point,
        const idAICombatHint::combatHintClass_t hintClass) const {
    return Services(*this) != nullptr
        ? Services(*this)->CombatRoleHintScore(*this, point, hintClass)
        : 0.0f;
}

// Retail symbol: ?GetAnimationDelta@idAI2@@QBAXPBVidMD6Anim@@AAVidVec3@@@Z
// EA: 0x829FB178, RVA: 0x009FB178
void idAI2::GetAnimationDelta(const idMD6Anim* const animation,
        idVec3& delta) const {
    delta.Set(0.0f, 0.0f, 0.0f);
    if (animation == nullptr || Services(*this) == nullptr) return;
    idVec3 startTranslation;
    idVec3 endTranslation;
    idQuat startRotation;
    if (!Services(*this)->GetAnimationRootDeltas(*animation,
            startTranslation, endTranslation, startRotation)) {
        return;
    }
    delta = startRotation.ToMat3().Transpose()
        * (endTranslation - startTranslation);
}

// Retail symbol: ?PlayAnimWebPath@idAI2@@QAA?BW4awPathResult_t@@ABVidAnimWebPath@@_N@Z
// EA: 0x829FB230, RVA: 0x009FB230
awPathResult_t idAI2::PlayAnimWebPath(const idAnimWebPath& path,
        const bool forceTransition) {
    if (Services(*this) == nullptr || path.IsEmpty()) {
        return AWPATH_FAILED;
    }
    const std::string text(path.c_str());
    const std::string::size_type finalSlash = text.find_last_of("/\\");
    if (finalSlash == std::string::npos || finalSlash + 1 >= text.size()) {
        return AWPATH_FAILED;
    }
    const std::string stateName = text.substr(finalSlash + 1);
    const std::string::size_type priorSlash = text.find_last_of(
        "/\\", finalSlash - 1);
    const std::string subWebName = text.substr(
        priorSlash == std::string::npos ? 0 : priorSlash + 1,
        finalSlash - (priorSlash == std::string::npos ? 0 : priorSlash + 1));
    idAnimWebSubWebIndex subWeb;
    idAnimWebStateIndex state;
    if (!Services(*this)->ResolveAnimationWebState(*this,
            AIANIMWEB_BODY, subWebName.c_str(), stateName.c_str(),
            subWeb, state)) {
        return AWPATH_FAILED;
    }
    const awPathResult_t result = forceTransition
        ? Services(*this)->ForceAnimationWebState(*this,
            AIANIMWEB_BODY, subWeb, state, 1000)
        : Services(*this)->ChangeAnimationWebState(*this,
            AIANIMWEB_BODY, subWeb, state);
    if (result == AWPATH_OK) {
        SetWaitEvent(*this, AIANIMWEB_BODY,
            idAnimWebEvent::PRIORITY_LOW, subWeb, state,
            ANIMWEB_EVENT_DEST_CLAMPED);
    }
    return result;
}

// Retail symbol: ?ShouldScramble@idAI2@@QBA_NXZ
// EA: 0x829FB3E8, RVA: 0x009FB3E8
bool idAI2::ShouldScramble() const {
    if (!core.scramblesEnabled) return false;
    if (core.currentTime - core.lastFiredAtTime < core.scrambleTime
            || IsInAvoidFSM() || (core.groupCondition & 0x10) != 0) {
        return true;
    }
    return core.currentCombatStageRetreat
        && core.encounterStageChangeTime + 8000 > core.currentTime;
}

// Retail symbol: ?UpdateGoreLevel@idAI2@@QAA_N_N@Z
// EA: 0x829FB510, RVA: 0x009FB510
bool idAI2::UpdateGoreLevel(const bool painTest) {
    if (!core.injuredRunsEnabled || !core.injuredRunUsesGoreLevel) {
        return false;
    }
    if (!core.advancedGoreSupported) {
        if (Services(*this) != nullptr) {
            Services(*this)->Error(
                "Advanced goring is not supported for injured-run gore levels");
        }
        return false;
    }
    idAI2GoreGroupRuntime& group = core.goreGroup;
    if (!group.valid) return false;

    int selectedIndex = -1;
    for (int index = 0;
            index < static_cast<int>(group.levels.size()); ++index) {
        const idAI2GoreLevelRuntime& candidate = group.levels[index];
        if ((!candidate.requiresPain || painTest)
                && candidate.goreLevel > group.currentGoreLevel
                && candidate.goreLevel > core.previousInjuryGoreLevel
                && group.healthRatio < candidate.healthRatioThreshold) {
            selectedIndex = index;
        }
    }
    if (selectedIndex < 0) return false;

    const idAI2GoreLevelRuntime& selected = group.levels[selectedIndex];
    group.currentGoreLevel = selected.goreLevel;
    core.injuryGoreLevelIndex = selectedIndex;
    core.injuryDamageGroupName = group.name;
    const idVec3 goreDirection = group.lastHitForward * -1.0f;
    if (Services(*this) != nullptr) {
        Services(*this)->ApplyGoreLevel(*this, group.name,
            selected.goreLevel, goreDirection);
        if (selected.forwardRunIndex != 0.0f) {
            Services(*this)->SetInjuredRunIndices(*this,
                selected.forwardRunIndex, selected.injuredIdleIndex);
        }
    }
    return true;
}

// Retail symbol: ?PauseCurrentThreadTillActionCompletes@idAIScriptProxy@@AAAXXZ
// EA: 0x829FB788, RVA: 0x009FB788
void idAIScriptProxy::PauseCurrentThreadTillActionCompletes() {
    if (owner == nullptr || owner->core.services == nullptr) return;
    idThread* const thread = owner->core.services->CurrentScriptThread();
    if (thread == nullptr) return;
    owner->core.services->RegisterCurrentScriptThread(*owner,
        owner->core.services->ScriptThreadHandle(*thread));
    PauseThreadTillActionCompletes(thread);
}

// Retail symbol: ?PauseCurrentFiberTillActionCompletes@idAIScriptProxy@@AAAXXZ
// EA: 0x829FB7F8, RVA: 0x009FB7F8
void idAIScriptProxy::PauseCurrentFiberTillActionCompletes() {
    if (owner == nullptr || owner->core.services == nullptr) return;
    const int handle = owner->core.services->CurrentScriptFiberHandle();
    if (handle == 0) return;
    owner->core.services->RegisterCurrentScriptFiber(*owner, handle);
    PauseFiberTillActionCompletes(idFiberHandle(handle));
}

// Retail symbol: ?Set@idAIDeathInfo@@QAAXABVidAIDamageInfo@@@Z
// EA: 0x829FC830, RVA: 0x009FC830
idAIDeathInfo::idAIDeathInfo()
    : attacker(nullptr), inflictor(nullptr),
      impulse{ nullptr, idVec3(0.0f, 0.0f, 0.0f),
          idVec3(0.0f, 0.0f, 0.0f), idJointIndex(), 0.0f,
          false, false },
      startDeathTime(0), currentTime(0), services(nullptr) {
}

void idAIDeathInfo::Set(const idAIDamageInfo& information) {
    if (services != nullptr) {
        services->ExtractAIDamageDeathInfo(
            information, attacker, inflictor, impulse);
    }
    startDeathTime = currentTime;
}

// Retail symbol: ??0idAnimWebDefaults@idAI2@@QAA@XZ
// EA: 0x829FCB10, RVA: 0x009FCB10
idAI2::idAnimWebDefaults::idAnimWebDefaults()
    : webPath(), activeLayers(), enabled(false) {
    activeLayers.Clear();
}

// Retail symbol: ??0idAnimWebDefaults@idAI2@@QAA@PBD0_N@Z
// EA: 0x829FCBA8, RVA: 0x009FCBA8
idAI2::idAnimWebDefaults::idAnimWebDefaults(
        const char* const subWebName, const char* const stateName,
        const bool enabledValue)
    : webPath(), activeLayers(), enabled(enabledValue) {
    activeLayers.Clear();
    webPath.SetPath("", subWebName, stateName);
}

// Retail symbol: ??0idAIFocusInfo@idAIVolatile@idAI2@@QAA@XZ
// EA: 0x829FCC90, RVA: 0x009FCC90
idAI2::idAIVolatile::idAIFocusInfo::idAIFocusInfo()
    : foci{}, bodyMinimumTurnRate(45.0f), bodyMaximumTurnRate(540.0f),
      bodyAxis(1.0f),
      enableHeadTracking(true), enableBodyRotation(true),
      enableAutoFocus(true), enableClosestFocus(true),
      checkSurroundingsState() {
}

// Retail symbol: ?RobotBatteryExplodes@idAI2@@QAA_NPAVidEntity@@@Z
// EA: 0x829FCED8, RVA: 0x009FCED8
bool idAI2::RobotBatteryExplodes(idEntity* const attacker) {
    idAI2RobotRuntime& robot = core.robot;
    if (!robot.usesRobot) return false;

    if (robot.curStage >= 0
            && robot.curStage < static_cast<int>(robot.stageTriggers.size())
            && robot.stageTriggers[robot.curStage] != nullptr
            && Services(*this) != nullptr) {
        Services(*this)->ActivateRobotStageTrigger(*this,
            *robot.stageTriggers[robot.curStage], attacker);
    }
    if (robot.isCharging && robot.triggerOnChargingDone != nullptr
            && Services(*this) != nullptr) {
        Services(*this)->ActivateRobotChargingDone(*this,
            *robot.triggerOnChargingDone);
    }

    ++robot.curStage;
    if (robot.curStage < robot.numStages) {
        robot.curStageHealth = robot.stageHealth;
        robot.chargeStartTime = -1;
        robot.isCharging = false;
        robot.chargeDoneTime = -1;
        robot.immuneDoneTime = core.currentTime + 2000;
        robot.noFireTime = core.currentTime + 2000;
        UpdateRobotBossHealth(robot);
        return false;
    }

    core.dead = true;
    if (Services(*this) != nullptr) {
        Services(*this)->KillRobotAI(*this, attacker);
    }
    return true;
}

// Retail symbol: ?OnActivateRobot@idAI2@@QAAXHPAVidEntity@@@Z
// EA: 0x829FD310, RVA: 0x009FD310
void idAI2::OnActivateRobot(const int currentTime,
        idEntity* const activator) {
    idAI2RobotRuntime& robot = core.robot;
    if (!robot.usesRobot || !robot.isCharging) return;
    if (robot.chargeDoneTime == -1) {
        robot.chargeStartTime = currentTime;
        robot.chargeDoneTime = currentTime
            + static_cast<int>(robot.chargeTime * 1000.0f);
    } else if (robot.chargeDoneTime > 0) {
        RobotBatteryExplodes(activator);
    }
}

// Retail symbol: ?OnActivate@idAI2@@UAAXPAVidEntity@@@Z
// EA: 0x829FD3A0, RVA: 0x009FD3A0
void idAI2::OnActivate(idEntity* const activator) {
    if (core.robot.usesRobot) {
        OnActivateRobot(core.currentTime, activator);
    }
}

// Retail symbol: ?UpdateBodyOrientationWhileMoving@idAI2@@QAAXXZ
// EA: 0x829FD520, RVA: 0x009FD520
void idAI2::UpdateBodyOrientationWhileMoving() {
    // Animation movement owns the body axis while its FSM is active.  The
    // normal movement path also leaves orientation untouched during authored
    // movement, traversal, and the transition frames around a move start.
    if (core.animationMoveInterfaceActive
            || core.movementUsesAnimationModes
            || core.playingTraversalAnimation
            || core.gameFrame == core.movementStartFrame
            || core.remainingTransitionFrames > 0) {
        return;
    }
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateMovingBodyOrientation(*this, false);
    }
}

// Retail symbol: ?UpdateBodyOrientationWhileMovingWithFSM@idAI2@@QAAXXZ
// EA: 0x829FDB40, RVA: 0x009FDB40
void idAI2::UpdateBodyOrientationWhileMovingWithFSM() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateMovingBodyOrientation(*this, true);
    }
}

// Retail symbol: ?StartStaggeringPain@idAI2@@IAA_NABVidAIDamageInfo@@@Z
// EA: 0x829FE080, RVA: 0x009FE080
bool idAI2::StartStaggeringPain(
        const idAIDamageInfo& information) {
    return Services(*this) != nullptr
        && Services(*this)->StartAIStaggeringPain(*this, information);
}

// Retail symbol: ?StartStunningPain@idAI2@@IAA_NABVidAIDamageInfo@@@Z
// EA: 0x829FEB88, RVA: 0x009FEB88
bool idAI2::StartStunningPain(
        const idAIDamageInfo& information) {
    return Services(*this) != nullptr
        && Services(*this)->StartAIStunningPain(*this, information);
}

// Retail symbol: ?DamageFeedback@idAI2@@UAAXPAVidEntity@@0PBVidDeclDamage@@AAM@Z
// EA: 0x829FEF30, RVA: 0x009FEF30
void idAI2::DamageFeedback(idEntity* const victim,
        idEntity* const inflictor, const idDeclDamage* const damageDecl,
        float& damage) {
    if (Services(*this) != nullptr) {
        Services(*this)->ApplyAIDamageFeedback(
            *this, victim, inflictor, damageDecl, damage);
    }
}

// Retail symbol: ?EnemyTooCloseToGoProne@idAI2@@QBA_N_N0@Z
// EA: 0x829FF2D0, RVA: 0x009FF2D0
bool idAI2::EnemyTooCloseToGoProne(const bool facingMatters,
        const bool obscurityMatters) const {
    const idEntity* const enemy = core.currentEnemy;
    if (enemy == nullptr
            || obscurityMatters && core.visibilityObscurityValid
                && core.visibilityObscurity[0] == 3
            || !core.currentEnemyVisible
            || Services(*this) == nullptr) {
        return false;
    }

    idVec3 enemyOrigin;
    idVec3 enemyForward;
    if (!Services(*this)->GetEntityPhysicalState(
            *this, enemy, false, enemyOrigin, enemyForward)) {
        return false;
    }
    float distance = core.enemyTooCloseToGoProneDistance;
    if (facingMatters && IsFacingMe(enemy, 0.93f)) {
        distance = core.enemyTooCloseToGoProneFacingDistance;
    }
    const idVec3 delta = enemyOrigin - core.physicsOrigin;
    return Dot(delta, delta) < distance * distance;
}

// Retail symbol: ?WantsToAngryRage@idAI2@@QBA_NXZ
// EA: 0x829FF468, RVA: 0x009FF468
bool idAI2::WantsToAngryRage() const {
    if (!core.angryRageConfigured) {
        return false;
    }
    if (core.useGroupRageLimit
            && core.encounterLivingMembers <= core.noRageMemberCount) {
        return false;
    }
    if (core.wantTauntRageTime > 0
            && core.currentTime - core.wantTauntRageTime < 4000) {
        return false;
    }
    if (core.useGroupRageLimit && core.encounterLivingMembers > 1
            && core.closestGroupMemberToEnemy) {
        return false;
    }
    return core.wantAngryRageTime > 0
        && core.currentTime - core.wantAngryRageTime
            < core.staleAngryRageThreshold
        && core.currentTime >= core.soonestAngryRageTime;
}

// Retail symbol: ?WantsToTauntRage@idAI2@@QBA_NXZ
// EA: 0x829FF6D0, RVA: 0x009FF6D0
bool idAI2::WantsToTauntRage() const {
    if (!core.tauntRageConfigured) {
        return false;
    }
    if (core.useGroupRageLimit
            && core.encounterLivingMembers <= core.noRageMemberCount) {
        return false;
    }
    if (core.useGroupRageLimit && core.encounterLivingMembers > 1
            && core.closestGroupMemberToEnemy) {
        return false;
    }
    return core.wantTauntRageTime > 0
        && core.currentTime - core.wantTauntRageTime
            < core.staleTauntRageThreshold
        && core.currentTime >= core.soonestTauntRageTime;
}

// Retail symbol: ?CanBeTakenDown@idAI2@@QBA?AW4takedownMode_t@@PBVidEntity@@@Z
// EA: 0x829FF8F8, RVA: 0x009FF8F8
takedownMode_t idAI2::CanBeTakenDown(
        const idEntity* const activator) const {
    if (activator == nullptr || core.dead || core.dying
            || core.takedownDeathDisabled || core.takeDownType == 1
            || Services(*this) == nullptr) {
        return TAKEDOWNMODE_UNAVAILABLE;
    }

    idVec3 activatorOrigin;
    idVec3 activatorForward;
    int attitude = 1;
    if (!Services(*this)->GetTakedownActivatorState(*this, *activator,
            activatorOrigin, activatorForward, attitude)) {
        return TAKEDOWNMODE_UNAVAILABLE;
    }
    if (core.takeDownType == 2) {
        attitude = 0;
    }
    if (attitude > 1) {
        return TAKEDOWNMODE_UNAVAILABLE;
    }

    const idVec3 offset = core.physicsOrigin - activatorOrigin;
    const float distance = Length(offset);
    const idVec3 direction = distance > 0.000001f
        ? offset * (1.0f / distance)
        : idVec3(0.0f, 0.0f, 0.0f);
    const bool alertedToActivator = core.currentEnemy == activator
        && core.currentEnemyRecentlyConfirmed;
    if (alertedToActivator || distance >= 100.0f
            || Dot(activatorForward, direction) <= 0.8f
            || Dot(core.bodyOrientationAxis[0], direction) <= 0.8f) {
        return TakedownWindoIsOpen()
            ? TAKEDOWNMODE_WINDOW_OPEN
            : TAKEDOWNMODE_WINDOW_CLOSED;
    }
    return TAKEDOWNMODE_STEALTH;
}

// Retail symbol: ?PlayerInteractionDone@idAI2@@QAAX_N@Z
// EA: 0x829FFC68, RVA: 0x009FFC68
void idAI2::PlayerInteractionDone(const bool playerLeft) {
    if (!core.hasPlayerInteraction) {
        return;
    }
    core.interactionTempState = playerLeft || core.interactionCanBeClosed
        ? 0 // PISTATE_INACTIVE
        : 1; // PISTATE_APPROACH_PLAYED
    if (Services(*this) != nullptr) {
        Services(*this)->SetPlayerInteractionDoneState(
            *this, core.interactionTempState);
    }
}

// Retail symbol: ?AddDynamicGoods@idAI2@@QAAXPAVidPlayer@@@Z
// EA: 0x829FFD28, RVA: 0x009FFD28
void idAI2::AddDynamicGoods(idPlayer* const player) {
    for (int index = 0; index < static_cast<int>(
            core.conditionalMerchantLists.size()); ++index) {
        if (ShouldAddConditionalGoodList(player, index)) {
            AddConditionalGoodList(index);
        }
    }

    for (int index = 0; index < static_cast<int>(
            core.dynamicMerchantGoods.size()); ++index) {
        idAI2DynamicMerchantGood& good = core.dynamicMerchantGoods[index];
        if (!ShouldAddDynamicGood(player, index) || good.inventory == nullptr
                || good.desiredCount <= 0) {
            continue;
        }
        if (good.currentCount < good.desiredCount
                && Services(*this) != nullptr
                && Services(*this)->GiveMerchantItemCount(*this,
                    *good.inventory, good.desiredCount - good.currentCount)) {
            good.currentCount = good.desiredCount;
            good.itemGiven = true;
        }
    }

    if (core.specialDynamicNextGiveTime >= 0) {
        return;
    }
    int validItemCount = 0;
    for (const idDeclInventory* const inventory
            : core.specialDynamicMerchantItems) {
        if (inventory != nullptr) {
            ++validItemCount;
        }
    }
    if (validItemCount == 0) {
        return;
    }

    core.specialDynamicNextGiveTime = 0;
    core.specialDynamicIsMerchant = true;
    if (Services(*this) == nullptr) {
        return;
    }
    if (core.specialDynamicWipeInventory) {
        Services(*this)->WipeMerchantInventory(*this);
    }
    int selectedOrdinal = CoreRandomInt(*this, validItemCount);
    for (const idDeclInventory* const inventory
            : core.specialDynamicMerchantItems) {
        if (inventory != nullptr && selectedOrdinal-- == 0) {
            Services(*this)->GiveMerchantItemCount(*this, *inventory, 1);
            break;
        }
    }
}

// Retail symbol: ?AwareOfEnemy@idAI2@@QAA_NXZ
// EA: 0x82A00078, RVA: 0x00A00078
bool idAI2::AwareOfEnemy() {
    return core.currentEnemy != nullptr;
}

// Retail symbol: ?IsBlockedByFriendly@idAI2@@QAA_NPBVidEntity@@@Z
// EA: 0x82A00100, RVA: 0x00A00100
bool idAI2::IsBlockedByFriendly(const idEntity* const enemy) {
    const idEntity* const blocker = core.currentFriendlyBlocker;
    if (enemy == nullptr || blocker == nullptr || Services(*this) == nullptr
            || Services(*this)->IsDeadActor(*enemy)
            || Services(*this)->IsDeadActor(*blocker)) {
        return false;
    }
    idVec3 enemyOrigin;
    idVec3 unusedForward;
    idVec3 blockerOrigin;
    if (!Services(*this)->GetEntityPhysicalState(
            *this, enemy, false, enemyOrigin, unusedForward)
            || !Services(*this)->GetEntityPhysicalState(
                *this, blocker, false, blockerOrigin, unusedForward)) {
        return false;
    }
    const idVec3 blockerDelta = blockerOrigin - enemyOrigin;
    const idVec3 selfDelta = core.physicsOrigin - enemyOrigin;
    return Dot(blockerDelta, blockerDelta) < Dot(selfDelta, selfDelta);
}

// Retail symbol: ?GetFakeEnemyWeight@idAI2@@QBAMXZ
// EA: 0x82A002A0, RVA: 0x00A002A0
float idAI2::GetFakeEnemyWeight() const {
    return core.fakeEnemy != nullptr ? core.fakeEnemyWeight : 0.0f;
}

// Retail symbol: ?OnAIEvent_Investigate@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x82A00378, RVA: 0x00A00378
void idAI2::OnAIEvent_Investigate(
        const idAIEventSound* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->AddInvestigateEntityState(*this, *event);
    }
}

// Retail symbol: ?OnAIEvent_PlayerAim@idAI2@@AAAXPBVidAIEvent_PlayerAim@@@Z
// EA: 0x82A00438, RVA: 0x00A00438
void idAI2::OnAIEvent_PlayerAim(
        const idAIEvent_PlayerAim* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandlePlayerAimEvent(*this, *event);
    }
}

// Retail symbol: ?ReserveCover@idAI2@@QAAXABVidAICover@@@Z
// EA: 0x82A00868, RVA: 0x00A00868
void idAI2::ReserveCover(const idAICover& cover) {
    if (Services(*this) != nullptr) {
        Services(*this)->ReserveAICover(*this, cover);
    }
    core.currentCoverValid = true;
}

// Retail symbol: ?SetLookFocusEntity@idAI2@@QAAXPBVidEntity@@_NW4aimPoint_t@@H@Z
// EA: 0x82A008D8, RVA: 0x00A008D8
void idAI2::SetLookFocusEntity(const idEntity* const entity,
        const bool keepFocusInView, const aimPoint_t aimPoint,
        const int timeout) {
    if (Services(*this) != nullptr) {
        Services(*this)->SetAILookFocusEntity(
            *this, entity, keepFocusInView, aimPoint, timeout);
    }
}

// Retail symbol: ?GetEnemySenseState@idAI2@@QBAPBVaiSenseState_t@@W4aiSense_t@@@Z
// EA: 0x82A00958, RVA: 0x00A00958
const aiSenseState_t* idAI2::GetEnemySenseState(
        const aiSense_t senseType) const {
    return core.currentEnemy != nullptr && Services(*this) != nullptr
        ? Services(*this)->EnemySenseState(*this, senseType)
        : nullptr;
}

// Retail symbol: ?IsEnemySenseStateValid@idAI2@@QBA_NW4aiSense_t@@@Z
// EA: 0x82A00A20, RVA: 0x00A00A20
bool idAI2::IsEnemySenseStateValid(const aiSense_t senseType) const {
    return core.currentEnemy != nullptr && Services(*this) != nullptr
        && Services(*this)->EnemySenseStateValid(*this, senseType);
}

// Retail symbol: ?CheckForSuspectedToTrailUpdate@idAI2@@QAA_NH@Z
// EA: 0x82A00AD0, RVA: 0x00A00AD0
bool idAI2::CheckForSuspectedToTrailUpdate(const int currentTime) {
    return core.currentEnemy != nullptr && Services(*this) != nullptr
        && Services(*this)->UpdateSuspectedEnemyTrail(*this, currentTime);
}

// Retail symbol: ?FindClosestFocus@idAI2@@AAA_NXZ
// EA: 0x82A00DE8, RVA: 0x00A00DE8
bool idAI2::FindClosestFocus() {
    return core.enableAutoFocus && Services(*this) != nullptr
        && Services(*this)->FindClosestAIFocus(*this);
}

// Retail symbol: ?GetAlertCycle@idAI2@@QBA?AW4alertCycle_t@@XZ
// EA: 0x82A01490, RVA: 0x00A01490
alertCycle_t idAI2::GetAlertCycle() const {
    return static_cast<alertCycle_t>(
        core.playerControlled ? 3 : core.alertCycle);
}

// Retail symbol: ?LeaveActionNode@idAI2@@QAAX_N@Z
// EA: 0x82A014F0, RVA: 0x00A014F0
void idAI2::LeaveActionNode(const bool force) {
    if (Services(*this) != nullptr) {
        Services(*this)->LeaveCurrentActionNode(*this, force);
    }
}

// Retail symbol: ?RestartPlayerInteractions@idAI2@@SAXXZ
// EA: 0x82A01570, RVA: 0x00A01570
void idAI2::RestartPlayerInteractions() {
    const std::vector<idAI2*> instances = g_knownAI2Instances;
    for (idAI2* const ai : instances) {
        if (ai == nullptr || !ai->core.playerInteractionFSMActive) {
            continue;
        }
        ai->PlayerInteractionDone(true);
        if (Services(*ai) != nullptr) {
            Services(*ai)->RestartPlayerInteraction(*ai);
        }
    }
}

// Retail symbol: ?SetRunCycleHint@idAI2@@QAAXW4runIndexType_t@@@Z
// EA: 0x82A016B8, RVA: 0x00A016B8
void idAI2::SetRunCycleHint(const runIndexType_t runType) {
    if ((runType == ANIMWEBAI_RUNINDEXTYPE_UP_STAIRS
            || runType == ANIMWEBAI_RUNINDEXTYPE_DOWN_STAIRS)
            && core.postureCrouched
            && core.currentRunCycleHint == ANIMWEBAI_RUNINDEXTYPE_INJURED
            && Services(*this) != nullptr) {
        Services(*this)->ApplyBleedOutDamage(*this);
    }
    core.currentRunCycleHint = runType;
    if (Services(*this) != nullptr) {
        Services(*this)->SetAIRunCycleHint(*this, runType);
    }
}

// Retail symbol: GetCoverTransionAnimName
// EA: 0x82A017D0, RVA: 0x00A017D0
idStr GetCoverTransionAnimName(const idAICover& cover,
        const idAI2::coverApproach_t approach,
        const bool desireScramble, const bool desireMicro) {
    idStr stateName("runforward");
    if (!desireMicro && desireScramble) {
        stateName.Append("_scramble");
    }
    switch (approach) {
    case idAI2::COVER_APPROACH_FORWARD:
        stateName.Append("_to_fcover");
        break;
    case idAI2::COVER_APPROACH_LEFT:
        stateName.Append("_turn_left_to_fcover");
        break;
    case idAI2::COVER_APPROACH_RIGHT:
        stateName.Append("_turn_right_to_fcover");
        break;
    case idAI2::COVER_APPROACH_TURN_AROUND_LEFT:
    case idAI2::COVER_APPROACH_TURN_AROUND_RIGHT:
        stateName.Append("_turn_back_left_to_fcover");
        break;
    case idAI2::COVER_APPROACH_WRAP_AROUND_LEFT:
    case idAI2::COVER_APPROACH_WRAP_AROUND_RIGHT:
        stateName.Append("_turn_back_right_to_fcover");
        break;
    default:
        break;
    }
    posture_t coverPosture = POSTURE_STANDING;
    for (const idAI2* const ai : g_knownAI2Instances) {
        if (ai != nullptr && ai->core.services != nullptr) {
            coverPosture = ai->core.services->GetCoverPosture(cover);
            break;
        }
    }
    if (coverPosture == POSTURE_CROUCHED) {
        stateName.Append("_crouch");
    }
    if (desireMicro) {
        stateName.Append("_micro");
    }
    idStr result("$weapontransition:");
    result.Append(stateName);
    return result;
}

// Retail symbol: ?GetCoverTransitionRadius@idAI2@@QBAMABVidAICover@@_N1AAVidStr@@AAMAAVidVec3@@AAH@Z
// EA: 0x82A01A50, RVA: 0x00A01A50
float idAI2::GetCoverTransitionRadius(const idAICover& cover,
        const bool desireScramble, const bool desireMicro,
        idStr& animationName, float& yaw, idVec3& delta,
        int& frames) const {
    yaw = 0.0f;
    delta.Set(0.0f, 0.0f, 0.0f);
    frames = 0;
    if (Services(*this) == nullptr) {
        return -1.0f;
    }
    idVec3 coverOrigin;
    idMat3 coverAxis(1.0f);
    posture_t posture = POSTURE_STANDING;
    bool allowTurnAroundLeft = false;
    bool allowTurnAroundRight = false;
    if (!Services(*this)->GetCoverTransitionState(*this, cover,
            coverOrigin, coverAxis, posture, allowTurnAroundLeft,
            allowTurnAroundRight)) {
        return -1.0f;
    }
    const idVec3 sourceOrigin = core.coverTransitionObstacleValid
        ? core.coverTransitionObstacleOrigin : coverOrigin;
    const idVec3 worldOffset = core.physicsOrigin - sourceOrigin;
    const idVec3 relative(
        Dot(coverAxis[0], worldOffset),
        Dot(coverAxis[1], worldOffset),
        Dot(coverAxis[2], worldOffset));
    const coverApproach_t approach = CoverApproachForDirection(relative,
        allowTurnAroundLeft, allowTurnAroundRight);
    if (approach == COVER_APPROACH_MAX
            || approach == COVER_APPROACH_WRAP_AROUND_LEFT
            || approach == COVER_APPROACH_WRAP_AROUND_RIGHT) {
        return -1.0f;
    }

    animationName = GetCoverTransionAnimName(
        cover, approach, desireScramble, desireMicro);
    int animationFrames = 0;
    if (!Services(*this)->GetCoverTransitionAnimation(*this,
            animationName.c_str(), delta, animationFrames)) {
        return -1.0f;
    }
    yaw = std::atan2(delta.y, delta.x);
    frames = animationFrames * 2;
    return std::sqrt(delta.x * delta.x + delta.y * delta.y);
}

// Retail symbol: ?DamageRobot@idAI2@@QAA_NPAVidEntity@@PBVidDeclDamage@@PAUtrace_t@@@Z
// EA: 0x82A02B68, RVA: 0x00A02B68
bool idAI2::DamageRobot(idEntity* const attacker,
        const idDeclDamage* const damageDecl, trace_t* const trace) {
    if (!core.robot.usesRobot || Services(*this) == nullptr) {
        return false;
    }
    return Services(*this)->DamageRobotAI(
        *this, attacker, damageDecl, trace);
}

// Retail symbol: ?ThinkRobot@idAI2@@QAAXH@Z
// EA: 0x82A02F88, RVA: 0x00A02F88
void idAI2::ThinkRobot(const int currentTime) {
    if (!core.robot.usesRobot) {
        return;
    }
    core.currentTime = currentTime;
    if (Services(*this) != nullptr) {
        Services(*this)->ThinkRobotAI(*this, currentTime);
    }
}

// Retail symbol: ?Hide@idAI2@@UAAXXZ
// EA: 0x82A035E8, RVA: 0x00A035E8
void idAI2::Hide() {
    core.hidden = true;
    if (!core.relaxedChatter) {
        SetSolid(false);
    }
    if (Services(*this) != nullptr) {
        Services(*this)->SetAIHidden(*this, true);
    }
}

// Retail symbol: ?ShouldDeadThink@idAI2@@QBA_NXZ
// EA: 0x82A036F0, RVA: 0x00A036F0
bool idAI2::ShouldDeadThink() const {
    return !core.playerControlled && core.alertCycle == 6
        && core.currentTime - core.deathTime > 500;
}

// Retail symbol: ?ShouldEnterDormancy@idAI2@@UAA_NXZ
// EA: 0x82A03770, RVA: 0x00A03770
bool idAI2::ShouldEnterDormancy() {
    if (!core.dormancyEnabled) {
        return false;
    }
    if (core.inNonResidentCollisionArea) {
        return true;
    }
    if (core.hasControllingPlayer || core.animationEdgeTransitionActive
            || (core.afActive || core.afClientAuthoritativeActive)
                && !core.afAtRest
            || core.boundToZipline) {
        return false;
    }
    if (core.previousAlertCycle != 11
            && core.currentTime - core.alertCycleLastTransitionTime < 250) {
        return false;
    }
    if (GetAlertCycle() != static_cast<alertCycle_t>(1)
            || core.actionScriptRunning || core.movementDropping) {
        return false;
    }
    return Services(*this) != nullptr
        ? Services(*this)->BaseShouldEnterDormancy(*this)
        : false;
}

// Retail symbol: ?DamageGroupPopOffArmor@idAI2@@QAAXPAVidDamageGroup@@VidVec3@@1MAA_N@Z
// EA: 0x82A03960, RVA: 0x00A03960
void idAI2::DamageGroupPopOffArmor(idDamageGroup* const damageGroup,
        const idVec3 impactPoint, const idVec3 impactDirection,
        const float damage, bool& armorPoppedOff) {
    if (damageGroup != nullptr && Services(*this) != nullptr) {
        Services(*this)->PopOffAIDamageGroupArmor(*this, damageGroup,
            impactPoint, impactDirection, damage, armorPoppedOff);
    }
}

// Retail symbol: ?KilledNotification@idAI2@@UAAXPBVidEntity@@0PBVidDeclDamage@@M@Z
// EA: 0x82A04140, RVA: 0x00A04140
void idAI2::KilledNotification(const idEntity* const victim,
        const idEntity* const inflictor,
        const idDeclDamage* const damageDecl, const float damage) {
    core.currentActionEntity = victim;
    if (victim != nullptr && victim == core.currentEnemy
            && CoreRandomInt(*this, 100)
                < core.tauntRageAfterKillingEnemyChance) {
        core.wantTauntRageTime = core.currentTime;
    }
    if (Services(*this) != nullptr) {
        Services(*this)->NotifyAIKilledEntity(
            *this, victim, inflictor, damageDecl, damage);
    }
}

// Retail symbol: ?IsFacingMeMoreThanAnyoneElse@idAI2@@QBA_NPBVidEntity@@M@Z
// EA: 0x82A04350, RVA: 0x00A04350
bool idAI2::IsFacingMeMoreThanAnyoneElse(
        const idEntity* const entity, const float dotThreshold) const {
    if (entity == nullptr || core.encounterGroupHandle < 0
            || Services(*this) == nullptr) {
        return true;
    }
    return Services(*this)->IsAIGroupMemberMostFaced(
        *this, *entity, dotThreshold);
}

// Retail symbol: ?RelinquishControl@idAI2@@QAA_NXZ
// EA: 0x82A046A8, RVA: 0x00A046A8
bool idAI2::RelinquishControl() {
    if (!core.playerControlled || Services(*this) == nullptr
            || !Services(*this)->RelinquishAIPlayerControl(*this)) {
        return false;
    }
    core.playerControlled = false;
    core.hasControllingPlayer = false;
    return true;
}

// Retail symbol: ?Takedown@idAI2@@QAAXPAVidEntity@@_N1W4takedownMode_t@@@Z
// EA: 0x82A04A20, RVA: 0x00A04A20
void idAI2::Takedown(idEntity* const activator, const bool dualWield,
        const bool reversedGrip, const takedownMode_t mode) {
    if (activator == nullptr) {
        return;
    }
    if (mode != TAKEDOWNMODE_WINDOW_CLOSED) {
        core.dying = true;
        core.dead = true;
        SetSolid(false);
    }
    if (Services(*this) != nullptr) {
        Services(*this)->StartAITakedown(
            *this, *activator, dualWield, reversedGrip, mode);
    }
}

// Retail symbol: ?Use@idAI2@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA: 0x82A04F98, RVA: 0x00A04F98
bool idAI2::Use(idEntity* const activator, const usableState_t usable) {
    if (activator == nullptr || Services(*this) == nullptr) {
        return false;
    }
    const bool used = Services(*this)->UseAI(*this, *activator, usable);
    if (used && (usable == USABLE_DISASSEMBLE || usable == USABLE_LOOT)) {
        core.looted = true;
    }
    return used;
}

// Retail symbol: ?SetupInteractionView@idAI2@@QAAXPAVidPlayer@@@Z
// EA: 0x82A05658, RVA: 0x00A05658
void idAI2::SetupInteractionView(idPlayer* const player) {
    if (player == nullptr) {
        return;
    }
    core.interactionViewActive = true;
    if (Services(*this) != nullptr) {
        Services(*this)->SetupAIInteractionView(*this, *player);
    }
}

// Retail symbol: ?EndInteractionView@idAI2@@QAAXPAVidPlayer@@@Z
// EA: 0x82A05998, RVA: 0x00A05998
void idAI2::EndInteractionView(idPlayer* const player) {
    if (player == nullptr) {
        return;
    }
    core.interactionViewActive = false;
    if (Services(*this) != nullptr) {
        Services(*this)->EndAIInteractionView(*this, *player);
    }
    SetLookFocusEntity(reinterpret_cast<const idEntity*>(player), true,
        static_cast<aimPoint_t>(1), -1);
}

// Retail symbol: ?InteractionCameraDeactivateCallback@idAI2@@QAAXPAVidPlayer@@@Z
// EA: 0x82A05B00, RVA: 0x00A05B00
void idAI2::InteractionCameraDeactivateCallback(idPlayer* const player) {
    if (player != nullptr) {
        SetLookFocusEntity(reinterpret_cast<const idEntity*>(player), true,
            static_cast<aimPoint_t>(1), -1);
    }
}

// Retail symbol: ?SetActionNodeGroupName@idAI2@@QAAXPBD@Z
// EA: 0x82A05B10, RVA: 0x00A05B10
void idAI2::SetActionNodeGroupName(const char* const groupName) {
    const char* const newName = groupName != nullptr ? groupName : "";
    if (std::strcmp(core.actionNodeGroupName.c_str(), newName) == 0) {
        return;
    }
    core.actionNodeGroupName = newName;
    LeaveActionNode(true);
}

// Retail symbol: ?UpdateAvoidCharacter@idAI2@@IAAXXZ
// EA: 0x82A05B80, RVA: 0x00A05B80
void idAI2::UpdateAvoidCharacter() {
    if (core.avoidCharacterRadius > 0.0f && Services(*this) != nullptr) {
        Services(*this)->UpdateAIAvoidCharacter(*this);
    }
}

// Retail symbol: ?SetFakeEnemy@idAI2@@QAAXPAVidEntity@@@Z
// EA: 0x82A05DE8, RVA: 0x00A05DE8
void idAI2::SetFakeEnemy(idEntity* const entity) {
    core.fakeEnemy = entity;
    core.fakeEnemyWeight = entity != nullptr && Services(*this) != nullptr
        ? Services(*this)->FakeEnemyWeight(*entity) : 0.0f;
    if (Services(*this) != nullptr) {
        Services(*this)->SetAIFakeEnemy(*this, entity);
    }
}

// Retail symbol: ?ClearFakeEnemy@idAI2@@QAAXXZ
// EA: 0x82A05EA8, RVA: 0x00A05EA8
void idAI2::ClearFakeEnemy() {
    SetFakeEnemy(nullptr);
}

// Retail symbol: ?ClearWorldState@idAI2@@QAAXXZ
// EA: 0x82A05F30, RVA: 0x00A05F30
void idAI2::ClearWorldState() {
    core.currentEnemy = nullptr;
    core.currentEnemyVisible = false;
    core.currentEnemyRecentlyConfirmed = false;
    core.currentFriendlyBlocker = nullptr;
    ClearFakeEnemy();
    if (Services(*this) != nullptr) {
        Services(*this)->ClearAIWorldState(*this);
    }
}

// Retail symbol: ?OnAIEvent_Voice@idAI2@@AAAXPBVidAIEventVoice@@@Z
// EA: 0x82A05F80, RVA: 0x00A05F80
void idAI2::OnAIEvent_Voice(const idAIEventVoice* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAIVoiceEvent(*this, *event);
    }
}

// Retail symbol: ?OnAIEvent_Footstep@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x82A06580, RVA: 0x00A06580
void idAI2::OnAIEvent_Footstep(const idAIEventSound* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAISoundEvent(*this, *event, 0);
    }
}

// Retail symbol: ?OnAIEvent_Gunfire@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x82A066D8, RVA: 0x00A066D8
void idAI2::OnAIEvent_Gunfire(const idAIEventSound* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAISoundEvent(*this, *event, 1);
    }
}

// Retail symbol: ?OnAIEvent_Explosion@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x82A06E80, RVA: 0x00A06E80
void idAI2::OnAIEvent_Explosion(const idAIEventSound* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAISoundEvent(*this, *event, 2);
    }
}

// Retail symbol: ?OnAIEvent_ProjectileImpact@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x82A070E0, RVA: 0x00A070E0
void idAI2::OnAIEvent_ProjectileImpact(
        const idAIEventSound* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAISoundEvent(*this, *event, 3);
    }
}

// Retail symbol: ?OnAIEvent_DeadBodyLand@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x82A07348, RVA: 0x00A07348
void idAI2::OnAIEvent_DeadBodyLand(const idAIEventSound* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAISoundEvent(*this, *event, 4);
    }
}

// Retail symbol: ?OnAIEvent_DoorMotion@idAI2@@AAAXPBVidAIEventSound@@@Z
// EA: 0x82A07578, RVA: 0x00A07578
void idAI2::OnAIEvent_DoorMotion(const idAIEventSound* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAISoundEvent(*this, *event, 5);
    }
}

// Retail symbol: ?OnAIEvent_Projectile@idAI2@@AAAXPBVidAIEventProjectile@@@Z
// EA: 0x82A077C8, RVA: 0x00A077C8
void idAI2::OnAIEvent_Projectile(
        const idAIEventProjectile* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAIProjectileEvent(*this, *event);
    }
}

// Retail symbol: ?OnAIEvent_Grenade@idAI2@@AAAXPBVidAIEventProjectedSphere@@@Z
// EA: 0x82A079E0, RVA: 0x00A079E0
void idAI2::OnAIEvent_Grenade(
        const idAIEventProjectedSphere* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAIGrenadeEvent(*this, *event);
    }
}

// Retail symbol: ?OnAIEvent_Vehicle@idAI2@@AAAXPBVidAIEvent_Vehicle@@@Z
// EA: 0x82A07C80, RVA: 0x00A07C80
void idAI2::OnAIEvent_Vehicle(const idAIEvent_Vehicle* const event) {
    if (event != nullptr && Services(*this) != nullptr) {
        Services(*this)->HandleAIVehicleEvent(*this, *event);
    }
}

// Retail symbol: ?StartMoveToCover@idAI2@@QAA_NABVidAICover@@PAVidAIFSM@@PAVidAIState@@_NH@Z
// EA: 0x82A07E50, RVA: 0x00A07E50
bool idAI2::StartMoveToCover(const idAICover& cover, idAIFSM* const fsm,
        idAIState* const state, const bool allowInterrupt,
        const int currentTime) {
    return Services(*this) != nullptr
        && Services(*this)->StartAIMoveToCover(
            *this, cover, fsm, state, allowInterrupt, currentTime);
}

// Retail symbol: ?Debug_Perception@idAI2@@QAAXXZ
// EA: 0x82A08760, RVA: 0x00A08760
void idAI2::Debug_Perception() {
    if (Services(*this) != nullptr) {
        Services(*this)->DebugAIPerception(*this);
    }
}

// Retail symbol: ?ShouldDiveOrDodgeOrCrouch@idAI2@@QAA?AW4aiTransCode_t@idAIStateTransition@@PBVidAIFSM@@@Z
// EA: 0x82A08FD8, RVA: 0x00A08FD8
idAIStateTransition::aiTransCode_t idAI2::ShouldDiveOrDodgeOrCrouch(
        const idAIFSM* const fsm) {
    return static_cast<idAIStateTransition::aiTransCode_t>(
        Services(*this) != nullptr
            ? Services(*this)->ChooseAIDefensiveTransition(*this, fsm)
            : 0);
}

// Retail symbol: ?DormantBegin@idAI2@@UAAXXZ
// EA: 0x82A0A720, RVA: 0x00A0A720
void idAI2::DormantBegin() {
    core.dormant = true;
    if (Services(*this) != nullptr) {
        Services(*this)->BeginAIDormancy(*this);
    }
}

// Retail symbol: ?CanUse@idCheckSurroundingsState@@QBA_NPBVidAI2@@@Z
// EA: 0x82A0A858, RVA: 0x00A0A858
bool idCheckSurroundingsState::CanUse(const idAI2* const ai) const {
    return services != nullptr
        && services->CanUseCheckSurroundings(*this, ai);
}

// Retail symbol: ?FindBestLookInterestPoint@idCheckSurroundingsState@@QBAMPBVidAI2@@AAVidVec3@@@Z
// EA: 0x82A0A910, RVA: 0x00A0A910
float idCheckSurroundingsState::FindBestLookInterestPoint(
        const idAI2* const ai, idVec3& point) const {
    point.Set(0.0f, 0.0f, 0.0f);
    return services != nullptr
        ? services->FindBestAILookInterestPoint(*this, ai, point)
        : 0.0f;
}

// Retail symbol: ?FindAutoFocusEntity@idAI2@@AAAMAAPBVidEntity@@@Z
// EA: 0x82A0AAE8, RVA: 0x00A0AAE8
float idAI2::FindAutoFocusEntity(const idEntity*& entity) {
    entity = nullptr;
    return Services(*this) != nullptr
        ? Services(*this)->FindAIAutoFocusEntity(*this, entity)
        : 0.0f;
}

// Retail symbol: ?StartActionScript@idAI2@@QAAXH@Z
// EA: 0x82A0B260, RVA: 0x00A0B260
void idAI2::StartActionScript(const int currentTime) {
    if (core.dead) {
        return;
    }
    core.currentTime = currentTime;
    core.actionScriptRunning = true;
    SetAlertCycle(static_cast<alertCycle_t>(1));
    if (Services(*this) != nullptr) {
        Services(*this)->BeginAIActionScript(*this, currentTime);
    }
}

// Retail symbol: ?GiveAwarenessOfEntity@idAI2@@QAAXPBVidEntity@@W4alertCycle_t@@@Z
// EA: 0x82A0B3E0, RVA: 0x00A0B3E0
void idAI2::GiveAwarenessOfEntity(const idEntity* const entity,
        const alertCycle_t cycle) {
    if (entity == nullptr) {
        if (Services(*this) != nullptr) {
            Services(*this)->Print(
                "idAI2::GiveAwarenessOfEntity - entity is NULL\n");
        }
        return;
    }
    core.currentEnemy = const_cast<idEntity*>(entity);
    if (Services(*this) != nullptr) {
        Services(*this)->GiveAIAwareness(*this, *entity, cycle);
    }
    SetAlertCycle(cycle);
}

// Retail symbol: ?GiveAwarenessOfNearestPlayer@idAI2@@QAAXW4alertCycle_t@@@Z
// EA: 0x82A0B630, RVA: 0x00A0B630
void idAI2::GiveAwarenessOfNearestPlayer(const alertCycle_t cycle) {
    const idEntity* const player = Services(*this) != nullptr
        ? Services(*this)->NearestPlayerForAI(*this) : nullptr;
    if (player != nullptr) {
        GiveAwarenessOfEntity(player, cycle);
    } else if (Services(*this) != nullptr) {
        Services(*this)->Print(
            "idAI2::ForceAwarenessOfNearestPlayer - no players found.\n");
    }
}

// Retail symbol: ?ForceOpenCombat@idAI2@@QAAXPBVidEntity@@@Z
// EA: 0x82A0B6B0, RVA: 0x00A0B6B0
void idAI2::ForceOpenCombat(const idEntity* const enemy) {
    core.currentEnemy = const_cast<idEntity*>(enemy);
    core.alertCycle = 3;
    if (Services(*this) != nullptr) {
        Services(*this)->ForceAIOpenCombat(*this, enemy);
    }
}

// Retail symbol: ?ForcePlayerInteraction@idAI2@@QAAXPBVidEntity@@@Z
// EA: 0x82A0B868, RVA: 0x00A0B868
void idAI2::ForcePlayerInteraction(const idEntity* const entity) {
    core.interactionEntity = entity;
    core.playerInteractionFSMActive = true;
    if (Services(*this) != nullptr) {
        Services(*this)->ForceAIPlayerInteraction(*this, entity);
    }
}

// Retail symbol: ?ForceFollowFriendly@idAI2@@QAAXPBVidEntity@@@Z
// EA: 0x82A0B980, RVA: 0x00A0B980
void idAI2::ForceFollowFriendly(const idEntity* const friendly) {
    core.friendlyEntity = friendly;
    if (Services(*this) != nullptr) {
        Services(*this)->ForceAIFollowFriendly(*this, friendly);
    }
}

// Retail symbol: ?PositionScore@idAI2@@QAAMABVidVec3@@PBVaiSenseState_t@@AAM222@Z
// EA: 0x82A0BB00, RVA: 0x00A0BB00
float idAI2::PositionScore(const idVec3& candidatePosition,
        const aiSenseState_t* const senseState,
        float& targetDistanceScore, float& aiDistanceScore,
        float& groupScore, float& hintNodeScore) {
    targetDistanceScore = 0.0f;
    aiDistanceScore = 0.0f;
    groupScore = 0.0f;
    hintNodeScore = 0.0f;
    return senseState != nullptr && Services(*this) != nullptr
        ? Services(*this)->ScoreAIPosition(*this, candidatePosition,
            senseState, targetDistanceScore, aiDistanceScore,
            groupScore, hintNodeScore)
        : 0.0f;
}

// Retail symbol: ?Cmd_ForceFollow_f@idAI2@@SAXABVidCmdArgs@@@Z
// EA: 0x82A0C068, RVA: 0x00A0C068
void idAI2::Cmd_ForceFollow_f(const idCmdArgs& args) {
    for (idAI2* const ai : g_knownAI2Instances) {
        if (ai != nullptr && ai->core.services != nullptr) {
            ai->core.services->HandleForceFollowCommand(args);
            return;
        }
    }
}

// Retail symbol: ?ForceFSMIntoExecutingScript@idAIScriptProxy@@AAA_NXZ
// EA: 0x82A0C138, RVA: 0x00A0C138
bool idAIScriptProxy::ForceFSMIntoExecutingScript() {
    if (owner == nullptr || owner->core.executeScriptFSMActive
            || owner->core.services == nullptr
            || !owner->core.services->ForceAIExecuteScriptFSM(*owner)) {
        return false;
    }
    owner->core.executeScriptFSMActive = true;
    return true;
}

// Retail symbol: ?Damage@idAI2@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA: 0x82A0CAC8, RVA: 0x00A0CAC8
float idAI2::Damage(idEntity* const inflictor, idEntity* const attacker,
        const idDeclDamage* const damageDecl, const float damageScale,
        const idVec3& direction, trace_t* const trace) {
    return damageDecl != nullptr && Services(*this) != nullptr
        ? Services(*this)->DamageAI(*this, inflictor, attacker,
            damageDecl, damageScale, direction, trace)
        : 0.0f;
}

// Retail symbol: ?ModifyCrosshairInfo@idAI2@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA: 0x82A0DFB0, RVA: 0x00A0DFB0
bool idAI2::ModifyCrosshairInfo(const idEntity* const activator,
        const idFocusTrace& focusTrace, const usableState_t usable,
        idCrosshairInfo& crosshairInfo) const {
    return Services(*this) != nullptr
        && Services(*this)->ModifyAICrosshairInfo(
            *this, activator, focusTrace, usable, crosshairInfo);
}

// Retail symbol: ?GetKnownEnemiesAsCoverTargets@idAI2@@QBAXAAV?$idList@UcoverTarget_t@idCoverQuery@@$04@@W4aiAwareness_t@@@Z
// EA: 0x82A0E240, RVA: 0x00A0E240
void idAI2::GetKnownEnemiesAsCoverTargets(
        idList<idCoverQuery::coverTarget_t, 5>& targets,
        const aiAwareness_t minimumAwareness) const {
    targets.Clear();
    if (Services(*this) != nullptr) {
        Services(*this)->GatherKnownEnemyCoverTargets(
            *this, &targets, static_cast<int>(minimumAwareness));
    }
}

// Retail symbol: ?ForceEntranceAnimationToCombat@idAI2@@QAAXXZ
// EA: 0x82A0E420, RVA: 0x00A0E420
void idAI2::ForceEntranceAnimationToCombat() {
    core.alertCycle = 3;
    if (Services(*this) != nullptr) {
        Services(*this)->ForceAIEntranceAnimationToCombat(*this);
    }
}

// Retail symbol: ?ForceSearchToEntity@idAI2@@QAAXPAVidEntity@@@Z
// EA: 0x82A0E5F8, RVA: 0x00A0E5F8
void idAI2::ForceSearchToEntity(idEntity* const entity) {
    core.currentEnemy = entity;
    core.alertCycle = 2;
    if (Services(*this) != nullptr) {
        Services(*this)->ForceAISearchToEntity(*this, entity);
    }
}

// Retail symbol: ?ForceAwarenessOfNearestPlayer@idAI2@@QAAXXZ
// EA: 0x82A0E698, RVA: 0x00A0E698
void idAI2::ForceAwarenessOfNearestPlayer() {
    GiveAwarenessOfNearestPlayer(static_cast<alertCycle_t>(3));
}

// Retail symbol: ?ForceSearchToNearestPlayer@idAI2@@QAAXXZ
// EA: 0x82A0E6E0, RVA: 0x00A0E6E0
void idAI2::ForceSearchToNearestPlayer() {
    idEntity* const player = const_cast<idEntity*>(
        Services(*this) != nullptr
            ? Services(*this)->NearestPlayerForAI(*this) : nullptr);
    ForceSearchToEntity(player);
}

// Retail symbol: ?InternalCallEvent@idAIScriptProxy@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA: 0x82A0E728, RVA: 0x00A0E728
idEventArg idAIScriptProxy::InternalCallEvent(const idEventDef& event,
        const idEventArg* const args) {
    idEventArg result;
    if (owner != nullptr && owner->core.services != nullptr) {
        owner->core.services->ProxyCallAIEvent(
            *owner, result, event, args);
    }
    return result;
}

// Retail symbol: ?AIStats_f@@YAXABVidCmdArgs@@@Z
// EA: 0x82A0E938, RVA: 0x00A0E938
void AIStats_f(const idCmdArgs& args) {
    for (const idAI2* const ai : g_knownAI2Instances) {
        if (ai != nullptr && ai->core.services != nullptr) {
            ai->core.services->PrintAIStats(args);
            return;
        }
    }
}

// Retail symbol: ?UpdateGroupStatusConditions@idAI2@@AAAXXZ
// EA: 0x82A0FAC8, RVA: 0x00A0FAC8
void idAI2::UpdateGroupStatusConditions() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIGroupStatusConditions(*this);
    }
}

// Retail symbol: ?InitMemory@idAI2@@AAAXXZ
// EA: 0x82A10298, RVA: 0x00A10298
void idAI2::InitMemory() {
    core.spawnTime = core.currentTime;
    core.confidenceLevel = Services(*this) != nullptr
        ? Services(*this)->InitialAIConfidence(*this) : 0.0f;
}

// Retail symbol: ?InitScriptObjects@idAI2@@AAAXXZ
// EA: 0x82A103A0, RVA: 0x00A103A0
void idAI2::InitScriptObjects() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitializeAIScriptObjects(*this);
    }
}

// Retail symbol: ?InitFSMs@idAI2@@AAAXXZ
// EA: 0x82A10500, RVA: 0x00A10500
void idAI2::InitFSMs() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitializeAIFSMs(*this);
    }
}

// Retail symbol: ?InitActionSettings@idAI2@@AAAXXZ
// EA: 0x82A10638, RVA: 0x00A10638
void idAI2::InitActionSettings() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitializeAIActionSettings(*this);
    }
}

// Retail symbol: ?InitFireControl@idAI2@@AAAXXZ
// EA: 0x82A106C0, RVA: 0x00A106C0
void idAI2::InitFireControl() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitializeAIFireControl(*this);
    }
}

// Retail symbol: ?UpdateMeleeCapabilities@idAI2@@AAAXXZ
// EA: 0x82A107E0, RVA: 0x00A107E0
void idAI2::UpdateMeleeCapabilities() {
    core.meleeCapabilities = Services(*this) != nullptr
        ? Services(*this)->ComputeAIMeleeCapabilities(*this) : 0;
}

// Retail symbol: ?EquipItem@idAI2@@UAA_NPAVidInventoryItem@@W4equipSlot_t@@@Z
// EA: 0x82A109D8, RVA: 0x00A109D8
bool idAI2::EquipItem(idInventoryItem* const item,
        const equipSlot_t equipSlot) {
    if (Services(*this) == nullptr
            || !Services(*this)->EquipAIItem(*this, item, equipSlot)) {
        return false;
    }
    if (Services(*this)->IsWeaponInventoryItem(item)) {
        UpdateMeleeCapabilities();
    }
    return true;
}

// Retail symbol: ?UnequipItem@idAI2@@UAA_NPAVidInventoryItem@@@Z
// EA: 0x82A10A18, RVA: 0x00A10A18
bool idAI2::UnequipItem(idInventoryItem* const item) {
    if (Services(*this) == nullptr
            || !Services(*this)->UnequipAIItem(*this, item)) {
        return false;
    }
    if (Services(*this)->IsWeaponInventoryItem(item)) {
        UpdateMeleeCapabilities();
    }
    return true;
}

// Retail symbol: ?InitHeadTracking@idAI2@@AAAXXZ
// EA: 0x82A10A60, RVA: 0x00A10A60
void idAI2::InitHeadTracking() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitializeAIHeadTracking(*this);
    }
}

// Retail symbol: ?InitPhysics@idAI2@@AAAXXZ
// EA: 0x82A10CF0, RVA: 0x00A10CF0
void idAI2::InitPhysics() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitializeAIPhysics(*this);
    }
}

// Retail symbol: ?InitAAS@idAI2@@AAAXXZ
// EA: 0x82A11130, RVA: 0x00A11130
void idAI2::InitAAS() {
    if (Services(*this) != nullptr) {
        Services(*this)->InitializeAIAAS(*this);
    }
}

// Retail symbol: ?InitAnimation@idAI2@@AAA_NXZ
// EA: 0x82A11328, RVA: 0x00A11328
bool idAI2::InitAnimation() {
    return Services(*this) != nullptr
        && Services(*this)->InitializeAIAnimation(*this);
}

// Retail compiler cleanup label: $LN370. In recovered C++ the scoped
// instrumentation lifetime is represented by ordinary automatic objects.
// EA: 0x82A12198, RVA: 0x00A12198
static void AI2_InitAnimationScopedEventCleanup() {
}

// Retail symbol: ?UpdateTravelFlags@idAI2@@QAAXXZ
// EA: 0x82A12650, RVA: 0x00A12650
void idAI2::UpdateTravelFlags() {
    core.travelFlags = Services(*this) != nullptr
        ? Services(*this)->ComputeAITravelFlags(*this) : 0;
}

// Retail symbol: ?PlayAmbientSound@idAI2@@QAAXPBVidSoundShader@@@Z
// EA: 0x82A12D08, RVA: 0x00A12D08
void idAI2::PlayAmbientSound(const idSoundShader* const soundShader) {
    if (Services(*this) != nullptr) {
        Services(*this)->PlayAIAmbientSound(*this, soundShader);
    }
}

// Retail symbol: ?UpdateEffects@idAI2@@AAAXXZ
// EA: 0x82A12DD0, RVA: 0x00A12DD0
void idAI2::UpdateEffects() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIEffects(*this);
    }
}

// Retail symbol: ?UpdateMovement@idAI2@@IAAXXZ
// EA: 0x82A13750, RVA: 0x00A13750
void idAI2::UpdateMovement() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIMovement(*this);
    }
}

// Retail symbol: ?UpdateConfidenceLevel@idAI2@@AAAXXZ
// EA: 0x82A13890, RVA: 0x00A13890
void idAI2::UpdateConfidenceLevel() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIConfidence(*this);
    }
}

// Retail symbol: ?UpdatePathToEnemy@idAI2@@AAAX_N@Z
// EA: 0x82A14530, RVA: 0x00A14530
void idAI2::UpdatePathToEnemy(const bool forceUpdate) {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIPathToEnemy(*this, forceUpdate);
    }
}

// Retail symbol: ?CheckForGore@idAI2@@QAA_NXZ
// EA: 0x82A14AF0, RVA: 0x00A14AF0
bool idAI2::CheckForGore() {
    return Services(*this) != nullptr
        && Services(*this)->CheckAIGore(*this);
}

// Retail symbol: ?UpdateWorldState@idAI2@@IAAXXZ
// EA: 0x82A14F10, RVA: 0x00A14F10
void idAI2::UpdateWorldState() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIWorldState(*this);
    }
}

// Retail symbol: ?OnAIEvent@idAI2@@UAAXPBVidAIEvent@@@Z
// EA: 0x82A16118, RVA: 0x00A16118
void idAI2::OnAIEvent(const idAIEvent* const event) {
    if (event != nullptr && RespondsToAIEvent(event)
            && Services(*this) != nullptr) {
        Services(*this)->DispatchAIEvent(*this, *event);
    }
}

// Retail symbol: ?HandlePendingAIEvents@idAI2@@IAAXXZ
// EA: 0x82A16418, RVA: 0x00A16418
void idAI2::HandlePendingAIEvents() {
    if (Services(*this) != nullptr) {
        Services(*this)->HandlePendingAIEvents(*this);
    }
}

// Retail symbol: ?UpdateAnimationControllers@idAI2@@UAA_NXZ
// EA: 0x82A17620, RVA: 0x00A17620
bool idAI2::UpdateAnimationControllers() {
    return Services(*this) != nullptr
        && Services(*this)->UpdateAIAnimationControllers(*this);
}

// Retail symbol: ?PathPassesNear@idAI2@@QBA_NABVidVec3@@0HH0HM_N@Z
// EA: 0x82A18278, RVA: 0x00A18278
bool idAI2::PathPassesNear(const idVec3& startPoint,
        const idVec3& goalPoint, const int startAreaNum,
        const int goalAreaNum, const idVec3& testPoint,
        const int testAreaNum, const float nearDistance,
        const bool debug) const {
    return Services(*this) != nullptr
        && Services(*this)->AIPathPassesNear(*this, startPoint,
            goalPoint, startAreaNum, goalAreaNum, testPoint,
            testAreaNum, nearDistance, debug);
}

// Retail symbol: ?Update@idVisibilityObscurity@idAI2@@QAAXPBV2@@Z
// EA: 0x82A185A0, RVA: 0x00A185A0
void idAI2::idVisibilityObscurity::Update(const idAI2* const ai) {
    if (ai != nullptr && Services(*ai) != nullptr) {
        const_cast<idAI2CoreServices*>(Services(*ai))
            ->UpdateAIVisibilityObscurity(
            const_cast<idAI2&>(*ai), this);
    }
}

// Retail symbol: ?TestFireWeapon@idAI2@@QAA_NPAVidWeapon@@AAVidFireParms@@AAVidTestFireResults@@ABUtestFireWeaponParms_t@@@Z
// EA: 0x82A19B20, RVA: 0x00A19B20
bool idAI2::TestFireWeapon(idWeapon* const weapon,
        idFireParms& fireParms, idTestFireResults& results,
        const testFireWeaponParms_t& parameters) {
    return weapon != nullptr && Services(*this) != nullptr
        && Services(*this)->TestAIFireWeapon(
            *this, weapon, fireParms, results, parameters);
}

// Retail symbol: ?TestForBlockedTrace@idAI2@@QBAPBVidEntity@@ABVidFireParms@@ABVidTestFireResults@@AAHABUtestForBlockedTraceParms_t@@@Z
// EA: 0x82A1A188, RVA: 0x00A1A188
const idEntity* idAI2::TestForBlockedTrace(
        const idFireParms& fireParms,
        const idTestFireResults& results, int& blockedJoint,
        const testForBlockedTraceParms_t& parameters) const {
    blockedJoint = -1;
    return Services(*this) != nullptr
        ? Services(*this)->TestAIBlockedTrace(
            *this, fireParms, results, blockedJoint, parameters)
        : nullptr;
}

// Retail symbol: ?FinishFireWeapon@idAI2@@QAA_NPAVidWeapon@@ABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA: 0x82A1A4D8, RVA: 0x00A1A4D8
bool idAI2::FinishFireWeapon(idWeapon* const weapon,
        const idFireParms& fireParms, idTestFireResults& testResults,
        idFinishFireResults& finishResults) {
    return weapon != nullptr && Services(*this) != nullptr
        && Services(*this)->FinishAIFireWeapon(*this, weapon,
            fireParms, testResults, finishResults);
}

// Retail symbol: ?UpdateAimFocus@idAI2@@AAAXXZ
// EA: 0x82A1A758, RVA: 0x00A1A758
void idAI2::UpdateAimFocus() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIAimFocus(*this);
    }
}

// Retail symbol: ?TraceVector@idCheckSurroundingsState@@ABA_NPBVidAI2@@ABVidVec3@@1@Z
// EA: 0x82A1AF18, RVA: 0x00A1AF18
bool idCheckSurroundingsState::TraceVector(const idAI2* const ai,
        const idVec3& start, const idVec3& end) const {
    return services != nullptr
        && services->TraceAISurroundingsVector(*this, ai, start, end);
}

// Retail symbol: ?UpdateDirectionDistanceExponent@idCheckSurroundingsState@@AAAHHPBVidAI2@@@Z
// EA: 0x82A1B0E8, RVA: 0x00A1B0E8
int idCheckSurroundingsState::UpdateDirectionDistanceExponent(
        const int directionToTrace, const idAI2* const ai) {
    return services != nullptr
        ? services->UpdateAISurroundingsDirection(
            *this, directionToTrace, ai)
        : 0;
}

// Retail symbol: ?UpdateLookInterests@idCheckSurroundingsState@@AAAXPBVidAI2@@@Z
// EA: 0x82A1B410, RVA: 0x00A1B410
void idCheckSurroundingsState::UpdateLookInterests(
        const idAI2* const ai) {
    if (services != nullptr) {
        services->UpdateAILookInterests(*this, ai);
    }
}

// Retail symbol: ?Update@idCheckSurroundingsState@@QAAXPBVidAI2@@@Z
// EA: 0x82A1B828, RVA: 0x00A1B828
void idCheckSurroundingsState::Update(const idAI2* const ai) {
    if (services != nullptr && CanUse(ai)) {
        services->UpdateAICheckSurroundings(*this, ai);
    }
}

// Retail symbol: ?FindAutoFocus@idAI2@@AAAXXZ
// EA: 0x82A1BA10, RVA: 0x00A1BA10
void idAI2::FindAutoFocus() {
    if (core.enableAutoFocus && Services(*this) != nullptr) {
        Services(*this)->FindAIAutoFocus(*this);
    }
}

// Retail symbol: ?UpdateActions@idAI2@@QAAXH@Z
// EA: 0x82A1BF18, RVA: 0x00A1BF18
void idAI2::UpdateActions(const int currentTime) {
    core.currentTime = currentTime;
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIActions(*this, currentTime);
    }
}

// Retail symbol: ?PrepTakeCoverFromEntity@idAI2@@QAA?AVidAICover@@PBVidEntity@@00@Z
// EA: 0x82A1BFE8, RVA: 0x00A1BFE8
idAICover idAI2::PrepTakeCoverFromEntity(const idEntity* const enemy,
        const idEntity* const coverReference,
        const idEntity* const coverTarget) {
    idAICover cover;
    if (Services(*this) != nullptr) {
        Services(*this)->PrepAITakeCover(
            *this, cover, enemy, coverReference, coverTarget);
    }
    return cover;
}

// Retail symbol: ?EnableInfluenceTrail@idAI2@@AAAXVidEntityInfluenceTrail@@@Z
// EA: 0x82A1C568, RVA: 0x00A1C568
void idAI2::EnableInfluenceTrail(
        const idEntityInfluenceTrail influenceTrail) {
    core.influenceTrailEnabled = true;
    if (Services(*this) != nullptr) {
        Services(*this)->EnableAIInfluenceTrail(*this, influenceTrail);
    }
}

// Retail symbol: ?Spawn@idAI2@@QAAXXZ
// EA: 0x82A1DA90, RVA: 0x00A1DA90
void idAI2::Spawn() {
    RememberAI2Instance(*this);
    core.spawned = true;
    core.spawnTime = core.currentTime;

    InitMemory();
    InitScriptObjects();
    InitMovement();
    InitPhysics();
    SetMovePushStatus(
        static_cast<aiMovePushStatus_t>(core.movePushStatus), 0);
    InitNav();
    InitAAS();
    UpdateTravelFlags();
    InitAnimation();
    InitHeadTracking();
    UpdateMeleeCapabilities();
    InitActionSettings();
    InitFireControl();
    InitFSMs();

    core.eventOverloadEnableFlags = 0;
    core.eventOverloadDisableFlags = 0;
    if (core.alwaysInCombat) {
        core.previousAlertCycle = core.alertCycle;
        core.alertCycle = 3;
        core.highestAlertCycle = std::max(core.highestAlertCycle,
            core.alertCycle);
    }

    if (Services(*this) != nullptr) {
        Services(*this)->SpawnAI(*this);
    }
}

// Retail symbol: $LN369
// EA: 0x82A1E3E8, RVA: 0x00A1E3E8
static void AI2_SpawnScopedEventCleanup() {
    // Hex-Rays emitted this label for a compiler-generated scoped-event
    // destructor. Ordinary C++ automatic storage performs the cleanup.
}

// Retail symbol: ?Show@idAI2@@UAAXXZ
// EA: 0x82A1E4B0, RVA: 0x00A1E4B0
void idAI2::Show() {
    core.hidden = false;
    core.dormant = false;
    if (!core.dead && !core.dying) {
        SetSolid(true);
    }
    if (Services(*this) != nullptr) {
        Services(*this)->ShowAI(*this);
    }
}

// Retail symbol: ?UpdateFSMs@idAI2@@IAAXXZ
// EA: 0x82A1E658, RVA: 0x00A1E658
void idAI2::UpdateFSMs() {
    core.lastFSMUpdateTime = core.currentTime;
    UpdateActions(core.currentTime);
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAIFSMs(*this);
    }
}

// Retail symbol: ?StartDeathSystem@idAI2@@IAAXXZ
// EA: 0x82A1EA50, RVA: 0x00A1EA50
void idAI2::StartDeathSystem() {
    core.dying = true;
    core.deathSystemStarted = true;
    if (Services(*this) != nullptr) {
        Services(*this)->StartAIDeathSystem(*this);
    }
}

// Retail symbol: ?WaitForTraversal@idAI2@@QAA_NW4priority_t@idAnimWebEvent@@PBD1W4animWebEvent_t@@@Z
// EA: 0x82A1F888, RVA: 0x00A1F888
bool idAI2::WaitForTraversal(
        const idAnimWebEvent::priority_t priority,
        const char* const traversalAnimRef,
        const char* const destinationAnimRef,
        const animWebEvent_t eventType) {
    if (traversalAnimRef == nullptr || traversalAnimRef[0] == '\0') {
        return false;
    }
    idAI2CoreServices* const services = Services(*this);
    return services != nullptr
        && services->WaitForAITraversal(*this, priority,
            traversalAnimRef, destinationAnimRef, eventType);
}

// Retail symbol: ?DormantEnd@idAI2@@UAAXH@Z
// EA: 0x82A1FE30, RVA: 0x00A1FE30
void idAI2::DormantEnd(const int timeDormant) {
    core.dormant = false;
    core.lastDormantDuration = std::max(timeDormant, 0);
    if (Services(*this) != nullptr) {
        Services(*this)->EndAIDormancy(*this, timeDormant);
    }
}

// Retail symbol: ?UpdateLookFocus@idAI2@@AAAXXZ
// EA: 0x82A1FF68, RVA: 0x00A1FF68
void idAI2::UpdateLookFocus() {
    if (Services(*this) != nullptr) {
        Services(*this)->UpdateAILookFocus(*this);
    }
}

// Retail symbol: ?Think_PlayerControl@idAI2@@AAAXXZ
// EA: 0x82A21428, RVA: 0x00A21428
void idAI2::Think_PlayerControl() {
    if (Services(*this) != nullptr) {
        Services(*this)->ThinkAIPlayerControl(*this);
    }
}

// Retail symbol: ?ForceTakeCoverFromEntity@idAI2@@QAAXPBVidEntity@@00@Z
// EA: 0x82A22A28, RVA: 0x00A22A28
void idAI2::ForceTakeCoverFromEntity(const idEntity* const enemy,
        const idEntity* const coverReference,
        const idEntity* const coverTarget) {
    if (enemy == nullptr) {
        return;
    }
    if (Services(*this) != nullptr) {
        Services(*this)->ForceAITakeCoverFromEntity(
            *this, enemy, coverReference, coverTarget);
    }
}

// Retail symbol: ?Think_AIControl@idAI2@@AAAXXZ
// EA: 0x82A23058, RVA: 0x00A23058
void idAI2::Think_AIControl() {
    if (Services(*this) != nullptr) {
        Services(*this)->ThinkAIControl(*this);
    }
}

// Retail symbol: ?UpdateDeaths@idAI2@@SAXXZ
// EA: 0x82A236D0, RVA: 0x00A236D0
void idAI2::UpdateDeaths() {
    const std::vector<idAI2*> instances = g_knownAI2Instances;
    for (idAI2* const ai : instances) {
        if (ai == nullptr) {
            continue;
        }
        idAI2CoreServices* const services = Services(*ai);
        if (services != nullptr) {
            services->UpdateAIDeath(*ai);
        }
    }
}

// Retail symbol: ?ForceTakeCoverFromNearestPlayer@idAI2@@QAAXPBVidEntity@@0@Z
// EA: 0x82A23B10, RVA: 0x00A23B10
void idAI2::ForceTakeCoverFromNearestPlayer(
        const idEntity* const coverReference,
        const idEntity* const coverTarget) {
    if (Services(*this) != nullptr) {
        Services(*this)->ForceAITakeCoverFromNearestPlayer(
            *this, coverReference, coverTarget);
    }
}

// Retail symbol: ?DoSpawnSettings@idAI2@@AAAXXZ
// EA: 0x82A23B88, RVA: 0x00A23B88
void idAI2::DoSpawnSettings() {
    core.spawnSettingsApplied = true;
    if (Services(*this) != nullptr) {
        Services(*this)->ApplyAISpawnSettings(*this);
    }
}

// Retail symbol: ?DropComplete@idAI2@@QAAXXZ
// EA: 0x82A24378, RVA: 0x00A24378
void idAI2::DropComplete() {
    DoSpawnSettings();
    core.dropState = 3;
    core.dropComplete = true;
    if (Services(*this) != nullptr) {
        Services(*this)->CompleteAIDrop(*this);
    }
}

// Retail symbol: ??0idAIVolatile@idAI2@@QAA@XZ
// EA: 0x82A247D8, RVA: 0x00A247D8
idAI2::idAIVolatile::idAIVolatile()
    : focus() {
}

// Retail symbol: ?FirstThink@idAI2@@AAAXXZ
// EA: 0x82A24DA8, RVA: 0x00A24DA8
void idAI2::FirstThink() {
    if (core.firstThinkComplete) {
        return;
    }
    core.firstThinkComplete = true;

    InitEncounterGroup();
    if (core.dropState == 1) {
        core.movementDropping = true;
    } else if (!core.executeScriptFSMActive
            && !core.actionScriptRunning) {
        DoSpawnSettings();
    }

    if (Services(*this) != nullptr) {
        Services(*this)->FirstAIThink(*this);
    }
}

// Retail symbol: ??1idAI2@@UAA@XZ
// EA: 0x82A25570, RVA: 0x00A25570
idAI2::~idAI2() {
    idAI2CoreServices* const services = core.services;
    if (services != nullptr) {
        services->ShutdownAI(*this);
    }
    g_knownAI2Instances.erase(
        std::remove(g_knownAI2Instances.begin(),
            g_knownAI2Instances.end(), this),
        g_knownAI2Instances.end());
}

// Retail symbol: ?Think@idAI2@@UAAXXZ
// EA: 0x82A25EF8, RVA: 0x00A25EF8
void idAI2::Think() {
    if (!core.firstThinkComplete) {
        FirstThink();
    }
    if (core.hidden || core.dormant) {
        return;
    }

    if (Services(*this) != nullptr) {
        Services(*this)->ThinkAI(*this);
    }
    if (core.playerControlled || core.hasControllingPlayer) {
        Think_PlayerControl();
    } else {
        Think_AIControl();
    }
}

// Retail symbol: ??0idAIEditable@@QAA@XZ
// EA: 0x82A28DF8, RVA: 0x00A28DF8
idAIEditable::idAIEditable() {
}

// Retail symbol: ??0idAI2@@QAA@XZ
// EA: 0x82A29238, RVA: 0x00A29238
idAI2::idAI2()
    : editable(), volatileState(), core() {
    RememberAI2Instance(*this);
}
