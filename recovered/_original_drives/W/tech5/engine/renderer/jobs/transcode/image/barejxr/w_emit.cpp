
// ========================================================================
// ?initialize_index_table@@YAXPAUjxr_image@@@Z
// EA  : 0x82914B40
// RVA : 0x00914B40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall initialize_index_table(jxr_image *image)
{
  __int64 v1; // r11
  unsigned int v2; // r4

  if ( (image->header_flags1 & 0x40) != 0 )
  {
    LODWORD(v1) = image->bands_present_of_primary;
    HIDWORD(v1) = image->tile_columns * image->tile_rows;
    if ( (_DWORD)v1 == 4 )
      v2 = 4 * HIDWORD(v1);
    else
      v2 = (4 - v1) * HIDWORD(v1);
  }
  else
  {
    HIDWORD(v1) = image->tile_rows;
    v2 = image->tile_columns * HIDWORD(v1);
  }
  LODWORD(v1) = v2;
  image->tile_index_table_length = v1;
  image->tile_index_table = (__int64 *)_jxr_temp_calloc(image, count: v2, size: 8u);
}


// ========================================================================
// w_image_header
// EA  : 0x82914BC8
// RVA : 0x00914BC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall w_image_header(jxr_image *image, wbitstream *str)
{
  _BYTE *v2; // r10
  const char *v5; // r11
  int i; // ctr
  unsigned int j; // r29
  unsigned int v8; // r28
  int v9; // r29
  unsigned int *tile_column_width; // r11
  unsigned int v11; // r28
  int v12; // r29
  unsigned int *tile_row_height; // r11
  _BYTE v15[65]; // [sp+4Fh] [-41h] BYREF

  v2 = v15;
  v5 = &abslevel_code1v[63];
  for ( i = 9; i != 0; --i )
    *++v2 = *++v5;
  for ( j = 0; j < 8; ++j )
    _jxr_wbitstream_uint8(str, val: v15[j + 1]);
  _jxr_wbitstream_uint4(str, val: 1u);
  _jxr_wbitstream_uint1(str, val: image->disableTileOverlapFlag);
  _jxr_wbitstream_uint3(str, val: 1u);
  _jxr_wbitstream_uint8(str, val: image->header_flags1);
  _jxr_wbitstream_uint8(str, val: image->header_flags2);
  _jxr_wbitstream_uint8(str, val: image->header_flags_fmt);
  if ( (image->header_flags2 & 0x80) != 0 )
  {
    _jxr_wbitstream_uint16(str, val: image->width1);
    _jxr_wbitstream_uint16(str, val: image->height1);
  }
  else
  {
    _jxr_wbitstream_uint32(str, val: image->width1);
    _jxr_wbitstream_uint32(str, val: image->height1);
  }
  if ( jxr_get_TILING_FLAG(image) != 0 )
  {
    _jxr_wbitstream_uint12(str, val: image->tile_columns - 1);
    _jxr_wbitstream_uint12(str, val: image->tile_rows - 1);
    v8 = 0;
    if ( image->tile_columns != 1 )
    {
      v9 = 0;
      do
      {
        tile_column_width = image->tile_column_width;
        if ( (image->header_flags2 & 0x80) != 0 )
          _jxr_wbitstream_uint8(str, val: tile_column_width[v9]);
        else
          _jxr_wbitstream_uint16(str, val: tile_column_width[v9]);
        ++v8;
        ++v9;
      }
      while ( v8 < image->tile_columns - 1 );
    }
    v11 = 0;
    if ( image->tile_rows != 1 )
    {
      v12 = 0;
      do
      {
        tile_row_height = image->tile_row_height;
        if ( (image->header_flags2 & 0x80) != 0 )
          _jxr_wbitstream_uint8(str, val: tile_row_height[v12]);
        else
          _jxr_wbitstream_uint16(str, val: tile_row_height[v12]);
        ++v11;
        ++v12;
      }
      while ( v11 < image->tile_rows - 1 );
    }
  }
  if ( (image->header_flags2 & 0x20) != 0 )
  {
    _jxr_wbitstream_uint6(str, val: image->window_extra_top);
    _jxr_wbitstream_uint6(str, val: image->window_extra_left);
    _jxr_wbitstream_uint6(str, val: image->window_extra_bottom);
    _jxr_wbitstream_uint6(str, val: image->window_extra_right);
  }
  return 0;
}


// ========================================================================
// ?_jxr_w_DC_QP@@YAXPAUjxr_image@@PAUwbitstream@@@Z
// EA  : 0x82914E08
// RVA : 0x00914E08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_DC_QP(jxr_image *image, wbitstream *str)
{
  jxr_component_mode_e dc_component_mode; // r31
  int v5; // r31

  if ( image->num_channels == 1 )
  {
    dc_component_mode = JXR_CM_UNIFORM;
  }
  else
  {
    dc_component_mode = image->dc_component_mode;
    _jxr_wbitstream_uint2(str, val: dc_component_mode);
  }
  if ( dc_component_mode != JXR_CM_UNIFORM )
  {
    if ( dc_component_mode == JXR_CM_SEPARATE )
    {
      _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[0]);
      _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[1]);
    }
    else if ( (unsigned int)dc_component_mode < JXR_CM_Reserved )
    {
      v5 = 0;
      if ( image->num_channels != 0 )
      {
        do
          _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[v5++]);
        while ( v5 < image->num_channels );
      }
    }
  }
  else
  {
    _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[0]);
  }
}


// ========================================================================
// ?_jxr_w_LP_QP@@YAXPAUjxr_image@@PAUwbitstream@@@Z
// EA  : 0x82914EC0
// RVA : 0x00914EC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_LP_QP(jxr_image *image, wbitstream *str)
{
  unsigned int v4; // r27
  unsigned __int8 *v5; // r26
  jxr_component_mode_e dc_component_mode; // r31
  int v7; // r31
  unsigned __int8 *v8; // r30
  unsigned __int8 v9; // r4

  v4 = 0;
  if ( image->num_lp_qps != 0 )
  {
    v5 = image->lp_quant_ch[0];
    do
    {
      if ( image->num_channels == 1 )
      {
        dc_component_mode = JXR_CM_UNIFORM;
      }
      else
      {
        dc_component_mode = image->dc_component_mode;
        _jxr_wbitstream_uint2(str, val: dc_component_mode);
      }
      if ( dc_component_mode != JXR_CM_UNIFORM )
      {
        if ( dc_component_mode != JXR_CM_SEPARATE )
        {
          if ( (unsigned int)dc_component_mode < JXR_CM_Reserved )
          {
            v7 = 0;
            if ( image->num_channels != 0 )
            {
              v8 = &v5[v4 - 16];
              do
              {
                v8 += 16;
                _jxr_wbitstream_uint8(str, val: *v8);
                ++v7;
              }
              while ( v7 < image->num_channels );
            }
          }
          goto LABEL_16;
        }
        _jxr_wbitstream_uint8(str, val: v5[v4]);
        v9 = image->lp_quant_ch[1][v4];
      }
      else
      {
        v9 = v5[v4];
      }
      _jxr_wbitstream_uint8(str, val: v9);
LABEL_16:
      ++v4;
    }
    while ( v4 < image->num_lp_qps );
  }
}


// ========================================================================
// ?_jxr_w_HP_QP@@YAXPAUjxr_image@@PAUwbitstream@@@Z
// EA  : 0x82914F98
// RVA : 0x00914F98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_HP_QP(jxr_image *image, wbitstream *str)
{
  unsigned int v4; // r27
  unsigned __int8 *v5; // r26
  jxr_component_mode_e dc_component_mode; // r31
  int v7; // r31
  unsigned __int8 *v8; // r30
  unsigned __int8 v9; // r4

  v4 = 0;
  if ( image->num_hp_qps != 0 )
  {
    v5 = image->hp_quant_ch[0];
    do
    {
      if ( image->num_channels == 1 )
      {
        dc_component_mode = JXR_CM_UNIFORM;
      }
      else
      {
        dc_component_mode = image->dc_component_mode;
        _jxr_wbitstream_uint2(str, val: dc_component_mode);
      }
      if ( dc_component_mode != JXR_CM_UNIFORM )
      {
        if ( dc_component_mode != JXR_CM_SEPARATE )
        {
          if ( (unsigned int)dc_component_mode < JXR_CM_Reserved )
          {
            v7 = 0;
            if ( image->num_channels != 0 )
            {
              v8 = &v5[v4 - 16];
              do
              {
                v8 += 16;
                _jxr_wbitstream_uint8(str, val: *v8);
                ++v7;
              }
              while ( v7 < image->num_channels );
            }
          }
          goto LABEL_16;
        }
        _jxr_wbitstream_uint8(str, val: v5[v4]);
        v9 = image->hp_quant_ch[1][v4];
      }
      else
      {
        v9 = v5[v4];
      }
      _jxr_wbitstream_uint8(str, val: v9);
LABEL_16:
      ++v4;
    }
    while ( v4 < image->num_hp_qps );
  }
}


// ========================================================================
// w_TILE
// EA  : 0x82915070
// RVA : 0x00915070
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall w_TILE(jxr_image *image, wbitstream *str, int a3, int a4, int a5, int a6, __int64 a7)
{
  int v9; // r25
  unsigned int v10; // r27
  unsigned int tile_columns; // r11
  unsigned int v12; // r29
  int v13; // r28
  unsigned int write_count; // r11
  unsigned int v15; // r27
  unsigned __int8 i; // r24
  unsigned int j; // r29
  __int64 *tile_index_table; // r8
  int v19; // r28
  int tile_index_table_length; // r10
  int v21; // ctr
  int v22; // r11

  v9 = 0;
  if ( (image->header_flags1 & 0x40) != 0 )
  {
    v15 = 0;
    for ( i = image->bands_present_of_primary; v15 < image->tile_rows; ++v15 )
    {
      for ( j = 0; j < image->tile_columns; ++v9 )
      {
        _jxr_w_TILE_DC(image, str, tx: j, ty: v15);
        HIDWORD(a7) = str->write_count;
        tile_index_table = image->tile_index_table;
        v19 = (4 - i) * v9;
        tile_index_table[v19] = *(__int64 *)((char *)&a7 + 4);
        if ( i != 3 )
        {
          _jxr_w_TILE_LP(image, str, tx: j, ty: v15);
          LODWORD(a7) = str->write_count;
          image->tile_index_table[v19 + 1] = a7;
          if ( i != 2 )
            idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)image);
        }
        ++j;
      }
    }
  }
  else if ( (image->header_flags1 & 0x80) != 0 )
  {
    v10 = 0;
    if ( image->tile_rows != 0 )
    {
      tile_columns = image->tile_columns;
      do
      {
        v12 = 0;
        if ( tile_columns != 0 )
        {
          v13 = 8 * v9;
          do
          {
            _jxr_w_TILE_SPATIAL(image, str, tx: v12, ty: v10);
            write_count = str->write_count;
            LODWORD(a7) = image->tile_index_table;
            ++v12;
            ++v9;
            *(_QWORD *)(v13 + a7) = *(__int64 *)((char *)&a7 - 4);
            v13 += 8;
            tile_columns = image->tile_columns;
          }
          while ( v12 < tile_columns );
        }
        ++v10;
      }
      while ( v10 < image->tile_rows );
    }
  }
  else
  {
    _jxr_w_TILE_SPATIAL(image, str, tx: 0, ty: 0);
  }
  if ( (image->header_flags1 & 4) != 0 )
  {
    tile_index_table_length = image->tile_index_table_length;
    if ( tile_index_table_length != 1 )
    {
      v21 = tile_index_table_length - 1;
      v22 = tile_index_table_length - 1;
      do
      {
        LODWORD(a7) = &image->tile_index_table[v22--];
        *(__int64 *)((char *)&a7 + 4) = *(_QWORD *)(a7 - 8);
        *(_QWORD *)a7 = *(__int64 *)((char *)&a7 + 4);
        --v21;
      }
      while ( v21 != 0 );
    }
    LODWORD(a7) = 0;
    *image->tile_index_table = a7;
  }
}


// ========================================================================
// short_header_ok
// EA  : 0x82915240
// RVA : 0x00915240
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall short_header_ok(jxr_image *image)
{
  unsigned int v2; // r30
  unsigned int v3; // r30

  if ( image->width1 < 0x10000 && image->height1 < 0x10000 )
  {
    if ( jxr_get_TILING_FLAG(image) == 0 )
      return 1;
    v2 = 0;
    if ( image->tile_columns != 0 )
    {
      while ( (int)jxr_get_TILE_WIDTH(image, column: v2) / 16 <= 256 )
      {
        if ( ++v2 >= image->tile_columns )
          goto LABEL_7;
      }
      return 0;
    }
LABEL_7:
    v3 = 0;
    if ( image->tile_rows == 0 )
      return 1;
    while ( (int)jxr_get_TILE_HEIGHT(image, row: v3) / 16 <= 256 )
    {
      if ( ++v3 >= image->tile_rows )
        return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?_jxr_w_TILE_HEADER_DC@@YAXPAUjxr_image@@PAUwbitstream@@HII@Z
// EA  : 0x82915320
// RVA : 0x00915320
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_TILE_HEADER_DC(
        jxr_image *image,
        wbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty)
{
  jxr_tile_qp *v7; // r10
  jxr_component_mode_e component_mode; // r11
  bool v9; // cr56
  bool v10; // cr58
  int v11; // r11
  unsigned __int8 *v12; // r10
  unsigned int num_channels; // r7
  int v14; // r11
  int v15; // r11
  jxr_component_mode_e dc_component_mode; // r30
  int v17; // r30

  if ( (*((_DWORD *)image + 26) & 0x40000000) == 0 )
  {
    v7 = &image->tile_quant[(image->tile_rows + 1) * ty + tx];
    component_mode = v7->component_mode;
    v9 = v7->component_mode == JXR_CM_UNIFORM;
    v10 = v7->component_mode == JXR_CM_SEPARATE;
    image->dc_component_mode = v7->component_mode;
    if ( v9 )
    {
      v15 = 0;
      if ( image->num_channels != 0 )
      {
        do
          image->dc_quant_ch[v15++] = v7->channel[0].dc_qp;
        while ( v15 < image->num_channels );
      }
    }
    else if ( v10 )
    {
      num_channels = image->num_channels;
      v14 = 1;
      image->dc_quant_ch[0] = v7->channel[0].dc_qp;
      if ( num_channels > 1 )
      {
        do
          image->dc_quant_ch[v14++] = v7->channel[1].dc_qp;
        while ( v14 < image->num_channels );
      }
    }
    else if ( (unsigned int)component_mode < JXR_CM_Reserved )
    {
      v11 = 0;
      if ( image->num_channels != 0 )
      {
        v12 = &v7[-1].hp_quant_ch[14][1];
        do
        {
          v12 += 35;
          image->dc_quant_ch[v11++] = *v12;
        }
        while ( v11 < image->num_channels );
      }
    }
    if ( image->num_channels == 1 )
    {
      dc_component_mode = JXR_CM_UNIFORM;
    }
    else
    {
      dc_component_mode = image->dc_component_mode;
      _jxr_wbitstream_uint2(str, val: dc_component_mode);
    }
    if ( dc_component_mode != JXR_CM_UNIFORM )
    {
      if ( dc_component_mode == JXR_CM_SEPARATE )
      {
        _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[0]);
        _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[1]);
      }
      else if ( (unsigned int)dc_component_mode < JXR_CM_Reserved )
      {
        v17 = 0;
        if ( image->num_channels != 0 )
        {
          do
            _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[v17++]);
          while ( v17 < image->num_channels );
        }
      }
    }
    else
    {
      _jxr_wbitstream_uint8(str, val: image->dc_quant_ch[0]);
    }
  }
}


