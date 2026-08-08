
// ========================================================================
// backup_dc_strip
// EA  : 0x82912A08
// RVA : 0x00912A08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

void __fastcall backup_dc_strip(jxr_image *image, int tx, int ty, int my)
{
  int v4; // r7
  int v5; // r31
  unsigned int v6; // r4
  int v7; // r10
  macroblock_s **p_cur; // r6
  macroblock_s **mb_row_buffer; // r5
  int v10; // r11
  macroblock_s *v11; // r9
  unsigned int v12; // r8

  v4 = tx;
  v5 = 0;
  if ( image->num_channels != 0 )
  {
    v6 = (image->tile_row_position[ty] + my) * (image->extended_width >> 4) + image->tile_column_position[tx];
    v7 = image->tile_column_width[v4];
    p_cur = &image->strip[0].cur;
    mb_row_buffer = image->mb_row_buffer;
    do
    {
      v10 = 0;
      if ( v7 > 0 )
      {
        v11 = &(*mb_row_buffer)[v6 - 1];
        do
        {
          ++v11;
          v12 = image->tile_column_position[v4] + v10++;
          *v11->data = *(*p_cur)[v12].data;
          v7 = image->tile_column_width[v4];
        }
        while ( v10 < v7 );
      }
      ++v5;
      ++mb_row_buffer;
      p_cur += 7;
    }
    while ( v5 < image->num_channels );
  }
}


// ========================================================================
// backup_dclp_strip
// EA  : 0x82912AD8
// RVA : 0x00912AD8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

void __fastcall backup_dclp_strip(jxr_image *image, int tx, int ty, int my)
{
  int v4; // r7
  int v5; // r30
  int use_clr_fmt; // r11
  unsigned int v7; // r10
  int v8; // r4
  unsigned int v9; // r31
  int v10; // r5
  signed int v11; // r10
  char *v12; // r9
  int v13; // r6
  int v14; // r11
  int i; // ctr
  int v16; // r27
  int v17; // r8
  unsigned int v18; // r11

  v4 = tx;
  v5 = 15;
  use_clr_fmt = image->use_clr_fmt;
  v7 = (image->tile_row_position[ty] + my) * (image->extended_width >> 4) + image->tile_column_position[tx];
  if ( use_clr_fmt == 2 )
  {
    v5 = 7;
  }
  else if ( use_clr_fmt == 1 )
  {
    v5 = 3;
  }
  v8 = 0;
  if ( image->num_channels != 0 )
  {
    v9 = v7;
    do
    {
      v10 = 15;
      if ( v8 != 0 )
        v10 = v5;
      v11 = 0;
      if ( (int)image->tile_column_width[v4] > 0 )
      {
        v12 = (char *)&image->mb_row_buffer[v8][v9 - 1] + 8;
        v13 = 28 * (v8 + 5);
        do
        {
          **((_DWORD **)v12 + 19) = **(_DWORD **)(84 * (image->tile_column_position[v4] + v11)
                                                + *(int *)((char *)&image->user_flags + v13));
          v14 = 0;
          for ( i = v10; i != 0; --i )
          {
            v16 = v14 + *((_DWORD *)v12 + 19);
            v17 = *(_DWORD *)(84 * (image->tile_column_position[v4] + v11) + *(int *)((char *)&image->user_flags + v13))
                + v14;
            v14 += 4;
            *(_DWORD *)(v16 + 4) = *(_DWORD *)(v17 + 4);
          }
          v18 = image->tile_column_position[v4] + v11++;
          v12 += 84;
          *v12 = *(_BYTE *)(84 * v18 + *(int *)((char *)&image->user_flags + v13) + 8);
        }
        while ( v11 < (signed int)image->tile_column_width[v4] );
      }
      ++v8;
    }
    while ( v8 < image->num_channels );
  }
}


// ========================================================================
// backup_hp_strip
// EA  : 0x82912C38
// RVA : 0x00912C38
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

