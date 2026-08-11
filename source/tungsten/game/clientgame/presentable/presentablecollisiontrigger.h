#pragma once

#include "presentable.h"

class idPresentableCollisionTriggerServices {
public:
    virtual ~idPresentableCollisionTriggerServices() = default;
    virtual idPresentable* ResolvePresentable(std::uint32_t) const {
        return nullptr;
    }
};

void Tungsten_SetPresentableCollisionTriggerServices(
    idPresentableCollisionTriggerServices* services);

class idPresentableCollisionTrigger : public idPresentable {
public:
    idPresentableCollisionTrigger();
    idPresentableCollisionTrigger(idEntity* entity,
        idRenderModel* renderModel, int entityNumber, const idDeclFX* fx);

    void Serialize(idSerializer& serializer) override;
    presentableType_t GetType() const override {
        return PRESENTABLE_COLLISION_TRIGGER;
    }
    idPresentableCollisionTrigger* GetCollisionTriggerInterface() {
        return this;
    }
    void PredictTouch(idPresentablePlayer* player);

    std::uint32_t targetPresentableSpawnId;
    bool triggered;
};

