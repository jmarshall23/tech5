
// ========================================================================
// alloc_small
// EA  : 0x83225E60
// RVA : 0x01225E60
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

int __fastcall alloc_small(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  jpeg_memory_mgr *mem; // r25
  unsigned int v6; // r26
  int v7; // r23
  _DWORD *v8; // r27
  _DWORD *i; // r11
  unsigned int v10; // r29
  const unsigned int *v11; // r9
  unsigned int v12; // r31
  int v13; // r10
  unsigned int v14; // r6

  mem = cinfo->mem;
  v6 = sizeofobject;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 1;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (v6 & 7) != 0 )
    v6 = v6 - (v6 & 7) + 8;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  v7 = 4 * (pool_id + 13);
  v8 = nullptr;
  i = *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v7);
  if ( i != nullptr )
  {
    while ( i[2] < v6 )
    {
      v8 = i;
      i = (_DWORD *)*i;
      if ( i == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v10 = v6 + 16;
    if ( v8 != nullptr )
      v11 = extra_pool_slop;
    else
      v11 = first_pool_slop;
    v12 = v11[pool_id];
    if ( v12 > 1000000000 - v10 )
      v12 = 1000000000 - v10;
    for ( i = jpeg_get_large(cinfo, sizeofobject: v12 + v10);
          i == nullptr;
          i = jpeg_get_large(cinfo, sizeofobject: v12 + v10) )
    {
      v12 >>= 1;
      if ( v12 < 0x32 )
      {
        cinfo->err->msg_code = 54;
        cinfo->err->msg_parm.i[0] = 2;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    mem[1].realize_virt_arrays = (void (__fastcall *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays
                                                                           + v12
                                                                           + v10);
    *i = 0;
    i[1] = 0;
    i[2] = v12 + v6;
    if ( v8 != nullptr )
      *v8 = i;
    else
      *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v7) = (void *(__fastcall *)(jpeg_common_struct *, int, unsigned int))i;
  }
  v13 = i[1];
  v14 = i[2] - v6;
  i[1] = v13 + v6;
  i[2] = v14;
  return (int)i + v13 + 16;
}


// ========================================================================
// alloc_large
// EA  : 0x83226038
// RVA : 0x01226038
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

_DWORD *__fastcall alloc_large(jpeg_common_struct *cinfo, unsigned int pool_id, unsigned int sizeofobject)
{
  jpeg_memory_mgr *mem; // r28
  int v6; // r29
  void *(__fastcall *large)(jpeg_common_struct *, int, unsigned int); // r31
  int v8; // r11
  int v10; // r6

  mem = cinfo->mem;
  v6 = sizeofobject;
  if ( sizeofobject > 0x3B9AC9F0 )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 3;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (v6 & 7) != 0 )
    v6 = v6 - (v6 & 7) + 8;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  large = (void *(__fastcall *)(jpeg_common_struct *, int, unsigned int))jpeg_get_large(cinfo, sizeofobject: v6 + 16);
  if ( large == nullptr )
  {
    cinfo->err->msg_code = 54;
    cinfo->err->msg_parm.i[0] = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  v8 = 4 * (pool_id + 15);
  mem[1].realize_virt_arrays = (void (__fastcall *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays + v6 + 16);
  v10 = *(int *)((char *)&mem->alloc_small + v8);
  *((_DWORD *)large + 1) = v6;
  *((_DWORD *)large + 2) = 0;
  *(_DWORD *)large = v10;
  *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v8) = large;
  return (_DWORD *)((char *)large + 16);
}


// ========================================================================
// alloc_sarray
// EA  : 0x83226158
// RVA : 0x01226158
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

unsigned __int8 **__fastcall alloc_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int samplesperrow,
        signed int numrows)
{
  jpeg_memory_mgr *mem; // r30
  unsigned int v9; // r31
  int v10; // r26
  unsigned int v11; // r30
  _DWORD *v12; // r3
  unsigned int v13; // ctr
  unsigned int v14; // r11
  _DWORD *v15; // r11

  mem = cinfo->mem;
  v9 = 0x3B9AC9F0 / samplesperrow;
  __twllei(samplesperrow, 0);
  if ( 0x3B9AC9F0 / samplesperrow == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v9 >= numrows )
    v9 = numrows;
  mem[1].access_virt_sarray = (unsigned __int8 **(__fastcall *)(jpeg_common_struct *, jvirt_sarray_control *, unsigned int, unsigned int, unsigned __int8))v9;
  v10 = alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v11 = 0;
  while ( v11 < numrows )
  {
    if ( v9 >= numrows - v11 )
      v9 = numrows - v11;
    v12 = alloc_large(cinfo, pool_id, sizeofobject: v9 * samplesperrow);
    if ( v9 != 0 )
    {
      v13 = v9;
      v14 = 4 * v11 + v10;
      v11 += v9;
      v15 = (_DWORD *)(v14 - 4);
      do
      {
        *++v15 = v12;
        v12 = (_DWORD *)((char *)v12 + samplesperrow);
        --v13;
      }
      while ( v13 != 0 );
    }
  }
  return (unsigned __int8 **)v10;
}


// ========================================================================
// alloc_barray
// EA  : 0x83226238
// RVA : 0x01226238
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

__int16 (**__fastcall alloc_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned int blocksperrow,
        signed int numrows))[64]
{
  jpeg_memory_mgr *mem; // r30
  unsigned int v5; // r25
  unsigned int v10; // r31
  int v11; // r27
  unsigned int v12; // r30
  _DWORD *v13; // r3
  unsigned int v14; // ctr
  unsigned int v15; // r11
  _DWORD *v16; // r11

  mem = cinfo->mem;
  v5 = blocksperrow << 7;
  v10 = 0x3B9AC9F0 / (blocksperrow << 7);
  __twllei(blocksperrow << 7, 0);
  if ( v10 == 0 )
  {
    cinfo->err->msg_code = 70;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( (int)v10 >= numrows )
    v10 = numrows;
  mem[1].access_virt_sarray = (unsigned __int8 **(__fastcall *)(jpeg_common_struct *, jvirt_sarray_control *, unsigned int, unsigned int, unsigned __int8))v10;
  v11 = alloc_small(cinfo, pool_id, sizeofobject: 4 * numrows);
  v12 = 0;
  while ( v12 < numrows )
  {
    if ( v10 >= numrows - v12 )
      v10 = numrows - v12;
    v13 = alloc_large(cinfo, pool_id, sizeofobject: (v10 * blocksperrow) << 7);
    if ( v10 != 0 )
    {
      v14 = v10;
      v15 = 4 * v12 + v11;
      v12 += v10;
      v16 = (_DWORD *)(v15 - 4);
      do
      {
        *++v16 = v13;
        v13 = (_DWORD *)((char *)v13 + v5);
        --v14;
      }
      while ( v14 != 0 );
    }
  }
  return (__int16 (**)[64])v11;
}


// ========================================================================
// request_virt_sarray
// EA  : 0x83226320
// RVA : 0x01226320
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

jvirt_sarray_control *__fastcall request_virt_sarray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int samplesperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // r30
  jvirt_sarray_control *result; // r3

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_sarray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->mem_buffer = nullptr;
  result->samplesperrow = samplesperrow;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_sarray_control *)mem[1].request_virt_sarray;
  mem[1].request_virt_sarray = (jvirt_sarray_control *(__fastcall *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}


// ========================================================================
// request_virt_barray
// EA  : 0x832263B8
// RVA : 0x012263B8
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

jvirt_barray_control *__fastcall request_virt_barray(
        jpeg_common_struct *cinfo,
        unsigned int pool_id,
        unsigned __int8 pre_zero,
        unsigned int blocksperrow,
        unsigned int numrows,
        unsigned int maxaccess)
{
  jpeg_memory_mgr *mem; // r30
  jvirt_barray_control *result; // r3

  mem = cinfo->mem;
  if ( pool_id != 1 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = (jvirt_barray_control *)alloc_small(cinfo, pool_id, sizeofobject: 0x78u);
  result->rows_in_array = numrows;
  result->mem_buffer = nullptr;
  result->blocksperrow = blocksperrow;
  result->maxaccess = maxaccess;
  result->pre_zero = pre_zero;
  result->b_s_open = 0;
  result->next = (jvirt_barray_control *)mem[1].request_virt_barray;
  mem[1].request_virt_barray = (jvirt_barray_control *(__fastcall *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))result;
  return result;
}


// ========================================================================
// realize_virt_arrays
// EA  : 0x83226450
// RVA : 0x01226450
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

void __fastcall realize_virt_arrays(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // r27
  int v3; // r31
  int v4; // r30
  jvirt_sarray_control *(__fastcall *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r11
  int v6; // r9
  jvirt_barray_control *(__fastcall *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r11
  int v8; // r10
  int TitleStorageString; // r3
  int v10; // r30
  jvirt_sarray_control *(__fastcall *k)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r31
  int v12; // r11
  unsigned int v13; // r10
  int v14; // r9
  jvirt_barray_control *(__fastcall *m)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r31
  int v16; // r11
  unsigned int v17; // r10
  int v18; // r9

  mem = cinfo->mem;
  v3 = 0;
  v4 = 0;
  for ( i = mem[1].request_virt_sarray;
        i != nullptr;
        i = *((jvirt_sarray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
            + 9) )
  {
    if ( *(_DWORD *)i == 0 )
    {
      v6 = *((_DWORD *)i + 2);
      v3 += *((_DWORD *)i + 3) * v6;
      v4 += *((_DWORD *)i + 1) * v6;
    }
  }
  for ( j = mem[1].request_virt_barray;
        j != nullptr;
        j = *((jvirt_barray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
            + 9) )
  {
    if ( *(_DWORD *)j == 0 )
    {
      v8 = *((_DWORD *)j + 2);
      v3 += (*((_DWORD *)j + 3) * v8) << 7;
      v4 += (*((_DWORD *)j + 1) * v8) << 7;
    }
  }
  if ( v3 > 0 )
  {
    TitleStorageString = idSession::GetTitleStorageString(
                           cinfo,
                           min_bytes_needed: v3,
                           max_bytes_needed: v4,
                           already_allocated: (int)mem[1].realize_virt_arrays);
    if ( TitleStorageString < v4 )
    {
      v10 = TitleStorageString / v3;
      __twllei(v3, 0);
      __twlgei(v3 & ~(__ROL4__(TitleStorageString, 1) - 1), 0xFFFFFFFF);
      if ( TitleStorageString / v3 <= 0 )
        v10 = 1;
    }
    else
    {
      v10 = 1000000000;
    }
    for ( k = mem[1].request_virt_sarray;
          k != nullptr;
          k = *((jvirt_sarray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))k
              + 9) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v12 = *((_DWORD *)k + 1);
        v13 = *((_DWORD *)k + 3);
        __twllei(v13, 0);
        if ( (int)((v12 - 1) / v13 + 1) > v10 )
        {
          v14 = *((_DWORD *)k + 2);
          *((_DWORD *)k + 4) = v13 * v10;
          jpeg_open_backing_store(cinfo, info: (backing_store_struct *)((char *)k + 40), total_bytes_needed: v14 * v12);
          *((_BYTE *)k + 34) = 1;
        }
        else
        {
          *((_DWORD *)k + 4) = v12;
        }
        *(_DWORD *)k = alloc_sarray(cinfo, pool_id: 1u, samplesperrow: *((_DWORD *)k + 2), numrows: *((_DWORD *)k + 4));
        *((_DWORD *)k + 5) = mem[1].access_virt_sarray;
        *((_DWORD *)k + 6) = 0;
        *((_DWORD *)k + 7) = 0;
        *((_BYTE *)k + 33) = 0;
      }
    }
    for ( m = mem[1].request_virt_barray;
          m != nullptr;
          m = *((jvirt_barray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))m
              + 9) )
    {
      if ( *(_DWORD *)m == 0 )
      {
        v16 = *((_DWORD *)m + 1);
        v17 = *((_DWORD *)m + 3);
        __twllei(v17, 0);
        if ( (int)((v16 - 1) / v17 + 1) > v10 )
        {
          v18 = *((_DWORD *)m + 2);
          *((_DWORD *)m + 4) = v17 * v10;
          jpeg_open_backing_store(
            cinfo,
            info: (backing_store_struct *)((char *)m + 40),
            total_bytes_needed: (v18 * v16) << 7);
          *((_BYTE *)m + 34) = 1;
        }
        else
        {
          *((_DWORD *)m + 4) = v16;
        }
        *(_DWORD *)m = alloc_barray(cinfo, pool_id: 1u, blocksperrow: *((_DWORD *)m + 2), numrows: *((_DWORD *)m + 4));
        *((_DWORD *)m + 5) = mem[1].access_virt_sarray;
        *((_DWORD *)m + 6) = 0;
        *((_DWORD *)m + 7) = 0;
        *((_BYTE *)m + 33) = 0;
      }
    }
  }
}


// ========================================================================
// do_sarray_io
// EA  : 0x83226688
// RVA : 0x01226688
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

void __fastcall do_sarray_io(jpeg_common_struct *cinfo, jvirt_sarray_control *ptr, unsigned __int8 writing)
{
  unsigned int samplesperrow; // r26
  signed int rows_in_mem; // r11
  signed int v8; // r30
  int i; // r28
  signed int rowsperchunk; // r11
  unsigned int v11; // r10
  signed int v12; // r10
  int v13; // r29
  int v14; // r7
  backing_store_struct *p_b_s_info; // r4
  unsigned __int8 *v16; // r5

  samplesperrow = ptr->samplesperrow;
  rows_in_mem = ptr->rows_in_mem;
  v8 = 0;
  for ( i = ptr->cur_start_row * samplesperrow; v8 < rows_in_mem; v8 += ptr->rowsperchunk )
  {
    rowsperchunk = rows_in_mem - v8;
    if ( (signed int)ptr->rowsperchunk < rowsperchunk )
      rowsperchunk = ptr->rowsperchunk;
    v11 = ptr->cur_start_row + v8;
    if ( rowsperchunk >= (int)(ptr->first_undef_row - v11) )
      rowsperchunk = ptr->first_undef_row - v11;
    v12 = ptr->rows_in_array - v11;
    if ( rowsperchunk >= v12 )
      rowsperchunk = v12;
    if ( rowsperchunk <= 0 )
      break;
    v13 = rowsperchunk * samplesperrow;
    v14 = rowsperchunk * samplesperrow;
    p_b_s_info = &ptr->b_s_info;
    v16 = ptr->mem_buffer[v8];
    if ( writing != 0 )
      ptr->b_s_info.write_backing_store(a1: cinfo, a2: p_b_s_info, a3: v16, a4: i, a5: v14);
    else
      ptr->b_s_info.read_backing_store(a1: cinfo, a2: p_b_s_info, a3: v16, a4: i, a5: v14);
    i += v13;
    rows_in_mem = ptr->rows_in_mem;
  }
}


// ========================================================================
// do_barray_io
// EA  : 0x83226768
// RVA : 0x01226768
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

void __fastcall do_barray_io(jpeg_common_struct *cinfo, jvirt_barray_control *ptr, unsigned __int8 writing)
{
  signed int rows_in_mem; // r11
  unsigned int v6; // r26
  signed int v8; // r30
  int i; // r28
  signed int rowsperchunk; // r11
  unsigned int v11; // r10
  signed int v12; // r10
  int v13; // r29
  int v14; // r7
  backing_store_struct *p_b_s_info; // r4
  __int16 *v16; // r5

  rows_in_mem = ptr->rows_in_mem;
  v6 = ptr->blocksperrow << 7;
  v8 = 0;
  for ( i = v6 * ptr->cur_start_row; v8 < rows_in_mem; v8 += ptr->rowsperchunk )
  {
    rowsperchunk = rows_in_mem - v8;
    if ( (signed int)ptr->rowsperchunk < rowsperchunk )
      rowsperchunk = ptr->rowsperchunk;
    v11 = v8 + ptr->cur_start_row;
    if ( rowsperchunk >= (int)(ptr->first_undef_row - v11) )
      rowsperchunk = ptr->first_undef_row - v11;
    v12 = ptr->rows_in_array - v11;
    if ( rowsperchunk >= v12 )
      rowsperchunk = v12;
    if ( rowsperchunk <= 0 )
      break;
    v13 = rowsperchunk * v6;
    v14 = rowsperchunk * v6;
    p_b_s_info = &ptr->b_s_info;
    v16 = (__int16 *)ptr->mem_buffer[v8];
    if ( writing != 0 )
      ptr->b_s_info.write_backing_store(a1: cinfo, a2: p_b_s_info, a3: v16, a4: i, a5: v14);
    else
      ptr->b_s_info.read_backing_store(a1: cinfo, a2: p_b_s_info, a3: v16, a4: i, a5: v14);
    i += v13;
    rows_in_mem = ptr->rows_in_mem;
  }
}


// ========================================================================
// access_virt_sarray
// EA  : 0x83226850
// RVA : 0x01226850
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

unsigned __int8 **__fastcall access_virt_sarray(
        jpeg_common_struct *cinfo,
        jvirt_sarray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable)
{
  unsigned int v5; // r30
  unsigned int cur_start_row; // r11
  unsigned int first_undef_row; // r11
  unsigned int v12; // r10
  unsigned int samplesperrow; // r28
  unsigned int v14; // r11
  unsigned int v15; // r10
  unsigned int v16; // r29
  unsigned int v17; // r30

  v5 = start_row + num_rows;
  if ( start_row + num_rows > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > ptr->rows_in_mem + cur_start_row )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_sarray_io(cinfo, ptr, writing: 1u);
      ptr->dirty = 0;
    }
    if ( start_row <= ptr->cur_start_row )
      ptr->cur_start_row = (((v5 - ptr->rows_in_mem) >> 31) - 1) & (v5 - ptr->rows_in_mem);
    else
      ptr->cur_start_row = start_row;
    do_sarray_io(cinfo, ptr, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row < v5 )
  {
    if ( first_undef_row < start_row )
    {
      if ( writable != 0 )
      {
        cinfo->err->msg_code = 22;
        cinfo->err->error_exit(a1: cinfo);
      }
      first_undef_row = start_row;
    }
    if ( writable != 0 )
      ptr->first_undef_row = v5;
    if ( ptr->pre_zero != 0 )
    {
      v12 = ptr->cur_start_row;
      samplesperrow = ptr->samplesperrow;
      v14 = first_undef_row - v12;
      v15 = v5 - v12;
      if ( v14 < v15 )
      {
        v16 = v14;
        v17 = v15 - v14;
        do
        {
          jzero_far(target: ptr->mem_buffer[v16], bytestozero: samplesperrow);
          --v17;
          ++v16;
        }
        while ( v17 != 0 );
      }
    }
    else if ( writable == 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  if ( writable != 0 )
    ptr->dirty = 1;
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}


// ========================================================================
// access_virt_barray
// EA  : 0x83226A50
// RVA : 0x01226A50
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

__int16 (**__fastcall access_virt_barray(
        jpeg_common_struct *cinfo,
        jvirt_barray_control *ptr,
        unsigned int start_row,
        unsigned int num_rows,
        unsigned __int8 writable))[64]
{
  unsigned int v5; // r30
  unsigned int cur_start_row; // r11
  unsigned int first_undef_row; // r11
  unsigned int v12; // r10
  unsigned int v13; // r11
  unsigned int v14; // r10
  unsigned int v15; // r28
  unsigned int v16; // r29
  unsigned int v17; // r30

  v5 = start_row + num_rows;
  if ( start_row + num_rows > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == nullptr )
  {
    cinfo->err->msg_code = 22;
    cinfo->err->error_exit(a1: cinfo);
  }
  cur_start_row = ptr->cur_start_row;
  if ( start_row < cur_start_row || v5 > ptr->rows_in_mem + cur_start_row )
  {
    if ( ptr->b_s_open == 0 )
    {
      cinfo->err->msg_code = 69;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( ptr->dirty != 0 )
    {
      do_barray_io(cinfo, ptr, writing: 1u);
      ptr->dirty = 0;
    }
    if ( start_row <= ptr->cur_start_row )
      ptr->cur_start_row = (((v5 - ptr->rows_in_mem) >> 31) - 1) & (v5 - ptr->rows_in_mem);
    else
      ptr->cur_start_row = start_row;
    do_barray_io(cinfo, ptr, writing: 0);
  }
  first_undef_row = ptr->first_undef_row;
  if ( first_undef_row < v5 )
  {
    if ( first_undef_row < start_row )
    {
      if ( writable != 0 )
      {
        cinfo->err->msg_code = 22;
        cinfo->err->error_exit(a1: cinfo);
      }
      first_undef_row = start_row;
    }
    if ( writable != 0 )
      ptr->first_undef_row = v5;
    if ( ptr->pre_zero != 0 )
    {
      v12 = ptr->cur_start_row;
      v13 = first_undef_row - v12;
      v14 = v5 - v12;
      v15 = ptr->blocksperrow << 7;
      if ( v13 < v14 )
      {
        v16 = v13;
        v17 = v14 - v13;
        do
        {
          jzero_far(target: ptr->mem_buffer[v16], bytestozero: v15);
          --v17;
          ++v16;
        }
        while ( v17 != 0 );
      }
    }
    else if ( writable == 0 )
    {
      cinfo->err->msg_code = 22;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  if ( writable != 0 )
    ptr->dirty = 1;
  return &ptr->mem_buffer[start_row - ptr->cur_start_row];
}


// ========================================================================
// free_pool
// EA  : 0x83226C50
// RVA : 0x01226C50
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

void __fastcall free_pool(jpeg_common_struct *cinfo, unsigned int pool_id)
{
  jpeg_memory_mgr *mem; // r31
  jvirt_sarray_control *(__fastcall *i)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r30
  jvirt_barray_control *(__fastcall *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r30
  int v7; // r11
  _DWORD *v8; // r4
  _DWORD *v9; // r30
  int v10; // r29
  int v11; // r11
  _DWORD *v12; // r4
  _DWORD *v13; // r30
  int v14; // r29

  mem = cinfo->mem;
  if ( pool_id >= 2 )
  {
    cinfo->err->msg_code = 14;
    cinfo->err->msg_parm.i[0] = pool_id;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( pool_id == 1 )
  {
    for ( i = mem[1].request_virt_sarray;
          i != nullptr;
          i = *((jvirt_sarray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))i
              + 9) )
    {
      if ( *((_BYTE *)i + 34) != 0 )
      {
        *((_BYTE *)i + 34) = 0;
        (*((void (__fastcall **)(jpeg_common_struct *, int))i + 12))(a1: cinfo, a2: (int)i + 40);
      }
    }
    request_virt_barray = mem[1].request_virt_barray;
    for ( mem[1].request_virt_sarray = nullptr;
          request_virt_barray != nullptr;
          request_virt_barray = *((jvirt_barray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                + 9) )
    {
      if ( *((_BYTE *)request_virt_barray + 34) != 0 )
      {
        *((_BYTE *)request_virt_barray + 34) = 0;
        (*((void (__fastcall **)(jpeg_common_struct *, int))request_virt_barray + 12))(
          a1: cinfo,
          a2: (int)request_virt_barray + 40);
      }
    }
    mem[1].request_virt_barray = nullptr;
  }
  v7 = 4 * (pool_id + 15);
  v8 = *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v7);
  *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v7) = nullptr;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      zcfree(opaque: cinfo, ptr: v8);
      v8 = v9;
      mem[1].realize_virt_arrays = (void (__fastcall *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v10);
    }
    while ( v9 != nullptr );
  }
  v11 = 4 * (pool_id + 13);
  v12 = *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v11);
  *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v11) = nullptr;
  if ( v12 != nullptr )
  {
    do
    {
      v13 = (_DWORD *)*v12;
      v14 = v12[2] + v12[1] + 16;
      zcfree(opaque: cinfo, ptr: v12);
      v12 = v13;
      mem[1].realize_virt_arrays = (void (__fastcall *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v14);
    }
    while ( v13 != nullptr );
  }
}


// ========================================================================
// self_destruct
// EA  : 0x83226DD8
// RVA : 0x01226DD8
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

void __fastcall self_destruct(jpeg_common_struct *cinfo)
{
  int i; // r26
  jpeg_memory_mgr *mem; // r31
  jvirt_sarray_control *(__fastcall *j)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r30
  jvirt_barray_control *(__fastcall *request_virt_barray)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int); // r30
  int v6; // r11
  _DWORD *v7; // r4
  _DWORD *v8; // r30
  int v9; // r29
  int v10; // r11
  _DWORD *v11; // r4
  _DWORD *v12; // r30
  int v13; // r29

  for ( i = 1; i >= 0; --i )
  {
    mem = cinfo->mem;
    if ( i >= 2 )
    {
      cinfo->err->msg_code = 14;
      cinfo->err->msg_parm.i[0] = i;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( i == 1 )
    {
      for ( j = mem[1].request_virt_sarray;
            j != nullptr;
            j = *((jvirt_sarray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))j
                + 9) )
      {
        if ( *((_BYTE *)j + 34) != 0 )
        {
          *((_BYTE *)j + 34) = 0;
          (*((void (__fastcall **)(jpeg_common_struct *, int))j + 12))(a1: cinfo, a2: (int)j + 40);
        }
      }
      request_virt_barray = mem[1].request_virt_barray;
      for ( mem[1].request_virt_sarray = nullptr;
            request_virt_barray != nullptr;
            request_virt_barray = *((jvirt_barray_control *(__fastcall **)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray
                                  + 9) )
      {
        if ( *((_BYTE *)request_virt_barray + 34) != 0 )
        {
          *((_BYTE *)request_virt_barray + 34) = 0;
          (*((void (__fastcall **)(jpeg_common_struct *, int))request_virt_barray + 12))(
            a1: cinfo,
            a2: (int)request_virt_barray + 40);
        }
      }
      mem[1].request_virt_barray = nullptr;
    }
    v6 = 4 * (i + 15);
    v7 = *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v6);
    *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v6) = nullptr;
    if ( v7 != nullptr )
    {
      do
      {
        v8 = (_DWORD *)*v7;
        v9 = v7[2] + v7[1] + 16;
        zcfree(opaque: cinfo, ptr: v7);
        v7 = v8;
        mem[1].realize_virt_arrays = (void (__fastcall *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v9);
      }
      while ( v8 != nullptr );
    }
    v10 = 4 * (i + 13);
    v11 = *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v10);
    *(void *(__fastcall **)(jpeg_common_struct *, int, unsigned int))((char *)&mem->alloc_small + v10) = nullptr;
    if ( v11 != nullptr )
    {
      do
      {
        v12 = (_DWORD *)*v11;
        v13 = v11[2] + v11[1] + 16;
        zcfree(opaque: cinfo, ptr: v11);
        v11 = v12;
        mem[1].realize_virt_arrays = (void (__fastcall *)(jpeg_common_struct *))((char *)mem[1].realize_virt_arrays - v13);
      }
      while ( v12 != nullptr );
    }
  }
  zcfree(opaque: cinfo, ptr: cinfo->mem);
  cinfo->mem = nullptr;
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)cinfo);
}


// ========================================================================
// ?jinit_memory_mgr@@YAXPAUjpeg_common_struct@@@Z
// EA  : 0x83226F80
// RVA : 0x01226F80
// PDB : w:\tech5\libs\jpeg\jmemmgr.cpp
// ========================================================================

void __fastcall jinit_memory_mgr(_exception *cinfo)
{
  int started; // r28
  jpeg_memory_mgr *large; // r31

  cinfo->name = nullptr;
  started = idLobbyBackend360::StartArbitration(pexcept: cinfo);
  large = (jpeg_memory_mgr *)jpeg_get_large((jpeg_common_struct *)cinfo, sizeofobject: 0x54u);
  if ( large == nullptr )
  {
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)cinfo);
    *(_DWORD *)(cinfo->type + 20) = 54;
    *(_DWORD *)(cinfo->type + 24) = 0;
    (*(void (__fastcall **)(_exception *))cinfo->type)(a1: cinfo);
  }
  large->max_memory_to_use = started;
  large->alloc_small = (void *(__fastcall *)(jpeg_common_struct *, int, unsigned int))alloc_small;
  large->alloc_large = (void *(__fastcall *)(jpeg_common_struct *, int, unsigned int))alloc_large;
  large->alloc_sarray = (unsigned __int8 **(__fastcall *)(jpeg_common_struct *, int, unsigned int, unsigned int))alloc_sarray;
  large->alloc_barray = (__int16 (**(__fastcall *)(jpeg_common_struct *, int, unsigned int, unsigned int))[64])alloc_barray;
  large->request_virt_sarray = (jvirt_sarray_control *(__fastcall *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_sarray;
  large->request_virt_barray = (jvirt_barray_control *(__fastcall *)(jpeg_common_struct *, int, unsigned __int8, unsigned int, unsigned int, unsigned int))request_virt_barray;
  large->realize_virt_arrays = realize_virt_arrays;
  large->access_virt_sarray = access_virt_sarray;
  large->access_virt_barray = access_virt_barray;
  large->free_pool = (void (__fastcall *)(jpeg_common_struct *, int))free_pool;
  large->self_destruct = self_destruct;
  large->max_alloc_chunk = 1000000000;
  large[1].alloc_large = nullptr;
  large[1].alloc_barray = nullptr;
  large[1].alloc_small = nullptr;
  large[1].alloc_sarray = nullptr;
  large[1].request_virt_sarray = nullptr;
  large[1].request_virt_barray = nullptr;
  large[1].realize_virt_arrays = (void (__fastcall *)(jpeg_common_struct *))84;
  cinfo->name = (char *)large;
}

