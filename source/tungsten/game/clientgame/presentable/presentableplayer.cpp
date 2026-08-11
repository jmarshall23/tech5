#include "presentableplayer.h"
#include "presentableai.h"
#include "../../../../shared/idlib/text/cmdargs.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>

namespace {

idUCmdTrackerServices defaultTrackerServices;
idUCmdTrackerServices* trackerServices = &defaultTrackerServices;
idPresentableActorServices defaultActorServices;
idPresentableActorServices* actorServices = &defaultActorServices;
idPresentablePlayerServices defaultPlayerServices;
idPresentablePlayerServices* playerServices = &defaultPlayerServices;

constexpr float SHORT_TO_ANGLE = 360.0f / 65536.0f;
constexpr float ANGLE_TO_SHORT = 65536.0f / 360.0f;

float Normalize180(float angle) {
    angle -= std::floor(angle / 360.0f) * 360.0f;
    if (angle > 180.0f) angle -= 360.0f;
    return angle;
}

float NormalizeAround(float angle, float base) {
    while (angle - base < -180.0f) angle += 360.0f;
    while (angle - base > 180.0f) angle -= 360.0f;
    return angle;
}

std::int8_t ClampMove(std::int8_t value, std::int8_t minimum,
        std::int8_t maximum) {
    return (std::max)(minimum, (std::min)(maximum, value));
}

void RecalculateDelta(idUCmdTracker& tracker) {
    tracker.deltaViewAngles.pitch = tracker.viewAngles.pitch
        - tracker.usercmd.angles[0] * SHORT_TO_ANGLE;
    tracker.deltaViewAngles.yaw = tracker.viewAngles.yaw
        - tracker.usercmd.angles[1] * SHORT_TO_ANGLE;
    tracker.deltaViewAngles.roll = tracker.viewAngles.roll
        - tracker.usercmd.angles[2] * SHORT_TO_ANGLE;
    tracker.prevcmd.angles[0] = tracker.usercmd.angles[0];
    tracker.prevcmd.angles[1] = tracker.usercmd.angles[1];
    tracker.prevcmd.angles[2] = tracker.usercmd.angles[2];
}

int PlayerButtons(const usercmd_t& command) {
    return command.inhibited ? 0 : command.buttons;
}

bool EqualsIgnoreCase(const char* left, const char* right) {
    if (left == nullptr || right == nullptr) return left == right;
    while (*left != '\0' && *right != '\0') {
        const unsigned char l = static_cast<unsigned char>(*left++);
        const unsigned char r = static_cast<unsigned char>(*right++);
        if (std::tolower(l) != std::tolower(r)) return false;
    }
    return *left == *right;
}

} // namespace

void Tungsten_SetPresentableActorServices(
        idPresentableActorServices* services) {
    actorServices = services != nullptr ? services : &defaultActorServices;
}

void Tungsten_SetPresentablePlayerServices(
        idPresentablePlayerServices* services) {
    playerServices = services != nullptr ? services : &defaultPlayerServices;
}

idPresentablePlayerServices* Tungsten_GetPresentablePlayerServices() {
    return playerServices;
}

idPresentablePlayer::idPresentablePlayer() {
    screenPrtState.SetNum(5);
    zoomFov.Init(0.0f, 0.0f, playerServices->GetDefaultFov(),
        playerServices->GetDefaultFov());
    scriptFunction_resumeMap.pThis = this;
    scriptFunction_goToMission.pThis = this;
}

idPresentablePlayer::idPresentablePlayer(idPlayer* entity_,
        idRenderModel* renderModel, idAnimStack* stack,
        idInventoryCollection* inventory_,
        const idDeclPlayerProps* properties, int entityNumber_)
    : idPresentableActor(reinterpret_cast<idEntity*>(entity_), renderModel,
        stack, inventory_,
        entityNumber_, nullptr, playerServices->IsMultiplayer())
    , playerProps(properties)
    , activeInventory(inventory_) {
    screenPrtState.SetNum(5);
    zoomFov.Init(0.0f, 0.0f, playerServices->GetDefaultFov(),
        playerServices->GetDefaultFov());
    scriptFunction_resumeMap.pThis = this;
    scriptFunction_goToMission.pThis = this;
}

idPresentablePlayer::~idPresentablePlayer() {
    playerServices->ShutdownPlayer(*this);
    loadedGuis[GUI_GENERAL_GAME_USE] = nullptr;
    isGeneralGuiCardGame = false;
    for (int gui = 0; gui < GUI_COUNT; ++gui) {
        if (loadedGuis[gui] != nullptr) {
            playerServices->DestroyPlayerGui(
                reinterpret_cast<idSWF*>(loadedGuis[gui]));
            loadedGuis[gui] = nullptr;
        }
    }
}

idPresentableActor::idPresentableActor()
    : inventory(nullptr)
    , actorModifierManager(this)
    , overdrivePoints(0.0f) {
}

idPresentableActor::idPresentableActor(idEntity* entity_,
        idRenderModel* renderModel, idAnimStack* stack,
        idInventoryCollection* actorInventory, int entityNumber_,
        const idDeclFX* fx, bool sphereModel)
    : idPresentableAnimatedEntity(entity_, renderModel, stack,
        entityNumber_, fx, sphereModel)
    , inventory(actorInventory)
    , actorModifierManager(this)
    , overdrivePoints(0.0f) {
}

idPresentableActor::~idPresentableActor() {
    actorModifierManager = nullptr;
}

void idPresentableActor::PostSerializeRead(bool firstClientFrame) {
    idPresentableAnimatedEntity::PostSerializeRead(firstClientFrame);
    actorServices->PostSerializeRead(*this, firstClientFrame);
}

void idPresentableActor::ClientThink(int currentTime, float fraction,
        bool predict) {
    idPresentableAnimatedEntity::ClientThink(currentTime, fraction, predict);
    actorServices->Think(*this);
}

void idPresentableActor::ServerThink(int currentTime) {
    actorServices->UpdatePhysicsTime(*this, currentTime);
    actorServices->Think(*this);
}

void idPresentableActor::HandleActorModifierMessage(std::uint32_t uid,
        std::uint8_t modifierIndex) {
    actorServices->HandleModifierMessage(*this, uid, modifierIndex);
}

float idPresentableActor::GetSpeedScale() {
    return actorServices->GetSpeedModifier(*this);
}

float idPresentableActor::GetDamageScale() {
    return actorServices->GetDamageModifier(*this);
}

bool idPresentableActor::IsOverdriveDisabled() {
    return actorServices->IsOverdriveDisabled(*this);
}

void idPresentableActor::Serialize(idSerializer& serializer) {
    idPresentableAnimatedEntity::Serialize(serializer);
    actorServices->SerializeModifiers(*this, serializer);
    serializer.Serialize(overdrivePoints);
}

void idPresentablePlayer::ExecuteCoopScoringCallout(
        const idDeclOnlineScoringCallout* callout) {
    if (callout == nullptr || !playerServices->HasLocalPresentablePlayer()) {
        return;
    }
    const idSoundShader* sound =
        playerServices->GetScoringCalloutSound(callout);
    if (sound != nullptr) {
        StartSoundShader(SND_CHANNEL_ANY, sound, 0, 0);
    }
}

idPresentablePlayer::moveBufferItem_t&
idPresentablePlayer::GetMoveBufferItemForClientGameFrame(int frame) {
    return moveBuffer[frame % 64];
}

void idPresentablePlayer::WriteFireDataToUserCmd(usercmd_t& command) {
    command.fireCount = clientFire.fireCount;
    command.fireAngles[0] = clientFire.fireAngles[0];
    command.fireAngles[1] = clientFire.fireAngles[1];
    command.firePos[0] = clientFire.firePos[0];
    command.firePos[1] = clientFire.firePos[1];
    command.firePos[2] = clientFire.firePos[2];
}

bool idPresentablePlayer::IsInterpolated() const {
    return playerServices->IsClient()
        && !playerServices->IsLocallyControlled(*this);
}

bool idPresentablePlayer::IsLocallyControlled() const {
    return playerServices->IsLocallyControlled(*this);
}

void idPresentablePlayer::PlayLootSound(bool hasLoot) {
    StartSoundShader(SND_CHANNEL_ANY,
        playerServices->GetLootSound(hasLoot), 0, 0);
}

localView_t* idPresentablePlayer::GetLocalView() {
    if (!IsLocallyControlled()) {
        return nullptr;
    }
    if (!localView.initialized) {
        localView.initialized = true;
        playerServices->InitializeLocalView(localView);
    }
    return &localView;
}

void idPresentablePlayer::ChallengeExit() {
    challengeLeavingSoon = true;
    challengeLocalRestart = false;
    challengeRemoteRestart = false;
}

void idPresentablePlayer::SetPlayerGuiFile(playerGuis_t gui,
        const char* filename, bool purgableImage) {
    guiNames[gui] = filename != nullptr ? filename : "";
    purgableGuis[gui] = purgableImage;
}

bool idPresentablePlayer::HandleGuiEvent(const sysEvent_t* event) {
    for (int gui = GUI_COUNT - 1; gui >= 0; --gui) {
        if (loadedGuis[gui] != nullptr
                && playerServices->HandleGuiEvent(loadedGuis[gui], event)) {
            return true;
        }
    }
    return false;
}

