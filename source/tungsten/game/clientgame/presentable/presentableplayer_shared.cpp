#include "presentableplayer.h"

#include <algorithm>
#include <cmath>

#define playerServices (Tungsten_GetPresentablePlayerServices())

namespace {

idAngles QuatToPlayerAngles(const idQuat& quaternion) {
    constexpr float radiansToDegrees = 57.29577951308232f;
    const float sinRoll = 2.0f * (quaternion.w * quaternion.x
        + quaternion.y * quaternion.z);
    const float cosRoll = 1.0f - 2.0f
        * (quaternion.x * quaternion.x + quaternion.y * quaternion.y);
    const float sinPitch = 2.0f * (quaternion.w * quaternion.y
        - quaternion.z * quaternion.x);
    const float sinYaw = 2.0f * (quaternion.w * quaternion.z
        + quaternion.x * quaternion.y);
    const float cosYaw = 1.0f - 2.0f
        * (quaternion.y * quaternion.y + quaternion.z * quaternion.z);
    const float pitch = std::fabs(sinPitch) >= 1.0f
        ? std::copysign(90.0f, sinPitch)
        : std::asin(sinPitch) * radiansToDegrees;
    return idAngles(pitch, std::atan2(sinYaw, cosYaw) * radiansToDegrees,
        std::atan2(sinRoll, cosRoll) * radiansToDegrees);
}

} // namespace

bool idPresentablePlayer::IsZoomedIn() const {
    return zoomedIn;
}

idWeapon* idPresentablePlayer::GetPendingWeapon() const {
    if (!IsLocallyControlled() || pendingQuickWeapon < 0) {
        return const_cast<idPresentablePlayer*>(this)->GetEquippedWeapon(
            EQUIP_RIGHT_HAND);
    }
    return playerServices->GetPendingQuickWeapon(*this, pendingQuickWeapon);
}

void idPresentablePlayer::Reload() {
    if (!playerServices->ReloadHand(*this, EQUIP_RIGHT_HAND, false)) {
        playerServices->ReloadHand(*this, EQUIP_LEFT_HAND, false);
    }
}

void idPresentablePlayer::ClearPendingAmmo() {
    pendingAmmo = nullptr;
    nextAmmoChangeTime = 0;
}

int idPresentablePlayer::StartSoundShader(soundChannel_t channel,
        const idSoundShader* shader, const soundShaderParms_t& parameters,
        std::uint8_t peerMask) {
    return idPresentable::StartSoundShader(channel, shader, parameters,
        peerMask);
}

int idPresentablePlayer::StartSoundShader_Predicted(
        soundChannel_t channel, const idSoundShader* shader,
        int soundShaderFlags) {
    const std::uint8_t peerMask = playerServices->IsMultiplayer()
        ? GetPeerMaskForPrediction() : 0xFF;
    return idPresentable::StartSoundShader(channel, shader,
        soundShaderFlags, peerMask);
}

void idPresentablePlayer::StopSound(soundChannel_t channel,
        std::uint8_t peerMask) {
    idPresentable::StopSound(channel, peerMask);
}

void idPresentablePlayer::StopSound_Predicted(soundChannel_t channel) {
    idPresentable::StopSound(channel, GetPeerMaskForPrediction());
}

void idPresentablePlayer::SetSoundVolume(soundChannel_t channel,
        float volume, std::uint8_t peerMask) {
    idPresentable::SetSoundVolume(channel, volume, peerMask);
}

void idPresentablePlayer::PlayLocalSound(soundChannel_t channel,
        const idSoundShader* shader, int soundShaderFlags) {
    if (IsLocallyControlled()) {
        idPresentable::StartSoundShader(channel, shader, soundShaderFlags, 0);
    }
}

const decayParams_s& idPresentablePlayer::GetDecayParams(bool crouch) const {
    return crouch ? crouchingDecay : standingDecay;
}

idInventoryCollection* idPresentablePlayer::GetInventory() {
    return activeInventory;
}

void idPresentablePlayer::DisplayDeathMessage() {
    if (deathInfoShow) deathInfoShow = false;
}

int idPresentablePlayer::GetPeerIndex() {
    return playerServices->GetPlayerPeerIndex(*this);
}

std::uint8_t idPresentablePlayer::GetPeerMaskForPrediction() {
    const int peerIndex = GetPeerIndex();
    return peerIndex < 0 ? 0xFF
        : static_cast<std::uint8_t>(~(1u << peerIndex));
}

void idPresentablePlayer::InitOutlineModel() {
    if (!playerServices->IsMultiplayer()) return;
    if (outlineModel != nullptr) {
        playerServices->UpdateOutlineModel(outlineModel, true,
            idVec4(0.0f, 0.5f, 0.0f, 1.0f));
    }
    outlineModel = playerServices->CreatePlayerOutlineModel(*this);
    if (outlineModel != nullptr) {
        playerServices->UpdateOutlineModel(outlineModel, false,
            idVec4(0.0f, 0.5f, 0.0f, 1.0f));
    }
}

