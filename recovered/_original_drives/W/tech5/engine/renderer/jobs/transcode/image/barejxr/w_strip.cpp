
// ========================================================================
// ?_jxr_select_lp_index@@YAEPAUjxr_image@@IIII@Z
// EA  : 0x829196B8
// RVA : 0x009196B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

int __fastcall _jxr_select_lp_index(
        jxr_image *image,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  jxr_tile_qp *v6; // r31

  if ( (*((_DWORD *)image + 26) & 0x10000000) != 0 )
    return 0;
  v6 = &image->tile_quant[(image->tile_rows + 1) * ty + tx];
  if ( v6->lp_map == nullptr )
    return 0;
  else
    return v6->lp_map[jxr_get_TILE_WIDTH(image, column: tx) * my + mx];
}


// ========================================================================
// ?_jxr_select_hp_index@@YAEPAUjxr_image@@IIII@Z
// EA  : 0x82919730
// RVA : 0x00919730
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

int __fastcall _jxr_select_hp_index(
        jxr_image *image,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  jxr_tile_qp *v6; // r31

  if ( (*((_DWORD *)image + 26) & 0x4000000) != 0 )
    return 0;
  v6 = &image->tile_quant[(image->tile_rows + 1) * ty + tx];
  if ( v6->hp_map == nullptr )
    return 0;
  else
    return v6->hp_map[jxr_get_TILE_WIDTH(image, column: tx) * my + mx];
}


// ========================================================================
// quantize_up_dclp
// EA  : 0x829197A8
// RVA : 0x009197A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall quantize_up_dclp(jxr_image *image, int use_my, int ch, unsigned int tx, int ty)
{
  int v10; // r21
  int use_clr_fmt; // r11
  unsigned __int8 dc_qp; // r11
  jxr_tile_qp *v13; // r11
  int v14; // r3
  signed int v15; // r24
  signed int v16; // r29
  char *v17; // r28
  int v18; // r22
  unsigned int v19; // r27
  unsigned __int8 v20; // r11
  jxr_tile_qp *v21; // r30
  unsigned __int8 v22; // r10
  jxr_tile_qp *v23; // r11
  signed int v24; // r3
  int v25; // r9
  int *v26; // r10
  int v27; // r11
  int v28; // r9
  int v29; // r10
  int v30; // ctr
  int v31; // r8
  int *v32; // r9
  int v33; // r11
  int v34; // r8

  v10 = 16;
  if ( ch > 0 )
  {
    use_clr_fmt = image->use_clr_fmt;
    if ( use_clr_fmt == 2 )
    {
      v10 = 8;
    }
    else if ( use_clr_fmt == 1 )
    {
      v10 = 4;
    }
  }
  if ( (*((_DWORD *)image + 26) & 0x40000000) != 0 )
  {
    dc_qp = image->dc_quant_ch[ch];
    goto LABEL_15;
  }
  v13 = &image->tile_quant[(image->tile_rows + 1) * ty + tx];
  if ( ch == 0 || v13->component_mode == JXR_CM_UNIFORM )
  {
LABEL_14:
    dc_qp = v13->channel[0].dc_qp;
    goto LABEL_15;
  }
  if ( v13->component_mode != JXR_CM_SEPARATE )
  {
    if ( v13->component_mode >= (unsigned int)JXR_CM_Reserved )
    {
      dc_qp = 0;
      goto LABEL_15;
    }
    v13 = (jxr_tile_qp *)((char *)v13 + 35 * ch);
    goto LABEL_14;
  }
  dc_qp = v13->channel[1].dc_qp;
LABEL_15:
  v14 = _jxr_quant_map(image, x: dc_qp, shift: 1);
  v15 = v14;
  v16 = 0;
  if ( image->extended_width >> 4 != 0 )
  {
    v17 = (char *)image + 28 * ch;
    v18 = v14 >> 1;
    v19 = tx;
    do
    {
      if ( (*((_DWORD *)image + 26) & 0x10000000) != 0 )
      {
        v20 = image->lp_quant_ch[ch][0];
      }
      else
      {
        v21 = &image->tile_quant[(image->tile_rows + 1) * ty + tx];
        if ( v21->lp_map != nullptr )
          v22 = v21->lp_map[jxr_get_TILE_WIDTH(image, column: tx) * use_my + v16];
        else
          v22 = 0;
        v23 = &image->tile_quant[(image->tile_rows + 1) * ty + tx];
        if ( ch == 0 || v23->component_mode == JXR_CM_UNIFORM )
          goto LABEL_29;
        if ( v23->component_mode == JXR_CM_SEPARATE )
        {
          v20 = v23->channel[1].lp_qp[v22];
          goto LABEL_30;
        }
        if ( v23->component_mode < (unsigned int)JXR_CM_Reserved )
        {
          v23 = (jxr_tile_qp *)((char *)v23 + 35 * ch);
LABEL_29:
          v20 = v23->channel[0].lp_qp[v22];
          goto LABEL_30;
        }
        v20 = 0;
      }
LABEL_30:
      *(_BYTE *)(84 * (image->tile_column_position[v19] + v16) + *((_DWORD *)v17 + 34) + 8) = v20;
      v24 = _jxr_quant_map(image, x: v20, shift: 1);
      v25 = 1;
      v26 = *(int **)(84 * (image->tile_column_position[v19] + v16) + *((_DWORD *)v17 + 34));
      v27 = *v26;
      if ( *v26 < 0 )
      {
        v25 = -1;
        v27 = -v27;
      }
      v28 = (v18 + v27) * v25;
      __twllei(v15, 0);
      *v26 = v28 / v15;
      __twlgei(v15 & ~(__ROL4__(v28, 1) - 1), 0xFFFFFFFF);
      v29 = 4;
      v30 = v10 - 1;
      do
      {
        v31 = 1;
        v32 = (int *)(*(_DWORD *)(84 * (image->tile_column_position[v19] + v16) + *((_DWORD *)v17 + 34)) + v29);
        v33 = *v32;
        if ( *v32 < 0 )
        {
          v31 = -1;
          v33 = -v33;
        }
        v29 += 4;
        v34 = (((3 * v24 + 1) >> 3) + v33) * v31;
        __twllei(v24, 0);
        *v32 = v34 / v24;
        __twlgei(v24 & ~(__ROL4__(v34, 1) - 1), 0xFFFFFFFF);
        --v30;
      }
      while ( v30 != 0 );
      ++v16;
    }
    while ( v16 < (signed int)(image->extended_width >> 4) );
  }
}


// ========================================================================
// _jxr_w_load_hpcbp_state
// EA  : 0x82919A90
// RVA : 0x00919A90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall jxr_w_load_hpcbp_state(jxr_image *image, int tx)
{
  int v2; // r8
  int v3; // r9
  int v4; // r10
  int v5; // ctr
  int v6; // r4
  int v7; // r31
  int *v8; // r11
  int v9; // r6
  int v10; // r7
  int v11; // r6
  int v12; // r29
  int v13; // r7
  int v14; // r5

  v2 = tx;
  v3 = tx;
  v4 = 0;
  v5 = 4;
  v7 = 48 * tx + 35;
  v6 = 32 * tx + 19;
  v8 = &image->hp_cbp_model.count0[15];
  do
  {
    v9 = v2 * 32 + v4;
    v8[307] = image->model_hp_buffer->bits[v9];
    v10 = v3 * 48 + v4;
    v8[323] = image->model_hp_buffer[v2].state[v4];
    *(v8 - 31) = image->hp_cbp_model_buffer->state[v10];
    *(v8 - 15) = image->hp_cbp_model_buffer[v3].count0[v4];
    v8[1] = image->hp_cbp_model_buffer[v3].count1[v4];
    v8[308] = image->model_hp_buffer->bits[v9 + 1];
    v8[324] = image->model_hp_buffer[v2].state[v4 + 1];
    *(v8 - 30) = image->hp_cbp_model_buffer->state[v10 + 1];
    *(v8 - 14) = image->hp_cbp_model_buffer[v3].count0[v4 + 1];
    v8[2] = image->hp_cbp_model_buffer[v3].count1[v4 + 1];
    v8[309] = image->model_hp_buffer[v2].bits[v4 + 2];
    v8[325] = image->model_hp_buffer[v2].state[v4 + 2];
    *(v8 - 29) = image->hp_cbp_model_buffer[v3].state[v4 + 2];
    *(v8 - 13) = image->hp_cbp_model_buffer[v3].count0[v4 + 2];
    v11 = v6 + v4;
    v12 = v3 * 48 + v4 + 3;
    v8[3] = image->hp_cbp_model_buffer[v3].count1[v4 + 2];
    v13 = v3 * 48 + v4 + 19;
    v14 = v7 + v4;
    v8[310] = image->model_hp_buffer[v2].bits[v4 + 3];
    v4 += 4;
    v8[326] = image->model_hp_buffer->bits[v11];
    *(v8 - 28) = image->hp_cbp_model_buffer->state[v12];
    *(v8 - 12) = image->hp_cbp_model_buffer->state[v13];
    v8 += 4;
    *v8 = image->hp_cbp_model_buffer->state[v14];
    --v5;
  }
  while ( v5 != 0 );
}


// ========================================================================
// _jxr_w_store_hpcbp_state
// EA  : 0x82919C90
// RVA : 0x00919C90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall jxr_w_store_hpcbp_state(jxr_image *image, int tx)
{
  int v2; // r8
  int v3; // r9
  int v4; // r10
  int v5; // ctr
  int v6; // r31
  int v7; // r30
  int *v8; // r11
  int v9; // r7
  int v10; // r6
  int v11; // r4
  int v12; // r5
  int v13; // r6

  v2 = tx;
  v3 = tx;
  v4 = 0;
  v5 = 4;
  v6 = 32 * tx + 19;
  v7 = 48 * tx + 35;
  v8 = &image->hp_cbp_model.count0[15];
  do
  {
    v9 = v2 * 32 + v4;
    image->model_hp_buffer->bits[v9] = v8[307];
    v10 = v3 * 48 + v4;
    image->model_hp_buffer[v2].state[v4] = v8[323];
    image->hp_cbp_model_buffer->state[v10] = *(v8 - 31);
    image->hp_cbp_model_buffer[v3].count0[v4] = *(v8 - 15);
    image->hp_cbp_model_buffer[v3].count1[v4] = v8[1];
    image->model_hp_buffer->bits[v9 + 1] = v8[308];
    image->model_hp_buffer[v2].state[v4 + 1] = v8[324];
    image->hp_cbp_model_buffer->state[v10 + 1] = *(v8 - 30);
    image->hp_cbp_model_buffer[v3].count0[v4 + 1] = *(v8 - 14);
    image->hp_cbp_model_buffer[v3].count1[v4 + 1] = v8[2];
    image->model_hp_buffer[v2].bits[v4 + 2] = v8[309];
    image->model_hp_buffer[v2].state[v4 + 2] = v8[325];
    image->hp_cbp_model_buffer[v3].state[v4 + 2] = *(v8 - 29);
    image->hp_cbp_model_buffer[v3].count0[v4 + 2] = *(v8 - 13);
    image->hp_cbp_model_buffer[v3].count1[v4 + 2] = v8[3];
    image->model_hp_buffer[v2].bits[v4 + 3] = v8[310];
    v11 = v3 * 48 + v4 + 3;
    v12 = v3 * 48 + v4 + 19;
    image->model_hp_buffer->bits[v6 + v4] = v8[326];
    v13 = v7 + v4;
    v4 += 4;
    image->hp_cbp_model_buffer->state[v11] = *(v8 - 28);
    image->hp_cbp_model_buffer->state[v12] = *(v8 - 12);
    v8 += 4;
    image->hp_cbp_model_buffer->state[v13] = *v8;
    --v5;
  }
  while ( v5 != 0 );
}


// ========================================================================
// wflush_to_tile_buffer
// EA  : 0x82919E90
// RVA : 0x00919E90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall wflush_to_tile_buffer(jxr_image *image, int my)
{
  int use_clr_fmt; // r11
  int v3; // r28
  signed int v4; // r27
  int v5; // r9
  signed int i; // r10
  int v7; // r5
  unsigned int v8; // r29
  int v9; // r11
  macroblock_s *v10; // r8
  int v11; // r7
  int *p_hp_diff_cbp; // r6
  int v13; // ctr
  int v14; // r26
  int v15; // r31
  int v16; // r6
  int v17; // r7
  int j; // ctr

  use_clr_fmt = image->use_clr_fmt;
  v3 = 256;
  if ( use_clr_fmt == 2 )
  {
    v3 = 136;
  }
  else if ( use_clr_fmt == 1 )
  {
    v3 = 76;
  }
  v4 = 0;
  if ( (int)image->tile_columns > 0 )
  {
    v5 = 0;
    do
    {
      for ( i = 0; i < (signed int)image->tile_column_width[v5]; ++i )
      {
        v7 = 0;
        if ( image->num_channels != 0 )
        {
          v8 = (image->extended_width >> 4) * my + image->tile_column_position[v5] + i;
          do
          {
            v9 = 28 * (v7 + 5);
            v10 = &image->mb_row_buffer[v7][v8];
            v11 = 0;
            p_hp_diff_cbp = &v10->hp_diff_cbp;
            v13 = 4;
            *((_BYTE *)v10 + 8) = *(_BYTE *)(84 * (image->tile_column_position[v5] + i)
                                           + *(int *)((char *)&image->user_flags + v9)
                                           + 8);
            *((_BYTE *)v10 + 9) = *(_WORD *)(84 * (image->tile_column_position[v5] + i)
                                           + *(int *)((char *)&image->user_flags + v9)
                                           + 8);
            v14 = *((_DWORD *)v10 + 2);
            v10->hp_cbp = *(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                    + *(int *)((char *)&image->user_flags + v9)
                                    + 12);
            v10->hp_diff_cbp = *(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                         + *(int *)((char *)&image->user_flags + v9)
                                         + 16);
            *((_DWORD *)v10 + 2) = v14 & 0xFFFF1FFF
                                 | *(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                             + *(int *)((char *)&image->user_flags + v9)
                                             + 8)
                                 & 0xE000;
            do
            {
              p_hp_diff_cbp[1] = *(_DWORD *)(4 * (21 * (image->tile_column_position[v5] + i) + v11 + 5)
                                           + *(int *)((char *)&image->user_flags + v9));
              p_hp_diff_cbp[2] = *(_DWORD *)(4 * (21 * (image->tile_column_position[v5] + i) + v11 + 6)
                                           + *(int *)((char *)&image->user_flags + v9));
              p_hp_diff_cbp[3] = *(_DWORD *)(4 * (21 * (image->tile_column_position[v5] + i) + v11 + 7)
                                           + *(int *)((char *)&image->user_flags + v9));
              v15 = 21 * (image->tile_column_position[v5] + i) + v11;
              v11 += 4;
              p_hp_diff_cbp += 4;
              *p_hp_diff_cbp = *(_DWORD *)(4 * (v15 + 8) + *(int *)((char *)&image->user_flags + v9));
              --v13;
            }
            while ( v13 != 0 );
            if ( v7 != 0 )
              v16 = v3;
            else
              v16 = 256;
            v17 = 0;
            for ( j = v16; j != 0; --j )
            {
              v10->data[v17] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                     + *(int *)((char *)&image->user_flags + v9))
                                         + v17 * 4);
              ++v17;
            }
            ++v7;
            *v10->pred_dclp = **(_DWORD **)(84 * (image->tile_column_position[v5] + i)
                                          + *(int *)((char *)&image->user_flags + v9)
                                          + 4);
            v10->pred_dclp[1] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                      + *(int *)((char *)&image->user_flags + v9)
                                                      + 4)
                                          + 4);
            v10->pred_dclp[2] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                      + *(int *)((char *)&image->user_flags + v9)
                                                      + 4)
                                          + 8);
            v10->pred_dclp[3] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                      + *(int *)((char *)&image->user_flags + v9)
                                                      + 4)
                                          + 12);
            v10->pred_dclp[4] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                      + *(int *)((char *)&image->user_flags + v9)
                                                      + 4)
                                          + 16);
            v10->pred_dclp[5] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                      + *(int *)((char *)&image->user_flags + v9)
                                                      + 4)
                                          + 20);
            v10->pred_dclp[6] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                      + *(int *)((char *)&image->user_flags + v9)
                                                      + 4)
                                          + 24);
          }
          while ( v7 < image->num_channels );
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (signed int)image->tile_columns );
  }
}


// ========================================================================
// wflush_collect_mb_strip_data
// EA  : 0x8291A230
// RVA : 0x0091A230
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall wflush_collect_mb_strip_data(jxr_image *image, int my)
{
  int use_clr_fmt; // r11
  int v3; // r28
  signed int v4; // r27
  int v5; // r9
  signed int i; // r10
  int v7; // r31
  unsigned int v8; // r29
  int v9; // r11
  macroblock_s *v10; // r8
  int v11; // ctr
  int v12; // r7
  int *p_hp_diff_cbp; // r6
  unsigned int v14; // r5
  int v15; // r30
  int v16; // r6
  int v17; // r7
  int j; // ctr

  use_clr_fmt = image->use_clr_fmt;
  v3 = 256;
  if ( use_clr_fmt == 2 )
  {
    v3 = 136;
  }
  else if ( use_clr_fmt == 1 )
  {
    v3 = 76;
  }
  v4 = 0;
  if ( (int)image->tile_columns > 0 )
  {
    v5 = 0;
    do
    {
      for ( i = 0; i < (signed int)image->tile_column_width[v5]; ++i )
      {
        v7 = 0;
        if ( image->num_channels != 0 )
        {
          v8 = (image->extended_width >> 4) * my + image->tile_column_position[v5] + i;
          do
          {
            v9 = 28 * (v7 + 5);
            v10 = &image->mb_row_buffer[v7][v8];
            v11 = 4;
            v12 = 0;
            p_hp_diff_cbp = &v10->hp_diff_cbp;
            *(_BYTE *)(84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9) + 8) = *((_BYTE *)v10 + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9) + 9) = *((_WORD *)v10 + 4);
            *(_DWORD *)(84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9) + 12) = v10->hp_cbp;
            *(_DWORD *)(84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9) + 16) = v10->hp_diff_cbp;
            v14 = 84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9);
            *(_DWORD *)(v14 + 8) = *(_DWORD *)(v14 + 8) & 0xFFFF1FFF | *((_DWORD *)v10 + 2) & 0xE000;
            do
            {
              *(_DWORD *)(4 * (21 * (image->tile_column_position[v5] + i) + v12 + 5)
                        + *(int *)((char *)&image->user_flags + v9)) = p_hp_diff_cbp[1];
              *(_DWORD *)(4 * (21 * (image->tile_column_position[v5] + i) + v12 + 6)
                        + *(int *)((char *)&image->user_flags + v9)) = p_hp_diff_cbp[2];
              *(_DWORD *)(4 * (21 * (image->tile_column_position[v5] + i) + v12 + 7)
                        + *(int *)((char *)&image->user_flags + v9)) = p_hp_diff_cbp[3];
              p_hp_diff_cbp += 4;
              v15 = 21 * (image->tile_column_position[v5] + i) + v12;
              v12 += 4;
              *(_DWORD *)(4 * (v15 + 8) + *(int *)((char *)&image->user_flags + v9)) = *p_hp_diff_cbp;
              --v11;
            }
            while ( v11 != 0 );
            if ( v7 != 0 )
              v16 = v3;
            else
              v16 = 256;
            v17 = 0;
            for ( j = v16; j != 0; --j )
            {
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                    + *(int *)((char *)&image->user_flags + v9))
                        + v17 * 4) = v10->data[v17];
              ++v17;
            }
            ++v7;
            **(_DWORD **)(84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9) + 4) = *v10->pred_dclp;
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                  + *(int *)((char *)&image->user_flags + v9)
                                  + 4)
                      + 4) = v10->pred_dclp[1];
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                  + *(int *)((char *)&image->user_flags + v9)
                                  + 4)
                      + 8) = v10->pred_dclp[2];
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                  + *(int *)((char *)&image->user_flags + v9)
                                  + 4)
                      + 12) = v10->pred_dclp[3];
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                  + *(int *)((char *)&image->user_flags + v9)
                                  + 4)
                      + 16) = v10->pred_dclp[4];
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                  + *(int *)((char *)&image->user_flags + v9)
                                  + 4)
                      + 20) = v10->pred_dclp[5];
            *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                  + *(int *)((char *)&image->user_flags + v9)
                                  + 4)
                      + 24) = v10->pred_dclp[6];
          }
          while ( v7 < image->num_channels );
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (signed int)image->tile_columns );
  }
}


// ========================================================================
// w_rotate_mb_strip
// EA  : 0x8291A5D8
// RVA : 0x0091A5D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall w_rotate_mb_strip(jxr_image *image)
{
  int v2; // r10
  unsigned __int16 *p_window_extra_top; // r11
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5

  _jxr_clear_strip_cur(image);
  v2 = 0;
  if ( image->num_channels != 0 )
  {
    p_window_extra_top = &image->window_extra_top;
    do
    {
      ++v2;
      v4 = *((_DWORD *)p_window_extra_top + 9);
      v5 = *((_DWORD *)p_window_extra_top + 8);
      v6 = *((_DWORD *)p_window_extra_top + 7);
      v7 = *((_DWORD *)p_window_extra_top + 11);
      *((_DWORD *)p_window_extra_top + 11) = *((_DWORD *)p_window_extra_top + 10);
      *((_DWORD *)p_window_extra_top + 10) = v4;
      *((_DWORD *)p_window_extra_top + 9) = v5;
      *((_DWORD *)p_window_extra_top + 8) = v6;
      p_window_extra_top += 14;
      *(_DWORD *)p_window_extra_top = v7;
    }
    while ( v2 < image->num_channels );
  }
}


// ========================================================================
// rgb_to_yuv444_up4
// EA  : 0x8291A650
// RVA : 0x0091A650
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall rgb_to_yuv444_up4(jxr_image *image)
{
  unsigned int v2; // r26
  int v3; // r30
  unsigned int v4; // r6
  int *data; // r31
  char *v6; // r28
  char *v7; // r27
  int v8; // r25
  int v9; // r24
  int v10; // r23
  int v11; // r25

  v2 = 0;
  if ( (image->extended_width & 0xFFFFFFF0) != 0 )
  {
    do
    {
      v3 = 256;
      v4 = *image->tile_column_position + v2;
      data = image->strip[1].up4[v4].data;
      v6 = (char *)((char *)image->strip[0].up4[v4].data - (char *)data);
      v7 = (char *)((char *)image->strip[2].up4[v4].data - (char *)data);
      do
      {
        v8 = *(int *)((char *)data + (_DWORD)v6);
        v9 = *data;
        v10 = *(int *)((char *)data + (_DWORD)v7) - v8;
        v11 = _jxr_ceil_div2(x: v10) + v8 - v9;
        *(int *)((char *)data + (_DWORD)v6) = _jxr_floor_div2(x: v11) + v9;
        --v3;
        *data = -v11;
        *(int *)((char *)data++ + (_DWORD)v7) = v10;
      }
      while ( v3 != 0 );
      ++v2;
    }
    while ( v2 < image->extended_width >> 4 );
  }
}


// ========================================================================
// cmyk_to_yuvk_up4
// EA  : 0x8291A710
// RVA : 0x0091A710
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall cmyk_to_yuvk_up4(jxr_image *image)
{
  unsigned int v2; // r25
  int v3; // r29
  unsigned int v4; // r5
  int *data; // r31
  char *v6; // r27
  char *v7; // r26
  char *v8; // r28
  int v9; // r24
  int v10; // r23
  int v11; // r22
  int v12; // r21
  int v13; // r24
  int v14; // r23
  int v15; // r3

  v2 = 0;
  if ( (image->extended_width & 0xFFFFFFF0) != 0 )
  {
    do
    {
      v3 = 256;
      v4 = *image->tile_column_position + v2;
      data = image->strip[1].up4[v4].data;
      v6 = (char *)((char *)image->strip[0].up4[v4].data - (char *)data);
      v7 = (char *)((char *)image->strip[2].up4[v4].data - (char *)data);
      v8 = (char *)((char *)image->strip[3].up4[v4].data - (char *)data);
      do
      {
        v9 = *(int *)((char *)data + (_DWORD)v6);
        v10 = *data;
        v11 = v9 - *(int *)((char *)data + (_DWORD)v7);
        v12 = *(int *)((char *)data + (_DWORD)v8);
        v13 = v9 - v10 - _jxr_floor_div2(x: v11);
        v14 = v12 - v10 - _jxr_floor_div2(x: v13);
        v15 = _jxr_floor_div2(x: v14);
        *(int *)((char *)data + (_DWORD)v6) = v14;
        *data = v13;
        *(int *)((char *)data + (_DWORD)v7) = v11;
        --v3;
        *(int *)((char *)data++ + (_DWORD)v8) = v12 - v15;
      }
      while ( v3 != 0 );
      ++v2;
    }
    while ( v2 < image->extended_width >> 4 );
  }
}


