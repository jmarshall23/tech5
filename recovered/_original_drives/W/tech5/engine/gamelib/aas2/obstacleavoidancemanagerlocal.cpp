
// ========================================================================
// ?Shutdown@idObstacleAvoidanceManagerLocal@@UAAXXZ
// EA  : 0x826C8588
// RVA : 0x006C8588
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceManagerLocal::Shutdown(idObstacleAvoidanceManagerLocal *this)
{
  int v2; // r28
  int v3; // r30
  idObstacleBuffers **list; // r4
  idObstacleBuffers **v5; // r4
  idObstacleBuffers **v6; // r4

  this->FrameFreeObstacleBuffers(this);
  v2 = 0;
  if ( this->freeBuffers.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: this->freeBuffers.list[v3]->parms, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: this->freeBuffers.list[v3]->route, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: (void *)this->freeBuffers.list[v3]->obstacles, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: this->freeBuffers.list[v3]->vertices, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: this->freeBuffers.list[v3]->edges, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: (void *)this->freeBuffers.list[v3]->corners, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: (void *)this->freeBuffers.list[v3]->traces, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: this->freeBuffers.list[v3]->traceFractions, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: this->freeBuffers.list[v3]->path, align: ALIGN_128);
      idMem::Free(this: &mem, ptr: this->freeBuffers.list[v3], align: ALIGN_16);
      ++v2;
      ++v3;
    }
    while ( v2 < this->freeBuffers.num );
  }
  if ( this->usedBuffers.listStatic == 0 || this->usedBuffers.listStatic == 2 )
  {
    list = this->usedBuffers.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->usedBuffers.list = nullptr;
    this->usedBuffers.size = 0;
  }
  this->usedBuffers.num = 0;
  if ( this->freeBuffers.listStatic == 0 || this->freeBuffers.listStatic == 2 )
  {
    v5 = this->freeBuffers.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->freeBuffers.list = nullptr;
    this->freeBuffers.size = 0;
  }
  this->freeBuffers.num = 0;
  if ( this->toBeFreedBuffers.listStatic == 0 || this->toBeFreedBuffers.listStatic == 2 )
  {
    v6 = this->toBeFreedBuffers.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->toBeFreedBuffers.list = nullptr;
    this->toBeFreedBuffers.size = 0;
  }
  this->toBeFreedBuffers.num = 0;
  this->jobList = nullptr;
}


// ========================================================================
// ?Init@idObstacleAvoidanceManagerLocal@@UAAXPAVidParallelJobList@@@Z
// EA  : 0x826C89F0
// RVA : 0x006C89F0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceManagerLocal::Init(
        idObstacleAvoidanceManagerLocal *this,
        idParallelJobList *jobList)
{
  idList<idObstacleBuffers *,5> *p_freeBuffers; // r17
  int i; // r18
  idObstacleBuffers *v4; // r31
  obstaclePath_t *v5; // r3
  obstaclePath_t *v6; // r3

  if ( this->jobList == nullptr )
  {
    this->jobList = jobList;
    p_freeBuffers = &this->freeBuffers;
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->freeBuffers, newNum: 32);
    for ( i = 0; i < 32; ++i )
    {
      v4 = (idObstacleBuffers *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x44u,
                                  tag: TAG_AI_OBSTACLE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      v4->parms = (obstacleParms_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(34) : TAG_AI_OBSTACLE",
                                       size: 0xA0u,
                                       tag: TAG_AI_OBSTACLE,
                                       zeroBuffer: false,
                                       align: ALIGN_128,
                                       heap: HEAP_DEFAULTHEAP);
      v4->route = (obstacleRoute_t *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(35) : TAG_AI_OBSTACLE",
                                       size: 0x150u,
                                       tag: TAG_AI_OBSTACLE,
                                       zeroBuffer: false,
                                       align: ALIGN_128,
                                       heap: HEAP_DEFAULTHEAP);
      v4->obstacles = (obstacleBox_t *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(36) : TAG_AI_OBSTACLE",
                                         size: 0x2800u,
                                         tag: TAG_AI_OBSTACLE,
                                         zeroBuffer: false,
                                         align: ALIGN_128,
                                         heap: HEAP_DEFAULTHEAP);
      v4->vertices = (obstacleVertex_t *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(37) : TAG_AI_OBSTACLE",
                                           size: 0x2400u,
                                           tag: TAG_AI_OBSTACLE,
                                           zeroBuffer: false,
                                           align: ALIGN_128,
                                           heap: HEAP_DEFAULTHEAP);
      v4->edges = (obstacleEdge_t *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(38) : TAG_AI_OBSTACLE",
                                      size: 0x2000u,
                                      tag: TAG_AI_OBSTACLE,
                                      zeroBuffer: false,
                                      align: ALIGN_128,
                                      heap: HEAP_DEFAULTHEAP);
      v4->corners = (obstacleCorner_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(39) : TAG_AI_OBSTACLE",
                                          size: 0x100u,
                                          tag: TAG_AI_OBSTACLE,
                                          zeroBuffer: false,
                                          align: ALIGN_128,
                                          heap: HEAP_DEFAULTHEAP);
      v4->traces = (obstacleTrace_t *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(40) : TAG_AI_OBSTACLE",
                                        size: 0x1000u,
                                        tag: TAG_AI_OBSTACLE,
                                        zeroBuffer: false,
                                        align: ALIGN_128,
                                        heap: HEAP_DEFAULTHEAP);
      v4->traceFractions = (float *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(41) : TAG_AI_OBSTACLE",
                                      size: 0x400u,
                                      tag: TAG_AI_OBSTACLE,
                                      zeroBuffer: false,
                                      align: ALIGN_128,
                                      heap: HEAP_DEFAULTHEAP);
      v5 = (obstaclePath_t *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\gamelib\\aas2\\ObstacleAvoidanceManagerLocal.cpp(42) : TAG_AI_OBSTACLE",
                               size: 0x270u,
                               tag: TAG_AI_OBSTACLE,
                               zeroBuffer: false,
                               align: ALIGN_128,
                               heap: HEAP_DEFAULTHEAP);
      if ( v5 != nullptr )
        v6 = obstaclePath_t::obstaclePath_t(this: v5);
      else
        v6 = nullptr;
      v4->path = v6;
      v4->numObstacles = 0;
      v4->numVertices = 0;
      v4->numEdges = 0;
      v4->numCorners = 0;
      v4->numTraces = 0;
      v4->frameCount = 0;
      v4->user = nullptr;
      v4->job = nullptr;
      p_freeBuffers->list[i] = v4;
    }
  }
}