void idPresentablePlayer::PresentableRespawn(bool initial) {
    respawnCount = static_cast<std::uint8_t>((respawnCount + 1) % 7);
    ++respawnSerial;
    deathInfoShow = false;
    zoomedIn = false;
    perfectOriginActive = false;
    serverOverridePositionTime = playerServices->GetScaledGameTime();
    zoomFov.Init(0.0f, 0.0f, DefaultFov(), DefaultFov());
    for (idWeaponKick& kick : weaponKick) kick = idWeaponKick();
    playerServices->RespawnPlayerSystems(*this, initial);
}

void idPresentablePlayer::StartPerfectOrigin(const idQuat& idealAxis,
        const idVec3& idealPosition, int lerpTimeMS) {
    perfectOriginActive = true;
    playerServices->StartPerfectPlayerOrigin(*this, idealPosition,
        lerpTimeMS);
    perfectOriginRotation = idealAxis;
    perfectOriginDuration = lerpTimeMS;
    perfectOriginStartTime = GetPlayerGameTime();
}

void idPresentablePlayer::ChangeCurrentZoomLevel() {
    idWeapon* weapon = GetEquippedWeapon(EQUIP_RIGHT_HAND);
    if (weapon == nullptr || !playerServices->WeaponSupportsZoomLevels(weapon)) {
        return;
    }
    const int gameTime = GetPlayerGameTime();
    if (gameTime < zoomFov.GetEndTime()) return;
    int currentLevel = playerServices->GetWeaponZoomLevel(weapon);
    const float currentFov = playerServices->GetWeaponZoomFov(weapon,
        currentLevel);
    if (playerServices->GetWeaponChangeZoomLevelTime(weapon) < gameTime) {
        const int levelCount = playerServices->GetWeaponZoomLevelCount(weapon);
        currentLevel = currentLevel < levelCount - 1 ? currentLevel + 1 : 0;
        playerServices->SetWeaponZoomLevel(weapon, currentLevel);
    }
    zoomFov.Init(static_cast<float>(gameTime),
        static_cast<float>(playerServices->GetWeaponZoomTime(weapon)),
        currentFov, playerServices->GetWeaponZoomedFov(weapon));
}

void idPresentablePlayer::SetCurrentZoomLevel(int zoomLevel) {
    idWeapon* weapon = GetEquippedWeapon(EQUIP_RIGHT_HAND);
    if (weapon != nullptr
            && zoomLevel < playerServices->GetWeaponZoomLevelCount(weapon) - 1) {
        playerServices->SetWeaponZoomLevel(weapon, zoomLevel);
    }
}

void idPresentablePlayer::DecayOriginError() {
    const float length = originError.Length();
    if (length > 1000.0f || length <= 0.01f) {
        originError.Zero();
        return;
    }
    float decay = playerServices->GetOriginErrorDecayRate() * length;
    decay = (std::min)(decay,
        playerServices->GetOriginErrorMaximumDecay());
    idVec3 correction = originError * -1.0f;
    correction.NormalizeFast();
    originError = originError + correction * decay;
}

idAngles idPresentablePlayer::GetViewAngles(bool includeWeaponKick) const {
    idAngles result = playerViewAngles;
    if (includeWeaponKick) {
        result.pitch += weaponKick[2].GetOffset();
        result.pitch += weaponKick[4].GetOffset();
        result.yaw += weaponKick[1].GetOffset();
    }
    return result;
}

void idPresentablePlayer::SetLocalViewLimits(const idAngles& minimum,
        const idAngles& maximum) {
    localMinViewAngles = minimum;
    localMaxViewAngles = maximum;
}

void idPresentablePlayer::ResetLocalViewLimits() {
    localMinViewAngles = idAngles(-89.0f, -180.0f, 0.0f);
    localMaxViewAngles = idAngles(89.0f, 180.0f, 0.0f);
}

float idPresentablePlayer::DefaultFov() const {
    return playerServices->GetDefaultFov();
}

float idPresentablePlayer::CalcFov(bool) const {
    const float fov = zoomFov.GetCurrentValue(static_cast<float>(
        playerServices->GetPlayerGameTime()));
    return (std::max)(1.0f, (std::min)(179.0f, fov));
}

void idPresentablePlayer::CheckFovModified() {
    if (!playerServices->ConsumeFovModified()) return;
    const float fov = DefaultFov();
    zoomFov.Init(static_cast<float>(GetPlayerGameTime()), 0.0f, fov, fov);
}

idWeapon* idPresentablePlayer::GetWeaponClosestToSlot(bool forward,
        int currentSlot, bool requireAmmo) {
    idWeapon* exact = nullptr;
    idWeapon* nearest = nullptr;
    idWeapon* unarmed = nullptr;
    idWeapon* minimum = nullptr;
    idWeapon* maximum = nullptr;
    int nearestSlot = forward ? 0x7FFFFFFF : -0x7FFFFFFF;
    int minimumSlot = 0x7FFFFFFF;
    int maximumSlot = -0x7FFFFFFF;
    const int targetSlot = currentSlot + (forward ? 1 : -1);

    const int weaponCount = playerServices->GetInventoryWeaponCount(*this);
    for (int weaponIndex = 0; weaponIndex < weaponCount; ++weaponIndex) {
        idWeapon* weapon = playerServices->GetInventoryWeapon(*this,
            weaponIndex);
        if (weapon == nullptr
                || !playerServices->WeaponCanCycle(*this, weapon,
                    requireAmmo)) {
            continue;
        }
        const int slot = playerServices->GetWeaponCycleSlot(weapon);
        if (slot == 0) unarmed = weapon;
        if (slot < minimumSlot) {
            minimumSlot = slot;
            minimum = weapon;
        }
        if (slot > maximumSlot) {
            maximumSlot = slot;
            maximum = weapon;
        }
        if (slot == targetSlot) exact = weapon;
        if (forward) {
            if (slot > currentSlot && slot < nearestSlot) {
                nearestSlot = slot;
                nearest = weapon;
            }
        } else if (slot < currentSlot && slot > nearestSlot) {
            nearestSlot = slot;
            nearest = weapon;
        }
    }
    if (exact != nullptr) return exact;
    if (nearest != nullptr) return nearest;
    if (unarmed != nullptr) return unarmed;
    return forward ? minimum : maximum;
}

