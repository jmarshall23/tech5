#include "game/entities/animcamera.h"

#include <algorithm>
#include <cmath>

namespace {
idAnimCameraServices defaultAnimCameraServices;
idAnimCameraServices* animCameraServices = &defaultAnimCameraServices;

float ClampFov(const float degrees) {
    return std::max(1.0f, std::min(179.0f, degrees));
}

int SecondsToMilliseconds(const float seconds) {
    return static_cast<int>(seconds * 1000.0f);
}
}

void idAnimCamera::SetServices(idAnimCameraServices* const services) {
    animCameraServices = services == nullptr
        ? &defaultAnimCameraServices : services;
}

idAnimCameraServices& idAnimCamera::Services() {
    return *animCameraServices;
}

// Retail: 0x82C05400 ?JobSync@idAnimCamera@@UAAXXZ
void idAnimCamera::JobSync() {
    Services().JobSync(*this);
}

// Retail: 0x82C05478 ?CalcValue@idRenderParmLerp@@QBAXPAVidVec4@@@Z
void idRenderParmLerp::CalcValue(idVec4& destination) const {
    for (int index = 0; index < 4; ++index) {
        destination[index] = (overrideMask & (1 << index)) != 0
            ? overrideValue[index] : curValue[index];
    }
    if (isDepthOfField) {
        destination.z += destination.x;
        destination.y = std::max(destination.y - destination.x, 0.0f);
    }
}

// Retail: 0x82C05540 ?Update@idRenderParmLerp@@QAAXAAVidView@@H@Z
void idRenderParmLerp::Update(const int currentTime) {
    if (name.IsEmpty()) {
        return;
    }
    if (overrideMask != 15 && startTime < 0 && overrideMask == 0) {
        return;
    }
    if (startTime >= 0) {
        const int elapsed = currentTime - startTime;
        if (duration > 0 && elapsed < duration) {
            const float fraction = std::max(0.0f,
                static_cast<float>(elapsed) / static_cast<float>(duration));
            for (int index = 0; index < 4; ++index) {
                curValue[index] = startValue[index]
                    + (endValue[index] - startValue[index]) * fraction;
            }
        } else {
            curValue = endValue;
            startTime = -1;
            duration = -1;
        }
    }
    idVec4 value;
    CalcValue(value);
    idAnimCamera::Services().ApplyRenderParm(name.c_str(), value);
}

void idRenderParmLerp::Begin(const idVec4& destination,
        const int currentTime, const int milliseconds) {
    startTime = currentTime;
    duration = std::max(milliseconds, 0);
    startValue = curValue;
    endValue = destination;
}

// Retail: 0x82C05688 ??1idAnimCamera@@UAA@XZ
idAnimCamera::~idAnimCamera() {
    Services().Shutdown(*this);
}

// Retail: 0x82C05848 ?Pause@idAnimCamera@@QAAXXZ
void idAnimCamera::Pause() {
    if (pauseTime >= 0) {
        return;
    }
    pauseTime = Services().GetGameMilliseconds();
    Services().PauseAnimation(*this, pauseTime);
}

// Retail: 0x82C05898 ?Draw@idAnimCamera@@UAA_NPAVidPlayer@@@Z
bool idAnimCamera::Draw(idPlayer* const player) {
    if ((overrideDOFMask & 1) == 0) {
        depthOfField.overrideValue.x = cameraDOF;
        if (cameraDOF >= 0.0f) {
            depthOfField.overrideMask |= 1;
        } else {
            depthOfField.overrideMask &= ~1;
        }
    }
    const int currentTime = Services().GetGameMilliseconds();
    for (idRenderParmLerp* renderParm : renderParms) {
        renderParm->Update(currentTime);
    }
    return Services().Draw(*this, player);
}

// Retail: 0x82C05E20 ?AnimEvent_CameraFade@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraFade(const idMD6Anim*,
        const idVec3& color, const float alpha, const float seconds) {
    screenFade.fadeColor.Set(color.x, color.y, color.z, alpha);
    screenFade.fadeTime = SecondsToMilliseconds(seconds);
    return {};
}

// Retail: 0x82C05E58 ?AnimEvent_CameraTimeScale@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraTimeScale(
        const idMD6Anim*, const float scale) {
    Services().SetCVarFloat("timescale", scale);
    return {};
}

