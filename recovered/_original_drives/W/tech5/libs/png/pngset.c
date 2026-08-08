
// ========================================================================
// png_set_bKGD
// EA  : 0x8321CFB8
// RVA : 0x0121CFB8
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_bKGD(png_struct_def *png_ptr, png_info_struct *info_ptr, png_color_16_struct *background)
{
  unsigned __int16 *p_gray; // r11
  unsigned __int16 *v4; // r10
  int i; // ctr

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    p_gray = &background[-1].gray;
    v4 = &info_ptr->trans_values.gray;
    for ( i = 5; i != 0; --i )
      *++v4 = *++p_gray;
    info_ptr->valid |= 0x20u;
  }
}


// ========================================================================
// png_set_cHRM
// EA  : 0x8321CFF8
// RVA : 0x0121CFF8
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_cHRM(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        long double white_x,
        long double white_y,
        long double red_x,
        long double red_y,
        double a7,
        long double green_x,
        long double green_y,
        long double blue_x,
        long double blue_y)
{
  const char *v11; // r4
  unsigned int v12; // r10

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    if ( *(double *)&white_x == 0.0
      && *((double *)&white_x + 1) == 0.0
      && *(double *)&white_y == 0.0
      && *((double *)&white_y + 1) == 0.0
      && *(double *)&red_x == 0.0
      && *((double *)&red_x + 1) == 0.0
      && *(double *)&red_y == 0.0
      && *((double *)&red_y + 1) == 0.0 )
    {
      v11 = "Ignoring attempt to set all-zero chromaticity values";
    }
    else if ( *(double *)&white_x < 0.0
           || *((double *)&white_x + 1) < 0.0
           || *(double *)&white_y < 0.0
           || *((double *)&white_y + 1) < 0.0
           || *(double *)&red_x < 0.0
           || *((double *)&red_x + 1) < 0.0
           || *(double *)&red_y < 0.0
           || *((double *)&red_y + 1) < 0.0 )
    {
      v11 = "Ignoring attempt to set negative chromaticity value";
    }
    else
    {
      if ( *(double *)&white_x <= 21474.83
        && *((double *)&white_x + 1) <= 21474.83
        && *(double *)&white_y <= 21474.83
        && *((double *)&white_y + 1) <= 21474.83
        && *(double *)&red_x <= 21474.83
        && *((double *)&red_x + 1) <= 21474.83
        && *(double *)&red_y <= 21474.83
        && *((double *)&red_y + 1) <= 21474.83 )
      {
        info_ptr->x_white = *(double *)&white_x;
        info_ptr->y_white = *((double *)&white_x + 1);
        info_ptr->x_red = *(double *)&white_y;
        info_ptr->y_red = *((double *)&white_y + 1);
        v12 = info_ptr->valid | 4;
        info_ptr->x_green = *(double *)&red_x;
        info_ptr->x_blue = *(double *)&red_y;
        info_ptr->scal_s_width = (char *)(int)(*(double *)&white_x * 100000.0 + 0.5);
        info_ptr->scal_s_height = (char *)(int)(*((double *)&white_x + 1) * 100000.0 + 0.5);
        info_ptr->row_pointers = (unsigned __int8 **)(int)(*(double *)&white_y * 100000.0 + 0.5);
        info_ptr->int_gamma = (int)(*((double *)&white_y + 1) * 100000.0 + 0.5);
        info_ptr->int_x_white = (int)(*(double *)&red_x * 100000.0 + 0.5);
        info_ptr->int_y_white = (int)(*((double *)&red_x + 1) * 100000.0 + 0.5);
        info_ptr->int_x_red = (int)(*(double *)&red_y * 100000.0 + 0.5);
        info_ptr->y_green = *((double *)&red_x + 1);
        info_ptr->y_blue = *((double *)&red_y + 1);
        info_ptr->int_y_red = (int)(*((double *)&red_y + 1) * 100000.0 + 0.5);
        info_ptr->valid = v12;
        return;
      }
      v11 = "Ignoring attempt to set chromaticity value exceeding 21474.83";
    }
    png_warning(png_ptr, warning_message: v11);
  }
}


