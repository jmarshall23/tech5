
// ========================================================================
// ?jpeg_make_d_derived_tbl@@YAXPAUjpeg_decompress_struct@@EHPAPAUd_derived_tbl@@@Z
// EA  : 0x832358E0
// RVA : 0x012358E0
// PDB : w:\tech5\libs\jpeg\jdhuff.cpp
// ========================================================================

void __fastcall jpeg_make_d_derived_tbl(
        jpeg_common_struct *cinfo,
        unsigned __int8 isDC,
        unsigned int tblno,
        d_derived_tbl **pdtbl)
{
  int v8; // r21
  unsigned int v9; // r11
  JHUFF_TBL *v10; // r27
  _DWORD *v11; // r26
  int v12; // r31
  int i; // r29
  int v14; // r30
  int v15; // ctr
  char *v16; // r11
  int v17; // r23
  int v18; // r30
  int v19; // r31
  int v20; // r29
  int j; // r28
  char *v22; // r11
  char *v23; // r10
  char v24; // r9
  int v25; // r11
  int v26; // r9
  _DWORD *v27; // r10
  int k; // ctr
  int v29; // r4
  int v30; // r6
  int m; // r31
  int v32; // r5
  unsigned __int8 *v33; // r9
  char *v34; // r7
  int v35; // r11
  int v36; // ctr
  _DWORD *v37; // r10
  int n; // r31
  char v39[1408]; // [sp+50h] [-580h] BYREF

  if ( tblno >= 4 )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  v8 = isDC;
  v9 = tblno + 40;
  if ( isDC == 0 )
    v9 = tblno + 44;
  v10 = *((JHUFF_TBL **)&cinfo->err + v9);
  if ( v10 == nullptr )
  {
    cinfo->err->msg_code = 50;
    cinfo->err->msg_parm.i[0] = tblno;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *pdtbl == nullptr )
    *pdtbl = (d_derived_tbl *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1424);
  v11 = *pdtbl;
  v12 = 0;
  (*pdtbl)->pub = v10;
  for ( i = 1; i <= 16; ++i )
  {
    v14 = v10->bits[i];
    if ( v14 + v12 > 256 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v14 != 0 )
    {
      v15 = v14;
      v16 = &v39[v12 - 1];
      v12 += v14;
      do
      {
        *++v16 = i;
        --v15;
      }
      while ( v15 != 0 );
    }
  }
  v17 = v12;
  v18 = 0;
  v39[v12] = 0;
  v19 = 0;
  v20 = v39[0];
  for ( j = __ROL4__(1, v39[0]); v39[v19] != 0; j = __ROL4__(j, 1) )
  {
    v22 = &v39[v19];
    if ( v39[v19] == v20 )
    {
      v23 = &v39[4 * v19 + 268];
      do
      {
        v24 = *++v22;
        ++v19;
        v23 += 4;
        *(_DWORD *)v23 = v18++;
      }
      while ( v24 == v20 );
    }
    if ( v18 >= j )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    v18 *= 2;
    ++v20;
  }
  v25 = 0;
  v26 = 1;
  v27 = v11 + 1;
  for ( k = 16; k != 0; --k )
  {
    if ( v10->bits[v26] != 0 )
    {
      v27[18] = v25 - *(_DWORD *)&v39[4 * v25 + 272];
      v25 += v10->bits[v26];
      *v27 = *(_DWORD *)&v39[4 * v25 + 268];
    }
    else
    {
      *v27 = -1;
    }
    ++v26;
    ++v27;
  }
  v11[17] = 0xFFFFF;
  memset(Dst: v11 + 36, Val: 0, Size: 0x400u);
  v29 = 0;
  v30 = 1;
  for ( m = 7; m >= 0; --m )
  {
    if ( v10->bits[v30] != 0 )
    {
      v32 = 1;
      v33 = &v10->huffval[v29];
      v34 = &v39[4 * v29 + 272];
      do
      {
        v35 = *(_DWORD *)v34 << m;
        if ( 1 << m > 0 )
        {
          v36 = 1 << m;
          v37 = &v11[v35 + 35];
          do
          {
            *++v37 = v30;
            *((_BYTE *)v11 + v35++ + 1168) = *v33;
            --v36;
          }
          while ( v36 != 0 );
        }
        ++v32;
        ++v29;
        v34 += 4;
        ++v33;
      }
      while ( v32 <= v10->bits[v30] );
    }
    ++v30;
  }
  if ( v8 != 0 )
  {
    for ( n = 0; n < v17; ++n )
    {
      if ( v10->huffval[n] > 0xFu )
      {
        cinfo->err->msg_code = 8;
        ((void (__fastcall *)(jpeg_common_struct *, int))cinfo->err->error_exit)(a1: cinfo, a2: v29);
      }
    }
  }
}


