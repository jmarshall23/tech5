
// ========================================================================
// ?jpeg_idct_float@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
// EA  : 0x8323C340
// RVA : 0x0123C340
// PDB : w:\tech5\libs\jpeg\jidctflt.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall jpeg_idct_float(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  int v5; // r2 OVERLAPPED
  __int16 *v6; // r10
  int v7; // ctr
  int v8; // r9
  float *v9; // r8
  float *v10; // r11
  __int16 v11; // r5
  double v12; // fp13
  int v13; // r3
  int v14; // r3
  __int64 v15; // r31
  double v16; // fp9
  int v17; // r3
  __int16 v18; // r28
  __int64 v19; // r4
  __int64 v20; // fp1
  __int64 v21; // fp8
  __int16 v22; // r29
  __int64 v23; // fp7
  double v24; // fp28
  double v25; // fp9
  double v26; // fp1
  double v27; // fp5
  double v28; // fp9
  double v29; // fp3
  double v30; // fp2
  double v31; // fp1
  double v32; // fp8
  double v33; // fp5
  double v34; // fp13
  double v35; // fp4
  double v36; // fp1
  double v37; // fp6
  double v38; // fp3
  double v39; // fp9
  double v40; // fp7
  float *v41; // r11
  unsigned __int8 **v42; // r6
  int i; // ctr
  double v44; // fp5
  double v45; // fp7
  double v46; // fp3
  double v47; // fp1
  double v48; // fp9
  double v49; // fp8
  double v50; // fp6
  double v51; // fp4
  unsigned __int8 *v52; // r10
  double v53; // fp2
  double v54; // fp9
  double v55; // fp7
  double v56; // fp9
  int v57; // r4
  double v58; // fp3
  double v59; // fp2
  double v60; // fp8
  int v61; // r5
  int v62; // r8
  int v63; // [sp+Ch] [-1A4h]
  __int64 v64; // [sp+10h] [-1A0h]
  _QWORD v65[15]; // [sp+30h] [-180h] BYREF
  char v66; // [sp+ACh] [-104h] BYREF

  v6 = coef_block + 55;
  v7 = 8;
  v8 = cinfo->max_h_samp_factor + 128;
  v9 = (float *)((char *)compptr->dct_table + 220);
  v10 = (float *)&v66;
  do
  {
    if ( *(v6 - 47) != 0
      || *(v6 - 39) != 0
      || *(v6 - 31) != 0
      || *(v6 - 23) != 0
      || *(v6 - 15) != 0
      || *(v6 - 7) != 0
      || v6[1] != 0 )
    {
      v14 = *(v6 - 47);
      HIDWORD(v15) = (unsigned __int16)*(v6 - 31);
      v16 = *(v9 - 39);
      v64 = *(_QWORD *)(&v5 - 1);
      v17 = SWORD1(v15);
      v18 = *(v6 - 39);
      LODWORD(v19) = *(v6 - 7);
      LODWORD(v65[0]) = SWORD1(v15);
      v20 = *(_QWORD *)(&v5 - 1);
      HIDWORD(v19) = v18;
      v21 = v19;
      LOWORD(v15) = *(v6 - 23);
      LODWORD(v19) = *(v6 - 55);
      v22 = *(v6 - 15);
      v65[1] = v19;
      LODWORD(v15) = (__int16)v15;
      v23 = v19;
      LODWORD(v19) = v22;
      ++v6;
      v24 = *(v9 - 47);
      v25 = (float)((float)*(__int64 *)(&v5 - 1) * (float)v16);
      v26 = (float)((float)v20 * *(v9 - 31));
      v27 = (float)((float)((float)v21 * *(v9 - 7)) + (float)v25);
      v29 = (float)((float)((float)v19 * *(v9 - 15)) + (float)v26);
      v30 = (float)((float)((float)v19 * *(v9 - 15)) - (float)v26);
      LODWORD(v19) = *v6;
      v31 = (float)((float)((float)((float)v25 - (float)((float)v21 * *(v9 - 7))) * (float)1.4142135)
                  - (float)((float)((float)v21 * *(v9 - 7)) + (float)v25));
      v32 = (float)((float)((float)((float)v21 * *(v9 - 7)) + (float)v25)
                  + (float)((float)((float)v15 * *(v9 - 23)) + (float)((float)v23 * *(v9 - 55))));
      v28 = (float)((float)((float)v23 * *(v9 - 55)) - (float)((float)v15 * *(v9 - 23)));
      v33 = (float)((float)((float)((float)v15 * *(v9 - 23)) + (float)((float)v23 * *(v9 - 55))) - (float)v27);
      v34 = (float)((float)((float)v64 * (float)v24) - (float)((float)v19 * *++v9));
      v35 = (float)((float)v31 + (float)v28);
      v36 = (float)((float)v28 - (float)v31);
      v37 = (float)((float)((float)((float)v19 * *v9) + (float)((float)v64 * (float)v24)) + (float)v29);
      v39 = (float)((float)((float)((float)((float)v64 * (float)v24) - (float)((float)v19 * *v9)) + (float)v30)
                  * (float)1.847759);
      v40 = (float)((float)((float)((float)((float)v19 * *v9) + (float)((float)v64 * (float)v24)) + (float)v29)
                  + (float)v32);
      v38 = (float)((float)((float)((float)v19 * *v9) + (float)((float)v64 * (float)v24)) - (float)v29);
      *(v10 - 23) = v40;
      v10[33] = (float)v32 - (float)v37;
      *(v10 - 15) = (float)((float)-(float)((float)((float)v30 * (float)2.613126) - (float)v39) - (float)v37)
                  + (float)v35;
      v10[25] = (float)v35 - (float)((float)-(float)((float)((float)v30 * (float)2.613126) - (float)v39) - (float)v37);
      *(v10 - 7) = (float)((float)((float)v38 * (float)1.4142135)
                         - (float)((float)-(float)((float)((float)v30 * (float)2.613126) - (float)v39) - (float)v37))
                 + (float)v36;
      v10[17] = (float)v36
              - (float)((float)((float)v38 * (float)1.4142135)
                      - (float)((float)-(float)((float)((float)v30 * (float)2.613126) - (float)v39) - (float)v37));
      v10[9] = (float)((float)((float)((float)v34 * (float)1.0823922) - (float)v39)
                     + (float)((float)((float)v38 * (float)1.4142135)
                             - (float)((float)-(float)((float)((float)v30 * (float)2.613126) - (float)v39) - (float)v37)))
             + (float)v33;
      *++v10 = (float)v33
             - (float)((float)((float)((float)v34 * (float)1.0823922) - (float)v39)
                     + (float)((float)((float)v38 * (float)1.4142135)
                             - (float)((float)-(float)((float)((float)v30 * (float)2.613126) - (float)v39) - (float)v37)));
    }
    else
    {
      v11 = *(v6 - 55);
      v12 = *(v9 - 55);
      ++v6;
      ++v9;
      v13 = v11;
      v65[2] = *(_QWORD *)(&v5 - 1);
      *(v10 - 23) = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      *(v10 - 15) = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      *(v10 - 7) = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      v10[1] = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      v10[9] = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      v10[17] = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      v10[25] = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      v10[33] = (float)*(__int64 *)(&v5 - 1) * (float)v12;
      ++v10;
    }
    --v7;
  }
  while ( v7 != 0 );
  v41 = (float *)v65 + 1;
  v42 = output_buf - 1;
  for ( i = 8; i != 0; --i )
  {
    ++v42;
    v44 = (float)(v41[7] - v41[11]);
    v45 = (float)(v41[7] + v41[11]);
    v46 = (float)(v41[13] + v41[9]);
    v47 = (float)(v41[9] - v41[13]);
    v48 = v41[14];
    v49 = (float)(v41[10] + v41[12]);
    v50 = (float)(v41[12] - v41[10]);
    v41 += 8;
    v51 = (float)((float)v48 + *v41);
    v52 = &(*v42)[output_col];
    v53 = (float)(*v41 - (float)v48);
    v63 = (int)(float)((float)((float)((float)v48 + *v41) + (float)v49) + (float)((float)v46 + (float)v45));
    v57 = (int)(float)((float)((float)v46 + (float)v45) - (float)((float)((float)v48 + *v41) + (float)v49));
    v54 = (float)((float)((float)v47 * (float)1.4142135) - (float)v46);
    v55 = (float)((float)v45 - (float)v46);
    v58 = (float)((float)-(float)((float)((float)v50 * (float)2.613126)
                                - (float)((float)((float)v53 + (float)v50) * (float)1.847759))
                - (float)((float)v51 + (float)v49));
    *v52 = *(_BYTE *)((((v63 + 4) >> 3) & 0x3FF) + v8);
    v60 = (float)((float)((float)((float)v51 - (float)v49) * (float)1.4142135)
                - (float)((float)-(float)((float)((float)v50 * (float)2.613126)
                                        - (float)((float)((float)v53 + (float)v50) * (float)1.847759))
                        - (float)((float)v51 + (float)v49)));
    v59 = (float)((float)((float)v53 * (float)1.0823922) - (float)((float)((float)v53 + (float)v50) * (float)1.847759));
    v52[7] = *(_BYTE *)((((v57 + 4) >> 3) & 0x3FF) + v8);
    v61 = (int)(float)((float)((float)v54 + (float)v44) - (float)v58);
    v62 = (int)(float)((float)v58 + (float)((float)v54 + (float)v44));
    v56 = (float)((float)v44 - (float)v54);
    v52[1] = *(_BYTE *)((((v62 + 4) >> 3) & 0x3FF) + v8);
    v52[6] = *(_BYTE *)((((v61 + 4) >> 3) & 0x3FF) + v8);
    v52[2] = *(_BYTE *)(((((int)(float)((float)v60 + (float)v56) + 4) >> 3) & 0x3FF) + v8);
    v52[5] = *(_BYTE *)(((((int)(float)((float)v56 - (float)v60) + 4) >> 3) & 0x3FF) + v8);
    v52[4] = *(_BYTE *)(((((int)(float)((float)((float)v59 + (float)v60) + (float)v55) + 4) >> 3) & 0x3FF) + v8);
    v52[3] = *(_BYTE *)(((((int)(float)((float)v55 - (float)((float)v59 + (float)v60)) + 4) >> 3) & 0x3FF) + v8);
  }
}

