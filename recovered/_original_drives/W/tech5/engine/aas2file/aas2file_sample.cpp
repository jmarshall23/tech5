
// ========================================================================
// ?AreaCenter@idAAS2File@@QBA?AVidVec3@@H@Z
// EA  : 0x825B99A8
// RVA : 0x005B99A8
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::AreaCenter(idAAS2File *this, idVec3 *result, int areaNum)
{
  int v3; // r25
  __int16 v4; // r8
  int v5; // r24
  int v6; // r10
  int v7; // r27
  int v8; // r26
  float z; // r5
  float y; // r9
  float x; // r11
  double v12; // fp12
  double v13; // fp11
  int *v14; // r7
  int v15; // r6
  int v16; // r7
  int v17; // r31
  int v18; // r30
  int v19; // r29
  int *v20; // r7
  int v21; // r6
  int v22; // r31
  int *v23; // r7
  int v24; // r31
  int v25; // r29
  int v26; // r30
  float *v27; // r7
  double v28; // fp7
  float *v29; // r7
  float *v30; // r6
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  double v34; // fp5
  double v35; // fp2
  double v36; // fp4
  double v37; // fp11
  double v38; // fp9
  double v39; // fp6
  unsigned int v40; // r7
  _DWORD *v41; // r8
  int v42; // r30
  float *v43; // r8
  int v44; // r6
  int v45; // r31
  double v46; // fp1
  double v47; // fp13
  double v48; // fp12
  double v49; // fp11
  double v50; // fp8
  double v51; // fp10
  double v52; // fp4
  int v53; // r5
  float v54; // r31
  float v55; // r30
  float v56; // r8
  int v57; // ctr
  double v58; // fp12
  int v59; // r9
  double v60; // fp11
  _DWORD *v61; // r11
  float *v62; // r11
  float *v63; // r9
  double v64; // fp10
  double v65; // fp9
  double v66; // fp12
  double v67; // fp9

  v3 = LODWORD(result[37].y) + 40 * areaNum;
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->trackedMemory = 0.0;
  *(float *)&this->name.str = 0.0;
  v4 = *(_WORD *)(v3 + 6);
  v5 = v4;
  if ( v4 > 0 )
  {
    v6 = 0;
    if ( v4 >= 4 )
    {
      v7 = *(_DWORD *)(v3 + 8);
      v8 = v4 - 3;
      z = result[34].z;
      y = result[33].y;
      x = result[32].x;
      do
      {
        v12 = *(float *)&this->trackedMemory;
        v13 = *(float *)&this->name.str;
        v14 = (int *)(4 * (v7 + v6) + LODWORD(z));
        v15 = *v14;
        v17 = *v14 >> 31;
        v16 = v14[1];
        v18 = v16 >> 31;
        v19 = v16 ^ (v16 >> 31);
        v20 = (int *)(12 * ((v15 ^ v17) - v17) + LODWORD(y));
        v21 = v20[1];
        v22 = *v20;
        v23 = (int *)(12 * (v19 - v18) + LODWORD(y));
        v25 = 12 * v22;
        v24 = v23[1];
        v26 = *v23;
        v27 = (float *)(12 * v21 + LODWORD(x));
        v28 = (float)(*v27 + *(float *)(v25 + LODWORD(x)));
        v30 = (float *)(12 * v26 + LODWORD(x));
        v31 = (float)((float)(*(float *)(v25 + LODWORD(x) + 4) + v27[1]) * (float)0.5);
        v33 = (float)((float)(*(float *)(v25 + LODWORD(x) + 8) + v27[2]) * (float)0.5);
        v29 = (float *)(12 * v24 + LODWORD(x));
        v34 = (float)((float)(*v29 + *v30) * (float)0.5);
        v35 = (float)((float)(v30[1] + v29[1]) * (float)0.5);
        v36 = (float)((float)((float)v28 * (float)0.5) + *(float *)&this->__vftable);
        v32 = (float)(v30[2] + v29[2]);
        *(float *)&this->__vftable = v36;
        *(float *)&this->trackedMemory = (float)v31 + (float)v12;
        v37 = (float)((float)v13 + (float)v33);
        *(float *)&this->name.str = v37;
        *(float *)&this->__vftable = (float)v34 + (float)v36;
        *(float *)&this->trackedMemory = (float)v35 + (float)((float)v31 + (float)v12);
        v38 = (float)((float)v37 + (float)((float)v32 * (float)0.5));
        *(float *)&this->name.str = (float)v37 + (float)((float)v32 * (float)0.5);
        v39 = (float)((float)v35 + (float)((float)v31 + (float)v12));
        v40 = abs32(*(_DWORD *)(4 * (v7 + v6 + 3) + LODWORD(z)));
        v41 = (_DWORD *)(12 * abs32(*(_DWORD *)(4 * (v7 + v6 + 2) + LODWORD(z))) + LODWORD(y));
        v42 = 12 * *v41;
        v43 = (float *)(12 * v41[1] + LODWORD(x));
        v44 = 12 * *(_DWORD *)(12 * v40 + LODWORD(y) + 4);
        v45 = 12 * *(_DWORD *)(12 * v40 + LODWORD(y));
        v46 = (float)((float)(*(float *)(v42 + LODWORD(x) + 8) + v43[2]) * (float)0.5);
        v48 = (float)((float)(*v43 + *(float *)(v42 + LODWORD(x))) * (float)0.5);
        v49 = (float)((float)(*(float *)(v44 + LODWORD(x)) + *(float *)(v45 + LODWORD(x))) * (float)0.5);
        v50 = (float)((float)(*(float *)(v45 + LODWORD(x) + 4) + *(float *)(v44 + LODWORD(x) + 4)) * (float)0.5);
        v51 = (float)((float)((float)(*(float *)(v42 + LODWORD(x) + 4) + v43[1]) * (float)0.5) + (float)v39);
        v47 = (float)(*(float *)(v45 + LODWORD(x) + 8) + *(float *)(v44 + LODWORD(x) + 8));
        *(float *)&this->trackedMemory = (float)((float)(*(float *)(v42 + LODWORD(x) + 4) + v43[1]) * (float)0.5)
                                       + (float)v39;
        *(float *)&this->name.str = (float)v38 + (float)v46;
        v52 = (float)((float)v48 + (float)((float)v34 + (float)v36));
        *(float *)&this->__vftable = v52;
        *(float *)&this->trackedMemory = (float)v50 + (float)v51;
        *(float *)&this->__vftable = (float)v49 + (float)v52;
        v6 += 4;
        *(float *)&this->name.str = (float)((float)v38 + (float)v46) + (float)((float)v47 * (float)0.5);
      }
      while ( v6 < v8 );
    }
    if ( v6 < v5 )
    {
      v53 = *(_DWORD *)(v3 + 8);
      v54 = result[34].z;
      v55 = result[33].y;
      v56 = result[32].x;
      v57 = v5 - v6;
      do
      {
        v58 = *(float *)&this->trackedMemory;
        v59 = 4 * (v53 + v6++);
        v60 = *(float *)&this->name.str;
        v61 = (_DWORD *)(12 * abs32(*(_DWORD *)(v59 + LODWORD(v54))) + LODWORD(v55));
        v63 = (float *)(12 * *v61 + LODWORD(v56));
        v62 = (float *)(12 * v61[1] + LODWORD(v56));
        v64 = (float)((float)(v63[1] + v62[1]) * (float)0.5);
        v65 = (float)((float)(v63[2] + v62[2]) * (float)0.5);
        *(float *)&this->__vftable = (float)((float)(*v62 + *v63) * (float)0.5) + *(float *)&this->__vftable;
        *(float *)&this->trackedMemory = (float)v64 + (float)v58;
        *(float *)&this->name.str = (float)v60 + (float)v65;
        --v57;
      }
      while ( v57 != 0 );
    }
    v66 = *(float *)&this->trackedMemory;
    v67 = *(float *)&this->name.str;
    *(float *)&this->__vftable = *(float *)&this->__vftable * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v5));
    *(float *)&this->trackedMemory = (float)v66 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v5));
    *(float *)&this->name.str = (float)v67 * (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v5));
  }
  return this;
}


// ========================================================================
// ?EdgeBounds@idAAS2File@@QBA?AVidBounds@@H@Z
// EA  : 0x825B9DC0
// RVA : 0x005B9DC0
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::EdgeBounds(idAAS2File *this, idBounds *result, int edgeNum)
{
  float x; // r9
  _DWORD *v4; // r10
  int v5; // r11
  double v6; // fp5
  double v7; // fp4
  double v8; // fp3
  double v9; // fp7
  double v10; // fp6
  float *v11; // r11

  x = result[16].b[0].x;
  v4 = (_DWORD *)(12 * abs32(edgeNum) + LODWORD(result[16].b[1].y));
  v5 = 12 * *v4 + LODWORD(x);
  this->__vftable = *(idAAS2File_vtbl **)v5;
  this->trackedMemory = *(int *)(v5 + 4);
  this->name.str = *(const char **)(v5 + 8);
  v6 = *(float *)v5;
  this->nextOnHashChain = *(idResource **)v5;
  v7 = *(float *)(v5 + 4);
  this->resourceListPtr = *(idResourceList **)(v5 + 4);
  v8 = *(float *)(v5 + 8);
  this->resourceError = *(const char **)(v5 + 8);
  v9 = *(float *)&this->trackedMemory;
  v10 = *(float *)&this->name.str;
  v11 = (float *)(12 * v4[1] + LODWORD(x));
  _FP1 = (float)(*(float *)&this->__vftable - *v11);
  __asm { fsel      f0, f1, f2, f8 }
  *(float *)&this->__vftable = _FP0;
  _FP12 = (float)((float)v9 - v11[1]);
  __asm { fsel      f11, f12, f13, f7 }
  *(float *)&this->trackedMemory = _FP11;
  _FP9 = (float)((float)v10 - v11[2]);
  __asm { fsel      f8, f9, f10, f6 }
  *(float *)&this->name.str = _FP8;
  _FP6 = (float)(*v11 - (float)v6);
  __asm { fsel      f5, f6, f7, f5 }
  *(float *)&this->nextOnHashChain = _FP5;
  _FP1 = (float)(v11[1] - (float)v7);
  __asm { fsel      f0, f1, f2, f4 }
  *(float *)&this->resourceListPtr = _FP0;
  _FP12 = (float)(v11[2] - (float)v8);
  __asm { fsel      f11, f12, f13, f3 }
  *(float *)&this->resourceError = _FP11;
  return this;
}


// ========================================================================
// ?AreaBounds@idAAS2File@@QBA?AVidBounds@@H@Z
// EA  : 0x825B9EB8
// RVA : 0x005B9EB8
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

idAAS2File *__fastcall idAAS2File::AreaBounds(idAAS2File *this, idBounds *result, int areaNum)
{
  float y; // r10
  int v5; // r30
  int v6; // r29
  float *v7; // r3
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double v12; // fp8
  double v13; // fp7
  char v26; // [sp+50h] [-40h] BYREF

  y = result[18].b[1].y;
  v5 = 0;
  *(float *)&this->name.str = 1.0e30;
  v6 = LODWORD(y) + 40 * areaNum;
  *(float *)&this->trackedMemory = 1.0e30;
  *(float *)&this->__vftable = 1.0e30;
  *(float *)&this->resourceError = -1.0e30;
  *(float *)&this->resourceListPtr = -1.0e30;
  *(float *)&this->nextOnHashChain = -1.0e30;
  if ( *(__int16 *)(v6 + 6) > 0 )
  {
    do
    {
      v7 = (float *)idAAS2File::EdgeBounds(
                      this: (idAAS2File *)&v26,
                      result,
                      edgeNum: abs32(*(_DWORD *)(4 * (*(_DWORD *)(v6 + 8) + v5++) + LODWORD(result[17].b[0].z))));
      _FP9 = (float)(*(float *)&this->__vftable - *v7);
      v9 = *(float *)&this->trackedMemory;
      v10 = *(float *)&this->name.str;
      v11 = *(float *)&this->nextOnHashChain;
      v12 = *(float *)&this->resourceListPtr;
      v13 = *(float *)&this->resourceError;
      __asm { fsel      f6, f9, f10, f0 }
      *(float *)&this->__vftable = _FP6;
      _FP4 = (float)((float)v9 - v7[1]);
      __asm { fsel      f3, f4, f5, f13 }
      *(float *)&this->trackedMemory = _FP3;
      _FP1 = (float)((float)v10 - v7[2]);
      __asm { fsel      f0, f1, f2, f12 }
      *(float *)&this->name.str = _FP0;
      _FP12 = (float)(v7[3] - (float)v11);
      __asm { fsel      f11, f12, f13, f11 }
      *(float *)&this->nextOnHashChain = _FP11;
      _FP9 = (float)(v7[4] - (float)v12);
      __asm { fsel      f8, f9, f10, f8 }
      *(float *)&this->resourceListPtr = _FP8;
      _FP5 = (float)(v7[5] - (float)v13);
      __asm { fsel      f4, f5, f6, f7 }
      *(float *)&this->resourceError = _FP4;
    }
    while ( v5 < *(__int16 *)(v6 + 6) );
  }
  return this;
}


// ========================================================================
// ?PointAreaNum@idAAS2File@@QBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@@Z
// EA  : 0x825B9FE0
// RVA : 0x005B9FE0
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::PointAreaNum(idAAS2File *this, int tree, const idVec3 *origin)
{
  int headNode; // r11
  aas2Node_t *v4; // r10
  idPlane *v5; // r11

  if ( tree < 0 || tree >= this->trees.num )
    return 0;
  headNode = this->trees.list[tree].headNode;
  while ( 1 )
  {
    v4 = &this->nodes.list[headNode];
    v5 = &this->planes.list[v4->planeNum];
    headNode = (float)((float)((float)(origin->x * v5->a)
                             + (float)((float)(v5->b * origin->y) + (float)(v5->c * origin->z)))
                     + v5->d) <= 0.0
             ? v4->children[1]
             : v4->children[0];
    if ( headNode < 0 )
      break;
    if ( headNode == 0 )
      return 0;
  }
  return -headNode;
}


