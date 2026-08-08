
// ========================================================================
// dequantize_up_dclp
// EA  : 0x8290B930
// RVA : 0x0090B930
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall dequantize_up_dclp(jxr_image *image, int use_my, int ch)
{
  unsigned int v5; // r24
  int v6; // r23
  int use_clr_fmt; // r11
  unsigned int tile_rows; // r5
  unsigned int v9; // r8
  unsigned int v10; // r7
  int v11; // r11
  unsigned int v12; // r10
  signed int tile_columns; // r11
  signed int v14; // r26
  int v15; // r29
  int v16; // r4
  int v17; // r25
  signed int v18; // r30
  char *v19; // r28
  int v20; // r27
  int v21; // r11
  int v22; // r4
  int v23; // r3
  _DWORD *v24; // r7
  int v25; // r11
  int v26; // ctr
  int v27; // r6

  v5 = 0;
  v6 = 16;
  if ( ch > 0 )
  {
    use_clr_fmt = image->use_clr_fmt;
    if ( use_clr_fmt == 2 )
    {
      v6 = 8;
    }
    else if ( use_clr_fmt == 1 )
    {
      v6 = 4;
    }
  }
  tile_rows = image->tile_rows;
  v9 = use_my - 1;
  v10 = 0;
  if ( tile_rows != 0 )
  {
    v11 = 0;
    while ( 1 )
    {
      v12 = image->tile_row_position[v11];
      if ( v9 >= v12 && v9 < image->tile_row_height[v11] + v12 )
        break;
      ++v10;
      ++v11;
      if ( v10 >= tile_rows )
        goto LABEL_13;
    }
    v5 = v10;
  }
LABEL_13:
  tile_columns = image->tile_columns;
  v14 = 0;
  if ( tile_columns > 0 )
  {
    v15 = 0;
    do
    {
      if ( (*((_DWORD *)image + 26) & 0x40000000) != 0 )
        v16 = image->dc_quant_ch[ch];
      else
        v16 = image->tile_quant[tile_columns * v5 + v14].dc_quant_ch[ch];
      v17 = _jxr_quant_map(image, x: v16, shift: 1);
      v18 = 0;
      if ( (int)image->tile_column_width[v15] > 0 )
      {
        v19 = (char *)image + 28 * ch;
        v20 = ch;
        do
        {
          v21 = *(unsigned __int8 *)(84 * (image->tile_column_position[v15] + v18) + *((_DWORD *)v19 + 34) + 8);
          if ( (*((_DWORD *)image + 26) & 0x10000000) != 0 )
            v22 = image->lp_quant_ch[v20][v21];
          else
            v22 = image->tile_quant[image->tile_columns * v5 + v14].lp_quant_ch[v20][v21];
          v23 = _jxr_quant_map(image, x: v22, shift: 1);
          v24 = *(_DWORD **)(84 * (image->tile_column_position[v15] + v18) + *((_DWORD *)v19 + 34));
          *v24 *= v17;
          v25 = 4;
          v26 = v6 - 1;
          do
          {
            v27 = *(_DWORD *)(84 * (image->tile_column_position[v15] + v18) + *((_DWORD *)v19 + 34));
            *(_DWORD *)(v25 + v27) *= v23;
            v25 += 4;
            --v26;
          }
          while ( v26 != 0 );
          ++v18;
        }
        while ( v18 < (signed int)image->tile_column_width[v15] );
      }
      tile_columns = image->tile_columns;
      ++v14;
      ++v15;
    }
    while ( v14 < tile_columns );
  }
}


// ========================================================================
// IPCT_level1_up1
// EA  : 0x8290BB50
// RVA : 0x0090BB50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall IPCT_level1_up1(jxr_image *image, int use_my, int ch)
{
  signed int v5; // r28
  char *v6; // r30
  int v7; // r31
  int use_clr_fmt; // r11

  dequantize_up_dclp(image, use_my, ch);
  v5 = 0;
  if ( image->extended_width >> 4 != 0 )
  {
    v6 = (char *)image + 28 * ch;
    v7 = 0;
    while ( ch > 0 )
    {
      use_clr_fmt = image->use_clr_fmt;
      if ( use_clr_fmt == 1 )
      {
        _jxr_2x2IPCT(coeff: *(int **)(v7 + *((_DWORD *)v6 + 34)));
        _jxr_InvPermute2pt(
          a: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 4),
          b: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 8));
      }
      else
      {
        if ( use_clr_fmt != 2 )
          break;
        _jxr_2ptT(a: *(int **)(v7 + *((_DWORD *)v6 + 34)), b: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 16));
        _jxr_2x2IPCT(coeff: *(int **)(v7 + *((_DWORD *)v6 + 34)));
        _jxr_2x2IPCT(coeff: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 16));
        _jxr_InvPermute2pt(
          a: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 4),
          b: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 8));
        _jxr_InvPermute2pt(
          a: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 20),
          b: (int *)(*(_DWORD *)(v7 + *((_DWORD *)v6 + 34)) + 24));
      }
LABEL_9:
      ++v5;
      v7 += 84;
      if ( v5 >= (signed int)(image->extended_width >> 4) )
        return;
    }
    _jxr_4x4IPCT(coeff: *(int **)(v7 + *((_DWORD *)v6 + 34)));
    goto LABEL_9;
  }
}


// ========================================================================
// overlap_level1_up2_444
// EA  : 0x8290BC50
// RVA : 0x0090BC50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall overlap_level1_up2_444(jxr_image *image, int use_my, int ch)
{
  unsigned int *tile_row_position; // r10
  unsigned int v4; // r25
  unsigned int *tile_row_height; // r9
  int v8; // r24
  int v9; // r11
  unsigned int v10; // r23
  signed int v11; // r22
  unsigned int v12; // r28
  unsigned int i; // r27
  unsigned int disableTileOverlapFlag; // r11
  macroblock_s *v15; // r11
  int *data; // r30
  int *v17; // r29
  int *v18; // r3
  int *v19; // r11
  unsigned int v20; // r28
  unsigned int j; // r27
  unsigned int v22; // r11
  macroblock_s *v23; // r11
  int *v24; // r29
  int *v25; // r30
  int *v26; // r11
  int *v27; // r11
  unsigned int v28; // r28
  unsigned int k; // r27
  unsigned int v30; // r9
  char *v31; // r11
  int *v32; // r30
  int *v33; // r29
  char *v34; // r11
  unsigned int v35; // r10
  int v36; // r9
  int **v37; // r11
  _DWORD *v38; // r8
  char *v39; // r11
  unsigned int v40; // r8
  int *v41; // r30
  int *v42; // r29
  int *v43; // [sp+8h] [-E8h]
  int *v44; // [sp+Ch] [-E4h]
  int *v45; // [sp+10h] [-E0h]
  int *v46; // [sp+14h] [-DCh]
  int *v47; // [sp+18h] [-D8h]
  int *v48; // [sp+1Ch] [-D4h]
  int *v49; // [sp+20h] [-D0h]
  int *v50; // [sp+24h] [-CCh]
  int v51; // [sp+28h] [-C8h]
  int v52; // [sp+2Ch] [-C4h]
  int v53; // [sp+30h] [-C0h]
  int v54; // [sp+34h] [-BCh]
  int v55; // [sp+38h] [-B8h]
  int v56; // [sp+3Ch] [-B4h]
  int v57; // [sp+40h] [-B0h]
  int v58; // [sp+44h] [-ACh]
  int v59; // [sp+48h] [-A8h]
  int v60; // [sp+4Ch] [-A4h]
  int v61; // [sp+50h] [-A0h]
  int v62; // [sp+58h] [-98h]
  int v63; // [sp+60h] [-90h]
  int v64; // [sp+68h] [-88h]
  int v65; // [sp+70h] [-80h]
  int v66; // [sp+78h] [-78h]
  int v67; // [sp+80h] [-70h]
  int v68; // [sp+88h] [-68h]

  tile_row_position = image->tile_row_position;
  v4 = use_my - 2;
  tile_row_height = image->tile_row_height;
  v8 = 0;
  if ( use_my - 2 > *tile_row_position + *tile_row_height - 1 )
  {
    v9 = 0;
    do
    {
      ++v9;
      ++v8;
    }
    while ( v4 > tile_row_height[v9] + tile_row_position[v9] - 1 );
  }
  v10 = 0;
  if ( image->tile_columns != 0 )
  {
    v11 = v4 + 1;
    do
    {
      if ( v4 == 0 || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] )
      {
        v12 = v10;
        for ( i = 0; i < image->tile_column_width[v12]; ++i )
        {
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v12] + i != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_15;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            continue;
          }
          if ( i != 0 )
          {
LABEL_15:
            v15 = &image->strip[ch].up2[image->tile_column_position[v12] + i];
            data = v15->data;
            v17 = v15[-1].data;
            _jxr_4OverlapFilter(a: v17 + 2, b: v17 + 3, c: v15->data, d: v15->data + 1);
            _jxr_4OverlapFilter(a: v17 + 6, b: v17 + 7, c: data + 4, d: data + 5);
          }
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v18 = image->strip[ch].up2[image->tile_column_position[v10]].data;
          _jxr_4OverlapFilter(a: v18, b: v18 + 1, c: v18 + 4, d: v18 + 5);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v19 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4OverlapFilter(a: v19 + 2, b: v19 + 3, c: v19 + 6, d: v19 + 7);
        }
      }
      if ( v11 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
      {
        v20 = v10;
        for ( j = 0; j < image->tile_column_width[v20]; ++j )
        {
          v22 = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v20] + j != 0 )
          {
            if ( v22 == 0 )
              goto LABEL_32;
          }
          else if ( v22 == 0 )
          {
            continue;
          }
          if ( j != 0 )
          {
LABEL_32:
            v23 = &image->strip[ch].up2[image->tile_column_position[v20] + j];
            v24 = v23->data;
            v25 = v23[-1].data;
            _jxr_4OverlapFilter(a: v25 + 10, b: v25 + 11, c: v23->data + 8, d: v23->data + 9);
            _jxr_4OverlapFilter(a: v25 + 14, b: v25 + 15, c: v24 + 12, d: v24 + 13);
          }
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v26 = image->strip[ch].up2[image->tile_column_position[v10]].data;
          _jxr_4OverlapFilter(a: v26 + 8, b: v26 + 9, c: v26 + 12, d: v26 + 13);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v27 = image->strip[ch].up2[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4OverlapFilter(a: v27 + 10, b: v27 + 11, c: v27 + 14, d: v27 + 15);
        }
      }
      v28 = v10;
      for ( k = 0; k < image->tile_column_width[v28]; ++k )
      {
        if ( v11 < (signed int)(image->extended_height >> 4) )
        {
          if ( v10 == 0 && k == 0 && image->disableTileOverlapFlag == 0
            || image->disableTileOverlapFlag != 0
            && k == 0
            && v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
          {
            v30 = image->tile_column_position[v10];
            v31 = (char *)image + 28 * ch;
            v32 = *(int **)(*((_DWORD *)v31 + 33) + 84 * v30);
            v33 = *(int **)(*((_DWORD *)v31 + 34) + 84 * v30);
            _jxr_4OverlapFilter(a: v32 + 8, b: v32 + 12, c: v33, d: v33 + 4);
            _jxr_4OverlapFilter(a: v32 + 9, b: v32 + 13, c: v33 + 1, d: v33 + 5);
          }
          if ( image->tile_column_position[v28] + k < (image->extended_width >> 4) - 1
            && image->disableTileOverlapFlag == 0
            || image->disableTileOverlapFlag != 0
            && k != image->tile_column_width[v28] - 1
            && v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
          {
            v34 = (char *)image + 28 * ch;
            v35 = 84 * (image->tile_column_position[v28] + k);
            v36 = *((_DWORD *)v34 + 33);
            v37 = (int **)(*((_DWORD *)v34 + 34) + v35);
            v38 = (_DWORD *)(v36 + v35);
            _jxr_4x4OverlapFilter(
              a: (int *)(*v38 + 40),
              b: (int *)(*v38 + 44),
              c: (int *)(v38[21] + 32),
              d: (int *)(v38[21] + 36),
              e: (int *)(*v38 + 56),
              f: (int *)(*v38 + 60),
              g: (int *)(v38[21] + 48),
              h: (int *)(v38[21] + 52),
              i: v43,
              j: v44,
              k: v45,
              l: v46,
              m: v47,
              n: v48,
              o: v49,
              p: v50,
              a17: v51,
              a18: v52,
              a19: v53,
              a20: v54,
              a21: v55,
              a22: v56,
              a23: v57,
              a24: v58,
              a25: v59,
              a26: v60,
              a27: v61,
              a28: *v37 + 2,
              a29: v62,
              a30: *v37 + 3,
              a31: v63,
              a32: v37[21],
              a33: v64,
              a34: v37[21] + 1,
              a35: v65,
              ia: *v37 + 6,
              a37: v66,
              ja: *v37 + 7,
              a39: v67,
              ka: v37[21] + 4,
              a41: v68,
              la: v37[21] + 5);
          }
          if ( image->tile_column_position[v28] + k == (image->extended_width >> 4) - 1
            && image->disableTileOverlapFlag == 0
            || image->disableTileOverlapFlag != 0
            && k == image->tile_column_width[v28] - 1
            && v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
          {
            v39 = (char *)image + 28 * ch;
            v40 = image->tile_column_position[v28] + image->tile_column_width[v28];
            v41 = *(int **)(*((_DWORD *)v39 + 34) + 84 * v40 - 84);
            v42 = *(int **)(*((_DWORD *)v39 + 33) + 84 * v40 - 84);
            _jxr_4OverlapFilter(a: v42 + 10, b: v42 + 14, c: v41 + 2, d: v41 + 6);
            _jxr_4OverlapFilter(a: v42 + 11, b: v42 + 15, c: v41 + 3, d: v41 + 7);
          }
        }
      }
      ++v10;
    }
    while ( v10 < image->tile_columns );
  }
}


// ========================================================================
// overlap_level1_up2_422
// EA  : 0x8290C288
// RVA : 0x0090C288
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall overlap_level1_up2_422(jxr_image *image, int use_my, int ch)
{
  unsigned int *tile_row_position; // r10
  unsigned int v4; // r26
  unsigned int *tile_row_height; // r9
  int v8; // r25
  int v9; // r11
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
  unsigned int i; // r30
  unsigned int disableTileOverlapFlag; // r11
  macroblock_s *v25; // r11
  unsigned int j; // r30
  unsigned int v27; // r11
  macroblock_s *v28; // r11
  int v29; // r29
  unsigned int v30; // r9
  unsigned int v31; // r11
  unsigned int v32; // r8
  unsigned int v33; // r11
  int v34; // r10
  unsigned int v35; // r11
  macroblock_s *v36; // r11
  unsigned int v37; // r7
  int v38; // r11
  int *v39; // r3
  int *v40; // r4
  unsigned int v41; // r7
  int v42; // r11
  int *v43; // r3
  int *v44; // r4

  tile_row_position = image->tile_row_position;
  v4 = use_my - 2;
  tile_row_height = image->tile_row_height;
  v8 = 0;
  if ( use_my - 2 > *tile_row_position + *tile_row_height - 1 )
  {
    v9 = 0;
    do
    {
      ++v9;
      ++v8;
    }
    while ( v4 > tile_row_height[v9] + tile_row_position[v9] - 1 );
  }
  if ( use_my == 2 || image->disableTileOverlapFlag != 0 && v4 == tile_row_position[v8] )
  {
    v10 = 0;
    if ( image->tile_columns != 0 )
    {
      v11 = 0;
      do
      {
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          data = image->strip[ch].up2[image->tile_column_position[v11]].data;
          *data -= data[1];
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v13 = &image->strip[ch].up2[image->tile_column_position[v11] + image->tile_column_width[v11]];
          v13[-1].data[1] -= *v13[-1].data;
        }
        ++v10;
        ++v11;
      }
      while ( v10 < image->tile_columns );
    }
  }
  v14 = v4 + 1;
  if ( v4 + 1 == image->extended_height >> 4
    || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] + image->tile_row_height[v8] - 1 )
  {
    v15 = 0;
    if ( image->tile_columns != 0 )
    {
      v16 = 0;
      do
      {
        if ( v15 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v17 = image->strip[ch].up2[image->tile_column_position[v16]].data;
          v17[6] -= v17[7];
        }
        if ( v15 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v18 = &image->strip[ch].up2[image->tile_column_position[v16] + image->tile_column_width[v16]];
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
        v21 = image->strip[ch].up2[image->tile_column_position[v20]].data;
        _jxr_2OverlapFilter(a: v21 + 2, b: v21 + 4);
      }
      if ( v20 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v22 = image->strip[ch].up2[image->tile_column_position[v20] - 1 + image->tile_column_width[v20]].data;
        _jxr_2OverlapFilter(a: v22 + 3, b: v22 + 5);
      }
      if ( v4 == 0 || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] )
      {
        for ( i = 0; i < image->tile_column_width[v20]; ++i )
        {
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v20] + i != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_44;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            continue;
          }
          if ( i != 0 )
          {
LABEL_44:
            v25 = &image->strip[ch].up2[image->tile_column_position[v20] + i];
            _jxr_2OverlapFilter(a: v25[-1].data + 1, b: v25->data);
          }
        }
      }
      if ( v14 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] + image->tile_row_height[v8] - 1 )
      {
        for ( j = 0; j < image->tile_column_width[v20]; ++j )
        {
          v27 = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v20] + j != 0 )
          {
            if ( v27 == 0 )
              goto LABEL_55;
          }
          else if ( v27 == 0 )
          {
            continue;
          }
          if ( j != 0 )
          {
LABEL_55:
            v28 = &image->strip[ch].up2[image->tile_column_position[v20] + j];
            _jxr_2OverlapFilter(a: v28[-1].data + 7, b: v28->data + 6);
          }
        }
      }
      v29 = 0;
      if ( image->tile_column_width[v20] != 0 )
        break;
LABEL_88:
      tile_columns = image->tile_columns;
      if ( ++v20 >= tile_columns )
        goto LABEL_89;
    }
    while ( 1 )
    {
      if ( v4 >= (image->extended_height >> 4) - 1 )
        goto LABEL_81;
      if ( v20 == 0 && v29 == 0 )
        break;
      if ( image->disableTileOverlapFlag != 0 && v29 == 0 )
        goto LABEL_65;
LABEL_67:
      v31 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v20] + v29 == (image->extended_width >> 4) - 1 )
      {
        if ( v31 == 0 )
          goto LABEL_73;
      }
      else if ( v31 == 0 )
      {
        goto LABEL_74;
      }
      if ( v29 == image->tile_column_width[v20] - 1
        && v4 != image->tile_row_position[v8] + image->tile_row_height[v8] - 1 )
      {
LABEL_73:
        v32 = image->tile_column_position[v20] + image->tile_column_width[v20];
        _jxr_2OverlapFilter(a: image->strip[ch].up2[v32 - 1].data + 7, b: image->strip[ch].up1[v32 - 1].data + 1);
      }
LABEL_74:
      v33 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v20] + v29 >= (image->extended_width >> 4) - 1 )
      {
        if ( v33 == 0 )
          goto LABEL_81;
      }
      else if ( v33 == 0 )
      {
        goto LABEL_80;
      }
      if ( v29 != image->tile_column_width[v20] - 1
        && v4 != image->tile_row_position[v8] + image->tile_row_height[v8] - 1 )
      {
LABEL_80:
        v34 = image->tile_column_position[v20] + v29;
        _jxr_2x2OverlapFilter(
          a: image->strip[ch].up2[v34].data + 7,
          b: image->strip[ch].up2[v34 + 1].data + 6,
          c: image->strip[ch].up1[v34].data + 1,
          d: image->strip[ch].up1[v34 + 1].data);
      }
LABEL_81:
      v35 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v20] + v29 >= (image->extended_width >> 4) - 1 )
      {
        if ( v35 == 0 )
          goto LABEL_87;
      }
      else if ( v35 == 0 )
      {
        goto LABEL_86;
      }
      if ( v29 != image->tile_column_width[v20] - 1 )
      {
LABEL_86:
        v36 = &image->strip[ch].up2[image->tile_column_position[v20] + v29];
        _jxr_2x2OverlapFilter(a: v36->data + 3, b: v36[1].data + 2, c: v36->data + 5, d: v36[1].data + 4);
      }
LABEL_87:
      if ( ++v29 >= image->tile_column_width[v20] )
        goto LABEL_88;
    }
    if ( image->disableTileOverlapFlag != 0 )
    {
LABEL_65:
      if ( v4 == image->tile_row_position[v8] + image->tile_row_height[v8] - 1 )
        goto LABEL_67;
    }
    v30 = image->tile_column_position[v20];
    _jxr_2OverlapFilter(a: image->strip[ch].up2[v30].data + 6, b: image->strip[ch].up1[v30].data);
    goto LABEL_67;
  }
LABEL_89:
  if ( v4 == 0 || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] )
  {
    v37 = 0;
    if ( tile_columns != 0 )
    {
      v38 = 0;
      do
      {
        if ( v37 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v39 = image->strip[ch].up2[image->tile_column_position[v38]].data;
          *v39 += v39[1];
        }
        if ( v37 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v40 = image->strip[ch].up2[image->tile_column_position[v38] - 1 + image->tile_column_width[v38]].data;
          v40[1] += *v40;
        }
        tile_columns = image->tile_columns;
        ++v37;
        ++v38;
      }
      while ( v37 < tile_columns );
    }
  }
  if ( v14 == image->extended_height >> 4
    || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] + image->tile_row_height[v8] - 1 )
  {
    v41 = 0;
    if ( tile_columns != 0 )
    {
      v42 = 0;
      do
      {
        if ( v41 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v43 = image->strip[ch].up2[image->tile_column_position[v42]].data;
          v43[6] += v43[7];
        }
        if ( v41 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v44 = image->strip[ch].up2[image->tile_column_position[v42] - 1 + image->tile_column_width[v42]].data;
          v44[7] += v44[6];
        }
        ++v41;
        ++v42;
      }
      while ( v41 < image->tile_columns );
    }
  }
}


