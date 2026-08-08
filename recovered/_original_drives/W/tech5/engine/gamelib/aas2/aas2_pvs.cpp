
// ========================================================================
// ?ShutdownObstaclePVS@idAAS2Local@@AAAXXZ
// EA  : 0x826B46E8
// RVA : 0x006B46E8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

void __fastcall idAAS2Local::ShutdownObstaclePVS(idAAS2Local *this)
{
  idMem::Free(this: &mem, ptr: this->obstaclePVS, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->areaClipModels, align: ALIGN_16);
  this->numObstaclePVSBytes = 0;
  this->obstaclePVS = nullptr;
  this->areaClipModels = nullptr;
  this->obstaclePVSAreaNum = 0;
}


// ========================================================================
// ?GetObstaclePVSWallEdges@idAAS2Local@@UBAHHHPAHH@Z
// EA  : 0x826B4758
// RVA : 0x006B4758
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2Local::GetObstaclePVSWallEdges(
        idAAS2Local *this,
        int areaNum,
        int edgeFlags,
        int *edges,
        int maxEdges)
{
  idAAS2File *result; // r3

  result = this->file;
  if ( result != nullptr )
    return (idAAS2File *)idAAS2File::GetObstaclePVSWallEdges(this: result, areaNum, edgeFlags, edges, maxEdges);
  return result;
}


// ========================================================================
// ?UnLinkClipModel@idAAS2Local@@UAAPAVidAASClipLink@@PAV2@@Z
// EA  : 0x826B4810
// RVA : 0x006B4810
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

idAASClipLink *__fastcall idAAS2Local::UnLinkClipModel(idAAS2Local *this, idAASClipLink *link)
{
  idAASClipLink *prevClip; // r11
  idAASClipLink *nextArea; // r9
  idAASClipLink *nextClip; // r11
  int v5; // r8

  if ( link != nullptr )
  {
    do
    {
      prevClip = link->prevClip;
      nextArea = link->nextArea;
      if ( prevClip != nullptr )
        prevClip->nextClip = link->nextClip;
      else
        this->areaClipModels[link->areaNum] = link->nextClip;
      nextClip = link->nextClip;
      if ( nextClip != nullptr )
        nextClip->prevClip = link->prevClip;
      link->prevArea = (idAASClipLink *)this->clipModelLinkAllocator.free;
      v5 = this->clipModelLinkAllocator.active - 1;
      this->clipModelLinkAllocator.free = (idBlockAlloc<idAASClipLink,128,37>::element_t *)link;
      link = nextArea;
      this->clipModelLinkAllocator.active = v5;
    }
    while ( nextArea != nullptr );
  }
  return nullptr;
}


// ========================================================================
// ?SetupObstaclePVS@idAAS2Local@@AAAXXZ
// EA  : 0x826B4890
// RVA : 0x006B4890
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

