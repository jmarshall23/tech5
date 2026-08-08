
// ========================================================================
// ?GetName@idCompressor_None@@UBAPBDXZ
// EA  : 0x82F03940
// RVA : 0x00F03940
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

char *__fastcall idCompressor_None::GetName(idCompressor_None *this)
{
  idFile *file; // r11

  file = this->file;
  if ( file != nullptr )
    return (char *)((const char *(*)(void))file->GetName)();
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetFullPath@idCompressor_None@@UBAPBDXZ
// EA  : 0x82F03970
// RVA : 0x00F03970
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

char *__fastcall idCompressor_None::GetFullPath(idCompressor_None *this)
{
  idFile *file; // r11

  file = this->file;
  if ( file != nullptr )
    return (char *)((const char *(*)(void))file->GetFullPath)();
  else
    return &byte_8200D768;
}


// ========================================================================
// ?Length@idCompressor_None@@UBA_JXZ
// EA  : 0x82F039A0
// RVA : 0x00F039A0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_None::Length(idCompressor_None *this)
{
  if ( this->file == nullptr )
    return 0;
  if ( this->compress )
    return (unsigned __int64)((__int64 (__fastcall *)(idCompressor_None *))this->GetCompressedSize)(a1: this) >> 32;
  return (unsigned __int64)this->file->Length(this: this->file) >> 32;
}


// ========================================================================
// ?Timestamp@idCompressor_None@@UBAIXZ
// EA  : 0x82F03A20
// RVA : 0x00F03A20
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

unsigned int __fastcall idCompressor_None::Timestamp(idCompressor_None *this)
{
  idFile *file; // r11

  file = this->file;
  if ( file != nullptr )
    return ((unsigned int (*)(void))file->Timestamp)();
  else
    return 0;
}


// ========================================================================
// ?Tell@idCompressor_None@@UBA_JXZ
// EA  : 0x82F03A48
// RVA : 0x00F03A48
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_None::Tell(idCompressor_None *this)
{
  idFile *file; // r11

  file = this->file;
  if ( file != nullptr )
    return (unsigned __int64)((__int64 (*)(void))file->Tell)() >> 32;
  else
    return 0;
}


// ========================================================================
// ?ForceFlush@idCompressor_None@@UAAXXZ
// EA  : 0x82F03A70
// RVA : 0x00F03A70
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_None::ForceFlush(idCompressor_None *this)
{
  idFile *file; // r11

  file = this->file;
  if ( file != nullptr )
    ((void (*)(void))file->ForceFlush)();
}


// ========================================================================
// ?Flush@idCompressor_None@@UAAXXZ
// EA  : 0x82F03A98
// RVA : 0x00F03A98
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_None::Flush(idCompressor_None *this)
{
  idFile *file; // r11

  file = this->file;
  if ( file != nullptr )
    ((void (*)(void))file->Flush)();
}


// ========================================================================
// ?Seek@idCompressor_None@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x82F03AC0
// RVA : 0x00F03AC0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_None::Seek(idCompressor_None *this, int a2, __int64 offset, fsOrigin_t origin)
{
  idLib::Error(fmt: "cannot seek on idCompressor", a2, offset, origin);
}


// ========================================================================
// ?Init@idCompressor_BitStream@@UAAXPAVidFile@@_NH@Z
// EA  : 0x82F03AD0
// RVA : 0x00F03AD0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_BitStream::Init(idCompressor_BitStream *this, idFile *f, bool compress, int wordLength)
{
  this->file = f;
  this->compress = compress;
  this->wordLength = wordLength;
  this->readTotalBytes = 0;
  this->readTotalBits = 0;
  this->readLength = 0;
  this->readByte = 0;
  this->readBit = 0;
  this->readData = nullptr;
  this->writeTotalBytes = 0;
  this->writeTotalBits = 0;
  this->writeLength = 0;
  this->writeByte = 0;
  this->writeBit = 0;
  this->writeData = nullptr;
}


// ========================================================================
// ?InitDecompress@idCompressor_BitStream@@IAAXPAXH@Z
// EA  : 0x82F03B18
// RVA : 0x00F03B18
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_BitStream::InitDecompress(
        idCompressor_BitStream *this,
        unsigned __int8 *outData,
        int outLength)
{
  if ( this->readLength == 0 )
  {
    this->readLength = this->file->Read(this: this->file, a2: this->buffer, a3: 512u);
    this->readData = this->buffer;
    this->readByte = 0;
    this->readBit = 0;
  }
  this->writeLength = outLength;
  this->writeData = outData;
  this->writeByte = 0;
  this->writeBit = 0;
}


// ========================================================================
// ?WriteBits@idCompressor_BitStream@@IAAXHH@Z
// EA  : 0x82F03B88
// RVA : 0x00F03B88
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_BitStream::WriteBits(idCompressor_BitStream *this, int value, int numBits)
{
  int v4; // r29
  int v5; // r30
  int writeByte; // r9
  unsigned __int8 *writeData; // r7
  int v8; // r5
  int v9; // r5
  int v10; // r9
  int writeBit; // r7
  int v12; // r11
  unsigned __int8 *v13; // r10
  unsigned __int8 v14; // r9
  int writeTotalBytes; // r10

  v4 = value;
  v5 = numBits;
  if ( this->writeBit == 0 && numBits == 8 )
  {
    writeByte = this->writeByte;
    if ( writeByte < this->writeLength )
    {
      writeData = this->writeData;
      v8 = this->writeTotalBits + 8;
      ++this->writeTotalBytes;
      this->writeTotalBits = v8;
      writeData[writeByte] = value;
      ++this->writeByte;
      return;
    }
  }
  this->writeTotalBits += numBits;
  if ( numBits != 0 )
  {
    do
    {
      if ( this->writeBit == 0 )
      {
        v9 = this->writeByte;
        if ( v9 >= this->writeLength )
        {
          if ( this->writeData != this->buffer )
          {
            this->writeBit = v5 & 7;
            writeTotalBytes = this->writeTotalBytes;
            this->writeByte = ((v5 & 7) != 0) + (v5 >> 3) + v9;
            this->writeTotalBytes = ((v5 & 7) != 0) + (v5 >> 3) + writeTotalBytes;
            return;
          }
          ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
          this->writeByte = 0;
        }
        this->writeData[this->writeByte] = 0;
        v10 = this->writeTotalBytes + 1;
        ++this->writeByte;
        this->writeTotalBytes = v10;
      }
      writeBit = this->writeBit;
      v12 = 8 - writeBit;
      if ( 8 - writeBit > v5 )
        v12 = v5;
      v5 -= v12;
      v13 = &this->writeData[this->writeByte];
      v14 = (((unsigned __int8)((1 << v12) - 1) & (unsigned __int8)v4) << writeBit) | *(v13 - 1);
      v4 >>= v12;
      *(v13 - 1) = v14;
      this->writeBit = (v12 + this->writeBit) & 7;
    }
    while ( v5 != 0 );
  }
}


// ========================================================================
// ?ReadBits@idCompressor_BitStream@@IAAHH@Z
// EA  : 0x82F03D28
// RVA : 0x00F03D28
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_BitStream::ReadBits(idCompressor_BitStream *this, int numBits)
{
  int v4; // r28
  int v5; // r30
  int readByte; // r11
  const unsigned __int8 *readData; // r7
  int v8; // r5
  int result; // r3
  int v10; // r7
  int v11; // r3
  int v12; // r9
  int readBit; // r10
  int v14; // r11
  char v15; // r6
  unsigned int v16; // r9
  int readTotalBytes; // r10
  int v18; // r6
  int v19; // r11

  v4 = 0;
  v5 = 0;
  if ( this->readBit == 0 && numBits == 8 )
  {
    readByte = this->readByte;
    if ( readByte < this->readLength )
    {
      readData = this->readData;
      v8 = this->readTotalBits + 8;
      ++this->readTotalBytes;
      this->readTotalBits = v8;
      result = readData[readByte];
      this->readByte = readByte + 1;
      return result;
    }
  }
  this->readTotalBits += numBits;
  if ( numBits <= 0 )
    return v4;
  while ( this->readBit != 0 )
  {
LABEL_11:
    readBit = this->readBit;
    v14 = 8 - readBit;
    if ( 8 - readBit > numBits - v5 )
      v14 = numBits - v5;
    v15 = this->readBit;
    v16 = this->readData[this->readByte - 1];
    this->readBit = (readBit + v14) & 7;
    v4 |= ((v16 >> v15) & ((1 << v14) - 1)) << v5;
    v5 += v14;
    if ( v5 >= numBits )
      return v4;
  }
  v10 = this->readByte;
  if ( v10 < this->readLength )
  {
LABEL_10:
    v12 = this->readTotalBytes + 1;
    ++this->readByte;
    this->readTotalBytes = v12;
    goto LABEL_11;
  }
  if ( this->readData == this->buffer )
  {
    v11 = ((int (__fastcall *)(idFile *))this->file->Read)(a1: this->file);
    this->readByte = 0;
    this->readLength = v11;
    if ( v11 == 0 )
      return v4;
    goto LABEL_10;
  }
  readTotalBytes = this->readTotalBytes;
  v18 = (numBits - v5) & 7;
  v19 = (numBits - v5) >> 3;
  this->readBit = v18;
  this->readByte = (v18 != 0) + v19 + v10;
  this->readTotalBytes = (v18 != 0) + v19 + readTotalBytes;
  return v4;
}


// ========================================================================
// ?WriteAlignedByte@idCompressor_BitStream@@IAAXE@Z
// EA  : 0x82F03ED0
// RVA : 0x00F03ED0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_BitStream::WriteAlignedByte(idCompressor_BitStream *this, unsigned __int8 value)
{
  int writeByte; // r5
  int v5; // r9
  unsigned __int8 *writeData; // r7
  int v7; // r6

  writeByte = this->writeByte;
  if ( writeByte < this->writeLength )
    goto LABEL_4;
  if ( this->writeData == this->buffer )
  {
    ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
    this->writeByte = 0;
LABEL_4:
    v5 = this->writeByte;
    writeData = this->writeData;
    v7 = this->writeTotalBytes + 1;
    this->writeTotalBits += 8;
    this->writeTotalBytes = v7;
    writeData[v5] = value;
    ++this->writeByte;
    return;
  }
  this->writeByte = writeByte + 1;
}


// ========================================================================
// ?ReadAlignedByte@idCompressor_BitStream@@IAAEXZ
// EA  : 0x82F03F80
// RVA : 0x00F03F80
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_BitStream::ReadAlignedByte(idCompressor_BitStream *this)
{
  int readByte; // r11
  int v3; // r11
  const unsigned __int8 *readData; // r8
  int v5; // r7
  int result; // r3

  readByte = this->readByte;
  if ( readByte < this->readLength )
    goto LABEL_4;
  if ( this->readData == this->buffer )
  {
    this->readLength = ((int (__fastcall *)(idFile *))this->file->Read)(a1: this->file);
    this->readByte = 0;
LABEL_4:
    v3 = this->readByte;
    readData = this->readData;
    v5 = this->readTotalBits + 8;
    ++this->readTotalBytes;
    this->readTotalBits = v5;
    result = readData[v3];
    this->readByte = v3 + 1;
    return result;
  }
  this->readByte = readByte + 1;
  return 0;
}


// ========================================================================
// ?WriteAlignedWord@idCompressor_BitStream@@IAAXG@Z
// EA  : 0x82F04038
// RVA : 0x00F04038
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_BitStream::WriteAlignedWord(idCompressor_BitStream *this, unsigned __int16 value)
{
  int v4; // r30
  int writeByte; // r5
  unsigned __int8 v6; // r6
  int v7; // r9

  v4 = 0;
  while ( 1 )
  {
    writeByte = this->writeByte;
    if ( writeByte >= this->writeLength )
      break;
LABEL_5:
    v6 = value >> v4;
    v4 += 8;
    this->writeData[this->writeByte++] = v6;
    if ( v4 > 8 )
    {
      v7 = this->writeTotalBits + 16;
      this->writeTotalBytes += 2;
      this->writeTotalBits = v7;
      return;
    }
  }
  if ( this->writeData == this->buffer )
  {
    ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
    this->writeByte = 0;
    goto LABEL_5;
  }
  this->writeByte = writeByte + 1;
}


// ========================================================================
// ?ReadAlignedWord@idCompressor_BitStream@@IAAGXZ
// EA  : 0x82F040F0
// RVA : 0x00F040F0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_BitStream::ReadAlignedWord(idCompressor_BitStream *this)
{
  int v2; // r30
  int v3; // r29
  int readByte; // r11
  int v5; // r11
  int v6; // r8
  int v8; // r9

  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    readByte = this->readByte;
    if ( readByte >= this->readLength )
      break;
LABEL_5:
    v5 = this->readByte;
    v6 = this->readData[v5];
    this->readByte = v5 + 1;
    v3 |= v6 << v2;
    v2 += 8;
    if ( v2 > 8 )
    {
      v8 = this->readTotalBits + 16;
      this->readTotalBytes += 2;
      this->readTotalBits = v8;
      return (unsigned __int16)v3;
    }
  }
  if ( this->readData == this->buffer )
  {
    this->readLength = ((int (__fastcall *)(idFile *))this->file->Read)(a1: this->file);
    this->readByte = 0;
    goto LABEL_5;
  }
  this->readByte = readByte + 2;
  return 0;
}


