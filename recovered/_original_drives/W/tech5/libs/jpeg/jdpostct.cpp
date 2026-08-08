
// ========================================================================
// post_process_1pass
// EA  : 0x83237978
// RVA : 0x01237978
// PDB : w:\tech5\libs\jpeg\jdpostct.cpp
// ========================================================================

void __fastcall post_process_1pass(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  int unread_marker; // r29

  unread_marker = cinfo->unread_marker;
  cinfo->inputctl->reset_input_controller(a1: cinfo);
  ((void (__fastcall *)(jpeg_decompress_struct *, _DWORD, unsigned __int8 **, _DWORD))cinfo->entropy->decode_mcu)(
    a1: cinfo,
    a2: *(_DWORD *)(unread_marker + 12),
    a3: &output_buf[*out_row_ctr],
    a4: 0);
  *out_row_ctr = *out_row_ctr;
}


// ========================================================================
// post_process_prepass
// EA  : 0x83237A10
// RVA : 0x01237A10
// PDB : w:\tech5\libs\jpeg\jdpostct.cpp
// ========================================================================

void __fastcall post_process_prepass(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  _DWORD *unread_marker; // r31
  unsigned int *v13; // r28
  unsigned int v14; // r29
  unsigned int v15; // r11
  unsigned int v16; // r27
  unsigned int v17; // r11
  unsigned int v18; // r8

  unread_marker = (_DWORD *)cinfo->unread_marker;
  v13 = unread_marker + 6;
  if ( unread_marker[6] == 0 )
    unread_marker[3] = ((int (*)(void))cinfo->mem->access_virt_sarray)();
  v14 = *v13;
  ((void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, _DWORD, _DWORD *, _DWORD))cinfo->inputctl->reset_input_controller)(
    a1: cinfo,
    a2: input_buf,
    a3: in_row_group_ctr,
    a4: in_row_groups_avail,
    a5: unread_marker[3],
    a6: unread_marker + 6,
    a7: unread_marker[4]);
  v15 = *v13;
  if ( *v13 > v14 )
  {
    v16 = v15 - v14;
    ((void (__fastcall *)(jpeg_decompress_struct *, unsigned int, _DWORD, unsigned int))cinfo->entropy->decode_mcu)(
      a1: cinfo,
      a2: 4 * v14 + unread_marker[3],
      a3: 0,
      a4: v15 - v14);
    *out_row_ctr += v16;
  }
  v17 = unread_marker[4];
  if ( *v13 >= v17 )
  {
    v18 = unread_marker[5] + v17;
    *v13 = 0;
    unread_marker[5] = v18;
  }
}


// ========================================================================
// post_process_2pass
// EA  : 0x83237B08
// RVA : 0x01237B08
// PDB : w:\tech5\libs\jpeg\jdpostct.cpp
// ========================================================================

void __fastcall post_process_2pass(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  _DWORD *unread_marker; // r31
  int v12; // r11
  unsigned int v13; // r9
  unsigned int v14; // r30
  int v15; // r8
  unsigned int v16; // r10
  unsigned int v17; // r11
  unsigned int v18; // r8

  unread_marker = (_DWORD *)cinfo->unread_marker;
  if ( unread_marker[6] == 0 )
    unread_marker[3] = ((int (*)(void))cinfo->mem->access_virt_sarray)();
  v12 = unread_marker[6];
  v13 = out_rows_avail - *out_row_ctr;
  v14 = unread_marker[4] - v12;
  if ( v14 > v13 )
    v14 = v13;
  v15 = unread_marker[5];
  if ( v14 > *(_DWORD *)&cinfo->two_pass_quantize - v15 )
    v14 = *(_DWORD *)&cinfo->two_pass_quantize - v15;
  ((void (__fastcall *)(jpeg_decompress_struct *, int, unsigned __int8 **, unsigned int))cinfo->entropy->decode_mcu)(
    a1: cinfo,
    a2: 4 * v12 + unread_marker[3],
    a3: &output_buf[*out_row_ctr],
    a4: v14);
  *out_row_ctr += v14;
  v16 = unread_marker[4];
  v17 = unread_marker[6] + v14;
  unread_marker[6] = v17;
  if ( v17 >= v16 )
  {
    v18 = unread_marker[5] + v16;
    unread_marker[6] = 0;
    unread_marker[5] = v18;
  }
}


// ========================================================================
// start_pass_dpost
// EA  : 0x83237C00
// RVA : 0x01237C00
// PDB : w:\tech5\libs\jpeg\jdpostct.cpp
// ========================================================================

void __fastcall start_pass_dpost(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  _DWORD *client_data; // r31
  void (__fastcall *pass_counter)(jpeg_decompress_struct *); // r10
  int v4; // r10

  client_data = cinfo[16].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( client_data[2] == 0 )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      pass_counter = (void (__fastcall *)(jpeg_decompress_struct *))post_process_2pass;
    }
    else
    {
      if ( pass_mode != JBUF_SAVE_AND_PASS )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
        goto LABEL_16;
      }
      if ( client_data[2] == 0 )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      pass_counter = (void (__fastcall *)(jpeg_decompress_struct *))post_process_prepass;
    }
LABEL_15:
    client_data[1] = pass_counter;
    goto LABEL_16;
  }
  if ( BYTE2(cinfo[3].err) == 0 )
  {
    pass_counter = (void (__fastcall *)(jpeg_decompress_struct *))cinfo[17].progress->pass_counter;
    goto LABEL_15;
  }
  v4 = client_data[3];
  client_data[1] = post_process_1pass;
  if ( v4 == 0 )
    client_data[3] = ((int (*)(void))cinfo->mem->access_virt_sarray)();
LABEL_16:
  client_data[6] = 0;
  client_data[5] = 0;
}


// ========================================================================
// ?jinit_d_post_controller@@YAXPAUjpeg_decompress_struct@@E@Z
// EA  : 0x83237D30
// RVA : 0x01237D30
// PDB : w:\tech5\libs\jpeg\jdpostct.cpp
// ========================================================================

void __fastcall jinit_d_post_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  void (__fastcall **v4)(jpeg_common_struct *, J_BUF_MODE); // r3
  void (__fastcall **v5)(jpeg_common_struct *, J_BUF_MODE); // r30
  unsigned int client_data; // r29
  jpeg_memory_mgr *mem; // r28
  int v8; // r3

  v4 = (void (__fastcall **)(jpeg_common_struct *, J_BUF_MODE))((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[16].client_data = v4;
  v4[2] = nullptr;
  v5 = v4;
  *v4 = start_pass_dpost;
  v4[3] = nullptr;
  if ( BYTE2(cinfo[3].err) != 0 )
  {
    client_data = (unsigned int)cinfo[11].client_data;
    v4[4] = (void (__fastcall *)(jpeg_common_struct *, J_BUF_MODE))client_data;
    if ( need_full_buffer != 0 )
    {
      mem = cinfo->mem;
      v8 = jround_up(a: (int)cinfo[4].err, b: client_data);
      v5[2] = (void (__fastcall *)(jpeg_common_struct *, J_BUF_MODE))mem->request_virt_sarray(
                                                                       a1: cinfo,
                                                                       a2: 1,
                                                                       a3: 0,
                                                                       a4: (int)cinfo[4].mem * cinfo[3].global_state,
                                                                       a5: v8,
                                                                       a6: client_data);
    }
    else
    {
      v4[3] = (void (__fastcall *)(jpeg_common_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                       a1: cinfo,
                                                                       a2: 1,
                                                                       a3: (int)cinfo[4].mem * cinfo[3].global_state,
                                                                       a4: client_data);
    }
  }
}

