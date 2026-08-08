
// ========================================================================
// unzlocal_getShort
// EA  : 0x82F1CE98
// RVA : 0x00F1CE98
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzlocal_getShort(_iobuf *fin, unsigned int *pX)
{
  int result; // r3
  bool v4; // zf
  _BYTE v5[16]; // [sp+50h] [-20h] BYREF

  v4 = fread(buffer: v5, elementSize: 2u, count: 1u, stream: fin) == 1;
  result = 0;
  if ( v4 )
    *pX = (unsigned __int16)((v5[1] << 8) | v5[0]);
  else
    *pX = 0;
  return result;
}


// ========================================================================
// unzlocal_getLong
// EA  : 0x82F1CF10
// RVA : 0x00F1CF10
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzlocal_getLong(_iobuf *fin, unsigned int *pX)
{
  int result; // r3
  bool v4; // zf
  _BYTE v5[16]; // [sp+50h] [-20h] BYREF

  v4 = fread(buffer: v5, elementSize: 4u, count: 1u, stream: fin) == 1;
  result = 0;
  if ( v4 )
    *pX = ((((unsigned __int16)((v5[3] << 8) | v5[2]) << 8) | v5[1]) << 8) | v5[0];
  else
    *pX = 0;
  return result;
}


// ========================================================================
// unzlocal_SearchCentralDir
// EA  : 0x82F1CF98
// RVA : 0x00F1CF98
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

unsigned int __fastcall unzlocal_SearchCentralDir(_iobuf *fin)
{
  unsigned int v2; // r27
  unsigned int v3; // r24
  unsigned int v5; // r3
  unsigned int v6; // r26
  void *v7; // r30
  unsigned int v8; // r28
  unsigned int v9; // r11
  bool v10; // zf
  unsigned int v11; // r29
  unsigned int v12; // r31
  int v13; // r11

  v2 = 0xFFFF;
  v3 = 0;
  if ( fseek(stream: fin, offset: 0, whence: 2) != 0 )
    return 0;
  v5 = ftell(stream: fin);
  v6 = v5;
  if ( v5 < 0xFFFF )
    v2 = v5;
  v7 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\filesystem\\Unzip.cpp(212) : TAG_FILE",
         size: 0x404u,
         tag: TAG_FILE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v7 == nullptr )
    return 0;
  v8 = 4;
  while ( v8 < v2 )
  {
    v9 = v8 + 1024;
    v10 = v8 + 1024 > v2;
    v8 = v2;
    if ( !v10 )
      v8 = v9;
    v11 = v6 - v8;
    v12 = 1028;
    if ( v8 <= 0x404 )
      v12 = v8;
    if ( fseek(stream: fin, offset: v6 - v8, whence: 0) != 0
      || fread(buffer: v7, elementSize: v12, count: 1u, stream: fin) != 1 )
    {
      break;
    }
    v13 = v12 - 3;
    if ( (int)(v12 - 3) > 0 )
    {
      while ( *((_BYTE *)v7 + --v13) != 80
           || *((_BYTE *)v7 + v13 + 1) != 75
           || *((_BYTE *)v7 + v13 + 2) != 5
           || *((_BYTE *)v7 + v13 + 3) != 6 )
      {
        if ( v13 <= 0 )
          goto LABEL_21;
      }
      v3 = v13 + v11;
      if ( v13 + v11 != 0 )
        break;
    }
LABEL_21:
    ;
  }
  idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
  return v3;
}


// ========================================================================
// ?unzReOpen@@YAPAXPBDPAX_N@Z
// EA  : 0x82F1D110
// RVA : 0x00F1D110
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

_iobuf *__fastcall unzReOpen(const char *path, void *file, bool retryOnOpen)
{
  _iobuf *i; // r31
  _iobuf **v6; // r30
  _iobuf *result; // r3

  if ( retryOnOpen )
  {
    for ( i = fopen(file: path, mode: "rb"); i == nullptr; i = fopen(file: path, mode: "rb") )
      mgthread_sleep(ms: 10);
    goto LABEL_4;
  }
  result = fopen(file: path, mode: "rb");
  i = result;
  if ( result != nullptr )
  {
LABEL_4:
    v6 = (_iobuf **)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\filesystem\\Unzip.cpp(271) : TAG_FILE",
                      size: 0x80u,
                      tag: TAG_FILE,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
    memcpy(Dst: v6, Src: file, Size: 0x80u);
    *v6 = i;
    v6[31] = nullptr;
    return (_iobuf *)v6;
  }
  return result;
}


