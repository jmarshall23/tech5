
// ========================================================================
// png_write_chunk_start
// EA  : 0x8322CCF8
// RVA : 0x0122CCF8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_chunk_start(png_struct_def *png_ptr, unsigned __int8 *chunk_name, unsigned int length)
{
  unsigned int v5; // [sp+50h] [-20h] BYREF

  if ( png_ptr != nullptr )
  {
    v5 = length;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v5, length: 4u);
    png_write_data(png_ptr, data: chunk_name, length: 4u);
    png_reset_crc(png_ptr);
    png_calculate_crc(png_ptr, ptr: chunk_name, length: 4u);
  }
}


// ========================================================================
// png_write_chunk_end
// EA  : 0x8322CD88
// RVA : 0x0122CD88
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_chunk_end(png_struct_def *png_ptr)
{
  unsigned int crc; // r11
  unsigned int v2; // [sp+50h] [-10h] BYREF

  if ( png_ptr != nullptr )
  {
    crc = png_ptr->crc;
    v2 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v2, length: 4u);
  }
}


// ========================================================================
// png_write_sig
// EA  : 0x8322CDD8
// RVA : 0x0122CDD8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_sig(png_struct_def *png_ptr)
{
  int sig_bytes; // r11
  _BYTE v3[16]; // [sp+50h] [-20h] BYREF

  sig_bytes = png_ptr->sig_bytes;
  v3[5] = 10;
  v3[0] = -119;
  v3[1] = 80;
  v3[2] = 78;
  v3[3] = 71;
  v3[4] = 13;
  v3[6] = 26;
  v3[7] = 10;
  png_write_data(png_ptr, data: &v3[sig_bytes], length: 8 - sig_bytes);
  if ( png_ptr->sig_bytes < 3u )
    png_ptr->mode |= 0x1000u;
}


// ========================================================================
// png_text_compress
// EA  : 0x8322CE68
// RVA : 0x0122CE68
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

unsigned int __fastcall png_text_compress(
        png_struct_def *png_ptr,
        char *text,
        unsigned int text_len,
        int compression,
        compression_state *comp)
{
  unsigned int result; // r3
  unsigned int zbuf_size; // r11
  unsigned __int8 *zbuf; // r10
  char *msg; // r4
  int num_output_ptr; // r11
  int max_output_ptr; // r28
  char **output_ptr; // r29
  int v16; // r11
  unsigned int v17; // r4
  char **v18; // r3
  unsigned int v19; // r3
  int v20; // r3
  int v21; // r11
  int v22; // r28
  char **v23; // r29
  int v24; // r11
  unsigned int v25; // r4
  char **v26; // r3
  unsigned int v27; // r3
  char *v28; // r4
  unsigned int v29; // r11
  unsigned int avail_out; // r10
  char v31[112]; // [sp+50h] [-70h] BYREF

  comp->num_output_ptr = 0;
  comp->max_output_ptr = 0;
  comp->output_ptr = nullptr;
  comp->input = nullptr;
  comp->input_len = 0;
  if ( compression == -1 )
  {
    comp->input = text;
    comp->input_len = text_len;
    return text_len;
  }
  else
  {
    if ( compression >= 3 )
    {
      snprintf_0(string: v31, count: 0x32u, format: "Unknown compression type %d", compression);
      png_warning(png_ptr, warning_message: (png_struct_def *)v31);
    }
    zbuf_size = png_ptr->zbuf_size;
    zbuf = png_ptr->zbuf;
    png_ptr->zstream.avail_in = text_len;
    png_ptr->zstream.next_in = (unsigned __int8 *)text;
    png_ptr->zstream.avail_out = zbuf_size;
    png_ptr->zstream.next_out = zbuf;
    do
    {
      if ( deflate(strm: &png_ptr->zstream, flush: 0) != 0 )
      {
        msg = png_ptr->zstream.msg;
        if ( msg == nullptr )
          msg = "zlib error";
        png_error(png_ptr, error_message: msg);
      }
      if ( png_ptr->zstream.avail_out == 0 )
      {
        num_output_ptr = comp->num_output_ptr;
        max_output_ptr = comp->max_output_ptr;
        if ( num_output_ptr >= max_output_ptr )
        {
          output_ptr = comp->output_ptr;
          v16 = num_output_ptr + 4;
          comp->max_output_ptr = v16;
          v17 = 4 * v16;
          if ( output_ptr != nullptr )
          {
            v18 = (char **)png_malloc(png_ptr, size: v17);
            comp->output_ptr = v18;
            memcpy(Dst: v18, Src: output_ptr, Size: 4 * max_output_ptr);
            png_free(png_ptr, ptr: output_ptr);
          }
          else
          {
            comp->output_ptr = (char **)png_malloc(png_ptr, size: v17);
          }
        }
        comp->output_ptr[comp->num_output_ptr] = (char *)png_malloc(png_ptr, size: png_ptr->zbuf_size);
        memcpy(Dst: comp->output_ptr[comp->num_output_ptr], Src: png_ptr->zbuf, Size: png_ptr->zbuf_size);
        ++comp->num_output_ptr;
        v19 = png_ptr->zbuf_size;
        png_ptr->zstream.next_out = png_ptr->zbuf;
        png_ptr->zstream.avail_out = v19;
      }
    }
    while ( png_ptr->zstream.avail_in != 0 );
    while ( 1 )
    {
      while ( 1 )
      {
        v20 = deflate(strm: &png_ptr->zstream, flush: 4u);
        if ( v20 != 0 )
          break;
        if ( png_ptr->zstream.avail_out == 0 )
        {
          v21 = comp->num_output_ptr;
          v22 = comp->max_output_ptr;
          if ( v21 >= v22 )
          {
            v23 = comp->output_ptr;
            v24 = v21 + 4;
            comp->max_output_ptr = v24;
            v25 = 4 * v24;
            if ( v23 != nullptr )
            {
              v26 = (char **)png_malloc(png_ptr, size: v25);
              comp->output_ptr = v26;
              memcpy(Dst: v26, Src: v23, Size: 4 * v22);
              png_free(png_ptr, ptr: v23);
            }
            else
            {
              comp->output_ptr = (char **)png_malloc(png_ptr, size: v25);
            }
          }
          comp->output_ptr[comp->num_output_ptr] = (char *)png_malloc(png_ptr, size: png_ptr->zbuf_size);
          memcpy(Dst: comp->output_ptr[comp->num_output_ptr], Src: png_ptr->zbuf, Size: png_ptr->zbuf_size);
          ++comp->num_output_ptr;
          v27 = png_ptr->zbuf_size;
          png_ptr->zstream.next_out = png_ptr->zbuf;
          png_ptr->zstream.avail_out = v27;
        }
      }
      if ( v20 == 1 )
        break;
      v28 = png_ptr->zstream.msg;
      if ( v28 != nullptr )
        png_error(png_ptr, error_message: v28);
      else
        png_error(png_ptr, error_message: "zlib error");
    }
    v29 = png_ptr->zbuf_size;
    avail_out = png_ptr->zstream.avail_out;
    result = v29 * comp->num_output_ptr;
    if ( avail_out < v29 )
      result += v29 - avail_out;
  }
  return result;
}


// ========================================================================
// png_write_compressed_data_out
// EA  : 0x8322D118
// RVA : 0x0122D118
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_compressed_data_out(png_struct_def *png_ptr, compression_state *comp)
{
  unsigned __int8 *input; // r29
  unsigned int input_len; // r30
  int v6; // r26
  int v7; // r29
  char **output_ptr; // r11
  unsigned int zbuf_size; // r27
  unsigned __int8 *v10; // r28
  unsigned int avail_out; // r11
  unsigned int v12; // r10
  unsigned __int8 *zbuf; // r30
  unsigned int v14; // r29

  input = (unsigned __int8 *)comp->input;
  if ( comp->input != nullptr )
  {
    input_len = comp->input_len;
    if ( png_ptr != nullptr && input_len != 0 )
    {
      png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)comp->input, length: input_len);
      png_write_data(png_ptr, data: input, length: input_len);
    }
  }
  else
  {
    v6 = 0;
    if ( comp->num_output_ptr > 0 )
    {
      v7 = 0;
      do
      {
        output_ptr = comp->output_ptr;
        zbuf_size = png_ptr->zbuf_size;
        v10 = (unsigned __int8 *)output_ptr[v7];
        if ( v10 != nullptr && zbuf_size != 0 )
        {
          png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)output_ptr[v7], length: png_ptr->zbuf_size);
          png_write_data(png_ptr, data: v10, length: zbuf_size);
        }
        png_free(png_ptr, ptr: comp->output_ptr[v7]);
        ++v6;
        comp->output_ptr[v7++] = nullptr;
      }
      while ( v6 < comp->num_output_ptr );
    }
    if ( comp->max_output_ptr != 0 )
      png_free(png_ptr, ptr: comp->output_ptr);
    comp->output_ptr = nullptr;
    avail_out = png_ptr->zstream.avail_out;
    v12 = png_ptr->zbuf_size;
    if ( avail_out < v12 )
    {
      zbuf = png_ptr->zbuf;
      v14 = v12 - avail_out;
      if ( zbuf != nullptr && v14 != 0 )
      {
        png_calculate_crc(png_ptr, ptr: png_ptr->zbuf, length: v12 - avail_out);
        png_write_data(png_ptr, data: zbuf, length: v14);
      }
    }
    deflateReset(strm: &png_ptr->zstream);
    png_ptr->zstream.data_type = 0;
  }
}


// ========================================================================
// png_write_PLTE
// EA  : 0x8322D268
// RVA : 0x0122D268
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_PLTE(png_struct_def *png_ptr, png_color_struct *palette, unsigned int num_pal)
{
  unsigned int v3; // r29
  unsigned int v4; // r8
  png_struct_def *v5; // r30
  char *v7; // r4
  unsigned __int8 *p_blue; // r31
  unsigned __int8 v9; // r11
  unsigned __int8 v10; // r10
  unsigned __int8 v11; // r9
  unsigned int crc; // r11
  unsigned __int8 v13[4]; // [sp+50h] [-30h] BYREF
  unsigned int v14; // [sp+54h] [-2Ch] BYREF
  char v15[40]; // [sp+58h] [-28h] BYREF

  v3 = num_pal;
  v4 = png_ptr->mng_features_permitted & 1;
  strcpy(v15, "PLTE");
  v5 = png_ptr;
  if ( v4 == 0 && num_pal == 0 || num_pal > 0x100 )
  {
    v7 = "Invalid number of colors in palette";
    if ( png_ptr->color_type != 3 )
    {
LABEL_8:
      png_warning(png_ptr, warning_message: (png_struct_def *)v7);
      return;
    }
    png_error(png_ptr, error_message: "Invalid number of colors in palette");
  }
  if ( (v5->color_type & 2) == 0 )
  {
    png_ptr = v5;
    v7 = "Ignoring request to write a PLTE chunk in grayscale PNG";
    goto LABEL_8;
  }
  v5->num_palette = v3;
  png_write_chunk_start(png_ptr: v5, chunk_name: (unsigned __int8 *)v15, length: 3 * v3);
  if ( v3 != 0 )
  {
    p_blue = &palette[-1].blue;
    do
    {
      v9 = p_blue[1];
      v10 = p_blue[2];
      p_blue += 3;
      v11 = *p_blue;
      v13[0] = v9;
      v13[1] = v10;
      v13[2] = v11;
      png_calculate_crc(png_ptr: v5, ptr: v13, length: 3u);
      png_write_data(png_ptr: v5, data: v13, length: 3u);
      --v3;
    }
    while ( v3 != 0 );
  }
  crc = v5->crc;
  v14 = crc;
  png_write_data(png_ptr: v5, data: (unsigned __int8 *)&v14, length: 4u);
  v5->mode |= 2u;
}