// ========================================================================
// png_set_cHRM_fixed
// EA  : 0x8321D208
// RVA : 0x0121D208
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall png_set_cHRM_fixed(
        png_struct_def *png_ptr,
        __int64 white_x,
        __int64 red_x,
        __int64 green_x,
        int a5,
        int blue_x,
        int blue_y,
        int a8,
        int a9,
        int a10,
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
        int a27)
{
  __int64 v27; // r28 OVERLAPPED
  __int64 green_y; // r11
  bool v29; // cr56
  bool v30; // cr56
  bool v31; // cr56
  bool v32; // cr56
  bool v33; // cr56
  bool v34; // cr56
  bool v35; // cr56
  int v36; // r29
  int v37; // r3
  double v38; // fp12
  __int64 v39; // [sp+50h] [-60h]
  __int64 v40; // [sp+78h] [-38h]

  if ( png_ptr != nullptr && HIDWORD(white_x) != 0 )
  {
    if ( (_DWORD)white_x != 0 )
    {
      if ( (int)white_x < 0 )
        goto LABEL_28;
      v29 = red_x < 0;
    }
    else
    {
      v29 = red_x < 0;
      if ( HIDWORD(red_x) == 0 )
      {
        v30 = (int)red_x < 0;
        if ( (_DWORD)red_x == 0 )
        {
          v31 = green_x < 0;
          if ( HIDWORD(green_x) == 0 )
          {
            v32 = (int)green_x < 0;
            if ( (_DWORD)green_x == 0 )
            {
              v33 = green_y < 0;
              if ( HIDWORD(green_y) == 0 )
              {
                v34 = a25 < 0;
                if ( a25 == 0 )
                {
                  v35 = a27 < 0;
                  if ( a27 == 0 )
                  {
                    png_warning(png_ptr, warning_message: "Ignoring attempt to set all-zero chromaticity values");
                    return;
                  }
LABEL_26:
                  if ( !v35 )
                  {
                    v36 = green_x;
                    *(_DWORD *)(HIDWORD(white_x) + 256) = white_x;
                    v37 = *(_DWORD *)(HIDWORD(white_x) + 8);
                    LODWORD(green_y) = HIDWORD(green_x);
                    v40 = white_x;
                    v39 = green_y;
                    LODWORD(white_x) = red_x;
                    LODWORD(green_y) = a25;
                    *(_QWORD *)(HIDWORD(white_x) + 260) = red_x;
                    *(_QWORD *)(HIDWORD(white_x) + 268) = green_x;
                    v38 = (double)green_y;
                    LODWORD(green_y) = HIDWORD(red_x);
                    *(_DWORD *)(HIDWORD(white_x) + 276) = HIDWORD(green_y);
                    *(_DWORD *)(HIDWORD(white_x) + 280) = a25;
                    *(_DWORD *)(HIDWORD(white_x) + 284) = a27;
                    *(_DWORD *)(HIDWORD(white_x) + 8) = v37 | 4;
                    *(float *)(HIDWORD(white_x) + 140) = (double)v39 * 0.00001;
                    *(float *)(HIDWORD(white_x) + 144) = (double)*(__int64 *)((char *)&v27 - 4) * 0.00001;
                    LODWORD(v27) = HIDWORD(green_y);
                    *(float *)(HIDWORD(white_x) + 136) = (double)white_x * 0.00001;
                    *(float *)(HIDWORD(white_x) + 132) = (double)green_y * 0.00001;
                    *(float *)(HIDWORD(white_x) + 128) = (double)v40 * 0.00001;
                    *(float *)(HIDWORD(white_x) + 148) = (double)v27 * 0.00001;
                    *(float *)(HIDWORD(white_x) + 152) = v38 * 0.00001;
                    *(float *)(HIDWORD(white_x) + 156) = (double)__SPAIR64__(HIDWORD(green_y), a27) * 0.00001;
                    return;
                  }
                  goto LABEL_28;
                }
LABEL_24:
                if ( !v34 )
                {
                  v35 = a27 < 0;
                  goto LABEL_26;
                }
LABEL_28:
                png_warning(png_ptr, warning_message: "Ignoring attempt to set negative chromaticity value");
                return;
              }
LABEL_22:
              if ( v33 )
                goto LABEL_28;
              v34 = a25 < 0;
              goto LABEL_24;
            }
LABEL_20:
            if ( v32 )
              goto LABEL_28;
            v33 = green_y < 0;
            goto LABEL_22;
          }
LABEL_18:
          if ( v31 )
            goto LABEL_28;
          v32 = (int)green_x < 0;
          goto LABEL_20;
        }
LABEL_16:
        if ( v30 )
          goto LABEL_28;
        v31 = green_x < 0;
        goto LABEL_18;
      }
    }
    if ( v29 )
      goto LABEL_28;
    v30 = (int)red_x < 0;
    goto LABEL_16;
  }
}


// ========================================================================
// png_set_gAMA
// EA  : 0x8321D448
// RVA : 0x0121D448
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_gAMA(png_struct_def *png_ptr, png_info_struct *info_ptr, long double file_gamma)
{
  double v4; // fp0

  v4 = *(double *)&file_gamma;
  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    if ( *(double *)&file_gamma > 21474.83 )
    {
      png_warning(png_ptr, warning_message: "Limiting gamma to 21474.83");
      v4 = 21474.83;
    }
    info_ptr->gamma = v4;
    info_ptr->valid |= 1u;
    LODWORD(info_ptr->scal_pixel_height) = (int)(v4 * 100000.0 + 0.5);
    if ( v4 == 0.0 )
      png_warning(png_ptr, warning_message: "Setting gamma=0");
  }
}


