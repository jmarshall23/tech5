
// ========================================================================
// ?FDCT_AP922_float@@YAXPBFPBGPAF@Z
// EA  : 0x828EA590
// RVA : 0x008EA590
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FDCT_AP922_float(const __int16 *src, __int64 coeff)
{
  __int64 v2; // r27 OVERLAPPED
  int v3; // r2 OVERLAPPED
  float *v4; // r10
  int v5; // ctr
  double v6; // fp12
  const __int16 *v7; // r11
  double v8; // fp13
  double v9; // fp0
  double v10; // fp11
  int v11; // r3
  __int16 v12; // r29
  int v13; // r31
  __int16 v14; // r9
  __int16 v15; // r28
  __int128 v16; // r8 OVERLAPPED
  int v17; // r3
  int v18; // r29
  __int64 v19; // r31
  int v20; // r28
  __int64 v21; // fp7
  int v22; // r3
  int v23; // r9
  _WORD *v24; // r8
  float *v25; // r9
  int v26; // ctr
  int v27; // r10
  const float **v28; // r7
  unsigned __int16 *v29; // r11
  double v30; // fp11
  double v31; // fp12
  double v32; // fp10
  double v33; // fp7
  double v34; // fp9
  double v35; // fp6
  double v36; // fp5
  double v37; // fp0
  double v38; // fp0
  double v39; // fp0
  double v40; // fp0
  double v41; // fp0
  double v42; // fp0
  double v43; // fp0
  double v44; // fp0
  __int64 v45; // [sp+20h] [-1F0h]
  char v46; // [sp+94h] [-17Ch] BYREF
  char v47; // [sp+ECh] [-124h] BYREF

  v4 = (float *)&v47;
  v5 = 8;
  v6 = tg_1_16;
  v7 = src + 23;
  v8 = cos_4_16;
  v9 = tg_2_16;
  v10 = tg_3_16;
  do
  {
    v11 = v7[17];
    v12 = *(v7 - 23);
    v13 = *(v7 - 7);
    v14 = v7[33];
    v15 = v7[9];
    LODWORD(v16) = v13 - v11;
    DWORD2(v16) = *((unsigned __int16 *)v7 + 25);
    WORD3(v16) = *(v7 - 15);
    v17 = v13 + v11;
    ++v7;
    v45 = v16;
    LODWORD(v16) = v12;
    v18 = v15;
    HIDWORD(v19) = *v7;
    v20 = v16 + v14;
    v21 = *(_QWORD *)(&v3 - 1);
    DWORD1(v16) = SWORD3(v16);
    v22 = v16 - v14;
    v23 = SWORD1(v19) - v18;
    LODWORD(v2) = SWORD3(v16) + SWORD5(v16);
    DWORD2(v16) = SWORD3(v16) - SWORD5(v16);
    LODWORD(v16) = DWORD2(v16);
    LODWORD(v19) = v18 + SWORD1(v19);
    *(v4 - 23) = (float)((float)v21 + (float)v2) + (float)((float)v19 + (float)*(__int64 *)((char *)&v2 - 4));
    v4[9] = (float)((float)v19 + (float)*(__int64 *)((char *)&v2 - 4)) - (float)((float)v21 + (float)v2);
    *(v4 - 7) = (float)((float)v9 * (float)((float)v2 - (float)v21))
              + (float)((float)*(__int64 *)((char *)&v2 - 4) - (float)v19);
    v4[25] = (float)((float)v9 * (float)((float)*(__int64 *)((char *)&v2 - 4) - (float)v19))
           - (float)((float)v2 - (float)v21);
    *(v4 - 15) = (float)((float)v6
                       * (float)((float)((float)((float)*(__int64 *)((char *)&v16 + 4) - (float)v45) * (float)v8)
                               + (float)*(__int64 *)((char *)&v16 - 4)))
               + (float)((float)((float)((float)*(__int64 *)((char *)&v16 + 4) + (float)v45) * (float)v8)
                       + (float)*(__int64 *)(&v3 - 1));
    v4[33] = (float)((float)v6
                   * (float)((float)((float)((float)*(__int64 *)((char *)&v16 + 4) + (float)v45) * (float)v8)
                           + (float)*(__int64 *)(&v3 - 1)))
           - (float)((float)((float)((float)*(__int64 *)((char *)&v16 + 4) - (float)v45) * (float)v8)
                   + (float)*(__int64 *)((char *)&v16 - 4));
    v4[17] = (float)((float)v10
                   * (float)((float)*(__int64 *)(&v3 - 1)
                           - (float)((float)((float)*(__int64 *)((char *)&v16 + 4) + (float)v45) * (float)v8)))
           + (float)((float)*(__int64 *)((char *)&v16 - 4)
                   - (float)((float)((float)*(__int64 *)((char *)&v16 + 4) - (float)v45) * (float)v8));
    *++v4 = -(float)((float)((float)v10
                           * (float)((float)*(__int64 *)((char *)&v16 - 4)
                                   - (float)((float)((float)*(__int64 *)((char *)&v16 + 4) - (float)v45) * (float)v8)))
                   - (float)((float)*(__int64 *)(&v3 - 1)
                           - (float)((float)((float)*(__int64 *)((char *)&v16 + 4) + (float)v45) * (float)v8)));
    --v5;
  }
  while ( v5 != 0 );
  v24 = (_WORD *)(coeff - 2);
  v25 = (float *)&v46;
  v26 = 8;
  v27 = coeff - HIDWORD(coeff);
  v28 = forwardRowTables;
  v29 = (unsigned __int16 *)(HIDWORD(coeff) + 2);
  do
  {
    v30 = (float)((float)((*v28)[1] * (float)(v25[6] + *(v25 - 1)))
                + (float)((float)((*v28)[9] * (float)(v25[5] + *v25))
                        + (float)((float)((*v28)[13] * (float)(v25[2] + v25[3]))
                                + (float)((*v28)[5] * (float)(v25[4] + v25[1])))));
    v31 = (float)((float)((*v28)[16] * (float)(*(v25 - 1) - v25[6]))
                + (float)((float)((*v28)[24] * (float)(*v25 - v25[5]))
                        + (float)((float)((*v28)[28] * (float)(v25[2] - v25[3]))
                                + (float)((*v28)[20] * (float)(v25[1] - v25[4])))));
    v32 = (float)((float)((*v28)[17] * (float)(*(v25 - 1) - v25[6]))
                + (float)((float)((*v28)[25] * (float)(*v25 - v25[5]))
                        + (float)((float)((*v28)[29] * (float)(v25[2] - v25[3]))
                                + (float)((*v28)[21] * (float)(v25[1] - v25[4])))));
    v33 = (float)((float)((*v28)[18] * (float)(*(v25 - 1) - v25[6]))
                + (float)((float)((*v28)[26] * (float)(*v25 - v25[5]))
                        + (float)((float)((*v28)[30] * (float)(v25[2] - v25[3]))
                                + (float)((*v28)[22] * (float)(v25[1] - v25[4])))));
    v34 = (float)((float)((*v28)[2] * (float)(v25[6] + *(v25 - 1)))
                + (float)((float)((*v28)[10] * (float)(v25[5] + *v25))
                        + (float)((float)((*v28)[14] * (float)(v25[2] + v25[3]))
                                + (float)((*v28)[6] * (float)(v25[4] + v25[1])))));
    v35 = (float)((float)((*v28)[3] * (float)(v25[6] + *(v25 - 1)))
                + (float)((float)((*v28)[11] * (float)(v25[5] + *v25))
                        + (float)((float)((*v28)[15] * (float)(v25[2] + v25[3]))
                                + (float)((*v28)[7] * (float)(v25[4] + v25[1])))));
    v36 = (float)((float)((*v28)[19] * (float)(*(v25 - 1) - v25[6]))
                + (float)((float)((*v28)[27] * (float)(*v25 - v25[5]))
                        + (float)((float)((*v28)[31] * (float)(v25[2] - v25[3]))
                                + (float)((*v28)[23] * (float)(v25[1] - v25[4])))));
    LODWORD(coeff) = *(v29 - 1);
    if ( (float)((float)(**v28 * (float)(v25[6] + *(v25 - 1)))
               + (float)((float)((*v28)[8] * (float)(v25[5] + *v25))
                       + (float)((float)((*v28)[12] * (float)(v25[2] + v25[3]))
                               + (float)((*v28)[4] * (float)(v25[4] + v25[1]))))) >= 0.0 )
      v37 = (float)((float)((float)((float)(**v28 * (float)(v25[6] + *(v25 - 1)))
                                  + (float)((float)((*v28)[8] * (float)(v25[5] + *v25))
                                          + (float)((float)((*v28)[12] * (float)(v25[2] + v25[3]))
                                                  + (float)((*v28)[4] * (float)(v25[4] + v25[1])))))
                          / (float)coeff)
                  + (float)0.5);
    else
      v37 = (float)((float)((float)((float)(**v28 * (float)(v25[6] + *(v25 - 1)))
                                  + (float)((float)((*v28)[8] * (float)(v25[5] + *v25))
                                          + (float)((float)((*v28)[12] * (float)(v25[2] + v25[3]))
                                                  + (float)((*v28)[4] * (float)(v25[4] + v25[1])))))
                          / (float)coeff)
                  - (float)0.5);
    v24[1] = (int)v37;
    LODWORD(coeff) = *v29;
    if ( v31 >= 0.0 )
      v38 = (float)((float)((float)v31 / (float)coeff) + (float)0.5);
    else
      v38 = (float)((float)((float)v31 / (float)coeff) - (float)0.5);
    *(unsigned __int16 *)((char *)v29 + v27) = (int)v38;
    LODWORD(coeff) = v29[1];
    if ( v30 >= 0.0 )
      v39 = (float)((float)((float)v30 / (float)coeff) + (float)0.5);
    else
      v39 = (float)((float)((float)v30 / (float)coeff) - (float)0.5);
    v24[3] = (int)v39;
    LODWORD(coeff) = v29[2];
    if ( v32 >= 0.0 )
      v40 = (float)((float)((float)v32 / (float)coeff) + (float)0.5);
    else
      v40 = (float)((float)((float)v32 / (float)coeff) - (float)0.5);
    v24[4] = (int)v40;
    LODWORD(coeff) = v29[3];
    if ( v34 >= 0.0 )
      v41 = (float)((float)((float)v34 / (float)coeff) + (float)0.5);
    else
      v41 = (float)((float)((float)v34 / (float)coeff) - (float)0.5);
    v24[5] = (int)v41;
    LODWORD(coeff) = v29[4];
    if ( v33 >= 0.0 )
      v42 = (float)((float)((float)v33 / (float)coeff) + (float)0.5);
    else
      v42 = (float)((float)((float)v33 / (float)coeff) - (float)0.5);
    v24[6] = (int)v42;
    LODWORD(coeff) = v29[5];
    if ( v35 >= 0.0 )
      v43 = (float)((float)((float)v35 / (float)coeff) + (float)0.5);
    else
      v43 = (float)((float)((float)v35 / (float)coeff) - (float)0.5);
    v24[7] = (int)v43;
    LODWORD(coeff) = v29[6];
    if ( v36 >= 0.0 )
      v44 = (float)((float)((float)v36 / (float)coeff) + (float)0.5);
    else
      v44 = (float)((float)((float)v36 / (float)coeff) - (float)0.5);
    v25 += 8;
    v29 += 8;
    ++v28;
    v24 += 8;
    *v24 = (int)v44;
    --v26;
  }
  while ( v26 != 0 );
}


