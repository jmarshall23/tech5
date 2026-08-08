
// ========================================================================
// ?IsClockwise@idEarClipTriangulate@@CA_NABV?$idList@VidVec2@@$04@@@Z
// EA  : 0x827C27D8
// RVA : 0x007C27D8
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

BOOL __fastcall idEarClipTriangulate::IsClockwise(const idList<idVec2,5> *points)
{
  int num; // r31
  int v2; // r9
  int v3; // r4
  int v4; // r5
  double v5; // fp0
  double v6; // fp13
  double v7; // fp11
  idVec2 *list; // r8
  int v9; // r11
  int v10; // r6
  BOOL result; // r3
  int v12; // r11

  num = points->num;
  v2 = 0;
  v3 = num - 1;
  v4 = num - 1;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  if ( num >= 2 )
  {
    list = points->list;
    v9 = 0;
    v10 = 8 * v3;
    do
    {
      v4 = v2 + 1;
      v2 += 2;
      v5 = (float)((float)((float)(list[v9].y * *(float *)((char *)&list->x + v10))
                         - (float)(*(float *)((char *)&list->y + v10) * list[v9].x))
                 + (float)v5);
      v10 = v9 * 8 + 8;
      v6 = (float)((float)((float)(list[v9 + 1].y * list[v9].x) - (float)(list[v9].y * list[v9 + 1].x)) + (float)v6);
      v9 += 2;
    }
    while ( v2 < v3 );
  }
  if ( v2 < num )
    v7 = (float)((float)(points->list[v2].y * points->list[v4].x) - (float)(points->list[v4].y * points->list[v2].x));
  result = (float)((float)((float)v6 + (float)v5) + (float)v7) < 0.0;
  v12 = 0;
  if ( num >= 4 )
  {
    do
      v12 += 4;
    while ( v12 < num - 3 );
  }
  return result;
}


// ========================================================================
// ?RemapIndices@idEarClipTriangulate@@AAAXXZ
// EA  : 0x827C28E0
// RVA : 0x007C28E0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::RemapIndices(idEarClipTriangulate *this)
{
  int num; // r11
  int v2; // ctr
  __int16 *list; // r8
  int v4; // r11
  __int16 v5; // r9
  int v6; // r10
  int maxIndex; // r10

  num = this->triangles.num;
  this->maxIndex = -1;
  if ( num > 0 )
  {
    v2 = num;
    list = this->triangles.list;
    v4 = 0;
    do
    {
      v5 = list[v4];
      v6 = this->indexMap.hashIndex.hash[v5 & this->indexMap.hashIndex.lookupMask & this->indexMap.hashIndex.hashMask];
      if ( v6 != -1 )
        v5 = this->indexMap.indices.list[v6];
      list[v4] = v5;
      list = this->triangles.list;
      maxIndex = this->maxIndex;
      if ( maxIndex <= list[v4] )
        maxIndex = list[v4];
      this->maxIndex = maxIndex;
      ++v4;
      --v2;
    }
    while ( v2 != 0 );
  }
}


// ========================================================================
// ?RemoveZeroAreas@idEarClipTriangulate@@AAAXXZ
// EA  : 0x827C2970
// RVA : 0x007C2970
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::RemoveZeroAreas(idEarClipTriangulate *this)
{
  int v1; // r30
  idList<short,5> *p_indices; // r6
  int v3; // r31
  int v4; // r5
  idVec2 *v5; // r11
  idVec2 *v6; // r9
  idVec2 *v7; // r10
  int v8; // r11
  int num; // r10
  int v10; // r10
  int v11; // r10
  _WORD *v12; // r9
  int v13; // r11
  int v14; // r10
  int v15; // r10
  int v16; // r10
  _WORD *v17; // r9
  int v18; // r11
  int v19; // r11
  bool v20; // zf
  int v21; // r10
  _WORD *v22; // r9
  char v23; // r30
  int v24; // r4
  int v25; // r31
  int v26; // r7
  int v27; // r10
  int v28; // r11
  int v29; // r11
  int v30; // r11
  int v31; // r5
  int v32; // r7
  char *v33; // r11
  _WORD *v34; // r10
  char *v35; // r11
  int i; // ctr

  v1 = 0;
  if ( this->indices.num > 2 )
  {
    p_indices = &this->indices;
    v3 = 2;
    v4 = 0;
    do
    {
      v5 = &this->positions.list[p_indices->list[v4]];
      v6 = &this->positions.list[p_indices->list[v4 + 1]];
      v7 = &this->positions.list[p_indices->list[v4 + 2]];
      if ( (float)((float)((float)(v7->y - v5->y) * (float)(v6->x - v5->x))
                 - (float)((float)(v6->y - v5->y) * (float)(v7->x - v5->x))) == 0.0 )
      {
        v8 = v3 - 2;
        if ( v3 - 2 >= 0 )
        {
          num = this->indices.num;
          if ( v8 < num )
          {
            v10 = num - 1;
            this->indices.num = v10;
            if ( v8 < v10 )
            {
              v11 = v4 * 2;
              do
              {
                ++v8;
                v12 = (__int16 *)((char *)p_indices->list + v11);
                v11 += 2;
                *v12 = v12[1];
              }
              while ( v8 < this->indices.num );
            }
          }
        }
        v13 = v3 - 1;
        if ( v3 - 1 >= 0 )
        {
          v14 = this->indices.num;
          if ( v13 < v14 )
          {
            v15 = v14 - 1;
            this->indices.num = v15;
            if ( v13 < v15 )
            {
              v16 = v4 * 2 + 2;
              do
              {
                ++v13;
                v17 = (__int16 *)((char *)p_indices->list + v16);
                v16 += 2;
                *v17 = v17[1];
              }
              while ( v13 < this->indices.num );
            }
          }
        }
        if ( v3 >= 0 )
        {
          v18 = this->indices.num;
          if ( v3 < v18 )
          {
            this->indices.num = v18 - 1;
            v20 = v3 >= v18 - 1;
            v19 = v3;
            if ( !v20 )
            {
              v21 = v4 * 2 + 4;
              do
              {
                ++v19;
                v22 = (__int16 *)((char *)p_indices->list + v21);
                v21 += 2;
                *v22 = v22[1];
              }
              while ( v19 < this->indices.num );
            }
          }
        }
        ++v1;
      }
      else
      {
        v4 += 2;
        v3 += 2;
      }
    }
    while ( v3 < this->indices.num );
    if ( v1 > 0 )
    {
      v23 = 0;
      v24 = 0;
      if ( this->vertices.num > 0 )
      {
        v25 = 0;
        do
        {
          v26 = this->indices.num;
          v27 = 0;
          if ( v26 > 0 )
          {
            v28 = 0;
            while ( p_indices->list[v28] != this->vertices.list[v25].index )
            {
              ++v27;
              ++v28;
              if ( v27 >= v26 )
                goto LABEL_31;
            }
            v23 = 1;
          }
LABEL_31:
          if ( v23 != 0 )
          {
            ++v24;
            ++v25;
          }
          else if ( v24 >= 0 )
          {
            v29 = this->vertices.num;
            if ( v24 < v29 )
            {
              v30 = v29 - 1;
              v31 = v24;
              this->vertices.num = v30;
              if ( v24 < v30 )
              {
                v32 = v25 * 16;
                do
                {
                  v33 = (char *)this->vertices.list + v32;
                  v34 = v33 + 14;
                  v35 = v33 - 2;
                  for ( i = 8; i != 0; --i )
                  {
                    ++v34;
                    v35 += 2;
                    *(_WORD *)v35 = *v34;
                  }
                  ++v31;
                  v32 += 16;
                }
                while ( v31 < this->vertices.num );
              }
            }
          }
        }
        while ( v24 < this->vertices.num );
      }
    }
  }
}


// ========================================================================
// ?RemoveReflex@idEarClipTriangulate@@AAAXH@Z
// EA  : 0x827C2C20
// RVA : 0x007C2C20
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::RemoveReflex(idEarClipTriangulate *this, int index)
{
  idEarClipTriangulate::Vertex_t *list; // r9
  int convex; // r11
  idEarClipTriangulate::Vertex_t *v4; // r9
  int v5; // r11
  idEarClipTriangulate::Vertex_t *v6; // r8
  int v7; // r11
  idEarClipTriangulate::Vertex_t *v8; // r9
  idEarClipTriangulate::Vertex_t::<unnamed_type_prevShared> v9; // r7
  int v10; // r4

  if ( index == this->headReflex )
  {
    list = this->vertices.list;
    convex = list[index].nextShared.convex;
    this->headReflex = convex;
    if ( convex != -1 )
      list[convex].prevShared.convex = -1;
    this->vertices.list[index].nextShared.convex = -1;
  }
  else if ( index == this->tailReflex )
  {
    v4 = this->vertices.list;
    v5 = v4[index].prevShared.convex;
    this->tailReflex = v5;
    if ( v5 != -1 )
      v4[v5].nextShared.convex = -1;
    this->vertices.list[index].prevShared.convex = -1;
  }
  else
  {
    v6 = this->vertices.list;
    v7 = index;
    v8 = &v6[index];
    v9.convex = (__int16)v8->prevShared;
    v10 = v8->nextShared.convex;
    v6[v9.convex].nextShared.convex = v10;
    this->vertices.list[v10].prevShared = v9;
    this->vertices.list[v7].nextShared.convex = -1;
    this->vertices.list[v7].prevShared.convex = -1;
  }
}


