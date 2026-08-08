
// ========================================================================
// ?InitHash@idRawSurface@@QAAXABV?$idList@VidVec3@@$04@@ABV?$idList@VidVec2@@$04@@0@Z
// EA  : 0x82876178
// RVA : 0x00876178
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall idRawSurface::InitHash(
        idRawSurface *this,
        const idList<idVec3,5> *vList,
        const idList<idVec2,5> *tvList,
        const idList<idVec3,5> *morphList)
{
  idList<int,5> *p_vertHash; // r31
  int num; // r30
  int size; // r11
  int v8; // r10
  int v9; // r11

  this->pvList = vList;
  this->ptvList = tvList;
  p_vertHash = &this->vertHash;
  this->pMorphList = morphList;
  num = vList->num;
  if ( num <= this->vertHash.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->vertHash,
                          newsize: vList->num) != 0 )
  {
    size = p_vertHash->size;
    if ( num < size )
      size = num;
    p_vertHash->num = size;
  }
  v8 = 0;
  if ( vList->num > 0 )
  {
    v9 = 0;
    do
    {
      ++v8;
      p_vertHash->list[v9++] = -1;
    }
    while ( v8 < vList->num );
  }
}


// ========================================================================
// ?BuildAveragedSurfaceNormals@@YA_NABV?$idList@VidVec3@@$04@@ABV?$idList@H$04@@AAV1@@Z
// EA  : 0x82876550
// RVA : 0x00876550
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

int __fastcall BuildAveragedSurfaceNormals(
        const idList<idVec3,5> *verts,
        const idList<int,5> *indexes,
        idList<idVec3,5> *averagedSurfaceNormals)
{
  int num; // r31
  int size; // r11
  int v8; // r9
  int v9; // r10
  idVec3 *v10; // r11
  int v11; // r27
  int v12; // r31
  int *list; // r10
  int v14; // r8
  int v15; // r11
  int v16; // r9
  idVec3 *v17; // r11
  idVec3 *v18; // r11
  idVec3 *v19; // r11
  int v20; // r9
  int v21; // r10
  idVec3 *v22; // r11
  double y; // fp11
  double z; // fp8
  double v27; // fp2
  double v28; // fp3
  double v29; // fp2
  idVec3 v31; // [sp+50h] [-50h] BYREF

  num = verts->num;
  if ( num <= averagedSurfaceNormals->size
    || (unsigned __int8)idList<idVec3,59>::Resize(this: averagedSurfaceNormals, newsize: verts->num) != 0 )
  {
    size = averagedSurfaceNormals->size;
    if ( num < size )
      size = num;
    averagedSurfaceNormals->num = size;
  }
  v8 = 0;
  if ( verts->num > 0 )
  {
    v9 = 0;
    do
    {
      ++v8;
      v10 = &averagedSurfaceNormals->list[v9++];
      v10->z = 0.0;
      v10->y = 0.0;
      v10->x = 0.0;
    }
    while ( v8 < verts->num );
  }
  v11 = 0;
  if ( indexes->num > 0 )
  {
    v12 = 0;
    while ( 2 )
    {
      list = indexes->list;
      v14 = 0;
      v15 = v12 * 4;
      do
      {
        v16 = *(int *)((char *)list + v15);
        if ( v16 < 0 || v16 >= verts->num )
          return 0;
        ++v14;
        v15 += 4;
      }
      while ( v14 < 3 );
      idGeometry::TriangleNormal(
        result: &v31,
        a: &verts->list[list[v12]],
        b: &verts->list[list[v12 + 1]],
        c: &verts->list[list[v12 + 2]]);
      v11 += 3;
      v17 = &averagedSurfaceNormals->list[indexes->list[v12]];
      v17->x = v17->x + v31.x;
      v17->y = v17->y + v31.y;
      v17->z = v17->z + v31.z;
      v18 = &averagedSurfaceNormals->list[indexes->list[v12 + 1]];
      v18->x = v18->x + v31.x;
      v18->y = v18->y + v31.y;
      v18->z = v18->z + v31.z;
      v19 = &averagedSurfaceNormals->list[indexes->list[v12 + 2]];
      v12 += 3;
      v19->x = v19->x + v31.x;
      v19->y = v19->y + v31.y;
      v19->z = v19->z + v31.z;
      if ( v11 < indexes->num )
        continue;
      break;
    }
  }
  v20 = 0;
  if ( averagedSurfaceNormals->num > 0 )
  {
    v21 = 0;
    do
    {
      ++v20;
      v22 = &averagedSurfaceNormals->list[v21++];
      y = v22->y;
      z = v22->z;
      _FP5 = (float)((float)((float)(v22->z * v22->z) + (float)((float)(v22->x * v22->x) + (float)(v22->y * v22->y)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f3, f5, f6, f13 }
      v27 = __frsqrte(_FP3);
      v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                          * (float)((float)((float)(v22->z * v22->z) + (float)((float)(v22->x * v22->x) + (float)(v22->y * v22->y)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v27)
                                                                          - (float)1.5)
                                                          * (float)v27)
                                                  * (float)((float)((float)(v22->z * v22->z)
                                                                  + (float)((float)(v22->x * v22->x)
                                                                          + (float)(v22->y * v22->y)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v27
                                                                                  * (float)((float)((float)(v22->z * v22->z)
                                                                                                  + (float)((float)(v22->x * v22->x) + (float)(v22->y * v22->y)))
                                                                                          * (float)0.5))
                                                                          * (float)v27)
                                                                  - (float)1.5)
                                                  * (float)v27))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v27
                                                          * (float)((float)((float)(v22->z * v22->z)
                                                                          + (float)((float)(v22->x * v22->x)
                                                                                  + (float)(v22->y * v22->y)))
                                                                  * (float)0.5))
                                                  * (float)v27)
                                          - (float)1.5)
                          * (float)v27));
      v29 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                                  * (float)((float)((float)(v22->z * v22->z) + (float)((float)(v22->x * v22->x) + (float)(v22->y * v22->y))) * (float)0.5))
                                                                                          * (float)v27)
                                                                                  - (float)1.5)
                                                                  * (float)v27)
                                                          * (float)((float)((float)(v22->z * v22->z)
                                                                          + (float)((float)(v22->x * v22->x)
                                                                                  + (float)(v22->y * v22->y)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v27
                                                                                          * (float)((float)((float)(v22->z * v22->z) + (float)((float)(v22->x * v22->x) + (float)(v22->y * v22->y)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v27)
                                                                          - (float)1.5)
                                                          * (float)v27))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v27
                                                                  * (float)((float)((float)(v22->z * v22->z)
                                                                                  + (float)((float)(v22->x * v22->x)
                                                                                          + (float)(v22->y * v22->y)))
                                                                          * (float)0.5))
                                                          * (float)v27)
                                                  - (float)1.5)
                                  * (float)v27))
                  * (float)((float)((float)(v22->z * v22->z)
                                  + (float)((float)(v22->x * v22->x) + (float)(v22->y * v22->y)))
                          * (float)0.5));
      v22->x = v22->x * (float)((float)-(float)((float)((float)v29 * (float)v28) - (float)1.5) * (float)v28);
      v22->y = (float)y * (float)((float)-(float)((float)((float)v29 * (float)v28) - (float)1.5) * (float)v28);
      v22->z = (float)z * (float)((float)-(float)((float)((float)v29 * (float)v28) - (float)1.5) * (float)v28);
    }
    while ( v20 < averagedSurfaceNormals->num );
  }
  return 1;
}


