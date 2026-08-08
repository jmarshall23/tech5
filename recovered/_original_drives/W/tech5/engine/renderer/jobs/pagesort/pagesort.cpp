
// ========================================================================
// ?PageListQuickSort@@YAXPA_J_J@Z
// EA  : 0x828D4C80
// RVA : 0x008D4C80
// PDB : w:\tech5\engine\renderer\jobs\pagesort\pagesort.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall PageListQuickSort(__int64 *a, int a2, __int64 num)
{
  int v3; // r31 OVERLAPPED
  __int64 i; // r5
  __int64 v5; // r10
  int v6; // r11
  __int64 *v7; // r6
  __int64 j; // r8
  __int64 v9; // r6
  int v10; // r8
  int v11; // r10
  int v12; // r7
  int v13; // r9
  __int64 v14; // r7
  int v15; // r10
  __int128 v16; // r8
  int v17; // r4
  _BYTE v18[2048]; // [sp+10h] [-810h] BYREF

  if ( a2 > 0 )
  {
    v3 = 0;
    for ( i = (unsigned int)(a2 - 1); ; i = *(_QWORD *)&v18[8 * v17 + 1024] )
    {
      while ( 1 )
      {
        LODWORD(v5) = v3;
        v6 = i;
        if ( (int)i - v3 < 4 || SHIDWORD(i) >= 127 )
          break;
        do
        {
          v7 = &a[v5];
          for ( j = *v7; (int)j < SHIDWORD(j); j = *v7 )
          {
            LODWORD(v5) = v5 + 1;
            v7 = &a[v5];
          }
          for ( HIDWORD(v5) = &a[v6]; *(_DWORD *)(HIDWORD(v5) + 4) > SHIDWORD(j); HIDWORD(v5) = &a[v6] )
            --v6;
          if ( (int)v5 > v6 )
            break;
          LODWORD(v5) = v5 + 1;
          --v6;
          *v7 = *(_QWORD *)HIDWORD(v5);
          *(_QWORD *)HIDWORD(v5) = j;
        }
        while ( (int)v5 < v6 );
        HIDWORD(v5) = 8 * HIDWORD(i)++;
        *(_QWORD *)&v18[HIDWORD(v5) + 1024] = i;
        LODWORD(i) = v6;
        *(_QWORD *)&v18[HIDWORD(v5)] = v5;
      }
      if ( v3 < (int)i )
      {
        HIDWORD(v9) = v3 + 1;
        do
        {
          v10 = v3;
          v11 = HIDWORD(v9);
          if ( SHIDWORD(v9) <= v6 )
          {
            v12 = HIDWORD(v9);
            v13 = v6 - HIDWORD(v9) + 1;
            do
            {
              v14 = a[v12];
              v9 = *(__int64 *)((char *)a + HIDWORD(v14));
              if ( (int)v14 > (int)v9 )
                v10 = v11;
              ++v11;
              --v13;
              v12 = v11;
            }
            while ( v13 != 0 );
          }
          v15 = v10;
          *((_QWORD *)&v16 + 1) = a[v6];
          *(_QWORD *)((char *)&v16 + 4) = a[v15];
          a[v15] = v16;
          a[v6--] = *(_QWORD *)((char *)&v16 + 4);
        }
        while ( v6 > v3 );
      }
      v17 = HIDWORD(i) - 1;
      if ( v17 < 0 )
        break;
      *(_QWORD *)&v3 = *(_QWORD *)&v18[8 * v17];
    }
  }
}


// ========================================================================
// ?PageSortJob@@YAXPBUpageSortParms_t@@@Z
// EA  : 0x828D4E20
// RVA : 0x008D4E20
// PDB : w:\tech5\engine\renderer\jobs\pagesort\pagesort.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall PageSortJob(const pageSortParms_t *parms)
{
  int v1; // r2 OVERLAPPED
  int indexMask; // r9
  __int64 v4; // r6
  int v5; // r8
  int v6; // r7
  int v7; // ctr
  int v8; // r10
  int v9; // r11
  __int64 v10; // r9
  int v11; // r11
  int v12; // ctr
  __int64 v13; // r4
  __int64 v14; // r10
  int v15; // r10
  int v16; // ctr
  int v17; // r10
  int v18; // r11
  __int64 *v19; // r30
  int v20; // r3

  indexMask = parms->indexMask;
  LODWORD(v4) = *parms->firstPageIndex;
  HIDWORD(v4) = *parms->lastPageIndex;
  v5 = indexMask & v4;
  v6 = indexMask & HIDWORD(v4);
  if ( (int)(indexMask & v4) > (indexMask & HIDWORD(v4)) )
  {
    if ( v6 >= 0 )
    {
      v11 = 0;
      v12 = v6 + 1;
      do
      {
        HIDWORD(v13) = parms->frameNum;
        HIDWORD(v14) = *(_DWORD *)(HIDWORD(parms->physicalPageNums[v11]) + 4 * LODWORD(parms->physicalPageNums[v11]))
                     + parms->pageFrameNum[LODWORD(parms->physicalPageNums[v11])];
        LODWORD(v13) = HIDWORD(v14) - parms->frameNum;
        *(_QWORD *)(&v1 - 1) = v13 << 32;
        LODWORD(v14) = HIDWORD(v13) | LODWORD(parms->physicalPageNums[v11]);
        parms->sortedPhysicalPageNums[v11++] = v14;
        --v12;
      }
      while ( v12 != 0 );
    }
    v15 = parms->indexMask - v5;
    if ( v15 + 1 > 0 )
    {
      v16 = v15 + 1;
      v17 = v6;
      v18 = v5;
      do
      {
        v19 = &parms->sortedPhysicalPageNums[v17++];
        v20 = parms->physicalPageNums[v18++];
        v19[1] = *(_QWORD *)(&v1 - 1);
        --v16;
      }
      while ( v16 != 0 );
    }
  }
  else if ( v6 - v5 + 1 > 0 )
  {
    v7 = v6 - v5 + 1;
    v8 = 0;
    v9 = v5;
    do
    {
      HIDWORD(v10) = *(_DWORD *)(HIDWORD(parms->physicalPageNums[v9]) + 4 * LODWORD(parms->physicalPageNums[v9]))
                   + parms->pageFrameNum[LODWORD(parms->physicalPageNums[v9])];
      LODWORD(v10) = parms->physicalPageNums[v9++];
      *(_QWORD *)(v8 + HIDWORD(v10) - parms->frameNum) = v10;
      v8 += 8;
      --v7;
    }
    while ( v7 != 0 );
  }
  *parms->firstPageIndex = 0;
  *parms->lastPageIndex = HIDWORD(v4) - v4;
  PageListQuickSort(a: parms->sortedPhysicalPageNums, a2: HIDWORD(v4) - v4 + 1, num: v4);
  *parms->done = 1;
}


// ========================================================================
// `dynamic initializer for 'register_PageSortJob''
// EA  : 0x8334C1D8
// RVA : 0x0134C1D8
// PDB : w:\tech5\engine\renderer\jobs\pagesort\pagesort.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_PageSortJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_PageSortJob,
           function: (void (__fastcall *)(void *))PageSortJob,
           name: "PageSortJob");
}

