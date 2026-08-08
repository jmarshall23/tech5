
// ========================================================================
// ?QueueVisTrace@idBotTraceManager@@AAA?AW4queueTraceResults_t@@HH@Z
// EA  : 0x82B49FA8
// RVA : 0x00B49FA8
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

int __fastcall idBotTraceManager::QueueVisTrace(
        idBotTraceManager *this,
        unsigned int srcIndex,
        unsigned int targetIndex)
{
  unsigned __int64 v6; // r4
  idEntity *v7; // r30
  idEntity *v8; // r3
  idEntity *v9; // r29
  int numActiveTraces; // r11
  idBotTraceManager::traceWorkData_t *v11; // r31
  int v13; // [sp+8h] [-C8h]
  bool v14; // [sp+Fh] [-C1h]
  const char *v15; // [sp+10h] [-C0h]
  int v16; // [sp+14h] [-BCh]
  int v17; // [sp+18h] [-B8h]
  int v18; // [sp+1Ch] [-B4h]
  int v19; // [sp+20h] [-B0h]
  int v20; // [sp+24h] [-ACh]
  int v21; // [sp+28h] [-A8h]
  int v22; // [sp+2Ch] [-A4h]
  int v23; // [sp+30h] [-A0h]
  int v24; // [sp+34h] [-9Ch]
  int v25; // [sp+38h] [-98h]
  int v26; // [sp+3Ch] [-94h]
  int v27; // [sp+40h] [-90h]
  int v28; // [sp+44h] [-8Ch]
  int v29; // [sp+48h] [-88h]
  int v30; // [sp+4Ch] [-84h]
  int v31; // [sp+50h] [-80h]
  int v32; // [sp+58h] [-78h]
  int v33; // [sp+60h] [-70h]
  char v34; // [sp+70h] [-60h] BYREF
  idVec3 v35; // [sp+78h] [-58h] BYREF
  idVec3 v36[6]; // [sp+88h] [-48h] BYREF

  if ( this->numActiveTraces >= 8 )
    return 0;
  if ( srcIndex >= 0x20 )
    return 1;
  if ( targetIndex >= 0x20 )
    return 1;
  v7 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&this->entityData[srcIndex].ent);
  v8 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&this->entityData[targetIndex].ent);
  v9 = v8;
  if ( v7 == nullptr || v8 == nullptr )
    return 1;
  v7->GetEyePos(this: v7, a2: v36);
  v9->GetEyePos(this: v9, a2: &v35);
  numActiveTraces = this->numActiveTraces;
  this->numActiveTraces = numActiveTraces + 1;
  v11 = &this->traceWorkData[numActiveTraces];
  v11->srcIndex = srcIndex;
  v11->targetIndex = targetIndex;
  v6 = *(_QWORD *)&idClip::Translation(
                     this: (idClip *)&v34,
                     result: &clientGame->clip,
                     a3: nullptr,
                     start: v36,
                     end: &v35,
                     clipModel: nullptr,
                     startAxis: &mat3_identity,
                     clipMask: 8462469,
                     passEntityNumber: v13,
                     moveClipModel: v14,
                     userName: v15,
                     a12: v16,
                     a13: v17,
                     a14: v18,
                     a15: v19,
                     a16: v20,
                     a17: v21,
                     a18: v22,
                     a19: v23,
                     a20: v24,
                     a21: v25,
                     a22: v26,
                     a23: v27,
                     a24: v28,
                     a25: v29,
                     a26: v30,
                     a27: v31,
                     a28: 0x2000,
                     a29: v32,
                     a30: false,
                     a31: v33,
                     a32: (int)"BotVisCast")->world;
  HIDWORD(v6) = 2;
  v11->clipQuery.index = v6;
  return HIDWORD(v6);
}


// ========================================================================
// ?DebugDraw@idBotTraceManager@@AAAXH@Z
// EA  : 0x82B4A0F0
// RVA : 0x00B4A0F0
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

