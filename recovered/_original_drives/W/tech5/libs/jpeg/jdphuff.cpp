
// ========================================================================
// process_restart
// EA  : 0x83236620
// RVA : 0x01236620
// PDB : w:\tech5\libs\jpeg\jdphuff.cpp
// ========================================================================

int __fastcall process_restart(jpeg_decompress_struct *cinfo)
{
  jpeg_d_coef_controller *coef; // r30
  int v4; // r11
  jpeg_d_coef_controller *v5; // r10

  coef = cinfo->coef;
  cinfo->main[2].process_data = (void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))((char *)cinfo->main[2].process_data + (int)coef->coef_arrays / 8);
  coef->coef_arrays = nullptr;
  if ( ((unsigned __int8 (*)(void))cinfo->main[1].start_pass)() == 0 )
    return 0;
  v4 = 0;
  if ( cinfo->max_v_samp_factor > 0 )
  {
    v5 = coef + 1;
    do
    {
      ++v4;
      v5 = (jpeg_d_coef_controller *)((char *)v5 + 4);
      v5->start_input_pass = nullptr;
    }
    while ( v4 < cinfo->max_v_samp_factor );
  }
  coef[1].start_input_pass = nullptr;
  coef[2].start_input_pass = *(void (__fastcall **)(jpeg_decompress_struct *))&cinfo->arith_ac_K[2];
  if ( cinfo->Ss == 0 )
    HIBYTE(coef->start_output_pass) = 0;
  return 1;
}


// ========================================================================
// decode_mcu_DC_first
// EA  : 0x832366D0
// RVA : 0x012366D0
// PDB : w:\tech5\libs\jpeg\jdphuff.cpp
// ========================================================================

int __fastcall decode_mcu_DC_first(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_d_coef_controller *coef; // r24
  int v5; // r21
  jpeg_source_mgr *src; // r8
  _DWORD *v8; // r10
  jvirt_barray_control ***p_coef_arrays; // r9
  int v10; // ctr
  int decompress_data; // r4
  int coef_arrays; // r5
  int v13; // r26
  __int16 (**v14)[64]; // r29
  jpeg_component_info **v15; // r28
  jpeg_component_info *v16; // r27
  __int16 *v17; // r25
  d_derived_tbl *v18; // r31
  int v19; // r7
  int v20; // r11
  int v21; // r10
  int v22; // r31
  int v23; // r11
  int v24; // r8
  int v25; // r11
  _DWORD *v26; // r10
  jvirt_barray_control ***v27; // r9
  int v28; // ctr
  bitread_working_state v29; // [sp+50h] [-A0h] BYREF
  _BYTE v30[132]; // [sp+6Ch] [-84h] BYREF

  coef = cinfo->coef;
  v5 = cinfo->MCU_membership[9];
  if ( *(_DWORD *)&cinfo->arith_ac_K[2] != 0
    && coef[2].start_input_pass == nullptr
    && (unsigned __int8)process_restart(cinfo) == 0 )
  {
    return 0;
  }
  if ( HIBYTE(coef->start_output_pass) == 0 )
  {
    src = cinfo->src;
    v29.cinfo = cinfo;
    v8 = v30;
    p_coef_arrays = &coef->coef_arrays;
    v10 = 5;
    v29.next_input_byte = src->next_input_byte;
    v29.bytes_in_buffer = src->bytes_in_buffer;
    decompress_data = (int)coef->decompress_data;
    coef_arrays = (int)coef->coef_arrays;
    do
    {
      *++v8 = *++p_coef_arrays;
      --v10;
    }
    while ( v10 != 0 );
    v13 = 0;
    if ( (int)cinfo->cur_comp_info[2] > 0 )
    {
      v14 = MCU_data;
      v15 = &cinfo->cur_comp_info[3];
      while ( 1 )
      {
        v16 = *v15;
        v17 = (__int16 *)*v14;
        v18 = *((d_derived_tbl **)&coef[2].consume_data
              + *(_DWORD *)(*((_DWORD *)&cinfo->err + (_DWORD)&(*v15)->last_row_height + 2) + 20));
        if ( coef_arrays < 8 )
        {
          if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                  state: &v29,
                                  get_buffer: decompress_data,
                                  bits_left: coef_arrays,
                                  nbits: 0) == 0 )
            return 0;
          coef_arrays = v29.bits_left;
          decompress_data = v29.get_buffer;
          if ( v29.bits_left < 8 )
            break;
        }
        v20 = (unsigned __int8)(decompress_data >> (coef_arrays - 8));
        v21 = v18->look_nbits[v20];
        if ( v21 == 0 )
        {
          v19 = 9;
          goto label1_0;
        }
        coef_arrays -= v21;
        v22 = v18->look_sym[v20];
LABEL_19:
        if ( v22 != 0 )
        {
          if ( coef_arrays < v22 )
          {
            if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                    state: &v29,
                                    get_buffer: decompress_data,
                                    bits_left: coef_arrays,
                                    nbits: v22) == 0 )
              return 0;
            decompress_data = v29.get_buffer;
            coef_arrays = v29.bits_left;
          }
          coef_arrays -= v22;
          v23 = v22;
          v24 = extend_test_0[v22];
          v22 = ((1 << v22) - 1) & (decompress_data >> coef_arrays);
          if ( v22 < v24 )
            v22 += extend_offset_0[v23];
        }
        ++v13;
        ++v14;
        ++v15;
        v25 = *(_DWORD *)&v30[4 * (_DWORD)v16 + 8] + v22;
        *(_DWORD *)&v30[4 * (_DWORD)v16 + 8] = v25;
        *v17 = v25 << v5;
        if ( v13 >= (int)cinfo->cur_comp_info[2] )
          goto LABEL_26;
      }
      v19 = 1;