void __fastcall backup_hp_strip(jxr_image *image, int tx, int ty, int my)
{
  int v4; // r10
  int v5; // r23
  int use_clr_fmt; // r11
  int v7; // r25
  unsigned int v8; // r24
  macroblock_s *v9; // r8
  int v10; // r26
  signed int v11; // r9
  int v12; // r7
  unsigned int *v13; // r31
  int v14; // r11
  int i; // ctr
  int v16; // r27
  int v17; // r6
  unsigned int v18; // r4
  unsigned int v19; // r6
  signed int v20; // r9
  char *v21; // r7
  int v22; // r6
  int v23; // r8
  int v24; // r5
  int j; // r27
  int v26; // r11
  int k; // ctr
  int v28; // r4
  int v29; // r18
  int v30; // r29
  int v31; // r19
  int v32; // r30
  int v33; // r17
  int v34; // r20
  unsigned int v35; // r5

  v4 = tx;
  v5 = 16;
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 2 )
  {
    v5 = 8;
  }
  else if ( use_clr_fmt == 1 )
  {
    v5 = 4;
  }
  v7 = 0;
  if ( image->num_channels != 0 )
  {
    v8 = (image->tile_row_position[ty] + my) * (image->extended_width >> 4) + image->tile_column_position[tx];
    do
    {
      v9 = &image->mb_row_buffer[v7][v8];
      if ( v7 != 0 )
      {
        v10 = v5;
      }
      else
      {
        v10 = 16;
        v11 = 0;
        if ( (int)image->tile_column_width[v4] > 0 )
        {
          v12 = 0;
          v13 = (unsigned int *)((char *)&v9[-1] + 8);
          do
          {
            v14 = 0;
            for ( i = 4; i != 0; --i )
            {
              v16 = 4 * (v12 * 21 + 8 + v14);
              v9[v12].hp_model_bits[v14] = image->strip[0].cur[image->tile_column_position[v4] + v11].hp_model_bits[v14];
              v9[v12].hp_model_bits[v14 + 1] = image->strip[0].cur[image->tile_column_position[v4] + v11].hp_model_bits[v14 + 1];
              v9[v12].hp_model_bits[v14 + 2] = image->strip[0].cur[image->tile_column_position[v4] + v11].hp_model_bits[v14 + 2];
              v17 = 21 * (image->tile_column_position[v4] + v11) + v14;
              v14 += 4;
              *(int **)((char *)&v9->data + v16) = (int *)image->strip[0].cur->hp_model_bits[v17 + 3];
            }
            ++v12;
            v18 = image->tile_column_position[v4] + v11++;
            v19 = v13[21] & 0xFFFF1FFF | *((_DWORD *)&image->strip[0].cur[v18] + 2) & 0xE000;
            v13 += 21;
            *v13 = v19;
          }
          while ( v11 < (signed int)image->tile_column_width[v4] );
        }
      }
      v20 = 0;
      if ( (int)image->tile_column_width[v4] > 0 )
      {
        v21 = (char *)&v9[-1] + 9;
        v22 = 28 * (v7 + 5);
        do
        {
          **(_DWORD **)(v21 + 75) = **(_DWORD **)(84 * (image->tile_column_position[v4] + v20)
                                                + *(int *)((char *)&image->user_flags + v22));
          v23 = 0;
          v24 = v10;
          for ( j = v10; j != 0; --j )
          {
            v26 = 0;
            for ( k = 3; k != 0; --k )
            {
              v28 = 4 * (v24 + v26);
              v29 = 4 * (v23 + v26 + 18);
              *(_DWORD *)(*(_DWORD *)(v21 + 75) + v28) = *(_DWORD *)(*(_DWORD *)(84
                                                                               * (image->tile_column_position[v4] + v20)
                                                                               + *(int *)((char *)&image->user_flags
                                                                                        + v22))
                                                                   + 4 * (v23 + v26 + 16));
              v30 = 4 * (v24 + v26 + 2);
              v31 = 4 * (v23 + v26 + 19);
              *(_DWORD *)(*(_DWORD *)(v21 + 75) + v28 + 4) = *(_DWORD *)(*(_DWORD *)(84
                                                                                   * (image->tile_column_position[v4]
                                                                                    + v20)
                                                                                   + *(int *)((char *)&image->user_flags
                                                                                            + v22))
                                                                       + 4 * (v23 + v26 + 17));
              v32 = 4 * (v24 + v26 + 3);
              v33 = 4 * (v23 + v26 + 20);
              v34 = 4 * (v24 + 4 + v26);
              v26 += 5;
              *(_DWORD *)(v30 + *(_DWORD *)(v21 + 75)) = *(_DWORD *)(*(_DWORD *)(84
                                                                               * (image->tile_column_position[v4] + v20)
                                                                               + *(int *)((char *)&image->user_flags
                                                                                        + v22))
                                                                   + v29);
              *(_DWORD *)(v32 + *(_DWORD *)(v21 + 75)) = *(_DWORD *)(*(_DWORD *)(84
                                                                               * (image->tile_column_position[v4] + v20)
                                                                               + *(int *)((char *)&image->user_flags
                                                                                        + v22))
                                                                   + v31);
              *(_DWORD *)(v34 + *(_DWORD *)(v21 + 75)) = *(_DWORD *)(*(_DWORD *)(84
                                                                               * (image->tile_column_position[v4] + v20)
                                                                               + *(int *)((char *)&image->user_flags
                                                                                        + v22))
                                                                   + v33);
            }
            v23 += 15;
            v24 += 15;
          }
          v35 = image->tile_column_position[v4] + v20++;
          v21 += 84;
          *v21 = *(_WORD *)(84 * v35 + *(int *)((char *)&image->user_flags + v22) + 8);
        }
        while ( v20 < (signed int)image->tile_column_width[v4] );
      }
      ++v7;
    }
    while ( v7 < image->num_channels );
  }
}


// ========================================================================
// recover_dc_strip
// EA  : 0x82912FF0
// RVA : 0x00912FF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

