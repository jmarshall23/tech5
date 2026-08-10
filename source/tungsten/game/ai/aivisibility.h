#pragma once

#include "gamelib/effects/weapontracemanager.h"
#include "cm/jobs/collisionresults.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idAIGameState;

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery {
    std::uint64_t index;
};
#endif

class idAIVisibility {
public:
    static float ByteToFOVDot(std::uint8_t fov);
    static std::uint8_t FOVDotToByte(float fov);
    static float CheckFOV(const idVec3& direction,
        const idVec3& eyeForward, float cosineFov);
    static float CheckFOV(const idVec3& direction,
        const idVec3& eyeForward, float cosineHorizontalFov,
        float cosineVerticalFov);

    static bool TraceVisible_Resolve(const idAIGameState* gameState,
        idSpawnId destinationId, idClipQuery& query, trace_t& trace);
    static bool TraceVisible(const idAIGameState* gameState,
        const idVec3& fromPoint, const idVec3& toPoint,
        idSpawnId ignoreId, idSpawnId destinationId, trace_t& trace,
        bool seeThroughBreakables);
    static void TraceVisible_Submit(const idVec3& fromPoint,
        const idVec3& toPoint, idSpawnId ignoreId,
        bool seeThroughBreakables, idClipQuery& query);

    static const idVec3 VEC_Z;
};

bool Tungsten_FinishAIVisibilityTrace(
    idClipQuery& query, trace_t& trace);
void Tungsten_TraceAIVisibility(trace_t& trace,
    const idVec3& fromPoint, const idVec3& toPoint, int clipMask,
    int ignoredEntityNumber);
void Tungsten_SubmitAIVisibilityTrace(idClipQuery& query,
    const idVec3& fromPoint, const idVec3& toPoint, int clipMask,
    int ignoredEntityNumber);
bool Tungsten_GetAIVisibilityDestinationEntities(
    const idAIGameState* gameState, idSpawnId destinationId,
    int& destinationEntityNumber, int& masterEntityNumber);
void Tungsten_DebugAIVisibilityTrace(const idVec3& fromPoint,
    const idVec3& endPoint, idSpawnId destinationId, bool visible);
