
// ========================================================================
// ?ParticleStageAxis@@YA?AVidMat3@@PBVidParticleStage@@H@Z
// EA  : 0x827E4D48
// RVA : 0x007E4D48
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

idMat3 *__fastcall ParticleStageAxis(
        idMat3 *result,
        const idParticleStage *stage,
        int diversity,
        int a4,
        int a5,
        __int64 a6)
{
  unsigned int v7; // r29
  const idVec3 *v8; // r26
  float *angleOffsetStart; // r30
  int v10; // r23
  double v11; // fp13
  double v12; // fp13
  float v14[28]; // [sp+60h] [-70h] BYREF

  v7 = (diversity << 10) & 0x7C00;
  v8 = (const idVec3 *)v14;
  result->mat[0].x = 1.0;
  angleOffsetStart = stage->direction.angleOffsetStart;
  v14[0] = 0.0;
  v10 = 2;
  result->mat[0].y = 0.0;
  v14[1] = 1.0;
  result->mat[0].z = 0.0;
  v14[2] = 0.0;
  result->mat[1].x = 0.0;
  v14[3] = 0.0;
  result->mat[1].y = 1.0;
  v14[4] = 0.0;
  result->mat[1].z = 0.0;
  v14[5] = 1.0;
  result->mat[2].x = 0.0;
  result->mat[2].y = 0.0;
  result->mat[2].z = 1.0;
  do
  {
    v11 = __fabs(angleOffsetStart[2]);
    v7 = 1664525 * v7 + 1013904223;
    LODWORD(a6) = (v7 >> 10) & 0x7FFF;
    v12 = (float)((float)((float)((float)((float)a6 * (float)((float)v11 - (float)-v11)) * 0.000030518509)
                        + *angleOffsetStart)
                + (float)-v11);
    if ( __fabs(v12) > 0.00000011920929 )
      idMat3::RotateSelf(this: result, axis: v8, angle: (float)(idMath::M_DEG2RAD * (float)v12));
    --v10;
    ++angleOffsetStart;
    ++v8;
  }
  while ( v10 != 0 );
  return result;
}


// ========================================================================
// ?ParticleOrigin@@YA?AVidVec3@@PBUparticleInput_t@@PAUparticleGen_t@@AAV1@@Z
// EA  : 0x827E5108
// RVA : 0x007E5108
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idVec3 *__fastcall ParticleOrigin(
        idVec3 *result,
        const particleInput_t *inputs,
        idRandom2 *g,
        idVec3 *origin,
        __int64 a5)
{
  const idParticleStage *stage; // r27
  char *v6; // r10
  idRandom2 *tables; // r25
  int v12; // ctr
  int *p_totalParticles; // r9
  idRandom2 *v14; // r31
  float y; // r10
  float z; // r9
  double v17; // fp1
  double x; // fp24
  double v19; // fp30
  __int64 v20; // r8
  idRandom2 *v21; // r5
  double v22; // fp26
  double v23; // fp29
  __int64 v24; // r8
  idRandom2 *v25; // r5
  int v26; // r2 OVERLAPPED
  double v27; // fp1
  _BYTE v28[12]; // r9 OVERLAPPED
  unsigned int type; // r11
  double v30; // fp25
  unsigned int v31; // r5
  double v32; // fp28
  unsigned int v33; // r3
  unsigned int v34; // r6
  __int64 v35; // r4
  unsigned int v36; // r4
  unsigned int v37; // r6
  double v38; // fp13
  __int128 v39; // r6
  unsigned int v40; // r9
  int v41; // r8
  double v42; // fp7
  double v43; // fp0
  unsigned int v44; // r10
  double v45; // fp6
  double v46; // fp13
  int v47; // r11
  double v48; // fp12
  unsigned int v49; // r11
  __int64 v50; // r9
  __int64 v51; // r6
  unsigned int v52; // r6
  double v53; // fp23
  double v54; // fp0
  double v55; // fp6
  double v56; // fp12
  double v57; // fp13
  double v60; // fp1
  double v61; // fp6
  __int64 v62; // r7
  __int64 v63; // r5
  __int64 v64; // r10
  double v65; // fp1
  double v66; // fp0
  __int128 v67; // r5
  unsigned int v68; // r9
  __int64 v69; // r10
  unsigned int v70; // r7
  double v71; // fp13
  double v72; // fp12
  double v73; // fp11
  prtCustomPthType_t v74; // r11
  unsigned int v75; // r11
  double v76; // fp30
  __int64 v77; // r8
  idRandom2 *v78; // r5
  double v79; // fp1
  int v80; // r10
  __int64 v81; // r7
  double v82; // fp1
  float *v83; // r3
  __int64 v84; // r8
  idRandom2 *v85; // r5
  double v86; // fp29
  __int64 v87; // r8
  idRandom2 *v88; // r5
  double v89; // fp28
  __int64 v90; // r8
  idRandom2 *v91; // r5
  double v92; // fp1
  double v93; // fp3
  double v94; // fp2
  __int64 v95; // r11
  double v96; // fp10
  double v97; // fp13
  double v98; // fp12
  double v99; // fp30
  __int64 v100; // r8
  idRandom2 *v101; // r5
  __int64 v102; // r7
  __int64 v103; // r5
  double v104; // fp1
  __int64 v105; // r9
  double v106; // fp13
  double v107; // fp0
  double v108; // fp11
  unsigned int v109; // r9
  double v110; // fp0
  __int64 v111; // r6
  int v112; // r10
  float *v113; // r3
  double v114; // fp11
  double v115; // fp0
  double v116; // fp13
  double v117; // fp1
  double v118; // fp30
  float *v119; // r3
  __int64 v120; // r8
  idRandom2 *v121; // r5
  double v122; // fp1
  double v123; // fp1
  double v124; // fp0
  double v125; // fp12
  double v126; // fp11
  double v127; // fp10
  double v128; // fp8
  double v129; // fp1
  int v130; // r9
  __int64 v131; // r6
  float *v132; // r3
  __int64 v133; // r8
  idRandom2 *v134; // r5
  double v135; // fp1
  double v136; // fp10
  double v137; // fp9
  double v138; // fp13
  double v139; // fp12
  double v140; // fp10
  double v143; // fp30
  double v144; // fp29
  __int64 v145; // r8
  idRandom2 *v146; // r5
  double v147; // fp28
  __int64 v148; // r8
  idRandom2 *v149; // r5
  double v150; // fp1
  double v151; // fp2
  double v152; // fp1
  __int64 v153; // r8
  idRandom2 *v154; // r5
  double v155; // fp30
  __int64 v156; // r8
  idRandom2 *v157; // r5
  double v158; // fp29
  __int64 v159; // r8
  idRandom2 *v160; // r5
  double v161; // fp1
  double v162; // fp10
  double v163; // fp9
  __int64 v164; // r8
  idRandom2 *v165; // r5
  __int64 v166; // r8
  idRandom2 *v167; // r5
  double v168; // fp1
  double v169; // fp30
  __int64 v170; // r8
  idRandom2 *v171; // r5
  double v172; // fp1
  double v173; // fp29
  __int64 v174; // r8
  idRandom2 *v175; // r5
  double v176; // fp1
  double v177; // fp28
  double v178; // fp30
  __int64 v179; // r8
  idRandom2 *v180; // r5
  double v181; // fp29
  __int64 v182; // r8
  idRandom2 *v183; // r5
  __int64 v184; // r8
  idRandom2 *v185; // r5
  int v186; // r2 OVERLAPPED
  double v187; // fp1
  unsigned int v188; // r11
  double v189; // fp28
  double v190; // fp0
  prtDirectionType_t v191; // r11
  double v192; // fp10
  double v193; // fp9
  double v194; // fp0
  double v195; // fp1
  double v196; // fp12
  double v197; // fp11
  double v198; // fp10
  double v199; // fp9
  double v200; // fp9
  double v201; // fp8
  double v202; // fp30
  __int64 v203; // r8
  idRandom2 *v204; // r5
  double v205; // fp29
  __int64 v206; // r8
  idRandom2 *v207; // r5
  __int64 v208; // r8
  idRandom2 *v209; // r5
  double v210; // fp1
  double v211; // fp25
  double v212; // fp28
  double v213; // fp24
  double v214; // fp23
  double v215; // fp22
  double v216; // fp21
  double v217; // fp20
  double v218; // fp19
  double v219; // fp18
  double v220; // fp17
  double v221; // fp10
  double v222; // fp9
  double v223; // fp27
  double v224; // fp26
  __int64 v225; // r8
  idRandom2 *v226; // r5
  double v227; // fp31
  double v228; // fp1
  double v229; // fp2
  double v230; // fp3
  double v231; // fp10
  double v232; // fp9
  double v233; // fp8
  double v234; // fp7
  double v235; // fp12
  double v236; // fp31
  double v237; // fp1
  double v238; // fp0
  double v239; // fp11
  double v240; // fp7
  double v241; // fp4
  double v242; // fp13
  double v243; // fp12
  double v244; // fp1
  double v245; // fp0
  double v246; // fp11
  double v247; // fp6
  double v248; // fp4
  double v249; // fp2
  double v252; // fp1
  double v253; // fp7
  double v254; // fp1
  double v255; // fp3
  double v256; // fp2
  double v257; // fp1
  double v259; // fp9
  double v260; // fp7
  double v261; // fp4
  double v262; // fp3
  double v263; // fp13
  double v264; // fp12
  unsigned int v265; // r7
  __int64 v266; // r6
  float *v267; // r3
  double v268; // fp0
  double v269; // fp12
  unsigned int v270; // r8
  double v271; // fp31
  float *v272; // r3
  float v273; // [sp+50h] [-160h] BYREF
  float v274; // [sp+54h] [-15Ch] BYREF
  idVec3 v275; // [sp+58h] [-158h] BYREF
  idVec3 v276; // [sp+68h] [-148h] BYREF
  idVec3 v277; // [sp+78h] [-138h] BYREF
  char v278; // [sp+8Ch] [-124h] BYREF
  float v279; // [sp+90h] [-120h]
  float v280; // [sp+94h] [-11Ch]
  float v281; // [sp+98h] [-118h]
  float v282; // [sp+9Ch] [-114h]
  float v283; // [sp+A0h] [-110h]
  float v284; // [sp+A4h] [-10Ch]
  float v285; // [sp+A8h] [-108h]
  float v286; // [sp+ACh] [-104h]
  float v287; // [sp+B0h] [-100h]

  stage = inputs->stage;
  v6 = &v278;
  tables = (idRandom2 *)inputs->tables;
  v12 = 9;
  p_totalParticles = &inputs->totalParticles;
  do
  {
    ++p_totalParticles;
    v6 += 4;
    *(_DWORD *)v6 = *p_totalParticles;
    --v12;
  }
  while ( v12 != 0 );
  v14 = g + 6;
  y = inputs->distribScale.y;
  z = inputs->distribScale.z;
  v17 = *(float *)&g[5].seed;
  v276.x = inputs->distribScale.x;
  v276.y = y;
  v276.z = z;
  x = v276.x;
  v22 = y;
  v19 = (float)(idParticleParm::Compute(this: stage->distribution.size, tables, frac: v17, rand: g, a5: g + 6, a6: a5)
              * v276.x);
  v23 = (float)(idParticleParm::Compute(
                  this: &stage->distribution.size[1],
                  tables,
                  frac: *(float *)&g[5].seed,
                  rand: v21,
                  a5: g + 6,
                  a6: v20)
              * v276.y);
  v27 = idParticleParm::Compute(
          this: &stage->distribution.size[2],
          tables,
          frac: *(float *)&g[5].seed,
          rand: v25,
          a5: g + 6,
          a6: v24);
  *(_DWORD *)&v28[4] = 0x82000000;
  *(_DWORD *)v28 = 0x82000000;
  type = stage->distribution.type;
  v30 = v276.z;
  v31 = (unsigned int)byte_821B0000;
  v32 = (float)((float)v27 * v276.z);
  v33 = 1013841920;
  if ( type <= 5 )
  {
    switch ( type )
    {
      case 1u:
        if ( stage->distribution.random )
        {
          HIDWORD(v50) = 1664525 * v14->seed + 1013904223;
          HIDWORD(v51) = HIDWORD(v50);
          v14->seed = (unsigned int)HIDWORD(v50);
          LODWORD(v51) = (HIDWORD(v50) >> 10) & 0x7FFF;
          v33 = 1664525 * HIDWORD(v50) + 1013904223;
          LODWORD(v50) = (v33 >> 10) & 0x7FFF;
          v14->seed = v33;
          v276.y = (float)((float)v51 * (float)0.000061037019) - (float)1.0;
          v276.x = (float)((float)v50 * (float)0.000061037019) - (float)1.0;
        }
        else
        {
          v276.x = 1.0;
          v276.y = 1.0;
        }
        idMath::SinCos16(a: (float)(idMath::TWO_PI * v276.x), s: (float *)v33, c: &origin->x, a4: &origin->y);
        origin->z = v276.y;
        origin->x = origin->x * (float)v19;
        origin->y = origin->y * (float)v23;
        origin->z = (float)v32 * origin->z;
        break;
      case 2u:
        if ( stage->distribution.random )
        {
          HIDWORD(v62) = 1664525 * v14->seed + 1013904223;
          v14->seed = (unsigned int)HIDWORD(v62);
          LODWORD(v62) = (HIDWORD(v62) >> 10) & 0x7FFF;
          HIDWORD(v63) = 1664525 * HIDWORD(v62) + 1013904223;
          LODWORD(v64) = (HIDWORD(v63) >> 10) & 0x7FFF;
          v14->seed = (unsigned int)HIDWORD(v63);
          HIDWORD(v64) = HIDWORD(v63);
          *(_QWORD *)&v276.x = v64;
          v275.x = (float)((float)v62 * (float)0.000061037019) - (float)1.0;
          LODWORD(v62) = 1664525 * HIDWORD(v63) + 1013904223;
          LODWORD(v63) = ((unsigned int)v62 >> 10) & 0x7FFF;
          v14->seed = v62;
          v275.z = (float)((float)v63 * (float)0.000061037019) - (float)1.0;
          v275.y = (float)((float)*(__int64 *)&v276.x * (float)0.000061037019) - (float)1.0;
          *(_QWORD *)&v276.x = v63;
          idVec3::NormalizeFast(this: &v275);
          v65 = v275.y;
          v66 = v275.z;
          origin->x = v275.x;
          origin->y = v65;
          origin->z = v66;
        }
        else
        {
          origin->x = 1.0;
          origin->y = 1.0;
          origin->z = 1.0;
        }
        origin->x = origin->x * (float)v19;
        origin->y = origin->y * (float)v23;
        origin->z = (float)v32 * origin->z;
        break;
      case 3u:
        DWORD1(v39) = 1664525 * v14->seed + 1013904223;
        v14->seed = *(_DWORD *)((unsigned int)&v39 + 4);
        DWORD2(v39) = (DWORD1(v39) >> 10) & 0x7FFF;
        v40 = 1664525 * DWORD1(v39) + 1013904223;
        v14->seed = v40;
        LODWORD(v39) = (v40 >> 10) & 0x7FFF;
        v41 = 1664525 * v40;
        v42 = (float)(__int64)v39;
        v43 = (float)((float)((float)*(__int64 *)((char *)&v39 + 4) * (float)0.000061037019) - (float)1.0);
        v31 = 1664525 * v40 + 1013904223;
        v14->seed = v31;
        *(_DWORD *)&v28[8] = (v31 >> 10) & 0x7FFF;
        *(_QWORD *)&v276.x = *(_QWORD *)&v28[4];
        v44 = 1664525 * v31 + 1013904223;
        v45 = (float)*(__int64 *)&v28[4];
        v46 = (float)((float)((float)v42 * (float)0.000061037019) - (float)1.0);
        *(_DWORD *)&v28[4] = (v44 >> 10) & 0x7FFF;
        v14->seed = v44;
        v47 = (unsigned __int64)(715827883LL * *(int *)&v28[4]) >> 32;
        v48 = (float)((float)((float)v45 * (float)0.000061037019) - (float)1.0);
        *(_DWORD *)v28 = 3 * v47;
        v49 = *(_DWORD *)&v28[4] - 6 * v47;
        if ( v49 <= 5 )
        {
          switch ( v49 )
          {
            case 1u:
              v46 = 1.0;
              break;
            case 2u:
              v43 = 1.0;
              break;
            case 3u:
              v48 = -1.0;
              break;
            case 4u:
              v46 = -1.0;
              break;
            default:
              if ( v49 != 0 )
                v43 = -1.0;
              else
                v48 = 1.0;
              break;
          }
        }
        origin->x = (float)v19 * (float)v48;
        origin->y = (float)v23 * (float)v46;
        origin->z = (float)v32 * (float)v43;
        break;
      case 4u:
        v52 = 1664525 * v14->seed + 1013904223;
        v14->seed = v52;
        *(_DWORD *)v28 = (v52 >> 10) & 0x7FFF;
        *(_DWORD *)&v28[8] = ((1664525 * v52 + 1013904223) >> 10) & 0x7FFF;
        v14->seed = 1664525 * v52 + 1013904223;
        v53 = (float)((float)((float)*(__int64 *)&v28[8] * (float)0.000061037019) - (float)1.0);
        *(_QWORD *)&v276.x = *(_QWORD *)&v28[4];
        idMath::SinCos16(
          a: (float)((float)((float)((float)*(__int64 *)&v28[4] * (float)0.000061037019) - (float)1.0) * idMath::TWO_PI),
          s: (float *)(1664525 * v52),
          c: &v276.x,
          a4: &v276.y);
        v54 = v276.x;
        v55 = (float)(v276.x * v276.x);
        v56 = v276.y;
        v57 = idMath::FLT_SMALLEST_NON_DENORMAL;
        origin->z = (float)v53 * (float)v32;
        _FP4 = (float)((float)((float)((float)v56 * (float)v56) + (float)v55) - (float)v57);
        __asm { fsel      f2, f4, f5, f13 }
        v60 = __frsqrte(_FP2);
        v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                            * (float)((float)((float)((float)v56 * (float)v56) + (float)v55) * (float)0.5))
                                                                                    * (float)v60)
                                                                            - (float)1.5)
                                                            * (float)v60)
                                                    * (float)((float)((float)((float)v56 * (float)v56) + (float)v55)
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v60
                                                                                    * (float)((float)((float)((float)v56 * (float)v56) + (float)v55)
                                                                                            * (float)0.5))
                                                                            * (float)v60)
                                                                    - (float)1.5)
                                                    * (float)v60))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v60
                                                            * (float)((float)((float)((float)v56 * (float)v56)
                                                                            + (float)v55)
                                                                    * (float)0.5))
                                                    * (float)v60)
                                            - (float)1.5)
                            * (float)v60));
        origin->x = (float)((float)v54 * (float)v61) * (float)v19;
        origin->y = (float)((float)v56 * (float)v61) * (float)v23;
        break;
      default:
        if ( type != 0 )
        {
          DWORD1(v67) = &v275;
          v68 = 1664525 * v14->seed + 1013904223;
          DWORD2(v67) = (v68 >> 10) & 0x7FFF;
          v14->seed = v68;
          *(_QWORD *)&v276.x = *(_QWORD *)((char *)&v67 + 4);
          HIDWORD(v69) = 1664525 * v68 + 1013904223;
          v14->seed = (unsigned int)HIDWORD(v69);
          LODWORD(v69) = (HIDWORD(v69) >> 10) & 0x7FFF;
          v70 = 1664525 * HIDWORD(v69) + 1013904223;
          v71 = (double)*(__int64 *)&v276.x;
          LODWORD(v67) = (v70 >> 10) & 0x7FFF;
          v14->seed = v70;
          *(_QWORD *)&v276.x = v67;
          v275.y = (float)((float)v69 * (float)0.000061037019) - (float)1.0;
          v275.x = (float)((float)v71 * (float)0.000061037019) - (float)1.0;
          v275.z = (float)((float)(__int64)v67 * (float)0.000061037019) - (float)1.0;
          idVec3::NormalizeFast(this: &v275);
          v72 = (float)(v275.y * (float)v23);
          v73 = (float)(v275.z * (float)v32);
          origin->x = v275.x * (float)v19;
          origin->y = v72;
          origin->z = v73;
        }
        else
        {
          if ( stage->distribution.random )
          {
            v34 = 1664525 * v14->seed + 1013904223;
            v14->seed = v34;
            HIDWORD(v35) = (v34 >> 10) & 0x7FFF;
            v31 = 1664525 * v34;
            v36 = 1664525 * v34 + 1013904223;
            *(_DWORD *)&v28[8] = (v36 >> 10) & 0x7FFF;
            v14->seed = v36;
            *(_DWORD *)&v28[4] = v36;
            *(_DWORD *)v28 = 1664525 * v36;
            v276.z = (float)((float)*(__int64 *)(&v26 - 1) * (float)0.000061037019) - (float)1.0;
            v37 = 1664525 * v36 + 1013904223;
            LODWORD(v35) = (v37 >> 10) & 0x7FFF;
            v14->seed = v37;
            v276.x = (float)((float)v35 * (float)0.000061037019) - (float)1.0;
            v276.y = (float)((float)*(__int64 *)&v28[4] * (float)0.000061037019) - (float)1.0;
          }
          else
          {
            v276.x = 1.0;
            v276.y = 1.0;
            v276.z = 1.0;
          }
          *(float *)&v28[4] = v276.y;
          v38 = v276.x;
          origin->z = (float)v32 * v276.z;
          origin->y = (float)v23 * *(float *)&v28[4];
          origin->x = (float)v19 * (float)v38;
        }
        break;
    }
  }
  v74 = stage->customPath.type;
  if ( v74 != PPATH_STANDARD )
  {
    v75 = v74 - 1;
    if ( v75 <= 3 )
    {
      switch ( v75 )
      {
        case 1u:
          v99 = idParticleParm::Compute(
                  this: stage->customPath.parms,
                  tables,
                  frac: *(float *)&g[5].seed,
                  rand: (idRandom2 *)v31,
                  a5: g + 6,
                  a6: *(__int64 *)v28);
          v104 = idParticleParm::Compute(
                   this: &stage->customPath.parms[1],
                   tables,
                   frac: *(float *)&g[5].seed,
                   rand: v101,
                   a5: g + 6,
                   a6: v100);
          HIDWORD(v105) = 1664525 * v14->seed + 1013904223;
          LODWORD(v103) = (HIDWORD(v105) >> 10) & 0x7FFF;
          v14->seed = (unsigned int)HIDWORD(v105);
          *(_QWORD *)&v276.x = v103;
          v106 = 0.40000001;
          v107 = (float)((float)v103 * (float)0.000030518509);
          if ( v107 >= 0.40000001 )
          {
            if ( v107 <= 1.0 )
              v108 = (float)((float)v103 * (float)0.000030518509);
            else
              v108 = 1.0;
          }
          else
          {
            v108 = 0.40000001;
          }
          v109 = 1664525 * v14->seed + 1013904223;
          LODWORD(v102) = (v109 >> 10) & 0x7FFF;
          v14->seed = v109;
          *(_QWORD *)&v276.x = v102;
          v110 = (float)((float)v102 * (float)0.000030518509);
          if ( v110 >= 0.40000001 )
          {
            if ( v110 <= 1.0 )
              v106 = (float)((float)v102 * (float)0.000030518509);
            else
              v106 = 1.0;
          }
          HIDWORD(v111) = &v273;
          v112 = 1664525 * v14->seed;
          v14->seed = v112 + 1013904223;
          LODWORD(v111) = ((unsigned int)(v112 + 1013904223) >> 10) & 0x7FFF;
          v113 = (float *)(1664525 * (v112 + 1013904223));
          v114 = (float)(*(float *)&g[1].seed * (float)v108);
          *(_QWORD *)&v276.x = v111;
          v115 = idMath::TWO_PI;
          LODWORD(v105) = (((unsigned int)v113 + 1013904223) >> 10) & 0x7FFF;
          v14->seed = (unsigned int)v113 + 1013904223;
          v116 = (float)((float)(*(float *)&g[1].seed * (float)v106) * (float)v104);
          *(_QWORD *)&v275.x = v105;
          v117 = (float)((float)((float)((float)*(__int64 *)&v276.x * (float)v115) * (float)0.000030518509)
                       + (float)((float)v114 * (float)v99));
          v118 = (float)((float)((float)((float)v105 * idMath::TWO_PI) * (float)0.000030518509) + (float)v116);
          idMath::SinCos16(a: v117, s: v113, c: &v275.x, a4: &v273);
          idMath::SinCos16(a: v118, s: v119, c: &v276.x, a4: &v274);
          v122 = idParticleParm::Compute(
                   this: &stage->customPath.parms[2],
                   tables,
                   frac: *(float *)&g[5].seed,
                   rand: v121,
                   a5: g + 6,
                   a6: v120);
          v124 = origin->z;
          v125 = (float)((float)(v274 * v275.x) * (float)((float)v122 * (float)x));
          v126 = (float)((float)-v276.x * (float)((float)v122 * (float)x));
          v127 = (float)((float)((float)(v274 * v273) * (float)((float)v122 * (float)x)) + origin->x);
          v123 = origin->y;
          origin->x = v127;
          origin->y = (float)v125 + (float)v123;
          v128 = (float)((float)v126 + (float)v124);
          break;
        case 2u:
          v129 = idParticleParm::Compute(
                   this: &stage->customPath.parms[1],
                   tables,
                   frac: *(float *)&g[5].seed,
                   rand: (idRandom2 *)v31,
                   a5: g + 6,
                   a6: *(__int64 *)v28);
          v130 = 1664525 * v14->seed;
          HIDWORD(v131) = &v276;
          LODWORD(v131) = ((unsigned int)(v130 + 1013904223) >> 10) & 0x7FFF;
          v14->seed = v130 + 1013904223;
          *(_QWORD *)&v276.x = v131;
          idMath::SinCos16(
            a: (float)((float)((float)((float)v131 * idMath::TWO_PI) * (float)0.000030518509)
                  + (float)(*(float *)&g[1].seed * (float)v129)),
            s: v132,
            c: &v275.x,
            a4: &v276.x);
          v135 = idParticleParm::Compute(
                   this: stage->customPath.parms,
                   tables,
                   frac: *(float *)&g[5].seed,
                   rand: v134,
                   a5: g + 6,
                   a6: v133);
          v277.z = 0.0;
          v277.x = (float)v135 * v276.x;
          v277.y = (float)v135 * v275.x;
          idVec3::ProjectSelfOntoSphere(this: &v277, radius: v135);
          v136 = (float)(v277.y + origin->y);
          v137 = (float)(v277.z + origin->z);
          origin->x = v277.x + origin->x;
          origin->y = v136;
          origin->z = v137;
          goto LABEL_56;
        case 0u:
          v76 = idParticleParm::Compute(
                  this: &stage->customPath.parms[4],
                  tables,
                  frac: *(float *)&g[5].seed,
                  rand: (idRandom2 *)v31,
                  a5: g + 6,
                  a6: *(__int64 *)v28);
          v79 = idParticleParm::Compute(
                  this: &stage->customPath.parms[3],
                  tables,
                  frac: *(float *)&g[5].seed,
                  rand: v78,
                  a5: g + 6,
                  a6: v77);
          v80 = 1664525 * v14->seed;
          LODWORD(v81) = ((unsigned int)(v80 + 1013904223) >> 10) & 0x7FFF;
          v14->seed = v80 + 1013904223;
          v82 = (float)((float)((float)((float)v81 * idMath::TWO_PI) * (float)0.000030518509)
                      + (float)(*(float *)&g[1].seed * (float)v79));
          *(_QWORD *)&v276.x = v81;
          idMath::SinCos16(a: v82, s: v83, c: &v274, a4: &v273);
          v86 = (float)(idParticleParm::Compute(
                          this: stage->customPath.parms,
                          tables,
                          frac: *(float *)&g[5].seed,
                          rand: v85,
                          a5: g + 6,
                          a6: v84)
                      * (float)x);
          v89 = (float)(idParticleParm::Compute(
                          this: &stage->customPath.parms[1],
                          tables,
                          frac: *(float *)&g[5].seed,
                          rand: v88,
                          a5: g + 6,
                          a6: v87)
                      * (float)v22);
          v92 = idParticleParm::Compute(
                  this: &stage->customPath.parms[2],
                  tables,
                  frac: *(float *)&g[5].seed,
                  rand: v91,
                  a5: g + 6,
                  a6: v90);
          v31 = 1664525 * v14->seed;
          v93 = (float)((float)v86 * v273);
          v94 = (float)((float)v89 * v274);
          LODWORD(v95) = ((v31 + 1013904223) >> 10) & 0x7FFF;
          v14->seed = v31 + 1013904223;
          v96 = *(float *)&g[1].seed;
          *(_QWORD *)&v276.x = v95;
          v97 = origin->y;
          v98 = origin->z;
          origin->x = (float)v93 + origin->x;
          origin->y = (float)v94 + (float)v97;
          origin->z = (float)((float)((float)((float)v95 * (float)((float)v92 * (float)v30)) * (float)0.000030518509)
                            + (float)((float)v96 * (float)v76))
                    + (float)v98;
          goto LABEL_56;
        default:
          v138 = (float)(*(float *)&g[1].seed
                       * idParticleParm::Compute(
                           this: stage->customPath.parms,
                           tables,
                           frac: *(float *)&g[5].seed,
                           rand: (idRandom2 *)v31,
                           a5: g + 6,
                           a6: *(__int64 *)v28));
          v139 = origin->z;
          v140 = origin->y;
          origin->x = origin->x;
          origin->y = v140;
          v128 = (float)((float)-v138 + (float)v139);
          break;
      }
      origin->z = v128;
    }
  }
