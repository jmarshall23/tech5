
// ========================================================================
// start_iMCU_row
// EA  : 0x83234608
// RVA : 0x01234608
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

void __fastcall start_iMCU_row(jpeg_decompress_struct *cinfo)
{
  _DWORD *Al; // r11
  int min_DCT_scaled_size; // r10
  int v3; // r9

  Al = (_DWORD *)cinfo->Al;
  if ( cinfo->max_v_samp_factor <= 1 )
  {
    min_DCT_scaled_size = cinfo->min_DCT_scaled_size;
    if ( cinfo->actual_number_of_colors >= (unsigned int)&cinfo->marker_list[-1].data + 3 )
      v3 = *(_DWORD *)(min_DCT_scaled_size + 72);
    else
      v3 = *(_DWORD *)(min_DCT_scaled_size + 12);
    Al[5] = 0;
    Al[6] = 0;
    Al[7] = v3;
  }
  else
  {
    Al[7] = 1;
    Al[5] = 0;
    Al[6] = 0;
  }
}


// ========================================================================
// start_input_pass_0
// EA  : 0x83234678
// RVA : 0x01234678
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

void __fastcall start_input_pass_0(jpeg_decompress_struct *cinfo)
{
  cinfo->actual_number_of_colors = 0;
  start_iMCU_row(cinfo);
}


// ========================================================================
// decompress_onepass
// EA  : 0x83234688
// RVA : 0x01234688
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

int __fastcall decompress_onepass(jpeg_decompress_struct *cinfo, unsigned __int8 ***output_buf)
{
  int Al; // r22
  char *v5; // r29
  int v6; // r18
  unsigned int v7; // r19
  int v8; // r20
  int v9; // r14
  int *p_min_DCT_scaled_size; // r15
  _DWORD *v11; // r30
  int v12; // r11
  void (__fastcall *v13)(jpeg_decompress_struct *, _DWORD *, _DWORD, unsigned __int8 **, int); // r23
  int v14; // r26
  unsigned __int8 **v15; // r9
  int v16; // r24
  int v17; // r11
  int v18; // r21
  unsigned __int8 **v19; // r28
  int v20; // r29
  int i; // r31
  jpeg_marker_struct *marker_list; // r10
  unsigned int v23; // r11
  _DWORD *v24; // r9
  int min_DCT_scaled_size; // r11
  bool v27; // zf
  int v28; // r10
  char *v29; // [sp+50h] [-A0h]
  char *v30; // [sp+54h] [-9Ch]

  Al = cinfo->Al;
  v5 = (char *)&cinfo->cur_comp_info[0][-1].dct_table + 3;
  v30 = v5;
  v6 = *(_DWORD *)(Al + 24);
  v29 = (char *)&cinfo->marker_list[-1].data + 3;
  if ( v6 >= *(_DWORD *)(Al + 28) )
  {
LABEL_21:
    marker_list = cinfo->marker_list;
    v23 = cinfo->actual_number_of_colors + 1;
    ++cinfo->output_scanline;
    cinfo->actual_number_of_colors = v23;
    if ( v23 >= (unsigned int)marker_list )
    {
      cinfo->master[1].prepare_for_output_pass(a1: cinfo);
      return 4;
    }
    else
    {
      v24 = (_DWORD *)cinfo->Al;
      if ( cinfo->max_v_samp_factor <= 1 )
      {
        v27 = v23 >= (unsigned int)&marker_list[-1].data + 3;
        min_DCT_scaled_size = cinfo->min_DCT_scaled_size;
        if ( v27 )
          v28 = *(_DWORD *)(min_DCT_scaled_size + 72);
        else
          v28 = *(_DWORD *)(min_DCT_scaled_size + 12);
        v24[5] = 0;
        v24[6] = 0;
        v24[7] = v28;
        return 3;
      }
      else
      {
        v24[5] = 0;
        v24[6] = 0;
        v24[7] = 1;
        return 3;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(Al + 20);
      if ( v7 <= (unsigned int)v5 )
        break;
LABEL_20:
      ++v6;
      *(_DWORD *)(Al + 20) = 0;
      if ( v6 >= *(_DWORD *)(Al + 28) )
        goto LABEL_21;
    }
    while ( 1 )
    {
      jzero_far(target: *(void **)(Al + 32), bytestozero: (int)cinfo->cur_comp_info[2] << 7);
      if ( ((unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, int))cinfo->coef->consume_data)(
             a1: cinfo,
             a2: Al + 32) == 0 )
        break;
      v8 = 0;
      v9 = 0;
      if ( cinfo->max_v_samp_factor > 0 )
      {
        p_min_DCT_scaled_size = &cinfo->min_DCT_scaled_size;
        do
        {
          v11 = (_DWORD *)*p_min_DCT_scaled_size;
          if ( *(_BYTE *)(*p_min_DCT_scaled_size + 48) != 0 )
          {
            v12 = v11[1];
            v13 = *(void (__fastcall **)(jpeg_decompress_struct *, _DWORD *, _DWORD, unsigned __int8 **, int))((char *)&cinfo->post->post_process_data + v12 * 4);
            if ( v7 >= (unsigned int)v5 )
              v14 = v11[17];
            else
              v14 = v11[13];
            v15 = output_buf[v12];
            v16 = 0;
            v17 = v11[9];
            v18 = v11[16] * v7;
            v19 = &v15[v17 * v6];
            if ( (int)v11[14] > 0 )
            {
              do
              {
                if ( cinfo->actual_number_of_colors < (unsigned int)v29 || v16 + v6 < v11[18] )
                {
                  v20 = v18;
                  for ( i = 0; i < v14; v20 += v17 )
                  {
                    v13(a1: cinfo, a2: v11, a3: *(_DWORD *)(4 * (v8 + 8 + i) + Al), a4: v19, a5: v20);
                    v17 = v11[9];
                    ++i;
                  }
                }
                ++v16;
                v8 += v11[13];
                v19 += v17;
              }
              while ( v16 < v11[14] );
              v5 = v30;
            }
          }
          else
          {
            v8 += v11[15];
          }
          ++v9;
          ++p_min_DCT_scaled_size;
        }
        while ( v9 < cinfo->max_v_samp_factor );
      }
      if ( ++v7 > (unsigned int)v5 )
        goto LABEL_20;
    }
    *(_DWORD *)(Al + 24) = v6;
    *(_DWORD *)(Al + 20) = v7;
    return 0;
  }
}


