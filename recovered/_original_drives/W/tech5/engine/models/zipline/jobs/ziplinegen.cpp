
// ========================================================================
// ?GenZipline@@YAXPBUzipLineGenParms_t@@@Z
// EA  : 0x82891F80
// RVA : 0x00891F80
// PDB : w:\tech5\engine\models\zipline\jobs\ziplinegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall GenZipline(const zipLineGenParms_t *parms)
{
  idNonUniformBSpline<idVec3> *controlSpline; // r4
  double time; // fp1
  const zipLineGenParms_t *v3; // r19
  signed int v4; // r17
  double v5; // fp19
  double v6; // fp30
  float y; // r9
  float z; // r8
  float *v9; // r7
  double v10; // fp17
  double v11; // fp25
  double v12; // fp24
  double v13; // fp23
  double v14; // fp9
  double v15; // fp0
  float *v16; // r11
  float v17; // r4
  float v18; // r3
  double v19; // fp29
  float v20; // r11
  double v21; // fp27
  BOOL downDirection; // r10
  double v23; // fp26
  double v24; // fp16
  double v25; // fp15
  double v26; // fp14
  double v27; // fp8
  double v28; // fp7
  double v29; // fp11
  double v30; // fp8
  double fractionBeforeLerp; // fp12
  double v32; // fp10
  double v33; // fp31
  double v34; // fp13
  int splineMaxSubdivisions; // r10
  signed int cableSubdivisions; // r9
  int *p_cableSubdivisions; // r23
  int maxVertices; // r11
  signed int splineTessellationDistance; // r6
  int v40; // r31
  int v41; // r28
  signed int v42; // r11
  unsigned int v43; // r4
  unsigned int v44; // r3
  __int64 v45; // r11 OVERLAPPED
  unsigned int v46; // r9 OVERLAPPED
  float *v47; // r18
  double v48; // fp20
  double v49; // fp22
  int v50; // r30
  float *v51; // r29
  idNonUniformBSpline<idVec3> *v52; // r4
  double v53; // fp30
  double v54; // fp0
  double v56; // fp2
  double v58; // fp6
  double v59; // fp1
  double v60; // fp4
  double v61; // fp1
  double v62; // fp1
  double v63; // fp12
  double v64; // fp11
  double v65; // fp24
  double v66; // fp25
  int v67; // r31
  __int64 v68; // r11
  float *v69; // r30
  idNonUniformBSpline<idVec3> *v70; // r4
  double v71; // fp30
  double v72; // fp1
  double v74; // fp2
  double v76; // fp6
  double v77; // fp1
  double v78; // fp4
  double v79; // fp1
  double v80; // fp1
  double v81; // fp12
  double v82; // fp11
  double cableDiameter; // fp12
  signed int v84; // r25
  double v85; // fp23
  double v86; // fp22
  float *v87; // r24
  double v97; // fp27
  double v98; // fp26
  double v99; // fp25
  double v100; // fp13
  double v101; // fp12
  double v102; // fp11
  double v105; // fp4
  double v106; // fp7
  double v107; // fp4
  double v108; // fp31
  double v109; // fp30
  double v110; // fp29
  double v111; // fp24
  const idMat3 *v112; // r3
  idMat3 *v113; // r3
  double v115; // fp3
  double v116; // fp2
  double v117; // fp1
  double v118; // fp13
  double v119; // fp12
  double v120; // fp11
  int v121; // r11
  double v122; // fp10
  double v123; // fp9
  double v124; // fp8
  double v127; // fp1
  double v128; // fp4
  double v129; // fp1
  double v130; // fp13
  double v131; // fp11
  double v132; // fp12
  double v133; // fp6
  double v134; // fp4
  double v135; // fp5
  double v138; // fp7
  double v139; // fp3
  double v140; // fp10
  double v141; // fp7
  double v142; // fp6
  double v143; // fp5
  int v144; // ctr
  const sweptPoint_t *sweptPoints; // r7
  int v146; // r9
  double v156; // fp8
  double v157; // fp10
  double v158; // fp19
  double v159; // fp20
  double v160; // fp18
  double s; // fp17
  double v162; // fp3
  double v163; // fp2
  double v164; // fp9
  int v166; // ctr
  int v170; // r27
  int v171; // r10
  signed int v172; // r11
  int *v173; // r9
  int v174; // r28
  int v175; // r7
  int v176; // r6
  int v177; // r4
  int v178; // r31
  int v179; // r10
  int v180; // r7
  int v181; // r8
  int v182; // r29
  int v183; // r5
  float x; // [sp+50h] [-1C00h] BYREF
  float v185; // [sp+54h] [-1BFCh] BYREF
  float v186; // [sp+58h] [-1BF8h] BYREF
  int v187; // [sp+5Ch] [-1BF4h]
  __int64 v188; // [sp+60h] [-1BF0h] BYREF
  float v189; // [sp+68h] [-1BE8h] BYREF
  const float *v190; // [sp+70h] [-1BE0h]
  int v191; // [sp+74h] [-1BDCh]
  float v192; // [sp+78h] [-1BD8h]
  float v193; // [sp+7Ch] [-1BD4h]
  float v194; // [sp+80h] [-1BD0h]
  idMat3 v195; // [sp+90h] [-1BC0h] BYREF
  idVec3 v196; // [sp+B8h] [-1B98h] BYREF
  idMat3 v197; // [sp+D0h] [-1B80h] BYREF
  idQuat v198; // [sp+110h] [-1B40h] BYREF
  _BYTE v199[8]; // [sp+140h] [-1B10h] BYREF
  char v200; // [sp+148h] [-1B08h] BYREF
  _BYTE v201[496]; // [sp+150h] [-1B00h] BYREF
  int v202; // [sp+33Ch] [-1914h] BYREF
  float v203[580]; // [sp+340h] [-1910h] BYREF

  controlSpline = (idNonUniformBSpline<idVec3> *)parms->controlSpline;
  time = parms->time;
  v3 = parms;
  v4 = 0;
  v187 = 0;
  v5 = controlSpline->times[0];
  v6 = (float)((float)time - controlSpline->times[0]);
  y = controlSpline->values[0].y;
  z = controlSpline->values[0].z;
  v9 = &controlSpline->times[controlSpline->numKnots];
  x = controlSpline->values[0].x;
  v185 = y;
  v186 = z;
  v10 = *(v9 - 1);
  v11 = z;
  v12 = x;
  v13 = y;
  idNonUniformBSpline<idVec3>::GetCurrentValue(this: (idNonUniformBSpline<idVec3> *)&v188, result: controlSpline, time);
  v14 = 1.0;
  v15 = (float)((float)v6 / (float)((float)v10 - (float)v5));
  v16 = &v3->controlSpline->times[3 * v3->controlSpline->numKnots];
  v193 = 1.0;
  v17 = v16[511];
  v18 = v16[509];
  v19 = v189;
  v20 = v16[510];
  v21 = *(float *)&v188;
  downDirection = v3->downDirection;
  v23 = *((float *)&v188 + 1);
  v24 = v17;
  v25 = v18;
  v26 = v20;
  v27 = (float)((float)((float)(x - *(float *)&v188) * (float)(x - *(float *)&v188))
              + (float)((float)(v186 - v189) * (float)(v186 - v189)));
  x = v18;
  v186 = v17;
  v28 = (float)((float)((float)(v185 - *((float *)&v188 + 1)) * (float)(v185 - *((float *)&v188 + 1))) + (float)v27);
  v185 = v20;
  v29 = __fsqrts(v28);
  v30 = __fsqrts((float)((float)((float)(*((float *)&v188 + 1) - v20) * (float)(*((float *)&v188 + 1) - v20))
                       + (float)((float)((float)(*(float *)&v188 - v18) * (float)(*(float *)&v188 - v18))
                               + (float)((float)(v189 - v17) * (float)(v189 - v17)))));
  v192 = v30;
  if ( !downDirection )
    v15 = (float)((float)1.0 - (float)((float)v6 / (float)((float)v10 - (float)v5)));
  fractionBeforeLerp = v3->fractionBeforeLerp;
  v32 = 0.0;
  v194 = 0.0;
  v33 = 0.0;
  if ( v15 > fractionBeforeLerp )
  {
    v34 = 0.2;
    if ( fractionBeforeLerp >= 0.2 )
    {
      v34 = 0.80000001;
      if ( fractionBeforeLerp <= 0.80000001 )
        v34 = fractionBeforeLerp;
    }
    v33 = (float)((float)((float)v15 - (float)v34) / (float)((float)0.89999998 - (float)v34));
    if ( v33 >= 0.0 )
    {
      if ( v33 > 1.0 )
        v33 = 1.0;
    }
    else
    {
      v33 = 0.0;
    }
  }
  splineMaxSubdivisions = v3->splineMaxSubdivisions;
  if ( splineMaxSubdivisions >= 512 )
    splineMaxSubdivisions = 512;
  cableSubdivisions = v3->cableSubdivisions;
  p_cableSubdivisions = &v3->cableSubdivisions;
  maxVertices = v3->maxVertices;
  if ( cableSubdivisions * splineMaxSubdivisions > maxVertices )
  {
    splineMaxSubdivisions = maxVertices / cableSubdivisions;
    __twllei(cableSubdivisions, 0);
    __twlgei(cableSubdivisions & ~(__ROL4__(maxVertices, 1) - 1), 0xFFFFFFFF);
  }
  v191 = (int)v29;
  splineTessellationDistance = v3->splineTessellationDistance;
  v40 = (int)v29 / splineTessellationDistance + 1;
  v41 = (int)v30 / splineTessellationDistance + 1;
  v42 = v41 + v40;
  __twllei(splineTessellationDistance, 0);
  __twllei(splineTessellationDistance, 0);
  __twlgei(splineTessellationDistance & ~(__ROL4__((int)v29, 1) - 1), 0xFFFFFFFF);
  __twlgei(splineTessellationDistance & ~(__ROL4__((int)v30, 1) - 1), 0xFFFFFFFF);
  if ( v41 + v40 > splineMaxSubdivisions )
  {
    v43 = v42 & ~(__ROL4__(v40 * splineMaxSubdivisions, 1) - 1);
    v44 = v42 & ~(__ROL4__(v41 * splineMaxSubdivisions, 1) - 1);
    v40 = v40 * splineMaxSubdivisions / v42;
    __twllei(v42, 0);
    __twlgei(v43, 0xFFFFFFFF);
    v41 = v41 * splineMaxSubdivisions / v42;
    __twllei(v42, 0);
    __twlgei(v44, 0xFFFFFFFF);
  }
  HIDWORD(v45) = &off_82010000;
  v46 = 0x82000000;
  v47 = (float *)&idMath::FLT_SMALLEST_NON_DENORMAL;
  v190 = &idMath::FLT_SMALLEST_NON_DENORMAL;
  if ( v29 <= 2.0 )
  {
    v4 = 1;
    v203[0] = v12;
    v203[1] = v13;
    v203[2] = v11;
    v187 = 1;
LABEL_27:
    v54 = idMath::FLT_SMALLEST_NON_DENORMAL;
    goto LABEL_28;
  }
  v48 = 0.0;
  v49 = 0.0;
  if ( v40 > 1 )
  {
    HIDWORD(v45) = v40 - 1;
    v188 = *(__int64 *)((char *)&v45 + 4);
    v48 = (float)((float)((float)1.0 / (float)*(__int64 *)((char *)&v45 + 4)) * (float)v6);
    v49 = (float)((float)((float)1.0 / (float)*(__int64 *)((char *)&v45 + 4)) * (float)v29);
  }
  v50 = 0;
  if ( v40 <= 0 )
    goto LABEL_27;
  v4 = v40;
  v187 = v40;
  v51 = v203;
  do
  {
    LODWORD(v45) = v50;
    v52 = (idNonUniformBSpline<idVec3> *)v3->controlSpline;
    v188 = v45;
    v53 = (float)v45;
    idNonUniformBSpline<idVec3>::GetCurrentValue(
      this: (idNonUniformBSpline<idVec3> *)&x,
      result: v52,
      time: (float)((float)((float)v45 * (float)v48) + (float)v5));
    HIDWORD(v45) = v3->downDirection;
    v54 = idMath::FLT_SMALLEST_NON_DENORMAL;
    if ( v3->downDirection )
    {
      _FP3 = (float)((float)((float)((float)((float)v23 - (float)v13) * (float)((float)v23 - (float)v13))
                           + (float)((float)((float)((float)v21 - (float)v12) * (float)((float)v21 - (float)v12))
                                   + (float)((float)((float)v19 - (float)v11) * (float)((float)v19 - (float)v11))))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v56 = (float)((float)((float)((float)((float)v23 - (float)v13) * (float)((float)v23 - (float)v13))
                          + (float)((float)((float)((float)v21 - (float)v12) * (float)((float)v21 - (float)v12))
                                  + (float)((float)((float)v19 - (float)v11) * (float)((float)v19 - (float)v11))))
                  * (float)0.5);
      __asm { fsel      f1, f3, f4, f0 }
      v58 = __frsqrte(_FP1);
      v59 = (float)((float)-(float)((float)((float)((float)v58
                                                  * (float)((float)((float)((float)((float)v23 - (float)v13)
                                                                          * (float)((float)v23 - (float)v13))
                                                                  + (float)((float)((float)((float)v21 - (float)v12)
                                                                                  * (float)((float)v21 - (float)v12))
                                                                          + (float)((float)((float)v19 - (float)v11)
                                                                                  * (float)((float)v19 - (float)v11))))
                                                          * (float)0.5))
                                          * (float)v58)
                                  - (float)1.5)
                  * (float)v58);
      v60 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58
                                                                                          * (float)((float)((float)((float)((float)v23 - (float)v13) * (float)((float)v23 - (float)v13)) + (float)((float)((float)((float)v21 - (float)v12) * (float)((float)v21 - (float)v12)) + (float)((float)((float)v19 - (float)v11) * (float)((float)v19 - (float)v11))))
                                                                                                  * (float)0.5))
                                                                                  * (float)v58)
                                                                          - (float)1.5)
                                                          * (float)v58)
                                                  * (float)((float)((float)((float)((float)v23 - (float)v13)
                                                                          * (float)((float)v23 - (float)v13))
                                                                  + (float)((float)((float)((float)v21 - (float)v12)
                                                                                  * (float)((float)v21 - (float)v12))
                                                                          + (float)((float)((float)v19 - (float)v11)
                                                                                  * (float)((float)v19 - (float)v11))))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v58
                                                                                  * (float)((float)((float)((float)((float)v23 - (float)v13) * (float)((float)v23 - (float)v13))
                                                                                                  + (float)((float)((float)((float)v21 - (float)v12) * (float)((float)v21 - (float)v12)) + (float)((float)((float)v19 - (float)v11) * (float)((float)v19 - (float)v11))))
                                                                                          * (float)0.5))
                                                                          * (float)v58)
                                                                  - (float)1.5)
                                                  * (float)v58))
                                  - (float)1.5)
                  * (float)v59);
      v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v58 * (float)((float)((float)((float)((float)v23 - (float)v13) * (float)((float)v23 - (float)v13)) + (float)((float)((float)((float)v21 - (float)v12) * (float)((float)v21 - (float)v12)) + (float)((float)((float)v19 - (float)v11) * (float)((float)v19 - (float)v11)))) * (float)0.5)) * (float)v58) - (float)1.5)
                                                                                                  * (float)v58)
                                                                                          * (float)((float)((float)((float)((float)v23 - (float)v13) * (float)((float)v23 - (float)v13)) + (float)((float)((float)((float)v21 - (float)v12) * (float)((float)v21 - (float)v12)) + (float)((float)((float)v19 - (float)v11) * (float)((float)v19 - (float)v11))))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v58 * (float)((float)((float)((float)((float)v23 - (float)v13) * (float)((float)v23 - (float)v13)) + (float)((float)((float)((float)v21 - (float)v12) * (float)((float)v21 - (float)v12)) + (float)((float)((float)v19 - (float)v11) * (float)((float)v19 - (float)v11)))) * (float)0.5)) * (float)v58) - (float)1.5)
                                                                                          * (float)v58))
                                                                          - (float)1.5)
                                                          * (float)v59)
                                                  * (float)v56)
                                          * (float)v60)
                                  - (float)1.5)
                  * (float)v60);
      x = (float)((float)(x
                        - (float)((float)((float)((float)((float)v21 - (float)v12) * (float)v61)
                                        * (float)((float)v53 * (float)v49))
                                + (float)v12))
                * (float)v33)
        + (float)((float)((float)((float)((float)v21 - (float)v12) * (float)v61) * (float)((float)v53 * (float)v49))
                + (float)v12);
      v186 = (float)((float)(v186
                           - (float)((float)((float)((float)((float)v19 - (float)v11) * (float)v61)
                                           * (float)((float)v53 * (float)v49))
                                   + (float)v11))
                   * (float)v33)
           + (float)((float)((float)((float)((float)v19 - (float)v11) * (float)v61) * (float)((float)v53 * (float)v49))
                   + (float)v11);
      v62 = (float)((float)((float)((float)((float)v23 - (float)v13) * (float)v61) * (float)((float)v53 * (float)v49))
                  + (float)v13);
      v185 = (float)((float)(v185 - (float)v62) * (float)v33) + (float)v62;
    }
    ++v50;
    v63 = v185;
    v64 = v186;
    *v51 = x;
    v51[1] = v63;
    v51[2] = v64;
    v51 += 3;
  }
  while ( v50 < v40 );
  v32 = v194;
  v14 = v193;
  v30 = v192;