label1_0:
      v22 = jpeg_huff_decode(state: &v29, get_buffer: decompress_data, bits_left: coef_arrays, htbl: v18, min_bits: v19);
      if ( v22 < 0 )
        return 0;
      decompress_data = v29.get_buffer;
      coef_arrays = v29.bits_left;
      goto LABEL_19;
    }
LABEL_26:
    v26 = v30;
    v27 = &coef->coef_arrays;
    v28 = 5;
    cinfo->src->next_input_byte = v29.next_input_byte;
    cinfo->src->bytes_in_buffer = v29.bytes_in_buffer;
    coef->decompress_data = (int (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 ***))decompress_data;
    coef->coef_arrays = (jvirt_barray_control **)coef_arrays;
    do
    {
      *++v27 = (jvirt_barray_control **)*++v26;
      --v28;
    }
    while ( v28 != 0 );
  }
  --coef[2].start_input_pass;
  return 1;
}


// ========================================================================
// decode_mcu_AC_first
// EA  : 0x83236930
// RVA : 0x01236930
// PDB : w:\tech5\libs\jpeg\jdphuff.cpp
// ========================================================================

int __fastcall decode_mcu_AC_first(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_d_coef_controller *coef; // r24
  int v5; // r21
  int v6; // r20
  void (__fastcall *start_input_pass)(jpeg_decompress_struct *); // r19
  jpeg_source_mgr *src; // r11
  int v10; // r29
  int v11; // r22
  int decompress_data; // r4
  int coef_arrays; // r5
  d_derived_tbl *v14; // r28
  int v15; // r7
  int v16; // r11
  int v17; // r10
  int v18; // r3
  int v19; // r31
  int v20; // r30
  int v21; // r30
  int v22; // r11
  int v23; // r31
  bitread_working_state v24[7]; // [sp+50h] [-90h] BYREF

  coef = cinfo->coef;
  v5 = cinfo->MCU_membership[7];
  v6 = cinfo->MCU_membership[9];
  if ( *(_DWORD *)&cinfo->arith_ac_K[2] != 0
    && coef[2].start_input_pass == nullptr
    && (unsigned __int8)process_restart(cinfo) == 0 )
  {
    return 0;
  }
  if ( HIBYTE(coef->start_output_pass) != 0 )
    goto LABEL_37;
  start_input_pass = coef[1].start_input_pass;
  if ( start_input_pass != nullptr )
  {
    start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))((char *)start_input_pass - 1);
    goto LABEL_36;
  }
  src = cinfo->src;
  v24[0].cinfo = cinfo;
  v10 = cinfo->MCU_membership[6];
  v11 = (int)*MCU_data;
  v24[0].next_input_byte = src->next_input_byte;
  v24[0].bytes_in_buffer = src->bytes_in_buffer;
  decompress_data = (int)coef->decompress_data;
  coef_arrays = (int)coef->coef_arrays;
  v14 = (d_derived_tbl *)coef[3].start_input_pass;
  if ( v10 > v5 )
    goto LABEL_35;
  while ( 1 )
  {
    if ( coef_arrays >= 8 )
      goto LABEL_13;
    if ( (unsigned __int8)jpeg_fill_bit_buffer(
                            state: v24,
                            get_buffer: decompress_data,
                            bits_left: coef_arrays,
                            nbits: 0) == 0 )
      return 0;
    coef_arrays = v24[0].bits_left;
    decompress_data = v24[0].get_buffer;
    if ( v24[0].bits_left >= 8 )
    {
LABEL_13:
      v16 = (unsigned __int8)(decompress_data >> (coef_arrays - 8));
      v17 = v14->look_nbits[v16];
      if ( v17 != 0 )
      {
        coef_arrays -= v17;
        v18 = v14->look_sym[v16];
        goto LABEL_18;
      }
      v15 = 9;
    }
    else
    {
      v15 = 1;
    }
    v18 = jpeg_huff_decode(state: v24, get_buffer: decompress_data, bits_left: coef_arrays, htbl: v14, min_bits: v15);
    if ( v18 < 0 )
      return 0;
    decompress_data = v24[0].get_buffer;
    coef_arrays = v24[0].bits_left;
LABEL_18:
    v19 = v18 & 0xF;
    v20 = v18 >> 4;
    if ( (v18 & 0xF) != 0 )
    {
      v21 = v20 + v10;
      if ( coef_arrays < v19 )
      {
        if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                state: v24,
                                get_buffer: decompress_data,
                                bits_left: coef_arrays,
                                nbits: v18 & 0xF) == 0 )
          return 0;
        decompress_data = v24[0].get_buffer;
        coef_arrays = v24[0].bits_left;
      }
      coef_arrays -= v19;
      v22 = ((1 << v19) - 1) & (decompress_data >> coef_arrays);
      if ( v22 < extend_test_0[v19] )
        v22 += extend_offset_0[v19];
      *(_WORD *)(2 * jpeg_natural_order[v21] + v11) = v22 << v6;
      goto LABEL_27;
    }
    if ( v20 != 15 )
      break;
    v21 = v10 + 15;
