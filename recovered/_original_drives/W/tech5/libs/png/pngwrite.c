
// ========================================================================
// png_write_info_before_PLTE
// EA  : 0x8321B980
// RVA : 0x0121B980
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_write_info_before_PLTE(png_struct_def *png_ptr, png_info_struct *info_ptr)
{
  long double v4; // fp2
  long double v5; // fp8
  long double v6; // fp6
  long double v7; // fp4
  long double v8; // fp2
  unsigned int unknown_chunks_num; // r11
  png_unknown_chunk_t *unknown_chunks; // r11
  int v11; // r10
  unsigned __int8 *p_location; // r31
  int v13; // r3
  long double v14; // [sp+10h] [-80h]
  long double v15; // [sp+20h] [-70h]
  long double v16; // [sp+30h] [-60h]
  long double v17; // [sp+40h] [-50h]

  if ( png_ptr != nullptr && info_ptr != nullptr && (png_ptr->mode & 0x400) == 0 )
  {
    png_write_sig(png_ptr);
    if ( (png_ptr->mode & 0x1000) != 0 && png_ptr->mng_features_permitted != 0 )
    {
      png_warning(png_ptr, warning_message: "MNG features are not allowed in a PNG datastream");
      png_ptr->mng_features_permitted = 0;
    }
    png_write_IHDR(
      png_ptr,
      width: info_ptr->width,
      height: info_ptr->height,
      bit_depth: info_ptr->bit_depth,
      color_type: info_ptr->color_type,
      compression_type: info_ptr->compression_type,
      filter_type: info_ptr->filter_type,
      interlace_type: info_ptr->interlace_type);
    if ( (info_ptr->valid & 1) != 0 )
    {
      *(double *)&v4 = info_ptr->gamma;
      png_write_gAMA(png_ptr, file_gamma: v4);
    }
    if ( (info_ptr->valid & 0x800) != 0 )
      png_write_sRGB(png_ptr, srgb_intent: info_ptr->srgb_intent);
    if ( (info_ptr->valid & 0x1000) != 0 )
      png_write_iCCP(
        png_ptr,
        name: info_ptr->iccp_name,
        compression_type: 0,
        profile: info_ptr->iccp_profile,
        profile_len: info_ptr->iccp_proflen);
    if ( (info_ptr->valid & 2) != 0 )
      png_write_sBIT(png_ptr, sbit: &info_ptr->sig_bit, color_type: info_ptr->color_type);
    if ( (info_ptr->valid & 4) != 0 )
    {
      *((double *)&v5 + 1) = info_ptr->y_blue;
      *(double *)&v5 = info_ptr->x_blue;
      *((double *)&v6 + 1) = info_ptr->y_green;
      *(double *)&v6 = info_ptr->x_green;
      *((double *)&v7 + 1) = info_ptr->y_red;
      *(double *)&v7 = info_ptr->x_red;
      *((double *)&v8 + 1) = info_ptr->y_white;
      *(double *)&v8 = info_ptr->x_white;
      png_write_cHRM(
        png_ptr,
        white_x: v8,
        white_y: v7,
        red_x: v6,
        red_y: v5,
        green_x: v14,
        green_y: v15,
        blue_x: v16,
        blue_y: v17);
    }
    unknown_chunks_num = info_ptr->unknown_chunks_num;
    if ( unknown_chunks_num != 0 )
    {
      v11 = unknown_chunks_num;
      unknown_chunks = info_ptr->unknown_chunks;
      if ( unknown_chunks < &unknown_chunks[v11] )
      {
        p_location = &unknown_chunks->location;
        do
        {
          v13 = png_handle_as_unknown(png_ptr, chunk_name: p_location - 16);
          if ( v13 != 1
            && *p_location != 0
            && (*p_location & 2) == 0
            && (*p_location & 4) == 0
            && ((*(p_location - 13) & 0x20) != 0 || v13 == 3 || (png_ptr->flags & 0x10000) != 0) )
          {
            if ( *((_DWORD *)p_location - 1) == 0 )
              png_warning(png_ptr, warning_message: "Writing zero-length unknown chunk");
            png_write_chunk(
              png_ptr,
              chunk_name: p_location - 16,
              data: *((unsigned __int8 **)p_location - 2),
              length: *((_DWORD *)p_location - 1));
          }
          p_location += 20;
        }
        while ( (png_unknown_chunk_t *)(p_location - 16) < &info_ptr->unknown_chunks[info_ptr->unknown_chunks_num] );
      }
    }
    png_ptr->mode |= 0x400u;
  }
}