// ========================================================================
// overlap_level1_up2_420
// EA  : 0x8290CBA8
// RVA : 0x0090CBA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall overlap_level1_up2_420(jxr_image *image, int use_my, int ch)
{
  unsigned int *tile_row_position; // r10
  unsigned int v4; // r26
  unsigned int *tile_row_height; // r9
  int v8; // r25
  int v9; // r11
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
  int v20; // r27
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

  tile_row_position = image->tile_row_position;
  v4 = use_my - 2;
  tile_row_height = image->tile_row_height;
  v8 = 0;
  if ( use_my - 2 > *tile_row_position + *tile_row_height - 1 )
  {
    v9 = 0;
    do
    {
      ++v9;
      ++v8;
    }
    while ( v4 > tile_row_height[v9] + tile_row_position[v9] - 1 );
  }
  if ( use_my == 2 || image->disableTileOverlapFlag != 0 && v4 == tile_row_position[v8] )
  {
    v10 = 0;
    if ( image->tile_columns != 0 )
    {
      v11 = 0;
      do
      {
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          data = image->strip[ch].up2[image->tile_column_position[v11]].data;
          *data -= data[1];
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v13 = &image->strip[ch].up2[image->tile_column_position[v11] + image->tile_column_width[v11]];
          v13[-1].data[1] -= *v13[-1].data;
        }
        ++v10;
        ++v11;
      }
      while ( v10 < image->tile_columns );
    }
  }
  v14 = v4 + 1;
  if ( v4 + 1 == image->extended_height >> 4
    || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
  {
    v15 = 0;
    if ( image->tile_columns != 0 )
    {
      v16 = 0;
      do
      {
        if ( v15 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v17 = image->strip[ch].up2[image->tile_column_position[v16]].data;
          v17[2] -= v17[3];
        }
        if ( v15 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v18 = image->strip[ch].up2[image->tile_column_position[v16] - 1 + image->tile_column_width[v16]].data;
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
      if ( v4 == 0 || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] )
      {
        v21 = v20;
        for ( i = 0; i < image->tile_column_width[v21]; ++i )
        {
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( image->tile_column_position[v21] + i != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_38;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            continue;
          }
          if ( i != 0 )
          {
LABEL_38:
            v24 = &image->strip[ch].up2[image->tile_column_position[v21] + i];
            _jxr_2OverlapFilter(a: v24[-1].data + 1, b: v24->data);
          }
        }
      }
      if ( v14 != image->extended_height >> 4
        && (image->disableTileOverlapFlag == 0 || v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1) )
      {
        v25 = v20;
        v26 = 0;
        if ( image->tile_column_width[v20] != 0 )
        {
          while ( v20 != 0 || v26 != 0 )
          {
            if ( image->disableTileOverlapFlag != 0 && v26 == 0 )
              goto LABEL_50;
LABEL_52:
            v27 = image->disableTileOverlapFlag;
            if ( image->tile_column_position[v25] + v26 == (image->extended_width >> 4) - 1 )
            {
              if ( v27 == 0 )
                goto LABEL_58;
            }
            else if ( v27 == 0 )
            {
              goto LABEL_59;
            }
            if ( v26 == image->tile_column_width[v25] - 1
              && v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
            {
LABEL_58:
              v28 = image->tile_column_position[v25] + image->tile_column_width[v25];
              _jxr_2OverlapFilter(a: image->strip[ch].up2[v28 - 1].data + 3, b: image->strip[ch].up1[v28 - 1].data + 1);
            }
LABEL_59:
            v29 = image->disableTileOverlapFlag;
            if ( image->tile_column_position[v25] + v26 < (image->extended_width >> 4) - 1 )
            {
              if ( v29 != 0 )
              {
LABEL_63:
                if ( v26 == image->tile_column_width[v25] - 1
                  || v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
                {
                  goto LABEL_66;
                }
              }
              v30 = image->tile_column_position[v25] + v26;
              _jxr_2x2OverlapFilter(
                a: image->strip[ch].up2[v30].data + 3,
                b: image->strip[ch].up2[v30 + 1].data + 2,
                c: image->strip[ch].up1[v30].data + 1,
                d: image->strip[ch].up1[v30 + 1].data);
              goto LABEL_66;
            }
            if ( v29 != 0 )
              goto LABEL_63;
LABEL_66:
            if ( ++v26 >= image->tile_column_width[v25] )
              goto LABEL_76;
          }
          if ( image->disableTileOverlapFlag != 0 )
          {
LABEL_50:
            if ( v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
              goto LABEL_52;
          }
          _jxr_2OverlapFilter(
            a: image->strip[ch].up2[image->tile_column_position[v25]].data + 2,
            b: image->strip[ch].up1[image->tile_column_position[v25]].data);
          goto LABEL_52;
        }
        goto LABEL_76;
      }
      v31 = v20;
      v32 = 0;
      if ( image->tile_column_width[v20] != 0 )
        break;
LABEL_76:
      tile_columns = image->tile_columns;
      if ( ++v20 >= tile_columns )
        goto LABEL_77;
    }
    while ( 1 )
    {
      v33 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v31] + v32 != 0 )
      {
        if ( v33 == 0 )
          goto LABEL_74;
      }
      else if ( v33 == 0 )
      {
        goto LABEL_75;
      }
      if ( v32 != 0 )
      {
LABEL_74:
        v34 = &image->strip[ch].up2[image->tile_column_position[v31] + v32];
        _jxr_2OverlapFilter(a: v34[-1].data + 3, b: v34->data + 2);
      }
LABEL_75:
      if ( ++v32 >= image->tile_column_width[v31] )
        goto LABEL_76;
    }
  }
LABEL_77:
  if ( v4 == 0 || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] )
  {
    v35 = 0;
    if ( tile_columns != 0 )
    {
      v36 = 0;
      do
      {
        if ( v35 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v37 = image->strip[ch].up2[image->tile_column_position[v36]].data;
          *v37 += v37[1];
        }
        if ( v35 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v38 = image->strip[ch].up2[image->tile_column_position[v36] - 1 + image->tile_column_width[v36]].data;
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
    || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
  {
    v39 = 0;
    if ( tile_columns != 0 )
    {
      v40 = 0;
      do
      {
        if ( v39 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v41 = image->strip[ch].up2[image->tile_column_position[v40]].data;
          v41[2] += v41[3];
        }
        if ( v39 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v42 = image->strip[ch].up2[image->tile_column_position[v40] - 1 + image->tile_column_width[v40]].data;
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
// overlap_level2_up3_444
// EA  : 0x8290D398
// RVA : 0x0090D398
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall overlap_level2_up3_444(jxr_image *image, int use_my, int ch)
{
  unsigned int *tile_row_position; // r10
  unsigned int v4; // r25
  unsigned int *tile_row_height; // r9
  int v6; // r24
  int v8; // r23
  int v9; // r11
  unsigned int v10; // r22
  int v11; // r31
  int *data; // r30
  int v13; // r31
  int *v14; // r30
  int *v15; // r29
  int *v16; // r28
  int *v17; // r27
  int *v18; // r26
  unsigned int v19; // r29
  unsigned int v20; // r28
  char *v21; // r27
  int *v22; // r31
  unsigned int *tile_column_position; // r7
  unsigned int disableTileOverlapFlag; // r10
  int *v25; // r30
  int *v26; // r3
  int *v27; // r11
  unsigned int v28; // r29
  unsigned int v29; // r28
  char *v30; // r27
  int *v31; // r31
  unsigned int *v32; // r7
  unsigned int v33; // r10
  int *v34; // r30
  int *v35; // r11
  int *v36; // r11
  unsigned int v37; // r15
  unsigned int v38; // r16
  char *v39; // r14
  int v40; // r26
  int v41; // r31
  int v42; // r24
  int v43; // r25
  int *v44; // r30
  int *v45; // r29
  int v46; // r23
  unsigned int v47; // r22
  int *v48; // r28
  int *v49; // r27
  unsigned int v50; // r10
  unsigned int v51; // r11
  int v52; // r11
  unsigned int v53; // r6
  int *v54; // r31
  int *v55; // r30
  int v56; // r28
  unsigned int v57; // r11
  unsigned int v58; // r11
  int *v59; // r5
  int *v60; // r11
  unsigned int v61; // r11
  int *v62; // [sp+8h] [-138h]
  int *v63; // [sp+8h] [-138h]
  int *v64; // [sp+8h] [-138h]
  int *v65; // [sp+8h] [-138h]
  int *v66; // [sp+8h] [-138h]
  int *v67; // [sp+Ch] [-134h]
  int *v68; // [sp+Ch] [-134h]
  int *v69; // [sp+Ch] [-134h]
  int *v70; // [sp+Ch] [-134h]
  int *v71; // [sp+Ch] [-134h]
  int *v72; // [sp+10h] [-130h]
  int *v73; // [sp+10h] [-130h]
  int *v74; // [sp+10h] [-130h]
  int *v75; // [sp+10h] [-130h]
  int *v76; // [sp+10h] [-130h]
  int *v77; // [sp+14h] [-12Ch]
  int *v78; // [sp+14h] [-12Ch]
  int *v79; // [sp+14h] [-12Ch]
  int *v80; // [sp+14h] [-12Ch]
  int *v81; // [sp+14h] [-12Ch]
  int *v82; // [sp+18h] [-128h]
  int *v83; // [sp+18h] [-128h]
  int *v84; // [sp+18h] [-128h]
  int *v85; // [sp+18h] [-128h]
  int *v86; // [sp+18h] [-128h]
  int *v87; // [sp+1Ch] [-124h]
  int *v88; // [sp+1Ch] [-124h]
  int *v89; // [sp+1Ch] [-124h]
  int *v90; // [sp+1Ch] [-124h]
  int *v91; // [sp+1Ch] [-124h]
  int *v92; // [sp+20h] [-120h]
  int *v93; // [sp+20h] [-120h]
  int *v94; // [sp+20h] [-120h]
  int *v95; // [sp+20h] [-120h]
  int *v96; // [sp+20h] [-120h]
  int *v97; // [sp+24h] [-11Ch]
  int *v98; // [sp+24h] [-11Ch]
  int *v99; // [sp+24h] [-11Ch]
  int *v100; // [sp+24h] [-11Ch]
  int *v101; // [sp+24h] [-11Ch]
  int v102; // [sp+28h] [-118h]
  int v103; // [sp+28h] [-118h]
  int v104; // [sp+28h] [-118h]
  int v105; // [sp+28h] [-118h]
  int v106; // [sp+28h] [-118h]
  int v107; // [sp+2Ch] [-114h]
  int v108; // [sp+2Ch] [-114h]
  int v109; // [sp+2Ch] [-114h]
  int v110; // [sp+2Ch] [-114h]
  int v111; // [sp+2Ch] [-114h]
  int v112; // [sp+30h] [-110h]
  int v113; // [sp+30h] [-110h]
  int v114; // [sp+30h] [-110h]
  int v115; // [sp+30h] [-110h]
  int v116; // [sp+30h] [-110h]
  int v117; // [sp+34h] [-10Ch]
  int v118; // [sp+34h] [-10Ch]
  int v119; // [sp+34h] [-10Ch]
  int v120; // [sp+34h] [-10Ch]
  int v121; // [sp+34h] [-10Ch]
  int v122; // [sp+38h] [-108h]
  int v123; // [sp+38h] [-108h]
  int v124; // [sp+38h] [-108h]
  int v125; // [sp+38h] [-108h]
  int v126; // [sp+38h] [-108h]
  int v127; // [sp+3Ch] [-104h]
  int v128; // [sp+3Ch] [-104h]
  int v129; // [sp+3Ch] [-104h]
  int v130; // [sp+3Ch] [-104h]
  int v131; // [sp+3Ch] [-104h]
  int v132; // [sp+40h] [-100h]
  int v133; // [sp+40h] [-100h]
  int v134; // [sp+40h] [-100h]
  int v135; // [sp+40h] [-100h]
  int v136; // [sp+40h] [-100h]
  int v137; // [sp+44h] [-FCh]
  int v138; // [sp+44h] [-FCh]
  int v139; // [sp+44h] [-FCh]
  int v140; // [sp+44h] [-FCh]
  int v141; // [sp+44h] [-FCh]
  int v142; // [sp+48h] [-F8h]
  int v143; // [sp+48h] [-F8h]
  int v144; // [sp+48h] [-F8h]
  int v145; // [sp+48h] [-F8h]
  int v146; // [sp+48h] [-F8h]
  int v147; // [sp+4Ch] [-F4h]
  int v148; // [sp+4Ch] [-F4h]
  int v149; // [sp+4Ch] [-F4h]
  int v150; // [sp+4Ch] [-F4h]
  int v151; // [sp+4Ch] [-F4h]
  int v152; // [sp+50h] [-F0h]
  int v153; // [sp+50h] [-F0h]
  int v154; // [sp+50h] [-F0h]
  int v155; // [sp+50h] [-F0h]
  int v156; // [sp+50h] [-F0h]
  int v157; // [sp+58h] [-E8h]
  int v158; // [sp+58h] [-E8h]
  int v159; // [sp+58h] [-E8h]
  int v160; // [sp+58h] [-E8h]
  int v161; // [sp+58h] [-E8h]
  int v162; // [sp+60h] [-E0h]
  int v163; // [sp+60h] [-E0h]
  int v164; // [sp+60h] [-E0h]
  int v165; // [sp+60h] [-E0h]
  int v166; // [sp+60h] [-E0h]
  int v167; // [sp+68h] [-D8h]
  int v168; // [sp+68h] [-D8h]
  int v169; // [sp+68h] [-D8h]
  int v170; // [sp+68h] [-D8h]
  int v171; // [sp+68h] [-D8h]
  int v172; // [sp+70h] [-D0h]
  int v173; // [sp+70h] [-D0h]
  int v174; // [sp+70h] [-D0h]
  int v175; // [sp+70h] [-D0h]
  int v176; // [sp+70h] [-D0h]
  int v177; // [sp+78h] [-C8h]
  int v178; // [sp+78h] [-C8h]
  int v179; // [sp+78h] [-C8h]
  int v180; // [sp+78h] [-C8h]
  int v181; // [sp+78h] [-C8h]
  int v182; // [sp+80h] [-C0h]
  int v183; // [sp+80h] [-C0h]
  int v184; // [sp+80h] [-C0h]
  int v185; // [sp+80h] [-C0h]
  int v186; // [sp+80h] [-C0h]
  int v187; // [sp+88h] [-B8h]
  int v188; // [sp+88h] [-B8h]
  int v189; // [sp+88h] [-B8h]
  int v190; // [sp+88h] [-B8h]
  int v191; // [sp+88h] [-B8h]
  int v192; // [sp+90h] [-B0h]
  unsigned int v193; // [sp+94h] [-ACh]
  unsigned int v194; // [sp+98h] [-A8h]

  tile_row_position = image->tile_row_position;
  v4 = use_my - 3;
  tile_row_height = image->tile_row_height;
  v6 = 0;
  v8 = ch;
  v194 = use_my - 3;
  v192 = 0;
  if ( use_my - 3 > *tile_row_position + *tile_row_height - 1 )
  {
    v9 = 0;
    do
    {
      ++v9;
      ++v6;
    }
    while ( v4 > tile_row_height[v9] + tile_row_position[v9] - 1 );
    v192 = v6;
  }
  v10 = 0;
  v193 = 0;
  if ( image->tile_columns == 0 )
    return;
  while ( 2 )
  {
    if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
    {
      v11 = 4;
      data = image->strip[v8].up3[image->tile_column_position[v10]].data;
      do
      {
        _jxr_4OverlapFilter(
          a: &data[4 * ((4 * (v11 - 2)) & 0xFFFFFFF0) + 4 * (((_BYTE)v11 - 2) & 3)],
          b: &data[64 * ((v11 - 1) / 4) + 4 * ((v11 - 1) % 4)],
          c: &data[64 * (v11 / 4) + 4 * (v11 % 4)],
          d: &data[64 * ((v11 + 1) / 4) + 4 * ((v11 + 1) % 4)]);
        _jxr_4OverlapFilter(
          a: &data[4 * ((4 * (v11 - 2)) & 0xFFFFFFF0) + 1 + 4 * (((_BYTE)v11 - 2) & 3)],
          b: &data[64 * ((v11 - 1) / 4) + 1 + 4 * ((v11 - 1) % 4)],
          c: &data[64 * (v11 / 4) + 1 + 4 * (v11 % 4)],
          d: &data[64 * ((v11 + 1) / 4) + 1 + 4 * ((v11 + 1) % 4)]);
        v11 += 4;
      }
      while ( v11 - 2 < 14 );
    }
    if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
    {
      v13 = 4;
      v14 = image->strip[v8].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
      do
      {
        v15 = &v14[64 * ((v13 + 1) / 4) + 4 * ((v13 + 1) % 4)];
        v16 = &v14[64 * (v13 / 4) + 4 * (v13 % 4)];
        v17 = &v14[64 * ((v13 - 1) / 4) + 4 * ((v13 - 1) % 4)];
        v18 = &v14[4 * ((4 * (v13 - 2)) & 0xFFFFFFF0) + 4 * (((_BYTE)v13 - 2) & 3)];
        _jxr_4OverlapFilter(a: v18 + 50, b: v17 + 50, c: v16 + 50, d: v15 + 50);
        _jxr_4OverlapFilter(a: v18 + 51, b: v17 + 51, c: v16 + 51, d: v15 + 51);
        v13 += 4;
      }
      while ( v13 - 2 < 14 );
    }
    if ( v4 == 0 || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v6] )
    {
      v19 = v10;
      v20 = 0;
      if ( image->tile_column_width[v10] != 0 )
      {
        v21 = (char *)image + 28 * v8;
        do
        {
          v22 = *(int **)(84 * (image->tile_column_position[v19] + v20) + *((_DWORD *)v21 + 32));
          _jxr_4OverlapFilter(a: v22 + 2, b: v22 + 3, c: v22 + 16, d: v22 + 17);
          _jxr_4OverlapFilter(a: v22 + 18, b: v22 + 19, c: v22 + 32, d: v22 + 33);
          _jxr_4OverlapFilter(a: v22 + 34, b: v22 + 35, c: v22 + 48, d: v22 + 49);
          _jxr_4OverlapFilter(a: v22 + 6, b: v22 + 7, c: v22 + 20, d: v22 + 21);
          _jxr_4OverlapFilter(a: v22 + 22, b: v22 + 23, c: v22 + 36, d: v22 + 37);
          _jxr_4OverlapFilter(a: v22 + 38, b: v22 + 39, c: v22 + 52, d: v22 + 53);
          tile_column_position = image->tile_column_position;
          disableTileOverlapFlag = image->disableTileOverlapFlag;
          if ( tile_column_position[v19] + v20 != 0 )
          {
            if ( disableTileOverlapFlag == 0 )
              goto LABEL_26;
          }
          else if ( disableTileOverlapFlag == 0 )
          {
            goto LABEL_27;
          }
          if ( v20 != 0 )
          {
LABEL_26:
            v25 = *(int **)(84 * (tile_column_position[v19] + v20) + *((_DWORD *)v21 + 32) - 84);
            _jxr_4OverlapFilter(a: v25 + 50, b: v25 + 51, c: v22, d: v22 + 1);
            _jxr_4OverlapFilter(a: v25 + 54, b: v25 + 55, c: v22 + 4, d: v22 + 5);
          }
LABEL_27:
          ++v20;
        }
        while ( v20 < image->tile_column_width[v10] );
      }
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        v26 = image->strip[v8].up3[image->tile_column_position[v10]].data;
        _jxr_4OverlapFilter(a: v26, b: v26 + 1, c: v26 + 4, d: v26 + 5);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v27 = image->strip[v8].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4OverlapFilter(a: v27 + 51, b: v27 + 50, c: v27 + 55, d: v27 + 54);
      }
    }
    if ( v4 + 1 == image->extended_height >> 4
      || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v6] + image->tile_row_height[v6] - 1 )
    {
      v28 = v10;
      v29 = 0;
      if ( image->tile_column_width[v10] != 0 )
      {
        v30 = (char *)image + 28 * v8;
        do
        {
          v31 = *(int **)(84 * (image->tile_column_position[v28] + v29) + *((_DWORD *)v30 + 32));
          _jxr_4OverlapFilter(a: v31 + 202, b: v31 + 203, c: v31 + 216, d: v31 + 217);
          _jxr_4OverlapFilter(a: v31 + 218, b: v31 + 219, c: v31 + 232, d: v31 + 233);
          _jxr_4OverlapFilter(a: v31 + 234, b: v31 + 235, c: v31 + 248, d: v31 + 249);
          _jxr_4OverlapFilter(a: v31 + 206, b: v31 + 207, c: v31 + 220, d: v31 + 221);
          _jxr_4OverlapFilter(a: v31 + 222, b: v31 + 223, c: v31 + 236, d: v31 + 237);
          _jxr_4OverlapFilter(a: v31 + 238, b: v31 + 239, c: v31 + 252, d: v31 + 253);
          v32 = image->tile_column_position;
          v33 = image->disableTileOverlapFlag;
          if ( v32[v28] + v29 != 0 )
          {
            if ( v33 == 0 )
              goto LABEL_44;
          }
          else if ( v33 == 0 )
          {
            goto LABEL_45;
          }
          if ( v29 != 0 )
          {
LABEL_44:
            v34 = *(int **)(84 * (v32[v28] + v29) + *((_DWORD *)v30 + 32) - 84);
            _jxr_4OverlapFilter(a: v34 + 250, b: v34 + 251, c: v31 + 200, d: v31 + 201);
            _jxr_4OverlapFilter(a: v34 + 254, b: v34 + 255, c: v31 + 204, d: v31 + 205);
          }
LABEL_45:
          ++v29;
        }
        while ( v29 < image->tile_column_width[v10] );
      }
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        v35 = image->strip[v8].up3[image->tile_column_position[v10]].data;
        _jxr_4OverlapFilter(a: v35 + 204, b: v35 + 205, c: v35 + 200, d: v35 + 201);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v36 = image->strip[v8].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4OverlapFilter(a: v36 + 255, b: v36 + 254, c: v36 + 251, d: v36 + 250);
      }
    }
    v37 = v10;
    v38 = 0;
    if ( image->tile_column_width[v10] == 0 )
      goto LABEL_89;
    v39 = (char *)image + 28 * ch;
    do
    {
      v40 = 4;
      do
      {
        v41 = *(_DWORD *)(84 * (image->tile_column_position[v37] + v38) + *((_DWORD *)v39 + 32));
        v42 = 16 * (v40 / 4) + v40 % 4;
        v43 = 16 * ((v40 + 1) / 4) + (v40 + 1) % 4;
        v44 = (int *)(v41 + 16 * v43);
        v45 = (int *)(16 * v42 + v41);
        v46 = 16 * ((v40 - 1) / 4) + (v40 - 1) % 4;
        v47 = ((4 * (v40 - 2)) & 0xFFFFFFF0) + (((_BYTE)v40 - 2) & 3);
        v48 = (int *)(16 * v46 + v41);
        v49 = (int *)(16 * v47 + v41);
        _jxr_4x4OverlapFilter(
          a: v49 + 2,
          b: v49 + 3,
          c: (int *)(16 * (v47 + 4) + v41),
          d: v49 + 17,
          e: v48 + 2,
          f: v48 + 3,
          g: (int *)(16 * (v46 + 4) + v41),
          h: v48 + 17,
          i: v62,
          j: v67,
          k: v72,
          l: v77,
          m: v82,
          n: v87,
          o: v92,
          p: v97,
          a17: v102,
          a18: v107,
          a19: v112,
          a20: v117,
          a21: v122,
          a22: v127,
          a23: v132,
          a24: v137,
          a25: v142,
          a26: v147,
          a27: v152,
          a28: v45 + 2,
          a29: v157,
          a30: v45 + 3,
          a31: v162,
          a32: (int *)(16 * (v42 + 4) + v41),
          a33: v167,
          a34: v45 + 17,
          a35: v172,
          ia: v44 + 2,
          a37: v177,
          ja: v44 + 3,
          a39: v182,
          ka: (int *)(16 * (v43 + 4) + v41),
          a41: v187,
          la: v44 + 17);
        _jxr_4x4OverlapFilter(
          a: v49 + 18,
          b: v49 + 19,
          c: (int *)(16 * (v47 + 8) + v41),
          d: v49 + 33,
          e: v48 + 18,
          f: v48 + 19,
          g: (int *)(16 * (v46 + 8) + v41),
          h: v48 + 33,
          i: v63,
          j: v68,
          k: v73,
          l: v78,
          m: v83,
          n: v88,
          o: v93,
          p: v98,
          a17: v103,
          a18: v108,
          a19: v113,
          a20: v118,
          a21: v123,
          a22: v128,
          a23: v133,
          a24: v138,
          a25: v143,
          a26: v148,
          a27: v153,
          a28: v45 + 18,
          a29: v158,
          a30: v45 + 19,
          a31: v163,
          a32: (int *)(16 * (v42 + 8) + v41),
          a33: v168,
          a34: v45 + 33,
          a35: v173,
          ia: v44 + 18,
          a37: v178,
          ja: v44 + 19,
          a39: v183,
          ka: (int *)(16 * (v43 + 8) + v41),
          a41: v188,
          la: v44 + 33);
        _jxr_4x4OverlapFilter(
          a: v49 + 34,
          b: v49 + 35,
          c: (int *)(16 * (v47 + 12) + v41),
          d: v49 + 49,
          e: v48 + 34,
          f: v48 + 35,
          g: (int *)(16 * (v46 + 12) + v41),
          h: v48 + 49,
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
          a28: v45 + 34,
          a29: v159,
          a30: v45 + 35,
          a31: v164,
          a32: (int *)(16 * (v42 + 12) + v41),
          a33: v169,
          a34: v45 + 49,
          a35: v174,
          ia: v44 + 34,
          a37: v179,
          ja: v44 + 35,
          a39: v184,
          ka: (int *)(16 * (v43 + 12) + v41),
          a41: v189,
          la: v44 + 49);
        v50 = image->disableTileOverlapFlag;
        v51 = image->tile_column_position[v37] + v38;
        if ( v51 >= (image->extended_width >> 4) - 1 )
        {
          if ( v50 == 0 )
            goto LABEL_61;
LABEL_59:
          if ( v38 == image->tile_column_width[v37] - 1 )
            goto LABEL_61;
          goto LABEL_60;
        }
        if ( v50 != 0 )
          goto LABEL_59;
LABEL_60:
        v52 = *(_DWORD *)(84 * (v51 + 1) + *((_DWORD *)v39 + 32));
        _jxr_4x4OverlapFilter(
          a: v49 + 50,
          b: v49 + 51,
          c: (int *)(16 * v47 + v52),
          d: (int *)(16 * v47 + v52 + 4),
          e: v48 + 50,
          f: v48 + 51,
          g: (int *)(16 * v46 + v52),
          h: (int *)(16 * v46 + v52 + 4),
          i: v62,
          j: v67,
          k: v72,
          l: v77,
          m: v82,
          n: v87,
          o: v92,
          p: v97,
          a17: v102,
          a18: v107,
          a19: v112,
          a20: v117,
          a21: v122,
          a22: v127,
          a23: v132,
          a24: v137,
          a25: v142,
          a26: v147,
          a27: v152,
          a28: v45 + 50,
          a29: v157,
          a30: v45 + 51,
          a31: v162,
          a32: (int *)(16 * v42 + v52),
          a33: v167,
          a34: (int *)(16 * v42 + v52 + 4),
          a35: v172,
          ia: v44 + 50,
          a37: v177,
          ja: v44 + 51,
          a39: v182,
          ka: (int *)(v52 + 16 * v43),
          a41: v187,
          la: (int *)(v52 + 16 * v43 + 4));
LABEL_61:
        v40 += 4;
      }
      while ( v40 - 2 < 14 );
      if ( (signed int)(v194 + 1) < (signed int)(image->extended_height >> 4) )
      {
        v53 = 84 * (image->tile_column_position[v37] + v38);
        v54 = *(int **)(v53 + *((_DWORD *)v39 + 32));
        v55 = *(int **)(v53 + *((_DWORD *)v39 + 33));
        if ( v193 != 0 || v38 != 0 )
        {
          if ( image->disableTileOverlapFlag != 0 )
          {
            if ( v38 == 0 )
              goto LABEL_69;
            goto LABEL_71;
          }
LABEL_73:
          _jxr_4x4OverlapFilter(
            a: v54 + 202,
            b: v54 + 203,
            c: v54 + 216,
            d: v54 + 217,
            e: v54 + 206,
            f: v54 + 207,
            g: v54 + 220,
            h: v54 + 221,
            i: v62,
            j: v67,
            k: v72,
            l: v77,
            m: v82,
            n: v87,
            o: v92,
            p: v97,
            a17: v102,
            a18: v107,
            a19: v112,
            a20: v117,
            a21: v122,
            a22: v127,
            a23: v132,
            a24: v137,
            a25: v142,
            a26: v147,
            a27: v152,
            a28: v55 + 2,
            a29: v157,
            a30: v55 + 3,
            a31: v162,
            a32: v55 + 16,
            a33: v167,
            a34: v55 + 17,
            a35: v172,
            ia: v55 + 6,
            a37: v177,
            ja: v55 + 7,
            a39: v182,
            ka: v55 + 20,
            a41: v187,
            la: v55 + 21);
          _jxr_4x4OverlapFilter(
            a: v54 + 218,
            b: v54 + 219,
            c: v54 + 232,
            d: v54 + 233,
            e: v54 + 222,
            f: v54 + 223,
            g: v54 + 236,
            h: v54 + 237,
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
            a28: v55 + 18,
            a29: v160,
            a30: v55 + 19,
            a31: v165,
            a32: v55 + 32,
            a33: v170,
            a34: v55 + 33,
            a35: v175,
            ia: v55 + 22,
            a37: v180,
            ja: v55 + 23,
            a39: v185,
            ka: v55 + 36,
            a41: v190,
            la: v55 + 37);
          _jxr_4x4OverlapFilter(
            a: v54 + 234,
            b: v54 + 235,
            c: v54 + 248,
            d: v54 + 249,
            e: v54 + 238,
            f: v54 + 239,
            g: v54 + 252,
            h: v54 + 253,
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
            a28: v55 + 34,
            a29: v161,
            a30: v55 + 35,
            a31: v166,
            a32: v55 + 48,
            a33: v171,
            a34: v55 + 49,
            a35: v176,
            ia: v55 + 38,
            a37: v181,
            ja: v55 + 39,
            a39: v186,
            ka: v55 + 52,
            a41: v191,
            la: v55 + 53);
          v56 = v192;
        }
        else
        {
          if ( image->disableTileOverlapFlag == 0 )
            goto LABEL_70;
LABEL_69:
          if ( v194 != image->tile_row_position[v192] + image->tile_row_height[v192] - 1 )
          {
LABEL_70:
            _jxr_4OverlapFilter(a: v54 + 200, b: v54 + 204, c: v55, d: v55 + 4);
            _jxr_4OverlapFilter(a: v54 + 201, b: v54 + 205, c: v55 + 1, d: v55 + 5);
          }
LABEL_71:
          if ( image->disableTileOverlapFlag == 0 )
            goto LABEL_73;
          v56 = v192;
          if ( v194 != image->tile_row_position[v192] + image->tile_row_height[v192] - 1 )
            goto LABEL_73;
        }
        v57 = image->disableTileOverlapFlag;
        if ( image->tile_column_position[v37] + v38 >= (image->extended_width >> 4) - 1 )
        {
          if ( v57 != 0 )
          {
LABEL_78:
            if ( v38 != image->tile_column_width[v37] - 1
              && v194 != image->tile_row_position[v56] + image->tile_row_height[v56] - 1 )
            {
              goto LABEL_80;
            }
          }
        }
        else
        {
          if ( v57 != 0 )
            goto LABEL_78;
LABEL_80:
          v58 = 84 * (image->tile_column_position[v37] + v38);
          v59 = *(int **)(v58 + *((_DWORD *)v39 + 33) + 84);
          v60 = *(int **)(v58 + *((_DWORD *)v39 + 32) + 84);
          _jxr_4x4OverlapFilter(
            a: v54 + 250,
            b: v54 + 251,
            c: v60 + 200,
            d: v60 + 201,
            e: v54 + 254,
            f: v54 + 255,
            g: v60 + 204,
            h: v60 + 205,
            i: v62,
            j: v67,
            k: v72,
            l: v77,
            m: v82,
            n: v87,
            o: v92,
            p: v97,
            a17: v102,
            a18: v107,
            a19: v112,
            a20: v117,
            a21: v122,
            a22: v127,
            a23: v132,
            a24: v137,
            a25: v142,
            a26: v147,
            a27: v152,
            a28: v55 + 50,
            a29: v157,
            a30: v55 + 51,
            a31: v162,
            a32: v59,
            a33: v167,
            a34: v59 + 1,
            a35: v172,
            ia: v55 + 54,
            a37: v177,
            ja: v55 + 55,
            a39: v182,
            ka: v59 + 4,
            a41: v187,
            la: v59 + 5);
        }
        v61 = image->disableTileOverlapFlag;
        if ( image->tile_column_position[v37] + v38 == (image->extended_width >> 4) - 1 )
        {
          if ( v61 != 0 )
            goto LABEL_85;
LABEL_87:
          _jxr_4OverlapFilter(a: v54 + 250, b: v54 + 254, c: v55 + 50, d: v55 + 54);
          _jxr_4OverlapFilter(a: v54 + 251, b: v54 + 255, c: v55 + 51, d: v55 + 55);
        }
        else if ( v61 != 0 )
        {
LABEL_85:
          if ( v38 == image->tile_column_width[v37] - 1
            && v194 != image->tile_row_position[v56] + image->tile_row_height[v56] - 1 )
          {
            goto LABEL_87;
          }
        }
      }
      ++v38;
    }
    while ( v38 < image->tile_column_width[v37] );
LABEL_89:
    if ( ++v193 < image->tile_columns )
    {
      v6 = v192;
      v4 = v194;
      v10 = v193;
      v8 = ch;
      continue;
    }
    break;
  }
}


// ========================================================================
// overlap_level2_up3_422
// EA  : 0x8290E178
// RVA : 0x0090E178
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall overlap_level2_up3_422(jxr_image *image, int use_my, int ch)
{
  unsigned int *tile_row_position; // r10
  unsigned int v4; // r25
  unsigned int *tile_row_height; // r9
  int v8; // r24
  int v9; // r11
  int v10; // r23
  signed int v11; // r21
  int *data; // r31
  int *v13; // r31
  int v14; // r28
  unsigned int v15; // r27
  char *v16; // r26
  int *v17; // r31
  unsigned int *tile_column_position; // r7
  unsigned int disableTileOverlapFlag; // r10
  int *v20; // r29
  int *v21; // r3
  int *v22; // r11
  int v23; // r28
  unsigned int v24; // r27
  char *v25; // r26
  int *v26; // r31
  unsigned int *v27; // r7
  unsigned int v28; // r10
  int *v29; // r29
  int *v30; // r11
  int *v31; // r11
  int v32; // r27
  int v33; // r28
  char *v34; // r26
  int *v35; // r31
  unsigned int v36; // r10
  unsigned int v37; // r11
  int *v38; // r29
  unsigned int v39; // r7
  int *v40; // r31
  int *v41; // r29
  unsigned int v42; // r11
  unsigned int v43; // r11
  int *v44; // r5
  int *v45; // r11
  unsigned int v46; // r11
  int *v47; // [sp+8h] [-F8h]
  int *v48; // [sp+8h] [-F8h]
  int *v49; // [sp+8h] [-F8h]
  int *v50; // [sp+8h] [-F8h]
  int *v51; // [sp+8h] [-F8h]
  int *v52; // [sp+Ch] [-F4h]
  int *v53; // [sp+Ch] [-F4h]
  int *v54; // [sp+Ch] [-F4h]
  int *v55; // [sp+Ch] [-F4h]
  int *v56; // [sp+Ch] [-F4h]
  int *v57; // [sp+10h] [-F0h]
  int *v58; // [sp+10h] [-F0h]
  int *v59; // [sp+10h] [-F0h]
  int *v60; // [sp+10h] [-F0h]
  int *v61; // [sp+10h] [-F0h]
  int *v62; // [sp+14h] [-ECh]
  int *v63; // [sp+14h] [-ECh]
  int *v64; // [sp+14h] [-ECh]
  int *v65; // [sp+14h] [-ECh]
  int *v66; // [sp+14h] [-ECh]
  int *v67; // [sp+18h] [-E8h]
  int *v68; // [sp+18h] [-E8h]
  int *v69; // [sp+18h] [-E8h]
  int *v70; // [sp+18h] [-E8h]
  int *v71; // [sp+18h] [-E8h]
  int *v72; // [sp+1Ch] [-E4h]
  int *v73; // [sp+1Ch] [-E4h]
  int *v74; // [sp+1Ch] [-E4h]
  int *v75; // [sp+1Ch] [-E4h]
  int *v76; // [sp+1Ch] [-E4h]
  int *v77; // [sp+20h] [-E0h]
  int *v78; // [sp+20h] [-E0h]
  int *v79; // [sp+20h] [-E0h]
  int *v80; // [sp+20h] [-E0h]
  int *v81; // [sp+20h] [-E0h]
  int *v82; // [sp+24h] [-DCh]
  int *v83; // [sp+24h] [-DCh]
  int *v84; // [sp+24h] [-DCh]
  int *v85; // [sp+24h] [-DCh]
  int *v86; // [sp+24h] [-DCh]
  int v87; // [sp+28h] [-D8h]
  int v88; // [sp+28h] [-D8h]
  int v89; // [sp+28h] [-D8h]
  int v90; // [sp+28h] [-D8h]
  int v91; // [sp+28h] [-D8h]
  int v92; // [sp+2Ch] [-D4h]
  int v93; // [sp+2Ch] [-D4h]
  int v94; // [sp+2Ch] [-D4h]
  int v95; // [sp+2Ch] [-D4h]
  int v96; // [sp+2Ch] [-D4h]
  int v97; // [sp+30h] [-D0h]
  int v98; // [sp+30h] [-D0h]
  int v99; // [sp+30h] [-D0h]
  int v100; // [sp+30h] [-D0h]
  int v101; // [sp+30h] [-D0h]
  int v102; // [sp+34h] [-CCh]
  int v103; // [sp+34h] [-CCh]
  int v104; // [sp+34h] [-CCh]
  int v105; // [sp+34h] [-CCh]
  int v106; // [sp+34h] [-CCh]
  int v107; // [sp+38h] [-C8h]
  int v108; // [sp+38h] [-C8h]
  int v109; // [sp+38h] [-C8h]
  int v110; // [sp+38h] [-C8h]
  int v111; // [sp+38h] [-C8h]
  int v112; // [sp+3Ch] [-C4h]
  int v113; // [sp+3Ch] [-C4h]
  int v114; // [sp+3Ch] [-C4h]
  int v115; // [sp+3Ch] [-C4h]
  int v116; // [sp+3Ch] [-C4h]
  int v117; // [sp+40h] [-C0h]
  int v118; // [sp+40h] [-C0h]
  int v119; // [sp+40h] [-C0h]
  int v120; // [sp+40h] [-C0h]
  int v121; // [sp+40h] [-C0h]
  int v122; // [sp+44h] [-BCh]
  int v123; // [sp+44h] [-BCh]
  int v124; // [sp+44h] [-BCh]
  int v125; // [sp+44h] [-BCh]
  int v126; // [sp+44h] [-BCh]
  int v127; // [sp+48h] [-B8h]
  int v128; // [sp+48h] [-B8h]
  int v129; // [sp+48h] [-B8h]
  int v130; // [sp+48h] [-B8h]
  int v131; // [sp+48h] [-B8h]
  int v132; // [sp+4Ch] [-B4h]
  int v133; // [sp+4Ch] [-B4h]
  int v134; // [sp+4Ch] [-B4h]
  int v135; // [sp+4Ch] [-B4h]
  int v136; // [sp+4Ch] [-B4h]
  int v137; // [sp+50h] [-B0h]
  int v138; // [sp+50h] [-B0h]
  int v139; // [sp+50h] [-B0h]
  int v140; // [sp+50h] [-B0h]
  int v141; // [sp+50h] [-B0h]
  int v142; // [sp+58h] [-A8h]
  int v143; // [sp+58h] [-A8h]
  int v144; // [sp+58h] [-A8h]
  int v145; // [sp+58h] [-A8h]
  int v146; // [sp+58h] [-A8h]
  int v147; // [sp+60h] [-A0h]
  int v148; // [sp+60h] [-A0h]
  int v149; // [sp+60h] [-A0h]
  int v150; // [sp+60h] [-A0h]
  int v151; // [sp+60h] [-A0h]
  int v152; // [sp+68h] [-98h]
  int v153; // [sp+68h] [-98h]
  int v154; // [sp+68h] [-98h]
  int v155; // [sp+68h] [-98h]
  int v156; // [sp+68h] [-98h]
  int v157; // [sp+70h] [-90h]
  int v158; // [sp+70h] [-90h]
  int v159; // [sp+70h] [-90h]
  int v160; // [sp+70h] [-90h]
  int v161; // [sp+70h] [-90h]
  int v162; // [sp+78h] [-88h]
  int v163; // [sp+78h] [-88h]
  int v164; // [sp+78h] [-88h]
  int v165; // [sp+78h] [-88h]
  int v166; // [sp+78h] [-88h]
  int v167; // [sp+80h] [-80h]
  int v168; // [sp+80h] [-80h]
  int v169; // [sp+80h] [-80h]
  int v170; // [sp+80h] [-80h]
  int v171; // [sp+80h] [-80h]
  int v172; // [sp+88h] [-78h]
  int v173; // [sp+88h] [-78h]
  int v174; // [sp+88h] [-78h]
  int v175; // [sp+88h] [-78h]
  int v176; // [sp+88h] [-78h]

  tile_row_position = image->tile_row_position;
  v4 = use_my - 3;
  tile_row_height = image->tile_row_height;
  v8 = 0;
  if ( use_my - 3 > *tile_row_position + *tile_row_height - 1 )
  {
    v9 = 0;
    do
    {
      ++v9;
      ++v8;
    }
    while ( v4 > tile_row_height[v9] + tile_row_position[v9] - 1 );
  }
  v10 = 0;
  if ( image->tile_columns != 0 )
  {
    v11 = v4 + 1;
    while ( 1 )
    {
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        data = image->strip[ch].up3[image->tile_column_position[v10]].data;
        _jxr_4OverlapFilter(a: data + 8, b: data + 12, c: data + 32, d: data + 36);
        _jxr_4OverlapFilter(a: data + 40, b: data + 44, c: data + 64, d: data + 68);
        _jxr_4OverlapFilter(a: data + 72, b: data + 76, c: data + 96, d: data + 100);
        _jxr_4OverlapFilter(a: data + 9, b: data + 13, c: data + 33, d: data + 37);
        _jxr_4OverlapFilter(a: data + 41, b: data + 45, c: data + 65, d: data + 69);
        _jxr_4OverlapFilter(a: data + 73, b: data + 77, c: data + 97, d: data + 101);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v13 = image->strip[ch].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4OverlapFilter(a: v13 + 26, b: v13 + 30, c: v13 + 50, d: v13 + 54);
        _jxr_4OverlapFilter(a: v13 + 27, b: v13 + 31, c: v13 + 51, d: v13 + 55);
        _jxr_4OverlapFilter(a: v13 + 58, b: v13 + 62, c: v13 + 82, d: v13 + 86);
        _jxr_4OverlapFilter(a: v13 + 59, b: v13 + 63, c: v13 + 83, d: v13 + 87);
        _jxr_4OverlapFilter(a: v13 + 90, b: v13 + 94, c: v13 + 114, d: v13 + 118);
        _jxr_4OverlapFilter(a: v13 + 91, b: v13 + 95, c: v13 + 115, d: v13 + 119);
      }
      if ( v4 == 0 || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_position[v8] )
      {
        v14 = v10;
        v15 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v16 = (char *)image + 28 * ch;
          do
          {
            v17 = *(int **)(84 * (image->tile_column_position[v14] + v15) + *((_DWORD *)v16 + 32));
            _jxr_4OverlapFilter(a: v17 + 2, b: v17 + 3, c: v17 + 16, d: v17 + 17);
            _jxr_4OverlapFilter(a: v17 + 6, b: v17 + 7, c: v17 + 20, d: v17 + 21);
            tile_column_position = image->tile_column_position;
            disableTileOverlapFlag = image->disableTileOverlapFlag;
            if ( tile_column_position[v14] + v15 != 0 )
            {
              if ( disableTileOverlapFlag == 0 )
                goto LABEL_22;
            }
            else if ( disableTileOverlapFlag == 0 )
            {
              goto LABEL_23;
            }
            if ( v15 != 0 )
            {
LABEL_22:
              v20 = *(int **)(84 * (tile_column_position[v14] + v15) + *((_DWORD *)v16 + 32) - 84);
              _jxr_4OverlapFilter(a: v20 + 18, b: v20 + 19, c: v17, d: v17 + 1);
              _jxr_4OverlapFilter(a: v20 + 22, b: v20 + 23, c: v17 + 4, d: v17 + 5);
            }
LABEL_23:
            ++v15;
          }
          while ( v15 < image->tile_column_width[v14] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v21 = image->strip[ch].up3[image->tile_column_position[v10]].data;
          _jxr_4OverlapFilter(a: v21, b: v21 + 1, c: v21 + 4, d: v21 + 5);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v22 = image->strip[ch].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4OverlapFilter(a: v22 + 18, b: v22 + 19, c: v22 + 22, d: v22 + 23);
        }
      }
      if ( v11 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
      {
        v23 = v10;
        v24 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v25 = (char *)image + 28 * ch;
          do
          {
            v26 = *(int **)(84 * (image->tile_column_position[v23] + v24) + *((_DWORD *)v25 + 32));
            _jxr_4OverlapFilter(a: v26 + 106, b: v26 + 107, c: v26 + 120, d: v26 + 121);
            _jxr_4OverlapFilter(a: v26 + 110, b: v26 + 111, c: v26 + 124, d: v26 + 125);
            v27 = image->tile_column_position;
            v28 = image->disableTileOverlapFlag;
            if ( v27[v23] + v24 != 0 )
            {
              if ( v28 == 0 )
                goto LABEL_40;
            }
            else if ( v28 == 0 )
            {
              goto LABEL_41;
            }
            if ( v24 != 0 )
            {
LABEL_40:
              v29 = *(int **)(84 * (v27[v23] + v24) + *((_DWORD *)v25 + 32) - 84);
              _jxr_4OverlapFilter(a: v29 + 122, b: v29 + 123, c: v26 + 104, d: v26 + 105);
              _jxr_4OverlapFilter(a: v29 + 126, b: v29 + 127, c: v26 + 108, d: v26 + 109);
            }
LABEL_41:
            ++v24;
          }
          while ( v24 < image->tile_column_width[v23] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v30 = image->strip[ch].up3[image->tile_column_position[v10]].data;
          _jxr_4OverlapFilter(a: v30 + 104, b: v30 + 105, c: v30 + 108, d: v30 + 109);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v31 = image->strip[ch].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4OverlapFilter(a: v31 + 122, b: v31 + 123, c: v31 + 126, d: v31 + 127);
        }
      }
      v32 = v10;
      v33 = 0;
      if ( image->tile_column_width[v10] != 0 )
        break;
LABEL_83:
      if ( ++v10 >= image->tile_columns )
        return;
    }
    v34 = (char *)image + 28 * ch;
    while ( 1 )
    {
      v35 = *(int **)(84 * (image->tile_column_position[v32] + v33) + *((_DWORD *)v34 + 32));
      _jxr_4x4OverlapFilter(
        a: v35 + 10,
        b: v35 + 11,
        c: v35 + 24,
        d: v35 + 25,
        e: v35 + 14,
        f: v35 + 15,
        g: v35 + 28,
        h: v35 + 29,
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
        a28: v35 + 34,
        a29: v142,
        a30: v35 + 35,
        a31: v147,
        a32: v35 + 48,
        a33: v152,
        a34: v35 + 49,
        a35: v157,
        ia: v35 + 38,
        a37: v162,
        ja: v35 + 39,
        a39: v167,
        ka: v35 + 52,
        a41: v172,
        la: v35 + 53);
      _jxr_4x4OverlapFilter(
        a: v35 + 42,
        b: v35 + 43,
        c: v35 + 56,
        d: v35 + 57,
        e: v35 + 46,
        f: v35 + 47,
        g: v35 + 60,
        h: v35 + 61,
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
        a28: v35 + 66,
        a29: v143,
        a30: v35 + 67,
        a31: v148,
        a32: v35 + 80,
        a33: v153,
        a34: v35 + 81,
        a35: v158,
        ia: v35 + 70,
        a37: v163,
        ja: v35 + 71,
        a39: v168,
        ka: v35 + 84,
        a41: v173,
        la: v35 + 85);
      _jxr_4x4OverlapFilter(
        a: v35 + 74,
        b: v35 + 75,
        c: v35 + 88,
        d: v35 + 89,
        e: v35 + 78,
        f: v35 + 79,
        g: v35 + 92,
        h: v35 + 93,
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
        a28: v35 + 98,
        a29: v144,
        a30: v35 + 99,
        a31: v149,
        a32: v35 + 112,
        a33: v154,
        a34: v35 + 113,
        a35: v159,
        ia: v35 + 102,
        a37: v164,
        ja: v35 + 103,
        a39: v169,
        ka: v35 + 116,
        a41: v174,
        la: v35 + 117);
      v36 = image->disableTileOverlapFlag;
      v37 = image->tile_column_position[v32] + v33;
      if ( v37 >= (image->extended_width >> 4) - 1 )
        break;
      if ( v36 != 0 )
        goto LABEL_54;
LABEL_55:
      v38 = *(int **)(84 * (v37 + 1) + *((_DWORD *)v34 + 32));
      _jxr_4x4OverlapFilter(
        a: v35 + 26,
        b: v35 + 27,
        c: v38 + 8,
        d: v38 + 9,
        e: v35 + 30,
        f: v35 + 31,
        g: v38 + 12,
        h: v38 + 13,
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
        a28: v35 + 50,
        a29: v142,
        a30: v35 + 51,
        a31: v147,
        a32: v38 + 32,
        a33: v152,
        a34: v38 + 33,
        a35: v157,
        ia: v35 + 54,
        a37: v162,
        ja: v35 + 55,
        a39: v167,
        ka: v38 + 36,
        a41: v172,
        la: v38 + 37);
      _jxr_4x4OverlapFilter(
        a: v35 + 58,
        b: v35 + 59,
        c: v38 + 40,
        d: v38 + 41,
        e: v35 + 62,
        f: v35 + 63,
        g: v38 + 44,
        h: v38 + 45,
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
        a28: v35 + 82,
        a29: v145,
        a30: v35 + 83,
        a31: v150,
        a32: v38 + 64,
        a33: v155,
        a34: v38 + 65,
        a35: v160,
        ia: v35 + 86,
        a37: v165,
        ja: v35 + 87,
        a39: v170,
        ka: v38 + 68,
        a41: v175,
        la: v38 + 69);
      _jxr_4x4OverlapFilter(
        a: v35 + 90,
        b: v35 + 91,
        c: v38 + 72,
        d: v38 + 73,
        e: v35 + 94,
        f: v35 + 95,
        g: v38 + 76,
        h: v38 + 77,
        i: v51,
        j: v56,
        k: v61,
        l: v66,
        m: v71,
        n: v76,
        o: v81,
        p: v86,
        a17: v91,
        a18: v96,
        a19: v101,
        a20: v106,
        a21: v111,
        a22: v116,
        a23: v121,
        a24: v126,
        a25: v131,
        a26: v136,
        a27: v141,
        a28: v35 + 114,
        a29: v146,
        a30: v35 + 115,
        a31: v151,
        a32: v38 + 96,
        a33: v156,
        a34: v38 + 97,
        a35: v161,
        ia: v35 + 118,
        a37: v166,
        ja: v35 + 119,
        a39: v171,
        ka: v38 + 100,
        a41: v176,
        la: v38 + 101);
LABEL_56:
      if ( v11 >= (signed int)(image->extended_height >> 4) )
        goto LABEL_82;
      v39 = 84 * (image->tile_column_position[v32] + v33);
      v40 = *(int **)(*((_DWORD *)v34 + 32) + v39);
      v41 = *(int **)(v39 + *((_DWORD *)v34 + 33));
      if ( v10 != 0 || v33 != 0 )
      {
        if ( image->disableTileOverlapFlag == 0 )
          goto LABEL_67;
        if ( v33 != 0 )
          goto LABEL_65;
      }
      else if ( image->disableTileOverlapFlag == 0 )
      {
        goto LABEL_64;
      }
      if ( v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
      {
LABEL_64:
        _jxr_4OverlapFilter(a: v40 + 104, b: v40 + 108, c: v41, d: v41 + 4);
        _jxr_4OverlapFilter(a: v40 + 105, b: v40 + 109, c: v41 + 1, d: v41 + 5);
      }
LABEL_65:
      if ( image->disableTileOverlapFlag == 0 || v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
LABEL_67:
        _jxr_4x4OverlapFilter(
          a: v40 + 106,
          b: v40 + 107,
          c: v40 + 120,
          d: v40 + 121,
          e: v40 + 110,
          f: v40 + 111,
          g: v40 + 124,
          h: v40 + 125,
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
          a28: v41 + 2,
          a29: v142,
          a30: v41 + 3,
          a31: v147,
          a32: v41 + 16,
          a33: v152,
          a34: v41 + 17,
          a35: v157,
          ia: v41 + 6,
          a37: v162,
          ja: v41 + 7,
          a39: v167,
          ka: v41 + 20,
          a41: v172,
          la: v41 + 21);
      v42 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v32] + v33 < (image->extended_width >> 4) - 1 )
      {
        if ( v42 != 0 )
        {
LABEL_72:
          if ( v33 == image->tile_column_width[v32] - 1
            || v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
          {
            goto LABEL_75;
          }
        }
        v43 = 84 * (image->tile_column_position[v32] + v33);
        v44 = *(int **)(v43 + *((_DWORD *)v34 + 33) + 84);
        v45 = *(int **)(*((_DWORD *)v34 + 32) + v43 + 84);
        _jxr_4x4OverlapFilter(
          a: v40 + 122,
          b: v40 + 123,
          c: v45 + 104,
          d: v45 + 105,
          e: v40 + 126,
          f: v40 + 127,
          g: v45 + 108,
          h: v45 + 109,
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
          a28: v41 + 18,
          a29: v142,
          a30: v41 + 19,
          a31: v147,
          a32: v44,
          a33: v152,
          a34: v44 + 1,
          a35: v157,
          ia: v41 + 22,
          a37: v162,
          ja: v41 + 23,
          a39: v167,
          ka: v44 + 4,
          a41: v172,
          la: v44 + 5);
        goto LABEL_75;
      }
      if ( v42 != 0 )
        goto LABEL_72;
LABEL_75:
      v46 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v32] + v33 == (image->extended_width >> 4) - 1 )
      {
        if ( v46 != 0 )
        {
LABEL_79:
          if ( v33 != image->tile_column_width[v32] - 1
            || v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
          {
            goto LABEL_82;
          }
        }
        _jxr_4OverlapFilter(a: v40 + 122, b: v40 + 126, c: v41 + 18, d: v41 + 22);
        _jxr_4OverlapFilter(a: v40 + 123, b: v40 + 127, c: v41 + 19, d: v41 + 23);
        goto LABEL_82;
      }
      if ( v46 != 0 )
        goto LABEL_79;
LABEL_82:
      if ( ++v33 >= image->tile_column_width[v32] )
        goto LABEL_83;
    }
    if ( v36 == 0 )
      goto LABEL_56;
LABEL_54:
    if ( v33 == image->tile_column_width[v32] - 1 )
      goto LABEL_56;
    goto LABEL_55;
  }
}


// ========================================================================
// overlap_level2_up3_420
// EA  : 0x8290ECA0
// RVA : 0x0090ECA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall overlap_level2_up3_420(jxr_image *image, int use_my, int ch)
{
  unsigned int *tile_row_position; // r10
  unsigned int v4; // r25
  unsigned int *tile_row_height; // r9
  int v8; // r24
  int v9; // r11
  int v10; // r23
  signed int v11; // r21
  int *data; // r30
  int *v13; // r30
  int v14; // r28
  unsigned int v15; // r27
  char *v16; // r26
  int *v17; // r30
  unsigned int *tile_column_position; // r7
  unsigned int disableTileOverlapFlag; // r10
  int *v20; // r29
  int *v21; // r3
  int *v22; // r11
  int v23; // r29
  unsigned int v24; // r27
  char *v25; // r26
  int *v26; // r30
  unsigned int *v27; // r7
  unsigned int v28; // r10
  int *v29; // r28
  int *v30; // r11
  char *v31; // r26
  int *v32; // r11
  unsigned int i; // r27
  int *v34; // r30
  unsigned int *v35; // r7
  unsigned int v36; // r10
  int *v37; // r28
  int *v38; // r3
  int *v39; // r11
  int v40; // r27
  int v41; // r28
  char *v42; // r26
  int *v43; // r30
  unsigned int v44; // r10
  unsigned int v45; // r11
  int *v46; // r11
  unsigned int v47; // r7
  int *v48; // r30
  int *v49; // r29
  unsigned int v50; // r11
  unsigned int v51; // r11
  int *v52; // r5
  int *v53; // r11
  unsigned int v54; // r11
  int *v55; // [sp+8h] [-F8h]
  int *v56; // [sp+Ch] [-F4h]
  int *v57; // [sp+10h] [-F0h]
  int *v58; // [sp+14h] [-ECh]
  int *v59; // [sp+18h] [-E8h]
  int *v60; // [sp+1Ch] [-E4h]
  int *v61; // [sp+20h] [-E0h]
  int *v62; // [sp+24h] [-DCh]
  int v63; // [sp+28h] [-D8h]
  int v64; // [sp+2Ch] [-D4h]
  int v65; // [sp+30h] [-D0h]
  int v66; // [sp+34h] [-CCh]
  int v67; // [sp+38h] [-C8h]
  int v68; // [sp+3Ch] [-C4h]
  int v69; // [sp+40h] [-C0h]
  int v70; // [sp+44h] [-BCh]
  int v71; // [sp+48h] [-B8h]
  int v72; // [sp+4Ch] [-B4h]
  int v73; // [sp+50h] [-B0h]
  int v74; // [sp+58h] [-A8h]
  int v75; // [sp+60h] [-A0h]
  int v76; // [sp+68h] [-98h]
  int v77; // [sp+70h] [-90h]
  int v78; // [sp+78h] [-88h]
  int v79; // [sp+80h] [-80h]
  int v80; // [sp+88h] [-78h]

  tile_row_position = image->tile_row_position;
  v4 = use_my - 3;
  tile_row_height = image->tile_row_height;
  v8 = 0;
  if ( use_my - 3 > *tile_row_position + *tile_row_height - 1 )
  {
    v9 = 0;
    do
    {
      ++v9;
      ++v8;
    }
    while ( v4 > tile_row_height[v9] + tile_row_position[v9] - 1 );
  }
  v10 = 0;
  if ( image->tile_columns != 0 )
  {
    v11 = v4 + 1;
    while ( 1 )
    {
      if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
      {
        data = image->strip[ch].up3[image->tile_column_position[v10]].data;
        _jxr_4OverlapFilter(a: data + 8, b: data + 12, c: data + 32, d: data + 36);
        _jxr_4OverlapFilter(a: data + 9, b: data + 13, c: data + 33, d: data + 37);
      }
      if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
      {
        v13 = image->strip[ch].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
        _jxr_4OverlapFilter(a: v13 + 26, b: v13 + 30, c: v13 + 50, d: v13 + 54);
        _jxr_4OverlapFilter(a: v13 + 27, b: v13 + 31, c: v13 + 51, d: v13 + 55);
      }
      if ( v4 == 0 )
      {
        v14 = v10;
        v15 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v16 = (char *)image + 28 * ch;
          do
          {
            v17 = *(int **)(84 * (image->tile_column_position[v14] + v15) + *((_DWORD *)v16 + 32));
            _jxr_4OverlapFilter(a: v17 + 2, b: v17 + 3, c: v17 + 16, d: v17 + 17);
            _jxr_4OverlapFilter(a: v17 + 6, b: v17 + 7, c: v17 + 20, d: v17 + 21);
            tile_column_position = image->tile_column_position;
            disableTileOverlapFlag = image->disableTileOverlapFlag;
            if ( tile_column_position[v14] + v15 != 0 )
            {
              if ( disableTileOverlapFlag == 0 )
                goto LABEL_20;
            }
            else if ( disableTileOverlapFlag == 0 )
            {
              goto LABEL_21;
            }
            if ( v15 != 0 )
            {
LABEL_20:
              v20 = *(int **)(84 * (tile_column_position[v14] + v15) + *((_DWORD *)v16 + 32) - 84);
              _jxr_4OverlapFilter(a: v20 + 18, b: v20 + 19, c: v17, d: v17 + 1);
              _jxr_4OverlapFilter(a: v20 + 22, b: v20 + 23, c: v17 + 4, d: v17 + 5);
            }
LABEL_21:
            ++v15;
          }
          while ( v15 < image->tile_column_width[v14] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v21 = image->strip[ch].up3[image->tile_column_position[v10]].data;
          _jxr_4OverlapFilter(a: v21, b: v21 + 1, c: v21 + 4, d: v21 + 5);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v22 = image->strip[ch].up3[image->tile_column_position[v10] - 1 + image->tile_column_width[v10]].data;
          _jxr_4OverlapFilter(a: v22 + 18, b: v22 + 19, c: v22 + 22, d: v22 + 23);
        }
      }
      if ( v11 == image->extended_height >> 4
        || image->disableTileOverlapFlag != 0 && v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
      {
        v23 = v10;
        v24 = 0;
        if ( image->tile_column_width[v10] != 0 )
        {
          v25 = (char *)image + 28 * ch;
          do
          {
            v26 = *(int **)(84 * (image->tile_column_position[v23] + v24) + *((_DWORD *)v25 + 32));
            _jxr_4OverlapFilter(a: v26 + 42, b: v26 + 43, c: v26 + 56, d: v26 + 57);
            _jxr_4OverlapFilter(a: v26 + 46, b: v26 + 47, c: v26 + 60, d: v26 + 61);
            v27 = image->tile_column_position;
            v28 = image->disableTileOverlapFlag;
            if ( v27[v23] + v24 != 0 )
            {
              if ( v28 == 0 )
                goto LABEL_38;
            }
            else if ( v28 == 0 )
            {
              goto LABEL_39;
            }
            if ( v24 != 0 )
            {
LABEL_38:
              v29 = *(int **)(84 * (v27[v23] + v24) + *((_DWORD *)v25 + 32) - 84);
              _jxr_4OverlapFilter(a: v29 + 58, b: v29 + 59, c: v26 + 40, d: v26 + 41);
              _jxr_4OverlapFilter(a: v29 + 62, b: v29 + 63, c: v26 + 44, d: v26 + 45);
            }
LABEL_39:
            ++v24;
          }
          while ( v24 < image->tile_column_width[v23] );
        }
        if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
        {
          v30 = image->strip[ch].up3[image->tile_column_position[v10]].data;
          _jxr_4OverlapFilter(a: v30 + 40, b: v30 + 41, c: v30 + 44, d: v30 + 45);
        }
        if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
        {
          v31 = (char *)image + 28 * ch;
          v32 = *(int **)(84 * (image->tile_column_position[v23] + image->tile_column_width[v23])
                        + *((_DWORD *)v31 + 32)
                        - 84);
          _jxr_4OverlapFilter(a: v32 + 58, b: v32 + 59, c: v32 + 62, d: v32 + 63);
          if ( image->disableTileOverlapFlag != 0
            && v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1
            && v4 < (image->extended_height >> 4) - 1 )
          {
            for ( i = 0; i < image->tile_column_width[v23]; ++i )
            {
              v34 = *(int **)(84 * (image->tile_column_position[v23] + i) + *((_DWORD *)v31 + 33));
              _jxr_4OverlapFilter(a: v34 + 2, b: v34 + 3, c: v34 + 16, d: v34 + 17);
              _jxr_4OverlapFilter(a: v34 + 6, b: v34 + 7, c: v34 + 20, d: v34 + 21);
              v35 = image->tile_column_position;
              v36 = image->disableTileOverlapFlag;
              if ( v35[v23] + i != 0 )
              {
                if ( v36 == 0 )
                  goto LABEL_54;
              }
              else if ( v36 == 0 )
              {
                continue;
              }
              if ( i != 0 )
              {
LABEL_54:
                v37 = *(int **)(84 * (v35[v23] + i) + *((_DWORD *)v31 + 33) - 84);
                _jxr_4OverlapFilter(a: v37 + 18, b: v37 + 19, c: v34, d: v34 + 1);
                _jxr_4OverlapFilter(a: v37 + 22, b: v37 + 23, c: v34 + 4, d: v34 + 5);
              }
            }
            if ( v10 == 0 || image->disableTileOverlapFlag != 0 )
            {
              v38 = *(int **)(84 * image->tile_column_position[v23] + *((_DWORD *)v31 + 33));
              _jxr_4OverlapFilter(a: v38, b: v38 + 1, c: v38 + 4, d: v38 + 5);
            }
            if ( v10 == image->tile_columns - 1 || image->disableTileOverlapFlag != 0 )
            {
              v39 = *(int **)(84 * (image->tile_column_position[v23] + image->tile_column_width[v23])
                            + *((_DWORD *)v31 + 33)
                            - 84);
              _jxr_4OverlapFilter(a: v39 + 18, b: v39 + 19, c: v39 + 22, d: v39 + 23);
            }
          }
        }
      }
      v40 = v10;
      v41 = 0;
      if ( image->tile_column_width[v10] != 0 )
        break;
LABEL_97:
      if ( ++v10 >= image->tile_columns )
        return;
    }
    v42 = (char *)image + 28 * ch;
    while ( 1 )
    {
      v43 = *(int **)(84 * (image->tile_column_position[v40] + v41) + *((_DWORD *)v42 + 32));
      _jxr_4x4OverlapFilter(
        a: v43 + 10,
        b: v43 + 11,
        c: v43 + 24,
        d: v43 + 25,
        e: v43 + 14,
        f: v43 + 15,
        g: v43 + 28,
        h: v43 + 29,
        i: v55,
        j: v56,
        k: v57,
        l: v58,
        m: v59,
        n: v60,
        o: v61,
        p: v62,
        a17: v63,
        a18: v64,
        a19: v65,
        a20: v66,
        a21: v67,
        a22: v68,
        a23: v69,
        a24: v70,
        a25: v71,
        a26: v72,
        a27: v73,
        a28: v43 + 34,
        a29: v74,
        a30: v43 + 35,
        a31: v75,
        a32: v43 + 48,
        a33: v76,
        a34: v43 + 49,
        a35: v77,
        ia: v43 + 38,
        a37: v78,
        ja: v43 + 39,
        a39: v79,
        ka: v43 + 52,
        a41: v80,
        la: v43 + 53);
      v44 = image->disableTileOverlapFlag;
      v45 = image->tile_column_position[v40] + v41;
      if ( v45 >= (image->extended_width >> 4) - 1 )
        break;
      if ( v44 != 0 )
        goto LABEL_68;
LABEL_69:
      v46 = *(int **)(84 * (v45 + 1) + *((_DWORD *)v42 + 32));
      _jxr_4x4OverlapFilter(
        a: v43 + 26,
        b: v43 + 27,
        c: v46 + 8,
        d: v46 + 9,
        e: v43 + 30,
        f: v43 + 31,
        g: v46 + 12,
        h: v46 + 13,
        i: v55,
        j: v56,
        k: v57,
        l: v58,
        m: v59,
        n: v60,
        o: v61,
        p: v62,
        a17: v63,
        a18: v64,
        a19: v65,
        a20: v66,
        a21: v67,
        a22: v68,
        a23: v69,
        a24: v70,
        a25: v71,
        a26: v72,
        a27: v73,
        a28: v43 + 50,
        a29: v74,
        a30: v43 + 51,
        a31: v75,
        a32: v46 + 32,
        a33: v76,
        a34: v46 + 33,
        a35: v77,
        ia: v43 + 54,
        a37: v78,
        ja: v43 + 55,
        a39: v79,
        ka: v46 + 36,
        a41: v80,
        la: v46 + 37);
LABEL_70:
      if ( v11 >= (signed int)(image->extended_height >> 4) )
        goto LABEL_96;
      v47 = 84 * (image->tile_column_position[v40] + v41);
      v48 = *(int **)(v47 + *((_DWORD *)v42 + 32));
      v49 = *(int **)(v47 + *((_DWORD *)v42 + 33));
      if ( v10 != 0 || v41 != 0 )
      {
        if ( image->disableTileOverlapFlag == 0 )
          goto LABEL_81;
        if ( v41 != 0 )
          goto LABEL_79;
      }
      else if ( image->disableTileOverlapFlag == 0 )
      {
        goto LABEL_78;
      }
      if ( v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
      {
LABEL_78:
        _jxr_4OverlapFilter(a: v48 + 40, b: v48 + 44, c: v49, d: v49 + 4);
        _jxr_4OverlapFilter(a: v48 + 41, b: v48 + 45, c: v49 + 1, d: v49 + 5);
      }
LABEL_79:
      if ( image->disableTileOverlapFlag == 0 || v4 != image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
LABEL_81:
        _jxr_4x4OverlapFilter(
          a: v48 + 42,
          b: v48 + 43,
          c: v48 + 56,
          d: v48 + 57,
          e: v48 + 46,
          f: v48 + 47,
          g: v48 + 60,
          h: v48 + 61,
          i: v55,
          j: v56,
          k: v57,
          l: v58,
          m: v59,
          n: v60,
          o: v61,
          p: v62,
          a17: v63,
          a18: v64,
          a19: v65,
          a20: v66,
          a21: v67,
          a22: v68,
          a23: v69,
          a24: v70,
          a25: v71,
          a26: v72,
          a27: v73,
          a28: v49 + 2,
          a29: v74,
          a30: v49 + 3,
          a31: v75,
          a32: v49 + 16,
          a33: v76,
          a34: v49 + 17,
          a35: v77,
          ia: v49 + 6,
          a37: v78,
          ja: v49 + 7,
          a39: v79,
          ka: v49 + 20,
          a41: v80,
          la: v49 + 21);
      v50 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v40] + v41 < (image->extended_width >> 4) - 1 )
      {
        if ( v50 != 0 )
        {
LABEL_86:
          if ( v41 == image->tile_column_width[v40] - 1
            || v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
          {
            goto LABEL_89;
          }
        }
        v51 = 84 * (image->tile_column_position[v40] + v41);
        v52 = *(int **)(v51 + *((_DWORD *)v42 + 33) + 84);
        v53 = *(int **)(v51 + *((_DWORD *)v42 + 32) + 84);
        _jxr_4x4OverlapFilter(
          a: v48 + 58,
          b: v48 + 59,
          c: v53 + 40,
          d: v53 + 41,
          e: v48 + 62,
          f: v48 + 63,
          g: v53 + 44,
          h: v53 + 45,
          i: v55,
          j: v56,
          k: v57,
          l: v58,
          m: v59,
          n: v60,
          o: v61,
          p: v62,
          a17: v63,
          a18: v64,
          a19: v65,
          a20: v66,
          a21: v67,
          a22: v68,
          a23: v69,
          a24: v70,
          a25: v71,
          a26: v72,
          a27: v73,
          a28: v49 + 18,
          a29: v74,
          a30: v49 + 19,
          a31: v75,
          a32: v52,
          a33: v76,
          a34: v52 + 1,
          a35: v77,
          ia: v49 + 22,
          a37: v78,
          ja: v49 + 23,
          a39: v79,
          ka: v52 + 4,
          a41: v80,
          la: v52 + 5);
        goto LABEL_89;
      }
      if ( v50 != 0 )
        goto LABEL_86;
LABEL_89:
      v54 = image->disableTileOverlapFlag;
      if ( image->tile_column_position[v40] + v41 == (image->extended_width >> 4) - 1 )
      {
        if ( v54 != 0 )
        {
LABEL_93:
          if ( v41 != image->tile_column_width[v40] - 1
            || v4 == image->tile_row_height[v8] + image->tile_row_position[v8] - 1 )
          {
            goto LABEL_96;
          }
        }
        _jxr_4OverlapFilter(a: v48 + 58, b: v48 + 62, c: v49 + 18, d: v49 + 22);
        _jxr_4OverlapFilter(a: v48 + 59, b: v48 + 63, c: v49 + 19, d: v49 + 23);
        goto LABEL_96;
      }
      if ( v54 != 0 )
        goto LABEL_93;
LABEL_96:
      if ( ++v41 >= image->tile_column_width[v40] )
        goto LABEL_97;
    }
    if ( v44 == 0 )
      goto LABEL_70;
LABEL_68:
    if ( v41 == image->tile_column_width[v40] - 1 )
      goto LABEL_70;
    goto LABEL_69;
  }
}


// ========================================================================
// yuv444_to_rgb
// EA  : 0x8290F710
// RVA : 0x0090F710
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall yuv444_to_rgb(jxr_image *image, int mx)
{
  int v3; // r30
  int i; // r31
  int v5; // r27
  int v6; // r26
  int v7; // r28
  int v8; // r26
  int v9; // r11

  v3 = mx;
  for ( i = 0; i < 256; ++i )
  {
    v5 = image->strip[1].up3[v3].data[i];
    v6 = image->strip[0].up3[v3].data[i];
    v7 = image->strip[2].up3[v3].data[i];
    v8 = v6 - _jxr_floor_div2(x: -v5);
    v9 = v8 - v5 - _jxr_ceil_div2(x: v7);
    image->strip[0].up3[v3].data[i] = v9;
    image->strip[1].up3[v3].data[i] = v8;
    image->strip[2].up3[v3].data[i] = v9 + v7;
  }
}


// ========================================================================
// upsample
// EA  : 0x8290F7A8
// RVA : 0x0090F7A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall upsample(int *inbuf, int *outbuf, int upsamplelen, int chroma_center)
{
  int *v4; // r11
  int v5; // r7
  int *v6; // r8
  int *v7; // r10
  int v8; // ctr
  int v9; // r31
  int v10; // r30
  int v11; // r10
  int v12; // r8
  int *v13; // r10
  int v14; // ctr
  int v15; // r4
  int v16; // r6

  v4 = inbuf;
  if ( chroma_center == 5 || chroma_center == 6 || chroma_center == 7 )
    chroma_center = 0;
  if ( (upsamplelen - 2) / 2 >= 0 )
  {
    v5 = chroma_center;
    v6 = outbuf - 1;
    v8 = (upsamplelen - 2) / 2 + 1;
    v7 = inbuf + 1;
    do
    {
      v9 = v7[1];
      v10 = *v7++ * iH[v5][0];
      v6 += 2;
      *v6 = (iH[v5][1] * v9 + v10 + 4) >> 3;
      --v8;
    }
    while ( v8 != 0 );
  }
  v11 = (upsamplelen - 4) / 2;
  if ( v11 >= -1 )
  {
    v12 = chroma_center;
    v14 = v11 + 2;
    v13 = outbuf - 2;
    do
    {
      v15 = v4[1];
      v16 = *v4++ * iH[v12][2];
      v13 += 2;
      *v13 = (iH[v12][3] * v15 + v16 + 4) >> 3;
      --v14;
    }
    while ( v14 != 0 );
  }
}


// ========================================================================
// yuv422_to_yuv444
// EA  : 0x8290F890
// RVA : 0x0090F890
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall yuv422_to_yuv444(jxr_image *image, int mx)
{
  signed int v4; // r22
  int v5; // r28
  macroblock_s **p_up3; // r29
  int i; // r18
  int v8; // r26
  int v9; // r25
  int *v10; // r24
  int v11; // r30
  int *v12; // r27
  macroblock_s *v13; // r10
  signed int v14; // r8
  int *data; // r31
  int v16; // r6
  int v17; // r17
  int v18; // r16
  int v19; // r6
  int v20; // r5
  int v21; // r4
  int v22; // r9
  int v23; // r11
  int v24; // r10
  unsigned int v25; // r10
  int j; // ctr
  _BYTE *v27; // r11
  int v28; // r6
  int v29; // r5
  int v30; // r4
  int v31[9]; // [sp+50h] [-4C0h] BYREF
  int v32; // [sp+74h] [-49Ch]
  char v33; // [sp+80h] [-490h] BYREF
  _BYTE v34[1164]; // [sp+84h] [-48Ch] BYREF

  v4 = mx + 1;
  v5 = mx;
  p_up3 = &image->strip[1].up3;
  for ( i = 2; i != 0; --i )
  {
    v8 = 0;
    v9 = 0;
    v10 = (int *)&v33;
    v11 = 3;
    do
    {
      if ( mx == 0 )
        *(int **)((char *)&p_up3[5]->data + v8) = (int *)(*p_up3)->data[v9];
      v12 = (int *)((char *)p_up3[5] + v8);
      v13 = &(*p_up3)[v5];
      v14 = image->extended_width >> 4;
      data = v13->data;
      v16 = (int)&v13->data[v11];
      v31[0] = *v12;
      v17 = data[v11 - 3];
      v18 = data[v11 - 2];
      v20 = *(_DWORD *)(v16 + 4);
      v21 = *(_DWORD *)(v16 + 8);
      v19 = *(_DWORD *)(v16 - 4);
      v22 = data[v11 + 3];
      v23 = data[v11 + 4];
      v31[4] = data[v11];
      v31[3] = v19;
      v31[1] = v17;
      v31[2] = v18;
      v31[8] = v23;
      v31[5] = v20;
      v31[6] = v21;
      v31[7] = v22;
      if ( v4 >= v14 )
        v32 = v23;
      else
        v32 = v13[1].data[v9];
      upsample(inbuf: v31, outbuf: v10, upsamplelen: 16, chroma_center: image->chroma_centering_x);
      v11 += 8;
      v10 += 16;
      v8 += 4;
      v24 = data[v9 + 7];
      v9 += 8;
      *v12 = v24;
    }
    while ( v11 < 131 );
    v25 = 0;
    for ( j = 64; j != 0; --j )
    {
      v27 = &v34[v25];
      v28 = *(_DWORD *)&v34[v25];
      v29 = *(_DWORD *)&v34[v25 + 4];
      v30 = *(_DWORD *)&v34[v25 + 8];
      (*p_up3)[v5].data[v25 / 4] = *(_DWORD *)&v34[v25 - 4];
      (*p_up3)[v5].data[v25 / 4 + 1] = v28;
      v25 += 16;
      *(int *)((char *)(*p_up3)[v5].data + 8 - (_DWORD)v34 + (unsigned int)v27) = v29;
      *(int *)((char *)(*p_up3)[v5].data + 12 - (_DWORD)v34 + (unsigned int)v27) = v30;
    }
    p_up3 += 7;
  }
}


// ========================================================================
// yuv420_to_yuv444
// EA  : 0x8290FA40
// RVA : 0x0090FA40
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall yuv420_to_yuv444(jxr_image *image, int use_my, int mx)
{
  signed int v5; // r19
  int v6; // r25
  int v7; // r17
  unsigned __int8 *p_use_clr_fmt; // r30
  int i; // r24
  int v10; // r26
  int v11; // r29
  int v12; // r31
  int v13; // r27
  int v14; // r11
  bool v15; // cr56
  int v16; // r9
  int v17; // r23
  _DWORD *v18; // r11
  int v19; // r6
  int v20; // r5
  int v21; // r4
  int v22; // r3
  int v23; // r8
  int v24; // r28
  int v25; // r11
  int v26; // r11
  int *v27; // r10
  int v28; // r11
  int j; // ctr
  int v30; // r8
  signed int v31; // r23
  int v32; // r24
  macroblock_s **p_up3; // r29
  signed int v34; // r10
  macroblock_s *v35; // r11
  int *data; // r9
  int v37; // r9
  int *v38; // r8
  int *v39; // r8
  int *v40; // r8
  int *v41; // r8
  int *v42; // r8
  int *v43; // r8
  int *v44; // r11
  int v45; // r11
  signed int v46; // r7
  int v47; // r31
  int v48; // r30
  int *v49; // r26
  macroblock_s *v50; // r9
  int v51; // r28
  unsigned int extended_width; // r8
  int v53; // r11
  int v54; // r7
  int v55; // r5
  int v56; // r4
  int v57; // r10
  int v58; // r5
  _DWORD *v59; // r27
  int v60; // r7
  int v61; // r11
  unsigned int v62; // r10
  int k; // ctr
  _BYTE *v64; // r11
  int v65; // r6
  int v66; // r5
  int v67; // r4
  int v68; // [sp+50h] [-910h] BYREF
  int v69; // [sp+54h] [-90Ch]
  int v70; // [sp+58h] [-908h]
  int v71; // [sp+5Ch] [-904h]
  int v72; // [sp+60h] [-900h]
  int v73; // [sp+64h] [-8FCh]
  int v74; // [sp+68h] [-8F8h]
  int v75; // [sp+6Ch] [-8F4h]
  int v76; // [sp+70h] [-8F0h]
  int v77; // [sp+74h] [-8ECh]
  int v78[271]; // [sp+80h] [-8E0h] BYREF
  char v79; // [sp+4BCh] [-4A4h] BYREF
  int v80; // [sp+4C0h] [-4A0h] BYREF
  _BYTE v81[1180]; // [sp+4C4h] [-49Ch] BYREF

  v5 = use_my - 2;
  v6 = mx;
  v7 = 8 * mx;
  p_use_clr_fmt = &image->use_clr_fmt;
  for ( i = 0; i < 32; i += 16 )
  {
    v10 = 0;
    v11 = v7 * 4;
    v12 = 64;
    do
    {
      if ( v5 == 1 )
        *(_DWORD *)(*((_DWORD *)p_use_clr_fmt + 36) + v11) = *(_DWORD *)(*(_DWORD *)(v6 * 84
                                                                                   + *((_DWORD *)p_use_clr_fmt + 32))
                                                                       + v12
                                                                       - 64);
      v13 = *((_DWORD *)p_use_clr_fmt + 36);
      v14 = *(_DWORD *)(v6 * 84 + *((_DWORD *)p_use_clr_fmt + 32));
      v15 = v5 < (signed int)(image->extended_height >> 4);
      v16 = *(_DWORD *)(v12 - 64 + v14);
      v17 = *(_DWORD *)(v12 + v14);
      v18 = (_DWORD *)(v12 + v14);
      v19 = *(v18 - 8);
      v20 = v18[8];
      v21 = v18[16];
      v22 = v18[24];
      v23 = v18[32];
      v25 = v18[40];
      v24 = v25;
      v68 = *(_DWORD *)(v13 + v11);
      v69 = v16;
      v71 = v17;
      v70 = v19;
      v76 = v25;
      v72 = v20;
      v73 = v21;
      v74 = v22;
      v75 = v23;
      if ( v15 )
      {
        v26 = *((_DWORD *)p_use_clr_fmt + 33);
        if ( v10 > 3 )
          v77 = *(_DWORD *)(*(_DWORD *)(v6 * 84 + v26) + v12 - 16);
        else
          v77 = *(_DWORD *)(*(_DWORD *)(v6 * 84 + v26) + v12 - 64);
      }
      else
      {
        v77 = v25;
      }
      upsample(inbuf: &v68, outbuf: &v80, upsamplelen: 16, chroma_center: image->chroma_centering_y);
      v27 = (int *)&v79;
      v28 = 0;
      for ( j = 16; j != 0; --j )
      {
        ++v27;
        v30 = 8 * (i + v28++);
        v78[v30 + 16 + v10] = *v27;
      }
      v12 += 4;
      *(_DWORD *)(v13 + v11) = v24;
      ++v10;
      v11 += 4;
    }
    while ( v12 < 96 );
    p_use_clr_fmt += 28;
  }
  v31 = mx + 1;
  v32 = 16;
  p_up3 = &image->strip[1].up3;
  do
  {
    v34 = image->extended_width >> 4;
    v35 = &(*p_up3)[v6];
    if ( v31 >= v34 )
      data = v35->data;
    else
      data = v35[1].data;
    v37 = *data;
    v69 = v37;
    if ( v31 >= v34 )
      v38 = v35->data;
    else
      v38 = v35[1].data;
    v70 = v38[8];
    if ( v31 >= v34 )
      v39 = v35->data;
    else
      v39 = v35[1].data;
    v71 = v39[16];
    if ( v31 >= v34 )
      v40 = v35->data;
    else
      v40 = v35[1].data;
    v72 = v40[24];
    if ( v31 >= v34 )
      v41 = v35->data;
    else
      v41 = v35[1].data;
    v73 = v41[32];
    if ( v31 >= v34 )
      v42 = v35->data;
    else
      v42 = v35[1].data;
    v74 = v42[40];
    if ( v31 >= v34 )
      v43 = v35->data;
    else
      v43 = v35[1].data;
    v75 = v43[48];
    if ( v31 >= v34 )
      v44 = v35->data;
    else
      v44 = v35[1].data;
    v45 = v44[56];
    v46 = image->extended_height >> 4;
    v76 = v45;
    if ( v5 >= v46 || v31 >= v34 )
      v77 = v45;
    else
      v77 = *p_up3[1][v6 + 1].data;
    if ( v5 == 1 || v31 >= v34 )
      v68 = v37;
    else
      v68 = p_up3[4]->hp_model_bits[v7 + 3];
    upsample(inbuf: &v68, outbuf: v78, upsamplelen: 16, chroma_center: image->chroma_centering_y);
    v47 = 0;
    v48 = 0;
    v49 = &v80;
    do
    {
      if ( mx == 0 )
        *(int **)((char *)&p_up3[5]->data + v48 * 4) = (int *)v78[8 * v32 - 112 + 8 * v47];
      v50 = p_up3[5];
      v51 = v32 + v47;
      extended_width = image->extended_width;
      v53 = 8 * (v32 + v47);
      v68 = *(int *)((char *)&v50->data + v48 * 4);
      v54 = v78[8 * v32 - 112 + 8 * v47];
      v55 = v78[v53 - 110];
      v70 = v78[v53 - 111];
      v56 = v78[v53 - 109];
      v69 = v54;
      v71 = v55;
      v72 = v56;
      v57 = v78[v53 - 108];
      v58 = v78[v53 - 107];
      v59 = (int **)((char *)&v50->data + v48 * 4);
      v60 = v78[v53 - 106];
      v61 = v78[v53 - 105];
      v73 = v57;
      v74 = v58;
      v75 = v60;
      v76 = v61;
      if ( v31 >= (int)(extended_width >> 4) )
        v77 = v61;
      else
        v77 = v78[v48];
      upsample(inbuf: &v68, outbuf: v49, upsamplelen: 16, chroma_center: image->chroma_centering_x);
      ++v48;
      ++v47;
      v49 += 16;
      *v59 = v78[8 * v51 - 105];
    }
    while ( v48 < 16 );
    v62 = 0;
    for ( k = 64; k != 0; --k )
    {
      v64 = &v81[v62];
      v65 = *(_DWORD *)&v81[v62];
      v66 = *(_DWORD *)&v81[v62 + 4];
      v67 = *(_DWORD *)&v81[v62 + 8];
      (*p_up3)[v6].data[v62 / 4] = *(_DWORD *)&v81[v62 - 4];
      (*p_up3)[v6].data[v62 / 4 + 1] = v65;
      v62 += 16;
      *(int *)((char *)(*p_up3)[v6].data + 8 - (_DWORD)v81 + (unsigned int)v64) = v66;
      *(int *)((char *)(*p_up3)[v6].data + 12 - (_DWORD)v81 + (unsigned int)v64) = v67;
    }
    v32 += 16;
    p_up3 += 7;
  }
  while ( v32 < 48 );
}


// ========================================================================
// yuvk_to_cmykdirect
// EA  : 0x8290FF08
// RVA : 0x0090FF08
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall yuvk_to_cmykdirect(jxr_image *image, int mx)
{
  int v2; // r11
  int v3; // ctr
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int *data; // r7
  int v8; // r6
  int v9; // r31
  int v10; // r5
  int *v11; // r7
  int v12; // r6
  int v13; // r5
  int v14; // r4
  int *v15; // r7
  int v16; // r31
  int v17; // r6
  int v18; // r5
  int *v19; // r8
  int v20; // r7
  int v21; // r4
  int v22; // r6
  int v23; // r5

  v2 = mx;
  v3 = 64;
  v4 = 0;
  do
  {
    v5 = v4 * 4 + 12;
    v6 = v4 * 4 + 8;
    data = image->strip[0].up3[v2].data;
    v8 = image->strip[2].up3[v2].data[v4];
    v9 = data[v4];
    v10 = image->strip[3].up3[v2].data[v4];
    data[v4] = image->strip[1].up3[v2].data[v4];
    image->strip[1].up3[v2].data[v4] = v8;
    image->strip[2].up3[v2].data[v4] = v10;
    image->strip[3].up3[v2].data[v4] = v9;
    v11 = &image->strip[0].up3[v2].data[v4];
    v12 = v11[1];
    v13 = image->strip[2].up3[v2].data[v4 + 1];
    v14 = image->strip[3].up3[v2].data[v4 + 1];
    v11[1] = image->strip[1].up3[v2].data[v4 + 1];
    image->strip[1].up3[v2].data[v4 + 1] = v13;
    image->strip[2].up3[v2].data[v4 + 1] = v14;
    image->strip[3].up3[v2].data[v4 + 1] = v12;
    v15 = image->strip[0].up3[v2].data;
    v16 = v15[v4 + 2];
    v17 = image->strip[2].up3[v2].data[v4 + 2];
    v18 = image->strip[3].up3[v2].data[v4 + 2];
    *(int *)((char *)v15 + v6) = image->strip[1].up3[v2].data[v4 + 2];
    *(int *)((char *)image->strip[1].up3[v2].data + v6) = v17;
    *(int *)((char *)image->strip[2].up3[v2].data + v6) = v18;
    *(int *)((char *)image->strip[3].up3[v2].data + v6) = v16;
    v19 = image->strip[0].up3[v2].data;
    v20 = v19[v4 + 3];
    v21 = image->strip[1].up3[v2].data[v4 + 3];
    v22 = image->strip[2].up3[v2].data[v4 + 3];
    v23 = image->strip[3].up3[v2].data[v4 + 3];
    v4 += 4;
    *(int *)((char *)v19 + v5) = v21;
    *(int *)((char *)image->strip[1].up3[v2].data + v5) = v22;
    *(int *)((char *)image->strip[2].up3[v2].data + v5) = v23;
    *(int *)((char *)image->strip[3].up3[v2].data + v5) = v20;
    --v3;
  }
  while ( v3 != 0 );
}


// ========================================================================
// shift_and_clip_BD565
// EA  : 0x829100B8
// RVA : 0x009100B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall shift_and_clip_BD565(jxr_image *image, int idx, int bias, char scale, int round)
{
  int *data; // r9
  int *v6; // r4
  int *v7; // r8
  int v8; // r10
  int v9; // ctr
  char v10; // r30
  _DWORD *v11; // r29
  _DWORD *v12; // r31
  unsigned int *v13; // r11
  int v14; // r28
  int v15; // r27
  int v16; // r26
  int v17; // r8
  int v18; // r5
  unsigned int v19; // r4
  unsigned int v20; // r8
  int v21; // r9
  int v22; // r9
  int v23; // r5
  int v24; // r4
  unsigned int v25; // r8
  int v26; // r9
  int v27; // r9
  int v28; // r8
  int v29; // r4
  unsigned int v30; // r8
  unsigned int v31; // r9
  int v32; // r9
  int v33; // r8
  int v34; // r5
  int v35; // r4
  int v36; // r8
  int v37; // r9

  data = image->strip[0].up3[idx].data;
  v7 = image->strip[2].up3[idx].data;
  v8 = bias << scale;
  v9 = 64;
  v10 = scale + 1;
  v11 = data;
  v6 = image->strip[1].up3[idx].data;
  v12 = v7 + 2;
  v13 = (unsigned int *)(v6 + 1);
  v14 = (char *)data - (char *)v6;
  v15 = (char *)v7 - (char *)v6;
  v16 = (char *)data - (char *)v7;
  do
  {
    v17 = (int)(*(v13 - 1) + v8 + round) >> scale;
    v18 = (*(v12 - 2) + v8 + round) >> v10;
    if ( (v8 + *v11 + round) >> v10 <= 31 )
      v19 = (((unsigned int)(v8 + *v11 + round) >> 31) - 1) & ((v8 + *v11 + round) >> v10);
    else
      v19 = 31;
    if ( v17 <= 63 )
      v20 = (((*(v13 - 1) + v8 + round) >> 31) - 1) & v17;
    else
      v20 = 63;
    if ( v18 <= 31 )
      v21 = (((unsigned int)v18 >> 31) - 1) & v18;
    else
      v21 = 31;
    if ( (image->header_flags2 & 4) != 0 )
    {
      *v11 = v19;
      *(v13 - 1) = v20;
      *(v12 - 2) = v21;
    }
    else
    {
      *v11 = v21;
      *(v13 - 1) = v20;
      *(v12 - 2) = v19;
    }
    v22 = (int)(v8 + round + *(unsigned int *)((char *)v13 + v14)) >> v10;
    v23 = (int)(*(unsigned int *)((char *)v13 + v15) + v8 + round) >> v10;
    if ( v22 <= 31 )
      v24 = (((unsigned int)v22 >> 31) - 1) & v22;
    else
      v24 = 31;
    if ( (int)(v8 + *v13 + round) >> scale <= 63 )
      v25 = (((v8 + *v13 + round) >> 31) - 1) & ((int)(v8 + *v13 + round) >> scale);
    else
      v25 = 63;
    if ( v23 <= 31 )
      v26 = (((unsigned int)v23 >> 31) - 1) & v23;
    else
      v26 = 31;
    if ( (image->header_flags2 & 4) != 0 )
    {
      *(unsigned int *)((char *)v13 + v14) = v24;
      *v13 = v25;
      *(unsigned int *)((char *)v13 + v15) = v26;
    }
    else
    {
      *(unsigned int *)((char *)v13 + v14) = v26;
      *v13 = v25;
      *(unsigned int *)((char *)v13 + v15) = v24;
    }
    v27 = (v8 + *(_DWORD *)((char *)v12 + v16) + round) >> v10;
    v28 = (int)(v13[1] + v8 + round) >> scale;
    if ( v27 <= 31 )
      v29 = (((unsigned int)v27 >> 31) - 1) & v27;
    else
      v29 = 31;
    if ( v28 <= 63 )
      v30 = (((v13[1] + v8 + round) >> 31) - 1) & v28;
    else
      v30 = 63;
    if ( (v8 + *v12 + round) >> v10 <= 31 )
      v31 = (((unsigned int)(v8 + *v12 + round) >> 31) - 1) & ((v8 + *v12 + round) >> v10);
    else
      v31 = 31;
    if ( (image->header_flags2 & 4) != 0 )
    {
      *(_DWORD *)((char *)v12 + v16) = v29;
      v13[1] = v30;
      *v12 = v31;
    }
    else
    {
      *(_DWORD *)((char *)v12 + v16) = v31;
      v13[1] = v30;
      *v12 = v29;
    }
    v32 = (v8 + v11[3] + round) >> v10;
    v33 = (int)(v13[2] + v8 + round) >> scale;
    v34 = (v12[1] + v8 + round) >> v10;
    if ( v32 <= 31 )
      v35 = (((unsigned int)v32 >> 31) - 1) & v32;
    else
      v35 = 31;
    if ( v33 <= 63 )
      v36 = (((unsigned int)v33 >> 31) - 1) & v33;
    else
      v36 = 63;
    if ( v34 <= 31 )
      v37 = (((unsigned int)v34 >> 31) - 1) & v34;
    else
      v37 = 31;
    if ( (image->header_flags2 & 4) != 0 )
    {
      v11[3] = v35;
      v13[2] = v36;
      v12[1] = v37;
    }
    else
    {
      v11[3] = v37;
      v13[2] = v36;
      v12[1] = v35;
    }
    v11 += 4;
    v13 += 4;
    v12 += 4;
    --v9;
  }
  while ( v9 != 0 );
}


// ========================================================================
// shift_and_clip_BDxxx
// EA  : 0x829103D8
// RVA : 0x009103D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall shift_and_clip_BDxxx(
        jxr_image *image,
        int idx,
        int bias,
        char shift_bits,
        char scale,
        int round,
        int clip_low,
        int clip_hig)
{
  int *data; // r30
  int *v9; // r31
  int v10; // ctr
  int v11; // r5
  int *v12; // r27
  int *v13; // r28
  int *v14; // r11
  int v15; // r26
  int v16; // r25
  int v17; // r24
  int v18; // r31
  int v19; // r29
  int v20; // r4
  int v21; // r30
  int v22; // r31
  int v23; // r4
  int v24; // r30
  int v25; // r31
  int v26; // r31
  int v27; // r29
  int v28; // r4
  int v29; // r30
  int v30; // r31
  int v31; // r31
  int v32; // r29
  int v33; // r4
  int v34; // r30
  int v35; // r31

  data = image->strip[1].up3[idx].data;
  v9 = image->strip[2].up3[idx].data;
  v10 = 64;
  v11 = bias >> shift_bits << scale;
  v12 = image->strip[0].up3[idx].data;
  v13 = v9 + 2;
  v14 = data + 1;
  v15 = (char *)v12 - (char *)data;
  v16 = (char *)v9 - (char *)data;
  v17 = (char *)v12 - (char *)v9;
  do
  {
    v18 = (*(v14 - 1) + v11 + round) >> scale;
    v19 = (*(v13 - 2) + v11 + round) >> scale;
    v20 = (v11 + *v12 + round) >> scale << shift_bits;
    if ( v20 > clip_hig )
      v20 = clip_hig;
    if ( v20 < clip_low )
      v20 = clip_low;
    v21 = v18 << shift_bits;
    if ( v18 << shift_bits > clip_hig )
      v21 = clip_hig;
    if ( v21 < clip_low )
      v21 = clip_low;
    v22 = v19 << shift_bits;
    if ( v19 << shift_bits > clip_hig )
      v22 = clip_hig;
    if ( v22 < clip_low )
      v22 = clip_low;
    if ( (image->header_flags2 & 4) != 0 )
    {
      *v12 = v20;
      *(v14 - 1) = v21;
      *(v13 - 2) = v22;
    }
    else
    {
      *v12 = v22;
      *(v14 - 1) = v21;
      *(v13 - 2) = v20;
    }
    v23 = (v11 + *(int *)((char *)v14 + v15) + round) >> scale << shift_bits;
    if ( v23 > clip_hig )
      v23 = clip_hig;
    if ( v23 < clip_low )
      v23 = clip_low;
    v24 = (v11 + *v14 + round) >> scale << shift_bits;
    if ( v24 > clip_hig )
      v24 = clip_hig;
    if ( v24 < clip_low )
      v24 = clip_low;
    v25 = (v11 + *(int *)((char *)v14 + v16) + round) >> scale << shift_bits;
    if ( v25 > clip_hig )
      v25 = clip_hig;
    if ( v25 < clip_low )
      v25 = clip_low;
    if ( (image->header_flags2 & 4) != 0 )
    {
      *(int *)((char *)v14 + v15) = v23;
      *v14 = v24;
      *(int *)((char *)v14 + v16) = v25;
    }
    else
    {
      *(int *)((char *)v14 + v15) = v25;
      *v14 = v24;
      *(int *)((char *)v14 + v16) = v23;
    }
    v26 = (v14[1] + v11 + round) >> scale;
    v27 = (v11 + *v13 + round) >> scale;
    v28 = (*(int *)((char *)v13 + v17) + v11 + round) >> scale << shift_bits;
    if ( v28 > clip_hig )
      v28 = clip_hig;
    if ( v28 < clip_low )
      v28 = clip_low;
    v29 = v26 << shift_bits;
    if ( v26 << shift_bits > clip_hig )
      v29 = clip_hig;
    if ( v29 < clip_low )
      v29 = clip_low;
    v30 = v27 << shift_bits;
    if ( v27 << shift_bits > clip_hig )
      v30 = clip_hig;
    if ( v30 < clip_low )
      v30 = clip_low;
    if ( (image->header_flags2 & 4) != 0 )
    {
      *(int *)((char *)v13 + v17) = v28;
      v14[1] = v29;
      *v13 = v30;
    }
    else
    {
      *(int *)((char *)v13 + v17) = v30;
      v14[1] = v29;
      *v13 = v28;
    }
    v31 = (v14[2] + v11 + round) >> scale;
    v32 = (v13[1] + v11 + round) >> scale;
    v33 = (v11 + v12[3] + round) >> scale << shift_bits;
    if ( v33 > clip_hig )
      v33 = clip_hig;
    if ( v33 < clip_low )
      v33 = clip_low;
    v34 = v31 << shift_bits;
    if ( v31 << shift_bits > clip_hig )
      v34 = clip_hig;
    if ( v34 < clip_low )
      v34 = clip_low;
    v35 = v32 << shift_bits;
    if ( v32 << shift_bits > clip_hig )
      v35 = clip_hig;
    if ( v35 < clip_low )
      v35 = clip_low;
    if ( (image->header_flags2 & 4) != 0 )
    {
      v12[3] = v33;
      v14[2] = v34;
      v13[1] = v35;
    }
    else
    {
      v12[3] = v35;
      v14[2] = v34;
      v13[1] = v33;
    }
    v12 += 4;
    v14 += 4;
    v13 += 4;
    --v10;
  }
  while ( v10 != 0 );
}


// ========================================================================
// shift_and_clip_regular
// EA  : 0x829106F8
// RVA : 0x009106F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall shift_and_clip_regular(
        jxr_image *image,
        int idx,
        int bias,
        char shift_bits,
        char scale,
        int round,
        int clip_low,
        int clip_hig)
{
  int v8; // r29
  int v9; // r30
  int v10; // r4
  macroblock_s **p_up3; // r31
  int *data; // r11
  int i; // ctr
  int v14; // r5

  v8 = 0;
  if ( image->num_channels != 0 )
  {
    v9 = idx;
    v10 = bias >> shift_bits << scale;
    p_up3 = &image->strip[0].up3;
    do
    {
      data = (*p_up3)[v9].data;
      for ( i = 256; i != 0; --i )
      {
        v14 = (*data + v10 + round) >> scale << shift_bits;
        *data = v14;
        if ( v14 > clip_hig )
          *data = clip_hig;
        if ( *data < clip_low )
          *data = clip_low;
        ++data;
      }
      ++v8;
      p_up3 += 7;
    }
    while ( v8 < image->num_channels );
  }
}


// ========================================================================
// shift_and_clip_FLOAT
// EA  : 0x82910788
// RVA : 0x00910788
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall shift_and_clip_FLOAT(jxr_image *image, int idx, char scale, int round)
{
  int v4; // r28
  int v5; // r29
  macroblock_s **p_up3; // r30
  int v7; // ctr
  int *v8; // r4
  int v9; // r11
  unsigned __int8 len_mantissa; // r10
  int v11; // r10
  unsigned int v12; // r11
  int v13; // r7
  int v14; // r10
  unsigned int v15; // r11
  int v16; // r9
  int v17; // r11
  bool v18; // zf
  int v19; // r9

  v4 = 0;
  if ( image->num_channels != 0 )
  {
    v5 = idx;
    p_up3 = &image->strip[0].up3;
    do
    {
      v7 = 256;
      v8 = (*p_up3)[v5].data - 1;
      do
      {
        v9 = (v8[1] + round) >> scale;
        v8[1] = v9;
        len_mantissa = image->len_mantissa;
        if ( (image->header_flags_fmt & 0xF) == 4 )
        {
          v11 = 0;
          if ( v9 < 0 )
          {
            v11 = 1;
            v9 = -v9;
          }
          if ( v9 > 0x7FFF )
            v9 = 0x7FFF;
          v12 = (v11 << 15) & 0x7F8000 | v9;
        }
        else
        {
          v13 = v9 >> 31;
          v15 = abs32(v9);
          v16 = v15 >> len_mantissa;
          v18 = v15 >> len_mantissa != 0;
          v14 = 1 << len_mantissa;
          v17 = (v14 - 1) & v15 | v14;
          if ( !v18 )
          {
            v17 ^= v14;
            v16 = 1;
          }
          v19 = v16 - image->exp_bias + 127;
          if ( v17 >= v14 )
            goto LABEL_16;
          while ( v19 > 1 && v17 > 0 )
          {
            v17 *= 2;
            --v19;
            if ( v17 >= v14 )
              goto LABEL_16;
          }
          if ( v17 >= v14 )
LABEL_16:
            v17 ^= v14;
          else
            v19 = 0;
          v12 = (v17 << (23 - image->len_mantissa)) | (v19 << 23) | v13 & 0x80000000;
        }
        *++v8 = v12;
        --v7;
      }
      while ( v7 != 0 );
      ++v4;
      p_up3 += 7;
    }
    while ( v4 < image->num_channels );
  }
}


// ========================================================================
// shift_and_clip_RGBE
// EA  : 0x829108C8
// RVA : 0x009108C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall shift_and_clip_RGBE(jxr_image *image, int idx, char scale, int round, int *buffer)
{
  int *data; // r11
  int *v6; // r28
  int v7; // r27
  char *v8; // r26
  char *v9; // r25
  int i; // ctr
  int v11; // r10
  int v12; // r9
  int v13; // r31
  int *v14; // r11
  int v15; // r29
  int v16; // r30
  int v17; // r4
  int v18; // r10

  data = image->strip[1].up3[idx].data;
  v6 = data;
  v7 = 0;
  v8 = (char *)((char *)image->strip[0].up3[idx].data - (char *)data);
  v9 = (char *)((char *)image->strip[2].up3[idx].data - (char *)data);
  for ( i = 256; i != 0; --i )
  {
    v11 = (*(int *)((char *)v6 + (_DWORD)v8) + round) >> scale;
    v12 = (*v6 + round) >> scale;
    v13 = (*(int *)((char *)v6 + (_DWORD)v9) + round) >> scale;
    v14 = &buffer[(image->num_channels + 1) * v7];
    if ( v11 > 0 )
    {
      if ( v11 >> 7 <= 1 )
      {
        v15 = 1;
      }
      else
      {
        v15 = v11 >> 7;
        v11 = (v11 & 0x7F) + 128;
      }
      *v14 = v11;
    }
    else
    {
      v15 = 0;
      *v14 = 0;
    }
    if ( v12 > 0 )
    {
      if ( v12 >> 7 <= 1 )
      {
        v16 = 1;
        v14[1] = v12;
      }
      else
      {
        v16 = v12 >> 7;
        v14[1] = (v12 & 0x7F) + 128;
      }
    }
    else
    {
      v16 = 0;
      v14[1] = 0;
    }
    if ( v13 > 0 )
    {
      if ( v13 >> 7 <= 1 )
      {
        v17 = 1;
        v14[2] = v13;
      }
      else
      {
        v17 = v13 >> 7;
        v14[2] = (v13 & 0x7F) + 128;
      }
    }
    else
    {
      v17 = 0;
      v14[2] = 0;
    }
    if ( v15 <= v16 )
    {
      v18 = v16;
      if ( v16 <= v17 )
        v18 = v17;
    }
    else if ( v15 <= v17 )
    {
      v18 = v17;
    }
    else
    {
      v18 = v15;
    }
    v14[3] = v18;
    if ( v18 > v15 )
      *v14 = (unsigned __int8)((2 * *v14 + 1) >> (v18 - v15 + 1));
    if ( v18 > v16 )
      v14[1] = (unsigned __int8)((2 * v14[1] + 1) >> (v18 - v16 + 1));
    if ( v18 > v17 )
      v14[2] = (unsigned __int8)((2 * v14[2] + 1) >> (v18 - v17 + 1));
    ++v7;
    ++v6;
  }
}


// ========================================================================
// rflush_to_tile_buffer
// EA  : 0x82910AA0
// RVA : 0x00910AA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall rflush_to_tile_buffer(jxr_image *image, int tx, int my)
{
  int use_clr_fmt; // r11
  int v4; // r30
  int v5; // r7
  signed int i; // r8
  int v7; // r6
  unsigned int v8; // r31
  int v9; // r9
  macroblock_s *v10; // r10
  int v11; // r4
  int v12; // r11
  int j; // ctr

  use_clr_fmt = image->use_clr_fmt;
  v4 = 256;
  if ( use_clr_fmt == 2 )
  {
    v4 = 136;
  }
  else if ( use_clr_fmt == 1 )
  {
    v4 = 76;
  }
  v5 = tx;
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
        *((_BYTE *)v10 + 8) = *(_BYTE *)(84 * (image->tile_column_position[v5] + i)
                                       + *(int *)((char *)&image->user_flags + v9)
                                       + 8);
        *((_BYTE *)v10 + 9) = *(_WORD *)(84 * (image->tile_column_position[v5] + i)
                                       + *(int *)((char *)&image->user_flags + v9)
                                       + 8);
        if ( v7 != 0 )
          v11 = v4;
        else
          v11 = 256;
        v12 = 0;
        for ( j = v11; j != 0; --j )
        {
          v10->data[v12] = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                                 + *(int *)((char *)&image->user_flags + v9))
                                     + v12 * 4);
          ++v12;
        }
        ++v7;
      }
      while ( v7 < image->num_channels );
    }
  }
}


// ========================================================================
// rflush_collect_mb_strip_data
// EA  : 0x82910BE8
// RVA : 0x00910BE8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall rflush_collect_mb_strip_data(jxr_image *image, int my)
{
  int use_clr_fmt; // r11
  int v3; // r30
  signed int v4; // r29
  int v5; // r7
  signed int i; // r8
  int v7; // r6
  unsigned int v8; // r31
  int v9; // r9
  macroblock_s *v10; // r11
  int v11; // r5
  int v12; // r10
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
  if ( (signed int)(image->tile_columns - 1) > 0 )
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
            *(_BYTE *)(84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9) + 8) = *((_BYTE *)v10 + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v5] + i) + *(int *)((char *)&image->user_flags + v9) + 9) = *((_WORD *)v10 + 4);
            if ( v7 != 0 )
              v11 = v3;
            else
              v11 = 256;
            v12 = 0;
            for ( j = v11; j != 0; --j )
            {
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v5] + i)
                                    + *(int *)((char *)&image->user_flags + v9))
                        + v12 * 4) = v10->data[v12];
              ++v12;
            }
            ++v7;
          }
          while ( v7 < image->num_channels );
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < (signed int)(image->tile_columns - 1) );
  }
}