// ========================================================================
// ?_jxr_w_TILE_HEADER_LOWPASS@@YAXPAUjxr_image@@PAUwbitstream@@HII@Z
// EA  : 0x829154B8
// RVA : 0x009154B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_TILE_HEADER_LOWPASS(
        jxr_image *image,
        wbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty)
{
  jxr_tile_qp *tile_quant; // r10
  int v8; // r9
  jxr_component_mode_e component_mode; // r8
  jxr_tile_qp *v10; // r7
  unsigned int num_lp; // r10
  int v12; // r8
  unsigned __int8 *v13; // r9
  unsigned __int8 *lp_qp; // r10
  unsigned int j; // r11
  unsigned int v16; // r11
  int v17; // r8
  unsigned __int8 *v18; // r10
  unsigned int i; // r11
  int v20; // r8
  unsigned __int8 *v21; // r10
  unsigned int k; // r11

  if ( (*((_DWORD *)image + 26) & 0x10000000) == 0 )
  {
    tile_quant = image->tile_quant;
    v8 = (image->tile_rows + 1) * ty + tx;
    component_mode = tile_quant[v8].component_mode;
    v10 = &tile_quant[v8];
    image->lp_component_mode = component_mode;
    num_lp = v10->channel[0].num_lp;
    image->num_lp_qps = num_lp;
    if ( component_mode != JXR_CM_UNIFORM )
    {
      if ( component_mode == JXR_CM_SEPARATE )
      {
        v16 = 0;
        if ( num_lp != 0 )
        {
          do
          {
            image->lp_quant_ch[0][v16] = v10->channel[0].lp_qp[v16];
            ++v16;
          }
          while ( v16 < image->num_lp_qps );
        }
        v17 = 1;
        if ( image->num_channels > 1u )
        {
          v18 = image->lp_quant_ch[1];
          do
          {
            for ( i = 0; i < image->num_lp_qps; ++i )
              v18[i] = v10->channel[1].lp_qp[i];
            ++v17;
            v18 += 16;
          }
          while ( v17 < image->num_channels );
        }
      }
      else if ( (unsigned int)component_mode < JXR_CM_Reserved )
      {
        v12 = 0;
        if ( image->num_channels != 0 )
        {
          v13 = image->lp_quant_ch[0];
          lp_qp = v10->channel[0].lp_qp;
          do
          {
            for ( j = 0; j < image->num_lp_qps; ++j )
              v13[j] = lp_qp[j];
            ++v12;
            lp_qp += 35;
            v13 += 16;
          }
          while ( v12 < image->num_channels );
        }
      }
    }
    else
    {
      v20 = 0;
      if ( image->num_channels != 0 )
      {
        v21 = image->lp_quant_ch[0];
        do
        {
          for ( k = 0; k < image->num_lp_qps; ++k )
            v21[k] = v10->channel[0].lp_qp[k];
          ++v20;
          v21 += 16;
        }
        while ( v20 < image->num_channels );
      }
    }
    _jxr_wbitstream_uint1(str, val: 0);
    _jxr_wbitstream_uint4(str, val: HIBYTE(image->num_lp_qps) - 1);
    _jxr_w_LP_QP(image, str);
  }
}


// ========================================================================
// ?_jxr_w_TILE_HEADER_HIGHPASS@@YAXPAUjxr_image@@PAUwbitstream@@HII@Z
// EA  : 0x829156A0
// RVA : 0x009156A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_TILE_HEADER_HIGHPASS(
        jxr_image *image,
        wbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty)
{
  jxr_tile_qp *tile_quant; // r10
  int v8; // r9
  jxr_component_mode_e component_mode; // r8
  jxr_tile_qp *v10; // r7
  unsigned int num_hp; // r10
  int v12; // r8
  unsigned __int8 *v13; // r9
  unsigned __int8 *hp_qp; // r10
  unsigned int j; // r11
  unsigned int v16; // r11
  int v17; // r8
  unsigned __int8 *v18; // r10
  unsigned int i; // r11
  int v20; // r8
  unsigned __int8 *v21; // r10
  unsigned int k; // r11

  if ( (*((_DWORD *)image + 26) & 0x4000000) == 0 )
  {
    tile_quant = image->tile_quant;
    v8 = (image->tile_rows + 1) * ty + tx;
    component_mode = tile_quant[v8].component_mode;
    v10 = &tile_quant[v8];
    image->hp_component_mode = component_mode;
    num_hp = v10->channel[0].num_hp;
    image->num_hp_qps = num_hp;
    if ( component_mode != JXR_CM_UNIFORM )
    {
      if ( component_mode == JXR_CM_SEPARATE )
      {
        v16 = 0;
        if ( num_hp != 0 )
        {
          do
          {
            image->hp_quant_ch[0][v16] = v10->channel[0].hp_qp[v16];
            ++v16;
          }
          while ( v16 < image->num_hp_qps );
        }
        v17 = 1;
        if ( image->num_channels > 1u )
        {
          v18 = image->hp_quant_ch[1];
          do
          {
            for ( i = 0; i < image->num_hp_qps; ++i )
              v18[i] = v10->channel[1].hp_qp[i];
            ++v17;
            v18 += 16;
          }
          while ( v17 < image->num_channels );
        }
      }
      else if ( (unsigned int)component_mode < JXR_CM_Reserved )
      {
        v12 = 0;
        if ( image->num_channels != 0 )
        {
          v13 = image->hp_quant_ch[0];
          hp_qp = v10->channel[0].hp_qp;
          do
          {
            for ( j = 0; j < image->num_hp_qps; ++j )
              v13[j] = hp_qp[j];
            ++v12;
            hp_qp += 35;
            v13 += 16;
          }
          while ( v12 < image->num_channels );
        }
      }
    }
    else
    {
      v20 = 0;
      if ( image->num_channels != 0 )
      {
        v21 = image->hp_quant_ch[0];
        do
        {
          for ( k = 0; k < image->num_hp_qps; ++k )
            v21[k] = v10->channel[0].hp_qp[k];
          ++v20;
          v21 += 16;
        }
        while ( v20 < image->num_channels );
      }
    }
    _jxr_wbitstream_uint1(str, val: 0);
    _jxr_wbitstream_uint4(str, val: HIBYTE(image->num_hp_qps) - 1);
    _jxr_w_HP_QP(image, str);
  }
}


// ========================================================================
// ?_jxr_w_ENCODE_QP_INDEX@@YAXPAUjxr_image@@PAUwbitstream@@IIIIII@Z
// EA  : 0x82915888
// RVA : 0x00915888
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_ENCODE_QP_INDEX(
        jxr_image *image,
        wbitstream *str,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my,
        unsigned int num_qps,
        unsigned int qp_index)
{
  if ( qp_index != 0 )
  {
    _jxr_wbitstream_uint1(str, val: 1);
    _jxr_wbitstream_uintN(str, val: qp_index - 1, N: bits_per_qp_index[num_qps]);
  }
  else
  {
    _jxr_wbitstream_uint1(str, val: 0);
  }
}


// ========================================================================
// encode_val_dc_yuv
// EA  : 0x829158E8
// RVA : 0x009158E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall encode_val_dc_yuv(wbitstream *image, wbitstream *str, int val)
{
  unsigned __int8 v4; // r4
  int v5; // r4

  if ( (unsigned int)str <= 7 )
  {
    if ( str == (wbitstream *)1 )
    {
      v4 = 0;
LABEL_17:
      _jxr_wbitstream_uint2(str: image, val: v4);
      goto LABEL_18;
    }
    if ( str == (wbitstream *)2 )
    {
      _jxr_wbitstream_uint4(str: image, val: 0);
LABEL_18:
      v5 = 1;
      goto LABEL_19;
    }
    if ( str == (wbitstream *)3 )
    {
      _jxr_wbitstream_uint4(str: image, val: 1u);
      return;
    }
    if ( str == (wbitstream *)4 )
    {
      _jxr_wbitstream_uint2(str: image, val: 3u);
      return;
    }
    if ( str == (wbitstream *)5 )
    {
      _jxr_wbitstream_uint2(str: image, val: 1u);
      v5 = 0;
    }
    else
    {
      if ( str != (wbitstream *)6 )
      {
        if ( str == nullptr )
        {
          _jxr_wbitstream_uint2(str: image, val: 2u);
          return;
        }
        v4 = 1;
        goto LABEL_17;
      }
      _jxr_wbitstream_uint4(str: image, val: 0);
      v5 = 0;
    }
LABEL_19:
    _jxr_wbitstream_uint1(str: image, val: v5);
  }
}


// ========================================================================
// AdaptiveLPPermute
// EA  : 0x829159F8
// RVA : 0x009159F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall AdaptiveLPPermute(jxr_image *image, int *dst, const int *src)
{
  int v3; // r8
  int *v4; // r7
  unsigned int *lopass_scantotals; // r11
  int v6; // r6
  unsigned int v7; // r10
  unsigned int v8; // r9
  unsigned int v9; // r6
  unsigned int v10; // r4
  int v11; // r6
  unsigned int v12; // r10
  unsigned int v13; // r6
  unsigned int v14; // r4
  int v15; // r6
  unsigned int v16; // r10
  unsigned int v17; // r9
  unsigned int v18; // r6
  unsigned int v19; // r4
  int v20; // r6
  unsigned int v21; // r10
  unsigned int v22; // r9
  unsigned int v23; // r6
  unsigned int v24; // r4
  int v25; // r6
  unsigned int v26; // r10
  unsigned int v27; // r9
  unsigned int v28; // r6
  unsigned int v29; // r4

  v3 = 3;
  v4 = dst + 3;
  lopass_scantotals = image->lopass_scantotals;
  do
  {
    v6 = src[*(lopass_scantotals - 15)];
    *(v4 - 2) = v6;
    if ( v6 != 0 )
    {
      v7 = *lopass_scantotals + 1;
      *lopass_scantotals = v7;
      if ( v3 - 2 > 1 )
      {
        v8 = *(lopass_scantotals - 1);
        if ( v7 > v8 )
        {
          v9 = *(lopass_scantotals - 15);
          v10 = *(lopass_scantotals - 16);
          *lopass_scantotals = v8;
          *(lopass_scantotals - 1) = v7;
          *(lopass_scantotals - 16) = v9;
          *(lopass_scantotals - 15) = v10;
        }
      }
    }
    v11 = src[*(lopass_scantotals - 14)];
    *(v4 - 1) = v11;
    if ( v11 != 0 )
    {
      v12 = lopass_scantotals[1] + 1;
      lopass_scantotals[1] = v12;
      if ( v3 - 1 > 1 && v12 > *lopass_scantotals )
      {
        v13 = *(lopass_scantotals - 14);
        v14 = *(lopass_scantotals - 15);
        lopass_scantotals[1] = *lopass_scantotals;
        *lopass_scantotals = v12;
        *(lopass_scantotals - 15) = v13;
        *(lopass_scantotals - 14) = v14;
      }
    }
    v15 = src[*(lopass_scantotals - 13)];
    *v4 = v15;
    if ( v15 != 0 )
    {
      v16 = lopass_scantotals[2] + 1;
      lopass_scantotals[2] = v16;
      if ( v3 > 1 )
      {
        v17 = lopass_scantotals[1];
        if ( v16 > v17 )
        {
          v18 = *(lopass_scantotals - 13);
          v19 = *(lopass_scantotals - 14);
          lopass_scantotals[2] = v17;
          lopass_scantotals[1] = v16;
          *(lopass_scantotals - 14) = v18;
          *(lopass_scantotals - 13) = v19;
        }
      }
    }
    v20 = src[*(lopass_scantotals - 12)];
    v4[1] = v20;
    if ( v20 != 0 )
    {
      v21 = lopass_scantotals[3] + 1;
      lopass_scantotals[3] = v21;
      if ( v3 + 1 > 1 )
      {
        v22 = lopass_scantotals[2];
        if ( v21 > v22 )
        {
          v23 = *(lopass_scantotals - 12);
          v24 = *(lopass_scantotals - 13);
          lopass_scantotals[3] = v22;
          lopass_scantotals[2] = v21;
          *(lopass_scantotals - 13) = v23;
          *(lopass_scantotals - 12) = v24;
        }
      }
    }
    v25 = src[*(lopass_scantotals - 11)];
    v4[2] = v25;
    if ( v25 != 0 )
    {
      v26 = lopass_scantotals[4] + 1;
      lopass_scantotals[4] = v26;
      if ( v3 + 2 > 1 )
      {
        v27 = lopass_scantotals[3];
        if ( v26 > v27 )
        {
          v28 = *(lopass_scantotals - 11);
          v29 = *(lopass_scantotals - 12);
          lopass_scantotals[4] = v27;
          lopass_scantotals[3] = v26;
          *(lopass_scantotals - 12) = v28;
          *(lopass_scantotals - 11) = v29;
        }
      }
    }
    v3 += 5;
    lopass_scantotals += 5;
    v4 += 5;
  }
  while ( v3 - 2 < 16 );
}


// ========================================================================
// FixedLPPermuteUV
// EA  : 0x82915BC0
// RVA : 0x00915BC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall FixedLPPermuteUV(jxr_image *image, int *dst, int (*src)[16])
{
  int v3; // r6
  int v4; // r10
  int v5; // ctr
  int *v6; // r7
  int use_clr_fmt; // r8
  int v8; // r11
  int v9; // r9
  int *v10; // r10
  int v11; // ctr

  v3 = 14;
  if ( image->use_clr_fmt == 1 )
    v3 = 6;
  v4 = 0;
  v5 = v3;
  v6 = dst;
  do
  {
    use_clr_fmt = image->use_clr_fmt;
    v8 = v4 >> 1;
    v9 = (v4 & 1) + 1;
    if ( use_clr_fmt == 1 )
      ++v8;
    if ( use_clr_fmt == 2 )
      v8 = remap_arr[v8];
    if ( use_clr_fmt == 1 )
      v8 = transpose420_0[v8];
    if ( use_clr_fmt == 2 )
      v8 = transpose422_0[v8];
    ++v4;
    *++v6 = (*src)[16 * v9 + v8];
    --v5;
  }
  while ( v5 != 0 );
  v10 = &dst[v3];
  v11 = 15 - v3;
  do
  {
    *++v10 = 0;
    --v11;
  }
  while ( v11 != 0 );
}


