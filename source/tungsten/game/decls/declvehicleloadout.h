#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/langdict.h"

class idDeclVehicleUnlock;

class idDeclVehicleLoadout : public idDeclTypeInfo {
public:
    idDeclVehicleLoadout();

    // Retail symbol: ?GetDeclInfo@idDeclVehicleLoadout@@UBAPAVidDeclInfo@@XZ
    // EA: 0x82BCBD60, RVA: 0x00BCBD60
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idStrId desc;
    const idDeclVehicleUnlock* vehicleClass;
    const idDeclVehicleUnlock* vehicle;
    const idDeclVehicleUnlock* weaponPrimary;
    const idDeclVehicleUnlock* weaponSecondary;
    const idDeclVehicleUnlock* quickUse1;
    const idDeclVehicleUnlock* quickUse2;
    bool isDefault;
    int order;

    static idList<const idDeclVehicleLoadout*, 5> defaultLoadouts;
    static idDeclInfoTemplate<idDeclVehicleLoadout> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclVehicleLoadout) == 100,
    "Recovered idDeclVehicleLoadout layout changed");
#endif
