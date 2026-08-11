#pragma once

#include "../../../engine/gamelib/effects/weapontracemanager.h"

struct idNpObstacleData {
    enum navMask_t : int {
        NavMask_None = 0,
        NavMask_Player = 1,
        NavMask_Monster16 = 2,
        NavMask_Monster32 = 4,
        NavMask_Monster48 = 8,
        NavMask_Monster96 = 16,
        NavMask_Monster128 = 32,
        NavMask_MonsterFlight = 64,
        NavMask_AllLayers = -1
    };
    enum obstacleFlags_t : int {
        Obstacle_None = 0,
        Obstacle_Tick = 1,
        Obstacle_Humanoid = 2,
        Obstacle_Imp = 4,
        Obstacle_Succubus = 8,
        Obstacle_Hellknight = 16,
        Obstacle_Melee = 32,
        Obstacle_Flight = 64,
        Obstacle_Special_1 = 128,
        Obstacle_Special_2 = 256,
        Obstacle_Special_3 = 512,
        Obstacle_Special_4 = 1024,
        Obstacle_All = 0xFFFF
    };

    idNpObstacleData();

    navMask_t obstacleAffects;
    float obstaclePenalty;
    obstacleFlags_t obstacleBlockageFlags;
};

struct idNpLinkData {
    enum navLayer_t : int {
        NAVLAYER_PLAYER = 0,
        NAVLAYER_MONSTER16 = 1,
        NAVLAYER_MONSTER32 = 2,
        NAVLAYER_MONSTER48 = 3,
        NAVLAYER_MONSTER96 = 4,
        NAVLAYER_MONSTER128 = 5,
        NAVLAYER_FLIGHT = 6,
        NAVLAYER_NONE = 7,
        NAVLAYER_MAX = 8
    };
    enum navLinkFlags_t : int {
        LinkFl_None = 0,
        LinkFl_ClassA = 1,
        LinkFl_ClassB = 2,
        LinkFl_ClassC = 4,
        LinkFl_ClassD = 8,
        LinkFl_ClassE = 16,
        LinkFl_TeleportA = 32,
        LinkFl_Melee = 64
    };

    idNpLinkData();

    navLayer_t linkLayers;
    navLinkFlags_t linkUsageFlags;
    float linkPenaltyMultiplier;
    float linkMaxSnapDistance;
    float linkMayUseDistance;
    float linkMustUseDistance;
    unsigned char linkMaxUsers;
    bool linkBiDirectional;
    bool linkStopToUse;
    bool linkIsJump;
};

struct idNpRepulsorData {
    enum repulsorType_t : int {
        Repulsor_None = 0,
        Repulsor_Player = 1,
        Repulsor_Tick = 2,
        Repulsor_Humanoid = 4,
        Repulsor_Imp = 8,
        Repulsor_Succubus = 16,
        Repulsor_Hellknight = 32,
        Repulsor_Pinky = 64,
        Repulsor_All = -1
    };

    idNpRepulsorData();

    repulsorType_t repulsorType;
    float repulsorRadius;
    float repulsorInnerCushion;
    float repulsorOuterCushion;
    float repulsorBulk;
};

class idNpLinkImpl;

class idNpLink {
public:
    idNpLink();

    idNpLinkImpl* impl;
    bool autoDeleteLink;
};

struct idNpLinkInfo {
    struct entityRef_t {
        idSpawnId spawnId;
    };

    idNpLinkInfo();

    entityRef_t linkEntityStart;
    entityRef_t linkEntityEnd;
    bool linkEnabled;
    idNpLinkData linkData;
};

static_assert(sizeof(idNpObstacleData) == 12,
    "Recovered NavPower obstacle parameters ABI changed");
static_assert(sizeof(idNpLinkData) == 28,
    "Recovered NavPower link parameters ABI changed");
static_assert(sizeof(idNpRepulsorData) == 20,
    "Recovered NavPower repulsor parameters ABI changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idNpLink) == 8,
    "Recovered NavPower link owner ABI changed");
static_assert(sizeof(idNpLinkInfo) == 40,
    "Recovered NavPower link information ABI changed");
#endif
