#include "bot_entitymanager.h"

namespace {
idBotEntityManagerServices* g_entityManagerServices = nullptr;
}

void Tungsten_SetBotEntityManagerServices(
        idBotEntityManagerServices* const services) {
    g_entityManagerServices = services;
}

idBotEntityFilter::idBotEntityFilter()
    : bestEntityIndex(-1), desiredEntityType(0), desiredEntityFlags(0),
      ignoreEntityFlags(0), bestEntity() {
}

// Retail symbol: ?Init@idBotEntityFilter@@UAAXHHH@Z
// EA: 0x82B48B38, RVA: 0x00B48B38
void idBotEntityFilter::Init(const int desiredEntType,
        const int desiredEntFlags, const int ignoreEntFlags) {
    desiredEntityType = desiredEntType;
    desiredEntityFlags = desiredEntFlags;
    ignoreEntityFlags = ignoreEntFlags;
}

// Retail symbol: ?CheckEntitiesBasedOnFilter@idBotEntityManager@@QAAXAAVidBotEntityFilter@@@Z
// EA: 0x82B48B48, RVA: 0x00B48B48
void idBotEntityManager::CheckEntitiesBasedOnFilter(
        idBotEntityFilter& filter) {
    const int numEntities = entityList.Num();
    const int desiredFlags = filter.desiredEntityFlags;
    const int ignoredFlags = filter.ignoreEntityFlags;
    const int desiredType = filter.desiredEntityType;
    filter.PreCheckEntities(numEntities);
    for (int index = 0; index < numEntities; ++index) {
        const entInfo_t& info = entityList[index];
        if ((desiredType == 0 || (info.entityType & desiredType) != 0) &&
                (desiredFlags == 0 ||
                    (info.entityFlags & desiredFlags) != 0) &&
                (ignoredFlags == 0 ||
                    (info.entityFlags & ignoredFlags) == 0)) {
            filter.CheckEntity(index, info);
        }
    }
}

// Retail symbol: ?EntityExistsInList@idBotEntityManager@@ABA_NPBVidEntity@@@Z
// EA: 0x82B48C18, RVA: 0x00B48C18
bool idBotEntityManager::EntityExistsInList(
        const idEntity* const entity) const {
    if (g_entityManagerServices == nullptr) return false;
    for (int index = 0; index < entityList.Num(); ++index) {
        if (g_entityManagerServices->ResolveEntitySpawnId(
                entityList[index].entity.GetSpawnId()) == entity) {
            return true;
        }
    }
    return false;
}

// Retail symbol: ?GetEntityForIndex@idBotEntityListFilter@@QAAPBVidEntity@@H@Z
// EA: 0x82B48CC8, RVA: 0x00B48CC8
const idEntity* idBotEntityListFilter::GetEntityForIndex(
        const int index) const {
    if (g_entityManagerServices == nullptr || index < 0 ||
            index >= entitiesList.Num()) {
        return nullptr;
    }
    return g_entityManagerServices->ResolveEntitySpawnId(
        entitiesList[index].entity.GetSpawnId());
}

// Retail symbol: ??1idBotEntityManager@@QAA@XZ
// EA: 0x82B48D28, RVA: 0x00B48D28
idBotEntityManager::~idBotEntityManager() {
    entityList.Clear();
}

// Retail symbol: ?UnRegisterEntity@idBotEntityManager@@QAAXPBVidEntity@@@Z
// EA: 0x82B48DA0, RVA: 0x00B48DA0
void idBotEntityManager::UnRegisterEntity(const idEntity* const entity) {
    if (g_entityManagerServices != nullptr) {
        for (int index = 0; index < entityList.Num(); ++index) {
            if (g_entityManagerServices->ResolveEntitySpawnId(
                    entityList[index].entity.GetSpawnId()) == entity) {
                entityList.RemoveIndexFast(index);
                break;
            }
        }
    }
    ++currentEntityListHandle;
}

// Retail symbol: ?Reset@idBotEntityFilter@@UAAXXZ
// EA: 0x82B48EC0, RVA: 0x00B48EC0
void idBotEntityFilter::Reset() {
    desiredEntityType = 0;
    desiredEntityFlags = 0;
    ignoreEntityFlags = 0;
    bestEntityIndex = -1;
    bestEntity.Invalidate();
}

// Retail symbol: ?Reset@idBotEntityListFilter@@UAAXXZ
// EA: 0x82B48EE8, RVA: 0x00B48EE8
void idBotEntityListFilter::Reset() {
    idBotEntityFilter::Reset();
    entitiesList.Clear();
}

// Retail symbol: ??1idBotEntityFilter@@UAA@XZ
// EA: 0x82B48F18, RVA: 0x00B48F18
idBotEntityFilter::~idBotEntityFilter() {
    Reset();
}

// Retail symbol: ??0idBotEntityListFilter@@QAA@XZ
// EA: 0x82B48F50, RVA: 0x00B48F50
idBotEntityListFilter::idBotEntityListFilter()
    : idBotEntityFilter(), entitiesList(0) {
}

// Retail symbol: ??1idBotEntityListFilter@@UAA@XZ
// EA: 0x82B49018, RVA: 0x00B49018
idBotEntityListFilter::~idBotEntityListFilter() {
    entitiesList.Clear();
    Reset();
}

// Retail symbol: ??0idBotEntityManager@@QAA@XZ
// EA: 0x82B49128, RVA: 0x00B49128
idBotEntityManager::idBotEntityManager()
    : currentEntityListHandle(0), entityList() {
}

// Retail symbol: ?RegisterEntity@idBotEntityManager@@QAAXPBVidEntity@@HH@Z
// EA: 0x82B49240, RVA: 0x00B49240
void idBotEntityManager::RegisterEntity(const idEntity* const entity,
        const int entityType, const int entityFlags) {
    if (EntityExistsInList(entity)) return;
    entInfo_t info = {};
    info.active = true;
    info.entityType = entityType;
    info.entityFlags = entityFlags;
    info.entity.SetSpawnId(entity != nullptr &&
            g_entityManagerServices != nullptr
        ? g_entityManagerServices->GetEntitySpawnId(entity) : 0x1FFF);
    if (entityList.Append(info) >= 0) ++currentEntityListHandle;
}
