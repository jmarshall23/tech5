
// ========================================================================
// ?CheckOverflow@idBitMsg@@AAA_NH@Z
// EA  : 0x82F4F6A8
// RVA : 0x00F4F6A8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idBitMsg::CheckOverflow(idBitMsg *this, int numBits, __int64 a3)
{
  _DWORD *v3; // r3
  __int64 v4; // r10
  _DWORD *v5; // r31
  int v6; // r11
  __int64 v7; // r8
  int v8; // r3
  const char *v9; // r3
  const char *v10; // r3
  int v12; // [sp+8h] [-58h]
  int v13; // [sp+Ch] [-54h]
  int v14; // [sp+10h] [-50h]
  int v15; // [sp+14h] [-4Ch]

  LODWORD(a3) = numBits;
  numBits = v3[2];
  LODWORD(v4) = v3[3];
  v5 = v3;
  v6 = v3[4];
  LODWORD(v7) = 8 * v4;
  HIDWORD(v7) = 8 * numBits - 8 * v4 - v6;
  if ( (int)a3 <= SHIDWORD(v7) )
    return 0;
  HIDWORD(v4) = *(unsigned __int8 *)(v8 + 28);
  if ( *(_BYTE *)(v8 + 28) == 0 )
  {
    HIDWORD(v4) = v6 - 1;
    LODWORD(v7) = &unk_82390000;
    v9 = "idBitMsg: overflow without allowOverflow set; maxsize=%i size=%i numBits=%i numRemainingWriteBits=%i";
    HIDWORD(a3) = (v6 != 0) + (_DWORD)v4;
    idLib::FatalError(fmt: *(__int64 *)&numBits, a2: a3, a3: v7, a4: v4, a5: v12, a6: v13, a7: v14, a8: v15);
  }
  if ( (int)a3 > 8 * numBits )
    idLib::FatalError(
      fmt: __SPAIR64__("idBitMsg: %i bits is > full message size", a3),
      a2: a3,
      a3: v7,
      a4: v4,
      a5: v12,
      a6: v13,
      a7: v14,
      a8: v15);
  v10 = "idBitMsg: overflow\n";
  idLib::Printf(fmt: *(__int64 *)&numBits, a2: a3, a3: v7, a4: v4, a5: v12, a6: v13, a7: v14, a8: v15);
  v5[3] = 0;
  v5[4] = 0;
  *((_QWORD *)v5 + 4) = 0x100000000LL;
  *((_BYTE *)v5 + 29) = 1;
  return 1;
}


// ========================================================================
// ?GetByteSpace@idBitMsg@@AAAPAEH@Z
// EA  : 0x82F4F778
// RVA : 0x00F4F778
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int8 *__fastcall idBitMsg::GetByteSpace(idBitMsg *this, int length, __int64 a3, __int64 a4, __int64 a5)
{
  idBitMsg *v5; // r3
  idBitMsg *v6; // r31
  const char *v8; // r3
  unsigned __int64 v9; // r10
  int curSize; // r11
  int v11; // r11
  unsigned __int8 *result; // r3
  int v13; // [sp+8h] [-68h]
  int v14; // [sp+Ch] [-64h]
  int v15; // [sp+10h] [-60h]
  int v16; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( v5->writeData == nullptr )
  {
    v8 = "idBitMsg::GetByteSpace: cannot write to message";
    idLib::FatalError(fmt: *(__int64 *)&length, a2: a3, a3: a4, a4: a5, a5: v13, a6: v14, a7: v15, a8: v16);
  }
  HIDWORD(v9) = v6->writeBit;
  LODWORD(v9) = 0;
  curSize = v6->curSize;
  v6->writeBit = 0;
  v6->tempValue = v9;
  v6->curSize = (HIDWORD(v9) != 0) + curSize;
  idBitMsg::CheckOverflow(this: v6, numBits: 8 * length, a3);
  v11 = v6->curSize;
  result = &v6->writeData[v11];
  v6->curSize = v11 + length;
  return result;
}


