
// ========================================================================
// ?SetupSubTreePtrsFromTreeNodes@@YAXAAUdm_subTreeTreeNodePtrs_t@@PBUdm_subTreeTreeNodes_t@@@Z
// EA  : 0x827CC950
// RVA : 0x007CC950
// PDB : w:\tech5\engine\models\detail\jobs\detailgather.cpp
// ========================================================================

void __fastcall SetupSubTreePtrsFromTreeNodes(
        dm_subTreeTreeNodePtrs_t *subTreePtrs,
        const dm_subTreeTreeNodes_t *subTree)
{
  subTreePtrs->treeNodes = (dm_treeNode_t *)((char *)subTree + subTree->treeNodeOffset);
}


// ========================================================================
// ?R_CullDetailBoundsToMVP@@YA_NABUdm_subTreeBounds_t@@HPBM@Z
// EA  : 0x827CC960
// RVA : 0x007CC960
// PDB : w:\tech5\engine\models\detail\jobs\detailgather.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall R_CullDetailBoundsToMVP(
        const dm_subTreeBounds_t *bounds,
        int maxDetailHeight,
        const float *mvp,
        int a4,
        __int64 a5)
{
  __int64 v5; // r11
  double v6; // fp1
  __int64 v7; // r8 OVERLAPPED
  __int128 v8; // r6 OVERLAPPED
  double v9; // fp24
  double v10; // fp20
  double v11; // fp31
  int v12; // r11
  double v13; // fp30
  float *v14; // r6
  double v15; // fp23
  int v16; // r5
  double v17; // fp19
  double v18; // fp29
  double v19; // fp18
  double v20; // fp28
  double v21; // fp22
  double v22; // fp27
  double v23; // fp17
  double v24; // fp26
  double v25; // fp21
  double v26; // fp25
  float *v27; // r8
  int i; // r7
  float *v29; // r9
  int j; // ctr
  double v31; // fp0
  double v32; // fp13
  double v33; // fp11
  double v34; // fp10
  double v35; // fp12
  __int64 v37; // [sp+0h] [-E0h]
  __int64 v38; // [sp+8h] [-D8h]
  __int64 v39; // [sp+18h] [-C8h]
  float v40; // [sp+40h] [-A0h] BYREF
  float v41; // [sp+44h] [-9Ch] BYREF
  float v42[36]; // [sp+48h] [-98h] BYREF

  LODWORD(a5) = maxDetailHeight;
  HIDWORD(v5) = mvp;
  v6 = mvp[2];
  LODWORD(v5) = bounds->b[1][2];
  v37 = a5;
  v38 = v5;
  HIDWORD(v7) = (unsigned __int16)bounds->b[1][0];
  DWORD1(v8) = (unsigned __int16)bounds->b[0][0];
  v9 = mvp[1];
  v10 = *mvp;
  LODWORD(v5) = SWORD3(v8);
  LODWORD(v7) = SWORD1(v7);
  v39 = v7;
  LODWORD(v8) = bounds->b[1][1];
  HIDWORD(v7) = bounds->b[0][1];
  v11 = mvp[3];
  v13 = mvp[6];
  v15 = mvp[5];
  v17 = mvp[4];
  v18 = mvp[7];
  v19 = mvp[8];
  v20 = mvp[10];
  v21 = mvp[9];
  v22 = mvp[11];
  v23 = mvp[12];
  v24 = mvp[14];
  v25 = mvp[13];
  v26 = mvp[15];
  DWORD2(v8) = (unsigned __int16)bounds->b[0][2];
  v40 = (float)v5;
  v12 = 0;
  v42[1] = (float)v39;
  v42[2] = (float)(__int64)v8;
  DWORD2(v8) = SWORD5(v8);
  v42[0] = (float)*(__int64 *)((char *)&v8 + 4);
  v16 = 2;
  v41 = (float)*(__int64 *)((char *)&v7 + 4);
  v14 = &v40;
  v42[3] = (float)v37 + (float)v38;
  do
  {
    v27 = &v41;
    for ( i = 2; i != 0; --i )
    {
      v29 = v42;
      for ( j = 2; j != 0; --j )
      {
        v31 = (float)((float)((float)((float)((float)v24 * *v29) + (float)v26) + (float)((float)v25 * *v27))
                    + (float)((float)v23 * *v14));
        v32 = (float)((float)((float)((float)((float)v6 * *v29) + (float)v11) + (float)((float)v10 * *v14))
                    + (float)((float)v9 * *v27));
        v33 = (float)((float)((float)((float)((float)v13 * *v29) + (float)v18) + (float)((float)v17 * *v14))
                    + (float)((float)v15 * *v27));
        v34 = (float)((float)((float)((float)((float)v20 * *v29) + (float)v22) + (float)((float)v21 * *v27))
                    + (float)((float)v19 * *v14));
        v35 = -v31;
        if ( v32 > -v31 )
          v12 |= 1u;
        if ( v32 < v31 )
          v12 |= 2u;
        if ( v33 > v35 )
          v12 |= 4u;
        if ( v33 < v31 )
          v12 |= 8u;
        if ( v34 > v35 )
          v12 |= 0x10u;
        if ( v34 < v31 )
          v12 |= 0x20u;
        v29 += 3;
      }
      v27 += 3;
    }
    --v16;
    v14 += 3;
  }
  while ( v16 != 0 );
  return v12 != 63;
}