// ========================================================================
// png_write_info
// EA  : 0x8321BBC8
// RVA : 0x0121BBC8
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_write_info(png_struct_def *png_ptr, png_info_struct *info_ptr)
{
  long double v4; // fp4
  int v5; // r11
  unsigned __int8 *v6; // r10
  signed int v7; // r29
  int v8; // r30
  int v9; // r25
  int v10; // r30
  int compression; // r11
  unsigned int unknown_chunks_num; // r11
  png_unknown_chunk_t *unknown_chunks; // r11
  int v14; // r10
  unsigned __int8 *p_location; // r30
  int v16; // r3

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    png_write_info_before_PLTE(png_ptr, info_ptr);
    if ( (info_ptr->valid & 8) != 0 )
    {
      png_write_PLTE(png_ptr, palette: info_ptr->palette, num_pal: info_ptr->num_palette);
    }
    else if ( info_ptr->color_type == 3 )
    {
      png_error(png_ptr, error_message: "Valid palette required for paletted images");
    }
    if ( (info_ptr->valid & 0x10) != 0 )
    {
      if ( (png_ptr->transformations & 0x80000) != 0 && info_ptr->color_type == 3 )
      {
        v5 = 0;
        if ( info_ptr->num_trans != 0 )
        {
          do
          {
            v6 = &info_ptr->trans[v5++];
            *v6 = -1 - *v6;
          }
          while ( v5 < info_ptr->num_trans );
        }
      }
      png_write_tRNS(
        png_ptr,
        trans: info_ptr->trans,
        tran: &info_ptr->trans_values,
        num_trans: info_ptr->num_trans,
        color_type: info_ptr->color_type);
    }
    if ( (info_ptr->valid & 0x20) != 0 )
      png_write_bKGD(png_ptr, back: &info_ptr->background, color_type: info_ptr->color_type);
    if ( (info_ptr->valid & 0x40) != 0 )
      png_write_hIST(png_ptr, hist: info_ptr->hist, num_hist: info_ptr->num_palette);
    if ( (info_ptr->valid & 0x100) != 0 )
      png_write_oFFs(
        png_ptr,
        x_offset: info_ptr->x_offset,
        y_offset: info_ptr->y_offset,
        unit_type: info_ptr->offset_unit_type);
    if ( (info_ptr->valid & 0x400) != 0 )
      png_write_pCAL(
        png_ptr,
        purpose: info_ptr->pcal_purpose,
        X0: info_ptr->pcal_X0,
        X1: info_ptr->pcal_X1,
        type: info_ptr->pcal_type,
        nparams: info_ptr->pcal_nparams,
        units: info_ptr->pcal_units,
        params: info_ptr->pcal_params);
    if ( (info_ptr->valid & 0x4000) != 0 )
      png_write_sCAL(png_ptr, unit: info_ptr->scal_unit, width: info_ptr->scal_pixel_width, height: v4);
    if ( (info_ptr->valid & 0x80) != 0 )
      png_write_pHYs(
        png_ptr,
        x_pixels_per_unit: info_ptr->x_pixels_per_unit,
        y_pixels_per_unit: info_ptr->y_pixels_per_unit,
        unit_type: info_ptr->phys_unit_type);
    if ( (info_ptr->valid & 0x200) != 0 )
    {
      png_write_tIME(png_ptr, mod_time: &info_ptr->mod_time);
      png_ptr->mode |= 0x200u;
    }
    if ( (info_ptr->valid & 0x2000) != 0 )
    {
      v7 = 0;
      if ( (int)info_ptr->splt_palettes_num > 0 )
      {
        v8 = 0;
        do
        {
          png_write_sPLT(png_ptr, spalette: &info_ptr->splt_palettes[v8]);
          ++v7;
          ++v8;
        }
        while ( v7 < (signed int)info_ptr->splt_palettes_num );
      }
    }
    v9 = 0;
    if ( info_ptr->num_text > 0 )
    {
      v10 = 0;
      while ( 1 )
      {
        compression = info_ptr->text[v10].compression;
        if ( compression > 0 )
          break;
        if ( compression != 0 )
        {
          if ( compression == -1 )
          {
            png_write_tEXt(png_ptr, key: info_ptr->text[v10].key, text: info_ptr->text[v10].text, text_len: 0);
            goto LABEL_39;
          }
        }
        else
        {
          png_write_zTXt(
            png_ptr,
            key: info_ptr->text[v10].key,
            text: info_ptr->text[v10].text,
            text_len: 0,
            compression: info_ptr->text[v10].compression);
          info_ptr->text[v10].compression = -2;
        }
LABEL_40:
        ++v9;
        ++v10;
        if ( v9 >= info_ptr->num_text )
          goto LABEL_41;
      }
      png_warning(png_ptr, warning_message: "Unable to write international text");
LABEL_39:
      info_ptr->text[v10].compression = -3;
      goto LABEL_40;
    }
LABEL_41:
    unknown_chunks_num = info_ptr->unknown_chunks_num;
    if ( unknown_chunks_num != 0 )
    {
      v14 = unknown_chunks_num;
      unknown_chunks = info_ptr->unknown_chunks;
      if ( unknown_chunks < &unknown_chunks[v14] )
      {
        p_location = &unknown_chunks->location;
        do
        {
          v16 = png_handle_as_unknown(png_ptr, chunk_name: p_location - 16);
          if ( v16 != 1
            && *p_location != 0
            && (*p_location & 2) != 0
            && (*p_location & 4) == 0
            && ((*(p_location - 13) & 0x20) != 0 || v16 == 3 || (png_ptr->flags & 0x10000) != 0) )
          {
            png_write_chunk(
              png_ptr,
              chunk_name: p_location - 16,
              data: *((unsigned __int8 **)p_location - 2),
              length: *((_DWORD *)p_location - 1));
          }
          p_location += 20;
        }
        while ( (png_unknown_chunk_t *)(p_location - 16) < &info_ptr->unknown_chunks[info_ptr->unknown_chunks_num] );
      }
    }
  }
}


