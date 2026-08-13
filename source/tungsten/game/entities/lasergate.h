#pragma once

#include "game/clientgame/presentable/presentablelasergate.h"
#include "game/entities/entity.h"

class idDeclFX;
class idDeclLaserGate;
class idLaserGate;

class idLaserGateServices {
public:
    virtual ~idLaserGateServices() = default;
    virtual bool IsDeclarationValid(const idDeclLaserGate* declaration) const;
    virtual void ReportBadData(const idLaserGate& gate);
    virtual void UpdateGateSound(idLaserGate& gate,
        const idVec3& origin, const idVec3& velocity);
    virtual void PlayPowerSound(idLaserGate& gate, bool poweringUp);
    virtual void SetEndpointFX(idLaserGate& gate,
        int beamIndex, bool enabled);
    virtual bool IsBindMasterStationary(const idEntity* master) const;
};

class idLaserGate : public idEntity {
public:
    idLaserGate();
    ~idLaserGate() override;

    static void SetServices(idLaserGateServices* services);
    static idLaserGateServices& LaserServices();

    idPresentable* AllocPresentable(idRenderModel* model) override;
    void Spawn() override;
    void DormantBegin() override;
    void DormantEnd(int timeDormant) override;
    void UpdateModelTransform() override;
    void Event_PowerUpLasers();
    void Event_ShutDownLasers();
    void OnActivate(idEntity* activator) override;
    void Think() override;

    idList<laserGateBeamInfo_t, 5> laserEndPoints;
    const idDeclLaserGate* laserGateInfo;
    const idDeclFX* overrideFXDecl;
    laserGateState_t gateState;
    idBounds gateBounds;
    bool startsOn;
    bool moveable;
    bool firstThink;
};
