#pragma once

#include "presentable.h"

#include <cstdint>

class idDeclLaserGate;
class idMaterial;

#ifndef TUNGSTEN_LASER_GATE_STATE_T_DEFINED
#define TUNGSTEN_LASER_GATE_STATE_T_DEFINED
enum laserGateState_t : int {
    LASERGATE_OPENING = 0,
    LASERGATE_OPENED = 1,
    LASERGATE_CLOSING = 2,
    LASERGATE_CLOSED = 3
};
#endif

#ifndef TUNGSTEN_LASER_GATE_BEAM_INFO_T_DEFINED
#define TUNGSTEN_LASER_GATE_BEAM_INFO_T_DEFINED
struct laserGateBeamInfo_t {
    idVec3 point1;
    idVec3 point2;
};
#endif

struct idRecoveredLaserBeam {
    const idMaterial* material{nullptr};
    float height{0.0f};
};

class idLaserGateBeam;
class idPresentableLaserGate;

class idPresentableLaserGateServices {
public:
    virtual ~idPresentableLaserGateServices() = default;

    virtual int GetScaledGameTime() const { return 0; }
    virtual void GetEntitySpawnTransform(const idEntity*, idVec3& outOrigin,
        idMat3& outAxis) const {
        outOrigin.Set(0.0f, 0.0f, 0.0f);
        outAxis = idMat3(1.0f);
    }
    virtual const idDeclFX* GetFXDeclaration(
        const idDeclLaserGate*) const { return nullptr; }
    virtual const idMaterial* GetBeamMaterial(
        const idDeclLaserGate*) const { return nullptr; }
    virtual float GetBeamHeight(const idDeclLaserGate*) const { return 0.0f; }
    virtual int GetBeamSpacing(const idDeclLaserGate*) const { return 0; }
    virtual int GetBeamPowerUpTime(const idDeclLaserGate*) const { return 1; }
    virtual const idSoundShader* GetPassThroughSound(
        const idDeclLaserGate*) const { return nullptr; }
    virtual void SerializeDeclaration(idSerializer&, const void*&) {}

    virtual bool SuppressEndpointFX(const idEntity*) const { return false; }
    virtual void StartEndpointFX(idPresentableLaserGate*, int, int,
        const idVec3&, const idVec3&) {}
    virtual void StopEndpointFX(idPresentableLaserGate*, int, int) {}
    virtual void RenderBeam(idLaserGateBeam&) {}

    virtual bool PollGather(std::uint64_t) const { return false; }
    virtual std::uint64_t SubmitGather(const idBounds&, int, int) {
        return 0;
    }
};

void Tungsten_SetPresentableLaserGateServices(
    idPresentableLaserGateServices* services);
idPresentableLaserGateServices*
Tungsten_GetPresentableLaserGateServices();

class idLaserGateBeam {
public:
    idLaserGateBeam();

    void UpdateLaserBeams(laserGateState_t parentState,
        unsigned int beamPowerUpTime, int startTime, float maxBeamHeight);

    idRecoveredLaserBeam beam;
    idVec3 point1;
    idVec3 point2;
    laserGateState_t state;
};

class idPresentableLaserGate : public idPresentable {
public:
    idPresentableLaserGate();
    idPresentableLaserGate(idEntity* entity, idRenderModel* renderModel,
        int entityNumber, const idDeclLaserGate* laserGateInfo,
        const idList<laserGateBeamInfo_t, 5>& laserEndPoints,
        const idDeclFX* overrideFXDecl = nullptr);
    ~idPresentableLaserGate() override;

    presentableType_t GetType() const override { return PRESENTABLE_GENERIC; }
    void Serialize(idSerializer& serializer) override;
    void ClientThink(int currentTime, float fraction, bool predict) override;

    void PowerUp();
    void PowerDown();
    void UpdateBeams();
    void EnterDormancy();
    void LeaveDormancy();
    void BuildBeams();
    void SerializeBeams(idSerializer& serializer, bool firstTimeIn);
    void UpdateGateLogic();

    int gateActivationTime;
    int shutdownTime;
    laserGateState_t currentGateState;
    laserGateState_t requestedGateState;
    const idDeclLaserGate* laserGateDecl;
    idList<idLaserGateBeam, 5> laserBeams;
    idList<laserGateBeamInfo_t, 5> laserEndPoints;
    bool collisionLastFrame;
    std::uint64_t gatherQuery;
};