// ========================================================================
// png_write_end
// EA  : 0x8321BF88
// RVA : 0x0121BF88
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_write_end(png_struct_def *png_ptr, png_info_struct *info_ptr)
{
  int v4; // r25
  int v5; // r31
  int compression; // r11
  unsigned int unknown_chunks_num; // r11
  png_unknown_chunk_t *unknown_chunks; // r11
  int v9; // r10
  unsigned __int8 *p_location; // r31
  int v11; // r3

  if ( png_ptr != nullptr )
  {
    if ( (png_ptr->mode & 4) == 0 )
      png_error(png_ptr, error_message: "No IDATs written into file");
    if ( info_ptr != nullptr )
    {
      if ( (info_ptr->valid & 0x200) != 0 && (png_ptr->mode & 0x200) == 0 )
        png_write_tIME(png_ptr, mod_time: &info_ptr->mod_time);
      v4 = 0;
      if ( info_ptr->num_text > 0 )
      {
        v5 = 0;
        while ( 1 )
        {
          compression = info_ptr->text[v5].compression;
          if ( compression > 0 )
            break;
          if ( compression < 0 )
          {
            if ( compression == -1 )
            {
              png_write_tEXt(png_ptr, key: info_ptr->text[v5].key, text: info_ptr->text[v5].text, text_len: 0);
              goto LABEL_16;
            }
          }
          else
          {
            png_write_zTXt(
              png_ptr,
              key: info_ptr->text[v5].key,
              text: info_ptr->text[v5].text,
              text_len: 0,
              compression: info_ptr->text[v5].compression);
            info_ptr->text[v5].compression = -2;
          }
LABEL_17:
          ++v4;
          ++v5;
          if ( v4 >= info_ptr->num_text )
            goto LABEL_18;
        }
        png_warning(png_ptr, warning_message: "Unable to write international text");
LABEL_16:
        info_ptr->text[v5].compression = -3;
        goto LABEL_17;
      }
LABEL_18:
      unknown_chunks_num = info_ptr->unknown_chunks_num;
      if ( unknown_chunks_num != 0 )
      {
        v9 = unknown_chunks_num;
        unknown_chunks = info_ptr->unknown_chunks;
        if ( unknown_chunks < &unknown_chunks[v9] )
        {
          p_location = &unknown_chunks->location;
          do
          {
            v11 = png_handle_as_unknown(png_ptr, chunk_name: p_location - 16);
            if ( v11 != 1
              && *p_location != 0
              && (*p_location & 8) != 0
              && ((*(p_location - 13) & 0x20) != 0 || v11 == 3 || (png_ptr->flags & 0x10000) != 0) )
            {
              png_write_chunk(
                png_ptr,
                chunk_name: p_location - 16,
                data: *((unsigned __int8 **)p_location - 2),
                length: *((_DWORD *)p_location - 1));
            }
            p_location += 20;
          }
          while ( (png_unknown_chunk_t *)(p_location - 16) < &info_ptr->unknown_chunks[info_ptr->unknown_chunks_num] );
        }
      }
    }
    png_ptr->mode |= 8u;
    png_write_IEND(png_ptr);
  }
}


