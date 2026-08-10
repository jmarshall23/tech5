#include "aieventtrace.h"

#include <cstring>

namespace {

constexpr std::uint64_t INVALID_CLIP_QUERY = 0xFFFFFFFF00000000ull;

const idBounds clearedBounds = {
    idVec3(1.0e30f, 1.0e30f, 1.0e30f),
    idVec3(-1.0e30f, -1.0e30f, -1.0e30f)
};

} // namespace

idAIEventTrace::idAIEventTrace()
    : dir(0.0f, 0.0f, 0.0f)
    , traceQuery{INVALID_CLIP_QUERY}
    , lastTraceFrame(-1)
    , lastTraceResult{} {
    lastTraceResult.fraction = 1.0f;
}

const idBounds& idAIEventTrace::GetBounds() const {
    return eventDecl != nullptr ? eventDecl->bounds : clearedBounds;
}

float idAIEventTrace::GetDistance() const {
    return eventDecl != nullptr ? eventDecl->distance : 0.0f;
}

void idAIEventTrace::InternalDrawDebug(
        const int level, const int, const int duration) {
    const int debugDuration = duration > 0
        ? duration : Tungsten_GetAIEventGameMillisecondsPerFrame();
    const float hitDistance = GetDistance() * lastTraceResult.fraction;
    const idVec3 hitPoint = origin + dir * hitDistance;
    Tungsten_DebugAIEventTracePoint(
        hitPoint, Tungsten_GetAIEventGameMillisecondsPerFrame());
    Tungsten_DebugAIEventTraceLine(origin, hitPoint, debugDuration);

    if (level <= 1) {
        return;
    }

    const idVec3 midpoint = origin + dir * (hitDistance * 0.5f);
    idVec3 gravity = Tungsten_GetAIEventGravity();
    gravity.NormalizeFast();
    if (dir.Dot(gravity) > 0.9999f) {
        gravity.Set(1.0f, 0.0f, 0.0f);
    }

    idMat3 axis;
    axis[0] = dir;
    axis[1] = gravity.Cross(dir);
    axis[1].NormalizeFast();
    axis[2] = axis[0].Cross(axis[1]);
    axis[2].NormalizeFast();
    Tungsten_DebugAIEventTraceBounds(
        GetBounds(), midpoint, axis, debugDuration);
}

bool idAIEventTrace::InternalIsTouching(
        const idEntity* const entity, const int) {
    Tungsten_FinishAIEventTrace(traceQuery, lastTraceResult);

    const int currentFrame = Tungsten_GetAIEventTraceFrame();
    if (lastTraceFrame != currentFrame && dir.LengthSqr() != 0.0f) {
        const int clipMask = eventDecl != nullptr
            ? static_cast<int>(eventDecl->clipMask.bits) : 0;
        const idVec3 end = origin + dir * GetDistance();
        Tungsten_SubmitAIEventTrace(traceQuery,
            origin, end, clipMask, originator.GetSpawnId());
        lastTraceFrame = currentFrame;
    }

    return lastTraceResult.fraction != 1.0f
        && Tungsten_GetAIEventEntityNumber(entity)
            == lastTraceResult.contact.entityNum;
}
