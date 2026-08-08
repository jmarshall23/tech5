
// ========================================================================
// flush_pending
// EA  : 0x8321E7F8
// RVA : 0x0121E7F8
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

void __fastcall flush_pending(z_stream_s *strm)
{
  internal_state *state; // r11
  size_t pending; // r30
  internal_state *v4; // r11
  internal_state *v5; // r11
  unsigned int v6; // r7
  internal_state *v7; // r11

  state = strm->state;
  pending = state->pending;
  if ( pending > strm->avail_out )
    pending = strm->avail_out;
  if ( pending != 0 )
  {
    memcpy(Dst: strm->next_out, Src: state->pending_out, Size: pending);
    v4 = strm->state;
    strm->next_out += pending;
    v4->pending_out += pending;
    v5 = strm->state;
    v6 = strm->total_out + pending;
    strm->avail_out -= pending;
    strm->total_out = v6;
    v5->pending -= pending;
    v7 = strm->state;
    if ( v7->pending == 0 )
      v7->pending_out = v7->pending_buf;
  }
}


// ========================================================================
// deflate
// EA  : 0x8321E8B8
// RVA : 0x0121E8B8
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

int __fastcall deflate(z_stream_s *strm, unsigned int flush)
{
  internal_state *state; // r31
  int status; // r11
  int last_flush; // r26
  unsigned __int8 *pending_buf; // r6
  int v9; // r11
  unsigned __int8 *v10; // r5
  int v11; // r11
  gz_header_s *gzhead; // r11
  int v13; // r10
  unsigned __int8 *v14; // r10
  int v15; // r11
  unsigned __int8 *v16; // r9
  int v17; // r11
  unsigned __int8 *v18; // r8
  int v19; // r11
  unsigned __int8 *v20; // r7
  int v21; // r11
  int v22; // r10
  int v23; // r11
  char v24; // r10
  bool v25; // zf
  unsigned __int8 *v26; // r6
  int v27; // r11
  unsigned int pending; // r11
  gz_header_s *v29; // r6
  unsigned __int8 *v30; // r5
  int v31; // r11
  gz_header_s *v32; // r10
  unsigned __int8 *v33; // r9
  int v34; // r11
  gz_header_s *v35; // r7
  unsigned __int8 *v36; // r6
  int v37; // r11
  gz_header_s *v38; // r4
  unsigned __int8 *v39; // r3
  int v40; // r11
  int level; // r10
  int v42; // r11
  char v43; // r10
  unsigned __int8 *v44; // r6
  gz_header_s *v45; // r7
  int v46; // r11
  gz_header_s *v47; // r11
  unsigned int v48; // r5
  unsigned __int8 *v49; // r8
  gz_header_s *v50; // r7
  int v51; // r11
  int v52; // r11
  int v53; // r11
  unsigned int v54; // r11
  unsigned int v55; // r8
  unsigned __int8 *v56; // r7
  unsigned int v57; // r11
  unsigned __int8 v58; // r4
  unsigned __int8 *v59; // r3
  int v60; // r11
  unsigned int strstart; // r10
  int v62; // r11
  __int16 adler_high; // r10
  int v64; // r11
  unsigned __int8 *v65; // r6
  int v66; // r11
  unsigned __int8 *v67; // r5
  __int16 adler; // r4
  unsigned __int8 *v69; // r9
  int v70; // r11
  gz_header_s *v71; // r11
  unsigned int v72; // r10
  unsigned int v73; // r11
  unsigned int v74; // r4
  int v75; // r3
  unsigned int v76; // r11
  unsigned int v77; // r9
  unsigned int v78; // r11
  unsigned int gzindex; // r10
  unsigned __int8 *v80; // r7
  int v81; // r29
  unsigned int v82; // r11
  unsigned int v83; // r9
  unsigned int v84; // r11
  unsigned int v85; // r10
  unsigned __int8 *v86; // r7
  int v87; // r29
  unsigned int v88; // r11
  unsigned int v89; // r11
  int v90; // r11
  int v91; // r11
  block_state v92; // r3
  int wrap; // r11
  unsigned int v94; // r10
  unsigned __int8 *v95; // r9
  unsigned __int8 *v96; // r7
  int v97; // r11
  int v98; // r11
  unsigned __int8 *v99; // r5
  unsigned __int8 *v100; // r3
  int v101; // r11
  int v102; // r11
  unsigned __int8 *v103; // r6
  int v104; // r11
  unsigned __int8 *v105; // r4
  int v106; // r11
  unsigned __int8 *v107; // r10
  int v108; // r11
  __int16 v109; // r7
  unsigned __int8 *v110; // r6
  int v111; // r11
  unsigned __int8 *v112; // r5
  int v113; // r11
  __int16 v114; // r4
  unsigned __int8 *v115; // r9
  int v116; // r11
  int v117; // r11

  if ( strm == nullptr )
    return -2;
  state = strm->state;
  if ( state == nullptr || flush > 4 )
    return -2;
  if ( strm->next_out == nullptr
    || strm->next_in == nullptr && strm->avail_in != 0
    || (status = state->status) == 666 && flush != 4 )
  {
    strm->msg = (char *)-2109691632;
    return -2;
  }
  if ( strm->avail_out == 0 )
  {
LABEL_10:
    strm->msg = (char *)-2109691680;
    return -5;
  }
  last_flush = state->last_flush;
  state->strm = strm;
  state->last_flush = flush;
  if ( status == 42 )
  {
    if ( state->wrap == 2 )
    {
      strm->adler = crc32(crc: 0, buf: nullptr, len: 0);
      state->pending_buf[state->pending] = 31;
      pending_buf = state->pending_buf;
      v9 = state->pending + 1;
      state->pending = v9;
      pending_buf[v9] = -117;
      v10 = state->pending_buf;
      v11 = state->pending + 1;
      state->pending = v11;
      v10[v11] = 8;
      gzhead = state->gzhead;
      v13 = state->pending + 1;
      state->pending = v13;
      if ( gzhead != nullptr )
      {
        state->pending_buf[v13] = (gzhead->comment == nullptr ? 0 : 0x10)
                                + (gzhead->hcrc == 0 ? 0 : 2)
                                + (gzhead->name == nullptr ? 0 : 8)
                                + (gzhead->extra == nullptr ? 0 : 4)
                                + gzhead->text
                                - (HIBYTE(gzhead->text)
                                 - 1
                                 + (gzhead->text == 0));
        v29 = state->gzhead;
        v30 = state->pending_buf;
        v31 = state->pending + 1;
        state->pending = v31;
        v30[v31] = v29->time;
        v32 = state->gzhead;
        v33 = state->pending_buf;
        v34 = state->pending + 1;
        state->pending = v34;
        v33[v34] = BYTE2(v32->time);
        v35 = state->gzhead;
        v36 = state->pending_buf;
        v37 = state->pending + 1;
        state->pending = v37;
        v36[v37] = BYTE1(v35->time);
        v38 = state->gzhead;
        v39 = state->pending_buf;
        v40 = state->pending + 1;
        state->pending = v40;
        v39[v40] = HIBYTE(v38->time);
        level = state->level;
        v42 = state->pending + 1;
        state->pending = v42;
        if ( level == 9 )
        {
          v43 = 2;
        }
        else if ( state->strategy >= 2 || (v25 = level >= 2, v43 = 0, !v25) )
        {
          v43 = 4;
        }
        state->pending_buf[v42] = v43;
        v44 = state->pending_buf;
        v45 = state->gzhead;
        v46 = state->pending + 1;
        state->pending = v46;
        v44[v46] = v45->os;
        v47 = state->gzhead;
        v48 = state->pending + 1;
        state->pending = v48;
        if ( v47->extra != nullptr )
        {
          state->pending_buf[v48] = v47->extra_len;
          v49 = state->pending_buf;
          v50 = state->gzhead;
          v51 = state->pending + 1;
          state->pending = v51;
          v49[v51] = BYTE2(v50->extra_len);
          v48 = state->pending + 1;
          state->pending = v48;
        }
        if ( state->gzhead->hcrc != 0 )
          strm->adler = crc32(crc: strm->adler, buf: state->pending_buf, len: v48);
        state->gzindex = 0;
        state->status = 69;
      }
      else
      {
        state->pending_buf[v13] = 0;
        v14 = state->pending_buf;
        v15 = state->pending + 1;
        state->pending = v15;
        v14[v15] = 0;
        v16 = state->pending_buf;
        v17 = state->pending + 1;
        state->pending = v17;
        v16[v17] = 0;
        v18 = state->pending_buf;
        v19 = state->pending + 1;
        state->pending = v19;
        v18[v19] = 0;
        v20 = state->pending_buf;
        v21 = state->pending + 1;
        state->pending = v21;
        v20[v21] = 0;
        v22 = state->level;
        v23 = state->pending + 1;
        state->pending = v23;
        if ( v22 == 9 )
        {
          v24 = 2;
        }
        else if ( state->strategy >= 2 || (v25 = v22 >= 2, v24 = 0, !v25) )
        {
          v24 = 4;
        }
        state->pending_buf[v23] = v24;
        v26 = state->pending_buf;
        v27 = state->pending + 1;
        state->pending = v27;
        v26[v27] = 11;
        pending = state->pending;
        state->status = 113;
        state->pending = pending + 1;
      }
    }
    else
    {
      if ( state->strategy >= 2 || (v52 = state->level) < 2 )
      {
        v53 = 0;
      }
      else if ( v52 >= 6 )
      {
        v53 = ((_cntlzw(v52 - 6) & 0x20) == 0) + 2;
      }
      else
      {
        v53 = 1;
      }
      v54 = (v53 << 6) | (((state->w_bits - 8) << 12) + 2048);
      if ( state->strstart != 0 )
        v54 |= 0x20u;
      v55 = state->pending;
      v56 = state->pending_buf;
      state->status = 113;
      v57 = v54 - v54 % 0x1F + 31;
      v58 = v57;
      v56[v55] = BYTE2(v57);
      v59 = state->pending_buf;
      v60 = state->pending + 1;
      state->pending = v60;
      v59[v60] = v58;
      strstart = state->strstart;
      v62 = state->pending + 1;
      state->pending = v62;
      if ( strstart != 0 )
      {
        adler_high = HIWORD(strm->adler);
        state->pending_buf[v62] = HIBYTE(adler_high);
        v64 = state->pending + 1;
        v65 = state->pending_buf;
        state->pending = v64;
        v65[v64] = adler_high;
        v66 = state->pending + 1;
        v67 = state->pending_buf;
        state->pending = v66;
        adler = strm->adler;
        v67[v66] = HIBYTE(adler);
        v69 = state->pending_buf;
        v70 = state->pending + 1;
        state->pending = v70;
        v69[v70] = adler;
        ++state->pending;
      }
      strm->adler = adler32(adler: 0, buf: nullptr, len: 0);
    }
  }
  if ( state->status == 69 )
  {
    v71 = state->gzhead;
    if ( v71->extra == nullptr )
    {
LABEL_55:
      state->status = 73;
      goto LABEL_56;
    }
    v72 = state->pending;
    if ( state->gzindex < LOWORD(v71->extra_len) )
    {
      do
      {
        v73 = state->pending;
        if ( v73 == state->pending_buf_size )
        {
          if ( state->gzhead->hcrc != 0 && v73 > v72 )
            strm->adler = crc32(crc: strm->adler, buf: &state->pending_buf[v72], len: v73 - v72);
          flush_pending(strm);
          v73 = state->pending;
          v72 = v73;
          if ( v73 == state->pending_buf_size )
            break;
        }
        state->pending_buf[v73] = state->gzhead->extra[state->gzindex];
        v74 = state->gzindex + 1;
        v75 = state->pending + 1;
        state->gzindex = v74;
        state->pending = v75;
      }
      while ( v74 < LOWORD(state->gzhead->extra_len) );
    }
    if ( state->gzhead->hcrc != 0 )
    {
      v76 = state->pending;
      if ( v76 > v72 )
        strm->adler = crc32(crc: strm->adler, buf: &state->pending_buf[v72], len: v76 - v72);
    }
    if ( state->gzindex == state->gzhead->extra_len )
    {
      state->gzindex = 0;
      goto LABEL_55;
    }
  }
LABEL_56:
  if ( state->status == 73 )
  {
    if ( state->gzhead->name == nullptr )
    {
LABEL_72:
      state->status = 91;
      goto LABEL_73;
    }
    v77 = state->pending;
    while ( 1 )
    {
      v78 = state->pending;
      if ( v78 == state->pending_buf_size )
      {
        if ( state->gzhead->hcrc != 0 && v78 > v77 )
          strm->adler = crc32(crc: strm->adler, buf: &state->pending_buf[v77], len: v78 - v77);
        flush_pending(strm);
        v78 = state->pending;
        v77 = v78;
        if ( v78 == state->pending_buf_size )
          break;
      }
      gzindex = state->gzindex;
      v80 = state->pending_buf;
      v81 = state->gzhead->name[gzindex];
      state->gzindex = gzindex + 1;
      v80[v78] = v81;
      ++state->pending;
      if ( v81 == 0 )
        goto LABEL_67;
    }
    v81 = 1;
LABEL_67:
    if ( state->gzhead->hcrc != 0 )
    {
      v82 = state->pending;
      if ( v82 > v77 )
        strm->adler = crc32(crc: strm->adler, buf: &state->pending_buf[v77], len: v82 - v77);
    }
    if ( v81 == 0 )
    {
      state->gzindex = 0;
      goto LABEL_72;
    }
  }
LABEL_73:
  if ( state->status == 91 )
  {
    if ( state->gzhead->comment == nullptr )
      goto LABEL_88;
    v83 = state->pending;
    while ( 1 )
    {
      v84 = state->pending;
      if ( v84 == state->pending_buf_size )
      {
        if ( state->gzhead->hcrc != 0 && v84 > v83 )
          strm->adler = crc32(crc: strm->adler, buf: &state->pending_buf[v83], len: v84 - v83);
        flush_pending(strm);
        v84 = state->pending;
        v83 = v84;
        if ( v84 == state->pending_buf_size )
          break;
      }
      v85 = state->gzindex;
      v86 = state->pending_buf;
      v87 = state->gzhead->comment[v85];
      state->gzindex = v85 + 1;
      v86[v84] = v87;
      ++state->pending;
      if ( v87 == 0 )
        goto LABEL_84;
    }
    v87 = 1;
LABEL_84:
    if ( state->gzhead->hcrc != 0 )
    {
      v88 = state->pending;
      if ( v88 > v83 )
        strm->adler = crc32(crc: strm->adler, buf: &state->pending_buf[v83], len: v88 - v83);
    }
    if ( v87 == 0 )
LABEL_88:
      state->status = 103;
  }
  if ( state->status == 103 )
  {
    if ( state->gzhead->hcrc == 0 )
    {
LABEL_95:
      state->status = 113;
      goto LABEL_96;
    }
    if ( state->pending + 2 > state->pending_buf_size )
      flush_pending(strm);
    v89 = state->pending;
    if ( v89 + 2 <= state->pending_buf_size )
    {
      state->pending_buf[v89] = strm->adler;
      v90 = state->pending + 1;
      state->pending = v90;
      state->pending_buf[v90] = BYTE2(strm->adler);
      ++state->pending;
      strm->adler = crc32(crc: 0, buf: nullptr, len: 0);
      goto LABEL_95;
    }
  }
LABEL_96:
  if ( state->pending != 0 )
  {
    flush_pending(strm);
    if ( strm->avail_out == 0 )
    {
LABEL_98:
      state->last_flush = -1;
      return 0;
    }
  }
  else if ( strm->avail_in == 0 && (int)flush <= last_flush && flush != 4 )
  {
    goto LABEL_10;
  }
  v91 = state->status;
  if ( v91 == 666 && strm->avail_in != 0 )
    goto LABEL_10;
  if ( strm->avail_in != 0 || state->lookahead != 0 || flush != 0 && v91 != 666 )
  {
    v92 = configuration_table[state->level].func(a1: state, a2: flush);
    if ( v92 == finish_started || v92 == finish_done )
      state->status = 666;
    if ( v92 == need_more || v92 == finish_started )
    {
      if ( strm->avail_out == 0 )
        state->last_flush = -1;
      return 0;
    }
    if ( v92 == block_done )
    {
      if ( flush == 1 )
      {
        tr_align(s: state);
      }
      else
      {
        tr_stored_block(s: state, buf: nullptr, stored_len: 0, eof: 0);
        if ( flush == 3 )
        {
          state->head[state->hash_size - 1] = 0;
          memset(Dst: state->head, Val: 0, Size: 2 * (state->hash_size - 1));
        }
      }
      flush_pending(strm);
      if ( strm->avail_out == 0 )
        goto LABEL_98;
    }
  }
  if ( flush != 4 )
    return 0;
  wrap = state->wrap;
  if ( wrap <= 0 )
    return 1;
  v94 = state->pending;
  v95 = state->pending_buf;
  if ( wrap == 2 )
  {
    v95[v94] = strm->adler;
    v96 = state->pending_buf;
    v97 = state->pending + 1;
    state->pending = v97;
    v96[v97] = BYTE2(strm->adler);
    v98 = state->pending + 1;
    v99 = state->pending_buf;
    state->pending = v98;
    v99[v98] = BYTE1(strm->adler);
    v100 = state->pending_buf;
    v101 = state->pending + 1;
    state->pending = v101;
    v100[v101] = HIBYTE(strm->adler);
    v102 = state->pending + 1;
    state->pending = v102;
    state->pending_buf[v102] = strm->total_in;
    v103 = state->pending_buf;
    v104 = state->pending + 1;
    state->pending = v104;
    v103[v104] = BYTE2(strm->total_in);
    v105 = state->pending_buf;
    v106 = state->pending + 1;
    state->pending = v106;
    v105[v106] = BYTE1(strm->total_in);
    v107 = state->pending_buf;
    v108 = state->pending + 1;
    state->pending = v108;
    v107[v108] = HIBYTE(strm->total_in);
  }
  else
  {
    v109 = HIWORD(strm->adler);
    v95[v94] = HIBYTE(v109);
    v110 = state->pending_buf;
    v111 = state->pending + 1;
    state->pending = v111;
    v110[v111] = v109;
    v112 = state->pending_buf;
    v113 = state->pending + 1;
    state->pending = v113;
    v114 = strm->adler;
    v112[v113] = HIBYTE(v114);
    v115 = state->pending_buf;
    v116 = state->pending + 1;
    state->pending = v116;
    v115[v116] = v114;
  }
  ++state->pending;
  flush_pending(strm);
  v117 = state->wrap;
  if ( v117 > 0 )
    state->wrap = -v117;
  return (_cntlzw(state->pending) & 0x20) != 0;
}


