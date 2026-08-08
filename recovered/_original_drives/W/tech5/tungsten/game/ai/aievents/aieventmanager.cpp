
// ========================================================================
// ?GetEventType@idAIEventManager@@CAPBVidTypeInfo@@PBVidDeclAiEvent@@@Z
// EA  : 0x82A43020
// RVA : 0x00A43020
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

const idTypeInfo *__fastcall idAIEventManager::GetEventType(const idDeclAiEvent *eventDecl)
{
  idAIEvent::aiEventClass_t eventClass; // r11
  const idTypeInfo *result; // r3

  eventClass = eventDecl->eventClass;
  result = nullptr;
  if ( eventClass > AIEVENT_POSSESSION )
  {
    if ( eventClass > AIEVENT_PLAYER_GRENADE )
    {
      if ( eventClass > AIEVENT_PROJECTILE_IMPACT )
      {
        if ( eventClass == AIEVENT_DELAYED_VO )
          return &idAIEvent_DelayedVO::Type;
        return result;
      }
      if ( eventClass == AIEVENT_PROJECTILE_IMPACT )
        return &idAIEventSound::Type;
      if ( eventClass != AIEVENT_PLAYER_INTERACTION )
      {
        if ( eventClass != AIEVENT_RELOAD )
          return result;
        return &idAIEventSound::Type;
      }
    }
    else if ( eventClass != AIEVENT_PLAYER_GRENADE )
    {
      if ( eventClass > AIEVENT_DEPLOY_SOUND )
      {
        if ( eventClass != AIEVENT_VEHICLE_SOUND )
          return result;
      }
      else if ( eventClass != AIEVENT_DEPLOY_SOUND
             && eventClass != AIEVENT_DOOR_MOTION
             && eventClass != AIEVENT_DEAD_BODY_LAND )
      {
        return result;
      }
      return &idAIEventSound::Type;
    }
    return &idAIEventSphere::Type;
  }
  if ( eventClass == AIEVENT_POSSESSION )
    return &idAIEventSphere::Type;
  if ( eventClass <= AIEVENT_VEHICLE )
  {
    if ( eventClass == AIEVENT_VEHICLE )
      return &idAIEvent_Vehicle::Type;
    switch ( eventClass )
    {
      case AIEVENT_FOOTSTEP:
      case AIEVENT_GUNFIRE:
      case AIEVENT_EXPLOSION:
        return &idAIEventSound::Type;
      case AIEVENT_GUNFIRE|AIEVENT_FOOTSTEP:
      case AIEVENT_EXPLOSION|AIEVENT_FOOTSTEP:
      case AIEVENT_EXPLOSION|AIEVENT_GUNFIRE:
      case AIEVENT_EXPLOSION|AIEVENT_GUNFIRE|AIEVENT_FOOTSTEP:
      case AIEVENT_GRENADE|AIEVENT_FOOTSTEP:
      case AIEVENT_GRENADE|AIEVENT_GUNFIRE:
      case AIEVENT_GRENADE|AIEVENT_GUNFIRE|AIEVENT_FOOTSTEP:
      case AIEVENT_GRENADE|AIEVENT_EXPLOSION:
      case AIEVENT_GRENADE|AIEVENT_EXPLOSION|AIEVENT_FOOTSTEP:
      case AIEVENT_GRENADE|AIEVENT_EXPLOSION|AIEVENT_GUNFIRE:
      case AIEVENT_GRENADE|AIEVENT_EXPLOSION|AIEVENT_GUNFIRE|AIEVENT_FOOTSTEP:
        return result;
      case AIEVENT_GRENADE:
        result = &idAIEventProjectedSphere::Type;
        break;
      case AIEVENT_BODY:
        return &idAIEventSphere::Type;
    }
    return result;
  }
  if ( eventClass <= AIEVENT_INVESTIGATE )
  {
    if ( eventClass != AIEVENT_INVESTIGATE )
    {
      if ( eventClass == AIEVENT_AIM )
        return &idAIEvent_PlayerAim::Type;
      if ( eventClass == AIEVENT_VOICE )
        return &idAIEventVoice::Type;
      return result;
    }
    return &idAIEventSound::Type;
  }
  if ( eventClass == AIEVENT_PROJECTILE )
    return &idAIEventProjectile::Type;
  return result;
}


