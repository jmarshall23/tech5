
// ========================================================================
// ?ToggleDummyFire@idTarget_C01_TurretFight@@AAAXPAVidEntity@@_N@Z
// EA  : 0x82CE00D0
// RVA : 0x00CE00D0
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

void __fastcall idTarget_C01_TurretFight::ToggleDummyFire(
        idTarget_C01_TurretFight *this,
        idEntity *entity,
        bool activate)
{
  idEntity *TeamMaster; // r3
  idEntity *v5; // r29
  idTarget_DummyFire *NextTeamEntity; // r31
  idEntity *v7; // r30
  idTarget_DummyFire *v8; // r3
  idEntity *v9; // r31

  TeamMaster = idEntity::GetTeamMaster(this: entity);
  v5 = TeamMaster;
  if ( TeamMaster != nullptr )
  {
    NextTeamEntity = (idTarget_DummyFire *)idEntity::GetNextTeamEntity(this: TeamMaster);
    if ( NextTeamEntity != nullptr )
    {
      do
      {
        v7 = idEntity::GetNextTeamEntity(this: NextTeamEntity);
        v8 = idTarget_DummyFire::CastTo(c: NextTeamEntity);
        v9 = v8;
        if ( v8 != nullptr )
        {
          if ( activate )
          {
            idEntity::SetIsActivatable(this: v8, activatable: true);
            idEntity::Activate(this: v9, activator: v5);
          }
          else
          {
            idEntity::SetIsActivatable(this: v8, activatable: false);
          }
        }
        NextTeamEntity = (idTarget_DummyFire *)v7;
      }
      while ( v7 != nullptr );
    }
  }
}


// ========================================================================
// ?FindAttackRoute@idTarget_C01_TurretFight@@ABAHXZ
// EA  : 0x82CE0168
// RVA : 0x00CE0168
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