void idPresentablePlayer::SelectClosestWeapon(bool forward) {
    idWeapon* current = GetEquippedWeapon(EQUIP_RIGHT_HAND);
    const int currentSlot = current != nullptr
        ? playerServices->GetWeaponCycleSlot(current) : 0;
    idWeapon* selected = GetWeaponClosestToSlot(forward, currentSlot,
        playerServices->WeaponHasUsableAmmo(*this, current));
    if (selected == nullptr || selected == current) return;
    playerServices->PrepareWeaponForCycleSelection(selected);
    playerServices->SelectHandsWeapon(*this, EQUIP_RIGHT_HAND, selected,
        false);
    ClearPendingAmmo();
}

void idPresentablePlayer::NextWeapon() {
    SelectClosestWeapon(true);
}

void idPresentablePlayer::PrevWeapon() {
    SelectClosestWeapon(false);
}

void idPresentablePlayer::EquipPrevEquippedWeapon() {
    ClearPendingAmmo();
    idWeapon* previous = playerServices->GetPreviousEquippedWeapon(*this);
    if (previous != nullptr
            && playerServices->WeaponHasUsableAmmo(*this, previous)) {
        playerServices->SelectHandsWeapon(*this, EQUIP_RIGHT_HAND, previous,
            false);
    } else {
        SelectBestWeapon();
    }
}

int idPresentablePlayer::NextQuickWeaponSlot() const {
    idWeapon* current = pendingQuickWeapon >= 0 ? GetPendingWeapon()
        : const_cast<idPresentablePlayer*>(this)->GetEquippedWeapon(
            EQUIP_RIGHT_HAND);
    if (current == nullptr) return -1;
    const int quickSlot = playerServices->GetWeaponQuickSlot(current);
    const int firstSlot = quickSlot < 0 ? 0 : quickSlot;
    int slot = firstSlot;
    for (;;) {
        slot = slot == 3 ? 0 : slot + 1;
        if (slot == firstSlot) return -1;
        idWeapon* candidate = playerServices->GetQuickWeapon(*this, slot);
        if (candidate == current) return -1;
        if (candidate != nullptr
                && playerServices->WeaponIsUsable(*this, candidate)
                && playerServices->WeaponHasUsableAmmo(*this, candidate)) {
            return playerServices->GetWeaponQuickSlot(candidate);
        }
    }
}

const idDeclAmmo* idPresentablePlayer::GetNextAmmoDecl() const {
    idWeapon* weapon = const_cast<idPresentablePlayer*>(this)
        ->GetEquippedWeapon(EQUIP_RIGHT_HAND);
    return weapon != nullptr
        ? playerServices->GetNextAmmoDeclaration(*this, weapon) : nullptr;
}

void idPresentablePlayer::ReleaseWeaponKickRecoveryDelay() {
    const float gameTime = static_cast<float>(GetPlayerGameTime());
    idWeaponKick& pitchKick = weaponKick[2];
    if (gameTime < pitchKick.recoveryOffset.GetEndTime()
            && gameTime < pitchKick.recoilOffset.GetEndTime()) {
        pitchKick.recoveryOffset.SetStartTime(gameTime);
    }
}

void idPresentablePlayer::SetAmmoStatus(bool leftHand) {
    playerServices->UpdateAmmoStatus(*this, leftHand);
}

void idPresentablePlayer::SelectQuickAmmo(int slot) {
    nextAmmoChangeTime = GetPlayerGameTime();
    idWeapon* weapon = GetPendingWeapon();
    const idDeclAmmo* declaration = weapon != nullptr
        ? playerServices->GetQuickAmmoDeclaration(*this, weapon, slot)
        : nullptr;
    if (declaration == nullptr
            || !playerServices->IsQuickAmmoAvailable(*this, weapon,
                declaration)) {
        if (IsLocallyControlled()) {
            playerServices->PlayBadButtonSound(*this);
        }
        return;
    }
    pendingAmmo = declaration;
}

void idPresentablePlayer::SelectQuickWeapon(int slot) {
    nextWeaponChangeTime = 0;
    idWeapon* current = GetEquippedWeapon(EQUIP_RIGHT_HAND);
    int nextSlot = pendingQuickWeapon;
    if (current != nullptr
            && slot == playerServices->GetWeaponQuickSlot(current)) {
        nextSlot = -1;
    } else if (slot >= 0 && slot < 4
            && playerServices->GetQuickWeapon(*this, slot) != nullptr) {
        nextSlot = slot;
    }
    if (nextSlot != pendingQuickWeapon) {
        pendingQuickWeapon = nextSlot;
        pendingAmmo = nullptr;
    }
}