// ========================================================================
// ?GetEvent@idAIEventManager@@QAAPAVidAIEvent@@ABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@@Z
// EA  : 0x82A433B0
// RVA : 0x00A433B0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idAIEvent *__fastcall idAIEventManager::GetEvent(
        idAIEventManager *this,
        const idHandle<int,enum invalidAIEvent_t,-1> *handle)
{
  int lookupMask; // r6
  int v4; // r11
  int v5; // r9
  idAIEvent *result; // r3

  lookupMask = this->eventHash.lookupMask;
  v4 = this->eventHash.hash[this->eventHash.hashMask & lookupMask & handle->value];
  if ( v4 == -1 )
    return nullptr;
  v5 = v4;
  while ( 1 )
  {
    result = this->eventList.list[v5];
    if ( result->handle.value == handle->value )
      break;
    v4 = this->eventHash.indexChain[lookupMask & v4];
    v5 = v4;
    if ( v4 == -1 )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?FindPoolForEventDecl@idAIEventManager@@ABAPAVidAIEventPool@@PBVidDeclAiEvent@@@Z
// EA  : 0x82A43420
// RVA : 0x00A43420
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idAIEventPool *__fastcall idAIEventManager::FindPoolForEventDecl(
        idAIEventManager *this,
        const idDeclAiEvent *eventDecl)
{
  int v2; // r9
  const idTypeInfo *EventType; // r3
  int v4; // r8
  int v5; // r10
  int v6; // r9
  int i; // r11
  int v8; // r7

  EventType = idAIEventManager::GetEventType(eventDecl);
  v4 = *(_DWORD *)(v2 + 68);
  v5 = 0;
  if ( v4 <= 0 )
    return nullptr;
  v6 = *(_DWORD *)(v2 + 64);
  for ( i = 0; ; i += 4 )
  {
    v8 = *(_DWORD *)(i + v6);
    if ( v8 != 0 && *(const idTypeInfo **)(v8 + 8) == EventType )
      break;
    if ( ++v5 >= v4 )
      return nullptr;
  }
  return *(idAIEventPool **)(4 * v5 + v6);
}


// ========================================================================
// ?RemoveEvent@idAIEventManager@@AAAXH@Z
// EA  : 0x82A434B8
// RVA : 0x00A434B8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::RemoveEvent(idAIEventManager *this, int index)
{
  int v2; // r29
  idAIEvent *v5; // r28
  int num; // r11
  int v7; // r11
  idAIEventPool *PoolForEventDecl; // r3

  v2 = index;
  v5 = this->eventList.list[index];
  idHashIndex::RemoveIndexFast(this: &this->eventHash, key: this->eventHash.hashMask & v5->handle.value, index);
  if ( index >= 0 )
  {
    num = this->eventList.num;
    if ( index < num )
    {
      v7 = num - 1;
      this->eventList.num = v7;
      if ( index != v7 )
        this->eventList.list[v2] = this->eventList.list[v7];
    }
  }
  PoolForEventDecl = idAIEventManager::FindPoolForEventDecl(this, eventDecl: v5->eventDecl);
  if ( PoolForEventDecl != nullptr )
    idAIEventPool::FreeEvent(this: PoolForEventDecl, event: v5);
}


// ========================================================================
// ?RemoveReceiver@idAIEventManager@@QAAXPAVidEntity@@@Z
// EA  : 0x82A43548
// RVA : 0x00A43548
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::RemoveReceiver(idAIEventManager *this, idEntity *receiver)
{
  int v4; // r30
  idList<idEntityPtr<idEntity>,5> *p_receivers; // r29
  int v6; // r31
  idGameLocal *v7; // r10
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  int num; // r11
  int v12; // r11

  v4 = 0;
  if ( this->receivers.num > 0 )
  {
    p_receivers = &this->receivers;
    v6 = 0;
    v7 = gameLocal;
    while ( 1 )
    {
      value = p_receivers->list[v6].spawnId.value;
      if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v9 = v7->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v10 = idEntity::CastTo(c: v9);
        v7 = gameLocal;
      }
      else
      {
        v10 = nullptr;
      }
      if ( v10 == receiver )
        break;
      ++v4;
      ++v6;
      if ( v4 >= this->receivers.num )
        return;
    }
    if ( v4 >= 0 )
    {
      num = p_receivers->num;
      if ( v4 < num )
      {
        v12 = num - 1;
        p_receivers->num = v12;
        if ( v4 != v12 )
          p_receivers->list[v4].spawnId.value = p_receivers->list[v12].spawnId.value;
      }
    }
  }
}


// ========================================================================
// ?ShowStats@idAIEventManager@@QAAXXZ
// EA  : 0x82A43628
// RVA : 0x00A43628
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::ShowStats(idAIEventManager *this)
{
  int v2; // r30
  unsigned int v3; // r25
  int v4; // r29
  idTypeInfo *v5; // r3
  int v6; // r24
  int v7; // r23
  int v8; // r29
  int v9; // r30
  unsigned int Size; // r28
  idAIEventPool *v11; // r10
  int v12; // r27
  int num; // r26

  idLib::Printf(fmt: "AI Event Manager Stats:\n");
  v2 = 0;
  v3 = 4 * (this->eventPools.size + this->eventList.size + 20);
  if ( this->eventList.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = this->eventList.list[v4]->GetType(this: this->eventList.list[v4]);
      ++v2;
      ++v4;
      v3 += v5->size;
    }
    while ( v2 < this->eventList.num );
  }
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( this->eventPools.num > 0 )
  {
    v9 = 0;
    do
    {
      Size = idAIEventPool::GetSize(this: this->eventPools.list[v9]);
      v11 = this->eventPools.list[v9];
      v12 = v11->freeEvents.size;
      num = v11->freeEvents.num;
      idLib::Printf(
        fmt: "Pool '%s': %d bytes, # allocated = %d, # free = %d\n",
        v11->eventType->classname,
        Size,
        v12,
        num);
      ++v8;
      v3 += Size;
      v6 += v12;
      v7 += num;
      ++v9;
    }
    while ( v8 < this->eventPools.num );
  }
  idLib::Printf(fmt: "------------------------\n");
  idLib::Printf(fmt: "%d active events\n", this->eventList.num);
  idLib::Printf(fmt: "%d event pools\n", this->eventPools.num);
  idLib::Printf(fmt: "Total: %d KB, # allocated = %d, # free = %d\n", v3 >> 10, v6, v7);
}