// ========================================================================
// rflush_save_context
// EA  : 0x82910D58
// RVA : 0x00910D58
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall rflush_save_context(jxr_image *image)
{
  int use_clr_fmt; // r11
  int v2; // r26
  signed int v3; // r25
  int v4; // r9
  signed int i; // r10
  int v6; // r6
  unsigned int v7; // r11
  unsigned int v8; // r8
  unsigned int v9; // r7
  unsigned int v10; // r5
  unsigned int v11; // r11
  int v12; // r30
  int v13; // r29
  int v14; // r28
  int v15; // r27
  int v16; // r7
  int v17; // r11
  int *v18; // r8
  int v19; // r31
  int v20; // r5
  int j; // ctr
  int v22; // r7
  int k; // ctr
  int v24; // r7
  int m; // ctr
  int v26; // r7
  int n; // ctr

  use_clr_fmt = image->use_clr_fmt;
  v2 = 256;
  if ( use_clr_fmt == 2 )
  {
    v2 = 136;
  }
  else if ( use_clr_fmt == 1 )
  {
    v2 = 76;
  }
  v3 = 0;
  if ( (int)image->tile_columns > 0 )
  {
    v4 = 0;
    do
    {
      for ( i = 0; i < (signed int)image->tile_column_width[v4]; ++i )
      {
        v6 = 0;
        v7 = image->extended_width >> 4;
        v8 = image->tile_column_position[v4] + i;
        v9 = v7 + v8;
        v10 = v7 + v7 + v8;
        v11 = v7 + v10;
        if ( image->num_channels != 0 )
        {
          v12 = 84 * v8;
          v13 = 84 * v9;
          v14 = 84 * v10;
          v15 = 84 * v11;
          do
          {
            v16 = 28 * (v6 + 5);
            v17 = 4 * (v6 + 159);
            *(_BYTE *)(v12 + *(int *)((char *)&image->user_flags + v17) + 8) = *(_BYTE *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + *(int *)((char *)&image->user_flags
                                                                                                 + v16)
                                                                                        + 8);
            v18 = &image->user_flags + 7 * v6;
            *(_BYTE *)(v13 + *(int *)((char *)&image->user_flags + v17) + 8) = *(_BYTE *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + v18[34]
                                                                                        + 8);
            *(_BYTE *)(v14 + *(int *)((char *)&image->user_flags + v17) + 8) = *(_BYTE *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + v18[33]
                                                                                        + 8);
            *(_BYTE *)(v15 + *(int *)((char *)&image->user_flags + v17) + 8) = *(_BYTE *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + v18[32]
                                                                                        + 8);
            *(_BYTE *)(v12 + *(int *)((char *)&image->user_flags + v17) + 9) = *(_WORD *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + *(int *)((char *)&image->user_flags
                                                                                                 + v16)
                                                                                        + 8);
            *(_BYTE *)(v13 + *(int *)((char *)&image->user_flags + v17) + 9) = *(_WORD *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + v18[34]
                                                                                        + 8);
            *(_BYTE *)(v14 + *(int *)((char *)&image->user_flags + v17) + 9) = *(_WORD *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + v18[33]
                                                                                        + 8);
            *(_BYTE *)(v15 + *(int *)((char *)&image->user_flags + v17) + 9) = *(_WORD *)(84
                                                                                        * (image->tile_column_position[v4]
                                                                                         + i)
                                                                                        + v18[32]
                                                                                        + 8);
            if ( v6 != 0 )
              v19 = v2;
            else
              v19 = 256;
            v20 = 0;
            for ( j = v19; j != 0; --j )
            {
              *(_DWORD *)(*(_DWORD *)(v12 + *(int *)((char *)&image->user_flags + v17)) + v20) = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i) + *(int *)((char *)&image->user_flags + v16)) + v20);
              v20 += 4;
            }
            v22 = 0;
            for ( k = v19; k != 0; --k )
            {
              *(_DWORD *)(*(_DWORD *)(v13 + *(int *)((char *)&image->user_flags + v17)) + v22) = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i) + v18[34]) + v22);
              v22 += 4;
            }
            v24 = 0;
            for ( m = v19; m != 0; --m )
            {
              *(_DWORD *)(*(_DWORD *)(v14 + *(int *)((char *)&image->user_flags + v17)) + v24) = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i) + v18[33]) + v24);
              v24 += 4;
            }
            v26 = 0;
            for ( n = v19; n != 0; --n )
            {
              *(_DWORD *)(*(_DWORD *)(v15 + *(int *)((char *)&image->user_flags + v17)) + v26) = *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i) + v18[32]) + v26);
              v26 += 4;
            }
            ++v6;
          }
          while ( v6 < image->num_channels );
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < (signed int)image->tile_columns );
  }
}


