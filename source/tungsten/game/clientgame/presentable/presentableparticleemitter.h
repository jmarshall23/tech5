#pragma once

#include "presentable.h"
#include "presentableptr.h"
#include "../../effects/gameeffects.h"

class idDeclParticle;

class idPresentableParticleEmitter;

class idPresentableParticleEmitterServices {
public:
    virtual ~idPresentableParticleEmitterServices() = default;

    virtual bool IsServer() const { return false; }
    virtual int GetGameFrame() const { return 0; }
    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual float RandomUnitFloat() { return 0.0f; }
    virtual idVec3 GetWind() const { return idVec3(0.0f, 0.0f, 0.0f); }
    virtual void UpdateFade(idPresentableParticleEmitter&, idFadeHelper&) {}
    virtual void StartFade(idPresentableParticleEmitter&, idFadeHelper& fade,
        float from, float to, int duration) {
        fade.fadeFrom = from;
        fade.fadeTo = to;
        fade.fadeStartTime = GetScaledGameTime();
        fade.fadeEndTime = fade.fadeStartTime + duration;
        fade.noStippleFade = false;
    }
    virtual void ConfigureParticleModel(idPresentableParticleEmitter&,
        const idDeclParticle*, const idVec4&, const idVec3&, float,
        int, bool, const idVec3&, const idVec3&, float) {}
    virtual void RestartParticleModel(idPresentableParticleEmitter&, int,
        const idVec3&, const idVec3&, float) {}
    virtual void AddSmokeParticles(const idDeclParticle*, int, int, float,
        const idVec3&, const idMat3&, const idVec3&, const idVec4&) {}
    virtual void WarnParticleError(const idDeclParticle*) {}
    virtual void WarnMissingRenderModel() {}
    virtual void SerializeDeclaration(idSerializer&, const void*&) {}
};

void Tungsten_SetPresentableParticleEmitterServices(
    idPresentableParticleEmitterServices* services);

class idPresentableParticleEmitter : public idPresentable {
public:
    idPresentableParticleEmitter();
    idPresentableParticleEmitter(const idDeclParticle* particle,
        idEntity* entity, idRenderModel* renderModel, int entityNumber,
        const idDeclFX* fxDecl);

    void PostSerializeRead(bool firstClientFrame) override;
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void Serialize(idSerializer& serializer) override;
    presentableType_t GetType() const override {
        return PRESENTABLE_PARTICLE_EMITTER;
    }
    idPresentableParticleEmitter* GetParticleEmitterInterface() override {
        return this;
    }

    virtual void TriggerShow();
    virtual void TriggerHide();
    virtual void SetParticle(const idDeclParticle* particle);

    const idDeclParticle* particleSystem;
    netBoolEvent_t activated;
    netBoolEvent_t deactivated;
    idFadeHelper fade;
    float fadeIn;
    float fadeOut;
    float alphaScale;
    int smokeSystemRate;
    idVec3 distributionScale;
    idVec3 velocity;
    idVec4 colorv4;
    bool useGlobalShadows;
    bool useSmokeSystem;
};
