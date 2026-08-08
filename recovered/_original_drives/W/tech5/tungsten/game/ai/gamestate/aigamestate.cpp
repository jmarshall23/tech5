
// ========================================================================
// ?GetState@idAIGameState@@QBAPBUaiLatchedState_t@@ABVidSpawnId@@@Z
// EA  : 0x82AFBF70
// RVA : 0x00AFBF70
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

const aiLatchedState_t *__fastcall idAIGameState::GetState(idAIGameState *this, const idSpawnId *spawnId)
{
  int v2; // r11
  const aiLatchedState_t *result; // r3

  v2 = spawnId->value & 0x1FFF;
  if ( v2 == 0x1FFF )
    return nullptr;
  result = this->entStates.ptr[v2];
  if ( result == nullptr || result->spawnId.value != spawnId->value )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetStateForEntityNum@idAIGameState@@QBAPBUaiLatchedState_t@@H@Z
// EA  : 0x82AFBFA8
// RVA : 0x00AFBFA8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

const aiLatchedState_t *__fastcall idAIGameState::GetStateForEntityNum(idAIGameState *this, const int num)
{
  if ( num == 0x1FFF )
    return nullptr;
  else
    return this->entStates.ptr[num];
}


// ========================================================================
// ?GetEvent@idAIGameState@@QBAPBUaiLatchedEvent_t@@ABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@@Z
// EA  : 0x82AFBFC8
// RVA : 0x00AFBFC8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

const aiLatchedEvent_t *__fastcall idAIGameState::GetEvent(
        idAIGameState *this,
        const idHandle<int,enum invalidAIEvent_t,-1> *handle)
{
  int v2; // r10
  int numEvents; // r9
  idArray<aiLatchedEvent_t *,256> *i; // r11
  const aiLatchedEvent_t *result; // r3

  if ( handle->value == -1 )
    return nullptr;
  v2 = 0;
  numEvents = this->numEvents;
  if ( numEvents <= 0 )
    return nullptr;
  for ( i = &this->events; ; i = (idArray<aiLatchedEvent_t *,256> *)((char *)i + 4) )
  {
    result = i->ptr[0];
    if ( i->ptr[0]->eventHandle.value == handle->value )
      break;
    if ( ++v2 >= numEvents )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?Shutdown@idAIGameState@@QAAXXZ
// EA  : 0x82AFC1C8
// RVA : 0x00AFC1C8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void __fastcall idAIGameState::Shutdown(idAIGameState *this)
{
  memset(Dst: this, Val: 0, Size: 0x8000u);
  memset(Dst: &this->events, Val: 0, Size: sizeof(this->events));
  this->numEvents = 0;
  this->gameTime = -1;
  this->gameFrame = -1;
  this->garbageIndex = 0;
  idBlockAlloc<aiLatchedState_t,256,63>::Shutdown(this: &this->stateAllocator);
  idBlockAlloc<aiLatchedEvent_t,64,63>::Shutdown(this: &this->eventAllocator);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->forcedLatches);
}


// ========================================================================
// ?GetPhysicalState@idAIGameState@@SA_NPBVidGameLocal@@PBVidEntity@@AAUaiPhysicalState_t@@@Z
// EA  : 0x82AFC278
// RVA : 0x00AFC278
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

idPhysics *__fastcall idAIGameState::GetPhysicalState(const idGameLocal *game, idTurret *ent, aiPhysicalState_t *ps)
{
  idPhysics *result; // r3
  idPhysics *v6; // r29
  float *v7; // r3
  float *v8; // r3
  const idBounds *(__fastcall *GetBounds)(idPhysics *, int); // r11
  const idBounds *v10; // r3
  idTurret *v11; // r29
  idPlayer *v12; // r27
  idAI2 *v13; // r3
  idAI2 *v14; // r28
  idPresentable *presentable; // r11
  idQuat *v16; // r3
  double x; // fp0
  double y; // fp13
  double z; // fp12
  idPresentable *v20; // r11
  idPresentable *v21; // r3
  float *v22; // r3
  idAIOrientation *BodyOrientation; // r3
  double v24; // fp9
  double v25; // fp8
  idPresentable *v26; // r11
  idPhysics *Physics; // r3
  idQuat *v28; // r3
  idPhysics *v29; // r3
  float *v30; // r3
  __int16 entFlags; // r9
  char v32; // r27
  idActor *v33; // r3
  idActor *v34; // r29
  int v35; // r3
  bool v36; // r3
  int v37; // r5
  __int16 v38; // r4
  int v39; // r3
  char v40; // r11
  idVec3 v41; // [sp+50h] [-70h] BYREF
  idVec3 v42; // [sp+60h] [-60h] BYREF
  idPhysics v43; // [sp+70h] [-50h] BYREF

  result = idEntity::GetPhysics(this: ent);
  v6 = result;
  if ( result == nullptr )
    return result;
  v7 = (float *)result->GetOrigin(this: result, a2: 0);
  ps->origin.x = *v7;
  ps->origin.y = v7[1];
  ps->origin.z = v7[2];
  v8 = (float *)v6->GetLinearVelocity(this: &v43, result: (idVec3 *)v6, a3: 0);
  GetBounds = v6->GetBounds;
  ps->velocity.x = *v8;
  ps->velocity.y = v8[1];
  ps->velocity.z = v8[2];
  v10 = GetBounds(this: v6, a2: -1);
  idBoundsShort::SetBounds(this: &ps->bounds, bounds: v10);
  v11 = idTurret::CastTo(c: ent);
  v12 = idPlayer::CastTo(c: (idPlayer *)ent);
  v13 = idAI2::CastTo(c: (idAI2 *)ent);
  v14 = v13;
  if ( v11 != nullptr )
  {
    idTurret::GetMuzzleDirection(this: v11, dir: &v41);
    presentable = ent->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: ent);
      presentable = ent->presentable;
    }
    v16 = idMat3::ToQuat(this: (idMat3 *)&v43, result: (idQuat *)&presentable->axis);
    ps->rotation.x = v16->x;
    ps->rotation.y = v16->y;
    ps->rotation.z = v16->z;
    x = v41.x;
    y = v41.y;
    z = v41.z;
    ps->rotation.w = v16->w;
    ps->viewfwd.x = x;
    ps->viewfwd.y = y;
    ps->viewfwd.z = z;
  }
  else
  {
    v20 = ent->presentable;
    if ( v12 != nullptr )
    {
      if ( v20 == nullptr )
      {
        idEntity::InitPresentableInternal(this: ent);
        v20 = ent->presentable;
      }
      ps->rotation = *idMat3::ToQuat(this: (idMat3 *)&v43, result: (idQuat *)&v20->axis);
      v21 = v12->presentable;
      if ( v21 != nullptr )
        v22 = (float *)v21->GetPlayerInterface_2(this: v21);
      else
        v22 = nullptr;
      ps->viewfwd.x = v22[11636];
      ps->viewfwd.y = v22[11637];
      ps->viewfwd.z = v22[11638];
    }
    else
    {
      if ( v13 != nullptr )
      {
        if ( v20 == nullptr )
        {
          idEntity::InitPresentableInternal(this: ent);
          v20 = ent->presentable;
        }
        ps->rotation = *idMat3::ToQuat(this: (idMat3 *)&v43, result: (idQuat *)&v20->axis);
        BodyOrientation = idAI2::GetBodyOrientation(this: v14);
        idRotationTracker::GetWorldSpaceDir(
          this: &v14->aiVolatile.focus.foci.ptr[0].aimTracker,
          refAxis: &BodyOrientation->axis,
          wsDir: &v42);
        v24 = v42.y;
        v25 = v42.z;
        ps->viewfwd.x = v42.x;
        ps->viewfwd.y = v24;
      }
      else
      {
        if ( v20 != nullptr )
        {
          ps->rotation = *idMat3::ToQuat(this: (idMat3 *)&v43, result: (idQuat *)&v20->axis);
          v26 = ent->presentable;
          if ( v26 == nullptr )
          {
            idEntity::InitPresentableInternal(this: ent);
            v26 = ent->presentable;
          }
          ps->viewfwd.x = v26->axis.mat[0].x;
          ps->viewfwd.y = v26->axis.mat[0].y;
          ps->viewfwd.z = v26->axis.mat[0].z;
          goto LABEL_23;
        }
        Physics = idEntity::GetPhysics(this: ent);
        v28 = (idQuat *)Physics->GetAxis(this: Physics, a2: 0);
        ps->rotation = *idMat3::ToQuat(this: (idMat3 *)&v43, result: v28);
        v29 = idEntity::GetPhysics(this: ent);
        v30 = (float *)v29->GetAxis(this: v29, a2: 0);
        ps->viewfwd.x = *v30;
        ps->viewfwd.y = v30[1];
        v25 = v30[2];
      }
      ps->viewfwd.z = v25;
    }
  }
LABEL_23:
  ent->GetVisibilityPoint(this: ent, a2: VISPOINT_EYES, a3: &ps->eyePos);
  entFlags = ps->entFlags;
  ps->entFlags = 0;
  v32 = (entFlags & 2) != 0;
  ps->entFlags |= ent->IsDead(this: ent);
  ps->entFlags |= !ent->IsDying(this: ent) ? 0 : 0x80;
  v33 = idActor::CastTo(c: (idActor *)ent);
  v34 = v33;
  if ( v33 != nullptr )
  {
    v35 = v33->GetLeanState(this: v33);
    ps->entFlags |= (v35 != 1 ? 0 : 8) | (v35 != 2 ? 0 : 4);
    v36 = v34->IsDying(this: v34);
    ps->entFlags |= !v36 ? 0 : 0x80;
    v37 = ((unsigned __int8 (__fastcall *)(idActor *, int))v34->IsDrivingVehicle)(a1: v34, a2: -v36);
    v38 = ps->entFlags;
    ps->entFlags = (v37 == 0 ? 0 : 0x40) | v38;
    if ( (v38 & 1) != 0 || (v39 = v34->GetPosture(this: v34), v40 = 1, v39 != 2) )
      v40 = 0;
    ps->entFlags |= v40 == 0 ? 0 : 2;
    if ( v32 == v40 )
    {
      if ( ps->crouchChangeDelta < 0x7FFF
                                 - idGameTimeManager::GetGameMsPerFrame(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED) )
        ps->crouchChangeDelta += idGameTimeManager::GetGameMsPerFrame(
                                   this: &clientGame->gameTimeManager,
                                   type: GAMETIME_SCALED);
    }
    else
    {
      ps->crouchChangeDelta = 0;
    }
  }
  else
  {
    ps->crouchChangeDelta = 0x7FFF;
  }
  if ( (*((_BYTE *)&ent->flags + 1) & 0x40) != 0 )
    ps->entFlags |= 0x20u;
  return (idPhysics *)1;
}


