
// ========================================================================
// png_set_interlace_handling
// EA  : 0x832165F8
// RVA : 0x012165F8
// PDB : w:\tech5\libs\png\pngtrans.c
// ========================================================================

int __fastcall png_set_interlace_handling(png_struct_def *png_ptr)
{
  if ( png_ptr == nullptr || png_ptr->interlaced == 0 )
    return 1;
  png_ptr->transformations |= 2u;
  return 7;
}


// ========================================================================
// png_set_filler
// EA  : 0x83216630
// RVA : 0x01216630
// PDB : w:\tech5\libs\png\pngtrans.c
// ========================================================================

void __fastcall png_set_filler(png_struct_def *png_ptr, unsigned __int8 filler, int filler_loc)
{
  unsigned int v3; // r9
  unsigned int flags; // r11
  unsigned int v5; // r10
  int color_type; // r11

  if ( png_ptr != nullptr )
  {
    v3 = png_ptr->transformations | 0x8000;
    flags = png_ptr->flags;
    png_ptr->filler = filler;
    png_ptr->transformations = v3;
    v5 = flags | 0x80;
    if ( filler_loc != 1 )
      v5 = flags & 0xFFFFFF7F;
    color_type = png_ptr->color_type;
    png_ptr->flags = v5;
    if ( color_type == 2 )
      png_ptr->usr_channels = 4;
    if ( color_type == 0 && png_ptr->bit_depth >= 8u )
      png_ptr->usr_channels = 2;
  }
}


// ========================================================================
// png_do_invert
// EA  : 0x83216698
// RVA : 0x01216698
// PDB : w:\tech5\libs\png\pngtrans.c
// ========================================================================

void __fastcall png_do_invert(png_row_info_struct *row_info, unsigned __int8 *row)
{
  unsigned int v2; // ctr
  unsigned __int8 *v3; // r11
  char v4; // r10
  unsigned int rowbytes; // r11
  unsigned __int8 *v6; // r11
  unsigned int v7; // r10
  unsigned int v8; // ctr
  unsigned __int8 v9; // r10
  unsigned int v10; // r11
  unsigned __int8 *v11; // r11
  unsigned int v12; // r10
  unsigned int v13; // ctr
  unsigned __int8 v14; // r3

  if ( row_info->color_type != 0 )
  {
    if ( row_info->color_type == 4 )
    {
      if ( row_info->bit_depth == 8 )
      {
        rowbytes = row_info->rowbytes;
        if ( rowbytes != 0 )
        {
          v7 = (rowbytes - 1) >> 1;
          v6 = row - 2;
          v8 = v7 + 1;
          do
          {
            v9 = v6[2];
            v6 += 2;
            *v6 = ~v9;
            --v8;
          }
          while ( v8 != 0 );
        }
      }
      else if ( row_info->bit_depth == 16 )
      {
        v10 = row_info->rowbytes;
        if ( v10 != 0 )
        {
          v12 = (v10 - 1) >> 2;
          v11 = row - 3;
          v13 = v12 + 1;
          do
          {
            v14 = ~v11[4];
            v11[3] = ~v11[3];
            v11 += 4;
            *v11 = v14;
            --v13;
          }
          while ( v13 != 0 );
        }
      }
    }
  }
  else if ( row_info->rowbytes != 0 )
  {
    v2 = row_info->rowbytes;
    v3 = row - 1;
    do
    {
      v4 = *++v3;
      *v3 = ~v4;
      --v2;
    }
    while ( v2 != 0 );
  }
}


// ========================================================================
// png_do_swap
// EA  : 0x83216788
// RVA : 0x01216788
// PDB : w:\tech5\libs\png\pngtrans.c
// ========================================================================

void __fastcall png_do_swap(png_row_info_struct *row_info, unsigned __int8 *row)
{
  unsigned int v2; // ctr
  unsigned __int8 *v3; // r11
  unsigned __int8 v4; // r9

  if ( row_info->bit_depth == 16 && row_info->channels * row_info->width != 0 )
  {
    v2 = row_info->channels * row_info->width;
    v3 = row - 1;
    do
    {
      v4 = v3[1];
      v3[1] = v3[2];
      v3 += 2;
      *v3 = v4;
      --v2;
    }
    while ( v2 != 0 );
  }
}


// ========================================================================
// png_do_packswap
// EA  : 0x832167C8
// RVA : 0x012167C8
// PDB : w:\tech5\libs\png\pngtrans.c
// ========================================================================

