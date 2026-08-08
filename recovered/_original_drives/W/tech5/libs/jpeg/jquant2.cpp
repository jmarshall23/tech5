
// ========================================================================
// prescan_quantize
// EA  : 0x832393A8
// RVA : 0x012393A8
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall prescan_quantize(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_entropy_decoder *entropy; // r11
  J_DITHER_MODE dither_mode; // r3
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r7
  unsigned __int8 *v7; // r8
  J_DITHER_MODE i; // ctr
  int v9; // r10
  int v10; // r9
  int v11; // r11

  entropy = cinfo->entropy;
  dither_mode = cinfo->dither_mode;
  start_pass = entropy[2].start_pass;
  if ( num_rows > 0 )
  {
    do
    {
      v7 = *input_buf;
      if ( dither_mode != JDITHER_NONE )
      {
        for ( i = dither_mode; i != JDITHER_NONE; --i )
        {
          v9 = *(_DWORD *)((char *)start_pass + ((*v7 >> 1) & 0x7C));
          v10 = 2 * (((8 * v7[1]) & 0x7E0) + (v7[2] >> 3));
          v11 = (unsigned __int16)(*(_WORD *)(v10 + v9) + 1);
          *(_WORD *)(v10 + v9) = v11;
          if ( v11 == 0 )
            *(_WORD *)(v10 + v9) = -1;
          v7 += 3;
        }
      }
      --num_rows;
      ++input_buf;
    }
    while ( num_rows != 0 );
  }
}


// ========================================================================
// update_box
// EA  : 0x83239440
// RVA : 0x01239440
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall update_box(jpeg_decompress_struct *cinfo, box *boxp)
{
  int c0min; // r31
  int c0max; // r26
  int c1min; // r29
  int c1max; // r27
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r25
  int c2min; // r30
  int c2max; // r28
  int v9; // r3
  _DWORD *v10; // r5
  int v11; // r6
  int v12; // r8
  int v13; // r11
  _WORD *v14; // r9
  int v15; // r3
  _DWORD *v16; // r5
  int v17; // r6
  int v18; // r8
  int v19; // r11
  _WORD *v20; // r9
  int v21; // r5
  int v22; // r7
  int v23; // r6
  _DWORD *v24; // r8
  int v25; // r10
  _WORD *v26; // r9
  int v27; // r5
  int v28; // r7
  int v29; // r6
  _DWORD *v30; // r8
  int v31; // r10
  _WORD *v32; // r9
  int v33; // r6
  int v34; // r7
  _DWORD *v35; // r9
  int v36; // r11
  _WORD *v37; // r10
  int v38; // r6
  int v39; // r7
  _DWORD *v40; // r9
  int v41; // r11
  _WORD *v42; // r10
  int v43; // r3
  int v44; // r31
  _DWORD *v45; // r6
  int v46; // r7
  int v47; // r10
  _WORD *v48; // r11
  int v49; // ctr

  c0min = boxp->c0min;
  c0max = boxp->c0max;
  c1min = boxp->c1min;
  c1max = boxp->c1max;
  start_pass = cinfo->entropy[2].start_pass;
  c2min = boxp->c2min;
  c2max = boxp->c2max;
  if ( c0max > boxp->c0min )
  {
    v9 = boxp->c0min;
    v10 = (_DWORD *)((char *)start_pass + 4 * c0min);
    while ( 1 )
    {
      v11 = boxp->c1min;
      if ( c1min <= c1max )
        break;
LABEL_10:
      ++v9;
      ++v10;
      if ( v9 > c0max )
        goto have_c0min;
    }
    v12 = 2 * (32 * c1min + c2min);
    while ( 1 )
    {
      v13 = boxp->c2min;
      if ( c2min <= c2max )
        break;
LABEL_9:
      ++v11;
      v12 += 64;
      if ( v11 > c1max )
        goto LABEL_10;
    }
    v14 = (_WORD *)(*v10 + v12 - 2);
    while ( *++v14 == 0 )
    {
      if ( ++v13 > c2max )
        goto LABEL_9;
    }
    c0min = v9;
    boxp->c0min = v9;
have_c0min:
    if ( c0max > c0min )
    {
      v15 = c0max;
      v16 = (_DWORD *)((char *)start_pass + 4 * c0max);
      while ( 1 )
      {
        v17 = c1min;
        if ( c1min <= c1max )
          break;
LABEL_22:
        --v15;
        --v16;
        if ( v15 < c0min )
          goto have_c0max;
      }
      v18 = 2 * (32 * c1min + c2min);
      while ( 1 )
      {
        v19 = c2min;
        if ( c2min <= c2max )
          break;
LABEL_21:
        ++v17;
        v18 += 64;
        if ( v17 > c1max )
          goto LABEL_22;
      }
      v20 = (_WORD *)(*v16 + v18 - 2);
      while ( *++v20 == 0 )
      {
        if ( ++v19 > c2max )
          goto LABEL_21;
      }
      c0max = v15;
      boxp->c0max = v15;
    }
  }
have_c0max:
  if ( c1min < c1max )
  {
    v21 = c1min;
    v22 = 2 * (32 * c1min + c2min);
    while ( 1 )
    {
      v23 = c0min;
      if ( c0min <= c0max )
        break;
LABEL_34:
      ++v21;
      v22 += 64;
      if ( v21 > c1max )
        goto have_c1min;
    }
    v24 = (_DWORD *)((char *)start_pass + 4 * c0min);
    while ( 1 )
    {
      v25 = c2min;
      if ( c2min <= c2max )
        break;
LABEL_33:
      ++v23;
      ++v24;
      if ( v23 > c0max )
        goto LABEL_34;
    }
    v26 = (_WORD *)(*v24 + v22 - 2);
    while ( *++v26 == 0 )
    {
      if ( ++v25 > c2max )
        goto LABEL_33;
    }
    c1min = v21;
    boxp->c1min = v21;
have_c1min:
    if ( c1max > c1min )
    {
      v27 = c1max;
      v28 = 2 * (32 * c1max + c2min);
      while ( 1 )
      {
        v29 = c0min;
        if ( c0min <= c0max )
          break;
LABEL_46:
        --v27;
        v28 -= 64;
        if ( v27 < c1min )
          goto have_c1max;
      }
      v30 = (_DWORD *)((char *)start_pass + 4 * c0min);
      while ( 1 )
      {
        v31 = c2min;
        if ( c2min <= c2max )
          break;
LABEL_45:
        ++v29;
        ++v30;
        if ( v29 > c0max )
          goto LABEL_46;
      }
      v32 = (_WORD *)(*v30 + v28 - 2);
      while ( *++v32 == 0 )
      {
        if ( ++v31 > c2max )
          goto LABEL_45;
      }
      c1max = v27;
      boxp->c1max = v27;
    }
  }
have_c1max:
  if ( c2min < c2max )
  {
    v33 = c2min;
    while ( 1 )
    {
      v34 = c0min;
      if ( c0min <= c0max )
        break;
LABEL_57:
      if ( ++v33 > c2max )
        goto have_c2min;
    }
    v35 = (_DWORD *)((char *)start_pass + 4 * c0min);
    while ( 1 )
    {
      v36 = c1min;
      v37 = (_WORD *)(*v35 + 2 * (32 * c1min + v33));
      if ( c1min <= c1max )
        break;
LABEL_56:
      ++v34;
      ++v35;
      if ( v34 > c0max )
        goto LABEL_57;
    }
    while ( *v37 == 0 )
    {
      ++v36;
      v37 += 32;
      if ( v36 > c1max )
        goto LABEL_56;
    }
    c2min = v33;
    boxp->c2min = v33;
have_c2min:
    if ( c2max > c2min )
    {
      v38 = c2max;
      while ( 1 )
      {
        v39 = c0min;
        if ( c0min <= c0max )
          break;
LABEL_68:
        if ( --v38 < c2min )
          goto have_c2max;
      }
      v40 = (_DWORD *)((char *)start_pass + 4 * c0min);
      while ( 1 )
      {
        v41 = c1min;
        v42 = (_WORD *)(*v40 + 2 * (32 * c1min + v38));
        if ( c1min <= c1max )
          break;
LABEL_67:
        ++v39;
        ++v40;
        if ( v39 > c0max )
          goto LABEL_68;
      }
      while ( *v42 == 0 )
      {
        ++v41;
        v42 += 32;
        if ( v41 > c1max )
          goto LABEL_67;
      }
      c2max = v38;
      boxp->c2max = v38;
    }
  }
have_c2max:
  v43 = 0;
  boxp->volume = 8 * (c2max - c2min) * 8 * (c2max - c2min)
               + 12 * (c1max - c1min) * 12 * (c1max - c1min)
               + 16 * (c0max - c0min) * 16 * (c0max - c0min);
  if ( c0min <= c0max )
  {
    v45 = (_DWORD *)((char *)start_pass + 4 * c0min);
    v44 = c0max - c0min + 1;
    do
    {
      if ( c1min <= c1max )
      {
        v46 = c1max - c1min + 1;
        v47 = 2 * (32 * c1min + c2min) + *v45;
        do
        {
          v48 = (_WORD *)v47;
          if ( c2min <= c2max )
          {
            v49 = c2max - c2min + 1;
            do
            {
              if ( *v48 != 0 )
                ++v43;
              ++v48;
              --v49;
            }
            while ( v49 != 0 );
          }
          --v46;
          v47 += 64;
        }
        while ( v46 != 0 );
      }
      --v44;
      ++v45;
    }
    while ( v44 != 0 );
  }
  boxp->colorcount = v43;
}