// ========================================================================
// yuv444_to_yuv422_up4
// EA  : 0x8291A7F0
// RVA : 0x0091A7F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall yuv444_to_yuv422_up4(jxr_image *image)
{
  int v2; // r31
  int *v3; // r30
  jxr_image::<unnamed_type_strip> *v4; // r21
  int i; // r20
  unsigned int v6; // r11
  unsigned int v7; // r8
  int *data; // r25
  unsigned int v9; // r23
  macroblock_s *v10; // r10
  int *v11; // r24
  int v12; // r26
  int *v13; // r29
  char *v14; // r28
  _DWORD *v15; // r10
  _DWORD *v16; // r30
  int v17; // r27
  int *v18; // r7
  int v19; // r11
  int v20; // r6
  int v21; // r9
  _DWORD *v22; // r11
  int j; // ctr
  int v24; // r8
  unsigned int v25; // r19
  int v26; // r4
  int v27; // r5
  int v28; // r3
  int v29; // r9
  int v30; // r8
  int v31; // r11
  unsigned int v32; // r3
  int *v33; // r9
  int v34; // r8
  int v35; // ctr
  int *v36; // r11
  int v37; // r4
  int *v38; // r10
  int v39; // r5
  int v40; // r6
  int v41; // r31
  int *v42; // r30
  int v43; // [sp+4Ch] [-B4h] BYREF
  char v44; // [sp+50h] [-B0h] BYREF

  v2 = 16;
  v3 = &v43;
  do
  {
    --v2;
    *++v3 = (int)_jxr_temp_calloc(image, count: (image->extended_width >> 1) & 0x7FFFFFF8, size: 4u);
  }
  while ( v2 != 0 );
  v4 = &image->strip[1];
  for ( i = 2; i != 0; --i )
  {
    v6 = 0;
    v7 = image->extended_width >> 4;
    if ( v7 != 0 )
    {
      do
      {
        if ( v6 != 0 )
          data = v4->up4[*image->tile_column_position - 1 + v6].data;
        else
          data = nullptr;
        v9 = v6 + 1;
        v10 = &v4->up4[*image->tile_column_position + v6];
        if ( v6 + 1 >= v7 )
          v11 = nullptr;
        else
          v11 = v10[1].data;
        v12 = 32 * v6;
        v13 = v11;
        v14 = &v44;
        v15 = v10->data + 2;
        v16 = data + 14;
        v17 = 16;
        do
        {
          v18 = (int *)(v12 + *(_DWORD *)v14);
          v19 = *(v15 - 2);
          if ( data != nullptr )
            v20 = 4 * (*(v15 - 1) + v16[1] + 2) + 6 * v19 + *v15 + *v16;
          else
            v20 = 2 * (4 * (*(v15 - 1) + 1) + 3 * v19 + *v15);
          *v18 = v20;
          v21 = 2;
          v22 = v15 - 3;
          for ( j = 6; j != 0; --j )
          {
            v24 = v22[3];
            v25 = (2 * v21) & 0xFFFFFFFC;
            v26 = v22[5];
            v21 += 2;
            v27 = v22[1];
            v28 = v22[4];
            v22 += 2;
            *(int *)((char *)v18 + v25) = 4 * (v28 + *v22 + 2) + 6 * v24 + v26 + v27;
          }
          if ( v11 != nullptr )
          {
            v30 = v15[10];
            v29 = *v13;
            v31 = 4 * (v15[13] + v15[11] + 2) + 6 * v15[12];
          }
          else
          {
            v29 = v15[10];
            v30 = 7 * v15[12];
            v31 = 4 * (v15[13] + v15[11] + 2);
          }
          --v17;
          v14 += 4;
          v18[7] = v31 + v30 + v29;
          v15 += 16;
          v16 += 16;
          v13 += 16;
        }
        while ( v17 != 0 );
        v6 = v9;
        v7 = image->extended_width >> 4;
      }
      while ( v9 < v7 );
    }
    v32 = 0;
    if ( v7 != 0 )
    {
      do
      {
        v33 = &v43;
        v34 = 32 * v32;
        v35 = 4;
        v36 = v4->up4[*image->tile_column_position + v32].data - 1;
        do
        {
          v37 = v33[2];
          v38 = (int *)(v34 + v33[1]);
          v39 = v33[3];
          v33 += 4;
          v40 = *v33;
          v36[1] = *v38 >> 4;
          v36[2] = v38[1] >> 4;
          v36[3] = v38[2] >> 4;
          v36[4] = v38[3] >> 4;
          v36[5] = v38[4] >> 4;
          v36[6] = v38[5] >> 4;
          v36[7] = v38[6] >> 4;
          v36[8] = v38[7] >> 4;
          v36[9] = *(int *)(v34 + v37) >> 4;
          v36[10] = *(int *)(v34 + v37 + 4) >> 4;
          v36[11] = *(int *)(v34 + v37 + 8) >> 4;
          v36[12] = *(int *)(v34 + v37 + 12) >> 4;
          v36[13] = *(int *)(v34 + v37 + 16) >> 4;
          v36[14] = *(int *)(v34 + v37 + 20) >> 4;
          v36[15] = *(int *)(v34 + v37 + 24) >> 4;
          v36[16] = *(int *)(v34 + v37 + 28) >> 4;
          v36[17] = *(int *)(v34 + v39) >> 4;
          v36[18] = *(int *)(v34 + v39 + 4) >> 4;
          v36[19] = *(int *)(v34 + v39 + 8) >> 4;
          v36[20] = *(int *)(v34 + v39 + 12) >> 4;
          v36[21] = *(int *)(v34 + v39 + 16) >> 4;
          v36[22] = *(int *)(v34 + v39 + 20) >> 4;
          v36[23] = *(int *)(v34 + v39 + 24) >> 4;
          v36[24] = *(int *)(v34 + v39 + 28) >> 4;
          v36[25] = *(int *)(v34 + v40) >> 4;
          v36[26] = *(int *)(v34 + v40 + 4) >> 4;
          v36[27] = *(int *)(v34 + v40 + 8) >> 4;
          v36[28] = *(int *)(v34 + v40 + 12) >> 4;
          v36[29] = *(int *)(v34 + v40 + 16) >> 4;
          v36[30] = *(int *)(v34 + v40 + 20) >> 4;
          v36[31] = *(int *)(v34 + v40 + 24) >> 4;
          v36 += 32;
          *v36 = *(int *)(v34 + v40 + 28) >> 4;
          --v35;
        }
        while ( v35 != 0 );
        ++v32;
      }
      while ( v32 < image->extended_width >> 4 );
    }
    ++v4;
  }
  v41 = 16;
  v42 = &v43;
  do
  {
    ++v42;
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)image);
    --v41;
  }
  while ( v41 != 0 );
}


// ========================================================================
// yuv422_to_yuv420_up3
// EA  : 0x8291AC50
// RVA : 0x0091AC50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall yuv422_to_yuv420_up3(jxr_image *image)
{
  unsigned __int8 *p_use_clr_fmt; // r25
  int v2; // r23
  int v3; // r22
  unsigned int v4; // r26
  int v5; // ctr
  int *v6; // r9
  _DWORD *v7; // r11
  _DWORD *v8; // r10
  int v9; // r6
  int v10; // r5
  int v11; // r29
  int v12; // r8
  int v13; // r4
  int v14; // r28
  int v15; // r27
  _DWORD *v16; // r31
  int v17; // r7
  int *v18; // r10
  int i; // ctr
  unsigned int v20; // r8
  int *v21; // r6
  int v22; // r31
  int v23; // r5
  int v24; // r6
  int v25; // r4
  int v26; // r6
  int v27; // r10
  _DWORD *v28; // r30
  int *v29; // r8
  int *v30; // r8

  p_use_clr_fmt = &image->use_clr_fmt;
  v2 = 2;
  v3 = image->cur_my + 3;
  do
  {
    v4 = 0;
    if ( (image->extended_width & 0xFFFFFFF0) != 0 )
    {
      do
      {
        v5 = 128;
        v6 = *(int **)(84 * (*image->tile_column_position + v4) + *((_DWORD *)p_use_clr_fmt + 32));
        v7 = v6 + 128;
        v8 = v6 + 128;
        do
        {
          *v8 = *(v8 - 128);
          ++v8;
          --v5;
        }
        while ( v5 != 0 );
        if ( v3 != 0 )
        {
          v16 = *(_DWORD **)(84 * (*image->tile_column_position + v4) + *((_DWORD *)p_use_clr_fmt + 33));
          *v6 = (4 * (v6[136] + v16[248] + 2) + 6 * v6[128] + v16[240] + v6[144]) >> 4;
          v6[1] = (4 * (v6[137] + v16[249] + 2) + 6 * v6[129] + v6[145] + v16[241]) >> 4;
          v6[2] = (4 * (v6[138] + v16[250] + 2) + 6 * v6[130] + v6[146] + v16[242]) >> 4;
          v6[3] = (4 * (v6[139] + v16[251] + 2) + 6 * v6[131] + v6[147] + v16[243]) >> 4;
          v6[4] = (4 * (v6[140] + v16[252] + 2) + 6 * v6[132] + v6[148] + v16[244]) >> 4;
          v6[5] = (4 * (v6[141] + v16[253] + 2) + 6 * v6[133] + v6[149] + v16[245]) >> 4;
          v6[6] = (4 * (v6[142] + v16[254] + 2) + 6 * v6[134] + v6[150] + v16[246]) >> 4;
          v6[7] = (4 * (v6[143] + v16[255] + 2) + 6 * v6[135] + v6[151] + v16[247]) >> 4;
        }
        else
        {
          v9 = v6[4];
          v10 = v6[5];
          v11 = 3 * v6[1];
          v12 = v6[6];
          v13 = v6[7];
          v14 = 3 * v6[2];
          v15 = 3 * v6[3];
          *v6 = (2 * (4 * (v6[8] + 1) + 3 * *v6 + v6[16])) >> 4;
          v6[1] = (2 * (4 * (v6[9] + 1) + v11 + v6[17])) >> 4;
          v6[2] = (2 * (4 * (v6[10] + 1) + v14 + v6[18])) >> 4;
          v6[3] = (2 * (4 * (v6[11] + 1) + v15 + v6[19])) >> 4;
          v6[4] = (2 * (4 * (v6[12] + 1) + 3 * v9 + v6[20])) >> 4;
          v6[5] = (2 * (4 * (v6[13] + 1) + 3 * v10 + v6[21])) >> 4;
          v6[6] = (2 * (4 * (v6[14] + 1) + 3 * v12 + v6[22])) >> 4;
          v6[7] = (2 * (4 * (v6[15] + 1) + 3 * v13 + v6[23])) >> 4;
        }
        v17 = 2;
        v18 = v6 + 143;
        for ( i = 6; i != 0; --i )
        {
          v20 = (4 * v17) & 0xFFFFFFF8;
          v21 = (int *)((char *)v6 + ((16 * v17) & 0xFFFFFFE0));
          *v21 = (4 * (*(v18 - 7) + v18[9] + 2) + 6 * v18[1] + *(v18 - 15) + v18[17]) >> 4;
          v21[1] = (4 * (*(v18 - 6) + v18[10] + 2) + 6 * v18[2] + *(v18 - 14) + v18[18]) >> 4;
          v6[v20 + 2] = (4 * (*(v18 - 5) + v18[11] + 2) + 6 * v18[3] + *(v18 - 13) + v18[19]) >> 4;
          v6[v20 + 3] = (4 * (*(v18 - 4) + v18[12] + 2) + 6 * v18[4] + *(v18 - 12) + v18[20]) >> 4;
          v6[v20 + 4] = (4 * (*(v18 - 3) + v18[13] + 2) + 6 * v18[5] + *(v18 - 11) + v18[21]) >> 4;
          v17 += 2;
          v6[v20 + 5] = (4 * (*(v18 - 2) + v18[14] + 2) + 6 * v18[6] + *(v18 - 10) + v18[22]) >> 4;
          v6[v20 + 6] = (4 * (*(v18 - 1) + v18[15] + 2) + 6 * v18[7] + *(v18 - 9) + v18[23]) >> 4;
          v22 = *v18;
          v23 = *(v18 - 8);
          v24 = v18[24];
          v25 = 6 * v18[8];
          v18 += 16;
          v6[v20 + 7] = (4 * (v22 + *v18 + 2) + v25 + v23 + v24) >> 4;
        }
        v26 = v6[248];
        v27 = 8 * (v17 / 2);
        if ( v3 + 1 >= (signed int)(image->extended_height >> 4) )
        {
          v30 = &v6[8 * (v17 / 2)];
          *v30 = (4 * (v26 + v6[232] + 2) + 6 * v6[240] + v6[224] + v6[240]) >> 4;
          v30[1] = (4 * (v6[249] + v6[233] + 2) + 6 * v6[241] + v6[241] + v6[225]) >> 4;
          v6[v27 + 2] = (4 * (v7[122] + v7[106] + 2) + 6 * v7[114] + v7[114] + v7[98]) >> 4;
          v6[v27 + 3] = (4 * (v6[251] + v6[235] + 2) + 6 * v6[243] + v6[243] + v6[227]) >> 4;
          v6[v27 + 4] = (4 * (v7[124] + v7[108] + 2) + 6 * v7[116] + v7[116] + v7[100]) >> 4;
          v6[v27 + 5] = (4 * (v6[253] + v6[237] + 2) + 6 * v6[245] + v6[245] + v6[229]) >> 4;
          v6[v27 + 6] = (4 * (v7[126] + v7[110] + 2) + 6 * v7[118] + v7[118] + v7[102]) >> 4;
          v6[v27 + 7] = (4 * (v6[255] + v6[239] + 2) + 6 * v6[247] + v6[247] + v6[231]) >> 4;
        }
        else
        {
          v28 = *(_DWORD **)(84 * (*image->tile_column_position + v4) + *((_DWORD *)p_use_clr_fmt + 31));
          v29 = &v6[8 * (v17 / 2)];
          *v29 = (4 * (v26 + v6[232] + 2) + 6 * v6[240] + *v28 + v6[224]) >> 4;
          v29[1] = (4 * (v6[249] + v6[233] + 2) + 6 * v6[241] + v28[1] + v6[225]) >> 4;
          v6[v27 + 2] = (4 * (v6[250] + v6[234] + 2) + 6 * v6[242] + v28[2] + v6[226]) >> 4;
          v6[v27 + 3] = (4 * (v6[251] + v6[235] + 2) + 6 * v6[243] + v28[3] + v6[227]) >> 4;
          v6[v27 + 4] = (4 * (v6[252] + v6[236] + 2) + 6 * v6[244] + v28[4] + v6[228]) >> 4;
          v6[v27 + 5] = (4 * (v6[253] + v6[237] + 2) + 6 * v6[245] + v28[5] + v6[229]) >> 4;
          v6[v27 + 6] = (4 * (v6[254] + v6[238] + 2) + 6 * v6[246] + v28[6] + v6[230]) >> 4;
          v6[v27 + 7] = (4 * (v6[255] + v6[239] + 2) + 6 * v6[247] + v28[7] + v6[231]) >> 4;
        }
        ++v4;
      }
      while ( v4 < image->extended_width >> 4 );
    }
    --v2;
    p_use_clr_fmt += 28;
  }
  while ( v2 != 0 );
}


// ========================================================================
// block_shuffle444
// EA  : 0x8291B790
// RVA : 0x0091B790
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall block_shuffle444(int *data)
{
  int *v1; // r11
  unsigned int v2; // r10
  int i; // ctr
  int v4; // r9
  int v5; // r8
  int v6; // r9
  int v7; // r6
  int v8; // r5
  int v9; // r4
  int v10; // r9
  char v11; // [sp+4Ch] [-414h] BYREF
  _BYTE v12[1032]; // [sp+50h] [-410h] BYREF

  v1 = (int *)&v11;
  v2 = 0;
  for ( i = 64; i != 0; --i )
  {
    v4 = 4 * (4 * (v2 >> 6) + (((int)v2 >> 2) & 3));
    v5 = (v2 >> 4) - 4 * (v2 >> 6);
    v2 += 4;
    v6 = 4 * (v4 + v5);
    v7 = data[v6];
    v8 = data[v6 + 1];
    v9 = data[v6 + 2];
    v10 = data[v6 + 3];
    v1[1] = v7;
    v1[2] = v8;
    v1[3] = v9;
    v1 += 4;
    *v1 = v10;
  }
  blkmov(a1: data, a2: v12, a3: 1024);
}


// ========================================================================
// collect_and_scale_up4
// EA  : 0x8291B840
// RVA : 0x0091B840
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall collect_and_scale_up4(jxr_image *image, int ty)
{
  unsigned __int8 shift_bits; // r29
  char v5; // r19
  int v6; // r31
  int v7; // r11
  _iobuf *v8; // r3
  int v9; // r18
  int v10; // r20
  int container_nc; // r29
  int v12; // r17
  int num_channels; // r21
  int v14; // r26
  signed int v15; // r11
  int v16; // r22
  unsigned int v17; // r11
  int v18; // r27
  int v19; // r25
  signed int width1; // r28
  int v21; // r24
  int v22; // r4
  int v23; // r30
  int v24; // r3
  int v25; // r8
  jxr_output_clr_fmt_e output_clr_fmt; // r11
  int v27; // r11
  int v28; // r6
  int v29; // r31
  int v30; // r11
  int v31; // ctr
  int v32; // r7
  int v33; // r10
  int v34; // r9
  unsigned int v35; // r11
  int v36; // r31
  int v37; // r30
  int v38; // r7
  int v39; // r5
  int v40; // r11
  int v41; // r6
  jxr_output_clr_fmt_e v42; // r10
  int v43; // r3
  int v44; // r10
  int m; // r4
  int v46; // r11
  int v47; // ctr
  int v48; // r9
  int v49; // r8
  int v50; // r7
  int v51; // r11
  unsigned __int16 *p_window_extra_top; // r9
  int i; // ctr
  int v54; // r10
  int v55; // r8
  jxr_image::<unnamed_type_strip> *strip; // r9
  int j; // r7
  int v58; // ctr
  int *v59; // r11
  int v60; // r5
  int v61; // ctr
  int *v62; // r11
  int v63; // r9
  int v64; // ctr
  int *v65; // r11
  int v66; // r8
  jxr_image::<unnamed_type_strip> *v67; // r9
  int k; // r8
  int v69; // ctr
  int *v70; // r11
  int v71; // r7
  jxr_output_clr_fmt_e v72; // r11
  jxr_output_clr_fmt_e v73; // r11
  jxr_output_clr_fmt_e v74; // r10
  unsigned int v75; // r7
  int v76; // ctr
  unsigned int v77; // r3
  int *data; // r11
  char *v79; // r10
  char *v80; // r9
  char *v81; // r8
  int v82; // r5
  int v83; // r4
  int v84; // r3
  _DWORD v85[292]; // [sp+50h] [-4490h] BYREF

  shift_bits = image->shift_bits;
  v5 = *((_DWORD *)image + 26) >= 0 ? 0 : 3;
  if ( image->output_clr_fmt == JXR_OCF_RGBE )
  {
LABEL_9:
    v7 = 0;
  }
  else
  {
    v6 = image->header_flags_fmt & 0xF;
    switch ( image->header_flags_fmt & 0xF )
    {
      case 0:
      case 3:
      case 4:
      case 6:
      case 7:
      case 0xF:
        goto LABEL_9;
      case 1:
        v7 = 128;
        break;
      case 2:
        v7 = 0x8000;
        break;
      case 8:
        v7 = 16;
        break;
      case 9:
        v7 = 512;
        break;
      case 0xA:
        v7 = 32;
        break;
      default:
        v8 = _iob_func();
        fprintf(str: v8 + 2, format: "XXXX Don't know how to scale bit depth %d?\n", v6);
        goto LABEL_9;
    }
  }
  v9 = v7 >> shift_bits;
  v10 = 0;
  container_nc = image->container_nc;
  v12 = image->tile_row_position[ty] + image->cur_my + 4;
  num_channels = image->num_channels;
  if ( (image->header_flags2 & 1) != 0 )
  {
    ++num_channels;
    v10 = container_nc - 1;
    image->strip[image->num_channels].up4 = image->alpha->strip[0].up4;
  }
  v14 = 0;
  v15 = image->extended_width >> 4;
  if ( v15 != 0 )
  {
    v16 = 0;
    while ( 1 )
    {
      image->inp_fun(a1: image, a2: v14, a3: v12, a4: v85);
      if ( v12 + 1 == image->extended_height >> 4 )
      {
        v17 = image->window_extra_top + image->height1;
        if ( ((v17 + 1) & 0xF) != 0 )
        {
          v18 = 0;
          if ( num_channels > 0 )
          {
            v19 = v17 & 0xF;
            width1 = image->width1;
            v21 = (image->window_extra_left + width1) & 0xF;
            while ( 1 )
            {
              v22 = 16;
              v23 = v19;
              v24 = v21;
              if ( v10 == 0 || (v25 = v10, v18 != num_channels - 1) )
                v25 = v18;
              if ( v18 > 0 )
              {
                output_clr_fmt = image->output_clr_fmt;
                if ( output_clr_fmt == JXR_OCF_YUV420 )
                  break;
                if ( output_clr_fmt == JXR_OCF_YUV422 )
                  goto LABEL_25;
              }
LABEL_26:
              v27 = v23 + 1;
              if ( v23 + 1 < 16 )
              {
                v28 = v27 * v22;
                v29 = 16 - v27;
                do
                {
                  v30 = 0;
                  v31 = v22;
                  v32 = v23 * v22;
                  do
                  {
                    v33 = v32 + v24;
                    if ( 16 * v14 + v30 <= width1 )
                      v33 = v32 + v30;
                    v34 = (v28 + v30++) * container_nc;
                    v85[v34 + v25] = v85[v33 * container_nc + v25];
                    --v31;
                  }
                  while ( v31 != 0 );
                  --v29;
                  v28 += v22;
                }
                while ( v29 != 0 );
              }
              if ( ++v18 >= num_channels )
                goto LABEL_34;
            }
            v23 = v19 >> 1;
LABEL_25:
            v24 = v21 >> 1;
            v22 = 8;
            goto LABEL_26;
          }
        }
      }
LABEL_34:
      if ( ++v14 == image->extended_width >> 4 )
      {
        v35 = image->window_extra_left + image->width1;
        if ( ((v35 + 1) & 0xF) != 0 )
        {
          v36 = 0;
          if ( num_channels > 0 )
            break;
        }
      }
LABEL_52:
      v49 = 0;
      v50 = 0;
      do
      {
        v51 = 0;
        if ( num_channels > 0 )
        {
          p_window_extra_top = &image->window_extra_top;
          for ( i = num_channels; i != 0; --i )
          {
            if ( v10 == 0 || (v54 = v10, v51 != num_channels - 1) )
              v54 = v51;
            p_window_extra_top += 14;
            ++v51;
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_window_extra_top + v16 * 84) + v49) = v85[v50 + v54];
          }
        }
        v49 += 4;
        v50 += container_nc;
      }
      while ( v49 < 1024 );
      if ( image->use_clr_fmt == 4 && image->output_clr_fmt == JXR_OCF_CMYK )
      {
        v55 = v9 >> 1;
        strip = image->strip;
        for ( j = 3; j != 0; --j )
        {
          v58 = 256;
          v59 = strip->up4[v16].data - 1;
          do
          {
            v60 = (v59[1] - v55) << v5;
            *++v59 = v60;
            --v58;
          }
          while ( v58 != 0 );
          ++strip;
        }
        v61 = 256;
        v62 = image->strip[3].up4[v16].data - 1;
        do
        {
          v63 = (v55 + v62[1]) << v5;
          *++v62 = v63;
          --v61;
        }
        while ( v61 != 0 );
        if ( num_channels == 5 )
        {
          v64 = 256;
          v65 = image->strip[4].up4[v16].data - 1;
          do
          {
            v66 = (v65[1] - v9) << v5;
            *++v65 = v66;
            --v64;
          }
          while ( v64 != 0 );
        }
      }
      else if ( num_channels > 0 )
      {
        v67 = image->strip;
        for ( k = num_channels; k != 0; --k )
        {
          v69 = 256;
          v70 = v67->up4[v16].data - 1;
          do
          {
            v71 = v70[1] - v9;
            *++v70 = v71 << v5;
            --v69;
          }
          while ( v69 != 0 );
          ++v67;
        }
      }
      ++v16;
      v15 = image->extended_width >> 4;
      if ( v14 >= v15 )
        goto LABEL_78;
    }
    v37 = v35 & 0xF;
    while ( 1 )
    {
      if ( v10 == 0 || (v38 = v10, v36 != num_channels - 1) )
        v38 = v36;
      v39 = 16;
      v40 = 16;
      v41 = v37;
      if ( v36 > 0 )
      {
        v42 = image->output_clr_fmt;
        if ( v42 == JXR_OCF_YUV420 )
        {
          v40 = 8;
        }
        else if ( v42 != JXR_OCF_YUV422 )
        {
          goto LABEL_46;
        }
        v41 = v37 >> 1;
        v39 = 8;
      }
LABEL_46:
      v43 = v41 + 1;
      v44 = 0;
      for ( m = v40; m != 0; --m )
      {
        v46 = v41 + 1;
        if ( v43 < v39 )
        {
          v47 = v39 - v43;
          do
          {
            v48 = (v44 + v46++) * container_nc + v38;
            v85[v48] = v85[(v44 + v41) * container_nc + v38];
            --v47;
          }
          while ( v47 != 0 );
        }
        v44 += v39;
      }
      if ( ++v36 >= num_channels )
        goto LABEL_52;
    }
  }