// ========================================================================
// ?GenerateNormals@idRawSurface@@QAAXXZ
// EA  : 0x82876850
// RVA : 0x00876850
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall idRawSurface::GenerateNormals(idRawSurface *this)
{
  int num; // r28
  int size; // r11
  idVehicleState **list; // r26
  int v5; // ctr
  int v6; // r11
  int v7; // r9
  idVec3 *v8; // r4
  int v9; // r8
  matchVert_t *v10; // r11
  float *p_x; // r10
  idList<idVehicleState *,5> v12; // [sp+60h] [-60h] BYREF
  idList<idVec3,5> v13; // [sp+70h] [-50h] BYREF

  memset(&v12, 0, 14);
  *(_WORD *)&v12.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v12);
  num = this->indexes.num;
  size = v12.size;
  if ( num > v12.size )
  {
    if ( (unsigned __int8)idList<idNavSpline *,5>::Resize(
                            this: (idList<idSpawnArea::GeneratedPosition *,5> *)&v12,
                            newsize: this->indexes.num) == 0 )
    {
      num = v12.num;
      goto LABEL_8;
    }
    size = v12.size;
  }
  if ( num >= size )
  {
    num = size;
    v12.num = size;
  }
  else
  {
    v12.num = num;
  }
LABEL_8:
  list = v12.list;
  if ( num > 0 )
  {
    v5 = num;
    v6 = 0;
    do
    {
      list[v6] = (idVehicleState *)this->verts.list[this->indexes.list[v6]].v;
      ++v6;
      --v5;
    }
    while ( v5 != 0 );
  }
  *(_WORD *)&v13.memTag = 1280;
  memset(&v13, 0, 14);
  if ( (unsigned __int8)BuildAveragedSurfaceNormals(
                          verts: this->pvList,
                          indexes: (const idList<int,5> *)&v12,
                          averagedSurfaceNormals: &v13) == 0 )
    idLib::Error(fmt: "BuildAveragedSurfaceNormals failed");
  v7 = 0;
  v8 = v13.list;
  if ( this->verts.num > 0 )
  {
    v9 = 0;
    do
    {
      ++v7;
      v10 = &this->verts.list[v9++];
      p_x = &v8[v10->v].x;
      v10->normal.x = *p_x;
      v10->normal.y = p_x[1];
      v10->normal.z = p_x[2];
    }
    while ( v7 < this->verts.num );
  }
  if ( (v13.listStatic == 0 || v13.listStatic == 2) && v8 != nullptr )
    idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
  if ( (v12.listStatic == 0 || v12.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// $LN89_0
// EA  : 0x82876A1C
// RVA : 0x00876A1C
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _LN89_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$223493_0
// EA  : 0x82876A44
// RVA : 0x00876A44
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_223493_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 112));
}


// ========================================================================
// ?InitIndex@idRawSurface@@QAAXH@Z
// EA  : 0x82876E50
// RVA : 0x00876E50
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall idRawSurface::InitIndex(idRawSurface *this, int maxIndexes)
{
  idList<int,5> *p_indexes; // r3
  int size; // r11

  size = this->indexes.size;
  p_indexes = &this->indexes;
  if ( maxIndexes > size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)p_indexes, newsize: maxIndexes);
  if ( maxIndexes > this->verts.size )
    idList<matchVert_t,5>::Resize(this: &this->verts, newsize: maxIndexes);
}


// ========================================================================
// ?DuplicateMirroredVertexes@idRawSurface@@QAAXXZ
// EA  : 0x82876EB8
// RVA : 0x00876EB8
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall idRawSurface::DuplicateMirroredVertexes(idRawSurface *this)
{
  const idList<idVec2,5> *ptvList; // r11
  tangentVert_t *buffer; // r25
  signed int v4; // r29
  char *v5; // r24
  signed int v6; // r4
  int v7; // r9
  matchVert_t *list; // r10
  int *v9; // r6
  int tv; // r28
  float *p_x; // r11
  int v12; // r3
  int v13; // r10
  int v14; // r11
  int v15; // r6
  tangentVert_t *v16; // r3
  int num; // r26
  int v18; // r27
  int *p_negativeRemap; // r29
  int v20; // r8
  int v21; // r11
  const idList<idVec2,5> *v22; // [sp+50h] [-B0h]
  idTempArray<tangentVert_t> v23; // [sp+58h] [-A8h] BYREF
  idTempArray<char> v24; // [sp+60h] [-A0h] BYREF
  matchVert_t v25[2]; // [sp+70h] [-90h] BYREF

  ptvList = this->ptvList;
  if ( ptvList != nullptr && ptvList->num != 0 )
  {
    idTempArray<tangentVert_t>::idTempArray<tangentVert_t>(this: &v23, num: this->verts.num);
    buffer = v23.buffer;
    memset(Dst: v23.buffer, Val: 0, Size: 8 * v23.num);
    v4 = this->indexes.num / 3;
    idTempArray<char>::idTempArray<char>(this: &v24, num: v4);
    v5 = v24.buffer;
    v6 = 0;
    if ( v4 > 0 )
    {
      v7 = 0;
      do
      {
        list = this->verts.list;
        v9 = &this->indexes.list[v7];
        v22 = this->ptvList;
        v7 += 3;
        tv = list[v9[1]].tv;
        p_x = &v22->list[list[*v9].tv].x;
        v12 = list[v9[2]].tv;
        v5[v6++] = (float)((float)((float)(v22->list[v12].y - p_x[1]) * (float)(v22->list[tv].x - *p_x))
                         - (float)((float)(v22->list[v12].x - *p_x) * (float)(v22->list[tv].y - p_x[1]))) < 0.0;
      }
      while ( v6 < v4 );
    }
    v13 = 0;
    if ( this->indexes.num > 0 )
    {
      v14 = 0;
      do
      {
        v15 = (unsigned __int8)v5[v13 / 3];
        v13 += 3;
        buffer[this->indexes.list[v14]].polarityUsed[v15] = true;
        buffer[this->indexes.list[v14 + 1]].polarityUsed[v15] = true;
        v16 = &buffer[this->indexes.list[v14 + 2]];
        v14 += 3;
        v16->polarityUsed[v15] = true;
      }
      while ( v13 < this->indexes.num );
    }
    num = this->verts.num;
    if ( num > 0 )
    {
      v18 = 0;
      p_negativeRemap = &buffer->negativeRemap;
      do
      {
        if ( *((_BYTE *)p_negativeRemap - 4) != 0 && *((_BYTE *)p_negativeRemap - 3) != 0 )
        {
          *p_negativeRemap = this->verts.num;
          memcpy(Dst: v25, Src: &this->verts.list[v18], Size: 0x38u);
          idList<matchVert_t,5>::Append(this: &this->verts, obj: v25);
        }
        --num;
        p_negativeRemap += 2;
        ++v18;
      }
      while ( num != 0 );
    }
    v20 = 0;
    if ( this->indexes.num > 0 )
    {
      v21 = 0;
      do
      {
        if ( buffer[this->indexes.list[v21]].negativeRemap != 0 && v5[v20 / 3] != 0 )
          this->indexes.list[v21] = buffer[this->indexes.list[v21]].negativeRemap;
        ++v20;
        ++v21;
      }
      while ( v20 < this->indexes.num );
    }
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$224082
// EA  : 0x82877188
// RVA : 0x00877188
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_224082()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$224083
// EA  : 0x828771B0
// RVA : 0x008771B0
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_224083()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 256 + 96));
}


