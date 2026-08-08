
// ========================================================================
// ??0idFile@@QAA@XZ
// EA  : 0x82F07480
// RVA : 0x00F07480
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

idFile *__fastcall idFile::idFile(idFile *this)
{
  this->__vftable = (idFile_vtbl *)&idFile::`vftable';
  this->uniqID = Sys_InterlockedAdd(value: &atomicUniqID, i: 1);
  return this;
}


// ========================================================================
// ?VPrintf@idFile@@UAAIPBDPAD@Z
// EA  : 0x82F074D0
// RVA : 0x00F074D0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

unsigned int __fastcall idFile::VPrintf(idFile *this, const char *fmt, char *args)
{
  signed int v4; // r5
  char v6[16]; // [sp+50h] [-1010h] BYREF

  v4 = idStr::vsnPrintf(dest: v6, size: 4096, fmt, argptr: args);
  if ( v4 >= 4096 )
    idLib::FatalError(fmt: "idFile::WriteFloatString: string too long.");
  return this->Write(this, a2: v6, a3: v4);
}


// ========================================================================
// ?SetReadOnlyData@idFile_Memory@@QAAXPBDI@Z
// EA  : 0x82F07540
// RVA : 0x00F07540
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::SetReadOnlyData(idFile_Memory *this, char *data, unsigned int length)
{
  this->maxSize = length;
  this->fileSize = length;
  this->allocated = length;
  this->mode = 0;
  this->filePtr = data;
  this->curPtr = data;
  this->ownsData = false;
}


// ========================================================================
// ?SetWritableData@idFile_Memory@@QAAXPADI@Z
// EA  : 0x82F07568
// RVA : 0x00F07568
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::SetWritableData(idFile_Memory *this, char *data, unsigned int length)
{
  this->maxSize = length;
  this->allocated = length;
  this->fileSize = 0;
  this->mode = 1;
  this->filePtr = data;
  this->curPtr = data;
  this->ownsData = false;
}


// ========================================================================
// ?ReadOfs@idFile_Memory@@UAAI_JPAXI@Z
// EA  : 0x82F07590
// RVA : 0x00F07590
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

unsigned int __fastcall idFile_Memory::ReadOfs(
        idFile_RingBuffer *this,
        int a2,
        __int64 offset,
        void *buffer,
        unsigned int len)
{
  void *v5; // r30
  unsigned int v7; // r29

  v5 = (void *)HIDWORD(offset);
  v7 = offset;
  ((void (__fastcall *)(idFile_RingBuffer *))this->Seek)(a1: this);
  return this->Read(this, a2: v5, a3: v7);
}


// ========================================================================
// ?WriteOfs@idFile_Memory@@UAAI_JPBXI@Z
// EA  : 0x82F075E0
// RVA : 0x00F075E0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

unsigned int __fastcall idFile_Memory::WriteOfs(
        idFile_Memory *this,
        int a2,
        __int64 offset,
        const void *buffer,
        unsigned int len)
{
  const void *v5; // r30
  unsigned int v7; // r29

  v5 = (const void *)HIDWORD(offset);
  v7 = offset;
  ((void (__fastcall *)(idFile_Memory *))this->Seek)(a1: this);
  return this->Write(this, a2: v5, a3: v7);
}


// ========================================================================
// ?Length@idFile_Memory@@UBA_JXZ
// EA  : 0x82F07630
// RVA : 0x00F07630
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

unsigned int __fastcall idFile_Memory::Length(idFile_Memory *this)
{
  return this->fileSize;
}


// ========================================================================
// ?SetLength@idFile_Memory@@UAAXI@Z
// EA  : 0x82F07638
// RVA : 0x00F07638
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::SetLength(idFile_Memory *this, unsigned int len)
{
  unsigned int maxSize; // r4
  char *v5; // r3
  size_t allocated; // r5
  char *v7; // r30
  char *filePtr; // r4
  char *curPtr; // r10

  if ( len > this->allocated )
  {
    maxSize = this->maxSize;
    if ( maxSize != 0 )
      idLib::Error(fmt: "idFile_Memory::SetLength: exceeded maximum size %d", maxSize);
    v5 = (char *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\filesystem\\File.cpp(477) : TAG_FILE",
                   size: len,
                   tag: TAG_FILE,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    allocated = this->allocated;
    v7 = v5;
    if ( allocated != 0 )
      memcpy(Dst: v5, Src: this->filePtr, Size: allocated);
    filePtr = this->filePtr;
    curPtr = this->curPtr;
    this->allocated = len;
    this->curPtr = &curPtr[v7 - filePtr];
    if ( filePtr != nullptr )
      idMem::Free(this: &mem, ptr: filePtr, align: ALIGN_16);
    this->filePtr = v7;
  }
  this->fileSize = len;
}


// ========================================================================
// ?Tell@idFile_Memory@@UBA_JXZ
// EA  : 0x82F076F0
// RVA : 0x00F076F0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_Memory::Tell(idFile_Memory *this)
{
  return this->curPtr - this->filePtr;
}


// ========================================================================
// ?SetMaxLength@idFile_Memory@@QAAXI@Z
// EA  : 0x82F07708
// RVA : 0x00F07708
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::SetMaxLength(idFile_Memory *this, unsigned int len)
{
  unsigned int fileSize; // r29

  fileSize = this->fileSize;
  ((void (__fastcall *)(idFile_Memory *))this->SetLength)(a1: this);
  this->maxSize = len;
  this->fileSize = fileSize;
}


// ========================================================================
// ?MakeReadOnly@idFile_Memory@@QAAXXZ
// EA  : 0x82F07740
// RVA : 0x00F07740
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::MakeReadOnly(idFile_Memory *this)
{
  idFile_Memory_vtbl *v1; // r10

  v1 = this->__vftable;
  this->mode = 0;
  v1->Seek(this, a2: 0, a3: FS_SEEK_SET);
}


// ========================================================================
// ?MakeWritable@idFile_Memory@@QAAXXZ
// EA  : 0x82F07760
// RVA : 0x00F07760
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::MakeWritable(idFile_Memory *this)
{
  idFile_Memory_vtbl *v1; // r10

  v1 = this->__vftable;
  this->mode = 1;
  v1->Seek(this, a2: 0, a3: FS_SEEK_SET);
}


// ========================================================================
// ?Clear@idFile_Memory@@UAAX_N@Z
// EA  : 0x82F07780
// RVA : 0x00F07780
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::Clear(idFile_Memory *this, bool freeMemory)
{
  this->fileSize = 0;
  if ( freeMemory )
  {
    this->allocated = 0;
    idMem::Free(this: &mem, ptr: this->filePtr, align: ALIGN_16);
    this->filePtr = nullptr;
    this->curPtr = nullptr;
  }
  else
  {
    this->curPtr = this->filePtr;
  }
}


// ========================================================================
// ?Read@idFile_BitMsg@@UAAIPAXI@Z
// EA  : 0x82F077F0
// RVA : 0x00F077F0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_BitMsg::Read(idFile_BitMsg *this, void *buffer, int len)
{
  return idBitMsg::ReadData(this: this->msg, data: buffer, length: len);
}


// ========================================================================
// ?IsOpen@idFile_Permanent@@QAA_NXZ
// EA  : 0x82F077F8
// RVA : 0x00F077F8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

BOOL __fastcall idFile_Permanent::IsOpen(idFile_Permanent *this)
{
  return this->handle != (void *)-1;
}


// ========================================================================
// ?ForceFlush@idFile_Permanent@@UAAXXZ
// EA  : 0x82F07810
// RVA : 0x00F07810
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Permanent::ForceFlush(idFile_Permanent *this)
{
  FlushFileBuffers(hFile: this->handle);
}


// ========================================================================
// ?Flush@idFile_Permanent@@UAAXXZ
// EA  : 0x82F07818
// RVA : 0x00F07818
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Permanent::Flush(idFile_Permanent *this)
{
  FlushFileBuffers(hFile: this->handle);
  GetFileSizeEx(hFile: this->handle, lpFileSize: (_LARGE_INTEGER *)&this->fileSize);
}


// ========================================================================
// ?Tell@idFile_Permanent@@UBA_JXZ
// EA  : 0x82F07858
// RVA : 0x00F07858
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

unsigned int __fastcall idFile_Permanent::Tell(idFile_Permanent *this)
{
  _LARGE_INTEGER v1; // r4
  unsigned int result; // r3
  bool v3; // zf
  _LARGE_INTEGER v4; // [sp+50h] [-10h] BYREF

  v1.LowPart = 0;
  v1.HighPart = (int)this->handle;
  v4 = v1;
  v3 = SetFilePointerEx(hFile: (void *)v1.HighPart, liDistanceToMove: nullptr, lpNewFilePointer: &v4, dwMoveMethod: 1u) != 0;
  result = v4.LowPart;
  if ( !v3 )
    return 0;
  return result;
}


// ========================================================================
// ?Length@idFile_Permanent@@UBA_JXZ
// EA  : 0x82F078A0
// RVA : 0x00F078A0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idFile_Permanent::Length(idFile_Permanent *this)
{
  __int64 result; // r4 OVERLAPPED

  *(__int64 *)((char *)&result + 4) = this->fileSize;
  return result;
}


// ========================================================================
// ?SetLength@idFile_Permanent@@UAAXI@Z
// EA  : 0x82F078A8
// RVA : 0x00F078A8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Permanent::SetLength(idFile_Permanent *this, unsigned int len)
{
  __int64 v2; // r30
  unsigned int LastError; // r3

  LODWORD(v2) = len;
  this->Seek(this, a2: len, a3: FS_SEEK_SET);
  if ( SetEndOfFile(hFile: this->handle) == 0 )
  {
    LastError = GetLastError();
    idLib::Warning(fmt: "Error: SetLength( %lld ) - %i", (_DWORD)v2, LastError);
  }
  this->fileSize = v2;
}


// ========================================================================
// ?Timestamp@idFile_Permanent@@UBAIXZ
// EA  : 0x82F07920
// RVA : 0x00F07920
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

unsigned int __fastcall idFile_Permanent::Timestamp(idFile_Permanent *this)
{
  unsigned int dwLowDateTime; // r31
  unsigned __int64 v2; // r9
  unsigned __int64 v3; // r11
  _FILETIME v5; // [sp+50h] [-40h] BYREF
  _FILETIME v6; // [sp+58h] [-38h] BYREF
  _FILETIME v7; // [sp+60h] [-30h] BYREF
  _FILETIME v8; // [sp+68h] [-28h] BYREF
  _SYSTEMTIME v9; // [sp+70h] [-20h] BYREF

  if ( GetFileTime(hFile: this->handle, lpCreationTime: &v8, lpLastAccessTime: &v7, lpLastWriteTime: &v5) == 0 )
    idLib::FatalError(fmt: "GetFileTime failed.");
  dwLowDateTime = v5.dwLowDateTime;
  v9.wDayOfWeek = 0;
  v9.wMonth = 1;
  v9.wYear = 1970;
  v9.wDay = 1;
  v9.wHour = 0;
  v9.wMinute = 0;
  v9.wSecond = 0;
  v9.wMilliseconds = 0;
  if ( SystemTimeToFileTime(lpSystemTime: &v9, lpFileTime: &v6) != 0 )
    LODWORD(v3) = dwLowDateTime - v6.dwLowDateTime;
  else
    LODWORD(v3) = dwLowDateTime + 717324288;
  HIDWORD(v3) = 9961472;
  LODWORD(v2) = 10000000;
  return v3 / v2;
}


// ========================================================================
// ??1idFileLocal@@QAA@XZ
// EA  : 0x82F079E8
// RVA : 0x00F079E8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFileLocal::~idFileLocal(idFileLocal *this)
{
  idFile *file; // r3

  file = this->file;
  if ( file != nullptr )
  {
    ((void (__fastcall *)(idFile *, int))file->dtr_idFile)(a1: file, a2: 1);
    this->file = nullptr;
  }
}


// ========================================================================
// ??1idFile_Memory@@UAA@XZ
// EA  : 0x82F07A40
// RVA : 0x00F07A40
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::~idFile_Memory(idFile_Memory *this)
{
  this->__vftable = (idFile_Memory_vtbl *)&idFile_Memory::`vftable';
  if ( this->ownsData )
    idMem::Free(this: &mem, ptr: this->filePtr, align: ALIGN_16);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_Memory_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$115424
// EA  : 0x82F07AB8
// RVA : 0x00F07AB8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115424()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$115425
// EA  : 0x82F07AE0
// RVA : 0x00F07AE0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115425()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?Read@idFile_Memory@@UAAIPAXI@Z
// EA  : 0x82F07B10
// RVA : 0x00F07B10
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

size_t __fastcall idFile_Memory::Read(idFile_Memory *this, void *buffer, size_t len)
{
  void *v4; // r3
  int mode; // r11
  char *filePtr; // r11
  unsigned int fileSize; // r10
  char *curPtr; // r4

  mode = this->mode;
  v4 = buffer;
  if ( mode != 0 )
    idLib::FatalError(fmt: "idFile_Memory::Read: %s not opened in read mode", this->name.data);
  filePtr = this->filePtr;
  fileSize = this->fileSize;
  curPtr = this->curPtr;
  if ( &curPtr[len] > &filePtr[fileSize] )
    len = (size_t)&filePtr[fileSize - (_DWORD)curPtr];
  memcpy(Dst: v4, Src: curPtr, Size: len);
  this->curPtr += len;
  return len;
}


// ========================================================================
// ?Write@idFile_Memory@@UAAIPBXI@Z
// EA  : 0x82F07BA0
// RVA : 0x00F07BA0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

size_t __fastcall idFile_Memory::Write(idFile_Memory *this, const void *buffer, size_t len)
{
  unsigned int allocated; // r11
  unsigned int v7; // r10
  unsigned int maxSize; // r4
  unsigned int v9; // r5
  unsigned int v10; // r8
  unsigned int v11; // r29
  char *v12; // r3
  size_t v13; // r5
  char *v14; // r30
  char *filePtr; // r4
  char *curPtr; // r11
  char *v17; // r8
  char *v18; // r11
  unsigned int fileSize; // r10

  if ( this->mode == 0 )
    idLib::FatalError(fmt: "idFile_Memory::Write: %s not opened in write mode", this->name.data);
  allocated = this->allocated;
  v7 = this->curPtr - this->filePtr + len + 1;
  if ( v7 > allocated )
  {
    maxSize = this->maxSize;
    if ( maxSize != 0 )
      idLib::FatalError(fmt: "idFile_Memory::Write: exceeded maximum size %d", maxSize);
    v9 = ((((v7 - 1) >> 1) | (v7 - 1)) >> 2) | ((v7 - 1) >> 1) | (v7 - 1);
    v10 = (((v9 >> 4) | v9) >> 8) | (v9 >> 4) | v9;
    v11 = (HIWORD(v10) | v10) + allocated + 1;
    if ( v11 <= 2 * allocated )
      v11 = 2 * allocated;
    v12 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\filesystem\\File.cpp(438) : TAG_FILE",
                    size: v11,
                    tag: TAG_FILE,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    v13 = this->allocated;
    v14 = v12;
    if ( v13 != 0 )
      memcpy(Dst: v12, Src: this->filePtr, Size: v13);
    filePtr = this->filePtr;
    curPtr = this->curPtr;
    this->allocated = v11;
    this->curPtr = &v14[curPtr - filePtr];
    if ( filePtr != nullptr )
      idMem::Free(this: &mem, ptr: filePtr, align: ALIGN_16);
    this->filePtr = v14;
  }
  memcpy(Dst: this->curPtr, Src: buffer, Size: len);
  v17 = this->filePtr;
  v18 = &this->curPtr[len];
  fileSize = this->fileSize;
  this->curPtr = v18;
  if ( fileSize <= v18 - v17 )
    fileSize = v18 - v17;
  this->fileSize = fileSize;
  v17[fileSize] = 0;
  return len;
}


// ========================================================================
// ?Seek@idFile_Memory@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x82F07D18
// RVA : 0x00F07D18
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Memory::Seek(idFile_Memory *this, char *a2, __int64 offset, fsOrigin_t origin)
{
  char *filePtr; // r11
  char *curPtr; // r10
  char *v6; // r10
  char *v7; // r11

  if ( HIDWORD(offset) == 0 )
  {
    curPtr = this->curPtr;
    filePtr = a2;
LABEL_8:
    this->curPtr = &curPtr[(_DWORD)filePtr];
    goto LABEL_9;
  }
  if ( HIDWORD(offset) != 1 )
  {
    if ( HIDWORD(offset) >= 3 )
    {
      idLib::FatalError(fmt: "idFile_Memory::Seek: bad origin for %s\n", this->name.data);
      return;
    }
    filePtr = this->filePtr;
    curPtr = a2;
    goto LABEL_8;
  }
  this->curPtr = (char *)(&this->filePtr[this->fileSize] - a2);
LABEL_9:
  v6 = this->curPtr;
  v7 = this->filePtr;
  if ( v6 < v7 || (v7 += this->fileSize, v6 > v7) )
    this->curPtr = v7;
}


// ========================================================================
// ?AtomicWrite@idFile_Memory@@QBA_NQBDW4fsPath_t@@@Z
// EA  : 0x82F07DB0
// RVA : 0x00F07DB0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_Memory::AtomicWrite(idFile_Memory *this, const char *relativePath, fsPath_t basePath)
{
  __int64 ClockTicks; // r4
  idFile *v7; // r29
  idFile_vtbl *v9; // r25
  char *filePtr; // r24
  unsigned int v11; // r3
  int v12; // r25
  idFile_Memory *v13; // r3
  char *data; // r30
  __int64 (__fastcall *Length)(struct idFile_Memory *); // ctr
  int v16; // r3
  idStr v17[3]; // [sp+50h] [-70h] BYREF

  v17[0].len = 0;
  v17[0].allocedAndFlag = 20;
  v17[0].data = v17[0].baseBuffer;
  v17[0].baseBuffer[0] = 0;
  ClockTicks = Sys_GetClockTicks();
  idStr::Format(this: v17, fmt: "%s.%4X.tmp", relativePath, WORD1(ClockTicks));
  v7 = fileSystem->OpenFileWritePermanent(this: fileSystem, a2: v17[0].data, a3: basePath);
  if ( v7 != nullptr )
  {
    v9 = v7->__vftable;
    filePtr = this->filePtr;
    v11 = this->Length(this);
    v12 = v9->Write(this: v7, a2: filePtr, a3: v11);
    ((void (__fastcall *)(idFile *, int))v7->dtr_idFile)(a1: v7, a2: 1);
    if ( v12 == (int)this->Length(this) )
    {
      fileSystem->RemoveFile(this: fileSystem, a2: relativePath, a3: basePath);
      if ( fileSystem->RenameFile(this: fileSystem, a2: v17[0].data, a3: relativePath, a4: basePath) )
      {
        idStr::FreeData(this: v17);
        return 1;
      }
      else
      {
        idLib::Warning(fmt: "Failed to rename %s to %s", v17[0].data, relativePath);
        idStr::FreeData(this: v17);
        return 0;
      }
    }
    else
    {
      v13 = this;
      Length = this->Length;
      data = v17[0].data;
      v16 = Length(this: v13);
      idLib::Warning(fmt: "Only wrote %i of %i bytes to %s", v12, v16, data);
      idStr::FreeData(this: v17);
      return 0;
    }
  }
  else
  {
    idStr::FreeData(this: v17);
    return 0;
  }
}


// ========================================================================
// __unwind$115547
// EA  : 0x82F07F70
// RVA : 0x00F07F70
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115547()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ??0idFile_BitMsg@@QAA@AAVidBitMsg@@@Z
// EA  : 0x82F07FA0
// RVA : 0x00F07FA0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

idFile_BitMsg *__fastcall idFile_BitMsg::idFile_BitMsg(idFile_BitMsg *this, idBitMsg *msg)
{
  this->__vftable = (idFile_BitMsg_vtbl *)&idFile::`vftable';
  this->uniqID = Sys_InterlockedAdd(value: &atomicUniqID, i: 1);
  this->__vftable = (idFile_BitMsg_vtbl *)&idFile_BitMsg::`vftable';
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  idStr::operator=(this: &this->name, text: "*bitmsg*");
  this->msg = msg;
  this->mode = 2;
  return this;
}


// ========================================================================
// __unwind$115625
// EA  : 0x82F08030
// RVA : 0x00F08030
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115625()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$115626
// EA  : 0x82F08058
// RVA : 0x00F08058
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115626()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ?Write@idFile_BitMsg@@UAAIPBXI@Z
// EA  : 0x82F08088
// RVA : 0x00F08088
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_BitMsg::Write(idFile_BitMsg *this, const void *buffer, int len)
{
  if ( this->mode == 0 )
    idLib::FatalError(fmt: "idFile_Memory::Write: %s not opened in write mode", this->name.data);
  idBitMsg::WriteData(this: this->msg, data: buffer, length: len);
  return len;
}


// ========================================================================
// ?Length@idFile_BitMsg@@UBA_JXZ
// EA  : 0x82F080E0
// RVA : 0x00F080E0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_BitMsg::Length(idFile_BitMsg *this)
{
  return (this->msg->writeBit != 0) + this->msg->curSize;
}


// ========================================================================
// ?Tell@idFile_BitMsg@@UBA_JXZ
// EA  : 0x82F08100
// RVA : 0x00F08100
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_BitMsg::Tell(idFile_BitMsg *this)
{
  idBitMsg *msg; // r11

  msg = this->msg;
  if ( this->mode != 0 )
    return (msg->writeBit != 0) + msg->curSize;
  else
    return msg->readCount;
}


// ========================================================================
// ??0idFile_Permanent@@QAA@PBD0W4fsMode_t@@_N@Z
// EA  : 0x82F08140
// RVA : 0x00F08140
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

idFile_Permanent *__fastcall idFile_Permanent::idFile_Permanent(
        idFile_Permanent *this,
        const char *relativePath,
        const char *osPath,
        fsMode_t m,
        bool create)
{
  char *v10; // r3
  char v11; // r11
  char v12; // r28
  fsMode_t mode; // r11
  unsigned int v14; // r5
  unsigned int v15; // r8
  unsigned int v16; // r4
  unsigned int v17; // r7
  char *data; // r3
  void *UncachedFileA; // r3
  int v20; // r3
  int v21; // r11
  idStr *v22; // r11
  fsDevice_t device; // r11
  int v25; // r6
  int v26; // r5
  int v27; // r4
  int v28; // r3
  idStr *p_fullPath; // [sp+50h] [-80h] BYREF
  idStr v30[3]; // [sp+60h] [-70h] BYREF

  this->__vftable = (idFile_Permanent_vtbl *)&idFile::`vftable';
  this->uniqID = Sys_InterlockedAdd(value: &atomicUniqID, i: 1);
  this->__vftable = (idFile_Permanent_vtbl *)&idFile_Permanent::`vftable';
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->fullPath.allocedAndFlag = 20;
  this->fullPath.len = 0;
  p_fullPath = &this->fullPath;
  this->fullPath.data = this->fullPath.baseBuffer;
  this->fullPath.baseBuffer[0] = 0;
  idStr::operator=(this: &this->name, text: relativePath);
  idStr::operator=(this: &this->fullPath, text: osPath);
  this->mode = m;
  this->device = FS_DEVICE_HARD_DISK_DRIVE;
  this->sectorSize = 1;
  if ( *fs_cachepath.valueString.data == 0
    || (v10 = strstr(str1: osPath, str2: fs_cachepath.valueString.data), v11 = 1, v10 == nullptr) )
  {
    v11 = 0;
  }
  v12 = v11;
  idStr::SlashesToBackSlashes(this: &this->fullPath);
  mode = this->mode;
  v14 = 0;
  v15 = 0;
  if ( (unsigned int)mode <= FS_APPEND )
  {
    switch ( mode )
    {
      case FS_WRITE:
        v16 = 0x40000000;
        v17 = 2;
LABEL_16:
        data = this->fullPath.data;
        if ( v12 != 0 )
          UncachedFileA = XFileCacheCreateUncachedFileA(
                            lpFileName: data,
                            dwDesiredAccess: v16,
                            dwShareMode: v14,
                            lpSecurityAttributes: nullptr,
                            dwCreationDisposition: v17,
                            dwFlagsAndAttributes: v15,
                            hTemplateFile: nullptr);
        else
          UncachedFileA = CreateFileA(
                            lpFileName: data,
                            dwDesiredAccess: v16,
                            dwShareMode: v14,
                            lpSecurityAttributes: nullptr,
                            dwCreationDisposition: v17,
                            dwFlagsAndAttributes: v15,
                            hTemplateFile: nullptr);
        this->handle = UncachedFileA;
        if ( UncachedFileA == (void *)-1 )
          return this;
        GetFileSizeEx(hFile: UncachedFileA, lpFileSize: (_LARGE_INTEGER *)&this->fileSize);
        if ( this->mode == FS_APPEND )
          SetFilePointer(hFile: this->handle, lDistanceToMove: 0, lpDistanceToMoveHigh: nullptr, dwMoveMethod: 2u);
        if ( this->mode != FS_READ_NO_BUFFERING && idLib::production != PROD_PRODUCTION )
          return this;
        v20 = idStr::Find(
                searchIn: this->fullPath.data,
                searchFor: ":\\",
                casesensitive: true,
                start: 0,
                end: this->fullPath.len);
        p_fullPath = &this->fullPath;
        idStr::Left(this: v30, result: &this->fullPath, len: v20);
        if ( idStr::Icmp(s1: v30[0].data, s2: "CACHE") == 0 )
        {
          v21 = 512;
          this->device = FS_DEVICE_HARD_DISK_DRIVE;
          goto LABEL_40;
        }
        p_fullPath = nullptr;
        if ( XContentQueryVolumeDeviceType(
               pszRootName: v30[0].data,
               pDeviceType: (unsigned int *)&p_fullPath,
               pOverlapped: nullptr) != 0 )
        {
          if ( idStr::Cmp(s1: v30[0].data, s2: "GAME") != 0 )
          {
            if ( idStr::Cmpn(s1: v30[0].data, s2: "DLC", n: 3) == 0
              && idStr::IsNumeric(s: (const char *)v30[0].data + 3) )
            {
              v21 = 512;
              this->device = FS_DEVICE_HARD_DISK_DRIVE;
              goto LABEL_40;
            }
          }
          else if ( fileBenchmarkImpliesGameIsOnHD )
          {
            v21 = 512;
            this->device = FS_DEVICE_HARD_DISK_DRIVE;
            goto LABEL_40;
          }
        }
        else
        {
          v22 = p_fullPath;
          if ( p_fullPath != (idStr *)4 )
          {
            if ( p_fullPath != (idStr *)1 )
            {
              this->sectorSize = 512;
              if ( v22 == (idStr *)2 )
                this->device = FS_DEVICE_SOLID_STATE_DRIVE;
              else
                this->device = FS_DEVICE_HARD_DISK_DRIVE;
LABEL_41:
              device = this->device;
              if ( device == FS_DEVICE_OPTICAL_DISK_DRIVE )
              {
                idLib::Printf(fmt: "ODD: opened %s\n", this->fullPath.data);
              }
              else if ( device != FS_DEVICE_HARD_DISK_DRIVE )
              {
                if ( device == FS_DEVICE_SOLID_STATE_DRIVE )
                {
                  idLib::Printf(fmt: "SSD: opened %s\n", this->fullPath.data);
                }
                else if ( device == FS_DEVICE_MEMORY )
                {
                  idLib::Printf(fmt: "MEM: opened %s\n", this->fullPath.data);
                }
              }
              else
              {
                idLib::Printf(fmt: "HDD: opened %s\n", this->fullPath.data);
              }
              idStr::FreeData(this: v30);
              return this;
            }
            v21 = 512;
            this->device = FS_DEVICE_HARD_DISK_DRIVE;
LABEL_40:
            this->sectorSize = v21;
            goto LABEL_41;
          }
        }
        v21 = 2048;
        this->device = FS_DEVICE_OPTICAL_DISK_DRIVE;
        goto LABEL_40;
      case FS_READ_WRITE:
        v16 = -1073741824;
        v14 = 3;
        v17 = ((_cntlzw(create) & 0x20) == 0) + 3;
        if ( v12 != 0 )
        {
          v15 = 1610612864;
          goto LABEL_16;
        }
        break;
      case FS_READ_NO_BUFFERING:
        v16 = 0x80000000;
        v14 = 3;
        v17 = 3;
        v15 = 1610612864;
        goto LABEL_16;
      case FS_READ:
        v16 = 0x80000000;
        v14 = 3;
        v17 = 3;
        v15 = 134217856;
        goto LABEL_16;
      default:
        v16 = 4;
        v14 = 7;
        v17 = 4;
        break;
    }
    v15 = 128;
    goto LABEL_16;
  }
  idLib::FatalError(fmt: "Invalid file open mode");
  return _LN131_0(a1: v28, a2: v27, a3: v26, a4: v25);
}


// ========================================================================
// $LN131_0
// EA  : 0x82F08504
// RVA : 0x00F08504
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _LN131_0()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 208 + 228));
}


