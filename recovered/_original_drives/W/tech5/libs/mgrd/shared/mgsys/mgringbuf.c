
// ========================================================================
// mgringbuf_reset
// EA  : 0x832333D0
// RVA : 0x012333D0
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgringbuf.c
// ========================================================================

void __fastcall mgringbuf_reset(MGRINGBUF *ringbuf)
{
  char *start; // r11

  start = ringbuf->start;
  ringbuf->write = ringbuf->start;
  ringbuf->put = start;
  ringbuf->get = start;
}


// ========================================================================
// mgringbuf_init
// EA  : 0x832333E8
// RVA : 0x012333E8
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgringbuf.c
// ========================================================================

void __fastcall mgringbuf_init(MGRINGBUF *ringbuf, char *memory, unsigned int size)
{
  ringbuf->write = memory;
  ringbuf->put = memory;
  ringbuf->start = memory;
  ringbuf->size = size;
  ringbuf->end = &memory[size];
  ringbuf->get = memory;
}


// ========================================================================
// mgringbuf_put
// EA  : 0x83233408
// RVA : 0x01233408
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgringbuf.c
// ========================================================================

void __fastcall mgringbuf_put(MGRINGBUF *ringbuf, char *buffer, size_t size)
{
  char *v4; // r26
  size_t v5; // r27
  char *volatile v7; // r31
  unsigned int v8; // r10
  unsigned int v9; // r11
  char v13; // cr34
  char *start; // r3
  char *v15; // r30
  char v19; // cr34

  v4 = buffer;
  v5 = size;
  if ( size != 0 )
  {
    _R9 = &ringbuf->write;
    do
    {
      do
      {
        v7 = *_R9;
        v8 = ringbuf->size;
        v9 = *_R9 - ringbuf->get;
        if ( v9 >= v8 )
          v9 += v8;
      }
      while ( v8 - v9 - 1 < size );
      _R29 = (size_t)&v7[size - v8];
      if ( &v7[size] < ringbuf->end )
        _R29 = (size_t)&v7[size];
      while ( 1 )
      {
        __asm
        {
          mfmsr     r10
          mtmsree   r13
          lwarx     r11, 0, r9
        }
        if ( _R11 != v7 )
          break;
        __asm
        {
          stwcx.    r29, 0, r9
          mtmsree   r10
        }
        if ( v13 != 0 )
          goto LABEL_12;
      }
      __asm
      {
        stwcx.    r11, 0, r9
        mtmsree   r10
      }
LABEL_12:
      ;
    }
    while ( _R11 != v7 );
    start = *_R9;
    if ( _R29 < (unsigned int)v7 )
    {
      v15 = (char *)(ringbuf->end - (char *)v7);
      memcpy(Dst: start, Src: buffer, Size: (size_t)v15);
      start = ringbuf->start;
      size = v5 - (_DWORD)v15;
      buffer = &v4[(_DWORD)v15];
    }
    memcpy(Dst: start, Src: buffer, Size: size);
    __lwsync();
    _R10 = &ringbuf->put;
    while ( 1 )
    {
      __asm
      {
        mfmsr     r9
        mtmsree   r13
        lwarx     r11, 0, r10
      }
      if ( _R11 == v7 )
      {
        __asm
        {
          stwcx.    r29, 0, r10
          mtmsree   r9
        }
        if ( v19 != 0 )
          goto LABEL_20;
      }
      else
      {
        __asm
        {
          stwcx.    r11, 0, r10
          mtmsree   r9
        }
LABEL_20:
        if ( _R11 == v7 )
          return;
      }
    }
  }
}


// ========================================================================
// mgringbuf_put_with_timedelay
// EA  : 0x83233528
// RVA : 0x01233528
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgringbuf.c
// ========================================================================

