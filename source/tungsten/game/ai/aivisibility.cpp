#include "aivisibility.h"

#include <algorithm>

namespace {

constexpr int kEntityNumberMask = 0x1FFF;
constexpr int kOpaqueVisibilityMask = 0x2003;
constexpr int kBreakableVisibilityMask = 0x0003;

int EntityNumber(const idSpawnId id) {
    return id.value & kEntityNumberMask;
}

bool TraceReachedDestination(const idAIGameState* const gameState,
        const idSpawnId destinationId, const trace_t& trace) {
    if (!destinationId.IsValid()) {
        return false;
    }
    int destinationEntityNumber = EntityNumber(destinationId);
    int masterEntityNumber = kEntityNumberMask;
    if (!Tungsten_GetAIVisibilityDestinationEntities(gameState,
            destinationId, destinationEntityNumber, masterEntityNumber)) {
        return false;
    }
    return trace.c.entityNum == destinationEntityNumber
        || trace.c.entityNum == masterEntityNumber;
}

float NormalizedFovScore(const float dot, const float cosineFov) {
    return dot > cosineFov
        ? (dot - cosineFov) / (1.0f - cosineFov) : 0.0f;
}

} // namespace

const idVec3 idAIVisibility::VEC_Z(0.0f, 0.0f, 1.0f);

// Retail symbol: ?ByteToFOVDot@idAIVisibility@@SAME@Z
// EA: 0x82A60ED8, RVA: 0x00A60ED8
float idAIVisibility::ByteToFOVDot(const std::uint8_t fov) {
    return static_cast<float>(fov) * (2.0f / 255.0f) - 1.0f;
}

// Retail symbol: ?FOVDotToByte@idAIVisibility@@SAEM@Z
// EA: 0x82A60F08, RVA: 0x00A60F08
std::uint8_t idAIVisibility::FOVDotToByte(const float fov) {
    return static_cast<std::uint8_t>((fov + 1.0f) * 127.5f);
}

// Retail symbol:
// ?TraceVisible_Resolve@idAIVisibility@@SA_NPBVidAIGameState@@VidSpawnId@@AAVidClipQuery@@AAUtrace_t@@@Z
// EA: 0x82A60F38, RVA: 0x00A60F38
bool idAIVisibility::TraceVisible_Resolve(
        const idAIGameState* const gameState,
        const idSpawnId destinationId, idClipQuery& query,
        trace_t& trace) {
    if (!Tungsten_FinishAIVisibilityTrace(query, trace)) {
        trace.fraction = 0.0f;
        return false;
    }
    return trace.fraction >= 1.0f
        || TraceReachedDestination(gameState, destinationId, trace);
}

// Retail symbol: ?CheckFOV@idAIVisibility@@SAMABVidVec3@@0M@Z
// EA: 0x82A61038, RVA: 0x00A61038
float idAIVisibility::CheckFOV(const idVec3& direction,
        const idVec3& eyeForward, const float cosineFov) {
    return NormalizedFovScore(direction.Dot(eyeForward), cosineFov);
}

// Retail symbol: ?CheckFOV@idAIVisibility@@SAMABVidVec3@@0MM@Z
// EA: 0x82A61150, RVA: 0x00A61150
float idAIVisibility::CheckFOV(const idVec3& direction,
        const idVec3& eyeForward, const float cosineHorizontalFov,
        const float cosineVerticalFov) {
    // First remove the component perpendicular to the vertical view plane.
    // The executable does not normalize this cross product before removal.
    const idVec3 lateral = eyeForward.Cross(VEC_Z);
    idVec3 verticalDirection = direction
        - lateral * direction.Dot(lateral);
    if (verticalDirection.NormalizeFast() == 0.0f) {
        return 0.0f;
    }
    const float verticalDot = eyeForward.Dot(verticalDirection);
    if (verticalDot < cosineVerticalFov) {
        return 0.0f;
    }

    idVec3 horizontalDirection = direction
        - VEC_Z * direction.Dot(VEC_Z);
    idVec3 horizontalForward = eyeForward
        - VEC_Z * eyeForward.Dot(VEC_Z);
    if (horizontalDirection.NormalizeFast() == 0.0f
        || horizontalForward.NormalizeFast() == 0.0f) {
        return NormalizedFovScore(verticalDot, cosineVerticalFov);
    }
    const float horizontalDot =
        horizontalForward.Dot(horizontalDirection);
    return horizontalDot >= cosineHorizontalFov
        ? NormalizedFovScore(horizontalDot, cosineHorizontalFov)
        : NormalizedFovScore(verticalDot, cosineVerticalFov);
}

// Retail symbol:
// ?TraceVisible@idAIVisibility@@SA_NPBVidAIGameState@@ABVidVec3@@1VidSpawnId@@2AAUtrace_t@@_N@Z
// EA: 0x82A61458, RVA: 0x00A61458
bool idAIVisibility::TraceVisible(const idAIGameState* const gameState,
        const idVec3& fromPoint, const idVec3& toPoint,
        const idSpawnId ignoreId, const idSpawnId destinationId,
        trace_t& trace, const bool seeThroughBreakables) {
    const int clipMask = seeThroughBreakables
        ? kBreakableVisibilityMask : kOpaqueVisibilityMask;
    Tungsten_TraceAIVisibility(trace, fromPoint, toPoint, clipMask,
        EntityNumber(ignoreId));
    const bool visible = trace.fraction >= 1.0f
        || TraceReachedDestination(gameState, destinationId, trace);
    Tungsten_DebugAIVisibilityTrace(
        fromPoint, trace.endpos, destinationId, visible);
    return visible;
}

// Retail symbol:
// ?TraceVisible_Submit@idAIVisibility@@SAXABVidVec3@@0VidSpawnId@@_NAAVidClipQuery@@@Z
// EA: 0x82A616F0, RVA: 0x00A616F0
void idAIVisibility::TraceVisible_Submit(const idVec3& fromPoint,
        const idVec3& toPoint, const idSpawnId ignoreId,
        const bool seeThroughBreakables, idClipQuery& query) {
    const int clipMask = seeThroughBreakables
        ? kBreakableVisibilityMask : kOpaqueVisibilityMask;
    Tungsten_SubmitAIVisibilityTrace(query, fromPoint, toPoint,
        clipMask, EntityNumber(ignoreId));
}