// ========================================================================
// __unwind$115801
// EA  : 0x82F0852C
// RVA : 0x00F0852C
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115801()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 208 + 228) + 8));
}


// ========================================================================
// __unwind$115802
// EA  : 0x82F08558
// RVA : 0x00F08558
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115802()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 208 + 228) + 40));
}


// ========================================================================
// __unwind$115803
// EA  : 0x82F08584
// RVA : 0x00F08584
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115803()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ??1idFile_Permanent@@UAA@XZ
// EA  : 0x82F085C8
// RVA : 0x00F085C8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_Permanent::~idFile_Permanent(idFile_Permanent *this)
{
  void *handle; // r3

  this->__vftable = (idFile_Permanent_vtbl *)&idFile_Permanent::`vftable';
  handle = this->handle;
  if ( handle != (void *)-1 )
    CloseHandle(hObject: handle);
  idStr::FreeData(this: &this->fullPath);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_Permanent_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$115990
// EA  : 0x82F08638
// RVA : 0x00F08638
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115990()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$115991
// EA  : 0x82F08660
// RVA : 0x00F08660
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_115991()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?WriteOfs@idFile_Permanent@@UAAI_JPBXI@Z
// EA  : 0x82F08690
// RVA : 0x00F08690
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall idFile_Permanent::WriteOfs(
        idFile_Permanent *this,
        int a2,
        __int64 offset,
        const void *buffer,
        unsigned int len)
{
  const void *v6; // r30
  unsigned int v7; // r29
  __int64 v9; // r11
  void *handle; // r3
  unsigned int LastError; // r3
  unsigned int v12; // r3
  unsigned int v13[4]; // [sp+50h] [-50h] BYREF
  _OVERLAPPED v14[3]; // [sp+60h] [-40h] BYREF
  __int64 v15; // [sp+B8h] [+18h]

  v15 = *(_QWORD *)(&this - 1);
  v6 = (const void *)HIDWORD(offset);
  v7 = offset;
  if ( fs_noOverlappedIO.valueInteger != 0 )
  {
    ((void (__fastcall *)(idFile_Permanent *))this->Seek)(a1: this);
    return this->Write(this, a2: v6, a3: v7);
  }
  HIDWORD(v9) = v14;
  LODWORD(v9) = 0;
  handle = this->handle;
  *(_QWORD *)HIDWORD(v9) = v9;
  *(_QWORD *)(HIDWORD(v9) + 8) = v9;
  v14[0].OffsetHigh = HIDWORD(v15);
  v14[0].Offset = v15;
  v14[0].hEvent = nullptr;
  if ( WriteFile(
         hFile: handle,
         lpBuffer: (const void *)HIDWORD(offset),
         nNumberOfBytesToWrite: offset,
         lpNumberOfBytesWritten: v13,
         lpOverlapped: v14) != 0 )
    return v13[0];
  LastError = GetLastError();
  if ( LastError != 0 )
  {
    if ( LastError == 997 )
    {
      if ( GetOverlappedResult(hFile: this->handle, lpOverlapped: v14, lpNumberOfBytesTransferred: v13, bWait: 1) == 0 )
      {
        v12 = GetLastError();
        idLib::Warning(fmt: "WriteOfs GetOverlappedResult: error %i", v12);
        return 0;
      }
    }
    else
    {
      idLib::Warning(fmt: "WriteOfs: error %i", LastError);
    }
  }
  return 0;
}


// ========================================================================
// ?Read@idFile_Permanent@@UAAIPAXI@Z
// EA  : 0x82F087B8
// RVA : 0x00F087B8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_Permanent::Read(idFile_Permanent *this, char *buffer, unsigned int len)
{
  fsMode_t mode; // r11
  const char *v7; // r3
  const char *v8; // r3
  __int64 v10; // r10
  int valueInteger; // r11
  const char *v12; // r3
  int v13; // r31
  int v14; // r27
  unsigned int v15; // r5
  unsigned int LastError; // r30
  const char *v17; // r3
  const char *v18; // r3
  unsigned int v19; // [sp+50h] [-60h] BYREF

  if ( len != 0 )
  {
    mode = this->mode;
    if ( mode != FS_READ && mode != FS_READ_WRITE && mode != FS_READ_NO_BUFFERING )
    {
      v7 = this->GetName(this);
      idLib::FatalError(fmt: "idFile_Permanent::Read: %s not opened in read mode", v7);
    }
    if ( this->handle == (void *)-1 )
    {
      v8 = this->GetName(this);
      idLib::Warning(fmt: "Tried to read from an unopened file: %s", v8);
      return 0;
    }
    HIDWORD(v10) = allocationCurrent[242];
    LODWORD(v10) = HIDWORD(totalFileReadCount) + totalFileReadCount;
    valueInteger = fs_reportReads.valueInteger;
    *(_QWORD *)(HIDWORD(v10) - 23848) = v10;
    if ( valueInteger != 0 )
    {
      v12 = this->GetName(this);
      idLib::Printf(fmt: "Read( %s, %i )\n", v12, len);
    }
    v13 = 0;
    v14 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v15 = len - v13;
        if ( len - v13 > 0x1000000 )
          v15 = 0x1000000;
        v19 = 0;
        if ( ReadFile(
               hFile: this->handle,
               lpBuffer: &buffer[v13],
               nNumberOfBytesToRead: v15,
               lpNumberOfBytesRead: &v19,
               lpOverlapped: nullptr) == 0 )
          break;
        v13 += v19;
        if ( v13 == len || v19 == 0 )
          return v13;
      }
      LastError = GetLastError();
      if ( LastError == 38 )
        return v13;
      v17 = this->GetFullPath(this);
      idLib::Printf(fmt: "ReadFile returned %d on %s\n", LastError, v17);
      if ( ++v14 == 3 )
        break;
      Sleep(dwMilliseconds: 0xAu);
    }
    v18 = this->GetFullPath(this);
    idLib::Printf(fmt: "ReadFile error %i on %s, %i bytes 3 times, failing load...", LastError, v18, len);
  }
  return 0;
}


// ========================================================================
// ?Write@idFile_Permanent@@UAAIPBXI@Z
// EA  : 0x82F08990
// RVA : 0x00F08990
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall idFile_Permanent::Write(idFile_Permanent *this, char *buffer, unsigned int len)
{
  fsMode_t mode; // r11
  const char *v7; // r3
  unsigned int v9; // r31
  unsigned int v10; // r5
  __int64 fileSize; // r10
  bool v12; // cr58
  unsigned int LastError; // r29
  const char *v14; // r31
  unsigned int v15; // r3
  fsOrigin_t v16; // r7
  __int64 v17; // r6
  idFile_Permanent *v18; // r3
  unsigned int v19; // [sp+50h] [-50h] BYREF

  mode = this->mode;
  if ( mode != FS_READ && mode != FS_READ_NO_BUFFERING )
  {
    if ( this->handle == (void *)-1 )
    {
      v7 = this->GetName(this);
      idLib::Warning(fmt: "Tried to write to an unopened file: %s", v7);
      return 0;
    }
    v9 = 0;
    if ( len == 0 )
      return v9;
    while ( 1 )
    {
      v10 = len - v9;
      if ( len - v9 > 0x1000000 )
        v10 = 0x1000000;
      v19 = 0;
      if ( WriteFile(
             hFile: this->handle,
             lpBuffer: &buffer[v9],
             nNumberOfBytesToWrite: v10,
             lpNumberOfBytesWritten: &v19,
             lpOverlapped: nullptr) == 1 )
      {
        fileSize = this->fileSize;
        v9 += v19;
        LODWORD(fileSize) = v19 + fileSize;
        v12 = v19 == 0;
        this->fileSize = fileSize;
        if ( v12 )
          return v9;
      }
      else
      {
        LastError = GetLastError();
        if ( LastError != 0 )
        {
          v14 = this->GetName(this);
          v15 = GetLastError();
          idLib::Warning(fmt: "WriteFile returned %d on %s", v15, v14);
          return (LastError != 112) - 1;
        }
      }
      if ( v9 >= len )
        return v9;
    }
  }
  idLib::FatalError(fmt: "idFile_Permanent::Write: %s not opened in write mode", this->name.data);
  return idFile_Permanent::Seek(this: v18, offset: v17, origin: v16);
}


// ========================================================================
// ?Seek@idFile_Permanent@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x82F08AE0
// RVA : 0x00F08AE0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

BOOL __fastcall idFile_Permanent::Seek(idFile_Permanent *this, _LARGE_INTEGER *a2, __int64 offset, fsOrigin_t origin)
{
  void *handle; // r3
  unsigned int v6; // r30
  unsigned int LastError; // r29
  const char *v8; // r3
  _DWORD v10[12]; // [sp+50h] [-30h] BYREF

  if ( HIDWORD(offset) > 2 )
  {
    idLib::FatalError(fmt: "idFile_Permanent::Seek: bad origin for %s\n", this->name.data);
    JUMPOUT(0x82F08BA0);
  }
  handle = this->handle;
  v10[0] = 1;
  v10[1] = 2;
  v10[2] = 0;
  v6 = SetFilePointerEx(
         hFile: handle,
         liDistanceToMove: a2,
         lpNewFilePointer: nullptr,
         dwMoveMethod: v10[HIDWORD(offset)]);
  if ( v6 == 0 && fs_debug.valueInteger != 0 )
  {
    LastError = GetLastError();
    v8 = this->GetName(this);
    idLib::Printf(fmt: "SetFilePointerEx error %s: %d\n", v8, LastError);
  }
  return (_cntlzw(v6) & 0x20) != 0;
}


// ========================================================================
// ??1idFile_AtomicWrite@@UAA@XZ
// EA  : 0x82F08BA8
// RVA : 0x00F08BA8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __fastcall idFile_AtomicWrite::~idFile_AtomicWrite(idFile_AtomicWrite *this)
{
  this->__vftable = (idFile_AtomicWrite_vtbl *)&idFile_AtomicWrite::`vftable';
  idFile_Memory::AtomicWrite(this, relativePath: this->writeName.data, basePath: this->basePath);
  idStr::FreeData(this: &this->osPath);
  idStr::FreeData(this: &this->writeName);
  idFile_Memory::~idFile_Memory(this);
}


