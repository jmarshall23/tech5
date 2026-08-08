
// ========================================================================
// ?Read@idFile_MTP@@UAAIPAXI@Z
// EA  : 0x82F11460
// RVA : 0x00F11460
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

unsigned int __fastcall idFile_MTP::Read(idFile_MTP *this, void *buffer, unsigned int len)
{
  return this->ReadOfs(
           this: (struct idFile_MTP *)HIDWORD(this->position),
           a2: LODWORD(this->position),
           a3: buffer,
           a4: len);
}


// ========================================================================
// ?Write@idFile_MTP@@UAAIPBXI@Z
// EA  : 0x82F11480
// RVA : 0x00F11480
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

unsigned int __fastcall idFile_MTP::Write(idFile_MTP *this, const void *buffer, unsigned int len)
{
  return this->WriteOfs(
           this: (struct idFile_MTP *)HIDWORD(this->position),
           a2: LODWORD(this->position),
           a3: buffer,
           a4: len);
}


// ========================================================================
// ?Length@idFile_MTP@@UBA_JXZ
// EA  : 0x82F114A0
// RVA : 0x00F114A0
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idFile_MTP::Length(idFile_MTP *this)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = this->length;
  return result;
}


// ========================================================================
// ?GetStateCompiler@XGRAPHICS@@YAPAU_CC_STATE_COMPILER@1@PAX@Z
// EA  : 0x82F114A8
// RVA : 0x00F114A8
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

XGRAPHICS::_CC_STATE_COMPILER *__fastcall XGRAPHICS::GetStateCompiler(_DWORD *hSSMDev)
{
  return (XGRAPHICS::_CC_STATE_COMPILER *)hSSMDev[24];
}


// ========================================================================
// ??0idFile_MTP@@QAA@XZ
// EA  : 0x82F114B0
// RVA : 0x00F114B0
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