LABEL_56:
  *(_DWORD *)&v28[8] = inputs->totalParticles;
  *(idRandom2 *)&v28[4] = (idRandom2)g->seed;
  *(_QWORD *)&v276.x = *(_QWORD *)&v28[4];
  *(_QWORD *)&v275.x = *(_QWORD *)v28;
  _FP8 = (float)((float)*(__int64 *)&v28[4] - (float)1.0);
  __asm { fsel      f7, f8, f10, f31 }
  v143 = (float)((float)*(__int64 *)v28 / (float)_FP7);
  v144 = idParticleParm::Compute(
           this: stage->spawnLocation.spawnLocation,
           tables,
           frac: v143,
           rand: (idRandom2 *)v31,
           a5: g + 6,
           a6: *(__int64 *)v28);
  v147 = idParticleParm::Compute(
           this: &stage->spawnLocation.spawnLocation[1],
           tables,
           frac: v143,
           rand: v146,
           a5: g + 6,
           a6: v145);
  v150 = idParticleParm::Compute(
           this: &stage->spawnLocation.spawnLocation[2],
           tables,
           frac: v143,
           rand: v149,
           a5: g + 6,
           a6: v148);
  v151 = (float)(origin->y + (float)v147);
  v152 = (float)((float)v150 + origin->z);
  origin->x = (float)v144 + origin->x;
  origin->y = v151;
  origin->z = v152;
  v155 = idParticleParm::Compute(
           this: stage->offset.offset,
           tables,
           frac: *(float *)&g[5].seed,
           rand: v154,
           a5: g + 6,
           a6: v153);
  v158 = idParticleParm::Compute(
           this: &stage->offset.offset[1],
           tables,
           frac: *(float *)&g[5].seed,
           rand: v157,
           a5: g + 6,
           a6: v156);
  v161 = idParticleParm::Compute(
           this: &stage->offset.offset[2],
           tables,
           frac: *(float *)&g[5].seed,
           rand: v160,
           a5: g + 6,
           a6: v159);
  v162 = (float)(origin->y + (float)v158);
  v163 = (float)((float)v161 + origin->z);
  origin->x = (float)v155 + origin->x;
  origin->y = v162;
  origin->z = v163;
  v168 = idParticleParm::Compute(
           this: stage->friction.friction,
           tables,
           frac: *(float *)&g[5].seed,
           rand: v165,
           a5: g + 6,
           a6: v164);
  if ( v168 >= 0.0 )
  {
    if ( v168 <= 1.0 )
      v169 = v168;
    else
      v169 = 1.0;
  }
  else
  {
    v169 = 0.0;
  }
  v172 = idParticleParm::Compute(
           this: &stage->friction.friction[1],
           tables,
           frac: *(float *)&g[5].seed,
           rand: v167,
           a5: g + 6,
           a6: v166);
  if ( v172 >= 0.0 )
  {
    if ( v172 <= 1.0 )
      v173 = v172;
    else
      v173 = 1.0;
  }
  else
  {
    v173 = 0.0;
  }
  v176 = idParticleParm::Compute(
           this: &stage->friction.friction[2],
           tables,
           frac: *(float *)&g[5].seed,
           rand: v171,
           a5: g + 6,
           a6: v170);
  if ( v176 >= 0.0 )
  {
    if ( v176 <= 1.0 )
      v177 = v176;
    else
      v177 = 1.0;
  }
  else
  {
    v177 = 0.0;
  }
  v178 = idParticleParm::Compute(
           this: stage->speed.speed,
           tables,
           frac: (float)-(float)((float)((float)((float)(*(float *)&g[4].seed * *(float *)&g[5].seed) * (float)v169)
                                 * (float)0.5)
                         - *(float *)&g[4].seed),
           rand: v175,
           a5: g + 6,
           a6: v174);
  v181 = idParticleParm::Compute(
           this: &stage->speed.speed[1],
           tables,
           frac: (float)-(float)((float)((float)((float)(*(float *)&g[4].seed * *(float *)&g[5].seed) * (float)v173)
                                 * (float)0.5)
                         - *(float *)&g[4].seed),
           rand: v180,
           a5: g + 6,
           a6: v179);
  v187 = idParticleParm::Compute(
           this: &stage->speed.speed[2],
           tables,
           frac: (float)-(float)((float)((float)((float)(*(float *)&g[4].seed * *(float *)&g[5].seed) * (float)v177)
                                 * (float)0.5)
                         - *(float *)&g[4].seed),
           rand: v183,
           a5: g + 6,
           a6: v182);
  v188 = stage->direction.type;
  v189 = v187;
  if ( v188 != 0 )
  {
    if ( v188 == 1 )
    {
      v263 = origin->y;
      v264 = origin->z;
      v276.x = origin->x;
      v276.y = v263;
      v276.z = v264;
      idVec3::NormalizeFast(this: &v276);
      v190 = (float)(stage->direction.parms[0] + v276.z);
    }
    else
    {
      if ( v188 < 3 )
      {
        v276.x = v178;
        v276.y = v181;
        v276.z = v187;
        idVec3::NormalizeFast(this: &v276);
        v178 = __fabs(v178);
        v181 = __fabs(v181);
        v189 = __fabs(v189);
      }
      v190 = v276.z;
    }
  }
  else
  {
    v265 = 1664525 * v14->seed + 1013904223;
    HIDWORD(v266) = &v275;
    v267 = (float *)((v265 >> 10) & 0x7FFF);
    v14->seed = v265;
    *(_QWORD *)&v276.x = *(_QWORD *)(&v186 - 1);
    v268 = idMath::M_DEG2RAD;
    v269 = stage->direction.parms[0];
    v270 = 1664525 * v265 + 1013904223;
    LODWORD(v266) = (v270 >> 10) & 0x7FFF;
    v14->seed = v270;
    *(_QWORD *)&v276.x = v266;
    v271 = (float)((float)((float)((float)v266 * (float)0.000061037019) - (float)1.0) * (float)3.1415927);
    idMath::SinCos16(
      a: (float)((float)((float)((float)((float)*(__int64 *)(&v186 - 1) * (float)0.000061037019) - (float)1.0) * (float)v269)
            * (float)v268),
      s: v267,
      c: &v276.x,
      a4: &v275.x);
    idMath::SinCos16(a: v271, s: v272, c: &v273, a4: &v274);
    v190 = v275.x;
    v276.y = v273 * v276.x;
    v276.x = v274 * v276.x;
  }
  v191 = stage->direction.type;
  v192 = (float)((float)v181 * v276.y);
  result->x = v276.x * (float)v178;
  v193 = (float)((float)v189 * (float)v190);
  result->y = v192;
  result->z = (float)v189 * (float)v190;
  if ( v191 == PDIR_CONE )
  {
    v194 = (float)((float)v189 * (float)v190);
    v195 = stage->direction.coneAxis.mat[2].y;
    v196 = stage->direction.coneAxis.mat[2].z;
    v197 = (float)((float)(stage->direction.coneAxis.mat[1].x * (float)v192)
                 + (float)(stage->direction.coneAxis.mat[2].x * (float)v193));
    v199 = (float)((float)(stage->direction.coneAxis.mat[0].z * result->x)
                 + (float)(stage->direction.coneAxis.mat[1].z * (float)v192));
    v198 = (float)((float)(stage->direction.coneAxis.mat[0].y * result->x)
                 + (float)(stage->direction.coneAxis.mat[1].y * (float)v192));
    result->x = (float)(result->x * stage->direction.coneAxis.mat[0].x) + (float)v197;
    result->y = (float)((float)v195 * (float)v194) + (float)v198;
    result->z = (float)((float)v196 * (float)v194) + (float)v199;
  }
  v200 = (float)(*(float *)&g[3].seed * result->y);
  v201 = (float)(*(float *)&g[3].seed * result->z);
  result->x = *(float *)&g[3].seed * result->x;
  result->y = v200;
  result->z = v201;
  v202 = idParticleParm::Compute(
           this: stage->acceleration.acceleration,
           tables,
           frac: *(float *)&g[5].seed,
           rand: v185,
           a5: g + 6,
           a6: v184);
  v205 = idParticleParm::Compute(
           this: &stage->acceleration.acceleration[1],
           tables,
           frac: *(float *)&g[5].seed,
           rand: v204,
           a5: g + 6,
           a6: v203);
  v210 = idParticleParm::Compute(
           this: &stage->acceleration.acceleration[2],
           tables,
           frac: *(float *)&g[5].seed,
           rand: v207,
           a5: g + 6,
           a6: v206);
  v211 = v287;
  v212 = v210;
  v213 = v286;
  v214 = v285;
  v215 = v284;
  v216 = v283;
  v217 = v282;
  v218 = v281;
  v219 = v280;
  v220 = v279;
  if ( stage->acceleration.world )
  {
    v221 = (float)((float)((float)v202 * v282) + (float)((float)v205 * v283));
    v222 = (float)((float)((float)v202 * v285) + (float)((float)v205 * v286));
    v202 = (float)((float)((float)v210 * v281) + (float)((float)(v279 * (float)v202) + (float)((float)v205 * v280)));
    v205 = (float)((float)((float)v210 * v284) + (float)v221);
    v212 = (float)((float)((float)v210 * v287) + (float)v222);
  }
  v223 = 0.0;
  v224 = 0.0;
  v227 = -idParticleParm::Compute(
            this: &stage->gravity.gravity,
            tables,
            frac: *(float *)&g[5].seed,
            rand: v209,
            a5: g + 6,
            a6: v208);
  if ( stage->gravity.world )
  {
    v223 = (float)((float)((float)((float)v220 + (float)v219) * (float)0.0) + (float)((float)v227 * (float)v218));
    v224 = (float)((float)((float)((float)v217 + (float)v216) * (float)0.0) + (float)((float)v227 * (float)v215));
    v227 = (float)((float)((float)((float)v214 + (float)v213) * (float)0.0) + (float)((float)v227 * (float)v211));
  }
  v228 = idParticleParm::Compute(
           this: &stage->systemProperties.windBias,
           tables,
           frac: *(float *)&g[5].seed,
           rand: v226,
           a5: g + 6,
           a6: v225);
  v229 = origin->x;
  v230 = origin->z;
  v231 = (float)(result->y
               + (float)(*(float *)&g[1].seed
                       * (float)((float)((float)v205 + (float)(*(float *)&g[1].seed * (float)v224))
                               + (float)(inputs->wind.y * (float)v228))));
  v232 = (float)(result->z
               + (float)(*(float *)&g[1].seed
                       * (float)((float)((float)v212 + (float)(*(float *)&g[1].seed * (float)v227))
                               + (float)(inputs->wind.z * (float)v228))));
  v233 = (float)((float)((float)((float)((float)(*(float *)&g[1].seed * (float)v223) + (float)v202)
                               + (float)(inputs->wind.x * (float)v228))
                       * *(float *)&g[1].seed)
               + result->x);
  v234 = (float)(origin->y
               + (float)(result->y
                       + (float)(*(float *)&g[1].seed
                               * (float)((float)((float)v205 + (float)(*(float *)&g[1].seed * (float)v224))
                                       + (float)(inputs->wind.y * (float)v228)))));
  origin->y = origin->y
            + (float)(result->y
                    + (float)(*(float *)&g[1].seed
                            * (float)((float)((float)v205 + (float)(*(float *)&g[1].seed * (float)v224))
                                    + (float)(inputs->wind.y * (float)v228))));
  origin->z = (float)v232 + (float)v230;
  origin->x = (float)v233 + (float)v229;
  v235 = inputs->stageAxis.mat[2].y;
  v236 = inputs->stageAxis.mat[0].z;
  v237 = (float)((float)((float)v234 * inputs->stageAxis.mat[1].y)
               + (float)(inputs->stageAxis.mat[0].y * (float)((float)v233 + (float)v229)));
  v238 = (float)((float)((float)v234 * inputs->stageAxis.mat[1].z)
               + (float)((float)((float)v232 + (float)v230) * inputs->stageAxis.mat[2].z));
  v239 = (float)((float)((float)v234 * inputs->stageAxis.mat[1].x)
               + (float)((float)((float)((float)v232 + (float)v230) * inputs->stageAxis.mat[2].x)
                       + (float)((float)((float)v233 + (float)v229) * inputs->stageAxis.mat[0].x)));
  origin->x = (float)((float)v234 * inputs->stageAxis.mat[1].x)
            + (float)((float)((float)((float)v232 + (float)v230) * inputs->stageAxis.mat[2].x)
                    + (float)((float)((float)v233 + (float)v229) * inputs->stageAxis.mat[0].x));
  origin->y = (float)((float)((float)v232 + (float)v230) * (float)v235) + (float)v237;
  origin->z = (float)((float)((float)v233 + (float)v229) * (float)v236) + (float)v238;
  v241 = (float)((float)(inputs->globalAxis.mat[2].z
                       * (float)((float)((float)((float)v233 + (float)v229) * (float)v236) + (float)v238))
               + (float)(inputs->globalAxis.mat[1].z
                       * (float)((float)((float)((float)v232 + (float)v230) * (float)v235) + (float)v237)));
  v240 = (float)((float)((float)v239 * inputs->globalAxis.mat[0].x)
               + (float)((float)(inputs->globalAxis.mat[2].x
                               * (float)((float)((float)((float)v233 + (float)v229) * (float)v236) + (float)v238))
                       + (float)(inputs->globalAxis.mat[1].x
                               * (float)((float)((float)((float)v232 + (float)v230) * (float)v235) + (float)v237))));
  v242 = (float)((float)((float)((float)v239 * inputs->globalAxis.mat[0].x)
                       + (float)((float)(inputs->globalAxis.mat[2].x
                                       * (float)((float)((float)((float)v233 + (float)v229) * (float)v236) + (float)v238))
                               + (float)(inputs->globalAxis.mat[1].x
                                       * (float)((float)((float)((float)v232 + (float)v230) * (float)v235) + (float)v237))))
               + inputs->globalOrigin.x);
  v243 = (float)(inputs->globalOrigin.y
               + (float)((float)(inputs->globalAxis.mat[0].y * (float)v239)
                       + (float)((float)(inputs->globalAxis.mat[2].y
                                       * (float)((float)((float)((float)v233 + (float)v229) * (float)v236) + (float)v238))
                               + (float)(inputs->globalAxis.mat[1].y
                                       * (float)((float)((float)((float)v232 + (float)v230) * (float)v235) + (float)v237)))));
  v244 = inputs->globalOrigin.z;
  v245 = (float)((float)(inputs->globalAxis.mat[0].z * (float)v239) + (float)v241);
  origin->x = (float)v240 + inputs->globalOrigin.x;
  origin->y = v243;
  v246 = (float)((float)v244 + (float)v245);
  origin->z = (float)v244 + (float)v245;
  if ( stage->orientation.depthOffset > 0.0 )
  {
    v247 = (float)(inputs->localViewOrg.z - (float)((float)v244 + (float)v245));
    v248 = (float)(inputs->localViewOrg.x - (float)v242);
    v249 = (float)(inputs->localViewOrg.y - (float)v243);
    _FP1 = (float)((float)((float)((float)v249 * (float)v249)
                         + (float)((float)((float)v248 * (float)v248) + (float)((float)v247 * (float)v247)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f1, f3, f7 }
    v252 = __frsqrte(_FP3);
    v253 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v252
                                                                                         * (float)((float)((float)((float)v249 * (float)v249) + (float)((float)((float)v248 * (float)v248) + (float)((float)v247 * (float)v247)))
                                                                                                 * (float)0.5))
                                                                                 * (float)v252)
                                                                         - (float)1.5)
                                                         * (float)v252)
                                                 * (float)((float)((float)((float)v249 * (float)v249)
                                                                 + (float)((float)((float)v248 * (float)v248)
                                                                         + (float)((float)v247 * (float)v247)))
                                                         * (float)0.5))
                                         * (float)((float)-(float)((float)((float)((float)v252
                                                                                 * (float)((float)((float)((float)v249 * (float)v249)
                                                                                                 + (float)((float)((float)v248 * (float)v248) + (float)((float)v247 * (float)v247)))
                                                                                         * (float)0.5))
                                                                         * (float)v252)
                                                                 - (float)1.5)
                                                 * (float)v252))
                                 - (float)1.5)
                 * (float)((float)-(float)((float)((float)((float)v252
                                                         * (float)((float)((float)((float)v249 * (float)v249)
                                                                         + (float)((float)((float)v248 * (float)v248)
                                                                                 + (float)((float)v247 * (float)v247)))
                                                                 * (float)0.5))
                                                 * (float)v252)
                                         - (float)1.5)
                         * (float)v252));
    v254 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v252 * (float)((float)((float)((float)v249 * (float)v249) + (float)((float)((float)v248 * (float)v248) + (float)((float)v247 * (float)v247))) * (float)0.5)) * (float)v252) - (float)1.5)
                                                                                                 * (float)v252)
                                                                                         * (float)((float)((float)((float)v249 * (float)v249) + (float)((float)((float)v248 * (float)v248) + (float)((float)v247 * (float)v247)))
                                                                                                 * (float)0.5))
                                                                                 * (float)((float)-(float)((float)((float)((float)v252 * (float)((float)((float)((float)v249 * (float)v249) + (float)((float)((float)v248 * (float)v248) + (float)((float)v247 * (float)v247))) * (float)0.5)) * (float)v252) - (float)1.5)
                                                                                         * (float)v252))
                                                                         - (float)1.5)
                                                         * (float)((float)-(float)((float)((float)((float)v252
                                                                                                 * (float)((float)((float)((float)v249 * (float)v249) + (float)((float)((float)v248 * (float)v248) + (float)((float)v247 * (float)v247))) * (float)0.5))
                                                                                         * (float)v252)
                                                                                 - (float)1.5)
                                                                 * (float)v252))
                                                 * (float)((float)((float)((float)v249 * (float)v249)
                                                                 + (float)((float)((float)v248 * (float)v248)
                                                                         + (float)((float)v247 * (float)v247)))
                                                         * (float)0.5))
                                         * (float)v253)
                                 - (float)1.5)
                 * (float)v253);
    v255 = (float)(stage->orientation.depthOffset * (float)((float)(inputs->localViewOrg.x - (float)v242) * (float)v254));
    v256 = (float)(stage->orientation.depthOffset * (float)((float)v254 * (float)(inputs->localViewOrg.y - (float)v243)));
    v257 = (float)(stage->orientation.depthOffset * (float)((float)v254 * (float)(inputs->localViewOrg.z - (float)v246)));
    origin->x = (float)v255 + (float)v242;
    origin->y = (float)v256 + (float)v243;
    origin->z = (float)v257 + (float)v246;
  }
  if ( !stage->orientation.orientToVelOnly )
  {
    result->x = v233;
    result->y = v231;
    result->z = v232;
  }
  v259 = inputs->localVelocity.y;
  v260 = inputs->localVelocity.z;
  v261 = (float)((float)(inputs->stageAxis.mat[2].y * result->z)
               + (float)((float)(result->y * inputs->stageAxis.mat[1].y)
                       + (float)(result->x * inputs->stageAxis.mat[0].y)));
  v262 = (float)((float)(result->z * inputs->stageAxis.mat[2].z)
               + (float)((float)(result->y * inputs->stageAxis.mat[1].z)
                       + (float)(result->x * inputs->stageAxis.mat[0].z)));
  result->x = (float)((float)(result->y * inputs->stageAxis.mat[1].x)
                    + (float)((float)(result->z * inputs->stageAxis.mat[2].x)
                            + (float)(result->x * inputs->stageAxis.mat[0].x)))
            + inputs->localVelocity.x;
  result->y = (float)v259 + (float)v261;
  result->z = (float)v260 + (float)v262;
  return result;
}


// ========================================================================
// ComputeTextureAnimation
// EA  : 0x827E6318
// RVA : 0x007E6318
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall ComputeTextureAnimation(
        const particleInput_t *inputs,
        particleGen_t *g,
        int width,
        float *s,
        float *height,
        float *t,
        unsigned __int8 *frameBlendFrac,
        bool *wrap,
        long double a9)
{
  int v9; // r2 OVERLAPPED
  const idParticleStage *stage; // r31
  idRandom2 *tables; // r4
  float *v13; // r25
  int numRows; // r11
  __int16 startFrame; // r10
  __int64 v21; // r8
  __int64 v22; // r29
  signed int v23; // r6
  unsigned int type; // r11
  __int64 v25; // r10 OVERLAPPED
  double frac; // fp0
  double totalAge; // fp0
  int v30; // r11
  int v31; // r11
  double v32; // fp31
  int v33; // r10
  int v34; // r30
  signed int numColumns; // r8
  unsigned int v36; // r6
  int v37; // r5
  double v38; // fp0
  __int64 v39; // r8
  int v40; // r29
  int v41; // r3
  double v42; // fp29
  long double v43; // fp2
  __int64 v44; // r11
  __int64 v45; // r9
  double v46; // fp7
  double v47; // fp30
  long double v48; // fp2
  int v49; // r11
  bool v50; // r11

  stage = inputs->stage;
  tables = (idRandom2 *)inputs->tables;
  v13 = (float *)width;
  numRows = 1;
  if ( !inputs->stage->texAnimation.useRandomRow )
    numRows = stage->texAnimation.numRows;
  startFrame = stage->texAnimation.startFrame;
  v21 = stage->texAnimation.numColumns | 0x3C6E000000000000LL;
  LODWORD(v22) = startFrame;
  HIDWORD(v22) = stage->texAnimation.numColumns * numRows;
  if ( startFrame < 0 )
  {
    if ( HIDWORD(v22) - 1 > 0 )
    {
      LODWORD(v21) = 1664525 * g->random.seed;
      HIDWORD(v21) = v21 + 1013904223;
      __twllei(HIDWORD(v22), 0);
      v23 = ((unsigned int)(v21 + 1013904223) >> 10) & 0x7FFF;
      g->random.seed = v21 + 1013904223;
      width = v23 / SHIDWORD(v22);
      LODWORD(v22) = v23 % SHIDWORD(v22);
      __twlgei(HIDWORD(v22) & ~(__ROL4__(v23, 1) - 1), 0xFFFFFFFF);
    }
    else
    {
      LODWORD(v22) = 0;
    }
  }
  type = stage->texAnimation.type;
  HIDWORD(v25) = 0x82000000;
  _FP0 = 0.0;
  if ( type != 0 )
  {
    if ( type == 1 )
    {
      *(double *)&a9 = idParticleParm::Compute(
                         this: &stage->texAnimation.rate,
                         tables,
                         frac: g->parmVal,
                         rand: (idRandom2 *)width,
                         a5: &g->random,
                         a6: v21);
      if ( stage->texAnimation.rate.calcType == PARTICLE_CALC_GENERIC )
        frac = g->frac;
      else
        frac = 1.0;
      LODWORD(v25) = HIDWORD(v22);
      _FP5 = (float)((float)((float)((float)frac * (float)*(double *)&a9) + (float)v22)
                   - (float)((float)v25 - (float)1.0));
      __asm { fsel      f0, f5, f7, f6 }
    }
    else if ( type < 3 )
    {
      LODWORD(v25) = HIDWORD(v22);
      _FP0 = (float)((float)(g->frac * (float)v25) + (float)v22);
    }
  }
  else
  {
    *(double *)&a9 = idParticleParm::Compute(
                       this: &stage->texAnimation.rate,
                       tables,
                       frac: g->parmVal,
                       rand: (idRandom2 *)width,
                       a5: &g->random,
                       a6: v21);
    if ( stage->texAnimation.rate.calcType == PARTICLE_CALC_GENERIC )
      totalAge = g->totalAge;
    else
      totalAge = 1.0;
    v30 = v22;
    _FP0 = (float)((float)((float)totalAge * (float)*(double *)&a9) + (float)*(__int64 *)((char *)&v25 - 4));
  }
  LODWORD(v25) = (int)_FP0;
  v32 = (float)((float)_FP0 - (float)v25);
  v31 = (int)_FP0;
  if ( stage->texAnimation.useRandomRow )
  {
    v33 = stage->texAnimation.numRows - 1;
    if ( v33 <= 0 )
    {
      v34 = 0;
      goto LABEL_25;
    }
    numColumns = stage->texAnimation.numRows;
    v36 = 1664525 * g->random.seed + 1013904223;
    v37 = (v36 >> 10) & 0x7FFF;
    g->random.seed = v36;
    v34 = v37 % (v33 + 1);
    __twlgei((v33 + 1) & ~(__ROL4__(v37, 1) - 1), 0xFFFFFFFF);
  }
  else
  {
    numColumns = stage->texAnimation.numColumns;
    __twllei(HIDWORD(v22), 0);
    __twlgei(HIDWORD(v22) & ~(__ROL4__(v31, 1) - 1), 0xFFFFFFFF);
    v34 = v31 % SHIDWORD(v22) / numColumns;
    __twlgei(numColumns & ~(__ROL4__(v31 % SHIDWORD(v22), 1) - 1), 0xFFFFFFFF);
  }
  __twllei(numColumns, 0);
LABEL_25:
  v38 = *v13;
  LODWORD(v39) = stage->texAnimation.numColumns;
  HIDWORD(v39) = v31 / (int)v39;
  v40 = v31 % (int)v39;
  v41 = v31 % (int)v39;
  __twllei(v39, 0);
  __twlgei(v39 & ~(__ROL4__(v31, 1) - 1), 0xFFFFFFFF);
  *v13 = (float)((float)1.0 / (float)v39) * (float)v38;
  v42 = (float)((float)*(__int64 *)(&v9 - 1) * (float)((float)((float)1.0 / (float)v39) * (float)v38));
  *(double *)&a9 = v42;
  v43 = floor(x: a9);
  LODWORD(v44) = v34;
  *((double *)&v43 + 1) = (float)((float)v42 - (float)*(double *)&v43);
  *s = *s + (float)((float)v42 - (float)*(double *)&v43);
  LODWORD(v45) = stage->texAnimation.numRows;
  v46 = (float)((float)((float)1.0 / (float)v45) * *height);
  *height = (float)((float)1.0 / (float)v45) * *height;
  v47 = (float)((float)v44 * (float)v46);
  *(double *)&v43 = v47;
  v48 = floor(x: v43);
  *t = *t + (float)((float)v47 - (float)*(double *)&v48);
  if ( stage->texAnimation.useFrameBlending )
  {
    v49 = (int)(float)((float)v32 * (float)255.0);
    if ( v49 >= 0 )
    {
      if ( v49 > 255 )
        LOBYTE(v49) = -1;
    }
    else
    {
      LOBYTE(v49) = 0;
    }
    *frameBlendFrac = v49;
    if ( stage->texAnimation.numRows <= 1u
      || stage->texAnimation.useRandomRow
      || (v50 = true, v40 != stage->texAnimation.numColumns - 1) )
    {
      v50 = false;
    }
    *wrap = v50;
  }
}


// ========================================================================
// ParticleTexCoords
// EA  : 0x827E6700
// RVA : 0x007E6700
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