// ========================================================================
// __unwind$116091
// EA  : 0x82F08C10
// RVA : 0x00F08C10
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116091()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: *(idFile_Memory **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$116092
// EA  : 0x82F08C38
// RVA : 0x00F08C38
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116092()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 332));
}


// ========================================================================
// __unwind$116093
// EA  : 0x82F08C64
// RVA : 0x00F08C64
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116093()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 368));
}


// ========================================================================
// ?FS_WriteFloatString@@YAHPADPBD0@Z
// EA  : 0x82F08D38
// RVA : 0x00F08D38
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

int __fastcall FS_WriteFloatString(char *buf, const char *fmt, char *argPtr)
{
  const char *v4; // r26
  char v6; // r27
  int v7; // r28
  int v8; // r5
  unsigned __int8 *v9; // r26
  unsigned int v10; // r10
  int v11; // r10
  int v12; // r11
  char v13; // r30
  char *v14; // r29
  char v15; // r30
  int v16; // r11
  int v17; // r10
  int v18; // r11
  int v19; // r10
  unsigned int v20; // r11
  unsigned int v21; // r11
  double v22; // fp1
  int v23; // r3
  unsigned int v24; // r11
  int v25; // r5
  idStr v27; // [sp+60h] [-E0h] BYREF
  idStr v28; // [sp+80h] [-C0h] BYREF

  v28.len = 0;
  v28.baseBuffer[0] = 0;
  v4 = fmt;
  v28.allocedAndFlag = 20;
  v28.data = v28.baseBuffer;
  v27.len = 0;
  v27.baseBuffer[0] = 0;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v6 = *fmt;
  v7 = 0;
  v8 = *fmt;
  if ( *fmt == 0 )
  {
LABEL_58:
    idStr::FreeData(this: &v27);
    idStr::FreeData(this: &v28);
    return v7;
  }
  while ( 1 )
  {
    if ( v6 == 37 )
    {
      idStr::operator=(this: &v27, text: &byte_8200D768);
      v12 = v27.len + 2;
      v13 = *v4;
      v11 = v27.allocedAndFlag & 0x7FFFFFFF;
      if ( v27.allocedAndFlag >= 0 )
      {
        if ( v12 > v11 )
          idStr::ReAllocate(this: &v27, amount: (v12 >> 1) + v12, keepold: true);
      }
      else if ( v12 > v11
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      v14 = (char *)(v4 + 1);
      v27.data[v27.len++] = v13;
      for ( v27.data[v27.len] = 0; ; v27.data[v27.len] = 0 )
      {
        v15 = *v14;
        if ( (*v14 < 48 || v15 > 57) && v15 != 46 && v15 != 45 && v15 != 43 && v15 != 35 )
          break;
        v16 = v27.len + 2;
        v17 = v27.allocedAndFlag & 0x7FFFFFFF;
        if ( v27.allocedAndFlag >= 0 )
        {
          if ( v16 > v17 )
            idStr::ReAllocate(this: &v27, amount: (v16 >> 1) + v16, keepold: true);
        }
        else if ( v16 > v17
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        ++v14;
        v27.data[v27.len++] = v15;
      }
      v18 = v27.len + 2;
      v19 = v27.allocedAndFlag & 0x7FFFFFFF;
      if ( v27.allocedAndFlag >= 0 )
      {
        if ( v18 > v19 )
          idStr::ReAllocate(this: &v27, amount: (v18 >> 1) + v18, keepold: true);
      }
      else if ( v18 > v19
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      v27.data[v27.len++] = v15;
      v27.data[v27.len] = 0;
      v20 = (unsigned __int8)*v14;
      if ( v20 > 0x67 )
      {
        switch ( *v14 )
        {
          case 'i':
          case 'o':
          case 's':
          case 'u':
          case 'x':
            goto LABEL_54;
          default:
            goto _LN188_0;
        }
      }
      if ( v20 >= 0x65 )
      {
LABEL_47:
        v21 = (unsigned int)(argPtr + 7) & 0xFFFFFFF8;
        argPtr = (char *)(v21 + 8);
        v22 = *(double *)v21;
        if ( __fabs((float)*(double *)v21) < idMath::FLT_SMALLEST_NON_DENORMAL )
          v22 = 0.0;
        if ( v27.len > 2 )
        {
          v23 = sprintf_0(string: &buf[v7], format: v27.data, LODWORD(v22));
        }
        else
        {
          idStr::Format(this: &v28, fmt: (const char *)HIDWORD(v22), LODWORD(v22));
          idStr::StripTrailing(this: &v28, c: 48);
          idStr::StripTrailing(this: &v28, c: 46);
          v23 = sprintf_0(string: &buf[v7], format: "%s", v28.data);
        }
        goto LABEL_56;
      }
      if ( v20 > 0x58 )
      {
        if ( v20 == 99 )
        {
          v24 = (unsigned int)(argPtr + 7) & 0xFFFFFFF8;
          v25 = (char)*(_DWORD *)(v24 + 4);
          goto LABEL_55;
        }
        if ( v20 != 100 )
          goto _LN188_0;
      }
      else if ( v20 != 88 )
      {
        if ( v20 != 37 )
        {
          if ( v20 != 69 && v20 != 71 )
            goto _LN188_0;
          goto LABEL_47;
        }
        v23 = sprintf_0(string: &buf[v7], format: v27.data);
LABEL_56:
        v7 += v23;
        v4 = v14 + 1;
        goto LABEL_57;
      }
LABEL_54:
      v24 = (unsigned int)(argPtr + 7) & 0xFFFFFFF8;
      v25 = *(_DWORD *)(v24 + 4);
LABEL_55:
      argPtr = (char *)(v24 + 8);
      v23 = sprintf_0(string: &buf[v7], format: v27.data, v25);
      goto LABEL_56;
    }
    if ( v6 != 92 )
    {
      v7 += sprintf_0(string: &buf[v7], format: "%c", v8);
      ++v4;
      goto LABEL_57;
    }
    v9 = (unsigned __int8 *)(v4 + 1);
    v10 = *v9;
    if ( v10 > 0x74 )
      break;
    switch ( v10 )
    {
      case 't':
        v7 += sprintf_0(string: &buf[v7], format: "\t");
        v4 = (const char *)(v9 + 1);
        break;
      case '\\':
        v7 += sprintf_0(string: &buf[v7], format: "\\");
        v4 = (const char *)(v9 + 1);
        break;
      case 'n':
        v7 += sprintf_0(string: &buf[v7], format: "\n");
        v4 = (const char *)(v9 + 1);
        break;
      default:
        goto LABEL_62;
    }
LABEL_57:
    v6 = *v4;
    v8 = *v4;
    if ( *v4 == 0 )
      goto LABEL_58;
  }
  if ( v10 == 118 )
  {
    v7 += sprintf_0(string: &buf[v7], format: "\v");
    v4 = (const char *)(v9 + 1);
    goto LABEL_57;
  }
LABEL_62:
  idLib::Error(fmt: "FS_WriteFloatString: unknown escape character '%c'", (char)v10);
_LN188_0:
  idLib::Error(fmt: "FS_WriteFloatString: invalid format %s", v27.data);
  return _LN189_0();
}


// ========================================================================
// $LN189_0
// EA  : 0x82F09284
// RVA : 0x00F09284
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _LN189_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$116309
// EA  : 0x82F092AC
// RVA : 0x00F092AC
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 96));
}


