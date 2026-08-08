
// ========================================================================
// ?jxr_output_mb_id_mono@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x829069F0
// RVA : 0x009069F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

// attributes: thunk
void __fastcall jxr_output_mb_id_mono(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  _jxr_output_mb_id_mono(image, mx, buffer, byteStride);
}


// ========================================================================
// ?jxr_output_mb_id_grayscale@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x829069F8
// RVA : 0x009069F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

// attributes: thunk
void __fastcall jxr_output_mb_id_grayscale(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  _jxr_output_mb_id_grayscale(image, mx, buffer, byteStride);
}


// ========================================================================
// ?jxr_output_mb_id_rgb@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x82906A00
// RVA : 0x00906A00
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

// attributes: thunk
void __fastcall jxr_output_mb_id_rgb(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  _jxr_output_mb_id_rgb(image, mx, buffer, byteStride);
}


// ========================================================================
// ?jxr_output_mb_id_cocg_y@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x82906A08
// RVA : 0x00906A08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

// attributes: thunk
void __fastcall jxr_output_mb_id_cocg_y(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  _jxr_output_mb_id_cocg_y(image, mx, buffer, byteStride);
}


// ========================================================================
// ?jxr_output_mb_id_normal_y_x@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x82906A10
// RVA : 0x00906A10
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

// attributes: thunk
void __fastcall jxr_output_mb_id_normal_y_x(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  _jxr_output_mb_id_normal_y_x(image, mx, buffer, byteStride);
}


// ========================================================================
// r_image_header
// EA  : 0x82906A18
// RVA : 0x00906A18
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_image_header(jxr_image *image, rbitstream *str)
{
  _BYTE *v2; // r10
  const char *v5; // r11
  int i; // ctr
  unsigned int j; // r30
  unsigned __int8 v8; // r3
  unsigned __int8 header_flags2; // r11
  unsigned int *v11; // r3
  unsigned int tile_columns; // r10
  unsigned int v13; // r4
  unsigned int *v14; // r3
  unsigned int tile_rows; // r7
  unsigned __int8 v16; // r6
  unsigned int v17; // r28
  unsigned int v18; // r11
  unsigned int v19; // r29
  int v20; // r30
  unsigned int v21; // r11
  unsigned int v22; // r11
  unsigned int v23; // r30
  unsigned int v24; // r26
  int v25; // r29
  unsigned int v26; // r11
  unsigned int v27; // r11
  unsigned int height1; // r11
  int v29; // r11
  unsigned int v30; // r7
  int v31; // r10
  unsigned int *tile_column_width; // r8
  unsigned int v33; // r11
  unsigned int v34; // r9
  int use_clr_fmt; // r11
  unsigned int v36; // r10
  unsigned int k; // r11
  _BYTE v38[81]; // [sp+4Fh] [-51h] BYREF

  v2 = v38;
  v5 = &abslevel_code1v[63];
  for ( i = 9; i != 0; --i )
    *++v2 = *++v5;
  for ( j = 0; j < 8; ++j )
  {
    if ( (unsigned __int8)_jxr_rbitstream_uint8(str) != (char)v38[j + 1] )
      return -2;
  }
  _jxr_rbitstream_uint4(str);
  image->disableTileOverlapFlag = _jxr_rbitstream_uint1(str);
  _jxr_rbitstream_uint3(str);
  image->header_flags1 = _jxr_rbitstream_uint8(str);
  image->header_flags2 = _jxr_rbitstream_uint8(str);
  v8 = _jxr_rbitstream_uint8(str);
  header_flags2 = image->header_flags2;
  image->header_flags_fmt = v8;
  if ( (header_flags2 & 0x80) != 0 )
  {
    image->width1 = (unsigned __int16)_jxr_rbitstream_uint16(str);
    image->height1 = (unsigned __int16)_jxr_rbitstream_uint16(str);
  }
  else
  {
    image->width1 = _jxr_rbitstream_uint32(str);
    image->height1 = _jxr_rbitstream_uint32(str);
  }
  if ( jxr_get_TILING_FLAG(image) != 0 )
  {
    image->tile_columns = (unsigned __int16)_jxr_rbitstream_uint12(str) + 1;
    image->tile_rows = (unsigned __int16)_jxr_rbitstream_uint12(str) + 1;
  }
  else
  {
    image->tile_columns = 1;
    image->tile_rows = 1;
  }
  v11 = (unsigned int *)_jxr_temp_calloc(image, count: 2 * image->tile_columns, size: 4u);
  tile_columns = image->tile_columns;
  image->tile_column_width = v11;
  v13 = 2 * image->tile_rows;
  image->tile_column_position = &v11[tile_columns];
  v14 = (unsigned int *)_jxr_temp_calloc(image, count: v13, size: 4u);
  tile_rows = image->tile_rows;
  v16 = image->header_flags2;
  v17 = 0;
  image->tile_row_height = v14;
  v18 = image->tile_columns;
  image->tile_row_position = &v14[tile_rows];
  v19 = 0;
  if ( v18 != 1 )
  {
    v20 = 0;
    if ( (v16 & 0x80) != 0 )
    {
      do
      {
        ++v19;
        image->tile_column_width[v20] = (unsigned __int8)_jxr_rbitstream_uint8(str);
        image->tile_column_position[v20] = v17;
        v21 = image->tile_column_width[v20++];
        v17 += v21;
      }
      while ( v19 < image->tile_columns - 1 );
    }
    else
    {
      do
      {
        ++v19;
        image->tile_column_width[v20] = (unsigned __int16)_jxr_rbitstream_uint16(str);
        image->tile_column_position[v20] = v17;
        v22 = image->tile_column_width[v20++];
        v17 += v22;
      }
      while ( v19 < image->tile_columns - 1 );
    }
  }
  v23 = 0;
  v24 = 0;
  if ( image->tile_rows != 1 )
  {
    v25 = 0;
    if ( (image->header_flags2 & 0x80) != 0 )
    {
      do
      {
        ++v24;
        image->tile_row_height[v25] = (unsigned __int8)_jxr_rbitstream_uint8(str);
        image->tile_row_position[v25] = v23;
        v26 = image->tile_row_height[v25++];
        v23 += v26;
      }
      while ( v24 < image->tile_rows - 1 );
    }
    else
    {
      do
      {
        ++v24;
        image->tile_row_height[v25] = (unsigned __int16)_jxr_rbitstream_uint16(str);
        image->tile_row_position[v25] = v23;
        v27 = image->tile_row_height[v25++];
        v23 += v27;
      }
      while ( v24 < image->tile_rows - 1 );
    }
  }
  if ( (image->header_flags2 & 0x20) != 0 )
  {
    image->window_extra_top = (unsigned __int8)_jxr_rbitstream_uint6(str);
    image->window_extra_left = (unsigned __int8)_jxr_rbitstream_uint6(str);
    image->window_extra_bottom = (unsigned __int8)_jxr_rbitstream_uint6(str);
    image->window_extra_right = (unsigned __int8)_jxr_rbitstream_uint6(str);
  }
  else
  {
    height1 = image->height1;
    image->window_extra_top = 0;
    image->window_extra_left = 0;
    v29 = ((_BYTE)height1 + 1) & 0xF;
    if ( v29 != 0 )
      image->window_extra_bottom = 16 - v29;
    else
      image->window_extra_bottom = 0;
    if ( (((unsigned __int8)image->width1 + 1) & 0xF) != 0 )
      image->window_extra_right = 16 - (((unsigned __int8)image->width1 + 1) & 0xF);
    else
      image->window_extra_right = 0;
  }
  v30 = image->height1;
  v31 = image->window_extra_bottom + image->window_extra_top;
  tile_column_width = image->tile_column_width;
  v33 = image->window_extra_right + image->window_extra_left + image->width1 + 1;
  v34 = image->tile_columns;
  image->lwf_test = 0;
  image->extended_width = v33;
  image->extended_height = v31 + v30 + 1;
  tile_column_width[v34 - 1] = (v33 >> 4) - v17;
  image->tile_column_position[image->tile_columns - 1] = v17;
  image->tile_row_height[image->tile_rows - 1] = (image->extended_height >> 4) - v23;
  image->tile_row_position[image->tile_rows - 1] = v23;
  if ( (image->header_flags1 & 3u) >= 2 )
  {
    use_clr_fmt = image->use_clr_fmt;
    if ( (use_clr_fmt == 1 || use_clr_fmt == 2) && image->disableTileOverlapFlag != 0 )
    {
      v36 = image->tile_columns;
      for ( k = 0; k < v36; ++k )
        ;
    }
  }
  return 0;
}


// ========================================================================
// ?_jxr_r_DC_QP@@YAHPAUjxr_image@@PAUrbitstream@@@Z
// EA  : 0x82906EA8
// RVA : 0x00906EA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall _jxr_r_DC_QP(jxr_image *image, rbitstream *str)
{
  unsigned int v4; // r11
  unsigned int v5; // r30
  unsigned __int8 v7; // r3
  unsigned int v8; // r10
  unsigned int v9; // r11
  unsigned __int8 v10; // r3
  unsigned int num_channels; // r10
  unsigned int v12; // r11

  if ( image->num_channels == 1 )
    v4 = 0;
  else
    v4 = (unsigned __int8)_jxr_rbitstream_uint2(str);
  if ( v4 == 0 )
  {
    v10 = _jxr_rbitstream_uint8(str);
    num_channels = image->num_channels;
    image->dc_quant_ch[0] = v10;
    v12 = 1;
    if ( num_channels > 1 )
    {
      do
        image->dc_quant_ch[v12++] = image->dc_quant_ch[0];
      while ( v12 < image->num_channels );
    }
    return 0;
  }
  if ( v4 != 1 )
  {
    if ( v4 < 3 )
    {
      v5 = 0;
      if ( image->num_channels != 0 )
      {
        do
          image->dc_quant_ch[v5++] = _jxr_rbitstream_uint8(str);
        while ( v5 < image->num_channels );
        return 0;
      }
    }
    return 0;
  }
  image->dc_quant_ch[0] = _jxr_rbitstream_uint8(str);
  v7 = _jxr_rbitstream_uint8(str);
  v8 = image->num_channels;
  image->dc_quant_ch[1] = v7;
  v9 = 2;
  if ( v8 <= 2 )
    return 0;
  do
    image->dc_quant_ch[v9++] = image->dc_quant_ch[1];
  while ( v9 < image->num_channels );
  return 0;
}


// ========================================================================
// ?_jxr_r_LP_QP@@YAHPAUjxr_image@@PAUrbitstream@@@Z
// EA  : 0x82906FC0
// RVA : 0x00906FC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall _jxr_r_LP_QP(jxr_image *image, rbitstream *str)
{
  unsigned __int8 *v4; // r25
  int v5; // r26
  unsigned __int8 *v6; // r30
  unsigned int v7; // r11
  unsigned int v8; // r29
  unsigned __int8 *v9; // r28
  unsigned __int8 *v10; // r29
  unsigned __int8 v11; // r3
  unsigned int v12; // r11
  _BYTE *v13; // r10
  unsigned __int8 v14; // r3
  unsigned int v15; // r11
  unsigned __int8 *v16; // r10

  if ( image->num_lp_qps != 0 )
  {
    v4 = image->lp_quant_ch[0];
    v5 = -1688 - (_DWORD)image;
    v6 = image->lp_quant_ch[0];
    do
    {
      if ( image->num_channels == 1 )
        v7 = 0;
      else
        v7 = (unsigned __int8)_jxr_rbitstream_uint2(str);
      if ( v7 != 0 )
      {
        if ( v7 == 1 )
        {
          v10 = &v6[v5];
          v4[(_DWORD)v10] = _jxr_rbitstream_uint8(str);
          v11 = _jxr_rbitstream_uint8(str);
          v12 = 2;
          image->lp_quant_ch[1][(_DWORD)v10] = v11;
          if ( image->num_channels > 2u )
          {
            v13 = v6 + 16;
            do
            {
              ++v12;
              v13 += 16;
              *v13 = v6[16];
            }
            while ( v12 < image->num_channels );
          }
        }
        else if ( v7 < 3 )
        {
          v8 = 0;
          if ( image->num_channels != 0 )
          {
            v9 = v6 - 16;
            do
            {
              ++v8;
              v9 += 16;
              *v9 = _jxr_rbitstream_uint8(str);
            }
            while ( v8 < image->num_channels );
          }
        }
      }
      else
      {
        v14 = _jxr_rbitstream_uint8(str);
        v15 = 1;
        v6[v5 + (_DWORD)v4] = v14;
        if ( image->num_channels > 1u )
        {
          v16 = v6;
          do
          {
            ++v15;
            v16 += 16;
            *v16 = *v6;
          }
          while ( v15 < image->num_channels );
        }
      }
      ++v6;
    }
    while ( (unsigned int)&v6[v5] < image->num_lp_qps );
  }
  return 0;
}


// ========================================================================
// r_HP_QP
// EA  : 0x82907100
// RVA : 0x00907100
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_HP_QP(jxr_image *image, rbitstream *str)
{
  unsigned __int8 *v4; // r25
  int v5; // r26
  unsigned __int8 *v6; // r30
  unsigned int v7; // r11
  unsigned int v8; // r29
  unsigned __int8 *v9; // r28
  unsigned __int8 *v10; // r29
  unsigned __int8 v11; // r3
  unsigned int v12; // r11
  _BYTE *v13; // r10
  unsigned __int8 v14; // r3
  unsigned int v15; // r11
  unsigned __int8 *v16; // r10

  if ( image->num_hp_qps != 0 )
  {
    v4 = image->hp_quant_ch[0];
    v5 = -1944 - (_DWORD)image;
    v6 = image->hp_quant_ch[0];
    do
    {
      if ( image->num_channels == 1 )
        v7 = 0;
      else
        v7 = (unsigned __int8)_jxr_rbitstream_uint2(str);
      if ( v7 != 0 )
      {
        if ( v7 == 1 )
        {
          v10 = &v6[v5];
          v4[(_DWORD)v10] = _jxr_rbitstream_uint8(str);
          v11 = _jxr_rbitstream_uint8(str);
          v12 = 2;
          image->hp_quant_ch[1][(_DWORD)v10] = v11;
          if ( image->num_channels > 2u )
          {
            v13 = v6 + 16;
            do
            {
              ++v12;
              v13 += 16;
              *v13 = v6[16];
            }
            while ( v12 < image->num_channels );
          }
        }
        else if ( v7 < 3 )
        {
          v8 = 0;
          if ( image->num_channels != 0 )
          {
            v9 = v6 - 16;
            do
            {
              ++v8;
              v9 += 16;
              *v9 = _jxr_rbitstream_uint8(str);
            }
            while ( v8 < image->num_channels );
          }
        }
      }
      else
      {
        v14 = _jxr_rbitstream_uint8(str);
        v15 = 1;
        v6[v5 + (_DWORD)v4] = v14;
        if ( image->num_channels > 1u )
        {
          v16 = v6;
          do
          {
            ++v15;
            v16 += 16;
            *v16 = *v6;
          }
          while ( v15 < image->num_channels );
        }
      }
      ++v6;
    }
    while ( (unsigned int)&v6[v5] < image->num_hp_qps );
  }
  return 0;
}


