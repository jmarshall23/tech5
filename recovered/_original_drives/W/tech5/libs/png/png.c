
// ========================================================================
// png_set_sig_bytes
// EA  : 0x83214678
// RVA : 0x01214678
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

void __fastcall png_set_sig_bytes(png_struct_def *png_ptr, int num_bytes)
{
  if ( png_ptr != nullptr )
  {
    if ( num_bytes > 8 )
      png_error(png_ptr, error_message: "Too many bytes for PNG signature.");
    png_ptr->sig_bytes = num_bytes < 0 ? 0 : num_bytes;
  }
}


// ========================================================================
// png_sig_cmp
// EA  : 0x832146D8
// RVA : 0x012146D8
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

int __fastcall png_sig_cmp(unsigned __int8 *sig, unsigned int start, unsigned int num_to_check)
{
  char *v3; // r10
  unsigned __int8 *v4; // r11
  int result; // r3
  unsigned __int8 *v6; // r9
  int v7; // r8
  int v8; // r7
  char back_chain; // [sp+0h] [-10h] BYREF

  if ( num_to_check <= 8 )
  {
    if ( num_to_check == 0 )
      return -1;
  }
  else
  {
    num_to_check = 8;
  }
  if ( start > 7 )
    return -1;
  if ( start + num_to_check > 8 )
    num_to_check = 8 - start;
  v3 = &back_chain + start;
  v4 = &sig[start];
  result = 0;
  if ( num_to_check != 0 )
  {
    v6 = &v4[num_to_check];
    do
    {
      v7 = *v4;
      v8 = (unsigned __int8)*v3;
      result = v7 - v8;
      if ( v7 != v8 )
        break;
      ++v4;
      ++v3;
    }
    while ( v4 != v6 );
  }
  return result;
}


// ========================================================================
// png_zalloc
// EA  : 0x83214788
// RVA : 0x01214788
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

void *__fastcall png_zalloc(png_struct_def *png_ptr, unsigned int items, unsigned int size)
{
  unsigned int flags; // r30
  void *result; // r3

  flags = png_ptr->flags;
  __twllei(size, 0);
  if ( items <= 0xFFFFFFFF / size )
  {
    png_ptr->flags = flags | 0x100000;
    result = png_malloc(png_ptr, size: items * size);
    png_ptr->flags = flags;
  }
  else
  {
    png_warning(png_ptr, warning_message: "Potential overflow in png_zalloc()");
    return nullptr;
  }
  return result;
}


// ========================================================================
// png_zfree
// EA  : 0x832147F8
// RVA : 0x012147F8
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

// attributes: thunk
void __fastcall png_zfree(png_struct_def *png_ptr, void *ptr)
{
  png_free(png_ptr, ptr);
}


// ========================================================================
// png_reset_crc
// EA  : 0x83214800
// RVA : 0x01214800
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

void __fastcall png_reset_crc(png_struct_def *png_ptr)
{
  png_ptr->crc = crc32(crc: 0, buf: nullptr, len: 0);
}


// ========================================================================
// png_calculate_crc
// EA  : 0x83214840
// RVA : 0x01214840
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

void __fastcall png_calculate_crc(png_struct_def *png_ptr, unsigned __int8 *ptr, unsigned int length)
{
  if ( (png_ptr->chunk_name[0] & 0x20) == 0 )
  {
    if ( (png_ptr->flags & 0x800) != 0 )
      return;
    goto LABEL_5;
  }
  if ( (png_ptr->flags & 0x300) != 0x300 )
LABEL_5:
    png_ptr->crc = crc32(crc: png_ptr->crc, buf: ptr, len: length);
}


// ========================================================================
// png_free_data
// EA  : 0x832148B8
// RVA : 0x012148B8
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