void __fastcall mgringbuf_put_with_timedelay(
        MGRINGBUF *ringbuf,
        char *buffer,
        size_t size,
        unsigned __int64 *timedelay)
{
  int v8; // r24
  char *volatile v10; // r31
  unsigned int v11; // r10
  unsigned int v12; // r11
  char v16; // cr34
  char *v17; // r4
  char *start; // r3
  char *v19; // r30
  size_t v20; // r5
  void *v21; // r3
  unsigned __int64 v22; // r11
  char v26; // cr34

  v8 = ((int (*)(void))mgtimestamp_now)();
  if ( size != 0 )
  {
    _R9 = &ringbuf->write;
    do
    {
      do
      {
        v10 = *_R9;
        v11 = ringbuf->size;
        v12 = *_R9 - ringbuf->get;
        if ( v12 >= v11 )
          v12 += v11;
      }
      while ( v11 - v12 - 1 < size );
      _R29 = (unsigned int)&v10[size - v11];
      if ( &v10[size] < ringbuf->end )
        _R29 = (unsigned int)&v10[size];
      while ( 1 )
      {
        __asm
        {
          mfmsr     r10
          mtmsree   r13
          lwarx     r11, 0, r9
        }
        if ( _R11 != v10 )
          break;
        __asm
        {
          stwcx.    r29, 0, r9
          mtmsree   r10
        }
        if ( v16 != 0 )
          goto LABEL_12;
      }
      __asm
      {
        stwcx.    r11, 0, r9
        mtmsree   r10
      }
LABEL_12:
      ;
    }
    while ( _R11 != v10 );
    v17 = buffer;
    start = *_R9;
    if ( _R29 >= (unsigned int)v10 )
    {
      v20 = size;
    }
    else
    {
      v19 = (char *)(ringbuf->end - (char *)v10);
      memcpy(Dst: start, Src: buffer, Size: (size_t)v19);
      start = ringbuf->start;
      v20 = size - (_DWORD)v19;
      v17 = &buffer[(_DWORD)v19];
    }
    v21 = memcpy(Dst: start, Src: v17, Size: v20);
    LODWORD(v22) = v8 - mgtimestamp_now(a1: v21);
    *timedelay = v22;
    __lwsync();
    _R10 = &ringbuf->put;
    while ( 1 )
    {
      __asm
      {
        mfmsr     r9
        mtmsree   r13
        lwarx     r11, 0, r10
      }
      if ( _R11 == v10 )
      {
        __asm
        {
          stwcx.    r29, 0, r10
          mtmsree   r9
        }
        if ( v26 != 0 )
          goto LABEL_21;
      }
      else
      {
        __asm
        {
          stwcx.    r11, 0, r10
          mtmsree   r9
        }
LABEL_21:
        if ( _R11 == v10 )
          return;
      }
    }
  }
}


// ========================================================================
// mgringbuf_get
// EA  : 0x83233660
// RVA : 0x01233660
// PDB : w:\tech5\libs\mgrd\shared\mgsys\mgringbuf.c
// ========================================================================

unsigned int __fastcall mgringbuf_get(MGRINGBUF *ringbuf, char *buffer, unsigned int maxsize)
{
  unsigned int size; // r9
  unsigned int v6; // r11
  unsigned int v7; // r29
  char *get; // r4
  char *end; // r10
  char *v11; // r28
  char *v12; // r3
  int v13; // r31
  size_t v14; // r5

  size = ringbuf->size;
  v6 = ringbuf->put - ringbuf->get;
  if ( v6 >= size )
    v6 += size;
  v7 = v6;
  if ( v6 == 0 )
    return 0;
  if ( maxsize < v6 )
    v7 = maxsize;
  get = ringbuf->get;
  end = ringbuf->end;
  v11 = &get[v7 - size];
  if ( &get[v7] < end )
    v11 = &get[v7];
  v12 = buffer;
  if ( v11 >= get )
  {
    v14 = v7;
  }
  else
  {
    v13 = end - get;
    memcpy(Dst: buffer, Src: get, Size: end - get);
    get = ringbuf->start;
    v14 = v7 - v13;
    v12 = &buffer[v13];
  }
  memcpy(Dst: v12, Src: get, Size: v14);
  __lwsync();
  ringbuf->get = v11;
  return v7;
}