// ========================================================================
// ?AddVert@idRawSurface@@QAAXHHABVidVec3@@IH@Z
// EA  : 0x828771D8
// RVA : 0x008771D8
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall idRawSurface::AddVert(
        idRawSurface *this,
        int v,
        int tv,
        const idVec3 *normal,
        unsigned int color,
        int morph)
{
  int v6; // r30
  int v8; // r10
  int next; // r11
  matchVert_t *v10; // r9
  matchVert_t *v11; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12
  int v15; // r3
  int *list; // r10
  encounterGroupRole_t v17[4]; // [sp+50h] [-60h] BYREF
  matchVert_t v18; // [sp+60h] [-50h] BYREF

  v6 = v;
  v8 = this->vertHash.list[v];
  next = v8;
  v17[0] = v8;
  if ( v8 == -1 )
  {
LABEL_10:
    x = normal->x;
    v18.v = v;
    y = normal->y;
    v18.tv = tv;
    z = normal->z;
    v18.color = color;
    v18.normal.x = x;
    v18.morph = morph;
    v18.normal.y = y;
    v18.next = v8;
    v18.normal.z = z;
    v15 = idList<matchVert_t,5>::Append(this: &this->verts, obj: &v18);
    list = this->vertHash.list;
    v17[0] = v15;
    list[v6] = v15;
  }
  else
  {
    v10 = this->verts.list;
    while ( 1 )
    {
      v11 = &v10[next];
      if ( v11->v == v
        && v11->tv == tv
        && v11->color == color
        && v11->morph == morph
        && (this->generateNormals
         || (float)((float)(v11->normal.x * normal->x)
                  + (float)((float)(v11->normal.z * normal->z) + (float)(v11->normal.y * normal->y))) > (double)this->normalEpsilon) )
      {
        break;
      }
      next = v11->next;
      v17[0] = next;
      if ( next == -1 )
        goto LABEL_10;
    }
  }
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->indexes, obj: v17);
}


