
// ========================================================================
// png_crc_read
// EA  : 0x83228880
// RVA : 0x01228880
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_crc_read(png_struct_def *png_ptr, unsigned __int8 *buf, unsigned int length)
{
  if ( png_ptr != nullptr )
  {
    png_read_data(png_ptr, data: buf, length);
    png_calculate_crc(png_ptr, ptr: buf, length);
  }
}


// ========================================================================
// png_crc_error
// EA  : 0x832288C0
// RVA : 0x012288C0
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

BOOL __fastcall png_crc_error(png_struct_def *png_ptr)
{
  BOOL v2; // r30
  unsigned __int8 v4[8]; // [sp+50h] [-20h] BYREF

  if ( (png_ptr->chunk_name[0] & 0x20) != 0 )
    v2 = (png_ptr->flags & 0x300) != 768;
  else
    v2 = (png_ptr->flags & 0x800) == 0;
  png_read_data(png_ptr, data: v4, length: 4u);
  return v2 && png_ptr->crc != ((((__ROL4__(v4[0], 8) + v4[1]) << 8) + v4[2]) << 8) + v4[3];
}


// ========================================================================
// png_decompress_chunk
// EA  : 0x83228988
// RVA : 0x01228988
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

char *__fastcall png_decompress_chunk(
        png_struct_def *png_ptr,
        int comp_type,
        char *chunkdata,
        unsigned int chunklength,
        size_t prefix_size,
        unsigned int *newlength)
{
  unsigned __int8 *zbuf; // r11
  unsigned int zbuf_size; // r10
  size_t v13; // r29
  z_stream_s *p_zstream; // r20
  _DWORD *v15; // r30
  unsigned int v16; // r3
  unsigned int v17; // r21
  unsigned int avail_out; // r11
  unsigned int v19; // r10
  void *v20; // r28
  unsigned int v21; // r10
  char *msg; // r4
  char v24[176]; // [sp+50h] [-B0h] BYREF

  if ( comp_type == 0 )
  {
    zbuf = png_ptr->zbuf;
    zbuf_size = png_ptr->zbuf_size;
    v13 = 0;
    png_ptr->zstream.avail_in = chunklength - prefix_size;
    p_zstream = &png_ptr->zstream;
    png_ptr->zstream.next_in = (unsigned __int8 *)&chunkdata[prefix_size];
    v15 = nullptr;
    png_ptr->zstream.next_out = zbuf;
    png_ptr->zstream.avail_out = zbuf_size;
    if ( chunklength != prefix_size )
    {
      while ( 1 )
      {
        v16 = inflate(strm: p_zstream, flush: 1);
        v17 = v16;
        if ( v16 > 1 )
          break;
        avail_out = png_ptr->zstream.avail_out;
        if ( avail_out == 0 || v16 == 1 )
        {
          v19 = png_ptr->zbuf_size;
          if ( v15 != nullptr )
          {
            v20 = v15;
            v15 = png_malloc_warn(png_ptr, size: v13 - avail_out + v19 + 1);
            if ( v15 == nullptr )
            {
              png_free(png_ptr, ptr: v20);
              png_free(png_ptr, ptr: chunkdata);
              png_error(png_ptr, error_message: "Not enough memory to decompress chunk..");
            }
            memcpy(Dst: v15, Src: v20, Size: v13);
            png_free(png_ptr, ptr: v20);
            memcpy(Dst: (char *)v15 + v13, Src: png_ptr->zbuf, Size: png_ptr->zbuf_size - png_ptr->zstream.avail_out);
            v13 = v13 - png_ptr->zstream.avail_out + png_ptr->zbuf_size;
          }
          else
          {
            v13 = prefix_size - avail_out + v19;
            v15 = png_malloc_warn(png_ptr, size: v13 + 1);
            if ( v15 == nullptr )
            {
              png_free(png_ptr, ptr: chunkdata);
              png_error(png_ptr, error_message: "Not enough memory to decompress chunk.");
            }
            memcpy(Dst: (char *)v15 + prefix_size, Src: png_ptr->zbuf, Size: v13 - prefix_size);
            memcpy(Dst: v15, Src: chunkdata, Size: prefix_size);
          }
          *((_BYTE *)v15 + v13) = 0;
          if ( v17 == 1 )
            goto LABEL_37;
          v21 = png_ptr->zbuf_size;
          png_ptr->zstream.next_out = png_ptr->zbuf;
          png_ptr->zstream.avail_out = v21;
        }
        if ( png_ptr->zstream.avail_in == 0 )
          goto LABEL_26;
      }
      msg = png_ptr->zstream.msg;
      if ( msg == nullptr )
        msg = "Error decoding compressed text";
      png_warning(png_ptr, warning_message: (png_struct_def *)msg);
      inflateReset(strm: p_zstream);
      png_ptr->zstream.avail_in = 0;
      if ( v15 == nullptr )
      {
        v13 = prefix_size + 32;
        v15 = png_malloc_warn(png_ptr, size: prefix_size + 32);
        if ( v15 == nullptr )
        {
          png_free(png_ptr, ptr: chunkdata);
          png_error(png_ptr, error_message: "Not enough memory to decompress chunk");
        }
        memcpy(Dst: v15, Src: chunkdata, Size: prefix_size);
      }
      *((_BYTE *)v15 + v13 - 1) = 0;
      v13 = chunkdata - (char *)v15 + chunklength - 1;
      if ( v13 >= 0x1F )
        v13 = 31;
      memcpy(Dst: (char *)v15 + prefix_size, Src: "Error decoding compressed text", Size: v13);
LABEL_26:
      switch ( v17 )
      {
        case 1u:
          goto LABEL_37;
        case 0xFFFFFFFB:
          snprintf_0(
            string: v24,
            count: 0x34u,
            format: "Buffer error in compressed datastream in %s chunk",
            png_ptr->chunk_name);
LABEL_32:
          png_warning(png_ptr, warning_message: (png_struct_def *)v24);
          v13 = prefix_size;
          if ( v15 == nullptr )
          {
            v15 = png_malloc_warn(png_ptr, size: prefix_size + 1);
            if ( v15 == nullptr )
            {
              png_free(png_ptr, ptr: chunkdata);
              png_error(png_ptr, error_message: "Not enough memory for text.");
            }
            memcpy(Dst: v15, Src: chunkdata, Size: prefix_size);
          }
          *((_BYTE *)v15 + prefix_size) = 0;
LABEL_37:
          inflateReset(strm: p_zstream);
          png_ptr->zstream.avail_in = 0;
          png_free(png_ptr, ptr: chunkdata);
          *newlength = v13;
          return (char *)v15;
        case 0xFFFFFFFD:
          snprintf_0(
            string: v24,
            count: 0x34u,
            format: "Data error in compressed datastream in %s chunk",
            png_ptr->chunk_name);
          goto LABEL_32;
        default:
          break;
      }
    }
    snprintf_0(string: v24, count: 0x34u, format: "Incomplete compressed datastream in %s chunk", png_ptr->chunk_name);
    goto LABEL_32;
  }
  snprintf_0(string: v24, count: 0x32u, format: "Unknown zTXt compression type %d", comp_type);
  png_warning(png_ptr, warning_message: (png_struct_def *)v24);
  chunkdata[prefix_size] = 0;
  *newlength = prefix_size;
  return chunkdata;
}


// ========================================================================
// png_check_chunk_name
// EA  : 0x83228D00
// RVA : 0x01228D00
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_check_chunk_name(png_struct_def *png_ptr, unsigned __int8 *chunk_name)
{
  unsigned int v2; // r11
  unsigned int v3; // r11
  unsigned int v4; // r11
  unsigned int v5; // r11

  v2 = *chunk_name;
  if ( v2 < 0x41
    || v2 > 0x7A
    || v2 > 0x5A && v2 < 0x61
    || (v3 = chunk_name[1]) < 0x41
    || v3 > 0x7A
    || v3 > 0x5A && v3 < 0x61
    || (v4 = chunk_name[2]) < 0x41
    || v4 > 0x7A
    || v4 > 0x5A && v4 < 0x61
    || (v5 = chunk_name[3]) < 0x41
    || v5 > 0x7A
    || v5 > 0x5A && v5 < 0x61 )
  {
    png_chunk_error(png_ptr, error_message: "invalid chunk type");
  }
}


// ========================================================================
// png_combine_row
// EA  : 0x83228DA0
// RVA : 0x01228DA0
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_combine_row(png_struct_def *png_ptr, unsigned __int8 *row, int mask)
{
  unsigned int pixel_depth; // r10
  unsigned int width; // r9
  unsigned int v6; // r9
  unsigned __int8 *row_buf; // r10
  unsigned __int8 *v8; // r30
  size_t v9; // r29
  char *v10; // r31
  unsigned __int8 v11; // r27
  unsigned int v12; // r26
  int v13; // r7
  unsigned __int8 *v14; // r10
  int v15; // r8
  int v16; // r6
  int v17; // r5
  int v18; // r11
  unsigned int v19; // ctr
  int v20; // r8
  unsigned __int8 *v21; // r10
  int v22; // r7
  int v23; // r6
  int v24; // r5
  int v25; // r11
  unsigned int v26; // ctr
  int v27; // r8
  unsigned __int8 *v28; // r10
  int v29; // r7
  int v30; // r6
  int v31; // r5
  int v32; // r11
  unsigned int v33; // ctr

  if ( mask == 255 )
  {
    pixel_depth = png_ptr->row_info.pixel_depth;
    width = png_ptr->width;
    if ( pixel_depth < 8 )
      memcpy(Dst: row, Src: png_ptr->row_buf + 1, Size: (width * pixel_depth + 7) >> 3);
    else
      memcpy(Dst: row, Src: png_ptr->row_buf + 1, Size: (pixel_depth >> 3) * width);
  }
  else
  {
    v6 = png_ptr->row_info.pixel_depth;
    row_buf = png_ptr->row_buf;
    switch ( v6 )
    {
      case 1u:
        v27 = 128;
        v28 = row_buf + 1;
        if ( (png_ptr->transformations & 0x10000) != 0 )
        {
          v29 = 0;
          v30 = 7;
          v31 = 1;
        }
        else
        {
          v29 = 7;
          v30 = 0;
          v31 = -1;
        }
        v32 = v29;
        if ( png_ptr->width != 0 )
        {
          v33 = png_ptr->width;
          do
          {
            if ( (v27 & mask) != 0 )
              *row = (32639 >> (7 - v32)) & *row | (((*v28 >> v32) & 1) << v32);
            if ( v32 == v30 )
            {
              v32 = v29;
              ++v28;
              ++row;
            }
            else
            {
              v32 += v31;
            }
            if ( v27 == 1 )
              v27 = 128;
            else
              v27 >>= 1;
            --v33;
          }
          while ( v33 != 0 );
        }
        break;
      case 2u:
        v20 = 128;
        v21 = row_buf + 1;
        if ( (png_ptr->transformations & 0x10000) != 0 )
        {
          v22 = 0;
          v23 = 6;
          v24 = 2;
        }
        else
        {
          v22 = 6;
          v23 = 0;
          v24 = -2;
        }
        v25 = v22;
        if ( png_ptr->width != 0 )
        {
          v26 = png_ptr->width;
          do
          {
            if ( (v20 & mask) != 0 )
              *row = (16191 >> (6 - v25)) & *row | (((*v21 >> v25) & 3) << v25);
            if ( v25 == v23 )
            {
              v25 = v22;
              ++v21;
              ++row;
            }
            else
            {
              v25 += v24;
            }
            if ( v20 == 1 )
              v20 = 128;
            else
              v20 >>= 1;
            --v26;
          }
          while ( v26 != 0 );
        }
        break;
      case 4u:
        v13 = 128;
        v14 = row_buf + 1;
        if ( (png_ptr->transformations & 0x10000) != 0 )
        {
          v15 = 0;
          v16 = 4;
          v17 = 4;
        }
        else
        {
          v15 = 4;
          v16 = 0;
          v17 = -4;
        }
        v18 = v15;
        if ( png_ptr->width != 0 )
        {
          v19 = png_ptr->width;
          do
          {
            if ( (v13 & mask) != 0 )
              *row = (3855 >> (4 - v18)) & *row | (((*v14 >> v18) & 0xF) << v18);
            if ( v18 == v16 )
            {
              v18 = v15;
              ++v14;
              ++row;
            }
            else
            {
              v18 += v17;
            }
            if ( v13 == 1 )
              v13 = 128;
            else
              v13 >>= 1;
            --v19;
          }
          while ( v19 != 0 );
        }
        break;
      default:
        v8 = row;
        v9 = v6 >> 3;
        v10 = (char *)(row_buf + 1);
        v11 = 0x80;
        if ( png_ptr->width != 0 )
        {
          v12 = png_ptr->width;
          do
          {
            if ( (v11 & (unsigned __int8)mask) != 0 )
              memcpy(Dst: v8, Src: v10, Size: v9);
            v10 += v9;
            v8 += v9;
            if ( v11 == 1 )
              v11 = 0x80;
            else
              v11 >>= 1;
            --v12;
          }
          while ( v12 != 0 );
        }
        break;
    }
  }
}


