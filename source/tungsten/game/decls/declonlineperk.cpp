#include "game/decls/declonlineperk.h"

idDeclInfoTemplate<idDeclOnlinePerk> idDeclOnlinePerk::resourceList(
    "onlinePerk", "idDeclOnlinePerk", "tdef");

// EA 0x82BCA730
idDeclOnlinePerk::idDeclOnlinePerk()
    : boostUpModifier(1.0f)
    , duraBumpModifier(1.0f)
    , jumpManModifier(1.0f)
    , overAmmoModifier(1.0f)
    , lockJackModifier(1.0f)
    , fasterFasterModifier(1.0f)
    , theSnapperModifier(1.0f)
    , overLoadModifier(0) {
}

// EA 0x82BCA810
void idDeclOnlinePerk::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }
}
