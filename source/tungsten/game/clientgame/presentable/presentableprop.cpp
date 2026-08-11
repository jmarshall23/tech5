#include "presentableprop.h"
#include "presentableplayer.h"

namespace {

idPresentablePropServices defaultPropServices;
idPresentablePropServices* propServices = &defaultPropServices;

} // namespace

void Tungsten_SetPresentablePropServices(idPresentablePropServices* services) {
    propServices = services != nullptr ? services : &defaultPropServices;
}

// EA 0x82B8D9C0
idPresentableProp::~idPresentableProp() = default;

// EA 0x82B8D9D0
void idPresentableProp::InternalPickupProp(idPresentable* activator) {
    propServices->StopPickupEffects(*this);
    if (pickupSound != nullptr && shouldPlayPickupSound) {
        idPresentable* receiver = propServices->GetPresentableByIndex(
            pickupEventInfo.presentableIndex);
        if (receiver == nullptr) {
            receiver = this;
        }
        propServices->PlayPickupSound(*this, *receiver);
    }
    Hide(false);
    SetLocalClipModelContents(0);
    propServices->StartPickupEffect(*this);
    if (specialType != SPECIAL_PROP_NONE) {
        if (activator != nullptr) {
            propServices->StartVehicleRallyEffect(activator);
        }
        if (specialType == SPECIAL_PROP_RALLY) {
            propServices->StartRallyMarkerEffect(*this);
            propServices->StopRallyIdleEffect(*this);
        }
    }
}

// EA 0x82B8DBA8
idPresentableProp::idPresentableProp(idProp* prop,
        idRenderModel* renderModel, idAnimStack* stack, int entityNumberValue,
        const idDeclFX* declaration, bool, const idDeclInventory* inventory,
        bool usable)
    : idPresentableAnimatedEntity(reinterpret_cast<idEntity*>(prop),
        renderModel, stack, entityNumberValue, declaration),
      pickupEventInfo(), pickupSound(nullptr), shouldPlayPickupSound(true),
      predictedPickup(false), pickupOnTouch(false), pickupOnUse(false),
      inventoryDecl(inventory), isUsable(usable), resetPickup(),
      specialType(SPECIAL_PROP_NONE) {
    clipModelDynamic = true;
    clipModelDynamicAxis = true;
}

// EA 0x82B8DC40
void idPresentableProp::ClientPredict(int, float) {
    if (propServices->GetSnapshotsSerialized() >= 10) {
        if (pickupEventInfo.lastHandledEventTime
                != pickupEventInfo.eventTime) {
            if (!predictedPickup) {
                InternalPickupProp(nullptr);
            }
            predictedPickup = false;
        }
    } else if (hidden) {
        propServices->StopPickupEffects(*this);
    }
    pickupEventInfo.lastHandledEventTime = pickupEventInfo.eventTime;
    if (predictedPickup) {
        Hide(false);
        SetLocalClipModelContents(0);
    }
}

// EA 0x82B8DD00
idStrId idPresentableProp::GetOnlineUsableText() const {
    return propServices->GetInventoryDisplayName(inventoryDecl);
}

// EA 0x82B8DD28
void idPresentableProp::Serialize(idSerializer& serializer) {
    resetPickup.Serialize(serializer);
    if (serializer.IsReading() && resetPickup.count != resetPickup.lastCount) {
        resetPickup.lastCount = resetPickup.count;
        predictedPickup = false;
        SetClipModelContents(0);
    }
    idPresentableAnimatedEntity::Serialize(serializer);
    serializer.Serialize(pickupEventInfo.eventTime);
    serializer.SerializeUMax(pickupEventInfo.playerIndex, 6);
    serializer.Serialize(pickupEventInfo.presentableIndex);
    serializer.Serialize(isUsable);
    serializer.Serialize(shouldPlayPickupSound);
    serializer.Serialize(pickupOnTouch);
    serializer.Serialize(pickupOnUse);
    propServices->SerializeSoundDeclaration(serializer, pickupSound);
    propServices->SerializeInventoryDeclaration(serializer, inventoryDecl);
}

// EA 0x82B8DF40
int idPresentableProp::GetPlayerIndex(idPresentable* presentable) const {
    if (presentable == nullptr) {
        return 0;
    }
    idPresentablePlayer* player = presentable->GetPlayerInterface();
    if (player != nullptr) {
        return player->entityNumber;
    }
    return presentable->controller != nullptr
        ? presentable->controller->entityNumber : 0;
}

// EA 0x82B8DFB0
void idPresentableProp::PickupProp(idPresentable* activator) {
    if (activator != nullptr
            && activator->GetPlayerInterface() != nullptr
            && (origin - activator->origin).LengthSqr() > 25600.0f) {
        return;
    }
    if (propServices->IsServer()) {
        pickupEventInfo.playerIndex = GetPlayerIndex(activator);
        pickupEventInfo.eventTime = propServices->GetServerGameTime();
        pickupEventInfo.lastHandledEventTime = pickupEventInfo.eventTime;
    } else {
        predictedPickup = true;
    }
    pickupEventInfo.presentableIndex = activator != nullptr
        ? activator->index : -1;
    InternalPickupProp(activator);
}
