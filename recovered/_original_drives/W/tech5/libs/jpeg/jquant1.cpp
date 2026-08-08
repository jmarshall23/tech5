
// ========================================================================
// select_ncolors
// EA  : 0x8323ADA8
// RVA : 0x0123ADA8
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

int __fastcall select_ncolors(jpeg_common_struct *cinfo, int *Ncolors)
{
  int mem; // r29
  J_DCT_METHOD client_data; // r28
  int v6; // r11
  int v7; // r10
  int v8; // ctr
  int v9; // r30
  int result; // r3
  int v11; // r11
  int *v12; // r10
  int i; // ctr
  char v14; // r6
  int v15; // r8
  const int *v16; // r7
  int v17; // r11
  int v18; // r9
  signed int v19; // r11
  int v20; // r10
  unsigned int v21; // r4
  int v22; // r11

  mem = (int)cinfo[4].mem;
  client_data = (J_DCT_METHOD)cinfo[3].client_data;
  v6 = 1;
  do
  {
    v7 = ++v6;
    if ( mem > 1 )
    {
      v8 = mem - 1;
      do
      {
        v7 *= v6;
        --v8;
      }
      while ( v8 != 0 );
    }
  }
  while ( v7 <= client_data );
  v9 = v6 - 1;
  if ( v6 - 1 < 2 )
  {
    cinfo->err->msg_code = 56;
    cinfo->err->msg_parm.i[0] = v7;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = 1;
  if ( mem > 0 )
  {
    v11 = mem;
    v12 = Ncolors - 1;
    for ( i = mem; i != 0; --i )
      *++v12 = v9;
    do
    {
      --v11;
      result *= v9;
    }
    while ( v11 != 0 );
  }
  do
  {
    v14 = 0;
    v15 = 0;
    if ( mem > 0 )
    {
      v16 = RGB_order;
      do
      {
        if ( cinfo[1].global_state == 2 )
          v17 = *v16;
        else
          v17 = v15;
        v18 = v17;
        v19 = Ncolors[v17];
        v20 = v19 + 1;
        v21 = v19 & ~(__ROL4__(result, 1) - 1);
        __twllei(v19, 0);
        v22 = result / v19 * (v19 + 1);
        __twlgei(v21, 0xFFFFFFFF);
        if ( v22 > client_data )
          break;
        ++v15;
        Ncolors[v18] = v20;
        result = v22;
        v14 = 1;
        ++v16;
      }
      while ( v15 < mem );
    }
  }
  while ( v14 != 0 );
  return result;
}


// ========================================================================
// create_colormap
// EA  : 0x8323AEF0
// RVA : 0x0123AEF0
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall create_colormap(jpeg_common_struct *cinfo)
{
  jpeg_entropy_decoder *v1; // r22
  unsigned int *p_insufficient_data; // r31
  signed int v4; // r28
  jpeg_error_mgr *err; // r11
  unsigned __int8 **v6; // r3
  signed int v7; // r25
  int v8; // r23
  unsigned __int8 **v9; // r7
  int v10; // r11
  int v11; // r6
  unsigned int v12; // r9
  signed int v13; // r29
  signed int v14; // r5
  int v15; // r30
  int v16; // r26
  int i; // r27
  signed int v18; // r9
  int v19; // r11
  int j; // ctr
  int v21; // r10

  v1 = *(jpeg_entropy_decoder **)&cinfo[17].is_decompressor;
  p_insufficient_data = (unsigned int *)&v1[2].insufficient_data;
  v4 = select_ncolors(cinfo, Ncolors: (int *)&v1[2].insufficient_data);
  err = cinfo->err;
  if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
  {
    err->msg_parm.i[0] = v4;
    err->msg_parm.i[1] = *p_insufficient_data;
    err->msg_parm.i[2] = (int)v1[3].start_pass;
    err->msg_parm.i[3] = (int)v1[3].decode_mcu;
    cinfo->err->msg_code = 94;
  }
  else
  {
    err->msg_code = 95;
    cinfo->err->msg_parm.i[0] = v4;
  }
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  v6 = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: v4, a4: cinfo[4].mem);
  v7 = v4;
  v8 = 0;
  if ( (int)cinfo[4].mem > 0 )
  {
    v9 = v6;
    do
    {
      v10 = *p_insufficient_data;
      v11 = v7 / (int)*p_insufficient_data;
      v12 = *p_insufficient_data & ~(__ROL4__(v7, 1) - 1);
      __twllei(*p_insufficient_data, 0);
      __twlgei(v12, 0xFFFFFFFF);
      if ( v10 > 0 )
      {
        v13 = v10 - 1;
        v14 = 0;
        v15 = 0;
        v16 = (v10 - 1) / 2;
        for ( i = v10; i != 0; --i )
        {
          v18 = v14;
          __twllei(v13, 0);
          __twlgei(v13 & ~(__ROL4__(v15 + v16, 1) - 1), 0xFFFFFFFF);
          if ( v14 < v4 )
          {
            do
            {
              v19 = 0;
              if ( v11 > 0 )
              {
                for ( j = v11; j != 0; --j )
                {
                  v21 = (int)&(*v9)[v19++];
                  *(_BYTE *)(v21 + v18) = (v15 + v16) / v13;
                }
              }
              v18 += v7;
            }
            while ( v18 < v4 );
          }
          v15 += 255;
          v14 += v11;
        }
      }
      ++v8;
      v7 = v11;
      ++p_insufficient_data;
      ++v9;
    }
    while ( v8 < (int)cinfo[4].mem );
  }
  *(_DWORD *)&v1[1].insufficient_data = v4;
  v1[1].decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))v6;
}