// ========================================================================
// ?DeriveVertexTangents@@YAXABV?$idList@H$04@@ABV?$idList@VidDrawVert@@$04@@AAV?$idList@UvertexTangents_t@@$04@@@Z
// EA  : 0x828774B8
// RVA : 0x008774B8
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall DeriveVertexTangents(
        const idList<int,5> *indexes,
        const idList<idDrawVert,5> *verts,
        idList<vertexTangents_t,5> *vertTangents,
        int a4,
        __int64 a5)
{
  int num; // r23
  int v8; // r24
  int size; // r11
  int v11; // r31
  int v12; // r26
  int v13; // r27
  vertexTangents_t *v14; // r28
  vertexTangents_t *v15; // r11
  float *p_x; // r11
  int v17; // r31
  unsigned int v18; // r28
  float *v19; // r11
  double v20; // fp5
  double v21; // fp4
  float *v22; // r11
  float *v23; // r11
  int v24; // r7
  int i; // r6
  vertexTangents_t *v26; // r10
  float *p_z; // r11
  int v28; // ctr
  double y; // fp11
  double z; // fp8
  double v33; // fp2
  double v34; // fp3
  double v35; // fp2
  double v36; // fp9
  double v37; // fp7
  double v38; // fp2
  double v39; // fp1
  double v40; // fp13
  double v41; // fp10
  double v42; // fp8
  double v43; // fp9
  double v44; // fp5
  double v47; // fp2
  double v48; // fp13
  double v49; // fp1
  double v50; // fp13
  idDrawVert v51; // [sp+50h] [-90h] BYREF
  idVec3 v52; // [sp+70h] [-70h] BYREF
  idVec3 v53; // [sp+7Ch] [-64h] BYREF

  num = verts->num;
  v8 = indexes->num;
  if ( num <= vertTangents->size
    || (unsigned __int8)idList<vertexTangents_t,5>::Resize(this: vertTangents, newsize: verts->num) != 0 )
  {
    size = vertTangents->size;
    if ( num < size )
      size = num;
    vertTangents->num = size;
  }
  if ( num > 0 )
  {
    v11 = 0;
    v12 = 0;
    v13 = num;
    do
    {
      v14 = &vertTangents->list[v11];
      v14->normal = *idDrawVert::GetNormal(this: &v51, result: &verts->list[v12].xyz, a3: (int)vertTangents, a4: a5);
      --v13;
      ++v12;
      v15 = &vertTangents->list[v11];
      v15->tangents[0].z = 0.0;
      v15->tangents[0].y = 0.0;
      v15->tangents[0].x = 0.0;
      p_x = &vertTangents->list[v11].normal.x;
      p_x[8] = 0.0;
      p_x[7] = 0.0;
      ++v11;
      p_x[6] = 0.0;
    }
    while ( v13 != 0 );
  }
  if ( v8 > 0 )
  {
    v17 = 0;
    v18 = (v8 - 1) / 3u + 1;
    do
    {
      idTriangles::TriangleVectors(
        a: &verts->list[indexes->list[v17]],
        b: &verts->list[indexes->list[v17 + 1]],
        c: &verts->list[indexes->list[v17 + 2]],
        normal: (idVec3 *)&v51.st.y,
        tangent: &v52,
        biTangent: &v53);
      --v18;
      v19 = &vertTangents->list[indexes->list[v17]].normal.x;
      v19[3] = v19[3] + v52.x;
      v19[4] = v19[4] + v52.y;
      v19[5] = v19[5] + v52.z;
      v20 = v19[7];
      v21 = v19[8];
      v19[6] = v19[6] + v53.x;
      v19[7] = (float)v20 + v53.y;
      v19[8] = v53.z + (float)v21;
      v22 = &vertTangents->list[indexes->list[v17 + 1]].normal.x;
      v22[3] = v22[3] + v52.x;
      v22[4] = v22[4] + v52.y;
      v22[5] = v22[5] + v52.z;
      v22[6] = v22[6] + v53.x;
      v22[7] = v22[7] + v53.y;
      v22[8] = v53.z + v22[8];
      v23 = &vertTangents->list[indexes->list[v17 + 2]].normal.x;
      v17 += 3;
      v23[3] = v23[3] + v52.x;
      v23[4] = v23[4] + v52.y;
      v23[5] = v23[5] + v52.z;
      v23[6] = v23[6] + v53.x;
      v23[7] = v23[7] + v53.y;
      v23[8] = v53.z + v23[8];
    }
    while ( v18 != 0 );
  }
  if ( num > 0 )
  {
    v24 = 0;
    for ( i = num; i != 0; --i )
    {
      v26 = &vertTangents->list[v24];
      p_z = &v26->normal.z;
      v28 = 2;
      y = v26->normal.y;
      z = v26->normal.z;
      _FP5 = (float)((float)((float)(v26->normal.z * v26->normal.z)
                           + (float)((float)(v26->normal.x * v26->normal.x) + (float)(v26->normal.y * v26->normal.y)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f3, f5, f6, f13 }
      v33 = __frsqrte(_FP3);
      v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                          * (float)((float)((float)(v26->normal.z * v26->normal.z) + (float)((float)(v26->normal.x * v26->normal.x) + (float)(v26->normal.y * v26->normal.y)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v33)
                                                                          - (float)1.5)
                                                          * (float)v33)
                                                  * (float)((float)((float)(v26->normal.z * v26->normal.z)
                                                                  + (float)((float)(v26->normal.x * v26->normal.x)
                                                                          + (float)(v26->normal.y * v26->normal.y)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v33
                                                                                  * (float)((float)((float)(v26->normal.z * v26->normal.z)
                                                                                                  + (float)((float)(v26->normal.x * v26->normal.x) + (float)(v26->normal.y * v26->normal.y)))
                                                                                          * (float)0.5))
                                                                          * (float)v33)
                                                                  - (float)1.5)
                                                  * (float)v33))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v33
                                                          * (float)((float)((float)(v26->normal.z * v26->normal.z)
                                                                          + (float)((float)(v26->normal.x * v26->normal.x)
                                                                                  + (float)(v26->normal.y * v26->normal.y)))
                                                                  * (float)0.5))
                                                  * (float)v33)
                                          - (float)1.5)
                          * (float)v33));
      v35 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                                  * (float)((float)((float)(v26->normal.z * v26->normal.z) + (float)((float)(v26->normal.x * v26->normal.x) + (float)(v26->normal.y * v26->normal.y))) * (float)0.5))
                                                                                          * (float)v33)
                                                                                  - (float)1.5)
                                                                  * (float)v33)
                                                          * (float)((float)((float)(v26->normal.z * v26->normal.z)
                                                                          + (float)((float)(v26->normal.x * v26->normal.x)
                                                                                  + (float)(v26->normal.y * v26->normal.y)))
                                                                  * (float)0.5))
                                                  * (float)((float)-(float)((float)((float)((float)v33
                                                                                          * (float)((float)((float)(v26->normal.z * v26->normal.z) + (float)((float)(v26->normal.x * v26->normal.x) + (float)(v26->normal.y * v26->normal.y)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v33)
                                                                          - (float)1.5)
                                                          * (float)v33))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v33
                                                                  * (float)((float)((float)(v26->normal.z * v26->normal.z)
                                                                                  + (float)((float)(v26->normal.x
                                                                                                  * v26->normal.x)
                                                                                          + (float)(v26->normal.y
                                                                                                  * v26->normal.y)))
                                                                          * (float)0.5))
                                                          * (float)v33)
                                                  - (float)1.5)
                                  * (float)v33))
                  * (float)((float)((float)(v26->normal.z * v26->normal.z)
                                  + (float)((float)(v26->normal.x * v26->normal.x)
                                          + (float)(v26->normal.y * v26->normal.y)))
                          * (float)0.5));
      v26->normal.x = v26->normal.x
                    * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34);
      v26->normal.y = (float)y * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34);
      v26->normal.z = (float)z * (float)((float)-(float)((float)((float)v35 * (float)v34) - (float)1.5) * (float)v34);
      do
      {
        v36 = p_z[1];
        v37 = p_z[3];
        v38 = (float)(v26->normal.z
                    * (float)((float)(v26->normal.z * p_z[3])
                            + (float)((float)(v26->normal.x * p_z[1]) + (float)(v26->normal.y * p_z[2]))));
        v39 = (float)(v26->normal.x
                    * (float)((float)(v26->normal.z * p_z[3])
                            + (float)((float)(v26->normal.x * p_z[1]) + (float)(v26->normal.y * p_z[2]))));
        v40 = (float)(p_z[2]
                    - (float)(v26->normal.y
                            * (float)((float)(v26->normal.z * p_z[3])
                                    + (float)((float)(v26->normal.x * p_z[1]) + (float)(v26->normal.y * p_z[2])))));
        p_z[2] = p_z[2]
               - (float)(v26->normal.y
                       * (float)((float)(v26->normal.z * p_z[3])
                               + (float)((float)(v26->normal.x * p_z[1]) + (float)(v26->normal.y * p_z[2]))));
        p_z[3] = (float)v37 - (float)v38;
        v41 = (float)((float)v36 - (float)v39);
        p_z[1] = (float)v36 - (float)v39;
        v42 = v40;
        v44 = (float)((float)((float)((float)v36 - (float)v39) * (float)((float)v36 - (float)v39))
                    + (float)((float)v40 * (float)v40));
        _FP3 = (float)((float)((float)((float)((float)v37 - (float)v38) * (float)((float)v37 - (float)v38))
                             + (float)((float)((float)((float)v36 - (float)v39) * (float)((float)v36 - (float)v39))
                                     + (float)((float)v40 * (float)v40)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v43 = (float)((float)v37 - (float)v38);
        __asm { fsel      f1, f3, f4, f13 }
        v47 = (float)((float)((float)((float)((float)v37 - (float)v38) * (float)((float)v37 - (float)v38)) + (float)v44)
                    * (float)0.5);
        v48 = __frsqrte(_FP1);
        v49 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v48 * (float)v47)
                                                                                    * (float)v48)
                                                                            - (float)1.5)
                                                            * (float)v48)
                                                    * (float)v47)
                                            * (float)((float)-(float)((float)((float)((float)v48 * (float)v47)
                                                                            * (float)v48)
                                                                    - (float)1.5)
                                                    * (float)v48))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v48 * (float)v47) * (float)v48) - (float)1.5)
                            * (float)v48));
        v50 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v48 * (float)v47)
                                                                                            * (float)v48)
                                                                                    - (float)1.5)
                                                                    * (float)v48)
                                                            * (float)v47)
                                                    * (float)((float)-(float)((float)((float)((float)v48 * (float)v47)
                                                                                    * (float)v48)
                                                                            - (float)1.5)
                                                            * (float)v48))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v48 * (float)v47) * (float)v48) - (float)1.5)
                                    * (float)v48))
                    * (float)v47);
        p_z[1] = (float)v41 * (float)((float)-(float)((float)((float)v50 * (float)v49) - (float)1.5) * (float)v49);
        p_z[2] = (float)v42 * (float)((float)-(float)((float)((float)v50 * (float)v49) - (float)1.5) * (float)v49);
        p_z += 3;
        *p_z = (float)v43 * (float)((float)-(float)((float)((float)v50 * (float)v49) - (float)1.5) * (float)v49);
        --v28;
      }
      while ( v28 != 0 );
      ++v24;
    }
  }
}