void idPresentablePlayer::ClearPickupItems() {
    playerServices->ClearHudPickupItems(*this);
}

void idPresentablePlayer::UpdateSound() {
    if (!IsLocallyControlled() || playerServices->UseThirdPersonSoundOrigin()) {
        idPresentable::UpdateSound();
        return;
    }
    idVec3 soundOrigin;
    idMat3 soundAxis;
    playerServices->GetViewTransform(*this, soundOrigin, soundAxis);
    idPresentable::UpdateSound(soundOrigin, soundAxis,
        idVec3(0.0f, 0.0f, 0.0f), index + 1);
}

void idPresentablePlayer::ClientPredictTriggers() {
    playerServices->PredictCollisionTriggers(*this);
}

bool idPresentablePlayer::ToggleDualWieldItem(bool justClear,
        bool leftWeaponToRightHand, bool forceOn) {
    if (GetEquippedWeapon(EQUIP_RIGHT_HAND) == nullptr) return false;
    return playerServices->ToggleDualWieldPlayerItem(*this, justClear,
        leftWeaponToRightHand, forceOn);
}

bool idPresentablePlayer::EquipItem(idInventoryItem* item) {
    return item != nullptr && playerServices->EquipPlayerItem(*this, item);
}

idInventoryItem* idPresentablePlayer::GetEquipped(equipSlot_t slot) const {
    return playerServices->GetEquippedPlayerItem(*this, slot);
}

bool idPresentablePlayer::IsDead() const {
    if (entity != nullptr && playerServices->IsServer()) {
        return playerServices->IsServerPlayerDead(*this);
    }
    return replicatedDead;
}

bool idPresentablePlayer::IsCrouching() const {
    if (entity != nullptr && playerServices->IsServer()) {
        return playerServices->IsServerPlayerCrouching(*this);
    }
    return playerServices->IsPredictedPlayerCrouching(*this);
}

bool idPresentablePlayer::AFIsActive() const {
    return entity != nullptr && playerServices->IsServer()
        && playerServices->IsPlayerAFActive(*this);
}

bool idPresentablePlayer::GetFocusFriendly() const {
    return entity != nullptr && playerServices->IsServer()
        && playerServices->GetServerFocusFriendly(*this);
}

bool idPresentablePlayer::DeployableAllowed(
        const idDeclThrowable* declaration) const {
    if (entity == nullptr || !playerServices->IsServer()
            || declaration == nullptr
            || !playerServices->ThrowableUsesDeployableRules(declaration)) {
        return true;
    }
    return playerServices->CanAddServerDeployable(*this);
}

void idPresentablePlayer::GetFireTrajectory(idVec3& firePosition,
        idMat3& fireAxis) const {
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->GetServerFireTrajectory(*this, firePosition,
            fireAxis);
    } else {
        firePosition = firstPersonViewOrigin;
        fireAxis = firstPersonViewAxis;
    }
}

bool idPresentablePlayer::BeforeUse() {
    return entity != nullptr && playerServices->IsServer()
        && playerServices->ServerBeforeUse(*this);
}

bool idPresentablePlayer::BeforeUseIsRunning() {
    return entity != nullptr && playerServices->IsServer()
        && playerServices->ServerBeforeUseIsRunning(*this);
}

void idPresentablePlayer::SetAngles(const idAngles& angles) {
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->SetServerPlayerAngles(*this, angles);
    }
}

bool idPresentablePlayer::IsPlayerControlInhibited() {
    if (playerServices->IsGamePaused()) return true;
    for (int guiIndex = GUI_DELIVERY; guiIndex < GUI_COUNT; ++guiIndex) {
        const playerGuis_t gui = static_cast<playerGuis_t>(guiIndex);
        if (!GuiIsActive(gui)) continue;
        idSWF* swf = GetPlayerGui(gui);
        if (swf != nullptr && playerServices->GuiInhibitsPlayerControl(swf)) {
            return true;
        }
    }
    return playerServices->LocalViewInhibitsPlayerControl(*this)
        || playerControlInhibited;
}

void idPresentablePlayer::InhibitFire(bool inhibit) {
    inhibitFireControl = inhibit;
    inhibitFireControlStartTime = playerServices->GetScaledGameTime();
}

bool idPresentablePlayer::CheckInhibitFire() {
    const int gameTime = playerServices->GetScaledGameTime();
    if (inhibitFireControlStartTime + 48 >= gameTime
            || (inhibitFireControl
                && ucmdTracker1.IsPressedForPlayer(1))) {
        inhibitFireControl = true;
    } else if (inhibitFireControl
            && !ucmdTracker1.IsPressedForPlayer(1)) {
        inhibitFireControl = false;
    }
    return inhibitFireControl || focusUseButtonOverride;
}