// ========================================================================
// median_cut
// EA  : 0x83239850
// RVA : 0x01239850
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

int __fastcall median_cut(jpeg_decompress_struct *cinfo, box *boxlist, int numboxes, int desired_colors)
{
  int v6; // r27
  int v8; // r26
  int *p_c1max; // r31
  int v10; // r9
  box *v11; // r4
  int *p_colorcount; // r11
  int j; // ctr
  int *p_volume; // r11
  int i; // ctr
  int v16; // r30
  int c0max; // r9
  int c2max; // r5
  int c2min; // r3
  int c1max; // r7
  int c1min; // r6
  int v22; // r11
  int v23; // r11
  int v24; // r11
  int v25; // r11

  v6 = numboxes;
  if ( numboxes < desired_colors )
  {
    v8 = 2 * numboxes;
    p_c1max = &boxlist[numboxes].c1max;
    do
    {
      v10 = 0;
      v11 = nullptr;
      if ( v8 > desired_colors )
      {
        if ( v6 > 0 )
        {
          p_volume = &boxlist->volume;
          for ( i = v6; i != 0; --i )
          {
            if ( *p_volume > v10 )
            {
              v11 = (box *)(p_volume - 6);
              v10 = *p_volume;
            }
            p_volume += 8;
          }
        }
      }
      else if ( v6 > 0 )
      {
        p_colorcount = &boxlist->colorcount;
        for ( j = v6; j != 0; --j )
        {
          if ( *p_colorcount > v10 && *(p_colorcount - 1) > 0 )
          {
            v11 = (box *)(p_colorcount - 7);
            v10 = *p_colorcount;
          }
          p_colorcount += 8;
        }
      }
      if ( v11 == nullptr )
        break;
      v16 = 1;
      *(p_c1max - 2) = v11->c0max;
      *p_c1max = v11->c1max;
      p_c1max[2] = v11->c2max;
      *(p_c1max - 3) = v11->c0min;
      *(p_c1max - 1) = v11->c1min;
      p_c1max[1] = v11->c2min;
      c0max = v11->c0max;
      c2max = v11->c2max;
      c2min = v11->c2min;
      c1max = v11->c1max;
      c1min = v11->c1min;
      v22 = 12 * (c1max - c1min);
      if ( 16 * (c0max - v11->c0min) > v22 )
      {
        v22 = 16 * (c0max - v11->c0min);
        v16 = 0;
      }
      if ( 8 * (c2max - c2min) > v22 )
        v16 = 2;
      if ( v16 != 0 )
      {
        if ( v16 == 1 )
        {
          v24 = (c1min + c1max) / 2;
          v11->c1max = v24;
          *(p_c1max - 1) = v24 + 1;
        }
        else
        {
          v23 = (c2min + c2max) / 2;
          v11->c2max = v23;
          p_c1max[1] = v23 + 1;
        }
      }
      else
      {
        v25 = (v11->c0min + c0max) / 2;
        v11->c0max = v25;
        *(p_c1max - 3) = v25 + 1;
      }
      update_box(cinfo, boxp: v11);
      update_box(cinfo, boxp: (box *)(p_c1max - 3));
      ++v6;
      v8 += 2;
      p_c1max += 8;
    }
    while ( v6 < desired_colors );
  }
  return v6;
}


