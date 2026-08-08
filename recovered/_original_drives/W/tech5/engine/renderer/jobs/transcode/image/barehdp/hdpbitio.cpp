
// ========================================================================
// ?ReadWS_Memory@@YA?AW4hdpError_t@@PAUhdpStream_t@@PAXI@Z
// EA  : 0x828EC6B8
// RVA : 0x008EC6B8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

int __fastcall ReadWS_Memory(hdpStream_t *stream, void *pv, size_t cb)
{
  unsigned int cbCur; // r11

  cbCur = stream->state.buf.cbCur;
  if ( cbCur + cb > stream->state.buf.cbBuf )
    return -3;
  memcpy(Dst: pv, Src: (char *)stream->state.file.pFile + cbCur, Size: cb);
  stream->state.buf.cbCur += cb;
  return 0;
}


// ========================================================================
// ?WriteWS_Memory@@YA?AW4hdpError_t@@PAUhdpStream_t@@PBXI@Z
// EA  : 0x828EC730
// RVA : 0x008EC730
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

int __fastcall WriteWS_Memory(hdpStream_t *stream, const void *pv, size_t cb)
{
  unsigned int cbCur; // r11

  cbCur = stream->state.buf.cbCur;
  if ( cbCur + cb > stream->state.buf.cbBuf )
    return -3;
  memcpy(Dst: (char *)stream->state.file.pFile + cbCur, Src: pv, Size: cb);
  stream->state.buf.cbCur += cb;
  return 0;
}


// ========================================================================
// ?WritePtrWS_Memory@@YAPAXPAUhdpStream_t@@@Z
// EA  : 0x828EC7A0
// RVA : 0x008EC7A0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

char *__fastcall WritePtrWS_Memory(hdpStream_t *stream)
{
  return (char *)stream->state.file.pFile + stream->state.buf.cbCur;
}


// ========================================================================
// ?EndPtrWS_Memory@@YAPAXPAUhdpStream_t@@@Z
// EA  : 0x828EC7B0
// RVA : 0x008EC7B0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

char *__fastcall EndPtrWS_Memory(hdpStream_t *stream)
{
  return (char *)stream->state.file.pFile + stream->state.buf.cbBuf;
}


// ========================================================================
// ?SetPosWS_Memory@@YA?AW4hdpError_t@@PAUhdpStream_t@@I@Z
// EA  : 0x828EC7C0
// RVA : 0x008EC7C0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

hdpError_t __fastcall SetPosWS_Memory(hdpStream_t *stream, unsigned int offPos)
{
  stream->state.buf.cbCur = offPos;
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?GetPosWS_Memory@@YA?AW4hdpError_t@@PAUhdpStream_t@@PAI@Z
// EA  : 0x828EC7D0
// RVA : 0x008EC7D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

hdpError_t __fastcall GetPosWS_Memory(hdpStream_t *stream, unsigned int *poffPos)
{
  *poffPos = stream->state.buf.cbCur;
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?CreateWS_Memory@@YA?AW4hdpError_t@@PAUhdpStream_t@@PAXI@Z
// EA  : 0x828EC7E0
// RVA : 0x008EC7E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

hdpError_t __fastcall CreateWS_Memory(hdpStream_t *stream, _iobuf *pv, unsigned int cb)
{
  stream->state.file.pFile = pv;
  stream->state.buf.cbBuf = cb;
  stream->Close = (hdpError_t (__fastcall *)(hdpStream_t *))idLobbyBackend360::StartArbitration;
  stream->GetPos = GetPosWS_Memory;
  stream->state.buf.cbCur = 0;
  stream->Read = (hdpError_t (__fastcall *)(hdpStream_t *, void *, unsigned int))ReadWS_Memory;
  stream->Write = (hdpError_t (__fastcall *)(hdpStream_t *, const void *, unsigned int))WriteWS_Memory;
  stream->ReadPtr = (void *(__fastcall *)(hdpStream_t *))WritePtrWS_Memory;
  stream->WritePtr = (void *(__fastcall *)(hdpStream_t *))WritePtrWS_Memory;
  stream->EndPtr = (void *(__fastcall *)(hdpStream_t *))EndPtrWS_Memory;
  stream->SetPos = SetPosWS_Memory;
  return HDP_ERROR_NONE;
}


// ========================================================================
// ?FillBitBuffer@@YAXPIAUhdpBitIO_t@@AA_K1@Z
// EA  : 0x828EC868
// RVA : 0x008EC868
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall FillBitBuffer(hdpBitIO_t *pIO, unsigned __int64 *bitBuff, __int64 bitCnt)
{
  unsigned __int8 *byteBufCur; // r11
  int v4; // r10
  unsigned int byteCount; // r9
  int v6; // r7
  __int128 v7; // r7 OVERLAPPED
  int v8; // r8
  int v9; // r8
  __int64 v10; // r11

  byteBufCur = pIO->byteBufCur;
  v4 = pIO->byteBufEnd - byteBufCur;
  byteCount = pIO->byteCount;
  v6 = byteBufCur[(v4 - 1) >> 31] | (*((_DWORD *)bitBuff + 1) << 8);
  LODWORD(bitCnt) = byteBufCur[((v4 - 2) >> 31) ^ 1];
  LODWORD(bitCnt) = (v6 << 8) | (*(unsigned __int64 *)((char *)&bitCnt - 4) >> 24);
  *(_QWORD *)((char *)&v7 + 4) = bitCnt << 8;
  LODWORD(v7) = DWORD2(v7) | byteBufCur[((v4 - 3) >> 31) ^ 2];
  DWORD2(v7) = v4 - 6;
  *((_QWORD *)&v7 + 1) = (_QWORD)v7 << 8;
  v8 = v7 | byteBufCur[((v4 - 4) >> 31) ^ 3];
  LODWORD(v7) = (SDWORD2(v7) >> 31) ^ 5;
  *(_QWORD *)((char *)&v7 - 4) <<= 8;
  v9 = v8 | byteBufCur[((v4 - 5) >> 31) ^ 4];
  LODWORD(v7) = byteBufCur[v7];
  LODWORD(v7) = (v9 << 8) | (*(_QWORD *)((char *)&v7 - 4) >> 24);
  DWORD2(v7) = &byteBufCur[~(unsigned __int8)(v4 >> 31) & 6];
  *bitBuff = v7;
  v10 = *(_QWORD *)DWORD1(v7);
  LODWORD(v10) = *(_DWORD *)(DWORD1(v7) + 4) + 48;
  pIO->byteCount = byteCount + 6;
  pIO->byteBufCur = (unsigned __int8 *)DWORD2(v7);
  *(_QWORD *)DWORD1(v7) = v10;
}