// ========================================================================
// ?unzOpen@@YAPAXPBD@Z
// EA  : 0x82F1D1D8
// RVA : 0x00F1D1D8
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

void *__fastcall unzOpen(const char *path)
{
  int v1; // r31
  _iobuf *v2; // r3
  _iobuf *v3; // r30
  int v4; // r3
  unsigned int v5; // r29
  void *v7; // r31
  unsigned int v8; // [sp+50h] [-B0h] BYREF
  unsigned int v9; // [sp+54h] [-ACh] BYREF
  unsigned int v10; // [sp+58h] [-A8h] BYREF
  unsigned int v11[40]; // [sp+60h] [-A0h] BYREF

  v1 = 0;
  v2 = fopen(file: path, mode: "rb");
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  v4 = unzlocal_SearchCentralDir(fin: v2);
  v5 = v4;
  if ( v4 == 0 )
    v1 = -1;
  if ( fseek(stream: v3, offset: v4, whence: 0) != 0 )
    v1 = -1;
  if ( unzlocal_getLong(fin: v3, pX: &v8) != 0 )
    v1 = -1;
  if ( unzlocal_getShort(fin: v3, pX: &v8) != 0 )
    v1 = -1;
  if ( unzlocal_getShort(fin: v3, pX: &v9) != 0 )
    v1 = -1;
  if ( unzlocal_getShort(fin: v3, pX: &v11[1]) != 0 )
    v1 = -1;
  if ( unzlocal_getShort(fin: v3, pX: &v10) != 0 )
    v1 = -1;
  if ( v10 != v11[1] || v9 != 0 || v8 != 0 )
    v1 = -103;
  if ( unzlocal_getLong(fin: v3, pX: &v11[8]) != 0 )
    v1 = -1;
  if ( unzlocal_getLong(fin: v3, pX: &v11[9]) != 0 )
    v1 = -1;
  if ( unzlocal_getShort(fin: v3, pX: &v11[2]) != 0 )
    v1 = -1;
  if ( v5 < v11[8] + v11[9] || v1 != 0 )
  {
    fclose(stream: v3);
    return nullptr;
  }
  v11[0] = (unsigned int)v3;
  v11[7] = v5;
  v11[3] = v5 - v11[8] - v11[9];
  v11[31] = 0;
  v7 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\filesystem\\Unzip.cpp(372) : TAG_FILE",
         size: 0x80u,
         tag: TAG_FILE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  memcpy(Dst: v7, Src: v11, Size: 0x80u);
  return v7;
}


// ========================================================================
// ?unzGetGlobalInfo@@YAHPAXPAUunz_global_info_s@@@Z
// EA  : 0x82F1D3B0
// RVA : 0x00F1D3B0
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzGetGlobalInfo(char *file, unz_global_info_s *pglobal_info)
{
  if ( file == nullptr )
    return -102;
  *pglobal_info = *(unz_global_info_s *)(file + 4);
  return 0;
}