// ========================================================================
// ?jpeg_fill_bit_buffer@@YAEPAUbitread_working_state@@JHH@Z
// EA  : 0x83235C50
// RVA : 0x01235C50
// PDB : w:\tech5\libs\jpeg\jdhuff.cpp
// ========================================================================

int __fastcall jpeg_fill_bit_buffer(bitread_working_state *state, int get_buffer, int bits_left, int nbits)
{
  jpeg_decompress_struct *cinfo; // r29
  const unsigned __int8 *next_input_byte; // r31
  unsigned int bytes_in_buffer; // r30
  int v9; // r28
  jpeg_source_mgr *src; // r11
  int v12; // r11
  jpeg_source_mgr *v13; // r11
  int v14; // r11

  cinfo = state->cinfo;
  next_input_byte = state->next_input_byte;
  bytes_in_buffer = state->bytes_in_buffer;
  v9 = bits_left;
  if ( cinfo->Ss != 0 )
    goto no_more_bytes;
  if ( bits_left < 25 )
  {
    do
    {
      if ( bytes_in_buffer == 0 )
      {
        if ( cinfo->src->fill_input_buffer(a1: cinfo) == 0 )
          return 0;
        src = cinfo->src;
        next_input_byte = src->next_input_byte;
        bytes_in_buffer = src->bytes_in_buffer;
      }
      v12 = *next_input_byte;
      --bytes_in_buffer;
      ++next_input_byte;
      if ( v12 == 255 )
      {
        do
        {
          if ( bytes_in_buffer == 0 )
          {
            if ( cinfo->src->fill_input_buffer(a1: cinfo) == 0 )
              return 0;
            v13 = cinfo->src;
            next_input_byte = v13->next_input_byte;
            bytes_in_buffer = v13->bytes_in_buffer;
          }
          v14 = *next_input_byte;
          --bytes_in_buffer;
          ++next_input_byte;
        }
        while ( v14 == 255 );
        if ( v14 != 0 )
        {
          cinfo->Ss = v14;
no_more_bytes:
          if ( nbits > v9 )
          {
            if ( HIBYTE(cinfo->coef->start_output_pass) == 0 )
            {
              cinfo->err->msg_code = 117;
              cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: -1);
              HIBYTE(cinfo->coef->start_output_pass) = 1;
            }
            get_buffer <<= 25 - v9;
            v9 = 25;
          }
          break;
        }
        v12 = 255;
      }
      v9 += 8;
      get_buffer = (get_buffer << 8) | v12;
    }
    while ( v9 < 25 );
  }
  state->next_input_byte = next_input_byte;
  state->bytes_in_buffer = bytes_in_buffer;
  state->get_buffer = get_buffer;
  state->bits_left = v9;
  return 1;
}


// ========================================================================
// ?jpeg_huff_decode@@YAHPAUbitread_working_state@@JHPAUd_derived_tbl@@H@Z
// EA  : 0x83235DC0
// RVA : 0x01235DC0
// PDB : w:\tech5\libs\jpeg\jdhuff.cpp
// ========================================================================

int __fastcall jpeg_huff_decode(
        bitread_working_state *state,
        int get_buffer,
        int bits_left,
        d_derived_tbl *htbl,
        int min_bits)
{
  int v7; // r31
  int v9; // r5
  int v10; // r11
  int *v11; // r30
  int v12; // r28

  v7 = min_bits;
  if ( bits_left < min_bits )
  {
    if ( (unsigned __int8)jpeg_fill_bit_buffer(state, get_buffer, bits_left, nbits: min_bits) == 0 )
      return -1;
    get_buffer = state->get_buffer;
    bits_left = state->bits_left;
  }
  v9 = bits_left - v7;
  v10 = (get_buffer >> v9) & ((1 << v7) - 1);
  if ( v10 > htbl->maxcode[v7] )
  {
    v11 = &htbl->maxcode[v7];
    do
    {
      v12 = 2 * v10;
      if ( v9 < 1 )
      {
        if ( (unsigned __int8)jpeg_fill_bit_buffer(state, get_buffer, bits_left: v9, nbits: 1) == 0 )
          return -1;
        get_buffer = state->get_buffer;
        v9 = state->bits_left;
      }
      --v9;
      ++v11;
      ++v7;
      v10 = (get_buffer >> v9) & 1 | v12;
    }
    while ( v10 > *v11 );
  }
  state->get_buffer = get_buffer;
  state->bits_left = v9;
  if ( v7 <= 16 )
    return htbl->pub->huffval[htbl->valoffset[v7] + v10];
  state->cinfo->err->msg_code = 118;
  state->cinfo->err->emit_message(a1: (jpeg_common_struct *)state->cinfo, a2: -1);
  return 0;
}