void idUCmdInhibit::DebugPrintInhibitFlagNames(inhibitFlags_t flags) {
    std::ostringstream output;
    output << "DebugPrintInhibitFlagNames " << static_cast<int>(flags)
        << "\n";
    struct flagName_t { int flag; const char* name; };
    static const flagName_t names[] = {
        {UCMD_INHIBIT_MOVEMENT_FWD, "UCMD_INHIBIT_MOVEMENT_FWD"},
        {UCMD_INHIBIT_MOVEMENT_RT, "UCMD_INHIBIT_MOVEMENT_RT"},
        {UCMD_INHIBIT_MOVEMENT_UP, "UCMD_INHIBIT_MOVEMENT_UP"},
        {UCMD_INHIBIT_VIEW, "UCMD_INHIBIT_VIEW"},
        {UCMD_INHIBIT_BUTTONS, "UCMD_INHIBIT_BUTTONS"},
        {UCMD_INHIBIT_MOVEMENT_ONCE, "UCMD_INHIBIT_MOVEMENT_ONCE"},
        {UCMD_INHIBIT_VIEW_ONCE, "UCMD_INHIBIT_VIEW_ONCE"},
        {UCMD_INHIBIT_BUTTONS_ONCE, "UCMD_INHIBIT_BUTTONS_ONCE"},
        {UCMD_INHIBIT_VIEW_DISCARD, "UCMD_INHIBIT_VIEW_DISCARD"}
    };
    if (flags == UCMD_INHIBIT_NONE) {
        output << " No flags set\n";
    } else {
        for (const flagName_t& item : names) {
            if ((static_cast<int>(flags) & item.flag) != 0) {
                output << " - " << item.name << "\n";
            }
        }
    }
    playerServices->Print(output.str().c_str());
}

void p_printInhibitFlags_f(const idCmdArgs& args) {
    const int playerIndex = args.Argc() > 1
        ? std::atoi(args.Argv(1)) : 0;
    idPresentablePlayer* player = playerServices->FindPlayer(playerIndex);
    std::ostringstream output;
    if (player == nullptr) {
        output << "Could not print inhibit flags: #" << playerIndex
            << " not a valid player\n";
        playerServices->Print(output.str().c_str());
        return;
    }
    output << "The following flags are inhibited on player #"
        << playerIndex << "\n";
    playerServices->Print(output.str().c_str());
    idUCmdInhibit::DebugPrintInhibitFlagNames(
        static_cast<idUCmdInhibit::inhibitFlags_t>(player->inhibitFlags));
    if (player->restrictedGamePlay) {
        playerServices->Print("Restricted Gameplay is ON\n");
    }
    if (!player->allowWeaponChange || player->inhibitChangeWeapon) {
        playerServices->Print("Weaponchange is BLOCKED\n");
    }
    if (player->inhibitRaiseWeapon) {
        playerServices->Print("Raise weapon is BLOCKED\n");
    }
}

void sub_status_f(const idCmdArgs& args) {
    const int playerIndex = args.Argc() > 1
        ? std::atoi(args.Argv(1)) : 0;
    for (int language = 0; language < 10; ++language) {
        bool enabled = false;
        if (!playerServices->GetSubtitleForLanguage(playerIndex, language,
                enabled)) {
            std::ostringstream failure;
            failure << "Could not find profile for player #" << playerIndex
                << "\n";
            playerServices->Print(failure.str().c_str());
            return;
        }
        std::ostringstream line;
        line << "#" << language << " "
            << playerServices->GetLanguageIsoName(language) << ": "
            << (enabled ? 1 : 0) << "\n";
        playerServices->Print(line.str().c_str());
    }
}

void sub_set_f(const idCmdArgs& args) {
    const int playerIndex = args.Argc() > 3
        ? std::atoi(args.Argv(3)) : 0;
    int selectedLanguage = -1;
    for (int language = 0; language < 10; ++language) {
        if (EqualsIgnoreCase(args.Argv(1),
                playerServices->GetLanguageIsoName(language))) {
            selectedLanguage = language;
            break;
        }
    }
    if (selectedLanguage < 0) {
        std::ostringstream failure;
        failure << "Could not language " << args.Argv(1) << "\n";
        playerServices->Print(failure.str().c_str());
        return;
    }
    if (!playerServices->SetSubtitleForLanguage(playerIndex,
            selectedLanguage, std::atoi(args.Argv(2)) != 0)) {
        std::ostringstream failure;
        failure << "Could not find profile for player #" << playerIndex
            << "\n";
        playerServices->Print(failure.str().c_str());
    }
}

idActor* idPresentableActor::GetActorEntity() const {
    return actorServices->GetActorEntity(*this);
}

idWeapon* idPresentableActor::GetEquippedWeapon(equipSlot_t slot) {
    return actorServices->GetEquippedWeapon(*this, slot);
}

idWeapon* idPresentableActor::GetEquippedWeapon() {
    return actorServices->GetEquippedWeapon(*this);
}

void idPresentablePlayer::UpdateSerializedView() {
    playerServices->GetSerializedView(*this, serializedViewOrigin,
        serializedViewAxis);
}

void idPresentablePlayer::ClientJobSync() {
    idPresentableAnimatedEntity::ClientJobSync();
    playerServices->SyncHands(*this);
}

void idPresentablePlayer::UpdateScoringCallout() {
    if (lastCalloutHistoryIndex <= calloutHistoryIndex - 4) {
        lastCalloutHistoryIndex = calloutHistoryIndex - 4;
    }
    const idDeclOnlineScoringCallout* bestCallout = nullptr;
    int bestPriority = 0;
    while (lastCalloutHistoryIndex < calloutHistoryIndex) {
        const idDeclOnlineScoringCallout* callout =
            calloutHistory[lastCalloutHistoryIndex % 4].callout;
        if (callout != nullptr) {
            const int priority =
                playerServices->GetScoringCalloutPriority(callout);
            if (priority != 0) {
                if (priority >= bestPriority) {
                    bestPriority = priority;
                    bestCallout = callout;
                }
            } else {
                ExecuteCoopScoringCallout(callout);
            }
        }
        ++lastCalloutHistoryIndex;
    }
    if (bestCallout != nullptr) {
        ExecuteCoopScoringCallout(bestCallout);
    }

    if (lastCoopScoringIndex <= coopScoringIndex - 4) {
        lastCoopScoringIndex = coopScoringIndex - 4;
    }
    while (lastCoopScoringIndex < coopScoringIndex) {
        coopScoreItem_t& item =
            coopScoreHistory[lastCoopScoringIndex % 4];
        item.time = playerServices->GetScaledGameTime();
        item.index = lastCoopScoringIndex;
        ++lastCoopScoringIndex;
    }
}

void idPresentablePlayer::ClientUpdateFocusEntity() {
    playerServices->UpdateFocus(*this, firstPersonViewOrigin,
        firstPersonViewAxis);
}

idWeapon* idPresentablePlayer::SelectBestWeapon() {
    idWeapon* bestWeapon = nullptr;
    float bestPriority = -1.0f;
    idWeapon* equipped = GetEquippedWeapon(EQUIP_RIGHT_HAND);
    const float equippedPriority =
        playerServices->GetWeaponSelectionPriority(equipped);
    const int weaponCount = playerServices->GetInventoryWeaponCount(*this);
    for (int weaponNumber = 0; weaponNumber < weaponCount; ++weaponNumber) {
        idWeapon* weapon = playerServices->GetInventoryWeapon(*this,
            weaponNumber);
        if (weapon == nullptr) continue;
        const float priority =
            playerServices->GetWeaponSelectionPriority(weapon);
        if (priority != equippedPriority && priority > bestPriority
                && playerServices->WeaponIsUsable(*this, weapon)) {
            bestPriority = priority;
            bestWeapon = weapon;
        }
    }
    if (bestWeapon != nullptr) {
        playerServices->SelectHandsWeapon(*this, EQUIP_RIGHT_HAND,
            bestWeapon, false);
    }
    return bestWeapon;
}

void idPresentablePlayer::SelectFists(bool deleteCurrentWeapon) {
    idWeapon* fists = playerServices->FindInventoryWeapon(*this, "fists");
    if (fists == nullptr) return;
    playerServices->SelectHandsWeapon(*this,
        playerServices->GetWeaponEquipSlot(fists), fists, false);
    if (deleteCurrentWeapon) {
        playerServices->DeleteCurrentHandsWeapon(*this);
    }
}

void idPresentablePlayer::GetViewTransform(idVec3& outOrigin,
        idMat3& outAxis) const {
    outOrigin = firstPersonViewOrigin;
    outAxis = firstPersonViewAxis;
}

void idPresentablePlayer::StartScreenParticle(
        unsigned int screenParticleType, float excludeAngle) {
    if (screenParticleType >= static_cast<unsigned int>(screenPrtState.Num())) {
        return;
    }
    screenParticleState_t& state = screenPrtState[screenParticleType];
    if (state.pModel == nullptr || state.isActive) return;
    idVec3 physicsOrigin;
    idMat3 physicsAxis;
    playerServices->GetPlayerPhysicsTransform(*this, physicsOrigin,
        physicsAxis);
    playerServices->StartScreenParticleModel(state.pModel, physicsOrigin,
        physicsAxis, playerServices->RandomUnitFloat(),
        playerServices->GetScaledGameTime(), 0);
    state.excludeAngle = excludeAngle;
    state.fadeStartTime = 0;
    state.fadeEndTime = 0;
    state.isActive = true;
}

void idPresentablePlayer::StopScreenParticle(
        unsigned int screenParticleType, int fadeTime) {
    if (screenParticleType >= static_cast<unsigned int>(screenPrtState.Num())) {
        return;
    }
    screenParticleState_t& state = screenPrtState[screenParticleType];
    if (fadeTime != 0) {
        state.fadeStartTime = playerServices->GetScaledGameTime();
        state.fadeEndTime = state.fadeStartTime + fadeTime;
    } else {
        if (state.pModel != nullptr
                && !playerServices->IsScreenParticleModelUnlinked(
                    state.pModel)) {
            playerServices->UnlinkScreenParticleModel(state.pModel);
        }
        state.isActive = false;
    }
}