// ========================================================================
// png_write_flush
// EA  : 0x8321C188
// RVA : 0x0121C188
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_write_flush(png_struct_def *png_ptr)
{
  z_stream_s *p_zstream; // r29
  char *msg; // r4
  unsigned int avail_out; // r11
  unsigned int zbuf_size; // r10
  unsigned int v6; // r10
  unsigned int v7; // r10

  if ( png_ptr != nullptr && png_ptr->row_number < png_ptr->num_rows )
  {
    p_zstream = &png_ptr->zstream;
    while ( 1 )
    {
      if ( deflate(strm: p_zstream, flush: 2) != 0 )
      {
        msg = png_ptr->zstream.msg;
        if ( msg == nullptr )
          msg = "zlib error";
        png_error(png_ptr, error_message: msg);
      }
      avail_out = png_ptr->zstream.avail_out;
      if ( avail_out != 0 )
        break;
      png_write_IDAT(png_ptr, data: png_ptr->zbuf, length: png_ptr->zbuf_size);
      zbuf_size = png_ptr->zbuf_size;
      png_ptr->zstream.next_out = png_ptr->zbuf;
      png_ptr->zstream.avail_out = zbuf_size;
    }
    v6 = png_ptr->zbuf_size;
    if ( v6 != avail_out )
    {
      png_write_IDAT(png_ptr, data: png_ptr->zbuf, length: v6 - avail_out);
      v7 = png_ptr->zbuf_size;
      png_ptr->zstream.next_out = png_ptr->zbuf;
      png_ptr->zstream.avail_out = v7;
    }
    png_ptr->flush_rows = 0;
    png_flush(png_ptr);
  }
}


// ========================================================================
// png_write_destroy
// EA  : 0x8321C260
// RVA : 0x0121C260
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_write_destroy(png_struct_def *png_ptr)
{
  void (__fastcall *error_fn)(png_struct_def *, const char *); // r30
  void (__fastcall *warning_fn)(png_struct_def *, const char *); // r29
  void *error_ptr; // r28
  void (__fastcall *free_fn)(png_struct_def *, void *); // r27
  _BYTE v6[1344]; // [sp+50h] [-570h] BYREF

  deflateEnd(strm: &png_ptr->zstream);
  png_free(png_ptr, ptr: png_ptr->zbuf);
  png_free(png_ptr, ptr: png_ptr->row_buf);
  png_free(png_ptr, ptr: png_ptr->prev_row);
  png_free(png_ptr, ptr: png_ptr->sub_row);
  png_free(png_ptr, ptr: png_ptr->up_row);
  png_free(png_ptr, ptr: png_ptr->avg_row);
  png_free(png_ptr, ptr: png_ptr->paeth_row);
  png_free(png_ptr, ptr: png_ptr->time_buffer);
  png_free(png_ptr, ptr: png_ptr->prev_filters);
  png_free(png_ptr, ptr: png_ptr->filter_weights);
  png_free(png_ptr, ptr: png_ptr->inv_filter_weights);
  png_free(png_ptr, ptr: png_ptr->filter_costs);
  png_free(png_ptr, ptr: png_ptr->inv_filter_costs);
  memcpy(Dst: v6, Src: png_ptr, Size: sizeof(v6));
  error_fn = png_ptr->error_fn;
  warning_fn = png_ptr->warning_fn;
  error_ptr = png_ptr->error_ptr;
  free_fn = png_ptr->free_fn;
  memset(Dst: png_ptr, Val: 0, Size: sizeof(png_struct_def));
  png_ptr->error_fn = error_fn;
  png_ptr->warning_fn = warning_fn;
  png_ptr->error_ptr = error_ptr;
  png_ptr->free_fn = free_fn;
  memcpy(Dst: png_ptr, Src: v6, Size: 0x540u);
}


