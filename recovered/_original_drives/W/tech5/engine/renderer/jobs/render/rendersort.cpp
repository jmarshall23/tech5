
// ========================================================================
// QuickSort_0
// EA  : 0x828E3AD0
// RVA : 0x008E3AD0
// PDB : w:\tech5\engine\renderer\jobs\render\rendersort.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall QuickSort_0(__int64 a, __int64 num)
{
  __int64 v2; // r25
  unsigned __int64 v3; // r11
  int v4; // r5
  int v5; // r28 OVERLAPPED
  __int64 v6; // r30 OVERLAPPED
  int v7; // r31 OVERLAPPED
  __int128 v8; // r11
  int *v9; // r8
  int v10; // r7
  int v11; // r6
  _DWORD *v12; // r11
  bool v13; // cr56
  int v14; // r10
  int v15; // r9
  _DWORD *v16; // r11
  bool v17; // cr57
  int v18; // r10
  int v19; // r10
  int v20; // r9
  _DWORD *v21; // r11
  _DWORD *v22; // r11
  int v23; // r5
  int v24; // r6
  int v25; // r8
  int v26; // r11
  int v27; // r7
  int v28; // r10
  _DWORD *v29; // r11
  _DWORD *v30; // r10
  bool v31; // cr57
  int v32; // r9
  int v33; // r8
  __int64 v34; // [sp+10h] [-850h] BYREF
  _BYTE v35[1016]; // [sp+18h] [-848h] BYREF
  unsigned __int64 v36; // [sp+410h] [-450h]
  _BYTE v37[1096]; // [sp+418h] [-448h] BYREF

  if ( (int)a > 0 )
  {
    LODWORD(v3) = a - 1;
    LODWORD(v2) = 0;
    v36 = v3;
    v34 = v2;
    do
    {
      v4 = 8 * v2;
      *(_QWORD *)(&v5 - 1) = *(_QWORD *)&v35[8 * (_DWORD)v2 - 8];
      v6 = *(_QWORD *)(8 * v2 + v5);
      v7 = HIDWORD(v6);
      LODWORD(a) = *(_DWORD *)(8 * v2 + v5 + 4);
      if ( (int)v6 - HIDWORD(v6) < 4 || (int)v2 >= 127 )
      {
        if ( SHIDWORD(v6) < (int)a )
        {
          v23 = HIDWORD(v6) + 1;
          do
          {
            v24 = HIDWORD(v6);
            v25 = HIDWORD(v6) + 1;
            if ( v23 <= (int)a )
            {
              v26 = 4 * HIDWORD(v6);
              v27 = a - HIDWORD(v6);
              v28 = 4 * v23;
              do
              {
                v29 = *(_DWORD **)(v26 + HIDWORD(a));
                v30 = *(_DWORD **)(v28 + HIDWORD(a));
                v31 = *v30 - *v29 > 0;
                if ( *v30 == *v29 )
                {
                  v32 = (v30[5] - v29[5]) / 648;
                  if ( v32 == 0 )
                    v32 = (v30[2] - v29[2]) / 1488;
                  v31 = v32 > 0;
                }
                if ( v31 )
                  v24 = v25;
                ++v25;
                --v27;
                v26 = 4 * v24;
                v28 = 4 * v25;
              }
              while ( v27 != 0 );
            }
            HIDWORD(v3) = 4 * a;
            v33 = *(_DWORD *)(4 * v24 + HIDWORD(a));
            *(_DWORD *)(4 * v24 + HIDWORD(a)) = *(_DWORD *)(4 * a + HIDWORD(a));
            *(_DWORD *)(4 * a + HIDWORD(a)) = v33;
            LODWORD(a) = a - 1;
          }
          while ( (int)a > SHIDWORD(v6) );
        }
        LODWORD(v2) = v2 - 1;
      }
      else
      {
        LODWORD(v3) = v6 + HIDWORD(v6);
        *(_QWORD *)((char *)&v8 + 4) = v3 >> 63;
        LODWORD(v8) = DWORD2(v8) + v6 + HIDWORD(v6);
        v9 = *(int **)(4 * ((__int64)v8 >> 1) + HIDWORD(a));
        do
        {
          v10 = *v9;
          while ( 1 )
          {
            v11 = 4 * v7;
            v12 = *(_DWORD **)(4 * v7 + HIDWORD(a));
            v13 = *v12 - v10 < 0;
            if ( *v12 == v10 )
            {
              v14 = (v12[5] - v9[5]) / 648;
              if ( v14 == 0 )
                v14 = (v12[2] - v9[2]) / 1488;
              v13 = v14 < 0;
            }
            if ( !v13 )
              break;
            ++v7;
          }
          while ( 1 )
          {
            v15 = 4 * a;
            v16 = *(_DWORD **)(4 * a + HIDWORD(a));
            v17 = *v16 - v10 > 0;
            if ( *v16 == v10 )
            {
              v18 = (v16[5] - v9[5]) / 648;
              if ( v18 == 0 )
                v18 = (v16[2] - v9[2]) / 1488;
              v17 = v18 > 0;
            }
            if ( !v17 )
              break;
            LODWORD(a) = a - 1;
          }
          if ( v7 > (int)a )
            break;
          ++v7;
          v19 = *(_DWORD *)(v11 + HIDWORD(a));
          LODWORD(a) = a - 1;
          *(_DWORD *)(v11 + HIDWORD(a)) = *(_DWORD *)(v15 + HIDWORD(a));
          *(_DWORD *)(v15 + HIDWORD(a)) = v19;
        }
        while ( v7 < (int)a );
        v20 = *v9;
        while ( 1 )
        {
          v21 = *(_DWORD **)(4 * v7 + HIDWORD(a));
          if ( *v21 != v20 || (v21[5] - v9[5]) / 648 != 0 || (v21[2] - v9[2]) / 1488 != 0 || v7 >= (int)v6 )
            break;
          ++v7;
        }
        while ( 1 )
        {
          v22 = *(_DWORD **)(4 * a + HIDWORD(a));
          if ( *v22 != v20 || (v22[5] - v9[5]) / 648 != 0 || (v22[2] - v9[2]) / 1488 != 0 || SHIDWORD(v6) >= (int)a )
            break;
          LODWORD(a) = a - 1;
        }
        HIDWORD(v3) = v35;
        LODWORD(v2) = v2 + 1;
        *(_QWORD *)&v37[v4] = v6;
        *(_QWORD *)&v35[v4] = *(_QWORD *)&v7;
        *(_QWORD *)(v4 + v5) = a;
      }
    }
    while ( (int)v2 >= 0 );
  }
}


