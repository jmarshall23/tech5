#include "game/decls/declvehicleloadout.h"

idDeclInfoTemplate<idDeclVehicleLoadout> idDeclVehicleLoadout::resourceList(
    "vehicleLoadout", "idDeclVehicleLoadout", "tdef");
idList<const idDeclVehicleLoadout*, 5>
    idDeclVehicleLoadout::defaultLoadouts;

// EA 0x82BCBCF8
idDeclVehicleLoadout::idDeclVehicleLoadout()
    : desc()
    , vehicleClass(nullptr)
    , vehicle(nullptr)
    , weaponPrimary(nullptr)
    , weaponSecondary(nullptr)
    , quickUse1(nullptr)
    , quickUse2(nullptr)
    , isDefault(false)
    , order(0) {
}
