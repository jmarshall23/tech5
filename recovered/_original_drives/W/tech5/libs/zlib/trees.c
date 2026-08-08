
// ========================================================================
// pqdownheap
// EA  : 0x83231508
// RVA : 0x01231508
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall pqdownheap(internal_state *s, ct_data_s *tree, int k)
{
  int heap_len; // r10
  int v4; // r11
  int v5; // r31
  bool v6; // cr56
  int v7; // r8
  int v8; // r7
  unsigned int freq; // r10
  unsigned int v10; // r9
  unsigned int v11; // r9
  z_stream_s *v12; // r10
  unsigned int v13; // r8
  int v14; // r8
  int v15; // r10

  heap_len = s->heap_len;
  v4 = 2 * k;
  v5 = s->heap[k];
  if ( 2 * k <= heap_len )
  {
    v6 = v4 < heap_len;
    do
    {
      if ( v6 )
      {
        v7 = s->heap[v4 + 1];
        v8 = s->heap[v4];
        freq = tree[v7].fc.freq;
        v10 = tree[v8].fc.freq;
        if ( freq < v10 || freq == v10 && s->depth[v7] <= (unsigned int)s->depth[v8] )
          ++v4;
      }
      v11 = tree[v5].fc.freq;
      v12 = (z_stream_s *)s->heap[v4];
      v13 = tree[(_DWORD)v12].fc.freq;
      if ( v11 < v13 || v11 == v13 && s->depth[v5] <= (unsigned int)s->depth[(_DWORD)v12] )
        break;
      v14 = 4 * (k + 727);
      k = v4;
      v4 *= 2;
      *(z_stream_s **)((char *)&s->strm + v14) = v12;
      v15 = s->heap_len;
      v6 = v4 < v15;
    }
    while ( v4 <= v15 );
  }
  s->heap[k] = v5;
}


// ========================================================================
// gen_bitlen
// EA  : 0x832315F8
// RVA : 0x012315F8
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall gen_bitlen(internal_state *s, tree_desc_s *desc)
{
  static_tree_desc_s *stat_desc; // r8
  ct_data_s *dyn_tree; // r26
  int max_code; // r24
  int v5; // r29
  _WORD *v6; // r10
  const ct_data_s *static_tree; // r4
  int v8; // ctr
  const int *extra_bits; // r27
  int extra_base; // r30
  int max_length; // r28
  int v12; // r11
  int v13; // r25
  int *v14; // r31
  int v15; // ctr
  int v16; // r10
  int v17; // r5
  ct_data_s *v18; // r6
  int v19; // r11
  int v20; // r9
  int v21; // r7
  int freq; // r11
  unsigned __int16 *v23; // r7
  int v24; // r11
  _WORD *i; // r10
  int v26; // r10
  int v27; // r11
  __int16 v28; // r4
  int j; // r9
  int v30; // r5
  int *v31; // r6
  ct_data_s *v32; // r11
  int dad; // r10

  stat_desc = desc->stat_desc;
  dyn_tree = desc->dyn_tree;
  max_code = desc->max_code;
  v5 = 0;
  v6 = (_WORD *)&s->bl_desc.stat_desc + 1;
  static_tree = stat_desc->static_tree;
  v8 = 16;
  extra_bits = stat_desc->extra_bits;
  extra_base = stat_desc->extra_base;
  max_length = stat_desc->max_length;
  do
  {
    *++v6 = 0;
    --v8;
  }
  while ( v8 != 0 );
  dyn_tree[s->heap[s->heap_max]].dl.dad = 0;
  v12 = s->heap_max + 1;
  if ( v12 < 573 )
  {
    v13 = 573;
    v14 = &s->heap[s->heap_max + 1];
    v15 = 573 - v12;
    do
    {
      v16 = *v14;
      v17 = *v14;
      v18 = &dyn_tree[v17];
      v19 = *(unsigned __int16 *)((char *)&dyn_tree->dl.dad + __ROL4__(dyn_tree[v17].dl.dad, 2)) + 1;
      if ( v19 > max_length )
      {
        v19 = max_length;
        ++v5;
      }
      v18->dl.dad = v19;
      if ( v16 <= max_code )
      {
        v20 = 0;
        ++s->bl_count[v19];
        if ( v16 >= extra_base )
          v20 = extra_bits[v16 - extra_base];
        v21 = v20 + v19;
        freq = v18->fc.freq;
        s->opt_len += v21 * freq;
        if ( static_tree != nullptr )
          s->static_len += (static_tree[v17].dl.dad + v20) * freq;
      }
      ++v14;
      --v15;
    }
    while ( v15 != 0 );
    if ( v5 != 0 )
    {
      v23 = &s->bl_count[max_length];
      do
      {
        v24 = max_length - 1;
        for ( i = (_WORD *)&s->bl_desc.stat_desc + max_length + 1; *i == 0; --v24 )
          --i;
        v26 = 2 * (v24 + 1438);
        v27 = 2 * (v24 + 1439);
        v5 -= 2;
        v28 = *(_WORD *)((char *)&s->strm + v27) + 2;
        --*(_WORD *)((char *)&s->strm + v26);
        *(_WORD *)((char *)&s->strm + v27) = v28;
        --*v23;
      }
      while ( v5 > 0 );
      for ( j = max_length; j != 0; --v23 )
      {
        v30 = *v23;
        if ( *v23 != 0 )
        {
          v31 = &s->heap[v13];
          do
          {
            --v31;
            --v13;
            if ( *v31 <= max_code )
            {
              v32 = &dyn_tree[*v31];
              dad = v32->dl.dad;
              if ( dad != j )
              {
                s->opt_len += (j - dad) * v32->fc.freq;
                v32->dl.dad = j;
              }
              --v30;
            }
          }
          while ( v30 != 0 );
        }
        --j;
      }
    }
  }
}


