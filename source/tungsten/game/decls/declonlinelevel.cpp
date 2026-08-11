#include "game/decls/declonlinelevel.h"

#include <algorithm>
#include <climits>

idDeclInfoTemplate<idDeclOnlineLevel> idDeclOnlineLevel::resourceList(
    "onlineLevel", "idDeclOnlineLevel", "tdef");

// EA 0x82BCA300
int idDeclOnlineLevel::GetNumLoadouts(const int level) const {
    if (levelList.Num() == 0) {
        return 0;
    }

    int index = (std::max)(level - 1, 0);
    index = (std::min)(index, levelList.Num() - 1);
    while (index > 0 && levelList[index].loadouts == 0) {
        --index;
    }
    return levelList[index].loadouts;
}

// EA 0x82BCA378
int idDeclOnlineLevel::GetXpRequiredForLevel(const int level) const {
    if (level <= levelList.Num() && levelList.Num() > 0) {
        const int index = (std::max)(level - 1, 0);
        return static_cast<int>(
            static_cast<float>(levelList[index].baseXp)
            * levelList[index].localXpScale * globalXpScale);
    }
    return static_cast<int>(static_cast<float>(xpCap) * globalXpScale);
}

// EA 0x82BCA430
int idDeclOnlineLevel::GetLevelForXp(const int xp) const {
    int level = 0;
    while (level < levelList.Num()) {
        const onlineLevel_t& threshold = levelList[level];
        const int requiredXp = static_cast<int>(
            static_cast<float>(threshold.baseXp)
            * threshold.localXpScale * globalXpScale);
        if (xp < requiredXp) {
            break;
        }
        ++level;
    }
    return level;
}

// EA 0x82BCA520
idDeclOnlineLevel::idDeclOnlineLevel()
    : levelList()
    , globalXpScale(1.0f)
    , xpCap(INT_MAX) {
}

// EA 0x82BCA5E8
void idDeclOnlineLevel::LoadAllDecls() {
    for (int sourceIndex = 0;
            sourceIndex < resourceList.declSources.Num(); ++sourceIndex) {
        const idDeclSource* source = resourceList.declSources[sourceIndex];
        if (source != nullptr && source->name.c_str() != nullptr) {
            resourceList.FindWithInheritance(source->name.c_str(), false);
        }
    }
}