// ========================================================================
// ?BoundsAreaNums@idAAS2File@@QBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidBounds@@PAHH@Z
// EA  : 0x825BA090
// RVA : 0x005BA090
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::BoundsAreaNums(idAAS2File *this, int tree, idBounds *bounds, int *areas, int maxAreas)
{
  int v9; // r27
  int v10; // r28
  char *v11; // r30
  int *v12; // r24
  int headNode; // r11
  int v14; // r9
  int v15; // r10
  int *v16; // r11
  aas2Node_t *v17; // r31
  const idPlane *v18; // r4
  int v19; // r3
  char v21; // [sp+50h] [-260h] BYREF

  if ( tree >= 0 && tree < this->trees.num )
  {
    v9 = 0;
    v10 = 0;
    v11 = &v21;
    v12 = areas - 1;
    headNode = this->trees.list[tree].headNode;
    while ( 1 )
    {
      while ( headNode > 0 )
      {
        v17 = &this->nodes.list[headNode];
        v18 = &this->planes.list[v17->planeNum];
        *(_DWORD *)v11 = v17->children[1];
        v19 = idBounds::PlaneSide(this: bounds, plane: v18, epsilon: 0.1);
        if ( v19 == 3 )
        {
          headNode = v17->children[0];
          ++v9;
          v11 += 4;
        }
        else
        {
          headNode = v17->children[v19];
        }
      }
      if ( headNode < 0 )
      {
        v14 = -headNode;
        v15 = 0;
        if ( v10 <= 0 )
        {
LABEL_10:
          if ( v14 > 0 )
          {
            ++v10;
            *++v12 = v14;
            if ( v10 >= maxAreas )
              return v10;
          }
        }
        else
        {
          v16 = areas;
          while ( *v16 != v14 )
          {
            ++v15;
            ++v16;
            if ( v15 >= v10 )
              goto LABEL_10;
          }
        }
      }
      if ( v9 == 0 )
        return v10;
      v11 -= 4;
      headNode = *(_DWORD *)v11;
      --v9;
    }
  }
  return 0;
}


// ========================================================================
// ?FlagBoundsAreas@idAAS2File@@QBAXV?$idIndex@HW4invalidAASTree_t@@@@ABVidBounds@@PA_N@Z
// EA  : 0x825BA1C8
// RVA : 0x005BA1C8
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

void __fastcall idAAS2File::FlagBoundsAreas(idAAS2File *this, int tree, idBounds *bounds, bool *areasTouched)
{
  int v7; // r28
  char *v8; // r30
  int headNode; // r11
  aas2Node_t *v10; // r31
  const idPlane *v11; // r4
  int v12; // r3
  char v13; // [sp+50h] [-250h] BYREF

  if ( tree >= 0 && tree < this->trees.num )
  {
    v7 = 0;
    v8 = &v13;
    headNode = this->trees.list[tree].headNode;
    while ( 1 )
    {
      while ( headNode > 0 )
      {
        v10 = &this->nodes.list[headNode];
        v11 = &this->planes.list[v10->planeNum];
        *(_DWORD *)v8 = v10->children[1];
        v12 = idBounds::PlaneSide(this: bounds, plane: v11, epsilon: 0.1);
        if ( v12 == 3 )
        {
          headNode = v10->children[0];
          ++v7;
          v8 += 4;
        }
        else
        {
          headNode = v10->children[v12];
        }
      }
      if ( headNode < 0 )
        areasTouched[-headNode] = true;
      if ( v7 == 0 )
        break;
      v8 -= 4;
      headNode = *(_DWORD *)v8;
      --v7;
    }
  }
}


// ========================================================================
// ?BoundsReachableAreaNum@idAAS2File@@QBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidBounds@@HH@Z
// EA  : 0x825BA2A8
// RVA : 0x005BA2A8
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::BoundsReachableAreaNum(
        idAAS2File *this,
        int tree,
        idBounds *bounds,
        unsigned __int16 areaFlags,
        const int excludeTravelFlags)
{
  int v9; // r28
  char *v10; // r29
  int headNode; // r11
  int result; // r3
  aas2Area_t *v13; // r11
  aas2Node_t *v14; // r31
  int v15; // r3
  char v16; // [sp+50h] [-250h] BYREF

  if ( tree < 0 || tree >= this->trees.num )
    return 0;
  v9 = 0;
  v10 = &v16;
  headNode = this->trees.list[tree].headNode;
  while ( 1 )
  {
    while ( headNode > 0 )
    {
      v14 = &this->nodes.list[headNode];
      v15 = idBounds::PlaneSide(this: bounds, plane: &this->planes.list[v14->planeNum], epsilon: 0.1);
      if ( v15 == 3 )
      {
        ++v9;
        headNode = v14->children[0];
        *(_DWORD *)v10 = v14->children[1];
        v10 += 4;
      }
      else
      {
        headNode = v14->children[v15];
      }
    }
    if ( headNode < 0 )
    {
      result = -headNode;
      v13 = &this->areas.list[-headNode];
      if ( (v13->flags & areaFlags) != 0 && (excludeTravelFlags & v13->travelFlags) == 0 )
        break;
    }
    if ( v9 == 0 )
      return 0;
    v10 -= 4;
    headNode = *(_DWORD *)v10;
    --v9;
  }
  return result;
}


// ========================================================================
// ?TraceHeight@idAAS2File@@QBA_NV?$idIndex@HW4invalidAASTree_t@@@@AAUaas2TraceHeight_t@@ABVidVec3@@2@Z
// EA  : 0x825BA3B8
// RVA : 0x005BA3B8
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::TraceHeight(idAAS2File *this, int tree, aas2TraceHeight_t *trace, __int64 end)
{
  double v4; // fp13
  idAAS2File::bspTree_t *list; // r9
  double v6; // fp12
  double v7; // fp11
  double v8; // fp10
  double v9; // fp9
  double v10; // fp4
  double v11; // fp6
  double v12; // fp5
  float *v13; // r11
  double v14; // fp1
  double v15; // fp2
  double v16; // fp3
  int v17; // r10
  aas2Node_t *v18; // r9
  int numPoints; // r10
  double v20; // fp13
  double v21; // fp12
  idVec3 *v22; // r10
  unsigned int planeNum; // r8
  double v24; // fp11
  double v25; // fp12
  double v26; // fp10
  double v27; // fp8
  idPlane *v28; // r10
  double v29; // fp9
  double v30; // fp7
  double v31; // fp0
  double v32; // fp13
  int v33; // r7
  double v34; // fp13
  double v35; // fp30
  double v36; // fp13
  double v37; // fp13
  double v38; // fp7
  double v39; // fp12
  double v40; // fp13
  unsigned int v41; // r10
  unsigned int v42; // r11
  float v44[16]; // [sp+60h] [-1040h] BYREF
  float v45[10]; // [sp+1060h] [-40h] BYREF

  if ( tree < 0 || tree >= this->trees.num )
    return 0;
  trace->numPoints = 0;
  v4 = *(float *)end;
  list = this->trees.list;
  v6 = *(float *)(end + 4);
  v7 = *(float *)(end + 8);
  v8 = *(float *)HIDWORD(end);
  v9 = *(float *)(HIDWORD(end) + 4);
  v44[2] = *(float *)(HIDWORD(end) + 8);
  v10 = 0.125;
  v11 = 0.0;
  v12 = -0.1000000014901161;
  v13 = v44;
  v44[1] = v9;
  v44[6] = 0.0;
  v44[0] = v8;
  HIDWORD(end) = 0x20000000;
  v44[7] = *(float *)&list[tree].headNode;
  v14 = 1.0;
  v44[3] = v4;
  v44[4] = v6;
  v44[5] = v7;
  v15 = 0.001000000047497451;
  v16 = 0.1000000014901161;
  while ( 1 )
  {
    v17 = *((_DWORD *)v13 + 7);
    if ( v17 == 0 )
      goto LABEL_25;
    v18 = &this->nodes.list[v17];
    if ( (v18->flags & 2) != 0 )
    {
      numPoints = trace->numPoints;
      if ( numPoints < trace->maxPoints )
      {
        v20 = *v13;
        v21 = v13[1];
        v22 = &trace->points[numPoints];
        v22->z = v13[2];
        v22->x = v20;
        v22->y = v21;
        LODWORD(end) = (v18->flags >> 2) - HIDWORD(end);
        trace->points[trace->numPoints++].z = (float)end;
      }
      goto LABEL_25;
    }
    planeNum = v18->planeNum;
    v24 = v13[1];
    v25 = v13[5];
    v26 = v13[2];
    v27 = v13[4];
    v28 = &this->planes.list[v18->planeNum];
    v29 = *v13;
    v30 = v13[3];
    v31 = (float)((float)((float)(v28->a * *v13) + (float)((float)(v28->c * v13[2]) + (float)(v28->b * v13[1]))) + v28->d);
    v32 = (float)((float)((float)(v28->a * v13[3]) + (float)((float)(v28->b * v13[4]) + (float)(v28->c * v13[5])))
                + v28->d);
    if ( v31 >= v12 && v32 >= v12 )
    {
      v13[7] = *(float *)v18->children;
      v13 += 8;
      if ( v13 < v45 )
        goto LABEL_25;
      idLib::Error(fmt: "idAAS2File::Trace: stack overflow", v14, v15, v16, v10);
    }
    if ( v31 < v16 && v32 < v16 )
    {
      v13[7] = *(float *)&v18->children[1];
      v13 += 8;
      if ( v13 < v45 )
        goto LABEL_25;
      idLib::Error(fmt: "idAAS2File::Trace: stack overflow", v14, v15);
    }
    v33 = *((_DWORD *)v13 + 6);
    v34 = v31 - v32;
    v35 = v31 >= v11 ? v31 - v10 : v31 + v10;
    v36 = v35 / v34;
    if ( v36 >= v11 )
    {
      if ( v36 > v14 )
        v36 = 0.9990000128746033;
    }
    else
    {
      v36 = v15;
    }
    v37 = (float)v36;
    v38 = (float)((float)((float)v30 - (float)v29) * (float)v37);
    v39 = (float)((float)((float)((float)v25 - (float)v26) * (float)v37) + (float)v26);
    v40 = (float)((float)((float)((float)v27 - (float)v24) * (float)v37) + (float)v24);
    v41 = v31 < v11;
    *((_DWORD *)v13 + 6) = planeNum;
    *v13 = (float)v38 + (float)v29;
    v13[1] = v40;
    v13[2] = v39;
    v13[7] = *(float *)&v18->children[(_cntlzw(v41) & 0x20) != 0];
    v42 = (unsigned int)(v13 + 8);
    if ( v42 >= (unsigned int)v45 )
      break;
    *(float *)v42 = v29;
    *(float *)(v42 + 4) = v24;
    *(float *)(v42 + 8) = v26;
    *(float *)(v42 + 16) = v40;
    *(float *)(v42 + 20) = v39;
    *(float *)(v42 + 12) = (float)v38 + (float)v29;
    *(_DWORD *)(v42 + 24) = v33;
    *(_DWORD *)(v42 + 28) = v18->children[v41];
    v13 = (float *)(v42 + 32);
    if ( v13 >= v45 )
      goto _LN104;
LABEL_25:
    v13 -= 8;
    if ( v13 < v44 )
      return 1;
  }
  idLib::Error(fmt: "idAAS2File::Trace: stack overflow", v14);
_LN104:
  idLib::Error(fmt: "idAAS2File::Trace: stack overflow", v14);
  return 0;
}


