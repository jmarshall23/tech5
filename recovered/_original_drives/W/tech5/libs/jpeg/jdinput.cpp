
// ========================================================================
// initial_setup
// EA  : 0x83225658
// RVA : 0x01225658
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

void __fastcall initial_setup(jpeg_common_struct *cinfo)
{
  int client_data; // r10
  JHUFF_TBL *mem; // r11
  int v4; // r29
  int *v5; // r30
  int v6; // r11
  jpeg_progress_mgr *progress; // r11
  int v8; // r11
  int v9; // r10
  JHUFF_TBL *v10; // r11
  int v11; // r29
  unsigned __int8 *v12; // r30
  jpeg_marker_struct *v13; // r3
  int v14; // r10
  int v15; // r9

  if ( (int)cinfo[1].progress > 65500 || (int)cinfo[1].mem > 65500 )
  {
    cinfo->err->msg_code = 41;
    cinfo->err->msg_parm.i[0] = 65500;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[8].err != (jpeg_error_mgr *)8 )
  {
    cinfo->err->msg_code = 15;
    cinfo->err->msg_parm.i[0] = (int)cinfo[8].err;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[1].client_data > 10 )
  {
    cinfo->err->msg_code = 26;
    cinfo->err->msg_parm.i[0] = (int)cinfo[1].client_data;
    cinfo->err->msg_parm.i[1] = 10;
    cinfo->err->error_exit(a1: cinfo);
  }
  client_data = (int)cinfo[1].client_data;
  mem = (JHUFF_TBL *)cinfo[8].mem;
  cinfo[11].progress = (jpeg_progress_mgr *)1;
  v4 = 0;
  cinfo[11].client_data = (void *)1;
  if ( client_data > 0 )
  {
    v5 = (int *)&mem->bits[12];
    do
    {
      v6 = *(v5 - 1);
      if ( v6 <= 0 || v6 > 4 || *v5 <= 0 || *v5 > 4 )
      {
        cinfo->err->msg_code = 18;
        cinfo->err->error_exit(a1: cinfo);
      }
      progress = cinfo[11].progress;
      if ( (int)progress <= *(v5 - 1) )
        progress = (jpeg_progress_mgr *)*(v5 - 1);
      cinfo[11].progress = progress;
      v8 = (int)cinfo[11].client_data;
      if ( v8 <= *v5 )
        v8 = *v5;
      ++v4;
      cinfo[11].client_data = (void *)v8;
      v5 += 21;
    }
    while ( v4 < (int)cinfo[1].client_data );
  }
  v9 = (int)cinfo[1].client_data;
  v10 = (JHUFF_TBL *)cinfo[8].mem;
  v11 = 0;
  *(_DWORD *)&cinfo[11].is_decompressor = 8;
  if ( v9 > 0 )
  {
    v12 = &v10[-1].huffval[249];
    do
    {
      *((_DWORD *)v12 + 11) = 8;
      *((_DWORD *)v12 + 9) = jdiv_round_up(a: *((_DWORD *)v12 + 4) * (int)cinfo[1].mem, b: 8 * (int)cinfo[11].progress);
      *((_DWORD *)v12 + 10) = jdiv_round_up(
                                a: *((_DWORD *)v12 + 5) * (int)cinfo[1].progress,
                                b: 8 * (int)cinfo[11].client_data);
      *((_DWORD *)v12 + 12) = jdiv_round_up(a: *((_DWORD *)v12 + 4) * (int)cinfo[1].mem, b: (int)cinfo[11].progress);
      *((_DWORD *)v12 + 13) = jdiv_round_up(
                                a: *((_DWORD *)v12 + 5) * (int)cinfo[1].progress,
                                b: (int)cinfo[11].client_data);
      v12[56] = 1;
      ++v11;
      v12 += 84;
      *(_DWORD *)v12 = 0;
    }
    while ( v11 < (int)cinfo[1].client_data );
  }
  v13 = (jpeg_marker_struct *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[11].client_data);
  v14 = (int)cinfo[12].mem;
  v15 = (int)cinfo[1].client_data;
  cinfo[11].global_state = (int)v13;
  *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 16) = v14 < v15 || HIBYTE(cinfo[8].progress) != 0;
}


// ========================================================================
// per_scan_setup
// EA  : 0x832258D8
// RVA : 0x012258D8
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

