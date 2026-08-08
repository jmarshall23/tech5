
// ========================================================================
// ?Init@idBotEntityFilter@@UAAXHHH@Z
// EA  : 0x82B48B38
// RVA : 0x00B48B38
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityFilter::Init(
        idBotEntityFilter *this,
        int desiredEntType,
        int desiredEntFlags,
        int ignoreEntFlags)
{
  this->desiredEntityType = desiredEntType;
  this->desiredEntityFlags = desiredEntFlags;
  this->ignoreEntityFlags = ignoreEntFlags;
}


// ========================================================================
// ?CheckEntitiesBasedOnFilter@idBotEntityManager@@QAAXAAVidBotEntityFilter@@@Z
// EA  : 0x82B48B48
// RVA : 0x00B48B48
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityManager::CheckEntitiesBasedOnFilter(idBotEntityManager *this, idBotEntityFilter *filter)
{
  int num; // r27
  int desiredEntityFlags; // r25
  int ignoreEntityFlags; // r24
  int desiredEntityType; // r26
  int v8; // r30
  int v9; // r29
  entInfo_t *v10; // r5

  num = this->entityList.num;
  desiredEntityFlags = filter->desiredEntityFlags;
  ignoreEntityFlags = filter->ignoreEntityFlags;
  desiredEntityType = filter->desiredEntityType;
  filter->PreCheckEntities(this: filter, a2: num);
  v8 = 0;
  if ( num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &this->entityList.list[v9];
      if ( (desiredEntityType == 0 || (v10->entityType & desiredEntityType) != 0)
        && (desiredEntityFlags == 0 || (v10->entityFlags & desiredEntityFlags) != 0)
        && (ignoreEntityFlags == 0 || (v10->entityFlags & ignoreEntityFlags) == 0) )
      {
        filter->CheckEntity(this: filter, a2: v8, a3: v10);
      }
      ++v8;
      ++v9;
    }
    while ( v8 < num );
  }
}


// ========================================================================
// ?EntityExistsInList@idBotEntityManager@@ABA_NPBVidEntity@@@Z
// EA  : 0x82B48C18
// RVA : 0x00B48C18
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

int __fastcall idBotEntityManager::EntityExistsInList(idBotEntityManager *this, const idEntity *entity)
{
  int num; // r27
  int v5; // r29
  int v6; // r31
  idGameLocal *v7; // r9
  int value; // r10
  idEntity *v9; // r3
  idEntity *v10; // r3

  num = this->entityList.num;
  v5 = 0;
  if ( num <= 0 )
    return 0;
  v6 = 0;
  v7 = gameLocal;
  while ( 1 )
  {
    value = this->entityList.list[v6].entity.spawnId.value;
    if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = v7->entities.ptr[this->entityList.list[v6].entity.spawnId.value & 0x1FFF]) != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
      v7 = gameLocal;
    }
    else
    {
      v10 = nullptr;
    }
    if ( v10 == entity )
      break;
    ++v5;
    ++v6;
    if ( v5 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetEntityForIndex@idBotEntityListFilter@@QAAPBVidEntity@@H@Z
// EA  : 0x82B48CC8
// RVA : 0x00B48CC8
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

const idEntity *__fastcall idBotEntityListFilter::GetEntityForIndex(idBotEntityListFilter *this, const int index)
{
  int value; // r8
  idEntity *v3; // r3

  value = this->entitiesList.list[index].entity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[this->entitiesList.list[index].entity.spawnId.value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v3);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??1idBotEntityManager@@QAA@XZ
// EA  : 0x82B48D28
// RVA : 0x00B48D28
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityManager::~idBotEntityManager(idBotEntityManager *this)
{
  idList<idVehicleState *,5> *p_entityList; // r30

  p_entityList = (idList<idVehicleState *,5> *)&this->entityList;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entityList);
  idList<idThread *,58>::Clear(this: p_entityList);
}


// ========================================================================
// __unwind$488023
// EA  : 0x82B48D70
// RVA : 0x00B48D70
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void _unwind_488023()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?UnRegisterEntity@idBotEntityManager@@QAAXPBVidEntity@@@Z
// EA  : 0x82B48DA0
// RVA : 0x00B48DA0
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityManager::UnRegisterEntity(idBotEntityManager *this, const idEntity *entity)
{
  int num; // r27
  int v5; // r29
  idStaticList<entInfo_t,64> *p_entityList; // r30
  int v7; // r31
  idGameLocal *v8; // r9
  int value; // r10
  idEntity *v10; // r3
  idEntity *v11; // r3
  int v12; // r11
  int v13; // r11
  int v14; // r11
  int v15; // r10

  num = this->entityList.num;
  v5 = 0;
  if ( num > 0 )
  {
    p_entityList = &this->entityList;
    v7 = 0;
    v8 = gameLocal;
    while ( 1 )
    {
      value = p_entityList->list[v7].entity.spawnId.value;
      if ( v8->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v10 = v8->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        v8 = gameLocal;
      }
      else
      {
        v11 = nullptr;
      }
      if ( v11 == entity )
        break;
      ++v5;
      ++v7;
      if ( v5 >= num )
      {
        ++this->currentEntityListHandle;
        return;
      }
    }
    if ( v5 >= 0 )
    {
      v12 = p_entityList->num;
      if ( v5 < v12 )
      {
        v13 = v12 - 1;
        p_entityList->num = v13;
        if ( v5 != v13 )
        {
          v14 = (int)&p_entityList->list[v13];
          v15 = (int)&p_entityList->list[v5];
          *(_BYTE *)v15 = *(_BYTE *)v14;
          *(_DWORD *)(v15 + 4) = *(_DWORD *)(v14 + 4);
          *(_DWORD *)(v15 + 8) = *(_DWORD *)(v14 + 8);
          *(_DWORD *)(v15 + 12) = *(_DWORD *)(v14 + 12);
        }
      }
    }
  }
  ++this->currentEntityListHandle;
}


// ========================================================================
// ?Reset@idBotEntityFilter@@UAAXXZ
// EA  : 0x82B48EC0
// RVA : 0x00B48EC0
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityFilter::Reset(idBotEntityFilter *this)
{
  this->desiredEntityType = 0;
  this->desiredEntityFlags = 0;
  this->ignoreEntityFlags = 0;
  this->bestEntityIndex = -1;
  this->bestEntity.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?Reset@idBotEntityListFilter@@UAAXXZ
// EA  : 0x82B48EE8
// RVA : 0x00B48EE8
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityListFilter::Reset(idBotEntityListFilter *this)
{
  this->desiredEntityType = 0;
  this->desiredEntityFlags = 0;
  this->ignoreEntityFlags = 0;
  this->bestEntityIndex = -1;
  this->bestEntity.spawnId.value = 0x1FFF;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entitiesList);
}


// ========================================================================
// ??1idBotEntityFilter@@UAA@XZ
// EA  : 0x82B48F18
// RVA : 0x00B48F18
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityFilter::~idBotEntityFilter(idBotEntityFilter *this)
{
  this->desiredEntityType = 0;
  this->__vftable = (idBotEntityFilter_vtbl *)&idBotEntityFilter::`vftable';
  this->desiredEntityFlags = 0;
  this->ignoreEntityFlags = 0;
  this->bestEntityIndex = -1;
  this->bestEntity.spawnId.value = 0x1FFF;
}


// ========================================================================
// ??0idBotEntityListFilter@@QAA@XZ
// EA  : 0x82B48F50
// RVA : 0x00B48F50
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

idBotEntityListFilter *__fastcall idBotEntityListFilter::idBotEntityListFilter(idBotEntityListFilter *this)
{
  this->desiredEntityType = 0;
  this->bestEntityIndex = -1;
  this->desiredEntityFlags = 0;
  this->ignoreEntityFlags = 0;
  this->bestEntity.spawnId.value = 0x1FFF;
  this->__vftable = (idBotEntityListFilter_vtbl *)&idBotEntityListFilter::`vftable';
  this->entitiesList.list = nullptr;
  this->entitiesList.granularity = 0;
  this->entitiesList.memTag = 5;
  this->entitiesList.listStatic = 0;
  this->entitiesList.size = 0;
  this->entitiesList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entitiesList);
  return this;
}


