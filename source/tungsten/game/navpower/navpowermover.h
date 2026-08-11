#pragma once

#include "navpowerdata.h"
#include "navtypes.h"

class idDeclNavigation;

enum navRepulsorFlags_t : int {
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

enum navLayerMask_t : int {
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

enum navObstacleFlags_t : int {
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

enum contentsFlags_t : int {
    CONTENTS_SOLID = 0x00000001,
    CONTENTS_MONSTERCLIP = 0x00000010,
    CONTENTS_BREAKABLE = 0x00002000,
    CONTENTS_PLAYER = 0x00008000,
    CONTENTS_VEHICLE = 0x00010000
};

struct idAINavPowerLinks {
    navLinkFlags_t linkUsageFlags;
};

struct idAINavPowerMoverParms {
    struct idAINavPowerMover {
        idAINavPowerMover();

        const idDeclNavigation* navDecl;
        float moverSpeed;
        float moverSpeedWalk;
        float moverSpeedRun;
        float moverSpeedSprint;
        float moverSpeedCreep;
        float moverSpeedStep;
        float moverSpeedCrouchWalk;
        float moverSpeedWater;
        float overSpeedFraction;
        float bulk;
        float cruiseAcceleration;
        float startStopAcceleration;
        float pathAcceleration;
        float backPedalFraction;
        float sidestepFraction;
        float pathSharePenalty;
        float pathSharePenaltyMax;
        float turnSpeed;
        float turnAccelAngle;
        float turnInPlaceWhenMovingAngle;
        float turnInPlaceWhenStoppedAngle;
        bool turnInPlaceUTurn;
        float circleApproachRadius;
        bool circleApproach;
        bool pathProbeStraightFirst;
        bool pathAdditionalSmoothing;
        bool allowDetour;
        bool clientMotionEnabled;
        bool useVelocityToScaleAnimationRate;
        bool ignoreFlippedMovers;
    };

    struct idAINavPowerRepulsor {
        idAINavPowerRepulsor();

        navRepulsorFlags_t repulsorType;
        navRepulsorFlags_t repulsorTypeBlockedBy;
        float repulsorRadius;
        float repulsorInnerCushion;
        float repulsorOuterCushion;
        float repulsorInitialAcceleration;
        float repulsorOuterCushionAcceleration;
        float repulsorInnerCushionAcceleration;
    };

    struct idAINavPowerObstacle {
        idAINavPowerObstacle();

        navObstacleFlags_t obstacleType;
        navObstacleFlags_t obstaclesBlockedBy;
        navLayerMask_t obstacleLayers;
        float obstaclePenaltyMultiplier;
        float obstacleWhenStoppedDelay;
        bool obstacleWhenStopped;
    };

    struct idAINavPowerFlocking {
        idAINavPowerFlocking();

        int flockId;
        float flockAcceleration;
        float flockAccelerationDistance;
    };

    struct idAINavPowerCaution {
        idAINavPowerCaution();

        float cautionTurnDegrees;
        float cautionSpeedFraction;
    };

    struct idAINavPowerJumper {
        idAINavPowerJumper();

        float jumpSpeed;
        float jumpArcFraction;
        float jumpTurnAngle;
        bool onlyToEndPoint;
    };

    struct idAINavPowerProbe {
        idAINavPowerProbe();

        contentsFlags_t probeMask;
        float probeDropHeight;
        float probeInterval;
        bool probeForGround;
    };

    struct idAINavPowerIdle {
        idAINavPowerIdle();

        float idleTetherDistance;
        float idleReturnDelay;
    };

    struct idAINavPowerSurfaces {
        idAINavPowerSurfaces();

        navCustomFlags_t surfacesUsable;
        float surfaceOrientAngle;
        float surfaceOrientSlerpTime;
        bool surfaceOrientUpOnAutoNav;
    };

    struct idAINavPowerFollower {
        idAINavPowerFollower();

        float followStartupSpeedFraction;
        float followStartupBulk;
        float followPadding;
        float formationChangeMinTime;
        float formationChangeMaxTime;
        bool formationChangeEnabled;
    };

    struct idAINavPowerDeath {
        idAINavPowerDeath();

        float deathObstacleLifetime;
        idNpObstacleData deathObstacleParms;
        float deathRepulsorLifetime;
        idNpRepulsorData deathRepulsorParms;
        bool waitForSettle;
        bool trackObjects;
    };

    struct idAINavPowerArrivals {
        idAINavPowerArrivals();

        bool createGoalObstacle;
        idNpObstacleData goalObstacleParms;
        float goalObstacleLifetime;
    };

    idAINavPowerMoverParms();

    idAINavPowerMover mover;
    idAINavPowerRepulsor repulsor;
    idAINavPowerObstacle obstacle;
    idAINavPowerFlocking flocking;
    idAINavPowerCaution caution;
    idAINavPowerLinks links;
    idAINavPowerJumper jump;
    idAINavPowerProbe probe;
    idAINavPowerIdle idle;
    idAINavPowerSurfaces surface;
    idAINavPowerFollower follow;
    idAINavPowerDeath death;
    idAINavPowerArrivals arrival;
};

static_assert(sizeof(idAINavPowerMoverParms::idAINavPowerMover) == 104,
    "Recovered NavPower mover tuning ABI changed");
static_assert(sizeof(idAINavPowerMoverParms::idAINavPowerRepulsor) == 32,
    "Recovered NavPower repulsor tuning ABI changed");
static_assert(sizeof(idAINavPowerMoverParms::idAINavPowerObstacle) == 24,
    "Recovered NavPower obstacle tuning ABI changed");
static_assert(sizeof(idAINavPowerMoverParms::idAINavPowerDeath) == 44,
    "Recovered NavPower death tuning ABI changed");
static_assert(sizeof(idAINavPowerMoverParms) == 328,
    "Recovered aggregate NavPower mover tuning ABI changed");