int idPresentablePlayer::StartFxScreenParticle(idRenderModel* particleModel,
        float excludeAngle) {
    if (particleModel == nullptr) return -1;
    int handle = 0;
    while (handle < 4 && fxScreenPrtState[handle].isActive) ++handle;
    if (handle == 4) return -1;
    idVec3 physicsOrigin;
    idMat3 physicsAxis;
    playerServices->GetPlayerPhysicsTransform(*this, physicsOrigin,
        physicsAxis);
    playerServices->StartScreenParticleModel(particleModel, physicsOrigin,
        physicsAxis, playerServices->RandomUnitFloat(),
        playerServices->GetScaledGameTime(), entityNumber + 1);
    screenParticleState_t& state = fxScreenPrtState[handle];
    state.pModel = particleModel;
    state.excludeAngle = excludeAngle;
    state.fadeStartTime = 0;
    state.fadeEndTime = 0;
    state.isActive = true;
    return handle;
}

void idPresentablePlayer::StopFxScreenParticle(unsigned int handle,
        int fadeTime) {
    if (handle >= 4) return;
    screenParticleState_t& state = fxScreenPrtState[handle];
    if (fadeTime != 0) {
        state.fadeStartTime = playerServices->GetScaledGameTime();
        state.fadeEndTime = state.fadeStartTime + fadeTime;
    } else {
        if (state.pModel != nullptr
                && !playerServices->IsScreenParticleModelUnlinked(
                    state.pModel)) {
            playerServices->UnlinkScreenParticleModel(state.pModel);
        }
        state.pModel = nullptr;
        state.isActive = false;
    }
}

void idPresentablePlayer::UpdateScreenParticles() {
    idVec3 viewOrigin;
    idMat3 viewAxis;
    playerServices->GetViewTransform(*this, viewOrigin, viewAxis);
    viewOrigin = viewOrigin + viewAxis[0]
        * playerServices->GetScreenParticleOffset();
    const float upDot = viewAxis[0].z;
    const int gameTime = playerServices->GetScaledGameTime();

    const auto updateState = [&](screenParticleState_t& state,
            bool clearModelWhenDone) {
        if (state.pModel == nullptr || !state.isActive) return;
        if (upDot < state.excludeAngle) {
            if (!playerServices->IsScreenParticleModelUnlinked(state.pModel)) {
                playerServices->UnlinkScreenParticleModel(state.pModel);
            }
            return;
        }
        float coverage = 1.0f;
        if (state.fadeEndTime != 0) {
            if (gameTime >= state.fadeEndTime) {
                if (!playerServices->IsScreenParticleModelUnlinked(
                        state.pModel)) {
                    playerServices->UnlinkScreenParticleModel(state.pModel);
                }
                state.isActive = false;
                if (clearModelWhenDone) state.pModel = nullptr;
                return;
            }
            coverage = 1.0f - static_cast<float>(
                gameTime - state.fadeStartTime)
                / static_cast<float>(state.fadeEndTime
                    - state.fadeStartTime);
        }
        playerServices->UpdateScreenParticleModel(state.pModel,
            viewOrigin, viewAxis, coverage);
    };
    for (int particle = 0; particle < screenPrtState.Num(); ++particle) {
        updateState(screenPrtState[particle], false);
    }
    for (int particle = 0; particle < 4; ++particle) {
        updateState(fxScreenPrtState[particle], true);
    }
}

void idPresentableAI::UpdateInfluenceTrail() {
    idPresentableAIServices* services = Tungsten_GetPresentableAIServices();
    services->UpdateInfluence(this, origin, services->GetScaledGameTime());
}

void idPresentablePlayer::EnableInfluenceTrail() {
    playerServices->EnableInfluenceTrail(*this);
}

int idPresentablePlayer::GetUserCmdsForNetSend(usercmd_t** buffer,
        int bufferSize) {
    int commandCount = (std::min)(bufferSize, 64);
    commandCount = (std::min)(commandCount, lastRecordedMoveBufferIndex);
    for (int command = 0; command < commandCount; ++command) {
        const int moveIndex = lastRecordedMoveBufferIndex
            - commandCount + command;
        buffer[command] = &moveBuffer[moveIndex % 64].curCmd;
    }
    return commandCount;
}

void idPresentablePlayer::ScopeZoomBlur() {
    playerServices->ForceScopeZoomBlur(*this, 5.0f, 0.0f, 500.0f);
}

playerScopeGuiNum_t idPresentablePlayer::GetScopeGuiNum() const {
    idWeapon* controlWeapon = playerServices->GetControlWeapon(*this);
    if (controlWeapon != nullptr
            && playerServices->WeaponHasActiveScope(controlWeapon)) {
        return playerServices->GetWeaponScopeGuiNum(controlWeapon);
    }
    return PLAYER_SCOPE_NONE;
}

void idPresentablePlayer::RespondToUseItem(idInventoryItem* item,
        bool used) {
    if (used && item != nullptr) {
        if (playerServices->ItemClosesInventoryOnUse(item)
                && entity != nullptr && playerServices->IsServer()) {
            playerServices->ForceCloseInventory(*this);
        }
        if (playerServices->ItemIsRemovedOnUse(item)) {
            playerServices->DeleteInventoryItem(*this, item, 1);
        }
    } else if (IsLocallyControlled()) {
        playerServices->PlayCannotUseItemSound(*this);
    }
}

void idPresentablePlayer::InventoryRemoved(idInventoryItem* item) {
    if (playerServices->HandsContainItem(*this, EQUIP_LEFT_HAND, item)) {
        playerServices->DetachHandsItem(*this, EQUIP_LEFT_HAND);
    }
    if (playerServices->HandsContainItem(*this, EQUIP_RIGHT_HAND, item)) {
        playerServices->DetachHandsItem(*this, EQUIP_RIGHT_HAND);
    }
    if (entity != nullptr) {
        playerServices->NotifyInventoryRemoved(*this, item);
    }
}

bool idPresentablePlayer::ClientCanUseItem(idInventoryItem*) {
    const int gameTime = playerServices->GetScaledGameTime();
    return (gameTime >> 31) + (gameTime >= lastUsedTime)
        + (lastUsedTime >> 31) != 0;
}

void idPresentablePlayer::SetServerOverridePos(bool teleport, int extra) {
    serverOverridePositionTime = playerServices->GetScaledGameTime() + extra;
    if (teleport) {
        teleportedCount = static_cast<std::uint8_t>(
            (teleportedCount + 1) % 7);
    }
}

idUCmdInhibit::inhibitFlags_t idPresentablePlayer::GetInhibitFlags(
        int& specificInhibitButtons) {
    if (playerServices->AllowUninhibitedCommands(*this)) {
        return idUCmdInhibit::UCMD_INHIBIT_NONE;
    }
    int flags = inhibitFlags;
    if (entity != nullptr) {
        if (restrictedGamePlay) {
            flags |= idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_UP;
            specificInhibitButtons |= 0x33F7FFDB;
        }
        if (PlayerBehavior_ContextualShimmy_IsInShimmy()
                || PlayerBehavior_WallClimb_IsInWallClimb()) {
            flags |= idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_UP;
            specificInhibitButtons |= 0x00800010;
        }
        if (playerServices->IsInTakedown(*this)) {
            flags |= idUCmdInhibit::UCMD_INHIBIT_MOVEMENT
                | idUCmdInhibit::UCMD_INHIBIT_BUTTONS;
        }
    }
    return static_cast<idUCmdInhibit::inhibitFlags_t>(flags);
}

void idPresentablePlayer::SetInhibitFlags(
        idUCmdInhibit::inhibitFlags_t flags) {
    inhibitFlags = flags;
}

void idPresentablePlayer::AddInhibitFlags(
        idUCmdInhibit::inhibitFlags_t flags) {
    inhibitFlags |= flags;
}

void idPresentablePlayer::ClearInhibitFlags(
        idUCmdInhibit::inhibitFlags_t flags) {
    inhibitFlags &= ~flags;
}

void idPresentablePlayer::SetRestrictedGamePlay(bool restricted,
        bool canRun) {
    if (restricted && !restrictedGamePlay) {
        playerServices->EnterRestrictedHud(*this);
    } else if (!restricted && restrictedGamePlay) {
        playerServices->RestoreRestrictedHud(*this);
    }
    restrictedCanRun = canRun;
    restrictedGamePlay = restricted;
    playerServices->SetHudRestrictedGameplay(*this, restricted);
}

void idPresentablePlayer::SetInhibitRaiseWeapon(bool restricted) {
    if (restricted && !restrictedGamePlay) {
        playerServices->EnterRestrictedHud(*this);
    } else if (!restricted && restrictedGamePlay) {
        playerServices->RestoreRestrictedHud(*this);
    }
    inhibitRaiseWeapon = restricted;
}

bool idPresentablePlayer::PlayerBehavior_ContextualShimmy_IsInShimmy() const {
    return entity != nullptr && playerServices->IsInContextualShimmy(*this);
}

bool idPresentablePlayer::PlayerBehavior_WallClimb_IsInWallClimb() const {
    return entity != nullptr && playerServices->IsInWallClimb(*this);
}

bool idPresentablePlayer::PlayerBehavior_SprintSlide_IsSliding() const {
    return entity != nullptr && playerServices->IsInSprintSlide(*this);
}

bool idPresentablePlayer::PlayerBehavior_Shared_ShouldHideWeapon() const {
    return inhibitRaiseWeapon || (entity != nullptr
        && playerServices->ShouldHideWeapon(*this));
}

void idPresentablePlayer::PlayerBehavior_Lean_GetHandsOffsetScale(
        idVec2& scale) const {
    if (entity != nullptr) {
        playerServices->GetLeanHandsOffsetScale(*this, scale);
    } else {
        scale.Set(0.0f, 0.0f);
    }
}

void idPresentablePlayer::ExitedVehicle() {
    vehicleExitedCount = static_cast<std::uint8_t>(
        (vehicleExitedCount + 1) % 7);
}

void idPresentablePlayer::ChallengeRestart() {
    challengeLocalRestart = false;
    challengeRestartingSoon = true;
    challengeRemoteRestart = false;
    playerServices->PrepareChallengeRestart(*this);
}

