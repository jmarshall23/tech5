
// ========================================================================
// ?R_CullFoliageBoundsToMVP@@YA_NQAY02$$CBFPBMAAVidBounds@@@Z
// EA  : 0x827D72A0
// RVA : 0x007D72A0
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegather.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall R_CullFoliageBoundsToMVP(
        const __int16 (*bounds)[3],
        const float *mvp,
        idBounds *floatBounds,
        int a4,
        __int64 a5)
{
  int v5; // r2 OVERLAPPED
  int v7; // r3
  float *p_y; // r4
  int v9; // r11
  int v10; // r3
  int v11; // r8
  __int64 v12; // r7 OVERLAPPED
  double v13; // fp1
  double v14; // fp24
  double v15; // fp20
  double v16; // fp31
  double v17; // fp30
  double v18; // fp23
  double v19; // fp19
  double v20; // fp29
  double v21; // fp18
  double v22; // fp28
  double v23; // fp22
  double v24; // fp27
  double v25; // fp17
  double v26; // fp26
  double v27; // fp21
  double v28; // fp25
  float *v29; // r8
  int i; // r7
  float *v31; // r9
  int j; // ctr
  double v33; // fp0
  double v34; // fp13
  double v35; // fp11
  double v36; // fp10
  double v37; // fp12

  v7 = (*bounds)[0];
  HIDWORD(v12) = &floatBounds->b[0].z;
  floatBounds->b[0].x = (float)*(__int64 *)(&v5 - 1);
  LODWORD(a5) = (*bounds)[3];
  v9 = 0;
  floatBounds->b[1].x = (float)a5;
  LODWORD(v12) = (*bounds)[1];
  v10 = 2;
  floatBounds->b[0].y = (float)v12;
  v11 = (*bounds)[4];
  floatBounds->b[1].y = (float)*(__int64 *)((char *)&v12 - 4);
  LODWORD(v12) = (*bounds)[2];
  floatBounds->b[0].z = (float)v12;
  LODWORD(v12) = (*bounds)[5];
  floatBounds->b[1].z = (float)v12;
  v13 = mvp[2];
  v14 = mvp[1];
  v15 = *mvp;
  v16 = mvp[3];
  v17 = mvp[6];
  v18 = mvp[5];
  v19 = mvp[4];
  v20 = mvp[7];
  v21 = mvp[8];
  v22 = mvp[10];
  v23 = mvp[9];
  v24 = mvp[11];
  v25 = mvp[12];
  v26 = mvp[14];
  v27 = mvp[13];
  v28 = mvp[15];
  p_y = &floatBounds->b[0].y;
  do
  {
    v29 = p_y;
    for ( i = 2; i != 0; --i )
    {
      v31 = (float *)HIDWORD(v12);
      for ( j = 2; j != 0; --j )
      {
        v33 = (float)((float)((float)((float)((float)v26 * *v31) + (float)v28) + (float)((float)v27 * *v29))
                    + (float)((float)v25 * floatBounds->b[0].x));
        v34 = (float)((float)((float)((float)((float)v13 * *v31) + (float)v16)
                            + (float)((float)v15 * floatBounds->b[0].x))
                    + (float)((float)v14 * *v29));
        v35 = (float)((float)((float)((float)((float)v17 * *v31) + (float)v20)
                            + (float)((float)v19 * floatBounds->b[0].x))
                    + (float)((float)v18 * *v29));
        v36 = (float)((float)((float)((float)((float)v22 * *v31) + (float)v24) + (float)((float)v23 * *v29))
                    + (float)((float)v21 * floatBounds->b[0].x));
        v37 = -v33;
        if ( v34 > -v33 )
          v9 |= 1u;
        if ( v34 < v33 )
          v9 |= 2u;
        if ( v35 > v37 )
          v9 |= 4u;
        if ( v35 < v33 )
          v9 |= 8u;
        if ( v36 > v37 )
          v9 |= 0x10u;
        if ( v36 < v33 )
          v9 |= 0x20u;
        v31 += 3;
      }
      v29 += 3;
    }
    --v10;
    floatBounds = (idBounds *)((char *)floatBounds + 12);
  }
  while ( v10 != 0 );
  return v9 != 63;
}


// ========================================================================
// ?SortInfluenceSphereStackFront@@YAHHHPBUinfluenceSphere_t@@HPAHH@Z
// EA  : 0x827D74B0
// RVA : 0x007D74B0
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegather.cpp
// ========================================================================

int __fastcall SortInfluenceSphereStackFront(
        int planeType,
        int planeDist,
        const influenceSphere_t *influenceSpheres,
        int stackSize,
        int *stack,
        int stackOffset)
{
  __int64 v6; // r10
  int result; // r3
  int v8; // r31
  int *v9; // r11
  double v10; // fp0
  int v11; // r6
  int *v12; // r8
  int v13; // r9

  HIDWORD(v6) = planeType;
  result = stackOffset;
  v8 = stackSize;
  if ( stackOffset < stackSize )
  {
    LODWORD(v6) = planeDist;
    v9 = &stack[stackOffset];
    v10 = (float)v6;
    v12 = &stack[stackSize];
    v11 = 4 * HIDWORD(v6);
    do
    {
      if ( (float)(*(float *)((char *)&influenceSpheres[*v9].center.x + v11) + influenceSpheres[*v9].outerRadius) <= v10 )
      {
        ++result;
        ++v9;
      }
      else
      {
        --v12;
        --v8;
        v13 = *v9;
        *v9 = *v12;
        *v12 = v13;
      }
    }
    while ( result < v8 );
  }
  return result;
}


// ========================================================================
// ?SortInfluenceSphereStackBack@@YAHHHPBUinfluenceSphere_t@@HPAHH@Z
// EA  : 0x827D7548
// RVA : 0x007D7548
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegather.cpp
// ========================================================================

