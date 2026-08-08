
// ========================================================================
// alloc_funny_pointers
// EA  : 0x83233D98
// RVA : 0x01233D98
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall alloc_funny_pointers(jpeg_common_struct *cinfo)
{
  int mem; // r27
  int v3; // r30
  int v4; // r3
  int v5; // r28
  int v6; // r26
  int v7; // r30
  unsigned __int8 *p_alloc_large; // r29
  int v9; // r10
  int v10; // r8
  signed int v11; // r7
  void *(__fastcall *alloc_small)(jpeg_common_struct *, int, unsigned int); // ctr
  int v13; // r24
  int v14; // r11

  mem = (int)cinfo[16].mem;
  v3 = *(_DWORD *)&cinfo[11].is_decompressor;
  v4 = ((int (*)(void))cinfo->mem->alloc_small)();
  *(_DWORD *)(mem + 56) = v4;
  v5 = 0;
  *(_DWORD *)(mem + 60) = 4 * (int)cinfo[1].client_data + v4;
  if ( (int)cinfo[1].client_data > 0 )
  {
    v6 = v3 + 4;
    v7 = 0;
    p_alloc_large = (unsigned __int8 *)&cinfo[8].mem[-1].alloc_large;
    do
    {
      v9 = *((_DWORD *)p_alloc_large + 15);
      p_alloc_large += 84;
      v10 = v9 * *(_DWORD *)p_alloc_large;
      v11 = *(_DWORD *)&cinfo[11].is_decompressor;
      alloc_small = cinfo->mem->alloc_small;
      v13 = v6 * (v10 / v11);
      __twllei(v11, 0);
      __twlgei(v11 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
      v14 = (int)alloc_small(a1: cinfo, a2: 1, a3: 8 * v13) + 4 * (v10 / v11);
      ++v5;
      *(_DWORD *)(*(_DWORD *)(mem + 56) + v7) = v14;
      *(_DWORD *)(v7 + *(_DWORD *)(mem + 60)) = 4 * v13 + v14;
      v7 += 4;
    }
    while ( v5 < (int)cinfo[1].client_data );
  }
}


// ========================================================================
// make_funny_pointers
// EA  : 0x83233E88
// RVA : 0x01233E88
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall make_funny_pointers(jpeg_decompress_struct *cinfo)
{
  int v1; // r26
  int Ah; // r30
  int v3; // r27
  int v4; // r5
  unsigned __int8 *v5; // r31
  int v6; // r9
  signed int v7; // r6
  int v8; // r8
  char *v9; // r4
  _DWORD *v10; // r10
  int v11; // r7
  int v12; // r11
  int v13; // r9
  int v14; // ctr
  _DWORD *v15; // r11
  int v16; // r25
  int v17; // r11
  int v18; // ctr
  int v19; // r25
  int v20; // r24
  int v21; // ctr
  char *v22; // r11

  v1 = 0;
  Ah = cinfo->Ah;
  v3 = *(_DWORD *)&cinfo->saw_Adobe_marker;
  if ( cinfo->num_components > 0 )
  {
    v4 = 0;
    v5 = &cinfo->ac_huff_tbl_ptrs[1]->bits[12];
    do
    {
      v6 = *(_DWORD *)v5 * *((_DWORD *)v5 + 6);
      v7 = *(_DWORD *)&cinfo->saw_Adobe_marker;
      v8 = *(_DWORD *)(Ah + 8 + v4);
      v9 = *(char **)(v4 + *(_DWORD *)(Ah + 56));
      v10 = *(_DWORD **)(v4 + *(_DWORD *)(Ah + 60));
      v11 = v6 / v7;
      v12 = __ROL4__(v6, 1) - 1;
      __twllei(v7, 0);
      v13 = (v3 + 2) * (v6 / v7);
      __twlgei(v7 & ~v12, 0xFFFFFFFF);
      if ( v13 > 0 )
      {
        v14 = v13;
        v15 = v10;
        do
        {
          v16 = *(_DWORD *)((char *)v15 + v8 - (_DWORD)v10);
          *v15 = v16;
          *(_DWORD *)((char *)v15++ + v9 - (char *)v10) = v16;
          --v14;
        }
        while ( v14 != 0 );
      }
      v17 = 0;
      if ( 2 * v11 > 0 )
      {
        v18 = 2 * v11;
        do
        {
          v19 = v11 * v3 + v17;
          v20 = (v3 - 2) * v11 + v17++;
          v10[v20] = *(_DWORD *)(v19 * 4 + v8);
          v10[v19] = *(_DWORD *)(v20 * 4 + v8);
          --v18;
        }
        while ( v18 != 0 );
      }
      if ( v11 > 0 )
      {
        v21 = v11;
        v22 = &v9[-4 * v11 - 4];
        do
        {
          v22 += 4;
          *(_DWORD *)v22 = *(_DWORD *)v9;
          --v21;
        }
        while ( v21 != 0 );
      }
      ++v1;
      v4 += 4;
      v5 += 84;
    }
    while ( v1 < cinfo->num_components );
  }
}


// ========================================================================
// set_wraparound_pointers
// EA  : 0x83233FB0
// RVA : 0x01233FB0
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall set_wraparound_pointers(jpeg_decompress_struct *cinfo)
{
  int v1; // r27
  int Ah; // r29
  int v3; // r28
  int v4; // r31
  unsigned __int8 *v5; // r30
  int v6; // r8
  signed int v7; // r6
  int v8; // r5
  _DWORD *v9; // r9
  int v10; // r7
  int v11; // r11
  int v12; // ctr
  int v13; // r5
  int v14; // r4
  _DWORD *v15; // r10
  _DWORD *v16; // r11
  int v17; // r6
  int v18; // r26
  int v19; // r25

  v1 = 0;
  Ah = cinfo->Ah;
  v3 = *(_DWORD *)&cinfo->saw_Adobe_marker;
  if ( cinfo->num_components > 0 )
  {
    v4 = 0;
    v5 = &cinfo->ac_huff_tbl_ptrs[1]->bits[12];
    do
    {
      v6 = 0;
      v7 = *(_DWORD *)&cinfo->saw_Adobe_marker;
      v8 = *(_DWORD *)v5 * *((_DWORD *)v5 + 6);
      v9 = *(_DWORD **)(v4 + *(_DWORD *)(Ah + 60));
      v10 = *(_DWORD *)(v4 + *(_DWORD *)(Ah + 56));
      v11 = v8 / v7;
      __twllei(v7, 0);
      __twlgei(v7 & ~(__ROL4__(v8, 1) - 1), 0xFFFFFFFF);
      if ( v8 / v7 > 0 )
      {
        v12 = v8 / v7;
        v13 = (v3 + 1) * v11;
        v14 = (v3 + 2) * v11;
        v15 = v9;
        v16 = &v9[-v11];
        v17 = v10 - (_DWORD)v9;
        do
        {
          v18 = v13 + v6;
          v19 = v14 + v6++;
          *(_DWORD *)((char *)v16 + v17) = *(_DWORD *)(v18 * 4 + v10);
          *v16++ = v9[v18];
          *(_DWORD *)(v19 * 4 + v10) = *(_DWORD *)((char *)v15 + v17);
          v9[v19] = *v15++;
          --v12;
        }
        while ( v12 != 0 );
      }
      ++v1;
      v4 += 4;
      v5 += 84;
    }
    while ( v1 < cinfo->num_components );
  }
}


// ========================================================================
// set_bottom_pointers
// EA  : 0x832340A0
// RVA : 0x012340A0
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall set_bottom_pointers(jpeg_decompress_struct *cinfo)
{
  int v1; // r5
  int Ah; // r6
  unsigned __int8 *v3; // r7
  unsigned int v4; // r9
  unsigned int v5; // r11
  signed int v6; // r8
  int v7; // r9
  signed int v8; // r10
  int v9; // ctr
  int v10; // r11
  _DWORD *v11; // r10

  v1 = 0;
  Ah = cinfo->Ah;
  if ( cinfo->num_components > 0 )
  {
    v3 = &cinfo->ac_huff_tbl_ptrs[1]->bits[12];
    do
    {
      v4 = *((_DWORD *)v3 + 8);
      v5 = *(_DWORD *)v3 * *((_DWORD *)v3 + 6);
      v6 = *(_DWORD *)&cinfo->saw_Adobe_marker;
      __twllei(v5, 0);
      v7 = v4 % v5;
      v8 = (int)v5 / v6;
      __twllei(v6, 0);
      __twlgei(v6 & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
      if ( v7 == 0 )
        v7 = v5;
      if ( v1 == 0 )
      {
        __twllei(v8, 0);
        *(_DWORD *)(Ah + 72) = (v7 - 1) / v8 + 1;
        __twlgei(v8 & ~(__ROL4__(v7 - 1, 1) - 1), 0xFFFFFFFF);
      }
      if ( 2 * v8 > 0 )
      {
        v9 = 2 * v8;
        v10 = 4 * v7 + *(_DWORD *)(*(_DWORD *)(4 * (*(_DWORD *)(Ah + 64) + 14) + Ah) + 4 * v1);
        v11 = (_DWORD *)(v10 - 4);
        do
        {
          *++v11 = *(_DWORD *)(v10 - 4);
          --v9;
        }
        while ( v9 != 0 );
      }
      ++v1;
      v3 += 84;
    }
    while ( v1 < cinfo->num_components );
  }
}


// ========================================================================
// process_data_simple_main
// EA  : 0x83234190
// RVA : 0x01234190
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall process_data_simple_main(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  int Ah; // r30
  unsigned int v9; // r25

  Ah = cinfo->Ah;
  if ( *(_BYTE *)(Ah + 48) == 0 )
  {
    if ( (*(int (**)(void))(cinfo->Al + 12))() == 0 )
      return;
    *(_BYTE *)(Ah + 48) = 1;
  }
  v9 = *(_DWORD *)&cinfo->saw_Adobe_marker;
  (*(void (__fastcall **)(jpeg_decompress_struct *, int, int, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))(cinfo->unread_marker + 4))(
    a1: cinfo,
    a2: Ah + 8,
    a3: Ah + 52,
    a4: v9,
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
  if ( *(_DWORD *)(Ah + 52) >= v9 )
  {
    *(_BYTE *)(Ah + 48) = 0;
    *(_DWORD *)(Ah + 52) = 0;
  }
}


// ========================================================================
// process_data_context_main
// EA  : 0x83234238
// RVA : 0x01234238
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall process_data_context_main(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  int Ah; // r31
  int v9; // r11
  unsigned int v10; // r11
  jpeg_marker_struct *v11; // r10
  int v12; // r11
  int v13; // r7

  Ah = cinfo->Ah;
  if ( *(_BYTE *)(Ah + 48) == 0 )
  {
    if ( (*(int (**)(void))(cinfo->Al + 12))() == 0 )
      return;
    v9 = *(_DWORD *)(Ah + 76);
    *(_BYTE *)(Ah + 48) = 1;
    *(_DWORD *)(Ah + 76) = v9 + 1;
  }
  v10 = *(_DWORD *)(Ah + 68);
  if ( v10 == 0 )
  {
LABEL_9:
    *(_DWORD *)(Ah + 52) = 0;
    v11 = *(jpeg_marker_struct **)(Ah + 76);
    *(_DWORD *)(Ah + 72) = *(_DWORD *)&cinfo->saw_Adobe_marker - 1;
    if ( v11 == cinfo->marker_list )
      set_bottom_pointers(cinfo);
    *(_DWORD *)(Ah + 68) = 1;
    goto LABEL_12;
  }
  if ( v10 != 1 )
  {
    if ( v10 >= 3 )
      return;
    (*(void (__fastcall **)(jpeg_decompress_struct *, _DWORD, int, _DWORD, unsigned __int8 **, unsigned int *, unsigned int))(cinfo->unread_marker + 4))(
      a1: cinfo,
      a2: *(_DWORD *)(4 * (*(_DWORD *)(Ah + 64) + 14) + Ah),
      a3: Ah + 52,
      a4: *(_DWORD *)(Ah + 72),
      a5: output_buf,
      a6: out_row_ctr,
      a7: out_rows_avail);
    if ( *(_DWORD *)(Ah + 52) < *(_DWORD *)(Ah + 72) )
      return;
    *(_DWORD *)(Ah + 68) = 0;
    if ( *out_row_ctr >= out_rows_avail )
      return;
    goto LABEL_9;
  }
LABEL_12:
  (*(void (__fastcall **)(jpeg_decompress_struct *, _DWORD, int, _DWORD, unsigned __int8 **, unsigned int *, unsigned int))(cinfo->unread_marker + 4))(
    a1: cinfo,
    a2: *(_DWORD *)(4 * (*(_DWORD *)(Ah + 64) + 14) + Ah),
    a3: Ah + 52,
    a4: *(_DWORD *)(Ah + 72),
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
  if ( *(_DWORD *)(Ah + 52) >= *(_DWORD *)(Ah + 72) )
  {
    if ( *(_DWORD *)(Ah + 76) == 1 )
      set_wraparound_pointers(cinfo);
    v12 = *(_DWORD *)(Ah + 64);
    *(_BYTE *)(Ah + 48) = 0;
    *(_DWORD *)(Ah + 64) = v12 ^ 1;
    *(_DWORD *)(Ah + 52) = *(_DWORD *)&cinfo->saw_Adobe_marker + 1;
    v13 = *(_DWORD *)&cinfo->saw_Adobe_marker + 2;
    *(_DWORD *)(Ah + 68) = 2;
    *(_DWORD *)(Ah + 72) = v13;
  }
}


// ========================================================================
// process_data_crank_post
// EA  : 0x832343E0
// RVA : 0x012343E0
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall process_data_crank_post(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  (*(void (**)(void))(cinfo->unread_marker + 4))();
}


// ========================================================================
// start_pass_main
// EA  : 0x83234408
// RVA : 0x01234408
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall start_pass_main(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  int mem; // r31

  mem = (int)cinfo[16].mem;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      *(_DWORD *)(mem + 4) = process_data_crank_post;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else
  {
    if ( HIBYTE(cinfo[17].progress->pass_limit) != 0 )
    {
      *(_DWORD *)(mem + 4) = process_data_context_main;
      make_funny_pointers((jpeg_decompress_struct *)cinfo);
      *(_DWORD *)(mem + 64) = 0;
      *(_DWORD *)(mem + 68) = 0;
      *(_DWORD *)(mem + 76) = 0;
    }
    else
    {
      *(_DWORD *)(mem + 4) = process_data_simple_main;
    }
    *(_BYTE *)(mem + 48) = 0;
    *(_DWORD *)(mem + 52) = 0;
  }
}


// ========================================================================
// ?jinit_d_main_controller@@YAXPAUjpeg_decompress_struct@@E@Z
// EA  : 0x832344C0
// RVA : 0x012344C0
// PDB : w:\tech5\libs\jpeg\jdmainct.cpp
// ========================================================================

void __fastcall jinit_d_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  void (__fastcall **v4)(jpeg_common_struct *, J_BUF_MODE); // r3
  void (__fastcall **v5)(jpeg_common_struct *, J_BUF_MODE); // r28
  int v6; // r27
  int v7; // r29
  int *p_max_alloc_chunk; // r30
  _DWORD *v9; // r28
  int v10; // r9
  signed int v11; // r5
  int v12; // r6
  int v13; // r11
  unsigned __int8 **(__fastcall *alloc_sarray)(jpeg_common_struct *, int, unsigned int, unsigned int); // ctr

  v4 = (void (__fastcall **)(jpeg_common_struct *, J_BUF_MODE))((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[16].mem = (jpeg_memory_mgr *)v4;
  v5 = v4;
  *v4 = start_pass_main;
  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( HIBYTE(cinfo[17].progress->pass_limit) != 0 )
  {
    if ( *(int *)&cinfo[11].is_decompressor < 2 )
    {
      cinfo->err->msg_code = 47;
      cinfo->err->error_exit(a1: cinfo);
    }
    alloc_funny_pointers(cinfo);
    v6 = *(_DWORD *)&cinfo[11].is_decompressor + 2;
  }
  else
  {
    v6 = *(_DWORD *)&cinfo[11].is_decompressor;
  }
  v7 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_max_alloc_chunk = &cinfo[8].mem[-2].max_alloc_chunk;
    v9 = v5 + 1;
    do
    {
      v10 = p_max_alloc_chunk[23];
      v11 = *(_DWORD *)&cinfo[11].is_decompressor;
      v12 = p_max_alloc_chunk[17] * v10;
      p_max_alloc_chunk += 21;
      v13 = *p_max_alloc_chunk;
      alloc_sarray = cinfo->mem->alloc_sarray;
      __twllei(v11, 0);
      __twlgei(v11 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
      ++v7;
      *++v9 = alloc_sarray(a1: cinfo, a2: 1, a3: v13 * v10, a4: v12 / v11 * v6);
    }
    while ( v7 < (int)cinfo[1].client_data );
  }
}

