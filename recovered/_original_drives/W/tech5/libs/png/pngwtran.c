
// ========================================================================
// png_do_pack
// EA  : 0x83230B68
// RVA : 0x01230B68
// PDB : w:\tech5\libs\png\pngwtran.c
// ========================================================================

void __fastcall png_do_pack(png_row_info_struct *row_info, unsigned __int8 *row, unsigned int bit_depth)
{
  unsigned __int8 *v3; // r8
  int v4; // r10
  int v5; // r11
  unsigned int v6; // ctr
  unsigned __int8 *v7; // r8
  int v8; // r10
  int v9; // r11
  unsigned int v10; // ctr
  unsigned __int8 *v11; // r8
  int v12; // r11
  unsigned __int8 v13; // r10
  unsigned int width; // ctr
  unsigned int v15; // r10
  unsigned __int8 v16; // r9

  if ( row_info->bit_depth == 8 && row_info->channels == 1 )
  {
    switch ( bit_depth )
    {
      case 1u:
        v11 = row;
        v12 = 128;
        v13 = 0;
        if ( row_info->width != 0 )
        {
          width = row_info->width;
          do
          {
            if ( *v11 != 0 )
              v13 |= v12;
            ++v11;
            if ( v12 <= 1 )
            {
              *row = v13;
              v12 = 128;
              ++row;
              v13 = 0;
            }
            else
            {
              v12 >>= 1;
            }
            --width;
          }
          while ( width != 0 );
          if ( v12 != 128 )
            *row = v13;
        }
        break;
      case 2u:
        v7 = row;
        v8 = 6;
        v9 = 0;
        if ( row_info->width != 0 )
        {
          v10 = row_info->width;
          do
          {
            v9 |= (*v7 & 3) << v8;
            if ( v8 != 0 )
            {
              v8 -= 2;
            }
            else
            {
              *row = v9;
              v8 = 6;
              ++row;
              v9 = 0;
            }
            ++v7;
            --v10;
          }
          while ( v10 != 0 );
          if ( v8 != 6 )
            *row = v9;
        }
        break;
      case 4u:
        v3 = row;
        v4 = 4;
        v5 = 0;
        if ( row_info->width != 0 )
        {
          v6 = row_info->width;
          do
          {
            v5 |= (*v3 & 0xF) << v4;
            if ( v4 != 0 )
            {
              v4 -= 4;
            }
            else
            {
              *row = v5;
              v4 = 4;
              ++row;
              v5 = 0;
            }
            ++v3;
            --v6;
          }
          while ( v6 != 0 );
          if ( v4 != 4 )
            *row = v5;
        }
        break;
      default:
        break;
    }
    v15 = row_info->width;
    v16 = row_info->channels * bit_depth;
    row_info->bit_depth = bit_depth;
    row_info->pixel_depth = v16;
    if ( v16 < 8u )
      row_info->rowbytes = (v16 * v15 + 7) >> 3;
    else
      row_info->rowbytes = (v16 >> 3) * v15;
  }
}


// ========================================================================
// png_do_shift
// EA  : 0x83230D08
// RVA : 0x01230D08
// PDB : w:\tech5\libs\png\pngwtran.c
// ========================================================================

