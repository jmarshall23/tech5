
// ========================================================================
// ??0idDeferredVisGrid@@QAA@XZ
// EA  : 0x826B8AD8
// RVA : 0x006B8AD8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

idDeferredVisGrid *__fastcall idDeferredVisGrid::idDeferredVisGrid(idDeferredVisGrid *this)
{
  this->xyz[2] = 0;
  this->xyz[1] = 0;
  this->xyz[0] = 0;
  memset(Dst: this, Val: 0, Size: 0x40u);
  return this;
}


// ========================================================================
// ?AllocNode@idDeferredVisCache@@AAAPAVidDeferredVisQuery@@XZ
// EA  : 0x826B8B20
// RVA : 0x006B8B20
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

idDeferredVisQuery *__fastcall idDeferredVisCache::AllocNode(idDeferredVisCache *this)
{
  idDeferredVisQuery *queryList; // r11

  queryList = this->queryList;
  if ( queryList == nullptr )
    return nullptr;
  this->queryList = queryList->next;
  queryList->nextInHash = nullptr;
  queryList->prev = nullptr;
  queryList->next = nullptr;
  queryList->frameCounter = -1;
  queryList->state = 0;
  ++numQueriesAlloc;
  return queryList;
}


// ========================================================================
// ?FreeLinkedList@idDeferredVisCache@@AAAXAAUdeferredVisList_t@@@Z
// EA  : 0x826B8B70
// RVA : 0x006B8B70
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::FreeLinkedList(idDeferredVisCache *this, deferredVisList_t *list)
{
  idDeferredVisQuery *i; // r11
  idDeferredVisQuery *queryList; // r6
  idDeferredVisQuery *v4; // r5
  idDeferredVisQuery **p_next; // r9

  for ( i = list->headNode; i != nullptr; --numQueriesAlloc )
  {
    queryList = this->queryList;
    v4 = i;
    p_next = &i->next;
    i = i->next;
    v4->state = 0;
    *p_next = queryList;
    v4->frameCounter = -1;
    this->queryList = v4;
  }
  list->headNode = nullptr;
  list->tailNode = nullptr;
  list->numElements = 0;
}


// ========================================================================
// ?RemoveNoDelete@idDeferredVisCache@@AAAXAAUdeferredVisList_t@@PAVidDeferredVisQuery@@@Z
// EA  : 0x826B8BD0
// RVA : 0x006B8BD0
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::RemoveNoDelete(
        idDeferredVisCache *this,
        deferredVisList_t *list,
        idDeferredVisQuery *node)
{
  idDeferredVisQuery *prev; // r11
  idDeferredVisQuery *next; // r11

  prev = node->prev;
  if ( prev != nullptr )
    prev->next = node->next;
  else
    list->headNode = node->next;
  next = node->next;
  if ( next != nullptr )
    next->prev = node->prev;
  else
    list->tailNode = node->prev;
  --list->numElements;
  node->next = nullptr;
  node->prev = nullptr;
}


// ========================================================================
// ?AddToFront@idDeferredVisCache@@AAAXAAUdeferredVisList_t@@PAVidDeferredVisQuery@@@Z
// EA  : 0x826B8C30
// RVA : 0x006B8C30
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::AddToFront(
        idDeferredVisCache *this,
        deferredVisList_t *list,
        idDeferredVisQuery *newNode)
{
  idDeferredVisQuery *headNode; // r11
  idDeferredVisQuery *prev; // r10
  idDeferredVisQuery *v5; // r10

  headNode = list->headNode;
  if ( list->headNode != nullptr )
  {
    prev = headNode->prev;
    newNode->next = headNode;
    newNode->prev = prev;
    v5 = headNode->prev;
    if ( v5 != nullptr )
      v5->next = nullptr;
    else
      list->headNode = newNode;
    headNode->prev = newNode;
    ++list->numElements;
  }
  else
  {
    list->headNode = newNode;
    list->tailNode = newNode;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    ++list->numElements;
  }
}


// ========================================================================
// ?Init@idDeferredVisCache@@QAAXPAVidClip@@@Z
// EA  : 0x826B8CA8
// RVA : 0x006B8CA8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::Init(idDeferredVisCache *this, idClip *inClip)
{
  this->clip = inClip;
  this->initialized = true;
}


