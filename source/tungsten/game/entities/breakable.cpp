#include "game/entities/breakable.h"

#include <algorithm>
#include <cmath>

namespace {
idBreakableServices defaultBreakableServices;
idBreakableServices* breakableServices = &defaultBreakableServices;
}

void idBreakable::SetServices(idBreakableServices* const services) {
    breakableServices = services == nullptr
        ? &defaultBreakableServices : services;
}

idBreakableServices& idBreakable::Services() {
    return *breakableServices;
}

// Retail: 0x82C0C5B8 ?Hide@idBreakable@@UAAXXZ
void idBreakable::Hide() {
    Services().Hide(*this);
    Services().SetClipEnabled(*this, false);
    if (isPooled) {
        Services().SetThinkFlags(*this, 7, false);
    }
}

// Retail: 0x82C0C618 ?Spawn@idBreakable@@QAAXXZ
void idBreakable::Spawn() {
    currentHealth = health;
    if (!Services().Initialize(*this, maxSimulationTime)) {
        Services().Warn("breakable is missing its breakable model or declaration");
        return;
    }
    Services().SetClipEnabled(*this, true);
    Services().UpdateBreakableModel(*this);
    Services().SetThinkFlags(*this, 1, true);
    idMat3 axis;
    Services().GetTransform(*this, oldOrigin, axis);
    velocity.Zero();
}

// Retail: 0x82C0C920 ?AllocPresentable@idBreakable@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idBreakable::AllocPresentable(
        idRenderModel* const renderModel) {
    return Services().AllocPresentable(*this, renderModel,
        impactSoundTable, pieceMinBounceVelocity);
}

// Retail: 0x82C0C9D8 ?PostBind@idBreakable@@UAAXXZ
void idBreakable::PostBind() {
    Services().SetThinkFlags(*this, 2, true);
    idMat3 axis;
    Services().GetTransform(*this, oldOrigin, axis);
    velocity.Zero();
}

// Retail: 0x82C0CA60 ?GetModelTransform@idBreakable@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idBreakable::GetModelTransform(idVec3& origin, idMat3& axis) const {
    Services().GetTransform(*this, origin, axis);
}

void idBreakable::ResetCommon(const bool resetModel) {
    Services().ResetPhysics(*this, !resetModel);
    Services().SetThinkFlags(*this, 2, false);
    brokenStartTime = -1;
    brokenFrame = -1;
    fade = {};
    Services().SetCoverage(*this, 1.0f);
}

// Retail: 0x82C0CB18 ?Reset@idBreakable@@QAAXXZ
void idBreakable::Reset() {
    if (brokenStartTime == -1) {
        return;
    }
    ResetCommon(true);
    Services().UpdateBreakableModel(*this);
    currentHealth = health;
}

// Retail: 0x82C0CCA0 ?ResetRigidBodies@idBreakable@@QAAXXZ
void idBreakable::ResetRigidBodies() {
    ResetCommon(false);
}

// Retail: 0x82C0CD90 ?Show@idBreakable@@UAAXXZ
void idBreakable::Show() {
    Services().Show(*this);
    Services().SetClipEnabled(*this, true);
    Services().SetThinkFlags(*this, 1, true);
    Services().UpdateBreakableModel(*this);
}

// Retail: 0x82C0CE50 ?Break@idBreakable@@AAAXPAVidEntity@@@Z
void idBreakable::Break(idEntity* const activator) {
    Services().ForceDormancy(*this, false, 10000);
    Services().BreakPresentable(*this, activator);
    if (brokenStartTime != -1) {
        return;
    }
    brokenStartTime = Services().GetGameMilliseconds();
    brokenFrame = Services().GetGameFrame() + 1;
    Services().UnlinkMainClip(*this);
    if (Services().IsVehicle(activator)) {
        Services().ConfigureVehicleBreakExplosions(*this, activator);
    }
    Services().ApplyBreakForce(*this, idVec3(
        velocity.x * velocityScale,
        velocity.y * velocityScale,
        velocity.z * velocityScale));
    Services().PlayBreakSound(*this, soundExplosion);
    Services().SetThinkFlags(*this, 2, true);
    Services().ActivateTargets(*this, activator);
}

// Retail: 0x82C0D4C8 ?ApplyImpulse@idBreakable@@UAAXHHABVidVec3@@0@Z
void idBreakable::ApplyImpulse(const int physicsId, int,
        const idVec3&, const idVec3&) {
    idEntity* activator = nullptr;
    idVec3 worldOrigin;
    idBreakableExplosionParms explosion;
    if (!Services().GetImpulseExplosion(
            physicsId, activator, worldOrigin, explosion)) {
        return;
    }
    idVec3 origin;
    idMat3 axis;
    Services().GetTransform(*this, origin, axis);
    explosion.position = axis * (worldOrigin - origin);
    Services().AddPhysicsExplosion(*this, explosion);
    Break(activator);
}

// Retail: 0x82C0D648 ?Damage@idBreakable@@UAAMPAVidEntity@@0PBVidDeclDamage@@...
float idBreakable::Damage(idEntity* const inflictor,
        idEntity* const attacker, const idDeclDamage* const damage,
        const float damageScale, const idVec3& direction,
        trace_t* const trace) {
    if (!Services().TakesDamage(*this) || brokenStartTime != -1
            || damage == nullptr) {
        return 0.0f;
    }
    const float amount = Services().GetDamageAmount(damage) * damageScale;
    if (amount == 0.0f
            || (Services().GetDamageTypes(damage) & ~ignoreDamageType) == 0) {
        return 0.0f;
    }
    if (currentHealth <= amount) {
        currentHealth = 0.0f;
        Services().ConfigureDamageExplosion(
            *this, attacker, damage, direction, trace);
        Break(attacker);
    } else {
        currentHealth -= amount;
        if (attacker != nullptr) {
            Services().DamageFeedback(
                attacker, *this, inflictor, damage, amount);
        } else {
            Services().Warn("null attacker in idBreakable::Damage");
        }
    }
    return amount;
}

