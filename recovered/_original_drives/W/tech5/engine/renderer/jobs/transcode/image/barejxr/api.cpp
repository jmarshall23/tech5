
// ========================================================================
// ?_jxr_send_mb_to_output@@YAXPAUjxr_image@@HHPAH@Z
// EA  : 0x829027D8
// RVA : 0x009027D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall _jxr_send_mb_to_output(jxr_image *image, int mx, int my, int *data)
{
  void (*out_fun)(void); // r11

  out_fun = (void (*)(void))image->out_fun;
  if ( out_fun != nullptr )
    out_fun();
}


// ========================================================================
// ?jxr_set_block_input@@YAXPAUjxr_image@@P6AX0HHPAH@Z@Z
// EA  : 0x829027F0
// RVA : 0x009027F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_block_input(jxr_image *image, void (__fastcall *fun)(jxr_image *, int, int, int *))
{
  image->inp_fun = fun;
}


// ========================================================================
// ?jxr_set_user_data@@YAXPAUjxr_image@@PAX@Z
// EA  : 0x829027F8
// RVA : 0x009027F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_user_data(jxr_image *image, void *data)
{
  image->user_data = data;
}


// ========================================================================
// ?jxr_get_user_data@@YAPAXPAUjxr_image@@@Z
// EA  : 0x82902800
// RVA : 0x00902800
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void *__fastcall jxr_get_user_data(jxr_image *image)
{
  return image->user_data;
}


// ========================================================================
// ?jxr_set_INTERNAL_CLR_FMT@@YAXPAUjxr_image@@W4jxr_color_fmt_e@@H@Z
// EA  : 0x82902808
// RVA : 0x00902808
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_INTERNAL_CLR_FMT(jxr_image *image, unsigned int fmt, unsigned __int8 channels)
{
  if ( fmt > 6 )
    goto LABEL_12;
  switch ( fmt )
  {
    case 1u:
    case 2u:
    case 3u:
      image->use_clr_fmt = fmt;
      image->container_nc = channels;
      image->num_channels = 3;
      return;
    case 4u:
      image->container_nc = channels;
      image->use_clr_fmt = 4;
      image->num_channels = 4;
      return;
    case 5u:
LABEL_12:
      image->num_channels = channels;
      image->use_clr_fmt = fmt;
      image->container_nc = channels;
      break;
    default:
      if ( fmt != 0 )
      {
        image->num_channels = channels;
        image->container_nc = channels;
        image->use_clr_fmt = 6;
      }
      else
      {
        image->container_nc = channels;
        image->use_clr_fmt = 0;
        image->num_channels = 1;
      }
      break;
  }
}


// ========================================================================
// ?jxr_set_OUTPUT_CLR_FMT@@YAXPAUjxr_image@@W4jxr_output_clr_fmt_e@@@Z
// EA  : 0x82902898
// RVA : 0x00902898
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_OUTPUT_CLR_FMT(jxr_image *image, jxr_output_clr_fmt_e fmt)
{
  image->output_clr_fmt = fmt;
  if ( (unsigned int)fmt <= JXR_OCF_RGBE && fmt != JXR_OCF_YONLY )
  {
    switch ( fmt )
    {
      case JXR_OCF_YUV420:
        image->header_flags_fmt |= 0x10u;
        break;
      case JXR_OCF_YUV422:
        image->header_flags_fmt |= 0x20u;
        break;
      case JXR_OCF_YUV444:
        image->header_flags_fmt |= 0x30u;
        break;
      case JXR_OCF_CMYK:
        image->header_flags_fmt |= 0x40u;
        break;
      case JXR_OCF_CMYKDIRECT:
        image->header_flags_fmt |= 0x50u;
        break;
      case JXR_OCF_NCOMPONENT:
        image->header_flags_fmt |= 0x60u;
        break;
      case JXR_OCF_RGB:
        image->header_flags_fmt |= 0x70u;
        break;
      default:
        image->header_flags_fmt |= 0x80u;
        break;
    }
  }
}


// ========================================================================
// ?jxr_set_OUTPUT_BITDEPTH@@YAXPAUjxr_image@@W4jxr_bitdepth_e@@@Z
// EA  : 0x82902950
// RVA : 0x00902950
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_OUTPUT_BITDEPTH(jxr_image *image, jxr_bitdepth_e bd)
{
  image->header_flags_fmt = image->header_flags_fmt & 0xF0 | bd;
}