int __fastcall idTarget_C01_TurretFight::FindAttackRoute(idTarget_C01_TurretFight *this)
{
  signed int num; // r7
  int v3; // r5
  int v4; // r11
  int v5; // ctr
  attackRoute_t *list; // r10
  int numTimesUsed; // r10
  signed int v8; // r9
  int v9; // r11
  int v10; // ctr
  attackRoute_t *v11; // r10
  unsigned int seed; // r9
  unsigned int v13; // r4
  int v14; // r3
  int v15; // r10
  idClientGame *v16; // r11
  int v17; // r8
  int v18; // r6
  unsigned int v19; // r4
  int v20; // r6
  int v21; // r11
  attackRoute_t *v22; // r9

  num = this->attackRoutes.num;
  if ( num <= 0 )
    return -1;
  v3 = 0x7FFFFFFF;
  v4 = 0;
  v5 = this->attackRoutes.num;
  list = this->attackRoutes.list;
  do
  {
    numTimesUsed = list->numTimesUsed;
    if ( v3 >= numTimesUsed )
      v3 = numTimesUsed;
    list = &this->attackRoutes.list[++v4];
    --v5;
  }
  while ( v5 != 0 );
  v8 = 0;
  v9 = 0;
  v10 = this->attackRoutes.num;
  v11 = this->attackRoutes.list;
  do
  {
    if ( v11->numTimesUsed == v3 )
      ++v8;
    v11 = &this->attackRoutes.list[++v9];
    --v10;
  }
  while ( v10 != 0 );
  if ( v8 == 0 )
  {
    seed = clientGame->random.seed;
    __twllei(num, 0);
    v13 = 1664525 * seed + 1013904223;
    clientGame->random.seed = v13;
    v14 = (v13 >> 10) & 0x7FFF;
    __twlgei(num & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
    return v14 % num;
  }
  v15 = 0;
  __twllei(v8, 0);
  v16 = clientGame;
  clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
  v17 = this->attackRoutes.num;
  v18 = (v16->random.seed >> 10) & 0x7FFF;
  v19 = v8 & ~(__ROL4__(v18, 1) - 1);
  v20 = v18 % v8;
  __twlgei(v19, 0xFFFFFFFF);
  if ( v17 <= 0 )
    return v20;
  v21 = 0;
  v22 = this->attackRoutes.list;
  while ( v22->numTimesUsed != v3 )
  {
LABEL_18:
    ++v15;
    v22 = &this->attackRoutes.list[++v21];
    if ( v15 >= v17 )
      return v20;
  }
  if ( v20 != 0 )
  {
    --v20;
    goto LABEL_18;
  }
  return v15;
}


// ========================================================================
// ?Spawn@idTarget_C01_TurretFight@@QAAXXZ
// EA  : 0x82CE0300
// RVA : 0x00CE0300
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

void __fastcall idTarget_C01_TurretFight::Spawn(idTarget_C01_TurretFight *this)
{
  int v2; // r26
  int v3; // r30
  idGameLocal *v4; // r11
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r3
  idBreakable *v8; // r29
  int v9; // r9
  idEntity *v10; // r3
  idAnimatedSimple *v11; // r3
  idAnimatedSimple *v12; // r25
  idBreakable *v13; // r3
  bool v14; // r10
  int v15; // r10
  int v16; // r11

  idEntity::BecomeInactive(this, flags: 1);
  v2 = 0;
  if ( this->attackPlanes.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = gameLocal;
      value = this->attackPlanes.list[v3].plane.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = idEntity::CastTo(c: v6);
        v4 = gameLocal;
        v8 = (idBreakable *)v7;
      }
      else
      {
        v8 = nullptr;
      }
      v9 = this->attackPlanes.list[v3].animator.spawnId.value;
      if ( v4->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
        && (v10 = v4->entities.ptr[this->attackPlanes.list[v3].animator.spawnId.value & 0x1FFF]) != nullptr )
      {
        v11 = (idAnimatedSimple *)idEntity::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      v12 = idAnimatedSimple::CastTo(c: v11);
      v13 = idBreakable::CastTo(c: v8);
      if ( v12 == nullptr || (v14 = true, v13 == nullptr) )
        v14 = false;
      ++v2;
      this->attackPlanes.list[v3++].free = v14;
    }
    while ( v2 < this->attackPlanes.num );
  }
  v15 = 0;
  if ( this->attackRoutes.num > 0 )
  {
    v16 = 0;
    do
    {
      ++v15;
      this->attackRoutes.list[v16].numTimesUsed = 0;
      this->attackRoutes.list[v16++].timestampAvailable = 0;
    }
    while ( v15 < this->attackRoutes.num );
  }
}


// ========================================================================
// ?SpawnPlane@idTarget_C01_TurretFight@@AAAXXZ
// EA  : 0x82CE0468
// RVA : 0x00CE0468
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

