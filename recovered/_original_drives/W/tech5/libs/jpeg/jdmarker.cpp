
// ========================================================================
// get_soi
// EA  : 0x83211898
// RVA : 0x01211898
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall get_soi(jpeg_common_struct *cinfo)
{
  int v2; // r11
  int i; // ctr
  jpeg_d_main_controller *global_state; // r11

  cinfo->err->msg_code = 102;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  if ( *(_BYTE *)(cinfo[16].global_state + 12) != 0 )
  {
    cinfo->err->msg_code = 61;
    cinfo->err->error_exit(a1: cinfo);
  }
  v2 = 0;
  for ( i = 16; i != 0; --i )
  {
    *((_BYTE *)&cinfo[8].progress + v2 + 2) = 0;
    *((_BYTE *)&cinfo[9].err + v2 + 2) = 1;
    *(&cinfo[9].is_decompressor + v2++ + 2) = 5;
  }
  global_state = (jpeg_d_main_controller *)cinfo[16].global_state;
  cinfo[10].client_data = nullptr;
  *(_DWORD *)&cinfo[1].is_decompressor = 0;
  BYTE2(cinfo[11].err) = 0;
  *(_WORD *)&cinfo[10].is_decompressor = 1;
  *(&cinfo[10].is_decompressor + 2) = 1;
  *(&cinfo[10].is_decompressor + 3) = 0;
  HIWORD(cinfo[10].global_state) = 1;
  LOWORD(cinfo[10].global_state) = 1;
  HIBYTE(cinfo[11].err) = 0;
  BYTE1(cinfo[11].err) = 0;
  HIBYTE(global_state[1].process_data) = 1;
  return 1;
}


