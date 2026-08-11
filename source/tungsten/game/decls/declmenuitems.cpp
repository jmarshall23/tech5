#include "game/decls/declmenuitems.h"

idDeclInfoTemplate<idDeclMenuItem> idDeclMenuItem::resourceList(
    "menuItem", "idDeclMenuItem", "tdef");
idList<const idDeclMenuItem*, 5> idDeclMenuItem::orderedList;

// EA 0x82BC8360
idDeclMenuItem::idDeclMenuItem()
    : material(nullptr)
    , title()
    , help()
    , loadoutSlot(LOADOUT_SLOT_VEHICLE_CLASS)
    , index(0) {
}

// EA 0x82BC83F8
idDeclMenuItem::~idDeclMenuItem() = default;

// EA 0x82BC8508
void idDeclMenuItem::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }

    orderedList.SetNum(resourceList.num);
    for (int index = 0; index < resourceList.num; ++index) {
        orderedList[index] = static_cast<const idDeclMenuItem*>(
            resourceList.Index(index));
    }

    for (int index = 0; index < orderedList.Num(); ++index) {
        if (orderedList[index] != nullptr) {
            orderedList[index]->index = index;
        }
    }
}
