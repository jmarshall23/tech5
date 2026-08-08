
// ========================================================================
// ?TracePath@?$idDijkstra@VidAnimator_AnimWeb@@VidNodeCache@idDeclAnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@VidEdgeCache@3@VidAnimWebRoute@@@@QAA_NABVidAnimator_AnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@1PBUdjScratch_t@@AAVidAnimWebRoute@@@Z
// EA  : 0x826D1008
// RVA : 0x006D1008
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

int __fastcall idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::TracePath(
        idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *this,
        const idAnimator_AnimWeb *nodeHolder,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *startNode,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *destNode,
        const djScratch_t *scratchBuff,
        idAnimWebRoute *path)
{
  int v7; // r10
  const djScratch_t *v8; // r11
  __int16 prevIndex; // r9
  int v10; // r10

  if ( this->lastStartNode != (__int16)startNode )
    return 0;
  path->num = 0;
  path->cost = 0x7FFFFFFF;
  if ( (__int16)destNode == (__int16)startNode )
    return 0;
  path->path[0].value = (__int16)destNode;
  v7 = path->num + 1;
  v8 = &scratchBuff[(__int16)destNode];
  path->num = v7;
  path->cost = v8->cost;
  if ( v7 >= 32 )
  {
LABEL_8:
    idAnimWebRoute::Invert(this: path);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      prevIndex = v8->prevIndex;
      if ( prevIndex < 0 )
        break;
      path->path[path->num].value = prevIndex;
      v10 = path->num + 1;
      path->num = v10;
      v8 = &scratchBuff[prevIndex];
      if ( prevIndex == (__int16)startNode || v10 >= 32 )
        goto LABEL_8;
    }
    path->cost = 0x7FFFFFFF;
    path->num = 0;
    return 0;
  }
}


// ========================================================================
// ?FindShortestPaths@?$idDijkstra@VidAnimator_AnimWeb@@VidNodeCache@idDeclAnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@VidEdgeCache@3@VidAnimWebRoute@@@@QAA_NABVidAnimator_AnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@PBV3@HPBVidEdgeCache@idDeclAnimWeb@@PAUdjScratch_t@@HH@Z
// EA  : 0x826D50D0
// RVA : 0x006D50D0
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

