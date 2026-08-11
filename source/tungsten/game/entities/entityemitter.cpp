#include "game/entities/entityemitter.h"

#include <algorithm>
#include <cmath>

namespace {
idEntityEmitterServices defaultEmitterServices;
idEntityEmitterServices* emitterServices = &defaultEmitterServices;

float Clamp(const float value, const float minimum, const float maximum) {
    return (std::max)(minimum, (std::min)(value, maximum));
}

idVec3 Normalized(idVec3 vector) {
    vector.NormalizeFast();
    return vector;
}

idVec3 RotateAroundAxis(const idVec3& vector, const idVec3& axis,
        const float radians) {
    const float cosine = std::cos(radians);
    const float sine = std::sin(radians);
    return vector * cosine + axis.Cross(vector) * sine
        + axis * (axis.Dot(vector) * (1.0f - cosine));
}

void RotateBasis(idMat3& basis, idVec3 rotationAxis,
        const float degrees) {
    if (rotationAxis.NormalizeFast() <= 1.0e-6f
            || std::fabs(degrees) <= 1.0e-6f) {
        return;
    }
    const float radians = degrees * 0.01745329251994329577f;
    for (int index = 0; index < 3; ++index) {
        basis[index] = RotateAroundAxis(basis[index], rotationAxis, radians);
    }
    basis.OrthoNormalizeSelf();
}

void AlignDominantAxis(idMat3& basis, const idVec3& collisionNormal,
        const idEntityEmitter::AXIS excludedAxis) {
    idVec3 normal = Normalized(collisionNormal);
    if (normal.LengthSqr() <= 1.0e-6f) {
        return;
    }

    int bestAxis = -1;
    float bestDot = 0.0f;
    for (int axis = 0; axis < 3; ++axis) {
        if (axis == static_cast<int>(excludedAxis)) {
            continue;
        }
        const float dot = basis[axis].Dot(normal);
        if (bestAxis < 0 || std::fabs(dot) > std::fabs(bestDot)) {
            bestAxis = axis;
            bestDot = dot;
        }
    }
    if (bestAxis < 0) {
        return;
    }

    const idVec3 target = bestDot < 0.0f ? -normal : normal;
    const idVec3 source = Normalized(basis[bestAxis]);
    idVec3 turnAxis = source.Cross(target);
    const float sine = turnAxis.NormalizeFast();
    const float cosine = Clamp(source.Dot(target), -1.0f, 1.0f);
    if (sine <= 1.0e-6f) {
        return;
    }
    const float radians = std::atan2(sine, cosine);
    for (int index = 0; index < 3; ++index) {
        basis[index] = RotateAroundAxis(basis[index], turnAxis, radians);
    }
    basis.OrthoNormalizeSelf();
}
} // namespace

int idEntityEmitterServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}
int idEntityEmitterServices::GetFrameMilliseconds() const {
    return idEntity::Services().GetGameMillisecondsPerFrame();
}
idVec3 idEntityEmitterServices::GetGravity() const {
    return idVec3(0.0f, 0.0f, -1066.0f);
}
bool idEntityEmitterServices::RunParticlePhysics() const { return true; }
bool idEntityEmitterServices::CheckParticleCollisions() const { return true; }
float idEntityEmitterServices::GetFovScaleSpeed() const { return 1.0f; }
float idEntityEmitterServices::GetPushAwayFactor() const { return -0.005f; }
bool idEntityEmitterServices::TracePoint(const idEntityParticle&,
        const idVec3&, const idVec3&, idEntityEmitterTrace&) const {
    return false;
}
idEntityParticle* idEntityEmitterServices::SpawnParticle(
        const idDeclEntityDef*) {
    return new idEntityParticle();
}
void idEntityEmitterServices::DisableDimShadows(idEntityParticle&) {}
void idEntityEmitterServices::PresentParticle(idEntityParticle& particle) {
    particle.UpdateVisuals();
}
bool idEntityEmitterServices::PlayImpactSound(idEntityParticle&,
        const idDeclImpactSound*, int) {
    return false;
}
int idEntityEmitterServices::GetImpactSoundInterval(
        const idDeclImpactSound*) const {
    return 0;
}