// ========================================================================
// decode_mcu
// EA  : 0x83235EF0
// RVA : 0x01235EF0
// PDB : w:\tech5\libs\jpeg\jdhuff.cpp
// ========================================================================

int __fastcall decode_mcu(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_d_coef_controller *coef; // r24
  char v5; // r11
  int v6; // r11
  jvirt_barray_control ***p_coef_arrays; // r10
  jpeg_source_mgr *src; // r11
  int (__fastcall *consume_data)(jpeg_decompress_struct *); // r8
  int v11; // r19
  void (__fastcall *start_output_pass)(jpeg_decompress_struct *); // r7
  int (__fastcall *decompress_data)(jpeg_decompress_struct *, unsigned __int8 ***); // r6
  const unsigned __int8 *next_input_byte; // r3
  unsigned int bytes_in_buffer; // r11
  jpeg_component_info *v16; // r5
  bool v17; // cr57
  int get_buffer; // r4
  int coef_arrays; // r5
  __int16 (**v20)[64]; // r20
  jpeg_component_info **v21; // r21
  d_derived_tbl **p_decompress_data; // r23
  __int16 *v23; // r29
  d_derived_tbl *v24; // r31
  d_derived_tbl *v25; // r28
  int v26; // r7
  int v27; // r11
  int v28; // r10
  int v29; // r31
  int v30; // r11
  int v31; // r8
  int v32; // r10
  int v33; // r11
  int v34; // r30
  int v35; // r7
  int v36; // r11
  int v37; // r10
  int v38; // r3
  int v39; // r31
  int v40; // r11
  int v41; // r30
  int v42; // r11
  int v43; // r7
  int v44; // r11
  int v45; // r10
  int v46; // r3
  int v47; // r31
  int v48; // r11
  int v49; // r30
  unsigned int v50; // r8
  void (__fastcall *v51)(jpeg_decompress_struct *); // r7
  int (__fastcall *v52)(jpeg_decompress_struct *); // r6
  void (__fastcall *v53)(jpeg_decompress_struct *); // r3
  int (__fastcall *v54)(jpeg_decompress_struct *, unsigned __int8 ***); // r11
  void (__fastcall *start_input_pass)(jpeg_decompress_struct *); // [sp+50h] [-A0h] BYREF
  int (__fastcall *v56)(jpeg_decompress_struct *); // [sp+54h] [-9Ch]
  void (__fastcall *v57)(jpeg_decompress_struct *); // [sp+58h] [-98h]
  int (__fastcall *v58)(jpeg_decompress_struct *, unsigned __int8 ***); // [sp+5Ch] [-94h]
  bitread_working_state v59[7]; // [sp+60h] [-90h] BYREF

  coef = cinfo->coef;
  if ( *(_DWORD *)&cinfo->arith_ac_K[2] != 0 && coef[1].coef_arrays == nullptr )
  {
    cinfo->main[2].process_data = (void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))((char *)cinfo->main[2].process_data + (int)coef->coef_arrays / 8);
    coef->coef_arrays = nullptr;
    if ( ((unsigned __int8 (*)(void))cinfo->main[1].start_pass)() != 0 )
    {
      v6 = 0;
      if ( cinfo->max_v_samp_factor > 0 )
      {
        p_coef_arrays = &coef->coef_arrays;
        do
        {
          ++v6;
          *++p_coef_arrays = nullptr;
        }
        while ( v6 < cinfo->max_v_samp_factor );
      }
      coef[1].coef_arrays = *(jvirt_barray_control ***)&cinfo->arith_ac_K[2];
      if ( cinfo->Ss == 0 )
        HIBYTE(coef->start_output_pass) = 0;
      v5 = 1;
    }
    else
    {
      v5 = 0;
    }
    if ( v5 == 0 )
      return 0;
  }
  if ( HIBYTE(coef->start_output_pass) != 0 )
    goto LABEL_73;
  src = cinfo->src;
  consume_data = coef[1].consume_data;
  v11 = 0;
  start_output_pass = coef[1].start_output_pass;
  decompress_data = coef[1].decompress_data;
  next_input_byte = src->next_input_byte;
  bytes_in_buffer = src->bytes_in_buffer;
  v16 = cinfo->cur_comp_info[2];
  start_input_pass = coef[1].start_input_pass;
  v56 = consume_data;
  v17 = (int)v16 > 0;
  v57 = start_output_pass;
  get_buffer = (int)coef->decompress_data;
  coef_arrays = (int)coef->coef_arrays;
  v59[0].cinfo = cinfo;
  v59[0].next_input_byte = next_input_byte;
  v59[0].bytes_in_buffer = bytes_in_buffer;
  v58 = decompress_data;
  if ( !v17 )
    goto LABEL_72;
  v20 = MCU_data;
  v21 = &cinfo->cur_comp_info[3];
  p_decompress_data = (d_derived_tbl **)&coef[5].decompress_data;
  do
  {
    v23 = (__int16 *)*v20;
    v24 = *(p_decompress_data - 10);
    v25 = *p_decompress_data;
    if ( coef_arrays >= 8 )
      goto LABEL_20;
    if ( (unsigned __int8)jpeg_fill_bit_buffer(state: v59, get_buffer, bits_left: coef_arrays, nbits: 0) == 0 )
      return 0;
    coef_arrays = v59[0].bits_left;
    get_buffer = v59[0].get_buffer;
    if ( v59[0].bits_left >= 8 )
    {
LABEL_20:
      v27 = (unsigned __int8)(get_buffer >> (coef_arrays - 8));
      v28 = v24->look_nbits[v27];
      if ( v28 != 0 )
      {
        coef_arrays -= v28;
        v29 = v24->look_sym[v27];
        goto LABEL_25;
      }
      v26 = 9;
    }
    else
    {
      v26 = 1;
    }
    v29 = jpeg_huff_decode(state: v59, get_buffer, bits_left: coef_arrays, htbl: v24, min_bits: v26);
    if ( v29 < 0 )
      return 0;
    get_buffer = v59[0].get_buffer;
    coef_arrays = v59[0].bits_left;
LABEL_25:
    if ( v29 != 0 )
    {
      if ( coef_arrays < v29 )
      {
        if ( (unsigned __int8)jpeg_fill_bit_buffer(state: v59, get_buffer, bits_left: coef_arrays, nbits: v29) == 0 )
          return 0;
        get_buffer = v59[0].get_buffer;
        coef_arrays = v59[0].bits_left;
      }
      coef_arrays -= v29;
      v30 = v29;
      v31 = extend_test[v29];
      v29 = ((1 << v29) - 1) & (get_buffer >> coef_arrays);
      if ( v29 < v31 )
        v29 += extend_offset[v30];
    }
    if ( *((_BYTE *)&coef[7].decompress_data + v11) != 0 )
    {
      v32 = 4 * (_DWORD)*v21;
      v33 = *(int *)((char *)&start_input_pass + v32) + v29;
      *(void (__fastcall **)(jpeg_decompress_struct *))((char *)&start_input_pass + v32) = (void (__fastcall *)(jpeg_decompress_struct *))v33;
      *v23 = v33;
    }
    v34 = 1;
    if ( *((_BYTE *)&coef[8].start_input_pass + v11 + 2) != 0 )
    {
      while ( 1 )
      {
        if ( coef_arrays < 8 )
        {
          if ( (unsigned __int8)jpeg_fill_bit_buffer(state: v59, get_buffer, bits_left: coef_arrays, nbits: 0) == 0 )
            return 0;
          coef_arrays = v59[0].bits_left;
          get_buffer = v59[0].get_buffer;
          if ( v59[0].bits_left < 8 )
            break;
        }
        v36 = (unsigned __int8)(get_buffer >> (coef_arrays - 8));
        v37 = v25->look_nbits[v36];
        if ( v37 == 0 )
        {
          v35 = 9;
          goto label2;
        }
        coef_arrays -= v37;
        v38 = v25->look_sym[v36];
LABEL_43:
        v39 = v38 & 0xF;
        v40 = v38 >> 4;
        if ( (v38 & 0xF) != 0 )
        {
          v41 = v34 + v40;
          if ( coef_arrays < v39 )
          {
            if ( (unsigned __int8)jpeg_fill_bit_buffer(state: v59, get_buffer, bits_left: coef_arrays, nbits: v38 & 0xF) == 0 )
              return 0;
            get_buffer = v59[0].get_buffer;
            coef_arrays = v59[0].bits_left;
          }
          coef_arrays -= v39;
          v42 = ((1 << v39) - 1) & (get_buffer >> coef_arrays);
          if ( v42 < extend_test[v39] )
            v42 += extend_offset[v39];
          v23[jpeg_natural_order[v41]] = v42;
        }
        else
        {
          if ( v40 != 15 )
            goto LABEL_71;
          v41 = v34 + 15;
        }
        v34 = v41 + 1;
        if ( v34 >= 64 )
          goto LABEL_71;
      }
      v35 = 1;
label2:
      v38 = jpeg_huff_decode(state: v59, get_buffer, bits_left: coef_arrays, htbl: v25, min_bits: v35);
      if ( v38 < 0 )
        return 0;
      get_buffer = v59[0].get_buffer;
      coef_arrays = v59[0].bits_left;
      goto LABEL_43;
    }
    do
    {
      if ( coef_arrays >= 8 )
        goto LABEL_58;
      if ( (unsigned __int8)jpeg_fill_bit_buffer(state: v59, get_buffer, bits_left: coef_arrays, nbits: 0) == 0 )
        return 0;
      coef_arrays = v59[0].bits_left;
      get_buffer = v59[0].get_buffer;
      if ( v59[0].bits_left >= 8 )
      {
LABEL_58:
        v44 = (unsigned __int8)(get_buffer >> (coef_arrays - 8));
        v45 = v25->look_nbits[v44];
        if ( v45 != 0 )
        {
          coef_arrays -= v45;
          v46 = v25->look_sym[v44];
          goto LABEL_63;
        }
        v43 = 9;
      }
      else
      {
        v43 = 1;
      }
      v46 = jpeg_huff_decode(state: v59, get_buffer, bits_left: coef_arrays, htbl: v25, min_bits: v43);
      if ( v46 < 0 )
        return 0;
      get_buffer = v59[0].get_buffer;
      coef_arrays = v59[0].bits_left;
LABEL_63:
      v47 = v46 & 0xF;
      v48 = v46 >> 4;
      if ( (v46 & 0xF) != 0 )
      {
        v49 = v34 + v48;
        if ( coef_arrays < v47 )
        {
          if ( (unsigned __int8)jpeg_fill_bit_buffer(state: v59, get_buffer, bits_left: coef_arrays, nbits: v46 & 0xF) == 0 )
            return 0;
          get_buffer = v59[0].get_buffer;
          coef_arrays = v59[0].bits_left;
        }
        coef_arrays -= v47;
      }
      else
      {
        if ( v48 != 15 )
          break;
        v49 = v34 + 15;
      }
      v34 = v49 + 1;
    }
    while ( v34 < 64 );
LABEL_71:
    ++v11;
    ++v20;
    ++p_decompress_data;
    ++v21;
  }
  while ( v11 < (int)cinfo->cur_comp_info[2] );