int __fastcall SortInfluenceSphereStackBack(
        int planeType,
        int planeDist,
        const influenceSphere_t *influenceSpheres,
        int stackSize,
        int *stack,
        int stackOffset)
{
  __int64 v6; // r10
  int result; // r3
  int v8; // r31
  int *v9; // r11
  double v10; // fp0
  int v11; // r6
  int *v12; // r8
  int v13; // r9

  HIDWORD(v6) = planeType;
  result = stackOffset;
  v8 = stackSize;
  if ( stackOffset < stackSize )
  {
    LODWORD(v6) = planeDist;
    v9 = &stack[stackOffset];
    v10 = (float)v6;
    v12 = &stack[stackSize];
    v11 = 4 * HIDWORD(v6);
    do
    {
      if ( (float)(*(float *)((char *)&influenceSpheres[*v9].center.x + v11) - influenceSpheres[*v9].outerRadius) >= v10 )
      {
        ++result;
        ++v9;
      }
      else
      {
        --v12;
        --v8;
        v13 = *v9;
        *v9 = *v12;
        *v12 = v13;
      }
    }
    while ( result < v8 );
  }
  return result;
}


// ========================================================================
// ?SortInfluenceSphereStack@@YAXHPAHH@Z
// EA  : 0x827D75E0
// RVA : 0x007D75E0
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegather.cpp
// ========================================================================

void __fastcall SortInfluenceSphereStack(int stackSize, int *stack, int stackOffset)
{
  int v3; // r9
  int v4; // r10
  int v5; // ctr
  int *v6; // r11
  int v7; // r7

  v3 = stackSize - 1;
  if ( stackOffset < stackSize - 1 )
  {
    v4 = v3 - stackOffset;
    do
    {
      v5 = v4;
      v6 = &stack[stackOffset];
      do
      {
        if ( *v6 > v6[1] )
        {
          v7 = *v6;
          *v6 = v6[1];
          v6[1] = v7;
        }
        ++v6;
        --v5;
      }
      while ( v5 != 0 );
      --v3;
      --v4;
    }
    while ( stackOffset < v3 );
  }
}


// ========================================================================
// ?GetFoliageRenderListForView_r@@YAXAAUfm_subTreeTreeNodePtrs_t@@AAUfm_subTreeBounds_t@@AAUfoliageGather_t@@IIII@Z
// EA  : 0x827D7638
// RVA : 0x007D7638
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegather.cpp
// ========================================================================