// ========================================================================
// ?GetFloorEdgeSplitPoints@idAAS2File@@ABA_NAAUfloorEdgeSplitPoint_t@1@0HABVidPlane@@1@Z
// EA  : 0x825BA730
// RVA : 0x005BA730
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::GetFloorEdgeSplitPoints(
        idAAS2File *this,
        idAAS2File::floorEdgeSplitPoint_t *nearest,
        idAAS2File::floorEdgeSplitPoint_t *furthest,
        int areaNum,
        const idPlane *pathPlane,
        const idPlane *nearPlane)
{
  float *v7; // r7
  int v8; // r6
  int v9; // r11
  int v10; // r12
  float *v11; // r27
  int v12; // r10
  int *list; // r29
  float *v14; // r9
  aas2Edge_t *v15; // r26
  idVec3 *v16; // r25
  int v17; // r10
  float *p_x; // r10
  float *v19; // r8
  int v20; // r6
  int v21; // r5
  int v22; // r4
  int v23; // r9
  int v24; // r12
  int v25; // r10
  float *v26; // r11
  double v27; // fp13
  int result; // r3
  int v29; // r26
  double v30; // fp0
  double v31; // fp13
  idVec3 *v32; // r9
  unsigned int v33; // r11
  aas2Edge_t *v34; // r10
  int v35; // r7
  idVec3 *v36; // r10
  float *v37; // r9
  float y; // r30
  float z; // r29
  double v40; // fp11
  double v41; // fp12
  double v42; // fp13
  double v43; // fp0
  double v44; // fp11
  _DWORD back_chain[19]; // [sp+0h] [-C0h]
  int v46; // [sp+4Ch] [-74h] BYREF
  float x; // [sp+50h] [-70h] BYREF
  float v48; // [sp+54h] [-6Ch]
  float v49; // [sp+58h] [-68h]

  nearest->edgeNum = 0;
  nearest->point.x = 0.0;
  nearest->point.z = 0.0;
  nearest->point.y = 0.0;
  nearest->dist = 1.0e30;
  furthest->edgeNum = 0;
  furthest->point.z = 0.0;
  furthest->point.y = 0.0;
  furthest->point.x = 0.0;
  furthest->dist = -1.0e30;
  ((void (*)(void))RtlCheckStack12)();
  v9 = 0;
  *(_DWORD *)((char *)back_chain + v10) = back_chain[0];
  v11 = &x;
  if ( v12 > 0 )
  {
    list = this->edgeIndex.list;
    v14 = (float *)&v46;
    v15 = this->edges.list;
    v16 = this->vertices.list;
    do
    {
      v17 = *(_DWORD *)(v8 + 8) + v9++;
      p_x = &v16[v15[abs32(list[v17])].vertexNum[(unsigned int)list[v17] >> 31]].x;
      *++v14 = (float)((float)(*v7 * *p_x) + (float)((float)(p_x[2] * v7[2]) + (float)(p_x[1] * v7[1]))) + v7[3];
    }
    while ( v9 < *(__int16 *)(v8 + 6) );
  }
  ((void (*)(void))RtlCheckStack12)();
  v23 = 0;
  *(_DWORD *)((char *)back_chain + v24) = back_chain[0];
  if ( v25 > 0 )
  {
    v26 = &x;
    do
    {
      v27 = *v26;
      if ( v27 >= -idMath::FLT_SMALLEST_NON_DENORMAL )
        *(_DWORD *)v26 = v27 > idMath::FLT_SMALLEST_NON_DENORMAL;
      else
        *v26 = NAN;
      ++v23;
      ++v26;
    }
    while ( v23 < *(__int16 *)(v20 + 6) );
  }
  result = 0;
  v29 = 0;
  *(&x + *(__int16 *)(v20 + 6)) = x;
  for ( *(&x + *(__int16 *)(v20 + 6)) = x; v29 < *(__int16 *)(v20 + 6); ++v11 )
  {
    if ( *((_DWORD *)v11 + 1) + *(_DWORD *)v11 == 0 || *(_DWORD *)v11 == 0 )
    {
      v30 = *v11;
      v31 = (float)(*v11 - v11[1]);
      v32 = this->vertices.list;
      result = 1;
      v33 = this->edgeIndex.list[*(_DWORD *)(v20 + 8) + v29];
      v34 = &this->edges.list[abs32(v33)];
      v35 = *(int *)((char *)v34->vertexNum + ((~v33 >> 29) & 4));
      v36 = &v32[*(int *)((char *)v34->vertexNum + ((v33 >> 29) & 4))];
      v37 = &v32[v35].x;
      y = v36->y;
      z = v36->z;
      x = v36->x;
      v48 = y;
      v49 = z;
      if ( __fabs(v31) <= idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        v43 = v49;
        v42 = v48;
        v41 = x;
      }
      else
      {
        v40 = (float)((float)v30 / (float)v31);
        v41 = (float)((float)((float)(*v37 - v36->x) * (float)((float)v30 / (float)v31)) + x);
        v42 = (float)(v48 + (float)((float)(v37[1] - v36->y) * (float)((float)v30 / (float)v31)));
        v43 = (float)(v49 + (float)((float)(v37[2] - v36->z) * (float)v40));
      }
      v44 = (float)((float)((float)(*v19 * (float)v41)
                          + (float)((float)(v19[2] * (float)v43) + (float)(v19[1] * (float)v42)))
                  + v19[3]);
      if ( v44 < *(float *)(v22 + 12) )
      {
        *(float *)(v22 + 12) = (float)((float)(*v19 * (float)v41)
                                     + (float)((float)(v19[2] * (float)v43) + (float)(v19[1] * (float)v42)))
                             + v19[3];
        *(_DWORD *)(v22 + 16) = v33;
        *(float *)v22 = v41;
        *(float *)(v22 + 4) = v42;
        *(float *)(v22 + 8) = v43;
      }
      if ( v44 > *(float *)(v21 + 12) )
      {
        *(float *)(v21 + 12) = v44;
        *(_DWORD *)(v21 + 16) = v33;
        *(float *)v21 = v41;
        *(float *)(v21 + 4) = v42;
        *(float *)(v21 + 8) = v43;
      }
    }
    ++v29;
  }
  return result;
}


// ========================================================================
// ?MaxTreeDepth_r@idAAS2File@@ABAXHAAH0@Z
// EA  : 0x825BAAF0
// RVA : 0x005BAAF0
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

void __fastcall idAAS2File::MaxTreeDepth_r(idAAS2File *this, int nodeNum, int *depth, int *maxDepth)
{
  int v7; // r11
  aas2Node_t *v8; // r29

  if ( nodeNum > 0 )
  {
    v7 = *depth + 1;
    *depth = v7;
    if ( v7 > *maxDepth )
      *maxDepth = v7;
    v8 = &this->nodes.list[nodeNum];
    idAAS2File::MaxTreeDepth_r(this, nodeNum: v8->children[0], depth, maxDepth);
    idAAS2File::MaxTreeDepth_r(this, nodeNum: v8->children[1], depth, maxDepth);
    --*depth;
  }
}


// ========================================================================
// ?MaxTreeDepth@idAAS2File@@ABAHV?$idIndex@HW4invalidAASTree_t@@@@@Z
// EA  : 0x825BAB78
// RVA : 0x005BAB78
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::MaxTreeDepth(idAAS2File *this, int tree)
{
  idAAS2File::bspTree_t *list; // r11
  int v4; // [sp+50h] [-10h] BYREF
  int v5; // [sp+54h] [-Ch] BYREF

  if ( tree < 0 || tree >= this->trees.num )
    return 0;
  list = this->trees.list;
  v5 = 0;
  v4 = 0;
  idAAS2File::MaxTreeDepth_r(this, nodeNum: list[tree].headNode, depth: &v5, maxDepth: &v4);
  return v4;
}