// ========================================================================
// rflush_recover_context
// EA  : 0x82911080
// RVA : 0x00911080
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall rflush_recover_context(jxr_image *image)
{
  int use_clr_fmt; // r11
  int v2; // r26
  signed int v3; // r25
  int v4; // r9
  signed int i; // r10
  int v6; // r6
  unsigned int v7; // r11
  unsigned int v8; // r8
  unsigned int v9; // r7
  unsigned int v10; // r5
  unsigned int v11; // r11
  int v12; // r30
  int v13; // r29
  int v14; // r28
  int v15; // r27
  int v16; // r11
  int v17; // r7
  int *v18; // r8
  int v19; // r31
  int v20; // r5
  int j; // ctr
  int v22; // r7
  int k; // ctr
  int v24; // r7
  int m; // ctr
  int v26; // r7
  int n; // ctr

  use_clr_fmt = image->use_clr_fmt;
  v2 = 256;
  if ( use_clr_fmt == 2 )
  {
    v2 = 136;
  }
  else if ( use_clr_fmt == 1 )
  {
    v2 = 76;
  }
  v3 = 0;
  if ( (int)image->tile_columns > 0 )
  {
    v4 = 0;
    do
    {
      for ( i = 0; i < (signed int)image->tile_column_width[v4]; ++i )
      {
        v6 = 0;
        v7 = image->extended_width >> 4;
        v8 = image->tile_column_position[v4] + i;
        v9 = v7 + v8;
        v10 = v7 + v7 + v8;
        v11 = v7 + v10;
        if ( image->num_channels != 0 )
        {
          v12 = 84 * v8;
          v13 = 84 * v9;
          v14 = 84 * v10;
          v15 = 84 * v11;
          do
          {
            v16 = 4 * (v6 + 159);
            v17 = 28 * (v6 + 5);
            v18 = &image->user_flags + 7 * v6;
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + *(int *)((char *)&image->user_flags + v17) + 8) = *(_BYTE *)(v12 + *(int *)((char *)&image->user_flags + v16) + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + v18[34] + 8) = *(_BYTE *)(v13
                                                                                            + *(int *)((char *)&image->user_flags + v16)
                                                                                            + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + v18[33] + 8) = *(_BYTE *)(v14
                                                                                            + *(int *)((char *)&image->user_flags + v16)
                                                                                            + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + v18[32] + 8) = *(_BYTE *)(v15
                                                                                            + *(int *)((char *)&image->user_flags + v16)
                                                                                            + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + *(int *)((char *)&image->user_flags + v17) + 9) = *(_WORD *)(v12 + *(int *)((char *)&image->user_flags + v16) + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + v18[34] + 9) = *(_WORD *)(v13
                                                                                            + *(int *)((char *)&image->user_flags + v16)
                                                                                            + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + v18[33] + 9) = *(_WORD *)(v14
                                                                                            + *(int *)((char *)&image->user_flags + v16)
                                                                                            + 8);
            *(_BYTE *)(84 * (image->tile_column_position[v4] + i) + v18[32] + 9) = *(_WORD *)(v15
                                                                                            + *(int *)((char *)&image->user_flags + v16)
                                                                                            + 8);
            if ( v6 != 0 )
              v19 = v2;
            else
              v19 = 256;
            v20 = 0;
            for ( j = v19; j != 0; --j )
            {
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i)
                                    + *(int *)((char *)&image->user_flags + v17))
                        + v20) = *(_DWORD *)(*(_DWORD *)(v12 + *(int *)((char *)&image->user_flags + v16)) + v20);
              v20 += 4;
            }
            v22 = 0;
            for ( k = v19; k != 0; --k )
            {
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i) + v18[34]) + v22) = *(_DWORD *)(*(_DWORD *)(v13 + *(int *)((char *)&image->user_flags + v16)) + v22);
              v22 += 4;
            }
            v24 = 0;
            for ( m = v19; m != 0; --m )
            {
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i) + v18[33]) + v24) = *(_DWORD *)(*(_DWORD *)(v14 + *(int *)((char *)&image->user_flags + v16)) + v24);
              v24 += 4;
            }
            v26 = 0;
            for ( n = v19; n != 0; --n )
            {
              *(_DWORD *)(*(_DWORD *)(84 * (image->tile_column_position[v4] + i) + v18[32]) + v26) = *(_DWORD *)(*(_DWORD *)(v15 + *(int *)((char *)&image->user_flags + v16)) + v26);
              v26 += 4;
            }
            ++v6;
          }
          while ( v6 < image->num_channels );
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < (signed int)image->tile_columns );
  }
}