// ========================================================================
// ?DebugDrawGrid@idDeferredVisGrid@@ABAXXZ
// EA  : 0x826B8CB8
// RVA : 0x006B8CB8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredVisGrid::DebugDrawGrid(idDeferredVisGrid *this, int a2, int a3, __int64 a4)
{
  int v5; // r25
  int v6; // r28
  int i; // r24
  __int64 v8; // r11
  int v9; // r30
  double v10; // fp28
  float v11; // r26
  int v12; // r29
  double v13; // fp30
  __int16 v14; // r11
  __int64 v15; // r10
  float *v16; // r11
  float v17; // r8
  float v18; // r7
  float v19; // r6
  idRenderWorld *v20; // r3
  idRenderWorld *v21; // r3
  idRenderWorld *v22; // r3
  idRenderWorld *v23; // r3
  idRenderWorld *v24; // r3
  idRenderWorld *v25; // r3
  __int64 v26; // r4 OVERLAPPED
  __int16 v27; // r9
  __int16 v28; // r7
  __int16 v29; // r6
  __int16 v30; // r8
  __int64 v31; // r6 OVERLAPPED
  _DWORD v32[3]; // [sp+60h] [-140h] BYREF
  float v33[3]; // [sp+6Ch] [-134h] BYREF
  float v34[3]; // [sp+78h] [-128h] BYREF
  float v35[3]; // [sp+84h] [-11Ch] BYREF
  float v36; // [sp+90h] [-110h]
  float v37; // [sp+94h] [-10Ch]
  float v38; // [sp+98h] [-108h]
  __int64 v39; // [sp+A0h] [-100h]
  __int64 v40; // [sp+A8h] [-F8h]
  idVec4 v41; // [sp+B0h] [-F0h] BYREF
  float v42[4]; // [sp+C0h] [-E0h] BYREF
  float v43[4]; // [sp+D0h] [-D0h] BYREF
  float v44[4]; // [sp+E0h] [-C0h] BYREF
  float v45[26]; // [sp+F0h] [-B0h] BYREF

  v5 = this->xyz[1] - 144;
  v6 = 0;
  for ( i = 8; i != 0; --i )
  {
    LODWORD(v8) = v5;
    HIDWORD(v8) = (unsigned __int16)this->xyz[0];
    v9 = 8;
    v40 = v8;
    v10 = (float)v8;
    v37 = (float)v8;
    v11 = v37;
    v12 = SWORD1(v8) - 144;
    v13 = (float)(v37 + (float)32.0);
    do
    {
      v14 = this->xyz[2];
      LODWORD(v15) = v12;
      HIDWORD(v15) = this->cells[v6];
      v33[1] = v10;
      LODWORD(a4) = v14;
      v39 = v15;
      v36 = (float)v15;
      v35[0] = v36;
      *(float *)&v32[1] = v11;
      v34[1] = v13;
      v35[1] = v13;
      *(float *)v32 = v36;
      v33[0] = v36 + (float)32.0;
      v34[0] = v33[0];
      v38 = (float)a4;
      v33[2] = v38;
      v35[2] = v38;
      *(float *)&v32[2] = v38;
      v34[2] = v38;
      if ( HIDWORD(v15) != 0 )
      {
        v44[0] = 0.0;
        v16 = v44;
        v44[1] = 1.0;
        v44[2] = 0.0;
        v44[3] = 1.0;
      }
      else
      {
        v43[0] = 1.0;
        v16 = v43;
        v43[1] = 0.0;
        v43[2] = 1.0;
        v43[3] = 1.0;
      }
      v17 = v16[1];
      v18 = v16[2];
      v19 = v16[3];
      v41.x = *v16;
      v41.y = v17;
      v41.z = v18;
      v41.w = v19;
      v20 = common->RW(this: common);
      v20->DebugLine(this: v20, a2: &v41, a3: (const idVec3 *)v32, a4: (const idVec3 *)v33, a5: 0, a6: false);
      v21 = common->RW(this: common);
      v21->DebugLine(this: v21, a2: &v41, a3: (const idVec3 *)v33, a4: (const idVec3 *)v34, a5: 0, a6: false);
      v22 = common->RW(this: common);
      v22->DebugLine(this: v22, a2: &v41, a3: (const idVec3 *)v34, a4: (const idVec3 *)v35, a5: 0, a6: false);
      v23 = common->RW(this: common);
      v23->DebugLine(this: v23, a2: &v41, a3: (const idVec3 *)v35, a4: (const idVec3 *)v32, a5: 0, a6: false);
      v24 = common->RW(this: common);
      v24->DebugLine(this: v24, a2: &v41, a3: (const idVec3 *)v32, a4: (const idVec3 *)v34, a5: 0, a6: false);
      v25 = common->RW(this: common);
      v25->DebugLine(this: v25, a2: &v41, a3: (const idVec3 *)v33, a4: (const idVec3 *)v35, a5: 0, a6: false);
      --v9;
      ++v6;
      v12 += 32;
    }
    while ( v9 != 0 );
    v5 += 32;
  }
  HIDWORD(v26) = common->RW(this: common);
  v27 = this->xyz[1];
  v28 = this->xyz[0];
  v45[3] = 1.0;
  v29 = this->xyz[2];
  v45[4] = 1.0;
  v45[5] = 1.0;
  v30 = v29;
  v45[6] = mat3_identity.mat[0].x;
  v42[0] = 1.0;
  LODWORD(v31) = v27 - 16;
  v39 = v31;
  LODWORD(v26) = v28 - 16;
  v40 = v26;
  v45[7] = mat3_identity.mat[0].y;
  v45[8] = mat3_identity.mat[0].z;
  v45[10] = mat3_identity.mat[1].y;
  v45[9] = mat3_identity.mat[1].x;
  v45[11] = mat3_identity.mat[1].z;
  v45[12] = mat3_identity.mat[2].x;
  v45[13] = mat3_identity.mat[2].y;
  v45[14] = mat3_identity.mat[2].z;
  v42[1] = 0.0;
  v42[2] = 0.0;
  v42[3] = 1.0;
  v45[1] = (float)v31;
  HIDWORD(v31) = v30;
  v45[0] = (float)v26;
  v45[2] = (float)*(__int64 *)((char *)&v26 - 4);
  (*(void (__fastcall **)(_DWORD, float *, float *, _DWORD, _DWORD))(*(_DWORD *)HIDWORD(v26) + 228))(
    a1: HIDWORD(v26),
    a2: v42,
    a3: v45,
    a4: 0,
    a5: 0);
}


// ========================================================================
// ?PrintDebugInfo@idDeferredVisCache@@QAAXXZ
// EA  : 0x826B9080
// RVA : 0x006B9080
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::PrintDebugInfo(idDeferredVisCache *this)
{
  int v2; // r6
  int numQueriesIssued; // r10
  int v4; // r5
  int v5; // r4
  __int64 v6; // r8
  _BYTE v7[12]; // r11
  double v8; // fp0
  double v9; // fp1
  double v10; // fp31
  double v11; // fp27
  const char *v12; // r4
  double recentCacheHitRatio; // fp0
  const char *v14; // r4
  const char *v15; // r4
  idDeferredVisQuery *i; // r11
  int v17; // [sp+8h] [-D8h]
  int v18; // [sp+Ch] [-D4h]
  char v19[56]; // [sp+80h] [-60h] BYREF

  v2 = this->numFrames + 1;
  numQueriesIssued = this->numQueriesIssued;
  *(_DWORD *)v7 = this->numCacheHits;
  v4 = numQueriesIssued + this->totalQueriesIssued;
  v5 = this->totalCacheHits + *(_DWORD *)v7;
  HIDWORD(v6) = this->recentTotalQueriesIssued;
  *(_DWORD *)&v7[8] = this->recentNumFrames + 1;
  LODWORD(v6) = this->recentTotalCacheHits + *(_DWORD *)v7;
  this->numFrames = v2;
  *(_DWORD *)&v7[4] = HIDWORD(v6) + numQueriesIssued;
  this->totalQueriesIssued = v4;
  this->totalCacheHits = v5;
  this->recentNumFrames = *(_DWORD *)&v7[8];
  this->recentTotalCacheHits = v6;
  this->recentTotalQueriesIssued = *(_DWORD *)&v7[4];
  if ( *(int *)&v7[8] > 300 )
  {
    if ( *(_DWORD *)&v7[4] + (int)v6 <= 0 )
    {
      this->recentCacheHitRatio = -1.0;
    }
    else
    {
      *(_QWORD *)&v7[4] = __PAIR64__(v6, *(unsigned int *)&v7[4]);
      this->recentCacheHitRatio = (float)*(__int64 *)v7 / (float)((float)*(__int64 *)&v7[4] + (float)*(__int64 *)v7);
    }
    this->recentNumFrames = 0;
    this->recentTotalCacheHits = 0;
    this->recentTotalQueriesIssued = 0;
  }
  *(_DWORD *)&v7[8] = v4;
  *(_DWORD *)&v7[4] = this->numCreatedThisFrame;
  LODWORD(v6) = v2;
  v8 = (float)*(__int64 *)&v7[4];
  v9 = (float)((float)*(__int64 *)&v7[4] / (float)v6);
  if ( *(_DWORD *)&v7[4] + *(_DWORD *)v7 <= 0 )
  {
    v10 = -1.0;
  }
  else
  {
    LODWORD(v6) = *(_DWORD *)v7;
    *(_QWORD *)v19 = v6;
    *(_DWORD *)&v7[8] = *(_DWORD *)&v7[4] + *(_DWORD *)v7;
    v10 = (float)((float)v6 / (float)*(__int64 *)&v7[4]);
  }
  if ( v5 + v4 <= 0 )
  {
    v11 = -1.0;
  }
  else
  {
    *(_DWORD *)&v7[8] = v5;
    *(_QWORD *)v19 = *(_QWORD *)&v7[4];
    v11 = (float)((float)*(__int64 *)&v7[4] / (float)((float)*(__int64 *)&v7[4] + (float)v8));
  }
  if ( vis_showInfo.valueInteger != 0 )
  {
    idLib::Printf(
      fmt: "LRU:%d  Priority:%d\t Bumped:%d Purged:%d  Expired:%d  # Hits = %d Created:%d  Avg Issued = %5.2f  Alloc:%d  Max Created:%d ",
      this->leastRecentlyUsedList.numElements,
      this->priorityList.numElements,
      this->numBumped,
      this->numPurged,
      this->numExpired,
      *(_DWORD *)v7,
      *(_DWORD *)&v7[4],
      v9,
      v17,
      v18);
    if ( v10 >= 0.0 )
    {
      if ( v10 > 0.5 )
      {
        v12 = "^3";
        if ( v10 > 0.75 )
          v12 = "^2";
        sprintf_0(string: v19, format: v12);
      }
      else
      {
        sprintf_0(string: v19, format: "^1");
      }
      idLib::Printf(fmt: "Hit %% = %s%5.2f^0 ", (const char *)HIDWORD(v10), v10);
    }
    else
    {
      idLib::Printf(fmt: "Hit %% = N/A ");
    }
    recentCacheHitRatio = this->recentCacheHitRatio;
    if ( recentCacheHitRatio >= 0.0 )
    {
      if ( recentCacheHitRatio > 0.5 )
      {
        v14 = "^3";
        if ( recentCacheHitRatio > 0.75 )
          v14 = "^2";
        sprintf_0(string: v19, format: v14);
      }
      else
      {
        sprintf_0(string: v19, format: "^1");
      }
      idLib::Printf(fmt: "Recent Hit %% = %s%5.2f^0 ", v19, this->recentCacheHitRatio);
    }
    else
    {
      idLib::Printf(fmt: "Recent Hit %% = N/A ");
    }
    if ( v11 >= 0.0 )
    {
      if ( v11 > 0.5 )
      {
        v15 = "^3";
        if ( v11 > 0.75 )
          v15 = "^2";
        sprintf_0(string: v19, format: v15);
      }
      else
      {
        sprintf_0(string: v19, format: "^1");
      }
      idLib::Printf(fmt: "Avg Hit %% = %s%5.2f^0", (const char *)HIDWORD(v11), v11);
    }
    else
    {
      idLib::Printf(fmt: "Avg Hit %% =  N/A");
    }
    idLib::Printf(fmt: "\n");
  }
  if ( vis_checkLRU.valueInteger != 0 )
  {
    for ( i = this->leastRecentlyUsedList.headNode; i != nullptr; i = i->next )
      ;
  }
}


