
// ========================================================================
// ?jpeg_idct_4x4@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
// EA  : 0x8323C798
// RVA : 0x0123C798
// PDB : w:\tech5\libs\jpeg\jidctred.cpp
// ========================================================================

void __fastcall jpeg_idct_4x4(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // r11
  int v6; // r29
  int v7; // r30
  int v8; // ctr
  __int16 *v9; // r10
  int *p_back_chain; // r9
  int v11; // r8
  int v12; // r28
  int v13; // r27
  int v14; // r4
  int v15; // r25
  int v16; // r4
  int v17; // r3
  int v18; // r31
  int v19; // r5
  int v20; // r27
  int v21; // r3
  int v22; // r8
  int v23; // r4
  int v24; // r31
  int v25; // r5
  char *v26; // r11
  int i; // ctr
  int v29; // r31
  unsigned __int8 *v30; // r10
  int v31; // r9
  unsigned __int8 v32; // r5
  int v33; // r27
  int v34; // r30
  int v35; // r5
  int v36; // r4
  int v37; // r26
  int v38; // r6
  int v39; // r5
  int v40; // r4
  int v41; // r9
  char v42; // [sp+0h] [-104h] BYREF
  char back_chain; // [sp+34h] [-D0h] BYREF

  dct_table = compptr->dct_table;
  v6 = cinfo->max_h_samp_factor + 128;
  v7 = 8;
  v8 = 8;
  v9 = coef_block + 48;
  p_back_chain = (int *)&back_chain;
  do
  {
    if ( v7 != 4 )
    {
      if ( *(v9 - 40) != 0 || *(v9 - 32) != 0 || *(v9 - 24) != 0 || *(v9 - 8) != 0 || *v9 != 0 || v9[8] != 0 )
      {
        v12 = *(v9 - 24) * dct_table[24];
        v13 = dct_table[8] * *(v9 - 40);
        v14 = *(v9 - 8) * dct_table[40];
        v15 = v9[8] * dct_table[56];
        v17 = 11893 * v14 - 17799 * v12;
        v18 = 20995 * v13 + 7373 * v12 - 4926 * v14;
        v16 = 15137 * *(v9 - 32) * dct_table[16] - 6270 * *v9 * dct_table[48];
        v19 = (*(v9 - 48) * *dct_table) << 14;
        v20 = v17 + 8697 * v13;
        v21 = v18 - 4176 * v15;
        v22 = v16 + v19;
        v24 = v16 + v19 + v21;
        v23 = v19 - v16;
        v25 = v20 - 1730 * v15;
        *(p_back_chain - 8) = (v24 + 2048) >> 12;
        p_back_chain[16] = (v22 - v21 + 2048) >> 12;
        v11 = (v23 + v25 + 2048) >> 12;
        p_back_chain[8] = (v23 - v25 + 2048) >> 12;
      }
      else
      {
        v11 = 4 * *(v9 - 48) * *dct_table;
        *(p_back_chain - 8) = v11;
        p_back_chain[8] = v11;
        p_back_chain[16] = v11;
      }
      *p_back_chain = v11;
    }
    ++v9;
    ++dct_table;
    ++p_back_chain;
    --v7;
    --v8;
  }
  while ( v8 != 0 );
  v26 = &v42;
  for ( i = 4; i != 0; --i )
  {
    v29 = *((_DWORD *)v26 + 6);
    v30 = &(*output_buf)[output_col];
    if ( v29 != 0
      || *((_DWORD *)v26 + 7) != 0
      || *((_DWORD *)v26 + 8) != 0
      || *((_DWORD *)v26 + 10) != 0
      || *((_DWORD *)v26 + 11) != 0
      || *((_DWORD *)v26 + 12) != 0 )
    {
      v33 = *((_DWORD *)v26 + 12);
      v34 = *((_DWORD *)v26 + 10);
      v35 = *((_DWORD *)v26 + 5);
      v36 = *((_DWORD *)v26 + 11);
      v37 = *((_DWORD *)v26 + 7);
      v26 += 32;
      v38 = v35 << 14;
      v39 = 15137 * v37 - 6270 * v36;
      v40 = 20995 * v29 + 7373 * *(_DWORD *)v26 - 4926 * v34 - 4176 * v33;
      v41 = 11893 * v34 - 17799 * *(_DWORD *)v26 + 8697 * v29 - 1730 * v33;
      *v30 = *(_BYTE *)((((v39 + v38 + v40 + 0x40000) >> 19) & 0x3FF) + v6);
      v30[3] = *(_BYTE *)((((v39 + v38 - v40 + 0x40000) >> 19) & 0x3FF) + v6);
      v30[1] = *(_BYTE *)((((v38 - v39 + v41 + 0x40000) >> 19) & 0x3FF) + v6);
      v30[2] = *(_BYTE *)((((v38 - v39 - v41 + 0x40000) >> 19) & 0x3FF) + v6);
    }
    else
    {
      v31 = *((_DWORD *)v26 + 5);
      v26 += 32;
      v32 = *(_BYTE *)((((v31 + 16) >> 5) & 0x3FF) + v6);
      *v30 = v32;
      v30[1] = v32;
      v30[2] = v32;
      v30[3] = v32;
    }
    ++output_buf;
  }
}


