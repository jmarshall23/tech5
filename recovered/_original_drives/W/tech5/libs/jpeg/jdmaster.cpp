
// ========================================================================
// use_merged_upsample
// EA  : 0x832271E0
// RVA : 0x012271E0
// PDB : w:\tech5\libs\jpeg\jdmaster.cpp
// ========================================================================

int __fastcall use_merged_upsample(jpeg_decompress_struct *cinfo)
{
  JHUFF_TBL *v1; // r11
  int v2; // r10
  int result; // r3

  if ( BYTE8(cinfo->output_gamma) != 0 )
    return 0;
  if ( cinfo->arith_ac_K[16] != 0 )
    return 0;
  if ( cinfo->jpeg_color_space != JCS_YCbCr )
    return 0;
  if ( cinfo->num_components != 3 )
    return 0;
  if ( cinfo->out_color_space != JCS_RGB )
    return 0;
  if ( cinfo->desired_number_of_colors != 4 )
    return 0;
  v1 = cinfo->ac_huff_tbl_ptrs[1];
  if ( *(_DWORD *)&v1->bits[8] != 2 )
    return 0;
  if ( *(_DWORD *)&v1->huffval[75] != 1 )
    return 0;
  if ( *(_DWORD *)&v1->huffval[159] != 1 )
    return 0;
  if ( *(int *)&v1->bits[12] > 2 )
    return 0;
  if ( *(_DWORD *)&v1->huffval[79] != 1 )
    return 0;
  if ( *(_DWORD *)&v1->huffval[163] != 1 )
    return 0;
  v2 = *(_DWORD *)&cinfo->saw_Adobe_marker;
  if ( *(_DWORD *)&v1->huffval[19] != v2 )
    return 0;
  if ( *(_DWORD *)&v1->huffval[103] != v2 )
    return 0;
  result = 1;
  if ( *(_DWORD *)&v1->huffval[187] != v2 )
    return 0;
  return result;
}


// ========================================================================
// ?jpeg_calc_output_dimensions@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x832272A8
// RVA : 0x012272A8
// PDB : w:\tech5\libs\jpeg\jdmaster.cpp
// ========================================================================

void __fastcall jpeg_calc_output_dimensions(jpeg_common_struct *cinfo)
{
  unsigned int err; // r11
  unsigned int mem; // r10
  J_DITHER_MODE v4; // r11
  unsigned int progress; // r9
  int v6; // r6
  int *p_alloc_large; // r9
  int v8; // r10
  int i; // r11
  int v10; // r29
  unsigned __int8 *p_free_pool; // r30
  int client_data; // r11
  int v13; // r11

  if ( cinfo->global_state != 202 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (unsigned int)cinfo[2].err;
  mem = (unsigned int)cinfo[2].mem;
  if ( 8 * err > mem )
  {
    if ( 4 * err > mem )
    {
      if ( 2 * err > mem )
      {
        v4 = (J_DITHER_MODE)cinfo[1].mem;
        progress = (unsigned int)cinfo[1].progress;
        *(_DWORD *)&cinfo[11].is_decompressor = 8;
        cinfo[3].global_state = v4;
        cinfo[4].err = (jpeg_error_mgr *)progress;
      }
      else
      {
        cinfo[3].global_state = jdiv_round_up(a: (int)cinfo[1].mem, b: 2);
        cinfo[4].err = (jpeg_error_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 2);
        *(_DWORD *)&cinfo[11].is_decompressor = 4;
      }
    }
    else
    {
      cinfo[3].global_state = jdiv_round_up(a: (int)cinfo[1].mem, b: 4);
      cinfo[4].err = (jpeg_error_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 4);
      *(_DWORD *)&cinfo[11].is_decompressor = 2;
    }
  }
  else
  {
    cinfo[3].global_state = jdiv_round_up(a: (int)cinfo[1].mem, b: 8);
    cinfo[4].err = (jpeg_error_mgr *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8);
    *(_DWORD *)&cinfo[11].is_decompressor = 1;
  }
  v6 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_alloc_large = (int *)&cinfo[8].mem[-1].alloc_large;
    do
    {
      v8 = *(_DWORD *)&cinfo[11].is_decompressor;
      for ( i = v8; i < 8; i *= 2 )
      {
        if ( 2 * p_alloc_large[14] * i > (int)cinfo[11].progress * v8 )
          break;
        if ( 2 * p_alloc_large[15] * i > (int)cinfo[11].client_data * v8 )
          break;
      }
      p_alloc_large += 21;
      *p_alloc_large = i;
      ++v6;
    }
    while ( v6 < (int)cinfo[1].client_data );
  }
  v10 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (unsigned __int8 *)&cinfo[8].mem->free_pool;
    do
    {
      *((_DWORD *)p_free_pool + 1) = jdiv_round_up(
                                       a: *((_DWORD *)p_free_pool - 7) * *(_DWORD *)p_free_pool * (int)cinfo[1].mem,
                                       b: 8 * (int)cinfo[11].progress);
      *((_DWORD *)p_free_pool + 2) = jdiv_round_up(
                                       a: *((_DWORD *)p_free_pool - 6) * *(_DWORD *)p_free_pool * (int)cinfo[1].progress,
                                       b: 8 * (int)cinfo[11].client_data);
      ++v10;
      p_free_pool += 84;
    }
    while ( v10 < (int)cinfo[1].client_data );
  }
  if ( (unsigned int)(cinfo[1].global_state - 1) > 4 )
  {
    client_data = (int)cinfo[1].client_data;
    goto LABEL_28;
  }
  if ( cinfo[1].global_state == 2 )
  {
LABEL_26:
    cinfo[4].mem = (jpeg_memory_mgr *)4;
    goto LABEL_29;
  }
  if ( cinfo[1].global_state != 3 )
  {
    if ( cinfo[1].global_state == 1 )
    {
      cinfo[4].mem = (jpeg_memory_mgr *)1;
      goto LABEL_29;
    }
    goto LABEL_26;
  }
  client_data = 3;