// ========================================================================
// r_INDEX_TABLE
// EA  : 0x82907240
// RVA : 0x00907240
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_INDEX_TABLE(jxr_image *image, rbitstream *str)
{
  char v4; // r31
  char v5; // r3
  __int64 v6; // r11
  signed int v7; // r31
  int v8; // r30
  __int64 v9; // r3

  if ( (image->header_flags1 & 4) == 0 )
    return 0;
  v4 = _jxr_rbitstream_uint8(str);
  v5 = _jxr_rbitstream_uint8(str);
  if ( v4 == 0 && v5 == 1 )
  {
    if ( (image->header_flags1 & 0x40) != 0 )
    {
      LODWORD(v6) = image->bands_present;
      HIDWORD(v6) = image->tile_columns * image->tile_rows;
      if ( (_DWORD)v6 == 4 )
        v7 = 4 * HIDWORD(v6);
      else
        v7 = (4 - v6) * HIDWORD(v6);
    }
    else
    {
      HIDWORD(v6) = image->tile_rows;
      v7 = image->tile_columns * HIDWORD(v6);
    }
    LODWORD(v6) = v7;
    image->tile_index_table_length = v6;
    image->tile_index_table = (__int64 *)_jxr_temp_calloc(image, count: v7, size: 8u);
    if ( v7 > 0 )
    {
      v8 = 0;
      do
      {
        LODWORD(v9) = _jxr_rbitstream_intVLW(str);
        --v7;
        image->tile_index_table[v8++] = v9;
      }
      while ( v7 != 0 );
    }
    return 0;
  }
  return -1;
}


// ========================================================================
// r_TILE_stripe
// EA  : 0x82907338
// RVA : 0x00907338
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_TILE_stripe(jxr_image *image, rbitstream *str, unsigned __int64 a3)
{
  char *v5; // r3
  int v7; // r3
  int v8; // r30
  unsigned int tile_rows; // r10
  unsigned int v10; // r11
  unsigned int tile_columns; // r10
  unsigned int v12; // r11
  unsigned int bands_present; // r11
  int v14; // r23
  unsigned int v15; // r26
  int i; // r27
  unsigned int v17; // r29
  int v18; // r28
  unsigned int v19; // r26
  int j; // r27
  unsigned int v21; // r29
  int v22; // r28
  __int64 v23; // r4
  unsigned int v24; // r25
  int k; // r27
  unsigned int v26; // r29
  int v27; // r28
  unsigned int v28; // r27
  int m; // r26
  unsigned int v30; // r29
  int v31; // r28
  __int64 v32; // r4

  if ( image->tile_quant == nullptr )
  {
    v5 = _jxr_temp_calloc(image, count: image->tile_columns * image->tile_rows, size: 0x44Cu);
    image->tile_quant = (jxr_tile_qp *)v5;
    if ( v5 == nullptr )
      return -6;
  }
  if ( (image->header_flags1 & 0x40) == 0 )
  {
    while ( 1 )
    {
      v7 = _jxr_r_TILE_SPATIAL_stripe(image, str, tx: image->stripe_tx, ty: image->stripe_ty);
      v8 = v7;
      if ( v7 >= 0 )
      {
        if ( v7 == 0 )
          return 0;
      }
      else if ( v7 == -256 )
      {
        tile_rows = image->tile_rows;
        v10 = image->stripe_ty + 1;
        image->stripe_tx = 0;
        image->stripe_ty = v10;
        if ( v10 < tile_rows )
          return 0;
        v8 = -256;
        goto RET;
      }
      tile_columns = image->tile_columns;
      v12 = image->stripe_tx + 1;
      image->stripe_tx = v12;
      if ( v12 >= tile_columns )
        goto RET;
    }
  }
  if ( image->freq_buffered_flag == 0 )
  {
    bands_present = image->bands_present;
    v14 = 0;
    if ( bands_present <= 3 )
    {
      if ( bands_present == 1 )
      {
        v14 = 3;
      }
      else if ( bands_present == 2 )
      {
        v14 = 2;
      }
      else if ( image->bands_present != 0 )
      {
        v14 = 1;
      }
      else
      {
        v14 = 4;
      }
    }
    v15 = 0;
    for ( i = 0; v15 < image->tile_rows; ++v15 )
    {
      v17 = 0;
      if ( image->tile_columns != 0 )
      {
        v18 = i * v14;
        do
        {
          _jxr_rbitstream_seek(
            str: (rbitstream *)HIDWORD(image->tile_index_table[v18]),
            a2: image->tile_index_table[v18],
            off: a3);
          v8 = _jxr_r_TILE_DC(image, str, tx: v17, ty: v15);
          if ( v8 < 0 )
            goto RET;
          ++v17;
          ++i;
          v18 += v14;
        }
        while ( v17 < image->tile_columns );
      }
    }
    if ( v14 > 1 )
    {
      v19 = 0;
      for ( j = 0; v19 < image->tile_rows; ++v19 )
      {
        v21 = 0;
        if ( image->tile_columns != 0 )
        {
          v22 = j * v14;
          do
          {
            v23 = image->tile_index_table[v22 + 1];
            _jxr_rbitstream_seek(str: (rbitstream *)HIDWORD(v23), a2: v23, off: a3);
            v8 = _jxr_r_TILE_LP(image, str, tx: v21, ty: v19);
            if ( v8 < 0 )
              goto RET;
            ++v21;
            ++j;
            v22 += v14;
          }
          while ( v21 < image->tile_columns );
        }
      }
    }
    if ( v14 > 2 )
    {
      v24 = 0;
      for ( k = 0; v24 < image->tile_rows; ++v24 )
      {
        v26 = 0;
        if ( image->tile_columns != 0 )
        {
          v27 = k * v14 + 2;
          do
          {
            _jxr_rbitstream_seek(
              str: (rbitstream *)HIDWORD(image->tile_index_table[v27]),
              a2: image->tile_index_table[v27],
              off: a3);
            v8 = _jxr_r_TILE_HP(image, str, tx: v26, ty: v24);
            if ( v8 < 0 )
              goto RET;
            ++v26;
            ++k;
            v27 += v14;
          }
          while ( v26 < image->tile_columns );
        }
      }
    }
    if ( v14 > 3 )
    {
      v28 = 0;
      for ( m = 0; v28 < image->tile_rows; ++v28 )
      {
        v30 = 0;
        if ( image->tile_columns != 0 )
        {
          v31 = m * v14 + 3;
          do
          {
            v32 = image->tile_index_table[v31];
            if ( (int)v32 < 0 )
            {
              _jxr_r_TILE_FLEXBITS_ESCAPE(image, tx: v30, ty: v28);
            }
            else
            {
              _jxr_rbitstream_seek(str, a2: v32, off: a3);
              v8 = _jxr_r_TILE_FLEXBITS(image, str, tx: v30, ty: v28);
              if ( v8 < 0 )
                goto RET;
            }
            ++v30;
            ++m;
            v31 += v14;
          }
          while ( v30 < image->tile_columns );
        }
      }
    }
    image->output_sent = 0;
    image->freq_buffered_flag = 1;
  }
  v8 = _jxr_frequency_mode_render_stripe(image);
  if ( v8 == 0 )
    return 0;
RET:
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)image);
  image->tile_quant = nullptr;
  return v8;
}


// ========================================================================
// ?_jxr_r_TILE_HEADER_DC@@YAXPAUjxr_image@@PAUrbitstream@@HII@Z
// EA  : 0x829076F8
// RVA : 0x009076F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall _jxr_r_TILE_HEADER_DC(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty)
{
  jxr_tile_qp *v8; // r11

  if ( (*((_DWORD *)image + 26) & 0x40000000) == 0 )
  {
    _jxr_r_DC_QP(image, str);
    v8 = &image->tile_quant[image->tile_columns * ty + tx];
    *(_DWORD *)v8->dc_quant_ch = *(_DWORD *)image->dc_quant_ch;
    *(_DWORD *)&v8->dc_quant_ch[4] = *(_DWORD *)&image->dc_quant_ch[4];
    *(_DWORD *)&v8->dc_quant_ch[8] = *(_DWORD *)&image->dc_quant_ch[8];
    *(_DWORD *)&v8->dc_quant_ch[12] = *(_DWORD *)&image->dc_quant_ch[12];
  }
}


// ========================================================================
// ?_jxr_r_TILE_HEADER_LOWPASS@@YAXPAUjxr_image@@PAUrbitstream@@HII@Z
// EA  : 0x82907768
// RVA : 0x00907768
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall _jxr_r_TILE_HEADER_LOWPASS(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty)
{
  int v9; // r3
  int num_channels; // r10
  int v11; // r11
  unsigned __int8 *dc_quant_ch; // r9
  int v13; // r10
  unsigned __int8 v14; // r5
  char *v15; // r8

  if ( (*((_DWORD *)image + 26) & 0x10000000) == 0 )
  {
    v9 = _jxr_rbitstream_uint1(str);
    *((_DWORD *)image + 26) = (v9 << 29) & 0x20000000 | *((_DWORD *)image + 26) & 0xDFFFFFFF;
    if ( ((v9 << 29) & 0x20000000) != 0 )
    {
      num_channels = image->num_channels;
      v11 = 0;
      image->num_lp_qps = 1;
      if ( num_channels != 0 )
      {
        dc_quant_ch = image->dc_quant_ch;
        v13 = 0;
        do
        {
          image->lp_quant_ch[v13][0] = dc_quant_ch[v11];
          v14 = dc_quant_ch[v11++];
          v15 = (char *)&image->tile_quant[image->tile_columns * ty + tx] + v13 * 16;
          ++v13;
          v15[588] = v14;
        }
        while ( v11 < image->num_channels );
      }
    }
    else
    {
      image->num_lp_qps = (unsigned __int8)_jxr_rbitstream_uint4(str) + 1;
      _jxr_r_LP_QP(image, str);
      memcpy(
        Dst: image->tile_quant[image->tile_columns * ty + tx].lp_quant_ch,
        Src: image->lp_quant_ch,
        Size: sizeof(image->tile_quant[image->tile_columns * ty + tx].lp_quant_ch));
    }
  }
}


// ========================================================================
// ?_jxr_r_TILE_HEADER_HIGHPASS@@YAXPAUjxr_image@@PAUrbitstream@@HII@Z
// EA  : 0x82907870
// RVA : 0x00907870
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall _jxr_r_TILE_HEADER_HIGHPASS(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty)
{
  int v9; // r3
  int v10; // r29
  int num_channels; // r10
  unsigned __int8 *v12; // r31

  if ( (*((_DWORD *)image + 26) & 0x4000000) == 0 )
  {
    v9 = _jxr_rbitstream_uint1(str);
    *((_DWORD *)image + 26) = (v9 << 27) & 0x8000000 | *((_DWORD *)image + 26) & 0xF7FFFFFF;
    if ( ((v9 << 27) & 0x8000000) != 0 )
    {
      v10 = 0;
      num_channels = image->num_channels;
      image->num_hp_qps = image->num_lp_qps;
      if ( num_channels != 0 )
      {
        v12 = image->lp_quant_ch[0];
        do
        {
          *((_OWORD *)v12 + 16) = *(_OWORD *)v12;
          *(_OWORD *)&image->tile_quant[image->tile_columns * ty - 1 + tx].channel[6].hp_qp[(unsigned int)v12
                                                                                          + 15
                                                                                          - (_DWORD)image
                                                                                          + 8] = *(_OWORD *)v12;
          ++v10;
          v12 += 16;
        }
        while ( v10 < image->num_channels );
      }
    }
    else
    {
      image->num_hp_qps = (unsigned __int8)_jxr_rbitstream_uint4(str) + 1;
      r_HP_QP(image, str);
      memcpy(
        Dst: image->tile_quant[image->tile_columns * ty + tx].hp_quant_ch,
        Src: image->hp_quant_ch,
        Size: sizeof(image->tile_quant[image->tile_columns * ty + tx].hp_quant_ch));
    }
  }
}


// ========================================================================
// ?_jxr_DECODE_QP_INDEX@@YAIPAUrbitstream@@I@Z
// EA  : 0x82907988
// RVA : 0x00907988
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

unsigned int __fastcall _jxr_DECODE_QP_INDEX(rbitstream *str, unsigned int index_count)
{
  unsigned int result; // r3

  result = _jxr_rbitstream_uint1(str);
  if ( result != 0 )
    return _jxr_rbitstream_uintN(str, N: bits_per_qp_index[index_count]) + 1;
  return result;
}


// ========================================================================
// r_REFINE_CBP
// EA  : 0x829079E8
// RVA : 0x009079E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_REFINE_CBP(rbitstream *str, int num)
{
  if ( (unsigned int)(num - 1) > 3 )
    return 0;
  switch ( num )
  {
    case 2:
      if ( _jxr_rbitstream_uint1(str) )
      {
        if ( _jxr_rbitstream_uint1(str) )
          return !_jxr_rbitstream_uint1(str) ? 10 : 12;
        else
          return !_jxr_rbitstream_uint1(str) ? 6 : 9;
      }
      else
      {
        return !_jxr_rbitstream_uint1(str) ? 3 : 5;
      }
    case 3:
      return (1 << _jxr_rbitstream_uint2(str)) ^ 0xF;
    case 1:
      return 1 << _jxr_rbitstream_uint2(str);
    default:
      return 15;
  }
}


