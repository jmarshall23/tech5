
// ========================================================================
// inflate_fast
// EA  : 0x832249A8
// RVA : 0x012249A8
// PDB : w:\tech5\libs\zlib\inffast.c
// ========================================================================

void __fastcall inflate_fast(z_stream_s *strm, unsigned int start)
{
  internal_state *state; // r30
  unsigned __int8 *v3; // r31
  unsigned int avail_out; // r11
  unsigned __int8 *v5; // r7
  int last_flush; // r25
  unsigned int w_size; // r20
  unsigned int w_bits; // r28
  unsigned int v9; // r21
  unsigned int w_mask; // r19
  unsigned __int8 *v11; // r24
  unsigned __int8 *window; // r11
  unsigned int v13; // r18
  unsigned int window_size; // r9
  int v15; // r22
  unsigned int hash_size; // r26
  int v17; // r23
  unsigned int hash_bits; // r27
  unsigned __int8 *v19; // r31
  int v20; // r8
  char v21; // r10
  unsigned int v22; // r10
  unsigned int v23; // r5
  int v24; // r8
  unsigned __int8 *v25; // r31
  int v26; // r8
  char v27; // r10
  unsigned int v28; // r10
  int v29; // r8
  int v30; // r8
  unsigned int v31; // r4
  unsigned __int8 *v32; // r10
  unsigned int v33; // r8
  unsigned int v34; // r10
  unsigned __int8 *v35; // r10
  unsigned int v36; // r8
  int v37; // r10
  unsigned int v38; // r8
  unsigned int v39; // ctr
  _BYTE *v40; // r10
  _BYTE *v41; // r7
  _BYTE *v42; // r10
  _BYTE *v43; // r7
  unsigned __int8 *v44; // r10
  char *v45; // r6
  unsigned int v46; // r8
  unsigned __int8 *v47; // r10
  int back_chain; // [sp+0h] [-90h]
  int back_chaina; // [sp+0h] [-90h]

  state = strm->state;
  v3 = strm->next_in - 1;
  avail_out = strm->avail_out;
  v5 = strm->next_out - 1;
  last_flush = state->last_flush;
  w_size = state->w_size;
  w_bits = state->w_bits;
  v9 = (unsigned int)&v3[strm->avail_in - 5];
  w_mask = state->w_mask;
  v11 = &v5[avail_out - start];
  v13 = (unsigned int)&v5[avail_out - 257];
  window = state->window;
  window_size = state->window_size;
  v15 = (1 << state->hash_mask) - 1;
  hash_size = state->hash_size;
  v17 = (1 << state->hash_shift) - 1;
  hash_bits = state->hash_bits;
  do
  {
    if ( window_size < 0xF )
    {
      v19 = v3 + 1;
      v20 = *v19 << window_size;
      v3 = v19 + 1;
      window += (*v3 << (window_size + 8)) + v20;
      window_size += 16;
    }
    back_chain = *(_DWORD *)(4 * (v15 & (unsigned int)window) + hash_size);
    v21 = HIBYTE(back_chain);
    window = (unsigned __int8 *)((unsigned int)window >> SBYTE1(back_chain));
    window_size -= BYTE1(back_chain);
    if ( HIBYTE(back_chain) == 0 )
    {
LABEL_8:
      *++v5 = back_chain;
      continue;
    }
    while ( (v21 & 0x10) == 0 )
    {
      if ( (v21 & 0x40) != 0 )
      {
        if ( (v21 & 0x20) != 0 )
        {
          state->strm = (z_stream_s *)11;
          goto LABEL_58;
        }
        v45 = "invalid literal/length code";
        goto LABEL_57;
      }
      back_chain = *(_DWORD *)(4 * ((((1 << v21) - 1) & (unsigned int)window) + (unsigned __int16)back_chain) + hash_size);
      v21 = HIBYTE(back_chain);
      window = (unsigned __int8 *)((unsigned int)window >> SBYTE1(back_chain));
      window_size -= BYTE1(back_chain);
      if ( HIBYTE(back_chain) == 0 )
        goto LABEL_8;
    }
    v22 = v21 & 0xF;
    v23 = (unsigned __int16)back_chain;
    if ( v22 != 0 )
    {
      if ( window_size < v22 )
      {
        window += *++v3 << window_size;
        window_size += 8;
      }
      window_size -= v22;
      v24 = ((1 << v22) - 1) & (unsigned int)window;
      window = (unsigned __int8 *)((unsigned int)window >> v22);
      v23 = v24 + (unsigned __int16)back_chain;
    }
    if ( window_size < 0xF )
    {
      v25 = v3 + 1;
      v26 = *v25 << window_size;
      v3 = v25 + 1;
      window += (*v3 << (window_size + 8)) + v26;
      window_size += 16;
    }
    back_chaina = *(_DWORD *)(4 * (v17 & (unsigned int)window) + hash_bits);
    v27 = HIBYTE(back_chaina);
    window = (unsigned __int8 *)((unsigned int)window >> SBYTE1(back_chaina));
    window_size -= BYTE1(back_chaina);
    if ( (back_chaina & 0x10000000) == 0 )
    {
      while ( (v27 & 0x40) == 0 )
      {
        back_chaina = *(_DWORD *)(4 * ((((1 << v27) - 1) & (unsigned int)window) + (unsigned __int16)back_chaina)
                                + hash_bits);
        v27 = HIBYTE(back_chaina);
        window = (unsigned __int8 *)((unsigned int)window >> SBYTE1(back_chaina));
        window_size -= BYTE1(back_chaina);
        if ( (back_chaina & 0x10000000) != 0 )
          goto LABEL_18;
      }
      v45 = "invalid distance code";
      goto LABEL_57;
    }
LABEL_18:
    v28 = v27 & 0xF;
    if ( window_size < v28 )
    {
      v29 = *++v3 << window_size;
      window_size += 8;
      window += v29;
      if ( window_size < v28 )
      {
        window += *++v3 << window_size;
        window_size += 8;
      }
    }
    window_size -= v28;
    v30 = ((1 << v28) - 1) & (unsigned int)window;
    window = (unsigned __int8 *)((unsigned int)window >> v28);
    v31 = v30 + (unsigned __int16)back_chaina;
    v32 = (unsigned __int8 *)(v5 - v11);
    if ( v31 > v5 - v11 )
    {
      v33 = v31 - (_DWORD)v32;
      if ( v31 - (unsigned int)v32 > w_size )
      {
        v45 = "invalid distance too far back";
LABEL_57:
        strm->msg = v45;
        state->strm = (z_stream_s *)27;
        break;
      }
      v34 = w_mask - 1 - v33;
      if ( w_bits != 0 )
      {
        v35 = (unsigned __int8 *)(v34 + w_bits);
        if ( w_bits >= v33 )
        {
          if ( v33 >= v23 )
            goto LABEL_40;
          v23 -= v33;
          do
          {
            ++v35;
            --v33;
            *++v5 = *v35;
          }
          while ( v33 != 0 );
        }
        else
        {
          v36 = v33 - w_bits;
          v35 += last_flush;
          if ( v36 >= v23 )
            goto LABEL_40;
          v23 -= v36;
          v37 = v35 - v5;
          do
          {
            ++v5;
            --v36;
            *v5 = v5[v37];
          }
          while ( v36 != 0 );
          v35 = (unsigned __int8 *)(w_mask - 1);
          if ( w_bits >= v23 )
          {
LABEL_40:
            if ( v23 > 2 )
            {
              v39 = (v23 - 3) / 3 + 1;
              do
              {
                v40 = v35 + 1;
                v23 -= 3;
                v41 = v5 + 1;
                *v41 = *v40++;
                *++v41 = *v40;
                v35 = v40 + 1;
                v5 = v41 + 1;
                *v5 = *v35;
                --v39;
              }
              while ( v39 != 0 );
            }
            goto LABEL_46;
          }
          v38 = w_bits;
          v23 -= w_bits;
          do
          {
            ++v35;
            --v38;
            *++v5 = *v35;
          }
          while ( v38 != 0 );
        }
      }
      else
      {
        v35 = (unsigned __int8 *)(v34 + last_flush);
        if ( v33 >= v23 )
          goto LABEL_40;
        v23 -= v33;
        do
        {
          ++v35;
          --v33;
          *++v5 = *v35;
        }
        while ( v33 != 0 );
      }
      v35 = &v5[-v31];
      goto LABEL_40;
    }
    v35 = &v5[-v31];
    do
    {
      v42 = v35 + 1;
      v23 -= 3;
      v43 = v5 + 1;
      *v43 = *v42++;
      *++v43 = *v42;
      v35 = v42 + 1;
      v5 = v43 + 1;
      *v5 = *v35;
    }
    while ( v23 > 2 );
LABEL_46:
    if ( v23 != 0 )
    {
      v44 = v35 + 1;
      *++v5 = *v44;
      if ( v23 > 1 )
        *++v5 = v44[1];
    }
  }
  while ( (unsigned int)v3 < v9 && (unsigned int)v5 < v13 );
LABEL_58:
  v46 = window_size - (window_size & 0xFFFFFFF8);
  v47 = &v3[-(window_size >> 3)];
  strm->next_in = v47 + 1;
  strm->next_out = v5 + 1;
  strm->avail_in = v9 - (_DWORD)v47 + 5;
  strm->avail_out = v13 - (_DWORD)v5 + 257;
  state->window = (unsigned __int8 *)(((1 << v46) - 1) & (unsigned int)window);
  state->window_size = v46;
}