// ========================================================================
// png_do_read_interlace
// EA  : 0x832290E0
// RVA : 0x012290E0
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_do_read_interlace(png_struct_def *png_ptr)
{
  unsigned __int8 *row_buf; // r10
  int v2; // r5
  int pass; // r9
  int v4; // r6
  unsigned int transformations; // r8
  int v6; // r4
  unsigned __int8 *v7; // r10
  png_row_info_struct *p_row_info; // r24
  unsigned int width; // r11
  unsigned int pixel_depth; // r9
  int v11; // r25
  int v12; // r26
  size_t v13; // r31
  unsigned __int8 *v14; // r28
  unsigned __int8 *v15; // r29
  unsigned int v16; // r27
  int m; // r30
  unsigned __int8 *v18; // r3
  unsigned __int8 *v19; // r9
  int v20; // r6
  int v21; // r8
  int v22; // r10
  int v23; // r7
  unsigned int v24; // r31
  int v25; // r11
  int k; // ctr
  unsigned __int8 *v27; // r3
  unsigned __int8 *v28; // r8
  bool v29; // zf
  int v30; // r9
  int v31; // r10
  int v32; // r5
  int v33; // r7
  unsigned int v34; // r31
  int v35; // r11
  int j; // ctr
  unsigned __int8 *v37; // r3
  unsigned __int8 *v38; // r9
  char v39; // r10
  int v40; // r8
  int v41; // r10
  int v42; // r6
  int v43; // r7
  unsigned int v44; // r31
  int v45; // r11
  int i; // ctr
  unsigned int v47; // r11
  _BYTE v48[16]; // [sp+50h] [-80h] BYREF
  _DWORD v49[28]; // [sp+60h] [-70h] BYREF

  row_buf = png_ptr->row_buf;
  v2 = 4;
  pass = png_ptr->pass;
  v4 = 2;
  transformations = png_ptr->transformations;
  v6 = 1;
  v49[0] = 8;
  v7 = row_buf + 1;
  v49[1] = 8;
  v49[2] = 4;
  p_row_info = &png_ptr->row_info;
  v49[3] = 4;
  v49[4] = 2;
  v49[5] = 2;
  v49[6] = 1;
  if ( v7 != nullptr && png_ptr != (png_struct_def *)-1536 )
  {
    width = p_row_info->width;
    v11 = v49[pass];
    pixel_depth = png_ptr->row_info.pixel_depth;
    v12 = p_row_info->width * v11;
    switch ( pixel_depth )
    {
      case 1u:
        v37 = &v7[(width - 1) >> 3];
        v38 = &v7[(unsigned int)(v12 - 1) >> 3];
        v39 = width - 1;
        if ( (transformations & 0x10000) != 0 )
        {
          v40 = v39 & 7;
          v41 = ((_BYTE)v12 - 1) & 7;
          v42 = 7;
          v43 = 0;
          v6 = -1;
        }
        else
        {
          v40 = 7 - (v39 & 7);
          v41 = 7 - (((_BYTE)v12 - 1) & 7);
          v42 = 0;
          v43 = 7;
        }
        v44 = 0;
        if ( width != 0 )
        {
          do
          {
            v45 = (*v37 >> v40) & 1;
            if ( v11 > 0 )
            {
              for ( i = v11; i != 0; --i )
              {
                *v38 = (32639 >> (7 - v41)) & *v38 | ((_BYTE)v45 << v41);
                if ( v41 == v43 )
                {
                  v41 = v42;
                  --v38;
                }
                else
                {
                  v41 += v6;
                }
              }
            }
            if ( v40 == v43 )
            {
              v40 = v42;
              --v37;
            }
            else
            {
              v40 += v6;
            }
            ++v44;
          }
          while ( v44 < p_row_info->width );
        }
        break;
      case 2u:
        v27 = &v7[(width - 1) >> 2];
        v29 = (transformations & 0x10000) == 0;
        v28 = &v7[(unsigned int)(v12 - 1) >> 2];
        if ( v29 )
        {
          v30 = 2 * (3 - (((_BYTE)width - 1) & 3));
          v31 = 2 * (3 - (((_BYTE)v12 - 1) & 3));
          v32 = 0;
          v33 = 6;
        }
        else
        {
          v30 = (2 * (_BYTE)width - 1) & 6;
          v31 = (2 * (_BYTE)v12 - 1) & 6;
          v32 = 6;
          v33 = 0;
          v4 = -2;
        }
        v34 = 0;
        if ( width != 0 )
        {
          do
          {
            v35 = (*v27 >> v30) & 3;
            if ( v11 > 0 )
            {
              for ( j = v11; j != 0; --j )
              {
                *v28 = (16191 >> (6 - v31)) & *v28 | ((_BYTE)v35 << v31);
                if ( v31 == v33 )
                {
                  v31 = v32;
                  --v28;
                }
                else
                {
                  v31 += v4;
                }
              }
            }
            if ( v30 == v33 )
            {
              v30 = v32;
              --v27;
            }
            else
            {
              v30 += v4;
            }
            ++v34;
          }
          while ( v34 < p_row_info->width );
        }
        break;
      case 4u:
        v18 = &v7[(width - 1) >> 1];
        v19 = &v7[(unsigned int)(v12 - 1) >> 1];
        if ( (transformations & 0x10000) != 0 )
        {
          v20 = 4;
          v21 = (-1 - 4 * (_BYTE)width) & 4;
          v22 = (-1 - 4 * v12) & 4;
          v23 = 0;
          v2 = -4;
        }
        else
        {
          v21 = 4 - ((4 * (width - 1)) & 4);
          v22 = 4 - ((4 * (v12 - 1)) & 4);
          v23 = 4;
          v20 = 0;
        }
        v24 = 0;
        if ( width != 0 )
        {
          do
          {
            v25 = (*v18 >> v21) & 0xF;
            if ( v11 > 0 )
            {
              for ( k = v11; k != 0; --k )
              {
                *v19 = (3855 >> (4 - v22)) & *v19 | ((_BYTE)v25 << v22);
                if ( v22 == v23 )
                {
                  v22 = v20;
                  --v19;
                }
                else
                {
                  v22 += v2;
                }
              }
            }
            if ( v21 == v23 )
            {
              v21 = v20;
              --v18;
            }
            else
            {
              v21 += v2;
            }
            ++v24;
          }
          while ( v24 < p_row_info->width );
        }
        break;
      default:
        v13 = pixel_depth >> 3;
        v14 = &v7[(width - 1) * (pixel_depth >> 3)];
        v15 = &v7[(v12 - 1) * (pixel_depth >> 3)];
        v16 = 0;
        if ( width != 0 )
        {
          do
          {
            memcpy(Dst: v48, Src: v14, Size: v13);
            if ( v11 > 0 )
            {
              for ( m = v11; m != 0; --m )
              {
                memcpy(Dst: v15, Src: v48, Size: v13);
                v15 -= v13;
              }
            }
            ++v16;
            v14 -= v13;
          }
          while ( v16 < p_row_info->width );
        }
        break;
    }
    v47 = p_row_info->pixel_depth;
    p_row_info->width = v12;
    if ( v47 < 8 )
      p_row_info->rowbytes = (v47 * v12 + 7) >> 3;
    else
      p_row_info->rowbytes = (v47 >> 3) * v12;
  }
}


// ========================================================================
// png_read_filter_row
// EA  : 0x83229518
// RVA : 0x01229518
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_read_filter_row(
        png_struct_def *png_ptr,
        png_row_info_struct *row_info,
        unsigned __int8 *row,
        unsigned __int8 *prev_row,
        unsigned int filter)
{
  unsigned __int8 *v6; // r9
  unsigned int rowbytes; // r10
  unsigned int v8; // r11
  unsigned int v9; // r8
  unsigned __int8 *v10; // r11
  unsigned __int8 *v11; // r10
  unsigned int v12; // ctr
  char v13; // r9
  int v14; // r10
  unsigned int v15; // ctr
  unsigned __int8 *v16; // r11
  unsigned __int8 v17; // r7
  unsigned __int8 v18; // r7
  unsigned __int8 *v19; // r11
  int v20; // r10
  unsigned int v21; // r7
  int v22; // ctr
  int v23; // r10
  int v24; // r6
  unsigned int i; // ctr
  int v26; // r9
  unsigned __int8 *v27; // r10
  unsigned __int8 *v28; // r11
  int v29; // r8
  unsigned int v30; // r6
  int v31; // ctr
  unsigned __int8 v32; // r8
  unsigned __int8 *v33; // r4
  unsigned int v34; // ctr
  int v35; // r3
  unsigned __int8 *v36; // r31
  int v37; // r8
  int v38; // r6
  int v39; // r7
  signed int v40; // r10
  signed int v41; // r11
  signed int v42; // r5
  char v43; // r11

  v6 = prev_row;
  if ( filter > 4 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Ignoring bad adaptive filter type");
    *row = 0;
  }
  else if ( filter != 0 )
  {
    switch ( filter )
    {
      case 1u:
        rowbytes = row_info->rowbytes;
        v8 = (row_info->pixel_depth + 7) >> 3;
        if ( v8 < rowbytes )
        {
          v9 = rowbytes - v8;
          v11 = row - 1;
          v10 = &row[v8 - 1];
          v12 = v9;
          do
          {
            ++v11;
            v13 = *++v10;
            *v10 = *v11 + v13;
            --v12;
          }
          while ( v12 != 0 );
        }
        break;
      case 2u:
        v14 = 0;
        if ( row_info->rowbytes != 0 )
        {
          v15 = row_info->rowbytes;
          v16 = row - 1;
          do
          {
            v17 = prev_row[v14++];
            v18 = v17 + *++v16;
            *v16 = v18;
            --v15;
          }
          while ( v15 != 0 );
        }
        break;
      case 3u:
        v19 = row;
        v20 = (row_info->pixel_depth + 7) >> 3;
        v21 = row_info->rowbytes - v20;
        if ( v20 != 0 )
        {
          v22 = (row_info->pixel_depth + 7) >> 3;
          do
          {
            *v19++ += *v6++ >> 1;
            --v22;
          }
          while ( v22 != 0 );
        }
        v23 = 0;
        if ( v21 != 0 )
        {
          v24 = v6 - v19;
          for ( i = v21; i != 0; --i )
          {
            v26 = row[v23++];
            *v19 += (v19[v24] + v26) >> 1;
            ++v19;
          }
        }
        break;
      default:
        v27 = prev_row;
        v28 = row;
        v29 = (row_info->pixel_depth + 7) >> 3;
        v30 = row_info->rowbytes - v29;
        if ( v29 != 0 )
        {
          v31 = (row_info->pixel_depth + 7) >> 3;
          do
          {
            v32 = *v27++ + *v28;
            *v28++ = v32;
            --v31;
          }
          while ( v31 != 0 );
        }
        if ( v30 != 0 )
        {
          v33 = (unsigned __int8 *)(row - v6);
          v34 = v30;
          v35 = v27 - v6;
          v36 = v28 - 1;
          do
          {
            v37 = *v6;
            v38 = v6[v35];
            v39 = (v6++)[(_DWORD)v33];
            v40 = abs32(v39 - v37);
            v41 = abs32(v38 - v37);
            v42 = abs32(v39 - v37 + v38 - v37);
            if ( v41 > v40 || v41 > v42 )
            {
              if ( v40 <= v42 )
                LOBYTE(v37) = v38;
            }
            else
            {
              LOBYTE(v37) = v39;
            }
            v43 = *++v36;
            *v36 = v43 + v37;
            --v34;
          }
          while ( v34 != 0 );
        }
        break;
    }
  }
}