// ========================================================================
// r_DECODE_FIRST_INDEX
// EA  : 0x82907B40
// RVA : 0x00907B40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_DECODE_FIRST_INDEX(jxr_image *image, rbitstream *str, unsigned int chroma_flag, int band)
{
  int v6; // r27
  int result; // r3
  int *v8; // r29
  unsigned int v9; // r11
  const char *v10; // r6
  const unsigned __int8 *v11; // r5
  char v12; // r4
  int v13; // r7
  int v14; // r8
  _DWORD v15[64]; // [sp+50h] [-100h] BYREF

  v6 = 0;
  if ( band == 1 )
  {
    v6 = chroma_flag == 0 ? 2 : 9;
  }
  else if ( band == 2 )
  {
    v6 = ((_cntlzw(chroma_flag) & 0x20) == 0) + 16;
  }
  result = 0;
  v8 = &image->user_flags + 5 * v6;
  v9 = v8[177];
  if ( v9 <= 4 )
  {
    switch ( v9 )
    {
      case 1u:
        v10 = c1v;
        v11 = c1b;
        v12 = 6;
LABEL_20:
        result = _jxr_rbitstream_intE(str, code_size: v12, codeb: v11, codev: v10);
        goto LABEL_21;
      case 2u:
        v10 = c2v;
        v11 = c2b;
LABEL_19:
        v12 = 7;
        goto LABEL_20;
      case 3u:
        v10 = c3v;
        v11 = c3b;
        goto LABEL_19;
      default:
        break;
    }
    if ( v9 != 0 )
    {
      if ( !_jxr_rbitstream_uint1(str) )
      {
        v10 = c4v;
        v11 = c4b;
        goto LABEL_19;
      }
      result = 1;
    }
    else
    {
      if ( !_jxr_rbitstream_uint1(str) )
      {
        v10 = c0v;
        v11 = c0b;
        v12 = 6;
        goto LABEL_20;
      }
      result = 7;
    }
  }
LABEL_21:
  v13 = v8[179];
  v15[5] = 0;
  v15[6] = 0;
  v15[8] = 2;
  v15[12] = 2;
  v15[13] = 2;
  v15[27] = 2;
  v15[10] = 0;
  v15[11] = 0;
  v15[17] = 0;
  v15[20] = 0;
  v15[21] = 0;
  v15[26] = 0;
  memset(&v15[28], 0, 16);
  v15[33] = 0;
  v15[36] = 0;
  v15[38] = 0;
  v15[41] = 0;
  v15[18] = -2;
  v15[22] = -2;
  v15[32] = -2;
  v15[40] = -2;
  v15[44] = -2;
  v15[46] = -2;
  v15[47] = -2;
  v15[0] = 1;
  v15[1] = 1;
  v15[2] = 1;
  v15[3] = 1;
  v14 = v8[178];
  v15[4] = 1;
  v15[7] = -1;
  v15[9] = 1;
  memset(&v15[14], 255, 12);
  v15[19] = -1;
  v15[23] = -1;
  v15[24] = -1;
  v15[25] = 1;
  v15[34] = 1;
  v15[35] = 1;
  v15[37] = 1;
  v15[39] = 1;
  v15[42] = -1;
  v15[43] = -1;
  v15[45] = -1;
  v8[176] += v15[12 * v13 + result];
  image->vlc_table[v6].discriminant += v15[12 * v14 + result];
  return result;
}


// ========================================================================
// r_DECODE_INDEX
// EA  : 0x82907DB0
// RVA : 0x00907DB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_DECODE_INDEX(
        jxr_image *image,
        rbitstream *str,
        int location,
        int chroma_flag,
        int band,
        unsigned int context)
{
  int v8; // r26
  BOOL v9; // r11
  BOOL v10; // r11
  int v11; // r31
  int *v13; // r28
  unsigned int v14; // r11
  unsigned __int8 v15; // r3
  unsigned __int8 v16; // r3
  int v17; // r10
  int v18; // r9
  int v19; // r10
  _DWORD v20[36]; // [sp+50h] [-90h] BYREF

  v8 = 0;
  if ( band == 1 )
  {
    v10 = (_cntlzw(context) & 0x20) == 0;
    v8 = v10 + 10;
    if ( chroma_flag == 0 )
      v8 = v10 + 7;
  }
  else if ( band == 2 )
  {
    v9 = (_cntlzw(context) & 0x20) == 0;
    if ( chroma_flag != 0 )
      v8 = v9 + 18;
    else
      v8 = v9 + 14;
  }
  v11 = 0;
  if ( location > 15 )
    return _jxr_rbitstream_uint1(str);
  if ( location != 15 )
  {
    v13 = &image->user_flags + 5 * v8;
    v14 = v13[177];
    if ( v14 > 3 )
    {
LABEL_52:
      v17 = v13[179];
      v20[6] = -2;
      v20[16] = -2;
      v20[9] = 2;
      v18 = v13[178];
      v20[0] = -1;
      v20[12] = -1;
      v20[13] = -1;
      v20[1] = 1;
      v20[2] = 1;
      v20[3] = 1;
      v20[4] = 0;
      v20[5] = 1;
      v20[7] = 0;
      v20[8] = 0;
      v20[10] = 0;
      v20[11] = 0;
      v20[14] = 0;
      v20[15] = 1;
      v20[17] = 0;
      v19 = v20[6 * v17 + v11] + v13[176];
      image->vlc_table[v8].discriminant += v20[6 * v18 + v11];
      v13[176] = v19;
      return v11;
    }
    if ( v14 == 1 )
    {
      v15 = _jxr_rbitstream_uint2(str);
      if ( v15 > 3u )
        goto LABEL_52;
      if ( v15 != 0 )
      {
        if ( v15 != 1 )
        {
          if ( v15 != 2 )
            goto LABEL_50;
          goto LABEL_42;
        }
        goto LABEL_33;
      }
      if ( !_jxr_rbitstream_uint1(str) )
      {
        if ( _jxr_rbitstream_uint1(str) )
        {
          v11 = 3;
          goto LABEL_52;
        }
        goto LABEL_27;
      }
LABEL_44:
      v11 = 5;
      goto LABEL_52;
    }
    if ( v14 == 2 )
    {
      v16 = _jxr_rbitstream_uint2(str);
      if ( v16 > 3u )
        goto LABEL_52;
      if ( v16 != 0 )
      {
        if ( v16 != 1 )
        {
          if ( v16 != 2 )
            goto LABEL_50;
          goto LABEL_46;
        }
LABEL_42:
        v11 = 2;
        goto LABEL_52;
      }
      if ( _jxr_rbitstream_uint1(str) )
        goto LABEL_44;
LABEL_51:
      v11 = _jxr_rbitstream_uint1(str);
      goto LABEL_52;
    }
    if ( v14 != 0 )
    {
      if ( _jxr_rbitstream_uint1(str) )
        goto LABEL_46;
      if ( _jxr_rbitstream_uint1(str) )
        goto LABEL_42;
      if ( _jxr_rbitstream_uint1(str) )
        goto LABEL_44;
      if ( !_jxr_rbitstream_uint1(str) )
        goto LABEL_51;
    }
    else
    {
      if ( _jxr_rbitstream_uint1(str) )
      {
LABEL_33:
        v11 = 0;
        goto LABEL_52;
      }
      if ( !_jxr_rbitstream_uint1(str) )
      {
        if ( _jxr_rbitstream_uint1(str) )
          goto LABEL_42;
        if ( _jxr_rbitstream_uint1(str) )
          goto LABEL_44;
        if ( !_jxr_rbitstream_uint1(str) )
        {
LABEL_27:
          v11 = 1;
          goto LABEL_52;
        }
LABEL_46:
        v11 = 3;
        goto LABEL_52;
      }
    }
LABEL_50:
    v11 = 4;
    goto LABEL_52;
  }
  if ( !_jxr_rbitstream_uint1(str) )
    return 0;
  if ( _jxr_rbitstream_uint1(str) )
    return !_jxr_rbitstream_uint1(str) ? 1 : 3;
  return 2;
}


// ========================================================================
// r_DECODE_RUN
// EA  : 0x829080F0
// RVA : 0x009080F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_DECODE_RUN(rbitstream *image, rbitstream *str, int max_run)
{
  int v5; // r31
  int v7; // r9
  int v8; // r11
  int v9; // r4

  v5 = 0;
  if ( (int)str >= 5 )
  {
    if ( _jxr_rbitstream_uint1(str: image) )
    {
      v7 = 0;
    }
    else if ( _jxr_rbitstream_uint1(str: image) )
    {
      v7 = 1;
    }
    else if ( _jxr_rbitstream_uint1(str: image) )
    {
      v7 = 2;
    }
    else
    {
      v7 = ((_cntlzw(_jxr_rbitstream_uint1(str: image)) & 0x20) == 0) + 3;
    }
    v8 = 5 * RunBin[(_DWORD)str] + v7;
    v9 = RunFixedLen[v8];
    v5 = Remap[v8];
    if ( v9 != 0 )
      v5 += _jxr_rbitstream_uintN(str: image, N: v9);
  }
  else if ( (unsigned int)&str[-1].mark_stream_position + 3 <= 3 )
  {
    if ( str == (rbitstream *)2 )
      return ((_cntlzw(_jxr_rbitstream_uint1(str: image)) & 0x20) != 0) + 1;
    if ( str == (rbitstream *)3 )
    {
      if ( !_jxr_rbitstream_uint1(str: image) )
        return ((_cntlzw(_jxr_rbitstream_uint1(str: image)) & 0x20) != 0) + 2;
      return 1;
    }
    if ( str == (rbitstream *)1 || _jxr_rbitstream_uint1(str: image) )
      return 1;
    if ( _jxr_rbitstream_uint1(str: image) )
      return 2;
    else
      return ((_cntlzw(_jxr_rbitstream_uint1(str: image)) & 0x20) != 0) + 3;
  }
  return v5;
}


// ========================================================================
// r_PredCBP
// EA  : 0x82908298
// RVA : 0x00908298
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall r_PredCBP(
        jxr_image *image,
        int *diff_cbp,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int use_clr_fmt; // r11
  int v12; // r26
  unsigned int *p_num_lp_qps; // r25
  unsigned int v14; // r24
  int v15; // r3
  unsigned int v16; // r26
  int v17; // r3

  if ( _jxr_InitContext(image, tx, ty, mx, my) != 0 )
    _jxr_InitializeCBPModel(image);
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 1 )
  {
    v16 = tx;
    image->strip[0].cur[image->tile_column_position[v16] + mx].hp_cbp = _jxr_PredCBP444(
                                                                          image,
                                                                          diff_cbp,
                                                                          channel: 0,
                                                                          tx,
                                                                          mx,
                                                                          my);
    image->strip[1].cur[image->tile_column_position[v16] + mx].hp_cbp = _jxr_PredCBP420(
                                                                          image,
                                                                          diff_cbp,
                                                                          channel: 1,
                                                                          tx,
                                                                          mx,
                                                                          my);
    v17 = _jxr_PredCBP420(image, diff_cbp, channel: 2, tx, mx, my);
    goto LABEL_11;
  }
  if ( use_clr_fmt == 2 )
  {
    v16 = tx;
    image->strip[0].cur[image->tile_column_position[v16] + mx].hp_cbp = _jxr_PredCBP444(
                                                                          image,
                                                                          diff_cbp,
                                                                          channel: 0,
                                                                          tx,
                                                                          mx,
                                                                          my);
    image->strip[1].cur[image->tile_column_position[v16] + mx].hp_cbp = _jxr_PredCBP422(
                                                                          image,
                                                                          diff_cbp,
                                                                          channel: 1,
                                                                          tx,
                                                                          mx,
                                                                          my);
    v17 = _jxr_PredCBP422(image, diff_cbp, channel: 2, tx, mx, my);
LABEL_11:
    image->strip[2].cur[image->tile_column_position[v16] + mx].hp_cbp = v17;
    return;
  }
  v12 = 0;
  if ( image->num_channels != 0 )
  {
    p_num_lp_qps = &image->num_lp_qps;
    do
    {
      p_num_lp_qps += 7;
      v14 = *p_num_lp_qps;
      v15 = _jxr_PredCBP444(image, diff_cbp, channel: v12++, tx, mx, my);
      *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + v14 + 12) = v15;
    }
    while ( v12 < image->num_channels );
  }
}


// ========================================================================
// r_DECODE_FLEX
// EA  : 0x829084A0
// RVA : 0x009084A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall r_DECODE_FLEX(
        jxr_image *image,
        rbitstream *str,
        unsigned int tx,
        unsigned int mx,
        int ch,
        unsigned int block,
        unsigned int k,
        int flexbits)
{
  unsigned int v8; // r26
  int v10; // r24
  unsigned int v13; // r25
  int v14; // r30
  unsigned int v15; // r3
  unsigned int v16; // r29
  int v17; // r11

  v8 = tx;
  v10 = 28 * (ch + 5);
  v13 = 4 * (15 * block + k + 16);
  v14 = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v10))
                  + v13);
  v15 = _jxr_rbitstream_uintN(str, N: flexbits);
  v16 = v15;
  if ( v14 <= 0 )
  {
    if ( v14 >= 0 )
    {
      if ( v15 != 0 && _jxr_rbitstream_uint1(str) )
        v17 = -v16 << (*((_DWORD *)image + 9) >> 28);
      else
        v17 = v16 << (*((_DWORD *)image + 9) >> 28);
    }
    else
    {
      v17 = v14 - (v15 << (*((_DWORD *)image + 9) >> 28));
    }
  }
  else
  {
    v17 = (v15 << (*((_DWORD *)image + 9) >> 28)) + v14;
  }
  if ( (image->user_flags & 2) == 0 )
    *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v8] + mx) + *(int *)((char *)&image->user_flags + v10))
              + v13) = v17;
}


// ========================================================================
// r_BLOCK_FLEXBITS
// EA  : 0x829085A8
// RVA : 0x009085A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall r_BLOCK_FLEXBITS(
        jxr_image *image,
        rbitstream *str,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my,
        unsigned int ch,
        unsigned int bl,
        unsigned int model_bits)
{
  unsigned int v10; // r11
  int v13; // r20
  unsigned int v14; // r11
  int v15; // r21
  unsigned int v16; // r26
  unsigned int v17; // r27
  unsigned int v18; // r23
  _DWORD *v19; // r24
  int v20; // r28
  int v21; // r30
  unsigned int v22; // r3
  unsigned int v23; // r29
  int v24; // r11
  _DWORD v25[43]; // [sp+54h] [-ACh] BYREF

  v10 = *((_DWORD *)image + 9);
  v25[0] = 4;
  v25[1] = 8;
  v25[2] = 12;
  v25[3] = 1;
  v25[4] = 5;
  v25[5] = 9;
  v25[6] = 13;
  v25[7] = 2;
  v25[8] = 6;
  v13 = 15;
  v25[9] = 10;
  v14 = v10 >> 28;
  v25[14] = 15;
  v25[10] = 14;
  v25[11] = 3;
  v25[12] = 7;
  v25[13] = 11;
  if ( v14 <= ch )
  {
    v15 = ch - v14;
    if ( ch != v14 )
    {
      v16 = 28 * (mx + 5);
      v17 = tx;
      v18 = 15 * my + 16;
      v19 = v25;
      do
      {
        v20 = 4 * (v18 + *v19 - 1);
        v21 = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v17] + ty)
                                    + *(int *)((char *)&image->user_flags + v16))
                        + v20);
        v22 = _jxr_rbitstream_uintN(str, N: v15);
        v23 = v22;
        if ( v21 <= 0 )
        {
          if ( v21 >= 0 )
          {
            if ( v22 != 0 && _jxr_rbitstream_uint1(str) )
              v24 = -v23 << (*((_DWORD *)image + 9) >> 28);
            else
              v24 = v23 << (*((_DWORD *)image + 9) >> 28);
          }
          else
          {
            v24 = v21 - (v22 << (*((_DWORD *)image + 9) >> 28));
          }
        }
        else
        {
          v24 = (v22 << (*((_DWORD *)image + 9) >> 28)) + v21;
        }
        if ( (image->user_flags & 2) == 0 )
          *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v17] + ty)
                                + *(int *)((char *)&image->user_flags + v16))
                    + v20) = v24;
        --v13;
        ++v19;
      }
      while ( v13 != 0 );
    }
  }
}