// ========================================================================
// ?Shutdown@idDeferredVisCache@@QAAXXZ
// EA  : 0x826B93C0
// RVA : 0x006B93C0
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::Shutdown(idDeferredVisCache *this)
{
  idDeferredVisCache *v2; // r3
  idList<int,5> *v3; // r3
  idDeferredVisQuery *queryList; // r11
  int v5; // r10
  int v6; // [sp+50h] [-20h] BYREF

  this->clip = nullptr;
  idDeferredVisCache::FreeLinkedList(this, list: &this->leastRecentlyUsedList);
  idDeferredVisCache::FreeLinkedList(this: v2, list: &v2->priorityList);
  v6 = 0;
  idList<idRenderModelCommitted *,5>::SetNum(this: v3, newNum: 4096, initValue: &v6);
  queryList = this->queryList;
  this->initialized = false;
  v5 = 0;
  this->numCreatedThisFrame = 0;
  for ( this->numBumped = 0; queryList != nullptr; ++v5 )
    queryList = queryList->next;
  numQueriesAlloc = 0;
  if ( v5 != 5120 )
    idLib::Warning(fmt: "idDeferredVisCache::Shutdown() - Not all vis queries returned back to the pool!");
  this->expiredIndex = 0;
  this->numFrames = 0;
  this->totalQueriesIssued = 0;
  this->totalCacheHits = 0;
}


// ========================================================================
// ??0idDeferredVisCache@@QAA@XZ
// EA  : 0x826B9480
// RVA : 0x006B9480
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

idDeferredVisCache *__fastcall idDeferredVisCache::idDeferredVisCache(idDeferredVisCache *this)
{
  idList<idClipQuery,106> *p_clipQueries; // r28
  idDeferredVisQuery *v3; // r3
  int v4; // r10
  int v5; // ctr
  idDeferredVisQuery *queryPool; // r11
  idDeferredVisQuery *v7; // r11
  idDeferredVisQuery *v8; // r11
  int size; // r11
  idClipQuery *v10; // r3
  char v11; // r11
  int num; // r11
  int v13; // r11
  deferredVisList_t *p_priorityList; // [sp+50h] [-40h] BYREF

  this->hashTable.list = nullptr;
  this->hashTable.granularity = 0;
  this->hashTable.memTag = 106;
  this->hashTable.listStatic = 0;
  this->hashTable.size = 0;
  this->hashTable.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->clipQueries.list = nullptr;
  this->clipQueries.granularity = 0;
  p_clipQueries = &this->clipQueries;
  this->clipQueries.memTag = 106;
  this->clipQueries.listStatic = 0;
  this->clipQueries.size = 0;
  this->clipQueries.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clipQueries);
  this->curClipQueryIdx = 0;
  this->leastRecentlyUsedList.headNode = nullptr;
  this->leastRecentlyUsedList.tailNode = nullptr;
  this->leastRecentlyUsedList.numElements = 0;
  this->priorityList.headNode = nullptr;
  this->priorityList.tailNode = nullptr;
  this->priorityList.numElements = 0;
  this->recentCacheHitRatio = 0.0;
  this->recentAvgHitRatio = 0.0;
  this->clip = nullptr;
  this->expiredIndex = 0;
  this->numFrames = 0;
  this->numCreatedThisFrame = 0;
  this->numBumped = 0;
  this->numQueriesIssued = 0;
  this->totalQueriesIssued = 0;
  this->numPurged = 0;
  this->numExpired = 0;
  this->numCacheHits = 0;
  this->totalCacheHits = 0;
  this->maxCreatedInAFrame = 0;
  this->recentNumFrames = 0;
  this->recentTotalCacheHits = 0;
  this->recentTotalQueriesIssued = 0;
  this->initialized = false;
  this->alreadyWarned = false;
  p_priorityList = &this->priorityList;
  v3 = (idDeferredVisQuery *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\gamelib\\aas2\\DeferredVisCache.cpp(471) : TAG_DEFERRED_VIS",
                               size: 0x28000u,
                               tag: TAG_DEFERRED_VIS,
                               zeroBuffer: false,
                               align: ALIGN_128,
                               heap: HEAP_DEFAULTHEAP);
  this->queryPool = v3;
  this->queryList = v3;
  v4 = 1;
  v3->nextInHash = nullptr;
  v3->prev = nullptr;
  v3->next = nullptr;
  v5 = 5119;
  v3->frameCounter = -1;
  v3->state = 0;
  queryPool = this->queryPool;
  p_priorityList = (deferredVisList_t *)v3;
  queryPool->next = queryPool + 1;
  do
  {
    v7 = &this->queryPool[v4];
    v7->nextInHash = nullptr;
    v7->prev = nullptr;
    v7->next = nullptr;
    v7->frameCounter = -1;
    v7->state = 0;
    v8 = &this->queryPool[v4++];
    v8[-1].next = v8;
    --v5;
  }
  while ( v5 != 0 );
  size = this->clipQueries.size;
  if ( size < 256 )
  {
    if ( this->clipQueries.listStatic == 0 )
    {
      if ( size > 0 || this->clipQueries.granularity == 256 )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v3);
      v10 = (idClipQuery *)idListArrayResize<idClipQuery>(
                             voldptr: p_clipQueries->list,
                             oldNum: this->clipQueries.size,
                             newNum: 256,
                             tag: (memTag_t)this->clipQueries.memTag,
                             zeroBuffer: false);
      p_clipQueries->list = v10;
      if ( v10 == nullptr )
      {
        v11 = 0;
        goto LABEL_13;
      }
      num = this->clipQueries.num;
      this->clipQueries.size = 256;
      if ( num > 256 )
        this->clipQueries.num = 256;
    }
    v11 = 1;