// ========================================================================
// ?WriteBits@idBitMsg@@QAAXHH@Z
// EA  : 0x82F4F808
// RVA : 0x00F4F808
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBitMsg::WriteBits(idBitMsg *this, int value, __int64 numBits, __int64 a4, __int64 a5)
{
  idBitMsg *v5; // r3
  idBitMsg *v6; // r31
  int v8; // r30
  const char *v9; // r3
  int v10; // r11
  __int64 v11; // r10
  int v12; // r2 OVERLAPPED
  unsigned __int64 v13; // r10
  unsigned __int64 tempValue; // r8
  int writeBit; // r5
  unsigned __int64 v16; // r4
  int curSize; // r11
  unsigned __int64 v18; // r7
  unsigned __int64 v19; // r5
  int v20; // r5
  const void *v21; // r4
  idBitMsg *v22; // r3
  int v23; // [sp+8h] [-68h]
  int v24; // [sp+Ch] [-64h]
  int v25; // [sp+10h] [-60h]
  int v26; // [sp+14h] [-5Ch]

  v6 = v5;
  v8 = HIDWORD(numBits);
  if ( v5->writeData == nullptr )
  {
    v9 = "idBitMsg::WriteBits: cannot write to message";
    idLib::FatalError(fmt: *(__int64 *)&value, a2: numBits, a3: a4, a4: a5, a5: v23, a6: v24, a7: v25, a8: v26);
  }
  if ( v8 == 0 || v8 < -31 || v8 > 32 )
  {
    idLib::FatalError(
      fmt: __SPAIR64__("idBitMsg::WriteBits: bad numBits %i", v8),
      a2: numBits,
      a3: a4,
      a4: a5,
      a5: v23,
      a6: v24,
      a7: v25,
      a8: v26);
    idBitMsg::WriteData(this: v22, data: v21, length: v20);
    return;
  }
  if ( v8 != 32 )
  {
    if ( v8 > 0 )
    {
      LODWORD(a5) = (1 << v8) - 1;
      if ( value > (int)a5 )
      {
        HIDWORD(numBits) = v8;
        idLib::FatalError(
          fmt: __SPAIR64__("idBitMsg::WriteBits: value overflow %d %d", value),
          a2: numBits,
          a3: a4,
          a4: a5,
          a5: v23,
          a6: v24,
          a7: v25,
          a8: v26);
      }
      if ( value >= 0 )
        goto _LN29_2;
      HIDWORD(numBits) = v8;
      idLib::FatalError(
        fmt: __SPAIR64__("idBitMsg::WriteBits: value overflow %d %d", value),
        a2: numBits,
        a3: a4,
        a4: a5,
        a5: v23,
        a6: v24,
        a7: v25,
        a8: v26);
    }
    LODWORD(v11) = 1;
    v10 = 1 << (-1 - v8);
    HIDWORD(v11) = v10 - 1;
    if ( value > v10 - 1 )
    {
      HIDWORD(numBits) = v8;
      idLib::FatalError(
        fmt: __SPAIR64__("idBitMsg::WriteBits: value overflow %d %d", value),
        a2: numBits,
        a3: a4,
        a4: v11,
        a5: v23,
        a6: v24,
        a7: v25,
        a8: v26);
    }
    if ( value < -v10 )
    {
      HIDWORD(numBits) = v8;
      idLib::FatalError(
        fmt: __SPAIR64__("idBitMsg::WriteBits: value overflow %d %d", value),
        a2: numBits,
        a3: a4,
        a4: v11,
        a5: v23,
        a6: v24,
        a7: v25,
        a8: v26);
    }
  }
_LN29_2:
  if ( v8 < 0 )
    v8 = -v8;
  if ( (unsigned __int8)idBitMsg::CheckOverflow(this: v6, numBits: v8, a3: numBits) == 0 )
  {
    HIDWORD(v13) = 8 * v8;
    tempValue = v6->tempValue;
    writeBit = v6->writeBit;
    v16 = maskForNumBits64[v8];
    v6->writeBit = writeBit + v8;
    HIDWORD(v16) = v16 & value;
    LODWORD(v13) = (*(_QWORD *)(&v12 - 1) << writeBit) | tempValue;
    v6->tempValue = v13;
    if ( writeBit + v8 >= 8 )
    {
      do
      {
        v6->writeData[v6->curSize] = v6->tempValue;
        curSize = v6->curSize;
        v18 = v6->tempValue;
        HIDWORD(v18) = v6->writeBit - 8;
        v19 = v18 >> 8;
        v6->writeBit = HIDWORD(v18);
        HIDWORD(v19) = curSize + 1;
        v6->tempValue = v19;
        v6->curSize = curSize + 1;
      }
      while ( SHIDWORD(v18) >= 8 );
    }
    if ( v6->writeBit > 0 )
      v6->writeData[v6->curSize] = v6->tempValue;
  }
}