// ========================================================================
// png_write_hIST
// EA  : 0x8322D3B8
// RVA : 0x0122D3B8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_hIST(png_struct_def *png_ptr, unsigned __int16 *hist, int num_hist)
{
  int num_palette; // r11
  int v6; // r31
  unsigned __int16 *v7; // r29
  __int16 v8; // r11
  unsigned int crc; // r11
  unsigned __int8 v10[4]; // [sp+50h] [-30h] BYREF
  unsigned int v11; // [sp+54h] [-2Ch] BYREF
  char v12[40]; // [sp+58h] [-28h] BYREF

  num_palette = png_ptr->num_palette;
  strcpy(v12, "hIST");
  v6 = num_hist;
  if ( num_hist <= num_palette )
  {
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v12, length: 2 * num_hist);
    if ( v6 > 0 )
    {
      v7 = hist - 1;
      do
      {
        v8 = *++v7;
        v10[0] = HIBYTE(*v7);
        v10[1] = v8;
        png_calculate_crc(png_ptr, ptr: v10, length: 2u);
        png_write_data(png_ptr, data: v10, length: 2u);
        --v6;
      }
      while ( v6 != 0 );
    }
    crc = png_ptr->crc;
    v11 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v11, length: 4u);
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid number of histogram entries specified");
  }
}


// ========================================================================
// png_check_keyword
// EA  : 0x8322D4A0
// RVA : 0x0122D4A0
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

unsigned int __fastcall png_check_keyword(png_struct_def *png_ptr, char *key, char **new_key)
{
  char *v4; // r30
  int v6; // r23
  char *v7; // r11
  int v8; // r10
  int v9; // r11
  unsigned int v10; // r27
  char *v11; // r3
  char *i; // r31
  unsigned int v14; // r11
  char *v15; // r31
  char *v16; // r31
  char v17; // r10
  int j; // r11
  char *v19; // r9
  int v20; // r8
  char v21[128]; // [sp+50h] [-80h] BYREF

  v4 = key;
  *new_key = nullptr;
  v6 = 0;
  if ( key == nullptr )
    goto LABEL_35;
  v7 = key;
  do
    v8 = (unsigned __int8)*v7++;
  while ( v8 != 0 );
  v9 = v7 - key - 1;
  v10 = v9;
  if ( v9 != 0 )
  {
    v11 = (char *)png_malloc_warn(png_ptr, size: v9 + 2);
    *new_key = v11;
    if ( v11 == nullptr )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Out of memory while procesing keyword");
      return 0;
    }
    for ( i = v11; *v4 != 0; ++i )
    {
      v14 = (unsigned __int8)*v4;
      if ( v14 < 0x20 || v14 > 0x7E && v14 < 0xA1 )
      {
        snprintf_0(string: v21, count: 0x28u, format: "invalid keyword character 0x%02X", v14);
        png_warning(png_ptr, warning_message: (png_struct_def *)v21);
        *i = 32;
      }
      else
      {
        *i = v14;
      }
      ++v4;
    }
    *i = 0;
    v15 = &(*new_key)[v10 - 1];
    if ( *v15 == 32 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"trailing spaces removed from keyword");
      for ( ; *v15 == 32; --v15 )
      {
        *v15 = 0;
        --v10;
      }
    }
    v16 = *new_key;
    v17 = **new_key;
    j = v17;
    if ( v17 == 32 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"leading spaces removed from keyword");
      v17 = *v16;
      for ( j = *v16; j == 32; j = *v16 )
      {
        v17 = *++v16;
        --v10;
      }
    }
    v19 = *new_key;
    v20 = 0;
    if ( j != 0 )
    {
      while ( j == 32 )
      {
        if ( v20 == 0 )
        {
          v20 = 1;
LABEL_26:
          *v19++ = v17;
          goto LABEL_27;
        }
        --v10;
        v6 = 1;
LABEL_27:
        v17 = *++v16;
        j = *v16;
        if ( *v16 == 0 )
          goto LABEL_28;
      }
      v20 = 0;
      goto LABEL_26;
    }
LABEL_28:
    *v19 = 0;
    if ( v6 != 0 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"extra interior spaces removed from keyword");
    if ( v10 != 0 )
    {
      if ( v10 > 0x4F )
      {
        png_warning(png_ptr, warning_message: (png_struct_def *)"keyword length must be 1 - 79 characters");
        v10 = 79;
        new_key[79] = nullptr;
      }
      return v10;
    }
    else
    {
      png_free(png_ptr, ptr: *new_key);
      *new_key = nullptr;
      png_warning(png_ptr, warning_message: (png_struct_def *)"Zero length keyword");
      return 0;
    }
  }
  else
  {
LABEL_35:
    png_warning(png_ptr, warning_message: (png_struct_def *)"zero length keyword");
    return 0;
  }
}


// ========================================================================
// png_write_tEXt
// EA  : 0x8322D720
// RVA : 0x0122D720
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_tEXt(png_struct_def *png_ptr, char *key, char *text, unsigned int text_len)
{
  unsigned int v4; // r30
  unsigned int v7; // r3
  unsigned int v8; // r29
  char *v9; // r11
  int v10; // r10
  unsigned __int8 *v11; // r28
  unsigned int v12; // r29
  char *v13; // [sp+50h] [-40h] BYREF
  char v14[60]; // [sp+54h] [-3Ch] BYREF

  v4 = 0;
  strcpy(v14, "tEXt");
  if ( key != nullptr && (v7 = png_check_keyword(png_ptr, key, new_key: &v13), v8 = v7, v7 != 0) )
  {
    if ( text != nullptr && *text != 0 )
    {
      v9 = text;
      do
        v10 = (unsigned __int8)*v9++;
      while ( v10 != 0 );
      v4 = v9 - text - 1;
    }
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v14, length: v7 + v4 + 1);
    v11 = (unsigned __int8 *)v13;
    v12 = v8 + 1;
    if ( png_ptr != nullptr && v13 != nullptr && v12 != 0 )
    {
      png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v13, length: v12);
      png_write_data(png_ptr, data: v11, length: v12);
    }
    if ( v4 != 0 && png_ptr != nullptr && text != nullptr )
    {
      png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)text, length: v4);
      png_write_data(png_ptr, data: (unsigned __int8 *)text, length: v4);
    }
    png_write_chunk_end(png_ptr);
    png_free(png_ptr, ptr: v11);
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Empty keyword in tEXt chunk");
  }
}


// ========================================================================
// png_write_zTXt
// EA  : 0x8322D870
// RVA : 0x0122D870
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_zTXt(png_struct_def *png_ptr, char *key, char *text, unsigned int text_len, int compression)
{
  unsigned int v8; // r29
  char *v9; // r11
  int v10; // r10
  unsigned int v11; // r3
  unsigned __int8 *v12; // r28
  char *v13; // r29
  unsigned __int8 v14[4]; // [sp+50h] [-60h] BYREF
  char *v15; // [sp+54h] [-5Ch] BYREF
  char v16[8]; // [sp+58h] [-58h] BYREF
  compression_state v17[4]; // [sp+60h] [-50h] BYREF

  strcpy(v16, "zTXt");
  memset(v17, 0, 20);
  if ( key != nullptr && (v8 = png_check_keyword(png_ptr, key, new_key: &v15)) != 0 )
  {
    if ( text != nullptr && *text != 0 && compression != -1 )
    {
      v9 = text;
      do
        v10 = (unsigned __int8)*v9++;
      while ( v10 != 0 );
      v11 = png_text_compress(png_ptr, text, text_len: v9 - text - 1, compression, comp: v17);
      png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v16, length: v8 + v11 + 2);
      v12 = (unsigned __int8 *)v15;
      if ( png_ptr != nullptr && v15 != nullptr && v8 != -1 )
      {
        png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v15, length: v8 + 1);
        png_write_data(png_ptr, data: v12, length: v8 + 1);
      }
      png_free(png_ptr, ptr: v12);
      v14[0] = compression;
      if ( png_ptr != nullptr )
      {
        png_calculate_crc(png_ptr, ptr: v14, length: 1u);
        png_write_data(png_ptr, data: v14, length: 1u);
      }
      png_write_compressed_data_out(png_ptr, comp: v17);
      png_write_chunk_end(png_ptr);
    }
    else
    {
      v13 = v15;
      png_write_tEXt(png_ptr, key: v15, text, text_len: 0);
      png_free(png_ptr, ptr: v13);
    }
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Empty keyword in zTXt chunk");
  }
}


// ========================================================================
// png_write_pCAL
// EA  : 0x8322DA20
// RVA : 0x0122DA20
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_pCAL(
        png_struct_def *png_ptr,
        char *purpose,
        int X0,
        int X1,
        int type,
        int nparams,
        char *units,
        char **params)
{
  char v8; // r21
  unsigned int v16; // r26
  char *v17; // r11
  int v18; // r10
  unsigned int v19; // r27
  int v20; // r31
  _BYTE *v21; // r3
  _BYTE *v22; // r22
  int v23; // r9
  int v24; // ctr
  int *v25; // r11
  char *v26; // r6
  unsigned __int8 *v27; // r10
  int v28; // r5
  int v29; // r8
  BOOL v30; // r10
  int v31; // r10
  unsigned __int8 *v32; // r28
  unsigned __int8 **v33; // r31
  int v34; // r26
  unsigned int v35; // r28
  unsigned __int8 *v36; // r27
  unsigned int crc; // r11
  int v38; // [sp+50h] [-90h] BYREF
  unsigned int v39; // [sp+54h] [-8Ch] BYREF
  char *v40; // [sp+58h] [-88h] BYREF
  char v41[12]; // [sp+5Ch] [-84h] BYREF
  _DWORD v42[2]; // [sp+68h] [-78h] BYREF
  char v43; // [sp+70h] [-70h]
  char v44; // [sp+71h] [-6Fh]

  v8 = type;
  strcpy(v41, "pCAL");
  if ( type >= 4 )
    png_warning(png_ptr, warning_message: (png_struct_def *)"Unrecognized equation type for pCAL chunk");
  v16 = png_check_keyword(png_ptr, key: purpose, new_key: &v40) + 1;
  v17 = units;
  do
    v18 = (unsigned __int8)*v17++;
  while ( v18 != 0 );
  v19 = v17 - units - (nparams == 0);
  v20 = v19 + v16 + 10;
  v21 = png_malloc(png_ptr, size: 4 * nparams);
  v22 = v21;
  v23 = 0;
  if ( nparams > 0 )
  {
    v24 = nparams;
    v25 = (int *)v21;
    v26 = (char *)((char *)params - v21);
    do
    {
      v27 = *(unsigned __int8 **)((char *)v25 + (_DWORD)v26);
      do
        v28 = *v27++;
      while ( v28 != 0 );
      v29 = (int)&v27[-*(int *)((char *)v25 + (_DWORD)v26) - 1];
      v30 = nparams - 1 != v23++;
      v31 = v30 + v29;
      *v25 = v31;
      v20 += v31;
      ++v25;
      --v24;
    }
    while ( v24 != 0 );
  }
  v32 = (unsigned __int8 *)v40;
  if ( png_ptr != nullptr )
  {
    v38 = v20;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v38, length: 4u);
    png_write_data(png_ptr, data: (unsigned __int8 *)v41, length: 4u);
    png_reset_crc(png_ptr);
    png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v41, length: 4u);
    if ( v32 != nullptr && v16 != 0 )
    {
      png_calculate_crc(png_ptr, ptr: v32, length: v16);
      png_write_data(png_ptr, data: v32, length: v16);
    }
  }
  v42[0] = X0;
  v42[1] = X1;
  v43 = v8;
  v44 = nparams;
  if ( png_ptr != nullptr )
  {
    png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v42, length: 0xAu);
    png_write_data(png_ptr, data: (unsigned __int8 *)v42, length: 0xAu);
    if ( units != nullptr && v19 != 0 )
    {
      png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)units, length: v19);
      png_write_data(png_ptr, data: (unsigned __int8 *)units, length: v19);
    }
  }
  png_free(png_ptr, ptr: v32);
  if ( nparams > 0 )
  {
    v33 = (unsigned __int8 **)params;
    v34 = v22 - (_BYTE *)params;
    do
    {
      v35 = *(unsigned int *)((char *)v33 + v34);
      v36 = *v33;
      if ( png_ptr != nullptr && v36 != nullptr && v35 != 0 )
      {
        png_calculate_crc(png_ptr, ptr: *v33, length: *(unsigned int *)((char *)v33 + v34));
        png_write_data(png_ptr, data: v36, length: v35);
      }
      --nparams;
      ++v33;
    }
    while ( nparams != 0 );
  }
  png_free(png_ptr, ptr: v22);
  if ( png_ptr != nullptr )
  {
    crc = png_ptr->crc;
    v39 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v39, length: 4u);
  }
}


