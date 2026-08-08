
// ========================================================================
// QuickSort
// EA  : 0x8288B280
// RVA : 0x0088B280
// PDB : w:\tech5\engine\models\transparency\jobs\transparencysort.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall QuickSort(__int64 a, __int64 num, int a3, unsigned __int64 a4)
{
  int v4; // r31 OVERLAPPED
  int v5; // r30 OVERLAPPED
  __int64 v6; // r10
  int v7; // r11
  __int128 v8; // r9
  int v9; // r7
  int *v10; // r5
  int i; // r6
  int j; // r8
  int v13; // r5
  int v14; // r8
  int v15; // r10
  int v16; // r7
  int v17; // r9
  int v18; // r6
  int v19; // r10
  int v20; // r7
  int v21; // r30
  _QWORD v22[128]; // [sp+10h] [-820h] BYREF
  _QWORD v23[132]; // [sp+410h] [-420h] BYREF

  if ( (int)a > 0 )
  {
    v4 = 0;
    LODWORD(a) = a - 1;
    v5 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        LODWORD(v6) = v4;
        v7 = a;
        if ( (int)a - v4 < 4 || v5 >= 127 )
          break;
        LODWORD(a4) = a + v4;
        *(_QWORD *)((char *)&v8 + 4) = a4 >> 63;
        LODWORD(v8) = DWORD2(v8) + a + v4;
        v9 = *(_DWORD *)(4 * ((__int64)v8 >> 1) + HIDWORD(a));
        do
        {
          v10 = (int *)(4 * v6 + HIDWORD(a));
          for ( i = *v10; *v10 > v9; i = *v10 )
          {
            LODWORD(v6) = v6 + 1;
            v10 = (int *)(4 * v6 + HIDWORD(a));
          }
          HIDWORD(v6) = 4 * v7 + HIDWORD(a);
          for ( j = *(_DWORD *)HIDWORD(v6); *(_DWORD *)HIDWORD(v6) < v9; j = *(_DWORD *)HIDWORD(v6) )
          {
            --v7;
            HIDWORD(v6) = 4 * v7 + HIDWORD(a);
          }
          if ( (int)v6 > v7 )
            break;
          LODWORD(v6) = v6 + 1;
          *v10 = j;
          --v7;
          *(_DWORD *)HIDWORD(v6) = i;
        }
        while ( (int)v6 < v7 );
        LODWORD(a4) = 8 * v5;
        HIDWORD(a4) = v23;
        ++v5;
        *(_QWORD *)((char *)v23 + a4) = a;
        LODWORD(a) = v7;
        *(_QWORD *)((char *)v22 + a4) = *(unsigned __int64 *)((char *)&a4 - 4);
      }
      if ( v4 < (int)a )
      {
        v13 = v4 + 1;
        do
        {
          v14 = v4;
          v15 = v4 + 1;
          if ( v13 <= v7 )
          {
            v16 = 4 * v13;
            v17 = v7 - v4;
            v18 = 4 * v4;
            do
            {
              if ( *(_DWORD *)(v16 + HIDWORD(a)) < *(_DWORD *)(v18 + HIDWORD(a)) )
                v14 = v15;
              ++v15;
              --v17;
              v16 = 4 * v15;
              v18 = 4 * v14;
            }
            while ( v17 != 0 );
          }
          v19 = 4 * v14;
          v20 = *(_DWORD *)(4 * v14 + HIDWORD(a));
          HIDWORD(a4) = *(_DWORD *)(4 * v7 + HIDWORD(a));
          *(_DWORD *)(v19 + HIDWORD(a)) = HIDWORD(a4);
          *(_DWORD *)(4 * v7-- + HIDWORD(a)) = v20;
        }
        while ( v7 > v4 );
      }
      v21 = v5 - 1;
      if ( v21 < 0 )
        break;
      a = v23[v21];
      *(_QWORD *)&v4 = v22[v21];
    }
  }
}


// ========================================================================
// ?TransparencyTriIndGen@@YAHPBUtransSortParms_t@@H@Z
// EA  : 0x8288B428
// RVA : 0x0088B428
// PDB : w:\tech5\engine\models\transparency\jobs\transparencysort.cpp
// ========================================================================

