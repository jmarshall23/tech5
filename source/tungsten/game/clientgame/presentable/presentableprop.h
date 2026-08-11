#pragma once

#include "presentable.h"
#include "presentableptr.h"
#include "../../../../shared/idlib/langdict.h"

class idAnimStack;
class idDeclInventory;
class idProp;
class idRenderModel;

class idPresentableProp;

class idPresentablePropServices {
public:
    virtual ~idPresentablePropServices() = default;
    virtual bool IsServer() const { return false; }
    virtual int GetServerGameTime() const { return 0; }
    virtual int GetSnapshotsSerialized() const { return 0; }
    virtual idPresentable* GetPresentableByIndex(int) const { return nullptr; }
    virtual idStrId GetInventoryDisplayName(const idDeclInventory*) const {
        return idStrId();
    }
    virtual void SerializeInventoryDeclaration(idSerializer&,
        const idDeclInventory*&) {}
    virtual void SerializeSoundDeclaration(idSerializer&,
        const idSoundShader*&) {}
    virtual void StopPickupEffects(idPresentableProp&) {}
    virtual void PlayPickupSound(idPresentableProp&, idPresentable&) {}
    virtual void StartPickupEffect(idPresentableProp&) {}
    virtual void StartVehicleRallyEffect(idPresentable*) {}
    virtual void StartRallyMarkerEffect(idPresentableProp&) {}
    virtual void StopRallyIdleEffect(idPresentableProp&) {}
};

void Tungsten_SetPresentablePropServices(idPresentablePropServices* services);

class idPresentableProp : public idPresentableAnimatedEntity {
public:
    enum specialProp_t : int {
        SPECIAL_PROP_NONE = 0,
        SPECIAL_PROP_RALLY = 1
    };

    struct pickupEventInfo_t {
        int eventTime{0};
        int lastHandledEventTime{0};
        int playerIndex{0};
        int presentableIndex{-1};
    };

    idPresentableProp(idProp* entity, idRenderModel* renderModel,
        idAnimStack* animStack, int entityNumber, const idDeclFX* fxDecl,
        bool useSphereModel, const idDeclInventory* inventoryDecl,
        bool isUsable);
    ~idPresentableProp() override;

    void InternalPickupProp(idPresentable* activator);
    void ClientPredict(int currentTime, float fraction) override;
    idStrId GetOnlineUsableText() const override;
    void Serialize(idSerializer& serializer) override;
    int GetPlayerIndex(idPresentable* presentable) const;
    void PickupProp(idPresentable* activator);

    presentableType_t GetType() const override { return PRESENTABLE_PROP; }
    idPresentableProp* GetPropInterface() override { return this; }

    pickupEventInfo_t pickupEventInfo;
    const idSoundShader* pickupSound;
    bool shouldPlayPickupSound;
    bool predictedPickup;
    bool pickupOnTouch;
    bool pickupOnUse;
    const idDeclInventory* inventoryDecl;
    bool isUsable;
    netBoolEvent_t resetPickup;
    specialProp_t specialType;
};