void __fastcall idBotTraceManager::DebugDraw(idBotTraceManager *this, const int curTime)
{
  idEntityPtr<idEntity const > *p_ent; // r20
  int v5; // r25
  idEntityPtr<idEntity const > *v6; // r22
  idEntity *v7; // r3
  idEntity *v8; // r29
  __int64 v9; // r9
  int value; // r11
  idPhysics *Physics; // r30
  idRenderWorld *v12; // r27
  idPhysics *v13; // r3
  int v14; // r17
  idRenderWorld_vtbl *v15; // r31
  int v16; // r3
  int v17; // r30
  idEntityPtr<idEntity const > *v18; // r27
  idEntity *v19; // r3
  idEntity *v20; // r31
  __int64 v21; // r9
  int v22; // r3
  const idColor *v23; // r4
  idRenderWorld *v24; // r3
  idVec3 v25; // [sp+60h] [-D0h] BYREF
  idVec3 v26; // [sp+70h] [-C0h] BYREF
  idColor v27; // [sp+80h] [-B0h] BYREF
  idColor v28; // [sp+90h] [-A0h] BYREF

  p_ent = &this->entityData[0].ent;
  v5 = 2;
  v6 = &this->entityData[0].ent;
  do
  {
    if ( gameLocal->spawnIds.ptr[v6->spawnId.value & 0x1FFF] == v6->spawnId.value >> 13 )
    {
      v7 = gameLocal->entities.ptr[v6->spawnId.value & 0x1FFF];
      if ( v7 != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
        if ( v8 != nullptr )
        {
          value = v6[-1].spawnId.value;
          v28.a = -1.0;
          v28.b = -1.0;
          v28.g = -1.0;
          v28.r = -1.0;
          LODWORD(v9) = curTime - value;
          idColor::Lerp(
            this: &v28,
            from: &idColor::colorCyan,
            to: &idColor::colorBlack,
            lerp: (float)((float)v9 * (float)0.001));
          Physics = idEntity::GetPhysics(this: v8);
          v12 = gameLocal->GetRenderWorld(this: gameLocal);
          v13 = idEntity::GetPhysics(this: v8);
          v14 = (int)v13->GetOrigin(this: v13, a2: 0);
          v15 = v12->__vftable;
          v16 = (int)Physics->GetBounds(this: Physics, a2: -1);
          v15->DebugBounds(
            this: v12,
            a2: (const idVec4 *)&v28,
            a3: (const idBounds *)v16,
            a4: (const idVec3 *)v14,
            a5: 0,
            a6: false);
          v17 = 0;
          v18 = p_ent;
          do
          {
            if ( gameLocal->spawnIds.ptr[v18->spawnId.value & 0x1FFF] == v18->spawnId.value >> 13 )
            {
              v19 = gameLocal->entities.ptr[v18->spawnId.value & 0x1FFF];
              if ( v19 != nullptr )
              {
                v20 = idEntity::CastTo(c: v19);
                if ( v20 != nullptr )
                {
                  v8->GetEyePos(this: v8, a2: &v26);
                  v20->GetEyePos(this: v20, a2: &v25);
                  v27.a = -1.0;
                  v27.b = -1.0;
                  v27.g = -1.0;
                  v27.r = -1.0;
                  v22 = *(&this->curEntDataIndex + 2 * v5 + 2 * v17);
                  v23 = &idColor::colorGreen;
                  if ( v22 != *((_DWORD *)this + 2 * v5 + 2 * v17 - 1) )
                    v23 = &idColor::colorRed;
                  LODWORD(v21) = curTime - v22;
                  idColor::Lerp(
                    this: &v27,
                    from: v23,
                    to: &idColor::colorBlack,
                    lerp: (float)((float)v21 * (float)0.001));
                  v24 = gameLocal->GetRenderWorld(this: gameLocal);
                  v24->DebugLine(this: v24, a2: (const idVec4 *)&v27, a3: &v26, a4: &v25, a5: 0, a6: false);
                }
              }
            }
            ++v17;
            v18 += 2;
          }
          while ( v17 < 32 );
        }
      }
    }
    v5 += 32;
    v6 += 2;
  }
  while ( v5 < 194 );
}


