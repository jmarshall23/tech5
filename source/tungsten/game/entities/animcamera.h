#pragma once

#include "game/gamesys/eventarg.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idAnimCamera;
class idEntity;
class idMD6Anim;
class idPlayer;
class idSoundShader;

class idRenderParmLerp {
public:
    idRenderParmLerp(const char* name = nullptr, int valueCount = 4);

    void CalcValue(idVec4& destination) const;
    void Update(int currentTime);
    void Begin(const idVec4& destination, int currentTime, int milliseconds);

    idStr name;
    int numValues;
    int startTime;
    int duration;
    idVec4 startValue;
    idVec4 endValue;
    idVec4 curValue;
    idVec4 overrideValue;
    int overrideMask;
    bool isDepthOfField;
};

class idAnimCameraServices {
public:
    virtual ~idAnimCameraServices() = default;
    virtual int GetGameMilliseconds() const { return 0; }
    virtual void JobSync(idAnimCamera&) {}
    virtual void ApplyRenderParm(const char*, const idVec4&) {}
    virtual void Shutdown(idAnimCamera&) {}
    virtual bool Draw(idAnimCamera&, idPlayer*) { return false; }
    virtual void PauseAnimation(idAnimCamera&, int) {}
    virtual void UnpauseAnimation(idAnimCamera&, int, int) {}
    virtual void SetCVarFloat(const char*, float) {}
    virtual void SetCVarString(const char*, const char*) {}
    virtual void PlaySound(idAnimCamera&, const idSoundShader*) {}
    virtual void TeleportPlayerToView(idAnimCamera&) {}
    virtual void KillVehicleAI(const char*) {}
    virtual void TeleportPlayer(
        idAnimCamera&, const idVec3&, const idAngles&) {}
    virtual void TriggerEntity(idAnimCamera&, const char*) {}
    virtual void Spawn(idAnimCamera&) {}
    virtual const idMD6Anim* ResolveCameraAnimation(
        idAnimCamera&, const char*) { return nullptr; }
    virtual const idMD6Anim* ResolveCameraAlias(
        idAnimCamera&, idAnimAliasHandle) { return nullptr; }
    virtual idJointIndex ResolveCameraJoint(
        const idAnimCamera&, const char*) const { return {}; }
    virtual bool ActivateCamera(idAnimCamera&, idEntity*) { return false; }
    virtual bool DeactivateCamera(idAnimCamera&) { return true; }
    virtual void BeginCameraAnimation(
        idAnimCamera&, const idMD6Anim*, bool) {}
    virtual void CapturePlayerView(idAnimCamera&,
        idVec3& position, idQuat& rotation) const {
        position.Zero(); rotation = idQuat(0.0f, 0.0f, 0.0f, 1.0f);
    }
    virtual void ScheduleDeactivate(idAnimCamera&, int) {}
    virtual void ActivateDoneTarget(idAnimCamera&) {}
    virtual bool GetCameraTransform(idAnimCamera&,
        idJointIndex, idVec3&, idMat3&) { return false; }
    virtual bool GetCameraUserChannels(
        idAnimCamera&, float&, float&) { return false; }
    virtual void BlendCameraTransform(idAnimCamera&, int, int) {}
    virtual void RunPhysics(idAnimCamera&) {}
    virtual void BlendAnimation(idAnimCamera&) {}
    virtual bool IsAnimationPaused(const idAnimCamera&) const {
        return false;
    }
    virtual bool IsAnimationDone(const idAnimCamera&) const { return true; }
    virtual int GetAnimationLoopCount(const idAnimCamera&) const { return 0; }
    virtual bool WasCameraInputPressed(const idAnimCamera&) const {
        return false;
    }
    virtual void ApplyScreenFade(
        idAnimCamera&, const idVec4&, int) {}
    virtual void ProcessFrameCommands(idAnimCamera&) {}
    virtual void UpdateVisuals(idAnimCamera&) {}
};