// ========================================================================
// png_set_filter_heuristics
// EA  : 0x8321C370
// RVA : 0x0121C370
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_set_filter_heuristics(
        png_struct_def *png_ptr,
        int heuristic_method,
        int num_weights,
        long double *filter_weights,
        long double *filter_costs)
{
  int v6; // r29
  int v9; // r11
  int i; // ctr
  int v11; // r11
  int j; // ctr
  int v13; // r7
  int v14; // r11
  double *v15; // r10
  int v16; // r9
  int v17; // r8
  int v18; // r11
  double *v19; // r10
  int v20; // ctr
  double v21; // fp0
  double v22; // fp0
  double v23; // fp0
  double v24; // fp0
  double v25; // fp0

  v6 = num_weights;
  if ( png_ptr != nullptr )
  {
    if ( heuristic_method < 3 )
    {
      if ( heuristic_method == 0 )
        heuristic_method = 1;
      if ( num_weights < 0 || filter_weights == nullptr || heuristic_method == 1 )
        v6 = 0;
      png_ptr->num_prev_filters = v6;
      png_ptr->heuristic_method = heuristic_method;
      if ( v6 > 0 )
      {
        if ( png_ptr->prev_filters == nullptr )
        {
          png_ptr->prev_filters = (unsigned __int8 *)png_malloc(png_ptr, size: v6);
          v9 = 0;
          for ( i = v6; i != 0; --i )
            png_ptr->prev_filters[v9++] = -1;
        }
        if ( png_ptr->filter_weights == nullptr )
        {
          png_ptr->filter_weights = (unsigned __int16 *)png_malloc(png_ptr, size: 2 * v6);
          png_ptr->inv_filter_weights = (unsigned __int16 *)png_malloc(png_ptr, size: 2 * v6);
          v11 = 0;
          for ( j = v6; j != 0; --j )
          {
            png_ptr->filter_weights[v11] = 256;
            png_ptr->inv_filter_weights[v11++] = 256;
          }
        }
        v13 = 0;
        if ( v6 >= 4 )
        {
          v14 = 0;
          v15 = (double *)(filter_weights + 1);
          do
          {
            if ( *(v15 - 2) >= 0.0 )
            {
              png_ptr->inv_filter_weights[v14] = (__int64)(*(v15 - 2) * 256.0 + 0.5);
              png_ptr->filter_weights[v14] = (__int64)(256.0 / *(v15 - 2) + 0.5);
            }
            else
            {
              png_ptr->filter_weights[v14] = 256;
              png_ptr->inv_filter_weights[v14] = 256;
            }
            if ( *(v15 - 1) >= 0.0 )
            {
              png_ptr->inv_filter_weights[v14 + 1] = (__int64)(*(v15 - 1) * 256.0 + 0.5);
              png_ptr->filter_weights[v14 + 1] = (__int64)(256.0 / *(v15 - 1) + 0.5);
            }
            else
            {
              png_ptr->filter_weights[v14 + 1] = 256;
              png_ptr->inv_filter_weights[v14 + 1] = 256;
            }
            v16 = v14 * 2 + 6;
            v17 = v14 * 2 + 4;
            if ( *v15 >= 0.0 )
            {
              *(unsigned __int16 *)((char *)png_ptr->inv_filter_weights + v17) = (__int64)(*v15 * 256.0 + 0.5);
              *(unsigned __int16 *)((char *)png_ptr->filter_weights + v17) = (__int64)(256.0 / *v15 + 0.5);
            }
            else
            {
              *(unsigned __int16 *)((char *)png_ptr->filter_weights + v17) = 256;
              *(unsigned __int16 *)((char *)png_ptr->inv_filter_weights + v17) = 256;
            }
            if ( v15[1] >= 0.0 )
            {
              *(unsigned __int16 *)((char *)png_ptr->inv_filter_weights + v16) = (__int64)(v15[1] * 256.0 + 0.5);
              *(unsigned __int16 *)((char *)png_ptr->filter_weights + v16) = (__int64)(256.0 / v15[1] + 0.5);
            }
            else
            {
              *(unsigned __int16 *)((char *)png_ptr->filter_weights + v16) = 256;
              *(unsigned __int16 *)((char *)png_ptr->inv_filter_weights + v16) = 256;
            }
            v13 += 4;
            v15 += 4;
            v14 += 4;
          }
          while ( v13 < v6 - 3 );
        }
        if ( v13 < v6 )
        {
          v18 = v13;
          v19 = (double *)&filter_weights[v13 / 2u];
          v20 = v6 - v13;
          do
          {
            if ( *v19 >= 0.0 )
            {
              png_ptr->inv_filter_weights[v18] = (__int64)(*v19 * 256.0 + 0.5);
              png_ptr->filter_weights[v18] = (__int64)(256.0 / *v19 + 0.5);
            }
            else
            {
              png_ptr->filter_weights[v18] = 256;
              png_ptr->inv_filter_weights[v18] = 256;
            }
            ++v19;
            ++v18;
            --v20;
          }
          while ( v20 != 0 );
        }
      }
      if ( png_ptr->filter_costs == nullptr )
      {
        png_ptr->filter_costs = (unsigned __int16 *)png_malloc(png_ptr, size: 0xAu);
        png_ptr->inv_filter_costs = (unsigned __int16 *)png_malloc(png_ptr, size: 0xAu);
        *png_ptr->filter_costs = 8;
        *png_ptr->inv_filter_costs = 8;
        png_ptr->filter_costs[1] = 8;
        png_ptr->inv_filter_costs[1] = 8;
        png_ptr->filter_costs[2] = 8;
        png_ptr->inv_filter_costs[2] = 8;
        png_ptr->filter_costs[3] = 8;
        png_ptr->inv_filter_costs[3] = 8;
        png_ptr->filter_costs[4] = 8;
        png_ptr->inv_filter_costs[4] = 8;
      }
      if ( filter_costs != nullptr && (v21 = *(double *)filter_costs, *(double *)filter_costs >= 0.0) )
      {
        if ( v21 >= 1.0 )
        {
          *png_ptr->inv_filter_costs = (__int64)(8.0 / v21 + 0.5);
          *png_ptr->filter_costs = (__int64)(*(double *)filter_costs * 8.0 + 0.5);
        }
      }
      else
      {
        *png_ptr->filter_costs = 8;
        *png_ptr->inv_filter_costs = 8;
      }
      if ( filter_costs != nullptr && (v22 = *((double *)filter_costs + 1)) >= 0.0 )
      {
        if ( v22 >= 1.0 )
        {
          png_ptr->inv_filter_costs[1] = (__int64)(8.0 / v22 + 0.5);
          png_ptr->filter_costs[1] = (__int64)(*((double *)filter_costs + 1) * 8.0 + 0.5);
        }
      }
      else
      {
        png_ptr->filter_costs[1] = 8;
        png_ptr->inv_filter_costs[1] = 8;
      }
      if ( filter_costs != nullptr && (v23 = *((double *)filter_costs + 2)) >= 0.0 )
      {
        if ( v23 >= 1.0 )
        {
          png_ptr->inv_filter_costs[2] = (__int64)(8.0 / v23 + 0.5);
          png_ptr->filter_costs[2] = (__int64)(*((double *)filter_costs + 2) * 8.0 + 0.5);
        }
      }
      else
      {
        png_ptr->filter_costs[2] = 8;
        png_ptr->inv_filter_costs[2] = 8;
      }
      if ( filter_costs != nullptr && (v24 = *((double *)filter_costs + 3)) >= 0.0 )
      {
        if ( v24 >= 1.0 )
        {
          png_ptr->inv_filter_costs[3] = (__int64)(8.0 / v24 + 0.5);
          png_ptr->filter_costs[3] = (__int64)(*((double *)filter_costs + 3) * 8.0 + 0.5);
        }
      }
      else
      {
        png_ptr->filter_costs[3] = 8;
        png_ptr->inv_filter_costs[3] = 8;
      }
      if ( filter_costs != nullptr && (v25 = *((double *)filter_costs + 4)) >= 0.0 )
      {
        if ( v25 >= 1.0 )
        {
          png_ptr->inv_filter_costs[4] = (__int64)(8.0 / v25 + 0.5);
          png_ptr->filter_costs[4] = (__int64)(*((double *)filter_costs + 4) * 8.0 + 0.5);
        }
      }
      else
      {
        png_ptr->filter_costs[4] = 8;
        png_ptr->inv_filter_costs[4] = 8;
      }
    }
    else
    {
      png_warning(png_ptr, warning_message: "Unknown filter heuristic method");
    }
  }
}