// ========================================================================
// ?GetIndexForEntity@idBotTraceManager@@ABAHPBVidEntity@@@Z
// EA  : 0x82B4A3B0
// RVA : 0x00B4A3B0
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

int __fastcall idBotTraceManager::GetIndexForEntity(idBotTraceManager *this, idEntity *ent)
{
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  int v8; // r29
  idEntityPtr<idEntity const > *p_ent; // r31
  idGameLocal *v10; // r10
  idEntity *v11; // r3
  idEntity *v12; // r3

  v4 = *(_DWORD *)(ent->GetType(this: ent) + 36);
  if ( v4 < idPlayer::Type.typeNum || (v6 = v4 <= idPlayer::Type.lastChild, v5 = 1, !v6) )
    v5 = 0;
  if ( v5 != 0 )
    return ent->entityNumber;
  v8 = 0;
  p_ent = &this->entityData[0].ent;
  v10 = gameLocal;
  while ( 1 )
  {
    if ( v10->spawnIds.ptr[p_ent->spawnId.value & 0x1FFF] == p_ent->spawnId.value >> 13
      && (v11 = v10->entities.ptr[p_ent->spawnId.value & 0x1FFF]) != nullptr )
    {
      v12 = idEntity::CastTo(c: v11);
      v10 = gameLocal;
    }
    else
    {
      v12 = nullptr;
    }
    if ( ent == v12 )
      break;
    ++v8;
    p_ent += 2;
    if ( v8 >= 32 )
      return -1;
  }
  return v8;
}


// ========================================================================
// ?Update@idBotTraceManager@@QAAXH@Z
// EA  : 0x82B4A4A8
// RVA : 0x00B4A4A8
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