// ========================================================================
// ?WriteData@idBitMsg@@QAAXPBXH@Z
// EA  : 0x82F4F9C8
// RVA : 0x00F4F9C8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

void __fastcall idBitMsg::WriteData(idBitMsg *this, const void *data, __int64 length, __int64 a4, __int64 a5)
{
  size_t v6; // r30
  unsigned __int8 *ByteSpace; // r3

  v6 = HIDWORD(length);
  ByteSpace = idBitMsg::GetByteSpace(this, length: SHIDWORD(length), a3: length, a4, a5);
  memcpy(Dst: ByteSpace, Src: data, Size: v6);
}


// ========================================================================
// ?WriteDelta@idBitMsg@@AAAXHHH@Z
// EA  : 0x82F4FA10
// RVA : 0x00F4FA10
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBitMsg::WriteDelta(idBitMsg *this, int oldValue, __int64 numBits, __int64 a4, __int64 a5)
{
  idBitMsg *v5; // r3
  unsigned __int8 *writeData; // r11
  idBitMsg *v7; // r31
  int v8; // r30
  int v9; // r29
  const char *v10; // r3
  unsigned __int64 v11; // r6
  __int128 v12; // r10
  int curSize; // r11
  unsigned __int64 tempValue; // r7
  unsigned __int64 v15; // r5
  const char *v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8 OVERLAPPED
  __int64 v19; // r6
  unsigned __int64 v20; // r4
  int v21; // r11
  unsigned __int64 v22; // r11
  int v23; // [sp+8h] [-68h]
  int v24; // [sp+Ch] [-64h]
  int v25; // [sp+10h] [-60h]
  int v26; // [sp+14h] [-5Ch]

  writeData = v5->writeData;
  v7 = v5;
  v8 = HIDWORD(numBits);
  v9 = numBits;
  if ( oldValue == HIDWORD(numBits) )
  {
    if ( writeData == nullptr )
    {
      v10 = "idBitMsg::WriteBits: cannot write to message";
      idLib::FatalError(fmt: *(__int64 *)&oldValue, a2: numBits, a3: a4, a4: a5, a5: v23, a6: v24, a7: v25, a8: v26);
    }
    if ( (unsigned __int8)idBitMsg::CheckOverflow(this: v7, numBits: 1, a3: numBits) == 0 )
    {
      LODWORD(v12) = 0;
      *(_QWORD *)((char *)&v12 + 4) = v7->tempValue;
      DWORD1(v12) = v7->writeBit;
      LODWORD(v11) = ((_QWORD)v12 << SBYTE7(v12)) | DWORD2(v12);
      v7->writeBit = DWORD1(v12) + 1;
      v7->tempValue = v11;
      if ( DWORD1(v12) + 1 >= 8 )
      {
        do
        {
          v7->writeData[v7->curSize] = v7->tempValue;
          curSize = v7->curSize;
          tempValue = v7->tempValue;
          HIDWORD(tempValue) = v7->writeBit - 8;
          v15 = tempValue >> 8;
          v7->writeBit = HIDWORD(tempValue);
          HIDWORD(v15) = curSize + 1;
          v7->tempValue = v15;
          v7->curSize = curSize + 1;
        }
        while ( SHIDWORD(tempValue) >= 8 );
      }
      if ( v7->writeBit > 0 )
        v7->writeData[v7->curSize] = v7->tempValue;
    }
  }
  else
  {
    if ( writeData == nullptr )
    {
      v16 = "idBitMsg::WriteBits: cannot write to message";
      idLib::FatalError(fmt: *(__int64 *)&oldValue, a2: numBits, a3: a4, a4: a5, a5: v23, a6: v24, a7: v25, a8: v26);
    }
    HIDWORD(v20) = idBitMsg::CheckOverflow(this: v7, numBits: 1, a3: numBits);
    if ( BYTE3(v20) == 0 )
    {
      LODWORD(v18) = maskForNumBits64;
      HIDWORD(v18) = v7->writeBit;
      v17 = maskForNumBits64[1];
      v7->writeBit = HIDWORD(v18) + 1;
      LODWORD(v19) = v17 & 1;
      LODWORD(v20) = (v19 << SBYTE3(v18)) | HIDWORD(v17);
      v7->tempValue = v20;
      if ( HIDWORD(v18) + 1 >= 8 )
      {
        do
        {
          HIDWORD(v17) = v7->writeData;
          LODWORD(v18) = (unsigned __int8)LODWORD(v7->tempValue);
          v7->writeData[v7->curSize] = v18;
          *(__int64 *)((char *)&v18 + 4) = v7->tempValue;
          LODWORD(v17) = v7->writeBit;
          v21 = v7->curSize;
          v19 = *(unsigned __int64 *)((char *)&v18 + 4) >> 8;
          v7->writeBit = HIDWORD(v19);
          v7->tempValue = v19;
          v7->curSize = v21 + 1;
        }
        while ( SHIDWORD(v19) >= 8 );
      }
      if ( v7->writeBit > 0 )
      {
        v22 = v7->tempValue;
        LODWORD(v17) = v7->curSize;
        HIDWORD(v17) = v7->writeData;
        v7->writeData[v17] = v22;
      }
    }
    HIDWORD(v19) = v9;
    idBitMsg::WriteBits(this: v7, value: v8, numBits: v19, a4: v18, a5: v17);
  }
}


