#pragma once

#include "gamelib/physics/physics_dynamicbase.h"
#include "idlib/math/rotation.h"

class idPhysics_Actor : public idPhysics_DynamicBase {
public:
    enum actorClipModel_t : int {
        ACTORCLIP_DEFAULT = 0,
        ACTORCLIP_PLAYER = 1,
        ACTORCLIP_MAX = 2
    };

    idPhysics_Actor();
    ~idPhysics_Actor() override;

    void SetClipModel(idClipModel*, float, int, bool) override;
    idClipModel* GetClipModel(int) override;
    int GetNumClipModels() override;
    void SetMass(float, int) override;
    float GetMass(int) override;
    void SetContents(int, int) override;
    int GetContents(int) override;
    void SetClipMask(int, int) override;
    int GetClipMask(int) override;
    const idBounds* GetBounds(int) override;
    const idBounds* GetAbsBounds(int) override;
    const idVec3* GetOrigin(int) override;
    const idMat3* GetAxis(int) override;
    void SetGravity(const idVec3*) override;
    bool IsPushable(int) override;
    void ClipTranslation(trace_t*, const idVec3*,
        const idClipModel*) override;
    void ClipRotation(trace_t*, const idRotation*,
        const idClipModel*) override;
    int ClipContents(const idClipModel*, int) override;
    void DisableClip() override;
    void EnableClip() override;
    void UnlinkClip() override;
    void LinkClip() override;
    bool EvaluateContacts() override;

    virtual const idMat3* GetGravityAxis() { return &clipModelAxis; }
    virtual void DisableClip(actorClipModel_t clipType);
    virtual void EnableClip(actorClipModel_t clipType);
    virtual void LinkClip(const idVec3& origin, const idMat3& axis);
    void SetClipModelAxis();
    float GetMasterDeltaYaw() const;
    void RememberHistorySample();
    idVec3 GetOriginHistory(int millisecondsAgo) const;
    idVec3 GetVelocityHistory(int millisecondsAgo) const;

    idClipModel* clipModels[ACTORCLIP_MAX];
    int clipMasks[ACTORCLIP_MAX];
    idMat3 clipModelAxis;
    float mass;
    float invMass;
    bool hasMaster;
    float masterYaw;
    float masterDeltaYaw;
    bool wasHistoryInitialized;
    int lastHistorySaveTime;
    idVec3 originHistory[16];
    float yawHistory[16];
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idPhysics_Actor) == 456,
    "Recovered idPhysics_Actor ABI changed");
#endif