// ========================================================================
// AdaptiveHPPermute
// EA  : 0x82915CB0
// RVA : 0x00915CB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall AdaptiveHPPermute(jxr_image *image, int *dst, const int *src, int mbhp_pred_mode)
{
  int v4; // r8
  int *v5; // r7
  unsigned int *hipass_ver_scantotals; // r11
  int v7; // r6
  unsigned int v8; // r10
  unsigned int v9; // r9
  unsigned int v10; // r6
  unsigned int v11; // r4
  int v12; // r6
  unsigned int v13; // r10
  unsigned int v14; // r6
  unsigned int v15; // r4
  int v16; // r6
  unsigned int v17; // r10
  unsigned int v18; // r9
  unsigned int v19; // r6
  unsigned int v20; // r4
  int v21; // r6
  unsigned int v22; // r10
  unsigned int v23; // r9
  unsigned int v24; // r6
  unsigned int v25; // r4
  int v26; // r6
  unsigned int v27; // r10
  unsigned int v28; // r9
  unsigned int v29; // r6
  unsigned int v30; // r4
  unsigned int *hipass_hor_scantotals; // r11
  int v32; // r6
  unsigned int v33; // r10
  unsigned int v34; // r9
  unsigned int v35; // r6
  unsigned int v36; // r4
  int v37; // r6
  unsigned int v38; // r10
  unsigned int v39; // r6
  unsigned int v40; // r4
  int v41; // r6
  unsigned int v42; // r10
  unsigned int v43; // r9
  unsigned int v44; // r6
  unsigned int v45; // r4
  int v46; // r6
  unsigned int v47; // r10
  unsigned int v48; // r9
  unsigned int v49; // r6
  unsigned int v50; // r4
  int v51; // r6
  unsigned int v52; // r10
  unsigned int v53; // r9
  unsigned int v54; // r6
  unsigned int v55; // r4

  v4 = 3;
  v5 = dst + 3;
  if ( mbhp_pred_mode == 1 )
  {
    hipass_ver_scantotals = image->hipass_ver_scantotals;
    do
    {
      v7 = src[*(hipass_ver_scantotals - 15)];
      *(v5 - 2) = v7;
      if ( v7 != 0 )
      {
        v8 = *hipass_ver_scantotals + 1;
        *hipass_ver_scantotals = v8;
        if ( v4 - 2 > 1 )
        {
          v9 = *(hipass_ver_scantotals - 1);
          if ( v8 > v9 )
          {
            v10 = *(hipass_ver_scantotals - 15);
            v11 = *(hipass_ver_scantotals - 16);
            *hipass_ver_scantotals = v9;
            *(hipass_ver_scantotals - 1) = v8;
            *(hipass_ver_scantotals - 16) = v10;
            *(hipass_ver_scantotals - 15) = v11;
          }
        }
      }
      v12 = src[*(hipass_ver_scantotals - 14)];
      *(v5 - 1) = v12;
      if ( v12 != 0 )
      {
        v13 = hipass_ver_scantotals[1] + 1;
        hipass_ver_scantotals[1] = v13;
        if ( v4 - 1 > 1 && v13 > *hipass_ver_scantotals )
        {
          v14 = *(hipass_ver_scantotals - 14);
          v15 = *(hipass_ver_scantotals - 15);
          hipass_ver_scantotals[1] = *hipass_ver_scantotals;
          *hipass_ver_scantotals = v13;
          *(hipass_ver_scantotals - 15) = v14;
          *(hipass_ver_scantotals - 14) = v15;
        }
      }
      v16 = src[*(hipass_ver_scantotals - 13)];
      *v5 = v16;
      if ( v16 != 0 )
      {
        v17 = hipass_ver_scantotals[2] + 1;
        hipass_ver_scantotals[2] = v17;
        if ( v4 > 1 )
        {
          v18 = hipass_ver_scantotals[1];
          if ( v17 > v18 )
          {
            v19 = *(hipass_ver_scantotals - 13);
            v20 = *(hipass_ver_scantotals - 14);
            hipass_ver_scantotals[2] = v18;
            hipass_ver_scantotals[1] = v17;
            *(hipass_ver_scantotals - 14) = v19;
            *(hipass_ver_scantotals - 13) = v20;
          }
        }
      }
      v21 = src[*(hipass_ver_scantotals - 12)];
      v5[1] = v21;
      if ( v21 != 0 )
      {
        v22 = hipass_ver_scantotals[3] + 1;
        hipass_ver_scantotals[3] = v22;
        if ( v4 + 1 > 1 )
        {
          v23 = hipass_ver_scantotals[2];
          if ( v22 > v23 )
          {
            v24 = *(hipass_ver_scantotals - 12);
            v25 = *(hipass_ver_scantotals - 13);
            hipass_ver_scantotals[3] = v23;
            hipass_ver_scantotals[2] = v22;
            *(hipass_ver_scantotals - 13) = v24;
            *(hipass_ver_scantotals - 12) = v25;
          }
        }
      }
      v26 = src[*(hipass_ver_scantotals - 11)];
      v5[2] = v26;
      if ( v26 != 0 )
      {
        v27 = hipass_ver_scantotals[4] + 1;
        hipass_ver_scantotals[4] = v27;
        if ( v4 + 2 > 1 )
        {
          v28 = hipass_ver_scantotals[3];
          if ( v27 > v28 )
          {
            v29 = *(hipass_ver_scantotals - 11);
            v30 = *(hipass_ver_scantotals - 12);
            hipass_ver_scantotals[4] = v28;
            hipass_ver_scantotals[3] = v27;
            *(hipass_ver_scantotals - 12) = v29;
            *(hipass_ver_scantotals - 11) = v30;
          }
        }
      }
      v4 += 5;
      hipass_ver_scantotals += 5;
      v5 += 5;
    }
    while ( v4 - 2 < 16 );
  }
  else
  {
    hipass_hor_scantotals = image->hipass_hor_scantotals;
    do
    {
      v32 = src[*(hipass_hor_scantotals - 15)];
      *(v5 - 2) = v32;
      if ( v32 != 0 )
      {
        v33 = *hipass_hor_scantotals + 1;
        *hipass_hor_scantotals = v33;
        if ( v4 - 2 > 1 )
        {
          v34 = *(hipass_hor_scantotals - 1);
          if ( v33 > v34 )
          {
            v35 = *(hipass_hor_scantotals - 15);
            v36 = *(hipass_hor_scantotals - 16);
            *hipass_hor_scantotals = v34;
            *(hipass_hor_scantotals - 1) = v33;
            *(hipass_hor_scantotals - 16) = v35;
            *(hipass_hor_scantotals - 15) = v36;
          }
        }
      }
      v37 = src[*(hipass_hor_scantotals - 14)];
      *(v5 - 1) = v37;
      if ( v37 != 0 )
      {
        v38 = hipass_hor_scantotals[1] + 1;
        hipass_hor_scantotals[1] = v38;
        if ( v4 - 1 > 1 && v38 > *hipass_hor_scantotals )
        {
          v39 = *(hipass_hor_scantotals - 14);
          v40 = *(hipass_hor_scantotals - 15);
          hipass_hor_scantotals[1] = *hipass_hor_scantotals;
          *hipass_hor_scantotals = v38;
          *(hipass_hor_scantotals - 15) = v39;
          *(hipass_hor_scantotals - 14) = v40;
        }
      }
      v41 = src[*(hipass_hor_scantotals - 13)];
      *v5 = v41;
      if ( v41 != 0 )
      {
        v42 = hipass_hor_scantotals[2] + 1;
        hipass_hor_scantotals[2] = v42;
        if ( v4 > 1 )
        {
          v43 = hipass_hor_scantotals[1];
          if ( v42 > v43 )
          {
            v44 = *(hipass_hor_scantotals - 13);
            v45 = *(hipass_hor_scantotals - 14);
            hipass_hor_scantotals[2] = v43;
            hipass_hor_scantotals[1] = v42;
            *(hipass_hor_scantotals - 14) = v44;
            *(hipass_hor_scantotals - 13) = v45;
          }
        }
      }
      v46 = src[*(hipass_hor_scantotals - 12)];
      v5[1] = v46;
      if ( v46 != 0 )
      {
        v47 = hipass_hor_scantotals[3] + 1;
        hipass_hor_scantotals[3] = v47;
        if ( v4 + 1 > 1 )
        {
          v48 = hipass_hor_scantotals[2];
          if ( v47 > v48 )
          {
            v49 = *(hipass_hor_scantotals - 12);
            v50 = *(hipass_hor_scantotals - 13);
            hipass_hor_scantotals[3] = v48;
            hipass_hor_scantotals[2] = v47;
            *(hipass_hor_scantotals - 13) = v49;
            *(hipass_hor_scantotals - 12) = v50;
          }
        }
      }
      v51 = src[*(hipass_hor_scantotals - 11)];
      v5[2] = v51;
      if ( v51 != 0 )
      {
        v52 = hipass_hor_scantotals[4] + 1;
        hipass_hor_scantotals[4] = v52;
        if ( v4 + 2 > 1 )
        {
          v53 = hipass_hor_scantotals[3];
          if ( v52 > v53 )
          {
            v54 = *(hipass_hor_scantotals - 11);
            v55 = *(hipass_hor_scantotals - 12);
            hipass_hor_scantotals[4] = v53;
            hipass_hor_scantotals[3] = v52;
            *(hipass_hor_scantotals - 12) = v54;
            *(hipass_hor_scantotals - 11) = v55;
          }
        }
      }
      v4 += 5;
      hipass_hor_scantotals += 5;
      v5 += 5;
    }
    while ( v4 - 2 < 16 );
  }
}


// ========================================================================
// collect_lp_input
// EA  : 0x82916040
// RVA : 0x00916040
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall collect_lp_input(jxr_image *image, int ch, int tx, int mx, int (*LPInput)[16], char model_bits)
{
  int result; // r3
  int v8; // r11
  int use_clr_fmt; // r10
  int v10; // r28
  int v11; // r30
  int v12; // r29
  int v13; // ctr
  int v14; // r4
  int v15; // r5
  int v16; // r9
  int v17; // r10
  int v18; // r11
  int v19; // r11

  result = 0;
  v8 = 16;
  if ( ch > 0 )
  {
    use_clr_fmt = image->use_clr_fmt;
    if ( use_clr_fmt == 2 )
      v8 = 8;
    if ( use_clr_fmt == 1 )
      v8 = 4;
  }
  v10 = 1;
  v11 = tx;
  v12 = 28 * (ch + 5);
  v13 = v8 - 1;
  v14 = 16 * ch;
  v15 = 4;
  do
  {
    v16 = 0;
    v17 = v14 + v10;
    v18 = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v11] + mx)
                                + *(int *)((char *)&image->user_flags + v12))
                    + v15);
    (*LPInput)[v17] = v18;
    if ( v18 < 0 )
    {
      v16 = 1;
      (*LPInput)[v17] = -v18;
    }
    v19 = (*LPInput)[v17] >> model_bits;
    (*LPInput)[v17] = v19;
    if ( v19 != 0 )
    {
      ++result;
      if ( v16 != 0 )
        (*LPInput)[v17] = -v19;
    }
    ++v10;
    v15 += 4;
    --v13;
  }
  while ( v13 != 0 );
  return result;
}


// ========================================================================
// encode_val_1
// EA  : 0x82916118
// RVA : 0x00916118
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall encode_val_1(
        jxr_image *image,
        wbitstream *str,
        adaptive_vlc_s *vlc,
        unsigned int val1,
        unsigned int chr_cbp)
{
  unsigned int use_clr_fmt; // r11
  int v9; // r30

  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt > 6 )
    return;
  if ( use_clr_fmt == 1 || use_clr_fmt == 2 || use_clr_fmt == 3 && image->use_clr_fmt != 0 )
  {
    v9 = val1;
    if ( (int)val1 > 8 )
      v9 = 8;
    if ( vlc->table != 0 )
    {
      if ( (unsigned int)v9 <= 8 )
      {
        switch ( v9 )
        {
          case 0:
            goto LABEL_19;
          case 1:
            _jxr_wbitstream_uint2(str, val: 0);
            _jxr_wbitstream_uint1(str, val: 1);
            return;
          case 2:
            _jxr_wbitstream_uint2(str, val: 1u);
            _jxr_wbitstream_uint1(str, val: 0);
            return;
          case 3:
            goto LABEL_63;
          case 4:
            _jxr_wbitstream_uint4(str, val: 0);
            goto LABEL_65;
          case 5:
            goto LABEL_48;
          case 6:
            _jxr_wbitstream_uint4(str, val: 0);
            _jxr_wbitstream_uint1(str, val: 1);
            break;
          default:
            _jxr_wbitstream_uint4(str, val: 0);
            _jxr_wbitstream_uint2(str, val: 0);
            if ( v9 != 7 )
              goto LABEL_60;
            _jxr_wbitstream_uint1(str, val: 0);
            break;
        }
LABEL_69:
        if ( chr_cbp != 0 )
        {
          if ( chr_cbp == 1 )
          {
            _jxr_wbitstream_uint2(str, val: 1u);
          }
          else if ( chr_cbp < 3 )
          {
            _jxr_wbitstream_uint2(str, val: 0);
          }
        }
        else
        {
          _jxr_wbitstream_uint1(str, val: 1);
        }
LABEL_75:
        if ( v9 != 8 )
          return;
        if ( val1 == 8 )
          goto LABEL_19;
        if ( val1 != 9 )
        {
          if ( val1 - 8 < 3 )
            _jxr_wbitstream_uint2(str, val: 0);
          return;
        }
LABEL_65:
        _jxr_wbitstream_uint2(str, val: 1u);
        return;
      }
    }
    else if ( (unsigned int)v9 <= 8 )
    {
      switch ( v9 )
      {
        case 1:
          _jxr_wbitstream_uint1(str, val: 0);
          goto LABEL_47;
        case 2:
          _jxr_wbitstream_uint4(str, val: 2u);
          return;
        case 3:
          _jxr_wbitstream_uint4(str, val: 0);
          _jxr_wbitstream_uint1(str, val: 1);
          return;
        case 4:
          _jxr_wbitstream_uint4(str, val: 1u);
          _jxr_wbitstream_uint1(str, val: 0);
          return;
        default:
          break;
      }
      if ( v9 != 5 )
      {
        if ( v9 != 6 )
        {
          if ( v9 != 7 )
          {
            if ( v9 == 0 )
            {
LABEL_46:
              _jxr_wbitstream_uint1(str, val: 0);
              _jxr_wbitstream_uint2(str, val: 2u);
              return;
            }
            _jxr_wbitstream_uint4(str, val: 3u);
            goto LABEL_69;
          }
          _jxr_wbitstream_uint4(str, val: 1u);
          goto LABEL_60;
        }
LABEL_48:
        _jxr_wbitstream_uint1(str, val: 0);
        _jxr_wbitstream_uint2(str, val: 3u);
        goto LABEL_69;
      }
LABEL_60:
      _jxr_wbitstream_uint1(str, val: 1);
      goto LABEL_69;
    }
    if ( v9 < 5 )
      goto LABEL_75;
    goto LABEL_69;
  }
  if ( use_clr_fmt == 4 && image->use_clr_fmt != 0 || use_clr_fmt != 5 || image->use_clr_fmt == 0 )
  {
    if ( vlc->table == 0 )
    {
      if ( val1 > 4 )
        return;
      if ( val1 != 0 )
      {
        if ( val1 != 1 )
        {
          if ( val1 != 2 )
          {
            if ( val1 != 3 )
            {
LABEL_63:
              _jxr_wbitstream_uint4(str, val: 1u);
              return;
            }
LABEL_47:
            _jxr_wbitstream_uint4(str, val: 0);
            return;
          }
          _jxr_wbitstream_uint1(str, val: 0);
        }
        _jxr_wbitstream_uint1(str, val: 0);
      }
      goto LABEL_19;
    }
    if ( val1 <= 4 )
    {
      if ( val1 != 0 )
      {
        if ( val1 == 1 )
        {
          _jxr_wbitstream_uint1(str, val: 0);
          _jxr_wbitstream_uint2(str, val: 0);
          return;
        }
        if ( val1 == 2 )
        {
          _jxr_wbitstream_uint1(str, val: 0);
          _jxr_wbitstream_uint2(str, val: 1u);
          return;
        }
        if ( val1 != 3 )
        {
          _jxr_wbitstream_uint1(str, val: 0);
          _jxr_wbitstream_uint2(str, val: 3u);
          return;
        }
        goto LABEL_46;
      }
LABEL_19:
      _jxr_wbitstream_uint1(str, val: 1);
    }
  }
}