int __fastcall idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::FindShortestPaths(
        idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *this,
        const idAnimator_AnimWeb *nodeHolder,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *startNode,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *destNodes,
        int numDestNodes,
        const idDeclAnimWeb::idEdgeCache *edges,
        djScratch_t *scratchBuff,
        const int skipFlags,
        const int requiredFlags,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *v28; // r25
  __int16 v30; // r30
  unsigned __int64 v34; // r6
  const char *v35; // r7
  const idDeclAnimWeb *decl; // r10
  size_t v37; // r5
  int v38; // r20
  int v39; // r28
  unsigned __int64 v40; // r6
  const char *v41; // r7
  int v42; // r8
  int num; // r7
  const idList<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,32> *v44; // r9
  int v45; // r10
  int v46; // r11
  int v47; // ctr
  __int16 value; // r6
  int v49; // r15
  int logIndex; // r10
  int v51; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v53; // r30
  int v54; // r3
  __int64 totalTicks; // r11
  __int64 v56; // r9
  int v57; // r21
  int v58; // r18
  idPLog::logEntry_t *v59; // r30
  __int64 v60; // r3
  int v61; // r10
  int v62; // r12
  int numNodes; // r28
  idBinaryHeap<int,int,-2147483648>::idHeapNode *nodes; // r30
  int v65; // r11
  int node; // r29
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v67; // r10
  int v68; // r24
  unsigned int cost; // r8
  int v70; // r9
  const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v71; // r10
  idDeclAnimWeb::idNodeCache *list; // r11
  idDeclAnimWeb::idNodeCache *v73; // r11
  int flags; // r10
  unsigned int edgeIndexOffset; // r10
  int numEdges; // r11
  unsigned __int16 *v77; // r10
  unsigned __int16 *v78; // r25
  int i; // r23
  __int64 v80; // r6
  int v81; // r11
  int v82; // r28
  djScratch_t *v83; // r30
  const idDeclAnimWeb *v84; // r10
  idAnimator_AnimWeb_vtbl *v85; // r9
  int (__fastcall *InternalGetEdgeCost)(idAnimator_AnimWeb *, const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *__struct_ptr, const idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *__struct_ptr); // ctr
  double v87; // fp30
  __int64 v88; // r5
  unsigned __int16 v89; // r11
  int v90; // r5
  idPLog::logEntry_t *v91; // r30
  int v92; // r3
  int v93; // r11
  __int64 v94; // r9
  idPLog *v95; // r29
  idPLog::logEntry_t *v96; // r30
  int v97; // r3
  __int64 v98; // r11
  __int64 v99; // r9
  idPLog::logEntry_t *v100; // r30
  int v101; // r3
  int v102; // r11
  __int64 v103; // r9
  idPLog *v104; // r29
  idPLog::logEntry_t *v105; // r30
  int v106; // r3
  __int64 v107; // r11
  __int64 v108; // r9
  idPLog::logEntry_t *v109; // r30
  int v110; // r3
  int parent; // r11
  __int64 v112; // r9
  idPLog *v113; // r29
  idPLog::logEntry_t *v114; // r30
  int v115; // r3
  __int64 v116; // r11
  __int64 v117; // r9
  _DWORD back_chain[20]; // [sp+0h] [-140h]
  __int16 v120; // [sp+50h] [-F0h] BYREF
  unsigned int edgeIndexCache; // [sp+54h] [-ECh]
  idPLogScope v122; // [sp+58h] [-E8h] BYREF
  idPLogScope v123[3]; // [sp+60h] [-E0h] BYREF
  int v125; // [sp+7Ch] [-C4h]
  idBinaryHeap<int,int,-2147483648> v126; // [sp+80h] [-C0h] BYREF

  v28 = this;
  v30 = (__int16)startNode;
  RD_EventBegin(name: "idDijkstra::FindShortestPaths");
  LODWORD(v34) = "idDijkstra::FindShortestPaths";
  HIDWORD(v34) = 2;
  idPLogScope::idPLogScope(this: &v122, pl: &::pLog, gMask: v34, label: v35);
  decl = nodeHolder->decl;
  v37 = 4 * decl->nodes.num;
  edgeIndexCache = (unsigned int)decl->edgeIndexCache;
  memset(Dst: scratchBuff, Val: 255, Size: v37);
  v38 = 0;
  v39 = 0;
  RD_EventBegin(name: "idDijkstra::FindShortestPaths - init scratch");
  LODWORD(v40) = "idDijkstra::FindShortestPaths - init scratch";
  HIDWORD(v40) = 2;
  idPLogScope::idPLogScope(this: v123, pl: &::pLog, gMask: v40, label: v41);
  if ( nodeHolder->pathableSubWebNodeLists.num > 0 )
  {
    v42 = 0;
    num = nodeHolder->pathableSubWebNodeLists.num;
    do
    {
      v44 = nodeHolder->pathableSubWebNodeLists.list[v42];
      v45 = v44->num;
      v39 += v45;
      if ( v45 > 0 )
      {
        v46 = 0;
        v47 = v44->num;
        do
        {
          value = v44->list[v46++].value;
          scratchBuff[value].cost &= ~0x8000u;
          --v47;
        }
        while ( v47 != 0 );
      }
      --num;
      ++v42;
    }
    while ( num != 0 );
  }
  v49 = v30;
  logIndex = v123[0].logIndex;
  v51 = v30;
  scratchBuff[v51].cost &= ~0x8000u;
  scratchBuff[v51].cost = 0;
  if ( logIndex >= 0 )
  {
    pLog = v123[0].pLog;
    v53 = &v123[0].pLog->logEntries.list[logIndex];
    v54 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v53->totalTicks;
    HIDWORD(totalTicks) = v53->parent;
    LODWORD(v56) = v54 - totalTicks;
    v53->totalTicks = v56;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  v57 = -1;
  v28->lastStartNode = -1;
  v58 = 0;
  RD_EventBegin(name: "idDijkstra::FindShortestPaths - path");
  v123[0].pLog = &::pLog;
  v123[0].logIndex = -1;
  if ( (::pLog.groupMask & 2) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
      this: &::pLog.logEntries,
      newSize: ::pLog.logEntries.num + 1);
    if ( ::pLog.logEntries.num >= ::pLog.logEntries.size )
      v59 = &::pLog.logEntries.list[::pLog.logEntries.size - 1];
    else
      v59 = &::pLog.logEntries.list[::pLog.logEntries.num++];
    idMem::PopHeap(this: &mem);
    v59->label = "idDijkstra::FindShortestPaths - path";
    v59->parent = ::pLog.lastEntry;
    v57 = ::pLog.logEntries.num - 1;
    ::pLog.lastEntry = ::pLog.logEntries.num - 1;
    v123[0].logIndex = ::pLog.logEntries.num - 1;
    LODWORD(v60) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v59->totalTicks = v60;
  }
  ((void (*)(void))RtlCheckStack12)();
  v126.initialSize = v61;
  v126.numNodes = 0;
  v126.ordered = true;
  v126.externalBuffer = true;
  *(_DWORD *)((char *)back_chain + v62) = back_chain[0];
  v126.curSize = v61 - 1;
  v126.nodes = (idBinaryHeap<int,int,-2147483648>::idHeapNode *)&v120;
  edgeIndexCache = 0x80000000;
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(this: &v126, node: v49, priority: 0);
  if ( nodeHolder->decl->nodes.num <= 0 )
  {
    nodes = v126.nodes;
_M260435:
    v28->lastStartNode = v49;
    if ( !v126.externalBuffer && nodes != nullptr )
      idMem::Free(this: &mem, ptr: nodes, align: ALIGN_16);
    if ( v57 >= 0 )
    {
      v109 = &::pLog.logEntries.list[v57];
      v110 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      parent = v109->parent;
      LODWORD(v112) = v110 - LODWORD(v109->totalTicks);
      v109->totalTicks = v112;
      ::pLog.lastEntry = parent;
    }
    RD_EventEnd();
    if ( v122.logIndex >= 0 )
    {
      v113 = v122.pLog;
      v114 = &v122.pLog->logEntries.list[v122.logIndex];
      v115 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v116 = v114->totalTicks;
      HIDWORD(v116) = v114->parent;
      LODWORD(v117) = v115 - v116;
      v114->totalTicks = v117;
      v113->lastEntry = HIDWORD(v116);
    }
  }
  else
  {
    numNodes = v126.numNodes;
    nodes = v126.nodes;
    while ( 1 )
    {
      do
      {
        if ( numNodes == 0 )
        {
          v28->lastStartNode = v49;
          if ( !v126.externalBuffer && nodes != nullptr )
            idMem::Free(this: &mem, ptr: nodes, align: ALIGN_16);
          if ( v57 >= 0 )
          {
            v91 = &::pLog.logEntries.list[v57];
            v92 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v93 = v91->parent;
            LODWORD(v94) = v92 - LODWORD(v91->totalTicks);
            v91->totalTicks = v94;
            ::pLog.lastEntry = v93;
          }
          RD_EventEnd();
          if ( v122.logIndex >= 0 )
          {
            v95 = v122.pLog;
            v96 = &v122.pLog->logEntries.list[v122.logIndex];
            v97 = (unsigned __int64)Sys_GetClockTicks() >> 32;
            v98 = v96->totalTicks;
            HIDWORD(v98) = v96->parent;
            LODWORD(v99) = v97 - v98;
            v96->totalTicks = v99;
            v95->lastEntry = HIDWORD(v98);
          }
          goto LABEL_59;
        }
        if ( !v126.ordered )
        {
          idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::SortHeap(this: &v126);
          numNodes = v126.numNodes;
          nodes = v126.nodes;
        }
        v65 = numNodes;
        node = nodes[1].node;
        v67 = &nodes[numNodes--];
        v126.numNodes = numNodes;
        nodes[1].node = nodes[v65].node;
        nodes[1].priority = v67->priority;
        idBinaryHeap<int,int,-2147483648>::PercolateDown(this: &v126, hole: 1);
        v68 = (__int16)node;
        cost = scratchBuff[v68].cost;
      }
      while ( cost >> 15 != 0 );
      v70 = 0;
      if ( numDestNodes > 0 )
        break;
LABEL_25:
      list = nodeHolder->decl->nodeCache.list;
      scratchBuff[v68].cost = cost | 0x8000;
      v73 = &list[(__int16)node];
      flags = v73->flags;
      if ( (flags & skipFlags) == 0 && (flags & a28) == a28 )
      {
        edgeIndexOffset = v73->edgeIndexOffset;
        numEdges = v73->numEdges;
        v77 = (unsigned __int16 *)(2 * edgeIndexOffset + edgeIndexCache);
        if ( numEdges > 0 )
        {
          v78 = v77;
          for ( i = numEdges; i != 0; --i )
          {
            HIDWORD(v80) = *v78;
            v81 = SWORD1(v80);
            v82 = edges[v81].destNodeIndex.value;
            v83 = &scratchBuff[v82];
            if ( v83->cost >> 15 == 0 )
            {
              v84 = nodeHolder->decl;
              v85 = nodeHolder->__vftable;
              v120 = node;
              InternalGetEdgeCost = v85->InternalGetEdgeCost;
              LODWORD(v80) = v84->edgeCache.list[v81].weightScale;
              v123[1] = (idPLogScope)v80;
              v87 = (float)((float)v80 * (float)0.0625);
              LODWORD(v88) = ((int (__fastcall *)(const idAnimator_AnimWeb *, _DWORD))InternalGetEdgeCost)(
                               a1: nodeHolder,
                               a2: (__int16)node);
              HIDWORD(v88) = scratchBuff[v68].cost;
              v89 = v83->cost;
              v123[2] = (idPLogScope)v88;
              v125 = (int)(float)((float)v88 * (float)v87);
              v90 = (WORD1(v88) & 0x7FFF) + v125;
              if ( (v89 & 0x7FFF) > v90 )
              {
                v83->prevIndex = node;
                v83->cost = v89 & 0x8000 | v90 & 0x7FFF;
                idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(this: &v126, node: v82, priority: v90);
              }
            }
            ++v78;
          }
          numNodes = v126.numNodes;
          nodes = v126.nodes;
          v28 = this;
        }
      }
      if ( ++v38 >= nodeHolder->decl->nodes.num )
        goto _M260435;
    }
    v71 = destNodes;
    while ( v71->value != (__int16)node || ++v58 != numDestNodes )
    {
      ++v70;
      ++v71;
      if ( v70 >= numDestNodes )
        goto LABEL_25;
    }
    v28->lastStartNode = v49;
    if ( !v126.externalBuffer )
      idMem::Free(this: &mem, ptr: nodes, align: ALIGN_16);
    if ( v57 >= 0 )
    {
      v100 = &::pLog.logEntries.list[v57];
      v101 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v102 = v100->parent;
      LODWORD(v103) = v101 - LODWORD(v100->totalTicks);
      v100->totalTicks = v103;
      ::pLog.lastEntry = v102;
    }
    RD_EventEnd();
    if ( v122.logIndex >= 0 )
    {
      v104 = v122.pLog;
      v105 = &v122.pLog->logEntries.list[v122.logIndex];
      v106 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v107 = v105->totalTicks;
      HIDWORD(v107) = v105->parent;
      LODWORD(v108) = v106 - v107;
      v105->totalTicks = v108;
      v104->lastEntry = HIDWORD(v107);
    }
  }
LABEL_59:
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$260008
// EA  : 0x826D573C
// RVA : 0x006D573C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

void _unwind_260008()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 148));
}


// ========================================================================
// __unwind$260009
// EA  : 0x826D5764
// RVA : 0x006D5764
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

void _unwind_260009()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 88));
}


// ========================================================================
// __unwind$260010
// EA  : 0x826D578C
// RVA : 0x006D578C
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

void _unwind_260010()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 149));
}


// ========================================================================
// __unwind$260012
// EA  : 0x826D57B4
// RVA : 0x006D57B4
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

void _unwind_260012()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 150));
}


// ========================================================================
// __unwind$260013
// EA  : 0x826D57DC
// RVA : 0x006D57DC
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

void _unwind_260013()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$260014
// EA  : 0x826D5804
// RVA : 0x006D5804
// PDB : w:\tech5\engine\gamelib\animstack\animweb\dijkstra_impl.h
// ========================================================================

void _unwind_260014()
{
  int v0; // r12

  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::~idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>(this: (idBinaryHeap<int,int,-2147483648> *)(v0 - 320 + 128));
}