// ========================================================================
// ?ReadBits@idBitMsg@@QBAHH@Z
// EA  : 0x82F4FBD0
// RVA : 0x00F4FBD0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idBitMsg::ReadBits(idBitMsg *this, int numBits, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v7; // r3
  int v8; // r3
  int v9; // r10
  char v10; // r30
  int v11; // r3
  int v12; // r9
  int v13; // r11
  unsigned int v14; // r28
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3
  int v19; // r3
  const char *v20; // r3
  int result; // r3
  int v22; // [sp+8h] [-78h]
  int v23; // [sp+Ch] [-74h]
  int v24; // [sp+10h] [-70h]
  int v25; // [sp+14h] [-6Ch]

  v6 = *(_DWORD *)(v5 + 4);
  HIDWORD(a4) = v5;
  if ( v6 == 0 )
  {
    v7 = "idBitMsg::ReadBits: cannot read from message";
    idLib::FatalError(fmt: *(__int64 *)&numBits, a2: a3, a3: a4, a4: a5, a5: v22, a6: v23, a7: v24, a8: v25);
  }
  if ( numBits == 0 || numBits < -31 || numBits > 32 )
  {
    v20 = "idBitMsg::ReadBits: bad numBits %i";
    idLib::FatalError(fmt: *(__int64 *)&numBits, a2: a3, a3: a4, a4: a5, a5: v22, a6: v23, a7: v24, a8: v25);
    JUMPOUT(0x82F4FD1C);
  }
  v8 = 0;
  v9 = 0;
  if ( numBits >= 0 )
  {
    v10 = 0;
  }
  else
  {
    numBits = -numBits;
    v10 = 1;
  }
  LODWORD(a4) = *(_DWORD *)(HIDWORD(a4) + 20);
  if ( numBits <= (-*(_DWORD *)(HIDWORD(a4) + 24) & 7) - 8 * (int)a4 + 8 * *(_DWORD *)(HIDWORD(a4) + 12) )
  {
    if ( numBits > 0 )
    {
      do
      {
        v12 = *(_DWORD *)(HIDWORD(a4) + 24);
        if ( v12 == 0 )
          *(_DWORD *)(HIDWORD(a4) + 20) = a4 + 1;
        v13 = 8 - v12;
        if ( 8 - v12 > numBits - v9 )
          v13 = numBits - v9;
        LODWORD(a4) = *(_DWORD *)(HIDWORD(a4) + 20);
        v14 = *(unsigned __int8 *)(a4 + v6 - 1);
        *(_DWORD *)(HIDWORD(a4) + 24) = ((_BYTE)v12 + (_BYTE)v13) & 7;
        v16 = (((v14 >> v12) & ((1 << v13) - 1)) << v9) | v15;
        v9 += v13;
      }
      while ( v9 < numBits );
    }
    if ( v10 != 0 && ((1 << (numBits - 1)) & v17) != 0 )
      v19 = v18 | ~((1 << numBits) - 1);
  }
  else
  {
    v11 = -1;
  }
  return result;
}


