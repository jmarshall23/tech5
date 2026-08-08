
// ========================================================================
// ??1ContourManager@@QAA@XZ
// EA  : 0x827B9D70
// RVA : 0x007B9D70
// PDB : w:\tech5\engine\models\cuttable\cuttercontour.cpp
// ========================================================================

void __fastcall ContourManager::~ContourManager(ContourManager *this)
{
  Contour *contoursPool; // r4
  Contour *next; // r31
  ContourEdge_t *edgesPool; // r4
  ContourEdge_t *v5; // r31
  ContourNode_t *nodesPool; // r4
  ContourNode_t *v7; // r31

  contoursPool = this->contoursPool;
  if ( this->contoursPool != nullptr )
  {
    do
    {
      next = contoursPool->next;
      idMem::Free(this: &mem, ptr: contoursPool, align: ALIGN_16);
      contoursPool = next;
    }
    while ( next != nullptr );
  }
  edgesPool = this->edgesPool;
  if ( edgesPool != nullptr )
  {
    do
    {
      v5 = edgesPool->next;
      idMem::Free(this: &mem, ptr: edgesPool, align: ALIGN_16);
      edgesPool = v5;
    }
    while ( v5 != nullptr );
  }
  nodesPool = this->nodesPool;
  if ( nodesPool != nullptr )
  {
    do
    {
      v7 = nodesPool->next;
      idMem::Free(this: &mem, ptr: nodesPool, align: ALIGN_16);
      nodesPool = v7;
    }
    while ( v7 != nullptr );
  }
}


// ========================================================================
// ?Free@ContourManager@@QAAXPAVContour@@@Z
// EA  : 0x827B9E08
// RVA : 0x007B9E08
// PDB : w:\tech5\engine\models\cuttable\cuttercontour.cpp
// ========================================================================

void __fastcall ContourManager::Free(ContourManager *this, Contour *contour)
{
  ContourEdge_t *edges; // r9
  ContourNode_t *node; // r11
  ContourEdge_t *next; // r8
  ContourNode_t *v5; // r10
  bool v6; // cr58

  edges = contour->edges;
  if ( edges != nullptr )
  {
    do
    {
      node = edges->node;
      next = edges->next;
      if ( node != nullptr )
      {
        do
        {
          v5 = node->next;
          v6 = node->next == nullptr;
          node->next = this->nodesPool;
          this->nodesPool = node;
          node = v5;
        }
        while ( !v6 );
      }
      edges->next = this->edgesPool;
      this->edgesPool = edges;
      edges = next;
    }
    while ( next != nullptr );
  }
  contour->next = this->contoursPool;
  this->contoursPool = contour;
}


// ========================================================================
// ?AllocContour@ContourManager@@AAAPAVContour@@XZ
// EA  : 0x827B9E68
// RVA : 0x007B9E68
// PDB : w:\tech5\engine\models\cuttable\cuttercontour.cpp
// ========================================================================

