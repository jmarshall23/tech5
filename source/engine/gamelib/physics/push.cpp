#include "gamelib/physics/push.h"

#include "gamelib/physics/clipmodel.h"

#include <algorithm>
#include <cstring>

int GameLib_GetPushPhysicsObjects(idClip* clip, const idBounds& bounds,
    idPhysics** objects, int maxObjects);
bool GameLib_GetPushSweepBounds(idPhysics* pusher,
    const idVec3& oldOrigin, const idVec3& newOrigin,
    const idMat3& oldAxis, const idMat3& newAxis, idBounds& bounds);
idRotation GameLib_GetPushRotation(const idVec3& origin,
    const idMat3& oldAxis, const idMat3& newAxis);
bool GameLib_RotatePushObjectToAxial(idPhysics* physics,
    const idVec3& rotationPoint, const idClipModel* clipModel);

namespace {

void ClearTrace(trace_t& trace, const idVec3& end,
    const idMat3& endAxis) {
    std::memset(&trace, 0, sizeof(trace));
    trace.fraction = 1.0f;
    trace.endpos = end;
    trace.endAxis = endAxis;
    trace.c.entityNum = 0x1FFF;
    trace.c.physicsId = -1;
}

} // namespace

idPush::idPush(idClip* const clip_)
    : clip(clip_)
    , pushed(4) {
}

void idPush::Init(idClip* const clip_) { clip = clip_; }

void idPush::InitSavingPushedPhysicsObjectState() { pushed.Clear(); }

void idPush::SavePhysicsObjectState(idPhysics* const physics) {
    if (physics == nullptr) return;
    for (int index = 0; index < pushed.Num(); ++index)
        if (pushed[index] == physics) return;
    physics->SaveState();
    pushed.Append(physics);
}

void idPush::RestorePushedPhysicsObjectState() {
    for (int index = 0; index < pushed.Num(); ++index)
        if (pushed[index] != nullptr) pushed[index]->RestoreState();
}

void idPush::SetPushedOnPushedPhysicsObjects(const int deltaTime) {
    for (int index = 0; index < pushed.Num(); ++index)
        if (pushed[index] != nullptr) pushed[index]->SetPushed(deltaTime);
}

void idPush::ClipPhysicsObjectRotation(trace_t& trace,
    idPhysics* const physics, const idClipModel* const clipModel,
    idClipModel* const skip, const idRotation& rotation) {
    if (skip != nullptr) skip->Disable();
    physics->ClipRotation(&trace, &rotation, clipModel);
    if (skip != nullptr) skip->Enable();
}

void idPush::ClipPhysicsObjectTranslation(trace_t& trace,
    idPhysics* const physics, const idClipModel* const clipModel,
    idClipModel* const skip, const idVec3& translation) {
    if (skip != nullptr) skip->Disable();
    physics->ClipTranslation(&trace, &translation, clipModel);
    if (skip != nullptr) skip->Enable();
}

bool idPush::CanPushPhysicsObject(idPhysics* const physics,
    const int flags, idPhysics* const pusher) {
    if (physics == nullptr || pusher == nullptr || physics == pusher) {
        return false;
    }
    const int pusherContents = pusher->GetContents(-1);
    if (!physics->IsPushable(pusherContents) ||
        (physics->GetClipMask(-1) & pusherContents) == 0) {
        return false;
    }
    if ((flags & 4) != 0 && physics->GetType() != PHYSICS_RIGIDBODY) {
        return false;
    }
    if ((flags & 8) != 0 &&
        pusher->IsGroundEntity(physics->GetEntityNumber())) {
        return false;
    }
    return true;
}

int idPush::GetPhysicsObjectsTouchingBounds(idPhysics** const objects,
    const idBounds& bounds, const int flags, idPhysics* const pusher) {
    if (clip == nullptr || objects == nullptr) return 0;
    idPhysics* candidates[256]{};
    const int count = (std::max)(0, (std::min)(256,
        GameLib_GetPushPhysicsObjects(clip, bounds, candidates, 256)));
    int accepted = 0;
    for (int index = 0; index < count; ++index) {
        if (!CanPushPhysicsObject(candidates[index], flags, pusher)) continue;
        bool duplicate = false;
        for (int check = 0; check < accepted; ++check)
            if (objects[check] == candidates[index]) duplicate = true;
        if (!duplicate) objects[accepted++] = candidates[index];
    }
    return accepted;
}

bool idPush::RotatePhysicsObjectToAxial(idPhysics* const physics,
    const idVec3& rotationPoint, const idClipModel* const clipModel) {
    return physics != nullptr && GameLib_RotatePushObjectToAxial(
        physics, rotationPoint, clipModel);
}

idPush::pushResult_t idPush::RecursiveTryTranslatePushPhysicsObject(
    trace_t& results, trace_t& trace, idPhysics* const pusher,
    const int flags, const idVec3& translation, float& mass) {
    idPhysics* const blocking = idPhysics::GetPhysicsForId(trace.c.physicsId);
    if (!CanPushPhysicsObject(blocking, flags & ~8, pusher)) {
        results = trace;
        return PUSH_BLOCKED;
    }
    const pushResult_t result = TryTranslatePushPhysicsObject(results,
        blocking, pusher->GetClipModel(0), flags, *blocking->GetOrigin(0),
        translation, mass);
    if (result == PUSH_OK) {
        pusher->ClipTranslation(&trace, &translation,
            pusher->GetClipModel(0));
    }
    return result;
}