// ========================================================================
// png_set_gAMA_fixed
// EA  : 0x8321D510
// RVA : 0x0121D510
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_gAMA_fixed(png_struct_def *png_ptr, png_info_struct *info_ptr, int int_gamma)
{
  int v5; // r11
  __int64 v6; // r10

  v5 = int_gamma;
  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    if ( int_gamma < 0 )
    {
      png_warning(png_ptr, warning_message: "Setting negative gamma to zero");
      v5 = 0;
    }
    LODWORD(v6) = v5;
    HIDWORD(v6) = info_ptr->valid;
    LODWORD(info_ptr->scal_pixel_height) = v5;
    info_ptr->valid = HIDWORD(v6) | 1;
    info_ptr->gamma = (double)v6 * 0.00001;
    if ( v5 == 0 )
      png_warning(png_ptr, warning_message: "Setting gamma=0");
  }
}


// ========================================================================
// png_set_hIST
// EA  : 0x8321D5D0
// RVA : 0x0121D5D0
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_hIST(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned __int16 *hist)
{
  unsigned __int16 *v6; // r3
  int v7; // r10
  int v8; // r11
  unsigned int v9; // r8
  unsigned int v10; // r7

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    if ( info_ptr->num_palette != 0 && info_ptr->num_palette <= 0x100u )
    {
      png_free_data(png_ptr, info_ptr, mask: 8u, num: 0);
      v6 = (unsigned __int16 *)png_malloc_warn(png_ptr, size: 0x200u);
      png_ptr->hist = v6;
      if ( v6 != nullptr )
      {
        v7 = 0;
        if ( info_ptr->num_palette != 0 )
        {
          v8 = 0;
          do
          {
            ++v7;
            png_ptr->hist[v8] = hist[v8];
            ++v8;
          }
          while ( v7 < info_ptr->num_palette );
        }
        v9 = info_ptr->valid | 0x40;
        v10 = info_ptr->free_me | 8;
        info_ptr->hist = png_ptr->hist;
        info_ptr->valid = v9;
        info_ptr->free_me = v10;
      }
      else
      {
        png_warning(png_ptr, warning_message: "Insufficient memory for hIST chunk data.");
      }
    }
    else
    {
      png_warning(png_ptr, warning_message: "Invalid palette size, hIST allocation skipped.");
    }
  }
}


// ========================================================================
// png_set_IHDR
// EA  : 0x8321D6C0
// RVA : 0x0121D6C0
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_IHDR(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        unsigned int width,
        unsigned int height,
        int bit_depth,
        int color_type,
        int interlace_type,
        int compression_type,
        int filter_type,
        int a10,
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
        int a28)
{
  unsigned __int8 v36; // r9
  unsigned __int8 v37; // r11

  if ( png_ptr == nullptr || info_ptr == nullptr )
    return;
  if ( width == 0 || height == 0 )
    png_error(png_ptr, error_message: "Image width or height is zero in IHDR");
  if ( width > png_ptr->user_width_max || height > png_ptr->user_height_max )
    png_error(png_ptr, error_message: "image size exceeds user limits in IHDR");
  if ( width > 0x7FFFFFFF || height > 0x7FFFFFFF )
    png_error(png_ptr, error_message: "Invalid image size in IHDR");
  if ( width > 0x1FFFFF7E )
    png_warning(png_ptr, warning_message: "Width is too large for libpng to process pixels");
  if ( bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16 )
    png_error(png_ptr, error_message: "Invalid bit depth in IHDR");
  if ( color_type < 0 || color_type == 1 || color_type == 5 || color_type > 6 )
    png_error(png_ptr, error_message: "Invalid color type in IHDR");
  if ( color_type == 3 )
  {
    if ( bit_depth <= 8 )
      goto LABEL_33;
  }
  else if ( color_type != 2 && color_type != 4 && color_type != 6 || bit_depth >= 8 )
  {
    goto LABEL_33;
  }
  png_error(png_ptr, error_message: "Invalid color type/bit depth combination in IHDR");
LABEL_33:
  if ( interlace_type >= 2 )
    png_error(png_ptr, error_message: "Unknown interlace method in IHDR");
  if ( compression_type != 0 )
    png_error(png_ptr, error_message: "Unknown compression method in IHDR");
  if ( (png_ptr->mode & 0x1000) != 0 && png_ptr->mng_features_permitted != 0 )
    png_warning(png_ptr, warning_message: "MNG features are not allowed in a PNG datastream");
  if ( a28 != 0 )
  {
    if ( (png_ptr->mng_features_permitted & 4) == 0
      || a28 != 64
      || (png_ptr->mode & 0x1000) != 0
      || color_type != 2 && color_type != 6 )
    {
      png_error(png_ptr, error_message: "Unknown filter method in IHDR");
    }
    if ( (png_ptr->mode & 0x1000) != 0 )
      png_warning(png_ptr, warning_message: "Invalid filter method in IHDR");
  }
  info_ptr->width = width;
  info_ptr->height = height;
  info_ptr->color_type = color_type;
  info_ptr->bit_depth = bit_depth;
  info_ptr->compression_type = compression_type;
  info_ptr->filter_type = a28;
  info_ptr->interlace_type = interlace_type;
  if ( (unsigned __int8)color_type == 3 || (v36 = 3, (color_type & 2) == 0) )
    v36 = 1;
  info_ptr->channels = v36;
  if ( (color_type & 4) != 0 )
    info_ptr->channels = v36 + 1;
  v37 = bit_depth * info_ptr->channels;
  info_ptr->pixel_depth = v37;
  if ( width <= 0x1FFFFF7E )
  {
    if ( v37 < 8u )
      info_ptr->rowbytes = (v37 * width + 7) >> 3;
    else
      info_ptr->rowbytes = (v37 >> 3) * width;
  }
  else
  {
    info_ptr->rowbytes = 0;
  }
}


