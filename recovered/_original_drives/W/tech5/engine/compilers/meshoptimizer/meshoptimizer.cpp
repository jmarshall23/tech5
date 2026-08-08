
// ========================================================================
// GetTriangleCost
// EA  : 0x825F5628
// RVA : 0x005F5628
// PDB : w:\tech5\engine\compilers\meshoptimizer\meshoptimizer.cpp
// ========================================================================

unsigned int __fastcall GetTriangleCost(
        unsigned __int16 *l1Cache,
        unsigned __int16 *l2Cache,
        unsigned __int16 *indexes)
{
  unsigned int result; // r3
  int i; // ctr
  int v6; // r8
  int v7; // r9
  int v8; // r10
  char v9; // r7
  int v10; // r10
  unsigned __int16 *v11; // r6
  int v12; // r30
  int v13; // r10
  int v14; // r30
  int v15; // r10
  unsigned int v16; // r9
  unsigned __int16 *v17; // r10

  result = 0;
  for ( i = 3; i != 0; --i )
  {
    v6 = *indexes;
    v7 = 0;
    v8 = *l1Cache;
    v9 = 0;
    if ( v8 == v6 )
    {
      l1Cache[7] = v6;
      v9 = 1;
    }
    else
    {
      l1Cache[4] = v8;
      v7 = 1;
    }
    v10 = l1Cache[1];
    v11 = l1Cache + 1;
    if ( v10 == v6 )
    {
      l1Cache[7] = v6;
      v9 = 1;
    }
    else
    {
      v12 = v7 + 4;
      ++v7;
      l1Cache[v12] = v10;
    }
    v13 = l1Cache[2];
    if ( v13 == v6 )
    {
      l1Cache[7] = v6;
      v9 = 1;
    }
    else
    {
      v14 = v7 + 4;
      ++v7;
      l1Cache[v14] = v13;
    }
    v15 = l1Cache[3];
    if ( v15 == v6 )
    {
      l1Cache[7] = v6;
      v9 = 1;
    }
    else
    {
      l1Cache[v7 + 4] = v15;
    }
    if ( v9 != 0 )
    {
      l1Cache += 4;
    }
    else
    {
      ++l1Cache;
      v11[3] = v6;
      result += 6;
      v16 = 0;
      v17 = l2Cache;
      do
      {
        if ( *v17 == v6 )
          break;
        ++v16;
        ++v17;
      }
      while ( v16 < 0x17 );
      if ( v16 == 23 )
      {
        ++l2Cache;
        result += 36;
        l2Cache[22] = v6;
      }
    }
    ++indexes;
  }
  return result;
}


// ========================================================================
// RenderTriangle
// EA  : 0x825F5768
// RVA : 0x005F5768
// PDB : w:\tech5\engine\compilers\meshoptimizer\meshoptimizer.cpp
// ========================================================================

void __fastcall RenderTriangle(unsigned __int16 **l1Cache, unsigned __int16 **l2Cache, unsigned __int16 *indexes)
{
  int i; // ctr
  int v4; // r11
  int v5; // r9
  int v6; // r8
  char v7; // r7
  int v8; // r10
  int v9; // r11
  int v10; // r10
  int v11; // r31
  int v12; // r11
  int v13; // r10
  int v14; // r31
  int v15; // r11
  int v16; // r10
  int v17; // r9
  unsigned int v18; // r11
  unsigned __int16 *v19; // r10
  int v20; // r10

  for ( i = 3; i != 0; --i )
  {
    v4 = (int)*l1Cache;
    v5 = 0;
    v6 = *indexes;
    v7 = 0;
    v8 = **l1Cache;
    if ( v8 == v6 )
    {
      *(_WORD *)(v4 + 14) = v6;
      v7 = 1;
    }
    else
    {
      *(_WORD *)(v4 + 8) = v8;
      v5 = 1;
    }
    v9 = (int)*l1Cache;
    v10 = (*l1Cache)[1];
    if ( v10 == v6 )
    {
      *(_WORD *)(v9 + 14) = v6;
      v7 = 1;
    }
    else
    {
      v11 = 2 * (v5 + 4);
      ++v5;
      *(_WORD *)(v11 + v9) = v10;
    }
    v12 = (int)*l1Cache;
    v13 = (*l1Cache)[2];
    if ( v13 == v6 )
    {
      *(_WORD *)(v12 + 14) = v6;
      v7 = 1;
    }
    else
    {
      v14 = 2 * (v5 + 4);
      ++v5;
      *(_WORD *)(v14 + v12) = v13;
    }
    v15 = (int)*l1Cache;
    v16 = (*l1Cache)[3];
    if ( v16 == v6 )
    {
      *(_WORD *)(v15 + 14) = v6;
      v7 = 1;
    }
    else
    {
      *(_WORD *)(2 * (v5 + 4) + v15) = v16;
    }
    if ( v7 != 0 )
    {
      *l1Cache += 4;
    }
    else
    {
      v17 = 0;
      v18 = 0;
      v19 = *l1Cache + 1;
      *l1Cache = v19;
      v19[3] = v6;
      v20 = (int)*l2Cache;
      do
      {
        if ( *(unsigned __int16 *)(v18 + v20) == v6 )
          break;
        v18 += 2;
        ++v17;
      }
      while ( v18 < 0x2E );
      if ( v17 == 23 )
      {
        *l2Cache = (unsigned __int16 *)(v20 + 2);
        *(_WORD *)(v20 + 46) = v6;
      }
    }
    ++indexes;
  }
}


