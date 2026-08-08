
// ========================================================================
// output_pass_setup
// EA  : 0x832114E0
// RVA : 0x012114E0
// PDB : w:\tech5\libs\jpeg\jdapistd.cpp
// ========================================================================

int __fastcall output_pass_setup(jpeg_common_struct *cinfo)
{
  int *v2; // r30
  jpeg_error_mgr *v3; // r11
  jpeg_progress_mgr *progress; // r10
  int v5; // r28

  if ( cinfo->global_state != 204 )
  {
    ((void (*)(void))cinfo[16].err->error_exit)();
    cinfo[5].err = nullptr;
    cinfo->global_state = 204;
  }
  if ( HIBYTE(cinfo[16].err->output_message) != 0 )
  {
    v2 = (int *)&cinfo[5];
    while ( 1 )
    {
      v3 = (jpeg_error_mgr *)*v2;
      if ( (jpeg_error_mgr *)*v2 < cinfo[4].err )
        break;
LABEL_10:
      ((void (__fastcall *)(jpeg_common_struct *))cinfo[16].err->emit_message)(a1: cinfo);
      cinfo[16].err->error_exit(a1: cinfo);
      *v2 = 0;
      if ( HIBYTE(cinfo[16].err->output_message) == 0 )
        goto LABEL_11;
    }
    while ( 1 )
    {
      progress = cinfo->progress;
      if ( progress != nullptr )
      {
        progress->pass_counter = (int)v3;
        cinfo->progress->pass_limit = (int)cinfo[4].err;
        cinfo->progress->progress_monitor(a1: cinfo);
      }
      v5 = *v2;
      ((void (__fastcall *)(jpeg_common_struct *, _DWORD, jpeg_common_struct *, _DWORD))cinfo[16].mem->alloc_large)(
        a1: cinfo,
        a2: 0,
        a3: &cinfo[5],
        a4: 0);
      v3 = (jpeg_error_mgr *)*v2;
      if ( *v2 == v5 )
        return 0;
      if ( v3 >= cinfo[4].err )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_11:
    cinfo->global_state = ((_cntlzw(*(&cinfo[2].is_decompressor + 1)) & 0x20) == 0) + 205;
    return 1;
  }
}


// ========================================================================
// ?jpeg_read_scanlines@@YAIPAUjpeg_decompress_struct@@PAPAEI@Z
// EA  : 0x83211620
// RVA : 0x01211620
// PDB : w:\tech5\libs\jpeg\jdapistd.cpp
// ========================================================================

unsigned int __fastcall jpeg_read_scanlines(
        jpeg_common_struct *cinfo,
        unsigned __int8 **scanlines,
        unsigned int max_lines)
{
  unsigned int err; // r10
  unsigned int result; // r3
  jpeg_progress_mgr *progress; // r11
  int mem; // r10
  unsigned int v10; // [sp+50h] [-30h] BYREF

  if ( cinfo->global_state != 205 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = (unsigned int)cinfo[5].err;
  if ( (jpeg_error_mgr *)err < cinfo[4].err )
  {
    progress = cinfo->progress;
    if ( progress != nullptr )
    {
      progress->pass_counter = err;
      cinfo->progress->pass_limit = (int)cinfo[4].err;
      cinfo->progress->progress_monitor(a1: cinfo);
    }
    mem = (int)cinfo[16].mem;
    v10 = 0;
    (*(void (__fastcall **)(jpeg_common_struct *, unsigned __int8 **, unsigned int *, unsigned int))(mem + 4))(
      a1: cinfo,
      a2: scanlines,
      a3: &v10,
      a4: max_lines);
    result = v10;
    cinfo[5].err = (jpeg_error_mgr *)((char *)cinfo[5].err + v10);
  }
  else
  {
    cinfo->err->msg_code = 123;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
    return 0;
  }
  return result;
}


// ========================================================================
// ?jpeg_start_decompress@@YAEPAUjpeg_decompress_struct@@@Z
// EA  : 0x83211720
// RVA : 0x01211720
// PDB : w:\tech5\libs\jpeg\jdapistd.cpp
// ========================================================================

int __fastcall jpeg_start_decompress(jpeg_decompress_struct *cinfo)
{
  int global_state; // r11
  jpeg_progress_mgr *progress; // r11
  int v5; // r3
  jpeg_progress_mgr *v6; // r11
  int v7; // r10
  jpeg_progress_mgr *v8; // r11
  int pass_limit; // r9

  if ( cinfo->global_state == 202 )
  {
    jinit_master_decompress(cinfo);
    if ( HIBYTE(cinfo->output_gamma) != 0 )
    {
      cinfo->global_state = 207;
      return 1;
    }
    cinfo->global_state = 203;
  }
  global_state = cinfo->global_state;
  if ( global_state != 203 )
  {
    if ( global_state != 204 )
    {
      cinfo->err->msg_code = 20;
      cinfo->err->msg_parm.i[0] = cinfo->global_state;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
    }
    return output_pass_setup((jpeg_common_struct *)cinfo);
  }
  if ( HIBYTE(cinfo->master[1].finish_output_pass) == 0 )
  {
LABEL_17:
    cinfo->colormap = (unsigned __int8 **)cinfo->rec_outbuf_height;
    return output_pass_setup((jpeg_common_struct *)cinfo);
  }
  while ( 1 )
  {
    progress = cinfo->progress;
    if ( progress != nullptr )
      progress->progress_monitor(a1: (jpeg_common_struct *)cinfo);
    v5 = ((int (__fastcall *)(jpeg_decompress_struct *))cinfo->master->prepare_for_output_pass)(a1: cinfo);
    if ( v5 == 0 )
      return 0;
    if ( v5 == 2 )
      goto LABEL_17;
    v6 = cinfo->progress;
    if ( v6 != nullptr && (v5 == 3 || v5 == 1) )
    {
      v7 = v6->pass_counter + 1;
      v6->pass_counter = v7;
      v8 = cinfo->progress;
      pass_limit = v8->pass_limit;
      if ( v7 >= pass_limit )
        v8->pass_limit = (int)cinfo->marker_list + pass_limit;
    }
  }
}