LABEL_28:
  cinfo[4].mem = (jpeg_memory_mgr *)client_data;
LABEL_29:
  v13 = 1;
  if ( BYTE2(cinfo[3].err) == 0 )
    v13 = (int)cinfo[4].mem;
  cinfo[4].progress = (jpeg_progress_mgr *)v13;
  if ( (unsigned __int8)use_merged_upsample((jpeg_decompress_struct *)cinfo) != 0 )
    cinfo[4].client_data = cinfo[11].client_data;
  else
    cinfo[4].client_data = (void *)1;
}


// ========================================================================
// master_selection
// EA  : 0x83227538
// RVA : 0x01227538
// PDB : w:\tech5\libs\jpeg\jdmaster.cpp
// ========================================================================

void __fastcall master_selection(jpeg_common_struct *cinfo)
{
  int err; // r29
  char *v3; // r3
  char *v4; // r30
  int v5; // r11
  int i; // ctr
  char *v7; // r30
  char *v8; // r11
  int j; // ctr
  int v10; // r11
  unsigned __int8 v11; // r4
  jpeg_progress_mgr *progress; // r9
  int client_data; // r11

  err = (int)cinfo[16].err;
  jpeg_calc_output_dimensions(cinfo);
  v3 = (char *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1408);
  v4 = v3 + 256;
  cinfo[12].err = (jpeg_error_mgr *)(v3 + 256);
  memset(Dst: v3, Val: 0, Size: 0x100u);
  v5 = 0;
  for ( i = 256; i != 0; --i )
  {
    v4[v5] = v5;
    ++v5;
  }
  v7 = v4 + 128;
  v8 = v7 + 127;
  for ( j = 384; j != 0; --j )
    *++v8 = -1;
  memset(Dst: v7 + 512, Val: 0, Size: 0x180u);
  memcpy(Dst: v7 + 896, Src: cinfo[12].err, Size: 0x80u);
  *(_DWORD *)(err + 12) = 0;
  *(_BYTE *)(err + 16) = use_merged_upsample((jpeg_decompress_struct *)cinfo);
  *(_DWORD *)(err + 20) = 0;
  *(_DWORD *)(err + 24) = 0;
  v10 = BYTE2(cinfo[3].err);
  if ( BYTE2(cinfo[3].err) == 0 || cinfo[2].is_decompressor == 0 )
  {
    cinfo[3].is_decompressor = 0;
    *(&cinfo[3].is_decompressor + 1) = 0;
    *(&cinfo[3].is_decompressor + 2) = 0;
  }
  if ( v10 != 0 )
  {
    if ( *(&cinfo[2].is_decompressor + 1) != 0 )
    {
      cinfo->err->msg_code = 47;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
    {
      if ( cinfo[4].global_state != 0 )
      {
        *(&cinfo[3].is_decompressor + 1) = 1;
        goto LABEL_14;
      }
      if ( HIBYTE(cinfo[3].progress) != 0 )
      {
        *(&cinfo[3].is_decompressor + 2) = 1;
        goto LABEL_14;
      }
    }
    else
    {
      *(&cinfo[3].is_decompressor + 1) = 0;
      *(&cinfo[3].is_decompressor + 2) = 0;
      cinfo[4].global_state = 0;
    }
    cinfo[3].is_decompressor = 1;
LABEL_14:
    if ( cinfo[3].is_decompressor != 0 )
    {
      jinit_1pass_quantizer((jpeg_decompress_struct *)cinfo);
      *(_DWORD *)(err + 20) = *(_DWORD *)&cinfo[17].is_decompressor;
    }
    if ( *(&cinfo[3].is_decompressor + 2) != 0 || *(&cinfo[3].is_decompressor + 1) != 0 )
    {
      jinit_2pass_quantizer((jpeg_decompress_struct *)cinfo);
      *(_DWORD *)(err + 24) = *(_DWORD *)&cinfo[17].is_decompressor;
    }
  }
  if ( *(&cinfo[2].is_decompressor + 1) == 0 )
  {
    if ( *(_BYTE *)(err + 16) != 0 )
    {
      jinit_merged_upsampler((jpeg_decompress_struct *)cinfo);
    }
    else
    {
      jinit_color_deconverter((jpeg_decompress_struct *)cinfo);
      jinit_upsampler((jpeg_decompress_struct *)cinfo);
    }
    jinit_d_post_controller((jpeg_decompress_struct *)cinfo, need_full_buffer: *(&cinfo[3].is_decompressor + 2));
  }
  jinit_inverse_dct((jpeg_decompress_struct *)cinfo);
  if ( BYTE1(cinfo[8].progress) != 0 )
  {
    cinfo->err->msg_code = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  else if ( HIBYTE(cinfo[8].progress) != 0 )
  {
    jinit_phuff_decoder((jpeg_decompress_struct *)cinfo);
  }
  else
  {
    jinit_huff_decoder((jpeg_decompress_struct *)cinfo);
  }
  if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 16) != 0 || (v11 = 0, cinfo[2].is_decompressor != 0) )
    v11 = 1;
  jinit_d_coef_controller((jpeg_decompress_struct *)cinfo, need_full_buffer: v11);
  if ( *(&cinfo[2].is_decompressor + 1) == 0 )
    jinit_d_main_controller((jpeg_decompress_struct *)cinfo, need_full_buffer: 0);
  cinfo->mem->realize_virt_arrays(a1: cinfo);
  (*(void (__fastcall **)(jpeg_common_struct *))(*(_DWORD *)&cinfo[16].is_decompressor + 8))(a1: cinfo);
  progress = cinfo->progress;
  if ( progress != nullptr
    && cinfo[2].is_decompressor == 0
    && *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 16) != 0 )
  {
    client_data = (int)cinfo[1].client_data;
    if ( HIBYTE(cinfo[8].progress) != 0 )
      client_data = 3 * client_data + 2;
    progress->pass_counter = 0;
    cinfo->progress->pass_limit = cinfo[11].global_state * client_data;
    cinfo->progress->completed_passes = 0;
    cinfo->progress->total_passes = ((_cntlzw(*(&cinfo[3].is_decompressor + 2)) & 0x20) == 0) + 2;
    ++*(_DWORD *)(err + 12);
  }
}