// ========================================================================
// png_read_start_row
// EA  : 0x83229768
// RVA : 0x01229768
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_read_start_row(png_struct_def *png_ptr)
{
  unsigned int height; // r11
  unsigned int width; // r6
  int v4; // r8
  unsigned int pixel_depth; // r11
  int v6; // r7
  unsigned int v7; // r10
  unsigned int v8; // r10
  unsigned int v9; // r11
  unsigned int v10; // r9
  unsigned int transformations; // r7
  int v12; // r11
  int color_type; // r10
  int v14; // r10
  bool v15; // zf
  int v16; // r10
  int user_transform_depth; // r9
  unsigned int v18; // r10
  unsigned int v19; // r10
  unsigned int v20; // r30
  unsigned __int8 *v21; // r3
  size_t v22; // r6
  unsigned __int8 *v23; // r3
  unsigned int rowbytes; // r11
  _DWORD v25[8]; // [sp+50h] [-60h] BYREF
  _DWORD v26[10]; // [sp+70h] [-40h] BYREF

  png_ptr->zstream.avail_in = 0;
  v25[0] = 0;
  v25[1] = 4;
  v25[2] = 0;
  v25[3] = 2;
  v25[4] = 0;
  v25[5] = 1;
  v25[6] = 0;
  v26[0] = 8;
  v26[1] = 8;
  v26[2] = 4;
  v26[3] = 4;
  v26[4] = 2;
  v26[5] = 2;
  v26[6] = 1;
  png_init_read_transformations(png_ptr);
  if ( png_ptr->interlaced != 0 )
  {
    height = png_ptr->height;
    if ( (png_ptr->transformations & 2) != 0 )
      png_ptr->num_rows = height;
    else
      png_ptr->num_rows = (height + 7) >> 3;
    width = png_ptr->width;
    v4 = __ROL4__(png_ptr->pass, 2);
    pixel_depth = png_ptr->pixel_depth;
    v6 = *(_DWORD *)((char *)v25 + v4);
    v7 = *(_DWORD *)((char *)v26 + v4);
    __twllei(v7, 0);
    v8 = (width - v6 + v7 - 1) / v7;
    png_ptr->iwidth = v8;
    if ( pixel_depth < 8 )
      v9 = ((pixel_depth * v8 + 7) >> 3) + 1;
    else
      v9 = (pixel_depth >> 3) * v8 + 1;
    png_ptr->irowbytes = v9;
  }
  else
  {
    width = png_ptr->width;
    v10 = png_ptr->rowbytes + 1;
    png_ptr->num_rows = png_ptr->height;
    png_ptr->iwidth = width;
    png_ptr->irowbytes = v10;
  }
  transformations = png_ptr->transformations;
  v12 = png_ptr->pixel_depth;
  if ( (transformations & 4) != 0 && png_ptr->bit_depth < 8u )
    v12 = 8;
  if ( (transformations & 0x1000) != 0 )
  {
    color_type = png_ptr->color_type;
    if ( color_type == 3 )
    {
      v12 = png_ptr->num_trans == 0 ? 24 : 32;
    }
    else if ( png_ptr->color_type != 0 )
    {
      if ( color_type == 2 && png_ptr->num_trans != 0 )
        v12 = 4 * v12 / 3;
    }
    else
    {
      if ( v12 < 8 )
        v12 = 8;
      if ( png_ptr->num_trans != 0 )
        v12 *= 2;
    }
  }
  if ( (transformations & 0x8000) != 0 )
  {
    v14 = png_ptr->color_type;
    if ( v14 == 3 )
    {
LABEL_26:
      v12 = 32;
      goto LABEL_33;
    }
    if ( png_ptr->color_type != 0 )
    {
      if ( v14 == 2 )
      {
        v15 = v12 <= 32;
        v12 = 32;
        if ( !v15 )
          v12 = 64;
      }
    }
    else
    {
      if ( v12 > 8 )
        goto LABEL_26;
      v12 = 16;
    }
  }
LABEL_33:
  if ( (transformations & 0x4000) == 0 )
    goto LABEL_46;
  if ( png_ptr->num_trans != 0 && (transformations & 0x1000) != 0
    || (transformations & 0x8000) != 0
    || (v16 = png_ptr->color_type) == 4 )
  {
    v15 = v12 <= 16;
    v12 = 32;
    if ( v15 )
      goto LABEL_46;
    goto LABEL_45;
  }
  if ( v12 > 8 )
  {
    if ( v16 != 6 )
    {
      v12 = 48;
      goto LABEL_46;
    }
LABEL_45:
    v12 = 64;
    goto LABEL_46;
  }
  if ( v16 == 6 )
    v12 = 32;
  else
    v12 = 24;
LABEL_46:
  if ( (transformations & 0x100000) != 0 )
  {
    user_transform_depth = png_ptr->user_transform_depth;
    if ( png_ptr->user_transform_channels * user_transform_depth > v12 )
      v12 = png_ptr->user_transform_channels * user_transform_depth;
  }
  v18 = (width + 7) & 0xFFFFFFF8;
  if ( v12 < 8 )
    v19 = (v12 * v18 + 7) >> 3;
  else
    v19 = ((unsigned int)v12 >> 3) * v18;
  v20 = ((v12 + 7) >> 3) + v19 + 65;
  if ( v20 > png_ptr->old_big_row_buf_size )
  {
    png_free(png_ptr, ptr: png_ptr->big_row_buf);
    v21 = (unsigned __int8 *)png_malloc(png_ptr, size: v20);
    png_ptr->old_big_row_buf_size = v20;
    png_ptr->big_row_buf = v21;
    png_ptr->row_buf = v21 + 32;
  }
  if ( png_ptr->rowbytes == -1 )
    png_error(png_ptr, error_message: "Row has too many bytes to allocate in memory.");
  v22 = png_ptr->rowbytes + 1;
  if ( v22 > png_ptr->old_prev_row_size )
  {
    png_free(png_ptr, ptr: png_ptr->prev_row);
    v23 = (unsigned __int8 *)png_malloc(png_ptr, size: png_ptr->rowbytes + 1);
    rowbytes = png_ptr->rowbytes;
    png_ptr->prev_row = v23;
    v22 = rowbytes + 1;
    png_ptr->old_prev_row_size = rowbytes + 1;
  }
  png_memset_check(png_ptr, s1: png_ptr->prev_row, value: 0, length: v22);
  png_ptr->flags |= 0x40u;
}


// ========================================================================
// png_get_uint_31
// EA  : 0x83229B18
// RVA : 0x01229B18
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

unsigned int __fastcall png_get_uint_31(png_struct_def *png_ptr, unsigned __int8 *buf)
{
  unsigned int v2; // r31

  v2 = ((((__ROL4__(*buf, 8) + buf[1]) << 8) + buf[2]) << 8) + buf[3];
  if ( v2 > 0x7FFFFFFF )
    png_error(png_ptr, error_message: "PNG unsigned integer out of range.");
  return v2;
}


// ========================================================================
// png_crc_finish
// EA  : 0x83229B88
// RVA : 0x01229B88
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

int __fastcall png_crc_finish(png_struct_def *png_ptr, unsigned int skip)
{
  unsigned int zbuf_size; // r29
  unsigned int i; // r30
  unsigned int v5; // r28
  unsigned __int8 *zbuf; // r27
  unsigned __int8 *v7; // r29

  zbuf_size = png_ptr->zbuf_size;
  for ( i = skip; i > zbuf_size; i -= zbuf_size )
  {
    v5 = png_ptr->zbuf_size;
    zbuf = png_ptr->zbuf;
    png_read_data(png_ptr, data: zbuf, length: v5);
    png_calculate_crc(png_ptr, ptr: zbuf, length: v5);
  }
  if ( i != 0 )
  {
    v7 = png_ptr->zbuf;
    png_read_data(png_ptr, data: v7, length: i);
    png_calculate_crc(png_ptr, ptr: v7, length: i);
  }
  if ( !png_crc_error(png_ptr) )
    return 0;
  if ( (png_ptr->chunk_name[0] & 0x20) == 0 )
    goto LABEL_9;
  if ( (png_ptr->flags & 0x200) == 0 )
  {
LABEL_10:
    png_chunk_warning(png_ptr, warning_message: "CRC error");
    return 1;
  }
  if ( (png_ptr->chunk_name[0] & 0x20) == 0 )
  {
LABEL_9:
    if ( (png_ptr->flags & 0x400) != 0 )
      goto LABEL_10;
  }
  png_chunk_error(png_ptr, error_message: "CRC error");
  return 1;
}


// ========================================================================
// png_handle_IHDR
// EA  : 0x83229C98
// RVA : 0x01229C98
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_IHDR(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int v6; // r29
  unsigned int v7; // r30
  int v8; // r8
  int v9; // r7
  bool v10; // cr57
  int v11; // r10
  int v12; // r9
  int v13; // r6
  unsigned __int8 v14; // r11
  unsigned int v15; // r11
  int v16; // r11
  int v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]
  int v21; // [sp+18h] [-88h]
  int v22; // [sp+1Ch] [-84h]
  int v23; // [sp+20h] [-80h]
  int v24; // [sp+24h] [-7Ch]
  int v25; // [sp+28h] [-78h]
  int v26; // [sp+2Ch] [-74h]
  int v27; // [sp+30h] [-70h]
  int v28; // [sp+34h] [-6Ch]
  int v29; // [sp+38h] [-68h]
  int v30; // [sp+3Ch] [-64h]
  int v31; // [sp+40h] [-60h]
  int v32; // [sp+44h] [-5Ch]
  int v33; // [sp+48h] [-58h]
  int v34; // [sp+4Ch] [-54h]
  int v35; // [sp+50h] [-50h]
  unsigned __int8 v36[9]; // [sp+60h] [-40h] BYREF
  unsigned __int8 v37; // [sp+69h] [-37h]
  unsigned __int8 v38; // [sp+6Ah] [-36h]
  unsigned __int8 v39; // [sp+6Bh] [-35h]
  unsigned __int8 v40; // [sp+6Ch] [-34h]

  if ( (png_ptr->mode & 1) != 0 )
    png_error(png_ptr, error_message: "Out of place IHDR");
  if ( length != 13 )
    png_error(png_ptr, error_message: "Invalid IHDR chunk");
  png_ptr->mode |= 1u;
  png_read_data(png_ptr, data: v36, length: 0xDu);
  png_calculate_crc(png_ptr, ptr: v36, length: 0xDu);
  png_crc_finish(png_ptr, skip: 0);
  v6 = ((((__ROL4__(v36[0], 8) + v36[1]) << 8) + v36[2]) << 8) + v36[3];
  if ( v6 > 0x7FFFFFFF )
    png_error(png_ptr, error_message: "PNG unsigned integer out of range.");
  v7 = ((((__ROL4__(v36[4], 8) + v36[5]) << 8) + v36[6]) << 8) + v36[7];
  if ( v7 > 0x7FFFFFFF )
    png_error(png_ptr, error_message: "PNG unsigned integer out of range.");
  v8 = v37;
  v9 = v36[8];
  v10 = v37 > 6u;
  v11 = v38;
  v12 = v40;
  v13 = v39;
  png_ptr->width = v6;
  png_ptr->height = v7;
  png_ptr->color_type = v8;
  png_ptr->bit_depth = v9;
  png_ptr->compression_type = v11;
  png_ptr->filter_type = v13;
  png_ptr->interlaced = v12;
  if ( !v10 && v8 != 1 )
  {
    if ( v8 == 2 )
    {
      v14 = 3;
LABEL_20:
      png_ptr->channels = v14;
      goto LABEL_21;
    }
    if ( v8 != 3 )
    {
      if ( v8 == 4 )
      {
        v14 = 2;
        goto LABEL_20;
      }
      if ( v8 == 5 )
        goto LABEL_21;
      if ( v8 != 0 )
      {
        v14 = 4;
        goto LABEL_20;
      }
    }
    v14 = 1;
    goto LABEL_20;
  }
LABEL_21:
  v15 = (unsigned __int8)(png_ptr->channels * v9);
  png_ptr->pixel_depth = v15;
  if ( v15 < 8 )
    v16 = (v15 * v6 + 7) >> 3;
  else
    v16 = (v15 >> 3) * v6;
  png_ptr->rowbytes = v16;
  png_set_IHDR(
    png_ptr,
    info_ptr,
    width: v6,
    height: v7,
    bit_depth: v9,
    color_type: v8,
    interlace_type: v12,
    compression_type: v11,
    filter_type: v17,
    a10: v18,
    a11: v19,
    a12: v20,
    a13: v21,
    a14: v22,
    a15: v23,
    a16: v24,
    a17: v25,
    a18: v26,
    a19: v27,
    a20: v28,
    a21: v29,
    a22: v30,
    a23: v31,
    a24: v32,
    a25: v33,
    a26: v34,
    a27: v35,
    a28: v13);
}


