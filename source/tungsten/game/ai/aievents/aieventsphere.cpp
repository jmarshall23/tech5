#include "aieventsphere.h"

namespace {

constexpr float SIMULATION_STEP_SECONDS = 1.0f / 60.0f;
constexpr float GRAVITY_PER_STEP = 1000.0f / 60.0f;

} // namespace

idColor idAIEventSphere::defaultColor(1.0f, 1.0f, 1.0f, 1.0f);

idAIEventSphere::idAIEventSphere() = default;

float idAIEventSphere::GetRadius() const {
    return eventDecl != nullptr ? eventDecl->radius : 0.0f;
}

const idColor& idAIEventSphere::GetColor() const {
    return defaultColor;
}

void idAIEventSphere::InternalDrawDebug(
        const int level, const int, const int duration) {
    const int debugDuration = duration > 0
        ? duration : Tungsten_GetAIEventGameMillisecondsPerFrame();
    Tungsten_DebugAIEventPoint(
        GetColor(), origin, debugDuration, true);
    if (level > 1) {
        Tungsten_DebugAIEventSphere(
            GetColor(), origin, GetRadius(), 12, debugDuration, true);
    }
}

idAIEventProjectedSphere::idAIEventProjectedSphere()
    : hasProjection(false)
    , projectedOrigin(0.0f, 0.0f, 0.0f)
    , curSimPos(0.0f, 0.0f, 0.0f)
    , curSimVel(0.0f, 0.0f, 0.0f)
    , traceFrom(0.0f, 0.0f, 0.0f)
    , bounces(-1)
    , horizontalBounces(-1) {
}

void idAIEventProjectedSphere::Clear() {
    hasProjection = false;
    projectedOrigin.Zero();
    curSimPos.Zero();
    curSimVel.Zero();
    traceFrom.Zero();
    bounces = -1;
    horizontalBounces = -1;
}

bool idAIEventProjectedSphere::InternalIsTouching(
        const idEntity* const entity, const int) {
    idVec3 entityOrigin;
    if (!Tungsten_GetAIEventEntityWorldOrigin(entity, entityOrigin)) {
        return false;
    }
    return (entityOrigin - origin).LengthSqr()
        <= GetRadius() * GetRadius();
}

idAIEvent::aiEventUpdateResult_t
idAIEventProjectedSphere::InternalUpdateAttached(const int) {
    idVec3 originatorVelocity;
    const bool hasOriginatorVelocity = Tungsten_GetAIEventEntityLinearVelocity(
        originator.GetSpawnId(), originatorVelocity);
    const bool shouldProject = Tungsten_IsAIEventPlayerSpawnId(
            instigator.GetSpawnId())
        && Tungsten_GetAIEventGameMilliseconds() - startTime >= 100
        && hasOriginatorVelocity
        && originatorVelocity.LengthSqr() >= 100.0f;

    if (!shouldProject) {
        idVec3 attachedOrigin;
        if (!Tungsten_GetAIEventEntityOrigin(
                originator.GetSpawnId(), attachedOrigin)) {
            return AIUPDATE_REMOVE;
        }
        origin = attachedOrigin;
        return AIUPDATE_OK;
    }

    if (hasProjection) {
        origin = projectedOrigin;
        return AIUPDATE_OK;
    }

    if (bounces == -1) {
        curSimPos = origin;
        curSimVel = hasOriginatorVelocity
            ? originatorVelocity : idVec3(0.0f, 0.0f, 0.0f);
        traceFrom = curSimPos;
        bounces = 0;
        horizontalBounces = 0;
    }

    for (int step = 0; step < 10; ++step) {
        const idVec3 previous = curSimPos;
        curSimPos.x += curSimVel.x * SIMULATION_STEP_SECONDS;
        curSimPos.y += curSimVel.y * SIMULATION_STEP_SECONDS;
        curSimPos.z += curSimVel.z * SIMULATION_STEP_SECONDS;
        curSimVel.z -= GRAVITY_PER_STEP;
        Tungsten_DebugAIEventTrajectory(previous, curSimPos, 0, 2000);

        if (step != 9) {
            continue;
        }

        idAIEventProjectionTrace trace;
        if (!Tungsten_TraceAIEventProjection(traceFrom, curSimPos, trace)) {
            traceFrom = curSimPos;
            return AIUPDATE_OK;
        }

        Tungsten_DebugAIEventTrajectory(
            trace.endPosition, trace.endPosition, 1, 2000);
        curSimPos = trace.endPosition;
        traceFrom.x = curSimPos.x
            - curSimVel.x * SIMULATION_STEP_SECONDS;
        traceFrom.y = curSimPos.y
            - curSimVel.y * SIMULATION_STEP_SECONDS;
        traceFrom.z = curSimPos.z
            - curSimVel.z * SIMULATION_STEP_SECONDS;

        float restitution = 0.5f;
        if (trace.normal.z > 0.1f) {
            restitution = 0.1f;
            ++horizontalBounces;
        } else {
            curSimVel.x *= 0.8f;
            curSimVel.y *= 0.8f;
            curSimVel.z *= 0.8f;
        }

        ++bounces;
        const float reflectedScale = curSimVel.Dot(trace.normal)
            * (restitution + 1.0f);
        curSimVel.x -= reflectedScale * trace.normal.x;
        curSimVel.y -= reflectedScale * trace.normal.y;
        curSimVel.z -= reflectedScale * trace.normal.z;

        if (bounces >= 4 || horizontalBounces >= 2) {
            projectedOrigin = trace.endPosition;
            origin = projectedOrigin;
            hasProjection = true;
        }
        return AIUPDATE_OK;
    }

    return AIUPDATE_OK;
}