void __fastcall ParticleTexCoords(
        const particleInput_t *inputs,
        particleGen_t *g,
        const idVec2 *sMinMax,
        const idVec2 *tMinMax,
        unsigned int atlasWidth,
        unsigned int atlasHeight,
        idTransparencyVert *verts,
        long double a8)
{
  const idParticleStage *stage; // r30
  unsigned __int8 v9; // r22
  double x; // fp27
  double v11; // fp26
  double y; // fp31
  double v15; // fp29
  unsigned int numColumns; // r10
  prtTextureFlipMode_t textureFlipS; // r11
  int v22; // r10
  bool v23; // r27
  prtTextureFlipMode_t textureFlipT; // r11
  bool v25; // r28
  double v26; // fp30
  long double v27; // fp2
  BOOL v28; // r29
  double v29; // fp25
  double v30; // fp31
  double v31; // fp13
  double v32; // fp0
  __int64 v33; // r10
  double v34; // fp11
  double v35; // fp10
  double z; // fp9
  double w; // fp8
  int v38; // r11
  int v39; // ctr
  double v40; // fp13
  double v41; // fp12
  double v42; // fp6
  double v43; // fp7
  double v44; // fp0
  double v45; // fp0
  double v46; // fp0
  double v47; // fp0
  double v48; // fp13
  double v49; // fp0
  double v50; // fp13
  double v51; // fp0
  double v52; // fp13
  double v53; // fp0
  int v54; // r28
  unsigned int v55; // r30
  int i; // r29
  long double v57; // fp2
  __int16 v58; // r11
  double v59; // fp13
  long double v60; // fp2
  __int16 v61; // r11
  double v62; // fp13
  long double v63; // fp2
  __int16 v64; // r11
  double v65; // fp13
  __int16 v66; // r11
  double v67; // fp0
  char v68; // r11
  double v69; // fp0
  unsigned __int8 v70; // r11
  __int16 v71; // r11
  __int16 v72; // r10
  __int16 v73; // r9
  __int16 v74; // r8
  bool v75; // r7
  unsigned __int8 v76; // r6
  __int16 v77; // r5
  __int16 v78; // r4
  bool v79; // r3
  __int16 v80; // r30
  __int16 v81; // r29
  unsigned __int8 v82; // r28
  unsigned __int8 v83[2]; // [sp+50h] [-E0h] BYREF
  bool v84[2]; // [sp+52h] [-DEh] BYREF
  float v85; // [sp+54h] [-DCh] BYREF
  float v86; // [sp+58h] [-D8h] BYREF
  float v87; // [sp+5Ch] [-D4h] BYREF
  float v88[2]; // [sp+60h] [-D0h] BYREF
  float v89; // [sp+68h] [-C8h] BYREF
  float v90; // [sp+6Ch] [-C4h]
  float v91; // [sp+70h] [-C0h] BYREF
  float v92; // [sp+74h] [-BCh]
  float v93; // [sp+78h] [-B8h] BYREF
  float v94; // [sp+7Ch] [-B4h]
  float v95; // [sp+80h] [-B0h] BYREF
  float v96; // [sp+84h] [-ACh]
  float v97[2]; // [sp+88h] [-A8h] BYREF
  __int64 v98; // [sp+90h] [-A0h] BYREF
  int v100; // [sp+9Ch] [-94h]

  stage = inputs->stage;
  v9 = 0;
  x = sMinMax->x;
  v11 = tMinMax->x;
  y = sMinMax->y;
  v15 = tMinMax->y;
  numColumns = inputs->stage->texAnimation.numColumns;
  v85 = sMinMax->x;
  v86 = v11;
  v87 = y;
  v88[0] = v15;
  v84[0] = false;
  v83[0] = 0;
  if ( numColumns > 1 || stage->texAnimation.numRows > 1u )
  {
    ComputeTextureAnimation(
      inputs,
      g,
      width: (int)&v87,
      s: &v85,
      height: v88,
      t: &v86,
      frameBlendFrac: v83,
      wrap: v84,
      a9: a8);
    x = v85;
    v9 = v83[0];
    v11 = v86;
    y = v87;
    v15 = v88[0];
  }
  textureFlipS = stage->systemProperties.textureFlipS;
  v22 = g->index & 1;
  v23 = textureFlipS == PTEXTURE_FLIP_ALWAYS || textureFlipS == PTEXTURE_FLIP_RANDOM && v22 != 0;
  textureFlipT = stage->systemProperties.textureFlipT;
  v25 = textureFlipT == PTEXTURE_FLIP_ALWAYS || textureFlipT == PTEXTURE_FLIP_RANDOM && v22 != 0;
  v26 = (float)((float)y + (float)x);
  *(double *)&a8 = v26;
  v27 = floor(x: a8);
  v28 = v84[0];
  v29 = (float)((float)((float)y + (float)x) - (float)*(double *)&v27);
  v30 = (float)((float)((float)((float)y + (float)x) - (float)*(double *)&v27) + (float)y);
  if ( v84[0] )
  {
    *(double *)&v27 = (float)((float)v15 + (float)v11);
    v27 = floor(x: v27);
    v31 = (float)((float)((float)v15 + (float)v11) - (float)*(double *)&v27);
  }
  else
  {
    v31 = v11;
  }
  if ( v28 )
    v32 = (float)((float)v31 + (float)v15);
  else
    v32 = (float)((float)v15 + (float)v11);
  if ( v23 )
    v89 = v26;
  else
    v89 = x;
  if ( v23 )
    v90 = x;
  else
    v90 = v26;
  if ( v25 )
    v91 = (float)v15 + (float)v11;
  else
    v91 = v11;
  if ( v25 )
    v92 = v11;
  else
    v92 = (float)v15 + (float)v11;
  if ( v23 )
    v93 = v30;
  else
    v93 = v29;
  if ( v23 )
    v94 = v29;
  else
    v94 = v30;
  if ( v25 )
    v95 = v32;
  else
    v95 = v31;
  if ( v25 )
    v96 = v31;
  else
    v96 = v32;
  HIDWORD(v33) = 0x82000000;
  if ( (*((_BYTE *)stage + 68) & 0x20) != 0 )
  {
    LODWORD(v33) = atlasWidth;
    v34 = stage->atlasScaleBias.x;
    v35 = stage->atlasScaleBias.y;
    v98 = v33;
    z = stage->atlasScaleBias.z;
    w = stage->atlasScaleBias.w;
    v38 = 0;
    v39 = 2;
    v40 = (float)((float)0.5 / (float)((float)__SPAIR64__(atlasWidth, atlasHeight) * (float)v35));
    v41 = (float)((float)0.5 / (float)((float)v33 * (float)v34));
    v42 = (float)((float)1.0 - (float)((float)0.5 / (float)((float)__SPAIR64__(atlasWidth, atlasHeight) * (float)v35)));
    v43 = (float)((float)1.0 - (float)((float)0.5 / (float)((float)v33 * (float)v34)));
    do
    {
      v44 = *(float *)((char *)&v89 + v38);
      if ( v44 >= v41 )
      {
        if ( v44 > v43 )
          v44 = (float)((float)1.0 - (float)((float)0.5 / (float)((float)v33 * (float)v34)));
      }
      else
      {
        v44 = (float)((float)0.5 / (float)((float)v33 * (float)v34));
      }
      *(float *)((char *)&v89 + v38) = (float)((float)v34 * (float)v44) + (float)z;
      v45 = *(float *)((char *)&v91 + v38);
      if ( v45 >= v40 )
      {
        if ( v45 > v42 )
          v45 = (float)((float)1.0
                      - (float)((float)0.5 / (float)((float)__SPAIR64__(atlasWidth, atlasHeight) * (float)v35)));
      }
      else
      {
        v45 = (float)((float)0.5 / (float)((float)__SPAIR64__(atlasWidth, atlasHeight) * (float)v35));
      }
      *(float *)((char *)&v91 + v38) = (float)((float)v35 * (float)v45) + (float)w;
      v46 = *(float *)((char *)&v93 + v38);
      if ( v46 >= v41 )
      {
        if ( v46 > v43 )
          v46 = (float)((float)1.0 - (float)((float)0.5 / (float)((float)v33 * (float)v34)));
      }
      else
      {
        v46 = (float)((float)0.5 / (float)((float)v33 * (float)v34));
      }
      *(float *)((char *)&v93 + v38) = (float)((float)v34 * (float)v46) + (float)z;
      v47 = *(float *)((char *)&v95 + v38);
      if ( v47 >= v40 )
      {
        if ( v47 > v42 )
          v47 = (float)((float)1.0
                      - (float)((float)0.5 / (float)((float)__SPAIR64__(atlasWidth, atlasHeight) * (float)v35)));
      }
      else
      {
        v47 = (float)((float)0.5 / (float)((float)__SPAIR64__(atlasWidth, atlasHeight) * (float)v35));
      }
      *(float *)((char *)&v95 + v38) = (float)((float)v35 * (float)v47) + (float)w;
      v38 += 4;
      --v39;
    }
    while ( v39 != 0 );
  }
  v48 = sMinMax->x;
  if ( v48 >= 0.0 )
  {
    if ( v48 > 1.0 )
      v48 = 1.0;
  }
  else
  {
    v48 = 0.0;
  }
  v49 = sMinMax->y;
  v97[0] = v48;
  if ( v49 >= 0.0 )
  {
    if ( v49 <= 1.0 )
      v50 = v49;
    else
      v50 = 1.0;
  }
  else
  {
    v50 = 0.0;
  }
  v51 = tMinMax->x;
  v97[1] = v50;
  if ( v51 >= 0.0 )
  {
    if ( v51 <= 1.0 )
      v52 = v51;
    else
      v52 = 1.0;
  }
  else
  {
    v52 = 0.0;
  }
  v53 = tMinMax->y;
  *(float *)&v98 = v52;
  if ( v53 >= 0.0 )
  {
    if ( v53 > 1.0 )
      v53 = 1.0;
  }
  else
  {
    v53 = 0.0;
  }
  *((float *)&v98 + 1) = v53;
  v54 = 0;
  v55 = 0;
  for ( i = 0; i < 4; i += 2 )
  {
    *(double *)&v27 = (float)((float)((float)(*(float *)((char *)&v89 + v55) - (float)0.5) * (float)65534.0) + (float)0.5);
    v57 = floor(x: v27);
    v100 = (int)(float)*(double *)&v57;
    v58 = v100;
    if ( v100 >= -32768 )
    {
      if ( v100 > 0x7FFF )
        v58 = 0x7FFF;
    }
    else
    {
      v58 = 0x8000;
    }
    v59 = (float)(*(float *)((char *)&v91 + v55) - (float)0.5);
    *(_WORD *)((char *)v88 + i) = v58;
    *(double *)&v57 = (float)((float)((float)v59 * (float)65534.0) + (float)0.5);
    v60 = floor(x: v57);
    v100 = (int)(float)*(double *)&v60;
    v61 = v100;
    if ( v100 >= -32768 )
    {
      if ( v100 > 0x7FFF )
        v61 = 0x7FFF;
    }
    else
    {
      v61 = 0x8000;
    }
    v62 = (float)(*(float *)((char *)&v93 + v55) - (float)0.5);
    *(_WORD *)((char *)&v86 + i) = v61;
    *(double *)&v60 = (float)((float)((float)v62 * (float)65534.0) + (float)0.5);
    v63 = floor(x: v60);
    v100 = (int)(float)*(double *)&v63;
    v64 = v100;
    if ( v100 >= -32768 )
    {
      if ( v100 > 0x7FFF )
        v64 = 0x7FFF;
    }
    else
    {
      v64 = 0x8000;
    }
    v65 = (float)(*(float *)((char *)&v95 + v55) - (float)0.5);
    *(_WORD *)((char *)&v88[-1] + i) = v64;
    *(double *)&v63 = (float)((float)((float)v65 * (float)65534.0) + (float)0.5);
    v27 = floor(x: v63);
    v100 = (int)(float)*(double *)&v27;
    v66 = v100;
    if ( v100 >= -32768 )
    {
      if ( v100 > 0x7FFF )
        v66 = 0x7FFF;
    }
    else
    {
      v66 = 0x8000;
    }
    v67 = v97[v55 / 4];
    *(_WORD *)((char *)&v85 + i) = v66;
    if ( v67 >= 0.0 )
    {
      if ( v67 > 1.0 )
        v67 = 1.0;
    }
    else
    {
      v67 = 0.0;
    }
    v100 = (int)(float)((float)v67 * (float)255.5);
    v68 = v100;
    if ( v100 >= 0 )
    {
      if ( v100 > 255 )
        v68 = -1;
    }
    else
    {
      v68 = 0;
    }
    v69 = *(float *)((char *)&v98 + v55);
    v84[v54] = v68;
    if ( v69 >= 0.0 )
    {
      if ( v69 > 1.0 )
        v69 = 1.0;
    }
    else
    {
      v69 = 0.0;
    }
    v100 = (int)(float)((float)v69 * (float)255.5);
    v70 = v100;
    if ( v100 >= 0 )
    {
      if ( v100 > 255 )
        v70 = -1;
    }
    else
    {
      v70 = 0;
    }
    v55 += 4;
    v83[v54++] = v70;
  }
  v71 = HIWORD(v88[0]);
  v72 = HIWORD(v86);
  v73 = HIWORD(v87);
  v74 = HIWORD(v85);
  v75 = v84[0];
  v76 = v83[0];
  v77 = LOWORD(v88[0]);
  v78 = LOWORD(v87);
  v79 = v84[1];
  v80 = LOWORD(v86);
  v81 = LOWORD(v85);
  v82 = v83[1];
  verts->st[0] = HIWORD(v88[0]);
  verts->st[1] = v72;
  verts->st1[0] = v73;
  verts->st1[1] = v74;
  verts->tangent[0] = v75;
  verts->tangent[1] = v76;
  verts->tangent[2] = v9;
  verts[1].st[0] = v77;
  verts[1].st[1] = v72;
  verts[1].st1[0] = v78;
  verts[1].st1[1] = v74;
  verts[1].tangent[0] = v79;
  verts[1].tangent[1] = v76;
  verts[1].tangent[2] = v9;
  verts[2].st[0] = v71;
  verts[2].st[1] = v80;
  verts[2].st1[0] = v73;
  verts[2].st1[1] = v81;
  verts[2].tangent[0] = v75;
  verts[2].tangent[1] = v82;
  verts[2].tangent[2] = v9;
  verts[3].st[0] = v77;
  verts[3].st[1] = v80;
  verts[3].st1[0] = v78;
  verts[3].st1[1] = v81;
  verts[3].tangent[0] = v79;
  verts[3].tangent[1] = v82;
  verts[3].tangent[2] = v9;
}


// ========================================================================
// GenerateTrailVerts
// EA  : 0x827E6DC8
// RVA : 0x007E6DC8
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

int __fastcall GenerateTrailVerts(
        const particleInput_t *inputs,
        idRandom2 *g,
        idRandom2 *outputs,
        const idVec3 *origin,
        __int64 a5)
{
  idRandom2 *tables; // r27
  idRandom2 *v6; // r23
  const idParticleStage *stage; // r28
  const particleRenderView_t *view; // r22
  idTransparencyVert *seed; // r18
  float *v13; // r17
  idVec4 *v14; // r24
  double v15; // fp15
  __int64 v16; // r8
  idRandom2 *v17; // r5
  double v18; // fp1
  float v19; // r9
  int numTrails; // r8
  float v21; // r7
  float v22; // r5
  __int64 v23; // r4
  float x; // r10
  float z; // r31
  unsigned int v26; // r6
  double v27; // fp10
  double v28; // fp12
  double v29; // fp14
  double v30; // fp11
  double v31; // fp18
  double segmentLength; // fp0
  double v33; // fp17
  float *p_seed; // r16
  float *v35; // r20
  int v36; // r14
  double v37; // fp16
  int v38; // r21
  double v39; // fp27
  __int64 v40; // r8
  double v41; // fp28
  double v42; // fp29
  __int64 v43; // r11
  float *p_z; // r31
  double v47; // fp0
  unsigned int v48; // r11
  double y; // fp21
  double v51; // fp20
  double v52; // fp19
  double v53; // fp25
  double v54; // fp24
  double v55; // fp23
  double v56; // fp8
  double v57; // fp7
  double v58; // fp6
  double v61; // fp4
  double v63; // fp13
  double v65; // fp3
  double v66; // fp12
  double v67; // fp4
  double v68; // fp3
  double v69; // fp4
  double v70; // fp3
  double v71; // fp13
  double v72; // fp10
  double v73; // fp12
  double v74; // fp11
  double v75; // fp5
  double v76; // fp9
  double v77; // fp8
  double v78; // fp7
  double v79; // fp1
  double v80; // fp6
  double v81; // fp3
  double v84; // fp2
  double v85; // fp0
  double v86; // fp2
  double v87; // fp5
  double v88; // fp4
  double v89; // fp3
  double v90; // fp0
  double v93; // fp12
  double v94; // fp11
  double v95; // fp10
  double v96; // fp6
  double v97; // fp2
  double v98; // fp0
  double v99; // fp12
  double v100; // fp11
  double v101; // fp13
  double v102; // fp12
  double v103; // fp0
  double v104; // fp29
  double v105; // fp28
  double v106; // fp27
  double v107; // fp5
  double v108; // fp2
  double v109; // fp4
  double v110; // fp3
  double v111; // fp1
  double v112; // fp11
  long double v113; // fp2
  double viewFade; // fp10
  double v115; // fp6
  double v117; // fp12
  double v119; // fp3
  double v120; // fp3
  double v121; // fp2
  double v122; // fp1
  int v128; // ctr
  double v132; // fp8
  double v133; // fp7
  double v134; // fp3
  double v135; // fp0
  double v136; // fp12
  int v138; // ctr
  int v141; // ctr
  unsigned int v143; // r11
  double v144; // fp0
  float *v146; // [sp+50h] [-1E0h]
  float v147; // [sp+60h] [-1D0h] BYREF
  float v148; // [sp+64h] [-1CCh]
  float v149; // [sp+68h] [-1C8h]
  float v150; // [sp+6Ch] [-1C4h]
  __int64 v151; // [sp+70h] [-1C0h]
  float v152; // [sp+78h] [-1B8h]
  __int64 v153; // [sp+80h] [-1B0h] BYREF
  float v154; // [sp+90h] [-1A0h]
  float v155; // [sp+94h] [-19Ch]
  float v156; // [sp+98h] [-198h]
  float v157; // [sp+9Ch] [-194h]
  float v158; // [sp+A0h] [-190h]
  float v159; // [sp+A4h] [-18Ch]
  float v160; // [sp+A8h] [-188h]
  float v161; // [sp+ACh] [-184h]
  float v162; // [sp+B0h] [-180h]
  unsigned int v163; // [sp+B4h] [-17Ch]
  unsigned int v164; // [sp+B8h] [-178h]
  float v165; // [sp+BCh] [-174h]
  float v166; // [sp+C0h] [-170h]
  float v167; // [sp+C4h] [-16Ch]
  float v168; // [sp+C8h] [-168h]
  float v169; // [sp+D0h] [-160h]
  float v170; // [sp+D4h] [-15Ch]
  float v171; // [sp+D8h] [-158h]
  idVec2 v172; // [sp+E0h] [-150h] BYREF
  idVec3 v173; // [sp+E8h] [-148h] BYREF
  idVec3 v174[13]; // [sp+F8h] [-138h] BYREF

  tables = (idRandom2 *)inputs->tables;
  v6 = g + 6;
  stage = inputs->stage;
  view = inputs->view;
  seed = (idTransparencyVert *)outputs->seed;
  v13 = (float *)outputs[1].seed;
  v14 = (idVec4 *)&g[8];
  v15 = (float)(idParticleParm::Compute(
                  this: inputs->stage->size.size,
                  tables,
                  frac: *(float *)&g[5].seed,
                  rand: outputs,
                  a5: g + 6,
                  a6: a5)
              * inputs->sizeScale);
  v18 = idParticleParm::Compute(
          this: &stage->size.aspectRatio,
          tables,
          frac: *(float *)&g[5].seed,
          rand: v17,
          a5: v6,
          a6: v16);
  v19 = *(float *)&g[8].seed;
  numTrails = stage->orientation.numTrails;
  v21 = *(float *)&g[9].seed;
  v22 = *(float *)&g[10].seed;
  LODWORD(v23) = numTrails;
  v153 = v23;
  LODWORD(v23) = LODWORD(origin->y);
  x = origin->x;
  HIDWORD(v23) = g[11];
  z = origin->z;
  v26 = g[6].seed;
  v27 = (float)((float)1.0 / *(float *)&g[3].seed);
  v28 = *(float *)&g[1].seed;
  v29 = 0.0;
  v30 = *(float *)&g[4].seed;
  v31 = 0.0;
  segmentLength = stage->orientation.segmentLength;
  v33 = 0.0;
  v164 = g[1].seed;
  v158 = v30;
  p_seed = (float *)&g[1].seed;
  v159 = v18;
  v163 = v26;
  v167 = v27;
  v35 = (float *)&g[4].seed;
  *(float *)&v151 = x;
  v36 = 0;
  LODWORD(v151) = v23;
  v37 = 0.0;
  v152 = z;
  v38 = 0;
  v154 = v19;
  v155 = v21;
  v156 = v22;
  v157 = *(float *)&v23;
  v165 = (float)1.0 / (float)((float)v153 + (float)1.0);
  if ( numTrails >= 0 )
  {
    LODWORD(v40) = 0x82000000;
    v39 = v152;
    HIDWORD(v40) = 0x82000000;
    v41 = *((float *)&v151 + 1);
    v42 = *(float *)&v151;
    HIDWORD(v43) = &si_vector_decode_cat_0[184];
    v146 = v13;
    p_z = &seed[1].xyz.z;
    _R26 = 1;
    _R27 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
    v166 = (float)((float)((float)1.0 / (float)((float)v153 + (float)1.0)) * (float)v18) * (float)segmentLength;
    v168 = 0.000001;
    do
    {
      LODWORD(v43) = v38;
      v151 = v43;
      v47 = (float)-(float)((float)((float)((float)v43 + (float)1.0) * v166) - (float)v28);
      *p_seed = -(float)((float)((float)((float)v43 + (float)1.0) * v166) - (float)v28);
      if ( v47 >= 0.0 )
      {
        v48 = g[7].seed;
        *v35 = (float)v47 * v167;
        v6->seed = v48;
        ParticleOrigin(result: v174, inputs, g, origin: &v173, a5: v40);
        memcpy(Dst: p_z - 10, Src: seed, Size: 0x80u);
        y = v173.y;
        v51 = v173.z;
        v52 = v173.x;
        v53 = (float)((float)((float)((float)v41 - v173.y) * (float)0.5) + v173.y);
        v54 = (float)((float)((float)((float)v39 - v173.z) * (float)0.5) + v173.z);
        v55 = (float)((float)((float)((float)v42 - v173.x) * (float)0.5) + v173.x);
        v56 = (float)((float)((float)((float)((float)v41 - v173.y) * (float)0.5) + v173.y) - inputs->localViewOrg.y);
        v57 = (float)((float)((float)((float)((float)v39 - v173.z) * (float)0.5) + v173.z) - inputs->localViewOrg.z);
        v58 = (float)((float)((float)((float)((float)v42 - v173.x) * (float)0.5) + v173.x) - inputs->localViewOrg.x);
        _FP3 = (float)((float)((float)((float)((float)v42 - v173.x) * (float)((float)v42 - v173.x))
                             + (float)((float)((float)((float)v39 - v173.z) * (float)((float)v39 - v173.z))
                                     + (float)((float)((float)v41 - v173.y) * (float)((float)v41 - v173.y))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f13, f3, f5, f0 }
        v61 = __frsqrte(_FP13);
        _FP3 = (float)((float)((float)((float)v58 * (float)v58)
                             + (float)((float)((float)v57 * (float)v57) + (float)((float)v56 * (float)v56)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v63 = (float)v61;
        __asm { fsel      f12, f3, f12, f0 }
        v65 = __frsqrte(_FP12);
        v66 = (float)-(float)((float)((float)((float)v61
                                            * (float)((float)((float)((float)((float)v42 - v173.x)
                                                                    * (float)((float)v42 - v173.x))
                                                            + (float)((float)((float)((float)v39 - v173.z)
                                                                            * (float)((float)v39 - v173.z))
                                                                    + (float)((float)((float)v41 - v173.y)
                                                                            * (float)((float)v41 - v173.y))))
                                                    * (float)0.5))
                                    * (float)v61)
                            - (float)1.5);
        v67 = (float)((float)-(float)((float)((float)((float)v65
                                                    * (float)((float)((float)((float)v58 * (float)v58)
                                                                    + (float)((float)((float)v57 * (float)v57)
                                                                            + (float)((float)v56 * (float)v56)))
                                                            * (float)0.5))
                                            * (float)v65)
                                    - (float)1.5)
                    * (float)v65);
        v68 = (float)((float)-(float)((float)((float)((float)((float)v66 * (float)v63)
                                                    * (float)((float)((float)((float)((float)v42 - v173.x)
                                                                            * (float)((float)v42 - v173.x))
                                                                    + (float)((float)((float)((float)v39 - v173.z)
                                                                                    * (float)((float)v39 - v173.z))
                                                                            + (float)((float)((float)v41 - v173.y)
                                                                                    * (float)((float)v41 - v173.y))))
                                                            * (float)0.5))
                                            * (float)((float)v66 * (float)v63))
                                    - (float)1.5)
                    * (float)((float)v66 * (float)v63));
        v69 = (float)((float)-(float)((float)((float)((float)v67
                                                    * (float)((float)((float)((float)v58 * (float)v58)
                                                                    + (float)((float)((float)v57 * (float)v57)
                                                                            + (float)((float)v56 * (float)v56)))
                                                            * (float)0.5))
                                            * (float)v67)
                                    - (float)1.5)
                    * (float)v67);
        v70 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v66 * (float)v63)
                                                                                            * (float)((float)((float)((float)((float)v42 - v173.x) * (float)((float)v42 - v173.x)) + (float)((float)((float)((float)v39 - v173.z) * (float)((float)v39 - v173.z)) + (float)((float)((float)v41 - v173.y) * (float)((float)v41 - v173.y)))) * (float)0.5))
                                                                                    * (float)((float)v66 * (float)v63))
                                                                            - (float)1.5)
                                                            * (float)((float)v66 * (float)v63))
                                                    * (float)((float)((float)((float)((float)v42 - v173.x)
                                                                            * (float)((float)v42 - v173.x))
                                                                    + (float)((float)((float)((float)v39 - v173.z)
                                                                                    * (float)((float)v39 - v173.z))
                                                                            + (float)((float)((float)v41 - v173.y)
                                                                                    * (float)((float)v41 - v173.y))))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)((float)v66 * (float)v63)
                                                                                    * (float)((float)((float)((float)((float)v42 - v173.x) * (float)((float)v42 - v173.x)) + (float)((float)((float)((float)v39 - v173.z) * (float)((float)v39 - v173.z)) + (float)((float)((float)v41 - v173.y) * (float)((float)v41 - v173.y))))
                                                                                            * (float)0.5))
                                                                            * (float)((float)v66 * (float)v63))
                                                                    - (float)1.5)
                                                    * (float)((float)v66 * (float)v63)))
                                    - (float)1.5)
                    * (float)v68);
        v71 = (float)((float)((float)v39 - v173.z) * (float)v70);
        v72 = (float)((float)v70
                    * (float)((float)((float)((float)v42 - v173.x) * (float)((float)v42 - v173.x))
                            + (float)((float)((float)((float)v39 - v173.z) * (float)((float)v39 - v173.z))
                                    + (float)((float)((float)v41 - v173.y) * (float)((float)v41 - v173.y)))));
        v73 = (float)((float)((float)v42 - v173.x) * (float)v70);
        v74 = (float)((float)((float)v41 - v173.y) * (float)v70);
        v75 = (float)((float)-(float)((float)((float)((float)v69
                                                    * (float)((float)((float)((float)v58 * (float)v58)
                                                                    + (float)((float)((float)v57 * (float)v57)
                                                                            + (float)((float)v56 * (float)v56)))
                                                            * (float)0.5))
                                            * (float)v69)
                                    - (float)1.5)
                    * (float)v69);
        v76 = (float)((float)v57
                    * (float)((float)-(float)((float)((float)((float)v69
                                                            * (float)((float)((float)((float)v58 * (float)v58)
                                                                            + (float)((float)((float)v57 * (float)v57)
                                                                                    + (float)((float)v56 * (float)v56)))
                                                                    * (float)0.5))
                                                    * (float)v69)
                                            - (float)1.5)
                            * (float)v69));
        v77 = (float)((float)v56
                    * (float)((float)-(float)((float)((float)((float)v69
                                                            * (float)((float)((float)((float)v58 * (float)v58)
                                                                            + (float)((float)((float)v57 * (float)v57)
                                                                                    + (float)((float)v56 * (float)v56)))
                                                                    * (float)0.5))
                                                    * (float)v69)
                                            - (float)1.5)
                            * (float)v69));
        v78 = (float)((float)v75
                    * (float)((float)((float)((float)((float)v42 - v173.x) * (float)0.5) + v173.x)
                            - inputs->localViewOrg.x));
        v79 = (float)((float)((float)((float)((float)v39 - v173.z) * (float)v70)
                            * (float)((float)v75
                                    * (float)((float)((float)((float)((float)v42 - v173.x) * (float)0.5) + v173.x)
                                            - inputs->localViewOrg.x)))
                    - (float)((float)v76 * (float)((float)((float)v42 - v173.x) * (float)v70)));
        v80 = (float)((float)((float)v76 * (float)((float)((float)v41 - v173.y) * (float)v70))
                    - (float)((float)v77 * (float)((float)((float)v39 - v173.z) * (float)v70)));
        v81 = (float)((float)((float)v77 * (float)((float)((float)v42 - v173.x) * (float)v70))
                    - (float)((float)((float)((float)v41 - v173.y) * (float)v70)
                            * (float)((float)v75
                                    * (float)((float)((float)((float)((float)v42 - v173.x) * (float)0.5) + v173.x)
                                            - inputs->localViewOrg.x))));
        _FP2 = (float)((float)((float)((float)v79 * (float)v79)
                             + (float)((float)((float)v80 * (float)v80) + (float)((float)v81 * (float)v81)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f4, f2, f4, f0 }
        v84 = __frsqrte(_FP4);
        v85 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84
                                                                                            * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)v80 * (float)v80) + (float)((float)v81 * (float)v81))) * (float)0.5))
                                                                                    * (float)v84)
                                                                            - (float)1.5)
                                                            * (float)v84)
                                                    * (float)((float)((float)((float)v79 * (float)v79)
                                                                    + (float)((float)((float)v80 * (float)v80)
                                                                            + (float)((float)v81 * (float)v81)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v84
                                                                                    * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)v80 * (float)v80) + (float)((float)v81 * (float)v81)))
                                                                                            * (float)0.5))
                                                                            * (float)v84)
                                                                    - (float)1.5)
                                                    * (float)v84))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v84
                                                            * (float)((float)((float)((float)v79 * (float)v79)
                                                                            + (float)((float)((float)v80 * (float)v80)
                                                                                    + (float)((float)v81 * (float)v81)))
                                                                    * (float)0.5))
                                                    * (float)v84)
                                            - (float)1.5)
                            * (float)v84));
        v86 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)v80 * (float)v80) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v84) - (float)1.5) * (float)v84)
                                                                                            * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)v80 * (float)v80) + (float)((float)v81 * (float)v81))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)v80 * (float)v80) + (float)((float)v81 * (float)v81))) * (float)0.5)) * (float)v84) - (float)1.5)
                                                                                            * (float)v84))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v84 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)v80 * (float)v80) + (float)((float)v81 * (float)v81))) * (float)0.5))
                                                                                            * (float)v84)
                                                                                    - (float)1.5)
                                                                    * (float)v84))
                                                    * (float)((float)((float)((float)v79 * (float)v79)
                                                                    + (float)((float)((float)v80 * (float)v80)
                                                                            + (float)((float)v81 * (float)v81)))
                                                            * (float)0.5))
                                            * (float)v85)
                                    - (float)1.5)
                    * (float)v85);
        v87 = (float)((float)v80 * (float)v86);
        v88 = (float)((float)v79 * (float)v86);
        v89 = (float)((float)v81 * (float)v86);
        if ( stage->orientation.aimedSafeQuad )
        {
          v90 = __fabs((float)((float)((float)v78 * (float)v73)
                             + (float)((float)((float)v76 * (float)v71) + (float)((float)v77 * (float)v74))));
          if ( stage->orientation.aimedSafeQuadAlign != 1.0 )
          {
            _FP29 = (float)((float)((float)1.0 - (float)((float)1.0 - stage->orientation.aimedSafeQuadAlign)) - v168);
            __asm { fsel      f1, f29, f1, f0 }
            v90 = (float)((float)((float)v90 - (float)((float)1.0 - stage->orientation.aimedSafeQuadAlign)) / (float)_FP1);
            if ( v90 >= 0.0 )
            {
              if ( v90 > 1.0 )
                v90 = 1.0;
            }
            else
            {
              v90 = 0.0;
            }
          }
          v93 = (float)((float)v73 * (float)v72);
          v94 = (float)((float)v74 * (float)v72);
          v95 = (float)((float)v71 * (float)v72);
          v97 = (float)((float)((float)((float)((float)((float)v88 * (float)v78)
                                              - (float)((float)v77 * (float)((float)v80 * (float)v86)))
                                      * (float)(v159 * (float)v15))
                              - (float)v95)
                      * (float)v90);
          v96 = (float)((float)((float)((float)((float)((float)v76 * (float)v87) - (float)((float)v89 * (float)v78))
                                      * (float)(v159 * (float)v15))
                              - (float)v94)
                      * (float)v90);
          v98 = (float)((float)((float)((float)((float)((float)((float)v89 * (float)v77)
                                                      - (float)((float)v88 * (float)v76))
                                              * (float)(v159 * (float)v15))
                                      - (float)v93)
                              * (float)v90)
                      + (float)v93);
          v99 = (float)((float)v96 + (float)v94);
          v100 = (float)((float)v97 + (float)v95);
        }
        else
        {
          v98 = (float)((float)v73 * (float)v72);
          v99 = (float)((float)v74 * (float)v72);
          v100 = (float)((float)v71 * (float)v72);
        }
        v101 = (float)((float)v99 * (float)0.5);
        v161 = (float)v99 * (float)0.5;
        v162 = (float)v100 * (float)0.5;
        v103 = (float)((float)v98 * (float)0.5);
        v160 = v103;
        v104 = (float)((float)v87 * (float)v15);
        v105 = (float)((float)v88 * (float)v15);
        v106 = (float)((float)v89 * (float)v15);
        v102 = v162;
        if ( v38 != 0 )
        {
          v107 = (float)((float)((float)v55 + (float)v103) - (float)v31);
          v108 = (float)((float)((float)v55 + (float)v103) + (float)v31);
          v109 = (float)((float)((float)v53 + v161) - (float)v33);
          v110 = (float)((float)((float)v54 + (float)((float)v100 * (float)0.5)) - (float)v37);
          v111 = (float)((float)((float)v53 + v161) + (float)v33);
          v112 = (float)((float)((float)v54 + (float)((float)v100 * (float)0.5)) + (float)v37);
        }
        else
        {
          v107 = (float)((float)((float)v55 + (float)v103) - (float)((float)v87 * (float)v15));
          v108 = (float)((float)((float)v55 + (float)v103) + (float)v104);
          v109 = (float)((float)((float)v53 + v161) - (float)((float)v88 * (float)v15));
          v110 = (float)((float)((float)v54 + (float)((float)v100 * (float)0.5)) - (float)((float)v89 * (float)v15));
          v111 = (float)((float)((float)v53 + v161) + (float)v105);
          v112 = (float)((float)((float)v54 + (float)((float)v100 * (float)0.5)) + (float)v106);
        }
        *(p_z - 10) = v107;
        *(p_z - 9) = v109;
        *(p_z - 8) = v110;
        *p_z = v112;
        *(p_z - 1) = v111;
        *(p_z - 2) = v108;
        p_z[7] = (float)((float)v53 - (float)v101) - (float)v105;
        p_z[8] = (float)((float)v54 - (float)v102) - (float)v106;
        *(double *)&v113 = (float)((float)((float)v53 - (float)v101) + (float)v105);
        p_z[6] = (float)((float)v55 - (float)v103) - (float)v104;
        *((double *)&v113 + 1) = (float)((float)((float)v55 - (float)v103) + (float)v104);
        p_z[14] = (float)((float)v55 - (float)v103) + (float)v104;
        p_z[15] = (float)((float)v53 - (float)v101) + (float)v105;
        p_z[16] = (float)((float)v54 - (float)v102) + (float)v106;
        viewFade = stage->orientation.viewFade;
        if ( viewFade < 1.0 )
        {
          v115 = (float)((float)1.0 - stage->orientation.viewFade);
          v170 = v161;
          v171 = v162;
          v169 = v160;
          _FP1 = (float)((float)((float)((float)v103 * (float)v103)
                               + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v117 = (float)((float)((float)((float)v103 * (float)v103)
                               + (float)((float)((float)v102 * (float)v102) + (float)((float)v101 * (float)v101)))
                       * (float)0.5);
          __asm { fsel      f11, f1, f2, f13 }
          v119 = __frsqrte(_FP11);
          v121 = (float)((float)(v162
                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119) * (float)v117) * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119))
                                                                                               - (float)1.5)
                                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5)
                                                                                       * (float)v119))
                                                                       * (float)v117)
                                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119) * (float)v117)
                                                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                                                               - (float)1.5)
                                                                               * (float)v119)))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5)
                                                                                       * (float)v119)
                                                                               * (float)v117)
                                                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                                                               - (float)1.5)
                                                                               * (float)v119))
                                                               - (float)1.5)
                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117)
                                                                               * (float)v119)
                                                                       - (float)1.5)
                                                       * (float)v119))))
                       * (float)v76);
          v122 = (float)(v161
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119) * (float)v117)
                                                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                                                               - (float)1.5)
                                                                               * (float)v119))
                                                               * (float)v117)
                                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119)
                                                                                               * (float)v117)
                                                                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5)
                                                                                               * (float)v119))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117)
                                                                                               * (float)v119)
                                                                                       - (float)1.5)
                                                                       * (float)v119)))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                                                               - (float)1.5)
                                                                               * (float)v119)
                                                                       * (float)v117)
                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117)
                                                                                               * (float)v119)
                                                                                       - (float)1.5)
                                                                       * (float)v119))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                               - (float)1.5)
                                               * (float)v119))));
          v120 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119) * (float)v117)
                                                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119))
                                                                                       - (float)1.5)
                                                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                                                               - (float)1.5)
                                                                               * (float)v119))
                                                               * (float)v117)
                                                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5) * (float)v119)
                                                                                               * (float)v117)
                                                                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119) - (float)1.5)
                                                                                               * (float)v119))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117)
                                                                                               * (float)v119)
                                                                                       - (float)1.5)
                                                                       * (float)v119)))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                                                               - (float)1.5)
                                                                               * (float)v119)
                                                                       * (float)v117)
                                                               * (float)((float)-(float)((float)((float)((float)v119 * (float)v117)
                                                                                               * (float)v119)
                                                                                       - (float)1.5)
                                                                       * (float)v119))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)((float)v119 * (float)v117) * (float)v119)
                                                               - (float)1.5)
                                               * (float)v119)))
                       * (float)v103);
          _FP11 = (float)((float)__fabs((float)((float)((float)v122 * (float)v77)
                                              + (float)((float)((float)v120 * (float)v78) + (float)v121)))
                        - (float)viewFade);
          __asm { fsel      f10, f11, f11, f22 }
          if ( v38 != 0 )
          {
            _R11 = (char *)p_z - 10;
            _R10 = -2;
            _R9 = -1;
            v147 = v154;
            v128 = 2;
            _R8 = &v147;
            v148 = v155;
            v149 = v156;
            v150 = v157;
            __asm { lvx128    v62, r0, r8 }
            do
            {
              __asm
              {
                lvx128    v63, r0, r27
                vmulfp128 v63, v94, v63
                vcfpsxws128 v61, v63, 0
                vpkswss128 v60, v93, v61
                vpkshus128 v0, v92, v60
                stvebx    v0, r11, r10
                stvebx    v0, r11, r9
                stvebx    v0, 0, r11
                stvebx    v0, r11, r26
              }
              _R11 += 32;
              --v128;
            }
            while ( v128 != 0 );
          }
          _R10 = -2;
          _R9 = -1;
          *(double *)&v113 = v14->x;
          v132 = *(float *)&g[10].seed;
          v133 = *(float *)&g[11].seed;
          v134 = (float)((float)(inputs->entityColor.z * stage->colorAttributes.fadeColor.z)
                       * (float)((float)_FP10 / (float)v115));
          *((double *)&v113 + 1) = (float)((float)(inputs->entityColor.w * stage->colorAttributes.fadeColor.w)
                                         * (float)((float)_FP10 / (float)v115));
          v136 = (float)((float)(*(float *)&g[9].seed * (float)((float)1.0 - (float)((float)_FP10 / (float)v115)))
                       + (float)((float)(inputs->entityColor.y * stage->colorAttributes.fadeColor.y)
                               * (float)((float)_FP10 / (float)v115)));
          v135 = (float)((float)((float)(stage->colorAttributes.fadeColor.x * inputs->entityColor.x)
                               * (float)((float)_FP10 / (float)v115))
                       + (float)(v14->x * (float)((float)1.0 - (float)((float)_FP10 / (float)v115))));
          v148 = (float)(*(float *)&g[9].seed * (float)((float)1.0 - (float)((float)_FP10 / (float)v115)))
               + (float)((float)(inputs->entityColor.y * stage->colorAttributes.fadeColor.y)
                       * (float)((float)_FP10 / (float)v115));
          v147 = v135;
          v149 = (float)((float)v132 * (float)((float)1.0 - (float)((float)_FP10 / (float)v115))) + (float)v134;
          v150 = (float)((float)v133 * (float)((float)1.0 - (float)((float)_FP10 / (float)v115)))
               + (float)*((double *)&v113 + 1);
          if ( v38 != 0 )
          {
            _R11 = (char *)p_z + 54;
            v141 = 2;
            _R8 = &v147;
            __asm { lvx128    v62, r0, r8 }
            do
            {
              __asm
              {
                lvx128    v63, r0, r27
                vmulfp128 v56, v94, v63
                vcfpsxws128 v55, v56, 0
                vpkswss128 v54, v87, v55
                vpkshus128 v0, v86, v54
                stvebx    v0, r11, r10
                stvebx    v0, r11, r9
                stvebx    v0, 0, r11
                stvebx    v0, r11, r26
              }
              _R11 += 32;
              --v141;
            }
            while ( v141 != 0 );
          }
          else
          {
            _R11 = (char *)p_z - 10;
            v138 = 4;
            _R8 = &v147;
            __asm { lvx128    v62, r0, r8 }
            do
            {
              __asm
              {
                lvx128    v63, r0, r27
                vmulfp128 v59, v94, v63
                vcfpsxws128 v58, v59, 0
                vpkswss128 v57, v90, v58
                vpkshus128 v0, v89, v57
                stvebx    v0, r11, r10
                stvebx    v0, r11, r9
                stvebx    v0, 0, r11
                stvebx    v0, r11, r26
              }
              _R11 += 32;
              --v138;
            }
            while ( v138 != 0 );
          }
          v154 = v135;
          v155 = v136;
          v156 = (float)((float)v132 * (float)((float)1.0 - (float)((float)_FP10 / (float)v115))) + (float)v134;
          v157 = (float)((float)v133 * (float)((float)1.0 - (float)((float)_FP10 / (float)v115)))
               + (float)*((double *)&v113 + 1);
        }
        v172.x = v29;
        v172.y = v165;
        *(float *)&v153 = 0.0;
        *((float *)&v153 + 1) = 1.0;
        v29 = (float)((float)v29 + v165);
        ParticleTexCoords(
          inputs,
          (particleGen_t *)g,
          sMinMax: (const idVec2 *)&v153,
          tMinMax: &v172,
          atlasWidth: view->atlasWidth,
          atlasHeight: view->atlasHeight,
          verts: (idTransparencyVert *)(p_z - 10),
          a8: v113);
        v31 = v104;
        v33 = v105;
        p_z += 32;
        v37 = v106;
        v42 = v52;
        v41 = y;
        v39 = v51;
        if ( v13 != nullptr )
          *v146 = (float)(view->viewFwd.x * (float)((float)v55 - view->viewOrg.x))
                + (float)((float)(view->viewFwd.z * (float)((float)v54 - view->viewOrg.z))
                        + (float)(view->viewFwd.y * (float)((float)v53 - view->viewOrg.y)));
        v28 = *(float *)&v164;
        ++v36;
        ++v146;
      }
      ++v38;
      HIDWORD(v43) = stage->orientation.numTrails;
    }
    while ( v38 <= SHIDWORD(v43) );
  }
  v143 = v163;
  v144 = v158;
  *p_seed = v28;
  *v35 = v144;
  v6->seed = v143;
  return 4 * v36;
}