idFile_MTP *__fastcall idFile_MTP::idFile_MTP(idFile_MTP *this)
{
  unsigned __int64 v2; // r11

  idFile::idFile(this);
  this->__vftable = (idFile_MTP_vtbl *)&idFile_MTP::`vftable';
  LODWORD(v2) = 0;
  this->name.data = this->name.baseBuffer;
  HIDWORD(v2) = this->fullPath.baseBuffer;
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->fullPath.allocedAndFlag = 20;
  this->fullPath.data = this->fullPath.baseBuffer;
  this->fullPath.len = 0;
  this->fullPath.baseBuffer[0] = 0;
  this->position = v2;
  this->mode = FS_READ;
  this->length = v2;
  this->timestamp = -1;
  return this;
}


// ========================================================================
// ??1idFile_MTP@@UAA@XZ
// EA  : 0x82F11548
// RVA : 0x00F11548
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void __fastcall idFile_MTP::~idFile_MTP(idFile_MTP *this)
{
  this->__vftable = (idFile_MTP_vtbl *)&idFile_MTP::`vftable';
  idStr::FreeData(this: &this->fullPath);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_MTP_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$112090
// EA  : 0x82F115A8
// RVA : 0x00F115A8
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _unwind_112090()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$112091
// EA  : 0x82F115D0
// RVA : 0x00F115D0
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _unwind_112091()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?Seek@idFile_MTP@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x82F11608
// RVA : 0x00F11608
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

int __fastcall idFile_MTP::Seek(idFile_MTP *this, int a2, __int64 offset, fsOrigin_t origin)
{
  unsigned __int64 v4; // r27
  unsigned int v6; // r28
  unsigned __int64 v8; // r3
  unsigned __int64 position; // r11

  LODWORD(v4) = a2;
  v6 = HIDWORD(offset);
  Sys_MutexLock(handle: &idFile_MTP::mutex.handle, blocking: true);
  if ( v6 != 0 )
  {
    if ( v6 == 1 )
    {
      LODWORD(v8) = this->Length(this);
      this->position = v8;
    }
    else
    {
      if ( v6 >= 3 )
      {
        Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
        return -1;
      }
      this->position = v4;
    }
  }
  else
  {
    position = this->position;
    LODWORD(position) = v4 + position;
    this->position = position;
  }
  Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
  return 0;
}


// ========================================================================
// __unwind$112127
// EA  : 0x82F116A8
// RVA : 0x00F116A8
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _unwind_112127()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?SendRequest@idFile_MTP@@AAA_N_KIG@Z
// EA  : 0x82F11738
// RVA : 0x00F11738
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

int __fastcall idFile_MTP::SendRequest(
        idFile_MTP *this,
        unsigned int a2,
        unsigned __int64 offset,
        unsigned int length,
        unsigned __int16 operation)
{
  unsigned __int64 v6; // r29
  int v7; // r27
  __int16 v8; // r26
  int len; // r11
  char *data; // r10
  int v11; // r9
  char v12; // r8
  int v13; // r29
  int v14; // r30
  int v15; // r27
  _QWORD v17[2]; // [sp+60h] [-450h] BYREF
  int v18; // [sp+70h] [-440h] BYREF

  v6 = __PAIR64__(&idFile_MTP::tcp, a2);
  v7 = HIDWORD(offset);
  v8 = offset;
  Sys_MutexLock(handle: &idFile_MTP::mutex.handle, blocking: true);
  if ( (!idTCP::IsOpen(this: &idFile_MTP::tcp) || idTCP::Read(this: &idFile_MTP::tcp, data: nullptr, size: 0) != 0)
    && !idTCP::Connect(
          this: &idFile_MTP::tcp,
          host: mtp_server.valueString.data,
          port: 0xAD1u,
          nonBlocking: true,
          silent: false,
          nagle: false) )
  {
    idLib::FatalError(fmt: "idFile_MTP::SendRequest: connect failed (%s:%d)", mtp_server.valueString.data, 2769);
  }
  len = this->name.len;
  data = this->name.data;
  v17[0] = v6;
  HIDWORD(v17[1]) = v7;
  v11 = (char *)&v18 - data;
  LOWORD(v17[1]) = v8;
  WORD2(v17[1]) = len;
  do
  {
    v12 = *data;
    data[v11] = *data;
    ++data;
  }
  while ( v12 != 0 );
  v13 = len + 16;
  if ( len + 16 < 0 )
    idLib::Printf(fmt: "idTCP toWrite < 0");
  v14 = idTCP::Write(this: &idFile_MTP::tcp, data: v17, size: v13);
  if ( v14 == v13 )
    goto LABEL_17;
  idLib::Printf(fmt: "idFile_MTP::SendRequest: partial write, %i != %i\n", v14, v13);
  if ( !idTCP::IsOpen(this: &idFile_MTP::tcp)
    && !idTCP::Connect(
          this: &idFile_MTP::tcp,
          host: mtp_server.valueString.data,
          port: 0xAD1u,
          nonBlocking: true,
          silent: false,
          nagle: false) )
  {
    idLib::FatalError(fmt: "idFile_MTP::SendRequest: connect failed (%s:%d)", mtp_server.valueString.data, 2769);
  }
  v15 = __CFADD__(-v14, v14 ^ 0x80000000) ? 0 : v14;
  if ( v13 - v15 < 0 )
    idLib::Printf(fmt: "idTCP toWrite < 0");
  if ( idTCP::Write(this: &idFile_MTP::tcp, data: (char *)v17 + v15, size: v13 - v15) == v13 - v15 )
  {
LABEL_17:
    Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
    return 1;
  }
  else
  {
    Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
    return 0;
  }
}


// ========================================================================
// $LN54_5
// EA  : 0x82F11928
// RVA : 0x00F11928
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _LN54_5()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 1200 + 84));
}


// ========================================================================
// ?Open@idFile_MTP@@QAA_NPBDW4fsMode_t@@@Z
// EA  : 0x82F11958
// RVA : 0x00F11958
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