// ========================================================================
// w_REFINE_CBP
// EA  : 0x829164F8
// RVA : 0x009164F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_REFINE_CBP(jxr_image *image, wbitstream *str, int cbp_block_mask)
{
  unsigned int v5; // r30
  int table; // r8
  int v7; // r4

  v5 = (cbp_block_mask & 1) != 0;
  if ( (cbp_block_mask & 2) != 0 )
    ++v5;
  if ( (cbp_block_mask & 4) != 0 )
    ++v5;
  if ( (cbp_block_mask & 8) != 0 )
    ++v5;
  table = image->vlc_table[12].table;
  image->vlc_table[12].discriminant += Num_BLKCBP_Delta5[v5];
  if ( table == 0 )
  {
    if ( v5 > 4 )
      goto LABEL_18;
    if ( v5 != 0 )
    {
      if ( v5 != 1 )
      {
        if ( v5 != 2 )
        {
          if ( v5 == 3 )
          {
            _jxr_wbitstream_uint1(str, val: 0);
            _jxr_wbitstream_uint1(str, val: 0);
            _jxr_wbitstream_uint1(str, val: 0);
            v7 = 0;
            goto LABEL_17;
          }
          _jxr_wbitstream_uint1(str, val: 0);
        }
        _jxr_wbitstream_uint1(str, val: 0);
      }
      _jxr_wbitstream_uint1(str, val: 0);
    }
LABEL_16:
    v7 = 1;
LABEL_17:
    _jxr_wbitstream_uint1(str, val: v7);
    goto LABEL_18;
  }
  if ( v5 == 0 )
    goto LABEL_16;
  _jxr_wbitstream_uint1(str, val: 0);
  _jxr_wbitstream_uint2(str, val: v5 - 1);
LABEL_18:
  switch ( cbp_block_mask )
  {
    case 1:
    case 3:
    case 14:
      _jxr_wbitstream_uint2(str, val: 0);
      return;
    case 2:
    case 5:
    case 13:
      goto LABEL_25;
    case 4:
    case 11:
      goto LABEL_27;
    case 6:
      _jxr_wbitstream_uint1(str, val: 1);
      _jxr_wbitstream_uint2(str, val: 0);
      return;
    case 7:
    case 8:
      goto LABEL_29;
    case 9:
      _jxr_wbitstream_uint1(str, val: 1);
LABEL_25:
      _jxr_wbitstream_uint2(str, val: 1u);
      return;
    case 10:
      _jxr_wbitstream_uint1(str, val: 1);
LABEL_27:
      _jxr_wbitstream_uint2(str, val: 2u);
      break;
    case 12:
      _jxr_wbitstream_uint1(str, val: 1);
LABEL_29:
      _jxr_wbitstream_uint2(str, val: 3u);
      break;
    default:
      return;
  }
}


// ========================================================================
// w_REFINE_CBP_CHR
// EA  : 0x82916710
// RVA : 0x00916710
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_REFINE_CBP_CHR(wbitstream *image, wbitstream *str, int cbp_block_mask)
{
  int v5; // r11
  unsigned int v6; // r11
  int v7; // r4
  unsigned __int8 v8; // r4

  v5 = ((unsigned __int8)str & 1) != 0;
  if ( ((unsigned __int8)str & 2) != 0 )
    ++v5;
  if ( ((unsigned __int8)str & 4) != 0 )
    ++v5;
  if ( ((unsigned __int8)str & 8) != 0 )
    ++v5;
  v6 = v5 - 1;
  if ( v6 <= 3 )
  {
    if ( v6 != 0 )
    {
      if ( v6 == 1 )
      {
        _jxr_wbitstream_uint2(str: image, val: 1u);
        goto LABEL_16;
      }
      if ( v6 == 2 )
      {
        _jxr_wbitstream_uint2(str: image, val: 0);
        v7 = 0;
LABEL_15:
        _jxr_wbitstream_uint1(str: image, val: v7);
        goto LABEL_16;
      }
      _jxr_wbitstream_uint2(str: image, val: 0);
    }
    v7 = 1;
    goto LABEL_15;
  }
LABEL_16:
  switch ( (unsigned int)str )
  {
    case 1u:
    case 3u:
    case 0xEu:
      v8 = 0;
      goto LABEL_25;
    case 2u:
    case 5u:
    case 0xDu:
      goto LABEL_20;
    case 4u:
    case 0xBu:
      goto LABEL_22;
    case 6u:
      _jxr_wbitstream_uint1(str: image, val: 1);
      v8 = 0;
      goto LABEL_25;
    case 7u:
    case 8u:
      goto LABEL_24;
    case 9u:
      _jxr_wbitstream_uint1(str: image, val: 1);
LABEL_20:
      v8 = 1;
      goto LABEL_25;
    case 0xAu:
      _jxr_wbitstream_uint1(str: image, val: 1);
LABEL_22:
      v8 = 2;
      goto LABEL_25;
    case 0xCu:
      _jxr_wbitstream_uint1(str: image, val: 1);
LABEL_24:
      v8 = 3;
LABEL_25:
      _jxr_wbitstream_uint2(str: image, val: v8);
      break;
    default:
      return;
  }
}


// ========================================================================
// w_BLOCK_FLEXBITS
// EA  : 0x829168A0
// RVA : 0x009168A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_BLOCK_FLEXBITS(
        jxr_image *image,
        wbitstream *str,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my,
        unsigned int ch,
        unsigned int bl,
        unsigned int model_bits)
{
  unsigned int v10; // r11
  int v13; // r18
  unsigned int v14; // r11
  int v15; // r22
  int v16; // r23
  unsigned int v17; // r24
  unsigned int v18; // r26
  unsigned int v19; // r25
  _DWORD *v20; // r28
  int v21; // r27
  int v22; // r11
  int v23; // r30
  _DWORD v24[47]; // [sp+54h] [-BCh] BYREF

  v10 = *((_DWORD *)image + 9);
  v24[0] = 4;
  v24[1] = 8;
  v24[2] = 12;
  v24[4] = 5;
  v24[5] = 9;
  v24[6] = 13;
  v24[7] = 2;
  v24[8] = 6;
  v24[9] = 10;
  v13 = 15;
  v14 = v10 >> 28;
  v24[3] = 1;
  v24[14] = 15;
  v24[10] = 14;
  v24[11] = 3;
  v24[12] = 7;
  v24[13] = 11;
  if ( v14 <= ch )
  {
    v15 = ch - v14;
    if ( ch != v14 )
    {
      v16 = __ROL4__(1, v15) - 1;
      v17 = 28 * (mx + 5);
      v18 = tx;
      v19 = 15 * my;
      v20 = v24;
      do
      {
        v21 = 0;
        v22 = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v18] + ty)
                                    + *(int *)((char *)&image->user_flags + v17))
                        + 4 * (*v20 + v19 + 15));
        if ( v22 < 0 )
        {
          v21 = 1;
          v22 = -v22;
        }
        v23 = v22 >> (*((_DWORD *)image + 9) >> 28);
        _jxr_wbitstream_uintN(str, val: v16 & v23, N: v15);
        if ( (~v16 & v23) == 0 && (v16 & v23) != 0 )
          _jxr_wbitstream_uint1(str, val: v21);
        --v13;
        ++v20;
      }
      while ( v13 != 0 );
    }
  }
}


// ========================================================================
// encode_abslevel_index
// EA  : 0x82916A08
// RVA : 0x00916A08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall encode_abslevel_index(jxr_image *image, wbitstream *str, unsigned int abslevel_index, int vlc_select)
{
  unsigned __int8 v5; // r4

  if ( image->vlc_table[vlc_select].table != 0 )
  {
    if ( abslevel_index > 6 )
      return;
    if ( abslevel_index != 1 )
    {
      switch ( abslevel_index )
      {
        case 2u:
          goto LABEL_22;
        case 3u:
          goto LABEL_23;
        case 4u:
LABEL_24:
          _jxr_wbitstream_uint4(str, val: 0);
          _jxr_wbitstream_uint1(str, val: 1);
          return;
        case 5u:
          _jxr_wbitstream_uint4(str, val: 0);
          v5 = 0;
          goto LABEL_27;
        case 0u:
          _jxr_wbitstream_uint1(str, val: 1);
          return;
        default:
          break;
      }
      _jxr_wbitstream_uint4(str, val: 0);
    }
LABEL_26:
    v5 = 1;
    goto LABEL_27;
  }
  if ( abslevel_index > 6 )
    return;
  switch ( abslevel_index )
  {
    case 0u:
      goto LABEL_26;
    case 1u:
      v5 = 2;
      break;
    case 2u:
      v5 = 3;
      break;
    case 3u:
LABEL_22:
      _jxr_wbitstream_uint2(str, val: 0);
      _jxr_wbitstream_uint1(str, val: 1);
      return;
    case 4u:
LABEL_23:
      _jxr_wbitstream_uint4(str, val: 1u);
      return;
    case 5u:
      _jxr_wbitstream_uint4(str, val: 0);
      _jxr_wbitstream_uint1(str, val: 0);
      return;
    default:
      goto LABEL_24;
  }
LABEL_27:
  _jxr_wbitstream_uint2(str, val: v5);
}


// ========================================================================
// w_DECODE_FIRST_INDEX
// EA  : 0x82916BA0
// RVA : 0x00916BA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_DECODE_FIRST_INDEX(
        jxr_image *image,
        wbitstream *str,
        unsigned int chroma_flag,
        int band,
        int first_index)
{
  int v8; // r29
  int *v9; // r30
  int v10; // r5
  int v11; // r26
  int bits; // r25
  int v13; // r7
  int v14; // r11
  int v15; // r6
  int v16; // r8
  _DWORD v17[68]; // [sp+50h] [-110h] BYREF

  v8 = 0;
  if ( band == 1 )
  {
    v8 = chroma_flag == 0 ? 2 : 9;
  }
  else if ( band == 2 )
  {
    v8 = ((_cntlzw(chroma_flag) & 0x20) == 0) + 16;
  }
  v9 = &image->user_flags + 5 * v8;
  v10 = 12 * v9[177] + first_index;
  LOBYTE(v11) = first_index_vlc[0][v10].len;
  bits = first_index_vlc[0][v10].bits;
  if ( (_BYTE)v11 != 0 )
  {
    do
    {
      _jxr_wbitstream_uint1(str, val: (bits & 0x80) != 0);
      bits = (2 * bits) & 0xFE;
      v11 = (unsigned __int8)(v11 - 1);
    }
    while ( v11 != 0 );
  }
  v13 = v9[179];
  v17[5] = 0;
  v17[0] = 1;
  v17[1] = 1;
  v17[2] = 1;
  v17[8] = 2;
  v17[12] = 2;
  v17[13] = 2;
  v17[27] = 2;
  v17[3] = 1;
  v17[4] = 1;
  v17[9] = 1;
  v17[25] = 1;
  v17[34] = 1;
  v17[35] = 1;
  v17[37] = 1;
  v17[39] = 1;
  v17[18] = -2;
  v17[22] = -2;
  v17[32] = -2;
  v17[40] = -2;
  v17[44] = -2;
  v17[46] = -2;
  v14 = 20 * (v8 + 35);
  v17[47] = -2;
  v17[6] = 0;
  v17[7] = -1;
  v17[10] = 0;
  v17[11] = 0;
  memset(&v17[14], 255, 12);
  v17[17] = 0;
  v17[19] = -1;
  v15 = v9[178];
  v17[20] = 0;
  v17[21] = 0;
  v17[23] = -1;
  v17[24] = -1;
  v17[26] = 0;
  memset(&v17[28], 0, 16);
  v17[33] = 0;
  v17[36] = 0;
  v17[38] = 0;
  v17[41] = 0;
  v17[42] = -1;
  v17[43] = -1;
  v17[45] = -1;
  v16 = *(int *)((char *)&image->user_flags + v14);
  v9[176] += v17[12 * v13 + first_index];
  *(int *)((char *)&image->user_flags + v14) = v17[12 * v15 + first_index] + v16;
}


// ========================================================================
// w_DECODE_INDEX
// EA  : 0x82916D98
// RVA : 0x00916D98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_DECODE_INDEX(
        jxr_image *image,
        wbitstream *str,
        int location,
        int chroma_flag,
        int band,
        unsigned int context,
        unsigned int index_code)
{
  int v10; // r29
  BOOL v11; // r11
  BOOL v12; // r11
  int *v13; // r30
  unsigned int v14; // r5
  int v15; // r27
  unsigned __int8 bits; // r25
  int v17; // r9
  int v18; // r10
  int v19; // r8
  unsigned int v20; // r5
  int v21; // r8
  _DWORD v22[36]; // [sp+50h] [-90h] BYREF

  v10 = 0;
  if ( band == 1 )
  {
    v12 = (_cntlzw(context) & 0x20) == 0;
    v10 = v12 + 10;
    if ( chroma_flag == 0 )
      v10 = v12 + 7;
  }
  else if ( band == 2 )
  {
    v11 = (_cntlzw(context) & 0x20) == 0;
    if ( chroma_flag != 0 )
      v10 = v11 + 18;
    else
      v10 = v11 + 14;
  }
  if ( location > 15 )
  {
    _jxr_wbitstream_uint1(str, val: index_code);
    return;
  }
  if ( location == 15 )
  {
    if ( index_code > 3 )
      return;
    if ( index_code == 1 )
    {
      _jxr_wbitstream_uint1(str, val: 1);
LABEL_17:
      _jxr_wbitstream_uint2(str, val: 2u);
      return;
    }
    if ( index_code == 2 )
      goto LABEL_17;
    if ( index_code != 0 )
    {
      _jxr_wbitstream_uint1(str, val: 1);
      _jxr_wbitstream_uint2(str, val: 3u);
    }
    else
    {
      _jxr_wbitstream_uint1(str, val: 0);
    }
  }
  else
  {
    v13 = &image->user_flags + 5 * v10;
    v14 = 6 * v13[177] + index_code;
    LOBYTE(v15) = index1_vlc[0][v14].len;
    bits = index1_vlc[0][v14].bits;
    if ( (_BYTE)v15 != 0 )
    {
      do
      {
        _jxr_wbitstream_uint1(str, val: (bits & 0x80) != 0);
        bits *= 2;
        v15 = (unsigned __int8)(v15 - 1);
      }
      while ( v15 != 0 );
    }
    v17 = v13[179];
    v22[0] = -1;
    v22[1] = 1;
    v22[12] = -1;
    v22[13] = -1;
    v22[9] = 2;
    v22[2] = 1;
    v22[3] = 1;
    v22[5] = 1;
    v22[15] = 1;
    v22[4] = 0;
    v22[7] = 0;
    v22[8] = 0;
    v18 = 20 * (v10 + 35);
    v19 = v13[178];
    v22[6] = -2;
    v22[10] = 0;
    v22[11] = 0;
    v22[14] = 0;
    v22[16] = -2;
    v22[17] = 0;
    v20 = 6 * v19 + index_code;
    v21 = *(int *)((char *)&image->user_flags + v18);
    v13[176] += v22[6 * v17 + index_code];
    *(int *)((char *)&image->user_flags + v18) = v22[v20] + v21;
  }
}