// ========================================================================
// scan_tree
// EA  : 0x83231848
// RVA : 0x01231848
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall scan_tree(internal_state *s, ct_data_s *tree, int max_code)
{
  int dad; // r7
  int v4; // r6
  int v5; // r8
  int v6; // r11
  int v7; // r9
  $2467CA9704E0472D4CCF1296A763D23A *p_dl; // r5
  int v9; // ctr
  int v10; // r10

  dad = tree->dl.dad;
  v4 = -1;
  v5 = 0;
  v6 = 7;
  v7 = 4;
  if ( tree->dl.dad == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  tree[max_code + 1].dl.dad = -1;
  if ( max_code >= 0 )
  {
    v9 = max_code + 1;
    p_dl = &tree[1].dl;
    do
    {
      ++v5;
      v10 = dad;
      dad = p_dl->dad;
      if ( v5 >= v6 || v10 != p_dl->dad )
      {
        if ( v5 >= v7 )
        {
          if ( v10 != 0 )
          {
            if ( v10 != v4 )
              ++s->bl_tree[v10].fc.freq;
            ++s->bl_tree[16].fc.freq;
          }
          else if ( v5 > 10 )
          {
            ++s->bl_tree[18].fc.freq;
          }
          else
          {
            ++s->bl_tree[17].fc.freq;
          }
        }
        else
        {
          s->bl_tree[v10].fc.freq += v5;
        }
        v5 = 0;
        v4 = v10;
        if ( dad != 0 )
        {
          if ( v10 == dad )
          {
            v6 = 6;
            v7 = 3;
          }
          else
          {
            v6 = 7;
            v7 = 4;
          }
        }
        else
        {
          v6 = 138;
          v7 = 3;
        }
      }
      p_dl += 2;
      --v9;
    }
    while ( v9 != 0 );
  }
}


// ========================================================================
// send_tree
// EA  : 0x83231978
// RVA : 0x01231978
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall send_tree(internal_state *s, ct_data_s *tree, int max_code)
{
  int dad; // r31
  int v4; // r8
  int v5; // r6
  int v6; // r11
  int v7; // r10
  $2467CA9704E0472D4CCF1296A763D23A *p_dl; // r30
  int i; // ctr
  int v10; // r5
  int v11; // r8
  int v12; // r10
  int bi_valid; // r11
  unsigned __int16 bi_buf; // r28
  int v15; // r9
  unsigned int pending; // r27
  unsigned __int16 v17; // r11
  unsigned __int8 *pending_buf; // r28
  unsigned int v19; // r26
  unsigned __int8 bi_buf_high; // r9
  unsigned __int8 *v21; // r28
  unsigned int v22; // r11
  int v23; // r11
  unsigned __int16 v24; // r8
  int v25; // r11
  int v26; // r10
  int v27; // r9
  unsigned int v28; // r7
  unsigned __int8 *v29; // r28
  unsigned int v30; // r27
  unsigned __int16 v31; // r11
  unsigned int v32; // r11
  unsigned __int8 *v33; // r8
  int v34; // r11
  __int16 v35; // r9
  int v36; // r10
  int v37; // r11
  int freq; // r9
  unsigned int v39; // r11
  unsigned __int8 *v40; // r7
  unsigned int v41; // r28
  unsigned __int16 v42; // r9
  unsigned int v43; // r11
  unsigned __int8 *v44; // r9
  int v45; // r11
  unsigned __int16 v46; // r7
  int v47; // r10
  unsigned __int16 v48; // r9
  unsigned int v49; // r8
  unsigned __int8 *v50; // r6
  unsigned __int16 v51; // r10
  unsigned int v52; // r9
  unsigned __int8 *v53; // r8
  unsigned int v54; // r11
  int v55; // r11
  int v56; // r8
  __int16 v57; // r11
  int v58; // r11
  int v59; // r10
  int v60; // r9
  unsigned int v61; // r11
  unsigned __int8 *v62; // r7
  unsigned int v63; // r28
  unsigned __int16 v64; // r9
  unsigned __int8 *v65; // r9
  unsigned int v66; // r11
  int v67; // r11
  unsigned __int16 v68; // r7
  unsigned int v69; // r8
  unsigned __int8 *v70; // r6
  unsigned __int16 v71; // r10
  unsigned int v72; // r9
  unsigned __int8 *v73; // r10
  unsigned int v74; // r11
  int v75; // r11
  int v76; // r10
  int v77; // r9
  unsigned int v78; // r11
  unsigned __int8 *v79; // r7
  unsigned int v80; // r28
  unsigned __int16 v81; // r9
  unsigned int v82; // r11
  unsigned __int8 *v83; // r9
  int v84; // r11
  int v85; // r8
  unsigned int v86; // r8
  unsigned __int8 *v87; // r6
  unsigned __int16 v88; // r10
  unsigned int v89; // r9
  unsigned __int8 *v90; // r10
  unsigned int v91; // r11
  int v92; // r11

  dad = tree->dl.dad;
  v4 = -1;
  v5 = 0;
  v6 = 7;
  v7 = 4;
  if ( tree->dl.dad == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  if ( max_code >= 0 )
  {
    p_dl = &tree[1].dl;
    for ( i = max_code + 1; i != 0; --i )
    {
      ++v5;
      v10 = dad;
      dad = p_dl->dad;
      if ( v5 < v6 && v10 == p_dl->dad )
        goto LABEL_46;
      if ( v5 < v7 )
      {
        v11 = 4 * (v10 + 671);
        do
        {
          v12 = s->bl_tree[v10].dl.dad;
          bi_valid = s->bi_valid;
          bi_buf = s->bi_buf;
          v15 = *(unsigned __int16 *)((char *)&s->strm + v11);
          if ( bi_valid <= 16 - v12 )
          {
            s->bi_valid = bi_valid + v12;
            s->bi_buf = (v15 << bi_valid) | bi_buf;
          }
          else
          {
            pending = s->pending;
            v17 = (v15 << bi_valid) | bi_buf;
            pending_buf = s->pending_buf;
            v19 = *(unsigned __int16 *)((char *)&s->strm + v11);
            s->bi_buf = v17;
            pending_buf[pending] = v17;
            bi_buf_high = HIBYTE(s->bi_buf);
            v21 = s->pending_buf;
            v22 = s->pending + 1;
            s->pending = v22;
            v21[v22] = bi_buf_high;
            v23 = s->bi_valid;
            ++s->pending;
            s->bi_buf = v19 >> (16 - v23);
            s->bi_valid = v23 + v12 - 16;
          }
          --v5;
        }
        while ( v5 != 0 );
        goto LABEL_41;
      }
      if ( v10 != 0 )
      {
        if ( v10 != v4 )
        {
          v24 = s->bi_buf;
          v25 = s->bi_valid;
          v26 = s->bl_tree[v10].dl.dad;
          v27 = v10 + 671;
          if ( v25 <= 16 - v26 )
          {
            v35 = *((_WORD *)&s->strm + 2 * v27);
            s->bi_valid = v25 + v26;
            s->bi_buf = (v35 << v25) | v24;
          }
          else
          {
            v28 = s->pending;
            v29 = s->pending_buf;
            v30 = *((unsigned __int16 *)&s->strm + 2 * v27);
            v31 = (v30 << v25) | v24;
            s->bi_buf = v31;
            v29[v28] = v31;
            LOBYTE(v28) = HIBYTE(s->bi_buf);
            v32 = s->pending + 1;
            v33 = s->pending_buf;
            s->pending = v32;
            v33[v32] = v28;
            v34 = s->bi_valid;
            ++s->pending;
            s->bi_buf = v30 >> (16 - v34);
            s->bi_valid = v34 + v26 - 16;
          }
          --v5;
        }
        v36 = s->bl_tree[16].dl.dad;
        v37 = s->bi_valid;
        freq = s->bl_tree[16].fc.freq;
        if ( v37 <= 16 - v36 )
        {
          v46 = s->bi_buf;
          s->bi_valid = v37 + v36;
          s->bi_buf = (freq << v37) | v46;
        }
        else
        {
          v40 = s->pending_buf;
          v41 = s->bl_tree[16].fc.freq;
          v42 = (freq << v37) | s->bi_buf;
          v39 = s->pending;
          s->bi_buf = v42;
          v40[v39] = v42;
          v43 = s->pending + 1;
          v44 = s->pending_buf;
          LOBYTE(v40) = HIBYTE(s->bi_buf);
          s->pending = v43;
          v44[v43] = (unsigned __int8)v40;
          v45 = s->bi_valid;
          ++s->pending;
          s->bi_buf = v41 >> (16 - v45);
          s->bi_valid = v45 + v36 - 16;
        }
        v47 = s->bi_valid;
        v48 = s->bi_buf;
        if ( v47 <= 14 )
        {
          v57 = v5 - 3;
          v56 = v47 + 2;
LABEL_39:
          s->bi_buf = (v57 << v47) | v48;
          goto LABEL_40;
        }
        v49 = s->pending;
        v51 = ((v5 - 3) << v47) | v48;
        v52 = (unsigned __int16)(v5 - 3);
        v50 = s->pending_buf;
        s->bi_buf = v51;
        v50[v49] = v51;
        LOBYTE(v51) = HIBYTE(s->bi_buf);
        v53 = s->pending_buf;
        v54 = s->pending + 1;
        s->pending = v54;
        v53[v54] = v51;
        v55 = s->bi_valid;
        v56 = v55 - 14;
        ++s->pending;
        s->bi_buf = v52 >> (16 - v55);
      }
      else
      {
        v58 = s->bi_valid;
        if ( v5 > 10 )
        {
          v76 = s->bl_tree[18].dl.dad;
          v77 = s->bl_tree[18].fc.freq;
          if ( v58 <= 16 - v76 )
          {
            v85 = v58 + v76;
            s->bi_buf |= v77 << v58;
          }
          else
          {
            v79 = s->pending_buf;
            v80 = s->bl_tree[18].fc.freq;
            v81 = (v77 << v58) | s->bi_buf;
            v78 = s->pending;
            s->bi_buf = v81;
            v79[v78] = v81;
            v82 = s->pending + 1;
            LOBYTE(v79) = HIBYTE(s->bi_buf);
            v83 = s->pending_buf;
            s->pending = v82;
            v83[v82] = (unsigned __int8)v79;
            v84 = s->bi_valid;
            ++s->pending;
            v85 = v84 + v76 - 16;
            s->bi_buf = v80 >> (16 - v84);
          }
          LOBYTE(v47) = v85;
          v48 = s->bi_buf;
          s->bi_valid = v85;
          if ( v85 <= 9 )
          {
            v57 = v5 - 11;
            v56 = v85 + 7;
            goto LABEL_39;
          }
          v86 = s->pending;
          v88 = ((v5 - 11) << v47) | v48;
          v89 = (unsigned __int16)(v5 - 11);
          v87 = s->pending_buf;
          s->bi_buf = v88;
          v87[v86] = v88;
          v90 = s->pending_buf;
          LOBYTE(v86) = HIBYTE(s->bi_buf);
          v91 = s->pending + 1;
          s->pending = v91;
          v90[v91] = v86;
          v92 = s->bi_valid;
          v56 = v92 - 9;
          ++s->pending;
          s->bi_buf = v89 >> (16 - v92);
        }
        else
        {
          v59 = s->bl_tree[17].dl.dad;
          v60 = s->bl_tree[17].fc.freq;
          if ( v58 <= 16 - v59 )
          {
            v68 = s->bi_buf;
            s->bi_valid = v58 + v59;
            s->bi_buf = (v60 << v58) | v68;
          }
          else
          {
            v62 = s->pending_buf;
            v63 = s->bl_tree[17].fc.freq;
            v64 = (v60 << v58) | s->bi_buf;
            v61 = s->pending;
            s->bi_buf = v64;
            v62[v61] = v64;
            v65 = s->pending_buf;
            v66 = s->pending + 1;
            LOBYTE(v62) = HIBYTE(s->bi_buf);
            s->pending = v66;
            v65[v66] = (unsigned __int8)v62;
            v67 = s->bi_valid;
            ++s->pending;
            s->bi_buf = v63 >> (16 - v67);
            s->bi_valid = v67 + v59 - 16;
          }
          v47 = s->bi_valid;
          v48 = s->bi_buf;
          if ( v47 <= 13 )
          {
            v57 = v5 - 3;
            v56 = v47 + 3;
            goto LABEL_39;
          }
          v69 = s->pending;
          v71 = ((v5 - 3) << v47) | v48;
          v72 = (unsigned __int16)(v5 - 3);
          v70 = s->pending_buf;
          s->bi_buf = v71;
          v70[v69] = v71;
          v73 = s->pending_buf;
          LOBYTE(v69) = HIBYTE(s->bi_buf);
          v74 = s->pending + 1;
          s->pending = v74;
          v73[v74] = v69;
          v75 = s->bi_valid;
          v56 = v75 - 13;
          ++s->pending;
          s->bi_buf = v72 >> (16 - v75);
        }
      }
LABEL_40:
      s->bi_valid = v56;
LABEL_41:
      v5 = 0;
      v4 = v10;
      if ( dad != 0 )
      {
        if ( v10 == dad )
        {
          v6 = 6;
          v7 = 3;
        }
        else
        {
          v6 = 7;
          v7 = 4;
        }
      }
      else
      {
        v6 = 138;
        v7 = 3;
      }
LABEL_46:
      p_dl += 2;
    }
  }
}


// ========================================================================
// send_all_trees
// EA  : 0x83231F10
// RVA : 0x01231F10
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall send_all_trees(internal_state *s, int lcodes, int dcodes, int blcodes)
{
  int bi_valid; // r10
  unsigned __int16 bi_buf; // r9
  unsigned int pending; // r8
  unsigned __int8 *pending_buf; // r5
  unsigned __int16 v9; // r10
  unsigned __int8 *v10; // r8
  unsigned int v11; // r11
  int v12; // r11
  int v13; // r8
  char v14; // r10
  unsigned __int16 v15; // r9
  unsigned int v16; // r8
  unsigned __int8 *v17; // r5
  unsigned __int16 v18; // r10
  unsigned __int8 *v19; // r8
  unsigned int v20; // r11
  int v21; // r11
  int v22; // r8
  char v23; // r10
  unsigned __int16 v24; // r9
  unsigned int v25; // r8
  unsigned __int8 *v26; // r5
  unsigned __int16 v27; // r10
  unsigned __int8 *v28; // r8
  unsigned int v29; // r11
  int v30; // r11
  int v31; // r9
  int i; // ctr
  int v33; // r11
  int v34; // r10
  unsigned int v35; // r6
  unsigned __int8 *v36; // r5
  unsigned int v37; // r30
  unsigned __int16 v38; // r11
  unsigned int v39; // r11
  unsigned __int8 *v40; // r7
  int v41; // r11
  unsigned __int16 v42; // r6
  __int16 v43; // r10
  internal_state *v44; // r3

  bi_valid = s->bi_valid;
  bi_buf = s->bi_buf;
  if ( bi_valid <= 11 )
  {
    v13 = bi_valid + 5;
    s->bi_buf = ((lcodes + 65279) << bi_valid) | bi_buf;
  }
  else
  {
    pending = s->pending;
    pending_buf = s->pending_buf;
    v9 = ((lcodes - 257) << bi_valid) | bi_buf;
    s->bi_buf = v9;
    pending_buf[pending] = v9;
    LOBYTE(v9) = HIBYTE(s->bi_buf);
    v10 = s->pending_buf;
    v11 = s->pending + 1;
    s->pending = v11;
    v10[v11] = v9;
    v12 = s->bi_valid;
    v13 = v12 - 11;
    ++s->pending;
    s->bi_buf = (unsigned __int16)(lcodes - 257) >> (16 - v12);
  }
  v14 = v13;
  v15 = s->bi_buf;
  s->bi_valid = v13;
  if ( v13 <= 11 )
  {
    v22 = v13 + 5;
    s->bi_buf = ((dcodes + 0xFFFF) << v14) | v15;
  }
  else
  {
    v16 = s->pending;
    v17 = s->pending_buf;
    v18 = ((dcodes - 1) << v14) | v15;
    s->bi_buf = v18;
    v17[v16] = v18;
    LOBYTE(v18) = HIBYTE(s->bi_buf);
    v19 = s->pending_buf;
    v20 = s->pending + 1;
    s->pending = v20;
    v19[v20] = v18;
    v21 = s->bi_valid;
    v22 = v21 - 11;
    ++s->pending;
    s->bi_buf = (unsigned __int16)(dcodes - 1) >> (16 - v21);
  }
  v23 = v22;
  v24 = s->bi_buf;
  s->bi_valid = v22;
  if ( v22 <= 12 )
  {
    s->bi_valid = v22 + 4;
    s->bi_buf = ((blcodes + 65532) << v22) | v24;
  }
  else
  {
    v25 = s->pending;
    v26 = s->pending_buf;
    v27 = ((blcodes - 4) << v23) | v24;
    s->bi_buf = v27;
    v26[v25] = v27;
    v28 = s->pending_buf;
    v29 = s->pending + 1;
    LOBYTE(v27) = HIBYTE(s->bi_buf);
    s->pending = v29;
    v28[v29] = v27;
    v30 = s->bi_valid;
    ++s->pending;
    s->bi_valid = v30 - 12;
    s->bi_buf = (unsigned __int16)(blcodes - 4) >> (16 - v30);
  }
  v31 = 0;
  if ( blcodes > 0 )
  {
    for ( i = blcodes; i != 0; --i )
    {
      v33 = s->bi_valid;
      v34 = __ROL4__(bl_order[v31], 2);
      if ( v33 <= 13 )
      {
        v42 = s->bi_buf;
        v43 = *(unsigned __int16 *)((char *)&s->bl_tree[0].dl.dad + v34);
        s->bi_valid = v33 + 3;
        s->bi_buf = (v43 << v33) | v42;
      }
      else
      {
        v35 = s->pending;
        v36 = s->pending_buf;
        v37 = *(unsigned __int16 *)((char *)&s->bl_tree[0].dl.dad + v34);
        v38 = (v37 << v33) | s->bi_buf;
        s->bi_buf = v38;
        v36[v35] = v38;
        LOBYTE(v35) = HIBYTE(s->bi_buf);
        v39 = s->pending + 1;
        v40 = s->pending_buf;
        s->pending = v39;
        v40[v39] = v35;
        v41 = s->bi_valid;
        ++s->pending;
        s->bi_valid = v41 - 13;
        s->bi_buf = v37 >> (16 - v41);
      }
      ++v31;
    }
  }
  send_tree(s, tree: s->dyn_ltree, max_code: lcodes - 1);
  send_tree(s: v44, tree: v44->dyn_dtree, max_code: dcodes - 1);
}


// ========================================================================
// compress_block
// EA  : 0x832321D0
// RVA : 0x012321D0
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall compress_block(internal_state *s, ct_data_s *ltree, ct_data_s *dtree)
{
  unsigned int v3; // r30
  int v4; // r28
  int v5; // r6
  int v6; // r7
  int bi_valid; // r11
  ct_data_s *v8; // r10
  int v9; // r9
  unsigned int v10; // r10
  int v11; // r7
  unsigned __int16 v12; // r8
  unsigned __int16 v13; // r11
  unsigned int v14; // r6
  unsigned __int8 *v15; // r8
  unsigned __int8 *v16; // r6
  unsigned int v17; // r11
  int v18; // r11
  int v19; // r10
  int v20; // r8
  int v21; // r9
  unsigned int freq; // r10
  unsigned __int16 bi_buf; // r26
  unsigned int pending; // r25
  unsigned __int16 v25; // r11
  unsigned __int8 *pending_buf; // r24
  unsigned int v27; // r26
  unsigned int v28; // r11
  unsigned __int8 bi_buf_high; // r10
  unsigned __int8 *v30; // r25
  int v31; // r11
  int v32; // r9
  int v33; // r11
  int v34; // r10
  unsigned __int16 v35; // r8
  int v36; // r7
  unsigned __int16 v37; // r11
  unsigned int v38; // r8
  unsigned __int8 *v39; // r7
  unsigned __int8 *v40; // r8
  unsigned int v41; // r11
  int v42; // r11
  int v43; // r9
  unsigned int v44; // r7
  int v45; // r11
  int v46; // r8
  int v47; // r11
  ct_data_s *v48; // r10
  int dad; // r9
  unsigned int v50; // r10
  unsigned __int16 v51; // r6
  unsigned int v52; // r26
  unsigned __int16 v53; // r6
  unsigned __int8 *v54; // r11
  unsigned int v55; // r25
  unsigned __int8 *v56; // r10
  unsigned int v57; // r11
  int v58; // r11
  int v59; // r9
  int v60; // r11
  int v61; // r10
  unsigned int v62; // r10
  unsigned __int16 v63; // r6
  unsigned int v64; // r11
  unsigned __int8 *v65; // r8
  unsigned int v66; // r11
  unsigned __int8 *v67; // r8
  int v68; // r11
  int v69; // r10
  int v70; // r11
  unsigned int v71; // r9
  unsigned int v72; // r6
  unsigned __int8 *v73; // r11
  unsigned __int16 v74; // r8
  unsigned __int8 *v75; // r5
  unsigned int v76; // r11
  int v77; // r11
  int v78; // r5

  v3 = 0;
  if ( s->last_lit != 0 )
  {
    v4 = 0;
    do
    {
      v5 = s->d_buf[v4++];
      v6 = s->l_buf[v3++];
      bi_valid = s->bi_valid;
      if ( v5 != 0 )
      {
        v19 = length_code[v6];
        v20 = __ROL4__(v19, 2);
        v21 = *(unsigned __int16 *)((char *)&ltree[257].dl.dad + v20);
        freq = ltree[v19 + 257].fc.freq;
        bi_buf = s->bi_buf;
        if ( bi_valid <= 16 - v21 )
        {
          s->bi_valid = bi_valid + v21;
          s->bi_buf = ((_WORD)freq << bi_valid) | bi_buf;
        }
        else
        {
          pending = s->pending;
          v25 = (freq << bi_valid) | bi_buf;
          pending_buf = s->pending_buf;
          v27 = freq;
          s->bi_buf = v25;
          pending_buf[pending] = v25;
          v28 = s->pending + 1;
          bi_buf_high = HIBYTE(s->bi_buf);
          v30 = s->pending_buf;
          s->pending = v28;
          v30[v28] = bi_buf_high;
          v31 = s->bi_valid;
          ++s->pending;
          s->bi_buf = v27 >> (16 - v31);
          s->bi_valid = v31 + v21 - 16;
        }
        v32 = *(const int *)((char *)extra_lbits + v20);
        if ( v32 != 0 )
        {
          v33 = s->bi_valid;
          v34 = v6 - *(const int *)((char *)base_length + v20);
          v35 = s->bi_buf;
          v36 = v34 << v33;
          if ( v33 <= 16 - v32 )
          {
            v43 = v33 + v32;
            s->bi_buf = v36 | v35;
          }
          else
          {
            v37 = v36 | v35;
            v38 = s->pending;
            v39 = s->pending_buf;
            s->bi_buf = v37;
            v39[v38] = v37;
            LOBYTE(v39) = HIBYTE(s->bi_buf);
            v40 = s->pending_buf;
            v41 = s->pending + 1;
            s->pending = v41;
            v40[v41] = (unsigned __int8)v39;
            v42 = s->bi_valid;
            v43 = v42 + v32 - 16;
            ++s->pending;
            s->bi_buf = (unsigned __int16)v34 >> (16 - v42);
          }
          s->bi_valid = v43;
        }
        v44 = v5 - 1;
        if ( (unsigned int)(v5 - 1) >= 0x100 )
          v45 = dist_code[(v44 >> 7) + 256];
        else
          v45 = dist_code[v44];
        v46 = v45;
        v48 = &dtree[v45];
        v47 = s->bi_valid;
        dad = v48->dl.dad;
        v50 = v48->fc.freq;
        v51 = s->bi_buf;
        if ( v47 <= 16 - dad )
        {
          s->bi_valid = v47 + dad;
          s->bi_buf = (v50 << v47) | v51;
        }
        else
        {
          v52 = s->pending;
          v53 = (v50 << v47) | v51;
          v54 = s->pending_buf;
          v55 = v50;
          s->bi_buf = v53;
          v54[v52] = v53;
          LOBYTE(v53) = HIBYTE(s->bi_buf);
          v56 = s->pending_buf;
          v57 = s->pending + 1;
          s->pending = v57;
          v56[v57] = v53;
          v58 = s->bi_valid;
          ++s->pending;
          s->bi_buf = v55 >> (16 - v58);
          s->bi_valid = v58 + dad - 16;
        }
        v59 = extra_dbits[v46];
        if ( v59 == 0 )
          continue;
        v60 = s->bi_valid;
        v61 = base_dist[v46];
        v12 = s->bi_buf;
        v62 = v44 - v61;
        v11 = v62 << v60;
        if ( v60 <= 16 - v59 )
        {
          s->bi_valid = v60 + v59;
          goto LABEL_25;
        }
        v63 = v11 | v12;
        v64 = s->pending;
        v65 = s->pending_buf;
        s->bi_buf = v63;
        v65[v64] = v63;
        v66 = s->pending + 1;
        LOBYTE(v63) = HIBYTE(s->bi_buf);
        v67 = s->pending_buf;
        s->pending = v66;
        v67[v66] = v63;
        v68 = s->bi_valid;
        ++s->pending;
        s->bi_buf = (unsigned __int16)v62 >> (16 - v68);
        s->bi_valid = v68 + v59 - 16;
      }
      else
      {
        v8 = &ltree[v6];
        v9 = v8->dl.dad;
        v10 = v8->fc.freq;
        v11 = v10 << bi_valid;
        v12 = s->bi_buf;
        if ( bi_valid <= 16 - v9 )
        {
          s->bi_valid = bi_valid + v9;
LABEL_25:
          s->bi_buf = v11 | v12;
          continue;
        }
        v13 = v11 | v12;
        v14 = s->pending;
        v15 = s->pending_buf;
        s->bi_buf = v13;
        v15[v14] = v13;
        LOBYTE(v15) = HIBYTE(s->bi_buf);
        v16 = s->pending_buf;
        v17 = s->pending + 1;
        s->pending = v17;
        v16[v17] = (unsigned __int8)v15;
        v18 = s->bi_valid;
        ++s->pending;
        s->bi_buf = v10 >> (16 - v18);
        s->bi_valid = v18 + v9 - 16;
      }
    }
    while ( v3 < s->last_lit );
  }
  v69 = ltree[256].dl.dad;
  v70 = s->bi_valid;
  v71 = ltree[256].fc.freq;
  if ( v70 <= 16 - v69 )
  {
    v78 = (v71 << v70) | s->bi_buf;
    s->bi_valid = v70 + v69;
    s->bi_buf = v78;
  }
  else
  {
    v72 = s->pending;
    v74 = (v71 << v70) | s->bi_buf;
    v73 = s->pending_buf;
    s->bi_buf = v74;
    v73[v72] = v74;
    v75 = s->pending_buf;
    LOBYTE(v72) = HIBYTE(s->bi_buf);
    v76 = s->pending + 1;
    s->pending = v76;
    v75[v76] = v72;
    v77 = s->bi_valid;
    ++s->pending;
    s->bi_valid = v77 + v69 - 16;
    s->bi_buf = v71 >> (16 - v77);
  }
  s->last_eob_len = ltree[256].dl.dad;
}


// ========================================================================
// set_data_type
// EA  : 0x83232628
// RVA : 0x01232628
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall set_data_type(internal_state *s)
{
  int v1; // r11
  ct_data_s *dyn_ltree; // r10
  ct_data_s *v3; // r10

  v1 = 0;
  dyn_ltree = s->dyn_ltree;
  do
  {
    if ( dyn_ltree->fc.freq != 0 )
      break;
    ++v1;
    ++dyn_ltree;
  }
  while ( v1 < 9 );
  if ( v1 == 9 )
  {
    v1 = 14;
    v3 = &s->dyn_ltree[15];
    while ( v3[-1].fc.freq == 0 )
    {
      if ( v3->fc.freq != 0 )
      {
        ++v1;
        break;
      }
      if ( v3[1].fc.freq != 0 )
      {
        v1 += 2;
        break;
      }
      if ( v3[2].fc.freq != 0 )
      {
        v1 += 3;
        break;
      }
      if ( v3[3].fc.freq != 0 )
      {
        v1 += 4;
        break;
      }
      if ( v3[4].fc.freq != 0 )
      {
        v1 += 5;
        break;
      }
      v1 += 6;
      v3 += 6;
      if ( v1 >= 32 )
        break;
    }
  }
  s->strm->data_type = (_cntlzw(v1 - 32) & 0x20) != 0;
}


// ========================================================================
// bi_flush
// EA  : 0x832326F8
// RVA : 0x012326F8
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall bi_flush(internal_state *s)
{
  int bi_valid; // r11
  unsigned __int8 bi_buf_high; // r6
  unsigned __int8 *pending_buf; // r5
  unsigned int v4; // r11
  unsigned int v5; // r4
  unsigned int v6; // r5

  bi_valid = s->bi_valid;
  if ( bi_valid == 16 )
  {
    s->pending_buf[s->pending] = s->bi_buf;
    bi_buf_high = HIBYTE(s->bi_buf);
    pending_buf = s->pending_buf;
    v4 = s->pending + 1;
    s->pending = v4;
    pending_buf[v4] = bi_buf_high;
    v5 = s->pending + 1;
    s->bi_buf = 0;
    s->bi_valid = 0;
    s->pending = v5;
  }
  else if ( bi_valid >= 8 )
  {
    s->pending_buf[s->pending] = s->bi_buf;
    s->bi_buf = HIBYTE(s->bi_buf);
    v6 = s->pending + 1;
    s->bi_valid -= 8;
    s->pending = v6;
  }
}


// ========================================================================
// bi_windup
// EA  : 0x83232788
// RVA : 0x01232788
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall bi_windup(internal_state *s)
{
  int bi_valid; // r11
  unsigned __int8 bi_buf_high; // r6
  unsigned __int8 *pending_buf; // r7
  unsigned int v4; // r11

  bi_valid = s->bi_valid;
  if ( bi_valid <= 8 )
  {
    if ( bi_valid > 0 )
      s->pending_buf[s->pending++] = s->bi_buf;
    s->bi_buf = 0;
    s->bi_valid = 0;
  }
  else
  {
    s->pending_buf[s->pending] = s->bi_buf;
    bi_buf_high = HIBYTE(s->bi_buf);
    pending_buf = s->pending_buf;
    v4 = s->pending + 1;
    s->pending = v4;
    pending_buf[v4] = bi_buf_high;
    ++s->pending;
    s->bi_buf = 0;
    s->bi_valid = 0;
  }
}


// ========================================================================
// _tr_init
// EA  : 0x83232810
// RVA : 0x01232810
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall tr_init(internal_state *s)
{
  int *p_nice_match; // r11
  int v2; // ctr
  ct_data_s *v3; // r11
  int i; // ctr
  ct_data_s *v5; // r11
  int j; // ctr

  s->l_desc.stat_desc = &static_l_desc;
  s->bi_buf = 0;
  s->d_desc.stat_desc = &static_d_desc;
  s->l_desc.dyn_tree = s->dyn_ltree;
  s->bl_desc.stat_desc = &static_bl_desc;
  s->d_desc.dyn_tree = s->dyn_dtree;
  s->bl_desc.dyn_tree = s->bl_tree;
  p_nice_match = &s->nice_match;
  s->bi_valid = 0;
  v2 = 286;
  s->last_eob_len = 8;
  do
  {
    *(_WORD *)++p_nice_match = 0;
    --v2;
  }
  while ( v2 != 0 );
  v3 = &s->dyn_ltree[572];
  for ( i = 30; i != 0; --i )
  {
    ++v3;
    v3->fc.freq = 0;
  }
  v5 = &s->dyn_dtree[60];
  for ( j = 19; j != 0; --j )
  {
    ++v5;
    v5->fc.freq = 0;
  }
  s->static_len = 0;
  s->opt_len = 0;
  s->dyn_ltree[256].fc.freq = 1;
  s->matches = 0;
  s->last_lit = 0;
}


// ========================================================================
// build_tree
// EA  : 0x832328B0
// RVA : 0x012328B0
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall build_tree(internal_state *s, tree_desc_s *desc)
{
  static_tree_desc_s *stat_desc; // r10
  ct_data_s *dyn_tree; // r31
  int v5; // r26
  int v6; // r11
  int elems; // r28
  const ct_data_s *static_tree; // r6
  ct_data_s *v9; // r9
  int i; // ctr
  int v11; // r7
  int v12; // r11
  int v13; // r5
  int j; // r30
  unsigned __int8 *depth; // r30
  ct_data_s *v16; // r29
  int heap_len; // r11
  int v18; // r24
  int v19; // r7
  internal_state *v20; // r3
  int v21; // r6
  ct_data_s *v22; // r10
  ct_data_s *v23; // r9
  int v24; // r11
  int v25; // r11
  unsigned int v26; // r11
  int v27; // r10
  int v28; // r11
  __int16 v29; // r11
  _WORD *v30; // r9
  int v31; // r3
  _WORD *v32; // r10
  int k; // ctr
  int v34; // r6
  int dad; // r11
  int v36; // ctr
  unsigned int v37; // r8
  unsigned int v38; // r9
  int v39; // r10
  _WORD v40[56]; // [sp+50h] [-70h] BYREF

  stat_desc = desc->stat_desc;
  dyn_tree = desc->dyn_tree;
  v5 = -1;
  v6 = 0;
  elems = stat_desc->elems;
  static_tree = stat_desc->static_tree;
  s->heap_len = 0;
  s->heap_max = 573;
  if ( elems > 0 )
  {
    v9 = dyn_tree;
    for ( i = elems; i != 0; --i )
    {
      if ( v9->fc.freq != 0 )
      {
        v5 = v6;
        v11 = s->heap_len + 728;
        ++s->heap_len;
        *((_DWORD *)&s->strm + v11) = v6;
        s->depth[v6] = 0;
      }
      else
      {
        v9->dl.dad = 0;
      }
      ++v6;
      ++v9;
    }
  }
  while ( s->heap_len < 2 )
  {
    if ( v5 >= 2 )
      v12 = 0;
    else
      v12 = ++v5;
    v13 = s->heap_len + 728;
    ++s->heap_len;
    *((_DWORD *)&s->strm + v13) = v12;
    dyn_tree[v12].fc.freq = 1;
    s->depth[v12] = 0;
    --s->opt_len;
    if ( static_tree != nullptr )
      s->static_len -= static_tree[v12].dl.dad;
  }
  desc->max_code = v5;
  for ( j = s->heap_len / 2; j >= 1; --j )
    pqdownheap(s, tree: dyn_tree, k: j);
  depth = s->depth;
  v16 = &dyn_tree[elems];
  do
  {
    heap_len = s->heap_len;
    v18 = s->heap[1];
    v19 = s->heap[heap_len];
    s->heap_len = heap_len - 1;
    s->heap[1] = v19;
    pqdownheap(s, tree: dyn_tree, k: 1);
    v21 = v20->heap[1];
    v22 = &dyn_tree[v18];
    v23 = &dyn_tree[v21];
    v24 = v20->heap_max - 1;
    v20->heap_max = v24;
    v20->heap[v24] = v18;
    v25 = v20->heap_max - 1;
    v20->heap_max = v25;
    v20->heap[v25] = v21;
    v16->fc.freq = v23->fc.freq + v22->fc.freq;
    v26 = depth[v21];
    if ( depth[v18] >= v26 )
      LOBYTE(v26) = depth[v18];
    depth[elems] = v26 + 1;
    v23->dl.dad = elems;
    v22->dl.dad = elems;
    ++v16;
    v20->heap[1] = elems++;
    pqdownheap(s: v20, tree: dyn_tree, k: 1);
  }
  while ( s->heap_len >= 2 );
  v27 = s->heap[1];
  v28 = s->heap_max - 1;
  s->heap_max = v28;
  s->heap[v28] = v27;
  gen_bitlen(s, desc);
  v29 = 0;
  v30 = v40;
  v32 = (_WORD *)(v31 + 2874);
  for ( k = 15; k != 0; --k )
  {
    v29 = 2 * (*++v32 + v29);
    *++v30 = v29;
  }
  if ( v5 >= 0 )
  {
    v34 = v5 + 1;
    do
    {
      dad = dyn_tree->dl.dad;
      if ( dyn_tree->dl.dad != 0 )
      {
        v36 = dyn_tree->dl.dad;
        v37 = 0;
        v38 = (unsigned __int16)v40[dad];
        v40[dad] = v38 + 1;
        do
        {
          v39 = v38 & 1 | v37;
          v38 >>= 1;
          v37 = 2 * v39;
          --v36;
        }
        while ( v36 != 0 );
        dyn_tree->fc.freq = v37 >> 1;
      }
      --v34;
      ++dyn_tree;
    }
    while ( v34 != 0 );
  }
}


// ========================================================================
// build_bl_tree
// EA  : 0x83232B80
// RVA : 0x01232B80
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

int __fastcall build_bl_tree(internal_state *s)
{
  internal_state *v2; // r3
  internal_state *v3; // r3
  int result; // r3

  scan_tree(s, tree: s->dyn_ltree, max_code: s->l_desc.max_code);
  scan_tree(s: v2, tree: v2->dyn_dtree, max_code: v2->d_desc.max_code);
  build_tree(s: v3, desc: &v3->bl_desc);
  result = 18;
  while ( *(unsigned __int16 *)((char *)&s->bl_tree[0].dl.dad + __ROL4__(bl_order[result], 2)) == 0 )
  {
    if ( *(unsigned __int16 *)((char *)&s->bl_tree[0].dl.dad + __ROL4__(bl_order[result - 1], 2)) != 0 )
    {
      --result;
      break;
    }
    if ( *(unsigned __int16 *)((char *)&s->bl_tree[0].dl.dad + __ROL4__(bl_order[result - 2], 2)) != 0 )
    {
      result -= 2;
      break;
    }
    if ( *(unsigned __int16 *)((char *)&s->bl_tree[0].dl.dad + __ROL4__(bl_order[result - 3], 2)) != 0 )
    {
      result -= 3;
      break;
    }
    result -= 4;
    if ( result < 3 )
      break;
  }
  s->opt_len += 3 * result + 17;
  return result;
}


// ========================================================================
// _tr_stored_block
// EA  : 0x83232C80
// RVA : 0x01232C80
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall tr_stored_block(internal_state *s, char *buf, unsigned int stored_len, int eof)
{
  int bi_valid; // r11
  int v5; // r7
  unsigned int pending; // r5
  unsigned __int8 *pending_buf; // r11
  unsigned __int8 *v8; // r10
  unsigned int v9; // r11
  int v10; // r11
  int v11; // r8
  int v12; // r4
  _DWORD *v13; // r3
  int v14; // r10
  int v15; // r11
  int v16; // r9
  int v17; // r11
  int v18; // r7
  int v19; // r11
  int v20; // r11
  int v21; // ctr
  int v22; // r10

  bi_valid = s->bi_valid;
  v5 = (eof << bi_valid) | s->bi_buf;
  if ( bi_valid <= 13 )
  {
    s->bi_buf = v5;
    s->bi_valid = bi_valid + 3;
  }
  else
  {
    pending = s->pending;
    pending_buf = s->pending_buf;
    s->bi_buf = v5;
    pending_buf[pending] = v5;
    LOBYTE(pending) = HIBYTE(s->bi_buf);
    v8 = s->pending_buf;
    v9 = s->pending + 1;
    s->pending = v9;
    v8[v9] = pending;
    v10 = s->bi_valid;
    ++s->pending;
    s->bi_valid = v10 - 13;
    s->bi_buf = (unsigned __int16)eof >> (16 - v10);
  }
  bi_windup(s);
  v13[1453] = 8;
  *(_BYTE *)(v13[2] + v13[5]) = v11;
  v14 = v13[2];
  v15 = v13[5] + 1;
  v13[5] = v15;
  *(_BYTE *)(v14 + v15) = BYTE2(v11);
  v16 = v13[2];
  v17 = v13[5] + 1;
  v13[5] = v17;
  *(_BYTE *)(v16 + v17) = ~(_BYTE)v11;
  v18 = v13[2];
  v19 = v13[5] + 1;
  v13[5] = v19;
  *(_BYTE *)(v18 + v19) = (unsigned __int16)~(_WORD)v11 >> 8;
  v20 = v13[5] + 1;
  v13[5] = v20;
  if ( v11 != 0 )
  {
    v21 = v11;
    v22 = v12 - 1;
    do
    {
      *(_BYTE *)(v13[2] + v20) = *(_BYTE *)++v22;
      v20 = v13[5] + 1;
      v13[5] = v20;
      --v21;
    }
    while ( v21 != 0 );
  }
}


// ========================================================================
// _tr_align
// EA  : 0x83232DC0
// RVA : 0x01232DC0
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall tr_align(internal_state *s)
{
  int bi_valid; // r11
  unsigned __int16 bi_buf; // r10
  int v3; // r8
  unsigned int pending; // r9
  unsigned __int8 *pending_buf; // r7
  unsigned __int8 bi_buf_high; // r10
  unsigned __int8 *v7; // r9
  unsigned int v8; // r11
  int v9; // r11
  unsigned int v10; // r6
  int v11; // r11
  unsigned __int16 v12; // r10
  unsigned int v13; // r9
  unsigned __int8 *v14; // r7
  unsigned int v15; // r11
  unsigned int v16; // r4
  internal_state *v17; // r3
  int v18; // r11
  int v19; // r8
  unsigned int v20; // r7
  unsigned __int8 *v21; // r6
  unsigned __int8 *v22; // r10
  unsigned __int8 v23; // r9
  int v24; // r11
  int v25; // r11
  int v26; // r4
  int v27; // r11
  unsigned __int16 v28; // r8
  unsigned int v29; // r7
  unsigned __int8 *v30; // r6
  unsigned __int8 *v31; // r10
  unsigned __int8 v32; // r9
  int v33; // r11
  int v34; // r11

  bi_valid = s->bi_valid;
  bi_buf = s->bi_buf;
  v3 = 2 << bi_valid;
  if ( bi_valid <= 13 )
  {
    s->bi_valid = bi_valid + 3;
    s->bi_buf = v3 | bi_buf;
  }
  else
  {
    pending = s->pending;
    pending_buf = s->pending_buf;
    s->bi_buf = v3 | bi_buf;
    pending_buf[pending] = v3 | bi_buf;
    bi_buf_high = HIBYTE(s->bi_buf);
    v7 = s->pending_buf;
    v8 = s->pending + 1;
    s->pending = v8;
    v7[v8] = bi_buf_high;
    v9 = s->bi_valid;
    v10 = s->pending + 1;
    s->bi_valid = v9 - 13;
    s->pending = v10;
    s->bi_buf = 2u >> (16 - v9);
  }
  v11 = s->bi_valid;
  v12 = s->bi_buf;
  if ( v11 <= 9 )
  {
    s->bi_valid = v11 + 7;
    s->bi_buf = v12;
  }
  else
  {
    v13 = s->pending;
    v14 = s->pending_buf;
    s->bi_buf = v12;
    v14[v13] = v12;
    v15 = s->pending + 1;
    s->pending = v15;
    s->pending_buf[v15] = HIBYTE(s->bi_buf);
    v16 = s->pending + 1;
    s->bi_valid -= 9;
    s->pending = v16;
    s->bi_buf = 0;
  }
  bi_flush(s);
  v18 = v17->bi_valid;
  if ( v17->last_eob_len - v18 + 11 < 9 )
  {
    v19 = (2 << v18) | v17->bi_buf;
    if ( v18 <= 13 )
    {
      v17->bi_buf = v19;
      v17->bi_valid = v18 + 3;
    }
    else
    {
      v20 = v17->pending;
      v21 = v17->pending_buf;
      v17->bi_buf = v19;
      v21[v20] = v19;
      v22 = v17->pending_buf;
      v23 = HIBYTE(v17->bi_buf);
      v24 = v17->pending + 1;
      v17->pending = v24;
      v22[v24] = v23;
      v25 = v17->bi_valid;
      v26 = v17->pending + 1;
      v17->bi_valid = v25 - 13;
      v17->pending = v26;
      v17->bi_buf = 2u >> (16 - v25);
    }
    v27 = v17->bi_valid;
    v28 = v17->bi_buf;
    if ( v27 <= 9 )
    {
      v17->bi_buf = v28;
      v17->bi_valid = v27 + 7;
    }
    else
    {
      v29 = v17->pending;
      v30 = v17->pending_buf;
      v17->bi_buf = v28;
      v30[v29] = v28;
      v31 = v17->pending_buf;
      v32 = HIBYTE(v17->bi_buf);
      v33 = v17->pending + 1;
      v17->pending = v33;
      v31[v33] = v32;
      v34 = v17->bi_valid;
      ++v17->pending;
      v17->bi_valid = v34 - 9;
      v17->bi_buf = 0;
    }
    bi_flush(s: v17);
  }
  v17->last_eob_len = 7;
}


// ========================================================================
// _tr_flush_block
// EA  : 0x83233020
// RVA : 0x01233020
// PDB : w:\tech5\libs\zlib\trees.c
// ========================================================================

void __fastcall tr_flush_block(internal_state *s, char *buf, unsigned int stored_len, int eof)
{
  int level; // r11
  int v9; // r3
  internal_state *v10; // r3
  internal_state *v11; // r3
  unsigned int v12; // r11
  unsigned int v13; // r10
  int v14; // r10
  unsigned __int16 v15; // r9
  int v16; // r7
  unsigned int v17; // r8
  unsigned __int8 *v18; // r6
  unsigned __int8 v19; // r9
  unsigned __int8 *v20; // r8
  unsigned int v21; // r11
  int v22; // r11
  ct_data_s *dyn_dtree; // r5
  ct_data_s *dyn_ltree; // r4
  int bi_valid; // r10
  unsigned __int16 bi_buf; // r9
  int v27; // r7
  unsigned int pending; // r8
  unsigned __int8 *pending_buf; // r6
  unsigned __int8 *v30; // r9
  unsigned int v31; // r11
  unsigned __int8 bi_buf_high; // r10
  int v33; // r11
  int *p_nice_match; // r11
  int i; // ctr
  ct_data_s *v36; // r11
  int j; // ctr
  ct_data_s *v38; // r11
  int k; // ctr

  level = s->level;
  v9 = 0;
  if ( level <= 0 )
  {
    v13 = stored_len + 5;
LABEL_8:
    v12 = v13;
    goto LABEL_9;
  }
  if ( stored_len != 0 && s->strm->data_type == 2 )
    set_data_type(s);
  build_tree(s, desc: &s->l_desc);
  build_tree(s: v10, desc: &s->d_desc);
  v9 = build_bl_tree(s: v11);
  v12 = (s->opt_len + 10) >> 3;
  v13 = (s->static_len + 10) >> 3;
  if ( v13 <= v12 )
    goto LABEL_8;
LABEL_9:
  if ( stored_len + 4 <= v12 && buf != nullptr )
  {
    tr_stored_block(s, buf, stored_len, eof);
  }
  else
  {
    if ( s->strategy == 4 || v13 == v12 )
    {
      bi_valid = s->bi_valid;
      bi_buf = s->bi_buf;
      v27 = (eof + 2) << bi_valid;
      if ( bi_valid <= 13 )
      {
        s->bi_valid = bi_valid + 3;
        s->bi_buf = v27 | bi_buf;
      }
      else
      {
        pending = s->pending;
        pending_buf = s->pending_buf;
        s->bi_buf = v27 | bi_buf;
        pending_buf[pending] = v27 | bi_buf;
        v30 = s->pending_buf;
        v31 = s->pending + 1;
        bi_buf_high = HIBYTE(s->bi_buf);
        s->pending = v31;
        v30[v31] = bi_buf_high;
        v33 = s->bi_valid;
        ++s->pending;
        s->bi_valid = v33 - 13;
        s->bi_buf = (unsigned __int16)(eof + 2) >> (16 - v33);
      }
      dyn_ltree = (ct_data_s *)static_ltree;
      dyn_dtree = (ct_data_s *)static_dtree;
    }
    else
    {
      v14 = s->bi_valid;
      v15 = s->bi_buf;
      v16 = (eof + 4) << v14;
      if ( v14 <= 13 )
      {
        s->bi_valid = v14 + 3;
        s->bi_buf = v16 | v15;
      }
      else
      {
        v17 = s->pending;
        v18 = s->pending_buf;
        s->bi_buf = v16 | v15;
        v18[v17] = v16 | v15;
        v19 = HIBYTE(s->bi_buf);
        v20 = s->pending_buf;
        v21 = s->pending + 1;
        s->pending = v21;
        v20[v21] = v19;
        v22 = s->bi_valid;
        ++s->pending;
        s->bi_valid = v22 - 13;
        s->bi_buf = (unsigned __int16)(eof + 4) >> (16 - v22);
      }
      send_all_trees(s, lcodes: s->l_desc.max_code + 1, dcodes: s->d_desc.max_code + 1, blcodes: v9 + 1);
      dyn_dtree = s->dyn_dtree;
      dyn_ltree = s->dyn_ltree;
    }
    compress_block(s, ltree: dyn_ltree, dtree: dyn_dtree);
  }
  p_nice_match = &s->nice_match;
  for ( i = 286; i != 0; --i )
    *(_WORD *)++p_nice_match = 0;
  v36 = &s->dyn_ltree[572];
  for ( j = 30; j != 0; --j )
  {
    ++v36;
    v36->fc.freq = 0;
  }
  v38 = &s->dyn_dtree[60];
  for ( k = 19; k != 0; --k )
  {
    ++v38;
    v38->fc.freq = 0;
  }
  s->static_len = 0;
  s->opt_len = 0;
  s->dyn_ltree[256].fc.freq = 1;
  s->matches = 0;
  s->last_lit = 0;
  if ( eof != 0 )
    bi_windup(s);
}