// ========================================================================
// ?Printf@idFile@@UAAIPBDZZ
// EA  : 0x82F092E0
// RVA : 0x00F092E0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int idFile::Printf(
        idFile *this,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  unsigned int v12; // r30
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  int v20; // r4
  int v21; // r3
  idStr v22; // [sp+60h] [-1040h] BYREF
  char v23[32]; // [sp+80h] [-1020h] BYREF
  __int64 v25; // [sp+10C0h] [+20h] BYREF
  va_list va; // [sp+10C0h] [+20h]
  __int64 v27; // [sp+10C8h] [+28h]
  __int64 v28; // [sp+10D0h] [+30h]
  __int64 v29; // [sp+10D8h] [+38h]
  __int64 v30; // [sp+10E0h] [+40h]
  __int64 v31; // [sp+10E8h] [+48h]
  va_list va1; // [sp+10F0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v25 = *(__int64 *)((char *)&a3 + 4);
  v27 = a3;
  v28 = *(__int64 *)((char *)&a4 + 4);
  v29 = a4;
  v30 = *(__int64 *)((char *)&a5 + 4);
  v31 = a5;
  if ( (unsigned int)idStr::vsnPrintf(dest: v23, size: 4096, fmt, argptr: va) >= 0x1000 )
  {
    idLib::FatalError(fmt: "idFile::Printf: string too long or format failed.");
    return _LN19_7(
             a1: v21,
             a2: v20,
             a3: v19,
             a4: v18,
             a5: v17,
             a6: v16,
             a7: v15,
             a8: v14,
             a9: a6,
             a10: a7,
             a11: a8,
             a12: a9,
             a13: a10,
             a14: fmt,
             a15: HIDWORD(v25),
             a16: v25,
             a17: HIDWORD(v27),
             a18: v27);
  }
  else
  {
    idStr::idStr(this: &v22, text: v23);
    idStr::Replace(this: &v22, old: "\n", nw: "\r\n");
    v12 = this->Write(this, a2: v22.data, a3: v22.len);
    idStr::FreeData(this: &v22);
    return v12;
  }
}