// ========================================================================
// consume_data
// EA  : 0x83234928
// RVA : 0x01234928
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

int __fastcall consume_data(jpeg_common_struct *cinfo)
{
  jpeg_progress_mgr *progress; // r27
  int v3; // r31
  int *p_mem; // r30
  int *v5; // r29
  __int16 (**v6)[64]; // r3
  int mem; // r10
  int pass_counter; // r23
  int v9; // r24
  jpeg_component_info *progress_monitor; // r26
  int v11; // r6
  int v12; // r29
  char *v13; // r30
  int *p_progress; // r31
  int v15; // r7
  int v16; // r3
  int v17; // r9
  int v18; // r4
  _DWORD *v19; // r5
  int v20; // r11
  int v21; // r10
  int *v22; // r8
  jpeg_marker_struct *global_state; // r9
  unsigned int v24; // r11
  jpeg_progress_mgr *v25; // r10
  int v27; // r11
  bool v28; // zf
  int v29; // r9
  int v30; // [sp+4Ch] [-74h] BYREF
  char v31; // [sp+50h] [-70h] BYREF

  progress = cinfo[16].progress;
  v3 = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_mem = (int *)&cinfo[12].mem;
    v5 = &v30;
    do
    {
      ++p_mem;
      v6 = cinfo->mem->access_virt_barray(
             a1: cinfo,
             a2: *(&progress[3].completed_passes + *(_DWORD *)(*p_mem + 4)),
             a3: (int)cinfo[5].progress * *(_DWORD *)(*p_mem + 12),
             a4: *(_DWORD *)(*p_mem + 12),
             a5: 1);
      mem = (int)cinfo[12].mem;
      *++v5 = (int)v6;
      ++v3;
    }
    while ( v3 < mem );
  }
  pass_counter = progress[1].pass_counter;
  if ( pass_counter >= progress[1].pass_limit )
  {
LABEL_19:
    global_state = (jpeg_marker_struct *)cinfo[11].global_state;
    v24 = (unsigned int)&cinfo[5].progress->progress_monitor + 1;
    cinfo[5].progress = (jpeg_progress_mgr *)v24;
    if ( v24 >= (unsigned int)global_state )
    {
      (*(void (__fastcall **)(jpeg_common_struct *))(*(_DWORD *)&cinfo[16].is_decompressor + 12))(a1: cinfo);
      return 4;
    }
    else
    {
      v25 = cinfo[16].progress;
      if ( (int)cinfo[12].mem <= 1 )
      {
        v28 = v24 >= (unsigned int)&global_state[-1].data + 3;
        v27 = (int)cinfo[12].progress;
        if ( v28 )
          v29 = *(_DWORD *)(v27 + 72);
        else
          v29 = *(_DWORD *)(v27 + 12);
        v25[1].progress_monitor = nullptr;
        v25[1].pass_counter = 0;
        v25[1].pass_limit = v29;
        return 3;
      }
      else
      {
        v25[1].progress_monitor = nullptr;
        v25[1].pass_counter = 0;
        v25[1].pass_limit = 1;
        return 3;
      }
    }
  }
  else
  {
    v9 = 4 * pass_counter;
    while ( 1 )
    {
      progress_monitor = (jpeg_component_info *)progress[1].progress_monitor;
      if ( (jpeg_error_mgr *)progress_monitor < cinfo[13].err )
        break;
LABEL_18:
      ++pass_counter;
      progress[1].progress_monitor = nullptr;
      v9 += 4;
      if ( pass_counter >= progress[1].pass_limit )
        goto LABEL_19;
    }
    while ( 1 )
    {
      v11 = 0;
      v12 = 0;
      if ( (int)cinfo[12].mem > 0 )
      {
        v13 = &v31;
        p_progress = (int *)&cinfo[12].progress;
        do
        {
          v15 = *p_progress;
          v16 = 0;
          v17 = *(_DWORD *)(*p_progress + 52);
          if ( *(int *)(*p_progress + 56) > 0 )
          {
            v18 = (v17 * (_DWORD)progress_monitor) << 7;
            v19 = (_DWORD *)(*(_DWORD *)v13 + v9);
            do
            {
              v20 = 0;
              v21 = *v19 + v18;
              if ( v17 > 0 )
              {
                v22 = &progress[1].pass_limit + v11;
                do
                {
                  ++v20;
                  *++v22 = v21;
                  v17 = *(_DWORD *)(v15 + 52);
                  ++v11;
                  v21 += 128;
                }
                while ( v20 < v17 );
              }
              ++v16;
              ++v19;
            }
            while ( v16 < *(_DWORD *)(v15 + 56) );
          }
          ++v12;
          ++p_progress;
          v13 += 4;
        }
        while ( v12 < (int)cinfo[12].mem );
      }
      if ( ((unsigned __int8 (__fastcall *)(jpeg_common_struct *, int *))cinfo[17].err->emit_message)(
             a1: cinfo,
             a2: &progress[1].completed_passes) == 0 )
        break;
      progress_monitor = (jpeg_component_info *)((char *)progress_monitor + 1);
      if ( (jpeg_error_mgr *)progress_monitor >= cinfo[13].err )
        goto LABEL_18;
    }
    progress[1].pass_counter = pass_counter;
    progress[1].progress_monitor = (void (__fastcall *)(jpeg_common_struct *))progress_monitor;
    return 0;
  }
}