// ========================================================================
// compute_color
// EA  : 0x83239A28
// RVA : 0x01239A28
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall compute_color(jpeg_decompress_struct *cinfo, box *boxp, int icolor)
{
  int c0max; // r10
  signed int v4; // r7
  int v5; // r4
  int v6; // r31
  int v7; // r30
  int c0min; // r11
  int c1min; // r24
  int c1max; // r20
  int c2min; // r26
  int c2max; // r22
  bool v13; // zf
  int v14; // r28
  _DWORD *v15; // r21
  int v16; // r19
  int v17; // r29
  int v18; // r25
  int v19; // r23
  int v20; // r6
  _WORD *v21; // r27
  int v22; // ctr
  int v23; // r11
  _DWORD *out_color_components; // r10
  int v25; // r9
  int v26; // r8
  int v27; // r6
  int v28; // r4

  c0max = boxp->c0max;
  v4 = 0;
  v6 = 0;
  v7 = 0;
  c0min = boxp->c0min;
  c1min = boxp->c1min;
  c1max = boxp->c1max;
  c2min = boxp->c2min;
  c2max = boxp->c2max;
  v13 = boxp->c0min > c0max;
  v5 = 0;
  if ( !v13 )
  {
    v14 = 8 * c0min + 4;
    v15 = (_DWORD *)((char *)cinfo->entropy[2].start_pass + 4 * c0min);
    v16 = c0max - c0min + 1;
    do
    {
      if ( c1min <= c1max )
      {
        v17 = 4 * c1min + 2;
        v18 = 2 * (32 * c1min + c2min) + *v15;
        v19 = c1max - c1min + 1;
        do
        {
          if ( c2min <= c2max )
          {
            v20 = 8 * c2min + 4;
            v21 = (_WORD *)(v18 - 2);
            v22 = c2max - c2min + 1;
            do
            {
              v23 = (unsigned __int16)*++v21;
              if ( *v21 != 0 )
              {
                v4 += v23;
                v5 += v14 * v23;
                v6 += v17 * v23;
                v7 += v20 * v23;
              }
              v20 += 8;
              --v22;
            }
            while ( v22 != 0 );
          }
          --v19;
          v18 += 64;
          v17 += 4;
        }
        while ( v19 != 0 );
      }
      --v16;
      ++v15;
      v14 += 8;
    }
    while ( v16 != 0 );
  }
  out_color_components = (_DWORD *)cinfo->out_color_components;
  __twllei(v4, 0);
  v25 = (v4 >> 1) + v5;
  v26 = (v4 >> 1) + v6;
  v27 = (v4 >> 1) + v7;
  *(_BYTE *)(*out_color_components + icolor) = v25 / v4;
  *(_BYTE *)(*(_DWORD *)(cinfo->out_color_components + 4) + icolor) = v26 / v4;
  v28 = *(_DWORD *)(cinfo->out_color_components + 8);
  __twllei(v4, 0);
  *(_BYTE *)(v28 + icolor) = v27 / v4;
  __twllei(v4, 0);
  __twlgei(v4 & ~(__ROL4__(v25, 1) - 1), 0xFFFFFFFF);
  __twlgei(v4 & ~(__ROL4__(v26, 1) - 1), 0xFFFFFFFF);
  __twlgei(v4 & ~(__ROL4__(v27, 1) - 1), 0xFFFFFFFF);
}


// ========================================================================
// select_colors
// EA  : 0x83239BA0
// RVA : 0x01239BA0
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall select_colors(jpeg_decompress_struct *cinfo, int desired_colors)
{
  box *v4; // r31
  box *v5; // r4
  signed int v6; // r29
  int i; // r5
  int v8; // r5
  jpeg_error_mgr *err; // r11

  v4 = (box *)((int (*)(void))cinfo->mem->alloc_small)();
  v4->c0min = 0;
  v4->c1min = 0;
  v4->c2min = 0;
  v4->c0max = 31;
  v4->c1max = 63;
  v4->c2max = 31;
  update_box(cinfo, boxp: v4);
  v6 = median_cut(cinfo, boxlist: v5, numboxes: 1, desired_colors);
  for ( i = 0; i < v6; ++v4 )
  {
    compute_color(cinfo, boxp: v4, icolor: i);
    i = v8 + 1;
  }
  err = cinfo->err;
  cinfo->output_height = v6;
  err->msg_code = 96;
  cinfo->err->msg_parm.i[0] = v6;
  ((void (__fastcall *)(jpeg_decompress_struct *, int, int))cinfo->err->emit_message)(a1: cinfo, a2: 1, a3: i);
}


// ========================================================================
// find_nearby_colors
// EA  : 0x83239C78
// RVA : 0x01239C78
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

int __fastcall find_nearby_colors(
        jpeg_decompress_struct *cinfo,
        int minc0,
        int minc1,
        int minc2,
        unsigned __int8 *colorlist)
{
  int v5; // r28
  signed int output_height; // r26
  int v7; // r30
  int v8; // r29
  int v9; // r22
  int v10; // r27
  _DWORD *out_color_components; // r25
  int *v12; // r24
  unsigned int v13; // ctr
  int v14; // r21
  int v15; // r11
  int v16; // r10
  int v17; // r9
  int v18; // r11
  int v19; // r11
  int v20; // r8
  int v21; // r11
  int v22; // r8
  int v23; // r11
  int v24; // r11
  int v25; // r9
  int v26; // r8
  int v27; // r9
  int v28; // r8
  int v29; // r9
  int v30; // r11
  int result; // r3
  unsigned __int8 v32; // r11
  int *v33; // r10
  signed int i; // ctr
  _BYTE v35[1136]; // [sp+10h] [-470h] BYREF

  v5 = minc0 + 24;
  output_height = cinfo->output_height;
  v7 = minc1 + 28;
  v8 = minc2 + 24;
  v9 = 0x7FFFFFFF;
  v10 = 0;
  if ( output_height > 0 )
  {
    out_color_components = (_DWORD *)cinfo->out_color_components;
    v12 = (int *)v35;
    v13 = cinfo->output_height;
    v14 = out_color_components[2];
    do
    {
      v15 = *(unsigned __int8 *)(*out_color_components + v10);
      if ( v15 >= minc0 )
      {
        if ( v15 <= v5 )
        {
          v16 = 0;
          if ( v15 > (minc0 + 24 + minc0) >> 1 )
            v18 = v15 - minc0;
          else
            v18 = v15 - v5;
          v17 = 2 * v18 * 2 * v18;
        }
        else
        {
          v16 = 2 * (v15 - v5) * 2 * (v15 - v5);
          v17 = 2 * (v15 - minc0) * 2 * (v15 - minc0);
        }
      }
      else
      {
        v16 = 2 * (v15 - minc0) * 2 * (v15 - minc0);
        v17 = 2 * (v15 - v5) * 2 * (v15 - v5);
      }
      v19 = *(unsigned __int8 *)(out_color_components[1] + v10);
      if ( v19 >= minc1 )
      {
        if ( v19 <= v7 )
        {
          if ( v19 > (minc1 + 28 + minc1) >> 1 )
            v23 = v19 - minc1;
          else
            v23 = v19 - v7;
          v21 = 3 * v23;
        }
        else
        {
          v22 = 3 * (v19 - v7) * 3 * (v19 - v7);
          v21 = 3 * (v19 - minc1);
          v16 += v22;
        }
      }
      else
      {
        v20 = 3 * (v19 - minc1) * 3 * (v19 - minc1);
        v21 = 3 * (v19 - v7);
        v16 += v20;
      }
      v24 = v21 * v21 + v17;
      v25 = *(unsigned __int8 *)(v14 + v10);
      if ( v25 >= minc2 )
      {
        if ( v25 <= v8 )
        {
          if ( v25 > (minc2 + 24 + minc2) >> 1 )
            v29 = v25 - minc2;
          else
            v29 = v25 - v8;
          v27 = v29 * v29;
        }
        else
        {
          v28 = (v25 - v8) * (v25 - v8);
          v27 = (v25 - minc2) * (v25 - minc2);
          v16 += v28;
        }
      }
      else
      {
        v26 = (v25 - minc2) * (v25 - minc2);
        v27 = (v25 - v8) * (v25 - v8);
        v16 += v26;
      }
      v30 = v27 + v24;
      *v12 = v16;
      if ( v30 < v9 )
        v9 = v30;
      ++v10;
      ++v12;
      --v13;
    }
    while ( v13 != 0 );
  }
  result = 0;
  v32 = 0;
  if ( output_height > 0 )
  {
    v33 = (int *)v35;
    for ( i = output_height; i != 0; --i )
    {
      if ( *v33 <= v9 )
        colorlist[result++] = v32;
      ++v32;
      ++v33;
    }
  }
  return result;
}