// ========================================================================
// create_colorindex
// EA  : 0x8323B090
// RVA : 0x0123B090
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall create_colorindex(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // r11
  jpeg_entropy_decoder *v3; // r31
  int v4; // r28
  int v5; // r26
  int v6; // r30
  int v7; // r3
  signed int v8; // r11
  int v9; // r10
  int v10; // r5
  int v11; // r10
  int v12; // r7
  signed int v13; // r9
  int v14; // r11
  _BYTE *v15; // r4
  int v16; // r7
  int v17; // r8
  int v18; // r11
  int v19; // r7
  int v20; // r6
  int v21; // r11
  _BYTE *v22; // r10
  int i; // ctr

  mem = cinfo[3].mem;
  v3 = *(jpeg_entropy_decoder **)&cinfo[17].is_decompressor;
  if ( mem == (jpeg_memory_mgr *)1 )
  {
    v4 = 510;
  }
  else
  {
    LOBYTE(mem) = 0;
    v4 = 0;
  }
  HIBYTE(v3[2].decode_mcu) = (_BYTE)mem;
  v3[2].start_pass = (void (__fastcall *)(jpeg_decompress_struct *))cinfo->mem->alloc_sarray(
                                                                      a1: cinfo,
                                                                      a2: 1,
                                                                      a3: v4 + 256,
                                                                      a4: cinfo[4].mem);
  v5 = 0;
  v6 = *(_DWORD *)&v3[1].insufficient_data;
  if ( (int)cinfo[4].mem > 0 )
  {
    v7 = 0;
    do
    {
      v8 = *(_DWORD *)(&v3[2].insufficient_data + v7);
      v9 = __ROL4__(v6, 1) - 1;
      v6 /= v8;
      __twllei(v8, 0);
      __twlgei(v8 & ~v9, 0xFFFFFFFF);
      if ( v4 != 0 )
        *(_DWORD *)((char *)v3[2].start_pass + v7) += 255;
      v10 = v8 - 1;
      v11 = 0;
      v12 = v8 - 1 + 255;
      v13 = 2 * (v8 - 1);
      v14 = __ROL4__(v12, 1);
      v15 = *(_BYTE **)((char *)v3[2].start_pass + v7);
      v16 = v12 / v13;
      __twllei(v13, 0);
      v17 = 0;
      __twlgei(v13 & ~(v14 - 1), 0xFFFFFFFF);
      do
      {
        if ( v17 > v16 )
        {
          v18 = 510 * v11;
          do
          {
            v18 += 510;
            ++v11;
            __twllei(v13, 0);
            v19 = v18 + v10 + 255;
            v20 = __ROL4__(v19, 1);
            v16 = v19 / v13;
            __twlgei(v13 & ~(v20 - 1), 0xFFFFFFFF);
          }
          while ( v17 > v16 );
        }
        v15[v17++] = v11 * v6;
      }
      while ( v17 <= 255 );
      if ( v4 != 0 )
      {
        v21 = 1;
        v22 = v15;
        for ( i = 255; i != 0; --i )
        {
          *--v22 = *v15;
          v15[v21++ + 255] = v15[255];
        }
      }
      ++v5;
      v7 += 4;
    }
    while ( v5 < (int)cinfo[4].mem );
  }
}