void __fastcall png_do_shift(png_row_info_struct *row_info, unsigned __int8 *row, png_color_8_struct *bit_depth)
{
  int color_type; // r9
  int v5; // r8
  unsigned int v6; // r30
  int v7; // r6
  int red; // r11
  int v9; // r29
  int v10; // r6
  int v11; // r4
  int alpha; // r11
  unsigned int v13; // r9
  int v14; // r8
  unsigned int v15; // r8
  int gray; // r11
  char v17; // r5
  int v18; // r7
  unsigned int rowbytes; // ctr
  unsigned __int16 v20; // r8
  int v21; // r11
  int v22; // r9
  unsigned __int8 v23; // r3
  unsigned int width; // r11
  unsigned int v25; // r4
  unsigned int i; // r6
  unsigned __int16 v27; // r7
  int v28; // r9
  int v29; // r5
  int j; // r11
  unsigned __int8 v31; // r3
  unsigned __int8 *v32; // r3
  unsigned int v33; // r29
  unsigned int k; // r5
  __int16 v35; // r7
  int v36; // r10
  __int16 v37; // r6
  int v38; // r31
  int v39; // r9
  int v40; // r11
  unsigned __int16 m; // r7
  _DWORD v42[4]; // [sp+0h] [-50h] BYREF
  _DWORD v43[16]; // [sp+10h] [-40h] BYREF

  color_type = row_info->color_type;
  if ( color_type != 3 )
  {
    v5 = row_info->bit_depth;
    if ( (color_type & 2) != 0 )
    {
      v6 = 3;
      v7 = v5 - bit_depth->green;
      red = bit_depth->red;
      v9 = v5 - bit_depth->blue;
      v42[2] = bit_depth->blue;
      v43[1] = v7;
      v43[2] = v9;
    }
    else
    {
      red = bit_depth->gray;
      v6 = 1;
    }
    v10 = v5 - red;
    v42[0] = red;
    v11 = red;
    v43[0] = v5 - red;
    if ( (color_type & 4) != 0 )
    {
      alpha = bit_depth->alpha;
      v13 = v6;
      v14 = row_info->bit_depth;
      ++v6;
      v42[v13] = alpha;
      v43[v13] = v14 - alpha;
      v10 = v43[0];
      v11 = v42[0];
    }
    v15 = row_info->bit_depth;
    if ( v15 >= 8 )
    {
      width = row_info->width;
      if ( v15 == 8 )
      {
        v25 = width * v6;
        for ( i = 0; i < v25; ++row )
        {
          v27 = *row;
          *row = 0;
          v28 = i % v6;
          __twllei(v6, 0);
          v29 = v42[v28];
          for ( j = v43[v28]; j > -v29; *row = v31 )
          {
            if ( j <= 0 )
              v31 = (v27 >> -(char)j) | *row;
            else
              v31 = ((_BYTE)v27 << j) | *row;
            j -= v29;
          }
          ++i;
        }
      }
      else
      {
        v32 = row;
        v33 = width * v6;
        for ( k = 0; k < v33; v32 += 2 )
        {
          v35 = v32[1];
          v36 = k % v6;
          v37 = __ROL4__(*v32, 8);
          __twllei(v6, 0);
          v38 = v42[v36];
          v39 = 0;
          v40 = v43[v36];
          for ( m = v37 + v35; v40 > -v38; v40 -= v38 )
          {
            if ( v40 <= 0 )
              v39 |= m >> -(char)v40;
            else
              v39 = (unsigned __int16)((m << v40) | v39);
          }
          ++k;
          *(_WORD *)v32 = v39;
        }
      }
    }
    else
    {
      gray = bit_depth->gray;
      if ( gray == 1 && v15 == 2 )
      {
        v17 = 85;
      }
      else if ( v15 != 4 || (v17 = 17, gray != 3) )
      {
        v17 = -1;
      }
      if ( row_info->rowbytes != 0 )
      {
        v18 = -v11;
        rowbytes = row_info->rowbytes;
        do
        {
          v20 = *row;
          v21 = v10;
          *row = 0;
          if ( v10 > v18 )
          {
            v22 = -v10;
            do
            {
              if ( v21 <= 0 )
                v23 = (v20 >> v22) & v17 | *row;
              else
                v23 = (v20 << v21) | *row;
              v21 -= v11;
              *row = v23;
              LOBYTE(v22) = v22 + v11;
            }
            while ( v21 > v18 );
          }
          ++row;
          --rowbytes;
        }
        while ( rowbytes != 0 );
      }
    }
  }
}


// ========================================================================
// png_do_write_swap_alpha
// EA  : 0x83230FF8
// RVA : 0x01230FF8
// PDB : w:\tech5\libs\png\pngwtran.c
// ========================================================================

