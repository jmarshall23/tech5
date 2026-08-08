
// ========================================================================
// ?OnNotifyProgressionOwner@idProgressionEntity@@MAAXXZ
// EA  : 0x82C99DA8
// RVA : 0x00C99DA8
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void __fastcall idProgressionEntity::OnNotifyProgressionOwner(idProgressionEntity *this)
{
  this->retainedState->targetState = this->defaultState;
  this->waitUntilNextMapLoad = true;
}


// ========================================================================
// ?EnableEntity@idProgressionEntity@@AAAXPAVidEntity@@_N@Z
// EA  : 0x82C99DC0
// RVA : 0x00C99DC0
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void __fastcall idProgressionEntity::EnableEntity(idProgressionEntity *this, idEntity *entity, const bool enable)
{
  idPhysics *Physics; // r3
  idPhysics *v5; // r3

  if ( entity != nullptr )
  {
    if ( enable )
    {
      idEntity::BecomeActive(this: entity, flags: 1);
      idEntity::BecomeActive(this: entity, flags: 2);
      Physics = idEntity::GetPhysics(this: entity);
      Physics->EnableClip(this: Physics);
      entity->Show(this: entity);
    }
    else
    {
      idEntity::BecomeInactive(this: entity, flags: 1);
      idEntity::BecomeInactive(this: entity, flags: 2);
      v5 = idEntity::GetPhysics(this: entity);
      v5->DisableClip(this: v5);
      entity->Hide_2(this: entity);
    }
  }
}


// ========================================================================
// ?EnableState@idProgressionEntity@@AAAXH_N@Z
// EA  : 0x82C99E78
// RVA : 0x00C99E78
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void __fastcall idProgressionEntity::EnableState(idProgressionEntity *this, const int state, bool enable)
{
  idList<idEntity *,5> *v3; // r31
  idProgressionEntity::idProgressionParms *v4; // r11
  idList<idEntityPtr<idEntity>,5> *p_entities; // r27
  idList<idEntityPtr<idTrigger>,5> *p_triggers; // r25
  int v9; // r30
  int v10; // r29
  int v11; // r30
  int v12; // r31
  int value; // r9
  idEntity *v14; // r3
  idEntity *v15; // r4
  int v16; // r30
  int v17; // r31
  int v18; // r9
  int v19; // r11
  idTrigger *v20; // r3
  idEventArg *v21; // r4
  const idEventDef *v22; // r5
  idTrigger *v23; // r3
  idEventReceiver v24[8]; // [sp+50h] [-60h] BYREF

  v3 = &this->spawnedEntities.list[state];
  v4 = &this->progressionParms.list[state];
  p_entities = &v4->entities;
  p_triggers = &v4->triggers;
  v9 = 0;
  if ( v3->num > 0 )
  {
    v10 = 0;
    do
    {
      idProgressionEntity::EnableEntity(this, entity: v3->list[v10], enable);
      ++v9;
      ++v10;
    }
    while ( v9 < v3->num );
  }
  v11 = 0;
  if ( p_entities->num > 0 )
  {
    v12 = 0;
    do
    {
      value = p_entities->list[v12].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v15 = idEntity::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      idProgressionEntity::EnableEntity(this, entity: v15, enable);
      ++v11;
      ++v12;
    }
    while ( v11 < p_entities->num );
  }
  v16 = 0;
  if ( p_triggers->num > 0 )
  {
    v17 = 0;
    do
    {
      v18 = p_triggers->list[v17].spawnId.value;
      v19 = v18 & 0x1FFF;
      if ( enable )
      {
        if ( gameLocal->spawnIds.ptr[v19] == v18 >> 13 && (v20 = (idTrigger *)gameLocal->entities.ptr[v19]) != nullptr )
        {
          v21 = (idEventArg *)idTrigger::CastTo(c: v20);
          v22 = &EV_Activate;
        }
        else
        {
          v21 = nullptr;
          v22 = &EV_Activate;
        }
      }
      else
      {
        if ( gameLocal->spawnIds.ptr[v19] == v18 >> 13 && (v23 = (idTrigger *)gameLocal->entities.ptr[v19]) != nullptr )
          v21 = (idEventArg *)idTrigger::CastTo(c: v23);
        else
          v21 = nullptr;
        v22 = &EV_Deactivate;
      }
      idEventReceiver::ProcessEvent(this: v24, result: v21, ev: v22);
      ++v16;
      ++v17;
    }
    while ( v16 < p_triggers->num );
  }
}