// ========================================================================
// unzlocal_GetCurrentFileInfoInternal
// EA  : 0x82F1D3E0
// RVA : 0x00F1D3E0
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzlocal_GetCurrentFileInfoInternal(
        _iobuf **file,
        unz_file_info_s *pfile_info,
        unz_file_info_internal_s *pfile_info_internal,
        char *szFileName,
        unsigned int fileNameBufferSize,
        void *extraField,
        unsigned int extraFieldBufferSize,
        char *szComment,
        unsigned int commentBufferSize,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int a28)
{
  int v36; // r28
  _iobuf *v38; // r3
  unsigned int v39; // r30
  unsigned int v40; // r31
  unsigned int v41; // r29
  unsigned int v42; // r30
  unsigned int v43; // r11
  int v44; // r4
  unsigned int v45; // r31
  unsigned int v46; // r30
  unsigned int v47[4]; // [sp+50h] [-D0h] BYREF
  unsigned int v48[48]; // [sp+60h] [-C0h] BYREF

  v36 = 0;
  if ( file == nullptr )
    return -102;
  if ( fseek(stream: *file, offset: (int)file[3] + (_DWORD)file[5], whence: 0) != 0 )
  {
    v36 = -1;
  }
  else if ( unzlocal_getLong(fin: *file, pX: v47) != 0 )
  {
    v36 = -1;
  }
  else if ( v47[0] != 33639248 )
  {
    v36 = -103;
  }
  if ( unzlocal_getShort(fin: *file, pX: v48) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[1]) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[2]) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[3]) != 0 )
    v36 = -1;
  if ( unzlocal_getLong(fin: *file, pX: &v48[4]) != 0 )
    v36 = -1;
  v38 = *file;
  v48[17] = HIWORD(v48[4]) & 0x1F;
  v48[16] = LOWORD(v48[4]) >> 11;
  v48[15] = (v48[4] >> 5) & 0x3F;
  v48[14] = (2 * v48[4]) & 0x3E;
  v48[18] = ((v48[4] >> 21) & 0xF) - 1;
  v48[19] = (v48[4] >> 25) + 1980;
  if ( unzlocal_getLong(fin: v38, pX: &v48[5]) != 0 )
    v36 = -1;
  if ( unzlocal_getLong(fin: *file, pX: &v48[6]) != 0 )
    v36 = -1;
  if ( unzlocal_getLong(fin: *file, pX: &v48[7]) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[8]) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[9]) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[10]) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[11]) != 0 )
    v36 = -1;
  if ( unzlocal_getShort(fin: *file, pX: &v48[12]) != 0 )
    v36 = -1;
  if ( unzlocal_getLong(fin: *file, pX: &v48[13]) != 0 )
    v36 = -1;
  if ( unzlocal_getLong(fin: *file, pX: v47) != 0 )
    v36 = -1;
  v39 = v48[8];
  v40 = v48[8];
  if ( v36 != 0 )
    goto LABEL_61;
  if ( szFileName != nullptr )
  {
    if ( v48[8] >= fileNameBufferSize )
      v40 = fileNameBufferSize;
    else
      szFileName[v48[8]] = 0;
    if ( v39 != 0
      && fileNameBufferSize != 0
      && fread(buffer: szFileName, elementSize: v40, count: 1u, stream: *file) != 1 )
    {
      v36 = -1;
    }
    v40 = v39 - v40;
    if ( v36 != 0 )
      goto LABEL_61;
  }
  if ( extraField == nullptr )
  {
LABEL_61:
    v43 = v48[9];
  }
  else
  {
    v41 = v48[9];
    v42 = v48[9];
    if ( v48[9] >= extraFieldBufferSize )
      v42 = extraFieldBufferSize;
    if ( v40 != 0 )
    {
      if ( fseek(stream: *file, offset: v40, whence: 1) != 0 )
        v36 = -1;
      else
        v40 = 0;
    }
    if ( v41 != 0
      && extraFieldBufferSize != 0
      && fread(buffer: extraField, elementSize: v42, count: 1u, stream: *file) != 1 )
    {
      v36 = -1;
    }
    v43 = v41 - v42;
  }
  v44 = v43 + v40;
  if ( v36 == 0 )
  {
    if ( szComment == nullptr )
      goto LABEL_75;
    v45 = v48[10];
    if ( v48[10] >= a28 )
    {
      v46 = a28;
    }
    else
    {
      v46 = v48[10];
      szComment[v48[10]] = 0;
    }
    if ( v44 != 0 && fseek(stream: *file, offset: v44, whence: 1) != 0 )
      v36 = -1;
    if ( v45 != 0 && a28 != 0 && fread(buffer: szComment, elementSize: v46, count: 1u, stream: *file) != 1 )
      return -1;
    if ( v36 == 0 )
    {
LABEL_75:
      if ( pfile_info != nullptr )
        memcpy(Dst: pfile_info, Src: v48, Size: sizeof(unz_file_info_s));
      if ( pfile_info_internal != nullptr )
        pfile_info_internal->offset_curfile = v47[0];
    }
  }
  return v36;
}


