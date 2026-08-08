
// ========================================================================
// build_ycc_rgb_table_0
// EA  : 0x83238CF8
// RVA : 0x01238CF8
// PDB : w:\tech5\libs\jpeg\jdmerge.cpp
// ========================================================================

void __fastcall build_ycc_rgb_table_0(jpeg_common_struct *cinfo)
{
  jpeg_input_controller *progress; // r31
  int v3; // ctr
  int v4; // r11
  int v5; // r8
  int v6; // r9
  int v7; // r10
  int v8; // r7

  progress = (jpeg_input_controller *)cinfo[17].progress;
  *(_DWORD *)&progress->has_multiple_scans = ((int (*)(void))cinfo->mem->alloc_small)();
  progress[1].consume_input = (int (__fastcall *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                              a1: cinfo,
                                                                              a2: 1,
                                                                              a3: 1024);
  progress[1].reset_input_controller = (void (__fastcall *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                                        a1: cinfo,
                                                                                        a2: 1,
                                                                                        a3: 1024);
  progress[1].start_input_pass = (void (__fastcall *)(jpeg_decompress_struct *))cinfo->mem->alloc_small(
                                                                                  a1: cinfo,
                                                                                  a2: 1,
                                                                                  a3: 1024);
  v3 = 256;
  v4 = 0;
  v5 = 5990656;
  v6 = -14831872;
  v7 = -11728000;
  v8 = 2919680;
  do
  {
    *(_DWORD *)(v4 + *(_DWORD *)&progress->has_multiple_scans) = v7 >> 16;
    v7 += 91881;
    *(_DWORD *)((char *)progress[1].consume_input + v4) = v6 >> 16;
    v6 += 116130;
    *(_DWORD *)((char *)progress[1].reset_input_controller + v4) = v5;
    v5 -= 46802;
    *(_DWORD *)((char *)progress[1].start_input_pass + v4) = v8;
    v8 -= 22554;
    v4 += 4;
    --v3;
  }
  while ( v3 != 0 );
}


// ========================================================================
// start_pass_merged_upsample
// EA  : 0x83238E18
// RVA : 0x01238E18
// PDB : w:\tech5\libs\jpeg\jdmerge.cpp
// ========================================================================

void __fastcall start_pass_merged_upsample(jpeg_decompress_struct *cinfo)
{
  jpeg_input_controller *inputctl; // r11

  inputctl = cinfo->inputctl;
  inputctl[1].has_multiple_scans = 0;
  inputctl[2].reset_input_controller = *(void (__fastcall **)(jpeg_decompress_struct *))&cinfo->two_pass_quantize;
}


// ========================================================================
// merged_2v_upsample
// EA  : 0x83238E30
// RVA : 0x01238E30
// PDB : w:\tech5\libs\jpeg\jdmerge.cpp
// ========================================================================

void __fastcall merged_2v_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_input_controller *inputctl; // r31
  unsigned int reset_input_controller; // r30
  int has_multiple_scans; // r10

  inputctl = cinfo->inputctl;
  if ( inputctl[1].has_multiple_scans != 0 )
  {
    jcopy_sample_rows(
      input_array: (unsigned __int8 **)&inputctl[1].finish_input_pass,
      source_row: 0,
      output_array: &output_buf[*out_row_ctr],
      dest_row: 0,
      num_rows: 1,
      num_cols: (size_t)inputctl[2].consume_input);
    reset_input_controller = 1;
    inputctl[1].has_multiple_scans = 0;
  }
  else
  {
    reset_input_controller = 2;
    if ( (char *)inputctl[2].reset_input_controller < (char *)2 )
      reset_input_controller = (unsigned int)inputctl[2].reset_input_controller;
    if ( reset_input_controller > out_rows_avail - *out_row_ctr )
      reset_input_controller = out_rows_avail - *out_row_ctr;
    if ( reset_input_controller <= 1 )
      inputctl[1].has_multiple_scans = 1;
    ((void (*)(void))inputctl->finish_input_pass)();
  }
  *out_row_ctr += reset_input_controller;
  has_multiple_scans = inputctl[1].has_multiple_scans;
  inputctl[2].reset_input_controller = (void (__fastcall *)(jpeg_decompress_struct *))((char *)inputctl[2].reset_input_controller
                                                                                     - reset_input_controller);
  if ( has_multiple_scans == 0 )
    ++*in_row_group_ctr;
}


// ========================================================================
// merged_1v_upsample
// EA  : 0x83238F38
// RVA : 0x01238F38
// PDB : w:\tech5\libs\jpeg\jdmerge.cpp
// ========================================================================

void __fastcall merged_1v_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  ((void (*)(void))cinfo->inputctl->finish_input_pass)();
  ++*out_row_ctr;
  ++*in_row_group_ctr;
}


// ========================================================================
// h2v1_merged_upsample
// EA  : 0x83238FA8
// RVA : 0x01238FA8
// PDB : w:\tech5\libs\jpeg\jdmerge.cpp
// ========================================================================

