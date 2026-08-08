
// ========================================================================
// ?ReadBits@idLZWCompressor@@QAAHH@Z
// EA  : 0x82899B00
// RVA : 0x00899B00
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idLZWCompressor::ReadBits(idLZWCompressor *this, int bits)
{
  int v2; // r10
  int bytesRead; // r9
  __int128 v4; // r7
  lzwCompressionData_t *lzwData; // r11
  unsigned __int64 tempValue; // r7
  unsigned __int64 v7; // r5

  v2 = bits - this->lzwData->tempBits;
  if ( v2 <= 0 )
  {
LABEL_4:
    tempValue = this->lzwData->tempValue;
    HIDWORD(tempValue) = (1 << bits) - 1;
    v7 = tempValue >> bits;
    this->lzwData->tempValue = v7;
    this->lzwData->tempBits -= HIDWORD(v7);
    return HIDWORD(tempValue) & tempValue;
  }
  else
  {
    while ( 1 )
    {
      bytesRead = this->bytesRead;
      if ( bytesRead >= this->maxSize )
        return -1;
      v2 -= 8;
      DWORD2(v4) = this->data[bytesRead];
      DWORD1(v4) = this->lzwData->tempBits;
      LODWORD(v4) = (*(_QWORD *)((char *)&v4 + 4) << SBYTE7(v4)) | LODWORD(this->lzwData->tempValue);
      this->lzwData->tempValue = v4;
      lzwData = this->lzwData;
      ++this->bytesRead;
      lzwData->tempBits += 8;
      if ( v2 <= 0 )
        goto LABEL_4;
    }
  }
}


// ========================================================================
// ?WriteBits@idLZWCompressor@@QAAXIH@Z
// EA  : 0x82899BB0
// RVA : 0x00899BB0
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLZWCompressor::WriteBits(idLZWCompressor *this, unsigned int value, int bits)
{
  __int64 v3; // r10
  __int64 v4; // r4
  _DWORD *v5; // r3
  int v6; // r3

  LODWORD(v3) = value;
  HIDWORD(v3) = *(_DWORD *)(*(_DWORD *)HIDWORD(v4) + 12312);
  LODWORD(v4) = (v3 << SBYTE3(v3)) | *(_DWORD *)(*(_DWORD *)HIDWORD(v4) + 12308);
  *(_QWORD *)(*(_DWORD *)HIDWORD(v4) + 12304) = v4;
  *(_DWORD *)(*(_DWORD *)HIDWORD(v4) + 12312) += (unsigned __int64)(v3 << SBYTE3(v3)) >> 32;
  if ( *(int *)(*(_DWORD *)HIDWORD(v4) + 12312) >= 8 )
  {
    while ( *(_DWORD *)(*v5 + 12316) < v5[2563] )
    {
      *(_BYTE *)(v5[2562] + *(_DWORD *)(*v5 + 12304)) = *(_QWORD *)(*v5 + 12304);
      ++*(_DWORD *)(*v5 + 12316);
      *(_QWORD *)(*v5 + 12304) >>= 8;
      *(_DWORD *)(*v5 + 12312) -= 8;
      if ( *(int *)(*v5 + 12312) < 8 )
        return;
    }
    *(_BYTE *)(v6 + 10256) = 1;
  }
}


// ========================================================================
// ?WriteChain@idLZWCompressor@@QAAHH@Z
// EA  : 0x82899C68
// RVA : 0x00899C68
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idLZWCompressor::WriteChain(idLZWCompressor *this, int code)
{
  _BYTE *v2; // r10
  lzwCompressionData_t *lzwData; // r9
  int v5; // r11
  int v6; // r11
  int result; // r3
  _BYTE *v8; // r10
  int *p_blockSize; // r11
  int v10; // ctr
  _BYTE v11[4097]; // [sp+Fh] [-1001h] BYREF

  v2 = v11;
  lzwData = this->lzwData;
  v5 = 0;
  do
  {
    ++v5;
    *++v2 = lzwData->dictionaryK[code];
    code = lzwData->dictionaryW[code];
  }
  while ( code != 0xFFFF );
  v6 = v5 - 1;
  result = (unsigned __int8)v11[v6 + 1];
  if ( v6 >= 0 )
  {
    v8 = &v11[v6 + 2];
    v10 = v6 + 1;
    p_blockSize = &this->blockSize;
    do
    {
      this->block[(*p_blockSize)++] = *--v8;
      --v10;
    }
    while ( v10 != 0 );
  }
  return result;
}