// ========================================================================
// png_write_start_row
// EA  : 0x8322DD20
// RVA : 0x0122DD20
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_start_row(png_struct_def *png_ptr)
{
  unsigned int v2; // r11
  unsigned int width; // r10
  unsigned int v4; // r11
  unsigned int v5; // r30
  unsigned __int8 *v6; // r3
  unsigned __int8 *v7; // r3
  unsigned __int8 *v8; // r3
  unsigned __int8 *v9; // r3
  unsigned __int8 *v10; // r3
  unsigned __int8 *v11; // r3
  unsigned int v12; // r7
  unsigned int height; // r11
  unsigned __int8 *zbuf; // r10

  v2 = png_ptr->usr_channels * png_ptr->usr_bit_depth;
  width = png_ptr->width;
  if ( v2 < 8 )
    v4 = (width * v2 + 7) >> 3;
  else
    v4 = (v2 >> 3) * width;
  v5 = v4 + 1;
  v6 = (unsigned __int8 *)png_malloc(png_ptr, size: v4 + 1);
  png_ptr->row_buf = v6;
  *v6 = 0;
  if ( (png_ptr->do_filter & 0x10) != 0 )
  {
    v7 = (unsigned __int8 *)png_malloc(png_ptr, size: png_ptr->rowbytes + 1);
    png_ptr->sub_row = v7;
    *v7 = 1;
  }
  if ( (png_ptr->do_filter & 0xE0) != 0 )
  {
    v8 = (unsigned __int8 *)png_malloc(png_ptr, size: v5);
    png_ptr->prev_row = v8;
    memset(Dst: v8, Val: 0, Size: v5);
    if ( (png_ptr->do_filter & 0x20) != 0 )
    {
      v9 = (unsigned __int8 *)png_malloc(png_ptr, size: png_ptr->rowbytes + 1);
      png_ptr->up_row = v9;
      *v9 = 2;
    }
    if ( (png_ptr->do_filter & 0x40) != 0 )
    {
      v10 = (unsigned __int8 *)png_malloc(png_ptr, size: png_ptr->rowbytes + 1);
      png_ptr->avg_row = v10;
      *v10 = 3;
    }
    if ( (png_ptr->do_filter & 0x80) != 0 )
    {
      v11 = (unsigned __int8 *)png_malloc(png_ptr, size: png_ptr->rowbytes + 1);
      png_ptr->paeth_row = v11;
      *v11 = 4;
    }
  }
  if ( png_ptr->interlaced == 0 || (png_ptr->transformations & 2) != 0 )
  {
    height = png_ptr->height;
    png_ptr->usr_width = png_ptr->width;
    png_ptr->num_rows = height;
  }
  else
  {
    v12 = (png_ptr->width + 7) >> 3;
    png_ptr->num_rows = (png_ptr->height + 7) >> 3;
    png_ptr->usr_width = v12;
  }
  zbuf = png_ptr->zbuf;
  png_ptr->zstream.avail_out = png_ptr->zbuf_size;
  png_ptr->zstream.next_out = zbuf;
}


// ========================================================================
// png_do_write_interlace
// EA  : 0x8322DED8
// RVA : 0x0122DED8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_do_write_interlace(png_row_info_struct *row_info, unsigned __int8 *row, int pass)
{
  unsigned int pixel_depth; // r11
  int v6; // r24
  unsigned int v7; // r28
  unsigned __int8 *v8; // r31
  size_t v9; // r29
  unsigned int v10; // r26
  unsigned int v11; // r30
  int v12; // r25
  unsigned __int8 *v13; // r4
  unsigned int v14; // r6
  unsigned __int8 *v15; // r7
  int v16; // r9
  int v17; // r10
  unsigned int v18; // r11
  unsigned int v19; // r8
  int v20; // r5
  bool v21; // cr58
  unsigned int v22; // r6
  int v23; // r9
  unsigned int v24; // r11
  unsigned int v25; // r8
  int v26; // r5
  unsigned int width; // r6
  int v28; // r9
  unsigned int v29; // r11
  unsigned int v30; // r8
  int v31; // r5
  unsigned int v32; // r9
  unsigned int v33; // r11
  unsigned int v34; // r8
  unsigned int v35; // r10
  _DWORD v36[8]; // [sp+50h] [-90h] BYREF
  _DWORD v37[28]; // [sp+70h] [-70h] BYREF

  v37[0] = 0;
  v37[1] = 4;
  v37[2] = 0;
  v37[3] = 2;
  v37[4] = 0;
  v37[5] = 1;
  v37[6] = 0;
  v36[0] = 8;
  v36[1] = 8;
  v36[2] = 4;
  v36[3] = 4;
  v36[4] = 2;
  v36[5] = 2;
  v36[6] = 1;
  if ( pass < 6 )
  {
    pixel_depth = row_info->pixel_depth;
    v6 = pass;
    switch ( pixel_depth )
    {
      case 1u:
        width = row_info->width;
        v15 = row;
        v17 = 0;
        v28 = 7;
        v10 = v37[v6];
        v29 = v10;
        if ( v10 >= row_info->width )
          goto LABEL_34;
        v30 = v10 >> 3;
        v31 = v36[v6];
        do
        {
          v17 |= ((row[v30] >> (7 - (v29 & 7))) & 1) << v28;
          if ( v28 != 0 )
          {
            --v28;
          }
          else
          {
            *v15 = v17;
            v28 = 7;
            ++v15;
            v17 = 0;
          }
          v29 += v31;
          v30 = v29 >> 3;
        }
        while ( v29 < width );
        v21 = v28 == 7;
        break;
      case 2u:
        v22 = row_info->width;
        v15 = row;
        v23 = 6;
        v17 = 0;
        v10 = v37[v6];
        v24 = v10;
        if ( v10 >= row_info->width )
          goto LABEL_34;
        v25 = v10 >> 2;
        v26 = v36[v6];
        do
        {
          v17 |= ((row[v25] >> (2 * (3 - (v24 & 3)))) & 3) << v23;
          if ( v23 != 0 )
          {
            v23 -= 2;
          }
          else
          {
            *v15 = v17;
            v23 = 6;
            ++v15;
            v17 = 0;
          }
          v24 += v26;
          v25 = v24 >> 2;
        }
        while ( v24 < v22 );
        v21 = v23 == 6;
        break;
      case 4u:
        v14 = row_info->width;
        v15 = row;
        v16 = 4;
        v17 = 0;
        v10 = v37[v6];
        v18 = v10;
        if ( v10 < row_info->width )
        {
          v19 = v10 >> 1;
          v20 = v36[v6];
          do
          {
            v17 |= ((row[v19] >> (-4 * (v18 & 1) + 4)) & 0xF) << v16;
            if ( v16 != 0 )
            {
              v16 -= 4;
            }
            else
            {
              *v15 = v17;
              v16 = 4;
              ++v15;
              v17 = 0;
            }
            v18 += v20;
            v19 = v18 >> 1;
          }
          while ( v18 < v14 );
          v21 = v16 == 4;
          break;
        }
LABEL_34:
        v32 = row_info->width;
        v33 = row_info->pixel_depth;
        v34 = v36[v6];
        __twllei(v34, 0);
        v35 = (v34 - v10 + v32 - 1) / v34;
        row_info->width = v35;
        if ( v33 < 8 )
          row_info->rowbytes = (v35 * v33 + 7) >> 3;
        else
          row_info->rowbytes = (v33 >> 3) * v35;
        return;
      default:
        v7 = row_info->width;
        v8 = row;
        v9 = pixel_depth >> 3;
        v10 = v37[v6];
        v11 = v10;
        if ( v10 < row_info->width )
        {
          v12 = v36[v6];
          do
          {
            v13 = &row[v11 * v9];
            if ( v8 != v13 )
              memcpy(Dst: v8, Src: v13, Size: v9);
            v11 += v12;
            v8 += v9;
          }
          while ( v11 < v7 );
        }
        goto LABEL_34;
    }
    if ( !v21 )
      *v15 = v17;
    goto LABEL_34;
  }
}


// ========================================================================
// png_write_chunk
// EA  : 0x8322E1B8
// RVA : 0x0122E1B8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_chunk(
        png_struct_def *png_ptr,
        unsigned __int8 *chunk_name,
        unsigned __int8 *data,
        unsigned int length)
{
  unsigned int crc; // r11
  unsigned int v8; // [sp+50h] [-30h] BYREF

  if ( png_ptr != nullptr )
  {
    png_write_chunk_start(png_ptr, chunk_name, length);
    if ( data != nullptr && length != 0 )
    {
      png_calculate_crc(png_ptr, ptr: data, length);
      png_write_data(png_ptr, data, length);
    }
    crc = png_ptr->crc;
    v8 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v8, length: 4u);
  }
}