void __fastcall idBotTraceManager::Update(idBotTraceManager *this, int curTime)
{
  __int64 v2; // r18
  __int64 v5; // r18
  __int64 v6; // r3
  int *p_targetIndex; // r29
  int i; // r24
  __int64 v9; // r11
  unsigned int v10; // r9
  char v11; // r9
  bool v12; // zf
  __int64 v13; // r11
  int curEntDataIndex; // r11
  unsigned int curTraceIndex; // r5
  int v16; // r10
  int v17; // r8
  int v18; // r4
  int v19; // r5
  int v20; // r10
  int *list; // r11
  int v22; // r9
  int v23; // r7
  int v24; // r28
  int v25; // r29
  int v26; // r10
  unsigned int v27; // r5
  int v28; // r10
  int v29; // r3
  __int64 v30; // r10
  __int64 v31; // r11
  double clockTicks; // fp31
  __int128 v33; // r4
  idTimer v34; // [sp+50h] [-140h] BYREF
  __int64 v35; // [sp+70h] [-120h]
  trace_t v36; // [sp+80h] [-110h] BYREF

  if ( this->playerUpdateIndexes.num < 2 )
    return;
  LODWORD(v2) = 0;
  v34.state = TS_STOPPED;
  v34.clockTicks = v2;
  v34.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  HIDWORD(v5) = &bot_debugTraceManager;
  if ( bot_debugTraceManager.valueInteger != 0 )
  {
    idBotTraceManager::DebugDraw(this, curTime);
    v34.state = TS_STARTED;
    LODWORD(v6) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v34.start = v6;
  }
  p_targetIndex = &this->traceWorkData[0].targetIndex;
  for ( i = 8; i != 0; --i )
  {
    v9 = *(_QWORD *)(p_targetIndex + 1);
    HIDWORD(v9) += 10688;
    if ( (unsigned int)v9 < *(_DWORD *)(HIDWORD(v9) + 377212) || (unsigned int)v9 > *(_DWORD *)(HIDWORD(v9) + 377220) )
    {
      v11 = 0;
    }
    else
    {
      v10 = *(_DWORD *)(8 * ((v9 & 0xFFF) + ((2 * v9) & 0x1FFE)) + HIDWORD(v9) + 278924);
      if ( v10 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
        || (v12 = v10 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v11 = 1, !v12) )
      {
        v11 = 0;
      }
    }
    if ( v11 != 0 && (unsigned int)v9 <= LODWORD(clientGame->clip.collisionQueryLastSubmittedIndex) )
    {
      v13 = *(_QWORD *)(p_targetIndex + 1);
      *(_QWORD *)(p_targetIndex + 1) = v5;
      HIDWORD(v35) = HIDWORD(v13);
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v36,
        query: (idCollisionQuery *)(24 * (v13 & 0xFFF) + HIDWORD(v13) + 278920),
        peek: false);
      if ( v36.fraction == 1.0 )
      {
        this->perceptionTable[*(p_targetIndex - 1)][*p_targetIndex].lastSeenTime = curTime;
        if ( *p_targetIndex < 6 )
          this->perceptionTable[*p_targetIndex][*(p_targetIndex - 1)].lastSeenTime = curTime;
      }
      this->perceptionTable[*(p_targetIndex - 1)][*p_targetIndex].lastUpdateTime = curTime;
      if ( *p_targetIndex < 6 )
        this->perceptionTable[*p_targetIndex][*(p_targetIndex - 1)].lastUpdateTime = curTime;
    }
    p_targetIndex += 4;
  }
  curEntDataIndex = this->curEntDataIndex;
  this->numActiveTraces = 0;
  if ( curEntDataIndex != -1 )
  {
    if ( gameLocal->spawnIds.ptr[this->entityData[curEntDataIndex].ent.spawnId.value & 0x1FFF] == this->entityData[curEntDataIndex].ent.spawnId.value >> 13 )
    {
      this->curTraceIndex = 0;
      while ( 1 )
      {
        curTraceIndex = this->curTraceIndex;
        if ( gameLocal->spawnIds.ptr[this->entityData[curTraceIndex].ent.spawnId.value & 0x1FFF] == this->entityData[curTraceIndex].ent.spawnId.value >> 13
          && curTraceIndex != this->curEntDataIndex
          && idBotTraceManager::QueueVisTrace(this, srcIndex: this->curEntDataIndex, targetIndex: curTraceIndex) == 0 )
        {
          goto TracesFinished;
        }
        v16 = this->curTraceIndex + 1;
        this->curTraceIndex = v16;
        if ( v16 >= 32 )
        {
          this->entityData[this->curEntDataIndex].lastUpdateTime = curTime;
          goto LABEL_29;
        }
      }
    }
    this->curEntDataIndex = -1;
  }
LABEL_29:
  if ( this->playerUpdateIndexes.num > 0 )
  {
    v17 = 0;
    v18 = 1;
    do
    {
      v19 = v18;
      if ( v18 < this->playerUpdateIndexes.num )
      {
        v20 = v17 * 4 + 4;
        do
        {
          list = this->playerUpdateIndexes.list;
          v22 = *(int *)((char *)list + v20);
          if ( this->entityData[list[v17]].lastUpdateTime > this->entityData[v22].lastUpdateTime )
          {
            v23 = list[v17];
            list[v17] = v22;
            *(int *)((char *)this->playerUpdateIndexes.list + v20) = v23;
          }
          ++v19;
          v20 += 4;
        }
        while ( v19 < this->playerUpdateIndexes.num );
      }
      ++v18;
      ++v17;
    }
    while ( v18 - 1 < this->playerUpdateIndexes.num );
  }
  v24 = 0;
  if ( this->playerUpdateIndexes.num > 0 )
  {
    v25 = 0;
LABEL_39:
    v26 = this->playerUpdateIndexes.list[v25];
    this->curTraceIndex = 0;
    this->curEntDataIndex = v26;
    while ( 1 )
    {
      v27 = this->curTraceIndex;
      if ( gameLocal->spawnIds.ptr[this->entityData[v27].ent.spawnId.value & 0x1FFF] == this->entityData[v27].ent.spawnId.value >> 13
        && v27 != this->curEntDataIndex
        && this->entityData[v27].lastUpdateTime != curTime
        && idBotTraceManager::QueueVisTrace(this, srcIndex: this->curEntDataIndex, targetIndex: v27) == 0 )
      {
        break;
      }
      v28 = this->curTraceIndex + 1;
      this->curTraceIndex = v28;
      if ( v28 >= 32 )
      {
        ++v24;
        ++v25;
        this->entityData[this->curEntDataIndex].lastUpdateTime = curTime;
        this->curEntDataIndex = -1;
        if ( v24 < this->playerUpdateIndexes.num )
          goto LABEL_39;
        break;
      }
    }
  }
