
// ========================================================================
// ?ReadU@idSWFBitStream@@QAAII@Z
// EA  : 0x8276DC98
// RVA : 0x0076DC98
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

unsigned int __fastcall idSWFBitStream::ReadU(idSWFBitStream *this, unsigned __int64 numBits, unsigned __int64 a3)
{
  unsigned __int64 currentBit; // r9
  unsigned __int64 v4; // r11
  int v5; // r6
  int v6; // r7
  unsigned __int64 currentByte; // r5

  currentBit = this->currentBit;
  LODWORD(a3) = HIDWORD(numBits) - currentBit + 7;
  v4 = a3 >> 3;
  LODWORD(numBits) = 8 * (a3 >> 3) - HIDWORD(numBits) + currentBit;
  this->currentBit = numBits;
  if ( (unsigned int)(a3 >> 3) != 0 )
  {
    do
    {
      v5 = this->readp[HIDWORD(v4)++];
      LODWORD(numBits) = v5 | (LODWORD(this->currentByte) << 8);
      this->currentByte = numBits;
    }
    while ( HIDWORD(v4) < (unsigned int)v4 );
  }
  v6 = HIDWORD(numBits);
  this->readp += v4;
  currentByte = this->currentByte;
  HIDWORD(currentByte) = maskForNumBits[v6];
  return (currentByte >> this->currentBit) & HIDWORD(currentByte);
}


// ========================================================================
// ?ReadS@idSWFBitStream@@QAAHI@Z
// EA  : 0x8276DD28
// RVA : 0x0076DD28
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

int __fastcall idSWFBitStream::ReadS(idSWFBitStream *this, unsigned __int64 numBits, unsigned __int64 a3)
{
  unsigned __int64 currentBit; // r9
  unsigned __int64 v4; // r11
  int v5; // r6
  unsigned __int64 currentByte; // r4

  currentBit = this->currentBit;
  LODWORD(a3) = HIDWORD(numBits) - currentBit + 7;
  v4 = a3 >> 3;
  LODWORD(numBits) = 8 * (a3 >> 3) - HIDWORD(numBits) + currentBit;
  this->currentBit = numBits;
  if ( (unsigned int)(a3 >> 3) != 0 )
  {
    do
    {
      v5 = this->readp[HIDWORD(v4)++];
      LODWORD(numBits) = v5 | (LODWORD(this->currentByte) << 8);
      this->currentByte = numBits;
    }
    while ( HIDWORD(v4) < (unsigned int)v4 );
  }
  this->readp += v4;
  currentByte = this->currentByte;
  return (((currentByte >> *(_QWORD *)(HIDWORD(currentByte) + 16))
         & *(int *)((char *)maskForNumBits + *(_DWORD *)(HIDWORD(currentByte) + 16)))
        + *(int *)((char *)signForNumBits + *(_DWORD *)(HIDWORD(currentByte) + 16)))
       ^ *(int *)((char *)signForNumBits + *(_DWORD *)(HIDWORD(currentByte) + 16));
}