void idPresentablePlayer::NoteSwfForBuildGame() {
    localView.initialized = true;
    playerServices->InitializeBuildGameView(*this, localView);
    for (int gui = 0; gui < GUI_COUNT; ++gui) {
        if (!guiNames[gui].IsEmpty()) {
            playerServices->RegisterSWFResources(guiNames[gui].c_str());
        }
    }
}

idSWF* idPresentablePlayer::GetPlayerGui(playerGuis_t gui) {
    if (!IsLocallyControlled() || gui < GUI_DELIVERY || gui >= GUI_COUNT) {
        return nullptr;
    }
    idSWF*& loaded = reinterpret_cast<idSWF*&>(loadedGuis[gui]);
    if (loaded == nullptr) {
        const bool useMenuSoundWorld = gui == GUI_INVENTORY
            || gui == GUI_TOWTRUCK || gui == GUI_TUTORIAL;
        loaded = playerServices->CreatePlayerGui(*this, gui,
            guiNames[gui].c_str(), purgableGuis[gui], useMenuSoundWorld);
    }
    return loaded;
}

bool idPresentablePlayer::ClearPlayerGui(playerGuis_t gui) {
    if (!IsLocallyControlled() || gui < GUI_DELIVERY || gui >= GUI_COUNT) {
        return false;
    }
    idSWF*& loaded = reinterpret_cast<idSWF*&>(loadedGuis[gui]);
    if (loaded == nullptr) return false;
    playerServices->DestroyPlayerGui(loaded);
    loaded = nullptr;
    return true;
}

bool idPresentablePlayer::GuiIsActive(playerGuis_t gui) const {
    if (gui < GUI_DELIVERY || gui >= GUI_COUNT) return false;
    return loadedGuis[gui] != nullptr && playerServices->GuiIsActive(
        reinterpret_cast<const idSWF*>(loadedGuis[gui]));
}

void idPresentablePlayer::SetGeneralGameGui(idSWF* gui) {
    loadedGuis[GUI_GENERAL_GAME_USE] = gui;
    if (gui != nullptr) playerServices->SetGuiPausedRender(gui, false);
    isGeneralGuiCardGame = false;
}

void idPresentablePlayer::DrawSubtitles(idRenderModelGui* guiModel) {
    if (!playerServices->ShouldDrawGuis()
            || playerServices->IsMainMenuActive()) return;
    if (GuiIsActive(GUI_INVENTORY) || !GuiIsActive(GUI_SUBTITLE)
            || GuiIsActive(GUI_PLAYERGARAGE)
            || GuiIsActive(GUI_TUNE_VEHICLE)) return;
    idSWF* subtitle = GetPlayerGui(GUI_SUBTITLE);
    if (subtitle != nullptr) {
        playerServices->RenderSubtitleGui(subtitle, guiModel,
            playerServices->GetScaledGameTime());
    }
}

void idPresentablePlayer::ToggleShowLegendTitle(
        const idStrId& legendTitle) {
    renderLegendTitle = !renderLegendTitle;
    coopLegendTitle = legendTitle;
}

void idPresentablePlayer::GetLobbyUserID(lobbyUserID_t& result) const {
    playerServices->GetLobbyUserID(*this, result);
}

void idPresentablePlayer::SetLobbyUserID(const lobbyUserID_t& value) {
    playerServices->SetLobbyUserID(*this, value);
}

const char* idPlayerViewCallbacks::GetName() {
    return self != nullptr ? playerServices->GetPlayerModelName(*self)
        : "NULL";
}

int idPlayerViewCallbacks::GetViewID() const {
    return self != nullptr ? playerServices->GetPlayerViewID(*self) : -1;
}

void idPlayerViewCallbacks::GetPosition(idVec3& origin, idMat3& axis) {
    if (self != nullptr) {
        origin = self->origin;
        axis = self->axis;
    } else {
        origin.Zero();
        axis = idMat3(1.0f);
    }
}

void idPlayerViewCallbacks::GetViewPosition(idVec3& origin, idMat3& axis) {
    if (self != nullptr) {
        playerServices->GetPlayerViewPosition(*self, origin, axis);
    } else {
        origin.Zero();
        axis = idMat3(1.0f);
    }
}

void idPlayerViewCallbacks::ApplyScreenShake(float shakeMagnitude,
        const idAngles&, const idVec3&) {
    if (self != nullptr) {
        playerServices->SetCameraShake(*self,
            (std::max)(0.0f, (std::min)(1.0f, shakeMagnitude)));
    }
}

void idPlayerViewCallbacks::ApplyControllerShake(float highDuration,
        float lowDuration, float highMagnitude, float lowMagnitude) {
    if (self != nullptr) {
        playerServices->SetControllerShake(*self, highDuration, lowDuration,
            highMagnitude, lowMagnitude);
    }
}

void idPlayerViewCallbacks::ApplyDynEnvOverride(
        const idDeclEnv* environment, float blendDuration) {
    if (self != nullptr) {
        playerServices->SetEnvironmentOverride(*self, environment,
            blendDuration);
    }
}

void idPlayerViewCallbacks::ApplyDynEnvParmOverride(
        const idDeclRenderParm* parameter, const idVec4& value,
        bool clearParameter, float blendDuration) {
    if (self == nullptr) return;
    if (clearParameter) {
        playerServices->ClearEnvironmentParm(*self, parameter, blendDuration);
    } else {
        playerServices->SetEnvironmentParm(*self, parameter, value,
            blendDuration);
    }
}

void idPlayerViewCallbacks::ApplyRadialBlur(const idVec3& position,
        float startTime, float duration, float minimumBlur,
        float maximumBlur, float maximumScale) {
    if (self != nullptr) {
        playerServices->AddRadialBlur(*self, position, startTime, duration,
            minimumBlur, maximumBlur, maximumScale);
    }
}

int idPlayerViewCallbacks::AddScreenParticle(idRenderModel* particleModel,
        float excludeAngle) {
    return self != nullptr
        ? self->StartFxScreenParticle(particleModel, excludeAngle) : -1;
}

void idPlayerViewCallbacks::RemoveScreenParticle(unsigned int handle,
        int fadeTime) {
    if (self != nullptr) self->StopFxScreenParticle(handle, fadeTime);
}

void p_clearInhibitFlags_f(const idCmdArgs& args) {
    const int playerIndex = args.Argc() > 1 ? std::atoi(args.Argv(1)) : 0;
    idPresentablePlayer* player = playerServices->FindPlayer(playerIndex);
    if (player == nullptr) {
        std::ostringstream failure;
        failure << "Could not print inhibit flags: #" << playerIndex
            << " not a valid player\n";
        playerServices->Print(failure.str().c_str());
        return;
    }
    playerServices->Print("Clearing inhibit flags\n");
    player->ClearInhibitFlags(static_cast<idUCmdInhibit::inhibitFlags_t>(
        player->inhibitFlags));
    if (player->restrictedGamePlay) {
        player->SetRestrictedGamePlay(false, false);
    }
    if (!player->allowWeaponChange || player->inhibitChangeWeapon) {
        player->allowWeaponChange = true;
        player->inhibitChangeWeapon = false;
        playerServices->Print("Removing weaponchange block\n");
    }
    if (player->inhibitRaiseWeapon) {
        player->SetInhibitRaiseWeapon(false);
        playerServices->Print("Removed raise weapon block\n");
    }
}

float idWeaponKick::GetOffset() const {
    const float gameTime = static_cast<float>(
        playerServices->GetPlayerGameTime());
    if (gameTime < recoilOffset.startTime + recoilOffset.duration) {
        return recoilOffset.GetCurrentValue(gameTime);
    }
    return recoveryOffset.GetCurrentValueEaseOut(gameTime);
}

void idWeaponKick::Init(const float& kick, const float& maximumKick,
        const float& inSpeed, const float& outSpeed, bool additiveKick,
        float recoveryDelay) {
    if (kick <= 0.0f) return;
    const float kickDelta = playerServices->RandomCenteredFloat() * kick;
    const float oldOffset = GetOffset();
    float newOffset;
    if (additiveKick && maximumKick != 0.0f) {
        const float ratio = oldOffset / maximumKick;
        const float attenuation = 1.0f - 3.0f * ratio * ratio
            + 2.0f * ratio * ratio * ratio;
        newOffset = oldOffset + attenuation * kickDelta;
    } else {
        newOffset = (std::max)(-maximumKick,
            (std::min)(maximumKick, oldOffset + kickDelta));
    }
    const float recoilDuration = inSpeed != 0.0f
        ? std::fabs(newOffset - oldOffset) * 1000.0f / inSpeed : 0.0f;
    const float gameTime = static_cast<float>(
        playerServices->GetPlayerGameTime());
    recoilOffset.Init(gameTime, recoilDuration, oldOffset, newOffset);
    const float recoveryDuration = outSpeed != 0.0f
        ? std::fabs(newOffset) * 1000.0f / outSpeed : 0.0f;
    recoveryOffset.Init(gameTime + recoilDuration + recoveryDelay,
        recoveryDuration, newOffset, 0.0f);
}

void idPresentablePlayer::InitForClient() {
    playerServices->InitializeClientHands(*this);
    playerServices->SetHandsViewID(*this, entityNumber + 1);
    if (IsLocallyControlled() && index < 12288) {
        playerServices->ShowAndEnableHands(*this);
    } else {
        playerServices->HideHands(*this);
    }
    if (IsLocallyControlled() && SelectBestWeapon() == nullptr) {
        SelectFists(false);
    }
}

void idPresentablePlayer::SerializeHud(idSerializer& serializer,
        idHudInfo& info) {
    serializer.Serialize(info.armor);
    for (int item = 0; item < 4; ++item) {
        info.combinerItemState[item] = serializer.SerializeBoolNonRef(
            info.combinerItemState[item]);
    }
}