TracesFinished:
  if ( bot_debugTraceManager.valueInteger != 0 )
  {
    v29 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    HIDWORD(v30) = 0x82000000;
    LODWORD(v30) = v29 + LODWORD(v34.clockTicks) - LODWORD(v34.start);
    v34.clockTicks = v30;
    if ( (float)idTimer::base < 0.0 )
      idTimer::InitBaseClockTicks(this: &v34);
    HIDWORD(v31) = HIDWORD(idTimer::base);
    if ( SHIDWORD(idTimer::base) > (int)idTimer::base )
    {
      LODWORD(v31) = HIDWORD(idTimer::base) - idTimer::base;
      v34.clockTicks = v31;
    }
    v34.state = TS_STOPPED;
    clockTicks = (float)v34.clockTicks;
    DWORD2(v33) = Sys_ClockTicksPerSecond();
    v35 = *(_QWORD *)((char *)&v33 + 4);
    *((double *)&v33 + 1) = (float)((float)clockTicks / (float)((float)*(__int64 *)((char *)&v33 + 4) * (float)0.001));
    idLib::Printf(fmt: (const char *)DWORD2(v33), (_DWORD)v33);
  }
}


// ========================================================================
// __unwind$488185
// EA  : 0x82B4A998
// RVA : 0x00B4A998
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

void _unwind_488185()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 400 + 80));
}


// ========================================================================
// ?RemoveEntity@idBotTraceManager@@QAAXPBVidEntity@@@Z
// EA  : 0x82B4A9C0
// RVA : 0x00B4A9C0
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

