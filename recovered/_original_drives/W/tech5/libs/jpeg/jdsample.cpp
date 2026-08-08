
// ========================================================================
// start_pass_upsample
// EA  : 0x83237E18
// RVA : 0x01237E18
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall start_pass_upsample(jpeg_decompress_struct *cinfo)
{
  jpeg_input_controller *inputctl; // r11

  inputctl = cinfo->inputctl;
  inputctl[4].finish_input_pass = *(void (__fastcall **)(jpeg_decompress_struct *))&cinfo->X_density;
  *(_DWORD *)&inputctl[4].has_multiple_scans = *(_DWORD *)&cinfo->two_pass_quantize;
}


// ========================================================================
// sep_upsample
// EA  : 0x83237E30
// RVA : 0x01237E30
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall sep_upsample(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_input_controller *inputctl; // r29
  int v12; // r28
  JHUFF_TBL *v13; // r27
  unsigned __int8 ***v14; // r26
  void (__fastcall **p_finish_input_pass)(jpeg_decompress_struct *); // r31
  unsigned int v16; // r31
  unsigned int v17; // r6
  void (__fastcall *v18)(jpeg_decompress_struct *); // r11

  inputctl = cinfo->inputctl;
  if ( (int)inputctl[4].finish_input_pass >= *(_DWORD *)&cinfo->X_density )
  {
    v12 = 0;
    v13 = cinfo->ac_huff_tbl_ptrs[1];
    if ( cinfo->num_components > 0 )
    {
      v14 = input_buf - 1;
      p_finish_input_pass = &inputctl->finish_input_pass;
      do
      {
        ((void (__fastcall *)(jpeg_decompress_struct *, JHUFF_TBL *, unsigned __int8 **, void (__fastcall **)(jpeg_decompress_struct *)))p_finish_input_pass[10])(
          a1: cinfo,
          a2: v13,
          a3: &(*++v14)[(_DWORD)p_finish_input_pass[22] * *in_row_group_ctr],
          a4: p_finish_input_pass);
        ++v12;
        ++p_finish_input_pass;
        v13 = (JHUFF_TBL *)((char *)v13 + 84);
      }
      while ( v12 < cinfo->num_components );
    }
    inputctl[4].finish_input_pass = nullptr;
  }
  v16 = *(_DWORD *)&cinfo->X_density - (unsigned int)inputctl[4].finish_input_pass;
  if ( v16 > *(_DWORD *)&inputctl[4].has_multiple_scans )
    v16 = *(_DWORD *)&inputctl[4].has_multiple_scans;
  if ( v16 > out_rows_avail - *out_row_ctr )
    v16 = out_rows_avail - *out_row_ctr;
  ((void (__fastcall *)(jpeg_decompress_struct *, void (__fastcall **)(jpeg_decompress_struct *)))cinfo->marker->read_markers)(
    a1: cinfo,
    a2: &inputctl->finish_input_pass);
  *out_row_ctr += v16;
  v17 = *(_DWORD *)&inputctl[4].has_multiple_scans - v16;
  v18 = (void (__fastcall *)(jpeg_decompress_struct *))((char *)inputctl[4].finish_input_pass + v16);
  inputctl[4].finish_input_pass = v18;
  *(_DWORD *)&inputctl[4].has_multiple_scans = v17;
  if ( (int)v18 >= *(_DWORD *)&cinfo->X_density )
    ++*in_row_group_ctr;
}


// ========================================================================
// fullsize_upsample
// EA  : 0x83237F68
// RVA : 0x01237F68
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall fullsize_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  *output_data_ptr = input_data;
}


// ========================================================================
// noop_upsample
// EA  : 0x83237F70
// RVA : 0x01237F70
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall noop_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  *output_data_ptr = nullptr;
}


