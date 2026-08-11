#include "presentableplayer.h"

#include <algorithm>

#define playerServices (Tungsten_GetPresentablePlayerServices())

namespace {

constexpr float kDegreesToPackedAngle = 65536.0f / 360.0f;
constexpr float kPackedAngleToDegrees = 360.0f / 65536.0f;

} // namespace

void idPresentablePlayer::RecordClientFire(const idWeapon* weapon,
        const idDeclProjectile* projectileDeclaration,
        const idFireParms& fireParameters,
        const idTestFireResults& testResults,
        const idFinishFireResults& finishResults) {
    if (playerServices->IsServer() || weapon == nullptr) return;
    idVec3 firePosition;
    idAngles fireAngles;
    if (!playerServices->BuildClientFireRecord(*this, weapon,
            projectileDeclaration, fireParameters, testResults,
            finishResults, firePosition, fireAngles)) {
        return;
    }
    if (GetEquippedWeapon(EQUIP_RIGHT_HAND) != weapon) return;
    ++clientFire.fireCount;
    clientFire.firePos[0] = static_cast<std::int16_t>(firePosition.x);
    clientFire.firePos[1] = static_cast<std::int16_t>(firePosition.y);
    clientFire.firePos[2] = static_cast<std::int16_t>(firePosition.z);
    clientFire.fireAngles[0] = static_cast<std::int16_t>(
        fireAngles.pitch * kDegreesToPackedAngle);
    clientFire.fireAngles[1] = static_cast<std::int16_t>(
        fireAngles.yaw * kDegreesToPackedAngle);
}

void idPresentablePlayer::ClientHitScanHit(int hitEntityNumber,
        int jointNumber, int bodyId,
        const idDeclWeapon* weaponDeclaration,
        const idDeclProjectile* projectileDeclaration,
        int serverTimeOfHit) {
    if (projectileDeclaration == nullptr || hitEntityNumber == entityNumber) {
        return;
    }
    playerServices->ApplyClientHitScanHit(*this, hitEntityNumber,
        jointNumber, bodyId, weaponDeclaration, projectileDeclaration,
        serverTimeOfHit);
}

void idPresentablePlayer::PerformClientFire(idWeapon* weapon,
        int serverTime, const idVec3& commandFirePosition,
        const idMat3& commandFireAxis) {
    if (weapon == nullptr || IsDead()) return;
    playerServices->PerformRecordedClientFire(*this, weapon, serverTime,
        commandFirePosition, commandFireAxis);
}

void idPresentablePlayer::EvaluateClientFire(const usercmd_t& command,
        int, int) {
    if (!playerServices->ClientFireEvaluationEnabled()) return;
    if (command.fireCount - clientFire.fireCount > 3) {
        clientFire.fireCount = static_cast<std::uint16_t>(
            command.fireCount - 1);
    }
    if (clientFire.fireCount == command.fireCount) {
        idWeapon* weapon = GetEquippedWeapon(EQUIP_RIGHT_HAND);
        if (weapon != nullptr) playerServices->ReleaseClientFireTrigger(weapon);
    }
    while (clientFire.fireCount < command.fireCount) {
        idWeapon* weapon = GetEquippedWeapon(EQUIP_RIGHT_HAND);
        const idVec3 firePosition(
            static_cast<float>(command.firePos[0]),
            static_cast<float>(command.firePos[1]),
            static_cast<float>(command.firePos[2]));
        const idAngles fireAngles(
            command.fireAngles[0] * kPackedAngleToDegrees,
            command.fireAngles[1] * kPackedAngleToDegrees, 0.0f);
        PerformClientFire(weapon, command.serverGameTime, firePosition,
            fireAngles.ToMat3());
        ++clientFire.fireCount;
    }
    if (clientFire.fireCount > command.fireCount && command.fireCount != 0) {
        clientFire.fireCount = command.fireCount;
    }
}