void idPresentablePlayer::PostSerializeRead(bool firstClientFrame) {
    idPresentableActor::PostSerializeRead(firstClientFrame);
    playerServices->PostSerializeInventory(*this);
    const bool teleported = teleportedCount != teleportedLastCount;
    if (teleported) teleportedLastCount = teleportedCount;
    if (IsLocallyControlled() && (firstPredictionSerialize || teleported)) {
        playerServices->RestoreSerializedPlayerState(*this);
    }
    if (teleported) serializedOrigins[0] = serializedOrigins[1];

    const bool respawned = respawnCount != respawnLastCount;
    if (respawned) {
        respawnLastCount = respawnCount;
        playerServices->PresentableRespawn(*this, false);
        serializedOrigins[0] = serializedOrigins[1];
    }
    const bool exitedVehicle = vehicleExitedCount != vehicleExitedLastCount;
    if (exitedVehicle) vehicleExitedLastCount = vehicleExitedCount;
    if (exitedVehicle && IsLocallyControlled()) {
        playerServices->ResetViewShake(*this);
    }
    if (IsLocallyControlled()
            && roverBombSoundCounter > localRoverBombSoundCounter) {
        localRoverBombSoundCounter = roverBombSoundCounter;
        playerServices->PlayRoverBombSelfDestructSound(*this);
    }
}

void idPresentablePlayer::HudThink() {
    UpdateScoringCallout();
    playerServices->UpdateHud(*this);
}

void idPresentablePlayer::InventoryAdded(idInventoryItem* item, int count,
        bool) {
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->NotifyServerInventoryAdded(*this, item, count);
    }
    if (IsLocallyControlled()) {
        playerServices->ShowInventoryPickup(*this, item, count);
    }
}

void idPresentablePlayer::ApplyDamageToPresentable(idPresentable* attacker,
        const idDeclDamage* damageDefinition, float damage,
        const idVec3& impactDirection, const idVec3& impactKick,
        int impactOverrideTimer) {
    damageFeedback_t& feedback =
        damageFeedback[damageFeedbackBufferPos % 10];
    feedback.attackerSpawnId = attacker != nullptr ? attacker->spawnId : 0;
    feedback.damageDefinition = damageDefinition;
    feedback.damage = damage;
    feedback.impactDirection = impactDirection;
    feedback.impactKick = impactKick;
    feedback.impactOverrideTimer = impactOverrideTimer;
    ++damageFeedbackBufferPos;
}

namespace {

struct TutorialWaitInputState {
    TutorialWaitInputState(const idDeclTutorialEvent* declaration_,
            idSWF* gui_, idEntity* activatingEntity_,
            idPresentablePlayer* player_, const char* action_)
        : declaration(declaration_), gui(gui_)
        , activatingEntity(activatingEntity_), player(player_)
        , action(action_ != nullptr ? action_ : "") {}

    const idDeclTutorialEvent* declaration;
    idSWF* gui;
    idEntity* activatingEntity;
    idPresentablePlayer* player;
    idStr action;
};

} // namespace

void idPresentablePlayer::HideTutorialGui() {
    idSWF* gui = GetPlayerGui(GUI_TUTORIAL);
    if (gui != nullptr && playerServices->GuiIsActive(gui)) {
        playerServices->ActivateGui(gui, false);
        currentTutorialGuiDecl = nullptr;
    }
}

void idPresentablePlayer::HideSpecificTutorialGui(
        const idDeclTutorialEvent* declaration) {
    idSWF* gui = GetPlayerGui(GUI_TUTORIAL);
    if (gui != nullptr && playerServices->GuiIsActive(gui)
            && currentTutorialGuiDecl == declaration) {
        playerServices->ActivateGui(gui, false);
        currentTutorialGuiDecl = nullptr;
    }
}

void idPresentablePlayer::DeactivateGuis() {
    if (!IsLocallyControlled()) return;
    for (int guiIndex = GUI_DELIVERY; guiIndex < GUI_COUNT; ++guiIndex) {
        const playerGuis_t gui = static_cast<playerGuis_t>(guiIndex);
        if (gui == GUI_SUBTITLE || !GuiIsActive(gui)) continue;
        playerServices->ActivateGui(GetPlayerGui(gui), false);
    }
}

void idPresentableActor::PostAlloc() {
    predictedModifierParentSpawnId = spawnId;
}

idPresentable* idPresentablePlayer::GetControl() const {
    return controlledPresentables.Num() > 0
        ? controlledPresentables[controlledPresentables.Num() - 1] : nullptr;
}

idPresentableVehicle* idPresentablePlayer::GetVehicle() const {
    idPresentable* control = GetControl();
    if (control != nullptr && control->GetType() == PRESENTABLE_VEHICLE) {
        return control->GetVehicleInterface();
    }
    if (groupMaster != nullptr
            && groupMaster->GetType() == PRESENTABLE_VEHICLE) {
        return groupMaster->GetVehicleInterface();
    }
    return nullptr;
}

bool idPresentablePlayer::UseItem(idInventoryItem* item) {
    if (item == nullptr) return false;
    if (playerServices->IsAmmoItem(item)) {
        playerServices->SelectAmmoItem(*this, item);
        return true;
    }
    if (playerServices->IsThrowableItem(item)) {
        if (playerServices->CanThrowItem(*this, item)
                && playerServices->UniqueProjectileAllowed(*this, item)
                && playerServices->DeployableAllowed(*this, item)) {
            playerServices->ThrowItem(*this, item);
            return !playerServices->InfiniteAmmo()
                && !playerServices->PermanentInfiniteAmmo();
        }
        if (!playerServices->CookItemPending(*this)) {
            playerServices->PlayCannotUseItemSound(*this);
        }
        return false;
    }
    if (entity != nullptr && playerServices->IsServer()) {
        const bool used = playerServices->ServerUseItem(*this, item);
        RespondToUseItem(item, used);
        if (!used && !IsLocallyControlled()) {
            playerServices->RestoreFailedServerItemCount(*this, item);
            playerServices->ReplicateCannotUseItem(*this);
        }
        return used;
    }
    if (!ClientCanUseItem(item)) return false;
    const bool used = playerServices->ClientUseItem(*this, item);
    RespondToUseItem(item, used);
    if (used) {
        playerServices->SendQuickUseMessage(*this, item);
        lastUsedTime = playerServices->GetScaledGameTime()
            + playerServices->GetClientUseThrottleTime();
    }
    return used;
}

void idPresentablePlayer::ChallengeRestartRequest(bool restartChallenge,
        bool local) {
    if (local) {
        challengeLocalRestart = true;
    } else if (restartChallenge) {
        challengeRemoteRestart = true;
    } else {
        challengeLocalRestart = false;
        challengeLeavingSoon = true;
        challengeRemoteRestart = false;
        playerServices->PrepareChallengeExit(*this);
    }
    if (playerServices->ShouldRestartChallenge(*this)
            && challengeLocalRestart) {
        ChallengeRestart();
        playerServices->FinalizeChallengeRestart(*this);
    }
}

void idPresentablePlayer::SetupSubtitle(const idVoiceTrack* track,
        const idPresentable* source, const idStrId&) {
    if (track == nullptr) {
        playerServices->Print("SetupSubtitle: tried to play NULL vtr\n");
        return;
    }
    if (!playerServices->CanStartSubtitle(*this, track, source)) return;
    const char* text = playerServices->GetSubtitleText(track);
    if (text == nullptr || text[0] == '\0') return;
    subtitleStartTime = -1;
    playerServices->StartSubtitle(*this, text,
        playerServices->GetSubtitleDurationMS(track) * 0.001f);
}

idWeapon* idPresentableActor::GetFiredWeapon(
        const idDeclWeapon* weaponDefinition) {
    idWeapon* weapon = actorServices->FindFiredInventoryWeapon(*this,
        weaponDefinition);
    if (weapon != nullptr) return weapon;
    idPresentablePlayer* player = GetPlayerInterface();
    if (player == nullptr) return nullptr;
    idPresentable* control = player->GetControl();
    return control != nullptr ? actorServices->GetControlledFiredWeapon(
        control, weaponDefinition) : nullptr;
}

void idPresentablePlayer::InitSideMissions() {
    idSWF* gui = GetPlayerGui(GUI_SIDEMISSION);
    scriptFunction_goToMission.pThis = this;
    scriptFunction_resumeMap.pThis = this;
    if (gui != nullptr) {
        playerServices->BindSideMissionCallbacks(*this, gui);
    }
}

bool idPresentablePlayer::idSWFScriptFunction_resumeMap::Call(
        int parameterCount) {
    if (parameterCount != 0 || pThis == nullptr) return false;
    return playerServices->ResumeMap(*pThis);
}

bool idPresentablePlayer::idSWFScriptFunction_goToMission::Call(
        int parameterCount) {
    if (parameterCount != 0 || pThis == nullptr) return false;
    return playerServices->GoToMission(*pThis);
}

bool idPresentablePlayer::Draw(idPresentablePlayer*) {
    playerServices->ClearPlayerGuiModel(*this);
    playerServices->UpdatePlayerHudInfo(*this, hudInfo);
    if (index >= 12288 || !IsLocallyControlled()) return false;
    idPresentable* control = GetControl();
    if (control != nullptr) {
        if (!playerServices->DrawControlledPresentable(control, *this)) {
            if (playerServices->IsPlayerDead(*this)) {
                playerServices->RenderDeadPlayerView(*this);
            }
            playerServices->RestoreSerializedViewPosition(*this,
                serializedViewOrigin, serializedViewAxis);
            return false;
        }
    } else {
        playerServices->DrawSharedPlayer(*this);
    }
    return true;
}

void idPresentablePlayer::ClientPredict(int, float) {
    if (!IsLocallyControlled()) return;
    idPresentable* control = GetControl();
    const bool inVehicle = GetVehicle() != nullptr;
    if (control == nullptr || inVehicle) {
        playerServices->ProcessPlayerInput(*this, true);
    } else if (playerServices->IsPlayerDead(*this)) {
        playerServices->UpdatePlayerHands(*this);
    }
    if (control == nullptr) playerServices->PredictPlayerTriggers(*this);
}