// ========================================================================
// $LN19_7
// EA  : 0x82F093C0
// RVA : 0x00F093C0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _LN19_7()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 96));
}


// ========================================================================
// ?WriteFloatString@idFile@@UAAIPBDZZ
// EA  : 0x82F093E8
// RVA : 0x00F093E8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int idFile::WriteFloatString(
        idFile *this,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  signed int v12; // r5
  char v14[16]; // [sp+60h] [-1010h] BYREF
  __int64 v15; // [sp+1090h] [+20h] BYREF
  va_list va; // [sp+1090h] [+20h]
  __int64 v17; // [sp+1098h] [+28h]
  __int64 v18; // [sp+10A0h] [+30h]
  __int64 v19; // [sp+10A8h] [+38h]
  __int64 v20; // [sp+10B0h] [+40h]
  __int64 v21; // [sp+10B8h] [+48h]
  va_list va1; // [sp+10C0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v15 = *(__int64 *)((char *)&a3 + 4);
  v17 = a3;
  v18 = *(__int64 *)((char *)&a4 + 4);
  v19 = a4;
  v20 = *(__int64 *)((char *)&a5 + 4);
  v21 = a5;
  v12 = FS_WriteFloatString(buf: v14, fmt, argPtr: va);
  if ( v12 >= 4096 )
    idLib::FatalError(fmt: "idFile::WriteFloatString: string too long.");
  return this->Write(this, a2: v14, a3: v12);
}