// ========================================================================
// ?ReadString@idBitMsg@@QBAHAAVidStr@@@Z
// EA  : 0x82F4FD20
// RVA : 0x00F4FD20
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

int __fastcall idBitMsg::ReadString(idBitMsg *this, idStr *str)
{
  int readCount; // r11
  int curSize; // r10
  int v6; // r29
  char *data; // r11

  readCount = this->readCount;
  curSize = this->curSize;
  this->readBit = 0;
  v6 = 0;
  if ( readCount < curSize )
  {
    do
    {
      if ( this->readData[readCount] == 0 )
        break;
      ++readCount;
      ++v6;
    }
    while ( readCount < this->curSize );
  }
  if ( str->allocedAndFlag >= 0 )
  {
    idStr::FreeData(this: str);
    str->len = 0;
    str->allocedAndFlag = 20;
    str->data = str->baseBuffer;
    str->baseBuffer[0] = 0;
  }
  else
  {
    data = str->data;
    str->len = 0;
    *data = 0;
  }
  idStr::Append(this: str, text: (const char *)&this->readData[this->readCount], l: v6);
  this->readCount += v6 + 1;
  return str->len;
}


// ========================================================================
// ?ReadData@idBitMsg@@QBAHPAXH@Z
// EA  : 0x82F4FDE8
// RVA : 0x00F4FDE8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

int __fastcall idBitMsg::ReadData(idBitMsg *this, void *data, size_t length)
{
  int readCount; // r30
  int curSize; // r11
  int v7; // r10
  int v9; // r10

  readCount = this->readCount;
  curSize = this->curSize;
  this->readBit = 0;
  if ( (int)(readCount + length) <= curSize )
  {
    if ( data != nullptr )
      memcpy(Dst: data, Src: &this->readData[readCount], Size: length);
    v9 = this->readCount + length;
    this->readCount = v9;
    return v9 - readCount;
  }
  else
  {
    if ( data != nullptr )
      memcpy(Dst: data, Src: &this->readData[readCount], Size: curSize - readCount);
    v7 = this->curSize;
    this->readCount = v7;
    return v7 - readCount;
  }
}


// ========================================================================
// ?ReadDelta@idBitMsg@@ABAHHH@Z
// EA  : 0x82F4FE80
// RVA : 0x00F4FE80
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

int __fastcall idBitMsg::ReadDelta(idBitMsg *this, int oldValue, __int64 numBits, __int64 a4, __int64 a5)
{
  int v7; // r30
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6

  v7 = HIDWORD(numBits);
  if ( idBitMsg::ReadBits(this, numBits: 1, a3: numBits, a4, a5) != 0 )
    return idBitMsg::ReadBits(this, numBits: v7, a3: v10, a4: v9, a5: v8);
  else
    return oldValue;
}


// ========================================================================
// ?WriteString@idBitMsg@@QAAXPBDH_N@Z
// EA  : 0x82F4FEC8
// RVA : 0x00F4FEC8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