// ========================================================================
// GetBestRenderOrder_r
// EA  : 0x825F58B0
// RVA : 0x005F58B0
// PDB : w:\tech5\engine\compilers\meshoptimizer\meshoptimizer.cpp
// ========================================================================

unsigned int __fastcall GetBestRenderOrder_r(
        unsigned int inCost,
        unsigned int inBestCost,
        unsigned int *renderList,
        unsigned int renderListSize,
        unsigned int *triOrder,
        unsigned __int16 *renderOrder,
        unsigned __int16 *l1Cache,
        unsigned __int16 *l2Cache,
        unsigned __int16 *indexes,
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
        unsigned __int16 *a24,
        int a25,
        unsigned __int16 *a26,
        int a27,
        unsigned __int16 *a28)
{
  unsigned __int16 *v28; // r16
  unsigned int v31; // r19
  unsigned __int16 *v34; // r22
  unsigned __int16 *v35; // r23
  unsigned int *v36; // r18
  unsigned int v37; // r21
  int v38; // r20
  unsigned int v39; // r27
  unsigned int *v40; // r26
  unsigned int v41; // r28
  unsigned __int16 *v42; // r11
  unsigned __int16 v43; // r8
  unsigned __int16 v44; // r7
  unsigned int TriangleCost; // r30
  unsigned int v46; // r29
  unsigned int v47; // r3
  unsigned int v48; // r10
  unsigned __int16 *v49; // r11
  unsigned __int16 v50; // r8
  unsigned __int16 v51; // r7
  int v52; // r3
  unsigned int v53; // r18
  int v54; // r12
  int v55; // r12
  unsigned int *v56; // r27
  unsigned int i; // r17
  unsigned int v58; // r26
  unsigned __int16 *v59; // r11
  unsigned __int16 v60; // r8
  unsigned __int16 v61; // r7
  unsigned int v62; // r30
  unsigned int v63; // r29
  unsigned int v64; // r3
  unsigned int v65; // r29
  unsigned __int16 *v66; // r28
  unsigned int v67; // r3
  unsigned __int16 *v68; // r10
  unsigned __int16 *v69; // r9
  unsigned __int16 *v70; // r29
  unsigned int BestRenderOrder_r; // r3
  unsigned int v72; // r10
  unsigned __int16 v73; // r9
  unsigned __int16 v74; // r8
  unsigned __int16 *back_chain[24]; // [sp+0h] [-110h]
  unsigned __int16 *v77; // [sp+60h] [-B0h] BYREF
  unsigned __int16 *v78; // [sp+64h] [-ACh] BYREF
  unsigned __int16 v79; // [sp+68h] [-A8h] BYREF
  unsigned __int16 v80; // [sp+6Ah] [-A6h] BYREF
  unsigned __int16 v81[82]; // [sp+6Ch] [-A4h] BYREF

  v28 = a28;
  v31 = renderListSize;
  a24 = l1Cache;
  a26 = l2Cache;
  v34 = l1Cache;
  v35 = l2Cache;
  if ( renderListSize > 4 )
  {
    v36 = &renderList[renderListSize];
    while ( 1 )
    {
      v37 = inBestCost;
      v38 = -1;
      v39 = 0;
      if ( v31 == 0 )
        break;
      v40 = renderList;
      do
      {
        v41 = *v40;
        v42 = &v28[*v40];
        v43 = *v42;
        v44 = v42[1];
        v81[0] = v28[*v40 + 2];
        v79 = v43;
        v80 = v44;
        v81[1] = v43;
        v81[2] = v44;
        TriangleCost = GetTriangleCost(l1Cache: v34, l2Cache: v35, indexes: &v79);
        v46 = GetTriangleCost(l1Cache: v34, l2Cache: v35, indexes: &v80);
        v47 = GetTriangleCost(l1Cache: v34, l2Cache: v35, indexes: v81);
        if ( v46 >= TriangleCost )
        {
          if ( TriangleCost <= v47 )
          {
            v48 = TriangleCost + inCost;
            v49 = &v79;
            goto LABEL_12;
          }
          if ( v46 > TriangleCost )
            goto LABEL_11;
        }
        if ( v46 > v47 )
        {
LABEL_11:
          v48 = v47 + inCost;
          v49 = v81;
        }
        else
        {
          v48 = v46 + inCost;
          v49 = &v80;
        }
LABEL_12:
        if ( v48 < v37 )
        {
          v37 = v48;
          v50 = v49[1];
          v38 = v39;
          v51 = v49[2];
          *renderOrder = *v49;
          renderOrder[1] = v50;
          renderOrder[2] = v51;
          *triOrder = v41;
        }
        ++v39;
        ++v40;
      }
      while ( v39 < v31 );
      if ( v38 != -1 )
      {
        RenderTriangle(l1Cache: &a24, l2Cache: &a26, indexes: renderOrder);
        --v36;
        --v31;
        renderOrder += 3;
        inCost = v37;
        ++triOrder;
        renderList[v38] = *v36;
        v35 = a26;
        v34 = a24;
        if ( v31 > 4 )
          continue;
      }
      break;
    }
  }
  v52 = ((int (*)(void))RtlCheckStack12)();
  v53 = v31;
  *(unsigned __int16 **)((char *)back_chain + v54) = back_chain[0];
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v52);
  *(unsigned __int16 **)((char *)back_chain + v55) = back_chain[0];
  if ( v31 != 0 )
  {
    v56 = renderList;
    for ( i = v31; i != 0; --i )
    {
      v58 = *v56;
      v59 = &v28[*v56];
      v60 = *v59;
      v61 = v59[1];
      v81[0] = v28[*v56 + 2];
      v79 = v60;
      v80 = v61;
      v81[1] = v60;
      v81[2] = v61;
      v62 = GetTriangleCost(l1Cache: v34, l2Cache: v35, indexes: &v79);
      v63 = GetTriangleCost(l1Cache: v34, l2Cache: v35, indexes: &v80);
      v64 = GetTriangleCost(l1Cache: v34, l2Cache: v35, indexes: v81);
      if ( v63 >= v62 )
      {
        if ( v62 <= v64 )
        {
          v65 = v62 + inCost;
          v66 = &v79;
          goto LABEL_26;
        }
        if ( v63 > v62 )
          goto LABEL_25;
      }
      if ( v63 > v64 )
      {
LABEL_25:
        v65 = v64 + inCost;
        v66 = v81;
        goto LABEL_26;
      }
      v65 = v63 + inCost;
      v66 = &v80;
LABEL_26:
      if ( v65 < inBestCost )
      {
        if ( v31 > 1 )
        {
          v78 = v34;
          v77 = v35;
          RenderTriangle(l1Cache: &v78, l2Cache: &v77, indexes: v66);
          v67 = v65;
          v68 = v77;
          v69 = v78;
          back_chain[21] = v28;
          v70 = (unsigned __int16 *)*v56;
          *v56 = renderList[v53 - 1];
          BestRenderOrder_r = GetBestRenderOrder_r(
                                inCost: v67,
                                inBestCost,
                                renderList,
                                renderListSize: v31 - 1,
                                triOrder: (unsigned int *)&v77,
                                renderOrder: (unsigned __int16 *)&v77,
                                l1Cache: v69,
                                l2Cache: v68,
                                indexes: back_chain[2]);
          v72 = *v56;
          v78 = v70;
          renderList[v53 - 1] = v72;
          *v56 = (unsigned int)v70;
          v65 = BestRenderOrder_r;
        }
        if ( v65 < inBestCost )
        {
          inBestCost = v65;
          memcpy(Dst: renderOrder + 3, Src: &v77, Size: 6 * (v31 - 1));
          v73 = v66[1];
          v74 = v66[2];
          *renderOrder = *v66;
          renderOrder[1] = v73;
          renderOrder[2] = v74;
          memcpy(Dst: triOrder + 1, Src: &v77, Size: 4 * (v31 - 1));
          *triOrder = v58;
        }
      }
      ++v56;
    }
  }
  return inBestCost;
}


