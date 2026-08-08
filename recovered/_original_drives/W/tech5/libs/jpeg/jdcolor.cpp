
// ========================================================================
// build_ycc_rgb_table
// EA  : 0x832386D0
// RVA : 0x012386D0
// PDB : w:\tech5\libs\jpeg\jdcolor.cpp
// ========================================================================

void __fastcall build_ycc_rgb_table(jpeg_common_struct *cinfo)
{
  jpeg_marker_reader *client_data; // r31
  int v3; // ctr
  int v4; // r11
  int v5; // r8
  int v6; // r9
  int v7; // r10
  int v8; // r7

  client_data = (jpeg_marker_reader *)cinfo[17].client_data;
  client_data->read_restart_marker = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *))((int (*)(void))cinfo->mem->alloc_small)();
  *(_DWORD *)&client_data->saw_SOI = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  client_data->next_restart_num = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  client_data->discarded_bytes = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
  v3 = 256;
  v4 = 0;
  v5 = 5990656;
  v6 = -14831872;
  v7 = -11728000;
  v8 = 2919680;
  do
  {
    *(_DWORD *)((char *)client_data->read_restart_marker + v4) = v7 >> 16;
    v7 += 91881;
    *(_DWORD *)(*(_DWORD *)&client_data->saw_SOI + v4) = v6 >> 16;
    v6 += 116130;
    *(_DWORD *)(v4 + client_data->next_restart_num) = v5;
    v5 -= 46802;
    *(_DWORD *)(client_data->discarded_bytes + v4) = v8;
    v8 -= 22554;
    v4 += 4;
    --v3;
  }
  while ( v3 != 0 );
}


// ========================================================================
// ycc_rgb_convert
// EA  : 0x832387F0
// RVA : 0x012387F0
// PDB : w:\tech5\libs\jpeg\jdcolor.cpp
// ========================================================================

void __fastcall ycc_rgb_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_marker_reader *marker; // r11
  int v6; // r24
  J_DITHER_MODE dither_mode; // r26
  int max_h_samp_factor; // r8
  unsigned __int8 (__fastcall *read_restart_marker)(jpeg_decompress_struct *); // r31
  int v10; // r30
  int next_restart_num; // r29
  unsigned int discarded_bytes; // r28
  unsigned int v13; // r27
  unsigned __int8 **v14; // r25
  unsigned __int8 *v15; // r9
  unsigned __int8 *v16; // r11
  unsigned __int8 *v17; // r7
  J_DITHER_MODE v18; // ctr
  unsigned __int8 *v19; // r10
  int v20; // r5
  int v21; // r3
  int v22; // r9
  int v23; // r6
  int v24; // r7
  int v25; // r23

  marker = cinfo->marker;
  v6 = num_rows - 1;
  dither_mode = cinfo->dither_mode;
  max_h_samp_factor = cinfo->max_h_samp_factor;
  read_restart_marker = marker->read_restart_marker;
  v10 = *(_DWORD *)&marker->saw_SOI;
  next_restart_num = marker->next_restart_num;
  discarded_bytes = marker->discarded_bytes;
  if ( num_rows - 1 >= 0 )
  {
    v13 = input_row;
    v14 = output_buf - 1;
    do
    {
      ++v14;
      v15 = (*input_buf)[v13];
      v16 = input_buf[1][v13];
      v17 = input_buf[2][v13++];
      if ( dither_mode != JDITHER_NONE )
      {
        v18 = dither_mode;
        v19 = *v14 - 2;
        v20 = v15 - v16;
        v21 = v17 - v16;
        do
        {
          v22 = v16[v20];
          v23 = __ROL4__(v16[v21], 2);
          v24 = *v16++;
          v25 = __ROL4__(v24, 2);
          v19[2] = *(_BYTE *)(*(_DWORD *)((char *)read_restart_marker + v23) + v22 + max_h_samp_factor);
          v19[3] = *(_BYTE *)(((*(_DWORD *)(v25 + discarded_bytes) + *(_DWORD *)(v23 + next_restart_num)) >> 16)
                            + v22
                            + max_h_samp_factor);
          v19 += 4;
          *v19 = *(_BYTE *)(*(_DWORD *)(v25 + v10) + v22 + max_h_samp_factor);
          --v18;
        }
        while ( v18 != JDITHER_NONE );
      }
      --v6;
    }
    while ( v6 >= 0 );
  }
}


// ========================================================================
// null_convert
// EA  : 0x832388C0
// RVA : 0x012388C0
// PDB : w:\tech5\libs\jpeg\jdcolor.cpp
// ========================================================================

