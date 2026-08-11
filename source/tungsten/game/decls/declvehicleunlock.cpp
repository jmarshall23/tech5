#include "game/decls/declvehicleunlock.h"

#include "decls/declentitydef.h"
#include "game/decls/declinventory.h"
#include "idlib/hashing/murmur.h"
#include "idlib/lib_print.h"
#include "renderer/declmaterial.h"
#include "sound/soundshader.h"

#include <cstring>

idDeclInfoTemplate<idDeclVehicleUnlock> idDeclVehicleUnlock::resourceList(
    "vehicleUnlock", "idDeclVehicleUnlock", "tdef");
idHashTableT<int, const idDeclVehicleUnlock*>
    idDeclVehicleUnlock::unlockLookup;

// EA 0x82BCBDD8
vehicleUnlockType_t idDeclVehicleUnlock::GetUnlockTypeForSlot(
        const vehicleLoadoutSlot_t slot) {
    switch (slot) {
        case LOADOUT_SLOT_VEHICLE_CLASS:
            return UNLOCK_TYPE_VEHICLE_CLASS;
        case LOADOUT_SLOT_VEHICLE:
            return UNLOCK_TYPE_VEHICLE;
        case LOADOUT_SLOT_WEAPON_PRIMARY:
            return UNLOCK_TYPE_WEAPON_PRIMARY;
        case LOADOUT_SLOT_WEAPON_SECONDARY:
            return UNLOCK_TYPE_WEAPON_SECONDARY;
        case LOADOUT_SLOT_QUICK_USE_1:
            return UNLOCK_TYPE_QUICK_USE_1;
        case LOADOUT_SLOT_QUICK_USE_2:
            return UNLOCK_TYPE_QUICK_USE_2;
        default:
            return UNLOCK_TYPE_NONE;
    }
}

// EA 0x82BCBE38
void idDeclVehicleUnlock::Parse(idParser* parser) {
    idDeclTypeInfo::Parse(parser);
    const char* declarationName = GetName();
    ordinal = static_cast<int>(MurMur32_HashData(
        declarationName,
        declarationName == nullptr
            ? 0
            : static_cast<int>(std::strlen(declarationName)),
        0));
}

// EA 0x82BCBE98
const char* idDeclVehicleUnlock::GetBigLoadoutImageName() const {
    return bigLoadoutIcon == nullptr ? "" : bigLoadoutIcon->GetName();
}

// EA 0x82BCBFA8
const idDeclInventory* idDeclVehicleUnlock::GetInventoryDecl(
        const inventoryUnlock_t& unlock) {
    if (unlock.itemDeclStr.IsEmpty()) {
        return nullptr;
    }
    return static_cast<const idDeclInventory*>(
        idDeclInventory::resourceList.FindWithInheritance(
            unlock.itemDeclStr.c_str(), false));
}

// EA 0x82BCBFD8
const idDeclEntityDef* idDeclVehicleUnlock::GetEntityDef(
        const inventoryUnlock_t& unlock) {
    if (unlock.entityDefStr.IsEmpty()) {
        return nullptr;
    }
    return static_cast<const idDeclEntityDef*>(
        idDeclEntityDef::resourceList.FindWithInheritance(
            unlock.entityDefStr.c_str(), false));
}

// EA 0x82BCC008
const idSoundShader* idDeclVehicleUnlock::GetSoundShader(
        const inventoryUnlock_t& unlock) {
    if (unlock.soundDeclStr.IsEmpty()) {
        return nullptr;
    }
    return static_cast<const idSoundShader*>(
        idSoundShader::resourceList.FindWithInheritance(
            unlock.soundDeclStr.c_str(), false));
}

// EA 0x82BCC038
const idDeclVehicleUnlock* idDeclVehicleUnlock::GetUnlockByOrdinal(
        const int ordinal) {
    const idDeclVehicleUnlock** declaration = nullptr;
    if (ordinal == -1 || !unlockLookup.Get(ordinal, &declaration)) {
        return nullptr;
    }
    return *declaration;
}

// EA 0x82BCC0A8
void idDeclVehicleUnlock::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }

    unlockLookup.Clear();
    for (int declarationIndex = 0;
            declarationIndex < resourceList.num; ++declarationIndex) {
        const idDeclVehicleUnlock* declaration =
            static_cast<const idDeclVehicleUnlock*>(
                resourceList.Index(declarationIndex));
        if (declaration == nullptr) {
            continue;
        }
        if (declaration->ordinal == -1) {
            idLibPrint::Error(
                "idDeclVehicleUnlock [ %s ] failed to load. Ordinal cannot "
                "be -1.  Rename to resolve conflict.",
                declaration->GetName());
        }
        const idDeclVehicleUnlock** existing = nullptr;
        if (unlockLookup.Get(declaration->ordinal, &existing)) {
            idLibPrint::Error(
                "idDeclVehicleUnlock [ %s ] failed to load. Ordinal %d "
                "already exists!  Rename to resolve conflict.",
                declaration->GetName(), declaration->ordinal);
        }
        unlockLookup.Set(declaration->ordinal, declaration);
    }
}

// EA 0x82BCC1F8
idDeclVehicleUnlock::idDeclVehicleUnlock()
    : unlockType(UNLOCK_TYPE_NONE)
    , levelRequired(0)
    , displayName()
    , quantity(0)
    , rangeRank(0)
    , damageRank(0)
    , accuracyRank(0)
    , rateOfFireRank(0)
    , description()
    , loadoutIcon(nullptr)
    , bigLoadoutIcon(nullptr)
    , upgradeTo(nullptr)
    , spRequired(0)
    , metricType(static_cast<rageStat_t>(0))
    , ordinal(-1)
    , items(0) {
}

// Header EA 0x82BCC2F8
idDeclVehicleUnlock::~idDeclVehicleUnlock() = default;
