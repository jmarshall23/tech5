
// ========================================================================
// ?BlockToGridPos@@YAXHHHHAAH0@Z
// EA  : 0x8288D208
// RVA : 0x0088D208
// PDB : w:\tech5\engine\models\water\jobs\watergen.cpp
// ========================================================================

void __fastcall BlockToGridPos(
        const int blockLocX,
        const int blockLocY,
        const int blockX,
        const int blockY,
        int *gridX,
        int *gridY)
{
  *gridX = 16 * blockLocX + blockX;
  *gridY = 16 * blockLocY + blockY;
}


// ========================================================================
// ?GridPosToBlockLoc@@YAXHHHHAAH@Z
// EA  : 0x8288D228
// RVA : 0x0088D228
// PDB : w:\tech5\engine\models\water\jobs\watergen.cpp
// ========================================================================

void __fastcall GridPosToBlockLoc(
        const int gridX,
        const int gridY,
        const int numBlocksX,
        const int numBlocksY,
        int *blockPos)
{
  *blockPos = 16 * (16 * (gridY / 16 * numBlocksX + gridX / 16) + gridY % 16) + gridX % 16;
}


// ========================================================================
// ?BlockPosToBlockLoc@@YAXHHHAAH@Z
// EA  : 0x8288D278
// RVA : 0x0088D278
// PDB : w:\tech5\engine\models\water\jobs\watergen.cpp
// ========================================================================

void __fastcall BlockPosToBlockLoc(const int blockX, const int blockY, const int numBlocksX, int *offset)
{
  *offset = (blockY * numBlocksX + blockX) << 8;
}