void __fastcall idBitMsg::WriteString(idBitMsg *this, const char *s, __int64 make7Bit, __int64 a4, __int64 a5)
{
  char v6; // r29
  int v7; // r31
  unsigned __int8 *ByteSpace; // r3
  int v9; // r8
  unsigned __int8 *v10; // r11
  int i; // ctr
  unsigned int v12; // r10
  unsigned __int8 *v13; // r11
  int v14; // ctr

  v6 = make7Bit;
  if ( s == nullptr )
  {
    *idBitMsg::GetByteSpace(this, length: 1, a3: make7Bit, a4, a5) = 0;
    return;
  }
  v7 = 0;
  if ( *s != 0 )
  {
    do
      ++v7;
    while ( s[v7] != 0 );
  }
  if ( make7Bit >= 0 && v7 >= SHIDWORD(make7Bit) )
    v7 = HIDWORD(make7Bit) - 1;
  ByteSpace = idBitMsg::GetByteSpace(this, length: v7 + 1, a3: make7Bit, a4, a5);
  v9 = 0;
  if ( v6 == 0 )
  {
    if ( v7 > 0 )
    {
      v13 = ByteSpace;
      v14 = v7;
      v9 = v7;
      do
      {
        *v13 = v13[s - (const char *)ByteSpace];
        ++v13;
        --v14;
      }
      while ( v14 != 0 );
    }
    goto LABEL_19;
  }
  if ( v7 <= 0 )
  {
LABEL_19:
    ByteSpace[v9] = 0;
    return;
  }
  v10 = ByteSpace;
  for ( i = v7; i != 0; --i )
  {
    v12 = v10[s - (const char *)ByteSpace];
    if ( v12 <= 0x7F )
      *v10 = v12;
    else
      *v10 = 46;
    ++v10;
  }
  ByteSpace[v7] = 0;
}


// ========================================================================
// ?WriteNetadr@idBitMsg@@QAAXUnetadr_t@@@Z
// EA  : 0x82F4FFD0
// RVA : 0x00F4FFD0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBitMsg::WriteNetadr(idBitMsg *this, const netadr_t *adr, __int64 a3, __int64 a4, __int64 a5)
{
  idBitMsg *v5; // r3
  idBitMsg *v6; // r31
  unsigned __int8 *ByteSpace; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // [sp+90h] [+20h]

  v14 = *(_QWORD *)&adr;
  v6 = v5;
  ByteSpace = idBitMsg::GetByteSpace(this: v5, length: 4, a3, a4, a5);
  LODWORD(v8) = BYTE4(v14);
  HIDWORD(v8) = BYTE5(v14);
  LODWORD(v9) = BYTE6(v14);
  HIDWORD(v10) = 16;
  HIDWORD(v9) = (unsigned __int8)v14;
  *(_DWORD *)ByteSpace = v14;
  idBitMsg::WriteBits(this: v6, value: 0, numBits: v10, a4: v9, a5: v8);
  HIDWORD(v11) = 8;
  idBitMsg::WriteBits(this: v6, value: SHIDWORD(v14), numBits: v11, a4: v13, a5: v12);
}


// ========================================================================
// ?WriteDeltaShortCounter@idBitMsg@@QAAXHH@Z
// EA  : 0x82F50058
// RVA : 0x00F50058
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

void __fastcall idBitMsg::WriteDeltaShortCounter(idBitMsg *this, int oldValue, __int64 newValue, __int64 a4)
{
  int v4; // r30
  __int64 v6; // r10
  int v7; // r31
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8

  v4 = HIDWORD(newValue) - oldValue;
  LODWORD(v6) = (HIDWORD(newValue) - oldValue) ^ ((HIDWORD(newValue) - oldValue) >> 31);
  HIDWORD(v6) = abs32(HIDWORD(newValue) - oldValue);
  LODWORD(a4) = _cntlzw(HIDWORD(v6));
  v7 = 32 - a4;
  if ( 32 - (int)a4 <= 1 )
    v7 = 1;
  HIDWORD(newValue) = 4;
  idBitMsg::WriteBits(this, value: v7 - 1, numBits: newValue, a4, a5: v6);
  HIDWORD(v8) = -1 - v7;
  idBitMsg::WriteBits(this, value: v4, numBits: v8, a4: v10, a5: v9);
}


// ========================================================================
// ?WriteDeltaLongCounter@idBitMsg@@QAAXHH@Z
// EA  : 0x82F500B8
// RVA : 0x00F500B8
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