LABEL_27:
    v10 = v21 + 1;
    if ( v21 + 1 > v5 )
      goto LABEL_35;
  }
  v23 = 1 << v20;
  if ( v20 != 0 )
  {
    if ( coef_arrays < v20 )
    {
      if ( (unsigned __int8)jpeg_fill_bit_buffer(
                              state: v24,
                              get_buffer: decompress_data,
                              bits_left: coef_arrays,
                              nbits: v18 >> 4) == 0 )
        return 0;
      decompress_data = v24[0].get_buffer;
      coef_arrays = v24[0].bits_left;
    }
    coef_arrays -= v20;
    v23 += (decompress_data >> coef_arrays) & (v23 - 1);
  }
  start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))(v23 - 1);
LABEL_35:
  cinfo->src->next_input_byte = v24[0].next_input_byte;
  cinfo->src->bytes_in_buffer = v24[0].bytes_in_buffer;
  coef->decompress_data = (int (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 ***))decompress_data;
  coef->coef_arrays = (jvirt_barray_control **)coef_arrays;
LABEL_36:
  coef[1].start_input_pass = start_input_pass;
LABEL_37:
  --coef[2].start_input_pass;
  return 1;
}


// ========================================================================
// decode_mcu_DC_refine
// EA  : 0x83236BA0
// RVA : 0x01236BA0
// PDB : w:\tech5\libs\jpeg\jdphuff.cpp
// ========================================================================