LABEL_72:
  v50 = v59[0].bytes_in_buffer;
  v51 = start_input_pass;
  v52 = v56;
  v53 = v57;
  v54 = v58;
  cinfo->src->next_input_byte = v59[0].next_input_byte;
  cinfo->src->bytes_in_buffer = v50;
  coef->decompress_data = (int (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 ***))get_buffer;
  coef->coef_arrays = (jvirt_barray_control **)coef_arrays;
  coef[1].start_input_pass = v51;
  coef[1].consume_data = v52;
  coef[1].start_output_pass = v53;
  coef[1].decompress_data = v54;
LABEL_73:
  --coef[1].coef_arrays;
  return 1;
}


// ========================================================================
// start_pass_huff_decoder
// EA  : 0x83236408
// RVA : 0x01236408
// PDB : w:\tech5\libs\jpeg\jdhuff.cpp
// ========================================================================

void __fastcall start_pass_huff_decoder(jpeg_common_struct *cinfo)
{
  jpeg_d_coef_controller *err; // r30
  int v3; // r28
  jvirt_barray_control ***p_coef_arrays; // r26
  int *p_mem; // r27
  unsigned int v6; // r29
  int v7; // r10
  char *v8; // r5
  int (__fastcall **p_decompress_data)(jpeg_decompress_struct *, unsigned __int8 ***); // r4
  int (__fastcall **v10)(jpeg_decompress_struct *, unsigned __int8 ***); // r8
  jpeg_component_info **p_client_data; // r6
  int v12; // r11

  err = (jpeg_d_coef_controller *)cinfo[17].err;
  if ( cinfo[15].mem != nullptr
    || cinfo[15].progress != (jpeg_progress_mgr *)63
    || cinfo[15].client_data != nullptr
    || *(_DWORD *)&cinfo[15].is_decompressor != 0 )
  {
    cinfo->err->msg_code = 122;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
  }
  v3 = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_coef_arrays = &err->coef_arrays;
    p_mem = (int *)&cinfo[12].mem;
    do
    {
      v6 = *(_DWORD *)(*++p_mem + 24);
      jpeg_make_d_derived_tbl(
        cinfo,
        isDC: 1u,
        tblno: *(_DWORD *)(*p_mem + 20),
        pdtbl: (d_derived_tbl **)&err[2].start_input_pass + *(_DWORD *)(*p_mem + 20));
      jpeg_make_d_derived_tbl(cinfo, isDC: 0, tblno: v6, pdtbl: (d_derived_tbl **)&err[2].coef_arrays + v6);
      ++v3;
      *++p_coef_arrays = nullptr;
    }
    while ( v3 < (int)cinfo[12].mem );
  }
  v7 = 0;
  if ( (int)cinfo[13].progress > 0 )
  {
    v8 = (char *)&err[8].start_input_pass + 2;
    p_decompress_data = &err[7].decompress_data;
    v10 = &err[5].decompress_data;
    p_client_data = (jpeg_component_info **)&cinfo[13].client_data;
    do
    {
      v12 = *((_DWORD *)&cinfo->err + (_DWORD)&(*p_client_data)->last_row_height + 2);
      *(v10 - 10) = *((int (__fastcall **)(jpeg_decompress_struct *, unsigned __int8 ***))&err[2].start_input_pass
                    + *(_DWORD *)(v12 + 20));
      *v10 = *((int (__fastcall **)(jpeg_decompress_struct *, unsigned __int8 ***))&err[2].coef_arrays
             + *(_DWORD *)(v12 + 24));
      if ( *(_BYTE *)(v12 + 48) != 0 )
      {
        *((_BYTE *)p_decompress_data + v7) = 1;
        v8[v7] = ((*(_DWORD *)(v12 + 36) >= 0) + (*(_DWORD *)(v12 + 36) <= 1u)) & 1;
      }
      else
      {
        v8[v7] = 0;
        *((_BYTE *)p_decompress_data + v7) = 0;
      }
      ++v7;
      ++p_client_data;
      ++v10;
    }
    while ( v7 < (int)cinfo[13].progress );
  }
  err->coef_arrays = nullptr;
  err->decompress_data = nullptr;
  HIBYTE(err->start_output_pass) = 0;
  err[1].coef_arrays = (jvirt_barray_control **)cinfo[10].client_data;
}


// ========================================================================
// ?jinit_huff_decoder@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x832365A8
// RVA : 0x012365A8
// PDB : w:\tech5\libs\jpeg\jdhuff.cpp
// ========================================================================

void __fastcall jinit_huff_decoder(jpeg_decompress_struct *cinfo)
{
  jpeg_d_coef_controller *v2; // r3
  int v3; // ctr
  jvirt_barray_control ***p_coef_arrays; // r11

  v2 = (jpeg_d_coef_controller *)((int (*)(void))cinfo->mem->alloc_small)();
  cinfo->coef = v2;
  v3 = 4;
  v2->start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))start_pass_huff_decoder;
  p_coef_arrays = &v2[1].coef_arrays;
  v2->consume_data = (int (__fastcall *)(jpeg_decompress_struct *))decode_mcu;
  do
  {
    p_coef_arrays[5] = nullptr;
    *++p_coef_arrays = nullptr;
    --v3;
  }
  while ( v3 != 0 );
}