void __fastcall recover_dc_strip(jxr_image *image, int tx, int ty, int my)
{
  int v4; // r7
  int v5; // r31
  unsigned int v6; // r4
  int v7; // r10
  macroblock_s **p_cur; // r6
  macroblock_s **mb_row_buffer; // r5
  int v10; // r11
  macroblock_s *v11; // r9
  unsigned int v12; // r8

  v4 = tx;
  v5 = 0;
  if ( image->num_channels != 0 )
  {
    v6 = (image->tile_row_position[ty] + my) * (image->extended_width >> 4) + image->tile_column_position[tx];
    v7 = image->tile_column_width[v4];
    p_cur = &image->strip[0].cur;
    mb_row_buffer = image->mb_row_buffer;
    do
    {
      v10 = 0;
      if ( v7 > 0 )
      {
        v11 = &(*mb_row_buffer)[v6 - 1];
        do
        {
          ++v11;
          v12 = image->tile_column_position[v4] + v10++;
          *(*p_cur)[v12].data = *v11->data;
          v7 = image->tile_column_width[v4];
        }
        while ( v10 < v7 );
      }
      ++v5;
      ++mb_row_buffer;
      p_cur += 7;
    }
    while ( v5 < image->num_channels );
  }
}


// ========================================================================
// recover_dclp_strip
// EA  : 0x829130C0
// RVA : 0x009130C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

void __fastcall recover_dclp_strip(jxr_image *image, int tx, int ty, int my)
{
  int v4; // r8
  int v5; // r29
  int use_clr_fmt; // r11
  int v7; // r31
  unsigned int v8; // r30
  int v9; // r4
  signed int v10; // r10
  char *v11; // r9
  int v12; // r6
  int v13; // r11
  int i; // ctr
  int v15; // r27
  int v16; // r7
  unsigned int v17; // r7

  v4 = tx;
  v5 = 15;
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 2 )
  {
    v5 = 7;
  }
  else if ( use_clr_fmt == 1 )
  {
    v5 = 3;
  }
  v7 = 0;
  if ( image->num_channels != 0 )
  {
    v8 = (image->tile_row_position[ty] + my) * (image->extended_width >> 4) + image->tile_column_position[tx];
    do
    {
      v9 = 15;
      if ( v7 != 0 )
        v9 = v5;
      v10 = 0;
      if ( (int)image->tile_column_width[v4] > 0 )
      {
        v11 = (char *)&image->mb_row_buffer[v7][v8 - 1] + 8;
        v12 = 28 * (v7 + 5);
        do
        {
          **(_DWORD **)(84 * (image->tile_column_position[v4] + v10) + *(int *)((char *)&image->user_flags + v12)) = **((_DWORD **)v11 + 19);
          v13 = 0;
          for ( i = v9; i != 0; --i )
          {
            v15 = *((_DWORD *)v11 + 19) + v13;
            v16 = *(_DWORD *)(84 * (image->tile_column_position[v4] + v10) + *(int *)((char *)&image->user_flags + v12))
                + v13;
            v13 += 4;
            *(_DWORD *)(v16 + 4) = *(_DWORD *)(v15 + 4);
          }
          v11 += 84;
          v17 = image->tile_column_position[v4] + v10++;
          *(_BYTE *)(84 * v17 + *(int *)((char *)&image->user_flags + v12) + 8) = *v11;
        }
        while ( v10 < (signed int)image->tile_column_width[v4] );
      }
      ++v7;
    }
    while ( v7 < image->num_channels );
  }
}


// ========================================================================
// recover_dclphp_strip
// EA  : 0x82913220
// RVA : 0x00913220
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