// ========================================================================
// ??0idFile_Memory@@QAA@XZ
// EA  : 0x82F09480
// RVA : 0x00F09480
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

idFile_Memory *__fastcall idFile_Memory::idFile_Memory(idFile_Memory *this)
{
  char *data; // r3
  size_t v3; // r5
  char *v4; // r4
  idStrStatic<260> v6; // [sp+60h] [-150h] BYREF

  this->__vftable = (idFile_Memory_vtbl *)&idFile::`vftable';
  this->uniqID = Sys_InterlockedAdd(value: &atomicUniqID, i: 1);
  this->__vftable = (idFile_Memory_vtbl *)&idFile_Memory::`vftable';
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->name.data = this->name.buffer;
  this->name.buffer[0] = 0;
  this->name.len = 0;
  this->name.allocedAndFlag = -2147483388;
  idStrStatic<260>::idStrStatic<260>(this: &v6, text: "*unknown*");
  data = this->name.data;
  v3 = v6.len + 1;
  v4 = v6.data;
  this->name.len = v6.len;
  memcpy(Dst: data, Src: v4, Size: v3);
  idStr::FreeData(this: &v6);
  this->maxSize = 0;
  this->fileSize = 0;
  this->allocated = 0;
  this->mode = 1;
  this->filePtr = nullptr;
  this->curPtr = nullptr;
  this->ownsData = true;
  return this;
}