LABEL_78:
  if ( (unsigned int)image->use_clr_fmt - 1 <= 3 )
  {
    switch ( image->use_clr_fmt )
    {
      case 2u:
        goto LABEL_82;
      case 3u:
        v73 = image->output_clr_fmt;
        if ( v73 == JXR_OCF_RGB || v73 == JXR_OCF_RGBE )
          rgb_to_yuv444_up4(image);
        break;
      case 1u:
LABEL_82:
        v72 = image->output_clr_fmt;
        if ( v72 == JXR_OCF_RGB )
        {
          rgb_to_yuv444_up4(image);
          yuv444_to_yuv422_up4(image);
        }
        else if ( v72 == JXR_OCF_YUV444 )
        {
          yuv444_to_yuv422_up4(image);
        }
        return;
      default:
        v74 = image->output_clr_fmt;
        if ( v74 == JXR_OCF_CMYK )
        {
          cmyk_to_yuvk_up4(image);
        }
        else if ( v74 == JXR_OCF_CMYKDIRECT )
        {
          v75 = 0;
          if ( v15 != 0 )
          {
            do
            {
              v76 = 256;
              v77 = *image->tile_column_position + v75;
              data = image->strip[1].up4[v77].data;
              v79 = (char *)((char *)image->strip[0].up4[v77].data - (char *)data);
              v80 = (char *)((char *)image->strip[2].up4[v77].data - (char *)data);
              v81 = (char *)((char *)image->strip[3].up4[v77].data - (char *)data);
              do
              {
                v82 = *(int *)((char *)data + (_DWORD)v79);
                v83 = *data;
                v84 = *(int *)((char *)data + (_DWORD)v80);
                *(int *)((char *)data + (_DWORD)v79) = *(int *)((char *)data + (_DWORD)v81);
                *data = v82;
                *(int *)((char *)data + (_DWORD)v80) = v83;
                *(int *)((char *)data++ + (_DWORD)v81) = v84;
                --v76;
              }
              while ( v76 != 0 );
              ++v75;
            }
            while ( v75 < image->extended_width >> 4 );
          }
        }
        break;
    }
  }
}


// ========================================================================
// scale_and_shuffle_up3
// EA  : 0x8291BEB8
// RVA : 0x0091BEB8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall scale_and_shuffle_up3(jxr_image *image)
{
  jxr_output_clr_fmt_e output_clr_fmt; // r11
  int v3; // r27
  int i; // r30
  int v5; // r28
  macroblock_s **p_up3; // r31
  int use_clr_fmt; // r11
  int *v8; // r11
  unsigned int v9; // r10
  int *data; // r3
  int j; // ctr
  int v12; // r8
  int v13; // r9
  int v14; // r9
  int v15; // r5
  int *v16; // r9
  int v17; // r4
  int v18; // r6
  int v19; // r7
  int v20; // r5
  int v21; // r5
  int *v22; // r11
  unsigned int v23; // r10
  int k; // ctr
  int v25; // r9
  int v26; // r8
  int v27; // r9
  int v28; // r6
  int v29; // r5
  int v30; // r4
  int v31; // r9
  char v32; // [sp+4Ch] [-234h] BYREF
  char v33; // [sp+50h] [-230h] BYREF

  if ( image->use_clr_fmt == 1 )
  {
    output_clr_fmt = image->output_clr_fmt;
    if ( output_clr_fmt == JXR_OCF_RGB || output_clr_fmt == JXR_OCF_YUV444 )
      yuv422_to_yuv420_up3(image);
  }
  v3 = 0;
  if ( image->extended_width >> 4 != 0 )
  {
    for ( i = 0; ; ++i )
    {
      block_shuffle444(data: image->strip[0].up3[i].data);
      v5 = 1;
      if ( image->num_channels > 1u )
        break;
LABEL_20:
      if ( ++v3 >= (signed int)(image->extended_width >> 4) )
        return;
    }
    p_up3 = &image->strip[1].up3;
    while ( 1 )
    {
      use_clr_fmt = image->use_clr_fmt;
      if ( use_clr_fmt == 1 )
        break;
      if ( use_clr_fmt == 2 )
      {
        v8 = (int *)&v32;
        v9 = 0;
        data = (*p_up3)[i].data;
        for ( j = 32; j != 0; --j )
        {
          v12 = 2 * (4 * (v9 >> 5) + (((int)v9 >> 2) & 3));
          v13 = (v9 >> 4) - 2 * (v9 >> 5);
          v9 += 4;
          v14 = 4 * (v12 + v13);
          v15 = v14 + 2;
          v17 = v14 + 3;
          v16 = &data[v14];
          v18 = data[v15];
          v19 = v16[1];
          v20 = data[v17];
          v8[1] = *v16;
          v8[3] = v18;
          v8[2] = v19;
          v8 += 4;
          *v8 = v20;
        }
        v21 = 512;
LABEL_18:
        blkmov(a1: data, a2: &v33, a3: v21);
        goto LABEL_19;
      }
      block_shuffle444(data: (*p_up3)[i].data);
LABEL_19:
      ++v5;
      p_up3 += 7;
      if ( v5 >= image->num_channels )
        goto LABEL_20;
    }
    v22 = (int *)&v32;
    v23 = 0;
    data = (*p_up3)[i].data;
    for ( k = 16; k != 0; --k )
    {
      v25 = 2 * (4 * (v23 >> 5) + (((int)v23 >> 2) & 3));
      v26 = (v23 >> 4) - 2 * (v23 >> 5);
      v23 += 4;
      v27 = 4 * (v25 + v26);
      v28 = data[v27];
      v29 = data[v27 + 1];
      v30 = data[v27 + 2];
      v31 = data[v27 + 3];
      v22[1] = v28;
      v22[2] = v29;
      v22[3] = v30;
      v22 += 4;
      *v22 = v31;
    }
    v21 = 256;
    goto LABEL_18;
  }
}


// ========================================================================
// first_prefilter444_up2
// EA  : 0x8291C0B8
// RVA : 0x0091C0B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall first_prefilter444_up2(jxr_image *image, int ch, int ty)
{
  unsigned int *tile_row_height; // r9
  int v5; // r24
  unsigned int v6; // r11
  unsigned int v7; // r10
  unsigned int v8; // r10
  int v9; // r23
  int v10; // r20
  unsigned int v11; // r22
  int v12; // r31
  int *data; // r30
  int i; // r29
  int v15; // r31
  int v16; // r29
  int *v17; // r30
  int *v18; // r28
  int *v19; // r27
  int *v20; // r26
  int *v21; // r25
  unsigned int v22; // r28
  char *v23; // r27
  int *v24; // r31
  unsigned int *tile_column_position; // r7
  unsigned int disableTileOverlapFlag; // r10
  int *v27; // r30
  int *v28; // r3
  int *v29; // r11
  unsigned int v30; // r28
  char *v31; // r27
  int *v32; // r31
  unsigned int *v33; // r7
  unsigned int v34; // r10
  int *v35; // r30
  int *v36; // r11
  int *v37; // r11
  int v38; // r15
  unsigned int v39; // r16
  char *v40; // r14
  int v41; // r26
  int v42; // r31
  int v43; // r24
  int v44; // r25
  int *v45; // r30
  int *v46; // r29
  int v47; // r23
  unsigned int v48; // r22
  int *v49; // r28
  int *v50; // r27
  unsigned int v51; // r10
  unsigned int v52; // r11
  int v53; // r11
  unsigned int v55; // r6
  int *v56; // r31
  int *v57; // r30
  unsigned int v58; // r29
  unsigned int v59; // r11
  unsigned int v60; // r11
  _DWORD *v61; // r5
  int *v62; // r11
  unsigned int v63; // r11
  int *v64; // [sp+8h] [-138h]
  int *v65; // [sp+8h] [-138h]
  int *v66; // [sp+8h] [-138h]
  int *v67; // [sp+8h] [-138h]
  int *v68; // [sp+8h] [-138h]
  int *v69; // [sp+Ch] [-134h]
  int *v70; // [sp+Ch] [-134h]
  int *v71; // [sp+Ch] [-134h]
  int *v72; // [sp+Ch] [-134h]
  int *v73; // [sp+Ch] [-134h]
  int *v74; // [sp+10h] [-130h]
  int *v75; // [sp+10h] [-130h]
  int *v76; // [sp+10h] [-130h]
  int *v77; // [sp+10h] [-130h]
  int *v78; // [sp+10h] [-130h]
  int *v79; // [sp+14h] [-12Ch]
  int *v80; // [sp+14h] [-12Ch]
  int *v81; // [sp+14h] [-12Ch]
  int *v82; // [sp+14h] [-12Ch]
  int *v83; // [sp+14h] [-12Ch]
  int *v84; // [sp+18h] [-128h]
  int *v85; // [sp+18h] [-128h]
  int *v86; // [sp+18h] [-128h]
  int *v87; // [sp+18h] [-128h]
  int *v88; // [sp+18h] [-128h]
  int *v89; // [sp+1Ch] [-124h]
  int *v90; // [sp+1Ch] [-124h]
  int *v91; // [sp+1Ch] [-124h]
  int *v92; // [sp+1Ch] [-124h]
  int *v93; // [sp+1Ch] [-124h]
  int *v94; // [sp+20h] [-120h]
  int *v95; // [sp+20h] [-120h]
  int *v96; // [sp+20h] [-120h]
  int *v97; // [sp+20h] [-120h]
  int *v98; // [sp+20h] [-120h]
  int *v99; // [sp+24h] [-11Ch]
  int *v100; // [sp+24h] [-11Ch]
  int *v101; // [sp+24h] [-11Ch]
  int *v102; // [sp+24h] [-11Ch]
  int *v103; // [sp+24h] [-11Ch]
  int v104; // [sp+28h] [-118h]
  int v105; // [sp+28h] [-118h]
  int v106; // [sp+28h] [-118h]
  int v107; // [sp+28h] [-118h]
  int v108; // [sp+28h] [-118h]
  int v109; // [sp+2Ch] [-114h]
  int v110; // [sp+2Ch] [-114h]
  int v111; // [sp+2Ch] [-114h]
  int v112; // [sp+2Ch] [-114h]
  int v113; // [sp+2Ch] [-114h]
  int v114; // [sp+30h] [-110h]
  int v115; // [sp+30h] [-110h]
  int v116; // [sp+30h] [-110h]
  int v117; // [sp+30h] [-110h]
  int v118; // [sp+30h] [-110h]
  int v119; // [sp+34h] [-10Ch]
  int v120; // [sp+34h] [-10Ch]
  int v121; // [sp+34h] [-10Ch]
  int v122; // [sp+34h] [-10Ch]
  int v123; // [sp+34h] [-10Ch]
  int v124; // [sp+38h] [-108h]
  int v125; // [sp+38h] [-108h]
  int v126; // [sp+38h] [-108h]
  int v127; // [sp+38h] [-108h]
  int v128; // [sp+38h] [-108h]
  int v129; // [sp+3Ch] [-104h]
  int v130; // [sp+3Ch] [-104h]
  int v131; // [sp+3Ch] [-104h]
  int v132; // [sp+3Ch] [-104h]
  int v133; // [sp+3Ch] [-104h]
  int v134; // [sp+40h] [-100h]
  int v135; // [sp+40h] [-100h]
  int v136; // [sp+40h] [-100h]
  int v137; // [sp+40h] [-100h]
  int v138; // [sp+40h] [-100h]
  int v139; // [sp+44h] [-FCh]
  int v140; // [sp+44h] [-FCh]
  int v141; // [sp+44h] [-FCh]
  int v142; // [sp+44h] [-FCh]
  int v143; // [sp+44h] [-FCh]
  int v144; // [sp+48h] [-F8h]
  int v145; // [sp+48h] [-F8h]
  int v146; // [sp+48h] [-F8h]
  int v147; // [sp+48h] [-F8h]
  int v148; // [sp+48h] [-F8h]
  int v149; // [sp+4Ch] [-F4h]
  int v150; // [sp+4Ch] [-F4h]
  int v151; // [sp+4Ch] [-F4h]
  int v152; // [sp+4Ch] [-F4h]
  int v153; // [sp+4Ch] [-F4h]
  int v154; // [sp+50h] [-F0h]
  int v155; // [sp+50h] [-F0h]
  int v156; // [sp+50h] [-F0h]
  int v157; // [sp+50h] [-F0h]
  int v158; // [sp+50h] [-F0h]
  int v159; // [sp+58h] [-E8h]
  int v160; // [sp+58h] [-E8h]
  int v161; // [sp+58h] [-E8h]
  int v162; // [sp+58h] [-E8h]
  int v163; // [sp+58h] [-E8h]
  int v164; // [sp+60h] [-E0h]
  int v165; // [sp+60h] [-E0h]
  int v166; // [sp+60h] [-E0h]
  int v167; // [sp+60h] [-E0h]
  int v168; // [sp+60h] [-E0h]
  int v169; // [sp+68h] [-D8h]
  int v170; // [sp+68h] [-D8h]
  int v171; // [sp+68h] [-D8h]
  int v172; // [sp+68h] [-D8h]
  int v173; // [sp+68h] [-D8h]
  int v174; // [sp+70h] [-D0h]
  int v175; // [sp+70h] [-D0h]
  int v176; // [sp+70h] [-D0h]
  int v177; // [sp+70h] [-D0h]
  int v178; // [sp+70h] [-D0h]
  int v179; // [sp+78h] [-C8h]
  int v180; // [sp+78h] [-C8h]
  int v181; // [sp+78h] [-C8h]
  int v182; // [sp+78h] [-C8h]
  int v183; // [sp+78h] [-C8h]
  int v184; // [sp+80h] [-C0h]
  int v185; // [sp+80h] [-C0h]
  int v186; // [sp+80h] [-C0h]
  int v187; // [sp+80h] [-C0h]
  int v188; // [sp+80h] [-C0h]
  int v189; // [sp+88h] [-B8h]
  int v190; // [sp+88h] [-B8h]
  int v191; // [sp+88h] [-B8h]
  int v192; // [sp+88h] [-B8h]
  int v193; // [sp+88h] [-B8h]
  unsigned int v194; // [sp+90h] [-B0h]
  int v195; // [sp+94h] [-ACh]
  int v196; // [sp+98h] [-A8h]
  unsigned int v197; // [sp+9Ch] [-A4h]

  tile_row_height = image->tile_row_height;
  v5 = ch;
  v6 = image->cur_my + 2;
  v7 = tile_row_height[ty];
  if ( v6 >= v7 )
  {
    v6 -= v7;
    ++ty;
  }
  v8 = tile_row_height[ty];
  if ( v6 >= v8 )
  {
    v6 -= v8;
    ++ty;
  }
  v9 = 4 * ty;
  v10 = 0;
  v194 = 4 * ty;
  v195 = 0;
  v11 = image->tile_row_position[ty] + v6;
  v197 = v11;
  if ( image->tile_columns == 0 )
    return;
  while ( 2 )
  {
    if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
    {
      v12 = 4;
      data = image->strip[v5].up2[image->tile_column_position[v10]].data;
      for ( i = 3; i != 0; --i )
      {
        _jxr_4PreFilter(
          a: &data[4 * ((4 * (v12 - 2)) & 0xFFFFFFF0) + 4 * ((v12 - 2) & 3)],
          b: &data[64 * ((v12 - 1) / 4) + 4 * ((v12 - 1) % 4)],
          c: &data[64 * (v12 / 4) + 4 * (v12 % 4)],
          d: &data[64 * ((v12 + 1) / 4) + 4 * ((v12 + 1) % 4)]);
        _jxr_4PreFilter(
          a: &data[4 * ((4 * (v12 - 2)) & 0xFFFFFFF0) + 1 + 4 * ((v12 - 2) & 3)],
          b: &data[64 * ((v12 - 1) / 4) + 1 + 4 * ((v12 - 1) % 4)],
          c: &data[64 * (v12 / 4) + 1 + 4 * (v12 % 4)],
          d: &data[64 * ((v12 + 1) / 4) + 1 + 4 * ((v12 + 1) % 4)]);
        v12 += 4;
      }
    }
    if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
    {
      v15 = 4;
      v16 = 3;
      v17 = image->strip[v5].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
      do
      {
        v18 = &v17[64 * ((v15 + 1) / 4) + 4 * ((v15 + 1) % 4)];
        v19 = &v17[64 * (v15 / 4) + 4 * (v15 % 4)];
        v20 = &v17[64 * ((v15 - 1) / 4) + 4 * ((v15 - 1) % 4)];
        v21 = &v17[4 * ((4 * (v15 - 2)) & 0xFFFFFFF0) + 4 * ((v15 - 2) & 3)];
        _jxr_4PreFilter(a: v21 + 50, b: v20 + 50, c: v19 + 50, d: v18 + 50);
        _jxr_4PreFilter(a: v21 + 51, b: v20 + 51, c: v19 + 51, d: v18 + 51);
        --v16;
        v15 += 4;
      }
      while ( v16 != 0 );
    }
    if ( v11 == 0
      || image->disableTileOverlapFlag != 0 && v11 == *(unsigned int *)((char *)image->tile_row_position + v9) )
    {
      v22 = 0;
      if ( image->tile_column_width[v10] != 0 )
      {
        v23 = (char *)image + 28 * v5;
        do
        {
          v24 = *(int **)(84 * (image->tile_column_position[v10] + v22) + *((_DWORD *)v23 + 33));
          _jxr_4PreFilter(a: v24 + 2, b: v24 + 3, c: v24 + 16, d: v24 + 17);
          _jxr_4PreFilter(a: v24 + 18, b: v24 + 19, c: v24 + 32, d: v24 + 33);
          _jxr_4PreFilter(a: v24 + 34, b: v24 + 35, c: v24 + 48, d: v24 + 49);
          _jxr_4PreFilter(a: v24 + 6, b: v24 + 7, c: v24 + 20, d: v24 + 21);
          _jxr_4PreFilter(a: v24 + 22, b: v24 + 23, c: v24 + 36, d: v24 + 37);
          _jxr_4PreFilter(a: v24 + 38, b: v24 + 39, c: v24 + 52, d: v24 + 53);
          tile_column_position = image->tile_column_position;
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( tile_column_position[v10] + v22 != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_26;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            goto LABEL_27;
          }
          if ( v22 != 0 )
          {
LABEL_26:
            v27 = *(int **)(84 * (tile_column_position[v10] + v22) + *((_DWORD *)v23 + 33) - 84);
            _jxr_4PreFilter(a: v27 + 50, b: v27 + 51, c: v24, d: v24 + 1);
            _jxr_4PreFilter(a: v27 + 54, b: v27 + 55, c: v24 + 4, d: v24 + 5);
          }
LABEL_27:
          ++v22;
        }
        while ( v22 < image->tile_column_width[v10] );
      }
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        v28 = image->strip[v5].up2[image->tile_column_position[v10]].data;
        _jxr_4PreFilter(a: v28, b: v28 + 1, c: v28 + 4, d: v28 + 5);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v29 = image->strip[v5].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4PreFilter(a: v29 + 51, b: v29 + 50, c: v29 + 55, d: v29 + 54);
      }
    }
    if ( v11 + 1 == image->extended_height >> 4
      || image->disableTileOverlapFlag != 0
      && v11 == *(unsigned int *)((char *)image->tile_row_position + v9)
              + *(unsigned int *)((char *)image->tile_row_height + v9)
              - 1 )
    {
      v30 = 0;
      if ( image->tile_column_width[v10] != 0 )
      {
        v31 = (char *)image + 28 * v5;
        do
        {
          v32 = *(int **)(84 * (image->tile_column_position[v10] + v30) + *((_DWORD *)v31 + 33));
          _jxr_4PreFilter(a: v32 + 202, b: v32 + 203, c: v32 + 216, d: v32 + 217);
          _jxr_4PreFilter(a: v32 + 218, b: v32 + 219, c: v32 + 232, d: v32 + 233);
          _jxr_4PreFilter(a: v32 + 234, b: v32 + 235, c: v32 + 248, d: v32 + 249);
          _jxr_4PreFilter(a: v32 + 206, b: v32 + 207, c: v32 + 220, d: v32 + 221);
          _jxr_4PreFilter(a: v32 + 222, b: v32 + 223, c: v32 + 236, d: v32 + 237);
          _jxr_4PreFilter(a: v32 + 238, b: v32 + 239, c: v32 + 252, d: v32 + 253);
          v33 = image->tile_column_position;
          v34 = image->disableTileOverlapFlag;
          if ( v33[v10] + v30 != 0 )
          {
            if ( v34 == 0 )
              goto LABEL_44;
          }
          else if ( v34 == 0 )
          {
            goto LABEL_45;
          }
          if ( v30 != 0 )
          {
LABEL_44:
            v35 = *(int **)(84 * (v33[v10] + v30) + *((_DWORD *)v31 + 33) - 84);
            _jxr_4PreFilter(a: v35 + 250, b: v35 + 251, c: v32 + 200, d: v32 + 201);
            _jxr_4PreFilter(a: v35 + 254, b: v35 + 255, c: v32 + 204, d: v32 + 205);
          }
LABEL_45:
          ++v30;
        }
        while ( v30 < image->tile_column_width[v10] );
      }
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        v36 = image->strip[v5].up2[image->tile_column_position[v10]].data;
        _jxr_4PreFilter(a: v36 + 204, b: v36 + 205, c: v36 + 200, d: v36 + 201);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v37 = image->strip[v5].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4PreFilter(a: v37 + 255, b: v37 + 254, c: v37 + 251, d: v37 + 250);
      }
    }
    v38 = v10;
    v39 = 0;
    if ( image->tile_column_width[v10] == 0 )
      goto LABEL_93;
    v40 = (char *)image + 28 * ch;
    do
    {
      v41 = 4;
      v196 = 3;
      do
      {
        v42 = *(_DWORD *)(84 * (image->tile_column_position[v10] + v39) + *((_DWORD *)v40 + 33));
        v43 = 16 * (v41 / 4) + v41 % 4;
        v44 = 16 * ((v41 + 1) / 4) + (v41 + 1) % 4;
        v45 = (int *)(16 * v44 + v42);
        v46 = (int *)(16 * v43 + v42);
        v47 = 16 * ((v41 - 1) / 4) + (v41 - 1) % 4;
        v48 = ((4 * (v41 - 2)) & 0xFFFFFFF0) + ((v41 - 2) & 3);
        v49 = (int *)(16 * v47 + v42);
        v50 = (int *)(16 * v48 + v42);
        _jxr_4x4PreFilter(
          a: v50 + 2,
          b: v50 + 3,
          c: (int *)(16 * (v48 + 4) + v42),
          d: v50 + 17,
          e: v49 + 2,
          f: v49 + 3,
          g: (int *)(16 * (v47 + 4) + v42),
          h: v49 + 17,
          i: v64,
          j: v69,
          k: v74,
          l: v79,
          m: v84,
          n: v89,
          o: v94,
          p: v99,
          a17: v104,
          a18: v109,
          a19: v114,
          a20: v119,
          a21: v124,
          a22: v129,
          a23: v134,
          a24: v139,
          a25: v144,
          a26: v149,
          a27: v154,
          a28: v46 + 2,
          a29: v159,
          a30: v46 + 3,
          a31: v164,
          a32: (_DWORD *)(16 * (v43 + 4) + v42),
          a33: v169,
          a34: v46 + 17,
          a35: v174,
          ia: v45 + 2,
          a37: v179,
          ja: v45 + 3,
          a39: v184,
          ka: (int *)(16 * (v44 + 4) + v42),
          a41: v189,
          la: v45 + 17);
        _jxr_4x4PreFilter(
          a: v50 + 18,
          b: v50 + 19,
          c: (int *)(16 * (v48 + 8) + v42),
          d: v50 + 33,
          e: v49 + 18,
          f: v49 + 19,
          g: (int *)(16 * (v47 + 8) + v42),
          h: v49 + 33,
          i: v65,
          j: v70,
          k: v75,
          l: v80,
          m: v85,
          n: v90,
          o: v95,
          p: v100,
          a17: v105,
          a18: v110,
          a19: v115,
          a20: v120,
          a21: v125,
          a22: v130,
          a23: v135,
          a24: v140,
          a25: v145,
          a26: v150,
          a27: v155,
          a28: v46 + 18,
          a29: v160,
          a30: v46 + 19,
          a31: v165,
          a32: (_DWORD *)(16 * (v43 + 8) + v42),
          a33: v170,
          a34: v46 + 33,
          a35: v175,
          ia: v45 + 18,
          a37: v180,
          ja: v45 + 19,
          a39: v185,
          ka: (int *)(16 * (v44 + 8) + v42),
          a41: v190,
          la: v45 + 33);
        _jxr_4x4PreFilter(
          a: v50 + 34,
          b: v50 + 35,
          c: (int *)(16 * (v48 + 12) + v42),
          d: v50 + 49,
          e: v49 + 34,
          f: v49 + 35,
          g: (int *)(16 * (v47 + 12) + v42),
          h: v49 + 49,
          i: v66,
          j: v71,
          k: v76,
          l: v81,
          m: v86,
          n: v91,
          o: v96,
          p: v101,
          a17: v106,
          a18: v111,
          a19: v116,
          a20: v121,
          a21: v126,
          a22: v131,
          a23: v136,
          a24: v141,
          a25: v146,
          a26: v151,
          a27: v156,
          a28: v46 + 34,
          a29: v161,
          a30: v46 + 35,
          a31: v166,
          a32: (_DWORD *)(16 * (v43 + 12) + v42),
          a33: v171,
          a34: v46 + 49,
          a35: v176,
          ia: v45 + 34,
          a37: v181,
          ja: v45 + 35,
          a39: v186,
          ka: (int *)(16 * (v44 + 12) + v42),
          a41: v191,
          la: v45 + 49);
        v51 = image->disableTileOverlapFlag;
        v52 = image->tile_column_position[v10] + v39;
        if ( v52 >= (image->extended_width >> 4) - 1 )
        {
          if ( v51 == 0 )
            goto LABEL_61;
LABEL_59:
          if ( v39 == image->tile_column_width[v38] - 1 )
            goto LABEL_61;
          goto LABEL_60;
        }
        if ( v51 != 0 )
          goto LABEL_59;
LABEL_60:
        v53 = *(_DWORD *)(84 * (v52 + 1) + *((_DWORD *)v40 + 33));
        _jxr_4x4PreFilter(
          a: v50 + 50,
          b: v50 + 51,
          c: (int *)(16 * v48 + v53),
          d: (int *)(16 * v48 + v53 + 4),
          e: v49 + 50,
          f: v49 + 51,
          g: (int *)(16 * v47 + v53),
          h: (int *)(16 * v47 + v53 + 4),
          i: v64,
          j: v69,
          k: v74,
          l: v79,
          m: v84,
          n: v89,
          o: v94,
          p: v99,
          a17: v104,
          a18: v109,
          a19: v114,
          a20: v119,
          a21: v124,
          a22: v129,
          a23: v134,
          a24: v139,
          a25: v144,
          a26: v149,
          a27: v154,
          a28: v46 + 50,
          a29: v159,
          a30: v46 + 51,
          a31: v164,
          a32: (_DWORD *)(16 * v43 + v53),
          a33: v169,
          a34: (_DWORD *)(16 * v43 + v53 + 4),
          a35: v174,
          ia: v45 + 50,
          a37: v179,
          ja: v45 + 51,
          a39: v184,
          ka: (int *)(16 * v44 + v53),
          a41: v189,
          la: (int *)(16 * v44 + v53 + 4));
LABEL_61:
        v41 += 4;
      }
      while ( v196-- != 1 );
      if ( (signed int)(v197 + 1) < (signed int)(image->extended_height >> 4) )
      {
        v55 = 84 * (image->tile_column_position[v10] + v39);
        v56 = *(int **)(v55 + *((_DWORD *)v40 + 33));
        v57 = *(int **)(v55 + *((_DWORD *)v40 + 32));
        if ( v195 == 0 && v39 == 0 )
        {
          if ( image->disableTileOverlapFlag == 0 )
          {
            v58 = v194;
            goto LABEL_67;
          }
LABEL_70:
          v58 = v194;
          if ( v197 != image->tile_row_position[v194 / 4] + image->tile_row_height[v194 / 4] - 1 )
          {
LABEL_67:
            _jxr_4PreFilter(a: v56 + 200, b: v56 + 204, c: v57, d: v57 + 4);
            _jxr_4PreFilter(a: v56 + 201, b: v56 + 205, c: v57 + 1, d: v57 + 5);
          }
          goto LABEL_73;
        }
        if ( image->disableTileOverlapFlag == 0 )
        {
          v58 = v194;
          goto LABEL_77;
        }
        if ( v39 == 0 )
          goto LABEL_70;
        v58 = v194;
LABEL_73:
        if ( image->disableTileOverlapFlag == 0
          || v197 != *(unsigned int *)((char *)image->tile_row_position + v58)
                   + *(unsigned int *)((char *)image->tile_row_height + v58)
                   - 1 )
        {
LABEL_77:
          _jxr_4x4PreFilter(
            a: v56 + 202,
            b: v56 + 203,
            c: v56 + 216,
            d: v56 + 217,
            e: v56 + 206,
            f: v56 + 207,
            g: v56 + 220,
            h: v56 + 221,
            i: v64,
            j: v69,
            k: v74,
            l: v79,
            m: v84,
            n: v89,
            o: v94,
            p: v99,
            a17: v104,
            a18: v109,
            a19: v114,
            a20: v119,
            a21: v124,
            a22: v129,
            a23: v134,
            a24: v139,
            a25: v144,
            a26: v149,
            a27: v154,
            a28: v57 + 2,
            a29: v159,
            a30: v57 + 3,
            a31: v164,
            a32: v57 + 16,
            a33: v169,
            a34: v57 + 17,
            a35: v174,
            ia: v57 + 6,
            a37: v179,
            ja: v57 + 7,
            a39: v184,
            ka: v57 + 20,
            a41: v189,
            la: v57 + 21);
          _jxr_4x4PreFilter(
            a: v56 + 218,
            b: v56 + 219,
            c: v56 + 232,
            d: v56 + 233,
            e: v56 + 222,
            f: v56 + 223,
            g: v56 + 236,
            h: v56 + 237,
            i: v67,
            j: v72,
            k: v77,
            l: v82,
            m: v87,
            n: v92,
            o: v97,
            p: v102,
            a17: v107,
            a18: v112,
            a19: v117,
            a20: v122,
            a21: v127,
            a22: v132,
            a23: v137,
            a24: v142,
            a25: v147,
            a26: v152,
            a27: v157,
            a28: v57 + 18,
            a29: v162,
            a30: v57 + 19,
            a31: v167,
            a32: v57 + 32,
            a33: v172,
            a34: v57 + 33,
            a35: v177,
            ia: v57 + 22,
            a37: v182,
            ja: v57 + 23,
            a39: v187,
            ka: v57 + 36,
            a41: v192,
            la: v57 + 37);
          _jxr_4x4PreFilter(
            a: v56 + 234,
            b: v56 + 235,
            c: v56 + 248,
            d: v56 + 249,
            e: v56 + 238,
            f: v56 + 239,
            g: v56 + 252,
            h: v56 + 253,
            i: v68,
            j: v73,
            k: v78,
            l: v83,
            m: v88,
            n: v93,
            o: v98,
            p: v103,
            a17: v108,
            a18: v113,
            a19: v118,
            a20: v123,
            a21: v128,
            a22: v133,
            a23: v138,
            a24: v143,
            a25: v148,
            a26: v153,
            a27: v158,
            a28: v57 + 34,
            a29: v163,
            a30: v57 + 35,
            a31: v168,
            a32: v57 + 48,
            a33: v173,
            a34: v57 + 49,
            a35: v178,
            ia: v57 + 38,
            a37: v183,
            ja: v57 + 39,
            a39: v188,
            ka: v57 + 52,
            a41: v193,
            la: v57 + 53);
        }
        v59 = image->disableTileOverlapFlag;
        if ( image->tile_column_position[v10] + v39 >= (image->extended_width >> 4) - 1 )
        {
          if ( v59 != 0 )
          {
LABEL_82:
            if ( v39 != image->tile_column_width[v38] - 1
              && v197 != *(unsigned int *)((char *)image->tile_row_position + v58)
                       + *(unsigned int *)((char *)image->tile_row_height + v58)
                       - 1 )
            {
              goto LABEL_84;
            }
          }
        }
        else
        {
          if ( v59 != 0 )
            goto LABEL_82;
LABEL_84:
          v60 = 84 * (image->tile_column_position[v10] + v39);
          v61 = *(_DWORD **)(v60 + *((_DWORD *)v40 + 32) + 84);
          v62 = *(int **)(v60 + *((_DWORD *)v40 + 33) + 84);
          _jxr_4x4PreFilter(
            a: v56 + 250,
            b: v56 + 251,
            c: v62 + 200,
            d: v62 + 201,
            e: v56 + 254,
            f: v56 + 255,
            g: v62 + 204,
            h: v62 + 205,
            i: v64,
            j: v69,
            k: v74,
            l: v79,
            m: v84,
            n: v89,
            o: v94,
            p: v99,
            a17: v104,
            a18: v109,
            a19: v114,
            a20: v119,
            a21: v124,
            a22: v129,
            a23: v134,
            a24: v139,
            a25: v144,
            a26: v149,
            a27: v154,
            a28: v57 + 50,
            a29: v159,
            a30: v57 + 51,
            a31: v164,
            a32: v61,
            a33: v169,
            a34: v61 + 1,
            a35: v174,
            ia: v57 + 54,
            a37: v179,
            ja: v57 + 55,
            a39: v184,
            ka: v61 + 4,
            a41: v189,
            la: v61 + 5);
        }
        v63 = image->disableTileOverlapFlag;
        if ( image->tile_column_position[v10] + v39 == (image->extended_width >> 4) - 1 )
        {
          if ( v63 != 0 )
            goto LABEL_89;
LABEL_91:
          _jxr_4PreFilter(a: v56 + 250, b: v56 + 254, c: v57 + 50, d: v57 + 54);
          _jxr_4PreFilter(a: v56 + 251, b: v56 + 255, c: v57 + 51, d: v57 + 55);
        }
        else if ( v63 != 0 )
        {
LABEL_89:
          if ( v39 == image->tile_column_width[v38] - 1
            && v197 != *(unsigned int *)((char *)image->tile_row_position + v58)
                     + *(unsigned int *)((char *)image->tile_row_height + v58)
                     - 1 )
          {
            goto LABEL_91;
          }
        }
      }
      ++v39;
    }
    while ( v39 < image->tile_column_width[v38] );
