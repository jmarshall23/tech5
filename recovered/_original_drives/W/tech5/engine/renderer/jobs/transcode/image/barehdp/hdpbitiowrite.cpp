
// ========================================================================
// ?WriteBits16@@YAXPIAUhdpBitIO_t@@II@Z
// EA  : 0x828ECA50
// RVA : 0x008ECA50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitiowrite.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall WriteBits16(hdpBitIO_t *pIO, unsigned int uiBits, char cBits)
{
  __int128 v3; // r7 OVERLAPPED
  unsigned __int64 bitCnt; // r11
  unsigned __int8 *byteBufCur; // r9
  unsigned int byteCount; // r8
  int v7; // r3
  unsigned __int64 v8; // r11

  *((_QWORD *)&v3 + 1) = pIO->bitBuff;
  bitCnt = pIO->bitCnt;
  byteBufCur = pIO->byteBufCur;
  byteCount = pIO->byteCount;
  DWORD2(v3) = ~(-1 << cBits);
  LODWORD(bitCnt) = bitCnt + HIDWORD(bitCnt);
  LODWORD(v3) = DWORD2(v3) & ((_QWORD)v3 << SBYTE3(bitCnt) >> 32) | ((_QWORD)v3 << SBYTE3(bitCnt));
  HIDWORD(bitCnt) = 32 - bitCnt;
  pIO->bitBuff = v3;
  *(_QWORD *)((char *)&v3 + 4) = bitCnt >> 3;
  *(_QWORD *)&v3 = (_QWORD)v3 << (32 - (unsigned __int8)bitCnt);
  *(_QWORD *)((char *)&v3 + 12) = *(_QWORD *)&v3 >> 24;
  *(_DWORD *)(v7 + 24) = &byteBufCur[(*(_QWORD *)&v3 >> 8 >> 32) & 2];
  v8 = bitCnt & 0xF;
  *(_WORD *)byteBufCur = (DWORD1(v3) >> 8) & 0xFF00 | BYTE3(v3);
  *(_DWORD *)(v7 + 28) = byteCount + HIDWORD(v8);
  *(_QWORD *)(v7 + 8) = v8;
}


// ========================================================================
// ?WriteBits32@@YAXPIAUhdpBitIO_t@@II@Z
// EA  : 0x828ECAD0
// RVA : 0x008ECAD0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitiowrite.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall WriteBits32(hdpBitIO_t *pIO, unsigned int uiBits, __int64 cBits)
{
  __int128 v3; // r7 OVERLAPPED
  __int128 v4; // r11
  __int64 v5; // r31
  unsigned __int64 bitCnt; // r11
  unsigned __int8 *byteBufCur; // r9
  unsigned int byteCount; // r8
  __int128 v9; // r7 OVERLAPPED
  int v10; // r3
  unsigned __int64 v11; // r11

  if ( HIDWORD(cBits) > 0x10 )
  {
    DWORD1(v3) = HIDWORD(cBits) - 16;
    *((_QWORD *)&v4 + 1) = pIO->bitCnt;
    DWORD2(v4) = uiBits;
    DWORD1(v4) = pIO->byteBufCur;
    LODWORD(v4) = v4 + 16;
    HIDWORD(v4) = pIO->byteCount;
    *(_QWORD *)((char *)&v4 + 4) >>= SBYTE7(v3);
    DWORD2(v4) = 32 - v4;
    *((_QWORD *)&v3 + 1) = (unsigned __int64)v4 >> 3;
    pIO->bitBuff = *(_QWORD *)((char *)&v3 + 4);
    *(_QWORD *)((char *)&v3 + 4) <<= 32 - (unsigned __int8)v4;
    DWORD2(v4) = ((unsigned __int64)v4 >> 3) & 2;
    v5 = *(_QWORD *)((char *)&v3 + 4) >> 24;
    cBits = *(_QWORD *)((char *)&v3 + 4) >> 8;
    LODWORD(v3) = DWORD2(v4) + DWORD1(v4);
    pIO->byteBufCur = (unsigned __int8 *)(DWORD2(v4) + DWORD1(v4));
    DWORD2(v4) += HIDWORD(v4);
    HIDWORD(v4) = v4 & 0xF;
    pIO->byteCount = DWORD2(v4);
    *(_WORD *)DWORD1(v4) = cBits & 0xFF00 | (unsigned __int8)v5;
    pIO->bitCnt = *(_QWORD *)((char *)&v3 - 4);
  }
  *(__int64 *)((char *)&cBits - 4) = pIO->bitBuff;
  bitCnt = pIO->bitCnt;
  byteBufCur = pIO->byteBufCur;
  byteCount = pIO->byteCount;
  DWORD2(v9) = ~(-1 << SBYTE3(cBits));
  LODWORD(bitCnt) = bitCnt + HIDWORD(bitCnt);
  LODWORD(v9) = DWORD2(v9) & ((_QWORD)v9 << SBYTE3(bitCnt) >> 32) | ((_QWORD)v9 << SBYTE3(bitCnt));
  HIDWORD(bitCnt) = 32 - bitCnt;
  pIO->bitBuff = v9;
  *(_QWORD *)((char *)&v9 + 4) = bitCnt >> 3;
  *(_QWORD *)&v9 = (_QWORD)v9 << (32 - (unsigned __int8)bitCnt);
  *(_QWORD *)((char *)&v9 + 12) = *(_QWORD *)&v9 >> 24;
  *(_DWORD *)(v10 + 24) = &byteBufCur[(*(_QWORD *)&v9 >> 8 >> 32) & 2];
  v11 = bitCnt & 0xF;
  *(_WORD *)byteBufCur = (DWORD1(v9) >> 8) & 0xFF00 | BYTE3(v9);
  *(_DWORD *)(v10 + 28) = byteCount + HIDWORD(v11);
  *(_QWORD *)(v10 + 8) = v11;
}