// ========================================================================
// __unwind$116683
// EA  : 0x82F09558
// RVA : 0x00F09558
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116683()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 432 + 452));
}


// ========================================================================
// __unwind$116684
// EA  : 0x82F09580
// RVA : 0x00F09580
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116684()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 432 + 452) + 8));
}


// ========================================================================
// ??0idFile_Memory@@QAA@PBD@Z
// EA  : 0x82F095B8
// RVA : 0x00F095B8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

idFile_Memory *__fastcall idFile_Memory::idFile_Memory(idFile_Memory *this, const char *name)
{
  char *data; // r3
  size_t v5; // r5
  char *v6; // r4
  idStrStatic<260> v8; // [sp+60h] [-160h] BYREF

  this->__vftable = (idFile_Memory_vtbl *)&idFile::`vftable';
  this->uniqID = Sys_InterlockedAdd(value: &atomicUniqID, i: 1);
  this->__vftable = (idFile_Memory_vtbl *)&idFile_Memory::`vftable';
  this->name.allocedAndFlag = 20;
  this->name.baseBuffer[0] = 0;
  this->name.data = this->name.buffer;
  this->name.buffer[0] = 0;
  this->name.len = 0;
  this->name.allocedAndFlag = -2147483388;
  idStrStatic<260>::idStrStatic<260>(this: &v8, text: name);
  data = this->name.data;
  v5 = v8.len + 1;
  v6 = v8.data;
  this->name.len = v8.len;
  memcpy(Dst: data, Src: v6, Size: v5);
  idStr::FreeData(this: &v8);
  this->maxSize = 0;
  this->fileSize = 0;
  this->allocated = 0;
  this->mode = 1;
  this->filePtr = nullptr;
  this->curPtr = nullptr;
  this->ownsData = true;
  return this;
}