// ========================================================================
// find_best_colors
// EA  : 0x83239E80
// RVA : 0x01239E80
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall find_best_colors(
        jpeg_decompress_struct *cinfo,
        int minc0,
        int minc1,
        int minc2,
        int numcolors,
        unsigned __int8 *colorlist,
        unsigned __int8 *bestcolor)
{
  char *v7; // r10
  int i; // ctr
  int j; // r19
  _DWORD *out_color_components; // r10
  int *v11; // r11
  int v12; // r25
  unsigned __int8 *v13; // r28
  int v14; // r22
  int v15; // r31
  int v16; // r26
  int v17; // r10
  int v18; // r27
  int v19; // r23
  int v20; // r20
  int v21; // r21
  int v22; // r26
  int v23; // r24
  int v24; // r31
  int v25; // r29
  int k; // ctr
  int v27; // r10
  int v28; // r10
  int v29; // r10
  int *v30; // r11
  int v31; // r30
  int v32; // r31
  int v33; // r31
  int v34; // r31
  int *v35; // r11
  int v36; // r30
  int v37; // r31
  int v38; // r31
  int v39; // r31
  int *v40; // r11
  int v41; // r30
  int v42; // r31
  int v43; // r31
  int v44; // r31
  char v45; // [sp+Ch] [-284h] BYREF
  char v46; // [sp+10h] [-280h] BYREF

  v7 = &v45;
  for ( i = 128; i != 0; --i )
  {
    v7 += 4;
    *(_DWORD *)v7 = 0x7FFFFFFF;
  }
  for ( j = 0; j < numcolors; ++j )
  {
    out_color_components = (_DWORD *)cinfo->out_color_components;
    v11 = (int *)&v46;
    v12 = colorlist[j];
    v13 = bestcolor;
    v14 = 3;
    v15 = minc2 - *(unsigned __int8 *)(out_color_components[2] + v12);
    v16 = minc0 - *(unsigned __int8 *)(v12 + *out_color_components);
    v17 = 3 * (minc1 - *(unsigned __int8 *)(out_color_components[1] + v12));
    v18 = 16 * (v15 + 4);
    v19 = v15 * v15 + v17 * v17 + 2 * v16 * 2 * v16;
    v20 = 24 * (v17 + 6);
    v21 = 32 * (2 * v16 + 8);
    v22 = v18 + 128;
    v23 = v18 + 256;
    do
    {
      v24 = v19;
      v25 = v20;
      for ( k = 2; k != 0; --k )
      {
        if ( v24 < *v11 )
        {
          *v11 = v24;
          *v13 = v12;
        }
        v27 = v24 + v18;
        if ( v24 + v18 < v11[1] )
        {
          v11[1] = v27;
          v13[1] = v12;
        }
        v28 = v22 + v27;
        if ( v28 < v11[2] )
        {
          v11[2] = v28;
          v13[2] = v12;
        }
        v29 = v23 + v28;
        if ( v29 < v11[3] )
        {
          v11[3] = v29;
          v13[3] = v12;
        }
        v30 = v11 + 4;
        v31 = v25 + v24;
        if ( v25 + v24 < *v30 )
        {
          *v30 = v31;
          v13[4] = v12;
        }
        v32 = v31 + v18;
        if ( v31 + v18 < v30[1] )
        {
          v30[1] = v32;
          v13[5] = v12;
        }
        v33 = v22 + v32;
        if ( v33 < v30[2] )
        {
          v30[2] = v33;
          v13[6] = v12;
        }
        v34 = v23 + v33;
        if ( v34 < v30[3] )
        {
          v30[3] = v34;
          v13[7] = v12;
        }
        v35 = v30 + 4;
        v36 = v25 + v31 + 288;
        if ( v36 < *v35 )
        {
          *v35 = v36;
          v13[8] = v12;
        }
        v37 = v36 + v18;
        if ( v36 + v18 < v35[1] )
        {
          v35[1] = v37;
          v13[9] = v12;
        }
        v38 = v22 + v37;
        if ( v38 < v35[2] )
        {
          v35[2] = v38;
          v13[10] = v12;
        }
        v39 = v23 + v38;
        if ( v39 < v35[3] )
        {
          v35[3] = v39;
          v13[11] = v12;
        }
        v40 = v35 + 4;
        v41 = v25 + v36 + 576;
        if ( v41 < *v40 )
        {
          *v40 = v41;
          v13[12] = v12;
        }
        v42 = v41 + v18;
        if ( v41 + v18 < v40[1] )
        {
          v40[1] = v42;
          v13[13] = v12;
        }
        v43 = v22 + v42;
        if ( v43 < v40[2] )
        {
          v40[2] = v43;
          v13[14] = v12;
        }
        v44 = v23 + v43;
        if ( v44 < v40[3] )
        {
          v40[3] = v44;
          v13[15] = v12;
        }
        v11 = v40 + 4;
        v13 += 16;
        v24 = v25 + v41 + 864;
        v25 += 1152;
      }
      v19 += v21;
      --v14;
      v21 += 512;
    }
    while ( v14 >= 0 );
  }
}