// ========================================================================
// decompress_data
// EA  : 0x83234B90
// RVA : 0x01234B90
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

int __fastcall decompress_data(jpeg_common_struct *cinfo, unsigned __int8 ***output_buf)
{
  int progress; // r30
  char *v5; // r18
  int result; // r3
  int v7; // r21
  JHUFF_TBL *mem; // r31
  int v9; // r22
  int v10; // r20
  __int16 (**v11)[64]; // r3
  int v12; // r10
  unsigned int v13; // r11
  unsigned int v14; // r10
  unsigned __int8 **v15; // r26
  void (__fastcall *v16)(jpeg_common_struct *, JHUFF_TBL *, __int16 *, unsigned __int8 **, int); // r25
  unsigned int v17; // r11
  __int16 (**v18)[64]; // r24
  int i; // r23
  __int16 *v20; // r29
  int v21; // r28
  unsigned int j; // r30
  jpeg_marker_struct *global_state; // r10
  unsigned int v24; // r11

  progress = (int)cinfo[16].progress;
  v5 = (char *)(cinfo[11].global_state - 1);
  while ( *(_QWORD *)&cinfo[5].mem <= *(_QWORD *)&cinfo[5].client_data )
  {
    result = (**(int (__fastcall ***)(jpeg_common_struct *))&cinfo[16].is_decompressor)(a1: cinfo);
    if ( result == 0 )
      return result;
  }
  v7 = 0;
  mem = (JHUFF_TBL *)cinfo[8].mem;
  if ( (int)cinfo[1].client_data > 0 )
  {
    v9 = 0;
    v10 = progress + 72;
    do
    {
      if ( mem->huffval[31] != 0 )
      {
        v11 = cinfo->mem->access_virt_barray(
                a1: cinfo,
                a2: *(_DWORD *)(v10 + v9 * 4),
                a3: *(_DWORD *)&cinfo[5].is_decompressor * *(_DWORD *)&mem->bits[12],
                a4: *(_DWORD *)&mem->bits[12],
                a5: 0);
        if ( *(_DWORD *)&cinfo[5].is_decompressor >= (unsigned int)v5 )
        {
          v13 = *(_DWORD *)&mem->bits[12];
          v14 = *(_DWORD *)&mem->huffval[15];
          __twllei(v13, 0);
          v12 = v14 % v13;
          if ( v12 == 0 )
            v12 = v13;
        }
        else
        {
          v12 = *(_DWORD *)&mem->bits[12];
        }
        v15 = output_buf[v9];
        v16 = *(void (__fastcall **)(jpeg_common_struct *, JHUFF_TBL *, __int16 *, unsigned __int8 **, int))((char *)&cinfo[17].mem->alloc_large + v9 * 4);
        if ( v12 > 0 )
        {
          v17 = *(_DWORD *)&mem->huffval[11];
          v18 = v11;
          for ( i = v12; i != 0; --i )
          {
            v20 = (__int16 *)*v18;
            v21 = 0;
            for ( j = 0; j < v17; v21 += *(_DWORD *)&mem->huffval[19] )
            {
              v16(a1: cinfo, a2: mem, a3: v20, a4: v15, a5: v21);
              v17 = *(_DWORD *)&mem->huffval[11];
              ++j;
              v20 += 64;
            }
            ++v18;
            v15 += *(_DWORD *)&mem->huffval[19];
          }
        }
      }
      ++v7;
      ++v9;
      mem = (JHUFF_TBL *)((char *)mem + 84);
    }
    while ( v7 < (int)cinfo[1].client_data );
  }
  global_state = (jpeg_marker_struct *)cinfo[11].global_state;
  v24 = *(_DWORD *)&cinfo[5].is_decompressor + 1;
  *(_DWORD *)&cinfo[5].is_decompressor = v24;
  return (v24 >= (unsigned int)global_state) - 1 + 4;
}