// ========================================================================
// int_upsample
// EA  : 0x83237F80
// RVA : 0x01237F80
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall int_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  int v5; // r30
  char *v6; // r11
  unsigned __int8 **v7; // r25
  int v8; // r29
  int v9; // r26
  unsigned __int8 **v10; // r27
  unsigned __int32 v12; // r11
  unsigned __int32 v13; // r7
  unsigned __int8 *v14; // r8
  char v15; // r9
  unsigned __int32 v16; // r10
  int i; // ctr

  v5 = 0;
  v6 = (char *)cinfo->inputctl + compptr->component_index;
  v7 = *output_data_ptr;
  v8 = (unsigned __int8)v6[140];
  v9 = (unsigned __int8)v6[150];
  if ( *(int *)&cinfo->X_density > 0 )
  {
    v10 = *output_data_ptr;
    do
    {
      v12 = (unsigned __int32)*v10;
      v13 = (unsigned __int32)&(*v10)[cinfo->dither_mode];
      if ( (unsigned int)*v10 < v13 )
      {
        v14 = *input_data - 1;
        do
        {
          v15 = *++v14;
          if ( v8 > 0 )
          {
            v16 = v12 - 1;
            for ( i = v8; i != 0; --i )
              *(_BYTE *)++v16 = v15;
            v12 += v8;
          }
        }
        while ( v12 < v13 );
      }
      if ( v9 > 1 )
        jcopy_sample_rows(
          input_array: v7,
          source_row: v5,
          output_array: v7,
          dest_row: v5 + 1,
          num_rows: v9 - 1,
          num_cols: cinfo->dither_mode);
      v5 += v9;
      ++input_data;
      v10 += v9;
    }
    while ( v5 < *(_DWORD *)&cinfo->X_density );
  }
}


// ========================================================================
// h2v1_upsample
// EA  : 0x83238058
// RVA : 0x01238058
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall h2v1_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  int v4; // r4
  char *v5; // r7
  int v6; // r6
  _BYTE *v7; // r11
  unsigned __int32 v8; // r9
  _BYTE *v9; // r8
  char v10; // r10

  v4 = 0;
  v5 = (char *)*output_data_ptr;
  if ( *(int *)&cinfo->X_density > 0 )
  {
    v6 = (char *)input_data - v5;
    do
    {
      v7 = *(_BYTE **)v5;
      v8 = cinfo->dither_mode + *(_DWORD *)v5;
      if ( *(_DWORD *)v5 < v8 )
      {
        v9 = (_BYTE *)(*(_DWORD *)&v5[v6] - 1);
        do
        {
          v10 = *++v9;
          *v7 = *v9;
          v7[1] = v10;
          v7 += 2;
        }
        while ( (unsigned int)v7 < v8 );
      }
      ++v4;
      v5 += 4;
    }
    while ( v4 < *(_DWORD *)&cinfo->X_density );
  }
}


// ========================================================================
// h2v2_upsample
// EA  : 0x832380C0
// RVA : 0x012380C0
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall h2v2_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  unsigned __int8 **v5; // r27
  int v6; // r28
  unsigned __int8 **v7; // r30
  unsigned __int8 *v9; // r11
  unsigned __int32 v10; // r9
  unsigned __int8 *v11; // r8
  unsigned __int8 v12; // r10

  v5 = *output_data_ptr;
  v6 = 0;
  if ( *(int *)&cinfo->X_density > 0 )
  {
    v7 = *output_data_ptr;
    do
    {
      v9 = *v7;
      v10 = (unsigned __int32)&(*v7)[cinfo->dither_mode];
      if ( (unsigned int)*v7 < v10 )
      {
        v11 = *input_data - 1;
        do
        {
          v12 = *++v11;
          *v9 = *v11;
          v9[1] = v12;
          v9 += 2;
        }
        while ( (unsigned int)v9 < v10 );
      }
      jcopy_sample_rows(
        input_array: v5,
        source_row: v6,
        output_array: v5,
        dest_row: v6 + 1,
        num_rows: 1,
        num_cols: cinfo->dither_mode);
      v6 += 2;
      ++input_data;
      v7 += 2;
    }
    while ( v6 < *(_DWORD *)&cinfo->X_density );
  }
}