// ========================================================================
// get_sof
// EA  : 0x83211980
// RVA : 0x01211980
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall get_sof(jpeg_common_struct *cinfo, unsigned __int8 is_prog, unsigned __int8 is_arith)
{
  jpeg_source_mgr *err; // r27
  unsigned int bytes_in_buffer; // r11
  const unsigned __int8 *next_input_byte; // r10
  int v8; // r9
  unsigned int v9; // r11
  const unsigned __int8 *v10; // r10
  int v11; // r30
  int v12; // r9
  unsigned int v13; // r11
  const unsigned __int8 *v14; // r10
  int v15; // r30
  jpeg_error_mgr *v16; // r9
  unsigned int v17; // r11
  const unsigned __int8 *v18; // r10
  int v19; // r9
  unsigned int v20; // r11
  const unsigned __int8 *v21; // r10
  const unsigned __int8 *v22; // r9
  unsigned int v23; // r11
  unsigned int v24; // r10
  const unsigned __int8 *v25; // r11
  bool v26; // zf
  unsigned int v27; // r9
  bool v28; // cr34
  const unsigned __int8 *v29; // r10
  const unsigned __int8 *v30; // r28
  int global_state; // r6
  unsigned int v32; // r29
  jpeg_error_mgr *v33; // r11
  int v34; // r30
  int v35; // r26
  void (__fastcall **p_free_pool)(jpeg_common_struct *, int); // r30
  unsigned int v37; // r10
  const unsigned __int8 *v38; // r11
  int v39; // r9
  unsigned int v40; // r10
  const unsigned __int8 *v41; // r11
  int v42; // r8
  jpeg_error_mgr *v43; // r11

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  HIBYTE(cinfo[8].progress) = is_prog;
  BYTE1(cinfo[8].progress) = is_arith;
  if ( bytes_in_buffer == 0 )
  {
    if ( ((unsigned __int8 (*)(void))err->fill_input_buffer)() == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v8 = *next_input_byte;
  v9 = bytes_in_buffer - 1;
  v10 = next_input_byte + 1;
  v11 = __ROL4__(v8, 8);
  if ( v9 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v10 = err->next_input_byte;
    v9 = err->bytes_in_buffer;
  }
  v12 = *v10;
  v13 = v9 - 1;
  v14 = v10 + 1;
  v15 = v12 + v11;
  if ( v13 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v14 = err->next_input_byte;
    v13 = err->bytes_in_buffer;
  }
  v16 = (jpeg_error_mgr *)*v14;
  v17 = v13 - 1;
  v18 = v14 + 1;
  cinfo[8].err = v16;
  if ( v17 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v18 = err->next_input_byte;
    v17 = err->bytes_in_buffer;
  }
  v19 = *v18;
  v20 = v17 - 1;
  v21 = v18 + 1;
  cinfo[1].progress = (jpeg_progress_mgr *)__ROL4__(v19, 8);
  if ( v20 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v21 = err->next_input_byte;
    v20 = err->bytes_in_buffer;
  }
  v22 = v21 + 1;
  v23 = v20 - 1;
  cinfo[1].progress = (jpeg_progress_mgr *)((char *)cinfo[1].progress + *v21);
  if ( v23 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v22 = err->next_input_byte;
    v23 = err->bytes_in_buffer;
  }
  v24 = v23 - 1;
  cinfo[1].mem = (jpeg_memory_mgr *)__ROL4__(*v22, 8);
  v26 = v23 != 1;
  v25 = v22 + 1;
  if ( !v26 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v25 = err->next_input_byte;
    v24 = err->bytes_in_buffer;
  }
  v27 = v24 - 1;
  v28 = v24 == 1;
  v29 = v25 + 1;
  cinfo[1].mem = (jpeg_memory_mgr *)((char *)cinfo[1].mem + *v25);
  if ( v28 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v29 = err->next_input_byte;
    v27 = err->bytes_in_buffer;
  }
  v30 = v29 + 1;
  global_state = cinfo[15].global_state;
  v32 = v27 - 1;
  v33 = cinfo->err;
  cinfo[1].client_data = (void *)*v29;
  v34 = v15 - 8;
  v33->msg_parm.i[0] = global_state;
  v33->msg_parm.i[1] = (int)cinfo[1].mem;
  v33->msg_parm.i[2] = (int)cinfo[1].progress;
  v33->msg_parm.i[3] = (int)cinfo[1].client_data;
  cinfo->err->msg_code = 100;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  if ( *(_BYTE *)(cinfo[16].global_state + 13) != 0 )
  {
    cinfo->err->msg_code = 58;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[1].progress == nullptr || cinfo[1].mem == nullptr || (int)cinfo[1].client_data <= 0 )
  {
    cinfo->err->msg_code = 32;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( v34 != 3 * (int)cinfo[1].client_data )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( cinfo[8].mem == nullptr )
    cinfo[8].mem = (jpeg_memory_mgr *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 84 * (int)cinfo[1].client_data);
  v35 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = &cinfo[8].mem[-2].free_pool;
    do
    {
      p_free_pool[18] = (void (__fastcall *)(jpeg_common_struct *, int))v35;
      if ( v32 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v30 = err->next_input_byte;
        v32 = err->bytes_in_buffer;
      }
      v37 = v32 - 1;
      v38 = v30 + 1;
      p_free_pool[17] = (void (__fastcall *)(jpeg_common_struct *, int))*v30;
      if ( v32 == 1 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v38 = err->next_input_byte;
        v37 = err->bytes_in_buffer;
      }
      v39 = *v38;
      v40 = v37 - 1;
      v41 = v38 + 1;
      p_free_pool[20] = (void (__fastcall *)(jpeg_common_struct *, int))(v39 & 0xF);
      p_free_pool[19] = (void (__fastcall *)(jpeg_common_struct *, int))(v39 >> 4);
      if ( v40 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v41 = err->next_input_byte;
        v40 = err->bytes_in_buffer;
      }
      v30 = v41 + 1;
      v42 = (int)p_free_pool[17];
      v32 = v40 - 1;
      p_free_pool[21] = (void (__fastcall *)(jpeg_common_struct *, int))*v41;
      v43 = cinfo->err;
      v43->msg_parm.i[0] = v42;
      v43->msg_parm.i[1] = (int)p_free_pool[19];
      v43->msg_parm.i[2] = (int)p_free_pool[20];
      p_free_pool += 21;
      v43->msg_parm.i[3] = (int)*p_free_pool;
      cinfo->err->msg_code = 101;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      ++v35;
    }
    while ( v35 < (int)cinfo[1].client_data );
  }
  *(_BYTE *)(cinfo[16].global_state + 13) = 1;
  err->next_input_byte = v30;
  err->bytes_in_buffer = v32;
  return 1;
}


// ========================================================================
// get_sos
// EA  : 0x83211E00
// RVA : 0x01211E00
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall get_sos(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r25
  const unsigned __int8 *next_input_byte; // r30
  unsigned int bytes_in_buffer; // r29
  const unsigned __int8 *v6; // r11
  unsigned int v7; // r10
  int v8; // r30
  int v9; // r9
  unsigned int v10; // r10
  const unsigned __int8 *v11; // r11
  int v12; // r30
  int v13; // r23
  unsigned int v14; // r26
  const unsigned __int8 *v15; // r28
  int v16; // r24
  int *p_mem; // r22
  int v18; // r27
  unsigned int v19; // r10
  const unsigned __int8 *v20; // r11
  int v21; // r29
  JHUFF_TBL *mem; // r30
  int v23; // r11
  jpeg_error_mgr *v24; // r11
  unsigned int v25; // r10
  const unsigned __int8 *v26; // r11
  unsigned int v27; // r29
  const unsigned __int8 *v28; // r30
  int v29; // r10
  jpeg_error_mgr *v30; // r11
  int v31; // r7

  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  bytes_in_buffer = err->bytes_in_buffer;
  if ( *(_BYTE *)(cinfo[16].global_state + 13) == 0 )
  {
    cinfo->err->msg_code = 62;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( bytes_in_buffer == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v6 = next_input_byte + 1;
  v7 = bytes_in_buffer - 1;
  v8 = __ROL4__(*next_input_byte, 8);
  if ( bytes_in_buffer == 1 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v6 = err->next_input_byte;
    v7 = err->bytes_in_buffer;
  }
  v9 = *v6;
  v10 = v7 - 1;
  v11 = v6 + 1;
  v12 = v9 + v8;
  if ( v10 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v11 = err->next_input_byte;
    v10 = err->bytes_in_buffer;
  }
  v13 = *v11;
  v14 = v10 - 1;
  v15 = v11 + 1;
  cinfo->err->msg_code = 103;
  cinfo->err->msg_parm.i[0] = v13;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  if ( v12 != 2 * (v13 + 3) || v13 < 1 || v13 > 4 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  cinfo[12].mem = (jpeg_memory_mgr *)v13;
  v16 = 0;
  if ( v13 > 0 )
  {
    p_mem = (int *)&cinfo[12].mem;
    do
    {
      if ( v14 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v15 = err->next_input_byte;
        v14 = err->bytes_in_buffer;
      }
      v18 = *v15;
      v19 = v14 - 1;
      v20 = v15 + 1;
      if ( v14 == 1 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v20 = err->next_input_byte;
        v19 = err->bytes_in_buffer;
      }
      v15 = v20 + 1;
      v21 = *v20;
      v14 = v19 - 1;
      mem = (JHUFF_TBL *)cinfo[8].mem;
      v23 = 0;
      if ( (int)cinfo[1].client_data <= 0 )
      {
LABEL_28:
        cinfo->err->msg_code = 5;
        cinfo->err->msg_parm.i[0] = v18;
        cinfo->err->error_exit(a1: cinfo);
      }
      else
      {
        while ( v18 != *(_DWORD *)mem->bits )
        {
          ++v23;
          mem = (JHUFF_TBL *)((char *)mem + 84);
          if ( v23 >= (int)cinfo[1].client_data )
            goto LABEL_28;
        }
      }
      *++p_mem = (int)mem;
      *(_DWORD *)&mem->huffval[7] = v21 & 0xF;
      *(_DWORD *)&mem->huffval[3] = (v21 >> 4) & 0xF;
      v24 = cinfo->err;
      v24->msg_parm.i[0] = v18;
      v24->msg_parm.i[1] = *(_DWORD *)&mem->huffval[3];
      v24->msg_parm.i[2] = *(_DWORD *)&mem->huffval[7];
      cinfo->err->msg_code = 104;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      ++v16;
    }
    while ( v16 < v13 );
  }
  if ( v14 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v15 = err->next_input_byte;
    v14 = err->bytes_in_buffer;
  }
  v25 = v14 - 1;
  v26 = v15 + 1;
  cinfo[15].mem = (jpeg_memory_mgr *)*v15;
  if ( v14 == 1 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v26 = err->next_input_byte;
    v25 = err->bytes_in_buffer;
  }
  v27 = v25 - 1;
  v28 = v26 + 1;
  cinfo[15].progress = (jpeg_progress_mgr *)*v26;
  if ( v25 == 1 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v28 = err->next_input_byte;
    v27 = err->bytes_in_buffer;
  }
  v29 = *v28;
  v30 = cinfo->err;
  v31 = (int)cinfo[15].mem;
  *(_DWORD *)&cinfo[15].is_decompressor = v29 & 0xF;
  cinfo[15].client_data = (void *)(v29 >> 4);
  v30->msg_parm.i[0] = v31;
  v30->msg_parm.i[1] = (int)cinfo[15].progress;
  v30->msg_parm.i[2] = (int)cinfo[15].client_data;
  v30->msg_parm.i[3] = *(_DWORD *)&cinfo[15].is_decompressor;
  cinfo->err->msg_code = 105;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  *(_DWORD *)(cinfo[16].global_state + 16) = 0;
  ++cinfo[5].mem;
  err->next_input_byte = v28 + 1;
  err->bytes_in_buffer = v27 - 1;
  return 1;
}


// ========================================================================
// get_dht
// EA  : 0x832121D8
// RVA : 0x012121D8
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall get_dht(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r24
  unsigned int bytes_in_buffer; // r10
  const unsigned __int8 *next_input_byte; // r11
  int v6; // r9
  unsigned int v7; // r10
  const unsigned __int8 *v8; // r11
  int v9; // r29
  const unsigned __int8 *v10; // r31
  unsigned int v11; // r28
  int v12; // r26
  unsigned int v13; // r25
  int v14; // r27
  int i; // r29
  unsigned __int8 v16; // r10
  jpeg_error_mgr *v17; // r11
  int v18; // r5
  int v19; // r26
  int v20; // r9
  int v21; // r6
  int v22; // r10
  int v23; // r8
  int v24; // r18
  int v25; // r29
  jpeg_error_mgr *v26; // r11
  int v27; // r5
  int v28; // r9
  int v29; // r6
  int v30; // r10
  int v31; // r8
  int v32; // r18
  int v33; // r29
  int j; // r29
  unsigned int v35; // r11
  void **v36; // r29
  _BYTE v37[32]; // [sp+50h] [-1A0h] BYREF
  _BYTE v38[384]; // [sp+70h] [-180h] BYREF

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( bytes_in_buffer == 0 )
  {
    if ( ((unsigned __int8 (*)(void))err->fill_input_buffer)() == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v6 = *next_input_byte;
  v7 = bytes_in_buffer - 1;
  v8 = next_input_byte + 1;
  v9 = __ROL4__(v6, 8);
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v8 = err->next_input_byte;
    v7 = err->bytes_in_buffer;
  }
  v10 = v8 + 1;
  v11 = v7 - 1;
  v12 = *v8 + v9 - 2;
  while ( v12 > 16 )
  {
    if ( v11 == 0 )
    {
      if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
        return 0;
      v10 = err->next_input_byte;
      v11 = err->bytes_in_buffer;
    }
    v13 = *v10;
    --v11;
    ++v10;
    cinfo->err->msg_code = 80;
    cinfo->err->msg_parm.i[0] = v13;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    v14 = 0;
    v37[0] = 0;
    for ( i = 1; i <= 16; ++i )
    {
      if ( v11 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v10 = err->next_input_byte;
        v11 = err->bytes_in_buffer;
      }
      v16 = *v10;
      --v11;
      v37[i] = *v10++;
      v14 += v16;
    }
    v17 = cinfo->err;
    v18 = v37[2];
    v19 = v12 - 17;
    v20 = v37[3];
    v21 = v37[4];
    v22 = v37[5];
    v23 = v37[6];
    v24 = v37[8];
    v25 = v37[7];
    v17->msg_parm.i[0] = v37[1];
    v17->msg_parm.i[1] = v18;
    v17->msg_parm.i[2] = v20;
    v17->msg_parm.i[3] = v21;
    v17->msg_parm.i[4] = v22;
    v17->msg_parm.i[5] = v23;
    v17->msg_parm.i[6] = v25;
    v17->msg_parm.i[7] = v24;
    cinfo->err->msg_code = 86;
    cinfo->err->emit_message(a1: cinfo, a2: 2);
    v26 = cinfo->err;
    v27 = v37[10];
    v28 = v37[11];
    v29 = v37[12];
    v30 = v37[13];
    v31 = v37[14];
    v32 = v37[16];
    v33 = v37[15];
    v26->msg_parm.i[0] = v37[9];
    v26->msg_parm.i[1] = v27;
    v26->msg_parm.i[2] = v28;
    v26->msg_parm.i[3] = v29;
    v26->msg_parm.i[4] = v30;
    v26->msg_parm.i[5] = v31;
    v26->msg_parm.i[6] = v33;
    v26->msg_parm.i[7] = v32;
    cinfo->err->msg_code = 86;
    cinfo->err->emit_message(a1: cinfo, a2: 2);
    if ( v14 > 256 || v14 > v19 )
    {
      cinfo->err->msg_code = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    for ( j = 0; j < v14; ++j )
    {
      if ( v11 == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        v10 = err->next_input_byte;
        v11 = err->bytes_in_buffer;
      }
      --v11;
      v38[j] = *v10++;
    }
    v12 = v19 - v14;
    if ( (v13 & 0x10) != 0 )
    {
      v13 -= 16;
      v35 = v13 + 44;
    }
    else
    {
      v35 = v13 + 40;
    }
    v36 = (void **)(&cinfo->err + v35);
    if ( v13 >= 4 )
    {
      cinfo->err->msg_code = 30;
      cinfo->err->msg_parm.i[0] = v13;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( *v36 == nullptr )
      *v36 = jpeg_alloc_huff_table(cinfo);
    memcpy(Dst: *v36, Src: v37, Size: 0x11u);
    memcpy(Dst: (char *)*v36 + 17, Src: v38, Size: 0x100u);
  }
  if ( v12 != 0 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  err->next_input_byte = v10;
  err->bytes_in_buffer = v11;
  return 1;
}


// ========================================================================
// get_dqt
// EA  : 0x83212588
// RVA : 0x01212588
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall get_dqt(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r26
  unsigned int bytes_in_buffer; // r10
  const unsigned __int8 *next_input_byte; // r11
  int v6; // r9
  unsigned int v7; // r10
  const unsigned __int8 *v8; // r11
  int v9; // r31
  const unsigned __int8 *v10; // r29
  unsigned int v11; // r27
  int v12; // r21
  int v13; // r10
  int v14; // r31
  int v15; // r24
  int v16; // r31
  int v17; // r25
  const int *v18; // r30
  unsigned int v19; // r10
  const unsigned __int8 *v20; // r11
  __int16 v21; // r31
  __int16 v22; // r11
  int v23; // r8
  unsigned __int16 *v24; // r31
  int i; // r30
  jpeg_error_mgr *v26; // r11

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( bytes_in_buffer == 0 )
  {
    if ( ((unsigned __int8 (*)(void))err->fill_input_buffer)() == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v6 = *next_input_byte;
  v7 = bytes_in_buffer - 1;
  v8 = next_input_byte + 1;
  v9 = __ROL4__(v6, 8);
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v8 = err->next_input_byte;
    v7 = err->bytes_in_buffer;
  }
  v10 = v8 + 1;
  v11 = v7 - 1;
  v12 = *v8 + v9 - 2;
  while ( v12 > 0 )
  {
    if ( v11 == 0 )
    {
      if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
        return 0;
      v10 = err->next_input_byte;
      v11 = err->bytes_in_buffer;
    }
    v13 = *v10;
    --v11;
    v14 = v13 & 0xF;
    v15 = v13 >> 4;
    cinfo->err->msg_code = 81;
    ++v10;
    cinfo->err->msg_parm.i[0] = v14;
    cinfo->err->msg_parm.i[1] = v13 >> 4;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    if ( v14 >= 4 )
    {
      cinfo->err->msg_code = 31;
      cinfo->err->msg_parm.i[0] = v14;
      cinfo->err->error_exit(a1: cinfo);
    }
    v16 = 4 * (v14 + 36);
    if ( *(jpeg_error_mgr **)((char *)&cinfo->err + v16) == nullptr )
      *(jpeg_error_mgr **)((char *)&cinfo->err + v16) = (jpeg_error_mgr *)jpeg_alloc_quant_table(cinfo);
    v17 = *(int *)((char *)&cinfo->err + v16);
    v18 = jpeg_natural_order;
    do
    {
      if ( v15 != 0 )
      {
        if ( v11 == 0 )
        {
          if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
            return 0;
          v10 = err->next_input_byte;
          v11 = err->bytes_in_buffer;
        }
        v19 = v11 - 1;
        v20 = v10 + 1;
        v21 = __ROL4__(*v10, 8);
        if ( v11 == 1 )
        {
          if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
            return 0;
          v20 = err->next_input_byte;
          v19 = err->bytes_in_buffer;
        }
        v10 = v20 + 1;
        v11 = v19 - 1;
        v22 = *v20 + v21;
      }
      else
      {
        if ( v11 == 0 )
        {
          if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
            return 0;
          v10 = err->next_input_byte;
          v11 = err->bytes_in_buffer;
        }
        v22 = *v10;
        --v11;
        ++v10;
      }
      v23 = 2 * *v18++;
      *(_WORD *)(v23 + v17) = v22;
    }
    while ( (int)v18 < (int)&jpeg_natural_order[64] );
    if ( cinfo->err->trace_level >= 2 )
    {
      v24 = (unsigned __int16 *)(v17 - 2);
      for ( i = 8; i != 0; --i )
      {
        v26 = cinfo->err;
        v26->msg_parm.i[0] = v24[1];
        v26->msg_parm.i[1] = v24[2];
        v26->msg_parm.i[2] = v24[3];
        v26->msg_parm.i[3] = v24[4];
        v26->msg_parm.i[4] = v24[5];
        v26->msg_parm.i[5] = v24[6];
        v26->msg_parm.i[6] = v24[7];
        v24 += 8;
        v26->msg_parm.i[7] = *v24;
        cinfo->err->msg_code = 93;
        cinfo->err->emit_message(a1: cinfo, a2: 2);
      }
    }
    v12 -= 65;
    if ( v15 != 0 )
      v12 -= 64;
  }
  if ( v12 != 0 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  err->next_input_byte = v10;
  err->bytes_in_buffer = v11;
  return 1;
}


// ========================================================================
// get_dri
// EA  : 0x832128B0
// RVA : 0x012128B0
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall get_dri(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r31
  unsigned int bytes_in_buffer; // r10
  const unsigned __int8 *next_input_byte; // r11
  int v6; // r9
  unsigned int v7; // r10
  const unsigned __int8 *v8; // r11
  int v9; // r27
  const unsigned __int8 *v10; // r29
  unsigned int v11; // r28
  int v12; // r11
  unsigned int v13; // r27
  const unsigned __int8 *v14; // r29
  int v15; // r28
  bool v16; // zf
  int v17; // r28

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( bytes_in_buffer == 0 )
  {
    if ( ((unsigned __int8 (*)(void))err->fill_input_buffer)() == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v6 = *next_input_byte;
  v7 = bytes_in_buffer - 1;
  v8 = next_input_byte + 1;
  v9 = __ROL4__(v6, 8);
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v8 = err->next_input_byte;
    v7 = err->bytes_in_buffer;
  }
  v10 = v8 + 1;
  v11 = v7 - 1;
  if ( *v8 + v9 != 4 )
  {
    cinfo->err->msg_code = 11;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( v11 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v10 = err->next_input_byte;
    v11 = err->bytes_in_buffer;
  }
  v12 = *v10;
  v13 = v11 - 1;
  v14 = v10 + 1;
  v16 = v11 != 1;
  v15 = __ROL4__(v12, 8);
  if ( !v16 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v14 = err->next_input_byte;
    v13 = err->bytes_in_buffer;
  }
  v17 = *v14 + v15;
  cinfo->err->msg_code = 82;
  cinfo->err->msg_parm.i[0] = v17;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  cinfo[10].client_data = (void *)v17;
  err->next_input_byte = v14 + 1;
  err->bytes_in_buffer = v13 - 1;
  return 1;
}


// ========================================================================
// examine_app0
// EA  : 0x83212A28
// RVA : 0x01212A28
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

void __fastcall examine_app0(jpeg_common_struct *cinfo, unsigned __int8 *data, unsigned int datalen, int remaining)
{
  int v6; // r29
  int v7; // r5
  jpeg_error_mgr *v8; // r11
  __int64 v9; // r8
  int v10; // r11
  jpeg_error_mgr *err; // r11
  bool v12; // zf
  int v13; // r10

  v6 = datalen + remaining;
  if ( datalen < 0xE || *data != 74 || data[1] != 70 || data[2] != 73 || data[3] != 70 || data[4] != 0 )
  {
    if ( datalen >= 6 && *data == 74 && data[1] == 70 && data[2] == 88 && data[3] == 88 && data[4] == 0 )
    {
      v10 = data[5];
      if ( v10 != 16 )
      {
        if ( v10 == 17 )
        {
          cinfo->err->msg_code = 109;
          cinfo->err->msg_parm.i[0] = v6;
          ((void (*)(void))cinfo->err->emit_message)();
        }
        else
        {
          v12 = v10 == 19;
          err = cinfo->err;
          if ( v12 )
          {
            err->msg_code = 110;
            cinfo->err->msg_parm.i[0] = v6;
          }
          else
          {
            err->msg_code = 89;
            cinfo->err->msg_parm.i[0] = data[5];
            cinfo->err->msg_parm.i[1] = v6;
          }
          ((void (*)(void))cinfo->err->emit_message)();
        }
        return;
      }
      v13 = 108;
    }
    else
    {
      v13 = 77;
    }
    cinfo->err->msg_code = v13;
    cinfo->err->msg_parm.i[0] = v6;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    return;
  }
  cinfo[10].is_decompressor = 1;
  *(&cinfo[10].is_decompressor + 1) = data[5];
  *(&cinfo[10].is_decompressor + 2) = data[6];
  *(&cinfo[10].is_decompressor + 3) = data[7];
  v7 = *(&cinfo[10].is_decompressor + 1);
  HIWORD(cinfo[10].global_state) = __ROL4__(data[8], 8) + data[9];
  LOWORD(cinfo[10].global_state) = __ROL4__(data[10], 8) + data[11];
  if ( v7 != 1 )
  {
    cinfo->err->msg_code = 119;
    cinfo->err->msg_parm.i[0] = *(&cinfo[10].is_decompressor + 1);
    cinfo->err->msg_parm.i[1] = *(&cinfo[10].is_decompressor + 2);
    cinfo->err->emit_message(a1: cinfo, a2: -1);
  }
  v8 = cinfo->err;
  v8->msg_parm.i[0] = *(&cinfo[10].is_decompressor + 1);
  v8->msg_parm.i[1] = *(&cinfo[10].is_decompressor + 2);
  v8->msg_parm.i[2] = HIWORD(cinfo[10].global_state);
  v8->msg_parm.i[3] = LOWORD(cinfo[10].global_state);
  v8->msg_parm.i[4] = *(&cinfo[10].is_decompressor + 3);
  cinfo->err->msg_code = 87;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  LODWORD(v9) = data[13];
  HIDWORD(v9) = data[12];
  if ( v9 != 0 )
  {
    cinfo->err->msg_code = 90;
    cinfo->err->msg_parm.i[0] = data[12];
    cinfo->err->msg_parm.i[1] = data[13];
    cinfo->err->emit_message(a1: cinfo, a2: 1);
  }
  if ( v6 - 14 != 3 * data[13] * data[12] )
  {
    cinfo->err->msg_code = 88;
    cinfo->err->msg_parm.i[0] = v6 - 14;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
  }
}


// ========================================================================
// examine_app14
// EA  : 0x83212D38
// RVA : 0x01212D38
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

void __fastcall examine_app14(jpeg_common_struct *cinfo, unsigned __int8 *data, unsigned int datalen, int remaining)
{
  int v5; // r29
  int v6; // r8
  jpeg_error_mgr *err; // r10
  int v8; // r11

  if ( datalen >= 0xC && *data == 65 && data[1] == 100 && data[2] == 111 && data[3] == 98 && data[4] == 101 )
  {
    v5 = data[11];
    v6 = __ROL4__(data[5], 8) + data[6];
    err = cinfo->err;
    v8 = __ROL4__(data[9], 8) + data[10];
    err->msg_parm.i[1] = __ROL4__(data[7], 8) + data[8];
    err->msg_parm.i[0] = v6;
    err->msg_parm.i[2] = v8;
    err->msg_parm.i[3] = v5;
    cinfo->err->msg_code = 76;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
    BYTE1(cinfo[11].err) = v5;
    HIBYTE(cinfo[11].err) = 1;
  }
  else
  {
    cinfo->err->msg_code = 78;
    cinfo->err->msg_parm.i[0] = datalen + remaining;
    cinfo->err->emit_message(a1: cinfo, a2: 1);
  }
}


// ========================================================================
// get_interesting_appn
// EA  : 0x83212E48
// RVA : 0x01212E48
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall get_interesting_appn(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r27
  unsigned int bytes_in_buffer; // r10
  const unsigned __int8 *next_input_byte; // r11
  int v6; // r9
  unsigned int v7; // r10
  const unsigned __int8 *v8; // r11
  int v9; // r30
  int v10; // r9
  unsigned __int8 *v11; // r31
  unsigned int v12; // r29
  int v13; // r26
  unsigned int v14; // r28
  unsigned int i; // r30
  int global_state; // r11
  unsigned __int8 v17[80]; // [sp+50h] [-50h] BYREF

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( bytes_in_buffer == 0 )
  {
    if ( ((unsigned __int8 (*)(void))err->fill_input_buffer)() == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v6 = *next_input_byte;
  v7 = bytes_in_buffer - 1;
  v8 = next_input_byte + 1;
  v9 = __ROL4__(v6, 8);
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v8 = err->next_input_byte;
    v7 = err->bytes_in_buffer;
  }
  v10 = *v8;
  v11 = (unsigned __int8 *)(v8 + 1);
  v12 = v7 - 1;
  v13 = v10 + v9 - 2;
  if ( v13 < 14 )
    v14 = ((v10 + v9 == 2) + ((unsigned int)(v10 + v9 - 2) >> 31) - 1) & v13;
  else
    v14 = 14;
  for ( i = 0; i < v14; ++i )
  {
    if ( v12 == 0 )
    {
      if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
        return 0;
      v11 = (unsigned __int8 *)err->next_input_byte;
      v12 = err->bytes_in_buffer;
    }
    --v12;
    v17[i] = *v11++;
  }
  global_state = cinfo[15].global_state;
  if ( global_state == 224 )
  {
    examine_app0(cinfo, data: v17, datalen: v14, remaining: v13 - v14);
  }
  else if ( global_state == 238 )
  {
    examine_app14(cinfo, data: v17, datalen: v14, remaining: v13 - v14);
  }
  else
  {
    cinfo->err->msg_code = 68;
    cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  err->next_input_byte = v11;
  err->bytes_in_buffer = v12;
  if ( (int)(v13 - v14) > 0 )
    ((void (__fastcall *)(jpeg_common_struct *, unsigned int))cinfo[1].err->reset_error_mgr)(a1: cinfo, a2: v13 - v14);
  return 1;
}


// ========================================================================
// skip_variable
// EA  : 0x83213000
// RVA : 0x01213000
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall skip_variable(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r30
  unsigned int bytes_in_buffer; // r10
  const unsigned __int8 *next_input_byte; // r11
  unsigned int v6; // r27
  const unsigned __int8 *v7; // r28
  int v8; // r29
  int v9; // r11
  int v10; // r29

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( bytes_in_buffer == 0 )
  {
    if ( ((unsigned __int8 (*)(void))err->fill_input_buffer)() == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v6 = bytes_in_buffer - 1;
  v7 = next_input_byte + 1;
  v8 = __ROL4__(*next_input_byte, 8);
  if ( bytes_in_buffer == 1 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v7 = err->next_input_byte;
    v6 = err->bytes_in_buffer;
  }
  v9 = *v7 + v8;
  cinfo->err->msg_code = 91;
  v10 = v9 - 2;
  cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
  cinfo->err->msg_parm.i[1] = v9 - 2;
  cinfo->err->emit_message(a1: cinfo, a2: 1);
  err->next_input_byte = v7 + 1;
  err->bytes_in_buffer = v6 - 1;
  if ( v10 > 0 )
    ((void (__fastcall *)(jpeg_common_struct *, int))cinfo[1].err->reset_error_mgr)(a1: cinfo, a2: v10);
  return 1;
}


// ========================================================================
// next_marker
// EA  : 0x83213108
// RVA : 0x01213108
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall next_marker(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r30
  const unsigned __int8 *next_input_byte; // r29
  unsigned int i; // r31
  int v5; // r11
  int v6; // r11
  int v7; // r28
  jpeg_d_main_controller *global_state; // r11
  void (__fastcall *process_data)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // r10

  err = (jpeg_source_mgr *)cinfo[1].err;
  next_input_byte = err->next_input_byte;
  for ( i = err->bytes_in_buffer; ; err->bytes_in_buffer = i )
  {
    if ( i == 0 )
    {
      if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
        return 0;
      next_input_byte = err->next_input_byte;
      i = err->bytes_in_buffer;
    }
    v5 = *next_input_byte;
    --i;
    ++next_input_byte;
    if ( v5 == 255 )
      goto LABEL_10;
    do
    {
      ++*(_DWORD *)(cinfo[16].global_state + 20);
      err->next_input_byte = next_input_byte;
      err->bytes_in_buffer = i;
      if ( i == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        next_input_byte = err->next_input_byte;
        i = err->bytes_in_buffer;
      }
      v6 = *next_input_byte;
      --i;
      ++next_input_byte;
    }
    while ( v6 != 255 );
    do
    {
LABEL_10:
      if ( i == 0 )
      {
        if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
          return 0;
        next_input_byte = err->next_input_byte;
        i = err->bytes_in_buffer;
      }
      v7 = *next_input_byte;
      --i;
      ++next_input_byte;
    }
    while ( v7 == 255 );
    global_state = (jpeg_d_main_controller *)cinfo[16].global_state;
    process_data = global_state[2].process_data;
    if ( v7 != 0 )
      break;
    global_state[2].process_data = (void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))((char *)process_data + 2);
    err->next_input_byte = next_input_byte;
  }
  if ( process_data != nullptr )
  {
    cinfo->err->msg_code = 116;
    cinfo->err->msg_parm.i[0] = *(_DWORD *)(cinfo[16].global_state + 20);
    cinfo->err->msg_parm.i[1] = v7;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
    *(_DWORD *)(cinfo[16].global_state + 20) = 0;
  }
  cinfo[15].global_state = v7;
  err->next_input_byte = next_input_byte;
  err->bytes_in_buffer = i;
  return 1;
}


// ========================================================================
// first_marker
// EA  : 0x83213298
// RVA : 0x01213298
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall first_marker(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // r31
  unsigned int bytes_in_buffer; // r10
  const unsigned __int8 *next_input_byte; // r11
  int v6; // r28
  unsigned int v7; // r10
  const unsigned __int8 *v8; // r11
  int v9; // r30
  unsigned int v10; // r27
  const unsigned __int8 *v11; // r26

  err = (jpeg_source_mgr *)cinfo[1].err;
  bytes_in_buffer = err->bytes_in_buffer;
  next_input_byte = err->next_input_byte;
  if ( bytes_in_buffer == 0 )
  {
    if ( ((unsigned __int8 (*)(void))err->fill_input_buffer)() == 0 )
      return 0;
    next_input_byte = err->next_input_byte;
    bytes_in_buffer = err->bytes_in_buffer;
  }
  v6 = *next_input_byte;
  v7 = bytes_in_buffer - 1;
  v8 = next_input_byte + 1;
  if ( v7 == 0 )
  {
    if ( err->fill_input_buffer(a1: (jpeg_decompress_struct *)cinfo) == 0 )
      return 0;
    v8 = err->next_input_byte;
    v7 = err->bytes_in_buffer;
  }
  v9 = *v8;
  v10 = v7 - 1;
  v11 = v8 + 1;
  if ( v6 != 255 || v9 != 216 )
  {
    cinfo->err->msg_code = 53;
    cinfo->err->msg_parm.i[0] = v6;
    cinfo->err->msg_parm.i[1] = v9;
    cinfo->err->error_exit(a1: cinfo);
  }
  cinfo[15].global_state = v9;
  err->next_input_byte = v11;
  err->bytes_in_buffer = v10;
  return 1;
}


// ========================================================================
// read_markers
// EA  : 0x83213380
// RVA : 0x01213380
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall read_markers(jpeg_common_struct *cinfo)
{
  char v2; // r3
  int global_state; // r11
  bool v4; // cr58
  unsigned int v5; // r11
  int result; // r3

  while ( 1 )
  {
    while ( 1 )
    {
      if ( cinfo[15].global_state == 0 )
      {
        v2 = *(_BYTE *)(cinfo[16].global_state + 12) != 0 ? next_marker(cinfo) : first_marker(cinfo);
        if ( v2 == 0 )
          return 0;
      }
      global_state = cinfo[15].global_state;
      if ( global_state > 207 )
        break;
      if ( global_state >= 205 )
        goto LABEL_25;
      if ( global_state > 200 )
      {
        v5 = global_state - 201;
        if ( v5 > 3 )
          goto LABEL_39;
        switch ( v5 )
        {
          case 1u:
            v4 = (unsigned __int8)get_sof(cinfo, is_prog: 1u, is_arith: 1u) == 0;
            goto LABEL_41;
          case 2u:
            goto LABEL_25;
          case 0u:
            v4 = (unsigned __int8)get_sof(cinfo, is_prog: 0, is_arith: 1u) == 0;
            goto LABEL_41;
          default:
            break;
        }
LABEL_24:
        v4 = (unsigned __int8)skip_variable(cinfo) == 0;
        goto LABEL_41;
      }
      if ( global_state >= 197 )
        goto LABEL_25;
      if ( global_state > 194 )
      {
        if ( global_state != 195 )
        {
          v4 = (unsigned __int8)get_dht(cinfo) == 0;
          goto LABEL_41;
        }
LABEL_25:
        cinfo->err->msg_code = 60;
        cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
        cinfo->err->error_exit(a1: cinfo);
        cinfo[15].global_state = 0;
      }
      else
      {
        if ( global_state == 194 )
        {
          v4 = (unsigned __int8)get_sof(cinfo, is_prog: 1u, is_arith: 0) == 0;
          goto LABEL_41;
        }
        if ( global_state == 1 )
        {
LABEL_30:
          cinfo->err->msg_code = 92;
          cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
          cinfo->err->emit_message(a1: cinfo, a2: 1);
          cinfo[15].global_state = 0;
        }
        else
        {
          if ( global_state > 191 )
          {
            v4 = (unsigned __int8)get_sof(cinfo, is_prog: 0, is_arith: 0) == 0;
            goto LABEL_41;
          }
LABEL_39:
          cinfo->err->msg_code = 68;
          cinfo->err->msg_parm.i[0] = cinfo[15].global_state;
          cinfo->err->error_exit(a1: cinfo);
          cinfo[15].global_state = 0;
        }
      }
    }
    if ( global_state <= 219 )
      break;
    if ( global_state > 239 )
    {
      if ( global_state != 254 )
        goto LABEL_39;
      v4 = (*(unsigned __int8 (__fastcall **)(jpeg_common_struct *))(cinfo[16].global_state + 24))(a1: cinfo) == 0;
    }
    else if ( global_state >= 224 )
    {
      v4 = (*(unsigned __int8 (__fastcall **)(jpeg_common_struct *))(4 * (global_state - 217) + cinfo[16].global_state))(a1: cinfo) == 0;
    }
    else
    {
      if ( global_state == 220 )
        goto LABEL_24;
      if ( global_state != 221 )
        goto LABEL_39;
      v4 = (unsigned __int8)get_dri(cinfo) == 0;
    }
LABEL_41:
    if ( v4 )
      return 0;
    cinfo[15].global_state = 0;
  }
  if ( global_state == 219 )
  {
    v4 = (unsigned __int8)get_dqt(cinfo) == 0;
    goto LABEL_41;
  }
  switch ( global_state )
  {
    case 208:
    case 209:
    case 210:
    case 211:
    case 212:
    case 213:
    case 214:
    case 215:
      goto LABEL_30;
    case 216:
      v4 = (unsigned __int8)get_soi(cinfo) == 0;
      goto LABEL_41;
    case 217:
      cinfo->err->msg_code = 85;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      cinfo[15].global_state = 0;
      result = 2;
      break;
    case 218:
      if ( (unsigned __int8)get_sos(cinfo) == 0 )
        return 0;
      cinfo[15].global_state = 0;
      result = 1;
      break;
  }
  return result;
}


// ========================================================================
// read_restart_marker
// EA  : 0x832136F0
// RVA : 0x012136F0
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall read_restart_marker(jpeg_common_struct *cinfo)
{
  if ( cinfo[15].global_state == 0 && (unsigned __int8)next_marker(cinfo) == 0 )
    return 0;
  if ( cinfo[15].global_state == *(_DWORD *)(cinfo[16].global_state + 16) + 208 )
  {
    cinfo->err->msg_code = 98;
    cinfo->err->msg_parm.i[0] = *(_DWORD *)(cinfo[16].global_state + 16);
    cinfo->err->emit_message(a1: cinfo, a2: 3);
    cinfo[15].global_state = 0;
  }
  else if ( ((unsigned __int8 (__fastcall *)(jpeg_common_struct *))cinfo[1].err->msg_code)(a1: cinfo) == 0 )
  {
    return 0;
  }
  *(_DWORD *)(cinfo[16].global_state + 16) = (*(_DWORD *)(cinfo[16].global_state + 16) + 1) & 7;
  return 1;
}


// ========================================================================
// ?jpeg_resync_to_restart@@YAEPAUjpeg_decompress_struct@@H@Z
// EA  : 0x832137E0
// RVA : 0x012137E0
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

int __fastcall jpeg_resync_to_restart(jpeg_common_struct *cinfo, int desired)
{
  int global_state; // r30
  char v3; // r28
  int v5; // r31

  global_state = cinfo[15].global_state;
  v3 = desired;
  cinfo->err->msg_code = 121;
  cinfo->err->msg_parm.i[0] = global_state;
  cinfo->err->msg_parm.i[1] = desired;
  cinfo->err->emit_message(a1: cinfo, a2: -1);
  while ( 1 )
  {
    if ( global_state < 192 )
    {
LABEL_3:
      v5 = 2;
      goto LABEL_12;
    }
    if ( global_state < 208
      || global_state > 215
      || global_state == ((v3 + 1) & 7) + 208
      || global_state == ((v3 + 2) & 7) + 208 )
    {
      v5 = 3;
    }
    else
    {
      if ( global_state == ((v3 - 1) & 7) + 208 || global_state == ((v3 - 2) & 7) + 208 )
        goto LABEL_3;
      v5 = 1;
    }
LABEL_12:
    cinfo->err->msg_code = 97;
    cinfo->err->msg_parm.i[0] = global_state;
    cinfo->err->msg_parm.i[1] = v5;
    cinfo->err->emit_message(a1: cinfo, a2: 4);
    if ( v5 == 1 )
      break;
    if ( v5 != 2 )
      return 1;
    if ( (unsigned __int8)next_marker(cinfo) == 0 )
      return 0;
    global_state = cinfo[15].global_state;
  }
  cinfo[15].global_state = 0;
  return 1;
}


// ========================================================================
// reset_marker_reader
// EA  : 0x83213938
// RVA : 0x01213938
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

void __fastcall reset_marker_reader(jpeg_decompress_struct *cinfo)
{
  jpeg_d_main_controller *main; // r10

  main = cinfo->main;
  cinfo->ac_huff_tbl_ptrs[1] = nullptr;
  cinfo->rec_outbuf_height = 0;
  cinfo->Ss = 0;
  HIBYTE(main[1].process_data) = 0;
  BYTE1(main[1].process_data) = 0;
  main[2].process_data = nullptr;
  main[20].start_pass = nullptr;
}


// ========================================================================
// ?jinit_marker_reader@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x83213960
// RVA : 0x01213960
// PDB : w:\tech5\libs\jpeg\jdmarker.cpp
// ========================================================================

void __fastcall jinit_marker_reader(jpeg_decompress_struct *cinfo)
{
  jpeg_d_main_controller *v2; // r3
  void (__fastcall **p_process_data)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // r10
  int i; // ctr
  jpeg_d_main_controller *main; // r6

  v2 = (jpeg_d_main_controller *)((int (*)(void))cinfo->mem->alloc_small)();
  cinfo->main = v2;
  v2->process_data = (void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))read_markers;
  v2->start_pass = (void (__fastcall *)(jpeg_decompress_struct *, J_BUF_MODE))reset_marker_reader;
  v2[11].process_data = nullptr;
  v2[1].start_pass = (void (__fastcall *)(jpeg_decompress_struct *, J_BUF_MODE))read_restart_marker;
  p_process_data = &v2[11].process_data;
  v2[3].start_pass = (void (__fastcall *)(jpeg_decompress_struct *, J_BUF_MODE))skip_variable;
  for ( i = 16; i != 0; --i )
  {
    *(p_process_data - 16) = (void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))skip_variable;
    *++p_process_data = nullptr;
  }
  v2[3].process_data = (void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))get_interesting_appn;
  v2[10].process_data = (void (__fastcall *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))get_interesting_appn;
  main = cinfo->main;
  cinfo->ac_huff_tbl_ptrs[1] = nullptr;
  cinfo->rec_outbuf_height = 0;
  cinfo->Ss = 0;
  HIBYTE(main[1].process_data) = 0;
  BYTE1(main[1].process_data) = 0;
  main[2].process_data = nullptr;
  main[20].start_pass = nullptr;
}

