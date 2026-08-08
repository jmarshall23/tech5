
// ========================================================================
// __make_jxr
// EA  : 0x82903D48
// RVA : 0x00903D48
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

jxr_image *__fastcall _make_jxr(jxr_image *buffer)
{
  jxr_image *v1; // r31
  __int64 v2; // r11
  int v3; // ctr
  unsigned int *p_num_lp_qps; // r10
  int i; // ctr
  int v6; // r10

  v1 = buffer;
  if ( buffer != nullptr )
  {
    memset(Dst: buffer, Val: 0, Size: sizeof(jxr_image));
    LODWORD(v2) = 0;
    v1->user_flags = 0;
    v1->width1 = 0;
    HIDWORD(v2) = &v1->mb_row_context[15];
    v1->height1 = 0;
    v3 = 20;
    v1->extended_width = 0;
    v1->extended_height = 0;
    *(_WORD *)&v1->header_flags1 = 128;
    v1->header_flags_fmt = 0;
    v1->bands_present = 0;
    v1->num_channels = 0;
    v1->tile_index_table = nullptr;
    v1->tile_index_table_length = v2;
    v1->tile_column_width = nullptr;
    v1->tile_row_height = nullptr;
    v1->primary = 1;
    do
    {
      *(_QWORD *)(HIDWORD(v2) + 4) = 0;
      *(_QWORD *)(HIDWORD(v2) + 12) = 0;
      HIDWORD(v2) += 20;
      *(_DWORD *)HIDWORD(v2) = 0;
      --v3;
    }
    while ( v3 != 0 );
    p_num_lp_qps = &v1->num_lp_qps;
    for ( i = 16; i != 0; --i )
    {
      p_num_lp_qps[3] = 0;
      p_num_lp_qps[4] = 0;
      p_num_lp_qps[5] = 0;
      p_num_lp_qps[6] = 0;
      p_num_lp_qps += 7;
      *p_num_lp_qps = 0;
    }
    v6 = *((_DWORD *)v1 + 26);
    v1->out_fun = nullptr;
    *((_DWORD *)v1 + 26) = v6 | 0x80000000;
    return v1;
  }
  return buffer;
}


// ========================================================================
// ?jxr_image_size@@YAHXZ
// EA  : 0x82903E40
// RVA : 0x00903E40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

int __fastcall jxr_image_size()
{
  return 2752;
}


// ========================================================================
// ?jxr_create_input@@YAPAUjxr_image@@PAX@Z
// EA  : 0x82903E48
// RVA : 0x00903E48
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

// attributes: thunk
jxr_image *__fastcall jxr_create_input(jxr_image *buffer)
{
  return _make_jxr(buffer);
}


// ========================================================================
// ?jxr_create_image@@YAPAUjxr_image@@HHPAEPAX@Z
// EA  : 0x82903E50
// RVA : 0x00903E50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

jxr_image *__fastcall jxr_create_image(int width, int height, unsigned __int8 *windowing, jxr_image *buffer)
{
  jxr_image *result; // r3
  unsigned __int8 v8; // r6
  char v9; // r4
  int v10; // r6
  int v11; // r11

  if ( width == 0 || height == 0 )
    return nullptr;
  result = _make_jxr(buffer);
  if ( *windowing == 1 )
  {
    v8 = windowing[3];
    v9 = v8 + windowing[1] + height;
    windowing[4] += -(char)(windowing[4] + windowing[2] + width) & 0xF;
    windowing[3] = (-v9 & 0xF) + v8;
  }
  else
  {
    windowing[2] = 0;
    windowing[1] = 0;
    windowing[3] = ((height + 15) & 0xF0) - height;
    windowing[4] = ((width + 15) & 0xF0) - width;
  }
  if ( windowing[1] >= 0x40u || windowing[2] >= 0x40u || windowing[3] >= 0x40u || windowing[4] >= 0x40u )
    return nullptr;
  v10 = *((_DWORD *)result + 26);
  result->height1 = height - 1;
  result->width1 = width - 1;
  result->extended_width = windowing[4] + windowing[2] + width;
  v11 = windowing[3] + windowing[1] + height - 1;
  result->num_lp_qps = 1;
  *((_DWORD *)result + 26) = v10 & 0x83FFFFFF | 0x54000000;
  result->num_hp_qps = 1;
  result->extended_height = v11 + 1;
  result->window_extra_top = windowing[1];
  result->window_extra_left = windowing[2];
  result->window_extra_bottom = windowing[3];
  result->window_extra_right = windowing[4];
  return result;
}