// ========================================================================
// png_set_oFFs
// EA  : 0x8321D9C8
// RVA : 0x0121D9C8
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_oFFs(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        int offset_x,
        int offset_y,
        unsigned __int8 unit_type)
{
  unsigned int valid; // r11

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    valid = info_ptr->valid;
    info_ptr->x_offset = offset_x;
    info_ptr->y_offset = offset_y;
    info_ptr->offset_unit_type = unit_type;
    info_ptr->valid = valid | 0x100;
  }
}


// ========================================================================
// png_set_pCAL
// EA  : 0x8321D9F8
// RVA : 0x0121D9F8
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_pCAL(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        char *purpose,
        int X0,
        int X1,
        unsigned __int8 type,
        int nparams,
        char *units,
        char **params,
        int a10,
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
        int a28)
{
  char *v36; // r11
  int v37; // r10
  size_t v38; // r31
  char *v39; // r3
  char *v40; // r11
  int v41; // r10
  size_t v42; // r31
  char *v43; // r3
  char **v44; // r3
  int v45; // r28
  int v46; // r31
  unsigned __int8 *v47; // r11
  unsigned __int8 *v48; // r10
  int v49; // r9
  size_t v50; // r29
  char **pcal_params; // r11
  unsigned int v52; // r8

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    v36 = purpose;
    do
      v37 = (unsigned __int8)*v36++;
    while ( v37 != 0 );
    v38 = v36 - purpose;
    v39 = (char *)png_malloc_warn(png_ptr, size: v36 - purpose);
    info_ptr->pcal_purpose = v39;
    if ( v39 != nullptr )
    {
      memcpy(Dst: v39, Src: purpose, Size: v38);
      info_ptr->pcal_X0 = X0;
      info_ptr->pcal_X1 = X1;
      v40 = units;
      info_ptr->pcal_type = type;
      info_ptr->pcal_nparams = nparams;
      do
        v41 = (unsigned __int8)*v40++;
      while ( v41 != 0 );
      v42 = v40 - units;
      v43 = (char *)png_malloc_warn(png_ptr, size: v40 - units);
      info_ptr->pcal_units = v43;
      if ( v43 != nullptr )
      {
        memcpy(Dst: v43, Src: units, Size: v42);
        v44 = (char **)png_malloc_warn(png_ptr, size: 4 * nparams + 4);
        info_ptr->pcal_params = v44;
        if ( v44 != nullptr )
        {
          v45 = 0;
          v44[nparams] = nullptr;
          if ( nparams <= 0 )
          {
LABEL_19:
            v52 = info_ptr->free_me | 0x80;
            info_ptr->valid |= 0x400u;
            info_ptr->free_me = v52;
          }
          else
          {
            v46 = 0;
            while ( 1 )
            {
              v47 = *(unsigned __int8 **)(v46 * 4 + a28);
              v48 = v47;
              do
                v49 = *v47++;
              while ( v49 != 0 );
              v50 = v47 - v48;
              info_ptr->pcal_params[v46] = (char *)png_malloc_warn(png_ptr, size: v47 - v48);
              pcal_params = info_ptr->pcal_params;
              if ( pcal_params[v46] == nullptr )
                break;
              memcpy(Dst: pcal_params[v46], Src: *(const void **)(v46 * 4 + a28), Size: v50);
              ++v45;
              ++v46;
              if ( v45 >= nparams )
                goto LABEL_19;
            }
            png_warning(png_ptr, warning_message: "Insufficient memory for pCAL parameter.");
          }
        }
        else
        {
          png_warning(png_ptr, warning_message: "Insufficient memory for pCAL params.");
        }
      }
      else
      {
        png_warning(png_ptr, warning_message: "Insufficient memory for pCAL units.");
      }
    }
    else
    {
      png_warning(png_ptr, warning_message: "Insufficient memory for pCAL purpose.");
    }
  }
}


// ========================================================================
// png_set_sCAL
// EA  : 0x8321DBF8
// RVA : 0x0121DBF8
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_sCAL(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        unsigned __int8 unit,
        long double width,
        long double height)
{
  unsigned int valid; // r11

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    valid = info_ptr->valid;
    info_ptr->scal_pixel_width = width;
    info_ptr->scal_unit = unit;
    info_ptr->valid = valid | 0x4000;
  }
}