// ========================================================================
// ?Lookup@idLZWCompressor@@QAAHHH@Z
// EA  : 0x82899CF0
// RVA : 0x00899CF0
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idLZWCompressor::Lookup(idLZWCompressor *this, int w, int k)
{
  int v4; // r11
  lzwCompressionData_t *lzwData; // r10

  if ( w == -1 )
    return k;
  v4 = this->hash[((unsigned __int16)w ^ (unsigned __int16)k) & 0x3FF];
  if ( v4 == 0xFFFF )
    return -1;
  lzwData = this->lzwData;
  while ( lzwData->dictionaryK[v4] != k || lzwData->dictionaryW[v4] != w )
  {
    v4 = this->nextHash[v4];
    if ( v4 == 0xFFFF )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?End@idLZWCompressor@@QAAHXZ
// EA  : 0x82899D68
// RVA : 0x00899D68
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idLZWCompressor::End(idLZWCompressor *this)
{
  unsigned int codeWord; // r4
  lzwCompressionData_t *lzwData; // r11
  int tempBits; // r9
  int bytesWritten; // r10
  int v7; // r11

  codeWord = this->lzwData->codeWord;
  if ( codeWord != -1 )
    idLZWCompressor::WriteBits(this, value: codeWord, bits: this->lzwData->codeBits);
  lzwData = this->lzwData;
  tempBits = this->lzwData->tempBits;
  if ( tempBits > 0 )
  {
    bytesWritten = lzwData->bytesWritten;
    if ( bytesWritten >= this->maxSize )
    {
      this->overflowed = true;
      return -1;
    }
    this->data[bytesWritten] = ((1 << tempBits) - 1) & lzwData->tempValue;
    ++this->lzwData->bytesWritten;
  }
  v7 = this->lzwData->bytesWritten;
  if ( v7 <= 0 )
    return -1;
  return v7;
}


// ========================================================================
// ?Save@idLZWCompressor@@QAAXXZ
// EA  : 0x82899E38
// RVA : 0x00899E38
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idLZWCompressor::Save(idLZWCompressor *this)
{
  lzwCompressionData_t *lzwData; // r11

  lzwData = this->lzwData;
  this->savedBytesWritten = this->lzwData->bytesWritten;
  this->savedCodeWord = lzwData->codeWord;
  this->saveCodeBits = lzwData->codeBits;
  this->savedTempValue = lzwData->tempValue;
  this->savedTempBits = lzwData->tempBits;
}


// ========================================================================
// ?Restore@idLZWCompressor@@QAAXXZ
// EA  : 0x82899E90
// RVA : 0x00899E90
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idLZWCompressor::Restore(idLZWCompressor *this)
{
  unsigned __int64 savedTempValue; // r7

  this->lzwData->bytesWritten = this->savedBytesWritten;
  this->lzwData->codeWord = this->savedCodeWord;
  this->lzwData->codeBits = this->saveCodeBits;
  savedTempValue = this->savedTempValue;
  this->lzwData->tempValue = savedTempValue;
  this->lzwData->tempBits = *(int *)((char *)&this->lzwData + HIDWORD(savedTempValue));
}


// ========================================================================
// ?Start@idZeroRunLengthCompressor@@QAAXPAEPAVidLZWCompressor@@H@Z
// EA  : 0x82899EF8
// RVA : 0x00899EF8
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idZeroRunLengthCompressor::Start(
        idZeroRunLengthCompressor *this,
        unsigned __int8 *dest_,
        idLZWCompressor *comp_,
        int maxSize_)
{
  this->dest = dest_;
  this->comp = comp_;
  this->zeroCount = 0;
  this->compressed = 0;
  this->maxSize = maxSize_;
}


// ========================================================================
// ?Start@idLZWCompressor@@QAAXPAEH_N@Z
// EA  : 0x82899F18
// RVA : 0x00899F18
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idLZWCompressor::Start(idLZWCompressor *this, unsigned __int8 *data_, int maxSize_, bool append)
{
  __int64 v8; // r7
  int v9; // r10
  int nextCode; // r9
  int v11; // r11
  int v12; // ctr
  unsigned __int16 v13; // r8
  unsigned __int8 v14; // r4
  unsigned __int16 v15; // r3
  int v16; // r9
  int v17; // r11
  int v18; // r10
  int i; // ctr

  memset(Dst: this->hash, Val: 255, Size: sizeof(this->hash));
  LODWORD(v8) = 0;
  if ( append )
  {
    v9 = 256;
    nextCode = this->lzwData->nextCode;
    this->lzwData->nextCode = 256;
    if ( nextCode > 256 )
    {
      v11 = 4608;
      v12 = nextCode - 256;
      do
      {
        v13 = this->lzwData->dictionaryK[v9];
        v14 = this->lzwData->dictionaryK[v9++];
        v15 = *(_WORD *)&this->lzwData->dictionaryK[v11];
        v11 += 2;
        this->lzwData->dictionaryK[this->lzwData->nextCode] = v14;
        v16 = 2 * (((v15 ^ v13) & 0x3FF) + 2);
        this->lzwData->dictionaryW[this->lzwData->nextCode] = v15;
        this->nextHash[this->lzwData->nextCode] = *(_WORD *)((char *)&this->lzwData + v16);
        *(_WORD *)((char *)&this->lzwData + v16) = this->lzwData->nextCode++;
        --v12;
      }
      while ( v12 != 0 );
    }
  }
  else
  {
    v17 = 0;
    v18 = 4096;
    for ( i = 256; i != 0; --i )
    {
      this->lzwData->dictionaryK[v17] = v17;
      ++v17;
      *(_WORD *)&this->lzwData->dictionaryK[v18] = -1;
      v18 += 2;
    }
    this->lzwData->nextCode = 256;
    this->lzwData->codeBits = 9;
    this->lzwData->codeWord = -1;
    this->lzwData->tempValue = 0xFFFFFFFF00000000uLL;
    this->lzwData->tempBits = 0;
    this->lzwData->bytesWritten = 0;
  }
  this->oldCode = -1;
  this->data = data_;
  this->maxSize = maxSize_;
  this->bytesRead = 0;
  this->overflowed = false;
  this->blockSize = 0;
  this->blockIndex = 0;
  HIDWORD(v8) = 43056;
  this->savedBytesWritten = 0;
  this->savedCodeWord = 0;
  this->saveCodeBits = 0;
  *(_QWORD *)((char *)&this->lzwData + HIDWORD(v8)) = v8;
  this->savedTempBits = 0;
}


// ========================================================================
// ?BumpBits@idLZWCompressor@@QAA_NXZ
// EA  : 0x8289A0E8
// RVA : 0x0089A0E8
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idLZWCompressor::BumpBits(idLZWCompressor *this)
{
  int codeBits; // r9

  codeBits = this->lzwData->codeBits;
  if ( this->lzwData->nextCode != 1 << codeBits )
    return 0;
  this->lzwData->codeBits = codeBits + 1;
  if ( this->lzwData->codeBits <= 12 )
    return 0;
  this->lzwData->nextCode = 256;
  this->lzwData->codeBits = 9;
  memset(Dst: this->hash, Val: 255, Size: sizeof(this->hash));
  return 1;
}


// ========================================================================
// ?DecompressBlock@idLZWCompressor@@QAAXXZ
// EA  : 0x8289A178
// RVA : 0x0089A178
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idLZWCompressor::DecompressBlock(idLZWCompressor *this)
{
  int *p_blockSize; // r30
  int Bits; // r3
  int v4; // r29
  int oldCode; // r4
  unsigned __int16 v6; // r3
  int v7; // r8
  int v8; // r11
  int codeBits; // r7
  char v10; // r11

  p_blockSize = &this->blockSize;
  this->blockIndex = 0;
  this->blockSize = 0;
  do
  {
    Bits = idLZWCompressor::ReadBits(this, bits: this->lzwData->codeBits);
    v4 = Bits;
    if ( Bits == -1 )
      break;
    oldCode = this->oldCode;
    if ( oldCode == -1 )
    {
      this->block[(*p_blockSize)++] = Bits;
    }
    else
    {
      if ( Bits < this->lzwData->nextCode )
      {
        v6 = idLZWCompressor::WriteChain(this, code: Bits);
      }
      else
      {
        v6 = idLZWCompressor::WriteChain(this, code: oldCode);
        this->block[(*p_blockSize)++] = v6;
      }
      v7 = this->oldCode;
      v8 = 2 * ((((unsigned __int16)v7 ^ v6) & 0x3FF) + 2);
      this->lzwData->dictionaryK[this->lzwData->nextCode] = v6;
      this->lzwData->dictionaryW[this->lzwData->nextCode] = v7;
      this->nextHash[this->lzwData->nextCode] = *(_WORD *)((char *)&this->lzwData + v8);
      *(_WORD *)((char *)&this->lzwData + v8) = this->lzwData->nextCode++;
      codeBits = this->lzwData->codeBits;
      if ( this->lzwData->nextCode == 1 << codeBits
        && (this->lzwData->codeBits = codeBits + 1, this->lzwData->codeBits > 12) )
      {
        this->lzwData->nextCode = 256;
        this->lzwData->codeBits = 9;
        memset(Dst: this->hash, Val: 255, Size: sizeof(this->hash));
        v10 = 1;
      }
      else
      {
        v10 = 0;
      }
      if ( v10 != 0 )
      {
        this->oldCode = -1;
        continue;
      }
    }
    this->oldCode = v4;
  }
  while ( *p_blockSize < 28672 );
}


// ========================================================================
// ?ReadByte@idLZWCompressor@@QAAH_N@Z
// EA  : 0x8289A328
// RVA : 0x0089A328
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idLZWCompressor::ReadByte(idLZWCompressor *this, bool ignoreOverflow)
{
  int *p_blockIndex; // r30
  int *p_blockSize; // r29
  int v6; // r11
  int result; // r3

  p_blockIndex = &this->blockIndex;
  p_blockSize = &this->blockSize;
  if ( this->blockIndex == this->blockSize )
    idLZWCompressor::DecompressBlock(this);
  v6 = *p_blockIndex;
  if ( *p_blockIndex == *p_blockSize )
  {
    if ( !ignoreOverflow )
      this->overflowed = true;
    return -1;
  }
  else
  {
    result = this->block[v6];
    *p_blockIndex = v6 + 1;
  }
  return result;
}


// ========================================================================
// ?WriteByte@idLZWCompressor@@QAAXE@Z
// EA  : 0x8289A3A8
// RVA : 0x0089A3A8
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idLZWCompressor::WriteByte(idLZWCompressor *this, unsigned __int8 value)
{
  int v2; // r30
  int v4; // r6
  unsigned int v5; // r4
  int v6; // r3
  idLZWCompressor *v7; // r3
  int codeWord; // r8
  int v9; // r11

  v2 = value;
  v6 = idLZWCompressor::Lookup(this, w: this->lzwData->codeWord, k: value);
  if ( v6 < 0 )
  {
    idLZWCompressor::WriteBits(this, value: v5, bits: *(_DWORD *)(v4 + 12292));
    if ( (unsigned __int8)idLZWCompressor::BumpBits(this: v7) == 0 )
    {
      codeWord = this->lzwData->codeWord;
      this->lzwData->dictionaryK[this->lzwData->nextCode] = v2;
      v9 = 2 * ((((unsigned __int16)v2 ^ (unsigned __int16)codeWord) & 0x3FF) + 2);
      this->lzwData->dictionaryW[this->lzwData->nextCode] = codeWord;
      this->nextHash[this->lzwData->nextCode] = *(_WORD *)((char *)&this->lzwData + v9);
      *(_WORD *)((char *)&this->lzwData + v9) = this->lzwData->nextCode++;
    }
    this->lzwData->codeWord = v2;
  }
  else
  {
    *(_DWORD *)(v4 + 12296) = v6;
  }
  if ( this->lzwData->bytesWritten >= this->maxSize - (this->lzwData->tempBits + this->lzwData->codeBits + 7) / 8 )
    this->overflowed = true;
}


// ========================================================================
// ?WriteRun@idZeroRunLengthCompressor@@QAA_NXZ
// EA  : 0x8289A4C0
// RVA : 0x0089A4C0
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idZeroRunLengthCompressor::WriteRun(idZeroRunLengthCompressor *this)
{
  idLZWCompressor *comp; // r3
  int zeroCount; // r10
  unsigned __int8 *v5; // r11
  int compressed; // r11

  if ( this->zeroCount > 0 )
  {
    if ( this->compressed + 2 > this->maxSize )
    {
      this->maxSize = -1;
      return 0;
    }
    comp = this->comp;
    if ( comp != nullptr )
    {
      idLZWCompressor::WriteByte(this: comp, value: 0);
      idLZWCompressor::WriteByte(this: this->comp, value: this->zeroCount);
    }
    else
    {
      *this->dest = 0;
      zeroCount = this->zeroCount;
      v5 = this->dest + 1;
      this->dest = v5;
      *v5 = zeroCount;
      ++this->dest;
    }
    compressed = this->compressed;
    this->zeroCount = 0;
    this->compressed = compressed + 2;
  }
  return 1;
}


// ========================================================================
// ?WriteByte@idZeroRunLengthCompressor@@QAA_NE@Z
// EA  : 0x8289A588
// RVA : 0x0089A588
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idZeroRunLengthCompressor::WriteByte(idZeroRunLengthCompressor *this, unsigned __int8 value)
{
  int v2; // r30
  idLZWCompressor *comp; // r3
  int v7; // r11

  v2 = value;
  if ( (value != 0 || this->zeroCount >= 255) && (unsigned __int8)idZeroRunLengthCompressor::WriteRun(this) == 0 )
    goto LABEL_4;
  if ( v2 != 0 )
  {
    if ( this->compressed + 1 > this->maxSize )
    {
LABEL_4:
      this->maxSize = -1;
      return 0;
    }
    comp = this->comp;
    if ( comp != nullptr )
    {
      idLZWCompressor::WriteByte(this: comp, value);
      ++this->compressed;
    }
    else
    {
      *this->dest = value;
      v7 = this->compressed + 1;
      ++this->dest;
      this->compressed = v7;
    }
    return 1;
  }
  else
  {
    ++this->zeroCount;
    return 1;
  }
}


// ========================================================================
// ?WriteBytes@idZeroRunLengthCompressor@@QAAXPAEH@Z
// EA  : 0x8289A668
// RVA : 0x0089A668
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idZeroRunLengthCompressor::WriteBytes(idZeroRunLengthCompressor *this, unsigned __int8 *src, int count)
{
  int i; // r27
  int v6; // r29
  idLZWCompressor *comp; // r3
  int v8; // r11

  if ( count > 0 )
  {
    for ( i = count; i != 0; --i )
    {
      v6 = *src;
      if ( *src == 0 && this->zeroCount < 255 || (unsigned __int8)idZeroRunLengthCompressor::WriteRun(this) != 0 )
      {
        if ( v6 != 0 )
        {
          if ( this->compressed + 1 <= this->maxSize )
          {
            comp = this->comp;
            if ( comp != nullptr )
            {
              idLZWCompressor::WriteByte(this: comp, value: v6);
              ++this->compressed;
            }
            else
            {
              *this->dest = v6;
              v8 = this->compressed + 1;
              ++this->dest;
              this->compressed = v8;
            }
          }
          else
          {
            this->maxSize = -1;
          }
        }
        else
        {
          ++this->zeroCount;
        }
      }
      else
      {
        this->maxSize = -1;
      }
      ++src;
    }
  }
}


// ========================================================================
// ?End@idZeroRunLengthCompressor@@QAAHXZ
// EA  : 0x8289A750
// RVA : 0x0089A750
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idZeroRunLengthCompressor::End(idZeroRunLengthCompressor *this)
{
  int result; // r3

  idZeroRunLengthCompressor::WriteRun(this);
  result = -1;
  if ( this->maxSize != -1 )
    return this->compressed;
  return result;
}


// ========================================================================
// ?ReadByte@idZeroRunLengthCompressor@@QAAEXZ
// EA  : 0x8289A790
// RVA : 0x0089A790
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

int __fastcall idZeroRunLengthCompressor::ReadByte(idZeroRunLengthCompressor *this)
{
  int compressed; // r11
  idLZWCompressor *comp; // r3
  int result; // r3
  unsigned __int8 *dest; // r11
  idLZWCompressor *v6; // r3
  int Byte; // r3
  unsigned __int8 *v8; // r11

  if ( this->zeroCount == 0 )
  {
    compressed = this->compressed;
    comp = this->comp;
    this->compressed = compressed + 1;
    if ( comp != nullptr )
    {
      result = idLZWCompressor::ReadByte(this: comp, ignoreOverflow: false);
    }
    else
    {
      dest = this->dest;
      result = *dest;
      this->dest = dest + 1;
    }
    if ( result != 0 )
      return (unsigned __int8)result;
    v6 = this->comp;
    ++this->compressed;
    if ( v6 != nullptr )
    {
      Byte = idLZWCompressor::ReadByte(this: v6, ignoreOverflow: false);
    }
    else
    {
      v8 = this->dest;
      Byte = *v8;
      this->dest = v8 + 1;
    }
    this->zeroCount = Byte;
  }
  --this->zeroCount;
  return 0;
}


// ========================================================================
// ?ReadBytes@idZeroRunLengthCompressor@@QAAXPAEH@Z
// EA  : 0x8289A860
// RVA : 0x0089A860
// PDB : w:\tech5\engine\network\lightweightcompression.cpp
// ========================================================================

void __fastcall idZeroRunLengthCompressor::ReadBytes(idZeroRunLengthCompressor *this, unsigned __int8 *dest, int count)
{
  int v4; // r30
  unsigned __int8 *v5; // r29
  idLZWCompressor *comp; // r3
  int Byte; // r3
  unsigned __int8 *v8; // r11
  unsigned __int8 v9; // r11
  idLZWCompressor *v10; // r3
  int v11; // r3
  unsigned __int8 *v12; // r11

  if ( count > 0 )
  {
    v4 = count;
    v5 = dest - 1;
    while ( 1 )
    {
      if ( this->zeroCount != 0 )
        goto LABEL_13;
      comp = this->comp;
      ++this->compressed;
      if ( comp != nullptr )
      {
        Byte = idLZWCompressor::ReadByte(this: comp, ignoreOverflow: false);
      }
      else
      {
        v8 = this->dest;
        Byte = *v8;
        this->dest = v8 + 1;
      }
      if ( Byte == 0 )
        break;
      v9 = Byte;
LABEL_14:
      --v4;
      *++v5 = v9;
      if ( v4 == 0 )
        return;
    }
    v10 = this->comp;
    ++this->compressed;
    if ( v10 != nullptr )
    {
      v11 = idLZWCompressor::ReadByte(this: v10, ignoreOverflow: false);
    }
    else
    {
      v12 = this->dest;
      v11 = *v12;
      this->dest = v12 + 1;
    }
    this->zeroCount = v11;
LABEL_13:
    v9 = 0;
    --this->zeroCount;
    goto LABEL_14;
  }
}