// ========================================================================
// ?SplitTrianglesForVertexLimit@@YAXABV?$idList@H$04@@HAAV?$idList@VidSplitResults@@$04@@@Z
// EA  : 0x82877B00
// RVA : 0x00877B00
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall SplitTrianglesForVertexLimit(
        const idList<int,5> *indexes,
        signed int maxVerts,
        idList<idSplitResults,5> *split)
{
  int num; // r10
  int size; // r9
  int v7; // r11
  int v8; // r10
  int v9; // r30
  int v11; // r11
  int v12; // r11
  encounterGroupRole_t v13; // r10
  int v14; // r8
  int *list; // r5
  int v16; // r11
  encounterGroupRole_t *v17; // r9
  int v18; // r23
  __int32 v19; // r22
  unsigned int v20; // r18
  char *v21; // r3
  char *v22; // r26
  char *v23; // r11
  __int32 i; // ctr
  int v25; // r11
  int v26; // r10
  idList<enum encounterGroupRole_t,5> *v27; // r27
  int v28; // r29
  int j; // r28
  encounterGroupRole_t *v30; // r30
  encounterGroupRole_t v31[2]; // [sp+50h] [-A0h] BYREF
  int v32; // [sp+58h] [-98h]
  __int32 v33; // [sp+5Ch] [-94h]
  int v34; // [sp+60h] [-90h]
  int v35; // [sp+64h] [-8Ch]
  int v36; // [sp+68h] [-88h]
  __int16 v37; // [sp+6Ch] [-84h]
  char v38; // [sp+6Eh] [-82h]
  char v39; // [sp+6Fh] [-81h]

  num = indexes->num;
  size = split->size;
  v7 = __ROL4__(num, 1);
  v8 = num / maxVerts;
  v9 = v8 + 1;
  __twllei(maxVerts, 0);
  __twlgei(maxVerts & ~(v7 - 1), 0xFFFFFFFF);
  if ( v8 + 1 <= size || (unsigned __int8)idList<idSplitResults,5>::Resize(this: split, newsize: v8 + 1) != 0 )
  {
    v11 = split->size;
    if ( v9 < v11 )
      v11 = v9;
    split->num = v11;
  }
  if ( split->size < 0 )
    idList<idSplitResults,5>::~idList<idSplitResults,5>(this: split);
  v12 = split->size;
  v31[0] = ROLE_NONE;
  v13 = ROLE_NONE;
  v14 = 0;
  split->num = __CFADD__(-v12, v12 ^ 0x80000000) ? 0 : v12;
  v32 = indexes->num;
  if ( v32 > 0 )
  {
    list = indexes->list;
    v16 = 0;
    do
    {
      v17 = (encounterGroupRole_t *)&list[v16];
      if ( v13 >= list[v16] )
        v17 = v31;
      v13 = *v17;
      ++v14;
      ++v16;
      v31[0] = *v17;
    }
    while ( v14 < v32 );
  }
  v18 = 0;
  if ( v32 > 0 )
  {
    v37 = 0;
    v19 = v13 + 1;
    v39 = 0;
    v38 = 5;
    v33 = v13 + 1;
    v20 = 4 * (v13 + 1);
    v34 = 0;
    v36 = 0;
    v35 = 0;
    do
    {
      v21 = (char *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                      size: v20,
                      tag: TAG_TEMP,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
      v22 = v21;
      v32 = (int)v21;
      if ( v19 != 0 )
      {
        v23 = v21 - 4;
        for ( i = v19; i != 0; --i )
        {
          v23 += 4;
          *(_DWORD *)v23 = -1;
        }
      }
      idList<idSplitResults,5>::PreAllocateWithGranularity(this: split, newSize: split->num + 1);
      v25 = split->num;
      v26 = split->size;
      if ( v25 >= v26 )
      {
        v27 = (idList<enum encounterGroupRole_t,5> *)&split->list[v26 - 1];
      }
      else
      {
        v27 = (idList<enum encounterGroupRole_t,5> *)&split->list[v25];
        split->num = v25 + 1;
      }
      for ( ; v18 < indexes->num; v18 += 3 )
      {
        if ( v27[1].num + 3 > maxVerts )
          break;
        v28 = v18;
        for ( j = 3; j != 0; --j )
        {
          v31[0] = (encounterGroupRole_t)indexes->list[v28];
          v30 = (encounterGroupRole_t *)&v22[4 * v31[0]];
          if ( *v30 == -1 )
          {
            *v30 = (encounterGroupRole_t)v27[1].num;
            idList<idAnimWebBlendTree *,5>::Append(this: v27 + 1, obj: v31);
          }
          idList<idAnimWebBlendTree *,5>::Append(this: v27, obj: v30);
          ++v28;
        }
      }
      if ( v22 != nullptr )
        idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
    }
    while ( v18 < indexes->num );
  }
}


// ========================================================================
// __unwind$224916
// EA  : 0x82877D7C
// RVA : 0x00877D7C
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_224916()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$224917
// EA  : 0x82877DA4
// RVA : 0x00877DA4
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_224917()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// ?MakeSurfaces@idRawSurface@@QAAXAAV?$idList@VidStaticModelSurface@@$04@@@Z
// EA  : 0x82877DD8
// RVA : 0x00877DD8
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall idRawSurface::MakeSurfaces(idRawSurface *this, idList<idStaticModelSurface,5> *surfaces)
{
  unsigned __int64 v5; // r16
  __int64 v6; // r8
  int v7; // r6
  int v11; // r4
  float y; // r17
  const idList<idVec2,5> **p_ptvList; // r29
  _DWORD *v22; // r10
  idVec3 *v23; // r8
  const idList<idVec2,5> *v24; // r9
  idVec2 *list; // r8
  int v26; // r6
  int v28; // r10
  __int64 v29; // r8
  int v30; // r5
  int v32; // r26
  vertexTangents_t *v33; // r24
  __int64 v39; // r8
  int v40; // r5
  const idVec3 *Normal; // r3
  char v42; // r11
  skinRemap_t *v43; // r30
  int materialNum; // r10
  float x; // r23
  float v46; // r25
  int *v47; // r27
  int *v48; // r29
  idTriangles *v49; // r3
  idTriangles *v50; // r30
  int v51; // r10
  int v52; // r9
  double v53; // fp13
  double z; // fp12
  double v55; // fp11
  double v56; // fp10
  int v57; // r8
  double v58; // fp9
  float *v59; // r11
  int v72; // r4
  unsigned int vertexMask; // r10
  int v74; // r3
  int v75; // r4
  int v76; // r5
  int v77; // r7
  float *v78; // r11
  matchVert_t *v79; // r8
  _BYTE *v80; // r9
  idVec3 *v81; // r10
  idVec3 *v82; // r10
  const idList<idVec2,5> *ptvList; // r10
  float *p_x; // r10
  int v85; // r7
  int v86; // r9
  int v87; // r8
  idDrawVert *v88; // r11
  int v89; // r6
  int v90; // r10
  int v91; // r4
  int v92; // r9
  int v93; // r10
  int v94; // r11
  unsigned __int16 v95; // r5
  const idVec3 *Tangent; // [sp+50h] [-150h]
  idDrawVert v98; // [sp+60h] [-140h] BYREF
  idList<vertexTangents_t,5> v99; // [sp+80h] [-120h] BYREF
  idStaticModelSurface v100; // [sp+90h] [-110h] BYREF
  idDrawVert v101; // [sp+D8h] [-C8h] BYREF

  _R12 = -176;
  __asm { stvx128   v127, r1, r12 }
  if ( this->indexes.num != 0 )
  {
    if ( this->generateNormals )
      idRawSurface::GenerateNormals(this);
    idRawSurface::DuplicateMirroredVertexes(this);
    LODWORD(v5) = 0;
    memset(&v98.st.y, 0, 14);
    v98.color[3] = 0;
    v98.color[2] = 5;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v98.st.y);
    HIDWORD(v5) = &this->verts.num;
    idList<idDrawVert,44>::SetNum(this: (idList<idDrawVert,44> *)&v98.st.y, newNum: this->verts.num);
    _R23 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    _R19 = -1;
    v11 = 0;
    _R22 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R21 = &_vmx_3f8000003f8000003f8000003f800000;
    y = v98.st.y;
    if ( this->verts.num > 0 )
    {
      __asm { vspltisw128 v62, 0 }
      p_ptvList = &this->ptvList;
      HIDWORD(v6) = 0;
      _R11 = (_BYTE *)(LODWORD(v98.st.y) + 21);
      _R27 = 16;
      _R24 = 4;
      _R25 = 8;
      _R26 = 1;
      do
      {
        __asm { vcmpequw128 v63, v94, v62 }
        _R9 = _R11 - 21;
        v22 = (int *)((char *)&this->verts.list->next + HIDWORD(v6));
        __asm
        {
          vsldoi128 v61, v94, v63, 4
          stvx128   v62, r0, r9
          stvx128   v61, r9, r27
        }
        v23 = &this->pvList->list[v22[1]];
        *(float *)(_R11 - 21) = v23->x;
        *(float *)(_R11 - 17) = v23->y;
        *(float *)(_R11 - 13) = v23->z;
        v24 = *p_ptvList;
        if ( (*p_ptvList)->num > 0 )
        {
          list = v24->list;
          v26 = v22[2];
          *(float *)(_R11 - 9) = v24->list[v26].x;
          *(float *)(_R11 - 5) = list[v26].y;
        }
        _R9 = v22 + 5;
        __asm
        {
          vor128    v60, v94, v62
          lvx128    v63, r0, r21
        }
        ++v11;
        __asm { lvx128    v0, r0, r22 }
        HIDWORD(v6) += 56;
        __asm
        {
          lvx128    v13, r0, r23
          lvlx128   v59, r0, r9
          vrlimi128 v60, v59, 8, 0
          lvlx128   v58, r9, r24
          lvlx128   v57, r9, r25
          vrlimi128 v60, v58, 4, 3
          vrlimi128 v60, v57, 2, 2
          vaddfp128 v12, v92, v63
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v56, v0, 0
          vpkswss128 v55, v88, v56
          vpkshus128 v0, v87, v55
          stvebx    v0, r11, r19
          stvebx    v0, 0, r11
          stvebx    v0, r11, r26
        }
        v28 = v22[4];
        LODWORD(v6) = BYTE1(v28);
        _R11[10] = HIBYTE(v28);
        v7 = BYTE2(v28);
        _R11[9] = BYTE1(v28);
        _R11[8] = BYTE2(v28);
        _R11[7] = v28;
        _R11 += 32;
      }
      while ( v11 < *(_DWORD *)HIDWORD(v5) );
    }
    *(_WORD *)&v99.memTag = 1280;
    memset(&v99, 0, 14);
    DeriveVertexTangents(
      indexes: &this->indexes,
      verts: (const idList<idDrawVert,5> *)&v98.st.y,
      vertTangents: &v99,
      a4: v7,
      a5: v6);
    v32 = *(_DWORD *)v98.normal;
    v33 = v99.list;
    if ( *(int *)v98.normal > 0 )
    {
      __asm { vspltisw128 v127, 0 }
      _R29 = LODWORD(y) + 26;
      _R30 = &v99.list->tangents[0].z;
      _R11 = -8;
      _R10 = -4;
      _R25 = -2;
      do
      {
        __asm
        {
          vmr128    v54, v127
          lvlx128   v53, r30, r11
          lvlx128   v52, r30, r10
        }
        __asm { lvlx128   v51, r0, r30 }
        __asm { lvx128    v63, r0, r21 }
        __asm
        {
          vrlimi128 v54, v53, 8, 0
          lvx128    v13, r0, r23
          lvx128    v0, r0, r22
          vrlimi128 v54, v52, 4, 3
          vrlimi128 v54, v51, 2, 2
          vaddfp128 v12, v86, v63
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v50, v0, 0
          vpkswss128 v49, v82, v50
          vpkshus128 v0, v81, v49
          stvebx    v0, r29, r25
          stvebx    v0, r29, r19
          stvebx    v0, 0, r29
        }
        Tangent = idDrawVert::GetTangent(this: &v101, result: (const idVec3 *)(_R29 - 26), a3: v30, a4: v29);
        Normal = idDrawVert::GetNormal(this: &v98, result: (const idVec3 *)(_R29 - 26), a3: v40, a4: v39);
        v42 = 0;
        if ( (float)((float)(_R30[1] * (float)((float)(Tangent->z * Normal->y) - (float)(Tangent->y * Normal->z)))
                   + (float)((float)(_R30[3] * (float)((float)(Normal->x * Tangent->y) - (float)(Tangent->x * Normal->y)))
                           + (float)(_R30[2] * (float)((float)(Tangent->x * Normal->z) - (float)(Normal->x * Tangent->z))))) >= 0.0 )
          v42 = -1;
        *(_BYTE *)(_R29 + 1) = v42;
        --v32;
        _R30 += 9;
        _R29 += 32;
        _R11 = -8;
        _R10 = -4;
      }
      while ( v32 != 0 );
    }
    if ( (v99.listStatic == 0 || v99.listStatic == 2) && v33 != nullptr )
      idMem::Free(this: &mem, ptr: v33, align: ALIGN_16);
    v100.skinOffsets.x = 0.0;
    v43 = nullptr;
    v100.skinOffsets.y = 0.0;
    v100.extraGLState = v5;
    v100.skinOffsets.z = 0.0;
    v100.geometry = nullptr;
    v100.skinOffsets.w = 0.0;
    v100.geometryIsReference = false;
    v100.referenceMask = 0;
    memset(&v100.binaryModelId, 0, 16);
    v100.skinRemaps.listStatic = 0;
    memset(&v100.skinRemaps, 0, 14);
    v100.skinRemaps.memTag = 5;
    materialNum = this->materialNum;
    v100.material = this->material;
    LODWORD(v98.st.x) = 1280;
    v100.materialNum = materialNum;
    memset(&v98, 0, 12);
    SplitTrianglesForVertexLimit(indexes: &this->indexes, maxVerts: 0x7FFF, split: (idList<idSplitResults,5> *)&v98);
    x = v98.xyz.x;
    if ( SLODWORD(v98.xyz.y) > 0 )
    {
      v46 = v98.xyz.y;
      v47 = (int *)(LODWORD(v98.xyz.x) + 20);
      do
      {
        v48 = v47 - 5;
        v49 = (idTriangles *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x84u,
                               tag: TAG_TRIANGLES,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        if ( v49 != nullptr )
          v50 = idTriangles::idTriangles(this: v49);
        else
          v50 = nullptr;
        v50->bounds.b[0].z = 1900671690;
        v51 = 0;
        v50->bounds.b[0].y = 1900671690;
        v50->bounds.b[0].x = 1900671690;
        v50->bounds.b[1].z = -1.0e30;
        v50->bounds.b[1].x = -1.0e30;
        v50->bounds.b[1].y = -1.0e30;
        if ( *v47 > 0 )
        {
          v52 = 0;
          do
          {
            v53 = v50->bounds.b[0].y;
            ++v51;
            z = v50->bounds.b[0].z;
            v55 = v50->bounds.b[1].x;
            v56 = v50->bounds.b[1].y;
            v57 = *(_DWORD *)(*(v47 - 1) + v52);
            v58 = v50->bounds.b[1].z;
            v52 += 4;
            v59 = (float *)(32 * v57 + LODWORD(y));
            _FP7 = (float)(v50->bounds.b[0].x - *v59);
            __asm { fsel      f6, f7, f8, f0 }
            v50->bounds.b[0].x = _FP6;
            _FP4 = (float)((float)v53 - v59[1]);
            __asm { fsel      f3, f4, f5, f13 }
            v50->bounds.b[0].y = _FP3;
            _FP1 = (float)((float)z - v59[2]);
            __asm { fsel      f0, f1, f2, f12 }
            v50->bounds.b[0].z = _FP0;
            _FP12 = (float)(*v59 - (float)v55);
            __asm { fsel      f11, f12, f13, f11 }
            v50->bounds.b[1].x = _FP11;
            _FP7 = (float)(v59[1] - (float)v56);
            __asm { fsel      f6, f7, f8, f10 }
            v50->bounds.b[1].y = _FP6;
            _FP4 = (float)(v59[2] - (float)v58);
            __asm { fsel      f3, f4, f5, f9 }
            v50->bounds.b[1].z = _FP3;
          }
          while ( v51 < *v47 );
        }
        v72 = *v47;
        v50->numVerts = *v47;
        if ( this->pMorphList->num <= 1 )
        {
          idTriangles::AllocStaticTriSurfVerts(this: v50, numVerts: v72);
          v85 = 0;
          if ( *v47 > 0 )
          {
            v86 = 0;
            v87 = 0;
            do
            {
              ++v85;
              v88 = &v50->verts[v86++];
              v89 = *(_DWORD *)(v87 + v48[4]);
              v87 += 4;
              v90 = 32 * v89 + LODWORD(y);
              v88->xyz.x = *(float *)v90;
              v88->xyz.y = *(float *)(v90 + 4);
              v88->xyz.z = *(float *)(v90 + 8);
              v88->st.x = *(float *)(v90 + 12);
              v88->st.y = *(float *)(v90 + 16);
              v88->normal[0] = *(_BYTE *)(v90 + 20);
              v88->normal[1] = *(_BYTE *)(v90 + 21);
              v88->normal[2] = *(_BYTE *)(v90 + 22);
              v88->normal[3] = *(_BYTE *)(v90 + 23);
              v88->tangent[0] = *(_BYTE *)(v90 + 24);
              v88->tangent[1] = *(_BYTE *)(v90 + 25);
              v88->tangent[2] = *(_BYTE *)(v90 + 26);
              v88->tangent[3] = *(_BYTE *)(v90 + 27);
              v88->color[0] = *(_BYTE *)(v90 + 28);
              v88->color[1] = *(_BYTE *)(v90 + 29);
              v88->color[2] = *(_BYTE *)(v90 + 30);
              v88->color[3] = *(_BYTE *)(v90 + 31);
            }
            while ( v85 < *v47 );
          }
        }
        else
        {
          vertexMask = v50->vertexMask;
          v50->cpuVertexMask |= 0x1000u;
          v50->vertexMask = vertexMask | 0x1000;
          idTriangles::AllocStaticTriSurfVerts(this: v50, numVerts: v72);
          v74 = 0;
          if ( (int)*(_DWORD *)HIDWORD(v5) > 0 )
          {
            v75 = 0;
            v76 = 0;
            do
            {
              v77 = *(_DWORD *)(v76 + v48[4]);
              v78 = (float *)((char *)&v50->verts->xyz.x + v75);
              v79 = &this->verts.list[v77];
              v80 = (_BYTE *)(32 * v77 + LODWORD(y));
              v81 = &this->pvList->list[v79->v];
              *v78 = v81->x;
              v78[1] = v81->y;
              v78[2] = v81->z;
              v82 = &this->pMorphList->list[v79->morph];
              v78[3] = v82->x;
              v78[4] = v82->y;
              v78[5] = v82->z;
              ptvList = this->ptvList;
              if ( ptvList->num > 0 )
              {
                p_x = &ptvList->list[v79->tv].x;
                v78[6] = *p_x;
                v78[7] = p_x[1];
              }
              ++v74;
              v76 += 4;
              v75 += 44;
              *((_BYTE *)v78 + 32) = v80[20];
              *((_BYTE *)v78 + 36) = v80[20];
              *((_BYTE *)v78 + 40) = v80[20];
              *((_BYTE *)v78 + 33) = v80[21];
              *((_BYTE *)v78 + 37) = v80[21];
              *((_BYTE *)v78 + 41) = v80[21];
              *((_BYTE *)v78 + 34) = v80[22];
              *((_BYTE *)v78 + 38) = v80[22];
              *((_BYTE *)v78 + 42) = v80[22];
              *((_BYTE *)v78 + 35) = v80[23];
              *((_BYTE *)v78 + 39) = v80[23];
              *((_BYTE *)v78 + 43) = v80[23];
            }
            while ( v74 < *(_DWORD *)HIDWORD(v5) );
          }
        }
        v91 = v48[1];
        v50->numIndexes = v91;
        idTriangles::AllocStaticTriSurfIndexes(this: v50, numIndexes: v91);
        v92 = 0;
        if ( v48[1] > 0 )
        {
          v93 = 0;
          v94 = 0;
          do
          {
            ++v92;
            v95 = *(_DWORD *)(v94 + *v48);
            v94 += 4;
            v50->indexes[v93++] = v95;
          }
          while ( v92 < v48[1] );
        }
        v100.geometry = v50;
        idList<idStaticModelSurface,5>::Append(this: surfaces, obj: &v100);
        --LODWORD(v46);
        v47 += 8;
      }
      while ( v46 != 0.0 );
      v43 = v100.skinRemaps.list;
    }
    if ( (LOBYTE(v98.st.x) == 0 || LOBYTE(v98.st.x) == 2) && x != 0.0 )
      idListArrayDelete<idSplitResults>(ptr: (char *)LODWORD(x), num: SLODWORD(v98.xyz.z));
    if ( (v100.skinRemaps.listStatic == 0 || v100.skinRemaps.listStatic == 2) && v43 != nullptr )
      idMem::Free(this: &mem, ptr: v43, align: ALIGN_16);
    if ( (v98.color[3] == 0 || v98.color[3] == 2) && y != 0.0 )
      idMem::Free(this: &mem, ptr: (void *)LODWORD(y), align: ALIGN_16);
  }
  _R0 = -176;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// __unwind$225232
// EA  : 0x82878680
// RVA : 0x00878680
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_225232()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 112));
}


