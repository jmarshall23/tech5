
// ========================================================================
// ?StreamReadAttach@@YA?AW4hdpError_t@@PIAUhdpBitIO_t@@PIAUhdpStream_t@@@Z
// EA  : 0x828EC948
// RVA : 0x008EC948
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitioread.cpp
// ========================================================================

hdpError_t __fastcall StreamReadAttach(hdpBitIO_t *pIO, hdpStream_t *stream)
{
  unsigned __int8 *v4; // r3
  unsigned __int8 *byteBufStart; // r8
  unsigned __int64 v6; // r11

  stream->GetPos(a1: stream, a2: &pIO->streamOffset);
  pIO->byteBufStart = (unsigned __int8 *)stream->ReadPtr(a1: stream);
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
// ?StreamReadDetach@@YA?AW4hdpError_t@@PIAUhdpBitIO_t@@@Z
// EA  : 0x828EC9D8
// RVA : 0x008EC9D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitioread.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
hdpError_t __fastcall StreamReadDetach(hdpBitIO_t *pIO, int a2, unsigned __int64 a3)
{
  unsigned __int64 bitCnt; // r10
  unsigned int streamOffset; // r11
  hdpStream_t *stream; // r7
  hdpError_t (__fastcall *SetPos)(hdpStream_t *, unsigned int); // ctr

  bitCnt = pIO->bitCnt;
  HIDWORD(bitCnt) = pIO->byteCount;
  streamOffset = pIO->streamOffset;
  stream = pIO->stream;
  LODWORD(a3) = bitCnt - (bitCnt & 7);
  *(unsigned __int64 *)((char *)&a3 + 4) = a3 >> 3;
  pIO->bitCnt = a3;
  SetPos = stream->SetPos;
  pIO->streamOffset = HIDWORD(bitCnt) - HIDWORD(a3) + streamOffset;
  ((void (__fastcall *)(hdpStream_t *))SetPos)(a1: stream);
  pIO->stream = nullptr;
  return HDP_ERROR_NONE;
}