// ========================================================================
// fill_inverse_cmap
// EA  : 0x8323A110
// RVA : 0x0123A110
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall fill_inverse_cmap(jpeg_decompress_struct *cinfo, int c0, int c1, int c2)
{
  int v4; // r31
  int v5; // r30
  int v6; // r29
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r26
  int nearby_colors; // r3
  int v10; // r6
  int v11; // r5
  int v12; // r4
  int v13; // r5
  _DWORD *v14; // r8
  unsigned __int8 *v15; // r11
  int v16; // r28
  int v17; // r27
  int v18; // r25
  int i; // r26
  int v20; // r7
  int v21; // r10
  int j; // ctr
  _WORD *v23; // r9
  __int16 v24; // r29
  __int16 v25; // r31
  __int16 v26; // r30
  __int16 v27; // r4
  __int16 v28; // r22
  __int16 v29; // r21
  __int16 v30; // r20
  unsigned __int8 *v31; // r11
  __int16 v32; // r21
  __int16 v33; // r19
  __int16 v34; // r31
  __int16 v35; // r22
  __int16 v36; // r6
  __int16 v37; // r20
  __int16 v38; // r29
  __int16 v39; // r18
  int v40; // r30
  __int16 v41; // r17
  _WORD *v42; // r9
  int v43; // r4
  __int16 v44; // r24
  _WORD *v45; // r9
  _WORD *v46; // r9
  __int16 v47; // r31
  unsigned __int8 v48[128]; // [sp+50h] [-200h] BYREF
  unsigned __int8 v49[384]; // [sp+D0h] [-180h] BYREF

  v4 = c0 >> 2;
  v5 = c1 >> 3;
  v6 = c2 >> 2;
  start_pass = cinfo->entropy[2].start_pass;
  nearby_colors = find_nearby_colors(
                    cinfo,
                    minc0: 32 * (c0 >> 2) + 4,
                    minc1: 32 * (c1 >> 3) + 2,
                    minc2: 32 * (c2 >> 2) + 4,
                    colorlist: v49);
  find_best_colors(cinfo, minc0: v12, minc1: v11, minc2: v10, numcolors: nearby_colors, colorlist: v49, bestcolor: v48);
  v13 = 4 * v6;
  v14 = (_DWORD *)((char *)start_pass + 16 * v4);
  v15 = v48;
  v16 = 8 * v5 + 2;
  v17 = 8 * v5 + 3;
  v18 = 2 * ((v5 << 8) + 4 * v6);
  for ( i = 4; i != 0; --i )
  {
    v20 = 0;
    v21 = v18;
    for ( j = 2; j != 0; --j )
    {
      v23 = (_WORD *)(v21 + *v14);
      v24 = v15[3];
      v25 = v15[1] + 1;
      v26 = v15[2] + 1;
      v27 = v15[4];
      *v23 = *v15 + 1;
      v23[1] = v25;
      v23[2] = v26;
      v23[3] = v24 + 1;
      v28 = v15[5];
      v29 = v15[6];
      v30 = v15[7];
      v31 = v15 + 8;
      v33 = v29 + 1;
      v32 = *v31 + 1;
      v34 = v31[3];
      v36 = v31[4];
      v38 = v28 + 1;
      v35 = v31[2];
      v39 = v30 + 1;
      v37 = v27 + 1;
      v40 = 2 * (32 * (v16 + v20) + v13);
      v41 = v31[5];
      v42 = (_WORD *)(v21 + *v14);
      v43 = 32 * (v17 + v20);
      v20 += 4;
      v44 = v31[1] + 1;
      v42[32] = v37;
      v42[33] = v38;
      v42[34] = v33;
      v42[35] = v39;
      v45 = (_WORD *)(v40 + *v14);
      *v45 = v32;
      v45[1] = v44;
      v45[2] = v35 + 1;
      v45[3] = v34 + 1;
      v46 = (_WORD *)(2 * (v43 + v13) + *v14);
      v47 = v31[7];
      *v46 = v36 + 1;
      LOWORD(v43) = v31[6] + 1;
      v46[1] = v41 + 1;
      v46[2] = v43;
      v21 += 256;
      v15 = v31 + 8;
      v46[3] = v47 + 1;
    }
    ++v14;
  }
}