void __fastcall recover_dclphp_strip(jxr_image *image, int tx, int ty, int my)
{
  int v4; // r11
  int v5; // r24
  int use_clr_fmt; // r10
  int v7; // r26
  unsigned int v8; // r25
  macroblock_s *v9; // r9
  int v10; // r28
  signed int v11; // r8
  int v12; // r7
  macroblock_s *v13; // r31
  int v14; // r10
  int i; // ctr
  unsigned int v16; // r29
  int v17; // r6
  unsigned int v18; // r4
  signed int v19; // r8
  int v20; // r7
  int v21; // r10
  int v22; // ctr
  int v23; // r29
  int j; // r27
  int v25; // r5
  int k; // ctr
  int v27; // r6
  int v28; // r20
  int v29; // r21
  int v30; // r31
  int v31; // r10
  __int16 v32; // r4
  unsigned int v33; // r6

  v4 = tx;
  v5 = 16;
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 2 )
  {
    v5 = 8;
  }
  else if ( use_clr_fmt == 1 )
  {
    v5 = 4;
  }
  v7 = 0;
  if ( image->num_channels != 0 )
  {
    v8 = (image->tile_row_position[ty] + my) * (image->extended_width >> 4) + image->tile_column_position[tx];
    do
    {
      v9 = &image->mb_row_buffer[v7][v8];
      if ( v7 != 0 )
      {
        v10 = v5;
      }
      else
      {
        v10 = 16;
        v11 = 0;
        if ( (int)image->tile_column_width[v4] > 0 )
        {
          v12 = 0;
          v13 = (macroblock_s *)((char *)v9 - 76);
          do
          {
            v14 = 0;
            for ( i = 4; i != 0; --i )
            {
              image->strip[0].cur[image->tile_column_position[v4] + v11].hp_model_bits[v14] = v9[v12].hp_model_bits[v14];
              image->strip[0].cur[image->tile_column_position[v4] + v11].hp_model_bits[v14 + 1] = v9[v12].hp_model_bits[v14 + 1];
              image->strip[0].cur[image->tile_column_position[v4] + v11].hp_model_bits[v14 + 2] = v9[v12].hp_model_bits[v14 + 2];
              v16 = v9[v12].hp_model_bits[v14 + 3];
              v17 = 21 * (image->tile_column_position[v4] + v11) + v14;
              v14 += 4;
              image->strip[0].cur->hp_model_bits[v17 + 3] = v16;
            }
            ++v12;
            ++v13;
            v18 = image->tile_column_position[v4] + v11++;
            *((_DWORD *)&image->strip[0].cur[v18] + 2) = *((_DWORD *)&image->strip[0].cur[v18] + 2) & 0xFFFF1FFF
                                                       | (int)v13->data & 0xE000;
          }
          while ( v11 < (signed int)image->tile_column_width[v4] );
        }
      }
      v19 = 0;
      if ( (int)image->tile_column_width[v4] > 0 )
      {
        v20 = 28 * (v7 + 5);
        do
        {
          **(_DWORD **)(84 * (image->tile_column_position[v4] + v19) + *(int *)((char *)&image->user_flags + v20)) = *v9->data;
          v21 = 1;
          v22 = v10 - 1;
          do
          {
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + v19)
                                  + *(int *)((char *)&image->user_flags + v20))
                      + v21 * 4) = v9->data[v21];
            ++v21;
            --v22;
          }
          while ( v22 != 0 );
          v23 = 0;
          for ( j = v10; j != 0; --j )
          {
            v25 = 0;
            for ( k = 3; k != 0; --k )
            {
              v27 = v25 + v23 + v10;
              v28 = v25 + v23 + 18;
              v29 = 4 * (v25 + v23 + 17);
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + v19)
                                    + *(int *)((char *)&image->user_flags + v20))
                        + 4 * (v25 + v23 + 16)) = v9->data[v27];
              v30 = v25 + v23 + 19;
              v31 = v25 + v23 + 20;
              v25 += 5;
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + v19)
                                    + *(int *)((char *)&image->user_flags + v20))
                        + v29) = v9->data[v27 + 1];
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + v19)
                                    + *(int *)((char *)&image->user_flags + v20))
                        + 4 * v28) = v9->data[v27 + 2];
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + v19)
                                    + *(int *)((char *)&image->user_flags + v20))
                        + 4 * v30) = v9->data[v27 + 3];
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + v19)
                                    + *(int *)((char *)&image->user_flags + v20))
                        + 4 * v31) = v9->data[v27 + 4];
            }
            v23 += 15;
          }
          *(_BYTE *)(84 * (image->tile_column_position[v4] + v19) + *(int *)((char *)&image->user_flags + v20) + 8) = *((_BYTE *)v9 + 8);
          v32 = *((_WORD *)v9++ + 4);
          v33 = 84 * (image->tile_column_position[v4] + v19++) + *(int *)((char *)&image->user_flags + v20);
          *(_BYTE *)(v33 + 9) = v32;
        }
        while ( v19 < (signed int)image->tile_column_width[v4] );
      }
      ++v7;
    }
    while ( v7 < image->num_channels );
  }
}


// ========================================================================
// ?_jxr_frequency_mode_render_stripe@@YAHPAUjxr_image@@@Z
// EA  : 0x82913618
// RVA : 0x00913618
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