// ========================================================================
// ?_jxr_temp_calloc@@YAPAXPAUjxr_image@@II@Z
// EA  : 0x82903FC0
// RVA : 0x00903FC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

char *__fastcall _jxr_temp_calloc(jxr_image *image, unsigned int count, unsigned int size)
{
  int temp_buffer_used; // r11
  size_t v5; // r30
  char *v7; // r29

  temp_buffer_used = image->temp_buffer_used;
  v5 = (count * size + 15) & 0xFFFFFFF0;
  if ( (signed int)(temp_buffer_used + v5) <= image->temp_buffer_size )
  {
    v7 = (char *)image->temp_buffer + temp_buffer_used;
    memset(Dst: v7, Val: 0, Size: v5);
    image->temp_buffer_used += v5;
    return v7;
  }
  else
  {
    MEMORY[0] = 0;
    return nullptr;
  }
}


// ========================================================================
// ?jxr_estimate_temp_memory@@YAHHHH@Z
// EA  : 0x82904038
// RVA : 0x00904038
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

int __fastcall jxr_estimate_temp_memory(int width, int height, int numChannels)
{
  return (5680 * ((width + 15) / 16) + 4096) * numChannels;
}


// ========================================================================
// ?jxr_set_temp_memory@@YAXPAUjxr_image@@PAXII@Z
// EA  : 0x82904058
// RVA : 0x00904058
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

void __fastcall jxr_set_temp_memory(jxr_image *image, void *buffer, int size, int used)
{
  image->temp_buffer = buffer;
  image->temp_buffer_size = size;
  image->temp_buffer_used = used;
}


// ========================================================================
// ?jxr_used_temp_memory@@YAIPAUjxr_image@@@Z
// EA  : 0x82904068
// RVA : 0x00904068
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

int __fastcall jxr_used_temp_memory(jxr_image *image)
{
  return image->temp_buffer_used;
}


// ========================================================================
// make_mb_row_buffer
// EA  : 0x82904070
// RVA : 0x00904070
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