// ========================================================================
// png_write_IHDR
// EA  : 0x8322E248
// RVA : 0x0122E248
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_IHDR(
        png_struct_def *png_ptr,
        unsigned int width,
        unsigned int height,
        int bit_depth,
        unsigned int color_type,
        int compression_type,
        int filter_type,
        unsigned int interlace_type)
{
  unsigned __int8 v14; // r29
  const char *v16; // r4
  unsigned __int8 channels; // r9
  unsigned int v18; // r11
  unsigned int v19; // r11
  unsigned int crc; // r8
  int do_filter; // r5
  unsigned int flags; // r11
  int v23; // r3
  const char *v24; // r4
  unsigned __int8 *zbuf; // r11
  unsigned int zbuf_size; // r10
  unsigned int v27; // [sp+50h] [-80h] BYREF
  char v28[12]; // [sp+54h] [-7Ch] BYREF
  unsigned __int8 v29[112]; // [sp+60h] [-70h] BYREF

  strcpy(v28, "IHDR");
  v14 = bit_depth;
  if ( color_type > 6 || color_type == 1 )
  {
LABEL_32:
    v16 = "Invalid image color type specified";
LABEL_33:
    png_error(png_ptr, error_message: v16);
    goto LABEL_34;
  }
  switch ( color_type )
  {
    case 2u:
      if ( bit_depth != 8 && bit_depth != 16 )
        png_error(png_ptr, error_message: "Invalid bit depth for RGB image");
      png_ptr->channels = 3;
      break;
    case 3u:
      if ( (unsigned int)(bit_depth - 1) <= 7
        && (bit_depth == 1
         || bit_depth == 2
         || bit_depth != 3 && (bit_depth == 4 || bit_depth != 5 && bit_depth != 6 && bit_depth != 7)) )
      {
LABEL_9:
        png_ptr->channels = 1;
        break;
      }
      v16 = "Invalid bit depth for paletted image";
      goto LABEL_33;
    case 4u:
      if ( bit_depth != 8 && bit_depth != 16 )
        png_error(png_ptr, error_message: "Invalid bit depth for grayscale+alpha image");
      png_ptr->channels = 2;
      break;
    case 5u:
      goto LABEL_32;
    case 0u:
      switch ( bit_depth )
      {
        case 1:
        case 2:
        case 4:
        case 8:
        case 16:
          goto LABEL_9;
        default:
          v16 = "Invalid bit depth for grayscale image";
          goto LABEL_33;
      }
    default:
      if ( bit_depth != 8 && bit_depth != 16 )
        png_error(png_ptr, error_message: "Invalid bit depth for RGBA image");
      png_ptr->channels = 4;
      break;
  }
LABEL_34:
  if ( compression_type != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid compression type specified");
    LOBYTE(compression_type) = 0;
  }
  if ( ((png_ptr->mng_features_permitted & 4) == 0
     || (png_ptr->mode & 0x1000) != 0
     || color_type != 2 && color_type != 6
     || filter_type != 64)
    && filter_type != 0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid filter type specified");
    LOBYTE(filter_type) = 0;
  }
  if ( interlace_type >= 2 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid interlace type specified");
    LOBYTE(interlace_type) = 1;
  }
  channels = png_ptr->channels;
  png_ptr->width = width;
  png_ptr->height = height;
  png_ptr->bit_depth = v14;
  png_ptr->color_type = color_type;
  v18 = (unsigned __int8)(channels * v14);
  png_ptr->pixel_depth = v18;
  png_ptr->interlaced = interlace_type;
  png_ptr->filter_type = filter_type;
  png_ptr->compression_type = compression_type;
  if ( v18 < 8 )
    v19 = (v18 * width + 7) >> 3;
  else
    v19 = (v18 >> 3) * width;
  png_ptr->rowbytes = v19;
  png_ptr->usr_width = width;
  v29[0] = HIBYTE(width);
  v29[1] = BYTE1(width);
  v29[2] = BYTE2(width);
  v29[4] = HIBYTE(height);
  v29[5] = BYTE1(height);
  v29[6] = BYTE2(height);
  png_ptr->usr_bit_depth = v14;
  png_ptr->usr_channels = channels;
  v29[3] = width;
  v29[7] = height;
  v29[8] = v14;
  v29[9] = color_type;
  v29[10] = compression_type;
  v29[11] = filter_type;
  v29[12] = interlace_type;
  png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v28, length: 0xDu);
  png_calculate_crc(png_ptr, ptr: v29, length: 0xDu);
  png_write_data(png_ptr, data: v29, length: 0xDu);
  crc = png_ptr->crc;
  v27 = crc;
  png_write_data(png_ptr, data: (unsigned __int8 *)&v27, length: 4u);
  do_filter = png_ptr->do_filter;
  png_ptr->zstream.opaque = png_ptr;
  png_ptr->zstream.zalloc = (void *(__fastcall *)(void *, unsigned int, unsigned int))png_zalloc;
  png_ptr->zstream.zfree = (void (__fastcall *)(void *, void *))png_zfree;
  if ( do_filter == 0 )
  {
    if ( png_ptr->color_type == 3 || png_ptr->bit_depth < 8u )
      png_ptr->do_filter = 8;
    else
      png_ptr->do_filter = -8;
  }
  flags = png_ptr->flags;
  if ( (flags & 1) == 0 )
    png_ptr->zlib_strategy = png_ptr->do_filter != 8;
  if ( (flags & 2) == 0 )
    png_ptr->zlib_level = -1;
  if ( (flags & 4) == 0 )
    png_ptr->zlib_mem_level = 8;
  if ( (flags & 8) == 0 )
    png_ptr->zlib_window_bits = 15;
  if ( (flags & 0x10) == 0 )
    png_ptr->zlib_method = 8;
  v23 = deflateInit2_(
          strm: &png_ptr->zstream,
          level: png_ptr->zlib_level,
          method: png_ptr->zlib_method,
          windowBits: png_ptr->zlib_window_bits,
          memLevel: png_ptr->zlib_mem_level,
          strategy: png_ptr->zlib_strategy,
          version: "1.2.3",
          stream_size: 56);
  if ( v23 != 0 )
  {
    switch ( v23 )
    {
      case -6:
        v24 = "zlib failed to initialize compressor -- version error";
        break;
      case -2:
        v24 = "zlib failed to initialize compressor -- stream error";
        break;
      case -4:
        v24 = "zlib failed to initialize compressor -- mem error";
        break;
      default:
LABEL_73:
        png_error(png_ptr, error_message: "zlib failed to initialize compressor");
        goto LABEL_74;
    }
    png_error(png_ptr, error_message: v24);
    goto LABEL_73;
  }
LABEL_74:
  zbuf = png_ptr->zbuf;
  zbuf_size = png_ptr->zbuf_size;
  png_ptr->zstream.data_type = 0;
  png_ptr->mode = 1;
  png_ptr->zstream.next_out = zbuf;
  png_ptr->zstream.avail_out = zbuf_size;
}


// ========================================================================
// png_write_IDAT
// EA  : 0x8322E728
// RVA : 0x0122E728
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_IDAT(png_struct_def *png_ptr, unsigned __int8 *data, unsigned int length)
{
  unsigned int mode; // r11
  char v7[48]; // [sp+50h] [-30h] BYREF

  mode = png_ptr->mode;
  strcpy(v7, "IDAT");
  if ( (mode & 4) == 0 && png_ptr->compression_type == 0 && ((*data & 0xF) != 8 || (*data & 0xF0u) > 0x70) )
    png_error(png_ptr, error_message: "Invalid zlib compression method or flags in IDAT");
  png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v7, data, length);
  png_ptr->mode |= 4u;
}


// ========================================================================
// png_write_IEND
// EA  : 0x8322E8A8
// RVA : 0x0122E8A8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_IEND(png_struct_def *png_ptr)
{
  unsigned int crc; // r11
  unsigned int v3; // [sp+50h] [-20h] BYREF
  char v4[12]; // [sp+54h] [-1Ch] BYREF

  strcpy(v4, "IEND");
  if ( png_ptr != nullptr )
  {
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v4, length: 0);
    crc = png_ptr->crc;
    v3 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v3, length: 4u);
  }
  png_ptr->mode |= 0x10u;
}


// ========================================================================
// png_write_gAMA
// EA  : 0x8322E948
// RVA : 0x0122E948
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_gAMA(png_struct_def *png_ptr, long double file_gamma)
{
  unsigned int crc; // r11
  _DWORD v4[2]; // [sp+50h] [-30h] BYREF
  __int64 v5; // [sp+58h] [-28h] BYREF
  char v6[16]; // [sp+60h] [-20h] BYREF

  strcpy(v6, "gAMA");
  v5 = (__int64)(*(double *)&file_gamma * 100000.0 + 0.5);
  v4[0] = v5;
  if ( png_ptr != nullptr )
  {
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v6, length: 4u);
    png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v4, length: 4u);
    png_write_data(png_ptr, data: (unsigned __int8 *)v4, length: 4u);
    crc = png_ptr->crc;
    HIDWORD(v5) = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v5, length: 4u);
  }
}


// ========================================================================
// png_write_sRGB
// EA  : 0x8322EA38
// RVA : 0x0122EA38
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_sRGB(png_struct_def *png_ptr, int srgb_intent)
{
  unsigned __int8 v3; // r30
  unsigned int crc; // r11
  unsigned __int8 v5[4]; // [sp+50h] [-30h] BYREF
  unsigned int v6; // [sp+54h] [-2Ch] BYREF
  char v7[16]; // [sp+58h] [-28h] BYREF

  strcpy(v7, "sRGB");
  v3 = srgb_intent;
  if ( srgb_intent >= 4 )
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid sRGB rendering intent specified");
  v5[0] = v3;
  if ( png_ptr != nullptr )
  {
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v7, length: 1u);
    png_calculate_crc(png_ptr, ptr: v5, length: 1u);
    png_write_data(png_ptr, data: v5, length: 1u);
    crc = png_ptr->crc;
    v6 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v6, length: 4u);
  }
}


// ========================================================================
// png_write_iCCP
// EA  : 0x8322EB18
// RVA : 0x0122EB18
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_iCCP(
        png_struct_def *png_ptr,
        char *name,
        int compression_type,
        char *profile,
        int profile_len)
{
  int v9; // r28
  unsigned int v10; // r27
  unsigned __int8 *v11; // r28
  unsigned int v12; // r27
  char *v13; // [sp+50h] [-70h] BYREF
  char v14[12]; // [sp+54h] [-6Ch] BYREF
  compression_state v15[4]; // [sp+60h] [-60h] BYREF

  strcpy(v14, "iCCP");
  v9 = 0;
  memset(v15, 0, 20);
  if ( name != nullptr && (v10 = png_check_keyword(png_ptr, key: name, new_key: &v13)) != 0 )
  {
    if ( compression_type != 0 )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Unknown compression type in iCCP chunk");
    if ( profile != nullptr )
    {
      if ( profile_len > 3 )
        v9 = ((((__ROL4__((unsigned __int8)*profile, 8) | (unsigned __int8)profile[1]) << 8)
             | (unsigned __int8)profile[2]) << 8)
           | (unsigned __int8)profile[3];
      if ( profile_len < v9 )
      {
        png_warning(png_ptr, warning_message: (png_struct_def *)"Embedded profile length too large in iCCP chunk");
        return;
      }
      if ( profile_len > v9 )
      {
        png_warning(png_ptr, warning_message: (png_struct_def *)"Truncating profile to actual length in iCCP chunk");
        profile_len = v9;
      }
      if ( profile_len != 0 )
        profile_len = png_text_compress(png_ptr, text: profile, text_len: profile_len, compression: 0, comp: v15);
    }
    else
    {
      profile_len = 0;
    }
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v14, length: v10 + profile_len + 2);
    v11 = (unsigned __int8 *)v13;
    v13[v10 + 1] = 0;
    v12 = v10 + 2;
    if ( png_ptr != nullptr && v11 != nullptr && v12 != 0 )
    {
      png_calculate_crc(png_ptr, ptr: v11, length: v12);
      png_write_data(png_ptr, data: v11, length: v12);
    }
    if ( profile_len != 0 )
      png_write_compressed_data_out(png_ptr, comp: v15);
    png_write_chunk_end(png_ptr);
    png_free(png_ptr, ptr: v11);
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Empty keyword in iCCP chunk");
  }
}


// ========================================================================
// png_write_sPLT
// EA  : 0x8322ECE8
// RVA : 0x0122ECE8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_sPLT(png_struct_def *png_ptr, png_sPLT_struct *spalette)
{
  int depth; // r11
  unsigned __int8 *p_depth; // r26
  unsigned int v6; // r27
  char *name; // r4
  int v8; // r28
  unsigned int v9; // r3
  unsigned int v10; // r31
  unsigned __int8 *v11; // r28
  unsigned int v12; // r31
  png_sPLT_entry_struct *entries; // r11
  unsigned __int16 *p_blue; // r31
  unsigned __int16 v15; // r3
  __int16 v16; // r11
  __int16 v17; // r8
  unsigned __int16 v18; // r5
  unsigned __int16 v19; // r11
  unsigned __int16 v20; // r8
  unsigned int crc; // r11
  unsigned int v22; // [sp+50h] [-60h] BYREF
  char *v23; // [sp+54h] [-5Ch] BYREF
  char v24[8]; // [sp+58h] [-58h] BYREF
  _WORD v25[40]; // [sp+60h] [-50h] BYREF

  depth = spalette->depth;
  strcpy(v24, "sPLT");
  p_depth = &spalette->depth;
  v6 = 6;
  if ( depth != 8 )
    v6 = 10;
  name = spalette->name;
  v8 = spalette->nentries * v6;
  if ( spalette->name != nullptr && (v9 = png_check_keyword(png_ptr, key: name, new_key: &v23), v10 = v9, v9 != 0) )
  {
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v24, length: v9 + v8 + 2);
    v11 = (unsigned __int8 *)v23;
    v12 = v10 + 1;
    if ( png_ptr != nullptr )
    {
      if ( v23 != nullptr && v12 != 0 )
      {
        png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v23, length: v12);
        png_write_data(png_ptr, data: v11, length: v12);
      }
      if ( p_depth != nullptr )
      {
        png_calculate_crc(png_ptr, ptr: p_depth, length: 1u);
        png_write_data(png_ptr, data: p_depth, length: 1u);
      }
    }
    entries = spalette->entries;
    if ( entries < &entries[spalette->nentries] )
    {
      p_blue = &entries->blue;
      do
      {
        if ( *p_depth == 8 )
        {
          HIBYTE(v25[0]) = *(p_blue - 2);
          LOBYTE(v25[0]) = *(p_blue - 1);
          HIBYTE(v25[1]) = *p_blue;
          LOBYTE(v25[1]) = p_blue[1];
          v15 = p_blue[2];
          v25[2] = v15;
        }
        else
        {
          v16 = *(p_blue - 2);
          v25[0] = v16;
          v17 = *(p_blue - 1);
          v25[1] = v17;
          v18 = *p_blue;
          HIBYTE(v25[2]) = HIBYTE(*p_blue);
          LOBYTE(v25[2]) = v18;
          v19 = p_blue[1];
          v25[3] = v19;
          v20 = p_blue[2];
          v25[4] = v20;
        }
        if ( png_ptr != nullptr )
        {
          png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v25, length: v6);
          png_write_data(png_ptr, data: (unsigned __int8 *)v25, length: v6);
        }
        p_blue += 5;
      }
      while ( (png_sPLT_entry_struct *)(p_blue - 2) < &spalette->entries[spalette->nentries] );
    }
    if ( png_ptr != nullptr )
    {
      crc = png_ptr->crc;
      v22 = crc;
      png_write_data(png_ptr, data: (unsigned __int8 *)&v22, length: 4u);
    }
    png_free(png_ptr, ptr: v11);
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Empty keyword in sPLT chunk");
  }
}