LABEL_13:
    if ( v11 == 0 )
      goto LABEL_17;
  }
  v13 = this->clipQueries.size;
  if ( v13 > 256 )
    v13 = 256;
  this->clipQueries.num = v13;
LABEL_17:
  p_priorityList = nullptr;
  idList<idRenderModelCommitted *,5>::SetNum(
    (idList<int,5> *)this,
    newNum: 4096,
    initValue: (const int *)&p_priorityList);
  return this;
}


// ========================================================================
// __unwind$247075
// EA  : 0x826B96BC
// RVA : 0x006B96BC
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247075()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$247076
// EA  : 0x826B96E4
// RVA : 0x006B96E4
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247076()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 16));
}


// ========================================================================
// ??1idDeferredVisCache@@QAA@XZ
// EA  : 0x826B9718
// RVA : 0x006B9718
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::~idDeferredVisCache(idDeferredVisCache *this)
{
  idDeferredVisCache::Shutdown(this);
  idMem::Free(this: &mem, ptr: this->queryPool, align: ALIGN_128);
  this->queryPool = nullptr;
  this->queryList = nullptr;
  this->clip = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clipQueries);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$247207
// EA  : 0x826B9788
// RVA : 0x006B9788
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247207()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$247208
// EA  : 0x826B97B0
// RVA : 0x006B97B0
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247208()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?Update@idDeferredVisGrid@@QAAXABVidVec3@@PBVidAAS2@@HH@Z
// EA  : 0x826B97E8
// RVA : 0x006B97E8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredVisGrid::Update(
        idDeferredVisGrid *this,
        const idVec3 *entityPos,
        const idAAS2 *aas,
        int areaNum,
        int travelFlags)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  int v12; // r5
  int v13; // r4
  int v14; // r2 OVERLAPPED
  __int16 v15; // r11
  __int16 v16; // r11
  __int16 v17; // r10
  __int64 v18; // r8
  char *v19; // r11
  int i; // ctr
  __int128 v21; // r11
  int v22; // r3
  idAAS2_vtbl *v23; // r4
  double v24; // fp9
  int *v25; // r11
  int j; // ctr
  idDeferredVisGrid *v27; // r11
  int v28; // r9
  int k; // ctr
  idPLog *pLog; // r29
  idPLog::logEntry_t *v31; // r30
  int v32; // r3
  __int64 totalTicks; // r11
  __int64 v34; // r9
  idPLogScope v35; // [sp+50h] [-C0h] BYREF
  __int64 v36; // [sp+58h] [-B8h]
  __int64 v37; // [sp+60h] [-B0h]
  float v38[5]; // [sp+68h] [-A8h] BYREF
  int v39; // [sp+7Ch] [-94h] BYREF
  _BYTE v40[144]; // [sp+80h] [-90h] BYREF

  RD_EventBegin(name: "idDeferredVisGrid::Update");
  LODWORD(v10) = "idDeferredVisGrid::Update";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: &v35, pl: &::pLog, gMask: v10, label: v11);
  LODWORD(v36) = (int)entityPos->x;
  v15 = v36;
  if ( (int)v36 >= -32768 )
  {
    if ( (int)v36 > 0x7FFF )
      v15 = 0x7FFF;
  }
  else
  {
    v15 = 0x8000;
  }
  LODWORD(v36) = (int)entityPos->y;
  v17 = (v15 + 31) & 0xFFE0;
  v16 = v36;
  if ( (int)v36 >= -32768 )
  {
    if ( (int)v36 > 0x7FFF )
      v16 = 0x7FFF;
  }
  else
  {
    v16 = 0x8000;
  }
  LODWORD(v36) = (int)entityPos->z;
  HIDWORD(v18) = (__int16)((v16 + 31) & 0xFFE0);
  if ( (int)v36 >= -32768 )
  {
    LODWORD(v18) = 0x7FFF;
    if ( (int)v36 <= 0x7FFF )
      LODWORD(v18) = (__int16)v36;
  }
  else
  {
    LODWORD(v18) = -32768;
  }
  if ( __PAIR64__(v17, SWORD1(v18)) != __PAIR64__(this->xyz[0], this->xyz[1]) )
  {
    this->xyz[0] = v17;
    v19 = (char *)this - 1;
    this->xyz[1] = WORD1(v18);
    this->xyz[2] = v18;
    for ( i = 64; i != 0; --i )
      *++v19 = 1;
    if ( aas != nullptr )
    {
      DWORD1(v21) = v40;
      v22 = this->xyz[2];
      LODWORD(v21) = this->xyz[1];
      v23 = aas->__vftable;
      DWORD2(v21) = this->xyz[0];
      v37 = v21;
      v24 = (double)(__int64)v21;
      v36 = *(_QWORD *)((char *)&v21 + 4);
      LODWORD(v21) = v23->ClipGridToAreas;
      v38[0] = (float)*(__int64 *)((char *)&v21 + 4);
      v38[1] = v24;
      v38[2] = (float)*(__int64 *)(&v14 - 1);
      ((void (__fastcall *)(const idAAS2 *, float *, int, int, int, int, _BYTE *))v21)(
        a1: aas,
        a2: v38,
        a3: areaNum,
        a4: travelFlags,
        a5: 32,
        a6: 8,
        a7: v40);
    }
    else
    {
      v25 = &v39;
      for ( j = 16; j != 0; --j )
        *++v25 = 16843009;
    }
    v27 = this;
    v28 = v40 - (_BYTE *)this;
    for ( k = 64; k != 0; --k )
    {
      LODWORD(v18) = v27->cells[v28];
      if ( v27->cells[v28] == 0 )
        v27->cells[0] = 0;
      v27 = (idDeferredVisGrid *)((char *)v27 + 1);
    }
  }
  if ( vis_showGrid.valueInteger != 0 )
    idDeferredVisGrid::DebugDrawGrid(this, a2: v13, a3: v12, a4: v18);
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
// __unwind$247248
// EA  : 0x826B9A6C
// RVA : 0x006B9A6C
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247248()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 272 + 192));
}


// ========================================================================
// __unwind$247249
// EA  : 0x826B9A94
// RVA : 0x006B9A94
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247249()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 80));
}


