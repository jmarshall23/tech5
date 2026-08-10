#pragma once

#include "idlib/math/vector.h"

class idAI2;
class idWeapon;

struct idWanderingAimRuntime {
    idWanderingAimRuntime();

    const idWeapon* effectiveWeapon;
    float maxDivergence;
    float convergeRate;
    float wanderScale;
    int wanderDuration;
    int lastFireGraceDuration;
    int settledDuration;
    int lastFireTime;
    int blockedShots;
    idVec3 gravityNormal;
    bool inCombat;
    bool accuratelyAiming;
    bool blindFiring;
};

class idWanderingAim {
public:
    idWanderingAim();

    void AddWeaponFireKickbackImpulse(
        const idAI2* ai, const idWeapon* weapon);
    void Diverge(const idAI2* ai);
    void Update(const idAI2* ai, const idVec3& eyePosition,
        const idVec3& directionToTarget, float distanceToTarget,
        idVec3& newFocusPoint, bool showDebug);

    idVec3 error;
    int lastTime;
    int convergeTime;

private:
    void ConvergeTo(float rate, const idVec3& destination);
    void SmoothWander(float scale, float maximumDivergence);
    const idWeapon* GetEffectiveWeapon(const idAI2* ai) const;
};

bool Tungsten_GetWanderingAimRuntime(
    const idAI2& ai, idWanderingAimRuntime& runtime);
float Tungsten_GetWanderingAimKickback(
    const idAI2& ai, const idWeapon& weapon);
int Tungsten_GetWanderingAimGameMilliseconds();
int Tungsten_GetWanderingAimGameMillisecondsPerFrame();
void Tungsten_DebugWanderingAim(const idVec3& eyePosition,
    const idVec3& focusPoint, int state);