// ========================================================================
// pass2_no_dither
// EA  : 0x8323A310
// RVA : 0x0123A310
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall pass2_no_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  J_DITHER_MODE dither_mode; // r10
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r3
  int v7; // r9
  unsigned __int8 **v8; // r31
  int v9; // r8
  unsigned __int8 *v10; // r23
  J_DITHER_MODE v11; // r6
  unsigned __int8 *v12; // r11
  unsigned __int8 *v13; // r5
  unsigned int v14; // r11
  unsigned int v15; // r9
  int v16; // r7
  int v17; // r10
  int v18; // r8
  int v19; // r9
  unsigned __int8 *v20; // r23
  int v21; // r11
  int v22; // r4
  int v23; // r8
  int v24; // r7
  int v25; // r31
  int v26; // r30
  int v27; // r29
  void (__fastcall *v28)(jpeg_decompress_struct *); // r26
  int nearby_colors; // r3
  int v30; // r6
  int v31; // r5
  int v32; // r4
  int v33; // r5
  _DWORD *v34; // r8
  unsigned __int8 *v35; // r11
  int v36; // r28
  int v37; // r27
  int v38; // r24
  int i; // r26
  int v40; // r7
  int v41; // r10
  int j; // ctr
  _WORD *v43; // r9
  __int16 v44; // r29
  __int16 v45; // r31
  __int16 v46; // r30
  __int16 v47; // r4
  __int16 v48; // r30
  __int16 v49; // r20
  __int16 v50; // r19
  unsigned __int8 *v51; // r11
  __int16 v52; // r4
  __int16 v53; // r19
  __int16 v54; // r18
  __int16 v55; // r30
  __int16 v56; // r6
  __int16 v57; // r17
  __int16 v58; // r16
  int v59; // r4
  __int16 v60; // r15
  int v61; // r3
  _WORD *v62; // r9
  __int16 v63; // r22
  __int16 v64; // r31
  _WORD *v65; // r9
  __int16 v66; // r31
  _WORD *v67; // r9
  __int16 v68; // r6
  unsigned __int8 *v69; // [sp+50h] [-240h]
  int v70; // [sp+54h] [-23Ch]
  J_DITHER_MODE v71; // [sp+58h] [-238h]
  unsigned __int8 **v72; // [sp+5Ch] [-234h]
  int v73; // [sp+60h] [-230h]
  int v74; // [sp+64h] [-22Ch]
  J_DITHER_MODE v75; // [sp+68h] [-228h]
  int v76; // [sp+6Ch] [-224h]
  void (__fastcall *v77)(jpeg_decompress_struct *); // [sp+70h] [-220h]
  unsigned __int8 v78[128]; // [sp+80h] [-210h] BYREF
  unsigned __int8 v79[400]; // [sp+100h] [-190h] BYREF

  dither_mode = cinfo->dither_mode;
  start_pass = cinfo->entropy[2].start_pass;
  v77 = start_pass;
  v75 = dither_mode;
  if ( num_rows > 0 )
  {
    v7 = (char *)input_buf - (char *)output_buf;
    v72 = output_buf;
    v8 = output_buf;
    v70 = num_rows;
    v9 = num_rows;
    v74 = (char *)input_buf - (char *)output_buf;
    do
    {
      v10 = *(unsigned __int8 **)((char *)v8 + v7);
      v11 = dither_mode;
      v12 = *v8;
      v71 = dither_mode;
      if ( dither_mode != JDITHER_NONE )
      {
        v13 = v12 - 1;
        v69 = v12 - 1;
        do
        {
          v14 = *v10;
          v15 = v10[1];
          v16 = (v14 >> 1) & 0x7C;
          v17 = v14 >> 3;
          v18 = (8 * v15) & 0x7E0;
          v19 = v15 >> 2;
          v20 = v10 + 2;
          v21 = *v20 >> 3;
          v10 = v20 + 1;
          v22 = v18 + v21;
          v73 = 2 * (v18 + v21);
          v23 = *(_DWORD *)((char *)start_pass + v16);
          v76 = v23;
          v24 = 2 * v22;
          if ( *(_WORD *)(2 * v22 + v23) == 0 )
          {
            v25 = v17 >> 2;
            v26 = v19 >> 3;
            v27 = v21 >> 2;
            v28 = cinfo->entropy[2].start_pass;
            nearby_colors = find_nearby_colors(
                              cinfo,
                              minc0: 32 * (v17 >> 2) + 4,
                              minc1: 32 * (v19 >> 3) + 2,
                              minc2: 32 * (v21 >> 2) + 4,
                              colorlist: v79);
            find_best_colors(
              cinfo,
              minc0: v32,
              minc1: v31,
              minc2: v30,
              numcolors: nearby_colors,
              colorlist: v79,
              bestcolor: v78);
            v33 = 4 * v27;
            v34 = (_DWORD *)((char *)v28 + 16 * v25);
            v35 = v78;
            v36 = 8 * v26 + 2;
            v37 = 8 * v26 + 3;
            v38 = 2 * ((v26 << 8) + 4 * v27);
            for ( i = 4; i != 0; --i )
            {
              v40 = 0;
              v41 = v38;
              for ( j = 2; j != 0; --j )
              {
                v43 = (_WORD *)(v41 + *v34);
                v44 = v35[3];
                v45 = v35[1] + 1;
                v46 = v35[2] + 1;
                v47 = v35[4];
                *v43 = *v35 + 1;
                v43[1] = v45;
                v43[2] = v46;
                v48 = v47 + 1;
                v43[3] = v44 + 1;
                v49 = v35[5];
                v50 = v35[6];
                v52 = v35[7];
                v51 = v35 + 8;
                v54 = v48;
                v55 = v51[3];
                v56 = v51[4];
                v57 = v50 + 1;
                v53 = *v51 + 1;
                v58 = v52 + 1;
                v59 = 2 * (32 * (v36 + v40) + v33);
                v60 = v51[5];
                v61 = 32 * (v37 + v40);
                v40 += 4;
                v62 = (_WORD *)(v41 + *v34);
                v63 = v51[1] + 1;
                v64 = v51[2] + 1;
                v62[32] = v54;
                v62[33] = v49 + 1;
                v62[34] = v57;
                v62[35] = v58;
                v65 = (_WORD *)(v59 + *v34);
                *v65 = v53;
                v65[1] = v63;
                v65[2] = v64;
                v66 = v56 + 1;
                v65[3] = v55 + 1;
                v67 = (_WORD *)(2 * (v61 + v33) + *v34);
                LOWORD(v59) = v51[6];
                v68 = v51[7];
                *v67 = v66;
                v67[1] = v60 + 1;
                v41 += 256;
                v67[2] = v59 + 1;
                v35 = v51 + 8;
                v67[3] = v68 + 1;
              }
              ++v34;
            }
            v13 = v69;
            start_pass = v77;
            v8 = v72;
            v11 = v71;
            v24 = v73;
            v23 = v76;
          }
          v71 = --v11;
          *++v13 = *(_WORD *)(v24 + v23) - 1;
          v69 = v13;
        }
        while ( v11 != JDITHER_NONE );
        v7 = v74;
        v9 = v70;
        dither_mode = v75;
      }
      --v9;
      ++v8;
      v70 = v9;
      v72 = v8;
    }
    while ( v9 != 0 );
  }
}