// ========================================================================
// ?LatchEntityState@idAIGameState@@AAAXPBVidGameLocal@@PBVidEntity@@_N@Z
// EA  : 0x82AFC7F8
// RVA : 0x00AFC7F8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void __fastcall idAIGameState::LatchEntityState(
        idAIGameState *this,
        const idGameLocal *game,
        idAI2 *ent,
        const bool force)
{
  idPhysics *Physics; // r3
  int entityNumber; // r29
  aiLatchedState_t *v10; // r31
  idAI2 *v11; // r3
  idAI2 *v12; // r28
  idEncounterGroup *EncounterGroup; // r3
  __int16 value; // r11
  const idEntity *BindMaster; // r5
  idSpawnId *SpawnId; // r3
  double fovDot; // fp1
  double StimulusScale; // fp1
  _DWORD v19[16]; // [sp+50h] [-40h] BYREF

  if ( ent != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ent);
    if ( force || (Physics->GetContents(this: Physics, a2: -1) & 0x19E00) != 0 )
    {
      entityNumber = ent->entityNumber;
      v10 = this->entStates.ptr[entityNumber];
      if ( v10 != nullptr )
      {
        if ( v10->frameNum == idAccolade::Count(this: &game->clientGame.gameTimeManager) )
          return;
      }
      else
      {
        v10 = (aiLatchedState_t *)idBlockAlloc<aiLatchedState_t,256,63>::Alloc(this: &this->stateAllocator);
        this->entStates.ptr[entityNumber] = v10;
      }
      v10->frameNum = this->gameFrame;
      v10->spawnId = (idSpawnId)idGameLocal::GetSpawnId(this: (idGameLocal *)v19, result: (idSpawnId *)gameLocal, ent)->value;
      if ( ent->GetFaction_2(this: ent) != nullptr )
        v10->faction = ent->GetFaction_2(this: ent)->myFaction;
      else
        v10->faction = nullptr;
      v11 = idAI2::CastTo(c: ent);
      v12 = v11;
      if ( v11 != nullptr && (EncounterGroup = idAI2::GetEncounterGroup(this: v11)) != nullptr )
        value = EncounterGroup->handle.value;
      else
        value = -1;
      v10->groupHandle.value = value;
      v10->entityType = idAIGameState::GetEntityType(ent);
      BindMaster = idEntity::GetBindMaster(this: ent);
      SpawnId = (idSpawnId *)v19;
      if ( BindMaster != nullptr )
        SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)v19, result: (idSpawnId *)gameLocal, ent: BindMaster);
      else
        v19[0] = 0x1FFF;
      v10->masterId = (idSpawnId)SpawnId->value;
      idAIGameState::GetPhysicalState(game, (idTurret *)ent, ps: &v10->physical);
      ent->GetViewStateFOV(this: ent, a2: &v10->physical.viewfwd, a3: &v10->horzFOV, a4: &v10->vertFOV);
      if ( v10->entityType == 0 )
      {
        if ( v12 != nullptr )
          fovDot = v12->aiVolatile.perception.fovDot;
        else
          fovDot = 0.0;
        v10->horzFOV = idAIVisibility::FOVDotToByte(fov: fovDot);
      }
      StimulusScale = idEntity::GetStimulusScale(this: ent);
      v10->physical.stimScale = idPerceptionVolume::ScaleToByte(scale: StimulusScale);
    }
  }
}