// ========================================================================
// GenerateAimedVerts
// EA  : 0x827E75A8
// RVA : 0x007E75A8
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

int __fastcall GenerateAimedVerts(
        const particleInput_t *inputs,
        particleGen_t *g,
        idRandom2 *outputs,
        const idVec3 *origin,
        __int64 vel)
{
  const idParticleStage *stage; // r30
  float *v6; // r10
  idRandom2 *tables; // r25
  const particleRenderView_t *view; // r23
  float *v12; // r27
  int v13; // ctr
  int *p_totalParticles; // r9
  idTransparencyVert *seed; // r28
  float *v16; // r22
  double v17; // fp20
  __int64 v18; // r8
  idRandom2 *v19; // r5
  double v21; // fp1
  float *p_y; // r27
  float *p_z; // r26
  double v24; // fp4
  double v25; // fp6
  double v26; // fp31
  double v27; // fp11
  double v28; // fp7
  double v29; // fp3
  double v34; // fp13
  double v35; // fp5
  double v36; // fp5
  double v37; // fp13
  double v38; // fp7
  double v39; // fp12
  double v40; // fp11
  double v41; // fp7
  double v42; // fp16
  double v43; // fp14
  double v44; // fp15
  double v45; // fp4
  double v46; // fp3
  double v47; // fp7
  double v48; // fp5
  double v49; // fp6
  double v52; // fp2
  double v53; // fp8
  double v54; // fp2
  double v55; // fp8
  double v56; // fp7
  double v57; // fp6
  double v58; // fp2
  double v59; // fp18
  double v60; // fp6
  double v61; // fp3
  double v62; // fp5
  double v63; // fp30
  double v64; // fp28
  double v65; // fp29
  double v66; // fp27
  double v67; // fp18
  double v68; // fp26
  double v69; // fp2
  double v70; // fp1
  double v71; // fp4
  double v72; // fp3
  double v75; // fp10
  double v76; // fp10
  double v77; // fp10
  double v78; // fp25
  double v79; // fp10
  double v80; // fp13
  double v83; // fp13
  double v84; // fp12
  double v85; // fp11
  double v86; // fp30
  double v87; // fp29
  double v88; // fp6
  double v89; // fp12
  double v90; // fp13
  double v91; // fp11
  double v92; // fp8
  double v93; // fp10
  double v94; // fp7
  long double v95; // fp2
  double v96; // fp8
  double v97; // fp7
  double v99; // fp3
  double z; // fp29
  int v101; // ctr
  double v109; // fp12
  double v110; // fp12
  double v111; // fp12
  double v112; // fp12
  double v115; // fp4
  double v116; // fp12
  double v117; // fp10
  double v118; // fp7
  int result; // r3
  idVec2 v120; // [sp+50h] [-130h] BYREF
  idVec2 v121; // [sp+60h] [-120h] BYREF
  float v122; // [sp+68h] [-118h]
  float v123; // [sp+6Ch] [-114h] BYREF
  float v124; // [sp+70h] [-110h]
  float v125; // [sp+74h] [-10Ch]
  float v126; // [sp+78h] [-108h]
  float v127; // [sp+7Ch] [-104h]
  float v128; // [sp+80h] [-100h]
  float v129; // [sp+84h] [-FCh]
  float v130; // [sp+88h] [-F8h]
  float v131; // [sp+8Ch] [-F4h]
  float v132; // [sp+90h] [-F0h]

  stage = inputs->stage;
  v6 = &v123;
  tables = (idRandom2 *)inputs->tables;
  view = inputs->view;
  v12 = (float *)HIDWORD(vel);
  v13 = 9;
  p_totalParticles = &inputs->totalParticles;
  do
  {
    *(_DWORD *)++v6 = *++p_totalParticles;
    --v13;
  }
  while ( v13 != 0 );
  seed = (idTransparencyVert *)outputs->seed;
  v16 = (float *)outputs[1].seed;
  v17 = (float)(idParticleParm::Compute(
                  this: stage->size.size,
                  tables,
                  frac: g->parmVal,
                  rand: outputs,
                  a5: &g->random,
                  a6: vel)
              * inputs->sizeScale);
  v21 = idParticleParm::Compute(
          this: &stage->size.aspectRatio,
          tables,
          frac: g->parmVal,
          rand: v19,
          a5: &g->random,
          a6: v18);
  p_z = &origin->z;
  v24 = (float)(origin->y - inputs->localViewOrg.y);
  v25 = (float)(origin->z - inputs->localViewOrg.z);
  v26 = (float)(origin->x - inputs->localViewOrg.x);
  v27 = (float)((float)(inputs->globalAxis.mat[2].z * v12[2])
              + (float)((float)(inputs->globalAxis.mat[0].z * *v12) + (float)(inputs->globalAxis.mat[1].z * v12[1])));
  v28 = (float)((float)(inputs->globalAxis.mat[0].x * *v12)
              + (float)((float)(inputs->globalAxis.mat[1].x * v12[1]) + (float)(inputs->globalAxis.mat[2].x * v12[2])));
  v29 = (float)((float)(inputs->globalAxis.mat[2].y * v12[2])
              + (float)((float)(inputs->globalAxis.mat[0].y * *v12) + (float)(inputs->globalAxis.mat[1].y * v12[1])));
  _FP2 = (float)((float)((float)((float)v26 * (float)v26)
                       + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP13 = (float)((float)((float)((float)v29 * (float)v29)
                        + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f2, f8, f10 }
  __asm { fsel      f5, f13, f5, f10 }
  v34 = __frsqrte(_FP5);
  v35 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                                      * (float)((float)((float)((float)v29 * (float)v29) + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))
                                                                                              * (float)0.5))
                                                                              * (float)v34)
                                                                      - (float)1.5)
                                                      * (float)v34)
                                              * (float)((float)((float)((float)v29 * (float)v29)
                                                              + (float)((float)((float)v28 * (float)v28)
                                                                      + (float)((float)v27 * (float)v27)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v34
                                                                              * (float)((float)((float)((float)v29 * (float)v29)
                                                                                              + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))
                                                                                      * (float)0.5))
                                                                      * (float)v34)
                                                              - (float)1.5)
                                              * (float)v34))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v34
                                                      * (float)((float)((float)((float)v29 * (float)v29)
                                                                      + (float)((float)((float)v28 * (float)v28)
                                                                              + (float)((float)v27 * (float)v27)))
                                                              * (float)0.5))
                                              * (float)v34)
                                      - (float)1.5)
                      * (float)v34));
  v36 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34 * (float)((float)((float)((float)v29 * (float)v29) + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27))) * (float)0.5)) * (float)v34) - (float)1.5)
                                                                                              * (float)v34)
                                                                                      * (float)((float)((float)((float)v29 * (float)v29) + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v34 * (float)((float)((float)((float)v29 * (float)v29) + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27))) * (float)0.5)) * (float)v34) - (float)1.5)
                                                                                      * (float)v34))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v34
                                                                                              * (float)((float)((float)((float)v29 * (float)v29) + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27))) * (float)0.5))
                                                                                      * (float)v34)
                                                                              - (float)1.5)
                                                              * (float)v34))
                                              * (float)((float)((float)((float)v29 * (float)v29)
                                                              + (float)((float)((float)v28 * (float)v28)
                                                                      + (float)((float)v27 * (float)v27)))
                                                      * (float)0.5))
                                      * (float)v35)
                              - (float)1.5)
              * (float)v35);
  v37 = (float)((float)((float)(inputs->globalAxis.mat[0].x * *v12)
                      + (float)((float)(inputs->globalAxis.mat[1].x * v12[1])
                              + (float)(inputs->globalAxis.mat[2].x * v12[2])))
              * (float)v36);
  v38 = __frsqrte(_FP2);
  v39 = (float)((float)((float)(inputs->globalAxis.mat[2].y * v12[2])
                      + (float)((float)(inputs->globalAxis.mat[0].y * *v12)
                              + (float)(inputs->globalAxis.mat[1].y * v12[1])))
              * (float)v36);
  v40 = (float)((float)((float)(inputs->globalAxis.mat[2].z * v12[2])
                      + (float)((float)(inputs->globalAxis.mat[0].z * *v12)
                              + (float)(inputs->globalAxis.mat[1].z * v12[1])))
              * (float)v36);
  v41 = (float)((float)-(float)((float)((float)((float)v38
                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                              + (float)((float)((float)v25 * (float)v25)
                                                                      + (float)((float)v24 * (float)v24)))
                                                      * (float)0.5))
                                      * (float)v38)
                              - (float)1.5)
              * (float)v38);
  v42 = (float)((float)v25
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41)
                                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)((float)v25 * (float)v25)
                                                                              + (float)((float)v24 * (float)v24)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v41
                                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)((float)v25 * (float)v25)
                                                                                      + (float)((float)v24 * (float)v24)))
                                                                      * (float)0.5))
                                                      * (float)v41)
                                              - (float)1.5)
                              * (float)v41)));
  v43 = (float)((float)v24
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41)
                                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)((float)v25 * (float)v25)
                                                                              + (float)((float)v24 * (float)v24)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v41
                                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)((float)v25 * (float)v25)
                                                                                      + (float)((float)v24 * (float)v24)))
                                                                      * (float)0.5))
                                                      * (float)v41)
                                              - (float)1.5)
                              * (float)v41)));
  v44 = (float)((float)v26
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41)
                                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                                      + (float)((float)((float)v25 * (float)v25)
                                                                              + (float)((float)v24 * (float)v24)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v41
                                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)((float)v25 * (float)v25)
                                                                                      + (float)((float)v24 * (float)v24)))
                                                                      * (float)0.5))
                                                      * (float)v41)
                                              - (float)1.5)
                              * (float)v41)));
  v46 = (float)((float)((float)((float)(inputs->globalAxis.mat[2].y * v12[2])
                              + (float)((float)(inputs->globalAxis.mat[0].y * *v12)
                                      + (float)(inputs->globalAxis.mat[1].y * v12[1])))
                      * (float)v36)
              * (float)((float)v26
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                              * (float)v41)
                                                                                      - (float)1.5)
                                                                      * (float)v41)
                                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)((float)v25 * (float)v25)
                                                                                      + (float)((float)v24 * (float)v24)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v41
                                                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                                                      + (float)((float)((float)v25 * (float)v25)
                                                                                              + (float)((float)v24 * (float)v24)))
                                                                              * (float)0.5))
                                                              * (float)v41)
                                                      - (float)1.5)
                                      * (float)v41))));
  v45 = (float)((float)((float)v25
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                              * (float)v41)
                                                                                      - (float)1.5)
                                                                      * (float)v41)
                                                              * (float)((float)((float)((float)v26 * (float)v26)
                                                                              + (float)((float)((float)v25 * (float)v25)
                                                                                      + (float)((float)v24 * (float)v24)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                                              * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)v41)
                                                                              - (float)1.5)
                                                              * (float)v41))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v41
                                                                      * (float)((float)((float)((float)v26 * (float)v26)
                                                                                      + (float)((float)((float)v25 * (float)v25)
                                                                                              + (float)((float)v24 * (float)v24)))
                                                                              * (float)0.5))
                                                              * (float)v41)
                                                      - (float)1.5)
                                      * (float)v41)))
              * (float)((float)((float)(inputs->globalAxis.mat[0].x * *v12)
                              + (float)((float)(inputs->globalAxis.mat[1].x * v12[1])
                                      + (float)(inputs->globalAxis.mat[2].x * v12[2])))
                      * (float)v36));
  v47 = (float)((float)((float)((float)((float)(inputs->globalAxis.mat[2].z * v12[2])
                                      + (float)((float)(inputs->globalAxis.mat[0].z * *v12)
                                              + (float)(inputs->globalAxis.mat[1].z * v12[1])))
                              * (float)v36)
                      * (float)v44)
              - (float)v45);
  v48 = (float)((float)((float)v42
                      * (float)((float)((float)(inputs->globalAxis.mat[2].y * v12[2])
                                      + (float)((float)(inputs->globalAxis.mat[0].y * *v12)
                                              + (float)(inputs->globalAxis.mat[1].y * v12[1])))
                              * (float)v36))
              - (float)((float)v43
                      * (float)((float)((float)(inputs->globalAxis.mat[2].z * v12[2])
                                      + (float)((float)(inputs->globalAxis.mat[0].z * *v12)
                                              + (float)(inputs->globalAxis.mat[1].z * v12[1])))
                              * (float)v36)));
  p_y = &origin->y;
  v49 = (float)((float)((float)v43 * (float)v37) - (float)v46);
  _FP8 = (float)((float)((float)((float)v48 * (float)v48)
                       + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f8, f2, f10 }
  v52 = __frsqrte(_FP3);
  v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52
                                                                                      * (float)((float)((float)((float)v48 * (float)v48) + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47)))
                                                                                              * (float)0.5))
                                                                              * (float)v52)
                                                                      - (float)1.5)
                                                      * (float)v52)
                                              * (float)((float)((float)((float)v48 * (float)v48)
                                                              + (float)((float)((float)v49 * (float)v49)
                                                                      + (float)((float)v47 * (float)v47)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v52
                                                                              * (float)((float)((float)((float)v48 * (float)v48)
                                                                                              + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47)))
                                                                                      * (float)0.5))
                                                                      * (float)v52)
                                                              - (float)1.5)
                                              * (float)v52))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v52
                                                      * (float)((float)((float)((float)v48 * (float)v48)
                                                                      + (float)((float)((float)v49 * (float)v49)
                                                                              + (float)((float)v47 * (float)v47)))
                                                              * (float)0.5))
                                              * (float)v52)
                                      - (float)1.5)
                      * (float)v52));
  v54 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v48 * (float)v48) + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47))) * (float)0.5)) * (float)v52) - (float)1.5)
                                                                                              * (float)v52)
                                                                                      * (float)((float)((float)((float)v48 * (float)v48) + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v52 * (float)((float)((float)((float)v48 * (float)v48) + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47))) * (float)0.5)) * (float)v52) - (float)1.5)
                                                                                      * (float)v52))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v52
                                                                                              * (float)((float)((float)((float)v48 * (float)v48) + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47))) * (float)0.5))
                                                                                      * (float)v52)
                                                                              - (float)1.5)
                                                              * (float)v52))
                                              * (float)((float)((float)((float)v48 * (float)v48)
                                                              + (float)((float)((float)v49 * (float)v49)
                                                                      + (float)((float)v47 * (float)v47)))
                                                      * (float)0.5))
                                      * (float)v53)
                              - (float)1.5)
              * (float)v53);
  v55 = (float)((float)v48 * (float)v54);
  v56 = (float)((float)v47 * (float)v54);
  v57 = (float)((float)v49 * (float)v54);
  if ( stage->orientation.world )
  {
    v58 = (float)((float)(v126 * (float)v40) + (float)(v125 * (float)v39));
    v59 = (float)((float)(v129 * (float)v57) + (float)(v128 * (float)v56));
    v61 = (float)((float)(v132 * (float)v40) + (float)(v131 * (float)v39));
    v62 = (float)((float)(v124 * (float)v55) + (float)((float)(v126 * (float)v57) + (float)(v125 * (float)v56)));
    v60 = (float)((float)(v132 * (float)v57) + (float)(v131 * (float)v56));
    v56 = (float)((float)(v127 * (float)v55) + (float)v59);
    v57 = (float)((float)(v130 * (float)v55) + (float)v60);
    v39 = (float)((float)(v127 * (float)v37) + (float)((float)(v129 * (float)v40) + (float)(v128 * (float)v39)));
    v40 = (float)((float)(v130 * (float)v37) + (float)v61);
    v55 = v62;
    v37 = (float)((float)(v124 * (float)v37) + (float)v58);
  }
  v63 = (float)((float)v37 * (float)(stage->orientation.segmentLength * (float)v21));
  v64 = (float)((float)v40 * (float)(stage->orientation.segmentLength * (float)v21));
  v65 = (float)((float)v39 * (float)(stage->orientation.segmentLength * (float)v21));
  v66 = (float)((float)((float)v37 * (float)(stage->orientation.segmentLength * (float)v21)) * (float)0.5);
  v67 = (float)((float)((float)v40 * (float)(stage->orientation.segmentLength * (float)v21)) * (float)0.5);
  v68 = (float)((float)((float)v39 * (float)(stage->orientation.segmentLength * (float)v21)) * (float)0.5);
  if ( stage->orientation.aimedSafeQuad )
  {
    v69 = (float)((float)v21 * (float)v17);
    v70 = (float)((float)((float)((float)((float)v39 * (float)(stage->orientation.segmentLength * (float)v21))
                                * (float)0.5)
                        + origin->y)
                - inputs->localViewOrg.y);
    v71 = (float)((float)((float)v67 + origin->z) - inputs->localViewOrg.z);
    v72 = (float)((float)(origin->x + (float)v66) - inputs->localViewOrg.x);
    _FP24 = (float)((float)((float)((float)v72 * (float)v72)
                          + (float)((float)((float)v71 * (float)v71) + (float)((float)v70 * (float)v70)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f10, f24, f25, f10 }
    v75 = __frsqrte(_FP10);
    v76 = (float)((float)-(float)((float)((float)((float)v75
                                                * (float)((float)((float)((float)v72 * (float)v72)
                                                                + (float)((float)((float)v71 * (float)v71)
                                                                        + (float)((float)v70 * (float)v70)))
                                                        * (float)0.5))
                                        * (float)v75)
                                - (float)1.5)
                * (float)v75);
    v77 = (float)((float)-(float)((float)((float)((float)v76
                                                * (float)((float)((float)((float)v72 * (float)v72)
                                                                + (float)((float)((float)v71 * (float)v71)
                                                                        + (float)((float)v70 * (float)v70)))
                                                        * (float)0.5))
                                        * (float)v76)
                                - (float)1.5)
                * (float)v76);
    v78 = (float)((float)-(float)((float)((float)((float)v77
                                                * (float)((float)((float)((float)v72 * (float)v72)
                                                                + (float)((float)((float)v71 * (float)v71)
                                                                        + (float)((float)v70 * (float)v70)))
                                                        * (float)0.5))
                                        * (float)v77)
                                - (float)1.5)
                * (float)v77);
    v79 = (float)((float)v71
                * (float)((float)-(float)((float)((float)((float)v77
                                                        * (float)((float)((float)((float)v72 * (float)v72)
                                                                        + (float)((float)((float)v71 * (float)v71)
                                                                                + (float)((float)v70 * (float)v70)))
                                                                * (float)0.5))
                                                * (float)v77)
                                        - (float)1.5)
                        * (float)v77));
    v80 = __fabs((float)((float)((float)((float)((float)((float)v68 + origin->y) - inputs->localViewOrg.y) * (float)v78)
                               * (float)v39)
                       + (float)((float)((float)((float)((float)(origin->x + (float)v66) - inputs->localViewOrg.x)
                                               * (float)v78)
                                       * (float)v37)
                               + (float)((float)v79 * (float)v40))));
    if ( stage->orientation.aimedSafeQuadAlign != 1.0 )
    {
      _FP11 = (float)((float)((float)1.0 - (float)((float)1.0 - stage->orientation.aimedSafeQuadAlign)) - (float)0.000001);
      __asm { fsel      f1, f11, f1, f12 }
      v80 = (float)((float)((float)v80 - (float)((float)1.0 - stage->orientation.aimedSafeQuadAlign)) / (float)_FP1);
      if ( v80 >= 0.0 )
      {
        if ( v80 > 1.0 )
          v80 = 1.0;
      }
      else
      {
        v80 = 0.0;
      }
    }
    v84 = (float)((float)((float)((float)((float)((float)((float)v79 * (float)v55)
                                                - (float)((float)v57
                                                        * (float)((float)((float)(origin->x + (float)v66)
                                                                        - inputs->localViewOrg.x)
                                                                * (float)v78)))
                                        * (float)v69)
                                - (float)v65)
                        * (float)v80)
                + (float)v65);
    v85 = (float)((float)((float)((float)((float)((float)((float)v56
                                                        * (float)((float)((float)(origin->x + (float)v66)
                                                                        - inputs->localViewOrg.x)
                                                                * (float)v78))
                                                - (float)((float)((float)((float)((float)v68 + origin->y)
                                                                        - inputs->localViewOrg.y)
                                                                * (float)v78)
                                                        * (float)v55))
                                        * (float)v69)
                                - (float)v64)
                        * (float)v80)
                + (float)v64);
    v83 = (float)((float)v63
                + (float)((float)((float)((float)((float)((float)((float)((float)((float)v68 + origin->y)
                                                                        - inputs->localViewOrg.y)
                                                                * (float)v78)
                                                        * (float)v57)
                                                - (float)((float)v79 * (float)v56))
                                        * (float)v69)
                                - (float)v63)
                        * (float)v80));
  }
  else
  {
    v83 = (float)((float)v37 * (float)(stage->orientation.segmentLength * (float)v21));
    v84 = (float)((float)v39 * (float)(stage->orientation.segmentLength * (float)v21));
    v85 = (float)((float)v40 * (float)(stage->orientation.segmentLength * (float)v21));
  }
  v86 = (float)((float)v55 * (float)v17);
  v87 = (float)((float)v56 * (float)v17);
  v88 = (float)((float)v57 * (float)v17);
  v92 = (float)((float)((float)v68 + *p_y) - (float)((float)v84 * (float)0.5));
  v89 = (float)((float)((float)v68 + *p_y) + (float)((float)v84 * (float)0.5));
  v93 = (float)((float)(origin->x + (float)v66) - (float)((float)v83 * (float)0.5));
  v90 = (float)((float)(origin->x + (float)v66) + (float)((float)v83 * (float)0.5));
  v94 = (float)((float)(*p_z + (float)v67) - (float)((float)v85 * (float)0.5));
  v91 = (float)((float)(*p_z + (float)v67) + (float)((float)v85 * (float)0.5));
  seed->xyz.y = (float)v89 - (float)v87;
  seed->xyz.x = (float)v90 - (float)v86;
  seed->xyz.z = (float)v91 - (float)v88;
  seed[1].xyz.x = (float)v90 + (float)v86;
  seed[1].xyz.z = (float)v91 + (float)v88;
  seed[1].xyz.y = (float)v89 + (float)v87;
  seed[2].xyz.x = (float)v93 - (float)v86;
  seed[2].xyz.y = (float)v92 - (float)v87;
  seed[2].xyz.z = (float)v94 - (float)v88;
  *(double *)&v95 = (float)((float)v94 + (float)v88);
  seed[3].xyz.z = (float)v94 + (float)v88;
  seed[3].xyz.x = (float)v93 + (float)v86;
  *((double *)&v95 + 1) = (float)((float)v92 + (float)v87);
  seed[3].xyz.y = (float)v92 + (float)v87;
  if ( stage->orientation.viewFade < 1.0 )
  {
    v96 = (float)((float)v89 - (float)v92);
    v97 = (float)((float)v91 - (float)v94);
    *(double *)&v95 = (float)(inputs->entityColor.z * stage->colorAttributes.fadeColor.z);
    _R6 = &v121;
    v99 = (float)(inputs->entityColor.x * stage->colorAttributes.fadeColor.x);
    z = g->vertColor.z;
    v101 = 4;
    _R9 = -2;
    _R10 = -1;
    _R7 = 1;
    _R8 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
    _FP25 = (float)((float)((float)((float)((float)v90 - (float)v93) * (float)((float)v90 - (float)v93))
                          + (float)((float)((float)v97 * (float)v97) + (float)((float)v96 * (float)v96)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    _R11 = &seed->color[2];
    __asm { fsel      f12, f25, f31, f12 }
    v109 = __frsqrte(_FP12);
    v110 = (float)((float)-(float)((float)((float)((float)v109
                                                 * (float)((float)((float)((float)((float)v90 - (float)v93)
                                                                         * (float)((float)v90 - (float)v93))
                                                                 + (float)((float)((float)v97 * (float)v97)
                                                                         + (float)((float)v96 * (float)v96)))
                                                         * (float)0.5))
                                         * (float)v109)
                                 - (float)1.5)
                 * (float)v109);
    v111 = (float)((float)-(float)((float)((float)((float)v110
                                                 * (float)((float)((float)((float)((float)v90 - (float)v93)
                                                                         * (float)((float)v90 - (float)v93))
                                                                 + (float)((float)((float)v97 * (float)v97)
                                                                         + (float)((float)v96 * (float)v96)))
                                                         * (float)0.5))
                                         * (float)v110)
                                 - (float)1.5)
                 * (float)v110);
    v112 = (float)((float)-(float)((float)((float)((float)v111
                                                 * (float)((float)((float)((float)((float)v90 - (float)v93)
                                                                         * (float)((float)v90 - (float)v93))
                                                                 + (float)((float)((float)v97 * (float)v97)
                                                                         + (float)((float)v96 * (float)v96)))
                                                         * (float)0.5))
                                         * (float)v111)
                                 - (float)1.5)
                 * (float)v111);
    _FP7 = (float)((float)__fabs((float)((float)((float)((float)v96 * (float)v112) * (float)v43)
                                       + (float)((float)((float)((float)((float)v90 - (float)v93) * (float)v112)
                                                       * (float)v44)
                                               + (float)((float)((float)v97 * (float)v112) * (float)v42))))
                 - stage->orientation.viewFade);
    __asm { fsel      f6, f7, f7, f17 }
    v115 = (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade));
    v116 = (float)((float)(inputs->entityColor.z * stage->colorAttributes.fadeColor.z)
                 * (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    *((double *)&v95 + 1) = (float)((float)1.0 - (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    v117 = (float)(g->vertColor.x
                 * (float)((float)1.0 - (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade))));
    v118 = (float)((float)(g->vertColor.w
                         * (float)((float)1.0 - (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade))))
                 + (float)((float)(inputs->entityColor.w * stage->colorAttributes.fadeColor.w)
                         * (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade))));
    v121.y = (float)(g->vertColor.y
                   * (float)((float)1.0 - (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade))))
           + (float)((float)(inputs->entityColor.y * stage->colorAttributes.fadeColor.y)
                   * (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    v123 = v118;
    v122 = (float)((float)z * (float)*((double *)&v95 + 1)) + (float)v116;
    v121.x = (float)((float)v99 * (float)v115) + (float)v117;
    __asm { lvx128    v62, r0, r6 }
    do
    {
      __asm
      {
        lvx128    v63, r0, r8
        vmulfp128 v63, v94, v63
        vcfpsxws128 v61, v63, 0
        vpkswss128 v60, v93, v61
        vpkshus128 v0, v92, v60
        stvebx    v0, r11, r9
        stvebx    v0, r11, r10
        stvebx    v0, 0, r11
        stvebx    v0, r11, r7
      }
      _R11 += 32;
      --v101;
    }
    while ( v101 != 0 );
  }
  v120.x = 0.0;
  v120.y = 1.0;
  v121.x = 0.0;
  v121.y = 1.0;
  ParticleTexCoords(
    inputs,
    g,
    sMinMax: &v121,
    tMinMax: &v120,
    atlasWidth: view->atlasWidth,
    atlasHeight: view->atlasHeight,
    verts: seed,
    a8: v95);
  result = 4;
  if ( v16 != nullptr )
    *v16 = (float)((float)((float)((float)v66 + origin->x) - view->viewOrg.x) * view->viewFwd.x)
         + (float)((float)(view->viewFwd.z * (float)((float)(*p_z + (float)v67) - view->viewOrg.z))
                 + (float)(view->viewFwd.y * (float)((float)((float)v68 + *p_y) - view->viewOrg.y)));
  return result;
}


// ========================================================================
// GenerateStaticMeshVerts
// EA  : 0x827E7C38
// RVA : 0x007E7C38
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall GenerateStaticMeshVerts(
        const particleInput_t *inputs,
        particleGen_t *g,
        idRandom2 *outputs,
        const idVec3 *origin,
        __int64 genericParm,
        long double a6)
{
  const idParticleStage *stage; // r21
  idRandom2 *tables; // r29
  unsigned __int8 *v8; // r24
  const particleRenderView_t *view; // r23
  const idDrawVert *staticVerts; // r26
  idTransparencyVert *seed; // r25
  unsigned __int8 v15; // r27
  double v16; // fp30
  __int64 v17; // r8
  idRandom2 *v18; // r5
  double v19; // fp29
  __int64 v20; // r8
  idRandom2 *v21; // r5
  double v22; // fp1
  double v23; // fp21
  double v24; // fp20
  double v25; // fp19
  __int64 v26; // r8
  idRandom2 *v27; // r5
  double v28; // fp30
  __int64 v29; // r8
  idRandom2 *v30; // r5
  double v31; // fp29
  __int64 v32; // r8
  idRandom2 *v33; // r5
  double v34; // fp28
  __int64 v35; // r8
  idRandom2 *v36; // r5
  double v37; // fp27
  __int64 v38; // r8
  idRandom2 *v39; // r5
  double v40; // fp26
  __int64 v41; // r8
  idRandom2 *v42; // r5
  double v43; // fp1
  double v44; // fp8
  double v45; // fp30
  double v46; // fp29
  float *v47; // r3
  float *v48; // r3
  float *v49; // r3
  prtOrientationType_t type; // r10
  double v51; // fp12
  double v52; // fp9
  double v53; // fp6
  double v56; // fp11
  double v57; // fp2
  const idMat3 *v58; // r3
  __int64 v59; // r6 OVERLAPPED
  prtTextureFlipMode_t textureFlipS; // r11
  int v62; // r9
  bool v63; // r10
  prtTextureFlipMode_t textureFlipT; // r11
  bool v65; // r11
  char v66; // r9
  double v67; // fp12
  double v68; // fp13
  double v69; // fp15
  double v70; // fp16
  double y; // fp13
  double x; // fp0
  int atlasHeight; // r7
  int result; // r3
  int *p_numStaticVerts; // r19
  int v76; // r29
  BOOL v77; // r16
  double z; // fp30
  double v79; // fp29
  double v80; // fp28
  double v81; // fp27
  double v82; // fp26
  float *p_y; // r30
  double v84; // fp25
  double v86; // fp24
  double v87; // fp23
  double v88; // fp22
  int v89; // r22
  double v93; // fp11
  float v94; // r9
  double v95; // fp10
  float v96; // r10
  double v97; // fp0
  long double v98; // fp2
  double v99; // fp3
  double v100; // fp0
  double v101; // fp0
  double v102; // fp31
  long double v103; // fp2
  __int16 v104; // r11
  long double v106; // fp2
  __int16 v107; // r11
  int v109; // r9
  int v110; // r8
  int v111; // r5
  unsigned __int8 v112[4]; // [sp+50h] [-1D0h] BYREF
  float v113; // [sp+54h] [-1CCh] BYREF
  float v114; // [sp+58h] [-1C8h] BYREF
  bool v115; // [sp+5Ch] [-1C4h] BYREF
  __int64 v116; // [sp+60h] [-1C0h] BYREF
  float v117[2]; // [sp+68h] [-1B8h] BYREF
  float v118; // [sp+70h] [-1B0h] BYREF
  int v119; // [sp+74h] [-1ACh]
  float v120[2]; // [sp+78h] [-1A8h] BYREF
  idMat3 v121; // [sp+80h] [-1A0h] BYREF
  float v122; // [sp+A4h] [-17Ch] BYREF
  float v123; // [sp+A8h] [-178h]
  float v124; // [sp+ACh] [-174h]
  float v125; // [sp+B0h] [-170h]
  float v126; // [sp+B4h] [-16Ch] BYREF
  idVec4 *p_vertColor; // [sp+B8h] [-168h]
  idMat3 v128[5]; // [sp+C0h] [-160h] BYREF

  stage = inputs->stage;
  tables = (idRandom2 *)inputs->tables;
  v8 = (unsigned __int8 *)genericParm;
  view = inputs->view;
  staticVerts = inputs->staticVerts;
  seed = (idTransparencyVert *)outputs->seed;
  LODWORD(genericParm) = inputs->stage->texAnimation.numColumns;
  v120[0] = 0.0;
  v117[0] = 1.0;
  v113 = 0.0;
  v15 = BYTE3(genericParm);
  v114 = 1.0;
  v112[0] = 0;
  p_vertColor = &g->vertColor;
  v115 = false;
  if ( (unsigned int)genericParm > 1 || stage->texAnimation.numRows > 1u )
    ComputeTextureAnimation(
      inputs,
      g,
      width: (int)v117,
      s: v120,
      height: &v114,
      t: &v113,
      frameBlendFrac: v112,
      wrap: &v115,
      a9: a6);
  v16 = idParticleParm::Compute(
          this: stage->size.size,
          tables,
          frac: g->parmVal,
          rand: outputs,
          a5: &g->random,
          a6: genericParm);
  v19 = idParticleParm::Compute(
          this: &stage->size.size[1],
          tables,
          frac: g->parmVal,
          rand: v18,
          a5: &g->random,
          a6: v17);
  v22 = idParticleParm::Compute(
          this: &stage->size.size[2],
          tables,
          frac: g->parmVal,
          rand: v21,
          a5: &g->random,
          a6: v20);
  v23 = (float)((float)v16 * inputs->sizeScale);
  v24 = (float)((float)v19 * inputs->sizeScale);
  v25 = (float)((float)v22 * inputs->sizeScale);
  v28 = idParticleParm::Compute(
          this: stage->initialRotation.initialAngle,
          tables,
          frac: g->parmVal,
          rand: v27,
          a5: &g->random,
          a6: v26);
  v31 = idParticleParm::Compute(
          this: &stage->initialRotation.initialAngle[1],
          tables,
          frac: g->parmVal,
          rand: v30,
          a5: &g->random,
          a6: v29);
  v34 = idParticleParm::Compute(
          this: &stage->initialRotation.initialAngle[2],
          tables,
          frac: g->parmVal,
          rand: v33,
          a5: &g->random,
          a6: v32);
  v37 = idParticleParm::Compute(
          this: stage->rotation.rotation,
          tables,
          frac: g->parmVal,
          rand: v36,
          a5: &g->random,
          a6: v35);
  v40 = idParticleParm::Compute(
          this: &stage->rotation.rotation[1],
          tables,
          frac: g->parmVal,
          rand: v39,
          a5: &g->random,
          a6: v38);
  v43 = idParticleParm::Compute(
          this: &stage->rotation.rotation[2],
          tables,
          frac: g->parmVal,
          rand: v42,
          a5: &g->random,
          a6: v41);
  v44 = (float)((float)v28 + (float)((float)v37 * g->particleLife));
  v45 = (float)((float)v34 + (float)((float)v43 * g->particleLife));
  v46 = (float)((float)v31 + (float)((float)v40 * g->particleLife));
  idMath::SinCos16(a: (float)((float)v44 * idMath::M_DEG2RAD), s: v47, c: &v118, a4: &v122);
  idMath::SinCos16(a: (float)((float)v46 * idMath::M_DEG2RAD), s: v48, c: &v126, a4: (float *)&v116);
  idMath::SinCos16(a: (float)((float)v45 * idMath::M_DEG2RAD), s: v49, c: &v114, a4: &v113);
  type = stage->orientation.type;
  v121.mat[0].x = v113 * *(float *)&v116;
  v121.mat[0].y = v114 * *(float *)&v116;
  v121.mat[0].z = -v126;
  v121.mat[1].z = *(float *)&v116 * v118;
  v121.mat[2].z = *(float *)&v116 * v122;
  v121.mat[1].x = (float)((float)(v113 * v126) * v118) - (float)(v114 * v122);
  v121.mat[2].y = (float)(v122 * (float)(v114 * v126)) - (float)(v113 * v118);
  v121.mat[1].y = (float)(v113 * v122) + (float)(v118 * (float)(v114 * v126));
  v121.mat[2].x = (float)(v114 * v118) + (float)((float)(v113 * v126) * v122);
  if ( type == POR_VIEW )
  {
    v51 = (float)(origin->z - inputs->localViewOrg.z);
    v52 = (float)(origin->x - inputs->localViewOrg.x);
    v53 = (float)(origin->y - inputs->localViewOrg.y);
    _FP2 = (float)((float)((float)((float)v53 * (float)v53)
                         + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f13 }
    v56 = __frsqrte(_FP13);
    v57 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56
                                                                                        * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                                                                                                * (float)0.5))
                                                                                * (float)v56)
                                                                        - (float)1.5)
                                                        * (float)v56)
                                                * (float)((float)((float)((float)v53 * (float)v53)
                                                                + (float)((float)((float)v52 * (float)v52)
                                                                        + (float)((float)v51 * (float)v51)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v56
                                                                                * (float)((float)((float)((float)v53 * (float)v53)
                                                                                                + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51)))
                                                                                        * (float)0.5))
                                                                        * (float)v56)
                                                                - (float)1.5)
                                                * (float)v56))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v56
                                                        * (float)((float)((float)((float)v53 * (float)v53)
                                                                        + (float)((float)((float)v52 * (float)v52)
                                                                                + (float)((float)v51 * (float)v51)))
                                                                * (float)0.5))
                                                * (float)v56)
                                        - (float)1.5)
                        * (float)v56));
    v128[0].mat[0].y = (float)(origin->y - inputs->localViewOrg.y)
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56) * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56)
                                                                                             - (float)1.5)
                                                                             * (float)v56))
                                                             * (float)((float)((float)((float)v53 * (float)v53)
                                                                             + (float)((float)((float)v52 * (float)v52)
                                                                                     + (float)((float)v51 * (float)v51)))
                                                                     * (float)0.5))
                                                     * (float)v57)
                                             - (float)1.5)
                             * (float)v57);
    v128[0].mat[0].x = (float)v52
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56) * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56)
                                                                                             - (float)1.5)
                                                                             * (float)v56))
                                                             * (float)((float)((float)((float)v53 * (float)v53)
                                                                             + (float)((float)((float)v52 * (float)v52)
                                                                                     + (float)((float)v51 * (float)v51)))
                                                                     * (float)0.5))
                                                     * (float)v57)
                                             - (float)1.5)
                             * (float)v57);
    v128[0].mat[0].z = (float)v51
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56) * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56) - (float)1.5) * (float)v56))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v56 * (float)((float)((float)((float)v53 * (float)v53) + (float)((float)((float)v52 * (float)v52) + (float)((float)v51 * (float)v51))) * (float)0.5)) * (float)v56)
                                                                                             - (float)1.5)
                                                                             * (float)v56))
                                                             * (float)((float)((float)((float)v53 * (float)v53)
                                                                             + (float)((float)((float)v52 * (float)v52)
                                                                                     + (float)((float)v51 * (float)v51)))
                                                                     * (float)0.5))
                                                     * (float)v57)
                                             - (float)1.5)
                             * (float)v57);
    v58 = idVec3::ToMat3(this: (idVec3 *)&v128[0].mat[1].y, result: v128);
    idMat3::operator*=(this: &v121, a: v58);
  }
  idMat3::operator*=(this: &v121, a: &inputs->globalAxis);
  textureFlipS = stage->systemProperties.textureFlipS;
  _R14 = 1;
  v62 = g->index & 1;
  v63 = textureFlipS == PTEXTURE_FLIP_ALWAYS || textureFlipS == PTEXTURE_FLIP_RANDOM && v62 != 0;
  textureFlipT = stage->systemProperties.textureFlipT;
  v65 = textureFlipT == PTEXTURE_FLIP_ALWAYS || textureFlipT == PTEXTURE_FLIP_RANDOM && v62 != 0;
  v66 = *((_BYTE *)stage + 68);
  v113 = 1.0;
  v114 = 1.0;
  v67 = 1.0;
  v68 = 1.0;
  v69 = 0.0;
  v70 = 0.0;
  if ( (v66 & 0x20) != 0 )
  {
    y = stage->atlasScaleBias.y;
    x = stage->atlasScaleBias.x;
    atlasHeight = view->atlasHeight;
    LODWORD(v59) = view->atlasWidth;
    v70 = (float)((float)0.5 / (float)((float)*(__int64 *)((char *)&v59 - 4) * stage->atlasScaleBias.y));
    v69 = (float)((float)0.5 / (float)((float)v59 * stage->atlasScaleBias.x));
    v114 = (float)1.0 - (float)((float)0.5 / (float)((float)*(__int64 *)((char *)&v59 - 4) * stage->atlasScaleBias.y));
    v116 = v59;
    v113 = (float)1.0 - (float)((float)0.5 / (float)((float)v59 * (float)x));
    v68 = (float)((float)1.0 - (float)((float)0.5 / (float)((float)*(__int64 *)((char *)&v59 - 4) * (float)y)));
    v67 = v113;
  }
  result = stage->numStaticVerts;
  p_numStaticVerts = &stage->numStaticVerts;
  v76 = 0;
  if ( result > 0 )
  {
    v77 = v63;
    z = v121.mat[2].z;
    v79 = v121.mat[2].y;
    v80 = v121.mat[2].x;
    v81 = v121.mat[1].z;
    v82 = v121.mat[1].y;
    p_y = &staticVerts->st.y;
    v84 = v121.mat[1].x;
    _R31 = &seed->color[2];
    v86 = v121.mat[0].z;
    v87 = v121.mat[0].y;
    v88 = v121.mat[0].x;
    HIDWORD(v116) = v65;
    v89 = (unsigned __int16)((v112[0] << 8) | v15);
    _R20 = -2;
    _R26 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
    _R25 = -1;
    while ( 1 )
    {
      v93 = origin->y;
      v94 = *(p_y - 2);
      v95 = origin->z;
      v96 = *(p_y - 3);
      v97 = origin->x;
      v123 = *(p_y - 4);
      v125 = v94;
      v124 = v96;
      *((double *)&v98 + 1) = (float)((float)((float)v80 * (float)(v94 * (float)v25))
                                    + (float)((float)((float)v88 * (float)(v123 * (float)v23))
                                            + (float)((float)v84 * (float)(v96 * (float)v24))));
      v99 = (float)((float)((float)v86 * (float)(v123 * (float)v23))
                  + (float)((float)((float)v81 * (float)(v96 * (float)v24))
                          + (float)((float)z * (float)(v94 * (float)v25))));
      *(float *)(_R31 - 26) = (float)v93
                            + (float)((float)((float)v87 * (float)(v123 * (float)v23))
                                    + (float)((float)((float)v82 * (float)(v96 * (float)v24))
                                            + (float)((float)v79 * (float)(v94 * (float)v25))));
      *(float *)(_R31 - 22) = (float)v95 + (float)v99;
      *(float *)(_R31 - 30) = (float)v97 + (float)*((double *)&v98 + 1);
      v100 = *(p_y - 1);
      if ( v77 )
        v100 = (float)((float)1.0 - *(p_y - 1));
      v101 = (float)((float)((float)v100 * v117[0]) + v120[0]);
      if ( HIDWORD(v116) != 0 )
        v102 = (float)((float)1.0 - *p_y);
      else
        v102 = *p_y;
      if ( (*((_BYTE *)stage + 68) & 0x20) != 0 )
      {
        if ( v101 >= v69 )
        {
          if ( v101 > v67 )
            v101 = v67;
        }
        else
        {
          v101 = v69;
        }
        v101 = (float)((float)(stage->atlasScaleBias.x * (float)v101) + stage->atlasScaleBias.z);
        if ( v102 >= v70 )
        {
          if ( v102 <= v68 )
            v68 = v102;
        }
        else
        {
          v68 = v70;
        }
        v102 = (float)((float)(stage->atlasScaleBias.y * (float)v68) + stage->atlasScaleBias.w);
      }
      *(double *)&v98 = (float)((float)((float)((float)v101 - (float)0.5) * (float)65534.0) + (float)0.5);
      v103 = floor(x: v98);
      v119 = (int)(float)*(double *)&v103;
      v104 = v119;
      if ( v119 >= -32768 )
      {
        if ( v119 > 0x7FFF )
          v104 = 0x7FFF;
      }
      else
      {
        v104 = 0x8000;
      }
      *((_WORD *)_R31 - 7) = v104;
      *((_WORD *)_R31 - 9) = v104;
      *(double *)&v103 = (float)((float)((float)((float)v102 - (float)0.5) * (float)65534.0) + (float)0.5);
      v106 = floor(x: v103);
      v119 = (int)(float)*(double *)&v106;
      v107 = v119;
      if ( v119 >= -32768 )
      {
        if ( v119 > 0x7FFF )
          v107 = 0x7FFF;
      }
      else
      {
        v107 = 0x8000;
      }
      *((_WORD *)_R31 - 6) = v107;
      ++v76;
      *((_WORD *)_R31 - 8) = v107;
      __asm { lvx128    v63, r0, r26 }
      _R11 = p_vertColor;
      p_y += 8;
      __asm
      {
        lvx128    v62, r0, r11
        vmulfp128 v61, v94, v63
        vcfpsxws128 v60, v61, 0
        vpkswss128 v59, v92, v60
        vpkshus128 v0, v91, v59
        stvebx    v0, r31, r20
        stvebx    v0, r31, r25
        stvebx    v0, 0, r31
        stvebx    v0, r31, r14
      }
      v109 = v8[2];
      v110 = v8[3];
      v111 = __ROL4__(*v8, 8) | v8[1];
      *(_DWORD *)(_R31 - 6) = v89;
      *(_DWORD *)(_R31 - 10) = (((v111 << 8) | v109) << 8) | v110;
      _R31 += 32;
      result = *p_numStaticVerts;
      if ( v76 >= *p_numStaticVerts )
        break;
      v68 = v114;
      v67 = v113;
    }
  }
  return result;
}