// ========================================================================
// ?Write@idCompressor_BitStream@@UAAIPBXI@Z
// EA  : 0x82F041B0
// RVA : 0x00F041B0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_BitStream::Write(idCompressor_BitStream *this, const unsigned __int8 *inData, int inLength)
{
  int writeLength; // r11
  int v5; // r26
  int v7; // r29
  int v8; // r30
  int v9; // r11
  const unsigned __int8 *readData; // r8
  int v11; // r6
  int readByte; // r8
  int v13; // r3
  int v14; // r9
  int v15; // r11
  char readBit; // r7
  unsigned int v17; // r4
  int readTotalBytes; // r9
  int v19; // r10
  BOOL v20; // r10
  int v21; // r11
  int v22; // r30
  int writeByte; // r10
  unsigned __int8 *writeData; // r8
  int v25; // r6
  int v26; // r5
  int v27; // r8
  int writeBit; // r7
  int v29; // r11
  unsigned __int8 *v30; // r10
  unsigned __int8 v31; // r9
  int writeTotalBytes; // r9
  int v33; // r11

  if ( this->compress && inLength != 0 )
  {
    writeLength = this->writeLength;
    this->readLength = inLength;
    this->readByte = 0;
    this->readBit = 0;
    this->readData = inData;
    if ( writeLength == 0 )
    {
      this->writeByte = 0;
      this->writeBit = 0;
      this->writeLength = 512;
      this->writeData = this->buffer;
    }
    v5 = inLength;
    while ( 1 )
    {
      v7 = 0;
      v8 = 0;
      if ( this->readBit != 0 || (v9 = this->readByte) >= this->readLength )
      {
        this->readTotalBits += 8;
        while ( 1 )
        {
          if ( this->readBit == 0 )
          {
            readByte = this->readByte;
            if ( readByte >= this->readLength )
            {
              if ( this->readData != this->buffer )
              {
                readTotalBytes = this->readTotalBytes;
                v19 = (8 - v8) & 7;
                this->readBit = v19;
                v20 = v19 != 0;
                v21 = (8 - v8) >> 3;
                this->readTotalBytes = readTotalBytes + v20 + v21;
                this->readByte = v20 + v21 + readByte;
                goto LABEL_20;
              }
              v13 = ((int (__fastcall *)(idFile *))this->file->Read)(a1: this->file);
              this->readByte = 0;
              this->readLength = v13;
              if ( v13 == 0 )
                goto LABEL_20;
            }
            v14 = this->readTotalBytes + 1;
            ++this->readByte;
            this->readTotalBytes = v14;
          }
          v15 = 8 - this->readBit;
          if ( v15 > 8 - v8 )
            v15 = 8 - v8;
          readBit = this->readBit;
          v17 = this->readData[this->readByte - 1];
          this->readBit = (this->readBit + v15) & 7;
          v7 |= ((v17 >> readBit) & ((1 << v15) - 1)) << v8;
          v8 += v15;
          if ( v8 >= 8 )
            goto LABEL_20;
        }
      }
      readData = this->readData;
      v11 = this->readTotalBytes + 1;
      this->readTotalBits += 8;
      this->readTotalBytes = v11;
      v7 = readData[v9];
      this->readByte = v9 + 1;
LABEL_20:
      v22 = 8;
      if ( this->writeBit == 0 )
      {
        writeByte = this->writeByte;
        if ( writeByte < this->writeLength )
        {
          writeData = this->writeData;
          v25 = this->writeTotalBytes + 1;
          this->writeTotalBits += 8;
          this->writeTotalBytes = v25;
          writeData[writeByte] = v7;
          ++this->writeByte;
          goto LABEL_34;
        }
      }
      this->writeTotalBits += 8;
      while ( this->writeBit != 0 )
      {
LABEL_29:
        writeBit = this->writeBit;
        v29 = 8 - writeBit;
        if ( 8 - writeBit > v22 )
          v29 = v22;
        v22 -= v29;
        v30 = &this->writeData[this->writeByte];
        v31 = (((unsigned __int8)((1 << v29) - 1) & (unsigned __int8)v7) << writeBit) | *(v30 - 1);
        v7 >>= v29;
        *(v30 - 1) = v31;
        this->writeBit = (v29 + this->writeBit) & 7;
        if ( v22 == 0 )
          goto LABEL_34;
      }
      v26 = this->writeByte;
      if ( v26 < this->writeLength )
        goto LABEL_28;
      if ( this->writeData == this->buffer )
        break;
      writeTotalBytes = this->writeTotalBytes;
      this->writeBit = v22 & 7;
      v33 = ((v22 & 7) != 0) + (v22 >> 3);
      this->writeByte = v33 + v26;
      this->writeTotalBytes = v33 + writeTotalBytes;
LABEL_34:
      if ( --v5 == 0 )
        return inLength;
    }
    ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
    this->writeByte = 0;
LABEL_28:
    this->writeData[this->writeByte] = 0;
    v27 = this->writeByte + 1;
    ++this->writeTotalBytes;
    this->writeByte = v27;
    goto LABEL_29;
  }
  return 0;
}


// ========================================================================
// ?FinishCompress@idCompressor_BitStream@@UAAXXZ
// EA  : 0x82F04500
// RVA : 0x00F04500
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_BitStream::FinishCompress(idCompressor_BitStream *this)
{
  if ( this->compress )
  {
    if ( this->writeByte != 0 )
      ((void (__fastcall *)(idFile *, unsigned __int8 *))this->file->Write)(a1: this->file, a2: this->buffer);
    this->writeLength = 0;
    this->writeByte = 0;
    this->writeBit = 0;
  }
}


// ========================================================================
// ?Read@idCompressor_BitStream@@UAAIPAXI@Z
// EA  : 0x82F04568
// RVA : 0x00F04568
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_BitStream::Read(
        idCompressor_BitStream *this,
        unsigned __int8 *outData,
        unsigned int outLength)
{
  int v5; // r26
  int readLength; // r6
  int v7; // r29
  int v8; // r30
  int v9; // r11
  int readTotalBits; // r9
  const unsigned __int8 *readData; // r7
  int readByte; // r7
  int v13; // r3
  int v14; // r9
  int readBit; // r10
  int v16; // r11
  char v17; // r5
  unsigned int v18; // r8
  int readTotalBytes; // r9
  int v20; // r6
  int v21; // r11
  int v22; // r30
  int writeByte; // r9
  unsigned __int8 *writeData; // r7
  int v25; // r5
  int v26; // r5
  int v27; // r9
  int writeBit; // r7
  int v29; // r11
  unsigned __int8 *v30; // r10
  unsigned __int8 v31; // r9
  int writeTotalBytes; // r10

  if ( !this->compress && outLength != 0 )
  {
    idCompressor_BitStream::InitDecompress(this, outData, outLength);
    v5 = 0;
    if ( outLength == 0 )
      return v5;
    while ( 1 )
    {
      readLength = this->readLength;
      if ( readLength < 0 )
        return v5;
      v7 = 0;
      v8 = 0;
      if ( this->readBit != 0 || (v9 = this->readByte) >= readLength )
      {
        this->readTotalBits += 8;
        while ( 1 )
        {
          if ( this->readBit == 0 )
          {
            readByte = this->readByte;
            if ( readByte >= readLength )
            {
              if ( this->readData != this->buffer )
              {
                readTotalBytes = this->readTotalBytes;
                v20 = (8 - v8) & 7;
                v21 = (8 - v8) >> 3;
                this->readBit = v20;
                this->readByte = (v20 != 0) + v21 + readByte;
                this->readTotalBytes = (v20 != 0) + readTotalBytes + v21;
                goto LABEL_19;
              }
              v13 = ((int (__fastcall *)(idFile *))this->file->Read)(a1: this->file);
              this->readByte = 0;
              readLength = v13;
              this->readLength = v13;
              if ( v13 == 0 )
                goto LABEL_19;
            }
            v14 = this->readTotalBytes + 1;
            ++this->readByte;
            this->readTotalBytes = v14;
          }
          readBit = this->readBit;
          v16 = 8 - readBit;
          if ( 8 - readBit > 8 - v8 )
            v16 = 8 - v8;
          v17 = this->readBit;
          v18 = this->readData[this->readByte - 1];
          this->readBit = (readBit + v16) & 7;
          v7 |= ((v18 >> v17) & ((1 << v16) - 1)) << v8;
          v8 += v16;
          if ( v8 >= 8 )
            goto LABEL_19;
        }
      }
      readTotalBits = this->readTotalBits;
      readData = this->readData;
      ++this->readTotalBytes;
      this->readTotalBits = readTotalBits + 8;
      v7 = readData[v9];
      this->readByte = v9 + 1;
LABEL_19:
      v22 = 8;
      if ( this->writeBit == 0 )
      {
        writeByte = this->writeByte;
        if ( writeByte < this->writeLength )
        {
          writeData = this->writeData;
          v25 = this->writeTotalBytes + 1;
          this->writeTotalBits += 8;
          this->writeTotalBytes = v25;
          writeData[writeByte] = v7;
          ++this->writeByte;
          goto LABEL_33;
        }
      }
      this->writeTotalBits += 8;
      while ( this->writeBit != 0 )
      {
LABEL_28:
        writeBit = this->writeBit;
        v29 = 8 - writeBit;
        if ( 8 - writeBit > v22 )
          v29 = v22;
        v22 -= v29;
        v30 = &this->writeData[this->writeByte];
        v31 = (((unsigned __int8)((1 << v29) - 1) & (unsigned __int8)v7) << writeBit) | *(v30 - 1);
        v7 >>= v29;
        *(v30 - 1) = v31;
        this->writeBit = (this->writeBit + v29) & 7;
        if ( v22 == 0 )
          goto LABEL_33;
      }
      v26 = this->writeByte;
      if ( v26 < this->writeLength )
        goto LABEL_27;
      if ( this->writeData == this->buffer )
        break;
      this->writeBit = v22 & 7;
      writeTotalBytes = this->writeTotalBytes;
      this->writeByte = ((v22 & 7) != 0) + (v22 >> 3) + v26;
      this->writeTotalBytes = ((v22 & 7) != 0) + (v22 >> 3) + writeTotalBytes;
LABEL_33:
      if ( ++v5 >= outLength )
        return v5;
    }
    ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
    this->writeByte = 0;
LABEL_27:
    this->writeData[this->writeByte] = 0;
    v27 = this->writeTotalBytes + 1;
    ++this->writeByte;
    this->writeTotalBytes = v27;
    goto LABEL_28;
  }
  return 0;
}