// ========================================================================
// ?Trace@idAAS2File@@QBA_NV?$idIndex@HW4invalidAASTree_t@@@@AAUaas2Trace_t@@ABVidVec3@@2@Z
// EA  : 0x825BADC8
// RVA : 0x005BADC8
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::Trace(
        idAAS2File *this,
        int tree,
        aas2Trace_t *trace,
        const idVec3 *start,
        const idVec3 *end)
{
  double z; // fp13
  idAAS2File::bspTree_t *list; // r10
  double y; // fp12
  double v8; // fp11
  double v9; // fp10
  double x; // fp9
  double v11; // fp6
  double v12; // fp1
  double v13; // fp3
  float *v14; // r11
  double v15; // fp2
  double v16; // fp4
  double v17; // fp5
  int v18; // r10
  aas2Area_t *v19; // r9
  int numAreas; // r9
  int v21; // r10
  int maxAreas; // r8
  int *areas; // r8
  idVec3 *points; // r8
  double v25; // fp13
  double v26; // fp12
  float *p_x; // r10
  double v28; // fp0
  double v29; // fp12
  double v30; // fp13
  double v31; // fp7
  double v32; // fp11
  int v33; // r9
  double v34; // fp11
  double v35; // fp9
  double v36; // fp11
  aas2Node_t *v37; // r9
  double v38; // fp12
  double v39; // fp10
  double v40; // fp8
  double v41; // fp9
  double v42; // fp7
  unsigned int planeNum; // r8
  idPlane *v44; // r10
  double v45; // fp0
  double v46; // fp13
  int v47; // r4
  double v48; // fp13
  double v49; // fp29
  double v50; // fp13
  double v51; // fp13
  double v52; // fp7
  double v53; // fp12
  double v54; // fp13
  unsigned int v55; // r10
  unsigned int v56; // r11
  double v57; // fp12
  double v59; // fp12
  double v60; // fp0
  double v61; // fp13
  double v62; // fp7
  double v63; // fp2
  int v64; // r9
  double v65; // fp10
  double v66; // fp9
  float v67[20]; // [sp+50h] [-1050h] BYREF
  float v68[10]; // [sp+1050h] [-50h] BYREF

  if ( tree >= 0 && tree < this->trees.num )
  {
    trace->numAreas = 0;
    trace->lastAreaNum = 0;
    trace->blockingAreaNum = 0;
    z = start->z;
    list = this->trees.list;
    y = end->y;
    v8 = end->z;
    v9 = start->y;
    x = end->x;
    v11 = 0.0;
    v67[0] = start->x;
    v67[6] = 0.0;
    v12 = 0.001000000047497451;
    v13 = 0.125;
    v14 = v67;
    v15 = 0.1000000014901161;
    v16 = -0.1000000014901161;
    v67[3] = x;
    v67[7] = *(float *)&list[tree].headNode;
    v67[1] = v9;
    v67[2] = z;
    v67[4] = y;
    v17 = 0.0;
    v67[5] = v8;
    while ( 1 )
    {
      v18 = *((_DWORD *)v14 + 7);
      if ( v18 < 0 )
      {
        v19 = &this->areas.list[-v18];
        if ( (v19->flags & trace->flags) != 0 || (trace->travelFlags & v19->travelFlags) != 0 )
        {
          if ( trace->lastAreaNum != 0 )
          {
            v60 = (float)(end->y - start->y);
            v62 = (float)(v14[1] - start->y);
            v61 = (float)(end->z - start->z);
            v63 = (float)(v14[2] - start->z);
            v59 = (float)(end->x - start->x);
            trace->fraction = (float)__fsqrts((float)((float)((float)(*v14 - start->x) * (float)(*v14 - start->x))
                                                    + (float)((float)((float)v63 * (float)v63)
                                                            + (float)((float)v62 * (float)v62))))
                            / (float)__fsqrts((float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                                                    + (float)((float)((float)v61 * (float)v61)
                                                            + (float)((float)v60 * (float)v60))));
          }
          else
          {
            trace->fraction = v17;
            v59 = vec3_origin.x;
            v60 = vec3_origin.y;
            v61 = vec3_origin.z;
          }
          v64 = *((_DWORD *)v14 + 6);
          v65 = v14[1];
          v66 = v14[2];
          trace->endpos.x = *v14;
          trace->endpos.y = v65;
          trace->endpos.z = v66;
          trace->planeNum = v64;
          trace->blockingAreaNum = -v18;
          if ( (float)((float)((float)v59 * this->planes.list[v64].a)
                     + (float)((float)(this->planes.list[v64].c * (float)v61)
                             + (float)(this->planes.list[v64].b * (float)v60))) > v17 )
            trace->planeNum = v64 ^ 1;
          return 1;
        }
        numAreas = trace->numAreas;
        v21 = -v18;
        maxAreas = trace->maxAreas;
        trace->lastAreaNum = v21;
        if ( numAreas < maxAreas )
        {
          areas = trace->areas;
          if ( areas != nullptr )
            areas[numAreas] = v21;
          points = trace->points;
          if ( points != nullptr )
          {
            v25 = v14[1];
            v26 = v14[2];
            p_x = &points[trace->numAreas].x;
            *p_x = *v14;
            p_x[1] = v25;
            p_x[2] = v26;
          }
          ++trace->numAreas;
        }
        goto LABEL_39;
      }
      if ( v18 == 0 )
      {
        if ( trace->lastAreaNum != 0 )
        {
          v28 = (float)(end->y - start->y);
          v31 = (float)(v14[1] - start->y);
          v30 = (float)(end->z - start->z);
          v29 = (float)(end->x - start->x);
          v32 = (float)(v14[2] - start->z);
          trace->fraction = (float)__fsqrts((float)((float)((float)(*v14 - start->x) * (float)(*v14 - start->x))
                                                  + (float)((float)((float)v32 * (float)v32)
                                                          + (float)((float)v31 * (float)v31))))
                          / (float)__fsqrts((float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                                                  + (float)((float)((float)v30 * (float)v30)
                                                          + (float)((float)v28 * (float)v28))));
        }
        else
        {
          trace->fraction = v17;
          v28 = vec3_origin.y;
          v29 = vec3_origin.x;
          v30 = vec3_origin.z;
        }
        v33 = *((_DWORD *)v14 + 6);
        v34 = *v14;
        v35 = v14[2];
        trace->endpos.y = v14[1];
        trace->endpos.x = v34;
        trace->endpos.z = v35;
        trace->planeNum = v33;
        trace->blockingAreaNum = 0;
        if ( (float)((float)((float)v29 * this->planes.list[v33].a)
                   + (float)((float)(this->planes.list[v33].c * (float)v30)
                           + (float)(this->planes.list[v33].b * (float)v28))) > v17 )
          trace->planeNum = v33 ^ 1;
        if ( trace->lastAreaNum != 0 || trace->getOutOfSolid == 0 )
          return 1;
        goto LABEL_39;
      }
      v36 = v14[2];
      v37 = &this->nodes.list[v18];
      v38 = v14[5];
      v39 = v14[1];
      v40 = v14[4];
      v41 = *v14;
      v42 = v14[3];
      planeNum = v37->planeNum;
      v44 = &this->planes.list[v37->planeNum];
      v45 = (float)((float)((float)(v44->a * *v14) + (float)((float)(v44->b * v14[1]) + (float)(v44->c * v14[2])))
                  + v44->d);
      v46 = (float)((float)((float)(v44->a * v14[3]) + (float)((float)(v44->b * v14[4]) + (float)(v44->c * v14[5])))
                  + v44->d);
      if ( v45 >= v16 && v46 >= v16 )
      {
        v14[7] = *(float *)v37->children;
        v14 += 8;
        if ( v14 < v68 )
          goto LABEL_39;
        idLib::Error(fmt: "idAAS2File::Trace: stack overflow", v12, v15, v13, v16, v17, v11);
      }
      if ( v45 >= v15 || v46 >= v15 )
        goto _LN196;
      v14[7] = *(float *)&v37->children[1];
      v14 += 8;
      if ( v14 >= v68 )
      {
        idLib::Error(fmt: "idAAS2File::Trace: stack overflow", v12);
_LN196:
        v47 = *((_DWORD *)v14 + 6);
        v48 = v45 - v46;
        if ( v45 >= v11 )
          v49 = v45 - v13;
        else
          v49 = v45 + v13;
        v50 = v49 / v48;
        if ( v50 >= v11 )
        {
          if ( v50 > 1.0 )
            v50 = 0.9990000128746033;
        }
        else
        {
          v50 = v12;
        }
        v51 = (float)v50;
        v52 = (float)((float)((float)v42 - (float)v41) * (float)v51);
        v53 = (float)((float)((float)((float)v38 - (float)v36) * (float)v51) + (float)v36);
        v54 = (float)((float)((float)((float)v40 - (float)v39) * (float)v51) + (float)v39);
        v55 = v45 < v11;
        *((_DWORD *)v14 + 6) = planeNum;
        *v14 = (float)v52 + (float)v41;
        v14[1] = v54;
        v14[2] = v53;
        v14[7] = *(float *)&v37->children[(_cntlzw(v55) & 0x20) != 0];
        v56 = (unsigned int)(v14 + 8);
        if ( v56 >= (unsigned int)v68 )
        {
          idLib::Error(fmt: "idAAS2File::Trace: stack overflow", v47);
_LN197:
          idLib::Error(fmt: "idAAS2File::Trace: stack overflow");
          JUMPOUT(0x825BB38C);
        }
        *(float *)v56 = v41;
        *(float *)(v56 + 4) = v39;
        *(float *)(v56 + 8) = v36;
        *(float *)(v56 + 16) = v54;
        *(float *)(v56 + 20) = v53;
        *(float *)(v56 + 12) = (float)v52 + (float)v41;
        *(_DWORD *)(v56 + 24) = v47;
        *(_DWORD *)(v56 + 28) = v37->children[v55];
        v14 = (float *)(v56 + 32);
        if ( v14 >= v68 )
          goto _LN197;
      }
LABEL_39:
      v14 -= 8;
      if ( v14 < v67 )
      {
        if ( trace->lastAreaNum != 0 )
        {
          trace->fraction = 1.0;
          trace->endpos.x = end->x;
          trace->endpos.y = end->y;
          v57 = end->z;
        }
        else
        {
          trace->fraction = v17;
          trace->endpos.x = start->x;
          trace->endpos.y = start->y;
          v57 = start->z;
        }
        trace->endpos.z = v57;
        trace->planeNum = 0;
        return 0;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?GetObstaclePVSWallEdges@idAAS2File@@QBAHHHPAHH@Z
// EA  : 0x825BB390
// RVA : 0x005BB390
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::GetObstaclePVSWallEdges(
        idAAS2File *this,
        int areaNum,
        int edgeFlags,
        int *edges,
        int maxEdges)
{
  int num; // r9
  aas2Area_t *list; // r11
  int result; // r3
  int v9; // r26
  unsigned int obstaclePVSOffset; // r23
  unsigned __int8 *v11; // r10
  int v12; // r24
  int v13; // r11
  int v14; // r10
  int v15; // r25
  int v16; // r27
  int v17; // r4
  aas2Area_t *v18; // r29
  int *v19; // r28
  int v20; // r11
  int v21; // r12
  int v22; // r3
  int v23; // r12
  unsigned int *v24; // r9
  unsigned int **v25; // r7
  int v26; // r6
  int v27; // r12
  int v28; // ctr
  unsigned int *v29; // r11
  unsigned int **v30; // r10
  unsigned int v31; // r9
  aas2Edge_t *v32; // r8
  int v33; // r25
  unsigned int v34; // r27
  aas2Edge_t *v35; // r9
  int v36; // r4
  int v37; // r29
  int v38; // r5
  _DWORD **v39; // r30
  int v40; // r9
  _DWORD **v41; // r11
  unsigned int *v42; // r8
  int v43; // r8
  _BYTE *v44; // r10
  unsigned int **v45; // r11
  int v46; // r8
  unsigned int **v47; // r9
  _DWORD *v48; // r11
  int v49; // ctr
  int v50; // r9
  int i; // ctr
  unsigned int *v52; // r11
  _DWORD *v53; // r10
  _DWORD back_chain[20]; // [sp+0h] [-B0h]
  _BYTE v55[96]; // [sp+50h] [-60h] BYREF

  num = this->areas.num;
  list = this->areas.list;
  result = 0;
  v9 = 0;
  obstaclePVSOffset = list[areaNum].obstaclePVSOffset;
  if ( num <= 0 )
  {
LABEL_16:
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v21) = back_chain[0];
    v22 = ((int (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v23) = back_chain[0];
    result = ((int (__fastcall *)(int))RtlCheckStack12)(a1: v22);
    *(_DWORD *)((char *)back_chain + v27) = back_chain[0];
    if ( result > 0 )
    {
      v28 = result;
      v29 = v24;
      v30 = v25;
      do
      {
        v31 = *(unsigned int *)((char *)v30 + v26 - (_DWORD)v25);
        v32 = this->edges.list;
        *v29 = v31;
        v33 = (v31 >> 29) & 4;
        v34 = (~v31 >> 29) & 4;
        v35 = &v32[abs32(v31)];
        v29[1] = *(int *)((char *)v35->vertexNum + v33);
        v29[2] = *(int *)((char *)v35->vertexNum + v34);
        v29[3] = 0;
        *v30 = v29;
        *(unsigned int **)((char *)v30 + v55 - (_BYTE *)v25) = v29;
        v29 += 4;
        ++v30;
        --v28;
      }
      while ( v28 != 0 );
    }
    v36 = result;
    v37 = 0;
    if ( result > 0 )
    {
      v38 = 0;
      v39 = v25 + 1;
      do
      {
        v40 = v37 + 1;
        if ( v37 + 1 < v36 )
        {
          v41 = v39;
          while ( 1 )
          {
            v42 = v25[v38];
            if ( v42[1] == (*(_DWORD **)((char *)v41 + v55 - (_BYTE *)v25))[2] )
            {
              v44 = &v55[4 * v40];
              v45 = &v25[v40];
              *(_DWORD *)(*(_DWORD *)v44 + 12) = v42;
              v25[v38] = *v45;
              goto LABEL_29;
            }
            v43 = *(_DWORD *)&v55[v38 * 4];
            if ( *(_DWORD *)(v43 + 8) == (*v41)[1] )
              break;
            ++v40;
            ++v41;
            if ( v40 >= v36 )
              goto LABEL_34;
          }
          v45 = &v25[v40];
          v44 = &v55[4 * v40];
          *(_DWORD *)(v43 + 12) = *v45;
          *(_DWORD *)&v55[v38 * 4] = *(_DWORD *)v44;
LABEL_29:
          if ( v40 < v36 )
          {
            if ( v40 < --v36 )
            {
              v46 = v36 - v40;
              v47 = v45 - 1;
              v48 = v44 + 4;
              v49 = v46;
              do
              {
                *++v47 = *(unsigned int **)((char *)v48 + (char *)v25 - v55);
                *(v48 - 1) = *v48;
                ++v48;
                --v49;
              }
              while ( v49 != 0 );
            }
            --v37;
            --v39;
            --v38;
          }
        }
LABEL_34:
        ++v37;
        ++v39;
        ++v38;
      }
      while ( v37 < v36 );
    }
    v50 = 0;
    if ( v36 > 0 )
    {
      for ( i = v36; i != 0; --i )
      {
        v52 = *v25;
        if ( *v25 != nullptr )
        {
          v53 = (_DWORD *)(4 * v50 + v26 - 4);
          do
          {
            ++v50;
            *++v53 = *v52;
            v52 = (unsigned int *)v52[3];
          }
          while ( v52 != nullptr );
        }
        ++v25;
      }
    }
    return result;
  }
  while ( 1 )
  {
    v11 = this->obstaclePVS.list;
    v12 = v11[obstaclePVSOffset++];
    if ( (v12 & 0x80) == 0 )
      break;
    v13 = v12 & 0x3F;
    if ( (v12 & 0x40) != 0 )
    {
      v14 = v11[obstaclePVSOffset++];
      v13 |= __ROL4__(v14, 6);
    }
    v9 += v13 + 1;
LABEL_15:
    if ( v9 >= this->areas.num )
      goto LABEL_16;
  }
  v15 = 0;
  v16 = v9;
  while ( 1 )
  {
    ++v9;
    if ( ((1 << v15) & v12) != 0 )
      break;
    ++v16;
LABEL_14:
    if ( ++v15 >= 7 )
      goto LABEL_15;
  }
  v17 = 0;
  v18 = &this->areas.list[v16++];
  if ( v18->numEdges <= 0 )
    goto LABEL_14;
  v19 = &edges[result - 1];
  while ( 1 )
  {
    v20 = this->edgeIndex.list[v18->firstEdge + v17];
    if ( (this->edges.list[abs32(v20)].flags & edgeFlags) != 0 )
    {
      ++result;
      *++v19 = v20;
      if ( result >= maxEdges )
        return result;
    }
    if ( ++v17 >= v18->numEdges )
      goto LABEL_14;
  }
}


// ========================================================================
// ?ClipGridToAreas@idAAS2File@@QBAXABVidVec3@@HHHHPAE@Z
// EA  : 0x825BB750
// RVA : 0x005BB750
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

void __fastcall idAAS2File::ClipGridToAreas(
        idAAS2File *this,
        const idVec3 *startOrigin,
        int startAreaNum,
        int travelFlags,
        unsigned int cellSize,
        int dimension,
        unsigned __int8 *reachable)
{
  __int64 v7; // r17
  __int64 v14; // r3
  signed int v19; // r23
  double v24; // fp3
  int v25; // r3
  int v26; // r12
  char *v27; // r20
  int v28; // r3
  int v29; // r12
  char *v30; // r21
  double v31; // fp13
  double v32; // fp12
  double v33; // fp11
  double v34; // fp10
  int v35; // r12
  char *v36; // r19
  float *v37; // r10
  int i; // r6
  float *v39; // r11
  double v40; // fp0
  int v41; // ctr
  double x; // fp0
  double y; // fp13
  double z; // fp10
  unsigned int v45; // r10
  int v47; // r12
  bool *v48; // r29
  int v49; // r10
  int v53; // r5
  int v54; // r28
  int v55; // r11
  int *v56; // r4
  int value; // r11
  _DWORD *v58; // r6
  int v59; // r7
  aas2Reachability_t *v60; // r11
  int toAreaNum; // r10
  int v62; // r9
  __int16 v63; // r10
  void *v64; // r3
  int v65; // r12
  _DWORD *v67; // r18
  int v71; // r22
  aas2Area_t *v72; // r24
  unsigned int v73; // r11
  aas2Edge_t *v74; // r9
  idVec3 *list; // r10
  int v76; // r8
  unsigned int v77; // r14
  int v78; // r11
  int v79; // r6
  unsigned int v91; // ctr
  _BYTE *v94; // r11
  signed int j; // ctr
  int v96; // r3
  __int64 clockTicks; // r9
  __int128 v98; // r11
  int v99; // r4
  __int128 v100; // r11
  int v101; // r4
  _DWORD v102[20]; // [sp+0h] [-640h]
  _DWORD v103[260]; // [sp+50h] [-5F0h] BYREF
  _DWORD back_chain[20]; // [sp+460h] [-1E0h]
  __int64 v105; // [sp+4B0h] [-190h] BYREF
  int v106; // [sp+4B8h] [-188h] BYREF
  signed int v107; // [sp+4BCh] [-184h]
  unsigned int v108; // [sp+4C0h] [-180h]
  signed int v109; // [sp+4C4h] [-17Ch]
  char *v110; // [sp+4C8h] [-178h]
  int v111; // [sp+4CCh] [-174h]
  char *v112; // [sp+4D0h] [-170h]
  char *v113; // [sp+4D4h] [-16Ch]
  _QWORD v114[2]; // [sp+4E0h] [-160h] BYREF
  idTimer v115; // [sp+4F0h] [-150h] BYREF
  unsigned __int64 v116; // [sp+510h] [-130h]
  idBounds v117; // [sp+520h] [-120h] BYREF
  BOOL v118; // [sp+538h] [-108h]
  BOOL v119; // [sp+53Ch] [-104h]
  _BYTE v120[16]; // [sp+540h] [-100h] BYREF
  _BYTE v121[80]; // [sp+550h] [-F0h] BYREF

  HIDWORD(v7) = reachable;
  LODWORD(v7) = 0;
  v115.clockTicks = v7;
  v115.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  v115.state = TS_STOPPED;
  if ( aas_timeClipGridToAreas.valueInteger != 0 )
  {
    v115.state = TS_STARTED;
    LODWORD(v14) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v115.start = v14;
  }
  idAAS2File::GetTreeForArea(
    this: (idAAS2File *)&v106,
    result: (idIndex<int,enum invalidAASTree_t> *)this,
    areaNum: startAreaNum);
  v114[1] = 0xFFFFFFFF00000000uLL;
  __asm { vspltisw128 v126, 0 }
  DWORD1(_R11) = this->trees.list;
  DWORD2(_R11) = cellSize * dimension;
  v114[0] = -1;
  _R3 = v114;
  _R30 = 16;
  _R11 = DWORD1(_R11) + 24 * v106;
  v19 = dimension * dimension;
  v111 = dimension * dimension;
  __asm
  {
    lvrx128   v63, r30, r11
    lvlx128   v62, r0, r11
    vor128    v61, v94, v63
  }
  v116 = cellSize | 0xFFFFFFFF00000000uLL;
  __asm { lvx128    v124, r0, r3 }
  __asm { vand128   v125, v93, v124 }
  HIDWORD(_R11) = &_vmx_bdcccccdbdcccccdbdcccccdbdcccccd;
  _R7 = v114;
  _R6 = v120;
  _R5 = v121;
  __asm { lvx128    v127, r0, r8 }
  __asm
  {
    stvx128   v126, r0, r7
    stvx128   v125, r0, r6
  }
  v24 = (float)((float)*(__int64 *)((char *)&_R11 + 4) * (float)0.5);
  DWORD2(_R11) = ((4 * dimension * dimension + 15) & 0xFFFFFFF0) + 16;
  __asm { stvx128   v127, r0, r5 }
  LODWORD(_R11) = (int)v24;
  v105 = _R11;
  v25 = ((int (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v26) = back_chain[0];
  v27 = (char *)&v105;
  v112 = (char *)&v105;
  v28 = ((int (__fastcall *)(int))RtlCheckStack12)(a1: v25);
  *(_DWORD *)((char *)back_chain + v29) = back_chain[0];
  v30 = (char *)&v105;
  v110 = (char *)&v105;
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v28);
  *(_DWORD *)((char *)back_chain + v35) = back_chain[0];
  v36 = (char *)&v105;
  v113 = (char *)&v105;
  if ( dimension > 0 )
  {
    v37 = (float *)&v105;
    for ( i = dimension; i != 0; --i )
    {
      v39 = v37;
      v40 = v34;
      v41 = dimension;
      v37 += dimension;
      do
      {
        *v39 = v40;
        v40 = (float)((float)v40 + (float)v32);
        *v39 = v31;
        *v39++ = startOrigin->z;
        --v41;
      }
      while ( v41 != 0 );
      v31 = (float)((float)v32 + (float)v31);
    }
  }
  x = startOrigin->x;
  y = startOrigin->y;
  z = startOrigin->z;
  v45 = (this->areas.num + 127) & 0xFFFFFF80;
  v117.b[0].x = startOrigin->x - (float)v33;
  v117.b[0].y = (float)y - (float)v33;
  v117.b[0].z = (float)z - (float)v33;
  v117.b[1].x = (float)x + (float)v33;
  v107 = v45;
  v117.b[1].y = (float)y + (float)v33;
  v117.b[1].z = (float)z + (float)v33;
  ((void (*)(void))RtlCheckStack12)();
  v109 = 0;
  *(_DWORD *)((char *)back_chain + v47) = back_chain[0];
  v48 = (bool *)(((unsigned int)&v117.b[1].x + 3) & 0xFFFFFF80);
  v108 = ((unsigned int)&v117.b[1].x + 3) & 0xFFFFFF80;
  if ( v49 > 0 )
  {
    do
    {
      __asm { dcbz128   r11, r29 }
      v48 = (bool *)v108;
      v109 += 128;
    }
    while ( v109 < v107 );
    _R11 = v114;
    v19 = v111;
    _R10 = v121;
    v27 = v112;
    _R9 = v120;
    v30 = v110;
    v36 = v113;
    __asm
    {
      lvx128    v126, r0, r11
      lvx128    v127, r0, r10
      lvx128    v125, r0, r9
    }
  }
  idAAS2File::FlagBoundsAreas(this, tree: v106, bounds: &v117, areasTouched: v48);
  v53 = 0;
  v54 = 1;
  v102[0] = back_chain[0];
  v55 = startAreaNum;
  v56 = v103;
  v103[0] = startAreaNum;
  do
  {
    if ( v54 >= 256 )
      break;
    value = this->areas.list[v55].reach.value;
    if ( value >= 0 )
    {
      v58 = &v103[v54 - 1];
      do
      {
        v59 = value;
        v60 = &this->reachabilities.list[value];
        if ( (v60->travelFlags & travelFlags) != 0 && (~travelFlags & v60->travelFlags) == 0 )
        {
          toAreaNum = v60->toAreaNum;
          v62 = *(&this->areas.list->travelFlags + 2 * toAreaNum + 2 * __ROL4__(toAreaNum, 2));
          if ( (v62 & travelFlags) != 0 && (v62 & ~travelFlags) == 0 && v48[toAreaNum] )
          {
            ++v54;
            v48[v60->toAreaNum] = false;
            *++v58 = v60->toAreaNum;
            if ( v54 >= 256 )
              break;
          }
        }
        v63 = this->reachabilities.list[v59].next.value;
        value = v63;
      }
      while ( v63 >= 0 );
    }
    ++v53;
    v55 = *++v56;
  }
  while ( v53 < v54 );
  v64 = memset(Dst: (void *)HIDWORD(v7), Val: 0, Size: v19);
  ((void (__fastcall *)(void *))RtlCheckStack12)(a1: v64);
  *(_DWORD *)((char *)v102 + v65) = v102[0];
  _R29 = v103;
  if ( v54 > 0 )
  {
    v67 = v103;
    _R27 = -32;
    _R25 = -48;
    do
    {
      memset(Dst: v103, Val: 255, Size: v19);
      v71 = 0;
      v72 = &this->areas.list[*v67];
      if ( v72->numEdges > 0 )
      {
        do
        {
          v73 = this->edgeIndex.list[v72->firstEdge + v71];
          v74 = &this->edges.list[abs32(v73)];
          if ( (v74->flags & 0x40) == 0 )
          {
            list = this->vertices.list;
            __asm { vpermwi128 v60, v125, 0x63 # 'c' }
            v118 = (v73 & 0x80000000) == 0;
            v119 = v118;
            v76 = *(int *)((char *)v74->vertexNum + ((v73 >> 29) & 4));
            v77 = v73 >> 31;
            v78 = v74->vertexNum[v118];
            HIDWORD(v116) = v77;
            HIDWORD(v105) = v77;
            v79 = v78;
            _R11 = &list[v76];
            _R8 = _R11;
            _R7 = &list[v79];
            _R10 = _R7;
            _R9 = 0;
            __asm
            {
              lvlx128   v59, r0, r8
              lvrx128   v58, r30, r11
              lvrx128   v57, r30, r7
              vor128    v56, v91, v58
              lvlx128   v55, r0, r10
              vor128    v54, v87, v57
              vand128   v53, v88, v124
              vand128   v52, v86, v124
              vsubfp128 v51, v84, v53
              vpermwi128 v11, v52, 0x87
              vpermwi128 v50, v51, 0x63 # 'c'
              vmulfp128 v49, v83, v60
              vmulfp128 v48, v125, v50
              vsubfp128 v47, v81, v48
              vmsum3fp128 v46, v79, v47
              vrsqrtefp128 v45, v46
              vmulfp128 v12, v79, v45
              vmaddcfp128 v11, v12, v11, v126
              vspltw    v0, v12, 1
              vspltw    v13, v12, 2
              vspltw    v12, v12, 0
              vpermwi128 v44, v11, 0xB1
              vaddfp128 v43, v11, v44
              vpermwi128 v42, v43, 0x4E # 'N'
              vaddfp128 v41, v75, v42
              vsubfp128 v11, v126, v41
            }
            if ( v19 > 0 )
            {
              _R8 = v36;
              _R10 = v30 + 48;
              _R11 = v27 + 32;
              _R7 = v30 - v27;
              _R6 = v36 - v27;
              _R5 = v36 - v30;
              v91 = ((unsigned int)(v19 - 1) >> 4) + 1;
              _R4 = -32;
              _R3 = -16;
              do
              {
                __asm
                {
                  lvx128    v10, r11, r3
                  lvx128    v9, r11, r30
                  vmaddfp   v2, v0, v11, v10
                  vmaddfp   v1, v0, v11, v9
                  lvx128    v10, r11, r4
                  lvx128    v9, r0, r11
                  vmaddfp   v31, v0, v11, v10
                  vmaddfp   v30, v0, v11, v9
                  lvx128    v10, r0, r10
                  lvx128    v9, r10, r27
                  lvx128    v8, r7, r11
                  lvx128    v4, r10, r25
                  lvx128    v7, r10, r5
                }
                _R10 += 8;
                __asm
                {
                  lvx128    v6, r0, r8
                  lvx128    v5, r6, r11
                }
                _R11 += 8;
                __asm { lvx128    v3, r8, r30 }
                _R8 += 64;
                __asm
                {
                  lvx128    v40, r9, r29
                  vmaddfp   v9, v13, v2, v9
                  vmaddfp   v10, v13, v1, v10
                  vmaddfp   v4, v13, v31, v4
                  vmaddfp   v8, v13, v30, v8
                  vmaddfp   v9, v12, v9, v3
                  vmaddfp   v10, v12, v10, v7
                  vmaddfp   v7, v12, v4, v6
                  vmaddfp   v8, v12, v8, v5
                  vcmpgtfp128 v39, v9, v127
                  vcmpgtfp128 v38, v10, v127
                  vcmpgtfp128 v37, v7, v127
                  vcmpgtfp128 v36, v8, v127
                  vpkuwus128 v35, v69, v39
                  vpkuwus128 v34, v68, v38
                  vpkuhus128 v33, v67, v34
                  vand128   v32, v65, v40
                  stvx128   v32, r9, r29
                }
                _R9 += 16;
                --v91;
              }
              while ( v91 != 0 );
            }
          }
          ++v71;
        }
        while ( v71 < v72->numEdges );
      }
      if ( v19 > 0 )
      {
        v94 = (_BYTE *)HIDWORD(v7);
        for ( j = v19; j != 0; --j )
        {
          *v94 |= v94[(_DWORD)v103 - HIDWORD(v7)];
          ++v94;
        }
      }
      --v54;
      ++v67;
    }
    while ( v54 != 0 );
  }
  if ( aas_timeClipGridToAreas.valueInteger != 0 )
  {
    v96 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    HIDWORD(clockTicks) = LODWORD(v115.clockTicks) - LODWORD(v115.start);
    LODWORD(clockTicks) = v96 + LODWORD(v115.clockTicks) - LODWORD(v115.start);
    v115.clockTicks = clockTicks;
    if ( (float)idTimer::base < 0.0 )
    {
      idTimer::InitBaseClockTicks(this: &v115);
      clockTicks = v115.clockTicks;
    }
    if ( (int)clockTicks > (int)idTimer::base )
    {
      LODWORD(clockTicks) = clockTicks - idTimer::base;
      v115.clockTicks = clockTicks;
    }
    v115.state = TS_STOPPED;
    DWORD1(v98) = HIDWORD(totalClockTicks);
    LODWORD(v98) = numCalls + 1;
    DWORD2(v98) = HIDWORD(totalClockTicks) + totalClockTicks;
    v99 = numCalls + 1;
    numCalls = v98;
    totalClockTicks = *(_QWORD *)((char *)&v98 + 4);
    idLib::Printf(
      fmt: "---------------------------------------------------------------------------\n\t\tnumCalls = %d",
      v99);
    idLib::Printf(fmt: "\tcurTick = %d\n", LODWORD(v115.clockTicks));
    idLib::Printf(fmt: "\t\ttotal = %d\n", (_DWORD)totalClockTicks);
    *(_QWORD *)((char *)&v100 + 4) = __PAIR64__(__ROL4__(totalClockTicks, 1), numCalls);
    v101 = __SPAIR64__(numCalls, totalClockTicks) / *(_QWORD *)((char *)&v100 + 4);
    LODWORD(v100) = numCalls & ~(DWORD1(v100) - 1);
    __tdllei(*(unsigned __int64 *)((char *)&v100 + 4), 0);
    __tdlgei(v100, 0xFFFFFFFF);
    idLib::Printf(fmt: "\t\tAvg   = %d\n", v101);
  }
}


// ========================================================================
// __unwind$222419
// EA  : 0x825BBF64
// RVA : 0x005BBF64
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

void _unwind_222419()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 480 + 144));
}


// ========================================================================
// ?GetFloorDistance@idAAS2File@@ABAMHABVidPlane@@ABVidVec3@@MM@Z
// EA  : 0x825BBF90
// RVA : 0x005BBF90
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

float __fastcall idAAS2File::GetFloorDistance(
        idAAS2File *this,
        int areaNum,
        const idPlane *floorPlane,
        const idVec3 *point,
        double bboxHeight,
        double maxEdgeDist)
{
  aas2Area_t *v11; // r28
  idAAS2File *TreeForArea; // r3
  double y; // fp4
  double x; // fp3
  double z; // fp2
  idAAS2File::bspTree_t *v16; // r11
  double v17; // fp26
  double v18; // fp25
  double v19; // fp24
  double v20; // fp1
  int numEdges; // r27
  double v22; // fp6
  int v23; // r31
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  int firstEdge; // r30
  int *list; // r3
  aas2Edge_t *v29; // r8
  idVec3 *v30; // r11
  int v31; // r7
  int *v32; // r6
  aas2Edge_t *v33; // r10
  float *v34; // r10
  float *p_x; // r9
  double v36; // fp13
  double v37; // fp11
  double v38; // fp0
  double v39; // fp0
  double v40; // fp13
  double v41; // fp12
  aas2Edge_t *v42; // r10
  float *v43; // r10
  float *v44; // r9
  double v45; // fp13
  double v46; // fp11
  double v47; // fp0
  double v48; // fp0
  double v49; // fp13
  double v50; // fp12
  aas2Edge_t *v51; // r10
  float *v52; // r10
  float *v53; // r9
  double v54; // fp13
  double v55; // fp11
  double v56; // fp0
  double v57; // fp0
  double v58; // fp13
  double v59; // fp12
  aas2Edge_t *v60; // r10
  float *v61; // r10
  float *v62; // r9
  double v63; // fp13
  double v64; // fp11
  double v65; // fp0
  double v66; // fp0
  double v67; // fp13
  double v68; // fp12
  idVec3 *v69; // r9
  int v70; // ctr
  aas2Edge_t *v71; // r11
  int v72; // r10
  float *v73; // r11
  float *v74; // r10
  double v75; // fp13
  double v76; // fp11
  double v77; // fp0
  double v78; // fp0
  double v79; // fp13
  double v80; // fp12
  double v81; // fp0
  char v83; // [sp+50h] [-A0h] BYREF
  idVec3 v84; // [sp+58h] [-98h]

  v11 = &this->areas.list[areaNum];
  TreeForArea = idAAS2File::GetTreeForArea(
                  this: (idAAS2File *)&v83,
                  result: (idIndex<int,enum invalidAASTree_t> *)this,
                  areaNum);
  y = point->y;
  x = point->x;
  z = point->z;
  v16 = &this->trees.list[(int)TreeForArea->__vftable];
  v17 = v16->floorNormal.y;
  v18 = v16->floorNormal.x;
  v19 = v16->floorNormal.z;
  v20 = (float)((float)__fabs((float)((float)((float)(point->z * floorPlane->c)
                                            + (float)((float)(point->x * floorPlane->a)
                                                    + (float)(point->y * floorPlane->b)))
                                    + floorPlane->d))
              / (float)((float)(v16->floorNormal.z * floorPlane->c)
                      + (float)((float)(v16->floorNormal.x * floorPlane->a) + (float)(v16->floorNormal.y * floorPlane->b))));
  if ( v20 >= bboxHeight )
  {
    numEdges = v11->numEdges;
    v22 = 1.0e30;
    v23 = 0;
    v84 = vec3_origin;
    v24 = vec3_origin.x;
    v25 = vec3_origin.y;
    v26 = vec3_origin.z;
    if ( numEdges >= 4 )
    {
      firstEdge = v11->firstEdge;
      list = this->edgeIndex.list;
      v29 = this->edges.list;
      v30 = this->vertices.list;
      do
      {
        v31 = firstEdge + v23;
        v32 = &list[firstEdge + v23];
        v33 = &v29[abs32(*v32)];
        p_x = &v30[v33->vertexNum[1]].x;
        v34 = &v30[v33->vertexNum[0]].x;
        v36 = (float)(p_x[2] - v34[2]);
        v37 = (float)(p_x[1] - v34[1]);
        if ( (float)((float)((float)v37 * (float)v37)
                   + (float)((float)((float)(*p_x - *v34) * (float)(*p_x - *v34)) + (float)((float)v36 * (float)v36))) >= 0.1 )
        {
          v38 = (float)((float)((float)((float)((float)y - v34[1]) * (float)(p_x[1] - v34[1]))
                              + (float)((float)((float)((float)z - v34[2]) * (float)(p_x[2] - v34[2]))
                                      + (float)((float)((float)x - *v34) * (float)(*p_x - *v34))))
                      / (float)((float)((float)v37 * (float)v37)
                              + (float)((float)((float)(*p_x - *v34) * (float)(*p_x - *v34))
                                      + (float)((float)v36 * (float)v36))));
          if ( v38 >= 0.0 )
          {
            if ( v38 > 1.0 )
              v38 = 1.0;
          }
          else
          {
            v38 = 0.0;
          }
          v40 = (float)((float)((float)z - v34[2]) - (float)((float)(p_x[2] - v34[2]) * (float)v38));
          v41 = (float)((float)((float)x - *v34) - (float)((float)(*p_x - *v34) * (float)v38));
          v39 = (float)((float)((float)y - v34[1]) - (float)((float)(p_x[1] - v34[1]) * (float)v38));
          if ( (float)((float)((float)v41 * (float)v41)
                     + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39))) < v22 )
          {
            v22 = (float)((float)((float)v41 * (float)v41)
                        + (float)((float)((float)v40 * (float)v40) + (float)((float)v39 * (float)v39)));
            v24 = v41;
            v25 = v39;
            v26 = v40;
          }
        }
        v42 = &v29[abs32(v32[1])];
        v44 = &v30[v42->vertexNum[1]].x;
        v43 = &v30[v42->vertexNum[0]].x;
        v45 = (float)(v44[2] - v43[2]);
        v46 = (float)(v44[1] - v43[1]);
        if ( (float)((float)((float)v46 * (float)v46)
                   + (float)((float)((float)(*v44 - *v43) * (float)(*v44 - *v43)) + (float)((float)v45 * (float)v45))) >= 0.1 )
        {
          v47 = (float)((float)((float)((float)((float)y - v43[1]) * (float)(v44[1] - v43[1]))
                              + (float)((float)((float)((float)z - v43[2]) * (float)(v44[2] - v43[2]))
                                      + (float)((float)((float)x - *v43) * (float)(*v44 - *v43))))
                      / (float)((float)((float)v46 * (float)v46)
                              + (float)((float)((float)(*v44 - *v43) * (float)(*v44 - *v43))
                                      + (float)((float)v45 * (float)v45))));
          if ( v47 >= 0.0 )
          {
            if ( v47 > 1.0 )
              v47 = 1.0;
          }
          else
          {
            v47 = 0.0;
          }
          v49 = (float)((float)((float)z - v43[2]) - (float)((float)(v44[2] - v43[2]) * (float)v47));
          v50 = (float)((float)((float)x - *v43) - (float)((float)(*v44 - *v43) * (float)v47));
          v48 = (float)((float)((float)y - v43[1]) - (float)((float)(v44[1] - v43[1]) * (float)v47));
          if ( (float)((float)((float)v50 * (float)v50)
                     + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48))) < v22 )
          {
            v22 = (float)((float)((float)v50 * (float)v50)
                        + (float)((float)((float)v49 * (float)v49) + (float)((float)v48 * (float)v48)));
            v24 = v50;
            v25 = v48;
            v26 = v49;
          }
        }
        v51 = &v29[abs32(list[v31 + 2])];
        v53 = &v30[v51->vertexNum[1]].x;
        v52 = &v30[v51->vertexNum[0]].x;
        v54 = (float)(v53[2] - v52[2]);
        v55 = (float)(v53[1] - v52[1]);
        if ( (float)((float)((float)v55 * (float)v55)
                   + (float)((float)((float)(*v53 - *v52) * (float)(*v53 - *v52)) + (float)((float)v54 * (float)v54))) >= 0.1 )
        {
          v56 = (float)((float)((float)((float)((float)y - v52[1]) * (float)(v53[1] - v52[1]))
                              + (float)((float)((float)((float)z - v52[2]) * (float)(v53[2] - v52[2]))
                                      + (float)((float)((float)x - *v52) * (float)(*v53 - *v52))))
                      / (float)((float)((float)v55 * (float)v55)
                              + (float)((float)((float)(*v53 - *v52) * (float)(*v53 - *v52))
                                      + (float)((float)v54 * (float)v54))));
          if ( v56 >= 0.0 )
          {
            if ( v56 > 1.0 )
              v56 = 1.0;
          }
          else
          {
            v56 = 0.0;
          }
          v58 = (float)((float)((float)z - v52[2]) - (float)((float)(v53[2] - v52[2]) * (float)v56));
          v59 = (float)((float)((float)x - *v52) - (float)((float)(*v53 - *v52) * (float)v56));
          v57 = (float)((float)((float)y - v52[1]) - (float)((float)(v53[1] - v52[1]) * (float)v56));
          if ( (float)((float)((float)v59 * (float)v59)
                     + (float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57))) < v22 )
          {
            v22 = (float)((float)((float)v59 * (float)v59)
                        + (float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)));
            v24 = v59;
            v25 = v57;
            v26 = v58;
          }
        }
        v60 = &v29[abs32(list[v31 + 3])];
        v62 = &v30[v60->vertexNum[1]].x;
        v61 = &v30[v60->vertexNum[0]].x;
        v63 = (float)(v62[2] - v61[2]);
        v64 = (float)(v62[1] - v61[1]);
        if ( (float)((float)((float)v64 * (float)v64)
                   + (float)((float)((float)(*v62 - *v61) * (float)(*v62 - *v61)) + (float)((float)v63 * (float)v63))) >= 0.1 )
        {
          v65 = (float)((float)((float)((float)((float)y - v61[1]) * (float)(v62[1] - v61[1]))
                              + (float)((float)((float)((float)z - v61[2]) * (float)(v62[2] - v61[2]))
                                      + (float)((float)((float)x - *v61) * (float)(*v62 - *v61))))
                      / (float)((float)((float)v64 * (float)v64)
                              + (float)((float)((float)(*v62 - *v61) * (float)(*v62 - *v61))
                                      + (float)((float)v63 * (float)v63))));
          if ( v65 >= 0.0 )
          {
            if ( v65 > 1.0 )
              v65 = 1.0;
          }
          else
          {
            v65 = 0.0;
          }
          v67 = (float)((float)((float)z - v61[2]) - (float)((float)(v62[2] - v61[2]) * (float)v65));
          v68 = (float)((float)((float)x - *v61) - (float)((float)(*v62 - *v61) * (float)v65));
          v66 = (float)((float)((float)y - v61[1]) - (float)((float)(v62[1] - v61[1]) * (float)v65));
          if ( (float)((float)((float)v68 * (float)v68)
                     + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66))) < v22 )
          {
            v22 = (float)((float)((float)v68 * (float)v68)
                        + (float)((float)((float)v67 * (float)v67) + (float)((float)v66 * (float)v66)));
            v24 = v68;
            v25 = v66;
            v26 = v67;
          }
        }
        v23 += 4;
      }
      while ( v23 < numEdges - 3 );
    }
    if ( v23 < numEdges )
    {
      v69 = this->vertices.list;
      v70 = numEdges - v23;
      do
      {
        v71 = &this->edges.list[abs32(this->edgeIndex.list[v11->firstEdge + v23])];
        v72 = v71->vertexNum[1];
        v73 = &v69[v71->vertexNum[0]].x;
        v74 = &v69[v72].x;
        v75 = (float)(v74[2] - v73[2]);
        v76 = (float)(v74[1] - v73[1]);
        if ( (float)((float)((float)v76 * (float)v76)
                   + (float)((float)((float)(*v74 - *v73) * (float)(*v74 - *v73)) + (float)((float)v75 * (float)v75))) >= 0.1 )
        {
          v77 = (float)((float)((float)((float)((float)y - v73[1]) * (float)(v74[1] - v73[1]))
                              + (float)((float)((float)((float)z - v73[2]) * (float)(v74[2] - v73[2]))
                                      + (float)((float)((float)x - *v73) * (float)(*v74 - *v73))))
                      / (float)((float)((float)v76 * (float)v76)
                              + (float)((float)((float)(*v74 - *v73) * (float)(*v74 - *v73))
                                      + (float)((float)v75 * (float)v75))));
          if ( v77 >= 0.0 )
          {
            if ( v77 > 1.0 )
              v77 = 1.0;
          }
          else
          {
            v77 = 0.0;
          }
          v79 = (float)((float)((float)z - v73[2]) - (float)((float)(v74[2] - v73[2]) * (float)v77));
          v80 = (float)((float)((float)x - *v73) - (float)((float)(*v74 - *v73) * (float)v77));
          v78 = (float)((float)((float)y - v73[1]) - (float)((float)(v74[1] - v73[1]) * (float)v77));
          if ( (float)((float)((float)v80 * (float)v80)
                     + (float)((float)((float)v79 * (float)v79) + (float)((float)v78 * (float)v78))) < v22 )
          {
            v22 = (float)((float)((float)v80 * (float)v80)
                        + (float)((float)((float)v79 * (float)v79) + (float)((float)v78 * (float)v78)));
            v24 = v80;
            v25 = v78;
            v26 = v79;
          }
        }
        ++v23;
        --v70;
      }
      while ( v70 != 0 );
    }
    if ( v22 < (float)((float)maxEdgeDist * (float)maxEdgeDist) )
    {
      v81 = __fabs((float)((float)((float)v19 * (float)v26)
                         + (float)((float)((float)v18 * (float)v24) + (float)((float)v17 * (float)v25))));
      if ( v81 < v20 )
        v20 = v81;
    }
  }
  return *((float *)&v20 + 1);
}