void __fastcall idTarget_C01_TurretFight::SpawnPlane(idTarget_C01_TurretFight *this)
{
  int v2; // r30
  int v3; // r10
  int v4; // r11
  attackPlane_t *list; // r9
  int AttackRoute; // r28
  int v7; // r30
  int value; // r7
  idEntity *v9; // r3
  idAnimatedSimple *v10; // r3
  idAnimatedSimple *v11; // r27
  int v12; // r9
  idEntity *v13; // r3
  idBreakable *v14; // r3
  idBreakable *v15; // r30
  int v16; // r28
  int v17; // r8
  idEntity *v18; // r3
  idTarget_C01_TurretFight *v19; // r29
  idPhysics *Physics; // r3
  const idVec3 *v21; // r3
  float y; // r7
  float z; // r6
  idPhysics *v24; // r3
  int v25; // r3
  idVec3 *v26; // r10
  float *v27; // r11
  int i; // ctr
  idAnimatedSimple_vtbl *v29; // r29
  idAngles *v30; // r3
  _DWORD v31[4]; // [sp+50h] [-80h] BYREF
  idMat3 v32[3]; // [sp+60h] [-70h] BYREF

  v2 = -1;
  v3 = 0;
  if ( this->attackPlanes.num <= 0 )
    goto LABEL_7;
  v4 = 0;
  list = this->attackPlanes.list;
  do
  {
    if ( list->free )
      v2 = v3;
    ++v3;
    list = &this->attackPlanes.list[++v4];
  }
  while ( v3 < this->attackPlanes.num );
  if ( v2 >= 0 )
  {
    AttackRoute = idTarget_C01_TurretFight::FindAttackRoute(this);
    if ( AttackRoute >= 0 )
    {
      v7 = v2;
      this->attackPlanes.list[v7].free = false;
      value = this->attackPlanes.list[v7].animator.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v9 = gameLocal->entities.ptr[this->attackPlanes.list[v7].animator.spawnId.value & 0x1FFF]) != nullptr )
      {
        v10 = (idAnimatedSimple *)idEntity::CastTo(c: v9);
      }
      else
      {
        v10 = nullptr;
      }
      v11 = idAnimatedSimple::CastTo(c: v10);
      v12 = this->attackPlanes.list[v7].plane.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
        && (v13 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
      {
        v14 = (idBreakable *)idEntity::CastTo(c: v13);
      }
      else
      {
        v14 = nullptr;
      }
      v15 = idBreakable::CastTo(c: v14);
      v16 = AttackRoute;
      ++this->attackRoutes.list[v16].numTimesUsed;
      v17 = this->startPosition.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] != v17 >> 13
        || (v18 = gameLocal->entities.ptr[v17 & 0x1FFF]) == nullptr
        || (v19 = (idTarget_C01_TurretFight *)idEntity::CastTo(c: v18)) == nullptr )
      {
        v19 = this;
      }
      Physics = idEntity::GetPhysics(this: v19);
      v21 = Physics->GetOrigin(this: Physics, a2: 0);
      y = v21->y;
      z = v21->z;
      v31[0] = LODWORD(v21->x);
      *(float *)&v31[1] = y;
      *(float *)&v31[2] = z;
      v24 = idEntity::GetPhysics(this: v19);
      v25 = (int)v24->GetAxis(this: v24, a2: 0);
      v26 = &v32[0].mat[1];
      v27 = (float *)(v25 - 4);
      for ( i = 9; i != 0; --i )
      {
        ++v27;
        v26 = (idVec3 *)((char *)v26 + 4);
        v26->x = *v27;
      }
      v11->Show(this: v11);
      v15->Show(this: v15);
      idBreakable::Reset(this: v15);
      v29 = v11->__vftable;
      v30 = idMat3::ToAngles(this: v32, result: (idAngles *)&v32[0].mat[1].y);
      v29->Teleport(this: v11, a2: (const idVec3 *)v31, a3: v30);
      idAnimatedSimple::SetAnimStateFromAnimAliasRef(
        this: v11,
        anim: &this->attackRoutes.list[v16].animation,
        blendTime: 0,
        queue: false);
      idTarget_C01_TurretFight::ToggleDummyFire(this, entity: v15, activate: true);
    }
    else
    {
      idLib::Warning(fmt: "No attack route to choose from in '%s'", this->name.data);
    }
  }
  else
  {
LABEL_7:
    idLib::Warning(fmt: "No resources left to spawn new instance in '%s'", this->name.data);
    ++this->numQueuedSpawns;
  }
}


// ========================================================================
// ?Think@idTarget_C01_TurretFight@@UAAXXZ
// EA  : 0x82CE0748
// RVA : 0x00CE0748
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