// ========================================================================
// ?UpdateCollisionQueries@idDeferredVisCache@@QAAXXZ
// EA  : 0x826B9AC8
// RVA : 0x006B9AC8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::UpdateCollisionQueries(idDeferredVisCache *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int numCreatedThisFrame; // r11
  unsigned __int64 v5; // r28
  idDeferredVisQuery *headNode; // r29
  idClipQuery *list; // r11
  int v8; // r10
  idClip *clip; // r9
  __int64 v10; // r8
  idDeferredVisQuery *v11; // r10
  idDeferredVisQuery **p_next; // r8
  idDeferredVisQuery *prev; // r11
  deferredVisList_t *p_leastRecentlyUsedList; // r11
  idDeferredVisQuery *v15; // r9
  idDeferredVisQuery *v16; // r7
  idDeferredVisQuery *v17; // r8
  idPLogScope v18; // [sp+50h] [-100h] BYREF
  idDeferredVisQuery *v19; // [sp+58h] [-F8h]
  trace_t v20; // [sp+60h] [-F0h] BYREF

  RD_EventBegin(name: "idDeferredVisCache::UpdateCollisionQueries");
  LODWORD(v2) = "idDeferredVisCache::UpdateCollisionQueries";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v18, pl: &pLog, gMask: v2, label: v3);
  if ( this->initialized && this->clip != nullptr )
  {
    numCreatedThisFrame = this->numCreatedThisFrame;
    if ( numCreatedThisFrame > this->maxCreatedInAFrame )
      this->maxCreatedInAFrame = numCreatedThisFrame;
    LODWORD(v5) = 0;
    headNode = this->priorityList.headNode;
    this->numPurged = 0;
    this->numExpired = 0;
    this->numCreatedThisFrame = 0;
    this->numBumped = 0;
    this->numCacheHits = 0;
    if ( headNode != nullptr )
    {
      HIDWORD(v5) = 278920;
      while ( headNode->state != 2 )
      {
        headNode = headNode->next;
LABEL_27:
        if ( headNode == nullptr )
          goto LABEL_28;
      }
      list = this->clipQueries.list;
      v8 = __ROL4__(headNode->queryIdx, 3);
      clip = this->clip;
      v10 = *(unsigned __int64 *)((char *)&list->index + v8);
      *(unsigned __int64 *)((char *)&list->index + v8) = v5;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v20,
        query: &clip->collisionQueries[v10 & 0xFFF].query,
        peek: false);
      *(unsigned __int64 *)((char *)&this->clipQueries.list->index + __ROL4__(headNode->queryIdx, 3)) = v5;
      if ( v20.fraction >= 1.0 )
      {
        headNode->state = 4;
      }
      else
      {
        headNode->state = 3;
        if ( v20.c.entityNum != 8190 )
        {
          headNode->frameCounter = 18;
LABEL_14:
          v11 = headNode;
          p_next = &headNode->next;
          prev = headNode->prev;
          headNode = headNode->next;
          if ( prev != nullptr )
            prev->next = *p_next;
          else
            this->priorityList.headNode = *p_next;
          if ( *p_next != nullptr )
            (*p_next)->prev = v11->prev;
          else
            this->priorityList.tailNode = v11->prev;
          p_leastRecentlyUsedList = &this->leastRecentlyUsedList;
          --this->priorityList.numElements;
          *p_next = nullptr;
          v11->prev = nullptr;
          v15 = this->leastRecentlyUsedList.headNode;
          if ( v15 != nullptr )
          {
            v16 = v15->prev;
            *p_next = v15;
            v19 = v15;
            v11->prev = v16;
            v17 = v15->prev;
            if ( v17 != nullptr )
              v17->next = nullptr;
            else
              p_leastRecentlyUsedList->headNode = v11;
            v15->prev = v11;
            ++this->leastRecentlyUsedList.numElements;
          }
          else
          {
            p_leastRecentlyUsedList->headNode = v11;
            this->leastRecentlyUsedList.tailNode = v11;
            v11->prev = nullptr;
            *p_next = nullptr;
            ++this->leastRecentlyUsedList.numElements;
          }
          goto LABEL_27;
        }
      }
      headNode->frameCounter = 30;
      goto LABEL_14;
    }
  }
LABEL_28:
  idPLogScope::~idPLogScope(this: &v18);
  RD_EventEnd();
}


// ========================================================================
// __unwind$247337_0
// EA  : 0x826B9D1C
// RVA : 0x006B9D1C
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247337_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 224));
}


// ========================================================================
// __unwind$247338_0
// EA  : 0x826B9D44
// RVA : 0x006B9D44
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247338_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 80));
}


// ========================================================================
// ?RemoveFromHash@idDeferredVisCache@@AAAXPAVidDeferredVisQuery@@@Z
// EA  : 0x826B9D78
// RVA : 0x006B9D78
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisCache::RemoveFromHash(idDeferredVisCache *this, idDeferredVisQuery *removeNode)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v6; // r10
  idDeferredVisQuery *v7; // r11
  idPLogScope v8[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idDeferredVisCache::RemoveFromHash");
  LODWORD(v4) = "idDeferredVisCache::RemoveFromHash";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v8, pl: &pLog, gMask: v4, label: v5);
  v6 = (4
      * (removeNode->start[2]
       + removeNode->start[1]
       + removeNode->end[2]
       + removeNode->end[1]
       + removeNode->end[0]
       + removeNode->start[0]))
     & 0x3FFC;
  v7 = *(idDeferredVisQuery **)((char *)this->hashTable.list + v6);
  if ( v7 == removeNode )
  {
    *(idDeferredVisQuery **)((char *)this->hashTable.list + v6) = v7->nextInHash;
  }
  else
  {
    for ( ; v7->nextInHash != removeNode; v7 = v7->nextInHash )
      ;
    v7->nextInHash = removeNode->nextInHash;
  }
  idPLogScope::~idPLogScope(this: v8);
  RD_EventEnd();
}


// ========================================================================
// __unwind$247427
// EA  : 0x826B9E64
// RVA : 0x006B9E64
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247427()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// ?GetVisQuery@idDeferredVisCache@@QAAEQAF0H@Z
// EA  : 0x826B9E98
// RVA : 0x006B9E98
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