// ========================================================================
// ?GetDetailRenderListForView_r@@YAXAAUdm_subTreeTreeNodePtrs_t@@AAUdm_subTreeBounds_t@@AAUdetailGather_t@@GGI@Z
// EA  : 0x827CCB80
// RVA : 0x007CCB80
// PDB : w:\tech5\engine\models\detail\jobs\detailgather.cpp
// ========================================================================

void __fastcall GetDetailRenderListForView_r(
        dm_subTreeTreeNodePtrs_t *subTreePtrs,
        dm_subTreeBounds_t *bounds,
        detailGather_t *gather,
        int nodeNum,
        __int64 counts)
{
  int v8; // r29
  unsigned int v9; // r28
  int v10; // r30
  dm_treeNode_t *v11; // r30
  int v12; // r10
  int v13; // ctr
  __int16 planeDist; // r3
  int v15; // r29
  detailGather_t *v16; // r9
  unsigned int v17; // r23
  unsigned int v18; // r21
  unsigned int v19; // r5
  unsigned int v20; // r24
  char *v21; // r10
  __int16 *v22; // r11
  int i; // ctr
  unsigned __int16 v24; // r11
  unsigned __int16 v25; // r11
  unsigned __int16 v26; // r10
  int v27; // r9
  unsigned int v28; // r10
  char v29; // [sp+4Eh] [-82h] BYREF
  dm_subTreeBounds_t v30; // [sp+50h] [-80h] BYREF

  LOWORD(v8) = WORD1(counts);
  v9 = counts;
  v10 = (unsigned __int16)nodeNum;
  if ( (nodeNum & 0x8000) == 0 )
  {
    while ( 1 )
    {
      v11 = &subTreePtrs->treeNodes[v10];
      HIDWORD(counts) = 0;
      nodeNum = 0;
      v12 = 0;
      v13 = 2;
      planeDist = v11->planeDist;
      v15 = v11->planeType & 3;
      LODWORD(counts) = 8 * v15;
      do
      {
        v16 = (detailGather_t *)((char *)gather + 2 * counts + 2 * v12);
        v17 = v16->frustumVerts[0][0];
        v18 = v16->frustumVerts[0][1];
        v19 = gather->frustumVerts[0][counts + 2 + v12];
        v20 = gather->frustumVerts[v15][v12 + 3];
        HIDWORD(counts) |= (((int)v20 >> 31) + (v20 >= planeDist) + ((unsigned int)planeDist >> 31))
                         | (((int)v19 >> 31) + (v19 >= planeDist) + ((unsigned int)planeDist >> 31))
                         | (((int)v18 >> 31) + (v18 >= planeDist) + ((unsigned int)planeDist >> 31))
                         | (((int)v17 >> 31) + (v17 >= planeDist) + ((unsigned int)planeDist >> 31));
        nodeNum |= ((planeDist >> 31) + (planeDist >= v20) + (v20 >> 31))
                 | ((planeDist >> 31) + (planeDist >= v19) + (v19 >> 31))
                 | ((planeDist >> 31) + (planeDist >= v18) + (v18 >> 31))
                 | ((planeDist >> 31) + (planeDist >= v17) + (v17 >> 31));
        v12 += 4;
        --v13;
      }
      while ( v13 != 0 );
      if ( HIDWORD(counts) == 0 )
        break;
      if ( nodeNum != 0 )
      {
        v21 = &v29;
        v22 = &bounds[-1].b[1][3];
        for ( i = 8; i != 0; --i )
        {
          ++v22;
          v21 += 2;
          *(_WORD *)v21 = *v22;
        }
        v30.b[0][v15] = v11->planeDist;
        GetDetailRenderListForView_r(
          subTreePtrs,
          bounds: &v30,
          gather,
          nodeNum: v11->children[0],
          numDetailAtLeaf: (v11->planeType >> 2) & 0x7F,
          counts: v11->counts[0]);
        LOWORD(nodeNum) = v15 + 4;
        bounds->b[1][v15] = v11->planeDist;
        v8 = v11->planeType >> 9;
LABEL_12:
        v9 = v11->counts[1];
        v24 = v11->children[1];
        goto LABEL_13;
      }
      bounds->b[0][v15] = planeDist;
      v8 = (v11->planeType >> 2) & 0x7F;
      v24 = v11->children[0];
      v9 = v11->counts[0];
LABEL_13:
      v10 = v24;
      if ( (v24 & 0x8000) != 0 )
        goto LABEL_14;
    }
    if ( nodeNum == 0 )
      return;
    bounds->b[1][v15] = planeDist;
    v8 = v11->planeType >> 9;
    goto LABEL_12;
  }
LABEL_14:
  if ( !R_CullDetailBoundsToMVP(
          bounds,
          maxDetailHeight: gather->maxDetailHeight,
          mvp: gather->mvpMatrix,
          a4: (unsigned __int16)nodeNum,
          a5: counts) )
  {
    v25 = v10 & 0x7FFF;
    if ( (unsigned __int16)v8 > gather->maxDetailIndices - gather->numDetailIndices )
      LOWORD(v8) = HIWORD(gather->maxDetailIndices) - HIWORD(gather->numDetailIndices);
    v26 = v10 & 0x7FFF;
    v27 = (unsigned __int16)v8 + (v10 & 0x7FFF);
    if ( (v10 & 0x7FFF) < v27 )
    {
      do
      {
        gather->detailIndices[gather->numDetailIndices] = v25;
        v25 = ++v26;
        ++gather->numDetailIndices;
      }
      while ( v26 < v27 );
    }
    v28 = HIWORD(v9) + gather->indexCount;
    gather->vertCount += (unsigned __int16)v9;
    gather->indexCount = v28;
  }
}