// ========================================================================
// ?WriteUpToByte@@YAXPIAUhdpBitIO_t@@@Z
// EA  : 0x828ECBC8
// RVA : 0x008ECBC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitiowrite.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall WriteUpToByte(hdpBitIO_t *pIO)
{
  unsigned __int64 bitCnt; // r11
  __int128 v2; // r7 OVERLAPPED
  unsigned __int8 *byteBufCur; // r9
  unsigned int byteCount; // r8
  int v5; // r3

  bitCnt = pIO->bitCnt;
  *((_QWORD *)&v2 + 1) = pIO->bitBuff;
  DWORD2(v2) = bitCnt;
  byteBufCur = pIO->byteBufCur;
  byteCount = pIO->byteCount;
  HIDWORD(bitCnt) = -(int)bitCnt & 7;
  LODWORD(bitCnt) = HIDWORD(bitCnt) + bitCnt;
  *(_QWORD *)((_QWORD)v2 << SBYTE3(bitCnt) >> 32) = (_QWORD)v2 << SBYTE3(bitCnt);
  *(_QWORD *)((char *)&v2 + 4) = (_QWORD)v2 << SBYTE3(bitCnt) << (32 - (unsigned __int8)bitCnt);
  HIDWORD(bitCnt) = 32 - bitCnt;
  *(_QWORD *)((char *)&v2 + 12) = *(_QWORD *)((char *)&v2 + 4) >> 8;
  HIDWORD(bitCnt) = (bitCnt >> 3) & 2;
  *(_DWORD *)(v5 + 24) = &byteBufCur[HIDWORD(bitCnt)];
  HIDWORD(v2) = bitCnt & 0xF;
  *(_WORD *)byteBufCur = BYTE8(v2);
  *(_DWORD *)(v5 + 28) = HIDWORD(bitCnt) + byteCount;
  *(_QWORD *)(v5 + 8) = *(_QWORD *)((char *)&v2 + 12);
}


// ========================================================================
// ?GetWritePos@@YAIPIAUhdpBitIO_t@@@Z
// EA  : 0x828ECC30
// RVA : 0x008ECC30
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitiowrite.cpp
// ========================================================================

unsigned int __fastcall GetWritePos(hdpBitIO_t *pIO)
{
  return (pIO->bitCnt >> 3) + pIO->streamOffset + pIO->byteCount;
}


// ========================================================================
// ?StreamWriteAttach@@YA?AW4hdpError_t@@PIAUhdpBitIO_t@@PIAUhdpStream_t@@@Z
// EA  : 0x828ECC50
// RVA : 0x008ECC50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitiowrite.cpp
// ========================================================================

hdpError_t __fastcall StreamWriteAttach(hdpBitIO_t *pIO, hdpStream_t *stream)
{
  unsigned __int8 *v4; // r3
  unsigned __int8 *byteBufStart; // r8
  unsigned __int64 v6; // r11

  stream->GetPos(a1: stream, a2: &pIO->streamOffset);
  pIO->byteBufStart = (unsigned __int8 *)stream->WritePtr(a1: stream);
  v4 = (unsigned __int8 *)stream->EndPtr(a1: stream);
  byteBufStart = pIO->byteBufStart;
  LODWORD(v6) = 0;
  pIO->byteBufEnd = v4;
  pIO->stream = stream;
  pIO->byteCount = 0;
  pIO->bitBuff = v6;
  pIO->byteBufCur = byteBufStart;
  pIO->bitCnt = v6;
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?StreamWriteDetach@@YA?AW4hdpError_t@@PIAUhdpBitIO_t@@@Z
// EA  : 0x828ECCE0
// RVA : 0x008ECCE0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitiowrite.cpp
// ========================================================================

hdpError_t __fastcall StreamWriteDetach(hdpBitIO_t *pIO)
{
  unsigned __int64 v2; // r9
  void (__fastcall *v3)(_DWORD); // r7

  v2 = pIO->bitCnt >> 3;
  HIDWORD(v2) = pIO->stream;
  v3 = *(void (__fastcall **)(_DWORD))(HIDWORD(v2) + 40);
  pIO->streamOffset += v2 + pIO->byteCount;
  v3(a1: HIDWORD(v2));
  pIO->stream = nullptr;
  return HDP_ERROR_NONE;
}