int __fastcall idDeferredVisCache::GetVisQuery(
        idDeferredVisCache *this,
        unsigned __int16 *start,
        unsigned __int16 *end,
        char flags)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int v11; // r27
  idDeferredVisQuery *i; // r11
  char v13; // r10
  idDeferredVisQuery *next; // r10
  idDeferredVisQuery **v15; // r6
  int v16; // r4
  idDeferredVisQuery *v17; // r3
  int state; // r30
  idPLogScope v19[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idDeferredVisCache::GetVisQuery");
  LODWORD(v8) = "idDeferredVisCache::GetVisQuery";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: v19, pl: &pLog, gMask: v8, label: v9);
  if ( vis_skipQueries.valueInteger != 0 )
    goto LABEL_2;
  v11 = 0;
  for ( i = *(idDeferredVisQuery **)((char *)this->hashTable.list
                                   + ((4
                                     * ((__int16)end[1]
                                      + (__int16)end[2]
                                      + (__int16)*start
                                      + (__int16)*end
                                      + (__int16)start[2]
                                      + (__int16)start[1]))
                                    & 0x3FFC)); i != nullptr; i = i->nextInHash )
  {
    if ( (unsigned __int16)i->start[0] != *start
      || (unsigned __int16)i->start[1] != start[1]
      || (unsigned __int16)i->start[2] != start[2]
      || (unsigned __int16)i->end[0] != *end
      || (unsigned __int16)i->end[1] != end[1]
      || (v13 = 1, (unsigned __int16)i->end[2] != end[2]) )
    {
      v13 = 0;
    }
    if ( v13 != 0 )
    {
      if ( i->state >= 3u )
      {
        ++this->numCacheHits;
        if ( i != this->leastRecentlyUsedList.headNode )
        {
          next = i->next;
          if ( next != nullptr )
            next->prev = i->prev;
          else
            this->leastRecentlyUsedList.tailNode = i->prev;
          i->prev->next = i->next;
          i->prev = nullptr;
          i->next = this->leastRecentlyUsedList.headNode;
          this->leastRecentlyUsedList.headNode->prev = i;
          this->leastRecentlyUsedList.headNode = i;
        }
      }
      if ( i->frameCounter != 1 || (flags & 2) == 0 )
      {
        state = i->state;
        idPLogScope::~idPLogScope(this: v19);
        RD_EventEnd();
        return state;
      }
      i->frameCounter = 0;
      v11 = i->state;
      ++this->numBumped;
    }
  }
  v17 = idDeferredVisCache::AllocNode(this);
  if ( v17 == nullptr )
  {
    if ( !this->alreadyWarned )
    {
      idLib::Warning(fmt: "idDeferredVisCache::GetVisQuery() ran out of query nodes");
      this->alreadyWarned = true;
    }
LABEL_2:
    idPLogScope::~idPLogScope(this: v19);
    RD_EventEnd();
    return 0;
  }
  ++this->numCreatedThisFrame;
  v17->start[0] = *start;
  v17->start[1] = start[1];
  v17->start[2] = start[2];
  v17->end[0] = *end;
  v17->end[1] = end[1];
  v17->end[2] = end[2];
  v17->state = 1;
  if ( v15 != nullptr )
    *v15 = v17;
  else
    *(idDeferredVisQuery **)((char *)this->hashTable.list + v16) = v17;
  idDeferredVisCache::AddToFront(this, list: &this->priorityList, newNode: v17);
  idPLogScope::~idPLogScope(this: v19);
  RD_EventEnd();
  if ( (_BYTE)v11 != 0 )
    return v11;
  else
    return 1;
}


// ========================================================================
// __unwind$247470
// EA  : 0x826BA180
// RVA : 0x006BA180
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247470()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$247471
// EA  : 0x826BA1A8
// RVA : 0x006BA1A8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247471()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?Init@idDeferredVisGrid@@QAAXABVidVec3@@@Z
// EA  : 0x826BA1D0
// RVA : 0x006BA1D0
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __fastcall idDeferredVisGrid::Init(idDeferredVisGrid *this, const idVec3 *entityPos)
{
  int x; // r11

  x = (int)entityPos->x;
  if ( x >= -32768 )
  {
    if ( x > 0x7FFF )
      LOWORD(x) = 0x7FFF;
  }
  else
  {
    LOWORD(x) = 0x8000;
  }
  this->xyz[0] = x + 32;
  idDeferredVisGrid::Update(this, entityPos, aas: nullptr, areaNum: -1, travelFlags: 0);
}