// ========================================================================
// ?AllocObstacleBuffers@idObstacleAvoidanceManagerLocal@@UAAXPAVidObstacleAvoidance@@@Z
// EA  : 0x826C8C38
// RVA : 0x006C8C38
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceManagerLocal::AllocObstacleBuffers(
        idObstacleAvoidanceManagerLocal *this,
        idObstacleAvoidance *obstacleAvoidance)
{
  int num; // r8
  idList<enum encounterGroupRole_t,5> *p_usedBuffers; // r28
  int v5; // r10
  encounterGroupRole_t *list; // r9
  int v7; // r11
  idObstacleBuffers *buffers; // r7
  int v9; // r11
  idObstacleBuffers *v10; // r31
  idObstacleBuffers *v11; // [sp+50h] [-30h] BYREF

  num = this->usedBuffers.num;
  p_usedBuffers = (idList<enum encounterGroupRole_t,5> *)&this->usedBuffers;
  v5 = 0;
  if ( num <= 0 )
    goto LABEL_5;
  list = p_usedBuffers->list;
  v7 = 0;
  buffers = obstacleAvoidance->buffers;
  while ( (idObstacleBuffers *)list[v7] != buffers )
  {
    ++v5;
    ++v7;
    if ( v5 >= num )
      goto LABEL_5;
  }
  if ( v5 >= 0 && &list[v5] != nullptr )
  {
    buffers->numObstacles = 0;
    obstacleAvoidance->buffers->numVertices = 0;
    obstacleAvoidance->buffers->numEdges = 0;
    obstacleAvoidance->buffers->numCorners = 0;
    obstacleAvoidance->buffers->numTraces = 0;
    obstacleAvoidance->buffers->frameCount = 2;
  }
  else
  {
LABEL_5:
    if ( this->freeBuffers.num > 0 )
    {
      v9 = this->freeBuffers.num;
      v11 = this->freeBuffers.list[v9 - 1];
      v10 = v11;
      idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->freeBuffers, newNum: v9 - 1);
      idList<idAnimWebBlendTree *,5>::Append(this: p_usedBuffers, obj: (const encounterGroupRole_t *)&v11);
      v10->user = obstacleAvoidance;
      obstacleAvoidance->buffers = v10;
      v10->job = nullptr;
      v10->numObstacles = 0;
      v10->numVertices = 0;
      v10->numEdges = 0;
      v10->numCorners = 0;
      v10->numTraces = 0;
      v10->frameCount = 2;
    }
    else
    {
      idLib::Warning(fmt: "out of obstacle avoidance buffers");
    }
  }
}