bool idPresentablePlayer::ShouldLinkPresentableCollision() {
    return GetControl() == nullptr;
}

void idPresentablePlayer::UpdateOutline() {
    if (outlineModel == nullptr) return;
    const bool unlink = (GetControl() != nullptr && GetVehicle() != nullptr)
        || hidden;
    const bool friendly = playerServices->UseFriendlyOutlineColor(*this);
    const idVec4 color(friendly ? 0.5f : 0.0f,
        friendly ? 0.0f : 0.5f, 0.0f, 1.0f);
    playerServices->UpdateOutlineModel(outlineModel, unlink, color);
}

void idPresentablePlayer::SerializePredictionState(
        idSerializer& serializer) {
    SerializeHud(serializer, hudInfo);
    serializer.SerializeQ(serializedViewAxis);
    serializer.Serialize(serializedViewOrigin);
    const int oldInputFrame = clientPlayerInputFrame;
    serializer.Serialize(clientPlayerInputFrame);
    if (serializer.IsReading() && clientPlayerInputFrame != 0
            && clientPlayerInputFrame <= oldInputFrame) {
        playerServices->Print("clientPlayerInputFrame out of sequence\n");
    }
    idPresentable* control = GetControl();
    if (control == nullptr
            || !playerServices->SerializeControlledVehiclePrediction(
                control, serializer)) {
        playerServices->SerializePlayerPhysicsPrediction(*this, serializer);
        firstPredictionSerialize = false;
    }
}

void idPresentablePlayer::SerializeNonPredictionState(
        idSerializer& serializer) {
    if (!serializer.IsWriting() && IsLocallyControlled()) {
        playerServices->Print(
            "Received NonPredictionState for local player\n");
        return;
    }
    idPresentable* control = GetControl();
    if (control != nullptr && GetVehicle() != nullptr) {
        playerServices->SerializeControlledVehicleNonPrediction(control,
            serializer);
    }
    playerServices->SerializePlayerPhysicsNonPrediction(*this, serializer);
}

void idPresentablePlayer::RecordMove(const usercmd_t& previousCommand,
        const usercmd_t& command, const idAngles& angles,
        int startTime, int endTime) {
    const int frame = playerServices->GetClientGameFrame();
    moveBufferItem_t& move = moveBuffer[frame % 64];
    lastRecordedMoveBufferIndex = frame;
    move.prevCmd = previousCommand;
    move.curCmd = command;
    move.viewAngles = angles;
    move.startTime = startTime;
    move.endTime = endTime;
    move.origin = playerServices->GetPlayerPhysicsOrigin(*this);
    idPresentable* control = GetControl();
    move.speed = control != nullptr && GetVehicle() != nullptr
        ? playerServices->GetControlledVehicleSpeed(control) : 0.0f;
    move.predictionBits = 0;
    if (playerServices->IsPlayerCrouching(*this)) move.predictionBits |= 1;
    if (isSprinting) move.predictionBits |= 2;
    if (playerServices->IsPlayerFullyZoomed(*this)) move.predictionBits |= 4;
    move.curCmd.clientGameFrame = frame;
}

void idPresentablePlayer::HandleUserCmds(const usercmd_t& newCommand) {
    if (!playerServices->IsClient()) {
        clientPlayerInputFrame = newCommand.clientGameFrame;
    }
    int specificInhibitButtons = 0;
    int flags = GetInhibitFlags(specificInhibitButtons);
    if ((flags & idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_ONCE) != 0) {
        flags = (flags & ~(idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_ONCE
            | idUCmdInhibit::UCMD_INHIBIT_MOVEMENT))
            | idUCmdInhibit::UCMD_INHIBIT_MOVEMENT;
        inhibitFlags &= ~idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_ONCE;
    }
    if ((flags & idUCmdInhibit::UCMD_INHIBIT_BUTTONS_ONCE) != 0) {
        flags = (flags & ~(idUCmdInhibit::UCMD_INHIBIT_BUTTONS_ONCE
            | idUCmdInhibit::UCMD_INHIBIT_BUTTONS))
            | idUCmdInhibit::UCMD_INHIBIT_BUTTONS;
        inhibitFlags &= ~idUCmdInhibit::UCMD_INHIBIT_BUTTONS_ONCE;
    }
    if ((flags & idUCmdInhibit::UCMD_INHIBIT_VIEW_ONCE) != 0) {
        flags = (flags & ~(idUCmdInhibit::UCMD_INHIBIT_VIEW_ONCE
            | idUCmdInhibit::UCMD_INHIBIT_VIEW))
            | idUCmdInhibit::UCMD_INHIBIT_VIEW;
        inhibitFlags &= ~idUCmdInhibit::UCMD_INHIBIT_VIEW_ONCE;
    }
    const bool gameInhibited = IsLocallyControlled()
        ? playerServices->IsPlayerControlInhibited(*this)
        : newCommand.inhibited;
    int cameraFlags = 0;
    int cameraButtons = 0;
    idPresentable* control = GetControl();
    if (control != nullptr) {
        playerServices->GetControlledCameraInhibit(control, cameraFlags,
            cameraButtons);
    }
    idUCmdInhibit primary;
    primary.game = gameInhibited;
    primary.flags = flags | cameraFlags;
    primary.buttons = specificInhibitButtons | cameraButtons;
    idUCmdInhibit secondary;
    secondary.game = gameInhibited;
    secondary.flags = flags;
    if (restrictedGamePlay && !restrictedCanRun) {
        primary.minForward = primary.minRight = -64;
        primary.maxForward = primary.maxRight = 64;
        secondary.minForward = secondary.minRight = -64;
        secondary.maxForward = secondary.maxRight = 64;
    }

    usercmd_t adjusted = newCommand;
    int buttons = adjusted.buttons;
    if ((buttons & 0x30000000) != 0) {
        buttons = (buttons & 0x10000000) != 0
            ? buttons & 0xDFFCFFFF : buttons & 0xEFFCFFFF;
    } else if ((buttons & 0x00030000) != 0) {
        buttons = (buttons & 0x00010000) != 0
            ? buttons & 0xCFFDFFFF : buttons & 0xCFFEFFFF;
    }
    adjusted.buttons = buttons;
    if (playerServices->IsDualWielding(*this)
            && !playerServices->UseAimAssist()) {
        const bool attackOne = (newCommand.buttons & 1) != 0;
        const bool attackTwo = (newCommand.buttons & 8) != 0;
        if (attackTwo) {
            adjusted.buttons |= 1;
            if (!attackOne) adjusted.buttons &= ~8;
        }
        if (attackOne) {
            adjusted.buttons |= 8;
            if (!attackTwo) adjusted.buttons &= ~1;
        }
    }
    ucmdTracker1.Update(adjusted, primary);
    ucmdTracker2.Update(adjusted, secondary);
}

int idPresentablePlayer::GetPlayerGameTime() {
    if (!playerServices->IsMultiplayer() || IsInterpolated()
            || (playerServices->IsServer() && IsLocallyControlled())) {
        return playerServices->GetScaledGameTime();
    }
    const idUCmdTracker& tracker = GetControl() != nullptr
        ? ucmdTracker2 : ucmdTracker1;
    return tracker.usercmd.clientGameFrame
        * playerServices->GetScaledMSPerFrame();
}

void idPresentablePlayer::AttachController(idPresentable* control) {
    if (control == nullptr) return;
    playerServices->AttachController(control, *this, spawnId);
    isTurretControl = playerServices->ControlIsStaticWeapon(control);
    HandleUserCmds(ucmdTracker2.usercmd);
}

void idPresentablePlayer::DetachController(idPresentable* control) {
    if (control != nullptr
            && playerServices->ControllerIsAttachedTo(control, *this)) {
        playerServices->ReleaseController(control);
    }
}

void idPresentablePlayer::Serialize(idSerializer& serializer) {
    idPresentableActor::Serialize(serializer);

    int controlCount = (std::min)(controlledPresentables.Num(), 4);
    serializer.Serialize(controlCount);
    if (serializer.IsReading()) controlledPresentables.Clear();
    for (int controlIndex = 0; controlIndex < 4; ++controlIndex) {
        std::uint32_t controlSpawnId = serializer.IsWriting()
            && controlIndex < controlCount
            ? playerServices->GetPresentableSpawnId(
                controlledPresentables[controlIndex]) : 0;
        serializer.Serialize(controlSpawnId);
        if (serializer.IsReading() && controlIndex < controlCount) {
            controlledPresentables.Append(
                playerServices->ResolveControlledPresentable(
                    controlSpawnId));
        }
    }
    if (playerServices->ShouldSerializeInventory()) {
        playerServices->SerializePlayerInventory(*this, serializer);
    }
    if (serializer.IsWriting()) {
        sentOfficialSnap = playerServices->HasOfficialSnapshot(*this);
    }
    serializer.Serialize(sentOfficialSnap);
    serializer.Serialize(isTurretControl);
    serializer.Serialize(restrictedGamePlay);
    serializer.Serialize(restrictedCanRun);
    serializer.Serialize(allowWeaponChange);
    serializer.Serialize(inhibitChangeWeapon);
    serializer.Serialize(inhibitRaiseWeapon);
    serializer.Serialize(challengeLeavingSoon);
    serializer.Serialize(challengeLocalRestart);
    serializer.Serialize(challengeRemoteRestart);
    serializer.Serialize(wasPaused);

    int eventCount = respawnCount;
    serializer.SerializeUMax(eventCount, 7);
    respawnCount = static_cast<std::uint8_t>(eventCount);
    eventCount = teleportedCount;
    serializer.SerializeUMax(eventCount, 7);
    teleportedCount = static_cast<std::uint8_t>(eventCount);
    eventCount = vehicleExitedCount;
    serializer.SerializeUMax(eventCount, 7);
    vehicleExitedCount = static_cast<std::uint8_t>(eventCount);

    serializer.Serialize(calloutHistoryIndex);
    for (int callout = 0; callout < 4; ++callout) {
        const void* declaration = calloutHistory[callout].callout;
        playerServices->SerializePlayerDeclaration(serializer, declaration);
        calloutHistory[callout].callout =
            static_cast<const idDeclOnlineScoringCallout*>(declaration);
        serializer.Serialize(calloutHistory[callout].scoreIndex);
    }
    serializer.Serialize(coopScoringIndex);
    for (int score = 0; score < 4; ++score) {
        serializer.Serialize(coopScoreHistory[score].worldPosition);
        serializer.Serialize(coopScoreHistory[score].score);
    }

    int serializedDamagePosition = damageFeedbackBufferPos;
    serializer.Serialize(serializedDamagePosition);
    for (int feedbackIndex = 0; feedbackIndex < 10; ++feedbackIndex) {
        damageFeedback_t& feedback = damageFeedback[feedbackIndex];
        serializer.Serialize(feedback.attackerSpawnId);
        const void* declaration = feedback.damageDefinition;
        playerServices->SerializePlayerDeclaration(serializer, declaration);
        feedback.damageDefinition = static_cast<const idDeclDamage*>(
            declaration);
        serializer.Serialize(feedback.damage);
        serializer.Serialize(feedback.impactDirection);
        serializer.Serialize(feedback.impactKick);
        serializer.Serialize(feedback.impactOverrideTimer);
    }
    if (serializer.IsReading()) {
        serializeDamageFeedbackCount = serializedDamagePosition
            - damageFeedbackBufferPos;
        if (serializeDamageFeedbackCount > 10) {
            damageFeedbackBufferPos = serializedDamagePosition - 10;
            serializeDamageFeedbackCount = 10;
        }
        if (serializeDamageFeedbackCount < 0) {
            serializeDamageFeedbackCount = 0;
            damageFeedbackBufferPos = serializedDamagePosition;
        }
    }
    serializer.Serialize(roverBombSoundCounter);
}