// ========================================================================
// ?jpeg_idct_2x2@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
// EA  : 0x8323CAB0
// RVA : 0x0123CAB0
// PDB : w:\tech5\libs\jpeg\jidctred.cpp
// ========================================================================

void __fastcall jpeg_idct_2x2(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // r11
  int *p_back_chain; // r9
  int max_h_samp_factor; // r10
  int v8; // r3
  int v9; // r31
  __int16 *v10; // r10
  int v11; // r5
  int v12; // r5
  int v13; // r8
  int v14; // r4
  int v15; // r5
  int v16; // r5
  int v17; // r8
  int v18; // r4
  int v19; // r5
  int v20; // r5
  int v21; // r8
  int v22; // r4
  int v23; // r5
  int v24; // r5
  int v25; // r8
  int v26; // r4
  unsigned __int8 *v27; // r11
  unsigned __int8 v28; // r3
  int v29; // r9
  unsigned __int8 *v30; // r11
  unsigned __int8 v31; // r6
  int v32; // r9
  int v33; // r10
  int v34; // [sp+0h] [-80h]
  int back_chain; // [sp+4h] [-7Ch] BYREF
  int v36; // [sp+Ch] [-74h]
  int v37; // [sp+14h] [-6Ch]
  int v38; // [sp+1Ch] [-64h]
  int v39; // [sp+20h] [-60h]
  int v40; // [sp+24h] [-5Ch]
  int v41; // [sp+2Ch] [-54h]
  int v42; // [sp+34h] [-4Ch]
  int v43; // [sp+3Ch] [-44h]

  dct_table = compptr->dct_table;
  p_back_chain = &back_chain;
  max_h_samp_factor = cinfo->max_h_samp_factor;
  v8 = 6;
  v9 = max_h_samp_factor + 128;
  v10 = coef_block + 24;
  do
  {
    if ( v8 != 4 && v8 != 2 && v8 != 0 )
    {
      if ( *(v10 - 16) != 0 || *v10 != 0 || v10[16] != 0 || v10[32] != 0 )
      {
        v12 = (*(v10 - 24) * *dct_table) << 15;
        v13 = 6967 * v10[16] * dct_table[40]
            - 5906 * v10[32] * dct_table[56]
            - 10426 * *v10 * dct_table[24]
            + 29692 * dct_table[8] * *(v10 - 16);
        v14 = v13 + v12 + 4096;
        v11 = (v12 - v13 + 4096) >> 13;
        *(p_back_chain - 1) = v14 >> 13;
      }
      else
      {
        v11 = 4 * *(v10 - 24) * *dct_table;
        *(p_back_chain - 1) = v11;
      }
      p_back_chain[7] = v11;
    }
    if ( v8 != 5 && v8 != 3 && v8 != 1 )
    {
      if ( *(v10 - 15) != 0 || v10[1] != 0 || v10[17] != 0 || v10[33] != 0 )
      {
        v16 = (*(v10 - 23) * dct_table[1]) << 15;
        v17 = 6967 * v10[17] * dct_table[41]
            - 5906 * v10[33] * dct_table[57]
            - 10426 * v10[1] * dct_table[25]
            + 29692 * dct_table[9] * *(v10 - 15);
        v18 = v17 + v16 + 4096;
        v15 = (v16 - v17 + 4096) >> 13;
        *p_back_chain = v18 >> 13;
      }
      else
      {
        v15 = 4 * *(v10 - 23) * dct_table[1];
        *p_back_chain = v15;
      }
      p_back_chain[8] = v15;
    }
    if ( v8 != 6 && v8 != 4 && v8 != 2 )
    {
      if ( *(v10 - 14) != 0 || v10[2] != 0 || v10[18] != 0 || v10[34] != 0 )
      {
        v20 = (*(v10 - 22) * dct_table[2]) << 15;
        v21 = 6967 * v10[18] * dct_table[42]
            - 5906 * v10[34] * dct_table[58]
            - 10426 * v10[2] * dct_table[26]
            + 29692 * dct_table[10] * *(v10 - 14);
        v22 = v21 + v20 + 4096;
        v19 = (v20 - v21 + 4096) >> 13;
        p_back_chain[1] = v22 >> 13;
      }
      else
      {
        v19 = 4 * *(v10 - 22) * dct_table[2];
        p_back_chain[1] = v19;
      }
      p_back_chain[9] = v19;
    }
    if ( v8 != 7 && v8 != 5 && v8 != 3 )
    {
      if ( *(v10 - 13) != 0 || v10[3] != 0 || v10[19] != 0 || v10[35] != 0 )
      {
        v24 = (*(v10 - 21) * dct_table[3]) << 15;
        v25 = 6967 * v10[19] * dct_table[43]
            - 5906 * v10[35] * dct_table[59]
            - 10426 * v10[3] * dct_table[27]
            + 29692 * dct_table[11] * *(v10 - 13);
        v26 = v25 + v24 + 4096;
        v23 = (v24 - v25 + 4096) >> 13;
        p_back_chain[2] = v26 >> 13;
      }
      else
      {
        v23 = 4 * *(v10 - 21) * dct_table[3];
        p_back_chain[2] = v23;
      }
      p_back_chain[10] = v23;
    }
    v8 -= 4;
    v10 += 4;
    dct_table += 4;
    p_back_chain += 4;
  }
  while ( v8 + 2 > 0 );
  v27 = &(*output_buf)[output_col];
  if ( back_chain != 0 || v36 != 0 || v37 != 0 || v38 != 0 )
  {
    v29 = 29692 * back_chain - 10426 * v36 + 6967 * v37 - 5906 * v38;
    *v27 = *(_BYTE *)((((v29 + (v34 << 15) + 0x80000) >> 20) & 0x3FF) + v9);
    v27[1] = *(_BYTE *)(((((v34 << 15) - v29 + 0x80000) >> 20) & 0x3FF) + v9);
  }
  else
  {
    v28 = *(_BYTE *)((((v34 + 16) >> 5) & 0x3FF) + v9);
    *v27 = v28;
    v27[1] = v28;
  }
  v30 = &output_buf[1][output_col];
  if ( v40 != 0 || v41 != 0 || v42 != 0 || v43 != 0 )
  {
    v32 = 29692 * v40 + 6967 * v42 - 5906 * v43 - 10426 * v41;
    v33 = (v39 << 15) - v32 + 0x80000;
    *v30 = *(_BYTE *)((((v32 + (v39 << 15) + 0x80000) >> 20) & 0x3FF) + v9);
    v30[1] = *(_BYTE *)(((v33 >> 20) & 0x3FF) + v9);
  }
  else
  {
    v31 = *(_BYTE *)((((v39 + 16) >> 5) & 0x3FF) + v9);
    *v30 = v31;
    v30[1] = v31;
  }
}


// ========================================================================
// ?jpeg_idct_1x1@@YAXPAUjpeg_decompress_struct@@PAUjpeg_component_info@@PAFPAPAEI@Z
// EA  : 0x8323D020
// RVA : 0x0123D020
// PDB : w:\tech5\libs\jpeg\jidctred.cpp
// ========================================================================

void __fastcall jpeg_idct_1x1(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  (*output_buf)[output_col] = *(_BYTE *)((((*(_DWORD *)compptr->dct_table * *coef_block + 4) >> 3) & 0x3FF)
                                       + cinfo->max_h_samp_factor
                                       + 128);
}