// ========================================================================
// ?unzGetCurrentFileInfo@@YAHPAXPAUunz_file_info_s@@PADK0K2K@Z
// EA  : 0x82F1D7E0
// RVA : 0x00F1D7E0
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzGetCurrentFileInfo(
        _iobuf **file,
        unz_file_info_s *pfile_info,
        char *szFileName,
        unsigned int fileNameBufferSize,
        void *extraField,
        unsigned int extraFieldBufferSize,
        char *szComment,
        unsigned int commentBufferSize)
{
  unsigned int v9; // [sp+8h] [-58h]
  int v10; // [sp+Ch] [-54h]
  int v11; // [sp+10h] [-50h]
  int v12; // [sp+14h] [-4Ch]
  int v13; // [sp+18h] [-48h]
  int v14; // [sp+1Ch] [-44h]
  int v15; // [sp+20h] [-40h]
  int v16; // [sp+24h] [-3Ch]
  int v17; // [sp+28h] [-38h]
  int v18; // [sp+2Ch] [-34h]
  int v19; // [sp+30h] [-30h]
  int v20; // [sp+34h] [-2Ch]
  int v21; // [sp+38h] [-28h]
  int v22; // [sp+3Ch] [-24h]
  int v23; // [sp+40h] [-20h]
  int v24; // [sp+44h] [-1Ch]
  int v25; // [sp+48h] [-18h]
  int v26; // [sp+4Ch] [-14h]
  int v27; // [sp+50h] [-10h]

  return unzlocal_GetCurrentFileInfoInternal(
           file,
           pfile_info,
           pfile_info_internal: nullptr,
           szFileName,
           fileNameBufferSize,
           extraField,
           extraFieldBufferSize,
           szComment,
           commentBufferSize: v9,
           a10: v10,
           a11: v11,
           a12: v12,
           a13: v13,
           a14: v14,
           a15: v15,
           a16: v16,
           a17: v17,
           a18: v18,
           a19: v19,
           a20: v20,
           a21: v21,
           a22: v22,
           a23: v23,
           a24: v24,
           a25: v25,
           a26: v26,
           a27: v27,
           a28: commentBufferSize);
}


// ========================================================================
// ?unzGoToFirstFile@@YAHPAX@Z
// EA  : 0x82F1D820
// RVA : 0x00F1D820
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

unsigned int __fastcall unzGoToFirstFile(char *file)
{
  unsigned int result; // r3
  int v3; // r5
  unsigned int v4; // [sp+8h] [-68h]
  int v5; // [sp+Ch] [-64h]
  int v6; // [sp+10h] [-60h]
  int v7; // [sp+14h] [-5Ch]
  int v8; // [sp+18h] [-58h]
  int v9; // [sp+1Ch] [-54h]
  int v10; // [sp+20h] [-50h]
  int v11; // [sp+24h] [-4Ch]
  int v12; // [sp+28h] [-48h]
  int v13; // [sp+2Ch] [-44h]
  int v14; // [sp+30h] [-40h]
  int v15; // [sp+34h] [-3Ch]
  int v16; // [sp+38h] [-38h]
  int v17; // [sp+3Ch] [-34h]
  int v18; // [sp+40h] [-30h]
  int v19; // [sp+44h] [-2Ch]
  int v20; // [sp+48h] [-28h]
  int v21; // [sp+4Ch] [-24h]
  int v22; // [sp+50h] [-20h]

  if ( file == nullptr )
    return -102;
  v3 = *((_DWORD *)file + 9);
  *((_DWORD *)file + 4) = 0;
  *((_DWORD *)file + 5) = v3;
  result = unzlocal_GetCurrentFileInfoInternal(
             (_iobuf **)file,
             pfile_info: (unz_file_info_s *)(file + 40),
             pfile_info_internal: (unz_file_info_internal_s *)file + 30,
             szFileName: nullptr,
             fileNameBufferSize: 0,
             extraField: nullptr,
             extraFieldBufferSize: 0,
             szComment: nullptr,
             commentBufferSize: v4,
             a10: v5,
             a11: v6,
             a12: v7,
             a13: v8,
             a14: v9,
             a15: v10,
             a16: v11,
             a17: v12,
             a18: v13,
             a19: v14,
             a20: v15,
             a21: v16,
             a22: v17,
             a23: v18,
             a24: v19,
             a25: v20,
             a26: v21,
             a27: v22,
             a28: 0);
  *((_DWORD *)file + 6) = (_cntlzw(result) & 0x20) != 0;
  return result;
}


// ========================================================================
// ?unzGoToNextFile@@YAHPAX@Z
// EA  : 0x82F1D8B0
// RVA : 0x00F1D8B0
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