BOOL __fastcall idFile_MTP::Open(idFile_MTP *this, const char *filename, fsMode_t mode)
{
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  va *v8; // r3
  unsigned __int16 v9; // r8
  unsigned int v10; // r7
  int v11; // r6
  int v13; // r11
  unsigned __int64 v14; // r9
  BOOL v15; // r30
  int v16; // [sp+8h] [-1098h]
  int v17; // [sp+Ch] [-1094h]
  int v18; // [sp+10h] [-1090h]
  int v19; // [sp+14h] [-108Ch]
  int v20; // [sp+18h] [-1088h]
  int v21; // [sp+1Ch] [-1084h]
  _DWORD v22[4]; // [sp+60h] [-1040h] BYREF
  va v23; // [sp+70h] [-1030h] BYREF

  this->mode = mode;
  idStr::operator=(this: &this->name, text: filename);
  HIDWORD(v5) = this->name.data;
  v8 = va::va(this: &v23, fmt: "MTP:%s", a3: v5, a4: v7, a5: v6, a6: v16, a7: v17, a8: v18, a9: v19, a10: v20, a11: v21);
  idStr::operator=(this: &this->fullPath, text: v8);
  Sys_MutexLock(handle: &idFile_MTP::mutex.handle, blocking: true);
  v11 = 1;
  if ( mode == FS_READ || mode == FS_READ_NO_BUFFERING )
  {
    v11 = 0;
  }
  else if ( mode == FS_APPEND )
  {
    v11 = 2;
  }
  if ( (unsigned __int8)idFile_MTP::SendRequest(this, a2: 0, offset: (unsigned int)v11, length: v10, operation: v9) != 0 )
  {
    if ( idTCP::ReadBlocking(this: &idFile_MTP::tcp, data: v22, size: 16, timeoutMS: 1000) == 16 )
    {
      v13 = v22[2];
      LODWORD(v14) = v22[1];
      HIDWORD(v14) = -1 - v22[2];
      this->timestamp = v22[2];
      this->length = v14;
      v15 = v13 != -1;
      Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
      return v15;
    }
    else
    {
      idTCP::Close(this: &idFile_MTP::tcp);
      Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
      return false;
    }
  }
  else
  {
    Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
    return false;
  }
}


// ========================================================================
// __unwind$112543
// EA  : 0x82F11A7C
// RVA : 0x00F11A7C
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _unwind_112543()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 4256 + 80));
}