// ========================================================================
// __unwind$225233
// EA  : 0x828786A8
// RVA : 0x008786A8
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_225233()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 128));
}


// ========================================================================
// __unwind$225234
// EA  : 0x828786D0
// RVA : 0x008786D0
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_225234()
{
  int v0; // r12

  idStaticModelSurface::~idStaticModelSurface(this: (idStaticModelSurface *)(v0 - 416 + 144));
}


// ========================================================================
// __unwind$225235
// EA  : 0x828786F8
// RVA : 0x008786F8
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_225235()
{
  int v0; // r12

  idList<idSplitResults,5>::~idList<idSplitResults,5>(this: (idList<idSplitResults,5> *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$225236
// EA  : 0x82878720
// RVA : 0x00878720
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_225236()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?EmitRawSurfacesToStaticModel@@YAXAAV?$idList@VidRawSurface@@$04@@AAVidStaticModel@@@Z
// EA  : 0x82878758
// RVA : 0x00878758
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void __fastcall EmitRawSurfacesToStaticModel(idList<idRawSurface,5> *rawSurfaces, idStaticModel *model)
{
  int v4; // r23
  int v5; // r27
  char *list; // r26
  idStaticModelSurface *v7; // r30
  int i; // r28
  int num; // r11
  idList<idStaticModelSurface,5> v10; // [sp+50h] [-70h] BYREF

  v4 = 0;
  if ( rawSurfaces->num > 0 )
  {
    v5 = 0;
    do
    {
      *(_WORD *)&v10.memTag = 1280;
      memset(&v10, 0, 14);
      idRawSurface::MakeSurfaces(this: &rawSurfaces->list[v5], surfaces: &v10);
      list = (char *)v10.list;
      if ( v10.num > 0 )
      {
        v7 = v10.list;
        for ( i = v10.num; i != 0; --i )
        {
          if ( v7->geometry->numVerts != 0 )
            idStaticModel::AddSurface(this: model, surf: v7);
          else
            idLib::Warning(
              fmt: "EmitRawSurfacesToStaticModel: model '%s' has surface '%s' with no triangles",
              model->name.str,
              v7->material->name.str);
          ++v7;
        }
      }
      if ( v10.listStatic == 0 || v10.listStatic == 2 )
      {
        if ( list != nullptr )
          idListArrayDelete<idStaticModelSurface>(ptr: list, num: v10.size);
        v10.list = nullptr;
        v10.size = 0;
      }
      num = rawSurfaces->num;
      ++v4;
      ++v5;
      v10.num = 0;
    }
    while ( v4 < num );
  }
}


// ========================================================================
// __unwind$225995
// EA  : 0x82878864
// RVA : 0x00878864
// PDB : w:\tech5\engine\models\static\staticmodelrawsurface.cpp
// ========================================================================

void _unwind_225995()
{
  int v0; // r12

  idList<idStaticModelSurface,5>::~idList<idStaticModelSurface,5>(this: (idList<idStaticModelSurface,5> *)(v0 - 192 + 80));
}