// ========================================================================
// ?GotoState@idProgressionEntity@@AAAXH_N@Z
// EA  : 0x82C9A058
// RVA : 0x00C9A058
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void __fastcall idProgressionEntity::GotoState(idProgressionEntity *this, int requestedState, bool force)
{
  int num; // r11
  int v5; // r30
  idEntityRetainedState *retainedState; // r9
  int state; // r4
  __int64 v8; // r10

  if ( requestedState >= 0 )
  {
    num = this->progressionParms.num;
    v5 = requestedState;
    if ( requestedState == num )
    {
      v5 = 0;
      if ( !this->wrappable )
        v5 = num - 1;
    }
    if ( force )
      goto LABEL_11;
    retainedState = this->retainedState;
    if ( retainedState->state == v5 )
      return;
    if ( this->preSpawnAll || v5 == this->spawnedState || this->progressionParms.list[v5].entityDefs.num == 0 )
    {
LABEL_11:
      state = this->retainedState->state;
      if ( state != -1 )
        idProgressionEntity::EnableState(this, state, enable: false);
      idProgressionEntity::EnableState(this, state: v5, enable: true);
      HIDWORD(v8) = this->retainedState;
      LODWORD(v8) = 0;
      *(_DWORD *)(HIDWORD(v8) + 32) = v5;
      this->retainedState->targetState = v5 + 1;
      this->retainedState->timeStarted = v8;
    }
    else
    {
      retainedState->targetState = v5;
    }
  }
}


// ========================================================================
// ?OnActivate@idProgressionEntity@@MAAXPAVidEntity@@@Z
// EA  : 0x82C9A158
// RVA : 0x00C9A158
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void __fastcall idProgressionEntity::OnActivate(idProgressionEntity *this, idEntity *activator)
{
  int state; // r11

  if ( !this->waitUntilNextMapLoad )
  {
    state = this->retainedState->state;
    if ( this->progressionParms.list[state].incrementsOnOwnerTrigger )
      idProgressionEntity::GotoState(this, requestedState: state + 1, force: false);
  }
}


// ========================================================================
// ?Think@idProgressionEntity@@UAAXXZ
// EA  : 0x82C9A260
// RVA : 0x00C9A260
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProgressionEntity::Think(idProgressionEntity *this, int a2, int a3, int a4, int a5, __int64 a6)
{
  int v7; // r25
  int v8; // r28
  int v9; // r27
  int v10; // r29
  int value; // r9
  idEntity *v12; // r3
  idEntity *v13; // r4
  idGameLayerManager *p_gameLayerManager; // r29
  idEntityRetainedState *RetainedEntityState; // r3
  __int64 v16; // r10
  int state; // r9
  int defaultState; // r4
  int v19; // r11
  double timeAtState; // fp0
  int v21; // r10
  idEventReceiver v22[2]; // [sp+60h] [-A0h] BYREF
  idEntityRetainedState v23[2]; // [sp+80h] [-80h] BYREF

  if ( this->retainedState == nullptr )
  {
    if ( this->initiallyHideEntities )
    {
      v7 = 0;
      if ( this->progressionParms.num > 0 )
      {
        v8 = 0;
        do
        {
          v9 = 0;
          if ( this->progressionParms.list[v8].entities.num > 0 )
          {
            v10 = 0;
            do
            {
              value = this->progressionParms.list[v8].entities.list[v10].spawnId.value;
              if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
                && (v12 = gameLocal->entities.ptr[this->progressionParms.list[v8].entities.list[v10].spawnId.value
                                                & 0x1FFF]) != nullptr )
              {
                v13 = idEntity::CastTo(c: v12);
              }
              else
              {
                v13 = nullptr;
              }
              idProgressionEntity::EnableEntity(this, entity: v13, enable: false);
              ++v9;
              ++v10;
            }
            while ( v9 < this->progressionParms.list[v8].entities.num );
          }
          ++v7;
          ++v8;
        }
        while ( v7 < this->progressionParms.num );
      }
    }
    p_gameLayerManager = &idGameLocal::GetPlayer(this: gameLocal, i: 0)->gameLayerManager;
    RetainedEntityState = idGameLayerManager::FindRetainedEntityState(
                            this: p_gameLayerManager,
                            entityName: this->name.data);
    this->retainedState = RetainedEntityState;
    if ( RetainedEntityState != nullptr )
    {
      state = RetainedEntityState->state;
      if ( state == -1 )
      {
        defaultState = this->defaultState;
      }
      else if ( this->progressionParms.list[state].incrementsOnMapLoad )
      {
        defaultState = RetainedEntityState->targetState;
      }
      else
      {
        defaultState = RetainedEntityState->state;
      }
      idProgressionEntity::GotoState(this, requestedState: defaultState, force: true);
    }
    else
    {
      idStr::idStr(this: &v23[0].entityName, text: &byte_8200D768);
      LODWORD(v16) = 0;
      v23[0].state = -1;
      v23[0].targetState = -1;
      v23[0].timeStarted = v16;
      v23[0].entity = this;
      idStr::operator=(this: &v23[0].entityName, text: this->name.data);
      idList<idEntityRetainedState,5>::Append(this: &p_gameLayerManager->entityRetainedStates, obj: v23);
      this->retainedState = idGameLayerManager::FindRetainedEntityState(
                              this: p_gameLayerManager,
                              entityName: this->name.data);
      idProgressionEntity::GotoState(this, requestedState: this->defaultState, force: false);
      idStr::FreeData(this: &v23[0].entityName);
    }
  }
  LODWORD(a6) = this->retainedState;
  if ( (_DWORD)a6 != 0 )
  {
    v19 = *(_DWORD *)(a6 + 32);
    if ( v19 >= 0 )
    {
      timeAtState = this->progressionParms.list[v19].timeAtState;
      if ( timeAtState > 0.0 )
      {
        v21 = -*(_DWORD *)(a6 + 44);
        LODWORD(a6) = (float)*(__int64 *)((char *)&a6 - 4) > timeAtState;
        if ( (float)((float)a6 * (float)0.001) != 0.0 )
          idEventReceiver::ProcessEvent(this: v22, result: (idEventArg *)this, ev: &EV_Activate);
      }
    }
    idEntity::BecomeInactive(this, flags: 1);
  }
}