// ========================================================================
// __unwind$488439
// EA  : 0x82B48FE4
// RVA : 0x00B48FE4
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void _unwind_488439()
{
  int v0; // r12

  idBotEntityFilter::~idBotEntityFilter(this: *(idBotEntityFilter **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idBotEntityListFilter@@UAA@XZ
// EA  : 0x82B49018
// RVA : 0x00B49018
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityListFilter::~idBotEntityListFilter(idBotEntityListFilter *this)
{
  idList<idVehicleState *,5> *p_entitiesList; // r29

  this->__vftable = (idBotEntityListFilter_vtbl *)&idBotEntityListFilter::`vftable';
  p_entitiesList = (idList<idVehicleState *,5> *)&this->entitiesList;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entitiesList);
  idList<idThread *,58>::Clear(this: p_entitiesList);
  this->desiredEntityType = 0;
  this->__vftable = (idBotEntityListFilter_vtbl *)&idBotEntityFilter::`vftable';
  this->desiredEntityFlags = 0;
  this->ignoreEntityFlags = 0;
  this->bestEntityIndex = -1;
  this->bestEntity.spawnId.value = 0x1FFF;
}


// ========================================================================
// __unwind$488492
// EA  : 0x82B49084
// RVA : 0x00B49084
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void _unwind_488492()
{
  int v0; // r12

  idBotEntityFilter::~idBotEntityFilter(this: *(idBotEntityFilter **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488493
// EA  : 0x82B490AC
// RVA : 0x00B490AC
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void _unwind_488493()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// ??0idBotEntityManager@@QAA@XZ
// EA  : 0x82B49128
// RVA : 0x00B49128
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

idBotEntityManager *__fastcall idBotEntityManager::idBotEntityManager(idBotEntityManager *this)
{
  this->currentEntityListHandle = 0;
  idStaticList<entInfo_t,64>::idStaticList<entInfo_t,64>(this: &this->entityList);
  return this;
}


// ========================================================================
// ?RegisterEntity@idBotEntityManager@@QAAXPBVidEntity@@HH@Z
// EA  : 0x82B49240
// RVA : 0x00B49240
// PDB : w:\tech5\tungsten\game\bot\global\bot_entitymanager.cpp
// ========================================================================

void __fastcall idBotEntityManager::RegisterEntity(
        idBotEntityManager *this,
        const idEntity *entity,
        int entityType,
        int entityFlags)
{
  entInfo_t v8; // [sp+50h] [-40h] BYREF

  if ( (unsigned __int8)idBotEntityManager::EntityExistsInList(this, entity) == 0 )
  {
    v8.entityType = entityType;
    v8.entityFlags = entityFlags;
    v8.active = true;
    if ( entity != nullptr )
      v8.entity.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
    else
      v8.entity.spawnId.value = 0x1FFF;
    idList<entInfo_t,5>::Append(this: &this->entityList, obj: &v8);
    ++this->currentEntityListHandle;
  }
}