// ========================================================================
// create_odither_tables
// EA  : 0x8323B210
// RVA : 0x0123B210
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall create_odither_tables(jpeg_common_struct *cinfo)
{
  jpeg_entropy_decoder *v2; // r25
  int v3; // r29
  jpeg_entropy_decoder *v4; // r26
  int v5; // r31
  int v6; // r11
  unsigned __int8 *p_insufficient_data; // r10
  int v8; // r11
  int v9; // r3
  int v10; // r7
  signed int v11; // r8
  int v12; // r10
  int v13; // r9
  int i; // ctr
  int v15; // r11
  int v16; // r11
  int v17; // r6

  v2 = *(jpeg_entropy_decoder **)&cinfo[17].is_decompressor;
  v3 = 0;
  if ( (int)cinfo[4].mem > 0 )
  {
    v4 = v2 + 4;
    do
    {
      v5 = *(_DWORD *)&v4[-2].insufficient_data;
      v6 = 0;
      if ( v3 <= 0 )
        goto LABEL_9;
      p_insufficient_data = &v2[2].insufficient_data;
      while ( v5 != *(_DWORD *)p_insufficient_data )
      {
        ++v6;
        p_insufficient_data += 4;
        if ( v6 >= v3 )
          goto LABEL_9;
      }
      v8 = *((_DWORD *)&v2[4].decode_mcu + v6);
      if ( v8 == 0 )
      {
LABEL_9:
        v9 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 1024);
        v10 = 0;
        v11 = (v5 << 9) - 512;
        do
        {
          v12 = 0;
          v13 = v10;
          for ( i = 16; i != 0; --i )
          {
            v15 = base_dither_matrix[0][v13];
            __twllei(v11, 0);
            v16 = 65025 - 510 * v15;
            __twlgei(v11 & ~(__ROL4__(v16, 1) - 1), 0xFFFFFFFF);
            v17 = 4 * (v10 + v12++);
            v13 = v10 + v12;
            *(_DWORD *)(v17 + v9) = v16 / v11;
          }
          v10 += 16;
        }
        while ( v10 < 256 );
        v8 = v9;
      }
      ++v3;
      v4 = (jpeg_entropy_decoder *)((char *)v4 + 4);
      v4->start_pass = (void (__fastcall *)(jpeg_decompress_struct *))v8;
    }
    while ( v3 < (int)cinfo[4].mem );
  }
}