// ========================================================================
// deflateEnd
// EA  : 0x8321F480
// RVA : 0x0121F480
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

unsigned int __fastcall deflateEnd(z_stream_s *strm)
{
  internal_state *state; // r11
  int status; // r30

  if ( strm == nullptr )
    return -2;
  state = strm->state;
  if ( state == nullptr )
    return -2;
  status = state->status;
  if ( status != 42 && status != 69 && status != 73 && status != 91 && status != 103 && status != 113 && status != 666 )
    return -2;
  if ( state->pending_buf != nullptr )
    ((void (__fastcall *)(void *))strm->zfree)(a1: strm->opaque);
  if ( strm->state->head != nullptr )
    ((void (__fastcall *)(void *))strm->zfree)(a1: strm->opaque);
  if ( strm->state->prev != nullptr )
    ((void (__fastcall *)(void *))strm->zfree)(a1: strm->opaque);
  if ( strm->state->window != nullptr )
    ((void (__fastcall *)(void *))strm->zfree)(a1: strm->opaque);
  strm->zfree(a1: strm->opaque, a2: strm->state);
  strm->state = nullptr;
  return status != 113 ? 0 : 0xFFFFFFFD;
}


// ========================================================================
// longest_match
// EA  : 0x8321F5B8
// RVA : 0x0121F5B8
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

