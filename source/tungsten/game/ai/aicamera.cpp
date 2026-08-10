#include "aicamera.h"

#include <algorithm>
#include <cmath>

namespace {

float NormalizeAngle180(float angle) {
    while (angle > 180.0f) angle -= 360.0f;
    while (angle < -180.0f) angle += 360.0f;
    return angle;
}

idMat3 DirectionToAxis(idVec3 direction) {
    if (direction.NormalizeFast() == 0.0f) {
        return idMat3(1.0f);
    }
    idVec3 referenceUp(0.0f, 0.0f, 1.0f);
    if (std::fabs(direction.z) > 0.999f) {
        referenceUp.Set(0.0f, 1.0f, 0.0f);
    }
    idVec3 left = referenceUp.Cross(direction);
    left.NormalizeFast();
    idVec3 up = direction.Cross(left);
    up.NormalizeFast();
    return idMat3(
        direction.x, direction.y, direction.z,
        left.x, left.y, left.z,
        up.x, up.y, up.z);
}

} // namespace

// Retail symbol: ??1idAICamera_Control@@UAA@XZ
// EA: 0x82A40C08, RVA: 0x00A40C08
idAICamera_Control::~idAICamera_Control() = default;

// Retail symbol: ??0idAICamera_Control@@QAA@XZ
// EA: 0x82A40C18, RVA: 0x00A40C18
idAICamera_Control::idAICamera_Control()
    : target(nullptr)
    , flying(false)
    , flyTo(0.0f, 0.0f, 0.0f)
    , camPos(0.0f, 0.0f, 0.0f)
    , camAxis(1.0f)
    , interactionNormal(0.0f, 0.0f, 0.0f)
    , angles(0.0f, 0.0f, 0.0f)
    , distance(128.0f) {
}

// Retail symbol: ?FlyTo@idAICamera_Control@@QAAXABVidVec3@@@Z
// EA: 0x82A40D28, RVA: 0x00A40D28
void idAICamera_Control::FlyTo(const idVec3& endPosition) {
    flying = true;
    flyTo = endPosition;
}

// Retail symbol: ?Draw@idAICamera_Control@@QAAXPAVidPlayer@@@Z
// EA: 0x82A40D50, RVA: 0x00A40D50
void idAICamera_Control::Draw(idPlayer* const player) {
    if (target != nullptr) {
        Tungsten_RenderAICameraView(target, player, camPos, camAxis);
    }
}

// Retail symbol:
// ?Update@idAICamera_Control@@QAAXABVusercmd_t@@0_N@Z
// EA: 0x82A40DE0, RVA: 0x00A40DE0
void idAICamera_Control::Update(
        const usercmd_t& previousCommand,
        const usercmd_t& currentCommand,
        const bool actionScriptRunning) {
    if (target == nullptr) {
        return;
    }

    idVec3 focus;
    if (!Tungsten_GetAICameraFocus(target, focus)) {
        return;
    }

    idVec3 desiredPosition;
    if (flying) {
        desiredPosition = flyTo;
    } else if (actionScriptRunning) {
        idVec3 direction = interactionNormal;
        Tungsten_PrepareAICameraActionScript(
            target, focus + direction * 256.0f, direction);
        desiredPosition = Tungsten_TraceAICamera(
            target, focus, focus - direction * distance);
    } else {
        constexpr float SHORT_TO_ANGLE = 360.0f / 65536.0f;
        angles.pitch += NormalizeAngle180(
            static_cast<float>(currentCommand.angles[0]
                - previousCommand.angles[0]) * SHORT_TO_ANGLE);
        angles.yaw += NormalizeAngle180(
            static_cast<float>(currentCommand.angles[1]
                - previousCommand.angles[1]) * SHORT_TO_ANGLE);
        angles.pitch = (std::max)(-35.0f, (std::min)(35.0f, angles.pitch));
        const idVec3 forward = angles.ToForward();
        desiredPosition = Tungsten_TraceAICamera(
            target, focus, focus - forward * distance);
    }

    const float lerpScale = Tungsten_GetAICameraLerpScale();
    camPos = camPos + (desiredPosition - camPos) * lerpScale;
    camAxis = DirectionToAxis(focus - camPos);
    camPos = camPos - camAxis[0] * Tungsten_GetAICameraForwardOffset();
}