void __fastcall make_mb_row_buffer(jxr_image *image, unsigned int use_height)
{
  int temp_buffer_used; // r11
  unsigned int v4; // r24
  size_t v5; // r22
  macroblock_s *v6; // r10
  macroblock_s *v7; // r30
  int v8; // r11
  int temp_buffer_size; // r8
  int v10; // r7
  unsigned int v11; // r30
  char *v12; // r29
  int v13; // r11
  int v14; // r8
  size_t v15; // r25
  int *v16; // r9
  char *v17; // r30
  int v18; // r11
  unsigned int v19; // ctr
  int *v20; // r10
  int use_clr_fmt; // r11
  int v22; // r26
  int v23; // r23
  macroblock_s **v24; // r28
  size_t v25; // r27
  int v26; // r10
  macroblock_s *v27; // r30
  int v28; // r11
  char *v29; // r29
  int v30; // r10
  int *v31; // r9
  char *v32; // r30
  int v33; // r11
  unsigned int v34; // ctr
  int *v35; // r10

  temp_buffer_used = image->temp_buffer_used;
  v4 = (image->extended_width >> 4) * use_height;
  v5 = (84 * v4 + 15) & 0xFFFFFFF0;
  if ( (signed int)(temp_buffer_used + v5) <= image->temp_buffer_size )
  {
    v7 = (macroblock_s *)((char *)image->temp_buffer + temp_buffer_used);
    memset(Dst: v7, Val: 0, Size: v5);
    v6 = v7;
    image->temp_buffer_used += v5;
  }
  else
  {
    v6 = nullptr;
    MEMORY[0] = 0;
  }
  v8 = image->temp_buffer_used;
  temp_buffer_size = image->temp_buffer_size;
  v10 = (v4 << 10) + 15;
  image->mb_row_buffer[0] = v6;
  v11 = v10 & 0xFFFFFFF0;
  if ( (int)(v8 + (v10 & 0xFFFFFFF0)) <= temp_buffer_size )
  {
    v12 = (char *)image->temp_buffer + v8;
    memset(Dst: v12, Val: 0, Size: v10 & 0xFFFFFFF0);
    image->temp_buffer_used += v11;
  }
  else
  {
    v12 = nullptr;
    MEMORY[0] = 0;
  }
  v13 = image->temp_buffer_used;
  v14 = 28 * v4 + 15;
  v15 = v14 & 0xFFFFFFF0;
  if ( (signed int)((v14 & 0xFFFFFFF0) + v13) <= image->temp_buffer_size )
  {
    v17 = (char *)image->temp_buffer + v13;
    memset(Dst: v17, Val: 0, Size: v14 & 0xFFFFFFF0);
    v16 = (int *)v17;
    image->temp_buffer_used += v15;
  }
  else
  {
    v16 = nullptr;
    MEMORY[0] = 0;
  }
  if ( v4 != 0 )
  {
    v18 = 0;
    v19 = v4;
    v20 = (int *)v12;
    do
    {
      image->mb_row_buffer[0][v18].data = v20;
      v20 += 256;
      image->mb_row_buffer[0][v18++].pred_dclp = v16;
      v16 += 7;
      --v19;
    }
    while ( v19 != 0 );
  }
  use_clr_fmt = image->use_clr_fmt;
  v22 = 256;
  if ( use_clr_fmt == 2 )
  {
    v22 = 136;
  }
  else if ( use_clr_fmt == 1 )
  {
    v22 = 76;
  }
  v23 = 1;
  if ( image->num_channels > 1u )
  {
    v24 = &image->mb_row_buffer[1];
    v25 = (4 * v22 * v4 + 15) & 0xFFFFFFF0;
    do
    {
      v26 = image->temp_buffer_used;
      if ( (signed int)(v26 + v5) <= image->temp_buffer_size )
      {
        v27 = (macroblock_s *)((char *)image->temp_buffer + v26);
        memset(Dst: v27, Val: 0, Size: v5);
        image->temp_buffer_used += v5;
      }
      else
      {
        v27 = nullptr;
        MEMORY[0] = 0;
      }
      *v24 = v27;
      v28 = image->temp_buffer_used;
      if ( (signed int)(v28 + v25) <= image->temp_buffer_size )
      {
        v29 = (char *)image->temp_buffer + v28;
        memset(Dst: v29, Val: 0, Size: v25);
        image->temp_buffer_used += v25;
      }
      else
      {
        v29 = nullptr;
        MEMORY[0] = 0;
      }
      v30 = image->temp_buffer_used;
      if ( (signed int)(v15 + v30) <= image->temp_buffer_size )
      {
        v32 = (char *)image->temp_buffer + v30;
        memset(Dst: v32, Val: 0, Size: v15);
        v31 = (int *)v32;
        image->temp_buffer_used += v15;
      }
      else
      {
        v31 = nullptr;
        MEMORY[0] = 0;
      }
      if ( v4 != 0 )
      {
        v33 = 0;
        v34 = v4;
        v35 = (int *)v29;
        do
        {
          (*v24)[v33].data = v35;
          v35 += v22;
          (*v24)[v33++].pred_dclp = v31;
          v31 += 7;
          --v34;
        }
        while ( v34 != 0 );
      }
      ++v23;
      ++v24;
    }
    while ( v23 < image->num_channels );
  }
}


// ========================================================================
// ?_jxr_make_mbstore@@YAXPAUjxr_image@@H@Z
// EA  : 0x82904340
// RVA : 0x00904340
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\init.cpp
// ========================================================================