void idPresentablePlayer::RemoveControl(idPresentable* control) {
    if (control == nullptr) return;
    for (int controlIndex = controlledPresentables.Num() - 1;
            controlIndex >= 0; --controlIndex) {
        if (controlledPresentables[controlIndex] != control) continue;
        DetachController(control);
        controlledPresentables.RemoveIndex(controlIndex);
        break;
    }
    idPresentable* nextControl = GetControl();
    if (nextControl != nullptr) AttachController(nextControl);
}

void idPresentablePlayer::ResetControl() {
    while (controlledPresentables.Num() > 0) {
        idPresentable* control = GetControl();
        DetachController(control);
        controlledPresentables.RemoveIndex(
            controlledPresentables.Num() - 1);
    }
    isTurretControl = false;
}

bool idPresentablePlayer::tutorialDeactivateCallback_t::Call() {
    return player != nullptr && playerServices->HandleTutorialDeactivate(
        *player, declaration, activatingEntity);
}

bool idPresentablePlayer::tutorialWaitInputCallback_t::Call(
        int keyNumber) {
    return player != nullptr && playerServices->HandleTutorialInput(*player,
        declaration, activatingEntity, keyNumber);
}

bool idPresentablePlayer::ShowTutorialGui(
        const idDeclTutorialEvent* declaration, idEntity* activatingEntity) {
    if (declaration == nullptr
            || !playerServices->CanShowTutorial(*this, declaration)) {
        return false;
    }
    idSWF* gui = GetPlayerGui(GUI_TUTORIAL);
    if (gui == nullptr) return false;
    playerServices->ConfigureTutorialGui(*this, declaration,
        activatingEntity, gui);
    if (playerServices->GuiIsActive(gui)) {
        playerServices->ActivateGui(gui, false);
    }
    playerServices->ActivateGui(gui, true);
    currentTutorialGuiDecl = declaration;
    playerServices->ScheduleTutorialEnd(*this, declaration);
    return true;
}

void idPresentablePlayer::DrawGuis(int listenerId) {
    if (!IsLocallyControlled() || !playerServices->ShouldDrawGuis()) return;
    idSWF* general = reinterpret_cast<idSWF*>(
        loadedGuis[GUI_GENERAL_GAME_USE]);
    if (isGeneralGuiCardGame && general != nullptr
            && playerServices->GuiIsActive(general)) {
        playerServices->PrepareGeneralCardGui(*this, general);
    }
    if (!playerServices->IsMainMenuActive()) {
        idSWF* inventoryGui = reinterpret_cast<idSWF*>(
            loadedGuis[GUI_INVENTORY]);
        if (inventoryGui != nullptr
                && playerServices->GuiIsActive(inventoryGui)) {
            playerServices->PrepareInventoryGui(*this, inventoryGui);
            playerServices->RenderPlayerGui(*this, inventoryGui,
                playerServices->GetScaledGameTime());
        } else {
            for (int guiIndex = 0; guiIndex < GUI_COUNT; ++guiIndex) {
                if (guiIndex == GUI_SUBTITLE
                        || guiIndex == GUI_GENERAL_GAME_USE) continue;
                idSWF* gui = reinterpret_cast<idSWF*>(loadedGuis[guiIndex]);
                if (gui == nullptr) continue;
                playerServices->SetGuiListener(gui, listenerId);
                playerServices->RenderPlayerGui(*this, gui,
                    playerServices->GetScaledGameTime());
            }
        }
    }
    if (general != nullptr && playerServices->GuiIsActive(general)
            && playerServices->CanRenderGeneralGui(*this, general)) {
        playerServices->RenderPlayerGui(*this, general,
            playerServices->GetScaledGameTime());
    }
}

void idPresentablePlayer::ResetLocalViews() {
    if (localView.initialized) hudInfo = idHudInfo();
}

void idPresentablePlayer::AddControl(idPresentable* control) {
    if (control == this) control = nullptr;
    idPresentable* previousControl = GetControl();
    if (control == nullptr) {
        ResetControl();
    } else if (control != previousControl) {
        if (previousControl != nullptr) DetachController(previousControl);
        controlledPresentables.Append(control);
        AttachController(control);
    }
}

void idPresentablePlayer::UpdateSubtitles(int currentTime) {
    if (subtitleStartTime == -1) subtitleStartTime = currentTime;
    const float elapsedSeconds =
        (currentTime - subtitleStartTime) * 0.001f;
    const char* text = playerServices->UpdateSubtitleSequencer(*this,
        elapsedSeconds);
    if (text == nullptr) return;
    idSWF* subtitle = GetPlayerGui(GUI_SUBTITLE);
    if (subtitle == nullptr) return;
    if (!playerServices->GuiIsActive(subtitle)) {
        playerServices->ActivateGui(subtitle, true);
    }
    playerServices->SetSubtitleText(subtitle, text);
}

void idPresentablePlayer::ClientThink(int currentTime, float fraction,
        bool predict) {
    if (playerServices->IsMultiplayer()) {
        playerServices->SetPlayerClipEnabled(*this, GetVehicle() == nullptr);
        playerServices->UpdateHandsHidden(*this);
    }
    if (!IsLocallyControlled()) Interpolate(currentTime, fraction);
    if (predict) {
        ClientPredict(currentTime, fraction);
        if (IsLocallyControlled()) {
            ClientUpdateFocusEntity();
        } else {
            playerServices->UpdateNonPredictiveClip(*this);
        }
    }
    if (playerServices->IsClient() && IsLocallyControlled()) {
        playerServices->UpdateClientHudState(*this);
    }
    HudThink();
    playerServices->ThinkPlayerHud(*this);
    playerServices->UpdatePlayerAnimation(*this, currentTime, fraction);
    playerServices->UpdatePlayerSound(*this);
    if (IsLocallyControlled()) {
        playerServices->UpdatePlayerDamageFeedback(*this);
        playerServices->UpdatePlayerDamageDealt(*this);
    }
    playerServices->UpdatePlayerWoundDecal(*this);
    Present();
    playerServices->DrawPlayerHands(*this);
    playerServices->UpdatePlayerInfluence(*this,
        playerServices->GetScaledGameTime());
    if (playerServices->ShouldRecordPlayerMove(*this)) {
        idUCmdTracker& tracker = GetControl() != nullptr
            ? ucmdTracker2 : ucmdTracker1;
        const int endTime = playerServices->GetClientGameFrame()
            * playerServices->GetScaledMSPerFrame();
        RecordMove(tracker.prevcmd, tracker.usercmd,
            playerServices->GetPlayerViewAnglesForRecord(*this),
            endTime - playerServices->GetScaledMSPerFrame(), endTime);
    }
    while (serializeDamageFeedbackCount > 0) {
        playerServices->ProcessSerializedDamageFeedback(*this,
            damageFeedbackBufferPos % 10);
        ++damageFeedbackBufferPos;
        --serializeDamageFeedbackCount;
    }
    UpdateOutline();
    playerServices->SyncPlayerPauseState(*this);
    playerServices->ThinkPlayerActorModifiers(*this);
    UpdateSubtitles(currentTime);
}

void Tungsten_SetUCmdTrackerServices(idUCmdTrackerServices* services) {
    trackerServices = services != nullptr ? services : &defaultTrackerServices;
}

idUCmdTracker::idUCmdTracker()
    : lastPlayerInputTime(0)
    , lastPlayerInputAngles{0, 0}
    , cmdInhibited(false)
    , clearViewDeltaNextUpdate(false)
    , deltaViewAngles(0.0f, 0.0f, 0.0f)
    , viewAngles(0.0f, 0.0f, 0.0f)
    , prevViewAngles(0.0f, 0.0f, 0.0f)
    , cmdAngles(0.0f, 0.0f, 0.0f)
    , constrainViewAngles(false)
    , constrainedViewAnglesBase(0.0f, 0.0f, 0.0f)
    , constrainedViewAnglesMinDelta(0.0f, 0.0f, 0.0f)
    , constrainedViewAnglesMaxDelta(0.0f, 0.0f, 0.0f)
    , constrainedViewAnglesRate(0.0f) {
    prevcmd.Clear();
    usercmd.Clear();
    usercmdRaw.Clear();
    ClearAngles();
}