int __fastcall decode_mcu_DC_refine(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  jpeg_d_coef_controller *coef; // r30
  int v5; // r26
  jpeg_source_mgr *src; // r11
  int v8; // r27
  jpeg_component_info *v9; // r10
  int decompress_data; // r4
  int coef_arrays; // r5
  _WORD *v12; // r28
  int v13; // r7
  bitread_working_state v14; // [sp+50h] [-50h] BYREF

  coef = cinfo->coef;
  v5 = 1 << cinfo->MCU_membership[9];
  if ( *(_DWORD *)&cinfo->arith_ac_K[2] != 0
    && coef[2].start_input_pass == nullptr
    && (unsigned __int8)process_restart(cinfo) == 0 )
  {
    return 0;
  }
  src = cinfo->src;
  v8 = 0;
  v14.cinfo = cinfo;
  v9 = cinfo->cur_comp_info[2];
  v14.next_input_byte = src->next_input_byte;
  v14.bytes_in_buffer = src->bytes_in_buffer;
  decompress_data = (int)coef->decompress_data;
  coef_arrays = (int)coef->coef_arrays;
  if ( (int)v9 > 0 )
  {
    do
    {
      v12 = *MCU_data;
      if ( coef_arrays < 1 )
      {
        if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                state: &v14,
                                get_buffer: decompress_data,
                                bits_left: coef_arrays,
                                nbits: 1) == 0 )
          return 0;
        decompress_data = v14.get_buffer;
        coef_arrays = v14.bits_left;
      }
      if ( ((decompress_data >> --coef_arrays) & 1) != 0 )
        *v12 |= v5;
      ++v8;
      ++MCU_data;
    }
    while ( v8 < (int)cinfo->cur_comp_info[2] );
  }
  cinfo->src->next_input_byte = v14.next_input_byte;
  cinfo->src->bytes_in_buffer = v14.bytes_in_buffer;
  v13 = (int)coef[2].start_input_pass - 1;
  coef->decompress_data = (int (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 ***))decompress_data;
  coef->coef_arrays = (jvirt_barray_control **)coef_arrays;
  coef[2].start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))v13;
  return 1;
}


// ========================================================================
// decode_mcu_AC_refine
// EA  : 0x83236CC0
// RVA : 0x01236CC0
// PDB : w:\tech5\libs\jpeg\jdphuff.cpp
// ========================================================================