unsigned int __fastcall longest_match(internal_state *s, unsigned int cur_match)
{
  unsigned int w_size; // r8
  unsigned int strstart; // r11
  unsigned __int8 *window; // r30
  unsigned int max_chain_length; // r25
  unsigned __int8 *v7; // r9
  unsigned int nice_match; // r27
  unsigned int prev_length; // r6
  unsigned int v10; // r26
  unsigned __int16 *prev; // r29
  unsigned __int8 *v12; // r5
  unsigned int w_mask; // r28
  unsigned __int8 v14; // r8
  unsigned __int8 v15; // r31
  unsigned int result; // r3
  unsigned __int8 *v17; // r10
  unsigned __int8 *v18; // r10
  unsigned __int8 *v19; // r11
  unsigned __int8 *v20; // r10
  unsigned __int8 *v21; // r10
  unsigned __int8 *v22; // r10
  unsigned __int8 *v23; // r10
  unsigned __int8 *v24; // r10
  unsigned __int8 *v25; // r10
  unsigned __int8 *v26; // r10
  unsigned __int8 *v27; // r10
  int v28; // r11

  w_size = s->w_size;
  strstart = s->strstart;
  window = s->window;
  max_chain_length = s->max_chain_length;
  v7 = &window[strstart];
  nice_match = s->nice_match;
  prev_length = s->prev_length;
  if ( strstart <= w_size - 262 )
    v10 = 0;
  else
    v10 = strstart - w_size + 262;
  prev = s->prev;
  v12 = v7 + 258;
  w_mask = s->w_mask;
  v15 = v7[prev_length - 1];
  v14 = v7[prev_length];
  if ( s->prev_length >= s->good_match )
    max_chain_length >>= 2;
  result = s->lookahead;
  if ( nice_match > result )
    nice_match = s->lookahead;
  do
  {
    v17 = &window[cur_match];
    if ( window[cur_match + prev_length] == v14 && window[cur_match - 1 + prev_length] == v15 && *v17 == *v7 )
    {
      v18 = v17 + 1;
      if ( *v18 == v7[1] )
      {
        v19 = v7 + 2;
        v20 = v18 + 1;
        do
        {
          v21 = v20 + 1;
          if ( *++v19 != *v21 )
            break;
          v22 = v21 + 1;
          if ( *++v19 != *v22 )
            break;
          v23 = v22 + 1;
          if ( *++v19 != *v23 )
            break;
          v24 = v23 + 1;
          if ( *++v19 != *v24 )
            break;
          v25 = v24 + 1;
          if ( *++v19 != *v25 )
            break;
          v26 = v25 + 1;
          if ( *++v19 != *v26 )
            break;
          v27 = v26 + 1;
          if ( *++v19 != *v27 )
            break;
          v20 = v27 + 1;
          if ( *++v19 != *v20 )
            break;
        }
        while ( v19 < v12 );
        v7 = v12 - 258;
        v28 = v19 - v12 + 258;
        if ( v28 > (int)prev_length )
        {
          s->match_start = cur_match;
          prev_length = v28;
          if ( v28 >= (int)nice_match )
            break;
          v14 = v7[v28];
          v15 = v7[v28 - 1];
        }
      }
    }
    cur_match = prev[w_mask & cur_match];
    if ( cur_match <= v10 )
      break;
    --max_chain_length;
  }
  while ( max_chain_length != 0 );
  if ( prev_length <= result )
    return prev_length;
  return result;
}