const idWeapon* idPresentablePlayer::GetControlWeapon() const {
    if (entity != nullptr && playerServices->IsServer()) {
        idWeapon* controlWeapon = playerServices->GetControlWeapon(*this);
        if (controlWeapon != nullptr) return controlWeapon;
    }
    return const_cast<idPresentablePlayer*>(this)->GetEquippedWeapon(
        EQUIP_RIGHT_HAND);
}

void idPresentablePlayer::SetControllerShake(float highMagnitude,
        int highDuration, float lowMagnitude, int lowDuration) {
    playerServices->SetControllerShake(*this,
        static_cast<float>(highDuration), static_cast<float>(lowDuration),
        highMagnitude, lowMagnitude);
}

void idPresentablePlayer::ShowInventory(bool inVehicle) {
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->ShowServerInventory(*this, inVehicle);
    }
}

void idPresentablePlayer::SetWalkState(walkState_t state) {
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->SetServerWalkState(*this, static_cast<int>(state));
    }
}

bool idPresentablePlayer::PlayFootStepEffect(
        footStepType_t footstepType) {
    return entity != nullptr && playerServices->IsServer()
        && playerServices->PlayServerFootStepEffect(*this,
            static_cast<int>(footstepType));
}

void idPresentablePlayer::PresentableDamaged(float damage) {
    const int gameTime = playerServices->GetScaledGameTime();
    if (!IsLocallyControlled() || painDebounceTime >= gameTime) return;
    painDebounceTime = gameTime + 1;
    playerServices->PlayPlayerPainFeedback(*this, damage);
}

void idPresentablePlayer::UpdateEditEntityMode() {
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->UpdateServerEditEntityMode(*this);
        playerServices->UpdateHandsHidden(*this);
    }
}

bool idPresentablePlayer::IsFullyZoomedIn() const {
    if (!IsLocallyControlled()) return replicatedFullyZoomed;
    idWeapon* weapon = const_cast<idPresentablePlayer*>(this)
        ->GetEquippedWeapon(EQUIP_RIGHT_HAND);
    if (weapon == nullptr) return false;
    const float gameTime = static_cast<float>(
        playerServices->GetPlayerGameTime());
    return (playerServices->WeaponSupportsZoom(weapon)
            && gameTime >= zoomFov.GetEndTime())
        || playerServices->WeaponForcesIronsight(weapon);
}

bool idPresentablePlayer::IsFullyZoomedOut() const {
    if (!IsLocallyControlled()) return !replicatedFullyZoomed;
    idWeapon* weapon = const_cast<idPresentablePlayer*>(this)
        ->GetEquippedWeapon(EQUIP_RIGHT_HAND);
    if (weapon == nullptr) return true;
    return static_cast<float>(playerServices->GetPlayerGameTime())
            >= zoomFov.GetEndTime()
        && !playerServices->WeaponSupportsZoom(weapon);
}

float idPresentablePlayer::GetMovementScale() const {
    idWeapon* weapon = const_cast<idPresentablePlayer*>(this)
        ->GetEquippedWeapon(EQUIP_RIGHT_HAND);
    return weapon != nullptr && IsFullyZoomedIn()
        ? playerServices->GetWeaponMovementScale(weapon) : 1.0f;
}

float idPresentablePlayer::GetCrouchedScale() const {
    idWeapon* weapon = const_cast<idPresentablePlayer*>(this)
        ->GetEquippedWeapon(EQUIP_RIGHT_HAND);
    return weapon != nullptr && IsFullyZoomedIn()
        ? playerServices->GetWeaponCrouchedScale(weapon) : 1.0f;
}

void idPresentablePlayer::NotifyThrowRelease(
        const idDeclThrowable* throwItem,
        idPresentableProjectile* spawnedProjectile) {
    ++throwCount;
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->NotifyServerThrowRelease(*this, throwItem,
            spawnedProjectile);
    }
}

void idPresentablePlayer::HandleCameraShake() {
    if (!cameraShake.active) return;
    const float elapsed = static_cast<float>(
        playerServices->GetScaledGameTime() - cameraShake.startTime);
    float amount = cameraShake.scale
        * std::exp(-elapsed * cameraShake.decay * 0.001f);
    if (amount < 0.01f) {
        cameraShake.active = false;
        amount = 0.0f;
    }
    playerServices->SetCameraShake(*this, amount);
}

void idPresentablePlayer::SetExplicitMove(const playerExplicitMove_t& move,
        bool alsoAllowPhysicsMove, bool useExplicitMove2) {
    explicitMoveType = alsoAllowPhysicsMove
        ? EXPLICIT_MOVE_SINGLE_ADDITIONAL : EXPLICIT_MOVE_SINGLE_EXCLUSIVE;
    if (!alsoAllowPhysicsMove && useExplicitMove2) {
        explicitMove2 = move;
    } else {
        explicitMove = move;
    }
}

void idPresentablePlayer::Init(const idDeclMD6* handsDeclMD6,
        const idDeclAnimWeb* handsDeclAnimWeb,
        const idDeclAnimWeb* handsDeclSecondaryAnimWeb,
        const idDeclFX* handsFX) {
    playerServices->InitializeSharedPlayer(*this, handsDeclMD6,
        handsDeclAnimWeb, handsDeclSecondaryAnimWeb, handsFX);
    InitOutlineModel();
    EnableInfluenceTrail();
}