int __fastcall decode_mcu_AC_refine(jpeg_decompress_struct *cinfo, __int16 (**MCU_data)[64])
{
  int v2; // r11
  int v3; // r27
  int v4; // r9
  jpeg_d_coef_controller *coef; // r17
  int v8; // r20
  jpeg_source_mgr *src; // r10
  int v10; // r14
  int v11; // r28
  int v12; // r24
  int start_input_pass; // r15
  int decompress_data; // r25
  int coef_arrays; // r30
  d_derived_tbl *v16; // r23
  _DWORD *v17; // r22
  int v18; // r7
  int v19; // r11
  int v20; // r10
  int v21; // r3
  int v22; // r27
  int v23; // r26
  const int *v24; // r29
  int v25; // r31
  __int16 v26; // r11
  int v27; // r9
  __int16 v28; // r26
  const int *v29; // r29
  int v30; // r31
  __int16 v31; // r11
  __int16 v32; // r11
  int v34; // ctr
  _DWORD *v35; // r11
  int v36; // [sp+50h] [-1D0h]
  bitread_working_state v37; // [sp+60h] [-1C0h] BYREF
  int v38; // [sp+74h] [-1ACh]
  _BYTE v39[420]; // [sp+7Ch] [-1A4h] BYREF

  v2 = cinfo->MCU_membership[9];
  v3 = cinfo->MCU_membership[7];
  v4 = *(_DWORD *)&cinfo->arith_ac_K[2];
  coef = cinfo->coef;
  v36 = v3;
  v8 = 1 << v2;
  v38 = -1 << v2;
  if ( v4 != 0 && coef[2].start_input_pass == nullptr && (unsigned __int8)process_restart(cinfo) == 0 )
    return 0;
  if ( HIBYTE(coef->start_output_pass) == 0 )
  {
    src = cinfo->src;
    v37.cinfo = cinfo;
    v10 = 0;
    v11 = (int)*MCU_data;
    v12 = cinfo->MCU_membership[6];
    v37.next_input_byte = src->next_input_byte;
    v37.bytes_in_buffer = src->bytes_in_buffer;
    start_input_pass = (int)coef[1].start_input_pass;
    decompress_data = (int)coef->decompress_data;
    coef_arrays = (int)coef->coef_arrays;
    v16 = (d_derived_tbl *)coef[3].start_input_pass;
    if ( start_input_pass != 0 )
      goto LABEL_49;
    if ( v12 <= v3 )
    {
      v17 = v39;
      do
      {
        if ( coef_arrays >= 8 )
          goto LABEL_12;
        if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                state: &v37,
                                get_buffer: decompress_data,
                                bits_left: coef_arrays,
                                nbits: 0) == 0 )
          goto undoit;
        decompress_data = v37.get_buffer;
        coef_arrays = v37.bits_left;
        if ( v37.bits_left >= 8 )
        {
LABEL_12:
          v19 = (unsigned __int8)(decompress_data >> (coef_arrays - 8));
          v20 = v16->look_nbits[v19];
          if ( v20 != 0 )
          {
            coef_arrays -= v20;
            v21 = v16->look_sym[v19];
            goto LABEL_17;
          }
          v18 = 9;
        }
        else
        {
          v18 = 1;
        }
        v21 = jpeg_huff_decode(
                state: &v37,
                get_buffer: decompress_data,
                bits_left: coef_arrays,
                htbl: v16,
                min_bits: v18);
        if ( v21 < 0 )
          goto undoit;
        decompress_data = v37.get_buffer;
        coef_arrays = v37.bits_left;
LABEL_17:
        v22 = v21 & 0xF;
        v23 = v21 >> 4;
        if ( (v21 & 0xF) != 0 )
        {
          if ( v22 != 1 )
          {
            cinfo->err->msg_code = 118;
            cinfo->err->emit_message(a1: (jpeg_common_struct *)cinfo, a2: -1);
          }
          if ( coef_arrays < 1 )
          {
            if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                    state: &v37,
                                    get_buffer: decompress_data,
                                    bits_left: coef_arrays,
                                    nbits: 1) == 0 )
              goto undoit;
            decompress_data = v37.get_buffer;
            coef_arrays = v37.bits_left;
          }
          if ( ((decompress_data >> --coef_arrays) & 1) != 0 )
            v22 = v8;
          else
            v22 = v38;
        }
        else if ( v23 != 15 )
        {
          start_input_pass = 1 << v23;
          if ( v23 != 0 )
          {
            if ( coef_arrays < v23 )
            {
              if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                      state: &v37,
                                      get_buffer: decompress_data,
                                      bits_left: coef_arrays,
                                      nbits: v21 >> 4) == 0 )
              {
undoit:
                if ( v10 > 0 )
                {
                  v34 = v10;
                  v35 = &v39[4 * v10 + 4];
                  do
                  {
                    *(_WORD *)(2 * *--v35 + v11) = 0;
                    --v34;
                  }
                  while ( v34 != 0 );
                }
                return 0;
              }
              decompress_data = v37.get_buffer;
              coef_arrays = v37.bits_left;
            }
            coef_arrays -= v23;
            start_input_pass += (decompress_data >> coef_arrays) & (start_input_pass - 1);
          }
          v3 = v36;
          if ( start_input_pass == 0 )
            break;