// ========================================================================
// GenerateQuadVerts
// EA  : 0x827E8310
// RVA : 0x007E8310
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

int __fastcall GenerateQuadVerts(
        const particleInput_t *inputs,
        particleGen_t *g,
        particleOutput_t *outputs,
        const idVec3 *origin,
        long double a5)
{
  const idParticleStage *stage; // r30
  float *v6; // r10
  idRandom2 *tables; // r26
  const particleRenderView_t *view; // r24
  int *p_totalParticles; // r9
  int i; // ctr
  idTransparencyVert *verts; // r28
  float *quadDepth; // r23
  unsigned int atlasHeight; // r8
  idTransparencyVert *v17; // r9
  unsigned int atlasWidth; // r7
  __int64 v19; // r8
  idRandom2 *v20; // r5
  double v21; // fp29
  __int64 v22; // r8
  idRandom2 *v23; // r5
  __int64 v24; // r8
  idRandom2 *v25; // r5
  double v26; // fp26
  double parmVal; // fp1
  idRandom2 *p_random; // r6
  idParticleParm *initialAngle; // r3
  double v30; // fp31
  __int64 v31; // r8
  idRandom2 *v32; // r5
  double v33; // fp30
  __int64 v34; // r8
  idRandom2 *v35; // r5
  double v36; // fp28
  __int64 v37; // r8
  idRandom2 *v38; // r5
  double v39; // fp27
  __int64 v40; // r8
  idRandom2 *v41; // r5
  double v42; // fp23
  __int64 v43; // r8
  idRandom2 *v44; // r5
  double v45; // fp1
  double v46; // fp10
  double v47; // fp31
  double v48; // fp30
  float *v49; // r3
  float *v50; // r3
  float *v51; // r3
  double v52; // fp8
  double v53; // fp12
  double x; // fp13
  double v55; // fp9
  double y; // fp10
  double z; // fp0
  double v58; // fp11
  double v59; // fp31
  __int64 v60; // r8
  idRandom2 *v61; // r5
  float *v62; // r3
  double v63; // fp1
  double v64; // fp0
  prtOrientationType_t type; // r11
  double v66; // fp1
  double v67; // fp5
  double v68; // fp2
  double v69; // fp1
  double v70; // fp13
  double v71; // fp10
  double v72; // fp12
  double v73; // fp9
  double v74; // fp8
  double v75; // fp0
  double v76; // fp13
  double v77; // fp11
  double v78; // fp5
  double v79; // fp11
  double v80; // fp13
  double v81; // fp7
  double v82; // fp30
  double v83; // fp31
  double v84; // fp28
  double v85; // fp27
  double v86; // fp29
  double v87; // fp26
  float *p_y; // r27
  float *p_z; // r26
  double v90; // fp4
  double v91; // fp0
  double v92; // fp8
  double v93; // fp7
  double v94; // fp13
  double v95; // fp12
  double v96; // fp8
  double v97; // fp7
  double v98; // fp6
  double v99; // fp7
  double v100; // fp6
  double v101; // fp5
  double v102; // fp6
  double v103; // fp3
  double v104; // fp1
  int v108; // ctr
  double v111; // fp11
  double v113; // fp9
  double w; // fp8
  double v117; // fp4
  double v118; // fp1
  double v119; // fp13
  double v120; // fp10
  int result; // r3
  float v123; // [sp+50h] [-F0h] BYREF
  float v124; // [sp+54h] [-ECh] BYREF
  float v125; // [sp+58h] [-E8h] BYREF
  float v126; // [sp+5Ch] [-E4h] BYREF
  idVec3 v127; // [sp+60h] [-E0h] BYREF
  idVec3 v128; // [sp+70h] [-D0h] BYREF
  float v129; // [sp+7Ch] [-C4h] BYREF
  float v130; // [sp+80h] [-C0h]
  float v131; // [sp+84h] [-BCh]
  float v132; // [sp+88h] [-B8h]
  float v133; // [sp+8Ch] [-B4h]
  float v134; // [sp+90h] [-B0h]
  float v135; // [sp+94h] [-ACh]
  float v136; // [sp+98h] [-A8h]
  float v137; // [sp+9Ch] [-A4h]
  float v138; // [sp+A0h] [-A0h]

  stage = inputs->stage;
  v6 = &v129;
  tables = (idRandom2 *)inputs->tables;
  view = inputs->view;
  p_totalParticles = &inputs->totalParticles;
  for ( i = 9; i != 0; --i )
    *(_DWORD *)++v6 = *++p_totalParticles;
  verts = outputs->verts;
  quadDepth = outputs->quadDepth;
  atlasHeight = view->atlasHeight;
  v17 = outputs->verts;
  atlasWidth = view->atlasWidth;
  v128.x = 0.0;
  v128.y = 1.0;
  v127.x = 0.0;
  v127.y = 1.0;
  ParticleTexCoords(
    inputs,
    g,
    sMinMax: (const idVec2 *)&v127,
    tMinMax: (const idVec2 *)&v128,
    atlasWidth,
    atlasHeight,
    verts: v17,
    a8: a5);
  v21 = (float)(idParticleParm::Compute(
                  this: stage->size.size,
                  tables,
                  frac: g->parmVal,
                  rand: v20,
                  a5: &g->random,
                  a6: v19)
              * inputs->sizeScale);
  v26 = (float)(idParticleParm::Compute(
                  this: &stage->size.aspectRatio,
                  tables,
                  frac: g->parmVal,
                  rand: v23,
                  a5: &g->random,
                  a6: v22)
              * (float)v21);
  parmVal = g->parmVal;
  p_random = &g->random;
  initialAngle = stage->initialRotation.initialAngle;
  if ( stage->orientation.type == POR_XYZ )
  {
    v30 = idParticleParm::Compute(this: initialAngle, tables, frac: parmVal, rand: v25, a5: p_random, a6: v24);
    v33 = idParticleParm::Compute(
            this: &stage->initialRotation.initialAngle[1],
            tables,
            frac: g->parmVal,
            rand: v32,
            a5: &g->random,
            a6: v31);
    v36 = idParticleParm::Compute(
            this: &stage->initialRotation.initialAngle[2],
            tables,
            frac: g->parmVal,
            rand: v35,
            a5: &g->random,
            a6: v34);
    v39 = idParticleParm::Compute(
            this: stage->rotation.rotation,
            tables,
            frac: g->parmVal,
            rand: v38,
            a5: &g->random,
            a6: v37);
    v42 = idParticleParm::Compute(
            this: &stage->rotation.rotation[1],
            tables,
            frac: g->parmVal,
            rand: v41,
            a5: &g->random,
            a6: v40);
    v45 = idParticleParm::Compute(
            this: &stage->rotation.rotation[2],
            tables,
            frac: g->parmVal,
            rand: v44,
            a5: &g->random,
            a6: v43);
    v46 = (float)((float)v30 + (float)((float)v39 * g->particleLife));
    v47 = (float)((float)v36 + (float)((float)v45 * g->particleLife));
    v48 = (float)((float)v33 + (float)((float)v42 * g->particleLife));
    idMath::SinCos16(a: (float)((float)v46 * idMath::M_DEG2RAD), s: v49, c: &v128.x, a4: &v126);
    idMath::SinCos16(a: (float)((float)v48 * idMath::M_DEG2RAD), s: v50, c: &v123, a4: &v127.x);
    idMath::SinCos16(a: (float)((float)v47 * idMath::M_DEG2RAD), s: v51, c: &v124, a4: &v125);
    v52 = -v123;
    v53 = (float)((float)((float)v52 * inputs->globalAxis.mat[2].x)
                + (float)((float)((float)(v125 * v127.x) * inputs->globalAxis.mat[0].x)
                        + (float)((float)(v124 * v127.x) * inputs->globalAxis.mat[1].x)));
    x = (float)((float)((float)v52 * inputs->globalAxis.mat[2].y)
              + (float)((float)((float)(v125 * v127.x) * inputs->globalAxis.mat[0].y)
                      + (float)((float)(v124 * v127.x) * inputs->globalAxis.mat[1].y)));
    v55 = (float)((float)((float)(v127.x * v128.x) * inputs->globalAxis.mat[2].x)
                + (float)((float)((float)((float)((float)(v125 * v123) * v128.x) - (float)(v124 * v126))
                                * inputs->globalAxis.mat[0].x)
                        + (float)((float)((float)((float)(v124 * v123) * v128.x) + (float)(v125 * v126))
                                * inputs->globalAxis.mat[1].x)));
    y = (float)((float)((float)(v127.x * v128.x) * inputs->globalAxis.mat[2].y)
              + (float)((float)((float)((float)((float)(v125 * v123) * v128.x) - (float)(v124 * v126))
                              * inputs->globalAxis.mat[0].y)
                      + (float)((float)((float)((float)(v124 * v123) * v128.x) + (float)(v125 * v126))
                              * inputs->globalAxis.mat[1].y)));
    z = (float)((float)((float)v52 * inputs->globalAxis.mat[2].z)
              + (float)((float)((float)(v125 * v127.x) * inputs->globalAxis.mat[0].z)
                      + (float)((float)(v124 * v127.x) * inputs->globalAxis.mat[1].z)));
    v58 = (float)((float)((float)(v127.x * v128.x) * inputs->globalAxis.mat[2].z)
                + (float)((float)((float)((float)((float)(v125 * v123) * v128.x) - (float)(v124 * v126))
                                * inputs->globalAxis.mat[0].z)
                        + (float)((float)((float)((float)(v124 * v123) * v128.x) + (float)(v125 * v126))
                                * inputs->globalAxis.mat[1].z)));
  }
  else
  {
    v59 = idParticleParm::Compute(this: initialAngle, tables, frac: parmVal, rand: v25, a5: p_random, a6: v24);
    v63 = idParticleParm::Compute(
            this: stage->rotation.rotation,
            tables,
            frac: g->parmVal,
            rand: v61,
            a5: &g->random,
            a6: v60);
    if ( (g->index & 1) != 0 && stage->rotation.allowRotDirOverride )
      v64 = (float)((float)v59 - (float)((float)v63 * g->particleLife));
    else
      v64 = (float)((float)((float)v63 * g->particleLife) + (float)v59);
    type = stage->orientation.type;
    v66 = (float)(idMath::M_DEG2RAD * (float)v64);
    if ( type != POR_VIEW )
    {
      switch ( type )
      {
        case POR_Z:
          idMath::SinCos16(a: v66, s: v62, c: &v127.x, a4: &v128.x);
          x = v128.x;
          v53 = v127.x;
          z = 0.0;
          v58 = 0.0;
          v55 = v128.x;
          y = -v127.x;
          break;
        case POR_X:
          idMath::SinCos16(a: v66, s: v62, c: &v127.x, a4: &v128.x);
          x = v128.x;
          z = v127.x;
          v53 = 0.0;
          v55 = 0.0;
          v58 = v128.x;
          y = -v127.x;
          break;
        case POR_Y:
          idMath::SinCos16(a: v66, s: v62, c: &v127.x, a4: &v128.x);
          v53 = v128.x;
          z = v127.x;
          x = 0.0;
          y = 0.0;
          v58 = v128.x;
          v55 = -v127.x;
          break;
        default:
          z = v128.z;
          x = v128.y;
          v53 = v128.x;
          v58 = v128.z;
          y = v128.y;
          v55 = v128.x;
          break;
      }
    }
    else
    {
      idMath::SinCos16(a: v66, s: v62, c: &v128.x, a4: &v127.x);
      v53 = (float)((float)(inputs->localViewLeft.x * v127.x) + (float)(inputs->localViewUp.x * v128.x));
      v55 = (float)((float)(inputs->localViewUp.x * v127.x) - (float)(inputs->localViewLeft.x * v128.x));
      y = (float)((float)(inputs->localViewUp.y * v127.x) - (float)(inputs->localViewLeft.y * v128.x));
      v58 = (float)((float)(inputs->localViewUp.z * v127.x) - (float)(inputs->localViewLeft.z * v128.x));
      z = (float)((float)(inputs->localViewLeft.z * v127.x) + (float)(inputs->localViewUp.z * v128.x));
      x = (float)((float)(inputs->localViewLeft.y * v127.x) + (float)(inputs->localViewUp.y * v128.x));
    }
  }
  v67 = (float)((float)((float)v53 * inputs->globalAxis.mat[0].y) + (float)((float)x * inputs->globalAxis.mat[1].y));
  v68 = (float)((float)((float)v55 * inputs->globalAxis.mat[0].y) + (float)((float)y * inputs->globalAxis.mat[1].y));
  v69 = (float)((float)((float)v53 * inputs->globalAxis.mat[0].z) + (float)((float)x * inputs->globalAxis.mat[1].z));
  v72 = (float)((float)((float)z * inputs->globalAxis.mat[2].x)
              + (float)((float)((float)v53 * inputs->globalAxis.mat[0].x)
                      + (float)((float)x * inputs->globalAxis.mat[1].x)));
  v70 = (float)((float)((float)v55 * inputs->globalAxis.mat[0].z) + (float)((float)y * inputs->globalAxis.mat[1].z));
  v73 = (float)((float)((float)v58 * inputs->globalAxis.mat[2].x)
              + (float)((float)((float)v55 * inputs->globalAxis.mat[0].x)
                      + (float)((float)y * inputs->globalAxis.mat[1].x)));
  v71 = (float)((float)((float)z * inputs->globalAxis.mat[2].y) + (float)v67);
  v74 = (float)((float)((float)v58 * inputs->globalAxis.mat[2].y) + (float)v68);
  v76 = (float)((float)((float)v58 * inputs->globalAxis.mat[2].z) + (float)v70);
  v77 = v71;
  v75 = (float)((float)((float)z * inputs->globalAxis.mat[2].z) + (float)v69);
  if ( stage->orientation.world )
  {
    v78 = (float)((float)(v132 * (float)v75) + (float)(v131 * (float)v71));
    v79 = (float)((float)(v135 * (float)v76) + (float)(v134 * (float)v74));
    v81 = (float)((float)(v130 * (float)v73) + (float)((float)(v132 * (float)v76) + (float)(v131 * (float)v74)));
    v80 = (float)((float)(v138 * (float)v76) + (float)(v137 * (float)v74));
    v74 = (float)((float)(v133 * (float)v73) + (float)v79);
    v76 = (float)((float)(v136 * (float)v73) + (float)v80);
    v77 = (float)((float)(v133 * (float)v72) + (float)((float)(v135 * (float)v75) + (float)(v134 * (float)v71)));
    v75 = (float)((float)(v136 * (float)v72) + (float)((float)(v138 * (float)v75) + (float)(v137 * (float)v71)));
    v73 = v81;
    v72 = (float)((float)(v130 * (float)v72) + (float)v78);
  }
  v82 = (float)((float)v77 * (float)v21);
  v83 = (float)((float)v72 * (float)v21);
  v84 = (float)((float)v73 * (float)v26);
  v85 = (float)((float)v74 * (float)v26);
  v86 = (float)((float)v75 * (float)v21);
  p_y = &origin->y;
  p_z = &origin->z;
  v90 = (float)((float)((float)v74 * (float)v26) * stage->pivot.pivotOffset.y);
  v91 = (float)((float)(stage->pivot.pivotOffset.x * (float)v83)
              + (float)(stage->pivot.pivotOffset.y * (float)((float)v73 * (float)v26)));
  v92 = (float)((float)(origin->y - (float)v82) + (float)((float)v74 * (float)v26));
  v87 = (float)((float)v76 * (float)v26);
  v93 = (float)((float)(origin->z - (float)v86) + (float)v87);
  v94 = (float)((float)((float)v82 * stage->pivot.pivotOffset.x) + (float)v90);
  v95 = (float)((float)((float)v86 * stage->pivot.pivotOffset.x) + (float)((float)v87 * stage->pivot.pivotOffset.y));
  verts->xyz.x = (float)((float)(origin->x - (float)v83) + (float)v84)
               + (float)((float)(stage->pivot.pivotOffset.x * (float)v83)
                       + (float)(stage->pivot.pivotOffset.y * (float)v84));
  verts->xyz.y = (float)v92 + (float)v94;
  verts->xyz.z = (float)v93 + (float)v95;
  v96 = (float)((float)((float)v86 + origin->z) + (float)v87);
  v97 = (float)((float)((float)v82 + origin->y) + (float)v85);
  verts[1].xyz.x = (float)((float)((float)v83 + origin->x) + (float)v84) + (float)v91;
  verts[1].xyz.z = (float)v96 + (float)v95;
  verts[1].xyz.y = (float)v97 + (float)v94;
  v98 = (float)((float)(origin->y - (float)v82) - (float)v85);
  v99 = (float)((float)(origin->z - (float)v86) - (float)v87);
  verts[2].xyz.x = (float)((float)(origin->x - (float)v83) - (float)v84) + (float)v91;
  verts[2].xyz.y = (float)v98 + (float)v94;
  verts[2].xyz.z = (float)v99 + (float)v95;
  v100 = (float)((float)((float)v86 + origin->z) - (float)v87);
  v101 = (float)((float)((float)v82 + origin->y) - (float)v85);
  verts[3].xyz.x = (float)((float)((float)v83 + origin->x) - (float)v84) + (float)v91;
  verts[3].xyz.z = (float)v100 + (float)v95;
  verts[3].xyz.y = (float)v101 + (float)v94;
  if ( stage->orientation.type != POR_VIEW && stage->orientation.viewFade < 1.0 )
  {
    v102 = (float)((float)v95 + *p_z);
    v103 = inputs->localViewOrg.z;
    v104 = (float)((float)((float)v94 + *p_y) - inputs->localViewOrg.y);
    v128.x = (float)((float)v91 + origin->x) - inputs->localViewOrg.x;
    v128.y = v104;
    v128.z = (float)v102 - (float)v103;
    idVec3::NormalizeFast(this: &v128);
    v127.x = (float)((float)v87 * (float)v82) - (float)((float)v85 * (float)v86);
    v127.y = (float)((float)v86 * (float)v84) - (float)((float)v87 * (float)v83);
    v127.z = (float)((float)v85 * (float)v83) - (float)((float)v82 * (float)v84);
    idVec3::NormalizeFast(this: &v127);
    _R6 = &v128;
    _R11 = &verts->color[2];
    v108 = 4;
    _R9 = -2;
    _R8 = -1;
    v111 = g->vertColor.y;
    _R10 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
    v113 = g->vertColor.z;
    w = g->vertColor.w;
    _FP7 = (float)((float)((float)1.0
                         - (float)__fabs((float)((float)(v127.x * v128.x)
                                               + (float)((float)(v127.z * v128.z) + (float)(v127.y * v128.y)))))
                 - stage->orientation.viewFade);
    __asm { fsel      f6, f7, f7, f25 }
    v117 = (float)((float)1.0 - (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    v118 = (float)((float)(inputs->entityColor.y * stage->colorAttributes.fadeColor.y)
                 * (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    v119 = (float)((float)(inputs->entityColor.z * stage->colorAttributes.fadeColor.z)
                 * (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    v120 = (float)((float)(inputs->entityColor.w * stage->colorAttributes.fadeColor.w)
                 * (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    v128.x = (float)(g->vertColor.x
                   * (float)((float)1.0 - (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade))))
           + (float)((float)(stage->colorAttributes.fadeColor.x * inputs->entityColor.x)
                   * (float)((float)_FP6 / (float)((float)1.0 - stage->orientation.viewFade)));
    v128.y = (float)((float)v111 * (float)v117) + (float)v118;
    v128.z = (float)((float)v113 * (float)v117) + (float)v119;
    v129 = (float)((float)w * (float)v117) + (float)v120;
    __asm { lvx128    v62, r0, r6 }
    _R7 = 1;
    do
    {
      __asm
      {
        lvx128    v63, r0, r10
        vmulfp128 v63, v94, v63
        vcfpsxws128 v61, v63, 0
        vpkswss128 v60, v93, v61
        vpkshus128 v0, v92, v60
        stvebx    v0, r11, r9
        stvebx    v0, r11, r8
        stvebx    v0, 0, r11
        stvebx    v0, r11, r7
      }
      _R11 += 32;
      --v108;
    }
    while ( v108 != 0 );
  }
  result = 4;
  if ( quadDepth != nullptr )
    *quadDepth = (float)(view->viewFwd.x * (float)(origin->x - view->viewOrg.x))
               + (float)((float)(view->viewFwd.z * (float)(*p_z - view->viewOrg.z))
                       + (float)(view->viewFwd.y * (float)(*p_y - view->viewOrg.y)));
  return result;
}


// ========================================================================
// CreateParticle
// EA  : 0x827E8B18
// RVA : 0x007E8B18
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall CreateParticle(const particleInput_t *inputs, idRandom2 *g, idRandom2 *outputs, int a4, __int64 a5)
{
  const idParticleStage *stage; // r31
  idRandom2 *tables; // r27
  __int64 v11; // r9 OVERLAPPED
  idRandom2 *v12; // r5
  double v13; // fp30
  double fadeIndexFraction; // fp0
  double shadow; // fp28
  double minShadowVal; // fp27
  float *p_seed; // r29
  double v18; // fp1
  float y; // r10
  __int64 v21; // r8
  double entityColorBlendVal; // fp13
  char v23; // r6
  double v25; // fp28
  double v26; // fp21
  double v27; // fp22
  double v28; // fp23
  double v29; // fp20
  double fade; // fp27
  double v31; // fp26
  double v32; // fp25
  double v33; // fp24
  double v34; // fp19
  __int64 v35; // r8
  idRandom2 *v36; // r5
  double v37; // fp18
  __int64 v38; // r8
  idRandom2 *v39; // r5
  double v40; // fp17
  __int64 v41; // r8
  idRandom2 *v42; // r5
  idRandom2 *v43; // r5
  double v45; // fp1
  double v51; // fp12
  double v52; // fp10
  double v53; // fp9
  int v54; // r23
  unsigned __int8 v55; // r22
  unsigned __int8 v56; // r21
  unsigned __int8 v57; // r20
  __int64 v63; // r8
  idRandom2 *v64; // r5
  __int64 v65; // r8
  idRandom2 *v66; // r5
  __int64 v67; // r8
  idRandom2 *v68; // r5
  long double v69; // fp2
  double alphaScaleOverride; // fp0
  __int64 v77; // r8
  unsigned __int8 v78; // r9
  int v79; // r22
  unsigned __int16 v80; // r11
  prtOrientationType_t type; // r11
  _QWORD v82[2]; // [sp+50h] [-130h] BYREF
  float x; // [sp+60h] [-120h] BYREF
  int v84; // [sp+64h] [-11Ch]
  float v85; // [sp+68h] [-118h]
  unsigned int v86; // [sp+6Ch] [-114h]
  idVec3 v87; // [sp+70h] [-110h] BYREF
  idVec3 v88[12]; // [sp+80h] [-100h] BYREF

  stage = inputs->stage;
  tables = (idRandom2 *)inputs->tables;
  _R30 = (idTransparencyVert *)outputs->seed;
  ParticleOrigin(result: v88, inputs, g, origin: &v87, a5);
  v13 = 1.0;
  if ( *(float *)&g[4].seed < (double)stage->colorAttributes.fadeInFraction )
    v13 = (float)(*(float *)&g[4].seed / stage->colorAttributes.fadeInFraction);
  if ( (float)((float)1.0 - *(float *)&g[4].seed) < (double)stage->colorAttributes.fadeOutFraction )
    v13 = (float)((float)((float)((float)1.0 - *(float *)&g[4].seed) / stage->colorAttributes.fadeOutFraction)
                * (float)v13);
  fadeIndexFraction = stage->colorAttributes.fadeIndexFraction;
  if ( fadeIndexFraction != 0.0 )
  {
    LODWORD(v11) = (idRandom2)g->seed;
    HIDWORD(v11) = inputs->totalParticles;
    v82[0] = *(__int64 *)((char *)&v11 + 4);
    if ( (float)((float)((float)*(__int64 *)((char *)&v11 + 4) - (float)v11) / (float)*(__int64 *)((char *)&v11 + 4)) < fadeIndexFraction )
      v13 = (float)((float)((float)((float)((float)*(__int64 *)((char *)&v11 + 4) - (float)v11)
                                  / (float)*(__int64 *)((char *)&v11 + 4))
                          / (float)fadeIndexFraction)
                  * (float)v13);
  }
  shadow = inputs->shadow;
  minShadowVal = stage->colorAttributes.minShadowVal;
  p_seed = (float *)&g[5].seed;
  v18 = idParticleParm::Compute(
          this: &stage->colorAttributes.brightness,
          tables,
          frac: *(float *)&g[5].seed,
          rand: v12,
          a5: g + 6,
          a6: *(__int64 *)((char *)&v11 + 4));
  y = inputs->entityColor.y;
  LODWORD(v21) = LODWORD(inputs->entityColor.z);
  _FP0 = (float)((float)minShadowVal - (float)shadow);
  *(float *)&v21 = inputs->entityColor.w;
  entityColorBlendVal = stage->colorAttributes.entityColorBlendVal;
  v23 = *((_BYTE *)stage + 68);
  x = inputs->entityColor.x;
  *(float *)&v84 = y;
  v86 = HIDWORD(v21);
  v85 = *((float *)&v21 + 1);
  __asm { fsel      f4, f0, f27, f28 }
  v25 = (float)((float)v18 * (float)_FP4);
  v26 = (float)((float)((float)(*((float *)&v21 + 1) - (float)1.0) * (float)entityColorBlendVal) + (float)1.0);
  v27 = (float)((float)((float)(y - (float)1.0) * (float)entityColorBlendVal) + (float)1.0);
  v28 = (float)((float)((float)(x - (float)1.0) * (float)entityColorBlendVal) + (float)1.0);
  v29 = (float)((float)((float)(*(float *)&v21 - (float)1.0) * (float)entityColorBlendVal) + (float)1.0);
  if ( v23 < 0 )
  {
    fade = inputs->fade;
    v31 = 1.0;
    v32 = 1.0;
    v33 = 1.0;
  }
  else
  {
    v31 = inputs->fade;
    fade = 1.0;
    v32 = v31;
    v33 = v31;
  }
  v34 = idParticleParm::Compute(
          this: stage->colorAttributes.baseColor,
          tables,
          frac: *p_seed,
          rand: (idRandom2 *)(v23 & 0x80),
          a5: g + 6,
          a6: v21);
  v37 = idParticleParm::Compute(
          this: &stage->colorAttributes.baseColor[1],
          tables,
          frac: *p_seed,
          rand: v36,
          a5: g + 6,
          a6: v35);
  v40 = idParticleParm::Compute(
          this: &stage->colorAttributes.baseColor[2],
          tables,
          frac: *p_seed,
          rand: v39,
          a5: g + 6,
          a6: v38);
  v45 = idParticleParm::Compute(
          this: &stage->colorAttributes.baseColor[3],
          tables,
          frac: *p_seed,
          rand: v42,
          a5: g + 6,
          a6: v41);
  _R10 = &x;
  _R24 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
  _R9 = v82;
  LODWORD(_R8) = (char *)v82 + 1;
  HIDWORD(_R8) = (char *)v82 + 2;
  _R6 = (char *)v82 + 3;
  v51 = (float)((float)((float)((float)(stage->colorAttributes.fadeColor.x * (float)((float)1.0 - (float)v13))
                              + (float)((float)v34 * (float)v13))
                      * (float)v28)
              * (float)v31);
  v52 = (float)((float)((float)((float)(stage->colorAttributes.fadeColor.y * (float)((float)1.0 - (float)v13))
                              + (float)((float)v37 * (float)v13))
                      * (float)v32)
              * (float)v27);
  v53 = (float)((float)((float)((float)(stage->colorAttributes.fadeColor.z * (float)((float)1.0 - (float)v13))
                              + (float)((float)v40 * (float)v13))
                      * (float)v33)
              * (float)v26);
  *(float *)&v86 = (float)((float)((float)(stage->colorAttributes.fadeColor.w * (float)((float)1.0 - (float)v13))
                                 + (float)((float)v45 * (float)v13))
                         * (float)fade)
                 * (float)v29;
  g[11].seed = v86;
  x = (float)v51 * (float)v25;
  *(float *)&v84 = (float)v52 * (float)v25;
  v85 = (float)v53 * (float)v25;
  *(float *)&g[8].seed = x;
  *(float *)&g[9].seed = (float)v52 * (float)v25;
  *(float *)&g[10].seed = (float)v53 * (float)v25;
  __asm
  {
    lvx128    v63, r0, r24
    lvx128    v62, r0, r10
    vmulfp128 v61, v94, v63
    vcfpsxws128 v60, v61, 0
    vpkswss128 v59, v92, v60
    vpkshus128 v0, v91, v59
    stvebx    v0, 0, r9
    stvebx    v0, 0, r8
    stvebx    v0, 0, r7
    stvebx    v0, 0, r6
  }
  v54 = HIBYTE(v82[0]);
  v55 = BYTE3(v82[0]);
  v56 = BYTE2(v82[0]);
  v57 = BYTE1(v82[0]);
  if ( HIBYTE(v82[0]) == 0 && *(_WORD *)((char *)v82 + 1) == 0 && BYTE3(v82[0]) == 0 )
    return 0;
  __asm { vspltisw128 v58, 0 }
  LODWORD(_R8) = 16;
  __asm { vor128    v57, v90, v58 }
  _R9 = 16;
  __asm { vor128    v56, v90, v58 }
  __asm { vor128    v55, v90, v58 }
  __asm
  {
    vcmpequw128 v51, v90, v58
    vcmpequw128 v54, v89, v57
    stvx128   v57, r0, r30
    vcmpequw128 v53, v88, v56
    vcmpequw128 v52, v87, v55
    vsldoi128 v47, v90, v51, 4
    vsldoi128 v50, v89, v54, 4
    vsldoi128 v49, v88, v53, 4
    vsldoi128 v48, v87, v52, 4
    stvx128   v50, r30, r11
  }
  _R11 = _R30 + 1;
  __asm
  {
    stvx128   v56, r0, r11
    stvx128   v49, r11, r8
  }
  _R11 = _R30 + 2;
  __asm
  {
    stvx128   v55, r0, r11
    stvx128   v48, r11, r8
  }
  _R11 = _R30 + 3;
  __asm
  {
    stvx128   v58, r0, r11
    stvx128   v47, r11, r8
  }
  x = idParticleParm::Compute(
        this: stage->genericParm.genericParm,
        tables,
        frac: *p_seed,
        rand: v43,
        a5: g + 6,
        a6: _R8);
  *(float *)&v84 = idParticleParm::Compute(
                     this: &stage->genericParm.genericParm[1],
                     tables,
                     frac: *p_seed,
                     rand: v64,
                     a5: g + 6,
                     a6: v63);
  v85 = idParticleParm::Compute(
          this: &stage->genericParm.genericParm[2],
          tables,
          frac: *p_seed,
          rand: v66,
          a5: g + 6,
          a6: v65);
  *(double *)&v69 = idParticleParm::Compute(
                      this: &stage->genericParm.genericParm[3],
                      tables,
                      frac: *p_seed,
                      rand: v68,
                      a5: g + 6,
                      a6: v67);
  _R7 = &x;
  __asm { lvx128    v63, r0, r24 }
  _R6 = v82;
  *(float *)&v86 = *(double *)&v69;
  _R5 = (char *)v82 + 1;
  _R4 = (char *)v82 + 2;
  _R3 = (char *)v82 + 3;
  __asm
  {
    lvx128    v46, r0, r7
    vmulfp128 v45, v78, v63
    vcfpsxws128 v44, v45, 0
    vpkswss128 v43, v76, v44
    vpkshus128 v0, v75, v43
    stvebx    v0, 0, r6
    stvebx    v0, 0, r5
    stvebx    v0, 0, r4
    stvebx    v0, 0, r3
  }
  alphaScaleOverride = inputs->alphaScaleOverride;
  if ( alphaScaleOverride >= 1.0 )
    alphaScaleOverride = stage->colorAttributes.softParticleAlphaScale;
  v84 = (int)(float)((float)alphaScaleOverride * (float)255.0);
  if ( v84 >= 0 )
  {
    HIDWORD(v77) = 255;
    if ( v84 <= 255 )
      HIDWORD(v77) = (unsigned __int8)v84;
  }
  else
  {
    HIDWORD(v77) = 0;
  }
  _R30->tangent[3] = BYTE3(v77);
  _R30[1].tangent[3] = BYTE3(v77);
  v78 = BYTE2(v82[0]);
  v79 = (((((v54 << 8) | v57) << 8) | v56) << 8) | v55;
  v80 = _byteswap_ushort(HIWORD(v82[0]));
  LOBYTE(v77) = BYTE3(v82[0]);
  _R30[2].tangent[3] = BYTE3(v77);
  _R30[3].tangent[3] = BYTE3(v77);
  *(_DWORD *)_R30->color = v79;
  *(_DWORD *)_R30[1].color = v79;
  *(_DWORD *)_R30[2].color = v79;
  LODWORD(v77) = (((v80 << 8) | v78) << 8) | (unsigned __int8)v77;
  *(_DWORD *)_R30[3].color = v79;
  *(_DWORD *)_R30->normal = v77;
  *(_DWORD *)_R30[1].normal = v77;
  *(_DWORD *)_R30[3].normal = v77;
  *(_DWORD *)_R30[2].normal = v77;
  if ( stage->staticData != nullptr )
  {
    LODWORD(v77) = v82;
    return GenerateStaticMeshVerts(inputs, (particleGen_t *)g, outputs, origin: &v87, genericParm: v77, a6: v69);
  }
  else
  {
    type = stage->orientation.type;
    if ( type == POR_TRAIL )
    {
      return GenerateTrailVerts(inputs, g, outputs, origin: &v87, a5: v77);
    }
    else if ( type == POR_AIMED )
    {
      HIDWORD(v77) = v88;
      return GenerateAimedVerts(inputs, (particleGen_t *)g, outputs, origin: &v87, vel: v77);
    }
    else
    {
      return GenerateQuadVerts(inputs, (particleGen_t *)g, (particleOutput_t *)outputs, origin: &v87, a5: v69);
    }
  }
}


// ========================================================================
// ?GenParticleStage@@YAHPBUdeferredParticleGenParms_t@@HH@Z
// EA  : 0x827E9060
// RVA : 0x007E9060
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall GenParticleStage(const deferredParticleGenParms_t *parms, int index, int vertOffset)
{
  const modelParticleParms_t *modelParticleParms; // r10
  idParticleStage *stage; // r28
  int v6; // r25
  const idLookupTable *tables; // r27
  const modelParticleParms_t *v8; // r26
  float y; // r9
  float z; // r8
  float w; // r7
  __int64 v12; // r4 OVERLAPPED
  double v13; // fp3
  double v14; // fp2
  double v15; // fp1
  double v16; // fp13
  float *p_axis; // r31
  double v18; // fp11
  double x; // fp12
  double v20; // fp31
  double v21; // fp0
  double v22; // fp26
  double v23; // fp27
  double v24; // fp28
  double v25; // fp30
  __int16 totalParticles; // r11
  __int16 v27; // r10
  int v28; // r5
  const particleRenderView_t *renderView; // r8
  const idDrawVert *staticVerts; // r6
  double v31; // fp5
  double v32; // fp4
  double v33; // fp3
  signed int v34; // r27
  __int64 v35; // r10
  int v36; // r7
  int v37; // r6
  __int64 v38; // r9
  float *v39; // r3
  int v40; // r10
  double v41; // fp5
  double v42; // fp4
  const particleRenderView_t *v43; // r11
  double v44; // fp3
  double v45; // fp2
  double v46; // fp1
  double v47; // fp0
  double v48; // fp13
  double v49; // fp12
  double v50; // fp11
  double v51; // fp10
  double v52; // fp25
  double v53; // fp9
  double v54; // fp6
  double v55; // fp4
  double v56; // fp13
  double v57; // fp24
  double v58; // fp8
  double v59; // fp3
  double v60; // fp1
  double v61; // fp5
  double v62; // fp19
  double v63; // fp23
  double v64; // fp10
  double v65; // fp12
  double v66; // fp7
  double v67; // fp25
  double v68; // fp18
  double v69; // fp21
  double v70; // fp16
  double v71; // fp2
  double v72; // fp11
  double v73; // fp22
  double v74; // fp3
  double v75; // fp8
  double v76; // fp24
  double v77; // fp13
  double v78; // fp4
  double v79; // fp23
  double v80; // fp20
  double v81; // fp11
  double v82; // fp17
  double v83; // fp5
  double v84; // fp13
  double v85; // fp12
  double v86; // fp19
  double v87; // fp10
  double v88; // fp18
  double v89; // fp5
  double v90; // fp6
  double v91; // fp7
  double v92; // fp12
  double v93; // fp2
  double v94; // fp0
  double v95; // fp9
  double v96; // fp3
  double v97; // fp13
  double v98; // fp4
  double v99; // fp21
  double v100; // fp10
  double v101; // fp20
  double v102; // fp25
  double v103; // fp18
  double v104; // fp24
  double v105; // fp23
  double v106; // fp1
  double v107; // fp11
  double v108; // fp22
  double v109; // fp17
  double v110; // fp8
  double v111; // fp19
  double v112; // fp4
  double v113; // fp9
  double v114; // fp1
  double v115; // fp9
  double v116; // fp3
  double v117; // fp13
  BOOL useGlobalShadows; // r10
  double v119; // fp13
  double v120; // fp12
  double v121; // fp11
  double coverage; // fp10
  double alphaScaleOverride; // fp9
  double v124; // fp12
  double v125; // fp6
  double v126; // fp9
  double v127; // fp3
  int diversity; // r9
  prtSortType_t *p_sortType; // r3
  double v130; // fp11
  int v131; // r11
  prtSortType_t sortType; // r10
  int v133; // r8
  int v134; // r6
  signed int v135; // r23
  double v136; // fp6
  int v137; // r4
  double v138; // fp28
  int v139; // r19
  int v140; // r31
  int v141; // r7
  int v142; // r10
  int v143; // r11
  BOOL randomOnCycle; // r11
  int v145; // r15
  float v146; // r16
  bool v147; // cr56
  int v148; // r8
  int v149; // r5
  int v150; // r18
  unsigned int v151; // r17
  int v152; // r22
  unsigned int v153; // r21
  float v154; // r14
  prtSortType_t v155; // r11
  float v156; // r31
  unsigned int v157; // r7
  int v158; // ctr
  int v159; // r29
  __int16 cycles; // r9
  int v161; // r10
  int v162; // r30
  idRandom2 *v163; // r11
  __int64 v164; // r10
  double v165; // fp1
  double v166; // fp30
  __int64 v167; // r8
  int v168; // r6
  int v169; // r3
  double v170; // fp0
  double useSysTime; // fp13
  double v172; // fp0
  float *quadDepth; // r11
  int v174; // r31
  int v175; // r3
  int v178; // ctr
  float *v183; // r7
  int v184; // r6
  double v185; // fp0
  int v186; // r10
  double v187; // fp13
  int v188; // r11
  __int64 v189; // r11
  double v190; // fp0
  int v191; // ctr
  __int64 v193; // [sp+50h] [-12D0h] BYREF
  idRandom2 v194; // [sp+58h] [-12C8h] BYREF
  int v195; // [sp+5Ch] [-12C4h]
  prtSortType_t *v196; // [sp+60h] [-12C0h]
  __int64 v197; // [sp+68h] [-12B8h]
  int v198; // [sp+70h] [-12B0h]
  int v199; // [sp+78h] [-12A8h] BYREF
  int v200; // [sp+7Ch] [-12A4h]
  __int64 v201; // [sp+80h] [-12A0h]
  float *v202; // [sp+88h] [-1298h]
  idRandom2 **p_tables; // [sp+8Ch] [-1294h]
  unsigned __int64 v204; // [sp+90h] [-1290h]
  float v205; // [sp+98h] [-1288h]
  float v206; // [sp+9Ch] [-1284h]
  idAngles v207; // [sp+A0h] [-1280h] BYREF
  particleInput_t v208; // [sp+B0h] [-1270h] BYREF
  idVec3 v209; // [sp+1B0h] [-1170h] BYREF
  idMat3 v210; // [sp+1C0h] [-1160h] BYREF
  float v211; // [sp+1E4h] [-113Ch]
  float v212; // [sp+1E8h] [-1138h]
  float v213; // [sp+1ECh] [-1134h]
  unsigned __int64 v214; // [sp+1F0h] [-1130h]
  __int64 v215; // [sp+1F8h] [-1128h]
  _BYTE v216[288]; // [sp+200h] [-1120h] BYREF

  modelParticleParms = parms->modelParticleParms;
  stage = (idParticleStage *)parms->stage;
  p_tables = (idRandom2 **)&parms->tables;
  v6 = vertOffset;
  tables = parms->tables;
  v8 = &modelParticleParms[index];
  if ( v8 == nullptr
    || stage == nullptr
    || stage->systemProperties.material == nullptr
    || stage->cycleMsec == 0
    || (*((_BYTE *)stage + 68) & 8) != 0 )
  {
    return 0;
  }
  y = v8->wind.y;
  z = v8->wind.z;
  w = v8->wind.w;
  *(float *)&v204 = v8->wind.x;
  *((float *)&v204 + 1) = y;
  v205 = z;
  v206 = w;
  v209.z = z;
  v209.y = y;
  v209.x = *(float *)&v204;
  HIDWORD(v12) = idAngles::ToForward(this: &v207, result: &v209);
  LODWORD(v12) = v8->lod;
  v13 = (float)(v206 * *(float *)HIDWORD(v12));
  v14 = *(float *)(HIDWORD(v12) + 8);
  v15 = (float)(*(float *)(HIDWORD(v12) + 4) * v206);
  v193 = v12;
  v16 = v8->axis.mat[0].z;
  p_axis = (float *)&v8->axis;
  v18 = v8->axis.mat[0].y;
  x = v8->axis.mat[0].x;
  v20 = 0.0;
  v21 = (float)((float)v12 * stage->lodParms.lerpAmount);
  v22 = (float)((float)((float)((float)v14 * v206) * v8->axis.mat[2].z)
              + (float)((float)((float)v15 * v8->axis.mat[2].y) + (float)(v8->axis.mat[2].x * (float)v13)));
  v23 = (float)((float)((float)v13 * v8->axis.mat[1].x)
              + (float)((float)(v8->axis.mat[1].z * (float)((float)v14 * v206)) + (float)((float)v15 * v8->axis.mat[1].y)));
  v24 = (float)((float)(v8->axis.mat[0].x * (float)v13)
              + (float)((float)((float)v15 * v8->axis.mat[0].y) + (float)((float)((float)v14 * v206) * v8->axis.mat[0].z)));
  if ( v21 >= 0.0 )
  {
    if ( v21 <= 1.0 )
      v25 = (float)((float)v12 * stage->lodParms.lerpAmount);
    else
      v25 = 1.0;
  }
  else
  {
    v25 = 0.0;
  }
  totalParticles = stage->lodParms.totalParticles;
  v27 = stage->systemProperties.totalParticles;
  v208.localVelocity.x = v8->velocity.x;
  v28 = totalParticles;
  v193 = *(__int64 *)((char *)&v12 - 4);
  LODWORD(v12) = v27;
  v197 = v12;
  v208.modelAxis.mat[0].x = x;
  renderView = parms->renderView;
  staticVerts = parms->staticVerts;
  v208.modelAxis.mat[1].x = v8->axis.mat[1].x;
  v208.tables = tables;
  v208.modelAxis.mat[0].y = v18;
  v208.stage = stage;
  v208.modelAxis.mat[1].y = v8->axis.mat[1].y;
  v208.view = renderView;
  v208.modelAxis.mat[1].z = v8->axis.mat[1].z;
  v208.staticVerts = staticVerts;
  v208.modelAxis.mat[2].x = v8->axis.mat[2].x;
  v31 = v8->axis.mat[2].z;
  v32 = v8->velocity.y;
  v33 = v8->velocity.z;
  v208.modelAxis.mat[2].y = v8->axis.mat[2].y;
  v208.modelAxis.mat[2].z = v31;
  v208.localVelocity.y = v32;
  v208.localVelocity.z = v33;
  v208.modelAxis.mat[0].z = v16;
  LODWORD(v193) = (int)(float)((float)((float)((float)v193 - (float)v12) * (float)v25) + (float)v12);
  v34 = v193;
  v208.totalParticles = v193;
  idVec3::NormalizeFast(this: &v208.localVelocity);
  LODWORD(v35) = stage->systemProperties.diversity;
  v39 = (float *)ParticleStageAxis(result: &v210, stage, diversity: v35 + v8->diversity, a4: v37, a5: v36, a6: v35);
  v40 = *((_BYTE *)stage + 68) & 0x40;
  v41 = v39[1];
  v42 = v39[2];
  v43 = parms->renderView;
  v44 = v39[3];
  v45 = v39[4];
  v46 = v39[5];
  v47 = v39[6];
  v48 = v39[7];
  v49 = v39[8];
  v50 = v8->axis.mat[1].z;
  v51 = v8->axis.mat[2].z;
  v52 = v8->axis.mat[1].y;
  v208.stageAxis.mat[0].x = *v39;
  v208.stageAxis.mat[0].y = v41;
  v208.stageAxis.mat[0].z = v42;
  v208.stageAxis.mat[1].x = v44;
  v208.stageAxis.mat[1].y = v45;
  v208.stageAxis.mat[1].z = v46;
  v208.stageAxis.mat[2].x = v47;
  v208.stageAxis.mat[2].y = v48;
  v208.stageAxis.mat[2].z = v49;
  if ( v40 != 0 )
  {
    v53 = v43->viewLeft.z;
    v54 = v43->viewUp.z;
    v55 = v43->viewUp.y;
    v56 = (float)((float)v50 * v43->viewUp.z);
    v57 = v8->axis.mat[2].y;
    v58 = v43->viewLeft.y;
    v59 = (float)((float)v51 * v43->viewLeft.z);
    v60 = *p_axis;
    v61 = (float)(v43->viewLeft.y * v8->axis.mat[0].y);
    v62 = v8->axis.mat[2].x;
    v63 = v52;
    v65 = v43->viewLeft.x;
    v66 = (float)((float)((float)v52 * v43->viewLeft.y) + (float)((float)v50 * v43->viewLeft.z));
    v67 = v8->axis.mat[0].z;
    v68 = v8->axis.mat[1].x;
    v69 = v8->scale.x;
    v70 = v8->axis.mat[2].z;
    v71 = (float)((float)(v43->viewUp.x * v8->axis.mat[0].x) + (float)(v43->viewUp.y * v8->axis.mat[0].y));
    v72 = (float)((float)(v8->axis.mat[2].y * v43->viewUp.y) + (float)((float)v51 * v43->viewUp.z));
    v64 = v43->viewUp.x;
    v208.globalAxis.mat[0].y = v8->scale.x * v8->axis.mat[0].y;
    v73 = v8->axis.mat[2].x;
    v74 = (float)((float)((float)v57 * (float)v58) + (float)v59);
    v75 = v8->scale.y;
    v76 = v8->scale.z;
    v77 = (float)((float)((float)v63 * (float)v55) + (float)v56);
    v78 = v8->axis.mat[1].y;
    v79 = (float)(v8->scale.y * v8->axis.mat[1].x);
    v208.globalAxis.mat[0].x = (float)v69 * (float)v60;
    v80 = v8->axis.mat[2].y;
    v208.localViewLeft.y = (float)((float)v68 * (float)v65) + (float)v66;
    v208.globalAxis.mat[1].x = v79;
    v81 = (float)((float)((float)v64 * (float)v62) + (float)v72);
    v82 = v8->axis.mat[1].z;
    v208.globalOrigin.z = v8->origin.z;
    v208.localViewLeft.z = (float)((float)v65 * (float)v62) + (float)v74;
    v83 = (float)((float)((float)v53 * (float)v67) + (float)((float)((float)v65 * (float)v60) + (float)v61));
    v84 = (float)((float)((float)v64 * (float)v68) + (float)v77);
    v85 = v8->origin.y;
    v86 = v43->viewOrg.x;
    v87 = v43->viewOrg.y;
    v88 = v43->viewOrg.z;
    v208.globalOrigin.x = v8->origin.x;
    v208.localViewUp.x = (float)((float)v54 * (float)v67) + (float)v71;
    v208.globalOrigin.y = v85;
    v208.localViewUp.y = v84;
    v208.localViewOrg.x = v86;
    v208.localViewUp.z = v81;
    v208.localViewOrg.y = v87;
    v208.localViewOrg.z = v88;
    v208.globalAxis.mat[2].x = (float)v76 * (float)v73;
    v208.globalAxis.mat[1].y = (float)v75 * (float)v78;
    v208.globalAxis.mat[2].y = (float)v76 * (float)v80;
    v208.globalAxis.mat[0].z = (float)v69 * (float)v67;
    v208.globalAxis.mat[1].z = (float)v75 * (float)v82;
    v208.globalAxis.mat[2].z = (float)v76 * (float)v70;
  }
  else
  {
    v89 = v43->viewLeft.z;
    v90 = (float)(v43->viewOrg.z - v8->origin.z);
    v91 = (float)(v43->viewOrg.y - v8->origin.y);
    v92 = v8->axis.mat[0].y;
    v93 = v43->viewUp.z;
    v94 = v43->viewUp.y;
    v95 = (float)(v8->axis.mat[2].z * v43->viewUp.z);
    v96 = (float)((float)(v8->axis.mat[1].y * v43->viewLeft.y) + (float)((float)v50 * v43->viewLeft.z));
    v97 = (float)((float)(v8->axis.mat[2].y * v43->viewLeft.y) + (float)((float)v51 * v43->viewLeft.z));
    v98 = v8->axis.mat[2].y;
    v99 = v43->viewLeft.x;
    v100 = (float)(v43->viewUp.y * v8->axis.mat[0].y);
    v101 = v43->viewUp.x;
    v102 = (float)((float)(v43->viewOrg.y - v8->origin.y) * (float)v52);
    v103 = v8->axis.mat[1].z;
    v104 = (float)(v43->viewOrg.x - v8->origin.x);
    v105 = *p_axis;
    v106 = (float)((float)(v43->viewLeft.x * v8->axis.mat[0].x) + (float)(v43->viewLeft.y * v8->axis.mat[0].y));
    v107 = v8->axis.mat[0].z;
    v108 = (float)((float)(v43->viewOrg.z - v8->origin.z) * v8->axis.mat[0].z);
    v109 = v98;
    v110 = (float)((float)(v8->axis.mat[1].y * v43->viewUp.y) + (float)(v8->axis.mat[1].z * v43->viewUp.z));
    v111 = v8->axis.mat[2].x;
    v208.globalOrigin.z = 0.0;
    v208.globalOrigin.y = 0.0;
    v208.globalOrigin.x = 0.0;
    v112 = (float)((float)((float)v98 * (float)v94) + (float)v95);
    v113 = v8->axis.mat[1].x;
    v208.globalAxis.mat[2].z = 1.0;
    v208.globalAxis.mat[1].y = 1.0;
    v208.globalAxis.mat[0].x = 1.0;
    v83 = (float)((float)((float)v89 * (float)v107) + (float)v106);
    v208.globalAxis.mat[1].z = 0.0;
    v114 = v113;
    v208.globalAxis.mat[0].z = 0.0;
    v208.globalAxis.mat[0].y = 0.0;
    v208.globalAxis.mat[2].y = 0.0;
    v115 = (float)((float)((float)v99 * (float)v113) + (float)v96);
    v208.globalAxis.mat[2].x = 0.0;
    v116 = (float)((float)((float)v99 * (float)v111) + (float)v97);
    v117 = v8->axis.mat[2].z;
    v208.globalAxis.mat[1].x = 0.0;
    v208.localViewLeft.y = v115;
    v208.localViewLeft.z = v116;
    v208.localViewUp.x = (float)((float)v93 * (float)v107) + (float)((float)((float)v101 * (float)v105) + (float)v100);
    v208.localViewUp.y = (float)((float)v101 * (float)v114) + (float)v110;
    v208.localViewUp.z = (float)((float)v101 * (float)v111) + (float)v112;
    v208.localViewOrg.y = (float)((float)v104 * (float)v114) + (float)((float)((float)v103 * (float)v90) + (float)v102);
    v208.localViewOrg.x = (float)((float)v105 * (float)v104) + (float)((float)((float)v91 * (float)v92) + (float)v108);
    v208.localViewOrg.z = (float)((float)v90 * (float)v117)
                        + (float)((float)((float)v91 * (float)v109) + (float)((float)v111 * (float)v104));
  }
  useGlobalShadows = stage->colorAttributes.useGlobalShadows;
  v119 = v8->color.y;
  v120 = v8->color.z;
  v121 = v8->color.w;
  coverage = v8->coverage;
  alphaScaleOverride = v8->alphaScaleOverride;
  v208.entityColor.x = v8->color.x;
  v208.localViewLeft.x = v83;
  v208.entityColor.y = v119;
  v208.entityColor.z = v120;
  v208.entityColor.w = v121;
  v208.fade = coverage;
  v208.alphaScaleOverride = alphaScaleOverride;
  if ( useGlobalShadows )
    v208.shadow = v8->shadow;
  else
    v208.shadow = 1.0;
  LODWORD(v38) = v43->renderTime;
  v124 = (float)(stage->maxParticleLife + parms->deadTime);
  v125 = (float)(stage->systemProperties.spawnBunching * stage->bunchTime);
  v201 = v38;
  v126 = (float)(stage->systemProperties.timeOffset + v8->timeOffset);
  v127 = (float)(stage->lodParms.sizeScale - (float)1.0);
  v208.wind.x = v24;
  diversity = stage->systemProperties.diversity;
  HIDWORD(v197) = &idMath::M_MS2SEC;
  p_sortType = &stage->systemProperties.sortType;
  v208.distribScale.x = v8->distribScale.x;
  v202 = (float *)&idMath::M_SEC2MS;
  v130 = (float)((float)v125 * (float)1000.0);
  v131 = v8->diversity;
  v208.distribScale.y = v8->distribScale.y;
  sortType = stage->systemProperties.sortType;
  v133 = 0;
  v208.distribScale.z = v8->distribScale.z;
  v208.wind.y = v23;
  v208.influenceSpheres = nullptr;
  v208.wind.z = v22;
  v208.numInfluenceSpheres = 0;
  v208.sizeScale = (float)((float)v127 * (float)v25) + (float)1.0;
  v196 = &stage->systemProperties.sortType;
  v134 = (diversity + v131) & 0x7FFF;
  v135 = (int)(float)((float)v124 * (float)1000.0);
  v136 = (double)v201;
  v137 = (int)v130;
  __twllei(v135, 0);
  v198 = (int)v130;
  v138 = (float)((float)v136 * (float)0.001);
  LODWORD(v193) = (int)(float)((float)((float)((float)v136 * (float)0.001) - (float)v126) * (float)1000.0);
  v139 = v193;
  v140 = (int)v193 / v135;
  HIDWORD(v201) = (int)v193 / v135;
  __twlgei(v135 & ~(__ROL4__(v193, 1) - 1), 0xFFFFFFFF);
  if ( sortType == PSORT_TYPE_NEWEST_TO_OLDEST || sortType == PSORT_TYPE_OLDEST_TO_NEWEST )
  {
    v141 = 1;
    if ( v34 > 1 )
    {
      v142 = (int)v130;
      while ( 1 )
      {
        v143 = v193 - v142 / v34;
        __twllei(v34, 0);
        __twlgei(v34 & ~(__ROL4__(v142, 1) - 1), 0xFFFFFFFF);
        if ( v143 >= 0 )
        {
          __twllei(v135, 0);
          __twlgei(v135 & ~(__ROL4__(v143, 1) - 1), 0xFFFFFFFF);
          if ( (int)v193 % v135 < v143 % v135 )
            break;
        }
        ++v141;
        v142 += v137;
        if ( v141 >= v34 )
          goto LABEL_26;
      }
      v133 = v141;
    }
  }
LABEL_26:
  randomOnCycle = stage->systemProperties.randomOnCycle;
  v145 = v133 + v34;
  v146 = *(float *)&v133;
  v195 = v6;
  v147 = v133 < v133 + v34;
  v148 = !randomOnCycle - 1;
  v149 = ((v148 & v140) << 10) & 0x7C00;
  v150 = v149 ^ v134;
  v151 = (((v148 & v140) - 1) << 10) & 0x7C00 ^ v134;
  v152 = v149 ^ v134;
  v153 = v151;
  if ( !v147 )
    goto LABEL_61;
  LODWORD(v154) = v145 - 1;
  while ( 1 )
  {
    v155 = *p_sortType;
    v156 = v146;
    if ( *p_sortType == PSORT_TYPE_NEWEST_TO_OLDEST )
      v156 = v154;
    if ( v155 == PSORT_TYPE_OLDEST_TO_NEWEST || v155 == PSORT_TYPE_NEWEST_TO_OLDEST )
    {
      v199 = v150;
      v194.seed = v151;
      v157 = v34 & ~(__ROL4__(LODWORD(v156), 1) - 1);
      __twllei(v34, 0);
      SLODWORD(v156) %= v34;
      v152 = v150;
      v153 = v151;
      __twlgei(v157, 0xFFFFFFFF);
      if ( v156 < 0.0 )
        goto LABEL_37;
      v158 = LODWORD(v156) + 1;
      do
      {
        v152 = 1664525 * v152 + 1013904223;
        v153 = 1664525 * v153 + 1013904223;
        --v158;
      }
      while ( v158 != 0 );
    }
    else
    {
      v152 = 1664525 * v152 + 1013904223;
      v153 = 1664525 * v153 + 1013904223;
    }
    v199 = v152;
    v194.seed = v153;
LABEL_37:
    __twllei(v34, 0);
    v159 = v139 - LODWORD(v156) * v137 / v34;
    __twlgei(v34 & ~(__ROL4__(LODWORD(v156) * v137, 1) - 1), 0xFFFFFFFF);
    if ( v159 >= 0 )
    {
      cycles = stage->systemProperties.cycles;
      v161 = v159 / v135;
      __twllei(v135, 0);
      __twlgei(v135 & ~(__ROL4__(v159, 1) - 1), 0xFFFFFFFF);
      if ( cycles == 0 || v161 < cycles )
      {
        v162 = v159 % v135;
        if ( v8->stopTime != 0 && parms->renderView->renderTime - v162 >= v8->stopTime )
          goto LABEL_57;
        v163 = (idRandom2 *)&v199;
        if ( v161 != HIDWORD(v201) )
          v163 = &v194;
        HIDWORD(v164) = (idRandom2)v163->seed;
        LODWORD(v164) = v34;
        v214 = __PAIR64__((unsigned int)p_tables, LODWORD(v156));
        v215 = v164;
        v194.seed = HIDWORD(v164);
        v165 = idParticleParm::Compute(
                 this: &stage->systemProperties.particleLife,
                 tables: *p_tables,
                 frac: (float)((float)__SPAIR64__((unsigned int)p_tables, LODWORD(v156)) / (float)v164),
                 rand: (idRandom2 *)v149,
                 a5: &v194,
                 a6: __SPAIR64__((unsigned int)p_tables, LODWORD(v156)));
        v166 = v165;
        if ( v162 >= 0 )
        {
          v200 = (int)(float)((float)v165 * *v202);
          if ( v162 <= v200 )
            break;
        }
LABEL_56:
        v137 = v198;
        p_sortType = v196;
      }
    }
LABEL_57:
    ++LODWORD(v146);
    --LODWORD(v154);
    if ( SLODWORD(v146) >= v145 )
      goto LABEL_60;
  }
  v169 = idParticleStage::NumVertsPerParticle(this: stage);
  if ( v169 + v195 <= parms->maxVertsToGen )
  {
    LODWORD(v167) = v159;
    *(_QWORD *)&v207.pitch = v167;
    v210.mat[1].x = v166;
    v204 = __PAIR64__(HIDWORD(v197), v162);
    v210.mat[0].x = v156;
    v170 = *(float *)HIDWORD(v197);
    useSysTime = stage->systemProperties.useSysTime;
    LODWORD(v210.mat[2].x) = (idRandom2)v194.seed;
    LODWORD(v210.mat[2].y) = (idRandom2)v194.seed;
    v210.mat[0].z = (float)v167 * (float)v170;
    v210.mat[0].y = (float)__SPAIR64__(HIDWORD(v197), v162) * (float)v170;
    v172 = (float)(v210.mat[0].y / (float)v166);
    v210.mat[1].y = v210.mat[0].y / (float)v166;
    if ( useSysTime != 0.0 )
      v172 = (float)((float)v138 * (float)useSysTime);
    quadDepth = parms->quadDepth;
    v174 = v195;
    v210.mat[1].z = v172;
    v210.mat[2].z = 1.0;
    HIDWORD(v193) = v216;
    v211 = 1.0;
    v212 = 1.0;
    v213 = 1.0;
    if ( quadDepth != nullptr )
    {
      LODWORD(v167) = &quadDepth[v195 / 4];
      LODWORD(v193) = v167;
    }
    else
    {
      LODWORD(v193) = 0;
    }
    v175 = CreateParticle(inputs: &v208, g: (idRandom2 *)&v210, outputs: (idRandom2 *)&v193, a4: v168, a5: v167);
    _R11 = &parms->verts[v174];
    if ( v175 > 0 )
    {
      v178 = v175;
      _R8 = 16;
      _R10 = (_BYTE *)(v216 - (_BYTE *)_R11);
      _R7 = 16;
      do
      {
        _R9 = &_R10[(_DWORD)_R11];
        __asm
        {
          lvx128    v63, r11, r10
          lvx128    v62, r9, r8
          stvx128   v63, r0, r11
          stvx128   v62, r11, r7
        }
        ++_R11;
        --v178;
      }
      while ( v178 != 0 );
    }
    v195 = v175 + v174;
    goto LABEL_56;
  }
  p_sortType = v196;
LABEL_60:
  v6 = vertOffset;
LABEL_61:
  v183 = parms->quadDepth;
  if ( v183 != nullptr && (*p_sortType == PSORT_TYPE_OLDEST_TO_NEWEST || *p_sortType == PSORT_TYPE_NEWEST_TO_OLDEST) )
  {
    v184 = (v195 - v6) / 4;
    if ( v184 > 0 )
    {
      v185 = 0.0;
      v186 = 0;
      v187 = 0.0;
      if ( v184 >= 2 )
      {
        v188 = 0;
        do
        {
          v186 += 2;
          v185 = (float)((float)v185 + v183[v188]);
          v187 = (float)(v183[v188 + 1] + (float)v187);
          v188 += 2;
        }
        while ( v186 < v184 - 1 );
      }
      if ( v186 < v184 )
        v20 = v183[v186];
      v189 = (unsigned int)v184;
      *(_QWORD *)&v207.pitch = (unsigned int)v184;
      v190 = (float)((float)((float)((float)v187 + (float)v185) + (float)v20) / (float)(unsigned int)v184);
      if ( v184 >= 4 )
      {
        LODWORD(v189) = 0;
        do
        {
          HIDWORD(v189) += 4;
          *(float *)((char *)parms->quadDepth + v189) = v190;
          *(float *)((char *)parms->quadDepth + v189 + 4) = v190;
          *(float *)((char *)parms->quadDepth + v189 + 8) = v190;
          *(float *)((char *)parms->quadDepth + v189 + 12) = v190;
          LODWORD(v189) = v189 + 16;
        }
        while ( SHIDWORD(v189) < v184 - 3 );
      }
      if ( SHIDWORD(v189) < v184 )
      {
        LODWORD(v189) = 4 * HIDWORD(v189);
        v191 = v184 - HIDWORD(v189);
        do
        {
          *(float *)((char *)parms->quadDepth + v189) = v190;
          LODWORD(v189) = v189 + 4;
          --v191;
        }
        while ( v191 != 0 );
      }
    }
  }
  return v195 - v6;
}


// ========================================================================
// ?GenEffectStage@@YAHPBUdeferredParticleGenParms_t@@HH@Z
// EA  : 0x827E9C10
// RVA : 0x007E9C10
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

int __fastcall GenEffectStage(const deferredParticleGenParms_t *parms, int index, int vertOffset)
{
  idParticleStage *stage; // r25
  int v5; // r28
  const effectParticleParms_t *v6; // r31
  double x; // fp0
  double y; // fp13
  __int64 v9; // r10
  double z; // fp12
  const idDrawVert *staticVerts; // r8
  int v12; // r5
  const idLookupTable *tables; // r6
  double v14; // fp31
  int totalParticles; // r7
  double v16; // fp30
  double v17; // fp29
  double v18; // fp28
  double v19; // fp27
  double v20; // fp25
  double v21; // fp26
  double v22; // fp24
  double v23; // fp23
  const idLookupTable **p_tables; // r21
  float *v25; // r3
  double v26; // fp4
  double v27; // fp13
  double v28; // fp3
  double v29; // fp12
  double v30; // fp11
  double v31; // fp10
  double v32; // fp9
  double v33; // fp8
  double v34; // fp6
  double v35; // fp7
  double v36; // fp2
  double v37; // fp1
  double v38; // fp0
  __int128 v39; // r5
  double v40; // fp9
  double v41; // fp8
  double v42; // fp10
  double v43; // fp13
  double v44; // fp31
  double v45; // fp3
  double v46; // fp1
  double v47; // fp0
  double v48; // fp11
  double v49; // fp6
  double v50; // fp12
  double v51; // fp5
  double v52; // fp9
  double v53; // fp8
  double v54; // fp2
  double v55; // fp7
  double v56; // fp4
  double v57; // fp10
  double v58; // fp29
  double v59; // fp26
  double v60; // fp25
  double v61; // fp27
  double v62; // fp11
  double v63; // fp12
  double v64; // fp9
  double spawnBunching; // fp0
  double v66; // fp2
  double v67; // fp4
  double v68; // fp31
  double v69; // fp30
  double v70; // fp10
  double v71; // fp4
  __int64 v72; // r11
  double v73; // fp3
  double v74; // fp23
  double v75; // fp22
  double v76; // fp29
  float v77; // r24
  int v78; // r17
  int v79; // r5
  float v80; // r29
  __int16 v81; // r9
  __int64 v82; // r8
  idRandom2 *v83; // r4
  double v84; // fp11
  int v85; // r26
  double v86; // fp1
  const particleRenderView_t *renderView; // r28
  double v88; // fp30
  int renderTime; // r27
  int v90; // r26
  __int64 v91; // r5
  __int64 v92; // r10
  double v93; // fp8
  __int64 v94; // r8
  double v95; // fp12
  double v96; // fp7
  double v97; // fp6
  float *quadDepth; // r11
  double v99; // fp0
  double v100; // fp2
  double v101; // fp13
  double v102; // fp1
  int v103; // r3
  int v106; // ctr
  float *v111; // r7
  int v112; // r6
  int v113; // r10
  double v114; // fp0
  double v115; // fp13
  double v116; // fp12
  int v117; // r11
  __int64 v118; // r11
  double v119; // fp0
  int v120; // ctr
  int v122; // [sp+50h] [-1270h]
  float v123; // [sp+54h] [-126Ch]
  __int64 v124; // [sp+58h] [-1268h] BYREF
  __int64 v125; // [sp+60h] [-1260h]
  idRandom2 v126; // [sp+68h] [-1258h] BYREF
  int v127; // [sp+6Ch] [-1254h]
  __int64 v128; // [sp+70h] [-1250h]
  __int64 v129; // [sp+78h] [-1248h]
  idMat3 v130; // [sp+80h] [-1240h] BYREF
  float v131; // [sp+A4h] [-121Ch]
  float v132; // [sp+A8h] [-1218h]
  float v133; // [sp+ACh] [-1214h]
  particleInput_t v134; // [sp+B0h] [-1210h] BYREF
  __int64 v135; // [sp+1B0h] [-1110h]
  __int64 v136; // [sp+1B8h] [-1108h]
  __int64 v137; // [sp+1C0h] [-1100h]
  _BYTE v138[240]; // [sp+1D0h] [-10F0h] BYREF

  stage = (idParticleStage *)parms->stage;
  v5 = vertOffset;
  v6 = &parms->effectParticleParms[index];
  if ( v6 == nullptr || stage == nullptr )
    return 0;
  x = v6->axis.mat[0].x;
  y = v6->axis.mat[0].y;
  HIDWORD(v9) = parms->renderView;
  z = v6->axis.mat[0].z;
  staticVerts = parms->staticVerts;
  v12 = stage->systemProperties.diversity + v6->diversity;
  tables = parms->tables;
  v14 = v6->axis.mat[1].x;
  totalParticles = (unsigned __int16)stage->systemProperties.totalParticles;
  v16 = v6->axis.mat[1].y;
  v17 = v6->axis.mat[1].z;
  LODWORD(v9) = (__int16)totalParticles;
  v18 = v6->axis.mat[2].x;
  v19 = v6->axis.mat[2].y;
  v20 = v6->axis.mat[2].z;
  v134.modelAxis.mat[1].x = v6->axis.mat[1].x;
  v134.modelAxis.mat[1].y = v16;
  v21 = x;
  v134.modelAxis.mat[1].z = v17;
  v22 = y;
  v134.modelAxis.mat[2].x = v18;
  v23 = z;
  v134.modelAxis.mat[2].y = v19;
  v134.modelAxis.mat[0].x = x;
  v134.modelAxis.mat[2].z = v20;
  v134.modelAxis.mat[0].y = y;
  v134.modelAxis.mat[0].z = z;
  v134.globalAxis.mat[1].x = v14;
  p_tables = &parms->tables;
  v134.globalAxis.mat[1].y = v16;
  v134.globalAxis.mat[1].z = v17;
  v134.tables = tables;
  v134.globalAxis.mat[2].x = v18;
  v134.globalAxis.mat[2].y = v19;
  v134.view = (const particleRenderView_t *)HIDWORD(v9);
  v134.globalAxis.mat[0].x = x;
  v134.globalAxis.mat[2].z = v20;
  v134.staticVerts = staticVerts;
  v134.globalAxis.mat[0].y = y;
  v134.stage = stage;
  v134.globalAxis.mat[0].z = z;
  v134.totalParticles = (__int16)totalParticles;
  v25 = (float *)ParticleStageAxis(result: &v130, stage, diversity: v12, a4: (int)tables, a5: totalParticles, a6: v9);
  v26 = v6->velocity.y;
  v27 = (float)(v6->velocity.z * (float)v20);
  v28 = v6->velocity.x;
  v29 = v25[1];
  v30 = v25[2];
  v31 = v25[3];
  v32 = (float)((float)(v6->velocity.z * (float)v23) + (float)(v6->velocity.y * (float)v22));
  v33 = v25[4];
  v34 = v25[5];
  v35 = (float)((float)(v6->velocity.x * (float)v14) + (float)(v6->velocity.z * (float)v17));
  v134.stageAxis.mat[0].x = *v25;
  v134.stageAxis.mat[0].y = v29;
  v134.stageAxis.mat[0].z = v30;
  v134.stageAxis.mat[1].x = v31;
  v36 = v25[6];
  v37 = v25[7];
  v38 = v25[8];
  v134.stageAxis.mat[1].y = v33;
  v134.stageAxis.mat[1].z = v34;
  v134.stageAxis.mat[2].x = v36;
  v134.stageAxis.mat[2].y = v37;
  v134.stageAxis.mat[2].z = v38;
  v134.localVelocity.x = (float)((float)v28 * (float)v21) + (float)v32;
  v134.localVelocity.y = (float)((float)v26 * (float)v16) + (float)v35;
  v134.localVelocity.z = (float)((float)v26 * (float)v19) + (float)((float)((float)v28 * (float)v18) + (float)v27);
  idVec3::NormalizeFast(this: &v134.localVelocity);
  LODWORD(v72) = BYTE1(v6->color);
  LODWORD(v39) = LOBYTE(v6->color);
  v40 = v6->axis.mat[1].z;
  DWORD2(v39) = BYTE2(v6->color);
  v41 = v6->axis.mat[2].z;
  DWORD1(v39) = parms->renderView;
  v42 = v6->axis.mat[0].y;
  v125 = v72;
  v43 = v6->axis.mat[1].y;
  v124 = v39;
  v44 = v6->axis.mat[2].y;
  v128 = *(_QWORD *)((char *)&v39 + 4);
  v45 = *(float *)(DWORD1(v39) + 32);
  v46 = *(float *)(DWORD1(v39) + 44);
  v47 = (float)((float)v40 * *(float *)(DWORD1(v39) + 32));
  v48 = (float)((float)v40 * *(float *)(DWORD1(v39) + 44));
  v49 = *(float *)(DWORD1(v39) + 28);
  v50 = (float)((float)v41 * *(float *)(DWORD1(v39) + 32));
  v51 = *(float *)(DWORD1(v39) + 40);
  v52 = (float)((float)v41 * *(float *)(DWORD1(v39) + 44));
  v53 = *(float *)(DWORD1(v39) + 24);
  v54 = (float)((float)v42 * *(float *)(DWORD1(v39) + 40));
  v55 = *(float *)(DWORD1(v39) + 36);
  v56 = (float)((float)v42 * *(float *)(DWORD1(v39) + 28));
  v57 = v6->axis.mat[0].x;
  v58 = v6->axis.mat[1].x;
  v59 = v6->axis.mat[2].x;
  v60 = v58;
  v61 = (float)((float)((float)v43 * *(float *)(DWORD1(v39) + 28)) + (float)v47);
  v62 = (float)((float)((float)v43 * *(float *)(DWORD1(v39) + 40)) + (float)v48);
  v134.localViewOrg.x = *(float *)DWORD1(v39);
  v134.localViewOrg.z = *(float *)(DWORD1(v39) + 8);
  v63 = (float)((float)((float)v44 * (float)v49) + (float)v50);
  v64 = (float)((float)((float)v44 * (float)v51) + (float)v52);
  spawnBunching = stage->systemProperties.spawnBunching;
  v66 = (float)((float)((float)v57 * (float)v55) + (float)v54);
  v134.shadow = v6->shadow;
  v67 = (float)((float)((float)v57 * (float)v53) + (float)v56);
  v68 = (double)v72;
  v134.localViewOrg.y = *(float *)(DWORD1(v39) + 4);
  v69 = v6->axis.mat[0].z;
  v70 = (float)((float)((float)spawnBunching * stage->bunchTime) * (float)1000.0);
  v71 = (float)((float)(v6->axis.mat[0].z * (float)v45) + (float)v67);
  HIDWORD(v128) = &v6->numParticles;
  v134.localViewLeft.x = v71;
  LODWORD(v72) = v6->numParticles;
  v73 = (float)((float)((float)v53 * (float)v58) + (float)v61);
  v134.localViewLeft.z = (float)((float)v59 * (float)v53) + (float)v63;
  v74 = v6->wind.x;
  v75 = v6->wind.y;
  v76 = v6->wind.z;
  v77 = *(float *)&v6->diversity;
  LODWORD(v124) = (int)v70;
  v78 = (int)v70;
  v134.wind.x = v74;
  v134.localViewLeft.y = v73;
  v134.influenceSpheres = nullptr;
  v134.wind.y = v75;
  v134.numInfluenceSpheres = 0;
  v134.localViewUp.x = (float)((float)v69 * (float)v46) + (float)v66;
  v122 = v5;
  v134.localViewUp.y = (float)((float)v60 * (float)v55) + (float)v62;
  v123 = 0.0;
  v134.localViewUp.z = (float)((float)v59 * (float)v55) + (float)v64;
  v134.entityColor.w = 1.0;
  v134.fade = 1.0;
  v134.alphaScaleOverride = 1.0;
  v134.distribScale.x = 1.0;
  v134.distribScale.y = 1.0;
  v134.distribScale.z = 1.0;
  v134.sizeScale = 1.0;
  v134.entityColor.x = (float)(__int64)v39 * (float)0.0039215689;
  v79 = v5;
  v134.entityColor.y = (float)*(__int64 *)((char *)&v39 + 4) * (float)0.0039215689;
  v134.entityColor.z = (float)v68 * (float)0.0039215689;
  v134.wind.z = v76;
  if ( (int)v72 > 0 )
  {
    HIDWORD(v125) = &idMath::M_MS2SEC;
    do
    {
      v80 = v123;
      if ( v6->stage->systemProperties.sortType == PSORT_TYPE_NEWEST_TO_OLDEST )
        LODWORD(v80) = v72 - 1;
      v81 = stage->systemProperties.totalParticles;
      *((float *)&v82 + 1) = v80;
      HIDWORD(v72) = v6->startTime;
      v135 = v72;
      HIDWORD(v82) = 1664525 * LODWORD(v77);
      v136 = v82;
      v83 = (idRandom2 *)*p_tables;
      v126.seed = 1664525 * LODWORD(v77) + 1013904223;
      v84 = (double)v82;
      LODWORD(v82) = v81 & ~(__ROL4__(LODWORD(v80) * v78, 1) - 1);
      __twllei(v81, 0);
      __twlgei(v82, 0xFFFFFFFF);
      v85 = LODWORD(v80) * v78 / v81 + HIDWORD(v72);
      v86 = idParticleParm::Compute(
              this: &stage->systemProperties.particleLife,
              tables: v83,
              frac: (float)((float)v84 / (float)v72),
              rand: (idRandom2 *)(LODWORD(v80) * v78),
              a5: &v126,
              a6: v82);
      renderView = parms->renderView;
      v77 = *(float *)&v126.seed;
      v88 = v86;
      renderTime = parms->renderView->renderTime;
      v90 = renderTime - v85;
      v127 = (int)(float)((float)v86 * 1000.0);
      if ( v90 < v127 )
      {
        if ( idParticleStage::NumVertsPerParticle(this: stage) + v122 > parms->maxVertsToGen )
          break;
        LODWORD(v92) = v90;
        HIDWORD(v92) = v6->currTime;
        v93 = v6->velocity.y;
        LODWORD(v94) = renderTime - renderView->deltaTime;
        v137 = v92;
        HIDWORD(v94) = v94 - HIDWORD(v92);
        v95 = v6->velocity.x;
        LODWORD(v91) = v94 - HIDWORD(v92);
        v96 = v6->velocity.z;
        v97 = v6->origin.x;
        quadDepth = parms->quadDepth;
        v129 = v91;
        v99 = *(float *)HIDWORD(v125);
        v100 = v6->origin.y;
        v101 = (float)((float)v92 * *(float *)HIDWORD(v125));
        v102 = v6->origin.z;
        v130.mat[0].z = (float)v92 * *(float *)HIDWORD(v125);
        v130.mat[0].x = v80;
        v130.mat[1].x = v88;
        v130.mat[2].x = v77;
        v130.mat[2].z = 1.0;
        v130.mat[2].y = v77;
        v131 = 1.0;
        HIDWORD(v124) = v138;
        v132 = 1.0;
        v133 = 1.0;
        v130.mat[0].y = v101;
        v130.mat[1].y = (float)v101 / (float)v88;
        v130.mat[1].z = v130.mat[1].y;
        v134.globalOrigin.x = (float)((float)((float)v91 * (float)v99) * (float)v95) + (float)v97;
        v134.globalOrigin.y = (float)v100 + (float)((float)v93 * (float)((float)v91 * (float)v99));
        v134.globalOrigin.z = (float)v102 + (float)((float)((float)v91 * (float)v99) * (float)v96);
        if ( quadDepth != nullptr )
        {
          LODWORD(v94) = &quadDepth[v122 / 4];
          LODWORD(v124) = v94;
        }
        else
        {
          LODWORD(v124) = 0;
        }
        v103 = CreateParticle(
                 inputs: &v134,
                 g: (idRandom2 *)&v130,
                 outputs: (idRandom2 *)&v124,
                 a4: SHIDWORD(v125),
                 a5: v94);
        _R11 = &parms->verts[v122];
        if ( v103 > 0 )
        {
          v106 = v103;
          _R8 = 16;
          _R10 = (_BYTE *)(v138 - (_BYTE *)_R11);
          _R7 = 16;
          do
          {
            _R9 = (char *)_R11 + (_DWORD)_R10;
            __asm
            {
              lvx128    v63, r10, r11
              lvx128    v62, r9, r8
              stvx128   v63, r0, r11
              stvx128   v62, r11, r7
            }
            ++_R11;
            --v106;
          }
          while ( v106 != 0 );
        }
        v122 += v103;
      }
      LODWORD(v72) = *(_DWORD *)HIDWORD(v128);
      ++LODWORD(v123);
    }
    while ( SLODWORD(v123) < *(_DWORD *)HIDWORD(v128) );
    v5 = vertOffset;
    v79 = v122;
  }
  v111 = parms->quadDepth;
  if ( v111 != nullptr && stage->systemProperties.sortType == PSORT_TYPE_NEWEST_TO_OLDEST )
  {
    v112 = (v79 - v5) / 4;
    if ( v112 > 0 )
    {
      v113 = 0;
      v114 = 0.0;
      v115 = 0.0;
      v116 = 0.0;
      if ( v112 >= 2 )
      {
        v117 = 0;
        do
        {
          v113 += 2;
          v114 = (float)(v111[v117] + (float)v114);
          v115 = (float)(v111[v117 + 1] + (float)v115);
          v117 += 2;
        }
        while ( v113 < v112 - 1 );
      }
      if ( v113 < v112 )
        v116 = v111[v113];
      v118 = (unsigned int)v112;
      v129 = (unsigned int)v112;
      v119 = (float)((float)((float)((float)v115 + (float)v114) + (float)v116) / (float)(unsigned int)v112);
      if ( v112 >= 4 )
      {
        LODWORD(v118) = 0;
        do
        {
          HIDWORD(v118) += 4;
          *(float *)((char *)parms->quadDepth + v118) = v119;
          *(float *)((char *)parms->quadDepth + v118 + 4) = v119;
          *(float *)((char *)parms->quadDepth + v118 + 8) = v119;
          *(float *)((char *)parms->quadDepth + v118 + 12) = v119;
          LODWORD(v118) = v118 + 16;
        }
        while ( SHIDWORD(v118) < v112 - 3 );
      }
      if ( SHIDWORD(v118) < v112 )
      {
        LODWORD(v118) = 4 * HIDWORD(v118);
        v120 = v112 - HIDWORD(v118);
        do
        {
          *(float *)((char *)parms->quadDepth + v118) = v119;
          LODWORD(v118) = v118 + 4;
          --v120;
        }
        while ( v120 != 0 );
      }
    }
  }
  return v79 - v5;
}


// ========================================================================
// ?ParticleGenJob@@YAXPBUdeferredParticleGenParms_t@@@Z
// EA  : 0x827EA350
// RVA : 0x007EA350
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

void __fastcall ParticleGenJob(const deferredParticleGenParms_t *parms)
{
  int *quadsUsed; // r11
  int **p_quadsUsed; // r27
  int *p_maxVertsToGen; // r28
  int v6; // r29
  int i; // r30
  int v8; // r3
  int j; // r30
  int v10; // r3
  int v11; // r10
  int v12; // r9
  int v13; // r11
  int v16; // r6
  int v17; // r10
  bool v18; // zf
  int v19; // r11
  int v20; // r11
  int v21; // ctr

  quadsUsed = parms->quadsUsed;
  p_quadsUsed = &parms->quadsUsed;
  if ( quadsUsed != nullptr )
    *quadsUsed = 0;
  p_maxVertsToGen = &parms->maxVertsToGen;
  if ( parms->maxVertsToGen > 0 )
  {
    v6 = 0;
    for ( i = 0; i < parms->numModelParticleParms; v6 += v8 )
      v8 = GenParticleStage(parms, index: i++, vertOffset: v6);
    for ( j = 0; j < parms->numEffectParticleParms; v6 += v10 )
      v10 = GenEffectStage(parms, index: j++, vertOffset: v6);
    v11 = *p_maxVertsToGen;
    v12 = v6;
    if ( v6 < *p_maxVertsToGen )
    {
      __asm { vspltisw128 v63, 0 }
      v13 = v6;
      _R7 = 16;
      __asm
      {
        vcmpequw128 v62, v95, v63
        vsldoi128 v62, v95, v62, 4
      }
      do
      {
        ++v12;
        _R10 = &parms->verts[v13++];
        __asm
        {
          stvx128   v63, r0, r10
          stvx128   v62, r10, r7
        }
        v11 = *p_maxVertsToGen;
      }
      while ( v12 < *p_maxVertsToGen );
    }
    if ( parms->quadDepth != nullptr )
    {
      v16 = v11 / 4;
      v18 = v6 / 4 >= v11 / 4;
      v17 = v6 / 4;
      if ( !v18 )
      {
        if ( v16 - v17 >= 4 )
        {
          v19 = v17;
          do
          {
            v17 += 4;
            parms->quadDepth[v19] = 0.0;
            parms->quadDepth[v19 + 1] = 0.0;
            parms->quadDepth[v19 + 2] = 0.0;
            parms->quadDepth[v19 + 3] = 0.0;
            v19 += 4;
          }
          while ( v17 < v16 - 3 );
        }
        if ( v17 < v16 )
        {
          v20 = v17;
          v21 = v16 - v17;
          do
          {
            parms->quadDepth[v20++] = 0.0;
            --v21;
          }
          while ( v21 != 0 );
        }
      }
    }
    if ( *p_quadsUsed != nullptr )
      **p_quadsUsed = v6 / 4;
  }
}


// ========================================================================
// `dynamic initializer for 'register_ParticleGenJob''
// EA  : 0x83342F30
// RVA : 0x01342F30
// PDB : w:\tech5\engine\models\particles\jobs\particlegen.cpp
// ========================================================================

idParallelJobRegistration *_dynamic_initializer_for__register_ParticleGenJob__()
{
  return idParallelJobRegistration::idParallelJobRegistration(
           this: &register_ParticleGenJob,
           function: (void (__fastcall *)(void *))ParticleGenJob,
           name: "ParticleGenJob");
}