// ========================================================================
// longest_match_fast
// EA  : 0x8321F770
// RVA : 0x0121F770
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

unsigned int __fastcall longest_match_fast(internal_state *s, unsigned int cur_match)
{
  unsigned __int8 *window; // r11
  unsigned __int8 *v3; // r10
  unsigned __int8 *v4; // r11
  unsigned __int8 *v5; // r8
  unsigned __int8 *v6; // r11
  unsigned __int8 *v7; // r10
  unsigned __int8 *v8; // r10
  unsigned __int8 *v9; // r10
  unsigned __int8 *v10; // r10
  unsigned __int8 *v11; // r10
  unsigned __int8 *v12; // r10
  unsigned __int8 *v13; // r10
  unsigned __int8 *v14; // r10
  int v15; // r11
  unsigned int lookahead; // r10

  window = s->window;
  v3 = &window[cur_match];
  v4 = &window[s->strstart];
  v5 = v4 + 258;
  if ( *v3 != *v4 || v3[1] != v4[1] )
    return 2;
  v6 = v4 + 2;
  v7 = v3 + 2;
  do
  {
    v8 = v7 + 1;
    if ( *++v6 != *v8 )
      break;
    v9 = v8 + 1;
    if ( *++v6 != *v9 )
      break;
    v10 = v9 + 1;
    if ( *++v6 != *v10 )
      break;
    v11 = v10 + 1;
    if ( *++v6 != *v11 )
      break;
    v12 = v11 + 1;
    if ( *++v6 != *v12 )
      break;
    v13 = v12 + 1;
    if ( *++v6 != *v13 )
      break;
    v14 = v13 + 1;
    if ( *++v6 != *v14 )
      break;
    v7 = v14 + 1;
    if ( *++v6 != *v7 )
      break;
  }
  while ( v6 < v5 );
  v15 = v6 - v5 + 258;
  if ( v15 < 3 )
    return 2;
  lookahead = s->lookahead;
  s->match_start = cur_match;
  if ( v15 > lookahead )
    return lookahead;
  return v15;
}


// ========================================================================
// fill_window
// EA  : 0x8321F868
// RVA : 0x0121F868
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