Contour *__fastcall ContourManager::AllocContour(ContourManager *this)
{
  Contour *v2; // r3
  Contour *result; // r3

  if ( this->contoursPool == nullptr )
  {
    v2 = (Contour *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\engine\\models\\cuttable\\CutterContour.cpp(390) : TAG_GAME",
                      size: 0x1Cu,
                      tag: TAG_GAME,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
    this->contoursPool = v2;
    this->contoursPool = v2;
    v2->next = nullptr;
  }
  result = this->contoursPool;
  this->contoursPool = this->contoursPool->next;
  return result;
}


// ========================================================================
// ?AllocNode@ContourManager@@AAAPAUContourNode_t@@XZ
// EA  : 0x827B9EE0
// RVA : 0x007B9EE0
// PDB : w:\tech5\engine\models\cuttable\cuttercontour.cpp
// ========================================================================

ContourNode_t *__fastcall ContourManager::AllocNode(ContourManager *this)
{
  ContourNode_t *v2; // r3
  ContourNode_t *result; // r3

  if ( this->nodesPool == nullptr )
  {
    v2 = (ContourNode_t *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\models\\cuttable\\CutterContour.cpp(420) : TAG_GAME",
                            size: 0xCu,
                            tag: TAG_GAME,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    this->nodesPool = v2;
    this->nodesPool = v2;
    v2->next = nullptr;
  }
  result = this->nodesPool;
  this->nodesPool = result->next;
  return result;
}


// ========================================================================
// ?Create@ContourManager@@QAAPAVContour@@ABV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827B9F58
// RVA : 0x007B9F58
// PDB : w:\tech5\engine\models\cuttable\cuttercontour.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
Contour *__fastcall ContourManager::Create(ContourManager *this, const idList<idVec2i,5> *points)
{
  Contour *v4; // r3
  signed int num; // r24
  Contour *v6; // r19
  int v7; // r30
  int v8; // r25
  int v9; // r28
  const idVec2i *v10; // r5
  const idVec2i *v11; // r4
  const idVec2i *v12; // r3
  int y; // r18
  int v14; // r17
  ContourNode_t *nodesPool; // r29
  int x; // r23
  ContourEdge_t *v17; // r21
  ContourNode_t *v18; // r22
  ContourEdge_t *v19; // r16
  signed int v20; // r14
  signed int v21; // r15
  ContourNode_t *v22; // r3
  idVec2i *list; // r9
  idVec2i *v24; // r11
  signed int v25; // r11
  ContourNode_t *v26; // r3
  ContourNode_t *v27; // r11
  idVec2i *v28; // r7
  int v29; // r2 OVERLAPPED
  ContourEdge_t *edgesPool; // r11
  ContourEdge_t *v31; // r3
  ContourEdge_t *v32; // r3
  ContourEdge_t *v33; // r11
  __int64 v34; // r6
  __int64 v35; // r8
  __int64 v36; // r5
  int v37; // r3
  __int64 v39; // [sp+50h] [-B0h]
  int v40; // [sp+60h] [-A0h]

  v4 = ContourManager::AllocContour(this);
  num = points->num;
  v6 = v4;
  v7 = 0;
  v8 = 1;
  v9 = 2;
  if ( num > 3 )
  {
    do
    {
      v10 = &points->list[v9];
      v11 = &points->list[v8];
      v12 = &points->list[v7];
      v7 = v8;
      v8 = v9;
      __twllei(num, 0);
      __twlgei(num & ~(__ROL4__(v9 + 1, 1) - 1), 0xFFFFFFFF);
      v9 = (v9 + 1) % num;
    }
    while ( Contour::SlopesEqual(v1: v12, v2: v11, v3: v10) );
  }
  v40 = v7;
  y = 0x7FFFFFFF;
  v14 = 0;
  nodesPool = nullptr;
  x = 0x7FFFFFFF;
  v17 = nullptr;
  v18 = nullptr;
  v19 = nullptr;
  v20 = 0x80000000;
  v21 = 0x80000000;
  do
  {
    if ( nodesPool == nullptr )
    {
      if ( this->nodesPool == nullptr )
      {
        v22 = (ContourNode_t *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\models\\cuttable\\CutterContour.cpp(420) : TAG_GAME",
                                 size: 0xCu,
                                 tag: TAG_GAME,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        this->nodesPool = v22;
        this->nodesPool = v22;
        v22->next = nullptr;
      }
      nodesPool = this->nodesPool;
      v18 = nodesPool;
      this->nodesPool = nodesPool->next;
      nodesPool->next = nullptr;
      list = points->list;
      nodesPool->pos.x = points->list[v7].x;
      nodesPool->pos.y = list[v7].y;
      v24 = &points->list[v7];
      if ( x >= v24->x )
        x = v24->x;
      if ( y >= v24->y )
        y = v24->y;
      if ( v20 < v24->x )
        v20 = v24->x;
      v25 = v24->y;
      if ( v21 < v25 )
        v21 = v25;
    }
    if ( this->nodesPool == nullptr )
    {
      v26 = (ContourNode_t *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\engine\\models\\cuttable\\CutterContour.cpp(420) : TAG_GAME",
                               size: 0xCu,
                               tag: TAG_GAME,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
      this->nodesPool = v26;
      this->nodesPool = v26;
      v26->next = nullptr;
    }
    v27 = this->nodesPool;
    this->nodesPool = v27->next;
    nodesPool->next = v27;
    nodesPool = v27;
    v28 = points->list;
    v27->pos.x = points->list[v8].x;
    v27->pos.y = v28[v8].y;
    v27->next = nullptr;
    if ( !Contour::SlopesEqual(v1: &points->list[v7], v2: &points->list[v8], v3: &points->list[v9]) )
    {
      edgesPool = this->edgesPool;
      if ( v17 != nullptr )
      {
        if ( edgesPool == nullptr )
        {
          v32 = (ContourEdge_t *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\models\\cuttable\\CutterContour.cpp(405) : TAG_GAME",
                                   size: 8u,
                                   tag: TAG_GAME,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
          this->edgesPool = v32;
          v32->next = nullptr;
        }
        v33 = this->edgesPool;
        this->edgesPool = v33->next;
        v17->next = v33;
        v17 = v33;
      }
      else
      {
        if ( edgesPool == nullptr )
        {
          v31 = (ContourEdge_t *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\models\\cuttable\\CutterContour.cpp(405) : TAG_GAME",
                                   size: 8u,
                                   tag: TAG_GAME,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
          this->edgesPool = v31;
          v31->next = nullptr;
        }
        v17 = this->edgesPool;
        v19 = v17;
        this->edgesPool = v17->next;
      }
      v17->node = v18;
      nodesPool = nullptr;
      v17->next = nullptr;
      ++v14;
    }
    v7 = v8;
    HIDWORD(v34) = num & ~(__ROL4__(v9 + 1, 1) - 1);
    v8 = v9;
    __twllei(num, 0);
    __twlgei(HIDWORD(v34), 0xFFFFFFFF);
    v9 = (v9 + 1) % num;
  }
  while ( v7 != v40 );
  v6->edges = v19;
  v6->numEdges = v14;
  LODWORD(v34) = v21 - y + 2;
  HIDWORD(v35) = v20 - x + 2;
  v39 = v34;
  HIDWORD(v36) = y - 1;
  LODWORD(v35) = x - 1;
  v37 = y - 1;
  LODWORD(v36) = HIDWORD(v35);
  v6->bound.bounds[0].x = (float)v35;
  v6->bound.bounds[0].y = (float)*(__int64 *)(&v29 - 1);
  v6->bound.bounds[1].x = (float)v35 + (float)v36;
  v6->bound.bounds[1].y = (float)*(__int64 *)(&v29 - 1) + (float)v39;
  v6->next = nullptr;
  return v6;
}


// ========================================================================
// ?Merge@ContourManager@@QAAXPAVContour@@@Z
// EA  : 0x827BA300
// RVA : 0x007BA300
// PDB : w:\tech5\engine\models\cuttable\cuttercontour.cpp
// ========================================================================

void __fastcall ContourManager::Merge(ContourManager *this, Contour *contours)
{
  Contour *v3; // r18
  ContourNode_t *i; // r26
  Contour *j; // r20
  ContourEdge_t *k; // r25
  ContourEdge_t *edges; // r27
  ContourNode_t *node; // r31
  ContourNode_t *v9; // r30
  ContourNode_t *v10; // r29
  int v11; // r28
  ContourNode_t *m; // r10
  ContourNode_t *v14; // r10
  ContourNode_t *v15; // r11
  ContourNode_t *v16; // r9
  ContourNode_t *next; // r8
  char *v18; // r9
  char *v19; // r9
  _DWORD *v20; // r9
  ContourNode_t *v21; // r8
  _DWORD *v22; // r10
  _DWORD *v23; // r11
  int n; // ctr
  int v25; // r31
  char *v26; // r30
  ContourNode_t *nodesPool; // r11
  _DWORD *v28; // r11
  ContourNode_t *v29; // r3
  int v30; // r10
  ContourNode_t *v31; // r11
  bool v32; // cr58
  _DWORD *v33; // r11
  int ii; // ctr
  char v35; // [sp+5Ch] [-484h] BYREF
  _DWORD v36[288]; // [sp+60h] [-480h] BYREF

  v3 = contours;
  for ( i = nullptr; v3 != nullptr; v3 = v3->next )
  {
    for ( j = v3->next; j != nullptr; j = j->next )
    {
      for ( k = v3->edges; k != nullptr; k = k->next )
      {
        edges = j->edges;
        if ( edges != nullptr )
        {
          while ( 1 )
          {
            node = k->node;
            v9 = nullptr;
            v10 = nullptr;
            if ( Contour::SlopesEqual(
                   v1: &node->pos,
                   v2: &node->next->pos,
                   v3: &edges->node->pos,
                   v4: &edges->node->next->pos) )
            {
              v11 = 0;
              while ( v9 == nullptr )
              {
                if ( v10 != nullptr )
                  goto LABEL_21;
                for ( m = edges->node; m != nullptr; m = m->next )
                {
                  if ( v9 != nullptr || v10 != nullptr )
                    break;
                  if ( (int)abs32(node->pos.x - m->pos.x) <= (int)0.00000011920929
                    && (int)0.00000011920929 >= (int)abs32(node->pos.y - m->pos.y) )
                  {
                    v9 = node;
                    v10 = m;
                  }
                }
                node = node->next;
                if ( node == nullptr )
                {
                  if ( v9 == nullptr )
                    goto LABEL_21;
                  break;
                }
              }
              if ( v10 != nullptr )
                break;
            }
LABEL_21:
            edges = edges->next;
            if ( edges == nullptr )
              goto LABEL_61;
          }
          v14 = k->node;
          v15 = edges->node;
          if ( (v14->next->pos.y - v14->pos.y) * (v15->next->pos.y - v15->pos.y)
             + (v15->next->pos.x - v15->pos.x) * (v14->next->pos.x - v14->pos.x) <= 0 )
          {
            v16 = nullptr;
            do
            {
              next = v15->next;
              v15->next = v16;
              v16 = v15;
              v15 = next;
            }
            while ( next != nullptr );
            edges->node = v16;
            v15 = v16;
          }
          if ( v9 == v14 )
          {
            if ( v15 != v10 )
            {
              v18 = &v35;
              do
              {
                v18 += 4;
                *(_DWORD *)v18 = v15;
                ++v11;
                v15 = v15->next;
              }
              while ( v15 != v10 );
            }
          }
          else
          {
            v19 = &v35;
            do
            {
              v19 += 4;
              *(_DWORD *)v19 = v14;
              ++v11;
              v14 = v14->next;
            }
            while ( v14 != v9 );
          }
          if ( v14 != nullptr )
          {
            v20 = &v36[v11 - 1];
            while ( v15 != nullptr )
            {
              *++v20 = v14;
              ++v11;
              v14 = v14->next;
              v21 = v15->next;
              v15->next = i;
              i = v15;
              v15 = v21;
              if ( v14 == nullptr )
                goto LABEL_38;
            }
            v28 = &v36[v11 - 1];
            do
            {
              *++v28 = v14;
              ++v11;
              v14 = v14->next;
            }
            while ( v14 != nullptr );
          }
          else
          {
LABEL_38:
            if ( v15 != nullptr )
            {
              v22 = &v36[v11 - 1];
              do
              {
                *++v22 = v15;
                ++v11;
                v15 = v15->next;
              }
              while ( v15 != nullptr );
            }
          }
          v36[v11] = 0;
          if ( v11 > 0 )
          {
            v23 = v36;
            for ( n = v11; n != 0; --n )
            {
              *(_DWORD *)*v23 = v23[1];
              ++v23;
            }
          }
          k->node = (ContourNode_t *)v36[0];
          if ( v11 > 0 )
          {
            v25 = v11;
            v26 = &v35;
            do
            {
              nodesPool = i;
              if ( i != nullptr )
              {
                i = i->next;
              }
              else
              {
                if ( this->nodesPool == nullptr )
                {
                  v29 = (ContourNode_t *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\models\\cuttable\\CutterContour.cpp(420) : TAG_GAME",
                                           size: 0xCu,
                                           tag: TAG_GAME,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
                  this->nodesPool = v29;
                  this->nodesPool = v29;
                  v29->next = nullptr;
                }
                nodesPool = this->nodesPool;
                this->nodesPool = nodesPool->next;
              }
              v30 = *((_DWORD *)v26 + 1);
              --v25;
              v26 += 4;
              *(_DWORD *)v26 = nodesPool;
              nodesPool->pos.x = *(_DWORD *)(v30 + 4);
              nodesPool->pos.y = *(_DWORD *)(v30 + 8);
            }
            while ( v25 != 0 );
          }
          if ( i != nullptr )
          {
            do
            {
              v31 = i->next;
              v32 = i->next == nullptr;
              i->next = this->nodesPool;
              this->nodesPool = i;
              i = v31;
            }
            while ( !v32 );
          }
          if ( v11 > 0 )
          {
            v33 = v36;
            for ( ii = v11; ii != 0; --ii )
            {
              *(_DWORD *)*v33 = v33[1];
              ++v33;
            }
          }
          edges->node = (ContourNode_t *)v36[0];
        }
LABEL_61:
        ;
      }
    }
  }
}


// ========================================================================
// ?SplitEdge@ContourManager@@QAAXPAUContourEdge_t@@ABVidVec2i@@11@Z
// EA  : 0x827BA708
// RVA : 0x007BA708
// PDB : w:\tech5\engine\models\cuttable\cuttercontour.cpp
// ========================================================================

void __fastcall ContourManager::SplitEdge(
        ContourManager *this,
        ContourEdge_t *edge,
        const idVec2i *v0,
        const idVec2i *v1,
        const idVec2i *pos)
{
  ContourNode_t *node; // r30
  ContourNode_t *next; // r31
  int x; // r9
  int v10; // r10
  char v11; // r11
  char v12; // r11
  char v13; // r11
  char v14; // r11
  ContourNode_t *v15; // r3
  ContourNode_t *i; // r11

  node = edge->node;
  next = node->next;
  if ( node->next != nullptr )
  {
    x = v0->x;
    while ( 1 )
    {
      v10 = node->pos.x;
      if ( x != v10 || (v11 = 1, v0->y != node->pos.y) )
        v11 = 0;
      if ( v11 != 0 )
      {
        if ( v1->x != next->pos.x || (v12 = 1, v1->y != next->pos.y) )
          v12 = 0;
        if ( v12 != 0 )
          break;
      }
      if ( x != next->pos.x || (v13 = 1, v0->y != next->pos.y) )
        v13 = 0;
      if ( v13 != 0 )
      {
        if ( v1->x != v10 || (v14 = 1, v1->y != node->pos.y) )
          v14 = 0;
        if ( v14 != 0 )
          break;
      }
      node = next;
      next = next->next;
      if ( next == nullptr )
        return;
    }
    v15 = ContourManager::AllocNode(this);
    v15->pos = *pos;
    v15->next = next;
    node->next = v15;
    for ( i = edge->node; i != nullptr; i = i->next )
      ;
  }
}