// ========================================================================
// png_write_sBIT
// EA  : 0x8322EF60
// RVA : 0x0122EF60
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_sBIT(png_struct_def *png_ptr, png_color_8_struct *sbit, int color_type)
{
  unsigned __int8 usr_bit_depth; // r11
  unsigned int v4; // r9
  unsigned int green; // r8
  unsigned int blue; // r11
  unsigned int v7; // r6
  unsigned int alpha; // r10
  unsigned __int8 v9[4]; // [sp+50h] [-20h] BYREF
  char v10[20]; // [sp+54h] [-1Ch] BYREF

  strcpy(v10, "sBIT");
  if ( (color_type & 2) != 0 )
  {
    usr_bit_depth = 8;
    if ( color_type != 3 )
      usr_bit_depth = png_ptr->usr_bit_depth;
    if ( sbit->red == 0 )
      goto LABEL_19;
    v4 = usr_bit_depth;
    if ( sbit->red > (unsigned int)usr_bit_depth )
      goto LABEL_19;
    green = sbit->green;
    if ( sbit->green == 0 )
      goto LABEL_19;
    if ( green > usr_bit_depth )
      goto LABEL_19;
    blue = sbit->blue;
    if ( sbit->blue == 0 || blue > v4 )
      goto LABEL_19;
    v9[0] = sbit->red;
    v7 = 3;
    v9[1] = green;
    v9[2] = blue;
  }
  else
  {
    if ( sbit->gray == 0 || sbit->gray > (unsigned int)png_ptr->usr_bit_depth )
      goto LABEL_19;
    v9[0] = sbit->gray;
    v7 = 1;
  }
  if ( (color_type & 4) == 0 )
  {
LABEL_18:
    png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v10, data: v9, length: v7);
    return;
  }
  alpha = sbit->alpha;
  if ( sbit->alpha != 0 && alpha <= png_ptr->usr_bit_depth )
  {
    v9[v7++] = alpha;
    goto LABEL_18;
  }
LABEL_19:
  png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid sBIT depth specified");
}


// ========================================================================
// png_write_cHRM
// EA  : 0x8322F0A8
// RVA : 0x0122F0A8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_cHRM(
        png_struct_def *png_ptr,
        long double white_x,
        long double white_y,
        long double red_x,
        long double red_y,
        double a6,
        long double green_x,
        long double green_y,
        long double blue_x,
        long double blue_y)
{
  double v10; // fp31
  double v11; // fp30
  _iobuf *v12; // r3
  char v13[8]; // [sp+50h] [-60h] BYREF
  __int64 v14; // [sp+58h] [-58h]
  __int64 v15; // [sp+60h] [-50h]
  unsigned __int8 v16[2]; // [sp+70h] [-40h] BYREF
  __int16 v17; // [sp+72h] [-3Eh]
  int v18; // [sp+74h] [-3Ch]
  char v19; // [sp+78h] [-38h]
  char v20; // [sp+79h] [-37h]
  __int16 v21; // [sp+7Ah] [-36h]
  int v22; // [sp+7Ch] [-34h]
  int v23; // [sp+80h] [-30h]
  int v24; // [sp+84h] [-2Ch]
  int v25; // [sp+88h] [-28h]
  int v26; // [sp+8Ch] [-24h]

  v10 = *(double *)&white_x;
  v11 = *((double *)&white_x + 1);
  strcpy(v13, "cHRM");
  if ( *(double *)&white_x < 0.0
    || *(double *)&white_x > 0.8
    || *((double *)&white_x + 1) < 0.0
    || *((double *)&white_x + 1) > 0.8
    || *(double *)&white_x + *((double *)&white_x + 1) > 1.0 )
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM white point specified");
    v12 = _iob_func();
    fprintf(str: v12 + 2, format: "white_x=%f, white_y=%f\n", v10, v11);
  }
  else
  {
    v14 = (__int64)(*((double *)&white_x + 1) * 100000.0 + 0.5);
    v16[0] = (unsigned int)(__int64)(*(double *)&white_x * 100000.0 + 0.5) >> 24;
    v18 = v14;
    v16[1] = (unsigned int)(__int64)(*(double *)&white_x * 100000.0 + 0.5) >> 16;
    v17 = (__int64)(*(double *)&white_x * 100000.0 + 0.5);
    if ( *(double *)&white_y < 0.0
      || *((double *)&white_y + 1) < 0.0
      || *(double *)&white_y + *((double *)&white_y + 1) > 1.0 )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM red point specified");
    }
    else
    {
      v14 = (__int64)(*((double *)&white_y + 1) * 100000.0 + 0.5);
      v19 = (unsigned int)(__int64)(*(double *)&white_y * 100000.0 + 0.5) >> 24;
      v20 = (unsigned int)(__int64)(*(double *)&white_y * 100000.0 + 0.5) >> 16;
      v21 = (__int64)(*(double *)&white_y * 100000.0 + 0.5);
      v22 = v14;
      if ( *(double *)&red_x < 0.0 || *((double *)&red_x + 1) < 0.0 || *(double *)&red_x + *((double *)&red_x + 1) > 1.0 )
      {
        png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM green point specified");
      }
      else
      {
        v15 = (__int64)(*((double *)&red_x + 1) * 100000.0 + 0.5);
        v14 = (__int64)(*(double *)&red_x * 100000.0 + 0.5);
        v23 = v14;
        v24 = v15;
        if ( *(double *)&red_y < 0.0
          || *((double *)&red_y + 1) < 0.0
          || *(double *)&red_y + *((double *)&red_y + 1) > 1.0 )
        {
          png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid cHRM blue point specified");
        }
        else
        {
          v15 = (__int64)(*((double *)&red_y + 1) * 100000.0 + 0.5);
          v14 = (__int64)(*(double *)&red_y * 100000.0 + 0.5);
          v25 = v14;
          v26 = v15;
          png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v13, data: v16, length: 0x20u);
        }
      }
    }
  }
}


// ========================================================================
// png_write_tRNS
// EA  : 0x8322F398
// RVA : 0x0122F398
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_tRNS(
        png_struct_def *png_ptr,
        unsigned __int8 *trans,
        png_color_16_struct *tran,
        int num_trans,
        int color_type)
{
  unsigned int red; // r11
  unsigned int green; // r10
  unsigned int blue; // r9
  int bit_depth; // r7
  unsigned int v9; // r11
  unsigned int v10; // r10
  unsigned int v11; // r9
  char v12[8]; // [sp+50h] [-20h] BYREF
  unsigned __int16 gray; // [sp+58h] [-18h] BYREF
  char v14; // [sp+5Ah] [-16h]
  char v15; // [sp+5Bh] [-15h]
  char v16; // [sp+5Ch] [-14h]
  char v17; // [sp+5Dh] [-13h]

  strcpy(v12, "tRNS");
  if ( color_type == 3 )
  {
    if ( num_trans <= 0 || num_trans > png_ptr->num_palette )
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid number of transparent colors specified");
    else
      png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v12, data: trans, length: num_trans);
  }
  else if ( color_type != 0 )
  {
    if ( color_type == 2 )
    {
      red = tran->red;
      green = tran->green;
      blue = tran->blue;
      bit_depth = png_ptr->bit_depth;
      LOBYTE(gray) = tran->red;
      v9 = red >> 8;
      v15 = green;
      v10 = green >> 8;
      v17 = blue;
      v11 = blue >> 8;
      HIBYTE(gray) = v9;
      v14 = v10;
      v16 = v11;
      if ( bit_depth == 8 && (__PAIR64__(v9, v10) & 0xFF000000FFLL | (unsigned __int8)v11) != 0 )
        png_warning(
          png_ptr,
          warning_message: (png_struct_def *)"Ignoring attempt to write 16-bit tRNS chunk when bit_depth is 8");
      else
        png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v12, data: (unsigned __int8 *)&gray, length: 6u);
    }
    else
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Can't write tRNS with an alpha channel");
    }
  }
  else if ( tran->gray < 1 << png_ptr->bit_depth )
  {
    gray = tran->gray;
    png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v12, data: (unsigned __int8 *)&gray, length: 2u);
  }
  else
  {
    png_warning(
      png_ptr,
      warning_message: (png_struct_def *)"Ignoring attempt to write tRNS chunk out-of-range for bit_depth");
  }
}


// ========================================================================
// png_write_bKGD
// EA  : 0x8322F540
// RVA : 0x0122F540
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_bKGD(png_struct_def *png_ptr, png_color_16_struct *back, int color_type)
{
  unsigned int v3; // r6
  unsigned int red; // r11
  unsigned int green; // r10
  unsigned int blue; // r9
  int bit_depth; // r7
  unsigned int v8; // r11
  unsigned int v9; // r10
  unsigned int v10; // r9
  char v11[8]; // [sp+50h] [-20h] BYREF
  unsigned __int16 gray; // [sp+58h] [-18h] BYREF
  char v13; // [sp+5Ah] [-16h]
  char v14; // [sp+5Bh] [-15h]
  char v15; // [sp+5Ch] [-14h]
  char v16; // [sp+5Dh] [-13h]

  strcpy(v11, "bKGD");
  if ( color_type == 3 )
  {
    if ( (png_ptr->num_palette != 0 || (png_ptr->mng_features_permitted & 1) == 0)
      && back->index > (unsigned int)png_ptr->num_palette )
    {
      png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid background palette index");
      return;
    }
    v3 = 1;
    HIBYTE(gray) = back->index;
  }
  else if ( (color_type & 2) != 0 )
  {
    red = back->red;
    green = back->green;
    blue = back->blue;
    bit_depth = png_ptr->bit_depth;
    LOBYTE(gray) = back->red;
    v8 = red >> 8;
    v14 = green;
    v9 = green >> 8;
    v16 = blue;
    v10 = blue >> 8;
    HIBYTE(gray) = v8;
    v13 = v9;
    v15 = v10;
    if ( bit_depth == 8 && (__PAIR64__(v8, v9) & 0xFF000000FFLL | (unsigned __int8)v10) != 0 )
    {
      png_warning(
        png_ptr,
        warning_message: (png_struct_def *)"Ignoring attempt to write 16-bit bKGD chunk when bit_depth is 8");
      return;
    }
    v3 = 6;
  }
  else
  {
    if ( back->gray >= 1 << png_ptr->bit_depth )
    {
      png_warning(
        png_ptr,
        warning_message: (png_struct_def *)"Ignoring attempt to write bKGD chunk out-of-range for bit_depth");
      return;
    }
    gray = back->gray;
    v3 = 2;
  }
  png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v11, data: (unsigned __int8 *)&gray, length: v3);
}


// ========================================================================
// png_write_oFFs
// EA  : 0x8322F6B8
// RVA : 0x0122F6B8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_oFFs(png_struct_def *png_ptr, int x_offset, int y_offset, int unit_type)
{
  char v7; // r28
  unsigned int crc; // r11
  unsigned int v9; // [sp+50h] [-50h] BYREF
  char v10[12]; // [sp+54h] [-4Ch] BYREF
  _DWORD v11[2]; // [sp+60h] [-40h] BYREF
  char v12; // [sp+68h] [-38h]

  strcpy(v10, "oFFs");
  v7 = unit_type;
  if ( unit_type >= 2 )
    png_warning(png_ptr, warning_message: (png_struct_def *)"Unrecognized unit type for oFFs chunk");
  v11[0] = x_offset;
  v11[1] = y_offset;
  v12 = v7;
  if ( png_ptr != nullptr )
  {
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v10, length: 9u);
    png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v11, length: 9u);
    png_write_data(png_ptr, data: (unsigned __int8 *)v11, length: 9u);
    crc = png_ptr->crc;
    v9 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v9, length: 4u);
  }
}


