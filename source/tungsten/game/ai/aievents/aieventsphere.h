#pragma once

#include "aievent.h"
#include "../../../../shared/idlib/color.h"

class idAIEventSphere : public idAIEvent {
public:
    idAIEventSphere();
    ~idAIEventSphere() override = default;

    float GetRadius() const;
    virtual const idColor& GetColor() const;
    void InternalDrawDebug(int level, int currentTime, int duration) override;

    static idColor defaultColor;
};

class idAIEventProjectedSphere : public idAIEventSphere {
public:
    idAIEventProjectedSphere();
    ~idAIEventProjectedSphere() override = default;

    void Clear() override;
    bool InternalIsTouching(const idEntity* entity, int currentTime) override;
    aiEventUpdateResult_t InternalUpdateAttached(int currentTime) override;

    bool hasProjection;
    idVec3 projectedOrigin;
    idVec3 curSimPos;
    idVec3 curSimVel;
    idVec3 traceFrom;
    int bounces;
    int horizontalBounces;
};

struct idAIEventProjectionTrace {
    idVec3 endPosition;
    idVec3 normal;
};

int Tungsten_GetAIEventGameMilliseconds();
int Tungsten_GetAIEventGameMillisecondsPerFrame();
bool Tungsten_IsAIEventPlayerSpawnId(int spawnId);
bool Tungsten_GetAIEventEntityWorldOrigin(
    const idEntity* entity, idVec3& origin);
bool Tungsten_GetAIEventEntityLinearVelocity(
    int spawnId, idVec3& velocity);
bool Tungsten_TraceAIEventProjection(const idVec3& start,
    const idVec3& end, idAIEventProjectionTrace& trace);
void Tungsten_DebugAIEventPoint(const idColor& color,
    const idVec3& point, int duration, bool depthTest);
void Tungsten_DebugAIEventSphere(const idColor& color,
    const idVec3& origin, float radius, int segments,
    int duration, bool depthTest);
void Tungsten_DebugAIEventTrajectory(const idVec3& start,
    const idVec3& end, int kind, int duration);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIEventSphere) == 52,
    "Recovered spherical AI-event ABI changed");
static_assert(sizeof(idAIEventProjectedSphere) == 112,
    "Recovered projected-sphere AI-event ABI changed");
#endif