// ========================================================================
// ?GetCompressionRatio@idCompressor_BitStream@@UBAMXZ
// EA  : 0x82F048A0
// RVA : 0x00F048A0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

float __fastcall idCompressor_BitStream::GetCompressionRatio(idCompressor_BitStream *this, int a2, __int64 a3)
{
  __int64 v3; // r8
  __int64 v4; // fp0
  __int64 v5; // r8
  double v6; // fp1

  if ( this->compress )
  {
    LODWORD(v3) = this->readTotalBytes;
    HIDWORD(v3) = v3 - this->writeTotalBytes;
    v4 = v3;
    LODWORD(a3) = HIDWORD(v3);
  }
  else
  {
    LODWORD(v5) = this->writeTotalBytes;
    HIDWORD(v5) = v5 - this->readTotalBytes;
    LODWORD(a3) = HIDWORD(v5);
    v4 = v5;
  }
  v6 = (float)((float)((float)a3 * 100.0) / (float)v4);
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?BitsToRead@idCompressor_RunLength_ZeroBased@@AAA_NXZ
// EA  : 0x82F04920
// RVA : 0x00F04920
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

BOOL __fastcall idCompressor_RunLength_ZeroBased::BitsToRead(idCompressor_RunLength_ZeroBased *this)
{
  int readByte; // r11
  int readLength; // r10

  readByte = this->readByte;
  readLength = this->readLength;
  return readByte < readLength || readByte == readLength && this->readBit > 0;
}


// ========================================================================
// ?BitsToWrite@idCompressor_RunLength_ZeroBased@@AAA_NXZ
// EA  : 0x82F04958
// RVA : 0x00F04958
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

BOOL __fastcall idCompressor_RunLength_ZeroBased::BitsToWrite(idCompressor_RunLength_ZeroBased *this)
{
  int writeByte; // r11
  int writeLength; // r10

  writeByte = this->writeByte;
  writeLength = this->writeLength;
  return writeByte < writeLength || writeByte == writeLength && this->writeBit > 0;
}


// ========================================================================
// ?Init@idCompressor_RunLength_ZeroBased@@UAAXPAVidFile@@_NH@Z
// EA  : 0x82F04990
// RVA : 0x00F04990
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_RunLength_ZeroBased::Init(
        idCompressor_RunLength_ZeroBased *this,
        idFile *f,
        bool compress,
        int wordLength)
{
  int v4; // r10

  this->file = f;
  this->compress = compress;
  this->wordLength = wordLength;
  v4 = (wordLength + 1) / 2;
  this->readTotalBytes = 0;
  this->runBits = v4;
  this->readTotalBits = 0;
  this->readLength = 0;
  this->readByte = 0;
  this->readBit = 0;
  this->readData = nullptr;
  this->writeTotalBytes = 0;
  this->writeTotalBits = 0;
  this->writeLength = 0;
  this->writeByte = 0;
  this->writeBit = 0;
  this->writeData = nullptr;
  this->maxRun = (1 << v4) - 1;
  this->bp = 0;
  this->count = 0;
}


// ========================================================================
// ?WriteRun@idCompressor_RunLength_ZeroBased@@AAAXXZ
// EA  : 0x82F04A00
// RVA : 0x00F04A00
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_RunLength_ZeroBased::WriteRun(idCompressor_RunLength_ZeroBased *this)
{
  int count; // r10
  signed int maxRun; // r8
  int v4; // r26
  int v5; // r29
  int runBits; // r30
  int writeByte; // r10
  unsigned __int8 *writeData; // r9
  int v9; // r7
  int v10; // r5
  int v11; // r9
  int writeBit; // r7
  int v13; // r11
  unsigned __int8 *v14; // r10
  unsigned __int8 v15; // r9
  int writeTotalBytes; // r8
  BOOL v17; // r11

  if ( this->count > 0 )
  {
    idCompressor_BitStream::WriteBits(this, value: 0, numBits: this->wordLength);
    count = this->count;
    maxRun = this->maxRun;
    __twllei(maxRun, 0);
    __twlgei(maxRun & ~(__ROL4__(count - 1, 1) - 1), 0xFFFFFFFF);
    this->count = count - maxRun * ((count - 1) / maxRun);
    if ( (count - 1) / maxRun > 0 )
    {
      v4 = (count - 1) / maxRun;
      do
      {
        v5 = 0;
        runBits = this->runBits;
        if ( this->writeBit == 0 && runBits == 8 )
        {
          writeByte = this->writeByte;
          if ( writeByte < this->writeLength )
          {
            writeData = this->writeData;
            v9 = this->writeTotalBytes + 1;
            this->writeTotalBits += 8;
            this->writeTotalBytes = v9;
            writeData[writeByte] = 0;
            ++this->writeByte;
            goto LABEL_19;
          }
        }
        for ( this->writeTotalBits += runBits; runBits != 0; this->writeBit = (this->writeBit + v13) & 7 )
        {
          if ( this->writeBit == 0 )
          {
            v10 = this->writeByte;
            if ( v10 >= this->writeLength )
            {
              if ( this->writeData != this->idCompressor_BitStream::buffer )
              {
                writeTotalBytes = this->writeTotalBytes;
                this->writeBit = runBits & 7;
                v17 = (runBits & 7) != 0;
                this->writeByte = v17 + (runBits >> 3) + v10;
                this->writeTotalBytes = writeTotalBytes + v17 + (runBits >> 3);
                break;
              }
              ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
              this->writeByte = 0;
            }
            this->writeData[this->writeByte] = 0;
            v11 = this->writeTotalBytes + 1;
            ++this->writeByte;
            this->writeTotalBytes = v11;
          }
          writeBit = this->writeBit;
          v13 = 8 - writeBit;
          if ( 8 - writeBit > runBits )
            v13 = runBits;
          runBits -= v13;
          v14 = &this->writeData[this->writeByte];
          v15 = (((unsigned __int8)((1 << v13) - 1) & (unsigned __int8)v5) << writeBit) | *(v14 - 1);
          v5 >>= v13;
          *(v14 - 1) = v15;
        }
LABEL_19:
        --v4;
      }
      while ( v4 != 0 );
    }
    idCompressor_BitStream::WriteBits(this, value: this->count, numBits: this->runBits);
    this->count = 0;
  }
}


// ========================================================================
// ?CompressBlock@idCompressor_RunLength_ZeroBased@@AAAHPBEH@Z
// EA  : 0x82F04BF8
// RVA : 0x00F04BF8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_RunLength_ZeroBased::CompressBlock(
        idCompressor_RunLength_ZeroBased *this,
        const unsigned __int8 *block,
        int size)
{
  int writeLength; // r10
  int Bits; // r30

  writeLength = this->writeLength;
  this->readLength = size;
  this->readData = block;
  this->readByte = 0;
  this->readBit = 0;
  if ( writeLength == 0 )
  {
    this->writeByte = 0;
    this->writeBit = 0;
    this->writeLength = 512;
    this->writeData = this->idCompressor_BitStream::buffer;
  }
  while ( idCompressor_RunLength_ZeroBased::BitsToRead(this) )
  {
    Bits = idCompressor_BitStream::ReadBits(this, numBits: this->wordLength);
    if ( Bits != 0 )
    {
      idCompressor_RunLength_ZeroBased::WriteRun(this);
      idCompressor_BitStream::WriteBits(this, value: Bits, numBits: this->wordLength);
    }
    else
    {
      ++this->count;
    }
  }
  return this->readByte;
}


// ========================================================================
// ?Write@idCompressor_RunLength_ZeroBased@@UAAIPBXI@Z
// EA  : 0x82F04CD0
// RVA : 0x00F04CD0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

signed int __fastcall idCompressor_RunLength_ZeroBased::Write(
        idCompressor_RunLength_ZeroBased *this,
        char *inData,
        signed int inLength)
{
  int bp; // r11
  int wordLength; // r9
  int v9; // r30
  signed int v10; // r11

  if ( !this->compress || inLength == 0 )
    return 0;
  bp = this->bp;
  wordLength = this->wordLength;
  if ( bp + inLength >= wordLength )
  {
    v9 = 0;
    if ( bp > 0 )
    {
      memcpy(Dst: &this->buffer[bp], Src: inData, Size: wordLength - bp);
      v9 = idCompressor_RunLength_ZeroBased::CompressBlock(this, block: this->buffer, size: this->wordLength) - this->bp;
      this->bp = 0;
    }
    v10 = this->wordLength;
    __twllei(v10, 0);
    __twlgei(v10 & ~(__ROL4__(inLength - v9, 1) - 1), 0xFFFFFFFF);
    if ( (inLength - v9) / v10 > 0 )
      v9 += idCompressor_RunLength_ZeroBased::CompressBlock(
              this,
              block: (const unsigned __int8 *)&inData[v9],
              size: v10 * ((inLength - v9) / v10));
    if ( v9 < inLength )
    {
      memcpy(Dst: this->buffer, Src: &inData[v9], Size: inLength - v9);
      this->bp = this->bp - v9 + inLength;
    }
    return inLength;
  }
  else
  {
    memcpy(Dst: &this->buffer[bp], Src: inData, Size: inLength);
    this->bp += inLength;
    return inLength;
  }
}