// ========================================================================
// smoothing_ok
// EA  : 0x83234D48
// RVA : 0x01234D48
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

int __fastcall smoothing_ok(jpeg_decompress_struct *cinfo)
{
  int Al; // r31
  int v3; // r29
  int v4; // r7
  _DWORD *v5; // r9
  int v6; // r8
  unsigned __int8 *i; // r6
  _WORD *v8; // r11
  int *v9; // r11

  Al = cinfo->Al;
  v3 = 0;
  if ( HIBYTE(cinfo->ac_huff_tbl_ptrs[2]) != 0 && cinfo->input_scan_number != 0 )
  {
    if ( *(_DWORD *)(Al + 112) == 0 )
      *(_DWORD *)(Al + 112) = ((int (*)(void))cinfo->mem->alloc_small)();
    v4 = 0;
    v5 = *(_DWORD **)(Al + 112);
    if ( cinfo->num_components <= 0 )
      return v3;
    v6 = 0;
    for ( i = &cinfo->ac_huff_tbl_ptrs[1]->huffval[59]; ; i += 84 )
    {
      v8 = *(_WORD **)i;
      if ( *(_DWORD *)i == 0 )
        break;
      if ( *v8 == 0 )
        break;
      if ( v8[1] == 0 )
        break;
      if ( v8[8] == 0 )
        break;
      if ( v8[16] == 0 )
        break;
      if ( v8[9] == 0 )
        break;
      if ( v8[2] == 0 )
        break;
      v9 = (int *)(v6 + cinfo->input_scan_number);
      if ( *v9 < 0 )
        break;
      v5[1] = v9[1];
      if ( v9[1] != 0 )
        v3 = 1;
      v5[2] = v9[2];
      if ( v9[2] != 0 )
        v3 = 1;
      v5[3] = v9[3];
      if ( v9[3] != 0 )
        v3 = 1;
      v5[4] = v9[4];
      if ( v9[4] != 0 )
        v3 = 1;
      v5[5] = v9[5];
      if ( v9[5] != 0 )
        v3 = 1;
      ++v4;
      v5 += 6;
      v6 += 256;
      if ( v4 >= cinfo->num_components )
        return v3;
    }
  }
  return 0;
}