// Retail: 0x82C05EA8 ?AnimEvent_CameraSound@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraSound(
        const idMD6Anim*, const idSoundShader* const sound) {
    Services().PlaySound(*this, sound);
    return {};
}

// Retail: 0x82C05EF0 ?AnimEvent_CameraWaitForKeypress@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraWaitForKeypress(const idMD6Anim*) {
    waitingForKey = true;
    Pause();
    return {};
}

// Retail: 0x82C05F58 ?SetDOFOverride@idAnimCamera@@QAAXABVidVec4@@@Z
void idAnimCamera::SetDOFOverride(const idVec4& value) {
    for (int index = 0; index < 4; ++index) {
        SetDOFOverride(value[index], index);
    }
}

// Retail: 0x82C05FE8 ?SetDOFOverride@idAnimCamera@@QAAXMH@Z
void idAnimCamera::SetDOFOverride(const float value, const int index) {
    if (index < 0 || index >= 4) {
        return;
    }
    const int bit = 1 << index;
    depthOfField.overrideValue[index] = value;
    if (value < 0.0f) {
        depthOfField.overrideMask &= ~bit;
        overrideDOFMask &= ~bit;
    } else {
        depthOfField.overrideMask |= bit;
        overrideDOFMask |= bit;
    }
}

// Retail: 0x82C06058 ?AnimEvent_CameraRenderParm@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraRenderParm(const idMD6Anim*,
        const char* const name_, const float x, const float y,
        const float z, const float w, const float durationSeconds) {
    for (idRenderParmLerp* renderParm : renderParms) {
        if (idStr::Icmp(renderParm->name.c_str(), name_) == 0) {
            renderParm->Begin(idVec4(x, y, z, w),
                Services().GetGameMilliseconds(),
                SecondsToMilliseconds(durationSeconds));
            break;
        }
    }
    return {};
}

// Retail: 0x82C06168 ?AnimEvent_CameraTeleportClientToViewPos@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraTeleportClientToViewPos(
        const idMD6Anim*) {
    Services().TeleportPlayerToView(*this);
    return {};
}

// Retail: 0x82C06238 ?AnimEvent_CameraKillVehicleAI@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraKillVehicleAI(
        const idMD6Anim*, const char* const name_) {
    Services().KillVehicleAI(name_);
    return {};
}

// Retail: 0x82C062B0 ?AnimEvent_CameraCVarFloat@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraCVarFloat(const idMD6Anim*,
        const char* const name_, const float value) {
    Services().SetCVarFloat(name_, value);
    return {};
}

// Retail: 0x82C06300 ?AnimEvent_CameraCVarString@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraCVarString(const idMD6Anim*,
        const char* const name_, const char* const value) {
    Services().SetCVarString(name_, value);
    return {};
}

// Retail: 0x82C06350 ?AnimEvent_CameraSetFieldOfView@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraSetFieldOfView(
        const idMD6Anim*, const float degrees) {
    cameraFOV = ClampFov(degrees);
    fovStartValue = cameraFOV;
    fovEndValue = cameraFOV;
    fovDuration = 0;
    return {};
}

// Retail: 0x82C06380 ?AnimEvent_CameraLerpToFOV@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraLerpToFOV(
        const idMD6Anim*, const float degrees, const int milliseconds) {
    fovStartValue = cameraFOV;
    fovEndValue = ClampFov(degrees);
    fovStartTime = Services().GetGameMilliseconds();
    fovDuration = std::max(milliseconds, 0);
    if (fovDuration == 0) {
        cameraFOV = fovEndValue;
    }
    return {};
}

// Retail: 0x82C06450 ?AnimEvent_CameraPause@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraPause(const idMD6Anim*) {
    Pause();
    return {};
}

// Retail: 0x82C064B0 ??0idRenderParmLerp@@QAA@PBDH@Z
idRenderParmLerp::idRenderParmLerp(
        const char* const name_, const int valueCount)
    : name(name_ == nullptr ? "" : name_),
      numValues(std::max(0, std::min(4, valueCount))),
      startTime(-1), duration(-1),
      startValue(0.0f, 0.0f, 0.0f, 0.0f),
      endValue(0.0f, 0.0f, 0.0f, 0.0f),
      curValue(0.0f, 0.0f, 0.0f, 0.0f),
      overrideValue(0.0f, 0.0f, 0.0f, 0.0f), overrideMask(0),
      isDepthOfField(idStr::Icmp(name.c_str(), "depthoffield") == 0) {
}