unsigned int __fastcall unzGoToNextFile(char *file)
{
  unsigned int result; // r3
  int v3; // r5
  int v4; // r7
  int v5; // r11
  int v6; // r6
  unsigned int v7; // [sp+8h] [-68h]
  int v8; // [sp+Ch] [-64h]
  int v9; // [sp+10h] [-60h]
  int v10; // [sp+14h] [-5Ch]
  int v11; // [sp+18h] [-58h]
  int v12; // [sp+1Ch] [-54h]
  int v13; // [sp+20h] [-50h]
  int v14; // [sp+24h] [-4Ch]
  int v15; // [sp+28h] [-48h]
  int v16; // [sp+2Ch] [-44h]
  int v17; // [sp+30h] [-40h]
  int v18; // [sp+34h] [-3Ch]
  int v19; // [sp+38h] [-38h]
  int v20; // [sp+3Ch] [-34h]
  int v21; // [sp+40h] [-30h]
  int v22; // [sp+44h] [-2Ch]
  int v23; // [sp+48h] [-28h]
  int v24; // [sp+4Ch] [-24h]
  int v25; // [sp+50h] [-20h]

  if ( file == nullptr )
    return -102;
  if ( *((_DWORD *)file + 6) == 0 )
    return -100;
  v3 = *((_DWORD *)file + 4) + 1;
  if ( v3 == *((_DWORD *)file + 1) )
    return -100;
  v4 = *((_DWORD *)file + 18);
  v5 = *((_DWORD *)file + 20) + *((_DWORD *)file + 19);
  v6 = *((_DWORD *)file + 5);
  *((_DWORD *)file + 4) = v3;
  *((_DWORD *)file + 5) = v5 + v4 + v6 + 46;
  result = unzlocal_GetCurrentFileInfoInternal(
             (_iobuf **)file,
             pfile_info: (unz_file_info_s *)(file + 40),
             pfile_info_internal: (unz_file_info_internal_s *)file + 30,
             szFileName: nullptr,
             fileNameBufferSize: 0,
             extraField: nullptr,
             extraFieldBufferSize: 0,
             szComment: nullptr,
             commentBufferSize: v7,
             a10: v8,
             a11: v9,
             a12: v10,
             a13: v11,
             a14: v12,
             a15: v13,
             a16: v14,
             a17: v15,
             a18: v16,
             a19: v17,
             a20: v18,
             a21: v19,
             a22: v20,
             a23: v21,
             a24: v22,
             a25: v23,
             a26: v24,
             a27: v25,
             a28: 0);
  *((_DWORD *)file + 6) = (_cntlzw(result) & 0x20) != 0;
  return result;
}


// ========================================================================
// ?unzGetCurrentFileInfoPosition@@YAHPAXPAK@Z
// EA  : 0x82F1D990
// RVA : 0x00F1D990
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzGetCurrentFileInfoPosition(_DWORD *file, unsigned int *pos)
{
  if ( file == nullptr )
    return -102;
  *pos = file[5];
  return 0;
}


// ========================================================================
// ?unzSetCurrentFileInfoPosition@@YAHPAXK@Z
// EA  : 0x82F1D9B0
// RVA : 0x00F1D9B0
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzSetCurrentFileInfoPosition(char *file, unsigned int pos)
{
  unsigned int v3; // [sp+8h] [-68h]
  int v4; // [sp+Ch] [-64h]
  int v5; // [sp+10h] [-60h]
  int v6; // [sp+14h] [-5Ch]
  int v7; // [sp+18h] [-58h]
  int v8; // [sp+1Ch] [-54h]
  int v9; // [sp+20h] [-50h]
  int v10; // [sp+24h] [-4Ch]
  int v11; // [sp+28h] [-48h]
  int v12; // [sp+2Ch] [-44h]
  int v13; // [sp+30h] [-40h]
  int v14; // [sp+34h] [-3Ch]
  int v15; // [sp+38h] [-38h]
  int v16; // [sp+3Ch] [-34h]
  int v17; // [sp+40h] [-30h]
  int v18; // [sp+44h] [-2Ch]
  int v19; // [sp+48h] [-28h]
  int v20; // [sp+4Ch] [-24h]
  int v21; // [sp+50h] [-20h]

  if ( file == nullptr )
    return -102;
  *((_DWORD *)file + 5) = pos;
  *((_DWORD *)file + 6) = (_cntlzw(
                             unzlocal_GetCurrentFileInfoInternal(
                               (_iobuf **)file,
                               pfile_info: (unz_file_info_s *)(file + 40),
                               pfile_info_internal: (unz_file_info_internal_s *)file + 30,
                               szFileName: nullptr,
                               fileNameBufferSize: 0,
                               extraField: nullptr,
                               extraFieldBufferSize: 0,
                               szComment: nullptr,
                               commentBufferSize: v3,
                               a10: v4,
                               a11: v5,
                               a12: v6,
                               a13: v7,
                               a14: v8,
                               a15: v9,
                               a16: v10,
                               a17: v11,
                               a18: v12,
                               a19: v13,
                               a20: v14,
                               a21: v15,
                               a22: v16,
                               a23: v17,
                               a24: v18,
                               a25: v19,
                               a26: v20,
                               a27: v21,
                               a28: 0))
                         & 0x20) != 0;
  return 0;
}