// ========================================================================
// png_create_write_struct_2
// EA  : 0x8321C998
// RVA : 0x0121C998
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

png_struct_def *__fastcall png_create_write_struct_2(
        const char *user_png_ver,
        void *error_ptr,
        void (__fastcall *error_fn)(png_struct_def *, const char *),
        void (__fastcall *warn_fn)(png_struct_def *, const char *),
        void *mem_ptr,
        void *(__fastcall *malloc_fn)(png_struct_def *, unsigned int),
        void (__fastcall *free_fn)(png_struct_def *, void *))
{
  png_struct_def *struct_2; // r3
  int v9; // r31
  int v10; // r11
  char *header_ver; // r3
  int v12; // r11
  const char *v13; // r3
  png_struct_def *v14; // [sp+50h] [-80h]
  char v15[112]; // [sp+60h] [-70h] BYREF

  struct_2 = (png_struct_def *)png_create_struct_2(type: 1, malloc_fn, mem_ptr);
  v14 = struct_2;
  if ( struct_2 == nullptr )
    return nullptr;
  struct_2->user_width_max = 1000000;
  struct_2->user_height_max = 1000000;
  if ( setjmp(a1: struct_2) != 0 )
  {
    png_free(png_ptr: v14, ptr: v14->zbuf);
    v14->zbuf = nullptr;
    png_destroy_struct(struct_ptr: v14);
    return nullptr;
  }
  png_set_mem_fn(png_ptr: v14, mem_ptr, malloc_fn, free_fn);
  png_set_error_fn(png_ptr: v14, error_ptr, error_fn, warning_fn: warn_fn);
  if ( user_png_ver != nullptr )
  {
    v9 = 0;
    do
    {
      if ( user_png_ver[v9] != png_get_header_ver(png_ptr: nullptr)[v9] )
        v14->flags |= 0x20000u;
      v10 = (unsigned __int8)png_get_header_ver(png_ptr: nullptr)[v9++];
    }
    while ( v10 != 0 );
  }
  if ( (v14->flags & 0x20000) != 0 )
  {
    if ( user_png_ver != nullptr )
    {
      header_ver = png_get_header_ver(png_ptr: nullptr);
      v12 = *user_png_ver;
      if ( v12 == *header_ver
        && (v12 != 49
         || *((unsigned __int8 *)user_png_ver + 2) == (unsigned __int8)png_get_header_ver(png_ptr: nullptr)[2])
        && (*user_png_ver != 48 || user_png_ver[2] >= 57) )
      {
        goto LABEL_19;
      }
      snprintf_0(
        string: v15,
        count: 0x50u,
        format: "Application was compiled with png.h from libpng-%.20s",
        user_png_ver);
      png_warning(png_ptr: v14, warning_message: v15);
    }
    v13 = png_get_header_ver(png_ptr: nullptr);
    snprintf_0(string: v15, count: 0x50u, format: "Application  is  running with png.c from libpng-%.20s", v13);
    png_warning(png_ptr: v14, warning_message: v15);
    v14->flags = 0;
    png_error(png_ptr: v14, error_message: "Incompatible libpng version in application and library");
  }
LABEL_19:
  v14->zbuf_size = 0x2000;
  v14->zbuf = (unsigned __int8 *)png_malloc(png_ptr: v14, size: 0x2000u);
  png_set_write_fn(png_ptr: v14, io_ptr: nullptr, write_data_fn: nullptr, output_flush_fn: nullptr);
  png_set_filter_heuristics(
    png_ptr: v14,
    heuristic_method: 0,
    num_weights: 1,
    filter_weights: nullptr,
    filter_costs: nullptr);
  if ( setjmp(a1: v14) != 0 )
    abort();
  return v14;
}