LABEL_93:
    if ( ++v195 < image->tile_columns )
    {
      v9 = v194;
      v11 = v197;
      v10 = v195;
      v5 = ch;
      continue;
    }
    break;
  }
}


// ========================================================================
// first_prefilter422_up2
// EA  : 0x8291CE88
// RVA : 0x0091CE88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall first_prefilter422_up2(jxr_image *image, int ch, int ty)
{
  unsigned int *tile_row_height; // r9
  unsigned int v6; // r11
  unsigned int v7; // r10
  unsigned int v8; // r10
  int v9; // r25
  int v10; // r24
  unsigned int v11; // r23
  signed int v12; // r21
  int *data; // r31
  int *v14; // r31
  unsigned int v15; // r27
  char *v16; // r26
  int *v17; // r31
  unsigned int *tile_column_position; // r7
  unsigned int disableTileOverlapFlag; // r10
  int *v20; // r29
  int *v21; // r3
  int *v22; // r11
  unsigned int v23; // r27
  char *v24; // r26
  int *v25; // r31
  unsigned int *v26; // r7
  unsigned int v27; // r10
  int *v28; // r29
  int *v29; // r11
  int *v30; // r11
  int v31; // r27
  int v32; // r28
  char *v33; // r26
  int *v34; // r31
  unsigned int v35; // r10
  unsigned int v36; // r11
  int *v37; // r29
  unsigned int v38; // r7
  int *v39; // r31
  int *v40; // r29
  unsigned int v41; // r11
  unsigned int v42; // r11
  _DWORD *v43; // r5
  int *v44; // r11
  unsigned int v45; // r11
  int *v46; // [sp+8h] [-F8h]
  int *v47; // [sp+8h] [-F8h]
  int *v48; // [sp+8h] [-F8h]
  int *v49; // [sp+8h] [-F8h]
  int *v50; // [sp+8h] [-F8h]
  int *v51; // [sp+Ch] [-F4h]
  int *v52; // [sp+Ch] [-F4h]
  int *v53; // [sp+Ch] [-F4h]
  int *v54; // [sp+Ch] [-F4h]
  int *v55; // [sp+Ch] [-F4h]
  int *v56; // [sp+10h] [-F0h]
  int *v57; // [sp+10h] [-F0h]
  int *v58; // [sp+10h] [-F0h]
  int *v59; // [sp+10h] [-F0h]
  int *v60; // [sp+10h] [-F0h]
  int *v61; // [sp+14h] [-ECh]
  int *v62; // [sp+14h] [-ECh]
  int *v63; // [sp+14h] [-ECh]
  int *v64; // [sp+14h] [-ECh]
  int *v65; // [sp+14h] [-ECh]
  int *v66; // [sp+18h] [-E8h]
  int *v67; // [sp+18h] [-E8h]
  int *v68; // [sp+18h] [-E8h]
  int *v69; // [sp+18h] [-E8h]
  int *v70; // [sp+18h] [-E8h]
  int *v71; // [sp+1Ch] [-E4h]
  int *v72; // [sp+1Ch] [-E4h]
  int *v73; // [sp+1Ch] [-E4h]
  int *v74; // [sp+1Ch] [-E4h]
  int *v75; // [sp+1Ch] [-E4h]
  int *v76; // [sp+20h] [-E0h]
  int *v77; // [sp+20h] [-E0h]
  int *v78; // [sp+20h] [-E0h]
  int *v79; // [sp+20h] [-E0h]
  int *v80; // [sp+20h] [-E0h]
  int *v81; // [sp+24h] [-DCh]
  int *v82; // [sp+24h] [-DCh]
  int *v83; // [sp+24h] [-DCh]
  int *v84; // [sp+24h] [-DCh]
  int *v85; // [sp+24h] [-DCh]
  int v86; // [sp+28h] [-D8h]
  int v87; // [sp+28h] [-D8h]
  int v88; // [sp+28h] [-D8h]
  int v89; // [sp+28h] [-D8h]
  int v90; // [sp+28h] [-D8h]
  int v91; // [sp+2Ch] [-D4h]
  int v92; // [sp+2Ch] [-D4h]
  int v93; // [sp+2Ch] [-D4h]
  int v94; // [sp+2Ch] [-D4h]
  int v95; // [sp+2Ch] [-D4h]
  int v96; // [sp+30h] [-D0h]
  int v97; // [sp+30h] [-D0h]
  int v98; // [sp+30h] [-D0h]
  int v99; // [sp+30h] [-D0h]
  int v100; // [sp+30h] [-D0h]
  int v101; // [sp+34h] [-CCh]
  int v102; // [sp+34h] [-CCh]
  int v103; // [sp+34h] [-CCh]
  int v104; // [sp+34h] [-CCh]
  int v105; // [sp+34h] [-CCh]
  int v106; // [sp+38h] [-C8h]
  int v107; // [sp+38h] [-C8h]
  int v108; // [sp+38h] [-C8h]
  int v109; // [sp+38h] [-C8h]
  int v110; // [sp+38h] [-C8h]
  int v111; // [sp+3Ch] [-C4h]
  int v112; // [sp+3Ch] [-C4h]
  int v113; // [sp+3Ch] [-C4h]
  int v114; // [sp+3Ch] [-C4h]
  int v115; // [sp+3Ch] [-C4h]
  int v116; // [sp+40h] [-C0h]
  int v117; // [sp+40h] [-C0h]
  int v118; // [sp+40h] [-C0h]
  int v119; // [sp+40h] [-C0h]
  int v120; // [sp+40h] [-C0h]
  int v121; // [sp+44h] [-BCh]
  int v122; // [sp+44h] [-BCh]
  int v123; // [sp+44h] [-BCh]
  int v124; // [sp+44h] [-BCh]
  int v125; // [sp+44h] [-BCh]
  int v126; // [sp+48h] [-B8h]
  int v127; // [sp+48h] [-B8h]
  int v128; // [sp+48h] [-B8h]
  int v129; // [sp+48h] [-B8h]
  int v130; // [sp+48h] [-B8h]
  int v131; // [sp+4Ch] [-B4h]
  int v132; // [sp+4Ch] [-B4h]
  int v133; // [sp+4Ch] [-B4h]
  int v134; // [sp+4Ch] [-B4h]
  int v135; // [sp+4Ch] [-B4h]
  int v136; // [sp+50h] [-B0h]
  int v137; // [sp+50h] [-B0h]
  int v138; // [sp+50h] [-B0h]
  int v139; // [sp+50h] [-B0h]
  int v140; // [sp+50h] [-B0h]
  int v141; // [sp+58h] [-A8h]
  int v142; // [sp+58h] [-A8h]
  int v143; // [sp+58h] [-A8h]
  int v144; // [sp+58h] [-A8h]
  int v145; // [sp+58h] [-A8h]
  int v146; // [sp+60h] [-A0h]
  int v147; // [sp+60h] [-A0h]
  int v148; // [sp+60h] [-A0h]
  int v149; // [sp+60h] [-A0h]
  int v150; // [sp+60h] [-A0h]
  int v151; // [sp+68h] [-98h]
  int v152; // [sp+68h] [-98h]
  int v153; // [sp+68h] [-98h]
  int v154; // [sp+68h] [-98h]
  int v155; // [sp+68h] [-98h]
  int v156; // [sp+70h] [-90h]
  int v157; // [sp+70h] [-90h]
  int v158; // [sp+70h] [-90h]
  int v159; // [sp+70h] [-90h]
  int v160; // [sp+70h] [-90h]
  int v161; // [sp+78h] [-88h]
  int v162; // [sp+78h] [-88h]
  int v163; // [sp+78h] [-88h]
  int v164; // [sp+78h] [-88h]
  int v165; // [sp+78h] [-88h]
  int v166; // [sp+80h] [-80h]
  int v167; // [sp+80h] [-80h]
  int v168; // [sp+80h] [-80h]
  int v169; // [sp+80h] [-80h]
  int v170; // [sp+80h] [-80h]
  int v171; // [sp+88h] [-78h]
  int v172; // [sp+88h] [-78h]
  int v173; // [sp+88h] [-78h]
  int v174; // [sp+88h] [-78h]
  int v175; // [sp+88h] [-78h]

  tile_row_height = image->tile_row_height;
  v6 = image->cur_my + 2;
  v7 = tile_row_height[ty];
  if ( v6 >= v7 )
  {
    v6 -= v7;
    ++ty;
  }
  v8 = tile_row_height[ty];
  if ( v6 >= v8 )
  {
    v6 -= v8;
    ++ty;
  }
  v9 = ty;
  v10 = 0;
  v11 = image->tile_row_position[ty] + v6;
  if ( image->tile_columns != 0 )
  {
    v12 = v11 + 1;
    while ( 1 )
    {
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        data = image->strip[ch].up2[image->tile_column_position[v10]].data;
        _jxr_4PreFilter(a: data + 8, b: data + 12, c: data + 32, d: data + 36);
        _jxr_4PreFilter(a: data + 40, b: data + 44, c: data + 64, d: data + 68);
        _jxr_4PreFilter(a: data + 72, b: data + 76, c: data + 96, d: data + 100);
        _jxr_4PreFilter(a: data + 9, b: data + 13, c: data + 33, d: data + 37);
        _jxr_4PreFilter(a: data + 41, b: data + 45, c: data + 65, d: data + 69);
        _jxr_4PreFilter(a: data + 73, b: data + 77, c: data + 97, d: data + 101);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v14 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4PreFilter(a: v14 + 26, b: v14 + 30, c: v14 + 50, d: v14 + 54);
        _jxr_4PreFilter(a: v14 + 27, b: v14 + 31, c: v14 + 51, d: v14 + 55);
        _jxr_4PreFilter(a: v14 + 58, b: v14 + 62, c: v14 + 82, d: v14 + 86);
        _jxr_4PreFilter(a: v14 + 59, b: v14 + 63, c: v14 + 83, d: v14 + 87);
        _jxr_4PreFilter(a: v14 + 90, b: v14 + 94, c: v14 + 114, d: v14 + 118);
        _jxr_4PreFilter(a: v14 + 91, b: v14 + 95, c: v14 + 115, d: v14 + 119);
      }
      if ( v11 == 0 || image->disableTileOverlapFlag != 0 && v11 == image->tile_row_position[v9] )
      {
        v15 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v16 = (char *)image + 28 * ch;
          do
          {
            v17 = *(int **)(84 * (image->tile_column_position[v10] + v15) + *((_DWORD *)v16 + 33));
            _jxr_4PreFilter(a: v17 + 2, b: v17 + 3, c: v17 + 16, d: v17 + 17);
            _jxr_4PreFilter(a: v17 + 6, b: v17 + 7, c: v17 + 20, d: v17 + 21);
            tile_column_position = image->tile_column_position;
            disableTileOverlapFlag = image->disableTileOverlapFlag;
            if ( tile_column_position[v10] + v15 != 0 )
            {
              if ( disableTileOverlapFlag == 0 )
                goto LABEL_23;
            }
            else if ( disableTileOverlapFlag == 0 )
            {
              goto LABEL_24;
            }
            if ( v15 != 0 )
            {
LABEL_23:
              v20 = *(int **)(84 * (tile_column_position[v10] + v15) + *((_DWORD *)v16 + 33) - 84);
              _jxr_4PreFilter(a: v20 + 18, b: v20 + 19, c: v17, d: v17 + 1);
              _jxr_4PreFilter(a: v20 + 22, b: v20 + 23, c: v17 + 4, d: v17 + 5);
            }
LABEL_24:
            ++v15;
          }
          while ( v15 < image->tile_column_width[v10] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v21 = image->strip[ch].up2[image->tile_column_position[v10]].data;
          _jxr_4PreFilter(a: v21, b: v21 + 1, c: v21 + 4, d: v21 + 5);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v22 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4PreFilter(a: v22 + 18, b: v22 + 19, c: v22 + 22, d: v22 + 23);
        }
      }
      if ( v12 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v11 == image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
      {
        v23 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v24 = (char *)image + 28 * ch;
          do
          {
            v25 = *(int **)(84 * (image->tile_column_position[v10] + v23) + *((_DWORD *)v24 + 33));
            _jxr_4PreFilter(a: v25 + 106, b: v25 + 107, c: v25 + 120, d: v25 + 121);
            _jxr_4PreFilter(a: v25 + 110, b: v25 + 111, c: v25 + 124, d: v25 + 125);
            v26 = image->tile_column_position;
            v27 = image->disableTileOverlapFlag;
            if ( v26[v10] + v23 != 0 )
            {
              if ( v27 == 0 )
                goto LABEL_41;
            }
            else if ( v27 == 0 )
            {
              goto LABEL_42;
            }
            if ( v23 != 0 )
            {
LABEL_41:
              v28 = *(int **)(84 * (v26[v10] + v23) + *((_DWORD *)v24 + 33) - 84);
              _jxr_4PreFilter(a: v28 + 122, b: v28 + 123, c: v25 + 104, d: v25 + 105);
              _jxr_4PreFilter(a: v28 + 126, b: v28 + 127, c: v25 + 108, d: v25 + 109);
            }
LABEL_42:
            ++v23;
          }
          while ( v23 < image->tile_column_width[v10] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v29 = image->strip[ch].up2[image->tile_column_position[v10]].data;
          _jxr_4PreFilter(a: v29 + 104, b: v29 + 105, c: v29 + 108, d: v29 + 109);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v30 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4PreFilter(a: v30 + 122, b: v30 + 123, c: v30 + 126, d: v30 + 127);
        }
      }
      v31 = v10;
      v32 = 0;
      if ( image->tile_column_width[v10] != 0 )
        break;
LABEL_84:
      if ( ++v10 >= image->tile_columns )
        return;
    }
    v33 = (char *)image + 28 * ch;
    while ( 1 )
    {
      v34 = *(int **)(84 * (image->tile_column_position[v10] + v32) + *((_DWORD *)v33 + 33));
      _jxr_4x4PreFilter(
        a: v34 + 10,
        b: v34 + 11,
        c: v34 + 24,
        d: v34 + 25,
        e: v34 + 14,
        f: v34 + 15,
        g: v34 + 28,
        h: v34 + 29,
        i: v46,
        j: v51,
        k: v56,
        l: v61,
        m: v66,
        n: v71,
        o: v76,
        p: v81,
        a17: v86,
        a18: v91,
        a19: v96,
        a20: v101,
        a21: v106,
        a22: v111,
        a23: v116,
        a24: v121,
        a25: v126,
        a26: v131,
        a27: v136,
        a28: v34 + 34,
        a29: v141,
        a30: v34 + 35,
        a31: v146,
        a32: v34 + 48,
        a33: v151,
        a34: v34 + 49,
        a35: v156,
        ia: v34 + 38,
        a37: v161,
        ja: v34 + 39,
        a39: v166,
        ka: v34 + 52,
        a41: v171,
        la: v34 + 53);
      _jxr_4x4PreFilter(
        a: v34 + 42,
        b: v34 + 43,
        c: v34 + 56,
        d: v34 + 57,
        e: v34 + 46,
        f: v34 + 47,
        g: v34 + 60,
        h: v34 + 61,
        i: v47,
        j: v52,
        k: v57,
        l: v62,
        m: v67,
        n: v72,
        o: v77,
        p: v82,
        a17: v87,
        a18: v92,
        a19: v97,
        a20: v102,
        a21: v107,
        a22: v112,
        a23: v117,
        a24: v122,
        a25: v127,
        a26: v132,
        a27: v137,
        a28: v34 + 66,
        a29: v142,
        a30: v34 + 67,
        a31: v147,
        a32: v34 + 80,
        a33: v152,
        a34: v34 + 81,
        a35: v157,
        ia: v34 + 70,
        a37: v162,
        ja: v34 + 71,
        a39: v167,
        ka: v34 + 84,
        a41: v172,
        la: v34 + 85);
      _jxr_4x4PreFilter(
        a: v34 + 74,
        b: v34 + 75,
        c: v34 + 88,
        d: v34 + 89,
        e: v34 + 78,
        f: v34 + 79,
        g: v34 + 92,
        h: v34 + 93,
        i: v48,
        j: v53,
        k: v58,
        l: v63,
        m: v68,
        n: v73,
        o: v78,
        p: v83,
        a17: v88,
        a18: v93,
        a19: v98,
        a20: v103,
        a21: v108,
        a22: v113,
        a23: v118,
        a24: v123,
        a25: v128,
        a26: v133,
        a27: v138,
        a28: v34 + 98,
        a29: v143,
        a30: v34 + 99,
        a31: v148,
        a32: v34 + 112,
        a33: v153,
        a34: v34 + 113,
        a35: v158,
        ia: v34 + 102,
        a37: v163,
        ja: v34 + 103,
        a39: v168,
        ka: v34 + 116,
        a41: v173,
        la: v34 + 117);
      v35 = image->disableTileOverlapFlag;
      v36 = image->tile_column_position[v10] + v32;
      if ( v36 >= (image->extended_width >> 4) - 1 )
        break;
      if ( v35 != 0 )
        goto LABEL_55;
LABEL_56:
      v37 = *(int **)(84 * (v36 + 1) + *((_DWORD *)v33 + 33));
      _jxr_4x4PreFilter(
        a: v34 + 26,
        b: v34 + 27,
        c: v37 + 8,
        d: v37 + 9,
        e: v34 + 30,
        f: v34 + 31,
        g: v37 + 12,
        h: v37 + 13,
        i: v46,
        j: v51,
        k: v56,
        l: v61,
        m: v66,
        n: v71,
        o: v76,
        p: v81,
        a17: v86,
        a18: v91,
        a19: v96,
        a20: v101,
        a21: v106,
        a22: v111,
        a23: v116,
        a24: v121,
        a25: v126,
        a26: v131,
        a27: v136,
        a28: v34 + 50,
        a29: v141,
        a30: v34 + 51,
        a31: v146,
        a32: v37 + 32,
        a33: v151,
        a34: v37 + 33,
        a35: v156,
        ia: v34 + 54,
        a37: v161,
        ja: v34 + 55,
        a39: v166,
        ka: v37 + 36,
        a41: v171,
        la: v37 + 37);
      _jxr_4x4PreFilter(
        a: v34 + 58,
        b: v34 + 59,
        c: v37 + 40,
        d: v37 + 41,
        e: v34 + 62,
        f: v34 + 63,
        g: v37 + 44,
        h: v37 + 45,
        i: v49,
        j: v54,
        k: v59,
        l: v64,
        m: v69,
        n: v74,
        o: v79,
        p: v84,
        a17: v89,
        a18: v94,
        a19: v99,
        a20: v104,
        a21: v109,
        a22: v114,
        a23: v119,
        a24: v124,
        a25: v129,
        a26: v134,
        a27: v139,
        a28: v34 + 82,
        a29: v144,
        a30: v34 + 83,
        a31: v149,
        a32: v37 + 64,
        a33: v154,
        a34: v37 + 65,
        a35: v159,
        ia: v34 + 86,
        a37: v164,
        ja: v34 + 87,
        a39: v169,
        ka: v37 + 68,
        a41: v174,
        la: v37 + 69);
      _jxr_4x4PreFilter(
        a: v34 + 90,
        b: v34 + 91,
        c: v37 + 72,
        d: v37 + 73,
        e: v34 + 94,
        f: v34 + 95,
        g: v37 + 76,
        h: v37 + 77,
        i: v50,
        j: v55,
        k: v60,
        l: v65,
        m: v70,
        n: v75,
        o: v80,
        p: v85,
        a17: v90,
        a18: v95,
        a19: v100,
        a20: v105,
        a21: v110,
        a22: v115,
        a23: v120,
        a24: v125,
        a25: v130,
        a26: v135,
        a27: v140,
        a28: v34 + 114,
        a29: v145,
        a30: v34 + 115,
        a31: v150,
        a32: v37 + 96,
        a33: v155,
        a34: v37 + 97,
        a35: v160,
        ia: v34 + 118,
        a37: v165,
        ja: v34 + 119,
        a39: v170,
        ka: v37 + 100,
        a41: v175,
        la: v37 + 101);
LABEL_57:
      if ( v12 >= (signed int)(image->extended_height >> 4) )
        goto LABEL_83;
      v38 = 84 * (image->tile_column_position[v10] + v32);
      v39 = *(int **)(v38 + *((_DWORD *)v33 + 33));
      v40 = *(int **)(v38 + *((_DWORD *)v33 + 32));
      if ( v10 != 0 || v32 != 0 )
      {
        if ( image->disableTileOverlapFlag == 0 )
          goto LABEL_68;
        if ( v32 != 0 )
          goto LABEL_66;
      }
      else if ( image->disableTileOverlapFlag == 0 )
      {
        goto LABEL_65;
      }
      if ( v11 != image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
      {
LABEL_65:
        _jxr_4PreFilter(a: v39 + 104, b: v39 + 108, c: v40, d: v40 + 4);
        _jxr_4PreFilter(a: v39 + 105, b: v39 + 109, c: v40 + 1, d: v40 + 5);
      }
LABEL_66:
      if ( image->disableTileOverlapFlag == 0 || v11 != image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
LABEL_68:
        _jxr_4x4PreFilter(
          a: v39 + 106,
          b: v39 + 107,
          c: v39 + 120,
          d: v39 + 121,
          e: v39 + 110,
          f: v39 + 111,
          g: v39 + 124,
          h: v39 + 125,
          i: v46,
          j: v51,
          k: v56,
          l: v61,
          m: v66,
          n: v71,
          o: v76,
          p: v81,
          a17: v86,
          a18: v91,
          a19: v96,
          a20: v101,
          a21: v106,
          a22: v111,
          a23: v116,
          a24: v121,
          a25: v126,
          a26: v131,
          a27: v136,
          a28: v40 + 2,
          a29: v141,
          a30: v40 + 3,
          a31: v146,
          a32: v40 + 16,
          a33: v151,
          a34: v40 + 17,
          a35: v156,
          ia: v40 + 6,
          a37: v161,
          ja: v40 + 7,
          a39: v166,
          ka: v40 + 20,
          a41: v171,
          la: v40 + 21);
      v41 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v10] + v32 < (image->extended_width >> 4) - 1 )
      {
        if ( v41 != 0 )
        {
LABEL_73:
          if ( v32 == image->tile_column_width[v31] - 1
            || v11 == image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
          {
            goto LABEL_76;
          }
        }
        v42 = 84 * (image->tile_column_position[v10] + v32);
        v43 = *(_DWORD **)(v42 + *((_DWORD *)v33 + 32) + 84);
        v44 = *(int **)(v42 + *((_DWORD *)v33 + 33) + 84);
        _jxr_4x4PreFilter(
          a: v39 + 122,
          b: v39 + 123,
          c: v44 + 104,
          d: v44 + 105,
          e: v39 + 126,
          f: v39 + 127,
          g: v44 + 108,
          h: v44 + 109,
          i: v46,
          j: v51,
          k: v56,
          l: v61,
          m: v66,
          n: v71,
          o: v76,
          p: v81,
          a17: v86,
          a18: v91,
          a19: v96,
          a20: v101,
          a21: v106,
          a22: v111,
          a23: v116,
          a24: v121,
          a25: v126,
          a26: v131,
          a27: v136,
          a28: v40 + 18,
          a29: v141,
          a30: v40 + 19,
          a31: v146,
          a32: v43,
          a33: v151,
          a34: v43 + 1,
          a35: v156,
          ia: v40 + 22,
          a37: v161,
          ja: v40 + 23,
          a39: v166,
          ka: v43 + 4,
          a41: v171,
          la: v43 + 5);
        goto LABEL_76;
      }
      if ( v41 != 0 )
        goto LABEL_73;
LABEL_76:
      v45 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v10] + v32 == (image->extended_width >> 4) - 1 )
      {
        if ( v45 != 0 )
        {
LABEL_80:
          if ( v32 != image->tile_column_width[v31] - 1
            || v11 == image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
          {
            goto LABEL_83;
          }
        }
        _jxr_4PreFilter(a: v39 + 122, b: v39 + 126, c: v40 + 18, d: v40 + 22);
        _jxr_4PreFilter(a: v39 + 123, b: v39 + 127, c: v40 + 19, d: v40 + 23);
        goto LABEL_83;
      }
      if ( v45 != 0 )
        goto LABEL_80;
LABEL_83:
      if ( ++v32 >= image->tile_column_width[v31] )
        goto LABEL_84;
    }
    if ( v35 == 0 )
      goto LABEL_57;
LABEL_55:
    if ( v32 == image->tile_column_width[v31] - 1 )
      goto LABEL_57;
    goto LABEL_56;
  }
}