// ========================================================================
// png_handle_PLTE
// EA  : 0x83229E80
// RVA : 0x01229E80
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_PLTE(png_struct_def *png_ptr, png_info_struct *info_ptr, signed int length)
{
  unsigned int mode; // r11
  png_struct_def *v4; // r31
  const char *v7; // r4
  char *v8; // r4
  int color_type; // r9
  int v10; // r28
  int v11; // r29
  unsigned __int8 *v12; // r30
  unsigned __int8 v13; // r10
  unsigned __int8 v14; // r9
  unsigned __int8 v15[15]; // [sp+50h] [-340h] BYREF
  char v16; // [sp+5Fh] [-331h] BYREF
  png_color_struct v17; // [sp+60h] [-330h] BYREF

  mode = png_ptr->mode;
  v4 = png_ptr;
  if ( (mode & 1) == 0 )
  {
    v7 = "Missing IHDR before PLTE";
LABEL_8:
    png_error(png_ptr, error_message: v7);
    goto LABEL_9;
  }
  if ( (mode & 4) != 0 )
  {
    v8 = "Invalid PLTE after IDAT";
    goto LABEL_5;
  }
  if ( (mode & 2) != 0 )
  {
    v7 = "Duplicate PLTE chunk";
    goto LABEL_8;
  }
LABEL_9:
  color_type = v4->color_type;
  v4->mode |= 2u;
  if ( (color_type & 2) == 0 )
  {
    png_warning(png_ptr: v4, warning_message: (png_struct_def *)"Ignoring PLTE chunk in grayscale PNG");
    png_crc_finish(png_ptr: v4, skip: length);
    return;
  }
  if ( (unsigned int)length > 0x300 || length != 3 * (length / 3u) )
  {
    png_ptr = v4;
    v8 = "Invalid palette chunk";
    if ( color_type == 3 )
    {
      png_error(png_ptr: v4, error_message: "Invalid palette chunk");
      goto LABEL_15;
    }
LABEL_5:
    png_warning(png_ptr, warning_message: (png_struct_def *)v8);
    png_crc_finish(png_ptr: v4, skip: length);
    return;
  }
LABEL_15:
  v10 = length / 3;
  if ( length / 3 > 0 )
  {
    v11 = length / 3;
    v12 = (unsigned __int8 *)&v16;
    do
    {
      png_read_data(png_ptr: v4, data: v15, length: 3u);
      png_calculate_crc(png_ptr: v4, ptr: v15, length: 3u);
      v13 = v15[1];
      --v11;
      v14 = v15[2];
      v12[1] = v15[0];
      v12[2] = v13;
      v12 += 3;
      *v12 = v14;
    }
    while ( v11 != 0 );
  }
  png_crc_finish(png_ptr: v4, skip: 0);
  png_set_PLTE(png_ptr: v4, info_ptr, palette: &v17, num_palette: v10);
  if ( v4->color_type == 3 && info_ptr != nullptr && (info_ptr->valid & 0x10) != 0 )
  {
    if ( v4->num_trans > (unsigned int)(unsigned __int16)v10 )
    {
      png_warning(png_ptr: v4, warning_message: (png_struct_def *)"Truncating incorrect tRNS chunk length");
      v4->num_trans = v10;
    }
    if ( info_ptr->num_trans > (unsigned int)(unsigned __int16)v10 )
    {
      png_warning(png_ptr: v4, warning_message: (png_struct_def *)"Truncating incorrect info tRNS chunk length");
      info_ptr->num_trans = v10;
    }
  }
}


// ========================================================================
// png_handle_IEND
// EA  : 0x8322A068
// RVA : 0x0122A068
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_IEND(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11

  mode = png_ptr->mode;
  if ( (mode & 1) == 0 || (mode & 4) == 0 )
    png_error(png_ptr, error_message: "No image in file");
  png_ptr->mode |= 0x18u;
  if ( length != 0 )
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect IEND chunk length");
  png_crc_finish(png_ptr, skip: length);
}


// ========================================================================
// png_handle_gAMA
// EA  : 0x8322A0F8
// RVA : 0x0122A0F8
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_gAMA(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned int valid; // r11
  long double v8; // fp2
  int v9; // r31
  _iobuf *v10; // r3
  unsigned __int8 v11[8]; // [sp+50h] [-30h] BYREF
  unsigned __int64 v12; // [sp+58h] [-28h]

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid gAMA after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( (mode & 2) != 0 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Out of place gAMA chunk");
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before gAMA");
  }
  if ( info_ptr != nullptr && ((valid = info_ptr->valid) & 1) != 0 && (valid & 0x800) == 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate gAMA chunk");
    png_crc_finish(png_ptr, skip: length);
  }
  else if ( length == 4 )
  {
    png_read_data(png_ptr, data: v11, length: 4u);
    png_calculate_crc(png_ptr, ptr: v11, length: 4u);
    if ( png_crc_finish(png_ptr, skip: 0) == 0 )
    {
      v9 = ((((__ROL4__(v11[0], 8) + v11[1]) << 8) + v11[2]) << 8) + v11[3];
      if ( v9 != 0 )
      {
        if ( info_ptr != nullptr && (info_ptr->valid & 0x800) != 0 && (v9 < 45000 || v9 > 46000) )
        {
          png_warning(
            png_ptr,
            warning_message: (png_struct_def *)"Ignoring incorrect gAMA value when sRGB is also present");
          v10 = _iob_func();
          fprintf(str: v10 + 2, format: "gamma = (%d/100000)\n", v9);
        }
        else
        {
          v12 = __PAIR64__(byte_821B0000, v9);
          *(double *)&v8 = (float)((float)__SPAIR64__(byte_821B0000, v9) * (float)0.0000099999997);
          png_ptr->gamma = (float)__SPAIR64__(byte_821B0000, v9) * (float)0.0000099999997;
          png_set_gAMA(png_ptr, info_ptr, file_gamma: v8);
          png_set_gAMA_fixed(png_ptr, info_ptr, int_gamma: v9);
        }
      }
      else
      {
        png_warning(png_ptr, warning_message: (png_struct_def *)"Ignoring gAMA chunk with gamma=0");
      }
    }
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect gAMA chunk length");
    png_crc_finish(png_ptr, skip: length);
  }
}


// ========================================================================
// png_handle_sBIT
// EA  : 0x8322A318
// RVA : 0x0122A318
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_sBIT(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r10
  char *v7; // r4
  unsigned int channels; // r30
  unsigned __int8 v9; // r10
  unsigned __int8 v10; // r9
  unsigned __int8 v11; // r8
  unsigned __int8 v12; // r11
  unsigned __int8 v13; // r10
  unsigned __int8 v14; // [sp+50h] [-30h] BYREF
  unsigned __int8 v15; // [sp+51h] [-2Fh]
  unsigned __int8 v16; // [sp+52h] [-2Eh]
  unsigned __int8 v17; // [sp+53h] [-2Dh]

  mode = png_ptr->mode;
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      v7 = "Invalid sBIT after IDAT";
LABEL_20:
      png_warning(png_ptr, warning_message: (png_struct_def *)v7);
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( (mode & 2) != 0 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Out of place sBIT chunk");
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before sBIT");
  }
  if ( info_ptr != nullptr && (info_ptr->valid & 2) != 0 )
  {
    v7 = "Duplicate sBIT chunk";
    goto LABEL_20;
  }
  channels = 3;
  if ( png_ptr->color_type != 3 )
    channels = png_ptr->channels;
  if ( length != channels || length > 4 )
  {
    v7 = "Incorrect sBIT chunk length";
    goto LABEL_20;
  }
  png_read_data(png_ptr, data: &v14, length: channels);
  png_calculate_crc(png_ptr, ptr: &v14, length: channels);
  if ( png_crc_finish(png_ptr, skip: 0) == 0 )
  {
    if ( (png_ptr->color_type & 2) != 0 )
    {
      v9 = v16;
      v10 = v17;
      v11 = v14;
      png_ptr->sig_bit.green = v15;
      png_ptr->sig_bit.blue = v9;
      png_ptr->sig_bit.alpha = v10;
      png_ptr->sig_bit.red = v11;
    }
    else
    {
      v12 = v14;
      v13 = v15;
      png_ptr->sig_bit.gray = v14;
      png_ptr->sig_bit.blue = v12;
      png_ptr->sig_bit.alpha = v13;
      png_ptr->sig_bit.red = v12;
      png_ptr->sig_bit.green = v12;
    }
    png_set_sBIT(png_ptr, info_ptr, sig_bit: &png_ptr->sig_bit);
  }
}