// ========================================================================
// ?GatherDetailIndicesForSubTree@@YAXPBUdeferredDetailGatherParms_t@@AAH@Z
// EA  : 0x827CCE40
// RVA : 0x007CCE40
// PDB : w:\tech5\engine\models\detail\jobs\detailgather.cpp
// ========================================================================

void __fastcall GatherDetailIndicesForSubTree(__int64 numDetailIndices)
{
  int v1; // r31
  unsigned int *v2; // r30
  _DWORD *v3; // r6
  int v4; // r11
  double v5; // fp0
  double v6; // fp13
  double v7; // fp8
  double v8; // fp11
  double v9; // fp5
  double v10; // fp9
  double v11; // fp3
  double v12; // fp7
  double v13; // fp2
  double v14; // fp1
  double v15; // fp31
  double v16; // fp10
  double v17; // fp28
  double v18; // fp12
  double v19; // fp30
  double v20; // fp6
  double v21; // fp26
  double v22; // fp17
  double v23; // fp15
  double v24; // fp20
  double v25; // fp18
  double v26; // fp16
  double v27; // fp8
  double v28; // fp15
  double v29; // fp22
  double v30; // fp23
  double v31; // fp9
  double v32; // fp0
  double v33; // fp15
  double v34; // fp13
  double v35; // fp14
  double v36; // fp5
  double v37; // fp27
  double v38; // fp8
  double v39; // fp22
  double v40; // fp7
  double v41; // fp11
  double v42; // fp15
  double v43; // fp20
  double v44; // fp27
  double v45; // fp25
  double v46; // fp31
  double v47; // fp7
  double v48; // fp4
  double v49; // fp8
  double v50; // fp11
  double v51; // fp2
  double v52; // fp16
  double v53; // fp18
  double v54; // fp30
  double v55; // fp11
  double v56; // fp5
  double v57; // fp19
  double v58; // fp6
  double v59; // fp4
  double v60; // fp11
  double v61; // fp0
  __int64 v62; // r8
  float *v63; // r9
  int i; // ctr
  __int16 v65; // r11
  double v66; // fp0
  int v67; // r11
  double v68; // fp0
  int v69; // r11
  unsigned __int16 *v70; // r5
  _WORD *v71; // r9
  int v72; // ctr
  _WORD *v73; // r10
  float v74; // [sp+50h] [-1D0h]
  float v75; // [sp+50h] [-1D0h]
  float v76; // [sp+54h] [-1CCh]
  float v77; // [sp+54h] [-1CCh]
  float v78; // [sp+58h] [-1C8h]
  float v79; // [sp+58h] [-1C8h]
  float v80; // [sp+5Ch] [-1C4h]
  float v81; // [sp+5Ch] [-1C4h]
  float v82; // [sp+60h] [-1C0h]
  float v83; // [sp+60h] [-1C0h]
  float v84; // [sp+60h] [-1C0h]
  float v85; // [sp+64h] [-1BCh]
  float v86; // [sp+64h] [-1BCh]
  float v87; // [sp+68h] [-1B8h]
  float v88; // [sp+6Ch] [-1B4h]
  float v89; // [sp+6Ch] [-1B4h]
  float v90; // [sp+70h] [-1B0h]
  float v91; // [sp+70h] [-1B0h]
  float v92; // [sp+74h] [-1ACh]
  float v93; // [sp+74h] [-1ACh]
  float v94; // [sp+78h] [-1A8h]
  float v95; // [sp+78h] [-1A8h]
  float v96; // [sp+7Ch] [-1A4h]
  float v97; // [sp+7Ch] [-1A4h]
  float v98; // [sp+80h] [-1A0h]
  float v99; // [sp+80h] [-1A0h]
  __int64 v100; // [sp+88h] [-198h] BYREF
  dm_subTreeBounds_t v101; // [sp+90h] [-190h] BYREF
  float v102; // [sp+A0h] [-180h]
  dm_subTreeTreeNodePtrs_t v103; // [sp+A4h] [-17Ch] BYREF
  float v104; // [sp+A8h] [-178h]
  float v105; // [sp+ACh] [-174h]
  float v106; // [sp+B0h] [-170h]
  float v107; // [sp+C0h] [-160h]
  float v108[23]; // [sp+C4h] [-15Ch] BYREF
  detailGather_t v109[3]; // [sp+120h] [-100h] BYREF

  v1 = HIDWORD(numDetailIndices);
  *(_DWORD *)numDetailIndices = 0;
  v2 = (unsigned int *)numDetailIndices;
  *(_QWORD *)*(_DWORD *)(HIDWORD(numDetailIndices) + 20) = 0;
  *(_QWORD *)(*(_DWORD *)(HIDWORD(numDetailIndices) + 20) + 8) = 0;
  v3 = *(_DWORD **)(HIDWORD(numDetailIndices) + 8);
  if ( *v3 != 0 )
  {
    v4 = *(_DWORD *)HIDWORD(numDetailIndices);
    v62 = *(unsigned int *)(HIDWORD(numDetailIndices) + 16);
    v5 = *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 4);
    v6 = *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 44);
    v7 = *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 32);
    v8 = (float)(*(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 44)
               * *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 4));
    v9 = (float)(*(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 32)
               * *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 4));
    v10 = (float)(*(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 48)
                * *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 4));
    v11 = (float)(*(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 36)
                * *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 4));
    v12 = (float)(*(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 52)
                * *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 4));
    v13 = (float)(*(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 40)
                * *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 4));
    v14 = *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 12);
    v15 = *(float *)(*(_DWORD *)HIDWORD(numDetailIndices) + 60);
    LOWORD(v100) = *(_DWORD *)(HIDWORD(numDetailIndices) + 16);
    v16 = *(float *)(v4 + 24);
    v17 = (float)((float)v15 * (float)v5);
    v18 = *(float *)(v4 + 20);
    v19 = (float)(*(float *)(v4 + 56) * (float)v5);
    v20 = *(float *)(v4 + 28);
    v21 = *(float *)(v4 + 16);
    v22 = (float)((float)v11 + *(float *)(v4 + 24));
    v23 = (float)((float)v13 + *(float *)(v4 + 28));
    v74 = *(float *)(v4 + 8);
    v88 = v15;
    v92 = *(float *)(v4 + 56);
    v80 = v6;
    v78 = v7;
    v90 = *(float *)(v4 + 64);
    v82 = v15;
    v85 = (float)(v92 * (float)v5) * *(float *)(v4 + 16);
    v24 = *(float *)(v4 + 48);
    v94 = (float)((float)v15 * (float)v5) * *(float *)(v4 + 16);
    v25 = *(float *)(v4 + 52);
    v98 = (float)(v90 * (float)v5) * *(float *)(v4 + 16);
    v96 = (float)v12 * (float)v14;
    v26 = *(float *)(v4 + 36);
    v27 = *(float *)(v4 + 40);
    v107 = (float)((float)(*(float *)(v4 + 20) + (float)v9) + (float)((float)v8 * (float)v14)) + v85;
    v108[0] = (float)((float)v22 + (float)((float)v10 * (float)v14))
            + (float)((float)((float)v15 * (float)v5) * (float)v21);
    v29 = (float)(v90 * (float)v5);
    LODWORD(numDetailIndices) = v62;
    v108[1] = (float)((float)v23 + v96) + v98;
    v28 = (float)((float)v18 + (float)v9);
    LOWORD(v100) = v62;
    v30 = (float)((float)((float)v18 + (float)v9) - (float)((float)v8 * (float)v14));
    v34 = (float)((float)((float)v11 + (float)v16) - (float)((float)v10 * (float)v14));
    v31 = (float)((float)((float)v25 * (float)v5) * (float)v14);
    v35 = v74;
    *(_QWORD *)&v101.b[0][0] = numDetailIndices;
    v36 = (float)((float)((float)((float)v26 * (float)v5) + (float)v16)
                + (float)((float)((float)v24 * (float)v5) * (float)v14));
    v32 = (float)((float)((float)v27 * (float)v5) + (float)v20);
    v37 = v78;
    v79 = (float)v27 * v74;
    v38 = (float)(v92 * v74);
    v75 = (float)v29 * (float)v21;
    v39 = v82;
    v40 = (float)((float)v28 + (float)((float)v8 * (float)v14));
    v41 = (float)((float)((float)v28 - (float)((float)v8 * (float)v14)) + v85);
    v33 = v80;
    v81 = v82 * (float)v35;
    v83 = v38;
    v42 = (float)((float)v33 * (float)v35);
    v43 = (float)((float)v24 * (float)v35);
    v108[2] = v41;
    v76 = v35;
    v44 = (float)((float)v37 * (float)v35);
    v108[3] = (float)v34 + v94;
    v108[4] = (float)((float)((float)v13 + (float)v20) - v96) + v98;
    v108[5] = (float)((float)v30 - (float)((float)v19 * (float)v21)) - (float)(v92 * (float)v62);
    v45 = (float)(v79 + (float)v20);
    v46 = v83;
    v108[7] = (float)((float)((float)((float)v13 + (float)v20) - v96) - v98) - (float)(v90 * (float)v62);
    v87 = v90 * (float)v62;
    v102 = (float)((float)v32 + (float)v31) - v75;
    v47 = (float)((float)v40 - (float)((float)v19 * (float)v21));
    v48 = *(float *)(v4 + 60);
    v49 = (float)((float)((float)v25 * (float)v35) * (float)v14);
    v50 = *(float *)(v4 + 40);
    v97 = (float)v36 - (float)((float)v17 * (float)v21);
    v51 = (float)((float)((float)v26 * (float)v35) + (float)v16);
    v86 = v92;
    v105 = v83 * (float)v21;
    v104 = v81 * (float)v21;
    v106 = (float)(v90 * (float)v35) * (float)v21;
    v52 = (float)(*(float *)(v4 + 48) * v76);
    v53 = (float)(*(float *)(v4 + 52) * v76);
    v54 = (float)(*(float *)(v4 + 36) * v76);
    v55 = (float)((float)v50 * v76);
    v56 = (float)((float)v48 * v76);
    v84 = *(float *)(v4 + 64);
    v57 = (float)(v84 * v76);
    v108[6] = (float)((float)v34 - (float)((float)v17 * (float)v21)) - (float)(v88 * (float)v62);
    v77 = v48;
    v91 = v92 * (float)v62;
    v93 = (float)v39 * (float)v62;
    v89 = v47;
    v95 = v46;
    v99 = v79 + (float)v20;
    v58 = (float)(*(float *)(v4 + 28) + (float)v55);
    v59 = (float)((float)(*(float *)(v4 + 24) + (float)v54) - (float)((float)v52 * (float)v14));
    v60 = (float)((float)(*(float *)(v4 + 28) + (float)v55) + (float)((float)v53 * (float)v14));
    v61 = (float)((float)(*(float *)(v4 + 24) + (float)v54) + (float)((float)v52 * (float)v14));
    v109[0].mvpMatrix = (const float *)(v4 + 80);
    v109[0].maxDetailHeight = v62;
    LODWORD(v62) = &v109[0].frustumVerts[1][7];
    v108[8] = v89 - v91;
    v108[9] = v97 - v93;
    v108[10] = v102 - v87;
    v108[11] = (float)((float)((float)v18 + (float)v44) + (float)((float)v42 * (float)v14)) + v105;
    v108[12] = (float)((float)v51 + (float)((float)v43 * (float)v14)) + v104;
    v108[13] = (float)((float)v45 + (float)v49) + v106;
    v108[14] = (float)((float)((float)v18 + (float)v44) - (float)((float)v42 * (float)v14))
             + (float)((float)v46 * (float)v21);
    v108[15] = (float)((float)v51 - (float)((float)v43 * (float)v14)) + v104;
    v108[16] = (float)(v99 - (float)v49) + v106;
    v108[17] = (float)((float)((float)((float)v44 + (float)v18) - (float)((float)v42 * (float)v14))
                     - (float)((float)v46 * (float)v21))
             - (float)(v86 * (float)numDetailIndices);
    v108[20] = (float)((float)((float)((float)v44 + (float)v18) + (float)((float)v42 * (float)v14))
                     - (float)(v95 * (float)v21))
             - (float)((float)numDetailIndices * v86);
    v108[18] = (float)((float)v59 - (float)((float)v56 * (float)v21)) - (float)(v77 * (float)numDetailIndices);
    v108[19] = (float)((float)((float)v58 - (float)((float)v53 * (float)v14)) - (float)((float)v57 * (float)v21))
             - (float)(v84 * (float)numDetailIndices);
    v108[21] = (float)((float)v61 - (float)((float)v56 * (float)v21)) - (float)(v77 * (float)numDetailIndices);
    v108[22] = (float)((float)v60 - (float)((float)v57 * (float)v21)) - (float)(v84 * (float)numDetailIndices);
    v63 = v108;
    for ( i = 8; i != 0; --i )
    {
      *(_DWORD *)&v101.b[0][2] = (int)*(v63 - 1);
      v65 = v101.b[0][3];
      if ( *(int *)&v101.b[0][2] >= -32768 )
      {
        if ( *(int *)&v101.b[0][2] > 0x7FFF )
          v65 = 0x7FFF;
      }
      else
      {
        v65 = 0x8000;
      }
      v66 = *v63;
      *(_WORD *)(v62 - 30) = v65;
      *(_DWORD *)&v101.b[0][2] = (int)v66;
      v67 = (int)v66;
      if ( (int)v66 >= -32768 )
      {
        if ( v67 > 0x7FFF )
          LOWORD(v67) = 0x7FFF;
      }
      else
      {
        LOWORD(v67) = 0x8000;
      }
      v68 = v63[1];
      *(_WORD *)(v62 - 14) = v67;
      *(_DWORD *)&v101.b[0][2] = (int)v68;
      v69 = (int)v68;
      if ( (int)v68 >= -32768 )
      {
        if ( v69 > 0x7FFF )
          LOWORD(v69) = 0x7FFF;
      }
      else
      {
        LOWORD(v69) = 0x8000;
      }
      LODWORD(v62) = v62 + 2;
      *(_WORD *)v62 = v69;
      v63 += 3;
    }
    v70 = *(unsigned __int16 **)(HIDWORD(numDetailIndices) + 24);
    LODWORD(v62) = *(_DWORD *)(HIDWORD(numDetailIndices) + 28);
    v109[0].numDetailIndices = HIDWORD(v62);
    v109[0].indexCount = HIDWORD(v62);
    v71 = (_WORD *)&v100 + 3;
    v109[0].vertCount = HIDWORD(v62);
    v109[0].detailIndices = v70;
    v72 = 8;
    v109[0].maxDetailIndices = v62;
    v73 = (_WORD *)(*(_DWORD *)(HIDWORD(numDetailIndices) + 4) - 2);
    v103.treeNodes = (dm_treeNode_t *)((char *)v3 + v3[1]);
    do
    {
      *++v71 = *++v73;
      --v72;
    }
    while ( v72 != 0 );
    GetDetailRenderListForView_r(subTreePtrs: &v103, bounds: &v101, gather: v109, nodeNum: 0, counts: 0);
    **(_DWORD **)(v1 + 20) = v109[0].numDetailIndices;
    *(_DWORD *)(*(_DWORD *)(v1 + 20) + 4) = v109[0].vertCount;
    *(_DWORD *)(*(_DWORD *)(v1 + 20) + 8) = v109[0].indexCount;
    *v2 = v109[0].numDetailIndices;
  }
}