int __fastcall _jxr_frequency_mode_render_stripe(jxr_image *image)
{
  unsigned int cleanup_state; // r11
  unsigned int stripe_ty; // r28
  unsigned int stripe_my; // r29
  int i; // r30
  unsigned int *tile_row_height; // r10
  unsigned int v7; // r11
  unsigned int v8; // r10
  unsigned int tile_rows; // r10
  unsigned int v11; // r11
  bool v12; // cr58
  int v13; // r10
  int v14; // r10
  int v15; // r10
  int output_sent; // r10

  cleanup_state = image->cleanup_state;
  stripe_ty = image->stripe_ty;
  stripe_my = image->stripe_my;
  if ( cleanup_state <= 4 )
  {
    if ( cleanup_state != 1 )
    {
      if ( cleanup_state == 2 )
        goto LABEL_25;
      if ( cleanup_state == 3 )
        goto LABEL_28;
      if ( cleanup_state != 0 )
      {
LABEL_31:
        _jxr_r_flush_rotate_mb_strip(image, tx: -1, ty: -1, my: (image->extended_height >> 4) + 3);
        if ( (image->header_flags2 & 1) != 0 )
          _jxr_r_flush_rotate_mb_strip(
            image: image->alpha,
            tx: -1,
            ty: -1,
            my: (image->alpha->extended_height >> 4) + 3);
        output_sent = image->output_sent;
        ++image->cleanup_state;
        if ( output_sent == 0 )
          return -256;
LABEL_15:
        image->output_sent = 0;
        return 0;
      }
      while ( 1 )
      {
        _jxr_r_flush_rotate_mb_strip(image, tx: -1, ty: -1, my: image->tile_row_position[stripe_ty] + stripe_my);
        if ( (image->header_flags2 & 1) != 0 )
          _jxr_r_flush_rotate_mb_strip(
            image: image->alpha,
            tx: -1,
            ty: -1,
            my: image->alpha->tile_row_position[stripe_ty] + stripe_my);
        for ( i = 0; i < (signed int)image->tile_columns; ++i )
        {
          recover_dclphp_strip(image, tx: i, ty: stripe_ty, my: stripe_my);
          if ( (image->header_flags2 & 1) != 0 )
            recover_dclphp_strip(image: image->alpha, tx: i, ty: stripe_ty, my: stripe_my);
        }
        tile_row_height = image->tile_row_height;
        v7 = image->stripe_my + 1;
        image->stripe_my = v7;
        stripe_my = v7;
        v8 = tile_row_height[stripe_ty];
        if ( v7 >= v8 )
          break;
        if ( image->output_sent != 0 )
        {
          if ( v7 < v8 )
            goto LABEL_15;
          break;
        }
      }
      tile_rows = image->tile_rows;
      v11 = image->stripe_ty + 1;
      image->stripe_my = 0;
      image->stripe_ty = v11;
      v12 = v11 == tile_rows;
      if ( v11 < tile_rows )
      {
        if ( image->output_sent != 0 )
          goto LABEL_15;
        v12 = v11 == tile_rows;
      }
      if ( v12 )
        ++image->cleanup_state;
      if ( image->output_sent != 0 )
        goto LABEL_15;
    }
    _jxr_r_flush_rotate_mb_strip(image, tx: -1, ty: -1, my: image->extended_height >> 4);
    if ( (image->header_flags2 & 1) != 0 )
      _jxr_r_flush_rotate_mb_strip(image: image->alpha, tx: -1, ty: -1, my: image->alpha->extended_height >> 4);
    v13 = image->output_sent;
    ++image->cleanup_state;
    if ( v13 != 0 )
      goto LABEL_15;
LABEL_25:
    _jxr_r_flush_rotate_mb_strip(image, tx: -1, ty: -1, my: (image->extended_height >> 4) + 1);
    if ( (image->header_flags2 & 1) != 0 )
      _jxr_r_flush_rotate_mb_strip(image: image->alpha, tx: -1, ty: -1, my: (image->alpha->extended_height >> 4) + 1);
    v14 = image->output_sent;
    ++image->cleanup_state;
    if ( v14 != 0 )
      goto LABEL_15;
LABEL_28:
    _jxr_r_flush_rotate_mb_strip(image, tx: -1, ty: -1, my: (image->extended_height >> 4) + 2);
    if ( (image->header_flags2 & 1) != 0 )
      _jxr_r_flush_rotate_mb_strip(image: image->alpha, tx: -1, ty: -1, my: (image->alpha->extended_height >> 4) + 2);
    v15 = image->output_sent;
    ++image->cleanup_state;
    if ( v15 != 0 )
      goto LABEL_15;
    goto LABEL_31;
  }
  return -256;
}


// ========================================================================
// ?_jxr_r_TILE_DC@@YAHPAUjxr_image@@PAUrbitstream@@II@Z
// EA  : 0x82913910
// RVA : 0x00913910
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