// ========================================================================
// ?_jxr_rcollect_tile_mb_rows@@YAHPAUjxr_image@@HHH@Z
// EA  : 0x829113A8
// RVA : 0x009113A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

int __fastcall _jxr_rcollect_tile_mb_rows(jxr_image *image, int tx, int ty, int my)
{
  unsigned int tile_columns; // r11
  int cur_my; // r5
  jxr_image *v7; // r3
  jxr_image *v8; // r3
  jxr_image *v10; // r3

  tile_columns = image->tile_columns;
  if ( tile_columns > 1 && tx >= 0 )
  {
    if ( tx + 1 < (int)tile_columns )
    {
      cur_my = image->cur_my;
      if ( cur_my >= 0 )
      {
        if ( my == 0 )
        {
          if ( tx == 0 )
          {
            if ( ty > 0 )
            {
              rflush_collect_mb_strip_data(image, my: image->cur_my);
              rflush_save_context(image: v7);
              rflush_to_tile_buffer(image: v8, tx: v8->tile_columns - 1, my: v8->cur_my);
              return 0;
            }
            return 0;
          }
          --tx;
        }
        rflush_to_tile_buffer(image, tx, my: cur_my);
      }
      return 0;
    }
    if ( my != 0 )
    {
      if ( my <= (signed int)image->tile_row_height[ty] )
        rflush_collect_mb_strip_data(image, my: image->cur_my);
    }
    else
    {
      rflush_to_tile_buffer(image, tx: tx - 1, my: image->cur_my);
      v10->cur_my = -1;
      if ( ty > 0 )
        rflush_recover_context(image: v10);
    }
  }
  return 1;
}