void __fastcall GetFoliageRenderListForView_r(
        fm_subTreeTreeNodePtrs_t *subTreePtrs,
        fm_subTreeBounds_t *bounds,
        foliageGather_t *gather,
        int nodeNum,
        __int64 numSmallFoliageAtLeaf,
        unsigned int stackOffset)
{
  fm_treeNode_t *v10; // r30
  int v11; // r8
  int v12; // r7
  int v13; // r11
  int v14; // ctr
  int v15; // r29
  unsigned int planeDist; // r4
  unsigned int v17; // r9
  foliageGather_t *v18; // r10
  unsigned int v19; // r23
  unsigned int v20; // r21
  unsigned int v21; // r6
  unsigned int v22; // r24
  const influenceSphere_t *influenceSpheres; // r5
  unsigned int influenceSphereStackSize; // r6
  int v25; // r3
  unsigned int v26; // r9
  __int16 *v27; // r8
  __int16 *v28; // r10
  int i; // ctr
  int *influenceSphereStack; // r7
  int v31; // r3
  unsigned int v32; // r30
  const __int16 *v33; // r3
  int v34; // r29
  unsigned int v35; // r3
  unsigned __int16 v36; // r6
  unsigned int v37; // r11
  unsigned int maxInfluenceSphereIndices; // r8
  unsigned int numInfluenceSphereIndices; // r7
  unsigned int *v40; // r11
  int v41; // ctr
  unsigned int numFoliageIndices; // r8
  char *v43; // r10
  unsigned int v44; // r11
  unsigned int v45; // r30
  unsigned int v46; // r27
  unsigned int v47; // r8
  double v48; // fp13
  double v49; // fp0
  unsigned int v50; // r11
  int v51; // r7
  unsigned int v52; // ctr
  int v53; // r9
  __int16 v54; // [sp+5Eh] [-B2h] BYREF
  fm_subTreeBounds_t v55; // [sp+60h] [-B0h] BYREF
  idBounds v56; // [sp+70h] [-A0h] BYREF

  if ( (nodeNum & 0x8000) == 0 )
  {
    while ( 1 )
    {
      v10 = &subTreePtrs->treeNodes[nodeNum];
      v11 = 0;
      v12 = 0;
      v13 = 0;
      v14 = 2;
      v15 = v10->planeType & 3;
      planeDist = v10->planeDist;
      v17 = 8 * v15;
      do
      {
        v18 = (foliageGather_t *)((char *)gather + 2 * v17 + 2 * v13);
        v19 = v18->frustumVerts[0][0];
        v20 = v18->frustumVerts[0][1];
        v21 = gather->frustumVerts[v17 / 8][v13 + 2];
        v22 = gather->frustumVerts[v17 / 8][v13 + 3];
        v11 |= (((int)v22 >> 31) + (v22 >= planeDist) + (planeDist >> 31))
             | (((int)v21 >> 31) + (v21 >= planeDist) + (planeDist >> 31))
             | (((int)v20 >> 31) + (v20 >= planeDist) + (planeDist >> 31))
             | (((int)v19 >> 31) + (v19 >= planeDist) + (planeDist >> 31));
        v12 |= (((int)planeDist >> 31) + (planeDist >= v22) + (v22 >> 31))
             | (((int)planeDist >> 31) + (planeDist >= v21) + (v21 >> 31))
             | (((int)planeDist >> 31) + (planeDist >= v20) + (v20 >> 31))
             | (((int)planeDist >> 31) + (planeDist >= v19) + (v19 >> 31));
        v13 += 4;
        --v14;
      }
      while ( v14 != 0 );
      if ( v11 == 0 )
        break;
      influenceSpheres = gather->influenceSpheres;
      influenceSphereStackSize = gather->influenceSphereStackSize;
      v25 = v10->planeType & 3;
      if ( v12 != 0 )
      {
        v26 = SortInfluenceSphereStackFront(
                planeType: v25,
                planeDist,
                influenceSpheres,
                stackSize: influenceSphereStackSize,
                stack: gather->influenceSphereStack,
                stackOffset);
        v27 = &v54;
        v28 = &bounds[-1].b[1][3];
        for ( i = 8; i != 0; --i )
          *++v27 = *++v28;
        v55.b[0][v15] = v10->planeDist;
        GetFoliageRenderListForView_r(
          subTreePtrs,
          bounds: &v55,
          gather,
          nodeNum: v10->children[0],
          numFoliageAtLeaf: (v10->planeType >> 2) & 7,
          numSmallFoliageAtLeaf: (unsigned __int8)v10->planeType >> 5,
          stackOffset: v26);
        influenceSphereStack = gather->influenceSphereStack;
        planeDist = v10->planeDist;
LABEL_12:
        v31 = SortInfluenceSphereStackBack(
                planeType: v15,
                planeDist,
                influenceSpheres: gather->influenceSpheres,
                stackSize: gather->influenceSphereStackSize,
                stack: influenceSphereStack,
                stackOffset);
        bounds->b[1][v15] = v10->planeDist;
        nodeNum = v10->children[1];
        goto LABEL_13;
      }
      v31 = SortInfluenceSphereStackFront(
              planeType: v25,
              planeDist,
              influenceSpheres,
              stackSize: influenceSphereStackSize,
              stack: gather->influenceSphereStack,
              stackOffset);
      bounds->b[0][v15] = v10->planeDist;
      nodeNum = v10->children[0];
LABEL_13:
      stackOffset = v31;
      if ( (nodeNum & 0x8000) != 0 )
        goto LABEL_14;
    }
    if ( v12 == 0 )
      return;
    influenceSphereStack = gather->influenceSphereStack;
    goto LABEL_12;
  }
LABEL_14:
  v32 = (16 * nodeNum) & 0x7FFF0;
  v33 = (const __int16 *)((char *)subTreePtrs->leafInfo + v32);
  v34 = *((unsigned __int8 *)v33 + 15) + *((unsigned __int8 *)v33 + 14);
  if ( !R_CullFoliageBoundsToMVP(
          bounds: (const __int16 (*)[3])v33,
          mvp: gather->mvpMatrix,
          floatBounds: &v56,
          a4: nodeNum,
          a5: numSmallFoliageAtLeaf) )
  {
    v35 = gather->influenceSphereStackSize;
    v36 = 0;
    if ( stackOffset < v35 && gather->numInfluenceSphereIndices + 1 < gather->maxInfluenceSphereIndices )
    {
      SortInfluenceSphereStack(stackSize: v35, stack: gather->influenceSphereStack, stackOffset);
      v37 = gather->influenceSphereStackSize;
      maxInfluenceSphereIndices = gather->maxInfluenceSphereIndices;
      numInfluenceSphereIndices = gather->numInfluenceSphereIndices;
      if ( v37 - stackOffset + 1 > maxInfluenceSphereIndices - numInfluenceSphereIndices )
        v37 = maxInfluenceSphereIndices - numInfluenceSphereIndices + stackOffset - 1;
      if ( stackOffset < v37 )
      {
        v41 = v37 - stackOffset;
        v40 = &gather->influenceSphereStackSize + stackOffset;
        do
        {
          gather->influenceSphereIndices[gather->numInfluenceSphereIndices++] = *++v40;
          --v41;
        }
        while ( v41 != 0 );
      }
      gather->influenceSphereIndices[gather->numInfluenceSphereIndices++] = -1;
    }
    numFoliageIndices = gather->numFoliageIndices;
    v43 = (char *)subTreePtrs->leafInfo + v32;
    v44 = *((unsigned __int16 *)v43 + 6);
    if ( v34 > gather->maxFoliageIndices - numFoliageIndices )
      v34 = gather->maxFoliageIndices - numFoliageIndices;
    v45 = v44 + v34;
    v46 = (unsigned __int8)v43[15] + v44;
    v47 = *((unsigned __int16 *)v43 + 6);
    v48 = (float)(gather->foliageSmallFadeDistMax - gather->foliageStartFadeDist);
    v49 = (float)((float)((float)((float)((float)(gather->viewDir.x
                                                * (float)((float)((float)(v56.b[0].x + v56.b[1].x) * (float)0.5)
                                                        - gather->viewOrg.x))
                                        + (float)((float)(gather->viewDir.z
                                                        * (float)((float)((float)(v56.b[0].z + v56.b[1].z) * (float)0.5)
                                                                - gather->viewOrg.z))
                                                + (float)(gather->viewDir.y
                                                        * (float)((float)((float)(v56.b[0].y + v56.b[1].y) * (float)0.5)
                                                                - gather->viewOrg.y))))
                                - (float)__fabs((float)(gather->viewDir.x
                                                      * (float)(v56.b[1].x
                                                              - (float)((float)(v56.b[0].x + v56.b[1].x) * (float)0.5)))))
                        - (float)__fabs((float)(gather->viewDir.y
                                              * (float)(v56.b[1].y
                                                      - (float)((float)(v56.b[0].y + v56.b[1].y) * (float)0.5)))))
                - (float)__fabs((float)(gather->viewDir.z
                                      * (float)(v56.b[1].z - (float)((float)(v56.b[0].z + v56.b[1].z) * (float)0.5)))));
    if ( v44 < v44 + v34 )
    {
      if ( v34 >= 4 )
      {
        v51 = 1664525 * v44 + 547180;
        v50 = v44 + 2;
        do
        {
          if ( v49 <= gather->foliageStartFadeDist
            || v47 >= v46
            || v49 <= (float)((float)((float)((float)((float)(COERCE_FLOAT((v51 - 1664525) & 0x7FFFFF | 0x3F800000)
                                                            - (float)1.0)
                                                    * (float)(COERCE_FLOAT((v51 - 1664525) & 0x7FFFFF | 0x3F800000)
                                                            - (float)1.0))
                                            * (float)(COERCE_FLOAT((v51 - 1664525) & 0x7FFFFF | 0x3F800000) - (float)1.0))
                                    * (float)v48)
                            + gather->foliageStartFadeDist) )
          {
            gather->foliageIndices[gather->numFoliageIndices].foliageIndex = v47;
            gather->foliageIndices[gather->numFoliageIndices++].influenceSphereOffset = v36;
          }
          if ( v49 <= gather->foliageStartFadeDist
            || v50 - 1 >= v46
            || v49 <= (float)((float)((float)((float)((float)(COERCE_FLOAT(v51 & 0x7FFFFF | 0x3F800000) - (float)1.0)
                                                    * (float)(COERCE_FLOAT(v51 & 0x7FFFFF | 0x3F800000) - (float)1.0))
                                            * (float)(COERCE_FLOAT(v51 & 0x7FFFFF | 0x3F800000) - (float)1.0))
                                    * (float)v48)
                            + gather->foliageStartFadeDist) )
          {
            gather->foliageIndices[gather->numFoliageIndices].foliageIndex = v50 - 1;
            gather->foliageIndices[gather->numFoliageIndices++].influenceSphereOffset = v36;
          }
          if ( v49 <= gather->foliageStartFadeDist
            || v50 >= v46
            || v49 <= (float)((float)((float)((float)((float)(COERCE_FLOAT((v51 + 1664525) & 0x7FFFFF | 0x3F800000)
                                                            - (float)1.0)
                                                    * (float)(COERCE_FLOAT((v51 + 1664525) & 0x7FFFFF | 0x3F800000)
                                                            - (float)1.0))
                                            * (float)(COERCE_FLOAT((v51 + 1664525) & 0x7FFFFF | 0x3F800000) - (float)1.0))
                                    * (float)v48)
                            + gather->foliageStartFadeDist) )
          {
            gather->foliageIndices[gather->numFoliageIndices].foliageIndex = v50;
            gather->foliageIndices[gather->numFoliageIndices++].influenceSphereOffset = v36;
          }
          if ( v49 <= gather->foliageStartFadeDist
            || v50 + 1 >= v46
            || v49 <= (float)((float)((float)((float)((float)(COERCE_FLOAT((v51 + 3329050) & 0x7FFFFF | 0x3F800000)
                                                            - (float)1.0)
                                                    * (float)(COERCE_FLOAT((v51 + 3329050) & 0x7FFFFF | 0x3F800000)
                                                            - (float)1.0))
                                            * (float)(COERCE_FLOAT((v51 + 3329050) & 0x7FFFFF | 0x3F800000) - (float)1.0))
                                    * (float)v48)
                            + gather->foliageStartFadeDist) )
          {
            gather->foliageIndices[gather->numFoliageIndices].foliageIndex = v50 + 1;
            gather->foliageIndices[gather->numFoliageIndices++].influenceSphereOffset = v36;
          }
          v47 += 4;
          v50 += 4;
          v51 += 6658100;
        }
        while ( v47 < v45 - 3 );
      }
      if ( v47 < v45 )
      {
        v52 = v45 - v47;
        v53 = 1664525 * v47 - 1117345;
        do
        {
          if ( v49 <= gather->foliageStartFadeDist
            || v47 >= v46
            || v49 <= (float)((float)((float)((float)((float)(COERCE_FLOAT(v53 & 0x7FFFFF | 0x3F800000) - (float)1.0)
                                                    * (float)(COERCE_FLOAT(v53 & 0x7FFFFF | 0x3F800000) - (float)1.0))
                                            * (float)(COERCE_FLOAT(v53 & 0x7FFFFF | 0x3F800000) - (float)1.0))
                                    * (float)v48)
                            + gather->foliageStartFadeDist) )
          {
            gather->foliageIndices[gather->numFoliageIndices].foliageIndex = v47;
            gather->foliageIndices[gather->numFoliageIndices++].influenceSphereOffset = v36;
          }
          ++v47;
          v53 += 1664525;
          --v52;
        }
        while ( v52 != 0 );
      }
    }
  }
}