// ========================================================================
// png_set_pHYs
// EA  : 0x8321DC28
// RVA : 0x0121DC28
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_pHYs(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        unsigned int res_x,
        unsigned int res_y,
        unsigned __int8 unit_type)
{
  unsigned int valid; // r11

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    valid = info_ptr->valid;
    info_ptr->x_pixels_per_unit = res_x;
    info_ptr->y_pixels_per_unit = res_y;
    info_ptr->phys_unit_type = unit_type;
    info_ptr->valid = valid | 0x80;
  }
}


// ========================================================================
// png_set_PLTE
// EA  : 0x8321DC58
// RVA : 0x0121DC58
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_PLTE(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        png_color_struct *palette,
        unsigned int num_palette)
{
  png_color_struct *v8; // r3
  unsigned int v9; // r6
  unsigned int v10; // r7

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    if ( num_palette <= 0x100 )
    {
LABEL_6:
      png_free_data(png_ptr, info_ptr, mask: 0x1000u, num: 0);
      v8 = (png_color_struct *)png_malloc(png_ptr, size: 0x300u);
      png_ptr->palette = v8;
      memset(Dst: v8, Val: 0, Size: 0x300u);
      memcpy(Dst: png_ptr->palette, Src: palette, Size: 3 * num_palette);
      info_ptr->palette = png_ptr->palette;
      png_ptr->num_palette = num_palette;
      v9 = info_ptr->valid | 8;
      v10 = info_ptr->free_me | 0x1000;
      info_ptr->num_palette = num_palette;
      info_ptr->valid = v9;
      info_ptr->free_me = v10;
      return;
    }
    if ( info_ptr->color_type == 3 )
    {
      png_error(png_ptr, error_message: "Invalid palette length");
      goto LABEL_6;
    }
    png_warning(png_ptr, warning_message: "Invalid palette length");
  }
}


// ========================================================================
// png_set_sBIT
// EA  : 0x8321DD38
// RVA : 0x0121DD38
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_sBIT(png_struct_def *png_ptr, png_info_struct *info_ptr, png_color_8_struct *sig_bit)
{
  unsigned __int8 *p_alpha; // r11
  unsigned __int8 *v4; // r10
  int i; // ctr

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    p_alpha = &sig_bit[-1].alpha;
    v4 = &info_ptr->mod_time.second + 1;
    for ( i = 5; i != 0; --i )
      *++v4 = *++p_alpha;
    info_ptr->valid |= 2u;
  }
}


// ========================================================================
// png_set_sRGB_gAMA_and_cHRM
// EA  : 0x8321DD78
// RVA : 0x0121DD78
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_sRGB_gAMA_and_cHRM(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        unsigned __int8 intent,
        long double a4)
{
  unsigned int valid; // r11
  long double v7; // fp8
  long double v8; // fp6
  long double v9; // fp4
  long double v10; // fp2
  int v11; // [sp+8h] [-78h]
  double v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  long double v15; // [sp+10h] [-70h]
  int v16; // [sp+14h] [-6Ch]
  int v17; // [sp+18h] [-68h]
  int v18; // [sp+1Ch] [-64h]
  int v19; // [sp+20h] [-60h]
  long double v20; // [sp+20h] [-60h]
  int v21; // [sp+24h] [-5Ch]
  int v22; // [sp+28h] [-58h]
  int v23; // [sp+2Ch] [-54h]
  int v24; // [sp+30h] [-50h]
  long double v25; // [sp+30h] [-50h]
  int v26; // [sp+34h] [-4Ch]
  int v27; // [sp+38h] [-48h]
  int v28; // [sp+3Ch] [-44h]
  int v29; // [sp+40h] [-40h]
  long double v30; // [sp+40h] [-40h]
  int v31; // [sp+44h] [-3Ch]
  int v32; // [sp+48h] [-38h]
  int v33; // [sp+4Ch] [-34h]
  int v34; // [sp+50h] [-30h]
  int v35; // [sp+58h] [-28h]
  int v36; // [sp+60h] [-20h]

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    valid = info_ptr->valid;
    info_ptr->srgb_intent = intent;
    info_ptr->valid = valid | 0x800;
    *(_QWORD *)&a4 = 0x3FDD1758E0000000LL;
    png_set_gAMA(png_ptr, info_ptr, file_gamma: a4);
    png_set_gAMA_fixed(png_ptr, info_ptr, int_gamma: 45455);
    png_set_cHRM_fixed(
      png_ptr,
      white_x: 0x7A2600008084LL,
      red_x: 0xFA00000080E8LL,
      green_x: 128849018940000LL,
      a5: v11,
      blue_x: v13,
      blue_y: v14,
      a8: v16,
      a9: v17,
      a10: v18,
      a11: v19,
      a12: v21,
      a13: v22,
      a14: v23,
      a15: v24,
      a16: v26,
      a17: v27,
      a18: v28,
      a19: v29,
      a20: v31,
      a21: v32,
      a22: v33,
      a23: v34,
      a24: 15000,
      a25: v35,
      a26: 6000,
      a27: v36);
    *((_QWORD *)&v7 + 1) = 0x3FAEB851E0000000LL;
    *(_QWORD *)&v7 = 0x3FC3333340000000LL;
    *((_QWORD *)&v8 + 1) = 0x3FE3333340000000LL;
    *(_QWORD *)&v8 = 0x3FD3333340000000LL;
    *((_QWORD *)&v9 + 1) = 0x3FD51EB860000000LL;
    *(_QWORD *)&v9 = 0x3FE47AE140000000LL;
    *((_QWORD *)&v10 + 1) = 0x3FD50E5600000000LL;
    *(_QWORD *)&v10 = 0x3FD40346E0000000LL;
    png_set_cHRM(
      png_ptr,
      info_ptr,
      white_x: v10,
      white_y: v9,
      red_x: v8,
      red_y: v7,
      a7: v12,
      green_x: v15,
      green_y: v20,
      blue_x: v25,
      blue_y: v30);
  }
}