// ========================================================================
// unblock_shuffle444
// EA  : 0x829114B8
// RVA : 0x009114B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall unblock_shuffle444(int *data)
{
  unsigned int v1; // r10
  int *v2; // r11
  int i; // ctr
  int v4; // r5
  int v5; // r4
  int v6; // r30
  int v7; // r9
  int v8; // r8
  _BYTE v9[1072]; // [sp+50h] [-430h] BYREF

  v1 = 0;
  v2 = data - 1;
  for ( i = 64; i != 0; --i )
  {
    v4 = v2[1];
    v5 = v2[2];
    v6 = v2[3];
    v2 += 4;
    v7 = *v2;
    v8 = 16 * (4 * (4 * (v1 >> 6) + (((int)v1 >> 2) & 3)) + (v1 >> 4) - 4 * (v1 >> 6));
    v1 += 4;
    *(_DWORD *)&v9[v8] = v4;
    *(_DWORD *)&v9[v8 + 4] = v5;
    *(_DWORD *)&v9[v8 + 8] = v6;
    *(_DWORD *)&v9[v8 + 12] = v7;
  }
  blkmov(a1: data, a2: v9, a3: 1024);
}


// ========================================================================
// ?_jxr_r_rotate_mb_strip@@YAXPAUjxr_image@@H@Z
// EA  : 0x82911558
// RVA : 0x00911558
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall _jxr_r_rotate_mb_strip(jxr_image *image, int my)
{
  int num_channels; // r11
  int v3; // r10
  unsigned int *p_num_lp_qps; // r11
  unsigned int v5; // r8
  unsigned int v6; // r7
  unsigned int v7; // r6

  num_channels = image->num_channels;
  v3 = 0;
  image->cur_my = my;
  if ( num_channels != 0 )
  {
    p_num_lp_qps = &image->num_lp_qps;
    do
    {
      ++v3;
      v5 = p_num_lp_qps[6];
      v6 = p_num_lp_qps[7];
      v7 = p_num_lp_qps[4];
      p_num_lp_qps[4] = p_num_lp_qps[5];
      p_num_lp_qps[5] = v5;
      p_num_lp_qps[6] = v6;
      p_num_lp_qps += 7;
      *p_num_lp_qps = v7;
    }
    while ( v3 < image->num_channels );
  }
  _jxr_clear_strip_cur(image);
}