void __fastcall h2v1_merged_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int in_row_group_ctr,
        unsigned __int8 **output_buf)
{
  jpeg_input_controller *inputctl; // r11
  unsigned __int8 *v5; // r9
  int v6; // r29
  int (__fastcall *consume_input)(jpeg_decompress_struct *); // r28
  void (__fastcall *reset_input_controller)(jpeg_decompress_struct *); // r27
  void (__fastcall *start_input_pass)(jpeg_decompress_struct *); // r26
  unsigned __int8 *v10; // r5
  int max_h_samp_factor; // r10
  unsigned __int8 *v12; // r7
  _BYTE *v13; // r11
  unsigned int v14; // ctr
  int v15; // r8
  int v16; // r6
  int v17; // r31
  int v18; // r8
  int v19; // r25
  int v20; // r4
  int v21; // r6
  int v22; // r31
  int v23; // r6
  int v24; // r8
  _BYTE *v25; // r11
  int v26; // r8
  int v27; // r7
  int v28; // r5
  int v29; // r9
  int v30; // r4
  int v31; // r6
  int v32; // r4

  inputctl = cinfo->inputctl;
  v5 = (*input_buf)[in_row_group_ctr];
  v6 = *(_DWORD *)&inputctl->has_multiple_scans;
  consume_input = inputctl[1].consume_input;
  reset_input_controller = inputctl[1].reset_input_controller;
  start_input_pass = inputctl[1].start_input_pass;
  max_h_samp_factor = cinfo->max_h_samp_factor;
  v12 = input_buf[2][in_row_group_ctr];
  v10 = input_buf[1][in_row_group_ctr];
  v13 = *output_buf;
  if ( (unsigned int)cinfo->dither_mode >> 1 != 0 )
  {
    v14 = (unsigned int)cinfo->dither_mode >> 1;
    do
    {
      v15 = *v12++;
      v16 = *v10++;
      v17 = __ROL4__(v15, 2);
      v18 = *v5;
      v19 = __ROL4__(v16, 2);
      v20 = *(_DWORD *)(v17 + v6);
      v21 = *(_DWORD *)((char *)reset_input_controller + v17);
      v22 = *(_DWORD *)((char *)consume_input + v19);
      v23 = (*(_DWORD *)((char *)start_input_pass + v19) + v21) >> 16;
      *v13 = *(_BYTE *)(v18 + v20 + max_h_samp_factor);
      v13[1] = *(_BYTE *)(v18 + v23 + max_h_samp_factor);
      v13[2] = *(_BYTE *)(v18 + v22 + max_h_samp_factor);
      v24 = v5[1];
      v25 = v13 + 4;
      *v25 = *(_BYTE *)(v24 + v20 + max_h_samp_factor);
      v5 += 2;
      v25[1] = *(_BYTE *)(v24 + v23 + max_h_samp_factor);
      v25[2] = *(_BYTE *)(v24 + v22 + max_h_samp_factor);
      v13 = v25 + 4;
      --v14;
    }
    while ( v14 != 0 );
  }
  if ( (cinfo->dither_mode & 1) != 0 )
  {
    v26 = *v12;
    v27 = *v10;
    v28 = __ROL4__(v26, 2);
    v29 = *v5;
    v30 = __ROL4__(v27, 2);
    v31 = v29 + *(_DWORD *)((char *)consume_input + v30);
    v32 = v29
        + ((*(_DWORD *)((char *)start_input_pass + v30) + *(_DWORD *)((char *)reset_input_controller + v28)) >> 16);
    *v13 = *(_BYTE *)(*(_DWORD *)(v28 + v6) + v29 + max_h_samp_factor);
    v13[1] = *(_BYTE *)(v32 + max_h_samp_factor);
    v13[2] = *(_BYTE *)(v31 + max_h_samp_factor);
  }
}


// ========================================================================
// h2v2_merged_upsample
// EA  : 0x832390F0
// RVA : 0x012390F0
// PDB : w:\tech5\libs\jpeg\jdmerge.cpp
// ========================================================================

