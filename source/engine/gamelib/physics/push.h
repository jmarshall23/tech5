#pragma once

#include "gamelib/physics/physics.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/rotation.h"

class idPush {
public:
    enum pushResult_t : int {
        PUSH_OK = 0,
        PUSH_BLOCKED = 1,
        PUSH_CRUSHED = 2
    };

    explicit idPush(idClip* clip = nullptr);
    void Init(idClip* clip);
    void InitSavingPushedPhysicsObjectState();
    void SavePhysicsObjectState(idPhysics* physics);
    void RestorePushedPhysicsObjectState();
    void SetPushedOnPushedPhysicsObjects(int deltaTime);
    float ClipPush(trace_t& results, idPhysics* pusher, int flags,
        const idVec3& oldOrigin, const idMat3& oldAxis,
        idVec3& newOrigin, idMat3& newAxis);

    idClip* clip;
    idList<idPhysics*, 77> pushed;

private:
    void ClipPhysicsObjectRotation(trace_t& trace, idPhysics* physics,
        const idClipModel* clipModel, idClipModel* skip,
        const idRotation& rotation);
    void ClipPhysicsObjectTranslation(trace_t& trace, idPhysics* physics,
        const idClipModel* clipModel, idClipModel* skip,
        const idVec3& translation);
    bool CanPushPhysicsObject(idPhysics* physics, int flags,
        idPhysics* pusher);
    int GetPhysicsObjectsTouchingBounds(idPhysics** physicsObjects,
        const idBounds& bounds, int flags, idPhysics* pusher);
    bool RotatePhysicsObjectToAxial(idPhysics* physics,
        const idVec3& rotationPoint, const idClipModel* clipModel);
    pushResult_t RecursiveTryTranslatePushPhysicsObject(trace_t& results,
        trace_t& trace, idPhysics* pusher, int flags,
        const idVec3& translation, float& mass);
    pushResult_t RecursiveTryRotatePushPhysicsObject(trace_t& results,
        trace_t& trace, idPhysics* pusher, int flags,
        const idRotation& rotation, float& mass);
    pushResult_t TryTranslatePushPhysicsObject(trace_t& results,
        idPhysics* check, idClipModel* pusherModel, int flags,
        const idVec3& oldOrigin, const idVec3& translation, float& mass);
    pushResult_t TryRotatePushPhysicsObject(trace_t& results,
        idPhysics* check, idClipModel* pusherModel, int flags,
        const idVec3& rotationPoint, const idMat3& oldAxis,
        const idRotation& rotation, float& mass);
    float ClipTranslationalPush(trace_t& results, idPhysics* pusher,
        int flags, const idVec3& newOrigin, const idVec3& translation);
    float ClipRotationalPush(trace_t& results, idPhysics* pusher,
        int flags, const idMat3& newAxis, const idRotation& rotation);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPush) == 20, "Recovered idPush ABI changed");
#endif