// ========================================================================
// h2v1_fancy_upsample
// EA  : 0x83238160
// RVA : 0x01238160
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall h2v1_fancy_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  int v4; // r31
  char *v5; // r7
  int v6; // r5
  _BYTE *v7; // r11
  _BYTE *v8; // r10
  int v9; // r9
  char *v10; // r11
  _BYTE *v11; // r10
  unsigned int v12; // ctr
  int v13; // r9
  int v14; // r9
  char v15; // r6

  v4 = 0;
  v5 = (char *)*output_data_ptr;
  if ( *(int *)&cinfo->X_density > 0 )
  {
    v6 = (char *)input_data - v5;
    do
    {
      v7 = *(_BYTE **)&v5[v6];
      v8 = *(_BYTE **)v5;
      v9 = (unsigned __int8)*v7;
      *v8 = *v7;
      v10 = v7 + 1;
      v8[1] = (v9 + __ROL4__(v9, 1) + (unsigned __int8)*v10 + 2) >> 2;
      v11 = v8 + 2;
      if ( compptr->downsampled_width != 2 )
      {
        v12 = compptr->downsampled_width - 2;
        do
        {
          v13 = (unsigned __int8)*v10++;
          v14 = v13 + __ROL4__(v13, 1);
          *v11 = ((unsigned __int8)*(v10 - 2) + v14 + 1) >> 2;
          v11[1] = ((unsigned __int8)*v10 + v14 + 2) >> 2;
          v11 += 2;
          --v12;
        }
        while ( v12 != 0 );
      }
      ++v4;
      v5 += 4;
      v15 = *v10;
      *v11 = ((unsigned __int8)*(v10 - 1) + (unsigned __int8)*v10 + __ROL4__((unsigned __int8)*v10, 1) + 1) >> 2;
      v11[1] = v15;
    }
    while ( v4 < *(_DWORD *)&cinfo->X_density );
  }
}


// ========================================================================
// h2v2_fancy_upsample
// EA  : 0x83238250
// RVA : 0x01238250
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall h2v2_fancy_upsample(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **input_data,
        unsigned __int8 ***output_data_ptr)
{
  int v4; // r28
  int i; // r24
  int v7; // r26
  _BYTE **v8; // r27
  unsigned __int8 *v9; // r8
  unsigned __int8 *v10; // r11
  int v11; // r9
  unsigned __int8 *v12; // r8
  int v13; // r5
  unsigned __int8 *v14; // r11
  int v15; // r9
  int v16; // r10
  unsigned __int8 *v17; // r31
  _BYTE *v18; // r11
  int v19; // r7
  unsigned __int8 *v20; // r6
  unsigned int downsampled_width; // r9
  unsigned int v22; // r8
  _BYTE *v23; // r11
  int v24; // r9
  bool v25; // zf
  unsigned int v26; // ctr
  unsigned __int8 *v27; // r5
  unsigned __int8 *v28; // r6
  int v29; // r8

  v4 = 0;
  for ( i = (int)*output_data_ptr; v4 < *(_DWORD *)&cinfo->X_density; ++input_data )
  {
    v7 = 0;
    v8 = (_BYTE **)(4 * v4 + i - 4);
    do
    {
      v9 = *input_data;
      if ( v7 != 0 )
        v10 = input_data[1];
      else
        v10 = *(input_data - 1);
      v11 = *v9;
      ++v4;
      v12 = v9 + 1;
      v13 = *v10;
      v14 = v10 + 1;
      v15 = v11 + __ROL4__(v11, 1) + v13;
      v16 = *v12 + __ROL4__(*v12, 1) + *v14;
      v17 = v14 + 1;
      v18 = *++v8;
      *v18 = (4 * (v15 + 2)) >> 4;
      v19 = v15;
      v18[1] = (3 * v15 + v16 + 7) >> 4;
      v20 = v12 + 1;
      downsampled_width = compptr->downsampled_width;
      v22 = downsampled_width - 2;
      v23 = v18 + 2;
      v25 = downsampled_width == 2;
      v24 = v16;
      if ( !v25 )
      {
        v26 = v22;
        v27 = v17 - 1;
        v28 = v20 - 1;
        do
        {
          ++v28;
          v16 = *v28 + __ROL4__(*v28, 1) + *++v27;
          v29 = 3 * v24 + v16 + 7;
          *v23 = (3 * v24 + v19 + 8) >> 4;
          v19 = v24;
          v24 = v16;
          v23[1] = v29 >> 4;
          v23 += 2;
          --v26;
        }
        while ( v26 != 0 );
      }
      ++v7;
      *v23 = (3 * v16 + v19 + 8) >> 4;
      v23[1] = (4 * v16 + 7) >> 4;
    }
    while ( v7 < 2 );
  }
}


// ========================================================================
// ?jinit_upsampler@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x832383C0
// RVA : 0x012383C0
// PDB : w:\tech5\libs\jpeg\jdsample.cpp
// ========================================================================