// ========================================================================
// ?LineTest@idEarClipTriangulate@@CAHABVidVec2@@00@Z
// EA  : 0x827C2D08
// RVA : 0x007C2D08
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

int __fastcall idEarClipTriangulate::LineTest(const idVec2 *vT, const idVec2 *v0, const idVec2 *v1)
{
  double v3; // fp0
  int result; // r3

  v3 = (float)((float)((float)(v1->y - v0->y) * (float)(vT->x - v0->x))
             - (float)((float)(vT->y - v0->y) * (float)(v1->x - v0->x)));
  if ( v3 > 0.0 )
    return 1;
  result = -1;
  if ( v3 >= 0.0 )
    return 0;
  return result;
}


// ========================================================================
// ?TriangleQuery@idEarClipTriangulate@@ABAHABVidVec2@@000@Z
// EA  : 0x827C2D68
// RVA : 0x007C2D68
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

int __fastcall idEarClipTriangulate::TriangleQuery(
        idEarClipTriangulate *this,
        const idVec2 *vT,
        const idVec2 *v0,
        const idVec2 *v1,
        const idVec2 *v2)
{
  double v5; // fp13
  int result; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r3
  bool v10; // zf

  if ( (float)((float)((float)(v2->y - v1->y) * (float)(vT->x - v1->x))
             - (float)((float)(vT->y - v1->y) * (float)(v2->x - v1->x))) > 0.0 )
    return 1;
  v5 = (float)((float)((float)(v2->y - v0->y) * (float)(vT->x - v0->x))
             - (float)((float)(vT->y - v0->y) * (float)(v2->x - v0->x)));
  if ( v5 <= 0.0 && v5 < 0.0 )
    return 1;
  v9 = idEarClipTriangulate::LineTest(vT, v0, v1);
  if ( v9 > 0 )
    return 1;
  if ( v8 == 0 )
    return 0;
  if ( v7 == 0 )
    return 0;
  v10 = v9 != 0;
  result = -1;
  if ( !v10 )
    return 0;
  return result;
}


// ========================================================================
// ?UpdateEar@idEarClipTriangulate@@AAA_NH@Z
// EA  : 0x827C2F80
// RVA : 0x007C2F80
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

int __fastcall idEarClipTriangulate::UpdateEar(idEarClipTriangulate *this, int vertexIndex)
{
  __int16 *p_index; // r27
  int v6; // r26
  idEarClipTriangulate::Vertex_t *list; // r8
  int v8; // r25
  int v9; // r30
  __int16 v10; // r24
  __int16 index; // r11
  __int16 v12; // r10
  int v13; // r29
  int headReflex; // r11
  int v15; // r28
  double v16; // fp2
  idEarClipTriangulate::Vertex_t *v17; // r8
  idVec2 *v18; // r5
  idVec2 *v19; // r7
  idVec2 *v20; // r6
  idVec2 *v21; // r4
  bool v22; // r11

  p_index = &this->vertices.list[vertexIndex].index;
  if ( this->headReflex == -1 )
  {
    p_index[7] |= 0x4000u;
    return 1;
  }
  v6 = p_index[1];
  list = this->vertices.list;
  v8 = p_index[2];
  v9 = *p_index;
  v10 = p_index[7] | 0x4000;
  index = list[v6].index;
  v12 = list[v8].index;
  p_index[7] = v10;
  v13 = index;
  headReflex = this->headReflex;
  v15 = v12;
  if ( headReflex == -1 )
    return (p_index[7] & 0x4000) != 0;
  v16 = 0.00000011920929;
  while ( 1 )
  {
    if ( headReflex == v6 || headReflex == vertexIndex || headReflex == v8 )
    {
      headReflex = this->vertices.list[headReflex].nextShared.convex;
      goto LABEL_20;
    }
    v17 = &this->vertices.list[headReflex];
    v18 = &this->positions.list[v13];
    v19 = &this->positions.list[v15];
    v20 = &this->positions.list[v9];
    v21 = &this->positions.list[v17->index];
    v22 = false;
    if ( __fabs((float)(v21->x - v18->x)) <= v16 )
      v22 = __fabs((float)(v21->y - v18->y)) <= v16;
    if ( !v22 )
    {
      if ( __fabs((float)(v21->x - v20->x)) <= v16 )
        v22 = __fabs((float)(v21->y - v20->y)) <= v16;
      if ( !v22 )
      {
        if ( __fabs((float)(v21->x - v19->x)) <= v16 )
          v22 = __fabs((float)(v21->y - v19->y)) <= v16;
        if ( !v22 && idEarClipTriangulate::TriangleQuery(this, vT: v21, v0: v18, v1: v20, v2: v19) <= 0 )
          break;
      }
    }
    headReflex = v17->nextShared.convex;
LABEL_20:
    if ( headReflex == -1 )
      return (p_index[7] & 0x4000) != 0;
  }
  p_index[7] = v10 & 0xBFFF;
  return 0;
}


// ========================================================================
// ??0idEarClipTriangulate@@QAA@XZ
// EA  : 0x827C3258
// RVA : 0x007C3258
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

idEarClipTriangulate *__fastcall idEarClipTriangulate::idEarClipTriangulate(idEarClipTriangulate *this)
{
  this->positions.list = nullptr;
  this->positions.granularity = 0;
  this->positions.memTag = 5;
  this->positions.listStatic = 0;
  this->positions.size = 0;
  this->positions.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->vertices.list = nullptr;
  this->vertices.granularity = 0;
  this->vertices.memTag = 5;
  this->vertices.listStatic = 0;
  this->vertices.size = 0;
  this->vertices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertices);
  this->contours.list = nullptr;
  this->contours.granularity = 0;
  this->contours.memTag = 5;
  this->contours.listStatic = 0;
  this->contours.size = 0;
  this->contours.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contours);
  this->indices.list = nullptr;
  this->indices.granularity = 0;
  this->indices.memTag = 5;
  this->indices.listStatic = 0;
  this->indices.size = 0;
  this->indices.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indices);
  this->triangles.list = nullptr;
  this->triangles.granularity = 0;
  this->triangles.memTag = 5;
  this->triangles.listStatic = 0;
  this->triangles.size = 0;
  this->triangles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triangles);
  idEarClipTriangulate::IndexMap::IndexMap(this: &this->indexMap);
  return this;
}


// ========================================================================
// __unwind$222742
// EA  : 0x827C3328
// RVA : 0x007C3328
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222742()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$222743
// EA  : 0x827C3350
// RVA : 0x007C3350
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222743()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$222744
// EA  : 0x827C337C
// RVA : 0x007C337C
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222744()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// __unwind$222745
// EA  : 0x827C33A8
// RVA : 0x007C33A8
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222745()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$222746
// EA  : 0x827C33D4
// RVA : 0x007C33D4
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222746()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// ??1idEarClipTriangulate@@QAA@XZ
// EA  : 0x827C3630
// RVA : 0x007C3630
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::~idEarClipTriangulate(idEarClipTriangulate *this)
{
  int v2; // r26
  int v3; // r28
  idEarClipTriangulate::Contour_t *v4; // r10
  idEarClipTriangulate::Contour_t *v5; // r29
  idEarClipTriangulate::Contour_t **list; // r4
  __int16 *v7; // r4
  __int16 *v8; // r4
  __int16 *v9; // r4
  idEarClipTriangulate::Contour_t **v10; // r4
  idEarClipTriangulate::Vertex_t *v11; // r4

  v2 = 0;
  if ( this->contours.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->contours.list[v3];
      if ( v4 != nullptr )
      {
        v5 = this->contours.list[v3];
        if ( v4->indices.listStatic == 0 || v4->indices.listStatic == 2 )
        {
          if ( v4->indices.list != nullptr )
            idMem::Free(this: &mem, ptr: v4->indices.list, align: ALIGN_16);
          v5->indices.list = nullptr;
          v5->indices.size = 0;
        }
        v5->indices.num = 0;
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->contours.num );
  }
  if ( this->contours.listStatic == 0 || this->contours.listStatic == 2 )
  {
    list = this->contours.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->contours.list = nullptr;
    this->contours.size = 0;
  }
  this->contours.num = 0;
  if ( this->indexMap.indices.listStatic == 0 || this->indexMap.indices.listStatic == 2 )
  {
    v7 = this->indexMap.indices.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->indexMap.indices.list = nullptr;
    this->indexMap.indices.size = 0;
  }
  this->indexMap.indices.num = 0;
  idHashIndex::Free(this: &this->indexMap.hashIndex);
  if ( this->triangles.listStatic == 0 || this->triangles.listStatic == 2 )
  {
    v8 = this->triangles.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->triangles.list = nullptr;
    this->triangles.size = 0;
  }
  this->triangles.num = 0;
  if ( this->indices.listStatic == 0 || this->indices.listStatic == 2 )
  {
    v9 = this->indices.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->indices.list = nullptr;
    this->indices.size = 0;
  }
  this->indices.num = 0;
  if ( this->contours.listStatic == 0 || this->contours.listStatic == 2 )
  {
    v10 = this->contours.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->contours.list = nullptr;
    this->contours.size = 0;
  }
  this->contours.num = 0;
  if ( this->vertices.listStatic == 0 || this->vertices.listStatic == 2 )
  {
    v11 = this->vertices.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->vertices.list = nullptr;
    this->vertices.size = 0;
  }
  this->vertices.num = 0;
  if ( this->positions.listStatic == 0 || this->positions.listStatic == 2 )
  {
    if ( this->positions.list != nullptr )
      idMem::Free(this: &mem, ptr: this->positions.list, align: ALIGN_16);
    this->positions.list = nullptr;
    this->positions.size = 0;
  }
  this->positions.num = 0;
}


