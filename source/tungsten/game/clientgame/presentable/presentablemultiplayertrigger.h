#pragma once

#include "presentable.h"

class idMultiplayerTrigger;
class idPresentableMultiplayerTrigger;

enum mpTriggerType_t : int {
    MP_TRIGGER_TYPE_NONE = 0,
    MP_TRIGGER_TYPE_BOOSTPAD = 1
};

class idPresentableVehicle : public idPresentable {
public:
    idPresentableVehicle* GetVehicleInterface() override { return this; }
};

class idPresentableMultiplayerTriggerServices {
public:
    virtual ~idPresentableMultiplayerTriggerServices() = default;

    virtual int GetScaledGameTime() const { return 0; }
    virtual idVec3 GetVehicleGravity(const idPresentableVehicle&) const {
        return idVec3(0.0f, 0.0f, -9.8f);
    }
    virtual idVec3 GetVehicleGravityNormal(
        const idPresentableVehicle&) const {
        return idVec3(0.0f, 0.0f, -1.0f);
    }
    virtual idVec3 GetVehicleOrigin(const idPresentableVehicle&) const {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    virtual void SetVehicleAngularVelocity(idPresentableVehicle&,
        const idVec3&) {}
    virtual void SetVehicleLinearVelocity(idPresentableVehicle&,
        const idVec3&) {}
    virtual void StartVehicleBoostFX(idPresentableVehicle&) {}
    virtual void SetVehicleExternalBoostDuration(idPresentableVehicle&,
        int) {}
    virtual void MegaBoost(idPresentableVehicle&, float, int) {}
    virtual void ActivateBoostPadFX(idPresentableMultiplayerTrigger&,
        const idVec3&, const idMat3&, int) {}
    virtual void CollectTouchingTriggers(idPresentableVehicle&,
        idList<idPresentableMultiplayerTrigger*, 5>&) {}
    virtual bool VehicleTouchesTrigger(const idPresentableVehicle&,
        const idPresentableMultiplayerTrigger&) const { return true; }
};

void Tungsten_SetPresentableMultiplayerTriggerServices(
    idPresentableMultiplayerTriggerServices* services);

class idMultiplayerTriggerStrategy {
public:
    virtual ~idMultiplayerTriggerStrategy() = default;
    virtual void Touch(idPresentableMultiplayerTrigger&, idPresentable&) {}
    virtual void Think(idPresentableMultiplayerTrigger&) {}
    virtual void Serialize(idSerializer&) {}
    virtual mpTriggerType_t GetTriggerType() const {
        return MP_TRIGGER_TYPE_NONE;
    }
};

class idMultiplayerTriggerStrategy_BoostPad final
    : public idMultiplayerTriggerStrategy {
public:
    idMultiplayerTriggerStrategy_BoostPad();

    void Think(idPresentableMultiplayerTrigger& trigger) override;
    void Touch(idPresentableMultiplayerTrigger& trigger,
        idPresentable& other) override;
    void Serialize(idSerializer& serializer) override;
    mpTriggerType_t GetTriggerType() const override {
        return MP_TRIGGER_TYPE_BOOSTPAD;
    }

    void Boost(idPresentableVehicle& car, const idVec3& pushVelocity) const;
    void BoostPadActivateFX(idPresentableMultiplayerTrigger& trigger) const;
    void BoostToTarget(idPresentableVehicle& car) const;

    idMat3 fxAxis;
    idVec3 fxOrigin;
    idVec3 targetOrigin;
    float acceleration;
    int time;
    int boostTime;
    bool hasTarget;
};

class idPresentableMultiplayerTrigger : public idPresentable {
public:
    idPresentableMultiplayerTrigger();
    idPresentableMultiplayerTrigger(idMultiplayerTrigger* entity,
        idRenderModel* renderModel, int entityNumber, const idDeclFX* fxDecl,
        idMultiplayerTriggerStrategy* strategy);
    ~idPresentableMultiplayerTrigger() override;

    void ServerThink(int currentTime);
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void Serialize(idSerializer& serializer) override;
    idPresentableMultiplayerTrigger* GetMultiplayerTriggerInterface()
        override { return this; }
    presentableType_t GetType() const override {
        return PRESENTABLE_MULTIPLAYER_TRIGGER;
    }

    static void Touch(idPresentableVehicle* car);
    void AllocStrategy(mpTriggerType_t triggerType);

    idList<int, 5> touching;
    idList<int, 5> oldTouching;
    idMultiplayerTriggerStrategy* strategy;
    idEntity* triggerEntity;
};