// ========================================================================
// ?ReadMatrix@idSWFBitStream@@QAAXAAUswfMatrix_t@@@Z
// EA  : 0x8276DDD0
// RVA : 0x0076DDD0
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWFBitStream::ReadMatrix(idSWFBitStream *this, swfMatrix_t *matrix)
{
  const unsigned __int8 *readp; // r9
  unsigned __int64 v4; // r11 OVERLAPPED
  __int128 v5; // r9 OVERLAPPED
  const unsigned __int8 *v6; // r5
  int v7; // r9
  int v8; // r31
  int v9; // r5 OVERLAPPED
  int v10; // r30
  const unsigned __int8 *v11; // r30
  int v12; // r10
  unsigned int v13; // r31
  int v14; // r8
  int v15; // r5
  const unsigned __int8 *v16; // r5
  const unsigned __int8 *v17; // r30
  int v18; // r31
  unsigned int v19; // r5 OVERLAPPED
  const unsigned __int8 *v20; // r30
  unsigned int v21; // r31
  int v22; // r5
  int v23; // r29
  int v24; // r5
  const unsigned __int8 *v25; // r31
  int v26; // r5
  int v27; // r30
  const unsigned __int8 *v28; // r30
  unsigned int v30; // r31
  int v31; // r29
  _DWORD back_chain[4]; // [sp+0h] [-70h] BYREF
  int i; // [sp+10h] [-60h] BYREF
  int v42; // [sp+14h] [-5Ch]
  int v43; // [sp+18h] [-58h]
  int v44; // [sp+1Ch] [-54h]
  _DWORD v45[20]; // [sp+20h] [-50h] BYREF

  readp = this->readp;
  v4 = 0;
  do
  {
    *(_QWORD *)&v5 = v4 << 8;
    LODWORD(v4) = readp[HIDWORD(v4)++] | ((_DWORD)v4 << 8);
  }
  while ( HIDWORD(v4) == 0 );
  HIDWORD(v4) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
  v6 = readp + 1;
  this->readp = readp + 1;
  v7 = v4 >> 7;
  HIDWORD(v4) = maskForNumBits[1];
  if ( (v7 & maskForNumBits[1]) != 0 )
  {
    this->readp = v6;
    v8 = (v4 >> 2) & *(_DWORD *)((v4 >> 2 >> 32) + 20);
    DWORD2(v5) = v8;
    *(unsigned __int64 *)((char *)&v4 + 4) = (unsigned __int64)(unsigned int)(v8 + 5) >> 3;
    *(_QWORD *)((char *)&v5 + 12) = 8 * *(unsigned __int64 *)((char *)&v4 + 4);
    HIDWORD(v5) = 8 * HIDWORD(v4) - v8 + 2;
    if ( HIDWORD(v4) != 0 )
    {
      do
      {
        v10 = *(unsigned __int8 *)(v9 + v5);
        LODWORD(v5) = v5 + 1;
        v4 <<= 8;
        LODWORD(v4) = v10 | v4;
      }
      while ( (unsigned int)v5 < HIDWORD(v4) );
    }
    LODWORD(v5) = 4 * v8;
    v11 = &this->readp[HIDWORD(v4)];
    this->readp = v11;
    v12 = v8 - HIDWORD(v5) + 7;
    *(unsigned __int64 *)((char *)&v4 + 4) = *(_QWORD *)((char *)&v5 - 4) >> 3;
    v13 = 0;
    HIDWORD(v5) += 8 * HIDWORD(v4) - DWORD2(v5);
    if ( HIDWORD(v4) != 0 )
    {
      do
      {
        v14 = v11[v13++];
        LODWORD(v4) = v14 | ((_DWORD)v4 << 8);
      }
      while ( v13 < HIDWORD(v4) );
    }
    this->readp += HIDWORD(v4);
  }
  back_chain[3] = 0;
  back_chain[2] = 0;
  *(_QWORD *)((char *)&v5 + 4) = (unsigned __int64)(unsigned int)(8 - HIDWORD(v5)) >> 3;
  *(_QWORD *)((char *)&v5 - 4) = 8LL * *(_QWORD *)((char *)&v5 + 4);
  HIDWORD(v4) = 8 * DWORD2(v5) + HIDWORD(v5) - 1;
  if ( DWORD2(v5) != 0 )
  {
    do
    {
      v15 = this->readp[v5];
      LODWORD(v5) = v5 + 1;
      v4 <<= 8;
      LODWORD(v4) = v15 | v4;
    }
    while ( (unsigned int)v5 < DWORD2(v5) );
  }
  v16 = &this->readp[DWORD2(v5)];
  *(_QWORD *)((char *)&v5 + 4) = v4 >> SBYTE3(v4);
  this->readp = v16;
  if ( ((unsigned int)(v4 >> SBYTE3(v4)) & *(_DWORD *)((v4 >> SBYTE3(v4) >> 32) + 4)) != 0 )
  {
    LODWORD(v5) = 12 - HIDWORD(v4);
    HIDWORD(v5) = 0;
    *((_QWORD *)&v5 + 1) = (unsigned __int64)v5 >> 3;
    *(_QWORD *)((char *)&v5 + 4) = 8 * v5;
    for ( BYTE11(v5) = BYTE11(v5) + BYTE3(v4) - 5;
          HIDWORD(v5) < (unsigned int)v5;
          LODWORD(v4) = (v4 >> 24) | ((_DWORD)v4 << 8) )
    {
      HIDWORD(v4) = v16[HIDWORD(v5)++];
    }
    HIDWORD(v4) = v5;
    v17 = &this->readp[v5];
    *((_QWORD *)&v5 + 1) = v4 >> SBYTE11(v5);
    this->readp = v17;
    v18 = v5 & *(_DWORD *)(DWORD1(v5) + 20);
    HIDWORD(v4) = v18;
    LODWORD(v5) = v18 - DWORD2(v5) + 7;
    *((_QWORD *)&v5 + 1) = (unsigned __int64)v5 >> 3;
    *(_QWORD *)((char *)&v5 + 12) = 8 * v5;
    HIDWORD(v5) = 8 * v5 - v18 + DWORD2(v5);
    if ( (_DWORD)v5 != 0 )
    {
      do
      {
        DWORD2(v5) = v17[v19++];
        v4 <<= 8;
        LODWORD(v4) = DWORD2(v5) | v4;
      }
      while ( v19 < (unsigned int)v5 );
    }
    DWORD2(v5) = 4 * v18;
    v20 = &this->readp[v5];
    this->readp = v20;
    LODWORD(v5) = HIDWORD(v4) - HIDWORD(v5) + 7;
    *((_QWORD *)&v5 + 1) = (unsigned __int64)v5 >> 3;
    v21 = 0;
    v22 = *(int *)((char *)signForNumBits + DWORD2(v5));
    v23 = ((v4 >> SBYTE3(v5)) & *(_DWORD *)(DWORD2(v5) + DWORD1(v5))) + v22;
    HIDWORD(v4) = 8 * v5 - HIDWORD(v4) + HIDWORD(v5);
    for ( i = v23 ^ v22; v21 < (unsigned int)v5; LODWORD(v4) = HIDWORD(v5) | ((_DWORD)v4 << 8) )
      HIDWORD(v5) = v20[v21++];
    this->readp += v5;
    v42 = (((v4 >> SBYTE3(v4)) & *(_DWORD *)(DWORD2(v5) + DWORD1(v5))) + *(int *)((char *)signForNumBits + DWORD2(v5)))
        ^ *(int *)((char *)signForNumBits + DWORD2(v5));
  }
  else
  {
    i = 0;
    v42 = 0;
  }
  v44 = 0;
  v43 = 0;
  *((_QWORD *)&v5 + 1) = (unsigned __int64)(unsigned int)(12 - HIDWORD(v4)) >> 3;
  HIDWORD(v5) = 8 * v5 + HIDWORD(v4) - 5;
  if ( (_DWORD)v5 != 0 )
  {
    HIDWORD(v4) = this->readp;
    do
    {
      v24 = *(unsigned __int8 *)(HIDWORD(v4) + DWORD2(v5)++);
      v4 <<= 8;
      LODWORD(v4) = v24 | v4;
    }
    while ( DWORD2(v5) < (unsigned int)v5 );
  }
  HIDWORD(v4) = v5;
  v25 = (const unsigned __int8 *)(v5 + (v4 >> SBYTE3(v5) >> 32));
  this->readp = v25;
  v26 = (v4 >> SBYTE3(v5)) & *(_DWORD *)(DWORD1(v5) + 20);
  HIDWORD(v4) = v26;
  *((_QWORD *)&v5 + 1) = (unsigned __int64)(unsigned int)(v26 - HIDWORD(v5) + 7) >> 3;
  HIDWORD(v5) += 8 * v5 - v26;
  if ( (_DWORD)v5 != 0 )
  {
    do
    {
      v27 = v25[DWORD2(v5)++];
      v4 <<= 8;
      LODWORD(v4) = v27 | v4;
    }
    while ( DWORD2(v5) < (unsigned int)v5 );
  }
  DWORD2(v5) = 4 * v26;
  v28 = &this->readp[v5];
  this->readp = v28;
  _R5 = v4 >> SBYTE3(v5);
  LODWORD(v5) = HIDWORD(v4) - HIDWORD(v5) + 7;
  v30 = 0;
  *((_QWORD *)&v5 + 1) = (unsigned __int64)v5 >> 3;
  v31 = (v4 >> SBYTE3(v5)) & *(_DWORD *)(DWORD2(v5) + DWORD1(v5));
  HIDWORD(v5) += 8 * v5 - HIDWORD(v4);
  v45[0] = (v31 + *(int *)((char *)signForNumBits + DWORD2(v5))) ^ *(int *)((char *)signForNumBits + DWORD2(v5));
  if ( (_DWORD)v5 != 0 )
  {
    do
    {
      HIDWORD(v4) = v28[v30++];
      _R5 = v4 << 8;
      LODWORD(v4) = HIDWORD(v4) | ((_DWORD)v4 << 8);
    }
    while ( v30 < (unsigned int)v5 );
  }
  HIDWORD(v4) = v5;
  this->readp += v5;
  LODWORD(_R5) = v45;
  v45[2] = 0;
  _R31 = back_chain;
  v45[3] = 0;
  _R29 = &i;
  _R30 = &vmx_float_one_over_20;
  _R28 = 4;
  __asm { lvx128    v63, r0, r31 }
  _R31 = 12;
  __asm
  {
    vcsxwfp128 v62, v63, 0x10
    lvx128    v61, r0, r29
  }
  _R29 = 16;
  __asm
  {
    lvx128    v63, r0, r30
    vcsxwfp128 v60, v61, 0x10
  }
  _R30 = 20;
  __asm { vspltw128 v59, v62, 0 }
  __asm { vspltw128 v58, v62, 1 }
  HIDWORD(v4) = *(int *)((char *)signForNumBits + (v4 >> SBYTE3(v5) >> 32));
  this->currentBit = *(_QWORD *)((char *)&v5 + 12);
  __asm { vspltw128 v57, v60, 0 }
  _R27 = 8;
  __asm { vspltw128 v56, v60, 1 }
  this->currentByte = v4;
  __asm
  {
    lvx128    v55, r0, r5
    vcsxwfp128 v54, v55, 0
    stvewx128 v59, r0, r4
    vmulfp128 v53, v86, v63
    stvewx128 v58, r4, r28
    stvewx128 v57, r4, r31
    stvewx128 v56, r4, r27
    vspltw128 v52, v53, 0
    vspltw128 v51, v53, 1
    stvewx128 v52, r4, r29
    stvewx128 v51, r4, r30
  }
}