// ========================================================================
// png_handle_cHRM
// EA  : 0x8322A4B0
// RVA : 0x0122A4B0
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall png_handle_cHRM(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned int v7; // r4
  unsigned int valid; // r11
  unsigned int v9; // r29
  unsigned int v10; // r11
  __int64 v11; // r24
  int v12; // r29
  int v13; // r6
  int v14; // r26
  int v15; // r25
  int v16; // r29
  int v17; // r6
  int v18; // r27
  int v19; // r28
  __int64 v20; // r4 OVERLAPPED
  _BYTE v21[12]; // r9 OVERLAPPED
  int v22; // r6 OVERLAPPED
  int v23; // r30
  __int64 v24; // fp11
  double v25; // fp29
  double v26; // fp26
  double v27; // fp25
  double v28; // fp24
  _iobuf *v29; // r3
  double v30; // r5
  double v31; // r8
  _iobuf *v32; // r3
  long double v33; // fp8
  long double v34; // fp6
  long double v35; // fp4
  long double v36; // fp2
  double v37; // [sp+8h] [-128h]
  int v38; // [sp+8h] [-128h]
  int v39; // [sp+Ch] [-124h]
  long double v40; // [sp+10h] [-120h]
  int v41; // [sp+10h] [-120h]
  int v42; // [sp+14h] [-11Ch]
  int v43; // [sp+18h] [-118h]
  int v44; // [sp+1Ch] [-114h]
  long double v45; // [sp+20h] [-110h]
  int v46; // [sp+20h] [-110h]
  int v47; // [sp+24h] [-10Ch]
  int v48; // [sp+28h] [-108h]
  int v49; // [sp+2Ch] [-104h]
  long double v50; // [sp+30h] [-100h]
  int v51; // [sp+30h] [-100h]
  int v52; // [sp+34h] [-FCh]
  int v53; // [sp+38h] [-F8h]
  int v54; // [sp+3Ch] [-F4h]
  long double v55; // [sp+40h] [-F0h]
  int v56; // [sp+40h] [-F0h]
  int v57; // [sp+44h] [-ECh]
  int v58; // [sp+48h] [-E8h]
  int v59; // [sp+4Ch] [-E4h]
  int v60; // [sp+50h] [-E0h]
  int v61; // [sp+58h] [-D8h]
  int v62[2]; // [sp+60h] [-D0h] BYREF
  unsigned __int64 v63; // [sp+68h] [-C8h]
  unsigned __int64 v64; // [sp+70h] [-C0h]
  __int64 v65; // [sp+78h] [-B8h]
  __int64 v66; // [sp+80h] [-B0h]
  __int64 v67; // [sp+88h] [-A8h]
  __int64 v68; // [sp+90h] [-A0h]

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM after IDAT");
      v7 = length;
      goto LABEL_44;
    }
    if ( (mode & 2) != 0 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Missing PLTE before cHRM");
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before cHRM");
  }
  if ( info_ptr != nullptr && ((valid = info_ptr->valid) & 4) != 0 && (valid & 0x800) == 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate cHRM chunk");
    v7 = length;
  }
  else if ( length == 32 )
  {
    png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
    png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
    v9 = ((((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0])) << 8) + LOBYTE(v62[0]);
    png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
    png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
    v10 = ((((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0])) << 8) + LOBYTE(v62[0]);
    if ( v9 > 0x13880 || v10 > 0x13880 || v10 + v9 > 0x186A0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM white point");
      v7 = 24;
    }
    else
    {
      v11 = __PAIR64__(v10, v9);
      png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
      png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
      v12 = ((((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0])) << 8) + LOBYTE(v62[0]);
      png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
      png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
      v13 = ((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0]);
      if ( (v13 << 8) + (unsigned int)LOBYTE(v62[0]) + v12 <= 0x186A0 )
      {
        v14 = v12;
        v15 = (v13 << 8) + LOBYTE(v62[0]);
        png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
        png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
        v16 = ((((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0])) << 8) + LOBYTE(v62[0]);
        png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
        png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
        v17 = ((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0]);
        if ( (v17 << 8) + (unsigned int)LOBYTE(v62[0]) + v16 <= 0x186A0 )
        {
          v18 = (v17 << 8) + LOBYTE(v62[0]);
          png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
          png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
          v19 = ((((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0])) << 8) + LOBYTE(v62[0]);
          png_read_data(png_ptr, data: (unsigned __int8 *)v62, length: 4u);
          png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v62, length: 4u);
          *(_DWORD *)&v21[4] = LOBYTE(v62[0]);
          v22 = ((__ROL4__(HIBYTE(v62[0]), 8) + BYTE1(v62[0])) << 8) + BYTE2(v62[0]);
          v23 = (v22 << 8) + LOBYTE(v62[0]);
          if ( (unsigned int)(v23 + v19) <= 0x186A0 )
          {
            *(_QWORD *)&v21[-4] = __PAIR64__(v18, v16);
            *(_DWORD *)v21 = (v22 << 8) + LOBYTE(v62[0]);
            *(__int64 *)((char *)&v20 - 4) = __PAIR64__(v14, HIDWORD(v11));
            v64 = __PAIR64__(v18, v16);
            v65 = *(_QWORD *)&v21[4];
            v68 = v11;
            v24 = *(_QWORD *)&v21[4];
            v63 = __PAIR64__(v14, HIDWORD(v11));
            v67 = v20;
            *(_DWORD *)&v21[4] = v19;
            v66 = *(_QWORD *)v21;
            v25 = (float)((float)v20 * (float)0.0000099999997);
            v26 = (float)((float)v24 * (float)0.0000099999997);
            v27 = (float)((float)*(__int64 *)v21 * (float)0.0000099999997);
            v28 = (float)((float)*(__int64 *)&v21[8] * (float)0.0000099999997);
            if ( info_ptr != nullptr && (info_ptr->valid & 0x800) != 0 )
            {
              if ( (int)v11 < 30270
                || (int)v11 > 32270
                || SHIDWORD(v11) < 31900
                || SHIDWORD(v11) > 33900
                || v14 < 63000
                || v14 > 65000
                || v15 < 32000
                || v15 > 34000
                || v16 < 29000
                || v16 > 31000
                || v18 < 59000
                || v18 > 61000
                || v19 < 14000
                || v19 > 16000
                || v23 < 5000
                || v23 > 7000 )
              {
                png_warning(
                  png_ptr,
                  warning_message: (png_struct_def *)"Ignoring incorrect cHRM value when sRGB is also present");
                v29 = _iob_func();
                v30 = (float)((float)v11 * (float)0.0000099999997);
                v31 = (float)((float)__SPAIR64__(v16, v15) * (float)0.0000099999997);
                fprintf(
                  str: v29 + 2,
                  format: (const char *)HIDWORD(v30),
                  LODWORD(v30),
                  HIDWORD(v25),
                  v31,
                  v30,
                  (float)((float)__SPAIR64__(v14, HIDWORD(v11)) * (float)0.0000099999997),
                  v25,
                  v31);
                v32 = _iob_func();
                fprintf(
                  str: v32 + 2,
                  format: "gx=%f, gy=%f, bx=%f, by=%f\n",
                  (float)((float)__SPAIR64__(v18, v16) * (float)0.0000099999997),
                  v26,
                  v27,
                  v28);
              }
              v7 = 0;
            }
            else
            {
              *((double *)&v33 + 1) = (float)((float)*(__int64 *)&v21[8] * (float)0.0000099999997);
              *(double *)&v33 = (float)((float)*(__int64 *)v21 * (float)0.0000099999997);
              *((double *)&v34 + 1) = (float)((float)v24 * (float)0.0000099999997);
              *(double *)&v34 = (float)((float)__SPAIR64__(v18, v16) * (float)0.0000099999997);
              *((double *)&v35 + 1) = (float)((float)__SPAIR64__(v16, v15) * (float)0.0000099999997);
              *(double *)&v35 = (float)((float)v20 * (float)0.0000099999997);
              *((double *)&v36 + 1) = (float)((float)__SPAIR64__(v14, HIDWORD(v11)) * (float)0.0000099999997);
              *(double *)&v36 = (float)((float)v11 * (float)0.0000099999997);
              png_set_cHRM(
                png_ptr,
                info_ptr,
                white_x: v36,
                white_y: v35,
                red_x: v34,
                red_y: v33,
                a7: v37,
                green_x: v40,
                green_y: v45,
                blue_x: v50,
                blue_y: v55);
              png_set_cHRM_fixed(
                png_ptr,
                white_x: __SPAIR64__(v11, HIDWORD(v11)),
                red_x: __SPAIR64__(v14, v15),
                green_x: __SPAIR64__(v16, v18),
                a5: v38,
                blue_x: v39,
                blue_y: v41,
                a8: v42,
                a9: v43,
                a10: v44,
                a11: v46,
                a12: v47,
                a13: v48,
                a14: v49,
                a15: v51,
                a16: v52,
                a17: v53,
                a18: v54,
                a19: v56,
                a20: v57,
                a21: v58,
                a22: v59,
                a23: v60,
                a24: v19,
                a25: v61,
                a26: v23,
                a27: v62[0]);
              v7 = 0;
            }
          }
          else
          {
            png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM blue point");
            v7 = 0;
          }
        }
        else
        {
          png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM green point");
          v7 = 8;
        }
      }
      else
      {
        png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM red point");
        v7 = 16;
      }
    }
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect cHRM chunk length");
    v7 = length;
  }
LABEL_44:
  png_crc_finish(png_ptr, skip: v7);
}


// ========================================================================
// png_handle_sRGB
// EA  : 0x8322AB30
// RVA : 0x0122AB30
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_sRGB(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  long double v7; // fp2
  unsigned __int8 v8; // r30
  int scal_pixel_height_low; // r11
  int int_gamma; // r28
  _iobuf *v11; // r3
  char *scal_s_width; // r11
  char *scal_s_height; // r11
  unsigned __int8 **row_pointers; // r11
  int v15; // r11
  int int_x_white; // r11
  int int_y_white; // r11
  int int_x_red; // r11
  int int_y_red; // r11
  unsigned __int8 v20[48]; // [sp+50h] [-30h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid sRGB after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( (mode & 2) != 0 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Out of place sRGB chunk");
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before sRGB");
  }
  if ( info_ptr != nullptr && (info_ptr->valid & 0x800) != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate sRGB chunk");
    png_crc_finish(png_ptr, skip: length);
  }
  else if ( length == 1 )
  {
    png_read_data(png_ptr, data: v20, length: 1u);
    png_calculate_crc(png_ptr, ptr: v20, length: 1u);
    if ( png_crc_finish(png_ptr, skip: 0) == 0 )
    {
      v8 = v20[0];
      if ( v20[0] < 4u )
      {
        if ( info_ptr != nullptr )
        {
          if ( (info_ptr->valid & 1) != 0 )
          {
            scal_pixel_height_low = LODWORD(info_ptr->scal_pixel_height);
            if ( scal_pixel_height_low < 45000 || scal_pixel_height_low > 46000 )
            {
              png_warning(
                png_ptr,
                warning_message: (png_struct_def *)"Ignoring incorrect gAMA value when sRGB is also present");
              int_gamma = png_ptr->int_gamma;
              v11 = _iob_func();
              fprintf(str: v11 + 2, format: "incorrect gamma=(%d/100000)\n", int_gamma);
            }
          }
          if ( (info_ptr->valid & 4) != 0 )
          {
            scal_s_width = info_ptr->scal_s_width;
            if ( (int)scal_s_width < 30270
              || (int)scal_s_width > 32270
              || (int)(scal_s_height = info_ptr->scal_s_height) < 31900
              || (int)scal_s_height > 33900
              || (int)(row_pointers = info_ptr->row_pointers) < 63000
              || (int)row_pointers > 65000
              || (v15 = info_ptr->int_gamma) < 32000
              || v15 > 34000
              || (int_x_white = info_ptr->int_x_white) < 29000
              || int_x_white > 31000
              || (int_y_white = info_ptr->int_y_white) < 59000
              || int_y_white > 61000
              || (int_x_red = info_ptr->int_x_red) < 14000
              || int_x_red > 16000
              || (int_y_red = info_ptr->int_y_red) < 5000
              || int_y_red > 7000 )
            {
              png_warning(
                png_ptr,
                warning_message: (png_struct_def *)"Ignoring incorrect cHRM value when sRGB is also present");
            }
          }
        }
        png_set_sRGB_gAMA_and_cHRM(png_ptr, info_ptr, intent: v8, a4: v7);
      }
      else
      {
        png_warning(png_ptr, warning_message: (png_struct_def *)"Unknown sRGB intent");
      }
    }
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect sRGB chunk length");
    png_crc_finish(png_ptr, skip: length);
  }
}


// ========================================================================
// png_handle_iCCP
// EA  : 0x8322ADE0
// RVA : 0x0122ADE0
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_iCCP(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 *v7; // r29
  unsigned __int8 *i; // r11
  unsigned __int8 *v9; // r10
  unsigned __int8 v10; // r11
  _BYTE *v11; // r31
  unsigned __int8 v12; // r28
  size_t v13; // r31
  char *v14; // r3
  unsigned int v15; // r8
  unsigned int v16; // r4
  int v17; // r10
  size_t v18; // [sp+50h] [-40h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid iCCP after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( (mode & 2) != 0 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Out of place iCCP chunk");
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before iCCP");
  }
  if ( info_ptr != nullptr && (info_ptr->valid & 0x1000) != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate iCCP chunk");
    png_crc_finish(png_ptr, skip: length);
    return;
  }
  v7 = (unsigned __int8 *)png_malloc(png_ptr, size: length + 1);
  png_read_data(png_ptr, data: v7, length);
  png_calculate_crc(png_ptr, ptr: v7, length);
  if ( png_crc_finish(png_ptr, skip: 0) != 0 )
    goto LABEL_22;
  v7[length] = 0;
  for ( i = v7; *i != 0; ++i )
    ;
  v9 = i + 1;
  if ( i + 1 >= &v7[length - 1] )
  {
    png_free(png_ptr, ptr: v7);
    png_warning(png_ptr, warning_message: (png_struct_def *)"Malformed iCCP chunk");
    return;
  }
  v10 = *v9;
  v11 = v9 + 1;
  if ( *v9 != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Ignoring nonzero compression type in iCCP chunk");
    v10 = 0;
  }
  v12 = v10;
  v13 = v11 - v7;
  v14 = png_decompress_chunk(
          png_ptr,
          comp_type: v10,
          chunkdata: (char *)v7,
          chunklength: length,
          prefix_size: v13,
          newlength: &v18);
  v7 = (unsigned __int8 *)v14;
  v15 = v18 - v13;
  if ( v13 > v18 || v15 < 4 )
  {
    png_free(png_ptr, ptr: v14);
    png_warning(png_ptr, warning_message: (png_struct_def *)"Profile size field missing from iCCP chunk");
  }
  else
  {
    v16 = (unsigned __int8)v14[v13 + 3];
    v17 = (((__ROL4__((unsigned __int8)v14[v13], 8) | (unsigned __int8)v14[v13 + 1]) << 8)
         | (unsigned __int8)v14[v13 + 2]) << 8;
    if ( (v17 | v16) < v15 )
    {
      v15 = v17 | v16;
LABEL_21:
      png_set_iCCP(png_ptr, info_ptr, name: v14, compression_type: v12, profile: &v14[v13], proflen: v15);
LABEL_22:
      png_free(png_ptr, ptr: v7);
      return;
    }
    if ( (v17 | v16) <= v15 )
      goto LABEL_21;
    png_free(png_ptr, ptr: v14);
    png_warning(png_ptr, warning_message: (png_struct_def *)"Ignoring truncated iCCP profile.");
  }
}