idPush::pushResult_t idPush::TryTranslatePushPhysicsObject(
    trace_t& results, idPhysics* const check,
    idClipModel* const pusherModel, const int flags,
    const idVec3& oldOrigin, const idVec3& translation, float& mass) {
    if (check == nullptr) return PUSH_BLOCKED;
    trace_t trace{};
    ClipPhysicsObjectTranslation(trace, check, pusherModel,
        pusherModel, translation);
    if (trace.fraction < 1.0f) {
        const pushResult_t recursive = RecursiveTryTranslatePushPhysicsObject(
            results, trace, check, flags, translation, mass);
        if (recursive != PUSH_OK) return recursive;
    }
    SavePhysicsObjectState(check);
    check->Translate(&translation, -1);
    mass += check->GetMass(-1);
    ClearTrace(results, oldOrigin + translation, *check->GetAxis(0));
    return PUSH_OK;
}

idPush::pushResult_t idPush::RecursiveTryRotatePushPhysicsObject(
    trace_t& results, trace_t& trace, idPhysics* const pusher,
    const int flags, const idRotation& rotation, float& mass) {
    idPhysics* const blocking = idPhysics::GetPhysicsForId(trace.c.physicsId);
    if (!CanPushPhysicsObject(blocking, flags & ~8, pusher)) {
        results = trace;
        return PUSH_BLOCKED;
    }
    return TryRotatePushPhysicsObject(results, blocking,
        pusher->GetClipModel(0), flags, rotation.GetOrigin(),
        *blocking->GetAxis(0), rotation, mass);
}

idPush::pushResult_t idPush::TryRotatePushPhysicsObject(trace_t& results,
    idPhysics* const check, idClipModel* const pusherModel,
    const int flags, const idVec3& rotationPoint, const idMat3& oldAxis,
    const idRotation& rotation, float& mass) {
    if (check == nullptr) return PUSH_BLOCKED;
    trace_t trace{};
    ClipPhysicsObjectRotation(trace, check, pusherModel, pusherModel,
        rotation);
    if (trace.fraction < 1.0f) {
        const pushResult_t recursive = RecursiveTryRotatePushPhysicsObject(
            results, trace, check, flags, rotation, mass);
        if (recursive != PUSH_OK) return recursive;
    }
    SavePhysicsObjectState(check);
    check->Rotate(&rotation, -1);
    if ((flags & 2) != 0 && !RotatePhysicsObjectToAxial(check,
        rotationPoint, pusherModel)) {
        check->RestoreState();
        return PUSH_BLOCKED;
    }
    mass += check->GetMass(-1);
    ClearTrace(results, *check->GetOrigin(0), oldAxis * rotation.ToMat3());
    return PUSH_OK;
}

float idPush::ClipTranslationalPush(trace_t& results,
    idPhysics* const pusher, const int flags, const idVec3& newOrigin,
    const idVec3& translation) {
    idBounds sweep;
    if (!GameLib_GetPushSweepBounds(pusher,
        newOrigin - translation, newOrigin, *pusher->GetAxis(0),
        *pusher->GetAxis(0), sweep)) return 0.0f;
    idPhysics* objects[256]{};
    const int count = GetPhysicsObjectsTouchingBounds(objects, sweep,
        flags, pusher);
    float mass = 0.0f;
    for (int index = 0; index < count; ++index) {
        if (TryTranslatePushPhysicsObject(results, objects[index],
            pusher->GetClipModel(0), flags, *objects[index]->GetOrigin(0),
            translation, mass) != PUSH_OK) return mass;
    }
    return mass;
}

float idPush::ClipRotationalPush(trace_t& results,
    idPhysics* const pusher, const int flags, const idMat3& newAxis,
    const idRotation& rotation) {
    idBounds sweep;
    const idVec3 origin = *pusher->GetOrigin(0);
    if (!GameLib_GetPushSweepBounds(pusher, origin, origin,
        *pusher->GetAxis(0), newAxis, sweep)) return 0.0f;
    idPhysics* objects[256]{};
    const int count = GetPhysicsObjectsTouchingBounds(objects, sweep,
        flags, pusher);
    float mass = 0.0f;
    for (int index = 0; index < count; ++index) {
        if (TryRotatePushPhysicsObject(results, objects[index],
            pusher->GetClipModel(0), flags, origin,
            *objects[index]->GetAxis(0), rotation, mass) != PUSH_OK)
            return mass;
    }
    return mass;
}

float idPush::ClipPush(trace_t& results, idPhysics* const pusher,
    const int flags, const idVec3& oldOrigin, const idMat3& oldAxis,
    idVec3& newOrigin, idMat3& newAxis) {
    ClearTrace(results, newOrigin, newAxis);
    if (pusher == nullptr) return 0.0f;
    InitSavingPushedPhysicsObjectState();
    float totalMass = 0.0f;
    const idVec3 translation = newOrigin - oldOrigin;
    if (translation.LengthSqr() > 0.0f) {
        totalMass += ClipTranslationalPush(results, pusher, flags,
            newOrigin, translation);
        if (results.fraction < 1.0f) {
            RestorePushedPhysicsObjectState();
            newOrigin = oldOrigin;
            newAxis = oldAxis;
            return totalMass;
        }
    }
    const idRotation rotation = GameLib_GetPushRotation(newOrigin,
        oldAxis, newAxis);
    if (rotation.GetAngle() != 0.0f) {
        totalMass += ClipRotationalPush(results, pusher, flags,
            newAxis, rotation);
        if (results.fraction < 1.0f) {
            RestorePushedPhysicsObjectState();
            newOrigin = oldOrigin;
            newAxis = oldAxis;
        }
    }
    return totalMass;
}