// ========================================================================
// __unwind$222926
// EA  : 0x827C38A0
// RVA : 0x007C38A0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222926()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$222927
// EA  : 0x827C38C8
// RVA : 0x007C38C8
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222927()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 16));
}


// ========================================================================
// __unwind$222928
// EA  : 0x827C38F4
// RVA : 0x007C38F4
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222928()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 32));
}


// ========================================================================
// __unwind$222929
// EA  : 0x827C3920
// RVA : 0x007C3920
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222929()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 48));
}


// ========================================================================
// __unwind$222930
// EA  : 0x827C394C
// RVA : 0x007C394C
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222930()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 64));
}


// ========================================================================
// __unwind$222931
// EA  : 0x827C3978
// RVA : 0x007C3978
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_222931()
{
  int v0; // r12

  idEarClipTriangulate::IndexMap::~IndexMap(this: (idEarClipTriangulate::IndexMap *)(*(_DWORD *)(v0 - 160 + 180) + 80));
}


// ========================================================================
// __unwind$223041
// EA  : 0x827C39A4
// RVA : 0x007C39A4
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_223041()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: *(idHashIndex **)(v0 - 160 + 80));
}


// ========================================================================
// ?BuildGeometry@idEarClipTriangulate@@QAAXABVidVec3@@AAV?$idList@VidVec2@@$04@@AAV?$idList@G$04@@@Z
// EA  : 0x827C39D0
// RVA : 0x007C39D0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::BuildGeometry(
        idEarClipTriangulate *this,
        idVec3 *normal,
        idList<idVec2,72> *pos,
        idList<unsigned short,5> *idx)
{
  int maxIndex; // r11
  int v8; // r31
  int v9; // r30
  idVec2 *v10; // r11
  double y; // fp13
  int num; // r4
  int v13; // r30
  int v14; // r31
  unsigned __int16 v15[4]; // [sp+50h] [-60h] BYREF
  idVec3 v16; // [sp+58h] [-58h] BYREF
  idVec3 v17[6]; // [sp+68h] [-48h] BYREF

  idVec3::NormalVectors(this: normal, left: v17, down: &v16);
  maxIndex = this->maxIndex;
  v8 = maxIndex + 1;
  if ( maxIndex + 1 > pos->size )
    idList<idVec2,72>::Resize(this: pos, newsize: maxIndex + 1);
  if ( v8 > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &this->positions.list[v9];
      y = v10->y;
      v16.x = v10->x;
      v16.y = y;
      idList<idVec2,72>::Append(this: pos, obj: (const idVec2 *)&v16);
      --v8;
      ++v9;
    }
    while ( v8 != 0 );
  }
  num = this->triangles.num;
  if ( num > idx->size )
    idList<unsigned short,30>::Resize(this: idx, newsize: num);
  v13 = 0;
  if ( this->triangles.num > 0 )
  {
    v14 = 0;
    do
    {
      v15[0] = this->triangles.list[v14];
      idList<unsigned short,72>::Append(this: idx, obj: v15);
      ++v13;
      ++v14;
    }
    while ( v13 < this->triangles.num );
  }
}


// ========================================================================
// ?SetOuterFromPoints@idEarClipTriangulate@@QAAXABV?$idList@VidVec2@@$04@@@Z
// EA  : 0x827C3AC0
// RVA : 0x007C3AC0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::SetOuterFromPoints(idEarClipTriangulate *this, const idList<idVec2,5> *points)
{
  int v4; // r28
  idList<idDeclVehicleUpgrade const *,5> *v5; // r3
  idEarClipTriangulate::Contour_t *v6; // r3
  int num; // r30
  __int16 v8; // r24
  idEarClipTriangulate::Contour_t *v9; // r29
  double x; // fp31
  int v11; // r26
  int v12; // r28
  const idVec2 *v13; // r30
  __int16 v14; // r3
  int i; // r26
  const idVec2 *v16; // r30
  __int16 v17; // r3
  encounterGroupRole_t v18[4]; // [sp+50h] [-60h] BYREF

  v4 = 0;
  if ( this->contours.num <= 0 )
  {
    v18[0] = ROLE_NONE;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->contours, obj: v18);
  }
  if ( *this->contours.list == nullptr )
  {
    v5 = (idList<idDeclVehicleUpgrade const *,5> *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                     size: 0x18u,
                                                     tag: TAG_NEW,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
    v18[0] = (encounterGroupRole_t)v5;
    if ( v5 != nullptr )
      v6 = (idEarClipTriangulate::Contour_t *)idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v5);
    else
      v6 = nullptr;
    *this->contours.list = v6;
  }
  num = points->num;
  v8 = -1;
  v9 = *this->contours.list;
  x = -1.0e30;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v9);
  if ( num > v9->indices.size )
    idList<unsigned short,30>::Resize(this: (idList<unsigned short,5> *)v9, newsize: num);
  if ( idEarClipTriangulate::IsClockwise(points) )
  {
    v11 = num - 1;
    if ( num - 1 >= 0 )
    {
      v12 = v11;
      do
      {
        v13 = &points->list[v12];
        HIWORD(v18[0]) = idList<idVec2,72>::Append((idList<idVec2,72> *)this, obj: v13);
        v14 = idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)v9, obj: (unsigned __int16 *)v18);
        if ( v13->x > x )
        {
          x = v13->x;
          v8 = v14;
        }
        --v11;
        --v12;
      }
      while ( v11 >= 0 );
    }
  }
  else if ( num > 0 )
  {
    for ( i = num; i != 0; --i )
    {
      v16 = &points->list[v4];
      HIWORD(v18[0]) = idList<idVec2,72>::Append((idList<idVec2,72> *)this, obj: v16);
      v17 = idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)v9, obj: (unsigned __int16 *)v18);
      if ( v16->x > x )
      {
        x = v16->x;
        v8 = v17;
      }
      ++v4;
    }
  }
  v9->valueMax = x;
  v9->indexMax = v8;
}


// ========================================================================
// __unwind$223406
// EA  : 0x827C3C5C
// RVA : 0x007C3C5C
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall _unwind_223406(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// ?AddInnerFromPoints@idEarClipTriangulate@@QAAXABV?$idList@VidVec2@@$04@@@Z
// EA  : 0x827C3C90
// RVA : 0x007C3C90
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::AddInnerFromPoints(idEarClipTriangulate *this, const idList<idVec2,5> *points)
{
  int v4; // r28
  idList<idVehicleState *,5> *v5; // r3
  idList<idVehicleState *,5> *v6; // r29
  int num; // r30
  __int16 v8; // r24
  double x; // fp31
  int i; // r25
  const idVec2 *v11; // r30
  __int16 v12; // r3
  int v13; // r25
  int v14; // r28
  const idVec2 *v15; // r30
  __int16 v16; // r3
  int v17; // [sp+50h] [-60h] BYREF
  idList<idVehicleState *,5> *v18; // [sp+54h] [-5Ch] BYREF

  v4 = 0;
  if ( this->contours.num <= 0 )
  {
    v17 = 0;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->contours,
      obj: (const encounterGroupRole_t *)&v17);
  }
  v5 = (idList<idVehicleState *,5> *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x18u,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  v6 = v5;
  v18 = v5;
  if ( v5 != nullptr )
  {
    v5->list = nullptr;
    v5->granularity = 0;
    v5->memTag = 5;
    v5->listStatic = 0;
    v5->size = 0;
    v5->num = 0;
    idList<idThread *,58>::Clear(this: v5);
  }
  else
  {
    v6 = nullptr;
  }
  num = points->num;
  v18 = v6;
  v8 = -1;
  x = -1.0e30;
  idList<idThread *,58>::Clear(this: v6);
  if ( num > v6->size )
    idList<unsigned short,30>::Resize(this: (idList<unsigned short,5> *)v6, newsize: num);
  if ( idEarClipTriangulate::IsClockwise(points) )
  {
    if ( num > 0 )
    {
      for ( i = num; i != 0; --i )
      {
        v11 = &points->list[v4];
        HIWORD(v17) = idList<idVec2,72>::Append((idList<idVec2,72> *)this, obj: v11);
        v12 = idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)v6, obj: (unsigned __int16 *)&v17);
        if ( v11->x > x )
        {
          x = v11->x;
          v8 = v12;
        }
        ++v4;
      }
    }
  }
  else
  {
    v13 = num - 1;
    if ( num - 1 >= 0 )
    {
      v14 = v13;
      do
      {
        v15 = &points->list[v14];
        HIWORD(v17) = idList<idVec2,72>::Append((idList<idVec2,72> *)this, obj: v15);
        v16 = idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)v6, obj: (unsigned __int16 *)&v17);
        if ( v15->x > x )
        {
          x = v15->x;
          v8 = v16;
        }
        --v13;
        --v14;
      }
      while ( v13 >= 0 );
    }
  }
  *(float *)&v6[1].list = x;
  HIWORD(v6[1].num) = v8;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->contours,
    obj: (const encounterGroupRole_t *)&v18);
}


