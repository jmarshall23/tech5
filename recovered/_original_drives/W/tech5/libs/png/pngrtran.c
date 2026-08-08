
// ========================================================================
// png_set_strip_16
// EA  : 0x83216C48
// RVA : 0x01216C48
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_set_strip_16(png_struct_def *png_ptr)
{
  if ( png_ptr != nullptr )
    png_ptr->transformations |= 0x400u;
}


// ========================================================================
// png_set_palette_to_rgb
// EA  : 0x83216C60
// RVA : 0x01216C60
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_set_palette_to_rgb(png_struct_def *png_ptr)
{
  unsigned int v1; // r9

  if ( png_ptr != nullptr )
  {
    v1 = png_ptr->transformations | 0x2001000;
    png_ptr->flags &= ~0x40u;
    png_ptr->transformations = v1;
  }
}


// ========================================================================
// png_do_unpack
// EA  : 0x83216C88
// RVA : 0x01216C88
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_unpack(png_row_info_struct *row_info, unsigned __int8 *row)
{
  unsigned int bit_depth; // r10
  unsigned int width; // r11
  unsigned __int8 *v4; // r9
  unsigned __int8 *v5; // r8
  int v6; // r10
  unsigned int v7; // ctr
  unsigned __int8 *v8; // r9
  unsigned __int8 *v9; // r8
  int v10; // r10
  unsigned int v11; // ctr
  unsigned __int8 *v12; // r9
  unsigned __int8 *v13; // r8
  int v14; // r10
  unsigned int v15; // ctr
  int channels; // r10

  bit_depth = row_info->bit_depth;
  if ( bit_depth < 8 )
  {
    width = row_info->width;
    switch ( bit_depth )
    {
      case 1u:
        v12 = &row[(width - 1) >> 3];
        v13 = &row[width - 1];
        v14 = 7 - ((width - 1) & 7);
        if ( width != 0 )
        {
          v15 = row_info->width;
          do
          {
            *v13 = (*v12 >> v14) & 1;
            if ( v14 == 7 )
            {
              v14 = 0;
              --v12;
            }
            else
            {
              ++v14;
            }
            --v13;
            --v15;
          }
          while ( v15 != 0 );
        }
        break;
      case 2u:
        v8 = &row[(width - 1) >> 2];
        v9 = &row[width - 1];
        v10 = 2 * (3 - ((width - 1) & 3));
        if ( width != 0 )
        {
          v11 = row_info->width;
          do
          {
            *v9 = (*v8 >> v10) & 3;
            if ( v10 == 6 )
            {
              v10 = 0;
              --v8;
            }
            else
            {
              v10 += 2;
            }
            --v9;
            --v11;
          }
          while ( v11 != 0 );
        }
        break;
      case 4u:
        v4 = &row[(width - 1) >> 1];
        v5 = &row[width - 1];
        v6 = 4 * (1 - ((width - 1) & 1));
        if ( width != 0 )
        {
          v7 = row_info->width;
          do
          {
            *v5 = (*v4 >> v6) & 0xF;
            if ( v6 == 4 )
            {
              v6 = 0;
              --v4;
            }
            else
            {
              v6 = 4;
            }
            --v5;
            --v7;
          }
          while ( v7 != 0 );
        }
        break;
      default:
        break;
    }
    channels = row_info->channels;
    row_info->bit_depth = 8;
    row_info->pixel_depth = 8 * channels;
    row_info->rowbytes = channels * width;
  }
}


// ========================================================================
// png_do_unshift
// EA  : 0x83216DF8
// RVA : 0x01216DF8
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_unshift(png_row_info_struct *row_info, unsigned __int8 *row, png_color_8_struct *sig_bits)
{
  int color_type; // r7
  unsigned __int8 *v4; // r11
  unsigned int width; // r31
  unsigned int v6; // r10
  __int16 v7; // r6
  int bit_depth; // r8
  unsigned int v9; // r9
  unsigned __int8 red; // r29
  char v11; // r8
  int *v12; // r8
  unsigned int i; // ctr
  unsigned int rowbytes; // ctr
  unsigned __int8 *v15; // r11
  unsigned __int8 v16; // r9
  unsigned int v17; // ctr
  unsigned __int8 *v18; // r11
  int v19; // r4
  int v20; // ctr
  unsigned __int8 *v21; // r11
  unsigned int v22; // r3
  int v23; // r7
  int v24; // ctr
  int v25; // r4
  unsigned __int16 v26; // r3
  _DWORD v27[12]; // [sp+0h] [-30h] BYREF

  color_type = row_info->color_type;
  v4 = row;
  if ( color_type != 3 )
  {
    width = row_info->width;
    v6 = 0;
    v7 = 0;
    if ( (color_type & 2) != 0 )
    {
      bit_depth = row_info->bit_depth;
      v9 = 3;
      red = sig_bits->red;
      v27[2] = bit_depth - sig_bits->blue;
      v11 = bit_depth - red;
    }
    else
    {
      v9 = 1;
      v11 = row_info->bit_depth - sig_bits->gray;
    }
    LOBYTE(v27[0]) = v11;
    if ( (color_type & 4) != 0 )
      v27[v9++] = row_info->bit_depth - sig_bits->alpha;
    if ( (int)v9 > 0 )
    {
      v12 = v27;
      for ( i = v9; i != 0; --i )
      {
        if ( *v12 > 0 )
          v7 = 1;
        else
          *v12 = 0;
        ++v12;
      }
      v11 = v27[0];
    }
    if ( v7 != 0 )
    {
      switch ( row_info->bit_depth )
      {
        case 2u:
          if ( row_info->rowbytes != 0 )
          {
            rowbytes = row_info->rowbytes;
            v15 = row - 1;
            do
            {
              v16 = (*++v15 >> 1) & 0x55;
              *v15 = v16;
              --rowbytes;
            }
            while ( rowbytes != 0 );
          }
          break;
        case 4u:
          if ( row_info->rowbytes != 0 )
          {
            v17 = row_info->rowbytes;
            v18 = row - 1;
            do
            {
              v19 = (*++v18 >> v11) & ((240 >> v11) & 0xF0 | (15 >> v11));
              *v18 = v19;
              --v17;
            }
            while ( v17 != 0 );
          }
          break;
        case 8u:
          if ( width * v9 != 0 )
          {
            v20 = width * v9;
            v21 = row - 1;
            do
            {
              v22 = v21[1];
              __twllei(v9, 0);
              v23 = v6 % v9;
              ++v6;
              *++v21 = v22 >> v27[v23];
              --v20;
            }
            while ( v20 != 0 );
          }
          break;
        case 0x10u:
          if ( width * v9 != 0 )
          {
            v24 = width * v9;
            do
            {
              v25 = v6 % v9;
              v26 = __ROL4__(*v4, 8) + v4[1];
              __twllei(v9, 0);
              ++v6;
              *(_WORD *)v4 = v26 >> v27[v25];
              v4 += 2;
              --v24;
            }
            while ( v24 != 0 );
          }
          break;
        default:
          return;
      }
    }
  }
}


// ========================================================================
// png_do_chop
// EA  : 0x83217070
// RVA : 0x01217070
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_chop(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int channels; // r10
  unsigned int v3; // ctr
  unsigned __int8 *v4; // r10
  unsigned __int8 *v5; // r11
  int v6; // r11
  unsigned int width; // r9

  if ( row_info->bit_depth == 16 )
  {
    channels = row_info->channels;
    if ( channels * row_info->width != 0 )
    {
      v3 = channels * row_info->width;
      v4 = row - 1;
      v5 = row - 2;
      do
      {
        v5 += 2;
        *++v4 = *v5;
        --v3;
      }
      while ( v3 != 0 );
    }
    v6 = row_info->channels;
    width = row_info->width;
    row_info->bit_depth = 8;
    row_info->pixel_depth = 8 * v6;
    row_info->rowbytes = width * v6;
  }
}


