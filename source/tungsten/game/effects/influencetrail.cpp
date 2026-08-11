#include "game/effects/influencetrail.h"

#include <algorithm>
#include <cmath>

namespace {
idInfluenceTrailServices defaultInfluenceTrailServices;
idInfluenceTrailServices* activeInfluenceTrailServices =
    &defaultInfluenceTrailServices;

bool ValidTrailHandle(const idInfluenceTrailHandle& handle) {
    return handle.IsValid() && handle.Get() >= 0 && handle.Get() < 128;
}
}

void idInfluenceTrailManager::SetServices(
        idInfluenceTrailServices* services) {
    activeInfluenceTrailServices = services == nullptr
        ? &defaultInfluenceTrailServices : services;
}

idInfluenceTrailServices& idInfluenceTrailManager::Services() {
    return *activeInfluenceTrailServices;
}

// EA 0x82BE0EA8
idInfluenceTrailHandle idInfluenceTrailManager::AllocInfluenceTrail(
        const float inner, const float outer, const float trailAngle,
        const float distance, const int fadeIn, const int fadeOut,
        idPresentable* presentable, const idSoundShader* foliageSound) {
    int freeIndex = -1;
    for (int index = 0; index < 128; ++index) {
        if (!influenceTrails[index].active) {
            freeIndex = index;
            break;
        }
    }
    if (freeIndex < 0) {
        Services().OutOfInfluenceTrails();
        return {};
    }

    idInfluenceTrail& trail = influenceTrails[freeIndex];
    trail.trailDist = distance;
    trail.innerRadius = inner;
    trail.outerRadius = outer;
    trail.angle = trailAngle;
    trail.trailFadeInTime = fadeIn;
    trail.trailFadeOutTime = fadeOut;
    trail.position.Zero();
    trail.lastPosition.Zero();
    trail.presentable = presentable;
    trail.sndFoliage = foliageSound;
    trail.active = true;
    return idInfluenceTrailHandle(freeIndex);
}

// EA 0x82BE0F70
void idInfluenceTrailManager::FreeInfluenceTrail(
        idPresentable& presentable) {
    const idInfluenceTrailHandle handle = Services().GetHandle(&presentable);
    if (!ValidTrailHandle(handle)) return;
    idInfluenceTrail& trail = influenceTrails[handle.Get()];
    trail.active = false;
    trail.presentable = nullptr;
    trail.sndFoliage = nullptr;
    Services().SetHandle(&presentable, idInfluenceTrailHandle());
}

// EA 0x82BE0FA8
void idInfluenceTrailManager::ModifyAngle(
        const idInfluenceTrailHandle& trail, const float newAngle) {
    if (ValidTrailHandle(trail)) {
        influenceTrails[trail.Get()].angle = newAngle;
    }
}