// ========================================================================
// __unwind$223467
// EA  : 0x827C3E3C
// RVA : 0x007C3E3C
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall _unwind_223467(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 84), tag: a2);
}


// ========================================================================
// ?Process@idEarClipTriangulate@@AAAXXZ
// EA  : 0x827C3E68
// RVA : 0x007C3E68
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::Process(idEarClipTriangulate *this)
{
  int num; // r25
  idList<unsigned short,5> *p_triangles; // r29
  int v4; // r4
  __int16 v5; // r30
  int v6; // r30
  int v7; // r28
  int i; // r30
  idEarClipTriangulate::Vertex_t *list; // r10
  idEarClipTriangulate::Vertex_t *v10; // r11
  int prevVertex; // r30
  int nextVertex; // r27
  int v13; // r29
  int v14; // r28
  idEarClipTriangulate::Vertex_t *v15; // r10
  idEarClipTriangulate::Vertex_t *v16; // r11
  __int16 v17; // r4
  int v18; // r3
  idEarClipTriangulate::Vertex_t *v19; // r9
  __int16 *p_index; // r11
  idEarClipTriangulate::Vertex_t *v21; // r10
  __int16 prevEar; // r9
  __int16 nextEar; // r8
  bool v24; // r6
  __int16 index; // r7
  __int16 v26; // r5
  idVec2 *v27; // r9
  idVec2 *v28; // r10
  double v29; // fp0
  unsigned int v30; // r10
  int v31; // r5
  idEarClipTriangulate::Vertex_t *v32; // r11
  idEarClipTriangulate::Vertex_t *v33; // r10
  idEarClipTriangulate::Vertex_t *v34; // r11
  idEarClipTriangulate::Vertex_t *v35; // r9
  __int16 *v36; // r11
  idEarClipTriangulate::Vertex_t *v37; // r10
  __int16 v38; // r9
  __int16 v39; // r8
  bool v40; // r6
  __int16 v41; // r7
  __int16 v42; // r5
  idVec2 *v43; // r9
  idVec2 *v44; // r10
  double v45; // fp0
  unsigned int v46; // r10
  int v47; // r5
  int headEar; // r7
  idEarClipTriangulate::Vertex_t *v49; // r11
  idEarClipTriangulate::Vertex_t *v50; // r10
  idEarClipTriangulate::Vertex_t *v51; // r11
  int v52; // r9
  idEarClipTriangulate::Vertex_t *v53; // r10
  idEarClipTriangulate::Vertex_t *v54; // r11
  __int16 v55; // r8
  int v56; // r5
  idEarClipTriangulate::Vertex_t *v57; // r9
  idVec2 *v58; // r3
  idVec2 *v59; // r31
  idVec2 *v60; // r30
  const char *v61; // r29
  const char *v62; // r31
  const char *v63; // r3
  idEarClipTriangulate::Vertex_t *v64; // r10
  idEarClipTriangulate::Vertex_t *v65; // r11
  __int16 v66; // r9
  int v67; // r6
  idEarClipTriangulate::Vertex_t *v68; // r10
  idEarClipTriangulate::Vertex_t *v69; // r11
  int v70; // r30
  unsigned __int16 v71[4]; // [sp+50h] [-50h] BYREF

  num = this->vertices.num;
  if ( this->headReflex == -1 )
  {
    p_triangles = (idList<unsigned short,5> *)&this->triangles;
    v4 = 3 * (num - 2);
    v5 = *this->indices.list;
    if ( v4 > this->triangles.size )
      idList<unsigned short,30>::Resize(this: (idList<unsigned short,5> *)&this->triangles, newsize: v4);
    if ( num - 1 > 1 )
    {
      v71[0] = v5;
      v6 = 1;
      v7 = num - 2;
      do
      {
        idList<unsigned short,72>::Append(this: p_triangles, obj: v71);
        idList<unsigned short,72>::Append(this: p_triangles, obj: (unsigned __int16 *)&this->indices.list[v6]);
        idList<unsigned short,72>::Append(this: p_triangles, obj: (unsigned __int16 *)&this->indices.list[v6 + 1]);
        --v7;
        ++v6;
      }
      while ( v7 != 0 );
    }
  }
  else
  {
    for ( i = this->headConvex; i != -1; i = this->vertices.list[i].nextShared.convex )
    {
      if ( (unsigned __int8)idEarClipTriangulate::UpdateEar(this, vertexIndex: i) != 0 )
      {
        if ( this->headEar == -1 )
        {
          this->headEar = i;
          this->tailEar = i;
        }
        this->vertices.list[this->tailEar].nextEar = i;
        this->vertices.list[i].prevEar = this->tailEar;
        this->tailEar = i;
      }
    }
    this->vertices.list[this->headEar].prevEar = this->tailEar;
    this->vertices.list[this->tailEar].nextEar = this->headEar;
    while ( 1 )
    {
      list = this->vertices.list;
      v10 = &list[this->headEar];
      prevVertex = v10->prevVertex;
      nextVertex = v10->nextVertex;
      v13 = prevVertex;
      idList<unsigned short,72>::Append(
        this: (idList<unsigned short,5> *)&this->triangles,
        obj: (unsigned __int16 *)&list[prevVertex]);
      idList<unsigned short,72>::Append(
        this: (idList<unsigned short,5> *)&this->triangles,
        obj: (unsigned __int16 *)&this->vertices.list[this->headEar]);
      v14 = nextVertex;
      idList<unsigned short,72>::Append(
        this: (idList<unsigned short,5> *)&this->triangles,
        obj: (unsigned __int16 *)&this->vertices.list[nextVertex]);
      v15 = this->vertices.list;
      --num;
      v16 = &v15[this->headEar];
      v17 = v16->nextVertex;
      v18 = v16->prevVertex;
      v15[v18].nextVertex = v17;
      this->vertices.list[v17].prevVertex = v18;
      if ( num == 3 )
        break;
      v19 = this->vertices.list;
      p_index = &v19[v13].index;
      if ( (*((_WORD *)&v19[v13] + 7) & 0x4000) != 0 )
      {
        if ( (unsigned __int8)idEarClipTriangulate::UpdateEar(this, vertexIndex: prevVertex) == 0 )
        {
          v21 = this->vertices.list;
          prevEar = v21[v13].prevEar;
          nextEar = v21[v13].nextEar;
          v21[prevEar].nextEar = nextEar;
          this->vertices.list[nextEar].prevEar = prevEar;
        }
      }
      else
      {
        v24 = (~*((_WORD *)&v19[v13] + 7) & 0x8000) != 0;
        index = v19[p_index[2]].index;
        v26 = v19[p_index[1]].index;
        v27 = &this->positions.list[*p_index];
        v28 = &this->positions.list[v26];
        v29 = (float)((float)((float)(this->positions.list[index].y - v28->y) * (float)(v27->x - v28->x))
                    - (float)((float)(v27->y - v28->y) * (float)(this->positions.list[index].x - v28->x)));
        if ( v29 <= 0.0 )
        {
          v30 = -1;
          if ( v29 >= 0.0 )
            v30 = 0;
        }
        else
        {
          v30 = 1;
        }
        v31 = HIWORD(v30) & 0x8000 ^ 0x8000;
        p_index[7] = p_index[7] & 0x7FFF | v31;
        if ( (v31 & 0x8000) != 0 )
        {
          if ( v24 )
            idEarClipTriangulate::RemoveReflex(this, index: prevVertex);
          if ( (unsigned __int8)idEarClipTriangulate::UpdateEar(this, vertexIndex: prevVertex) != 0 )
          {
            v32 = this->vertices.list;
            v33 = &v32[v13];
            v34 = &v32[this->headEar];
            v33->prevEar = v34->prevEar;
            v33->nextEar = this->headEar;
            this->vertices.list[v34->prevEar].nextEar = prevVertex;
            v34->prevEar = prevVertex;
          }
        }
      }
      v35 = this->vertices.list;
      v36 = &v35[v14].index;
      if ( (*((_WORD *)&v35[v14] + 7) & 0x4000) != 0 )
      {
        if ( (unsigned __int8)idEarClipTriangulate::UpdateEar(this, vertexIndex: nextVertex) == 0 )
        {
          v37 = this->vertices.list;
          v38 = v37[v14].prevEar;
          v39 = v37[v14].nextEar;
          v37[v38].nextEar = v39;
          this->vertices.list[v39].prevEar = v38;
        }
      }
      else
      {
        v40 = (~*((_WORD *)&v35[v14] + 7) & 0x8000) != 0;
        v41 = v35[v36[2]].index;
        v42 = v35[v36[1]].index;
        v43 = &this->positions.list[*v36];
        v44 = &this->positions.list[v42];
        v45 = (float)((float)((float)(this->positions.list[v41].y - v44->y) * (float)(v43->x - v44->x))
                    - (float)((float)(v43->y - v44->y) * (float)(this->positions.list[v41].x - v44->x)));
        if ( v45 <= 0.0 )
        {
          v46 = -1;
          if ( v45 >= 0.0 )
            v46 = 0;
        }
        else
        {
          v46 = 1;
        }
        v47 = HIWORD(v46) & 0x8000 ^ 0x8000;
        v36[7] = v36[7] & 0x7FFF | v47;
        if ( (v47 & 0x8000) != 0 )
        {
          if ( v40 )
            idEarClipTriangulate::RemoveReflex(this, index: nextVertex);
          if ( (unsigned __int8)idEarClipTriangulate::UpdateEar(this, vertexIndex: nextVertex) != 0 )
          {
            headEar = this->headEar;
            v49 = this->vertices.list;
            v50 = &v49[v14];
            v51 = &v49[headEar];
            v50->prevEar = headEar;
            v50->nextEar = v51->nextEar;
            this->vertices.list[v51->nextEar].prevEar = nextVertex;
            v51->nextEar = nextVertex;
          }
        }
      }
      v52 = this->headEar;
      v53 = this->vertices.list;
      v54 = &v53[v52];
      v55 = v54->prevEar;
      v56 = v54->nextEar;
      v53[v55].nextEar = v56;
      this->vertices.list[v56].prevEar = v55;
      this->headEar = v56;
      if ( v52 == v56 )
      {
        v57 = this->vertices.list;
        v58 = &this->positions.list[v57[v14].index];
        v60 = &this->positions.list[v57[v13].index];
        v59 = &this->positions.list[v57[v56].index];
        v61 = idVec2::ToString(this: v58, precision: 2);
        v62 = idVec2::ToString(this: v59, precision: 2);
        v63 = idVec2::ToString(this: v60, precision: 2);
        sprintf_0(
          string: &byte_8200D768,
          format: "idEarClipTriangulate::Process Circularity error same ear being processed.! prev %s index %s next %s",
          v63,
          v62,
          v61);
        idLib::Warning(fmt: &byte_8200D768);
        return;
      }
    }
    v64 = this->vertices.list;
    v65 = &v64[this->headEar];
    v66 = v65->prevEar;
    v67 = v65->nextEar;
    v64[v66].nextEar = v67;
    this->vertices.list[v67].prevEar = v66;
    v68 = this->vertices.list;
    v69 = &v68[v67];
    this->headEar = v67;
    v70 = v69->nextVertex;
    idList<unsigned short,72>::Append(
      this: (idList<unsigned short,5> *)&this->triangles,
      obj: (unsigned __int16 *)&v68[v69->prevVertex]);
    idList<unsigned short,72>::Append(
      this: (idList<unsigned short,5> *)&this->triangles,
      obj: (unsigned __int16 *)&this->vertices.list[this->headEar]);
    idList<unsigned short,72>::Append(
      this: (idList<unsigned short,5> *)&this->triangles,
      obj: (unsigned __int16 *)&this->vertices.list[v70]);
  }
}


