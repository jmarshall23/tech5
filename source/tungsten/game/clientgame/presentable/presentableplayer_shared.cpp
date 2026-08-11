#include "presentableplayer.h"

#include <algorithm>
#include <cmath>

#define playerServices (Tungsten_GetPresentablePlayerServices())

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
    idVec3 origin;
    idMat3 axis;
    playerServices->GetViewTransform(*this, origin, axis);
    idPresentable::UpdateSound(origin, axis,
        idVec3(0.0f, 0.0f, 0.0f), index + 1);
}

void idPresentablePlayer::ClientPredictTriggers() {
    playerServices->PredictCollisionTriggers(*this);
}