// ========================================================================
// first_prefilter420_up2
// EA  : 0x8291D998
// RVA : 0x0091D998
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall first_prefilter420_up2(jxr_image *image, int ch, int ty)
{
  unsigned int *tile_row_height; // r9
  unsigned int v6; // r11
  unsigned int v7; // r10
  unsigned int v8; // r10
  int v9; // r25
  int v10; // r24
  unsigned int v11; // r23
  signed int v12; // r21
  int *data; // r30
  int *v14; // r30
  unsigned int v15; // r27
  char *v16; // r26
  int *v17; // r30
  unsigned int *tile_column_position; // r7
  unsigned int disableTileOverlapFlag; // r10
  int *v20; // r29
  int *v21; // r3
  int *v22; // r11
  unsigned int v23; // r27
  char *v24; // r26
  int *v25; // r30
  unsigned int *v26; // r7
  unsigned int v27; // r10
  int *v28; // r29
  int *v29; // r11
  int *v30; // r11
  int v31; // r27
  int v32; // r28
  char *v33; // r26
  int *v34; // r30
  unsigned int v35; // r10
  unsigned int v36; // r11
  int *v37; // r11
  unsigned int v38; // r7
  int *v39; // r30
  int *v40; // r29
  unsigned int v41; // r11
  unsigned int v42; // r11
  _DWORD *v43; // r5
  int *v44; // r11
  unsigned int v45; // r11
  int *v46; // [sp+8h] [-F8h]
  int *v47; // [sp+Ch] [-F4h]
  int *v48; // [sp+10h] [-F0h]
  int *v49; // [sp+14h] [-ECh]
  int *v50; // [sp+18h] [-E8h]
  int *v51; // [sp+1Ch] [-E4h]
  int *v52; // [sp+20h] [-E0h]
  int *v53; // [sp+24h] [-DCh]
  int v54; // [sp+28h] [-D8h]
  int v55; // [sp+2Ch] [-D4h]
  int v56; // [sp+30h] [-D0h]
  int v57; // [sp+34h] [-CCh]
  int v58; // [sp+38h] [-C8h]
  int v59; // [sp+3Ch] [-C4h]
  int v60; // [sp+40h] [-C0h]
  int v61; // [sp+44h] [-BCh]
  int v62; // [sp+48h] [-B8h]
  int v63; // [sp+4Ch] [-B4h]
  int v64; // [sp+50h] [-B0h]
  int v65; // [sp+58h] [-A8h]
  int v66; // [sp+60h] [-A0h]
  int v67; // [sp+68h] [-98h]
  int v68; // [sp+70h] [-90h]
  int v69; // [sp+78h] [-88h]
  int v70; // [sp+80h] [-80h]
  int v71; // [sp+88h] [-78h]

  tile_row_height = image->tile_row_height;
  v6 = image->cur_my + 2;
  v7 = tile_row_height[ty];
  if ( v6 >= v7 )
  {
    v6 -= v7;
    ++ty;
  }
  v8 = tile_row_height[ty];
  if ( v6 >= v8 )
  {
    v6 -= v8;
    ++ty;
  }
  v9 = ty;
  v10 = 0;
  v11 = image->tile_row_position[ty] + v6;
  if ( image->tile_columns != 0 )
  {
    v12 = v11 + 1;
    while ( 1 )
    {
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        data = image->strip[ch].up2[image->tile_column_position[v10]].data;
        _jxr_4PreFilter(a: data + 8, b: data + 12, c: data + 32, d: data + 36);
        _jxr_4PreFilter(a: data + 9, b: data + 13, c: data + 33, d: data + 37);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v14 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4PreFilter(a: v14 + 26, b: v14 + 30, c: v14 + 50, d: v14 + 54);
        _jxr_4PreFilter(a: v14 + 27, b: v14 + 31, c: v14 + 51, d: v14 + 55);
      }
      if ( v11 == 0 || image->disableTileOverlapFlag != 0 && v11 == image->tile_row_position[v9] )
      {
        v15 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v16 = (char *)image + 28 * ch;
          do
          {
            v17 = *(int **)(84 * (image->tile_column_position[v10] + v15) + *((_DWORD *)v16 + 33));
            _jxr_4PreFilter(a: v17 + 2, b: v17 + 3, c: v17 + 16, d: v17 + 17);
            _jxr_4PreFilter(a: v17 + 6, b: v17 + 7, c: v17 + 20, d: v17 + 21);
            tile_column_position = image->tile_column_position;
            disableTileOverlapFlag = image->disableTileOverlapFlag;
            if ( tile_column_position[v10] + v15 != 0 )
            {
              if ( disableTileOverlapFlag == 0 )
                goto LABEL_23;
            }
            else if ( disableTileOverlapFlag == 0 )
            {
              goto LABEL_24;
            }
            if ( v15 != 0 )
            {
LABEL_23:
              v20 = *(int **)(84 * (tile_column_position[v10] + v15) + *((_DWORD *)v16 + 33) - 84);
              _jxr_4PreFilter(a: v20 + 18, b: v20 + 19, c: v17, d: v17 + 1);
              _jxr_4PreFilter(a: v20 + 22, b: v20 + 23, c: v17 + 4, d: v17 + 5);
            }
LABEL_24:
            ++v15;
          }
          while ( v15 < image->tile_column_width[v10] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v21 = image->strip[ch].up2[image->tile_column_position[v10]].data;
          _jxr_4PreFilter(a: v21, b: v21 + 1, c: v21 + 4, d: v21 + 5);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v22 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4PreFilter(a: v22 + 18, b: v22 + 19, c: v22 + 22, d: v22 + 23);
        }
      }
      if ( v12 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v11 == image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
      {
        v23 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v24 = (char *)image + 28 * ch;
          do
          {
            v25 = *(int **)(84 * (image->tile_column_position[v10] + v23) + *((_DWORD *)v24 + 33));
            _jxr_4PreFilter(a: v25 + 42, b: v25 + 43, c: v25 + 56, d: v25 + 57);
            _jxr_4PreFilter(a: v25 + 46, b: v25 + 47, c: v25 + 60, d: v25 + 61);
            v26 = image->tile_column_position;
            v27 = image->disableTileOverlapFlag;
            if ( v26[v10] + v23 != 0 )
            {
              if ( v27 == 0 )
                goto LABEL_41;
            }
            else if ( v27 == 0 )
            {
              goto LABEL_42;
            }
            if ( v23 != 0 )
            {
LABEL_41:
              v28 = *(int **)(84 * (v26[v10] + v23) + *((_DWORD *)v24 + 33) - 84);
              _jxr_4PreFilter(a: v28 + 58, b: v28 + 59, c: v25 + 40, d: v25 + 41);
              _jxr_4PreFilter(a: v28 + 62, b: v28 + 63, c: v25 + 44, d: v25 + 45);
            }
LABEL_42:
            ++v23;
          }
          while ( v23 < image->tile_column_width[v10] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v29 = image->strip[ch].up2[image->tile_column_position[v10]].data;
          _jxr_4PreFilter(a: v29 + 40, b: v29 + 41, c: v29 + 44, d: v29 + 45);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v30 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4PreFilter(a: v30 + 58, b: v30 + 59, c: v30 + 62, d: v30 + 63);
        }
      }
      v31 = v10;
      v32 = 0;
      if ( image->tile_column_width[v10] != 0 )
        break;
LABEL_84:
      if ( ++v10 >= image->tile_columns )
        return;
    }
    v33 = (char *)image + 28 * ch;
    while ( 1 )
    {
      v34 = *(int **)(84 * (image->tile_column_position[v10] + v32) + *((_DWORD *)v33 + 33));
      _jxr_4x4PreFilter(
        a: v34 + 10,
        b: v34 + 11,
        c: v34 + 24,
        d: v34 + 25,
        e: v34 + 14,
        f: v34 + 15,
        g: v34 + 28,
        h: v34 + 29,
        i: v46,
        j: v47,
        k: v48,
        l: v49,
        m: v50,
        n: v51,
        o: v52,
        p: v53,
        a17: v54,
        a18: v55,
        a19: v56,
        a20: v57,
        a21: v58,
        a22: v59,
        a23: v60,
        a24: v61,
        a25: v62,
        a26: v63,
        a27: v64,
        a28: v34 + 34,
        a29: v65,
        a30: v34 + 35,
        a31: v66,
        a32: v34 + 48,
        a33: v67,
        a34: v34 + 49,
        a35: v68,
        ia: v34 + 38,
        a37: v69,
        ja: v34 + 39,
        a39: v70,
        ka: v34 + 52,
        a41: v71,
        la: v34 + 53);
      v35 = image->disableTileOverlapFlag;
      v36 = image->tile_column_position[v10] + v32;
      if ( v36 >= (image->extended_width >> 4) - 1 )
        break;
      if ( v35 != 0 )
        goto LABEL_55;
LABEL_56:
      v37 = *(int **)(84 * (v36 + 1) + *((_DWORD *)v33 + 33));
      _jxr_4x4PreFilter(
        a: v34 + 26,
        b: v34 + 27,
        c: v37 + 8,
        d: v37 + 9,
        e: v34 + 30,
        f: v34 + 31,
        g: v37 + 12,
        h: v37 + 13,
        i: v46,
        j: v47,
        k: v48,
        l: v49,
        m: v50,
        n: v51,
        o: v52,
        p: v53,
        a17: v54,
        a18: v55,
        a19: v56,
        a20: v57,
        a21: v58,
        a22: v59,
        a23: v60,
        a24: v61,
        a25: v62,
        a26: v63,
        a27: v64,
        a28: v34 + 50,
        a29: v65,
        a30: v34 + 51,
        a31: v66,
        a32: v37 + 32,
        a33: v67,
        a34: v37 + 33,
        a35: v68,
        ia: v34 + 54,
        a37: v69,
        ja: v34 + 55,
        a39: v70,
        ka: v37 + 36,
        a41: v71,
        la: v37 + 37);
LABEL_57:
      if ( v12 >= (signed int)(image->extended_height >> 4) )
        goto LABEL_83;
      v38 = 84 * (image->tile_column_position[v10] + v32);
      v39 = *(int **)(v38 + *((_DWORD *)v33 + 33));
      v40 = *(int **)(v38 + *((_DWORD *)v33 + 32));
      if ( v10 != 0 || v32 != 0 )
      {
        if ( image->disableTileOverlapFlag == 0 )
          goto LABEL_68;
        if ( v32 != 0 )
          goto LABEL_66;
      }
      else if ( image->disableTileOverlapFlag == 0 )
      {
        goto LABEL_65;
      }
      if ( v11 != image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
      {
LABEL_65:
        _jxr_4PreFilter(a: v39 + 40, b: v39 + 44, c: v40, d: v40 + 4);
        _jxr_4PreFilter(a: v39 + 41, b: v39 + 45, c: v40 + 1, d: v40 + 5);
      }
LABEL_66:
      if ( image->disableTileOverlapFlag == 0 || v11 != image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
LABEL_68:
        _jxr_4x4PreFilter(
          a: v39 + 42,
          b: v39 + 43,
          c: v39 + 56,
          d: v39 + 57,
          e: v39 + 46,
          f: v39 + 47,
          g: v39 + 60,
          h: v39 + 61,
          i: v46,
          j: v47,
          k: v48,
          l: v49,
          m: v50,
          n: v51,
          o: v52,
          p: v53,
          a17: v54,
          a18: v55,
          a19: v56,
          a20: v57,
          a21: v58,
          a22: v59,
          a23: v60,
          a24: v61,
          a25: v62,
          a26: v63,
          a27: v64,
          a28: v40 + 2,
          a29: v65,
          a30: v40 + 3,
          a31: v66,
          a32: v40 + 16,
          a33: v67,
          a34: v40 + 17,
          a35: v68,
          ia: v40 + 6,
          a37: v69,
          ja: v40 + 7,
          a39: v70,
          ka: v40 + 20,
          a41: v71,
          la: v40 + 21);
      v41 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v10] + v32 < (image->extended_width >> 4) - 1 )
      {
        if ( v41 != 0 )
        {
LABEL_73:
          if ( v32 == image->tile_column_width[v31] - 1
            || v11 == image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
          {
            goto LABEL_76;
          }
        }
        v42 = 84 * (image->tile_column_position[v10] + v32);
        v43 = *(_DWORD **)(v42 + *((_DWORD *)v33 + 32) + 84);
        v44 = *(int **)(v42 + *((_DWORD *)v33 + 33) + 84);
        _jxr_4x4PreFilter(
          a: v39 + 58,
          b: v39 + 59,
          c: v44 + 40,
          d: v44 + 41,
          e: v39 + 62,
          f: v39 + 63,
          g: v44 + 44,
          h: v44 + 45,
          i: v46,
          j: v47,
          k: v48,
          l: v49,
          m: v50,
          n: v51,
          o: v52,
          p: v53,
          a17: v54,
          a18: v55,
          a19: v56,
          a20: v57,
          a21: v58,
          a22: v59,
          a23: v60,
          a24: v61,
          a25: v62,
          a26: v63,
          a27: v64,
          a28: v40 + 18,
          a29: v65,
          a30: v40 + 19,
          a31: v66,
          a32: v43,
          a33: v67,
          a34: v43 + 1,
          a35: v68,
          ia: v40 + 22,
          a37: v69,
          ja: v40 + 23,
          a39: v70,
          ka: v43 + 4,
          a41: v71,
          la: v43 + 5);
        goto LABEL_76;
      }
      if ( v41 != 0 )
        goto LABEL_73;
LABEL_76:
      v45 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v10] + v32 == (image->extended_width >> 4) - 1 )
      {
        if ( v45 != 0 )
        {
LABEL_80:
          if ( v32 != image->tile_column_width[v31] - 1
            || v11 == image->tile_row_position[v9] + image->tile_row_height[v9] - 1 )
          {
            goto LABEL_83;
          }
        }
        _jxr_4PreFilter(a: v39 + 58, b: v39 + 62, c: v40 + 18, d: v40 + 22);
        _jxr_4PreFilter(a: v39 + 59, b: v39 + 63, c: v40 + 19, d: v40 + 23);
        goto LABEL_83;
      }
      if ( v45 != 0 )
        goto LABEL_80;
LABEL_83:
      if ( ++v32 >= image->tile_column_width[v31] )
        goto LABEL_84;
    }
    if ( v35 == 0 )
      goto LABEL_57;
LABEL_55:
    if ( v32 == image->tile_column_width[v31] - 1 )
      goto LABEL_57;
    goto LABEL_56;
  }
}


// ========================================================================
// PCT_stage2_up1
// EA  : 0x8291E278
// RVA : 0x0091E278
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall PCT_stage2_up1(jxr_image *image, int ch, int ty)
{
  int v5; // r25
  int v6; // r26
  signed int v7; // r28
  char *v8; // r30
  int v9; // r31
  int use_clr_fmt; // r11

  v5 = image->cur_my + 1;
  v6 = ty;
  if ( v5 == image->tile_row_height[ty] )
  {
    v6 = ty + 1;
    v5 = 0;
  }
  v7 = 0;
  if ( image->extended_width >> 4 != 0 )
  {
    v8 = (char *)image + 28 * ch;
    v9 = 0;
    while ( ch > 0 )
    {
      use_clr_fmt = image->use_clr_fmt;
      if ( use_clr_fmt == 1 )
      {
        _jxr_InvPermute2pt(
          a: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 4),
          b: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 8));
        _jxr_2x2IPCT(coeff: *(int **)(*((_DWORD *)v8 + 34) + v9));
      }
      else
      {
        if ( use_clr_fmt != 2 )
          break;
        _jxr_InvPermute2pt(
          a: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 4),
          b: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 8));
        _jxr_InvPermute2pt(
          a: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 20),
          b: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 24));
        _jxr_2x2IPCT(coeff: *(int **)(*((_DWORD *)v8 + 34) + v9));
        _jxr_2x2IPCT(coeff: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 16));
        _jxr_2ptFwdT(a: *(int **)(*((_DWORD *)v8 + 34) + v9), b: (int *)(*(_DWORD *)(*((_DWORD *)v8 + 34) + v9) + 16));
      }