// ========================================================================
// ?jxr_set_BANDS_PRESENT@@YAXPAUjxr_image@@W4jxr_bands_present_e@@@Z
// EA  : 0x82902968
// RVA : 0x00902968
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_BANDS_PRESENT(jxr_image *image, jxr_bands_present_e bp)
{
  image->bands_present = bp;
  image->bands_present_of_primary = bp;
}


// ========================================================================
// ?jxr_set_TILE_WIDTH_IN_MB@@YAXPAUjxr_image@@PAI@Z
// EA  : 0x82902978
// RVA : 0x00902978
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_TILE_WIDTH_IN_MB(jxr_image *image, unsigned int *list)
{
  unsigned int v3; // r30
  unsigned int *v4; // r3
  unsigned int tile_columns; // r9
  unsigned int *tile_column_width; // r10
  unsigned int v7; // r9
  bool v8; // zf
  int v9; // r11
  unsigned int v10; // r7
  unsigned int v11; // r6
  unsigned int v12; // r8

  if ( list != nullptr && *list != 0 )
  {
    image->tile_column_width_input = list;
    image->tile_column_width = nullptr;
    image->tile_column_position = nullptr;
  }
  else
  {
    v3 = 0;
    v4 = (unsigned int *)_jxr_temp_calloc(image, count: 2 * image->tile_columns, size: 4u);
    tile_columns = image->tile_columns;
    tile_column_width = v4;
    image->tile_column_width = v4;
    image->tile_column_position = &v4[tile_columns];
    v8 = tile_columns == 1;
    v7 = 0;
    if ( !v8 )
    {
      v9 = 0;
      do
      {
        ++v7;
        v10 = image->tile_columns;
        v11 = image->extended_width >> 4;
        __twllei(v10, 0);
        tile_column_width[v9] = v11 / v10;
        image->tile_column_position[v9] = v3;
        tile_column_width = image->tile_column_width;
        v12 = tile_column_width[v9++];
        v3 += v12;
      }
      while ( v7 < image->tile_columns - 1 );
    }
    tile_column_width[image->tile_columns - 1] = (image->extended_width >> 4) - v3;
    image->tile_column_position[image->tile_columns - 1] = v3;
  }
}


// ========================================================================
// ?jxr_set_TILE_HEIGHT_IN_MB@@YAXPAUjxr_image@@PAI@Z
// EA  : 0x82902A88
// RVA : 0x00902A88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_TILE_HEIGHT_IN_MB(jxr_image *image, unsigned int *list)
{
  unsigned int *v3; // r3
  unsigned int tile_rows; // r10
  unsigned int v5; // r8
  unsigned int *tile_row_height; // r9
  unsigned int v7; // r10
  bool v8; // zf
  int v9; // r11
  unsigned int v10; // r6
  unsigned int v11; // r5
  unsigned int v12; // r7

  if ( list != nullptr && *list != 0 )
  {
    image->tile_row_height_input = list;
    image->tile_row_height = nullptr;
    image->tile_row_position = nullptr;
  }
  else
  {
    v3 = (unsigned int *)_jxr_temp_calloc(image, count: 2 * image->tile_rows, size: 4u);
    tile_rows = image->tile_rows;
    v5 = 0;
    image->tile_row_height = v3;
    tile_row_height = v3;
    image->tile_row_position = &v3[tile_rows];
    v8 = tile_rows == 1;
    v7 = 0;
    if ( !v8 )
    {
      v9 = 0;
      do
      {
        ++v5;
        v10 = image->tile_rows;
        v11 = image->extended_height >> 4;
        __twllei(v10, 0);
        tile_row_height[v9] = v11 / v10;
        image->tile_row_position[v9] = v7;
        tile_row_height = image->tile_row_height;
        v12 = tile_row_height[v9++];
        v7 += v12;
      }
      while ( v5 < image->tile_rows - 1 );
    }
    tile_row_height[image->tile_rows - 1] = (image->extended_height >> 4) - v7;
    image->tile_row_position[image->tile_rows - 1] = v7;
  }
}