// ========================================================================
// ?DecompressBlock@idCompressor_RunLength_ZeroBased@@AAAHPAEH@Z
// EA  : 0x82F04DF0
// RVA : 0x00F04DF0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_RunLength_ZeroBased::DecompressBlock(
        idCompressor_RunLength_ZeroBased *this,
        unsigned __int8 *block,
        int size)
{
  int Bits; // r4
  int v7; // r3
  int v8; // r30
  int v9; // r3

  if ( this->readLength == 0 )
  {
    this->readLength = this->file->Read(this: this->file, a2: this->idCompressor_BitStream::buffer, a3: 512u);
    this->readData = this->idCompressor_BitStream::buffer;
    this->readByte = 0;
    this->readBit = 0;
  }
  this->writeLength = size;
  this->writeData = block;
  this->writeBit = 0;
  for ( this->writeByte = 0; idCompressor_RunLength_ZeroBased::BitsToWrite(this); --this->count )
  {
    if ( this->count <= 0 )
      break;
    idCompressor_BitStream::WriteBits(this, value: 0, numBits: this->wordLength);
  }
  while ( idCompressor_RunLength_ZeroBased::BitsToWrite(this) )
  {
    if ( this->readLength <= 0 )
      break;
    Bits = idCompressor_BitStream::ReadBits(this, numBits: this->wordLength);
    if ( Bits != 0 )
    {
      idCompressor_BitStream::WriteBits(this, value: Bits, numBits: this->wordLength);
    }
    else
    {
      v7 = idCompressor_BitStream::ReadBits(this, numBits: this->runBits);
      v8 = 0;
      this->count = v7;
      if ( v7 == 0 )
      {
        do
        {
          if ( this->readLength <= 0 )
            break;
          v9 = idCompressor_BitStream::ReadBits(this, numBits: this->runBits);
          this->count = v9;
          ++v8;
        }
        while ( v9 == 0 );
      }
      for ( this->count += this->maxRun * v8; idCompressor_RunLength_ZeroBased::BitsToWrite(this); --this->count )
      {
        if ( this->count <= 0 )
          break;
        idCompressor_BitStream::WriteBits(this, value: 0, numBits: this->wordLength);
      }
    }
  }
  return this->writeByte;
}


// ========================================================================
// ?Init@idCompressor_Arithmetic@@UAAXPAVidFile@@_NH@Z
// EA  : 0x82F04FC0
// RVA : 0x00F04FC0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::Init(idCompressor_Arithmetic *this, idFile *f, bool compress, int wordLength)
{
  this->file = f;
  this->compress = compress;
  this->wordLength = wordLength;
  this->readTotalBytes = 0;
  this->readTotalBits = 0;
  this->readLength = 0;
  this->readByte = 0;
  this->readBit = 0;
  this->readData = nullptr;
  this->writeTotalBytes = 0;
  this->writeTotalBits = 0;
  this->writeLength = 0;
  this->writeByte = 0;
  this->writeBit = 0;
  this->writeData = nullptr;
  this->symbolBuffer = 0;
  this->symbolBit = 0;
}


// ========================================================================
// ?InitCode@idCompressor_Arithmetic@@AAAXXZ
// EA  : 0x82F05010
// RVA : 0x00F05010
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::InitCode(idCompressor_Arithmetic *this)
{
  int i; // r26
  int v3; // r29
  int v4; // r30
  int v5; // r8
  int readByte; // r8
  int v7; // r3
  int v8; // r9
  int v9; // r11
  char readBit; // r7
  unsigned int v11; // r4
  int readTotalBytes; // r9
  int v13; // r10
  BOOL v14; // r10
  int v15; // r11

  for ( i = 16; i != 0; --i )
  {
    v3 = 0;
    v4 = 0;
    v5 = this->readTotalBits + 1;
    this->code *= 2;
    this->readTotalBits = v5;
    while ( this->readBit != 0 )
    {
LABEL_8:
      v9 = 8 - this->readBit;
      if ( v9 > 1 - v4 )
        v9 = 1 - v4;
      readBit = this->readBit;
      v11 = this->readData[this->readByte - 1];
      this->readBit = (this->readBit + v9) & 7;
      v3 |= ((v11 >> readBit) & ((1 << v9) - 1)) << v4;
      v4 += v9;
      if ( v4 >= 1 )
        goto LABEL_13;
    }
    readByte = this->readByte;
    if ( readByte < this->readLength )
      goto LABEL_7;
    if ( this->readData == this->buffer )
    {
      v7 = ((int (__fastcall *)(idFile *))this->file->Read)(a1: this->file);
      this->readByte = 0;
      this->readLength = v7;
      if ( v7 == 0 )
        goto LABEL_13;
LABEL_7:
      v8 = this->readTotalBytes + 1;
      ++this->readByte;
      this->readTotalBytes = v8;
      goto LABEL_8;
    }
    readTotalBytes = this->readTotalBytes;
    v13 = (1 - v4) & 7;
    this->readBit = v13;
    v14 = v13 != 0;
    v15 = (1 - v4) >> 3;
    this->readTotalBytes = readTotalBytes + v14 + v15;
    this->readByte = v14 + v15 + readByte;
LABEL_13:
    this->code |= v3;
  }
}


// ========================================================================
// ?UpdateProbabilities@idCompressor_Arithmetic@@AAAXPAUidAcSymbol@1@@Z
// EA  : 0x82F05170
// RVA : 0x00F05170
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::UpdateProbabilities(
        idCompressor_Arithmetic *this,
        idCompressor_Arithmetic::idAcSymbol *symbol)
{
  int position; // r11
  int v3; // r11
  int v4; // r10
  unsigned __int8 **v5; // r11
  int v6; // ctr
  int v7; // r9

  position = symbol->position;
  v4 = 8 * (position + 73);
  v3 = position + 1;
  ++*(idCompressor_Arithmetic_vtbl **)((char *)&this->__vftable + v4);
  if ( v3 < 256 )
  {
    v6 = 256 - v3;
    v5 = &this->writeData + 2 * v3;
    do
    {
      v7 = (int)(v5[2] + 1);
      ++v5[1];
      v5 += 2;
      *v5 = (unsigned __int8 *)v7;
      --v6;
    }
    while ( v6 != 0 );
  }
  ++this->scale;
}


// ========================================================================
// ?ProbabilityForCount@idCompressor_Arithmetic@@AAAHI@Z
// EA  : 0x82F051D8
// RVA : 0x00F051D8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_Arithmetic::ProbabilityForCount(idCompressor_Arithmetic *this, unsigned int count)
{
  int v2; // r11
  int v3; // r7
  int v4; // r9
  int v5; // r10
  int v6; // r10

  v2 = 256;
  v3 = 0;
  while ( 1 )
  {
    v4 = v2 >> 1;
    v5 = v3 + (v2 >> 1);
    if ( count < this->probabilities[v5].high )
      break;
    v3 += v2 >> 1;
    v6 = 1;
LABEL_6:
    v2 -= v4;
    if ( v4 <= 0 )
      return v6 + v3;
  }
  if ( count < this->probabilities[v5].low )
  {
    v6 = 0;
    goto LABEL_6;
  }
  return v3 + (v2 >> 1);
}


// ========================================================================
// ?RemoveSymbolFromStream@idCompressor_Arithmetic@@AAAXPAUidAcSymbol@1@@Z
// EA  : 0x82F05240
// RVA : 0x00F05240
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::RemoveSymbolFromStream(
        idCompressor_Arithmetic *this,
        idCompressor_Arithmetic::idAcSymbol *symbol)
{
  int low; // r11
  unsigned int scale; // r8
  int readLength; // r7
  int v7; // r10
  unsigned int v8; // r9
  int high; // r9
  int v10; // r11
  unsigned __int16 code; // r7
  unsigned __int16 v12; // r9
  unsigned __int16 v13; // r8

  low = this->low;
  scale = this->scale;
  readLength = this->readLength;
  v7 = this->high - low + 1;
  v8 = symbol->high * v7 / scale;
  __twllei(scale, 0);
  __twllei(scale, 0);
  this->high = v8 + low - 1;
  this->low = symbol->low * v7 / scale + low;
  if ( readLength > 0 )
  {
    do
    {
      high = this->high;
      v10 = this->low;
      if ( ((v10 ^ high) & 0x8000) != 0 )
      {
        if ( ((v10 ^ high) & v10 & 0x4000) == 0 )
        {
          idCompressor_Arithmetic::UpdateProbabilities(this, symbol);
          return;
        }
        code = this->code;
        this->low = v10 & 0x3FFF;
        this->high = high | 0x4000;
        this->code = code ^ 0x4000;
      }
      v12 = this->code;
      v13 = (2 * this->high) | 1;
      this->low *= 2;
      this->high = v13;
      this->code = 2 * v12;
      this->code |= idCompressor_BitStream::ReadBits(this, numBits: 1);
    }
    while ( this->readLength > 0 );
  }
}


// ========================================================================
// ?GetByte@idCompressor_Arithmetic@@AAAHXZ
// EA  : 0x82F05368
// RVA : 0x00F05368
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_Arithmetic::GetByte(idCompressor_Arithmetic *this)
{
  int low; // r10
  int v3; // r10
  int v4; // r6
  unsigned int v5; // r5
  unsigned int v6; // r8
  unsigned int high; // r7
  idCompressor_Arithmetic::idAcSymbol v9; // [sp+50h] [-20h] BYREF

  low = this->low;
  v4 = this->code - low + 1;
  v3 = this->high - low;
  v5 = v4 * this->scale - 1;
  __twllei(v3 + 1, 0);
  v9.position = idCompressor_Arithmetic::ProbabilityForCount(this, count: v5 / (v3 + 1));
  v6 = this->probabilities[v9.position].low;
  high = this->probabilities[v9.position].high;
  this->symbolBuffer = v9.position;
  v9.low = v6;
  v9.high = high;
  idCompressor_Arithmetic::RemoveSymbolFromStream(this, symbol: &v9);
  return this->symbolBuffer;
}


// ========================================================================
// ?EncodeSymbol@idCompressor_Arithmetic@@AAAXPAUidAcSymbol@1@@Z
// EA  : 0x82F05400
// RVA : 0x00F05400
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::EncodeSymbol(
        idCompressor_Arithmetic *this,
        idCompressor_Arithmetic::idAcSymbol *symbol)
{
  int low; // r11
  unsigned int high; // r9
  unsigned int scale; // r8
  int v7; // r10
  unsigned int v8; // r10
  int v9; // r11
  unsigned int underflowBits; // r11
  unsigned int v11; // r7
  unsigned __int16 v12; // r9

  low = this->low;
  high = symbol->high;
  scale = this->scale;
  v7 = this->high - low + 1;
  __twllei(scale, 0);
  __twllei(scale, 0);
  this->high = high * v7 / scale + low - 1;
  this->low = symbol->low * v7 / scale + low;
  while ( 1 )
  {
    v8 = this->high;
    v9 = this->low;
    if ( ((v9 ^ v8) & 0x8000) != 0 )
      break;
    idCompressor_BitStream::WriteBits(this, value: v8 >> 15, numBits: 1);
    if ( this->underflowBits != 0 )
    {
      do
      {
        idCompressor_BitStream::WriteBits(this, value: ~this->high >> 15, numBits: 1);
        underflowBits = this->underflowBits;
        this->underflowBits = underflowBits - 1;
      }
      while ( underflowBits != 1 );
    }
LABEL_8:
    v12 = (2 * this->high) | 1;
    this->low *= 2;
    this->high = v12;
  }
  if ( ((v9 ^ v8) & v9 & 0x4000) != 0 )
  {
    v11 = this->underflowBits + 1;
    this->low = v9 & 0x3FFF;
    this->underflowBits = v11;
    this->high = v8 | 0x4000;
    goto LABEL_8;
  }
  idCompressor_Arithmetic::UpdateProbabilities(this, symbol);
}


