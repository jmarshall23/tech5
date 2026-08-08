
// ========================================================================
// ?UpdatePageTables_Xenon@@YAXPBUpageImagesUpdateParms_t@@@Z
// EA  : 0x828D4FC0
// RVA : 0x008D4FC0
// PDB : w:\tech5\engine\renderer\jobs\pageupdate\pageupdate.cpp
// ========================================================================

void __fastcall UpdatePageTables_Xenon(const pageImagesUpdateParms_t *parms)
{
  int v2; // r27
  int v3; // r31
  pageImagesUpdate_t *updates; // r10
  pageImagesUpdate_t *v5; // r11
  int v6; // r4
  int v7; // r5
  pageImageInfo_t *pageTableImageInfo; // r9
  int bytePitch; // r7
  char v10; // r11
  int v11; // r6
  int v12; // r8
  int v13; // r11
  _WORD *v14; // r10
  unsigned int v15; // r6
  _DWORD *v16; // r9
  unsigned int v17; // ctr
  unsigned int v19; // r8
  unsigned int v21; // ctr
  int back_chain; // [sp+0h] [-40h] BYREF

  v2 = 0;
  if ( parms->numUpdates > 0 )
  {
    v3 = 0;
    do
    {
      updates = parms->updates;
      v5 = &parms->updates[v3];
      if ( !v5->cancelled && v5->pageTableImageInfo[0].bits != nullptr )
      {
        v6 = 0;
        HIBYTE(back_chain) = v5->pageSpot[1];
        BYTE1(back_chain) = v5->pageSpot[0];
        BYTE2(back_chain) = v5->pageSpot[3];
        LOBYTE(back_chain) = v5->pageSpot[2];
        if ( v5->effectivePageLevel >= 0 )
        {
          v7 = v3 * 256 + 104;
          pageTableImageInfo = updates[v3].pageTableImageInfo;
          do
          {
            bytePitch = pageTableImageInfo->bytePitch;
            v10 = updates[v3].effectivePageLevel - v6;
            v11 = updates[v3].spotX << v10;
            v12 = (updates[v3].spotY << v10) * bytePitch;
            v13 = 1 << v10;
            v14 = (_WORD *)(v12 + 2 * v11 + *(physicalPagesPool_t *)((char *)&updates->physicalPagesPool + v7));
            if ( v13 == 1 )
            {
              *v14 = HIWORD(back_chain);
            }
            else if ( v13 >= 8 )
            {
              _R9 = &back_chain;
              __asm
              {
                lvlx128   v63, r0, r9
                vspltw128 v63, v63, 0
              }
              v19 = ((unsigned int)(v13 - 1) >> 3) + 1;
              do
              {
                _R9 = v14;
                v21 = v19;
                do
                {
                  __asm { stvx128   v63, r0, r9 }
                  _R9 += 8;
                  --v21;
                }
                while ( v21 != 0 );
                --v13;
                v14 = (_WORD *)((char *)v14 + bytePitch);
              }
              while ( v13 != 0 );
            }
            else if ( v13 > 0 )
            {
              v15 = 2 * (((v13 - 1) & 0xFFFFFFFE) + 2);
              do
              {
                v16 = v14 - 2;
                if ( v15 >> 2 != 0 )
                {
                  v17 = v15 >> 2;
                  do
                  {
                    *++v16 = back_chain;
                    --v17;
                  }
                  while ( v17 != 0 );
                }
                --v13;
                v14 = (_WORD *)((char *)v14 + bytePitch);
              }
              while ( v13 != 0 );
            }
            updates = parms->updates;
            ++v6;
            v7 += 8;
            pageTableImageInfo = (pageImageInfo_t *)((char *)parms->updates + v7);
          }
          while ( v6 <= parms->updates[v3].effectivePageLevel );
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < parms->numUpdates );
  }
}


// ========================================================================
// ?UpdatePageImagesJob@@YAXPBUpageImagesUpdateParms_t@@@Z
// EA  : 0x828D5150
// RVA : 0x008D5150
// PDB : w:\tech5\engine\renderer\jobs\pageupdate\pageupdate.cpp
// ========================================================================

// attributes: thunk
void __fastcall UpdatePageImagesJob(const pageImagesUpdateParms_t *parms)
{
  UpdatePageTables_Xenon(parms);
}


// ========================================================================
// `dynamic initializer for 'register_UpdatePageImagesJob''
// EA  : 0x8334C1F8
// RVA : 0x0134C1F8
// PDB : w:\tech5\engine\renderer\jobs\pageupdate\pageupdate.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_UpdatePageImagesJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_UpdatePageImagesJob,
           function: (void (__fastcall *)(void *))UpdatePageImagesJob,
           name: "UpdatePageImagesJob");
}

