#include "game/entities/infonav.h"

namespace {
idInfoNavServices defaultNavServices;
idInfoNavServices* navServices = &defaultNavServices;

idVec3 Add(const idVec3& a, const idVec3& b) {
    return idVec3(a.x + b.x, a.y + b.y, a.z + b.z);
}
idVec3 Scale(const idVec3& value, float scale) {
    return idVec3(value.x * scale, value.y * scale, value.z * scale);
}
}

int idInfoNavServices::GetGameFlags() const { return 0; }
void idInfoNavServices::PostRemove(idEntity&, float) {}
idNpLink* idInfoNavServices::CreateLink(idEntity&, const idVec3&,
        const idVec3&, const idVec3&, const idVec3&,
        const idInfoNavLinkData&, bool) { return nullptr; }
void idInfoNavServices::DestroyLink(idNpLink*) {}
void idInfoNavServices::SetLinkEnabled(idNpLink*, bool) {}
bool idInfoNavServices::IsLinkEnabled(const idNpLink*) const {
    return false;
}
bool idInfoNavServices::TryReserveLink(
        idNpLink*, idNpLink&, bool) { return false; }
void idInfoNavServices::CheckLinkForErrors(
        idNpLink*, idList<idStr, 5>&) const {}
bool idInfoNavServices::GetTraversalAnimationDelta(const char*,
        const char*, const char*, idVec3&, bool&) const { return false; }
void idInfoNavServices::ValidateFallTraversal(
        idEntity&, const idVec3&, const idVec3&, int) {}
void idInfoNavServices::DebugLine(const idColor&, const idVec3&,
        const idVec3&, int) {}
void idInfoNavServices::DebugArrow(const idColor&, const idVec3&,
        const idVec3&, float, int) {}
idNpObstacle* idInfoNavServices::CreateObstacle(idEntity&,
        const idVec3&, const idInfoNavObstacleData&, bool) {
    return nullptr;
}
void idInfoNavServices::DestroyObstacle(idNpObstacle*) {}
idNpRepulsor* idInfoNavServices::CreateRepulsor(idEntity&,
        const idInfoNavRepulsorData&) { return nullptr; }
void idInfoNavServices::DestroyRepulsor(idNpRepulsor*) {}
void idInfoNavServices::UpdateRepulsor(
        idNpRepulsor*, idEntity&, bool) {}

void idInfoLinkSegment::SetServices(idInfoNavServices* services) {
    navServices = services != nullptr ? services : &defaultNavServices;
}
idInfoNavServices& idInfoLinkSegment::NavServices() {
    return *navServices;
}

// Retail: 0x82C665B8
idInfoLinkSegment::idInfoLinkSegment()
    : disableExits(false), startWidth(64.0f),
      end0(64.0f, -32.0f, 0.0f), end1(64.0f, 32.0f, 0.0f),
      cooldown(0.0f), useExplicitEndPoints(false), navLink(nullptr) {}

// Retail: 0x82C67038
idInfoLinkSegment::~idInfoLinkSegment() {
    if (navLink != nullptr) {
        NavServices().DestroyLink(navLink);
        navLink = nullptr;
    }
}

// Retail: 0x82C66480
void idInfoLinkSegment::Hide() {
    if (navLink != nullptr) NavServices().SetLinkEnabled(navLink, false);
}

// Retail: 0x82C66498
void idInfoLinkSegment::Show() {
    if (navLink != nullptr) NavServices().SetLinkEnabled(navLink, true);
}

// Retail: 0x82C664B0
void idInfoLinkSegment::Spawn() { Event_PostSpawn(); }

// Retail: 0x82C664C0
void idInfoLinkSegment::OnActivate(idEntity*) {
    if (navLink != nullptr) {
        NavServices().SetLinkEnabled(navLink,
            !NavServices().IsLinkEnabled(navLink));
    }
}

// Retail: 0x82C66510
void idInfoLinkSegment::Think() { (void)NavServices().GetGameFlags(); }

// Retail: 0x82C66528
void idInfoLinkSegment::CheckForErrors(idList<idStr, 5>& errors) {
    idEntity::CheckForErrors(errors);
    if (navLink != nullptr) {
        NavServices().CheckLinkForErrors(navLink, errors);
    }
}

// Retail: 0x82C66578
bool idInfoLinkSegment::TryReserveLink(
        idNpLink& reservation, const bool force) {
    return navLink != nullptr
        && NavServices().TryReserveLink(navLink, reservation, force);
}

// Retail: 0x82C66750
void idInfoLinkSegment::Event_EnableLink(const bool enable) {
    if (navLink != nullptr) NavServices().SetLinkEnabled(navLink, enable);
}

// Retail: 0x82C66790
void idInfoLinkSegment::DebugDrawEntity(
        const idColor& color, const int duration) {
    const idVec3 worldEnd0 = Add(origin, axis * end0);
    const idVec3 worldEnd1 = Add(origin, axis * end1);
    if (startWidth == 0.0f) {
        NavServices().DebugArrow(color, origin, worldEnd0, 4.0f, duration);
        if (linkParms.linkBiDirectional) {
            NavServices().DebugArrow(color, worldEnd0, origin,
                4.0f, duration);
        }
        return;
    }
    const idVec3 startA = Add(origin, Scale(axis[1], -startWidth * 0.5f));
    const idVec3 startB = Add(origin, Scale(axis[1], startWidth * 0.5f));
    NavServices().DebugLine(color, startA, startB, duration);
    NavServices().DebugLine(color, worldEnd0, worldEnd1, duration);
    NavServices().DebugArrow(color, startA, worldEnd0, 4.0f, duration);
    NavServices().DebugArrow(color, startB, worldEnd1, 4.0f, duration);
    if (linkParms.linkBiDirectional) {
        NavServices().DebugArrow(color, worldEnd0, startA, 4.0f, duration);
        NavServices().DebugArrow(color, worldEnd1, startB, 4.0f, duration);
    }
}