// ========================================================================
// ?PointBestReachableAreaNum@idAAS2File@@ABAXV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@AAUbestReachableArea_t@1@@Z
// EA  : 0x825BC618
// RVA : 0x005BC618
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

void __fastcall idAAS2File::PointBestReachableAreaNum(
        idAAS2File *this,
        int tree,
        const idVec3 *origin,
        idAAS2File::bestReachableArea_t *bestArea)
{
  int planeNum; // r7
  int headNode; // r11
  bool v7; // cr56
  aas2Node_t *v8; // r10
  idPlane *v9; // r11
  int v10; // r31
  aas2Area_t *v11; // r11

  if ( tree >= 0 && tree < this->trees.num )
  {
    planeNum = -1;
    headNode = this->trees.list[tree].headNode;
    v7 = headNode < 0;
    while ( !v7 )
    {
      v8 = &this->nodes.list[headNode];
      v9 = &this->planes.list[v8->planeNum];
      if ( (float)((float)((float)(v9->a * origin->x) + (float)((float)(v9->c * origin->z) + (float)(v9->b * origin->y)))
                 + v9->d) <= 0.0 )
      {
        headNode = v8->children[1];
      }
      else
      {
        headNode = v8->children[0];
        if ( (v8->flags & 1) != 0 )
          planeNum = v8->planeNum;
      }
      v7 = headNode < 0;
      if ( headNode == 0 )
        return;
    }
    v10 = -headNode;
    v11 = &this->areas.list[-headNode];
    if ( (v11->flags & bestArea->areaFlags) != 0 && (bestArea->excludeTravelFlags & v11->travelFlags) == 0 )
    {
      bestArea->pointAreaFloorDist = idAAS2File::GetFloorDistance(
                                       this,
                                       areaNum: v10,
                                       floorPlane: &this->planes.list[planeNum],
                                       point: origin,
                                       bboxHeight: bestArea->bboxHeight,
                                       maxEdgeDist: bestArea->maxEdgeDist);
      bestArea->pointAreaNum = v10;
    }
  }
}