void __fastcall null_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  int v5; // r30
  int num_components; // r8
  J_DITHER_MODE dither_mode; // r7
  bool v8; // zf
  unsigned int v9; // r31
  int v10; // r5
  unsigned __int8 ***v11; // r3
  unsigned __int8 *v12; // r10
  J_DITHER_MODE v13; // ctr
  unsigned __int8 *v14; // r11

  v5 = num_rows - 1;
  num_components = cinfo->num_components;
  v8 = num_rows - 1 < 0;
  dither_mode = cinfo->dither_mode;
  if ( !v8 )
  {
    v9 = input_row;
    do
    {
      v10 = 0;
      if ( num_components > 0 )
      {
        v11 = input_buf;
        do
        {
          if ( dither_mode != JDITHER_NONE )
          {
            v12 = &(*output_buf)[v10 - num_components];
            v13 = dither_mode;
            v14 = (*v11)[v9] - 1;
            do
            {
              ++v14;
              v12 += num_components;
              *v12 = *v14;
              --v13;
            }
            while ( v13 != JDITHER_NONE );
          }
          ++v10;
          ++v11;
        }
        while ( v10 < num_components );
      }
      --v5;
      ++v9;
      ++output_buf;
    }
    while ( v5 >= 0 );
  }
}


// ========================================================================
// grayscale_convert
// EA  : 0x83238948
// RVA : 0x01238948
// PDB : w:\tech5\libs\jpeg\jdcolor.cpp
// ========================================================================

void __fastcall grayscale_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jcopy_sample_rows(
    input_array: *input_buf,
    source_row: input_row,
    output_array: output_buf,
    dest_row: 0,
    num_rows,
    num_cols: cinfo->dither_mode);
}


// ========================================================================
// gray_rgb_convert
// EA  : 0x83238968
// RVA : 0x01238968
// PDB : w:\tech5\libs\jpeg\jdcolor.cpp
// ========================================================================

void __fastcall gray_rgb_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  J_DITHER_MODE dither_mode; // r3
  int v6; // r31
  unsigned int v7; // r9
  unsigned __int8 **v8; // r7
  int v9; // r10
  unsigned __int8 *v10; // r8
  unsigned __int8 *v11; // r11
  J_DITHER_MODE i; // ctr
  unsigned __int8 v13; // r6

  dither_mode = cinfo->dither_mode;
  v6 = num_rows - 1;
  if ( num_rows - 1 >= 0 )
  {
    v7 = input_row;
    v8 = output_buf - 1;
    do
    {
      v9 = 0;
      ++v8;
      v10 = (*input_buf)[v7++];
      if ( dither_mode != JDITHER_NONE )
      {
        v11 = *v8 - 4;
        for ( i = dither_mode; i != JDITHER_NONE; --i )
        {
          v13 = v10[v9++];
          v11[6] = v13;
          v11[5] = v13;
          v11 += 4;
          *v11 = v13;
        }
      }
      --v6;
    }
    while ( v6 >= 0 );
  }
}


// ========================================================================
// ycck_cmyk_convert
// EA  : 0x832389D0
// RVA : 0x012389D0
// PDB : w:\tech5\libs\jpeg\jdcolor.cpp
// ========================================================================

void __fastcall ycck_cmyk_convert(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int input_row,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_marker_reader *marker; // r11
  int v6; // r24
  J_DITHER_MODE dither_mode; // r26
  int max_h_samp_factor; // r9
  unsigned __int8 (__fastcall *read_restart_marker)(jpeg_decompress_struct *); // r30
  int v10; // r29
  int next_restart_num; // r28
  unsigned int discarded_bytes; // r27
  unsigned int v13; // r31
  unsigned __int8 **v14; // r25
  unsigned __int8 *v15; // r8
  unsigned __int8 *v16; // r11
  unsigned __int8 *v17; // r7
  unsigned __int8 *v18; // r3
  J_DITHER_MODE v19; // ctr
  unsigned __int8 *v20; // r10
  int v21; // r6
  int v22; // r5
  int v23; // r3
  int v24; // r8
  int v25; // r23
  int v26; // r22
  unsigned __int8 v27; // r7

  marker = cinfo->marker;
  v6 = num_rows - 1;
  dither_mode = cinfo->dither_mode;
  max_h_samp_factor = cinfo->max_h_samp_factor;
  read_restart_marker = marker->read_restart_marker;
  v10 = *(_DWORD *)&marker->saw_SOI;
  next_restart_num = marker->next_restart_num;
  discarded_bytes = marker->discarded_bytes;
  if ( num_rows - 1 >= 0 )
  {
    v13 = input_row;
    v14 = output_buf - 1;
    do
    {
      ++v14;
      v15 = (*input_buf)[v13];
      v16 = input_buf[1][v13];
      v17 = input_buf[2][v13];
      v18 = input_buf[3][v13++];
      if ( dither_mode != JDITHER_NONE )
      {
        v19 = dither_mode;
        v20 = *v14 - 1;
        v21 = v15 - v16;
        v22 = v17 - v16;
        v23 = v18 - v16;
        do
        {
          v24 = __ROL4__(v16[v22], 2);
          v25 = v16[v21];
          v26 = __ROL4__(*v16, 2);
          v20[1] = *(_BYTE *)(max_h_samp_factor - *(_DWORD *)((char *)read_restart_marker + v24) - v25 + 255);
          v20[2] = *(_BYTE *)(max_h_samp_factor
                            - ((*(_DWORD *)(v26 + discarded_bytes) + *(_DWORD *)(v24 + next_restart_num)) >> 16)
                            - v25
                            + 255);
          v20[3] = *(_BYTE *)(max_h_samp_factor - *(_DWORD *)(v26 + v10) - v25 + 255);
          v27 = (v16++)[v23];
          v20 += 4;
          *v20 = v27;
          --v19;
        }
        while ( v19 != JDITHER_NONE );
      }
      --v6;
    }
    while ( v6 >= 0 );
  }
}


