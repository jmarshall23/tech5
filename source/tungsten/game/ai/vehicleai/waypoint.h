#pragma once

#include "idlib/containers/linklist.h"
#include "idlib/containers/list.h"

class idDeclVoiceOver;
class idDrone;
class idSoundShader;
class idVehicleAI;

class idWaypoint {
public:
    idWaypoint();
    virtual ~idWaypoint() = default;

    void Spawn();

    idLinkList<idWaypoint> waypointNode;
};

class idSplineWaypoint : public idWaypoint {
public:
    idSplineWaypoint();
    ~idSplineWaypoint() override = default;

    void AiReachedWaypoint(idVehicleAI* ai);

    const idDeclVoiceOver* voiceOver;
    int voSeat;
    const idDeclVoiceOver* voiceOver2;
    int voSeat2;
    const idSoundShader* sound;
};

class idDroneSplineWaypoint : public idSplineWaypoint {
public:
    idDroneSplineWaypoint();
    ~idDroneSplineWaypoint() override = default;

    float ScheduleDrone(idDrone* drone, float eta);

    idList<const idDrone*, 5> imminentArrivals;
    idList<int, 5> imminentEta;
};

idLinkList<idWaypoint>& Tungsten_GetWaypointListHead();
void Tungsten_ApplySplineWaypointControlAndActions(
    idVehicleAI& ai, const idSplineWaypoint& waypoint);
void Tungsten_PlaySplineWaypointVoiceOver(idVehicleAI& ai,
    const idDeclVoiceOver& voiceOver, int seat);
void Tungsten_PlaySplineWaypointSoundForPlayer(idVehicleAI& ai,
    const idSoundShader& sound);
int Tungsten_GetWaypointGameMilliseconds();