// Retail: 0x82C0DB18 ?AddExplosion@idBreakable@@QAA?AVidVec3@@ABV2@M@Z
idVec3 idBreakable::AddExplosion(
        const idVec3& position, const float impulse) {
    idVec3 origin;
    idMat3 axis;
    Services().GetTransform(*this, origin, axis);
    idBreakableExplosionParms explosion;
    explosion.position = axis * (position - origin);
    explosion.impulse = impulse;
    explosion.falloff = 0.2f;
    explosion.duration = 1000;
    Services().AddPhysicsExplosion(*this, explosion);
    Break(nullptr);
    return explosion.position;
}

// Retail: 0x82C0DCC0 ?OnActivate@idBreakable@@EAAXPAVidEntity@@@Z
void idBreakable::OnActivate(idEntity* const activator) {
    Break(activator);
}

// Retail: 0x82C0DCD0 ??0idBreakable@@QAA@XZ
idBreakable::idBreakable()
    : soundExplosion(nullptr), impactSoundTable(nullptr),
      pieceMinBounceVelocity(40.0f), targetable(false),
      ignoreDamageType(0), isPooled(false), breakState(),
      soundOffset(0.0f, 0.0f, 0.0f), maxSimulationTime(0),
      brokenStartTime(-1), brokenFrame(-1), currentHealth(0.0f),
      health(0.0f), fadeBroken(false), fadeTime(1.0f),
      fadeDelay(0.0f), velocityScale(1.0f), fade(),
      oldOrigin(0.0f, 0.0f, 0.0f), velocity(0.0f, 0.0f, 0.0f) {
}

// Retail: 0x82C0DEC8 ??1idBreakable@@UAA@XZ
idBreakable::~idBreakable() {
    Services().RemoveSimulation(*this);
    breakState.Clear();
}

// Retail: 0x82C0E010 ?Think@idBreakable@@UAAXXZ
void idBreakable::Think() {
    if (Services().UpdateDormant(*this)) {
        return;
    }
    const int currentTime = Services().GetGameMilliseconds();
    const int currentFrame = Services().GetGameFrame();
    if (brokenFrame == currentFrame) {
        Services().StartExplosions(*this);
    }

    const int thinkFlags = Services().GetThinkFlags(*this);
    if ((thinkFlags & 2) != 0) {
        if (brokenStartTime == -1) {
            Services().UpdateBreakableModel(*this);
            if (!Services().IsBound(*this)) {
                Services().SetThinkFlags(*this, 2, false);
            }
        } else {
            Services().UpdateSimulation(*this);
            Services().UpdateBreakableModel(*this);
            Services().RegisterSimulation(*this);
            const int fadeDelayMS = static_cast<int>(fadeDelay * 1000.0f);
            if (currentTime >= brokenStartTime
                    + maxSimulationTime + fadeDelayMS) {
                if (fadeBroken) {
                    Services().SetThinkFlags(*this, 1, true);
                }
                Services().SetThinkFlags(*this, 2, false);
            }
        }
        Services().UpdatePVSAreas(*this);
    }

    if ((thinkFlags & 1) != 0) {
        if (brokenStartTime == -1) {
            const int healthPercent = health > 0.0f
                ? static_cast<int>(currentHealth / health * 100.0f) : 0;
            for (int index = 0; index < breakState.Num(); ++index) {
                breakState_t& state = breakState[index];
                if (healthPercent > state.healthPercent
                        || (state.smokeSystemRate > 1
                            && currentFrame % state.smokeSystemRate != 0)) {
                    continue;
                }
                if (state.startTime == 0) {
                    state.startTime = currentTime;
                }
                Services().EmitDamageParticles(*this, state.particle,
                    state.startTime, state.offset, Services().RandomFloat());
            }
        } else if (fadeBroken) {
            const int fadeStart = brokenStartTime
                + static_cast<int>(fadeDelay * 1000.0f);
            const int fadeFinish = fadeStart
                + static_cast<int>(fadeTime * 1000.0f);
            if (Services().IsMultiplayer()) {
                Services().SetMultiplayerFade(*this,
                    static_cast<int>(fadeTime * 1000.0f),
                    static_cast<int>(fadeDelay * 1000.0f));
                if (currentTime >= fadeFinish) {
                    Hide();
                }
            }
            if (currentTime >= fadeStart) {
                if (fade.fadeEndTime == -1) {
                    Hide();
                } else if (fade.fadeEndTime > 0) {
                    Services().UpdateFade(*this, fade);
                } else {
                    fade.fadeFrom = 1.0f;
                    fade.fadeTo = 0.0f;
                    fade.fadeStartTime = currentTime;
                    fade.fadeEndTime = fadeFinish;
                }
            }
        }
    }

    idVec3 currentOrigin;
    idMat3 currentAxis;
    Services().GetTransform(*this, currentOrigin, currentAxis);
    const int frameMilliseconds = Services().GetGameMillisecondsPerFrame();
    if (frameMilliseconds > 0) {
        const float inverseSeconds = 1000.0f
            / static_cast<float>(frameMilliseconds);
        velocity = (currentOrigin - oldOrigin) * inverseSeconds;
    }
    oldOrigin = currentOrigin;
    Services().DebugDrawCollision(*this);
}