// ========================================================================
// ?WriteOverflowBits@idCompressor_Arithmetic@@AAAXXZ
// EA  : 0x82F05530
// RVA : 0x00F05530
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::WriteOverflowBits(idCompressor_Arithmetic *this)
{
  unsigned int underflowBits; // r10
  int v3; // r30
  int v4; // r8
  int v5; // r29
  int writeByte; // r5
  int v7; // r9
  int writeBit; // r7
  int v9; // r11
  unsigned __int8 *v10; // r10
  unsigned __int8 v11; // r9
  int writeTotalBytes; // r10
  unsigned int v13; // r10

  idCompressor_BitStream::WriteBits(this, value: this->low >> 14, numBits: 1);
  underflowBits = this->underflowBits;
  this->underflowBits = underflowBits + 1;
  if ( underflowBits == -1 )
    goto LABEL_14;
  do
  {
    v3 = 1;
    v4 = ~this->low;
    ++this->writeTotalBits;
    v5 = v4 >> 14;
    while ( this->writeBit != 0 )
    {
LABEL_8:
      writeBit = this->writeBit;
      v9 = 8 - writeBit;
      if ( 8 - writeBit > v3 )
        v9 = v3;
      v3 -= v9;
      v10 = &this->writeData[this->writeByte];
      v11 = (((unsigned __int8)((1 << v9) - 1) & (unsigned __int8)v5) << writeBit) | *(v10 - 1);
      v5 >>= v9;
      *(v10 - 1) = v11;
      this->writeBit = (v9 + this->writeBit) & 7;
      if ( v3 == 0 )
        goto LABEL_13;
    }
    writeByte = this->writeByte;
    if ( writeByte < this->writeLength )
      goto LABEL_7;
    if ( this->writeData == this->buffer )
    {
      ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
      this->writeByte = 0;
LABEL_7:
      this->writeData[this->writeByte] = 0;
      v7 = this->writeTotalBytes + 1;
      ++this->writeByte;
      this->writeTotalBytes = v7;
      goto LABEL_8;
    }
    this->writeBit = v3 & 7;
    writeTotalBytes = this->writeTotalBytes;
    this->writeByte = ((v3 & 7) != 0) + (v3 >> 3) + writeByte;
    this->writeTotalBytes = ((v3 & 7) != 0) + (v3 >> 3) + writeTotalBytes;
LABEL_13:
    v13 = this->underflowBits - 1;
    this->underflowBits = v13;
  }
  while ( v13 != 0 );
LABEL_14:
  idCompressor_BitStream::WriteBits(this, value: 0, numBits: 14);
}


// ========================================================================
// ?Write@idCompressor_Arithmetic@@UAAIPBXI@Z
// EA  : 0x82F056B8
// RVA : 0x00F056B8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_Arithmetic::Write(
        idCompressor_Arithmetic *this,
        const unsigned __int8 *inData,
        int inLength)
{
  int writeLength; // r11
  int i; // r28
  int readTotalBytes; // r11
  unsigned __int8 *v8; // r10
  unsigned __int8 **p_writeData; // r11
  int j; // ctr
  int AlignedByte; // r3
  unsigned int high; // r5
  idCompressor_Arithmetic::idAcSymbol v14; // [sp+50h] [-50h] BYREF

  if ( !this->compress || inLength == 0 )
    return 0;
  writeLength = this->writeLength;
  this->readLength = inLength;
  this->readData = inData;
  this->readByte = 0;
  this->readBit = 0;
  if ( writeLength == 0 )
  {
    this->writeByte = 0;
    this->writeBit = 0;
    this->writeLength = 512;
    this->writeData = this->buffer;
  }
  for ( i = inLength; i != 0; --i )
  {
    readTotalBytes = this->readTotalBytes;
    if ( (readTotalBytes & 0x3FFF) == 0 )
    {
      if ( readTotalBytes != 0 )
        idCompressor_Arithmetic::WriteOverflowBits(this);
      this->high = -1;
      this->low = 0;
      v8 = nullptr;
      this->underflowBits = 0;
      p_writeData = &this->writeData;
      this->code = 0;
      for ( j = 256; j != 0; --j )
      {
        p_writeData[1] = v8;
        p_writeData += 2;
        *p_writeData = ++v8;
      }
      this->scale = 256;
    }
    AlignedByte = idCompressor_BitStream::ReadAlignedByte(this);
    v14.position = (unsigned __int8)AlignedByte;
    high = this->probabilities[(unsigned __int8)AlignedByte].high;
    v14.low = *(unsigned int *)((char *)&this->probabilities[0].low + ((8 * AlignedByte) & 0x7F8));
    v14.high = high;
    idCompressor_Arithmetic::EncodeSymbol(this, symbol: &v14);
  }
  return inLength;
}


// ========================================================================
// ?FinishCompress@idCompressor_Arithmetic@@UAAXXZ
// EA  : 0x82F057E8
// RVA : 0x00F057E8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::FinishCompress(idCompressor_Arithmetic *this)
{
  if ( this->compress )
  {
    idCompressor_Arithmetic::WriteOverflowBits(this);
    idCompressor_BitStream::FinishCompress(this);
  }
}


// ========================================================================
// ?Read@idCompressor_Arithmetic@@UAAIPAXI@Z
// EA  : 0x82F05828
// RVA : 0x00F05828
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

unsigned int __fastcall idCompressor_Arithmetic::Read(
        idCompressor_Arithmetic *this,
        unsigned __int8 *outData,
        unsigned int outLength)
{
  unsigned int i; // r28
  unsigned __int8 *v6; // r10
  unsigned __int8 **p_writeData; // r11
  int j; // ctr
  unsigned __int8 Byte; // r3

  if ( this->compress || outLength == 0 )
    return 0;
  idCompressor_BitStream::InitDecompress(this, outData, outLength);
  for ( i = 0; i < outLength; ++i )
  {
    if ( this->readLength <= 0 )
      break;
    if ( (this->writeTotalBytes & 0x3FFF) == 0 )
    {
      this->high = -1;
      this->low = 0;
      v6 = nullptr;
      this->underflowBits = 0;
      p_writeData = &this->writeData;
      this->code = 0;
      for ( j = 256; j != 0; --j )
      {
        p_writeData[1] = v6;
        p_writeData += 2;
        *p_writeData = ++v6;
      }
      this->scale = 256;
      idCompressor_Arithmetic::InitCode(this);
    }
    Byte = idCompressor_Arithmetic::GetByte(this);
    if ( this->readLength <= 0 )
      break;
    idCompressor_BitStream::WriteAlignedByte(this, value: Byte);
  }
  return i;
}


// ========================================================================
// ?Init@idCompressor_LZSS_ByteAligned@@UAAXPAVidFile@@_NH@Z
// EA  : 0x82F05910
// RVA : 0x00F05910
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZSS_ByteAligned::Init(
        idCompressor_LZSS_ByteAligned *this,
        idFile *f,
        bool compress,
        int wordLength)
{
  this->compress = compress;
  this->wordLength = wordLength;
  this->file = f;
  this->readTotalBytes = 0;
  this->readTotalBits = 0;
  this->readLength = 0;
  this->readByte = 0;
  this->readBit = 0;
  this->readData = nullptr;
  this->writeTotalBytes = 0;
  this->writeTotalBits = 0;
  this->writeLength = 0;
  this->writeByte = 0;
  this->writeBit = 0;
  this->writeData = nullptr;
  this->offsetBits = 16;
  this->lengthBits = 8;
  this->minMatchWords = 4;
  this->blockSize = 0;
  this->blockIndex = 0;
}


// ========================================================================
// ?GetHashKey@idCompressor_LZSS_ByteAligned@@ABAHH@Z
// EA  : 0x82F05988
// RVA : 0x00F05988
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_LZSS_ByteAligned::GetHashKey(idCompressor_LZSS_ByteAligned *this, __int16 startValue)
{
  int readByte; // r11
  int readLength; // r9
  __int16 v4; // r10
  __int16 v5; // r8

  readByte = this->readByte;
  readLength = this->readLength;
  if ( readByte < readLength )
    v4 = this->readData[readByte];
  else
    v4 = 0;
  if ( readByte + 1 < readLength )
    LOBYTE(v5) = this->readData[readByte + 1];
  else
    LOBYTE(v5) = 0;
  if ( readByte + 2 < readLength )
    v5 = (this->readData[readByte + 2] << 8) | (unsigned __int8)v5;
  else
    v5 = (unsigned __int8)v5;
  return (unsigned __int16)(2 * v5) ^ (unsigned __int16)((v4 << 8) | startValue);
}


// ========================================================================
// ?FinishCompress@idCompressor_LZW@@UAAXXZ
// EA  : 0x82F05A18
// RVA : 0x00F05A18
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZW::FinishCompress(idCompressor_LZW *this)
{
  if ( this->compress )
  {
    idCompressor_BitStream::WriteBits(this, value: this->codeWord, numBits: this->codeBits);
    idCompressor_BitStream::FinishCompress(this);
  }
}


// ========================================================================
// ?WriteChain@idCompressor_LZW@@IAAHH@Z
// EA  : 0x82F05A70
// RVA : 0x00F05A70
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_LZW::WriteChain(idCompressor_LZW *this, int code)
{
  int v3; // r11
  int v4; // r6
  int v5; // r28
  bool v6; // cr32
  unsigned __int8 *v7; // r11
  int v8; // r27
  unsigned __int8 *v9; // r29
  int writeByte; // r5
  unsigned __int8 v11; // r30
  int v12; // r9
  unsigned __int8 *writeData; // r7
  int v14; // r6
  _BYTE v16[64]; // [sp+50h] [-1040h] BYREF

  v3 = 0;
  do
  {
    v4 = *(int *)((char *)&this->dictionary[0].k + ((8 * code) & 0x7FF8));
    code = this->dictionary[code & 0xFFF].w;
    v16[v3++] = v4;
  }
  while ( code >= 0 && v3 < 4096 );
  v5 = v3 - 1;
  v6 = v3 - 1 < 0;
  v7 = &v16[v3 - 1];
  v8 = *v7;
  if ( !v6 )
  {
    v9 = v7;
    do
    {
      writeByte = this->writeByte;
      v11 = *v9;
      if ( writeByte >= this->writeLength )
      {
        if ( this->writeData != this->buffer )
        {
          this->writeByte = writeByte + 1;
          goto LABEL_10;
        }
        ((void (__fastcall *)(idFile *))this->file->Write)(a1: this->file);
        this->writeByte = 0;
      }
      v12 = this->writeByte;
      writeData = this->writeData;
      v14 = this->writeTotalBytes + 1;
      this->writeTotalBits += 8;
      this->writeTotalBytes = v14;
      writeData[v12] = v11;
      ++this->writeByte;
LABEL_10:
      --v5;
      --v9;
    }
    while ( v5 >= 0 );
  }
  return v8;
}