// ========================================================================
// png_write_sCAL
// EA  : 0x8322F7B8
// RVA : 0x0122F7B8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_sCAL(png_struct_def *png_ptr, unsigned __int8 unit, long double width, long double height)
{
  double v5; // fp31
  char *v6; // r11
  int v7; // r9
  int v8; // r31
  char *v9; // r11
  int v10; // r10
  char v11[16]; // [sp+50h] [-80h] BYREF
  unsigned __int8 v12; // [sp+60h] [-70h] BYREF
  char v13[71]; // [sp+61h] [-6Fh] BYREF

  v12 = unit;
  v5 = *((double *)&width + 1);
  strcpy(v11, "sCAL");
  snprintf_0(string: v13, count: 0x3Fu, format: "%12.12e", *(double *)&width);
  v6 = v13;
  do
    v7 = (unsigned __int8)*v6++;
  while ( v7 != 0 );
  v8 = v6 - v13 - 1 + 2;
  snprintf_0(string: &v13[v8 - 1], count: 64 - v8, format: "%12.12e", v5);
  v9 = &v13[v8 - 1];
  do
    v10 = (unsigned __int8)*v9++;
  while ( v10 != 0 );
  png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v11, data: &v12, length: v9 - (char *)&v12 - 1);
}


// ========================================================================
// png_write_pHYs
// EA  : 0x8322F8A8
// RVA : 0x0122F8A8
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_pHYs(
        png_struct_def *png_ptr,
        unsigned int x_pixels_per_unit,
        unsigned int y_pixels_per_unit,
        int unit_type)
{
  char v7; // r28
  unsigned int crc; // r11
  unsigned int v9; // [sp+50h] [-50h] BYREF
  char v10[12]; // [sp+54h] [-4Ch] BYREF
  _DWORD v11[2]; // [sp+60h] [-40h] BYREF
  char v12; // [sp+68h] [-38h]

  strcpy(v10, "pHYs");
  v7 = unit_type;
  if ( unit_type >= 2 )
    png_warning(png_ptr, warning_message: (png_struct_def *)"Unrecognized unit type for pHYs chunk");
  v11[0] = x_pixels_per_unit;
  v11[1] = y_pixels_per_unit;
  v12 = v7;
  if ( png_ptr != nullptr )
  {
    png_write_chunk_start(png_ptr, chunk_name: (unsigned __int8 *)v10, length: 9u);
    png_calculate_crc(png_ptr, ptr: (unsigned __int8 *)v11, length: 9u);
    png_write_data(png_ptr, data: (unsigned __int8 *)v11, length: 9u);
    crc = png_ptr->crc;
    v9 = crc;
    png_write_data(png_ptr, data: (unsigned __int8 *)&v9, length: 4u);
  }
}


// ========================================================================
// png_write_tIME
// EA  : 0x8322F9B0
// RVA : 0x0122F9B0
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_tIME(png_struct_def *png_ptr, png_time_struct *mod_time)
{
  unsigned int month; // r8
  int day; // r9
  int hour; // r10
  int second; // r11
  unsigned __int16 year; // r7
  unsigned __int8 minute; // r31
  char v8[8]; // [sp+50h] [-20h] BYREF
  unsigned __int16 v9; // [sp+58h] [-18h] BYREF
  char v10; // [sp+5Ah] [-16h]
  char v11; // [sp+5Bh] [-15h]
  char v12; // [sp+5Ch] [-14h]
  unsigned __int8 v13; // [sp+5Dh] [-13h]
  char v14; // [sp+5Eh] [-12h]

  month = mod_time->month;
  strcpy(v8, "tIME");
  if ( month <= 0xC
    && month != 0
    && (unsigned int)(day = mod_time->day) <= 0x1F
    && mod_time->day != 0
    && (unsigned int)(hour = mod_time->hour) <= 0x17
    && (unsigned int)(second = mod_time->second) <= 0x3C )
  {
    year = mod_time->year;
    minute = mod_time->minute;
    v10 = month;
    v11 = day;
    v9 = year;
    v13 = minute;
    v12 = hour;
    v14 = second;
    png_write_chunk(png_ptr, chunk_name: (unsigned __int8 *)v8, data: (unsigned __int8 *)&v9, length: 7u);
  }
  else
  {
    png_warning(png_ptr, warning_message: (png_struct_def *)"Invalid time specified for tIME chunk");
  }
}


// ========================================================================
// png_write_finish_row
// EA  : 0x8322FAA0
// RVA : 0x0122FAA0
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_finish_row(png_struct_def *png_ptr)
{
  unsigned int row_number; // r8
  unsigned int num_rows; // r6
  unsigned int transformations; // r11
  bool v5; // zf
  unsigned __int8 v6; // r10
  int v7; // r4
  unsigned int v8; // r7
  unsigned int v9; // r6
  unsigned int v10; // r10
  unsigned int v11; // r3
  unsigned int v12; // r10
  unsigned __int8 *prev_row; // r3
  unsigned int v14; // r11
  unsigned int width; // r10
  int v16; // r3
  unsigned int zbuf_size; // r10
  char *msg; // r4
  unsigned int avail_out; // r11
  unsigned int v20; // r10
  _DWORD v21[8]; // [sp+50h] [-B0h] BYREF
  _DWORD v22[8]; // [sp+70h] [-90h] BYREF
  _DWORD v23[8]; // [sp+90h] [-70h] BYREF
  _DWORD v24[20]; // [sp+B0h] [-50h] BYREF

  row_number = png_ptr->row_number;
  num_rows = png_ptr->num_rows;
  v23[0] = 0;
  v23[1] = 4;
  v23[2] = 0;
  ++row_number;
  v23[3] = 2;
  v23[4] = 0;
  v23[5] = 1;
  v23[6] = 0;
  png_ptr->row_number = row_number;
  v21[0] = 8;
  v21[1] = 8;
  v21[2] = 4;
  v21[3] = 4;
  v21[4] = 2;
  v21[5] = 2;
  v21[6] = 1;
  v24[0] = 0;
  v24[1] = 0;
  v24[2] = 4;
  v24[3] = 0;
  v24[4] = 2;
  v24[5] = 0;
  v24[6] = 1;
  v22[0] = 8;
  v22[1] = 8;
  v22[2] = 8;
  v22[3] = 4;
  v22[4] = 4;
  v22[5] = 2;
  v22[6] = 2;
  if ( row_number >= num_rows )
  {
    if ( png_ptr->interlaced == 0 )
      goto LABEL_16;
    transformations = png_ptr->transformations;
    png_ptr->row_number = 0;
    v5 = (transformations & 2) == 0;
    LOBYTE(transformations) = png_ptr->pass;
    if ( v5 )
    {
      do
      {
        v6 = transformations + 1;
        png_ptr->pass = transformations + 1;
        if ( (unsigned __int8)(transformations + 1) >= 7u )
          break;
        v7 = __ROL4__(png_ptr->pass, 2);
        transformations = png_ptr->pass;
        v8 = *(_DWORD *)((char *)v21 + v7);
        v9 = *(_DWORD *)((char *)v21 + __ROL4__(v6, 2)) - *(_DWORD *)((char *)v23 + v7) + png_ptr->width - 1;
        v10 = *(_DWORD *)((char *)v22 + v7) - *(_DWORD *)((char *)v24 + v7) + png_ptr->height - 1;
        v11 = *(_DWORD *)((char *)v22 + __ROL4__(transformations, 2));
        __twllei(v8, 0);
        png_ptr->usr_width = v9 / v8;
        v12 = v10 / v11;
        __twllei(v11, 0);
        png_ptr->num_rows = v12;
      }
      while ( v9 / v8 == 0 || v12 == 0 );
    }
    else
    {
      png_ptr->pass = transformations + 1;
    }
    if ( png_ptr->pass < 7u )
    {
      prev_row = png_ptr->prev_row;
      if ( prev_row != nullptr )
      {
        v14 = png_ptr->usr_channels * png_ptr->usr_bit_depth;
        width = png_ptr->width;
        if ( v14 < 8 )
          memset(Dst: prev_row, Val: 0, Size: ((width * v14 + 7) >> 3) + 1);
        else
          memset(Dst: prev_row, Val: 0, Size: (v14 >> 3) * width + 1);
      }
    }
    else
    {
LABEL_16:
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = deflate(strm: &png_ptr->zstream, flush: 4u);
          if ( v16 != 0 )
            break;
          if ( png_ptr->zstream.avail_out == 0 )
          {
            png_write_IDAT(png_ptr, data: png_ptr->zbuf, length: png_ptr->zbuf_size);
            zbuf_size = png_ptr->zbuf_size;
            png_ptr->zstream.next_out = png_ptr->zbuf;
            png_ptr->zstream.avail_out = zbuf_size;
          }
        }
        if ( v16 == 1 )
          break;
        msg = png_ptr->zstream.msg;
        if ( msg != nullptr )
          png_error(png_ptr, error_message: msg);
        else
          png_error(png_ptr, error_message: "zlib error");
      }
      avail_out = png_ptr->zstream.avail_out;
      v20 = png_ptr->zbuf_size;
      if ( avail_out < v20 )
        png_write_IDAT(png_ptr, data: png_ptr->zbuf, length: v20 - avail_out);
      deflateReset(strm: &png_ptr->zstream);
      png_ptr->zstream.data_type = 0;
    }
  }
}


// ========================================================================
// png_write_filtered_row
// EA  : 0x8322FD58
// RVA : 0x0122FD58
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_filtered_row(png_struct_def *png_ptr, unsigned __int8 *filtered_row)
{
  unsigned int rowbytes; // r11
  z_stream_s *p_zstream; // r29
  char *msg; // r4
  unsigned int zbuf_size; // r10
  unsigned __int8 *prev_row; // r11
  unsigned __int8 *row_buf; // r10
  unsigned int flush_dist; // r11
  unsigned int v10; // r10

  rowbytes = png_ptr->row_info.rowbytes;
  p_zstream = &png_ptr->zstream;
  png_ptr->zstream.next_in = filtered_row;
  png_ptr->zstream.avail_in = rowbytes + 1;
  do
  {
    if ( deflate(strm: p_zstream, flush: 0) != 0 )
    {
      msg = png_ptr->zstream.msg;
      if ( msg == nullptr )
        msg = "zlib error";
      png_error(png_ptr, error_message: msg);
    }
    if ( png_ptr->zstream.avail_out == 0 )
    {
      png_write_IDAT(png_ptr, data: png_ptr->zbuf, length: png_ptr->zbuf_size);
      zbuf_size = png_ptr->zbuf_size;
      png_ptr->zstream.next_out = png_ptr->zbuf;
      png_ptr->zstream.avail_out = zbuf_size;
    }
  }
  while ( png_ptr->zstream.avail_in != 0 );
  prev_row = png_ptr->prev_row;
  if ( prev_row != nullptr )
  {
    row_buf = png_ptr->row_buf;
    png_ptr->row_buf = prev_row;
    png_ptr->prev_row = row_buf;
  }
  png_write_finish_row(png_ptr);
  flush_dist = png_ptr->flush_dist;
  v10 = png_ptr->flush_rows + 1;
  png_ptr->flush_rows = v10;
  if ( flush_dist != 0 && v10 >= flush_dist )
    png_write_flush(png_ptr);
}


// ========================================================================
// png_write_find_filter
// EA  : 0x8322FE38
// RVA : 0x0122FE38
// PDB : w:\tech5\libs\png\pngwutil.c
// ========================================================================