void __fastcall png_free_data(png_struct_def *png_ptr, png_info_struct *info_ptr, unsigned int mask, int num)
{
  png_text_struct *text; // r11
  int v9; // r29
  char *key; // r4
  int i; // r29
  unsigned int valid; // r11
  unsigned int v13; // r11
  char **pcal_params; // r11
  int v15; // r27
  int v16; // r29
  unsigned int v17; // r11
  png_sPLT_struct *splt_palettes; // r11
  int v19; // r29
  signed int splt_palettes_num; // r11
  int v21; // r29
  unsigned __int8 *data; // r4
  png_unknown_chunk_t *unknown_chunks; // r10
  signed int unknown_chunks_num; // r11
  int v25; // r29
  unsigned int v26; // r11
  unsigned int v27; // r11
  signed int v28; // r27
  int v29; // r29
  unsigned int free_me; // r11

  if ( png_ptr != nullptr && info_ptr != nullptr )
  {
    if ( (info_ptr->free_me & mask & 0x4000) != 0 )
    {
      if ( num == -1 )
      {
        for ( i = 0; i < info_ptr->num_text; ++i )
          png_free_data(png_ptr, info_ptr, mask: 0x4000u, num: i);
        png_free(png_ptr, ptr: info_ptr->text);
        info_ptr->text = nullptr;
        info_ptr->num_text = 0;
      }
      else
      {
        text = info_ptr->text;
        if ( text != nullptr )
        {
          v9 = num;
          key = text[num].key;
          if ( key != nullptr )
          {
            png_free(png_ptr, ptr: key);
            info_ptr->text[v9].key = nullptr;
          }
        }
      }
    }
    if ( (info_ptr->free_me & mask & 0x2000) != 0 )
    {
      png_free(png_ptr, ptr: info_ptr->trans);
      valid = info_ptr->valid;
      info_ptr->trans = nullptr;
      info_ptr->valid = valid & 0xFFFFFFEF;
    }
    v13 = info_ptr->free_me & mask;
    if ( (v13 & 0x100) != 0 )
      info_ptr->valid &= ~0x4000u;
    if ( (v13 & 0x80) != 0 )
    {
      png_free(png_ptr, ptr: info_ptr->pcal_purpose);
      png_free(png_ptr, ptr: info_ptr->pcal_units);
      pcal_params = info_ptr->pcal_params;
      info_ptr->pcal_purpose = nullptr;
      info_ptr->pcal_units = nullptr;
      if ( pcal_params != nullptr )
      {
        v15 = 0;
        if ( info_ptr->pcal_nparams != 0 )
        {
          v16 = 0;
          do
          {
            png_free(png_ptr, ptr: info_ptr->pcal_params[v16]);
            ++v15;
            info_ptr->pcal_params[v16++] = nullptr;
          }
          while ( v15 < info_ptr->pcal_nparams );
        }
        png_free(png_ptr, ptr: info_ptr->pcal_params);
        info_ptr->pcal_params = nullptr;
      }
      info_ptr->valid &= ~0x400u;
    }
    if ( (info_ptr->free_me & mask & 0x10) != 0 )
    {
      png_free(png_ptr, ptr: info_ptr->iccp_name);
      png_free(png_ptr, ptr: info_ptr->iccp_profile);
      v17 = info_ptr->valid;
      info_ptr->iccp_name = nullptr;
      info_ptr->iccp_profile = nullptr;
      info_ptr->valid = v17 & 0xFFFFEFFF;
    }
    if ( (info_ptr->free_me & mask & 0x20) != 0 )
    {
      if ( num == -1 )
      {
        splt_palettes_num = info_ptr->splt_palettes_num;
        if ( splt_palettes_num != 0 )
        {
          v21 = 0;
          if ( splt_palettes_num > 0 )
          {
            do
              png_free_data(png_ptr, info_ptr, mask: 0x20u, num: v21++);
            while ( v21 < (signed int)info_ptr->splt_palettes_num );
          }
          png_free(png_ptr, ptr: info_ptr->splt_palettes);
          info_ptr->splt_palettes = nullptr;
          info_ptr->splt_palettes_num = 0;
        }
        info_ptr->valid &= ~0x2000u;
      }
      else
      {
        splt_palettes = info_ptr->splt_palettes;
        if ( splt_palettes != nullptr )
        {
          v19 = num;
          png_free(png_ptr, ptr: splt_palettes[num].name);
          png_free(png_ptr, ptr: info_ptr->splt_palettes[num].entries);
          info_ptr->splt_palettes[v19].name = nullptr;
          info_ptr->splt_palettes[v19].entries = nullptr;
        }
      }
    }
    data = png_ptr->unknown_chunk.data;
    if ( data != nullptr )
    {
      png_free(png_ptr, ptr: data);
      png_ptr->unknown_chunk.data = nullptr;
    }
    if ( (info_ptr->free_me & mask & 0x200) != 0 )
    {
      if ( num == -1 )
      {
        unknown_chunks_num = info_ptr->unknown_chunks_num;
        if ( unknown_chunks_num != 0 )
        {
          v25 = 0;
          if ( unknown_chunks_num > 0 )
          {
            do
              png_free_data(png_ptr, info_ptr, mask: 0x200u, num: v25++);
            while ( v25 < (signed int)info_ptr->unknown_chunks_num );
          }
          png_free(png_ptr, ptr: info_ptr->unknown_chunks);
          info_ptr->unknown_chunks = nullptr;
          info_ptr->unknown_chunks_num = 0;
        }
      }
      else
      {
        unknown_chunks = info_ptr->unknown_chunks;
        if ( unknown_chunks != nullptr )
        {
          png_free(png_ptr, ptr: unknown_chunks[num].data);
          info_ptr->unknown_chunks[num].data = nullptr;
        }
      }
    }
    if ( (info_ptr->free_me & mask & 8) != 0 )
    {
      png_free(png_ptr, ptr: info_ptr->hist);
      v26 = info_ptr->valid;
      info_ptr->hist = nullptr;
      info_ptr->valid = v26 & 0xFFFFFFBF;
    }
    if ( (info_ptr->free_me & mask & 0x1000) != 0 )
    {
      png_free(png_ptr, ptr: info_ptr->palette);
      v27 = info_ptr->valid;
      info_ptr->palette = nullptr;
      info_ptr->num_palette = 0;
      info_ptr->valid = v27 & 0xFFFFFFF7;
    }
    if ( (info_ptr->free_me & mask & 0x40) != 0 )
    {
      if ( DWORD2(info_ptr->scal_pixel_height) != 0 )
      {
        v28 = 0;
        if ( (int)info_ptr->height > 0 )
        {
          v29 = 0;
          do
          {
            png_free(png_ptr, ptr: *(void **)(v29 + DWORD2(info_ptr->scal_pixel_height)));
            ++v28;
            *(_DWORD *)(v29 + DWORD2(info_ptr->scal_pixel_height)) = 0;
            v29 += 4;
          }
          while ( v28 < (signed int)info_ptr->height );
        }
        png_free(png_ptr, ptr: (void *)DWORD2(info_ptr->scal_pixel_height));
        DWORD2(info_ptr->scal_pixel_height) = 0;
      }
      info_ptr->valid &= ~0x8000u;
    }
    free_me = info_ptr->free_me;
    if ( num == -1 )
      info_ptr->free_me = free_me & ~mask;
    else
      info_ptr->free_me = free_me & ~(mask & 0xFFFFBDDF);
  }
}