// ========================================================================
// unzlocal_CheckCurrentFileCoherencyHeader
// EA  : 0x82F1DA38
// RVA : 0x00F1DA38
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzlocal_CheckCurrentFileCoherencyHeader(
        unz_s *s,
        unsigned int *piSizeVar,
        unsigned int *poffset_local_extrafield,
        unsigned int *psize_local_extrafield)
{
  int v5; // r31
  unsigned int compression_method; // r11
  int Long; // r3
  char v12; // r29
  int Short; // r3
  unsigned int v14; // r29
  unsigned int v15; // r11
  unsigned int v16; // [sp+50h] [-40h] BYREF
  unsigned int v17[15]; // [sp+54h] [-3Ch] BYREF

  v5 = 0;
  *piSizeVar = 0;
  *poffset_local_extrafield = 0;
  *psize_local_extrafield = 0;
  if ( fseek(stream: s->file, offset: s->byte_before_the_zipfile + s->cur_file_info_internal.offset_curfile, whence: 0) != 0 )
    return -1;
  if ( unzlocal_getLong(fin: s->file, pX: &v16) != 0 )
  {
    v5 = -1;
  }
  else if ( v16 != 67324752 )
  {
    v5 = -103;
  }
  if ( unzlocal_getShort(fin: s->file, pX: &v16) != 0 )
    v5 = -1;
  if ( unzlocal_getShort(fin: s->file, pX: v17) != 0 )
    v5 = -1;
  if ( unzlocal_getShort(fin: s->file, pX: &v16) != 0 )
  {
    v5 = -1;
  }
  else if ( v5 == 0 )
  {
    compression_method = s->cur_file_info.compression_method;
    if ( v16 != compression_method || compression_method != 0 && compression_method != 8 )
      v5 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &v16) != 0 )
    v5 = -1;
  Long = unzlocal_getLong(fin: s->file, pX: &v16);
  v12 = v17[0];
  if ( Long != 0 )
  {
    v5 = -1;
  }
  else if ( v5 == 0 && v16 != s->cur_file_info.crc && (v17[0] & 8) == 0 )
  {
    v5 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &v16) != 0 )
  {
    v5 = -1;
  }
  else if ( v5 == 0 && v16 != s->cur_file_info.compressed_size && (v12 & 8) == 0 )
  {
    v5 = -103;
  }
  if ( unzlocal_getLong(fin: s->file, pX: &v16) != 0 )
  {
    v5 = -1;
  }
  else if ( v5 == 0 && v16 != s->cur_file_info.uncompressed_size && (v12 & 8) == 0 )
  {
    v5 = -103;
  }
  Short = unzlocal_getShort(fin: s->file, pX: v17);
  v14 = v17[0];
  if ( Short != 0 )
  {
    v5 = -1;
  }
  else if ( v5 == 0 && v17[0] != s->cur_file_info.size_filename )
  {
    v5 = -103;
  }
  *piSizeVar += v17[0];
  if ( unzlocal_getShort(fin: s->file, pX: v17) != 0 )
    v5 = -1;
  v15 = v17[0];
  *poffset_local_extrafield = s->cur_file_info_internal.offset_curfile + v14 + 30;
  *psize_local_extrafield = v15;
  *piSizeVar += v15;
  return v5;
}