// ========================================================================
// w_DECODE_RUN
// EA  : 0x82916FC8
// RVA : 0x00916FC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_DECODE_RUN(wbitstream *image, wbitstream *str, int max_run, int run)
{
  wbitstream *v4; // r28
  unsigned int v6; // r7
  int i; // r10
  int v8; // r30
  int v9; // r31
  unsigned __int8 v10; // r4

  v4 = image;
  if ( (int)str >= 5 )
  {
    v6 = 0;
    for ( i = 5 * RunBin[(_DWORD)str]; ; ++i )
    {
      if ( (int)(v6 + 5 * RunBin[(_DWORD)str]) >= 0 )
      {
        v8 = Remap[i];
        if ( v8 <= max_run )
        {
          v9 = RunFixedLen[i];
          if ( max_run < (1 << v9) + v8 )
            break;
        }
      }
      if ( (int)++v6 >= 5 )
        return;
    }
    if ( v6 > 4 )
      goto LABEL_36;
    if ( v6 != 1 )
    {
      if ( v6 != 2 )
      {
        if ( v6 == 3 )
        {
          v10 = 0;
        }
        else
        {
          if ( v6 == 0 )
          {
            _jxr_wbitstream_uint1(str: image, val: 1);
            goto LABEL_36;
          }
          v10 = 1;
        }
        _jxr_wbitstream_uint4(str: image, val: v10);
LABEL_36:
        if ( v9 > 0 )
          _jxr_wbitstream_uintN(str: v4, val: max_run - v8, N: v9);
        return;
      }
      _jxr_wbitstream_uint1(str: image, val: 0);
    }
    _jxr_wbitstream_uint2(str: v4, val: 1u);
    goto LABEL_36;
  }
  if ( str == (wbitstream *)2 )
  {
    if ( max_run == 2 )
      _jxr_wbitstream_uint1(str: image, val: 0);
    else
      _jxr_wbitstream_uint1(str: image, val: 1);
  }
  else
  {
    if ( str != (wbitstream *)3 )
    {
      if ( str != (wbitstream *)4 )
        return;
      switch ( max_run )
      {
        case 1:
          goto LABEL_10;
        case 2:
          goto LABEL_9;
        case 3:
          _jxr_wbitstream_uint1(str: image, val: 0);
LABEL_9:
          _jxr_wbitstream_uint1(str: v4, val: 0);
LABEL_10:
          _jxr_wbitstream_uint1(str: v4, val: 1);
          return;
        default:
          break;
      }
      _jxr_wbitstream_uint1(str: image, val: 0);
      image = v4;
      goto LABEL_12;
    }
    if ( max_run == 1 )
      goto LABEL_10;
    if ( max_run != 2 )
    {
LABEL_12:
      _jxr_wbitstream_uint1(str: image, val: 0);
      _jxr_wbitstream_uint1(str: v4, val: 0);
      return;
    }
    _jxr_wbitstream_uint1(str: image, val: 0);
    _jxr_wbitstream_uint1(str: v4, val: 1);
  }
}


// ========================================================================
// fill_in_image_defaults
// EA  : 0x829171B0
// RVA : 0x009171B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall fill_in_image_defaults(jxr_image *image)
{
  unsigned __int8 v2; // r10
  JXRC_GUID_e ePixelFormat; // r11
  int container_nc; // r11
  unsigned __int8 v5; // r10
  int use_clr_fmt; // r11
  bool v7; // cr58
  unsigned int *v8; // r3
  unsigned int tile_columns; // r9
  unsigned int v10; // r10
  int v11; // r11
  unsigned int *tile_row_height; // r9
  unsigned int *v13; // r3
  unsigned int tile_rows; // r9
  unsigned int v15; // r10
  int v16; // r11
  unsigned int extended_width; // r11
  int v18; // r7
  unsigned int *tile_column_width; // r9
  unsigned int v20; // r4
  unsigned int v21; // r5
  unsigned int v22; // r3
  unsigned int v23; // r10
  unsigned int v24; // r8
  int v25; // r11
  unsigned int v26; // r7
  unsigned int v27; // r7
  unsigned int v28; // r10
  int v29; // r11
  unsigned int v30; // r8
  unsigned int *v31; // r9
  int v32; // r11
  unsigned int v33; // r6
  unsigned int *v34; // r10
  unsigned int v35; // r9
  unsigned int v36; // r8
  int v37; // r11
  unsigned int v38; // r7
  unsigned int v39; // r10
  unsigned int v40; // r9
  unsigned int *v41; // r8
  int v42; // r11
  unsigned int v43; // r7

  if ( image->tile_columns == 0 )
    image->tile_columns = 1;
  if ( image->tile_rows == 0 )
    image->tile_rows = 1;
  if ( image->tile_columns > 1 || image->tile_rows > 1 )
    image->header_flags1 |= 0x80u;
  if ( short_header_ok(image) != 0 )
    v2 = image->header_flags2 | 0x80;
  else
    v2 = image->header_flags2 & 0x7F;
  ePixelFormat = image->ePixelFormat;
  image->header_flags2 = v2;
  if ( ePixelFormat == JXRC_FMT_16bppBGR555
    || ePixelFormat == JXRC_FMT_16bppBGR565
    || ePixelFormat == JXRC_FMT_32bppBGR101010 )
  {
    image->header_flags2 |= 4u;
  }
  if ( ePixelFormat == JXRC_FMT_32bppPBGRA
    || ePixelFormat == JXRC_FMT_64bppPRGBA
    || ePixelFormat == JXRC_FMT_128bppPRGBAFloat )
  {
    container_nc = image->container_nc;
    if ( container_nc == 1 || container_nc == 4 )
      image->header_flags2 |= 2u;
  }
  if ( image->window_extra_top != 0 || image->window_extra_left != 0 )
    image->header_flags2 |= 0x20u;
  if ( image->bands_present != 0 || (*((_DWORD *)image + 9) & 0xF0000000) == 0 )
    v5 = image->header_flags2 & 0xEF;
  else
    v5 = image->header_flags2 | 0x10;
  use_clr_fmt = image->use_clr_fmt;
  image->header_flags2 = v5;
  if ( use_clr_fmt == 1 )
  {
    v7 = image->output_clr_fmt == JXR_OCF_YUV420;
  }
  else
  {
    if ( use_clr_fmt != 2 )
      goto LABEL_34;
    v7 = image->output_clr_fmt == JXR_OCF_YUV422;
  }
  if ( !v7 )
    *((_DWORD *)image + 26) |= 0x80000000;
LABEL_34:
  if ( image->tile_column_width == nullptr )
  {
    if ( image->tile_column_width_input != nullptr )
    {
      v8 = (unsigned int *)_jxr_temp_calloc(image, count: 2 * image->tile_columns, size: 4u);
      tile_columns = image->tile_columns;
      image->tile_column_width = v8;
      v10 = 0;
      if ( tile_columns != 0 )
      {
        v11 = 0;
        do
        {
          ++v10;
          image->tile_column_width[v11] = image->tile_column_width_input[v11];
          ++v11;
        }
        while ( v10 < image->tile_columns );
      }
    }
    else
    {
      jxr_set_NUM_VER_TILES_MINUS1(image, num: 1u);
      jxr_set_TILE_WIDTH_IN_MB(image, list: nullptr);
    }
  }
  tile_row_height = image->tile_row_height;
  image->tile_column_position = &image->tile_column_width[image->tile_columns];
  if ( tile_row_height == nullptr )
  {
    if ( image->tile_row_height_input != nullptr )
    {
      v13 = (unsigned int *)_jxr_temp_calloc(image, count: 2 * image->tile_rows, size: 4u);
      tile_rows = image->tile_rows;
      image->tile_row_height = v13;
      v15 = 0;
      if ( tile_rows != 0 )
      {
        v16 = 0;
        do
        {
          ++v15;
          image->tile_row_height[v16] = image->tile_row_height_input[v16];
          ++v16;
        }
        while ( v15 < image->tile_rows );
      }
    }
    else
    {
      jxr_set_NUM_HOR_TILES_MINUS1(image, num: 1u);
      jxr_set_TILE_HEIGHT_IN_MB(image, list: nullptr);
    }
  }
  extended_width = image->extended_width;
  v18 = image->header_flags1 & 0x80;
  image->tile_row_position = &image->tile_row_height[image->tile_rows];
  if ( v18 != 0 )
  {
    tile_column_width = image->tile_column_width;
    v20 = 1;
    v21 = extended_width >> 4;
    v22 = image->extended_height >> 4;
    if ( *tile_column_width == 0 )
    {
      v23 = 0;
      v24 = 0;
      if ( image->tile_columns != 1 )
      {
        v25 = 0;
        do
        {
          v26 = image->tile_columns;
          ++v24;
          __twllei(v26, 0);
          tile_column_width[v25] = v21 / v26;
          image->tile_column_position[v25] = v23;
          tile_column_width = image->tile_column_width;
          v27 = tile_column_width[v25++];
          v23 += v27;
        }
        while ( v24 < image->tile_columns - 1 );
      }
      tile_column_width[image->tile_columns - 1] = v21 - v23;
      image->tile_column_position[image->tile_columns - 1] = v23;
    }
    v28 = 0;
    if ( (image->header_flags1 & 3u) >= 2 )
    {
      v29 = image->use_clr_fmt;
      if ( (v29 == 1 || v29 == 2) && image->disableTileOverlapFlag != 0 )
        v20 = 2;
    }
    v30 = 0;
    if ( image->tile_columns != 1 )
    {
      v31 = image->tile_column_width;
      v32 = 0;
      do
      {
        if ( v31[v32] < v20 )
          break;
        ++v30;
        image->tile_column_position[v32] = v28;
        v31 = image->tile_column_width;
        v33 = v31[v32++];
        v28 += v33;
      }
      while ( v30 < image->tile_columns - 1 );
    }
    image->tile_column_position[image->tile_columns - 1] = v28;
    image->tile_column_width[image->tile_columns - 1] = v21 - v28;
    v34 = image->tile_row_height;
    if ( *v34 == 0 )
    {
      v35 = 0;
      v36 = 0;
      if ( image->tile_rows != 1 )
      {
        v37 = 0;
        do
        {
          v38 = image->tile_rows;
          ++v36;
          __twllei(v38, 0);
          v34[v37] = v22 / v38;
          image->tile_row_position[v37] = v35;
          v34 = image->tile_row_height;
          v35 += v34[v37++];
        }
        while ( v36 < image->tile_rows - 1 );
      }
      v34[image->tile_rows - 1] = v22 - v35;
      image->tile_row_position[image->tile_rows - 1] = v35;
    }
    v39 = 0;
    v40 = 0;
    if ( image->tile_rows != 1 )
    {
      v41 = image->tile_row_height;
      v42 = 0;
      do
      {
        if ( v41[v42] == 0 )
          break;
        ++v40;
        image->tile_row_position[v42] = v39;
        v41 = image->tile_row_height;
        v43 = v41[v42++];
        v39 += v43;
      }
      while ( v40 < image->tile_rows - 1 );
    }
    image->tile_row_position[image->tile_rows - 1] = v39;
    image->tile_row_height[image->tile_rows - 1] = v22 - v39;
  }
  else
  {
    *image->tile_column_width = extended_width >> 4;
    *image->tile_column_position = 0;
    *image->tile_row_height = image->extended_height >> 4;
    *image->tile_row_position = 0;
  }
  image->lwf_test = 0;
  _jxr_make_mbstore(image, up4_flag: 1);
  image->cur_my = -5;
  return 0;
}


// ========================================================================
// w_image_plane_header
// EA  : 0x82917718
// RVA : 0x00917718
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall w_image_plane_header(jxr_image *image, wbitstream *str, int alpha)
{
  unsigned int use_clr_fmt; // r11
  unsigned __int8 chroma_centering_x; // r4
  unsigned __int8 chroma_centering_y; // r4
  unsigned __int8 exp_bias; // r4

  _jxr_wbitstream_uint3(str, val: image->use_clr_fmt);
  _jxr_wbitstream_uint1(str, val: *((_DWORD *)image + 26) >> 31);
  _jxr_wbitstream_uint4(str, val: image->bands_present);
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt <= 6 )
  {
    if ( use_clr_fmt == 1 || use_clr_fmt == 2 || use_clr_fmt == 3 && image->use_clr_fmt != 0 )
    {
      chroma_centering_x = image->chroma_centering_x;
      image->num_channels = 3;
      _jxr_wbitstream_uint4(str, val: chroma_centering_x);
      chroma_centering_y = image->chroma_centering_y;
LABEL_15:
      _jxr_wbitstream_uint4(str, val: chroma_centering_y);
      goto LABEL_16;
    }
    if ( use_clr_fmt == 4 && image->use_clr_fmt != 0 )
    {
      image->num_channels = 4;
      goto LABEL_16;
    }
    if ( use_clr_fmt != 5 || image->use_clr_fmt == 0 )
    {
      if ( image->use_clr_fmt == 0 )
      {
        image->num_channels = 1;
        goto LABEL_16;
      }
      _jxr_wbitstream_uint4(str, val: image->num_channels - 1);
      chroma_centering_y = 0;
      goto LABEL_15;
    }
  }
LABEL_16:
  if ( (image->header_flags_fmt & 0xFu) - 2 <= 5 )
  {
    if ( (image->header_flags_fmt & 0xF) == 3 )
      goto LABEL_22;
    if ( (image->header_flags_fmt & 0xF) != 4 && (image->header_flags_fmt & 0xF) != 5 )
    {
      if ( (image->header_flags_fmt & 0xF) != 6 && (image->header_flags_fmt & 0xF) != 2 )
      {
        _jxr_wbitstream_uint8(str, val: image->len_mantissa);
        exp_bias = image->exp_bias;
        goto LABEL_24;
      }
LABEL_22:
      exp_bias = image->shift_bits;
LABEL_24:
      _jxr_wbitstream_uint8(str, val: exp_bias);
    }
  }
  _jxr_wbitstream_uint1(str, val: (*((_DWORD *)image + 26) & 0x40000000) != 0);
  if ( (*((_DWORD *)image + 26) & 0x40000000) != 0 )
    _jxr_w_DC_QP(image, str);
  if ( image->bands_present != 3 )
  {
    _jxr_wbitstream_uint1(str, val: 0);
    _jxr_wbitstream_uint1(str, val: (*((_DWORD *)image + 26) & 0x10000000) != 0);
    if ( (*((_DWORD *)image + 26) & 0x10000000) != 0 )
      _jxr_w_LP_QP(image, str);
    if ( image->bands_present != 2 )
    {
      _jxr_wbitstream_uint1(str, val: 0);
      _jxr_wbitstream_uint1(str, val: (*((_DWORD *)image + 26) & 0x4000000) != 0);
      if ( (*((_DWORD *)image + 26) & 0x4000000) != 0 )
        _jxr_w_HP_QP(image, str);
    }
  }
  _jxr_wbitstream_syncbyte(str);
  return 0;
}