void __fastcall per_scan_setup(jpeg_common_struct *cinfo)
{
  int mem; // r11
  jpeg_progress_mgr *progress; // r11
  unsigned int completed_passes; // r6
  int total_passes; // r7
  unsigned int v6; // r9
  int v7; // r8
  jpeg_component_info *v8; // r3
  int v9; // r9
  int v10; // r29
  int *p_progress; // r28
  _DWORD *v12; // r11
  unsigned int v13; // r10
  unsigned int v14; // r8
  unsigned int v15; // r9
  int v16; // r6
  int v17; // r30
  int v18; // r8
  unsigned int v19; // r10
  int v20; // r10
  int i; // ctr

  mem = (int)cinfo[12].mem;
  if ( mem == 1 )
  {
    progress = cinfo[12].progress;
    cinfo[13].err = (jpeg_error_mgr *)progress[1].pass_limit;
    cinfo[13].mem = (jpeg_memory_mgr *)progress[1].completed_passes;
    completed_passes = progress[1].completed_passes;
    total_passes = progress[1].total_passes;
    v6 = progress->completed_passes;
    __twllei(v6, 0);
    progress[2].completed_passes = 1;
    progress[2].total_passes = 1;
    progress[3].progress_monitor = (void (__fastcall *)(jpeg_common_struct *))1;
    progress[3].pass_counter = total_passes;
    progress[3].pass_limit = 1;
    v7 = completed_passes % v6;
    if ( completed_passes % v6 == 0 )
      v7 = v6;
    progress[3].completed_passes = v7;
    cinfo[13].progress = (jpeg_progress_mgr *)1;
    cinfo[13].client_data = nullptr;
  }
  else
  {
    if ( mem <= 0 || mem > 4 )
    {
      cinfo->err->msg_code = 26;
      cinfo->err->msg_parm.i[0] = (int)cinfo[12].mem;
      cinfo->err->msg_parm.i[1] = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    cinfo[13].err = (jpeg_error_mgr *)jdiv_round_up(a: (int)cinfo[1].mem, b: 8 * (int)cinfo[11].progress);
    v8 = (jpeg_component_info *)jdiv_round_up(a: (int)cinfo[1].progress, b: 8 * (int)cinfo[11].client_data);
    v9 = (int)cinfo[12].mem;
    v10 = 0;
    cinfo[13].mem = (jpeg_memory_mgr *)v8;
    cinfo[13].progress = nullptr;
    if ( v9 > 0 )
    {
      p_progress = (int *)&cinfo[12].progress;
      do
      {
        v12 = (_DWORD *)*p_progress;
        v13 = *(_DWORD *)(*p_progress + 8);
        v14 = *(_DWORD *)(*p_progress + 28);
        v15 = *(_DWORD *)(*p_progress + 12);
        __twllei(v13, 0);
        v16 = v12[9];
        v17 = v15 * v13;
        v12[13] = v13;
        v12[15] = v15 * v13;
        v12[14] = v15;
        v12[16] = v16 * v13;
        v18 = v14 % v13;
        if ( v18 == 0 )
          v18 = v13;
        v19 = v12[8];
        __twllei(v15, 0);
        v12[17] = v18;
        v20 = v19 % v15;
        if ( v20 == 0 )
          v20 = v15;
        v12[18] = v20;
        if ( (int)cinfo[13].progress + v17 > 10 )
        {
          cinfo->err->msg_code = 13;
          cinfo->err->error_exit(a1: cinfo);
        }
        if ( v17 > 0 )
        {
          for ( i = v17; i != 0; --i )
          {
            *((_DWORD *)&cinfo->err + (int)&cinfo[13].progress[4].progress_monitor + 1) = v10;
            ++cinfo[13].progress;
          }
        }
        ++v10;
        ++p_progress;
      }
      while ( v10 < (int)cinfo[12].mem );
    }
  }
}


// ========================================================================
// latch_quant_tables
// EA  : 0x83225AC8
// RVA : 0x01225AC8
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

void __fastcall latch_quant_tables(jpeg_common_struct *cinfo)
{
  int v2; // r27
  int *p_progress; // r28
  int v4; // r29
  unsigned int v5; // r30
  void *v6; // r3
  int v7; // r8
  void *v8; // r30

  v2 = 0;
  if ( (int)cinfo[12].mem > 0 )
  {
    p_progress = (int *)&cinfo[12].progress;
    do
    {
      v4 = *p_progress;
      if ( *(_DWORD *)(*p_progress + 76) == 0 )
      {
        v5 = *(_DWORD *)(v4 + 16);
        if ( v5 >= 4 || *((_DWORD *)&cinfo[6].err + v5) == 0 )
        {
          cinfo->err->msg_code = 52;
          cinfo->err->msg_parm.i[0] = v5;
          cinfo->err->error_exit(a1: cinfo);
        }
        v6 = (void *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 130);
        v7 = 4 * (v5 + 36);
        v8 = v6;
        memcpy(Dst: v6, Src: *(const void **)((char *)&cinfo->err + v7), Size: 0x82u);
        *(_DWORD *)(v4 + 76) = v8;
      }
      ++v2;
      ++p_progress;
    }
    while ( v2 < (int)cinfo[12].mem );
  }
}


// ========================================================================
// start_input_pass
// EA  : 0x83225BA0
// RVA : 0x01225BA0
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

void __fastcall start_input_pass(jpeg_common_struct *cinfo)
{
  per_scan_setup(cinfo);
  latch_quant_tables(cinfo);
  cinfo[17].err->error_exit(a1: cinfo);
  cinfo[16].progress->progress_monitor(a1: cinfo);
  **(_DWORD **)&cinfo[16].is_decompressor = cinfo[16].progress->pass_counter;
}


// ========================================================================
// consume_markers
// EA  : 0x83225C10
// RVA : 0x01225C10
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

int __fastcall consume_markers(jpeg_common_struct *cinfo)
{
  jpeg_decomp_master *v1; // r30
  int result; // r3
  int v4; // r29
  int is_dummy_pass; // r11
  unsigned __int8 **mem; // r11

  v1 = *(jpeg_decomp_master **)&cinfo[16].is_decompressor;
  if ( BYTE1(v1[1].finish_output_pass) != 0 )
    return 2;
  result = (*(int (__fastcall **)(jpeg_common_struct *))(cinfo[16].global_state + 4))(a1: cinfo);
  v4 = result;
  if ( result == 1 )
  {
    if ( v1[1].is_dummy_pass != 0 )
    {
      initial_setup(cinfo);
      v1[1].is_dummy_pass = 0;
      return 1;
    }
    if ( HIBYTE(v1[1].finish_output_pass) == 0 )
    {
      cinfo->err->msg_code = 35;
      cinfo->err->error_exit(a1: cinfo);
    }
    start_input_pass(cinfo);
  }
  else if ( result == 2 )
  {
    is_dummy_pass = v1[1].is_dummy_pass;
    BYTE1(v1[1].finish_output_pass) = 1;
    if ( is_dummy_pass != 0 )
    {
      if ( *(_BYTE *)(cinfo[16].global_state + 13) != 0 )
      {
        cinfo->err->msg_code = 59;
        cinfo->err->error_exit(a1: cinfo);
        return v4;
      }
    }
    else
    {
      mem = (unsigned __int8 **)cinfo[5].mem;
      if ( (int)cinfo[5].client_data > (int)mem )
      {
        cinfo[5].client_data = mem;
        return result;
      }
    }
  }
  return v4;
}


// ========================================================================
// reset_input_controller
// EA  : 0x83225D40
// RVA : 0x01225D40
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

void __fastcall reset_input_controller(jpeg_common_struct *cinfo)
{
  jpeg_decomp_master *v1; // r11

  v1 = *(jpeg_decomp_master **)&cinfo[16].is_decompressor;
  v1->prepare_for_output_pass = (void (__fastcall *)(jpeg_decompress_struct *))consume_markers;
  HIBYTE(v1[1].finish_output_pass) = 0;
  BYTE1(v1[1].finish_output_pass) = 0;
  v1[1].is_dummy_pass = 1;
  cinfo->err->reset_error_mgr(a1: cinfo);
  (*(void (__fastcall **)(jpeg_common_struct *))cinfo[16].global_state)(a1: cinfo);
  cinfo[5].global_state = 0;
}


// ========================================================================
// finish_input_pass
// EA  : 0x83225DC0
// RVA : 0x01225DC0
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

void __fastcall finish_input_pass(jpeg_decompress_struct *cinfo)
{
  cinfo->master->prepare_for_output_pass = (void (__fastcall *)(jpeg_decompress_struct *))consume_markers;
}


// ========================================================================
// ?jinit_input_controller@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x83225DD8
// RVA : 0x01225DD8
// PDB : w:\tech5\libs\jpeg\jdinput.cpp
// ========================================================================

void __fastcall jinit_input_controller(jpeg_decompress_struct *cinfo)
{
  int v2; // r3

  v2 = ((int (*)(void))cinfo->mem->alloc_small)();
  cinfo->master = (jpeg_decomp_master *)v2;
  *(_DWORD *)v2 = consume_markers;
  *(_DWORD *)(v2 + 4) = reset_input_controller;
  *(_BYTE *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 8) = start_input_pass;
  *(_DWORD *)(v2 + 12) = finish_input_pass;
  *(_BYTE *)(v2 + 17) = 0;
  *(_BYTE *)(v2 + 20) = 1;
}