// ========================================================================
// ?Free@idSWFBitStream@@QAAXXZ
// EA  : 0x8276E2D8
// RVA : 0x0076E2D8
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

void __fastcall idSWFBitStream::Free(idSWFBitStream *this)
{
  unsigned __int64 v1; // r11

  if ( this->free )
    idMem::Free(this: &mem, ptr: (void *)this->startp, align: ALIGN_16);
  LODWORD(v1) = 0;
  this->free = false;
  this->startp = nullptr;
  this->endp = nullptr;
  this->readp = nullptr;
  this->currentBit = v1;
  this->currentByte = v1;
}


// ========================================================================
// ?Load@idSWFBitStream@@QAAXPBEI_N@Z
// EA  : 0x8276E340
// RVA : 0x0076E340
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

void __fastcall idSWFBitStream::Load(idSWFBitStream *this, const unsigned __int8 *data, unsigned int len, bool copy)
{
  unsigned __int64 v6; // r30
  unsigned __int8 *v8; // r3
  const unsigned __int8 *startp; // r11

  HIDWORD(v6) = len;
  if ( this->free )
    idMem::Free(this: &mem, ptr: (void *)this->startp, align: ALIGN_16);
  LODWORD(v6) = 0;
  this->free = false;
  this->startp = nullptr;
  this->endp = nullptr;
  this->readp = nullptr;
  this->currentBit = v6;
  this->currentByte = v6;
  if ( copy )
  {
    this->free = true;
    v8 = (unsigned __int8 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\guis\\swf\\SWF_Bitstream.cpp(93) : TAG_SWF",
                              size: HIDWORD(v6),
                              tag: TAG_SWF,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    this->startp = v8;
    memcpy(Dst: v8, Src: data, Size: HIDWORD(v6));
  }
  else
  {
    this->startp = data;
    this->free = false;
  }
  startp = this->startp;
  this->currentBit = v6;
  this->currentByte = v6;
  this->endp = &startp[HIDWORD(v6)];
  this->readp = startp;
}


// ========================================================================
// ?ReadData@idSWFBitStream@@QAAPBEH@Z
// EA  : 0x8276E410
// RVA : 0x0076E410
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

const unsigned __int8 *__fastcall idSWFBitStream::ReadData(
        idSWFBitStream *this,
        int size,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *result; // r3
  const unsigned __int8 *endp; // r9

  result = this->readp;
  LODWORD(a7) = 0;
  this->currentBit = a7;
  this->currentByte = a7;
  endp = this->endp;
  if ( &result[size] <= endp )
  {
    this->readp = &result[size];
  }
  else
  {
    result = this->startp;
    this->readp = endp;
  }
  return result;
}


// ========================================================================
// ?ReadRect@idSWFBitStream@@QAAXAAUswfRect_t@@@Z
// EA  : 0x8276E448
// RVA : 0x0076E448
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWFBitStream::ReadRect(idSWFBitStream *this, swfRect_t *rect)
{
  const unsigned __int8 *readp; // r9
  unsigned __int64 v3; // r11 OVERLAPPED
  int v4; // r31
  unsigned __int64 v5; // r10
  int v6; // r9 OVERLAPPED
  int v7; // r6 OVERLAPPED
  unsigned __int64 v8; // r8 OVERLAPPED
  int v9; // r30
  const unsigned __int8 *v10; // r29
  unsigned int v11; // r30
  unsigned __int64 v12; // r8
  int v13; // r31
  unsigned __int64 v14; // r29
  const unsigned __int8 *v15; // r30
  __int64 v16; // r27
  unsigned __int64 v17; // r8
  unsigned int i; // r31
  int v19; // r29
  const unsigned __int8 *v20; // r30 OVERLAPPED
  int v21; // r31
  unsigned int j; // r9
  __int64 v23; // r8 OVERLAPPED
  int v24; // r31
  const unsigned __int8 *v25; // r9
  int v26; // r31
  __int64 v27; // fp13
  __int64 v28; // fp11
  bool (__fastcall **v29)(idLobbyBackend360 *__hidden); // r6
  int v30; // r9

  readp = this->readp;
  v3 = 0;
  do
    LODWORD(v3) = readp[HIDWORD(v3)++] | ((_DWORD)v3 << 8);
  while ( HIDWORD(v3) == 0 );
  HIDWORD(v3) = &idSort_Quick<idSortedMaterial,idSort_SortedMaterial> `RTTI Type Descriptor';
  this->readp = readp + 1;
  LODWORD(v8) = 0;
  v4 = (v3 >> 3) & maskForNumBits[5];
  HIDWORD(v5) = v4;
  LODWORD(v5) = v4 + 4;
  *(unsigned __int64 *)((char *)&v3 + 4) = v5 >> 3;
  *(unsigned __int64 *)((char *)&v8 + 4) = 8 * *(unsigned __int64 *)((char *)&v3 + 4);
  HIDWORD(v8) = 8 * HIDWORD(v3) - v6 + 3;
  if ( HIDWORD(v3) != 0 )
  {
    do
    {
      v9 = *(unsigned __int8 *)(v7 + v8);
      LODWORD(v8) = v8 + 1;
      v3 <<= 8;
      LODWORD(v3) = v9 | v3;
    }
    while ( (unsigned int)v8 < HIDWORD(v3) );
  }
  v10 = &this->readp[HIDWORD(v3)];
  HIDWORD(v3) = 4 * v4;
  this->readp = v10;
  LODWORD(v8) = v6 - HIDWORD(v8) + 7;
  v12 = v8 >> 3;
  v11 = 0;
  HIDWORD(v12) += 8 * v12 - v6;
  if ( (_DWORD)v12 != 0 )
  {
    do
    {
      v13 = v10[v11++];
      v3 <<= 8;
      LODWORD(v3) = v13 | v3;
    }
    while ( v11 < (unsigned int)v12 );
  }
  LODWORD(v14) = v6 - HIDWORD(v12) + 7;
  v15 = &this->readp[v12];
  this->readp = v15;
  HIDWORD(v14) = v3 >> SBYTE3(v12);
  v17 = v14 >> 3;
  v16 = 8 * (v14 >> 3);
  HIDWORD(v17) = v16 - v6 + (v14 >> 3 >> 32);
  LODWORD(v16) = ((HIDWORD(v14) & *(int *)((char *)maskForNumBits + HIDWORD(v3)))
                + *(int *)((char *)signForNumBits + HIDWORD(v3)))
               ^ *(int *)((char *)signForNumBits + HIDWORD(v3));
  for ( i = 0; i < (unsigned int)v17; LODWORD(v3) = v19 | v3 )
  {
    v19 = v15[i++];
    v3 <<= 8;
  }
  v20 = &this->readp[v17];
  this->readp = v20;
  v21 = v6 - HIDWORD(v17) + 7;
  v23 = *(_QWORD *)(&v20 - 1) >> 3;
  HIDWORD(v23) = 8 * (*(_QWORD *)(&v20 - 1) >> 3) - v6 + (*(_QWORD *)(&v20 - 1) >> 3 >> 32);
  for ( j = 0; j < (unsigned int)v23; LODWORD(v3) = v24 | v3 )
  {
    v24 = v20[j++];
    v3 <<= 8;
  }
  v25 = &this->readp[v23];
  LODWORD(v23) = HIDWORD(v16);
  v26 = v16;
  this->readp = v25;
  v27 = v23;
  *(__int64 *)((char *)&v23 - 4) = v3 >> SBYTE3(v23);
  v28 = v23;
  v29 = &off_82350000;
  LODWORD(v23) = v3 >> SBYTE3(v23);
  HIDWORD(v3) = (*(int *)((char *)signForNumBits + HIDWORD(v3)) + (v23 & *(int *)((char *)maskForNumBits + HIDWORD(v3))))
              ^ *(int *)((char *)signForNumBits + HIDWORD(v3));
  v30 = HIDWORD(v3);
  rect->tl.x = (float)v27 * (float)0.050000001;
  rect->br.x = (float)*(__int64 *)(&v20 - 1) * (float)0.050000001;
  rect->br.y = (float)*(__int64 *)((char *)&v23 - 4) * (float)0.050000001;
  rect->tl.y = (float)v28 * (float)0.050000001;
  this->currentBit = *(__int64 *)((char *)&v23 + 4);
  this->currentByte = v3;
}


// ========================================================================
// ?ReadColorXFormRGBA@idSWFBitStream@@QAAXAAUswfColorXform_t@@@Z
// EA  : 0x8276E6D8
// RVA : 0x0076E6D8
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWFBitStream::ReadColorXFormRGBA(idSWFBitStream *this, __int64 cxf)
{
  const unsigned __int8 *readp; // r8
  unsigned __int64 v4; // r11 OVERLAPPED
  int v5; // r25
  unsigned __int64 v6; // r9 OVERLAPPED
  int v7; // r26
  unsigned __int64 v8; // r7 OVERLAPPED
  unsigned __int64 v9; // r7
  int v10; // r30
  const unsigned __int8 *v11; // r28
  __int128 v12; // r7
  unsigned int v13; // r30
  unsigned __int64 v14; // r7
  int v15; // r5
  const unsigned __int8 *v16; // r30
  unsigned __int64 v17; // r7
  int v18; // r28
  const unsigned __int8 *v19; // r30
  __int128 v20; // r7
  int v21; // r5
  unsigned __int64 v22; // r10
  unsigned int v23; // r6
  char i; // r5
  int v25; // r30
  const unsigned __int8 *v26; // r28
  __int128 v27; // r7
  int v28; // r27
  unsigned int v29; // r30
  int v30; // r26
  unsigned __int64 v31; // r7
  int v32; // r5
  const unsigned __int8 *v33; // r28
  unsigned __int64 v34; // r7
  int v35; // r27
  unsigned int v36; // r30
  const unsigned __int8 *v37; // r28
  unsigned __int64 v38; // r30
  unsigned __int64 v39; // r6
  int v40; // r27
  unsigned int v41; // kr00_4
  int v42; // r9
  int v43; // r9
  int back_chain; // [sp+0h] [-70h] BYREF
  int v49; // [sp+8h] [-68h]
  int v50; // [sp+Ch] [-64h]
  int v51; // [sp+10h] [-60h] BYREF
  int j; // [sp+14h] [-5Ch]
  int v53; // [sp+18h] [-58h]
  int v54; // [sp+1Ch] [-54h]

  readp = this->readp;
  v4 = 0;
  do
    LODWORD(v4) = readp[HIDWORD(v4)++] | ((_DWORD)v4 << 8);
  while ( HIDWORD(v4) == 0 );
  HIDWORD(v4) = readp + 1;
  this->readp = readp + 1;
  v5 = (v4 >> 7) & *(_DWORD *)((v4 >> 7 >> 32) + 4);
  this->readp = readp + 1;
  v6 = v4 >> 7;
  LODWORD(v6) = *(_DWORD *)((v4 >> 7 >> 32) + 4);
  this->readp = (const unsigned __int8 *)HIDWORD(v4);
  HIDWORD(v8) = *(_DWORD *)((v4 >> 7 >> 32) + 16);
  v7 = (v4 >> 2) & HIDWORD(v8);
  LODWORD(v8) = 2;
  if ( ((unsigned int)(v4 >> 6) & (unsigned int)v6) != 0 )
  {
    v9 = (unsigned __int64)(unsigned int)(v7 + 5) >> 3;
    if ( (_DWORD)v9 != 0 )
    {
      do
      {
        v10 = *(unsigned __int8 *)(HIDWORD(v9) + HIDWORD(v4));
        ++HIDWORD(v9);
        v4 <<= 8;
        LODWORD(v4) = v10 | v4;
      }
      while ( HIDWORD(v9) < (unsigned int)v9 );
    }
    HIDWORD(v4) = 4 * v7;
    v11 = &this->readp[v9];
    this->readp = v11;
    *(_QWORD *)((char *)&v12 + 4) = v4 >> (8 * (unsigned __int8)v9 - v7 + 2);
    LODWORD(v12) = v7 - DWORD1(v12) + 7;
    v13 = 0;
    DWORD2(v12) = signForNumBits[v7];
    v14 = (unsigned __int64)v12 >> 3;
    HIDWORD(v14) = 8 * v14 - v7 + DWORD1(v12);
    if ( (_DWORD)v14 != 0 )
    {
      do
      {
        v15 = v11[v13++];
        v4 <<= 8;
        LODWORD(v4) = v15 | v4;
      }
      while ( v13 < (unsigned int)v14 );
    }
    v16 = &this->readp[v14];
    this->readp = v16;
    cxf = v4 >> SBYTE3(v14);
    LODWORD(v14) = v7 - HIDWORD(v14) + 7;
    v17 = v14 >> 3;
    LODWORD(cxf) = 8 * v17 - v7 + HIDWORD(v17);
    for ( HIDWORD(v17) = 0; HIDWORD(v17) < (unsigned int)v17; LODWORD(v4) = v18 | v4 )
    {
      v18 = v16[HIDWORD(v17)++];
      v4 <<= 8;
    }
    v19 = &this->readp[v17];
    this->readp = v19;
    LODWORD(v20) = v7 - cxf + 7;
    *(_QWORD *)((char *)&v20 + 4) = v4 >> cxf;
    LODWORD(v6) = 0;
    v49 = ((DWORD2(v20) & *(_DWORD *)(HIDWORD(v4) + HIDWORD(v6))) + *(int *)((char *)signForNumBits + HIDWORD(v4)))
        ^ *(int *)((char *)signForNumBits + HIDWORD(v4));
    *(unsigned __int64 *)((char *)&v8 + 4) = (unsigned __int64)v20 >> 3;
    LODWORD(v8) = 8 * HIDWORD(v8) - v7 + DWORD1(v20);
    if ( HIDWORD(v8) != 0 )
    {
      do
      {
        v21 = v19[v6];
        LODWORD(v6) = v6 + 1;
        v4 <<= 8;
        LODWORD(v4) = v21 | v4;
      }
      while ( (unsigned int)v6 < HIDWORD(v8) );
    }
    this->readp = (const unsigned __int8 *)(HIDWORD(v8) + (v4 >> v8 >> 32));
    HIDWORD(v8) = *(_DWORD *)(HIDWORD(v4) + HIDWORD(v6));
    HIDWORD(v4) = (((v4 >> v8) & HIDWORD(v8)) + *(int *)((char *)signForNumBits + HIDWORD(v4)))
                ^ *(int *)((char *)signForNumBits + HIDWORD(v4));
  }
  else
  {
    HIDWORD(v4) = 256;
    v49 = 256;
  }
  v50 = HIDWORD(v4);
  if ( v5 != 0 )
  {
    HIDWORD(v22) = v7;
    v23 = 0;
    LODWORD(v22) = v7 - v8 + 7;
    *(unsigned __int64 *)((char *)&v4 + 4) = v22 >> 3;
    for ( i = 8 * BYTE3(v4) - v6 + v8; v23 < HIDWORD(v4); LODWORD(v4) = v25 | v4 )
    {
      v25 = this->readp[v23++];
      v4 <<= 8;
    }
    v26 = &this->readp[HIDWORD(v4)];
    HIDWORD(v4) = 4 * v7;
    this->readp = v26;
    *(_QWORD *)((char *)&v27 + 4) = v4 >> i;
    v28 = DWORD2(v27);
    LODWORD(v27) = v6 - DWORD1(v27) + 7;
    v29 = 0;
    DWORD2(v27) = signForNumBits[v7];
    v31 = (unsigned __int64)v27 >> 3;
    v30 = ((v28 & *(_DWORD *)(4 * v7 + HIDWORD(v6))) + HIDWORD(v31)) ^ HIDWORD(v31);
    HIDWORD(v31) = 8 * v31 - v6 + DWORD1(v27);
    v51 = v30;
    if ( (_DWORD)v31 != 0 )
    {
      do
      {
        v32 = v26[v29++];
        v4 <<= 8;
        LODWORD(v4) = v32 | v4;
      }
      while ( v29 < (unsigned int)v31 );
    }
    v33 = &this->readp[v31];
    LODWORD(v31) = v6 - HIDWORD(v31) + 7;
    this->readp = v33;
    v35 = v4 >> SBYTE3(v31);
    v34 = v31 >> 3;
    cxf = 8 * v34;
    v36 = 0;
    LODWORD(cxf) = 8 * v34 - v6 + HIDWORD(v34);
    for ( j = ((v35 & *(_DWORD *)(HIDWORD(v4) + HIDWORD(v6))) + *(int *)((char *)signForNumBits + HIDWORD(v4)))
            ^ *(int *)((char *)signForNumBits + HIDWORD(v4)); v36 < (unsigned int)v34; LODWORD(v4) = HIDWORD(v34) | v4 )
    {
      HIDWORD(v34) = v33[v36++];
      v4 <<= 8;
    }
    HIDWORD(v34) = v34;
    v37 = &this->readp[v34];
    LODWORD(v34) = v6 - cxf + 7;
    this->readp = v37;
    v38 = v4 >> cxf;
    v40 = v4 >> cxf;
    v39 = v34 >> 3;
    v41 = v39;
    v8 = 8 * v39;
    LODWORD(v8) = v8 - v6 + HIDWORD(v39);
    v53 = ((v40 & *(_DWORD *)(HIDWORD(v4) + HIDWORD(v6))) + *(int *)((char *)signForNumBits + HIDWORD(v4)))
        ^ *(int *)((char *)signForNumBits + HIDWORD(v4));
    if ( !is_mul_ok(8u, v41) )
    {
      do
      {
        v42 = v37[HIDWORD(v38)++];
        cxf = v4 << 8;
        LODWORD(v4) = v42 | ((_DWORD)v4 << 8);
      }
      while ( HIDWORD(v38) < HIDWORD(v8) );
    }
    this->readp = (const unsigned __int8 *)(HIDWORD(v8) + (v4 >> v8 >> 32));
    v43 = (v4 >> v8) & *(_DWORD *)(HIDWORD(v4) + HIDWORD(v6));
    HIDWORD(v4) = *(int *)((char *)signForNumBits + HIDWORD(v4));
    HIDWORD(v8) = v43 + HIDWORD(v4);
    v54 = (v43 + HIDWORD(v4)) ^ HIDWORD(v4);
  }
  else
  {
    v51 = 0;
    j = 0;
    v53 = 0;
    v54 = 0;
  }
  _R9 = &back_chain;
  this->currentByte = v4;
  _R8 = &v51;
  this->currentBit = v8;
  _R10 = 16;
  _R11 = HIDWORD(cxf) + 16;
  __asm
  {
    lvx128    v63, r0, r9
    lvx128    v62, r0, r8
    vcsxwfp128 v61, v63, 8
    vcsxwfp128 v60, v62, 8
    stvlx128  v61, r0, r4
    stvrx128  v61, r4, r10
    stvlx128  v60, r0, r11
    stvrx128  v60, r11, r10
  }
}


// ========================================================================
// ?ReadString@idSWFBitStream@@QAAPBDXZ
// EA  : 0x8276EB60
// RVA : 0x0076EB60
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

const char *__fastcall idSWFBitStream::ReadString(idSWFBitStream *this, int a2, int a3, int a4, unsigned __int64 a5)
{
  const char *result; // r3
  int v7; // r10
  const unsigned __int8 *readp; // r9
  const unsigned __int8 *endp; // r9
  const unsigned __int8 *v10; // r10

  result = (const char *)this->readp;
  LODWORD(a5) = 0;
  v7 = 0;
  if ( *result != 0 )
  {
    readp = this->readp;
    do
      HIDWORD(a5) = readp[++v7];
    while ( readp[v7] != 0 );
  }
  endp = this->endp;
  this->currentBit = a5;
  v10 = (const unsigned __int8 *)&result[v7 + 1];
  this->currentByte = a5;
  if ( v10 <= endp )
  {
    this->readp = v10;
  }
  else
  {
    result = (const char *)this->startp;
    this->readp = endp;
  }
  return result;
}


// ========================================================================
// ?ReadColorRGB@idSWFBitStream@@QAAXAAUswfColorRGB_t@@@Z
// EA  : 0x8276EBC0
// RVA : 0x0076EBC0
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

void __fastcall idSWFBitStream::ReadColorRGB(idSWFBitStream *this, swfColorRGB_t *color)
{
  unsigned __int64 v2; // r11

  HIDWORD(v2) = this->readp;
  LODWORD(v2) = 0;
  this->currentBit = v2;
  this->currentByte = v2;
  color->r = *(_BYTE *)HIDWORD(v2);
  LODWORD(v2) = this->readp + 1;
  this->readp = (const unsigned __int8 *)v2;
  color->g = *(_BYTE *)v2;
  LODWORD(v2) = this->readp + 1;
  this->readp = (const unsigned __int8 *)v2;
  color->b = *(_BYTE *)v2;
  ++this->readp;
}


// ========================================================================
// ?ReadColorRGBA@idSWFBitStream@@QAAXAAUswfColorRGBA_t@@@Z
// EA  : 0x8276EC10
// RVA : 0x0076EC10
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

void __fastcall idSWFBitStream::ReadColorRGBA(idSWFBitStream *this, swfColorRGBA_t *color)
{
  unsigned __int64 v2; // r11

  HIDWORD(v2) = this->readp;
  LODWORD(v2) = 0;
  this->currentBit = v2;
  this->currentByte = v2;
  color->r = *(_BYTE *)HIDWORD(v2);
  LODWORD(v2) = this->readp + 1;
  this->readp = (const unsigned __int8 *)v2;
  color->g = *(_BYTE *)v2;
  LODWORD(v2) = this->readp + 1;
  this->readp = (const unsigned __int8 *)v2;
  color->b = *(_BYTE *)v2;
  LODWORD(v2) = this->readp + 1;
  this->readp = (const unsigned __int8 *)v2;
  color->a = *(_BYTE *)v2;
  ++this->readp;
}


// ========================================================================
// ?ReadGradient@idSWFBitStream@@QAAXAAUswfGradient_t@@_N@Z
// EA  : 0x8276EC78
// RVA : 0x0076EC78
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

void __fastcall idSWFBitStream::ReadGradient(
        idSWFBitStream *this,
        swfGradient_t *grad,
        bool rgba,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *readp; // r11
  int v8; // r8
  unsigned __int8 v9; // r7
  BOOL v10; // r7
  unsigned __int8 *v11; // r11
  char v12; // r5
  const unsigned __int8 *v13; // r9
  const unsigned __int8 *v14; // r9
  const unsigned __int8 *v15; // r9
  const unsigned __int8 *v16; // r9
  char v17; // r5
  char v18; // r31
  char v19; // r30
  char v20; // r29

  readp = this->readp;
  LODWORD(a7) = 0;
  this->currentBit = a7;
  HIDWORD(a7) = readp + 1;
  this->currentByte = a7;
  v8 = 0;
  v9 = *readp;
  this->readp = readp + 1;
  grad->numGradients = v9 & 0xF;
  if ( (v9 & 0xF) != 0 )
  {
    v10 = rgba;
    v11 = (unsigned __int8 *)&grad->gradientRecords[0].startColor + 1;
    do
    {
      HIDWORD(a7) = this->readp;
      this->currentBit = a7;
      this->currentByte = a7;
      v12 = *(_BYTE *)HIDWORD(a7);
      this->readp = (const unsigned __int8 *)(HIDWORD(a7) + 1);
      *(v11 - 3) = v12;
      HIDWORD(a7) = this->readp;
      this->currentByte = a7;
      this->currentBit = a7;
      *(v11 - 1) = *(_BYTE *)HIDWORD(a7);
      v13 = this->readp + 1;
      this->readp = v13;
      *v11 = *v13;
      v14 = this->readp + 1;
      this->readp = v14;
      v11[1] = *v14;
      v15 = this->readp;
      if ( v10 )
      {
        v16 = v15 + 1;
        this->readp = v16;
        v11[2] = *v16;
        v15 = this->readp;
      }
      this->readp = v15 + 1;
      v17 = *(v11 - 1);
      ++v8;
      v18 = *v11;
      v19 = v11[1];
      v20 = v11[2];
      *(v11 - 2) = *(v11 - 3);
      v11[3] = v17;
      v11[4] = v18;
      v11[5] = v19;
      v11[6] = v20;
      v11 += 10;
    }
    while ( v8 < grad->numGradients );
  }
}


// ========================================================================
// ?ReadMorphGradient@idSWFBitStream@@QAAXAAUswfGradient_t@@@Z
// EA  : 0x8276ED88
// RVA : 0x0076ED88
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

void __fastcall idSWFBitStream::ReadMorphGradient(
        idSWFBitStream *this,
        swfGradient_t *grad,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *readp; // r11
  int v8; // r8
  unsigned __int8 v9; // r7
  swfGradient_t *v10; // r11
  unsigned __int8 v11; // r6
  const unsigned __int8 *v12; // r5
  unsigned __int8 v13; // r6
  const unsigned __int8 *v14; // r5
  const unsigned __int8 *v15; // r9
  const unsigned __int8 *v16; // r9
  const unsigned __int8 *v17; // r9

  readp = this->readp;
  LODWORD(a7) = 0;
  this->currentBit = a7;
  HIDWORD(a7) = readp + 1;
  this->currentByte = a7;
  v8 = 0;
  v9 = *readp;
  this->readp = readp + 1;
  grad->numGradients = v9 & 0xF;
  if ( (v9 & 0xF) != 0 )
  {
    v10 = grad;
    do
    {
      HIDWORD(a7) = this->readp;
      ++v8;
      this->currentBit = a7;
      this->currentByte = a7;
      v11 = *(_BYTE *)HIDWORD(a7);
      this->readp = (const unsigned __int8 *)(HIDWORD(a7) + 1);
      v10->gradientRecords[0].startRatio = v11;
      v12 = this->readp;
      this->currentBit = a7;
      this->currentByte = a7;
      v10->gradientRecords[0].startColor.r = *v12;
      HIDWORD(a7) = this->readp + 1;
      this->readp = (const unsigned __int8 *)HIDWORD(a7);
      v10->gradientRecords[0].startColor.g = *(_BYTE *)HIDWORD(a7);
      HIDWORD(a7) = this->readp + 1;
      this->readp = (const unsigned __int8 *)HIDWORD(a7);
      v10->gradientRecords[0].startColor.b = *(_BYTE *)HIDWORD(a7);
      HIDWORD(a7) = this->readp + 1;
      this->readp = (const unsigned __int8 *)HIDWORD(a7);
      v10->gradientRecords[0].startColor.a = *(_BYTE *)HIDWORD(a7);
      HIDWORD(a7) = this->readp + 1;
      this->readp = (const unsigned __int8 *)HIDWORD(a7);
      this->currentBit = a7;
      this->currentByte = a7;
      v13 = *(_BYTE *)HIDWORD(a7);
      this->readp = (const unsigned __int8 *)(HIDWORD(a7) + 1);
      v10->gradientRecords[0].endRatio = v13;
      v14 = this->readp;
      this->currentBit = a7;
      this->currentByte = a7;
      v10->gradientRecords[0].endColor.r = *v14;
      v15 = this->readp + 1;
      this->readp = v15;
      v10->gradientRecords[0].endColor.g = *v15;
      v16 = this->readp + 1;
      this->readp = v16;
      v10->gradientRecords[0].endColor.b = *v16;
      v17 = this->readp + 1;
      this->readp = v17;
      v10 = (swfGradient_t *)((char *)v10 + 10);
      v10->numGradients = *v17;
      ++this->readp;
    }
    while ( v8 < grad->numGradients );
  }
}


// ========================================================================
// ??0idSWFBitStream@@QAA@XZ
// EA  : 0x8276EEC0
// RVA : 0x0076EEC0
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

idSWFBitStream *__fastcall idSWFBitStream::idSWFBitStream(idSWFBitStream *this)
{
  unsigned __int64 v1; // r11

  LODWORD(v1) = 0;
  this->free = false;
  this->startp = nullptr;
  this->endp = nullptr;
  this->readp = nullptr;
  this->currentBit = v1;
  this->currentByte = v1;
  return this;
}


// ========================================================================
// ??4idSWFBitStream@@QAAAAV0@AAV0@@Z
// EA  : 0x8276EEE0
// RVA : 0x0076EEE0
// PDB : w:\tech5\engine\guis\swf\swf_bitstream.cpp
// ========================================================================

idSWFBitStream *__fastcall idSWFBitStream::operator=(idSWFBitStream *this, idSWFBitStream *other)
{
  unsigned __int64 v2; // r11
  idSWFBitStream *result; // r3

  if ( this->free )
    idMem::Free(this: &mem, ptr: (void *)this->startp, align: ALIGN_16);
  LODWORD(v2) = 0;
  result = this;
  this->free = false;
  this->startp = nullptr;
  this->endp = nullptr;
  this->readp = nullptr;
  this->currentBit = v2;
  this->currentByte = v2;
  this->free = other->free;
  this->startp = other->startp;
  this->readp = other->readp;
  this->endp = other->endp;
  this->currentBit = other->currentBit;
  this->currentByte = other->currentByte;
  if ( other->free )
    other->free = false;
  return result;
}