// ========================================================================
// `dynamic initializer for 'tg_1_16''
// EA  : 0x8334C3D0
// RVA : 0x0134C3D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tg_1_16__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FC921FB60000000LL;
  tg_1_16 = tan(x: a1);
}


// ========================================================================
// `dynamic initializer for 'tg_2_16''
// EA  : 0x8334C408
// RVA : 0x0134C408
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tg_2_16__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FD921FB60000000LL;
  tg_2_16 = tan(x: a1);
}


// ========================================================================
// `dynamic initializer for 'tg_3_16''
// EA  : 0x8334C440
// RVA : 0x0134C440
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tg_3_16__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FE2D97C80000000LL;
  tg_3_16 = tan(x: a1);
}


// ========================================================================
// `dynamic initializer for 'cos_4_16''
// EA  : 0x8334C478
// RVA : 0x0134C478
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__cos_4_16__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FE921FB60000000LL;
  cos_4_16 = cos(x: a1);
}


// ========================================================================
// `dynamic initializer for 'tab_f_04''
// EA  : 0x8334C4B0
// RVA : 0x0134C4B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_f_04__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp27
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp27
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp27
  long double v14; // fp2
  long double v15; // fp2
  double v16; // fp27
  long double v17; // fp2
  long double v18; // fp2
  double v19; // fp27
  long double v20; // fp2
  long double v21; // fp2
  double v22; // fp12
  double v23; // fp27
  long double v24; // fp2
  long double v25; // fp2
  double v26; // fp27
  long double v27; // fp2
  long double v28; // fp2
  double v29; // fp27
  long double v30; // fp2
  long double v31; // fp2
  double v32; // fp27
  long double v33; // fp2
  long double v34; // fp2
  double v35; // fp3
  double v36; // fp27
  long double v37; // fp2
  double v38; // fp1
  long double v39; // fp2
  double v40; // fp13
  double v41; // fp27
  long double v42; // fp2
  long double v43; // fp2
  double v44; // fp29
  long double v45; // fp2
  long double v46; // fp2
  double v47; // fp8
  double v48; // fp29
  long double v49; // fp2
  long double v50; // fp2
  double v51; // fp28
  long double v52; // fp2
  long double v53; // fp2
  double v54; // fp3
  double v55; // fp27
  long double v56; // fp2
  double v57; // fp1
  long double v58; // fp2
  double v59; // fp26
  long double v60; // fp2
  long double v61; // fp2
  double v62; // fp25
  long double v63; // fp2
  long double v64; // fp2
  double v65; // fp25
  long double v66; // fp2
  long double v67; // fp2
  double v68; // fp25
  long double v69; // fp2
  long double v70; // fp2
  double v71; // fp25
  long double v72; // fp2
  long double v73; // fp2
  double v74; // fp3
  double v75; // fp25
  long double v76; // fp2
  double v77; // fp1
  long double v78; // fp2
  double v79; // fp25
  long double v80; // fp2
  long double v81; // fp2
  double v82; // fp25
  long double v83; // fp2
  long double v84; // fp2
  double v85; // fp25
  long double v86; // fp2
  long double v87; // fp2
  double v88; // fp7
  double v89; // fp25
  long double v90; // fp2
  long double v91; // fp2
  double v92; // fp4
  double v93; // fp25
  long double v94; // fp2
  double v95; // fp1
  long double v96; // fp2
  double v97; // fp0
  double v98; // fp26
  long double v99; // fp2
  long double v100; // fp2
  double v101; // fp27
  long double v102; // fp2
  long double v103; // fp2
  double v104; // fp9
  double v105; // fp28
  long double v106; // fp2
  long double v107; // fp2
  double v108; // fp29
  long double v109; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.7853981852531433;
  tab_f_04[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.7853981852531433;
  tab_f_04[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.7853981852531433;
  tab_f_04[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 1.178097248077393;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.7853981852531433;
  tab_f_04[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
  *(double *)&v12 = 0.7853981852531433;
  v13 = (float)cos(x: v12);
  *(double *)&v14 = 0.7853981852531433;
  tab_f_04[4] = (float)((float)cos(x: v14) * (float)v13) * (float)0.25;
  *(double *)&v15 = 1.178097248077393;
  v16 = (float)cos(x: v15);
  *(double *)&v17 = 0.7853981852531433;
  *((double *)&v18 + 1) = (float)((float)((float)cos(x: v17) * (float)v16) * (float)0.25);
  *(double *)&v18 = 0.7853981852531433;
  tab_f_04[5] = -*((double *)&v18 + 1);
  v19 = (float)cos(x: v18);
  *(double *)&v20 = 0.7853981852531433;
  v22 = (float)((float)((float)cos(x: v20) * (float)v19) * (float)0.25);
  *(double *)&v21 = 0.3926990926265717;
  tab_f_04[6] = -v22;
  v23 = (float)cos(x: v21);
  *(double *)&v24 = 0.7853981852531433;
  tab_f_04[7] = (float)((float)cos(x: v24) * (float)v23) * (float)0.25;
  *(double *)&v25 = 0.7853981852531433;
  v26 = (float)cos(x: v25);
  *(double *)&v27 = 0.7853981852531433;
  tab_f_04[8] = (float)((float)cos(x: v27) * (float)v26) * (float)0.25;
  *(double *)&v28 = 1.178097248077393;
  v29 = (float)cos(x: v28);
  *(double *)&v30 = 0.7853981852531433;
  tab_f_04[9] = (float)((float)cos(x: v30) * (float)v29) * (float)0.25;
  *(double *)&v31 = 0.7853981852531433;
  v32 = (float)cos(x: v31);
  *(double *)&v33 = 0.7853981852531433;
  v35 = (float)((float)((float)cos(x: v33) * (float)v32) * (float)0.25);
  *(double *)&v34 = 0.3926990926265717;
  tab_f_04[10] = -v35;
  v36 = (float)cos(x: v34);
  *(double *)&v37 = 0.7853981852531433;
  v38 = cos(x: v37);
  *((double *)&v39 + 1) = (float)v38;
  v40 = (float)((float)((float)v38 * (float)v36) * (float)0.25);
  *(double *)&v39 = 0.7853981852531433;
  tab_f_04[11] = -v40;
  v41 = (float)cos(x: v39);
  *(double *)&v42 = 0.7853981852531433;
  tab_f_04[12] = (float)((float)cos(x: v42) * (float)v41) * (float)0.25;
  *(double *)&v43 = 0.3926990926265717;
  v44 = (float)cos(x: v43);
  *(double *)&v45 = 0.7853981852531433;
  v47 = (float)((float)((float)cos(x: v45) * (float)v44) * (float)0.25);
  *(double *)&v46 = 0.7853981852531433;
  tab_f_04[13] = -v47;
  v48 = (float)cos(x: v46);
  *(double *)&v49 = 0.7853981852531433;
  tab_f_04[14] = (float)((float)cos(x: v49) * (float)v48) * (float)0.25;
  *(double *)&v50 = 1.178097248077393;
  v51 = (float)cos(x: v50);
  *(double *)&v52 = 0.7853981852531433;
  v54 = (float)((float)((float)cos(x: v52) * (float)v51) * (float)0.25);
  *(double *)&v53 = 0.1963495463132858;
  tab_f_04[15] = -v54;
  v55 = (float)cos(x: v53);
  *(double *)&v56 = 0.7853981852531433;
  v57 = cos(x: v56);
  *((double *)&v58 + 1) = (float)v57;
  tab_f_04[16] = (float)((float)v57 * (float)v55) * (float)0.25;
  *(double *)&v58 = 0.5890486240386963;
  v59 = (float)cos(x: v58);
  *(double *)&v60 = 0.7853981852531433;
  tab_f_04[17] = (float)((float)cos(x: v60) * (float)v59) * (float)0.25;
  *(double *)&v61 = 0.9817477464675903;
  v62 = (float)cos(x: v61);
  *(double *)&v63 = 0.7853981852531433;
  tab_f_04[18] = (float)((float)cos(x: v63) * (float)v62) * (float)0.25;
  *(double *)&v64 = 1.374446868896484;
  v65 = (float)cos(x: v64);
  *(double *)&v66 = 0.7853981852531433;
  tab_f_04[19] = (float)((float)cos(x: v66) * (float)v65) * (float)0.25;
  *(double *)&v67 = 0.9817477464675903;
  v68 = (float)cos(x: v67);
  *(double *)&v69 = 0.7853981852531433;
  tab_f_04[20] = (float)((float)cos(x: v69) * (float)v68) * (float)0.25;
  *(double *)&v70 = 0.1963495463132858;
  v71 = (float)cos(x: v70);
  *(double *)&v72 = 0.7853981852531433;
  v74 = (float)((float)((float)cos(x: v72) * (float)v71) * (float)0.25);
  *(double *)&v73 = 1.374446868896484;
  tab_f_04[21] = -v74;
  v75 = (float)cos(x: v73);
  *(double *)&v76 = 0.7853981852531433;
  v77 = cos(x: v76);
  *((double *)&v78 + 1) = (float)v77;
  tab_f_04[22] = (float)((float)v77 * (float)v75) * (float)0.25;
  *(double *)&v78 = 0.5890486240386963;
  v79 = (float)cos(x: v78);
  *(double *)&v80 = 0.7853981852531433;
  tab_f_04[23] = (float)((float)cos(x: v80) * (float)v79) * (float)0.25;
  *(double *)&v81 = 0.5890486240386963;
  v82 = (float)cos(x: v81);
  *(double *)&v83 = 0.7853981852531433;
  tab_f_04[24] = (float)((float)cos(x: v83) * (float)v82) * (float)0.25;
  *(double *)&v84 = 1.374446868896484;
  v85 = (float)cos(x: v84);
  *(double *)&v86 = 0.7853981852531433;
  v88 = (float)((float)((float)cos(x: v86) * (float)v85) * (float)0.25);
  *(double *)&v87 = 0.1963495463132858;
  tab_f_04[25] = -v88;
  v89 = (float)cos(x: v87);
  *(double *)&v90 = 0.7853981852531433;
  v92 = (float)((float)((float)cos(x: v90) * (float)v89) * (float)0.25);
  *(double *)&v91 = 0.9817477464675903;
  tab_f_04[26] = -v92;
  v93 = (float)cos(x: v91);
  *(double *)&v94 = 0.7853981852531433;
  v95 = cos(x: v94);
  *((double *)&v96 + 1) = (float)((float)v95 * (float)v93);
  v97 = (float)((float)((float)v95 * (float)v93) * (float)0.25);
  *(double *)&v96 = 1.374446868896484;
  tab_f_04[27] = -v97;
  v98 = (float)cos(x: v96);
  *(double *)&v99 = 0.7853981852531433;
  tab_f_04[28] = (float)((float)cos(x: v99) * (float)v98) * (float)0.25;
  *(double *)&v100 = 0.9817477464675903;
  v101 = (float)cos(x: v100);
  *(double *)&v102 = 0.7853981852531433;
  v104 = (float)((float)((float)cos(x: v102) * (float)v101) * (float)0.25);
  *(double *)&v103 = 0.5890486240386963;
  tab_f_04[29] = -v104;
  v105 = (float)cos(x: v103);
  *(double *)&v106 = 0.7853981852531433;
  tab_f_04[30] = (float)((float)cos(x: v106) * (float)v105) * (float)0.25;
  *(double *)&v107 = 0.1963495463132858;
  v108 = (float)cos(x: v107);
  *(double *)&v109 = 0.7853981852531433;
  tab_f_04[31] = -(float)((float)((float)cos(x: v109) * (float)v108) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_f_17''
// EA  : 0x8334C9E0
// RVA : 0x0134C9E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_f_17__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp26
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp26
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp26
  long double v14; // fp2
  long double v15; // fp2
  double v16; // fp26
  long double v17; // fp2
  long double v18; // fp2
  double v19; // fp26
  long double v20; // fp2
  long double v21; // fp2
  double v22; // fp12
  double v23; // fp26
  long double v24; // fp2
  long double v25; // fp2
  double v26; // fp26
  long double v27; // fp2
  long double v28; // fp2
  double v29; // fp26
  long double v30; // fp2
  long double v31; // fp2
  double v32; // fp26
  long double v33; // fp2
  long double v34; // fp2
  double v35; // fp3
  double v36; // fp26
  long double v37; // fp2
  double v38; // fp1
  long double v39; // fp2
  double v40; // fp13
  double v41; // fp26
  long double v42; // fp2
  long double v43; // fp2
  double v44; // fp28
  long double v45; // fp2
  long double v46; // fp2
  double v47; // fp8
  double v48; // fp29
  long double v49; // fp2
  long double v50; // fp2
  double v51; // fp29
  long double v52; // fp2
  long double v53; // fp2
  double v54; // fp3
  double v55; // fp28
  long double v56; // fp2
  double v57; // fp1
  long double v58; // fp2
  double v59; // fp27
  long double v60; // fp2
  long double v61; // fp2
  double v62; // fp26
  long double v63; // fp2
  long double v64; // fp2
  double v65; // fp26
  long double v66; // fp2
  long double v67; // fp2
  double v68; // fp26
  long double v69; // fp2
  long double v70; // fp2
  double v71; // fp26
  long double v72; // fp2
  long double v73; // fp2
  double v74; // fp3
  double v75; // fp26
  long double v76; // fp2
  double v77; // fp1
  long double v78; // fp2
  double v79; // fp26
  long double v80; // fp2
  long double v81; // fp2
  double v82; // fp26
  long double v83; // fp2
  long double v84; // fp2
  double v85; // fp26
  long double v86; // fp2
  long double v87; // fp2
  double v88; // fp7
  double v89; // fp26
  long double v90; // fp2
  long double v91; // fp2
  double v92; // fp4
  double v93; // fp26
  long double v94; // fp2
  double v95; // fp1
  long double v96; // fp2
  double v97; // fp0
  double v98; // fp27
  long double v99; // fp2
  long double v100; // fp2
  double v101; // fp28
  long double v102; // fp2
  long double v103; // fp2
  double v104; // fp9
  double v105; // fp29
  long double v106; // fp2
  long double v107; // fp2
  double v108; // fp29
  long double v109; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.1963495463132858;
  tab_f_17[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.1963495463132858;
  tab_f_17[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.1963495463132858;
  tab_f_17[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 1.178097248077393;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.1963495463132858;
  tab_f_17[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
  *(double *)&v12 = 0.7853981852531433;
  v13 = (float)cos(x: v12);
  *(double *)&v14 = 0.1963495463132858;
  tab_f_17[4] = (float)((float)cos(x: v14) * (float)v13) * (float)0.25;
  *(double *)&v15 = 1.178097248077393;
  v16 = (float)cos(x: v15);
  *(double *)&v17 = 0.1963495463132858;
  *((double *)&v18 + 1) = (float)((float)((float)cos(x: v17) * (float)v16) * (float)0.25);
  *(double *)&v18 = 0.7853981852531433;
  tab_f_17[5] = -*((double *)&v18 + 1);
  v19 = (float)cos(x: v18);
  *(double *)&v20 = 0.1963495463132858;
  v22 = (float)((float)((float)cos(x: v20) * (float)v19) * (float)0.25);
  *(double *)&v21 = 0.3926990926265717;
  tab_f_17[6] = -v22;
  v23 = (float)cos(x: v21);
  *(double *)&v24 = 0.1963495463132858;
  tab_f_17[7] = (float)((float)cos(x: v24) * (float)v23) * (float)0.25;
  *(double *)&v25 = 0.7853981852531433;
  v26 = (float)cos(x: v25);
  *(double *)&v27 = 0.1963495463132858;
  tab_f_17[8] = (float)((float)cos(x: v27) * (float)v26) * (float)0.25;
  *(double *)&v28 = 1.178097248077393;
  v29 = (float)cos(x: v28);
  *(double *)&v30 = 0.1963495463132858;
  tab_f_17[9] = (float)((float)cos(x: v30) * (float)v29) * (float)0.25;
  *(double *)&v31 = 0.7853981852531433;
  v32 = (float)cos(x: v31);
  *(double *)&v33 = 0.1963495463132858;
  v35 = (float)((float)((float)cos(x: v33) * (float)v32) * (float)0.25);
  *(double *)&v34 = 0.3926990926265717;
  tab_f_17[10] = -v35;
  v36 = (float)cos(x: v34);
  *(double *)&v37 = 0.1963495463132858;
  v38 = cos(x: v37);
  *((double *)&v39 + 1) = (float)v38;
  v40 = (float)((float)((float)v38 * (float)v36) * (float)0.25);
  *(double *)&v39 = 0.7853981852531433;
  tab_f_17[11] = -v40;
  v41 = (float)cos(x: v39);
  *(double *)&v42 = 0.1963495463132858;
  tab_f_17[12] = (float)((float)cos(x: v42) * (float)v41) * (float)0.25;
  *(double *)&v43 = 0.3926990926265717;
  v44 = (float)cos(x: v43);
  *(double *)&v45 = 0.1963495463132858;
  v47 = (float)((float)((float)cos(x: v45) * (float)v44) * (float)0.25);
  *(double *)&v46 = 0.7853981852531433;
  tab_f_17[13] = -v47;
  v48 = (float)cos(x: v46);
  *(double *)&v49 = 0.1963495463132858;
  tab_f_17[14] = (float)((float)cos(x: v49) * (float)v48) * (float)0.25;
  *(double *)&v50 = 1.178097248077393;
  v51 = (float)cos(x: v50);
  *(double *)&v52 = 0.1963495463132858;
  v54 = (float)((float)((float)cos(x: v52) * (float)v51) * (float)0.25);
  *(double *)&v53 = 0.1963495463132858;
  tab_f_17[15] = -v54;
  v55 = (float)cos(x: v53);
  *(double *)&v56 = 0.1963495463132858;
  v57 = cos(x: v56);
  *((double *)&v58 + 1) = (float)v57;
  tab_f_17[16] = (float)((float)v57 * (float)v55) * (float)0.25;
  *(double *)&v58 = 0.5890486240386963;
  v59 = (float)cos(x: v58);
  *(double *)&v60 = 0.1963495463132858;
  tab_f_17[17] = (float)((float)cos(x: v60) * (float)v59) * (float)0.25;
  *(double *)&v61 = 0.9817477464675903;
  v62 = (float)cos(x: v61);
  *(double *)&v63 = 0.1963495463132858;
  tab_f_17[18] = (float)((float)cos(x: v63) * (float)v62) * (float)0.25;
  *(double *)&v64 = 1.374446868896484;
  v65 = (float)cos(x: v64);
  *(double *)&v66 = 0.1963495463132858;
  tab_f_17[19] = (float)((float)cos(x: v66) * (float)v65) * (float)0.25;
  *(double *)&v67 = 0.9817477464675903;
  v68 = (float)cos(x: v67);
  *(double *)&v69 = 0.1963495463132858;
  tab_f_17[20] = (float)((float)cos(x: v69) * (float)v68) * (float)0.25;
  *(double *)&v70 = 0.1963495463132858;
  v71 = (float)cos(x: v70);
  *(double *)&v72 = 0.1963495463132858;
  v74 = (float)((float)((float)cos(x: v72) * (float)v71) * (float)0.25);
  *(double *)&v73 = 1.374446868896484;
  tab_f_17[21] = -v74;
  v75 = (float)cos(x: v73);
  *(double *)&v76 = 0.1963495463132858;
  v77 = cos(x: v76);
  *((double *)&v78 + 1) = (float)v77;
  tab_f_17[22] = (float)((float)v77 * (float)v75) * (float)0.25;
  *(double *)&v78 = 0.5890486240386963;
  v79 = (float)cos(x: v78);
  *(double *)&v80 = 0.1963495463132858;
  tab_f_17[23] = (float)((float)cos(x: v80) * (float)v79) * (float)0.25;
  *(double *)&v81 = 0.5890486240386963;
  v82 = (float)cos(x: v81);
  *(double *)&v83 = 0.1963495463132858;
  tab_f_17[24] = (float)((float)cos(x: v83) * (float)v82) * (float)0.25;
  *(double *)&v84 = 1.374446868896484;
  v85 = (float)cos(x: v84);
  *(double *)&v86 = 0.1963495463132858;
  v88 = (float)((float)((float)cos(x: v86) * (float)v85) * (float)0.25);
  *(double *)&v87 = 0.1963495463132858;
  tab_f_17[25] = -v88;
  v89 = (float)cos(x: v87);
  *(double *)&v90 = 0.1963495463132858;
  v92 = (float)((float)((float)cos(x: v90) * (float)v89) * (float)0.25);
  *(double *)&v91 = 0.9817477464675903;
  tab_f_17[26] = -v92;
  v93 = (float)cos(x: v91);
  *(double *)&v94 = 0.1963495463132858;
  v95 = cos(x: v94);
  *((double *)&v96 + 1) = (float)((float)v95 * (float)v93);
  v97 = (float)((float)((float)v95 * (float)v93) * (float)0.25);
  *(double *)&v96 = 1.374446868896484;
  tab_f_17[27] = -v97;
  v98 = (float)cos(x: v96);
  *(double *)&v99 = 0.1963495463132858;
  tab_f_17[28] = (float)((float)cos(x: v99) * (float)v98) * (float)0.25;
  *(double *)&v100 = 0.9817477464675903;
  v101 = (float)cos(x: v100);
  *(double *)&v102 = 0.1963495463132858;
  v104 = (float)((float)((float)cos(x: v102) * (float)v101) * (float)0.25);
  *(double *)&v103 = 0.5890486240386963;
  tab_f_17[29] = -v104;
  v105 = (float)cos(x: v103);
  *(double *)&v106 = 0.1963495463132858;
  tab_f_17[30] = (float)((float)cos(x: v106) * (float)v105) * (float)0.25;
  *(double *)&v107 = 0.1963495463132858;
  v108 = (float)cos(x: v107);
  *(double *)&v109 = 0.1963495463132858;
  tab_f_17[31] = -(float)((float)((float)cos(x: v109) * (float)v108) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_f_26''
// EA  : 0x8334CF10
// RVA : 0x0134CF10
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_f_26__(long double a1)
{
  double v1; // fp28
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp28
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp27
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp27
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp27
  long double v14; // fp2
  long double v15; // fp2
  double v16; // fp27
  long double v17; // fp2
  long double v18; // fp2
  double v19; // fp27
  long double v20; // fp2
  long double v21; // fp2
  double v22; // fp12
  double v23; // fp27
  long double v24; // fp2
  long double v25; // fp2
  double v26; // fp27
  long double v27; // fp2
  long double v28; // fp2
  double v29; // fp27
  long double v30; // fp2
  long double v31; // fp2
  double v32; // fp27
  long double v33; // fp2
  long double v34; // fp2
  double v35; // fp3
  double v36; // fp27
  long double v37; // fp2
  double v38; // fp1
  long double v39; // fp2
  double v40; // fp13
  double v41; // fp27
  long double v42; // fp2
  long double v43; // fp2
  double v44; // fp27
  long double v45; // fp2
  long double v46; // fp2
  double v47; // fp8
  double v48; // fp29
  long double v49; // fp2
  long double v50; // fp2
  double v51; // fp28
  long double v52; // fp2
  long double v53; // fp2
  double v54; // fp3
  double v55; // fp27
  long double v56; // fp2
  double v57; // fp1
  long double v58; // fp2
  double v59; // fp26
  long double v60; // fp2
  long double v61; // fp2
  double v62; // fp25
  long double v63; // fp2
  long double v64; // fp2
  double v65; // fp25
  long double v66; // fp2
  long double v67; // fp2
  double v68; // fp25
  long double v69; // fp2
  long double v70; // fp2
  double v71; // fp25
  long double v72; // fp2
  long double v73; // fp2
  double v74; // fp3
  double v75; // fp25
  long double v76; // fp2
  double v77; // fp1
  long double v78; // fp2
  double v79; // fp25
  long double v80; // fp2
  long double v81; // fp2
  double v82; // fp25
  long double v83; // fp2
  long double v84; // fp2
  double v85; // fp25
  long double v86; // fp2
  long double v87; // fp2
  double v88; // fp7
  double v89; // fp25
  long double v90; // fp2
  long double v91; // fp2
  double v92; // fp4
  double v93; // fp25
  long double v94; // fp2
  double v95; // fp1
  long double v96; // fp2
  double v97; // fp0
  double v98; // fp26
  long double v99; // fp2
  long double v100; // fp2
  double v101; // fp27
  long double v102; // fp2
  long double v103; // fp2
  double v104; // fp9
  double v105; // fp28
  long double v106; // fp2
  long double v107; // fp2
  double v108; // fp29
  long double v109; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.3926990926265717;
  tab_f_26[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.3926990926265717;
  tab_f_26[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.3926990926265717;
  tab_f_26[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 1.178097248077393;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.3926990926265717;
  tab_f_26[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
  *(double *)&v12 = 0.7853981852531433;
  v13 = (float)cos(x: v12);
  *(double *)&v14 = 0.3926990926265717;
  tab_f_26[4] = (float)((float)cos(x: v14) * (float)v13) * (float)0.25;
  *(double *)&v15 = 1.178097248077393;
  v16 = (float)cos(x: v15);
  *(double *)&v17 = 0.3926990926265717;
  *((double *)&v18 + 1) = (float)((float)((float)cos(x: v17) * (float)v16) * (float)0.25);
  *(double *)&v18 = 0.7853981852531433;
  tab_f_26[5] = -*((double *)&v18 + 1);
  v19 = (float)cos(x: v18);
  *(double *)&v20 = 0.3926990926265717;
  v22 = (float)((float)((float)cos(x: v20) * (float)v19) * (float)0.25);
  *(double *)&v21 = 0.3926990926265717;
  tab_f_26[6] = -v22;
  v23 = (float)cos(x: v21);
  *(double *)&v24 = 0.3926990926265717;
  tab_f_26[7] = (float)((float)cos(x: v24) * (float)v23) * (float)0.25;
  *(double *)&v25 = 0.7853981852531433;
  v26 = (float)cos(x: v25);
  *(double *)&v27 = 0.3926990926265717;
  tab_f_26[8] = (float)((float)cos(x: v27) * (float)v26) * (float)0.25;
  *(double *)&v28 = 1.178097248077393;
  v29 = (float)cos(x: v28);
  *(double *)&v30 = 0.3926990926265717;
  tab_f_26[9] = (float)((float)cos(x: v30) * (float)v29) * (float)0.25;
  *(double *)&v31 = 0.7853981852531433;
  v32 = (float)cos(x: v31);
  *(double *)&v33 = 0.3926990926265717;
  v35 = (float)((float)((float)cos(x: v33) * (float)v32) * (float)0.25);
  *(double *)&v34 = 0.3926990926265717;
  tab_f_26[10] = -v35;
  v36 = (float)cos(x: v34);
  *(double *)&v37 = 0.3926990926265717;
  v38 = cos(x: v37);
  *((double *)&v39 + 1) = (float)v38;
  v40 = (float)((float)((float)v38 * (float)v36) * (float)0.25);
  *(double *)&v39 = 0.7853981852531433;
  tab_f_26[11] = -v40;
  v41 = (float)cos(x: v39);
  *(double *)&v42 = 0.3926990926265717;
  tab_f_26[12] = (float)((float)cos(x: v42) * (float)v41) * (float)0.25;
  *(double *)&v43 = 0.3926990926265717;
  v44 = (float)cos(x: v43);
  *(double *)&v45 = 0.3926990926265717;
  v47 = (float)((float)((float)cos(x: v45) * (float)v44) * (float)0.25);
  *(double *)&v46 = 0.7853981852531433;
  tab_f_26[13] = -v47;
  v48 = (float)cos(x: v46);
  *(double *)&v49 = 0.3926990926265717;
  tab_f_26[14] = (float)((float)cos(x: v49) * (float)v48) * (float)0.25;
  *(double *)&v50 = 1.178097248077393;
  v51 = (float)cos(x: v50);
  *(double *)&v52 = 0.3926990926265717;
  v54 = (float)((float)((float)cos(x: v52) * (float)v51) * (float)0.25);
  *(double *)&v53 = 0.1963495463132858;
  tab_f_26[15] = -v54;
  v55 = (float)cos(x: v53);
  *(double *)&v56 = 0.3926990926265717;
  v57 = cos(x: v56);
  *((double *)&v58 + 1) = (float)v57;
  tab_f_26[16] = (float)((float)v57 * (float)v55) * (float)0.25;
  *(double *)&v58 = 0.5890486240386963;
  v59 = (float)cos(x: v58);
  *(double *)&v60 = 0.3926990926265717;
  tab_f_26[17] = (float)((float)cos(x: v60) * (float)v59) * (float)0.25;
  *(double *)&v61 = 0.9817477464675903;
  v62 = (float)cos(x: v61);
  *(double *)&v63 = 0.3926990926265717;
  tab_f_26[18] = (float)((float)cos(x: v63) * (float)v62) * (float)0.25;
  *(double *)&v64 = 1.374446868896484;
  v65 = (float)cos(x: v64);
  *(double *)&v66 = 0.3926990926265717;
  tab_f_26[19] = (float)((float)cos(x: v66) * (float)v65) * (float)0.25;
  *(double *)&v67 = 0.9817477464675903;
  v68 = (float)cos(x: v67);
  *(double *)&v69 = 0.3926990926265717;
  tab_f_26[20] = (float)((float)cos(x: v69) * (float)v68) * (float)0.25;
  *(double *)&v70 = 0.1963495463132858;
  v71 = (float)cos(x: v70);
  *(double *)&v72 = 0.3926990926265717;
  v74 = (float)((float)((float)cos(x: v72) * (float)v71) * (float)0.25);
  *(double *)&v73 = 1.374446868896484;
  tab_f_26[21] = -v74;
  v75 = (float)cos(x: v73);
  *(double *)&v76 = 0.3926990926265717;
  v77 = cos(x: v76);
  *((double *)&v78 + 1) = (float)v77;
  tab_f_26[22] = (float)((float)v77 * (float)v75) * (float)0.25;
  *(double *)&v78 = 0.5890486240386963;
  v79 = (float)cos(x: v78);
  *(double *)&v80 = 0.3926990926265717;
  tab_f_26[23] = (float)((float)cos(x: v80) * (float)v79) * (float)0.25;
  *(double *)&v81 = 0.5890486240386963;
  v82 = (float)cos(x: v81);
  *(double *)&v83 = 0.3926990926265717;
  tab_f_26[24] = (float)((float)cos(x: v83) * (float)v82) * (float)0.25;
  *(double *)&v84 = 1.374446868896484;
  v85 = (float)cos(x: v84);
  *(double *)&v86 = 0.3926990926265717;
  v88 = (float)((float)((float)cos(x: v86) * (float)v85) * (float)0.25);
  *(double *)&v87 = 0.1963495463132858;
  tab_f_26[25] = -v88;
  v89 = (float)cos(x: v87);
  *(double *)&v90 = 0.3926990926265717;
  v92 = (float)((float)((float)cos(x: v90) * (float)v89) * (float)0.25);
  *(double *)&v91 = 0.9817477464675903;
  tab_f_26[26] = -v92;
  v93 = (float)cos(x: v91);
  *(double *)&v94 = 0.3926990926265717;
  v95 = cos(x: v94);
  *((double *)&v96 + 1) = (float)((float)v95 * (float)v93);
  v97 = (float)((float)((float)v95 * (float)v93) * (float)0.25);
  *(double *)&v96 = 1.374446868896484;
  tab_f_26[27] = -v97;
  v98 = (float)cos(x: v96);
  *(double *)&v99 = 0.3926990926265717;
  tab_f_26[28] = (float)((float)cos(x: v99) * (float)v98) * (float)0.25;
  *(double *)&v100 = 0.9817477464675903;
  v101 = (float)cos(x: v100);
  *(double *)&v102 = 0.3926990926265717;
  v104 = (float)((float)((float)cos(x: v102) * (float)v101) * (float)0.25);
  *(double *)&v103 = 0.5890486240386963;
  tab_f_26[29] = -v104;
  v105 = (float)cos(x: v103);
  *(double *)&v106 = 0.3926990926265717;
  tab_f_26[30] = (float)((float)cos(x: v106) * (float)v105) * (float)0.25;
  *(double *)&v107 = 0.1963495463132858;
  v108 = (float)cos(x: v107);
  *(double *)&v109 = 0.3926990926265717;
  tab_f_26[31] = -(float)((float)((float)cos(x: v109) * (float)v108) * (float)0.25);
}


// ========================================================================
// `dynamic initializer for 'tab_f_35''
// EA  : 0x8334D440
// RVA : 0x0134D440
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\baredct\fdct_ap922_float.cpp
// ========================================================================

void __fastcall _dynamic_initializer_for__tab_f_35__(long double a1)
{
  double v1; // fp27
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp27
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp26
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp26
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp26
  long double v14; // fp2
  long double v15; // fp2
  double v16; // fp26
  long double v17; // fp2
  long double v18; // fp2
  double v19; // fp26
  long double v20; // fp2
  long double v21; // fp2
  double v22; // fp12
  double v23; // fp26
  long double v24; // fp2
  long double v25; // fp2
  double v26; // fp26
  long double v27; // fp2
  long double v28; // fp2
  double v29; // fp26
  long double v30; // fp2
  long double v31; // fp2
  double v32; // fp26
  long double v33; // fp2
  long double v34; // fp2
  double v35; // fp3
  double v36; // fp26
  long double v37; // fp2
  double v38; // fp1
  long double v39; // fp2
  double v40; // fp13
  double v41; // fp26
  long double v42; // fp2
  long double v43; // fp2
  double v44; // fp28
  long double v45; // fp2
  long double v46; // fp2
  double v47; // fp8
  double v48; // fp29
  long double v49; // fp2
  long double v50; // fp2
  double v51; // fp28
  long double v52; // fp2
  long double v53; // fp2
  double v54; // fp3
  double v55; // fp28
  long double v56; // fp2
  double v57; // fp1
  long double v58; // fp2
  double v59; // fp27
  long double v60; // fp2
  long double v61; // fp2
  double v62; // fp26
  long double v63; // fp2
  long double v64; // fp2
  double v65; // fp26
  long double v66; // fp2
  long double v67; // fp2
  double v68; // fp26
  long double v69; // fp2
  long double v70; // fp2
  double v71; // fp26
  long double v72; // fp2
  long double v73; // fp2
  double v74; // fp3
  double v75; // fp26
  long double v76; // fp2
  double v77; // fp1
  long double v78; // fp2
  double v79; // fp26
  long double v80; // fp2
  long double v81; // fp2
  double v82; // fp26
  long double v83; // fp2
  long double v84; // fp2
  double v85; // fp26
  long double v86; // fp2
  long double v87; // fp2
  double v88; // fp7
  double v89; // fp26
  long double v90; // fp2
  long double v91; // fp2
  double v92; // fp4
  double v93; // fp26
  long double v94; // fp2
  double v95; // fp1
  long double v96; // fp2
  double v97; // fp0
  double v98; // fp27
  long double v99; // fp2
  long double v100; // fp2
  double v101; // fp28
  long double v102; // fp2
  long double v103; // fp2
  double v104; // fp9
  double v105; // fp28
  long double v106; // fp2
  long double v107; // fp2
  double v108; // fp29
  long double v109; // fp2

  *(double *)&a1 = 0.7853981852531433;
  v1 = (float)cos(x: a1);
  *(double *)&v2 = 0.5890486240386963;
  tab_f_35[0] = (float)((float)cos(x: v2) * (float)v1) * (float)0.25;
  *(double *)&v3 = 0.3926990926265717;
  v4 = (float)cos(x: v3);
  *(double *)&v5 = 0.5890486240386963;
  tab_f_35[1] = (float)((float)cos(x: v5) * (float)v4) * (float)0.25;
  *(double *)&v6 = 0.7853981852531433;
  v7 = (float)cos(x: v6);
  *(double *)&v8 = 0.5890486240386963;
  tab_f_35[2] = (float)((float)cos(x: v8) * (float)v7) * (float)0.25;
  *(double *)&v9 = 1.178097248077393;
  v10 = (float)cos(x: v9);
  *(double *)&v11 = 0.5890486240386963;
  tab_f_35[3] = (float)((float)cos(x: v11) * (float)v10) * (float)0.25;
  *(double *)&v12 = 0.7853981852531433;
  v13 = (float)cos(x: v12);
  *(double *)&v14 = 0.5890486240386963;
  tab_f_35[4] = (float)((float)cos(x: v14) * (float)v13) * (float)0.25;
  *(double *)&v15 = 1.178097248077393;
  v16 = (float)cos(x: v15);
  *(double *)&v17 = 0.5890486240386963;
  *((double *)&v18 + 1) = (float)((float)((float)cos(x: v17) * (float)v16) * (float)0.25);
  *(double *)&v18 = 0.7853981852531433;
  tab_f_35[5] = -*((double *)&v18 + 1);
  v19 = (float)cos(x: v18);
  *(double *)&v20 = 0.5890486240386963;
  v22 = (float)((float)((float)cos(x: v20) * (float)v19) * (float)0.25);
  *(double *)&v21 = 0.3926990926265717;
  tab_f_35[6] = -v22;
  v23 = (float)cos(x: v21);
  *(double *)&v24 = 0.5890486240386963;
  tab_f_35[7] = (float)((float)cos(x: v24) * (float)v23) * (float)0.25;
  *(double *)&v25 = 0.7853981852531433;
  v26 = (float)cos(x: v25);
  *(double *)&v27 = 0.5890486240386963;
  tab_f_35[8] = (float)((float)cos(x: v27) * (float)v26) * (float)0.25;
  *(double *)&v28 = 1.178097248077393;
  v29 = (float)cos(x: v28);
  *(double *)&v30 = 0.5890486240386963;
  tab_f_35[9] = (float)((float)cos(x: v30) * (float)v29) * (float)0.25;
  *(double *)&v31 = 0.7853981852531433;
  v32 = (float)cos(x: v31);
  *(double *)&v33 = 0.5890486240386963;
  v35 = (float)((float)((float)cos(x: v33) * (float)v32) * (float)0.25);
  *(double *)&v34 = 0.3926990926265717;
  tab_f_35[10] = -v35;
  v36 = (float)cos(x: v34);
  *(double *)&v37 = 0.5890486240386963;
  v38 = cos(x: v37);
  *((double *)&v39 + 1) = (float)v38;
  v40 = (float)((float)((float)v38 * (float)v36) * (float)0.25);
  *(double *)&v39 = 0.7853981852531433;
  tab_f_35[11] = -v40;
  v41 = (float)cos(x: v39);
  *(double *)&v42 = 0.5890486240386963;
  tab_f_35[12] = (float)((float)cos(x: v42) * (float)v41) * (float)0.25;
  *(double *)&v43 = 0.3926990926265717;
  v44 = (float)cos(x: v43);
  *(double *)&v45 = 0.5890486240386963;
  v47 = (float)((float)((float)cos(x: v45) * (float)v44) * (float)0.25);
  *(double *)&v46 = 0.7853981852531433;
  tab_f_35[13] = -v47;
  v48 = (float)cos(x: v46);
  *(double *)&v49 = 0.5890486240386963;
  tab_f_35[14] = (float)((float)cos(x: v49) * (float)v48) * (float)0.25;
  *(double *)&v50 = 1.178097248077393;
  v51 = (float)cos(x: v50);
  *(double *)&v52 = 0.5890486240386963;
  v54 = (float)((float)((float)cos(x: v52) * (float)v51) * (float)0.25);
  *(double *)&v53 = 0.1963495463132858;
  tab_f_35[15] = -v54;
  v55 = (float)cos(x: v53);
  *(double *)&v56 = 0.5890486240386963;
  v57 = cos(x: v56);
  *((double *)&v58 + 1) = (float)v57;
  tab_f_35[16] = (float)((float)v57 * (float)v55) * (float)0.25;
  *(double *)&v58 = 0.5890486240386963;
  v59 = (float)cos(x: v58);
  *(double *)&v60 = 0.5890486240386963;
  tab_f_35[17] = (float)((float)cos(x: v60) * (float)v59) * (float)0.25;
  *(double *)&v61 = 0.9817477464675903;
  v62 = (float)cos(x: v61);
  *(double *)&v63 = 0.5890486240386963;
  tab_f_35[18] = (float)((float)cos(x: v63) * (float)v62) * (float)0.25;
  *(double *)&v64 = 1.374446868896484;
  v65 = (float)cos(x: v64);
  *(double *)&v66 = 0.5890486240386963;
  tab_f_35[19] = (float)((float)cos(x: v66) * (float)v65) * (float)0.25;
  *(double *)&v67 = 0.9817477464675903;
  v68 = (float)cos(x: v67);
  *(double *)&v69 = 0.5890486240386963;
  tab_f_35[20] = (float)((float)cos(x: v69) * (float)v68) * (float)0.25;
  *(double *)&v70 = 0.1963495463132858;
  v71 = (float)cos(x: v70);
  *(double *)&v72 = 0.5890486240386963;
  v74 = (float)((float)((float)cos(x: v72) * (float)v71) * (float)0.25);
  *(double *)&v73 = 1.374446868896484;
  tab_f_35[21] = -v74;
  v75 = (float)cos(x: v73);
  *(double *)&v76 = 0.5890486240386963;
  v77 = cos(x: v76);
  *((double *)&v78 + 1) = (float)v77;
  tab_f_35[22] = (float)((float)v77 * (float)v75) * (float)0.25;
  *(double *)&v78 = 0.5890486240386963;
  v79 = (float)cos(x: v78);
  *(double *)&v80 = 0.5890486240386963;
  tab_f_35[23] = (float)((float)cos(x: v80) * (float)v79) * (float)0.25;
  *(double *)&v81 = 0.5890486240386963;
  v82 = (float)cos(x: v81);
  *(double *)&v83 = 0.5890486240386963;
  tab_f_35[24] = (float)((float)cos(x: v83) * (float)v82) * (float)0.25;
  *(double *)&v84 = 1.374446868896484;
  v85 = (float)cos(x: v84);
  *(double *)&v86 = 0.5890486240386963;
  v88 = (float)((float)((float)cos(x: v86) * (float)v85) * (float)0.25);
  *(double *)&v87 = 0.1963495463132858;
  tab_f_35[25] = -v88;
  v89 = (float)cos(x: v87);
  *(double *)&v90 = 0.5890486240386963;
  v92 = (float)((float)((float)cos(x: v90) * (float)v89) * (float)0.25);
  *(double *)&v91 = 0.9817477464675903;
  tab_f_35[26] = -v92;
  v93 = (float)cos(x: v91);
  *(double *)&v94 = 0.5890486240386963;
  v95 = cos(x: v94);
  *((double *)&v96 + 1) = (float)((float)v95 * (float)v93);
  v97 = (float)((float)((float)v95 * (float)v93) * (float)0.25);
  *(double *)&v96 = 1.374446868896484;
  tab_f_35[27] = -v97;
  v98 = (float)cos(x: v96);
  *(double *)&v99 = 0.5890486240386963;
  tab_f_35[28] = (float)((float)cos(x: v99) * (float)v98) * (float)0.25;
  *(double *)&v100 = 0.9817477464675903;
  v101 = (float)cos(x: v100);
  *(double *)&v102 = 0.5890486240386963;
  v104 = (float)((float)((float)cos(x: v102) * (float)v101) * (float)0.25);
  *(double *)&v103 = 0.5890486240386963;
  tab_f_35[29] = -v104;
  v105 = (float)cos(x: v103);
  *(double *)&v106 = 0.5890486240386963;
  tab_f_35[30] = (float)((float)cos(x: v106) * (float)v105) * (float)0.25;
  *(double *)&v107 = 0.1963495463132858;
  v108 = (float)cos(x: v107);
  *(double *)&v109 = 0.5890486240386963;
  tab_f_35[31] = -(float)((float)((float)cos(x: v109) * (float)v108) * (float)0.25);
}