// ========================================================================
// ?SetOuterFromContour@idEarClipTriangulate@@QAAXPBVContour@@@Z
// EA  : 0x827C45D0
// RVA : 0x007C45D0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEarClipTriangulate::SetOuterFromContour(
        idEarClipTriangulate *this,
        const Contour *outer,
        int a3,
        __int64 a4)
{
  ContourEdge_t *i; // r30
  int x; // r8
  idVec2 v8[4]; // [sp+50h] [-2050h] BYREF
  idList<idVec2,72> v9; // [sp+70h] [-2030h] BYREF
  int v10; // [sp+80h] [-2020h] BYREF

  if ( outer->next != nullptr )
    idLib::Printf(fmt: "Multiple outer contours! Need tree view of inner contours beloning to outer etc.\n");
  v9.granularity = 1;
  v9.size = 1024;
  v9.num = 0;
  v9.list = (idVec2 *)&v10;
  v9.memTag = 5;
  v9.listStatic = 1;
  for ( i = outer->edges; i != nullptr; i = i->next )
  {
    x = i->node->pos.x;
    LODWORD(a4) = i->node->pos.y;
    v8[2] = (idVec2)a4;
    v8[1] = *(idVec2 *)((char *)&a4 - 4);
    v8[0].x = (float)*(__int64 *)((char *)&a4 - 4);
    v8[0].y = (float)a4;
    idList<idVec2,72>::Append(this: &v9, obj: v8);
  }
  idEarClipTriangulate::SetOuterFromPoints(this, points: (const idList<idVec2,5> *)&v9);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9);
}


// ========================================================================
// __unwind$224118
// EA  : 0x827C46B0
// RVA : 0x007C46B0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_224118()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8352 + 112));
}


// ========================================================================
// ?SetOuterFromPoints@idEarClipTriangulate@@QAAXABV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827C46E0
// RVA : 0x007C46E0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEarClipTriangulate::SetOuterFromPoints(
        idEarClipTriangulate *this,
        const idList<idVec2i,5> *points,
        int a3,
        __int64 a4)
{
  int num; // r30
  int v5; // r29
  int x; // r8
  idVec2 v9[4]; // [sp+50h] [-2060h] BYREF
  idList<idVec2,72> v10; // [sp+70h] [-2040h] BYREF
  int v11; // [sp+80h] [-2030h] BYREF

  num = points->num;
  v5 = 0;
  *(_QWORD *)&v10.num = 1024;
  v10.list = (idVec2 *)&v11;
  *(_DWORD *)&v10.granularity = 66817;
  if ( num > 0 )
  {
    do
    {
      x = points->list[v5].x;
      LODWORD(a4) = points->list[v5].y;
      v9[2] = (idVec2)a4;
      v9[1] = *(idVec2 *)((char *)&a4 - 4);
      v9[0].x = (float)*(__int64 *)((char *)&a4 - 4);
      v9[0].y = (float)a4;
      idList<idVec2,72>::Append(this: &v10, obj: v9);
      --num;
      ++v5;
    }
    while ( num != 0 );
  }
  idEarClipTriangulate::SetOuterFromPoints(this, points: (const idList<idVec2,5> *)&v10);
  if ( (v10.listStatic == 0 || v10.listStatic == 2) && v10.list != nullptr )
    idMem::Free(this: &mem, ptr: v10.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$224181
// EA  : 0x827C47D4
// RVA : 0x007C47D4
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_224181()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8368 + 112));
}


// ========================================================================
// ?AddInnerFromContour@idEarClipTriangulate@@QAAXPBVContour@@@Z
// EA  : 0x827C4808
// RVA : 0x007C4808
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEarClipTriangulate::AddInnerFromContour(
        idEarClipTriangulate *this,
        const Contour *inner,
        int a3,
        __int64 a4)
{
  const Contour *v4; // r29
  int size; // r10
  idVec2 *list; // r4
  bool v8; // zf
  ContourEdge_t *i; // r30
  int x; // r8
  idVec2 v11[4]; // [sp+50h] [-2070h] BYREF
  idList<idVec2,72> v12; // [sp+70h] [-2050h] BYREF
  _BYTE v13[64]; // [sp+80h] [-2040h] BYREF

  v4 = inner;
  size = 1024;
  *(_QWORD *)&v12.num = 1024;
  v12.list = (idVec2 *)v13;
  *(_DWORD *)&v12.granularity = 66817;
  v8 = inner == nullptr;
  list = (idVec2 *)v13;
  if ( !v8 )
  {
    while ( 1 )
    {
      if ( size >= 0 || v12.listStatic != 0 && v12.listStatic != 2 )
      {
        v12.num = 0;
        if ( size > 0 )
          goto LABEL_12;
      }
      else
      {
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        size = 0;
        v12.list = nullptr;
        v12.size = 0;
      }
      v12.num = size;
LABEL_12:
      for ( i = v4->edges; i != nullptr; i = i->next )
      {
        x = i->node->pos.x;
        LODWORD(a4) = i->node->pos.y;
        v11[2] = (idVec2)a4;
        v11[1] = *(idVec2 *)((char *)&a4 - 4);
        v11[0].x = (float)*(__int64 *)((char *)&a4 - 4);
        v11[0].y = (float)a4;
        idList<idVec2,72>::Append(this: &v12, obj: v11);
      }
      idEarClipTriangulate::AddInnerFromPoints(this, points: (const idList<idVec2,5> *)&v12);
      v4 = v4->next;
      if ( v4 == nullptr )
        break;
      size = v12.size;
      list = v12.list;
    }
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v12);
}


// ========================================================================
// __unwind$224295
// EA  : 0x827C4948
// RVA : 0x007C4948
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_224295()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8384 + 112));
}