// ========================================================================
// ?jxr_set_OVERLAP_FILTER@@YAXPAUjxr_image@@H@Z
// EA  : 0x82902BA0
// RVA : 0x00902BA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_OVERLAP_FILTER(jxr_image *image, char flag)
{
  image->header_flags1 = flag & 3 | image->header_flags1 & 0xFC;
}


// ========================================================================
// ?jxr_set_QP_UNIFORM@@YAXPAUjxr_image@@E@Z
// EA  : 0x82902BB0
// RVA : 0x00902BB0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_QP_UNIFORM(jxr_image *image, unsigned __int8 quant)
{
  int v2; // r9
  int v3; // r11
  unsigned __int8 *v4; // r10

  v2 = *((_DWORD *)image + 26);
  v3 = 0;
  image->num_lp_qps = 1;
  image->num_hp_qps = 1;
  image->dc_component_mode = JXR_CM_UNIFORM;
  image->lp_component_mode = JXR_CM_UNIFORM;
  image->hp_component_mode = JXR_CM_UNIFORM;
  *((_DWORD *)image + 26) = v2 & 0x3FFFFFF | 0x54000000;
  if ( quant != 0 )
    *((_DWORD *)image + 26) = v2 & 0x3FFFFFF | 0xD4000000;
  if ( image->bands_present != 0 )
    *((_DWORD *)image + 26) |= 0x80000000;
  if ( image->num_channels != 0 )
  {
    v4 = image->lp_quant_ch[15];
    do
    {
      image->dc_quant_ch[v3++] = quant;
      *(v4 - 240) = quant;
      v4 += 16;
      *v4 = quant;
    }
    while ( v3 < image->num_channels );
  }
}


// ========================================================================
// ?jxr_set_QP_SEPARATE@@YAXPAUjxr_image@@PAE@Z
// EA  : 0x82902C40
// RVA : 0x00902C40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_QP_SEPARATE(jxr_image *image, unsigned __int8 *quant_per_channel)
{
  int bands_present; // r10
  int v3; // r11
  int v4; // r11
  unsigned int v5; // r10
  unsigned __int8 *v6; // r10

  bands_present = image->bands_present;
  v3 = *((_DWORD *)image + 26) & 0x7FFFFFFF;
  *((_DWORD *)image + 26) = v3;
  if ( bands_present != 0 )
    *((_DWORD *)image + 26) = v3 | 0x80000000;
  v4 = 1;
  v5 = *((_DWORD *)image + 26) & 0x83FFFFFF | 0x54000000;
  image->dc_component_mode = JXR_CM_SEPARATE;
  image->lp_component_mode = JXR_CM_SEPARATE;
  image->hp_component_mode = JXR_CM_SEPARATE;
  *((_DWORD *)image + 26) = v5;
  if ( *quant_per_channel != 0 )
    *((_DWORD *)image + 26) = v5 | 0x80000000;
  image->dc_quant_ch[0] = *quant_per_channel;
  image->lp_quant_ch[0][0] = *quant_per_channel;
  image->hp_quant_ch[0][0] = *quant_per_channel;
  if ( quant_per_channel[1] != 0 )
    *((_DWORD *)image + 26) |= 0x80000000;
  if ( image->num_channels > 1u )
  {
    v6 = image->hp_quant_ch[0];
    do
    {
      image->dc_quant_ch[v4++] = quant_per_channel[1];
      *(v6 - 240) = quant_per_channel[1];
      v6 += 16;
      *v6 = quant_per_channel[1];
    }
    while ( v4 < image->num_channels );
  }
}


// ========================================================================
// ?jxr_set_NUM_VER_TILES_MINUS1@@YAXPAUjxr_image@@I@Z
// EA  : 0x82902D08
// RVA : 0x00902D08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_NUM_VER_TILES_MINUS1(jxr_image *image, unsigned int num)
{
  image->tile_columns = num;
  if ( num > 1 )
    image->header_flags1 |= 0x84u;
}


// ========================================================================
// ?jxr_set_NUM_HOR_TILES_MINUS1@@YAXPAUjxr_image@@I@Z
// EA  : 0x82902D28
// RVA : 0x00902D28
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\api.cpp
// ========================================================================

void __fastcall jxr_set_NUM_HOR_TILES_MINUS1(jxr_image *image, unsigned int num)
{
  image->tile_rows = num;
  if ( num > 1 )
    image->header_flags1 |= 0x84u;
}