// ========================================================================
// ??1idCompressor_BitStream@@UAA@XZ
// EA  : 0x82F05B78
// RVA : 0x00F05B78
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_BitStream::~idCompressor_BitStream(idCompressor_BitStream *this)
{
  this->__vftable = (idCompressor_BitStream_vtbl *)&idCompressor_BitStream::`vftable';
  if ( this->compress )
  {
    if ( this->writeByte != 0 )
      ((void (__fastcall *)(idFile *, unsigned __int8 *))this->file->Write)(a1: this->file, a2: this->buffer);
    this->writeLength = 0;
    this->writeByte = 0;
    this->writeBit = 0;
  }
  this->__vftable = (idCompressor_BitStream_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$114788
// EA  : 0x82F05C08
// RVA : 0x00F05C08
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_114788()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetCompressedSize@idCompressor_BitStream@@UBAHXZ
// EA  : 0x82F05C30
// RVA : 0x00F05C30
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_BitStream::GetCompressedSize(idCompressor_BitStream *this)
{
  if ( this->compress )
    return this->writeTotalBytes;
  else
    return this->readTotalBytes;
}


// ========================================================================
// ?GetUncompressedSize@idCompressor_BitStream@@UBAHXZ
// EA  : 0x82F05C50
// RVA : 0x00F05C50
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_BitStream::GetUncompressedSize(idCompressor_BitStream *this)
{
  if ( this->compress )
    return this->readTotalBytes;
  else
    return this->writeTotalBytes;
}


// ========================================================================
// ?FinishCompress@idCompressor_RunLength_ZeroBased@@UAAXXZ
// EA  : 0x82F05CD0
// RVA : 0x00F05CD0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_RunLength_ZeroBased::FinishCompress(idCompressor_RunLength_ZeroBased *this)
{
  int bp; // r5

  if ( this->compress )
  {
    bp = this->bp;
    if ( bp > 0 )
    {
      idCompressor_RunLength_ZeroBased::CompressBlock(this, block: this->buffer, size: bp);
      idCompressor_RunLength_ZeroBased::WriteRun(this);
    }
  }
  if ( this->compress )
  {
    if ( this->writeByte != 0 )
      ((void (__fastcall *)(idFile *, unsigned __int8 *))this->file->Write)(
        a1: this->file,
        a2: this->idCompressor_BitStream::buffer);
    this->writeLength = 0;
    this->writeByte = 0;
    this->writeBit = 0;
  }
}


// ========================================================================
// ?Read@idCompressor_RunLength_ZeroBased@@UAAIPAXI@Z
// EA  : 0x82F05D60
// RVA : 0x00F05D60
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

signed int __fastcall idCompressor_RunLength_ZeroBased::Read(
        idCompressor_RunLength_ZeroBased *this,
        char *outData,
        signed int outLength)
{
  signed int bp; // r5
  unsigned __int8 *buffer; // r30
  int v9; // r30
  signed int wordLength; // r11
  int v11; // r3
  size_t v12; // r29

  if ( this->compress || outLength == 0 )
    return 0;
  bp = this->bp;
  if ( outLength > bp )
  {
    v9 = 0;
    if ( bp > 0 )
    {
      memcpy(Dst: outData, Src: this->buffer, Size: bp);
      v9 = this->bp;
      this->bp = 0;
    }
    wordLength = this->wordLength;
    __twllei(wordLength, 0);
    __twlgei(wordLength & ~(__ROL4__(outLength - v9, 1) - 1), 0xFFFFFFFF);
    if ( (outLength - v9) / wordLength > 0 )
      v9 += idCompressor_RunLength_ZeroBased::DecompressBlock(
              this,
              block: (unsigned __int8 *)&outData[v9],
              size: wordLength * ((outLength - v9) / wordLength));
    if ( v9 < outLength )
    {
      v11 = idCompressor_RunLength_ZeroBased::DecompressBlock(this, block: this->buffer, size: this->wordLength);
      v12 = outLength - v9;
      this->bp = v11;
      if ( v11 < outLength - v9 )
        v12 = v11;
      memcpy(Dst: &outData[v9], Src: this->buffer, Size: v12);
      memmove(Dst: this->buffer, Src: &this->buffer[v12], Size: this->bp - v12);
      v9 += v12;
      this->bp -= v12;
    }
    return v9;
  }
  else
  {
    buffer = this->buffer;
    memcpy(Dst: outData, Src: this->buffer, Size: outLength);
    memmove(Dst: buffer, Src: &this->buffer[outLength], Size: this->bp - outLength);
    this->bp -= outLength;
    return outLength;
  }
}


// ========================================================================
// ?FindByteMatch@idCompressor_LZSS_ByteAligned@@AAA_NHHAAH0@Z
// EA  : 0x82F05EB8
// RVA : 0x00F05EB8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

BOOL __fastcall idCompressor_LZSS_ByteAligned::FindByteMatch(
        idCompressor_LZSS_ByteAligned *this,
        int startWordOffset,
        __int16 startValue,
        int *wordOffset,
        int *numWords)
{
  int v8; // r27
  unsigned __int8 *v9; // r28
  int v10; // r26
  int i; // r10
  int *v12; // r6
  int v13; // r5
  int v14; // r8
  int j; // r11

  *wordOffset = startWordOffset;
  *numWords = this->minMatchWords - 1;
  v8 = this->blockSize - startWordOffset;
  if ( v8 >= (1 << this->lengthBits) + this->minMatchWords - 2 )
    v8 = (1 << this->lengthBits) + this->minMatchWords - 2;
  v9 = &this->block[startWordOffset];
  v10 = *(_DWORD *)v9;
  for ( i = this->hashTable[idCompressor_LZSS_ByteAligned::GetHashKey(this, startValue)]; i >= v13; i = this->hashNext[i] )
  {
    if ( *(_DWORD *)&this->block[i] == v10 )
    {
      v14 = v8;
      if ( v8 >= startWordOffset - i )
        v14 = startWordOffset - i;
      if ( v14 >= this->minMatchWords )
      {
        for ( j = 4; j < v14; ++j )
        {
          if ( this->block[i + j] != v9[j] )
            break;
        }
        if ( j > *numWords )
        {
          *numWords = j;
          *v12 = i;
          if ( *numWords == v8 )
            break;
        }
      }
    }
  }
  return *numWords >= this->minMatchWords;
}


// ========================================================================
// ?CompressBlock@idCompressor_LZSS_ByteAligned@@AAAXXZ
// EA  : 0x82F06030
// RVA : 0x00F06030
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZSS_ByteAligned::CompressBlock(idCompressor_LZSS_ByteAligned *this)
{
  int writeLength; // r11
  int *p_blockSize; // r23
  idCompressor_LZSS_ByteAligned_vtbl *v4; // r30
  __int16 AlignedByte; // r29
  int v6; // r28
  int v7; // r11
  int v8; // r29
  int *v9; // r28
  unsigned __int8 v10; // r3
  int readByte; // r11
  int readLength; // r8
  __int16 v13; // r10
  unsigned __int8 v14; // r9
  __int16 v15; // r11
  int v16; // r11
  int v17; // r11
  int v18; // [sp+50h] [-60h] BYREF
  int v19; // [sp+54h] [-5Ch] BYREF

  writeLength = this->writeLength;
  p_blockSize = &this->blockSize;
  this->readByte = 0;
  this->readBit = 0;
  this->readData = this->block;
  this->readLength = this->blockSize;
  if ( writeLength == 0 )
  {
    this->writeByte = 0;
    this->writeBit = 0;
    this->writeLength = 512;
    this->writeData = this->buffer;
  }
  memset(Dst: this->hashTable, Val: -1, Size: sizeof(this->hashTable));
  memset(Dst: this->hashNext, Val: -1, Size: sizeof(this->hashNext));
  v4 = nullptr;
  while ( this->readByte < this->readLength )
  {
    AlignedByte = (unsigned __int8)idCompressor_BitStream::ReadAlignedByte(this);
    if ( idCompressor_LZSS_ByteAligned::FindByteMatch(
           this,
           startWordOffset: (int)v4,
           startValue: AlignedByte,
           wordOffset: &v19,
           numWords: &v18) )
    {
      v6 = v18;
      idCompressor_BitStream::WriteAlignedByte(this, value: v18 - HIBYTE(this->minMatchWords) + 1);
      idCompressor_BitStream::WriteAlignedWord(this, value: (_WORD)v4 - v19);
      v7 = 4 * (idCompressor_LZSS_ByteAligned::GetHashKey(this, startValue: AlignedByte) + 32918);
      *((_DWORD *)&this->__vftable + (_DWORD)v4 + 98454) = *(idCompressor_LZSS_ByteAligned_vtbl **)((char *)&this->__vftable
                                                                                                  + v7);
      *(idCompressor_LZSS_ByteAligned_vtbl **)((char *)&this->__vftable + v7) = v4;
      v4 = (idCompressor_LZSS_ByteAligned_vtbl *)((char *)v4 + 1);
      if ( v6 > 1 )
      {
        v8 = v6 - 1;
        v9 = (int *)(&this->__vftable + (_DWORD)v4 + 98453);
        do
        {
          v10 = idCompressor_BitStream::ReadAlignedByte(this);
          readByte = this->readByte;
          readLength = this->readLength;
          if ( readByte < readLength )
            v13 = this->readData[readByte];
          else
            v13 = 0;
          if ( readByte + 1 < readLength )
            v14 = this->readData[readByte + 1];
          else
            v14 = 0;
          if ( readByte + 2 < readLength )
            v15 = this->readData[readByte + 2];
          else
            v15 = 0;
          --v8;
          v16 = 4 * ((unsigned __int16)((2 * ((v15 << 8) | v14)) ^ ((v13 << 8) | v10)) + 32918);
          *++v9 = *(int *)((char *)&this->__vftable + v16);
          *(idCompressor_LZSS_ByteAligned_vtbl **)((char *)&this->__vftable + v16) = v4;
          v4 = (idCompressor_LZSS_ByteAligned_vtbl *)((char *)v4 + 1);
        }
        while ( v8 != 0 );
      }
    }
    else
    {
      idCompressor_BitStream::WriteAlignedByte(this, value: 0);
      idCompressor_BitStream::WriteAlignedByte(this, value: AlignedByte);
      v17 = 4 * (idCompressor_LZSS_ByteAligned::GetHashKey(this, startValue: AlignedByte) + 32918);
      *((_DWORD *)&this->__vftable + (_DWORD)v4 + 98454) = *(idCompressor_LZSS_ByteAligned_vtbl **)((char *)&this->__vftable
                                                                                                  + v17);
      *(idCompressor_LZSS_ByteAligned_vtbl **)((char *)&this->__vftable + v17) = v4;
      v4 = (idCompressor_LZSS_ByteAligned_vtbl *)((char *)v4 + 1);
    }
  }
  *p_blockSize = 0;
}


// ========================================================================
// ?DecompressBlock@idCompressor_LZSS_ByteAligned@@AAAXXZ
// EA  : 0x82F06288
// RVA : 0x00F06288
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZSS_ByteAligned::DecompressBlock(idCompressor_LZSS_ByteAligned *this)
{
  int v2; // r28
  int AlignedByte; // r10
  int v4; // r29
  unsigned __int16 AlignedWord; // r3
  int v6; // r30
  char *v7; // r11
  char *v8; // r27
  unsigned __int8 v9; // r3
  int writeByte; // r11

  if ( this->readLength == 0 )
  {
    this->readLength = this->file->Read(this: this->file, a2: this->buffer, a3: 512u);
    this->readData = this->buffer;
    this->readByte = 0;
    this->readBit = 0;
  }
  this->writeByte = 0;
  this->writeBit = 0;
  this->writeLength = 0x20000;
  v2 = 0;
  this->writeData = this->block;
  do
  {
    AlignedByte = (unsigned __int8)idCompressor_BitStream::ReadAlignedByte(this);
    if ( this->readLength <= 0 )
      break;
    if ( AlignedByte != 0 )
    {
      v4 = this->minMatchWords + AlignedByte - 1;
      AlignedWord = idCompressor_BitStream::ReadAlignedWord(this);
      v6 = 0;
      if ( v4 > 0 )
      {
        v7 = (char *)this + v2 - AlignedWord;
        v2 += v4;
        v8 = v7 + 592;
        do
          idCompressor_BitStream::WriteAlignedByte(this, value: v8[v6++]);
        while ( v6 < v4 );
      }
    }
    else
    {
      v9 = idCompressor_BitStream::ReadAlignedByte(this);
      idCompressor_BitStream::WriteAlignedByte(this, value: v9);
      ++v2;
    }
  }
  while ( this->writeByte < this->writeLength );
  writeByte = this->writeByte;
  if ( writeByte >= 0x20000 )
    writeByte = 0x20000;
  this->blockSize = writeByte;
}


// ========================================================================
// ?Write@idCompressor_LZSS_ByteAligned@@UAAIPBXI@Z
// EA  : 0x82F063B0
// RVA : 0x00F063B0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

unsigned int __fastcall idCompressor_LZSS_ByteAligned::Write(
        idCompressor_LZSS_ByteAligned *this,
        char *inData,
        unsigned int inLength)
{
  unsigned int v6; // r30
  int *p_blockSize; // r29
  char *v8; // r4
  unsigned int v9; // r31
  unsigned __int8 *v10; // r3

  if ( !this->compress || inLength == 0 )
    return 0;
  v6 = 0;
  p_blockSize = &this->blockSize;
  do
  {
    v8 = &inData[v6];
    v9 = 0x20000 - *p_blockSize;
    v10 = &this->block[*p_blockSize];
    if ( inLength - v6 < v9 )
    {
      memcpy(Dst: v10, Src: v8, Size: inLength - v6);
      v9 = inLength - v6;
      *p_blockSize += inLength - v6;
    }
    else
    {
      memcpy(Dst: v10, Src: v8, Size: 0x20000 - *p_blockSize);
      *p_blockSize = 0x20000;
      idCompressor_LZSS_ByteAligned::CompressBlock(this);
      *p_blockSize = 0;
    }
    v6 += v9;
  }
  while ( v6 < inLength );
  return inLength;
}


// ========================================================================
// ?FinishCompress@idCompressor_LZSS_ByteAligned@@UAAXXZ
// EA  : 0x82F06470
// RVA : 0x00F06470
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZSS_ByteAligned::FinishCompress(idCompressor_LZSS_ByteAligned *this)
{
  if ( this->compress )
  {
    if ( this->blockSize != 0 )
      idCompressor_LZSS_ByteAligned::CompressBlock(this);
    idCompressor_BitStream::FinishCompress(this);
  }
}


// ========================================================================
// ?Read@idCompressor_LZSS_ByteAligned@@UAAIPAXI@Z
// EA  : 0x82F064C8
// RVA : 0x00F064C8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

unsigned int __fastcall idCompressor_LZSS_ByteAligned::Read(
        idCompressor_LZSS_ByteAligned *this,
        char *outData,
        unsigned int outLength)
{
  int *p_blockSize; // r23
  unsigned int v7; // r29
  int v8; // r10
  int blockIndex; // r11
  int *p_blockIndex; // r30
  size_t v11; // r31
  char *v12; // r3
  unsigned __int8 *v13; // r4

  if ( this->compress || outLength == 0 )
    return 0;
  p_blockSize = &this->blockSize;
  if ( this->blockSize == 0 )
    idCompressor_LZSS_ByteAligned::DecompressBlock(this);
  v7 = 0;
  if ( outLength == 0 )
    return outLength;
  while ( 1 )
  {
    v8 = *p_blockSize;
    if ( *p_blockSize == 0 )
      break;
    blockIndex = this->blockIndex;
    p_blockIndex = &this->blockIndex;
    v11 = v8 - blockIndex;
    v12 = &outData[v7];
    v13 = &this->block[blockIndex];
    if ( outLength - v7 <= v8 - blockIndex )
    {
      memcpy(Dst: v12, Src: v13, Size: outLength - v7);
      v11 = outLength - v7;
      *p_blockIndex += outLength - v7;
    }
    else
    {
      memcpy(Dst: v12, Src: v13, Size: v11);
      idCompressor_LZSS_ByteAligned::DecompressBlock(this);
      *p_blockIndex = 0;
    }
    v7 += v11;
    if ( v7 >= outLength )
      return outLength;
  }
  return v7;
}


// ========================================================================
// ?Init@idCompressor_LZW@@UAAXPAVidFile@@_NH@Z
// EA  : 0x82F065B0
// RVA : 0x00F065B0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZW::Init(idCompressor_LZW *this, idFile *f, bool compress, int wordLength)
{
  unsigned __int8 *v5; // r11
  unsigned __int8 **p_writeData; // r10
  int v7; // ctr
  int *hash; // r3
  int *indexChain; // r3

  this->file = f;
  this->compress = compress;
  this->wordLength = 8;
  this->readTotalBytes = 0;
  v5 = nullptr;
  p_writeData = &this->writeData;
  this->readTotalBits = 0;
  v7 = 256;
  this->readLength = 0;
  this->readByte = 0;
  this->readBit = 0;
  this->readData = nullptr;
  this->writeTotalBytes = 0;
  this->writeTotalBits = 0;
  this->writeLength = 0;
  this->writeByte = 0;
  this->writeBit = 0;
  this->writeData = nullptr;
  do
  {
    p_writeData[1] = v5++;
    p_writeData += 2;
    *p_writeData = (unsigned __int8 *)-1;
    --v7;
  }
  while ( v7 != 0 );
  hash = this->index.hash;
  if ( hash != idHashIndex::INVALID_INDEX )
    memset(Dst: hash, Val: 255, Size: 4 * this->index.hashSize);
  indexChain = this->index.indexChain;
  if ( indexChain != idHashIndex::INVALID_INDEX )
    memset(Dst: indexChain, Val: 255, Size: 4 * this->index.indexSize);
  this->blockSize = 0;
  this->codeBits = 9;
  this->nextCode = 256;
  this->blockIndex = 0;
  this->codeWord = -1;
  this->oldCode = -1;
}


// ========================================================================
// ?Lookup@idCompressor_LZW@@IAAHHH@Z
// EA  : 0x82F066C8
// RVA : 0x00F066C8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_LZW::Lookup(idCompressor_LZW *this, int w, int k)
{
  int lookupMask; // r7
  int v5; // r11

  if ( w == -1 )
    return k;
  lookupMask = this->index.lookupMask;
  v5 = this->index.hash[(w ^ k) & this->index.hashMask & lookupMask];
  if ( v5 < 0 )
    return -1;
  while ( this->dictionary[v5].k != k || this->dictionary[v5].w != w )
  {
    v5 = this->index.indexChain[lookupMask & v5];
    if ( v5 < 0 )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?BumpBits@idCompressor_LZW@@IAA_NXZ
// EA  : 0x82F06760
// RVA : 0x00F06760
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_LZW::BumpBits(idCompressor_LZW *this)
{
  int *p_codeBits; // r11
  int codeBits; // r10
  int v3; // r10

  p_codeBits = &this->codeBits;
  codeBits = this->codeBits;
  if ( this->nextCode != 1 << codeBits )
    return 0;
  v3 = codeBits + 1;
  *p_codeBits = v3;
  if ( v3 <= 12 )
    return 0;
  this->nextCode = 256;
  *p_codeBits = 9;
  idHashIndex::Clear(this: &this->index);
  return 1;
}


// ========================================================================
// ?Write@idCompressor_LZW@@UAAIPBXI@Z
// EA  : 0x82F067E8
// RVA : 0x00F067E8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

int __fastcall idCompressor_LZW::Write(idCompressor_LZW *this, const unsigned __int8 *inData, int inLength)
{
  int writeLength; // r10
  int v6; // r25
  int *p_codeWord; // r29
  int AlignedByte; // r30
  int v9; // r4
  int v10; // r3
  int v11; // r10
  int v12; // r4

  writeLength = this->writeLength;
  this->readLength = inLength;
  this->readData = inData;
  this->readByte = 0;
  this->readBit = 0;
  if ( writeLength == 0 )
  {
    this->writeByte = 0;
    this->writeBit = 0;
    this->writeLength = 512;
    this->writeData = this->buffer;
  }
  if ( inLength != 0 )
  {
    v6 = inLength;
    p_codeWord = &this->codeWord;
    do
    {
      AlignedByte = (unsigned __int8)idCompressor_BitStream::ReadAlignedByte(this);
      v10 = idCompressor_LZW::Lookup(this, w: *p_codeWord, k: AlignedByte);
      if ( v10 < 0 )
      {
        idCompressor_BitStream::WriteBits(this, value: v9, numBits: this->codeBits);
        if ( (unsigned __int8)idCompressor_LZW::BumpBits(this) == 0 )
        {
          v11 = *p_codeWord;
          v12 = *p_codeWord ^ AlignedByte;
          this->dictionary[this->nextCode].k = AlignedByte;
          this->dictionary[this->nextCode].w = v11;
          idHashIndex::Add(this: &this->index, key: v12, index: this->nextCode);
          ++this->nextCode;
        }
        *p_codeWord = AlignedByte;
      }
      else
      {
        *p_codeWord = v10;
      }
      --v6;
    }
    while ( v6 != 0 );
  }
  return inLength;
}


// ========================================================================
// ?DecompressBlock@idCompressor_LZW@@IAAXXZ
// EA  : 0x82F06908
// RVA : 0x00F06908
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZW::DecompressBlock(idCompressor_LZW *this)
{
  int *p_codeBits; // r25
  int Bits; // r22
  int oldCode; // r4
  int *p_oldCode; // r24
  int writeByte; // r11
  int *p_nextCode; // r30
  int v8; // r26
  idHashIndex *p_index; // r31
  int v10; // r27
  int v11; // r28
  int indexSize; // r11
  int v13; // r5
  int v14; // r10
  int v15; // r11
  int v16; // r9
  int *indexChain; // r3
  char v18; // r11

  if ( this->readLength == 0 )
  {
    this->readLength = this->file->Read(this: this->file, a2: this->buffer, a3: 512u);
    this->readData = this->buffer;
    this->readByte = 0;
    this->readBit = 0;
  }
  this->writeByte = 0;
  this->writeBit = 0;
  this->writeLength = 0x8000;
  this->writeData = this->block;
  do
  {
    if ( this->readLength <= 0 )
      break;
    p_codeBits = &this->codeBits;
    Bits = idCompressor_BitStream::ReadBits(this, numBits: this->codeBits);
    if ( this->readLength == 0 )
      break;
    oldCode = this->oldCode;
    p_oldCode = &this->oldCode;
    if ( oldCode == -1 )
    {
      idCompressor_BitStream::WriteAlignedByte(this, value: Bits);
    }
    else
    {
      p_nextCode = &this->nextCode;
      if ( Bits < this->nextCode )
      {
        v8 = idCompressor_LZW::WriteChain(this, code: Bits);
      }
      else
      {
        v8 = idCompressor_LZW::WriteChain(this, code: oldCode);
        idCompressor_BitStream::WriteAlignedByte(this, value: v8);
      }
      p_index = &this->index;
      v10 = *p_oldCode;
      this->dictionary[*p_nextCode].k = v8;
      this->dictionary[*p_nextCode].w = v10;
      v11 = *p_nextCode;
      indexSize = this->index.indexSize;
      if ( this->index.hash == idHashIndex::INVALID_INDEX )
      {
        if ( v11 >= indexSize )
          indexSize = v11 + 1;
        idHashIndex::Allocate(this: &this->index, newHashSize: this->index.hashSize, newIndexSize: indexSize);
      }
      else if ( v11 >= indexSize )
      {
        idHashIndex::ResizeIndex(this: &this->index, newIndexSize: v11 + 1);
      }
      v13 = (v10 ^ v8) & this->index.hashMask;
      this->index.indexChain[v11] = this->index.hash[v13];
      p_index->hash[v13] = v11;
      v14 = *p_codeBits;
      v15 = *p_nextCode + 1;
      v16 = 1 << *p_codeBits;
      *p_nextCode = v15;
      if ( v15 == v16 && (*p_codeBits = v14 + 1, v14 + 1 > 12) )
      {
        *p_nextCode = 256;
        *p_codeBits = 9;
        if ( p_index->hash != idHashIndex::INVALID_INDEX )
          memset(Dst: p_index->hash, Val: 255, Size: 4 * this->index.hashSize);
        indexChain = this->index.indexChain;
        if ( indexChain != idHashIndex::INVALID_INDEX )
          memset(Dst: indexChain, Val: 255, Size: 4 * this->index.indexSize);
        v18 = 1;
      }
      else
      {
        v18 = 0;
      }
      if ( v18 != 0 )
      {
        *p_oldCode = -1;
        continue;
      }
    }
    *p_oldCode = Bits;
  }
  while ( this->writeByte < this->writeLength - 4096 );
  writeByte = this->writeByte;
  if ( writeByte >= 0x8000 )
    this->blockSize = 0x8000;
  else
    this->blockSize = writeByte;
}


// ========================================================================
// ??1idCompressor_RunLength_ZeroBased@@UAA@XZ
// EA  : 0x82F06BC0
// RVA : 0x00F06BC0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_RunLength_ZeroBased::~idCompressor_RunLength_ZeroBased(
        idCompressor_RunLength_ZeroBased *this)
{
  this->__vftable = (idCompressor_RunLength_ZeroBased_vtbl *)&idCompressor_RunLength_ZeroBased::`vftable';
  idCompressor_RunLength_ZeroBased::FinishCompress(this);
  idCompressor_BitStream::~idCompressor_BitStream(this);
}