// ========================================================================
// ?AddInnerFromPoints@idEarClipTriangulate@@QAAXABV?$idList@VidVec2i@@$04@@@Z
// EA  : 0x827C4978
// RVA : 0x007C4978
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEarClipTriangulate::AddInnerFromPoints(
        idEarClipTriangulate *this,
        const idList<idVec2i,5> *points,
        int a3,
        __int64 a4)
{
  int num; // r30
  int v5; // r29
  int x; // r8
  idVec2 v9[4]; // [sp+50h] [-2060h] BYREF
  idList<idVec2,72> v10; // [sp+70h] [-2040h] BYREF
  int v11; // [sp+80h] [-2030h] BYREF

  num = points->num;
  v5 = 0;
  *(_QWORD *)&v10.num = 1024;
  v10.list = (idVec2 *)&v11;
  *(_DWORD *)&v10.granularity = 66817;
  if ( num > 0 )
  {
    do
    {
      x = points->list[v5].x;
      LODWORD(a4) = points->list[v5].y;
      v9[2] = (idVec2)a4;
      v9[1] = *(idVec2 *)((char *)&a4 - 4);
      v9[0].x = (float)*(__int64 *)((char *)&a4 - 4);
      v9[0].y = (float)a4;
      idList<idVec2,72>::Append(this: &v10, obj: v9);
      --num;
      ++v5;
    }
    while ( num != 0 );
  }
  idEarClipTriangulate::AddInnerFromPoints(this, points: (const idList<idVec2,5> *)&v10);
  if ( (v10.listStatic == 0 || v10.listStatic == 2) && v10.list != nullptr )
    idMem::Free(this: &mem, ptr: v10.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$224624
// EA  : 0x827C4A6C
// RVA : 0x007C4A6C
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_224624()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8368 + 112));
}


// ========================================================================
// ?CreateVertices@idEarClipTriangulate@@AAAXXZ
// EA  : 0x827C4A98
// RVA : 0x007C4A98
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::CreateVertices(idEarClipTriangulate *this)
{
  signed int num; // r28
  idList<idEarClipTriangulate::Vertex_t,5> *p_vertices; // r29
  int v4; // r30
  __int16 v5; // r27
  int v6; // r25
  int v7; // r26
  int v8; // r11
  int size; // r10
  idEarClipTriangulate::Vertex_t *list; // r10
  idEarClipTriangulate::Vertex_t *v11; // r11
  signed int v12; // r8
  __int16 v13; // r4
  int v14; // r7
  __int16 *v15; // r4
  int v16; // r9
  idVec2 *v17; // r9
  double y; // fp0
  double x; // fp13
  idVec2 *v20; // r9
  double v21; // fp11
  double v22; // fp12
  double v23; // fp9
  idVec2 *v24; // r10
  double v25; // fp10
  double v26; // fp0
  unsigned int v27; // r10
  int v28; // r6

  num = this->indices.num;
  p_vertices = &this->vertices;
  if ( num > this->vertices.size )
    idList<idEarClipTriangulate::Vertex_t,5>::Resize(this: &this->vertices, newsize: this->indices.num);
  v4 = 0;
  v5 = num - 1;
  if ( num > 0 )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      idList<idEarClipTriangulate::Vertex_t,5>::PreAllocateWithGranularity(
        this: p_vertices,
        newSize: p_vertices->num + 1);
      v8 = p_vertices->num;
      size = p_vertices->size;
      if ( v8 >= size )
      {
        v11 = &p_vertices->list[size - 1];
      }
      else
      {
        list = p_vertices->list;
        p_vertices->num = v8 + 1;
        v11 = &list[v8];
      }
      v12 = v4 + 1;
      v13 = this->indices.list[v7];
      v11->prevVertex = v5;
      v11->index = v13;
      v14 = (__int16)((v4 + 1) % num);
      v11->nextVertex = v14;
      v16 = v13;
      v15 = this->indices.list;
      v17 = &this->positions.list[v16];
      y = v17->y;
      x = v17->x;
      v20 = &this->positions.list[v15[v5]];
      v21 = v20->y;
      v22 = v20->x;
      v23 = (float)((float)x - v20->x);
      v24 = &this->positions.list[v15[v14]];
      v25 = (float)((float)y - v20->y);
      __twllei(num, 0);
      __twlgei(num & ~(__ROL4__(v4 + 1, 1) - 1), 0xFFFFFFFF);
      v26 = (float)((float)((float)(v24->y - (float)v21) * (float)v23)
                  - (float)((float)v25 * (float)(v24->x - (float)v22)));
      if ( v26 <= 0.0 )
      {
        v27 = -1;
        if ( v26 >= 0.0 )
          v27 = 0;
      }
      else
      {
        v27 = 1;
      }
      v28 = HIWORD(v27) & 0x8000 ^ 0x8000;
      *((_WORD *)v11 + 7) = v28 | *((_WORD *)v11 + 7) & 0x7FFF;
      if ( (v28 & 0x8000) != 0 )
      {
        if ( this->headConvex == -1 )
        {
          this->headConvex = v4;
        }
        else
        {
          p_vertices->list[this->tailConvex].nextShared.convex = v4;
          p_vertices->list[v6].prevShared.convex = this->tailConvex;
        }
        this->tailConvex = v4;
      }
      else
      {
        if ( this->headReflex == -1 )
        {
          this->headReflex = v4;
        }
        else
        {
          p_vertices->list[this->tailReflex].nextShared.convex = v4;
          p_vertices->list[v6].prevShared.convex = this->tailReflex;
        }
        this->tailReflex = v4;
      }
      v5 = v4++;
      ++v7;
      ++v6;
    }
    while ( v12 < num );
  }
}


