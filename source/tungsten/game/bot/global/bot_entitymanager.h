#pragma once

#include "../bot_worldstate.h"
#include "../../../../shared/idlib/containers/staticlist.h"

class idEntity;

class idBotEntityManagerServices {
public:
    virtual ~idBotEntityManagerServices() = default;
    virtual int GetEntitySpawnId(const idEntity* entity) const = 0;
    virtual const idEntity* ResolveEntitySpawnId(int spawnId) const = 0;
};

void Tungsten_SetBotEntityManagerServices(
    idBotEntityManagerServices* services);

class idBotEntityManager {
public:
    idBotEntityManager();
    ~idBotEntityManager();

    void CheckEntitiesBasedOnFilter(idBotEntityFilter& filter);
    void RegisterEntity(const idEntity* entity, int entityType,
        int entityFlags);
    void UnRegisterEntity(const idEntity* entity);

    int GetCurrentEntityListHandle() const {
        return currentEntityListHandle;
    }
    int GetEntityCount() const { return entityList.Num(); }
    const entInfo_t& GetEntityInfo(int index) const {
        return entityList[index];
    }

private:
    bool EntityExistsInList(const idEntity* entity) const;

    int currentEntityListHandle;
    idStaticList<entInfo_t, 64> entityList;
};