// ========================================================================
// IPCT_level2_up2
// EA  : 0x829115A8
// RVA : 0x009115A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall IPCT_level2_up2(jxr_image *image, int use_my, int ch)
{
  int v4; // r22
  int use_clr_fmt; // r11
  signed int v6; // r23
  char *v7; // r29
  int v8; // r24
  int v9; // r31
  int v10; // r3
  int v11; // r7
  _DWORD *v12; // r11
  _DWORD *v13; // r6
  int i; // r5
  _DWORD *v15; // r8
  _DWORD *v16; // r11
  int v17; // ctr
  _DWORD *v18; // r10
  int v19; // r30
  int v20; // r27
  int v21; // r28
  unsigned int v22; // r26
  int v23; // r10
  int v24; // r11
  int j; // ctr
  int v26; // r3
  int v27; // r4
  int v28; // r21
  int v29; // r5
  _BYTE v30[1120]; // [sp+50h] [-460h] BYREF

  v4 = 16;
  if ( use_my > 0 )
  {
    use_clr_fmt = image->use_clr_fmt;
    if ( use_clr_fmt == 2 )
    {
      v4 = 8;
    }
    else if ( use_clr_fmt == 1 )
    {
      v4 = 4;
    }
  }
  v6 = 0;
  if ( image->extended_width >> 4 != 0 )
  {
    v7 = (char *)image + 28 * use_my;
    v8 = 16 * v4;
    v9 = 0;
    do
    {
      v10 = *(_DWORD *)(v9 + *((_DWORD *)v7 + 33));
      v11 = v10 + 64;
      v12 = v30;
      v13 = (_DWORD *)(v10 - 4);
      for ( i = v4; i != 0; --i )
      {
        ++v13;
        v15 = (_DWORD *)(v11 - 4);
        *v12 = *v13;
        v16 = v12 + 1;
        v17 = 15;
        v18 = v16 - 1;
        do
        {
          *++v18 = *++v15;
          --v17;
        }
        while ( v17 != 0 );
        v11 += 60;
        v12 = v16 + 15;
      }
      blkmov(a1: v10, a2: v30, a3: 1024);
      v19 = _jxr_quant_map(
              image,
              x: *(unsigned __int8 *)(84 * (*image->tile_column_position + v6) + *((_DWORD *)v7 + 33) + 9),
              shift: 1);
      if ( v8 > 0 )
      {
        v20 = 0;
        v21 = 3;
        v22 = ((unsigned int)(v8 - 1) >> 4) + 1;
        do
        {
          v23 = 1;
          v24 = v20 + 4;
          for ( j = 3; j != 0; --j )
          {
            v26 = 4 * (v21 + v23);
            v27 = 4 * (v21 - 1 + v23);
            v28 = 4 * (v21 + 1 + v23);
            v23 += 5;
            *(_DWORD *)(v24 + *(_DWORD *)(v9 + *((_DWORD *)v7 + 33))) *= v19;
            v29 = v24 + *(_DWORD *)(v9 + *((_DWORD *)v7 + 33));
            v24 += 20;
            *(_DWORD *)(v29 + 4) *= v19;
            *(_DWORD *)(v27 + *(_DWORD *)(v9 + *((_DWORD *)v7 + 33))) *= v19;
            *(_DWORD *)(v26 + *(_DWORD *)(v9 + *((_DWORD *)v7 + 33))) *= v19;
            *(_DWORD *)(v28 + *(_DWORD *)(v9 + *((_DWORD *)v7 + 33))) *= v19;
          }
          _jxr_4x4IPCT(coeff: (int *)(*(_DWORD *)(v9 + *((_DWORD *)v7 + 33)) + v20));
          --v22;
          v21 += 16;
          v20 += 64;
        }
        while ( v22 != 0 );
      }
      ++v6;
      v9 += 84;
    }
    while ( v6 < (signed int)(image->extended_width >> 4) );
  }
}