// ========================================================================
// ?ReadOfs@idFile_MTP@@UAAI_JPAXI@Z
// EA  : 0x82F11AB0
// RVA : 0x00F11AB0
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall idFile_MTP::ReadOfs(idFile_MTP *this, int a2, __int64 offset, void *buffer, unsigned int len)
{
  unsigned int v5; // r30
  int v6; // r25
  int v8; // r4
  __int64 v9; // r26
  int v10; // r16
  unsigned int v11; // r27
  fsMode_t mode; // r11
  unsigned __int16 v14; // r8
  unsigned int v15; // r7
  unsigned __int64 v16; // r6
  char v17; // r28
  unsigned int v18; // r26
  int v19; // r4
  int Blocking; // r3
  unsigned int v21; // r3
  unsigned __int64 v22; // r11
  int v23; // r8
  int v24; // r7
  int v25; // r6
  int v26; // r5
  int v27; // r4
  int v28; // r3
  int v29; // [sp+50h] [-B0h] BYREF
  int v30; // [sp+54h] [-ACh]
  idSysMutex *v31; // [sp+58h] [-A8h]
  idSysMutex *v32; // [sp+5Ch] [-A4h]
  __int64 v33; // [sp+118h] [+18h]

  v33 = *(_QWORD *)(&this - 1);
  LODWORD(v9) = v8;
  v10 = HIDWORD(offset);
  v11 = offset;
  if ( (_DWORD)offset == 0 )
    return 0;
  mode = this->mode;
  if ( mode != FS_READ && mode != FS_READ_WRITE && mode != FS_READ_NO_BUFFERING )
    return 0;
  if ( (unsigned int)offset > 0x10000000 || v6 > 100 )
  {
    idLib::FatalError(fmt: "idFile_MTP::Bad read parameters %s:%i,%i", this->name.data, v6, (_DWORD)offset);
    return _LN77_5(a1: v28, a2: v27, a3: v26, a4: v25, a5: v24, a6: v23);
  }
  else
  {
    v31 = &idFile_MTP::mutex;
    v32 = &idFile_MTP::mutex;
    Sys_MutexLock(handle: &idFile_MTP::mutex.handle, blocking: true);
    v30 = 0;
    HIDWORD(v9) = "idFile_MTP: excess data, %i + %i > %i\n";
LABEL_9:
    if ( idTCP::IsOpen(this: &idFile_MTP::tcp)
      || idTCP::Connect(
           this: &idFile_MTP::tcp,
           host: mtp_server.valueString.data,
           port: 0xAD1u,
           nonBlocking: true,
           silent: false,
           nagle: false) )
    {
      LODWORD(v16) = 0;
      HIDWORD(v16) = v11;
      v5 = 0;
      v17 = 0;
      if ( (unsigned __int8)idFile_MTP::SendRequest(this, a2: v9, offset: v16, length: v15, operation: v14) != 0 )
      {
        v18 = Sys_Milliseconds();
        if ( v11 != 0 )
        {
          while ( 1 )
          {
            v29 = 0;
            v19 = idTCP::ReadBlocking(this: &idFile_MTP::tcp, data: &v29, size: 4, timeoutMS: 1000);
            if ( v19 != 4 )
            {
              idLib::Printf(fmt: "idFile_MTP: length read failed, %i != %i\n", v19, 4);
              goto LABEL_22;
            }
            if ( v29 == 0 )
              goto LABEL_23;
            if ( v29 + v5 > v11 )
            {
              idLib::Printf(fmt: (const char *)HIDWORD(v9), v5);
              goto LABEL_22;
            }
            Blocking = idTCP::ReadBlocking(this: &idFile_MTP::tcp, data: (void *)(v5 + v10), size: v29, timeoutMS: 1000);
            if ( Blocking != v29 )
              break;
            v5 += v29;
            if ( v5 >= v11 )
              goto LABEL_23;
          }
          idLib::Printf(fmt: "idFile_MTP: ReadBlocking failed, %i != %i\n", Blocking, v29);
LABEL_22:
          v17 = 1;
        }
LABEL_23:
        v21 = Sys_Milliseconds();
        HIDWORD(v22) = showMTPtimes;
        if ( showMTPtimes != 0 )
          idLib::Printf(fmt: "%i msec for %i bytes\n", v21 - v18, v11);
        v9 = v33;
        goto LABEL_26;
      }
      while ( 1 )
      {
        idLib::Printf(fmt: "idFile_MTP: SendRequest failed\n");
LABEL_26:
        if ( v17 == 0 )
          break;
        idLib::Printf(fmt: "idFile_MTP: Closing MTP FTP connection for retry.\n");
        idTCP::Close(this: &idFile_MTP::tcp);
        if ( ++v30 < 5 )
          goto LABEL_9;
        v5 = v9;
        idLib::Printf(fmt: "offset: %i\n", (_DWORD)v9);
        idLib::Printf(fmt: "len: %i\n", v11);
        idLib::FatalError(fmt: "idFile_MTP::Read and retry failed on %s:%i,%i", this->name.data, (_DWORD)v9, v11);
      }
    }
    else
    {
      idLib::FatalError(fmt: "idFile_MTP: connect failed");
    }
    LODWORD(v22) = v11 + v9;
    this->position = v22;
    Sys_MutexUnlock(handle: &v31->handle);
    return v5;
  }
}


// ========================================================================
// $LN77_5
// EA  : 0x82F11D78
// RVA : 0x00F11D78
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _LN77_5()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 256 + 92));
}