void __fastcall fill_window(internal_state *s)
{
  size_t w_size; // r28
  unsigned int strstart; // r8
  unsigned int v4; // r26
  unsigned int hash_size; // r9
  unsigned __int16 *v6; // r10
  int v7; // r4
  size_t v8; // r11
  unsigned __int16 v9; // r11
  bool v10; // zf
  size_t v11; // r9
  unsigned __int16 *v12; // r10
  size_t v13; // r11
  unsigned __int16 v14; // r11
  z_stream_s *strm; // r30
  unsigned int avail_in; // r11
  unsigned __int8 *v17; // r27
  unsigned int v18; // r29
  unsigned int v19; // r11
  internal_state *state; // r10
  int wrap; // r11
  unsigned int v22; // r3
  unsigned int v23; // r8
  unsigned int v24; // r10
  unsigned int hash_shift; // r8
  unsigned __int8 *v26; // r11
  unsigned int hash_mask; // r7
  unsigned int v28; // r6

  w_size = s->w_size;
  do
  {
    strstart = s->strstart;
    v4 = s->window_size - s->lookahead - strstart;
    if ( strstart >= w_size + s->w_size - 262 )
    {
      memcpy(Dst: s->window, Src: &s->window[w_size], Size: w_size);
      hash_size = s->hash_size;
      v6 = &s->head[hash_size];
      v7 = s->block_start - w_size;
      s->strstart -= w_size;
      s->block_start = v7;
      s->match_start -= w_size;
      do
      {
        v8 = *--v6;
        v10 = v8 >= w_size;
        v9 = v8 - w_size;
        if ( !v10 )
          v9 = 0;
        --hash_size;
        *v6 = v9;
      }
      while ( hash_size != 0 );
      v11 = w_size;
      v12 = &s->prev[w_size];
      do
      {
        v13 = *--v12;
        v10 = v13 >= w_size;
        v14 = v13 - w_size;
        if ( !v10 )
          v14 = 0;
        --v11;
        *v12 = v14;
      }
      while ( v11 != 0 );
      v4 += w_size;
    }
    strm = s->strm;
    if ( s->strm->avail_in == 0 )
      break;
    avail_in = strm->avail_in;
    v17 = &s->window[s->lookahead + s->strstart];
    v18 = avail_in;
    if ( avail_in > v4 )
      v18 = v4;
    if ( v18 != 0 )
    {
      state = strm->state;
      strm->avail_in = avail_in - v18;
      wrap = state->wrap;
      if ( wrap == 1 )
      {
        v22 = adler32(adler: strm->adler, buf: strm->next_in, len: v18);
        goto LABEL_21;
      }
      if ( wrap == 2 )
      {
        v22 = crc32(crc: strm->adler, buf: strm->next_in, len: v18);
LABEL_21:
        strm->adler = v22;
      }
      memcpy(Dst: v17, Src: strm->next_in, Size: v18);
      v19 = v18;
      v23 = v18 + strm->total_in;
      strm->next_in += v18;
      strm->total_in = v23;
      goto LABEL_23;
    }
    v19 = 0;
LABEL_23:
    v24 = s->lookahead + v19;
    s->lookahead = v24;
    if ( v24 >= 3 )
    {
      hash_shift = s->hash_shift;
      v26 = &s->window[s->strstart];
      hash_mask = s->hash_mask;
      v28 = *v26;
      s->ins_h = v28;
      s->ins_h = ((v28 << hash_shift) ^ v26[1]) & hash_mask;
    }
  }
  while ( v24 < 0x106 && s->strm->avail_in != 0 );
}


// ========================================================================
// deflate_stored
// EA  : 0x8321FA68
// RVA : 0x0121FA68
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

block_state __fastcall deflate_stored(internal_state *s, int flush)
{
  unsigned int v4; // r30
  unsigned int lookahead; // r10
  int block_start; // r11
  unsigned int v7; // r10
  unsigned int v8; // r9
  char *v9; // r4
  z_stream_s *v10; // r3
  int v11; // r11
  unsigned int v12; // r5
  char *v13; // r4
  z_stream_s *strm; // r3
  block_state result; // r3
  int v16; // r11
  char *v17; // r4
  z_stream_s *v18; // r3

  v4 = 0xFFFF;
  if ( s->pending_buf_size - 5 < 0xFFFF )
    v4 = s->pending_buf_size - 5;
  while ( 1 )
  {
    lookahead = s->lookahead;
    if ( lookahead <= 1 )
    {
      fill_window(s);
      lookahead = s->lookahead;
      if ( lookahead == 0 )
        break;
    }
    block_start = s->block_start;
    v7 = lookahead + s->strstart;
    s->lookahead = 0;
    v8 = block_start + v4;
    s->strstart = v7;
    if ( v7 != 0 && v7 < v8
      || ((s->strstart = v8, s->lookahead = v7 - v8, block_start < 0)
        ? (v9 = nullptr)
        : (v9 = (char *)&s->window[block_start]),
          tr_flush_block(s, buf: v9, stored_len: v4, eof: 0),
          v10 = s->strm,
          s->block_start = s->strstart,
          flush_pending(strm: v10),
          s->strm->avail_out != 0) )
    {
      v11 = s->block_start;
      v12 = s->strstart - v11;
      if ( v12 < s->w_size - 262 )
        continue;
      v13 = v11 < 0 ? nullptr : (char *)&s->window[v11];
      tr_flush_block(s, buf: v13, stored_len: v12, eof: 0);
      strm = s->strm;
      s->block_start = s->strstart;
      flush_pending(strm);
      if ( s->strm->avail_out != 0 )
        continue;
    }
    return need_more;
  }
  if ( flush == 0 )
    return need_more;
  v16 = s->block_start;
  if ( v16 < 0 )
    v17 = nullptr;
  else
    v17 = (char *)&s->window[v16];
  tr_flush_block(s, buf: v17, stored_len: s->strstart - v16, eof: (_cntlzw(flush - 4) & 0x20) != 0);
  v18 = s->strm;
  s->block_start = s->strstart;
  flush_pending(strm: v18);
  if ( s->strm->avail_out == 0 )
    return flush != 4 ? 0 : 2;
  result = finish_done;
  if ( flush != 4 )
    return block_done;
  return result;
}


// ========================================================================
// deflate_fast
// EA  : 0x8321FC40
// RVA : 0x0121FC40
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

