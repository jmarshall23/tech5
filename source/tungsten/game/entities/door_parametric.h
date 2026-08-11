#pragma once

#include "game/entities/door_base.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idClipModel;
class idPresentable;
class idRenderModel;
class idDoor_Parametric;

struct idDoorParametricAngleCommand {
    idEntity* activator = nullptr;
    idVec3 direction{0.0f, 0.0f, 0.0f};
    float duration = 0.0f;
    float yaw = 0.0f;
};

class idDoorParametricServices {
public:
    virtual ~idDoorParametricServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual void HideEntity(idDoor_Parametric& door);
    virtual void ShowEntity(idDoor_Parametric& door);
    virtual void BecomeInactive(idDoor_Parametric& door, int flags);
    virtual void BecomeActive(idDoor_Parametric& door, int flags);
    virtual void UnlinkClip(idDoor_Parametric& door);
    virtual void LinkClip(idDoor_Parametric& door);
    virtual void RunPhysics(idDoor_Parametric& door);
    virtual bool IsActor(const idEntity* entity) const;
    virtual bool IsAI(const idEntity* entity) const;
    virtual void ReportNonActorAIUse(const idEntity* entity) const;
    virtual idVec3 GetEntityOrigin(const idEntity* entity) const;
    virtual idBounds GetEntityBounds(const idEntity* entity) const;
    virtual void PlaySound(idDoor_Parametric& door,
        const idSoundShader* sound);
    virtual void DeleteRequiredKey(idEntity* owner,
        const idDeclInventory* key);

    virtual bool IsMegaModel(const idDoor_Parametric& door) const;
    virtual void WarnSpawn(const idDoor_Parametric& door,
        const char* reason);
    virtual void QueueRemove(idDoor_Parametric& door);
    virtual idClipModel* AllocateFrameClip(idDoor_Parametric& door,
        idRenderModel* model);
    virtual idPresentable* AllocateFramePresentable(
        idDoor_Parametric& door, idRenderModel* model);
    virtual idPresentable* AllocateAnimatedPresentable(
        idDoor_Parametric& door, idRenderModel* model);
    virtual void DeleteClipModel(idClipModel* clipModel);
    virtual void DeletePresentable(idPresentable* presentable);
    virtual void FreeMainPresentable(idDoor_Parametric& door);
    virtual void ReleaseRenderModel(idRenderModel* model);
    virtual void ConfigureFrame(idDoor_Parametric& door,
        idClipModel* clipModel, idPresentable* presentable,
        const idVec3& origin, const idMat3& axis);
    virtual void ConfigureParametricPhysics(idDoor_Parametric& door,
        idRenderModel* model, const idVec3& origin,
        const idMat3& axis, int contents);
    virtual idBounds GetDoorClipBounds(
        const idDoor_Parametric& door) const;
    virtual void SetDoorContents(idDoor_Parametric& door, int contents);
    virtual void PresentFrame(idPresentable* presentable);
    virtual void PresentAttachment(idPresentable* presentable,
        const idVec3& origin, const idMat3& axis);
    virtual void PresentDoor(idDoor_Parametric& door);
    virtual void ConfigureMainClipInfo(idDoor_Parametric& door,
        const idVec3& origin, const idMat3& axis, int contents);

    virtual void AddDoorMotionEvent(idDoor_Parametric& door,
        idEntity* user, const idVec3& origin, int delay);
    virtual bool IsGatherQuerySubmitted(std::uint64_t query) const;
    virtual bool GatheredQueryHasActor(std::uint64_t query) const;
    virtual std::uint64_t SubmitActorGather(const idBounds& bounds,
        int contents);
    virtual float GetDoorClosingRange() const;