void __fastcall png_do_packswap(png_row_info_struct *row_info, unsigned __int8 *row)
{
  unsigned int bit_depth; // r11
  const unsigned __int8 *v3; // r10
  unsigned __int8 *v4; // r11
  unsigned int rowbytes; // ctr
  unsigned __int8 v6; // r7

  bit_depth = row_info->bit_depth;
  if ( bit_depth < 8 )
  {
    switch ( bit_depth )
    {
      case 1u:
        v3 = onebppswaptable;
        break;
      case 2u:
        v3 = twobppswaptable;
        break;
      case 4u:
        v3 = fourbppswaptable;
        break;
      default:
        return;
    }
    if ( row < &row[row_info->rowbytes] )
    {
      v4 = row - 1;
      rowbytes = row_info->rowbytes;
      do
      {
        v6 = v3[*++v4];
        *v4 = v6;
        --rowbytes;
      }
      while ( rowbytes != 0 );
    }
  }
}


// ========================================================================
// png_do_strip_filler
// EA  : 0x83216848
// RVA : 0x01216848
// PDB : w:\tech5\libs\png\pngtrans.c
// ========================================================================

void __fastcall png_do_strip_filler(png_row_info_struct *row_info, unsigned __int8 *row, unsigned int flags)
{
  int color_type; // r9
  unsigned __int8 *v4; // r11
  unsigned int width; // r8
  unsigned __int8 *v6; // r10
  unsigned __int8 *v7; // r9
  unsigned __int8 *v8; // r11
  unsigned int v9; // ctr
  _BYTE *v10; // r11
  _BYTE *v11; // r9
  char v12; // r10
  unsigned __int8 v13; // r11
  unsigned int v14; // ctr
  unsigned __int8 *v15; // r11
  unsigned __int8 *v16; // r10
  unsigned __int8 v17; // r9
  unsigned __int8 *v18; // r9
  unsigned __int8 *v19; // r11
  unsigned int v20; // ctr
  _BYTE *v21; // r9
  _BYTE *v22; // r11
  char v23; // r10
  unsigned int v24; // ctr
  unsigned __int8 *v25; // r11
  _BYTE *v26; // r10
  unsigned __int8 v27; // r9
  unsigned int v28; // ctr
  unsigned __int8 *v29; // r10
  unsigned __int8 *v30; // r11
  unsigned __int8 v31; // r11
  unsigned int v32; // ctr
  unsigned __int8 *v33; // r10
  unsigned __int8 v34; // r9
  unsigned __int8 *v35; // r10
  unsigned __int8 *v36; // r11
  unsigned int v37; // ctr
  unsigned __int8 v38; // r9
  unsigned int v39; // ctr
  unsigned __int8 *v40; // r11
  unsigned __int8 v41; // r9

  color_type = row_info->color_type;
  v4 = row;
  width = row_info->width;
  v6 = row;
  if ( (color_type == 2 || color_type == 6 && (flags & 0x400000) != 0) && row_info->channels == 4 )
  {
    if ( row_info->bit_depth != 8 )
    {
      if ( (flags & 0x80) != 0 )
      {
        v18 = row + 8;
        v19 = row + 6;
        if ( width > 1 )
        {
          v20 = width - 1;
          do
          {
            *v19 = *v18;
            v21 = v18 + 1;
            v22 = v19 + 1;
            *v22 = *v21++;
            *++v22 = *v21++;
            *++v22 = *v21++;
            *++v22 = *v21;
            v23 = v21[1];
            v18 = v21 + 4;
            v22[1] = v23;
            v19 = v22 + 2;
            --v20;
          }
          while ( v20 != 0 );
        }
      }
      else if ( width != 0 )
      {
        v24 = row_info->width;
        do
        {
          v25 = v4 + 2;
          *v6 = *v25++;
          v26 = v6 + 1;
          *v26 = *v25++;
          *++v26 = *v25++;
          *++v26 = *v25++;
          *++v26 = *v25;
          v27 = v25[1];
          v4 = v25 + 2;
          v26[1] = v27;
          v6 = v26 + 2;
          --v24;
        }
        while ( v24 != 0 );
      }
      row_info->pixel_depth = 48;
      v13 = 3;
      row_info->rowbytes = 6 * width;
      goto LABEL_48;
    }
    if ( (flags & 0x80) != 0 )
    {
      v7 = row + 3;
      v8 = row + 4;
      if ( width > 1 )
      {
        v9 = width - 1;
        do
        {
          *v7 = *v8;
          v10 = v8 + 1;
          v11 = v7 + 1;
          *v11 = *v10;
          v12 = v10[1];
          v8 = v10 + 3;
          v11[1] = v12;
          v7 = v11 + 2;
          --v9;
        }
        while ( v9 != 0 );
        row_info->pixel_depth = 24;
        v13 = 3;
        row_info->rowbytes = 3 * width;
        goto LABEL_48;
      }
    }
    else if ( width != 0 )
    {
      v14 = row_info->width;
      do
      {
        v15 = v4 + 1;
        *v6 = *v15++;
        v16 = v6 + 1;
        *v16 = *v15;
        v17 = v15[1];
        v4 = v15 + 2;
        v16[1] = v17;
        v6 = v16 + 2;
        --v14;
      }
      while ( v14 != 0 );
    }
    row_info->pixel_depth = 24;
    v13 = 3;
    row_info->rowbytes = 3 * width;
LABEL_48:
    row_info->channels = v13;
    goto LABEL_49;
  }
  if ( (row_info->color_type == 0 || color_type == 4 && (flags & 0x400000) != 0) && row_info->channels == 2 )
  {
    if ( row_info->bit_depth != 8 )
    {
      if ( (flags & 0x80) != 0 )
      {
        v35 = row + 4;
        v36 = row + 2;
        if ( width > 1 )
        {
          v37 = width - 1;
          do
          {
            *v36 = *v35;
            v38 = v35[1];
            v35 += 4;
            v36[1] = v38;
            v36 += 2;
            --v37;
          }
          while ( v37 != 0 );
        }
      }
      else if ( width != 0 )
      {
        v39 = row_info->width;
        do
        {
          v40 = v4 + 2;
          *v6 = *v40;
          v41 = v40[1];
          v4 = v40 + 2;
          v6[1] = v41;
          v6 += 2;
          --v39;
        }
        while ( v39 != 0 );
      }
      v31 = 16;
      row_info->rowbytes = 2 * width;
      goto LABEL_47;
    }
    if ( (flags & 0x80) != 0 )
    {
      if ( width != 0 )
      {
        v28 = row_info->width;
        v29 = row - 1;
        v30 = row - 2;
        do
        {
          v30 += 2;
          *++v29 = *v30;
          --v28;
        }
        while ( v28 != 0 );
        v31 = 8;
        row_info->rowbytes = width;
        goto LABEL_47;
      }
    }
    else if ( width != 0 )
    {
      v32 = row_info->width;
      v33 = row - 1;
      do
      {
        v34 = v4[1];
        v4 += 2;
        *++v33 = v34;
        --v32;
      }
      while ( v32 != 0 );
    }
    v31 = 8;
    row_info->rowbytes = width;
LABEL_47:
    row_info->pixel_depth = v31;
    v13 = 1;
    goto LABEL_48;
  }
LABEL_49:
  if ( (flags & 0x400000) != 0 )
    row_info->color_type &= ~4u;
}


