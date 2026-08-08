
// ========================================================================
// ?RemoveBySpawnId@idTargetCache@@QAAXABVidSpawnId@@@Z
// EA  : 0x82B038A8
// RVA : 0x00B038A8
// PDB : w:\tech5\tungsten\game\ai\targetting\targetcache.cpp
// ========================================================================

void __fastcall idTargetCache::RemoveBySpawnId(idTargetCache *this, const idSpawnId *spawnId)
{
  int num; // r7
  int v3; // r11
  idTargetInfo *list; // r8
  int i; // r10
  const idAIEntityState *es; // r9
  idTargetInfo *v7; // r10
  idTargetInfo *v8; // r11

  num = this->targets.num;
  v3 = 0;
  if ( num > 0 )
  {
    list = this->targets.list;
    for ( i = 0; ; ++i )
    {
      es = list[i].es;
      if ( es != nullptr && es->spawnId.value == spawnId->value )
        break;
      if ( ++v3 >= this->targets.num )
        return;
    }
    if ( v3 >= 0 && v3 < num )
    {
      this->targets.num = num - 1;
      if ( v3 != num - 1 )
      {
        v7 = &list[num - 1];
        v8 = &list[v3];
        v8->es = v7->es;
        v8->distSqr = v7->distSqr;
        v8->distTo = v7->distTo;
        v8->delta.x = v7->delta.x;
        v8->delta.y = v7->delta.y;
        v8->delta.z = v7->delta.z;
        v8->faceDir.x = v7->faceDir.x;
        v8->faceDir.y = v7->faceDir.y;
        v8->faceDir.z = v7->faceDir.z;
        v8->dirTo.x = v7->dirTo.x;
        v8->dirTo.y = v7->dirTo.y;
        v8->dirTo.z = v7->dirTo.z;
        v8->attitude = v7->attitude;
        v8->healthRatio = v7->healthRatio;
      }
    }
  }
}


// ========================================================================
// ??0idTargetCache@@QAA@XZ
// EA  : 0x82B03AF0
// RVA : 0x00B03AF0
// PDB : w:\tech5\tungsten\game\ai\targetting\targetcache.cpp
// ========================================================================

idTargetCache *__fastcall idTargetCache::idTargetCache(idTargetCache *this)
{
  idStaticList<idTargetInfo,8>::idStaticList<idTargetInfo,8>(this: &this->targets);
  this->curFrame = -1;
  return this;
}


// ========================================================================
// ?Clear@idTargetCache@@QAAXXZ
// EA  : 0x82B03BF8
// RVA : 0x00B03BF8
// PDB : w:\tech5\tungsten\game\ai\targetting\targetcache.cpp
// ========================================================================

void __fastcall idTargetCache::Clear(idTargetCache *this)
{
  int size; // r11

  if ( this->targets.size < 0 )
    idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  size = this->targets.size;
  this->curFrame = -1;
  this->targets.num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
}


// ========================================================================
// ?Init@idTargetCache@@QAAXPBUaiLatchedState_t@@ABVidAIWorldState@@@Z
// EA  : 0x82B03CD8
// RVA : 0x00B03CD8
// PDB : w:\tech5\tungsten\game\ai\targetting\targetcache.cpp
// ========================================================================

void __fastcall idTargetCache::Init(
        idTargetCache *this,
        const aiLatchedState_t *ownerState,
        const idAIWorldState *worldState)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int i; // r29
  int value; // r11
  const idAIEntityState *v10; // r30
  idTargetInfo *v11; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v13; // r30
  int v14; // r3
  __int64 totalTicks; // r11
  __int64 v16; // r9
  idPLogScope v17[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idTargetCache::Init");
  LODWORD(v6) = "idTargetCache::Init";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v17, pl: &::pLog, gMask: v6, label: v7);
  this->curFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
  if ( ownerState != nullptr )
  {
    for ( i = 0; i < worldState->numEnts; ++i )
    {
      value = worldState->ents[i].value;
      v10 = &worldState->entityStates[value];
      if ( (const idAIWorldState *)((char *)worldState + value * 576) != (const idAIWorldState *)-24
        && worldState->entityStates[value].highestAwareness != 0 )
      {
        if ( this->targets.num == this->targets.size )
          break;
        v11 = idList<idTargetInfo,5>::Alloc(this: &this->targets);
        idTargetInfo::Cache(this: v11, ownerState, es_: v10);
      }
    }
    if ( v17[0].logIndex >= 0 )
    {
      pLog = v17[0].pLog;
      v13 = &v17[0].pLog->logEntries.list[v17[0].logIndex];
      v14 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v13->totalTicks;
      HIDWORD(totalTicks) = v13->parent;
      LODWORD(v16) = v14 - totalTicks;
      v13->totalTicks = v16;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v17);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$488043
// EA  : 0x82B03E04
// RVA : 0x00B03E04
// PDB : w:\tech5\tungsten\game\ai\targetting\targetcache.cpp
// ========================================================================

void _unwind_488043()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$488044
// EA  : 0x82B03E2C
// RVA : 0x00B03E2C
// PDB : w:\tech5\tungsten\game\ai\targetting\targetcache.cpp
// ========================================================================

void _unwind_488044()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?Update@idTargetCache@@QAAXPBUaiLatchedState_t@@ABVidAIWorldState@@ABVidSpawnId@@@Z
// EA  : 0x82B03E58
// RVA : 0x00B03E58
// PDB : w:\tech5\tungsten\game\ai\targetting\targetcache.cpp
// ========================================================================

void __fastcall idTargetCache::Update(
        idTargetCache *this,
        const aiLatchedState_t *ownerState,
        idAIWorldState *worldState,
        const idSpawnId *targetSpawnId)
{
  const idAIEntityState *v7; // r29
  int num; // r7
  int v9; // r10
  idTargetInfo *v10; // r9
  int v11; // r11
  int v12; // r11
  int size; // r10
  idTargetInfo *list; // r9

  v7 = idAIWorldState::StateForSpawnId(this: worldState, entId: targetSpawnId);
  if ( v7 != nullptr )
  {
    num = this->targets.num;
    v9 = 0;
    if ( num <= 0 )
    {
LABEL_6:
      if ( num != this->targets.size )
      {
        idList<idTargetInfo,5>::PreAllocateWithGranularity(this: &this->targets, newSize: num + 1);
        v12 = this->targets.num;
        size = this->targets.size;
        list = this->targets.list;
        if ( v12 >= size )
        {
          idTargetInfo::Cache(this: &list[size - 1], ownerState, es_: v7);
        }
        else
        {
          this->targets.num = v12 + 1;
          idTargetInfo::Cache(this: &list[v12], ownerState, es_: v7);
        }
      }
    }
    else
    {
      v10 = this->targets.list;
      v11 = 0;
      while ( v10[v11].es->spawnId.value != targetSpawnId->value )
      {
        ++v9;
        ++v11;
        if ( v9 >= this->targets.num )
          goto LABEL_6;
      }
      idTargetInfo::Cache(this: &v10[v9], ownerState, es_: v7);
    }
  }
}