int __fastcall _jxr_r_TILE_DC(jxr_image *image, rbitstream *str, unsigned int tx, unsigned int ty)
{
  char v8; // r25
  char v9; // r30
  char v10; // r29
  unsigned int v11; // r24
  unsigned int v12; // r25
  unsigned int i; // r30
  unsigned int j; // r29
  jxr_image *alpha; // r3

  v8 = _jxr_rbitstream_uint8(str);
  v9 = _jxr_rbitstream_uint8(str);
  v10 = _jxr_rbitstream_uint8(str);
  _jxr_rbitstream_uint8(str);
  if ( v8 != 0 || v9 != 0 || v10 != 1 )
    return -1;
  _jxr_r_TILE_HEADER_DC(image, str, alpha_flag: 0, tx, ty);
  if ( (image->header_flags2 & 1) != 0 )
    _jxr_r_TILE_HEADER_DC(image: image->alpha, str, alpha_flag: 1, tx, ty);
  v11 = image->extended_height >> 4;
  v12 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v11 = image->tile_row_height[ty];
    v12 = image->tile_column_width[tx];
  }
  for ( i = 0; i < v11; ++i )
  {
    _jxr_r_rotate_mb_strip(image, my: i);
    if ( (image->header_flags2 & 1) != 0 )
      _jxr_r_rotate_mb_strip(image: image->alpha, my: i);
    for ( j = 0; j < v12; ++j )
    {
      _jxr_r_MB_DC(image, str, alpha_flag: 0, tx, ty, mx: j, my: i);
      if ( image->bands_present == 3 )
        _jxr_complete_cur_dclp(image, tx, mx: j, my: i);
      if ( (image->header_flags2 & 1) != 0 )
      {
        _jxr_r_MB_DC(image: image->alpha, str, alpha_flag: 1, tx, ty, mx: j, my: i);
        alpha = image->alpha;
        if ( alpha->bands_present == 3 )
          _jxr_complete_cur_dclp(image: alpha, tx, mx: j, my: i);
      }
    }
    if ( (image->header_flags2 & 1) != 0 )
      backup_dc_strip(image: image->alpha, tx, ty, my: i);
    backup_dc_strip(image, tx, ty, my: i);
  }
  _jxr_rbitstream_syncbyte(pLeafNode: (bfx::DynKDNode *)str);
  return 0;
}


// ========================================================================
// ?_jxr_r_TILE_LP@@YAHPAUjxr_image@@PAUrbitstream@@II@Z
// EA  : 0x82913B38
// RVA : 0x00913B38
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

int __fastcall _jxr_r_TILE_LP(jxr_image *image, rbitstream *str, unsigned int tx, unsigned int ty)
{
  char v8; // r28
  char v9; // r31
  char v10; // r30
  unsigned int v11; // r21
  unsigned int v12; // r22
  unsigned int v13; // r28
  unsigned int i; // r23
  unsigned int j; // r30
  unsigned int k; // r26
  char v17; // r3
  jxr_image *alpha; // r31
  unsigned int num_lp_qps; // r4
  int v20; // r11
  unsigned int *p_num_lp_qps; // r10

  v8 = _jxr_rbitstream_uint8(str);
  v9 = _jxr_rbitstream_uint8(str);
  v10 = _jxr_rbitstream_uint8(str);
  _jxr_rbitstream_uint8(str);
  if ( v8 != 0 || v9 != 0 || v10 != 1 )
    return -1;
  _jxr_r_TILE_HEADER_LOWPASS(image, str, alpha_flag: 0, tx, ty);
  if ( (image->header_flags2 & 1) != 0 )
    _jxr_r_TILE_HEADER_LOWPASS(image: image->alpha, str, alpha_flag: 1, tx, ty);
  v11 = image->extended_height >> 4;
  v12 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v11 = image->tile_row_height[ty];
    v12 = image->tile_column_width[tx];
  }
  v13 = 0;
  for ( i = ((_cntlzw(image->header_flags2 & 1) & 0x20) == 0) + 1; v13 < v11; ++v13 )
  {
    _jxr_r_rotate_mb_strip(image, my: v13);
    if ( (image->header_flags2 & 1) != 0 )
      _jxr_r_rotate_mb_strip(image: image->alpha, my: v13);
    recover_dc_strip(image, tx, ty, my: v13);
    if ( (image->header_flags2 & 1) != 0 )
      recover_dc_strip(image: image->alpha, tx, ty, my: v13);
    for ( j = 0; j < v12; ++j )
    {
      for ( k = 0; k < i; ++k )
      {
        v17 = 0;
        alpha = image;
        if ( k != 0 )
          alpha = image->alpha;
        if ( (*((_DWORD *)alpha + 26) & 0x20000000) == 0 )
        {
          num_lp_qps = alpha->num_lp_qps;
          if ( num_lp_qps > 1 )
            v17 = _jxr_DECODE_QP_INDEX(str, index_count: num_lp_qps);
        }
        v20 = 0;
        if ( alpha->num_channels != 0 )
        {
          p_num_lp_qps = &alpha->num_lp_qps;
          do
          {
            ++v20;
            p_num_lp_qps += 7;
            *(_BYTE *)(84 * (alpha->tile_column_position[tx] + j) + *p_num_lp_qps + 8) = v17;
          }
          while ( v20 < alpha->num_channels );
        }
        _jxr_r_MB_LP(image: alpha, str, alpha_flag: 0, tx, ty, mx: j, my: v13);
        if ( alpha->bands_present != 3 )
          _jxr_complete_cur_dclp(image: alpha, tx, mx: j, my: v13);
      }
    }
    backup_dclp_strip(image, tx, ty, my: v13);
    if ( (image->header_flags2 & 1) != 0 )
      backup_dclp_strip(image: image->alpha, tx, ty, my: v13);
  }
  _jxr_rbitstream_syncbyte(pLeafNode: (bfx::DynKDNode *)str);
  return 0;
}


