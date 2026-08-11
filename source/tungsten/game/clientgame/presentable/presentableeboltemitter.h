#pragma once

#include "presentable.h"

class idDeclElectricBolt;
class idElectricBolt;

class idPresentableEBoltEmitter;

class idPresentableEBoltEmitterServices {
public:
    virtual ~idPresentableEBoltEmitterServices() = default;
    virtual bool IsServer() const { return false; }
    virtual bool IsClient() const { return true; }
    virtual int GetScaledGameTime() const { return 0; }
    virtual int RandomIndex(int count) { return count > 0 ? 0 : -1; }
    virtual int RandomRange(int minimum, int) { return minimum; }
    virtual float RandomUnitFloat() { return 0.0f; }
    virtual bool ResolveTargetPosition(std::uint32_t, idVec3&) const {
        return false;
    }
    virtual idElectricBolt* CreateElectricBolt(
        const idDeclElectricBolt*) { return nullptr; }
    virtual void DeleteElectricBolt(idElectricBolt*) {}
    virtual void StartElectricBolt(idElectricBolt*, int, const idVec3&,
        const idVec3&, float) {}
    virtual void UpdateElectricBolt(idElectricBolt*, int) {}
    virtual void SerializeDeclaration(idSerializer&, const void*&) {}
};

void Tungsten_SetPresentableEBoltEmitterServices(
    idPresentableEBoltEmitterServices* services);

class idPresentableEBoltEmitter : public idPresentable {
public:
    idPresentableEBoltEmitter();
    idPresentableEBoltEmitter(idEntity* entity, idRenderModel* renderModel,
        int minimumResetTime, int maximumResetTime, bool startsOff,
        const idDeclElectricBolt* boltSystem,
        const idSoundShader* powerDownSound,
        const idSoundShader* powerUpSound, float maximumConeAngle,
        const idVec2& boltLength,
        const idList<std::uint32_t, 5>& targetSpawnIds);
    ~idPresentableEBoltEmitter() override;

    void Serialize(idSerializer& serializer) override;
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void ResetTarget();

    int minResetTime;
    int maxResetTime;
    const idDeclElectricBolt* electricBoltSystem;
    const idSoundShader* sndPowerDown;
    const idSoundShader* sndPowerUp;
    float maxConeAngle;
    idVec2 length;
    idElectricBolt* ebolt;
    idList<idVec3, 5> targetPoints;
    idList<std::uint32_t, 5> targets;
    int nextResetTime;
    bool startOff;
    bool firstSerialize;
};