// ========================================================================
// png_set_iCCP
// EA  : 0x8321DE80
// RVA : 0x0121DE80
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_iCCP(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        char *name,
        unsigned __int8 compression_type,
        char *profile,
        unsigned int proflen)
{
  char *v12; // r11
  int v13; // r10
  size_t v14; // r28
  char *v15; // r3
  char *v16; // r29
  char *v17; // r3
  char *v18; // r28
  unsigned int valid; // r9
  unsigned int v20; // r8

  if ( png_ptr != nullptr && info_ptr != nullptr && name != nullptr && profile != nullptr )
  {
    v12 = name;
    do
      v13 = (unsigned __int8)*v12++;
    while ( v13 != 0 );
    v14 = v12 - name;
    v15 = (char *)png_malloc_warn(png_ptr, size: v12 - name);
    v16 = v15;
    if ( v15 != nullptr )
    {
      memcpy(Dst: v15, Src: name, Size: v14);
      v17 = (char *)png_malloc_warn(png_ptr, size: proflen);
      v18 = v17;
      if ( v17 != nullptr )
      {
        memcpy(Dst: v17, Src: profile, Size: proflen);
        png_free_data(png_ptr, info_ptr, mask: 0x10u, num: 0);
        valid = info_ptr->valid;
        v20 = info_ptr->free_me | 0x10;
        info_ptr->iccp_proflen = proflen;
        info_ptr->iccp_name = v16;
        info_ptr->iccp_profile = v18;
        info_ptr->iccp_compression = compression_type;
        info_ptr->free_me = v20;
        info_ptr->valid = valid | 0x1000;
      }
      else
      {
        png_free(png_ptr, ptr: v16);
        png_warning(png_ptr, warning_message: "Insufficient memory to process iCCP profile.");
      }
    }
    else
    {
      png_warning(png_ptr, warning_message: "Insufficient memory to process iCCP chunk.");
    }
  }
}


// ========================================================================
// png_set_text_2
// EA  : 0x8321DFB8
// RVA : 0x0121DFB8
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

int __fastcall png_set_text_2(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        png_text_struct *text_ptr,
        int num_text)
{
  int max_text; // r30
  int v9; // r11
  png_text_struct *text; // r31
  int v11; // r11
  png_text_struct *v12; // r3
  png_text_struct *v14; // r3
  int v15; // r24
  const void **p_text; // r28
  int v17; // r11
  png_text_struct *v18; // r31
  unsigned __int8 *v19; // r10
  int v20; // r9
  int v21; // r9
  size_t v22; // r29
  _BYTE *v23; // r10
  unsigned __int8 *v24; // r11
  int v25; // r8
  size_t v26; // r30
  char *v27; // r3
  char *v28; // r3

  if ( png_ptr != nullptr && info_ptr != nullptr && num_text != 0 )
  {
    max_text = info_ptr->max_text;
    v9 = info_ptr->num_text + num_text;
    if ( v9 > max_text )
    {
      text = info_ptr->text;
      if ( text != nullptr )
      {
        v11 = v9 + 8;
        info_ptr->max_text = v11;
        v12 = (png_text_struct *)png_malloc_warn(png_ptr, size: 16 * v11);
        info_ptr->text = v12;
        if ( v12 == nullptr )
        {
          png_free(png_ptr, ptr: text);
          return 1;
        }
        memcpy(Dst: v12, Src: text, Size: 16 * max_text);
        png_free(png_ptr, ptr: text);
      }
      else
      {
        info_ptr->num_text = 0;
        info_ptr->max_text = num_text + 8;
        v14 = (png_text_struct *)png_malloc_warn(png_ptr, size: 16 * (num_text + 8));
        info_ptr->text = v14;
        if ( v14 == nullptr )
          return 1;
        info_ptr->free_me |= 0x4000u;
      }
    }
    v15 = 0;
    if ( num_text > 0 )
    {
      p_text = (const void **)&text_ptr->text;
      do
      {
        v17 = (int)*(p_text - 1);
        v18 = &info_ptr->text[info_ptr->num_text];
        if ( v17 != 0 )
        {
          v19 = (unsigned __int8 *)*(p_text - 1);
          do
            v20 = *v19++;
          while ( v20 != 0 );
          v21 = (int)*(p_text - 2);
          v22 = (size_t)&v19[-v17 - 1];
          if ( v21 > 0 )
          {
            png_warning(png_ptr, warning_message: "iTXt chunk not supported.");
          }
          else
          {
            v23 = *p_text;
            if ( *p_text != nullptr && *v23 != 0 )
            {
              v24 = (unsigned __int8 *)*p_text;
              do
                v25 = *v24++;
              while ( v25 != 0 );
              v18->compression = v21;
              v26 = v24 - v23 - 1;
            }
            else
            {
              v26 = 0;
              v18->compression = -1;
            }
            v27 = (char *)png_malloc_warn(png_ptr, size: v26 + v22 + 4);
            v18->key = v27;
            if ( v27 == nullptr )
              return 1;
            memcpy(Dst: v27, Src: *(p_text - 1), Size: v22);
            v18->key[v22] = 0;
            v28 = &v18->key[v22 + 1];
            v18->text = v28;
            if ( v26 != 0 )
              memcpy(Dst: v28, Src: *p_text, Size: v26);
            v18->text[v26] = 0;
            v18->text_length = v26;
            ++info_ptr->num_text;
          }
        }
        ++v15;
        p_text += 4;
      }
      while ( v15 < num_text );
    }
  }
  return 0;
}