block_state __fastcall deflate_fast(internal_state *s, int flush)
{
  int v4; // r30
  unsigned int lookahead; // r11
  unsigned int strstart; // r11
  unsigned __int16 *head; // r10
  unsigned __int16 *prev; // r8
  unsigned int v9; // r7
  unsigned int v10; // r6
  unsigned int v11; // r8
  unsigned int v12; // r10
  int strategy; // r11
  unsigned int matched; // r3
  unsigned int match_length; // r11
  int v16; // r4
  unsigned __int16 v17; // r11
  unsigned int v18; // r9
  int v19; // r11
  unsigned int max_lazy_match; // r6
  unsigned int v21; // r11
  unsigned int v22; // r10
  char v23; // r3
  BOOL v24; // r9
  unsigned __int8 *v25; // r10
  unsigned int v26; // r11
  unsigned int ins_h; // r8
  unsigned int v28; // r7
  unsigned __int16 *v29; // r10
  unsigned int v30; // r3
  unsigned __int16 *v31; // r7
  int v32; // r6
  int v33; // r11
  unsigned int v34; // r8
  unsigned int v35; // r11
  unsigned int hash_shift; // r8
  unsigned int v37; // r7
  unsigned __int8 *window; // r10
  unsigned int hash_mask; // r6
  unsigned int v40; // r4
  int v41; // r6
  unsigned int v42; // r4
  char v43; // r11
  int block_start; // r11
  char *v45; // r4
  z_stream_s *strm; // r3
  block_state result; // r3
  int v48; // r11
  char *v49; // r4
  z_stream_s *v50; // r3

  v4 = 0;
  while ( 1 )
  {
    lookahead = s->lookahead;
    if ( lookahead < 0x106 )
    {
      fill_window(s);
      lookahead = s->lookahead;
      if ( lookahead < 0x106 && flush == 0 )
        return need_more;
      if ( lookahead == 0 )
        break;
    }
    if ( lookahead >= 3 )
    {
      strstart = s->strstart;
      head = s->head;
      prev = s->prev;
      v9 = s->w_mask & strstart;
      v10 = ((s->ins_h << s->hash_shift) ^ s->window[strstart + 2]) & s->hash_mask;
      s->ins_h = v10;
      prev[v9] = head[v10];
      v11 = s->strstart;
      v4 = s->prev[s->w_mask & v11];
      s->head[s->ins_h] = v11;
    }
    if ( v4 != 0 )
    {
      v12 = s->strstart - v4;
      if ( v12 > s->w_size - 262 )
        goto LABEL_17;
      strategy = s->strategy;
      if ( strategy == 2 )
        goto LABEL_17;
      if ( strategy != 3 )
      {
        matched = longest_match(s, cur_match: v4);
LABEL_16:
        s->match_length = matched;
        goto LABEL_17;
      }
      if ( v12 == 1 )
      {
        matched = longest_match_fast(s, cur_match: v4);
        goto LABEL_16;
      }
    }
LABEL_17:
    match_length = s->match_length;
    if ( match_length < 3 )
    {
      v41 = s->window[s->strstart];
      s->d_buf[s->last_lit] = 0;
      s->l_buf[s->last_lit++] = v41;
      ++s->dyn_ltree[v41].fc.freq;
      v42 = s->lookahead - 1;
      v43 = _cntlzw(s->lit_bufsize - 1 - s->last_lit);
      ++s->strstart;
      s->lookahead = v42;
      v24 = (v43 & 0x20) != 0;
    }
    else
    {
      v16 = (unsigned __int8)(match_length - 3);
      v17 = HIWORD(s->strstart) - HIWORD(s->match_start);
      s->d_buf[s->last_lit] = v17;
      s->l_buf[s->last_lit] = v16;
      v18 = (unsigned __int16)(v17 - 1);
      ++s->last_lit;
      ++s->dyn_ltree[length_code[v16] + 257].fc.freq;
      if ( v18 >= 0x100 )
        v19 = dist_code[(v18 >> 7) + 256];
      else
        v19 = dist_code[v18];
      ++s->dyn_dtree[v19].fc.freq;
      max_lazy_match = s->max_lazy_match;
      v21 = s->match_length;
      v22 = s->lookahead - v21;
      v23 = _cntlzw(s->lit_bufsize - 1 - s->last_lit);
      s->lookahead = v22;
      v24 = (v23 & 0x20) != 0;
      if ( v21 > max_lazy_match || v22 < 3 )
      {
        s->match_length = 0;
        hash_shift = s->hash_shift;
        v37 = s->strstart + v21;
        window = s->window;
        hash_mask = s->hash_mask;
        s->strstart = v37;
        v40 = window[v37];
        s->ins_h = v40;
        s->ins_h = ((v40 << hash_shift) ^ window[v37 + 1]) & hash_mask;
      }
      else
      {
        s->match_length = v21 - 1;
        do
        {
          v25 = s->window;
          v26 = s->strstart + 1;
          ins_h = s->ins_h;
          v28 = s->hash_shift;
          s->strstart = v26;
          v30 = s->w_mask & v26;
          v32 = v25[v26 + 2];
          v29 = s->head;
          v33 = v32 ^ (ins_h << v28);
          v31 = s->prev;
          v34 = v33 & s->hash_mask;
          s->ins_h = v34;
          v31[v30] = v29[v34];
          v4 = s->prev[s->w_mask & s->strstart];
          s->head[s->ins_h] = s->strstart;
          v35 = s->match_length - 1;
          s->match_length = v35;
        }
        while ( v35 != 0 );
        ++s->strstart;
      }
    }
    if ( v24 )
    {
      block_start = s->block_start;
      v45 = block_start < 0 ? nullptr : (char *)&s->window[block_start];
      tr_flush_block(s, buf: v45, stored_len: s->strstart - block_start, eof: 0);
      strm = s->strm;
      s->block_start = s->strstart;
      flush_pending(strm);
      if ( s->strm->avail_out == 0 )
        return need_more;
    }
  }
  v48 = s->block_start;
  if ( v48 < 0 )
    v49 = nullptr;
  else
    v49 = (char *)&s->window[v48];
  tr_flush_block(s, buf: v49, stored_len: s->strstart - v48, eof: (_cntlzw(flush - 4) & 0x20) != 0);
  v50 = s->strm;
  s->block_start = s->strstart;
  flush_pending(strm: v50);
  if ( s->strm->avail_out == 0 )
    return flush != 4 ? 0 : 2;
  result = finish_done;
  if ( flush != 4 )
    return block_done;
  return result;
}


// ========================================================================
// deflate_slow
// EA  : 0x832200C0
// RVA : 0x012200C0
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