// ========================================================================
// png_handle_sPLT
// EA  : 0x8322B050
// RVA : 0x0122B050
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_sPLT(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 *v7; // r29
  unsigned __int8 *i; // r11
  unsigned __int8 *v9; // r11
  unsigned __int8 *v10; // r30
  unsigned int v11; // r10
  unsigned int v12; // r11
  unsigned int v13; // r11
  png_sPLT_entry_struct *entries; // r3
  int v15; // r6
  int v16; // r7
  unsigned __int8 *v17; // r11
  png_sPLT_entry_struct *v18; // r10
  unsigned __int16 v19; // r8
  unsigned __int8 *v20; // r11
  unsigned __int16 v21; // r4
  unsigned __int16 v22; // r9
  unsigned __int16 v23; // r5
  unsigned __int8 *v24; // r11
  int v25; // r9
  __int16 v26; // r5
  unsigned __int8 *v27; // r11
  __int16 v28; // r8
  __int16 v29; // r8
  __int16 v30; // r8
  __int16 v31; // r8
  png_sPLT_struct v32; // [sp+50h] [-40h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid sPLT after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before sPLT");
  }
  v7 = (unsigned __int8 *)png_malloc(png_ptr, size: length + 1);
  png_read_data(png_ptr, data: v7, length);
  png_calculate_crc(png_ptr, ptr: v7, length);
  if ( png_crc_finish(png_ptr, skip: 0) != 0 )
  {
    png_free(png_ptr, ptr: v7);
  }
  else
  {
    v7[length] = 0;
    for ( i = v7; *i != 0; ++i )
      ;
    v9 = i + 1;
    if ( v9 <= &v7[length - 2] )
    {
      v10 = v9 + 1;
      v32.depth = *v9;
      v11 = 6;
      if ( v32.depth != 8 )
        v11 = 10;
      __twllei(v11, 0);
      v12 = v7 - v10 + length;
      if ( v12 % v11 != 0 )
      {
        png_free(png_ptr, ptr: v7);
        png_warning(png_ptr, warning_message: (png_struct_def *)"sPLT chunk has bad length");
      }
      else
      {
        v13 = v12 / v11;
        __twllei(v11, 0);
        v32.nentries = v13;
        if ( v13 <= 0x19999999 )
        {
          entries = (png_sPLT_entry_struct *)png_malloc_warn(png_ptr, size: 10 * v13);
          v32.entries = entries;
          if ( entries != nullptr )
          {
            v15 = 0;
            if ( v32.nentries > 0 )
            {
              v16 = 0;
              v17 = v10 - 2;
              while ( 1 )
              {
                v18 = &entries[v16];
                if ( v32.depth == 8 )
                {
                  v19 = v17[2];
                  v20 = v17 + 1;
                  v18->red = v19;
                  v21 = v20[2];
                  ++v20;
                  v18->green = v21;
                  v22 = v20[2];
                  ++v20;
                  v18->blue = v22;
                  v23 = v20[2];
                  v24 = v20 + 1;
                  v18->alpha = v23;
                }
                else
                {
                  v25 = v17[2];
                  v26 = v17[3];
                  v27 = v17 + 2;
                  v18->red = __ROL4__(v25, 8) + v26;
                  LOWORD(v25) = v27[3];
                  v28 = __ROL4__(v27[2], 8);
                  v27 += 2;
                  v18->green = v28 + v25;
                  LOWORD(v25) = v27[3];
                  v29 = __ROL4__(v27[2], 8);
                  v27 += 2;
                  v18->blue = v29 + v25;
                  LOWORD(v25) = v27[3];
                  v30 = __ROL4__(v27[2], 8);
                  v24 = v27 + 2;
                  v18->alpha = v30 + v25;
                }
                v31 = v24[3];
                ++v15;
                v17 = v24 + 2;
                ++v16;
                v18->frequency = __ROL4__(*v17, 8) + v31;
                if ( v15 >= v32.nentries )
                  break;
                entries = v32.entries;
              }
            }
            v32.name = (char *)v7;
            png_set_sPLT(png_ptr, info_ptr, entries: &v32, nentries: 1);
            png_free(png_ptr, ptr: v7);
            png_free(png_ptr, ptr: v32.entries);
          }
          else
          {
            png_warning(png_ptr, warning_message: (png_struct_def *)"sPLT chunk requires too much memory");
          }
        }
        else
        {
          png_warning(png_ptr, warning_message: (png_struct_def *)"sPLT chunk too long");
        }
      }
    }
    else
    {
      png_free(png_ptr, ptr: v7);
      png_warning(png_ptr, warning_message: (png_struct_def *)"malformed sPLT chunk");
    }
  }
}


// ========================================================================
// png_handle_tRNS
// EA  : 0x8322B350
// RVA : 0x0122B350
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_tRNS(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  int color_type; // r11
  png_struct_def *v8; // r3
  char *v9; // r4
  int v10; // r10
  int v11; // r10
  int v12; // r7
  __int16 v13; // r8
  int v14; // r11
  unsigned __int16 v15; // r9
  unsigned __int8 v16[4]; // [sp+50h] [-130h] BYREF
  unsigned __int8 v17[12]; // [sp+54h] [-12Ch] BYREF
  unsigned __int8 v18[288]; // [sp+60h] [-120h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      v9 = "Invalid tRNS after IDAT";
      goto LABEL_28;
    }
    if ( info_ptr != nullptr && (info_ptr->valid & 0x10) != 0 )
    {
      v9 = "Duplicate tRNS chunk";
      goto LABEL_28;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before tRNS");
  }
  color_type = png_ptr->color_type;
  if ( png_ptr->color_type != 0 )
  {
    if ( color_type == 2 )
    {
      v8 = png_ptr;
      if ( length != 6 )
        goto LABEL_5;
      png_read_data(png_ptr, data: v17, length: 6u);
      png_calculate_crc(png_ptr, ptr: v17, length: 6u);
      v11 = v17[0];
      v12 = v17[4];
      v13 = __ROL4__(v17[2], 8);
      png_ptr->num_trans = 1;
      v14 = __ROL4__(v11, 8) + v17[1];
      LOWORD(v11) = v13 + v17[3];
      v15 = __ROL4__(v12, 8) + v17[5];
      png_ptr->trans_values.red = v14;
      png_ptr->trans_values.green = v11;
      png_ptr->trans_values.blue = v15;
      goto LABEL_23;
    }
    if ( color_type == 3 )
    {
      if ( (png_ptr->mode & 2) == 0 )
        png_warning(png_ptr, warning_message: (png_struct_def *)"Missing PLTE before tRNS");
      if ( length <= png_ptr->num_palette && length <= 0x100 )
      {
        if ( length == 0 )
        {
          png_warning(png_ptr, warning_message: (png_struct_def *)"Zero length tRNS chunk");
          png_crc_finish(png_ptr, skip: 0);
          return;
        }
        png_read_data(png_ptr, data: v18, length);
        png_calculate_crc(png_ptr, ptr: v18, length);
        png_ptr->num_trans = length;
        goto LABEL_23;
      }
      v9 = "Incorrect tRNS chunk length";
    }
    else
    {
      v9 = "tRNS chunk not allowed with alpha channel";
    }
LABEL_28:
    v8 = png_ptr;
    goto LABEL_29;
  }
  v8 = png_ptr;
  if ( length != 2 )
  {
LABEL_5:
    v9 = "Incorrect tRNS chunk length";
LABEL_29:
    png_warning(png_ptr: v8, warning_message: (png_struct_def *)v9);
    png_crc_finish(png_ptr, skip: length);
    return;
  }
  png_read_data(png_ptr, data: v16, length: 2u);
  png_calculate_crc(png_ptr, ptr: v16, length: 2u);
  v10 = v16[0];
  png_ptr->num_trans = 1;
  png_ptr->trans_values.gray = __ROL4__(v10, 8) + v16[1];
LABEL_23:
  if ( png_crc_finish(png_ptr, skip: 0) != 0 )
    png_ptr->num_trans = 0;
  else
    png_set_tRNS(png_ptr, info_ptr, trans: v18, num_trans: png_ptr->num_trans, trans_values: &png_ptr->trans_values);
}


// ========================================================================
// png_handle_bKGD
// EA  : 0x8322B598
// RVA : 0x0122B598
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_bKGD(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  int color_type; // r11
  unsigned int v8; // r30
  int v9; // r11
  unsigned __int8 v10; // r11
  png_color_struct *v11; // r11
  unsigned __int16 v12; // r7
  int v13; // r9
  int v14; // r8
  unsigned __int8 v15; // [sp+50h] [-30h] BYREF
  unsigned __int8 v16; // [sp+51h] [-2Fh]
  unsigned __int8 v17; // [sp+52h] [-2Eh]
  unsigned __int8 v18; // [sp+53h] [-2Dh]
  unsigned __int8 v19; // [sp+54h] [-2Ch]
  unsigned __int8 v20; // [sp+55h] [-2Bh]

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid bKGD after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( png_ptr->color_type == 3 && (mode & 2) == 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Missing PLTE before bKGD");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( info_ptr != nullptr && (info_ptr->valid & 0x20) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate bKGD chunk");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before bKGD");
  }
  color_type = png_ptr->color_type;
  if ( color_type == 3 )
    v8 = 1;
  else
    v8 = (2 * color_type) & 4 | 2;
  if ( length != v8 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect bKGD chunk length");
    png_crc_finish(png_ptr, skip: length);
    return;
  }
  png_read_data(png_ptr, data: &v15, length: v8);
  png_calculate_crc(png_ptr, ptr: &v15, length: v8);
  if ( png_crc_finish(png_ptr, skip: 0) == 0 )
  {
    v9 = png_ptr->color_type;
    if ( v9 == 3 )
    {
      v10 = v15;
      png_ptr->background.index = v15;
      if ( info_ptr != nullptr && info_ptr->num_palette != 0 )
      {
        if ( v10 > (unsigned int)info_ptr->num_palette )
        {
          png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect bKGD chunk index value");
          return;
        }
        v11 = &png_ptr->palette[v10];
        png_ptr->background.red = v11->red;
        png_ptr->background.green = v11->green;
        png_ptr->background.blue = v11->blue;
      }
    }
    else if ( (v9 & 2) != 0 )
    {
      v13 = __ROL4__(v17, 8) + v18;
      v14 = __ROL4__(v19, 8) + v20;
      png_ptr->background.red = __ROL4__(v15, 8) + v16;
      png_ptr->background.green = v13;
      png_ptr->background.blue = v14;
    }
    else
    {
      v12 = __ROL4__(v15, 8) + v16;
      png_ptr->background.gray = v12;
      png_ptr->background.blue = v12;
      png_ptr->background.green = v12;
      png_ptr->background.red = v12;
    }
    png_set_bKGD(png_ptr, info_ptr, background: &png_ptr->background);
  }
}


// ========================================================================
// png_handle_hIST
// EA  : 0x8322B7E8
// RVA : 0x0122B7E8
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_hIST(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned int v7; // r30
  __int16 *v8; // r29
  char *v9; // r4
  unsigned __int8 v10[14]; // [sp+50h] [-240h] BYREF
  __int16 v11; // [sp+5Eh] [-232h] BYREF
  unsigned __int16 v12; // [sp+60h] [-230h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) == 0 )
  {
    png_error(png_ptr, error_message: "Missing IHDR before hIST");
    goto LABEL_3;
  }
  if ( (mode & 4) != 0 )
  {
    v9 = "Invalid hIST after IDAT";
LABEL_18:
    png_warning(png_ptr, warning_message: (png_struct_def *)v9);
    png_crc_finish(png_ptr, skip: length);
    return;
  }
  if ( (mode & 2) == 0 )
  {
    v9 = "Missing PLTE before hIST";
    goto LABEL_18;
  }
  if ( info_ptr != nullptr && (info_ptr->valid & 0x40) != 0 )
  {
    v9 = "Duplicate hIST chunk";
    goto LABEL_18;
  }
LABEL_3:
  v7 = length >> 1;
  if ( length >> 1 != png_ptr->num_palette || v7 > 0x100 )
  {
    v9 = "Incorrect hIST chunk length";
    goto LABEL_18;
  }
  if ( v7 != 0 )
  {
    v8 = &v11;
    do
    {
      png_read_data(png_ptr, data: v10, length: 2u);
      png_calculate_crc(png_ptr, ptr: v10, length: 2u);
      --v7;
      *++v8 = __ROL4__(v10[0], 8) + v10[1];
    }
    while ( v7 != 0 );
  }
  if ( png_crc_finish(png_ptr, skip: 0) == 0 )
    png_set_hIST(png_ptr, info_ptr, hist: &v12);
}


// ========================================================================
// png_handle_pHYs
// EA  : 0x8322B930
// RVA : 0x0122B930
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_pHYs(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 v7[48]; // [sp+50h] [-30h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid pHYs after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( info_ptr != nullptr && (info_ptr->valid & 0x80) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate pHYs chunk");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before pHYs");
  }
  if ( length == 9 )
  {
    png_read_data(png_ptr, data: v7, length: 9u);
    png_calculate_crc(png_ptr, ptr: v7, length: 9u);
    if ( png_crc_finish(png_ptr, skip: 0) == 0 )
      png_set_pHYs(
        png_ptr,
        info_ptr,
        res_x: ((((__ROL4__(v7[0], 8) + v7[1]) << 8) + v7[2]) << 8) + v7[3],
        res_y: ((((__ROL4__(v7[4], 8) + v7[5]) << 8) + v7[6]) << 8) + v7[7],
        unit_type: v7[8]);
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect pHYs chunk length");
    png_crc_finish(png_ptr, skip: length);
  }
}