// ========================================================================
// png_do_read_swap_alpha
// EA  : 0x832170C8
// RVA : 0x012170C8
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_read_swap_alpha(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r11
  unsigned int width; // r9
  unsigned __int8 *v4; // r11
  unsigned __int8 *v5; // r10
  unsigned int v6; // ctr
  unsigned __int8 v7; // r9
  unsigned __int8 *v8; // r11
  unsigned __int8 *v9; // r10
  unsigned int v10; // ctr
  unsigned __int8 v11; // r9
  unsigned __int8 v12; // r8
  unsigned __int8 *v13; // r11
  unsigned __int8 *v14; // r10
  unsigned __int8 *v15; // r11
  unsigned __int8 *v16; // r10
  unsigned int v17; // ctr
  unsigned __int8 v18; // r9
  unsigned int v19; // ctr
  unsigned __int8 v20; // r9
  unsigned __int8 v21; // r8
  unsigned __int8 *v22; // r11
  unsigned __int8 *v23; // r10

  color_type = row_info->color_type;
  width = row_info->width;
  if ( color_type == 6 )
  {
    v5 = &row[row_info->rowbytes];
    v4 = v5;
    if ( row_info->bit_depth == 8 )
    {
      if ( width != 0 )
      {
        v6 = row_info->width;
        do
        {
          v7 = *(v4 - 1);
          v8 = v4 - 2;
          v9 = v5 - 1;
          *v9 = *v8--;
          *--v9 = *v8;
          v4 = v8 - 1;
          *(v9 - 1) = *v4;
          v5 = v9 - 2;
          *v5 = v7;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
    else if ( width != 0 )
    {
      v10 = row_info->width;
      do
      {
        v11 = *(v4 - 1);
        v12 = *(v4 - 2);
        v13 = v4 - 3;
        v14 = v5 - 1;
        *v14 = *v13--;
        *--v14 = *v13--;
        *--v14 = *v13--;
        *--v14 = *v13--;
        *--v14 = *v13;
        v4 = v13 - 1;
        *(v14 - 1) = *v4;
        *(v14 - 2) = v11;
        v5 = v14 - 3;
        *v5 = v12;
        --v10;
      }
      while ( v10 != 0 );
    }
  }
  else if ( color_type == 4 )
  {
    v16 = &row[row_info->rowbytes];
    v15 = v16;
    if ( row_info->bit_depth == 8 )
    {
      if ( width != 0 )
      {
        v17 = row_info->width;
        do
        {
          v18 = *(v15 - 1);
          v15 -= 2;
          *(v16 - 1) = *v15;
          v16 -= 2;
          *v16 = v18;
          --v17;
        }
        while ( v17 != 0 );
      }
    }
    else if ( width != 0 )
    {
      v19 = row_info->width;
      do
      {
        v20 = *(v15 - 1);
        v21 = *(v15 - 2);
        v22 = v15 - 3;
        v23 = v16 - 1;
        *v23 = *v22;
        v15 = v22 - 1;
        *(v23 - 1) = *v15;
        *(v23 - 2) = v20;
        v16 = v23 - 3;
        *v16 = v21;
        --v19;
      }
      while ( v19 != 0 );
    }
  }
}


// ========================================================================
// png_do_read_invert_alpha
// EA  : 0x832171F0
// RVA : 0x012171F0
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_read_invert_alpha(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r11
  unsigned int width; // r9
  unsigned __int8 *v4; // r10
  unsigned int v5; // ctr
  unsigned int v6; // ctr
  unsigned int rowbytes; // r11
  unsigned __int8 *v8; // r11
  unsigned __int8 *v9; // r10
  unsigned int v10; // ctr
  unsigned __int8 *v11; // r11
  unsigned __int8 *v12; // r10
  unsigned __int8 *v13; // r10
  unsigned int v14; // ctr

  color_type = row_info->color_type;
  width = row_info->width;
  if ( color_type == 6 )
  {
    v4 = &row[row_info->rowbytes];
    if ( row_info->bit_depth == 8 )
    {
      if ( width != 0 )
      {
        v5 = row_info->width;
        do
        {
          *(v4 - 1) = -1 - *(v4 - 1);
          v4 -= 4;
          --v5;
        }
        while ( v5 != 0 );
      }
    }
    else if ( width != 0 )
    {
      v6 = row_info->width;
      do
      {
        *(v4 - 1) = -1 - *(v4 - 1);
        *(v4 - 2) = -1 - *(v4 - 2);
        v4 -= 8;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  else if ( color_type == 4 )
  {
    rowbytes = row_info->rowbytes;
    if ( row_info->bit_depth == 8 )
    {
      v8 = &row[rowbytes];
      v9 = v8;
      if ( width != 0 )
      {
        v10 = row_info->width;
        do
        {
          v11 = v8 - 1;
          v12 = v9 - 1;
          *v12 = -1 - *v11;
          v8 = v11 - 1;
          v9 = v12 - 1;
          *v9 = *v8;
          --v10;
        }
        while ( v10 != 0 );
      }
    }
    else
    {
      v13 = &row[rowbytes];
      if ( width != 0 )
      {
        v14 = row_info->width;
        do
        {
          *(v13 - 1) = -1 - *(v13 - 1);
          *(v13 - 2) = -1 - *(v13 - 2);
          v13 -= 4;
          --v14;
        }
        while ( v14 != 0 );
      }
    }
  }
}


// ========================================================================
// png_do_read_filler
// EA  : 0x83217310
// RVA : 0x01217310
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_read_filler(png_row_info_struct *row_info, unsigned __int8 *row, __int16 filler, char flags)
{
  unsigned int width; // r9
  int v5; // r11
  unsigned __int8 *v6; // r10
  unsigned __int8 *v7; // r11
  unsigned int v8; // ctr
  unsigned __int8 *v9; // r11
  unsigned int v10; // ctr
  unsigned __int8 *v11; // r10
  unsigned __int8 *v12; // r11
  unsigned int v13; // ctr
  unsigned __int8 *v14; // r11
  unsigned __int8 *v15; // r10
  unsigned __int8 *v16; // r11
  unsigned int v17; // ctr
  unsigned __int8 *v18; // r10
  unsigned __int8 *v19; // r11
  int bit_depth; // r11
  unsigned __int8 *v21; // r10
  unsigned __int8 *v22; // r11
  unsigned int v23; // ctr
  unsigned __int8 *v24; // r11
  unsigned __int8 *v25; // r10
  unsigned int v26; // ctr
  unsigned __int8 *v27; // r10
  unsigned __int8 *v28; // r11
  unsigned __int8 *v29; // r10
  unsigned __int8 *v30; // r11
  unsigned int v31; // ctr
  unsigned __int8 *v32; // r11
  unsigned __int8 *v33; // r10
  unsigned __int8 *v34; // r11
  unsigned int v35; // ctr
  unsigned __int8 *v36; // r10
  unsigned __int8 *v37; // r11

  width = row_info->width;
  if ( row_info->color_type != 0 )
  {
    if ( row_info->color_type == 2 )
    {
      bit_depth = row_info->bit_depth;
      if ( bit_depth == 8 )
      {
        v21 = &row[3 * width];
        v22 = &v21[width];
        if ( flags < 0 )
        {
          if ( width > 1 )
          {
            v23 = width - 1;
            do
            {
              v24 = v22 - 1;
              *v24 = filler;
              v25 = v21 - 1;
              *--v24 = *v25--;
              *--v24 = *v25;
              v21 = v25 - 1;
              v22 = v24 - 1;
              *v22 = *v21;
              --v23;
            }
            while ( v23 != 0 );
          }
          *(v22 - 1) = filler;
          row_info->channels = 4;
          row_info->pixel_depth = 32;
          row_info->rowbytes = 4 * width;
        }
        else
        {
          if ( width != 0 )
          {
            v26 = row_info->width;
            do
            {
              v27 = v21 - 1;
              v28 = v22 - 1;
              *v28 = *v27--;
              *--v28 = *v27;
              v21 = v27 - 1;
              *(v28 - 1) = *v21;
              v22 = v28 - 2;
              *v22 = filler;
              --v26;
            }
            while ( v26 != 0 );
          }
          row_info->pixel_depth = 32;
          row_info->rowbytes = 4 * width;
          row_info->channels = 4;
        }
      }
      else if ( bit_depth == 16 )
      {
        v29 = &row[6 * width];
        v30 = &v29[2 * width];
        if ( flags < 0 )
        {
          if ( width > 1 )
          {
            v31 = width - 1;
            do
            {
              *(v30 - 1) = HIBYTE(filler);
              v32 = v30 - 2;
              *v32 = filler;
              v33 = v29 - 1;
              *--v32 = *v33--;
              *--v32 = *v33--;
              *--v32 = *v33--;
              *--v32 = *v33--;
              *--v32 = *v33;
              v29 = v33 - 1;
              v30 = v32 - 1;
              *v30 = *v29;
              --v31;
            }
            while ( v31 != 0 );
          }
          v34 = v30 - 1;
          *v34 = HIBYTE(filler);
          *(v34 - 1) = filler;
          row_info->channels = 4;
          row_info->pixel_depth = 64;
          row_info->rowbytes = 8 * width;
        }
        else
        {
          if ( width != 0 )
          {
            v35 = row_info->width;
            do
            {
              v36 = v29 - 1;
              v37 = v30 - 1;
              *v37 = *v36--;
              *--v37 = *v36--;
              *--v37 = *v36--;
              *--v37 = *v36--;
              *--v37 = *v36;
              v29 = v36 - 1;
              *(v37 - 1) = *v29;
              *(v37 - 2) = HIBYTE(filler);
              v30 = v37 - 3;
              *v30 = filler;
              --v35;
            }
            while ( v35 != 0 );
          }
          row_info->pixel_depth = 64;
          row_info->rowbytes = 8 * width;
          row_info->channels = 4;
        }
      }
    }
  }
  else
  {
    v5 = row_info->bit_depth;
    if ( v5 == 8 )
    {
      v6 = &row[width];
      v7 = &row[width + width];
      if ( flags < 0 )
      {
        if ( width > 1 )
        {
          v8 = width - 1;
          do
          {
            v9 = v7 - 1;
            *v9 = filler;
            --v6;
            v7 = v9 - 1;
            *v7 = *v6;
            --v8;
          }
          while ( v8 != 0 );
        }
        *(v7 - 1) = filler;
        row_info->channels = 2;
        row_info->pixel_depth = 16;
        row_info->rowbytes = 2 * width;
      }
      else
      {
        if ( width != 0 )
        {
          v10 = row_info->width;
          do
          {
            *(v7 - 1) = *--v6;
            v7 -= 2;
            *v7 = filler;
            --v10;
          }
          while ( v10 != 0 );
        }
        row_info->channels = 2;
        row_info->pixel_depth = 16;
        row_info->rowbytes = 2 * width;
      }
    }
    else if ( v5 == 16 )
    {
      v11 = &row[2 * width];
      v12 = &v11[2 * width];
      if ( flags < 0 )
      {
        if ( width > 1 )
        {
          v13 = width - 1;
          do
          {
            *(v12 - 1) = HIBYTE(filler);
            v14 = v12 - 2;
            *v14 = filler;
            v15 = v11 - 1;
            *--v14 = *v15;
            v11 = v15 - 1;
            v12 = v14 - 1;
            *v12 = *v11;
            --v13;
          }
          while ( v13 != 0 );
        }
        v16 = v12 - 1;
        *v16 = HIBYTE(filler);
        *(v16 - 1) = filler;
        row_info->channels = 2;
        row_info->pixel_depth = 32;
        row_info->rowbytes = 4 * width;
      }
      else
      {
        if ( width != 0 )
        {
          v17 = row_info->width;
          do
          {
            v18 = v11 - 1;
            v19 = v12 - 1;
            *v19 = *v18;
            v11 = v18 - 1;
            *(v19 - 1) = *v11;
            *(v19 - 2) = HIBYTE(filler);
            v12 = v19 - 3;
            *v12 = filler;
            --v17;
          }
          while ( v17 != 0 );
        }
        row_info->channels = 2;
        row_info->pixel_depth = 32;
        row_info->rowbytes = 4 * width;
      }
    }
  }
}


// ========================================================================
// png_do_gray_to_rgb
// EA  : 0x83217640
// RVA : 0x01217640
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_gray_to_rgb(png_row_info_struct *row_info, unsigned __int8 *row)
{
  unsigned int bit_depth; // r10
  unsigned int width; // r9
  int color_type; // r11
  unsigned __int8 *v5; // r11
  unsigned int v6; // ctr
  unsigned __int8 *v7; // r10
  unsigned __int8 *v8; // r11
  unsigned __int8 *v9; // r10
  unsigned __int8 *v10; // r11
  unsigned int v11; // ctr
  unsigned __int8 *v12; // r11
  unsigned __int8 v13; // r6
  unsigned __int8 *v14; // r10
  unsigned __int8 *v15; // r11
  unsigned int v16; // ctr
  unsigned __int8 *v17; // r10
  unsigned __int8 *v18; // r10
  unsigned __int8 *v19; // r11
  unsigned int v20; // ctr
  unsigned __int8 *v21; // r10
  unsigned __int8 *v22; // r11
  unsigned __int8 v23; // r5
  unsigned __int8 v24; // r10
  unsigned __int8 v25; // r7
  unsigned __int8 v26; // r6
  unsigned int v27; // r11
  int v28; // r11

  bit_depth = row_info->bit_depth;
  width = row_info->width;
  if ( bit_depth >= 8 )
  {
    color_type = row_info->color_type;
    if ( (color_type & 2) == 0 )
    {
      if ( row_info->color_type != 0 )
      {
        if ( color_type == 4 )
        {
          if ( bit_depth == 8 )
          {
            v14 = &row[2 * width - 1];
            v15 = &v14[2 * width];
            if ( width != 0 )
            {
              v16 = row_info->width;
              do
              {
                *v15 = *v14;
                v17 = v14 - 1;
                *(v15 - 1) = *v17;
                *(v15 - 2) = *v17;
                *(v15 - 3) = *v17;
                v14 = v17 - 1;
                v15 -= 4;
                --v16;
              }
              while ( v16 != 0 );
            }
          }
          else
          {
            v18 = &row[4 * width - 1];
            v19 = &v18[4 * width];
            if ( width != 0 )
            {
              v20 = row_info->width;
              do
              {
                *v19 = *v18;
                v21 = v18 - 1;
                v22 = v19 - 1;
                *v22 = *v21--;
                *(v22 - 1) = *v21;
                v22 -= 2;
                *v22 = *(v21 - 1);
                *(v22 - 1) = *v21;
                *(v22 - 2) = *(v21 - 1);
                *(v22 - 3) = *v21;
                v23 = *(v21 - 1);
                v18 = v21 - 2;
                *(v22 - 4) = v23;
                v19 = v22 - 5;
                --v20;
              }
              while ( v20 != 0 );
            }
          }
        }
      }
      else if ( bit_depth == 8 )
      {
        v5 = &row[2 * width - 1 + width];
        if ( width != 0 )
        {
          v6 = row_info->width;
          v7 = &row[width];
          do
          {
            *v5 = *(v7 - 1);
            v8 = v5 - 1;
            *v8 = *--v7;
            *(v8 - 1) = *v7;
            v5 = v8 - 2;
            --v6;
          }
          while ( v6 != 0 );
        }
      }
      else
      {
        v9 = &row[2 * width - 1];
        v10 = &v9[4 * width];
        if ( width != 0 )
        {
          v11 = row_info->width;
          do
          {
            *v10 = *v9;
            v12 = v10 - 1;
            *v12 = *(v9 - 1);
            *(v12 - 1) = *v9;
            *(v12 - 2) = *(v9 - 1);
            *(v12 - 3) = *v9;
            v13 = *(v9 - 1);
            v9 -= 2;
            *(v12 - 4) = v13;
            v10 = v12 - 5;
            --v11;
          }
          while ( v11 != 0 );
        }
      }
      v24 = row_info->bit_depth;
      v25 = row_info->color_type;
      v26 = row_info->channels + 2;
      row_info->channels = v26;
      row_info->color_type = v25 | 2;
      v27 = (unsigned __int8)(v24 * v26);
      row_info->pixel_depth = v27;
      if ( v27 < 8 )
        v28 = (v27 * width + 7) >> 3;
      else
        v28 = (v27 >> 3) * width;
      row_info->rowbytes = v28;
    }
  }
}


// ========================================================================
// png_do_rgb_to_gray
// EA  : 0x83217838
// RVA : 0x01217838
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

int __fastcall png_do_rgb_to_gray(png_struct_def *png_ptr, png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r9
  unsigned int width; // r5
  int result; // r3
  int rgb_to_gray_red_coeff; // r28
  int rgb_to_gray_green_coeff; // r27
  int rgb_to_gray_blue_coeff; // r26
  unsigned __int8 *v11; // r9
  unsigned int v12; // ctr
  unsigned __int8 *v13; // r30
  unsigned __int8 *gamma_to_1; // r31
  int v15; // r29
  int v16; // r8
  int v17; // r10
  unsigned __int8 v18; // r31
  unsigned __int8 *v19; // r30
  unsigned int v20; // ctr
  unsigned __int8 *v21; // r9
  int v22; // r8
  int v23; // r7
  unsigned __int8 v24; // r31
  unsigned __int8 *v25; // r30
  unsigned int v26; // ctr
  unsigned __int8 *v27; // r9
  unsigned __int8 *v28; // r9
  unsigned __int16 v29; // r10
  unsigned int v30; // r8
  unsigned __int16 v31; // r7
  unsigned int v32; // r31
  unsigned __int8 v33; // r10
  unsigned int v34; // r7
  bool v35; // zf
  int gamma_shift; // r10
  unsigned __int16 **gamma_16_to_1; // r24
  unsigned int v38; // r7
  unsigned __int8 *v39; // r9
  unsigned int v40; // ctr
  unsigned __int8 *v41; // r8
  unsigned __int8 *v42; // r8
  unsigned __int16 v43; // r10
  int v44; // r30
  unsigned __int16 v45; // r10
  int v46; // r31
  unsigned __int8 v47; // r10
  unsigned __int8 *v48; // r10
  unsigned int i; // ctr
  unsigned __int8 *v50; // r7
  int v51; // r30
  int v52; // r9
  int v53; // r31
  unsigned __int8 *v54; // r11
  unsigned __int8 v55; // r7
  unsigned __int8 *v56; // r10
  unsigned int j; // ctr
  int v58; // r9
  int v59; // r8
  unsigned __int8 v60; // r7
  unsigned __int8 *v61; // r10
  unsigned __int8 *v62; // r8
  unsigned int k; // ctr
  unsigned int v64; // r11
  unsigned __int8 *v65; // r7
  unsigned int v66; // r9
  unsigned int v67; // r10
  unsigned __int16 **v68; // r25
  unsigned int v69; // r10
  unsigned __int8 *v70; // r8
  unsigned __int8 *v71; // r7
  unsigned __int16 *v72; // r10
  unsigned int m; // ctr
  unsigned __int16 v74; // r6
  unsigned __int16 *v75; // r10
  unsigned __int16 v76; // r8
  _BYTE *v77; // r10
  unsigned __int16 v78; // r7
  unsigned __int8 *v79; // r11
  unsigned __int8 v80; // r9
  unsigned __int8 bit_depth; // r10
  unsigned __int8 v82; // r7
  unsigned __int8 v83; // r6
  unsigned int v84; // r11

  color_type = row_info->color_type;
  width = row_info->width;
  result = 0;
  if ( (color_type & 2) != 0 )
  {
    rgb_to_gray_red_coeff = png_ptr->rgb_to_gray_red_coeff;
    rgb_to_gray_green_coeff = png_ptr->rgb_to_gray_green_coeff;
    rgb_to_gray_blue_coeff = png_ptr->rgb_to_gray_blue_coeff;
    if ( color_type == 2 )
    {
      if ( row_info->bit_depth == 8 )
      {
        if ( png_ptr->gamma_from_1 != nullptr && png_ptr->gamma_to_1 != nullptr )
        {
          v11 = row;
          if ( width != 0 )
          {
            v12 = row_info->width;
            v13 = row - 1;
            do
            {
              gamma_to_1 = png_ptr->gamma_to_1;
              v15 = v11[2];
              v16 = gamma_to_1[*v11];
              v17 = gamma_to_1[v11[1]];
              v11 += 3;
              v18 = gamma_to_1[v15];
              if ( v16 == v17 && v16 == v18 )
              {
                *++v13 = *(v11 - 1);
              }
              else
              {
                result |= 1u;
                *++v13 = png_ptr->gamma_from_1[((unsigned int)v18 * rgb_to_gray_blue_coeff
                                              + v17 * rgb_to_gray_green_coeff
                                              + v16 * rgb_to_gray_red_coeff) >> 15];
              }
              --v12;
            }
            while ( v12 != 0 );
          }
        }
        else
        {
          v19 = row;
          if ( width != 0 )
          {
            v20 = row_info->width;
            v21 = row - 1;
            do
            {
              v22 = *v19;
              v23 = v19[1];
              v24 = v19[2];
              v19 += 3;
              if ( v22 == v23 && v22 == v24 )
              {
                *++v21 = *(v19 - 1);
              }
              else
              {
                result |= 1u;
                *++v21 = ((unsigned int)v24 * rgb_to_gray_blue_coeff
                        + v23 * rgb_to_gray_green_coeff
                        + v22 * rgb_to_gray_red_coeff) >> 15;
              }
              --v20;
            }
            while ( v20 != 0 );
          }
        }
      }
      else if ( png_ptr->gamma_16_to_1 != nullptr && png_ptr->gamma_16_from_1 != nullptr )
      {
        v25 = row;
        if ( width != 0 )
        {
          v26 = row_info->width;
          v27 = row - 2;
          do
          {
            v29 = _byteswap_ushort(*((_WORD *)v27 + 1));
            v28 = v27 + 2;
            v30 = v29;
            v31 = _byteswap_ushort(*((_WORD *)v28 + 1));
            v28 += 2;
            v32 = v31;
            v33 = v28[3];
            v27 = v28 + 2;
            v35 = v30 != v31;
            v34 = (unsigned __int16)((*v27 << 8) | v33);
            if ( v35 || v30 != (unsigned __int16)((*v27 << 8) | v33) )
            {
              gamma_shift = png_ptr->gamma_shift;
              gamma_16_to_1 = png_ptr->gamma_16_to_1;
              result |= 1u;
              v38 = (unsigned __int16)((*(unsigned __int16 *)((char *)gamma_16_to_1[(unsigned __int8)v34 >> gamma_shift]
                                                            + ((v34 >> 7) & 0x1FE))
                                      * rgb_to_gray_blue_coeff
                                      + *(unsigned __int16 *)((char *)gamma_16_to_1[(unsigned __int8)v30 >> gamma_shift]
                                                            + ((v30 >> 7) & 0x1FFFFFE))
                                      * rgb_to_gray_red_coeff
                                      + (unsigned int)*(unsigned __int16 *)((char *)gamma_16_to_1[(unsigned __int8)v32 >> gamma_shift]
                                                                          + ((v32 >> 7) & 0x1FFFFFE))
                                      * rgb_to_gray_green_coeff) >> 15);
              LOWORD(v30) = *(unsigned __int16 *)((char *)png_ptr->gamma_16_from_1[(unsigned __int8)v38 >> gamma_shift]
                                                + ((v38 >> 7) & 0x1FE));
            }
            *(_WORD *)v25 = v30;
            v25 += 2;
            --v26;
          }
          while ( v26 != 0 );
        }
      }
      else
      {
        v39 = row;
        if ( width != 0 )
        {
          v40 = row_info->width;
          v41 = row - 2;
          do
          {
            v43 = _byteswap_ushort(*((_WORD *)v41 + 1));
            v42 = v41 + 2;
            v44 = v43;
            v45 = _byteswap_ushort(*((_WORD *)v42 + 1));
            v42 += 2;
            v46 = v45;
            v47 = v42[3];
            v41 = v42 + 2;
            if ( v44 != v46 || v44 != (unsigned __int16)((*v41 << 8) | v47) )
              result |= 1u;
            *(_WORD *)v39 = ((unsigned int)(unsigned __int16)((*v41 << 8) | v47) * rgb_to_gray_blue_coeff
                           + v46 * rgb_to_gray_green_coeff
                           + v44 * rgb_to_gray_red_coeff) >> 15;
            v39 += 2;
            --v40;
          }
          while ( v40 != 0 );
        }
      }
    }
    if ( row_info->color_type == 6 )
    {
      if ( row_info->bit_depth == 8 )
      {
        if ( png_ptr->gamma_from_1 != nullptr && png_ptr->gamma_to_1 != nullptr )
        {
          v48 = row;
          if ( width != 0 )
          {
            for ( i = width; i != 0; --i )
            {
              v50 = png_ptr->gamma_to_1;
              v51 = row[2];
              v52 = v50[*row];
              v53 = v50[row[1]];
              v54 = row + 3;
              v55 = v50[v51];
              if ( v52 != v53 || v52 != v55 )
                result |= 1u;
              *v48 = png_ptr->gamma_from_1[((unsigned int)v55 * rgb_to_gray_blue_coeff
                                          + v53 * rgb_to_gray_green_coeff
                                          + v52 * rgb_to_gray_red_coeff) >> 15];
              v48[1] = *v54;
              row = v54 + 1;
              v48 += 2;
            }
          }
        }
        else
        {
          v56 = row;
          if ( width != 0 )
          {
            for ( j = width; j != 0; --j )
            {
              v58 = *v56;
              v59 = v56[1];
              v60 = v56[2];
              v61 = v56 + 3;
              if ( v58 != v59 || v58 != v60 )
                result |= 1u;
              *row = ((unsigned int)v60 * rgb_to_gray_blue_coeff
                    + v59 * rgb_to_gray_green_coeff
                    + v58 * rgb_to_gray_red_coeff) >> 15;
              row[1] = *v61;
              v56 = v61 + 1;
              row += 2;
            }
          }
        }
      }
      else if ( png_ptr->gamma_16_to_1 != nullptr && png_ptr->gamma_16_from_1 != nullptr )
      {
        v62 = row;
        if ( width != 0 )
        {
          for ( k = width; k != 0; --k )
          {
            v65 = row + 6;
            v66 = _byteswap_ushort(*((_WORD *)row + 1));
            v67 = _byteswap_ushort(*((_WORD *)row + 2));
            v64 = _byteswap_ushort(*(_WORD *)row);
            if ( v64 != v66 || v64 != (unsigned __int16)v67 )
            {
              v68 = png_ptr->gamma_16_to_1;
              result |= 1u;
              v69 = (unsigned __int16)((*(unsigned __int16 *)((char *)v68[(unsigned __int8)v67 >> png_ptr->gamma_shift]
                                                            + ((v67 >> 7) & 0x1FE))
                                      * rgb_to_gray_blue_coeff
                                      + *(unsigned __int16 *)((char *)v68[(unsigned __int8)v64 >> png_ptr->gamma_shift]
                                                            + ((v64 >> 7) & 0x1FFFFFE))
                                      * rgb_to_gray_red_coeff
                                      + (unsigned int)*(unsigned __int16 *)((char *)v68[(unsigned __int8)v66 >> png_ptr->gamma_shift]
                                                                          + ((v66 >> 7) & 0x1FFFFFE))
                                      * rgb_to_gray_green_coeff) >> 15);
              LOWORD(v64) = *(unsigned __int16 *)((char *)png_ptr->gamma_16_from_1[(unsigned __int8)v69 >> png_ptr->gamma_shift]
                                                + ((v69 >> 7) & 0x1FE));
            }
            *(_WORD *)v62 = v64;
            v70 = v62 + 2;
            *v70 = *v65;
            v71 = v65 + 1;
            row = v71 + 1;
            v70[1] = *v71;
            v62 = v70 + 2;
          }
        }
      }
      else
      {
        v72 = (unsigned __int16 *)row;
        if ( width != 0 )
        {
          for ( m = width; m != 0; --m )
          {
            v74 = _byteswap_ushort(*v72);
            v76 = _byteswap_ushort(v72[1]);
            v75 = v72 + 2;
            v78 = _byteswap_ushort(*v75);
            v77 = v75 + 1;
            if ( v74 != v76 || v74 != v78 )
              result |= 1u;
            *(_WORD *)row = (v78 * rgb_to_gray_blue_coeff
                           + v76 * rgb_to_gray_green_coeff
                           + (unsigned int)v74 * rgb_to_gray_red_coeff) >> 15;
            v79 = row + 2;
            *v79 = *v77;
            v80 = v77[1];
            v72 = (unsigned __int16 *)(v77 + 2);
            v79[1] = v80;
            row = v79 + 2;
          }
        }
      }
    }
    bit_depth = row_info->bit_depth;
    v82 = row_info->channels - 2;
    v83 = row_info->color_type & 0xFD;
    row_info->channels = v82;
    row_info->color_type = v83;
    v84 = (unsigned __int8)(bit_depth * v82);
    row_info->pixel_depth = v84;
    if ( v84 < 8 )
      row_info->rowbytes = (v84 * width + 7) >> 3;
    else
      row_info->rowbytes = (v84 >> 3) * width;
  }
  return result;
}


// ========================================================================
// png_do_background
// EA  : 0x83217EC0
// RVA : 0x01217EC0
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_background(
        png_row_info_struct *row_info,
        unsigned __int8 *row,
        png_color_16_struct *trans_values,
        png_color_16_struct *background,
        png_color_16_struct *background_1,
        unsigned __int8 *gamma_table,
        unsigned __int8 *gamma_from_1,
        unsigned __int8 *gamma_to_1,
        unsigned __int16 **gamma_16,
        unsigned __int16 **gamma_16_from_1,
        unsigned __int16 **gamma_16_to_1,
        int gamma_shift,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        char a34)
{
  unsigned int width; // r25
  unsigned int color_type; // r11
  int v36; // r11
  unsigned int v37; // ctr
  unsigned int v38; // r10
  int v39; // r11
  unsigned int v40; // ctr
  unsigned int v41; // r10
  unsigned __int8 v42; // r10
  unsigned int v43; // ctr
  unsigned int v44; // r10
  int v45; // r11
  unsigned int v46; // ctr
  unsigned int v47; // r10
  unsigned __int8 v48; // r10
  unsigned int v49; // ctr
  unsigned int v50; // r10
  unsigned int v51; // ctr
  int v52; // r11
  unsigned int v53; // ctr
  unsigned int v54; // ctr
  int v55; // r11
  unsigned int v56; // ctr
  unsigned int v57; // ctr
  unsigned __int8 *v58; // r11
  int v59; // r10
  int v60; // r9
  int v61; // r7
  unsigned int v62; // ctr
  unsigned __int8 *v63; // r11
  unsigned __int8 *v64; // r11
  unsigned int v65; // ctr
  int v66; // r8
  int v67; // r28
  int v68; // r9
  int v69; // r30
  int v70; // r7
  unsigned int v71; // ctr
  unsigned __int8 *v72; // r11
  unsigned __int8 *v73; // r31
  unsigned int v74; // ctr
  int v75; // r11
  unsigned __int8 gray; // r5
  __int16 v77; // r11
  unsigned __int8 *v78; // r9
  unsigned int v79; // ctr
  __int16 v80; // r11
  unsigned __int8 *v81; // r8
  unsigned int v82; // ctr
  unsigned __int8 *v83; // r10
  __int16 v84; // r4
  int v85; // r9
  unsigned int v86; // r9
  unsigned int v87; // r4
  unsigned int v88; // r9
  unsigned __int8 *v89; // r8
  unsigned int v90; // ctr
  unsigned __int8 *v91; // r10
  int v92; // r9
  unsigned int v93; // r9
  unsigned int v94; // r9
  unsigned __int8 *v95; // r11
  unsigned int v96; // ctr
  unsigned __int8 *v97; // r5
  int v98; // r31
  unsigned __int8 blue; // r4
  __int16 v100; // r4
  __int16 v101; // r4
  __int16 v102; // r4
  unsigned __int8 *v103; // r11
  unsigned int v104; // ctr
  unsigned __int8 *v105; // r10
  int v106; // r8
  __int16 v107; // r9
  __int16 v108; // r9
  __int16 v109; // r9
  unsigned int v110; // ctr
  unsigned __int8 *v111; // r9
  unsigned __int8 *v112; // r10
  __int16 v113; // r4
  int v114; // r8
  __int16 v115; // r8
  unsigned int v116; // r4
  unsigned int v117; // r4
  unsigned int v118; // r8
  unsigned __int8 *v119; // r9
  unsigned __int8 *v120; // r10
  unsigned int v121; // r26
  __int16 v122; // r7
  int v123; // r8
  unsigned __int8 *v124; // r8
  unsigned __int8 *v125; // r7
  int i; // ctr
  int v127; // r24
  unsigned int v128; // r7
  unsigned int v129; // r4
  int v130; // r7
  int v131; // r30
  int v132; // r4
  unsigned int v133; // r8
  unsigned int v134; // r8
  unsigned int v135; // r4
  unsigned __int8 bit_depth; // r9
  unsigned __int8 v137; // r7
  unsigned int v138; // r11

  width = row_info->width;
  if ( background == nullptr )
    return;
  color_type = row_info->color_type;
  if ( (color_type & 4) != 0 && (color_type == 3 || trans_values == nullptr) )
    return;
  if ( color_type <= 6 && color_type != 1 )
  {
    if ( color_type == 2 )
    {
      if ( row_info->bit_depth == 8 )
      {
        if ( gamma_table != nullptr )
        {
          if ( width != 0 )
          {
            v57 = row_info->width;
            v58 = row + 2;
            do
            {
              v59 = *(v58 - 2);
              if ( v59 == trans_values->red && *(v58 - 1) == trans_values->green && *v58 == trans_values->blue )
              {
                *(v58 - 2) = background->red;
                *(v58 - 1) = background->green;
                *v58 = background->blue;
              }
              else
              {
                v60 = *(v58 - 1);
                v61 = *v58;
                *(v58 - 2) = gamma_table[v59];
                *(v58 - 1) = gamma_table[v60];
                *v58 = gamma_table[v61];
              }
              v58 += 3;
              --v57;
            }
            while ( v57 != 0 );
          }
        }
        else if ( width != 0 )
        {
          v62 = row_info->width;
          v63 = row + 2;
          do
          {
            if ( *(v63 - 2) == trans_values->red && *(v63 - 1) == trans_values->green && *v63 == trans_values->blue )
            {
              *(v63 - 2) = background->red;
              *(v63 - 1) = background->green;
              *v63 = background->blue;
            }
            v63 += 3;
            --v62;
          }
          while ( v62 != 0 );
        }
      }
      else if ( a28 != 0 )
      {
        if ( width != 0 )
        {
          v64 = row + 2;
          v65 = row_info->width;
          do
          {
            v66 = *(v64 - 2);
            if ( (unsigned __int16)(__ROL4__(v66, 8) + *(v64 - 1)) == trans_values->red
              && (unsigned __int16)(__ROL4__(*v64, 8) + v64[1]) == trans_values->green
              && (unsigned __int16)(__ROL4__(v64[2], 8) + v64[3]) == trans_values->blue )
            {
              *(v64 - 2) = HIBYTE(background->red);
              *(v64 - 1) = background->red;
              *v64 = HIBYTE(background->green);
              v64[1] = background->green;
              v64[2] = HIBYTE(background->blue);
              v64[3] = background->blue;
            }
            else
            {
              v67 = v64[2];
              v68 = 4 * (v64[1] >> a34);
              v69 = __ROL4__(*v64, 1);
              v70 = 4 * (v64[3] >> a34);
              *((_WORD *)v64 - 1) = *(_WORD *)(*(_DWORD *)(4 * (*(v64 - 1) >> a34) + a28) + ((2 * v66) & 0x1FE));
              *(_WORD *)v64 = *(_WORD *)(*(_DWORD *)(v68 + a28) + v69);
              *((_WORD *)v64 + 1) = *(_WORD *)(*(_DWORD *)(v70 + a28) + __ROL4__(v67, 1));
            }
            v64 += 6;
            --v65;
          }
          while ( v65 != 0 );
        }
      }
      else if ( width != 0 )
      {
        v71 = row_info->width;
        v72 = row + 2;
        do
        {
          if ( (unsigned __int16)(__ROL4__(*(v72 - 2), 8) + *(v72 - 1)) == trans_values->red
            && (unsigned __int16)(__ROL4__(*v72, 8) + v72[1]) == trans_values->green
            && (unsigned __int16)(__ROL4__(v72[2], 8) + v72[3]) == trans_values->blue )
          {
            *(v72 - 2) = HIBYTE(background->red);
            *(v72 - 1) = background->red;
            *v72 = HIBYTE(background->green);
            v72[1] = background->green;
            v72[2] = HIBYTE(background->blue);
            v72[3] = background->blue;
          }
          v72 += 6;
          --v71;
        }
        while ( v71 != 0 );
      }
      goto LABEL_221;
    }
    if ( color_type != 3 || row_info->color_type == 0 )
    {
      if ( color_type != 4 || row_info->color_type == 0 )
      {
        if ( color_type != 5 || row_info->color_type == 0 )
        {
          if ( row_info->color_type != 0 )
          {
            if ( row_info->bit_depth == 8 )
            {
              if ( gamma_to_1 != nullptr && gamma_from_1 != nullptr && gamma_table != nullptr )
              {
                if ( width != 0 )
                {
                  v95 = row + 2;
                  v96 = row_info->width;
                  v97 = row + 1;
                  do
                  {
                    v98 = v97[2];
                    if ( v98 == 255 )
                    {
                      *(v95 - 2) = gamma_table[*(v97 - 1)];
                      *(v95 - 1) = gamma_table[*v97];
                      blue = gamma_table[v97[1]];
                    }
                    else if ( v97[2] != 0 )
                    {
                      v100 = gamma_to_1[*(v97 - 1)] * v97[2] + background_1->red * (255 - v97[2]) + 128;
                      *(v95 - 2) = gamma_from_1[(unsigned __int16)(HIBYTE(v100) + v100) >> 8];
                      v101 = gamma_to_1[*v97] * (unsigned __int8)v98 + background_1->green * (255 - v98) + 128;
                      *(v95 - 1) = gamma_from_1[(unsigned __int16)(HIBYTE(v101) + v101) >> 8];
                      v102 = gamma_to_1[v97[1]] * (unsigned __int8)v98 + background_1->blue * (255 - v98) + 128;
                      blue = gamma_from_1[(unsigned __int16)(HIBYTE(v102) + v102) >> 8];
                    }
                    else
                    {
                      *(v95 - 2) = background->red;
                      *(v95 - 1) = background->green;
                      blue = background->blue;
                    }
                    *v95 = blue;
                    v97 += 4;
                    v95 += 3;
                    --v96;
                  }
                  while ( v96 != 0 );
                }
              }
              else if ( width != 0 )
              {
                v103 = row + 2;
                v104 = row_info->width;
                v105 = row + 1;
                do
                {
                  v106 = v105[2];
                  if ( v106 == 255 )
                  {
                    *(v103 - 2) = *(v105 - 1);
                    *(v103 - 1) = *v105;
                    *v103 = v105[1];
                  }
                  else if ( v105[2] != 0 )
                  {
                    v107 = background->red * (255 - v105[2]) + v105[2] * *(v105 - 1) + 128;
                    *(v103 - 2) = (unsigned __int16)(HIBYTE(v107) + v107) >> 8;
                    v108 = background->green * (255 - v106) + (unsigned __int8)v106 * *v105 + 128;
                    *(v103 - 1) = (unsigned __int16)(HIBYTE(v108) + v108) >> 8;
                    v109 = background->blue * (255 - v106) + (unsigned __int8)v106 * v105[1] + 128;
                    *v103 = (unsigned __int16)(HIBYTE(v109) + v109) >> 8;
                  }
                  else
                  {
                    *(v103 - 2) = background->red;
                    *(v103 - 1) = background->green;
                    *v103 = background->blue;
                  }
                  v105 += 4;
                  v103 += 3;
                  --v104;
                }
                while ( v104 != 0 );
              }
            }
            else if ( a28 != 0 && a30 != 0 && a32 != 0 )
            {
              if ( width != 0 )
              {
                v110 = row_info->width;
                v111 = row + 2;
                v112 = row + 1;
                do
                {
                  v113 = __ROL4__(v112[5], 8);
                  v114 = (unsigned __int16)(v113 + v112[6]);
                  if ( v114 == 0xFFFF )
                  {
                    *((_WORD *)v111 - 1) = *(_WORD *)(*(_DWORD *)(4 * (*v112 >> a34) + a28) + __ROL4__(*(v112 - 1), 1));
                    *(_WORD *)v111 = *(_WORD *)(*(_DWORD *)(4 * (v112[2] >> a34) + a28) + __ROL4__(v112[1], 1));
                    *((_WORD *)v111 + 1) = *(_WORD *)(*(_DWORD *)(4 * (v112[4] >> a34) + a28) + __ROL4__(v112[3], 1));
                  }
                  else
                  {
                    if ( v113 + v112[6] != 0 )
                    {
                      v116 = *(unsigned __int16 *)(*(_DWORD *)(4 * (*v112 >> a34) + a32) + __ROL4__(*(v112 - 1), 1))
                           * v114
                           + background_1->red * (0xFFFF - v114)
                           + 0x8000;
                      *((_WORD *)v111 - 1) = *(_WORD *)(*(_DWORD *)(4
                                                                  * ((unsigned __int8)((HIWORD(v116) + v116) >> 16) >> a34)
                                                                  + a30)
                                                      + (((HIWORD(v116) + v116) >> 23) & 0x1FE));
                      v117 = *(unsigned __int16 *)(*(_DWORD *)(4 * (v112[2] >> a34) + a32) + __ROL4__(v112[1], 1))
                           * v114
                           + background_1->green * (0xFFFF - v114)
                           + 0x8000;
                      *(_WORD *)v111 = *(_WORD *)(*(_DWORD *)(4
                                                            * ((unsigned __int8)((HIWORD(v117) + v117) >> 16) >> a34)
                                                            + a30)
                                                + (((HIWORD(v117) + v117) >> 23) & 0x1FE));
                      v118 = *(unsigned __int16 *)(*(_DWORD *)(4 * (v112[4] >> a34) + a32) + __ROL4__(v112[3], 1))
                           * v114
                           + background_1->blue * (0xFFFF - v114)
                           + 0x8000;
                      v115 = *(_WORD *)(*(_DWORD *)(4 * ((unsigned __int8)((HIWORD(v118) + v118) >> 16) >> a34) + a30)
                                      + (((HIWORD(v118) + v118) >> 23) & 0x1FE));
                      v111[2] = HIBYTE(v115);
                    }
                    else
                    {
                      *(v111 - 2) = HIBYTE(background->red);
                      *(v111 - 1) = background->red;
                      *v111 = HIBYTE(background->green);
                      v111[1] = background->green;
                      v111[2] = HIBYTE(background->blue);
                      LOBYTE(v115) = background->blue;
                    }
                    v111[3] = v115;
                  }
                  v112 += 8;
                  v111 += 6;
                  --v110;
                }
                while ( v110 != 0 );
              }
            }
            else if ( width != 0 )
            {
              v119 = row + 2;
              v120 = row + 7;
              v121 = row_info->width;
              do
              {
                v122 = __ROL4__(*(v120 - 1), 8);
                v123 = (unsigned __int16)(v122 + *v120);
                if ( v123 == 0xFFFF )
                {
                  v124 = v120 - 8;
                  v125 = v119 - 3;
                  for ( i = 6; i != 0; --i )
                    *++v125 = *++v124;
                }
                else if ( v122 + *v120 != 0 )
                {
                  v127 = 0xFFFF - v123;
                  v128 = (unsigned __int16)(__ROL4__(*(v120 - 7), 8) + *(v120 - 6)) * v123
                       + background->red * (0xFFFF - v123)
                       + 0x8000;
                  v129 = HIWORD(v128) + v128;
                  v130 = (unsigned __int16)(__ROL4__(*(v120 - 5), 8) + *(v120 - 4));
                  v131 = (unsigned __int16)(__ROL4__(*(v120 - 3), 8) + *(v120 - 2));
                  *((_WORD *)v119 - 1) = HIWORD(v129);
                  v132 = v131 * v123;
                  v133 = background->green * (0xFFFF - v123) + v130 * v123 + 0x8000;
                  v119[1] = (HIWORD(v133) + v133) >> 16;
                  *v119 = (HIWORD(v133) + v133) >> 24;
                  v134 = background->blue * v127 + v132 + 0x8000;
                  v135 = HIWORD(v134) + v134;
                  v119[3] = BYTE1(v135);
                  v119[2] = HIBYTE(v135);
                }
                else
                {
                  *(v119 - 2) = HIBYTE(background->red);
                  *(v119 - 1) = background->red;
                  *v119 = HIBYTE(background->green);
                  v119[1] = background->green;
                  v119[2] = HIBYTE(background->blue);
                  v119[3] = background->blue;
                }
                --v121;
                v120 += 8;
                v119 += 6;
              }
              while ( v121 != 0 );
            }
          }
          else
          {
            switch ( row_info->bit_depth )
            {
              case 1u:
                v36 = 7;
                if ( width != 0 )
                {
                  v37 = row_info->width;
                  do
                  {
                    v38 = *row;
                    if ( ((v38 >> v36) & 1) == trans_values->gray )
                    {
                      *row = (32639 >> (7 - v36)) & v38;
                      *row = ((unsigned __int8)background->gray << v36) | (32639 >> (7 - v36)) & v38;
                    }
                    if ( v36 != 0 )
                    {
                      --v36;
                    }
                    else
                    {
                      v36 = 7;
                      ++row;
                    }
                    --v37;
                  }
                  while ( v37 != 0 );
                }
                break;
              case 2u:
                v39 = 6;
                if ( gamma_table != nullptr )
                {
                  if ( width != 0 )
                  {
                    v40 = row_info->width;
                    do
                    {
                      v41 = *row;
                      if ( ((v41 >> v39) & 3) == trans_values->gray )
                      {
                        v42 = (16191 >> (6 - v39)) & v41;
                        *row = v42;
                        *row = ((unsigned __int8)background->gray << v39) | v42;
                      }
                      else
                      {
                        *row = (16191 >> (6 - v39)) & v41
                             | (gamma_table[(4
                                           * ((4
                                             * ((4 * (((unsigned __int8)v41 >> v39) & 3))
                                              | ((unsigned __int8)v41 >> v39) & 3))
                                            | ((unsigned __int8)v41 >> v39) & 3))
                                          | ((unsigned __int8)v41 >> v39) & 3] >> 6 << v39);
                      }
                      if ( v39 != 0 )
                      {
                        v39 -= 2;
                      }
                      else
                      {
                        v39 = 6;
                        ++row;
                      }
                      --v40;
                    }
                    while ( v40 != 0 );
                  }
                }
                else if ( width != 0 )
                {
                  v43 = row_info->width;
                  do
                  {
                    v44 = *row;
                    if ( ((v44 >> v39) & 3) == trans_values->gray )
                    {
                      *row = (16191 >> (6 - v39)) & v44;
                      *row = ((unsigned __int8)background->gray << v39) | (16191 >> (6 - v39)) & v44;
                    }
                    if ( v39 != 0 )
                    {
                      v39 -= 2;
                    }
                    else
                    {
                      v39 = 6;
                      ++row;
                    }
                    --v43;
                  }
                  while ( v43 != 0 );
                }
                break;
              case 4u:
                v45 = 4;
                if ( gamma_table != nullptr )
                {
                  if ( width != 0 )
                  {
                    v46 = row_info->width;
                    do
                    {
                      v47 = *row;
                      if ( ((v47 >> v45) & 0xF) == trans_values->gray )
                      {
                        v48 = (3855 >> (4 - v45)) & v47;
                        *row = v48;
                        *row = ((unsigned __int8)background->gray << v45) | v48;
                      }
                      else
                      {
                        *row = (3855 >> (4 - v45)) & *row
                             | (gamma_table[(16 * ((*row >> v45) & 0xF)) | (*row >> v45) & 0xF] >> 4 << v45);
                      }
                      if ( v45 != 0 )
                      {
                        v45 -= 4;
                      }
                      else
                      {
                        v45 = 4;
                        ++row;
                      }
                      --v46;
                    }
                    while ( v46 != 0 );
                  }
                }
                else if ( width != 0 )
                {
                  v49 = row_info->width;
                  do
                  {
                    v50 = *row;
                    if ( ((v50 >> v45) & 0xF) == trans_values->gray )
                    {
                      *row = (3855 >> (4 - v45)) & v50;
                      *row = ((unsigned __int8)background->gray << v45) | (3855 >> (4 - v45)) & v50;
                    }
                    if ( v45 != 0 )
                    {
                      v45 -= 4;
                    }
                    else
                    {
                      v45 = 4;
                      ++row;
                    }
                    --v49;
                  }
                  while ( v49 != 0 );
                }
                break;
              case 8u:
                if ( gamma_table != nullptr )
                {
                  if ( width != 0 )
                  {
                    v51 = row_info->width;
                    do
                    {
                      v52 = *row;
                      if ( v52 == trans_values->gray )
                        *row = background->gray;
                      else
                        *row = gamma_table[v52];
                      ++row;
                      --v51;
                    }
                    while ( v51 != 0 );
                  }
                }
                else if ( width != 0 )
                {
                  v53 = row_info->width;
                  do
                  {
                    if ( *row == trans_values->gray )
                      *row = background->gray;
                    ++row;
                    --v53;
                  }
                  while ( v53 != 0 );
                }
                break;
              case 0x10u:
                if ( a28 != 0 )
                {
                  if ( width != 0 )
                  {
                    v54 = row_info->width;
                    do
                    {
                      v55 = *row;
                      if ( (unsigned __int16)(__ROL4__(v55, 8) + row[1]) == trans_values->gray )
                      {
                        *row = HIBYTE(background->gray);
                        row[1] = background->gray;
                      }
                      else
                      {
                        *(_WORD *)row = *(_WORD *)(*(_DWORD *)(4 * (row[1] >> a34) + a28) + ((2 * v55) & 0x1FE));
                      }
                      row += 2;
                      --v54;
                    }
                    while ( v54 != 0 );
                  }
                }
                else if ( width != 0 )
                {
                  v56 = row_info->width;
                  do
                  {
                    if ( (unsigned __int16)(__ROL4__(*row, 8) + row[1]) == trans_values->gray )
                    {
                      *row = HIBYTE(background->gray);
                      row[1] = background->gray;
                    }
                    row += 2;
                    --v56;
                  }
                  while ( v56 != 0 );
                }
                break;
              default:
                goto LABEL_221;
            }
          }
        }
        goto LABEL_221;
      }
      if ( row_info->bit_depth == 8 )
      {
        if ( gamma_to_1 != nullptr && gamma_from_1 != nullptr && gamma_table != nullptr )
        {
          v73 = row;
          if ( width != 0 )
          {
            v74 = row_info->width;
            do
            {
              v75 = v73[1];
              if ( v75 == 255 )
              {
                *row = gamma_table[*v73];
              }
              else
              {
                if ( v73[1] != 0 )
                {
                  v77 = background_1->gray * (255 - v75) + gamma_to_1[*v73] * (_WORD)v75 + 128;
                  gray = gamma_from_1[(unsigned __int16)(HIBYTE(v77) + v77) >> 8];
                }
                else
                {
                  gray = background->gray;
                }
                *row = gray;
              }
              v73 += 2;
              ++row;
              --v74;
            }
            while ( v74 != 0 );
          }
        }
        else
        {
          v78 = row;
          if ( width != 0 )
          {
            v79 = row_info->width;
            do
            {
              if ( v78[1] == 255 )
              {
                *row = *v78;
              }
              else if ( v78[1] != 0 )
              {
                v80 = background_1->gray * (255 - v78[1]) + *v78 * v78[1] + 128;
                *row = (unsigned __int16)(HIBYTE(v80) + v80) >> 8;
              }
              else
              {
                *row = background->gray;
              }
              v78 += 2;
              ++row;
              --v79;
            }
            while ( v79 != 0 );
          }
        }
        goto LABEL_221;
      }
      if ( a28 == 0 || a30 == 0 || a32 == 0 )
      {
        v89 = row;
        if ( width != 0 )
        {
          v90 = row_info->width;
          v91 = row + 3;
          do
          {
            v92 = (unsigned __int16)(__ROL4__(*(v91 - 1), 8) + *v91);
            if ( v92 == 0xFFFF )
            {
              *(_WORD *)v89 = *(_WORD *)(v91 - 3);
            }
            else
            {
              if ( v92 != 0 )
              {
                v94 = background_1->gray * (0xFFFF - v92)
                    + (unsigned __int16)(__ROL4__(*(v91 - 3), 8) + *(v91 - 2)) * v92
                    + 0x8000;
                v93 = (HIWORD(v94) + v94) >> 16;
                *v89 = BYTE2(v93);
              }
              else
              {
                *v89 = HIBYTE(background->gray);
                v93 = (unsigned __int8)background->gray;
              }
              v89[1] = v93;
            }
            v91 += 4;
            v89 += 2;
            --v90;
          }
          while ( v90 != 0 );
        }
        goto LABEL_221;
      }
      v81 = row;
      if ( width != 0 )
      {
        v82 = row_info->width;
        v83 = row + 1;
        while ( 1 )
        {
          v84 = __ROL4__(v83[1], 8);
          v85 = (unsigned __int16)(v84 + v83[2]);
          if ( v85 == 0xFFFF )
            break;
          if ( v84 + v83[2] != 0 )
          {
            v88 = *(unsigned __int16 *)(*(_DWORD *)(4 * (*v83 >> a34) + a32) + __ROL4__(*(v83 - 1), 1)) * v85
                + background_1->gray * (0xFFFF - v85)
                + 0x8000;
            v86 = *(unsigned __int16 *)(*(_DWORD *)(4 * ((unsigned __int8)((HIWORD(v88) + v88) >> 16) >> a34) + a30)
                                      + (((HIWORD(v88) + v88) >> 23) & 0x1FE));
            v87 = v86 >> 8;
            goto LABEL_163;
          }
          *v81 = HIBYTE(background->gray);
          LOBYTE(v86) = background->gray;
LABEL_164:
          v81[1] = v86;
          v83 += 4;
          v81 += 2;
          if ( --v82 == 0 )
            goto LABEL_221;
        }
        v86 = *(unsigned __int16 *)(*(_DWORD *)(4 * (*v83 >> a34) + a28) + __ROL4__(*(v83 - 1), 1));
        v87 = v86 >> 8;
LABEL_163:
        *v81 = v87;
        goto LABEL_164;
      }
    }
  }
LABEL_221:
  if ( (row_info->color_type & 4) != 0 )
  {
    bit_depth = row_info->bit_depth;
    v137 = row_info->channels - 1;
    row_info->color_type &= ~4u;
    row_info->channels = v137;
    v138 = (unsigned __int8)(bit_depth * v137);
    row_info->pixel_depth = v138;
    if ( v138 < 8 )
      row_info->rowbytes = (v138 * width + 7) >> 3;
    else
      row_info->rowbytes = (v138 >> 3) * width;
  }
}


// ========================================================================
// png_do_gamma
// EA  : 0x83219088
// RVA : 0x01219088
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_gamma(
        png_row_info_struct *row_info,
        unsigned __int8 *row,
        unsigned __int8 *gamma_table,
        unsigned __int16 **gamma_16_table,
        char gamma_shift)
{
  unsigned int bit_depth; // r9
  unsigned __int8 *v6; // r11
  unsigned int width; // r10
  unsigned int color_type; // r8
  unsigned int v9; // ctr
  unsigned int v10; // ctr
  unsigned __int8 *v11; // r11
  unsigned int v12; // ctr
  unsigned int v13; // ctr
  unsigned __int8 *v14; // r11
  unsigned int v15; // ctr
  unsigned __int8 *v16; // r11
  unsigned __int8 v17; // r8
  unsigned int v19; // ctr
  unsigned __int8 *v20; // r11
  __int16 v21; // r7
  unsigned __int8 *v22; // r9
  unsigned int v23; // ctr
  int v24; // r8
  int v25; // r9
  unsigned __int8 *v26; // r11
  unsigned int v27; // ctr
  int v28; // r10
  unsigned int v29; // ctr
  unsigned __int8 *v30; // r11
  unsigned __int8 v31; // r8
  unsigned int v33; // ctr
  unsigned __int8 *v34; // r11
  __int16 v35; // r7

  bit_depth = row_info->bit_depth;
  v6 = row;
  width = row_info->width;
  if ( bit_depth <= 8 && gamma_table != nullptr || bit_depth == 16 && gamma_16_table != nullptr )
  {
    color_type = row_info->color_type;
    if ( color_type <= 6 )
    {
      if ( row_info->color_type != 0 )
      {
        if ( color_type != 1 )
        {
          switch ( color_type )
          {
            case 2u:
              if ( bit_depth == 8 )
              {
                if ( width != 0 )
                {
                  v9 = row_info->width;
                  do
                  {
                    *v6 = gamma_table[*v6];
                    v6[1] = gamma_table[v6[1]];
                    v6[2] = gamma_table[v6[2]];
                    v6 += 3;
                    --v9;
                  }
                  while ( v9 != 0 );
                }
              }
              else if ( width != 0 )
              {
                v10 = row_info->width;
                do
                {
                  *(_WORD *)v6 = *(unsigned __int16 *)((char *)gamma_16_table[v6[1] >> gamma_shift] + __ROL4__(*v6, 1));
                  v11 = v6 + 2;
                  *(_WORD *)v11 = *(unsigned __int16 *)((char *)gamma_16_table[v11[1] >> gamma_shift] + __ROL4__(*v11, 1));
                  v11 += 2;
                  *(_WORD *)v11 = *(unsigned __int16 *)((char *)gamma_16_table[v11[1] >> gamma_shift] + __ROL4__(*v11, 1));
                  v6 = v11 + 2;
                  --v10;
                }
                while ( v10 != 0 );
              }
              break;
            case 3u:
              break;
            case 4u:
              if ( bit_depth == 8 )
              {
                if ( width != 0 )
                {
                  v15 = row_info->width;
                  v16 = row - 2;
                  do
                  {
                    v17 = gamma_table[v16[2]];
                    v16 += 2;
                    *v16 = v17;
                    --v15;
                  }
                  while ( v15 != 0 );
                }
              }
              else if ( width != 0 )
              {
                v19 = row_info->width;
                v20 = row - 3;
                do
                {
                  v21 = *(unsigned __int16 *)((char *)gamma_16_table[v20[4] >> gamma_shift] + __ROL4__(v20[3], 1));
                  v20[3] = HIBYTE(v21);
                  v20 += 4;
                  *v20 = v21;
                  --v19;
                }
                while ( v19 != 0 );
              }
              break;
            case 5u:
LABEL_60:
              break;
            default:
              if ( bit_depth == 8 )
              {
                if ( width != 0 )
                {
                  v12 = row_info->width;
                  do
                  {
                    *v6 = gamma_table[*v6];
                    v6[1] = gamma_table[v6[1]];
                    v6[2] = gamma_table[v6[2]];
                    v6 += 4;
                    --v12;
                  }
                  while ( v12 != 0 );
                }
              }
              else if ( width != 0 )
              {
                v13 = row_info->width;
                do
                {
                  *(_WORD *)v6 = *(unsigned __int16 *)((char *)gamma_16_table[v6[1] >> gamma_shift] + __ROL4__(*v6, 1));
                  v14 = v6 + 2;
                  *(_WORD *)v14 = *(unsigned __int16 *)((char *)gamma_16_table[v14[1] >> gamma_shift] + __ROL4__(*v14, 1));
                  v14 += 2;
                  *(_WORD *)v14 = *(unsigned __int16 *)((char *)gamma_16_table[v14[1] >> gamma_shift] + __ROL4__(*v14, 1));
                  v6 = v14 + 4;
                  --v13;
                }
                while ( v13 != 0 );
              }
              goto LABEL_60;
          }
        }
      }
      else
      {
        if ( bit_depth == 2 && width != 0 )
        {
          v22 = row - 1;
          v23 = ((width - 1) >> 2) + 1;
          do
          {
            v24 = *++v22;
            *v22 = ((((unsigned __int8)(gamma_table[(4 * ((4 * v24) & 0x30 | v24 & 0xC))
                                                  | ((v24 & 0xC) >> 2)
                                                  | v24 & 0xC]
                                      & 0xCF
                                      | (gamma_table[(4 * ((4 * ((4 * v24) & 0xC | v24 & 3)) | v24 & 3)) | v24 & 3] >> 2)) >> 2)
                   | gamma_table[((((v24 & 0x30) >> 2) | v24 & 0x30) >> 2) | (4 * v24) & 0xC0 | v24 & 0x30] & 0xC3u) >> 2)
                 | gamma_table[((((((v24 & 0xC0) >> 2) | v24 & 0xC0) >> 2) | v24 & 0xC0) >> 2) | v24 & 0xC0] & 0xC0;
            --v23;
          }
          while ( v23 != 0 );
        }
        v25 = row_info->bit_depth;
        if ( v25 == 4 )
        {
          if ( width != 0 )
          {
            v26 = row - 1;
            v27 = ((width - 1) >> 1) + 1;
            do
            {
              v28 = *++v26;
              *v26 = (gamma_table[(16 * v28) & 0xF0 | v28 & 0xF] >> 4)
                   | gamma_table[((v28 & 0xF0) >> 4) | v28 & 0xF0] & 0xF0;
              --v27;
            }
            while ( v27 != 0 );
          }
        }
        else if ( v25 == 8 )
        {
          if ( width != 0 )
          {
            v29 = width;
            v30 = row - 1;
            do
            {
              v31 = gamma_table[*++v30];
              *v30 = v31;
              --v29;
            }
            while ( v29 != 0 );
          }
        }
        else if ( v25 == 16 && width != 0 )
        {
          v33 = width;
          v34 = row - 1;
          do
          {
            v35 = *(unsigned __int16 *)((char *)gamma_16_table[v34[2] >> gamma_shift] + __ROL4__(v34[1], 1));
            v34[1] = HIBYTE(v35);
            v34 += 2;
            *v34 = v35;
            --v33;
          }
          while ( v33 != 0 );
        }
      }
    }
  }
}


// ========================================================================
// png_do_expand_palette
// EA  : 0x83219520
// RVA : 0x01219520
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_expand_palette(
        png_row_info_struct *row_info,
        unsigned __int8 *row,
        png_color_struct *palette,
        unsigned __int8 *trans,
        int num_trans)
{
  unsigned int width; // r10
  unsigned int bit_depth; // r11
  unsigned __int8 *v7; // r8
  unsigned __int8 *v8; // r9
  int v9; // r11
  unsigned int v10; // ctr
  unsigned __int8 *v11; // r8
  unsigned __int8 *v12; // r9
  int v13; // r11
  unsigned int v14; // ctr
  unsigned __int8 *v15; // r8
  unsigned __int8 *v16; // r9
  int v17; // r11
  unsigned int v18; // ctr
  unsigned __int8 *v19; // r11
  unsigned int v20; // r31
  unsigned __int8 *v21; // r8
  unsigned __int8 *v22; // r11
  unsigned int v23; // ctr
  unsigned __int8 *v24; // r10
  int v25; // r9
  unsigned __int8 *v26; // r11
  unsigned int v27; // r7
  unsigned __int8 *v28; // r9
  unsigned __int8 *v29; // r11
  unsigned int v30; // ctr
  unsigned __int8 *v31; // r10
  unsigned __int8 *v32; // r11

  width = row_info->width;
  if ( row_info->color_type == 3 )
  {
    bit_depth = row_info->bit_depth;
    if ( bit_depth < 8 )
    {
      switch ( bit_depth )
      {
        case 1u:
          v15 = &row[width - 1];
          v16 = &row[(width - 1) >> 3];
          v17 = 7 - (((_BYTE)width - 1) & 7);
          if ( width != 0 )
          {
            v18 = row_info->width;
            do
            {
              *v15 = (*v16 >> v17) & 1;
              if ( v17 == 7 )
              {
                v17 = 0;
                --v16;
              }
              else
              {
                ++v17;
              }
              --v15;
              --v18;
            }
            while ( v18 != 0 );
          }
          break;
        case 2u:
          v11 = &row[width - 1];
          v12 = &row[(width - 1) >> 2];
          v13 = 2 * (3 - (((_BYTE)width - 1) & 3));
          if ( width != 0 )
          {
            v14 = row_info->width;
            do
            {
              *v11 = (*v12 >> v13) & 3;
              if ( v13 == 6 )
              {
                v13 = 0;
                --v12;
              }
              else
              {
                v13 += 2;
              }
              --v11;
              --v14;
            }
            while ( v14 != 0 );
          }
          break;
        case 4u:
          v7 = &row[width - 1];
          v8 = &row[(width - 1) >> 1];
          v9 = (4 * width) & 4;
          if ( width != 0 )
          {
            v10 = row_info->width;
            do
            {
              *v7 = (*v8 >> v9) & 0xF;
              if ( v9 == 4 )
              {
                v9 = 0;
                --v8;
              }
              else
              {
                v9 += 4;
              }
              --v7;
              --v10;
            }
            while ( v10 != 0 );
          }
          break;
        default:
          break;
      }
      row_info->rowbytes = width;
      row_info->bit_depth = 8;
      row_info->pixel_depth = 8;
    }
    if ( row_info->bit_depth == 8 )
    {
      v19 = &row[width];
      if ( trans != nullptr )
      {
        v20 = 4 * width;
        v21 = v19 - 1;
        v22 = &row[4 * width - 1];
        if ( width != 0 )
        {
          v23 = width;
          v24 = v21 + 1;
          do
          {
            v25 = *(v24 - 1);
            if ( v25 < num_trans )
              *v22 = trans[v25];
            else
              *v22 = -1;
            v26 = v22 - 1;
            *v26-- = *(&palette->blue + *(v24 - 1) + __ROL4__(*(v24 - 1), 1));
            *v26 = *(&palette->green + *(v24 - 1) + __ROL4__(*(v24 - 1), 1));
            --v24;
            *(v26 - 1) = *(&palette->red + *v24 + __ROL4__(*v24, 1));
            v22 = v26 - 2;
            --v23;
          }
          while ( v23 != 0 );
        }
        row_info->rowbytes = v20;
        row_info->bit_depth = 8;
        row_info->pixel_depth = 32;
        row_info->color_type = 6;
        row_info->channels = 4;
      }
      else
      {
        v27 = 3 * width;
        v28 = v19 - 1;
        v29 = &row[3 * width - 1];
        if ( width != 0 )
        {
          v30 = width;
          v31 = v28 + 1;
          do
          {
            *v29 = *(&palette->blue + *(v31 - 1) + __ROL4__(*(v31 - 1), 1));
            v32 = v29 - 1;
            *v32 = *(&palette->green + *(v31 - 1) + __ROL4__(*(v31 - 1), 1));
            --v31;
            *(v32 - 1) = *(&palette->red + *v31 + __ROL4__(*v31, 1));
            v29 = v32 - 2;
            --v30;
          }
          while ( v30 != 0 );
        }
        row_info->rowbytes = v27;
        row_info->bit_depth = 8;
        row_info->pixel_depth = 24;
        row_info->color_type = 2;
        row_info->channels = 3;
      }
    }
  }
}


// ========================================================================
// png_do_expand
// EA  : 0x83219808
// RVA : 0x01219808
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_expand(png_row_info_struct *row_info, unsigned __int8 *row, png_color_16_struct *trans_value)
{
  unsigned int width; // r9
  unsigned __int16 gray; // r11
  unsigned int v5; // r10
  unsigned __int8 *v6; // r7
  unsigned __int8 *v7; // r8
  int v8; // r10
  unsigned int v9; // ctr
  unsigned __int8 *v10; // r7
  unsigned __int8 *v11; // r8
  int v12; // r10
  unsigned int v13; // ctr
  unsigned __int8 *v14; // r7
  unsigned __int8 *v15; // r8
  int v16; // r10
  unsigned int v17; // ctr
  int v18; // r10
  int v19; // r7
  unsigned int v20; // ctr
  unsigned __int8 *v21; // r11
  unsigned __int8 *v22; // r10
  unsigned int rowbytes; // r10
  unsigned __int8 v24; // r7
  unsigned __int8 v25; // r6
  unsigned __int8 *v26; // r8
  unsigned __int8 *v27; // r11
  unsigned int i; // ctr
  unsigned __int8 *v29; // r10
  unsigned __int8 *v30; // r11
  unsigned __int8 *v31; // r11
  unsigned int v32; // r11
  int bit_depth; // r11
  unsigned __int8 green; // r7
  unsigned __int8 blue; // r6
  unsigned __int8 *v36; // r11
  unsigned __int8 *v37; // r10
  int red; // r5
  unsigned int v39; // ctr
  unsigned __int8 *v40; // r10
  unsigned __int8 *v41; // r11
  unsigned __int8 v42; // r8
  unsigned __int8 *v43; // r11
  unsigned __int16 v44; // r5
  unsigned __int8 *v45; // r10
  int green_high; // r7
  unsigned __int8 v47; // r4
  int blue_high; // r6
  unsigned __int8 v49; // r31
  unsigned __int8 *v50; // r11
  unsigned __int8 *v51; // r10
  unsigned int v52; // ctr
  unsigned __int8 *v53; // r10
  unsigned __int8 *v54; // r10
  unsigned __int8 *v55; // r11
  unsigned __int8 v56; // r8

  width = row_info->width;
  if ( row_info->color_type != 0 )
  {
    if ( row_info->color_type == 2 && trans_value != nullptr )
    {
      bit_depth = row_info->bit_depth;
      if ( bit_depth == 8 )
      {
        green = trans_value->green;
        blue = trans_value->blue;
        v36 = &row[row_info->rowbytes - 1];
        v37 = &row[4 * width - 1];
        if ( width != 0 )
        {
          red = (unsigned __int8)trans_value->red;
          v39 = row_info->width;
          do
          {
            if ( *(v36 - 2) == red && *(v36 - 1) == green && *v36 == blue )
              *v37 = 0;
            else
              *v37 = -1;
            v40 = v37 - 1;
            *v40 = *v36;
            v41 = v36 - 1;
            *--v40 = *v41;
            v42 = *(v41 - 1);
            v36 = v41 - 2;
            *(v40 - 1) = v42;
            v37 = v40 - 2;
            --v39;
          }
          while ( v39 != 0 );
        }
      }
      else if ( bit_depth == 16 )
      {
        v43 = &row[row_info->rowbytes];
        v45 = &row[8 * width];
        green_high = HIBYTE(trans_value->green);
        v47 = trans_value->green;
        blue_high = HIBYTE(trans_value->blue);
        v49 = trans_value->blue;
        v44 = trans_value->red;
        v50 = v43 - 1;
        v51 = v45 - 1;
        if ( width != 0 )
        {
          v52 = row_info->width;
          do
          {
            if ( __PAIR64__(*(v50 - 5), *(v50 - 4)) == __PAIR64__(HIBYTE(v44), (unsigned __int8)v44)
              && *(v50 - 3) == (unsigned __int8)green_high
              && *(v50 - 2) == v47
              && *(v50 - 1) == (unsigned __int8)blue_high
              && *v50 == v49 )
            {
              *v51 = 0;
              v53 = v51 - 1;
              *v53 = 0;
            }
            else
            {
              *v51 = -1;
              v53 = v51 - 1;
              *v53 = -1;
            }
            v54 = v53 - 1;
            *v54 = *v50;
            v55 = v50 - 1;
            *--v54 = *v55--;
            *--v54 = *v55--;
            *--v54 = *v55--;
            *--v54 = *v55;
            v56 = *(v55 - 1);
            v50 = v55 - 2;
            *(v54 - 1) = v56;
            v51 = v54 - 2;
            --v52;
          }
          while ( v52 != 0 );
        }
      }
      v32 = (4 * row_info->bit_depth) & 0xFC;
      row_info->color_type = 6;
      row_info->channels = 4;
      row_info->pixel_depth = v32;
      if ( v32 >= 8 )
      {
        row_info->rowbytes = (v32 >> 3) * width;
        return;
      }
      goto LABEL_74;
    }
  }
  else
  {
    if ( trans_value != nullptr )
      gray = trans_value->gray;
    else
      gray = 0;
    v5 = row_info->bit_depth;
    if ( v5 < 8 )
    {
      switch ( v5 )
      {
        case 1u:
          gray = ((gray << 8) & 0x100) - (gray & 1);
          v14 = &row[width - 1];
          v15 = &row[(width - 1) >> 3];
          v16 = 7 - (((_BYTE)width - 1) & 7);
          if ( width != 0 )
          {
            v17 = row_info->width;
            do
            {
              *v14 = (((*v15 >> v16) & 1) == 0) - 1;
              if ( v16 == 7 )
              {
                v16 = 0;
                --v15;
              }
              else
              {
                ++v16;
              }
              --v14;
              --v17;
            }
            while ( v17 != 0 );
          }
          break;
        case 2u:
          v10 = &row[width - 1];
          gray = 85 * (gray & 3);
          v11 = &row[(width - 1) >> 2];
          v12 = 2 * (3 - (((_BYTE)width - 1) & 3));
          if ( width != 0 )
          {
            v13 = row_info->width;
            do
            {
              *v10 = (4 * ((4 * ((4 * ((*v11 >> v12) & 3)) | (*v11 >> v12) & 3)) | (*v11 >> v12) & 3))
                   | (*v11 >> v12) & 3;
              if ( v12 == 6 )
              {
                v12 = 0;
                --v11;
              }
              else
              {
                v12 += 2;
              }
              --v10;
              --v13;
            }
            while ( v13 != 0 );
          }
          break;
        case 4u:
          v6 = &row[width - 1];
          gray = ((16 * gray) & 0xF0) + (gray & 0xF);
          v7 = &row[(width - 1) >> 1];
          v8 = 4 - ((4 * (width - 1)) & 4);
          if ( width != 0 )
          {
            v9 = row_info->width;
            do
            {
              *v6 = (16 * ((*v7 >> v8) & 0xF)) | (*v7 >> v8) & 0xF;
              if ( v8 == 4 )
              {
                v8 = 0;
                --v7;
              }
              else
              {
                v8 = 4;
              }
              --v6;
              --v9;
            }
            while ( v9 != 0 );
          }
          break;
        default:
          break;
      }
      row_info->rowbytes = width;
      row_info->bit_depth = 8;
      row_info->pixel_depth = 8;
    }
    if ( trans_value != nullptr )
    {
      v18 = row_info->bit_depth;
      if ( v18 == 8 )
      {
        if ( width != 0 )
        {
          v19 = (unsigned __int8)gray;
          v20 = width;
          v21 = &row[2 * width];
          v22 = &row[width];
          do
          {
            if ( *(v22 - 1) == v19 )
              *(v21 - 1) = 0;
            else
              *(v21 - 1) = -1;
            --v22;
            v21 -= 2;
            *v21 = *v22;
            --v20;
          }
          while ( v20 != 0 );
        }
      }
      else if ( v18 == 16 )
      {
        rowbytes = row_info->rowbytes;
        v24 = HIBYTE(gray);
        v25 = gray;
        v26 = &row[rowbytes - 1];
        v27 = &row[2 * rowbytes - 1];
        if ( width != 0 )
        {
          for ( i = width; i != 0; --i )
          {
            v29 = v26 - 1;
            if ( *(v26 - 1) == v24 && *v26 == v25 )
            {
              *v27 = 0;
              v30 = v27 - 1;
              *v30 = 0;
            }
            else
            {
              *v27 = -1;
              v30 = v27 - 1;
              *v30 = -1;
            }
            v31 = v30 - 1;
            *v31 = *v26;
            v26 -= 2;
            *(v31 - 1) = *v29;
            v27 = v31 - 2;
          }
        }
      }
      v32 = (2 * row_info->bit_depth) & 0xFE;
      row_info->channels = 2;
      row_info->color_type = 4;
      row_info->pixel_depth = v32;
      if ( v32 >= 8 )
      {
        row_info->rowbytes = (v32 >> 3) * width;
        return;
      }
LABEL_74:
      row_info->rowbytes = (v32 * width + 7) >> 3;
    }
  }
}


// ========================================================================
// png_do_dither
// EA  : 0x83219D48
// RVA : 0x01219D48
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_dither(
        png_row_info_struct *row_info,
        unsigned __int8 *row,
        unsigned __int8 *palette_lookup,
        unsigned __int8 *dither_lookup)
{
  int color_type; // r10
  unsigned __int8 *v5; // r11
  unsigned int width; // r7
  unsigned int v7; // ctr
  unsigned __int8 *v8; // r10
  int v9; // r6
  unsigned __int8 *v10; // r11
  int v11; // r9
  __int16 v12; // t0
  unsigned int bit_depth; // r10
  unsigned int v14; // r11
  unsigned int v15; // ctr
  unsigned __int8 *v16; // r10
  int v17; // r6
  unsigned __int8 *v18; // r11
  int v19; // r9
  __int16 v20; // t0
  unsigned int v21; // r10
  unsigned int v22; // ctr
  unsigned __int8 *v23; // r11
  unsigned __int8 v24; // r8

  color_type = row_info->color_type;
  v5 = row;
  width = row_info->width;
  if ( color_type == 2 && palette_lookup != nullptr && row_info->bit_depth == 8 )
  {
    if ( width != 0 )
    {
      v7 = row_info->width;
      v8 = row - 1;
      do
      {
        v9 = *v5;
        v10 = v5 + 1;
        v11 = v10[1];
        v12 = __ROL4__((32 * v9) & 0x1F00 | *v10, 2);
        v5 = v10 + 2;
        *++v8 = palette_lookup[v12 & 0x7FE0 | (v11 >> 3)];
        --v7;
      }
      while ( v7 != 0 );
    }
    bit_depth = row_info->bit_depth;
    v14 = bit_depth;
    row_info->color_type = 3;
    row_info->channels = 1;
    row_info->pixel_depth = bit_depth;
    if ( bit_depth >= 8 )
    {
      row_info->rowbytes = (bit_depth >> 3) * width;
      return;
    }
LABEL_17:
    row_info->rowbytes = (v14 * width + 7) >> 3;
    return;
  }
  if ( color_type == 6 && palette_lookup != nullptr && row_info->bit_depth == 8 )
  {
    if ( width != 0 )
    {
      v15 = row_info->width;
      v16 = row - 1;
      do
      {
        v17 = *v5;
        v18 = v5 + 1;
        v19 = v18[1];
        v20 = __ROL4__((32 * v17) & 0x1F00 | *v18, 2);
        v5 = v18 + 3;
        *++v16 = palette_lookup[v20 & 0x7FE0 | (v19 >> 3)];
        --v15;
      }
      while ( v15 != 0 );
    }
    v21 = row_info->bit_depth;
    v14 = v21;
    row_info->color_type = 3;
    row_info->channels = 1;
    row_info->pixel_depth = v21;
    if ( v21 >= 8 )
    {
      row_info->rowbytes = (v21 >> 3) * width;
      return;
    }
    goto LABEL_17;
  }
  if ( color_type == 3 && dither_lookup != nullptr && row_info->bit_depth == 8 && width != 0 )
  {
    v22 = row_info->width;
    v23 = row - 1;
    do
    {
      v24 = dither_lookup[*++v23];
      *v23 = v24;
      --v22;
    }
    while ( v22 != 0 );
  }
}


// ========================================================================
// png_build_gamma_table
// EA  : 0x83219EC8
// RVA : 0x01219EC8
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_build_gamma_table(png_struct_def *png_ptr)
{
  double v2; // fp28
  unsigned __int8 *v3; // r3
  long double v4; // fp4
  __int64 v5; // r11
  int j; // r30
  long double v7; // fp2
  long double v8; // fp2
  double v9; // fp28
  __int64 v10; // r11
  long double v11; // fp4
  int k; // r30
  long double v13; // fp2
  long double v14; // fp2
  __int64 v15; // r11
  unsigned __int8 *v16; // r3
  long double v17; // fp4
  double v18; // fp0
  double v19; // fp28
  int m; // r30
  long double v21; // fp2
  long double v22; // fp2
  int red; // r11
  int v24; // r11
  bool v25; // zf
  __int64 v26; // r26
  double screen_gamma; // fp0
  char v28; // r27
  int v29; // r23
  double v30; // fp28
  unsigned __int16 **v31; // r3
  long double v32; // fp4
  __int64 v33; // r11
  int v34; // r29
  int v35; // r30
  double v36; // fp28
  unsigned int v37; // r30
  int i; // r29
  long double v39; // fp2
  long double v40; // fp2
  int v41; // ctr
  int v42; // r6
  unsigned int v43; // r5
  int v44; // ctr
  int v45; // r6
  unsigned int v46; // r5
  int v47; // r27
  int v48; // r28
  int v49; // r30
  long double v50; // fp4
  __int64 v51; // r11
  unsigned int v52; // r29
  long double v53; // fp2
  long double v54; // fp2
  double v55; // fp28
  int v56; // r27
  int v57; // r28
  int v58; // r30
  long double v59; // fp4
  __int64 v60; // r11
  unsigned int v61; // r29
  long double v62; // fp2
  long double v63; // fp2
  double v64; // fp0
  double gamma; // fp28
  int v66; // r27
  int v67; // r28
  int v68; // r30
  long double v69; // fp4
  __int64 v70; // r11
  unsigned int v71; // r29
  long double v72; // fp2
  long double v73; // fp2

  if ( png_ptr->bit_depth > 8u )
  {
    if ( (png_ptr->color_type & 2) != 0 )
    {
      red = png_ptr->sig_bit.red;
      if ( png_ptr->sig_bit.green > red )
        red = png_ptr->sig_bit.green;
      if ( png_ptr->sig_bit.blue > red )
        red = png_ptr->sig_bit.blue;
    }
    else
    {
      red = png_ptr->sig_bit.gray;
    }
    v25 = red > 0;
    v24 = 16 - red;
    if ( !v25 )
      v24 = 0;
    if ( (png_ptr->transformations & 0x400) != 0 && v24 < 5 )
    {
      HIDWORD(v26) = 5;
    }
    else if ( v24 <= 8 )
    {
      HIDWORD(v26) = (((unsigned int)v24 >> 31) - 1) & v24;
    }
    else
    {
      HIDWORD(v26) = 8;
    }
    screen_gamma = png_ptr->screen_gamma;
    v28 = 8 - BYTE3(v26);
    png_ptr->gamma_shift = BYTE3(v26);
    v29 = 1 << (8 - BYTE3(v26));
    if ( screen_gamma <= 0.000001 )
      v30 = 1.0;
    else
      v30 = 1.0 / (float)(png_ptr->gamma * (float)screen_gamma);
    v31 = (unsigned __int16 **)png_malloc(png_ptr, size: 4 * v29);
    LODWORD(v33) = png_ptr->transformations;
    HIDWORD(v33) = &off_82400000;
    png_ptr->gamma_16_table = v31;
    if ( (v33 & 0x480) != 0 )
    {
      if ( v29 > 0 )
      {
        v34 = 0;
        v35 = 1 << (8 - BYTE3(v26));
        do
        {
          --v35;
          png_ptr->gamma_16_table[v34++] = (unsigned __int16 *)png_malloc(png_ptr, size: 0x200u);
        }
        while ( v35 != 0 );
      }
      v36 = 1.0 / v30;
      LODWORD(v26) = v29 << 8;
      v37 = 0;
      for ( i = 0; i < 256; ++i )
      {
        LODWORD(v33) = i;
        *((double *)&v39 + 1) = v36;
        *(double *)&v39 = ((double)v33 + 0.5) * 0.00390625;
        v40 = pow(x: v39, y: v32);
        LODWORD(v33) = (__int64)(*(double *)&v40 * (double)v26);
        if ( v37 <= (unsigned int)v33 )
        {
          HIDWORD(v33) = 255 >> SBYTE3(v26);
          v41 = v33 - v37 + 1;
          do
          {
            v42 = HIDWORD(v33) & v37;
            v43 = v37++ >> v28;
            png_ptr->gamma_16_table[v42][v43] = ((_WORD)i << 8) | i;
            --v41;
          }
          while ( v41 != 0 );
        }
      }
      if ( v37 < (unsigned int)v26 )
      {
        v44 = v26 - v37;
        do
        {
          v45 = (255 >> SBYTE3(v26)) & v37;
          v46 = v37++ >> v28;
          png_ptr->gamma_16_table[v45][v46] = -1;
          --v44;
        }
        while ( v44 != 0 );
      }
    }
    else
    {
      v47 = 0;
      if ( v29 > 0 )
      {
        v48 = 0;
        do
        {
          v49 = 0;
          png_ptr->gamma_16_table[v48] = (unsigned __int16 *)png_malloc(png_ptr, size: 0x200u);
          HIDWORD(v51) = png_gamma_shift[HIDWORD(v26)];
          v52 = (unsigned int)(HIDWORD(v51) * v47) >> 4;
          do
          {
            LODWORD(v51) = v52;
            *((double *)&v53 + 1) = v30;
            *(double *)&v53 = (double)v51 * 0.00001525902189669642;
            v54 = pow(x: v53, y: v50);
            HIDWORD(v51) = png_ptr->gamma_16_table;
            v52 += 256;
            *(_WORD *)(*(_DWORD *)(v48 * 4 + HIDWORD(v51)) + v49) = (__int64)(*(double *)&v54 * 65535.0 + 0.5);
            v49 += 2;
          }
          while ( v49 < 512 );
          ++v47;
          ++v48;
        }
        while ( v47 < v29 );
      }
    }
    if ( (png_ptr->transformations & 0x600080) != 0 )
    {
      v55 = 1.0 / png_ptr->gamma;
      png_ptr->gamma_16_to_1 = (unsigned __int16 **)png_malloc(png_ptr, size: 4 * v29);
      v56 = 0;
      if ( v29 > 0 )
      {
        v57 = 0;
        do
        {
          v58 = 0;
          png_ptr->gamma_16_to_1[v57] = (unsigned __int16 *)png_malloc(png_ptr, size: 0x200u);
          HIDWORD(v60) = png_gamma_shift[HIDWORD(v26)];
          v61 = (unsigned int)(HIDWORD(v60) * v56) >> 4;
          do
          {
            LODWORD(v60) = v61;
            *((double *)&v62 + 1) = v55;
            *(double *)&v62 = (double)v60 * 0.00001525902189669642;
            v63 = pow(x: v62, y: v59);
            HIDWORD(v60) = png_ptr->gamma_16_to_1;
            v61 += 256;
            *(_WORD *)(*(_DWORD *)(v57 * 4 + HIDWORD(v60)) + v58) = (__int64)(*(double *)&v63 * 65535.0 + 0.5);
            v58 += 2;
          }
          while ( v58 < 512 );
          ++v56;
          ++v57;
        }
        while ( v56 < v29 );
      }
      v64 = png_ptr->screen_gamma;
      if ( v64 <= 0.000001 )
        gamma = png_ptr->gamma;
      else
        gamma = 1.0 / v64;
      png_ptr->gamma_16_from_1 = (unsigned __int16 **)png_malloc(png_ptr, size: 4 * v29);
      v66 = 0;
      if ( v29 > 0 )
      {
        v67 = 0;
        do
        {
          v68 = 0;
          png_ptr->gamma_16_from_1[v67] = (unsigned __int16 *)png_malloc(png_ptr, size: 0x200u);
          HIDWORD(v70) = png_gamma_shift[HIDWORD(v26)];
          v71 = (unsigned int)(HIDWORD(v70) * v66) >> 4;
          do
          {
            LODWORD(v70) = v71;
            *((double *)&v72 + 1) = gamma;
            *(double *)&v72 = (double)v70 * 0.00001525902189669642;
            v73 = pow(x: v72, y: v69);
            HIDWORD(v70) = png_ptr->gamma_16_from_1;
            v71 += 256;
            *(_WORD *)(*(_DWORD *)(v67 * 4 + HIDWORD(v70)) + v68) = (__int64)(*(double *)&v73 * 65535.0 + 0.5);
            v68 += 2;
          }
          while ( v68 < 512 );
          ++v66;
          ++v67;
        }
        while ( v66 < v29 );
      }
    }
  }
  else
  {
    if ( png_ptr->screen_gamma <= 0.000001 )
      v2 = 1.0;
    else
      v2 = 1.0 / (float)(png_ptr->gamma * png_ptr->screen_gamma);
    v3 = (unsigned __int8 *)png_malloc(png_ptr, size: 0x100u);
    HIDWORD(v5) = &off_82230000;
    png_ptr->gamma_table = v3;
    for ( j = 0; j < 256; ++j )
    {
      LODWORD(v5) = j;
      *((double *)&v7 + 1) = v2;
      *(double *)&v7 = (double)v5 * 0.00392156862745098;
      v8 = pow(x: v7, y: v4);
      HIDWORD(v5) = png_ptr->gamma_table;
      *(_BYTE *)(HIDWORD(v5) + j) = (__int64)(*(double *)&v8 * 255.0 + 0.5);
    }
    if ( (png_ptr->transformations & 0x600080) != 0 )
    {
      v9 = 1.0 / png_ptr->gamma;
      png_ptr->gamma_to_1 = (unsigned __int8 *)png_malloc(png_ptr, size: 0x100u);
      for ( k = 0; k < 256; ++k )
      {
        LODWORD(v10) = k;
        *((double *)&v13 + 1) = v9;
        *(double *)&v13 = (double)v10 * 0.00392156862745098;
        v14 = pow(x: v13, y: v11);
        HIDWORD(v10) = png_ptr->gamma_to_1;
        *(_BYTE *)(HIDWORD(v10) + k) = (__int64)(*(double *)&v14 * 255.0 + 0.5);
      }
      v16 = (unsigned __int8 *)png_malloc(png_ptr, size: 0x100u);
      v18 = png_ptr->screen_gamma;
      png_ptr->gamma_from_1 = v16;
      if ( v18 <= 0.000001 )
        v19 = png_ptr->gamma;
      else
        v19 = 1.0 / v18;
      for ( m = 0; m < 256; ++m )
      {
        LODWORD(v15) = m;
        *((double *)&v21 + 1) = v19;
        *(double *)&v21 = (double)v15 * 0.00392156862745098;
        v22 = pow(x: v21, y: v17);
        HIDWORD(v15) = png_ptr->gamma_from_1;
        *(_BYTE *)(HIDWORD(v15) + m) = (__int64)(*(double *)&v22 * 255.0 + 0.5);
      }
    }
  }
}


// ========================================================================
// png_do_read_intrapixel
// EA  : 0x8321A4C8
// RVA : 0x0121A4C8
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_read_intrapixel(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r9
  int bit_depth; // r11
  unsigned int width; // r10
  int v5; // r6
  unsigned __int8 *v6; // r11
  unsigned int v7; // ctr
  char v8; // r8
  unsigned __int8 v9; // r7
  int v10; // r7
  unsigned __int8 *v11; // r11
  unsigned int v12; // ctr
  int v13; // r10
  __int16 v14; // r4

  color_type = row_info->color_type;
  if ( (color_type & 2) != 0 )
  {
    bit_depth = row_info->bit_depth;
    width = row_info->width;
    if ( bit_depth == 8 )
    {
      if ( color_type == 2 )
      {
        v5 = 3;
      }
      else
      {
        if ( color_type != 6 )
          return;
        v5 = 4;
      }
      if ( width != 0 )
      {
        v6 = row + 2;
        v7 = row_info->width;
        do
        {
          v8 = *(v6 - 1);
          v9 = *v6;
          *(v6 - 2) += v8;
          *v6 = v9 + v8;
          v6 += v5;
          --v7;
        }
        while ( v7 != 0 );
      }
    }
    else
    {
      if ( bit_depth != 16 )
        return;
      if ( color_type == 2 )
      {
        v10 = 6;
      }
      else
      {
        if ( color_type != 6 )
          return;
        v10 = 8;
      }
      if ( width != 0 )
      {
        v11 = row + 1;
        v12 = row_info->width;
        do
        {
          v13 = __ROL4__(v11[1], 8) | v11[2];
          v14 = (__ROL4__(v11[3], 8) | v11[4]) + v13;
          *(_WORD *)(v11 - 1) = (__ROL4__(*(v11 - 1), 8) | *v11) + v13;
          *(_WORD *)(v11 + 3) = v14;
          v11 += v10;
          --v12;
        }
        while ( v12 != 0 );
      }
    }
  }
}


// ========================================================================
// png_init_read_transformations
// EA  : 0x8321A5F0
// RVA : 0x0121A5F0
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_init_read_transformations(png_struct_def *png_ptr)
{
  unsigned int transformations; // r8
  int color_type; // r26
  int red; // r10
  unsigned __int16 v5; // r7
  unsigned __int16 v6; // r8
  unsigned __int16 v7; // r8
  bool v8; // cr58
  unsigned __int16 v9; // r9
  unsigned __int16 v10; // r7
  int v11; // r11
  unsigned __int16 gray; // r11
  unsigned __int8 *v13; // r11
  int v14; // r11
  int num_trans; // ctr
  unsigned __int8 *v16; // r10
  _WORD *v17; // r11
  unsigned __int16 *p_gray; // r10
  int i; // ctr
  int v20; // r7
  int v21; // r10
  unsigned __int8 *trans; // r9
  unsigned int v23; // r11
  __int64 v24; // r8
  long double v25; // fp4
  int background_gamma_type; // r11
  png_color_struct *palette; // r27
  int num_palette; // r28
  unsigned __int8 *gamma_table; // r11
  int v30; // r10
  int v31; // r9
  int v32; // r8
  unsigned __int8 *gamma_to_1; // r7
  unsigned __int8 v34; // r30
  unsigned __int8 v35; // r29
  unsigned __int8 v36; // r7
  double screen_gamma; // fp27
  double v38; // fp28
  __int64 v39; // r10
  __int64 v40; // r10
  long double v41; // fp2
  long double v42; // fp2
  __int64 v43; // r8
  long double v44; // fp4
  long double v45; // fp2
  __int64 v46; // r5
  long double v47; // fp4
  long double v48; // fp2
  long double v49; // fp2
  long double v50; // fp2
  __int64 v51; // r8
  long double v52; // fp4
  long double v53; // fp2
  __int64 v54; // r6
  long double v55; // fp4
  long double v56; // fp2
  int v57; // r10
  unsigned __int8 *v58; // r11
  unsigned __int8 *v59; // r9
  int v60; // r3
  int v61; // r24
  __int16 v62; // r9
  __int16 v63; // r4
  __int16 v64; // r9
  __int16 v65; // r9
  int v66; // r6
  int v67; // r5
  double v68; // fp28
  double v69; // fp27
  double v70; // fp29
  __int64 v71; // r10
  double v72; // fp31
  long double v73; // fp2
  long double v74; // fp2
  __int64 v75; // r7
  long double v76; // fp4
  long double v77; // fp4
  long double v78; // fp2
  int v79; // r5
  __int64 v80; // r11
  long double v81; // fp2
  long double v82; // fp2
  __int64 v83; // r9
  long double v84; // fp4
  long double v85; // fp2
  __int64 v86; // r6
  long double v87; // fp4
  long double v88; // fp2
  __int64 v89; // r3
  long double v90; // fp4
  long double v91; // fp2
  __int64 v92; // r9
  long double v93; // fp4
  long double v94; // fp2
  __int64 v95; // r6
  long double v96; // fp4
  long double v97; // fp2
  int v98; // ctr
  unsigned __int8 *v99; // r11
  int v100; // r5
  int v101; // r4
  int v102; // r10
  unsigned __int8 v103; // r7
  unsigned __int8 green; // r6
  unsigned __int8 blue; // r5
  unsigned __int8 *p_blue; // r11
  int v107; // r4
  unsigned __int8 *v108; // r9
  __int16 v109; // r28
  __int16 v110; // r27
  __int16 v111; // r25
  __int16 v112; // r9
  __int16 v113; // r9
  int v114; // r11
  unsigned int v115; // r9
  unsigned __int16 v116; // r8
  unsigned int v117; // r10
  char v118; // r5
  char v119; // r7
  unsigned int v120; // r10
  unsigned int v121; // r11
  png_color_struct *v122; // r11
  __int16 v123; // [sp+50h] [-A0h]
  __int16 v124; // [sp+50h] [-A0h]
  unsigned __int8 v125; // [sp+52h] [-9Eh]
  __int64 v126; // [sp+60h] [-90h]

  transformations = png_ptr->transformations;
  color_type = png_ptr->color_type;
  if ( (transformations & 0x100) != 0 && (color_type & 2) == 0 )
    goto LABEL_9;
  if ( (transformations & 0x80) == 0 )
    goto LABEL_10;
  if ( (transformations & 0x100) == 0 )
  {
    if ( (transformations & 0x4000) == 0
      || (red = png_ptr->background.red) != png_ptr->background.green
      || red != png_ptr->background.blue )
    {
LABEL_10:
      if ( (transformations & 0x100) == 0 )
        goto LABEL_27;
      goto LABEL_11;
    }
    png_ptr->background.gray = red;
LABEL_9:
    png_ptr->mode |= 0x800u;
    goto LABEL_10;
  }
LABEL_11:
  if ( (transformations & 0x1000) != 0 )
  {
    if ( (color_type & 2) != 0 )
    {
      if ( color_type == 3 )
      {
        v13 = &png_ptr->palette->red + png_ptr->background.index + __ROL4__(png_ptr->background.index, 1);
        png_ptr->background.red = *v13;
        png_ptr->background.green = v13[1];
        png_ptr->background.blue = v13[2];
        if ( (transformations & 0x80000) != 0 )
        {
          v14 = transformations & 0x2000000;
          if ( (transformations & 0x2000000) == 0 && png_ptr->num_trans != 0 )
          {
            num_trans = png_ptr->num_trans;
            do
            {
              v16 = &png_ptr->trans[v14++];
              *v16 = -1 - *v16;
              --num_trans;
            }
            while ( num_trans != 0 );
          }
        }
      }
    }
    else
    {
      switch ( png_ptr->bit_depth )
      {
        case 1u:
          v5 = __ROL4__(png_ptr->background.gray, 8) - png_ptr->background.gray;
          png_ptr->background.gray = v5;
          png_ptr->background.blue = v5;
          png_ptr->background.green = v5;
          png_ptr->background.red = v5;
          if ( (transformations & 0x2000000) == 0 )
          {
            v6 = __ROL4__(png_ptr->trans_values.gray, 8) - png_ptr->trans_values.gray;
            png_ptr->trans_values.gray = v6;
            png_ptr->trans_values.blue = v6;
            png_ptr->trans_values.green = v6;
            png_ptr->trans_values.red = v6;
          }
          break;
        case 2u:
          v8 = (transformations & 0x2000000) == 0;
          v7 = 85 * png_ptr->background.gray;
          png_ptr->background.gray = v7;
          png_ptr->background.blue = v7;
          png_ptr->background.green = v7;
          png_ptr->background.red = v7;
          if ( v8 )
          {
            v9 = 85 * png_ptr->trans_values.gray;
            png_ptr->trans_values.gray = v9;
            png_ptr->trans_values.blue = v9;
            png_ptr->trans_values.green = v9;
            png_ptr->trans_values.red = v9;
          }
          break;
        case 4u:
          v10 = __ROL4__(png_ptr->background.gray, 4) + png_ptr->background.gray;
          png_ptr->background.gray = v10;
          png_ptr->background.blue = v10;
          png_ptr->background.green = v10;
          png_ptr->background.red = v10;
          if ( (transformations & 0x2000000) == 0 )
          {
            v11 = __ROL4__(png_ptr->trans_values.gray, 4) + png_ptr->trans_values.gray;
            png_ptr->trans_values.gray = v11;
            png_ptr->trans_values.blue = v11;
            png_ptr->trans_values.green = v11;
            png_ptr->trans_values.red = v11;
          }
          break;
        case 8u:
        case 0x10u:
          gray = png_ptr->background.gray;
          png_ptr->background.blue = gray;
          png_ptr->background.green = gray;
          png_ptr->background.red = gray;
          break;
        default:
          break;
      }
    }
  }
LABEL_27:
  v17 = (_WORD *)&png_ptr->background_gamma + 1;
  p_gray = &png_ptr->background.gray;
  for ( i = 5; i != 0; --i )
    *++p_gray = *++v17;
  if ( color_type == 3
    && png_ptr->num_trans != 0
    && __fabs((float)(png_ptr->screen_gamma * png_ptr->gamma) - 1.0) < 0.05 )
  {
    v20 = 0;
    v21 = 0;
    if ( png_ptr->num_trans == 0 )
      goto LABEL_39;
    trans = png_ptr->trans;
    do
    {
      if ( trans[v21] != 0 && trans[v21] != 255 )
        v20 = 1;
      ++v21;
    }
    while ( v21 < png_ptr->num_trans );
    if ( v20 == 0 )
LABEL_39:
      png_ptr->transformations &= ~0x2000u;
  }
  v23 = png_ptr->transformations;
  if ( (v23 & 0x602000) == 0 || png_ptr->gamma == 0.0 )
  {
    if ( (v23 & 0x80) != 0 && color_type == 3 )
    {
      v102 = 0;
      v103 = png_ptr->background.red;
      green = png_ptr->background.green;
      blue = png_ptr->background.blue;
      HIBYTE(v124) = v103;
      LOBYTE(v124) = green;
      if ( png_ptr->num_trans != 0 )
      {
        p_blue = &png_ptr->palette->blue;
        v107 = png_ptr->num_trans;
        do
        {
          v108 = png_ptr->trans;
          if ( v108[v102] != 0 )
          {
            if ( v108[v102] != 255 )
            {
              v109 = v108[v102];
              v110 = *(p_blue - 1);
              v111 = *p_blue;
              *(p_blue - 2) = (unsigned __int16)((unsigned __int8)((unsigned __int16)((255 - v109) * v103
                                                                                    + *(p_blue - 2) * v109
                                                                                    + 128) >> 8)
                                               + (255 - v109) * v103
                                               + *(p_blue - 2) * v109
                                               + 128) >> 8;
              v112 = v110 * png_ptr->trans[v102] + (255 - png_ptr->trans[v102]) * green + 128;
              *(p_blue - 1) = (unsigned __int16)(HIBYTE(v112) + v112) >> 8;
              v113 = (255 - png_ptr->trans[v102]) * blue + v111 * png_ptr->trans[v102] + 128;
              *p_blue = (unsigned __int16)(HIBYTE(v113) + v113) >> 8;
            }
          }
          else
          {
            *((_WORD *)p_blue - 1) = v124;
            *p_blue = blue;
          }
          --v107;
          ++v102;
          p_blue += 3;
        }
        while ( v107 != 0 );
      }
      png_ptr->transformations = png_ptr->transformations & 0xFFFBFF7F | 0x40000;
    }
  }
  else
  {
    png_build_gamma_table(png_ptr);
    if ( (png_ptr->transformations & 0x80) != 0 )
    {
      background_gamma_type = png_ptr->background_gamma_type;
      if ( color_type == 3 )
      {
        palette = png_ptr->palette;
        num_palette = png_ptr->num_palette;
        switch ( background_gamma_type )
        {
          case 2:
            gamma_table = png_ptr->gamma_table;
            v30 = png_ptr->background.red;
            v31 = png_ptr->background.green;
            v32 = png_ptr->background.blue;
            gamma_to_1 = png_ptr->gamma_to_1;
            v34 = gamma_to_1[v30];
            v35 = gamma_to_1[v31];
            v36 = gamma_to_1[v32];
            HIBYTE(v123) = gamma_table[v30];
            LOBYTE(v123) = gamma_table[v31];
            v125 = gamma_table[v32];
LABEL_56:
            v57 = 0;
            if ( num_palette > 0 )
            {
              v58 = &palette->blue;
              do
              {
                if ( v57 >= png_ptr->num_trans || (v59 = png_ptr->trans)[v57] == 255 )
                {
                  v66 = *(v58 - 1);
                  v67 = *v58;
                  *(v58 - 2) = png_ptr->gamma_table[*(v58 - 2)];
                  *(v58 - 1) = png_ptr->gamma_table[v66];
                  *v58 = png_ptr->gamma_table[v67];
                }
                else if ( v59[v57] != 0 )
                {
                  v60 = *(v58 - 1);
                  v61 = *v58;
                  v62 = png_ptr->gamma_to_1[*(v58 - 2)] * v59[v57] + (255 - v59[v57]) * v34 + 128;
                  *(v58 - 2) = png_ptr->gamma_from_1[(unsigned __int16)(HIBYTE(v62) + v62) >> 8];
                  v63 = png_ptr->gamma_to_1[v60];
                  LOWORD(v60) = png_ptr->trans[v57];
                  v64 = v63 * v60 + (255 - v60) * v35 + 128;
                  *(v58 - 1) = png_ptr->gamma_from_1[(unsigned __int16)(HIBYTE(v64) + v64) >> 8];
                  v65 = png_ptr->gamma_to_1[v61] * png_ptr->trans[v57] + (255 - png_ptr->trans[v57]) * v36 + 128;
                  *v58 = png_ptr->gamma_from_1[(unsigned __int16)(HIBYTE(v65) + v65) >> 8];
                }
                else
                {
                  *((_WORD *)v58 - 1) = v123;
                  *v58 = v125;
                }
                --num_palette;
                ++v57;
                v58 += 3;
              }
              while ( num_palette != 0 );
            }
            png_ptr->transformations = png_ptr->transformations & 0xFFFBDF7F | 0x40000;
            goto LABEL_92;
          case 1:
            screen_gamma = png_ptr->screen_gamma;
            break;
          case 3:
            screen_gamma = 1.0 / png_ptr->background_gamma;
            v38 = 1.0 / (float)(png_ptr->screen_gamma * png_ptr->background_gamma);
LABEL_52:
            HIDWORD(v39) = &off_82230000;
            if ( __fabs(v38 - 1.0) >= 0.05 )
            {
              LODWORD(v39) = png_ptr->background.red;
              *((double *)&v41 + 1) = v38;
              *(double *)&v41 = (double)v39 * 0.00392156862745098;
              v42 = pow(x: v41, y: v25);
              LODWORD(v43) = png_ptr->background.green;
              *((double *)&v42 + 1) = v38;
              HIBYTE(v123) = (__int64)(*(double *)&v42 * 255.0 + 0.5);
              *(double *)&v42 = (double)v43 * 0.00392156862745098;
              v45 = pow(x: v42, y: v44);
              LODWORD(v46) = png_ptr->background.blue;
              *((double *)&v45 + 1) = v38;
              LOBYTE(v123) = (__int64)(*(double *)&v45 * 255.0 + 0.5);
              *(double *)&v45 = (double)v46 * 0.00392156862745098;
              v48 = pow(x: v45, y: v47);
              *((double *)&v25 + 1) = *(double *)&v48 * 255.0 + 0.5;
              *(_QWORD *)&v25 = (__int64)*((double *)&v25 + 1);
              v125 = (__int64)*((double *)&v25 + 1);
            }
            else
            {
              HIDWORD(v40) = png_ptr->background.blue;
              HIBYTE(v123) = png_ptr->background.red;
              LOBYTE(v123) = png_ptr->background.green;
              v125 = png_ptr->background.blue;
            }
            LODWORD(v40) = png_ptr->background.red;
            *((double *)&v49 + 1) = screen_gamma;
            *(double *)&v49 = (double)v40 * 0.00392156862745098;
            v50 = pow(x: v49, y: v25);
            LODWORD(v51) = png_ptr->background.green;
            *((double *)&v50 + 1) = screen_gamma;
            v34 = (__int64)(*(double *)&v50 * 255.0 + 0.5);
            *(double *)&v50 = (double)v51 * 0.00392156862745098;
            v53 = pow(x: v50, y: v52);
            LODWORD(v54) = png_ptr->background.blue;
            *((double *)&v53 + 1) = screen_gamma;
            v35 = (__int64)(*(double *)&v53 * 255.0 + 0.5);
            *(double *)&v53 = (double)v54 * 0.00392156862745098;
            v56 = pow(x: v53, y: v55);
            v36 = (__int64)(*(double *)&v56 * 255.0 + 0.5);
            goto LABEL_56;
          default:
            screen_gamma = 1.0;
            break;
        }
        v38 = 1.0;
        goto LABEL_52;
      }
      v68 = 1.0;
      v69 = 1.0;
      LODWORD(v24) = (1 << png_ptr->bit_depth) - 1;
      v70 = (double)v24;
      switch ( background_gamma_type )
      {
        case 1:
          v68 = png_ptr->screen_gamma;
          v69 = 1.0;
          break;
        case 2:
          v68 = 1.0 / png_ptr->gamma;
          v69 = 1.0 / (float)(png_ptr->screen_gamma * png_ptr->gamma);
          break;
        case 3:
          v68 = 1.0 / png_ptr->background_gamma;
          v69 = 1.0 / (float)(png_ptr->screen_gamma * png_ptr->background_gamma);
          break;
        default:
          break;
      }
      LODWORD(v71) = png_ptr->background.gray;
      v72 = 1.0 / v70;
      *((double *)&v73 + 1) = v68;
      HIDWORD(v71) = (1 << png_ptr->bit_depth) - 1;
      *(double *)&v73 = (double)v71 * (1.0 / v70);
      v74 = pow(x: v73, y: v25);
      LODWORD(v75) = png_ptr->background.gray;
      *((double *)&v74 + 1) = v69;
      png_ptr->background_1.gray = (__int64)(*(double *)&v74 * v70 + 0.5);
      *(double *)&v74 = (double)v75 * (1.0 / v70);
      v78 = pow(x: v74, y: v76);
      v79 = png_ptr->background.green;
      LODWORD(v80) = png_ptr->background.red;
      HIDWORD(v80) = (unsigned __int16)(__int64)(*(double *)&v78 * v70 + 0.5);
      png_ptr->background.gray = WORD1(v80);
      if ( (_DWORD)v80 == v79
        && (_DWORD)v80 == png_ptr->background.blue
        && (_DWORD)v80 == (unsigned __int16)(__int64)(*(double *)&v78 * v70 + 0.5) )
      {
        LOWORD(v80) = png_ptr->background_1.gray;
        png_ptr->background.blue = WORD1(v80);
        png_ptr->background.green = WORD1(v80);
        png_ptr->background.red = WORD1(v80);
        png_ptr->background_1.blue = v80;
        png_ptr->background_1.green = v80;
        png_ptr->background_1.red = v80;
      }
      else
      {
        *((double *)&v81 + 1) = v68;
        *(double *)&v81 = (double)v80 * v72;
        v82 = pow(x: v81, y: v77);
        LODWORD(v83) = png_ptr->background.green;
        *((double *)&v82 + 1) = v68;
        v126 = (__int64)(*(double *)&v82 * v70 + 0.5);
        *(double *)&v82 = (double)v83 * v72;
        png_ptr->background_1.red = v126;
        v85 = pow(x: v82, y: v84);
        LODWORD(v86) = png_ptr->background.blue;
        *((double *)&v85 + 1) = v68;
        png_ptr->background_1.green = (__int64)(*(double *)&v85 * v70 + 0.5);
        *(double *)&v85 = (double)v86 * v72;
        v88 = pow(x: v85, y: v87);
        LODWORD(v89) = png_ptr->background.red;
        *((double *)&v90 + 1) = *(double *)&v88 * v70 + 0.5;
        *((double *)&v88 + 1) = v69;
        *(_QWORD *)&v90 = v89;
        png_ptr->background_1.blue = (__int64)*((double *)&v90 + 1);
        *(double *)&v88 = (double)v89 * v72;
        v91 = pow(x: v88, y: v90);
        LODWORD(v92) = png_ptr->background.green;
        *((double *)&v91 + 1) = v69;
        png_ptr->background.red = (__int64)(*(double *)&v91 * v70 + 0.5);
        *(double *)&v91 = (double)v92 * v72;
        v94 = pow(x: v91, y: v93);
        LODWORD(v95) = png_ptr->background.blue;
        *((double *)&v94 + 1) = v69;
        png_ptr->background.green = (__int64)(*(double *)&v94 * v70 + 0.5);
        *(double *)&v94 = (double)v95 * v72;
        v97 = pow(x: v94, y: v96);
        png_ptr->background.blue = (__int64)(*(double *)&v97 * v70 + 0.5);
      }
    }
    else if ( color_type == 3 )
    {
      if ( png_ptr->num_palette != 0 )
      {
        v98 = png_ptr->num_palette;
        v99 = &png_ptr->palette[-1].blue;
        do
        {
          v100 = v99[2];
          v101 = v99[3];
          v99[1] = png_ptr->gamma_table[v99[1]];
          v99[2] = png_ptr->gamma_table[v100];
          v99 += 3;
          *v99 = png_ptr->gamma_table[v101];
          --v98;
        }
        while ( v98 != 0 );
      }
      png_ptr->transformations &= ~0x2000u;
    }
  }
LABEL_92:
  if ( (png_ptr->transformations & 8) != 0 && color_type == 3 )
  {
    v114 = 8 - png_ptr->sig_bit.red;
    v115 = 8 - png_ptr->sig_bit.green;
    v116 = png_ptr->num_palette;
    v117 = 8 - png_ptr->sig_bit.blue;
    if ( png_ptr->sig_bit.red > 8u || v114 > 8 )
      LOBYTE(v114) = 0;
    if ( v115 > 8 )
      LOBYTE(v115) = 0;
    if ( v117 > 8 )
      LOBYTE(v117) = 0;
    if ( png_ptr->num_palette != 0 )
    {
      v118 = v117;
      v119 = v114;
      v120 = 0;
      do
      {
        v121 = v120;
        png_ptr->palette[v121].red = png_ptr->palette[v120].red >> v119;
        png_ptr->palette[v121].green >>= v115;
        v122 = &png_ptr->palette[v120];
        v120 = (unsigned __int16)(v120 + 1);
        v122->blue >>= v118;
      }
      while ( v120 < v116 );
    }
  }
}


// ========================================================================
// png_do_read_transformations
// EA  : 0x8321B210
// RVA : 0x0121B210
// PDB : w:\tech5\libs\png\pngrtran.c
// ========================================================================

void __fastcall png_do_read_transformations(png_struct_def *png_ptr)
{
  unsigned int transformations; // r11
  png_color_16_struct *p_trans_values; // r5
  unsigned int v4; // r11
  unsigned int v5; // r8
  unsigned int v6; // r11
  void (__fastcall *read_user_transform_fn)(png_struct_def *, png_row_info_struct *, unsigned __int8 *); // r11
  unsigned int width; // r10
  unsigned int v9; // r11
  unsigned __int16 **v10; // [sp+8h] [-D8h]
  unsigned __int16 **v11; // [sp+Ch] [-D4h]
  unsigned __int16 **v12; // [sp+10h] [-D0h]
  int v13; // [sp+14h] [-CCh]
  int v14; // [sp+18h] [-C8h]
  int v15; // [sp+1Ch] [-C4h]
  int v16; // [sp+20h] [-C0h]
  int v17; // [sp+24h] [-BCh]
  int v18; // [sp+28h] [-B8h]
  int v19; // [sp+2Ch] [-B4h]
  int v20; // [sp+30h] [-B0h]
  int v21; // [sp+34h] [-ACh]
  int v22; // [sp+38h] [-A8h]
  int v23; // [sp+3Ch] [-A4h]
  int v24; // [sp+40h] [-A0h]
  int v25; // [sp+44h] [-9Ch]
  int v26; // [sp+48h] [-98h]
  int v27; // [sp+4Ch] [-94h]
  int v28; // [sp+50h] [-90h]
  int v29; // [sp+58h] [-88h]
  int v30; // [sp+60h] [-80h]
  int v31; // [sp+68h] [-78h]
  char v32[112]; // [sp+70h] [-70h] BYREF

  if ( png_ptr->row_buf == nullptr )
  {
    snprintf_0(
      string: v32,
      count: 0x32u,
      format: "NULL row buffer for row %ld, pass %d",
      png_ptr->row_number,
      png_ptr->pass);
    png_error(png_ptr, error_message: v32);
  }
  if ( (png_ptr->flags & 0x40) == 0 )
    png_error(png_ptr, error_message: "Uninitialized row");
  transformations = png_ptr->transformations;
  if ( (transformations & 0x1000) != 0 )
  {
    if ( png_ptr->row_info.color_type == 3 )
    {
      png_do_expand_palette(
        row_info: &png_ptr->row_info,
        row: png_ptr->row_buf + 1,
        palette: png_ptr->palette,
        trans: png_ptr->trans,
        num_trans: png_ptr->num_trans);
    }
    else
    {
      if ( png_ptr->num_trans == 0 || (p_trans_values = &png_ptr->trans_values, (transformations & 0x2000000) == 0) )
        p_trans_values = nullptr;
      png_do_expand(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1, trans_value: p_trans_values);
    }
  }
  v4 = png_ptr->flags & 0x400000;
  if ( v4 != 0 )
    png_do_strip_filler(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1, flags: v4 | 0x80);
  if ( (png_ptr->transformations & 0x600000) != 0
    && png_do_rgb_to_gray(png_ptr, row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1) != 0 )
  {
    v5 = png_ptr->transformations & 0x600000;
    png_ptr->rgb_to_gray_status = 1;
    if ( v5 == 0x400000 )
      png_warning(png_ptr, warning_message: "png_do_rgb_to_gray found nongray pixel");
    if ( (png_ptr->transformations & 0x600000) == 0x200000 )
      png_error(png_ptr, error_message: "png_do_rgb_to_gray found nongray pixel");
  }
  if ( (png_ptr->transformations & 0x4000) != 0 && (png_ptr->mode & 0x800) == 0 )
    png_do_gray_to_rgb(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x80) != 0 && (png_ptr->num_trans != 0 || (png_ptr->color_type & 4) != 0) )
    png_do_background(
      row_info: &png_ptr->row_info,
      row: png_ptr->row_buf + 1,
      trans_values: &png_ptr->trans_values,
      background: &png_ptr->background,
      background_1: &png_ptr->background_1,
      gamma_table: png_ptr->gamma_table,
      gamma_from_1: png_ptr->gamma_from_1,
      gamma_to_1: png_ptr->gamma_to_1,
      gamma_16: v10,
      gamma_16_from_1: v11,
      gamma_16_to_1: v12,
      gamma_shift: v13,
      a13: v14,
      a14: v15,
      a15: v16,
      a16: v17,
      a17: v18,
      a18: v19,
      a19: v20,
      a20: v21,
      a21: v22,
      a22: v23,
      a23: v24,
      a24: v25,
      a25: v26,
      a26: v27,
      a27: v28,
      a28: (int)png_ptr->gamma_16_table,
      a29: v29,
      a30: (int)png_ptr->gamma_16_from_1,
      a31: v30,
      a32: (int)png_ptr->gamma_16_to_1,
      a33: v31,
      a34: png_ptr->gamma_shift);
  v6 = png_ptr->transformations;
  if ( (v6 & 0x2000) != 0
    && ((v6 & 0x80) == 0 || png_ptr->num_trans == 0 && (png_ptr->color_type & 4) == 0)
    && png_ptr->color_type != 3 )
  {
    png_do_gamma(
      row_info: &png_ptr->row_info,
      row: png_ptr->row_buf + 1,
      gamma_table: png_ptr->gamma_table,
      gamma_16_table: png_ptr->gamma_16_table,
      gamma_shift: png_ptr->gamma_shift);
  }
  if ( (png_ptr->transformations & 0x400) != 0 )
    png_do_chop(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x40) != 0 )
  {
    png_do_dither(
      row_info: &png_ptr->row_info,
      row: png_ptr->row_buf + 1,
      palette_lookup: png_ptr->palette_lookup,
      dither_lookup: png_ptr->dither_index);
    if ( png_ptr->row_info.rowbytes == 0 )
      png_error(png_ptr, error_message: "png_do_dither returned rowbytes=0");
  }
  if ( (png_ptr->transformations & 0x20) != 0 )
    png_do_invert(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 8) != 0 )
    png_do_unshift(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1, sig_bits: &png_ptr->shift);
  if ( (png_ptr->transformations & 4) != 0 )
    png_do_unpack(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 1) != 0 )
    png_do_bgr(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x10000) != 0 )
    png_do_packswap(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x4000) != 0 && (png_ptr->mode & 0x800) != 0 )
    png_do_gray_to_rgb(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x8000) != 0 )
    png_do_read_filler(
      row_info: &png_ptr->row_info,
      row: png_ptr->row_buf + 1,
      filler: png_ptr->filler,
      flags: png_ptr->flags);
  if ( (png_ptr->transformations & 0x80000) != 0 )
    png_do_read_invert_alpha(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x20000) != 0 )
    png_do_read_swap_alpha(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x10) != 0 )
    png_do_swap(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  if ( (png_ptr->transformations & 0x100000) != 0 )
  {
    read_user_transform_fn = png_ptr->read_user_transform_fn;
    if ( read_user_transform_fn != nullptr )
      read_user_transform_fn(a1: png_ptr, a2: &png_ptr->row_info, a3: png_ptr->row_buf + 1);
    if ( png_ptr->user_transform_depth != 0 )
      png_ptr->row_info.bit_depth = png_ptr->user_transform_depth;
    if ( png_ptr->user_transform_channels != 0 )
      png_ptr->row_info.channels = png_ptr->user_transform_channels;
    width = png_ptr->row_info.width;
    v9 = (unsigned __int8)(png_ptr->row_info.channels * png_ptr->row_info.bit_depth);
    png_ptr->row_info.pixel_depth = v9;
    if ( v9 < 8 )
      png_ptr->row_info.rowbytes = (width * v9 + 7) >> 3;
    else
      png_ptr->row_info.rowbytes = (v9 >> 3) * width;
  }
}