// ========================================================================
// pass2_fs_dither
// EA  : 0x8323A608
// RVA : 0x0123A608
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall pass2_fs_dither(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned __int8 **output_buf,
        int num_rows)
{
  jpeg_entropy_decoder *entropy; // r10
  int *out_color_components; // r11
  J_DITHER_MODE dither_mode; // r23
  int max_h_samp_factor; // r15
  unsigned __int8 (__fastcall *decode_mcu)(jpeg_decompress_struct *, __int16 (**)[64]); // r14
  int v9; // r4
  unsigned __int8 *v10; // r30
  int v11; // r6
  int v12; // r7
  int v13; // r3
  _WORD *v14; // r31
  int v15; // r11
  int v16; // r9
  int v17; // r8
  __int16 v18; // r16
  __int16 v19; // r17
  __int16 v20; // r18
  __int16 v21; // r20
  __int16 v22; // r21
  __int16 v23; // r22
  int v24; // r29
  int v25; // r10
  _BYTE *v26; // r19
  int v27; // r28
  int v28; // r27
  int v29; // r26
  int v30; // r25
  int v31; // r24
  int v32; // r11
  int v33; // r5
  int v34; // r4
  int v35; // r11
  int v36; // r8
  __int16 v37; // r6
  __int16 v38; // r10
  int v39; // r11
  int v40; // r7
  int v41; // r9
  __int16 v42; // r28
  __int16 v43; // r10
  int v44; // r11
  int v45; // r6
  int v46; // r10
  int v47; // r11
  __int16 v48; // r28
  bool v49; // cr34
  int v50; // [sp+50h] [-D0h]
  int v51; // [sp+54h] [-CCh]
  unsigned __int8 **v52; // [sp+58h] [-C8h]
  int v53; // [sp+5Ch] [-C4h]
  int i; // [sp+60h] [-C0h]
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // [sp+64h] [-BCh]
  int v56; // [sp+68h] [-B8h]
  int v57; // [sp+6Ch] [-B4h]
  int v58; // [sp+70h] [-B0h]
  int v59; // [sp+74h] [-ACh]
  J_DITHER_MODE v60; // [sp+78h] [-A8h]
  jpeg_entropy_decoder *v61; // [sp+7Ch] [-A4h]

  entropy = cinfo->entropy;
  out_color_components = (int *)cinfo->out_color_components;
  dither_mode = cinfo->dither_mode;
  max_h_samp_factor = cinfo->max_h_samp_factor;
  decode_mcu = entropy[3].decode_mcu;
  v61 = entropy;
  v60 = dither_mode;
  v58 = *out_color_components;
  start_pass = entropy[2].start_pass;
  v56 = out_color_components[1];
  v57 = out_color_components[2];
  if ( num_rows > 0 )
  {
    v9 = (char *)input_buf - (char *)output_buf;
    v53 = num_rows;
    v52 = output_buf;
    v59 = v9;
    while ( 1 )
    {
      v10 = *(unsigned __int8 **)((char *)output_buf + v9);
      v11 = (int)*output_buf;
      if ( HIBYTE(entropy[3].start_pass) != 0 )
      {
        v12 = *(_DWORD *)&entropy[2].insufficient_data;
        HIBYTE(entropy[3].start_pass) = 0;
        v13 = -3;
        v51 = -1;
        v10 = &v10[3 * dither_mode - 3];
        v11 = v11 + dither_mode - 1;
        v50 = -3;
        v14 = (_WORD *)(6 * (dither_mode + 1) + v12);
      }
      else
      {
        v14 = *(_WORD **)&entropy[2].insufficient_data;
        v50 = 3;
        v13 = 3;
        v51 = 1;
        HIBYTE(entropy[3].start_pass) = 1;
      }
      v15 = 0;
      v16 = 0;
      v17 = 0;
      v18 = 0;
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v23 = 0;
      if ( dither_mode != JDITHER_NONE )
      {
        v24 = v13;
        v25 = 2 * (v13 + 2);
        v26 = (_BYTE *)(v11 - v51);
        for ( i = v25; ; v25 = i )
        {
          v27 = *(unsigned __int8 *)(*((_DWORD *)decode_mcu + (((__int16)v14[v24 + 1] + v16 + 8) >> 4))
                                   + v10[1]
                                   + max_h_samp_factor);
          v28 = *(unsigned __int8 *)(*((_DWORD *)decode_mcu + ((*(__int16 *)((char *)v14 + v25) + v15 + 8) >> 4))
                                   + v10[2]
                                   + max_h_samp_factor);
          v29 = *(unsigned __int8 *)(*((_DWORD *)decode_mcu + (((__int16)v14[v24] + v17 + 8) >> 4))
                                   + *v10
                                   + max_h_samp_factor);
          v30 = 2 * (32 * (v27 >> 2) + (v28 >> 3));
          v31 = *((_DWORD *)start_pass + (v29 >> 3));
          if ( *(_WORD *)(v30 + v31) == 0 )
          {
            fill_inverse_cmap(cinfo, c0: v29 >> 3, c1: v27 >> 2, c2: v28 >> 3);
            v13 = v50;
          }
          --dither_mode;
          v10 += v13;
          v32 = *(unsigned __int16 *)(v30 + v31) - 1;
          v26 += v51;
          *v26 = v32;
          v33 = *(unsigned __int8 *)(v32 + v56);
          v34 = *(unsigned __int8 *)(v32 + v57);
          v35 = v29 - *(unsigned __int8 *)(v32 + v58);
          v36 = 2 * v35;
          v37 = v35;
          v38 = 3 * v35;
          v40 = 5 * v35;
          v39 = v27 - v33;
          v41 = 2 * (v27 - v33);
          v42 = v23 + v38;
          v43 = v41 + v39;
          v23 = v20 + v40;
          *v14 = v42;
          LOWORD(v33) = v39;
          v20 = v37;
          v45 = v41 + v41 + v39;
          v44 = v28 - v34;
          LOWORD(v34) = v22 + v43;
          v46 = 2 * v44;
          v22 = v19 + v45;
          v19 = v33;
          LOWORD(v33) = v44;
          v44 *= 3;
          v14[1] = v34;
          v48 = v21 + v44;
          v47 = v46 + v44;
          v21 = v18 + v47;
          v14[2] = v48;
          v17 = v36 + v40;
          v16 = v41 + v45;
          v18 = v33;
          v15 = v46 + v47;
          v14 = (_WORD *)((char *)v14 + v24 * 2);
          if ( dither_mode == JDITHER_NONE )
            break;
        }
        v9 = v59;
        output_buf = v52;
        dither_mode = v60;
        entropy = v61;
      }
      v49 = v53 == 1;
      *v14 = v23;
      v14[1] = v22;
      v14[2] = v21;
      v52 = output_buf + 1;
      --v53;
      if ( v49 )
        break;
      ++output_buf;
    }
  }
}


// ========================================================================
// init_error_limit
// EA  : 0x8323A8F8
// RVA : 0x0123A8F8
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall init_error_limit(jpeg_decompress_struct *cinfo)
{
  jpeg_entropy_decoder *entropy; // r31
  int v2; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r11
  int v6; // r8
  _DWORD *v7; // r7
  int v8; // ctr
  _DWORD *v9; // r6
  _DWORD *v10; // r8
  _DWORD *v11; // r7
  int i; // ctr
  int v13; // r8
  int v14; // r7
  _DWORD *v15; // r10
  _DWORD *v16; // r9
  int v17; // ctr

  entropy = cinfo->entropy;
  v2 = ((int (*)(void))cinfo->mem->alloc_small)();
  v3 = 16;
  v4 = v2 + 1020;
  v5 = 0;
  entropy[3].decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))(v2 + 1020);
  v6 = 0;
  v7 = (_DWORD *)(v2 + 1016);
  v8 = 16;
  v9 = (_DWORD *)(v2 + 1024);
  do
  {
    *++v7 = v5++;
    *--v9 = v6--;
    --v8;
  }
  while ( v8 != 0 );
  v10 = (_DWORD *)(v2 + 1080);
  v11 = (_DWORD *)(v2 + 960);
  for ( i = 32; i != 0; --i )
  {
    ++v3;
    *++v10 = v5;
    *--v11 = -v5;
    v5 += (v3 & 1) == 0;
  }
  if ( v3 <= 255 )
  {
    v13 = 4 * v3;
    v14 = 256 - v3;
    v15 = (_DWORD *)(4 * v3 + v4 - 4);
    v16 = (_DWORD *)(v4 - v13 + 4);
    v17 = v14;
    do
    {
      *++v15 = v5;
      *--v16 = -v5;
      --v17;
    }
    while ( v17 != 0 );
  }
}