// ========================================================================
// ?BoundsBestReachableAreaNum@idAAS2File@@ABAXV?$idIndex@HW4invalidAASTree_t@@@@ABVidBounds@@ABVidVec3@@AAUbestReachableArea_t@1@@Z
// EA  : 0x825BC770
// RVA : 0x005BC770
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

void __fastcall idAAS2File::BoundsBestReachableAreaNum(
        idAAS2File *this,
        int tree,
        idBounds *bounds,
        const idVec3 *origin,
        idAAS2File::bestReachableArea_t *bestArea)
{
  int v9; // r27
  int planeNum; // r26
  char *v11; // r28
  int headNode; // r11
  int v13; // r31
  aas2Area_t *v14; // r11
  double FloorDistance; // fp1
  aas2Node_t *v16; // r31
  int v17; // r3
  char v18; // [sp+50h] [-250h] BYREF

  if ( tree >= 0 && tree < this->trees.num )
  {
    v9 = 0;
    planeNum = -1;
    v11 = &v18;
    headNode = this->trees.list[tree].headNode;
    while ( 1 )
    {
      while ( headNode > 0 )
      {
        v16 = &this->nodes.list[headNode];
        v17 = idBounds::PlaneSide(this: bounds, plane: &this->planes.list[v16->planeNum], epsilon: 0.1);
        if ( (v16->flags & 1) != 0 && v17 != 1 )
          planeNum = v16->planeNum;
        if ( v17 == 3 )
        {
          ++v9;
          headNode = v16->children[0];
          *(_DWORD *)v11 = v16->children[1];
          v11 += 4;
        }
        else
        {
          headNode = v16->children[v17];
        }
      }
      if ( headNode < 0 )
      {
        v13 = -headNode;
        v14 = &this->areas.list[-headNode];
        if ( (v14->flags & bestArea->areaFlags) != 0 && (bestArea->excludeTravelFlags & v14->travelFlags) == 0 )
        {
          FloorDistance = idAAS2File::GetFloorDistance(
                            this,
                            areaNum: v13,
                            floorPlane: &this->planes.list[planeNum],
                            point: origin,
                            bboxHeight: bestArea->bboxHeight,
                            maxEdgeDist: bestArea->maxEdgeDist);
          if ( FloorDistance < (float)(bestArea->pointAreaFloorDist - bestArea->bboxHeight)
            && FloorDistance < bestArea->boundsAreaFloorDist )
          {
            bestArea->boundsAreaFloorDist = FloorDistance;
            bestArea->boundsAreaNum = v13;
          }
        }
      }
      if ( v9 == 0 )
        break;
      v11 -= 4;
      headNode = *(_DWORD *)v11;
      --v9;
    }
  }
}