int __fastcall TransparencyTriIndGen(const transSortParms_t *parms, int quadOffset)
{
  int maxIndices; // r10
  float *v4; // r8
  int result; // r3
  unsigned __int16 *indices; // r11
  float *v7; // r8
  int v8; // ctr
  int *v9; // r10
  int v10; // r11
  int v11; // r5

  maxIndices = parms->maxIndices;
  v4 = &parms->quadDepths[quadOffset];
  result = parms->sortResult->numSortedQuads - quadOffset;
  if ( 6 * result > maxIndices )
    result = maxIndices / 6;
  indices = parms->indices;
  if ( result > 0 )
  {
    v7 = v4 - 1;
    v8 = result;
    v9 = (int *)(indices - 2);
    do
    {
      v10 = (4 * *(_DWORD *)++v7) & 0x1FFFC;
      v11 = (v10 + 3) << 16;
      v9[1] = (*(_DWORD *)v7 << 18) | (v10 + 2);
      v9[2] = v11 | v10;
      v9 += 3;
      *v9 = (v10 + 1) | v11;
      --v8;
    }
    while ( v8 != 0 );
  }
  return result;
}


// ========================================================================
// ?TransparencyEmissiveTriIndGen@@YAHPBUtransSortParms_t@@H@Z
// EA  : 0x8288B4B8
// RVA : 0x0088B4B8
// PDB : w:\tech5\engine\models\transparency\jobs\transparencysort.cpp
// ========================================================================

int __fastcall TransparencyEmissiveTriIndGen(const transSortParms_t *parms, int quadOffset)
{
  float *v2; // r7
  int maxIndices; // r11
  unsigned __int8 *v4; // r31
  int v5; // r10
  int v6; // r6
  int v7; // r5
  int v8; // r8
  unsigned __int16 *v9; // r9
  int v10; // r11
  int v11; // r4
  transSortResult_t *sortResult; // r11
  int result; // r3

  v2 = &parms->quadDepths[quadOffset];
  maxIndices = parms->maxIndices;
  v4 = &parms->emissiveQuads[quadOffset];
  v5 = parms->sortResult->numSortedQuads - quadOffset;
  if ( 6 * v5 > maxIndices )
    v5 = maxIndices / 6;
  v6 = 0;
  v7 = 0;
  if ( v5 > 0 )
  {
    v8 = 0;
    v9 = parms->indices2 - 2;
    do
    {
      v10 = (4 * *(_DWORD *)v2) & 0x1FFFC;
      if ( v4[*(_DWORD *)v2 & 0x7FFF] != 0 )
      {
        v11 = (v10 + 3) << 16;
        *((_DWORD *)v9 + 2) = v11 | v10;
        *((_DWORD *)v9 + 1) = (v10 << 16) | (v10 + 2);
        v6 += 3;
        v9 += 6;
        *(_DWORD *)v9 = (v10 + 1) | v11;
        v8 += 6;
      }
      if ( v8 > parms->maxIndices2 - 6 )
        break;
      ++v7;
      ++v2;
    }
    while ( v7 < v5 );
  }
  sortResult = parms->sortResult;
  result = 2 * v6 / 6;
  if ( result != sortResult->numEmissiveQuads )
    sortResult->numEmissiveQuads = result;
  return result;
}


// ========================================================================
// ?TransparencySortQuads@@YAHPBUtransSortParms_t@@@Z
// EA  : 0x8288B5A8
// RVA : 0x0088B5A8
// PDB : w:\tech5\engine\models\transparency\jobs\transparencysort.cpp
// ========================================================================