// ========================================================================
// prepare_for_output_pass
// EA  : 0x83227868
// RVA : 0x01227868
// PDB : w:\tech5\libs\jpeg\jdmaster.cpp
// ========================================================================

void __fastcall prepare_for_output_pass(jpeg_common_struct *cinfo)
{
  int err; // r30
  jpeg_progress_mgr *progress; // r11

  err = (int)cinfo[16].err;
  if ( *(_BYTE *)(err + 8) != 0 )
  {
    *(_BYTE *)(err + 8) = 0;
    (**(void (***)(void))&cinfo[17].is_decompressor)();
    (*(void (__fastcall **)(jpeg_common_struct *, int))cinfo[16].client_data)(a1: cinfo, a2: 2);
    ((void (__fastcall *)(jpeg_common_struct *, int))cinfo[16].mem->alloc_small)(a1: cinfo, a2: 2);
  }
  else
  {
    if ( BYTE2(cinfo[3].err) != 0 && cinfo[4].global_state == 0 )
    {
      if ( HIBYTE(cinfo[3].progress) != 0 && *(&cinfo[3].is_decompressor + 2) != 0 )
      {
        *(_DWORD *)&cinfo[17].is_decompressor = *(_DWORD *)(err + 24);
        *(_BYTE *)(err + 8) = 1;
      }
      else if ( cinfo[3].is_decompressor != 0 )
      {
        *(_DWORD *)&cinfo[17].is_decompressor = *(_DWORD *)(err + 20);
      }
      else
      {
        cinfo->err->msg_code = 46;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    ((void (__fastcall *)(jpeg_common_struct *))cinfo[17].mem->alloc_small)(a1: cinfo);
    ((void (__fastcall *)(jpeg_common_struct *))cinfo[16].progress->pass_limit)(a1: cinfo);
    if ( *(&cinfo[2].is_decompressor + 1) == 0 )
    {
      if ( *(_BYTE *)(err + 16) == 0 )
        (*(void (__fastcall **)(jpeg_common_struct *))cinfo[17].client_data)(a1: cinfo);
      cinfo[17].progress->progress_monitor(a1: cinfo);
      if ( BYTE2(cinfo[3].err) != 0 )
        (**(void (__fastcall ***)(jpeg_common_struct *, _DWORD))&cinfo[17].is_decompressor)(
          a1: cinfo,
          a2: *(unsigned __int8 *)(err + 8));
      (*(void (__fastcall **)(jpeg_common_struct *, int))cinfo[16].client_data)(
        a1: cinfo,
        a2: *(_BYTE *)(err + 8) == 0 ? 0 : 3);
      ((void (__fastcall *)(jpeg_common_struct *, _DWORD))cinfo[16].mem->alloc_small)(a1: cinfo, a2: 0);
    }
  }
  progress = cinfo->progress;
  if ( progress != nullptr )
  {
    progress->completed_passes = *(_DWORD *)(err + 12);
    cinfo->progress->total_passes = ((_cntlzw(*(unsigned __int8 *)(err + 8)) & 0x20) == 0) + 1 + *(_DWORD *)(err + 12);
    if ( cinfo[2].is_decompressor != 0 && *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 17) == 0 )
      cinfo->progress->total_passes += ((_cntlzw(*(&cinfo[3].is_decompressor + 2)) & 0x20) == 0) + 1;
  }
}


// ========================================================================
// finish_output_pass
// EA  : 0x83227AB0
// RVA : 0x01227AB0
// PDB : w:\tech5\libs\jpeg\jdmaster.cpp
// ========================================================================

void __fastcall finish_output_pass(jpeg_decompress_struct *cinfo)
{
  int Se; // r31

  Se = cinfo->Se;
  if ( BYTE10(cinfo->output_gamma) != 0 )
    (*(void (**)(void))&cinfo->entropy->insufficient_data)();
  ++*(_DWORD *)(Se + 12);
}


// ========================================================================
// ?jinit_master_decompress@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x83227B00
// RVA : 0x01227B00
// PDB : w:\tech5\libs\jpeg\jdmaster.cpp
// ========================================================================

void __fastcall jinit_master_decompress(jpeg_common_struct *cinfo)
{
  int v2; // r3

  v2 = ((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[16].err = (jpeg_error_mgr *)v2;
  *(_DWORD *)v2 = prepare_for_output_pass;
  *(_DWORD *)(v2 + 4) = finish_output_pass;
  *(_BYTE *)(v2 + 8) = 0;
  master_selection(cinfo);
}