void __fastcall idBotTraceManager::RemoveEntity(idBotTraceManager *this, idEntity *ent)
{
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  int entityNumber; // r8
  int v8; // r11
  int num; // r7
  int i; // r10
  int v11; // r10
  int v12; // r10
  int v13; // r28
  idEntityPtr<idEntity const > *p_ent; // r31
  idGameLocal *v15; // r9
  idEntity *v16; // r3
  idEntity *v17; // r3

  v4 = *(_DWORD *)(ent->GetType(this: ent) + 36);
  if ( v4 < idPlayer::Type.typeNum || (v6 = v4 <= idPlayer::Type.lastChild, v5 = 1, !v6) )
    v5 = 0;
  if ( v5 != 0 )
  {
    entityNumber = ent->entityNumber;
    v8 = 0;
    this->entityData[entityNumber].ent.spawnId.value = 0x1FFF;
    num = this->playerUpdateIndexes.num;
    if ( num > 0 )
    {
      for ( i = 0; this->playerUpdateIndexes.list[i] != entityNumber; ++i )
      {
        if ( ++v8 >= num )
          return;
      }
      if ( v8 >= 0 )
      {
        v11 = this->playerUpdateIndexes.num;
        if ( v8 < v11 )
        {
          v12 = v11 - 1;
          this->playerUpdateIndexes.num = v12;
          if ( v8 != v12 )
            this->playerUpdateIndexes.list[v8] = this->playerUpdateIndexes.list[v12];
        }
      }
    }
  }
  else
  {
    v13 = 6;
    p_ent = &this->entityData[6].ent;
    v15 = gameLocal;
    while ( 1 )
    {
      if ( v15->spawnIds.ptr[p_ent->spawnId.value & 0x1FFF] == p_ent->spawnId.value >> 13 )
      {
        v16 = v15->entities.ptr[p_ent->spawnId.value & 0x1FFF];
        if ( v16 != nullptr )
        {
          v17 = idEntity::CastTo(c: v16);
          v15 = gameLocal;
        }
        else
        {
          v17 = nullptr;
        }
        if ( v17 == ent )
          break;
      }
      ++v13;
      p_ent += 2;
      if ( v13 >= 32 )
        return;
    }
    this->entityData[v13].ent.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?IsVisible@idBotTraceManager@@QAA_NPBVidEntity@@0H@Z
// EA  : 0x82B4AB58
// RVA : 0x00B4AB58
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

BOOL __fastcall idBotTraceManager::IsVisible(idBotTraceManager *this, idEntity *ent, idEntity *otherEnt, int timeDelta)
{
  int IndexForEntity; // r29
  int v8; // r3

  IndexForEntity = idBotTraceManager::GetIndexForEntity(this, ent);
  v8 = idBotTraceManager::GetIndexForEntity(this, ent: otherEnt);
  return IndexForEntity != -1
      && v8 != -1
      && timeDelta >= this->perceptionTable[IndexForEntity][v8].lastUpdateTime
                    - this->perceptionTable[IndexForEntity][v8].lastSeenTime;
}


// ========================================================================
// ??0idBotTraceManager@@QAA@XZ
// EA  : 0x82B4ABE0
// RVA : 0x00B4ABE0
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

idBotTraceManager *__fastcall idBotTraceManager::idBotTraceManager(idBotTraceManager *this)
{
  int *p_lastUpdateTime; // r11
  int v3; // ctr
  unsigned __int64 v4; // r10

  p_lastUpdateTime = &this->perceptionTable[5][31].lastUpdateTime;
  v3 = 32;
  LODWORD(v4) = 0;
  do
  {
    p_lastUpdateTime[1] = 0;
    p_lastUpdateTime += 2;
    *p_lastUpdateTime = 0x1FFF;
    --v3;
  }
  while ( v3 != 0 );
  this->traceWorkData[0].srcIndex = -1;
  this->traceWorkData[0].targetIndex = -1;
  HIDWORD(v4) = this->playerUpdateIndexes.staticList;
  this->traceWorkData[0].clipQuery.index = v4;
  this->traceWorkData[1].srcIndex = -1;
  this->traceWorkData[1].targetIndex = -1;
  this->traceWorkData[1].clipQuery.index = v4;
  this->traceWorkData[2].srcIndex = -1;
  this->traceWorkData[2].targetIndex = -1;
  this->traceWorkData[2].clipQuery.index = v4;
  this->traceWorkData[3].srcIndex = -1;
  this->traceWorkData[3].targetIndex = -1;
  this->traceWorkData[3].clipQuery.index = v4;
  this->traceWorkData[4].srcIndex = -1;
  this->traceWorkData[4].targetIndex = -1;
  this->traceWorkData[4].clipQuery.index = v4;
  this->traceWorkData[5].srcIndex = -1;
  this->traceWorkData[5].targetIndex = -1;
  this->traceWorkData[5].clipQuery.index = v4;
  this->traceWorkData[6].srcIndex = -1;
  this->traceWorkData[6].targetIndex = -1;
  this->traceWorkData[6].clipQuery.index = v4;
  this->traceWorkData[7].srcIndex = -1;
  this->traceWorkData[7].targetIndex = -1;
  this->traceWorkData[7].clipQuery.index = v4;
  this->playerUpdateIndexes.size = 6;
  this->playerUpdateIndexes.num = 0;
  this->playerUpdateIndexes.granularity = 1;
  this->playerUpdateIndexes.list = this->playerUpdateIndexes.staticList;
  this->playerUpdateIndexes.memTag = 5;
  this->playerUpdateIndexes.listStatic = 1;
  this->numActiveTraces = 0;
  this->curEntDataIndex = -1;
  this->curTraceIndex = 0;
  memset(Dst: this->perceptionTable, Val: 0, Size: sizeof(this->perceptionTable));
  return this;
}


// ========================================================================
// ??1idBotTraceManager@@QAA@XZ
// EA  : 0x82B4ACD8
// RVA : 0x00B4ACD8
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

void __fastcall idBotTraceManager::~idBotTraceManager(idBotTraceManager *this)
{
  int v1; // ctr
  unsigned __int64 v2; // r10

  LODWORD(v2) = &this->perceptionTable[5][31].lastUpdateTime;
  v1 = 32;
  HIDWORD(v2) = 0x1FFF;
  do
  {
    LODWORD(v2) = v2 + 8;
    *(_DWORD *)v2 = 0x1FFF;
    --v1;
  }
  while ( v1 != 0 );
  LODWORD(v2) = 0;
  this->traceWorkData[0].clipQuery.index = v2;
  this->traceWorkData[1].clipQuery.index = v2;
  this->traceWorkData[2].clipQuery.index = v2;
  this->traceWorkData[3].clipQuery.index = v2;
  this->traceWorkData[4].clipQuery.index = v2;
  this->traceWorkData[5].clipQuery.index = v2;
  this->traceWorkData[6].clipQuery.index = v2;
  this->traceWorkData[7].clipQuery.index = v2;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerUpdateIndexes);
}


// ========================================================================
// ?AddEntity@idBotTraceManager@@QAAXPBVidEntity@@@Z
// EA  : 0x82B4AD20
// RVA : 0x00B4AD20
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

void __fastcall idBotTraceManager::AddEntity(idBotTraceManager *this, idEntity *ent)
{
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  int entityNumber; // r10
  int v8; // r11
  int v9; // r9
  int i; // ctr
  int v11; // r10
  int v12; // r10
  idEntityPtr<idEntity const > *j; // r11
  encounterGroupRole_t v14[2]; // [sp+50h] [-20h] BYREF

  v4 = *(_DWORD *)(ent->GetType(this: ent) + 36);
  if ( v4 < idPlayer::Type.typeNum || (v6 = v4 <= idPlayer::Type.lastChild, v5 = 1, !v6) )
    v5 = 0;
  if ( v5 != 0 )
  {
    entityNumber = ent->entityNumber;
    v14[0] = entityNumber;
    this->entityData[entityNumber].ent.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
    if ( entityNumber < 6 )
    {
      v8 = 0;
      v9 = 32 * entityNumber;
      for ( i = 32; i != 0; --i )
      {
        v11 = v9 + v8++;
        this->perceptionTable[0][v11].lastSeenTime = 0;
      }
    }
    idList<int,46>::AddUnique(this: &this->playerUpdateIndexes, obj: v14);
  }
  else
  {
    v12 = 6;
    for ( j = &this->entityData[6].ent; gameLocal->spawnIds.ptr[j->spawnId.value & 0x1FFF] == j->spawnId.value >> 13; j += 2 )
    {
      if ( ++v12 >= 32 )
        return;
    }
    this->entityData[v12].ent.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  }
}


// ========================================================================
// `dynamic initializer for 'bot_debugTraceManager''
// EA  : 0x8336CF88
// RVA : 0x0136CF88
// PDB : w:\tech5\tungsten\game\bot\global\bot_tracemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_debugTraceManager__()
{
  idCVar::idCVar(
    this: &bot_debugTraceManager,
    name: "bot_debugTraceManager",
    value: "0",
    flags: 1,
    description: "draws trace manager debug information",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_debugTraceManager__);
}