// ========================================================================
// ?CombineContours@idEarClipTriangulate@@AAAXPBUContour_t@1@ABV?$idList@F$04@@AAV3@@Z
// EA  : 0x827C4CD0
// RVA : 0x007C4CD0
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::CombineContours(
        idEarClipTriangulate *this,
        const idEarClipTriangulate::Contour_t *contour,
        const idList<short,5> *outerIndices,
        idList<unsigned short,5> *combined)
{
  int indexMax; // r21
  idVec2 *list; // r29
  signed int num; // r26
  signed int v8; // r22
  int v9; // r25
  double v11; // fp10
  int v14; // r6
  int v15; // r5
  int v16; // r11
  int v17; // r4
  int v18; // r10
  int v19; // r9
  __int16 *v20; // r7
  int v21; // r8
  signed int v22; // ctr
  int v23; // r11
  float *p_x; // r11
  double v25; // fp12
  double v26; // fp11
  float *v27; // r11
  double v28; // fp13
  double v29; // fp0
  int v30; // r11
  __int16 *v31; // r30
  float *v32; // r11
  float *v33; // r10
  double v34; // fp0
  double v35; // fp13
  int v36; // r27
  int v37; // r18
  signed int v38; // r31
  int v39; // r28
  const idVec2 *v40; // r8
  float *v41; // r11
  double y; // fp0
  float *v43; // r10
  double x; // fp13
  double v45; // fp12
  double v46; // fp11
  double v47; // fp10
  double v48; // fp8
  double v49; // fp7
  float *v50; // r8
  double v51; // fp2
  double v52; // fp1
  int v53; // r30
  int v54; // r31
  signed int i; // r31
  unsigned __int16 *v56; // r4
  idEarClipTriangulate::IndexMap *p_indexMap; // r31
  int v58; // r28
  int v59; // r23
  int v60; // r11
  __int16 v61; // r30
  int lookupMask; // r9
  int hashMask; // r8
  int v64; // r29
  int v65; // r10
  int v66; // r30
  int indexSize; // r11
  idList<unsigned short,5> *p_indices; // r27
  int v69; // r6
  idVec2 *v70; // r30
  int size; // r10
  int v72; // r11
  idVec2 *v73; // r10
  idVec2 *v74; // r11
  int v75; // r11
  unsigned __int16 v76; // r30
  int *hash; // r11
  int v78; // r7
  int v79; // r29
  int v80; // r10
  int v81; // r30
  int v82; // r11
  bool v83; // zf
  int v84; // r6
  idVec2 *v85; // r31
  int v86; // r10
  int v87; // r11
  idVec2 *v88; // r9
  float *v89; // r11
  int v90; // r10
  int v91; // r30
  int v92; // r31
  unsigned __int16 v93[4]; // [sp+50h] [-D0h] BYREF
  idVec2 v94; // [sp+58h] [-C8h]
  idVec2 v95; // [sp+60h] [-C0h] BYREF
  idVec2 v96; // [sp+68h] [-B8h] BYREF
  idVec2 v97; // [sp+70h] [-B0h] BYREF

  indexMax = contour->indexMax;
  list = this->positions.list;
  num = outerIndices->num;
  v8 = contour->indices.num;
  v9 = num - 1;
  v11 = 1.0e30;
  v14 = -1;
  v15 = -1;
  v16 = contour->indices.list[indexMax];
  v17 = -1;
  v18 = num - 1;
  v19 = 0;
  v94 = this->positions.list[v16];
  if ( num > 0 )
  {
    v20 = outerIndices->list;
    v21 = 0;
    v22 = num;
    v23 = 2 * v9;
    while ( 1 )
    {
      p_x = &list[*(__int16 *)((char *)v20 + v23)].x;
      v25 = (float)(p_x[1] - v94.y);
      v26 = (float)(*p_x - v94.x);
      if ( v25 <= 0.0 )
      {
        v27 = &list[v20[v21]].x;
        v28 = (float)(v27[1] - v94.y);
        v29 = (float)(*v27 - v94.x);
        if ( v28 >= 0.0 )
          break;
      }
LABEL_17:
      v18 = v19;
      v23 = v21 * 2;
      ++v19;
      ++v21;
      if ( --v22 == 0 )
        goto LABEL_18;
    }
    v30 = -1;
    if ( v25 >= 0.0 )
    {
      if ( v28 > 0.0 )
      {
        v29 = v26;
        v30 = v18;
        goto LABEL_13;
      }
      if ( v26 < v29 )
      {
        v29 = v26;
        v30 = v18;
        goto LABEL_13;
      }
    }
    else if ( v28 > 0.0 )
    {
      v29 = (float)((float)((float)((float)v25 / (float)((float)v25 - (float)v28)) * (float)((float)v29 - (float)v26))
                  + (float)v26);
LABEL_13:
      if ( v29 >= 0.0 && v29 < v11 )
      {
        v11 = v29;
        v14 = v18;
        v15 = v19;
        v17 = -1;
        if ( v30 != -1 )
          v17 = v30;
      }
      goto LABEL_17;
    }
    v30 = v19;
    goto LABEL_13;
  }
LABEL_18:
  if ( v17 == -1 )
  {
    v31 = outerIndices->list;
    v96.y = v94.y;
    v97.y = v94.y;
    v32 = &list[v31[v14]].x;
    v33 = &list[v31[v15]].x;
    v34 = *v32;
    if ( v34 <= *v33 )
    {
      v34 = *v33;
      v36 = v15;
      v35 = v33[1];
      v96.x = v94.x;
      v97.x = v94.x + (float)v11;
    }
    else
    {
      v35 = v32[1];
      v36 = v14;
      v96.x = v94.x + (float)v11;
      v97.x = v94.x;
    }
    v95.y = v35;
    v95.x = v34;
    v37 = v36;
    v38 = 0;
    if ( num > 0 )
    {
      v39 = 0;
      do
      {
        if ( v38 != v36 )
        {
          v40 = &list[v31[v39]];
          v41 = &list[v31[(v38 + 1) % num]].x;
          y = v40->y;
          v43 = &list[v31[(v9 + v38) % num]].x;
          x = v40->x;
          v45 = *v41;
          v46 = *v43;
          __twllei(num, 0);
          v47 = v43[1];
          v48 = (float)((float)y - v43[1]);
          v49 = v41[1];
          __twllei(num, 0);
          __twlgei(num & ~(__ROL4__(v38 + 1, 1) - 1), 0xFFFFFFFF);
          __twlgei(num & ~(__ROL4__(v9 + v38, 1) - 1), 0xFFFFFFFF);
          if ( (float)((float)((float)((float)v49 - (float)v47) * (float)((float)x - (float)v46))
                     - (float)((float)v48 * (float)((float)v45 - (float)v46))) <= 0.0
            && idEarClipTriangulate::TriangleQuery(this, vT: v40, v0: &v95, v1: &v96, v2: &v97) <= 0
            && ((float)((float)((float)(*v50 - v94.x)
                              / (float)((float)((float)(*v50 - v94.x) * (float)(*v50 - v94.x))
                                      + (float)((float)(v50[1] - v94.y) * (float)(v50[1] - v94.y))))
                      * (float)(*v50 - v94.x)) > v51
             || __fabs((float)((float)((float)((float)(*v50 - v94.x)
                                             / (float)((float)((float)(*v50 - v94.x) * (float)(*v50 - v94.x))
                                                     + (float)((float)(v50[1] - v94.y) * (float)(v50[1] - v94.y))))
                                     * (float)(*v50 - v94.x))
                             - (float)v51)) <= 0.00000011920929
             && (float)((float)((float)(*v50 - v94.x) * (float)(*v50 - v94.x))
                      + (float)((float)(v50[1] - v94.y) * (float)(v50[1] - v94.y))) < v52) )
          {
            v37 = v38;
          }
        }
        ++v38;
        ++v39;
      }
      while ( v38 < num );
    }
  }
  else
  {
    v37 = v17;
  }
  if ( combined->size < 0 )
  {
    if ( combined->listStatic == 0 || combined->listStatic == 2 )
    {
      if ( combined->list != nullptr )
        idMem::Free(this: &mem, ptr: combined->list, align: ALIGN_16);
      combined->list = nullptr;
      combined->size = 0;
    }
    combined->num = 0;
  }
  combined->num = __CFADD__(-combined->size, combined->size ^ 0x80000000) ? 0 : combined->size;
  if ( v37 >= 0 )
  {
    v53 = 0;
    v54 = v37 + 1;
    do
    {
      idList<unsigned short,72>::Append(this: combined, obj: (unsigned __int16 *)&outerIndices->list[v53]);
      --v54;
      ++v53;
    }
    while ( v54 != 0 );
  }
  for ( i = 0; i < v8; ++i )
  {
    v56 = (unsigned __int16 *)&contour->indices.list[(i + indexMax) % v8];
    __twllei(v8, 0);
    __twlgei(v8 & ~(__ROL4__(i + indexMax, 1) - 1), 0xFFFFFFFF);
    idList<unsigned short,72>::Append(this: combined, obj: v56);
  }
  p_indexMap = &this->indexMap;
  v58 = contour->indices.list[indexMax];
  v59 = outerIndices->list[v37];
  v60 = this->indexMap.hashIndex.hash[this->indexMap.hashIndex.lookupMask & this->indexMap.hashIndex.hashMask & v58];
  if ( v60 == -1 )
    v61 = v58;
  else
    v61 = this->indexMap.indices.list[v60];
  v93[0] = this->positions.num;
  idList<unsigned short,72>::Append(this: combined, obj: v93);
  lookupMask = this->indexMap.hashIndex.lookupMask;
  hashMask = this->indexMap.hashIndex.hashMask;
  v93[0] = v61;
  v64 = this->positions.num;
  v65 = p_indexMap->hashIndex.hash[lookupMask & hashMask & v64];
  if ( v65 == -1 )
  {
    v66 = this->indexMap.indices.num;
    indexSize = this->indexMap.hashIndex.indexSize;
    if ( p_indexMap->hashIndex.hash == idHashIndex::INVALID_INDEX )
    {
      if ( v66 >= indexSize )
        indexSize = v66 + 1;
      idHashIndex::Allocate(
        this: &this->indexMap.hashIndex,
        newHashSize: this->indexMap.hashIndex.hashSize,
        newIndexSize: indexSize);
    }
    else if ( v66 >= indexSize )
    {
      idHashIndex::ResizeIndex(this: &this->indexMap.hashIndex, newIndexSize: v66 + 1);
    }
    p_indices = (idList<unsigned short,5> *)&this->indexMap.indices;
    v69 = this->indexMap.hashIndex.hashMask & v64;
    this->indexMap.hashIndex.indexChain[v66] = p_indexMap->hashIndex.hash[v69];
    p_indexMap->hashIndex.hash[v69] = v66;
    idList<unsigned short,72>::Append(this: (idList<unsigned short,5> *)&this->indexMap.indices, obj: v93);
  }
  else
  {
    p_indices = (idList<unsigned short,5> *)&this->indexMap.indices;
    this->indexMap.indices.list[v65] = v61;
  }
  v70 = &this->positions.list[v58];
  idList<idVec2,5>::PreAllocateWithGranularity(this: &this->positions, newSize: this->positions.num + 1);
  size = this->positions.size;
  v72 = this->positions.num;
  if ( v72 >= size )
  {
    v74 = &this->positions.list[size - 1];
  }
  else
  {
    v73 = this->positions.list;
    this->positions.num = v72 + 1;
    v74 = &v73[v72];
  }
  v74->x = v70->x;
  v74->y = v70->y;
  v75 = p_indexMap->hashIndex.hash[this->indexMap.hashIndex.lookupMask & this->indexMap.hashIndex.hashMask & v59];
  if ( v75 == -1 )
    v76 = v59;
  else
    v76 = p_indices->list[v75];
  v93[0] = this->positions.num;
  idList<unsigned short,72>::Append(this: combined, obj: v93);
  hash = p_indexMap->hashIndex.hash;
  v78 = this->indexMap.hashIndex.lookupMask & this->indexMap.hashIndex.hashMask;
  v93[0] = v76;
  v79 = this->positions.num;
  v80 = hash[v78 & v79];
  if ( v80 == -1 )
  {
    v81 = this->indexMap.indices.num;
    v83 = hash != idHashIndex::INVALID_INDEX;
    v82 = this->indexMap.hashIndex.indexSize;
    if ( v83 )
    {
      if ( v81 >= v82 )
        idHashIndex::ResizeIndex(this: &this->indexMap.hashIndex, newIndexSize: v81 + 1);
    }
    else
    {
      if ( v81 >= v82 )
        v82 = v81 + 1;
      idHashIndex::Allocate(
        this: &this->indexMap.hashIndex,
        newHashSize: this->indexMap.hashIndex.hashSize,
        newIndexSize: v82);
    }
    v84 = this->indexMap.hashIndex.hashMask & v79;
    this->indexMap.hashIndex.indexChain[v81] = p_indexMap->hashIndex.hash[v84];
    p_indexMap->hashIndex.hash[v84] = v81;
    idList<unsigned short,72>::Append(this: p_indices, obj: v93);
  }
  else
  {
    p_indices->list[v80] = v76;
  }
  v85 = &this->positions.list[v59];
  idList<idVec2,5>::PreAllocateWithGranularity(this: &this->positions, newSize: this->positions.num + 1);
  v86 = this->positions.size;
  v87 = this->positions.num;
  v88 = this->positions.list;
  if ( v87 >= v86 )
  {
    v89 = &v88[v86 - 1].x;
  }
  else
  {
    this->positions.num = v87 + 1;
    v89 = &v88[v87].x;
  }
  v90 = v37 + 1;
  *v89 = v85->x;
  v89[1] = v85->y;
  if ( v37 + 1 < num )
  {
    v91 = v90;
    v92 = num - v90;
    do
    {
      idList<unsigned short,72>::Append(this: combined, obj: (unsigned __int16 *)&outerIndices->list[v91]);
      --v92;
      ++v91;
    }
    while ( v92 != 0 );
  }
}