// ========================================================================
// ?SetLength@idFile_MTP@@UAAXI@Z
// EA  : 0x82F11DA0
// RVA : 0x00F11DA0
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void __fastcall idFile_MTP::SetLength(
        idFile_MTP *this,
        unsigned int len,
        int a3,
        int a4,
        unsigned int a5,
        unsigned __int16 a6)
{
  unsigned __int64 v6; // r11
  unsigned __int64 v7; // r6

  LODWORD(v6) = len;
  HIDWORD(v7) = len;
  LODWORD(v7) = 3;
  this->length = v6;
  idFile_MTP::SendRequest(this, a2: 0, offset: v7, length: a5, operation: a6);
}


// ========================================================================
// ?WriteOfs@idFile_MTP@@UAAI_JPBXI@Z
// EA  : 0x82F11DC0
// RVA : 0x00F11DC0
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

int __fastcall idFile_MTP::WriteOfs(idFile_MTP *this, int a2, __int64 offset, const void *buffer, unsigned int len)
{
  int v7; // r20
  int v8; // r26
  fsMode_t mode; // r11
  int v11; // r29
  int valueInteger; // r27
  unsigned __int16 v13; // r8
  unsigned int v14; // r7
  int v15; // r30
  unsigned __int64 v16; // r6
  _DWORD v17[28]; // [sp+50h] [-70h] BYREF

  v7 = HIDWORD(offset);
  v8 = offset;
  if ( (_DWORD)offset == 0 )
    return 0;
  mode = this->mode;
  if ( mode != FS_WRITE && mode != FS_READ_WRITE && mode != FS_APPEND )
    return 0;
  v17[1] = &idFile_MTP::mutex;
  Sys_MutexLock(handle: &idFile_MTP::mutex.handle, blocking: true);
  if ( !idTCP::IsOpen(this: &idFile_MTP::tcp)
    && !idTCP::Connect(
          this: &idFile_MTP::tcp,
          host: mtp_server.valueString.data,
          port: 0xAD1u,
          nonBlocking: true,
          silent: false,
          nagle: false) )
  {
    idLib::FatalError(fmt: "idFile_MTP: connect failed");
  }
  v11 = 0;
  v17[0] = 0;
  valueInteger = mtp_writeSize.valueInteger;
  if ( v8 <= 0 )
  {
LABEL_23:
    Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
    return v11;
  }
  else
  {
    while ( idTCP::IsOpen(this: &idFile_MTP::tcp)
         || idTCP::Connect(
              this: &idFile_MTP::tcp,
              host: mtp_server.valueString.data,
              port: 0xAD1u,
              nonBlocking: true,
              silent: false,
              nagle: false) )
    {
      v15 = v8 - v11;
      if ( valueInteger < v8 - v11 )
        v15 = valueInteger;
      LODWORD(v16) = 2;
      HIDWORD(v16) = v15;
      if ( (unsigned __int8)idFile_MTP::SendRequest(this, a2: v11 + a2, offset: v16, length: v14, operation: v13) == 0 )
        goto LABEL_21;
      if ( v15 < 0 )
        idLib::Printf(fmt: "idTCP toWrite < 0");
      if ( idTCP::Write(this: &idFile_MTP::tcp, data: (const void *)(v11 + v7), size: v15) <= 0 )
        idTCP::Close(this: &idFile_MTP::tcp);
      idTCP::ReadBlocking(this: &idFile_MTP::tcp, data: v17, size: 4, timeoutMS: 5000);
      if ( v17[0] != 0 )
        v11 += v17[0];
      else
LABEL_21:
        idTCP::Close(this: &idFile_MTP::tcp);
      if ( v11 >= v8 )
        goto LABEL_23;
    }
    idLib::FatalError(fmt: "idFile_MTP: connect failed");
    return _LN57_6();
  }
}


// ========================================================================
// $LN57_6
// EA  : 0x82F11F98
// RVA : 0x00F11F98
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _LN57_6()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 192 + 84));
}


// ========================================================================
// ?List@idFile_MTP@@QAA_NPBD0AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F11FC8
// RVA : 0x00F11FC8
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

