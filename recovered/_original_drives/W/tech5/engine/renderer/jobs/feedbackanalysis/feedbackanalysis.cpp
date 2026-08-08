
// ========================================================================
// ?GetUniqueVirtualPages@@YAXPIAUpageIndices_t@@PIAGPIBUvirtualTextureInfo_t@@PIBXIII3I_N@Z
// EA  : 0x828D44D8
// RVA : 0x008D44D8
// PDB : w:\tech5\engine\renderer\jobs\feedbackanalysis\feedbackanalysis.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall GetUniqueVirtualPages(
        pageIndices_t *pageIndices,
        unsigned __int16 *temp,
        const virtualTextureInfo_t *vtInfo,
        char *data,
        const unsigned int width,
        const unsigned int height,
        const unsigned int bytePitch,
        const void *data2,
        const unsigned int data2Width,
        bool forceHighestDetail,
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
        int a28,
        int a29,
        unsigned __int8 a30)
{
  pageIndices_t *v31; // r31
  unsigned __int16 *v32; // r22
  unsigned __int16 *v33; // r25
  int v36; // r14
  __int64 v37; // r7 OVERLAPPED
  __int64 v38; // r18
  __int128 v39; // r11 OVERLAPPED
  __int64 v40; // r16
  int v41; // r27
  unsigned __int64 *indices; // r30
  int v43; // r23
  unsigned __int8 *v44; // r21
  int v45; // r10
  unsigned int v46; // r7
  unsigned int v47; // r5
  const virtualTextureInfo_t *v48; // r29
  unsigned int numLevels; // r3
  unsigned __int64 v50; // r5 OVERLAPPED
  int v51; // r28
  int v52; // r31
  unsigned int v53; // r14
  int v54; // r10
  unsigned int v55; // ctr
  unsigned __int64 v56; // r3
  int v57; // r31
  int v58; // r11
  int i; // r10
  __int64 v60; // r4
  int v61; // ctr
  __int16 v62; // r7
  __int16 v63; // r6
  int v64; // ctr
  int v65; // r7 OVERLAPPED
  int v66; // r31
  __int128 v67; // r9
  unsigned __int64 v68; // r7 OVERLAPPED
  _QWORD *v69; // r5 OVERLAPPED
  __int64 v70; // r6
  int v71; // r7
  unsigned __int64 v72; // r7
  unsigned __int64 v73; // r7
  int v74; // [sp+50h] [-9B0h]
  unsigned __int8 *v75; // [sp+54h] [-9ACh]
  int v76; // [sp+58h] [-9A8h]
  int v77; // [sp+5Ch] [-9A4h]
  _QWORD v78[144]; // [sp+E0h] [-920h] BYREF
  _QWORD v79[148]; // [sp+560h] [-4A0h] BYREF

  v31 = pageIndices;
  v32 = temp + 1024;
  v33 = temp + 3067;
  XMemSet(dest: temp, c: 0, count: 0x800u);
  HIDWORD(v39) = a30 - 1;
  v36 = -1;
  HIDWORD(v37) = (a30 != 0) - 1;
  v74 = -1;
  v38 = -1;
  v77 = BYTE3(v37) & 0x1F;
  DWORD2(v39) = bytePitch == 0 ? 0 : height;
  v40 = -1;
  v76 = DWORD2(v39);
  LOWORD(v41) = 0;
  indices = v31->indices;
  v43 = 0;
  if ( SDWORD2(v39) > -1 )
  {
    do
    {
      if ( v36 == -1 )
      {
        LODWORD(v39) = data2;
        DWORD2(v39) = 4 * a28;
      }
      else
      {
        LODWORD(v39) = &data[v36 * bytePitch];
        DWORD2(v39) = 4 * width;
      }
      DWORD2(v39) += v39;
      v75 = (unsigned __int8 *)DWORD2(v39);
      if ( (_DWORD)v39 != DWORD2(v39) )
      {
        v44 = (unsigned __int8 *)(v39 + 2);
        do
        {
          v45 = *v44;
          v46 = v44[1];
          v47 = v46 >> 4;
          DWORD1(v39) = ((16 * v45) & 0xF00) + *(v44 - 1);
          DWORD2(v39) = ((v45 << 8) & 0xF00) + *(v44 - 2);
          HIDWORD(v39) = v46 & 0xF;
          if ( v46 >> 4 != 0 && v47 < 0x10 )
          {
            if ( v38 == *(_QWORD *)((char *)&v39 + 4) && v40 == __PAIR64__(v47, HIDWORD(v39)) )
            {
              LODWORD(v39) = v43;
              if ( v43 != 0 )
              {
                do
                {
                  DWORD2(v39) = &indices[v39];
                  LODWORD(v39) = v33[(_DWORD)v39];
                  *(_QWORD *)((char *)&v39 + 12) = *(_QWORD *)(DWORD2(v39) - 8);
                  LODWORD(v37) = HIDWORD(v39) + 1;
                  *(_QWORD *)(DWORD2(v39) - 8) = v37;
                }
                while ( (_DWORD)v39 != 0 );
              }
            }
            else
            {
              v48 = &vtInfo[v47];
              numLevels = v48->numLevels;
              if ( v48->numLevels != 0 )
              {
                HIDWORD(v50) = v48->baseLevel;
                if ( (HIDWORD(v39) & (unsigned int)v77) >= HIDWORD(v50) )
                {
                  HIDWORD(v50) = numLevels - 1;
                  if ( (HIDWORD(v39) & (unsigned int)v77) <= numLevels - 1 )
                    HIDWORD(v50) = HIDWORD(v39) & v77;
                }
                LODWORD(v39) = v48->pagesWide;
                if ( DWORD2(v39) < (unsigned int)v39 && DWORD1(v39) < (unsigned int)v39 )
                {
                  v38 = *(_QWORD *)((char *)&v39 + 4);
                  LODWORD(v40) = v46 & 0xF;
                  HIDWORD(v40) = v46 >> 4;
                  LODWORD(v37) = DWORD2(v39) >> SBYTE3(v50);
                  HIDWORD(v37) = DWORD1(v39) >> SBYTE3(v50);
                  if ( (unsigned int)v39 >> SBYTE3(v50) != 0 )
                  {
                    v51 = 0;
                    DWORD2(v39) = HIDWORD(v50);
                    if ( HIDWORD(v50) < numLevels )
                    {
                      v52 = (16 * v47) & 0xF0;
                      while ( 1 )
                      {
                        v53 = 1664525 * ((((DWORD2(v39) << 11) | HIDWORD(v37)) << 11) | v37) + 1013904223;
                        LODWORD(v39) = ((((BYTE11(v39) & 0xF | v52) << 11) | WORD1(v37) & 0x7FF) << 11) | v37 & 0x7FF;
                        LODWORD(v50) = (v53 >> 11) ^ v53;
                        *(_QWORD *)&v39 = 4 * v39;
                        *((_QWORD *)&v39 + 1) = v50 >> 11;
                        *(_QWORD *)HIDWORD(v39) = *(_QWORD *)&v39;
                        LODWORD(v39) = ((unsigned __int16)(v50 >> 11) ^ (unsigned __int16)v53) & 0x3FF;
                        *(_QWORD *)(HIDWORD(v39) - 128) = v39;
                        LODWORD(v39) = temp[(_DWORD)v39];
                        if ( (_DWORD)v39 != 0 )
                          break;
LABEL_28:
                        ++DWORD2(v39);
                        LODWORD(v37) = (unsigned int)v37 >> 1;
                        HIDWORD(v37) >>= 1;
                        HIDWORD(v39) += 8;
                        if ( DWORD2(v39) >= numLevels )
                          goto LABEL_29;
                      }
                      while ( 1 )
                      {
                        v50 = indices[(int)v39 - 1];
                        if ( DWORD1(v39) == (v50 & 0xFFFFFFFC) )
                          break;
                        LODWORD(v39) = v32[(_DWORD)v39];
                        if ( (_DWORD)v39 == 0 )
                          goto LABEL_28;
                      }
                      numLevels = DWORD2(v39);
                      v51 = v39;
                      v43 = v39;
LABEL_29:
                      v36 = v74;
                      if ( HIDWORD(v50) < numLevels )
                      {
                        HIDWORD(v39) = (unsigned __int16)v41;
                        if ( (unsigned int)(unsigned __int16)v41 + 16 >= 0x7FB )
                        {
                          v31 = pageIndices;
                          break;
                        }
                        v54 = 0;
                        if ( v74 == -1 )
                          v54 = 16;
                        LOWORD(v37) = v51;
                        HIDWORD(v37) = v48->priorityBias - HIDWORD(v50) + numLevels + 1;
                        LODWORD(v50) = HIDWORD(v37) | v54;
                        DWORD2(v39) = (HIDWORD(v37) | v54) - 1;
                        if ( numLevels > HIDWORD(v50) )
                        {
                          LODWORD(v39) = &v78[numLevels];
                          v55 = numLevels - HIDWORD(v50);
                          do
                          {
                            *(_QWORD *)&v39 = *(_QWORD *)(v39 - 136);
                            LODWORD(v39) = v39 - 8;
                            *(__int64 *)((char *)&v37 + 4) = *(_QWORD *)v39;
                            v56 = *(_QWORD *)((char *)&v39 + 4) << 48;
                            v41 = (unsigned __int16)(WORD1(v39) + 1);
                            DWORD1(v39) *= 2;
                            v57 = (2 * v41) & 0x1FFFE;
                            HIDWORD(v37) = *(unsigned __int16 *)((char *)temp + DWORD1(v39));
                            LODWORD(v56) = *(_DWORD *)(v39 + 4) | 1;
                            --DWORD2(v39);
                            indices[HIDWORD(v39)] = v56;
                            *(unsigned __int16 *)((char *)v32 + v57) = WORD1(v37);
                            *(unsigned __int16 *)((char *)temp + DWORD1(v39)) = v41;
                            *(unsigned __int16 *)((char *)v33 + v57) = v37;
                            LOWORD(v37) = WORD1(v39) + 1;
                            HIDWORD(v39) = v41;
                            --v55;
                          }
                          while ( v55 != 0 );
                        }
                        v43 = HIDWORD(v39);
                        v58 = v50;
                        for ( i = v51; i != 0; i = v33[i] )
                        {
                          DWORD1(v39) = &indices[i];
                          *(_QWORD *)((char *)&v39 + 12) = *(_QWORD *)(DWORD1(v39) - 8);
                          if ( v58 != 0 )
                          {
                            HIDWORD(v39) &= 0xFFE0FFFF;
                            HIDWORD(v37) = HIDWORD(v39);
                            *(_QWORD *)(DWORD1(v39) - 8) = *(__int64 *)((char *)&v37 + 4);
                          }
                          ++v58;
                        }
                      }
                      v31 = pageIndices;
                    }
                    if ( v43 != 0 )
                    {
                      LODWORD(v39) = &indices[v43];
                      DWORD1(v39) = *(_DWORD *)(v39 - 4) | 1;
                      *(_QWORD *)(v39 - 8) = *(_QWORD *)&v39;
                    }
                    LODWORD(v39) = v33[v43];
                    if ( v33[v43] != 0 )
                    {
                      do
                      {
                        DWORD2(v39) = &indices[v39];
                        LODWORD(v39) = v33[(_DWORD)v39];
                        *(_QWORD *)((char *)&v39 + 12) = *(_QWORD *)(DWORD2(v39) - 8);
                        LODWORD(v37) = HIDWORD(v39) | 2;
                        *(_QWORD *)(DWORD2(v39) - 8) = v37;
                      }
                      while ( (_DWORD)v39 != 0 );
                    }
                    LODWORD(v39) = v51;
                    if ( v51 != 0 )
                    {
                      do
                      {
                        DWORD2(v39) = &indices[v39];
                        LODWORD(v39) = v33[(_DWORD)v39];
                        *(_QWORD *)((char *)&v39 + 12) = *(_QWORD *)(DWORD2(v39) - 8);
                        LODWORD(v37) = HIDWORD(v39) + 1;
                        *(_QWORD *)(DWORD2(v39) - 8) = v37;
                      }
                      while ( (_DWORD)v39 != 0 );
                    }
                  }
                }
              }
            }
          }
          v44 += 4;
          DWORD2(v39) = v44 - 2;
        }
        while ( v44 - 2 != v75 );
      }
      v74 = ++v36;
    }
    while ( v36 < v76 );
  }
  LODWORD(v39) = (unsigned __int16)v41;
  v60 = (unsigned __int16)v41;
  v31->totalNumPages = v39;
  v31->pageStats[0].numPages = 0;
  v31->pageStats[0].numVisPages = 0;
  v31->pageStats[0].numTopPages = 0;
  v31->pageStats[1].numPages = 0;
  v31->pageStats[1].numVisPages = 0;
  v31->pageStats[1].numTopPages = 0;
  v31->pageStats[2].numPages = 0;
  v31->pageStats[2].numVisPages = 0;
  v31->pageStats[2].numTopPages = 0;
  v31->pageStats[3].numPages = 0;
  v31->pageStats[3].numVisPages = 0;
  v31->pageStats[3].numTopPages = 0;
  if ( (_WORD)v41 != 0 )
  {
    DWORD2(v39) = indices - 1;
    v61 = (unsigned __int16)v41;
    do
    {
      *((_QWORD *)&v39 + 1) = *(_QWORD *)(DWORD2(v39) + 8);
      v62 = v39 & 1;
      DWORD1(v39) = (v39 & 2) == 0;
      LODWORD(v39) = &v31->pageStats[*(unsigned __int16 *)((char *)&vtInfo->physicalPagesPool
                                                         + ((16 * ((unsigned __int64)v39 >> 28)) & 0xF0))];
      HIDWORD(v39) = *(unsigned __int16 *)(v39 + 4);
      v63 = *(_WORD *)v39 + 1;
      *(_WORD *)(v39 + 2) += v62;
      *(_WORD *)v39 = v63;
      *(_WORD *)(v39 + 4) = WORD3(v39) + WORD1(v39);
      --v61;
    }
    while ( v61 != 0 );
    if ( (_WORD)v41 != 0 )
    {
      v64 = (unsigned __int16)v41;
      *((_QWORD *)&v39 + 1) = (unsigned int)indices | 0xFFFFFFFF00000000uLL;
      *(_QWORD *)((char *)&v39 + 12) = *(_QWORD *)((char *)&v39 + 4) << 48;
      do
      {
        *(_QWORD *)&v39 = *(_QWORD *)v39;
        *(_QWORD *)((char *)&v39 + 4) = HIWORD(*(_QWORD *)v39);
        DWORD2(v39) = BYTE11(v39) & 0x1F;
        if ( DWORD2(v39) != 0
          && (BYTE11(v39) & 0x10) == 0
          && *(unsigned __int16 *)(v39 + 2) <= (unsigned int)(v65 << SBYTE11(v39)) )
        {
          DWORD2(v39) = DWORD1(v39) + HIDWORD(v39);
          *(_QWORD *)v39 = *(_QWORD *)((char *)&v39 + 4);
        }
        LODWORD(v39) = v39 + 8;
        --v64;
      }
      while ( v64 != 0 );
    }
  }
  if ( (unsigned __int16)v41 > 1u )
  {
    v66 = 0;
    LODWORD(v60) = (unsigned __int16)v41 - 1;
    while ( 1 )
    {
      while ( 1 )
      {
        *((_QWORD *)&v39 + 1) = v60;
        if ( (int)v60 - HIDWORD(v60) < 4 || v66 >= 127 )
          break;
        DWORD1(v39) = v60 + HIDWORD(v60);
        *(_QWORD *)((char *)&v67 + 4) = *(_QWORD *)&v39 >> 63;
        LODWORD(v67) = DWORD2(v67) + v60 + HIDWORD(v60);
        v68 = indices[(unsigned int)((__int64)v67 >> 1)];
        do
        {
          for ( *(unsigned __int64 *)((char *)&v68 + 4) = indices[DWORD2(v39)];
                HIDWORD(v68) > (unsigned int)v68;
                *(unsigned __int64 *)((char *)&v68 + 4) = indices[DWORD2(v39)] )
          {
            ++DWORD2(v39);
          }
          DWORD1(v39) = &indices[v39];
          for ( *(_QWORD *)((char *)&v39 + 12) = *(_QWORD *)DWORD1(v39);
                HIDWORD(v39) < (unsigned int)v68;
                *(_QWORD *)((char *)&v39 + 12) = *(_QWORD *)DWORD1(v39) )
          {
            LODWORD(v39) = v39 - 1;
            DWORD1(v39) = &indices[v39];
          }
          if ( SDWORD2(v39) > (int)v39 )
            break;
          ++DWORD2(v39);
          *v69 = *(_QWORD *)((char *)&v39 + 12);
          LODWORD(v39) = v39 - 1;
          *(_QWORD *)DWORD1(v39) = *(unsigned __int64 *)((char *)&v68 + 4);
        }
        while ( SDWORD2(v39) <= (int)v39 );
        DWORD1(v39) = 8 * v66;
        HIDWORD(v39) = v79;
        ++v66;
        *(_QWORD *)((char *)v79 + DWORD1(v39)) = v60;
        LODWORD(v60) = v39;
        *(_QWORD *)((char *)&v78[16] + DWORD1(v39)) = *(_QWORD *)((char *)&v39 + 4);
      }
      if ( SHIDWORD(v60) < (int)v60 )
      {
        HIDWORD(v70) = HIDWORD(v60) + 1;
        do
        {
          HIDWORD(v39) = HIDWORD(v60);
          DWORD2(v39) = HIDWORD(v70);
          if ( SHIDWORD(v70) <= (int)v39 )
          {
            v71 = HIDWORD(v70);
            DWORD1(v39) = v39 - HIDWORD(v70) + 1;
            do
            {
              v72 = indices[v71];
              v70 = *(unsigned __int64 *)((char *)indices + HIDWORD(v72));
              if ( (unsigned int)v72 < (unsigned int)v70 )
                HIDWORD(v39) = DWORD2(v39);
              ++DWORD2(v39);
              --DWORD1(v39);
              v71 = DWORD2(v39);
            }
            while ( DWORD1(v39) != 0 );
          }
          DWORD2(v39) = 8 * HIDWORD(v39);
          *(_QWORD *)((char *)&v39 + 12) = indices[(_DWORD)v39];
          v73 = *(unsigned __int64 *)((char *)indices + DWORD2(v39));
          *(unsigned __int64 *)((char *)indices + DWORD2(v39)) = *(_QWORD *)((char *)&v39 + 12);
          indices[(_DWORD)v39] = v73;
          LODWORD(v39) = v39 - 1;
        }
        while ( (int)v39 > SHIDWORD(v60) );
      }
      if ( --v66 < 0 )
        break;
      v60 = v79[v66];
    }
  }
}