// ========================================================================
// ?jinit_color_deconverter@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x83238AC0
// RVA : 0x01238AC0
// PDB : w:\tech5\libs\jpeg\jdcolor.cpp
// ========================================================================

void __fastcall jinit_color_deconverter(jpeg_common_struct *cinfo)
{
  jpeg_marker_reader *v2; // r3
  jpeg_marker_reader *v3; // r30
  J_COLOR_SPACE global_state; // r11
  J_COLOR_SPACE v5; // r11
  J_COLOR_SPACE v6; // r11
  J_COLOR_SPACE v7; // r11
  int v8; // r11
  int v9; // r10
  char *v10; // r9

  v2 = (jpeg_marker_reader *)((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[17].client_data = v2;
  v3 = v2;
  v2->reset_marker_reader = (void (__fastcall *)(jpeg_decompress_struct *))idPhysics_StaticMulti::UpdateTime;
  if ( (unsigned int)(*(_DWORD *)&cinfo[1].is_decompressor - 1) > 4 )
  {
    if ( (int)cinfo[1].client_data >= 1 )
      goto LABEL_13;
  }
  else if ( *(_DWORD *)&cinfo[1].is_decompressor == 2 || *(_DWORD *)&cinfo[1].is_decompressor == 3 )
  {
    if ( cinfo[1].client_data == (void *)3 )
      goto LABEL_13;
  }
  else if ( *(_DWORD *)&cinfo[1].is_decompressor == 1 )
  {
    if ( cinfo[1].client_data == (void *)1 )
      goto LABEL_13;
  }
  else if ( cinfo[1].client_data == (void *)4 )
  {
    goto LABEL_13;
  }
  cinfo->err->msg_code = 10;
  cinfo->err->error_exit(a1: cinfo);
LABEL_13:
  global_state = cinfo[1].global_state;
  if ( global_state != JCS_GRAYSCALE )
  {
    if ( global_state == JCS_RGB )
    {
      v6 = *(_DWORD *)&cinfo[1].is_decompressor;
      cinfo[4].mem = (jpeg_memory_mgr *)4;
      if ( v6 == JCS_YCbCr )
      {
        v3->read_markers = (int (__fastcall *)(jpeg_decompress_struct *))ycc_rgb_convert;
        build_ycc_rgb_table(cinfo);
        goto LABEL_32;
      }
      if ( v6 == JCS_GRAYSCALE )
      {
        v3->read_markers = (int (__fastcall *)(jpeg_decompress_struct *))gray_rgb_convert;
        goto LABEL_32;
      }
    }
    else if ( global_state == JCS_CMYK )
    {
      v5 = *(_DWORD *)&cinfo[1].is_decompressor;
      cinfo[4].mem = (jpeg_memory_mgr *)4;
      if ( v5 == JCS_YCCK )
      {
        v3->read_markers = (int (__fastcall *)(jpeg_decompress_struct *))ycck_cmyk_convert;
        build_ycc_rgb_table(cinfo);
        goto LABEL_32;
      }
      if ( v5 == JCS_CMYK )
      {
        v3->read_markers = (int (__fastcall *)(jpeg_decompress_struct *))null_convert;
        goto LABEL_32;
      }
    }
    else if ( global_state == *(_DWORD *)&cinfo[1].is_decompressor )
    {
      cinfo[4].mem = (jpeg_memory_mgr *)cinfo[1].client_data;
      v3->read_markers = (int (__fastcall *)(jpeg_decompress_struct *))null_convert;
      goto LABEL_32;
    }
    goto LABEL_28;
  }
  v7 = *(_DWORD *)&cinfo[1].is_decompressor;
  cinfo[4].mem = (jpeg_memory_mgr *)1;
  if ( v7 != JCS_GRAYSCALE && v7 != JCS_YCbCr )
  {
LABEL_28:
    cinfo->err->msg_code = 27;
    cinfo->err->error_exit(a1: cinfo);
    goto LABEL_32;
  }
  v8 = 1;
  v3->read_markers = (int (__fastcall *)(jpeg_decompress_struct *))grayscale_convert;
  if ( (int)cinfo[1].client_data > 1 )
  {
    v9 = 84;
    do
    {
      ++v8;
      v10 = (char *)cinfo[8].mem + v9;
      v9 += 84;
      v10[48] = 0;
    }
    while ( v8 < (int)cinfo[1].client_data );
  }
LABEL_32:
  if ( BYTE2(cinfo[3].err) != 0 )
    cinfo[4].progress = (jpeg_progress_mgr *)1;
  else
    cinfo[4].progress = (jpeg_progress_mgr *)cinfo[4].mem;
}