// ========================================================================
// ?_jxr_r_TILE_HP@@YAHPAUjxr_image@@PAUrbitstream@@II@Z
// EA  : 0x82913DF8
// RVA : 0x00913DF8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

int __fastcall _jxr_r_TILE_HP(jxr_image *image, rbitstream *str, unsigned int tx, unsigned int ty)
{
  char v8; // r28
  char v9; // r31
  char v10; // r30
  unsigned int v11; // r21
  unsigned int v12; // r22
  unsigned int v13; // r28
  unsigned int v14; // r23
  unsigned int v15; // r30
  int v16; // r24
  unsigned int v17; // r3
  jxr_image *alpha; // r31
  unsigned int num_hp_qps; // r4
  int v20; // r11
  unsigned int *p_num_lp_qps; // r10
  unsigned __int8 *v22; // r9
  int result; // r3

  v8 = _jxr_rbitstream_uint8(str);
  v9 = _jxr_rbitstream_uint8(str);
  v10 = _jxr_rbitstream_uint8(str);
  _jxr_rbitstream_uint8(str);
  if ( v8 != 0 || v9 != 0 || v10 != 1 )
    return -1;
  _jxr_r_TILE_HEADER_HIGHPASS(image, str, alpha_flag: 0, tx, ty);
  if ( (image->header_flags2 & 1) != 0 )
    _jxr_r_TILE_HEADER_HIGHPASS(image: image->alpha, str, alpha_flag: 1, tx, ty);
  v11 = image->extended_height >> 4;
  v12 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v11 = image->tile_row_height[ty];
    v12 = image->tile_column_width[tx];
  }
  v13 = 0;
  v14 = ((_cntlzw(image->header_flags2 & 1) & 0x20) == 0) + 1;
  if ( v11 != 0 )
  {
    while ( 1 )
    {
      _jxr_r_rotate_mb_strip(image, my: v13);
      if ( (image->header_flags2 & 1) != 0 )
        _jxr_r_rotate_mb_strip(image: image->alpha, my: v13);
      recover_dclp_strip(image, tx, ty, my: v13);
      if ( (image->header_flags2 & 1) != 0 )
        recover_dclp_strip(image: image->alpha, tx, ty, my: v13);
      v15 = 0;
      if ( v12 != 0 )
        break;
LABEL_28:
      backup_hp_strip(image, tx, ty, my: v13);
      if ( (image->header_flags2 & 1) != 0 )
        backup_hp_strip(image: image->alpha, tx, ty, my: v13);
      if ( ++v13 >= v11 )
        goto LABEL_31;
    }
    while ( 1 )
    {
      v16 = 0;
      if ( v14 != 0 )
        break;
LABEL_27:
      if ( ++v15 >= v12 )
        goto LABEL_28;
    }
    while ( 1 )
    {
      v17 = 0;
      alpha = image;
      if ( v16 != 0 )
        alpha = image->alpha;
      num_hp_qps = alpha->num_hp_qps;
      if ( num_hp_qps > 1 )
      {
        if ( (*((_DWORD *)alpha + 26) & 0x8000000) != 0 )
          v17 = *((unsigned __int8 *)&alpha->strip[0].cur[alpha->tile_column_position[tx] + v15] + 8);
        else
          v17 = _jxr_DECODE_QP_INDEX(str, index_count: num_hp_qps);
      }
      v20 = 0;
      if ( alpha->num_channels != 0 )
      {
        p_num_lp_qps = &alpha->num_lp_qps;
        v22 = &alpha->lp_quant_ch[15][v17];
        do
        {
          ++v20;
          p_num_lp_qps += 7;
          v22 += 16;
          *(_BYTE *)(84 * (alpha->tile_column_position[tx] + v15) + *p_num_lp_qps + 9) = *v22;
        }
        while ( v20 < alpha->num_channels );
      }
      result = _jxr_r_MB_CBP(image: alpha, str, alpha_flag: 0, tx, ty, mx: v15, my: v13);
      if ( result < 0 )
        break;
      result = _jxr_r_MB_HP(image: alpha, str, alpha_flag: 0, tx, ty, mx: v15, my: v13);
      if ( result < 0 )
        break;
      if ( ++v16 >= v14 )
        goto LABEL_27;
    }
  }
  else
  {
LABEL_31:
    _jxr_rbitstream_syncbyte(pLeafNode: (bfx::DynKDNode *)str);
    return 0;
  }
  return result;
}


// ========================================================================
// ?_jxr_r_TILE_FLEXBITS@@YAHPAUjxr_image@@PAUrbitstream@@II@Z
// EA  : 0x829140F0
// RVA : 0x009140F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