// ========================================================================
// ?ApplyDisturbances@@YAXPBUdeferredWaterBlockGenParms_t@@@Z
// EA  : 0x8288D290
// RVA : 0x0088D290
// PDB : w:\tech5\engine\models\water\jobs\watergen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ApplyDisturbances(
        const deferredWaterBlockGenParms_t *parms,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE a7[12])
{
  double spacing; // fp29
  const waterDisturbanceParms_t *disturbances; // r21
  float *currBlock; // r27
  int v11; // r22
  unsigned int v12; // r24
  double v13; // fp26
  unsigned int i; // r26
  unsigned int v15; // r25
  float v16; // r28
  int v17; // r29
  float *p_z; // r31
  int v19; // r11
  double v20; // fp30
  int v21; // r11
  double v22; // fp0
  int v23; // r11
  double v24; // fp13
  double v25; // fp6
  double v26; // fp3
  double v27; // fp0
  double v28; // fp12
  double v29; // fp30
  double v30; // fp25
  double v31; // fp2
  double v32; // fp12
  double v33; // fp24
  double v34; // fp23
  __int64 v35; // r7
  int v36; // r11
  int v37; // r11
  float *v38; // r11
  float v39; // r10
  __int64 v40; // r9 OVERLAPPED
  double v41; // fp0
  double v42; // fp13
  double v43; // fp4
  double v44; // fp3
  double v45; // fp13
  double v46; // fp12
  double v47; // fp4
  unsigned int v48; // r11
  double v49; // fp6
  float v50[2]; // [sp+58h] [-F8h] BYREF
  __int64 v51; // [sp+60h] [-F0h]
  __int64 v52; // [sp+68h] [-E8h]
  __int64 v53; // [sp+70h] [-E0h]
  __int64 v54; // [sp+78h] [-D8h]
  __int64 v55; // [sp+80h] [-D0h]
  __int64 v56; // [sp+88h] [-C8h]
  __int64 v57; // [sp+90h] [-C0h]
  __int64 v58; // [sp+98h] [-B8h]
  __int64 v59; // [sp+A0h] [-B0h]

  spacing = parms->spacing;
  disturbances = parms->disturbances;
  currBlock = parms->currBlock;
  v11 = 0;
  v12 = 0;
  v13 = (float)((float)1.0 / parms->spacing);
  do
  {
    for ( i = 0; i < 0x10; ++i )
    {
      v15 = 0;
      LODWORD(v16) = __ROL4__(parms->blockLocX, 4) + i;
      v17 = __ROL4__(parms->blockLocY, 4) + v11;
      if ( parms->numDisturbances != 0 )
      {
        p_z = &disturbances->parms.z;
        while ( 1 )
        {
          v19 = *((_DWORD *)p_z - 7);
          v20 = 0.0;
          if ( v19 == 0 )
            break;
          if ( v19 == 1 || v19 == 3 )
          {
            *(double *)&a2 = (float)((float)(p_z[2] * (float)v13) + (float)0.5);
            a2 = floor(x: a2);
            *(float *)&a7[4] = *(p_z - 5);
            *(float *)&a7[8] = *(p_z - 6);
            v36 = (int)(float)*(double *)&a2;
            *(_DWORD *)a7 = *(_DWORD *)&a7[4] - v36;
            if ( v17 < *(_DWORD *)&a7[4] - v36 )
              goto LABEL_23;
            *(_DWORD *)a7 = *(_DWORD *)&a7[4] + v36;
            if ( v17 > *(_DWORD *)&a7[4] + v36 )
              goto LABEL_23;
            *(_DWORD *)a7 = *(_DWORD *)&a7[8] - v36;
            if ( SLODWORD(v16) < *(_DWORD *)&a7[8] - v36 || SLODWORD(v16) > *(_DWORD *)&a7[8] + v36 )
              goto LABEL_23;
            if ( *((_DWORD *)p_z - 7) == 3 )
            {
              v37 = *((_DWORD *)p_z - 5);
              v56 = *(_QWORD *)&a7[-4];
              v55 = *(_QWORD *)&a7[4];
              v50[0] = (float)*(__int64 *)&a7[4] * (float)spacing;
              v50[1] = (float)*(__int64 *)&a7[-4] * (float)spacing;
              v38 = v50;
            }
            else
            {
              v38 = p_z - 4;
            }
            v39 = v16;
            v40 = *(_QWORD *)v38;
            LODWORD(v35) = v17;
            v41 = p_z[2];
            v42 = (float)(p_z[2] * p_z[2]);
            v57 = *(__int64 *)((char *)&v40 - 4);
            v58 = v35;
            v43 = (float)((float)((float)*(__int64 *)((char *)&v40 - 4) * (float)spacing) - *(float *)&v40);
            v44 = (float)((float)((float)v35 * (float)spacing) - *((float *)&v40 + 1));
            *((double *)&a2 + 1) = (float)((float)v43 * (float)v43);
            if ( (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43)) < v42 )
            {
              v20 = *(p_z - 2);
              if ( HIDWORD(v40) != 3 )
              {
                v45 = (float)((float)v42 - (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43)));
                v46 = __frsqrte(v45);
                v47 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5))
                                                                                            * (float)v46)
                                                                                    - (float)1.5)
                                                                    * (float)v46)
                                                            * (float)((float)v45 * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v46
                                                                                            * (float)((float)v45 * (float)0.5))
                                                                                    * (float)v46)
                                                                            - (float)1.5)
                                                            * (float)v46))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5))
                                                            * (float)v46)
                                                    - (float)1.5)
                                    * (float)v46));
                *((double *)&a2 + 1) = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46) * (float)((float)v45 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46))
                                                                                             - (float)1.5)
                                                                             * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5)
                                                                                     * (float)v46))
                                                                     * (float)((float)v45 * (float)0.5))
                                                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46) * (float)((float)v45 * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46)
                                                                                             - (float)1.5)
                                                                             * (float)v46)))
                                                     - (float)1.5);
                v20 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46) * (float)((float)v45 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46)) - (float)1.5)
                                                                                            * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46))
                                                                                    * (float)((float)v45 * (float)0.5))
                                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46) * (float)((float)v45 * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5) * (float)v46)) - (float)1.5)
                                                                                    * (float)((float)-(float)((float)((float)((float)v46 * (float)((float)v45 * (float)0.5)) * (float)v46) - (float)1.5)
                                                                                            * (float)v46)))
                                                                    - (float)1.5)
                                                    * (float)v47)
                                            / (float)v41)
                                    * (float)v45)
                            * *(p_z - 2));
              }
            }
            goto LABEL_22;
          }
          if ( v19 != 2 )
            goto LABEL_22;
          *(_QWORD *)&a7[4] = *((_QWORD *)p_z - 2);
          v23 = v17;
          v24 = p_z[2];
          v54 = *(_QWORD *)a7;
          v53 = *(_QWORD *)&a7[-4];
          v25 = (float)((float)((float)*(__int64 *)a7 * (float)spacing) - *(float *)&a7[4]);
          v26 = (float)((float)((float)*(__int64 *)&a7[-4] * (float)spacing) - *(float *)&a7[8]);
          v27 = (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25));
          *((double *)&a2 + 1) = (float)((float)((float)v24 * (float)v24)
                                       - (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)));
          if ( *((double *)&a2 + 1) > 0.0 )
          {
            v28 = __frsqrte(v27);
            v29 = *(p_z - 2);
            v30 = *(p_z - 1);
            v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28
                                                                                                * (float)((float)v27 * (float)0.5))
                                                                                        * (float)v28)
                                                                                - (float)1.5)
                                                                * (float)v28)
                                                        * (float)((float)v27 * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v28
                                                                                        * (float)((float)v27 * (float)0.5))
                                                                                * (float)v28)
                                                                        - (float)1.5)
                                                        * (float)v28))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)v27 * (float)0.5))
                                                        * (float)v28)
                                                - (float)1.5)
                                * (float)v28));
            v32 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)v27 * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                                * (float)v28)
                                                                                        * (float)((float)v27 * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)v27 * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                        * (float)v28))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                                * (float)((float)v27 * (float)0.5))
                                                                                        * (float)v28)
                                                                                - (float)1.5)
                                                                * (float)v28))
                                                * (float)((float)v27 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)v27 * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                        * (float)v28)
                                                                                * (float)((float)v27 * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)v27 * (float)0.5)) * (float)v28)
                                                                                                - (float)1.5)
                                                                                * (float)v28))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v28
                                                                                        * (float)((float)v27 * (float)0.5))
                                                                                * (float)v28)
                                                                        - (float)1.5)
                                                        * (float)v28)))
                                - (float)1.5);
            v33 = (float)((float)v24
                        - (float)((float)((float)v32 * (float)v31)
                                * (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))));
            v34 = idMath::Exp16(f: (float)((float)-(float)(*p_z
                                                         * (float)((float)v24
                                                                 - (float)((float)((float)v32 * (float)v31) * (float)v27)))
                                         + (float)-(float)(p_z[1]
                                                         * (float)((float)((float)v32 * (float)v31) * (float)v27))));
            v20 = (float)((float)((float)v34 * idMath::Sin16(a: (float)((float)v30 * (float)v33))) * (float)v29);
            goto LABEL_22;
          }