// Retail: 0x82C483E0 ??0idEntityParticle@@QAA@XZ
idEntityParticle::idEntityParticle()
    : idEntity(),
      emitTime(0.0f),
      nextSoundTime(0.0f),
      state(STATE_IDLE),
      vel(),
      rotationAxis(),
      rotationSpeed(0.0f),
      lastCollisionPos(),
      lastCollisionNormal(),
      fovScale(1.0f),
      modelDepthHack(0.0f) {
}

// Retail: 0x82C484C0 ?Spawn@idEntityParticle@@QAAXXZ
void idEntityParticle::Spawn() {
    contents = 0;
    BecomeInactive(7);
    Hide();
}

// Retail: 0x82C48528 ?RunState_Fade@idEntityEmitter@@QAA_NPAVidEntityParticle@@@Z
bool idEntityEmitter::RunState_Fade(idEntityParticle* particle) {
    if (particle == nullptr) {
        return false;
    }
    if (static_cast<float>(Services().GetGameMilliseconds())
            < particle->emitTime + particleFadeTime + particleLifespan) {
        return true;
    }

    particle->state = idEntityParticle::STATE_IDLE;
    particle->BecomeInactive(7);
    particle->Hide();
    if (numParticlesInUse > 0) {
        --numParticlesInUse;
        if (numParticlesInUse == 0) {
            BecomeInactive(7);
        }
    }
    return false;
}

// Retail: 0x82C486D0 ?RunPhysics@idEntityEmitter@@QAAXPAVidEntityParticle@@@Z
void idEntityEmitter::RunPhysics(idEntityParticle* particle) {
    if (particle == nullptr || (particle->thinkFlags & 2) == 0) {
        return;
    }

    idEntityEmitterServices& services = Services();
    const float deltaSeconds =
        static_cast<float>(services.GetFrameMilliseconds()) * 0.001f;
    particle->vel = particle->vel + services.GetGravity() * deltaSeconds;
    const idVec3 start = particle->origin;
    idVec3 end = start + particle->vel * deltaSeconds;
    idMat3 newAxis = particle->axis;
    RotateBasis(newAxis, particle->rotationAxis,
        particle->rotationSpeed * deltaSeconds);

    idEntityEmitterTrace trace;
    if (services.CheckParticleCollisions()
            && services.TracePoint(*particle, start, end, trace)
            && trace.hit) {
        trace.fraction = Clamp(trace.fraction, 0.0f, 1.0f);
        idVec3 normal = Normalized(trace.normal);
        const idVec3 contact = start + (end - start) * trace.fraction;
        const float normalSpeed = particle->vel.Dot(normal);
        const idVec3 normalVelocity = normal * normalSpeed;
        const idVec3 tangentialVelocity = particle->vel - normalVelocity;
        const float push = normalSpeed * services.GetPushAwayFactor();
        end = contact + normal * push;
        particle->vel = tangentialVelocity
            + normalVelocity * -particleCollisionElasticity;

        if (random.RandomFloat() < particleCrazyBounceChance) {
            const float bounceSpeed = normalVelocity.Length();
            const int randomAxis = random.RandomInt(3);
            idVec3 kickAxis = newAxis[randomAxis];
            if (kickAxis.Dot(normal) < 0.0f) {
                kickAxis = -kickAxis;
            }
            const float perturbation = random.CRandomFloat()
                * particleCrazyBounceChance;
            particle->vel = particle->vel * (1.0f - perturbation)
                + kickAxis * (bounceSpeed * perturbation);
        }

        particle->rotationSpeed *= 1.0f - particleAngularFriction;
        AlignDominantAxis(newAxis, normal, particleAlignmentExcludeAxis);
        particle->lastCollisionPos = trace.point;
        particle->lastCollisionNormal = normal;

        if (impactSoundTable != nullptr
                && static_cast<float>(services.GetGameMilliseconds())
                    >= particle->nextSoundTime
                && services.PlayImpactSound(*particle, impactSoundTable,
                    trace.surfaceType)) {
            particle->nextSoundTime = static_cast<float>(
                services.GetGameMilliseconds()
                + services.GetImpactSoundInterval(impactSoundTable));
        }
    }

    if ((end - particle->lastCollisionPos).Dot(
            particle->lastCollisionNormal) <= 0.5f) {
        const float speed = particle->vel.Length();
        if (speed > 1.0e-6f) {
            const float newSpeed = (std::max)(0.0f,
                speed - particleFriction * deltaSeconds);
            particle->vel = particle->vel * (newSpeed / speed);
        }
    }

    if ((end - start).LengthSqr() < 0.001f) {
        particle->state = idEntityParticle::STATE_ACTIVE_STOPPED;
    }
    particle->SetOrigin(end);
    particle->SetAxis(newAxis);
}