// ========================================================================
// png_set_tIME
// EA  : 0x8321E1D0
// RVA : 0x0121E1D0
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_tIME(png_struct_def *png_ptr, png_info_struct *info_ptr, png_time_struct *mod_time)
{
  if ( png_ptr != nullptr && info_ptr != nullptr && (png_ptr->mode & 0x200) == 0 )
  {
    info_ptr->mod_time = *mod_time;
    info_ptr->valid |= 0x200u;
  }
}


// ========================================================================
// png_set_tRNS
// EA  : 0x8321E228
// RVA : 0x0121E228
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_tRNS(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        unsigned __int8 *trans,
        int num_trans,
        png_color_16_struct *trans_values)
{
  unsigned __int8 *v10; // r3
  int v11; // r11
  unsigned __int16 *p_gray; // r11
  _WORD *v13; // r10
  int i; // ctr
  unsigned int v15; // r8

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    png_free_data(png_ptr, info_ptr, mask: 0x2000u, num: 0);
    if ( trans != nullptr )
    {
      v10 = (unsigned __int8 *)png_malloc(png_ptr, size: 0x100u);
      info_ptr->trans = v10;
      png_ptr->trans = v10;
      if ( num_trans > 0 && num_trans <= 256 )
        memcpy(Dst: info_ptr->trans, Src: trans, Size: num_trans);
    }
    if ( trans_values != nullptr )
    {
      v11 = 1 << info_ptr->bit_depth;
      if ( info_ptr->color_type == 0 && trans_values->gray > v11
        || info_ptr->color_type == 2
        && (trans_values->red > v11 || trans_values->green > v11 || trans_values->blue > v11) )
      {
        png_warning(png_ptr, warning_message: "tRNS chunk has out-of-range samples for bit_depth");
      }
      p_gray = &trans_values[-1].gray;
      v13 = (_WORD *)&info_ptr->trans + 1;
      for ( i = 5; i != 0; --i )
        *++v13 = *++p_gray;
      if ( num_trans == 0 )
        num_trans = 1;
    }
    info_ptr->num_trans = num_trans;
    if ( num_trans != 0 )
    {
      v15 = info_ptr->free_me | 0x2000;
      info_ptr->valid |= 0x10u;
      info_ptr->free_me = v15;
    }
  }
}