// ========================================================================
// scale_and_emit_mb
// EA  : 0x829117B0
// RVA : 0x009117B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall scale_and_emit_mb(jxr_image *image, int use_my, int mx)
{
  char shift_bits; // r22
  int v6; // r31
  int v8; // r23
  char v9; // r25
  int v10; // r26
  int v11; // r21
  int v12; // r24
  int v13; // r27
  macroblock_s **p_up3; // r20
  int v15; // r30
  macroblock_s **v16; // r31
  int use_clr_fmt; // r11
  int *data; // r3
  unsigned int v19; // r10
  int *v20; // r11
  int j; // ctr
  int v22; // r5
  int v23; // r4
  int v24; // r16
  int v25; // r9
  int v26; // r8
  int v27; // r5
  unsigned int v28; // r10
  int *v29; // r11
  int i; // ctr
  int v31; // r5
  int v32; // r4
  int v33; // r16
  int v34; // r9
  int v35; // r8
  int v36; // r11
  int k; // r31
  int v38; // r17
  int v39; // r30
  int v40; // r16
  int v41; // r15
  int v42; // r15
  int v43; // r17
  int v44; // r11
  int v45; // r11
  macroblock_s **v46; // r8
  int v47; // r9
  int m; // r7
  int *v49; // r11
  int n; // ctr
  int v51; // r5
  int *v52; // r11
  int ii; // ctr
  int v54; // r6
  int v55; // r11
  int num_channels; // r4
  int v57; // r3
  int v58; // r30
  int v59; // r5
  int jj; // r6
  int v61; // r11
  int v62; // r8
  unsigned __int16 *p_window_extra_bottom; // r10
  int v64; // r31
  jxr_image *alpha; // r8
  int v66; // r9
  int v67; // r11
  int v68; // r10
  int v69; // r5
  int v70; // ctr
  int v71; // r6
  int v72; // r7
  int v73; // r27
  int v74; // r25
  int v75; // r24
  int v76; // r22
  int v77; // r4
  _BYTE v78[512]; // [sp+50h] [-46A0h] BYREF
  _QWORD v79[2196]; // [sp+250h] [-44A0h] BYREF

  shift_bits = image->shift_bits;
  v6 = *((_DWORD *)image + 26) >> 31;
  v8 = 0;
  v9 = v6 == 0 ? 0 : 3;
  v10 = 255;
  memset(Dst: v79, Val: 0, Size: 0x4400u);
  v11 = 0;
  switch ( image->header_flags_fmt & 0xF )
  {
    case 0:
    case 0xF:
      v12 = 4 * v6;
      v10 = 1;
      goto LABEL_12;
    case 1:
      v13 = 128;
      v12 = v6 == 0 ? 0 : 3;
      v10 = 255;
      goto LABEL_13;
    case 2:
      v13 = 0x8000;
      v12 = 4 * v6;
      v10 = 0xFFFF;
      goto LABEL_13;
    case 3:
      v13 = 0;
      v12 = v6 == 0 ? 0 : 3;
      v8 = -32768;
      v10 = 0x7FFF;
      goto LABEL_14;
    case 4:
    case 7:
      v13 = 0;
      v12 = v6 == 0 ? 0 : 3;
      goto LABEL_14;
    case 6:
      v13 = 0;
      v12 = v6 == 0 ? 0 : 3;
      v10 = 0x7FFFFFFF;
      v8 = 0x80000000;
      goto LABEL_14;
    case 8:
      v13 = 16;
      v12 = v6 == 0 ? 0 : 3;
      v10 = 31;
      goto LABEL_13;
    case 9:
      v13 = 512;
      v12 = v6 == 0 ? 0 : 3;
      v10 = 1023;
      goto LABEL_13;
    case 0xA:
      v13 = 32;
      v12 = v6 == 0 ? 0 : 3;
      v10 = 31;
      goto LABEL_13;
    default:
      v12 = v6 == 0 ? 0 : 3;
      v10 = 255;
LABEL_12:
      v13 = 0;
LABEL_13:
      v8 = 0;
LABEL_14:
      p_up3 = &image->strip[0].up3;
      unblock_shuffle444(data: image->strip[0].up3[mx].data);
      v15 = 1;
      if ( image->num_channels <= 1u )
        goto LABEL_27;
      v16 = &image->strip[1].up3;
      break;
  }
  do
  {
    use_clr_fmt = image->use_clr_fmt;
    data = (*v16)[mx].data;
    if ( use_clr_fmt == 1 )
    {
      v28 = 0;
      v29 = data - 1;
      for ( i = 16; i != 0; --i )
      {
        v31 = v29[1];
        v32 = v29[2];
        v33 = v29[3];
        v29 += 4;
        v34 = *v29;
        v35 = 16 * (2 * (4 * (v28 >> 5) + (((int)v28 >> 2) & 3)) + (v28 >> 4) - 2 * (v28 >> 5));
        v28 += 4;
        *(_DWORD *)&v78[v35] = v31;
        *(_DWORD *)&v78[v35 + 4] = v32;
        *(_DWORD *)&v78[v35 + 8] = v33;
        *(_DWORD *)&v78[v35 + 12] = v34;
      }
      v27 = 256;
    }
    else
    {
      if ( use_clr_fmt != 2 )
      {
        unblock_shuffle444(data);
        goto LABEL_26;
      }
      v19 = 0;
      v20 = data - 1;
      for ( j = 32; j != 0; --j )
      {
        v22 = v20[1];
        v23 = v20[2];
        v24 = v20[3];
        v20 += 4;
        v25 = *v20;
        v26 = 16 * (2 * (4 * (v19 >> 5) + (((int)v19 >> 2) & 3)) + (v19 >> 4) - 2 * (v19 >> 5));
        v19 += 4;
        *(_DWORD *)&v78[v26] = v22;
        *(_DWORD *)&v78[v26 + 4] = v23;
        *(_DWORD *)&v78[v26 + 8] = v24;
        *(_DWORD *)&v78[v26 + 12] = v25;
      }
      v27 = 512;
    }
    blkmov(a1: data, a2: v78, a3: v27);
LABEL_26:
    ++v15;
    v16 += 7;
  }
  while ( v15 < image->num_channels );
LABEL_27:
  v36 = image->header_flags_fmt >> 4;
  if ( v36 != 1 && v36 != 2 && v36 != 3 && v36 != 5 )
  {
    if ( (unsigned int)image->use_clr_fmt - 1 > 3 )
      goto LABEL_49;
    if ( image->use_clr_fmt == 2 )
    {
      yuv422_to_yuv444(image, mx);
      yuv444_to_rgb(image, mx);
      goto LABEL_49;
    }
    if ( image->use_clr_fmt != 3 )
    {
      if ( image->use_clr_fmt != 1 )
      {
        for ( k = 0; k < 256; ++k )
        {
          v38 = (*p_up3)[mx].data[k];
          v39 = image->strip[1].up3[mx].data[k];
          v40 = image->strip[2].up3[mx].data[k];
          v41 = image->strip[3].up3[mx].data[k];
          v42 = _jxr_floor_div2(x: v38) + v41;
          v43 = v42 - v38 - _jxr_floor_div2(x: v39);
          v44 = _jxr_floor_div2(x: v40) + v43 + v39;
          (*p_up3)[mx].data[k] = v44;
          image->strip[1].up3[mx].data[k] = v43;
          image->strip[2].up3[mx].data[k] = v44 - v40;
          image->strip[3].up3[mx].data[k] = v42;
        }
        goto LABEL_49;
      }
      yuv420_to_yuv444(image, use_my, mx);
    }
    yuv444_to_rgb(image, mx);
    goto LABEL_49;
  }
  v11 = 1;
  if ( v36 == 5 && image->primary != 0 )
  {
    yuvk_to_cmykdirect(image, mx);
  }
  else if ( v36 == 3 )
  {
    v45 = image->use_clr_fmt;
    if ( v45 == 1 )
    {
      yuv420_to_yuv444(image, use_my, mx);
    }
    else if ( v45 == 2 )
    {
      yuv422_to_yuv444(image, mx);
    }
  }
LABEL_49:
  if ( image->use_clr_fmt != 4 || (image->header_flags_fmt & 0xF0) == 0x50 )
  {
    v55 = image->header_flags_fmt & 0xF;
    if ( v55 != 10 )
    {
      if ( v11 == 0 && (v55 == 8 || v55 == 9) )
      {
        if ( image->num_channels != 1 )
        {
          shift_and_clip_BDxxx(
            image,
            idx: mx,
            bias: v13,
            shift_bits,
            scale: v9,
            round: v12,
            clip_low: v8,
            clip_hig: v10);
          goto LABEL_82;
        }
      }
      else
      {
        if ( v55 == 4 || v55 == 7 )
        {
          shift_and_clip_FLOAT(image, idx: mx, scale: v9, round: v12);
          goto LABEL_82;
        }
        if ( (image->header_flags_fmt & 0xF0) == 0x80 )
        {
          shift_and_clip_RGBE(image, idx: mx, scale: v9, round: v12, buffer: (int *)v79);
          goto LABEL_82;
        }
      }
      shift_and_clip_regular(image, idx: mx, bias: v13, shift_bits, scale: v9, round: v12, clip_low: v8, clip_hig: v10);
      goto LABEL_82;
    }
    if ( image->num_channels == 1 )
      shift_and_clip_regular(image, idx: mx, bias: v13, shift_bits, scale: v9, round: v12, clip_low: 0, clip_hig: 63);
    else
      shift_and_clip_BD565(image, idx: mx, bias: v13, scale: v9, round: v12);
  }
  else
  {
    v46 = &image->strip[0].up3;
    v47 = v13 >> (shift_bits + 1) << v9;
    for ( m = 3; m != 0; --m )
    {
      v49 = (*v46)[mx].data;
      for ( n = 256; n != 0; --n )
      {
        v51 = (v47 + *v49 + v12) >> v9 << shift_bits;
        *v49 = v51;
        if ( v51 > v10 )
          *v49 = v10;
        if ( *v49 < v8 )
          *v49 = v8;
        ++v49;
      }
      v46 += 7;
    }
    v52 = image->strip[3].up3[mx].data;
    for ( ii = 256; ii != 0; --ii )
    {
      v54 = (*v52 - v47 + v12) >> v9 << shift_bits;
      *v52 = v54;
      if ( v54 > v10 )
        *v52 = v10;
      if ( *v52 < v8 )
        *v52 = v8;
      ++v52;
    }
  }
LABEL_82:
  if ( image->primary == 1 )
  {
    num_channels = image->num_channels;
    v57 = image->header_flags2 & 1;
    v58 = (unsigned __int8)num_channels;
    if ( (image->header_flags2 & 1) != 0 )
      v58 = (unsigned __int8)num_channels + 1;
    if ( (image->header_flags_fmt & 0xF0) != 0x80 )
    {
      v59 = 0;
      for ( jj = 0; jj < 1024; jj += 4 )
      {
        v61 = 0;
        if ( num_channels > 0 )
        {
          v62 = image->num_channels;
          p_window_extra_bottom = &image->window_extra_bottom;
          do
          {
            p_window_extra_bottom += 14;
            v64 = 4 * (v59 + v61++);
            *(_DWORD *)((char *)v79 + v64) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)p_window_extra_bottom + 84 * mx) + jj);
          }
          while ( v61 < v62 );
        }
        v59 += v58;
      }
    }
    if ( v57 != 0 )
    {
      alpha = image->alpha;
      v66 = image->num_channels;
      v67 = 0;
      v68 = 0;
      v69 = 4 * v58;
      v70 = 64;
      v71 = 3 * v58;
      v72 = 2 * v58;
      do
      {
        v73 = 4 * (v66 + v68);
        v74 = 4 * (v66 + v68 + v58);
        v75 = 4 * (v66 + v72);
        v76 = 4 * (v66 + v71);
        v68 += v69;
        v72 += v69;
        *(_DWORD *)((char *)v79 + v73) = alpha->strip[0].up3[mx].data[v67];
        v71 += v69;
        *(_DWORD *)((char *)v79 + v74) = alpha->strip[0].up3[mx].data[v67 + 1];
        *(_DWORD *)((char *)v79 + v75) = alpha->strip[0].up3[mx].data[v67 + 2];
        v77 = alpha->strip[0].up3[mx].data[v67 + 3];
        v67 += 4;
        *(_DWORD *)((char *)v79 + v76) = v77;
        --v70;
      }
      while ( v70 != 0 );
    }
    _jxr_send_mb_to_output(image, mx, my: use_my - 3, data: (int *)v79);
    image->output_sent = 1;
  }
}


// ========================================================================
// ?_jxr_output_mb_id_mono@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x82911F90
// RVA : 0x00911F90
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall _jxr_output_mb_id_mono(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  int v4; // r30
  int v9; // r9
  unsigned __int8 *v10; // r10
  int v11; // r11
  int i; // ctr
  int v13; // r8

  v4 = mx;
  unblock_shuffle444(data: image->strip[0].up3[mx].data);
  shift_and_clip_regular(
    image,
    idx: mx,
    bias: 128,
    shift_bits: image->shift_bits,
    scale: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    round: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    clip_low: 0,
    clip_hig: 255);
  v10 = buffer;
  do
  {
    v11 = 0;
    for ( i = 4; i != 0; --i )
    {
      v13 = v9 + v11;
      v10[v11] = image->strip[0].up3[v4].data[v13];
      v10[v11 + 1] = image->strip[0].up3[v4].data[v13 + 1];
      v10[v11 + 2] = image->strip[0].up3[v4].data[v9 + 2 + v11];
      v10[v11 + 3] = image->strip[0].up3[v4].data[v9 + 3 + v11];
      v11 += 4;
    }
    v9 += 16;
    v10 += byteStride;
  }
  while ( v9 < 256 );
}


// ========================================================================
// ?_jxr_output_mb_id_grayscale@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x82912098
// RVA : 0x00912098
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall _jxr_output_mb_id_grayscale(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  int v4; // r30
  int v9; // r8
  int i; // r6
  int v11; // r10
  int j; // ctr
  int v13; // r7
  unsigned __int8 *v14; // r11
  int v15; // r27
  int v16; // r26
  int v17; // r24
  int v18; // r4
  int v19; // r27
  unsigned __int8 v20; // r5

  v4 = mx;
  unblock_shuffle444(data: image->strip[0].up3[mx].data);
  shift_and_clip_regular(
    image,
    idx: mx,
    bias: 128,
    shift_bits: image->shift_bits,
    scale: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    round: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    clip_low: 0,
    clip_hig: 255);
  v9 = 0;
  for ( i = 0; i < 256; i += 16 )
  {
    v11 = 0;
    for ( j = 4; j != 0; --j )
    {
      v13 = 4 * (i + v11);
      v14 = &buffer[4 * v9 + 4 * v11];
      v15 = *(int *)((char *)image->strip[0].up3[v4].data + v13);
      v16 = i + v11 + 2;
      v14[3] = -1;
      v17 = 4 * (v9 + v11 + 3);
      *v14 = v15;
      v14[1] = v15;
      v18 = 4 * (v9 + v11 + 2);
      v14[2] = v15;
      v19 = i + 3 + v11;
      v11 += 4;
      LOBYTE(v13) = *(int *)((char *)image->strip[0].up3[v4].data + v13 + 4);
      v14[4] = v13;
      v14[5] = v13;
      v14[6] = v13;
      v14[7] = -1;
      LOBYTE(v13) = image->strip[0].up3[v4].data[v16];
      v14[11] = -1;
      buffer[v18] = v13;
      v14[9] = v13;
      v14[10] = v13;
      v20 = image->strip[0].up3[v4].data[v19];
      v14[15] = -1;
      buffer[v17] = v20;
      v14[13] = v20;
      v14[14] = v20;
    }
    v9 += byteStride;
  }
}


// ========================================================================
// ?_jxr_output_mb_id_rgb@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x82912200
// RVA : 0x00912200
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall _jxr_output_mb_id_rgb(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  int v4; // r30
  int v9; // r7
  int i; // r6
  int v11; // r10
  int j; // ctr
  int v13; // r9
  unsigned __int8 *v14; // r11
  int v15; // r24
  int v16; // r26
  int v17; // r4
  int v18; // r27

  v4 = mx;
  unblock_shuffle444(data: image->strip[0].up3[mx].data);
  unblock_shuffle444(data: image->strip[1].up3[v4].data);
  unblock_shuffle444(data: image->strip[2].up3[v4].data);
  yuv444_to_rgb(image, mx);
  shift_and_clip_regular(
    image,
    idx: mx,
    bias: 128,
    shift_bits: image->shift_bits,
    scale: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    round: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    clip_low: 0,
    clip_hig: 255);
  v9 = 0;
  for ( i = 0; i < 256; i += 16 )
  {
    v11 = 0;
    for ( j = 4; j != 0; --j )
    {
      v13 = i + v11;
      v14 = &buffer[4 * v9 + 4 * v11];
      v15 = 4 * (v9 + v11 + 3);
      v16 = i + v11 + 2;
      v17 = 4 * (v9 + v11 + 2);
      *v14 = image->strip[0].up3[v4].data[v13];
      v18 = i + 3 + v11;
      v11 += 4;
      v14[1] = image->strip[1].up3[v4].data[v13];
      v14[2] = image->strip[2].up3[v4].data[v13];
      v14[3] = -1;
      v14[4] = image->strip[0].up3[v4].data[v13 + 1];
      v14[5] = image->strip[1].up3[v4].data[v13 + 1];
      v14[6] = image->strip[2].up3[v4].data[v13 + 1];
      v14[7] = -1;
      buffer[v17] = image->strip[0].up3[v4].data[v16];
      v14[9] = image->strip[1].up3[v4].data[v16];
      v14[10] = image->strip[2].up3[v4].data[v16];
      v14[11] = -1;
      buffer[v15] = image->strip[0].up3[v4].data[v18];
      v14[13] = image->strip[1].up3[v4].data[v18];
      LOBYTE(v17) = image->strip[2].up3[v4].data[v18];
      v14[15] = -1;
      v14[14] = v17;
    }
    v9 += byteStride;
  }
}


// ========================================================================
// ?_jxr_output_mb_id_cocg_y@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x829123E8
// RVA : 0x009123E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall _jxr_output_mb_id_cocg_y(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  int v4; // r30
  int v9; // r7
  int i; // r6
  int v11; // r10
  int j; // ctr
  int v13; // r9
  unsigned __int8 *v14; // r11
  int v15; // r24
  int v16; // r26
  int v17; // r4
  int v18; // r27

  v4 = mx;
  unblock_shuffle444(data: image->strip[0].up3[mx].data);
  unblock_shuffle444(data: image->strip[1].up3[v4].data);
  unblock_shuffle444(data: image->strip[2].up3[v4].data);
  shift_and_clip_regular(
    image,
    idx: mx,
    bias: 128,
    shift_bits: image->shift_bits,
    scale: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    round: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    clip_low: 0,
    clip_hig: 255);
  v9 = 0;
  for ( i = 0; i < 256; i += 16 )
  {
    v11 = 0;
    for ( j = 4; j != 0; --j )
    {
      v13 = i + v11;
      v14 = &buffer[4 * v9 + 4 * v11];
      v15 = 4 * (v9 + v11 + 3);
      v16 = i + v11 + 2;
      v17 = 4 * (v9 + v11 + 2);
      *v14 = image->strip[1].up3[v4].data[v13];
      v18 = i + 3 + v11;
      v11 += 4;
      v14[1] = image->strip[2].up3[v4].data[v13];
      v14[2] = 0;
      v14[3] = image->strip[0].up3[v4].data[v13];
      v14[4] = image->strip[1].up3[v4].data[v13 + 1];
      v14[5] = image->strip[2].up3[v4].data[v13 + 1];
      v14[6] = 0;
      v14[7] = image->strip[0].up3[v4].data[v13 + 1];
      buffer[v17] = image->strip[1].up3[v4].data[v16];
      v14[9] = image->strip[2].up3[v4].data[v16];
      v14[10] = 0;
      v14[11] = image->strip[0].up3[v4].data[v16];
      buffer[v15] = image->strip[1].up3[v4].data[v18];
      v14[13] = image->strip[2].up3[v4].data[v18];
      v14[14] = 0;
      v14[15] = image->strip[0].up3[v4].data[v18];
    }
    v9 += byteStride;
  }
}


// ========================================================================
// ?_jxr_output_mb_id_normal_y_x@@YAXPAUjxr_image@@HPAEH@Z
// EA  : 0x829125C0
// RVA : 0x009125C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall _jxr_output_mb_id_normal_y_x(jxr_image *image, int mx, unsigned __int8 *buffer, int byteStride)
{
  int v4; // r30
  int v9; // r7
  int i; // r6
  int v11; // r10
  int j; // ctr
  unsigned __int8 *v13; // r11
  int v14; // r8
  int v15; // r27
  int v16; // r24
  int v17; // r25
  int v18; // r3

  v4 = mx;
  unblock_shuffle444(data: image->strip[0].up3[mx].data);
  unblock_shuffle444(data: image->strip[1].up3[v4].data);
  shift_and_clip_regular(
    image,
    idx: mx,
    bias: 128,
    shift_bits: image->shift_bits,
    scale: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    round: *((_DWORD *)image + 26) >= 0 ? 0 : 3,
    clip_low: 0,
    clip_hig: 255);
  v9 = 0;
  for ( i = 0; i < 256; i += 16 )
  {
    v11 = 0;
    for ( j = 4; j != 0; --j )
    {
      v13 = &buffer[4 * v9 + 4 * v11];
      v14 = i + v11;
      *v13 = -1;
      v15 = 4 * (v9 + v11 + 2);
      v16 = 4 * (v9 + v11 + 3);
      v17 = i + v11 + 2;
      v13[1] = image->strip[1].up3[v4].data[v14];
      v13[2] = -1;
      v18 = i + 3 + v11;
      v11 += 4;
      v13[3] = image->strip[0].up3[v4].data[v14];
      v13[4] = -1;
      v13[5] = image->strip[1].up3[v4].data[v14 + 1];
      v13[6] = -1;
      v13[7] = image->strip[0].up3[v4].data[v14 + 1];
      buffer[v15] = -1;
      v13[9] = image->strip[1].up3[v4].data[v17];
      v13[10] = -1;
      v13[11] = image->strip[0].up3[v4].data[v17];
      buffer[v16] = -1;
      v13[13] = image->strip[1].up3[v4].data[v18];
      v13[14] = -1;
      v13[15] = image->strip[0].up3[v4].data[v18];
    }
    v9 += byteStride;
  }
}


// ========================================================================
// ?_jxr_r_transform_mb_strip@@YAHPAUjxr_image@@HHH@Z
// EA  : 0x82912758
// RVA : 0x00912758
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

int __fastcall _jxr_r_transform_mb_strip(jxr_image *image, int tx, int ty, int my)
{
  int v7; // r5
  int result; // r3
  unsigned int v9; // r11
  int v10; // r28
  int v11; // r29
  int v12; // r30
  int v13; // r30
  int use_clr_fmt; // r11
  int v15; // r30
  int v16; // r30
  int v17; // r11

  result = _jxr_rcollect_tile_mb_rows(image, tx, ty, my);
  if ( result != 0 )
  {
    if ( ty < 0 )
      v9 = 0;
    else
      v9 = image->tile_row_position[ty];
    v10 = 0;
    v11 = v9 + my - 1;
    if ( v11 >= 1 )
    {
      v12 = 0;
      if ( image->num_channels != 0 )
      {
        do
          IPCT_level1_up1(image, use_my: v11, ch: v12++);
        while ( v12 < image->num_channels );
      }
      if ( v11 >= 2 )
      {
        if ( (image->header_flags1 & 3u) >= 2 )
        {
          v13 = 0;
          if ( image->num_channels != 0 )
          {
            do
            {
              if ( v13 != 0 )
              {
                use_clr_fmt = image->use_clr_fmt;
                if ( use_clr_fmt == 1 )
                {
                  overlap_level1_up2_420(image, use_my: v11, ch: v13);
                }
                else if ( use_clr_fmt == 2 )
                {
                  overlap_level1_up2_422(image, use_my: v11, ch: v13);
                }
                else
                {
                  overlap_level1_up2_444(image, use_my: v11, ch: v13);
                }
              }
              else
              {
                overlap_level1_up2_444(image, use_my: v11, ch: 0);
              }
              ++v13;
            }
            while ( v13 < image->num_channels );
          }
        }
        v15 = 0;
        if ( image->num_channels != 0 )
        {
          do
            IPCT_level2_up2(image, use_my: v15++, ch: v7);
          while ( v15 < image->num_channels );
        }
        if ( v11 >= 3 )
        {
          if ( (image->header_flags1 & 3) != 0 )
          {
            v16 = 0;
            if ( image->num_channels != 0 )
            {
              do
              {
                if ( v16 != 0 )
                {
                  v17 = image->use_clr_fmt;
                  if ( v17 == 1 )
                  {
                    overlap_level2_up3_420(image, use_my: v11, ch: v16);
                  }
                  else if ( v17 == 2 )
                  {
                    overlap_level2_up3_422(image, use_my: v11, ch: v16);
                  }
                  else
                  {
                    overlap_level2_up3_444(image, use_my: v11, ch: v16);
                  }
                }
                else
                {
                  overlap_level2_up3_444(image, use_my: v11, ch: 0);
                }
                ++v16;
              }
              while ( v16 < image->num_channels );
            }
          }
          v10 = 1;
        }
      }
      if ( image->lwf_test == 0 )
        image->lwf_test = _jxr_read_lwf_test_flag();
    }
    return v10;
  }
  return result;
}


// ========================================================================
// ?_jxr_r_output_mb_strip@@YAHPAUjxr_image@@HHH@Z
// EA  : 0x82912940
// RVA : 0x00912940
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

int __fastcall _jxr_r_output_mb_strip(jxr_image *image, int tx, int ty, int my)
{
  unsigned int v5; // r11
  int v6; // r31
  int v7; // r29

  if ( ty < 0 )
    v5 = 0;
  else
    v5 = image->tile_row_position[ty];
  v6 = 0;
  v7 = v5 + my - 1;
  if ( image->extended_width >> 4 != 0 )
  {
    do
      scale_and_emit_mb(image, use_my: v7, mx: v6++);
    while ( v6 < (signed int)(image->extended_width >> 4) );
  }
  return 0;
}


// ========================================================================
// ?_jxr_r_flush_rotate_mb_strip@@YAXPAUjxr_image@@HHH@Z
// EA  : 0x829129B8
// RVA : 0x009129B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_strip.cpp
// ========================================================================

void __fastcall _jxr_r_flush_rotate_mb_strip(jxr_image *image, int tx, int ty, int my)
{
  if ( _jxr_r_transform_mb_strip(image, tx, ty, my) != 0 )
    _jxr_r_output_mb_strip(image, tx, ty, my);
  _jxr_r_rotate_mb_strip(image, my);
}