// ========================================================================
// ?GatherFoliageIndicesForSubTree@@YAXPBUdeferredFoliageGatherParms_t@@AAH1@Z
// EA  : 0x827D7D30
// RVA : 0x007D7D30
// PDB : w:\tech5\engine\models\foliage\jobs\foliagegather.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall GatherFoliageIndicesForSubTree(
        const deferredFoliageGatherParms_t *parms,
        __int64 numInfluenceSphereIndices)
{
  int v2; // r2 OVERLAPPED
  unsigned int *v3; // r29
  unsigned int *v5; // r30
  const foliageRenderView_t *viewData; // r11
  __int64 maxFoliageHeight; // r7
  double nearDist; // fp0
  double y; // fp10
  double v10; // fp7
  double v11; // fp9
  double v12; // fp2
  double v13; // fp5
  double x; // fp4
  double v15; // fp30
  double v16; // fp8
  double z; // fp25
  double v18; // fp29
  double v19; // fp31
  double v20; // fp27
  double v21; // fp20
  double v22; // fp23
  double v23; // fp24
  double v24; // fp13
  double v25; // fp0
  double v26; // fp22
  double v27; // fp28
  int v28; // r3
  double v29; // fp17
  double v30; // fp16
  double v31; // fp11
  double v32; // fp3
  double v33; // fp14
  double v34; // fp15
  double v35; // fp4
  double v36; // fp7
  double v37; // fp6
  double v38; // fp30
  double v39; // fp23
  double v40; // fp2
  double v41; // fp31
  double v42; // fp21
  double v43; // fp9
  double v44; // fp29
  double v45; // fp1
  double v46; // fp0
  double v47; // fp13
  double v48; // fp31
  double v49; // fp7
  double v50; // fp9
  double v51; // fp2
  double v52; // fp3
  double v53; // fp20
  double v54; // fp26
  double v55; // fp29
  double v56; // fp28
  double v57; // fp18
  double v58; // fp8
  double v59; // fp5
  double v60; // fp1
  double v61; // fp10
  double v62; // fp12
  double v63; // fp25
  double v64; // fp22
  double v65; // fp18
  double v66; // fp23
  double v67; // fp21
  double v68; // fp19
  double v69; // fp13
  double v70; // fp0
  double v71; // fp14
  double v72; // fp29
  double v73; // fp11
  double v74; // fp15
  double v75; // fp8
  double v76; // fp7
  __int16 *v77; // r8
  double v78; // fp3
  float *v79; // r9
  double v80; // fp12
  double v81; // fp2
  double v82; // fp23
  double v83; // fp5
  double v84; // fp4
  double v85; // fp17
  double v86; // fp16
  double v87; // fp19
  double v88; // fp30
  double v89; // fp27
  double v90; // fp0
  double v91; // fp13
  double v92; // fp26
  double v93; // fp6
  double v94; // fp25
  double v95; // fp28
  double v96; // fp5
  int v97; // ctr
  double v98; // fp31
  double v99; // fp13
  __int16 v100; // r11
  double v101; // fp0
  int v102; // r11
  double v103; // fp0
  int v104; // r11
  const fm_subTreeBounds_t *subTreeBounds; // r11
  int v106; // r10
  __int16 v107; // r4
  __int16 v108; // r28
  int v109; // r3
  __int16 v110; // r27
  int v111; // r3 OVERLAPPED
  __int64 v112; // r9
  __int64 v113; // fp0
  __int64 v114; // fp11
  __int64 v115; // r5 OVERLAPPED
  double v116; // fp8
  float *v117; // r11
  unsigned int maxFoliageIndices; // r4
  unsigned int maxInfluenceSphereIndices; // r3
  _WORD *v120; // r8
  int v121; // ctr
  double foliageStartFadeDist; // fp13
  const fm_subTreeBounds_t *v123; // r10
  const fm_subTreeTreeNodes_t *subTreeTreeNodes; // r11
  __int16 *v125; // r9
  unsigned int v126; // r8
  float v127; // [sp+50h] [-610h]
  float v128; // [sp+50h] [-610h]
  float v129; // [sp+54h] [-60Ch]
  float v130; // [sp+54h] [-60Ch]
  float v131; // [sp+54h] [-60Ch]
  float v132; // [sp+54h] [-60Ch]
  float v133; // [sp+58h] [-608h]
  float v134; // [sp+58h] [-608h]
  float v135; // [sp+58h] [-608h]
  float v136; // [sp+5Ch] [-604h]
  float v137; // [sp+5Ch] [-604h]
  float v138; // [sp+5Ch] [-604h]
  float farDist; // [sp+60h] [-600h]
  float v140; // [sp+60h] [-600h]
  float v141; // [sp+60h] [-600h]
  float v142; // [sp+60h] [-600h]
  float v143; // [sp+64h] [-5FCh]
  float v144; // [sp+64h] [-5FCh]
  float v145; // [sp+64h] [-5FCh]
  float v146; // [sp+68h] [-5F8h]
  float v147; // [sp+68h] [-5F8h]
  float v148; // [sp+68h] [-5F8h]
  float v149; // [sp+68h] [-5F8h]
  float v150; // [sp+6Ch] [-5F4h]
  float v151; // [sp+6Ch] [-5F4h]
  float v152; // [sp+70h] [-5F0h]
  float v153; // [sp+70h] [-5F0h]
  float v154; // [sp+70h] [-5F0h]
  float v155; // [sp+74h] [-5ECh]
  float v156; // [sp+74h] [-5ECh]
  float v157; // [sp+78h] [-5E8h]
  float v158; // [sp+78h] [-5E8h]
  float v159; // [sp+78h] [-5E8h]
  float v160; // [sp+7Ch] [-5E4h] BYREF
  fm_subTreeBounds_t v161; // [sp+80h] [-5E0h] BYREF
  __int64 v162; // [sp+90h] [-5D0h]
  __int64 v163; // [sp+98h] [-5C8h]
  __int64 v164; // [sp+A0h] [-5C0h]
  __int64 v165; // [sp+A8h] [-5B8h]
  fm_subTreeTreeNodePtrs_t v166; // [sp+B0h] [-5B0h] BYREF
  float v167; // [sp+C0h] [-5A0h]
  float v168[23]; // [sp+C4h] [-59Ch] BYREF
  foliageGather_t v169; // [sp+120h] [-540h] BYREF

  v3 = (unsigned int *)numInfluenceSphereIndices;
  *(_DWORD *)HIDWORD(numInfluenceSphereIndices) = 0;
  *(_DWORD *)numInfluenceSphereIndices = 0;
  v5 = (unsigned int *)HIDWORD(numInfluenceSphereIndices);
  parms->foliageCount->subTreeFoliageCount = 0;
  parms->foliageCount->pad[0] = 0;
  parms->foliageCount->pad[1] = 0;
  parms->foliageCount->pad[2] = 0;
  if ( parms->subTreeTreeNodes->numTreeNodes != 0 )
  {
    viewData = parms->viewData;
    maxFoliageHeight = (unsigned int)parms->maxFoliageHeight;
    LODWORD(numInfluenceSphereIndices) = parms->maxFoliageHeight;
    nearDist = parms->viewData->nearDist;
    *(_QWORD *)&v161.b[0][0] = maxFoliageHeight;
    y = viewData->viewLeft.y;
    v10 = (float)(viewData->viewLeft.y * (float)nearDist);
    v165 = numInfluenceSphereIndices;
    v11 = (float)(viewData->viewFwd.x * (float)nearDist);
    v12 = (float)(viewData->viewFwd.z * (float)nearDist);
    v13 = viewData->fov[0];
    x = viewData->viewOrg.x;
    v15 = (float)(viewData->viewUp.y * (float)nearDist);
    v16 = viewData->viewUp.x;
    z = viewData->viewUp.z;
    v18 = viewData->fov[1];
    v19 = (float)(viewData->viewUp.x * (float)nearDist);
    v129 = viewData->viewFwd.x;
    v20 = viewData->viewOrg.z;
    v133 = nearDist;
    v21 = (float)(viewData->viewUp.z * (float)nearDist);
    v146 = viewData->viewLeft.x;
    farDist = viewData->farDist;
    v152 = v146 * (float)nearDist;
    v157 = viewData->viewUp.y;
    v143 = (float)v10 * viewData->fov[0];
    v136 = (float)(viewData->viewLeft.z * (float)nearDist) * viewData->fov[0];
    v22 = (float)(viewData->viewOrg.y + (float)(viewData->viewFwd.y * (float)nearDist));
    v23 = (float)((float)(viewData->viewUp.z * (float)nearDist) * viewData->fov[1]);
    v24 = (float)((float)(viewData->viewOrg.z + (float)(viewData->viewFwd.z * (float)nearDist)) + v136);
    v26 = (float)(viewData->viewOrg.z + (float)(viewData->viewFwd.z * (float)nearDist));
    v27 = (float)((float)((float)(viewData->viewOrg.x + (float)(v129 * (float)nearDist))
                        + (float)(v152 * viewData->fov[0]))
                + (float)((float)(viewData->viewUp.x * (float)nearDist) * viewData->fov[1]));
    v28 = maxFoliageHeight;
    v29 = (float)((float)(viewData->viewUp.x * (float)nearDist) * viewData->fov[1]);
    v30 = (float)((float)(v157 * (float)nearDist) * viewData->fov[1]);
    v25 = (float)((float)((float)(viewData->viewOrg.y + (float)(viewData->viewFwd.y * (float)nearDist))
                        + (float)((float)((float)y * (float)nearDist) * viewData->fov[0]))
                + (float)((float)(v157 * (float)nearDist) * viewData->fov[1]));
    *(float *)&v164 = v19;
    *(_QWORD *)&v161.b[0][0] = *(_QWORD *)(&v2 - 1);
    v31 = (float)((float)((float)x + (float)v11) - (float)(v152 * (float)v13));
    v155 = x;
    v32 = (float)((float)v22 - v143);
    v33 = v133;
    v34 = (float)((float)v21 * (float)v18);
    v36 = (float)((float)v22 - (float)((float)v10 * (float)v13));
    v37 = viewData->viewOrg.y;
    v38 = (float)((float)v15 * (float)v18);
    v39 = viewData->viewFwd.z;
    v40 = (float)((float)((float)v20 + (float)v12) - v136);
    v35 = farDist;
    *(float *)&v163 = viewData->viewOrg.z;
    v41 = (float)((float)v19 * (float)v18);
    v160 = v37;
    v127 = v13;
    v42 = viewData->viewFwd.y;
    v144 = v11;
    *(float *)&v162 = v18;
    v43 = viewData->viewLeft.y;
    v44 = viewData->viewLeft.z;
    *(_QWORD *)&v161.b[0][0] = *(_QWORD *)(&v2 - 1);
    v168[1] = (float)((float)v24 + (float)v23) + (float)((float)z * (float)maxFoliageHeight);
    v168[0] = (float)v25 + (float)(v157 * (float)maxFoliageHeight);
    v168[3] = (float)((float)v32 + (float)v30) + (float)(v157 * (float)maxFoliageHeight);
    v168[2] = (float)((float)v31 + (float)v29) + (float)((float)v16 * (float)maxFoliageHeight);
    v168[6] = (float)((float)v36 - (float)v38) - (float)(v157 * (float)maxFoliageHeight);
    v167 = (float)v27 + (float)((float)v16 * (float)maxFoliageHeight);
    v168[4] = (float)((float)((float)v26 - v136) + (float)v34) + (float)((float)z * (float)maxFoliageHeight);
    v137 = v157;
    v168[5] = (float)((float)v31 - (float)v41) - (float)((float)v16 * (float)maxFoliageHeight);
    v168[7] = (float)((float)v40 - (float)v34) - (float)((float)z * (float)maxFoliageHeight);
    v45 = (float)(v146 * farDist);
    v147 = v42;
    v46 = (float)((float)v43 * v133);
    v47 = (float)((float)v44 * v133);
    v134 = v16;
    v48 = z;
    v49 = (float)((float)v43 * farDist);
    v50 = (float)(v129 * farDist);
    v130 = v134 * farDist;
    v51 = v157;
    v52 = (float)((float)v44 * farDist);
    v140 = v39;
    v53 = v127;
    v54 = (float)((float)z * (float)v33);
    v55 = v152;
    v56 = (float)(v157 * (float)v33);
    v158 = viewData->viewOrg.z;
    v57 = *(float *)&v163;
    v58 = (float)(*(float *)&v163 + (float)(v140 * (float)v33));
    v59 = (float)((float)v45 * v127);
    v150 = viewData->viewOrg.y;
    *(float *)&v163 = v45;
    v60 = *(float *)&v162;
    v61 = (float)((float)v57 + (float)(v140 * (float)v35));
    v153 = *(float *)&v162;
    *(float *)&v162 = v155;
    v62 = (float)(v160 + (float)(v147 * (float)v35));
    v64 = (float)((float)z * (float)v35);
    v63 = viewData->viewLeft.y;
    v65 = v130;
    v66 = viewData->viewLeft.z;
    v67 = viewData->viewFwd.y;
    v68 = viewData->viewFwd.z;
    v69 = (float)((float)v58 + (float)((float)v47 * v127));
    v70 = (float)((float)(v160 + (float)(v147 * (float)v33)) + (float)((float)v46 * v127));
    v160 = v48;
    v148 = v35;
    v71 = (float)(*(float *)&v164 * (float)v60);
    v141 = v50;
    *(float *)&v164 = (float)v51 * (float)numInfluenceSphereIndices;
    v72 = (float)((float)(v155 + v144) + (float)((float)v55 * v127));
    v145 = *(float *)&v164;
    v73 = (float)((float)((float)(v155 + (float)v50) + (float)v59) + (float)(v130 * (float)v60));
    v74 = viewData->viewFwd.z;
    v75 = (float)((float)((float)v62 + (float)((float)v49 * v127))
                + (float)((float)((float)v51 * (float)v35) * (float)v60));
    v76 = (float)((float)((float)v61 + (float)((float)v52 * v127)) + (float)((float)v64 * (float)v60));
    v128 = v134 * (float)numInfluenceSphereIndices;
    v77 = &v169.frustumVerts[1][7];
    v78 = (float)((float)v63 * (float)v35);
    v79 = v168;
    v80 = (float)((float)v68 * (float)v35);
    v81 = (float)((float)v66 * (float)v35);
    v82 = v153;
    v83 = (float)(v137 * (float)v35);
    v85 = v148;
    v86 = (float)((float)((float)v67 * (float)v35) + v150);
    v84 = (float)(v160 * (float)v35);
    v151 = v160;
    v160 = v134;
    v135 = v130 * v153;
    v131 = (float)v48 * (float)numInfluenceSphereIndices;
    v87 = *(float *)&v164;
    v88 = (float)((float)v80 + v158);
    v89 = v155;
    v90 = (float)((float)v70 - (float)((float)v56 * (float)v60));
    *(float *)&v164 = v131;
    v91 = (float)((float)v69 - (float)((float)v54 * (float)v60));
    v92 = (float)(v155 + (float)v50);
    v159 = v78;
    v93 = v141;
    v94 = (float)(*(float *)&v163 * (float)v53);
    v156 = (float)v83 * v153;
    v142 = v83;
    *(float *)&v162 = v76;
    *(float *)&v165 = (float)v84 * v153;
    v154 = v137;
    v95 = (float)((float)v92 - (float)(*(float *)&v163 * (float)v53));
    *(float *)&v163 = (float)*(__int64 *)(&v2 - 1);
    v138 = viewData->viewOrg.y;
    *(float *)&v161.b[0][0] = *(float *)&v165;
    v96 = viewData->viewOrg.z;
    v169.viewOrg.x = v89;
    v97 = 8;
    v168[10] = (float)v91 - v131;
    v168[11] = (float)v73 + v128;
    v168[9] = (float)v90 - (float)v87;
    v168[12] = (float)v75 + v145;
    v168[13] = *(float *)&v162 + v131;
    v132 = v65;
    *(float *)&v164 = v160 * *(float *)&v163;
    *(float *)&v162 = v154 * *(float *)&v163;
    v168[8] = (float)((float)v72 - (float)v71) - v128;
    v98 = (float)(v151 * *(float *)&v163);
    *(float *)&v163 = v151 * *(float *)&v163;
    v169.viewOrg.y = viewData->viewOrg.y;
    v168[17] = (float)((float)((float)v92 - (float)v94) - (float)((float)v65 * (float)v82)) - *(float *)&v164;
    v168[20] = (float)((float)((float)((float)v89 + (float)v93) + (float)v94) - (float)(v132 * (float)v82))
             - *(float *)&v164;
    v168[15] = (float)((float)((float)v86 - (float)((float)v78 * (float)v53)) + v156) + *(float *)&v162;
    v168[14] = (float)((float)v95 + v135) + *(float *)&v164;
    v168[16] = (float)((float)((float)v88 - (float)((float)v81 * (float)v53)) + *(float *)&v165) + *(float *)&v163;
    v168[18] = (float)((float)((float)v86 - (float)((float)v78 * (float)v53)) - v156) - *(float *)&v162;
    v168[19] = (float)((float)((float)v88 - (float)((float)v81 * (float)v53)) - *(float *)&v165) - (float)v98;
    v169.viewOrg.z = viewData->viewOrg.z;
    v169.viewDir.x = viewData->viewFwd.x;
    v169.viewDir.y = viewData->viewFwd.y;
    v99 = viewData->viewFwd.z;
    v169.mvpMatrix = viewData->mvpMatrix.m;
    v168[21] = (float)((float)((float)((float)((float)v67 * v148) + v138) + (float)(v159 * (float)v53))
                     - (float)(v142 * (float)v82))
             - *(float *)&v162;
    v149 = v81;
    v169.viewDir.z = v99;
    v168[22] = (float)((float)((float)((float)((float)v74 * (float)v85) + (float)v96) + (float)(v149 * (float)v53))
                     - *(float *)&v165)
             - (float)v98;
    do
    {
      *(_DWORD *)&v161.b[0][2] = (int)*(v79 - 1);
      v100 = v161.b[0][3];
      if ( *(int *)&v161.b[0][2] >= -32768 )
      {
        if ( *(int *)&v161.b[0][2] > 0x7FFF )
          v100 = 0x7FFF;
      }
      else
      {
        v100 = 0x8000;
      }
      v101 = *v79;
      *(v77 - 15) = v100;
      *(_DWORD *)&v161.b[0][2] = (int)v101;
      v102 = (int)v101;
      if ( (int)v101 >= -32768 )
      {
        if ( v102 > 0x7FFF )
          LOWORD(v102) = 0x7FFF;
      }
      else
      {
        LOWORD(v102) = 0x8000;
      }
      v103 = v79[1];
      *(v77 - 7) = v102;
      *(_DWORD *)&v161.b[0][2] = (int)v103;
      v104 = (int)v103;
      if ( (int)v103 >= -32768 )
      {
        if ( v104 > 0x7FFF )
          LOWORD(v104) = 0x7FFF;
      }
      else
      {
        LOWORD(v104) = 0x8000;
      }
      *++v77 = v104;
      v79 += 3;
      --v97;
    }
    while ( v97 != 0 );
    subTreeBounds = parms->subTreeBounds;
    LODWORD(maxFoliageHeight) = HIDWORD(maxFoliageHeight);
    HIDWORD(v112) = parms->visibleInfluenceSpheres;
    v106 = HIDWORD(maxFoliageHeight);
    v107 = subTreeBounds->b[0][2];
    v108 = subTreeBounds->b[1][2];
    v109 = subTreeBounds->b[1][0];
    v110 = subTreeBounds->b[0][0];
    LODWORD(v115) = subTreeBounds->b[1][1];
    LOWORD(subTreeBounds) = subTreeBounds->b[0][1];
    v169.influenceSpheres = (const influenceSphere_t *)(HIDWORD(v112) + 16);
    LODWORD(v112) = v107;
    v165 = v112;
    v113 = *(_QWORD *)(&v2 - 1);
    v111 = v110;
    v164 = *(_QWORD *)(&v2 - 1);
    v114 = v112;
    LODWORD(v112) = (__int16)subTreeBounds;
    *(_QWORD *)&v161.b[0][0] = v112;
    HIDWORD(v115) = v108;
    v162 = v115;
    v163 = *(__int64 *)((char *)&v115 + 4);
    v169.influenceSphereStackSize = HIDWORD(maxFoliageHeight);
    v116 = (float)v112;
    if ( (int)*(_DWORD *)HIDWORD(v112) > 0 )
    {
      LODWORD(v112) = HIDWORD(maxFoliageHeight);
      do
      {
        v117 = (float *)((char *)&parms->visibleInfluenceSpheres->numSpheres + v112);
        if ( (float)(v117[8] + v117[4]) >= (double)(float)*(__int64 *)(&v2 - 1)
          && (float)(v117[8] + v117[5]) >= v116
          && (float)(v117[8] + v117[6]) >= (double)(float)v114
          && (float)(v117[4] - v117[8]) <= (double)(float)v113
          && (float)(v117[5] - v117[8]) <= (double)(float)v115
          && (float)(v117[6] - v117[8]) <= (double)(float)*(__int64 *)((char *)&v115 + 4) )
        {
          v169.influenceSphereStack[maxFoliageHeight] = v106;
          LODWORD(maxFoliageHeight) = ++v169.influenceSphereStackSize;
        }
        ++v106;
        LODWORD(v112) = v112 + 24;
      }
      while ( v106 < *(_DWORD *)HIDWORD(v112) );
    }
    LODWORD(maxFoliageHeight) = parms->foliageIndices;
    maxFoliageIndices = parms->maxFoliageIndices;
    maxInfluenceSphereIndices = parms->maxInfluenceSphereIndices;
    v120 = (_WORD *)&v160 + 1;
    v169.influenceSphereIndices = parms->influenceSphereIndices;
    v169.numFoliageIndices = HIDWORD(maxFoliageHeight);
    v121 = 8;
    v169.foliageIndices = (foliageIndex_t *)maxFoliageHeight;
    v169.maxFoliageIndices = maxFoliageIndices;
    v169.maxInfluenceSphereIndices = maxInfluenceSphereIndices;
    *v169.influenceSphereIndices = -1;
    foliageStartFadeDist = parms->foliageStartFadeDist;
    v123 = parms->subTreeBounds;
    subTreeTreeNodes = parms->subTreeTreeNodes;
    v169.foliageSmallFadeDistMax = parms->foliageSmallFadeDistMax;
    v125 = &v123[-1].b[1][3];
    v169.foliageStartFadeDist = foliageStartFadeDist;
    v169.numInfluenceSphereIndices = 1;
    v166.treeNodes = (fm_treeNode_t *)((char *)subTreeTreeNodes + subTreeTreeNodes->treeNodeOffset);
    v166.leafInfo = (fm_leafInfo_t *)((char *)subTreeTreeNodes + subTreeTreeNodes->leafInfoOffset);
    do
    {
      *++v120 = *++v125;
      --v121;
    }
    while ( v121 != 0 );
    GetFoliageRenderListForView_r(
      subTreePtrs: &v166,
      bounds: &v161,
      gather: &v169,
      nodeNum: 0,
      numSmallFoliageAtLeaf: 0,
      stackOffset: 0);
    parms->foliageCount->subTreeFoliageCount = v169.numFoliageIndices;
    v126 = v169.numInfluenceSphereIndices;
    *v5 = v169.numFoliageIndices;
    *v3 = v126;
  }
}