void __fastcall idTarget_C01_TurretFight::Think(idTarget_C01_TurretFight *this)
{
  int v2; // r24
  int v3; // r28
  attackPlane_t *v4; // r11
  int v5; // r11
  int v6; // r8
  idEntity *v7; // r3
  idBreakable *v8; // r3
  idBreakable *v9; // r29
  int value; // r9
  idEntity *v11; // r3
  idAnimatedSimple *v12; // r3
  idAnimatedSimple *v13; // r27
  attackPlane_t *v14; // r30
  int numQueuedSpawns; // r29
  int v16; // r6
  int v17; // r10
  int v18; // r11
  attackPlane_t *list; // r9
  int i; // r30

  v2 = 0;
  if ( this->attackPlanes.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->attackPlanes.list[v3];
      if ( !v4->free )
      {
        v6 = v4->plane.spawnId.value >> 13;
        v5 = v4->plane.spawnId.value & 0x1FFF;
        if ( gameLocal->spawnIds.ptr[v5] == v6 && (v7 = gameLocal->entities.ptr[v5]) != nullptr )
          v8 = (idBreakable *)idEntity::CastTo(c: v7);
        else
          v8 = nullptr;
        v9 = idBreakable::CastTo(c: v8);
        if ( v9 != nullptr )
        {
          value = this->attackPlanes.list[v3].animator.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v11 = gameLocal->entities.ptr[this->attackPlanes.list[v3].animator.spawnId.value & 0x1FFF]) != nullptr )
          {
            v12 = (idAnimatedSimple *)idEntity::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          v13 = idAnimatedSimple::CastTo(c: v12);
          if ( v13 != nullptr )
          {
            if ( !this->attackPlanes.list[v3].dead && v9->IsDead(this: v9) )
            {
              idTarget_C01_TurretFight::ToggleDummyFire(this, entity: v9, activate: false);
              v14 = &this->attackPlanes.list[v3];
              v14->dead = v9->IsDead(this: v9);
            }
            if ( this->attackPlanes.list[v3].dead
              && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)v9) != 0 )
            {
              this->attackPlanes.list[v3].free = true;
              v9->Hide_2(this: v9);
              v13->Hide_2(this: v13);
            }
          }
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->attackPlanes.num );
  }
  numQueuedSpawns = this->numQueuedSpawns;
  if ( numQueuedSpawns > 0 )
  {
    v16 = 0;
    v17 = 0;
    if ( this->attackPlanes.num > 0 )
    {
      v18 = 0;
      list = this->attackPlanes.list;
      do
      {
        if ( list->free )
          ++v16;
        ++v17;
        list = &this->attackPlanes.list[++v18];
      }
      while ( v17 < this->attackPlanes.num );
      if ( v16 > 0 )
      {
        if ( v16 < numQueuedSpawns )
          numQueuedSpawns = v16;
        for ( i = numQueuedSpawns; i != 0; --i )
          idTarget_C01_TurretFight::SpawnPlane(this);
        this->numQueuedSpawns -= numQueuedSpawns;
      }
    }
  }
}


// ========================================================================
// ?OnActivate@idTarget_C01_TurretFight@@UAAXPAVidEntity@@@Z
// EA  : 0x82CE09A8
// RVA : 0x00CE09A8
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

void __fastcall idTarget_C01_TurretFight::OnActivate(idTarget_C01_TurretFight *this, idEntity *activator)
{
  idEntity::BecomeActive(this, flags: 1);
  idTarget_C01_TurretFight::SpawnPlane(this);
}


// ========================================================================
// ??0idTarget_C01_TurretFight@@QAA@XZ
// EA  : 0x82CE09E8
// RVA : 0x00CE09E8
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

idTarget_C01_TurretFight *__fastcall idTarget_C01_TurretFight::idTarget_C01_TurretFight(idTarget_C01_TurretFight *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idTarget_C01_TurretFight_vtbl *)&idTarget_C01_TurretFight::`vftable';
  this->attackPlanes.list = nullptr;
  this->attackPlanes.granularity = 0;
  this->attackPlanes.memTag = 5;
  this->attackPlanes.listStatic = 0;
  this->attackPlanes.size = 0;
  this->attackPlanes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attackPlanes);
  this->attackRoutes.granularity = 0;
  this->attackRoutes.memTag = 5;
  this->attackRoutes.listStatic = 0;
  this->attackRoutes.list = nullptr;
  this->attackRoutes.size = 0;
  this->attackRoutes.num = 0;
  this->startPosition.spawnId.value = 0x1FFF;
  this->numQueuedSpawns = 0;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// __unwind$488324
// EA  : 0x82CE0A7C
// RVA : 0x00CE0A7C
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

void _unwind_488324()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488325
// EA  : 0x82CE0AA4
// RVA : 0x00CE0AA4
// PDB : w:\tech5\tungsten\game\entities\target_misc.cpp
// ========================================================================

void _unwind_488325()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}