// ========================================================================
// color_quantize
// EA  : 0x8323B330
// RVA : 0x0123B330
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall color_quantize(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  J_DITHER_MODE dither_mode; // r27
  int desired_number_of_colors; // r31
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r29
  unsigned __int8 **v7; // r28
  int i; // r25
  J_DITHER_MODE v9; // ctr
  int v10; // r30
  int v11; // r11
  char v12; // r7
  char v13; // r6
  char v14; // r3
  int v15; // r10
  _DWORD *v16; // r9
  int v17; // r24
  int v18; // r23
  int v19; // r22

  dither_mode = cinfo->dither_mode;
  desired_number_of_colors = cinfo->desired_number_of_colors;
  start_pass = cinfo->entropy[2].start_pass;
  if ( num_rows > 0 )
  {
    v7 = output_buf;
    for ( i = num_rows; i != 0; --i )
    {
      v9 = dither_mode;
      if ( dither_mode != JDITHER_NONE )
      {
        v10 = (int)(*v7 - 1);
        v11 = (int)(*(unsigned __int8 **)((char *)v7 + (char *)input_buf - (char *)output_buf) - 1);
        do
        {
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v15 = 0;
          if ( desired_number_of_colors >= 2 )
          {
            v16 = (_DWORD *)((char *)start_pass - 4);
            do
            {
              v17 = v16[1];
              v15 += 2;
              v18 = *(unsigned __int8 *)(v11 + 1);
              v19 = *(unsigned __int8 *)(v11 + 2);
              v11 += 2;
              v16 += 2;
              v12 += *(_BYTE *)(v18 + v17);
              v13 += *(_BYTE *)(v19 + *v16);
            }
            while ( v15 < desired_number_of_colors - 1 );
          }
          if ( v15 < desired_number_of_colors )
            v14 = *(_BYTE *)(*((_DWORD *)start_pass + v15) + *(unsigned __int8 *)++v11);
          *(_BYTE *)++v10 = v13 + v12 + v14;
          --v9;
        }
        while ( v9 != JDITHER_NONE );
      }
      ++v7;
    }
  }
}


// ========================================================================
// color_quantize3
// EA  : 0x8323B408
// RVA : 0x0123B408
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall color_quantize3(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  J_DITHER_MODE dither_mode; // r29
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r10
  int v6; // r3
  int v7; // r31
  int v8; // r30
  int v9; // r4
  unsigned __int8 *v10; // r11
  J_DITHER_MODE v11; // ctr
  unsigned __int8 *v12; // r10
  int v13; // r28
  char v14; // r9
  unsigned __int8 *v15; // r11
  int v16; // r7

  dither_mode = cinfo->dither_mode;
  start_pass = cinfo->entropy[2].start_pass;
  v6 = *(_DWORD *)start_pass;
  v7 = *((_DWORD *)start_pass + 1);
  v8 = *((_DWORD *)start_pass + 2);
  if ( num_rows > 0 )
  {
    v9 = (char *)input_buf - (char *)output_buf;
    do
    {
      v10 = *(unsigned __int8 **)((char *)output_buf + v9);
      if ( dither_mode != JDITHER_NONE )
      {
        v11 = dither_mode;
        v12 = *output_buf - 1;
        do
        {
          v13 = v10[1];
          v14 = *(_BYTE *)(*v10 + v6);
          v15 = v10 + 2;
          v16 = *v15;
          v10 = v15 + 1;
          *++v12 = *(_BYTE *)(v16 + v8) + *(_BYTE *)(v13 + v7) + v14;
          --v11;
        }
        while ( v11 != JDITHER_NONE );
      }
      --num_rows;
      ++output_buf;
    }
    while ( num_rows != 0 );
  }
}


// ========================================================================
// quantize_ord_dither
// EA  : 0x8323B490
// RVA : 0x0123B490
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall quantize_ord_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_entropy_decoder *entropy; // r27
  int desired_number_of_colors; // r31
  size_t dither_mode; // r30
  void **v7; // r29
  int v8; // r24
  int i; // r22
  int v10; // r28
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r23
  int v12; // r3
  int v13; // r11
  int v14; // r5
  int v15; // r4
  _BYTE *v16; // r10
  size_t v17; // ctr
  unsigned __int8 *v18; // r9
  int v19; // r8
  int v20; // r7

  entropy = cinfo->entropy;
  desired_number_of_colors = cinfo->desired_number_of_colors;
  dither_mode = cinfo->dither_mode;
  if ( num_rows > 0 )
  {
    v7 = (void **)output_buf;
    v8 = (char *)input_buf - (char *)output_buf;
    for ( i = num_rows; i != 0; --i )
    {
      jzero_far(target: *v7, bytestozero: dither_mode);
      v10 = 0;
      start_pass = entropy[4].start_pass;
      if ( desired_number_of_colors > 0 )
      {
        v12 = 0;
        do
        {
          LOBYTE(v13) = 0;
          v14 = *(int *)((char *)&entropy[4].decode_mcu + v12) + 64 * (_DWORD)start_pass;
          v15 = *(_DWORD *)((char *)entropy[2].start_pass + v12);
          if ( dither_mode != 0 )
          {
            v16 = (char *)*v7 - 1;
            v17 = dither_mode;
            v18 = (unsigned __int8 *)(*(char **)((char *)v7 + v8) + v10 - desired_number_of_colors);
            v19 = 0;
            do
            {
              v18 += desired_number_of_colors;
              v13 = ((_BYTE)v13 + 1) & 0xF;
              v20 = *(_DWORD *)(v19 + v14) + *v18;
              v19 = 4 * v13;
              LOBYTE(v20) = *(_BYTE *)(v20 + v15) + *++v16;
              *v16 = v20;
              --v17;
            }
            while ( v17 != 0 );
          }
          ++v10;
          v12 += 4;
        }
        while ( v10 < desired_number_of_colors );
      }
      ++v7;
      entropy[4].start_pass = (void (__fastcall *)(jpeg_decompress_struct *))(((unsigned int)start_pass + 1) & 0xF);
    }
  }
}