// ========================================================================
// png_handle_oFFs
// EA  : 0x8322BAB0
// RVA : 0x0122BAB0
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_oFFs(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 v7[48]; // [sp+50h] [-30h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid oFFs after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( info_ptr != nullptr && (info_ptr->valid & 0x100) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate oFFs chunk");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before oFFs");
  }
  if ( length == 9 )
  {
    png_read_data(png_ptr, data: v7, length: 9u);
    png_calculate_crc(png_ptr, ptr: v7, length: 9u);
    if ( png_crc_finish(png_ptr, skip: 0) == 0 )
      png_set_oFFs(
        png_ptr,
        info_ptr,
        offset_x: ((((__ROL4__(v7[0], 8) + v7[1]) << 8) + v7[2]) << 8) + v7[3],
        offset_y: ((((__ROL4__(v7[4], 8) + v7[5]) << 8) + v7[6]) << 8) + v7[7],
        unit_type: v7[8]);
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect oFFs chunk length");
    png_crc_finish(png_ptr, skip: length);
  }
}


// ========================================================================
// png_handle_pCAL
// EA  : 0x8322BC30
// RVA : 0x0122BC30
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_pCAL(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 *v7; // r26
  unsigned int v8; // r22
  unsigned __int8 *i; // r11
  char *v10; // r25
  unsigned int v11; // r28
  int v12; // r30
  int v13; // r24
  int v14; // r23
  char *j; // r31
  int v16; // r27
  _DWORD *v17; // r3
  void *v18; // r30
  int v19; // r10
  _DWORD *v20; // r11
  char **v21; // [sp+8h] [-B8h]
  int v22; // [sp+Ch] [-B4h]
  int v23; // [sp+10h] [-B0h]
  int v24; // [sp+14h] [-ACh]
  int v25; // [sp+18h] [-A8h]
  int v26; // [sp+1Ch] [-A4h]
  int v27; // [sp+20h] [-A0h]
  int v28; // [sp+24h] [-9Ch]
  int v29; // [sp+28h] [-98h]
  int v30; // [sp+2Ch] [-94h]
  int v31; // [sp+30h] [-90h]
  int v32; // [sp+34h] [-8Ch]
  int v33; // [sp+38h] [-88h]
  int v34; // [sp+3Ch] [-84h]
  int v35; // [sp+40h] [-80h]
  int v36; // [sp+44h] [-7Ch]
  int v37; // [sp+48h] [-78h]
  int v38; // [sp+4Ch] [-74h]
  int v39; // [sp+50h] [-70h]

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid pCAL after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( info_ptr != nullptr && (info_ptr->valid & 0x400) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate pCAL chunk");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before pCAL");
  }
  v7 = (unsigned __int8 *)png_malloc_warn(png_ptr, size: length + 1);
  if ( v7 == nullptr )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"No memory for pCAL purpose.");
    return;
  }
  png_read_data(png_ptr, data: v7, length);
  png_calculate_crc(png_ptr, ptr: v7, length);
  if ( png_crc_finish(png_ptr, skip: 0) != 0 )
    goto LABEL_15;
  v8 = (unsigned int)&v7[length];
  v7[length] = 0;
  for ( i = v7; *i != 0; ++i )
    ;
  if ( v8 <= (unsigned int)(i + 12) )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid pCAL data");
LABEL_15:
    png_free(png_ptr, ptr: v7);
    return;
  }
  v10 = (char *)(i + 11);
  v11 = i[9];
  v12 = i[10];
  v13 = ((((__ROL4__(i[5], 8) + i[6]) << 8) + i[7]) << 8) + i[8];
  v14 = ((((__ROL4__(i[1], 8) + i[2]) << 8) + i[3]) << 8) + i[4];
  if ( (i[9] != 0 || i[10] == 2) && (v11 != 1 || i[10] == 3) && (v11 != 2 || i[10] == 3) && (v11 != 3 || i[10] == 4) )
  {
    if ( v11 >= 4 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Unrecognized equation type for pCAL chunk");
    for ( j = v10; *j != 0; ++j )
      ;
    v16 = (unsigned __int8)v12;
    v17 = png_malloc_warn(png_ptr, size: (4 * v12) & 0x3FC);
    v18 = v17;
    if ( v17 != nullptr )
    {
      v19 = 0;
      if ( v16 <= 0 )
      {
LABEL_38:
        png_set_pCAL(
          png_ptr,
          info_ptr,
          purpose: (char *)v7,
          X0: v14,
          X1: v13,
          type: v11,
          nparams: v16,
          units: v10,
          params: v21,
          a10: v22,
          a11: v23,
          a12: v24,
          a13: v25,
          a14: v26,
          a15: v27,
          a16: v28,
          a17: v29,
          a18: v30,
          a19: v31,
          a20: v32,
          a21: v33,
          a22: v34,
          a23: v35,
          a24: v36,
          a25: v37,
          a26: v38,
          a27: v39,
          a28: (int)v17);
      }
      else
      {
        v20 = v17;
        while ( 1 )
        {
          *v20 = ++j;
          if ( (unsigned int)j > v8 )
            break;
          while ( *j != 0 )
          {
            if ( (unsigned int)++j > v8 )
              goto LABEL_36;
          }
          ++v19;
          ++v20;
          if ( v19 >= v16 )
            goto LABEL_38;
        }
LABEL_36:
        png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid pCAL data");
      }
      png_free(png_ptr, ptr: v7);
      png_free(png_ptr, ptr: v18);
    }
    else
    {
      png_free(png_ptr, ptr: v7);
      png_warning(png_ptr, warning_message: (png_struct_def *)"No memory for pCAL params.");
    }
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid pCAL parameters for equation type");
    png_free(png_ptr, ptr: v7);
  }
}


// ========================================================================
// png_handle_sCAL
// EA  : 0x8322BF78
// RVA : 0x0122BF78
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_sCAL(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  _DWORD *v7; // r30
  _BYTE *v8; // r29
  long double v9; // fp2
  double v10; // fp31
  _DWORD *i; // r11
  char *v12; // r4
  long double v13; // fp4
  long double v14; // fp2
  char *v15[4]; // [sp+50h] [-40h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 1) != 0 )
  {
    if ( (mode & 4) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid sCAL after IDAT");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
    if ( info_ptr != nullptr && (info_ptr->valid & 0x4000) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate sCAL chunk");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Missing IHDR before sCAL");
  }
  v7 = png_malloc_warn(png_ptr, size: length + 1);
  if ( v7 == nullptr )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Out of memory while processing sCAL chunk");
    return;
  }
  png_read_data(png_ptr, data: (unsigned __int8 *)v7, length);
  png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v7, length);
  if ( png_crc_finish(png_ptr, skip: 0) != 0 )
    goto LABEL_24;
  v8 = (char *)v7 + length;
  *v8 = 0;
  v9 = strtod(nptr: (const char *)v7 + 1, endptr: v15);
  v10 = *(double *)&v9;
  if ( *v15[0] != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"malformed width string in sCAL chunk");
    return;
  }
  for ( i = v7; *(_BYTE *)i != 0; i = (_DWORD *)((char *)i + 1) )
    ;
  if ( v8 < (_BYTE *)i + 1 )
  {
    v12 = "Truncated sCAL chunk";
LABEL_23:
    png_warning(png_ptr, warning_message: (png_struct_def *)v12);
    goto LABEL_24;
  }
  v14 = strtod(nptr: (const char *)i + 1, endptr: v15);
  *((double *)&v14 + 1) = *(double *)&v14;
  if ( *v15[0] != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"malformed height string in sCAL chunk");
    return;
  }
  if ( v10 <= 0.0 || *(double *)&v14 <= 0.0 )
  {
    v12 = "Invalid sCAL data";
    goto LABEL_23;
  }
  *(double *)&v14 = v10;
  png_set_sCAL(png_ptr, info_ptr, unit: *(_BYTE *)v7, width: v14, height: v13);
LABEL_24:
  png_free(png_ptr, ptr: v7);
}


// ========================================================================
// png_handle_tIME
// EA  : 0x8322C198
// RVA : 0x0122C198
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_tIME(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 v7[8]; // [sp+50h] [-30h] BYREF
  png_time_struct v8; // [sp+58h] [-28h] BYREF

  if ( (png_ptr->mode & 1) != 0 )
  {
    if ( info_ptr != nullptr && (info_ptr->valid & 0x200) != 0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Duplicate tIME chunk");
      png_crc_finish(png_ptr, skip: length);
      return;
    }
  }
  else
  {
    png_error(png_ptr, error_message: "Out of place tIME chunk");
  }
  mode = png_ptr->mode;
  if ( (mode & 4) != 0 )
    png_ptr->mode = mode | 8;
  if ( length == 7 )
  {
    png_read_data(png_ptr, data: v7, length: 7u);
    png_calculate_crc(png_ptr, ptr: v7, length: 7u);
    if ( png_crc_finish(png_ptr, skip: 0) == 0 )
    {
      v8.second = v7[6];
      v8.minute = v7[5];
      v8.hour = v7[4];
      v8.day = v7[3];
      v8.month = v7[2];
      v8.year = __ROL4__(v7[0], 8) + v7[1];
      png_set_tIME(png_ptr, info_ptr, mod_time: &v8);
    }
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Incorrect tIME chunk length");
    png_crc_finish(png_ptr, skip: length);
  }
}


// ========================================================================
// png_handle_tEXt
// EA  : 0x8322C2D8
// RVA : 0x0122C2D8
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_tEXt(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 *v7; // r29
  char *v8; // r28
  png_text_struct *v9; // r3
  png_text_struct *v10; // r30
  char *v11; // r11
  int v12; // r10
  int v13; // r28

  if ( (png_ptr->mode & 1) == 0 )
    png_error(png_ptr, error_message: "Missing IHDR before tEXt");
  mode = png_ptr->mode;
  if ( (mode & 4) != 0 )
    png_ptr->mode = mode | 8;
  v7 = (unsigned __int8 *)png_malloc_warn(png_ptr, size: length + 1);
  if ( v7 == nullptr )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"No memory to process text chunk.");
    return;
  }
  png_read_data(png_ptr, data: v7, length);
  png_calculate_crc(png_ptr, ptr: v7, length);
  if ( png_crc_finish(png_ptr, skip: 0) != 0 )
    goto LABEL_14;
  v7[length] = 0;
  v8 = (char *)v7;
  if ( *v7 != 0 )
  {
    do
      ++v8;
    while ( *v8 != 0 );
  }
  if ( v8 != (char *)&v7[length] )
    ++v8;
  v9 = (png_text_struct *)png_malloc_warn(png_ptr, size: 0x10u);
  v10 = v9;
  if ( v9 == nullptr )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Not enough memory to process text chunk.");
LABEL_14:
    png_free(png_ptr, ptr: v7);
    return;
  }
  v9->key = (char *)v7;
  v9->text = v8;
  v11 = v8;
  v9->compression = -1;
  do
    v12 = (unsigned __int8)*v11++;
  while ( v12 != 0 );
  v9->text_length = v11 - v8 - 1;
  v13 = png_set_text_2(png_ptr, info_ptr, text_ptr: v9, num_text: 1);
  png_free(png_ptr, ptr: v7);
  png_free(png_ptr, ptr: v10);
  if ( v13 != 0 )
    png_warning(png_ptr, warning_message: (png_struct_def *)"Insufficient memory to process text chunk.");
}


// ========================================================================
// png_handle_zTXt
// EA  : 0x8322C478
// RVA : 0x0122C478
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_zTXt(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r11
  unsigned __int8 *v7; // r30
  unsigned __int8 *i; // r29
  _BYTE *v9; // r29
  int v10; // r27
  size_t v11; // r28
  char *v12; // r29
  png_text_struct *v13; // r30
  unsigned int v14; // r11
  int v15; // r28
  unsigned int v16; // [sp+50h] [-50h] BYREF

  if ( (png_ptr->mode & 1) == 0 )
    png_error(png_ptr, error_message: "Missing IHDR before zTXt");
  mode = png_ptr->mode;
  if ( (mode & 4) != 0 )
    png_ptr->mode = mode | 8;
  v7 = (unsigned __int8 *)png_malloc_warn(png_ptr, size: length + 1);
  if ( v7 == nullptr )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Out of memory processing zTXt chunk.");
    return;
  }
  png_read_data(png_ptr, data: v7, length);
  png_calculate_crc(png_ptr, ptr: v7, length);
  if ( png_crc_finish(png_ptr, skip: 0) != 0 )
    goto LABEL_12;
  v7[length] = 0;
  for ( i = v7; *i != 0; ++i )
    ;
  if ( i >= &v7[length - 2] )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Truncated zTXt chunk");