// ========================================================================
// ??0idAIGameState@@QAA@XZ
// EA  : 0x82AFCA00
// RVA : 0x00AFCA00
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

idAIGameState *__fastcall idAIGameState::idAIGameState(idAIGameState *this)
{
  idList<idVehicleState *,5> *p_forcedLatches; // r3

  p_forcedLatches = (idList<idVehicleState *,5> *)&this->forcedLatches;
  p_forcedLatches->list = nullptr;
  p_forcedLatches->granularity = 0;
  p_forcedLatches->memTag = 5;
  p_forcedLatches->listStatic = 0;
  p_forcedLatches->size = 0;
  p_forcedLatches->num = 0;
  idList<idThread *,58>::Clear(this: p_forcedLatches);
  this->stateAllocator.blocks = nullptr;
  this->stateAllocator.free = nullptr;
  this->stateAllocator.total = 0;
  this->stateAllocator.active = 0;
  this->stateAllocator.allowAllocs = true;
  this->stateAllocator.clearAllocs = false;
  this->eventAllocator.blocks = nullptr;
  this->eventAllocator.free = nullptr;
  this->eventAllocator.total = 0;
  this->eventAllocator.active = 0;
  this->eventAllocator.allowAllocs = true;
  this->eventAllocator.clearAllocs = false;
  this->gameTime = -1;
  this->gameFrame = -1;
  this->numEvents = 0;
  this->garbageIndex = 0;
  memset(Dst: this, Val: 0, Size: 0x8000u);
  memset(Dst: &this->events, Val: 0, Size: sizeof(this->events));
  return this;
}