// ========================================================================
// ?PointReachableAreaNum@idAAS2File@@QBAHV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@HH@Z
// EA  : 0x825BC8F0
// RVA : 0x005BC8F0
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::PointReachableAreaNum(
        idAAS2File *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        const idVec3 *origin,
        int areaFlags,
        int excludeTravelFlags)
{
  double x; // fp13
  double y; // fp12
  int v10; // r28
  double v11; // fp9
  double v14; // fp4
  double v15; // fp3
  double v16; // fp2
  double v17; // fp1
  int result; // r3
  idBounds v19; // [sp+50h] [-80h] BYREF
  idAAS2File::bestReachableArea_t v20; // [sp+70h] [-60h] BYREF

  if ( (int)tree < 0 || (int)tree >= this->trees.num )
    return 0;
  x = this->settings.boundingBox.b[1].x;
  y = this->settings.boundingBox.b[1].y;
  v10 = 0;
  v11 = (float)(this->settings.boundingBox.b[1].z - this->settings.boundingBox.b[0].z);
  v20.areaFlags = areaFlags;
  v20.pointAreaNum = 0;
  v20.bboxHeight = v11;
  v20.boundsAreaNum = 0;
  v20.pointAreaFloorDist = 1.0e30;
  v20.excludeTravelFlags = excludeTravelFlags;
  v20.boundsAreaFloorDist = 1.0e30;
  _FP6 = (float)((float)((float)y * (float)0.25) - (float)((float)x * (float)0.25));
  __asm { fsel      f31, f6, f7, f8 }
  v20.maxEdgeDist = (float)_FP31 * (float)6.0;
  idAAS2File::PointBestReachableAreaNum(this, (int)tree, origin, bestArea: &v20);
  v14 = origin->x;
  v15 = origin->y;
  v16 = (float)(origin->x - (float)_FP31);
  v17 = (float)(origin->y - (float)_FP31);
  v19.b[1].z = origin->z;
  v19.b[0].z = v19.b[1].z;
  v19.b[0].x = v16;
  v19.b[0].y = v17;
  v19.b[1].x = (float)v14 + (float)_FP31;
  v19.b[1].y = (float)v15 + (float)_FP31;
  do
  {
    idAAS2File::BoundsBestReachableAreaNum(this, (int)tree, bounds: &v19, origin, bestArea: &v20);
    result = v20.boundsAreaNum;
    if ( v20.boundsAreaNum != 0 && v20.boundsAreaFloorDist < (double)(float)(v20.bboxHeight * (float)2.0) )
      break;
    ++v10;
    v19.b[0].x = v19.b[0].x - (float)_FP31;
    v19.b[0].y = v19.b[0].y - (float)_FP31;
    v19.b[0].z = v19.b[0].z - (float)_FP31;
    v19.b[1].x = v19.b[1].x + (float)_FP31;
    v19.b[1].y = v19.b[1].y + (float)_FP31;
    v19.b[1].z = v19.b[1].z + (float)_FP31;
  }
  while ( v10 < 4 );
  if ( v20.boundsAreaNum == 0 )
    return v20.pointAreaNum;
  return result;
}


// ========================================================================
// ?PushPointIntoAreaNum@idAAS2File@@QBA_NHAAVidVec3@@@Z
// EA  : 0x825BCA88
// RVA : 0x005BCA88
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::PushPointIntoAreaNum(idAAS2File *this, int areaNum, idVec3 *point)
{
  float y; // r9
  float z; // r8
  double v8; // fp30
  int v9; // r25
  char v10; // r23
  idAAS2File *TreeForArea; // r3
  double c; // fp29
  double b; // fp28
  double a; // fp27
  aas2Area_t *v15; // r27
  int v16; // r26
  idAAS2File::bspTree_t *v17; // r24
  double v18; // fp26
  double v19; // fp25
  double x; // fp24
  unsigned int v21; // r11
  aas2Edge_t *v22; // r10
  idVec3 *list; // r9
  unsigned int v24; // r6
  int v25; // r11
  int v26; // r10
  float *p_x; // r30
  float *v28; // r28
  double v29; // fp10
  double v30; // fp9
  double v31; // fp7
  double v32; // fp6
  double v33; // fp12
  double v34; // fp10
  double v35; // fp11
  double v36; // fp9
  double v37; // fp0
  int result; // r3
  char v39; // [sp+50h] [-D0h] BYREF
  idPlane v40; // [sp+60h] [-C0h] BYREF
  idVec3 v41; // [sp+70h] [-B0h] BYREF

  y = point->y;
  z = point->z;
  v8 = 1.0e30;
  v9 = 0;
  v41.x = point->x;
  v41.y = y;
  v10 = 0;
  v41.z = z;
  v40.a = v41.x;
  v40.b = y;
  v40.c = z;
  TreeForArea = idAAS2File::GetTreeForArea(
                  this: (idAAS2File *)&v39,
                  result: (idIndex<int,enum invalidAASTree_t> *)this,
                  areaNum);
  c = v40.c;
  b = v40.b;
  a = v40.a;
  v15 = &this->areas.list[areaNum];
  v16 = 0;
  v17 = &this->trees.list[(int)TreeForArea->__vftable];
  if ( v15->numEdges > 0 )
  {
    v18 = v41.z;
    v19 = v41.y;
    x = v41.x;
    do
    {
      v21 = this->edgeIndex.list[v15->firstEdge + v16];
      v22 = &this->edges.list[abs32(v21)];
      if ( (v22->flags & 0x40) == 0 )
      {
        list = this->vertices.list;
        v24 = (~v21 >> 29) & 4;
        v25 = *(int *)((char *)v22->vertexNum + ((v21 >> 29) & 4));
        v26 = *(int *)((char *)v22->vertexNum + v24);
        p_x = &list[v25].x;
        v28 = &list[v26].x;
        v29 = (float)(p_x[1] - (float)v19);
        v30 = (float)(p_x[2] - (float)v18);
        if ( (float)((float)((float)(*p_x - (float)x) * (float)(*p_x - (float)x))
                   + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29))) < v8 )
        {
          v8 = (float)((float)((float)(*p_x - (float)x) * (float)(*p_x - (float)x))
                     + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29)));
          a = list[v25].x;
          b = list[v25].y;
          c = list[v25].z;
        }
        v31 = (float)(v28[1] - list[v25].y);
        v32 = (float)(v28[2] - list[v25].z);
        v41.x = *v28 - list[v25].x;
        v41.y = v31;
        v41.z = v32;
        idPlane::FromVecs(this: &v40, dir1: &v41, dir2: &v17->floorNormal, p: &list[v26], fixDegenerate: true);
        v33 = point->y;
        v34 = v40.b;
        v35 = point->z;
        v36 = v40.c;
        v37 = (float)((float)((float)(point->x * v40.a) + (float)((float)(point->z * v40.c) + (float)(point->y * v40.b)))
                    + v40.d);
        if ( v37 < 0.0 )
        {
          v9 = 1;
          point->x = point->x
                   - (float)(v40.a
                           * (float)((float)((float)(point->x * v40.a)
                                           + (float)((float)(point->z * v40.c) + (float)(point->y * v40.b)))
                                   + v40.d));
          point->y = (float)v33 - (float)((float)v34 * (float)v37);
          point->z = (float)v35 - (float)((float)v36 * (float)v37);
          v37 = 0.0;
        }
        if ( __fabs(v37) < 0.1
          && (float)((float)((float)(point->x - *p_x) * (float)(*v28 - *p_x))
                   + (float)((float)((float)(point->z - p_x[2]) * (float)(v28[2] - p_x[2]))
                           + (float)((float)(point->y - p_x[1]) * (float)(v28[1] - p_x[1])))) >= 0.0
          && (float)((float)((float)(point->x - *v28) * (float)(*v28 - *p_x))
                   + (float)((float)((float)(point->z - v28[2]) * (float)(v28[2] - p_x[2]))
                           + (float)((float)(point->y - v28[1]) * (float)(v28[1] - p_x[1])))) <= 0.0 )
        {
          v10 = 1;
        }
      }
      ++v16;
    }
    while ( v16 < v15->numEdges );
  }
  result = v9;
  if ( (_BYTE)v9 != 0 && v10 == 0 )
  {
    point->x = a;
    point->y = b;
    point->z = c;
  }
  return result;
}


// ========================================================================
// ?TraceFloor@idAAS2File@@QBA_NAAUaas2TraceFloor_t@@ABVidVec3@@H1HH_N22@Z
// EA  : 0x825BCEA8
// RVA : 0x005BCEA8
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