// ========================================================================
// __unwind$489331
// EA  : 0x82C9A4D4
// RVA : 0x00C9A4D4
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void _unwind_489331()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?Spawn@idProgressionEntity@@QAAXXZ
// EA  : 0x82C9A500
// RVA : 0x00C9A500
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void __fastcall idProgressionEntity::Spawn(idProgressionEntity *this)
{
  idPlayer *Player; // r3
  int defaultState; // r21
  bool preSpawnAll; // r11
  idList<idList<idEntity *,5>,5> *p_spawnedEntities; // r20
  bool forcePrespawnAll; // r10
  int num; // r31
  int size; // r11
  int v9; // r24
  int v10; // r22
  int v11; // r23
  idProgressionEntity::idProgressionParms *v12; // r29
  idList<enum encounterGroupRole_t,5> *v13; // r25
  int v14; // r26
  int v15; // r27
  idEntity *v16; // r31
  idPhysics *Physics; // r30
  idPhysics *v18; // r18
  idPhysics *v19; // r3
  idPhysics_vtbl *v20; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v22; // r3
  idPhysics *v23; // r30
  idPhysics *v24; // r18
  idPhysics *v25; // r3
  idPhysics_vtbl *v26; // r30
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v28; // r3
  idPhysics *v29; // r3
  int v30; // r22
  int v31; // r23
  int v32; // r24
  int v33; // r31
  idList<idEntity *,5> *v34; // r30
  idProgressionEntity::idProgressionParms *v35; // r26
  int v36; // r29
  idEntity **list; // r27
  idEventArg *v38; // r3
  int v39; // r29
  int v40; // r30
  int value; // r9
  idEntity *v42; // r3
  idEventArg *v43; // r31
  idEventArg *v44; // r3
  idEntity *v45; // [sp+50h] [-C0h] BYREF
  idEventArg v46; // [sp+60h] [-B0h] BYREF
  idEventArg v47[7]; // [sp+80h] [-90h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  defaultState = this->defaultState;
  this->preSpawnAll = false;
  if ( Player != nullptr )
  {
    idGameLayerManager::FindRetainedEntityState(this: &Player->gameLayerManager, entityName: this->name.data);
    this->preSpawnAll = this->changeStateWithinMap;
  }
  preSpawnAll = this->preSpawnAll;
  p_spawnedEntities = &this->spawnedEntities;
  forcePrespawnAll = this->forcePrespawnAll;
  num = this->progressionParms.num;
  this->spawnedState = defaultState;
  this->preSpawnAll = forcePrespawnAll || preSpawnAll;
  if ( num <= this->spawnedEntities.size
    || (unsigned __int8)idList<idList<idDeclVehicleUpgrade const *,5>,5>::Resize(
                          this: (idList<idGuiListBox::row_t,5> *)&this->spawnedEntities,
                          newsize: num) != 0 )
  {
    size = this->spawnedEntities.size;
    if ( num < size )
      size = num;
    this->spawnedEntities.num = size;
  }
  v9 = 0;
  if ( this->progressionParms.num > 0 )
  {
    v10 = 0;
    v11 = 0;
    do
    {
      v12 = &this->progressionParms.list[v11];
      v13 = (idList<enum encounterGroupRole_t,5> *)&p_spawnedEntities->list[v10];
      if ( defaultState == v9 || this->preSpawnAll )
      {
        v14 = 0;
        if ( v12->entityDefs.num > 0 )
        {
          v15 = 0;
          do
          {
            v16 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v12->entityDefs.list[v15], a3: -1, a4: -1, a5: -1);
            v45 = v16;
            if ( v16 != nullptr )
            {
              Physics = idEntity::GetPhysics(this);
              v18 = idEntity::GetPhysics(this: v16);
              v19 = Physics;
              GetOrigin = Physics->GetOrigin;
              v20 = v18->__vftable;
              v22 = (int)GetOrigin(this: v19, a2: 0);
              v20->SetOrigin(this: v18, a2: (const idVec3 *)v22, a3: -1);
              v23 = idEntity::GetPhysics(this);
              v24 = idEntity::GetPhysics(this: v16);
              v25 = v23;
              GetAxis = v23->GetAxis;
              v26 = v24->__vftable;
              v28 = (int)GetAxis(this: v25, a2: 0);
              v26->SetAxis(this: v24, a2: (const idMat3 *)v28, a3: -1);
              v29 = idEntity::GetPhysics(this: v16);
              v29->DisableClip(this: v29);
              idEntity::BecomeInactive(this: v16, flags: 2);
              idEntity::BecomeInactive(this: v16, flags: 1);
              v16->Hide_2(this: v16);
              idList<idAnimWebBlendTree *,5>::Append(this: v13, obj: (encounterGroupRole_t *)&v45);
            }
            ++v14;
            ++v15;
          }
          while ( v14 < v12->entityDefs.num );
        }
      }
      ++v9;
      ++v11;
      ++v10;
    }
    while ( v9 < this->progressionParms.num );
  }
  v30 = 0;
  if ( this->progressionParms.num > 0 )
  {
    v31 = 0;
    v32 = 0;
    do
    {
      v33 = 0;
      v34 = &p_spawnedEntities->list[v31];
      v35 = &this->progressionParms.list[v32];
      if ( v34->num > 0 )
      {
        v36 = 0;
        do
        {
          list = v34->list;
          v38 = idEventArg::idEventArg(this: &v46, data: this);
          idEventReceiver::ProcessEvent(
            this: (idEventReceiver *)v47,
            result: (idEventArg *)list[v36],
            ev: *(const idEventDef **)&v38->type,
            arg1: (const idEventArg *)LODWORD(v38->value.v[1]));
          ++v33;
          ++v36;
        }
        while ( v33 < v34->num );
      }
      v39 = 0;
      if ( v35->entities.num > 0 )
      {
        v40 = 0;
        do
        {
          value = v35->entities.list[v40].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v42 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v43 = (idEventArg *)idEntity::CastTo(c: v42);
          }
          else
          {
            v43 = nullptr;
          }
          v44 = idEventArg::idEventArg(this: v47, data: this);
          idEventReceiver::ProcessEvent(
            this: (idEventReceiver *)&v46,
            result: v43,
            ev: *(const idEventDef **)&v44->type,
            arg1: (const idEventArg *)LODWORD(v44->value.v[1]));
          ++v39;
          ++v40;
        }
        while ( v39 < v35->entities.num );
      }
      ++v30;
      ++v32;
      ++v31;
    }
    while ( v30 < this->progressionParms.num );
  }
  this->Hide_2(this);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ??0idProgressionEntity@@QAA@XZ