void idPresentablePlayer::ToggleZoom(bool zoom) {
    if (wantZoom == zoom) return;
    const idWeapon* weapon = GetControlWeapon();
    wantZoom = weapon != nullptr
        && playerServices->CanTogglePlayerZoom(*this, weapon, zoom)
        ? zoom : false;
}

void idPresentablePlayer::SetupZoom(bool handsZoomIn, idWeapon* weapon) {
    if (weapon == nullptr || !playerServices->WeaponSupportsZoom(weapon)) {
        return;
    }
    const float gameTime = static_cast<float>(
        playerServices->GetPlayerGameTime());
    if (handsZoomIn) {
        const float zoomedFov = playerServices->GetWeaponZoomedFovValue(
            weapon);
        if (zoomedFov <= 0.0f) return;
        replicatedFullyZoomed = true;
        zoomFov.Init(gameTime,
            static_cast<float>(playerServices->GetWeaponZoomDuration(weapon)),
            DefaultFov(), zoomedFov);
        playerServices->SetPlayerWeaponZoomed(*this, weapon, true);
        playerServices->SetZoomHandsHidden(*this, true);
        playerServices->SetZoomBobScale(*this, 0.0f);
        return;
    }
    ToggleZoom(false);
    replicatedFullyZoomed = false;
    playerServices->SetPlayerWeaponZoomed(*this, weapon, false);
    playerServices->SetZoomHandsHidden(*this, false);
    playerServices->SetZoomBobScale(*this, 1.0f);
    const float defaultFov = DefaultFov();
    const float zoomedFov = playerServices->GetWeaponZoomedFovValue(weapon);
    float duration = static_cast<float>(
        playerServices->GetWeaponZoomDuration(weapon));
    if (zoomedFov > 0.0f && defaultFov - zoomedFov > 0.0001f) {
        duration *= (defaultFov - lastFov) / (defaultFov - zoomedFov);
    }
    zoomFov.Init(gameTime, (std::max)(0.0f, duration), lastFov,
        defaultFov);
}

idVec3 idPresentablePlayer::GetEyeOffset() const {
    return idVec3(0.0f, 0.0f, IsCrouching()
        ? playerServices->GetCrouchViewHeight()
        : playerServices->GetNormalViewHeight());
}

void idPresentablePlayer::SelectWeapon(int slot) {
    const int weaponCount = playerServices->GetInventoryWeaponCount(*this);
    for (int weaponIndex = 0; weaponIndex < weaponCount; ++weaponIndex) {
        idWeapon* weapon = playerServices->GetInventoryWeapon(*this,
            weaponIndex);
        if (weapon == nullptr
                || playerServices->GetWeaponCycleSlot(weapon) != slot) {
            continue;
        }
        const equipSlot_t equipSlot = playerServices->GetWeaponEquipSlot(
            weapon);
        if (GetEquippedWeapon(equipSlot) == weapon) {
            const idDeclAmmo* nextAmmo = GetNextAmmoDecl();
            if (nextAmmo != nullptr) {
                playerServices->SelectHandsAmmo(*this, nextAmmo, false);
            }
        } else {
            playerServices->SelectHandsWeapon(*this, equipSlot, weapon,
                false);
        }
        return;
    }
}

void idPresentablePlayer::ClearWeaponKick() {
    for (idWeaponKick& kick : weaponKick) kick = idWeaponKick();
    savedViewPitchForKick = 0.0f;
}

void idPresentablePlayer::UpdateWeaponKick(idAngles& viewAngles) {
    idWeaponKick& pitchKick = weaponKick[2];
    const float offset = pitchKick.GetOffset();
    if (offset >= 0.0f) return;
    const idAngles& inputAngles = GetControl() != nullptr
        ? ucmdTracker2.viewAngles : ucmdTracker1.viewAngles;
    if (std::fabs(savedViewPitchForKick - inputAngles.pitch) > 0.5f) {
        viewAngles.pitch += offset;
        pitchKick = idWeaponKick();
        savedViewPitchForKick = viewAngles.pitch;
    }
}

float idPresentablePlayer::GetCurWeaponSpread(bool secondary) const {
    const float gameTime = static_cast<float>(
        playerServices->GetPlayerGameTime());
    const float base = baseWeaponSpread.GetCurrentValue(gameTime);
    const float kick = kickWeaponSpread.GetCurrentValue(gameTime);
    const idWeapon* weapon = GetControlWeapon();
    const float projectileSpread = weapon != nullptr
        ? playerServices->GetCurrentProjectileSpread(weapon, secondary)
        : 0.0f;
    return (kick + 1.0f) * projectileSpread * base
        * playerServices->GetWeaponSpreadScale();
}

void idPresentablePlayer::UpdateWeaponAmmoInfo() {
    playerServices->UpdateWeaponAmmoHud(*this);
}

void idPresentablePlayer::WeaponFireFeedback(const idWeapon* weapon,
        const idDeclProjectile* projectileDeclaration) {
    playerServices->ApplyWeaponFireFeedback(*this, weapon,
        projectileDeclaration);
}

idWeapon* idPresentablePlayer::GetEquippedWeapon(equipSlot_t slot) {
    idWeapon* weapon = playerServices->GetEquippedPlayerWeapon(*this, slot);
    return weapon != nullptr ? weapon
        : idPresentableActor::GetEquippedWeapon(slot);
}