void __fastcall png_do_write_swap_alpha(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r10
  unsigned __int8 *v3; // r11
  unsigned int width; // r9
  unsigned __int8 *v5; // r10
  unsigned int v6; // ctr
  unsigned __int8 v7; // r8
  unsigned __int8 *v8; // r11
  unsigned __int8 *v9; // r10
  unsigned __int8 v10; // r9
  unsigned int v11; // ctr
  unsigned __int8 v12; // r7
  unsigned __int8 v13; // r9
  unsigned __int8 *v14; // r11
  _BYTE *v15; // r10
  unsigned __int8 v16; // r8
  unsigned int v17; // r9
  unsigned __int8 *v18; // r10
  unsigned int v19; // ctr
  unsigned __int8 v20; // r8
  unsigned __int8 v21; // r9
  unsigned int v22; // ctr
  unsigned __int8 v23; // r7
  unsigned __int8 v24; // r9
  unsigned __int8 *v25; // r11
  unsigned __int8 v26; // r8

  color_type = row_info->color_type;
  v3 = row;
  if ( color_type == 6 )
  {
    width = row_info->width;
    v5 = row;
    if ( row_info->bit_depth == 8 )
    {
      if ( width != 0 )
      {
        v6 = row_info->width;
        do
        {
          v7 = *v3;
          v8 = v3 + 1;
          *v5 = *v8++;
          v9 = v5 + 1;
          *v9 = *v8;
          v10 = v8[1];
          v3 = v8 + 2;
          v9[1] = v10;
          v9[2] = v7;
          v5 = v9 + 3;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
    else if ( width != 0 )
    {
      v11 = row_info->width;
      do
      {
        v12 = *v3;
        v13 = v3[1];
        v14 = v3 + 2;
        *v5 = *v14++;
        v15 = v5 + 1;
        *v15 = *v14++;
        *++v15 = *v14++;
        *++v15 = *v14++;
        *++v15 = *v14;
        v16 = v14[1];
        v3 = v14 + 2;
        v15[1] = v16;
        v15[2] = v12;
        v15[3] = v13;
        v5 = v15 + 4;
        --v11;
      }
      while ( v11 != 0 );
    }
  }
  else if ( color_type == 4 )
  {
    v17 = row_info->width;
    v18 = row;
    if ( row_info->bit_depth == 8 )
    {
      if ( v17 != 0 )
      {
        v19 = row_info->width;
        do
        {
          v20 = *v3;
          v21 = v3[1];
          v3 += 2;
          *v18 = v21;
          v18[1] = v20;
          v18 += 2;
          --v19;
        }
        while ( v19 != 0 );
      }
    }
    else if ( v17 != 0 )
    {
      v22 = row_info->width;
      do
      {
        v23 = *v3;
        v24 = v3[1];
        v25 = v3 + 2;
        *v18 = *v25;
        v26 = v25[1];
        v3 = v25 + 2;
        v18[1] = v26;
        v18[2] = v23;
        v18[3] = v24;
        v18 += 4;
        --v22;
      }
      while ( v22 != 0 );
    }
  }
}


// ========================================================================
// png_do_write_invert_alpha
// EA  : 0x83231138
// RVA : 0x01231138
// PDB : w:\tech5\libs\png\pngwtran.c
// ========================================================================

void __fastcall png_do_write_invert_alpha(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r10
  unsigned __int8 *v3; // r11
  unsigned int width; // r10
  unsigned int v5; // ctr
  unsigned int v6; // ctr
  _BYTE *v7; // r11
  unsigned __int8 *v8; // r10
  unsigned int v9; // ctr
  _BYTE *v10; // r11
  unsigned int v11; // ctr
  _BYTE *v12; // r11

  color_type = row_info->color_type;
  v3 = row;
  if ( color_type == 6 )
  {
    width = row_info->width;
    if ( row_info->bit_depth == 8 )
    {
      if ( width != 0 )
      {
        v5 = row_info->width;
        do
        {
          v3[3] = -1 - v3[3];
          v3 += 4;
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
        v7 = v3 + 6;
        *v7 = -1 - *v7;
        v7[1] = -1 - v7[1];
        v3 = v7 + 2;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  else if ( color_type == 4 )
  {
    if ( row_info->bit_depth == 8 )
    {
      v8 = row;
      if ( row_info->width != 0 )
      {
        v9 = row_info->width;
        do
        {
          *v8 = *v3;
          v10 = v3 + 1;
          v8[1] = -1 - *v10;
          v3 = v10 + 1;
          v8 += 2;
          --v9;
        }
        while ( v9 != 0 );
      }
    }
    else if ( row_info->width != 0 )
    {
      v11 = row_info->width;
      do
      {
        v12 = v3 + 2;
        *v12 = -1 - *v12;
        v12[1] = -1 - v12[1];
        v3 = v12 + 2;
        --v11;
      }
      while ( v11 != 0 );
    }
  }
}


// ========================================================================
// png_do_write_intrapixel
// EA  : 0x83231250
// RVA : 0x01231250
// PDB : w:\tech5\libs\png\pngwtran.c
// ========================================================================

void __fastcall png_do_write_intrapixel(png_row_info_struct *row_info, unsigned __int8 *row)
{
  int color_type; // r9
  int bit_depth; // r11
  unsigned int width; // r10
  int v5; // r9
  unsigned __int8 *v6; // r11
  unsigned int v7; // ctr
  unsigned __int8 v8; // r7
  char v9; // r6
  int v10; // r9
  unsigned __int8 *v11; // r11
  unsigned int v12; // ctr
  int v13; // r6
  int v14; // r5

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
          v8 = *v6;
          v9 = *(v6 - 1);
          *(v6 - 2) -= v9;
          *v6 = v8 - v9;
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
          v13 = __ROL4__(v11[3], 8) | v11[4];
          v14 = __ROL4__(v11[1], 8) | v11[2];
          *(_WORD *)(v11 - 1) = (__ROL4__(*(v11 - 1), 8) | *v11) - v14;
          *(_WORD *)(v11 + 3) = v13 - v14;
          v11 += v10;
          --v12;
        }
        while ( v12 != 0 );
      }
    }
  }
}


// ========================================================================
// png_do_write_transformations
// EA  : 0x83231378
// RVA : 0x01231378
// PDB : w:\tech5\libs\png\pngwtran.c
// ========================================================================

void __fastcall png_do_write_transformations(png_struct_def *png_ptr)
{
  void (__fastcall *write_user_transform_fn)(png_struct_def *, png_row_info_struct *, unsigned __int8 *); // r11

  if ( png_ptr != nullptr )
  {
    if ( (png_ptr->transformations & 0x100000) != 0 )
    {
      write_user_transform_fn = png_ptr->write_user_transform_fn;
      if ( write_user_transform_fn != nullptr )
        write_user_transform_fn(a1: png_ptr, a2: &png_ptr->row_info, a3: png_ptr->row_buf + 1);
    }
    if ( (png_ptr->transformations & 0x8000) != 0 )
      png_do_strip_filler(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1, flags: png_ptr->flags);
    if ( (png_ptr->transformations & 0x10000) != 0 )
      png_do_packswap(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
    if ( (png_ptr->transformations & 4) != 0 )
      png_do_pack(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1, bit_depth: png_ptr->bit_depth);
    if ( (png_ptr->transformations & 0x10) != 0 )
      png_do_swap(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
    if ( (png_ptr->transformations & 8) != 0 )
      png_do_shift(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1, bit_depth: &png_ptr->shift);
    if ( (png_ptr->transformations & 0x20000) != 0 )
      png_do_write_swap_alpha(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
    if ( (png_ptr->transformations & 0x80000) != 0 )
      png_do_write_invert_alpha(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
    if ( (png_ptr->transformations & 1) != 0 )
      png_do_bgr(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
    if ( (png_ptr->transformations & 0x20) != 0 )
      png_do_invert(row_info: &png_ptr->row_info, row: png_ptr->row_buf + 1);
  }
}