class idAnimCamera {
public:
    struct idScreenFade {
        int fadeTime = -1;
        idVec4 fadeColor{0.0f, 0.0f, 0.0f, 1.0f};
    };

    idAnimCamera();
    virtual ~idAnimCamera();

    static void SetServices(idAnimCameraServices* services);
    static idAnimCameraServices& Services();

    virtual void JobSync();
    virtual bool Draw(idPlayer* player);
    virtual void Think();
    void Pause();
    void Unpause();
    void Spawn();
    void SetCameraAnim(const char* name);
    virtual bool InternalActivate(idEntity* activator);
    virtual bool InternalDeactivate();

    eventVoid AnimEvent_CameraFade(const idMD6Anim*,
        const idVec3& color, float alpha, float seconds);
    eventVoid AnimEvent_CameraTimeScale(const idMD6Anim*, float scale);
    eventVoid AnimEvent_CameraSound(
        const idMD6Anim*, const idSoundShader* sound);
    eventVoid AnimEvent_CameraWaitForKeypress(const idMD6Anim*);
    void SetDOFOverride(const idVec4& value);
    void SetDOFOverride(float value, int index);
    eventVoid AnimEvent_CameraRenderParm(const idMD6Anim*,
        const char* name, float x, float y, float z, float w,
        float durationSeconds);
    eventVoid AnimEvent_CameraTeleportClientToViewPos(const idMD6Anim*);
    eventVoid AnimEvent_CameraKillVehicleAI(
        const idMD6Anim*, const char* name);
    eventVoid AnimEvent_CameraCVarFloat(
        const idMD6Anim*, const char* name, float value);
    eventVoid AnimEvent_CameraCVarString(
        const idMD6Anim*, const char* name, const char* value);
    eventVoid AnimEvent_CameraSetFieldOfView(
        const idMD6Anim*, float degrees);
    eventVoid AnimEvent_CameraLerpToFOV(
        const idMD6Anim*, float degrees, int milliseconds);
    eventVoid AnimEvent_CameraPause(const idMD6Anim*);
    eventVoid AnimEvent_CameraDepthOfField(const idMD6Anim*,
        float blurStart, float blurScale, float durationSeconds);
    eventVoid AnimEvent_Trigger(const idMD6Anim*, const char* entityName);
    eventVoid AnimEvent_CameraTeleportClient(const idMD6Anim*,
        const idVec3& position, const idAngles& angles);
    eventVoid AnimEvent_CameraSetJoint(
        const idMD6Anim*, const char* jointName);

    idStr cameraJointName;
    idStr cameraFovChannel;
    idStr cameraDofChannel;
    idAnimAliasHandle animationName;
    idStr guiName;
    int numLoops;
    float initialFov;
    bool hidePlayer;
    bool abortable;
    bool useDebugPlayerIfNeeded;
    bool forceVirtualMaterialLoad;
    int initialBlendTime;
    bool startCamAnimImmediately;
    int exitBlendTime;
    idEntity* triggerWhenDone;
    bool shouldPauseOnStart;
    bool fadeInOnStart;
    bool drawPlayerGUIS;
    bool showLetterboxView;
    float targetAspect;
    bool useHighQualityMipGeneration;
    bool adaptiveGlare;
    bool hasActivated;
    bool shouldPause;
    bool waitingForKey;
    idAngles blendAngleOffset;
    idVec3 camPos;
    idMat3 camAxis;
    idJointIndex camJointIdx;
    const idMD6Anim* camAnim;
    float fovStartValue;
    float fovEndValue;
    int fovStartTime;
    int fovDuration;
    int pauseTime;
    idVec3 offset;
    idScreenFade screenFade;
    int remainingFrames;
    idRenderParmLerp depthOfField;
    idRenderParmLerp fogColor;
    idRenderParmLerp fogScale;
    int overrideDOFMask;
    int blendStartTime;
    int startTime;
    int endTime;
    idVec3 startPos;
    idQuat startQuat;
    bool isBlendingIn;
    idRenderParmLerp* renderParms[3];
    float cameraFOV;
    float cameraDOF;
    bool active;
};