void __fastcall idAAS2Local::SetupObstaclePVS(idAAS2Local *this)
{
  int v2; // r5

  v2 = (this->file->areas.num + 7) / 8;
  this->numObstaclePVSBytes = v2;
  this->obstaclePVS = (unsigned __int8 *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_pvs.cpp(26) : TAG_AAS",
                                           size: v2,
                                           tag: TAG_AAS,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
  this->areaClipModels = (idAASClipLink **)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_pvs.cpp(27) : TAG_AAS",
                                             size: 4 * this->file->areas.num,
                                             tag: TAG_AAS,
                                             zeroBuffer: true,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?GetObstaclePVS@idAAS2Local@@UBAPBEH@Z
// EA  : 0x826B4938
// RVA : 0x006B4938
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

unsigned __int8 *__fastcall idAAS2Local::GetObstaclePVS(idAAS2Local *this, int areaNum)
{
  int obstaclePVSAreaNum; // r11
  unsigned __int8 *result; // r3
  idAAS2File *file; // r8
  int v7; // r11
  int num; // r3
  unsigned int obstaclePVSOffset; // r4
  unsigned __int8 *list; // r9
  int v11; // r10
  int v12; // r10
  bool v13; // zf
  int v14; // r9
  int v15; // r6
  int v16; // r27
  int v17; // r7
  int v18; // r8
  int v19; // r29
  int v20; // r25
  char v21; // r23
  int v22; // r9

  obstaclePVSAreaNum = this->obstaclePVSAreaNum;
  result = this->obstaclePVS;
  if ( areaNum != obstaclePVSAreaNum )
  {
    memset(Dst: result, Val: 0, Size: this->numObstaclePVSBytes);
    file = this->file;
    v7 = 0;
    num = file->areas.num;
    obstaclePVSOffset = file->areas.list[areaNum].obstaclePVSOffset;
    if ( num > 0 )
    {
      do
      {
        list = this->file->obstaclePVS.list;
        v11 = list[obstaclePVSOffset++];
        if ( (v11 & 0x80) != 0 )
        {
          v13 = (v11 & 0x40) == 0;
          v12 = v11 & 0x3F;
          if ( !v13 )
          {
            v14 = list[obstaclePVSOffset++];
            v12 |= __ROL4__(v14, 6);
          }
          v7 += v12 + 1;
        }
        else
        {
          this->obstaclePVS[v7 >> 3] |= (v11 & 1) << (v7 & 7);
          v15 = (v7 + 3) >> 3;
          v16 = ((v11 >> 3) & 1) << ((v7 + 3) & 7);
          this->obstaclePVS[(v7 + 1) >> 3] |= ((v11 >> 1) & 1) << ((v7 + 1) & 7);
          v17 = (v7 + 4) >> 3;
          v18 = (v7 + 5) >> 3;
          v19 = ((v11 >> 4) & 1) << ((v7 - 4) & 7);
          v20 = ((v11 >> 5) & 1) << ((v7 - 3) & 7);
          v21 = (v7 - 2) & 7;
          this->obstaclePVS[(v7 + 2) >> 3] |= ((v11 >> 2) & 1) << ((v7 + 2) & 7);
          v22 = (v7 + 6) >> 3;
          v7 += 7;
          this->obstaclePVS[v15] |= v16;
          this->obstaclePVS[v17] |= v19;
          this->obstaclePVS[v18] |= v20;
          this->obstaclePVS[v22] |= ((v11 >> 6) & 1) << v21;
        }
      }
      while ( v7 < num );
    }
    result = this->obstaclePVS;
    this->obstaclePVSAreaNum = areaNum;
  }
  return result;
}


// ========================================================================
// ?FreeClipLinks@idAAS2Local@@UAAXXZ
// EA  : 0x826B4B18
// RVA : 0x006B4B18
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

void __fastcall idAAS2Local::FreeClipLinks(idAAS2Local *this)
{
  int num; // ctr
  int v3; // r11

  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: &this->clipModelLinkAllocator);
  if ( this->file->areas.num > 0 )
  {
    num = this->file->areas.num;
    v3 = 0;
    do
    {
      this->areaClipModels[v3++] = nullptr;
      --num;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?LinkClipModel@idAAS2Local@@UAAPAVidAASClipLink@@PAVidClipModel@@@Z
// EA  : 0x826B4B78
// RVA : 0x006B4B78
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

idAASClipLink *__fastcall idAAS2Local::LinkClipModel(idAAS2Local *this, idClipModel *clip)
{
  char *v2; // r10
  float *p_z; // r11
  int i; // ctr
  idAAS2File *file; // r3
  idAASClipLink *v8; // r26
  int v9; // r24
  int v10; // r3
  int j; // r10
  int *v12; // r11
  int k; // ctr
  int v14; // r8
  int *v15; // r30
  int v16; // r27
  idAASClipLink *free; // r11
  int *p_areaNum; // r10
  int m; // ctr
  int v20; // r10
  int v21; // r10
  idAASClipLink *v22; // r8
  idAASClipLink **areaClipModels; // r7
  char v25; // [sp+4Ch] [-274h] BYREF
  idBounds v26; // [sp+50h] [-270h] BYREF
  int v27[148]; // [sp+70h] [-250h] BYREF

  v2 = &v25;
  p_z = &clip->bounds.b[1].z;
  for ( i = 6; i != 0; --i )
  {
    ++p_z;
    v2 += 4;
    *(float *)v2 = *p_z;
  }
  file = this->file;
  v8 = nullptr;
  v9 = 0;
  v26.b[0].x = v26.b[0].x - file->settings.boundingBox.b[1].x;
  v26.b[0].y = v26.b[0].y - file->settings.boundingBox.b[1].y;
  v26.b[1].x = v26.b[1].x - file->settings.boundingBox.b[0].x;
  v26.b[1].y = v26.b[1].y - file->settings.boundingBox.b[0].y;
  if ( file->trees.num > 0 )
  {
    while ( 1 )
    {
      v10 = idAAS2File::BoundsAreaNums(this: file, tree: v9, bounds: &v26, areas: v27, maxAreas: 128);
      for ( j = v10 - 1; j > 0; --j )
      {
        if ( j > 0 )
        {
          v12 = v27;
          for ( k = j; k != 0; --k )
          {
            if ( *v12 < v12[1] )
            {
              v14 = *v12;
              *v12 = v12[1];
              v12[1] = v14;
            }
            ++v12;
          }
        }
      }
      if ( v10 > 0 )
        break;
LABEL_25:
      file = this->file;
      if ( ++v9 >= file->trees.num )
        return v8;
    }
    v15 = v27;
    v16 = v10;
    while ( 1 )
    {
      if ( this->clipModelLinkAllocator.free != nullptr )
        goto LABEL_17;
      if ( this->clipModelLinkAllocator.allowAllocs )
        break;
      free = nullptr;
LABEL_20:
      v20 = *v15;
      free->clipModel = clip;
      free->nextArea = v8;
      free->prevArea = nullptr;
      free->areaNum = v20;
      if ( v8 != nullptr )
        v8->prevArea = free;
      v21 = v20;
      v8 = free;
      v22 = this->areaClipModels[v21];
      free->prevClip = nullptr;
      free->nextClip = v22;
      areaClipModels = this->areaClipModels;
      if ( areaClipModels[v21] != nullptr )
        areaClipModels[v21]->prevClip = free;
      --v16;
      ++v15;
      this->areaClipModels[v21] = free;
      if ( v16 == 0 )
        goto LABEL_25;
    }
    idBlockAlloc<idAASClipLink,128,37>::AllocNewBlock(this: &this->clipModelLinkAllocator);
LABEL_17:
    free = (idAASClipLink *)this->clipModelLinkAllocator.free;
    ++this->clipModelLinkAllocator.active;
    this->clipModelLinkAllocator.free = (idBlockAlloc<idAASClipLink,128,37>::element_t *)free->prevArea;
    free->prevArea = nullptr;
    if ( this->clipModelLinkAllocator.clearAllocs )
    {
      p_areaNum = &free[-1].areaNum;
      for ( m = 6; m != 0; --m )
        *++p_areaNum = 0;
    }
    goto LABEL_20;
  }
  return v8;
}


// ========================================================================
// ?GetObstaclePVSClipModels@idAAS2Local@@UBAHHPAPAVidClipModel@@H@Z
// EA  : 0x826B4D68
// RVA : 0x006B4D68
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

int __fastcall idAAS2Local::GetObstaclePVSClipModels(
        idAAS2Local *this,
        int areaNum,
        idClipModel **clipModels,
        int maxClipModels)
{
  int v8; // r30
  int v9; // r29
  int v10; // r7
  int num; // r25
  int v12; // r28
  unsigned __int8 *list; // r10
  int v14; // r29
  int v15; // r11
  int v16; // r10
  int v17; // r3
  int v18; // r4
  idAASClipLink *v19; // r9
  idClipModel **v20; // r6
  idAASClipLink *prevArea; // r11
  char v22; // r8
  int v23; // r23
  idAASClipLink *i; // r11

  v8 = 0;
  v9 = ((int (__fastcall *)(idAAS2Local *))this->GetArea)(a1: this);
  memset(Dst: this->obstaclePVS, Val: 0, Size: this->numObstaclePVSBytes);
  v10 = 0;
  num = this->file->areas.num;
  v12 = *(_DWORD *)(v9 + 16);
  if ( num <= 0 )
  {
LABEL_24:
    this->obstaclePVSAreaNum = areaNum;
  }
  else
  {
    while ( 1 )
    {
      list = this->file->obstaclePVS.list;
      v14 = list[v12++];
      if ( (v14 & 0x80) == 0 )
        break;
      v15 = v14 & 0x3F;
      if ( (v14 & 0x40) != 0 )
      {
        v16 = list[v12++];
        v15 |= __ROL4__(v16, 6);
      }
      v10 += v15 + 1;
LABEL_23:
      if ( v10 >= num )
        goto LABEL_24;
    }
    v17 = 0;
    v18 = v10;
    while ( 1 )
    {
      this->obstaclePVS[v10 >> 3] |= ((v14 >> v17) & 1) << (v10 & 7);
      ++v10;
      ++v18;
      if ( ((1 << v17) & v14) != 0 )
      {
        v19 = this->areaClipModels[v18 - 1];
        if ( v19 != nullptr )
          break;
      }
LABEL_22:
      if ( ++v17 >= 7 )
        goto LABEL_23;
    }
    v20 = &clipModels[v8 - 1];
    while ( v8 < maxClipModels )
    {
      prevArea = v19->prevArea;
      v22 = 0;
      if ( v19->prevArea != nullptr )
      {
        while ( 1 )
        {
          v23 = prevArea->areaNum;
          if ( v23 < v19->areaNum && ((1 << (v23 & 7)) & this->obstaclePVS[v23 >> 3]) != 0 )
            break;
          prevArea = prevArea->prevArea;
          if ( prevArea == nullptr )
            goto LABEL_17;
        }
        v22 = 1;
      }
LABEL_17:
      for ( i = v19->nextArea; i != nullptr; i = i->nextArea )
        ;
      if ( v22 == 0 )
      {
        ++v8;
        *++v20 = v19->clipModel;
      }
      v19 = v19->nextClip;
      if ( v19 == nullptr )
        goto LABEL_22;
    }
  }
  return v8;
}


// ========================================================================
// ?GetObstaclePVSObstaclesInternal@idAAS2Local@@ABAXHHPAUobstacleVertex_t@@AAHPAUobstacleEdge_t@@1PAPAVidClipModel@@1PAUobstacleRoute_t@@@Z
// EA  : 0x826B4F38
// RVA : 0x006B4F38
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

void __fastcall idAAS2Local::GetObstaclePVSObstaclesInternal(
        idAAS2Local *this,
        int areaNum,
        const int edgeFlags,
        obstacleVertex_t *vertices,
        int *maxVertices,
        obstacleEdge_t *edges,
        int *maxEdges,
        idClipModel **clipModels,
        int *maxClipModels,
        obstacleRoute_t *route,
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
        _DWORD *a28,
        int a29,
        int *a30)
{
  _DWORD *v31; // r21
  int *v32; // r22
  int v34; // r28
  int *v37; // r24
  int v38; // r31
  int v39; // r30
  int v40; // r27
  int v41; // r23
  int v42; // r20
  int v43; // r26
  int num; // r9
  int v45; // r16
  unsigned __int8 *list; // r10
  int v47; // r21
  int v48; // r11
  int v49; // r10
  int v50; // r22
  int v51; // r20
  int v52; // r24
  idAASClipLink *v53; // r9
  idClipModel **v54; // r7
  idAASClipLink *prevArea; // r11
  char v56; // r8
  int v57; // r6
  idAASClipLink *i; // r11
  const aas2Area_t *v59; // r3
  int v60; // r31
  int v61; // r28
  int v62; // r11
  obstacleVertex_t *v63; // r8
  __int16 *v64; // r9
  idAAS2File *file; // r7
  unsigned int v66; // r10
  unsigned int v67; // r5
  int v68; // r6
  int v69; // r4
  float *p_x; // r10
  idVec3 *v71; // r10
  int v72; // r7
  int v73; // r9
  int *j; // r11
  int v75; // [sp+54h] [-ACh]
  int v76; // [sp+58h] [-A8h]
  int v77; // [sp+5Ch] [-A4h]
  int v78; // [sp+60h] [-A0h]

  v31 = a28;
  v32 = maxEdges;
  v34 = areaNum;
  v37 = maxVertices;
  v38 = *a28;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v78 = *maxVertices;
  v77 = *maxEdges;
  v75 = *a28;
  v42 = ((int (__fastcall *)(idAAS2Local *))this->GetArea)(a1: this);
  memset(Dst: this->obstaclePVS, Val: 0, Size: this->numObstaclePVSBytes);
  v43 = 0;
  num = this->file->areas.num;
  v76 = num;
  v45 = *(_DWORD *)(v42 + 16);
  if ( num > 0 )
  {
    while ( 1 )
    {
      list = this->file->obstaclePVS.list;
      v47 = list[v45++];
      if ( (v47 & 0x80) == 0 )
        break;
      v48 = v47 & 0x3F;
      if ( (v47 & 0x40) != 0 )
      {
        v49 = list[v45++];
        v48 |= __ROL4__(v49, 6);
      }
      v43 += v48 + 1;
LABEL_34:
      if ( v43 >= num )
        goto LABEL_35;
    }
    v50 = 0;
    v51 = 1;
    v52 = v43;
    while ( v43 < num )
    {
      ++v52;
      this->obstaclePVS[v43 >> 3] |= ((v47 >> v50) & 1) << (v43 & 7);
      ++v43;
      if ( (v51 & v47) != 0 )
      {
        v53 = this->areaClipModels[v52 - 1];
        if ( v53 != nullptr )
        {
          v54 = &clipModels[v41 - 1];
          do
          {
            if ( v41 >= v38 )
              break;
            prevArea = v53->prevArea;
            v56 = 0;
            if ( v53->prevArea != nullptr )
            {
              while ( 1 )
              {
                v57 = prevArea->areaNum;
                if ( v57 < v53->areaNum && ((1 << (v57 & 7)) & this->obstaclePVS[v57 >> 3]) != 0 )
                  break;
                prevArea = prevArea->prevArea;
                if ( prevArea == nullptr )
                  goto LABEL_18;
              }
              v56 = 1;
            }
LABEL_18:
            for ( i = v53->nextArea; i != nullptr; i = i->nextArea )
              ;
            if ( v56 == 0 )
            {
              ++v41;
              *++v54 = v53->clipModel;
            }
            v53 = v53->nextClip;
          }
          while ( v53 != nullptr );
        }
        v59 = this->GetArea(this, a2: v43 - 1);
        v60 = -1;
        v61 = 0;
        if ( v59->numEdges > 0 )
        {
          v62 = v39 - 1;
          v63 = &vertices[v39];
          v64 = &edges[v40 - 1].verts[1];
          do
          {
            if ( v40 >= v77 || v39 >= v78 - 1 )
              break;
            file = this->file;
            v66 = file->edgeIndex.list[v59->firstEdge + v61];
            v67 = (unsigned int)&file->edges.list[abs32(v66)];
            if ( (*(_DWORD *)(v67 + 8) & edgeFlags) != 0 )
            {
              v68 = *(_DWORD *)(((v66 >> 29) & 4) + v67);
              v69 = *(_DWORD *)(((~v66 >> 29) & 4) + v67);
              if ( v60 == -1 )
              {
                LOWORD(v60) = v39++;
                p_x = &file->vertices.list[v68].x;
                ++v62;
                v63->position.x = *p_x;
                v63->position.y = p_x[1];
                v63->position.z = p_x[2];
                ++v63;
              }
              ++v62;
              ++v39;
              v71 = &this->file->vertices.list[v69];
              ++v40;
              v63->position.x = v71->x;
              v63->position.y = v71->y;
              v63->position.z = v71->z;
              ++v63;
              v72 = *(_DWORD *)(v67 + 8);
              v64[7] = v60;
              v60 = v62;
              *(_DWORD *)(v64 + 5) = v72;
              *(_DWORD *)(v64 + 9) = v68;
              *(_DWORD *)(v64 + 11) = v69;
              v64 += 8;
              *v64 = v62;
            }
            else
            {
              v60 = -1;
            }
            ++v61;
          }
          while ( v61 < v59->numEdges );
        }
      }
      ++v50;
      v38 = v75;
      num = v76;
      v51 = __ROL4__(v51, 1);
      if ( v50 >= 7 )
        goto LABEL_34;
    }
LABEL_35:
    v34 = areaNum;
    v31 = a28;
    v32 = maxEdges;
    v37 = maxVertices;
  }
  *v37 = v39;
  *v32 = v40;
  *v31 = v41;
  this->obstaclePVSAreaNum = v34;
  if ( a30 != nullptr )
  {
    v73 = 0;
    if ( *a30 > 0 )
    {
      for ( j = a30 + 7; ((1 << (*(_BYTE *)j & 7)) & this->obstaclePVS[*j >> 3]) != 0; j += 7 )
      {
        if ( ++v73 >= *a30 )
          return;
      }
      *a30 = v73;
    }
  }
}


// ========================================================================
// ?DecompressObstaclePVS@idAAS2Local@@ABAXHPAEH@Z
// EA  : 0x826B5378
// RVA : 0x006B5378
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

void __fastcall idAAS2Local::DecompressObstaclePVS(
        idAAS2Local *this,
        const int areaNum,
        unsigned __int8 *pvs,
        size_t pvsSize)
{
  int v7; // r28
  int v8; // r7
  int v9; // r11
  int num; // r6
  unsigned __int8 *list; // r9
  int v12; // r8
  int v13; // r10
  int v14; // r9
  int v15; // r10
  int v16; // r5

  v7 = ((int (__fastcall *)(idAAS2Local *))this->GetArea)(a1: this);
  memset(Dst: pvs, Val: 0, Size: pvsSize);
  v8 = *(_DWORD *)(v7 + 16);
  v9 = 0;
  num = this->file->areas.num;
  if ( num > 0 )
  {
    while ( 1 )
    {
      list = this->file->obstaclePVS.list;
      v12 = list[v8++];
      if ( (v12 & 0x80) == 0 )
        break;
      v13 = v12 & 0x3F;
      if ( (v12 & 0x40) != 0 )
      {
        v14 = list[v8++];
        v13 |= __ROL4__(v14, 6);
      }
      v9 += v13 + 1;
LABEL_9:
      if ( v9 >= num )
        return;
    }
    v15 = 0;
    while ( v9 < num )
    {
      v16 = (v12 >> v15++) & 1;
      pvs[v9 >> 3] |= v16 << (v9 & 7);
      ++v9;
      if ( v15 >= 7 )
        goto LABEL_9;
    }
  }
}


// ========================================================================
// ?GetObstaclePVSObstacles@idAAS2Local@@UBAXHHPAUobstacleVertex_t@@AAHPAUobstacleEdge_t@@1PAPAVidClipModel@@1PAUobstacleRoute_t@@@Z
// EA  : 0x826B5468
// RVA : 0x006B5468
// PDB : w:\tech5\engine\gamelib\aas2\aas2_pvs.cpp
// ========================================================================

void __fastcall idAAS2Local::GetObstaclePVSObstacles(
        idAAS2Local *this,
        int startAreaNum,
        int edgeFlags,
        obstacleVertex_t *vertices,
        int *maxVertices,
        obstacleEdge_t *edges,
        int *maxEdges,
        idClipModel **clipModels,
        int *maxClipModels,
        obstacleRoute_t *route,
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
        _DWORD *a28,
        int a29,
        int *a30)
{
  int v38; // r18
  int v39; // r16
  unsigned __int8 *obstaclePVS; // r5
  int v41; // r27
  int v42; // r26
  const int *v43; // r28
  int v44; // r30
  int *v45; // [sp+8h] [-E8h]
  obstacleRoute_t *v46; // [sp+Ch] [-E4h]
  int v47; // [sp+10h] [-E0h]
  int v48; // [sp+14h] [-DCh]
  int v49; // [sp+18h] [-D8h]
  int v50; // [sp+1Ch] [-D4h]
  int v51; // [sp+20h] [-D0h]
  int v52; // [sp+24h] [-CCh]
  int v53; // [sp+28h] [-C8h]
  int v54; // [sp+2Ch] [-C4h]
  int v55; // [sp+30h] [-C0h]
  int v56; // [sp+34h] [-BCh]
  int v57; // [sp+38h] [-B8h]
  int v58; // [sp+3Ch] [-B4h]
  int v59; // [sp+40h] [-B0h]
  int v60; // [sp+44h] [-ACh]
  int v61; // [sp+48h] [-A8h]
  int v62; // [sp+4Ch] [-A4h]
  int v63; // [sp+50h] [-A0h]
  int v64; // [sp+58h] [-98h]

  if ( a30 != nullptr )
  {
    v38 = 0;
    v39 = a30[7 * *a30];
    if ( *a30 <= 0 )
      goto LABEL_10;
    obstaclePVS = this->obstaclePVS;
    v41 = startAreaNum >> 3;
    v42 = 1 << (startAreaNum & 7);
    v43 = a30 + 7;
    while ( 1 )
    {
      v44 = *v43;
      idAAS2Local::DecompressObstaclePVS(this, areaNum: *v43, pvs: obstaclePVS, pvsSize: this->numObstaclePVSBytes);
      obstaclePVS = this->obstaclePVS;
      if ( (obstaclePVS[v41] & (unsigned __int8)v42) != 0 && ((1 << (v39 & 7)) & obstaclePVS[v39 >> 3]) != 0 )
        break;
      ++v38;
      v43 += 7;
      if ( v38 >= *a30 )
        goto LABEL_10;
    }
    idAAS2Local::GetObstaclePVSObstaclesInternal(
      this,
      areaNum: v44,
      edgeFlags,
      vertices,
      maxVertices,
      edges,
      maxEdges,
      clipModels,
      maxClipModels: v45,
      route: v46,
      a11: v47,
      a12: v48,
      a13: v49,
      a14: v50,
      a15: v51,
      a16: v52,
      a17: v53,
      a18: v54,
      a19: v55,
      a20: v56,
      a21: v57,
      a22: v58,
      a23: v59,
      a24: v60,
      a25: v61,
      a26: v62,
      a27: v63,
      a28,
      a29: v64,
      a30);
    if ( v44 < 0 )
LABEL_10:
      idAAS2Local::GetObstaclePVSObstaclesInternal(
        this,
        areaNum: startAreaNum,
        edgeFlags,
        vertices,
        maxVertices,
        edges,
        maxEdges,
        clipModels,
        maxClipModels: v45,
        route: v46,
        a11: v47,
        a12: v48,
        a13: v49,
        a14: v50,
        a15: v51,
        a16: v52,
        a17: v53,
        a18: v54,
        a19: v55,
        a20: v56,
        a21: v57,
        a22: v58,
        a23: v59,
        a24: v60,
        a25: v61,
        a26: v62,
        a27: v63,
        a28,
        a29: v64,
        a30);
  }
  else
  {
    idAAS2Local::GetObstaclePVSObstaclesInternal(
      this,
      areaNum: startAreaNum,
      edgeFlags,
      vertices,
      maxVertices,
      edges,
      maxEdges,
      clipModels,
      maxClipModels: v45,
      route: v46,
      a11: v47,
      a12: v48,
      a13: v49,
      a14: v50,
      a15: v51,
      a16: v52,
      a17: v53,
      a18: v54,
      a19: v55,
      a20: v56,
      a21: v57,
      a22: v58,
      a23: v59,
      a24: v60,
      a25: v61,
      a26: v62,
      a27: v63,
      a28,
      a29: v64,
      a30: nullptr);
  }
}