// ========================================================================
// ?unzReadCurrentFile@@YAHPAX0I@Z
// EA  : 0x82F1DCB0
// RVA : 0x00F1DCB0
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzReadCurrentFile(_DWORD *file, void *buf, unsigned int len)
{
  int v4; // r29
  int v6; // r31
  unsigned int v7; // r11
  unsigned int v8; // r11
  unsigned int v9; // r30
  void *v10; // r9
  unsigned int v11; // r8
  unsigned int v12; // r7
  unsigned int v13; // r30
  int v14; // r11
  unsigned int i; // ctr
  unsigned int v16; // r3
  unsigned int v17; // r9
  unsigned int v18; // r6
  unsigned int v19; // r5
  int v20; // r11
  unsigned int v21; // r4
  unsigned int v22; // r10
  const unsigned __int8 *v23; // r30
  int v24; // r28
  int v25; // r3
  const unsigned __int8 *v26; // r4
  unsigned int v27; // r30
  int v28; // r28
  unsigned int v29; // r3
  int v30; // r10

  v4 = 0;
  if ( file == nullptr )
    return -102;
  v6 = file[31];
  if ( v6 == 0 )
    return -102;
  if ( *(_DWORD *)v6 == 0 )
    return -100;
  if ( len == 0 )
    return 0;
  v7 = *(_DWORD *)(v6 + 92);
  *(_DWORD *)(v6 + 16) = buf;
  *(_DWORD *)(v6 + 20) = len;
  if ( len > v7 )
    *(_DWORD *)(v6 + 20) = v7;
  while ( *(_DWORD *)(v6 + 20) != 0 )
  {
    if ( *(_DWORD *)(v6 + 8) == 0 )
    {
      v8 = *(_DWORD *)(v6 + 88);
      if ( v8 != 0 )
      {
        v9 = 0x10000;
        if ( v8 < 0x10000 )
          v9 = *(_DWORD *)(v6 + 88);
        if ( file[16] == v8
          && fseek(stream: *(_iobuf **)(v6 + 96), offset: *(_DWORD *)(v6 + 104) + *(_DWORD *)(v6 + 60), whence: 0) != 0
          || fread(buffer: *(void **)v6, elementSize: v9, count: 1u, stream: *(_iobuf **)(v6 + 96)) != 1 )
        {
          return -1;
        }
        v10 = *(void **)v6;
        v11 = v9 + *(_DWORD *)(v6 + 60);
        v12 = *(_DWORD *)(v6 + 88) - v9;
        *(_DWORD *)(v6 + 8) = v9;
        *(_DWORD *)(v6 + 60) = v11;
        *(_DWORD *)(v6 + 88) = v12;
        *(_DWORD *)(v6 + 4) = v10;
      }
    }
    if ( *(_DWORD *)(v6 + 100) != 0 )
    {
      v23 = *(const unsigned __int8 **)(v6 + 16);
      v24 = *(_DWORD *)(v6 + 24);
      v25 = inflate(strm: (z_stream_s *)(v6 + 4), flush: 2);
      v26 = v23;
      v27 = *(_DWORD *)(v6 + 24) - v24;
      v28 = v25;
      v29 = crc32(crc: *(_DWORD *)(v6 + 80), buf: v26, len: v27);
      v30 = *(_DWORD *)(v6 + 92);
      *(_DWORD *)(v6 + 80) = v29;
      v4 += v27;
      *(_DWORD *)(v6 + 92) = v30 - v27;
      if ( v28 == 1 )
        return v4;
      if ( v28 != 0 )
        return v28;
    }
    else
    {
      v13 = *(_DWORD *)(v6 + 8);
      if ( *(_DWORD *)(v6 + 20) < v13 )
        v13 = *(_DWORD *)(v6 + 20);
      v14 = 0;
      if ( v13 != 0 )
      {
        for ( i = v13; i != 0; --i )
        {
          *(_BYTE *)(*(_DWORD *)(v6 + 16) + v14) = *(_BYTE *)(*(_DWORD *)(v6 + 4) + v14);
          ++v14;
        }
      }
      v16 = crc32(crc: *(_DWORD *)(v6 + 80), buf: *(const unsigned __int8 **)(v6 + 16), len: v13);
      v4 += v13;
      v17 = *(_DWORD *)(v6 + 16) + v13;
      v18 = *(_DWORD *)(v6 + 92) - v13;
      v19 = *(_DWORD *)(v6 + 8) - v13;
      v20 = *(_DWORD *)(v6 + 24);
      v21 = *(_DWORD *)(v6 + 20) - v13;
      v22 = *(_DWORD *)(v6 + 4) + v13;
      *(_DWORD *)(v6 + 80) = v16;
      *(_DWORD *)(v6 + 92) = v18;
      *(_DWORD *)(v6 + 8) = v19;
      *(_DWORD *)(v6 + 20) = v21;
      *(_DWORD *)(v6 + 16) = v17;
      *(_DWORD *)(v6 + 4) = v22;
      *(_DWORD *)(v6 + 24) = v13 + v20;
    }
  }
  return v4;
}


// ========================================================================
// ?unztell@@YAJPAX@Z
// EA  : 0x82F1DF10
// RVA : 0x00F1DF10
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unztell(_DWORD *file)
{
  int result; // r3
  int v2; // r11

  if ( file == nullptr )
    return -102;
  v2 = file[31];
  result = -102;
  if ( v2 != 0 )
    return *(_DWORD *)(v2 + 24);
  return result;
}