// ========================================================================
// ?RenderSort@@YAXPBUrenderSortParms_t@@@Z
// EA  : 0x828E3DF0
// RVA : 0x008E3DF0
// PDB : w:\tech5\engine\renderer\jobs\render\rendersort.cpp
// ========================================================================

void __fastcall RenderSort(const renderSortParms_t *parms)
{
  __int64 v2; // r6
  int numDrawSurfs; // r11
  int v4; // r10
  int v5; // r8
  int v6; // r9
  __int64 v7; // r4
  int v8; // r10
  int v9; // r11
  int v10; // r7
  drawSurf_t **sortedDrawSurfs; // r8
  double sortEmitOnly; // fp0
  int v13; // r10
  int v14; // r7
  int v15; // r10
  drawSurf_t **v16; // r8
  double sortLight; // fp0
  int v18; // r10
  int v19; // r7
  int v20; // r10
  drawSurf_t **v21; // r8
  double sortPerturber; // fp0
  int v23; // r10
  int v24; // r7
  int v25; // r10
  drawSurf_t **v26; // r8
  double sortLast; // fp0
  int v28; // r10

  idRenderLog::OpenMainBlock(this: &renderLog, block: MRB_SORT_SURFACES);
  numDrawSurfs = parms->numDrawSurfs;
  v4 = 0;
  if ( numDrawSurfs > 0 )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      ++v4;
      LODWORD(v2) = &parms->drawSurfs[v6++];
      parms->sortedDrawSurfs[v5++] = (drawSurf_t *)v2;
      numDrawSurfs = parms->numDrawSurfs;
    }
    while ( v4 < numDrawSurfs );
  }
  LODWORD(v7) = numDrawSurfs;
  HIDWORD(v7) = parms->sortedDrawSurfs;
  QuickSort_0(a: v7, num: v2);
  v8 = 0;
  v9 = 0;
  parms->renderPasses[1].firstSurface = 0;
  v10 = parms->numDrawSurfs;
  if ( v10 < 4 )
  {
LABEL_11:
    if ( v9 < v10 )
    {
      v13 = v9;
      do
      {
        if ( parms->sortedDrawSurfs[v13]->sort >= (double)parms->settings->sortEmitOnly )
          break;
        ++v9;
        ++v13;
      }
      while ( v9 < v10 );
    }
  }
  else
  {
    sortedDrawSurfs = parms->sortedDrawSurfs;
    sortEmitOnly = parms->settings->sortEmitOnly;
    while ( sortedDrawSurfs[v8]->sort < sortEmitOnly )
    {
      if ( sortedDrawSurfs[v8 + 1]->sort >= sortEmitOnly )
      {
        ++v9;
        break;
      }
      if ( sortedDrawSurfs[v8 + 2]->sort >= sortEmitOnly )
      {
        v9 += 2;
        break;
      }
      if ( sortedDrawSurfs[v8 + 3]->sort >= sortEmitOnly )
      {
        v9 += 3;
        break;
      }
      v9 += 4;
      v8 += 4;
      if ( v9 >= v10 - 3 )
        goto LABEL_11;
    }
  }
  parms->renderPasses[1].lastSurface = v9 - 1;
  parms->renderPasses[2].firstSurface = v9;
  v14 = parms->numDrawSurfs;
  if ( v9 < v14 )
  {
    if ( v14 - v9 < 4 )
    {
LABEL_27:
      if ( v9 < v14 )
      {
        v18 = v9;
        do
        {
          if ( parms->sortedDrawSurfs[v18]->sort >= (double)parms->settings->sortLight )
            break;
          ++v9;
          ++v18;
        }
        while ( v9 < v14 );
      }
    }
    else
    {
      v15 = v9;
      v16 = parms->sortedDrawSurfs;
      sortLight = parms->settings->sortLight;
      while ( v16[v15]->sort < sortLight )
      {
        if ( v16[v15 + 1]->sort >= sortLight )
        {
          ++v9;
          break;
        }
        if ( v16[v15 + 2]->sort >= sortLight )
        {
          v9 += 2;
          break;
        }
        if ( v16[v15 + 3]->sort >= sortLight )
        {
          v9 += 3;
          break;
        }
        v9 += 4;
        v15 += 4;
        if ( v9 >= v14 - 3 )
          goto LABEL_27;
      }
    }
  }
  parms->renderPasses[2].lastSurface = v9 - 1;
  parms->renderPasses[3].firstSurface = v9;
  v19 = parms->numDrawSurfs;
  if ( v9 < v19 )
  {
    if ( v19 - v9 < 4 )
    {
LABEL_43:
      if ( v9 < v19 )
      {
        v23 = v9;
        do
        {
          if ( parms->sortedDrawSurfs[v23]->sort >= (double)parms->settings->sortPerturber )
            break;
          ++v9;
          ++v23;
        }
        while ( v9 < v19 );
      }
    }
    else
    {
      v20 = v9;
      v21 = parms->sortedDrawSurfs;
      sortPerturber = parms->settings->sortPerturber;
      while ( v21[v20]->sort < sortPerturber )
      {
        if ( v21[v20 + 1]->sort >= sortPerturber )
        {
          ++v9;
          break;
        }
        if ( v21[v20 + 2]->sort >= sortPerturber )
        {
          v9 += 2;
          break;
        }
        if ( v21[v20 + 3]->sort >= sortPerturber )
        {
          v9 += 3;
          break;
        }
        v9 += 4;
        v20 += 4;
        if ( v9 >= v19 - 3 )
          goto LABEL_43;
      }
    }
  }
  parms->renderPasses[3].lastSurface = v9 - 1;
  parms->renderPasses[4].firstSurface = v9;
  v24 = parms->numDrawSurfs;
  if ( v9 < v24 )
  {
    if ( v24 - v9 < 4 )
    {
LABEL_59:
      if ( v9 < v24 )
      {
        v28 = v9;
        do
        {
          if ( parms->sortedDrawSurfs[v28]->sort >= (double)parms->settings->sortLast )
            break;
          ++v9;
          ++v28;
        }
        while ( v9 < v24 );
      }
    }
    else
    {
      v25 = v9;
      v26 = parms->sortedDrawSurfs;
      sortLast = parms->settings->sortLast;
      while ( v26[v25]->sort < sortLast )
      {
        if ( v26[v25 + 1]->sort >= sortLast )
        {
          ++v9;
          break;
        }
        if ( v26[v25 + 2]->sort >= sortLast )
        {
          v9 += 2;
          break;
        }
        if ( v26[v25 + 3]->sort >= sortLast )
        {
          v9 += 3;
          break;
        }
        v9 += 4;
        v25 += 4;
        if ( v9 >= v24 - 3 )
          goto LABEL_59;
      }
    }
  }
  parms->renderPasses[4].lastSurface = v9 - 1;
  idRenderLog::CloseMainBlock(this: &renderLog);
}


// ========================================================================
// `dynamic initializer for 'register_RenderSort''
// EA  : 0x8334C390
// RVA : 0x0134C390
// PDB : w:\tech5\engine\renderer\jobs\render\rendersort.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_RenderSort__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_RenderSort,
           function: (void (__fastcall *)(void *))RenderSort,
           name: "RenderSort");
}