int __fastcall idFile_MTP::List(idFile_MTP *this, const char *directory, const char *extension, idList<idStr,5> *list)
{
  idStr *p_fullPath; // r29
  unsigned __int16 v7; // r8
  unsigned int v8; // r7
  char *buffer; // r29
  int Blocking; // r3
  unsigned int v12; // r30
  int v13; // r11
  int v14[2]; // [sp+50h] [-60h] BYREF
  idTempArray<char> v15; // [sp+58h] [-58h] BYREF
  idStr v16[2]; // [sp+60h] [-50h] BYREF

  p_fullPath = &this->fullPath;
  idStr::Format(this: &this->fullPath, fmt: "%s\\*%s", directory, extension);
  idStr::Right(this: p_fullPath, len: this->fullPath.len - 4, result: &this->name);
  idStr::SlashesToBackSlashes(this: p_fullPath);
  if ( (unsigned __int8)idFile_MTP::SendRequest(this, a2: 1u, offset: 0, length: v8, operation: v7) == 0 )
    return 0;
  v14[1] = (int)&idFile_MTP::mutex;
  Sys_MutexLock(handle: &idFile_MTP::mutex.handle, blocking: true);
  if ( idTCP::ReadBlocking(this: &idFile_MTP::tcp, data: v14, size: 4, timeoutMS: 1000) != 4 )
  {
    idTCP::Close(this: &idFile_MTP::tcp);
    Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
    return 0;
  }
  idTempArray<char>::idTempArray<char>(this: &v15, num: v14[0]);
  buffer = v15.buffer;
  Blocking = idTCP::ReadBlocking(this: &idFile_MTP::tcp, data: v15.buffer, size: v14[0], timeoutMS: 1000);
  if ( Blocking == v14[0] )
  {
    v12 = 0;
    while ( v12 < v14[0] )
    {
      idStr::idStr(this: v16, text: &buffer[v12]);
      idList<idStr,5>::Append(this: list, obj: v16);
      idStr::FreeData(this: v16);
      do
        v13 = (unsigned __int8)buffer[v12++];
      while ( v13 != 0 );
    }
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
    return 1;
  }
  else
  {
    idTCP::Close(this: &idFile_MTP::tcp);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    Sys_MutexUnlock(handle: &idFile_MTP::mutex.handle);
    return 0;
  }
}


// ========================================================================
// __unwind$112814
// EA  : 0x82F1216C
// RVA : 0x00F1216C
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _unwind_112814()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 84));
}


// ========================================================================
// __unwind$112815
// EA  : 0x82F12194
// RVA : 0x00F12194
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _unwind_112815()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$112816
// EA  : 0x82F121BC
// RVA : 0x00F121BC
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void _unwind_112816()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// `dynamic initializer for 'mtp_server''
// EA  : 0x83395070
// RVA : 0x01395070
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mtp_server__()
{
  idCVar::idCVar(
    this: &mtp_server,
    name: "mtp_server",
    value: "10.4.20.180",
    flags: 0,
    description: "IP Address of the MTP server",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mtp_server__);
}


// ========================================================================
// `dynamic initializer for 'mtp_writeSize''
// EA  : 0x833950C8
// RVA : 0x013950C8
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mtp_writeSize__()
{
  idCVar::idCVar(
    this: &mtp_writeSize,
    name: "mtp_writeSize",
    value: "1400",
    flags: 0,
    description: "per write size for mtp writes to server",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mtp_writeSize__);
}


// ========================================================================
// `dynamic initializer for 'idFile_MTP::tcp''
// EA  : 0x83395120
// RVA : 0x01395120
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idFile_MTP::tcp__()
{
  idTCP::idTCP(this: &idFile_MTP::tcp);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idFile_MTP::tcp__);
}


// ========================================================================
// `dynamic initializer for 'idFile_MTP::mutex''
// EA  : 0x83395158
// RVA : 0x01395158
// PDB : w:\tech5\shared\idlib\filesystem\file_mtp.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idFile_MTP::mutex__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&idFile_MTP::mutex);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idFile_MTP::mutex__);
}