LABEL_28:
  if ( v30 > 2.0 )
  {
    v65 = v32;
    v66 = v32;
    if ( v41 > 0 )
    {
      LODWORD(v45) = v41;
      v65 = (float)((float)((float)v10 - v3->time) / (float)v45);
      v188 = v45;
      v66 = (float)((float)v30 / (float)v45);
    }
    v67 = 1;
    if ( v41 >= 1 )
    {
      HIDWORD(v68) = v203;
      LODWORD(v68) = 12 * v4;
      v4 += v41;
      v187 = v4;
      v69 = (float *)((char *)v203 + v68);
      do
      {
        LODWORD(v68) = v67;
        v70 = (idNonUniformBSpline<idVec3> *)v3->controlSpline;
        v71 = (float)v68;
        v72 = (float)((float)((float)v68 * (float)v65) + v3->time);
        v188 = v68;
        idNonUniformBSpline<idVec3>::GetCurrentValue(this: (idNonUniformBSpline<idVec3> *)&x, result: v70, time: v72);
        HIDWORD(v68) = v3->downDirection;
        v54 = idMath::FLT_SMALLEST_NON_DENORMAL;
        if ( !v3->downDirection )
        {
          _FP3 = (float)((float)((float)((float)((float)v25 - (float)v21) * (float)((float)v25 - (float)v21))
                               + (float)((float)((float)((float)v24 - (float)v19) * (float)((float)v24 - (float)v19))
                                       + (float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23))))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v74 = (float)((float)((float)((float)((float)v25 - (float)v21) * (float)((float)v25 - (float)v21))
                              + (float)((float)((float)((float)v24 - (float)v19) * (float)((float)v24 - (float)v19))
                                      + (float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23))))
                      * (float)0.5);
          __asm { fsel      f1, f3, f4, f0 }
          v76 = __frsqrte(_FP1);
          v77 = (float)((float)-(float)((float)((float)((float)v76
                                                      * (float)((float)((float)((float)((float)v25 - (float)v21)
                                                                              * (float)((float)v25 - (float)v21))
                                                                      + (float)((float)((float)((float)v24 - (float)v19)
                                                                                      * (float)((float)v24 - (float)v19))
                                                                              + (float)((float)((float)v26 - (float)v23)
                                                                                      * (float)((float)v26 - (float)v23))))
                                                              * (float)0.5))
                                              * (float)v76)
                                      - (float)1.5)
                      * (float)v76);
          v78 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76
                                                                                              * (float)((float)((float)((float)((float)v25 - (float)v21) * (float)((float)v25 - (float)v21)) + (float)((float)((float)((float)v24 - (float)v19) * (float)((float)v24 - (float)v19)) + (float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23)))) * (float)0.5))
                                                                                      * (float)v76)
                                                                              - (float)1.5)
                                                              * (float)v76)
                                                      * (float)((float)((float)((float)((float)v25 - (float)v21)
                                                                              * (float)((float)v25 - (float)v21))
                                                                      + (float)((float)((float)((float)v24 - (float)v19)
                                                                                      * (float)((float)v24 - (float)v19))
                                                                              + (float)((float)((float)v26 - (float)v23)
                                                                                      * (float)((float)v26 - (float)v23))))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v76
                                                                                      * (float)((float)((float)((float)((float)v25 - (float)v21) * (float)((float)v25 - (float)v21)) + (float)((float)((float)((float)v24 - (float)v19) * (float)((float)v24 - (float)v19)) + (float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23))))
                                                                                              * (float)0.5))
                                                                              * (float)v76)
                                                                      - (float)1.5)
                                                      * (float)v76))
                                      - (float)1.5)
                      * (float)v77);
          v79 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)((float)v25 - (float)v21) * (float)((float)v25 - (float)v21)) + (float)((float)((float)((float)v24 - (float)v19) * (float)((float)v24 - (float)v19)) + (float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23)))) * (float)0.5)) * (float)v76) - (float)1.5) * (float)v76)
                                                                                              * (float)((float)((float)((float)((float)v25 - (float)v21) * (float)((float)v25 - (float)v21)) + (float)((float)((float)((float)v24 - (float)v19) * (float)((float)v24 - (float)v19)) + (float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23)))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v76 * (float)((float)((float)((float)((float)v25 - (float)v21) * (float)((float)v25 - (float)v21)) + (float)((float)((float)((float)v24 - (float)v19) * (float)((float)v24 - (float)v19)) + (float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23)))) * (float)0.5)) * (float)v76) - (float)1.5)
                                                                                              * (float)v76))
                                                                              - (float)1.5)
                                                              * (float)v77)
                                                      * (float)v74)
                                              * (float)v78)
                                      - (float)1.5)
                      * (float)v78);
          v185 = (float)((float)(v185
                               - (float)((float)((float)((float)((float)v26 - (float)v23) * (float)v79)
                                               * (float)((float)v71 * (float)v66))
                                       + (float)v23))
                       * (float)v33)
               + (float)((float)((float)((float)((float)v26 - (float)v23) * (float)v79)
                               * (float)((float)v71 * (float)v66))
                       + (float)v23);
          v186 = (float)((float)(v186
                               - (float)((float)((float)((float)((float)v24 - (float)v19) * (float)v79)
                                               * (float)((float)v71 * (float)v66))
                                       + (float)v19))
                       * (float)v33)
               + (float)((float)((float)((float)((float)v24 - (float)v19) * (float)v79)
                               * (float)((float)v71 * (float)v66))
                       + (float)v19);
          v80 = (float)((float)((float)((float)((float)v25 - (float)v21) * (float)v79) * (float)((float)v71 * (float)v66))
                      + (float)v21);
          x = (float)((float)(x - (float)v80) * (float)v33) + (float)v80;
        }
        ++v67;
        v81 = v185;
        v82 = v186;
        *v69 = x;
        v69[1] = v81;
        v69[2] = v82;
        v69 += 3;
      }
      while ( v67 <= v41 );
      v32 = v194;
      v14 = v193;
    }
  }
  cableDiameter = v3->cableDiameter;
  v195.mat[2].z = v14;
  v84 = 0;
  v195.mat[1].y = v14;
  v195.mat[0].x = v14;
  v85 = v32;
  v195.mat[1].z = v32;
  v195.mat[0].z = v32;
  v195.mat[0].y = v32;
  v195.mat[2].y = v32;
  v195.mat[2].x = v32;
  v195.mat[1].x = v32;
  v86 = (float)((float)v14 / (float)((float)cableDiameter * (float)3.1415927));
  if ( v4 > 0 )
  {
    v87 = (float *)&v202;
    _R31 = 16;
    _R26 = 17;
    _R27 = 18;
    _R28 = 12;
    _R29 = 13;
    _R30 = 14;
    _R22 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    _R21 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R20 = &_vmx_3f8000003f8000003f8000003f800000;
    do
    {
      v97 = v87[1];
      v98 = v87[2];
      v99 = v87[3];
      if ( v84 == v4 - 1 )
      {
        v100 = (float)(v87[1] - *(v87 - 2));
        v101 = (float)(v87[2] - *(v87 - 1));
        v102 = (float)(v87[3] - *v87);
      }
      else
      {
        v100 = (float)(v87[4] - v87[1]);
        v101 = (float)(v87[5] - v87[2]);
        v102 = (float)(v87[6] - v87[3]);
      }
      _FP7 = (float)((float)((float)((float)v100 * (float)v100)
                           + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101)))
                   - (float)v54);
      __asm { fsel      f5, f7, f8, f0 }
      v105 = __frsqrte(_FP5);
      v106 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105
                                                                                           * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5))
                                                                                   * (float)v105)
                                                                           - (float)1.5)
                                                           * (float)v105)
                                                   * (float)((float)((float)((float)v100 * (float)v100)
                                                                   + (float)((float)((float)v102 * (float)v102)
                                                                           + (float)((float)v101 * (float)v101)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v105
                                                                                   * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101)))
                                                                                           * (float)0.5))
                                                                           * (float)v105)
                                                                   - (float)1.5)
                                                   * (float)v105))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v105
                                                           * (float)((float)((float)((float)v100 * (float)v100)
                                                                           + (float)((float)((float)v102 * (float)v102)
                                                                                   + (float)((float)v101 * (float)v101)))
                                                                   * (float)0.5))
                                                   * (float)v105)
                                           - (float)1.5)
                           * (float)v105));
      v107 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)v105) - (float)1.5) * (float)v105)
                                                                                           * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5)) * (float)v105) - (float)1.5)
                                                                                           * (float)v105))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v105 * (float)((float)((float)((float)v100 * (float)v100) + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))) * (float)0.5))
                                                                                           * (float)v105)
                                                                                   - (float)1.5)
                                                                   * (float)v105))
                                                   * (float)((float)((float)((float)v100 * (float)v100)
                                                                   + (float)((float)((float)v102 * (float)v102)
                                                                           + (float)((float)v101 * (float)v101)))
                                                           * (float)0.5))
                                           * (float)v106)
                                   - (float)1.5)
                   * (float)v106);
      v108 = (float)((float)v107 * (float)v100);
      v196.x = (float)v107 * (float)v100;
      v109 = (float)((float)v101 * (float)v107);
      v196.y = (float)v101 * (float)v107;
      v110 = (float)((float)v102 * (float)v107);
      v196.z = (float)v102 * (float)v107;
      v111 = (float)((float)v107
                   * (float)((float)((float)v100 * (float)v100)
                           + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101))));
      idQuat::MakeRotation(this: (idQuat *)&v197, from: &v195.mat[2], to: &v196);
      v112 = idQuat::ToMat3(this: &v198, result: &v197);
      v113 = idMat3::operator*(this: (idMat3 *)&v197.mat[1].y, result: &v195, a: v112);
      v115 = v113->mat[0].z;
      v116 = (float)(v113->mat[0].z * (float)v108);
      v117 = v113->mat[0].x;
      v118 = v113->mat[0].y;
      v119 = (float)((float)v109 * v113->mat[0].x);
      v120 = (float)(v113->mat[0].y * (float)v110);
      v54 = *v47;
      v121 = *p_cableSubdivisions;
      v195.mat[2].x = v108;
      v195.mat[2].y = v109;
      v195.mat[2].z = v110;
      v122 = (float)((float)((float)v110 * (float)v117) - (float)v116);
      v123 = (float)((float)((float)v118 * (float)v108) - (float)v119);
      v124 = (float)((float)((float)v115 * (float)v109) - (float)v120);
      _FP4 = (float)((float)((float)((float)v123 * (float)v123)
                           + (float)((float)((float)v124 * (float)v124) + (float)((float)v122 * (float)v122)))
                   - (float)v54);
      __asm { fsel      f2, f4, f5, f0 }
      v127 = __frsqrte(_FP2);
      v128 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v127
                                                                                           * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)((float)v124 * (float)v124) + (float)((float)v122 * (float)v122))) * (float)0.5))
                                                                                   * (float)v127)
                                                                           - (float)1.5)
                                                           * (float)v127)
                                                   * (float)((float)((float)((float)v123 * (float)v123)
                                                                   + (float)((float)((float)v124 * (float)v124)
                                                                           + (float)((float)v122 * (float)v122)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v127
                                                                                   * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)((float)v124 * (float)v124) + (float)((float)v122 * (float)v122)))
                                                                                           * (float)0.5))
                                                                           * (float)v127)
                                                                   - (float)1.5)
                                                   * (float)v127))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v127
                                                           * (float)((float)((float)((float)v123 * (float)v123)
                                                                           + (float)((float)((float)v124 * (float)v124)
                                                                                   + (float)((float)v122 * (float)v122)))
                                                                   * (float)0.5))
                                                   * (float)v127)
                                           - (float)1.5)
                           * (float)v127));
      v129 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v127 * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)((float)v124 * (float)v124) + (float)((float)v122 * (float)v122))) * (float)0.5)) * (float)v127) - (float)1.5) * (float)v127)
                                                                                           * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)((float)v124 * (float)v124) + (float)((float)v122 * (float)v122))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v127 * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)((float)v124 * (float)v124) + (float)((float)v122 * (float)v122))) * (float)0.5)) * (float)v127) - (float)1.5)
                                                                                           * (float)v127))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v127 * (float)((float)((float)((float)v123 * (float)v123) + (float)((float)((float)v124 * (float)v124) + (float)((float)v122 * (float)v122))) * (float)0.5))
                                                                                           * (float)v127)
                                                                                   - (float)1.5)
                                                                   * (float)v127))
                                                   * (float)((float)((float)((float)v123 * (float)v123)
                                                                   + (float)((float)((float)v124 * (float)v124)
                                                                           + (float)((float)v122 * (float)v122)))
                                                           * (float)0.5))
                                           * (float)v128)
                                   - (float)1.5)
                   * (float)v128);
      v195.mat[1].x = (float)((float)((float)v115 * (float)v109) - (float)v120) * (float)v129;
      v195.mat[1].y = (float)v122 * (float)v129;
      v132 = (float)((float)((float)((float)v118 * (float)v108) - (float)v119) * (float)v129);
      v130 = v195.mat[1].x;
      v195.mat[1].z = (float)v123 * (float)v129;
      v133 = (float)((float)(v195.mat[1].z * (float)v108) - (float)(v195.mat[1].x * (float)v110));
      v134 = (float)((float)(v195.mat[1].x * (float)v109) - (float)(v195.mat[1].y * (float)v108));
      v131 = v195.mat[1].y;
      v135 = (float)((float)(v195.mat[1].y * (float)v110) - (float)(v195.mat[1].z * (float)v109));
      _FP10 = (float)((float)((float)((float)v134 * (float)v134)
                            + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133)))
                    - (float)v54);
      __asm { fsel      f8, f10, f1, f0 }
      v138 = __frsqrte(_FP8);
      v139 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v138
                                                                                           * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5))
                                                                                   * (float)v138)
                                                                           - (float)1.5)
                                                           * (float)v138)
                                                   * (float)((float)((float)((float)v134 * (float)v134)
                                                                   + (float)((float)((float)v135 * (float)v135)
                                                                           + (float)((float)v133 * (float)v133)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v138
                                                                                   * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133)))
                                                                                           * (float)0.5))
                                                                           * (float)v138)
                                                                   - (float)1.5)
                                                   * (float)v138))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v138
                                                           * (float)((float)((float)((float)v134 * (float)v134)
                                                                           + (float)((float)((float)v135 * (float)v135)
                                                                                   + (float)((float)v133 * (float)v133)))
                                                                   * (float)0.5))
                                                   * (float)v138)
                                           - (float)1.5)
                           * (float)v138));
      v140 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v138 * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5)) * (float)v138) - (float)1.5) * (float)v138)
                                                                                           * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v138 * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5)) * (float)v138) - (float)1.5)
                                                                                           * (float)v138))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v138 * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5))
                                                                                           * (float)v138)
                                                                                   - (float)1.5)
                                                                   * (float)v138))
                                                   * (float)((float)((float)((float)v134 * (float)v134)
                                                                   + (float)((float)((float)v135 * (float)v135)
                                                                           + (float)((float)v133 * (float)v133)))
                                                           * (float)0.5))
                                           * (float)v139)
                                   - (float)1.5)
                   * (float)v139);
      v141 = (float)((float)v135
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v138 * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5)) * (float)v138) - (float)1.5) * (float)v138) * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5))
                                                                                           * (float)((float)-(float)((float)((float)((float)v138 * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5)) * (float)v138) - (float)1.5) * (float)v138))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v138 * (float)((float)((float)((float)v134 * (float)v134) + (float)((float)((float)v135 * (float)v135) + (float)((float)v133 * (float)v133))) * (float)0.5)) * (float)v138)
                                                                                           - (float)1.5)
                                                                           * (float)v138))
                                                           * (float)((float)((float)((float)v134 * (float)v134)
                                                                           + (float)((float)((float)v135 * (float)v135)
                                                                                   + (float)((float)v133 * (float)v133)))
                                                                   * (float)0.5))
                                                   * (float)v139)
                                           - (float)1.5)
                           * (float)v139));
      v195.mat[0].x = v141;
      v142 = (float)((float)((float)(v195.mat[1].z * (float)v108) - (float)(v195.mat[1].x * (float)v110)) * (float)v140);
      v195.mat[0].y = (float)((float)(v195.mat[1].z * (float)v108) - (float)(v195.mat[1].x * (float)v110)) * (float)v140;
      v143 = (float)((float)((float)(v195.mat[1].x * (float)v109) - (float)(v195.mat[1].y * (float)v108)) * (float)v140);
      v195.mat[0].z = (float)((float)(v195.mat[1].x * (float)v109) - (float)(v195.mat[1].y * (float)v108)) * (float)v140;
      if ( v121 > 0 )
      {
        v144 = v121;
        sweptPoints = v3->sweptPoints;
        __asm { lvx128    v62, r0, r20 }
        __asm
        {
          lvx128    v13, r0, r21
          vspltisw128 v63, 0
          lvx128    v12, r0, r22
        }
        v146 = 0;
        _R11 = (float *)&v200;
        _R6 = 16;
        do
        {
          __asm { vor128    v61, v95, v63 }
          _R8 = _R11 - 2;
          __asm { vor128    v60, v95, v63 }
          _R5 = &v185;
          __asm { vor128    v59, v95, v63 }
          _R4 = &v186;
          __asm { vcmpequw128 v58, v93, v61 }
          _R3 = &x;
          __asm { stvx128   v61, r0, r8 }
          _R18 = (char *)&v188 + 4;
          _R17 = &v189;
          _R19 = &v188;
          __asm
          {
            vsldoi128 v57, v93, v58, 4
            stvx128   v57, r8, r6
          }
          v156 = sweptPoints[v146].tangent.y;
          v157 = sweptPoints[v146].tangent.z;
          v158 = sweptPoints[v146].pos.x;
          v159 = sweptPoints[v146].pos.z;
          v160 = sweptPoints[v146].pos.y;
          s = sweptPoints[v146].s;
          v162 = (float)((float)((float)v143 * sweptPoints[v146].tangent.x)
                       + (float)((float)v110 * sweptPoints[v146].tangent.z));
          v163 = (float)((float)((float)v130 * sweptPoints[v146].tangent.y)
                       + (float)((float)v141 * sweptPoints[v146].tangent.x));
          v164 = (float)((float)((float)v131 * sweptPoints[v146].tangent.y)
                       + (float)((float)((float)v142 * sweptPoints[v146].tangent.x)
                               + (float)((float)v109 * sweptPoints[v146].tangent.z)));
          v185 = (float)((float)v131 * sweptPoints[v146].tangent.y)
               + (float)((float)((float)v142 * sweptPoints[v146].tangent.x)
                       + (float)((float)v109 * sweptPoints[v146].tangent.z));
          ++v146;
          v186 = (float)((float)v132 * (float)v156) + (float)v162;
          x = (float)((float)v108 * (float)v157) + (float)v163;
          __asm { lvlx128   v56, r0, r5 }
          __asm
          {
            lvlx128   v55, r0, r4
            lvlx128   v54, r0, r3
            vrlimi128 v60, v54, 8, 0
            vrlimi128 v60, v56, 4, 3
          }
          __asm { vrlimi128 v60, v55, 2, 2 }
          __asm { vaddfp128 v0, v92, v62 }
          v189 = (float)((float)v164 * (float)v108) - (float)((float)v109 * x);
          *(float *)&v188 = (float)(v186 * (float)v109) - (float)((float)v164 * (float)v110);
          *((float *)&v188 + 1) = (float)((float)v110 * x) - (float)(v186 * (float)v108);
          __asm { vmaddfp   v0, v0, v13, v12 }
          *(_R11 - 1) = (float)((float)((float)v131 * (float)v160)
                              + (float)((float)((float)v142 * (float)v158) + (float)((float)v109 * (float)v159)))
                      + (float)v98;
          __asm { vcfpsxws128 v53, v0, 0 }
          *(_R11 - 2) = (float)((float)((float)v108 * (float)v159)
                              + (float)((float)((float)v130 * (float)v160) + (float)((float)v141 * (float)v158)))
                      + (float)v97;
          *_R11 = (float)((float)((float)v132 * (float)v160)
                        + (float)((float)((float)v143 * (float)v158) + (float)((float)v110 * (float)v159)))
                + (float)v99;
          _R11[1] = s;
          _R11[2] = (float)v85 * (float)v86;
          __asm
          {
            vpkswss128 v52, v85, v53
            vpkshus128 v0, v84, v52
            stvebx    v0, r11, r31
            stvebx    v0, r11, r26
            stvebx    v0, r11, r27
            lvlx128   v50, r0, r18
            lvlx128   v49, r0, r17
            lvlx128   v51, r0, r19
            vrlimi128 v59, v51, 8, 0
            vrlimi128 v59, v50, 4, 3
            vrlimi128 v59, v49, 2, 2
            vaddfp128 v0, v91, v62
            vmaddfp   v0, v0, v13, v12
            vcfpsxws128 v48, v0, 0
            vpkswss128 v47, v80, v48
            vpkshus128 v0, v79, v47
            stvebx    v0, r11, r28
            stvebx    v0, r11, r29
            stvebx    v0, r11, r30
          }
          _R11 += 8;
          --v144;
        }
        while ( v144 != 0 );
        v47 = (float *)v190;
        v4 = v187;
        v3 = parms;
      }
      _R11 = (int)&v3->vertices[v84 * *p_cableSubdivisions];
      if ( *p_cableSubdivisions > 0 )
      {
        v166 = *p_cableSubdivisions;
        _R10 = &v199[-_R11];
        _R9 = &v201[-_R11];
        _R8 = 16;
        do
        {
          __asm
          {
            lvx128    v46, r10, r11
            stvx128   v46, r0, r11
            lvx128    v45, r9, r11
            stvx128   v45, r11, r8
          }
          _R11 += 32;
          --v166;
        }
        while ( v166 != 0 );
        v54 = *v47;
      }
      ++v84;
      v85 = (float)((float)v111 + (float)v85);
      v87 += 3;
    }
    while ( v84 < v4 );
  }
  v170 = v4 - 1;
  v171 = 0;
  if ( v4 - 1 > 0 )
  {
    v172 = *p_cableSubdivisions;
    v173 = (int *)(v3->indices - 2);
    do
    {
      v174 = v171 + 1;
      v175 = *p_cableSubdivisions;
      v176 = 0;
      __twllei(v4, 0);
      v177 = v175 * v171;
      __twlgei(v4 & ~(__ROL4__(v171 + 1, 1) - 1), 0xFFFFFFFF);
      v178 = (v171 + 1) % v4 * v175;
      if ( v172 > 0 )
      {
        v179 = v175 * v171;
        v180 = v178 << 16;
        v181 = v177 << 16;
        v182 = 1 - v177;
        do
        {
          v183 = (v182 + v179) % v172;
          v173[1] = (v183 + v177) | v181;
          __twllei(v172, 0);
          v173[2] = ((v183 + v178) << 16) | (v183 + v178);
          ++v176;
          v173 += 3;
          *v173 = v180 | v179;
          __twlgei(v172 & ~(__ROL4__(v182 + v179, 1) - 1), 0xFFFFFFFF);
          v181 += 0x10000;
          v180 += 0x10000;
          ++v179;
          v172 = *p_cableSubdivisions;
        }
        while ( v176 < *p_cableSubdivisions );
      }
      v171 = v174;
    }
    while ( v174 < v170 );
  }
  *v3->numVertices = v4 * *p_cableSubdivisions;
  *v3->numIndices = 6 * v170 * *p_cableSubdivisions;
}


// ========================================================================
// `dynamic initializer for 'register_GenZipline''
// EA  : 0x83345640
// RVA : 0x01345640
// PDB : w:\tech5\engine\models\zipline\jobs\ziplinegen.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_GenZipline__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_GenZipline,
           function: (void (__fastcall *)(void *))GenZipline,
           name: "GenZipline");
}