// ========================================================================
// r_calculate_mbhp_mode
// EA  : 0x82908760
// RVA : 0x00908760
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_calculate_mbhp_mode(jxr_image *image, int tx, int mx)
{
  int v3; // r11
  int *data; // r5
  signed int v5; // r10
  signed int v6; // r9
  int *v7; // r5
  int *v8; // r6
  int v9; // r7
  int v10; // r11
  int *v11; // r6
  int *v12; // r5
  unsigned int v13; // r8
  unsigned int v14; // r11
  unsigned int v15; // r6
  unsigned int v16; // r7
  int v17; // r4
  int result; // r3

  v3 = image->tile_column_position[tx] + mx;
  data = image->strip[0].cur[v3].data;
  v5 = abs32(data[3]) + abs32(data[2]) + abs32(data[1]);
  v6 = abs32(data[12]) + abs32(data[8]) + abs32(data[4]);
  if ( (unsigned int)image->use_clr_fmt - 1 > 3 )
    goto LABEL_9;
  if ( image->use_clr_fmt == 1 )
  {
    v7 = image->strip[2].cur[v3].data;
    v8 = image->strip[1].cur[v3].data;
    v9 = v7[2];
    v10 = v8[2];
    goto LABEL_7;
  }
  if ( image->use_clr_fmt != 2 )
  {
    v7 = image->strip[2].cur[v3].data;
    v8 = image->strip[1].cur[v3].data;
    v9 = v7[4];
    v10 = v8[4];
LABEL_7:
    v17 = v8[1];
    v16 = abs32(v9);
    v14 = abs32(v10);
    v15 = abs32(v7[1]);
    v13 = abs32(v17);
    goto LABEL_8;
  }
  v11 = image->strip[1].cur[v3].data;
  v12 = image->strip[2].cur[v3].data;
  v13 = abs32(v11[5]) + abs32(v11[1]) + abs32(v12[5]);
  v14 = abs32(v11[6]) + abs32(v11[2]) + abs32(v12[6]);
  v15 = abs32(v12[1]);
  v16 = abs32(v12[2]);
LABEL_8:
  v5 += v13 + v15;
  v6 += v14 + v16;
LABEL_9:
  if ( 4 * v5 < v6 )
    return 0;
  result = 1;
  if ( 4 * v6 >= v5 )
    return 2;
  return result;
}


// ========================================================================
// ?_jxr_propagate_hp_predictions@@YAXPAUjxr_image@@HIIH@Z
// EA  : 0x82908968
// RVA : 0x00908968
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall _jxr_propagate_hp_predictions(
        jxr_image *image,
        int ch,
        unsigned int tx,
        unsigned int mx,
        int mbhp_pred_mode)
{
  char v5; // r30
  int v6; // r11
  int i; // ctr
  int v8; // r10
  int v9; // r31
  int v10; // r9
  int v11; // r10
  unsigned int v12; // r10
  int v13; // r9
  int v14; // ctr
  int v15; // r11
  int v16; // r31
  int v17; // r8
  int v18; // r8
  int use_clr_fmt; // r11
  unsigned int v20; // r10
  int v21; // r11
  int n; // ctr
  int *v23; // r5
  int *v24; // r5
  int *v25; // r5
  int *v26; // r5
  int *v27; // r5
  int v28; // r8
  unsigned int v29; // r10
  int v30; // r11
  int m; // ctr
  int *v32; // r5
  int *v33; // r5
  int *v34; // r5
  int *v35; // r5
  int *v36; // r5
  int v37; // r8
  unsigned int v38; // r10
  int v39; // r11
  int k; // ctr
  int *v41; // r5
  int *v42; // r5
  int *v43; // r5
  int *v44; // r9
  int *v45; // r9
  int v46; // r8
  unsigned int v47; // r10
  int v48; // r11
  int j; // ctr
  int *v50; // r5
  int *v51; // r5
  int *v52; // r5
  int *v53; // r5
  int *v54; // r5
  int v55; // r8

  if ( mbhp_pred_mode != 0 )
  {
    if ( mbhp_pred_mode == 1 )
    {
      v12 = tx;
      v13 = 28 * (ch + 5);
      v14 = 12;
      v15 = 240;
      do
      {
        v16 = v15
            + *(_DWORD *)(84 * (image->tile_column_position[v12] + mx) + *(int *)((char *)&image->user_flags + v13));
        *(_DWORD *)(v16 + 64) += *(_DWORD *)(v16 - 176);
        v17 = *(_DWORD *)(84 * (image->tile_column_position[v12] + mx) + *(int *)((char *)&image->user_flags + v13))
            + v15;
        *(_DWORD *)(v17 + 68) += *(_DWORD *)(v17 - 172);
        v18 = *(_DWORD *)(84 * (image->tile_column_position[v12] + mx) + *(int *)((char *)&image->user_flags + v13))
            + v15;
        v15 += 60;
        *(_DWORD *)(v18 + 72) += *(_DWORD *)(v18 - 168);
        --v14;
      }
      while ( v14 != 0 );
    }
  }
  else
  {
    v5 = 1;
    v6 = 60;
    for ( i = 15; i != 0; --i )
    {
      if ( (v5 & 3) != 0 )
      {
        v8 = 28 * (ch + 5);
        v9 = *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v8)) + v6;
        *(_DWORD *)(v9 + 76) += *(_DWORD *)(v9 + 16);
        v10 = *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v8)) + v6;
        *(_DWORD *)(v10 + 92) += *(_DWORD *)(v10 + 32);
        v11 = *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v8)) + v6;
        *(_DWORD *)(v11 + 108) += *(_DWORD *)(v11 + 48);
      }
      ++v5;
      v6 += 60;
    }
  }
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 1 )
  {
    if ( mbhp_pred_mode != 0 )
    {
      if ( mbhp_pred_mode == 1 )
      {
        v47 = tx;
        v48 = 30;
        for ( j = 2; j != 0; --j )
        {
          v50 = &image->strip[1].cur[image->tile_column_position[v47] + mx].data[v48];
          v50[16] += *(v50 - 14);
          v51 = &image->strip[2].cur[image->tile_column_position[v47] + mx].data[v48];
          v51[16] += *(v51 - 14);
          v52 = &image->strip[1].cur[image->tile_column_position[v47] + mx].data[v48];
          v52[17] += *(v52 - 13);
          v53 = &image->strip[2].cur[image->tile_column_position[v47] + mx].data[v48];
          v53[17] += *(v53 - 13);
          v54 = &image->strip[1].cur[image->tile_column_position[v47] + mx].data[v48];
          v54[18] += *(v54 - 12);
          v55 = image->tile_column_position[v47] + mx;
          image->strip[2].cur[v55].data[v48 + 18] += image->strip[2].cur[v55].data[v48 - 12];
          v48 += 15;
        }
      }
    }
    else
    {
      v38 = tx;
      v39 = 15;
      for ( k = 2; k != 0; --k )
      {
        v41 = &image->strip[1].cur[image->tile_column_position[v38] + mx].data[v39];
        v41[19] += v41[4];
        v42 = &image->strip[2].cur[image->tile_column_position[v38] + mx].data[v39];
        v42[19] += v42[4];
        v43 = &image->strip[1].cur[image->tile_column_position[v38] + mx].data[v39];
        v43[23] += v43[8];
        v44 = &image->strip[2].cur[image->tile_column_position[v38] + mx].data[v39];
        v44[23] += v44[8];
        v45 = &image->strip[1].cur[image->tile_column_position[v38] + mx].data[v39];
        v45[27] += v45[12];
        v46 = image->tile_column_position[v38] + mx;
        image->strip[2].cur[v46].data[v39 + 27] += image->strip[2].cur[v46].data[v39 + 12];
        v39 += 30;
      }
    }
  }
  else if ( use_clr_fmt == 2 )
  {
    if ( mbhp_pred_mode != 0 )
    {
      if ( mbhp_pred_mode == 1 )
      {
        v29 = tx;
        v30 = 30;
        for ( m = 6; m != 0; --m )
        {
          v32 = &image->strip[1].cur[image->tile_column_position[v29] + mx].data[v30];
          v32[16] += *(v32 - 14);
          v33 = &image->strip[2].cur[image->tile_column_position[v29] + mx].data[v30];
          v33[16] += *(v33 - 14);
          v34 = &image->strip[1].cur[image->tile_column_position[v29] + mx].data[v30];
          v34[17] += *(v34 - 13);
          v35 = &image->strip[2].cur[image->tile_column_position[v29] + mx].data[v30];
          v35[17] += *(v35 - 13);
          v36 = &image->strip[1].cur[image->tile_column_position[v29] + mx].data[v30];
          v36[18] += *(v36 - 12);
          v37 = image->tile_column_position[v29] + mx;
          image->strip[2].cur[v37].data[v30 + 18] += image->strip[2].cur[v37].data[v30 - 12];
          v30 += 15;
        }
      }
    }
    else
    {
      v20 = tx;
      v21 = 15;
      for ( n = 4; n != 0; --n )
      {
        v23 = &image->strip[1].cur[image->tile_column_position[v20] + mx].data[v21];
        v23[19] += v23[4];
        v24 = &image->strip[2].cur[image->tile_column_position[v20] + mx].data[v21];
        v24[19] += v24[4];
        v25 = &image->strip[1].cur[image->tile_column_position[v20] + mx].data[v21];
        v25[23] += v25[8];
        v26 = &image->strip[2].cur[image->tile_column_position[v20] + mx].data[v21];
        v26[23] += v26[8];
        v27 = &image->strip[1].cur[image->tile_column_position[v20] + mx].data[v21];
        v27[27] += v27[12];
        v28 = image->tile_column_position[v20] + mx;
        image->strip[2].cur[v28].data[v21 + 27] += image->strip[2].cur[v28].data[v21 + 12];
        v21 += 30;
      }
    }
  }
}


// ========================================================================
// get_is_dc_yuv
// EA  : 0x82909098
// RVA : 0x00909098
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall get_is_dc_yuv(rbitstream *str)
{
  unsigned int v3; // r11

  if ( _jxr_rbitstream_uint1(str) )
    return !_jxr_rbitstream_uint1(str) ? 0 : 4;
  v3 = (unsigned __int8)_jxr_rbitstream_uint2(str);
  if ( v3 > 3 )
    return -1;
  if ( v3 == 1 )
    return 1;
  if ( v3 == 2 )
    return 5;
  if ( v3 != 0 )
    return 7;
  if ( _jxr_rbitstream_uint1(str) )
    return 3;
  if ( _jxr_rbitstream_uint1(str) )
    return 2;
  return 6;
}


// ========================================================================
// get_num_cbp
// EA  : 0x829091D8
// RVA : 0x009091D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall get_num_cbp(rbitstream *str, adaptive_vlc_s *vlc)
{
  int result; // r3

  if ( _jxr_rbitstream_uint1(str) )
    return 0;
  if ( vlc->table != 0 )
    return (unsigned __int8)_jxr_rbitstream_uint2(str) + 1;
  result = _jxr_rbitstream_uint1(str);
  if ( result != 1 )
  {
    if ( _jxr_rbitstream_uint1(str) )
      return 2;
    else
      return ((_cntlzw(_jxr_rbitstream_uint1(str) - 1) & 0x20) != 0) + 3;
  }
  return result;
}


// ========================================================================
// dec_cbp_yuv_lp1
// EA  : 0x82909280
// RVA : 0x00909280
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall dec_cbp_yuv_lp1(jxr_image *image, rbitstream *str)
{
  unsigned int use_clr_fmt; // r11

  use_clr_fmt = image->use_clr_fmt;
  if ( image->use_clr_fmt == 0 )
    return 0;
  if ( use_clr_fmt > 2 )
  {
    if ( use_clr_fmt == 3 )
      return _jxr_rbitstream_intE(str, code_size: 4, codeb: codeb, codev: codev);
    return 0;
  }
  if ( !_jxr_rbitstream_uint1(str) )
    return 0;
  if ( _jxr_rbitstream_uint1(str) )
    return ((_cntlzw(_jxr_rbitstream_uint1(str)) & 0x20) == 0) + 2;
  else
    return 1;
}


// ========================================================================
// ?jxr_read_stripe_bitstream@@YAHPAUjxr_image@@@Z
// EA  : 0x82909360
// RVA : 0x00909360
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall jxr_read_stripe_bitstream(jxr_image *image, int a2, unsigned __int64 a3)
{
  return r_TILE_stripe(image, str: &image->rbits, a3);
}