LABEL_11:
      ++v7;
      v9 += 84;
      if ( v7 >= (signed int)(image->extended_width >> 4) )
        goto LABEL_12;
    }
    _jxr_4x4PCT(coeff: *(int **)(*((_DWORD *)v8 + 34) + v9));
    goto LABEL_11;
  }
LABEL_12:
  quantize_up_dclp(image, use_my: v5, ch, tx: 0, ty: v6);
}


// ========================================================================
// second_prefilter444_up1
// EA  : 0x8291E3B0
// RVA : 0x0091E3B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall second_prefilter444_up1(jxr_image *image, int ch, int ty)
{
  unsigned int v5; // r11
  unsigned int v6; // r10
  int v7; // r25
  unsigned int v8; // r23
  unsigned int v9; // r24
  signed int v10; // r22
  unsigned int v11; // r28
  unsigned int i; // r27
  unsigned int disableTileOverlapFlag; // r11
  macroblock_s *v14; // r11
  int *data; // r30
  int *v16; // r29
  int *v17; // r3
  int *v18; // r11
  unsigned int v19; // r28
  unsigned int j; // r27
  unsigned int v21; // r11
  macroblock_s *v22; // r11
  int *v23; // r29
  int *v24; // r30
  int *v25; // r11
  int *v26; // r11
  unsigned int v27; // r28
  unsigned int k; // r27
  unsigned int v29; // r9
  char *v30; // r11
  int *v31; // r30
  int *v32; // r29
  char *v33; // r11
  unsigned int v34; // r10
  int v35; // r9
  _DWORD **v36; // r11
  _DWORD *v37; // r8
  char *v38; // r11
  unsigned int v39; // r8
  int *v40; // r30
  int *v41; // r29
  int *v42; // [sp+8h] [-E8h]
  int *v43; // [sp+Ch] [-E4h]
  int *v44; // [sp+10h] [-E0h]
  int *v45; // [sp+14h] [-DCh]
  int *v46; // [sp+18h] [-D8h]
  int *v47; // [sp+1Ch] [-D4h]
  int *v48; // [sp+20h] [-D0h]
  int *v49; // [sp+24h] [-CCh]
  int v50; // [sp+28h] [-C8h]
  int v51; // [sp+2Ch] [-C4h]
  int v52; // [sp+30h] [-C0h]
  int v53; // [sp+34h] [-BCh]
  int v54; // [sp+38h] [-B8h]
  int v55; // [sp+3Ch] [-B4h]
  int v56; // [sp+40h] [-B0h]
  int v57; // [sp+44h] [-ACh]
  int v58; // [sp+48h] [-A8h]
  int v59; // [sp+4Ch] [-A4h]
  int v60; // [sp+50h] [-A0h]
  int v61; // [sp+58h] [-98h]
  int v62; // [sp+60h] [-90h]
  int v63; // [sp+68h] [-88h]
  int v64; // [sp+70h] [-80h]
  int v65; // [sp+78h] [-78h]
  int v66; // [sp+80h] [-70h]
  int v67; // [sp+88h] [-68h]

  v5 = image->cur_my + 1;
  v6 = image->tile_row_height[ty];
  if ( v5 >= v6 )
  {
    v5 -= v6;
    ++ty;
  }
  v7 = ty;
  v8 = 0;
  v9 = image->tile_row_position[ty] + v5;
  if ( image->tile_columns != 0 )
  {
    v10 = v9 + 1;
    do
    {
      if ( v9 == 0 || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] )
      {
        v11 = v8;
        for ( i = 0; i < image->tile_column_width[v11]; ++i )
        {
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v11] + i != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_14;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            continue;
          }
          if ( i != 0 )
          {
LABEL_14:
            v14 = &image->strip[ch].up1[image->tile_column_position[v11] + i];
            data = v14->data;
            v16 = v14[-1].data;
            _jxr_4PreFilter(a: v16 + 2, b: v16 + 3, c: v14->data, d: v14->data + 1);
            _jxr_4PreFilter(a: v16 + 6, b: v16 + 7, c: data + 4, d: data + 5);
          }
        }
        if ( v8 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v17 = image->strip[ch].up1[image->tile_column_position[v8]].data;
          _jxr_4PreFilter(a: v17, b: v17 + 1, c: v17 + 4, d: v17 + 5);
        }
        if ( v8 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v18 = image->strip[ch].up1[image->tile_column_position[v8] - 1 + image->tile_column_width[v8]].data;
          _jxr_4PreFilter(a: v18 + 2, b: v18 + 3, c: v18 + 6, d: v18 + 7);
        }
      }
      if ( v10 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
      {
        v19 = v8;
        for ( j = 0; j < image->tile_column_width[v19]; ++j )
        {
          v21 = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v19] + j != 0 )
          {
            if ( v21 == 0 )
              goto LABEL_31;
          }
          else if ( v21 == 0 )
          {
            continue;
          }
          if ( j != 0 )
          {
LABEL_31:
            v22 = &image->strip[ch].up1[image->tile_column_position[v19] + j];
            v23 = v22->data;
            v24 = v22[-1].data;
            _jxr_4PreFilter(a: v24 + 10, b: v24 + 11, c: v22->data + 8, d: v22->data + 9);
            _jxr_4PreFilter(a: v24 + 14, b: v24 + 15, c: v23 + 12, d: v23 + 13);
          }
        }
        if ( v8 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v25 = image->strip[ch].up1[image->tile_column_position[v8]].data;
          _jxr_4PreFilter(a: v25 + 8, b: v25 + 9, c: v25 + 12, d: v25 + 13);
        }
        if ( v8 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v26 = image->strip[ch].up1[image->tile_column_position[v8] - 1 + image->tile_column_width[v8]].data;
          _jxr_4PreFilter(a: v26 + 10, b: v26 + 11, c: v26 + 14, d: v26 + 15);
        }
      }
      v27 = v8;
      for ( k = 0; k < image->tile_column_width[v27]; ++k )
      {
        if ( v10 < (signed int)(image->extended_height >> 4) )
        {
          if ( v8 == 0 && k == 0 && image->disableTileOverlapFlag == 0
            || image->disableTileOverlapFlag != 0
            && k == 0
            && v9 != image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
          {
            v29 = image->tile_column_position[v8];
            v30 = (char *)image + 28 * ch;
            v31 = *(int **)(*((_DWORD *)v30 + 34) + 84 * v29);
            v32 = *(int **)(*((_DWORD *)v30 + 33) + 84 * v29);
            _jxr_4PreFilter(a: v31 + 8, b: v31 + 12, c: v32, d: v32 + 4);
            _jxr_4PreFilter(a: v31 + 9, b: v31 + 13, c: v32 + 1, d: v32 + 5);
          }
          if ( image->tile_column_position[v27] + k < (image->extended_width >> 4) - 1
            && image->disableTileOverlapFlag == 0
            || image->disableTileOverlapFlag != 0
            && k != image->tile_column_width[v27] - 1
            && v9 != image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
          {
            v33 = (char *)image + 28 * ch;
            v34 = 84 * (image->tile_column_position[v27] + k);
            v35 = *((_DWORD *)v33 + 34);
            v36 = (_DWORD **)(*((_DWORD *)v33 + 33) + v34);
            v37 = (_DWORD *)(v35 + v34);
            _jxr_4x4PreFilter(
              a: (int *)(*v37 + 40),
              b: (int *)(*v37 + 44),
              c: (int *)(v37[21] + 32),
              d: (int *)(v37[21] + 36),
              e: (int *)(*v37 + 56),
              f: (int *)(*v37 + 60),
              g: (int *)(v37[21] + 48),
              h: (int *)(v37[21] + 52),
              i: v42,
              j: v43,
              k: v44,
              l: v45,
              m: v46,
              n: v47,
              o: v48,
              p: v49,
              a17: v50,
              a18: v51,
              a19: v52,
              a20: v53,
              a21: v54,
              a22: v55,
              a23: v56,
              a24: v57,
              a25: v58,
              a26: v59,
              a27: v60,
              a28: *v36 + 2,
              a29: v61,
              a30: *v36 + 3,
              a31: v62,
              a32: v36[21],
              a33: v63,
              a34: v36[21] + 1,
              a35: v64,
              ia: *v36 + 6,
              a37: v65,
              ja: *v36 + 7,
              a39: v66,
              ka: v36[21] + 4,
              a41: v67,
              la: v36[21] + 5);
          }
          if ( image->tile_column_position[v27] + k == (image->extended_width >> 4) - 1
            && image->disableTileOverlapFlag == 0
            || image->disableTileOverlapFlag != 0
            && k == image->tile_column_width[v27] - 1
            && v9 != image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
          {
            v38 = (char *)image + 28 * ch;
            v39 = image->tile_column_position[v27] + image->tile_column_width[v27];
            v40 = *(int **)(*((_DWORD *)v38 + 33) + 84 * v39 - 84);
            v41 = *(int **)(*((_DWORD *)v38 + 34) + 84 * v39 - 84);
            _jxr_4PreFilter(a: v41 + 10, b: v41 + 14, c: v40 + 2, d: v40 + 6);
            _jxr_4PreFilter(a: v41 + 11, b: v41 + 15, c: v40 + 3, d: v40 + 7);
          }
        }
      }
      ++v8;
    }
    while ( v8 < image->tile_columns );
  }
}


// ========================================================================
// second_prefilter422_up1
// EA  : 0x8291E9B8
// RVA : 0x0091E9B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall second_prefilter422_up1(jxr_image *image, int ch, int ty)
{
  unsigned int v5; // r11
  unsigned int v6; // r10
  int v7; // r26
  unsigned int v8; // r10
  unsigned int v9; // r25
  unsigned int v10; // r7
  int v11; // r11
  int *data; // r3
  macroblock_s *v13; // r3
  unsigned int v14; // r24
  unsigned int v15; // r7
  int v16; // r11
  int *v17; // r3
  macroblock_s *v18; // r3
  unsigned int tile_columns; // r10
  int v20; // r27
  int *v21; // r11
  int *v22; // r11
  int v23; // r29
  unsigned int i; // r30
  unsigned int disableTileOverlapFlag; // r11
  macroblock_s *v26; // r11
  int v27; // r29
  unsigned int j; // r30
  unsigned int v29; // r11
  macroblock_s *v30; // r11
  int v31; // r30
  int v32; // r29
  unsigned int v33; // r11
  unsigned int v34; // r8
  unsigned int v35; // r11
  int v36; // r10
  unsigned int v37; // r11
  macroblock_s *v38; // r11
  unsigned int v39; // r7
  int v40; // r11
  int *v41; // r3
  int *v42; // r4
  unsigned int v43; // r7
  int v44; // r11
  int *v45; // r3
  int *v46; // r4

  v5 = image->cur_my + 1;
  v6 = image->tile_row_height[ty];
  if ( v5 >= v6 )
  {
    v5 -= v6;
    ++ty;
  }
  v7 = ty;
  v8 = image->tile_row_position[ty];
  v9 = v8 + v5;
  if ( v8 + v5 == 0 || image->disableTileOverlapFlag != 0 && v9 == v8 )
  {
    v10 = 0;
    if ( image->tile_columns != 0 )
    {
      v11 = 0;
      do
      {
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          data = image->strip[ch].up1[image->tile_column_position[v11]].data;
          *data -= data[1];
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v13 = &image->strip[ch].up1[image->tile_column_position[v11] + image->tile_column_width[v11]];
          v13[-1].data[1] -= *v13[-1].data;
        }
        ++v10;
        ++v11;
      }
      while ( v10 < image->tile_columns );
    }
  }
  v14 = v9 + 1;
  if ( v9 + 1 == image->extended_height >> 4
    || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
  {
    v15 = 0;
    if ( image->tile_columns != 0 )
    {
      v16 = 0;
      do
      {
        if ( v15 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v17 = image->strip[ch].up1[image->tile_column_position[v16]].data;
          v17[6] -= v17[7];
        }
        if ( v15 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v18 = &image->strip[ch].up1[image->tile_column_position[v16] + image->tile_column_width[v16]];
          v18[-1].data[7] -= v18[-1].data[6];
        }
        ++v15;
        ++v16;
      }
      while ( v15 < image->tile_columns );
    }
  }
  tile_columns = image->tile_columns;
  v20 = 0;
  if ( tile_columns != 0 )
  {
    while ( 1 )
    {
      if ( v20 == 0 || image->disableTileOverlapFlag != 0 )
      {
        v21 = image->strip[ch].up1[image->tile_column_position[v20]].data;
        _jxr_2PreFilter(a: v21 + 2, b: v21 + 4);
      }
      if ( v20 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v22 = image->strip[ch].up1[image->tile_column_position[v20] - 1 + image->tile_column_width[v20]].data;
        _jxr_2PreFilter(a: v22 + 3, b: v22 + 5);
      }
      if ( v9 == 0 || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] )
      {
        v23 = v20;
        for ( i = 0; i < image->tile_column_width[v23]; ++i )
        {
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v23] + i != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_43;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            continue;
          }
          if ( i != 0 )
          {
LABEL_43:
            v26 = &image->strip[ch].up1[image->tile_column_position[v23] + i];
            _jxr_2PreFilter(a: v26[-1].data + 1, b: v26->data);
          }
        }
      }
      if ( v14 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
      {
        v27 = v20;
        for ( j = 0; j < image->tile_column_width[v27]; ++j )
        {
          v29 = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v27] + j != 0 )
          {
            if ( v29 == 0 )
              goto LABEL_54;
          }
          else if ( v29 == 0 )
          {
            continue;
          }
          if ( j != 0 )
          {
LABEL_54:
            v30 = &image->strip[ch].up1[image->tile_column_position[v27] + j];
            _jxr_2PreFilter(a: v30[-1].data + 7, b: v30->data + 6);
          }
        }
      }
      v31 = v20;
      v32 = 0;
      if ( image->tile_column_width[v20] != 0 )
        break;
LABEL_87:
      tile_columns = image->tile_columns;
      if ( ++v20 >= tile_columns )
        goto LABEL_88;
    }
    while ( 1 )
    {
      if ( v9 >= (image->extended_height >> 4) - 1 )
        goto LABEL_80;
      if ( v20 == 0 && v32 == 0 )
        break;
      if ( image->disableTileOverlapFlag != 0 && v32 == 0 )
        goto LABEL_64;
LABEL_66:
      v33 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v31] + v32 == (image->extended_width >> 4) - 1 )
      {
        if ( v33 == 0 )
          goto LABEL_72;
      }
      else if ( v33 == 0 )
      {
        goto LABEL_73;
      }
      if ( v32 == image->tile_column_width[v31] - 1
        && v9 != image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
      {
LABEL_72:
        v34 = image->tile_column_position[v31] + image->tile_column_width[v31];
        _jxr_2PreFilter(a: image->strip[ch].up1[v34 - 1].data + 7, b: image->strip[ch].up2[v34 - 1].data + 1);
      }
LABEL_73:
      v35 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v31] + v32 >= (image->extended_width >> 4) - 1 )
      {
        if ( v35 == 0 )
          goto LABEL_80;
      }
      else if ( v35 == 0 )
      {
        goto LABEL_79;
      }
      if ( v32 != image->tile_column_width[v31] - 1
        && v9 != image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
      {
LABEL_79:
        v36 = image->tile_column_position[v31] + v32;
        _jxr_2x2PreFilter(
          a: image->strip[ch].up1[v36].data + 7,
          b: image->strip[ch].up1[v36 + 1].data + 6,
          c: image->strip[ch].up2[v36].data + 1,
          d: image->strip[ch].up2[v36 + 1].data);
      }
LABEL_80:
      v37 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v31] + v32 >= (image->extended_width >> 4) - 1 )
      {
        if ( v37 == 0 )
          goto LABEL_86;
      }
      else if ( v37 == 0 )
      {
        goto LABEL_85;
      }
      if ( v32 != image->tile_column_width[v31] - 1 )
      {
LABEL_85:
        v38 = &image->strip[ch].up1[image->tile_column_position[v31] + v32];
        _jxr_2x2PreFilter(a: v38->data + 3, b: v38[1].data + 2, c: v38->data + 5, d: v38[1].data + 4);
      }
LABEL_86:
      if ( ++v32 >= image->tile_column_width[v31] )
        goto LABEL_87;
    }
    if ( image->disableTileOverlapFlag != 0 )
    {
LABEL_64:
      if ( v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
        goto LABEL_66;
    }
    _jxr_2PreFilter(
      a: image->strip[ch].up1[image->tile_column_position[v31]].data + 6,
      b: image->strip[ch].up2[image->tile_column_position[v31]].data);
    goto LABEL_66;
  }
LABEL_88:
  if ( v9 == 0 || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] )
  {
    v39 = 0;
    if ( tile_columns != 0 )
    {
      v40 = 0;
      do
      {
        if ( v39 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v41 = image->strip[ch].up1[image->tile_column_position[v40]].data;
          *v41 += v41[1];
        }
        if ( v39 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v42 = image->strip[ch].up1[image->tile_column_position[v40] - 1 + image->tile_column_width[v40]].data;
          v42[1] += *v42;
        }
        tile_columns = image->tile_columns;
        ++v39;
        ++v40;
      }
      while ( v39 < tile_columns );
    }
  }
  if ( v14 == image->extended_height >> 4
    || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
  {
    v43 = 0;
    if ( tile_columns != 0 )
    {
      v44 = 0;
      do
      {
        if ( v43 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v45 = image->strip[ch].up1[image->tile_column_position[v44]].data;
          v45[6] += v45[7];
        }
        if ( v43 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v46 = image->strip[ch].up1[image->tile_column_position[v44] - 1 + image->tile_column_width[v44]].data;
          v46[7] += v46[6];
        }
        ++v43;
        ++v44;
      }
      while ( v43 < image->tile_columns );
    }
  }
}


// ========================================================================
// second_prefilter420_up1
// EA  : 0x8291F290
// RVA : 0x0091F290
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall second_prefilter420_up1(jxr_image *image, int ch, int ty)
{
  unsigned int v5; // r11
  unsigned int v6; // r10
  int v7; // r27
  unsigned int v8; // r10
  unsigned int v9; // r25
  unsigned int v10; // r7
  int v11; // r11
  int *data; // r3
  macroblock_s *v13; // r3
  unsigned int v14; // r24
  unsigned int v15; // r7
  int v16; // r11
  int *v17; // r3
  int *v18; // r4
  unsigned int tile_columns; // r10
  int v20; // r26
  int v21; // r29
  unsigned int i; // r30
  unsigned int disableTileOverlapFlag; // r11
  macroblock_s *v24; // r11
  int v25; // r30
  int v26; // r29
  unsigned int v27; // r11
  unsigned int v28; // r8
  unsigned int v29; // r11
  int v30; // r10
  int v31; // r29
  int v32; // r30
  unsigned int v33; // r11
  macroblock_s *v34; // r11
  unsigned int v35; // r7
  int v36; // r11
  int *v37; // r3
  int *v38; // r4
  unsigned int v39; // r7
  int v40; // r11
  int *v41; // r3
  int *v42; // r4

  v5 = image->cur_my + 1;
  v6 = image->tile_row_height[ty];
  if ( v5 >= v6 )
  {
    v5 -= v6;
    ++ty;
  }
  v7 = ty;
  v8 = image->tile_row_position[ty];
  v9 = v8 + v5;
  if ( v8 + v5 == 0 || image->disableTileOverlapFlag != 0 && v9 == v8 )
  {
    v10 = 0;
    if ( image->tile_columns != 0 )
    {
      v11 = 0;
      do
      {
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          data = image->strip[ch].up1[image->tile_column_position[v11]].data;
          *data -= data[1];
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v13 = &image->strip[ch].up1[image->tile_column_position[v11] + image->tile_column_width[v11]];
          v13[-1].data[1] -= *v13[-1].data;
        }
        ++v10;
        ++v11;
      }
      while ( v10 < image->tile_columns );
    }
  }
  v14 = v9 + 1;
  if ( v9 + 1 == image->extended_height >> 4
    || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
  {
    v15 = 0;
    if ( image->tile_columns != 0 )
    {
      v16 = 0;
      do
      {
        if ( v15 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v17 = image->strip[ch].up1[image->tile_column_position[v16]].data;
          v17[2] -= v17[3];
        }
        if ( v15 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v18 = image->strip[ch].up1[image->tile_column_position[v16] - 1 + image->tile_column_width[v16]].data;
          v18[3] -= v18[2];
        }
        ++v15;
        ++v16;
      }
      while ( v15 < image->tile_columns );
    }
  }
  tile_columns = image->tile_columns;
  v20 = 0;
  if ( tile_columns != 0 )
  {
    while ( 1 )
    {
      if ( v9 == 0 || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] )
      {
        v21 = v20;
        for ( i = 0; i < image->tile_column_width[v21]; ++i )
        {
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v21] + i != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_37;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            continue;
          }
          if ( i != 0 )
          {
LABEL_37:
            v24 = &image->strip[ch].up1[image->tile_column_position[v21] + i];
            _jxr_2PreFilter(a: v24[-1].data + 1, b: v24->data);
          }
        }
      }
      if ( v14 != image->extended_height >> 4
        && (image->disableTileOverlapFlag == 0 || v9 != image->tile_row_position[v7] + image->tile_row_height[v7] - 1) )
      {
        v25 = v20;
        v26 = 0;
        if ( image->tile_column_width[v20] != 0 )
        {
          while ( v20 != 0 || v26 != 0 )
          {
            if ( image->disableTileOverlapFlag != 0 && v26 == 0 )
              goto LABEL_49;
LABEL_51:
            v27 = image->disableTileOverlapFlag;
            if ( image->tile_column_position[v25] + v26 == (image->extended_width >> 4) - 1 )
            {
              if ( v27 == 0 )
                goto LABEL_57;
            }
            else if ( v27 == 0 )
            {
              goto LABEL_58;
            }
            if ( v26 == image->tile_column_width[v25] - 1
              && v9 != image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
            {
LABEL_57:
              v28 = image->tile_column_position[v25] + image->tile_column_width[v25];
              _jxr_2PreFilter(a: image->strip[ch].up1[v28 - 1].data + 3, b: image->strip[ch].up2[v28 - 1].data + 1);
            }
LABEL_58:
            v29 = image->disableTileOverlapFlag;
            if ( image->tile_column_position[v25] + v26 < (image->extended_width >> 4) - 1 )
            {
              if ( v29 != 0 )
              {
LABEL_62:
                if ( v26 == image->tile_column_width[v25] - 1
                  || v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
                {
                  goto LABEL_65;
                }
              }
              v30 = image->tile_column_position[v25] + v26;
              _jxr_2x2PreFilter(
                a: image->strip[ch].up1[v30].data + 3,
                b: image->strip[ch].up1[v30 + 1].data + 2,
                c: image->strip[ch].up2[v30].data + 1,
                d: image->strip[ch].up2[v30 + 1].data);
              goto LABEL_65;
            }
            if ( v29 != 0 )
              goto LABEL_62;
LABEL_65:
            if ( ++v26 >= image->tile_column_width[v25] )
              goto LABEL_75;
          }
          if ( image->disableTileOverlapFlag != 0 )
          {
LABEL_49:
            if ( v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
              goto LABEL_51;
          }
          _jxr_2PreFilter(
            a: image->strip[ch].up1[image->tile_column_position[v25]].data + 2,
            b: image->strip[ch].up2[image->tile_column_position[v25]].data);
          goto LABEL_51;
        }
        goto LABEL_75;
      }
      v31 = v20;
      v32 = 0;
      if ( image->tile_column_width[v20] != 0 )
        break;
LABEL_75:
      tile_columns = image->tile_columns;
      if ( ++v20 >= tile_columns )
        goto LABEL_76;
    }
    while ( 1 )
    {
      v33 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v31] + v32 != 0 )
      {
        if ( v33 == 0 )
          goto LABEL_73;
      }
      else if ( v33 == 0 )
      {
        goto LABEL_74;
      }
      if ( v32 != 0 )
      {
LABEL_73:
        v34 = &image->strip[ch].up1[image->tile_column_position[v31] + v32];
        _jxr_2PreFilter(a: v34[-1].data + 3, b: v34->data + 2);
      }
LABEL_74:
      if ( ++v32 >= image->tile_column_width[v31] )
        goto LABEL_75;
    }
  }
LABEL_76:
  if ( v9 == 0 || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] )
  {
    v35 = 0;
    if ( tile_columns != 0 )
    {
      v36 = 0;
      do
      {
        if ( v35 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v37 = image->strip[ch].up1[image->tile_column_position[v36]].data;
          *v37 += v37[1];
        }
        if ( v35 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v38 = image->strip[ch].up1[image->tile_column_position[v36] - 1 + image->tile_column_width[v36]].data;
          v38[1] += *v38;
        }
        tile_columns = image->tile_columns;
        ++v35;
        ++v36;
      }
      while ( v35 < tile_columns );
    }
  }
  if ( v14 == image->extended_height >> 4
    || image->disableTileOverlapFlag != 0 && v9 == image->tile_row_position[v7] + image->tile_row_height[v7] - 1 )
  {
    v39 = 0;
    if ( tile_columns != 0 )
    {
      v40 = 0;
      do
      {
        if ( v39 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v41 = image->strip[ch].up1[image->tile_column_position[v40]].data;
          v41[2] += v41[3];
        }
        if ( v39 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v42 = image->strip[ch].up1[image->tile_column_position[v40] - 1 + image->tile_column_width[v40]].data;
          v42[3] += v42[2];
        }
        ++v39;
        ++v40;
      }
      while ( v39 < image->tile_columns );
    }
  }
}


