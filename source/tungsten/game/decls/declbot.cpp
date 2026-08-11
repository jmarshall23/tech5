#include "game/decls/declbot.h"

// EA 0x82BBC950
idDeclBot::~idDeclBot() = default;

// EA 0x82BBC9E8
idDeclBot::idDeclBot()
    : botName("Phobos") {
}

// EA 0x82BBCAD0
void idDeclBot::LoadAllDecls() {
    for (int index = 0; index < resourceList.declSources.Num(); ++index) {
        const idDeclSource* source = resourceList.declSources[index];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }
}