// ========================================================================
// r_image_plane_header
// EA  : 0x82909368
// RVA : 0x00909368
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_image_plane_header(jxr_image *image, rbitstream *str, int alpha)
{
  unsigned __int8 v5; // r3
  unsigned int use_clr_fmt; // r11
  char v7; // r3
  int v8; // r3
  int bands_present; // r10
  int v10; // r3
  int v11; // r3

  image->use_clr_fmt = _jxr_rbitstream_uint3(str);
  *((_DWORD *)image + 26) = (_jxr_rbitstream_uint1(str) << 31) | *((_DWORD *)image + 26) & 0x7FFFFFFF;
  v5 = _jxr_rbitstream_uint4(str);
  use_clr_fmt = image->use_clr_fmt;
  image->bands_present = v5;
  if ( use_clr_fmt <= 6 )
  {
    switch ( use_clr_fmt )
    {
      case 1u:
        _jxr_rbitstream_uint1(str);
        image->chroma_centering_x = _jxr_rbitstream_uint3(str);
        _jxr_rbitstream_uint1(str);
        image->chroma_centering_y = _jxr_rbitstream_uint3(str);
        image->num_channels = 3;
        break;
      case 2u:
        _jxr_rbitstream_uint1(str);
        image->chroma_centering_x = _jxr_rbitstream_uint3(str);
        _jxr_rbitstream_uint4(str);
        image->chroma_centering_y = 0;
        image->num_channels = 3;
        break;
      case 3u:
        _jxr_rbitstream_uint4(str);
        _jxr_rbitstream_uint4(str);
        image->num_channels = 3;
        break;
      case 4u:
        image->num_channels = 4;
        break;
      case 5u:
LABEL_31:
        break;
      default:
        if ( use_clr_fmt != 0 )
        {
          v7 = _jxr_rbitstream_uint4(str);
          if ( v7 == 15 )
          {
            image->num_channels = _jxr_rbitstream_uint12(str) + 16;
          }
          else
          {
            image->num_channels = v7 + 1;
            _jxr_rbitstream_uint4(str);
          }
        }
        else
        {
          image->num_channels = 1;
        }
        goto LABEL_31;
    }
  }
  switch ( image->header_flags_fmt & 0xF )
  {
    case 0:
    case 1:
    case 4:
    case 8:
    case 9:
    case 0xF:
      image->shift_bits = 0;
      break;
    case 2:
    case 3:
    case 6:
      image->shift_bits = _jxr_rbitstream_uint8(str);
      break;
    case 7:
      image->len_mantissa = _jxr_rbitstream_uint8(str);
      image->exp_bias = _jxr_rbitstream_uint8(str);
      break;
    default:
      break;
  }
  v8 = _jxr_rbitstream_uint1(str);
  *((_DWORD *)image + 26) = (v8 << 30) & 0x40000000 | *((_DWORD *)image + 26) & 0xBFFFFFFF;
  if ( ((v8 << 30) & 0x40000000) != 0 )
    _jxr_r_DC_QP(image, str);
  bands_present = image->bands_present;
  *((_DWORD *)image + 26) |= 0x14000000u;
  if ( bands_present != 3 )
  {
    _jxr_rbitstream_uint1(str);
    v10 = _jxr_rbitstream_uint1(str);
    *((_DWORD *)image + 26) = (v10 << 28) & 0x10000000 | *((_DWORD *)image + 26) & 0xEFFFFFFF;
    if ( ((v10 << 28) & 0x10000000) != 0 )
    {
      image->num_lp_qps = 1;
      _jxr_r_LP_QP(image, str);
    }
    if ( image->bands_present != 2 )
    {
      _jxr_rbitstream_uint1(str);
      v11 = _jxr_rbitstream_uint1(str);
      *((_DWORD *)image + 26) = (v11 << 26) & 0x4000000 | *((_DWORD *)image + 26) & 0xFBFFFFFF;
      if ( ((v11 << 26) & 0x4000000) != 0 )
      {
        image->num_hp_qps = 1;
        r_HP_QP(image, str);
      }
    }
  }
  _jxr_rbitstream_syncbyte(pLeafNode: (bfx::DynKDNode *)str);
  return 0;
}


// ========================================================================
// ?_jxr_r_MB_CBP@@YAHPAUjxr_image@@PAUrbitstream@@HIIII@Z
// EA  : 0x82909618
// RVA : 0x00909618
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall _jxr_r_MB_CBP(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int *v7; // r10
  unsigned int v8; // r27
  int v11; // ctr
  unsigned int v12; // r31
  unsigned int v13; // r30
  unsigned int v14; // r28
  int use_clr_fmt; // r10
  int num_channels; // r11
  int num_cbp; // r3
  int v18; // r17
  char v19; // r27
  int v20; // r24
  int i; // r28
  int v22; // r11
  adaptive_vlc_s *v23; // r31
  int v24; // r3
  int v25; // r11
  int v26; // r31
  int v27; // r30
  int v28; // r11
  int v29; // r11
  int v30; // r4
  int v31; // r31
  int v32; // r11
  int v33; // r31
  int v34; // r11
  int v35; // r3
  int v36; // r11
  int v37; // r3
  int v38; // r11
  int v39; // r11
  int v40; // r4
  int *v43; // [sp+50h] [-120h]
  int v44; // [sp+54h] [-11Ch]
  int v45; // [sp+70h] [-100h] BYREF
  _DWORD v46[3]; // [sp+74h] [-FCh] BYREF
  int v47; // [sp+80h] [-F0h] BYREF
  _DWORD v48[2]; // [sp+84h] [-ECh] BYREF
  int v49; // [sp+8Ch] [-E4h] BYREF
  int v50; // [sp+90h] [-E0h] BYREF
  int v51; // [sp+94h] [-DCh]
  int v52; // [sp+98h] [-D8h]

  v7 = &v49;
  v8 = my;
  v11 = 16;
  v12 = tx;
  v13 = ty;
  v14 = mx;
  do
  {
    *++v7 = 0;
    --v11;
  }
  while ( v11 != 0 );
  if ( _jxr_InitContext(image, tx, ty, mx, my) != 0 )
    _jxr_InitCBPVLC(image);
  use_clr_fmt = image->use_clr_fmt;
  num_channels = 1;
  if ( use_clr_fmt == 4 || use_clr_fmt == 6 )
    num_channels = image->num_channels;
  if ( num_channels > 0 )
  {
    v44 = num_channels;
    v43 = &v50;
    while ( 1 )
    {
      num_cbp = get_num_cbp(str, vlc: &image->vlc_table[12]);
      image->vlc_table[12].discriminant += Num_BLKCBP_Delta5[num_cbp];
      v18 = r_REFINE_CBP(str, num: num_cbp);
      v19 = 0;
      v20 = 1;
      for ( i = 0; i < 16; i += 4 )
      {
        if ( (v20 & v18) == 0 )
          goto LABEL_67;
        v22 = image->use_clr_fmt;
        v23 = &image->vlc_table[13];
        if ( image->use_clr_fmt == 0 || v22 == 4 || v22 == 6 )
        {
          v24 = get_num_cbp(str, vlc: &image->vlc_table[13]);
        }
        else if ( image->vlc_table[13].table != 0 )
        {
          v24 = _jxr_rbitstream_intE(str, code_size: 6, codeb: byte_82237258, codev: asc_82237298);
          if ( v24 == 7 )
            v24 = _jxr_rbitstream_uint1(str) + 7;
        }
        else
        {
          v24 = _jxr_rbitstream_intE(str, code_size: 5, codeb: byte_822372D8, codev: byte_822372F8);
        }
        v25 = image->use_clr_fmt;
        if ( image->use_clr_fmt == 0 || v25 == 4 || v25 == 6 )
          v23->discriminant += Num_BLKCBP_Delta5[v24];
        else
          v23->discriminant += Num_BLKCBP_Delta9[v24];
        v26 = v24 + 1;
        v27 = 0;
        if ( v24 + 1 >= 6 )
        {
          if ( _jxr_rbitstream_uint1(str) )
            v28 = 0;
          else
            v28 = ((_cntlzw(_jxr_rbitstream_uint1(str) - 1) & 0x20) == 0) + 1;
          v27 = 16 * (v28 + 1);
          if ( v26 >= 9 )
          {
            if ( _jxr_rbitstream_uint1(str) )
              v29 = 0;
            else
              v29 = ((_cntlzw(_jxr_rbitstream_uint1(str) - 1) & 0x20) == 0) + 1;
            v26 += v29;
          }
          v26 -= 6;
        }
        v30 = flc_table[v26];
        v31 = off_table[v26];
        if ( v30 != 0 )
          v31 += _jxr_rbitstream_uintN(str, N: v30);
        v32 = image->use_clr_fmt;
        v33 = out_table[v31] + v27;
        switch ( v32 )
        {
          case 1:
            v40 = (((v33 >> 5) & 1) << v19) + v52;
            v50 |= (v33 & 0xF) << i;
            v51 |= ((v33 >> 4) & 1) << v19;
LABEL_66:
            v52 = v40;
            break;
          case 2:
            v50 |= (v33 & 0xF) << i;
            if ( (v33 & 0x10) != 0 )
            {
              v45 = 0;
              v46[0] = 1;
              v46[1] = 4;
              v46[2] = 5;
              if ( _jxr_rbitstream_uint1(str) )
                v38 = 0;
              else
                v38 = ((_cntlzw(_jxr_rbitstream_uint1(str) - 1) & 0x20) == 0) + 1;
              v51 |= v46[v38] << v46[i / 4u - 1];
            }
            if ( (v33 & 0x20) != 0 )
            {
              v47 = 0;
              v48[0] = 1;
              v48[1] = 4;
              v49 = 5;
              if ( _jxr_rbitstream_uint1(str) )
                v39 = 0;
              else
                v39 = ((_cntlzw(_jxr_rbitstream_uint1(str) - 1) & 0x20) == 0) + 1;
              v40 = (v48[v39] << v48[i / 4u - 1]) | v52;
              goto LABEL_66;
            }
            break;
          case 3:
            v50 |= (v33 & 0xF) << i;
            if ( (v33 & 0x10) != 0 )
            {
              if ( _jxr_rbitstream_uint1(str) )
              {
                v34 = 0;
              }
              else if ( _jxr_rbitstream_uint1(str) )
              {
                v34 = 1;
              }
              else
              {
                v34 = ((_cntlzw(_jxr_rbitstream_uint1(str) - 1) & 0x20) != 0) + 2;
              }
              v35 = r_REFINE_CBP(str, num: v34 + 1);
              v51 |= v35 << i;
            }
            if ( (v33 & 0x20) != 0 )
            {
              if ( _jxr_rbitstream_uint1(str) )
              {
                v36 = 0;
              }
              else if ( _jxr_rbitstream_uint1(str) )
              {
                v36 = 1;
              }
              else
              {
                v36 = ((_cntlzw(_jxr_rbitstream_uint1(str) - 1) & 0x20) != 0) + 2;
              }
              v37 = r_REFINE_CBP(str, num: v36 + 1);
              v52 |= v37 << i;
            }
            break;
          default:
            *v43 |= v33 << i;
            break;
        }
LABEL_67:
        ++v19;
        v20 = __ROL4__(v20, 1);
      }
      ++v43;
      if ( v44-- == 1 )
      {
        v8 = my;
        v14 = mx;
        v13 = ty;
        v12 = tx;
        break;
      }
    }
  }
  r_PredCBP(image, diff_cbp: &v50, tx: v12, ty: v13, mx: v14, my: v8);
  return 0;
}


// ========================================================================
// ?_jxr_r_MB_FLEXBITS@@YAHPAUjxr_image@@PAUrbitstream@@HIIII@Z
// EA  : 0x82909BD8
// RVA : 0x00909BD8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall _jxr_r_MB_FLEXBITS(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int v9; // r25
  int v10; // r9
  int use_clr_fmt; // r11
  unsigned int v12; // r26
  unsigned int *v13; // r10
  unsigned int v14; // r27
  unsigned int v15; // r11
  unsigned int v16; // r11
  int v17; // r28
  _DWORD *v18; // r30
  int i; // r31
  int v21; // [sp+50h] [-F0h]
  const int *v22; // [sp+54h] [-ECh]
  unsigned int v23; // [sp+58h] [-E8h]
  _DWORD v24[56]; // [sp+60h] [-E0h] BYREF

  v9 = 0;
  if ( image->num_channels != 0 )
  {
    do
    {
      v21 = 4;
      v10 = 4;
      if ( (-v9 & ~v9) < 0 )
      {
        use_clr_fmt = image->use_clr_fmt;
        if ( use_clr_fmt == 1 )
        {
          v21 = 1;
LABEL_7:
          v10 = v21;
          goto LABEL_8;
        }
        if ( use_clr_fmt == 2 )
        {
          v21 = 2;
          goto LABEL_7;
        }
      }
LABEL_8:
      v23 = 0;
      v12 = image->strip[0].cur[image->tile_column_position[tx] + mx].hp_model_bits[v9];
      if ( 4 * v10 > 0 )
      {
        v13 = (unsigned int *)_jxr_hp_scan_map;
        v22 = _jxr_hp_scan_map;
        while ( 1 )
        {
          v14 = v23;
          if ( v10 == 4 )
            v14 = *v13;
          v15 = *((_DWORD *)image + 9);
          v24[0] = 0;
          v16 = v15 >> 28;
          v24[1] = 4;
          v24[2] = 8;
          v24[3] = 12;
          v24[4] = 1;
          v24[5] = 5;
          v24[6] = 9;
          v24[7] = 13;
          v24[8] = 2;
          v24[9] = 6;
          v24[10] = 10;
          v24[11] = 14;
          v24[12] = 3;
          v24[13] = 7;
          v24[14] = 11;
          v24[15] = 15;
          if ( v16 <= v12 )
          {
            v17 = v12 - v16;
            if ( v12 != v16 )
            {
              v18 = v24;
              for ( i = 15; i != 0; --i )
                r_DECODE_FLEX(image, str, tx, mx, ch: v9, block: v14, k: *++v18 - 1, flexbits: v17);
              v10 = v21;
              v13 = (unsigned int *)v22;
            }
          }
          v22 = (const int *)(v13 + 1);
          if ( (int)++v23 >= 4 * v10 )
            break;
          ++v13;
        }
      }
      ++v9;
    }
    while ( v9 < image->num_channels );
  }
  return 0;
}


// ========================================================================
// r_DECODE_ABS_LEVEL
// EA  : 0x82909DC0
// RVA : 0x00909DC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_DECODE_ABS_LEVEL(jxr_image *image, rbitstream *str, unsigned int band, unsigned int chroma_flag)
{
  int v6; // r3
  int v7; // r29
  int table; // r10
  int v9; // r30
  const unsigned __int8 *v10; // r5
  const char *v11; // r6
  int v12; // r3
  int v13; // r10
  int v14; // r30
  int v15; // r31
  int v16; // r29
  unsigned __int8 v18; // r3
  int v19; // r30
  unsigned __int8 v20; // r3
  int i; // r31
  _DWORD v22[8]; // [sp+50h] [-70h] BYREF
  _DWORD v23[20]; // [sp+70h] [-50h] BYREF

  v6 = _jxr_vlc_select(band, chroma_flag);
  v23[0] = 2;
  v22[3] = 2;
  v22[4] = 2;
  v7 = 0;
  v22[5] = 2;
  v23[4] = 10;
  v22[0] = 0;
  v22[1] = 0;
  v22[2] = 1;
  table = image->vlc_table[v6].table;
  v23[1] = 3;
  v23[2] = 4;
  v9 = v6;
  v23[3] = 6;
  v23[5] = 14;
  v10 = abslevel_code1b;
  if ( table != 0 )
  {
    v11 = abslevel_code1v;
  }
  else
  {
    v10 = abslevel_code0b;
    v11 = abslevel_code0v;
  }
  v12 = _jxr_rbitstream_intE(str, code_size: 6, codeb: v10, codev: v11);
  v13 = v12;
  image->vlc_table[v9].discriminant += _jxr_abslevel_index_delta[v12];
  if ( v12 >= 6 )
  {
    v18 = _jxr_rbitstream_uint4(str);
    v19 = v18 + 4;
    if ( v18 == 15 )
    {
      v20 = _jxr_rbitstream_uint2(str);
      v19 = v20 + 19;
      if ( v20 == 3 )
        v19 = (unsigned __int8)_jxr_rbitstream_uint3(str) + 22;
    }
    if ( v19 > 0 )
    {
      for ( i = v19; i != 0; --i )
        v7 = _jxr_rbitstream_uint1(str) | (2 * v7);
    }
    return (1 << v19) + v7 + 2;
  }
  else
  {
    v14 = 0;
    v15 = v22[v13];
    v16 = v23[v13];
    if ( v15 <= 0 )
    {
      return v23[v13];
    }
    else
    {
      do
      {
        --v15;
        v14 = _jxr_rbitstream_uint1(str) | (2 * v14);
      }
      while ( v15 != 0 );
      return v14 + v16;
    }
  }
}