// ========================================================================
// png_do_bgr
// EA  : 0x83216B40
// RVA : 0x01216B40
// PDB : w:\tech5\libs\png\pngtrans.c
// ========================================================================

void __fastcall png_do_bgr(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r9
  int bit_depth; // r10
  unsigned int width; // r11
  unsigned int v5; // ctr
  unsigned __int8 *v6; // r11
  unsigned __int8 v7; // r9
  unsigned int v8; // ctr
  unsigned __int8 *v9; // r11
  unsigned __int8 v10; // r9
  unsigned __int8 *v11; // r10
  unsigned int v12; // ctr
  unsigned __int8 v13; // r9
  unsigned __int8 v14; // r8
  unsigned __int8 v15; // r7
  unsigned __int8 *v16; // r10
  unsigned int v17; // ctr
  unsigned __int8 v18; // r9
  unsigned __int8 v19; // r8
  unsigned __int8 v20; // r7

  color_type = row_info->color_type;
  if ( (color_type & 2) != 0 )
  {
    bit_depth = row_info->bit_depth;
    width = row_info->width;
    if ( bit_depth == 8 )
    {
      if ( color_type == 2 )
      {
        if ( width != 0 )
        {
          v5 = row_info->width;
          v6 = row - 1;
          do
          {
            v7 = v6[1];
            v6[1] = v6[3];
            v6 += 3;
            *v6 = v7;
            --v5;
          }
          while ( v5 != 0 );
        }
      }
      else if ( color_type == 6 && width != 0 )
      {
        v8 = row_info->width;
        v9 = row - 2;
        do
        {
          v10 = v9[2];
          v9[2] = v9[4];
          v9 += 4;
          *v9 = v10;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
    else if ( bit_depth == 16 )
    {
      if ( color_type == 2 )
      {
        if ( width != 0 )
        {
          v11 = row - 1;
          v12 = row_info->width;
          do
          {
            v13 = v11[5];
            v14 = v11[6];
            v15 = v11[2];
            v11[5] = v11[1];
            v11[1] = v13;
            v11[2] = v14;
            v11 += 6;
            *v11 = v15;
            --v12;
          }
          while ( v12 != 0 );
        }
      }
      else if ( color_type == 6 && width != 0 )
      {
        v16 = row - 3;
        v17 = row_info->width;
        do
        {
          v18 = v16[7];
          v19 = v16[8];
          v20 = v16[4];
          v16[7] = v16[3];
          v16[3] = v18;
          v16[4] = v19;
          v16 += 8;
          *v16 = v20;
          --v17;
        }
        while ( v17 != 0 );
      }
    }
  }
}