// Retail: 0x82C065F0 ?Spawn@idAnimCamera@@UAAXXZ
void idAnimCamera::Spawn() {
    Services().Spawn(*this);
    camJointIdx = Services().ResolveCameraJoint(*this,
        cameraJointName.c_str());
    camAnim = Services().ResolveCameraAlias(*this, animationName);
    cameraFOV = ClampFov(initialFov);
    fovStartValue = fovEndValue = cameraFOV;
    fovDuration = 0;
    // Retail: 0x82C06898 $LN117 cleanup normalized by RAII-owned state.
}

// Retail: 0x82C068C0 ?Unpause@idAnimCamera@@QAAXXZ
void idAnimCamera::Unpause() {
    waitingForKey = false;
    if (pauseTime < 0) {
        return;
    }
    const int currentTime = Services().GetGameMilliseconds();
    const int pausedDuration = std::max(currentTime - pauseTime, 0);
    startTime += pausedDuration;
    blendStartTime += pausedDuration;
    if (fovDuration > 0) {
        fovStartTime += pausedDuration;
    }
    Services().UnpauseAnimation(*this, pauseTime, currentTime);
    pauseTime = -1;
}

// Retail: 0x82C06940 ?SetCameraAnim@idAnimCamera@@QAAXPBD@Z
void idAnimCamera::SetCameraAnim(const char* const name_) {
    camAnim = Services().ResolveCameraAnimation(*this, name_);
}

// Retail: 0x82C06A20 ?InternalDeactivate@idAnimCamera@@MAA_NXZ
bool idAnimCamera::InternalDeactivate() {
    if (exitBlendTime > 0 && endTime == 0) {
        Services().ActivateDoneTarget(*this);
        Services().CapturePlayerView(*this, startPos, startQuat);
        endTime = Services().GetGameMilliseconds();
        Services().ScheduleDeactivate(*this, exitBlendTime);
        return false;
    }
    Services().ActivateDoneTarget(*this);
    active = false;
    return Services().DeactivateCamera(*this);
}

// Retail: 0x82C06D18 ?AnimEvent_CameraDepthOfField@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraDepthOfField(const idMD6Anim* anim,
        const float blurStart, const float blurScale,
        const float durationSeconds) {
    return AnimEvent_CameraRenderParm(anim, "depthoffield",
        blurStart, blurScale, 0.0f, 0.0f, durationSeconds);
}

// Retail: 0x82C06DB0 ?Think@idAnimCamera@@UAAXXZ
void idAnimCamera::Think() {
    if (!active) {
        return;
    }
    Services().RunPhysics(*this);
    if (!Services().GetCameraTransform(
            *this, camJointIdx, camPos, camAxis)) {
        return;
    }

    float userFov = cameraFOV;
    float userDof = cameraDOF;
    if (Services().GetCameraUserChannels(*this, userFov, userDof)) {
        if (userFov > 0.0f) {
            cameraFOV = userFov;
        }
        cameraDOF = userDof;
    } else {
        const int currentTime = Services().GetGameMilliseconds();
        if (fovDuration > 0) {
            const float fraction = std::max(0.0f, std::min(1.0f,
                static_cast<float>(currentTime - fovStartTime)
                    / static_cast<float>(fovDuration)));
            cameraFOV = fovStartValue
                + (fovEndValue - fovStartValue) * fraction;
            if (fraction >= 1.0f) {
                fovDuration = 0;
            }
        }
        cameraDOF = -1.0f;
    }

    Services().BlendCameraTransform(*this,
        initialBlendTime, exitBlendTime);
    Services().BlendAnimation(*this);

    if (!Services().IsAnimationPaused(*this)) {
        if (remainingFrames > 0) {
            if (--remainingFrames == 0) {
                InternalDeactivate();
                return;
            }
        } else if (remainingFrames < 0) {
            const bool loopLimitReached = numLoops > 1
                && Services().GetAnimationLoopCount(*this) >= numLoops;
            const bool singlePlayDone = numLoops == 1
                && Services().IsAnimationDone(*this);
            if (loopLimitReached || singlePlayDone || camAnim == nullptr) {
                remainingFrames = 1;
            }
        }
    }

    Services().UpdateVisuals(*this);
    if (Services().WasCameraInputPressed(*this)) {
        if (waitingForKey) {
            Unpause();
        } else if (abortable) {
            InternalDeactivate();
            return;
        }
    }
    if (screenFade.fadeTime >= 0) {
        Services().ApplyScreenFade(
            *this, screenFade.fadeColor, screenFade.fadeTime);
        screenFade.fadeTime = -1;
    }
    if (!Services().IsAnimationPaused(*this)) {
        Services().ProcessFrameCommands(*this);
    }
    if (shouldPause) {
        Pause();
        shouldPause = false;
    }
}