int __fastcall TransparencySortQuads(
        const transSortParms_t *parms,
        int a2,
        __int64 a3,
        unsigned __int8 *emissiveQuads,
        int a5,
        unsigned __int64 a6)
{
  float *quadDepths; // r22
  int v8; // r27
  int numSegmentAllocations; // r11
  int v10; // r24
  int v11; // r23
  int v12; // r26
  int v13; // r29
  transSortSegmentInfo_t *v14; // r11
  signed int quadsUsed; // r31
  transSortSegmentInfo_t *v16; // r11
  int segmentOffset; // r28
  bool emissivePass; // r25
  float *v19; // r8
  int v20; // ctr
  int v21; // r11
  int v22; // r31
  int v23; // r3
  transSortSegmentInfo_t *v24; // r11
  int quadsAllocated; // r29
  transSortSegmentInfo_t *v26; // r10
  int v27; // r11
  bool v28; // r4
  int v29; // ctr
  float *v30; // r8
  int v31; // r7
  int v32; // r9
  int v33; // r10
  int v34; // r11
  float *v35; // r10

  quadDepths = parms->quadDepths;
  v8 = 0;
  v10 = 0;
  v11 = 0;
  numSegmentAllocations = parms->numSegmentAllocations;
  if ( parms->collapse != 0 )
  {
    v12 = 0;
    if ( numSegmentAllocations > 0 )
    {
      v13 = 0;
      do
      {
        v14 = &parms->segmentInfo[v13];
        quadsUsed = v14->quadsUsed;
        if ( quadsUsed >= v14->quadsAllocated )
          quadsUsed = v14->quadsAllocated;
        v16 = &parms->segmentInfo[v13];
        segmentOffset = v16->segmentOffset;
        emissivePass = v16->emissivePass;
        if ( v8 != v16->segmentOffset )
        {
          memmove(Dst: &parms->verts[4 * v8], Src: &parms->verts[4 * segmentOffset], Size: quadsUsed << 7);
          memmove(Dst: &parms->quadDepths[v8], Src: &parms->quadDepths[segmentOffset], Size: 4 * quadsUsed);
        }
        memset(Dst: &parms->emissiveQuads[v8], Val: emissivePass, Size: quadsUsed);
        LODWORD(a6) = parms->numSegmentAllocations;
        ++v12;
        v10 += 4 * quadsUsed;
        v8 += quadsUsed;
        HIDWORD(a6) = &parms->segmentInfo[v13++];
        v11 += *(unsigned __int8 *)(HIDWORD(a6) + 12) * quadsUsed;
      }
      while ( v12 < (int)a6 );
    }
    LODWORD(a3) = 0;
    if ( v8 > 0 )
    {
      v19 = quadDepths;
      v20 = v8;
      emissiveQuads = nullptr;
      do
      {
        HIDWORD(a6) = (*(_DWORD *)v19 >> 15) & 0x10000;
        LODWORD(a6) = (unsigned __int8)(*(_DWORD *)v19 >> 23) - 127;
        if ( (int)a6 > 0 )
        {
          if ( (int)a6 <= 15 )
          {
            HIDWORD(a3) = (*(_DWORD *)v19 >> 11) & 0xFFF | ((_DWORD)a6 << 12);
            v21 = HIDWORD(a3) | HIDWORD(a6);
          }
          else
          {
            v21 = HIDWORD(a6) | 0xFFFF;
          }
        }
        else
        {
          v21 = 0;
        }
        LODWORD(a6) = (v21 << 15) | a3;
        *(_DWORD *)v19 = a6;
        LODWORD(a3) = a3 + 1;
        ++v19;
        --v20;
      }
      while ( v20 != 0 );
    }
  }
  else
  {
    v22 = 0;
    if ( numSegmentAllocations > 0 )
    {
      v23 = 0;
      do
      {
        v24 = &parms->segmentInfo[v23];
        quadsAllocated = v24->quadsAllocated;
        HIDWORD(a3) = v24->quadsUsed;
        if ( SHIDWORD(a3) >= quadsAllocated )
          HIDWORD(a3) = v24->quadsAllocated;
        v26 = &parms->segmentInfo[v23];
        v27 = v26->segmentOffset;
        v28 = v26->emissivePass;
        if ( SHIDWORD(a3) > 0 )
        {
          v29 = HIDWORD(a3);
          v30 = &quadDepths[v27];
          LODWORD(a3) = &quadDepths[v8 - 1];
          do
          {
            v31 = (*(_DWORD *)v30 >> 15) & 0x10000;
            v32 = (unsigned __int8)(*(_DWORD *)v30 >> 23) - 127;
            if ( v32 > 0 )
            {
              if ( v32 <= 15 )
                v33 = (*(_DWORD *)v30 >> 11) & 0xFFF | (v32 << 12) | v31;
              else
                v33 = v31 | 0xFFFF;
            }
            else
            {
              v33 = 0;
            }
            ++v30;
            LODWORD(a3) = a3 + 4;
            *(_DWORD *)a3 = (v33 << 15) | v27;
            emissiveQuads = parms->emissiveQuads;
            emissiveQuads[v27++] = v28;
            --v29;
          }
          while ( v29 != 0 );
        }
        HIDWORD(a6) = parms->numSegmentAllocations;
        LODWORD(a6) = 4 * quadsAllocated;
        ++v22;
        v8 += HIDWORD(a3);
        v10 += 4 * quadsAllocated;
        v11 += v28 * HIDWORD(a3);
        ++v23;
      }
      while ( v22 < SHIDWORD(a6) );
    }
  }
  if ( parms->sort != 0 )
  {
    QuickSort(a: __SPAIR64__((unsigned int)quadDepths, v8), num: a3, a3: (int)emissiveQuads, a4: a6);
    v34 = 0;
    if ( v8 > 0 )
    {
      v35 = quadDepths;
      while ( (int)(*(_DWORD *)v35 & 0xFFFF8000) > 0 )
      {
        ++v34;
        ++v35;
        if ( v34 >= v8 )
          goto LABEL_38;
      }
      v8 = v34;
    }
  }
LABEL_38:
  parms->sortResult->numSortedQuads = v8;
  parms->sortResult->numCollapsedVerts = v10;
  parms->sortResult->numEmissiveQuads = v11;
  return v8;
}