// ========================================================================
// ?_jxr_w_MB_CBP@@YAXPAUjxr_image@@PAUwbitstream@@HIIII@Z
// EA  : 0x82917908
// RVA : 0x00917908
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_MB_CBP(
        jxr_image *image,
        wbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int use_clr_fmt; // r11
  int num_channels; // r7
  _DWORD *v13; // r10
  int v14; // ctr
  unsigned int *p_num_lp_qps; // r11
  unsigned int v16; // r9
  int v17; // r21
  int v18; // r3
  int v19; // r20
  int v20; // r22
  int v21; // r25
  int v22; // r23
  int v23; // r10
  int v24; // r11
  int v25; // r11
  int v26; // r27
  int v27; // r28
  int i; // r29
  adaptive_vlc_s *v29; // r5
  int v30; // r30
  unsigned int v31; // r7
  int v32; // r31
  int v33; // r11
  int v34; // r10
  signed int v35; // r6
  int v36; // r11
  int v37; // r5
  int v38; // r11
  int v39; // r11
  int v40; // r11
  int v41; // r11
  int v42; // [sp+50h] [-F0h]
  int v43; // [sp+54h] [-ECh]
  _BYTE v44[8]; // [sp+5Ch] [-E4h] BYREF
  int v45; // [sp+64h] [-DCh]
  int v46; // [sp+68h] [-D8h]

  if ( _jxr_InitContext(image, tx, ty, mx, my) != 0 )
    _jxr_InitCBPVLC(image);
  use_clr_fmt = image->use_clr_fmt;
  num_channels = 1;
  v42 = 1;
  if ( use_clr_fmt == 4 || use_clr_fmt == 6 )
  {
    num_channels = image->num_channels;
    v42 = num_channels;
  }
  if ( image->num_channels != 0 )
  {
    v13 = v44;
    v14 = image->num_channels;
    p_num_lp_qps = &image->num_lp_qps;
    v16 = 84 * (image->tile_column_position[tx] + mx);
    do
    {
      p_num_lp_qps += 7;
      *++v13 = *(_DWORD *)(*p_num_lp_qps + v16 + 16);
      --v14;
    }
    while ( v14 != 0 );
  }
  v43 = 0;
  if ( num_channels > 0 )
  {
    v17 = v46;
    v18 = 0;
    v19 = v45;
    while ( 1 )
    {
      v20 = *(_DWORD *)&v44[v18 + 4];
      v21 = 0;
      v22 = 0;
      v23 = (v20 & 0xF) != 0;
      if ( (v20 & 0xF0) != 0 )
        v23 |= 2u;
      if ( (v20 & 0xF00) != 0 )
        v23 |= 4u;
      if ( (v20 & 0xF000) != 0 )
        v23 |= 8u;
      v24 = image->use_clr_fmt;
      if ( v24 == 1 )
      {
        if ( (v19 & 1) != 0 )
          v21 = 1;
        if ( (v19 & 2) != 0 )
          v21 |= 2u;
        if ( (v19 & 4) != 0 )
          v21 |= 4u;
        if ( (v19 & 8) != 0 )
          v21 |= 8u;
        if ( (v17 & 1) != 0 )
          v22 = 1;
        if ( (v17 & 2) != 0 )
          v22 |= 2u;
        if ( (v17 & 4) != 0 )
          v22 |= 4u;
        v25 = v17 & 8;
        goto LABEL_65;
      }
      if ( v24 == 2 )
        break;
      if ( v24 == 3 )
      {
        if ( (v19 & 0xF) != 0 )
          v21 = 1;
        if ( (v19 & 0xF0) != 0 )
          v21 |= 2u;
        if ( (v19 & 0xF00) != 0 )
          v21 |= 4u;
        if ( (v19 & 0xF000) != 0 )
          v21 |= 8u;
        if ( (v17 & 0xF) != 0 )
          v22 = 1;
        if ( (v17 & 0xF0) != 0 )
          v22 |= 2u;
        if ( (v17 & 0xF00) != 0 )
          v22 |= 4u;
        v25 = v17 & 0xF000;
LABEL_65:
        if ( v25 != 0 )
          v22 |= 8u;
      }
      v26 = v22 | v21 | v23;
      w_REFINE_CBP(image, str, cbp_block_mask: v26);
      v27 = 1;
      for ( i = 0; i < 16; i += 4 )
      {
        if ( (v27 & v26) != 0 )
        {
          v29 = &image->vlc_table[13];
          v30 = (v20 >> i) & 0xF;
          if ( (v27 & v21) != 0 )
            v30 |= 0x10u;
          if ( (v27 & v22) != 0 )
            v30 |= 0x20u;
          v31 = (v30 >> 4) & 3;
          v32 = *(const int *)((char *)code_from_blkcbp + ((4 * v30) & 0x3C));
          v33 = val_from_code[v32];
          if ( v31 != 0 )
          {
            --v31;
            v33 += 6;
          }
          v34 = image->use_clr_fmt;
          v35 = v33 - 1;
          if ( image->use_clr_fmt == 0 || v34 == 4 || v34 == 6 )
          {
            v29->discriminant += Num_BLKCBP_Delta5[v35];
          }
          else
          {
            v36 = v33 - 1;
            if ( v35 > 8 )
              v36 = 8;
            v29->discriminant += Num_BLKCBP_Delta9[v36];
          }
          encode_val_1(image, str, vlc: v29, val1: v35, chr_cbp: v31);
          v38 = code_inc_bits_from_code[v32];
          if ( v38 == 1 )
          {
            _jxr_wbitstream_uint1(str, val: code_inc_from_code[v32]);
          }
          else if ( v38 == 2 )
          {
            _jxr_wbitstream_uint2(str, val: code_inc_from_code[v32]);
          }
          v39 = image->use_clr_fmt;
          if ( v39 == 2 )
          {
            if ( (v30 & 0x10) != 0 )
            {
              v40 = (v19 >> *(_DWORD *)((char *)&unk_822374BC + i)) & 5;
              switch ( v40 )
              {
                case 1:
                  _jxr_wbitstream_uint1(str, val: 1);
                  break;
                case 4:
                  _jxr_wbitstream_uint2(str, val: 1u);
                  break;
                case 5:
                  _jxr_wbitstream_uint2(str, val: 0);
                  break;
                default:
                  break;
              }
            }
            if ( (v30 & 0x20) != 0 )
            {
              v41 = (v17 >> *(_DWORD *)((char *)&unk_822374BC + i)) & 5;
              switch ( v41 )
              {
                case 1:
                  _jxr_wbitstream_uint1(str, val: 1);
                  break;
                case 4:
                  _jxr_wbitstream_uint2(str, val: 1u);
                  break;
                case 5:
                  _jxr_wbitstream_uint2(str, val: 0);
                  break;
                default:
                  break;
              }
            }
          }
          else if ( v39 == 3 )
          {
            if ( (v30 & 0x10) != 0 )
              w_REFINE_CBP_CHR(image: str, str: (wbitstream *)((v19 >> i) & 0xF), cbp_block_mask: v37);
            if ( (v30 & 0x20) != 0 )
              w_REFINE_CBP_CHR(image: str, str: (wbitstream *)((v17 >> i) & 0xF), cbp_block_mask: v37);
          }
        }
        v27 = __ROL4__(v27, 1);
      }
      v18 = 4 * ++v43;
      if ( v43 >= v42 )
        return;
    }
    if ( (v19 & 5) != 0 )
      v21 = 1;
    if ( (v19 & 0xA) != 0 )
      v21 |= 2u;
    if ( (v19 & 0x50) != 0 )
      v21 |= 4u;
    if ( (v19 & 0xA0) != 0 )
      v21 |= 8u;
    if ( (v17 & 5) != 0 )
      v22 = 1;
    if ( (v17 & 0xA) != 0 )
      v22 |= 2u;
    if ( (v17 & 0x50) != 0 )
      v22 |= 4u;
    v25 = v17 & 0xA0;
    goto LABEL_65;
  }
}


// ========================================================================
// w_DECODE_ABS_LEVEL
// EA  : 0x82917E70
// RVA : 0x00917E70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_DECODE_ABS_LEVEL(
        jxr_image *image,
        wbitstream *str,
        unsigned int band,
        unsigned int chroma_flag,
        unsigned int level)
{
  int v8; // r3
  int v9; // r29
  signed int v10; // r31
  _DWORD *v11; // r11
  signed int v12; // r11
  unsigned int v13; // r31
  bool v14; // zf
  int v15; // r30
  unsigned int v16; // r11
  int j; // ctr
  unsigned int i; // r11
  _DWORD v19[8]; // [sp+50h] [-A0h] BYREF
  _DWORD v20[8]; // [sp+70h] [-80h] BYREF
  _DWORD v21[24]; // [sp+90h] [-60h] BYREF

  v8 = _jxr_vlc_select(band, chroma_flag);
  v19[2] = 5;
  v19[0] = 2;
  v21[0] = 2;
  v20[3] = 2;
  v20[4] = 2;
  v20[5] = 2;
  v20[0] = 0;
  v20[1] = 0;
  v19[1] = 3;
  v19[3] = 9;
  v19[4] = 13;
  v9 = v8;
  v19[5] = 17;
  v10 = 0;
  v21[1] = 3;
  v11 = v19;
  v21[2] = 4;
  v21[3] = 6;
  v21[4] = 10;
  v21[5] = 14;
  v20[2] = 1;
  do
  {
    if ( *v11 >= level )
      break;
    ++v10;
    ++v11;
  }
  while ( v10 < 6 );
  encode_abslevel_index(image, str, abslevel_index: v10, vlc_select: v8);
  v12 = v10;
  image->vlc_table[v9].discriminant += _jxr_abslevel_index_delta[v10];
  v14 = v10 >= 6;
  v13 = 0;
  if ( v14 )
  {
    for ( i = level - 2; i > 1; ++v13 )
      i >>= 1;
    if ( v13 - 4 >= 0xF )
    {
      _jxr_wbitstream_uint4(str, val: 0xFu);
      if ( v13 - 19 >= 3 )
      {
        _jxr_wbitstream_uint2(str, val: 3u);
        _jxr_wbitstream_uint3(str, val: v13 - 22);
      }
      else
      {
        _jxr_wbitstream_uint2(str, val: v13 - 19);
      }
    }
    else
    {
      _jxr_wbitstream_uint4(str, val: v13 - 4);
    }
    _jxr_wbitstream_uintN(str, val: level - (1 << v13) - 2, N: v13);
  }
  else
  {
    v15 = v20[v12];
    v16 = level - v21[v12];
    if ( v15 > 0 )
    {
      for ( j = v15; j != 0; --j )
      {
        v13 = (2 * v13) | v16 & 1;
        v16 >>= 1;
      }
      do
      {
        _jxr_wbitstream_uint1(str, val: v13 & 1);
        --v15;
        v13 >>= 1;
      }
      while ( v15 != 0 );
    }
  }
}


// ========================================================================
// w_DECODE_BLOCK
// EA  : 0x82918078
// RVA : 0x00918078
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_DECODE_BLOCK(
        jxr_image *image,
        wbitstream *str,
        unsigned int band,
        unsigned int chroma_flag,
        int *RLCoeffs,
        int num_non_zero)
{
  int v12; // r28
  int use_clr_fmt; // r11
  signed int v14; // r30
  int v15; // r31
  int v16; // r29
  unsigned int v17; // r27
  int v18; // r6
  int v19; // r23
  int v20; // r28
  const int *v21; // r24
  int v22; // r29
  signed int v23; // r31
  signed int v24; // r30
  int v25; // r26

  v12 = 1;
  if ( chroma_flag != 0 && band == 1 )
  {
    use_clr_fmt = image->use_clr_fmt;
    if ( use_clr_fmt == 1 )
      v12 = 10;
    if ( use_clr_fmt == 2 )
      v12 = 2;
  }
  v14 = RLCoeffs[1];
  v15 = 0;
  v16 = 0;
  if ( v14 < 0 )
  {
    v16 = 1;
    v14 = -v14;
  }
  if ( *RLCoeffs == 0 )
    v15 = 1;
  if ( v14 != 1 )
    v15 |= 2u;
  if ( num_non_zero != 1 )
  {
    if ( RLCoeffs[2] != 0 )
      v15 |= 8u;
    else
      v15 |= 4u;
  }
  v17 = (v15 >> 2) & v15 & 1;
  w_DECODE_FIRST_INDEX(image, str, chroma_flag, band, first_index: v15);
  _jxr_wbitstream_uint1(str, val: v16);
  if ( (v15 & 2) != 0 )
    w_DECODE_ABS_LEVEL(image, str, band, chroma_flag: v17, level: v14);
  if ( (v15 & 1) == 0 )
    w_DECODE_RUN(image: str, str: (wbitstream *)(15 - v12), max_run: *RLCoeffs, run: v18);
  v19 = 1;
  v20 = *RLCoeffs + v12 + 1;
  if ( num_non_zero > 1 )
  {
    v21 = RLCoeffs + 2;
    do
    {
      if ( *v21 > 0 )
        w_DECODE_RUN(image: str, str: (wbitstream *)(15 - v20), max_run: *v21, run: v18);
      v22 = 0;
      v23 = v21[1];
      v20 += *v21 + 1;
      if ( v23 < 0 )
      {
        v22 = 1;
        v23 = -v23;
      }
      v24 = v23 != 1;
      v25 = v19 + 1;
      if ( v19 + 1 != num_non_zero )
      {
        if ( v21[2] != 0 )
          v24 |= 4u;
        else
          v24 |= 2u;
      }
      w_DECODE_INDEX(image, str, location: v20, chroma_flag, band, context: v17, index_code: v24);
      v17 &= v24 >> 1;
      _jxr_wbitstream_uint1(str, val: v22);
      if ( v23 != 1 )
        w_DECODE_ABS_LEVEL(image, str, band, chroma_flag: v17, level: v23);
      ++v19;
      v21 += 2;
    }
    while ( v25 < num_non_zero );
  }
}


// ========================================================================
// w_DECODE_BLOCK_ADAPTIVE
// EA  : 0x82918290
// RVA : 0x00918290
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall w_DECODE_BLOCK_ADAPTIVE(
        jxr_image *image,
        wbitstream *str,
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
  int v33; // ctr
  int *data; // r7
  int v35; // r6
  int v36; // r9
  int v37; // r5
  int *v38; // r11
  int v39; // r10
  int v40; // r10
  int v41; // r10
  int v42; // r10
  int v43; // r10
  int v44; // r10
  int v45; // r10
  int v46; // r10
  int v47; // r10
  int v48; // r10
  jxr_image *v49; // r3
  int v50; // r10
  int *v51; // r8
  int v52; // r7
  int v53; // r9
  int *v54; // r11
  int v55; // r6
  int v57; // r31
  int v58; // [sp+4Ch] [-E4h] BYREF
  int v59; // [sp+50h] [-E0h] BYREF
  char v60; // [sp+58h] [-D8h] BYREF
  int v61; // [sp+D0h] [-60h] BYREF
  char v62; // [sp+D4h] [-5Ch] BYREF

  if ( cbp_flag == 0 )
    return 0;
  v33 = 3;
  data = image->strip[channel].cur[image->tile_column_position[tx] + mx].data;
  v35 = 15 * block;
  v36 = 0;
  v59 = 0;
  v37 = 15 * block + 20;
  v38 = (int *)&v60;
  do
  {
    v39 = data[v35 + 16 + v36];
    *(v38 - 1) = v39;
    if ( v39 < 0 )
      v40 = -(-v39 >> a30);
    else
      v40 = v39 >> a30;
    *(v38 - 1) = v40;
    v41 = data[v35 + 17 + v36];
    *v38 = v41;
    if ( v41 < 0 )
      v42 = -(-v41 >> a30);
    else
      v42 = v41 >> a30;
    *v38 = v42;
    v43 = data[v35 + 18 + v36];
    v38[1] = v43;
    if ( v43 < 0 )
      v44 = -(-v43 >> a30);
    else
      v44 = v43 >> a30;
    v38[1] = v44;
    v45 = data[v35 + 19 + v36];
    v38[2] = v45;
    if ( v45 < 0 )
      v46 = -(-v45 >> a30);
    else
      v46 = v45 >> a30;
    v38[2] = v46;
    v47 = data[v37 + v36];
    v38[3] = v47;
    if ( v47 < 0 )
      v48 = -(-v47 >> a30);
    else
      v48 = v47 >> a30;
    v38[3] = v48;
    v36 += 5;
    v38 += 5;
    --v33;
  }
  while ( v33 != 0 );
  v61 = 0;
  AdaptiveHPPermute(image, dst: &v61, src: &v59, mbhp_pred_mode: a28);
  v50 = 1;
  v51 = &v58;
  v52 = 0;
  v53 = 0;
  v54 = (int *)&v62;
  do
  {
    v55 = *v54;
    ++v50;
    if ( *v54++ != 0 )
    {
      v51[1] = v53;
      v52 += 2;
      v51 += 2;
      *v51 = v55;
      v53 = 0;
    }
    else
    {
      ++v53;
    }
  }
  while ( v50 < 16 );
  v57 = v52 / 2;
  w_DECODE_BLOCK(image: v49, str, band: 2u, chroma_flag, RLCoeffs: &v59, num_non_zero: v52 / 2);
  return v57;
}