int __fastcall idAAS2File::TraceFloor(
        idAAS2File *this,
        aas2TraceFloor_t *trace,
        const idVec3 *start,
        int startAreaNum,
        const idVec3 *end,
        int endAreaNum,
        int travelFlags,
        bool allowFloorNormalChange,
        bool ignoreGravityDirectionDistance,
        bool ignoreSameArea,
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
        char a28,
        int a29,
        char a30)
{
  idVec3 *p_endpos; // r27
  idVec3 *p_edgePoint; // r16
  idVec3 *v39; // r20
  idAAS2File *TreeForArea; // r3
  double y; // fp31
  double z; // fp24
  double x; // fp20
  double v44; // fp18
  double v45; // fp25
  double v46; // fp17
  double v47; // fp5
  idAAS2File::bspTree_t *v48; // r9
  double v49; // fp4
  double v50; // fp3
  float v51; // r7
  float v52; // r6
  double v53; // fp30
  double v54; // fp28
  double v55; // fp29
  int v56; // r23
  double b; // fp26
  double c; // fp27
  double v59; // fp25
  double a; // fp23
  double v61; // fp22
  double v62; // fp21
  double v63; // fp20
  double v64; // fp12
  double v65; // fp13
  double v66; // fp0
  int *areas; // r10
  int numAreas; // r11
  int v69; // r6
  int v70; // r5
  double v71; // fp13
  double v72; // fp11
  double v73; // fp12
  int edgeNum; // r11
  aas2Area_t *v75; // r10
  int num; // r19
  int value; // r8
  int v78; // r25
  aas2Reachability_t *v79; // r29
  int v80; // r7
  char *v81; // r10
  int maxReachIndices; // r9
  idIndex<short,enum invalidReachability_t> *reachIndices; // r10
  int numReachIndices; // r11
  idAAS2File::bspTree_t *v85; // r31
  double v86; // fp31
  char v87; // r11
  double v88; // fp17
  double v89; // fp16
  double v90; // fp13
  double v91; // fp15
  double v92; // fp7
  double v93; // fp4
  double v94; // fp2
  double v95; // fp11
  double v96; // fp7
  double v97; // fp4
  int toAreaNum; // r6
  int v99; // r11
  double v100; // fp0
  double v101; // fp13
  double v102; // fp12
  double v103; // fp0
  double v104; // fp13
  int v105; // r31
  double v106; // fp12
  double v107; // fp5
  double v108; // fp4
  double v109; // fp0
  double v110; // fp13
  double v111; // fp12
  double v112; // fp13
  double v113; // fp12
  double v114; // fp10
  double v115; // fp8
  double v116; // fp10
  double v117; // fp11
  double v118; // fp0
  int v120; // [sp+8h] [-208h]
  int v121; // [sp+Ch] [-204h]
  int v122; // [sp+10h] [-200h]
  int v123; // [sp+14h] [-1FCh]
  int v124; // [sp+18h] [-1F8h]
  int v125; // [sp+1Ch] [-1F4h]
  int v126; // [sp+54h] [-1BCh] BYREF
  char v127; // [sp+58h] [-1B8h] BYREF
  idVec3 v128; // [sp+60h] [-1B0h] BYREF
  idPlane v129; // [sp+70h] [-1A0h] BYREF
  idPlane v130; // [sp+80h] [-190h] BYREF
  idPlane v131; // [sp+90h] [-180h] BYREF
  idPlane v132; // [sp+A0h] [-170h] BYREF
  idAAS2File::floorEdgeSplitPoint_t v133; // [sp+B0h] [-160h] BYREF
  idAAS2File::floorEdgeSplitPoint_t v134[8]; // [sp+D0h] [-140h] BYREF

  trace->fraction = 0.0;
  trace->endpos = *start;
  trace->firstEdge.toAreaNum = 0;
  trace->lastAreaNum = startAreaNum;
  p_endpos = &trace->endpos;
  trace->firstEdge.edgeNum = 0;
  trace->firstEdge.edgePoint = *start;
  p_edgePoint = &trace->firstEdge.edgePoint;
  v39 = &trace->lastEdge.edgePoint;
  trace->lastEdge.toAreaNum = 0;
  trace->lastEdge.edgeNum = 0;
  trace->lastEdge.edgePoint = *start;
  trace->numAreas = 0;
  trace->numReachIndices = 0;
  TreeForArea = idAAS2File::GetTreeForArea(
                  this: (idAAS2File *)&v126,
                  result: (idIndex<int,enum invalidAASTree_t> *)this,
                  areaNum: startAreaNum);
  y = start->y;
  z = start->z;
  x = end->x;
  v44 = start->x;
  v45 = end->y;
  v46 = end->z;
  v47 = (float)(end->x - start->x);
  v48 = &this->trees.list[(int)TreeForArea->__vftable];
  v49 = (float)(end->y - start->y);
  v50 = (float)(end->z - start->z);
  v51 = v48->floorNormal.z;
  v52 = v48->floorNormal.y;
  v128.x = v48->floorNormal.x;
  v53 = v128.x;
  v128.z = v51;
  v54 = v51;
  v128.y = v52;
  v55 = v52;
  v130.b = (float)(v51 * (float)v47) - (float)((float)v50 * v128.x);
  v130.a = (float)(v52 * (float)v50) - (float)(v51 * (float)v49);
  v130.c = (float)((float)v49 * v128.x) - (float)(v52 * (float)v47);
  idPlane::Normalize(this: &v130, fixDegenerate: true);
  v129.c = (float)((float)v55 * v130.a) - (float)(v130.b * (float)v53);
  v129.a = (float)(v130.b * (float)v54) - (float)(v130.c * (float)v55);
  v129.b = (float)(v130.c * (float)v53) - (float)((float)v54 * v130.a);
  v130.d = -(float)((float)(v130.a * (float)v44) + (float)((float)(v130.c * (float)z) + (float)(v130.b * (float)y)));
  idPlane::Normalize(this: &v129, fixDegenerate: true);
  v56 = startAreaNum;
  b = v129.b;
  c = v129.c;
  a = v129.a;
  v61 = v129.b;
  v62 = v129.c;
  v129.d = -(float)((float)(v129.a * (float)v44) + (float)((float)(v129.c * (float)z) + (float)(v129.b * (float)y)));
  v63 = (float)-(float)((float)(v129.a * (float)x) + (float)((float)(v129.c * (float)v46) + (float)(v129.b * (float)v45)));
  v59 = v129.a;
  if ( endAreaNum == 0 )
    endAreaNum = idAAS2File::PointAreaNum(this, tree: 0, origin: end);
  if ( (unsigned __int8)idAAS2File::GetFloorEdgeSplitPoints(
                          this,
                          nearest: v134,
                          furthest: &v133,
                          areaNum: startAreaNum,
                          pathPlane: &v130,
                          nearPlane: &v129) == 0 )
  {
    v64 = start->x;
    v133.edgeNum = 0;
    v65 = start->y;
    v134[0].edgeNum = 0;
    v66 = start->z;
    v133.point.x = v64;
    v133.point.y = v65;
    v133.point.z = v66;
    v133.dist = 0.0;
    v134[0].dist = 0.0;
    v134[0].point.x = v64;
    v134[0].point.y = v65;
    v134[0].point.z = v66;
  }
  idAAS2File::FloodClearVisitedAreas(this, offset: 0);
  while ( 2 )
  {
    areas = trace->areas;
    if ( areas != nullptr )
    {
      numAreas = trace->numAreas;
      if ( numAreas < trace->maxAreas )
      {
        areas[numAreas] = v56;
        ++trace->numAreas;
      }
    }
    v126 = v56;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->visitedAreas,
      obj: (const encounterGroupRole_t *)&v126);
    v71 = v133.point.z;
    v72 = v133.point.x;
    v73 = v133.point.y;
    this->areas.list[v56].flags |= 0x8000u;
    if ( (v56 == endAreaNum
       || (float)((float)((float)((float)v73 * (float)v61)
                        + (float)((float)((float)v72 * (float)a) + (float)((float)v71 * (float)v62)))
                + (float)v63) > 0.1)
      && a30 != 0 )
    {
      p_endpos->x = end->x;
      trace->endpos.y = end->y;
      trace->endpos.z = end->z;
      trace->fraction = 1.0;
      goto LABEL_51;
    }
    edgeNum = v133.edgeNum;
    trace->lastAreaNum = v56;
    p_endpos->x = v72;
    trace->endpos.z = v71;
    trace->endpos.y = v73;
    trace->lastEdge.edgeNum = edgeNum;
    trace->lastEdge.edgePoint.y = v73;
    trace->lastEdge.edgePoint.z = v71;
    v39->x = v72;
    v75 = &this->areas.list[v56];
    num = this->visitedAreas.num;
    v129.d = -(float)((float)((float)b * trace->endpos.y)
                    + (float)((float)((float)v59 * trace->endpos.x) + (float)((float)c * trace->endpos.z)));
    value = (unsigned __int16)v75->reach.value;
    v78 = (__int16)value;
    if ( (value & 0x8000u) != 0 )
      goto LABEL_31;
    while ( 1 )
    {
      v79 = &this->reachabilities.list[v78];
      if ( (v79->travelFlags & travelFlags) == 0 )
        goto LABEL_43;
      v80 = ~travelFlags;
      if ( (~travelFlags & v79->travelFlags) != 0 )
        goto LABEL_43;
      v81 = (char *)this->areas.list + 8 * v79->toAreaNum + 8 * __ROL4__(v79->toAreaNum, 2);
      maxReachIndices = *(_DWORD *)v81 & travelFlags;
      if ( maxReachIndices == 0 || (*(_DWORD *)v81 & v80) != 0 || *((unsigned __int16 *)v81 + 2) >> 15 != 0 )
        goto LABEL_43;
      reachIndices = trace->reachIndices;
      if ( reachIndices != nullptr )
      {
        numReachIndices = trace->numReachIndices;
        maxReachIndices = trace->maxReachIndices;
        if ( numReachIndices < maxReachIndices )
        {
          reachIndices[numReachIndices].value = value;
          reachIndices = (idIndex<short,enum invalidReachability_t> *)(trace->numReachIndices + 1);
          trace->numReachIndices = (int)reachIndices;
        }
      }
      idAAS2File::FloodAddVisitedArea(
        this,
        areaNum: v79->toAreaNum,
        a3: v70,
        a4: v69,
        a5: v80,
        a6: value,
        a7: maxReachIndices,
        a8: (int)reachIndices,
        a9: v120,
        a10: v121,
        a11: v122,
        a12: v123,
        a13: v124,
        a14: v125);
      if ( allowFloorNormalChange )
      {
        v85 = &this->trees.list[(int)idAAS2File::GetTreeForArea(
                                       this: (idAAS2File *)&v127,
                                       result: (idIndex<int,enum invalidAASTree_t> *)this,
                                       areaNum: v79->toAreaNum)->__vftable];
        v86 = v85->floorNormal.x;
        if ( v86 != v53 || v85->floorNormal.y != v55 || (v87 = 1, v85->floorNormal.z != v54) )
          v87 = 0;
        if ( v87 == 0 )
          break;
      }
      idAAS2File::GetFloorEdgeSplitPoints(
        this,
        nearest: v134,
        furthest: &v133,
        areaNum: v79->toAreaNum,
        pathPlane: &v130,
        nearPlane: &v129);
      if ( v134[0].dist < 1.0e30 && v133.dist >= -0.1 )
      {
        v103 = p_endpos->x;
        v104 = trace->endpos.y;
        v105 = v79->travelFlags & 0x200000;
        v106 = trace->endpos.z;
        v107 = (float)(trace->endpos.y - v134[0].point.y);
        v108 = (float)(trace->endpos.z - v134[0].point.z);
        v128.x = p_endpos->x - v134[0].point.x;
        v128.y = v107;
        v128.z = v108;
        if ( v105 != 0 && __fabs(v133.dist) < __fabs(v134[0].dist) )
        {
          v128.x = (float)v103 - v133.point.x;
          v128.y = (float)v104 - v133.point.y;
          v128.z = (float)v106 - v133.point.z;
        }
        idVec3::FixDenormals(this: &v128);
        v109 = (float)((float)v53
                     * (float)((float)(v128.y * (float)v55)
                             + (float)((float)(v128.x * (float)v53) + (float)(v128.z * (float)v54))));
        if ( v105 != 0
          || (v110 = (float)((float)v55
                           * (float)((float)(v128.y * (float)v55)
                                   + (float)((float)(v128.x * (float)v53) + (float)(v128.z * (float)v54)))),
              v111 = (float)((float)v54
                           * (float)((float)(v128.y * (float)v55)
                                   + (float)((float)(v128.x * (float)v53) + (float)(v128.z * (float)v54)))),
              (float)((float)((float)v109 * (float)v109)
                    + (float)((float)((float)v111 * (float)v111) + (float)((float)v110 * (float)v110))) <= (double)(float)(this->settings.maxStepHeight * this->settings.maxStepHeight)) )
        {
          v112 = (float)(v128.y
                       - (float)((float)v55
                               * (float)((float)(v128.y * (float)v55)
                                       + (float)((float)(v128.x * (float)v53) + (float)(v128.z * (float)v54)))));
          v113 = (float)(v128.z
                       - (float)((float)v54
                               * (float)((float)(v128.y * (float)v55)
                                       + (float)((float)(v128.x * (float)v53) + (float)(v128.z * (float)v54)))));
          if ( (float)((float)((float)(v128.x - (float)v109) * (float)(v128.x - (float)v109))
                     + (float)((float)((float)v113 * (float)v113) + (float)((float)v112 * (float)v112))) <= 0.040000003
            || v105 != 0 )
          {
            goto LABEL_30;
          }
        }
      }
LABEL_43:
      value = (unsigned __int16)this->reachabilities.list[v78].next.value;
      v78 = (__int16)value;
      if ( (value & 0x8000u) != 0 )
        goto LABEL_31;
    }
    v88 = start->x;
    v89 = start->y;
    v90 = (float)(end->x - start->x);
    v91 = start->z;
    v92 = v85->floorNormal.z;
    v93 = (float)((float)(end->z - start->z) * v85->floorNormal.x);
    v94 = (float)((float)((float)(end->z - start->z) * v85->floorNormal.y)
                - (float)((float)(end->y - start->y) * v85->floorNormal.z));
    v132.c = (float)((float)(end->y - start->y) * v85->floorNormal.x)
           - (float)(v85->floorNormal.y * (float)(end->x - start->x));
    v132.a = v94;
    v132.b = (float)((float)v92 * (float)v90) - (float)v93;
    idPlane::Normalize(this: &v132, fixDegenerate: true);
    v95 = v85->floorNormal.z;
    v96 = (float)(v132.c * v85->floorNormal.y);
    v97 = (float)((float)(v132.c * (float)v86) - (float)(v85->floorNormal.z * v132.a));
    v131.c = (float)(v85->floorNormal.y * v132.a) - (float)(v132.b * (float)v86);
    v131.b = v97;
    v131.a = (float)(v132.b * (float)v95) - (float)v96;
    v132.d = -(float)((float)(v132.a * (float)v88) + (float)((float)(v132.c * (float)v91) + (float)(v132.b * (float)v89)));
    idPlane::Normalize(this: &v131, fixDegenerate: true);
    toAreaNum = v79->toAreaNum;
    v131.d = -(float)((float)(v131.b * trace->endpos.y)
                    + (float)((float)(v131.a * trace->endpos.x) + (float)(v131.c * trace->endpos.z)));
    idAAS2File::GetFloorEdgeSplitPoints(
      this,
      nearest: v134,
      furthest: &v133,
      areaNum: toAreaNum,
      pathPlane: &v132,
      nearPlane: &v131);
    if ( v134[0].dist >= 1.0e30 || v133.dist < 0.1 )
      goto LABEL_43;
    v53 = v85->floorNormal.x;
    v55 = v85->floorNormal.y;
    v54 = v85->floorNormal.z;
    v129 = v131;
    v130 = v132;
    c = v131.c;
    b = v131.b;
    v59 = v131.a;
LABEL_30:
    v56 = v79->toAreaNum;
LABEL_31:
    if ( v78 != -1 )
    {
      idAAS2File::FloodClearVisitedAreas(this, offset: num);
      if ( trace->firstEdge.edgeNum == 0 )
      {
        v99 = v134[0].edgeNum;
        v100 = v134[0].point.x;
        v101 = v134[0].point.y;
        trace->firstEdge.toAreaNum = v56;
        v102 = v134[0].point.z;
        trace->firstEdge.edgeNum = v99;
        p_edgePoint->x = v100;
        trace->firstEdge.edgePoint.y = v101;
        trace->firstEdge.edgePoint.z = v102;
      }
      continue;
    }
    break;
  }
  v114 = (float)(end->y - start->y);
  v115 = (float)(end->z - start->z);
  v116 = (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
               + (float)((float)((float)v115 * (float)v115) + (float)((float)v114 * (float)v114)));
  if ( __fabs(v116) <= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    trace->fraction = 0.0;
  }
  else
  {
    v118 = (float)(trace->endpos.z - start->z);
    if ( a28 != 0 )
      v118 = 0.0;
    v117 = (float)(trace->endpos.y - start->y);
    trace->fraction = __fsqrts((float)((float)((float)((float)(p_endpos->x - start->x) * (float)(p_endpos->x - start->x))
                                             + (float)((float)((float)v118 * (float)v118)
                                                     + (float)((float)v117 * (float)v117)))
                                     / (float)v116));
  }
LABEL_51:
  trace->lastEdge.toAreaNum = v56;
  idAAS2File::FloodClearVisitedAreas(this, offset: 0);
  return 1;
}


// ========================================================================
// `dynamic initializer for 'aas_timeClipGridToAreas''
// EA  : 0x833350E0
// RVA : 0x013350E0
// PDB : w:\tech5\engine\aas2file\aas2file_sample.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_timeClipGridToAreas__()
{
  idCVar::idCVar(
    this: &aas_timeClipGridToAreas,
    name: "aas_timeClipGridToAreas",
    value: "0",
    flags: 1,
    description: "Time clip grid to areas.  0 - diable, 1 - enable.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_timeClipGridToAreas__);
}