LABEL_23:
          ++v15;
          p_z += 12;
          if ( v15 >= parms->numDisturbances )
            goto LABEL_24;
        }
        v21 = v17;
        *(_QWORD *)&a7[4] = *((_QWORD *)p_z - 2);
        *(float *)&a7[4] = v16;
        v22 = *(p_z - 1);
        v51 = *(_QWORD *)&a7[-4];
        v52 = *(_QWORD *)a7;
        idMath::Sin16(a: (float)((float)((float)((float)((float)((float)*(__int64 *)&a7[-4] * (float)spacing)
                                                       * *(float *)&a7[8])
                                               + (float)((float)((float)*(__int64 *)a7 * (float)spacing) * v16))
                                       * (float)v22)
                               + *p_z));
        v20 = *(p_z - 2);
LABEL_22:
        v48 = v12 + i;
        *(_DWORD *)&a7[4] = LOBYTE(parms->simulationParms[v48]);
        *(_DWORD *)a7 = *(_DWORD *)&a7[4];
        v49 = (float)((float)((float)((float)*(__int64 *)a7 * 0.0039215689) * (float)(parms->timeDelta * (float)v20))
                    + currBlock[v48]);
        v59 = *(_QWORD *)a7;
        currBlock[v48] = v49;
        goto LABEL_23;
      }