void __fastcall idBitMsg::WriteDeltaLongCounter(idBitMsg *this, int oldValue, __int64 newValue, __int64 a4)
{
  int v4; // r30
  __int64 v6; // r10
  int v7; // r31
  __int64 v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8

  v4 = HIDWORD(newValue) - oldValue;
  LODWORD(v6) = (HIDWORD(newValue) - oldValue) ^ ((HIDWORD(newValue) - oldValue) >> 31);
  HIDWORD(v6) = abs32(HIDWORD(newValue) - oldValue);
  LODWORD(a4) = _cntlzw(HIDWORD(v6));
  v7 = 32 - a4;
  if ( 32 - (int)a4 <= 1 )
    v7 = 1;
  HIDWORD(newValue) = 5;
  idBitMsg::WriteBits(this, value: v7 - 1, numBits: newValue, a4, a5: v6);
  HIDWORD(v8) = -1 - v7;
  idBitMsg::WriteBits(this, value: v4, numBits: v8, a4: v10, a5: v9);
}


// ========================================================================
// ?ReadString@idBitMsg@@QBAHPADH@Z
// EA  : 0x82F50118
// RVA : 0x00F50118
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

int __fastcall idBitMsg::ReadString(idBitMsg *this, char *buffer, __int64 bufferSize, __int64 a4, __int64 a5)
{
  int v7; // r28
  int v8; // r31
  int i; // r11
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6

  this->readBit = 0;
  v7 = HIDWORD(bufferSize);
  v8 = 0;
  for ( i = (unsigned __int8)idBitMsg::ReadBits(this, numBits: 8, a3: bufferSize, a4, a5);
        i != 0;
        i = (unsigned __int8)idBitMsg::ReadBits(this, numBits: 8, a3: v12, a4: v11, a5: v10) )
  {
    if ( i >= 255 )
      break;
    if ( i == 37 )
      LOBYTE(i) = 46;
    if ( v8 < v7 - 1 )
      buffer[v8++] = i;
    LODWORD(v10) = v7 - 1;
  }
  buffer[v8] = 0;
  return v8;
}


// ========================================================================
// ?ReadNetadr@idBitMsg@@QBAXPAUnetadr_t@@@Z
// EA  : 0x82F501A0
// RVA : 0x00F501A0
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

void __fastcall idBitMsg::ReadNetadr(idBitMsg *this, netadr_t *adr)
{
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6

  idBitMsg::ReadData(this, data: adr->ip, length: 4u);
  adr->port = idBitMsg::ReadBits(this, numBits: 16, a3: v6, a4: v5, a5: v4);
  adr->type = (unsigned __int8)idBitMsg::ReadBits(this, numBits: 8, a3: v9, a4: v8, a5: v7);
}


// ========================================================================
// ?ReadDeltaShortCounter@idBitMsg@@QBAHH@Z
// EA  : 0x82F50208
// RVA : 0x00F50208
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

int __fastcall idBitMsg::ReadDeltaShortCounter(idBitMsg *this, int oldValue, __int64 a3, __int64 a4, __int64 a5)
{
  int Bits; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6

  Bits = idBitMsg::ReadBits(this, numBits: 4, a3, a4, a5);
  return idBitMsg::ReadBits(this, numBits: -1 - (Bits + 1), a3: v10, a4: v9, a5: v8) + oldValue;
}


// ========================================================================
// ?ReadDeltaLongCounter@idBitMsg@@QBAHH@Z
// EA  : 0x82F50258
// RVA : 0x00F50258
// PDB : w:\tech5\shared\idlib\networking\bitmsg.cpp
// ========================================================================

int __fastcall idBitMsg::ReadDeltaLongCounter(idBitMsg *this, int oldValue, __int64 a3, __int64 a4, __int64 a5)
{
  int Bits; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6

  Bits = idBitMsg::ReadBits(this, numBits: 5, a3, a4, a5);
  return idBitMsg::ReadBits(this, numBits: -1 - (Bits + 1), a3: v10, a4: v9, a5: v8) + oldValue;
}