LABEL_49:
          if ( v12 <= v3 )
          {
            v28 = v38;
            v29 = &jpeg_natural_order[v12];
            do
            {
              v30 = 2 * *v29;
              if ( *(_WORD *)(v30 + v11) != 0 )
              {
                if ( coef_arrays < 1 )
                {
                  if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                          state: &v37,
                                          get_buffer: decompress_data,
                                          bits_left: coef_arrays,
                                          nbits: 1) == 0 )
                    goto undoit;
                  decompress_data = v37.get_buffer;
                  coef_arrays = v37.bits_left;
                }
                if ( ((decompress_data >> --coef_arrays) & 1) != 0 )
                {
                  v31 = *(_WORD *)(v30 + v11);
                  if ( (v31 & v8) == 0 )
                  {
                    if ( v31 < 0 )
                      v32 = v31 + v28;
                    else
                      v32 = v31 + v8;
                    *(_WORD *)(v30 + v11) = v32;
                  }
                }
              }
              ++v12;
              ++v29;
            }
            while ( v12 <= v3 );
          }
          --start_input_pass;
          break;
        }
        v24 = &jpeg_natural_order[v12];
        do
        {
          v25 = 2 * *v24;
          if ( *(_WORD *)(v25 + v11) != 0 )
          {
            if ( coef_arrays < 1 )
            {
              if ( (unsigned __int8)jpeg_fill_bit_buffer(
                                      state: &v37,
                                      get_buffer: decompress_data,
                                      bits_left: coef_arrays,
                                      nbits: 1) == 0 )
                goto undoit;
              decompress_data = v37.get_buffer;
              coef_arrays = v37.bits_left;
            }
            if ( ((decompress_data >> --coef_arrays) & 1) != 0 )
            {
              v26 = *(_WORD *)(v25 + v11);
              if ( (v26 & v8) == 0 )
              {
                if ( v26 < 0 )
                  *(_WORD *)(v25 + v11) = v26 + v38;
                else
                  *(_WORD *)(v25 + v11) = v26 + v8;
              }
            }
          }
          else if ( --v23 < 0 )
          {
            break;
          }
          ++v12;
          ++v24;
        }
        while ( v12 <= v36 );
        if ( v22 != 0 )
        {
          ++v10;
          v27 = jpeg_natural_order[v12];
          *++v17 = v27;
          *(_WORD *)(2 * v27 + v11) = v22;
        }
        ++v12;
      }
      while ( v12 <= v36 );
    }
    cinfo->src->next_input_byte = v37.next_input_byte;
    cinfo->src->bytes_in_buffer = v37.bytes_in_buffer;
    coef->decompress_data = (int (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 ***))decompress_data;
    coef->coef_arrays = (jvirt_barray_control **)coef_arrays;
    coef[1].start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))start_input_pass;
  }
  --coef[2].start_input_pass;
  return 1;
}


// ========================================================================
// start_pass_phuff_decoder
// EA  : 0x83237130
// RVA : 0x01237130
// PDB : w:\tech5\libs\jpeg\jdphuff.cpp
// ========================================================================

