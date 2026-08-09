#pragma once

#include "idlib/math/vector.h"

class idDeclEnv;
class idDeclRenderParm;
class idPresentablePlayer;
class idRenderModel;

class idViewCallbacks {
public:
    virtual const char* GetName() = 0;
    virtual int GetViewID() = 0;
    virtual void GetPosition(idVec3* origin, idMat3* axis) = 0;
    virtual void GetViewPosition(idVec3* origin, idMat3* axis) = 0;
    virtual void ApplyScreenShake(float scale, const idAngles* angles,
        const idVec3* translation) = 0;
    virtual void ApplyControllerShake(float highMagnitude,
        float highDuration, float lowMagnitude, float lowDuration) = 0;
    virtual void ApplyDynEnvOverride(const idDeclEnv* environment,
        float fraction) = 0;
    virtual void ApplyDynEnvParmOverride(const idDeclRenderParm* parameter,
        const idVec4* value, bool clear, float fraction) = 0;
    virtual void ApplyRadialBlur(const idVec3* origin, float radius,
        float intensity, float duration, float start, float fade) = 0;
    virtual int AddScreenParticle(idRenderModel* model, float lifetime) = 0;
    virtual void RemoveScreenParticle(int handle, int time) = 0;
};

class idPlayerViewCallbacks : public idViewCallbacks {
public:
    const char* GetName() override;
    int GetViewID() override;
    void GetPosition(idVec3* origin, idMat3* axis) override;
    void GetViewPosition(idVec3* origin, idMat3* axis) override;
    void ApplyScreenShake(float scale, const idAngles* angles,
        const idVec3* translation) override;
    void ApplyControllerShake(float highMagnitude, float highDuration,
        float lowMagnitude, float lowDuration) override;
    void ApplyDynEnvOverride(const idDeclEnv* environment,
        float fraction) override;
    void ApplyDynEnvParmOverride(const idDeclRenderParm* parameter,
        const idVec4* value, bool clear, float fraction) override;
    void ApplyRadialBlur(const idVec3* origin, float radius,
        float intensity, float duration, float start, float fade) override;
    int AddScreenParticle(idRenderModel* model, float lifetime) override;
    void RemoveScreenParticle(int handle, int time) override;

    idPresentablePlayer* self;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idViewCallbacks) == 4,
    "Recovered view-callback ABI changed");
static_assert(sizeof(idPlayerViewCallbacks) == 8,
    "Recovered player view-callback ABI changed");
#endif