int __fastcall _jxr_r_TILE_FLEXBITS(jxr_image *image, rbitstream *str, unsigned int tx, unsigned int ty)
{
  char v8; // r29
  char v9; // r31
  char v10; // r30
  int v11; // r8
  int use_clr_fmt; // r11
  int num_channels; // r18
  signed int v14; // r17
  signed int v15; // r19
  unsigned int v16; // r25
  int v17; // r20
  unsigned int v18; // r28
  int v19; // r22
  jxr_image *alpha; // r30
  int v21; // r27
  int result; // r3
  int v23; // r31
  int i; // r29

  v8 = _jxr_rbitstream_uint8(str);
  v9 = _jxr_rbitstream_uint8(str);
  v10 = _jxr_rbitstream_uint8(str);
  _jxr_rbitstream_uint8(str);
  if ( v8 != 0 || v9 != 0 || v10 != 1 )
    return -1;
  v11 = image->header_flags2 & 0x10;
  *((_DWORD *)image + 9) &= 0xFFFFFFFu;
  if ( v11 != 0 )
    *((_DWORD *)image + 9) = (_jxr_rbitstream_uint4(str) << 28) | *((_DWORD *)image + 9) & 0xFFFFFFF;
  use_clr_fmt = image->use_clr_fmt;
  num_channels = image->num_channels;
  if ( use_clr_fmt == 1 || use_clr_fmt == 2 )
    num_channels = 1;
  v14 = image->extended_height >> 4;
  v15 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v14 = image->tile_row_height[ty];
    v15 = image->tile_column_width[tx];
  }
  v16 = 0;
  v17 = ((_cntlzw(image->header_flags2 & 1) & 0x20) == 0) + 1;
  if ( v14 <= 0 )
  {
LABEL_29:
    _jxr_rbitstream_syncbyte(pLeafNode: (bfx::DynKDNode *)str);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      _jxr_r_rotate_mb_strip(image, my: v16);
      if ( (image->header_flags2 & 1) != 0 )
        _jxr_r_rotate_mb_strip(image: image->alpha, my: v16);
      recover_dclphp_strip(image, tx, ty, my: v16);
      if ( (image->header_flags2 & 1) != 0 )
        recover_dclphp_strip(image: image->alpha, tx, ty, my: v16);
      v18 = 0;
      if ( v15 > 0 )
        break;
LABEL_26:
      backup_hp_strip(image, tx, ty, my: v16);
      if ( (image->header_flags2 & 1) != 0 )
        backup_hp_strip(image: image->alpha, tx, ty, my: v16);
      if ( (int)++v16 >= v14 )
        goto LABEL_29;
    }
    while ( 1 )
    {
      v19 = 0;
      if ( v17 > 0 )
        break;
LABEL_25:
      if ( (int)++v18 >= v15 )
        goto LABEL_26;
    }
    while ( 1 )
    {
      if ( v19 != 0 )
      {
        alpha = image->alpha;
        v21 = 1;
      }
      else
      {
        alpha = image;
        v21 = num_channels;
      }
      result = _jxr_r_MB_FLEXBITS(image: alpha, str, alpha_flag: 0, tx, ty, mx: v18, my: v16);
      if ( result < 0 )
        break;
      v23 = 0;
      for ( i = (__int16)*((_DWORD *)&alpha->strip[0].cur[alpha->tile_column_position[tx] + v18] + 2) >> 13;
            v23 < v21;
            ++v23 )
      {
        _jxr_propagate_hp_predictions(image: alpha, ch: v23, tx, mx: v18, mbhp_pred_mode: i);
      }
      if ( ++v19 >= v17 )
        goto LABEL_25;
    }
  }
  return result;
}


// ========================================================================
// ?_jxr_r_TILE_FLEXBITS_ESCAPE@@YAHPAUjxr_image@@II@Z
// EA  : 0x82914398
// RVA : 0x00914398
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_frequency.cpp
// ========================================================================

int __fastcall _jxr_r_TILE_FLEXBITS_ESCAPE(jxr_image *image, unsigned int tx, int ty)
{
  int use_clr_fmt; // r11
  int num_channels; // r27
  signed int v8; // r21
  signed int v9; // r22
  int i; // r24
  signed int j; // r29
  int v12; // r31
  int k; // r28

  use_clr_fmt = image->use_clr_fmt;
  num_channels = image->num_channels;
  if ( use_clr_fmt == 1 || use_clr_fmt == 2 )
    num_channels = 1;
  v8 = image->extended_height >> 4;
  v9 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v8 = image->tile_row_height[ty];
    v9 = image->tile_column_width[tx];
  }
  for ( i = 0; i < v8; ++i )
  {
    _jxr_r_rotate_mb_strip(image, my: i);
    recover_dclphp_strip(image, tx, ty, my: i);
    for ( j = 0; j < v9; ++j )
    {
      v12 = 0;
      for ( k = (__int16)*((_DWORD *)&image->strip[0].cur[image->tile_column_position[tx] + j] + 2) >> 13;
            v12 < num_channels;
            ++v12 )
      {
        _jxr_propagate_hp_predictions(image, ch: v12, tx, mx: j, mbhp_pred_mode: k);
      }
    }
    backup_hp_strip(image, tx, ty, my: i);
  }
  return 0;
}

