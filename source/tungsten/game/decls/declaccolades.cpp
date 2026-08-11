#include "game/decls/declaccolades.h"

#include "renderer/declmaterial.h"

#include <algorithm>

idDeclInfoTemplate<idDeclAccolade> idDeclAccolade::resourceList(
    "accolade", "idDeclAccolade", "decl");
idList<const idDeclAccolade*, 5> idDeclAccolade::orderedList;

// EA 0x82BBADB8
idDeclAccolade::idDeclAccolade()
    : ordinal(0)
    , icon(nullptr)
    , stat(static_cast<rageStat_t>(-1))
    , accoladeName()
    , description()
    , index(-1) {
}

// EA 0x82BBAEF8
const char* idDeclAccolade::GetIconName() const {
    return icon != nullptr ? icon->GetName() : "";
}

// EA 0x82BBAFE8
void idDeclAccolade::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }

    orderedList.SetNum(resourceList.num);
    for (int index = 0; index < resourceList.num; ++index) {
        orderedList[index] = static_cast<const idDeclAccolade*>(
            resourceList.Index(index));
    }
    std::sort(orderedList.Ptr(), orderedList.Ptr() + orderedList.Num(),
        [](const idDeclAccolade* lhs, const idDeclAccolade* rhs) {
            if (lhs == nullptr) return false;
            if (rhs == nullptr) return true;
            return lhs->ordinal < rhs->ordinal;
        });
    for (int index = 0; index < orderedList.Num(); ++index) {
        if (orderedList[index] != nullptr) {
            orderedList[index]->index = index;
        }
    }
}