// ========================================================================
// ?r_DECODE_BLOCK@@YAHPAUjxr_image@@PAUrbitstream@@HQAHHH@Z
// EA  : 0x82909F78
// RVA : 0x00909F78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_DECODE_BLOCK(
        jxr_image *image,
        rbitstream *str,
        unsigned int chroma_flag,
        int *coeff,
        unsigned int band,
        int location)
{
  int v12; // r21
  int v13; // r30
  int v14; // r27
  unsigned int v15; // r29
  BOOL v16; // r23
  int v17; // r5
  int v18; // r28
  int *v19; // r30
  int v20; // r3
  char v21; // r26
  BOOL v22; // r3
  BOOL v23; // r26
  bool v24; // zf

  v12 = 1;
  v13 = r_DECODE_FIRST_INDEX(image, str, chroma_flag, band);
  v14 = v13 >> 2;
  v15 = (v13 >> 2) & v13 & 1;
  v16 = _jxr_rbitstream_uint1(str);
  if ( (v13 & 2) != 0 )
    coeff[1] = r_DECODE_ABS_LEVEL(image, str, band, chroma_flag: v15);
  else
    coeff[1] = 1;
  if ( v16 )
    coeff[1] = -coeff[1];
  if ( (v13 & 1) != 0 )
    *coeff = 0;
  else
    *coeff = r_DECODE_RUN(image: str, str: (rbitstream *)(15 - location), max_run: v17);
  v18 = *coeff + location + 1;
  if ( v14 != 0 )
  {
    v19 = coeff + 3;
    do
    {
      if ( (v14 & 1) != 0 )
        *(v19 - 1) = 0;
      else
        *(v19 - 1) = r_DECODE_RUN(image: str, str: (rbitstream *)(15 - v18), max_run: v17);
      v18 += *(v19 - 1) + 1;
      v20 = r_DECODE_INDEX(image, str, location: v18, chroma_flag, band, context: v15);
      v21 = v20;
      v14 = v20 >> 1;
      v15 &= v20 >> 1;
      v22 = _jxr_rbitstream_uint1(str);
      v24 = (v21 & 1) == 0;
      v23 = v22;
      if ( v24 )
        *v19 = 1;
      else
        *v19 = r_DECODE_ABS_LEVEL(image, str, band, chroma_flag: v15);
      if ( v23 )
        *v19 = -*v19;
      ++v12;
      v19 += 2;
    }
    while ( v14 != 0 );
  }
  return v12;
}


// ========================================================================
// r_DECODE_BLOCK_ADAPTIVE
// EA  : 0x8290A108
// RVA : 0x0090A108
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_DECODE_BLOCK_ADAPTIVE(
        jxr_image *image,
        rbitstream *str,
        unsigned int tx,
        unsigned int mx,
        int cbp_flag,
        unsigned int chroma_flag,
        int channel,
        int block,
        int mbhp_pred_mode,
        unsigned int model_bits,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        char a30)
{
  int result; // r3
  char *v39; // r11
  int i; // ctr
  int v41; // r28
  int v42; // r11
  int *v43; // r4
  int v44; // r11
  int v45; // r6
  int v46; // r7
  int v47; // r8
  int v48; // r9
  unsigned int v49; // r10
  int v50; // r5
  unsigned int v51; // r6
  int v52; // r23
  int v53; // r8
  int v54; // r9
  int v55; // ctr
  int v56; // r11
  int v57; // r8
  int v58; // r9
  int v59; // r5
  int v60; // r4
  int v61; // r28
  int v62; // r6
  int v63; // r26
  int v64; // r6
  int v65; // r8
  unsigned int v66; // r9
  int v67; // r29
  int *v68; // r10
  int v69; // r25
  int v70; // r24
  int v71; // r23
  int v72; // r22
  int v73; // r5
  int v74; // r26
  int v75; // r24
  int v76; // r28
  int v77; // r21
  char v78; // [sp+4Ch] [-134h] BYREF
  _DWORD v79[16]; // [sp+50h] [-130h] BYREF
  int v80; // [sp+90h] [-F0h] BYREF
  _BYTE v81[236]; // [sp+94h] [-ECh] BYREF

  v80 = 0;
  memset(Dst: v81, Val: 0, Size: 0x7Cu);
  result = 0;
  if ( cbp_flag != 0 )
  {
    v39 = &v78;
    for ( i = 16; i != 0; --i )
    {
      v39 += 4;
      *(_DWORD *)v39 = 0;
    }
    result = r_DECODE_BLOCK(image, str, chroma_flag, coeff: &v80, band: 2u, location: 1);
    v41 = 0;
    v42 = 1;
    if ( result > 0 )
    {
      v43 = (int *)v81;
      do
      {
        v44 = *(v43 - 1) + v42;
        if ( v44 >= 16 )
          return -1;
        v45 = *v43;
        if ( a28 == 1 )
        {
          v46 = 4 * (v44 + 384);
          v47 = 4 * (v44 + 399);
          v48 = *(int *)((char *)&image->user_flags + v46);
          v49 = *(int *)((char *)&image->user_flags + v47) + 1;
          *(int *)((char *)&image->user_flags + v47) = v49;
          v79[v48] = v45;
          if ( v44 <= 1 )
            goto LABEL_15;
          v50 = 4 * (v44 + 398);
          v51 = *(int *)((char *)&image->user_flags + v50);
          if ( v49 <= v51 )
            goto LABEL_15;
          v52 = v44 + 383;
        }
        else
        {
          v46 = 4 * (v44 + 354);
          v47 = 4 * (v44 + 369);
          v48 = *(int *)((char *)&image->user_flags + v46);
          v49 = *(int *)((char *)&image->user_flags + v47) + 1;
          *(int *)((char *)&image->user_flags + v47) = v49;
          v79[v48] = v45;
          if ( v44 <= 1 )
            goto LABEL_15;
          v50 = 4 * (v44 + 368);
          v51 = *(int *)((char *)&image->user_flags + v50);
          if ( v49 <= v51 )
            goto LABEL_15;
          v52 = v44 + 353;
        }
        *(int *)((char *)&image->user_flags + v50) = v49;
        *(int *)((char *)&image->user_flags + v47) = v51;
        v53 = *(&image->user_flags + v52);
        *(&image->user_flags + v52) = v48;
        *(int *)((char *)&image->user_flags + v46) = v53;
LABEL_15:
        ++v41;
        v42 = v44 + 1;
        v43 += 2;
      }
      while ( v41 < result );
    }
    v54 = channel + 5;
    v55 = 3;
    v56 = 1;
    if ( (image->user_flags & 1) != 0 )
    {
      v57 = 15 * block;
      v58 = 28 * v54;
      v59 = 15 * block + 19;
      do
      {
        v60 = 4 * (v57 + v56 + 16);
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v58))
                  + 4 * (v57 + v56 + 15)) = 0;
        v61 = 4 * (v57 + v56 + 17);
        v62 = 4 * (v57 + v56 + 18);
        v63 = 4 * (v59 + v56);
        v56 += 5;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v58))
                  + v60) = 0;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v58))
                  + v61) = 0;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v58))
                  + v62) = 0;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v58))
                  + v63) = 0;
        --v55;
      }
      while ( v55 != 0 );
    }
    else
    {
      v64 = 15 * block;
      v65 = 28 * v54;
      v66 = tx;
      v67 = 15 * block + 19;
      v68 = v79;
      do
      {
        v69 = v68[2];
        v70 = v68[1] << a30;
        v71 = v68[3];
        v72 = v68[4];
        v68 += 5;
        v73 = *v68;
        v74 = 4 * (v64 + v56 + 16);
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v66] + mx) + *(int *)((char *)&image->user_flags + v65))
                  + 4 * (v64 + v56 + 15)) = v70;
        v75 = 4 * (v64 + v56 + 17);
        v76 = 4 * (v64 + v56 + 18);
        v77 = 4 * (v67 + v56);
        v56 += 5;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v66] + mx) + *(int *)((char *)&image->user_flags + v65))
                  + v74) = v69 << a30;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v66] + mx) + *(int *)((char *)&image->user_flags + v65))
                  + v75) = v71 << a30;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v66] + mx) + *(int *)((char *)&image->user_flags + v65))
                  + v76) = v72 << a30;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v66] + mx) + *(int *)((char *)&image->user_flags + v65))
                  + v77) = v73 << a30;
        --v55;
      }
      while ( v55 != 0 );
    }
  }
  return result;
}


// ========================================================================
// ?jxr_init_read_stripe_bitstream@@YAHPAUjxr_image@@PBEI@Z
// EA  : 0x8290A4B0
// RVA : 0x0090A4B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall jxr_init_read_stripe_bitstream(jxr_image *image, const unsigned __int8 *data, unsigned int size)
{
  rbitstream *p_rbits; // r29
  int v5; // r5
  int result; // r3
  unsigned int v7; // r3
  char *v8; // r3
  jxr_image *input; // r3
  int v10; // r5
  int v11; // r7
  int v12; // r8
  _DWORD *v13; // r10
  int i; // ctr
  int v15; // r26
  int v16; // r28
  int v17; // r30
  int v18; // r30

  image->rbits.data = data;
  image->rbits.cur_ptr = data;
  p_rbits = &image->rbits;
  image->rbits.dataSize = size;
  image->rbits.bits_avail = 0;
  image->rbits.read_count = 0;
  image->rbits.mark_stream_position = 0;
  result = r_image_header(image, str: &image->rbits);
  if ( result >= 0 )
  {
    result = r_image_plane_header(image, str: p_rbits, alpha: v5);
    if ( result >= 0 )
    {
      _jxr_make_mbstore(image, up4_flag: 0);
      if ( (image->header_flags2 & 1) != 0 )
      {
        v7 = jxr_image_size();
        v8 = _jxr_temp_calloc(image, count: 1u, size: v7);
        input = jxr_create_input(buffer: (jxr_image *)v8);
        image->alpha = input;
        memcpy(Dst: input, Src: image, Size: sizeof(jxr_image));
        result = r_image_plane_header(image: image->alpha, str: p_rbits, alpha: v10);
        if ( result < 0 )
          return result;
        v11 = 0;
        if ( image->num_channels != 0 )
        {
          v12 = 0;
          do
          {
            v13 = (int *)((char *)&image->alpha->cur_my + v12);
            for ( i = 7; i != 0; --i )
              *++v13 = 0;
            ++v11;
            v12 += 28;
          }
          while ( v11 < image->num_channels );
        }
        _jxr_make_mbstore(image: image->alpha, up4_flag: 0);
        image->alpha->primary = 0;
      }
      v15 = r_INDEX_TABLE(image, str: p_rbits);
      if ( v15 >= 0 )
      {
        image->profile_idc = 111;
        image->level_idc = -1;
        v16 = _jxr_rbitstream_intVLW(str: p_rbits);
        if ( v16 > 0 )
        {
          v17 = 0;
          do
          {
            image->profile_idc = _jxr_rbitstream_uint8(str: p_rbits);
            image->level_idc = _jxr_rbitstream_uint8(str: p_rbits);
            _jxr_rbitstream_uint15(str: p_rbits);
            v17 += 4;
          }
          while ( !_jxr_rbitstream_uint1(str: p_rbits) );
          v18 = v16 - v17;
          if ( v18 > 0 )
          {
            do
            {
              _jxr_rbitstream_uint8(str: p_rbits);
              --v18;
            }
            while ( v18 != 0 );
          }
        }
        _jxr_rbitstream_mark(str: p_rbits);
        image->stripe_tx = 0;
        image->stripe_ty = 0;
        image->stripe_my = 0;
        image->freq_buffered_flag = 0;
        image->spatial_buffered_flag = 0;
        image->cleanup_state = 0;
      }
      return v15;
    }
  }
  return result;
}