void idUCmdTracker::SetLastPlayerInputAngles(
        const std::int16_t angles[2]) {
    lastPlayerInputAngles[0] = angles[0];
    lastPlayerInputAngles[1] = angles[1];
}

bool idUCmdTracker::GetAnglesMatchLastPlayerInputAngles(
        const std::int16_t angles[2]) const {
    for (int angleNumber = 0; angleNumber < 2; ++angleNumber) {
        if (lastPlayerInputAngles[angleNumber] != 0
                && lastPlayerInputAngles[angleNumber]
                    != angles[angleNumber]) {
            return false;
        }
    }
    return true;
}

void idUCmdTracker::ClearAngles() {
    prevcmd.Clear();
    usercmd.Clear();
    usercmdRaw.Clear();
    viewAngles = idAngles(0.0f, 0.0f, 0.0f);
    prevViewAngles = idAngles(0.0f, 0.0f, 0.0f);
    cmdAngles = idAngles(0.0f, 0.0f, 0.0f);
    deltaViewAngles = idAngles(0.0f, 0.0f, 0.0f);
    constrainViewAngles = false;
    constrainedViewAnglesBase = idAngles(0.0f, 0.0f, 0.0f);
    constrainedViewAnglesMinDelta = idAngles(0.0f, 0.0f, 0.0f);
    constrainedViewAnglesMaxDelta = idAngles(0.0f, 0.0f, 0.0f);
    constrainedViewAnglesRate = 0.0f;
    cmdInhibited = false;
}

void idUCmdTracker::SetCmdAnglesToView() {
    for (int axisNumber = 0; axisNumber < 3; ++axisNumber) {
        const std::int16_t packed = static_cast<std::int16_t>(
            static_cast<int>(viewAngles[axisNumber] * ANGLE_TO_SHORT));
        prevcmd.angles[axisNumber] = packed;
        usercmd.angles[axisNumber] = packed;
    }
}

void idUCmdTracker::SetViewAngles(const idAngles& angles) {
    for (int axisNumber = 0; axisNumber < 3; ++axisNumber) {
        deltaViewAngles[axisNumber] = angles[axisNumber]
            - usercmd.angles[axisNumber] * SHORT_TO_ANGLE;
    }
    viewAngles = angles;
}

void idUCmdTracker::ConstrainViewAngles(idAngles& angles) {
    if (!constrainViewAngles) {
        return;
    }

    idAngles previous = viewAngles;
    angles.yaw = NormalizeAround(angles.yaw,
        constrainedViewAnglesBase.yaw);
    previous.yaw = NormalizeAround(previous.yaw,
        constrainedViewAnglesBase.yaw);
    const float step = constrainedViewAnglesRate > 0.0f
        ? constrainedViewAnglesRate
            * trackerServices->GetScaledFrameTime() * 0.001f
        : 0.0f;

    for (int axisNumber = 0; axisNumber < 3; ++axisNumber) {
        const float minimum = constrainedViewAnglesBase[axisNumber]
            - constrainedViewAnglesMinDelta[axisNumber];
        const float maximum = constrainedViewAnglesBase[axisNumber]
            + constrainedViewAnglesMaxDelta[axisNumber];
        if (constrainedViewAnglesRate <= 0.0f) {
            angles[axisNumber] = (std::max)(minimum,
                (std::min)(maximum, angles[axisNumber]));
        } else if (angles[axisNumber] < minimum) {
            angles[axisNumber] = previous[axisNumber] >= minimum
                ? minimum
                : (std::min)(minimum, previous[axisNumber] + step);
        } else if (angles[axisNumber] > maximum) {
            angles[axisNumber] = previous[axisNumber] <= maximum
                ? maximum
                : (std::max)(maximum, previous[axisNumber] - step);
        }
    }
    angles.yaw = Normalize180(angles.yaw);
}

void idUCmdTracker::SetViewAnglesConstraintExplicit(bool constrain,
        const idAngles& baseAngles, const idAngles& minDeltaAngles,
        const idAngles& maxDeltaAngles, float rate) {
    constrainViewAngles = constrain;
    constrainedViewAnglesBase = baseAngles;
    constrainedViewAnglesMinDelta = minDeltaAngles;
    constrainedViewAnglesMaxDelta = maxDeltaAngles;
    constrainedViewAnglesRate = rate;
    for (int axisNumber = 0; axisNumber < 3; ++axisNumber) {
        constrainedViewAnglesBase[axisNumber] = Normalize180(
            constrainedViewAnglesBase[axisNumber]);
    }
}

void idUCmdTracker::ResetPrevViewAngles() {
    prevViewAngles = viewAngles;
}

bool idUCmdTracker::Update(const usercmd_t& newCommand,
        const idUCmdInhibit& inhibit) {
    prevcmd = usercmd;
    usercmdRaw = newCommand;
    prevViewAngles = viewAngles;

    const int flags = inhibit.flags;
    const bool viewIsInhibited = (flags
        & (idUCmdInhibit::UCMD_INHIBIT_VIEW
            | idUCmdInhibit::UCMD_INHIBIT_VIEW_DISCARD)) != 0;
    const bool wasInhibited = cmdInhibited;

    if (flags <= idUCmdInhibit::UCMD_INHIBIT_NONE) {
        usercmd = newCommand;
        usercmd.buttons &= ~inhibit.buttons;
        usercmd.forwardmove = ClampMove(newCommand.forwardmove,
            inhibit.minForward, inhibit.maxForward);
        usercmd.rightmove = ClampMove(newCommand.rightmove,
            inhibit.minRight, inhibit.maxRight);
        usercmd.upmove = ClampMove(newCommand.upmove,
            inhibit.minUp, inhibit.maxUp);
        usercmd.inhibited = inhibit.game;
        if (inhibit.game) {
            usercmd.ClearMoveCmds();
            std::memcpy(usercmd.angles, prevcmd.angles,
                sizeof(usercmd.angles));
        }
        if ((clearViewDeltaNextUpdate && !viewIsInhibited)
                || (wasInhibited && !usercmd.inhibited)) {
            clearViewDeltaNextUpdate = false;
            RecalculateDelta(*this);
        }
        cmdInhibited = false;
        for (int axisNumber = 0; axisNumber < 3; ++axisNumber) {
            cmdAngles[axisNumber] = usercmd.angles[axisNumber]
                * SHORT_TO_ANGLE;
        }
        return true;
    }

    if (!wasInhibited && viewIsInhibited) {
        cmdInhibited = true;
        if ((flags & idUCmdInhibit::UCMD_INHIBIT_VIEW_DISCARD) != 0) {
            clearViewDeltaNextUpdate = true;
        }
    }
    usercmd.forwardmove = (flags
        & idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_FWD) != 0
        ? 0 : ClampMove(newCommand.forwardmove,
            inhibit.minForward, inhibit.maxForward);
    usercmd.rightmove = (flags
        & idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_RT) != 0
        ? 0 : ClampMove(newCommand.rightmove,
            inhibit.minRight, inhibit.maxRight);
    usercmd.upmove = (flags
        & idUCmdInhibit::UCMD_INHIBIT_MOVEMENT_UP) != 0
        ? 0 : ClampMove(newCommand.upmove, inhibit.minUp, inhibit.maxUp);
    if ((flags & idUCmdInhibit::UCMD_INHIBIT_BUTTONS) == 0) {
        usercmd.buttons = newCommand.buttons;
    }
    usercmd.buttons &= ~inhibit.buttons;
    if (!viewIsInhibited) {
        std::memcpy(usercmd.angles, newCommand.angles,
            sizeof(usercmd.angles));
    }
    if (wasInhibited && !viewIsInhibited) {
        RecalculateDelta(*this);
        cmdInhibited = false;
    }
    usercmd.inhibited = newCommand.inhibited || inhibit.game;
    return false;
}

void idUCmdTracker::Clamp180(idAngles& clamped) const {
    for (int axisNumber = 0; axisNumber < 3; ++axisNumber) {
        clamped[axisNumber] = Normalize180(
            usercmd.angles[axisNumber] * SHORT_TO_ANGLE
                + deltaViewAngles[axisNumber]);
    }
}

void idPresentablePlayer::SetViewAnglesConstraintExplicit(bool constrain,
        const idAngles& baseAngles, const idAngles& minDeltaAngles,
        const idAngles& maxDeltaAngles, float rate) {
    ucmdTracker1.SetViewAnglesConstraintExplicit(constrain, baseAngles,
        minDeltaAngles, maxDeltaAngles, rate);
}

void idPresentablePlayer::SetViewAnglesConstraint(bool constrain,
        const idAngles& minAngles, const idAngles& maxAngles, float rate) {
    ucmdTracker1.SetViewAnglesConstraintExplicit(constrain,
        ucmdTracker1.viewAngles, minAngles, maxAngles, rate);
}

bool idUCmdTracker::IsPressedForPlayer(int mask) const {
    return (PlayerButtons(usercmd) & mask) != 0;
}

bool idUCmdTracker::WasReleasedForPlayer(int mask) const {
    return (PlayerButtons(usercmd) & mask) == 0
        && (PlayerButtons(prevcmd) & mask) != 0;
}

bool idUCmdTracker::WasPressedForPlayer(int mask) const {
    return (PlayerButtons(usercmd) & mask) != 0
        && (PlayerButtons(prevcmd) & mask) == 0;
}

bool idUCmdTracker::IsPressedForMenu(int mask) const {
    return (usercmd.buttons & mask) != 0;
}

bool idUCmdTracker::WasReleasedForMenu(int mask) const {
    return (usercmd.buttons & mask) == 0
        && (prevcmd.buttons & mask) != 0;
}