// ========================================================================
// __unwind$116791
// EA  : 0x82F09690
// RVA : 0x00F09690
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116791()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 448 + 468));
}


// ========================================================================
// __unwind$116792
// EA  : 0x82F096B8
// RVA : 0x00F096B8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_116792()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 448 + 468) + 8));
}


// ========================================================================
// ?ReadOfs@idFile_Permanent@@UAAI_JPAXI@Z
// EA  : 0x82F09750
// RVA : 0x00F09750
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
char *__fastcall idFile_Permanent::ReadOfs(
        idFile_Permanent *this,
        unsigned int a2,
        __int64 offset,
        void *buffer,
        unsigned int len)
{
  __int64 v5; // r29
  unsigned int v7; // r24
  char *v8; // r26
  int v9; // r9
  int v10; // r11
  int sectorSize; // r11
  int v12; // r23
  char *v13; // r27
  unsigned int v14; // r6
  size_t v15; // r30
  char *result; // r3
  int v17; // r25
  unsigned int LastError; // r3
  unsigned int v19; // r4
  idTempArray<char> v20[2]; // [sp+50h] [-80h] BYREF
  _OVERLAPPED v21; // [sp+60h] [-70h] BYREF

  v7 = HIDWORD(offset);
  v8 = (char *)offset;
  if ( this->mode == FS_READ_NO_BUFFERING
    && ((v9 = this->sectorSize, HIDWORD(v5) = a2, v10 = v9 - 1, (a2 & (v9 - 1)) != 0)
     || (v10 & HIDWORD(offset)) != 0
     || (v10 & (unsigned int)offset) != 0) )
  {
    sectorSize = this->sectorSize;
    v12 = ~(sectorSize - 1) & a2;
    LODWORD(v5) = ((sectorSize + a2 + offset - 1) & ~(sectorSize - 1)) - v12;
    idTempArray<char>::idTempArray<char>(this: v20, num: v9 + v5);
    v13 = v20[0].buffer;
    v14 = v5;
    LODWORD(v5) = &v20[0].buffer[this->sectorSize - ((this->sectorSize - 1) & (int)v20[0].buffer)];
    v15 = this->ReadOfs(this, a2: v12, a3: (void *)v5, a4: v14) - (HIDWORD(v5) - v12);
    if ( v15 > (unsigned int)v8 )
      v15 = (size_t)v8;
    memcpy(Dst: (void *)v7, Src: (const void *)(HIDWORD(v5) - v12 + v5), Size: v15);
    if ( v13 != nullptr )
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    return (char *)v15;
  }
  else if ( fs_noOverlappedIO.valueInteger != 0 )
  {
    ((void (__fastcall *)(idFile_Permanent *))this->Seek)(a1: this);
    return (char *)this->Read(this, a2: (void *)v7, a3: (unsigned int)v8);
  }
  else
  {
    LODWORD(v5) = 0;
    v17 = 0;
    *(_QWORD *)&v21.Internal = v5;
    v21.OffsetHigh = (unsigned int)this;
    v21.Offset = a2;
    v21.hEvent = nullptr;
    while ( 1 )
    {
      v20[0].buffer = nullptr;
      if ( ReadFile(
             hFile: this->handle,
             lpBuffer: (void *)v7,
             nNumberOfBytesToRead: (unsigned int)v8,
             lpNumberOfBytesRead: (unsigned int *)v20,
             lpOverlapped: &v21) != 0 )
        break;
      LastError = GetLastError();
      if ( LastError != 0 )
      {
        if ( LastError == 997 )
        {
          if ( GetOverlappedResult(
                 hFile: this->handle,
                 lpOverlapped: &v21,
                 lpNumberOfBytesTransferred: (unsigned int *)v20,
                 bWait: 1) != 0 )
            goto LABEL_23;
          v19 = GetLastError();
          idLib::Warning(fmt: "GetOverlappedResult: error %i", v19);
        }
        else
        {
          idLib::Warning(fmt: "ReadFile: error %i", LastError);
        }
      }
      Sleep(dwMilliseconds: 0xAu);
      if ( ++v17 >= 2 )
      {
        memset(Dst: (void *)v7, Val: 0, Size: (size_t)v8);
        return nullptr;
      }
    }
    result = v20[0].buffer;
    if ( v20[0].buffer == v8 )
      return result;
LABEL_23:
    memset(Dst: &v20[0].buffer[v7], Val: 0, Size: v8 - v20[0].buffer);
    return v20[0].buffer;
  }
}


// ========================================================================
// __unwind$117029
// EA  : 0x82F099D0
// RVA : 0x00F099D0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_117029()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 208 + 80));
}


// ========================================================================
// ??0idFile_AtomicWrite@@QAA@QBDW4fsPath_t@@@Z
// EA  : 0x82F09A00
// RVA : 0x00F09A00
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

idFile_AtomicWrite *__fastcall idFile_AtomicWrite::idFile_AtomicWrite(
        idFile_AtomicWrite *this,
        const char *relativePath,
        fsPath_t basePath_)
{
  char v7[304]; // [sp+60h] [-130h] BYREF

  idFile_Memory::idFile_Memory(this, name: relativePath);
  this->__vftable = (idFile_AtomicWrite_vtbl *)&idFile_AtomicWrite::`vftable';
  idStr::idStr(this: &this->writeName, text: relativePath);
  this->basePath = basePath_;
  this->osPath.len = 0;
  this->osPath.data = this->osPath.baseBuffer;
  this->osPath.allocedAndFlag = 20;
  this->osPath.baseBuffer[0] = 0;
  fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: this->writeName.data, a3: v7, a4: 256, a5: this->basePath);
  idStr::operator=(this: &this->osPath, text: v7);
  return this;
}


// ========================================================================
// __unwind$117067
// EA  : 0x82F09AA4
// RVA : 0x00F09AA4
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_117067()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: *(idFile_Memory **)(v0 - 400 + 420));
}


// ========================================================================
// __unwind$117068
// EA  : 0x82F09ACC
// RVA : 0x00F09ACC
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_117068()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 400 + 420) + 332));
}


// ========================================================================
// __unwind$117069
// EA  : 0x82F09AF8
// RVA : 0x00F09AF8
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void _unwind_117069()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 400 + 420) + 368));
}


// ========================================================================
// `dynamic initializer for 'mutexPageFile''
// EA  : 0x833945D0
// RVA : 0x013945D0
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mutexPageFile__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&mutexPageFile);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mutexPageFile__);
}


// ========================================================================
// `dynamic initializer for 'fs_reportReads''
// EA  : 0x83394608
// RVA : 0x01394608
// PDB : w:\tech5\shared\idlib\filesystem\file.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_reportReads__()
{
  idCVar::idCVar(
    this: &fs_reportReads,
    name: "fs_reportReads",
    value: "0",
    flags: 1,
    description: "Report every filesystem reads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_reportReads__);
}