// ========================================================================
// ?jxr_write_image_bitstream@@YAHPAUjxr_image@@PAEI@Z
// EA  : 0x829184A0
// RVA : 0x009184A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall jxr_write_image_bitstream(jxr_image *image, unsigned __int8 *data, unsigned int size)
{
  int result; // r3
  int v5; // r5
  unsigned __int64 v6; // r6
  unsigned __int16 window_extra_top; // r11
  unsigned __int16 window_extra_left; // r10
  unsigned __int16 window_extra_bottom; // r8
  unsigned __int16 window_extra_right; // r6
  unsigned int v11; // r3
  char *v12; // r3
  jxr_image *v13; // r3
  jxr_image *alpha; // r5
  __int64 v15; // r10
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  unsigned __int8 v20; // [sp+50h] [-50h] BYREF
  char v21; // [sp+51h] [-4Fh]
  char v22; // [sp+52h] [-4Eh]
  char v23; // [sp+53h] [-4Dh]
  char v24; // [sp+54h] [-4Ch]
  wbitstream v25; // [sp+60h] [-40h] BYREF

  v25.dataSize = size;
  v25.data = data;
  v25.byte = 0;
  v25.bits_ready = 0;
  v25.cur_ptr = data;
  v25.write_count = 0;
  v25.mark_stream_position = 0;
  result = fill_in_image_defaults(image);
  if ( result >= 0 )
  {
    initialize_index_table(image);
    w_image_header(image, str: &v25);
    w_image_plane_header(image, str: &v25, alpha: v5);
    if ( (image->header_flags2 & 1) != 0 )
    {
      window_extra_top = image->window_extra_top;
      if ( window_extra_top != 0 || image->window_extra_right != 0 )
      {
        window_extra_left = image->window_extra_left;
        window_extra_bottom = image->window_extra_bottom;
        window_extra_right = image->window_extra_right;
        v20 = 1;
        v21 = window_extra_top;
        v22 = window_extra_left;
        v23 = window_extra_bottom;
        v24 = window_extra_right;
      }
      else
      {
        v20 = 0;
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v24 = 0;
      }
      v11 = jxr_image_size();
      v12 = _jxr_temp_calloc(image, count: 1u, size: v11);
      v13 = jxr_create_image(
              width: image->width1 + 1,
              height: image->height1 + 1,
              windowing: &v20,
              buffer: (jxr_image *)v12);
      image->alpha = v13;
      memcpy(Dst: v13, Src: image, Size: sizeof(jxr_image));
      image->alpha->strip[0].cur = nullptr;
      image->alpha->strip[0].up1 = nullptr;
      image->alpha->strip[0].up2 = nullptr;
      image->alpha->strip[0].up3 = nullptr;
      image->alpha->strip[0].up4 = nullptr;
      jxr_set_INTERNAL_CLR_FMT(image: image->alpha, fmt: 0, channels: 1u);
      _jxr_make_mbstore(image: image->alpha, up4_flag: 1);
      alpha = image->alpha;
      alpha->hp_component_mode = JXR_CM_UNIFORM;
      image->alpha->lp_component_mode = JXR_CM_UNIFORM;
      image->alpha->dc_component_mode = JXR_CM_UNIFORM;
      image->alpha->primary = 0;
      image->alpha->cur_my = -5;
      w_image_plane_header(image: image->alpha, str: &v25, (int)alpha);
    }
    if ( (image->header_flags1 & 4) == 0 )
    {
      _jxr_wbitstream_intVLW(str: &v25, a2: 4u, val: v6);
      _jxr_wbitstream_uint8(str: &v25, val: image->profile_idc);
      _jxr_wbitstream_uint8(str: &v25, val: image->level_idc);
      _jxr_wbitstream_uint15(str: &v25, val: 0);
      _jxr_wbitstream_uint1(str: &v25, val: 1);
      _jxr_wbitstream_mark(str: &v25);
      w_TILE(image, str: &v25, a3: v19, a4: v18, a5: v17, a6: v16, a7: v15);
    }
    _jxr_wbitstream_flush(str: &v25);
    return (_jxr_wbitstream_bitpos(str: &v25) + 7) >> 3;
  }
  return result;
}


// ========================================================================
// ?_jxr_w_MB_LP@@YAXPAUjxr_image@@PAUwbitstream@@HIIII@Z
// EA  : 0x829186B8
// RVA : 0x009186B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_MB_LP(
        jxr_image *image,
        wbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int i; // r6
  int v13; // r11
  int j; // ctr
  int v15; // r7
  char *v16; // r11
  int k; // ctr
  unsigned int use_clr_fmt; // r30
  int num_channels; // r27
  int v20; // r16
  int v21; // r31
  model_s *p_model_lp; // r30
  int count_zero_CBPLP; // r11
  int v24; // r31
  int m; // r30
  int v26; // r31
  BOOL v27; // r4
  int v28; // r19
  char *v29; // r22
  const int *v30; // r18
  macroblock_s **p_cur; // r23
  model_s *v32; // r17
  int v33; // r9
  unsigned int v34; // r30
  int v35; // r11
  int v36; // r10
  int *v37; // r8
  int v38; // r7
  int v39; // r9
  int *v40; // r11
  int v41; // r6
  int v43; // r31
  int v44; // r29
  const int *v45; // r30
  int v46; // r8
  unsigned int v47; // r6
  int v48; // r31
  signed int v49; // r31
  int v50; // r11
  const int *v51; // r30
  int v52; // r8
  unsigned int v53; // r6
  int v54; // r31
  signed int v55; // r31
  unsigned int v56; // r27
  const int *v57; // r28
  int v58; // r30
  int *v59; // r6
  int v60; // r31
  signed int v61; // r31
  int *v62; // r7
  int v63; // r31
  signed int v64; // r31
  unsigned int v65; // r28
  const int *v66; // r27
  int v67; // r30
  int *data; // r6
  int v69; // r31
  signed int v70; // r31
  int *v71; // r7
  int v72; // r31
  signed int v73; // r31
  int v74; // [sp+50h] [-5B0h]
  char v75; // [sp+5Ch] [-5A4h] BYREF
  char v76[64]; // [sp+60h] [-5A0h] BYREF
  int v77; // [sp+A0h] [-560h] BYREF
  char v78; // [sp+A4h] [-55Ch] BYREF
  int v79; // [sp+DCh] [-524h] BYREF
  int v80[32]; // [sp+E0h] [-520h] BYREF
  int v81[18][16]; // [sp+160h] [-4A0h] BYREF

  for ( i = 0; i < 256; i += 16 )
  {
    v13 = 0;
    for ( j = 16; j != 0; --j )
    {
      v15 = i + v13++;
      v81[0][v15] = 0;
    }
  }
  v16 = &v75;
  for ( k = 16; k != 0; --k )
  {
    v16 += 4;
    *(_DWORD *)v16 = 0;
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
  v74 = num_channels;
  if ( use_clr_fmt == 1 || use_clr_fmt == 2 )
  {
    v74 = 2;
    num_channels = 2;
  }
  v20 = 0;
  if ( use_clr_fmt == 1 || use_clr_fmt == 2 || use_clr_fmt == 3 )
  {
    if ( collect_lp_input(image, ch: 0, tx, mx, LPInput: v81, model_bits: image->model_lp.bits[0]) > 0 )
      v20 = 1;
    if ( use_clr_fmt <= 2 )
    {
      if ( collect_lp_input(image, ch: 1, tx, mx, LPInput: v81, model_bits: image->model_lp.bits[1]) > 0 )
        v20 |= 2u;
      if ( collect_lp_input(image, ch: 2, tx, mx, LPInput: v81, model_bits: image->model_lp.bits[2]) > 0 )
        v20 |= 2u;
    }
    else
    {
      if ( collect_lp_input(image, ch: 1, tx, mx, LPInput: v81, model_bits: image->model_lp.bits[1]) > 0 )
        v20 |= 2u;
      if ( collect_lp_input(image, ch: 2, tx, mx, LPInput: v81, model_bits: image->model_lp.bits[2]) > 0 )
        v20 |= 4u;
    }
    count_zero_CBPLP = image->count_zero_CBPLP;
    if ( count_zero_CBPLP > 0 && image->count_max_CBPLP >= 0 )
    {
      if ( num_channels > 0 )
      {
        v24 = num_channels - 1;
        for ( m = num_channels; m != 0; --m )
          _jxr_wbitstream_uint1(str, val: ((1 << v24--) & v20) != 0);
      }
      goto LABEL_55;
    }
    v26 = 4 * num_channels - 5 - v20;
    if ( image->count_max_CBPLP >= count_zero_CBPLP )
      v26 = v20;
    if ( use_clr_fmt <= 2 )
    {
      if ( v26 != 0 )
      {
        if ( v26 == 1 )
        {
          _jxr_wbitstream_uint2(str, val: 2u);
          goto LABEL_55;
        }
        _jxr_wbitstream_uint2(str, val: 3u);
        v27 = v26 != 2;
      }
      else
      {
        v27 = false;
      }
    }
    else
    {
      if ( v26 != 0 )
      {
        if ( v26 != 1 )
        {
          _jxr_wbitstream_uint4(str, val: v26 - 88);
LABEL_55:
          _jxr_UpdateCountCBPLP(image, cbplp: v20, max: 4 * num_channels - 5);
          goto LABEL_56;
        }
        _jxr_wbitstream_uint2(str, val: 2u);
      }
      v27 = false;
    }
    _jxr_wbitstream_uint1(str, val: v27);
    goto LABEL_55;
  }
  v21 = 0;
  if ( image->num_channels != 0 )
  {
    p_model_lp = &image->model_lp;
    do
    {
      if ( collect_lp_input(image, ch: v21, tx, mx, LPInput: v81, model_bits: p_model_lp->bits[0]) <= 0 )
      {
        _jxr_wbitstream_uint1(str, val: 0);
      }
      else
      {
        _jxr_wbitstream_uint1(str, val: 1);
        v20 |= 1 << v21;
      }
      ++v21;
      p_model_lp = (model_s *)((char *)p_model_lp + 4);
    }
    while ( v21 < image->num_channels );
  }
LABEL_56:
  v28 = 0;
  if ( num_channels > 0 )
  {
    v29 = v76;
    v30 = v81[0];
    p_cur = &image->strip[0].cur;
    v32 = &image->model_lp;
    do
    {
      v33 = -v28 & ~v28;
      v34 = (unsigned int)v33 >> 31;
      if ( ((v20 >> v28) & 1) != 0 )
      {
        if ( v33 < 0 && ((v35 = image->use_clr_fmt) == 1 || v35 == 2) )
          FixedLPPermuteUV(image, dst: &v77, src: v81);
        else
          AdaptiveLPPermute(image, dst: &v77, src: v30);
        memset(v80, 0, sizeof(v80));
        v36 = 1;
        v37 = &v79;
        v38 = 0;
        v39 = 0;
        v40 = (int *)&v78;
        do
        {
          v41 = *v40;
          ++v36;
          if ( *v40++ != 0 )
          {
            v37[1] = v39;
            v38 += 2;
            v37 += 2;
            *v37 = v41;
            v39 = 0;
          }
          else
          {
            ++v39;
          }
        }
        while ( v36 < 16 );
        v43 = v38 / 2;
        w_DECODE_BLOCK(image, str, band: 1u, chroma_flag: v34, RLCoeffs: v80, num_non_zero: v38 / 2);
        *(_DWORD *)v29 += v43;
      }
      v44 = v32->bits[0];
      if ( v32->bits[0] == 0 )
        goto LABEL_128;
      if ( v34 != 0 )
      {
        v50 = image->use_clr_fmt;
        if ( v50 == 1 )
        {
          v65 = tx;
          v66 = &transpose420_0[1];
          do
          {
            v67 = *v66;
            data = image->strip[1].cur[image->tile_column_position[v65] + mx].data;
            v69 = data[v67];
            if ( v69 <= 0 )
            {
              if ( v69 >= 0 )
              {
                _jxr_wbitstream_uintN(str, val: 0, N: v44);
              }
              else
              {
                v70 = -v69;
                _jxr_wbitstream_uintN(str, val: v70, N: v44);
                if ( v70 >> v44 == 0 )
                  _jxr_wbitstream_uint1(str, val: 1);
              }
            }
            else
            {
              _jxr_wbitstream_uintN(str, val: data[v67], N: v44);
              if ( v69 >> v44 == 0 )
                _jxr_wbitstream_uint1(str, val: 0);
            }
            v71 = image->strip[2].cur[image->tile_column_position[v65] + mx].data;
            v72 = v71[v67];
            if ( v72 <= 0 )
            {
              if ( v72 >= 0 )
              {
                _jxr_wbitstream_uintN(str, val: 0, N: v44);
              }
              else
              {
                v73 = -v72;
                _jxr_wbitstream_uintN(str, val: v73, N: v44);
                if ( v73 >> v44 == 0 )
                  _jxr_wbitstream_uint1(str, val: 1);
              }
            }
            else
            {
              _jxr_wbitstream_uintN(str, val: v71[v67], N: v44);
              if ( v72 >> v44 == 0 )
                _jxr_wbitstream_uint1(str, val: 0);
            }
            ++v66;
          }
          while ( (int)v66 < (int)transpose422_0 );
        }
        else
        {
          if ( v50 != 2 )
          {
            v51 = &transpose444[1];
            do
            {
              v52 = *v51;
              v53 = image->tile_column_position[tx] + mx;
              v54 = (*p_cur)[v53].data[v52];
              if ( v54 <= 0 )
              {
                if ( v54 >= 0 )
                {
                  _jxr_wbitstream_uintN(str, val: 0, N: v44);
                }
                else
                {
                  v55 = -v54;
                  _jxr_wbitstream_uintN(str, val: v55, N: v44);
                  if ( v55 >> v44 == 0 )
                    _jxr_wbitstream_uint1(str, val: 1);
                }
              }
              else
              {
                _jxr_wbitstream_uintN(str, val: (*p_cur)[v53].data[v52], N: v44);
                if ( v54 >> v44 == 0 )
                  _jxr_wbitstream_uint1(str, val: 0);
              }
              ++v51;
            }
            while ( (int)v51 < (int)"XXXX Don't know how to scale bit depth %d?\n" );
            goto LABEL_128;
          }
          v56 = tx;
          v57 = &transpose422_0[1];
          do
          {
            v58 = *v57;
            v59 = image->strip[1].cur[image->tile_column_position[v56] + mx].data;
            v60 = v59[v58];
            if ( v60 <= 0 )
            {
              if ( v60 >= 0 )
              {
                _jxr_wbitstream_uintN(str, val: 0, N: v44);
              }
              else
              {
                v61 = -v60;
                _jxr_wbitstream_uintN(str, val: v61, N: v44);
                if ( v61 >> v44 == 0 )
                  _jxr_wbitstream_uint1(str, val: 1);
              }
            }
            else
            {
              _jxr_wbitstream_uintN(str, val: v59[v58], N: v44);
              if ( v60 >> v44 == 0 )
                _jxr_wbitstream_uint1(str, val: 0);
            }
            v62 = image->strip[2].cur[image->tile_column_position[v56] + mx].data;
            v63 = v62[v58];
            if ( v63 <= 0 )
            {
              if ( v63 >= 0 )
              {
                _jxr_wbitstream_uintN(str, val: 0, N: v44);
              }
              else
              {
                v64 = -v63;
                _jxr_wbitstream_uintN(str, val: v64, N: v44);
                if ( v64 >> v44 == 0 )
                  _jxr_wbitstream_uint1(str, val: 1);
              }
            }
            else
            {
              _jxr_wbitstream_uintN(str, val: v62[v58], N: v44);
              if ( v63 >> v44 == 0 )
                _jxr_wbitstream_uint1(str, val: 0);
            }
            ++v57;
          }
          while ( (int)v57 < (int)bits_per_qp_index );
        }
        num_channels = v74;
      }
      else
      {
        v45 = &transpose444[1];
        do
        {
          v46 = *v45;
          v47 = image->tile_column_position[tx] + mx;
          v48 = (*p_cur)[v47].data[v46];
          if ( v48 <= 0 )
          {
            if ( v48 >= 0 )
            {
              _jxr_wbitstream_uintN(str, val: 0, N: v44);
            }
            else
            {
              v49 = -v48;
              _jxr_wbitstream_uintN(str, val: v49, N: v44);
              if ( v49 >> v44 == 0 )
                _jxr_wbitstream_uint1(str, val: 1);
            }
          }
          else
          {
            _jxr_wbitstream_uintN(str, val: (*p_cur)[v47].data[v46], N: v44);
            if ( v48 >> v44 == 0 )
              _jxr_wbitstream_uint1(str, val: 0);
          }
          ++v45;
        }
        while ( (int)v45 < (int)"XXXX Don't know how to scale bit depth %d?\n" );
      }
LABEL_128:
      ++v28;
      p_cur += 7;
      v30 += 16;
      v29 += 4;
      v32 = (model_s *)((char *)v32 + 4);
    }
    while ( v28 < num_channels );
  }
  _jxr_UpdateModelMB(image, lap_mean: v76, model: &image->model_lp, band: 1);
  if ( _jxr_ResetContext(image, tx, mx) )
    _jxr_AdaptLP(image);
}