// ========================================================================
// png_set_sPLT
// EA  : 0x8321E360
// RVA : 0x0121E360
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_sPLT(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        png_sPLT_struct *entries,
        int nentries)
{
  png_sPLT_struct *v8; // r3
  png_sPLT_struct *v9; // r25
  int v10; // r26
  int *p_nentries; // r30
  unsigned __int8 *v12; // r10
  png_sPLT_struct *v13; // r31
  int v14; // r9
  unsigned int v15; // r29
  char *v16; // r3
  png_sPLT_entry_struct *v17; // r3
  unsigned int free_me; // r9
  unsigned int v19; // r8
  unsigned int v20; // r7

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    v8 = (png_sPLT_struct *)png_malloc_warn(png_ptr, size: 16 * (info_ptr->splt_palettes_num + nentries));
    v9 = v8;
    if ( v8 != nullptr )
    {
      memcpy(Dst: v8, Src: info_ptr->splt_palettes, Size: 16 * info_ptr->splt_palettes_num);
      png_free(png_ptr, ptr: info_ptr->splt_palettes);
      v10 = 0;
      info_ptr->splt_palettes = nullptr;
      if ( nentries > 0 )
      {
        p_nentries = &entries->nentries;
        do
        {
          v12 = (unsigned __int8 *)*(p_nentries - 3);
          v13 = &v9[info_ptr->splt_palettes_num + v10];
          do
            v14 = *v12++;
          while ( v14 != 0 );
          v15 = (unsigned int)&v12[-*(p_nentries - 3)];
          v16 = (char *)png_malloc_warn(png_ptr, size: v15);
          v13->name = v16;
          if ( v16 != nullptr )
          {
            memcpy(Dst: v16, Src: (const void *)*(p_nentries - 3), Size: v15);
            v17 = (png_sPLT_entry_struct *)png_malloc_warn(png_ptr, size: 10 * *p_nentries);
            v13->entries = v17;
            if ( v17 != nullptr )
            {
              memcpy(Dst: v17, Src: (const void *)*(p_nentries - 1), Size: 10 * *p_nentries);
              v13->nentries = *p_nentries;
              v13->depth = *((_BYTE *)p_nentries - 8);
            }
            else
            {
              png_warning(png_ptr, warning_message: "Out of memory while processing sPLT chunk");
              png_free(png_ptr, ptr: v13->name);
              v13->name = nullptr;
            }
          }
          else
          {
            png_warning(png_ptr, warning_message: "Out of memory while processing sPLT chunk");
          }
          ++v10;
          p_nentries += 4;
        }
        while ( v10 < nentries );
      }
      free_me = info_ptr->free_me;
      v19 = info_ptr->splt_palettes_num + nentries;
      v20 = info_ptr->valid | 0x2000;
      info_ptr->splt_palettes = v9;
      info_ptr->splt_palettes_num = v19;
      info_ptr->valid = v20;
      info_ptr->free_me = free_me | 0x20;
    }
    else
    {
      png_warning(png_ptr, warning_message: "No memory for sPLT palettes.");
    }
  }
}


// ========================================================================
// png_set_unknown_chunks
// EA  : 0x8321E518
// RVA : 0x0121E518
// PDB : w:\tech5\libs\png\pngset.c
// ========================================================================

void __fastcall png_set_unknown_chunks(
        png_struct_def *png_ptr,
        png_info_struct *info_ptr,
        png_unknown_chunk_t *unknowns,
        int num_unknowns)
{
  png_unknown_chunk_t *v8; // r3
  png_unknown_chunk_t *v9; // r27
  int v10; // r28
  unsigned int *p_size; // r30
  char *v12; // r8
  int v13; // ctr
  png_unknown_chunk_t *v14; // r31
  char *v15; // r11
  unsigned __int8 *v16; // r3
  unsigned int free_me; // r10
  unsigned int v18; // r9

  if ( png_ptr != nullptr && info_ptr != nullptr && num_unknowns != 0 )
  {
    v8 = (png_unknown_chunk_t *)png_malloc_warn(png_ptr, size: 20 * (info_ptr->unknown_chunks_num + num_unknowns));
    v9 = v8;
    if ( v8 != nullptr )
    {
      memcpy(Dst: v8, Src: info_ptr->unknown_chunks, Size: 20 * info_ptr->unknown_chunks_num);
      png_free(png_ptr, ptr: info_ptr->unknown_chunks);
      v10 = 0;
      info_ptr->unknown_chunks = nullptr;
      if ( num_unknowns > 0 )
      {
        p_size = &unknowns->size;
        do
        {
          v12 = (char *)p_size - 13;
          v13 = 5;
          v14 = &v9[info_ptr->unknown_chunks_num + v10];
          v15 = (char *)(&v14[-1].location + 3);
          do
          {
            *++v15 = *++v12;
            --v13;
          }
          while ( v13 != 0 );
          v14->name[4] = 0;
          v14->size = *p_size;
          v14->location = png_ptr->mode;
          if ( *p_size != 0 )
          {
            v16 = (unsigned __int8 *)png_malloc_warn(png_ptr, size: *p_size);
            v14->data = v16;
            if ( v16 != nullptr )
            {
              memcpy(Dst: v16, Src: (const void *)*(p_size - 1), Size: *p_size);
            }
            else
            {
              png_warning(png_ptr, warning_message: "Out of memory while processing unknown chunk.");
              v14->size = 0;
            }
          }
          else
          {
            v14->data = nullptr;
          }
          ++v10;
          p_size += 5;
        }
        while ( v10 < num_unknowns );
      }
      free_me = info_ptr->free_me;
      v18 = info_ptr->unknown_chunks_num + num_unknowns;
      info_ptr->unknown_chunks = v9;
      info_ptr->unknown_chunks_num = v18;
      info_ptr->free_me = free_me | 0x200;
    }
    else
    {
      png_warning(png_ptr, warning_message: "Out of memory while processing unknown chunk.");
    }
  }
}

