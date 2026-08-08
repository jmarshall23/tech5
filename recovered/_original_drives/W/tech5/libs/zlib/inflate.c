
// ========================================================================
// inflateReset
// EA  : 0x8320F208
// RVA : 0x0120F208
// PDB : w:\tech5\libs\zlib\inflate.c
// ========================================================================

int __fastcall inflateReset(z_stream_s *strm)
{
  internal_state *state; // r11

  if ( strm == nullptr )
    return -2;
  state = strm->state;
  if ( state == nullptr )
    return -2;
  state->gzhead = nullptr;
  strm->total_out = 0;
  strm->total_in = 0;
  strm->msg = nullptr;
  strm->adler = 1;
  state->strstart = (unsigned int)&state->dyn_ltree[295];
  state->strm = nullptr;
  state->status = 0;
  state->pending_buf_size = 0;
  state->pending = 0x8000;
  state->gzindex = 0;
  state->last_flush = 0;
  state->w_size = 0;
  state->w_bits = 0;
  state->window = nullptr;
  state->window_size = 0;
  state->hash_bits = (unsigned int)&state->dyn_ltree[295];
  state->hash_size = (unsigned int)&state->dyn_ltree[295];
  return 0;
}


// ========================================================================
// inflateInit2_
// EA  : 0x8320F288
// RVA : 0x0120F288
// PDB : w:\tech5\libs\zlib\inflate.c
// ========================================================================

int __fastcall inflateInit2_(z_stream_s *strm, int windowBits, const char *version, int stream_size)
{
  void *(__fastcall *zalloc)(void *, unsigned int, unsigned int); // r11
  internal_state *v8; // r3

  if ( version == nullptr || *version != 49 || stream_size != 56 )
    return -6;
  if ( strm == nullptr )
    return -2;
  zalloc = strm->zalloc;
  strm->msg = nullptr;
  if ( zalloc == nullptr )
  {
    strm->opaque = nullptr;
    strm->zalloc = zcalloc;
  }
  if ( strm->zfree == nullptr )
    strm->zfree = zcfree;
  v8 = (internal_state *)strm->zalloc(a1: strm->opaque, a2: 1, a3: 9520);
  if ( v8 == nullptr )
    return -4;
  strm->state = v8;
  if ( windowBits >= 0 )
  {
    v8->pending_buf = (unsigned __int8 *)((windowBits >> 4) + 1);
    if ( windowBits < 48 )
      windowBits &= 0xFu;
  }
  else
  {
    windowBits = -windowBits;
    v8->pending_buf = nullptr;
  }
  if ( windowBits < 8 || windowBits > 15 )
  {
    strm->zfree(a1: strm->opaque, a2: v8);
    strm->state = nullptr;
    return -2;
  }
  else
  {
    *(_DWORD *)&v8->method = windowBits;
    v8->w_mask = 0;
    return inflateReset(strm);
  }
}


// ========================================================================
// inflateInit_
// EA  : 0x8320F3C0
// RVA : 0x0120F3C0
// PDB : w:\tech5\libs\zlib\inflate.c
// ========================================================================

int __fastcall inflateInit_(z_stream_s *strm, const char *version, int stream_size)
{
  return inflateInit2_(strm, windowBits: 15, version, stream_size);
}


// ========================================================================
// updatewindow
// EA  : 0x8320F3D0
// RVA : 0x0120F3D0
// PDB : w:\tech5\libs\zlib\inflate.c
// ========================================================================

int __fastcall updatewindow(z_stream_s *strm, unsigned int out)
{
  internal_state *state; // r31
  char *w_mask; // r3
  int v7; // r11
  size_t last_flush; // r5
  unsigned int v9; // r30
  unsigned int v10; // r10
  unsigned int w_bits; // r11
  size_t v12; // r29
  size_t v13; // r30
  unsigned int v14; // r10
  unsigned int v15; // r10
  unsigned int v16; // r11
  unsigned int w_size; // r11

  state = strm->state;
  w_mask = (char *)state->w_mask;
  if ( w_mask == nullptr )
  {
    w_mask = (char *)strm->zalloc(a1: strm->opaque, a2: 1 << *(_DWORD *)&state->method, a3: 1);
    state->w_mask = (unsigned int)w_mask;
    if ( w_mask == nullptr )
      return 1;
  }
  if ( state->last_flush == 0 )
  {
    v7 = *(_DWORD *)&state->method;
    state->w_bits = 0;
    state->w_size = 0;
    state->last_flush = 1 << v7;
  }
  last_flush = state->last_flush;
  v9 = out - strm->avail_out;
  if ( v9 < last_flush )
  {
    w_bits = state->w_bits;
    v12 = last_flush - w_bits;
    if ( last_flush - w_bits > v9 )
      v12 = v9;
    memcpy(Dst: &w_mask[w_bits], Src: &strm->next_out[-v9], Size: v12);
    v13 = v9 - v12;
    if ( v13 != 0 )
    {
      memcpy(Dst: (void *)state->w_mask, Src: &strm->next_out[-v13], Size: v13);
      v14 = state->last_flush;
      state->w_bits = v13;
      state->w_size = v14;
      return 0;
    }
    else
    {
      v15 = state->last_flush;
      v16 = state->w_bits + v12;
      state->w_bits = v16;
      if ( v16 == v15 )
        state->w_bits = 0;
      w_size = state->w_size;
      if ( w_size < v15 )
        state->w_size = w_size + v12;
      return 0;
    }
  }
  else
  {
    memcpy(Dst: w_mask, Src: &strm->next_out[-last_flush], Size: last_flush);
    v10 = state->last_flush;
    state->w_bits = 0;
    state->w_size = v10;
    return 0;
  }
}


// ========================================================================
// inflate
// EA  : 0x8320F520
// RVA : 0x0120F520
// PDB : w:\tech5\libs\zlib\inflate.c
// ========================================================================