// ========================================================================
// ??1idAIGameState@@QAA@XZ
// EA  : 0x82AFCAF0
// RVA : 0x00AFCAF0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void __fastcall idAIGameState::~idAIGameState(idAIGameState *this)
{
  idAIGameState::Shutdown(this);
  idBlockAlloc<aiLatchedEvent_t,64,63>::Shutdown(this: &this->eventAllocator);
  idBlockAlloc<aiLatchedState_t,256,63>::Shutdown(this: &this->stateAllocator);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->forcedLatches);
}


// ========================================================================
// __unwind$488724
// EA  : 0x82AFCB50
// RVA : 0x00AFCB50
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void _unwind_488724()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 33792));
}


// ========================================================================
// __unwind$488725
// EA  : 0x82AFCB84
// RVA : 0x00AFCB84
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void _unwind_488725()
{
  int v0; // r12

  idBlockAlloc<aiLatchedState_t,256,63>::~idBlockAlloc<aiLatchedState_t,256,63>(this: (idBlockAlloc<aiLatchedState_t,256,63> *)(*(_DWORD *)(v0 - 112 + 132) + 33808));
}


// ========================================================================
// __unwind$488726
// EA  : 0x82AFCBB8
// RVA : 0x00AFCBB8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void _unwind_488726()
{
  int v0; // r12

  idBlockAlloc<aiLatchedEvent_t,64,63>::~idBlockAlloc<aiLatchedEvent_t,64,63>(this: (idBlockAlloc<aiLatchedEvent_t,64,63> *)(*(_DWORD *)(v0 - 112 + 132) + 33828));
}


