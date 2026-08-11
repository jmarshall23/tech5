#include "presentableparticleemitter.h"

namespace {

idPresentableParticleEmitterServices defaultParticleServices;
idPresentableParticleEmitterServices* particleServices =
    &defaultParticleServices;

void ClearFade(idFadeHelper& fade) {
    fade.fadeFrom = 0.0f;
    fade.fadeStartTime = 0;
    fade.fadeTo = 0.0f;
    fade.fadeEndTime = 0;
    fade.noStippleFade = false;
}

} // namespace

void Tungsten_SetPresentableParticleEmitterServices(
        idPresentableParticleEmitterServices* services) {
    particleServices = services != nullptr ? services
        : &defaultParticleServices;
}

idPresentableParticleEmitter::idPresentableParticleEmitter()
    : particleSystem(nullptr)
    , fadeIn(0.5f)
    , fadeOut(0.5f)
    , alphaScale(1.0f)
    , smokeSystemRate(1)
    , distributionScale(1.0f, 1.0f, 1.0f)
    , velocity(0.0f, 0.0f, 0.0f)
    , colorv4(1.0f, 1.0f, 1.0f, 1.0f)
    , useGlobalShadows(false)
    , useSmokeSystem(false) {
    ClearFade(fade);
}

idPresentableParticleEmitter::idPresentableParticleEmitter(
        const idDeclParticle* particle, idEntity* entity_,
        idRenderModel* renderModel, int entityNumber_,
        const idDeclFX* fxDecl_)
    : idPresentable(entity_, renderModel, entityNumber_, fxDecl_)
    , particleSystem(particle)
    , fadeIn(0.5f)
    , fadeOut(0.5f)
    , alphaScale(1.0f)
    , smokeSystemRate(1)
    , distributionScale(1.0f, 1.0f, 1.0f)
    , velocity(0.0f, 0.0f, 0.0f)
    , colorv4(1.0f, 1.0f, 1.0f, 1.0f)
    , useGlobalShadows(false)
    , useSmokeSystem(false) {
    ClearFade(fade);
}

void idPresentableParticleEmitter::PostSerializeRead(
        bool firstClientFrame) {
    idPresentable::PostSerializeRead(firstClientFrame);
    if (activated.count != activated.lastCount) {
        activated.lastCount = activated.count;
        TriggerShow();
    }
    if (deactivated.count != deactivated.lastCount) {
        deactivated.lastCount = deactivated.count;
        TriggerHide();
    }
}

void idPresentableParticleEmitter::ClientThink(int currentTime,
        float fraction, bool predict) {
    idPresentable::ClientThink(currentTime, fraction, predict);
    if (fade.fadeEndTime > 0) {
        particleServices->UpdateFade(*this, fade);
    }
    if (!useSmokeSystem) {
        return;
    }
    const int frame = particleServices->GetGameFrame();
    if (smokeSystemRate != 0 && frame % smokeSystemRate != 0) {
        return;
    }
    particleServices->AddSmokeParticles(particleSystem,
        particleServices->GetScaledGameTime(),
        particleServices->GetScaledFrameTime(),
        particleServices->RandomUnitFloat(), origin, axis, velocity, colorv4);
}

void idPresentableParticleEmitter::TriggerShow() {
    activated.count = (activated.count + 1) % 7;
    if (particleServices->IsServer()) {
        return;
    }
    if (model == nullptr) {
        particleServices->WarnMissingRenderModel();
        return;
    }
    if (useSmokeSystem) {
        return;
    }

    Show();
    particleServices->RestartParticleModel(*this,
        particleServices->GetScaledGameTime(), distributionScale,
        idVec3(0.0f, 0.0f, 0.0f), 1.0f / alphaScale);
    if (fadeIn != 0.0f) {
        particleServices->StartFade(*this, fade, 0.0f, 1.0f,
            static_cast<int>(fadeIn * 1000.0f));
    }
    Present();
}

void idPresentableParticleEmitter::TriggerHide() {
    deactivated.count = (deactivated.count + 1) % 7;
    if (particleServices->IsServer() || useSmokeSystem) {
        return;
    }
    if (fadeOut == 0.0f) {
        Hide(true);
    } else {
        particleServices->StartFade(*this, fade, 1.0f, 0.0f,
            static_cast<int>(fadeOut * 1000.0f));
    }
}

void idPresentableParticleEmitter::SetParticle(
        const idDeclParticle* particle) {
    if (particle == nullptr || model == nullptr) {
        return;
    }
    particleServices->WarnParticleError(particle);
    particleSystem = particle;
    ClearFade(fade);
    particleServices->ConfigureParticleModel(*this, particle, colorv4,
        particleServices->GetWind(), particleServices->RandomUnitFloat(),
        particleServices->GetScaledGameTime(), useGlobalShadows,
        distributionScale, velocity, 1.0f / alphaScale);
    Present();
}

void idPresentableParticleEmitter::Serialize(idSerializer& serializer) {
    idPresentable::Serialize(serializer);
    activated.Serialize(serializer);
    deactivated.Serialize(serializer);
    SERIALIZE_BOOL(serializer, useGlobalShadows);
    SERIALIZE_BOOL(serializer, useSmokeSystem);
    serializer.Serialize(fadeIn);
    serializer.Serialize(fadeOut);
    serializer.Serialize(alphaScale);
    serializer.Serialize(distributionScale);
    serializer.SerializeQ<32768, 16>(velocity);
    serializer.Serialize(colorv4);
    serializer.Serialize(smokeSystemRate);
    const void* declaration = particleSystem;
    particleServices->SerializeDeclaration(serializer, declaration);
    const idDeclParticle* serializedParticle =
        static_cast<const idDeclParticle*>(declaration);
    if (particleSystem != serializedParticle) {
        SetParticle(serializedParticle);
    }
}