block_state __fastcall deflate_slow(internal_state *s, int flush)
{
  int v4; // r29
  unsigned int lookahead; // r11
  unsigned int strstart; // r11
  unsigned __int16 *head; // r10
  unsigned __int16 *prev; // r8
  unsigned int v9; // r7
  unsigned int v10; // r6
  unsigned int v11; // r8
  unsigned int match_length; // r11
  unsigned int match_start; // r10
  unsigned int v14; // r10
  int strategy; // r11
  unsigned int matched; // r3
  unsigned int v17; // r11
  unsigned int prev_length; // r11
  unsigned int v19; // r11
  int v20; // r7
  unsigned __int16 v21; // r10
  unsigned int v22; // r8
  unsigned int v23; // r9
  int v24; // r11
  int v25; // r11
  unsigned int v26; // r11
  char v27; // r10
  BOOL v28; // r9
  unsigned int v29; // r11
  unsigned int v30; // r6
  unsigned __int16 *v31; // r5
  unsigned int v32; // r3
  unsigned __int16 *v33; // r11
  unsigned int v34; // r7
  unsigned int v35; // r10
  unsigned int v36; // r11
  unsigned int v37; // r11
  unsigned int v38; // r10
  int v39; // r11
  char *v40; // r4
  z_stream_s *v41; // r3
  bool v42; // cr58
  block_state result; // r3
  int v44; // r5
  int block_start; // r11
  char *v46; // r4
  z_stream_s *strm; // r3
  z_stream_s *v48; // r9
  unsigned int v49; // r7
  unsigned int v50; // r11
  unsigned int v51; // r9
  int v52; // r5
  int v53; // r11
  char *v54; // r4
  z_stream_s *v55; // r3

  v4 = 0;
  while ( 1 )
  {
    lookahead = s->lookahead;
    if ( lookahead < 0x106 )
    {
      fill_window(s);
      lookahead = s->lookahead;
      if ( lookahead < 0x106 && flush == 0 )
        return need_more;
      if ( lookahead == 0 )
        break;
    }
    if ( lookahead >= 3 )
    {
      strstart = s->strstart;
      head = s->head;
      prev = s->prev;
      v9 = s->w_mask & strstart;
      v10 = ((s->ins_h << s->hash_shift) ^ s->window[strstart + 2]) & s->hash_mask;
      s->ins_h = v10;
      prev[v9] = head[v10];
      v11 = s->strstart;
      v4 = s->prev[s->w_mask & v11];
      s->head[s->ins_h] = v11;
    }
    match_length = s->match_length;
    match_start = s->match_start;
    s->match_length = 2;
    s->prev_length = match_length;
    s->prev_match = match_start;
    if ( v4 == 0 )
      goto LABEL_23;
    if ( match_length >= s->max_lazy_match )
      goto LABEL_23;
    v14 = s->strstart - v4;
    if ( v14 <= s->w_size - 262 )
    {
      strategy = s->strategy;
      if ( strategy != 2 )
      {
        if ( strategy != 3 )
        {
          matched = longest_match(s, cur_match: v4);
LABEL_17:
          s->match_length = matched;
          goto LABEL_18;
        }
        if ( v14 == 1 )
        {
          matched = longest_match_fast(s, cur_match: v4);
          goto LABEL_17;
        }
      }
LABEL_18:
      v17 = s->match_length;
      if ( v17 <= 5 && (s->strategy == 1 || v17 == 3 && s->strstart - s->match_start > 0x1000) )
        s->match_length = 2;
    }
LABEL_23:
    prev_length = s->prev_length;
    if ( prev_length < 3 || s->match_length > prev_length )
    {
      if ( s->match_available != 0 )
      {
        v44 = s->window[s->strstart - 1];
        s->d_buf[s->last_lit] = 0;
        s->l_buf[s->last_lit++] = v44;
        ++s->dyn_ltree[v44].fc.freq;
        if ( s->last_lit == s->lit_bufsize - 1 )
        {
          block_start = s->block_start;
          if ( block_start < 0 )
            v46 = nullptr;
          else
            v46 = (char *)&s->window[block_start];
          tr_flush_block(s, buf: v46, stored_len: s->strstart - block_start, eof: 0);
          strm = s->strm;
          s->block_start = s->strstart;
          flush_pending(strm);
        }
        v48 = s->strm;
        v49 = s->lookahead - 1;
        ++s->strstart;
        s->lookahead = v49;
        v42 = v48->avail_out == 0;
        goto LABEL_37;
      }
      v50 = s->lookahead;
      s->match_available = 1;
      v51 = s->strstart + 1;
      s->lookahead = v50 - 1;
      s->strstart = v51;
    }
    else
    {
      v20 = (unsigned __int8)(prev_length - 3);
      v19 = s->strstart;
      v21 = v19 - s->prev_match - 1;
      v22 = v19 + s->lookahead - 3;
      s->d_buf[s->last_lit] = v21;
      s->l_buf[s->last_lit++] = v20;
      v23 = (unsigned __int16)(v21 - 1);
      v24 = 4 * (length_code[v20] + 294);
      ++*(_WORD *)((char *)&s->strm + v24);
      if ( v23 >= 0x100 )
        v25 = dist_code[(v23 >> 7) + 256];
      else
        v25 = dist_code[v23];
      ++s->dyn_dtree[v25].fc.freq;
      v26 = s->prev_length;
      v27 = _cntlzw(s->lit_bufsize - 1 - s->last_lit);
      s->lookahead = s->lookahead - v26 + 1;
      v28 = (v27 & 0x20) != 0;
      s->prev_length = v26 - 2;
      do
      {
        v29 = s->strstart + 1;
        s->strstart = v29;
        if ( v29 <= v22 )
        {
          v30 = v29 & s->w_mask;
          v31 = s->head;
          v32 = (s->ins_h << s->hash_shift) ^ s->window[v29 + 2];
          v33 = s->prev;
          v34 = v32 & s->hash_mask;
          s->ins_h = v34;
          v33[v30] = v31[v34];
          v35 = s->strstart;
          v4 = s->prev[s->w_mask & v35];
          s->head[s->ins_h] = v35;
        }
        v36 = s->prev_length - 1;
        s->prev_length = v36;
      }
      while ( v36 != 0 );
      v37 = s->strstart;
      s->match_available = 0;
      v38 = v37 + 1;
      s->match_length = 2;
      s->strstart = v37 + 1;
      if ( v28 )
      {
        v39 = s->block_start;
        if ( v39 < 0 )
          v40 = nullptr;
        else
          v40 = (char *)&s->window[v39];
        tr_flush_block(s, buf: v40, stored_len: v38 - v39, eof: 0);
        v41 = s->strm;
        s->block_start = s->strstart;
        flush_pending(strm: v41);
        v42 = s->strm->avail_out == 0;
LABEL_37:
        if ( v42 )
          return need_more;
      }
    }
  }
  if ( s->match_available != 0 )
  {
    v52 = s->window[s->strstart - 1];
    s->d_buf[s->last_lit] = 0;
    s->l_buf[s->last_lit++] = v52;
    ++s->dyn_ltree[v52].fc.freq;
    s->match_available = 0;
  }
  v53 = s->block_start;
  if ( v53 < 0 )
    v54 = nullptr;
  else
    v54 = (char *)&s->window[v53];
  tr_flush_block(s, buf: v54, stored_len: s->strstart - v53, eof: (_cntlzw(flush - 4) & 0x20) != 0);
  v55 = s->strm;
  s->block_start = s->strstart;
  flush_pending(strm: v55);
  if ( s->strm->avail_out == 0 )
    return flush != 4 ? 0 : 2;
  result = finish_done;
  if ( flush != 4 )
    return block_done;
  return result;
}


