#pragma once

#include "aas2file/aas2file.h"

class idBounds;
class idEntity;
class idPhysics;

struct vaiObstacle_t {
    idEntity* ent;
    int sideFlags;
    float collisionDistance;
    float speed;
    float fwdDistance;
    float rtDistance;
    float radius;
    float fwdRadius;
    float rtRadius;
};

class idAASObstacle {
public:
    idAASObstacle();

    void Spawn();
    virtual void OnActivate(idEntity* activator);

    // PDB member order. The idEntity base is intentionally held at the
    // integration seam until game/entities/entity.h is normalized.
    bool startOn;
    bool dynamicObstacle;
    aas2TravelFlag_t travelFlags;
    bool enabled;

private:
    void ChangeAreaState();
};

struct idAAS2Obstacle {
    // The authoritative layout uses two idBounds members. Keep this type
    // forward-only until the AAS2 obstacle manager translation unit needs it.
};

using aas2ObstaclePVS_t = unsigned char;

// Runtime ownership seams. These retain the calls made by the retail source
// without importing the still-raw idEntity and idGameLocal declarations.
idPhysics* Tungsten_GetAASObstaclePhysics(const idAASObstacle& obstacle);
const idBounds* Tungsten_GetAASObstacleAbsBounds(
    idPhysics& physics, int clipModelId);
int Tungsten_GetAASObstacleContents(idPhysics& physics, int clipModelId);
void Tungsten_SetAASObstacleContents(
    idPhysics& physics, int contents, int clipModelId);
void Tungsten_LinkAASObstacleClip(idPhysics& physics);
void Tungsten_UnlinkAASObstacleClip(idPhysics& physics);
void Tungsten_ChangeAASObstacleAreaTravelFlags(
    const idBounds& bounds, int areaFlags, int travelFlags, bool set);
