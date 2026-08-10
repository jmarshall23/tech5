#pragma once

#include "aievent.h"

#include <cstdint>

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery {
    std::uint64_t index;
};
#endif

struct idAIEventTraceContact {
    int type;
    idVec3 point;
    idVec3 normal;
    float distance;
    float separation;
    int contentFlags;
    int surfaceFlags;
    int surfaceType;
    int modelFeature;
    int traceModelFeature;
    int entityNum;
    int physicsId;
    int bodyId;
    int selfId;
    std::uint8_t flags;
    std::uint8_t surfaceColor[3];
};

struct idAIEventTraceResult {
    float fraction;
    idVec3 endPosition;
    idMat3 endAxis;
    idAIEventTraceContact contact;
};

class idAIEventTrace : public idAIEvent {
public:
    idAIEventTrace();
    ~idAIEventTrace() override = default;

    const idBounds& GetBounds() const;
    virtual float GetDistance() const;
    void InternalDrawDebug(int level, int currentTime, int duration) override;
    bool InternalIsTouching(const idEntity* entity, int currentTime) override;

    idVec3 dir;
    idClipQuery traceQuery;
    int lastTraceFrame;
    idAIEventTraceResult lastTraceResult;
};

int Tungsten_GetAIEventTraceFrame();
int Tungsten_GetAIEventGameMillisecondsPerFrame();
int Tungsten_GetAIEventEntityNumber(const idEntity* entity);
bool Tungsten_FinishAIEventTrace(
    idClipQuery& query, idAIEventTraceResult& result);
void Tungsten_SubmitAIEventTrace(idClipQuery& query,
    const idVec3& start, const idVec3& end, int clipMask,
    int originatorSpawnId);
idVec3 Tungsten_GetAIEventGravity();
void Tungsten_DebugAIEventTracePoint(
    const idVec3& point, int duration);
void Tungsten_DebugAIEventTraceLine(
    const idVec3& start, const idVec3& end, int duration);
void Tungsten_DebugAIEventTraceBounds(const idBounds& bounds,
    const idVec3& origin, const idMat3& axis, int duration);

static_assert(sizeof(idAIEventTraceContact) == 76,
    "Recovered AI-event trace contact ABI changed");
static_assert(sizeof(idAIEventTraceResult) == 128,
    "Recovered AI-event trace result ABI changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIEventTrace) == 208,
    "Recovered trace AI-event ABI changed");
#endif
