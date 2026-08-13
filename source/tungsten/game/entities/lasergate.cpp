#include "game/entities/lasergate.h"

#include <algorithm>

namespace {
idLaserGateServices defaultLaserGateEntityServices;
idLaserGateServices* laserGateEntityServices =
    &defaultLaserGateEntityServices;

void ClearBounds(idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
}
void AddPoint(idBounds& bounds, const idVec3& point) {
    bounds[0].x = (std::min)(bounds[0].x, point.x);
    bounds[0].y = (std::min)(bounds[0].y, point.y);
    bounds[0].z = (std::min)(bounds[0].z, point.z);
    bounds[1].x = (std::max)(bounds[1].x, point.x);
    bounds[1].y = (std::max)(bounds[1].y, point.y);
    bounds[1].z = (std::max)(bounds[1].z, point.z);
}
idBounds TranslateBounds(const idBounds& bounds, const idVec3& origin) {
    idBounds result;
    result[0] = bounds[0] + origin;
    result[1] = bounds[1] + origin;
    return result;
}
idPresentableLaserGate* EnsurePresentable(idLaserGate& gate) {
    if (gate.presentable == nullptr) gate.InitPresentableInternal();
    return static_cast<idPresentableLaserGate*>(gate.presentable);
}
}

bool idLaserGateServices::IsDeclarationValid(
        const idDeclLaserGate* declaration) const {
    return declaration != nullptr;
}
void idLaserGateServices::ReportBadData(const idLaserGate&) {}
void idLaserGateServices::UpdateGateSound(
        idLaserGate&, const idVec3&, const idVec3&) {}
void idLaserGateServices::PlayPowerSound(idLaserGate&, bool) {}
void idLaserGateServices::SetEndpointFX(idLaserGate&, int, bool) {}
bool idLaserGateServices::IsBindMasterStationary(
        const idEntity* master) const {
    return master == nullptr || (master->linearVelocity.x == 0.0f
        && master->linearVelocity.y == 0.0f
        && master->linearVelocity.z == 0.0f);
}

void idLaserGate::SetServices(idLaserGateServices* services) {
    laserGateEntityServices = services != nullptr
        ? services : &defaultLaserGateEntityServices;
}
idLaserGateServices& idLaserGate::LaserServices() {
    return *laserGateEntityServices;
}

// Retail: 0x82C685C0
idLaserGate::idLaserGate()
    : laserGateInfo(nullptr), overrideFXDecl(nullptr),
      gateState(LASERGATE_OPENED), startsOn(true), moveable(false),
      firstThink(true) {
    gateBounds[0].Set(0.0f, 0.0f, 0.0f);
    gateBounds[1].Set(0.0f, 0.0f, 0.0f);
}

// Retail: 0x82C68698
idLaserGate::~idLaserGate() { laserEndPoints.Clear(); }

// Retail: 0x82C67EA0
idPresentable* idLaserGate::AllocPresentable(idRenderModel* model) {
    return new idPresentableLaserGate(this, model, entityNumber,
        laserGateInfo, laserEndPoints, overrideFXDecl);
}

// Retail: 0x82C67F48
void idLaserGate::Spawn() {
    if (!LaserServices().IsDeclarationValid(laserGateInfo)
            || laserEndPoints.Num() == 0) {
        LaserServices().ReportBadData(*this);
        return;
    }
    BecomeActive(1);
    clipMask = 0;
    contents = 0;
    ClearBounds(gateBounds);
    for (int index = 0; index < laserEndPoints.Num(); ++index) {
        AddPoint(gateBounds, laserEndPoints[index].point1);
        AddPoint(gateBounds, laserEndPoints[index].point2);
    }
    const idBounds worldBounds = TranslateBounds(gateBounds, origin);
    UpdatePVSAreas(worldBounds);
    const idVec3 center = (worldBounds[0] + worldBounds[1]) * 0.5f;
    LaserServices().UpdateGateSound(*this, center, linearVelocity);
}

// Retail: 0x82C681B8
void idLaserGate::DormantBegin() {
    idPresentableLaserGate* gate = EnsurePresentable(*this);
    if (gate != nullptr) gate->EnterDormancy();
}

// Retail: 0x82C68200
void idLaserGate::DormantEnd(int) {
    idPresentableLaserGate* gate = EnsurePresentable(*this);
    if (gate != nullptr) gate->LeaveDormancy();
}

// Retail: 0x82C68248
void idLaserGate::UpdateModelTransform() {
    if (moveable) {
        idPresentableLaserGate* gate = EnsurePresentable(*this);
        if (gate != nullptr) gate->UpdateBeams();
    }
    idEntity::UpdateModelTransform();
}

// Retail: 0x82C682A0
void idLaserGate::Event_PowerUpLasers() {
    idPresentableLaserGate* gate = EnsurePresentable(*this);
    if (gate != nullptr) gate->PowerUp();
    gateState = LASERGATE_CLOSING;
    LaserServices().PlayPowerSound(*this, true);
    const int beamCount = (std::min)(7, laserEndPoints.Num());
    for (int beamIndex = 0; beamIndex < beamCount; ++beamIndex) {
        LaserServices().SetEndpointFX(*this, beamIndex, true);
    }
}

// Retail: 0x82C68438
void idLaserGate::Event_ShutDownLasers() {
    idPresentableLaserGate* gate = EnsurePresentable(*this);
    if (gate != nullptr) gate->PowerDown();
    gateState = LASERGATE_OPENING;
    LaserServices().PlayPowerSound(*this, false);
    const int beamCount = (std::min)(7, laserEndPoints.Num());
    for (int beamIndex = 0; beamIndex < beamCount; ++beamIndex) {
        LaserServices().SetEndpointFX(*this, beamIndex, false);
    }
}

// Retail: 0x82C68718
void idLaserGate::OnActivate(idEntity*) {
    if (gateState == LASERGATE_CLOSING
            || gateState == LASERGATE_CLOSED) {
        Event_ShutDownLasers();
    } else {
        Event_PowerUpLasers();
    }
}

// Retail: 0x82C687D8
void idLaserGate::Think() {
    if (UpdateDormant()) return;
    RunPhysics();
    UpdateFX();
    const idBounds worldBounds = TranslateBounds(gateBounds, origin);
    if (moveable) UpdatePVSAreas(worldBounds);
    if (firstThink) {
        firstThink = false;
        if (startsOn) Event_PowerUpLasers();
        else Event_ShutDownLasers();
    }
    idPresentableLaserGate* gate = EnsurePresentable(*this);
    if (moveable) {
        const idVec3 center = (worldBounds[0] + worldBounds[1]) * 0.5f;
        LaserServices().UpdateGateSound(*this, center, linearVelocity);
        if (bindMaster != nullptr
                && LaserServices().IsBindMasterStationary(bindMaster)
                && gate != nullptr) {
            gate->UpdateBeams();
        }
    }
    if (gate != nullptr) {
        gate->UpdateGateLogic();
        gateState = gate->currentGateState;
    }
}