// ========================================================================
// ?GetGridVisibility@idDeferredVisGrid@@QAAMABVidVec3@@AAVidDeferredVisCache@@PBMHPAVidColor@@3@Z
// EA  : 0x826BA240
// RVA : 0x006BA240
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idDeferredVisGrid::GetGridVisibility(
        idDeferredVisGrid *this,
        const idVec3 *worldPoint,
        idDeferredVisCache *deferredVisCache,
        const float *staggerZ,
        char flags,
        idColor *missDebugColor,
        idColor *hitDebugColor)
{
  __int64 v8; // r22 OVERLAPPED
  unsigned __int64 v12; // r6
  const char *v13; // r7
  __int16 v14; // r9
  __int16 v15; // r8
  int v16; // r19
  int v17; // r18
  int v18; // r6
  __int16 v19; // r5
  double v20; // fp0
  int v21; // r7
  __int16 v22; // r8
  double v23; // fp0
  int v24; // r9
  __int16 v25; // r10
  __int16 v26; // r11
  __int16 v27; // r11
  __int16 v28; // r11
  __int16 v29; // r9
  int v30; // r30
  unsigned int v31; // r25
  __int64 v32; // r10
  int v33; // r28
  __int16 v34; // r11
  __int16 v35; // r10
  __int16 v36; // r24
  int v37; // r30
  __int16 v38; // r23
  unsigned int v39; // r26
  int v40; // r27
  __int16 v41; // r5
  int VisQuery; // r11
  double v43; // fp1
  double v44; // fp31
  unsigned __int64 v46; // [sp+50h] [-160h] BYREF
  __int64 v47; // [sp+58h] [-158h]
  __int16 v48; // [sp+60h] [-150h]
  __int16 v49; // [sp+62h] [-14Eh]
  _WORD v50[5]; // [sp+68h] [-148h] BYREF
  __int16 v51; // [sp+72h] [-13Eh]
  _WORD v52[38]; // [sp+80h] [-130h] BYREF
  int v53; // [sp+CCh] [-E4h]
  int v54; // [sp+D0h] [-E0h]
  __int16 v55; // [sp+D4h] [-DCh]
  __int16 v56; // [sp+D6h] [-DAh]
  __int16 v57; // [sp+D8h] [-D8h]
  __int16 v58; // [sp+DAh] [-D6h]
  __int16 v59; // [sp+DCh] [-D4h]
  __int16 v60; // [sp+DEh] [-D2h]
  __int16 v61; // [sp+E0h] [-D0h]
  __int16 v62; // [sp+E2h] [-CEh]
  __int16 v63; // [sp+E4h] [-CCh]
  __int16 v64; // [sp+E6h] [-CAh]
  __int16 v65; // [sp+E8h] [-C8h]
  __int16 v66; // [sp+EAh] [-C6h]
  __int16 v67; // [sp+ECh] [-C4h]
  __int16 v68; // [sp+EEh] [-C2h]
  __int16 v69; // [sp+F0h] [-C0h]
  __int16 v70; // [sp+F2h] [-BEh]
  __int16 v71; // [sp+F4h] [-BCh]
  __int16 v72; // [sp+F6h] [-BAh]
  __int16 v73; // [sp+F8h] [-B8h]
  __int16 v74; // [sp+FAh] [-B6h]
  __int16 v75; // [sp+FCh] [-B4h]
  idPLogScope v76[2]; // [sp+100h] [-B0h] BYREF

  v8 = (unsigned int)worldPoint;
  RD_EventBegin(name: "idDeferredVisGrid::GetGridVisibility");
  LODWORD(v12) = "idDeferredVisGrid::GetGridVisibility";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: v76, pl: &pLog, gMask: v12, label: v13);
  v14 = this->xyz[0];
  v15 = this->xyz[1];
  v16 = v14;
  v17 = v15;
  v52[0] = 0;
  v48 = v14 - 128;
  v49 = v15 - 128;
  v52[1] = 7;
  v52[2] = 27;
  v52[3] = 28;
  v52[4] = 35;
  v52[5] = 36;
  v52[6] = 56;
  v52[7] = 63;
  v52[8] = 64;
  memset(&v52[9], 0, 26);
  LODWORD(v46) = (int)*(float *)v8;
  v47 = v8;
  v52[22] = 7;
  v52[23] = 11;
  v52[24] = 12;
  v52[25] = 25;
  v52[26] = 27;
  v52[27] = 28;
  v52[28] = 30;
  v52[29] = 33;
  v52[30] = 35;
  v52[31] = 36;
  v52[32] = 38;
  v52[33] = 51;
  v52[34] = 52;
  v52[35] = 56;
  v52[36] = 63;
  v52[37] = 64;
  v53 = 0;
  v54 = 0;
  v61 = 25;
  v18 = v46;
  v55 = 0;
  v60 = 21;
  v70 = 45;
  v56 = 7;
  v57 = 11;
  v58 = 12;
  v59 = 18;
  v62 = 27;
  v63 = 28;
  v64 = 30;
  v65 = 33;
  v66 = 35;
  v67 = 36;
  v68 = 38;
  v69 = 42;
  v71 = 51;
  v72 = 52;
  v73 = 56;
  v74 = 63;
  v75 = 64;
  v46 = *(__int64 *)((char *)&v8 + 4);
  if ( v18 >= -32768 )
  {
    v19 = 0x7FFF;
    if ( v18 <= 0x7FFF )
      v19 = v18;
  }
  else
  {
    v19 = 0x8000;
  }
  v20 = *(float *)(v8 + 4);
  v50[0] = v19;
  LODWORD(v47) = (int)v20;
  v21 = (int)v20;
  if ( (int)v20 >= -32768 )
  {
    v22 = 0x7FFF;
    if ( v21 <= 0x7FFF )
      v22 = (int)v20;
  }
  else
  {
    v22 = 0x8000;
  }
  v23 = *(float *)(v8 + 8);
  v50[1] = v22;
  LODWORD(v47) = (int)v23;
  v24 = (int)v23;
  if ( (int)v23 >= -32768 )
  {
    v25 = 0x7FFF;
    if ( v24 <= 0x7FFF )
      v25 = (int)v23;
  }
  else
  {
    v25 = 0x8000;
  }
  v50[2] = v25;
  if ( v18 >= -32768 )
  {
    v26 = 0x7FFF;
    if ( v18 <= 0x7FFF )
      v26 = v18;
  }
  else
  {
    v26 = 0x8000;
  }
  v50[3] = v26;
  if ( v21 >= -32768 )
  {
    v27 = 0x7FFF;
    if ( v21 <= 0x7FFF )
      v27 = v21;
  }
  else
  {
    v27 = 0x8000;
  }
  v50[4] = v27;
  if ( v24 >= -32768 )
  {
    v28 = 0x7FFF;
    if ( v24 <= 0x7FFF )
      v28 = (int)v23;
  }
  else
  {
    v28 = 0x8000;
  }
  v29 = this->xyz[2];
  v51 = v28;
  v30 = (v29 - v25) * (v29 - v25) + (v17 - v22) * (v17 - v22) + (v16 - v19) * (v16 - v19);
  v31 = !common->IsMultiplayer(this: common) ? -1 : 3;
  if ( v30 > 4000000 || (flags & 1) != 0 )
  {
    v31 = HIDWORD(v8);
  }
  else if ( v30 <= 1690000 )
  {
    if ( v30 > 1000000 )
      v31 = 2;
  }
  else
  {
    v31 = 1;
  }
  HIDWORD(v32) = common->IsMultiplayer(this: common);
  if ( HIDWORD(v32) != 0 )
    v31 = (((v31 - 1) >> 31) - 1) & (v31 - 1);
  v33 = HIDWORD(v8);
  if ( staggerZ != nullptr )
  {
    LODWORD(v47) = (int)*staggerZ;
    v34 = v47;
    if ( (int)v47 >= -32768 )
    {
      if ( (int)v47 > 0x7FFF )
        v34 = 0x7FFF;
    }
    else
    {
      v34 = 0x8000;
    }
    v35 = this->xyz[0];
    v51 = v34;
    if ( (v35 & 0x3F) == 0x20 )
      v33 = 1;
    HIDWORD(v32) = 0;
    if ( (this->xyz[1] & 0x3F) == 0 )
      v33 ^= 1u;
  }
  v36 = v48;
  v37 = HIDWORD(v8);
  v38 = v49;
  v39 = HIDWORD(v8);
  v40 = 1;
  do
  {
    if ( this->cells[v37] == 1 )
    {
      v41 = v37 >> 3;
      WORD2(v46) = this->xyz[2];
      HIWORD(v46) = 32 * (v37 & 7) + v36;
      WORD1(v46) = 32 * v41 + v38;
      VisQuery = (unsigned __int8)idDeferredVisCache::GetVisQuery(
                                    this: deferredVisCache,
                                    start: &v50[3 * (((unsigned __int8)v41 ^ v37 & 7) & 1 ^ v33)],
                                    end: (unsigned __int16 *)&v46,
                                    flags);
      if ( VisQuery == 4 )
      {
        ++v39;
      }
      else if ( VisQuery != 3 )
      {
        goto LABEL_49;
      }
      ++HIDWORD(v8);
    }
LABEL_49:
    if ( v31 == -1 )
    {
      ++v37;
    }
    else
    {
      HIDWORD(v32) = 2 * (21 * v31 + v40++);
      v37 = *(__int16 *)((char *)v52 + HIDWORD(v32));
    }
  }
  while ( v37 < 64 );
  if ( HIDWORD(v8) != 0 )
  {
    LODWORD(v32) = HIDWORD(v8);
    v47 = v32;
    v46 = __PAIR64__(HIDWORD(v8), v39);
    v44 = (float)((float)__SPAIR64__(HIDWORD(v8), v39) / (float)v32);
    idPLogScope::~idPLogScope(this: v76);
    RD_EventEnd();
    v43 = v44;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v76);
    RD_EventEnd();
    v43 = 0.0;
  }
  return *((float *)&v43 + 1);
}


// ========================================================================
// __unwind$247569
// EA  : 0x826BA78C
// RVA : 0x006BA78C
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247569()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 432 + 264));
}


// ========================================================================
// __unwind$247570
// EA  : 0x826BA7B4
// RVA : 0x006BA7B4
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247570()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 432 + 256));
}