void __fastcall h2v2_merged_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int in_row_group_ctr,
        unsigned __int8 **output_buf)
{
  unsigned __int8 **v4; // r10
  jpeg_input_controller *inputctl; // r31
  unsigned int v6; // r5
  int max_h_samp_factor; // r11
  unsigned __int8 *v8; // r8
  unsigned __int8 *v9; // r7
  unsigned __int8 *v10; // r29
  _BYTE *v11; // r10
  int v12; // r27
  int (__fastcall *consume_input)(jpeg_decompress_struct *); // r26
  void (__fastcall *reset_input_controller)(jpeg_decompress_struct *); // r25
  void (__fastcall *start_input_pass)(jpeg_decompress_struct *); // r24
  unsigned __int8 *v16; // r30
  unsigned __int8 *v17; // r9
  unsigned int v18; // ctr
  int v19; // r6
  int v20; // r5
  int v21; // r4
  int v22; // r31
  int v23; // r23
  int v24; // r5
  int v25; // r6
  int v26; // r4
  int v27; // r6
  int v28; // r31
  _BYTE *v29; // r10
  int v30; // r31
  int v31; // r31
  _BYTE *v32; // r9
  int v33; // r4
  int v34; // r8
  int v35; // r31
  int v36; // r5
  int v37; // r6
  int v38; // r4
  int v39; // r3
  int v40; // r10

  v4 = &(*input_buf)[2 * in_row_group_ctr];
  inputctl = cinfo->inputctl;
  v6 = in_row_group_ctr;
  max_h_samp_factor = cinfo->max_h_samp_factor;
  v8 = *v4;
  v9 = v4[1];
  v10 = input_buf[1][v6];
  v11 = *output_buf;
  v12 = *(_DWORD *)&inputctl->has_multiple_scans;
  consume_input = inputctl[1].consume_input;
  reset_input_controller = inputctl[1].reset_input_controller;
  start_input_pass = inputctl[1].start_input_pass;
  v16 = input_buf[2][v6];
  v17 = output_buf[1];
  if ( (unsigned int)cinfo->dither_mode >> 1 != 0 )
  {
    v18 = (unsigned int)cinfo->dither_mode >> 1;
    do
    {
      v19 = *v16++;
      v20 = *v10++;
      v21 = __ROL4__(v19, 2);
      v22 = *v8;
      v23 = __ROL4__(v20, 2);
      v24 = *(_DWORD *)(v21 + v12);
      v25 = *(_DWORD *)((char *)reset_input_controller + v21);
      v26 = *(_DWORD *)((char *)consume_input + v23);
      v27 = (*(_DWORD *)((char *)start_input_pass + v23) + v25) >> 16;
      *v11 = *(_BYTE *)(v22 + v24 + max_h_samp_factor);
      v11[1] = *(_BYTE *)(v22 + v27 + max_h_samp_factor);
      v11[2] = *(_BYTE *)(v22 + v26 + max_h_samp_factor);
      v28 = v8[1];
      v29 = v11 + 4;
      *v29 = *(_BYTE *)(v28 + v24 + max_h_samp_factor);
      v8 += 2;
      v29[1] = *(_BYTE *)(v28 + v27 + max_h_samp_factor);
      v29[2] = *(_BYTE *)(v28 + v26 + max_h_samp_factor);
      v11 = v29 + 4;
      v30 = *v9;
      *v17 = *(_BYTE *)(v30 + v24 + max_h_samp_factor);
      v17[1] = *(_BYTE *)(v30 + v27 + max_h_samp_factor);
      v17[2] = *(_BYTE *)(v30 + v26 + max_h_samp_factor);
      v31 = v9[1];
      v32 = v17 + 4;
      *v32 = *(_BYTE *)(v31 + v24 + max_h_samp_factor);
      v9 += 2;
      v32[1] = *(_BYTE *)(v31 + v27 + max_h_samp_factor);
      v32[2] = *(_BYTE *)(v31 + v26 + max_h_samp_factor);
      v17 = v32 + 4;
      --v18;
    }
    while ( v18 != 0 );
  }
  if ( (cinfo->dither_mode & 1) != 0 )
  {
    v33 = __ROL4__(*v16, 2);
    v34 = *v8;
    v35 = __ROL4__(*v10, 2);
    v36 = *(_DWORD *)(v33 + v12);
    v37 = *(_DWORD *)((char *)reset_input_controller + v33);
    v38 = *(_DWORD *)((char *)consume_input + v35);
    v39 = *(_DWORD *)((char *)start_input_pass + v35) + v37;
    *v11 = *(_BYTE *)(v34 + v36 + max_h_samp_factor);
    v11[1] = *(_BYTE *)(v34 + (v39 >> 16) + max_h_samp_factor);
    v11[2] = *(_BYTE *)(v34 + v38 + max_h_samp_factor);
    v40 = *v9;
    *v17 = *(_BYTE *)(v40 + v36 + max_h_samp_factor);
    v17[1] = *(_BYTE *)(v40 + (v39 >> 16) + max_h_samp_factor);
    v17[2] = *(_BYTE *)(v40 + v38 + max_h_samp_factor);
  }
}


// ========================================================================
// ?jinit_merged_upsampler@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x832392C8
// RVA : 0x012392C8
// PDB : w:\tech5\libs\jpeg\jdmerge.cpp
// ========================================================================

void __fastcall jinit_merged_upsampler(jpeg_common_struct *cinfo)
{
  int v2; // r3
  unsigned int v3; // r5

  v2 = ((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[17].progress = (jpeg_progress_mgr *)v2;
  *(_BYTE *)(v2 + 8) = 0;
  *(_DWORD *)v2 = start_pass_merged_upsample;
  v3 = (int)cinfo[4].mem * cinfo[3].global_state;
  *(_DWORD *)(v2 + 40) = v3;
  if ( cinfo[11].client_data == (void *)2 )
  {
    *(_DWORD *)(v2 + 4) = merged_2v_upsample;
    *(_DWORD *)(v2 + 12) = h2v2_merged_upsample;
    *(_DWORD *)(v2 + 32) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: v3);
  }
  else
  {
    *(_DWORD *)(v2 + 32) = 0;
    *(_DWORD *)(v2 + 4) = merged_1v_upsample;
    *(_DWORD *)(v2 + 12) = h2v1_merged_upsample;
  }
  build_ycc_rgb_table_0(cinfo);
}

