#pragma once

#include "game/entities/info.h"
#include "game/navpower/navpowerdata.h"

class idNpObstacle;
class idNpRepulsor;

struct idInfoNavLinkData {
    int linkLayers = idNpLinkData::NAVLAYER_MONSTER32;
    int linkUsageFlags = idNpLinkData::LinkFl_ClassA;
    float linkPenaltyMultiplier = 1.0f;
    float linkMaxSnapDistance = 150.0f;
    float linkMayUseDistance = 8.0f;
    float linkMustUseDistance = 6.0f;
    unsigned char linkMaxUsers = 0;
    bool linkBiDirectional = false;
    bool linkStopToUse = false;
    bool linkIsJump = false;
};

struct idInfoNavObstacleData {
    int obstacleAffects = idNpObstacleData::NavMask_AllLayers;
    float obstaclePenalty = 15.0f;
    int obstacleBlockageFlags = idNpObstacleData::Obstacle_All;
};

struct idInfoNavRepulsorData {
    int repulsorType = idNpRepulsorData::Repulsor_All;
    float repulsorRadius = 16.0f;
    float repulsorInnerCushion = 10.0f;
    float repulsorOuterCushion = 10.0f;
    float repulsorBulk = 1.0f;
};

class idInfoNavServices {
public:
    virtual ~idInfoNavServices() = default;
    virtual int GetGameFlags() const;
    virtual void PostRemove(idEntity& entity, float seconds);
    virtual idNpLink* CreateLink(idEntity& owner,
        const idVec3& startA, const idVec3& startB,
        const idVec3& endA, const idVec3& endB,
        const idInfoNavLinkData& parameters, bool jump);
    virtual void DestroyLink(idNpLink* link);
    virtual void SetLinkEnabled(idNpLink* link, bool enabled);
    virtual bool IsLinkEnabled(const idNpLink* link) const;
    virtual bool TryReserveLink(idNpLink* link,
        idNpLink& reservation, bool force);
    virtual void CheckLinkForErrors(idNpLink* link,
        idList<idStr, 5>& errors) const;
    virtual bool GetTraversalAnimationDelta(const char* animation,
        const char* optionalDestination, const char* fallCycle,
        idVec3& delta, bool& isFallTraversal) const;
    virtual void ValidateFallTraversal(idEntity& owner,
        const idVec3& start, const idVec3& end, int navLayer);
    virtual void DebugLine(const idColor& color,
        const idVec3& start, const idVec3& end, int duration);
    virtual void DebugArrow(const idColor& color,
        const idVec3& start, const idVec3& end, float size,
        int duration);

    virtual idNpObstacle* CreateObstacle(idEntity& owner,
        const idVec3& size, const idInfoNavObstacleData& parameters,
        bool asynchronous);
    virtual void DestroyObstacle(idNpObstacle* obstacle);
    virtual idNpRepulsor* CreateRepulsor(idEntity& owner,
        const idInfoNavRepulsorData& parameters);
    virtual void DestroyRepulsor(idNpRepulsor* repulsor);
    virtual void UpdateRepulsor(idNpRepulsor* repulsor,
        idEntity& owner, bool forceZeroVelocity);
};

class idInfoLinkSegment : public idInfo {
public:
    idInfoLinkSegment();
    ~idInfoLinkSegment() override;

    static void SetServices(idInfoNavServices* services);
    static idInfoNavServices& NavServices();

    void Hide() override;
    void Show() override;
    void Spawn() override;
    void OnActivate(idEntity* activator) override;
    void Think() override;
    void CheckForErrors(idList<idStr, 5>& errors) override;
    bool TryReserveLink(idNpLink& reservation, bool force);
    void Event_EnableLink(bool enable);
    void DebugDrawEntity(const idColor& color, int duration);
    void Event_PostSpawn();

    idStr anim;
    idStr animOptionalDest;
    idStr fallCycle;
    bool disableExits;
    float startWidth;
    idVec3 end0;
    idVec3 end1;
    float cooldown;
    idInfoNavLinkData linkParms;
    bool useExplicitEndPoints;
    idNpLink* navLink;
};

class idInfoNavObstacle : public idInfo {
public:
    idInfoNavObstacle();
    ~idInfoNavObstacle() override;
    void Init(const idNpObstacleData& parameters,
        const idVec3& size, float lifetime);
    void CreateNavObstacle();
    void Spawn() override;
    void OnActivate(idEntity* activator) override;

    idVec3 obstacleSize;
    idInfoNavObstacleData obstacleParms;
    bool startOn;
    idNpObstacle* navObstacle;
    float obstacleLifetime;
};

class idInfoNavInclusionVolume : public idInfo {
public:
    idInfoNavInclusionVolume();
    int layersAffected;
};

class idInfoNavExclusionVolume : public idInfo {
public:
    idInfoNavExclusionVolume();
    idInfoNavObstacleData obstacleParms;
};

class idInfoNavFlightVolume : public idInfo {
public:
    idInfoNavFlightVolume();
    int volumeFlags;
    idInfoNavObstacleData obstacleParms;
};

class idInfoNavRepulsor : public idInfo {
public:
    idInfoNavRepulsor();
    ~idInfoNavRepulsor() override;
    void CreateNavRepulsor();
    void Spawn() override;
    void Think() override;

    idInfoNavRepulsorData repulsorParms;
    idNpRepulsor* navRepulsor;
    float repulsorLifetime;
};

class idInfoNavIslandMarker : public idInfo {
public:
    idInfoNavIslandMarker();
    int navLayerAffected;
};