// ========================================================================
// ?UpdateFromGame@idAIGameState@@QAAXPBVidGameLocal@@@Z
// EA  : 0x82AFCBF0
// RVA : 0x00AFCBF0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void __fastcall idAIGameState::UpdateFromGame(idAIGameState *this, idGameLocal *game)
{
  idGameTimeManager *p_gameTimeManager; // r31
  int v5; // r18
  idLinkList<idEntity> *next; // r11
  idAI2 *i; // r31
  idLinkList<idEntity> *v8; // r11
  int v9; // r30
  int num; // r19
  int v11; // r20
  int v12; // r31
  idAI2 *v13; // r3
  idList<idSpawnId,5> *p_forcedLatches; // r31
  int *p_garbageIndex; // r29
  int garbageIndex; // r30
  int v17; // r31
  idBlockAlloc<aiLatchedState_t,256,63>::element_t *v18; // r11
  const idEntity *v19; // r5
  idSpawnId *SpawnId; // r3
  int v21; // r8
  int *p_numEvents; // r28
  int v23; // r9
  int numEvents; // r7
  aiLatchedState_t **v25; // r10
  idBlockAlloc<aiLatchedEvent_t,64,63>::element_t *v26; // r11
  int v27; // r23
  int v28; // r24
  idAIEvent *v29; // r30
  aiLatchedEvent_t *v30; // r3
  aiLatchedEvent_t *v31; // r31
  int v32; // r11
  idGameLocal *v33; // r10
  int value; // r5
  idEntity *v35; // r3
  idEntity *v36; // r5
  int v37; // r9
  idEntity *v38; // r3
  idEntity *v39; // r5
  int v40; // r5
  idEntity *v41; // r3
  idAI2 *v42; // r5
  int v43; // r9
  idEntity *v44; // r3
  idAI2 *v45; // r5
  char v46; // [sp+50h] [-80h] BYREF
  char v47; // [sp+54h] [-7Ch] BYREF

  p_gameTimeManager = &game->clientGame.gameTimeManager;
  this->gameTime = idGameTimeManager::GetGameMs(this: &game->clientGame.gameTimeManager, type: GAMETIME_SCALED);
  v5 = 0;
  this->gameFrame = idAccolade::Count(this: p_gameTimeManager);
  next = game->activeEntities.next;
  if ( next != nullptr && next != game->activeEntities.head )
  {
    for ( i = (idAI2 *)next->owner; i != nullptr; i = (idAI2 *)v8->owner )
    {
      idAIGameState::LatchEntityState(this, game, ent: i, force: false);
      v8 = i->activeNode.next;
      ++v5;
      if ( v8 == nullptr )
        break;
      if ( v8 == i->activeNode.head )
        break;
    }
  }
  v9 = 0;
  num = this->forcedLatches.num;
  v11 = num + v5;
  if ( num > 0 )
  {
    v12 = 0;
    do
    {
      v13 = (idAI2 *)game->GetEntityForSpawnId(this: game, a2: this->forcedLatches.list[v12].value);
      idAIGameState::LatchEntityState(this, game, ent: v13, force: true);
      ++v9;
      ++v11;
      ++v12;
    }
    while ( v9 < this->forcedLatches.num );
  }
  p_forcedLatches = &this->forcedLatches;
  if ( this->forcedLatches.size < 0 )
  {
    if ( this->forcedLatches.listStatic == 0 || this->forcedLatches.listStatic == 2 )
    {
      if ( p_forcedLatches->list != nullptr )
        idMem::Free(this: &mem, ptr: p_forcedLatches->list, align: ALIGN_16);
      p_forcedLatches->list = nullptr;
      this->forcedLatches.size = 0;
    }
    this->forcedLatches.num = 0;
  }
  p_garbageIndex = &this->garbageIndex;
  this->forcedLatches.num = __CFADD__(-this->forcedLatches.size, this->forcedLatches.size ^ 0x80000000)
                          ? 0
                          : this->forcedLatches.size;
  garbageIndex = this->garbageIndex;
  if ( garbageIndex < garbageIndex + 32 )
  {
    do
    {
      v17 = (4 * garbageIndex) & 0x7FFC;
      v18 = *(idBlockAlloc<aiLatchedState_t,256,63>::element_t **)((char *)this->entStates.ptr + v17);
      if ( v18 != nullptr )
      {
        v19 = game->entities.ptr[garbageIndex & 0x1FFF];
        if ( v19 == nullptr
          || (SpawnId = idGameLocal::GetSpawnId(this: (idGameLocal *)&v46, result: (idSpawnId *)game, ent: v19),
              *(_DWORD *)&(v18 = *(idBlockAlloc<aiLatchedState_t,256,63>::element_t **)((char *)this->entStates.ptr + v17))->buffer[88] != SpawnId->value) )
        {
          if ( v18 != nullptr )
          {
            v18->data = (aiLatchedState_t *)this->stateAllocator.free;
            v21 = this->stateAllocator.active - 1;
            this->stateAllocator.free = v18;
            this->stateAllocator.active = v21;
          }
          *(aiLatchedState_t **)((char *)this->entStates.ptr + v17) = nullptr;
        }
      }
      ++garbageIndex;
    }
    while ( garbageIndex < *p_garbageIndex + 32 );
  }
  p_numEvents = &this->numEvents;
  v23 = 0;
  numEvents = this->numEvents;
  *p_garbageIndex = ((unsigned __int16)*p_garbageIndex + 32) & 0x1FFF;
  if ( numEvents > 0 )
  {
    v25 = &this->entStates.ptr[0x1FFF];
    do
    {
      v26 = (idBlockAlloc<aiLatchedEvent_t,64,63>::element_t *)v25[1];
      if ( v26 != nullptr )
      {
        v26->data = (aiLatchedEvent_t *)this->eventAllocator.free;
        this->eventAllocator.free = v26;
        --this->eventAllocator.active;
      }
      ++v23;
      *++v25 = nullptr;
    }
    while ( v23 < *p_numEvents );
  }
  *p_numEvents = 0;
  if ( game != (idGameLocal *)-1395920 )
  {
    v27 = 0;
    if ( game->aiEventManager.eventList.num > 0 )
    {
      v28 = 0;
      do
      {
        v29 = game->aiEventManager.eventList.list[v28];
        if ( v29 != nullptr )
        {
          v30 = (aiLatchedEvent_t *)idBlockAlloc<aiLatchedEvent_t,64,63>::Alloc(this: &this->eventAllocator);
          v31 = v30;
          if ( v30 != nullptr )
          {
            v32 = *p_numEvents;
            if ( *p_numEvents >= 256 )
            {
              idLib::Warning(
                fmt: "idAIGameState::UpdateFromGame: No Free slots, skipped %d events",
                game->aiEventManager.eventList.num - v27);
              break;
            }
            *p_numEvents = v32 + 1;
            this->events.ptr[v32] = v30;
            v30->eventHandle.value = v29->handle.value;
            v30->eventTime = v29->startTime;
            v30->origin.x = v29->origin.x;
            v33 = gameLocal;
            v30->origin.y = v29->origin.y;
            v30->origin.z = v29->origin.z;
            value = v29->originator.spawnId.value;
            if ( v33->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v35 = v33->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v36 = idEntity::CastTo(c: v35);
            }
            else
            {
              v36 = nullptr;
            }
            v31->creatorId = (idSpawnId)idGameLocal::GetSpawnId(
                                          this: (idGameLocal *)&v46,
                                          result: (idSpawnId *)game,
                                          ent: v36)->value;
            v37 = v29->instigator.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v37 & 0x1FFF] == v37 >> 13
              && (v38 = gameLocal->entities.ptr[v37 & 0x1FFF]) != nullptr )
            {
              v39 = idEntity::CastTo(c: v38);
            }
            else
            {
              v39 = nullptr;
            }
            v31->relevantId = (idSpawnId)idGameLocal::GetSpawnId(
                                           this: (idGameLocal *)&v47,
                                           result: (idSpawnId *)game,
                                           ent: v39)->value;
            v31->priority = idAIEvent::GetPriority(this: v29);
            v31->flags = idAIEvent::GetInstigatorStimulus(this: v29);
            v31->eventClass = idAIEvent::GetEventClass(this: v29);
            v40 = v29->originator.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v40 & 0x1FFF] == v40 >> 13
              && (v41 = gameLocal->entities.ptr[v40 & 0x1FFF]) != nullptr )
            {
              v42 = (idAI2 *)idEntity::CastTo(c: v41);
            }
            else
            {
              v42 = nullptr;
            }
            idAIGameState::LatchEntityState(this, game, ent: v42, force: true);
            v43 = v29->instigator.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v43 & 0x1FFF] == v43 >> 13
              && (v44 = gameLocal->entities.ptr[v43 & 0x1FFF]) != nullptr )
            {
              v45 = (idAI2 *)idEntity::CastTo(c: v44);
            }
            else
            {
              v45 = nullptr;
            }
            idAIGameState::LatchEntityState(this, game, ent: v45, force: true);
          }
        }
        ++v27;
        ++v28;
      }
      while ( v27 < game->aiEventManager.eventList.num );
    }
  }
  if ( ai_debugGameState.valueInteger != 0 )
  {
    debugHUD->Clear(this: debugHUD, a2: false);
    debugHUD->SetLeftAlign(this: debugHUD);
    debugHUD->Printf_3(this: debugHUD, a2: 580, a3: 448, a4: "AI GameState:\n");
    debugHUD->Printf(this: debugHUD, a2: "active:  %d\n", v5);
    debugHUD->Printf(this: debugHUD, a2: "forced:  %d\n", num);
    debugHUD->Printf(this: debugHUD, a2: "latched: %d\n", v11);
  }
}