// ========================================================================
// ?CreateSimplePolygon@idEarClipTriangulate@@AAAXXZ
// EA  : 0x827C5470
// RVA : 0x007C5470
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::CreateSimplePolygon(idEarClipTriangulate *this)
{
  int num; // r24
  int v3; // r5
  int v4; // r4
  int v5; // r7
  int v6; // r11
  int v7; // r9
  int v8; // r29
  int v9; // r10
  idEarClipTriangulate::Contour_t **list; // r8
  char *v11; // r9
  int v12; // r29
  idEarClipTriangulate::Contour_t **v13; // r9
  idEarClipTriangulate::Contour_t *v14; // r29
  int v15; // r9
  idEarClipTriangulate::Contour_t **v16; // r10
  idEarClipTriangulate::Contour_t *v17; // r29
  int v18; // r10
  int v19; // ctr
  idEarClipTriangulate::Contour_t *v20; // r8
  int v21; // r4
  int v22; // r8
  int v23; // r7
  int v24; // r10
  idEarClipTriangulate::Contour_t **v25; // r9
  int v26; // r11
  idEarClipTriangulate::Contour_t *v27; // r3
  idEarClipTriangulate::Contour_t *v28; // r29
  int v29; // r29
  idList<short,5> *p_indices; // r26
  idList<short,5> *v31; // r29
  int v32; // r27
  int v33; // r28
  const idList<short,5> *v34; // r5
  idList<unsigned short,5> *v35; // r6
  _DWORD *v36; // [sp+50h] [-70h]
  idEarClipTriangulate::Contour_t **v37; // [sp+50h] [-70h]
  idList<unsigned short,5> v38[6]; // [sp+60h] [-60h] BYREF

  num = this->contours.num;
  if ( num == 1 )
    idList<short,5>::Append(this: &this->indices, other: *(const idList<short,5> **)this->contours.list);
  v3 = 1;
  if ( num > 1 )
  {
    v4 = num - 2;
    do
    {
      v5 = num - 1;
      if ( num - 1 > v3 )
      {
        if ( v4 >= 4 )
        {
          v6 = num - 4;
          do
          {
            v7 = v6 * 4 + 12;
            if ( this->contours.list[v6 + 2]->valueMax < (double)this->contours.list[v6 + 3]->valueMax )
            {
              v36 = (idEarClipTriangulate::Contour_t **)((char *)this->contours.list + v7);
              v8 = *(v36 - 1);
              *(v36 - 1) = *v36;
              *v36 = v8;
            }
            v9 = v6 * 4 + 4;
            if ( this->contours.list[v6 + 1]->valueMax < (double)(*(idEarClipTriangulate::Contour_t **)((char *)this->contours.list + v7 - 4))->valueMax )
            {
              list = this->contours.list;
              v11 = (char *)list + v7;
              v12 = *(int *)((char *)list + v9);
              *(idEarClipTriangulate::Contour_t **)((char *)list + v9) = *((idEarClipTriangulate::Contour_t **)v11 - 1);
              *((_DWORD *)v11 - 1) = v12;
            }
            if ( this->contours.list[v6]->valueMax < (double)(*(idEarClipTriangulate::Contour_t **)((char *)this->contours.list
                                                                                                  + v9))->valueMax )
            {
              v13 = this->contours.list;
              v14 = v13[v6];
              v13[v6] = *(idEarClipTriangulate::Contour_t **)((char *)v13 + v9);
              *(idEarClipTriangulate::Contour_t **)((char *)v13 + v9) = v14;
            }
            v15 = v6 * 4 - 4;
            if ( this->contours.list[v6 - 1]->valueMax < (double)this->contours.list[v6]->valueMax )
            {
              v16 = this->contours.list;
              v17 = *(idEarClipTriangulate::Contour_t **)((char *)v16 + v15);
              *(idEarClipTriangulate::Contour_t **)((char *)v16 + v15) = v16[v6];
              v16[v6] = v17;
            }
            v5 -= 4;
            v6 -= 4;
          }
          while ( v5 > v3 + 3 );
        }
        if ( v5 > v3 )
        {
          v18 = v5;
          v19 = v5 - v3;
          do
          {
            if ( this->contours.list[v18 - 1]->valueMax < (double)this->contours.list[v18]->valueMax )
            {
              v37 = &this->contours.list[v18];
              v20 = *(v37 - 1);
              *(v37 - 1) = *v37;
              *v37 = v20;
            }
            --v18;
            --v19;
          }
          while ( v19 != 0 );
        }
      }
      ++v3;
      --v4;
    }
    while ( v3 < num );
  }
  v21 = 2 * num;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  if ( num >= 2 )
  {
    v25 = this->contours.list;
    v26 = 0;
    do
    {
      v27 = v25[v26];
      v24 += 2;
      v28 = v25[v26 + 1];
      v26 += 2;
      v22 += v27->indices.num;
      v23 += v28->indices.num;
    }
    while ( v24 < num - 1 );
  }
  if ( v24 < num )
    v21 += this->contours.list[v24]->indices.num;
  v38[0].listStatic = 0;
  memset(v38, 0, 14);
  v29 = v23 + v22 + v21;
  v38[0].memTag = 5;
  if ( v29 > this->indices.size )
    idList<unsigned short,30>::Resize(this: (idList<unsigned short,5> *)&this->indices, newsize: v23 + v22 + v21);
  if ( v29 > 0 )
    idList<unsigned short,30>::Resize(this: v38, newsize: v29);
  p_indices = &this->indices;
  v31 = (idList<short,5> *)v38;
  if ( num % 2 != 0 )
  {
    v31 = &this->indices;
    p_indices = (idList<short,5> *)v38;
  }
  if ( v31->size < 0 )
  {
    if ( v31->listStatic == 0 || v31->listStatic == 2 )
    {
      if ( v31->list != nullptr )
        idMem::Free(this: &mem, ptr: v31->list, align: ALIGN_16);
      v31->list = nullptr;
      v31->size = 0;
    }
    v31->num = 0;
  }
  v31->num = __CFADD__(-v31->size, v31->size ^ 0x80000000) ? 0 : v31->size;
  idList<short,5>::Append(this: v31, other: *(const idList<short,5> **)this->contours.list);
  if ( num > 1 )
  {
    v32 = 1;
    v33 = num - 1;
    do
    {
      v34 = v31;
      v31 = p_indices;
      v35 = (idList<unsigned short,5> *)p_indices;
      p_indices = (idList<short,5> *)v34;
      idEarClipTriangulate::CombineContours(this, contour: this->contours.list[v32], outerIndices: v34, combined: v35);
      --v33;
      ++v32;
    }
    while ( v33 != 0 );
  }
  if ( (v38[0].listStatic == 0 || v38[0].listStatic == 2) && v38[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v38[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$225573_0
// EA  : 0x827C5800
// RVA : 0x007C5800
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void _unwind_225573_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// ?Triangulate@idEarClipTriangulate@@QAAXXZ
// EA  : 0x827C5828
// RVA : 0x007C5828
// PDB : w:\tech5\engine\models\cuttable\earcliptriangulate.cpp
// ========================================================================

void __fastcall idEarClipTriangulate::Triangulate(idEarClipTriangulate *this)
{
  idEarClipTriangulate *v2; // r3

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->indices);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vertices);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triangles);
  this->headConvex = -1;
  this->tailConvex = -1;
  this->headReflex = -1;
  this->tailReflex = -1;
  this->headEar = -1;
  this->tailEar = -1;
  idEarClipTriangulate::CreateSimplePolygon(this);
  idEarClipTriangulate::CreateVertices(this);
  idEarClipTriangulate::Process(this);
  idEarClipTriangulate::RemapIndices(this);
  idEarClipTriangulate::RemoveZeroAreas(this: v2);
}