// ========================================================================
// ?unzCloseCurrentFile@@YAHPAX@Z
// EA  : 0x82F1DF38
// RVA : 0x00F1DF38
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzCloseCurrentFile(_DWORD *file)
{
  int v2; // r27
  int v4; // r31
  int v5; // r11

  v2 = 0;
  if ( file == nullptr )
    return -102;
  v4 = file[31];
  if ( v4 == 0 )
    return -102;
  if ( *(_DWORD *)(v4 + 92) == 0 && *(_DWORD *)(v4 + 80) != *(_DWORD *)(v4 + 84) )
    v2 = -105;
  if ( *(_DWORD *)v4 != 0 )
    idMem::Free(this: &mem, ptr: *(void **)v4, align: ALIGN_16);
  v5 = *(_DWORD *)(v4 + 64);
  *(_DWORD *)v4 = 0;
  if ( v5 != 0 )
    inflateEnd(strm: (z_stream_s *)(v4 + 4));
  *(_DWORD *)(v4 + 64) = 0;
  idMem::Free(this: &mem, ptr: (void *)v4, align: ALIGN_16);
  file[31] = 0;
  return v2;
}


// ========================================================================
// ?unzClose@@YAHPAX@Z
// EA  : 0x82F1DFF0
// RVA : 0x00F1DFF0
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzClose(_iobuf **file)
{
  if ( file == nullptr )
    return -102;
  if ( file[31] != nullptr )
    unzCloseCurrentFile(file);
  fclose(stream: *file);
  idMem::Free(this: &mem, ptr: file, align: ALIGN_16);
  return 0;
}


// ========================================================================
// ?unzOpenCurrentFile@@YAHPAX@Z
// EA  : 0x82F1E070
// RVA : 0x00F1E070
// PDB : w:\tech5\shared\idlib\filesystem\unzip.cpp
// ========================================================================

int __fastcall unzOpenCurrentFile(unz_s *file)
{
  file_in_zip_read_info_s *v3; // r31
  char *v4; // r3
  unsigned int v5; // r10
  unsigned int v6; // r9
  char v7; // r10
  unsigned int v8; // r11
  int v9; // r8
  unsigned int v10; // [sp+50h] [-40h] BYREF
  unsigned int v11; // [sp+54h] [-3Ch] BYREF
  unsigned int v12; // [sp+58h] [-38h] BYREF

  if ( file == nullptr || file->current_file_ok == 0 )
    return -102;
  if ( file->pfile_in_zip_read != nullptr )
    unzCloseCurrentFile(file);
  if ( unzlocal_CheckCurrentFileCoherencyHeader(
         s: file,
         piSizeVar: &v12,
         poffset_local_extrafield: &v10,
         psize_local_extrafield: &v11) != 0 )
    return -103;
  v3 = (file_in_zip_read_info_s *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\filesystem\\Unzip.cpp(856) : TAG_FILE",
                                    size: 0x6Cu,
                                    tag: TAG_FILE,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v3 == nullptr )
    return -104;
  v4 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\filesystem\\Unzip.cpp(860) : TAG_FILE",
                 size: 0x10000u,
                 tag: TAG_FILE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v5 = v10;
  v6 = v11;
  v3->read_buffer = v4;
  v3->pos_local_extrafield = 0;
  v3->offset_local_extrafield = v5;
  v3->size_local_extrafield = v6;
  if ( v4 == nullptr )
  {
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
    return -104;
  }
  v3->stream_initialised = 0;
  v7 = _cntlzw(file->cur_file_info.compression_method);
  v3->crc32_wait = file->cur_file_info.crc;
  v3->crc32 = 0;
  v3->compression_method = file->cur_file_info.compression_method;
  v3->file = file->file;
  v3->byte_before_the_zipfile = file->byte_before_the_zipfile;
  v3->stream.total_out = 0;
  if ( (v7 & 0x20) == 0 )
  {
    v3->stream.zalloc = nullptr;
    v3->stream.zfree = nullptr;
    v3->stream.opaque = nullptr;
    if ( inflateInit2_(strm: &v3->stream, windowBits: -15, version: "1.2.3", stream_size: 56) == 0 )
      v3->stream_initialised = 1;
  }
  v8 = v12;
  v3->rest_read_compressed = file->cur_file_info.compressed_size;
  v3->rest_read_uncompressed = file->cur_file_info.uncompressed_size;
  v9 = file->cur_file_info_internal.offset_curfile + v8 + 30;
  v3->stream.avail_in = 0;
  v3->pos_in_zipfile = v9;
  file->pfile_in_zip_read = v3;
  return 0;
}