// ========================================================================
// quantize3_ord_dither
// EA  : 0x8323B580
// RVA : 0x0123B580
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall quantize3_ord_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_entropy_decoder *entropy; // r28
  J_DITHER_MODE dither_mode; // r22
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r11
  int v7; // r27
  int v8; // r26
  int v9; // r25
  unsigned __int8 **v10; // r24
  int v11; // r21
  int i; // r20
  void (__fastcall *v13)(jpeg_decompress_struct *); // r23
  int v14; // r10
  int v15; // r31
  unsigned __int8 *v16; // r11
  int v17; // r30
  int v18; // r29
  J_DITHER_MODE v19; // ctr
  int v20; // r9
  int v21; // r5
  unsigned __int8 *v22; // r11
  int v23; // r4
  int v24; // r6
  int v25; // r8
  int v26; // r5
  int v27; // r4

  entropy = cinfo->entropy;
  dither_mode = cinfo->dither_mode;
  start_pass = entropy[2].start_pass;
  v7 = *(_DWORD *)start_pass;
  v8 = *((_DWORD *)start_pass + 1);
  v9 = *((_DWORD *)start_pass + 2);
  if ( num_rows > 0 )
  {
    v10 = output_buf;
    v11 = (char *)input_buf - (char *)output_buf;
    for ( i = num_rows; i != 0; --i )
    {
      v13 = entropy[4].start_pass;
      v14 = 0;
      v15 = (int)entropy[4].decode_mcu + 64 * (_DWORD)v13;
      v16 = *(unsigned __int8 **)((char *)v10 + v11);
      v17 = *(_DWORD *)&entropy[4].insufficient_data + ((_DWORD)v13 << 6);
      v18 = (int)entropy[5].start_pass + 64 * (_DWORD)v13;
      if ( dither_mode != JDITHER_NONE )
      {
        v19 = dither_mode;
        v20 = (int)(*v10 - 1);
        do
        {
          v21 = *v16;
          v22 = v16 + 1;
          v23 = *(_DWORD *)(4 * v14 + v15);
          v24 = *(_DWORD *)(4 * v14 + v17) + *v22++;
          v25 = *(_DWORD *)(4 * v14 + v18);
          v14 = (v14 + 1) & 0xF;
          v26 = v23 + v21;
          v27 = v25 + *v22;
          v16 = v22 + 1;
          *(_BYTE *)++v20 = *(_BYTE *)(v27 + v9) + *(_BYTE *)(v24 + v8) + *(_BYTE *)(v26 + v7);
          --v19;
        }
        while ( v19 != JDITHER_NONE );
      }
      ++v10;
      entropy[4].start_pass = (void (__fastcall *)(jpeg_decompress_struct *))(((unsigned int)v13 + 1) & 0xF);
    }
  }
}