// ========================================================================
// ?SubmitCollisionQueries@idDeferredVisCache@@QAAXXZ
// EA  : 0x826BA7E8
// RVA : 0x006BA7E8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredVisCache::SubmitCollisionQueries(idDeferredVisCache *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  __int64 v4; // r6
  int v5; // r2 OVERLAPPED
  idDeferredVisQuery *headNode; // r29
  int i; // r28
  __int64 v8; // r11
  __int64 v9; // r4
  __int16 v10; // r11
  int curClipQueryIdx; // r27
  idClipQuery *list; // r26
  __int64 v13; // r20
  __int64 v14; // fp4
  int numElements; // r11
  idDeferredVisQuery *tailNode; // r29
  idDeferredVisQuery *prev; // r11
  idDeferredVisQuery *next; // r11
  idDeferredVisQuery *queryList; // r10
  int expiredIndex; // r11
  int v21; // r25
  int v22; // r26
  int v23; // r28
  idDeferredVisQuery *v25; // r29
  int frameCounter; // r11
  __int16 v27; // r11
  idDeferredVisCache *v28; // r3
  idDeferredVisQuery *v29; // r11
  int v30; // [sp+8h] [-138h]
  bool v31; // [sp+Fh] [-131h]
  const char *v32; // [sp+10h] [-130h]
  idPLogScope v33[7]; // [sp+70h] [-D0h] BYREF
  int v34; // [sp+A8h] [-98h] BYREF
  idVec3 v35; // [sp+B0h] [-90h] BYREF
  idVec3 v36; // [sp+C0h] [-80h] BYREF

  RD_EventBegin(name: "idDeferredVisCache::SubmitCollisionQueries");
  LODWORD(v2) = "idDeferredVisCache::SubmitCollisionQueries";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v33, pl: &pLog, gMask: v2, label: v3);
  if ( this->initialized && vis_skipQueries.valueInteger == 0 && this->clip != nullptr )
  {
    headNode = this->priorityList.headNode;
    for ( i = 0; headNode != nullptr; headNode = headNode->next )
    {
      if ( i >= 128 )
        break;
      if ( headNode->state == 1 )
      {
        HIDWORD(v8) = 1;
        HIDWORD(v9) = headNode->end[1];
        v10 = headNode->end[2];
        LODWORD(v4) = headNode->end[0];
        v33[2] = *(idPLogScope *)(&v5 - 1);
        v33[3] = (idPLogScope)v4;
        LODWORD(v9) = v10;
        v33[1] = (idPLogScope)v9;
        curClipQueryIdx = this->curClipQueryIdx;
        v35.z = (float)v9;
        list = this->clipQueries.list;
        LODWORD(v9) = this->clip;
        v35.x = (float)v4;
        v35.y = (float)*(__int64 *)(&v5 - 1);
        LODWORD(v8) = headNode->start[2];
        LODWORD(v13) = headNode->start[1];
        v33[5] = (idPLogScope)v8;
        v14 = v8;
        HIDWORD(v13) = (unsigned __int16)headNode->start[0];
        v33[4] = (idPLogScope)v13;
        LODWORD(v8) = SWORD1(v13);
        v33[6] = (idPLogScope)v8;
        v36.x = (float)v8;
        v36.y = (float)v13;
        v36.z = (float)v14;
        list[curClipQueryIdx] = (idClipQuery)idClip::Translation(
                                               this: (idClip *)&v34,
                                               result: (idClipQuery *)v9,
                                               result: nullptr,
                                               start: &v36,
                                               end: &v35,
                                               clipModel: nullptr,
                                               startAxis: &mat3_identity,
                                               clipMask: 1,
                                               passEntityNumber: v30,
                                               moveClipModel: v31,
                                               userName: v32)->index;
        ++i;
        headNode->queryIdx = this->curClipQueryIdx;
        this->curClipQueryIdx = (unsigned __int8)(this->curClipQueryIdx + 1);
        headNode->state = 2;
      }
    }
    numElements = this->leastRecentlyUsedList.numElements;
    this->numQueriesIssued = i;
    if ( numElements > 4096 )
    {
      do
      {
        tailNode = this->leastRecentlyUsedList.tailNode;
        prev = tailNode->prev;
        if ( prev != nullptr )
          prev->next = tailNode->next;
        else
          this->leastRecentlyUsedList.headNode = tailNode->next;
        next = tailNode->next;
        if ( next != nullptr )
          next->prev = tailNode->prev;
        else
          this->leastRecentlyUsedList.tailNode = tailNode->prev;
        --this->leastRecentlyUsedList.numElements;
        tailNode->next = nullptr;
        tailNode->prev = nullptr;
        idDeferredVisCache::RemoveFromHash(this, removeNode: tailNode);
        queryList = this->queryList;
        tailNode->frameCounter = -1;
        tailNode->state = 0;
        tailNode->next = queryList;
        this->queryList = tailNode;
        --numQueriesAlloc;
        ++this->numPurged;
      }
      while ( this->leastRecentlyUsedList.numElements > 4096 );
    }
    expiredIndex = this->expiredIndex;
    v21 = expiredIndex + 512;
    if ( expiredIndex + 512 < 5120 )
    {
      this->expiredIndex = v21;
    }
    else
    {
      v21 = 5120;
      this->expiredIndex = 0;
    }
    v22 = expiredIndex;
    if ( expiredIndex < v21 )
    {
      v23 = expiredIndex;
      do
      {
        if ( (v22 & 3) == 0 )
        {
          _R11 = &this->queryPool[v23 + 4];
          __asm { dcbt      0, r11 }
        }
        v25 = &this->queryPool[v23];
        frameCounter = v25->frameCounter;
        if ( frameCounter >= 0 )
        {
          v27 = frameCounter - 1;
          v25->frameCounter = v27;
          if ( v27 <= 0 )
          {
            idDeferredVisCache::RemoveNoDelete(this, list: &this->leastRecentlyUsedList, node: v25);
            idDeferredVisCache::RemoveFromHash(this: v28, removeNode: v25);
            v29 = this->queryList;
            v25->state = 0;
            v25->frameCounter = -1;
            v25->next = v29;
            this->queryList = v25;
            --numQueriesAlloc;
            ++this->numExpired;
          }
        }
        ++v22;
        ++v23;
      }
      while ( v22 < v21 );
    }
    this->alreadyWarned = false;
    idPLogScope::~idPLogScope(this: v33);
  }
  else
  {
    idPLogScope::~idPLogScope(this: v33);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$247669
// EA  : 0x826BAB50
// RVA : 0x006BAB50
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247669()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 204));
}


// ========================================================================
// __unwind$247670
// EA  : 0x826BAB78
// RVA : 0x006BAB78
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void _unwind_247670()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 112));
}


// ========================================================================
// `dynamic initializer for 'vis_showInfo''
// EA  : 0x8333E570
// RVA : 0x0133E570
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vis_showInfo__()
{
  idCVar::idCVar(
    this: &vis_showInfo,
    name: "vis_showInfo",
    value: "0",
    flags: 1,
    description: "show deferred vis cache info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vis_showInfo__);
}


// ========================================================================
// `dynamic initializer for 'vis_showGrid''
// EA  : 0x8333E5C8
// RVA : 0x0133E5C8
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vis_showGrid__()
{
  idCVar::idCVar(
    this: &vis_showGrid,
    name: "vis_showGrid",
    value: "0",
    flags: 1,
    description: "draw the deferred vis grid to the screen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vis_showGrid__);
}


// ========================================================================
// `dynamic initializer for 'vis_skipQueries''
// EA  : 0x8333E620
// RVA : 0x0133E620
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vis_skipQueries__()
{
  idCVar::idCVar(
    this: &vis_skipQueries,
    name: "vis_skipQueries",
    value: "0",
    flags: 1,
    description: "skip deferred vis cache collision queries",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vis_skipQueries__);
}


// ========================================================================
// `dynamic initializer for 'vis_checkLRU''
// EA  : 0x8333E678
// RVA : 0x0133E678
// PDB : w:\tech5\engine\gamelib\aas2\deferredviscache.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vis_checkLRU__()
{
  idCVar::idCVar(
    this: &vis_checkLRU,
    name: "vis_checkLRU",
    value: "0",
    flags: 1,
    description: "check that the lru has the right number of elements in it",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vis_checkLRU__);
}