// ========================================================================
// ?aievents_stats_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82A43770
// RVA : 0x00A43770
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall aievents_stats_f(const idCmdArgs *args)
{
  idAIEventManager::ShowStats(this: &gameLocal->aiEventManager);
}


// ========================================================================
// ??0idAIEventManager@@QAA@XZ
// EA  : 0x82A43A18
// RVA : 0x00A43A18
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idAIEventManager *__fastcall idAIEventManager::idAIEventManager(idAIEventManager *this)
{
  this->eventList.list = nullptr;
  this->eventList.granularity = 0;
  this->eventList.memTag = 5;
  this->eventList.listStatic = 0;
  this->eventList.size = 0;
  this->eventList.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->eventHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->eventHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->receivers.list = nullptr;
  this->receivers.granularity = 0;
  this->receivers.memTag = 5;
  this->receivers.listStatic = 0;
  this->receivers.size = 0;
  this->receivers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->receivers);
  this->eventPools.list = nullptr;
  this->eventPools.granularity = 0;
  this->eventPools.memTag = 5;
  this->eventPools.listStatic = 0;
  this->eventPools.size = 0;
  this->eventPools.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventPools);
  return this;
}


// ========================================================================
// __unwind$490004
// EA  : 0x82A43AB8
// RVA : 0x00A43AB8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490004()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$490005
// EA  : 0x82A43AE0
// RVA : 0x00A43AE0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490005()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$490006
// EA  : 0x82A43B0C
// RVA : 0x00A43B0C
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490006()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// ?RemoveEntityEvents@idAIEventManager@@QAAXPBVidEntity@@@Z
// EA  : 0x82A43B38
// RVA : 0x00A43B38
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::RemoveEntityEvents(idAIEventManager *this, const idEntity *ent)
{
  int v4; // r29
  int v5; // r30
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3

  v4 = this->eventList.num - 1;
  if ( v4 >= 0 )
  {
    v5 = v4;
    do
    {
      value = this->eventList.list[v5]->originator.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[this->eventList.list[v5]->originator.spawnId.value & 0x1FFF]) != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      if ( v8 == ent )
        idAIEventManager::RemoveEvent(this, index: v4);
      --v4;
      --v5;
    }
    while ( v4 >= 0 );
  }
}


// ========================================================================
// ?RemoveEntityEventsOfType@idAIEventManager@@QAAXPBVidEntity@@W4aiEventClass_t@idAIEvent@@@Z
// EA  : 0x82A43BD8
// RVA : 0x00A43BD8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::RemoveEntityEventsOfType(
        idAIEventManager *this,
        const idEntity *ent,
        const idAIEvent::aiEventClass_t eventClass)
{
  int v6; // r28
  int v7; // r31
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3

  v6 = this->eventList.num - 1;
  if ( v6 >= 0 )
  {
    v7 = v6;
    do
    {
      value = this->eventList.list[v7]->originator.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v9 = gameLocal->entities.ptr[this->eventList.list[v7]->originator.spawnId.value & 0x1FFF]) != nullptr )
      {
        v10 = idEntity::CastTo(c: v9);
      }
      else
      {
        v10 = nullptr;
      }
      if ( v10 == ent && eventClass == idAIEvent::GetEventClass(this: this->eventList.list[v7]) )
        idAIEventManager::RemoveEvent(this, index: v6);
      --v6;
      --v7;
    }
    while ( v6 >= 0 );
  }
}


// ========================================================================
// ?EnableEvents@idAIEventManager@@QAAXPBVidEntity@@H_N@Z
// EA  : 0x82A43C90
// RVA : 0x00A43C90
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::EnableEvents(
        idAIEventManager *this,
        const idEntity *ent,
        const int eventClassFlags,
        bool enable)
{
  int v8; // r28
  int v9; // r31
  int value; // r9
  idEntity *v11; // r3
  idEntity *v12; // r3

  v8 = this->eventList.num - 1;
  if ( v8 >= 0 )
  {
    v9 = v8;
    do
    {
      value = this->eventList.list[v9]->originator.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v11 = gameLocal->entities.ptr[this->eventList.list[v9]->originator.spawnId.value & 0x1FFF]) != nullptr )
      {
        v12 = idEntity::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      if ( v12 == ent && (idAIEvent::GetEventClass(this: this->eventList.list[v9]) & eventClassFlags) != 0 )
        this->eventList.list[v9]->enabled = enable;
      --v8;
      --v9;
    }
    while ( v8 >= 0 );
  }
}