// ========================================================================
// PCT_stage1_up2
// EA  : 0x8291FA38
// RVA : 0x0091FA38
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall PCT_stage1_up2(jxr_image *image, int ch, int ty)
{
  unsigned int v4; // r22
  unsigned int *tile_row_height; // r10
  int v7; // r23
  unsigned int v8; // r11
  int v9; // r26
  int use_clr_fmt; // r11
  int v11; // r29
  char *v12; // r30
  int v13; // r21
  int v14; // r20
  int i; // r25
  int v16; // r27
  unsigned int v17; // r28
  _DWORD *v18; // r3
  int v19; // r9
  int v20; // r10
  _DWORD *v21; // r5
  _DWORD *v22; // r6
  int v23; // r4
  int v24; // r11
  int j; // ctr
  int v26; // r7
  int v27; // r28
  unsigned __int8 v28; // r11
  jxr_tile_qp *v29; // r28
  unsigned __int8 v30; // r11
  int v31; // r10
  jxr_tile_qp *v32; // r11
  signed int v33; // r3
  int v34; // r4
  int v35; // r28
  int v36; // r9
  int v37; // r5
  int k; // ctr
  int v39; // r11
  int v40; // r7
  int v41; // r6
  int v42; // r8
  int v43; // r10
  int v44; // r7
  int v45; // r10
  int v46; // r7
  int v47; // r27
  unsigned int *tile_column_position; // r8
  int v49; // r6
  int v50; // r8
  int v51; // r10
  int v52; // r6
  int v53; // r10
  int v54; // r6
  unsigned int v55; // r8
  unsigned int *v56; // r10
  int v57; // r7
  int v58; // r8
  int v59; // r10
  int v60; // r7
  int v61; // r10
  int v62; // r7
  int v63; // r27
  unsigned int *v64; // r8
  int v65; // r6
  int v66; // r8
  int v67; // r10
  int v68; // r27
  int v69; // r6
  unsigned int *v70; // r10
  int v71; // r7
  int v72; // r8
  int v73; // r10
  int v74; // r11
  int v75; // r8
  _BYTE v76[1136]; // [sp+50h] [-470h] BYREF

  v4 = image->cur_my + 2;
  tile_row_height = image->tile_row_height;
  v7 = ty;
  if ( v4 >= tile_row_height[ty] )
  {
    v7 = ty + 1;
    v4 -= tile_row_height[ty];
    if ( v4 >= tile_row_height[ty + 1] )
    {
      v8 = tile_row_height[v7];
      v7 = ty + 2;
      v4 -= v8;
    }
  }
  v9 = 16;
  if ( ch > 0 )
  {
    use_clr_fmt = image->use_clr_fmt;
    if ( use_clr_fmt == 2 )
    {
      v9 = 8;
    }
    else if ( use_clr_fmt == 1 )
    {
      v9 = 4;
    }
  }
  v11 = 0;
  if ( image->extended_width >> 4 != 0 )
  {
    v12 = (char *)image + 28 * ch;
    v13 = 16 * v9;
    v14 = 15 * v9 + 16;
    for ( i = 0; ; i += 84 )
    {
      if ( v13 > 0 )
      {
        v16 = 0;
        v17 = ((unsigned int)(v13 - 1) >> 4) + 1;
        do
        {
          _jxr_4x4PCT(coeff: (int *)(*(_DWORD *)(*((_DWORD *)v12 + 33) + i) + v16));
          --v17;
          v16 += 64;
        }
        while ( v17 != 0 );
      }
      v18 = *(_DWORD **)(*((_DWORD *)v12 + 33) + i);
      v19 = 0;
      v20 = 0;
      v21 = v76;
      v22 = v18;
      v23 = v9;
      do
      {
        v24 = 1;
        *v21 = *v22;
        for ( j = 15; j != 0; --j )
        {
          v26 = v20 + v24;
          v27 = 4 * (v19 + v24++);
          *(_DWORD *)&v76[v27 + 60] = v18[v26];
        }
        --v23;
        v22 += 16;
        ++v21;
        v20 += 16;
        v19 += 15;
      }
      while ( v23 != 0 );
      if ( v14 > 0 )
        blkmov(a1: v18, a2: v76, a3: 4 * v14);
      if ( (*((_DWORD *)image + 26) & 0x4000000) != 0 )
      {
        v28 = image->hp_quant_ch[ch][0];
        goto LABEL_32;
      }
      v29 = &image->tile_quant[(image->tile_rows + 1) * v7];
      if ( v29->hp_map != nullptr )
        v30 = v29->hp_map[jxr_get_TILE_WIDTH(image, column: 0) * v4 + v11];
      else
        v30 = 0;
      v31 = v30;
      v32 = &image->tile_quant[(image->tile_rows + 1) * v7];
      if ( ch == 0 || v32->component_mode == JXR_CM_UNIFORM )
        goto LABEL_31;
      if ( v32->component_mode != JXR_CM_SEPARATE )
        break;
      v28 = v32->channel[1].hp_qp[v31];
LABEL_32:
      v33 = _jxr_quant_map(image, x: v28, shift: 1);
      v34 = 0;
      v35 = v9;
      v36 = (3 * v33 + 1) >> 3;
      do
      {
        v37 = 0;
        for ( k = 3; k != 0; --k )
        {
          v39 = v34 + v37;
          v40 = 1;
          v41 = 4 * (v34 + v37 + 16);
          v42 = *(_DWORD *)(84 * (*image->tile_column_position + v11) + *((_DWORD *)v12 + 33));
          v43 = *(_DWORD *)(v42 + v41);
          if ( v43 < 0 )
          {
            v40 = -1;
            v43 = -v43;
          }
          v44 = (v36 + v43) * v40;
          v45 = __ROL4__(v44, 1);
          *(_DWORD *)(v42 + v41) = v44 / v33;
          v46 = 4 * (v39 + 17);
          v47 = *((_DWORD *)v12 + 33);
          tile_column_position = image->tile_column_position;
          __twllei(v33, 0);
          v49 = 1;
          __twlgei(v33 & ~(v45 - 1), 0xFFFFFFFF);
          v50 = *(_DWORD *)(84 * (*tile_column_position + v11) + v47);
          v51 = *(_DWORD *)(v50 + v46);
          if ( v51 < 0 )
          {
            v49 = -1;
            v51 = -v51;
          }
          v52 = (v36 + v51) * v49;
          v53 = __ROL4__(v52, 1);
          *(_DWORD *)(v50 + v46) = v52 / v33;
          v54 = 4 * (v39 + 18);
          v55 = v33 & ~(v53 - 1);
          v56 = image->tile_column_position;
          __twllei(v33, 0);
          __twlgei(v55, 0xFFFFFFFF);
          v57 = 1;
          v58 = *(_DWORD *)(84 * (*v56 + v11) + *((_DWORD *)v12 + 33));
          v59 = *(_DWORD *)(v58 + v54);
          if ( v59 < 0 )
          {
            v57 = -1;
            v59 = -v59;
          }
          v60 = (v36 + v59) * v57;
          v61 = __ROL4__(v60, 1);
          *(_DWORD *)(v58 + v54) = v60 / v33;
          v62 = 4 * (v39 + 19);
          v63 = *((_DWORD *)v12 + 33);
          v64 = image->tile_column_position;
          __twllei(v33, 0);
          v65 = 1;
          __twlgei(v33 & ~(v61 - 1), 0xFFFFFFFF);
          v66 = *(_DWORD *)(84 * (*v64 + v11) + v63);
          v67 = *(_DWORD *)(v66 + v62);
          if ( v67 < 0 )
          {
            v65 = -1;
            v67 = -v67;
          }
          v68 = v39 + 20;
          v69 = (v36 + v67) * v65;
          *(_DWORD *)(v66 + v62) = v69 / v33;
          v70 = image->tile_column_position;
          __twllei(v33, 0);
          v71 = *((_DWORD *)v12 + 33);
          v72 = 1;
          __twlgei(v33 & ~(__ROL4__(v69, 1) - 1), 0xFFFFFFFF);
          v73 = *(_DWORD *)(84 * (*v70 + v11) + v71);
          v74 = *(_DWORD *)(v73 + 4 * (v39 + 20));
          if ( v74 < 0 )
          {
            v72 = -1;
            v74 = -v74;
          }
          v37 += 5;
          v75 = (v36 + v74) * v72;
          *(_DWORD *)(v73 + 4 * v68) = v75 / v33;
          __twllei(v33, 0);
          __twlgei(v33 & ~(__ROL4__(v75, 1) - 1), 0xFFFFFFFF);
        }
        --v35;
        v34 += 15;
      }
      while ( v35 != 0 );
      if ( ++v11 >= (signed int)(image->extended_width >> 4) )
        return;
    }
    if ( v32->component_mode >= (unsigned int)JXR_CM_Reserved )
    {
      v28 = 0;
      goto LABEL_32;
    }
    v32 = (jxr_tile_qp *)((char *)v32 + 35 * ch);
LABEL_31:
    v28 = v32->channel[0].hp_qp[v31];
    goto LABEL_32;
  }
}


// ========================================================================
// w_calculate_mbdc_mode
// EA  : 0x8291FEB8
// RVA : 0x0091FEB8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

int __fastcall w_calculate_mbdc_mode(jxr_image *image, int tx, int mx, int my)
{
  int use_clr_fmt; // r7
  int v6; // r9
  macroblock_s *v7; // r10
  int v8; // r30
  int v9; // r29
  int v10; // r6
  int v11; // r10
  int v12; // r11
  macroblock_s *v13; // r9
  macroblock_s *v14; // r8
  macroblock_s *v15; // r4
  int *pred_dclp; // r28
  int *v17; // r3
  int *v18; // r11
  int *v19; // r9
  int *v20; // r31
  int v21; // r8
  int v22; // r11
  int v23; // r3
  int v24; // r9
  int v25; // r3
  unsigned int v26; // r9
  signed int v27; // r11

  if ( mx == 0 )
    return my == 0 ? 3 : 1;
  if ( my == 0 )
    return 0;
  use_clr_fmt = image->use_clr_fmt;
  v6 = image->tile_column_position[tx] + mx;
  v7 = &image->strip[0].cur[v6];
  v8 = *v7->pred_dclp;
  v9 = *image->strip[0].up1[v6 - 1].pred_dclp;
  v10 = *v7[-1].pred_dclp;
  if ( image->use_clr_fmt == 0 || use_clr_fmt == 6 )
  {
    v26 = abs32(v10 - v9);
    v27 = abs32(v10 - v8);
  }
  else
  {
    v11 = 2;
    v12 = image->tile_column_position[tx] + mx;
    v13 = &image->strip[1].cur[v12];
    v14 = &image->strip[2].cur[v12];
    v15 = &image->strip[1].up1[v12];
    pred_dclp = image->strip[2].up1[v12 - 1].pred_dclp;
    v17 = v13->pred_dclp;
    v18 = v13[-1].pred_dclp;
    v19 = v14->pred_dclp;
    v20 = v14[-1].pred_dclp;
    v21 = *v17;
    v22 = *v18;
    v23 = *v19;
    v24 = *v20;
    if ( use_clr_fmt == 2 )
    {
      v11 = 4;
    }
    else if ( use_clr_fmt == 1 )
    {
      v11 = 8;
    }
    v25 = v24 - v23;
    v26 = abs32(v10 - v9) * v11 + abs32(v24 - *pred_dclp) + abs32(v22 - *v15[-1].pred_dclp);
    v27 = abs32(v10 - v8) * v11 + abs32(v25) + abs32(v22 - v21);
  }
  if ( (int)(4 * v26) >= v27 )
    return __CFADD__(4 * v27 - v26, v26 ^ 0x80000000) ? 0 : 2;
  else
    return 1;
}


// ========================================================================
// w_calculate_mbhp_mode_up1
// EA  : 0x82920090
// RVA : 0x00920090
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

int __fastcall w_calculate_mbhp_mode_up1(jxr_image *image, int tx, int mx)
{
  int v3; // r11
  int *data; // r5
  signed int v5; // r10
  signed int v6; // r9
  int *v7; // r5
  int *v8; // r6
  int v9; // r7
  int v10; // r11
  int *v11; // r6
  int *v12; // r5
  unsigned int v13; // r8
  unsigned int v14; // r11
  unsigned int v15; // r6
  unsigned int v16; // r7
  int v17; // r4
  int result; // r3

  v3 = image->tile_column_position[tx] + mx;
  data = image->strip[0].up1[v3].data;
  v5 = abs32(data[3]) + abs32(data[2]) + abs32(data[1]);
  v6 = abs32(data[12]) + abs32(data[8]) + abs32(data[4]);
  if ( (unsigned int)image->use_clr_fmt - 1 > 3 )
    goto LABEL_9;
  if ( image->use_clr_fmt == 1 )
  {
    v7 = image->strip[2].up1[v3].data;
    v8 = image->strip[1].up1[v3].data;
    v9 = v7[2];
    v10 = v8[2];
    goto LABEL_7;
  }
  if ( image->use_clr_fmt != 2 )
  {
    v7 = image->strip[2].up1[v3].data;
    v8 = image->strip[1].up1[v3].data;
    v9 = v7[4];
    v10 = v8[4];
LABEL_7:
    v17 = v8[1];
    v16 = abs32(v9);
    v14 = abs32(v10);
    v15 = abs32(v7[1]);
    v13 = abs32(v17);
    goto LABEL_8;
  }
  v11 = image->strip[1].up1[v3].data;
  v12 = image->strip[2].up1[v3].data;
  v13 = abs32(v11[5]) + abs32(v11[1]) + abs32(v12[5]);
  v14 = abs32(v11[6]) + abs32(v11[2]) + abs32(v12[6]);
  v15 = abs32(v12[1]);
  v16 = abs32(v12[2]);
LABEL_8:
  v5 += v13 + v15;
  v6 += v14 + v16;
LABEL_9:
  if ( 4 * v5 < v6 )
    return 0;
  result = 1;
  if ( 4 * v6 >= v5 )
    return 2;
  return result;
}


// ========================================================================
// w_predict_up1_hp
// EA  : 0x82920298
// RVA : 0x00920298
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall w_predict_up1_hp(jxr_image *image, int ch, int tx, int mx, int mbhp_pred_mode)
{
  char v5; // r30
  int v6; // r11
  int i; // ctr
  char *v8; // r10
  int v9; // r31
  int v10; // r31
  int v11; // r9
  int v12; // ctr
  char *v13; // r10
  int v14; // r9
  int v15; // r11
  int v16; // r31
  int v17; // r31
  int v18; // r31
  int v19; // r31
  int v20; // r8
  int v21; // r4
  int use_clr_fmt; // r11
  int v23; // r10
  int v24; // r11
  int n; // ctr
  int *v26; // r5
  int *v27; // r4
  int *v28; // r7
  int *v29; // r5
  int *v30; // r4
  int v31; // r8
  int v32; // r10
  int v33; // r11
  int m; // ctr
  int *v35; // r5
  int *v36; // r4
  int *v37; // r7
  int *v38; // r5
  int *v39; // r4
  int v40; // r8
  int v41; // r10
  int v42; // r11
  int k; // ctr
  int *v44; // r5
  int *v45; // r4
  int *v46; // r7
  int *v47; // r5
  int *v48; // r4
  int v49; // r8
  int v50; // r10
  int v51; // r11
  int j; // ctr
  int *v53; // r5
  int *v54; // r4
  int *data; // r7
  int *v56; // r5
  int *v57; // r4
  int v58; // r8

  if ( mbhp_pred_mode != 0 )
  {
    if ( mbhp_pred_mode == 1 )
    {
      v12 = 12;
      v13 = (char *)image + 28 * ch;
      v14 = tx;
      v15 = 900;
      do
      {
        v16 = *(_DWORD *)(84 * (image->tile_column_position[v14] + mx) + *((_DWORD *)v13 + 34));
        *(_DWORD *)(v15 + v16 + 64) -= *(_DWORD *)(v15 + v16 - 176);
        v17 = *(_DWORD *)(84 * (image->tile_column_position[v14] + mx) + *((_DWORD *)v13 + 34));
        *(_DWORD *)(v15 + v17 + 68) -= *(_DWORD *)(v15 + v17 - 172);
        v18 = *(_DWORD *)(84 * (image->tile_column_position[v14] + mx) + *((_DWORD *)v13 + 34));
        v20 = *(_DWORD *)(v15 + v18 - 168);
        v19 = *(_DWORD *)(v15 + v18 + 72);
        v21 = v15 + *(_DWORD *)(84 * (image->tile_column_position[v14] + mx) + *((_DWORD *)v13 + 34));
        v15 -= 60;
        *(_DWORD *)(v21 + 72) = v19 - v20;
        --v12;
      }
      while ( v12 != 0 );
    }
  }
  else
  {
    v5 = 15;
    v6 = 900;
    for ( i = 15; i != 0; --i )
    {
      if ( (v5 & 3) != 0 )
      {
        v8 = (char *)image + 28 * ch;
        v9 = *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
        *(_DWORD *)(v6 + v9 + 76) -= *(_DWORD *)(v6 + v9 + 16);
        v10 = *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
        *(_DWORD *)(v6 + v10 + 92) -= *(_DWORD *)(v6 + v10 + 32);
        v11 = *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
        *(_DWORD *)(v6 + v11 + 108) -= *(_DWORD *)(v6 + v11 + 48);
      }
      --v5;
      v6 -= 60;
    }
  }
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 1 )
  {
    if ( mbhp_pred_mode != 0 )
    {
      if ( mbhp_pred_mode == 1 )
      {
        v50 = tx;
        v51 = 45;
        for ( j = 2; j != 0; --j )
        {
          v53 = &image->strip[1].up1[image->tile_column_position[v50] + mx].data[v51];
          v53[16] -= *(v53 - 14);
          v54 = &image->strip[2].up1[image->tile_column_position[v50] + mx].data[v51];
          v54[16] -= *(v54 - 14);
          data = image->strip[1].up1[image->tile_column_position[v50] + mx].data;
          data[v51 + 17] -= data[v51 - 13];
          v56 = &image->strip[2].up1[image->tile_column_position[v50] + mx].data[v51];
          v56[17] -= *(v56 - 13);
          v57 = &image->strip[1].up1[image->tile_column_position[v50] + mx].data[v51];
          v57[18] -= *(v57 - 12);
          v58 = image->tile_column_position[v50] + mx;
          image->strip[2].up1[v58].data[v51 + 18] -= image->strip[2].up1[v58].data[v51 - 12];
          v51 -= 15;
        }
      }
    }
    else
    {
      v41 = tx;
      v42 = 45;
      for ( k = 2; k != 0; --k )
      {
        v44 = &image->strip[1].up1[image->tile_column_position[v41] + mx].data[v42];
        v44[19] -= v44[4];
        v45 = &image->strip[2].up1[image->tile_column_position[v41] + mx].data[v42];
        v45[19] -= v45[4];
        v46 = image->strip[1].up1[image->tile_column_position[v41] + mx].data;
        v46[v42 + 23] -= v46[v42 + 8];
        v47 = &image->strip[2].up1[image->tile_column_position[v41] + mx].data[v42];
        v47[23] -= v47[8];
        v48 = &image->strip[1].up1[image->tile_column_position[v41] + mx].data[v42];
        v48[27] -= v48[12];
        v49 = image->tile_column_position[v41] + mx;
        image->strip[2].up1[v49].data[v42 + 27] -= image->strip[2].up1[v49].data[v42 + 12];
        v42 -= 30;
      }
    }
  }
  else if ( use_clr_fmt == 2 )
  {
    if ( mbhp_pred_mode != 0 )
    {
      if ( mbhp_pred_mode == 1 )
      {
        v32 = tx;
        v33 = 105;
        for ( m = 6; m != 0; --m )
        {
          v35 = &image->strip[1].up1[image->tile_column_position[v32] + mx].data[v33];
          v35[16] -= *(v35 - 14);
          v36 = &image->strip[2].up1[image->tile_column_position[v32] + mx].data[v33];
          v36[16] -= *(v36 - 14);
          v37 = image->strip[1].up1[image->tile_column_position[v32] + mx].data;
          v37[v33 + 17] -= v37[v33 - 13];
          v38 = &image->strip[2].up1[image->tile_column_position[v32] + mx].data[v33];
          v38[17] -= *(v38 - 13);
          v39 = &image->strip[1].up1[image->tile_column_position[v32] + mx].data[v33];
          v39[18] -= *(v39 - 12);
          v40 = image->tile_column_position[v32] + mx;
          image->strip[2].up1[v40].data[v33 + 18] -= image->strip[2].up1[v40].data[v33 - 12];
          v33 -= 15;
        }
      }
    }
    else
    {
      v23 = tx;
      v24 = 105;
      for ( n = 4; n != 0; --n )
      {
        v26 = &image->strip[1].up1[image->tile_column_position[v23] + mx].data[v24];
        v26[19] -= v26[4];
        v27 = &image->strip[2].up1[image->tile_column_position[v23] + mx].data[v24];
        v27[19] -= v27[4];
        v28 = image->strip[1].up1[image->tile_column_position[v23] + mx].data;
        v28[v24 + 23] -= v28[v24 + 8];
        v29 = &image->strip[2].up1[image->tile_column_position[v23] + mx].data[v24];
        v29[23] -= v29[8];
        v30 = &image->strip[1].up1[image->tile_column_position[v23] + mx].data[v24];
        v30[27] -= v30[12];
        v31 = image->tile_column_position[v23] + mx;
        image->strip[2].up1[v31].data[v24 + 27] -= image->strip[2].up1[v31].data[v24 + 12];
        v24 -= 30;
      }
    }
  }
}


// ========================================================================
// w_predict_lp444
// EA  : 0x829209C8
// RVA : 0x009209C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall w_predict_lp444(jxr_image *image, int tx, int mx, int my, int ch, int mblp_mode)
{
  int v6; // r11
  char *v7; // r10
  _DWORD *v8; // r9
  _DWORD *v9; // r9
  _DWORD *v10; // r9
  _DWORD *v11; // r9
  _DWORD *v12; // r9
  _DWORD *v13; // r9
  int v14; // r8
  unsigned int v15; // r9
  unsigned int v16; // r9
  int v17; // r7
  int v18; // r6
  unsigned int v19; // r9
  unsigned int v20; // r9
  unsigned int v21; // r11

  v6 = tx;
  v7 = (char *)image + 28 * my;
  v8 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v8[1] + 4) = *(_DWORD *)(*v8 + 4);
  v9 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v9[1] + 8) = *(_DWORD *)(*v9 + 8);
  v10 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v10[1] + 12) = *(_DWORD *)(*v10 + 12);
  v11 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v11[1] + 16) = *(_DWORD *)(*v11 + 16);
  v12 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v12[1] + 20) = *(_DWORD *)(*v12 + 32);
  v13 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v13[1] + 24) = *(_DWORD *)(*v13 + 48);
  if ( ch != 0 )
  {
    if ( ch == 1 )
    {
      v14 = 28 * (my + 5);
      v15 = 84 * (image->tile_column_position[v6] + mx);
      *(_DWORD *)(*(_DWORD *)(v15 + *((_DWORD *)v7 + 34)) + 4) -= *(_DWORD *)(*(_DWORD *)(v15
                                                                                        + *(int *)((char *)&image->user_flags
                                                                                                 + v14)
                                                                                        + 4)
                                                                            + 4);
      v16 = 84 * (image->tile_column_position[v6] + mx);
      *(_DWORD *)(*(_DWORD *)(v16 + *((_DWORD *)v7 + 34)) + 8) -= *(_DWORD *)(*(_DWORD *)(v16
                                                                                        + *(int *)((char *)&image->user_flags
                                                                                                 + v14)
                                                                                        + 4)
                                                                            + 8);
      v17 = image->tile_column_position[v6] + mx;
      v18 = *(_DWORD *)(84 * v17 + *((_DWORD *)v7 + 34));
      *(_DWORD *)(v18 + 12) -= *(_DWORD *)(*(_DWORD *)(84 * v17 + *(int *)((char *)&image->user_flags + v14) + 4) + 12);
    }
  }
  else
  {
    v19 = 84 * (image->tile_column_position[v6] + mx) + *((_DWORD *)v7 + 34);
    *(_DWORD *)(*(_DWORD *)v19 + 16) -= *(_DWORD *)(*(_DWORD *)(v19 - 80) + 16);
    v20 = 84 * (image->tile_column_position[v6] + mx) + *((_DWORD *)v7 + 34);
    *(_DWORD *)(*(_DWORD *)v20 + 32) -= *(_DWORD *)(*(_DWORD *)(v20 - 80) + 20);
    v21 = 84 * (image->tile_column_position[v6] + mx) + *((_DWORD *)v7 + 34);
    *(_DWORD *)(*(_DWORD *)v21 + 48) -= *(_DWORD *)(*(_DWORD *)(v21 - 80) + 24);
  }
}