LABEL_12:
    png_free(png_ptr, ptr: v7);
    return;
  }
  v9 = i + 1;
  v10 = (char)*v9;
  if ( *v9 != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Unknown compression type in zTXt chunk");
    v10 = 0;
  }
  v11 = v9 - v7 + 1;
  v12 = png_decompress_chunk(
          png_ptr,
          comp_type: v10,
          chunkdata: (char *)v7,
          chunklength: length,
          prefix_size: v11,
          newlength: &v16);
  v13 = (png_text_struct *)png_malloc_warn(png_ptr, size: 0x10u);
  if ( v13 != nullptr )
  {
    v14 = v16;
    v13->compression = v10;
    v13->key = v12;
    v13->text = &v12[v11];
    v13->text_length = v14;
    v15 = png_set_text_2(png_ptr, info_ptr, text_ptr: v13, num_text: 1);
    png_free(png_ptr, ptr: v13);
    png_free(png_ptr, ptr: v12);
    if ( v15 != 0 )
      png_error(png_ptr, error_message: "Insufficient memory to store zTXt chunk.");
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Not enough memory to process zTXt chunk.");
    png_free(png_ptr, ptr: v12);
  }
}


// ========================================================================
// png_handle_unknown
// EA  : 0x8322C668
// RVA : 0x0122C668
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_handle_unknown(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int length)
{
  unsigned int mode; // r7
  unsigned __int8 *chunk_name; // r11
  char *v8; // r10
  int v9; // r6
  int v10; // r9
  unsigned __int8 *v11; // r28
  char *v12; // r11
  char *v13; // r10
  int i; // ctr
  unsigned __int8 *v15; // r3
  unsigned __int8 *v16; // r24
  int (__fastcall *read_user_chunk_fn)(png_struct_def *, png_unknown_chunk_t *); // r11
  png_struct_def *v18; // r3
  int v19; // r30
  bool v20; // cr58
  char v21[80]; // [sp+50h] [-50h] BYREF

  mode = png_ptr->mode;
  if ( (mode & 4) != 0 )
  {
    chunk_name = png_ptr->chunk_name;
    strcpy(v21, "IDAT");
    v8 = v21;
    do
    {
      v9 = (unsigned __int8)*v8;
      v10 = *chunk_name - v9;
      if ( *chunk_name != v9 )
        break;
      ++chunk_name;
      ++v8;
    }
    while ( chunk_name != &png_ptr->chunk_name[4] );
    if ( v10 != 0 )
      png_ptr->mode = mode | 8;
  }
  v11 = png_ptr->chunk_name;
  png_check_chunk_name(png_ptr, chunk_name: png_ptr->chunk_name);
  if ( (png_ptr->chunk_name[0] & 0x20) == 0
    && png_handle_as_unknown(png_ptr, chunk_name: png_ptr->chunk_name) != 3
    && png_ptr->read_user_chunk_fn == nullptr )
  {
    png_chunk_error(png_ptr, error_message: "unknown critical chunk");
  }
  if ( (png_ptr->flags & 0x8000) == 0 && png_ptr->read_user_chunk_fn == nullptr )
  {
    png_crc_finish(png_ptr, skip: length);
    return;
  }
  v12 = (char *)&png_ptr->num_trans + 1;
  v13 = (char *)&png_ptr->user_height_max + 3;
  for ( i = 5; i != 0; --i )
    *++v13 = *++v12;
  png_ptr->unknown_chunk.size = length;
  png_ptr->unknown_chunk.name[4] = 0;
  if ( length != 0 )
  {
    v15 = (unsigned __int8 *)png_malloc(png_ptr, size: length);
    png_ptr->unknown_chunk.data = v15;
    v16 = v15;
    png_read_data(png_ptr, data: v15, length);
    png_calculate_crc(png_ptr, ptr: v16, length);
  }
  else
  {
    png_ptr->unknown_chunk.data = nullptr;
  }
  read_user_chunk_fn = png_ptr->read_user_chunk_fn;
  v18 = png_ptr;
  if ( read_user_chunk_fn != nullptr )
  {
    v19 = read_user_chunk_fn(a1: png_ptr, a2: &png_ptr->unknown_chunk);
    v20 = v19 == 0;
    if ( v19 < 0 )
    {
      png_chunk_error(png_ptr, error_message: "error in user chunk");
      v20 = v19 == 0;
    }
    if ( !v20 )
      goto LABEL_28;
    if ( (*v11 & 0x20) == 0 && png_handle_as_unknown(png_ptr, chunk_name: png_ptr->chunk_name) != 3 )
      png_chunk_error(png_ptr, error_message: "unknown critical chunk");
    v18 = png_ptr;
  }
  png_set_unknown_chunks(png_ptr: v18, info_ptr, unknowns: &png_ptr->unknown_chunk, num_unknowns: 1);
LABEL_28:
  png_free(png_ptr, ptr: png_ptr->unknown_chunk.data);
  png_ptr->unknown_chunk.data = nullptr;
  png_crc_finish(png_ptr, skip: 0);
}


// ========================================================================
// png_read_finish_row
// EA  : 0x8322C890
// RVA : 0x0122C890
// PDB : w:\tech5\libs\png\pngrutil.c
// ========================================================================

void __fastcall png_read_finish_row(png_struct_def *png_ptr)
{
  unsigned int row_number; // r8
  unsigned int num_rows; // r7
  int pass; // r11
  unsigned __int8 v5; // r10
  unsigned int pixel_depth; // r11
  unsigned int v7; // r4
  unsigned int v8; // r10
  unsigned int v9; // r10
  unsigned int v10; // r11
  unsigned int v11; // r8
  unsigned int iwidth; // r4
  unsigned int height; // r9
  int v14; // r10
  unsigned int v15; // r7
  unsigned int v16; // r30
  unsigned __int8 *v17; // r10
  unsigned __int8 *chunk_name; // r11
  int v19; // r7
  int v20; // r9
  unsigned int zbuf_size; // r10
  unsigned __int8 *zbuf; // r30
  unsigned int idat_size; // r11
  unsigned int avail_in; // r29
  int v25; // r3
  char *msg; // r4
  unsigned int mode; // r10
  char v28; // [sp+50h] [-E0h] BYREF
  unsigned __int8 v29[4]; // [sp+54h] [-DCh] BYREF
  _BYTE v30[8]; // [sp+58h] [-D8h] BYREF
  _DWORD v31[8]; // [sp+60h] [-D0h] BYREF
  _DWORD v32[8]; // [sp+80h] [-B0h] BYREF
  _DWORD v33[8]; // [sp+A0h] [-90h] BYREF
  _DWORD v34[28]; // [sp+C0h] [-70h] BYREF

  row_number = png_ptr->row_number;
  num_rows = png_ptr->num_rows;
  v33[0] = 0;
  v33[1] = 4;
  v33[2] = 0;
  ++row_number;
  v33[3] = 2;
  v33[4] = 0;
  v33[5] = 1;
  v33[6] = 0;
  png_ptr->row_number = row_number;
  v31[0] = 8;
  v31[1] = 8;
  v31[2] = 4;
  v31[3] = 4;
  v31[4] = 2;
  v31[5] = 2;
  v31[6] = 1;
  v34[0] = 0;
  v34[1] = 0;
  v34[2] = 4;
  v34[3] = 0;
  v34[4] = 2;
  v34[5] = 0;
  v34[6] = 1;
  v32[0] = 8;
  v32[1] = 8;
  v32[2] = 8;
  v32[3] = 4;
  v32[4] = 4;
  v32[5] = 2;
  v32[6] = 2;
  if ( row_number >= num_rows )
  {
    if ( png_ptr->interlaced == 0 )
      goto LABEL_11;
    png_ptr->row_number = 0;
    png_memset_check(png_ptr, s1: png_ptr->prev_row, value: 0, length: png_ptr->rowbytes + 1);
    LOBYTE(pass) = png_ptr->pass;
    do
    {
      v5 = pass + 1;
      png_ptr->pass = pass + 1;
      if ( (unsigned __int8)(pass + 1) >= 7u )
        break;
      pixel_depth = png_ptr->pixel_depth;
      v7 = *(_DWORD *)((char *)v31 + __ROL4__(v5, 2));
      v8 = v7 - *(_DWORD *)((char *)v33 + __ROL4__(v5, 2)) + png_ptr->width;
      __twllei(v7, 0);
      v9 = (v8 - 1) / v7;
      png_ptr->iwidth = v9;
      v10 = pixel_depth < 8 ? (pixel_depth * v9 + 7) >> 3 : (pixel_depth >> 3) * v9;
      v11 = png_ptr->transformations & 2;
      png_ptr->irowbytes = v10 + 1;
      if ( v11 != 0 )
        break;
      pass = png_ptr->pass;
      iwidth = png_ptr->iwidth;
      height = png_ptr->height;
      v14 = *(_DWORD *)((char *)v32 + __ROL4__(pass, 2)) - *(_DWORD *)((char *)v34 + __ROL4__(pass, 2));
      v15 = *(_DWORD *)((char *)v32 + __ROL4__(pass, 2));
      __twllei(v15, 0);
      png_ptr->num_rows = (v14 + height - 1) / v15;
    }
    while ( iwidth == 0 );
    if ( png_ptr->pass >= 7u )
    {
LABEL_11:
      if ( (png_ptr->flags & 0x20) == 0 )
      {
        png_ptr->zstream.avail_out = 1;
        v30[4] = 0;
        png_ptr->zstream.next_out = (unsigned __int8 *)&v28;
        qmemcpy(v30, "IDAT", 4);
        while ( 1 )
        {
          if ( png_ptr->zstream.avail_in == 0 )
          {
            while ( png_ptr->idat_size == 0 )
            {
              png_crc_finish(png_ptr, skip: 0);
              png_read_data(png_ptr, data: v29, length: 4u);
              v16 = ((((__ROL4__(v29[0], 8) + v29[1]) << 8) + v29[2]) << 8) + v29[3];
              if ( v16 > 0x7FFFFFFF )
                png_error(png_ptr, error_message: "PNG unsigned integer out of range.");
              png_ptr->idat_size = v16;
              png_reset_crc(png_ptr);
              png_read_data(png_ptr, data: png_ptr->chunk_name, length: 4u);
              png_calculate_crc(png_ptr, ptr: png_ptr->chunk_name, length: 4u);
              v17 = v30;
              chunk_name = png_ptr->chunk_name;
              do
              {
                v19 = *v17;
                v20 = *chunk_name - v19;
                if ( *chunk_name != v19 )
                  break;
                ++chunk_name;
                ++v17;
              }
              while ( chunk_name != &png_ptr->chunk_name[4] );
              if ( v20 != 0 )
                png_error(png_ptr, error_message: "Not enough image data");
            }
            zbuf_size = png_ptr->zbuf_size;
            zbuf = png_ptr->zbuf;
            idat_size = png_ptr->idat_size;
            png_ptr->zstream.avail_in = zbuf_size;
            png_ptr->zstream.next_in = zbuf;
            if ( zbuf_size > idat_size )
              png_ptr->zstream.avail_in = idat_size;
            avail_in = png_ptr->zstream.avail_in;
            png_read_data(png_ptr, data: zbuf, length: avail_in);
            png_calculate_crc(png_ptr, ptr: zbuf, length: avail_in);
            png_ptr->idat_size -= png_ptr->zstream.avail_in;
          }
          v25 = inflate(strm: &png_ptr->zstream, flush: 1);
          if ( v25 == 1 )
            break;
          if ( v25 != 0 )
          {
            msg = png_ptr->zstream.msg;
            if ( msg == nullptr )
              msg = "Decompression Error";
            png_error(png_ptr, error_message: msg);
          }
          if ( png_ptr->zstream.avail_out == 0 )
          {
            png_warning(png_ptr, warning_message: (png_struct_def *)"Extra compressed data.");
            png_ptr->flags |= 0x20u;
            goto LABEL_33;
          }
        }
        if ( png_ptr->zstream.avail_out == 0 || png_ptr->zstream.avail_in != 0 || png_ptr->idat_size != 0 )
          png_warning(png_ptr, warning_message: (png_struct_def *)"Extra compressed data");
        png_ptr->flags |= 0x20u;
LABEL_33:
        mode = png_ptr->mode;
        png_ptr->zstream.avail_out = 0;
        png_ptr->mode = mode | 8;
      }
      if ( png_ptr->idat_size != 0 || png_ptr->zstream.avail_in != 0 )
        png_warning(png_ptr, warning_message: (png_struct_def *)"Extra compression data");
      inflateReset(strm: &png_ptr->zstream);
      png_ptr->mode |= 8u;
    }
  }
}