void __fastcall start_pass_phuff_decoder(jpeg_common_struct *cinfo)
{
  signed int mem; // r10
  jpeg_d_coef_controller *err; // r24
  char v4; // r11
  char v5; // r9
  BOOL v6; // r22
  int progress; // r11
  bool v8; // zf
  bool v9; // cr58
  int client_data; // r11
  int v11; // r25
  int *p_progress; // r26
  int v13; // r28
  int *v14; // r29
  int v15; // r30
  int *v16; // r29
  int (__fastcall *v17)(jpeg_decompress_struct *, __int16 (**)[64]); // r10
  int v18; // r28
  jpeg_d_coef_controller *v19; // r27
  int *v20; // r29
  int v21; // r11
  unsigned int v22; // r5
  d_derived_tbl **v23; // r30

  mem = (signed int)cinfo[15].mem;
  err = (jpeg_d_coef_controller *)cinfo[17].err;
  v4 = _cntlzw(mem);
  v5 = 0;
  v6 = (v4 & 0x20) != 0;
  v8 = (v4 & 0x20) == 0;
  progress = (int)cinfo[15].progress;
  if ( v8 )
  {
    if ( mem > progress || progress >= 64 )
      v5 = 1;
    v9 = cinfo[12].mem == (jpeg_memory_mgr *)1;
  }
  else
  {
    v9 = progress == 0;
  }
  if ( !v9 )
    v5 = 1;
  client_data = (int)cinfo[15].client_data;
  if ( client_data != 0 && *(_DWORD *)&cinfo[15].is_decompressor != client_data - 1 )
    v5 = 1;
  if ( *(int *)&cinfo[15].is_decompressor > 13 )
    v5 = 1;
  if ( v5 != 0 )
  {
    cinfo->err->msg_code = 16;
    cinfo->err->msg_parm.i[0] = (int)cinfo[15].mem;
    cinfo->err->msg_parm.i[1] = (int)cinfo[15].progress;
    cinfo->err->msg_parm.i[2] = (int)cinfo[15].client_data;
    cinfo->err->msg_parm.i[3] = *(_DWORD *)&cinfo[15].is_decompressor;
    cinfo->err->error_exit(a1: cinfo);
  }
  v11 = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_progress = (int *)&cinfo[12].progress;
    do
    {
      v13 = *(_DWORD *)(*p_progress + 4);
      v14 = (int *)((v13 << 8) + cinfo[5].global_state);
      if ( !v6 && *v14 < 0 )
      {
        cinfo->err->msg_code = 115;
        cinfo->err->msg_parm.i[0] = v13;
        cinfo->err->msg_parm.i[1] = 0;
        cinfo->err->emit_message(a1: cinfo, a2: -1);
      }
      v15 = (int)cinfo[15].mem;
      if ( v15 <= (int)cinfo[15].progress )
      {
        v16 = &v14[v15 - 1];
        do
        {
          if ( cinfo[15].client_data != (void *)((((unsigned int)v16[1] >> 31) - 1) & v16[1]) )
          {
            cinfo->err->msg_code = 115;
            cinfo->err->msg_parm.i[0] = v13;
            cinfo->err->msg_parm.i[1] = v15;
            cinfo->err->emit_message(a1: cinfo, a2: -1);
          }
          ++v15;
          *++v16 = *(_DWORD *)&cinfo[15].is_decompressor;
        }
        while ( v15 <= (int)cinfo[15].progress );
      }
      ++v11;
      ++p_progress;
    }
    while ( v11 < (int)cinfo[12].mem );
  }
  if ( cinfo[15].client_data != nullptr )
  {
    if ( v6 )
      v17 = decode_mcu_DC_refine;
    else
      v17 = decode_mcu_AC_refine;
  }
  else if ( v6 )
  {
    v17 = decode_mcu_DC_first;
  }
  else
  {
    v17 = decode_mcu_AC_first;
  }
  err->consume_data = (int (__fastcall *)(jpeg_decompress_struct *))v17;
  v18 = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    v19 = err + 1;
    v20 = (int *)&cinfo[12].progress;
    do
    {
      v21 = *v20;
      if ( v6 )
      {
        if ( cinfo[15].client_data == nullptr )
          jpeg_make_d_derived_tbl(
            cinfo,
            isDC: 1u,
            tblno: *(_DWORD *)(v21 + 20),
            pdtbl: (d_derived_tbl **)&err[2].consume_data + *(_DWORD *)(v21 + 20));
      }
      else
      {
        v22 = *(_DWORD *)(v21 + 24);
        v23 = (d_derived_tbl **)(&err[2].consume_data + v22);
        jpeg_make_d_derived_tbl(cinfo, isDC: 0, tblno: v22, pdtbl: v23);
        err[3].start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))*v23;
      }
      ++v18;
      v19 = (jpeg_d_coef_controller *)((char *)v19 + 4);
      v19->start_input_pass = nullptr;
      ++v20;
    }
    while ( v18 < (int)cinfo[12].mem );
  }
  HIBYTE(err->start_output_pass) = 0;
  err[1].start_input_pass = nullptr;
  err->decompress_data = nullptr;
  err->coef_arrays = nullptr;
  err[2].start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))cinfo[10].client_data;
}


// ========================================================================
// ?jinit_phuff_decoder@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x83237420
// RVA : 0x01237420
// PDB : w:\tech5\libs\jpeg\jdphuff.cpp
// ========================================================================

void __fastcall jinit_phuff_decoder(jpeg_common_struct *cinfo)
{
  jpeg_d_coef_controller *v2; // r3
  int v3; // r30
  int v4; // r3
  int client_data; // r10
  int v6; // r9
  _DWORD *v7; // r11
  int i; // ctr

  v2 = (jpeg_d_coef_controller *)((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[17].err = (jpeg_error_mgr *)v2;
  v3 = 0;
  v2->start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))start_pass_phuff_decoder;
  v2[2].consume_data = nullptr;
  v2[2].start_output_pass = nullptr;
  v2[2].decompress_data = nullptr;
  v2[2].coef_arrays = nullptr;
  v4 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: (int)cinfo[1].client_data << 8);
  client_data = (int)cinfo[1].client_data;
  v6 = v4;
  cinfo[5].global_state = v4;
  if ( client_data > 0 )
  {
    do
    {
      v7 = (_DWORD *)(v6 - 4);
      for ( i = 64; i != 0; --i )
        *++v7 = -1;
      ++v3;
      v6 += 256;
    }
    while ( v3 < (int)cinfo[1].client_data );
  }
}