// ========================================================================
// quantize_fs_dither
// EA  : 0x8323B660
// RVA : 0x0123B660
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall quantize_fs_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_entropy_decoder *entropy; // r21
  int desired_number_of_colors; // r23
  size_t dither_mode; // r24
  int max_h_samp_factor; // r26
  void **v8; // r19
  int v9; // r18
  int i; // r17
  int v11; // r20
  int v12; // r25
  unsigned __int8 *p_insufficient_data; // r22
  _BYTE *v14; // r11
  char *v15; // r6
  int v16; // r30
  int v17; // r29
  _WORD *v18; // r10
  int v19; // r9
  __int16 v20; // r7
  __int16 v21; // r4
  int v22; // r28
  int v23; // r27
  int v24; // r5
  size_t v25; // ctr
  char *v26; // r6
  int v27; // r8
  int v28; // r9
  int v29; // r9
  int v30; // r8
  __int16 v31; // r3
  __int16 v32; // r7
  int v33; // r9

  entropy = cinfo->entropy;
  desired_number_of_colors = cinfo->desired_number_of_colors;
  dither_mode = cinfo->dither_mode;
  max_h_samp_factor = cinfo->max_h_samp_factor;
  if ( num_rows > 0 )
  {
    v8 = (void **)output_buf;
    v9 = (char *)input_buf - (char *)output_buf;
    for ( i = num_rows; i != 0; --i )
    {
      jzero_far(target: *v8, bytestozero: dither_mode);
      v11 = 0;
      if ( desired_number_of_colors > 0 )
      {
        v12 = 0;
        p_insufficient_data = &entropy[5].insufficient_data;
        do
        {
          v14 = *v8;
          v15 = *(char **)((char *)v8 + v9) + v11;
          if ( HIBYTE(entropy[7].start_pass) != 0 )
          {
            v14 += dither_mode - 1;
            v15 += (dither_mode - 1) * desired_number_of_colors;
            v16 = -1;
            v17 = -desired_number_of_colors;
            v18 = (_WORD *)(*(_DWORD *)&p_insufficient_data[v12] + 2 * (dither_mode + 1));
          }
          else
          {
            v18 = *(_WORD **)&p_insufficient_data[v12];
            v16 = 1;
            v17 = desired_number_of_colors;
          }
          v19 = 0;
          v20 = 0;
          v21 = 0;
          v22 = *(_DWORD *)((char *)entropy[2].start_pass + v12);
          v23 = *(_DWORD *)((char *)entropy[1].decode_mcu + v12);
          if ( dither_mode != 0 )
          {
            v24 = v16;
            v25 = dither_mode;
            v26 = &v15[-v17];
            do
            {
              v26 += v17;
              v27 = *(unsigned __int8 *)((((__int16)v18[v24] + v19 + 8) >> 4) + (unsigned __int8)*v26 + max_h_samp_factor);
              v28 = *(unsigned __int8 *)(v27 + v22);
              *v14 += v28;
              v14 += v16;
              v29 = v27 - *(unsigned __int8 *)(v28 + v23);
              v30 = 2 * v29;
              v31 = v29;
              v29 *= 3;
              v32 = v20 + v29;
              v33 = v30 + v29;
              *v18 = v32;
              v20 = v21 + v33;
              v21 = v31;
              v19 = v30 + v33;
              v18 = (_WORD *)((char *)v18 + v24 * 2);
              --v25;
            }
            while ( v25 != 0 );
          }
          ++v11;
          *v18 = v20;
          v12 += 4;
        }
        while ( v11 < desired_number_of_colors );
      }
      ++v8;
      HIBYTE(entropy[7].start_pass) = (_cntlzw(HIBYTE(entropy[7].start_pass)) & 0x20) != 0;
    }
  }
}


// ========================================================================
// alloc_fs_workspace
// EA  : 0x8323B7D8
// RVA : 0x0123B7D8
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall alloc_fs_workspace(jpeg_common_struct *cinfo)
{
  int v2; // r30
  unsigned int v3; // r28
  _DWORD *v4; // r29

  v2 = 0;
  v3 = 2 * (cinfo[3].global_state + 2);
  if ( (int)cinfo[4].mem > 0 )
  {
    v4 = (_DWORD *)(*(_DWORD *)&cinfo[17].is_decompressor + 64);
    do
    {
      ++v2;
      *++v4 = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: v3);
    }
    while ( v2 < (int)cinfo[4].mem );
  }
}