// ========================================================================
// ?_jxr_r_MB_LP@@YAXPAUjxr_image@@PAUrbitstream@@HIIII@Z
// EA  : 0x8290A678
// RVA : 0x0090A678
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall _jxr_r_MB_LP(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int v7; // r19
  int i; // r6
  int v14; // r11
  int j; // ctr
  int v16; // r7
  char *v17; // r11
  int k; // ctr
  int use_clr_fmt; // r11
  int num_channels; // r28
  int v21; // r14
  int v22; // r30
  int v23; // r3
  unsigned int v24; // r30
  int v25; // r3
  char *v26; // r11
  int m; // ctr
  int v28; // r8
  int v29; // r11
  int v30; // r5
  _DWORD *v31; // r11
  int n; // ctr
  int v33; // r6
  int v34; // r8
  char *v35; // r11
  int ii; // ctr
  int v37; // r10
  int v38; // r10
  int v39; // r11
  int v40; // ctr
  _DWORD *v41; // r7
  int v42; // r10
  int v43; // r10
  int v44; // r10
  int v45; // r10
  int v46; // ctr
  int *v47; // r4
  int v48; // r5
  int v49; // r11
  int v50; // r7
  int v51; // r9
  int v52; // r8
  unsigned int v53; // r10
  int v54; // r5
  unsigned int v55; // r6
  int v56; // r10
  int v57; // r9
  int v58; // r8
  int v59; // r28
  const int *v60; // r25
  int v61; // r24
  int v62; // r27
  unsigned int v63; // r3
  unsigned int v64; // r26
  int v65; // r27
  const int *v66; // r25
  int v67; // r24
  int v68; // r27
  unsigned int v69; // r3
  unsigned int v70; // r26
  int v71; // r27
  const int *v72; // r22
  int v73; // r23
  int v74; // r27
  unsigned int v75; // r3
  unsigned int v76; // r26
  int v77; // r27
  int v78; // r27
  unsigned int v79; // r3
  unsigned int v80; // r26
  int v81; // r27
  const int *v82; // r22
  int v83; // r23
  int v84; // r27
  unsigned int v85; // r3
  unsigned int v86; // r26
  int v87; // r27
  int v88; // r27
  unsigned int v89; // r3
  unsigned int v90; // r26
  int v91; // r27
  int v92; // r9
  int v93; // r10
  int v94; // ctr
  int v95; // r11
  int v96; // r4
  int v97; // r24
  int v98; // r28
  int v99; // r27
  int v100; // r26
  int v101; // r4
  int v102; // r11
  int v103; // r9
  int v104; // r10
  int v105; // ctr
  int v106; // r11
  int v107; // r4
  int v108; // r24
  int v109; // r28
  int v110; // r27
  int v111; // r26
  int v112; // r4
  int v113; // r8
  int v114; // r8
  int v115; // r7
  int v116; // r6
  int v117; // r4
  int v118; // r3
  int v119; // r5
  int v120; // r28
  int v121; // r27
  int v122; // r26
  int v123; // r7
  int v124; // r5
  int v125; // r4
  int v126; // r8
  int v127; // r7
  int v128; // r6
  int v129; // r4
  int v130; // r3
  int v131; // [sp+50h] [-5B0h]
  _BYTE v132[64]; // [sp+5Ch] [-5A4h] BYREF
  char v133; // [sp+9Ch] [-564h] BYREF
  _DWORD v134[15]; // [sp+A0h] [-560h] BYREF
  char v135; // [sp+DCh] [-524h] BYREF
  int v136; // [sp+E0h] [-520h] BYREF
  _BYTE v137[192]; // [sp+E4h] [-51Ch] BYREF
  int v138; // [sp+1A4h] [-45Ch]
  int v139; // [sp+1A8h] [-458h]
  int v140; // [sp+1ACh] [-454h]
  int v141; // [sp+1B0h] [-450h]
  int v142; // [sp+1B4h] [-44Ch]
  int v143; // [sp+1B8h] [-448h]
  int v144; // [sp+1BCh] [-444h]
  _BYTE v145[4]; // [sp+1E0h] [-420h] BYREF
  int v146; // [sp+1E4h] [-41Ch]
  int v147; // [sp+1E8h] [-418h]
  int v148; // [sp+1ECh] [-414h]
  int v149; // [sp+1F0h] [-410h]
  int v150; // [sp+1F4h] [-40Ch]
  int v151; // [sp+1F8h] [-408h]
  int v152; // [sp+1FCh] [-404h]

  v7 = 0;
  for ( i = 0; i < 256; i += 16 )
  {
    v14 = 0;
    for ( j = 16; j != 0; --j )
    {
      v16 = 4 * (i + v14++);
      *(_DWORD *)&v137[v16 + 124] = 0;
    }
  }
  v17 = &v133;
  for ( k = 16; k != 0; --k )
  {
    v17 += 4;
    *(_DWORD *)v17 = 0;
  }
  if ( _jxr_InitContext(image, tx, ty, mx, my) != 0 )
  {
    _jxr_InitializeCountCBPLP(image);
    _jxr_InitLPVLC(image);
    _jxr_InitializeAdaptiveScanLP(image);
    _jxr_InitializeModelMB(model: &image->model_lp, band: 1);
  }
  if ( _jxr_ResetTotals(image, mx) )
    _jxr_ResetTotalsAdaptiveScanLP(image);
  use_clr_fmt = image->use_clr_fmt;
  num_channels = image->num_channels;
  v131 = num_channels;
  if ( (use_clr_fmt == 2 || use_clr_fmt == 1) && (num_channels = 2, v131 = 2, use_clr_fmt == 1)
    || use_clr_fmt == 2
    || use_clr_fmt == 3 )
  {
    if ( image->count_zero_CBPLP <= 0 || image->count_max_CBPLP < 0 )
    {
      v23 = dec_cbp_yuv_lp1(image, str);
      v21 = 4 * num_channels - 5 - v23;
      if ( image->count_max_CBPLP < image->count_zero_CBPLP )
      {
LABEL_24:
        _jxr_UpdateCountCBPLP(image, cbplp: v21, max: 4 * num_channels - 5);
        goto LABEL_25;
      }
    }
    else
    {
      v23 = _jxr_rbitstream_uintN(str, N: num_channels);
    }
    v21 = v23;
    goto LABEL_24;
  }
  v21 = 0;
  v22 = 0;
  if ( image->num_channels != 0 )
  {
    do
      v21 |= _jxr_rbitstream_uint1(str) << v22++;
    while ( v22 < image->num_channels );
  }
LABEL_25:
  if ( num_channels > 0 )
  {
    v24 = tx;
    do
    {
      v25 = 0;
      if ( ((v21 >> v7) & 1) != 0 )
      {
        v136 = 0;
        memset(Dst: v137, Val: 0, Size: 0x7Cu);
        v26 = &v135;
        for ( m = 32; m != 0; --m )
        {
          v26 += 4;
          *(_DWORD *)v26 = 0;
        }
        v28 = 1;
        if ( (-v7 & ~v7) < 0 )
        {
          v29 = image->use_clr_fmt;
          if ( v29 == 1 )
            v28 = 10;
          if ( v29 == 2 )
            v28 = 2;
        }
        v25 = r_DECODE_BLOCK(
                image,
                str,
                chroma_flag: (-v7 & (unsigned int)~v7) >> 31,
                coeff: &v136,
                band: 1u,
                location: v28);
        if ( (-v7 & ~v7) < 0 && ((v30 = image->use_clr_fmt) == 1 || v30 == 2) )
        {
          v31 = v132;
          for ( n = 14; n != 0; --n )
            *++v31 = 0;
          v33 = 14;
          if ( v30 == 1 )
            v33 = 6;
          v34 = 0;
          if ( v25 > 0 )
          {
            v35 = &v135;
            for ( ii = v25; ii != 0; --ii )
            {
              v37 = *((_DWORD *)v35 + 1);
              v35 += 8;
              v38 = v37 + v34;
              v34 = v38 + 1;
              *(_DWORD *)&v132[4 * v38 + 4] = *(_DWORD *)v35;
            }
          }
          v39 = 0;
          v40 = v33;
          v41 = v132;
          do
          {
            v42 = remap_arr[(v39 >> 1) + (v30 == 1)];
            if ( v30 == 1 )
              v43 = transpose420[v42];
            else
              v43 = transpose422[v42];
            ++v41;
            v44 = 16 * ((v39++ & 1) + 1) + v43;
            *(_DWORD *)&v137[4 * v44 + 124] = *v41;
            --v40;
          }
          while ( v40 != 0 );
        }
        else
        {
          v45 = 1;
          if ( v25 > 0 )
          {
            v46 = v25;
            v47 = (int *)v137;
            do
            {
              v48 = *v47;
              v49 = *(v47 - 1) + v45;
              v50 = 4 * (v49 + 324);
              v51 = 4 * (v49 + 339);
              v52 = *(int *)((char *)&image->user_flags + v50);
              v53 = *(int *)((char *)&image->user_flags + v51) + 1;
              *(int *)((char *)&image->user_flags + v51) = v53;
              *(_DWORD *)&v137[64 * v7 + 124 + 4 * v52] = v48;
              if ( v49 > 1 )
              {
                v54 = 4 * (v49 + 338);
                v55 = *(int *)((char *)&image->user_flags + v54);
                if ( v53 > v55 )
                {
                  *(int *)((char *)&image->user_flags + v54) = v53;
                  *(int *)((char *)&image->user_flags + v51) = v55;
                  v56 = 4 * (v49 + 323);
                  v57 = *(int *)((char *)&image->user_flags + v56);
                  *(int *)((char *)&image->user_flags + v56) = v52;
                  *(int *)((char *)&image->user_flags + v50) = v57;
                }
              }
              v45 = v49 + 1;
              v47 += 2;
              --v46;
            }
            while ( v46 != 0 );
          }
        }
      }
      v58 = image->use_clr_fmt;
      v59 = image->model_lp.bits[v7];
      v134[v7] += v25;
      if ( v59 != 0 )
      {
        if ( (-v7 & ~v7) >= 0 )
        {
          v60 = &transpose444[1];
          do
          {
            v61 = 4 * (16 * v7 + *v60);
            v62 = *(_DWORD *)&v137[v61 + 124];
            v63 = _jxr_rbitstream_uintN(str, N: v59);
            v64 = v63;
            if ( v62 <= 0 )
            {
              if ( v62 >= 0 )
              {
                v65 = v63;
                if ( v63 != 0 && _jxr_rbitstream_uint1(str) )
                  v65 = -v64;
              }
              else
              {
                v65 = (v62 << v59) - v63;
              }
            }
            else
            {
              v65 = (v62 << v59) + v63;
            }
            ++v60;
            *(_DWORD *)&v137[v61 + 124] = v65;
          }
          while ( (int)v60 < (int)"XXXX Don't know how to scale bit depth %d?\n" );
          goto LABEL_115;
        }
        if ( v58 == 1 )
        {
          v82 = &transpose420[1];
          do
          {
            v83 = 4 * *v82;
            v84 = *(_DWORD *)&v137[v83 + 188];
            v85 = _jxr_rbitstream_uintN(str, N: v59);
            v86 = v85;
            if ( v84 <= 0 )
            {
              if ( v84 >= 0 )
              {
                v87 = v85;
                if ( v85 != 0 && _jxr_rbitstream_uint1(str) )
                  v87 = -v86;
              }
              else
              {
                v87 = (v84 << v59) - v85;
              }
            }
            else
            {
              v87 = (v84 << v59) + v85;
            }
            *(_DWORD *)&v137[v83 + 188] = v87;
            v88 = *(_DWORD *)&v145[v83];
            v89 = _jxr_rbitstream_uintN(str, N: v59);
            v90 = v89;
            if ( v88 <= 0 )
            {
              if ( v88 >= 0 )
              {
                v91 = v89;
                if ( v89 != 0 && _jxr_rbitstream_uint1(str) )
                  v91 = -v90;
              }
              else
              {
                v91 = (v88 << v59) - v89;
              }
            }
            else
            {
              v91 = (v88 << v59) + v89;
            }
            ++v82;
            *(_DWORD *)&v145[v83] = v91;
          }
          while ( (int)v82 < (int)transpose422 );
        }
        else if ( v58 == 2 )
        {
          v72 = &transpose422[1];
          do
          {
            v73 = 4 * *v72;
            v74 = *(_DWORD *)&v137[v73 + 188];
            v75 = _jxr_rbitstream_uintN(str, N: v59);
            v76 = v75;
            if ( v74 <= 0 )
            {
              if ( v74 >= 0 )
              {
                v77 = v75;
                if ( v75 != 0 && _jxr_rbitstream_uint1(str) )
                  v77 = -v76;
              }
              else
              {
                v77 = (v74 << v59) - v75;
              }
            }
            else
            {
              v77 = (v74 << v59) + v75;
            }
            *(_DWORD *)&v137[v73 + 188] = v77;
            v78 = *(_DWORD *)&v145[v73];
            v79 = _jxr_rbitstream_uintN(str, N: v59);
            v80 = v79;
            if ( v78 <= 0 )
            {
              if ( v78 >= 0 )
              {
                v81 = v79;
                if ( v79 != 0 && _jxr_rbitstream_uint1(str) )
                  v81 = -v80;
              }
              else
              {
                v81 = (v78 << v59) - v79;
              }
            }
            else
            {
              v81 = (v78 << v59) + v79;
            }
            ++v72;
            *(_DWORD *)&v145[v73] = v81;
          }
          while ( (int)v72 < (int)&dword_822373F4 );
        }
        else
        {
          v66 = &transpose444[1];
          do
          {
            v67 = 4 * (16 * v7 + *v66);
            v68 = *(_DWORD *)&v137[v67 + 124];
            v69 = _jxr_rbitstream_uintN(str, N: v59);
            v70 = v69;
            if ( v68 <= 0 )
            {
              if ( v68 >= 0 )
              {
                v71 = v69;
                if ( v69 != 0 && _jxr_rbitstream_uint1(str) )
                  v71 = -v70;
              }
              else
              {
                v71 = (v68 << v59) - v69;
              }
            }
            else
            {
              v71 = (v68 << v59) + v69;
            }
            ++v66;
            *(_DWORD *)&v137[v67 + 124] = v71;
          }
          while ( (int)v66 < (int)"XXXX Don't know how to scale bit depth %d?\n" );
        }
      }
      if ( (-v7 & ~v7) < 0 )
      {
        v102 = image->use_clr_fmt;
        if ( v102 == 1 )
        {
          v126 = v146;
          v127 = v139;
          v128 = v147;
          v129 = v140;
          v130 = v148;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[1] = v138;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[1] = v126;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[2] = v127;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[2] = v128;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[3] = v129;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[3] = v130;
        }
        else if ( v102 == 2 )
        {
          v114 = v146;
          v115 = v139;
          v116 = v147;
          v117 = v140;
          v118 = v148;
          v119 = v141;
          v120 = v149;
          v121 = v142;
          v122 = v150;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[1] = v138;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[1] = v114;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[2] = v115;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[2] = v116;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[3] = v117;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[3] = v118;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[4] = v119;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[4] = v120;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[5] = v121;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[5] = v122;
          v123 = v151;
          v124 = v144;
          v125 = v152;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[6] = v143;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[6] = v123;
          image->strip[1].cur[image->tile_column_position[v24] + mx].data[7] = v124;
          image->strip[2].cur[image->tile_column_position[v24] + mx].data[7] = v125;
        }
        else
        {
          v103 = 1;
          v104 = 28 * (v7 + 5);
          v105 = 3;
          v106 = 16;
          do
          {
            v107 = 4 * (16 * v7 + v103);
            v108 = *(_DWORD *)&v137[v107 + 124];
            v109 = *(_DWORD *)&v137[v107 + 128];
            v103 += 5;
            v110 = *(_DWORD *)&v137[v107 + 132];
            v111 = *(_DWORD *)&v137[v107 + 136];
            v112 = *(_DWORD *)&v137[v107 + 140];
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx)
                                  + *(int *)((char *)&image->user_flags + v104))
                      + v106
                      - 12) = v108;
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx)
                                  + *(int *)((char *)&image->user_flags + v104))
                      + v106
                      - 12
                      + 4) = v109;
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx)
                                  + *(int *)((char *)&image->user_flags + v104))
                      + v106
                      - 4) = v110;
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx)
                                  + *(int *)((char *)&image->user_flags + v104))
                      + v106) = v111;
            v113 = *(_DWORD *)(84 * (image->tile_column_position[v24] + mx) + *(int *)((char *)&image->user_flags + v104))
                 + v106;
            v106 += 20;
            *(_DWORD *)(v113 + 4) = v112;
            --v105;
          }
          while ( v105 != 0 );
        }
        goto LABEL_125;
      }