// ========================================================================
// decompress_smooth_data
// EA  : 0x83234EE8
// RVA : 0x01234EE8
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

int __fastcall decompress_smooth_data(jpeg_common_struct *cinfo, unsigned __int8 ***output_buf)
{
  jpeg_decomp_master *v4; // r9
  JHUFF_TBL *mem; // r16
  unsigned int v6; // r10
  unsigned int v7; // r11
  unsigned __int8 v8; // r30
  int v9; // r28
  unsigned int v10; // r6
  unsigned int v12; // r9
  jvirt_barray_control *v13; // r4
  __int16 (**v14)[64]; // r3
  unsigned __int8 v15; // r9
  unsigned __int16 *v16; // r7
  int v17; // r15
  __int16 (**v18)[64]; // r11
  __int16 *v19; // r19
  __int16 *v20; // r9
  __int16 *v21; // r11
  int v22; // r20
  unsigned int v23; // r21
  int v24; // r25
  int v25; // r28
  int v26; // r24
  int v27; // r23
  int v28; // r26
  int v29; // r22
  int v30; // r30
  int v31; // r27
  int v32; // r29
  unsigned int v33; // r31
  __int16 *v34; // r18
  __int16 *v35; // r17
  int v36; // r10
  int v37; // r11
  int v38; // r6
  int v39; // r11
  int v40; // r10
  int v41; // r5
  int v42; // r11
  int v43; // r10
  int v44; // r10
  int v45; // r11
  int v46; // r6
  int v47; // r11
  int v48; // r10
  int v49; // r5
  int v50; // r11
  int v51; // r10
  int v52; // r9
  int v53; // r11
  int v54; // r6
  int v55; // r11
  int v56; // r5
  int v57; // r11
  int v58; // r9
  int v59; // r11
  int v60; // r6
  int v61; // r11
  int v62; // r5
  int v63; // r11
  int v64; // r9
  int v65; // r11
  int v66; // r7
  int v67; // r11
  int v68; // r6
  int v69; // r11
  int v70; // r11
  jpeg_marker_struct *global_state; // r9
  unsigned int v72; // r11
  int v73; // [sp+50h] [-170h]
  jvirt_barray_control **v74; // [sp+54h] [-16Ch]
  int v75; // [sp+58h] [-168h]
  int v76; // [sp+5Ch] [-164h]
  unsigned __int8 **v77; // [sp+60h] [-160h]
  unsigned __int8 ***v78; // [sp+64h] [-15Ch]
  int v79; // [sp+68h] [-158h]
  int v80; // [sp+6Ch] [-154h]
  int progress; // [sp+70h] [-150h]
  int v82; // [sp+74h] [-14Ch]
  int v83; // [sp+78h] [-148h]
  int v84; // [sp+7Ch] [-144h]
  int v85; // [sp+80h] [-140h]
  __int16 (**v86)[64]; // [sp+84h] [-13Ch]
  char *v87; // [sp+88h] [-138h]
  int v88; // [sp+8Ch] [-134h]
  _DWORD *v89; // [sp+90h] [-130h]
  int v90; // [sp+94h] [-12Ch]
  void (__fastcall *v91)(jpeg_common_struct *, JHUFF_TBL *, __int16 *, unsigned __int8 **, int); // [sp+98h] [-128h]
  __int16 v92[144]; // [sp+A0h] [-120h] BYREF

  progress = (int)cinfo[16].progress;
  v87 = (char *)(cinfo[11].global_state - 1);
  while ( (int)cinfo[5].mem <= (int)cinfo[5].client_data )
  {
    v4 = *(jpeg_decomp_master **)&cinfo[16].is_decompressor;
    if ( BYTE1(v4[1].finish_output_pass) != 0
      || cinfo[5].mem == cinfo[5].client_data
      && cinfo[5].progress > (jpeg_progress_mgr *)(((_cntlzw((unsigned int)cinfo[15].mem) & 0x20) != 0)
                                                 + *(_DWORD *)&cinfo[5].is_decompressor) )
    {
      break;
    }
    if ( ((int (__fastcall *)(jpeg_common_struct *))v4->prepare_for_output_pass)(a1: cinfo) == 0 )
      return 0;
  }
  mem = (JHUFF_TBL *)cinfo[8].mem;
  v80 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    v78 = output_buf;
    v76 = 0;
    v74 = (jvirt_barray_control **)(progress + 72);
    do
    {
      if ( mem->huffval[31] != 0 )
      {
        v6 = *(_DWORD *)&cinfo[5].is_decompressor;
        v7 = *(_DWORD *)&mem->bits[12];
        if ( v6 >= (unsigned int)v87 )
        {
          v12 = *(_DWORD *)&mem->huffval[15];
          __twllei(v7, 0);
          v9 = v12 % v7;
          v73 = v12 % v7;
          if ( v12 % v7 == 0 )
          {
            v9 = *(_DWORD *)&mem->bits[12];
            v73 = v9;
          }
          v10 = v9;
          v8 = 1;
        }
        else
        {
          v8 = 0;
          v73 = *(_DWORD *)&mem->bits[12];
          v9 = v73;
          v10 = 2 * v7;
        }
        v13 = *v74;
        if ( v6 != 0 )
        {
          v14 = cinfo->mem->access_virt_barray(a1: cinfo, a2: v13, a3: (v6 - 1) * v7, a4: v7 + v10, a5: 0);
          v15 = 0;
          v86 = &v14[*(_DWORD *)&mem->bits[12]];
        }
        else
        {
          v86 = cinfo->mem->access_virt_barray(a1: cinfo, a2: v13, a3: 0, a4: v10, a5: 0);
          v15 = 1;
        }
        v16 = *(unsigned __int16 **)&mem->huffval[59];
        v75 = 0;
        v17 = *v16;
        v77 = *v78;
        v89 = (_DWORD *)(*(_DWORD *)(progress + 112) + v76);
        v85 = v16[1];
        v83 = v16[8];
        v79 = v16[16];
        v82 = v16[9];
        v84 = v16[2];
        v91 = *(void (__fastcall **)(jpeg_common_struct *, JHUFF_TBL *, __int16 *, unsigned __int8 **, int))((char *)&cinfo[17].mem[-1] + (unsigned int)v74 - progress - 16);
        if ( v9 > 0 )
        {
          v90 = v15;
          v88 = v8;
          do
          {
            v18 = &v86[v75];
            v19 = (__int16 *)*v18;
            if ( v90 == 0 || (v20 = (__int16 *)*v18, v75 != 0) )
              v20 = (__int16 *)*(v18 - 1);
            if ( v88 != 0 && v75 == v73 - 1 )
              v21 = (__int16 *)*v18;
            else
              v21 = (__int16 *)v18[1];
            v22 = 0;
            v23 = 0;
            v24 = *v20;
            v25 = *v19;
            v26 = *v21;
            v27 = v24;
            v28 = v25;
            v29 = v26;
            v30 = v24;
            v31 = v25;
            v32 = v26;
            v33 = *(_DWORD *)&mem->huffval[11] - 1;
            v34 = v20 + 64;
            v35 = v21 + 64;
            do
            {
              jcopy_block_row(input_row: (__int16 (*)[64])v19, output_row: (__int16 (*)[64])v92, num_blocks: 1u);
              if ( v23 < v33 )
              {
                v24 = *v34;
                v25 = v19[64];
                v26 = *v35;
              }
              v36 = v89[1];
              if ( v36 != 0 && v92[1] == 0 )
              {
                v37 = 36 * (v31 - v25) * v17;
                if ( v37 < 0 )
                {
                  v41 = (v85 << 7) - v37;
                  __twllei(v85 << 8, 0);
                  v42 = v41 / (v85 << 8);
                  __twlgei((v85 << 8) & ~(__ROL4__(v41, 1) - 1), 0xFFFFFFFF);
                  if ( v36 > 0 )
                  {
                    v43 = 1 << v36;
                    if ( v42 >= v43 )
                      v42 = v43 - 1;
                  }
                  v39 = -v42;
                }
                else
                {
                  v38 = (v85 << 7) + v37;
                  __twllei(v85 << 8, 0);
                  v39 = v38 / (v85 << 8);
                  __twlgei((v85 << 8) & ~(__ROL4__(v38, 1) - 1), 0xFFFFFFFF);
                  if ( v36 > 0 )
                  {
                    v40 = 1 << v36;
                    if ( v39 >= v40 )
                      LOWORD(v39) = v40 - 1;
                  }
                }
                v92[1] = v39;
              }
              v44 = v89[2];
              if ( v44 != 0 && v92[8] == 0 )
              {
                v45 = 36 * (v27 - v29) * v17;
                if ( v45 < 0 )
                {
                  v49 = (v83 << 7) - v45;
                  __twllei(v83 << 8, 0);
                  v50 = v49 / (v83 << 8);
                  __twlgei((v83 << 8) & ~(__ROL4__(v49, 1) - 1), 0xFFFFFFFF);
                  if ( v44 > 0 )
                  {
                    v51 = 1 << v44;
                    if ( v50 >= v51 )
                      v50 = v51 - 1;
                  }
                  v47 = -v50;
                }
                else
                {
                  v46 = (v83 << 7) + v45;
                  __twllei(v83 << 8, 0);
                  v47 = v46 / (v83 << 8);
                  __twlgei((v83 << 8) & ~(__ROL4__(v46, 1) - 1), 0xFFFFFFFF);
                  if ( v44 > 0 )
                  {
                    v48 = 1 << v44;
                    if ( v47 >= v48 )
                      LOWORD(v47) = v48 - 1;
                  }
                }
                v92[8] = v47;
              }
              v52 = v89[3];
              if ( v52 != 0 && v92[16] == 0 )
              {
                v53 = 9 * (v29 - 2 * v28 + v27) * v17;
                if ( v53 < 0 )
                {
                  v56 = (v79 << 7) - v53;
                  __twllei(v79 << 8, 0);
                  v57 = v56 / (v79 << 8);
                  __twlgei((v79 << 8) & ~(__ROL4__(v56, 1) - 1), 0xFFFFFFFF);
                  if ( v52 > 0 && v57 >= 1 << v52 )
                    v57 = (1 << v52) - 1;
                  v55 = -v57;
                }
                else
                {
                  v54 = (v79 << 7) + v53;
                  __twllei(v79 << 8, 0);
                  v55 = v54 / (v79 << 8);
                  __twlgei((v79 << 8) & ~(__ROL4__(v54, 1) - 1), 0xFFFFFFFF);
                  if ( v52 > 0 && v55 >= 1 << v52 )
                    LOWORD(v55) = (1 << v52) - 1;
                }
                v92[16] = v55;
              }
              v58 = v89[4];
              if ( v58 != 0 && v92[9] == 0 )
              {
                v59 = 5 * (v26 - v32 - v24 + v30) * v17;
                if ( v59 < 0 )
                {
                  v62 = (v82 << 7) - v59;
                  __twllei(v82 << 8, 0);
                  v63 = v62 / (v82 << 8);
                  __twlgei((v82 << 8) & ~(__ROL4__(v62, 1) - 1), 0xFFFFFFFF);
                  if ( v58 > 0 && v63 >= 1 << v58 )
                    v63 = (1 << v58) - 1;
                  v61 = -v63;
                }
                else
                {
                  v60 = (v82 << 7) + v59;
                  __twllei(v82 << 8, 0);
                  v61 = v60 / (v82 << 8);
                  __twlgei((v82 << 8) & ~(__ROL4__(v60, 1) - 1), 0xFFFFFFFF);
                  if ( v58 > 0 && v61 >= 1 << v58 )
                    LOWORD(v61) = (1 << v58) - 1;
                }
                v92[9] = v61;
              }
              v64 = v89[5];
              if ( v64 != 0 && v92[2] == 0 )
              {
                v65 = 9 * (v25 - 2 * v28 + v31) * v17;
                if ( v65 < 0 )
                {
                  v68 = (v84 << 7) - v65;
                  __twllei(v84 << 8, 0);
                  v69 = v68 / (v84 << 8);
                  __twlgei((v84 << 8) & ~(__ROL4__(v68, 1) - 1), 0xFFFFFFFF);
                  if ( v64 > 0 && v69 >= 1 << v64 )
                    v69 = (1 << v64) - 1;
                  v67 = -v69;
                }
                else
                {
                  v66 = (v84 << 7) + v65;
                  __twllei(v84 << 8, 0);
                  v67 = v66 / (v84 << 8);
                  __twlgei((v84 << 8) & ~(__ROL4__(v66, 1) - 1), 0xFFFFFFFF);
                  if ( v64 > 0 && v67 >= 1 << v64 )
                    LOWORD(v67) = (1 << v64) - 1;
                }
                v92[2] = v67;
              }
              v91(a1: cinfo, a2: mem, a3: v92, a4: v77, a5: v22);
              v70 = *(_DWORD *)&mem->huffval[19];
              ++v23;
              v30 = v27;
              v31 = v28;
              v32 = v29;
              v27 = v24;
              v28 = v25;
              v29 = v26;
              v19 += 64;
              v34 += 64;
              v35 += 64;
              v22 += v70;
            }
            while ( v23 <= v33 );
            v77 += v70;
            ++v75;
          }
          while ( v75 < v73 );
        }
      }
      mem = (JHUFF_TBL *)((char *)mem + 84);
      v76 += 24;
      ++v74;
      ++v78;
      ++v80;
    }
    while ( v80 < (int)cinfo[1].client_data );
  }
  global_state = (jpeg_marker_struct *)cinfo[11].global_state;
  v72 = *(_DWORD *)&cinfo[5].is_decompressor + 1;
  *(_DWORD *)&cinfo[5].is_decompressor = v72;
  return (v72 >= (unsigned int)global_state) - 1 + 4;
}