void __fastcall _jxr_make_mbstore(jxr_image *image, int up4_flag)
{
  int v4; // r26
  int temp_buffer_used; // r11
  unsigned int v6; // r7
  unsigned int v7; // r30
  macroblock_s *v8; // r29
  int v9; // r11
  unsigned int v10; // r7
  unsigned int v11; // r30
  char *v12; // r29
  char *v13; // r28
  int v14; // r11
  size_t v15; // r30
  char *v16; // r29
  int v17; // r11
  size_t v18; // r30
  char *v19; // r29
  int v20; // r11
  unsigned int v21; // r7
  unsigned int v22; // r30
  char *v23; // r29
  int v24; // r27
  int v25; // r11
  size_t v26; // r30
  char *v27; // r29
  unsigned int v28; // r11
  int v29; // r10
  _DWORD *v30; // r9
  int v31; // r11
  size_t v32; // r30
  char *v33; // r29
  unsigned int v34; // r11
  int v35; // r10
  _DWORD *v36; // r9
  int v37; // r11
  size_t v38; // r30
  char *v39; // r29
  unsigned int v40; // r11
  int v41; // r10
  _DWORD *v42; // r9
  int v43; // r11
  size_t v44; // r30
  char *v45; // r29
  unsigned int v46; // r11
  int v47; // r10
  _DWORD *v48; // r9
  int v49; // r11
  size_t v50; // r30
  char *v51; // r29
  unsigned int v52; // r11
  int v53; // r10
  _DWORD *v54; // r9
  int v55; // r11
  unsigned int v56; // r7
  unsigned int v57; // r30
  char *v58; // r29
  unsigned int v59; // r11
  int v60; // r10
  int v61; // r9
  int v62; // r11
  unsigned int v63; // r7
  unsigned int v64; // r30
  char *v65; // r29
  unsigned int v66; // r11
  int v67; // r10
  int v68; // r9
  int v69; // r11
  unsigned int v70; // r7
  unsigned int v71; // r30
  char *v72; // r29
  unsigned int v73; // r11
  int v74; // r10
  int v75; // r9
  int v76; // r11
  unsigned int v77; // r7
  unsigned int v78; // r30
  char *v79; // r29
  unsigned int v80; // r11
  int v81; // r10
  int v82; // r9
  int v83; // r11
  unsigned int v84; // r7
  unsigned int v85; // r30
  char *v86; // r29
  unsigned int v87; // r11
  int v88; // r10
  int v89; // r9
  int use_clr_fmt; // r11
  int v91; // r10
  char *v92; // r30
  int v93; // r11
  size_t v94; // r30
  char *v95; // r29
  unsigned int v96; // r4
  unsigned int v97; // r9
  unsigned int *tile_row_height; // r8
  int v99; // r11
  int v100; // r11
  int v101; // r25
  int v102; // r26
  int v103; // r27
  int v104; // r11
  unsigned int v105; // r7
  unsigned int v106; // r30
  int v107; // r11
  char *v108; // r29
  int v109; // r29
  int v110; // r11
  unsigned int v111; // r5
  unsigned int v112; // r30
  char *v113; // r28
  unsigned int v114; // r10
  int v115; // r11
  _DWORD *v116; // r9
  unsigned int tile_columns; // r11
  int v118; // r9
  int v119; // r11
  unsigned int v120; // r30
  model_s *v121; // r29
  unsigned int v122; // r10
  int v123; // r11
  int temp_buffer_size; // r8
  size_t v125; // r30
  cbp_model_s *v126; // r29
  int v127; // r11

  v4 = 0;
  if ( image->num_channels != 0 )
  {
    do
    {
      if ( up4_flag != 0 )
      {
        temp_buffer_used = image->temp_buffer_used;
        v6 = 84 * (image->extended_width >> 4) + 15;
        v7 = v6 & 0xFFFFFFF0;
        if ( (signed int)(temp_buffer_used + (v6 & 0xFFFFFFF0)) <= image->temp_buffer_size )
        {
          v8 = (macroblock_s *)((char *)image->temp_buffer + temp_buffer_used);
          memset(Dst: v8, Val: 0, Size: v6 & 0xFFFFFFF0);
          image->temp_buffer_used += v7;
        }
        else
        {
          v8 = nullptr;
          MEMORY[0] = 0;
        }
        image->strip[v4].up4 = v8;
      }
      v9 = image->temp_buffer_used;
      v10 = 84 * (image->extended_width >> 4) + 15;
      v11 = v10 & 0xFFFFFFF0;
      if ( (signed int)(v9 + (v10 & 0xFFFFFFF0)) <= image->temp_buffer_size )
      {
        v12 = (char *)image->temp_buffer + v9;
        memset(Dst: v12, Val: 0, Size: v10 & 0xFFFFFFF0);
        image->temp_buffer_used += v11;
      }
      else
      {
        v12 = nullptr;
        MEMORY[0] = 0;
      }
      v13 = (char *)image + 28 * v4;
      *((_DWORD *)v13 + 32) = v12;
      v14 = image->temp_buffer_used;
      v15 = (84 * (image->extended_width >> 4) + 15) & 0xFFFFFFF0;
      if ( (signed int)(v14 + v15) <= image->temp_buffer_size )
      {
        v16 = (char *)image->temp_buffer + v14;
        memset(Dst: v16, Val: 0, Size: v15);
        image->temp_buffer_used += v15;
      }
      else
      {
        v16 = nullptr;
        MEMORY[0] = 0;
      }
      *((_DWORD *)v13 + 33) = v16;
      v17 = image->temp_buffer_used;
      v18 = (84 * (image->extended_width >> 4) + 15) & 0xFFFFFFF0;
      if ( (signed int)(v17 + v18) <= image->temp_buffer_size )
      {
        v19 = (char *)image->temp_buffer + v17;
        memset(Dst: v19, Val: 0, Size: v18);
        image->temp_buffer_used += v18;
      }
      else
      {
        v19 = nullptr;
        MEMORY[0] = 0;
      }
      *((_DWORD *)v13 + 34) = v19;
      v20 = image->temp_buffer_used;
      v21 = 84 * (image->extended_width >> 4) + 15;
      v22 = v21 & 0xFFFFFFF0;
      if ( (signed int)(v20 + (v21 & 0xFFFFFFF0)) <= image->temp_buffer_size )
      {
        v23 = (char *)image->temp_buffer + v20;
        memset(Dst: v23, Val: 0, Size: v21 & 0xFFFFFFF0);
        image->temp_buffer_used += v22;
      }
      else
      {
        v23 = nullptr;
        MEMORY[0] = 0;
      }
      v24 = 28 * (v4 + 5);
      *(int *)((char *)&image->user_flags + v24) = (int)v23;
      if ( up4_flag != 0 )
      {
        v25 = image->temp_buffer_used;
        v26 = (((image->extended_width << 6) & 0xFFFFFC00) + 15) & 0xFFFFFFF0;
        if ( (signed int)(v25 + v26) <= image->temp_buffer_size )
        {
          v27 = (char *)image->temp_buffer + v25;
          memset(Dst: v27, Val: 0, Size: v26);
          image->temp_buffer_used += v26;
        }
        else
        {
          v27 = nullptr;
          MEMORY[0] = 0;
        }
        v28 = 1;
        **((_DWORD **)v13 + 31) = v27;
        if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
        {
          v29 = 84;
          do
          {
            ++v28;
            v30 = (_DWORD *)(v29 + *((_DWORD *)v13 + 31));
            v29 += 84;
            *v30 = *(v30 - 21) + 1024;
          }
          while ( v28 < image->extended_width >> 4 );
        }
      }
      v31 = image->temp_buffer_used;
      v32 = (((image->extended_width << 6) & 0xFFFFFC00) + 15) & 0xFFFFFFF0;
      if ( (signed int)(v32 + v31) <= image->temp_buffer_size )
      {
        v33 = (char *)image->temp_buffer + v31;
        memset(Dst: v33, Val: 0, Size: v32);
        image->temp_buffer_used += v32;
      }
      else
      {
        v33 = nullptr;
        MEMORY[0] = 0;
      }
      v34 = 1;
      **((_DWORD **)v13 + 32) = v33;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v35 = 84;
        do
        {
          ++v34;
          v36 = (_DWORD *)(v35 + *((_DWORD *)v13 + 32));
          v35 += 84;
          *v36 = *(v36 - 21) + 1024;
        }
        while ( v34 < image->extended_width >> 4 );
      }
      v37 = image->temp_buffer_used;
      v38 = (((image->extended_width << 6) & 0xFFFFFC00) + 15) & 0xFFFFFFF0;
      if ( (signed int)(v38 + v37) <= image->temp_buffer_size )
      {
        v39 = (char *)image->temp_buffer + v37;
        memset(Dst: v39, Val: 0, Size: v38);
        image->temp_buffer_used += v38;
      }
      else
      {
        v39 = nullptr;
        MEMORY[0] = 0;
      }
      v40 = 1;
      **((_DWORD **)v13 + 33) = v39;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v41 = 84;
        do
        {
          ++v40;
          v42 = (_DWORD *)(v41 + *((_DWORD *)v13 + 33));
          v41 += 84;
          *v42 = *(v42 - 21) + 1024;
        }
        while ( v40 < image->extended_width >> 4 );
      }
      v43 = image->temp_buffer_used;
      v44 = (((image->extended_width << 6) & 0xFFFFFC00) + 15) & 0xFFFFFFF0;
      if ( (signed int)(v44 + v43) <= image->temp_buffer_size )
      {
        v45 = (char *)image->temp_buffer + v43;
        memset(Dst: v45, Val: 0, Size: v44);
        image->temp_buffer_used += v44;
      }
      else
      {
        v45 = nullptr;
        MEMORY[0] = 0;
      }
      v46 = 1;
      **((_DWORD **)v13 + 34) = v45;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v47 = 84;
        do
        {
          ++v46;
          v48 = (_DWORD *)(v47 + *((_DWORD *)v13 + 34));
          v47 += 84;
          *v48 = *(v48 - 21) + 1024;
        }
        while ( v46 < image->extended_width >> 4 );
      }
      v49 = image->temp_buffer_used;
      v50 = (((image->extended_width << 6) & 0xFFFFFC00) + 15) & 0xFFFFFFF0;
      if ( (signed int)(v50 + v49) <= image->temp_buffer_size )
      {
        v51 = (char *)image->temp_buffer + v49;
        memset(Dst: v51, Val: 0, Size: v50);
        image->temp_buffer_used += v50;
      }
      else
      {
        v51 = nullptr;
        MEMORY[0] = 0;
      }
      v52 = 1;
      **(_DWORD **)((char *)&image->user_flags + v24) = v51;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v53 = 84;
        do
        {
          ++v52;
          v54 = (_DWORD *)(v53 + *(int *)((char *)&image->user_flags + v24));
          v53 += 84;
          *v54 = *(v54 - 21) + 1024;
        }
        while ( v52 < image->extended_width >> 4 );
      }
      if ( up4_flag != 0 )
      {
        v55 = image->temp_buffer_used;
        v56 = 28 * (image->extended_width >> 4) + 15;
        v57 = v56 & 0xFFFFFFF0;
        if ( (signed int)((v56 & 0xFFFFFFF0) + v55) <= image->temp_buffer_size )
        {
          v58 = (char *)image->temp_buffer + v55;
          memset(Dst: v58, Val: 0, Size: v56 & 0xFFFFFFF0);
          image->temp_buffer_used += v57;
        }
        else
        {
          v58 = nullptr;
          MEMORY[0] = 0;
        }
        v59 = 1;
        *(_DWORD *)(*((_DWORD *)v13 + 31) + 4) = v58;
        if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
        {
          v60 = 84;
          do
          {
            ++v59;
            v61 = v60 + *((_DWORD *)v13 + 31);
            v60 += 84;
            *(_DWORD *)(v61 + 4) = *(_DWORD *)(v61 - 80) + 28;
          }
          while ( v59 < image->extended_width >> 4 );
        }
      }
      v62 = image->temp_buffer_used;
      v63 = 28 * (image->extended_width >> 4) + 15;
      v64 = v63 & 0xFFFFFFF0;
      if ( (signed int)((v63 & 0xFFFFFFF0) + v62) <= image->temp_buffer_size )
      {
        v65 = (char *)image->temp_buffer + v62;
        memset(Dst: v65, Val: 0, Size: v63 & 0xFFFFFFF0);
        image->temp_buffer_used += v64;
      }
      else
      {
        v65 = nullptr;
        MEMORY[0] = 0;
      }
      v66 = 1;
      *(_DWORD *)(*((_DWORD *)v13 + 32) + 4) = v65;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v67 = 84;
        do
        {
          ++v66;
          v68 = v67 + *((_DWORD *)v13 + 32);
          v67 += 84;
          *(_DWORD *)(v68 + 4) = *(_DWORD *)(v68 - 80) + 28;
        }
        while ( v66 < image->extended_width >> 4 );
      }
      v69 = image->temp_buffer_used;
      v70 = 28 * (image->extended_width >> 4) + 15;
      v71 = v70 & 0xFFFFFFF0;
      if ( (signed int)((v70 & 0xFFFFFFF0) + v69) <= image->temp_buffer_size )
      {
        v72 = (char *)image->temp_buffer + v69;
        memset(Dst: v72, Val: 0, Size: v70 & 0xFFFFFFF0);
        image->temp_buffer_used += v71;
      }
      else
      {
        v72 = nullptr;
        MEMORY[0] = 0;
      }
      v73 = 1;
      *(_DWORD *)(*((_DWORD *)v13 + 33) + 4) = v72;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v74 = 84;
        do
        {
          ++v73;
          v75 = v74 + *((_DWORD *)v13 + 33);
          v74 += 84;
          *(_DWORD *)(v75 + 4) = *(_DWORD *)(v75 - 80) + 28;
        }
        while ( v73 < image->extended_width >> 4 );
      }
      v76 = image->temp_buffer_used;
      v77 = 28 * (image->extended_width >> 4) + 15;
      v78 = v77 & 0xFFFFFFF0;
      if ( (signed int)((v77 & 0xFFFFFFF0) + v76) <= image->temp_buffer_size )
      {
        v79 = (char *)image->temp_buffer + v76;
        memset(Dst: v79, Val: 0, Size: v77 & 0xFFFFFFF0);
        image->temp_buffer_used += v78;
      }
      else
      {
        v79 = nullptr;
        MEMORY[0] = 0;
      }
      v80 = 1;
      *(_DWORD *)(*((_DWORD *)v13 + 34) + 4) = v79;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v81 = 84;
        do
        {
          ++v80;
          v82 = v81 + *((_DWORD *)v13 + 34);
          v81 += 84;
          *(_DWORD *)(v82 + 4) = *(_DWORD *)(v82 - 80) + 28;
        }
        while ( v80 < image->extended_width >> 4 );
      }
      v83 = image->temp_buffer_used;
      v84 = 28 * (image->extended_width >> 4) + 15;
      v85 = v84 & 0xFFFFFFF0;
      if ( (signed int)((v84 & 0xFFFFFFF0) + v83) <= image->temp_buffer_size )
      {
        v86 = (char *)image->temp_buffer + v83;
        memset(Dst: v86, Val: 0, Size: v84 & 0xFFFFFFF0);
        image->temp_buffer_used += v85;
      }
      else
      {
        v86 = nullptr;
        MEMORY[0] = 0;
      }
      v87 = 1;
      *(_DWORD *)(*(int *)((char *)&image->user_flags + v24) + 4) = v86;
      if ( (image->extended_width & 0xFFFFFFF0) > 0x10 )
      {
        v88 = 84;
        do
        {
          ++v87;
          v89 = v88 + *(int *)((char *)&image->user_flags + v24);
          v88 += 84;
          *(_DWORD *)(v89 + 4) = *(_DWORD *)(v89 - 80) + 28;
        }
        while ( v87 < image->extended_width >> 4 );
      }
      if ( v4 != 0 )
      {
        use_clr_fmt = image->use_clr_fmt;
        if ( use_clr_fmt == 2 || use_clr_fmt == 1 )
        {
          v91 = image->temp_buffer_used;
          if ( v91 + 64 <= image->temp_buffer_size )
          {
            v92 = (char *)image->temp_buffer + v91;
            memset(Dst: v92, Val: 0, Size: 0x40u);
            image->temp_buffer_used += 64;
          }
          else
          {
            v92 = nullptr;
            MEMORY[0] = 0;
          }
          *((_DWORD *)v13 + 37) = v92;
        }
        if ( image->use_clr_fmt == 1 )
        {
          v93 = image->temp_buffer_used;
          v94 = (((2 * image->extended_width) & 0xFFFFFFE0) + 15) & 0xFFFFFFF0;
          if ( (signed int)(v94 + v93) <= image->temp_buffer_size )
          {
            v95 = (char *)image->temp_buffer + v93;
            memset(Dst: v95, Val: 0, Size: v94);
            image->temp_buffer_used += v94;
          }
          else
          {
            v95 = nullptr;
            MEMORY[0] = 0;
          }
          *((_DWORD *)v13 + 36) = v95;
        }
      }
      ++v4;
    }
    while ( v4 < image->num_channels );
  }
  if ( (image->header_flags1 & 0x40) != 0 )
  {
    make_mb_row_buffer(image, use_height: image->extended_height >> 4);
  }
  else if ( (image->header_flags1 & 4) != 0 )
  {
    v96 = 0;
    v97 = 0;
    if ( image->tile_rows != 0 )
    {
      tile_row_height = image->tile_row_height;
      v99 = 0;
      do
      {
        if ( tile_row_height[v99] > v96 )
          v96 = tile_row_height[v99];
        ++v97;
        ++v99;
      }
      while ( v97 < image->tile_rows );
    }
    make_mb_row_buffer(image, use_height: v96);
    v100 = image->use_clr_fmt;
    v101 = 256;
    if ( v100 == 2 )
    {
      v101 = 136;
    }
    else if ( v100 == 1 )
    {
      v101 = 76;
    }
    v102 = 0;
    if ( image->num_channels != 0 )
    {
      do
      {
        v103 = 256;
        if ( v102 != 0 )
          v103 = v101;
        v104 = image->temp_buffer_used;
        v105 = 336 * (image->extended_width >> 4) + 15;
        v106 = v105 & 0xFFFFFFF0;
        if ( (signed int)((v105 & 0xFFFFFFF0) + v104) <= image->temp_buffer_size )
        {
          v108 = (char *)image->temp_buffer + v104;
          memset(Dst: v108, Val: 0, Size: v105 & 0xFFFFFFF0);
          v107 = (int)v108;
          image->temp_buffer_used += v106;
        }
        else
        {
          v107 = 0;
          MEMORY[0] = 0;
        }
        v109 = 4 * (v102 + 159);
        *(int *)((char *)&image->user_flags + v109) = v107;
        v110 = image->temp_buffer_used;
        v111 = 16 * (image->extended_width >> 4) * v103 + 15;
        v112 = v111 & 0xFFFFFFF0;
        if ( (signed int)((v111 & 0xFFFFFFF0) + v110) <= image->temp_buffer_size )
        {
          v113 = (char *)image->temp_buffer + v110;
          memset(Dst: v113, Val: 0, Size: v111 & 0xFFFFFFF0);
          image->temp_buffer_used += v112;
        }
        else
        {
          v113 = nullptr;
          MEMORY[0] = 0;
        }
        v114 = 1;
        **(_DWORD **)((char *)&image->user_flags + v109) = v113;
        if ( ((image->extended_width >> 2) & 0x3FFFFFFC) > 1 )
        {
          v115 = 84;
          do
          {
            ++v114;
            v116 = (_DWORD *)(v115 + *(int *)((char *)&image->user_flags + v109));
            v115 += 84;
            *v116 = *(v116 - 21) + 4 * v103;
          }
          while ( v114 < ((image->extended_width >> 2) & 0x3FFFFFFC) );
        }
        ++v102;
      }
      while ( v102 < image->num_channels );
    }
  }
  tile_columns = image->tile_columns;
  image->model_hp_buffer = nullptr;
  image->hp_cbp_model_buffer = nullptr;
  if ( tile_columns > 1 )
  {
    v118 = (tile_columns << 7) + 15;
    v119 = image->temp_buffer_used;
    v120 = v118 & 0xFFFFFFF0;
    if ( (signed int)((v118 & 0xFFFFFFF0) + v119) <= image->temp_buffer_size )
    {
      v121 = (model_s *)((char *)image->temp_buffer + v119);
      memset(Dst: v121, Val: 0, Size: v118 & 0xFFFFFFF0);
      image->temp_buffer_used += v120;
    }
    else
    {
      v121 = nullptr;
      MEMORY[0] = 0;
    }
    v122 = image->tile_columns;
    v123 = image->temp_buffer_used;
    temp_buffer_size = image->temp_buffer_size;
    image->model_hp_buffer = v121;
    v125 = (192 * v122 + 15) & 0xFFFFFFF0;
    if ( (int)(v125 + v123) > temp_buffer_size )
    {
      MEMORY[0] = 0;
      image->hp_cbp_model_buffer = nullptr;
      image->cur_my = -1;
      return;
    }
    v126 = (cbp_model_s *)((char *)image->temp_buffer + v123);
    memset(Dst: v126, Val: 0, Size: v125);
    v127 = image->temp_buffer_used;
    image->hp_cbp_model_buffer = v126;
    image->temp_buffer_used = v125 + v127;
  }
  image->cur_my = -1;
}