    virtual void BeginAngularInterpolation(idDoor_Parametric& door,
        int currentTime, int durationMilliseconds,
        float startAngle, float endAngle);
    virtual void BeginLinearInterpolation(idDoor_Parametric& door,
        int currentTime, int durationMilliseconds,
        const idVec3& startOffset, const idVec3& endOffset);
    virtual void ConvertToRigidBody(idDoor_Parametric& door,
        const idVec3& origin, const idMat3& axis,
        const idVec3& linearVelocity);
    virtual void SetFrameClipContents(idDoor_Parametric& door,
        int contents);
    virtual void ScheduleLockGrindAngle(idDoor_Parametric& door,
        const idDoorParametricAngleCommand& command);
    virtual void ScheduleDisableObstacle(idDoor_Parametric& door,
        int delayMilliseconds);
};

class idDoor_Parametric : public idDoor_Base {
public:
    enum slideDir_t {
        SLIDE_UP = 0,
        SLIDE_DOWN,
        SLIDE_LEFT,
        SLIDE_RIGHT,
        SLIDE_FORWARD,
        SLIDE_BACKWARD
    };

    enum axis_t {
        AXIS_X = 0,
        AXIS_Y,
        AXIS_Z
    };

    idDoor_Parametric();
    ~idDoor_Parametric() override;

    static void SetServices(idDoorParametricServices* services);
    static idDoorParametricServices& ParametricServices();

    virtual void Hide();
    virtual void Show();
    void SetLocked(bool lock, idEntity* user) override;
    bool IsLockedForEntity(const idEntity* entity,
        float kickedAmount) const override;
    bool Event_IsOpen() const;
    bool Event_IsClosed() const;
    bool Event_IsLockedForEntity(idEntity* entity) const;
    idVec3 Event_GetCenterOfDoor() const;
    virtual idPresentable* AllocPresentable(idRenderModel* renderModel);
    void AutoClose();
    bool Unlock(idEntity* user, float kickedAmount);
    virtual void GetUseLocation(const idEntity* actor, idVec3& position) const;
    float GetCurrentAngle() const;
    virtual void GetSoundTransform(idVec3& soundOrigin,
        idMat3& soundAxis) const;
    idVec3 Event_GetAIUsePosition(idEntity* entity) const;
    void Event_LockGrinderSetAngleAtTime(idEntity* activator,
        const idVec3& direction, float duration, float yaw);
    void Event_DisableObstacleFlag();
    virtual void LockGrind(idEntity* source, idEntity* lockGrinder);
    void Spawn();
    virtual void Think();
    bool CanClose(bool testingForUse) const override;
    bool Use(idEntity* user, int usableState) override;
    bool IsOpen() const override;
    bool IsClosed() const override;
    void Event_SetAngleAtTime(idEntity* source,
        float duration, float yaw);

    idClipModel* frameClip;
    idPresentable* framePresentable;
    idPresentable* doorAttachment;
    idRenderModel* frame;
    idRenderModel* door;
    axis_t heading_axis;
    axis_t rotation_axis;
    float min_angle;
    float max_angle;
    float min_kick_angle;
    float max_kick_angle;
    float start_angle;
    float angularspeed;
    bool invertRotationDir;
    bool slidingDoor;
    slideDir_t slideDir;
    float slideDist;
    float slideSpeed;
    float lockGrindRestAngle;
    idVec3 rotate_axis;
    idVec3 default_axis;
    const idSoundShader* start_sound;
    const idSoundShader* close_sound;
    const idSoundShader* kick_open_sound;
    idVec3 door_center;
    idVec3 door_ai_offset;
    int close_time;
    int close_range;
    int autoCloseTime;
    int forceUnopenedTime;
    idVec3 slideVec;
    idVec3 closedPos;
    mutable std::uint64_t canCloseQuery;

    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    idVec3 physicsOrigin;
    idMat3 physicsAxis;
    idBounds doorClipBounds;
    idVec3 linearOffset;
    idVec3 targetLinearOffset;
    float currentAngle;
    float targetAngle;
    int linearEndTime;
    int angularEndTime;
    int physicsContents;
    int frameClipContents;
    int thinkFlags;
    bool hidden;
    bool clipLinked;
    bool removed;
    bool usingRigidBody;
};