// ========================================================================
// png_info_destroy
// EA  : 0x83214D38
// RVA : 0x01214D38
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

void __fastcall png_info_destroy(png_struct_def *png_ptr, png_info_struct *info_ptr)
{
  png_free_data(png_ptr, info_ptr, mask: 0x7FFFu, num: -1);
  if ( png_ptr->num_chunk_list != 0 )
  {
    png_free(png_ptr, ptr: png_ptr->chunk_list);
    png_ptr->chunk_list = nullptr;
    png_ptr->num_chunk_list = 0;
  }
  if ( info_ptr != nullptr )
    memset(Dst: info_ptr, Val: 0, Size: 0x120u);
}


// ========================================================================
// png_get_io_ptr
// EA  : 0x83214DB8
// RVA : 0x01214DB8
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

_DWORD *__fastcall png_get_io_ptr(_DWORD *png_ptr)
{
  if ( png_ptr != nullptr )
    return (_DWORD *)png_ptr[341];
  return png_ptr;
}


// ========================================================================
// png_get_header_ver
// EA  : 0x83214DD0
// RVA : 0x01214DD0
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

char *__fastcall png_get_header_ver(png_struct_def *png_ptr)
{
  return "1.2.29";
}


// ========================================================================
// png_handle_as_unknown
// EA  : 0x83214DE0
// RVA : 0x01214DE0
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

int __fastcall png_handle_as_unknown(png_struct_def *png_ptr, unsigned __int8 *chunk_name)
{
  int num_chunk_list; // r11
  int v3; // ctr
  unsigned __int8 *i; // r7
  unsigned __int8 *v5; // r10
  unsigned __int8 *v6; // r11
  int v7; // r6
  int v8; // r9

  if ( png_ptr == nullptr )
    return 0;
  if ( chunk_name == nullptr )
    return 0;
  num_chunk_list = png_ptr->num_chunk_list;
  if ( num_chunk_list <= 0 )
    return 0;
  v3 = png_ptr->num_chunk_list;
  for ( i = &png_ptr->chunk_list[5 * num_chunk_list - 5]; ; i -= 5 )
  {
    v5 = i;
    v6 = chunk_name;
    do
    {
      v7 = *v5;
      v8 = *v6 - v7;
      if ( *v6 != v7 )
        break;
      ++v6;
      ++v5;
    }
    while ( v6 != chunk_name + 4 );
    if ( v8 == 0 )
      break;
    if ( --v3 == 0 )
      return 0;
  }
  return i[4];
}


// ========================================================================
// png_create_info_struct
// EA  : 0x83214E70
// RVA : 0x01214E70
// PDB : w:\tech5\libs\png\png.c
// ========================================================================

png_info_struct *__fastcall png_create_info_struct(png_info_struct *png_ptr)
{
  void *struct_2; // r3
  void *v2; // r31

  if ( png_ptr != nullptr )
  {
    struct_2 = png_create_struct_2(
                 type: 2,
                 malloc_fn: (void *(__fastcall *)(png_struct_def *, unsigned int))LODWORD(png_ptr[6].gamma),
                 mem_ptr: *(void **)&png_ptr[6].signature[4]);
    v2 = struct_2;
    if ( struct_2 != nullptr )
      memset(Dst: struct_2, Val: 0, Size: 0x120u);
    return (png_info_struct *)v2;
  }
  return png_ptr;
}