// EA  : 0x82C9A918
// RVA : 0x00C9A918
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

idProgressionEntity *__fastcall idProgressionEntity::idProgressionEntity(idProgressionEntity *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idProgressionEntity_vtbl *)&idProgressionEntity::`vftable';
  this->progressionParms.granularity = 0;
  this->progressionParms.memTag = 5;
  this->progressionParms.listStatic = 0;
  this->progressionParms.list = nullptr;
  this->progressionParms.size = 0;
  this->progressionParms.num = 0;
  this->defaultState = 0;
  this->changeStateWithinMap = false;
  this->forcePrespawnAll = false;
  *(_WORD *)&this->wrappable = 1;
  this->initiallyHideEntities = true;
  this->spawnedEntities.granularity = 0;
  this->spawnedEntities.memTag = 5;
  this->spawnedEntities.listStatic = 0;
  this->spawnedEntities.list = nullptr;
  this->spawnedEntities.size = 0;
  this->spawnedEntities.num = 0;
  this->preSpawnAll = false;
  this->waitUntilNextMapLoad = false;
  this->spawnedState = -1;
  this->retainedState = nullptr;
  return this;
}


// ========================================================================
// __unwind$489701
// EA  : 0x82C9A9D8
// RVA : 0x00C9A9D8
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void _unwind_489701()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489702
// EA  : 0x82C9AA00
// RVA : 0x00C9AA00
// PDB : w:\tech5\tungsten\game\entities\progressionentity.cpp
// ========================================================================

void _unwind_489702()
{
  int v0; // r12

  idList<idProgressionEntity::idProgressionParms,5>::~idList<idProgressionEntity::idProgressionParms,5>(this: (idList<idProgressionEntity::idProgressionParms,5> *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}