// Retail: 0x82C07568 ?AnimEvent_Trigger@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_Trigger(
        const idMD6Anim*, const char* const entityName) {
    Services().TriggerEntity(*this, entityName);
    return {};
}

// Retail: 0x82C07630 ?AnimEvent_CameraTeleportClient@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraTeleportClient(const idMD6Anim*,
        const idVec3& position, const idAngles& angles) {
    Services().TeleportPlayer(*this, position, angles);
    return {};
}

// Retail: 0x82C076C8 ?AnimEvent_CameraSetJoint@idAnimCamera@@...
eventVoid idAnimCamera::AnimEvent_CameraSetJoint(
        const idMD6Anim*, const char* const jointName) {
    cameraJointName = jointName == nullptr ? "" : jointName;
    camJointIdx = Services().ResolveCameraJoint(*this,
        cameraJointName.c_str());
    return {};
}

// Retail: 0x82C07748 ??0idAnimCamera@@QAA@XZ
idAnimCamera::idAnimCamera()
    : cameraJointName("camera"), cameraFovChannel(""),
      cameraDofChannel(""), animationName(), guiName(""), numLoops(1),
      initialFov(80.0f), hidePlayer(true), abortable(false),
      useDebugPlayerIfNeeded(false), forceVirtualMaterialLoad(false),
      initialBlendTime(500), startCamAnimImmediately(true),
      exitBlendTime(500), triggerWhenDone(nullptr),
      shouldPauseOnStart(false), fadeInOnStart(false),
      drawPlayerGUIS(true), showLetterboxView(false),
      targetAspect(1.7777778f), useHighQualityMipGeneration(true),
      adaptiveGlare(false), hasActivated(false), shouldPause(false),
      waitingForKey(false), blendAngleOffset(0.0f, 0.0f, 0.0f),
      camPos(0.0f, 0.0f, 0.0f), camAxis(1.0f), camJointIdx(),
      camAnim(nullptr), fovStartValue(0.0f), fovEndValue(0.0f),
      fovStartTime(0), fovDuration(0), pauseTime(-1),
      offset(0.0f, 0.0f, 0.0f), remainingFrames(0),
      depthOfField("depthoffield", 4), fogColor("fogcolor", 4),
      fogScale("fogscale", 1), overrideDOFMask(0), blendStartTime(0),
      startTime(0), endTime(0), startPos(0.0f, 0.0f, 0.0f),
      startQuat(0.0f, 0.0f, 0.0f, 1.0f), isBlendingIn(false),
      cameraFOV(80.0f), cameraDOF(-1.0f), active(false) {
    renderParms[0] = &depthOfField;
    renderParms[1] = &fogColor;
    renderParms[2] = &fogScale;
}

// Retail: 0x82C07BD8 ?InternalActivate@idAnimCamera@@MAA_NPAVidEntity@@@Z
bool idAnimCamera::InternalActivate(idEntity* const activator) {
    if (shouldPauseOnStart) {
        if (hasActivated) {
            Unpause();
            return false;
        }
        shouldPause = true;
    }
    hasActivated = true;
    if (!Services().ActivateCamera(*this, activator)) {
        return false;
    }

    active = true;
    endTime = 0;
    remainingFrames = -1;
    cameraFOV = ClampFov(initialFov);
    fovStartValue = fovEndValue = cameraFOV;
    fovDuration = 0;
    const int currentTime = Services().GetGameMilliseconds();
    startTime = currentTime;
    blendStartTime = currentTime;
    Services().CapturePlayerView(*this, startPos, startQuat);
    Services().BeginCameraAnimation(*this, camAnim, numLoops != 1);
    if (initialBlendTime > 0 && !startCamAnimImmediately) {
        isBlendingIn = true;
        shouldPause = true;
    } else {
        isBlendingIn = false;
    }
    if (fadeInOnStart) {
        screenFade.fadeColor.Set(0.0f, 0.0f, 0.0f, 0.0f);
        screenFade.fadeTime = 1000;
    }
    return true;
}