// ========================================================================
// w_predict_lp422
// EA  : 0x82920C28
// RVA : 0x00920C28
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall w_predict_lp422(
        jxr_image *image,
        int tx,
        int mx,
        int my,
        unsigned int ch,
        int mblp_mode,
        int mbdc_mode)
{
  int v7; // r11
  char *v8; // r10
  _DWORD *v9; // r9
  _DWORD *v10; // r9
  _DWORD *v11; // r9
  _DWORD *v12; // r9
  _DWORD *v13; // r9
  int v14; // r6
  int v15; // r7
  unsigned int v16; // r9
  unsigned int v17; // r9
  _DWORD *v18; // r11
  unsigned int v19; // r9
  unsigned int v20; // r9
  unsigned int v21; // r11

  v7 = tx;
  v8 = (char *)image + 28 * my;
  v9 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
  *(_DWORD *)(v9[1] + 4) = *(_DWORD *)(*v9 + 4);
  v10 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
  *(_DWORD *)(v10[1] + 8) = *(_DWORD *)(*v10 + 8);
  v11 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
  *(_DWORD *)(v11[1] + 16) = *(_DWORD *)(*v11 + 16);
  v12 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
  *(_DWORD *)(v12[1] + 20) = *(_DWORD *)(*v12 + 20);
  v13 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v8 + 34));
  *(_DWORD *)(v13[1] + 24) = *(_DWORD *)(*v13 + 24);
  if ( ch != 0 )
  {
    if ( ch == 1 )
    {
      v15 = 28 * (my + 5);
      v16 = 84 * (image->tile_column_position[v7] + mx);
      *(_DWORD *)(*(_DWORD *)(v16 + *((_DWORD *)v8 + 34)) + 16) -= *(_DWORD *)(*(_DWORD *)(v16
                                                                                         + *(int *)((char *)&image->user_flags
                                                                                                  + v15)
                                                                                         + 4)
                                                                             + 16);
      v17 = 84 * (image->tile_column_position[v7] + mx);
      *(_DWORD *)(*(_DWORD *)(v17 + *((_DWORD *)v8 + 34)) + 4) -= *(_DWORD *)(*(_DWORD *)(v17
                                                                                        + *(int *)((char *)&image->user_flags
                                                                                                 + v15)
                                                                                        + 4)
                                                                            + 20);
      v18 = (_DWORD *)(84 * (image->tile_column_position[v7] + mx) + *((_DWORD *)v8 + 34));
      *(_DWORD *)(*v18 + 20) -= *(_DWORD *)(v18[1] + 4);
    }
    else if ( ch < 3 && mblp_mode == 1 )
    {
      v14 = *(_DWORD *)(84 * (image->tile_column_position[v7] + mx) + *((_DWORD *)v8 + 34));
      *(_DWORD *)(v14 + 20) -= *(_DWORD *)(v14 + 4);
    }
  }
  else
  {
    v19 = 84 * (image->tile_column_position[v7] + mx) + *((_DWORD *)v8 + 34);
    *(_DWORD *)(*(_DWORD *)v19 + 16) -= *(_DWORD *)(*(_DWORD *)(v19 - 80) + 16);
    v20 = 84 * (image->tile_column_position[v7] + mx) + *((_DWORD *)v8 + 34);
    *(_DWORD *)(*(_DWORD *)v20 + 8) -= *(_DWORD *)(*(_DWORD *)(v20 - 80) + 8);
    v21 = 84 * (image->tile_column_position[v7] + mx) + *((_DWORD *)v8 + 34);
    *(_DWORD *)(*(_DWORD *)v21 + 24) -= *(_DWORD *)(*(_DWORD *)(v21 - 80) + 24);
  }
}


// ========================================================================
// w_predict_lp420
// EA  : 0x82920E98
// RVA : 0x00920E98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall w_predict_lp420(jxr_image *image, int tx, int mx, int my, int ch, int mblp_mode)
{
  int v6; // r11
  char *v7; // r10
  _DWORD *v8; // r9
  _DWORD *v9; // r9
  int v10; // r7
  int v11; // r6
  int v12; // r4
  unsigned int v13; // r11

  v6 = tx;
  v7 = (char *)image + 28 * my;
  v8 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v8[1] + 4) = *(_DWORD *)(*v8 + 4);
  v9 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *((_DWORD *)v7 + 34));
  *(_DWORD *)(v9[1] + 8) = *(_DWORD *)(*v9 + 8);
  if ( ch != 0 )
  {
    if ( ch == 1 )
    {
      v10 = 28 * (my + 5);
      v11 = image->tile_column_position[v6] + mx;
      v12 = *(_DWORD *)(*((_DWORD *)v7 + 34) + 84 * v11);
      *(_DWORD *)(v12 + 4) -= *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&image->user_flags + v10) + 84 * v11 + 4) + 4);
    }
  }
  else
  {
    v13 = 84 * (image->tile_column_position[v6] + mx) + *((_DWORD *)v7 + 34);
    *(_DWORD *)(*(_DWORD *)v13 + 8) -= *(_DWORD *)(*(_DWORD *)(v13 - 80) + 8);
  }
}


// ========================================================================
// calculate_hpcbp_up1
// EA  : 0x82920F80
// RVA : 0x00920F80
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall calculate_hpcbp_up1(jxr_image *image, unsigned int tx, unsigned int ty, unsigned int mx)
{
  unsigned int v6; // r7
  char *v8; // r11
  int i; // ctr
  int v10; // r23
  unsigned int v11; // r4
  char *v12; // r3
  unsigned __int8 *p_shift_bits; // r22
  model_s *p_model_hp; // r21
  int v15; // r30
  int v16; // r24
  int use_clr_fmt; // r11
  int v18; // r26
  unsigned int *tile_column_position; // r5
  const int *v20; // r25
  int v21; // r7
  int v22; // r6
  int v23; // r11
  int v24; // r8
  int v25; // r11
  int v26; // r29
  int v27; // r27
  int j; // ctr
  int v29; // r11
  unsigned int v30; // r9
  unsigned int *v31; // r10
  int k; // ctr
  int v33; // r7
  char v34; // [sp+4Ch] [-C4h] BYREF
  char v35[192]; // [sp+50h] [-C0h] BYREF

  v6 = image->cur_my + 1;
  if ( v6 == image->tile_row_height[ty] )
  {
    v6 = 0;
    ++ty;
  }
  if ( _jxr_InitContext(image, tx, ty, mx, my: v6) != 0 )
    _jxr_InitializeModelMB(model: &image->model_hp, band: 2);
  v8 = &v34;
  for ( i = 16; i != 0; --i )
  {
    v8 += 4;
    *(_DWORD *)v8 = 0;
  }
  v10 = 0;
  if ( image->num_channels != 0 )
  {
    v11 = tx;
    v12 = v35;
    p_shift_bits = &image->shift_bits;
    p_model_hp = &image->model_hp;
    do
    {
      v15 = 0;
      v16 = 16;
      if ( (-v10 & ~v10) < 0 )
      {
        use_clr_fmt = image->use_clr_fmt;
        if ( use_clr_fmt == 2 )
        {
          v16 = 8;
        }
        else if ( use_clr_fmt == 1 )
        {
          v16 = 4;
        }
      }
      v18 = 0;
      tile_column_position = image->tile_column_position;
      v20 = _jxr_hp_scan_map;
      v21 = *((_DWORD *)p_shift_bits + 7);
      v22 = p_model_hp->bits[0];
      do
      {
        v23 = v18;
        if ( v16 == 16 )
          v23 = *v20;
        v24 = 15 * v23;
        v26 = __ROL4__(1, v18);
        v27 = 15 * v23 + 20;
        v25 = 0;
        for ( j = 3; j != 0; --j )
        {
          if ( (int)abs32(*(_DWORD *)(*(_DWORD *)(84 * (tile_column_position[v11] + mx) + v21) + 4 * (v24 + v25 + 16))) >> v22 != 0 )
          {
            v15 |= v26;
            ++*(_DWORD *)v12;
          }
          if ( (int)abs32(*(_DWORD *)(*(_DWORD *)(84 * (tile_column_position[v11] + mx) + v21) + 4 * (v24 + v25 + 17))) >> v22 != 0 )
          {
            v15 |= v26;
            ++*(_DWORD *)v12;
          }
          if ( (int)abs32(*(_DWORD *)(*(_DWORD *)(84 * (tile_column_position[v11] + mx) + v21) + 4 * (v24 + v25 + 18))) >> v22 != 0 )
          {
            v15 |= v26;
            ++*(_DWORD *)v12;
          }
          if ( (int)abs32(*(_DWORD *)(*(_DWORD *)(84 * (tile_column_position[v11] + mx) + v21) + 4 * (v24 + v25 + 19))) >> v22 != 0 )
          {
            v15 |= v26;
            ++*(_DWORD *)v12;
          }
          if ( (int)abs32(*(_DWORD *)(*(_DWORD *)(84 * (tile_column_position[v11] + mx) + v21) + 4 * (v27 + v25))) >> v22 != 0 )
          {
            v15 |= v26;
            ++*(_DWORD *)v12;
          }
          v25 += 5;
        }
        ++v18;
        ++v20;
      }
      while ( v18 < v16 );
      ++v10;
      p_shift_bits += 28;
      p_model_hp = (model_s *)((char *)p_model_hp + 4);
      v12 += 4;
      *(_DWORD *)(84 * (image->tile_column_position[v11] + mx) + *(_DWORD *)p_shift_bits + 12) = v15;
    }
    while ( v10 < image->num_channels );
  }
  v29 = 0;
  v30 = tx;
  v31 = (unsigned int *)&image->model_lp.state[15];
  for ( k = 4; k != 0; --k )
  {
    image->strip[0].up1[image->tile_column_position[v30] + mx].hp_model_bits[v29] = v31[1];
    image->strip[0].up1[image->tile_column_position[v30] + mx].hp_model_bits[v29 + 1] = v31[2];
    image->strip[0].up1[image->tile_column_position[v30] + mx].hp_model_bits[v29 + 2] = v31[3];
    v31 += 4;
    v33 = 21 * (image->tile_column_position[v30] + mx) + v29;
    v29 += 4;
    image->strip[0].up1->hp_model_bits[v33 + 3] = *v31;
  }
  _jxr_UpdateModelMB(image, lap_mean: v35, model: &image->model_hp, band: 2);
}


// ========================================================================
// w_PredCBP
// EA  : 0x82921320
// RVA : 0x00921320
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall w_PredCBP(jxr_image *image, unsigned int tx, unsigned int ty, unsigned int mx)
{
  int v6; // r30
  int use_clr_fmt; // r11
  int v9; // r29

  v6 = image->cur_my + 1;
  if ( v6 == image->tile_row_height[ty] )
  {
    v6 = 0;
    ++ty;
  }
  if ( _jxr_InitContext(image, tx, ty, mx, my: v6) != 0 )
    _jxr_InitializeCBPModel(image);
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 1 )
  {
    _jxr_w_PredCBP444(image, channel: 0, tx, mx, my: v6);
    _jxr_w_PredCBP420(image, channel: 1, tx, mx, my: v6);
    _jxr_w_PredCBP420(image, channel: 2, tx, mx, my: v6);
  }
  else if ( use_clr_fmt == 2 )
  {
    _jxr_w_PredCBP444(image, channel: 0, tx, mx, my: v6);
    _jxr_w_PredCBP422(image, channel: 1, tx, mx, my: v6);
    _jxr_w_PredCBP422(image, channel: 2, tx, mx, my: v6);
  }
  else
  {
    v9 = 0;
    if ( image->num_channels != 0 )
    {
      do
        _jxr_w_PredCBP444(image, channel: v9++, tx, mx, my: v6);
      while ( v9 < image->num_channels );
    }
  }
}


// ========================================================================
// w_predict_up1_dclp
// EA  : 0x82921478
// RVA : 0x00921478
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall w_predict_up1_dclp(jxr_image *image, unsigned int tx, int ty, int mx)
{
  int v6; // r25
  int v7; // r26
  unsigned int v9; // r24
  int pred_dclp; // r8
  int v11; // r5
  macroblock_s **p_up1; // r11
  unsigned int v13; // r7
  unsigned int v14; // r9
  int v15; // r4
  int v16; // r9
  int use_clr_fmt; // r8
  int *v18; // r4
  unsigned int v19; // r9
  int *data; // r3
  int *v21; // r4
  unsigned __int8 v22; // r28
  jxr_tile_qp *v23; // r29
  unsigned __int8 v24; // r11
  jxr_tile_qp *v25; // r29
  int v26; // r28
  unsigned __int8 v27; // r11
  jxr_tile_qp *v28; // r29
  int v29; // r9
  int v30; // r8
  int v31; // r29
  int v32; // r11

  v6 = image->cur_my + 1;
  v7 = ty;
  if ( v6 == image->tile_row_height[ty] )
  {
    v6 = 0;
    v7 = ty + 1;
  }
  v9 = w_calculate_mbdc_mode(image, tx, mx, my: v6);
  v11 = 0;
  if ( image->num_channels != 0 )
  {
    p_up1 = &image->strip[0].up1;
    while ( 1 )
    {
      v13 = mx <= 0 ? 0 : *(*p_up1)[image->tile_column_position[tx] - 1 + mx].pred_dclp;
      v14 = image->tile_column_position[tx] + mx;
      v15 = *(*p_up1)[v14].data;
      pred_dclp = (int)(*p_up1)[v14].pred_dclp;
      v16 = *p_up1[1][v14].pred_dclp;
      *(_DWORD *)pred_dclp = v15;
      if ( v9 == 0 )
        break;
      if ( v9 == 1 )
      {
        data = (*p_up1)[image->tile_column_position[tx] + mx].data;
        pred_dclp = *data;
        *data -= v16;
      }
      else if ( v9 < 3 )
      {
        if ( v11 <= 0 || (use_clr_fmt = image->use_clr_fmt) != 1 && use_clr_fmt != 2 )
        {
          v13 = ((int)(v16 + v13) >> 1) | (v16 + v13) & 0x80000000;
          v19 = image->tile_column_position[tx];
LABEL_18:
          v21 = (*p_up1)[v19 + mx].data;
          pred_dclp = *v21 - v13;
          *v21 = pred_dclp;
          goto LABEL_19;
        }
        pred_dclp = (int)*p_up1;
        v18 = (*p_up1)[image->tile_column_position[tx] + mx].data;
        *v18 -= ((int)(v16 + v13 + 1) >> 1) | (v16 + v13 + 1) & 0x80000000;
      }
LABEL_19:
      ++v11;
      p_up1 += 7;
      if ( v11 >= image->num_channels )
        goto LABEL_20;
    }
    v19 = image->tile_column_position[tx];
    goto LABEL_18;
  }
LABEL_20:
  if ( (*((_DWORD *)image + 26) & 0x10000000) != 0 )
  {
    v22 = 0;
  }
  else
  {
    v23 = &image->tile_quant[(image->tile_rows + 1) * v7 + tx];
    pred_dclp = (int)v23->lp_map;
    if ( pred_dclp != 0 )
      v22 = v23->lp_map[jxr_get_TILE_WIDTH(image, column: tx) * v6 + mx];
    else
      v22 = 0;
  }
  if ( v9 != 0 )
  {
    if ( v9 == 1 )
    {
      if ( (*((_DWORD *)image + 26) & 0x10000000) != 0 )
      {
        v27 = 0;
      }
      else
      {
        v28 = &image->tile_quant[(image->tile_rows + 1) * v7 + tx];
        if ( v28->lp_map != nullptr )
          v27 = v28->lp_map[jxr_get_TILE_WIDTH(image, column: tx) * (v6 - 1) + mx];
        else
          v27 = 0;
      }
      pred_dclp = _cntlzw(v27 - v22);
      v26 = ((pred_dclp & 0x20) == 0) + 1;
    }
    else
    {
      v26 = 2;
    }
  }
  else
  {
    if ( (*((_DWORD *)image + 26) & 0x10000000) != 0 )
    {
      v24 = 0;
    }
    else
    {
      v25 = &image->tile_quant[(image->tile_rows + 1) * v7 + tx];
      if ( v25->lp_map != nullptr )
        v24 = v25->lp_map[jxr_get_TILE_WIDTH(image, column: tx) * v6 - 1 + mx];
      else
        v24 = 0;
    }
    pred_dclp = 2;
    v26 = v24 == v22 ? 0 : 2;
  }
  w_predict_lp444(image, tx, mx, my: 0, ch: v26, mblp_mode: pred_dclp);
  v31 = 1;
  if ( image->num_channels > 1u )
  {
    do
    {
      v32 = image->use_clr_fmt;
      if ( v32 == 1 )
      {
        w_predict_lp420(image, tx, mx, my: v31, ch: v26, mblp_mode: v30);
      }
      else if ( v32 == 2 )
      {
        w_predict_lp422(image, tx, mx, my: v31, ch: v26, mblp_mode: v9, mbdc_mode: v29);
      }
      else
      {
        w_predict_lp444(image, tx, mx, my: v31, ch: v26, mblp_mode: v30);
      }
      ++v31;
    }
    while ( v31 < image->num_channels );
  }
}


// ========================================================================
// wtransform_mb_strip
// EA  : 0x82921850
// RVA : 0x00921850
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall wtransform_mb_strip(jxr_image *image, unsigned int ty)
{
  unsigned int v4; // r29
  signed int v5; // r25
  unsigned int use_clr_fmt; // r11
  int v7; // r30
  int v8; // r30
  signed int v9; // r26
  unsigned int v10; // r11
  int v11; // r30
  int v12; // r30
  signed int v13; // r27
  int v14; // r28
  int i; // r30
  macroblock_s *v16; // r29
  int v17; // r11
  int num_channels; // r26
  signed int v19; // r27
  int v20; // r25
  signed int j; // r29
  int v22; // r30
  int k; // r28

  v4 = image->extended_height >> 4;
  v5 = image->tile_row_position[ty] + image->cur_my;
  if ( v5 >= -3 && v5 < (int)(v4 - 3) )
    scale_and_shuffle_up3(image);
  if ( v5 >= -2 && v5 < (int)(v4 - 2) )
  {
    if ( (image->header_flags1 & 3) != 0 )
    {
      first_prefilter444_up2(image, ch: 0, ty);
      use_clr_fmt = image->use_clr_fmt;
      if ( image->use_clr_fmt != 0 )
      {
        if ( use_clr_fmt == 1 )
        {
          first_prefilter420_up2(image, ch: 1, ty);
          first_prefilter420_up2(image, ch: 2, ty);
        }
        else if ( use_clr_fmt < 3 )
        {
          first_prefilter422_up2(image, ch: 1, ty);
          first_prefilter422_up2(image, ch: 2, ty);
        }
        else
        {
          v7 = 1;
          if ( image->num_channels > 1u )
          {
            do
              first_prefilter444_up2(image, ch: v7++, ty);
            while ( v7 < image->num_channels );
          }
        }
      }
    }
    v8 = 0;
    if ( image->num_channels != 0 )
    {
      do
        PCT_stage1_up2(image, ch: v8++, ty);
      while ( v8 < image->num_channels );
    }
    if ( image->lwf_test == 0 )
      image->lwf_test = _jxr_read_lwf_test_flag();
  }
  if ( v5 >= -1 )
  {
    v9 = v4 - 1;
    if ( v5 < (int)(v4 - 1) )
    {
      if ( (image->header_flags1 & 3u) >= 2 )
      {
        second_prefilter444_up1(image, ch: 0, ty);
        v10 = image->use_clr_fmt;
        if ( image->use_clr_fmt != 0 )
        {
          if ( v10 == 1 )
          {
            second_prefilter420_up1(image, ch: 1, ty);
            second_prefilter420_up1(image, ch: 2, ty);
          }
          else if ( v10 < 3 )
          {
            second_prefilter422_up1(image, ch: 1, ty);
            second_prefilter422_up1(image, ch: 2, ty);
          }
          else
          {
            v11 = 1;
            if ( image->num_channels > 1u )
            {
              do
                second_prefilter444_up1(image, ch: v11++, ty);
              while ( v11 < image->num_channels );
            }
          }
        }
      }
      v12 = 0;
      if ( image->num_channels != 0 )
      {
        do
          PCT_stage2_up1(image, ch: v12++, ty);
        while ( v12 < image->num_channels );
      }
      if ( image->lwf_test == 0 )
        image->lwf_test = _jxr_read_lwf_test_flag();
      if ( v5 < v9 )
      {
        v13 = 0;
        if ( (int)image->tile_columns > 0 )
        {
          v14 = 0;
          do
          {
            for ( i = 0; i < (signed int)image->tile_column_width[v14]; ++i )
            {
              v16 = &image->strip[0].up1[image->tile_column_position[v14] + i];
              *((_DWORD *)v16 + 2) = (w_calculate_mbhp_mode_up1(image, tx: v13, mx: i) << 13) & 0xE000
                                   | *((_DWORD *)v16 + 2) & 0xFFFF1FFF;
              w_predict_up1_dclp(image, tx: v13, ty, mx: i);
            }
            ++v13;
            ++v14;
          }
          while ( v13 < (signed int)image->tile_columns );
        }
        if ( v5 < v9 )
        {
          v17 = image->use_clr_fmt;
          num_channels = image->num_channels;
          if ( v17 == 1 || v17 == 2 )
            num_channels = 1;
          v19 = 0;
          if ( (int)image->tile_columns > 0 )
          {
            v20 = 0;
            do
            {
              if ( image->tile_columns > 1 )
                jxr_w_load_hpcbp_state(image, tx: v19);
              for ( j = 0; j < (signed int)image->tile_column_width[v20]; ++j )
              {
                v22 = 0;
                for ( k = (__int16)*((_DWORD *)&image->strip[0].up1[image->tile_column_position[v20] + j] + 2) >> 13;
                      v22 < num_channels;
                      ++v22 )
                {
                  w_predict_up1_hp(image, ch: v22, tx: v19, mx: j, mbhp_pred_mode: k);
                }
                calculate_hpcbp_up1(image, tx: v19, ty, mx: j);
                w_PredCBP(image, tx: v19, ty, mx: j);
              }
              if ( image->tile_columns > 1 )
                jxr_w_store_hpcbp_state(image, tx: v19);
              ++v19;
              ++v20;
            }
            while ( v19 < (signed int)image->tile_columns );
          }
        }
      }
    }
  }
}


// ========================================================================
// ?_jxr_w_flush_rotate_mb_strip@@YAXPAUjxr_image@@HHHH@Z
// EA  : 0x82921C78
// RVA : 0x00921C78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_strip.cpp
// ========================================================================

void __fastcall _jxr_w_flush_rotate_mb_strip(jxr_image *image, int tx, unsigned int ty, int my, int read_new)
{
  unsigned int v8; // r27
  int v9; // r9
  int v10; // r28
  unsigned int v11; // r29
  unsigned int *tile_row_position; // r10
  int v13; // r11
  int v14; // r8
  int v15; // r30
  int cur_my; // r11
  jxr_image *alpha; // r3
  int v18; // r11
  int v19; // r11

  v8 = 0;
  if ( (image->header_flags1 & 0x40) != 0 )
    v8 = image->tile_row_position[ty];
  if ( my == 0 && image->cur_my >= 0 )
  {
    v9 = image->header_flags2 & 1;
    image->cur_my = -1;
    if ( v9 != 0 )
      image->alpha->cur_my = -1;
  }
  if ( tx != 0 || read_new != 1 )
  {
    v19 = image->cur_my + 1;
    image->cur_my = v19;
    wflush_collect_mb_strip_data(image, my: v19 + v8);
    if ( (image->header_flags2 & 1) != 0 )
      wflush_collect_mb_strip_data(image: image->alpha, my: ++image->alpha->cur_my + v8);
  }
  else if ( image->cur_my < my )
  {
    v10 = ty;
    do
    {
      v11 = image->extended_height >> 4;
      w_rotate_mb_strip(image);
      tile_row_position = image->tile_row_position;
      v13 = image->cur_my + 1;
      v14 = image->header_flags2 & 1;
      image->cur_my = v13;
      v15 = tile_row_position[v10] + v13;
      if ( v14 != 0 )
      {
        w_rotate_mb_strip(image: image->alpha);
        ++image->alpha->cur_my;
      }
      if ( v15 >= -4 && v15 < (int)(v11 - 4) )
        collect_and_scale_up4(image, ty);
      wtransform_mb_strip(image, ty);
      if ( (image->header_flags1 & 4) != 0 )
      {
        cur_my = image->cur_my;
        if ( cur_my >= 0 )
          wflush_to_tile_buffer(image, my: cur_my + v8);
      }
      if ( (image->header_flags2 & 1) != 0 )
      {
        wtransform_mb_strip(image: image->alpha, ty);
        alpha = image->alpha;
        if ( (alpha->header_flags1 & 4) != 0 )
        {
          v18 = alpha->cur_my;
          if ( v18 >= 0 )
            wflush_to_tile_buffer(image: alpha, my: v18 + v8);
        }
      }
    }
    while ( image->cur_my < my );
  }
}

