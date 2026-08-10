#pragma once

#include "idlib/math/vector.h"

#include <cstdint>

class idDeclParticle;
class idPresentable;
class idTreeAnimator;

struct tagData_t {
    idVec3 trans;
    idQuat rot;
    std::uint16_t parentJoint;
};

bool Tungsten_GetSmokeEmitterTransform(const idTreeAnimator* animator,
    const tagData_t& tag, idVec3& origin, idMat3& axis);
unsigned int Tungsten_GetClientRandomSeed();
void Tungsten_SetClientRandomSeed(unsigned int seed);
int Tungsten_GetScaledGameMilliseconds();
int Tungsten_GetScaledGameMillisecondsPerFrame();
bool Tungsten_AddSmokeParticles(const idDeclParticle* particle,
    int systemStartTime, int gameMillisecondsPerFrame, float diversity,
    const idVec3& origin, const idMat3& axis, const idVec3& velocity);
void Tungsten_ApplyPresentableFade(
    idPresentable* presentable, float value, bool setModelFade);

class idSmokeEmitter {
public:
    bool Emit(const idVec3& velocity);

    const idDeclParticle* particle;
    idTreeAnimator* ta;
    tagData_t tag;
};

class idFadeHelper {
public:
    void Fade(const float& from, const float& to, const int& time,
        bool noStippleFade);
    bool Update(idPresentable* presentable);

    int fadeStartTime;
    int fadeEndTime;
    float fadeFrom;
    float fadeTo;
    bool noStippleFade;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(tagData_t) == 32, "Recovered tag-data ABI changed");
static_assert(sizeof(idSmokeEmitter) == 40,
    "Recovered smoke-emitter ABI changed");
static_assert(sizeof(idFadeHelper) == 20,
    "Recovered fade-helper ABI changed");
#endif