// ========================================================================
// ?_jxr_w_MB_HP@@YAHPAUjxr_image@@PAUwbitstream@@HIIII1@Z
// EA  : 0x82918F50
// RVA : 0x00918F50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

int __fastcall _jxr_w_MB_HP(
        jxr_image *image,
        wbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my,
        wbitstream *strFB)
{
  int v13; // r30
  int v14; // r16
  macroblock_s **p_cur; // r15
  int v16; // r21
  int v17; // r10
  unsigned int v18; // r19
  int use_clr_fmt; // r11
  int v20; // r24
  int v21; // r11
  int hp_cbp; // r26
  unsigned int v23; // r28
  unsigned int *v24; // r22
  unsigned int v25; // r29
  unsigned int v26; // r10
  wbitstream *v27; // r4
  unsigned int v29; // [sp+8h] [-F8h]
  unsigned int v30; // [sp+Ch] [-F4h]
  int v31; // [sp+10h] [-F0h]
  int v32; // [sp+14h] [-ECh]
  int v33; // [sp+18h] [-E8h]
  int v34; // [sp+1Ch] [-E4h]
  int v35; // [sp+20h] [-E0h]
  int v36; // [sp+24h] [-DCh]
  int v37; // [sp+28h] [-D8h]
  int v38; // [sp+2Ch] [-D4h]
  int v39; // [sp+30h] [-D0h]
  int v40; // [sp+34h] [-CCh]
  int v41; // [sp+38h] [-C8h]
  int v42; // [sp+3Ch] [-C4h]
  int v43; // [sp+40h] [-C0h]
  int v44; // [sp+44h] [-BCh]
  int v45; // [sp+48h] [-B8h]
  int v46; // [sp+4Ch] [-B4h]
  int v47; // [sp+50h] [-B0h]
  int v48; // [sp+58h] [-A8h]
  BOOL v49; // [sp+64h] [-9Ch]

  if ( _jxr_InitContext(image, tx, ty, mx, my) != 0 )
  {
    _jxr_InitHPVLC(image);
    _jxr_InitializeAdaptiveScanHP(image);
  }
  if ( _jxr_ResetTotals(image, mx) )
    _jxr_ResetTotalsAdaptiveScanHP(image);
  v13 = 0;
  v49 = (image->header_flags1 & 0x40) == 0 && image->bands_present != 1;
  v14 = (__int16)*((_DWORD *)&image->strip[0].cur[image->tile_column_position[tx] + mx] + 2) >> 13;
  if ( image->num_channels != 0 )
  {
    p_cur = &image->strip[0].cur;
    while ( 1 )
    {
      v16 = 4;
      v17 = -v13 & ~v13;
      v18 = (unsigned int)v17 >> 31;
      if ( v17 < 0 )
      {
        use_clr_fmt = image->use_clr_fmt;
        if ( use_clr_fmt == 1 )
        {
          v16 = 1;
        }
        else if ( use_clr_fmt == 2 )
        {
          v16 = 2;
        }
      }
      v20 = 0;
      v21 = image->tile_column_position[tx] + mx;
      hp_cbp = (*p_cur)[v21].hp_cbp;
      v23 = image->strip[0].cur[v21].hp_model_bits[v13];
      if ( 4 * v16 > 0 )
        break;
LABEL_23:
      ++v13;
      p_cur += 7;
      if ( v13 >= image->num_channels )
        goto LABEL_24;
    }
    v24 = (unsigned int *)_jxr_hp_scan_map;
    while ( 1 )
    {
      v25 = v20;
      if ( v16 == 4 )
        v25 = *v24;
      if ( w_DECODE_BLOCK_ADAPTIVE(
             image,
             str,
             tx,
             mx,
             cbp_flag: hp_cbp & 1,
             chroma_flag: v18,
             channel: v13,
             block: v25,
             mbhp_pred_mode: v29,
             model_bits: v30,
             a11: v31,
             a12: v32,
             a13: v33,
             a14: v34,
             a15: v35,
             a16: v36,
             a17: v37,
             a18: v38,
             a19: v39,
             a20: v40,
             a21: v41,
             a22: v42,
             a23: v43,
             a24: v44,
             a25: v45,
             a26: v46,
             a27: v47,
             a28: v14,
             a29: v48,
             a30: v23) < 0 )
        return -1;
      if ( strFB != nullptr )
        break;
      if ( v49 )
      {
        v27 = str;
        goto LABEL_21;
      }
LABEL_22:
      ++v20;
      ++v24;
      hp_cbp >>= 1;
      if ( v20 >= 4 * v16 )
        goto LABEL_23;
    }
    v27 = strFB;
LABEL_21:
    w_BLOCK_FLEXBITS(image, str: v27, tx, ty: mx, mx: v13, my: v25, ch: v23, bl: v26, model_bits: v29);
    goto LABEL_22;
  }
LABEL_24:
  if ( _jxr_ResetContext(image, tx, mx) )
    _jxr_AdaptHP(image);
  return 0;
}


// ========================================================================
// w_DEC_DC
// EA  : 0x82919198
// RVA : 0x00919198
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall w_DEC_DC(
        jxr_image *image,
        wbitstream *str,
        int model_bits,
        unsigned int chroma_flag,
        int is_dc_ch,
        int dc_val)
{
  int v9; // r22
  BOOL v10; // r21
  unsigned int v11; // r24
  int i; // ctr
  unsigned int v13; // r29
  int v14; // r3
  int v15; // r30
  signed int v16; // r31
  unsigned int *v17; // r11
  signed int v18; // r11
  unsigned int v19; // r31
  bool v20; // zf
  int v21; // r30
  unsigned int v22; // r11
  int k; // ctr
  unsigned int j; // r11
  unsigned int v25; // r29
  int m; // r31
  _DWORD v27[8]; // [sp+50h] [-C0h] BYREF
  _DWORD v28[8]; // [sp+70h] [-A0h] BYREF
  _DWORD v29[32]; // [sp+90h] [-80h] BYREF

  v9 = 0;
  v10 = (_cntlzw(is_dc_ch) & 0x20) != 0;
  if ( is_dc_ch < 0 )
  {
    v9 = 1;
    is_dc_ch = -is_dc_ch;
  }
  v11 = 0;
  if ( model_bits > 0 )
  {
    for ( i = model_bits; i != 0; --i )
    {
      v11 = (2 * v11) | is_dc_ch & 1;
      is_dc_ch >>= 1;
    }
  }
  if ( is_dc_ch != 0 )
  {
    v13 = is_dc_ch + 1;
    v14 = _jxr_vlc_select(band: 0, chroma_flag);
    v28[0] = 0;
    v27[2] = 5;
    v27[0] = 2;
    v29[0] = 2;
    v28[3] = 2;
    v28[4] = 2;
    v28[5] = 2;
    v27[1] = 3;
    v27[3] = 9;
    v27[4] = 13;
    v15 = v14;
    v27[5] = 17;
    v16 = 0;
    v29[1] = 3;
    v17 = v27;
    v29[2] = 4;
    v29[3] = 6;
    v29[4] = 10;
    v29[5] = 14;
    v28[1] = 0;
    v28[2] = 1;
    do
    {
      if ( *v17 >= v13 )
        break;
      ++v16;
      ++v17;
    }
    while ( v16 < 6 );
    encode_abslevel_index(image, str, abslevel_index: v16, vlc_select: v14);
    v18 = v16;
    image->vlc_table[v15].discriminant += _jxr_abslevel_index_delta[v16];
    v20 = v16 >= 6;
    v19 = 0;
    if ( v20 )
    {
      for ( j = v13 - 2; j > 1; ++v19 )
        j >>= 1;
      v25 = v13 - (1 << v19) - 2;
      if ( v19 - 4 >= 0xF )
      {
        _jxr_wbitstream_uint4(str, val: 0xFu);
        if ( v19 - 19 >= 3 )
        {
          _jxr_wbitstream_uint2(str, val: 3u);
          _jxr_wbitstream_uint3(str, val: v19 - 22);
        }
        else
        {
          _jxr_wbitstream_uint2(str, val: v19 - 19);
        }
      }
      else
      {
        _jxr_wbitstream_uint4(str, val: v19 - 4);
      }
      _jxr_wbitstream_uintN(str, val: v25, N: v19);
    }
    else
    {
      v21 = v28[v18];
      v22 = v13 - v29[v18];
      if ( v21 > 0 )
      {
        for ( k = v21; k != 0; --k )
        {
          v19 = (2 * v19) | v22 & 1;
          v22 >>= 1;
        }
        do
        {
          _jxr_wbitstream_uint1(str, val: v19 & 1);
          --v21;
          v19 >>= 1;
        }
        while ( v21 != 0 );
      }
    }
  }
  if ( model_bits > 0 )
  {
    for ( m = model_bits; m != 0; --m )
    {
      _jxr_wbitstream_uint1(str, val: v11 & 1);
      v11 >>= 1;
    }
  }
  if ( !v10 )
    _jxr_wbitstream_uint1(str, val: v9);
}


// ========================================================================
// ?_jxr_w_MB_DC@@YAXPAUjxr_image@@PAUwbitstream@@HIIII@Z
// EA  : 0x82919420
// RVA : 0x00919420
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_emit.cpp
// ========================================================================

void __fastcall _jxr_w_MB_DC(
        jxr_image *image,
        wbitstream *str,
        int alpha_flag,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  char *v7; // r10
  int i; // ctr
  int use_clr_fmt; // r11
  int v14; // r4
  int v15; // r3
  int v16; // r30
  int v17; // r29
  int v18; // r28
  int v19; // r5
  int v20; // r8
  int v21; // r8
  int v22; // r8
  unsigned int v23; // r23
  int *v24; // r25
  model_s *p_model_dc; // r27
  macroblock_s **p_cur; // r28
  int v27; // r26
  int v28; // r30
  BOOL v29; // r29
  int v30; // r8
  char v31; // [sp+4Ch] [-B4h] BYREF
  int v32; // [sp+50h] [-B0h] BYREF
  int v33; // [sp+54h] [-ACh]
  int v34; // [sp+58h] [-A8h]

  v7 = &v31;
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
    v23 = 0;
    if ( image->num_channels != 0 )
    {
      v24 = &v32;
      p_model_dc = &image->model_dc;
      p_cur = &image->strip[0].cur;
      do
      {
        v27 = p_model_dc->bits[0];
        v28 = *(*p_cur)[image->tile_column_position[tx] + mx].data;
        v29 = (int)abs32(v28) >> p_model_dc->bits[0] != 0;
        _jxr_wbitstream_uint1(str, val: v29);
        if ( v29 )
          ++*v24;
        w_DEC_DC(image, str, model_bits: v27, chroma_flag: 0, is_dc_ch: v28, dc_val: v30);
        ++v23;
        p_cur += 7;
        p_model_dc = (model_s *)((char *)p_model_dc + 4);
        ++v24;
      }
      while ( v23 < image->num_channels );
    }
  }
  else
  {
    v14 = 0;
    v15 = image->tile_column_position[tx] + mx;
    v16 = *image->strip[0].cur[v15].data;
    v17 = *image->strip[1].cur[v15].data;
    v18 = *image->strip[2].cur[v15].data;
    v19 = abs32(v16);
    if ( v19 >> image->model_dc.bits[0] != 0 )
    {
      v14 = 4;
      ++v32;
    }
    if ( (int)abs32(v17) >> image->model_dc.bits[1] != 0 )
    {
      v14 |= 2u;
      ++v33;
    }
    if ( (int)abs32(v18) >> image->model_dc.bits[2] != 0 )
    {
      v14 |= 1u;
      ++v34;
    }
    encode_val_dc_yuv(image: str, str: (wbitstream *)v14, val: v19);
    w_DEC_DC(image, str, model_bits: image->model_dc.bits[0], chroma_flag: 0, is_dc_ch: v16, dc_val: v20);
    w_DEC_DC(image, str, model_bits: image->model_dc.bits[1], chroma_flag: 1u, is_dc_ch: v17, dc_val: v21);
    w_DEC_DC(image, str, model_bits: image->model_dc.bits[2], chroma_flag: 1u, is_dc_ch: v18, dc_val: v22);
  }
  _jxr_UpdateModelMB(image, lap_mean: (char *)&v32, model: &image->model_dc, band: 0);
  if ( _jxr_ResetContext(image, tx, mx) )
  {
    _jxr_AdaptVLCTable(image, vlc_select: 0);
    _jxr_AdaptVLCTable(image, vlc_select: 1);
  }
}