// ========================================================================
// finish_pass1
// EA  : 0x8323A9D0
// RVA : 0x0123A9D0
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall finish_pass1(jpeg_decompress_struct *cinfo)
{
  jpeg_entropy_decoder *entropy; // r31

  entropy = cinfo->entropy;
  cinfo->out_color_components = (int)entropy[1].decode_mcu;
  select_colors(cinfo, desired_colors: *(_DWORD *)&entropy[1].insufficient_data);
  HIBYTE(entropy[2].decode_mcu) = 1;
}


// ========================================================================
// start_pass_2_quant
// EA  : 0x8323AA10
// RVA : 0x0123AA10
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall start_pass_2_quant(jpeg_common_struct *cinfo, unsigned __int8 is_pre_scan)
{
  jpeg_entropy_decoder *v2; // r30
  void (__fastcall *start_pass)(jpeg_decompress_struct *); // r28
  void (__fastcall *v5)(jpeg_decompress_struct *, unsigned __int8 **, unsigned __int8 **, int); // r10
  signed int v6; // r29
  unsigned int v7; // r29
  void **v8; // r29
  int i; // r31

  v2 = *(jpeg_entropy_decoder **)&cinfo[17].is_decompressor;
  start_pass = v2[2].start_pass;
  if ( cinfo[3].mem != nullptr )
    cinfo[3].mem = (jpeg_memory_mgr *)2;
  if ( is_pre_scan != 0 )
  {
    v2->decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))prescan_quantize;
    *(_DWORD *)&v2->insufficient_data = finish_pass1;
    HIBYTE(v2[2].decode_mcu) = 1;
  }
  else
  {
    if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
      v5 = pass2_fs_dither;
    else
      v5 = pass2_no_dither;
    v2->decode_mcu = (unsigned __int8 (__fastcall *)(jpeg_decompress_struct *, __int16 (**)[64]))v5;
    *(_DWORD *)&v2->insufficient_data = idPhysics_StaticMulti::UpdateTime;
    v6 = *(_DWORD *)&cinfo[4].is_decompressor;
    if ( v6 < 1 )
    {
      cinfo->err->msg_code = 56;
      cinfo->err->msg_parm.i[0] = 1;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( v6 > 256 )
    {
      cinfo->err->msg_code = 57;
      cinfo->err->msg_parm.i[0] = 256;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
    {
      v7 = 6 * (cinfo[3].global_state + 2);
      if ( *(_DWORD *)&v2[2].insufficient_data == 0 )
        *(_DWORD *)&v2[2].insufficient_data = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: v7);
      jzero_far(target: *(void **)&v2[2].insufficient_data, bytestozero: v7);
      if ( v2[3].decode_mcu == nullptr )
        init_error_limit((jpeg_decompress_struct *)cinfo);
      HIBYTE(v2[3].start_pass) = 0;
    }
  }
  if ( HIBYTE(v2[2].decode_mcu) != 0 )
  {
    v8 = (void **)((char *)start_pass - 4);
    for ( i = 32; i != 0; --i )
      jzero_far(target: *++v8, bytestozero: 0x1000u);
    HIBYTE(v2[2].decode_mcu) = 0;
  }
}


// ========================================================================
// new_color_map_2_quant
// EA  : 0x8323ABB0
// RVA : 0x0123ABB0
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall new_color_map_2_quant(jpeg_decompress_struct *cinfo)
{
  HIBYTE(cinfo->entropy[2].decode_mcu) = 1;
}


// ========================================================================
// ?jinit_2pass_quantizer@@YAXPAUjpeg_decompress_struct@@@Z
// EA  : 0x8323ABC0
// RVA : 0x0123ABC0
// PDB : w:\tech5\libs\jpeg\jquant2.cpp
// ========================================================================

void __fastcall jinit_2pass_quantizer(jpeg_common_struct *cinfo)
{
  int v2; // r3
  int v3; // r30
  int i; // r29
  J_DCT_METHOD client_data; // r29

  v2 = ((int (*)(void))cinfo->mem->alloc_small)();
  *(_DWORD *)&cinfo[17].is_decompressor = v2;
  *(_DWORD *)(v2 + 32) = 0;
  *(_DWORD *)v2 = start_pass_2_quant;
  v3 = v2;
  *(_DWORD *)(v2 + 12) = new_color_map_2_quant;
  *(_DWORD *)(v2 + 40) = 0;
  if ( cinfo[4].mem != (jpeg_memory_mgr *)3 )
  {
    cinfo->err->msg_code = 47;
    cinfo->err->error_exit(a1: cinfo);
  }
  *(_DWORD *)(v3 + 24) = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 128);
  for ( i = 0; i < 128; i += 4 )
    *(_DWORD *)(i + *(_DWORD *)(v3 + 24)) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 4096);
  *(_BYTE *)(v3 + 28) = 1;
  if ( *(&cinfo[3].is_decompressor + 2) != 0 )
  {
    client_data = (J_DCT_METHOD)cinfo[3].client_data;
    if ( client_data < 8 )
    {
      cinfo->err->msg_code = 56;
      cinfo->err->msg_parm.i[0] = 8;
      cinfo->err->error_exit(a1: cinfo);
    }
    if ( client_data > 256 )
    {
      cinfo->err->msg_code = 57;
      cinfo->err->msg_parm.i[0] = 256;
      cinfo->err->error_exit(a1: cinfo);
    }
    *(_DWORD *)(v3 + 16) = cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: client_data, a4: 3);
    *(_DWORD *)(v3 + 20) = client_data;
  }
  else
  {
    *(_DWORD *)(v3 + 16) = 0;
  }
  if ( cinfo[3].mem != nullptr )
    cinfo[3].mem = (jpeg_memory_mgr *)2;
  if ( cinfo[3].mem == (jpeg_memory_mgr *)2 )
  {
    *(_DWORD *)(v3 + 32) = cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 6 * (cinfo[3].global_state + 2));
    init_error_limit((jpeg_decompress_struct *)cinfo);
  }
}