LABEL_24:
      ;
    }
    v12 += 16;
    ++v11;
  }
  while ( v12 < 0x100 );
}


// ========================================================================
// ?GenWaterSurface@@YAXPBUdeferredWaterBlockGenParms_t@@PBM@Z
// EA  : 0x8288D640
// RVA : 0x0088D640
// PDB : w:\tech5\engine\models\water\jobs\watergen.cpp
// ========================================================================

void __fastcall GenWaterSurface(const deferredWaterBlockGenParms_t *parms, const float *prevHM)
{
  double spacing; // fp0
  __int64 v4; // r9
  __int64 v5; // r7
  double v6; // fp27
  float *prevBlock; // r28
  float *currBlock; // r30
  float *p_spacing; // r29
  int v10; // r6
  unsigned int **p_simulationParms; // r5
  double v12; // fp1
  double v13; // fp26
  double v14; // fp31
  __int64 v15; // r10
  int v16; // r31
  int v17; // r7
  unsigned int v18; // r8
  double v19; // fp6
  double v20; // fp7
  double v21; // fp8
  double v22; // fp11
  double v23; // fp13
  float *v24; // r11
  double v25; // fp5
  double v26; // fp9
  double v27; // fp24
  double y; // fp11
  double v29; // fp23
  double v30; // fp22
  double v31; // fp21
  double v32; // fp6
  double v33; // fp20
  double v34; // fp11
  double v35; // fp13
  double v36; // fp11
  double v37; // fp13
  int v38; // r10
  int v39; // r10
  int v40; // r10
  int v41; // r10
  unsigned int *v42; // r16
  unsigned __int8 *vertGradient; // r15
  unsigned __int8 v44; // r8
  int v46; // ctr
  _BYTE v50[16]; // [sp+30h] [-300h] BYREF
  _BYTE v51[608]; // [sp+40h] [-2F0h] BYREF

  if ( parms->verts != nullptr )
  {
    spacing = parms->spacing;
    HIDWORD(v4) = 0x82000000;
    LODWORD(v4) = parms->gridHeight;
    LODWORD(v5) = parms->gridWidth;
    HIDWORD(v5) = 0x82000000;
    v6 = (float)-(float)((float)(parms->damping * parms->timeDelta) - (float)1.0);
    prevBlock = parms->prevBlock;
    currBlock = parms->currBlock;
    p_spacing = &parms->spacing;
    p_simulationParms = &parms->simulationParms;
    v12 = (float)((float)1.0 / (float)((float)((float)v5 - (float)1.0) * parms->spacing));
    v10 = 0;
    v13 = (float)((float)((float)((float)((float)((float)1.0 / (float)(parms->spacing * parms->spacing))
                                        * (float)(parms->speed * parms->speed))
                                * parms->timeDelta)
                        * parms->timeDelta)
                * (float)0.5);
    v14 = (float)((float)1.0 / (float)((float)((float)v4 - (float)1.0) * parms->spacing));
    do
    {
      HIDWORD(v15) = 0;
      v16 = 16 * v10;
      do
      {
        v17 = v16 + HIDWORD(v15);
        v18 = v16 + HIDWORD(v15);
        if ( v10 == 15 )
        {
          v19 = parms->currBlockD[HIDWORD(v15)];
LABEL_6:
          v20 = currBlock[v16 - 16 + HIDWORD(v15)];
          goto LABEL_7;
        }
        v19 = currBlock[v16 + 16 + HIDWORD(v15)];
        if ( v10 != 0 )
          goto LABEL_6;
        v20 = parms->currBlockU[HIDWORD(v15) + 240];
LABEL_7:
        if ( HIDWORD(v15) == 15 )
        {
          v21 = parms->currBlockR[16 * v10];
LABEL_9:
          v22 = currBlock[v17 - 1];
          goto LABEL_10;
        }
        v21 = currBlock[v17 + 1];
        if ( HIDWORD(v15) != 0 )
          goto LABEL_9;
        v22 = parms->currBlockL[16 * v10 + 15];
LABEL_10:
        v23 = (float)((float)((float)((float)-(float)((float)(currBlock[v18] * (float)4.0)
                                                    - (float)((float)((float)((float)v22 + (float)v21) + (float)v20)
                                                            + (float)v19))
                                    * (float)v13)
                            + (float)((float)(currBlock[v18] * (float)1.99) - (float)(prevHM[v18] * (float)0.99000001)))
                    * (float)v6);
        if ( __fabs(v23) < idMath::FLT_SMALLEST_NON_DENORMAL )
          v23 = 0.0;
        v24 = (float *)&v50[32 * HIDWORD(v15)];
        LODWORD(v15) = LOBYTE((*p_simulationParms)[v18]);
        v25 = (float)((float)((float)((float)((float)v19 - (float)v20) * (float)((float)1.0 / (float)spacing))
                            * (float)0.5)
                    * (float)((float)v15 * (float)0.0039215689));
        prevBlock[v18] = (float)((float)v15 * (float)0.0039215689) * (float)v23;
        v26 = (float)((float)((float)((float)((float)v21 - (float)v22) * (float)((float)1.0 / (float)spacing))
                            * (float)0.5)
                    * (float)((float)v15 * (float)0.0039215689));
        v27 = (float)((float)((float)((float)v15 * (float)0.0039215689) * (float)v23) + parms->waterOrg.z);
        LODWORD(v15) = __ROL4__(parms->blockLocY, 4) + v10;
        y = parms->waterOrg.y;
        v29 = (double)v15;
        LODWORD(v15) = __ROL4__(parms->blockLocX, 4) + HIDWORD(v15);
        v30 = (float)((float)v15 * *p_spacing);
        v31 = (float)__frsqrte((float)((float)((float)v25 * (float)v25) + (float)1.0));
        v33 = (float)__frsqrte((float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))
                                     + (float)1.0));
        v32 = (float)((float)v29 * *p_spacing);
        *v24 = (float)((float)v15 * *p_spacing) + parms->waterOrg.x;
        v24[1] = (float)y + (float)v32;
        v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31
                                                                                            * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0) * (float)0.5))
                                                                                    * (float)v31)
                                                                            - (float)1.5)
                                                            * (float)v31)
                                                    * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0)
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v31
                                                                                    * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0)
                                                                                            * (float)0.5))
                                                                            * (float)v31)
                                                                    - (float)1.5)
                                                    * (float)v31))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v31
                                                            * (float)((float)((float)((float)v25 * (float)v25)
                                                                            + (float)1.0)
                                                                    * (float)0.5))
                                                    * (float)v31)
                                            - (float)1.5)
                            * (float)v31));
        v35 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                            * (float)((float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) + (float)1.0) * (float)0.5))
                                                                                    * (float)v33)
                                                                            - (float)1.5)
                                                            * (float)v33)
                                                    * (float)((float)((float)((float)((float)v26 * (float)v26)
                                                                            + (float)((float)v25 * (float)v25))
                                                                    + (float)1.0)
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v33
                                                                                    * (float)((float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) + (float)1.0)
                                                                                            * (float)0.5))
                                                                            * (float)v33)
                                                                    - (float)1.5)
                                                    * (float)v33))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v33
                                                            * (float)((float)((float)((float)((float)v26 * (float)v26)
                                                                                    + (float)((float)v25 * (float)v25))
                                                                            + (float)1.0)
                                                                    * (float)0.5))
                                                    * (float)v33)
                                            - (float)1.5)
                            * (float)v33));
        v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0) * (float)0.5)) * (float)v31) - (float)1.5) * (float)v31)
                                                                                            * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0) * (float)0.5)) * (float)v31) - (float)1.5)
                                                                                            * (float)v31))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v31 * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0) * (float)0.5))
                                                                                            * (float)v31)
                                                                                    - (float)1.5)
                                                                    * (float)v31))
                                                    * (float)((float)((float)((float)v25 * (float)v25) + (float)1.0)
                                                            * (float)0.5))
                                            * (float)v34)
                                    - (float)1.5)
                    * (float)v34);
        v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) + (float)1.0) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33)
                                                                                            * (float)((float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) + (float)1.0) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) + (float)1.0) * (float)0.5)) * (float)v33) - (float)1.5)
                                                                                            * (float)v33))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)) + (float)1.0) * (float)0.5))
                                                                                            * (float)v33)
                                                                                    - (float)1.5)
                                                                    * (float)v33))
                                                    * (float)((float)((float)((float)((float)v26 * (float)v26)
                                                                            + (float)((float)v25 * (float)v25))
                                                                    + (float)1.0)
                                                            * (float)0.5))
                                            * (float)v35)
                                    - (float)1.5)
                    * (float)v35);
        v24[3] = (float)v30 * (float)v12;
        v38 = (int)(float)((float)((float)((float)v37 * (float)v26) + (float)1.0) * (float)127.5);
        v24[2] = v27;
        v24[4] = (float)v32 * (float)v14;
        if ( v38 >= 0 )
        {
          if ( v38 > 255 )
            LOBYTE(v38) = -1;
        }
        else
        {
          LOBYTE(v38) = 0;
        }
        *((_BYTE *)v24 + 20) = v38;
        v39 = (int)(float)((float)((float)((float)v37 * (float)v25) + (float)1.0) * (float)127.5);
        if ( v39 >= 0 )
        {
          if ( v39 > 255 )
            LOBYTE(v39) = -1;
        }
        else
        {
          LOBYTE(v39) = 0;
        }
        *((_BYTE *)v24 + 21) = v39;
        v40 = (int)(float)((float)((float)v37 + (float)1.0) * (float)127.5);
        if ( v40 >= 0 )
        {
          if ( v40 > 255 )
            LOBYTE(v40) = -1;
        }
        else
        {
          LOBYTE(v40) = 0;
        }
        *((_BYTE *)v24 + 22) = v40;
        *((_BYTE *)v24 + 23) = 0;
        v41 = (int)(float)((float)((float)v36 + (float)1.0) * (float)127.5);
        if ( v41 >= 0 )
        {
          if ( v41 > 255 )
            LOBYTE(v41) = -1;
        }
        else
        {
          LOBYTE(v41) = 0;
        }
        *((_BYTE *)v24 + 24) = v41;
        *((_BYTE *)v24 + 25) = 127;
        LODWORD(v15) = (int)(float)((float)((float)((float)v36 * (float)v25) + (float)1.0) * (float)127.5);
        if ( (int)v15 >= 0 )
        {
          if ( (int)v15 > 255 )
            LOBYTE(v15) = -1;
        }
        else
        {
          LOBYTE(v15) = 0;
        }
        v42 = *p_simulationParms;
        ++HIDWORD(v15);
        vertGradient = parms->vertGradient;
        *((_BYTE *)v24 + 26) = v15;
        *((_BYTE *)v24 + 27) = -1;
        LODWORD(v15) = v42[v18];
        v44 = vertGradient[v17];
        *((_BYTE *)v24 + 29) = BYTE6(v15);
        *((_BYTE *)v24 + 30) = BYTE5(v15);
        *((_BYTE *)v24 + 28) = v44;
        *((_BYTE *)v24 + 31) = BYTE4(v15);
      }
      while ( SHIDWORD(v15) < 16 );
      _R11 = &parms->verts[16 * v10];
      v46 = 16;
      _R9 = (_BYTE *)(v50 - (_BYTE *)_R11);
      _R10 = (_BYTE *)(v51 - (_BYTE *)_R11);
      _R8 = 16;
      do
      {
        __asm
        {
          lvx128    v63, r9, r11
          stvx128   v63, r0, r11
          lvx128    v62, r10, r11
          stvx128   v62, r11, r8
        }
        ++_R11;
        --v46;
      }
      while ( v46 != 0 );
      ++v10;
    }
    while ( v10 < 16 );
  }
}