void idPresentablePlayer::DamageDealtFeedback(idPresentable* victim,
        bool predicted) {
    if (victim != nullptr) {
        playerServices->PlayDamageDealtFeedback(*this, victim, predicted);
    }
}

void idPresentablePlayer::UpdateDecal(float value, idStr tagName,
        float decalSize) {
    if (!playerServices->IsMultiplayer()
            && std::fabs(lastDecalValue - value) >= 0.000001f) {
        lastDecalValue = value;
        playerServices->UpdatePlayerDecal(*this,
            (std::max)(0.0f, (std::min)(1.0f, value)), tagName, decalSize);
    }
}

void idPresentablePlayer::GetSensitivityScale(float& mouseSensitivityScale,
        float& joySensitivityScale) const {
    idWeapon* weapon = const_cast<idPresentablePlayer*>(this)
        ->GetEquippedWeapon(EQUIP_RIGHT_HAND);
    if (weapon != nullptr && IsFullyZoomedIn()) {
        playerServices->GetWeaponSensitivityScale(weapon,
            mouseSensitivityScale, joySensitivityScale);
    } else {
        mouseSensitivityScale = 1.0f;
        joySensitivityScale = 1.0f;
    }
}

void idPresentablePlayer::Draw_Shared() {
    CheckFovModified();
    lastFov = CalcFov(true);
    playerServices->RenderSharedPlayerView(*this);
    UpdateScreenParticles();
    DrawGuis(entityNumber + 1);
}

inputSettings_t idPresentablePlayer::GetPlayerInputSettings() {
    inputSettings_t settings;
    playerServices->GetDefaultPlayerInputSettings(settings);
    GetSensitivityScale(settings.mouseSensScale, settings.joySensScale);
    return settings;
}

void idPresentablePlayer::PlayerUpdateZoomState() {
    idWeapon* weapon = const_cast<idWeapon*>(GetControlWeapon());
    if (weapon == nullptr) return;
    if (wantZoom && !replicatedFullyZoomed) {
        SetupZoom(true, weapon);
    } else if (!wantZoom && replicatedFullyZoomed) {
        SetupZoom(false, weapon);
    }
}

void idPresentablePlayer::OffsetThirdPersonView(float angle, float range,
        float height, const char* focusJoint, bool clip) {
    playerServices->OffsetPlayerThirdPersonView(*this, angle, range, height,
        focusJoint, clip);
}

void idPresentablePlayer::UpdateStepUpSprings() {
    playerServices->UpdatePlayerStepUpSprings(*this);
}

void idPresentablePlayer::WeaponFireFeedback(const idWeapon* weapon,
        const idDeclProjectile* projectileDeclaration,
        const idFireParms& fireParameters,
        const idTestFireResults& testResults,
        const idFinishFireResults& finishResults) {
    if (weapon != nullptr && !playerServices->IsServer()) {
        playerServices->RecordClientWeaponFire(*this, weapon,
            projectileDeclaration, fireParameters, testResults,
            finishResults);
    }
    WeaponFireFeedback(weapon, projectileDeclaration);
}

idEntity* idPresentablePlayer::GetFocusEntity() const {
    return entity != nullptr && playerServices->IsServer()
        ? playerServices->GetServerFocusEntity(*this) : nullptr;
}

void idPresentablePlayer::TrackUniqueProjectile(
        idPresentableProjectile* projectile) {
    uniqueTrackedProjectileSpawnId =
        playerServices->GetProjectileSpawnId(projectile);
    uniqueTrackedProjectileClientGameFrameWhenFired =
        playerServices->IsServer() ? playerServices->GetClientGameFrame()
            : ucmdTracker2.usercmd.clientGameFrame;
}

bool idPresentablePlayer::UniqueProjectileAllowed(
        const idDeclThrowable* throwableDeclaration) const {
    if (throwableDeclaration == nullptr
            || uniqueTrackedProjectileSpawnId == 0) {
        return true;
    }
    return !playerServices->UniqueTrackedProjectileIsActive(*this,
        throwableDeclaration, uniqueTrackedProjectileSpawnId);
}

bool idPresentablePlayer::Use() {
    return playerServices->UsePlayerFocus(*this);
}

void idPresentablePlayer::AddAttacker(idPresentable* attacker, float damage,
        const idVec3* direction, const idDeclDamage* damageDefinition) {
    if (attacker == this) return;
    playerServices->AddPlayerAttackerFeedback(*this, attacker, damage,
        direction, damageDefinition);
}

void idPresentablePlayer::UpdateDamageDealt() {
    playerServices->UpdatePlayerDamageDealtFeedback(*this);
}

void idPresentablePlayer::UpdateDamageFeedback() {
    playerServices->UpdatePlayerDamageIndicatorFeedback(*this);
}

void idPresentablePlayer::SetDefaults() {
    screenPrtState.SetNum(5);
    serializedViewOrigin.Zero();
    serializedViewAxis = idMat3(1.0f);
    standingDecay.linear = 0.9f;
    crouchingDecay.linear = 0.2f;
    wantZoom = false;
    replicatedFullyZoomed = false;
    ClearPendingAmmo();
    ClearWeaponKick();
    baseWeaponSpread.Init(0.0f, 0.0f, 1.0f, 1.0f);
    kickWeaponSpread.Init(0.0f, 0.0f, 0.0f, 0.0f);
    playerServices->ResetSharedPlayerDefaults(*this);
}