// ========================================================================
// deflateReset
// EA  : 0x83220640
// RVA : 0x01220640
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

int __fastcall deflateReset(z_stream_s *strm)
{
  internal_state *state; // r31
  int wrap; // r11
  unsigned __int8 *pending_buf; // r10
  int v5; // r11
  unsigned int v6; // r3
  int v7; // r7
  int level; // r9

  if ( strm == nullptr )
    return -2;
  state = strm->state;
  if ( state == nullptr || strm->zalloc == nullptr || strm->zfree == nullptr )
    return -2;
  strm->total_out = 0;
  strm->total_in = 0;
  strm->msg = nullptr;
  strm->data_type = 2;
  wrap = state->wrap;
  pending_buf = state->pending_buf;
  state->pending = 0;
  state->pending_out = pending_buf;
  if ( wrap < 0 )
    state->wrap = -wrap;
  v5 = state->wrap;
  state->status = v5 == 0 ? 113 : 42;
  if ( v5 == 2 )
    v6 = crc32(crc: 0, buf: nullptr, len: 0);
  else
    v6 = adler32(adler: 0, buf: nullptr, len: 0);
  strm->adler = v6;
  state->last_flush = 0;
  tr_init(s: state);
  v7 = (int)&state->head[state->hash_size];
  state->window_size = 2 * state->w_size;
  *(_WORD *)(v7 - 2) = 0;
  memset(Dst: state->head, Val: 0, Size: 2 * (state->hash_size - 1));
  level = state->level;
  state->max_lazy_match = configuration_table[level].max_lazy;
  state->good_match = configuration_table[level].good_length;
  state->nice_match = configuration_table[level].nice_length;
  state->max_chain_length = configuration_table[level].max_chain;
  state->strstart = 0;
  state->block_start = 0;
  state->lookahead = 0;
  state->prev_length = 2;
  state->match_length = 2;
  state->match_available = 0;
  state->ins_h = 0;
  return 0;
}


// ========================================================================
// deflateInit2_
// EA  : 0x832207B0
// RVA : 0x012207B0
// PDB : w:\tech5\libs\zlib\deflate.c
// ========================================================================

int __fastcall deflateInit2_(
        z_stream_s *strm,
        unsigned int level,
        int method,
        int windowBits,
        int memLevel,
        unsigned int strategy,
        const char *version,
        int stream_size)
{
  unsigned int v9; // r24
  int v10; // r29
  int v13; // r26
  void *(__fastcall *zalloc)(void *, unsigned int, unsigned int); // r11
  internal_state *v16; // r3
  internal_state *v17; // r31
  int v18; // r10
  int v19; // r3
  unsigned int lit_bufsize; // r11
  unsigned __int8 *window; // r6

  v9 = level;
  v10 = windowBits;
  v13 = 1;
  if ( version == nullptr || *version != 49 || stream_size != 56 )
    return -6;
  if ( strm != nullptr )
  {
    zalloc = strm->zalloc;
    strm->msg = nullptr;
    if ( zalloc == nullptr )
    {
      strm->opaque = nullptr;
      strm->zalloc = zcalloc;
    }
    if ( strm->zfree == nullptr )
      strm->zfree = zcfree;
    if ( level == -1 )
      v9 = 6;
    if ( windowBits >= 0 )
    {
      if ( windowBits > 15 )
      {
        v13 = 2;
        v10 = windowBits - 16;
      }
    }
    else
    {
      v13 = 0;
      v10 = -windowBits;
    }
    if ( memLevel >= 1 && memLevel <= 9 && method == 8 && v10 >= 8 && v10 <= 15 && v9 <= 9 && strategy <= 4 )
    {
      if ( v10 == 8 )
        v10 = 9;
      v16 = (internal_state *)strm->zalloc(a1: strm->opaque, a2: 1, a3: 5824);
      v17 = v16;
      if ( v16 != nullptr )
      {
        strm->state = v16;
        v16->w_size = 1 << v10;
        v16->strm = strm;
        v18 = 1 << (memLevel + 7);
        v16->wrap = v13;
        v16->w_bits = v10;
        v16->hash_bits = memLevel + 7;
        v16->hash_size = v18;
        v16->w_mask = (1 << v10) - 1;
        v16->gzhead = nullptr;
        v16->hash_mask = v18 - 1;
        v16->hash_shift = (memLevel + 9) / 3u;
        v16->window = (unsigned __int8 *)((int (__fastcall *)(void *))strm->zalloc)(a1: strm->opaque);
        v17->prev = (unsigned __int16 *)strm->zalloc(a1: strm->opaque, a2: v17->w_size, a3: 2);
        v17->head = (unsigned __int16 *)strm->zalloc(a1: strm->opaque, a2: v17->hash_size, a3: 2);
        v17->lit_bufsize = 1 << (memLevel + 6);
        v19 = ((int (__fastcall *)(void *))strm->zalloc)(a1: strm->opaque);
        lit_bufsize = v17->lit_bufsize;
        window = v17->window;
        v17->pending_buf = (unsigned __int8 *)v19;
        v17->pending_buf_size = 4 * lit_bufsize;
        if ( window != nullptr && v17->prev != nullptr && v17->head != nullptr && v19 != 0 )
        {
          v17->level = v9;
          v17->strategy = strategy;
          v17->d_buf = (unsigned __int16 *)((lit_bufsize & 0xFFFFFFFE) + v19);
          v17->l_buf = (unsigned __int8 *)(3 * lit_bufsize + v19);
          v17->method = 8;
          return deflateReset(strm);
        }
        v17->status = 666;
        strm->msg = (char *)-2109691664;
        deflateEnd(strm);
      }
      return -4;
    }
  }
  return -2;
}