// ========================================================================
// ?FreeObstacleBuffers@idObstacleAvoidanceManagerLocal@@UAAXPAVidObstacleAvoidance@@@Z
// EA  : 0x826C8D60
// RVA : 0x006C8D60
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceManagerLocal::FreeObstacleBuffers(
        idObstacleAvoidanceManagerLocal *this,
        idObstacleAvoidance *obstacleAvoidance)
{
  int num; // r10
  idList<idObstacleBuffers *,5> *p_usedBuffers; // r31
  int v5; // r30
  int i; // r11
  int v7; // r11
  int v8; // r11

  if ( obstacleAvoidance->buffers != nullptr )
  {
    num = this->usedBuffers.num;
    p_usedBuffers = &this->usedBuffers;
    v5 = 0;
    if ( num > 0 )
    {
      for ( i = 0; p_usedBuffers->list[i] != obstacleAvoidance->buffers; ++i )
      {
        if ( ++v5 >= num )
          return;
      }
      if ( v5 >= 0 )
      {
        p_usedBuffers->list[v5]->user = nullptr;
        p_usedBuffers->list[v5]->job = nullptr;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->toBeFreedBuffers,
          obj: (const encounterGroupRole_t *)&p_usedBuffers->list[v5]);
        v7 = p_usedBuffers->num;
        if ( v5 < v7 )
        {
          v8 = v7 - 1;
          p_usedBuffers->num = v8;
          if ( v5 != v8 )
            p_usedBuffers->list[v5] = p_usedBuffers->list[v8];
        }
        obstacleAvoidance->buffers = nullptr;
      }
    }
  }
}


// ========================================================================
// ?FrameFreeObstacleBuffers@idObstacleAvoidanceManagerLocal@@UAAXXZ
// EA  : 0x826C8E30
// RVA : 0x006C8E30
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceManagerLocal::FrameFreeObstacleBuffers(idObstacleAvoidanceManagerLocal *this)
{
  int v2; // r29
  idList<idObstacleBuffers *,5> *p_usedBuffers; // r30
  int v4; // r31
  idObstacleBuffers *v5; // r11
  int v6; // r9
  int num; // r11
  int v8; // r11
  int v9; // r30
  int v10; // r31
  idList<idObstacleBuffers *,5> *p_toBeFreedBuffers; // r31

  v2 = 0;
  if ( this->usedBuffers.num > 0 )
  {
    p_usedBuffers = &this->usedBuffers;
    v4 = 0;
    do
    {
      v5 = p_usedBuffers->list[v4];
      v6 = v5->frameCount - 1;
      v5->frameCount = v6;
      if ( v6 <= 0 )
      {
        p_usedBuffers->list[v4]->user->buffers = nullptr;
        p_usedBuffers->list[v4]->user = nullptr;
        p_usedBuffers->list[v4]->job = nullptr;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->toBeFreedBuffers,
          obj: (const encounterGroupRole_t *)&p_usedBuffers->list[v4]);
        if ( v2 >= 0 )
        {
          num = p_usedBuffers->num;
          if ( v2 < num )
          {
            v8 = num - 1;
            p_usedBuffers->num = v8;
            if ( v2 != v8 )
              p_usedBuffers->list[v4] = p_usedBuffers->list[v8];
          }
        }
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->usedBuffers.num );
  }
  v9 = 0;
  if ( this->toBeFreedBuffers.num > 0 )
  {
    v10 = 0;
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->freeBuffers,
        obj: (const encounterGroupRole_t *)&this->toBeFreedBuffers.list[v10]);
      ++v9;
      ++v10;
    }
    while ( v9 < this->toBeFreedBuffers.num );
  }
  p_toBeFreedBuffers = &this->toBeFreedBuffers;
  if ( this->toBeFreedBuffers.size < 0 )
  {
    if ( this->toBeFreedBuffers.listStatic == 0 || this->toBeFreedBuffers.listStatic == 2 )
    {
      if ( p_toBeFreedBuffers->list != nullptr )
        idMem::Free(this: &mem, ptr: p_toBeFreedBuffers->list, align: ALIGN_16);
      p_toBeFreedBuffers->list = nullptr;
      this->toBeFreedBuffers.size = 0;
    }
    this->toBeFreedBuffers.num = 0;
  }
  this->toBeFreedBuffers.num = __CFADD__(-this->toBeFreedBuffers.size, this->toBeFreedBuffers.size ^ 0x80000000)
                             ? 0
                             : this->toBeFreedBuffers.size;
}


// ========================================================================
// `dynamic initializer for 'obstacleAvoidanceManagerLocal''
// EA  : 0x8333EA20
// RVA : 0x0133EA20
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__obstacleAvoidanceManagerLocal__()
{
  idObstacleAvoidanceManagerLocal::idObstacleAvoidanceManagerLocal(this: &obstacleAvoidanceManagerLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__obstacleAvoidanceManagerLocal__);
}