void idPresentablePlayer::CalculateView() {
    playerServices->CalculatePlayerView(*this);
}

void idPresentablePlayer::SetViewAngles(const idAngles& angles,
        bool force) {
    idAngles constrained = angles;
    if (!perfectOriginActive) {
        ucmdTracker1.ConstrainViewAngles(constrained);
        ucmdTracker2.ConstrainViewAngles(constrained);
    }
    ucmdTracker1.SetViewAngles(constrained);
    ucmdTracker2.SetViewAngles(constrained);
    playerViewAngles = constrained;
    if (force) CalculateView();
}

void idPresentablePlayer::UpdateViewAngles() {
    playerServices->UpdatePlayerViewAngles(*this);
    idAngles angles;
    ucmdTracker1.Clamp180(angles);
    UpdateWeaponKick(angles);
    const float pitchKick = weaponKick[2].GetOffset();
    angles.pitch = (std::max)(localMinViewAngles.pitch,
        (std::min)(localMaxViewAngles.pitch, angles.pitch + pitchKick))
        - pitchKick;
    if (!perfectOriginActive) {
        angles.yaw = (std::max)(localMinViewAngles.yaw,
            (std::min)(localMaxViewAngles.yaw, angles.yaw));
    } else if (perfectOriginDuration <= 0
            || GetPlayerGameTime() - perfectOriginStartTime
                >= perfectOriginDuration) {
        angles = QuatToPlayerAngles(perfectOriginRotation);
    }
    SetViewAngles(angles, false);
}

void idPresentablePlayer::CalcCurWeaponSpread() {
    float target = 1.0f;
    float transition = 0.0f;
    float recoveryDelay = 100.0f;
    playerServices->GetWeaponSpreadState(*this, target, transition,
        recoveryDelay);
    const float gameTime = static_cast<float>(GetPlayerGameTime());
    const float currentBase = baseWeaponSpread.GetCurrentValue(gameTime);
    baseWeaponSpread.Init(gameTime, transition, currentBase, target);
    if (gameTime >= kickWeaponSpread.GetEndTime()) {
        const float currentKick = kickWeaponSpread.GetCurrentValue(gameTime);
        kickWeaponSpread.Init(gameTime + recoveryDelay, 250.0f,
            currentKick, 0.0f);
    }
}

void idPresentablePlayer::UpdateWeapon() {
    if (IsDead()) {
        playerServices->UpdatePlayerHands(*this);
        return;
    }
    const int gameTime = GetPlayerGameTime();
    const bool canSelect = allowWeaponChange && GetControl() == nullptr
        && playerServices->CanProcessWeaponSelection(*this);
    if (canSelect) {
        const bool releasedMenu = ucmdTracker1.WasReleasedForMenu(64);
        const bool timedWeapon = nextWeaponChangeTime > 0
            && gameTime > nextWeaponChangeTime
            && !ucmdTracker1.IsPressedForMenu(64);
        if (releasedMenu || timedWeapon) {
            idWeapon* pendingWeapon = GetPendingWeapon();
            if (pendingWeapon != nullptr
                    && pendingWeapon != GetEquippedWeapon(EQUIP_RIGHT_HAND)) {
                playerServices->SelectHandsWeapon(*this, EQUIP_RIGHT_HAND,
                    pendingWeapon, useIntroBringUp);
                if (pendingAmmo != nullptr
                        && playerServices->PendingAmmoIsUsable(*this,
                            pendingWeapon, pendingAmmo)) {
                    playerServices->ForceHandsAmmo(*this, pendingAmmo);
                }
            }
            pendingQuickWeapon = -1;
            useIntroBringUp = false;
            nextWeaponChangeTime = 0;
            ClearPendingAmmo();
        } else if (pendingAmmo != nullptr && nextAmmoChangeTime > 0
                && gameTime > nextAmmoChangeTime
                && !ucmdTracker1.IsPressedForMenu(64)) {
            idWeapon* current = GetEquippedWeapon(EQUIP_RIGHT_HAND);
            if (playerServices->PendingAmmoIsUsable(*this, current,
                    pendingAmmo)) {
                playerServices->SelectHandsAmmo(*this, pendingAmmo, false);
            }
            ClearPendingAmmo();
        }
        CalcCurWeaponSpread();
        if (ucmdTracker1.WasPressedForPlayer(64)) {
            weaponButtonPressTime = gameTime;
        }
        if (ucmdTracker1.WasReleasedForPlayer(64)
                && pendingQuickWeapon == -1
                && gameTime - weaponButtonPressTime < 180) {
            pendingQuickWeapon = NextQuickWeaponSlot();
            if (pendingQuickWeapon != -1) nextWeaponChangeTime = gameTime;
        }
    }
    UpdateWeaponAmmoInfo();
    playerServices->UpdatePlayerHands(*this);
    if (entity != nullptr && playerServices->IsServer()) {
        playerServices->PostHandsUpdated(*this);
    }
}