// Retail: 0x82C49088 ??0idEntityEmitter@@QAA@XZ
idEntityEmitter::idEntityEmitter()
    : idEntity(),
      particleCount(0),
      particleLifespan(0.0f),
      particleFadeTime(1000.0f),
      particleFadeSpeed(20.0f),
      particleCollisionElasticity(0.7f),
      particleCrazyBounceChance(0.0f),
      particleAngularVelocity(10000.0f),
      particleFriction(450.0f),
      particleAngularFriction(0.2f),
      particleAlignmentExcludeAxis(AXIS_NONE),
      impactSoundTable(nullptr),
      particleDef(nullptr),
      particles(),
      particleIndex(0),
      numParticlesInUse(0),
      random(0),
      emitFovScale(1.0f),
      emitModelDepthHack(0.0f) {
}

// Retail: 0x82C491B0 ??1idEntityEmitter@@UAA@XZ
idEntityEmitter::~idEntityEmitter() {
    particles.Clear();
}

void idEntityEmitter::SetServices(idEntityEmitterServices* services) {
    emitterServices = services != nullptr ? services : &defaultEmitterServices;
}

idEntityEmitterServices& idEntityEmitter::Services() {
    return *emitterServices;
}

// Retail: 0x82C49230 ?RunState_Active@idEntityEmitter@@QAAXPAVidEntityParticle@@@Z
void idEntityEmitter::RunState_Active(idEntityParticle* particle) {
    if (particle == nullptr) {
        return;
    }
    idEntityEmitterServices& services = Services();
    if (particle->state == idEntityParticle::STATE_ACTIVE_MOVING
            && services.RunParticlePhysics()) {
        RunPhysics(particle);
    }

    const float fadeStep = static_cast<float>(services.GetFrameMilliseconds())
        * services.GetFovScaleSpeed() * 0.001f;
    if (particle->fovScale < 1.0f) {
        particle->fovScale = (std::min)(1.0f,
            particle->fovScale + fadeStep);
    }
    if (particle->modelDepthHack > 0.0f) {
        particle->modelDepthHack = (std::max)(0.0f,
            particle->modelDepthHack - fadeStep);
    }
    if (static_cast<float>(services.GetGameMilliseconds())
            >= particle->emitTime + particleLifespan) {
        particle->state = idEntityParticle::STATE_FADE;
    }
}

// Retail: 0x82C493F8 ?Think@idEntityEmitter@@UAAXXZ
void idEntityEmitter::Think() {
    idEntity::Think();
    if ((thinkFlags & 1) == 0) {
        return;
    }

    random.RandomInt();
    for (int index = 0; index < particles.Num(); ++index) {
        idEntityParticle* const particle = particles[index];
        if (particle == nullptr) {
            continue;
        }
        bool active = false;
        if (particle->state == idEntityParticle::STATE_ACTIVE_MOVING
                || particle->state == idEntityParticle::STATE_ACTIVE_STOPPED) {
            RunState_Active(particle);
            active = true;
        } else if (particle->state == idEntityParticle::STATE_FADE) {
            active = RunState_Fade(particle);
        }
        if (active) {
            Services().PresentParticle(*particle);
        }
    }
}

// Retail: 0x82C49620 ?Spawn@idEntityEmitter@@QAAXXZ
void idEntityEmitter::Spawn() {
    contents = 0;
    BecomeInactive(7);
    Hide();
    if (particleDef != nullptr) {
        for (int index = 0; index < particleCount; ++index) {
            idEntityParticle* const particle =
                Services().SpawnParticle(particleDef);
            if (particle != nullptr) {
                Services().DisableDimShadows(*particle);
                particles.Append(particle);
            }
        }
    }
    particleAngularFriction = Clamp(particleAngularFriction, 0.0f, 1.0f);
    particleCollisionElasticity = Clamp(
        particleCollisionElasticity, 0.0f, 1.0f);
}