// ========================================================================
// ?FeedbackAnalysisJob@@YAXPBUanalyzeParms_t@@@Z
// EA  : 0x828D4C20
// RVA : 0x008D4C20
// PDB : w:\tech5\engine\renderer\jobs\feedbackanalysis\feedbackanalysis.cpp
// ========================================================================

void __fastcall FeedbackAnalysisJob(const analyzeParms_t *parms)
{
  unsigned int v1; // [sp+8h] [-2858h]
  bool v2; // [sp+Fh] [-2851h]
  int v3; // [sp+10h] [-2850h]
  int v4; // [sp+14h] [-284Ch]
  int v5; // [sp+18h] [-2848h]
  int v6; // [sp+1Ch] [-2844h]
  int v7; // [sp+20h] [-2840h]
  int v8; // [sp+24h] [-283Ch]
  int v9; // [sp+28h] [-2838h]
  int v10; // [sp+2Ch] [-2834h]
  int v11; // [sp+30h] [-2830h]
  int v12; // [sp+34h] [-282Ch]
  int v13; // [sp+38h] [-2828h]
  int v14; // [sp+3Ch] [-2824h]
  int v15; // [sp+40h] [-2820h]
  int v16; // [sp+44h] [-281Ch]
  int v17; // [sp+48h] [-2818h]
  int v18; // [sp+4Ch] [-2814h]
  int v19; // [sp+50h] [-2810h]
  int v20; // [sp+58h] [-2808h]
  unsigned __int16 v21[1024]; // [sp+60h] [-2800h] BYREF

  GetUniqueVirtualPages(
    pageIndices: parms->pageIndices,
    temp: v21,
    vtInfo: parms->vtInfo,
    data: (char *)parms->data,
    width: parms->width,
    height: parms->height,
    bytePitch: parms->bytePitch,
    data2: parms->data2,
    data2Width: v1,
    forceHighestDetail: v2,
    a11: v3,
    a12: v4,
    a13: v5,
    a14: v6,
    a15: v7,
    a16: v8,
    a17: v9,
    a18: v10,
    a19: v11,
    a20: v12,
    a21: v13,
    a22: v14,
    a23: v15,
    a24: v16,
    a25: v17,
    a26: v18,
    a27: v19,
    a28: parms->data2Width,
    a29: v20,
    a30: parms->forceHighestDetail);
}


// ========================================================================
// `dynamic initializer for 'register_FeedbackAnalysisJob''
// EA  : 0x8334C1B8
// RVA : 0x0134C1B8
// PDB : w:\tech5\engine\renderer\jobs\feedbackanalysis\feedbackanalysis.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_FeedbackAnalysisJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_FeedbackAnalysisJob,
           function: (void (__fastcall *)(void *))FeedbackAnalysisJob,
           name: "FeedbackAnalysisJob");
}