// ========================================================================
// start_output_pass
// EA  : 0x832356A0
// RVA : 0x012356A0
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

void __fastcall start_output_pass(jpeg_decompress_struct *cinfo)
{
  int Al; // r30

  Al = cinfo->Al;
  if ( *(_DWORD *)(Al + 16) != 0 )
  {
    if ( BYTE9(cinfo->output_gamma) != 0 && (unsigned __int8)smoothing_ok(cinfo) != 0 )
    {
      *(_DWORD *)(Al + 12) = decompress_smooth_data;
      cinfo->output_scanline = 0;
    }
    else
    {
      *(_DWORD *)(Al + 12) = decompress_data;
      cinfo->output_scanline = 0;
    }
  }
  else
  {
    cinfo->output_scanline = 0;
  }
}


// ========================================================================
// ?jinit_d_coef_controller@@YAXPAUjpeg_decompress_struct@@E@Z
// EA  : 0x83235738
// RVA : 0x01235738
// PDB : w:\tech5\libs\jpeg\jdcoefct.cpp
// ========================================================================

void __fastcall jinit_d_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_progress_mgr *v4; // r3
  int v5; // r27
  jpeg_progress_mgr *v6; // r29
  int *v7; // r30
  int *p_pass_limit; // r26
  int v9; // r4
  int v10; // r28
  int v11; // r25
  int v12; // r24
  jpeg_memory_mgr *mem; // r23
  int v14; // r22
  int v15; // r3
  char *v16; // r3

  v4 = (jpeg_progress_mgr *)((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[16].progress = v4;
  v5 = 0;
  v4[5].completed_passes = 0;
  v4->progress_monitor = (void (__fastcall *)(jpeg_common_struct *))start_input_pass_0;
  v6 = v4;
  v4->pass_limit = (int)start_output_pass;
  if ( need_full_buffer != 0 )
  {
    if ( (int)cinfo[1].client_data > 0 )
    {
      v7 = (int *)&cinfo[8].mem[-1];
      p_pass_limit = &v4[3].pass_limit;
      do
      {
        v9 = v7[16];
        v10 = v9;
        if ( HIBYTE(cinfo[8].progress) != 0 )
          v10 = 3 * v9;
        v11 = v7[20];
        v12 = v7[15];
        v7 += 21;
        mem = cinfo->mem;
        v14 = jround_up(a: *v7, b: v9);
        v15 = jround_up(a: v11, b: v12);
        ++v5;
        *++p_pass_limit = (int)mem->request_virt_barray(a1: cinfo, a2: 1, a3: 1u, a4: v15, a5: v14, a6: v10);
      }
      while ( v5 < (int)cinfo[1].client_data );
    }
    v6->pass_counter = (int)consume_data;
    v6->completed_passes = (int)decompress_data;
    v6->total_passes = (int)&v6[3].completed_passes;
  }
  else
  {
    v16 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    v6[1].completed_passes = (int)v16;
    v6[1].total_passes = (int)(v16 + 128);
    v6[2].progress_monitor = (void (__fastcall *)(jpeg_common_struct *))(v16 + 256);
    v6[2].pass_counter = (int)(v16 + 384);
    v6[2].pass_limit = (int)(v16 + 512);
    v6[2].completed_passes = (int)(v16 + 640);
    v6[2].total_passes = (int)(v16 + 768);
    v6[3].progress_monitor = (void (__fastcall *)(jpeg_common_struct *))(v16 + 896);
    v6[3].pass_counter = (int)(v16 + 1024);
    v6[3].pass_limit = (int)(v16 + 1152);
    v6->pass_counter = (int)idLobbyBackend360::StartArbitration;
    v6->completed_passes = (int)decompress_onepass;
    v6->total_passes = 0;
  }
}