void __fastcall jinit_upsampler(jpeg_common_struct *cinfo)
{
  int v2; // r3
  int v3; // r26
  char v4; // r23
  int v5; // r27
  unsigned __int8 *p_free_pool; // r29
  _DWORD *v7; // r30
  char v8; // r28
  signed int v9; // r6
  int v10; // r5
  jpeg_progress_mgr *progress; // r10
  int client_data; // r9
  signed int v13; // r11
  int v14; // r3
  signed int v15; // r8
  jpeg_memory_mgr *mem; // r28
  void *v17; // r22
  int v18; // r3

  v2 = ((int (*)(void))cinfo->mem->alloc_small)();
  cinfo[17].progress = (jpeg_progress_mgr *)v2;
  *(_DWORD *)v2 = start_pass_upsample;
  *(_DWORD *)(v2 + 4) = sep_upsample;
  v3 = v2;
  *(_BYTE *)(v2 + 8) = 0;
  if ( BYTE2(cinfo[11].err) != 0 )
  {
    cinfo->err->msg_code = 25;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( HIBYTE(cinfo[3].err) == 0 || (v4 = 1, *(int *)&cinfo[11].is_decompressor <= 1) )
    v4 = 0;
  v5 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (unsigned __int8 *)&cinfo[8].mem->free_pool;
    v7 = (_DWORD *)(v3 + 52);
    do
    {
      v8 = 1;
      v9 = *(_DWORD *)&cinfo[11].is_decompressor;
      v10 = *((_DWORD *)p_free_pool - 6) * *(_DWORD *)p_free_pool;
      progress = cinfo[11].progress;
      client_data = (int)cinfo[11].client_data;
      v13 = v10 / v9;
      v14 = *((_DWORD *)p_free_pool - 7) * *(_DWORD *)p_free_pool;
      v7[12] = v10 / v9;
      __twllei(v9, 0);
      v15 = v14 / v9;
      __twllei(v9, 0);
      __twlgei(v9 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
      __twlgei(v9 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
      if ( p_free_pool[12] != 0 )
      {
        if ( (jpeg_progress_mgr *)v15 == progress && v13 == client_data )
        {
          v8 = 0;
          *v7 = fullsize_upsample;
        }
        else
        {
          if ( (jpeg_progress_mgr *)(2 * v15) != progress )
            goto LABEL_25;
          if ( v13 == client_data )
          {
            if ( v4 != 0 && *((_DWORD *)p_free_pool + 1) > 2u )
              *v7 = h2v1_fancy_upsample;
            else
              *v7 = h2v1_upsample;
          }
          else
          {
            if ( (jpeg_progress_mgr *)(2 * v15) != progress || 2 * v13 != client_data )
            {
LABEL_25:
              __twllei(v15, 0);
              __twlgei(v15 & ~(__ROL4__(progress, 1) - 1), 0xFFFFFFFF);
              if ( (int)progress % v15 != 0
                || (__twllei(v13, 0), __twlgei(v13 & ~(__ROL4__(client_data, 1) - 1), 0xFFFFFFFF),
                                      client_data % v13 != 0) )
              {
                cinfo->err->msg_code = 38;
                cinfo->err->error_exit(a1: cinfo);
              }
              else
              {
                *v7 = int_upsample;
                *(_BYTE *)(v5 + v3 + 140) = (int)progress / v15;
                __twllei(v15, 0);
                *(_BYTE *)(v5 + v3 + 150) = client_data / v13;
                __twllei(v13, 0);
                __twlgei(v15 & ~(__ROL4__(progress, 1) - 1), 0xFFFFFFFF);
                __twlgei(v13 & ~(__ROL4__(client_data, 1) - 1), 0xFFFFFFFF);
              }
              goto LABEL_29;
            }
            if ( v4 != 0 && *((_DWORD *)p_free_pool + 1) > 2u )
            {
              *v7 = h2v2_fancy_upsample;
              *(_BYTE *)(v3 + 8) = 1;
            }
            else
            {
              *v7 = h2v2_upsample;
            }
          }
        }
      }
      else
      {
        v8 = 0;
        *v7 = noop_upsample;
      }
LABEL_29:
      if ( v8 != 0 )
      {
        mem = cinfo->mem;
        v17 = cinfo[11].client_data;
        v18 = jround_up(a: cinfo[3].global_state, b: (int)cinfo[11].progress);
        *(v7 - 10) = mem->alloc_sarray(a1: cinfo, a2: 1, a3: v18, a4: (unsigned int)v17);
      }
      ++v5;
      ++v7;
      p_free_pool += 84;
    }
    while ( v5 < (int)cinfo[1].client_data );
  }
}