// ========================================================================
// ?MapShutdown@idAIEventManager@@QAAXXZ
// EA  : 0x82A43D50
// RVA : 0x00A43D50
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::MapShutdown(idAIEventManager *this)
{
  int v2; // r29
  int v3; // r30
  idAIEvent *v4; // r5
  idAIEventPool *PoolForEventDecl; // r3
  int v6; // r29
  int v7; // r30
  idEntityPtr<idEntity> *list; // r4
  int *hash; // r3
  int *indexChain; // r3

  v2 = 0;
  if ( this->eventList.num > 0 )
  {
    v3 = 0;
    do
    {
      PoolForEventDecl = idAIEventManager::FindPoolForEventDecl(this, eventDecl: this->eventList.list[v3]->eventDecl);
      if ( PoolForEventDecl != nullptr )
      {
        idAIEventPool::FreeEvent(this: PoolForEventDecl, event: v4);
        this->eventList.list[v3] = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->eventList.num );
  }
  v6 = 0;
  if ( this->eventPools.num > 0 )
  {
    v7 = 0;
    do
    {
      if ( this->eventPools.list[v7] != nullptr )
      {
        ((void (__fastcall *)(idAIEventPool *, int))this->eventPools.list[v7]->dtr_idClass)(
          a1: this->eventPools.list[v7],
          a2: 1);
        this->eventPools.list[v7] = nullptr;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->eventPools.num );
  }
  idList<idCombatVolumeGroup *,5>::DeleteContents((idList<idCombatVolumeGroup *,5> *)this);
  if ( this->receivers.listStatic == 0 || this->receivers.listStatic == 2 )
  {
    list = this->receivers.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->receivers.list = nullptr;
    this->receivers.size = 0;
  }
  this->receivers.num = 0;
  hash = this->eventHash.hash;
  if ( hash != idHashIndex::INVALID_INDEX )
    memset(Dst: hash, Val: 255, Size: 4 * this->eventHash.hashSize);
  indexChain = this->eventHash.indexChain;
  if ( indexChain != idHashIndex::INVALID_INDEX )
    memset(Dst: indexChain, Val: 255, Size: 4 * this->eventHash.indexSize);
}


// ========================================================================
// ??1idAIEventManager@@QAA@XZ
// EA  : 0x82A43EB0
// RVA : 0x00A43EB0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::~idAIEventManager(idAIEventManager *this)
{
  idAIEventManager::MapShutdown(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventPools);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->receivers);
  idHashIndex::Free(this: &this->eventHash);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$490437
// EA  : 0x82A43F0C
// RVA : 0x00A43F0C
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490437()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490438
// EA  : 0x82A43F34
// RVA : 0x00A43F34
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490438()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$490439
// EA  : 0x82A43F60
// RVA : 0x00A43F60
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490439()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$490440
// EA  : 0x82A43F8C
// RVA : 0x00A43F8C
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490440()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// ?SetEventInstigator@idAIEventManager@@QAAXAAV?$idHandle@HW4invalidAIEvent_t@@$0?0@@PBVidEntity@@@Z
// EA  : 0x82A43FB8
// RVA : 0x00A43FB8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::SetEventInstigator(
        idAIEventManager *this,
        idHandle<int,enum invalidAIEvent_t,-1> *handle,
        const idEntity *instigator)
{
  idAIEvent *Event; // r3

  Event = idAIEventManager::GetEvent(this, handle);
  if ( Event != nullptr )
  {
    if ( instigator != nullptr )
      Event->instigator.spawnId.value = (gameLocal->spawnIds.ptr[instigator->entityNumber] << 13)
                                      | instigator->entityNumber;
    else
      Event->instigator.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?AddPool@idAIEventManager@@AAAPAVidAIEventPool@@PBVidDeclAiEvent@@@Z
// EA  : 0x82A44040
// RVA : 0x00A44040
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idAIEventPool *__fastcall idAIEventManager::AddPool(idAIEventManager *this, const idDeclAiEvent *eventDecl)
{
  idAIEventPool *PoolForEventDecl; // r30
  const idDeclAiEvent *v5; // r4
  const idTypeInfo *EventType; // r30
  idAIEventPool *v7; // r3
  idAIEventPool *v8; // r3
  idAIEventPool *v10; // [sp+50h] [-30h] BYREF

  if ( eventDecl->initialPoolSize <= 0 )
    return nullptr;
  PoolForEventDecl = idAIEventManager::FindPoolForEventDecl(this, eventDecl);
  if ( PoolForEventDecl == nullptr )
  {
    EventType = idAIEventManager::GetEventType(eventDecl: v5);
    v7 = (idAIEventPool *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                            size: 0x1Cu,
                            tag: TAG_NEW,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    v10 = v7;
    if ( v7 != nullptr )
      v8 = idAIEventPool::idAIEventPool(this: v7, eventType_: EventType);
    else
      v8 = nullptr;
    PoolForEventDecl = v8;
    v10 = v8;
    if ( v8 == nullptr )
      return nullptr;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->eventPools,
      obj: (const encounterGroupRole_t *)&v10);
  }
  PoolForEventDecl->initialPoolSize += eventDecl->initialPoolSize;
  return PoolForEventDecl;
}


// ========================================================================
// __unwind$490580
// EA  : 0x82A44110
// RVA : 0x00A44110
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall _unwind_490580(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Init@idAIEventManager@@QAAXXZ
// EA  : 0x82A44140
// RVA : 0x00A44140
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::Init(idAIEventManager *this, int a2, int a3, int a4, unsigned __int64 a5, __int64 a6)
{
  int v7; // r28
  int v8; // r29
  idDeclSource *v9; // r11
  const idDeclAiEvent *v10; // r4
  int v11; // r29
  int v12; // r30
  idAIEventPool **list; // r11
  idAIEventPool **v14; // r4
  unsigned int num; // r5
  idSort_Quick<idAIEventPool *,idSort_AIEventPoolsByNumAllocated> v16[16]; // [sp+50h] [-40h] BYREF

  v7 = 0;
  if ( idDeclAiEvent::resourceList.declSources.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = idDeclAiEvent::resourceList.declSources.list[v8];
      if ( v9 != nullptr && v9->name.str != nullptr )
      {
        v10 = (const idDeclAiEvent *)idDeclInfo::FindWithInheritance(
                                       this: &idDeclAiEvent::resourceList,
                                       name: v9->name.str,
                                       makeDefault: true);
        if ( v10 != nullptr )
          idAIEventManager::AddPool(this, eventDecl: v10);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < idDeclAiEvent::resourceList.declSources.num );
  }
  v11 = 0;
  if ( this->eventPools.num > 0 )
  {
    v12 = 0;
    do
    {
      list = this->eventPools.list;
      LODWORD(a6) = list[v12];
      if ( (_DWORD)a6 != 0 )
        idAIEventPool::AllocInitialPool(this: list[v12]);
      ++v11;
      ++v12;
    }
    while ( v11 < this->eventPools.num );
  }
  v16[0].__vftable = (idSort_Quick<idAIEventPool *,idSort_AIEventPoolsByNumAllocated>_vtbl *)&idSort_AIEventPoolsByNumAllocated::`vftable';
  v14 = this->eventPools.list;
  if ( v14 != nullptr )
  {
    num = this->eventPools.num;
    v16[1] = (idSort_Quick<idAIEventPool *,idSort_AIEventPoolsByNumAllocated>)this->eventPools.list;
    idSort_Quick<idAIEventPool *,idSort_AIEventPoolsByNumAllocated>::Sort(this: v16, base: v14, num, a4, a5, a6);
  }
}


// ========================================================================
// __unwind$490627
// EA  : 0x82A4423C
// RVA : 0x00A4423C
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490627()
{
  int v0; // r12

  idSort_AIEventPoolsByNumAllocated::~idSort_AIEventPoolsByNumAllocated(this: (idSort_AIEventPoolsByNumAllocated *)(v0 - 144 + 80));
}


// ========================================================================
// ?AllocEvent@idAIEventManager@@AAAPAVidAIEvent@@PBVidDeclAiEvent@@@Z
// EA  : 0x82A44268
// RVA : 0x00A44268
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idAIEventPool *__fastcall idAIEventManager::AllocEvent(idAIEventManager *this, const idDeclAiEvent *eventDecl)
{
  idAIEventManager *v2; // r5
  const idDeclAiEvent *v3; // r4
  idAIEventPool *result; // r3

  result = idAIEventManager::FindPoolForEventDecl(this, eventDecl);
  if ( result != nullptr )
    return (idAIEventPool *)idAIEventPool::AllocEvent(this: result);
  result = idAIEventManager::AddPool(this: v2, eventDecl: v3);
  if ( result != nullptr )
    return (idAIEventPool *)idAIEventPool::AllocEvent(this: result);
  return result;
}


// ========================================================================
// ?UpdateEvents@idAIEventManager@@QAAXH@Z
// EA  : 0x82A442C0
// RVA : 0x00A442C0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::UpdateEvents(idAIEventManager *this, int curTime)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  unsigned int DebugLevel; // r3
  int v7; // r29
  int v8; // r27
  int v9; // r28
  idAIEvent *v10; // r30
  int Duration; // r3
  char v12; // r11
  int v13; // r21
  idList<idEntityPtr<idEntity>,5> *p_receivers; // r25
  int v15; // r23
  int value; // r9
  idEntity *v17; // r3
  idEntity *v18; // r3
  idEntity *v19; // r29
  int num; // r11
  int v21; // r27
  int v22; // r28
  idAIEvent *v23; // r30
  int v24; // r3
  char v25; // r11
  int v26; // r10
  idEntity *v27; // r3
  idEntity *v28; // r3
  char v29; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v31; // r30
  int v32; // r3
  __int64 totalTicks; // r11
  __int64 v34; // r9
  idPLogScope v35; // [sp+58h] [-78h] BYREF

  RD_EventBegin(name: "idAIEventManager::UpdateEvents");
  LODWORD(v4) = "idAIEventManager::UpdateEvents";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v35, pl: &::pLog, gMask: v4, label: v5);
  DebugLevel = idAI2::GetDebugLevel();
  v7 = this->eventList.num - 1;
  v8 = ((DebugLevel == 0) + (DebugLevel >> 31) - 1) & aievents_show.valueInteger;
  if ( v7 >= 0 )
  {
    v9 = v7;
    do
    {
      v10 = this->eventList.list[v9];
      if ( curTime >= v10->startTime && v10->enabled )
      {
        if ( idAIEvent::GetDuration(this: this->eventList.list[v9]) == -1
          || (Duration = idAIEvent::GetDuration(this: v10), v12 = 1, curTime <= Duration + v10->startTime) )
        {
          v12 = 0;
        }
        if ( v12 != 0 || idAIEvent::Update(this: v10, curTime) == AIUPDATE_REMOVE )
        {
          idAIEventManager::RemoveEvent(this, index: v7);
        }
        else if ( v8 > 0 && v8 < 3 )
        {
          idAtlasResource::Print(this: (idDecl *)v10);
        }
      }
      --v7;
      --v9;
    }
    while ( v7 >= 0 );
  }
  v13 = this->receivers.num - 1;
  if ( v13 >= 0 )
  {
    p_receivers = &this->receivers;
    v15 = v13;
    do
    {
      value = p_receivers->list[v15].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v17 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && (v18 = idEntity::CastTo(c: v17), v19 = v18, v18 != nullptr) )
      {
        if ( v18->CanReceiveAIEvents(this: v18, a2: curTime) )
        {
          v21 = 0;
          if ( this->eventList.num > 0 )
          {
            v22 = 0;
            do
            {
              v23 = this->eventList.list[v22];
              if ( curTime >= v23->startTime )
              {
                if ( idAIEvent::GetDuration(this: this->eventList.list[v22]) == -1
                  || (v24 = idAIEvent::GetDuration(this: v23), v25 = 1, curTime <= v24 + v23->startTime) )
                {
                  v25 = 0;
                }
                if ( v25 == 0 )
                {
                  v26 = v23->originator.spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
                    && (v27 = gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr )
                  {
                    v28 = idEntity::CastTo(c: v27);
                  }
                  else
                  {
                    v28 = nullptr;
                  }
                  if ( v28 != v19 && v19->RespondsToAIEvent(this: v19, a2: v23) )
                  {
                    idAIEvent::IsTouching(this: (idResource *)v23);
                    if ( v29 != 0 )
                      v19->OnAIEvent(this: v19, a2: v23);
                  }
                }
              }
              ++v21;
              ++v22;
            }
            while ( v21 < this->eventList.num );
          }
        }
      }
      else
      {
        num = this->receivers.num;
        if ( v13 < num )
        {
          this->receivers.num = num - 1;
          if ( v13 != num - 1 )
            p_receivers->list[v15].spawnId.value = p_receivers->list[num - 1].spawnId.value;
        }
      }
      --v13;
      --v15;
    }
    while ( v13 >= 0 );
  }
  if ( v35.logIndex >= 0 )
  {
    pLog = v35.pLog;
    v31 = &v35.pLog->logEntries.list[v35.logIndex];
    v32 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v31->totalTicks;
    HIDWORD(totalTicks) = v31->parent;
    LODWORD(v34) = v32 - totalTicks;
    v31->totalTicks = v34;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490789
// EA  : 0x82A44630
// RVA : 0x00A44630
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490789()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$490790
// EA  : 0x82A44658
// RVA : 0x00A44658
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490790()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 88));
}


// ========================================================================
// ?AddEvent@idAIEventManager@@AAAPAVidAIEvent@@PBVidDeclAiEvent@@HH@Z
// EA  : 0x82A44688
// RVA : 0x00A44688
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idAIEventPool *__fastcall idAIEventManager::AddEvent(
        idAIEventManager *this,
        const idDeclAiEvent *eventDecl,
        const int curTime,
        const int delay)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  const idTypeInfo *EventType; // r3
  int typeNum; // r11
  char v12; // r11
  bool v13; // zf
  unsigned __int64 v14; // r6
  const char *v15; // r7
  idAIEventPool *v16; // r30
  int v17; // r25
  unsigned __int64 v18; // r6
  const char *v19; // r7
  idAIEventPool *v21; // [sp+50h] [-70h] BYREF
  idPLogScope v22; // [sp+58h] [-68h] BYREF
  idPLogScope v23[12]; // [sp+60h] [-60h] BYREF

  RD_EventBegin(name: "idAIEventManager::AddEvent");
  LODWORD(v8) = "idAIEventManager::AddEvent";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: &v22, pl: &pLog, gMask: v8, label: v9);
  if ( g_stopTime.valueInteger != 0 && idAccolade::Count(this: &clientGame->gameTimeManager) > 10 )
    goto LABEL_12;
  if ( eventDecl == nullptr )
    goto LABEL_12;
  EventType = idAIEventManager::GetEventType(eventDecl);
  if ( EventType == nullptr )
    goto LABEL_12;
  typeNum = EventType->typeNum;
  if ( typeNum < idAIEvent::Type.typeNum || (v13 = typeNum <= idAIEvent::Type.lastChild, v12 = 1, !v13) )
    v12 = 0;
  if ( v12 != 0 )
  {
    RD_EventBegin(name: "idAIEventManager::AddEvent - create");
    LODWORD(v14) = "idAIEventManager::AddEvent - create";
    HIDWORD(v14) = 2;
    idPLogScope::idPLogScope(this: v23, pl: &pLog, gMask: v14, label: v15);
    v16 = idAIEventManager::AllocEvent(this, eventDecl);
    v21 = v16;
    if ( v16 != nullptr )
    {
      idPLogScope::~idPLogScope(this: v23);
      RD_EventEnd();
      v17 = idList<idAnimWebBlendTree *,5>::Append(
              (idList<enum encounterGroupRole_t,5> *)this,
              obj: (const encounterGroupRole_t *)&v21);
      RD_EventBegin(name: "idAIEventManager::AddEvent - hash");
      LODWORD(v18) = "idAIEventManager::AddEvent - hash";
      HIDWORD(v18) = 2;
      idPLogScope::idPLogScope(this: v23, pl: &pLog, gMask: v18, label: v19);
      idHashIndex::InsertIndex(
        this: &this->eventHash,
        key: this->eventHash.hashMask & v16[1].freeEvents.size,
        index: v17);
      idPLogScope::~idPLogScope(this: v23);
      RD_EventEnd();
      v16[1].freeEvents.num = curTime + delay;
      idPLogScope::~idPLogScope(this: &v22);
      RD_EventEnd();
      return v16;
    }
    idPLogScope::~idPLogScope(this: v23);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: &v22);
  }
  else
  {
LABEL_12:
    idPLogScope::~idPLogScope(this: &v22);
  }
  RD_EventEnd();
  return nullptr;
}


// ========================================================================
// __unwind$490994
// EA  : 0x82A4485C
// RVA : 0x00A4485C
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490994()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 104));
}


// ========================================================================
// __unwind$490995
// EA  : 0x82A44884
// RVA : 0x00A44884
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490995()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$490996
// EA  : 0x82A448AC
// RVA : 0x00A448AC
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490996()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 105));
}


// ========================================================================
// __unwind$490997
// EA  : 0x82A448D4
// RVA : 0x00A448D4
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490997()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$490998
// EA  : 0x82A448FC
// RVA : 0x00A448FC
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490998()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 106));
}


// ========================================================================
// __unwind$490999
// EA  : 0x82A44924
// RVA : 0x00A44924
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_490999()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 96));
}


// ========================================================================
// ?AddEvent@idAIEventManager@@QAA?AV?$idHandle@HW4invalidAIEvent_t@@$0?0@@PBVidDeclAiEvent@@HPBVidEntity@@1ABVidVec3@@H@Z
// EA  : 0x82A44958
// RVA : 0x00A44958
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idAIEventManager *__fastcall idAIEventManager::AddEvent(
        idAIEventManager *this,
        idAIEventManager *result,
        const idDeclAiEvent *eventDecl,
        int curTime,
        idEntity *originator,
        const idEntity *instigator,
        const idVec3 *origin,
        int delay)
{
  unsigned __int64 v16; // r6
  const char *v17; // r7
  idAIEventPool *v18; // r29
  idPhysics *Physics; // r3
  const idVec3 *v20; // r7
  char *v21; // r28
  char *data; // r27
  const char *str; // r30
  int v24; // r3
  idPLogScope v26[14]; // [sp+50h] [-70h] BYREF

  RD_EventBegin(name: "idAIEventManager::AddEvent");
  LODWORD(v16) = "idAIEventManager::AddEvent";
  HIDWORD(v16) = 2;
  idPLogScope::idPLogScope(this: v26, pl: &pLog, gMask: v16, label: v17);
  if ( eventDecl != nullptr && (v18 = idAIEventManager::AddEvent(this: result, eventDecl, curTime, delay)) != nullptr )
  {
    if ( eventDecl->attached )
    {
      Physics = idEntity::GetPhysics(this: originator);
      v20 = Physics->GetOrigin(this: Physics, a2: 0);
    }
    else
    {
      v20 = origin;
    }
    idAIEvent::Init(this: (idAIEvent *)v18, decl: eventDecl, originator, instigator, origin: v20);
    if ( aievents_print.valueInteger > 0 )
    {
      v21 = "< none >";
      if ( idAIEvent::GetInstigator(this: (idAIEvent *)v18) != nullptr )
        data = idAIEvent::GetInstigator(this: (idAIEvent *)v18)->name.data;
      else
        data = "< none >";
      if ( idAIEvent::GetOriginator(this: (idAIEvent *)v18) != nullptr )
        v21 = idAIEvent::GetOriginator(this: (idAIEvent *)v18)->name.data;
      str = eventDecl->name.str;
      v24 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idLib::Printf(fmt: "^5EVENT(%d): %s sent %s, instigator %s\n", v24, v21, str, data);
    }
    if ( idAI2::GetDebugLevel() > 0 && aievents_show.valueInteger > 2 )
      idAtlasResource::Print(this: (idDecl *)v18);
    this->eventList.list = (idAIEvent **)v18[1].freeEvents.size;
    idPLogScope::~idPLogScope(this: v26);
  }
  else
  {
    this->eventList.list = (idAIEvent **)-1;
    idPLogScope::~idPLogScope(this: v26);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$491127
// EA  : 0x82A44B30
// RVA : 0x00A44B30
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_491127()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$491128
// EA  : 0x82A44B58
// RVA : 0x00A44B58
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_491128()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?RemoveEvent@idAIEventManager@@QAAXABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@@Z
// EA  : 0x82A44B88
// RVA : 0x00A44B88
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::RemoveEvent(
        idAIEventManager *this,
        const idHandle<int,enum invalidAIEvent_t,-1> *handle)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v6; // r4
  int v7; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v9; // r30
  int v10; // r3
  __int64 totalTicks; // r11
  __int64 v12; // r9
  idPLogScope v13; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idAIEventManager::RemoveEvent");
  LODWORD(v4) = "idAIEventManager::RemoveEvent";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v13, pl: &::pLog, gMask: v4, label: v5);
  v6 = this->eventList.num - 1;
  if ( v6 >= 0 )
  {
    v7 = v6;
    while ( this->eventList.list[v7]->handle.value != handle->value )
    {
      --v6;
      --v7;
      if ( v6 < 0 )
        goto LABEL_7;
    }
    idAIEventManager::RemoveEvent(this, index: v6);
  }
LABEL_7:
  if ( v13.logIndex >= 0 )
  {
    pLog = v13.pLog;
    v9 = &v13.pLog->logEntries.list[v13.logIndex];
    v10 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v9->totalTicks;
    HIDWORD(totalTicks) = v9->parent;
    LODWORD(v12) = v10 - totalTicks;
    v9->totalTicks = v12;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$491223
// EA  : 0x82A44C50
// RVA : 0x00A44C50
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_491223()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$491224
// EA  : 0x82A44C78
// RVA : 0x00A44C78
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void _unwind_491224()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ?AddReceiver@idAIEventManager@@QAAXPAVidEntity@@@Z
// EA  : 0x82A44CA0
// RVA : 0x00A44CA0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __fastcall idAIEventManager::AddReceiver(idAIEventManager *this, idEntity *receiver)
{
  int v2; // r7
  idList<idEntityPtr<idEntity>,58> *p_receivers; // r3
  int v4; // r10
  int num; // r9
  int v6; // r11
  idEntityPtr<idEntity> v7; // [sp+50h] [-10h] BYREF

  if ( receiver != nullptr )
    v2 = (gameLocal->spawnIds.ptr[receiver->entityNumber] << 13) | receiver->entityNumber;
  else
    v2 = 0x1FFF;
  p_receivers = (idList<idEntityPtr<idEntity>,58> *)&this->receivers;
  v7.spawnId.value = v2;
  v4 = 0;
  num = p_receivers->num;
  if ( num <= 0 )
    goto LABEL_10;
  v6 = 0;
  while ( p_receivers->list[v6].spawnId.value != v2 )
  {
    ++v4;
    ++v6;
    if ( v4 >= num )
      goto LABEL_10;
  }
  if ( v4 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_receivers, obj: &v7);
}


// ========================================================================
// `dynamic initializer for 'aievents_show''
// EA  : 0x83366DF0
// RVA : 0x01366DF0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aievents_show__()
{
  idCVar::idCVar(
    this: &aievents_show,
    name: "aievents_show",
    value: "0",
    flags: 2,
    description: "1 to show ai event origins, 2 to show event bounds, > 2 = millseconds to show event bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aievents_show__);
}


// ========================================================================
// `dynamic initializer for 'aievents_print''
// EA  : 0x83366E48
// RVA : 0x01366E48
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aievents_print__()
{
  idCVar::idCVar(
    this: &aievents_print,
    name: "aievents_print",
    value: "0",
    flags: 2,
    description: "1 to print AI events to the console.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aievents_print__);
}


// ========================================================================
// `dynamic initializer for 'aievents_stats_v''
// EA  : 0x83366EA0
// RVA : 0x01366EA0
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventmanager.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__aievents_stats_v__()
{
  return idCommandLink::idCommandLink(
           this: &aievents_stats_v,
           cmdName: "aievents_stats",
           function: aievents_stats_f,
           description: "show stats for AI event manager",
           argCompletion: nullptr);
}