// ========================================================================
// __unwind$115538
// EA  : 0x82F06C10
// RVA : 0x00F06C10
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_115538()
{
  int v0; // r12

  idCompressor_BitStream::~idCompressor_BitStream(this: *(idCompressor_BitStream **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idCompressor_Arithmetic@@UAA@XZ
// EA  : 0x82F06CA0
// RVA : 0x00F06CA0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_Arithmetic::~idCompressor_Arithmetic(idCompressor_Arithmetic *this)
{
  this->__vftable = (idCompressor_Arithmetic_vtbl *)&idCompressor_Arithmetic::`vftable';
  if ( this->compress )
  {
    idCompressor_Arithmetic::WriteOverflowBits(this);
    idCompressor_BitStream::FinishCompress(this);
  }
  idCompressor_BitStream::~idCompressor_BitStream(this);
}


// ========================================================================
// __unwind$115657
// EA  : 0x82F06D04
// RVA : 0x00F06D04
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_115657()
{
  int v0; // r12

  idCompressor_BitStream::~idCompressor_BitStream(this: *(idCompressor_BitStream **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idCompressor_LZSS_ByteAligned@@UAA@XZ
// EA  : 0x82F06D98
// RVA : 0x00F06D98
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZSS_ByteAligned::~idCompressor_LZSS_ByteAligned(idCompressor_LZSS_ByteAligned *this)
{
  this->__vftable = (idCompressor_LZSS_ByteAligned_vtbl *)&idCompressor_LZSS_ByteAligned::`vftable';
  if ( this->compress )
  {
    if ( this->blockSize != 0 )
      idCompressor_LZSS_ByteAligned::CompressBlock(this);
    idCompressor_BitStream::FinishCompress(this);
  }
  idCompressor_BitStream::~idCompressor_BitStream(this);
}


// ========================================================================
// __unwind$115790
// EA  : 0x82F06E10
// RVA : 0x00F06E10
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_115790()
{
  int v0; // r12

  idCompressor_BitStream::~idCompressor_BitStream(this: *(idCompressor_BitStream **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idCompressor_LZW@@QAA@XZ
// EA  : 0x82F06EA0
// RVA : 0x00F06EA0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

idCompressor_LZW *__fastcall idCompressor_LZW::idCompressor_LZW(idCompressor_LZW *this)
{
  idFile::idFile(this);
  this->file = nullptr;
  this->compress = true;
  this->__vftable = (idCompressor_LZW_vtbl *)&idCompressor_LZW::`vftable';
  this->index.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->index, initialHashSize: 1024, initialIndexSize: 1024);
  return this;
}


// ========================================================================
// __unwind$115822
// EA  : 0x82F06F18
// RVA : 0x00F06F18
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_115822()
{
  int v0; // r12

  idCompressor_BitStream::~idCompressor_BitStream(this: *(idCompressor_BitStream **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idCompressor_LZW@@UAA@XZ
// EA  : 0x82F06F48
// RVA : 0x00F06F48
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void __fastcall idCompressor_LZW::~idCompressor_LZW(idCompressor_LZW *this)
{
  this->__vftable = (idCompressor_LZW_vtbl *)&idCompressor_LZW::`vftable';
  if ( this->compress )
  {
    idCompressor_BitStream::WriteBits(this, value: this->codeWord, numBits: this->codeBits);
    idCompressor_BitStream::FinishCompress(this);
  }
  idHashIndex::Free(this: &this->index);
  idCompressor_BitStream::~idCompressor_BitStream(this);
}


// ========================================================================
// __unwind$115863
// EA  : 0x82F06FD0
// RVA : 0x00F06FD0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_115863()
{
  int v0; // r12

  idCompressor_BitStream::~idCompressor_BitStream(this: *(idCompressor_BitStream **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$115864
// EA  : 0x82F06FF8
// RVA : 0x00F06FF8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_115864()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 33348));
}


// ========================================================================
// ?Read@idCompressor_LZW@@UAAIPAXI@Z
// EA  : 0x82F07090
// RVA : 0x00F07090
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

unsigned int __fastcall idCompressor_LZW::Read(idCompressor_LZW *this, char *outData, unsigned int outLength)
{
  int *p_blockSize; // r22
  unsigned int v7; // r29
  int v8; // r10
  int blockIndex; // r11
  int *p_blockIndex; // r30
  size_t v11; // r31
  char *v12; // r3
  unsigned __int8 *v13; // r4

  if ( this->compress || outLength == 0 )
    return 0;
  p_blockSize = &this->blockSize;
  if ( this->blockSize == 0 )
    idCompressor_LZW::DecompressBlock(this);
  v7 = 0;
  if ( outLength == 0 )
    return outLength;
  while ( 1 )
  {
    v8 = *p_blockSize;
    if ( *p_blockSize == 0 )
      break;
    blockIndex = this->blockIndex;
    p_blockIndex = &this->blockIndex;
    v11 = v8 - blockIndex;
    v12 = &outData[v7];
    v13 = &this->block[blockIndex];
    if ( outLength - v7 < v8 - blockIndex )
    {
      memcpy(Dst: v12, Src: v13, Size: outLength - v7);
      v11 = outLength - v7;
      *p_blockIndex += outLength - v7;
    }
    else
    {
      memcpy(Dst: v12, Src: v13, Size: v11);
      idCompressor_LZW::DecompressBlock(this);
      *p_blockIndex = 0;
    }
    v7 += v11;
    if ( v7 >= outLength )
      return outLength;
  }
  return v7;
}


// ========================================================================
// ?AllocRunLength_ZeroBased@idCompressor@@SAPAV1@XZ
// EA  : 0x82F07188
// RVA : 0x00F07188
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

idCompressor *__fastcall idCompressor::AllocRunLength_ZeroBased()
{
  idFile *v0; // r3
  idFile *v1; // r30

  v0 = (idFile *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                   size: 0x274u,
                   tag: TAG_FILE,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  idFile::idFile(this: v0);
  v1[1].__vftable = nullptr;
  v1->__vftable = (idFile_vtbl *)&idCompressor_RunLength_ZeroBased::`vftable';
  HIBYTE(v1[1].uniqID) = 1;
  return (idCompressor *)v1;
}


// ========================================================================
// __unwind$116043
// EA  : 0x82F0721C
// RVA : 0x00F0721C
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_116043()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?AllocArithmetic@idCompressor@@SAPAV1@XZ
// EA  : 0x82F07250
// RVA : 0x00F07250
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

idCompressor *__fastcall idCompressor::AllocArithmetic()
{
  idFile *v0; // r3
  idFile *v1; // r30

  v0 = (idFile *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                   size: 0xA5Cu,
                   tag: TAG_FILE,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  idFile::idFile(this: v0);
  v1[1].__vftable = nullptr;
  v1->__vftable = (idFile_vtbl *)&idCompressor_Arithmetic::`vftable';
  HIBYTE(v1[1].uniqID) = 1;
  return (idCompressor *)v1;
}


// ========================================================================
// __unwind$116186
// EA  : 0x82F072E4
// RVA : 0x00F072E4
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_116186()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?AllocLZSS_ByteAligned@idCompressor@@SAPAV1@XZ
// EA  : 0x82F07318
// RVA : 0x00F07318
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

idCompressor *__fastcall idCompressor::AllocLZSS_ByteAligned()
{
  idFile *v0; // r3
  idFile *v1; // r30

  v0 = (idFile *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                   size: 0xE0258u,
                   tag: TAG_FILE,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  idFile::idFile(this: v0);
  v1[1].__vftable = nullptr;
  v1->__vftable = (idFile_vtbl *)&idCompressor_LZSS_ByteAligned::`vftable';
  HIBYTE(v1[1].uniqID) = 1;
  return (idCompressor *)v1;
}


// ========================================================================
// __unwind$116351
// EA  : 0x82F073B0
// RVA : 0x00F073B0
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_116351()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?AllocLZW@idCompressor@@SAPAV1@XZ
// EA  : 0x82F073E8
// RVA : 0x00F073E8
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

idCompressor_LZW *__fastcall idCompressor::AllocLZW()
{
  idCompressor_LZW *v0; // r3

  v0 = (idCompressor_LZW *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x1027Cu,
                             tag: TAG_FILE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    return idCompressor_LZW::idCompressor_LZW(this: v0);
  else
    return nullptr;
}


// ========================================================================
// __unwind$116402
// EA  : 0x82F07454
// RVA : 0x00F07454
// PDB : w:\tech5\shared\idlib\filesystem\compressor.cpp
// ========================================================================

void _unwind_116402()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_FILE);
}

