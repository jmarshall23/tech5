
// ========================================================================
// ??0idBitBlockAllocator@@QAA@HH@Z
// EA  : 0x82F78A30
// RVA : 0x00F78A30
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

idBitBlockAllocator *__fastcall idBitBlockAllocator::idBitBlockAllocator(
        idBitBlockAllocator *this,
        int blocksWide,
        int blocksHigh)
{
  this->width = blocksWide;
  this->height = blocksHigh;
  this->bits = (unsigned __int8 *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\packing\\BitBlockAllocator.cpp(23) : TAG_VIRTUALTEXTURE",
                                    size: (blocksWide * blocksHigh + 7) / 8,
                                    tag: TAG_VIRTUALTEXTURE,
                                    zeroBuffer: true,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// ??1idBitBlockAllocator@@QAA@XZ
// EA  : 0x82F78AA0
// RVA : 0x00F78AA0
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall idBitBlockAllocator::~idBitBlockAllocator(idBitBlockAllocator *this)
{
  unsigned __int8 *bits; // r4

  bits = this->bits;
  if ( bits != nullptr )
    idMem::Free(this: &mem, ptr: bits, align: ALIGN_16);
}


// ========================================================================
// ?FillBlock@idBitBlockAllocator@@QAAXHHHH@Z
// EA  : 0x82F78AC0
// RVA : 0x00F78AC0
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall idBitBlockAllocator::FillBlock(idBitBlockAllocator *this, int x, int y, int w, int h)
{
  int i; // r29
  int v6; // r8
  int j; // ctr
  int v8; // r11

  for ( i = 0; i < h; ++i )
  {
    v6 = 0;
    if ( w > 0 )
    {
      for ( j = w; j != 0; --j )
      {
        v8 = (i + y) * this->width + v6++;
        this->bits[(v8 + x) >> 3] |= 1 << ((v8 + x) & 7);
      }
    }
  }
}


// ========================================================================
// ?FillBitBlock@idBitBlockAllocator@@QAAXHHABV1@@Z
// EA  : 0x82F78B38
// RVA : 0x00F78B38
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall idBitBlockAllocator::FillBitBlock(
        idBitBlockAllocator *this,
        int x,
        int y,
        const idBitBlockAllocator *bb)
{
  int i; // r31
  int width; // r11
  int j; // r10

  for ( i = 0; i < bb->height; ++i )
  {
    width = bb->width;
    for ( j = 0; j < bb->width; ++j )
    {
      if ( ((1 << ((width * i + j) & 7)) & bb->bits[(width * i + j) >> 3]) != 0 )
        this->bits[((i + y) * this->width + j + x) >> 3] |= 1 << (((i + y) * HIBYTE(this->width) + j + x) & 7);
      width = bb->width;
    }
  }
}


// ========================================================================
// ?TestBlock@idBitBlockAllocator@@QBA_NHHHHPAH@Z
// EA  : 0x82F78BE0
// RVA : 0x00F78BE0
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

int __fastcall idBitBlockAllocator::TestBlock(idBitBlockAllocator *this, int x, int y, int w, int h, int *fail)
{
  int v6; // r11
  int width; // r29
  int v8; // r31
  int v9; // r30
  int v10; // r28
  int v11; // r10
  int v12; // r11

  if ( (fail == nullptr || *fail < x || *fail - x >= w || (v6 = fail[1]) < y || v6 - y >= h) && x >= 0 && y >= 0 )
  {
    width = this->width;
    if ( x + w <= this->width && y + h <= this->height )
    {
      v8 = width * y + x;
      v9 = 0;
      if ( h <= 0 )
        return 1;
      v10 = w - 1;
      while ( 1 )
      {
        v11 = w - 1;
        if ( v10 >= 0 )
          break;
LABEL_16:
        ++v9;
        v8 += width;
        if ( v9 >= h )
          return 1;
      }
      v12 = v10 + v8;
      while ( ((1 << (v12 & 7)) & this->bits[v12 >> 3]) == 0 )
      {
        --v11;
        --v12;
        if ( v11 < 0 )
          goto LABEL_16;
      }
      if ( fail != nullptr )
      {
        *fail = v11 + x;
        fail[1] = v9 + y;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?TestBitBlock@idBitBlockAllocator@@QBA_NHHABV1@@Z
// EA  : 0x82F78CE0
// RVA : 0x00F78CE0
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

int __fastcall idBitBlockAllocator::TestBitBlock(
        idBitBlockAllocator *this,
        int x,
        int y,
        const idBitBlockAllocator *bb)
{
  int width; // r31
  int v5; // r29
  int height; // r28
  int v8; // r30
  int v9; // r8
  int v10; // r9
  int v11; // r10

  width = bb->width;
  v5 = this->width;
  if ( bb->width + x > this->width )
    return 0;
  height = bb->height;
  if ( height + y > this->height )
    return 0;
  v8 = 0;
  if ( height > 0 )
  {
    v9 = 0;
    v10 = v5 * y + x;
    while ( 1 )
    {
      v11 = 0;
      if ( width > 0 )
        break;
LABEL_10:
      ++v8;
      v10 += v5;
      v9 += width;
      if ( v8 >= height )
        return 1;
    }
    while ( ((1 << ((v9 + v11) & 7)) & bb->bits[(v9 + v11) >> 3]) == 0
         || (this->bits[(v10 + v11) >> 3] & (1 << ((v10 + v11) & 7))) == 0 )
    {
      if ( ++v11 >= width )
        goto LABEL_10;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?FindBlockLinear@idBitBlockAllocator@@QAA_NAAH0HH@Z
// EA  : 0x82F78DB0
// RVA : 0x00F78DB0
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

int __fastcall idBitBlockAllocator::FindBlockLinear(idBitBlockAllocator *this, int *x, int *y, int w, int h)
{
  int width; // r11
  int height; // r9
  int v11; // r26
  int v12; // r27
  int v13; // r5
  int v14; // r4
  char v15; // r11
  int v16; // r10
  int v17; // r10
  int v19[20]; // [sp+50h] [-50h] BYREF

  width = this->width;
  if ( w > this->width )
    return 0;
  height = this->height;
  if ( h > height )
    return 0;
  v11 = height - h;
  v19[0] = -1;
  *y = 0;
  v12 = width - w;
  v19[1] = -1;
  if ( height - h < 0 )
    return 0;
  while ( 1 )
  {
    *x = 0;
    if ( v12 >= 0 )
      break;
LABEL_10:
    v17 = *y + 1;
    *y = v17;
    if ( v17 > v11 )
      return 0;
  }
  while ( 1 )
  {
    if ( (unsigned __int8)idBitBlockAllocator::TestBlock(this, x: *x, y: *y, w, h, fail: v19) != 0 )
    {
      idBitBlockAllocator::FillBlock(this, x: v14, y: v13, w, h);
      v15 = 1;
    }
    else
    {
      v15 = 0;
    }
    if ( v15 != 0 )
      return 1;
    v16 = *x + 1;
    *x = v16;
    if ( v16 > v12 )
      goto LABEL_10;
  }
}


// ========================================================================
// ?FindBitBlockLinear@idBitBlockAllocator@@QAA_NAAH0ABV1@@Z
// EA  : 0x82F78EA0
// RVA : 0x00F78EA0
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

int __fastcall idBitBlockAllocator::FindBitBlockLinear(
        idBitBlockAllocator *this,
        int *x,
        int *y,
        const idBitBlockAllocator *bb)
{
  int height; // r11
  int v8; // r10
  int v9; // r25
  int v10; // r26
  int v11; // r31
  int v12; // r30
  char v13; // r11
  int v14; // r10
  int v15; // r10

  if ( bb->width > this->width )
    return 0;
  height = bb->height;
  v8 = this->height;
  if ( height > v8 )
    return 0;
  v9 = v8 - height;
  v10 = this->width - bb->width;
  *y = 0;
  if ( v8 - height < 0 )
    return 0;
  while ( 1 )
  {
    *x = 0;
    if ( v10 >= 0 )
      break;
LABEL_10:
    v15 = *y + 1;
    *y = v15;
    if ( v15 > v9 )
      return 0;
  }
  while ( 1 )
  {
    v11 = *y;
    v12 = *x;
    if ( (unsigned __int8)idBitBlockAllocator::TestBitBlock(this, x: *x, y: *y, bb) != 0 )
    {
      idBitBlockAllocator::FillBitBlock(this, x: v12, y: v11, bb);
      v13 = 1;
    }
    else
    {
      v13 = 0;
    }
    if ( v13 != 0 )
      return 1;
    v14 = *x + 1;
    *x = v14;
    if ( v14 > v10 )
      goto LABEL_10;
  }
}


// ========================================================================
// ?SeparateBits@@YAXHAAH0@Z
// EA  : 0x82F78F90
// RVA : 0x00F78F90
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall SeparateBits(int bits, int *x, int *y)
{
  char v3; // r11
  int v4; // r9
  int i; // ctr

  v3 = 0;
  *x = 0;
  *y = 0;
  v4 = 1;
  for ( i = 16; i != 0; --i )
  {
    if ( ((1 << v3) & bits) != 0 )
      *x |= v4;
    if ( ((2 << v3) & bits) != 0 )
      *y |= v4;
    v3 += 2;
    v4 = __ROL4__(v4, 1);
  }
}


// ========================================================================
// ?SeparateBits2@@YAXHAAH0@Z
// EA  : 0x82F78FF8
// RVA : 0x00F78FF8
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall SeparateBits2(int bits, int *x, int *y)
{
  *x = ((((((((((((((((((((((((((((bits & 0x10000000 | (bits >> 1) & 0x20000000) >> 1) | bits & 0x4000000) >> 1)
                             | bits & 0x1000000) >> 1)
                           | bits & 0x400000) >> 1)
                         | bits & 0x100000) >> 1)
                       | bits & 0x40000) >> 1)
                     | bits & 0x10000) >> 1)
                   | bits & 0x4000) >> 1)
                 | bits & 0x1000) >> 1)
               | bits & 0x400) >> 1)
             | bits & 0x100) >> 1)
           | bits & 0x40) >> 1)
         | bits & 0x10) >> 1)
       | bits & 4) >> 1)
     | bits & 1;
  *y = ((((((((((((((((((((((((((((bits & 0x8000000 | (bits >> 1) & 0x10000000) >> 1) | bits & 0x2000000) >> 1)
                             | bits & 0x800000) >> 1)
                           | bits & 0x200000) >> 1)
                         | bits & 0x80000) >> 1)
                       | bits & 0x20000) >> 1)
                     | bits & 0x8000) >> 1)
                   | bits & 0x2000) >> 1)
                 | bits & 0x800) >> 1)
               | bits & 0x200) >> 1)
             | bits & 0x80) >> 1)
           | bits & 0x20) >> 1)
         | bits & 8) >> 1)
       | bits & 2) >> 1)
     | (bits >> 16) & 0x8000;
}


// ========================================================================
// ?TestSeparateBits_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F79178
// RVA : 0x00F79178
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall TestSeparateBits_f(const idCmdArgs *args)
{
  int i; // r31
  __int64 v2; // r6
  __int64 v3; // r4
  int v4; // r11
  __int64 v5; // r10
  __int64 v6; // r8
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  int v11; // [sp+50h] [-30h] BYREF
  int v12; // [sp+54h] [-2Ch] BYREF
  int v13; // [sp+58h] [-28h] BYREF
  int v14[3]; // [sp+5Ch] [-24h] BYREF

  for ( i = 0; i != 0x7FFFFFFF; ++i )
  {
    SeparateBits(bits: i, x: &v13, y: v14);
    SeparateBits2(bits: i, x: &v11, y: &v12);
    v4 = 0;
    LODWORD(v5) = &v11;
    HIDWORD(v5) = &v13;
    do
    {
      LODWORD(v6) = v14[v4 - 1];
      HIDWORD(v6) = *(int *)((char *)&v11 + v4 * 4);
      if ( (_DWORD)v6 != HIDWORD(v6) )
      {
        HIDWORD(v3) = "TestSeparateBits failed";
        idLib::FatalError(fmt: v3, a2: v2, a3: v6, a4: v5, a5: v7, a6: v8, a7: v9, a8: v10);
        JUMPOUT(0x82F79210);
      }
      ++v4;
    }
    while ( v4 < 2 );
  }
}


// ========================================================================
// ?TestMaskBlock_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F79218
// RVA : 0x00F79218
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall TestMaskBlock_f(const idCmdArgs *args)
{
  unsigned __int8 *v1; // r29
  unsigned __int8 v2; // r8
  unsigned __int8 v3; // r11
  unsigned __int8 *v4; // r30
  unsigned __int8 v5; // r8
  unsigned __int8 *v6; // r23
  int i; // r24
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r4
  int v16; // [sp+8h] [-D8h]
  int v17; // [sp+8h] [-D8h]
  int v18; // [sp+Ch] [-D4h]
  int v19; // [sp+Ch] [-D4h]
  int v20; // [sp+10h] [-D0h]
  int v21; // [sp+10h] [-D0h]
  int v22; // [sp+14h] [-CCh]
  int v23; // [sp+14h] [-CCh]
  int v24; // [sp+50h] [-90h] BYREF
  unsigned int v25; // [sp+54h] [-8Ch] BYREF
  idBitBlockAllocator v26; // [sp+58h] [-88h] BYREF
  idBitBlockAllocator v27; // [sp+68h] [-78h] BYREF
  idBitBlockAllocator v28; // [sp+78h] [-68h] BYREF

  v27.width = 3;
  v27.height = 3;
  v1 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\packing\\BitBlockAllocator.cpp(23) : TAG_VIRTUALTEXTURE",
                            size: 2u,
                            tag: TAG_VIRTUALTEXTURE,
                            zeroBuffer: true,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v27.bits = v1;
  v2 = *v1;
  v28.width = 3;
  v28.height = 3;
  *v1 = v2 | 1;
  v3 = *v1 | 6;
  *v1 = v3;
  v3 |= 8u;
  *v1 = v3;
  *v1 = v3 | 0x10;
  *v1 = v3 | 0x50;
  v4 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\packing\\BitBlockAllocator.cpp(23) : TAG_VIRTUALTEXTURE",
                            size: 2u,
                            tag: TAG_VIRTUALTEXTURE,
                            zeroBuffer: true,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v28.bits = v4;
  v5 = *v4;
  v26.height = 3;
  v26.width = 12;
  *v4 = v5 | 4;
  *v4 = v5 | 0x14;
  *v4 = v5 | 0x34;
  *v4 = v5 | 0x74;
  *v4 = v5 | 0xF4;
  v4[1] |= 1u;
  v6 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\packing\\BitBlockAllocator.cpp(23) : TAG_VIRTUALTEXTURE",
                            size: 5u,
                            tag: TAG_VIRTUALTEXTURE,
                            zeroBuffer: true,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v26.bits = v6;
  for ( i = 5; i != 0; --i )
  {
    if ( (unsigned __int8)idBitBlockAllocator::FindBitBlockLinear(this: &v26, x: (int *)&v25, y: &v24, bb: &v27) != 0 )
    {
      HIDWORD(v10) = v24;
      idLib::Printf(
        fmt: __SPAIR64__("Upper: %i, %i\n", v25),
        a2: v10,
        a3: v9,
        a4: v8,
        a5: v16,
        a6: v18,
        a7: v20,
        a8: v22);
    }
    else
    {
      HIDWORD(v11) = "Failed.\n";
      idLib::Printf(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v16, a6: v18, a7: v20, a8: v22);
    }
    if ( (unsigned __int8)idBitBlockAllocator::FindBitBlockLinear(this: &v26, x: (int *)&v25, y: &v24, bb: &v28) != 0 )
    {
      HIDWORD(v14) = v24;
      idLib::Printf(
        fmt: __SPAIR64__("Lower: %i, %i\n", v25),
        a2: v14,
        a3: v13,
        a4: v12,
        a5: v17,
        a6: v19,
        a7: v21,
        a8: v23);
    }
    else
    {
      HIDWORD(v15) = "Failed.\n";
      idLib::Printf(fmt: v15, a2: v14, a3: v13, a4: v12, a5: v17, a6: v19, a7: v21, a8: v23);
    }
  }
  if ( v6 != nullptr )
    idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$111559
// EA  : 0x82F79430
// RVA : 0x00F79430
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void _unwind_111559()
{
  int v0; // r12

  idBitBlockAllocator::~idBitBlockAllocator(this: (idBitBlockAllocator *)(v0 - 224 + 104));
}


// ========================================================================
// __unwind$111560
// EA  : 0x82F79458
// RVA : 0x00F79458
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void _unwind_111560()
{
  int v0; // r12

  idBitBlockAllocator::~idBitBlockAllocator(this: (idBitBlockAllocator *)(v0 - 224 + 120));
}


// ========================================================================
// __unwind$111561
// EA  : 0x82F79480
// RVA : 0x00F79480
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void _unwind_111561()
{
  int v0; // r12

  idBitBlockAllocator::~idBitBlockAllocator(this: (idBitBlockAllocator *)(v0 - 224 + 88));
}


// ========================================================================
// ?FindBlockInterleaved@idBitBlockAllocator@@QAA_NAAH0HH0_N@Z
// EA  : 0x82F794A8
// RVA : 0x00F794A8
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idBitBlockAllocator::FindBlockInterleaved(
        idBitBlockAllocator *this,
        int *x,
        int *y,
        int w,
        int h,
        int *searchPoint,
        bool naturallyAlign)
{
  int v7; // r2 OVERLAPPED
  bool v14; // cr56
  int v15; // r3
  int v16; // r6
  int v17; // r3
  char v18; // r25
  __int64 v19; // r5
  int v20; // r8
  int v21; // r23
  BOOL v22; // r22
  int v23; // r7
  int v24; // r5
  int v25; // r4
  char v26; // r11
  int v27; // r10
  int v29; // [sp+50h] [-70h]
  float v30; // [sp+50h] [-70h]
  int v31[26]; // [sp+58h] [-68h] BYREF

  if ( w > this->width || h > this->height )
    return 0;
  v14 = *searchPoint < 0;
  v31[0] = -1;
  v31[1] = -1;
  v15 = ((((w - 1) >> 1) | (w - 1)) >> 2) | ((w - 1) >> 1) | (w - 1);
  v16 = (((v15 >> 4) | v15) >> 8) | (v15 >> 4) | v15;
  v17 = ((v16 >> 16) | v16) + 1;
  *(float *)&v29 = (float)*(__int64 *)(&v7 - 1);
  v18 = (v29 >> 23) - 127;
  HIDWORD(v19) = ((((h - 1) >> 1) | (h - 1)) >> 2) | ((h - 1) >> 1) | (h - 1);
  v20 = (((SHIDWORD(v19) >> 4) | HIDWORD(v19)) >> 8) | (SHIDWORD(v19) >> 4) | HIDWORD(v19);
  LODWORD(v19) = ((v20 >> 16) | v20) + 1;
  v30 = (float)v19;
  if ( v14 )
    *searchPoint = 0;
  v21 = this->height * this->width;
  if ( *searchPoint >= v21 )
    return 0;
  v22 = naturallyAlign;
  while ( v22 )
  {
    SeparateBits2(bits: *searchPoint, x, y);
    if ( *x >> v18 == (*x + w - 1) >> v18
      && *y >> ((SLODWORD(v30) >> 23) - 127) == (*y + h - 1) >> ((SLODWORD(v30) >> 23) - 127) )
    {
      goto LABEL_12;
    }
LABEL_16:
    v27 = *searchPoint + 1;
    *searchPoint = v27;
    if ( v27 >= v21 )
      return 0;
  }
  SeparateBits2(bits: (*searchPoint >> 1) ^ *searchPoint, x, y);
LABEL_12:
  if ( (unsigned __int8)idBitBlockAllocator::TestBlock(this, x: *x, y: *y, w, h, fail: v31) != 0 )
  {
    idBitBlockAllocator::FillBlock(this, x: v25, y: v24, w, h: v23);
    v26 = 1;
  }
  else
  {
    v26 = 0;
  }
  if ( v26 == 0 )
    goto LABEL_16;
  return 1;
}


// ========================================================================
// ?Regression_idBitBlockAllocator_f_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F796B8
// RVA : 0x00F796B8
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void __fastcall Regression_idBitBlockAllocator_f_f(const idCmdArgs *args)
{
  void *v1; // r3
  void *v2; // r30
  int v3; // r8
  int v4; // r11
  int i; // ctr
  int v6; // r9
  char v7; // r10
  int v8; // r29
  unsigned __int8 *v9; // r27
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r4
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r4
  int v18; // [sp+8h] [-B8h]
  int v19; // [sp+Ch] [-B4h]
  int v20; // [sp+10h] [-B0h]
  int v21; // [sp+14h] [-ACh]
  int v22; // [sp+50h] [-70h] BYREF
  int v23; // [sp+54h] [-6Ch] BYREF
  int v24[2]; // [sp+58h] [-68h] BYREF
  idBitBlockAllocator v25; // [sp+60h] [-60h] BYREF
  int v26; // [sp+70h] [-50h]
  int v27; // [sp+74h] [-4Ch]
  void *v28; // [sp+78h] [-48h]

  v26 = 100;
  v27 = 100;
  v1 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\packing\\BitBlockAllocator.cpp(23) : TAG_VIRTUALTEXTURE",
         size: 0x4E2u,
         tag: TAG_VIRTUALTEXTURE,
         zeroBuffer: true,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  v28 = v1;
  v3 = 1515;
  v23 = 0;
  v24[0] = 0;
  do
  {
    v4 = 0;
    for ( i = 21; i != 0; --i )
    {
      v6 = (v3 + v4) >> 3;
      v7 = (v3 + v4++) & 7;
      *((_BYTE *)v1 + v6) &= ~(1 << v7);
    }
    v3 += 100;
  }
  while ( v3 < 3615 );
  if ( v1 != nullptr )
    memset(Dst: v1, Val: 0, Size: 0x4E2u);
  v8 = 256;
  v25.width = 256;
  v25.height = 256;
  v9 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\packing\\BitBlockAllocator.cpp(23) : TAG_VIRTUALTEXTURE",
                            size: 0x2000u,
                            tag: TAG_VIRTUALTEXTURE,
                            zeroBuffer: true,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v25.bits = v9;
  v22 = 0;
  do
  {
    if ( (unsigned __int8)idBitBlockAllocator::FindBlockInterleaved(
                            this: &v25,
                            x: v24,
                            y: &v23,
                            w: 16,
                            h: 16,
                            searchPoint: &v22,
                            naturallyAlign: false) == 0 )
    {
      HIDWORD(v13) = "Failed.\n";
      idLib::Printf(fmt: v13, a2: v12, a3: v11, a4: v10, a5: v18, a6: v19, a7: v20, a8: v21);
    }
    --v8;
  }
  while ( v8 != 0 );
  if ( (unsigned __int8)idBitBlockAllocator::FindBlockInterleaved(
                          this: &v25,
                          x: v24,
                          y: &v23,
                          w: 16,
                          h: 16,
                          searchPoint: &v22,
                          naturallyAlign: false) != 0 )
  {
    HIDWORD(v17) = "Failed.\n";
    idLib::Printf(fmt: v17, a2: v16, a3: v15, a4: v14, a5: v18, a6: v19, a7: v20, a8: v21);
  }
  HIDWORD(v17) = "Passed.\n";
  idLib::Printf(fmt: v17, a2: v16, a3: v15, a4: v14, a5: v18, a6: v19, a7: v20, a8: v21);
  if ( v9 != nullptr )
    idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
  if ( v2 != nullptr )
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
}


// ========================================================================
// __unwind$111884_0
// EA  : 0x82F79868
// RVA : 0x00F79868
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void _unwind_111884_0()
{
  int v0; // r12

  idBitBlockAllocator::~idBitBlockAllocator(this: (idBitBlockAllocator *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$111885
// EA  : 0x82F79890
// RVA : 0x00F79890
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

void _unwind_111885()
{
  int v0; // r12

  idBitBlockAllocator::~idBitBlockAllocator(this: (idBitBlockAllocator *)(v0 - 192 + 96));
}


// ========================================================================
// `dynamic initializer for 'TestSeparateBits_v''
// EA  : 0x83396788
// RVA : 0x01396788
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestSeparateBits_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestSeparateBits_v,
           cmdName: "TestSeparateBits",
           function: TestSeparateBits_f,
           description: "function test",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestMaskBlock_v''
// EA  : 0x833967B0
// RVA : 0x013967B0
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestMaskBlock_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestMaskBlock_v,
           cmdName: "TestMaskBlock",
           function: TestMaskBlock_f,
           description: "idBitBlockAllocator test",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Regression_idBitBlockAllocator_f_v''
// EA  : 0x833967D8
// RVA : 0x013967D8
// PDB : w:\tech5\shared\idlib\packing\bitblockallocator.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Regression_idBitBlockAllocator_f_v__()
{
  return idCommandLink::idCommandLink(
           this: &Regression_idBitBlockAllocator_f_v,
           cmdName: "Regression_idBitBlockAllocator_f",
           function: Regression_idBitBlockAllocator_f_f,
           description: "regression check",
           argCompletion: nullptr);
}