void __fastcall png_write_find_filter(png_struct_def *png_ptr, png_row_info_struct *row_info)
{
  int do_filter; // r10
  unsigned __int8 *row_buf; // r22
  unsigned int rowbytes; // r23
  unsigned __int8 *prev_row; // r28
  int num_prev_filters; // r20
  unsigned int v8; // r24
  unsigned __int8 *v9; // r29
  int v10; // r25
  int v11; // r27
  int v12; // r6
  int v13; // r7
  unsigned int v14; // r4
  unsigned int v15; // r8
  unsigned __int8 *v16; // r10
  unsigned int v17; // r9
  unsigned int v18; // r11
  unsigned int v19; // r11
  unsigned int v20; // r11
  unsigned int v21; // r9
  unsigned int v22; // r10
  int v23; // r8
  int v24; // r11
  int v25; // ctr
  int v26; // r5
  int v27; // r11
  unsigned int v28; // r10
  unsigned int v29; // r8
  unsigned __int8 *v30; // r10
  unsigned __int8 *v31; // r11
  int v32; // ctr
  int v33; // r9
  int v34; // r10
  unsigned int v35; // ctr
  unsigned int v36; // r3
  unsigned int v37; // r31
  unsigned int v38; // r9
  unsigned int v39; // r10
  int v40; // r8
  int v41; // r11
  int i; // ctr
  int v43; // r5
  int v44; // r11
  unsigned int v45; // r10
  int v46; // r6
  int v47; // r7
  unsigned int v48; // r9
  unsigned __int8 *v49; // r10
  unsigned __int8 *v50; // r11
  unsigned int v51; // r30
  unsigned int v52; // r8
  unsigned int v53; // r30
  unsigned int v54; // r8
  unsigned int v55; // r5
  unsigned int v56; // r8
  unsigned int v57; // r8
  int v58; // r7
  int v59; // r6
  int v60; // r10
  unsigned int v61; // r9
  unsigned int v62; // r10
  int v63; // r8
  int v64; // r11
  int j; // ctr
  int v66; // r5
  int v67; // r11
  unsigned int v68; // r10
  int v69; // r10
  unsigned int v70; // ctr
  unsigned __int8 *up_row; // r9
  unsigned __int8 *v72; // r11
  unsigned __int8 v73; // r6
  unsigned int v74; // r5
  unsigned int v75; // r6
  unsigned int v76; // r9
  unsigned int v77; // r10
  int v78; // r8
  int v79; // r11
  int k; // ctr
  int v81; // r4
  int v82; // r11
  unsigned int v83; // r10
  _BYTE *v84; // r10
  unsigned int v85; // r7
  unsigned __int8 *v86; // r9
  int v87; // r11
  unsigned int v88; // r9
  unsigned int v89; // r10
  int v90; // r8
  int v91; // r11
  int m; // ctr
  int v93; // r5
  int v94; // r11
  unsigned int v95; // r10
  unsigned int v96; // r7
  _BYTE *v97; // r10
  unsigned __int8 *v98; // r11
  unsigned __int8 *v99; // r9
  int v100; // ctr
  int v101; // r8
  int v102; // r7
  int v103; // r6
  unsigned int v104; // ctr
  int v105; // r31
  unsigned int v106; // r30
  unsigned int v107; // r9
  unsigned int v108; // r10
  int v109; // r8
  int v110; // r11
  int n; // ctr
  int v112; // r5
  int v113; // r11
  unsigned int v114; // r10
  int v115; // r5
  int v116; // r6
  unsigned int v117; // r7
  _BYTE *v118; // r10
  unsigned __int8 *v119; // r11
  unsigned __int8 *v120; // r9
  int v121; // r8
  int v122; // r8
  int v123; // r8
  unsigned int v124; // r8
  int v125; // r6
  int v126; // r5
  int v127; // r4
  int v128; // r10
  unsigned int v129; // r9
  unsigned int v130; // r10
  int v131; // r8
  int v132; // r11
  int ii; // ctr
  int v134; // r5
  int v135; // r11
  unsigned int v136; // r10
  unsigned __int8 *v137; // r9
  unsigned int v138; // r8
  _BYTE *v139; // r4
  _BYTE *v140; // r11
  unsigned __int8 *v141; // r10
  int v142; // ctr
  int v143; // r3
  int v144; // r30
  unsigned int v145; // ctr
  int v146; // r8
  int v147; // r6
  int v148; // r7
  signed int v149; // r11
  signed int v150; // r10
  signed int v151; // r5
  int v152; // r3
  unsigned int v153; // r27
  unsigned int v154; // r9
  unsigned int v155; // r10
  int v156; // r8
  int v157; // r11
  int jj; // ctr
  int v159; // r5
  int v160; // r11
  unsigned int v161; // r10
  unsigned __int8 *v162; // r9
  int v163; // r6
  int v164; // r7
  unsigned int v165; // r29
  _BYTE *v166; // r5
  unsigned __int8 *v167; // r11
  _BYTE *v168; // r10
  int v169; // r8
  int v170; // r8
  int v171; // r8
  unsigned int v172; // r30
  int v173; // r3
  int v174; // r31
  int v175; // r28
  int v176; // r8
  int v177; // r6
  int v178; // r7
  signed int v179; // r10
  signed int v180; // r11
  signed int v181; // r4
  int v182; // r11
  unsigned int v183; // r9
  unsigned int v184; // r10
  int v185; // r8
  int v186; // r11
  int kk; // ctr
  int v188; // r5
  int v189; // r11
  unsigned int v190; // r10
  int v191; // r11
  int v192; // ctr
  unsigned __int8 *v193; // r10

  do_filter = png_ptr->do_filter;
  row_buf = png_ptr->row_buf;
  rowbytes = row_info->rowbytes;
  prev_row = png_ptr->prev_row;
  num_prev_filters = png_ptr->num_prev_filters;
  v8 = 0x7FFFFFFF;
  v9 = row_buf;
  v10 = (row_info->pixel_depth + 7) >> 3;
  v11 = do_filter;
  if ( (do_filter & 8) != 0 && do_filter != 8 )
  {
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    v16 = row_buf + 1;
    if ( (int)rowbytes >= 2 )
    {
      do
      {
        v17 = *v16;
        if ( v17 >= 0x80 )
          v17 = 256 - v17;
        v18 = v16[1];
        v12 += v17;
        if ( v18 >= 0x80 )
          v18 = 256 - v18;
        v15 += 2;
        v13 += v18;
        v16 += 2;
      }
      while ( v15 < rowbytes - 1 );
    }
    if ( v15 < rowbytes )
    {
      v19 = *v16;
      if ( v19 >= 0x80 )
        v19 = 256 - v19;
      v14 = v19;
    }
    v20 = v12 + v13 + v14;
    if ( png_ptr->heuristic_method == 2 )
    {
      v21 = (unsigned __int16)(v12 + v13 + v14);
      v22 = (v20 >> 10) & 0x3FFFC0;
      v23 = 0;
      if ( png_ptr->num_prev_filters != 0 )
      {
        v24 = 0;
        v25 = png_ptr->num_prev_filters;
        do
        {
          if ( png_ptr->prev_filters[v23] == 0 )
          {
            v26 = png_ptr->filter_weights[v24];
            v21 = (v26 * v21) >> 8;
            v22 = (v26 * v22) >> 8;
          }
          ++v23;
          ++v24;
          --v25;
        }
        while ( v25 != 0 );
      }
      v27 = *png_ptr->filter_costs;
      v28 = (v27 * v22) >> 3;
      if ( v28 <= 0x3FFFC0 )
        v20 = ((v27 * v21) >> 3) + (v28 << 10);
      else
        v20 = 0x7FFFFFFF;
    }
    v8 = v20;
  }
  if ( v11 == 16 )
  {
    v29 = 0;
    v30 = row_buf + 1;
    v31 = png_ptr->sub_row + 1;
    if ( v10 != 0 )
    {
      v32 = v10;
      v29 = v10;
      do
      {
        *v31++ = *v30++;
        --v32;
      }
      while ( v32 != 0 );
    }
    if ( v29 < rowbytes )
    {
      v33 = row_buf + 1 - v31;
      v34 = v30 - v31;
      v35 = rowbytes - v29;
      do
      {
        *v31 = v31[v34] - v31[v33];
        ++v31;
        --v35;
      }
      while ( v35 != 0 );
    }
    goto LABEL_68;
  }
  if ( (v11 & 0x10) != 0 )
  {
    v36 = 0;
    v37 = v8;
    if ( png_ptr->heuristic_method == 2 )
    {
      v38 = (unsigned __int16)v8;
      v39 = (v8 >> 10) & 0x3FFFC0;
      v40 = 0;
      if ( num_prev_filters > 0 )
      {
        v41 = 0;
        for ( i = num_prev_filters; i != 0; --i )
        {
          if ( png_ptr->prev_filters[v40] == 1 )
          {
            v43 = png_ptr->inv_filter_weights[v41];
            v38 = (v43 * v38) >> 8;
            v39 = (v43 * v39) >> 8;
          }
          ++v40;
          ++v41;
        }
      }
      v44 = png_ptr->inv_filter_costs[1];
      v45 = (v44 * v39) >> 3;
      if ( v45 <= 0x3FFFC0 )
        v37 = ((v44 * v38) >> 3) + (v45 << 10);
      else
        v37 = 0x7FFFFFFF;
    }
    v46 = 0;
    v47 = 0;
    v48 = 0;
    v49 = row_buf + 1;
    v50 = png_ptr->sub_row + 1;
    if ( v10 >= 2 )
    {
      do
      {
        v51 = *v49;
        v52 = v51;
        *v50 = v51;
        if ( v51 >= 0x80 )
          v52 = 256 - v51;
        v53 = v49[1];
        v46 += v52;
        v54 = v53;
        v50[1] = v53;
        if ( v53 >= 0x80 )
          v54 = 256 - v53;
        v48 += 2;
        v47 += v54;
        v49 += 2;
        v50 += 2;
      }
      while ( v48 < v10 - 1 );
    }
    if ( v48 < v10 )
    {
      v55 = *v49;
      v56 = v55;
      *v50 = v55;
      if ( v55 >= 0x80 )
        v56 = 256 - v55;
      v36 = v56;
      ++v49;
      ++v50;
      ++v48;
    }
    v57 = v46 + v47 + v36;
    if ( v48 < rowbytes )
    {
      v58 = row_buf + 1 - v50;
      v59 = v49 - v50;
      do
      {
        v60 = (unsigned __int8)(v50[v59] - v50[v58]);
        *v50 = v60;
        if ( v60 >= 128 )
          v60 = 256 - v60;
        v57 += v60;
        if ( v57 > v37 )
          break;
        ++v48;
        ++v50;
      }
      while ( v48 < rowbytes );
    }
    if ( png_ptr->heuristic_method == 2 )
    {
      v61 = (unsigned __int16)v57;
      v62 = (v57 >> 10) & 0x3FFFC0;
      v63 = 0;
      if ( num_prev_filters > 0 )
      {
        v64 = 0;
        for ( j = num_prev_filters; j != 0; --j )
        {
          if ( png_ptr->prev_filters[v63] == 1 )
          {
            v66 = png_ptr->inv_filter_weights[v64];
            v61 = (v61 * v66) >> 8;
            v62 = (v62 * v66) >> 8;
          }
          ++v63;
          ++v64;
        }
      }
      v67 = png_ptr->inv_filter_costs[1];
      v68 = (v67 * v62) >> 3;
      if ( v68 <= 0x3FFFC0 )
        v57 = ((v67 * v61) >> 3) + (v68 << 10);
      else
        v57 = 0x7FFFFFFF;
    }
    if ( v57 < v8 )
    {
      v8 = v57;
LABEL_68:
      row_buf = png_ptr->sub_row;
    }
  }
  if ( v11 == 32 )
  {
    v69 = 0;
    if ( rowbytes != 0 )
    {
      v70 = rowbytes;
      up_row = png_ptr->up_row;
      v72 = prev_row;
      do
      {
        ++v72;
        v73 = v9[++v69];
        *++up_row = v73 - *v72;
        --v70;
      }
      while ( v70 != 0 );
    }
    goto LABEL_101;
  }
  if ( (v11 & 0x20) != 0 )
  {
    v74 = 0;
    v75 = v8;
    if ( png_ptr->heuristic_method == 2 )
    {
      v76 = (unsigned __int16)v8;
      v77 = (v8 >> 10) & 0x3FFFC0;
      v78 = 0;
      if ( num_prev_filters > 0 )
      {
        v79 = 0;
        for ( k = num_prev_filters; k != 0; --k )
        {
          if ( png_ptr->prev_filters[v78] == 2 )
          {
            v81 = png_ptr->inv_filter_weights[v79];
            v76 = (v76 * v81) >> 8;
            v77 = (v77 * v81) >> 8;
          }
          ++v78;
          ++v79;
        }
      }
      v82 = png_ptr->inv_filter_costs[2];
      v83 = (v82 * v77) >> 3;
      if ( v83 <= 0x3FFFC0 )
        v75 = ((v82 * v76) >> 3) + (v83 << 10);
      else
        v75 = 0x7FFFFFFF;
    }
    v84 = v9 + 1;
    v85 = 0;
    if ( rowbytes != 0 )
    {
      v86 = png_ptr->up_row;
      do
      {
        v87 = (unsigned __int8)(*v84 - v84[prev_row - v9]);
        ++v84;
        *++v86 = v87;
        if ( v87 >= 128 )
          v87 = 256 - v87;
        v74 += v87;
        if ( v74 > v75 )
          break;
        ++v85;
      }
      while ( v85 < rowbytes );
    }
    if ( png_ptr->heuristic_method == 2 )
    {
      v88 = (unsigned __int16)v74;
      v89 = (v74 >> 10) & 0x3FFFC0;
      v90 = 0;
      if ( num_prev_filters > 0 )
      {
        v91 = 0;
        for ( m = num_prev_filters; m != 0; --m )
        {
          if ( png_ptr->prev_filters[v90] == 2 )
          {
            v93 = png_ptr->filter_weights[v91];
            v88 = (v93 * v88) >> 8;
            v89 = (v93 * v89) >> 8;
          }
          ++v90;
          ++v91;
        }
      }
      v94 = png_ptr->filter_costs[2];
      v95 = (v94 * v89) >> 3;
      if ( v95 <= 0x3FFFC0 )
        v74 = ((v94 * v88) >> 3) + (v95 << 10);
      else
        v74 = 0x7FFFFFFF;
    }
    if ( v74 < v8 )
    {
      v8 = v74;
LABEL_101:
      row_buf = png_ptr->up_row;
    }
  }
  if ( v11 == 64 )
  {
    v96 = 0;
    v97 = v9 + 1;
    v98 = prev_row + 1;
    v99 = png_ptr->avg_row + 1;
    if ( v10 != 0 )
    {
      v100 = v10;
      v96 = v10;
      do
      {
        *v99++ = *v97++ - (*v98++ >> 1);
        --v100;
      }
      while ( v100 != 0 );
    }
    if ( v96 < rowbytes )
    {
      v101 = v9 + 1 - v98;
      v103 = v99 - v98;
      v104 = rowbytes - v96;
      v102 = v97 - v98;
      do
      {
        v98[v103] = v98[v102] - ((v98[v101] + *v98) >> 1);
        ++v98;
        --v104;
      }
      while ( v104 != 0 );
    }
    goto LABEL_147;
  }
  if ( (v11 & 0x40) != 0 )
  {
    v105 = 0;
    v106 = v8;
    if ( png_ptr->heuristic_method == 2 )
    {
      v107 = (unsigned __int16)v8;
      v108 = (v8 >> 10) & 0x3FFFC0;
      v109 = 0;
      if ( num_prev_filters > 0 )
      {
        v110 = 0;
        for ( n = num_prev_filters; n != 0; --n )
        {
          if ( png_ptr->prev_filters[v109] == 3 )
          {
            v112 = png_ptr->inv_filter_weights[v110];
            v107 = (v112 * v107) >> 8;
            v108 = (v112 * v108) >> 8;
          }
          ++v109;
          ++v110;
        }
      }
      v113 = png_ptr->inv_filter_costs[3];
      v114 = (v113 * v108) >> 3;
      if ( v114 <= 0x3FFFC0 )
        v106 = ((v113 * v107) >> 3) + (v114 << 10);
      else
        v106 = 0x7FFFFFFF;
    }
    v115 = 0;
    v116 = 0;
    v117 = 0;
    v118 = v9 + 1;
    v119 = prev_row + 1;
    v120 = png_ptr->avg_row + 1;
    if ( v10 >= 2 )
    {
      do
      {
        v121 = (unsigned __int8)(*v118 - (*v119 >> 1));
        *v120 = *v118 - (*v119 >> 1);
        if ( v121 >= 128 )
          v121 = 256 - v121;
        v115 += v121;
        v122 = (unsigned __int8)(v118[1] - (v119[1] >> 1));
        v120[1] = v118[1] - (v119[1] >> 1);
        if ( v122 >= 128 )
          v122 = 256 - v122;
        v117 += 2;
        v116 += v122;
        v118 += 2;
        v120 += 2;
        v119 += 2;
      }
      while ( v117 < v10 - 1 );
    }
    if ( v117 < v10 )
    {
      v123 = (unsigned __int8)(*v118 - (*v119 >> 1));
      *v120 = *v118 - (*v119 >> 1);
      if ( v123 >= 128 )
        v123 = 256 - v123;
      v105 = v123;
      ++v118;
      ++v120;
      ++v119;
      ++v117;
    }
    v124 = v115 + v116 + v105;
    if ( v117 < rowbytes )
    {
      v125 = v9 + 1 - v119;
      v126 = v118 - v119;
      v127 = v120 - v119;
      do
      {
        v128 = (unsigned __int8)(v119[v126] - ((v119[v125] + *v119) >> 1));
        (v119++)[v127] = v128;
        if ( v128 >= 128 )
          v128 = 256 - v128;
        v124 += v128;
        if ( v124 > v106 )
          break;
        ++v117;
      }
      while ( v117 < rowbytes );
    }
    if ( png_ptr->heuristic_method == 2 )
    {
      v129 = (unsigned __int16)v124;
      v130 = (v124 >> 10) & 0x3FFFC0;
      v131 = 0;
      if ( num_prev_filters > 0 )
      {
        v132 = 0;
        for ( ii = num_prev_filters; ii != 0; --ii )
        {
          if ( png_ptr->prev_filters[v131] == 0 )
          {
            v134 = png_ptr->filter_weights[v132];
            v129 = (v134 * v129) >> 8;
            v130 = (v134 * v130) >> 8;
          }
          ++v131;
          ++v132;
        }
      }
      v135 = png_ptr->filter_costs[3];
      v136 = (v130 * v135) >> 3;
      if ( v136 <= 0x3FFFC0 )
        v124 = ((v129 * v135) >> 3) + (v136 << 10);
      else
        v124 = 0x7FFFFFFF;
    }
    if ( v124 < v8 )
    {
      v8 = v124;
LABEL_147:
      row_buf = png_ptr->avg_row;
    }
  }
  if ( v11 == 128 )
  {
    v137 = v9 + 1;
    v138 = 0;
    v139 = v9 + 1;
    v140 = prev_row + 1;
    v141 = png_ptr->paeth_row + 1;
    if ( v10 != 0 )
    {
      v142 = v10;
      v138 = v10;
      do
      {
        *v141++ = *v139++ - *v140++;
        --v142;
      }
      while ( v142 != 0 );
    }
    if ( v138 < rowbytes )
    {
      v143 = v140 - v137;
      v144 = v141 - v139;
      v145 = rowbytes - v138;
      do
      {
        v146 = v137[prev_row - v9];
        v147 = v137[v143];
        v148 = *v137++;
        v149 = abs32(v147 - v146);
        v150 = abs32(v148 - v146);
        v151 = abs32(v148 - v146 + v147 - v146);
        if ( v149 > v150 || v149 > v151 )
        {
          if ( v150 <= v151 )
            LOBYTE(v146) = v147;
        }
        else
        {
          LOBYTE(v146) = v148;
        }
        v139[v144] = *v139 - v146;
        ++v139;
        --v145;
      }
      while ( v145 != 0 );
    }
LABEL_202:
    row_buf = png_ptr->paeth_row;
    goto LABEL_203;
  }
  if ( (v11 & 0x80) != 0 )
  {
    v152 = 0;
    v153 = v8;
    if ( png_ptr->heuristic_method == 2 )
    {
      v154 = (unsigned __int16)v8;
      v155 = (v8 >> 10) & 0x3FFFC0;
      v156 = 0;
      if ( num_prev_filters > 0 )
      {
        v157 = 0;
        for ( jj = num_prev_filters; jj != 0; --jj )
        {
          if ( png_ptr->prev_filters[v156] == 4 )
          {
            v159 = png_ptr->inv_filter_weights[v157];
            v154 = (v159 * v154) >> 8;
            v155 = (v159 * v155) >> 8;
          }
          ++v156;
          ++v157;
        }
      }
      v160 = png_ptr->inv_filter_costs[4];
      v161 = (v155 * v160) >> 3;
      if ( v161 <= 0x3FFFC0 )
        v153 = ((v154 * v160) >> 3) + (v161 << 10);
      else
        v153 = 0x7FFFFFFF;
    }
    v162 = v9 + 1;
    v163 = 0;
    v164 = 0;
    v166 = v9 + 1;
    v165 = 0;
    v167 = png_ptr->paeth_row + 1;
    v168 = prev_row + 1;
    if ( v10 >= 2 )
    {
      do
      {
        v169 = (unsigned __int8)(*v166 - *v168);
        *v167 = v169;
        if ( v169 >= 128 )
          v169 = 256 - v169;
        v163 += v169;
        v170 = (unsigned __int8)(v166[1] - v168[1]);
        v167[1] = v170;
        if ( v170 >= 128 )
          v170 = 256 - v170;
        v165 += 2;
        v164 += v170;
        v166 += 2;
        v167 += 2;
        v168 += 2;
      }
      while ( v165 < v10 - 1 );
    }
    if ( v165 < v10 )
    {
      v171 = (unsigned __int8)(*v166 - *v168);
      *v167 = v171;
      if ( v171 >= 128 )
        v171 = 256 - v171;
      v152 = v171;
      ++v166;
      ++v167;
      ++v168;
      ++v165;
    }
    v172 = v163 + v164 + v152;
    if ( v165 < rowbytes )
    {
      v173 = v168 - v162;
      v174 = prev_row + 1 - v162;
      v175 = v167 - v166;
      do
      {
        v176 = v162[v174];
        v177 = v162[v173];
        v178 = *v162++;
        v179 = abs32(v178 - v176);
        v180 = abs32(v177 - v176);
        v181 = abs32(v178 - v176 + v177 - v176);
        if ( v180 > v179 || v180 > v181 )
        {
          if ( v179 <= v181 )
            LOBYTE(v176) = v177;
        }
        else
        {
          LOBYTE(v176) = v178;
        }
        v182 = (unsigned __int8)(*v166 - v176);
        (v166++)[v175] = v182;
        if ( v182 >= 128 )
          v182 = 256 - v182;
        v172 += v182;
        if ( v172 > v153 )
          break;
        ++v165;
      }
      while ( v165 < rowbytes );
    }
    if ( png_ptr->heuristic_method == 2 )
    {
      v183 = (unsigned __int16)v172;
      v184 = (v172 >> 10) & 0x3FFFC0;
      v185 = 0;
      if ( num_prev_filters > 0 )
      {
        v186 = 0;
        for ( kk = num_prev_filters; kk != 0; --kk )
        {
          if ( png_ptr->prev_filters[v185] == 4 )
          {
            v188 = png_ptr->filter_weights[v186];
            v183 = (v183 * v188) >> 8;
            v184 = (v184 * v188) >> 8;
          }
          ++v185;
          ++v186;
        }
      }
      v189 = png_ptr->filter_costs[4];
      v190 = (v184 * v189) >> 3;
      if ( v190 <= 0x3FFFC0 )
        v172 = ((v183 * v189) >> 3) + (v190 << 10);
      else
        v172 = 0x7FFFFFFF;
    }
    if ( v172 < v8 )
      goto LABEL_202;
  }
LABEL_203:
  png_write_filtered_row(png_ptr, filtered_row: row_buf);
  if ( png_ptr->num_prev_filters != 0 )
  {
    v191 = 1;
    if ( num_prev_filters > 1 )
    {
      v192 = num_prev_filters - 1;
      do
      {
        v193 = &png_ptr->prev_filters[v191++];
        *v193 = *(v193 - 1);
        --v192;
      }
      while ( v192 != 0 );
    }
    png_ptr->prev_filters[v191] = *row_buf;
  }
}