LABEL_115:
      v92 = 1;
      v93 = 28 * (v7 + 5);
      v94 = 3;
      v95 = 16;
      do
      {
        v96 = 4 * (16 * v7 + v92);
        v97 = *(_DWORD *)&v137[v96 + 124];
        v98 = *(_DWORD *)&v137[v96 + 128];
        v92 += 5;
        v99 = *(_DWORD *)&v137[v96 + 132];
        v100 = *(_DWORD *)&v137[v96 + 136];
        v101 = *(_DWORD *)&v137[v96 + 140];
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx) + *(int *)((char *)&image->user_flags + v93))
                  + v95
                  - 12) = v97;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx) + *(int *)((char *)&image->user_flags + v93))
                  + v95
                  - 12
                  + 4) = v98;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx) + *(int *)((char *)&image->user_flags + v93))
                  + v95
                  - 4) = v99;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx) + *(int *)((char *)&image->user_flags + v93))
                  + v95) = v100;
        *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v24] + mx) + *(int *)((char *)&image->user_flags + v93))
                  + v95
                  + 4) = v101;
        v95 += 20;
        --v94;
      }
      while ( v94 != 0 );
LABEL_125:
      ++v7;
    }
    while ( v7 < v131 );
  }
  _jxr_UpdateModelMB(image, lap_mean: (char *)v134, model: &image->model_lp, band: 1);
  if ( _jxr_ResetContext(image, tx, mx) )
    _jxr_AdaptLP(image);
}


// ========================================================================
// ?_jxr_r_MB_HP@@YAHPAUjxr_image@@PAUrbitstream@@HIIII@Z
// EA  : 0x8290B260
// RVA : 0x0090B260
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall _jxr_r_MB_HP(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int *v11; // r7
  int v12; // ctr
  int v13; // r3
  signed int num_channels; // r11
  int v15; // r16
  signed int v16; // r24
  char *v17; // r21
  macroblock_s **p_cur; // r15
  model_s *p_model_hp; // r14
  int v20; // r19
  int v21; // r10
  unsigned int v22; // r18
  int use_clr_fmt; // r11
  unsigned int v24; // r25
  int v25; // r26
  int hp_cbp; // r27
  unsigned int *v27; // r23
  unsigned int v28; // r28
  int v29; // r29
  unsigned int v30; // r10
  int v31; // r10
  int v32; // r28
  int i; // r29
  unsigned int v34; // r9
  int v35; // r11
  unsigned int *v36; // r10
  int v37; // ctr
  unsigned int *v38; // r7
  int v39; // r7
  unsigned int v41; // [sp+8h] [-148h]
  unsigned int v42; // [sp+Ch] [-144h]
  int v43; // [sp+10h] [-140h]
  int v44; // [sp+14h] [-13Ch]
  int v45; // [sp+18h] [-138h]
  int v46; // [sp+1Ch] [-134h]
  int v47; // [sp+20h] [-130h]
  int v48; // [sp+24h] [-12Ch]
  int v49; // [sp+28h] [-128h]
  int v50; // [sp+2Ch] [-124h]
  int v51; // [sp+30h] [-120h]
  int v52; // [sp+34h] [-11Ch]
  int v53; // [sp+38h] [-118h]
  int v54; // [sp+3Ch] [-114h]
  int v55; // [sp+40h] [-110h]
  int v56; // [sp+44h] [-10Ch]
  int v57; // [sp+48h] [-108h]
  int v58; // [sp+4Ch] [-104h]
  int v59; // [sp+50h] [-100h]
  int v60; // [sp+58h] [-F8h]
  BOOL v61; // [sp+64h] [-ECh]
  int v62; // [sp+6Ch] [-E4h] BYREF
  char v63[224]; // [sp+70h] [-E0h] BYREF

  if ( _jxr_InitContext(image, tx, ty, mx, my) != 0 )
  {
    _jxr_InitHPVLC(image);
    _jxr_InitializeAdaptiveScanHP(image);
    _jxr_InitializeModelMB(model: &image->model_hp, band: 2);
  }
  if ( _jxr_ResetTotals(image, mx) )
    _jxr_ResetTotalsAdaptiveScanHP(image);
  v11 = &v62;
  v12 = 16;
  v61 = (image->header_flags1 & 0x40) == 0 && image->bands_present != 1;
  do
  {
    *++v11 = 0;
    --v12;
  }
  while ( v12 != 0 );
  v13 = r_calculate_mbhp_mode(image, tx, mx);
  num_channels = image->num_channels;
  v15 = v13;
  v16 = 0;
  if ( image->num_channels != 0 )
  {
    v17 = v63;
    p_cur = &image->strip[0].cur;
    p_model_hp = &image->model_hp;
    while ( 1 )
    {
      v20 = 4;
      v21 = -v16 & ~v16;
      v22 = (unsigned int)v21 >> 31;
      if ( v21 < 0 )
      {
        use_clr_fmt = image->use_clr_fmt;
        if ( use_clr_fmt == 1 )
        {
          v20 = 1;
        }
        else if ( use_clr_fmt == 2 )
        {
          v20 = 2;
        }
      }
      v24 = p_model_hp->bits[0];
      v25 = 0;
      hp_cbp = (*p_cur)[image->tile_column_position[tx] + mx].hp_cbp;
      if ( 4 * v20 > 0 )
        break;
LABEL_22:
      num_channels = image->num_channels;
      ++v16;
      p_cur += 7;
      p_model_hp = (model_s *)((char *)p_model_hp + 4);
      v17 += 4;
      if ( v16 >= num_channels )
        goto LABEL_23;
    }
    v27 = (unsigned int *)_jxr_hp_scan_map;
    while ( 1 )
    {
      v28 = v25;
      if ( v20 == 4 )
        v28 = *v27;
      v29 = r_DECODE_BLOCK_ADAPTIVE(
              image,
              str,
              tx,
              mx,
              cbp_flag: hp_cbp & 1,
              chroma_flag: v22,
              channel: v16,
              block: v28,
              mbhp_pred_mode: v41,
              model_bits: v42,
              a11: v43,
              a12: v44,
              a13: v45,
              a14: v46,
              a15: v47,
              a16: v48,
              a17: v49,
              a18: v50,
              a19: v51,
              a20: v52,
              a21: v53,
              a22: v54,
              a23: v55,
              a24: v56,
              a25: v57,
              a26: v58,
              a27: v59,
              a28: v15,
              a29: v60,
              a30: v24);
      if ( v29 < 0 )
        return -1;
      if ( v61 )
        r_BLOCK_FLEXBITS(image, str, tx, ty: mx, mx: v16, my: v28, ch: v24, bl: v30, model_bits: v41);
      ++v25;
      ++v27;
      hp_cbp >>= 1;
      *(_DWORD *)v17 += v29;
      if ( v25 >= 4 * v20 )
        goto LABEL_22;
    }
  }
  else
  {
LABEL_23:
    v31 = image->use_clr_fmt;
    v32 = num_channels;
    if ( v31 == 1 || v31 == 2 )
      v32 = 1;
    if ( (image->header_flags1 & 0x40) == 0 || image->bands_present == 1 )
    {
      for ( i = 0; i < v32; ++i )
        _jxr_propagate_hp_predictions(image, ch: i, tx, mx, mbhp_pred_mode: v15);
    }
    v34 = tx;
    v35 = 0;
    v36 = (unsigned int *)&image->model_lp.state[15];
    v37 = 4;
    v38 = (unsigned int *)((char *)&image->strip[0].cur[image->tile_column_position[tx] + mx] + 8);
    *v38 = (v15 << 13) & 0xE000 | *v38 & 0xFFFF1FFF;
    do
    {
      image->strip[0].cur[image->tile_column_position[v34] + mx].hp_model_bits[v35] = v36[1];
      image->strip[0].cur[image->tile_column_position[v34] + mx].hp_model_bits[v35 + 1] = v36[2];
      image->strip[0].cur[image->tile_column_position[v34] + mx].hp_model_bits[v35 + 2] = v36[3];
      v36 += 4;
      v39 = 21 * (image->tile_column_position[v34] + mx) + v35;
      v35 += 4;
      image->strip[0].cur->hp_model_bits[v39 + 3] = *v36;
      --v37;
    }
    while ( v37 != 0 );
    _jxr_UpdateModelMB(image, lap_mean: v63, model: &image->model_hp, band: 2);
    if ( _jxr_ResetContext(image, tx, mx) )
      _jxr_AdaptHP(image);
    return 0;
  }
}


// ========================================================================
// r_DEC_DC
// EA  : 0x8290B610
// RVA : 0x0090B610
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

int __fastcall r_DEC_DC(
        jxr_image *image,
        rbitstream *str,
        int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my,
        int model_bits,
        int chroma_flag,
        int is_dc_ch)
{
  int v11; // r30
  int result; // r3
  bool v13; // zf

  v11 = 0;
  if ( mx != 0 )
    v11 = r_DECODE_ABS_LEVEL(image, str, band: 0, chroma_flag: ty) - 1;
  if ( tx > 0 )
  {
    do
    {
      --tx;
      v11 = _jxr_rbitstream_uint1(str) | (2 * v11);
    }
    while ( tx != 0 );
  }
  if ( v11 == 0 )
    return v11;
  v13 = _jxr_rbitstream_uint1(str);
  result = -v11;
  if ( !v13 )
    return v11;
  return result;
}


// ========================================================================
// ?_jxr_r_MB_DC@@YAXPAUjxr_image@@PAUrbitstream@@HIIII@Z
// EA  : 0x8290B688
// RVA : 0x0090B688
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_parse.cpp
// ========================================================================

void __fastcall _jxr_r_MB_DC(
        jxr_image *image,
        rbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  char *v7; // r10
  int i; // ctr
  int use_clr_fmt; // r11
  int v14; // r10
  int v15; // r9
  unsigned int v16; // r8
  char is_dc_yuv; // r3
  char v18; // r30
  int v19; // r29
  int v20; // r10
  int v21; // r9
  unsigned int v22; // r8
  int v23; // r10
  int v24; // r9
  unsigned int v25; // r8
  int v26; // r3
  unsigned int v27; // r7
  int v28; // r30
  int v29; // r3
  unsigned int v30; // r26
  int *v31; // r28
  unsigned int *p_num_lp_qps; // r25
  model_s *p_model_dc; // r27
  int v34; // r29
  BOOL v35; // r3
  int v36; // r30
  int v37; // [sp+8h] [-E8h]
  int v38; // [sp+8h] [-E8h]
  int v39; // [sp+8h] [-E8h]
  char v40; // [sp+4Ch] [-A4h] BYREF
  int v41; // [sp+50h] [-A0h] BYREF
  int v42; // [sp+54h] [-9Ch]
  int v43; // [sp+58h] [-98h]

  v7 = &v40;
  for ( i = 16; i != 0; --i )
  {
    v7 += 4;
    *(_DWORD *)v7 = 0;
  }
  if ( _jxr_InitContext(image, tx, ty, mx, my) != 0 )
  {
    _jxr_InitVLCTable(image, vlc_select: 0);
    _jxr_InitVLCTable(image, vlc_select: 1);
    _jxr_InitializeModelMB(model: &image->model_dc, band: 0);
  }
  use_clr_fmt = image->use_clr_fmt;
  if ( image->use_clr_fmt == 0 || use_clr_fmt == 4 || use_clr_fmt == 6 )
  {
    v30 = 0;
    if ( image->num_channels != 0 )
    {
      v31 = &v41;
      p_num_lp_qps = &image->num_lp_qps;
      p_model_dc = &image->model_dc;
      do
      {
        v34 = p_model_dc->bits[0];
        v35 = _jxr_rbitstream_uint1(str);
        if ( v35 )
          ++*v31;
        v36 = 0;
        if ( v35 )
          v36 = r_DECODE_ABS_LEVEL(image, str, band: 0, chroma_flag: 0) - 1;
        if ( v34 > 0 )
        {
          do
          {
            --v34;
            v36 = _jxr_rbitstream_uint1(str) | (2 * v36);
          }
          while ( v34 != 0 );
        }
        if ( v36 != 0 && _jxr_rbitstream_uint1(str) )
          v36 = -v36;
        ++v30;
        p_num_lp_qps += 7;
        p_model_dc = (model_s *)((char *)p_model_dc + 4);
        ++v31;
        **(_DWORD **)(84 * (image->tile_column_position[tx] + mx) + *p_num_lp_qps) = v36;
      }
      while ( v30 < image->num_channels );
    }
  }
  else
  {
    is_dc_yuv = get_is_dc_yuv(str);
    v18 = is_dc_yuv;
    if ( (is_dc_yuv & 4) != 0 )
      v14 = ++v41;
    v19 = r_DEC_DC(
            image,
            str,
            tx: image->model_dc.bits[0],
            ty: 0,
            mx: is_dc_yuv & 4,
            my: v16,
            model_bits: v15,
            chroma_flag: v14,
            is_dc_ch: v37);
    if ( (v18 & 2) != 0 )
      v20 = ++v42;
    v26 = r_DEC_DC(
            image,
            str,
            tx: image->model_dc.bits[1],
            ty: 1u,
            mx: v18 & 2,
            my: v22,
            model_bits: v21,
            chroma_flag: v20,
            is_dc_ch: v38);
    v27 = v18 & 1;
    v28 = v26;
    if ( v27 != 0 )
      v23 = ++v43;
    v29 = r_DEC_DC(
            image,
            str,
            tx: image->model_dc.bits[2],
            ty: 1u,
            mx: v27,
            my: v25,
            model_bits: v24,
            chroma_flag: v23,
            is_dc_ch: v39);
    *image->strip[0].cur[image->tile_column_position[tx] + mx].data = v19;
    *image->strip[1].cur[image->tile_column_position[tx] + mx].data = v28;
    *image->strip[2].cur[image->tile_column_position[tx] + mx].data = v29;
  }
  _jxr_UpdateModelMB(image, lap_mean: (char *)&v41, model: &image->model_dc, band: 0);
  if ( _jxr_ResetContext(image, tx, mx) )
  {
    _jxr_AdaptVLCTable(image, vlc_select: 0);
    _jxr_AdaptVLCTable(image, vlc_select: 1);
  }
}