// ========================================================================
// ?MeshOptimizer@@YAXPAGI0MMM@Z
// EA  : 0x825F5C30
// RVA : 0x005F5C30
// PDB : w:\tech5\engine\compilers\meshoptimizer\meshoptimizer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall MeshOptimizer(
        unsigned __int16 *indexes,
        unsigned int numIndexes,
        unsigned __int16 *outputIndexes,
        double k1,
        double k2,
        double k3)
{
  unsigned int v8; // r25
  unsigned int v13; // r7
  unsigned __int16 *v14; // r11
  int v15; // r8
  int v16; // r10
  int v17; // r9
  unsigned int v18; // r18
  unsigned __int16 *v19; // r10
  unsigned int i; // ctr
  unsigned int v21; // r28
  unsigned int v22; // r5
  char *v23; // r22
  unsigned __int16 *v24; // r10
  unsigned int j; // ctr
  int v26; // r11
  unsigned int v27; // r5
  char *v28; // r3
  char *v29; // r24
  unsigned int v30; // r30
  unsigned int v31; // r27
  unsigned int *v32; // r10
  unsigned int v33; // ctr
  unsigned int v34; // r31
  unsigned int v35; // r5
  unsigned __int16 *v36; // r16
  unsigned int v37; // r5
  unsigned __int16 *v38; // r15
  unsigned int v39; // r5
  char *v40; // r31
  unsigned int v41; // r5
  char *v42; // r23
  int v43; // r11
  unsigned int v44; // ctr
  unsigned __int16 *v45; // r10
  int v46; // r8
  int v47; // r4
  int v48; // r9
  int v49; // r6
  int v50; // r3
  int v51; // r8
  int v52; // r7
  void *v53; // r17
  unsigned int v54; // r5
  unsigned int v55; // r5
  unsigned int v56; // r5
  unsigned __int16 *v57; // r18
  unsigned int v58; // r5
  unsigned int *v59; // r19
  unsigned int v60; // r5
  unsigned int *v61; // r20
  unsigned int v62; // r24
  double v63; // fp31
  int v64; // r21
  unsigned __int16 *v65; // r26
  int k; // r25
  int v67; // r27
  unsigned int v68; // r31
  unsigned int v69; // r11
  unsigned int *v70; // r9
  unsigned int *v71; // r10
  int v72; // ctr
  unsigned int BestRenderOrder_r; // r3
  int v74; // r2 OVERLAPPED
  unsigned int v75; // r28
  unsigned __int16 *v76; // r29
  unsigned int m; // r30
  unsigned __int16 *v78; // r10
  unsigned int n; // r11
  __int64 v80; // r9
  __int64 v81; // fp12
  __int64 v82; // r8
  unsigned int v83; // r3 OVERLAPPED
  unsigned __int16 *v84; // r26
  int ii; // r25
  int v86; // r27
  unsigned int v87; // r31
  unsigned int v88; // r11
  unsigned int *v89; // r9
  unsigned int *v90; // r10
  int v91; // ctr
  __int64 v92; // r9 OVERLAPPED
  unsigned int v93; // r3
  int v94; // r2 OVERLAPPED
  unsigned int v95; // r28
  unsigned __int16 *v96; // r29
  unsigned int jj; // r30
  unsigned __int16 *v98; // r10
  unsigned int kk; // r11
  unsigned int v100; // r3 OVERLAPPED
  int v101; // r8
  int v102; // r10
  int v103; // r9
  int *v104; // r7
  unsigned int mm; // ctr
  unsigned int v106; // r11
  unsigned int v107; // r10
  unsigned int *v108; // r9
  unsigned int *v109; // r10
  unsigned int v110; // ctr
  unsigned int v111; // r30
  unsigned __int16 *v112; // r31
  char *v113; // r29
  unsigned __int16 *v114; // r10
  unsigned int v115; // r7
  int v116; // r9
  int v117; // r10
  int v118; // r11
  unsigned __int16 v119; // r5
  unsigned int v120; // r31
  idMem *v121; // r31
  unsigned int v122; // r4
  idTempArray<unsigned short> *v123; // r3
  unsigned __int16 *v124; // [sp+8h] [-188h]
  int v125; // [sp+Ch] [-184h]
  int v126; // [sp+10h] [-180h]
  int v127; // [sp+14h] [-17Ch]
  int v128; // [sp+18h] [-178h]
  int v129; // [sp+1Ch] [-174h]
  int v130; // [sp+20h] [-170h]
  int v131; // [sp+24h] [-16Ch]
  int v132; // [sp+28h] [-168h]
  int v133; // [sp+2Ch] [-164h]
  int v134; // [sp+30h] [-160h]
  int v135; // [sp+34h] [-15Ch]
  int v136; // [sp+38h] [-158h]
  int v137; // [sp+3Ch] [-154h]
  int v138; // [sp+40h] [-150h]
  unsigned __int16 *v139; // [sp+44h] [-14Ch]
  int v140; // [sp+48h] [-148h]
  unsigned __int16 *v141; // [sp+4Ch] [-144h]
  int v142; // [sp+50h] [-140h]
  unsigned __int16 *v143; // [sp+60h] [-130h]
  char *v144; // [sp+64h] [-12Ch]
  char *v145; // [sp+68h] [-128h]
  char *v146; // [sp+6Ch] [-124h]
  unsigned __int16 *v147; // [sp+70h] [-120h] BYREF
  unsigned int v148; // [sp+74h] [-11Ch]
  unsigned int v149; // [sp+78h] [-118h]
  unsigned __int16 *v150; // [sp+7Ch] [-114h] BYREF
  idMem *v151; // [sp+80h] [-110h]
  __int64 v152; // [sp+88h] [-108h]
  __int64 v153; // [sp+90h] [-100h]
  __int64 v154; // [sp+98h] [-F8h]
  __int64 v155; // [sp+A0h] [-F0h]
  __int64 v156; // [sp+A8h] [-E8h]
  __int64 v157; // [sp+B0h] [-E0h]

  v8 = numIndexes / 3;
  v13 = 0;
  if ( numIndexes / 3 != 0 )
  {
    v14 = indexes + 1;
    while ( 1 )
    {
      v15 = *v14;
      v16 = *(v14 - 1);
      if ( v16 == v15 )
        break;
      v17 = v14[1];
      if ( v16 == v17 || v15 == v17 )
        break;
      ++v13;
      v14 += 3;
      if ( v13 >= v8 )
        goto LABEL_7;
    }
    idLib::Error(fmt: "Degenerate triangle in mesh!");
    idTempArray<unsigned short>::idTempArray<unsigned short>(this: v123, num: v122);
  }
  else
  {
LABEL_7:
    v18 = 0;
    v148 = 0;
    if ( numIndexes != 0 )
    {
      v19 = indexes;
      for ( i = numIndexes; i != 0; --i )
      {
        if ( *v19 > v18 )
          v18 = *v19;
        ++v19;
      }
      v148 = v18;
    }
    v21 = v18 + 1;
    v22 = 4 * (v18 + 1);
    if ( v18 + 1 > 0x3FFFFFFF )
      v22 = -1;
    v151 = &mem;
    v23 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                    size: v22,
                    tag: TAG_TOOLS,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    memset(Dst: v23, Val: 0, Size: 4 * (v18 + 1));
    if ( numIndexes != 0 )
    {
      v24 = indexes - 1;
      for ( j = numIndexes; j != 0; --j )
      {
        v26 = __ROL4__(*++v24, 2);
        ++*(_DWORD *)&v23[v26];
      }
    }
    v27 = 4 * v21;
    if ( v21 > 0x3FFFFFFF )
      v27 = -1;
    v28 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                    size: v27,
                    tag: TAG_TOOLS,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    v29 = v28;
    v30 = 0;
    v146 = v28;
    v31 = 0;
    v32 = (unsigned int *)v23;
    v33 = v18 + 1;
    do
    {
      *(unsigned int *)((char *)v32 + v28 - v23) = v30;
      v30 += *v32;
      if ( (int)v31 <= (int)*v32 )
        v31 = *v32;
      ++v32;
      --v33;
    }
    while ( v33 != 0 );
    v34 = v31 + 10;
    v35 = 24 * (v31 + 10);
    if ( 12 * (v31 + 10) > 0x7FFFFFFF )
      v35 = -1;
    v36 = (unsigned __int16 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                size: v35,
                                tag: TAG_TOOLS,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v37 = 46 * v34;
    if ( 23 * v34 > 0x7FFFFFFF )
      v37 = -1;
    v38 = (unsigned __int16 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                size: v37,
                                tag: TAG_TOOLS,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    memset(Dst: v36, Val: 255, Size: 24 * v34);
    memset(Dst: v38, Val: 255, Size: 46 * v34);
    v39 = 4 * v30;
    if ( v30 > 0x3FFFFFFF )
      v39 = -1;
    v40 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                    size: v39,
                    tag: TAG_TOOLS,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    v145 = v40;
    v41 = 2 * v21;
    if ( v21 > 0x7FFFFFFF )
      v41 = -1;
    v42 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                    size: v41,
                    tag: TAG_TOOLS,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    memset(Dst: v42, Val: 0, Size: 2 * (v18 + 1));
    if ( v8 != 0 )
    {
      v43 = 0;
      v44 = v8;
      v45 = indexes - 1;
      do
      {
        v46 = v45[1];
        v47 = v45[2];
        v48 = __ROL4__(v46, 1);
        v45 += 3;
        v49 = *v45;
        v50 = __ROL4__(v46, 2);
        v51 = __ROL4__(v47, 1);
        v52 = __ROL4__(v49, 1);
        *(_DWORD *)&v40[4 * *(_DWORD *)&v29[v50] + 4 * (unsigned __int16)(*(_WORD *)&v42[v48])++] = v43;
        *(_DWORD *)&v40[4 * *(_DWORD *)&v29[__ROL4__(v47, 2)] + 4 * (unsigned __int16)(*(_WORD *)&v42[v51])++] = v43;
        *(_DWORD *)&v40[4 * *(_DWORD *)&v29[__ROL4__(v49, 2)] + 4 * *(unsigned __int16 *)&v42[v52]] = v43;
        v43 += 3;
        ++*(_WORD *)&v42[v52];
        --v44;
      }
      while ( v44 != 0 );
    }
    v53 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
            size: v8,
            tag: TAG_TOOLS,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    memset(Dst: v53, Val: 0, Size: v8);
    v54 = 6 * v31;
    if ( 3 * v31 > 0x7FFFFFFF )
      v54 = -1;
    v143 = (unsigned __int16 *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                 size: v54,
                                 tag: TAG_TOOLS,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    v55 = 4 * v31;
    if ( v31 > 0x3FFFFFFF )
      v55 = -1;
    v144 = (char *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                     size: v55,
                     tag: TAG_TOOLS,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    v56 = 6 * v31;
    if ( 3 * v31 > 0x7FFFFFFF )
      v56 = -1;
    v57 = (unsigned __int16 *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                                size: v56,
                                tag: TAG_TOOLS,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v58 = 4 * v31;
    if ( v31 > 0x3FFFFFFF )
      v58 = -1;
    v59 = (unsigned int *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                            size: v58,
                            tag: TAG_TOOLS,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    v60 = 4 * v31;
    if ( v31 > 0x3FFFFFFF )
      v60 = -1;
    v61 = (unsigned int *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                            size: v60,
                            tag: TAG_TOOLS,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    v149 = v8;
    if ( v8 != 0 )
    {
      do
      {
        v62 = 0;
        v63 = 3.4028235e38;
        v64 = -1;
        v65 = v36;
        for ( k = 4; k != 0; --k )
        {
          v67 = *v65;
          if ( v67 != 0xFFFF && *(_DWORD *)&v23[4 * v67] != 0 )
          {
            v68 = 0;
            v69 = *(_DWORD *)&v146[4 * v67];
            if ( v69 < *(unsigned __int16 *)&v42[2 * v67] + v69 )
            {
              v70 = v61 - 1;
              v71 = (unsigned int *)&v145[4 * v69];
              v72 = *(unsigned __int16 *)&v42[2 * v67];
              do
              {
                if ( *((_BYTE *)v53 + *v71 / 3) == 0 )
                {
                  *++v70 = *v71;
                  ++v68;
                }
                ++v71;
                --v72;
              }
              while ( v72 != 0 );
            }
            BestRenderOrder_r = GetBestRenderOrder_r(
                                  inCost: 0,
                                  inBestCost: 0xFFFFFFFF,
                                  renderList: v61,
                                  renderListSize: v68,
                                  triOrder: v59,
                                  renderOrder: v57,
                                  l1Cache: v36,
                                  l2Cache: v38,
                                  indexes: v124,
                                  a10: v125,
                                  a11: v126,
                                  a12: v127,
                                  a13: v128,
                                  a14: v129,
                                  a15: v130,
                                  a16: v131,
                                  a17: v132,
                                  a18: v133,
                                  a19: v134,
                                  a20: v135,
                                  a21: v136,
                                  a22: v137,
                                  a23: v138,
                                  a24: v139,
                                  a25: v140,
                                  a26: v141,
                                  a27: v142,
                                  a28: indexes);
            v147 = v38;
            v75 = BestRenderOrder_r;
            v150 = v36;
            if ( v62 != 0 )
            {
              v76 = v143;
              for ( m = v62; m != 0; --m )
              {
                RenderTriangle(l1Cache: &v150, l2Cache: &v147, indexes: v76);
                v76 += 3;
              }
            }
            v78 = v147;
            for ( n = 0; n < 0x17; ++n )
            {
              HIDWORD(v80) = *v78;
              if ( HIDWORD(v80) == v67 )
                break;
              ++v78;
            }
            LODWORD(v80) = v75;
            v153 = v80;
            v81 = v80;
            LODWORD(v82) = v68;
            HIDWORD(v82) = 23 - n;
            v152 = v82;
            v83 = n == 23 ? 0 : n;
            v154 = *(_QWORD *)(&v74 - 1);
            if ( (float)((float)((float)((float)*(__int64 *)(&v74 - 1) * (float)k3) * (float)0.043478262)
                       + (float)((float)((float)((float)v81 * (float)k1) * (float)0.023809524)
                               + (float)((float)v82 * (float)k2))) < v63 )
            {
              v63 = (float)((float)((float)((float)*(__int64 *)(&v74 - 1) * (float)k3) * (float)0.043478262)
                          + (float)((float)((float)((float)v81 * (float)k1) * (float)0.023809524)
                                  + (float)((float)v82 * (float)k2)));
              v64 = v75;
              v62 = v68;
              memcpy(Dst: v143, Src: v57, Size: 6 * v68);
              memcpy(Dst: v144, Src: v59, Size: 4 * v68);
            }
          }
          ++v65;
        }
        if ( v64 == -1 )
        {
          v84 = v38;
          for ( ii = 23; ii != 0; --ii )
          {
            v86 = *v84;
            if ( v86 != 0xFFFF && *(_DWORD *)&v23[4 * v86] != 0 )
            {
              v87 = 0;
              v88 = *(_DWORD *)&v146[4 * v86];
              if ( v88 < *(unsigned __int16 *)&v42[2 * v86] + v88 )
              {
                v89 = v61 - 1;
                v90 = (unsigned int *)&v145[4 * v88];
                v91 = *(unsigned __int16 *)&v42[2 * v86];
                do
                {
                  if ( *((_BYTE *)v53 + *v90 / 3) == 0 )
                  {
                    *++v89 = *v90;
                    ++v87;
                  }
                  ++v90;
                  --v91;
                }
                while ( v91 != 0 );
              }
              v93 = GetBestRenderOrder_r(
                      inCost: 0,
                      inBestCost: 0xFFFFFFFF,
                      renderList: v61,
                      renderListSize: v87,
                      triOrder: v59,
                      renderOrder: v57,
                      l1Cache: v36,
                      l2Cache: v38,
                      indexes: v124,
                      a10: v125,
                      a11: v126,
                      a12: v127,
                      a13: v128,
                      a14: v129,
                      a15: v130,
                      a16: v131,
                      a17: v132,
                      a18: v133,
                      a19: v134,
                      a20: v135,
                      a21: v136,
                      a22: v137,
                      a23: v138,
                      a24: v139,
                      a25: v140,
                      a26: v141,
                      a27: v142,
                      a28: indexes);
              v147 = v38;
              v95 = v93;
              v150 = v36;
              if ( v62 != 0 )
              {
                v96 = v143;
                for ( jj = v62; jj != 0; --jj )
                {
                  RenderTriangle(l1Cache: &v150, l2Cache: &v147, indexes: v96);
                  v96 += 3;
                }
              }
              v98 = v147;
              for ( kk = 0; kk < 0x17; ++kk )
              {
                if ( *v98 == v86 )
                  break;
                ++v98;
              }
              HIDWORD(v92) = v87;
              v155 = *(__int64 *)((char *)&v92 + 4);
              LODWORD(v92) = v95;
              v156 = v92;
              v100 = kk == 23 ? 0 : kk;
              v157 = *(_QWORD *)(&v94 - 1);
              if ( (float)((float)((float)((float)*(__int64 *)(&v94 - 1) * (float)k3) * (float)0.043478262)
                         + (float)((float)((float)((float)v92 * (float)k1) * (float)0.023809524)
                                 + (float)((float)*(__int64 *)((char *)&v92 + 4) * (float)k2))) < v63 )
              {
                v63 = (float)((float)((float)((float)*(__int64 *)(&v94 - 1) * (float)k3) * (float)0.043478262)
                            + (float)((float)((float)((float)v92 * (float)k1) * (float)0.023809524)
                                    + (float)((float)*(__int64 *)((char *)&v92 + 4) * (float)k2)));
                v64 = v95;
                v62 = v87;
                memcpy(Dst: v143, Src: v57, Size: 6 * v87);
                memcpy(Dst: v144, Src: v59, Size: 4 * v87);
              }
            }
            ++v84;
          }
          if ( v64 == -1 )
          {
            v101 = 0x7FFFFFFF;
            v102 = -1;
            v103 = 0;
            if ( v148 != 0 )
            {
              v104 = (int *)v23;
              for ( mm = v148; mm != 0; --mm )
              {
                if ( *v104 != 0 && *v104 < v101 )
                {
                  v101 = *v104;
                  v102 = v103;
                }
                ++v103;
                ++v104;
              }
            }
            v62 = 0;
            v106 = *(_DWORD *)&v146[4 * v102];
            v107 = *(unsigned __int16 *)&v42[2 * v102] + v106;
            if ( v106 < v107 )
            {
              v108 = v61 - 1;
              v110 = v107 - v106;
              v109 = (unsigned int *)&v145[4 * v106];
              do
              {
                if ( *((_BYTE *)v53 + *v109 / 3) == 0 )
                {
                  *++v108 = *v109;
                  ++v62;
                }
                ++v109;
                --v110;
              }
              while ( v110 != 0 );
            }
            GetBestRenderOrder_r(
              inCost: 0,
              inBestCost: 0xFFFFFFFF,
              renderList: v61,
              renderListSize: v62,
              triOrder: (unsigned int *)v144,
              renderOrder: v143,
              l1Cache: v36,
              l2Cache: v38,
              indexes: v124,
              a10: v125,
              a11: v126,
              a12: v127,
              a13: v128,
              a14: v129,
              a15: v130,
              a16: v131,
              a17: v132,
              a18: v133,
              a19: v134,
              a20: v135,
              a21: v136,
              a22: v137,
              a23: v138,
              a24: v139,
              a25: v140,
              a26: v141,
              a27: v142,
              a28: indexes);
          }
        }
        v147 = v36;
        v150 = v38;
        if ( v62 != 0 )
        {
          v111 = v62;
          v112 = v143;
          v113 = v144 - 4;
          do
          {
            v113 += 4;
            v114 = &indexes[*(_DWORD *)v113];
            v115 = *(_DWORD *)v113 / 3u;
            v116 = __ROL4__(*v114, 2);
            v117 = __ROL4__(v114[1], 2);
            v118 = __ROL4__(indexes[*(_DWORD *)v113 + 2], 2);
            --*(_DWORD *)&v23[v116];
            --*(_DWORD *)&v23[v117];
            --*(_DWORD *)&v23[v118];
            *((_BYTE *)v53 + v115) = 1;
            RenderTriangle(l1Cache: &v147, l2Cache: &v150, indexes: v112);
            --v111;
            *outputIndexes = *v112;
            outputIndexes[1] = v112[1];
            v119 = v112[2];
            v112 += 3;
            outputIndexes[2] = v119;
            outputIndexes += 3;
          }
          while ( v111 != 0 );
        }
        v149 -= v62;
        v120 = v149;
        memmove(Dst: v36, Src: v147, Size: 8u);
        memmove(Dst: v38, Src: v150, Size: 0x2Eu);
      }
      while ( v120 != 0 );
    }
    v121 = v151;
    idMem::Free(this: v151, ptr: v143, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v144, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v57, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v59, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v61, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v53, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v42, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v36, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v38, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v145, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v146, align: ALIGN_16);
    idMem::Free(this: v121, ptr: v23, align: ALIGN_16);
  }
}