int __fastcall inflate(z_stream_s *strm, int flush)
{
  internal_state *state; // r29
  unsigned int avail_out; // r11
  unsigned int avail_in; // r27
  z_stream_s *v6; // r17
  unsigned __int8 *next_in; // r28
  unsigned __int8 *window; // r30
  unsigned int window_size; // r31
  unsigned int v10; // r21
  unsigned int v11; // r20
  unsigned __int8 *v12; // r22
  int v13; // r18
  unsigned __int8 *pending_buf; // r10
  int v15; // r11
  int v16; // r11
  unsigned int gzindex; // r11
  unsigned int v18; // r11
  char *v19; // r11
  unsigned int v20; // r3
  char v21; // t0
  int v22; // r11
  int v23; // r11
  _DWORD *v24; // r11
  int v25; // r11
  int v26; // r11
  unsigned int v27; // r11
  int v28; // r11
  int v29; // r11
  unsigned int v30; // r11
  int v31; // r11
  int v32; // r11
  unsigned int v33; // r11
  unsigned int v34; // r11
  unsigned __int16 *prev; // r9
  unsigned int v36; // r26
  _DWORD *v37; // r11
  int v38; // r8
  int v39; // r7
  unsigned int v40; // r10
  size_t v41; // r5
  unsigned int v42; // r26
  unsigned int v43; // r11
  int v44; // r25
  int v45; // r10
  unsigned int v46; // r9
  unsigned __int16 *v47; // r11
  unsigned int v48; // r11
  unsigned int v49; // r26
  unsigned int v50; // r11
  int v51; // r25
  int v52; // r10
  unsigned int v53; // r9
  unsigned __int16 *v54; // r11
  unsigned int v55; // r11
  int v56; // r11
  int v57; // r11
  unsigned int v58; // r11
  unsigned int v59; // r3
  int v60; // r11
  int v61; // r11
  unsigned int v62; // r11
  unsigned int v63; // r3
  int v64; // r11
  int v65; // r11
  int v66; // r11
  int v67; // r11
  int v68; // r11
  size_t v69; // r26
  int v70; // r11
  int v71; // r11
  unsigned int v72; // r7
  unsigned int v73; // r6
  int v74; // r5
  int v75; // r11
  int v76; // r11
  unsigned int v77; // r5
  unsigned int v78; // r5
  unsigned int v79; // r11
  int v80; // r11
  int v81; // r10
  int v82; // r10
  int v83; // r10
  int v84; // r10
  int match_available; // r10
  int v86; // r11
  __int16 v87; // r10
  int v88; // r10
  int v89; // r10
  int v90; // r8
  int v91; // r10
  int v92; // r10
  int v93; // r8
  int i; // ctr
  unsigned int match_length; // r5
  unsigned int strstart; // r10
  unsigned int v97; // r11
  unsigned int prev_match; // r5
  unsigned int hash_size; // r8
  const char *v100; // r10
  int v101; // r11
  int v102; // r11
  int v103; // r10
  unsigned int v104; // r7
  unsigned int ins_h; // r10
  int v106; // r11
  int v107; // r11
  int v108; // r11
  unsigned int hash_bits; // r7
  const char *v110; // r10
  int v111; // r11
  int v112; // r11
  char v113; // r9
  int v114; // r10
  unsigned int v115; // r7
  unsigned int v116; // r10
  int v117; // r11
  int v118; // r11
  int v119; // r11
  unsigned int head; // r11
  unsigned int w_bits; // r10
  unsigned int v122; // r11
  unsigned int w_mask; // r9
  unsigned __int8 *v124; // r9
  unsigned __int16 *v125; // r10
  int v126; // r10
  int v127; // r11
  int v128; // r11
  unsigned int v129; // r5
  const unsigned __int8 *v130; // r4
  unsigned int wrap; // r3
  unsigned int v132; // r3
  int v133; // r11
  int v134; // r11
  int v135; // r11
  unsigned int v137; // r30
  unsigned int v138; // r8
  unsigned int total_out; // r11
  unsigned int v140; // r31
  unsigned __int8 *v141; // r4
  unsigned int v142; // r5
  unsigned int v143; // r3
  const unsigned __int8 *v144; // r4
  unsigned int v145; // r3
  int v146; // [sp+50h] [-F0h]
  const char *v147; // [sp+50h] [-F0h]
  const char *v148; // [sp+50h] [-F0h]
  unsigned __int8 v149; // [sp+54h] [-ECh] BYREF
  char v150; // [sp+55h] [-EBh]
  char v151; // [sp+56h] [-EAh]
  char v152; // [sp+57h] [-E9h]
  const char *v153; // [sp+58h] [-E8h]
  unsigned __int8 *next_out; // [sp+5Ch] [-E4h]
  const char *v155; // [sp+60h] [-E0h]
  const char *v156; // [sp+64h] [-DCh]
  const char *v157; // [sp+68h] [-D8h]
  const char *v158; // [sp+6Ch] [-D4h]
  char *v159; // [sp+70h] [-D0h]
  const char *v160; // [sp+74h] [-CCh]
  const char *v161; // [sp+78h] [-C8h]
  const char *v162; // [sp+7Ch] [-C4h]
  const char *v163; // [sp+80h] [-C0h]
  const char *v164; // [sp+84h] [-BCh]
  const char *v165; // [sp+88h] [-B8h]
  const char *v166; // [sp+8Ch] [-B4h]
  const char *v167; // [sp+90h] [-B0h]
  const char *v168; // [sp+94h] [-ACh]
  const char *v169; // [sp+98h] [-A8h]
  unsigned int v170; // [sp+9Ch] [-A4h]

  if ( strm == nullptr )
    return -2;
  state = strm->state;
  if ( state == nullptr || strm->next_out == nullptr || strm->next_in == nullptr && strm->avail_in != 0 )
    return -2;
  if ( state->strm == (z_stream_s *)11 )
    state->strm = (z_stream_s *)12;
  avail_out = strm->avail_out;
  avail_in = strm->avail_in;
  v6 = state->strm;
  next_in = strm->next_in;
  window = state->window;
  window_size = state->window_size;
  next_out = strm->next_out;
  v170 = avail_in;
  v10 = avail_out;
  v153 = "invalid window size";
  v11 = avail_out;
  v12 = next_out;
  v158 = "header crc mismatch";
  v13 = 0;
  v155 = "unknown header flags set";
  v169 = "incorrect length check";
  v168 = "incorrect data check";
  v160 = "invalid stored block lengths";
  v157 = "invalid window size";
  v159 = "invalid block type";
  v167 = "invalid distance too far back";
  v166 = "invalid distance code";
  v165 = "invalid literal/length code";
  v164 = "invalid distances set";
  v163 = "invalid literal/lengths set";
  next_out = "invalid bit length repeat";
  v162 = "invalid code lengths set";
  v161 = "too many length or distance symbols";
  v156 = "incorrect header check";
  while ( 2 )
  {
    switch ( (unsigned int)v6 )
    {
      case 0u:
        pending_buf = state->pending_buf;
        if ( pending_buf == nullptr )
        {
          state->strm = (z_stream_s *)12;
          goto LABEL_297;
        }
        if ( window_size < 0x10 )
        {
          while ( avail_in != 0 )
          {
            v15 = *next_in;
            --avail_in;
            ++next_in;
            v16 = v15 << window_size;
            window_size += 8;
            window += v16;
            if ( window_size >= 0x10 )
              goto LABEL_15;
          }
          goto inf_leave;
        }
LABEL_15:
        if ( ((unsigned __int8)pending_buf & 2) != 0 && window == (unsigned __int8 *)35615 )
        {
          state->wrap = crc32(crc: 0, buf: nullptr, len: 0);
          v149 = 31;
          v150 = -117;
          state->wrap = crc32(crc: state->wrap, buf: &v149, len: 2u);
          window = nullptr;
          state->strm = (z_stream_s *)1;
          window_size = 0;
          goto LABEL_297;
        }
        gzindex = state->gzindex;
        state->pending_out = nullptr;
        if ( gzindex != 0 )
          *(_DWORD *)(gzindex + 48) = -1;
        if ( ((int)state->pending_buf & 1) == 0
          || ((((_DWORD)window << 8) & 0xFF00) + ((unsigned int)window >> 8)) % 0x1F != 0 )
        {
          v19 = (char *)v156;
          goto LABEL_295;
        }
        if ( ((unsigned __int8)window & 0xF) != 8 )
        {
          strm->msg = "unknown compression method";
          goto LABEL_296;
        }
        window = (unsigned __int8 *)((unsigned int)window >> 4);
        window_size -= 4;
        v18 = ((unsigned __int8)window & 0xF) + 8;
        if ( v18 > *(_DWORD *)&state->method )
        {
          v19 = (char *)v157;
          goto LABEL_295;
        }
        state->pending = 1 << v18;
        v20 = adler32(adler: 0, buf: nullptr, len: 0);
        state->wrap = v20;
        strm->adler = v20;
        v21 = __ROR4__(~(unsigned int)window, 8);
        window = nullptr;
        window_size = 0;
        state->strm = (z_stream_s *)(v21 & 2 | 9);
        goto LABEL_297;
      case 1u:
        for ( ; window_size < 0x10; window += v23 )
        {
          if ( avail_in == 0 )
            goto inf_leave;
          v22 = *next_in;
          --avail_in;
          ++next_in;
          v23 = v22 << window_size;
          window_size += 8;
        }
        state->pending_out = window;
        if ( (unsigned __int8)window != 8 )
        {
          strm->msg = "unknown compression method";
          goto LABEL_296;
        }
        if ( ((unsigned __int16)window & 0xE000) != 0 )
        {
          v19 = (char *)v155;
          goto LABEL_295;
        }
        v24 = (_DWORD *)state->gzindex;
        if ( v24 != nullptr )
          *v24 = ((unsigned __int16)window & 0x100) != 0;
        if ( ((int)state->pending_out & 0x200) != 0 )
        {
          v150 = BYTE2(window);
          v149 = (unsigned __int8)window;
          state->wrap = crc32(crc: state->wrap, buf: &v149, len: 2u);
        }
        window = nullptr;
        window_size = 0;
        state->strm = (z_stream_s *)2;
        do
        {
LABEL_41:
          if ( avail_in == 0 )
            goto inf_leave;
          v25 = *next_in;
          --avail_in;
          ++next_in;
          v26 = v25 << window_size;
          window_size += 8;
          window += v26;
        }
        while ( window_size < 0x20 );
LABEL_43:
        v27 = state->gzindex;
        if ( v27 != 0 )
          *(_DWORD *)(v27 + 4) = window;
        if ( ((int)state->pending_out & 0x200) != 0 )
        {
          v149 = (unsigned __int8)window;
          v152 = HIBYTE(window);
          v150 = BYTE2(window);
          v151 = BYTE1(window);
          state->wrap = crc32(crc: state->wrap, buf: &v149, len: 4u);
        }
        window = nullptr;
        window_size = 0;
        state->strm = (z_stream_s *)3;
        do
        {
LABEL_49:
          if ( avail_in == 0 )
            goto inf_leave;
          v28 = *next_in;
          --avail_in;
          ++next_in;
          v29 = v28 << window_size;
          window_size += 8;
          window += v29;
        }
        while ( window_size < 0x10 );
LABEL_51:
        v30 = state->gzindex;
        if ( v30 != 0 )
        {
          *(_DWORD *)(v30 + 8) = (unsigned __int8)window;
          *(_DWORD *)(state->gzindex + 12) = (unsigned int)window >> 8;
        }
        if ( ((int)state->pending_out & 0x200) != 0 )
        {
          v150 = BYTE2(window);
          v149 = (unsigned __int8)window;
          state->wrap = crc32(crc: state->wrap, buf: &v149, len: 2u);
        }
        window = nullptr;
        window_size = 0;
        state->strm = (z_stream_s *)4;
LABEL_56:
        if ( ((int)state->pending_out & 0x400) != 0 )
        {
          if ( window_size < 0x10 )
          {
            while ( avail_in != 0 )
            {
              v31 = *next_in;
              --avail_in;
              ++next_in;
              v32 = v31 << window_size;
              window_size += 8;
              window += v32;
              if ( window_size >= 0x10 )
                goto LABEL_60;
            }
            goto inf_leave;
          }
LABEL_60:
          v33 = state->gzindex;
          state->prev = (unsigned __int16 *)window;
          if ( v33 != 0 )
            *(_DWORD *)(v33 + 20) = window;
          if ( ((int)state->pending_out & 0x200) != 0 )
          {
            v150 = BYTE2(window);
            v149 = (unsigned __int8)window;
            state->wrap = crc32(crc: state->wrap, buf: &v149, len: 2u);
          }
          window = nullptr;
          window_size = 0;
        }
        else
        {
          v34 = state->gzindex;
          if ( v34 != 0 )
            *(_DWORD *)(v34 + 16) = 0;
        }
        state->strm = (z_stream_s *)5;
LABEL_68:
        if ( ((int)state->pending_out & 0x400) != 0 )
        {
          prev = state->prev;
          v36 = (unsigned int)prev;
          if ( (unsigned int)prev > avail_in )
            v36 = avail_in;
          if ( v36 != 0 )
          {
            v37 = (_DWORD *)state->gzindex;
            if ( v37 != nullptr )
            {
              v38 = v37[4];
              if ( v38 != 0 )
              {
                v39 = v37[5];
                v40 = v37[6];
                v41 = v40 - (v39 - (_DWORD)prev);
                if ( v36 + v39 - (_DWORD)prev <= v40 )
                  v41 = v36;
                memcpy(Dst: (void *)(v38 + v39 - (_DWORD)prev), Src: next_in, Size: v41);
              }
            }
            if ( ((int)state->pending_out & 0x200) != 0 )
              state->wrap = crc32(crc: state->wrap, buf: next_in, len: v36);
            avail_in -= v36;
            next_in += v36;
            state->prev = (unsigned __int16 *)((char *)state->prev - v36);
          }
          if ( state->prev != nullptr )
            goto inf_leave;
        }
        state->prev = nullptr;
        state->strm = (z_stream_s *)6;
LABEL_82:
        if ( ((int)state->pending_out & 0x800) != 0 )
        {
          if ( avail_in == 0 )
            goto inf_leave;
          v42 = 0;
          do
          {
            v43 = state->gzindex;
            v44 = next_in[v42++];
            if ( v43 != 0 )
            {
              v45 = *(_DWORD *)(v43 + 28);
              if ( v45 != 0 )
              {
                v46 = *(_DWORD *)(v43 + 32);
                v47 = state->prev;
                if ( (unsigned int)v47 < v46 )
                {
                  *((_BYTE *)v47 + v45) = v44;
                  ++state->prev;
                }
              }
            }
          }
          while ( v44 != 0 && v42 < avail_in );
          if ( ((int)state->pending_out & 0x200) != 0 )
            state->wrap = crc32(crc: state->wrap, buf: next_in, len: v42);
          avail_in -= v42;
          next_in += v42;
          if ( v44 != 0 )
            goto inf_leave;
        }
        else
        {
          v48 = state->gzindex;
          if ( v48 != 0 )
            *(_DWORD *)(v48 + 28) = 0;
        }
        state->prev = nullptr;
        state->strm = (z_stream_s *)7;
LABEL_98:
        if ( ((int)state->pending_out & 0x1000) != 0 )
        {
          if ( avail_in == 0 )
            goto inf_leave;
          v49 = 0;
          do
          {
            v50 = state->gzindex;
            v51 = next_in[v49++];
            if ( v50 != 0 )
            {
              v52 = *(_DWORD *)(v50 + 36);
              if ( v52 != 0 )
              {
                v53 = *(_DWORD *)(v50 + 40);
                v54 = state->prev;
                if ( (unsigned int)v54 < v53 )
                {
                  *((_BYTE *)v54 + v52) = v51;
                  ++state->prev;
                }
              }
            }
          }
          while ( v51 != 0 && v49 < avail_in );
          if ( ((int)state->pending_out & 0x200) != 0 )
            state->wrap = crc32(crc: state->wrap, buf: next_in, len: v49);
          avail_in -= v49;
          next_in += v49;
          if ( v51 != 0 )
            goto inf_leave;
        }
        else
        {
          v55 = state->gzindex;
          if ( v55 != 0 )
            *(_DWORD *)(v55 + 36) = 0;
        }
        state->strm = (z_stream_s *)8;
LABEL_114:
        if ( ((int)state->pending_out & 0x200) != 0 )
        {
          if ( window_size < 0x10 )
          {
            while ( avail_in != 0 )
            {
              v56 = *next_in;
              --avail_in;
              ++next_in;
              v57 = v56 << window_size;
              window_size += 8;
              window += v57;
              if ( window_size >= 0x10 )
                goto LABEL_118;
            }
            goto inf_leave;
          }
LABEL_118:
          if ( window != (unsigned __int8 *)LOWORD(state->wrap) )
          {
            v19 = (char *)v158;
            goto LABEL_295;
          }
          window = nullptr;
          window_size = 0;
        }
        v58 = state->gzindex;
        if ( v58 != 0 )
        {
          *(_DWORD *)(v58 + 44) = ((int)state->pending_out >> 9) & 1;
          *(_DWORD *)(state->gzindex + 48) = 1;
        }
        v59 = crc32(crc: 0, buf: nullptr, len: 0);
        state->wrap = v59;
        strm->adler = v59;
        state->strm = (z_stream_s *)11;
        goto LABEL_297;
      case 2u:
        if ( window_size < 0x20 )
          goto LABEL_41;
        goto LABEL_43;
      case 3u:
        if ( window_size < 0x10 )
          goto LABEL_49;
        goto LABEL_51;
      case 4u:
        goto LABEL_56;
      case 5u:
        goto LABEL_68;
      case 6u:
        goto LABEL_82;
      case 7u:
        goto LABEL_98;
      case 8u:
        goto LABEL_114;
      case 9u:
        for ( ; window_size < 0x20; window += v61 )
        {
          if ( avail_in == 0 )
            goto inf_leave;
          v60 = *next_in;
          --avail_in;
          ++next_in;
          v61 = v60 << window_size;
          window_size += 8;
        }
        v62 = ((((unsigned __int16)window & 0xFF00) + ((_DWORD)window << 16)) << 8)
            + (((unsigned int)window >> 8) & 0xFF00)
            + ((unsigned int)window >> 24);
        window = nullptr;
        window_size = 0;
        state->wrap = v62;
        strm->adler = v62;
        state->strm = (z_stream_s *)10;
LABEL_128:
        if ( state->pending_buf_size == 0 )
        {
          strm->next_out = v12;
          strm->avail_out = v10;
          strm->next_in = next_in;
          strm->avail_in = avail_in;
          state->window = window;
          state->window_size = window_size;
          return 2;
        }
        v63 = adler32(adler: 0, buf: nullptr, len: 0);
        state->wrap = v63;
        strm->adler = v63;
        state->strm = (z_stream_s *)11;
LABEL_130:
        if ( flush == 5 )
          goto inf_leave;
LABEL_131:
        if ( state->status != 0 )
        {
          window = (unsigned __int8 *)((unsigned int)window >> (window_size & 7));
          window_size -= window_size & 7;
          state->strm = (z_stream_s *)24;
        }
        else
        {
          if ( window_size < 3 )
          {
            while ( avail_in != 0 )
            {
              v64 = *next_in;
              --avail_in;
              ++next_in;
              v65 = v64 << window_size;
              window_size += 8;
              window += v65;
              if ( window_size >= 3 )
                goto LABEL_136;
            }
            goto inf_leave;
          }
LABEL_136:
          v66 = ((unsigned int)window >> 1) & 3;
          state->status = (unsigned __int8)window & 1;
          if ( v66 == 1 )
          {
            state->hash_size = (unsigned int)&unk_82404D90;
            state->hash_bits = (unsigned int)&unk_82405590;
            state->hash_mask = 9;
            state->hash_shift = 5;
            window = (unsigned __int8 *)((unsigned int)window >> 3);
            state->strm = (z_stream_s *)18;
            window_size -= 3;
          }
          else if ( v66 == 2 )
          {
            window = (unsigned __int8 *)((unsigned int)window >> 3);
            state->strm = (z_stream_s *)15;
            window_size -= 3;
          }
          else
          {
            if ( v66 != 0 )
            {
              strm->msg = v159;
              state->strm = (z_stream_s *)27;
              window = (unsigned __int8 *)((unsigned int)window >> 3);
            }
            else
            {
              window = (unsigned __int8 *)((unsigned int)window >> 3);
              state->strm = (z_stream_s *)13;
            }
            window_size -= 3;
          }
        }
        goto LABEL_297;
      case 0xAu:
        goto LABEL_128;
      case 0xBu:
        goto LABEL_130;
      case 0xCu:
        goto LABEL_131;
      case 0xDu:
        window = (unsigned __int8 *)((unsigned int)window >> (window_size & 7));
        for ( window_size -= window_size & 7; window_size < 0x20; window += v68 )
        {
          if ( avail_in == 0 )
            goto inf_leave;
          v67 = *next_in;
          --avail_in;
          ++next_in;
          v68 = v67 << window_size;
          window_size += 8;
        }
        if ( (unsigned __int16)window != ~(unsigned int)window >> 16 )
        {
          v19 = (char *)v160;
          goto LABEL_295;
        }
        state->prev = (unsigned __int16 *)(unsigned __int16)window;
        window = nullptr;
        window_size = 0;
        state->strm = (z_stream_s *)14;
LABEL_150:
        v69 = (size_t)state->prev;
        if ( v69 == 0 )
          goto LABEL_226;
        if ( v69 > avail_in )
          v69 = avail_in;
        if ( v69 > v10 )
          v69 = v10;
        if ( v69 == 0 )
          goto inf_leave;
        memcpy(Dst: v12, Src: next_in, Size: v69);
        avail_in -= v69;
        next_in += v69;
        v10 -= v69;
        state->prev = (unsigned __int16 *)((char *)state->prev - v69);
        v12 += v69;
        goto LABEL_297;
      case 0xEu:
        goto LABEL_150;
      case 0xFu:
        for ( ; window_size < 0xE; window += v71 )
        {
          if ( avail_in == 0 )
            goto inf_leave;
          v70 = *next_in;
          --avail_in;
          ++next_in;
          v71 = v70 << window_size;
          window_size += 8;
        }
        state->match_length = ((unsigned __int8)window & 0x1F) + 257;
        v72 = (((unsigned int)window >> 5) & 0x1F) + 1;
        v73 = ((unsigned __int8)window & 0x1F) + 257;
        v74 = (((unsigned int)window >> 10) & 0xF) + 4;
        state->prev_match = v72;
        window = (unsigned __int8 *)((unsigned int)window >> 14);
        window_size -= 14;
        state->block_start = v74;
        if ( v73 > 0x11E || v72 > 0x1E )
        {
          v19 = (char *)v161;
          goto LABEL_295;
        }
        state->match_available = 0;
        state->strm = (z_stream_s *)16;
LABEL_163:
        if ( state->match_available < (unsigned int)state->block_start )
        {
          while ( window_size >= 3 )
          {
LABEL_167:
            window_size -= 3;
            *((_WORD *)&state->match_start + order[state->match_available]) = (unsigned __int8)window & 7;
            window = (unsigned __int8 *)((unsigned int)window >> 3);
            v77 = state->match_available + 1;
            state->match_available = v77;
            if ( v77 >= state->block_start )
              goto LABEL_168;
          }
          while ( avail_in != 0 )
          {
            v75 = *next_in;
            --avail_in;
            ++next_in;
            v76 = v75 << window_size;
            window_size += 8;
            window += v76;
            if ( window_size >= 3 )
              goto LABEL_167;
          }
          goto inf_leave;
        }
LABEL_168:
        if ( state->match_available < 0x13u )
        {
          do
          {
            *((_WORD *)&state->match_start + order[state->match_available]) = 0;
            v78 = state->match_available + 1;
            state->match_available = v78;
          }
          while ( v78 < 0x13 );
        }
        state->hash_size = (unsigned int)&state->dyn_ltree[295];
        state->strstart = (unsigned int)&state->dyn_ltree[295];
        state->hash_mask = 7;
        v13 = inflate_table(
                type: CODES,
                lens: (unsigned __int16 *)&state->match_start,
                codes: 0x13u,
                table: (code **)&state->strstart,
                bits: &state->hash_mask,
                work: (unsigned __int16 *)&state->dyn_ltree[151]);
        if ( v13 != 0 )
        {
          v19 = (char *)v162;
          goto LABEL_295;
        }
        state->match_available = 0;
        state->strm = (z_stream_s *)17;
LABEL_174:
        if ( state->match_available < state->prev_match + state->match_length )
        {
          while ( 1 )
          {
            v146 = *(_DWORD *)(4 * (((1 << state->hash_mask) - 1) & (unsigned int)window) + state->hash_size);
            v79 = BYTE1(v146);
            if ( BYTE1(v146) > window_size )
              break;
LABEL_178:
            if ( (unsigned __int16)v146 >= 0x10u )
            {
              if ( (unsigned __int16)v146 == 16 )
              {
                if ( window_size < v79 + 2 )
                {
                  while ( avail_in != 0 )
                  {
                    v83 = *next_in;
                    --avail_in;
                    ++next_in;
                    v84 = v83 << window_size;
                    window_size += 8;
                    window += v84;
                    if ( window_size >= v79 + 2 )
                      goto LABEL_187;
                  }
                  goto inf_leave;
                }
LABEL_187:
                match_available = state->match_available;
                window = (unsigned __int8 *)((unsigned int)window >> v79);
                window_size -= v79;
                if ( match_available == 0 )
                  goto LABEL_207;
                v86 = ((unsigned __int8)window & 3) + 3;
                window = (unsigned __int8 *)((unsigned int)window >> 2);
                window_size -= 2;
                v87 = *((_WORD *)&state->strstart + match_available + 1);
              }
              else
              {
                if ( (unsigned __int16)v146 == 17 )
                {
                  if ( window_size < v79 + 3 )
                  {
                    while ( avail_in != 0 )
                    {
                      v88 = *next_in;
                      --avail_in;
                      ++next_in;
                      v89 = v88 << window_size;
                      window_size += 8;
                      window += v89;
                      if ( window_size >= v79 + 3 )
                        goto LABEL_193;
                    }
                    goto inf_leave;
                  }
LABEL_193:
                  v90 = ((unsigned int)window >> v79) & 7;
                  window = (unsigned __int8 *)((unsigned int)window >> v79 >> 3);
                  window_size = window_size - v79 - 3;
                  v86 = v90 + 3;
                }
                else
                {
                  if ( window_size < v79 + 7 )
                  {
                    while ( avail_in != 0 )
                    {
                      v91 = *next_in;
                      --avail_in;
                      ++next_in;
                      v92 = v91 << window_size;
                      window_size += 8;
                      window += v92;
                      if ( window_size >= v79 + 7 )
                        goto LABEL_197;
                    }
                    goto inf_leave;
                  }
LABEL_197:
                  v93 = ((unsigned int)window >> v79) & 0x7F;
                  window = (unsigned __int8 *)((unsigned int)window >> v79 >> 7);
                  window_size = window_size - v79 - 7;
                  v86 = v93 + 11;
                }
                v87 = 0;
              }
              if ( state->match_available + v86 > state->prev_match + state->match_length )
              {
LABEL_207:
                v19 = (char *)next_out;
                goto LABEL_295;
              }
              if ( v86 != 0 )
              {
                for ( i = v86; i != 0; --i )
                  *((_WORD *)&state->match_start + state->match_available++) = v87;
              }
            }
            else
            {
              if ( window_size < v79 )
              {
                while ( avail_in != 0 )
                {
                  v81 = *next_in;
                  --avail_in;
                  ++next_in;
                  v82 = v81 << window_size;
                  window_size += 8;
                  window += v82;
                  if ( window_size >= v79 )
                    goto LABEL_182;
                }
                goto inf_leave;
              }
LABEL_182:
              window = (unsigned __int8 *)((unsigned int)window >> v79);
              window_size -= v79;
              *((_WORD *)&state->match_start + state->match_available++) = v146;
            }
            if ( state->match_available >= state->prev_match + state->match_length )
              goto LABEL_204;
          }
          while ( avail_in != 0 )
          {
            v80 = *next_in;
            --avail_in;
            ++next_in;
            window += v80 << window_size;
            window_size += 8;
            v146 = *(_DWORD *)(4 * (((1 << state->hash_mask) - 1) & (unsigned int)window) + state->hash_size);
            v79 = BYTE1(v146);
            if ( BYTE1(v146) <= window_size )
              goto LABEL_178;
          }
          goto inf_leave;
        }
LABEL_204:
        if ( state->strm == (z_stream_s *)27 )
          goto LABEL_297;
        match_length = state->match_length;
        state->hash_size = (unsigned int)&state->dyn_ltree[295];
        state->strstart = (unsigned int)&state->dyn_ltree[295];
        state->hash_mask = 9;
        v13 = inflate_table(
                type: LENS,
                lens: (unsigned __int16 *)&state->match_start,
                codes: match_length,
                table: (code **)&state->strstart,
                bits: &state->hash_mask,
                work: (unsigned __int16 *)&state->dyn_ltree[151]);
        if ( v13 != 0 )
        {
          v19 = (char *)v163;
          goto LABEL_295;
        }
        strstart = state->strstart;
        v97 = state->match_length;
        state->hash_shift = 6;
        prev_match = state->prev_match;
        state->hash_bits = strstart;
        v13 = inflate_table(
                type: DISTS,
                lens: (unsigned __int16 *)&state->match_start + v97,
                codes: prev_match,
                table: (code **)&state->strstart,
                bits: &state->hash_shift,
                work: (unsigned __int16 *)&state->dyn_ltree[151]);
        if ( v13 != 0 )
        {
          v19 = (char *)v164;
          goto LABEL_295;
        }
        state->strm = (z_stream_s *)18;
LABEL_211:
        if ( avail_in >= 6 && v10 >= 0x102 )
        {
          strm->next_out = v12;
          strm->avail_out = v10;
          strm->next_in = next_in;
          strm->avail_in = avail_in;
          state->window = window;
          state->window_size = window_size;
          inflate_fast(strm, start: v11);
          v12 = strm->next_out;
          v10 = strm->avail_out;
          next_in = strm->next_in;
          avail_in = strm->avail_in;
          window = state->window;
          window_size = state->window_size;
          goto LABEL_297;
        }
        hash_size = state->hash_size;
        v100 = *(const char **)(4 * (((1 << state->hash_mask) - 1) & (unsigned int)window) + hash_size);
        v147 = v100;
        v101 = BYTE1(v100);
        if ( BYTE1(v100) > window_size )
        {
          while ( avail_in != 0 )
          {
            v102 = *next_in;
            --avail_in;
            ++next_in;
            window += v102 << window_size;
            window_size += 8;
            v100 = *(const char **)(4 * (((1 << state->hash_mask) - 1) & (unsigned int)window) + state->hash_size);
            v147 = v100;
            v101 = BYTE1(v100);
            if ( BYTE1(v100) <= window_size )
              goto LABEL_217;
          }
          goto inf_leave;
        }
LABEL_217:
        if ( HIBYTE(v147) != 0 && (HIBYTE(v147) & 0xF0) == 0 )
        {
          v153 = v100;
          v147 = *(const char **)(4
                                * (((((1 << (HIBYTE(v147) + v101)) - 1) & (unsigned int)window) >> v101)
                                 + (unsigned __int16)v147)
                                + hash_size);
          v101 = BYTE1(v147);
          v104 = BYTE1(v100) + BYTE1(v147);
          v103 = BYTE1(v100);
          if ( v104 > window_size )
          {
            while ( avail_in != 0 )
            {
              --avail_in;
              window += *next_in << window_size;
              window_size += 8;
              ++next_in;
              v147 = *(const char **)(4
                                    * (((((1 << (HIBYTE(v153) + v103)) - 1) & (unsigned int)window) >> v103)
                                     + (unsigned __int16)v153)
                                    + state->hash_size);
              v101 = BYTE1(v147);
              if ( v103 + (unsigned int)BYTE1(v147) <= window_size )
                goto LABEL_222;
            }
            goto inf_leave;
          }
LABEL_222:
          window = (unsigned __int8 *)((unsigned int)window >> v103);
          window_size -= v103;
        }
        window = (unsigned __int8 *)((unsigned int)window >> v101);
        window_size -= v101;
        state->prev = (unsigned __int16 *)(unsigned __int16)v147;
        if ( HIBYTE(v147) == 0 )
        {
          state->strm = (z_stream_s *)23;
          goto LABEL_297;
        }
        if ( (HIBYTE(v147) & 0x20) != 0 )
        {
LABEL_226:
          state->strm = (z_stream_s *)11;
          goto LABEL_297;
        }
        if ( (HIBYTE(v147) & 0x40) != 0 )
        {
          v19 = (char *)v165;
          goto LABEL_295;
        }
        state->ins_h = HIBYTE(v147) & 0xF;
        state->strm = (z_stream_s *)19;
LABEL_230:
        ins_h = state->ins_h;
        if ( ins_h != 0 )
        {
          if ( window_size < ins_h )
          {
            while ( avail_in != 0 )
            {
              v106 = *next_in;
              --avail_in;
              ++next_in;
              v107 = v106 << window_size;
              window_size += 8;
              window += v107;
              if ( window_size >= state->ins_h )
                goto LABEL_234;
            }
            goto inf_leave;
          }
LABEL_234:
          window_size -= ins_h;
          v108 = ((1 << ins_h) - 1) & (unsigned int)window;
          window = (unsigned __int8 *)((unsigned int)window >> ins_h);
          state->prev = (unsigned __int16 *)((char *)state->prev + v108);
        }
        state->strm = (z_stream_s *)20;
LABEL_236:
        hash_bits = state->hash_bits;
        v110 = *(const char **)(4 * (((1 << state->hash_shift) - 1) & (unsigned int)window) + hash_bits);
        v148 = v110;
        v111 = BYTE1(v110);
        if ( BYTE1(v110) > window_size )
        {
          while ( avail_in != 0 )
          {
            v112 = *next_in;
            --avail_in;
            ++next_in;
            window += v112 << window_size;
            window_size += 8;
            v110 = *(const char **)(4 * (((1 << state->hash_shift) - 1) & (unsigned int)window) + state->hash_bits);
            v148 = v110;
            v111 = BYTE1(v110);
            if ( BYTE1(v110) <= window_size )
              goto LABEL_239;
          }
          goto inf_leave;
        }
LABEL_239:
        v113 = HIBYTE(v148);
        if ( (HIBYTE(v148) & 0xF0) == 0 )
        {
          v153 = v110;
          v148 = *(const char **)(4
                                * (((((1 << (HIBYTE(v148) + v111)) - 1) & (unsigned int)window) >> v111)
                                 + (unsigned __int16)v148)
                                + hash_bits);
          v111 = BYTE1(v148);
          v115 = BYTE1(v110) + BYTE1(v148);
          v114 = BYTE1(v110);
          if ( v115 > window_size )
          {
            while ( avail_in != 0 )
            {
              --avail_in;
              window += *next_in << window_size;
              window_size += 8;
              ++next_in;
              v148 = *(const char **)(4
                                    * (((((1 << (HIBYTE(v153) + v114)) - 1) & (unsigned int)window) >> v114)
                                     + (unsigned __int16)v153)
                                    + state->hash_bits);
              v111 = BYTE1(v148);
              if ( v114 + (unsigned int)BYTE1(v148) <= window_size )
                goto LABEL_243;
            }
            goto inf_leave;
          }
LABEL_243:
          v113 = HIBYTE(v148);
          window = (unsigned __int8 *)((unsigned int)window >> v114);
          window_size -= v114;
        }
        window = (unsigned __int8 *)((unsigned int)window >> v111);
        window_size -= v111;
        if ( (v113 & 0x40) != 0 )
        {
          v19 = (char *)v166;
          goto LABEL_295;
        }
        state->ins_h = v113 & 0xF;
        state->strm = (z_stream_s *)21;
        state->head = (unsigned __int16 *)(unsigned __int16)v148;
LABEL_247:
        v116 = state->ins_h;
        if ( v116 != 0 )
        {
          if ( window_size < v116 )
          {
            while ( avail_in != 0 )
            {
              v117 = *next_in;
              --avail_in;
              ++next_in;
              v118 = v117 << window_size;
              window_size += 8;
              window += v118;
              if ( window_size >= state->ins_h )
                goto LABEL_251;
            }
            goto inf_leave;
          }
LABEL_251:
          window_size -= v116;
          v119 = ((1 << v116) - 1) & (unsigned int)window;
          window = (unsigned __int8 *)((unsigned int)window >> v116);
          state->head = (unsigned __int16 *)((char *)state->head + v119);
        }
        if ( state->head > (unsigned __int16 *)(state->w_size - v10 + v11) )
        {
          v19 = (char *)v167;
          goto LABEL_295;
        }
        state->strm = (z_stream_s *)22;
LABEL_255:
        if ( v10 == 0 )
          goto inf_leave;
        head = (unsigned int)state->head;
        if ( head <= v11 - v10 )
        {
          v125 = state->prev;
          v124 = &v12[-head];
LABEL_263:
          v122 = (unsigned int)v125;
          goto LABEL_264;
        }
        w_bits = state->w_bits;
        v122 = head - (v11 - v10);
        w_mask = state->w_mask;
        if ( v122 <= w_bits )
        {
          v124 = (unsigned __int8 *)(w_mask - v122 + w_bits);
        }
        else
        {
          v122 -= w_bits;
          v124 = (unsigned __int8 *)(w_mask + state->last_flush - v122);
        }
        v125 = state->prev;
        if ( v122 > (unsigned int)v125 )
          goto LABEL_263;
LABEL_264:
        if ( v122 > v10 )
          v122 = v10;
        v10 -= v122;
        state->prev = (unsigned __int16 *)((char *)v125 - v122);
        v126 = v124 - v12;
        do
        {
          --v122;
          *v12 = v12[v126];
          ++v12;
        }
        while ( v122 != 0 );
        if ( state->prev == nullptr )
          state->strm = (z_stream_s *)18;
        goto LABEL_297;
      case 0x10u:
        goto LABEL_163;
      case 0x11u:
        goto LABEL_174;
      case 0x12u:
        goto LABEL_211;
      case 0x13u:
        goto LABEL_230;
      case 0x14u:
        goto LABEL_236;
      case 0x15u:
        goto LABEL_247;
      case 0x16u:
        goto LABEL_255;
      case 0x17u:
        if ( v10 == 0 )
          goto inf_leave;
        --v10;
        *v12++ = (unsigned __int8)state->prev;
        state->strm = (z_stream_s *)18;
        goto LABEL_297;
      case 0x18u:
        if ( state->pending_buf == nullptr )
          goto LABEL_287;
        for ( ; window_size < 0x20; window += v128 )
        {
          if ( avail_in == 0 )
            goto inf_leave;
          v127 = *next_in;
          --avail_in;
          ++next_in;
          v128 = v127 << window_size;
          window_size += 8;
        }
        v129 = v11 - v10;
        strm->total_out += v11 - v10;
        state->gzhead = (gz_header_s *)((char *)state->gzhead + v11 - v10);
        if ( v11 != v10 )
        {
          v130 = &v12[-v129];
          wrap = state->wrap;
          if ( state->pending_out != nullptr )
            v132 = crc32(crc: wrap, buf: v130, len: v129);
          else
            v132 = adler32(adler: wrap, buf: v130, len: v129);
          state->wrap = v132;
          strm->adler = v132;
        }
        v11 = v10;
        if ( state->pending_out != nullptr )
          v133 = (int)window;
        else
          v133 = ((((unsigned __int16)window & 0xFF00) + ((_DWORD)window << 16)) << 8)
               + (((unsigned int)window >> 8) & 0xFF00)
               + ((unsigned int)window >> 24);
        if ( v133 != state->wrap )
        {
          v19 = (char *)v168;
          goto LABEL_295;
        }
        window = nullptr;
        window_size = 0;
LABEL_287:
        state->strm = (z_stream_s *)25;
LABEL_288:
        if ( state->pending_buf == nullptr || state->pending_out == nullptr )
          goto LABEL_301;
        if ( window_size < 0x20 )
        {
          while ( avail_in != 0 )
          {
            v134 = *next_in;
            --avail_in;
            ++next_in;
            v135 = v134 << window_size;
            window_size += 8;
            window += v135;
            if ( window_size >= 0x20 )
              goto LABEL_293;
          }
          goto inf_leave;
        }
LABEL_293:
        if ( window != (unsigned __int8 *)state->gzhead )
        {
          v19 = (char *)v169;
LABEL_295:
          strm->msg = v19;
LABEL_296:
          state->strm = (z_stream_s *)27;
LABEL_297:
          v6 = state->strm;
          if ( state->strm > (z_stream_s *)0x1C )
            return -2;
          continue;
        }
        window = nullptr;
        window_size = 0;
LABEL_301:
        state->strm = (z_stream_s *)26;
LABEL_302:
        v13 = 1;
inf_leave:
        strm->avail_out = v10;
        strm->next_in = next_in;
        strm->avail_in = avail_in;
        strm->next_out = v12;
        state->window = window;
        state->window_size = window_size;
        if ( (state->last_flush != 0 || (int)state->strm < 24 && v11 != strm->avail_out)
          && updatewindow(strm, out: v11) != 0 )
        {
          state->strm = (z_stream_s *)28;
          return -4;
        }
        else
        {
          v137 = v170 - strm->avail_in;
          v138 = strm->avail_out;
          total_out = strm->total_out;
          v140 = v11 - v138;
          strm->total_in += v137;
          strm->total_out = total_out + v11 - v138;
          v141 = state->pending_buf;
          state->gzhead = (gz_header_s *)((char *)state->gzhead + v11 - v138);
          if ( v141 != nullptr && v140 != 0 )
          {
            v142 = v11 - v138;
            v143 = state->wrap;
            v144 = &strm->next_out[-v140];
            if ( state->pending_out != nullptr )
              v145 = crc32(crc: v143, buf: v144, len: v142);
            else
              v145 = adler32(adler: v143, buf: v144, len: v142);
            state->wrap = v145;
            strm->adler = v145;
          }
          strm->data_type = (state->status == 0 ? 0 : 0x40)
                          + (state->strm != (z_stream_s *)11 ? 0 : 0x80)
                          + state->window_size;
          if ( (v137 == 0 && v140 == 0 || flush == 4) && v13 == 0 )
            return -5;
          return v13;
        }
      case 0x19u:
        goto LABEL_288;
      case 0x1Au:
        goto LABEL_302;
      case 0x1Bu:
        v13 = -3;
        goto inf_leave;
      case 0x1Cu:
        return -4;
      default:
        return -2;
    }
  }
}


// ========================================================================
// inflateEnd
// EA  : 0x83210D98
// RVA : 0x01210D98
// PDB : w:\tech5\libs\zlib\inflate.c
// ========================================================================

int __fastcall inflateEnd(z_stream_s *strm)
{
  internal_state *state; // r10
  void (__fastcall *zfree)(void *, void *); // r11

  if ( strm == nullptr )
    return -2;
  state = strm->state;
  if ( state == nullptr )
    return -2;
  zfree = strm->zfree;
  if ( zfree == nullptr )
    return -2;
  if ( state->w_mask != 0 )
    ((void (__fastcall *)(void *))zfree)(a1: strm->opaque);
  strm->zfree(a1: strm->opaque, a2: strm->state);
  strm->state = nullptr;
  return 0;
}