// ========================================================================
// start_pass_1_quant
// EA  : 0x8323B848
// RVA : 0x0123B848
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall start_pass_1_quant(jpeg_common_struct *cinfo, unsigned __int8 is_pre_scan)
{
  jpeg_entropy_decoder *v2; // r31
  unsigned int mem; // r11
  int v5; // r10
  unsigned __int8 *p_insufficient_data; // r29
  int v7; // r31
  size_t v8; // r28
  void **v9; // r29
  void (__fastcall *v10)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // r10
  int decode_mcu_high; // r11

  v2 = *(jpeg_entropy_decoder **)&cinfo[17].is_decompressor;
  mem = (unsigned int)cinfo[3].mem;
  cinfo[4].global_state = (int)v2[1].decode_mcu;
  *(_DWORD *)&cinfo[4].is_decompressor = *(_DWORD *)&v2[1].insufficient_data;
  if ( mem != 0 )
  {
    if ( mem == 1 )
    {
      if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
        v10 = quantize3_ord_dither;
      else
        v10 = quantize_ord_dither;
      v2->decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))v10;
      decode_mcu_high = HIBYTE(v2[2].decode_mcu);
      v2[4].start_pass = nullptr;
      if ( decode_mcu_high == 0 )
        create_colorindex(cinfo);
      if ( v2[4].decode_mcu == nullptr )
        create_odither_tables(cinfo);
    }
    else if ( mem < 3 )
    {
      v5 = *(_DWORD *)&v2[5].insufficient_data;
      p_insufficient_data = &v2[5].insufficient_data;
      HIBYTE(v2[7].start_pass) = 0;
      v2->decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))quantize_fs_dither;
      if ( v5 == 0 )
        alloc_fs_workspace(cinfo);
      v7 = 0;
      v8 = 2 * (cinfo[3].global_state + 2);
      if ( (int)cinfo[4].mem > 0 )
      {
        v9 = (void **)(p_insufficient_data - 4);
        do
        {
          jzero_far(target: *++v9, bytestozero: v8);
          ++v7;
        }
        while ( v7 < (int)cinfo[4].mem );
      }
    }
    else
    {
      cinfo->err->msg_code = 48;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else if ( cinfo[4].mem == (jpeg_memory_mgr *)3 )
  {
    v2->decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))color_quantize3;
  }
  else
  {
    v2->decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))color_quantize;
  }
}


// ========================================================================
// new_color_map_1_quant
// EA  : 0x8323B9A8
// RVA : 0x0123B9A8
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall new_color_map_1_quant(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 46;
  cinfo->err->error_exit(a1: cinfo);
}


// ========================================================================
// ?jinit_1pass_quantizer@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x8323B9C8
// RVA : 0x0123B9C8
// PDB : w:\tech5\libs\jpeg\jquant1.cpp
// ========================================================================

void __fastcall jinit_1pass_quantizer(jpeg_common_struct *cinfo)
{
  int v2; // r3

  v2 = ((int (*)(void))cinfo->mem->alloc_small)();
  *(_DWORD *)&cinfo[17].is_decompressor = v2;
  *(_DWORD *)(v2 + 68) = 0;
  *(_DWORD *)v2 = start_pass_1_quant;
  *(_DWORD *)(v2 + 8) = idPhysics_StaticMulti::UpdateTime;
  *(_DWORD *)(v2 + 12) = new_color_map_1_quant;
  *(_DWORD *)(v2 + 52) = 0;
  if ( (int)cinfo[4].mem > 4 )
  {
    cinfo->err->msg_code = 55;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)cinfo[3].client_data > 256 )
  {
    cinfo->err->msg_code = 57;
    cinfo->err->msg_parm.i[0] = 256;
    cinfo->err->error_exit(a1: cinfo);
  }
  create_colormap(cinfo);
  create_colorindex(cinfo);
  if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
    alloc_fs_workspace(cinfo);
}