// ========================================================================
// ?UpdateForcedLatches@idAIGameState@@QAAXPBVidGameLocal@@@Z
// EA  : 0x82AFD1D0
// RVA : 0x00AFD1D0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void __fastcall idAIGameState::UpdateForcedLatches(idAIGameState *this, const idGameLocal *game)
{
  int *p_num; // r27
  int v5; // r30
  int v6; // r31
  idList<idSpawnId,5> *p_forcedLatches; // r26
  idAI2 *v8; // r3
  idList<idSpawnId,5> *v9; // r31

  p_num = &this->forcedLatches.num;
  v5 = 0;
  if ( this->forcedLatches.num > 0 )
  {
    v6 = 0;
    p_forcedLatches = &this->forcedLatches;
    do
    {
      v8 = (idAI2 *)game->GetEntityForSpawnId(this: game, a2: p_forcedLatches->list[v6].value);
      idAIGameState::LatchEntityState(this, game, ent: v8, force: true);
      ++v5;
      ++v6;
    }
    while ( v5 < *p_num );
  }
  v9 = &this->forcedLatches;
  if ( this->forcedLatches.size < 0 )
  {
    if ( this->forcedLatches.listStatic == 0 || this->forcedLatches.listStatic == 2 )
    {
      if ( v9->list != nullptr )
        idMem::Free(this: &mem, ptr: v9->list, align: ALIGN_16);
      v9->list = nullptr;
      this->forcedLatches.size = 0;
    }
    this->forcedLatches.num = 0;
  }
  this->forcedLatches.num = __CFADD__(-this->forcedLatches.size, this->forcedLatches.size ^ 0x80000000)
                          ? 0
                          : this->forcedLatches.size;
}


// ========================================================================
// ?ForceLatch@idAIGameState@@QAAXABVidSpawnId@@@Z
// EA  : 0x82AFD2C8
// RVA : 0x00AFD2C8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void __fastcall idAIGameState::ForceLatch(idAIGameState *this, const idEntityPtr<idAI2> *spawnId)
{
  if ( spawnId->spawnId.value != 0x1FFF )
    idList<idEntityPtr<idEntity>,5>::AddUnique(this: (idList<idEntityPtr<idAI2>,5> *)&this->forcedLatches, obj: spawnId);
}


// ========================================================================
// `dynamic initializer for 'ai_debugGameState''
// EA  : 0x833699F0
// RVA : 0x013699F0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aigamestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugGameState__()
{
  idCVar::idCVar(
    this: &ai_debugGameState,
    name: "ai_debugGameState",
    value: "0",
    flags: 1,
    description: "1 = output AI game state debug information",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugGameState__);
}