// ========================================================================
// png_write_image
// EA  : 0x8321CBE8
// RVA : 0x0121CBE8
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_write_image(png_struct_def *png_ptr, unsigned __int8 **image)
{
  int v4; // r3
  int v5; // r24
  unsigned int v6; // r27
  void **v7; // r28
  void *v8; // r29
  unsigned int pass; // r11
  unsigned __int8 usr_bit_depth; // r9
  unsigned __int8 color_type; // r7
  unsigned __int8 usr_channels; // r8
  unsigned int usr_width; // r10
  unsigned int v14; // r11
  int v15; // r6
  int v16; // r5
  void (__fastcall *write_row_fn)(png_struct_def *, unsigned int, int); // r11

  if ( png_ptr != nullptr )
  {
    v4 = png_set_interlace_handling(png_ptr);
    if ( v4 > 0 )
    {
      v5 = v4;
      while ( 1 )
      {
        v6 = 0;
        v7 = (void **)image;
        if ( png_ptr->height != 0 )
          break;
LABEL_54:
        if ( --v5 == 0 )
          return;
      }
      while ( 1 )
      {
        v8 = *v7;
        if ( png_ptr->row_number == 0 && png_ptr->pass == 0 )
        {
          if ( (png_ptr->mode & 0x400) == 0 )
            png_error(png_ptr, error_message: "png_write_info was never called before png_write_row.");
          png_write_start_row(png_ptr);
        }
        if ( png_ptr->interlaced != 0 && (png_ptr->transformations & 2) != 0 )
        {
          pass = png_ptr->pass;
          if ( pass <= 6 )
          {
            if ( pass == 1 )
            {
              if ( (png_ptr->row_number & 7) != 0 || png_ptr->width < 5 )
                goto LABEL_45;
            }
            else if ( pass == 2 )
            {
              if ( (png_ptr->row_number & 7) != 4 )
                goto LABEL_45;
            }
            else if ( pass == 3 && png_ptr->pass != 0 )
            {
              if ( (png_ptr->row_number & 3) != 0 || png_ptr->width < 3 )
                goto LABEL_45;
            }
            else if ( pass == 4 && png_ptr->pass != 0 )
            {
              if ( (png_ptr->row_number & 3) != 2 )
                goto LABEL_45;
            }
            else if ( pass == 5 && png_ptr->pass != 0 )
            {
              if ( (png_ptr->row_number & 1) != 0 || png_ptr->width < 2 )
                goto LABEL_45;
            }
            else if ( png_ptr->pass != 0 )
            {
              if ( (png_ptr->row_number & 1) == 0 )
                goto LABEL_45;
            }
            else if ( (png_ptr->row_number & 7) != 0 )
            {
              goto LABEL_45;
            }
          }
        }
        usr_bit_depth = png_ptr->usr_bit_depth;
        color_type = png_ptr->color_type;
        usr_channels = png_ptr->usr_channels;
        usr_width = png_ptr->usr_width;
        png_ptr->row_info.channels = usr_channels;
        png_ptr->row_info.bit_depth = usr_bit_depth;
        png_ptr->row_info.color_type = color_type;
        png_ptr->row_info.width = usr_width;
        v14 = (unsigned __int8)(usr_bit_depth * usr_channels);
        png_ptr->row_info.pixel_depth = v14;
        if ( v14 < 8 )
          v15 = (v14 * usr_width + 7) >> 3;
        else
          v15 = (v14 >> 3) * usr_width;
        png_ptr->row_info.rowbytes = v15;
        png_memcpy_check(png_ptr, s1: png_ptr->row_buf + 1, s2: v8, length: v15);
        if ( png_ptr->interlaced == 0
          || (unsigned int)(v16 = png_ptr->pass) >= 6
          || (png_ptr->transformations & 2) == 0
          || (png_do_write_interlace(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1, pass: v16),
              png_ptr->row_info.width != 0) )
        {
          if ( png_ptr->transformations != 0 )
            png_do_write_transformations(png_ptr);
          if ( (png_ptr->mng_features_permitted & 4) != 0 && png_ptr->filter_type == 64 )
            png_do_write_intrapixel(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
          png_write_find_filter(png_ptr, row_info: &png_ptr->row_info);
          write_row_fn = png_ptr->write_row_fn;
          if ( write_row_fn != nullptr )
            write_row_fn(a1: png_ptr, a2: png_ptr->row_number, a3: png_ptr->pass);
          goto LABEL_53;
        }
LABEL_45:
        png_write_finish_row(png_ptr);
LABEL_53:
        ++v6;
        ++v7;
        if ( v6 >= png_ptr->height )
          goto LABEL_54;
      }
    }
  }
}


// ========================================================================
// png_destroy_write_struct
// EA  : 0x8321CEF0
// RVA : 0x0121CEF0
// PDB : w:\tech5\libs\png\pngwrite.c
// ========================================================================

void __fastcall png_destroy_write_struct(png_struct_def **png_ptr_ptr, png_info_struct **info_ptr_ptr)
{
  png_struct_def *v4; // r31
  void (__fastcall *free_fn)(png_struct_def *, void *); // r30
  void *mem_ptr; // r29
  png_info_struct *v7; // r28

  v4 = nullptr;
  free_fn = nullptr;
  mem_ptr = nullptr;
  if ( png_ptr_ptr != nullptr )
  {
    v4 = *png_ptr_ptr;
    free_fn = (*png_ptr_ptr)->free_fn;
    mem_ptr = (*png_ptr_ptr)->mem_ptr;
  }
  if ( info_ptr_ptr != nullptr )
  {
    v7 = *info_ptr_ptr;
    if ( *info_ptr_ptr != nullptr )
    {
      if ( v4 != nullptr )
      {
        png_free_data(png_ptr: v4, info_ptr: *info_ptr_ptr, mask: 0x7FFFu, num: -1);
        if ( v4->num_chunk_list != 0 )
        {
          png_free(png_ptr: v4, ptr: v4->chunk_list);
          v4->chunk_list = nullptr;
          v4->num_chunk_list = 0;
        }
      }
      png_destroy_struct_2(struct_ptr: v7, free_fn, mem_ptr);
      *info_ptr_ptr = nullptr;
    }
  }
  if ( v4 != nullptr )
  {
    png_write_destroy(png_ptr: v4);
    png_destroy_struct_2(struct_ptr: v4, free_fn, mem_ptr);
    *png_ptr_ptr = nullptr;
  }
}