// EA 0x82BE0FC8
void idInfluenceTrailManager::AddInfluenceSpheresToModel(
        idRenderModelTransparency* model, const int time) {
    if (model == nullptr) return;
    constexpr float TWO_PI = 6.28318530717958647692f;
    for (int trailIndex = 0; trailIndex < 128; ++trailIndex) {
        idInfluenceTrail& influence = influenceTrails[trailIndex];
        if (!influence.active) continue;

        Services().AddInfluenceSphere(model, influence.position,
            influence.innerRadius, influence.outerRadius, influence.angle);
        if (influence.trailDist == -1.0f) {
            if (influence.sndFoliage != nullptr &&
                    !Services().IsFoliageSoundPlaying(
                        influence.presentable)) {
                Services().StartFoliageSound(
                    influence.presentable, influence.sndFoliage);
            }
            for (int sphereIndex = 0;
                    sphereIndex < influence.trail.Num(); ++sphereIndex) {
                Services().AddInfluenceSphere(model,
                    influence.trail[sphereIndex].center,
                    influence.innerRadius, influence.outerRadius,
                    influence.angle);
            }
            continue;
        }

        for (int sphereIndex = 0;
                sphereIndex < influence.trail.Num(); ++sphereIndex) {
            const idInfluenceTrail::idInfluenceSphere& sphere =
                influence.trail[sphereIndex];
            const int elapsed = time - sphere.time;
            const int totalTime = influence.trailFadeInTime +
                influence.trailFadeOutTime;
            if (elapsed > totalTime) continue;

            float fade;
            if (elapsed <= influence.trailFadeInTime) {
                fade = influence.trailFadeInTime <= 0 ? 1.0f
                    : static_cast<float>(elapsed) /
                        influence.trailFadeInTime;
            } else {
                fade = influence.trailFadeOutTime <= 0 ? 0.0f
                    : static_cast<float>(totalTime - elapsed) /
                        influence.trailFadeOutTime;
            }
            const float elapsedSeconds = elapsed * 0.001f;
            const float wave = std::cos(
                TWO_PI / (elapsedSeconds + 1.0f) * elapsedSeconds);
            const float sphereAngle = influence.angle * wave * fade;
            if (influence.sndFoliage != nullptr &&
                    !Services().IsFoliageSoundPlaying(
                        influence.presentable)) {
                Services().StartFoliageSound(
                    influence.presentable, influence.sndFoliage);
            }
            Services().AddInfluenceSphere(model, sphere.center,
                influence.innerRadius, influence.outerRadius, sphereAngle);
        }
    }
}

// EA 0x82BE1240
void idInfluenceTrailManager::Enable(idPresentable& presentable,
        const idEntityInfluenceTrail& trail,
        const idSoundShader* foliageSound) {
    if (trail.angle == 0.0f ||
            Services().GetHandle(&presentable).IsValid()) {
        return;
    }
    const idInfluenceTrailHandle handle = AllocInfluenceTrail(
        trail.innerRadius, trail.outerRadius, trail.angle,
        trail.trailDist,
        static_cast<int>(trail.trailFadeInTime * 1000.0f),
        static_cast<int>(trail.trailFadeOutTime * 1000.0f),
        &presentable, foliageSound);
    Services().SetHandle(&presentable, handle);
}

// EA 0x82BE1368
idInfluenceTrail::idInfluenceTrail()
    : active(false)
    , trailDist(0.0f)
    , innerRadius(0.0f)
    , outerRadius(0.0f)
    , angle(0.0f)
    , trailFadeInTime(0)
    , trailFadeOutTime(0)
    , position(0.0f, 0.0f, 0.0f)
    , lastPosition(0.0f, 0.0f, 0.0f)
    , trail(0)
    , presentable(nullptr)
    , sndFoliage(nullptr) {
}

// EA 0x82BE1660
void idInfluenceTrail::UpdatePosition(const idVec3& newPosition,
        const int time) {
    position = newPosition;
    if (trailDist == -1.0f) return;

    const idVec3 delta = newPosition - lastPosition;
    if (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z >
            trailDist * trailDist) {
        idInfluenceSphere sphere;
        sphere.center = newPosition;
        sphere.time = time;
        trail.Append(sphere);
        lastPosition = newPosition;
    }
    for (int index = 0; index < trail.Num(); ++index) {
        if (time - trail[index].time >
                trailFadeInTime + trailFadeOutTime) {
            trail.RemoveIndex(index--);
        }
    }
}

// EA 0x82BE1860
void idInfluenceTrailManager::UpdateInfluenceTrails(const int time,
        idRenderModelTransparency* transparencyModel) {
    for (int index = 0; index < 128; ++index) {
        if (influenceTrails[index].active) {
            influenceTrails[index].UpdatePosition(
                influenceTrails[index].position, time);
        }
    }
    if (transparencyModel != nullptr) {
        Services().ClearInfluenceSpheres(transparencyModel);
        AddInfluenceSpheresToModel(transparencyModel, time);
    }
}

// EA 0x82BE18D0
void idInfluenceTrailManager::UpdatePosition(
        const idInfluenceTrailHandle& trail, const idVec3& position,
        const int time) {
    if (ValidTrailHandle(trail)) {
        influenceTrails[trail.Get()].UpdatePosition(position, time);
    }
}
