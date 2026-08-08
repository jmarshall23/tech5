
// ========================================================================
// ?jpeg_idct_islow@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
// EA  : 0x8323BAE0
// RVA : 0x0123BAE0
// PDB : w:\tech5\libs\jpeg\jidctint.cpp
// ========================================================================

void __fastcall jpeg_idct_islow(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  __int16 *v5; // r9
  int v6; // r8
  _DWORD *v7; // r10
  char *p_back_chain; // r11
  int i; // ctr
  __int16 v10; // r5
  int v11; // r30
  __int16 v12; // r5
  int v13; // r4
  int v14; // r4
  int v15; // r27
  int v16; // r26
  int v17; // r25
  __int16 v18; // r3
  __int16 v19; // r4
  int v20; // r28
  int v21; // r23
  int v22; // r22
  int v23; // r21
  int v24; // r31
  int v25; // r29
  int v26; // r20
  int v27; // r4
  int v28; // r3
  int v29; // r5
  int v30; // r31
  int v31; // r27
  int v32; // r25
  int v33; // r26
  int v34; // r19
  int v35; // r29
  int v36; // r24
  int v37; // r17
  int v38; // r16
  int v39; // r30
  int v40; // r25
  int v41; // r21
  int v42; // r5
  int v43; // r22
  int v44; // r30
  int v45; // r28
  int v46; // r3
  int v47; // r29
  int v48; // r30
  int v49; // r26
  int v50; // r31
  int v51; // r5
  char *v52; // r10
  int j; // ctr
  int v55; // r3
  unsigned __int8 *v56; // r11
  int v57; // r6
  unsigned __int8 v58; // r3
  int v59; // r4
  int v60; // r22
  int v61; // r5
  int v62; // r28
  int v63; // r27
  int v64; // r29
  int v65; // r26
  int v66; // r30
  int v67; // r19
  int v68; // r25
  int v69; // r31
  int v70; // r24
  int v71; // r3
  int v72; // r29
  int v73; // r23
  int v74; // r21
  int v75; // r22
  int v76; // r31
  int v77; // r29
  int v78; // r3
  int v79; // r31
  int v80; // r21
  int v81; // r29
  int v82; // r3
  int v83; // r6
  int v84; // r28
  int v85; // r30
  int v86; // r31
  int v87; // r3
  int v88; // r31
  int v89; // r27
  int v90; // r6
  int v91; // r5
  int v92; // r6
  char v93; // [sp+0h] [-1A4h] BYREF
  char back_chain; // [sp+90h] [-114h] BYREF

  v5 = coef_block + 23;
  v6 = cinfo->max_h_samp_factor + 128;
  v7 = (char *)compptr->dct_table + 28;
  p_back_chain = &back_chain;
  for ( i = 8; i != 0; --i )
  {
    v10 = *(v5 - 15);
    v11 = v10;
    if ( v10 != 0 || *(v5 - 7) != 0 || v5[1] != 0 || v5[9] != 0 || v5[17] != 0 || v5[25] != 0 || v5[33] != 0 )
    {
      v15 = v5[25];
      v16 = *(v5 - 23);
      v17 = v5[9];
      v18 = v5[17];
      v19 = v5[33];
      v20 = *(v5 - 7) * v7[9];
      ++v5;
      v21 = v7[41];
      v22 = *(v7 - 7);
      v23 = v7[25];
      v24 = v7[49];
      v25 = v7[33];
      v26 = v7[17];
      ++v7;
      v27 = v19 * v24;
      v29 = *v5 * v26;
      v30 = v18 * v25;
      v28 = v11 * *v7;
      v31 = v15 * v21;
      v32 = v17 * v23;
      v33 = v16 * v22;
      v34 = 9633 * (v30 + v28 + v27 + v29);
      v35 = 4433 * (v31 + v20);
      v36 = v34 - 3196 * (v30 + v28);
      v37 = 16069 * (v27 + v29);
      v38 = v33 - v32;
      v39 = (v32 + v33) << 13;
      v40 = v30 + v29;
      v41 = 25172 * v29;
      v42 = v39 + 6270 * v20 + v35;
      v43 = v39 - (6270 * v20 + v35);
      v44 = 12299 * v28 + v36 - 7373 * (v27 + v28);
      v45 = v35 - 15137 * v31;
      v40 *= -20995;
      v47 = v41 + v34 - v37 + v40;
      *((_DWORD *)p_back_chain - 31) = (v42 + v44 + 1024) >> 11;
      *((_DWORD *)p_back_chain + 25) = (v42 - v44 + 1024) >> 11;
      v48 = 2446 * v27 - 7373 * (v27 + v28);
      v46 = (v38 << 13) + v45;
      v49 = 16819 * v30 + v36;
      *((_DWORD *)p_back_chain - 23) = (v46 + v47 + 1024) >> 11;
      v50 = (v38 << 13) - v45;
      v51 = v48 + v34 - v37;
      *((_DWORD *)p_back_chain + 17) = (v46 - v47 + 1024) >> 11;
      *((_DWORD *)p_back_chain - 15) = (v50 + v49 + v40 + 1024) >> 11;
      *((_DWORD *)p_back_chain + 9) = (v50 - (v49 + v40) + 1024) >> 11;
      *((_DWORD *)p_back_chain - 7) = (v43 + v51 + 1024) >> 11;
      p_back_chain += 4;
      *(_DWORD *)p_back_chain = (v43 - v51 + 1024) >> 11;
    }
    else
    {
      v12 = *(v5 - 23);
      ++v5;
      v13 = *(v7 - 7);
      ++v7;
      v14 = 4 * v12 * v13;
      *((_DWORD *)p_back_chain - 31) = v14;
      *((_DWORD *)p_back_chain - 23) = v14;
      *((_DWORD *)p_back_chain - 15) = v14;
      *((_DWORD *)p_back_chain - 7) = v14;
      *((_DWORD *)p_back_chain + 1) = v14;
      *((_DWORD *)p_back_chain + 9) = v14;
      *((_DWORD *)p_back_chain + 17) = v14;
      *((_DWORD *)p_back_chain + 25) = v14;
      p_back_chain += 4;
    }
  }
  v52 = &v93;
  for ( j = 8; j != 0; --j )
  {
    v55 = *((_DWORD *)v52 + 6);
    v56 = &(*output_buf)[output_col];
    if ( v55 != 0
      || *((_DWORD *)v52 + 7) != 0
      || *((_DWORD *)v52 + 8) != 0
      || *((_DWORD *)v52 + 9) != 0
      || *((_DWORD *)v52 + 10) != 0
      || *((_DWORD *)v52 + 11) != 0
      || *((_DWORD *)v52 + 12) != 0 )
    {
      v59 = *((_DWORD *)v52 + 12);
      v60 = 12299 * v55;
      v61 = *((_DWORD *)v52 + 10);
      v62 = *((_DWORD *)v52 + 11);
      v63 = *((_DWORD *)v52 + 9);
      v64 = *((_DWORD *)v52 + 7);
      v65 = *((_DWORD *)v52 + 5);
      v52 += 32;
      v66 = v59 + *(_DWORD *)v52;
      v67 = 9633 * (v61 + v55 + v66);
      v68 = 4433 * (v62 + v64);
      v69 = v59 + v55;
      v70 = v67 - 3196 * (v61 + v55);
      v71 = 6270 * v64 + v68;
      v72 = (v65 + v63) << 13;
      v73 = -7373 * v69;
      v74 = v60 + v70;
      v75 = v72 - v71;
      v76 = v72 + v71;
      v77 = v72 + v71 + v74 + v73;
      v78 = v76 - (v74 + v73);
      v79 = ((v77 + 0x20000) >> 18) & 0x3FF;
      v80 = ((v78 + 0x20000) >> 18) & 0x3FF;
      v81 = v67 - 16069 * v66;
      v82 = v61 + *(_DWORD *)v52;
      v83 = 25172 * *(_DWORD *)v52;
      *v56 = *(_BYTE *)(v79 + v6);
      v85 = (v65 - v63) << 13;
      v86 = v68 - 15137 * v62;
      v84 = -20995 * v82;
      v87 = v83 + v81 - 20995 * v82;
      v56[7] = *(_BYTE *)(v80 + v6);
      v89 = v85 + v86 + v87 + 0x20000;
      v90 = v85 + v86 - v87;
      v88 = v85 - v86;
      v91 = 16819 * v61 + v70 + v84;
      v56[1] = *(_BYTE *)(((v89 >> 18) & 0x3FF) + v6);
      v56[6] = *(_BYTE *)((((v90 + 0x20000) >> 18) & 0x3FF) + v6);
      v92 = 2446 * v59 + v73 + v81;
      v56[2] = *(_BYTE *)((((v88 + v91 + 0x20000) >> 18) & 0x3FF) + v6);
      v56[5] = *(_BYTE *)((((v88 - v91 + 0x20000) >> 18) & 0x3FF) + v6);
      v56[3] = *(_BYTE *)((((v75 + v92 + 0x20000) >> 18) & 0x3FF) + v6);
      v58 = *(_BYTE *)((((v75 - v92 + 0x20000) >> 18) & 0x3FF) + v6);
    }
    else
    {
      v57 = *((_DWORD *)v52 + 5);
      v52 += 32;
      v58 = *(_BYTE *)((((v57 + 16) >> 5) & 0x3FF) + v6);
      *v56 = v58;
      v56[1] = v58;
      v56[2] = v58;
      v56[3] = v58;
      v56[5] = v58;
      v56[6] = v58;
      v56[7] = v58;
    }
    v56[4] = v58;
    ++output_buf;
  }
}