// Retail: 0x82C67160
void idInfoLinkSegment::Event_PostSpawn() {
    if ((NavServices().GetGameFlags() & 2) != 0) return;
    idVec3 destinationA = Add(origin, axis * end0);
    idVec3 destinationB = Add(origin, axis * end1);
    bool fallTraversal = false;
    if (!useExplicitEndPoints && !anim.IsEmpty()) {
        idVec3 delta;
        if (NavServices().GetTraversalAnimationDelta(anim.c_str(),
                animOptionalDest.c_str(), fallCycle.c_str(), delta,
                fallTraversal)) {
            destinationA = Add(origin, axis * delta);
            destinationB = destinationA;
        }
    }
    if (fallTraversal) {
        NavServices().ValidateFallTraversal(*this, origin, destinationA,
            linkParms.linkLayers);
    }
    idVec3 startA = origin;
    idVec3 startB = origin;
    if (startWidth != 0.0f) {
        startA = Add(origin, Scale(axis[1], -startWidth * 0.5f));
        startB = Add(origin, Scale(axis[1], startWidth * 0.5f));
    }
    navLink = NavServices().CreateLink(*this, startA, startB,
        destinationA, destinationB, linkParms, linkParms.linkIsJump);
    if (navLink != nullptr) {
        NavServices().SetLinkEnabled(navLink, !flags.hidden);
    }
}

// Retail: 0x82C66AC0
idInfoNavObstacle::idInfoNavObstacle()
    : obstacleSize(32.0f, 32.0f, 32.0f), startOn(true),
      navObstacle(nullptr), obstacleLifetime(0.0f) {}

// Retail: 0x82C67A30
idInfoNavObstacle::~idInfoNavObstacle() {
    if (navObstacle != nullptr) {
        idInfoLinkSegment::NavServices().DestroyObstacle(navObstacle);
        navObstacle = nullptr;
    }
}

// Retail: 0x82C66B78
void idInfoNavObstacle::Init(const idNpObstacleData& parameters,
        const idVec3& size, const float lifetime) {
    obstacleParms.obstacleAffects = parameters.obstacleAffects;
    obstacleParms.obstaclePenalty = parameters.obstaclePenalty;
    obstacleParms.obstacleBlockageFlags =
        parameters.obstacleBlockageFlags;
    obstacleSize = size;
    obstacleLifetime = lifetime;
    if (navObstacle != nullptr) {
        idInfoLinkSegment::NavServices().DestroyObstacle(navObstacle);
        navObstacle = nullptr;
    }
}

// Retail: 0x82C66C20
void idInfoNavObstacle::CreateNavObstacle() {
    navObstacle = idInfoLinkSegment::NavServices().CreateObstacle(
        *this, obstacleSize, obstacleParms, true);
    if (obstacleLifetime != 0.0f) {
        idInfoLinkSegment::NavServices().PostRemove(*this,
            obstacleLifetime);
    }
}

// Retail: 0x82C67AB8
void idInfoNavObstacle::Spawn() {
    if (startOn) CreateNavObstacle();
}

// Retail: 0x82C67AD0
void idInfoNavObstacle::OnActivate(idEntity*) {
    if (navObstacle != nullptr) {
        idInfoLinkSegment::NavServices().DestroyObstacle(navObstacle);
        navObstacle = nullptr;
    } else {
        CreateNavObstacle();
    }
}

// Retail: 0x82C66CF8
idInfoNavInclusionVolume::idInfoNavInclusionVolume()
    : layersAffected(idNpObstacleData::NavMask_AllLayers) {}

// Retail: 0x82C66D48
idInfoNavExclusionVolume::idInfoNavExclusionVolume() {
    obstacleParms.obstacleBlockageFlags = idNpObstacleData::Obstacle_None;
}

// Retail: 0x82C66DD8
idInfoNavFlightVolume::idInfoNavFlightVolume() : volumeFlags(0) {
    obstacleParms.obstacleAffects = idNpObstacleData::NavMask_MonsterFlight
        | idNpObstacleData::NavMask_Monster96;
    obstacleParms.obstacleBlockageFlags = idNpObstacleData::Obstacle_Flight;
    obstacleParms.obstaclePenalty = 0.0f;
}

// Retail: 0x82C66E80
idInfoNavRepulsor::idInfoNavRepulsor()
    : navRepulsor(nullptr), repulsorLifetime(0.0f) {}

// Retail: 0x82C67C80
idInfoNavRepulsor::~idInfoNavRepulsor() {
    if (navRepulsor != nullptr) {
        idInfoLinkSegment::NavServices().DestroyRepulsor(navRepulsor);
        navRepulsor = nullptr;
    }
}

// Retail: 0x82C66F18
void idInfoNavRepulsor::CreateNavRepulsor() {
    if (repulsorLifetime == 0.0f) return;
    navRepulsor = idInfoLinkSegment::NavServices().CreateRepulsor(
        *this, repulsorParms);
    idInfoLinkSegment::NavServices().PostRemove(*this, repulsorLifetime);
}

// Retail: 0x82C67D08
void idInfoNavRepulsor::Spawn() { CreateNavRepulsor(); }

// Retail: 0x82C66590
void idInfoNavRepulsor::Think() {
    if (navRepulsor != nullptr) {
        idInfoLinkSegment::NavServices().UpdateRepulsor(
            navRepulsor, *this, false);
    }
}

// Retail: 0x82C66FE8
idInfoNavIslandMarker::idInfoNavIslandMarker()
    : navLayerAffected(idNpLinkData::NAVLAYER_NONE) {}
