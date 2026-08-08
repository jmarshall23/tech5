
// ========================================================================
// ?jpeg_idct_ifast@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
// EA  : 0x8323BF60
// RVA : 0x0123BF60
// PDB : w:\tech5\libs\jpeg\jidctfst.cpp
// ========================================================================

void __fastcall jpeg_idct_ifast(
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
  __int16 v11; // r5
  int v12; // r4
  int v13; // r5
  int v14; // r28
  int v15; // r30
  int v16; // r24
  int v17; // r25
  int v18; // r27
  __int16 v19; // r31
  int v20; // r26
  int v21; // r23
  int v22; // r22
  int v23; // r21
  int v24; // r30
  int v25; // r20
  int v26; // r19
  int v27; // r29
  int v28; // r30
  int v29; // r4
  int v30; // r28
  int v31; // r27
  int v32; // r3
  int v33; // r31
  int v34; // r5
  int v35; // r4
  int v36; // r5
  int v37; // r30
  int v38; // r29
  int v39; // r4
  int v40; // r24
  int v41; // r29
  int v42; // r27
  int v43; // r28
  int v44; // r3
  int v45; // r26
  int v46; // r28
  int v47; // r29
  char *v48; // r10
  int j; // ctr
  int v51; // r26
  unsigned __int8 *v52; // r11
  int v53; // r9
  unsigned __int8 v54; // r4
  int v55; // r9
  int v56; // r6
  int v57; // r5
  int v58; // r4
  int v59; // r30
  int v60; // r27
  int v61; // r31
  int v62; // r3
  int v63; // r29
  int v64; // r9
  int v65; // r28
  int v66; // r3
  int v67; // r6
  int v68; // r6
  int v69; // r31
  int v70; // r24
  int v71; // r29
  int v72; // r26
  int v73; // r23
  int v74; // r5
  int v75; // r31
  char v76; // [sp+0h] [-174h] BYREF
  char back_chain; // [sp+60h] [-114h] BYREF

  v5 = coef_block + 55;
  v6 = cinfo->max_h_samp_factor + 128;
  v7 = (char *)compptr->dct_table + 220;
  p_back_chain = &back_chain;
  for ( i = 8; i != 0; --i )
  {
    v10 = *(v5 - 47);
    if ( v10 != 0
      || *(v5 - 39) != 0
      || *(v5 - 31) != 0
      || *(v5 - 23) != 0
      || *(v5 - 15) != 0
      || *(v5 - 7) != 0
      || v5[1] != 0 )
    {
      v14 = *(v5 - 39);
      v15 = *(v5 - 55);
      v16 = *(v5 - 31);
      v17 = *(v5 - 23);
      v18 = *(v5 - 7);
      v19 = *(v5 - 15);
      ++v5;
      v20 = v15 * *(v7 - 55);
      v21 = *(v7 - 39);
      v22 = *(v7 - 23);
      v23 = *(v7 - 7);
      v24 = *(v7 - 47);
      v25 = *(v7 - 31);
      v26 = *(v7 - 15);
      v27 = *v5 * *++v7;
      v28 = v10 * v24;
      v29 = v19 * v26;
      v30 = v14 * v21;
      v31 = v18 * v23;
      v32 = v29 - v16 * v25;
      v33 = v28 - v27;
      v34 = v29 + v16 * v25;
      v35 = v27 + v28;
      v37 = (473 * (v28 - v27 + v32)) >> 8;
      v38 = 362 * (v35 - v34);
      v36 = v35 + v34;
      v39 = v31 + v30;
      v40 = v38 >> 8;
      v41 = v17 * v22 + v20;
      v42 = ((362 * (v30 - v31)) >> 8) - (v31 + v30);
      v43 = v20 - v17 * v22;
      v44 = ((-669 * v32) >> 8) - v36 + v37;
      v45 = v41 - v39;
      *((_DWORD *)p_back_chain - 23) = v36 + v39 + v41;
      *((_DWORD *)p_back_chain + 33) = v39 + v41 - v36;
      v47 = ((277 * v33) >> 8) - v37 + v40 - v44;
      *((_DWORD *)p_back_chain - 15) = v44 + v42 + v43;
      *((_DWORD *)p_back_chain + 25) = v42 + v43 - v44;
      v46 = v43 - v42;
      *((_DWORD *)p_back_chain - 7) = v40 - v44 + v46;
      *((_DWORD *)p_back_chain + 17) = v46 - (v40 - v44);
      *((_DWORD *)p_back_chain + 9) = v47 + v45;
      p_back_chain += 4;
      *(_DWORD *)p_back_chain = v45 - v47;
    }
    else
    {
      v11 = *(v5 - 55);
      ++v5;
      v12 = *(v7 - 55);
      ++v7;
      v13 = v11 * v12;
      *((_DWORD *)p_back_chain - 23) = v13;
      *((_DWORD *)p_back_chain - 15) = v13;
      *((_DWORD *)p_back_chain - 7) = v13;
      *((_DWORD *)p_back_chain + 1) = v13;
      *((_DWORD *)p_back_chain + 9) = v13;
      *((_DWORD *)p_back_chain + 17) = v13;
      *((_DWORD *)p_back_chain + 25) = v13;
      *((_DWORD *)p_back_chain + 33) = v13;
      p_back_chain += 4;
    }
  }
  v48 = &v76;
  for ( j = 8; j != 0; --j )
  {
    v51 = *((_DWORD *)v48 + 2);
    v52 = &(*output_buf)[output_col];
    if ( v51 != 0
      || *((_DWORD *)v48 + 3) != 0
      || *((_DWORD *)v48 + 4) != 0
      || *((_DWORD *)v48 + 5) != 0
      || *((_DWORD *)v48 + 6) != 0
      || *((_DWORD *)v48 + 7) != 0
      || *((_DWORD *)v48 + 8) != 0 )
    {
      v55 = *((_DWORD *)v48 + 5);
      v56 = *((_DWORD *)v48 + 1);
      v57 = *((_DWORD *)v48 + 3);
      v58 = v56 + v55;
      v59 = *((_DWORD *)v48 + 6);
      v60 = v56 - v55;
      v61 = *((_DWORD *)v48 + 4);
      v62 = *((_DWORD *)v48 + 7);
      v48 += 32;
      v63 = v59 - v61;
      v64 = v62 + v57;
      v65 = v51 - *(_DWORD *)v48;
      v67 = *(_DWORD *)v48 + v51;
      v70 = (362 * (v67 - (v59 + v61))) >> 8;
      v68 = v67 + v59 + v61;
      v69 = (473 * (v65 + v59 - v61)) >> 8;
      v72 = ((v68 + v62 + v57 + v58) >> 5) & 0x3FF;
      v73 = v62 + v57 + v58 - v68;
      v66 = v57 - v62;
      v74 = ((-669 * v63) >> 8) - v68 + v69;
      v71 = ((362 * v66) >> 8) - v64;
      *v52 = *(_BYTE *)(v72 + v6);
      v75 = ((277 * v65) >> 8) - v69;
      v52[7] = *(_BYTE *)(((v73 >> 5) & 0x3FF) + v6);
      v52[1] = *(_BYTE *)((((v74 + v71 + v60) >> 5) & 0x3FF) + v6);
      v52[6] = *(_BYTE *)((((v71 + v60 - v74) >> 5) & 0x3FF) + v6);
      v52[2] = *(_BYTE *)((((v70 - v74 + v60 - v71) >> 5) & 0x3FF) + v6);
      v52[5] = *(_BYTE *)((((v60 - v71 - (v70 - v74)) >> 5) & 0x3FF) + v6);
      v52[4] = *(_BYTE *)((((v75 + v70 - v74 + v58 - v64) >> 5) & 0x3FF) + v6);
      v52[3] = *(_BYTE *)((((v58 - v64 - (v75 + v70 - v74)) >> 5) & 0x3FF) + v6);
    }
    else
    {
      v53 = *((_DWORD *)v48 + 1);
      v48 += 32;
      v54 = *(_BYTE *)(((v53 >> 5) & 0x3FF) + v6);
      *v52 = v54;
      v52[1] = v54;
      v52[2] = v54;
      v52[3] = v54;
      v52[4] = v54;
      v52[5] = v54;
      v52[6] = v54;
      v52[7] = v54;
    }
    ++output_buf;
  }
}

