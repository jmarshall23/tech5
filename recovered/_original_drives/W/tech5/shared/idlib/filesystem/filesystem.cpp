
// ========================================================================
// ?CopyGameFile@idFileSystemLocal@@QAA_NPAVidFile@@0@Z
// EA  : 0x82F09B88
// RVA : 0x00F09B88
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall idFileSystemLocal::CopyGameFile(idFileSystemLocal *this, idFile *src, idFile *dst)
{
  int v5; // r29
  unsigned int v6; // r31
  _BYTE v8[48]; // [sp+50h] [-1030h] BYREF

  v5 = 0;
  v6 = src->Read(this: src, a2: v8, a3: 4096u);
  if ( v6 != 0 )
  {
    while ( dst->Write(this: dst, a2: v8, a3: v6) == v6 )
    {
      v5 += v6;
      v6 = src->Read(this: src, a2: v8, a3: 4096u);
      if ( v6 == 0 )
        goto LABEL_4;
    }
    idLib::Warning(fmt: "Write didn't match requested size");
    return false;
  }
  else
  {
LABEL_4:
    src->Seek(this: src, a2: 0, a3: FS_SEEK_SET);
    if ( v5 != (int)src->Length(this: src) )
      idLib::Warning(fmt: "Total bytes written doesn't match filesize");
    return (_cntlzw(src->Length(this: src) - v5) & 0x20) != 0;
  }
}


// ========================================================================
// ?ReadFile@idFileSystemLocal@@UAAHPBDPAPAXPAI@Z
// EA  : 0x82F09CA8
// RVA : 0x00F09CA8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::ReadFile(
        idFileSystemLocal *this,
        const char *relativePath,
        void **buffer,
        unsigned int *timestamp)
{
  idFile *v8; // r3
  idFile *v9; // r31
  int v10; // r29
  int loadStack; // r10
  void *v13; // r3
  _BYTE *v14; // r30

  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  if ( relativePath == nullptr || *relativePath == 0 )
  {
    idLib::Warning(fmt: "idFileSystemLocal::ReadFile with empty name");
    return -1;
  }
  if ( timestamp != nullptr )
    *timestamp = -1;
  if ( buffer != nullptr )
    *buffer = nullptr;
  v8 = this->OpenFileRead(this, a2: relativePath, a3: buffer != nullptr, a4: 0);
  v9 = v8;
  if ( v8 == nullptr )
    return -1;
  v10 = v8->Length(this: v8);
  if ( timestamp != nullptr )
    *timestamp = v9->Timestamp(this: v9);
  if ( buffer != nullptr )
  {
    loadStack = this->loadStack;
    ++this->loadCount;
    this->loadStack = loadStack + 1;
    v13 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\filesystem\\FileSystem.cpp(1026) : TAG_FILE",
            size: v10 + 1,
            tag: TAG_FILE,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    *buffer = v13;
    v14 = v13;
    v9->Read(this: v9, a2: v13, a3: v10);
    v14[v10] = 0;
  }
  ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
  return v10;
}


// ========================================================================
// ?FreeFile@idFileSystemLocal@@UAAXPAX@Z
// EA  : 0x82F09E58
// RVA : 0x00F09E58
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::FreeFile(idFileSystemLocal *this, void *buffer)
{
  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  if ( buffer == nullptr )
    idLib::FatalError(fmt: "idFileSystemLocal::FreeFile( NULL )");
  --this->loadStack;
  idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
}


// ========================================================================
// ?Read@idFile_Stat@@UAAIPAXI@Z
// EA  : 0x82F09EE8
// RVA : 0x00F09EE8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFile_Stat::Read(idFile_Stat *this, void *buffer, unsigned int len)
{
  idLib::Error(fmt: "Read is not allowed with idFile_Stat", buffer, len);
}


// ========================================================================
// ?Write@idFile_Stat@@UAAIPBXI@Z
// EA  : 0x82F09EF8
// RVA : 0x00F09EF8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFile_Stat::Write(idFile_Stat *this, const void *buffer, unsigned int len)
{
  idLib::Error(fmt: "Write is not allowed with idFile_Stat", buffer, len);
}


// ========================================================================
// ?ReadOfs@idFile_Stat@@UAAI_JPAXI@Z
// EA  : 0x82F09F08
// RVA : 0x00F09F08
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFile_Stat::ReadOfs(idFile_Stat *this, int a2, __int64 offset, void *buffer, unsigned int len)
{
  idLib::Error(fmt: "ReadOfs is not allowed with idFile_Stat", a2, offset, buffer, len);
}


// ========================================================================
// ?WriteOfs@idFile_Stat@@UAAI_JPBXI@Z
// EA  : 0x82F09F18
// RVA : 0x00F09F18
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFile_Stat::WriteOfs(idFile_Stat *this, int a2, __int64 offset, const void *buffer, unsigned int len)
{
  idLib::Error(fmt: "WriteOfs is not allowed with idFile_Stat", a2, offset, buffer, len);
}


// ========================================================================
// ?SetLength@idFile_Stat@@UAAXI@Z
// EA  : 0x82F09F28
// RVA : 0x00F09F28
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFile_Stat::SetLength(idFile_Stat *this, unsigned int len)
{
  idLib::Error(fmt: "SetLength is not allowed with idFile_Stat", len);
}


// ========================================================================
// ?Seek@idFile_Stat@@UAAH_JW4fsOrigin_t@@@Z
// EA  : 0x82F09F38
// RVA : 0x00F09F38
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFile_Stat::Seek(idFile_Stat *this, int a2, __int64 offset, fsOrigin_t origin)
{
  idLib::Error(fmt: "Seeking is not allowed with idFile_Stat", a2, offset, origin);
}


// ========================================================================
// ??0idCachedZipFile@@QAA@XZ
// EA  : 0x82F09FB0
// RVA : 0x00F09FB0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idCachedZipFile *__fastcall idCachedZipFile::idCachedZipFile(idCachedZipFile *this)
{
  this->zipFileName.len = 0;
  this->zipFileName.allocedAndFlag = 20;
  this->zipFileName.data = this->zipFileName.baseBuffer;
  this->zipFileName.baseBuffer[0] = 0;
  this->relativeZipFileName.allocedAndFlag = 20;
  this->relativeZipFileName.data = this->relativeZipFileName.baseBuffer;
  this->relativeZipFileName.len = 0;
  this->relativeZipFileName.baseBuffer[0] = 0;
  this->handle = nullptr;
  this->numFiles = 0;
  memset(Dst: &this->hashTable, Val: 0, Size: sizeof(this->hashTable));
  this->fileList = nullptr;
  this->next = nullptr;
  return this;
}


// ========================================================================
// ?testCreateOSPath_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F0A038
// RVA : 0x00F0A038
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall testCreateOSPath_f(const idCmdArgs *args)
{
  if ( args->argc == 2 )
    fileSystem->CreateOSPath(this: fileSystem, a2: args->argv[1]);
}


// ========================================================================
// IsOSPath
// EA  : 0x82F0A068
// RVA : 0x00F0A068
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall IsOSPath(const char *path)
{
  int v3; // r11
  int v4; // r10

  if ( idStr::Icmpn(s1: path, s2: "mtp:", n: 4) == 0
    || idStr::Icmpn(s1: path, s2: "nfs:", n: 4) == 0
    || idStr::Icmpn(s1: path, s2: "devkit:", n: 7) == 0
    || idStr::Icmpn(s1: path, s2: "game:", n: 5) == 0
    || idStr::Icmpn(s1: path, s2: "cache:", n: 6) == 0
    || idStr::Icmpn(s1: path, s2: "dlc:", n: 4) == 0
    || idStr::Icmpn(s1: path, s2: "saves:", n: 6) == 0 )
  {
    return true;
  }
  v3 = 0;
  v4 = *path;
  if ( *path == 0 )
    return false;
  do
    ++v3;
  while ( path[v3] != 0 );
  if ( v3 < 2 )
    return false;
  return path[1] == 58 && (v4 > 64 && v4 < 91 || v4 > 96 && v4 < 123) || v4 == 92 || v4 == 47;
}


// ========================================================================
// ?IsOSNativePath@@YA_NPBD@Z
// EA  : 0x82F0A1D8
// RVA : 0x00F0A1D8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall IsOSNativePath(const char *OSPath)
{
  return IsOSPath(path: OSPath)
      && idStr::Icmpn(s1: OSPath, s2: "mtp:", n: 4) != 0
      && idStr::Icmpn(s1: OSPath, s2: "nfs:", n: 4) != 0;
}


// ========================================================================
// ?GetBasePathStr@idFileSystemLocal@@UBAPBDW4fsPath_t@@@Z
// EA  : 0x82F0A260
// RVA : 0x00F0A260
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

char *__fastcall idFileSystemLocal::GetBasePathStr(idFileSystemLocal *this, unsigned int basePath)
{
  char *result; // r3

  if ( basePath > 3 )
    return &byte_8200D768;
  switch ( basePath )
  {
    case 0u:
      return this->pathBase.data;
    case 1u:
      result = this->pathCache.data;
      if ( *result != 0 )
        return result;
      break;
    case 2u:
      break;
    default:
      return this->pathInstall.data;
  }
  result = this->pathSave.data;
  if ( *result == 0 )
    return this->pathBase.data;
  return result;
}


// ========================================================================
// ?renameFile_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F0A2C0
// RVA : 0x00F0A2C0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall renameFile_f(const idCmdArgs *args)
{
  bool v1; // r3

  if ( args->argc == 3 )
  {
    v1 = fileSystem->RenameFile(this: fileSystem, a2: args->argv[1], a3: args->argv[2], a4: FSPATH_BASE);
    idLib::Printf(fmt: "RenameFile() returned %i\n", v1);
  }
  else
  {
    idLib::Printf(fmt: "renameFile <from> <to>\n");
  }
}


// ========================================================================
// ?GetNumberedFilename@idFileSystemLocal@@UAAXAAHPBD1AAVidStr@@_N@Z
// EA  : 0x82F0A338
// RVA : 0x00F0A338
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::GetNumberedFilename(
        idFileSystemLocal *this,
        int *lastNumber,
        const char *base,
        const char *ext,
        idStr *outputFilename,
        BOOL overrideProduction)
{
  int v7; // r6

  v7 = *lastNumber + 1;
  *lastNumber = v7;
  if ( v7 <= 99999 )
  {
    for ( ; v7 < 99999; *lastNumber = v7 )
    {
      idStr::Format(this: outputFilename, fmt: "%s%05i.%s", base, v7, ext);
      if ( *lastNumber == 99999 )
        break;
      if ( !fileSystem->FileExists(this: fileSystem, a2: outputFilename->data, a3: overrideProduction) )
        break;
      v7 = *lastNumber + 1;
    }
  }
  else
  {
    *lastNumber = 99999;
  }
}


// ========================================================================
// ?Path_f@idFileSystemLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82F0A3F8
// RVA : 0x00F0A3F8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::Path_f(const idCmdArgs *args)
{
  int v1; // r29
  idStr *list; // r11
  int v3; // r31

  idLib::Printf(fmt: "Current search path:\n");
  v1 = 0;
  if ( fileSystemLocal.searchPaths.num > 0 )
  {
    list = fileSystemLocal.searchPaths.list;
    v3 = 0;
    do
    {
      idLib::Printf(fmt: "%s\n", list->data);
      ++v1;
      list = &fileSystemLocal.searchPaths.list[++v3];
    }
    while ( v1 < fileSystemLocal.searchPaths.num );
  }
}


// ========================================================================
// ?IsInitialized@idFileSystemLocal@@UBA_NXZ
// EA  : 0x82F0A4C8
// RVA : 0x00F0A4C8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

unsigned int __fastcall idFileSystemLocal::IsInitialized(idFileSystemLocal *this)
{
  return (-this->searchPaths.num & (unsigned int)~this->searchPaths.num) >> 31;
}


// ========================================================================
// ?OpenFromMTP@idFileSystemLocal@@AAAPAVidFile@@PBDW4fsMode_t@@@Z
// EA  : 0x82F0A4E8
// RVA : 0x00F0A4E8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile_MTP *__fastcall idFileSystemLocal::OpenFromMTP(idFileSystemLocal *this, const char *path, fsMode_t mode)
{
  idFile_MTP *v5; // r3
  idFile_MTP *v6; // r29
  int v7; // r30
  unsigned int v9; // r3
  unsigned int v10; // r28
  void *v11; // r3
  void *v12; // r27
  idFile_Memory *v13; // r3
  idFile_Memory *v14; // r30

  v5 = (idFile_MTP *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x68u,
                       tag: TAG_FILE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idFile_MTP::idFile_MTP(this: v5);
  else
    v6 = nullptr;
  v7 = 10;
  if ( mode != FS_WRITE )
    v7 = 1;
  while ( 1 )
  {
    --v7;
    if ( idFile_MTP::Open(this: v6, filename: path + 4, mode) )
      break;
    mgthread_sleep(ms: 10);
    if ( v7 <= 0 )
    {
      --v7;
      break;
    }
  }
  if ( v7 < 0 )
  {
    if ( v6 != nullptr )
      ((void (__fastcall *)(idFile_MTP *, int))v6->dtr_idFile)(a1: v6, a2: 1);
    return nullptr;
  }
  v9 = v6->Length(this: v6);
  v10 = v9;
  if ( mode != FS_READ && mode != FS_READ_NO_BUFFERING
    || fs_mtpWholeReadThreshold.valueInteger <= 0
    || v9 > fs_mtpWholeReadThreshold.valueInteger )
  {
    return v6;
  }
  v11 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\filesystem\\FileSystem.cpp(1836) : TAG_FILE",
          size: v9,
          tag: TAG_FILE,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v12 = v11;
  if ( v10 == 0 || v11 == nullptr || v6->Read(this: v6, a2: v11, a3: v10) != v10 )
  {
    idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    return v6;
  }
  v13 = (idFile_Memory *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x14Cu,
                           tag: TAG_FILE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v13 != nullptr )
    v14 = idFile_Memory::idFile_Memory(this: v13, name: path);
  else
    v14 = nullptr;
  idFile_Memory::SetReadOnlyData(this: v14, data: (char *)v12, length: v10);
  v14->ownsData = true;
  v14->timestamp = v6->Timestamp(this: v6);
  ((void (__fastcall *)(idFile_MTP *, int))v6->dtr_idFile)(a1: v6, a2: 1);
  return (idFile_MTP *)v14;
}


// ========================================================================
// __unwind$119482
// EA  : 0x82F0A710
// RVA : 0x00F0A710
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_119482()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_FILE);
}


// ========================================================================
// __unwind$119483
// EA  : 0x82F0A73C
// RVA : 0x00F0A73C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_119483()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?OpenFromNFS@idFileSystemLocal@@AAAPAVidFile@@PBDW4fsMode_t@@_N@Z
// EA  : 0x82F0A770
// RVA : 0x00F0A770
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile_Nfs *__fastcall idFileSystemLocal::OpenFromNFS(
        idFileSystemLocal *this,
        const char *path,
        fsMode_t mode,
        bool create)
{
  idFile_Nfs *v7; // r3
  idFile_Nfs *v8; // r30

  v7 = (idFile_Nfs *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0xE8u,
                       tag: TAG_FILE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idFile_Nfs::idFile_Nfs(this: v7);
  else
    v8 = nullptr;
  if ( idFile_Nfs::Open(this: v8, path, mode, create, createPath: create) )
    return v8;
  if ( v8 != nullptr )
    ((void (__fastcall *)(idFile_Nfs *, int))v8->dtr_idFile)(a1: v8, a2: 1);
  return nullptr;
}


// ========================================================================
// __unwind$119543
// EA  : 0x82F0A828
// RVA : 0x00F0A828
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_119543()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?IsRelativePath@idFileSystemLocal@@UBA_NPBD@Z
// EA  : 0x82F0A858
// RVA : 0x00F0A858
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall idFileSystemLocal::IsRelativePath(idFileSystemLocal *this, const char *path)
{
  return (_cntlzw(IsOSPath(path)) & 0x20) != 0;
}


// ========================================================================
// ?CreateOSPath@idFileSystemLocal@@UAAXPBD@Z
// EA  : 0x82F0AA80
// RVA : 0x00F0AA80
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::CreateOSPath(idFileSystemLocal *this, const char *OSPath)
{
  int v3; // r30
  int len; // r27
  char *data; // r10
  char v6; // r29
  idStr v7[2]; // [sp+50h] [-50h] BYREF

  if ( idStr::Icmpn(s1: OSPath, s2: "nfs:", n: 4) != 0 )
  {
    idStr::idStr(this: v7, text: OSPath);
    v3 = 1;
    len = v7[0].len;
    if ( v7[0].len > 1 )
    {
      data = v7[0].data;
      do
      {
        v6 = data[v3];
        if ( v6 == 92 || v6 == 47 )
        {
          data[v3] = 0;
          Sys_Mkdir(path: v7[0].data);
          v7[0].data[v3] = v6;
          data = v7[0].data;
        }
        ++v3;
      }
      while ( v3 < len );
    }
    idStr::FreeData(this: v7);
  }
  else
  {
    idFile_Nfs::CreateOsPath(path: OSPath);
  }
}


// ========================================================================
// __unwind$120546
// EA  : 0x82F0AB30
// RVA : 0x00F0AB30
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120546()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?BuildOSPath@idFileSystemLocal@@ABA?AVidStr@@PBD0@Z
// EA  : 0x82F0AB60
// RVA : 0x00F0AB60
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFileSystemLocal *__fastcall idFileSystemLocal::BuildOSPath(
        idFileSystemLocal *this,
        idStr *result,
        const char *base,
        const char *relativePath)
{
  char *i; // r11
  int v9; // r10
  idStr v10; // [sp+60h] [-470h] BYREF
  idStrStatic<1024> v11; // [sp+80h] [-450h] BYREF

  if ( IsOSPath(path: relativePath) )
  {
    idStr::idStr((idStr *)this, text: relativePath);
    return this;
  }
  else
  {
    idStrStatic<1024>::idStrStatic<1024>(this: &v11, text: base);
    if ( fs_caseSensitiveOS.valueInteger != 0 )
    {
      idStr::idStr(this: &v10, text: relativePath);
      idStr::ToLower(this: &v10);
      idStr::AppendPath(this: &v11, text: v10.data);
      idStr::FreeData(this: &v10);
    }
    else
    {
      idStr::AppendPath(this: &v11, text: relativePath);
    }
    idStr::CollapsePath(this: &v11);
    for ( i = v11.data; *i != 0; ++i )
    {
      v9 = *i;
      if ( v9 == 47 || v9 == 92 )
        *i = 92;
    }
    idStr::idStr((idStr *)this, text: &v11);
    idStr::FreeData(this: &v11);
    return this;
  }
}


// ========================================================================
// __unwind$120590
// EA  : 0x82F0AC74
// RVA : 0x00F0AC74
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120590()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 1232;
  if ( (*(_DWORD *)(v0 - 1232 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 1252));
  }
}


// ========================================================================
// __unwind$120593
// EA  : 0x82F0ACB8
// RVA : 0x00F0ACB8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120593()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1232 + 128));
}


// ========================================================================
// __unwind$120594
// EA  : 0x82F0ACE0
// RVA : 0x00F0ACE0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120594()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1232 + 96));
}


// ========================================================================
// ?BuildOSPath@idFileSystemLocal@@ABA?AVidStr@@W4fsPath_t@@PBD@Z
// EA  : 0x82F0AD10
// RVA : 0x00F0AD10
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFileSystemLocal *__fastcall idFileSystemLocal::BuildOSPath(
        idFileSystemLocal *this,
        idStr *result,
        fsPath_t fsPath,
        const char *relativePath)
{
  const char *v7; // r3
  idStrStatic<256> v9; // [sp+60h] [-150h] BYREF

  v7 = (const char *)(*(int (__fastcall **)(idStr *, fsPath_t))(result->len + 132))(a1: result, a2: fsPath);
  idStrStatic<256>::idStrStatic<256>(this: &v9, text: v7);
  idStr::AppendPath(this: &v9, text: "base");
  idFileSystemLocal::BuildOSPath(this, result, base: v9.data, relativePath);
  idStr::FreeData(this: &v9);
  return this;
}


// ========================================================================
// __unwind$120650
// EA  : 0x82F0AD9C
// RVA : 0x00F0AD9C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120650()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$120651
// EA  : 0x82F0ADC4
// RVA : 0x00F0ADC4
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120651()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 432;
  if ( (*(_DWORD *)(v0 - 432 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 452));
  }
}


// ========================================================================
// ?GeneratedPath@idFileSystemLocal@@UBA?AVidStr@@PBD@Z
// EA  : 0x82F0AE10
// RVA : 0x00F0AE10
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFileSystemLocal *__fastcall idFileSystemLocal::GeneratedPath(
        idFileSystemLocal *this,
        idStr *result,
        const char *appendedPath)
{
  idStrStatic<256> v6; // [sp+60h] [-140h] BYREF

  idStrStatic<256>::idStrStatic<256>(this: &v6, text: fs_generatedPath.valueString.data);
  idStr::AppendPath(this: &v6, text: appendedPath);
  idStr::idStr((idStr *)this, text: &v6);
  idStr::FreeData(this: &v6);
  return this;
}


// ========================================================================
// __unwind$120692
// EA  : 0x82F0AE7C
// RVA : 0x00F0AE7C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120692()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$120693
// EA  : 0x82F0AEA4
// RVA : 0x00F0AEA4
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120693()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 416;
  if ( (*(_DWORD *)(v0 - 416 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 436));
  }
}


// ========================================================================
// ?FixLongFilename@idFileSystemLocal@@UBA_NPBD00PADH@Z
// EA  : 0x82F0AEF0
// RVA : 0x00F0AEF0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::FixLongFilename(
        idFileSystemLocal *this,
        const char *basePath,
        const char *extension,
        const char *inPath,
        char *outPath,
        int maxOutPath)
{
  const char *v6; // r28
  int v11; // r11
  const char *v12; // r10
  int v13; // r30
  char *i; // r28
  char v15; // r23
  idStrStatic<256> v17; // [sp+50h] [-5F0h] BYREF
  idStr v18; // [sp+170h] [-4D0h] BYREF
  char v19; // [sp+190h] [-4B0h] BYREF
  idStr v20; // [sp+290h] [-3B0h] BYREF
  char v21; // [sp+2B0h] [-390h] BYREF
  idStrStatic<256> v22; // [sp+3B0h] [-290h] BYREF
  idStrStatic<256> v23; // [sp+4D0h] [-170h] BYREF

  v6 = inPath;
  if ( idStr::Find(searchIn: inPath, searchFor: sourceBase, casesensitive: false, start: 0, end: -1) == 0 )
  {
    v11 = 0;
    v12 = "../../";
    do
    {
      ++v12;
      ++v11;
    }
    while ( *v12 != 0 );
    v6 += v11;
  }
  idStrStatic<256>::idStrStatic<256>(this: &v17, text: v6);
  v18.baseBuffer[0] = 0;
  v19 = 0;
  v18.data = &v19;
  v18.len = 0;
  v18.allocedAndFlag = -2147483392;
  idStr::SetFileExtension(this: &v17, extension);
  idStr::ExtractFileName(this: &v17, dest: &v18);
  if ( v18.len >= 38 )
  {
    v20.baseBuffer[0] = 0;
    v21 = 0;
    v20.data = &v21;
    v20.len = 0;
    v20.allocedAndFlag = -2147483392;
    idStr::ExtractFilePath(this: &v17, dest: &v20);
    idStrStatic<256>::idStrStatic<256>(this: &v23, text: basePath);
    v17.len = v23.len;
    memcpy(Dst: v17.data, Src: v23.data, Size: v23.len + 1);
    idStr::FreeData(this: &v23);
    idStr::AppendPath(this: &v17, text: v20.data);
    idStr::StripFileExtension(this: &v18);
    v13 = 0;
    for ( i = v18.data; *i != 0; ++i )
    {
      if ( v13 >= 30 )
      {
        idStr::EnsureAlloced(this: &v17, amount: v17.len + 2, keepold: true, geometricGrowth: true);
        v13 = 0;
        v17.data[v17.len++] = 47;
        v17.data[v17.len] = 0;
      }
      v15 = *i;
      idStr::EnsureAlloced(this: &v17, amount: v17.len + 2, keepold: true, geometricGrowth: true);
      ++v13;
      v17.data[v17.len++] = v15;
      v17.data[v17.len] = 0;
    }
    idStr::SetFileExtension(this: &v17, extension);
    idStr::Copynz(dest: outPath, src: v17.data, destsize: maxOutPath);
    idStr::FreeData(this: &v20);
    idStr::FreeData(this: &v18);
  }
  else
  {
    idStrStatic<256>::idStrStatic<256>(this: &v22, text: basePath);
    v17.len = v22.len;
    memcpy(Dst: v17.data, Src: v22.data, Size: v22.len + 1);
    idStr::FreeData(this: &v22);
    idStr::AppendPath(this: &v17, text: v6);
    idStr::SetFileExtension(this: &v17, extension);
    idStr::Copynz(dest: outPath, src: v17.data, destsize: maxOutPath);
    idStr::FreeData(this: &v18);
  }
  idStr::FreeData(this: &v17);
  return 1;
}


// ========================================================================
// __unwind$120738
// EA  : 0x82F0B15C
// RVA : 0x00F0B15C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120738()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1600 + 80));
}


// ========================================================================
// __unwind$120739
// EA  : 0x82F0B184
// RVA : 0x00F0B184
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120739()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1600 + 368));
}


// ========================================================================
// __unwind$120741
// EA  : 0x82F0B1AC
// RVA : 0x00F0B1AC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_120741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1600 + 656));
}


// ========================================================================
// ?OSPathToRelativePath@idFileSystemLocal@@UAA_NPBDPADH@Z
// EA  : 0x82F0B1E0
// RVA : 0x00F0B1E0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::OSPathToRelativePath(
        idFileSystemLocal *this,
        const char *OSPath,
        char *relativePath,
        int maxLen)
{
  int v4; // r28
  int v9; // r29
  idStr v11[3]; // [sp+50h] [-60h] BYREF

  v4 = 0;
  *relativePath = 0;
  if ( this->searchPaths.num <= 0 )
  {
LABEL_5:
    if ( fs_debug.valueInteger > 0 )
      idLib::Warning(fmt: "idFileSystem::OSPathToRelativePath failed on %s", OSPath);
    return 0;
  }
  else
  {
    v9 = 0;
    while ( 1 )
    {
      idStr::idStr(this: v11, text: &this->searchPaths.list[v9]);
      if ( idStr::IcmpnPath(s1: v11[0].data, s2: OSPath, n: v11[0].len) == 0 )
        break;
      idStr::FreeData(this: v11);
      ++v4;
      ++v9;
      if ( v4 >= this->searchPaths.num )
        goto LABEL_5;
    }
    idStr::Copynz(dest: relativePath, src: &OSPath[v11[0].len], destsize: maxLen);
    idStr::BackSlashesToSlashes(path: relativePath);
    idStr::FreeData(this: v11);
    return 1;
  }
}


// ========================================================================
// __unwind$121025
// EA  : 0x82F0B2B8
// RVA : 0x00F0B2B8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121025()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?RelativePathToOSPath@idFileSystemLocal@@UBAXPBDPADHW4fsPath_t@@@Z
// EA  : 0x82F0B2E8
// RVA : 0x00F0B2E8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::RelativePathToOSPath(
        idFileSystemLocal *this,
        const char *relativePath,
        char *osPath,
        int maxLen,
        fsPath_t basePath)
{
  idFileSystemLocal *v7; // r3
  idStr v8[2]; // [sp+50h] [-40h] BYREF

  v7 = idFileSystemLocal::BuildOSPath(
         this: (idFileSystemLocal *)v8,
         result: (idStr *)this,
         fsPath: basePath,
         relativePath);
  idStr::Copynz(dest: osPath, src: (const char *)v7->searchPaths.list, destsize: maxLen);
  idStr::FreeData(this: v8);
}


// ========================================================================
// __unwind$121080
// EA  : 0x82F0B334
// RVA : 0x00F0B334
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121080()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?RelativePathToOSPath@idFileSystemLocal@@UBA?AVidStr@@PBDW4fsPath_t@@@Z
// EA  : 0x82F0B360
// RVA : 0x00F0B360
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFileSystemLocal *__fastcall idFileSystemLocal::RelativePathToOSPath(
        idFileSystemLocal *this,
        idStr *result,
        const char *relativePath,
        fsPath_t basePath)
{
  idFileSystemLocal::BuildOSPath(this, result, fsPath: basePath, relativePath);
  return this;
}


// ========================================================================
// ?RemoveDir@idFileSystemLocal@@UAA_NPBD@Z
// EA  : 0x82F0B3A8
// RVA : 0x00F0B3A8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::RemoveDir(idFileSystemLocal *this, const char *relativePath)
{
  int v4; // r25
  idFileSystemLocal *v5; // r25
  size_t v6; // r30
  idFileSystemLocal *v7; // r28
  size_t v8; // r30
  int v9; // r30
  idStr v11; // [sp+50h] [-A0h] BYREF
  idStr v12; // [sp+70h] [-80h] BYREF
  idStr v13[3]; // [sp+90h] [-60h] BYREF

  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  LOBYTE(v4) = 1;
  v11.baseBuffer[0] = 0;
  if ( *fs_savepath.valueString.data != 0 )
  {
    v5 = idFileSystemLocal::BuildOSPath(
           this: (idFileSystemLocal *)&v12,
           result: (idStr *)this,
           fsPath: FSPATH_SAVE,
           relativePath);
    v6 = (size_t)v5->__vftable;
    idStr::EnsureAlloced(this: &v11, amount: (int)&v5->dtr_idFileSystem + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v11.data, Src: v5->searchPaths.list, Size: v6);
    v11.data[v6] = 0;
    v11.len = v6;
    idStr::FreeData(this: &v12);
    if ( idStr::Icmpn(s1: v11.data, s2: "nfs:", n: 4) != 0 )
      v4 = idLobbyBackend360::StartArbitration(pexcept: (_exception *)v11.data) & 1;
    else
      LOBYTE(v4) = (_cntlzw(idFile_Nfs::RemoveFile(path: v11.data) - 1) & 0x20) != 0;
  }
  v7 = idFileSystemLocal::BuildOSPath(
         this: (idFileSystemLocal *)v13,
         result: (idStr *)this,
         fsPath: FSPATH_BASE,
         relativePath);
  v8 = (size_t)v7->__vftable;
  idStr::EnsureAlloced(this: &v11, amount: (int)&v7->dtr_idFileSystem + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v11.data, Src: v7->searchPaths.list, Size: v8);
  v11.data[v8] = 0;
  v11.len = v8;
  idStr::FreeData(this: v13);
  if ( idStr::Icmpn(s1: v11.data, s2: "nfs:", n: 4) != 0 )
    v9 = (unsigned __int8)(idLobbyBackend360::StartArbitration(pexcept: (_exception *)v11.data) & v4);
  else
    v9 = ((_cntlzw(idFile_Nfs::RemoveFile(path: v11.data) - 1) & 0x20) != 0) & (unsigned __int8)v4;
  idStr::FreeData(this: &v11);
  return v9;
}


// ========================================================================
// __unwind$121123
// EA  : 0x82F0B540
// RVA : 0x00F0B540
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121123()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$121124
// EA  : 0x82F0B568
// RVA : 0x00F0B568
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121124()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$121125
// EA  : 0x82F0B590
// RVA : 0x00F0B590
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121125()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// ?RenameFile@idFileSystemLocal@@UAA_NPBD0W4fsPath_t@@@Z
// EA  : 0x82F0B5C0
// RVA : 0x00F0B5C0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall idFileSystemLocal::RenameFile(
        idFileSystemLocal *this,
        const char *relativePath,
        const char *newName,
        fsPath_t basePath)
{
  BOOL v8; // r30
  int v9; // r3
  unsigned int LastError; // r3
  idStr v12; // [sp+50h] [-70h] BYREF
  idStr v13[2]; // [sp+70h] [-50h] BYREF

  idFileSystemLocal::BuildOSPath(this: (idFileSystemLocal *)v13, result: (idStr *)this, fsPath: basePath, relativePath);
  idFileSystemLocal::BuildOSPath(
    this: (idFileSystemLocal *)&v12,
    result: (idStr *)this,
    fsPath: basePath,
    relativePath: newName);
  if ( idStr::Icmpn(s1: relativePath, s2: "nfs:", n: 4) != 0 )
  {
    v9 = MoveFileExA(lpExistingFileName: v13[0].data, lpNewFileName: v12.data, dwFlags: 1u);
    v8 = v9 != 0;
    if ( v9 == 0 )
    {
      LastError = GetLastError();
      idLib::Warning(fmt: "RenameFile( %s, %s ) error %i", v12.data, v13[0].data, LastError);
    }
    idStr::FreeData(this: &v12);
  }
  else
  {
    v8 = (_cntlzw(idFile_Nfs::RenameFile(path: v13[0].data, newPath: v12.data) - 1) & 0x20) != 0;
    idStr::FreeData(this: &v12);
  }
  idStr::FreeData(this: v13);
  return v8;
}


// ========================================================================
// __unwind$121271
// EA  : 0x82F0B6A8
// RVA : 0x00F0B6A8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121271()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$121272
// EA  : 0x82F0B6D0
// RVA : 0x00F0B6D0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121272()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?IsWritable@idFileSystemLocal@@UBA_NPBD@Z
// EA  : 0x82F0B700
// RVA : 0x00F0B700
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall idFileSystemLocal::IsWritable(idFileSystemLocal *this, const char *relativePath)
{
  idFileSystemLocal *v2; // r3
  BOOL IsFileWritable; // r30
  idStr v5; // [sp+50h] [-40h] BYREF

  v2 = idFileSystemLocal::BuildOSPath(
         this: (idFileSystemLocal *)&v5,
         result: (idStr *)this,
         fsPath: FSPATH_BASE,
         relativePath);
  IsFileWritable = Sys_IsFileWritable(path: (const char *)v2->searchPaths.list);
  idStr::FreeData(this: &v5);
  return IsFileWritable;
}


// ========================================================================
// __unwind$121348
// EA  : 0x82F0B75C
// RVA : 0x00F0B75C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121348()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?IsFolder@idFileSystemLocal@@UBA?AW4sysFolder_t@@PBDW4fsPath_t@@@Z
// EA  : 0x82F0B790
// RVA : 0x00F0B790
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::IsFolder(idFileSystemLocal *this, const char *relativePath, fsPath_t basePath)
{
  idFileSystemLocal *v3; // r3
  int IsFolder; // r30
  idStr v6; // [sp+50h] [-40h] BYREF

  v3 = idFileSystemLocal::BuildOSPath(
         this: (idFileSystemLocal *)&v6,
         result: (idStr *)this,
         fsPath: basePath,
         relativePath);
  IsFolder = Sys_IsFolder(path: (const char *)v3->searchPaths.list);
  idStr::FreeData(this: &v6);
  return IsFolder;
}


// ========================================================================
// __unwind$121380
// EA  : 0x82F0B7E8
// RVA : 0x00F0B7E8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121380()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?ListOSFiles@idFileSystemLocal@@AAAXPBD0AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F0B818
// RVA : 0x00F0B818
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::ListOSFiles(
        idFileSystemLocal *this,
        const char *directory,
        char *extension,
        idList<idStr,5> *list)
{
  char *v5; // r29
  idFile_MTP *v7; // r3
  idFile_MTP *v8; // r30

  v5 = extension;
  if ( extension == nullptr )
    v5 = &byte_8200D768;
  if ( idStr::Icmpn(s1: directory, s2: "nfs:", n: 4) != 0 )
  {
    if ( idStr::Icmpn(s1: directory, s2: "mtp:", n: 4) != 0 )
    {
      Sys_ListFiles(directory, extension: v5, list);
    }
    else
    {
      v7 = (idFile_MTP *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x68u,
                           tag: TAG_FILE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idFile_MTP::idFile_MTP(this: v7);
      else
        v8 = nullptr;
      idFile_MTP::List(this: v8, directory, extension: v5, list);
      if ( v8 != nullptr )
        ((void (__fastcall *)(idFile_MTP *, int))v8->dtr_idFile)(a1: v8, a2: 1);
    }
  }
  else
  {
    idFile_Nfs::ListFiles(path: directory, extension: v5, list);
  }
}


// ========================================================================
// __unwind$121578
// EA  : 0x82F0B924
// RVA : 0x00F0B924
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121578()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_FILE);
}


// ========================================================================
// __unwind$121579
// EA  : 0x82F0B950
// RVA : 0x00F0B950
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121579()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 144 + 80));
}


// ========================================================================
// ?LoadZipFile@idFileSystemLocal@@AAAPAVidCachedZipFile@@PBD0@Z
// EA  : 0x82F0B990
// RVA : 0x00F0B990
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idCachedZipFile *__fastcall idFileSystemLocal::LoadZipFile(
        idFileSystemLocal *this,
        const char *zipFileName,
        const char *relativeZipFileName)
{
  void *v7; // r26
  unsigned int number_entry; // r28
  unsigned int v9; // r5
  unsigned int *v10; // r3
  idStr *v11; // r30
  idCachedZipFile *v12; // r3
  idCachedZipFile *v13; // r29
  int *p_numFiles; // r11
  int i; // ctr
  int j; // r28
  int v17; // r27
  int v18; // r11
  idCachedZipFile *cachedZipFiles; // r11
  idCachedZipFile *next; // r10
  unz_global_info_s v21; // [sp+50h] [-4B0h] BYREF
  unsigned int *v22; // [sp+58h] [-4A8h]
  unz_file_info_s v23; // [sp+60h] [-4A0h] BYREF
  char v24[1104]; // [sp+B0h] [-450h] BYREF

  if ( fs_arbitraryZipSupport.valueInteger == 0 )
    return nullptr;
  v7 = unzOpen(path: zipFileName);
  if ( unzGetGlobalInfo(file: v7, pglobal_info: &v21) != 0 )
    return nullptr;
  number_entry = v21.number_entry;
  if ( v21.number_entry > 0x6666666 || (v9 = 40 * v21.number_entry + 4, 40 * v21.number_entry > 0xFFFFFFFB) )
    v9 = -1;
  v10 = (unsigned int *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                          size: v9,
                          tag: TAG_FILE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v22 = v10;
  if ( v10 != nullptr )
  {
    *v10 = number_entry;
    v11 = (idStr *)(v10 + 1);
    `eh vector constructor iterator'(
      ptr: v10 + 1,
      size: 0x28u,
      count: number_entry,
      pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
      pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  }
  else
  {
    v11 = nullptr;
  }
  v12 = (idCachedZipFile *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x250u,
                             tag: TAG_FILE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v12 != nullptr )
    v13 = idCachedZipFile::idCachedZipFile(this: v12);
  else
    v13 = nullptr;
  p_numFiles = &v13->numFiles;
  for ( i = 128; i != 0; --i )
    *++p_numFiles = 0;
  idStr::operator=(this: &v13->zipFileName, text: zipFileName);
  idStr::operator=(this: &v13->relativeZipFileName, text: relativeZipFileName);
  v13->handle = v7;
  v13->numFiles = v21.number_entry;
  v13->fileList = (idZippedFile *)v11;
  v13->next = v13;
  unzGoToFirstFile(file: v7);
  for ( j = 0; j < (int)v21.number_entry; v11 = (idStr *)((char *)v11 + 40) )
  {
    if ( unzGetCurrentFileInfo(
           file: v7,
           pfile_info: &v23,
           szFileName: v24,
           fileNameBufferSize: 0x400u,
           extraField: nullptr,
           extraFieldBufferSize: 0,
           szComment: nullptr,
           commentBufferSize: 0) != 0 )
      break;
    v17 = idStr::FileNameHash(string: v24, hashSize: 128);
    idStr::operator=(this: v11, text: v24);
    idStr::ToLower(this: v11);
    idStr::BackSlashesToSlashes(this: v11);
    unzGetCurrentFileInfoPosition(file: v7, pos: (unsigned int *)&v11[1]);
    v18 = 4 * (v17 + 18);
    v11[1].data = *(char **)((char *)&v13->zipFileName.len + v18);
    *(int *)((char *)&v13->zipFileName.len + v18) = (int)v11;
    unzGoToNextFile(file: v7);
    ++j;
  }
  if ( this->cachedZipFiles != nullptr )
  {
    while ( 1 )
    {
      cachedZipFiles = this->cachedZipFiles;
      if ( cachedZipFiles->relativeZipFileName.len <= v13->relativeZipFileName.len )
        break;
      next = cachedZipFiles->next;
      this->cachedZipFiles = next;
      if ( next == nullptr )
        goto LABEL_23;
    }
    v13->next = cachedZipFiles;
    this->cachedZipFiles = v13;
  }
LABEL_23:
  if ( v13->next == v13 )
  {
    v13->next = nullptr;
    this->cachedZipFiles = v13;
  }
  return v13;
}


// ========================================================================
// __unwind$121686
// EA  : 0x82F0BC1C
// RVA : 0x00F0BC1C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121686()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1280 + 88), tag: TAG_FILE);
}


// ========================================================================
// ?GetFileLength@idFileSystemLocal@@UAA_JPBD@Z
// EA  : 0x82F0BC50
// RVA : 0x00F0BC50
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::GetFileLength(idFileSystemLocal *this, const char *relativePath)
{
  idFile *v4; // r3
  idFile *v5; // r30
  int v6; // r29

  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization");
  if ( relativePath != nullptr && *relativePath != 0 )
  {
    v4 = this->OpenFileRead(this, a2: relativePath, a3: 0, a4: 0);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v6 = v4->Length(this: v4);
      ((void (__fastcall *)(idFile *, int))v5->dtr_idFile)(a1: v5, a2: 1);
      return v6;
    }
  }
  else
  {
    idLib::Warning(fmt: "idFileSystemLocal::GetFileLength with empty name");
  }
  return -1;
}


// ========================================================================
// $LN24_8
// EA  : 0x82F0BD28
// RVA : 0x00F0BD28
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN24_8()
{
  int v0; // r12

  idLoadScreen::Shutdown(this: (idLoadScreen *)(v0 - 128 + 80));
}


// ========================================================================
// ?OpenFileAppend@idFileSystemLocal@@UAAPAVidFile@@PBDW4fsPath_t@@@Z
// EA  : 0x82F0BD58
// RVA : 0x00F0BD58
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile_Permanent *__fastcall idFileSystemLocal::OpenFileAppend(
        idFileSystemLocal *this,
        const char *relativePath,
        fsPath_t basePath)
{
  idFile_Permanent *v6; // r30
  idFile_Permanent *v7; // r3
  idStr v9[2]; // [sp+60h] [-50h] BYREF

  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  if ( fs_readOnly.valueInteger != 0 )
    return nullptr;
  idFileSystemLocal::BuildOSPath(this: (idFileSystemLocal *)v9, result: (idStr *)this, fsPath: basePath, relativePath);
  if ( fs_debug.valueInteger != 0 )
    idLib::Printf(fmt: "idFileSystem::OpenFileAppend: %s\n", v9[0].data);
  if ( idStr::Icmpn(s1: v9[0].data, s2: "nfs:", n: 4) != 0 )
  {
    if ( idStr::Icmpn(s1: v9[0].data, s2: "mtp:", n: 4) == 0 )
    {
      v6 = (idFile_Permanent *)idFileSystemLocal::OpenFromMTP(this, path: v9[0].data, mode: FS_APPEND);
      goto LABEL_18;
    }
    this->CreateOSPath(this, a2: v9[0].data);
    v7 = (idFile_Permanent *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x68u,
                               tag: TAG_FILE,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
      v6 = idFile_Permanent::idFile_Permanent(this: v7, relativePath, osPath: v9[0].data, m: FS_APPEND, create: false);
    else
      v6 = nullptr;
    if ( idFile_Permanent::IsOpen(this: v6) )
      goto LABEL_18;
    if ( v6 != nullptr )
      ((void (__fastcall *)(idFile_Permanent *, int))v6->dtr_idFile)(a1: v6, a2: 1);
    idStr::FreeData(this: v9);
    return nullptr;
  }
  v6 = (idFile_Permanent *)idFileSystemLocal::OpenFromNFS(this, path: v9[0].data, mode: FS_APPEND, create: true);
LABEL_18:
  idStr::FreeData(this: v9);
  return v6;
}


// ========================================================================
// $LN56_4
// EA  : 0x82F0BF20
// RVA : 0x00F0BF20
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN56_4()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$121815
// EA  : 0x82F0BF48
// RVA : 0x00F0BF48
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_121815()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_FILE);
}


// ========================================================================
// ??1idCachedZipFile@@QAA@XZ
// EA  : 0x82F0BF80
// RVA : 0x00F0BF80
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idCachedZipFile::~idCachedZipFile(idCachedZipFile *this)
{
  idZippedFile *fileList; // r3
  idZippedFile **p_next; // r29
  void *handle; // r3

  fileList = this->fileList;
  if ( fileList != nullptr )
  {
    p_next = &fileList[-1].next;
    `eh vector destructor iterator'(
      ptr: fileList,
      size: 0x28u,
      count: (int)fileList[-1].next,
      pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
    idMem::Free(this: &mem, ptr: p_next, align: ALIGN_16);
  }
  handle = this->handle;
  if ( handle != nullptr )
    unzClose(file: handle);
  idStr::FreeData(this: &this->relativeZipFileName);
  idStr::FreeData(this: &this->zipFileName);
}


// ========================================================================
// __unwind$122322
// EA  : 0x82F0BFF8
// RVA : 0x00F0BFF8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122322()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$122323
// EA  : 0x82F0C020
// RVA : 0x00F0C020
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122323()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// ??0idFileSystemLocal@@QAA@XZ
// EA  : 0x82F0C1C0
// RVA : 0x00F0C1C0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFileSystemLocal *__fastcall idFileSystemLocal::idFileSystemLocal(idFileSystemLocal *this)
{
  this->__vftable = (idFileSystemLocal_vtbl *)&idFileSystemLocal::`vftable';
  this->searchPaths.granularity = 0;
  this->searchPaths.memTag = 48;
  this->searchPaths.listStatic = 0;
  this->searchPaths.list = nullptr;
  this->searchPaths.size = 0;
  this->searchPaths.num = 0;
  this->pathBase.data = this->pathBase.baseBuffer;
  this->pathBase.allocedAndFlag = 20;
  this->pathBase.len = 0;
  this->pathBase.baseBuffer[0] = 0;
  this->pathCache.data = this->pathCache.baseBuffer;
  this->pathCache.allocedAndFlag = 20;
  this->pathCache.len = 0;
  this->pathCache.baseBuffer[0] = 0;
  this->pathInstall.data = this->pathInstall.baseBuffer;
  this->pathInstall.allocedAndFlag = 20;
  this->pathInstall.len = 0;
  this->pathInstall.baseBuffer[0] = 0;
  this->pathSave.allocedAndFlag = 20;
  this->pathSave.data = this->pathSave.baseBuffer;
  this->pathSave.len = 0;
  this->pathSave.baseBuffer[0] = 0;
  this->cachedZipFiles = nullptr;
  this->loadCount = 0;
  this->loadStack = 0;
  this->preCallback = nullptr;
  this->postCallback = nullptr;
  this->cacheCallback = nullptr;
  this->patchCallback = nullptr;
  return this;
}


// ========================================================================
// __unwind$122453
// EA  : 0x82F0C28C
// RVA : 0x00F0C28C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122453()
{
  int v0; // r12

  idFileSystem::~idFileSystem(this: *(idFileSystem **)(v0 - 32 + 52));
}


// ========================================================================
// ?SetFilePreCallback@idFileSystemLocal@@UAAXP6APAVidFile@@PBD@Z@Z
// EA  : 0x82F0C2B8
// RVA : 0x00F0C2B8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::SetFilePreCallback(
        idFileSystemLocal *this,
        idFile *(__fastcall *callback)(const char *))
{
  this->preCallback = callback;
}


// ========================================================================
// ?SetFilePostCallback@idFileSystemLocal@@UAAXP6AXPBDPAVidFile@@@Z@Z
// EA  : 0x82F0C2C0
// RVA : 0x00F0C2C0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::SetFilePostCallback(
        idFileSystemLocal *this,
        void (__fastcall *callback)(const char *, idFile *))
{
  this->postCallback = callback;
}


// ========================================================================
// ?SetFileCacheCallback@idFileSystemLocal@@UAAXP6APAVidFile@@PBD@Z1@Z
// EA  : 0x82F0C2C8
// RVA : 0x00F0C2C8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::SetFileCacheCallback(
        idFileSystemLocal *this,
        idFile *(__fastcall *callback)(const char *),
        idFile *(__fastcall *statCallback)(const char *))
{
  this->cacheCallback = callback;
  this->cacheStatCallback = statCallback;
}


// ========================================================================
// ?SetFilePatchCallback@idFileSystemLocal@@UAAXP6APAVidFile@@PBD@Z@Z
// EA  : 0x82F0C2D8
// RVA : 0x00F0C2D8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::SetFilePatchCallback(
        idFileSystemLocal *this,
        idFile *(__fastcall *callback)(const char *))
{
  this->patchCallback = callback;
}


// ========================================================================
// ?CopyGameFile@idFileSystemLocal@@UAA_NPBD0W4fsPath_t@@@Z
// EA  : 0x82F0C348
// RVA : 0x00F0C348
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall idFileSystemLocal::CopyGameFile(
        idFileSystemLocal *this,
        const char *fromRelativePath,
        const char *toRelativePath,
        fsPath_t basePath)
{
  idFile *v8; // r3
  idFile *v9; // r29
  BOOL v10; // r30
  idFileSystemLocal varB0; // [sp+50h] [-B0h] BYREF

  idFileSystemLocal::BuildOSPath(this: &varB0, result: (idStr *)this, fsPath: basePath, relativePath: toRelativePath);
  this->CreateOSPath(this, a2: (const char *)varB0.searchPaths.list);
  idFile_Permanent::idFile_Permanent(
    this: (idFile_Permanent *)&varB0.pathBase,
    relativePath: toRelativePath,
    osPath: (const char *)varB0.searchPaths.list,
    m: FS_WRITE,
    create: true);
  if ( idFile_Permanent::IsOpen(this: (idFile_Permanent *)&varB0.pathBase) )
  {
    v8 = this->OpenFileRead(this, a2: fromRelativePath, a3: 0, a4: 0);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v10 = idFileSystemLocal::CopyGameFile(this, src: v8, dst: (idFile *)&varB0.pathBase);
      ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
      idFile_Permanent::~idFile_Permanent(this: (idFile_Permanent *)&varB0.pathBase);
      idStr::FreeData(this: (idStr *)&varB0);
      return v10;
    }
    else
    {
      idLib::Warning(fmt: "Couldn't open input file, %s", fromRelativePath);
      idFile_Permanent::~idFile_Permanent(this: (idFile_Permanent *)&varB0.pathBase);
      idStr::FreeData(this: (idStr *)&varB0);
      return false;
    }
  }
  else
  {
    idLib::Warning(fmt: "Couldn't open output file, %s", (const char *)varB0.searchPaths.list);
    idFile_Permanent::~idFile_Permanent(this: (idFile_Permanent *)&varB0.pathBase);
    idStr::FreeData(this: (idStr *)&varB0);
    return false;
  }
}


// ========================================================================
// __unwind$122607
// EA  : 0x82F0C480
// RVA : 0x00F0C480
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122607()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$122608
// EA  : 0x82F0C4A8
// RVA : 0x00F0C4A8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122608()
{
  int v0; // r12

  idFile_Permanent::~idFile_Permanent(this: (idFile_Permanent *)(v0 - 256 + 112));
}


// ========================================================================
// ?Copy_f@idFileSystemLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82F0C4D0
// RVA : 0x00F0C4D0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::Copy_f(const idCmdArgs *args)
{
  if ( args->argc == 3 )
    idFileSystemLocal::CopyGameFile(
      this: &fileSystemLocal,
      fromRelativePath: args->argv[1],
      toRelativePath: args->argv[2],
      basePath: FSPATH_BASE);
  else
    idLib::Printf(fmt: "Usage: copy <src> <dst> (os paths)\n");
}


// ========================================================================
// ?BenchmarkGameData@@YAXXZ
// EA  : 0x82F0C508
// RVA : 0x00F0C508
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall BenchmarkGameData()
{
  idFile *v0; // r3
  unsigned int v1; // r28
  __int64 v2; // r6
  void *v3; // r27
  int v4; // r30
  _QWORD *v5; // r29
  int v6; // r23
  __int64 v7; // r7
  int v8; // r30
  _BYTE *v9; // r29
  int v10; // r8
  int v11; // r7
  int v12; // r6
  __int64 v13; // r10
  __int64 v14; // r4
  __int64 v15; // r11
  __int64 v16; // r30
  const char *v17; // r4
  idFileLocal v18; // [sp+50h] [-B0h] BYREF
  idSort_Quick<__int64,idSort_Int64> v19; // [sp+54h] [-ACh] BYREF
  _BYTE v20[8]; // [sp+58h] [-A8h] BYREF
  __int64 v21[20]; // [sp+60h] [-A0h] BYREF

  if ( idStr::Icmpn(s1: fs_basepath.valueString.data, s2: "mtp:", n: 4) != 0 )
  {
    if ( idStr::Icmpn(s1: fs_basepath.valueString.data, s2: "nfs:", n: 4) != 0 )
    {
      v0 = fileSystem->OpenFileRead(this: fileSystem, a2: "base/gameresources.resources", a3: 1, a4: 0);
      v18.file = v0;
      if ( v0 != nullptr )
      {
        v1 = (v0->Length(this: v0) - 0x10000) & 0xFFFF0000;
        if ( (int)(v1 - 10485760) >= 0 )
        {
          idLib::Printf(fmt: "BenchmarkGameData: ofs 0 and 0x%lldx \n", v2);
          v3 = idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\filesystem\\FileSystem.cpp(1522) : TAG_FILE",
                 size: 0x10000u,
                 tag: TAG_FILE,
                 zeroBuffer: false,
                 align: ALIGN_128,
                 heap: HEAP_DEFAULTHEAP);
          v4 = 0;
          v5 = v20;
          do
          {
            v6 = Sys_Microseconds() >> 32;
            v18.file->ReadOfs(this: v18.file, a2: v1 - v4, a3: v3, a4: 0x10000u);
            LODWORD(v7) = (Sys_Microseconds() >> 32) - v6;
            v4 += 0x100000;
            *++v5 = v7;
          }
          while ( v4 < 10485760 );
          idMem::Free(this: &mem, ptr: v3, align: ALIGN_128);
          v8 = 10;
          v9 = v20;
          do
          {
            v9 += 8;
            idLib::Printf(fmt: *(const char **)v9, *((_DWORD *)v9 + 1));
            --v8;
          }
          while ( v8 != 0 );
          LODWORD(v13) = &idSort_Int64::`vftable';
          v19.__vftable = (idSort_Quick<__int64,idSort_Int64>_vtbl *)&idSort_Int64::`vftable';
          HIDWORD(v13) = idSort_Quick<__int64,idSort_Int64>::Sort;
          idSort_Quick<__int64,idSort_Int64>::Sort(this: &v19, base: v21, num: 0xAu, a4: v12, a5: v11, a6: v10, a7: v13);
          HIDWORD(v14) = HIDWORD(v21[5]) + 5384;
          HIDWORD(v15) = v21[8];
          v19.__vftable = (idSort_Quick<__int64,idSort_Int64>_vtbl *)HIDWORD(v21[7]);
          LODWORD(v15) = HIDWORD(v21[2])
                       + LODWORD(v21[2])
                       + HIDWORD(v21[4])
                       + LODWORD(v21[4])
                       + HIDWORD(v21[6])
                       + HIDWORD(v21[8])
                       + LODWORD(v21[7])
                       + LODWORD(v21[8]);
          LODWORD(v14) = ((unsigned __int64)(v15 >> 2) >> 61) + v15;
          v16 = v14 >> 3;
          idLib::Printf(fmt: (const char *)(HIDWORD(v21[5]) + 5384), (unsigned int)(v14 >> 3));
          fileBenchmarkImpliesGameIsOnHD = (int)v16 < fs_benchmarkSeekMicroseconds.valueInteger;
          if ( (int)v16 >= fs_benchmarkSeekMicroseconds.valueInteger )
            v17 = "false";
          else
            v17 = "true";
          idLib::Printf(fmt: "fileBenchmarkImpliesGameIsOnHD: %s\n", v17);
        }
        else
        {
          idLib::Printf(fmt: "BenchmarkGameData: resource file was too small?\n");
        }
      }
      idFileLocal::~idFileLocal(this: &v18);
    }
    else
    {
      idLib::Printf(
        fmt: "%s - Not benchmarking game resources because we are using the NFS server\n",
        "BenchmarkGameData");
    }
  }
  else
  {
    idLib::Printf(
      fmt: "%s - Not benchmarking game resources because we are using the MTP server\n",
      "BenchmarkGameData");
  }
}


// ========================================================================
// __unwind$122784
// EA  : 0x82F0C7BC
// RVA : 0x00F0C7BC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122784()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$122785
// EA  : 0x82F0C7E4
// RVA : 0x00F0C7E4
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122785()
{
  int v0; // r12

  idSort_Int64::~idSort_Int64(this: (idSort_Int64 *)(v0 - 256 + 84));
}


// ========================================================================
// ?benchmarkGameData_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F0C810
// RVA : 0x00F0C810
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

// attributes: thunk
void __fastcall benchmarkGameData_f(const idCmdArgs *args)
{
  BenchmarkGameData();
}


// ========================================================================
// ?ReadFileFromZip@idFileSystemLocal@@AAAPAVidFile_InZip@@PAVidCachedZipFile@@PBD_N@Z
// EA  : 0x82F0C820
// RVA : 0x00F0C820
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile_InZip *__fastcall idFileSystemLocal::ReadFileFromZip(
        idFileSystemLocal *this,
        idCachedZipFile *zip,
        char *relativePath,
        bool allowCopyFiles)
{
  idStr *v6; // r3
  idZippedFile *v7; // r27
  idFile_InZip *v9; // r3
  idFile_InZip *v10; // r30
  void *v11; // r3
  idStr *v12; // r3
  idStr *v13; // r24
  size_t len; // r29
  int *z; // r29
  int v16; // r24
  unsigned __int16 v17; // [sp+50h] [-110h]
  unsigned __int16 v18; // [sp+54h] [-10Ch]
  tm v19; // [sp+60h] [-100h] BYREF
  idStr v20; // [sp+90h] [-D0h] BYREF
  idStr v21; // [sp+B0h] [-B0h] BYREF
  idStr v22; // [sp+D0h] [-90h] BYREF
  idStr v23[3]; // [sp+F0h] [-70h] BYREF

  idStr::idStr(this: &v20, text: relativePath);
  idStr::ToLower(this: &v20);
  idStr::BackSlashesToSlashes(this: &v20);
  v6 = operator+(result: &v21, a: &zip->relativeZipFileName, b: "/");
  idStr::StripLeading(this: &v20, string: v6->data);
  idStr::FreeData(this: &v21);
  v7 = zip->hashTable.ptr[idStr::FileNameHash(string: v20.data, hashSize: 128)];
  if ( v7 != nullptr )
  {
    while ( idStr::IcmpPath(s1: v7->name.data, s2: v20.data) != 0 )
    {
      v7 = v7->next;
      if ( v7 == nullptr )
        goto LABEL_4;
    }
    v9 = (idFile_InZip *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x58u,
                           tag: TAG_FILE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v9 != nullptr )
      v10 = idFile_InZip::idFile_InZip(this: v9);
    else
      v10 = nullptr;
    v11 = unzReOpen(path: zip->zipFileName.data, file: zip->handle, retryOnOpen: fs_shareRetry.valueInteger != 0);
    v10->z = v11;
    if ( v11 == nullptr )
      idLib::FatalError(fmt: "Couldn't reopen %s", zip->zipFileName.data);
    idStr::operator=(this: &v10->name, text: relativePath);
    v12 = operator+(result: &v22, a: &zip->zipFileName, b: "/");
    v13 = operator+(result: v23, a: v12, b: relativePath);
    len = v13->len;
    idStr::EnsureAlloced(this: &v10->fullPath, amount: v13->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v10->fullPath.data, Src: v13->data, Size: len);
    v10->fullPath.data[len] = 0;
    v10->fullPath.len = len;
    idStr::FreeData(this: v23);
    idStr::FreeData(this: &v22);
    z = (int *)v10->z;
    v16 = *z;
    unzSetCurrentFileInfoPosition(file: zip->handle, pos: v7->pos);
    memcpy(Dst: z, Src: zip->handle, Size: 0x80u);
    *z = v16;
    unzOpenCurrentFile(file: v10->z);
    v10->zipFilePos = v7->pos;
    v10->fileSize = z[17];
    LOBYTE(v18) = *((_WORD *)z + 28);
    HIBYTE(v17) = *((_WORD *)z + 29);
    HIBYTE(v18) = v18;
    LOBYTE(v17) = HIBYTE(*((_WORD *)z + 29));
    v19.tm_isdst = -1;
    v19.tm_wday = 0;
    v19.tm_yday = 0;
    v19.tm_sec = (2 * v18) & 0x3E;
    v19.tm_min = (v18 >> 5) & 0x3F;
    v19.tm_hour = v18 >> 11;
    v19.tm_mday = v17 & 0x1F;
    v19.tm_mon = ((v17 >> 5) & 0xF) - 1;
    v19.tm_year = (v17 >> 9) + 80;
    v10->timeStamp = (unsigned __int64)mktime64(tb: &v19) >> 32;
    if ( fs_debug.valueInteger != 0 )
      idLib::Printf(fmt: "idFileSystem::OpenFileRead: %s (found in '%s')\n", relativePath, zip->zipFileName.data);
    idStr::FreeData(this: &v20);
    return v10;
  }
  else
  {
LABEL_4:
    idStr::FreeData(this: &v20);
    return nullptr;
  }
}


// ========================================================================
// $LN91_0
// EA  : 0x82F0CAD8
// RVA : 0x00F0CAD8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN91_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 144));
}


// ========================================================================
// __unwind$122920
// EA  : 0x82F0CB00
// RVA : 0x00F0CB00
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122920()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 176));
}


// ========================================================================
// __unwind$122921
// EA  : 0x82F0CB28
// RVA : 0x00F0CB28
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122921()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 352 + 84), tag: TAG_FILE);
}


// ========================================================================
// __unwind$122922
// EA  : 0x82F0CB54
// RVA : 0x00F0CB54
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122922()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 208));
}


// ========================================================================
// __unwind$122923
// EA  : 0x82F0CB7C
// RVA : 0x00F0CB7C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_122923()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 240));
}


// ========================================================================
// ?OpenFileRead@idFileSystemLocal@@UAAPAVidFile@@PBD_N1@Z
// EA  : 0x82F0CBB0
// RVA : 0x00F0CBB0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile *__fastcall idFileSystemLocal::OpenFileRead(
        idFileSystemLocal *this,
        char *relativePath,
        bool allowCopyFiles,
        bool nonBuffered)
{
  idFile *(__fastcall *patchCallback)(const char *); // r11
  char *v6; // r23
  idFile *result; // r3
  idFile *(__fastcall *preCallback)(const char *); // r11
  int v11; // r29
  char *v12; // r11
  int v13; // r10
  idFile *(__fastcall *cacheCallback)(const char *); // r11
  idFile *(__fastcall *cacheStatCallback)(const char *); // r11
  char *v16; // r3
  int i; // r11
  int v18; // r11
  idFile *v19; // r20
  int v20; // r28
  int v21; // r29
  idFile_Permanent *v22; // r3
  idFile_Permanent *v23; // r30
  idCachedZipFile *j; // r30
  int len; // r11
  idFile_InZip *FileFromZip; // r11
  int v27; // r28
  int v28; // r29
  idCachedZipFile *cachedZipFiles; // r30
  int v30; // r11
  idFile_Permanent *v31; // r3
  idFile_Permanent *v32; // r30
  idCachedZipFile *ZipFile; // r4
  idFile_InZip *v34; // r11
  void (__fastcall *postCallback)(const char *, idFile *); // r11
  idStr v36; // [sp+50h] [-120h] BYREF
  idFile_Permanent *v37; // [sp+70h] [-100h]
  idFileSystemLocal v38; // [sp+80h] [-F0h] BYREF

  patchCallback = this->patchCallback;
  v6 = relativePath;
  if ( patchCallback != nullptr )
  {
    result = patchCallback(a1: relativePath);
    if ( result != nullptr )
      return result;
  }
  preCallback = this->preCallback;
  if ( preCallback != nullptr && allowCopyFiles )
  {
    v11 = (int)preCallback(a1: v6);
    v12 = v6;
    do
      v13 = (unsigned __int8)*v12++;
    while ( v13 != 0 );
    if ( (unsigned int)(v12 - v6 - 1) <= 8 || strstr(str1: v6, str2: ".loadout") != v12 - 9 )
      return (idFile *)v11;
  }
  cacheCallback = this->cacheCallback;
  if ( cacheCallback != nullptr && allowCopyFiles )
  {
    result = cacheCallback(a1: v6);
    if ( result != nullptr )
      return result;
  }
  else
  {
    cacheStatCallback = this->cacheStatCallback;
    if ( cacheStatCallback != nullptr && !allowCopyFiles )
    {
      result = cacheStatCallback(a1: v6);
      if ( result != nullptr )
        return result;
    }
  }
  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  if ( v6 == nullptr )
    idLib::FatalError(fmt: "idFileSystemLocal::OpenFileRead: NULL 'relativePath' parameter passed\n");
  v16 = strstr(str1: v6, str2: "base");
  if ( v16 == v6 || v16 == v6 + 1 )
  {
    for ( i = *v16; i != 47; i = *++v16 )
    {
      if ( i == 92 )
        break;
    }
    v6 = v16;
  }
  v18 = *v6;
  if ( v18 == 47 && v6[1] != 47 || v18 == 92 && v6[1] != 92 )
    ++v6;
  if ( *v6 == 0 )
    return nullptr;
  v38.pathBase.len = 0;
  v19 = nullptr;
  v38.pathBase.baseBuffer[0] = 0;
  v38.pathBase.allocedAndFlag = 20;
  v38.pathBase.data = v38.pathBase.baseBuffer;
  v20 = 0;
  if ( this->searchPaths.num <= 0 )
    goto LABEL_53;
  v21 = 0;
  while ( 1 )
  {
    idFileSystemLocal::BuildOSPath(
      this: &v38,
      result: (idStr *)this,
      base: this->searchPaths.list[v21].data,
      relativePath: v6);
    if ( idStr::Icmpn(s1: (const char *)v38.searchPaths.list, s2: "mtp:", n: 4) == 0 )
    {
      v19 = idFileSystemLocal::OpenFromMTP(this, path: (const char *)v38.searchPaths.list, mode: FS_READ);
      if ( v19 != nullptr )
        goto LABEL_50;
      goto LABEL_47;
    }
    if ( idStr::Icmpn(s1: (const char *)v38.searchPaths.list, s2: "nfs:", n: 4) != 0 )
      break;
    v19 = idFileSystemLocal::OpenFromNFS(this, path: (const char *)v38.searchPaths.list, mode: FS_READ, create: false);
    if ( v19 != nullptr )
      goto LABEL_50;
LABEL_47:
    idStr::FreeData(this: (idStr *)&v38);
    ++v20;
    ++v21;
    if ( v20 >= this->searchPaths.num )
      goto LABEL_53;
  }
  v22 = (idFile_Permanent *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x68u,
                              tag: TAG_FILE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v37 = v22;
  if ( v22 != nullptr )
    v23 = idFile_Permanent::idFile_Permanent(
            this: v22,
            relativePath: v6,
            osPath: (const char *)v38.searchPaths.list,
            m: !nonBuffered ? FS_READ : FS_READ_NO_BUFFERING,
            create: false);
  else
    v23 = nullptr;
  if ( !idFile_Permanent::IsOpen(this: v23) )
  {
    if ( v23 != nullptr )
      ((void (__fastcall *)(idFile_Permanent *, int))v23->dtr_idFile)(a1: v23, a2: 1);
    goto LABEL_47;
  }
  v19 = v23;
LABEL_50:
  if ( fs_debug.valueInteger != 0 )
    idLib::Printf(fmt: "idFileSystem::OpenFileRead: %s (found in '%s')\n", v6, this->searchPaths.list[v20].data);
  idStr::operator=(this: &v38.pathBase, text: (const idStr *)&v38);
  idStr::FreeData(this: (idStr *)&v38);
LABEL_53:
  if ( fs_arbitraryZipSupport.valueInteger == 0 )
    goto LABEL_91;
  idStr::idStr(this: &v36, text: v6);
  idStr::ToLower(this: &v36);
  idStr::BackSlashesToSlashes(this: &v36);
  idStr::StripFilename(this: &v36);
  idStr::StripTrailing(this: &v36, c: 47);
  idStr::StripTrailing(this: &v36, string: "/_combo");
  if ( v19 != nullptr )
    goto LABEL_90;
  for ( j = this->cachedZipFiles; j != nullptr; j = j->next )
  {
    len = j->relativeZipFileName.len;
    if ( v36.len > len )
      len = v36.len;
    if ( idStr::IcmpnPath(s1: j->relativeZipFileName.data, s2: v36.data, n: len) == 0 )
    {
      FileFromZip = idFileSystemLocal::ReadFileFromZip(this, zip: j, relativePath: v6, allowCopyFiles);
      if ( FileFromZip != nullptr )
      {
        v19 = FileFromZip;
        idStr::operator=(this: &v38.pathBase, text: v6);
        goto LABEL_90;
      }
    }
  }
  if ( v36.len <= 0 )
    goto LABEL_90;
  while ( 2 )
  {
    v27 = 0;
    if ( this->searchPaths.num <= 0 )
      goto LABEL_89;
    v28 = 0;
    while ( 2 )
    {
      idFileSystemLocal::BuildOSPath(
        this: (idFileSystemLocal *)&v38.pathCache,
        result: (idStr *)this,
        base: this->searchPaths.list[v28].data,
        relativePath: v36.data);
      idStr::SetFileExtension(this: &v38.pathCache, extension: "pk5");
      cachedZipFiles = this->cachedZipFiles;
      if ( cachedZipFiles != nullptr )
      {
        while ( 1 )
        {
          v30 = cachedZipFiles->relativeZipFileName.len;
          if ( v36.len > v30 )
            v30 = v36.len;
          if ( idStr::IcmpnPath(s1: cachedZipFiles->relativeZipFileName.data, s2: v36.data, n: v30) == 0 )
            break;
          cachedZipFiles = cachedZipFiles->next;
          if ( cachedZipFiles == nullptr )
            goto LABEL_69;
        }
LABEL_83:
        idStr::FreeData(this: &v38.pathCache);
        ++v27;
        ++v28;
        if ( v27 >= this->searchPaths.num )
          goto LABEL_89;
        continue;
      }
      break;
    }
LABEL_69:
    idStr::StripLeading(this: &v38.pathCache, string: "mtp:");
    if ( fs_sourceControlEnable.valueInteger == 0 )
    {
      v31 = (idFile_Permanent *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x68u,
                                  tag: TAG_FILE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      v37 = v31;
      if ( v31 != nullptr )
        v32 = idFile_Permanent::idFile_Permanent(
                this: v31,
                relativePath: v36.data,
                osPath: v38.pathCache.data,
                m: FS_READ,
                create: false);
      else
        v32 = nullptr;
      if ( !idFile_Permanent::IsOpen(this: v32) )
      {
        if ( v32 != nullptr )
          ((void (__fastcall *)(idFile_Permanent *, int))v32->dtr_idFile)(a1: v32, a2: 1);
        goto LABEL_83;
      }
      if ( v32 != nullptr )
        ((void (__fastcall *)(idFile_Permanent *, int))v32->dtr_idFile)(a1: v32, a2: 1);
    }
    ZipFile = idFileSystemLocal::LoadZipFile(this, zipFileName: v38.pathCache.data, relativeZipFileName: v36.data);
    if ( ZipFile == nullptr )
      goto LABEL_83;
    v34 = idFileSystemLocal::ReadFileFromZip(this, zip: ZipFile, relativePath: v6, allowCopyFiles);
    if ( v34 == nullptr )
      goto LABEL_83;
    v19 = v34;
    idStr::operator=(this: &v38.pathBase, text: v6);
    if ( v36.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &v36);
      v36.allocedAndFlag = 20;
      v36.data = v36.baseBuffer;
      v36.len = 0;
      v36.baseBuffer[0] = 0;
    }
    else
    {
      v36.len = 0;
      *v36.data = 0;
    }
    idStr::FreeData(this: &v38.pathCache);
LABEL_89:
    idStr::StripTrailing(this: &v36, c: 47);
    idStr::StripFilename(this: &v36);
    if ( v36.len > 0 )
      continue;
    break;
  }
LABEL_90:
  idStr::FreeData(this: &v36);
LABEL_91:
  if ( v19 == nullptr )
  {
    if ( fs_debug.valueInteger != 0 )
      idLib::Printf(fmt: "Can't find %s\n", v6);
    idStr::FreeData(this: &v38.pathBase);
    return nullptr;
  }
  if ( allowCopyFiles )
  {
    postCallback = this->postCallback;
    if ( postCallback != nullptr && !idLib::dontTrack )
      postCallback(a1: v38.pathBase.data, a2: v19);
  }
  idStr::FreeData(this: &v38.pathBase);
  return v19;
}


// ========================================================================
// $LN246
// EA  : 0x82F0D2FC
// RVA : 0x00F0D2FC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN246()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 160));
}


// ========================================================================
// __unwind$123195
// EA  : 0x82F0D324
// RVA : 0x00F0D324
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123195()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 128));
}


// ========================================================================
// __unwind$123196
// EA  : 0x82F0D34C
// RVA : 0x00F0D34C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123196()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 368 + 112), tag: TAG_FILE);
}


// ========================================================================
// __unwind$123197
// EA  : 0x82F0D378
// RVA : 0x00F0D378
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123197()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$123198
// EA  : 0x82F0D3A0
// RVA : 0x00F0D3A0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123198()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 192));
}


// ========================================================================
// __unwind$123199
// EA  : 0x82F0D3C8
// RVA : 0x00F0D3C8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123199()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 368 + 112), tag: TAG_FILE);
}


// ========================================================================
// ?RemoveDirTree@@YAXPBD@Z
// EA  : 0x82F0D688
// RVA : 0x00F0D688
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall RemoveDirTree(char *ospath)
{
  int v1; // r30
  int v3; // r25
  int v4; // r28
  int i; // r29
  idStr *list; // r29
  int size; // r30
  idStr *v8; // r28
  idList<idStr,5> v9; // [sp+50h] [-B0h] BYREF
  idStr v10; // [sp+60h] [-A0h] BYREF
  idStr v11; // [sp+80h] [-80h] BYREF
  idStr v12[3]; // [sp+A0h] [-60h] BYREF

  v1 = 0;
  *(_WORD *)&v9.memTag = 1280;
  memset(&v9, 0, 14);
  Sys_ListFiles(directory: ospath, extension: "/", list: &v9);
  v3 = 0;
  if ( v9.num > 0 )
  {
    v4 = 0;
    do
    {
      idStr::idStr(this: &v11, text: &v9.list[v4]);
      if ( idStr::Cmp(s1: v11.data, s2: ".") != 0 && idStr::Cmp(s1: v11.data, s2: "..") != 0 )
      {
        idStr::idStr(this: &v10, text: ospath);
        idStr::AppendPath(this: &v10, text: v9.list[v4].data);
        RemoveDirTree(ospath: v10.data);
        idStr::FreeData(this: &v10);
      }
      idStr::FreeData(this: &v11);
      ++v3;
      ++v4;
    }
    while ( v3 < v9.num );
  }
  Sys_ListFiles(directory: ospath, extension: &byte_8200D768, list: &v9);
  for ( i = 0; i < v9.num; ++v1 )
  {
    idStr::idStr(this: v12, text: ospath);
    idStr::AppendPath(this: v12, text: v9.list[v1].data);
    remove(path: v12[0].data);
    idStr::FreeData(this: v12);
    ++i;
  }
  idLobbyBackend360::StartArbitration(pexcept: (_exception *)ospath);
  if ( v9.listStatic == 0 || v9.listStatic == 2 )
  {
    list = v9.list;
    if ( v9.list != nullptr )
    {
      size = v9.size;
      v8 = v9.list;
      if ( v9.size > 0 )
      {
        do
        {
          idStr::FreeData(this: list);
          --size;
          ++list;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$123757
// EA  : 0x82F0D844
// RVA : 0x00F0D844
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123757()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$123758
// EA  : 0x82F0D86C
// RVA : 0x00F0D86C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123758()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$123759
// EA  : 0x82F0D894
// RVA : 0x00F0D894
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123759()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$123760
// EA  : 0x82F0D8BC
// RVA : 0x00F0D8BC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123760()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 160));
}


// ========================================================================
// ?AddUnique@idFileSystemLocal@@ABAHPBDAAV?$idList@VidStr@@$04@@AAVidHashIndex@@@Z
// EA  : 0x82F0D8F0
// RVA : 0x00F0D8F0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::AddUnique(
        idFileSystemLocal *this,
        const char *name,
        idList<idStr,5> *list,
        idHashIndex *hashIndex)
{
  int KeyForString; // r26
  int v8; // r29
  int indexSize; // r11
  int v10; // r6
  idStr v12[3]; // [sp+50h] [-60h] BYREF

  KeyForString = idHashIndex::GenerateKeyForString(this: hashIndex, string: name, caseSensitive: true);
  v8 = hashIndex->hash[hashIndex->hashMask & KeyForString & hashIndex->lookupMask];
  if ( v8 == -1 )
  {
LABEL_4:
    idStr::idStr(this: v12, text: name);
    v8 = idList<idStr,5>::Append(this: list, obj: v12);
    idStr::FreeData(this: v12);
    indexSize = hashIndex->indexSize;
    if ( hashIndex->hash == idHashIndex::INVALID_INDEX )
    {
      if ( v8 >= indexSize )
        indexSize = v8 + 1;
      idHashIndex::Allocate(this: hashIndex, newHashSize: hashIndex->hashSize, newIndexSize: indexSize);
    }
    else if ( v8 >= indexSize )
    {
      idHashIndex::ResizeIndex(this: hashIndex, newIndexSize: v8 + 1);
    }
    v10 = hashIndex->hashMask & KeyForString;
    hashIndex->indexChain[v8] = hashIndex->hash[v10];
    hashIndex->hash[v10] = v8;
  }
  else
  {
    while ( idStr::Icmp(s1: list->list[v8].data, s2: name) != 0 )
    {
      v8 = hashIndex->indexChain[v8 & hashIndex->lookupMask];
      if ( v8 == -1 )
        goto LABEL_4;
    }
  }
  return v8;
}


// ========================================================================
// __unwind$123967
// EA  : 0x82F0DA20
// RVA : 0x00F0DA20
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_123967()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetExtensionList@idFileSystemLocal@@ABAXPBDAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82F0DA50
// RVA : 0x00F0DA50
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::GetExtensionList(
        idFileSystemLocal *this,
        const char *extension,
        idList<idStr,5> *extensionList)
{
  int v5; // r25
  int v6; // r29
  int i; // r28
  char *baseBuffer; // r10
  signed int v9; // r30
  int v10; // r11
  unsigned int v11; // ctr
  idStr v12; // [sp+50h] [-90h] BYREF
  idStr v13[3]; // [sp+70h] [-70h] BYREF

  v5 = 0;
  if ( *extension != 0 )
  {
    do
      ++v5;
    while ( extension[v5] != 0 );
  }
  v6 = 0;
  for ( i = idStr::Find(str: extension, c: 124, start: 0, end: v5);
        i != -1;
        i = idStr::Find(str: extension, c: 124, start: i + 1, end: v5) )
  {
    v12.allocedAndFlag = 20;
    baseBuffer = v12.baseBuffer;
    v12.len = 0;
    v12.baseBuffer[0] = 0;
    v12.data = v12.baseBuffer;
    v9 = (((unsigned int)(i - v6) >> 31) - 1) & (i - v6);
    if ( v9 + 1 > 20 )
    {
      idStr::ReAllocate(this: &v12, amount: v9 + 1, keepold: true);
      baseBuffer = v12.data;
    }
    v10 = 0;
    if ( v9 > 0 )
    {
      v11 = (((unsigned int)(i - v6) >> 31) - 1) & (i - v6);
      do
      {
        baseBuffer[v10] = extension[v6 + v10];
        ++v10;
        baseBuffer = v12.data;
        --v11;
      }
      while ( v11 != 0 );
    }
    baseBuffer[v9] = 0;
    v12.len = (((unsigned int)(i - v6) >> 31) - 1) & (i - v6);
    idList<idStr,5>::Append(this: extensionList, obj: &v12);
    idStr::FreeData(this: &v12);
    v6 = i + 1;
  }
  v13[0].allocedAndFlag = 20;
  v13[0].len = 0;
  v13[0].data = v13[0].baseBuffer;
  v13[0].baseBuffer[0] = 0;
  idStr::CopyRange(this: v13, text: extension, start: v6, end: v5);
  idList<idStr,5>::Append(this: extensionList, obj: v13);
  idStr::FreeData(this: v13);
}


// ========================================================================
// __unwind$124017
// EA  : 0x82F0DBA0
// RVA : 0x00F0DBA0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124017()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$124018
// EA  : 0x82F0DBC8
// RVA : 0x00F0DBC8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124018()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// ?GetFileList@idFileSystemLocal@@AAAHPBDABV?$idList@VidStr@@$04@@AAV2@AAVidHashIndex@@_N@Z
// EA  : 0x82F0DBF8
// RVA : 0x00F0DBF8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::GetFileList(
        idFileSystemLocal *this,
        const char *relativePath,
        const idList<idStr,5> *extensions,
        idList<idStr,5> *list,
        idHashIndex *hashIndex,
        bool fullRelativePath)
{
  const char *v12; // r11
  int v13; // r16
  int v14; // r18
  int v15; // r19
  int v16; // r23
  char *data; // r11
  int Index; // r4
  int v19; // r4
  int v20; // r26
  int v21; // r30
  int num; // r11
  idList<idStr,5> v23; // [sp+50h] [-130h] BYREF
  idStr v24; // [sp+60h] [-120h] BYREF
  idStr v25; // [sp+80h] [-100h] BYREF
  idStr v26; // [sp+A0h] [-E0h] BYREF
  idFileSystemLocal v27; // [sp+C0h] [-C0h] BYREF

  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  if ( extensions->num == 0 || relativePath == nullptr )
    return 0;
  if ( *relativePath != 0 )
  {
    v12 = relativePath;
    do
      ++v12;
    while ( *v12 != 0 );
  }
  v13 = 0;
  if ( this->searchPaths.num > 0 )
  {
    v14 = 0;
    do
    {
      *(_WORD *)&v23.memTag = 1280;
      memset(&v23, 0, 14);
      idFileSystemLocal::BuildOSPath(
        this: &v27,
        result: (idStr *)this,
        base: this->searchPaths.list[v14].data,
        relativePath);
      v15 = 0;
      if ( extensions->num > 0 )
      {
        v16 = 0;
        do
        {
          idFileSystemLocal::ListOSFiles(
            this,
            directory: (const char *)v27.searchPaths.list,
            extension: extensions->list[v16].data,
            list: &v23);
          data = extensions->list[v16].data;
          if ( *data == 47 && data[1] == 0 )
          {
            idStr::idStr(this: &v25, text: ".");
            Index = idList<idStr,5>::FindIndex(this: &v23, obj: &v25, startIndex: 0);
            if ( Index >= 0 )
              idList<idStr,5>::RemoveIndex(this: &v23, index: Index);
            idStr::FreeData(this: &v25);
            idStr::idStr(this: &v26, text: "..");
            v19 = idList<idStr,5>::FindIndex(this: &v23, obj: &v26, startIndex: 0);
            if ( v19 >= 0 )
              idList<idStr,5>::RemoveIndex(this: &v23, index: v19);
            idStr::FreeData(this: &v26);
          }
          v20 = 0;
          if ( v23.num > 0 )
          {
            v21 = 0;
            do
            {
              if ( fullRelativePath )
              {
                idStr::idStr(this: &v24, text: relativePath);
                idStr::Append(this: &v24, text: "/");
                idStr::Append(this: &v24, text: &v23.list[v21]);
                idFileSystemLocal::AddUnique(this, name: v24.data, list, hashIndex);
                idStr::FreeData(this: &v24);
              }
              else
              {
                idFileSystemLocal::AddUnique(this, name: v23.list[v21].data, list, hashIndex);
              }
              ++v20;
              ++v21;
            }
            while ( v20 < v23.num );
          }
          ++v15;
          ++v16;
        }
        while ( v15 < extensions->num );
      }
      idStr::FreeData(this: (idStr *)&v27);
      if ( v23.listStatic == 0 || v23.listStatic == 2 )
      {
        if ( v23.list != nullptr )
          idListArrayDelete<idStr>(ptr: v23.list, num: v23.size);
        v23.list = nullptr;
        v23.size = 0;
      }
      num = this->searchPaths.num;
      ++v13;
      ++v14;
      v23.num = 0;
    }
    while ( v13 < num );
  }
  return list->num;
}


// ========================================================================
// $LN116_1
// EA  : 0x82F0DEB4
// RVA : 0x00F0DEB4
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN116_1()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$124172
// EA  : 0x82F0DEDC
// RVA : 0x00F0DEDC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124172()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 192));
}


// ========================================================================
// __unwind$124173
// EA  : 0x82F0DF04
// RVA : 0x00F0DF04
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124173()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$124174
// EA  : 0x82F0DF2C
// RVA : 0x00F0DF2C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124174()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$124175
// EA  : 0x82F0DF54
// RVA : 0x00F0DF54
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124175()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// ?ListFiles@idFileSystemLocal@@UAAPAVidFileList@@PBD0_N1@Z
// EA  : 0x82F0DF88
// RVA : 0x00F0DF88
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFileList *__fastcall idFileSystemLocal::ListFiles(
        idFileSystemLocal *this,
        const char *relativePath,
        const char *extension,
        bool sort,
        bool fullRelativePath)
{
  char *data; // r11
  int v11; // r10
  const char *v12; // r4
  idFileSystemLocal *v13; // r3
  idFileList *v14; // r3
  idFileList *v15; // r29
  idStr **p_list; // r30
  __int64 v17; // r10
  int v18; // r8
  int v19; // r7
  int v20; // r6
  idStr *v21; // r4
  unsigned int num; // r5
  idSort_Quick<idStr,idSort_PathStr> v24; // [sp+50h] [-420h] BYREF
  idList<idStr,5> v25; // [sp+60h] [-410h] BYREF
  idFileList *v26; // [sp+70h] [-400h]
  idHashIndex v27; // [sp+80h] [-3F0h] BYREF
  idFileSystemLocal v28; // [sp+A0h] [-3D0h] BYREF
  idStrStatic<256> v29; // [sp+1E0h] [-290h] BYREF
  idStrStatic<256> v30; // [sp+300h] [-170h] BYREF

  if ( idLib::production == PROD_BUILDING )
    idLib::FatalError(fmt: "idFileSystemLocal::ListFiles( %s, %s ) in PROD_BUILDING mode", relativePath, extension);
  if ( fs_sourceControlEnable.valueInteger != 0 && idLib::sourceControl != nullptr )
  {
    if ( !idLib::sourceControl->IsInitialized(this: idLib::sourceControl) )
      idLib::sourceControl->Init(this: idLib::sourceControl);
    if ( idLib::sourceControl->IsInitialized(this: idLib::sourceControl) )
    {
      data = fs_sourceControlWorkspace.valueString.data;
      do
        v11 = (unsigned __int8)*data++;
      while ( v11 != 0 );
      if ( data - fs_sourceControlWorkspace.valueString.data != 1 )
        ((void (__fastcall *)(idSourceControl *))idLib::sourceControl->SetWorkspace)(a1: idLib::sourceControl);
      v28.pathBase.baseBuffer[0] = 0;
      HIBYTE(v28.pathCache.len) = 0;
      v28.pathBase.len = 0;
      v28.pathBase.data = (char *)&v28.pathCache;
      v28.pathBase.allocedAndFlag = -2147483392;
      idStrStatic<256>::idStrStatic<256>(this: &v29, text: relativePath);
      v28.pathBase.len = v29.len;
      memcpy(Dst: v28.pathBase.data, Src: v29.data, Size: v29.len + 1);
      idStr::FreeData(this: &v29);
      idStr::MakeNameCanonical(this: &v28.pathBase);
      idStr::StripTrailing(this: &v28.pathBase, c: 47);
      idStr::operator+=(this: &v28.pathBase, a: 47);
      idStr::operator+=(this: &v28.pathBase, a: 42);
      if ( extension != nullptr && *extension != 0 )
        v12 = extension;
      else
        v12 = "*";
      idStr::SetFileExtension(this: &v28.pathBase, extension: v12);
      v13 = idFileSystemLocal::BuildOSPath(
              this: &v28,
              result: (idStr *)this,
              fsPath: FSPATH_BASE,
              relativePath: v28.pathBase.data);
      idStrStatic<256>::idStrStatic<256>(this: &v30, text: (const idStr *)v13);
      idStr::FreeData(this: (idStr *)&v28);
      idLib::sourceControl->UpdateFolder(this: idLib::sourceControl, a2: v30.data);
      idStr::FreeData(this: &v30);
      idStr::FreeData(this: &v28.pathBase);
    }
  }
  v14 = (idFileList *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x30u,
                        tag: TAG_FILE,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v26 = v14;
  if ( v14 != nullptr )
    v15 = idFileList::idFileList(this: v14);
  else
    v15 = nullptr;
  idStr::operator=(this: &v15->basePath, text: relativePath);
  *(_WORD *)&v25.memTag = 1280;
  memset(&v25, 0, 14);
  idFileSystemLocal::GetExtensionList(this, extension, extensionList: &v25);
  v27.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &v27, initialHashSize: 4096, initialIndexSize: 4096);
  p_list = &v15->list.list;
  idFileSystemLocal::GetFileList(
    this,
    relativePath,
    extensions: &v25,
    list: (idList<idStr,5> *)&v15->list,
    hashIndex: &v27,
    fullRelativePath);
  if ( sort )
  {
    v24.__vftable = (idSort_Quick<idStr,idSort_PathStr>_vtbl *)&idSort_PathStr::`vftable';
    v21 = *p_list;
    if ( *p_list != nullptr )
    {
      num = v15->list.num;
      v26 = (idFileList *)*p_list;
      HIDWORD(v17) = sort;
      idSort_Quick<idStr,idSort_PathStr>::Sort(this: &v24, base: v21, num, a4: v20, a5: v19, a6: v18, a7: v17);
    }
    v24.__vftable = (idSort_Quick<idStr,idSort_PathStr>_vtbl *)&idSort<idStr>::`vftable';
  }
  idHashIndex::Free(this: &v27);
  idList<idStr,99>::~idList<idStr,99>(this: &v25);
  return v15;
}


// ========================================================================
// $LN113_2
// EA  : 0x82F0E294
// RVA : 0x00F0E294
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN113_2()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1136 + 192));
}


// ========================================================================
// __unwind$124454
// EA  : 0x82F0E2BC
// RVA : 0x00F0E2BC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124454()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1136 + 160));
}


// ========================================================================
// __unwind$124455
// EA  : 0x82F0E2E4
// RVA : 0x00F0E2E4
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124455()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1136 + 768));
}


// ========================================================================
// __unwind$124456
// EA  : 0x82F0E30C
// RVA : 0x00F0E30C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124456()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1136 + 112), tag: TAG_FILE);
}


// ========================================================================
// __unwind$124457
// EA  : 0x82F0E338
// RVA : 0x00F0E338
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124457()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1136 + 96));
}


// ========================================================================
// __unwind$124458
// EA  : 0x82F0E360
// RVA : 0x00F0E360
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124458()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(v0 - 1136 + 128));
}


// ========================================================================
// __unwind$124459
// EA  : 0x82F0E388
// RVA : 0x00F0E388
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124459()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 1136 + 80));
}


// ========================================================================
// ?GetFileListTree@idFileSystemLocal@@AAAHPBDABV?$idList@VidStr@@$04@@AAV2@AAVidHashIndex@@@Z
// EA  : 0x82F0E3B8
// RVA : 0x00F0E3B8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::GetFileListTree(
        idFileSystemLocal *this,
        const char *relativePath,
        const idList<idStr,5> *extensions,
        idList<idStr,5> *list,
        idHashIndex *hashIndex)
{
  idStr *v10; // r23
  char **p_data; // r30
  int i; // r24
  int num; // r26
  int size; // r30
  idStr *v15; // r29
  idStr *v16; // r28
  int v17; // r30
  idStr *v18; // r29
  idList<idStr,5> v20; // [sp+50h] [-B0h] BYREF
  idList<idStr,5> v21; // [sp+60h] [-A0h] BYREF
  idHashIndex v22; // [sp+70h] [-90h] BYREF
  idStr v23[3]; // [sp+90h] [-70h] BYREF

  *(_WORD *)&v21.memTag = 1280;
  memset(&v21, 0, 14);
  *(_WORD *)&v20.memTag = 1280;
  memset(&v20, 0, 14);
  v22.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &v22, initialHashSize: 1024, initialIndexSize: 128);
  idStr::idStr(this: v23, text: "/");
  idList<idStr,5>::Append(this: &v21, obj: v23);
  idStr::FreeData(this: v23);
  idFileSystemLocal::GetFileList(
    this,
    relativePath,
    extensions: &v21,
    list: &v20,
    hashIndex: &v22,
    fullRelativePath: true);
  v10 = v20.list;
  if ( v20.num > 0 )
  {
    p_data = &v20.list->data;
    for ( i = v20.num; i != 0; --i )
    {
      if ( **p_data != 46 && idStr::Icmp(s1: *p_data, s2: relativePath) != 0 )
        idFileSystemLocal::GetFileListTree(this, relativePath: *p_data, extensions, list, hashIndex);
      p_data += 8;
    }
  }
  idFileSystemLocal::GetFileList(this, relativePath, extensions, list, hashIndex, fullRelativePath: true);
  num = list->num;
  idHashIndex::Free(this: &v22);
  if ( (v20.listStatic == 0 || v20.listStatic == 2) && v10 != nullptr )
  {
    size = v20.size;
    if ( v20.size > 0 )
    {
      v15 = v10;
      do
      {
        idStr::FreeData(this: v15);
        --size;
        ++v15;
      }
      while ( size != 0 );
    }
    idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
  }
  if ( v21.listStatic == 0 || v21.listStatic == 2 )
  {
    v16 = v21.list;
    if ( v21.list != nullptr )
    {
      v17 = v21.size;
      if ( v21.size > 0 )
      {
        v18 = v21.list;
        do
        {
          idStr::FreeData(this: v18);
          --v17;
          ++v18;
        }
        while ( v17 != 0 );
      }
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
    }
  }
  return num;
}


// ========================================================================
// __unwind$124722
// EA  : 0x82F0E5A8
// RVA : 0x00F0E5A8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124722()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$124723
// EA  : 0x82F0E5D0
// RVA : 0x00F0E5D0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124723()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$124724
// EA  : 0x82F0E5F8
// RVA : 0x00F0E5F8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124724()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$124725
// EA  : 0x82F0E620
// RVA : 0x00F0E620
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124725()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// ?ListFilesTree@idFileSystemLocal@@UAAPAVidFileList@@PBD0_N@Z
// EA  : 0x82F0E650
// RVA : 0x00F0E650
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFileList *__fastcall idFileSystemLocal::ListFilesTree(
        idFileSystemLocal *this,
        const char *relativePath,
        const char *extension,
        bool sort)
{
  _DWORD *v8; // r3
  _DWORD *v9; // r26
  idStr **v10; // r29
  __int64 v11; // r10
  int v12; // r8
  int v13; // r7
  int v14; // r6
  idStr *v15; // r4
  unsigned int v16; // r5
  idSort_Quick<idStr,idSort_PathStr> v18; // [sp+50h] [-90h] BYREF
  idStr *v19; // [sp+54h] [-8Ch]
  idList<idStr,5> v20; // [sp+60h] [-80h] BYREF
  idHashIndex v21[3]; // [sp+70h] [-70h] BYREF

  v21[0].memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: v21, initialHashSize: 4096, initialIndexSize: 4096);
  *(_WORD *)&v20.memTag = 1280;
  memset(&v20, 0, 14);
  v8 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0x30u,
         tag: TAG_FILE,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
  {
    *v8 = 0;
    v8[2] = 20;
    v8[1] = v8 + 3;
    *((_BYTE *)v8 + 12) = 0;
    *((_WORD *)v8 + 22) = 0;
    *((_BYTE *)v8 + 46) = 48;
    *((_BYTE *)v8 + 47) = 0;
    v8[8] = 0;
    v8[10] = 0;
    v8[9] = 0;
    v19 = (idStr *)(v8 + 8);
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  idStr::operator=(this: (idStr *)v9, text: relativePath);
  idFileSystemLocal::GetExtensionList(this, extension, extensionList: &v20);
  v10 = (idStr **)(v9 + 8);
  idFileSystemLocal::GetFileListTree(
    this,
    relativePath,
    extensions: &v20,
    list: (idList<idStr,5> *)v9 + 2,
    hashIndex: v21);
  if ( sort )
  {
    v18.__vftable = (idSort_Quick<idStr,idSort_PathStr>_vtbl *)&idSort_PathStr::`vftable';
    v15 = *v10;
    if ( *v10 != nullptr )
    {
      v16 = v9[9];
      v19 = *v10;
      idSort_Quick<idStr,idSort_PathStr>::Sort(this: &v18, base: v15, num: v16, a4: v14, a5: v13, a6: v12, a7: v11);
    }
    v18.__vftable = (idSort_Quick<idStr,idSort_PathStr>_vtbl *)&idSort<idStr>::`vftable';
  }
  if ( v20.listStatic == 0 || v20.listStatic == 2 )
  {
    if ( v20.list != nullptr )
      idListArrayDelete<idStr>(ptr: v20.list, num: v20.size);
    v20.list = nullptr;
    v20.size = 0;
  }
  v20.num = 0;
  idHashIndex::Free(this: v21);
  return (idFileList *)v9;
}


// ========================================================================
// __unwind$124984
// EA  : 0x82F0E7E8
// RVA : 0x00F0E7E8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124984()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$124985
// EA  : 0x82F0E810
// RVA : 0x00F0E810
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124985()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$124986
// EA  : 0x82F0E838
// RVA : 0x00F0E838
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124986()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 144), tag: TAG_FILE);
}


// ========================================================================
// __unwind$125009
// EA  : 0x82F0E864
// RVA : 0x00F0E864
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125009()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 224 + 144));
}


// ========================================================================
// __unwind$124987
// EA  : 0x82F0E88C
// RVA : 0x00F0E88C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_124987()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 224 + 80));
}


// ========================================================================
// ?AddGameDirectory@idFileSystemLocal@@AAAXPBD0@Z
// EA  : 0x82F0E8C0
// RVA : 0x00F0E8C0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::AddGameDirectory(idFileSystemLocal *this, const char *path, const char *dir)
{
  idList<idStr,48> *p_searchPaths; // r30
  idStr v6[2]; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: v6, text: path);
  idStr::AppendPath(this: v6, text: dir);
  idStr::EnsureAlloced(this: v6, amount: v6[0].len + 2, keepold: true, geometricGrowth: true);
  v6[0].data[v6[0].len] = 47;
  v6[0].data[++v6[0].len] = 0;
  idStr::BackSlashesToSlashes(this: v6);
  p_searchPaths = &this->searchPaths;
  if ( idList<idStr,5>::FindIndex(this: (idList<idStr,5> *)p_searchPaths, obj: v6, startIndex: 0) == -1 )
    idList<idStr,48>::Insert(this: p_searchPaths, obj: v6, index: 0);
  idStr::FreeData(this: v6);
}


// ========================================================================
// __unwind$125178
// EA  : 0x82F0E970
// RVA : 0x00F0E970
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125178()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReInit@idFileSystemLocal@@UAAXPBD@Z
// EA  : 0x82F0E998
// RVA : 0x00F0E998
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::ReInit(idFileSystemLocal *this, const char *basePath)
{
  idStr *list; // r3
  idCmdArgs v5; // [sp+50h] [-930h] BYREF

  idStr::operator=(this: &this->pathBase, text: basePath);
  if ( this->searchPaths.listStatic == 0 || this->searchPaths.listStatic == 2 )
  {
    list = this->searchPaths.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->searchPaths.size);
    this->searchPaths.list = nullptr;
    this->searchPaths.size = 0;
  }
  this->searchPaths.num = 0;
  idFileSystemLocal::AddGameDirectory(this, path: basePath, dir: "base");
  v5.argc = 0;
  idFileSystemLocal::Path_f(args: &v5);
  idLib::Printf(fmt: "file system re-initialized.\n");
  idLib::Printf(fmt: "---------------------------\n");
}


// ========================================================================
// ?ClearZipCache@idFileSystemLocal@@UAAXXZ
// EA  : 0x82F0EA30
// RVA : 0x00F0EA30
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::ClearZipCache(idFileSystemLocal *this)
{
  idCachedZipFile *cachedZipFiles; // r31
  idCachedZipFile *next; // r30

  cachedZipFiles = this->cachedZipFiles;
  if ( cachedZipFiles != nullptr )
  {
    do
    {
      next = cachedZipFiles->next;
      idCachedZipFile::~idCachedZipFile(this: cachedZipFiles);
      idMem::Free(this: &mem, ptr: cachedZipFiles, align: ALIGN_16);
      cachedZipFiles = next;
    }
    while ( next != nullptr );
  }
  this->cachedZipFiles = nullptr;
}


// ========================================================================
// ?FreeFileList@idFileSystemLocal@@UAAXPAVidFileList@@@Z
// EA  : 0x82F0EA90
// RVA : 0x00F0EA90
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::FreeFileList(idFileSystemLocal *this, idFileList *fileList)
{
  if ( fileList != nullptr )
  {
    idFileList::~idFileList(this: fileList);
    idMem::Free(this: &mem, ptr: fileList, align: ALIGN_16);
  }
}


// ========================================================================
// ?Dir_f@idFileSystemLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82F0EAE8
// RVA : 0x00F0EAE8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::Dir_f(const idCmdArgs *args)
{
  int v1; // r30
  int argc; // r11
  const char *v4; // r4
  const char *v5; // r4
  int num; // r4
  idFileList *v7; // r28
  int v8; // r29
  idStr v9; // [sp+60h] [-70h] BYREF
  idStr v10[2]; // [sp+80h] [-50h] BYREF

  v1 = 0;
  v9.len = 0;
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  v9.baseBuffer[0] = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  v10[0].len = 0;
  v10[0].baseBuffer[0] = 0;
  argc = args->argc;
  if ( args->argc < 2 || argc > 3 )
  {
    idLib::Printf(fmt: "usage: dir <directory> [extension]\n");
    idStr::FreeData(this: v10);
  }
  else
  {
    if ( argc == 2 )
    {
      idStr::operator=(this: &v9, text: args->argv[1]);
      idStr::operator=(this: v10, text: &byte_8200D768);
    }
    else
    {
      if ( argc <= 1 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[1];
      idStr::operator=(this: &v9, text: v4);
      if ( args->argc <= 2 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[2];
      idStr::operator=(this: v10, text: v5);
      if ( *v10[0].data != 46 )
        idLib::Warning(fmt: "extension should have a leading dot");
    }
    idStr::BackSlashesToSlashes(this: &v9);
    idStr::StripTrailing(this: &v9, c: 47);
    idLib::Printf(fmt: "Listing of %s/*%s\n", v9.data, v10[0].data);
    idLib::Printf(fmt: "---------------\n");
    v7 = idFileSystemLocal::ListFiles(
           this: &fileSystemLocal,
           relativePath: v9.data,
           extension: v10[0].data,
           sort: false,
           fullRelativePath: false);
    num = v7->list.num;
    if ( num > 0 )
    {
      v8 = 0;
      do
      {
        idLib::Printf(fmt: "%s\n", v7->list.list[v8].data);
        ++v1;
        ++v8;
        num = v7->list.num;
      }
      while ( v1 < num );
    }
    idLib::Printf(fmt: "%d files\n", num);
    idFileList::~idFileList(this: v7);
    idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    idStr::FreeData(this: v10);
  }
  idStr::FreeData(this: &v9);
}


// ========================================================================
// __unwind$125320
// EA  : 0x82F0ECE0
// RVA : 0x00F0ECE0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125320()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$125321
// EA  : 0x82F0ED08
// RVA : 0x00F0ED08
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125321()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?DirTree_f@idFileSystemLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82F0ED38
// RVA : 0x00F0ED38
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::DirTree_f(const idCmdArgs *args)
{
  int v1; // r30
  int argc; // r11
  const char *v4; // r4
  const char *v5; // r4
  int num; // r4
  idFileList *v7; // r28
  int v8; // r29
  idStr v9; // [sp+60h] [-70h] BYREF
  idStr v10[2]; // [sp+80h] [-50h] BYREF

  v1 = 0;
  v9.len = 0;
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  v9.baseBuffer[0] = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  v10[0].len = 0;
  v10[0].baseBuffer[0] = 0;
  argc = args->argc;
  if ( args->argc < 2 || argc > 3 )
  {
    idLib::Printf(fmt: "usage: dirtree <directory> [extension]\n");
    idStr::FreeData(this: v10);
  }
  else
  {
    if ( argc == 2 )
    {
      idStr::operator=(this: &v9, text: args->argv[1]);
      idStr::operator=(this: v10, text: &byte_8200D768);
    }
    else
    {
      if ( argc <= 1 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[1];
      idStr::operator=(this: &v9, text: v4);
      if ( args->argc <= 2 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[2];
      idStr::operator=(this: v10, text: v5);
      if ( *v10[0].data != 46 )
        idLib::Warning(fmt: "extension should have a leading dot");
    }
    idStr::BackSlashesToSlashes(this: &v9);
    idStr::StripTrailing(this: &v9, c: 47);
    idLib::Printf(fmt: "Listing of %s/*%s /s\n", v9.data, v10[0].data);
    idLib::Printf(fmt: "---------------\n");
    v7 = idFileSystemLocal::ListFilesTree(
           this: &fileSystemLocal,
           relativePath: v9.data,
           extension: v10[0].data,
           sort: false);
    num = v7->list.num;
    if ( num > 0 )
    {
      v8 = 0;
      do
      {
        idLib::Printf(fmt: "%s\n", v7->list.list[v8].data);
        ++v1;
        ++v8;
        num = v7->list.num;
      }
      while ( v1 < num );
    }
    idLib::Printf(fmt: "%d files\n", num);
    idFileList::~idFileList(this: v7);
    idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    idStr::FreeData(this: v10);
  }
  idStr::FreeData(this: &v9);
}


// ========================================================================
// __unwind$125527
// EA  : 0x82F0EF2C
// RVA : 0x00F0EF2C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125527()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$125528
// EA  : 0x82F0EF54
// RVA : 0x00F0EF54
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?Init@idFileSystemLocal@@UAAXXZ
// EA  : 0x82F0EF88
// RVA : 0x00F0EF88
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall idFileSystemLocal::Init(idFileSystemLocal *this)
{
  idStr *p_pathBase; // r29
  int v3; // r25
  const char *v4; // r3
  const char *v5; // r3
  size_t len; // r24
  char *data; // r4
  char *v8; // r4
  idFileList *v9; // r3
  idFileList *v10; // r27
  int v11; // r28
  const char *v12; // r29
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  va *v16; // r3
  int v17; // [sp+8h] [-1128h]
  int v18; // [sp+Ch] [-1124h]
  int v19; // [sp+10h] [-1120h]
  int v20; // [sp+14h] [-111Ch]
  int v21; // [sp+18h] [-1118h]
  int v22; // [sp+1Ch] [-1114h]
  idStr v23; // [sp+60h] [-10D0h] BYREF
  idStr v24; // [sp+80h] [-10B0h] BYREF
  idFileSystemLocal v25[23]; // [sp+A0h] [-1090h] BYREF

  p_pathBase = &this->pathBase;
  idLib::Printf(fmt: "------ Initializing File System ------\n");
  idStr::operator=(this: &this->pathBase, text: fs_basepath.valueString.data);
  idStr::operator=(this: &this->pathCache, text: fs_cachepath.valueString.data);
  idStr::operator=(this: &this->pathSave, text: fs_savepath.valueString.data);
  idStr::operator=(this: &this->pathInstall, text: fs_installpath.valueString.data);
  v3 = 0;
  if ( *this->pathBase.data == 0 )
  {
    v4 = Sys_EXEPath();
    idStr::operator=(this: &this->pathBase, text: v4);
    v5 = Sys_EXEPath();
    idStr::idStr(this: &v23, text: v5);
    idStr::StripFilename(this: &v23);
    idStr::idStr(this: &v24, text: &v23);
    idStr::AppendPath(this: &v24, text: "base");
    if ( this->IsFolder(this, a2: v24.data, a3: FSPATH_BASE) == FOLDER_YES )
    {
      len = v23.len;
      idStr::EnsureAlloced(this: &this->pathBase, amount: v23.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->pathBase.data, Src: v23.data, Size: len);
      this->pathBase.data[len] = 0;
      p_pathBase->len = len;
    }
    idStr::FreeData(this: &v24);
    idStr::FreeData(this: &v23);
  }
  idFileSystemLocal::AddGameDirectory(this, path: this->pathBase.data, dir: "base");
  data = this->pathSave.data;
  if ( *data != 0 )
    idFileSystemLocal::AddGameDirectory(this, path: data, dir: "base");
  v8 = this->pathInstall.data;
  if ( *v8 != 0 )
    idFileSystemLocal::AddGameDirectory(this, path: v8, dir: "base");
  else
    idStr::operator=(this: &this->pathInstall, text: fs_basepath.valueString.data);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "dir",
    a3: idFileSystemLocal::Dir_f,
    a4: "lists a folder",
    a5: idCmdSystem::ArgCompletion_FileName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "dirtree",
    a3: idFileSystemLocal::DirTree_f,
    a4: "lists a folder with subfolders",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "path",
    a3: idFileSystemLocal::Path_f,
    a4: "lists search paths",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "copy",
    a3: idFileSystemLocal::Copy_f,
    a4: "copy a file",
    a5: idCmdSystem::ArgCompletion_FileName);
  v25[0].pathCache.len = 0;
  idFileSystemLocal::Path_f(args: (const idCmdArgs *)&v25[0].pathCache);
  idLib::Printf(fmt: "file system initialized.\n");
  if ( fs_cleanGenerated.valueInteger != 0 )
  {
    if ( fs_cleanGenerated.valueInteger == 1 )
    {
      v9 = fileSystem->ListFiles(this: fileSystem, a2: "generated", a3: "/", a4: 0, a5: 0);
      v10 = v9;
      if ( v9 != nullptr )
      {
        if ( v9->list.num > 0 )
        {
          v11 = 0;
          do
          {
            v12 = v10->list.list[v11].data;
            if ( idStr::Icmp(s1: v12, s2: "cloud") != 0 )
            {
              HIDWORD(v15) = v12;
              v16 = va::va(
                      this: (va *)&v25[0].pathCache,
                      fmt: "generated/%s",
                      a3: v15,
                      a4: v14,
                      a5: v13,
                      a6: v17,
                      a7: v18,
                      a8: v19,
                      a9: v20,
                      a10: v21,
                      a11: v22);
              idFileSystemLocal::BuildOSPath(
                this: (idFileSystemLocal *)&v25[0].pathBase,
                result: (idStr *)this,
                fsPath: FSPATH_BASE,
                relativePath: v16->buffer);
              RemoveDirTree(ospath: v25[0].pathBase.data);
              idStr::FreeData(this: &v25[0].pathBase);
            }
            ++v3;
            ++v11;
          }
          while ( v3 < v10->list.num );
        }
        idFileList::~idFileList(this: v10);
        idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
      }
    }
    else
    {
      idFileSystemLocal::BuildOSPath(
        this: v25,
        result: (idStr *)this,
        fsPath: FSPATH_BASE,
        relativePath: fs_generatedPath.valueString.data);
      RemoveDirTree(ospath: (char *)v25[0].searchPaths.list);
      idStr::FreeData(this: (idStr *)v25);
    }
  }
  BenchmarkGameData();
  idLib::Printf(fmt: "---------------------------\n");
}


// ========================================================================
// __unwind$125740
// EA  : 0x82F0F354
// RVA : 0x00F0F354
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125740()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 96));
}


// ========================================================================
// __unwind$125741
// EA  : 0x82F0F37C
// RVA : 0x00F0F37C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125741()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 128));
}


// ========================================================================
// __unwind$125742
// EA  : 0x82F0F3A4
// RVA : 0x00F0F3A4
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125742()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 192));
}


// ========================================================================
// __unwind$125743
// EA  : 0x82F0F3CC
// RVA : 0x00F0F3CC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_125743()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4400 + 160));
}


// ========================================================================
// RemoveFileWithCheckout
// EA  : 0x82F0F528
// RVA : 0x00F0F528
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall RemoveFileWithCheckout(const char *ospath)
{
  char v1; // r28
  int v4; // r3
  char v5; // r11
  char v6; // r30
  idStr v7[2]; // [sp+60h] [-50h] BYREF

  v1 = 0;
  if ( idStr::Icmpn(s1: ospath, s2: "nfs:", n: 4) == 0 )
    return idFile_Nfs::RemoveFile(path: ospath);
  if ( !Sys_IsFileWritable(path: ospath) )
  {
    if ( idLib::sourceControl == nullptr
      || (idStr::idStr(this: v7, text: ospath),
          v1 = 1,
          v4 = idSourceControl::Delete(this: idLib::sourceControl, file: v7),
          v5 = 0,
          v4 == 0) )
    {
      v5 = 1;
    }
    v6 = v5;
    if ( (v1 & 1) != 0 )
      idStr::FreeData(this: v7);
    if ( v6 != 0 )
      idLib::Warning(fmt: "READONLY file couldn't be checked out: %s", ospath);
    else
      idLib::Printf(fmt: "Checked out: %s\n", ospath);
  }
  return (_cntlzw(remove(path: ospath)) & 0x20) != 0;
}


// ========================================================================
// __unwind$126047
// EA  : 0x82F0F614
// RVA : 0x00F0F614
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126047()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 96));
  }
}


// ========================================================================
// ?RemoveFile@idFileSystemLocal@@UAA_NPBDW4fsPath_t@@@Z
// EA  : 0x82F0F660
// RVA : 0x00F0F660
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::RemoveFile(idFileSystemLocal *this, const char *relativePath, fsPath_t basePath)
{
  char *data; // r25
  BOOL v6; // r27
  idFileSystemLocal *v7; // r24
  size_t v8; // r28
  idFileSystemLocal *v9; // r28
  size_t v10; // r30
  int v11; // r30
  idStr v13; // [sp+50h] [-D0h] BYREF
  idStr v14; // [sp+70h] [-B0h] BYREF
  idStr v15; // [sp+90h] [-90h] BYREF
  idStr v16[3]; // [sp+B0h] [-70h] BYREF

  idStr::idStr(this: &v14, text: relativePath);
  idStr::ReplaceChar(this: &v14, oldChar: 47, newChar: 92);
  v13.len = 0;
  v13.allocedAndFlag = 20;
  data = v14.data;
  v13.data = v13.baseBuffer;
  v13.baseBuffer[0] = 0;
  LOBYTE(v6) = 1;
  if ( *fs_savepath.valueString.data != 0 )
  {
    v7 = idFileSystemLocal::BuildOSPath(
           this: (idFileSystemLocal *)&v15,
           result: (idStr *)this,
           fsPath: FSPATH_SAVE,
           relativePath: v14.data);
    v8 = (size_t)v7->__vftable;
    idStr::EnsureAlloced(this: &v13, amount: (int)&v7->dtr_idFileSystem + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v13.data, Src: v7->searchPaths.list, Size: v8);
    v13.data[v8] = 0;
    v13.len = v8;
    idStr::FreeData(this: &v15);
    if ( this->FileExists(this, a2: v13.data, a3: false) )
      v6 = RemoveFileWithCheckout(ospath: v13.data);
  }
  v9 = idFileSystemLocal::BuildOSPath(
         this: (idFileSystemLocal *)v16,
         result: (idStr *)this,
         fsPath: basePath,
         relativePath: data);
  v10 = (size_t)v9->__vftable;
  idStr::EnsureAlloced(this: &v13, amount: (int)&v9->dtr_idFileSystem + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v13.data, Src: v9->searchPaths.list, Size: v10);
  v13.data[v10] = 0;
  v13.len = v10;
  idStr::FreeData(this: v16);
  v11 = RemoveFileWithCheckout(ospath: v13.data) && v6;
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v14);
  return v11;
}


// ========================================================================
// __unwind$126073
// EA  : 0x82F0F7D8
// RVA : 0x00F0F7D8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126073()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$126074
// EA  : 0x82F0F800
// RVA : 0x00F0F800
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126074()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$126075
// EA  : 0x82F0F828
// RVA : 0x00F0F828
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126075()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 144));
}


// ========================================================================
// __unwind$126076
// EA  : 0x82F0F850
// RVA : 0x00F0F850
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 176));
}


// ========================================================================
// ?FileExists@idFileSystemLocal@@UAA_NPBD_N@Z
// EA  : 0x82F0F880
// RVA : 0x00F0F880
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

BOOL __fastcall idFileSystemLocal::FileExists(
        idFileSystemLocal *this,
        const char *relativePath,
        BOOL overrideProduction)
{
  int v6; // r26
  char *data; // r11
  int v8; // r10
  idFileSystemLocal *v9; // r3
  const char *v10; // r3
  idFileSystemLocal v12; // [sp+50h] [-2A0h] BYREF
  idStrStatic<256> v13; // [sp+190h] [-160h] BYREF

  v6 = ((int (__fastcall *)(idFileSystemLocal *))this->GetTimestamp)(a1: this);
  if ( v6 == -1 && overrideProduction && fs_sourceControlEnable.valueInteger != 0 && idLib::sourceControl != nullptr )
  {
    if ( !idLib::sourceControl->IsInitialized(this: idLib::sourceControl) )
    {
      idLib::sourceControl->Init(this: idLib::sourceControl);
      data = fs_sourceControlWorkspace.valueString.data;
      do
        v8 = (unsigned __int8)*data++;
      while ( v8 != 0 );
      if ( data - fs_sourceControlWorkspace.valueString.data != 1 )
        ((void (__fastcall *)(idSourceControl *))idLib::sourceControl->SetWorkspace)(a1: idLib::sourceControl);
    }
    if ( idLib::sourceControl->IsInitialized(this: idLib::sourceControl) )
    {
      v9 = idFileSystemLocal::BuildOSPath(this: &v12, result: (idStr *)this, fsPath: FSPATH_BASE, relativePath);
      idStrStatic<256>::idStrStatic<256>(this: (idStrStatic<256> *)&v12.pathBase, text: (const idStr *)v9);
      idStr::FreeData(this: (idStr *)&v12);
      v10 = this->GetBasePathStr(this, a2: 0);
      idStrStatic<256>::idStrStatic<256>(this: &v13, text: v10);
      if ( idStr::Icmpn(s1: v12.pathBase.data, s2: v13.data, n: v13.len) == 0
        && (unsigned int)idLib::sourceControl->GetFileStatus(this: idLib::sourceControl, a2: &v12.pathBase) >= SCF_CHECKEDOUT
        && idSourceControl::GetLatest(this: idLib::sourceControl, file: &v12.pathBase, force: true) == 1 )
      {
        v6 = this->GetTimestamp(this, a2: relativePath, a3: overrideProduction);
      }
      idStr::FreeData(this: &v13);
      idStr::FreeData(this: &v12.pathBase);
    }
  }
  return v6 != -1;
}


// ========================================================================
// __unwind$126206
// EA  : 0x82F0FA6C
// RVA : 0x00F0FA6C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 80));
}


// ========================================================================
// __unwind$126207
// EA  : 0x82F0FA94
// RVA : 0x00F0FA94
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126207()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 112));
}


// ========================================================================
// __unwind$126208
// EA  : 0x82F0FABC
// RVA : 0x00F0FABC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126208()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 752 + 400));
}


// ========================================================================
// ?GetTimestamp@idFileSystemLocal@@UAAIPBD_N@Z
// EA  : 0x82F0FAF0
// RVA : 0x00F0FAF0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::GetTimestamp(
        idFileSystemLocal *this,
        const char *relativePath,
        bool overrideProduction,
        int a4,
        const char *a5)
{
  unsigned __int64 v8; // r6
  idFile *v10; // r3
  idFile *v11; // r30
  int v12; // r29
  idPLogScope v13[6]; // [sp+50h] [-30h] BYREF

  LODWORD(v8) = "idFileSystemLocal::GetTimestamp";
  HIDWORD(v8) = 1;
  idPLogScope::idPLogScope(this: v13, pl: &pLog, gMask: v8, label: a5);
  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  if ( relativePath != nullptr && *relativePath != 0 )
  {
    if ( (idLib::production == PROD_PRODUCTION || idLib::production == PROD_LOADED) && !overrideProduction )
    {
      idPLogScope::~idPLogScope(this: v13);
      return 1;
    }
    else
    {
      v10 = this->OpenFileRead(this, a2: relativePath, a3: 0, a4: 0);
      v11 = v10;
      if ( v10 != nullptr )
      {
        v12 = v10->Timestamp(this: v10);
        ((void (__fastcall *)(idFile *, int))v11->dtr_idFile)(a1: v11, a2: 1);
        idPLogScope::~idPLogScope(this: v13);
        return v12;
      }
      else
      {
        idPLogScope::~idPLogScope(this: v13);
        return -1;
      }
    }
  }
  else
  {
    idLib::FatalError(fmt: "idFileSystemLocal::GetTimestamp with empty name\n");
    return _LN31_1();
  }
}


// ========================================================================
// $LN31_1
// EA  : 0x82F0FC28
// RVA : 0x00F0FC28
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN31_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?PreOpenFileWrite@idFileSystemLocal@@ABA_NPBDAAW4fsPath_t@@AAVidStr@@@Z
// EA  : 0x82F0FC58
// RVA : 0x00F0FC58
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::PreOpenFileWrite(
        idFileSystemLocal *this,
        const char *relativePath,
        fsPath_t *basePath,
        idStr *OSPath)
{
  idFileSystemLocal *v9; // r28
  size_t v10; // r29
  idStr v11[2]; // [sp+50h] [-50h] BYREF

  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  if ( fs_readOnly.valueInteger != 0 )
    return 0;
  if ( *resource_outPath.valueString.data != 0 && idStr::Icmpn(s1: relativePath, s2: "generated", n: 9) == 0 )
    *basePath = FSPATH_SAVE;
  v9 = idFileSystemLocal::BuildOSPath(
         this: (idFileSystemLocal *)v11,
         result: (idStr *)this,
         fsPath: *basePath,
         relativePath);
  v10 = (size_t)v9->__vftable;
  idStr::EnsureAlloced(this: OSPath, amount: (int)&v9->dtr_idFileSystem + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: OSPath->data, Src: v9->searchPaths.list, Size: v10);
  OSPath->data[v10] = 0;
  OSPath->len = v10;
  idStr::FreeData(this: v11);
  if ( fs_debug.valueInteger != 0 )
    idLib::Printf(fmt: "idFileSystem::OpenFileWrite: %s\n", OSPath->data);
  if ( IsOSNativePath(OSPath: OSPath->data) && !Sys_IsFileWritable(path: OSPath->data) )
  {
    if ( idLib::sourceControl != nullptr && idSourceControl::CheckOut(this: idLib::sourceControl, file: OSPath) != 0 )
      idLib::Printf(fmt: "Checked out: %s\n", OSPath->data);
    else
      idLib::Warning(fmt: "READONLY file couldn't be checked out: %s", OSPath->data);
  }
  return 1;
}


// ========================================================================
// $LN40_5
// EA  : 0x82F0FDEC
// RVA : 0x00F0FDEC
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN40_5()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?OpenFileWritePermanent@idFileSystemLocal@@UAAPAVidFile@@PBDW4fsPath_t@@@Z
// EA  : 0x82F0FE20
// RVA : 0x00F0FE20
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile_Permanent *__fastcall idFileSystemLocal::OpenFileWritePermanent(
        idFileSystemLocal *this,
        const char *relativePath,
        fsPath_t basePath,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        fsPath_t a16)
{
  idFile_Permanent *v19; // r30
  idFile_Permanent *v20; // r3
  idStr v21[2]; // [sp+60h] [-50h] BYREF

  a16 = basePath;
  v21[0].len = 0;
  v21[0].allocedAndFlag = 20;
  v21[0].data = v21[0].baseBuffer;
  v21[0].baseBuffer[0] = 0;
  if ( (unsigned __int8)idFileSystemLocal::PreOpenFileWrite(this, relativePath, basePath: &a16, OSPath: v21) == 0 )
    goto LABEL_2;
  if ( idStr::Icmpn(s1: v21[0].data, s2: "mtp:", n: 4) != 0 )
  {
    if ( idStr::Icmpn(s1: v21[0].data, s2: "nfs:", n: 4) != 0 )
    {
      this->CreateOSPath(this, a2: v21[0].data);
      v20 = (idFile_Permanent *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x68u,
                                  tag: TAG_FILE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      if ( v20 != nullptr )
        v19 = idFile_Permanent::idFile_Permanent(
                this: v20,
                relativePath,
                osPath: v21[0].data,
                m: FS_WRITE,
                create: false);
      else
        v19 = nullptr;
      if ( !idFile_Permanent::IsOpen(this: v19) )
      {
        if ( v19 != nullptr )
          ((void (__fastcall *)(idFile_Permanent *, int))v19->dtr_idFile)(a1: v19, a2: 1);
LABEL_2:
        idStr::FreeData(this: v21);
        return nullptr;
      }
    }
    else
    {
      v19 = (idFile_Permanent *)idFileSystemLocal::OpenFromNFS(this, path: v21[0].data, mode: FS_WRITE, create: true);
    }
  }
  else
  {
    v19 = (idFile_Permanent *)idFileSystemLocal::OpenFromMTP(this, path: v21[0].data, mode: FS_WRITE);
  }
  idStr::FreeData(this: v21);
  return v19;
}


// ========================================================================
// __unwind$126429
// EA  : 0x82F0FFB8
// RVA : 0x00F0FFB8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126429()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$126430
// EA  : 0x82F0FFE0
// RVA : 0x00F0FFE0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126430()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?OpenFileReadWrite@idFileSystemLocal@@UAAPAVidFile@@PBD_NW4fsPath_t@@@Z
// EA  : 0x82F10018
// RVA : 0x00F10018
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile_Permanent *__fastcall idFileSystemLocal::OpenFileReadWrite(
        idFileSystemLocal *this,
        const char *relativePath,
        bool create,
        fsPath_t basePath)
{
  idFile_Permanent *v8; // r30
  idFile_Permanent *v9; // r3
  idStr v11[2]; // [sp+60h] [-50h] BYREF

  if ( !this->IsInitialized(this) )
    idLib::FatalError(fmt: "Filesystem call made without initialization\n");
  idFileSystemLocal::BuildOSPath(this: (idFileSystemLocal *)v11, result: (idStr *)this, fsPath: basePath, relativePath);
  if ( fs_debug.valueInteger != 0 )
    idLib::Printf(fmt: "idFileSystem::OpenFileReadWrite: %s\n", v11[0].data);
  if ( idStr::Icmpn(s1: v11[0].data, s2: "mtp:", n: 4) == 0 )
  {
    v8 = (idFile_Permanent *)idFileSystemLocal::OpenFromMTP(this, path: relativePath, mode: FS_READ_WRITE);
LABEL_20:
    idStr::FreeData(this: v11);
    return v8;
  }
  if ( idStr::Icmpn(s1: v11[0].data, s2: "nfs:", n: 4) == 0 )
  {
    v8 = (idFile_Permanent *)idFileSystemLocal::OpenFromNFS(this, path: v11[0].data, mode: FS_READ_WRITE, create);
    goto LABEL_20;
  }
  if ( !Sys_IsFileWritable(path: v11[0].data)
    && (idLib::sourceControl == nullptr || idSourceControl::CheckOut(this: idLib::sourceControl, file: v11) == 0) )
  {
    idLib::Warning(fmt: "READONLY file couldn't be checked out: %s", v11[0].data);
  }
  this->CreateOSPath(this, a2: v11[0].data);
  v9 = (idFile_Permanent *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x68u,
                             tag: TAG_FILE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v8 = idFile_Permanent::idFile_Permanent(this: v9, relativePath, osPath: v11[0].data, m: FS_READ_WRITE, create);
  else
    v8 = nullptr;
  if ( idFile_Permanent::IsOpen(this: v8) )
    goto LABEL_20;
  if ( v8 != nullptr )
    ((void (__fastcall *)(idFile_Permanent *, int))v8->dtr_idFile)(a1: v8, a2: 1);
  idStr::FreeData(this: v11);
  return nullptr;
}


// ========================================================================
// $LN58_5
// EA  : 0x82F10214
// RVA : 0x00F10214
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _LN58_5()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$126568
// EA  : 0x82F1023C
// RVA : 0x00F1023C
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126568()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?OpenFileWrite@idFileSystemLocal@@UAAPAVidFile@@PBDW4fsPath_t@@@Z
// EA  : 0x82F10270
// RVA : 0x00F10270
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idFile_AtomicWrite *__fastcall idFileSystemLocal::OpenFileWrite(
        idFileSystemLocal *this,
        const char *relativePath,
        fsPath_t basePath,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        fsPath_t a16)
{
  idFile_AtomicWrite *v18; // r3
  idFile_AtomicWrite *v19; // r30
  idStr v20[2]; // [sp+60h] [-40h] BYREF

  a16 = basePath;
  if ( fs_atomicFileWrite.valueInteger == 0 )
    return (idFile_AtomicWrite *)((int (__fastcall *)(idFileSystemLocal *, const char *))this->OpenFileWritePermanent)(
                                   a1: this,
                                   a2: relativePath);
  v20[0].len = 0;
  v20[0].allocedAndFlag = 20;
  v20[0].data = v20[0].baseBuffer;
  v20[0].baseBuffer[0] = 0;
  if ( (unsigned __int8)idFileSystemLocal::PreOpenFileWrite(this, relativePath, basePath: &a16, OSPath: v20) != 0 )
  {
    v18 = (idFile_AtomicWrite *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x190u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v18 != nullptr )
      v19 = idFile_AtomicWrite::idFile_AtomicWrite(this: v18, relativePath, basePath_: a16);
    else
      v19 = nullptr;
    idStr::FreeData(this: v20);
    return v19;
  }
  else
  {
    idStr::FreeData(this: v20);
    return nullptr;
  }
}


// ========================================================================
// __unwind$126686
// EA  : 0x82F10358
// RVA : 0x00F10358
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void _unwind_126686()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$126687
// EA  : 0x82F10380
// RVA : 0x00F10380
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __fastcall _unwind_126687(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ?WriteFile@idFileSystemLocal@@UAAIPBDPBXIW4fsPath_t@@@Z
// EA  : 0x82F103A8
// RVA : 0x00F103A8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

int __fastcall idFileSystemLocal::WriteFile(
        idFileSystemLocal *this,
        const char *relativePath,
        const void *buffer,
        int size,
        __int32 basePath,
        int a6,
        int a7,
        int a8)
{
  idFile_AtomicWrite *v11; // r31
  int v12; // r30
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+14h] [-6Ch]
  int v18; // [sp+18h] [-68h]
  int v19; // [sp+1Ch] [-64h]
  int v20; // [sp+20h] [-60h]
  fsPath_t v21; // [sp+24h] [-5Ch]

  v11 = idFileSystemLocal::OpenFileWrite(
          this,
          relativePath,
          (fsPath_t)basePath,
          a4: size,
          a5: basePath,
          a6,
          a7,
          a8,
          a9: v14,
          a10: v15,
          a11: v16,
          a12: v17,
          a13: v18,
          a14: v19,
          a15: v20,
          a16: v21);
  if ( v11 == nullptr )
    idLib::Error(fmt: "Failed to open %s\n", relativePath);
  v12 = v11->Write(this: v11, a2: buffer, a3: size);
  ((void (__fastcall *)(idFile_AtomicWrite *, int))v11->dtr_idFile)(a1: v11, a2: 1);
  return v12;
}


// ========================================================================
// `dynamic initializer for 'fs_benchmarkSeekMicroseconds''
// EA  : 0x83394660
// RVA : 0x01394660
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_benchmarkSeekMicroseconds__()
{
  idCVar::idCVar(
    this: &fs_benchmarkSeekMicroseconds,
    name: "fs_benchmarkSeekMicroseconds",
    value: "20000",
    flags: 2,
    description: "If benchmark < this, assume HD",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_benchmarkSeekMicroseconds__);
}


// ========================================================================
// `dynamic initializer for 'fs_debug''
// EA  : 0x833946B8
// RVA : 0x013946B8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_debug__()
{
  idCVar::idCVar(
    this: &fs_debug,
    name: "fs_debug",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))off_82010000,
    a9: (int)&loc_82660000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_debug__);
}


// ========================================================================
// `dynamic initializer for 'fs_basepath''
// EA  : 0x83394720
// RVA : 0x01394720
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_basepath__()
{
  idCVar::idCVar(
    this: &fs_basepath,
    name: "fs_basepath",
    value: &byte_8200D768,
    flags: 0,
    description: "(Read Only) Location for game files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_basepath__);
}


// ========================================================================
// `dynamic initializer for 'fs_savepath''
// EA  : 0x83394778
// RVA : 0x01394778
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_savepath__()
{
  idCVar::idCVar(
    this: &fs_savepath,
    name: "fs_savepath",
    value: "DEVKIT:\\RAGE-SAVES",
    flags: 0,
    description: "(Read/Write) Location for development storage files, overwrites the default savegame path as well for the PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_savepath__);
}


// ========================================================================
// `dynamic initializer for 'fs_cachepath''
// EA  : 0x833947D0
// RVA : 0x013947D0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_cachepath__()
{
  idCVar::idCVar(
    this: &fs_cachepath,
    name: "fs_cachepath",
    value: &byte_8200D768,
    flags: 0,
    description: "(Read/Write) Location for temporary files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_cachepath__);
}


// ========================================================================
// `dynamic initializer for 'fs_installpath''
// EA  : 0x83394828
// RVA : 0x01394828
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_installpath__()
{
  idCVar::idCVar(
    this: &fs_installpath,
    name: "fs_installpath",
    value: "GAME:\\",
    flags: 0,
    description: "(Read/Write) Location for installed files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_installpath__);
}


// ========================================================================
// `dynamic initializer for 'fs_shareRetry''
// EA  : 0x83394880
// RVA : 0x01394880
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_shareRetry__()
{
  idCVar::idCVar(
    this: &fs_shareRetry,
    name: "fs_shareRetry",
    value: "0",
    flags: 1,
    description: "default = 0, 1 = retry opening files when encountering a sharing error",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_shareRetry__);
}


// ========================================================================
// `dynamic initializer for 'fs_noOverlappedIO''
// EA  : 0x833948D8
// RVA : 0x013948D8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_noOverlappedIO__()
{
  idCVar::idCVar(
    this: &fs_noOverlappedIO,
    name: "fs_noOverlappedIO",
    value: "0",
    flags: 1,
    description: "default = 0, 1 = uses blocking reads instead of overlapped reads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_noOverlappedIO__);
}


// ========================================================================
// `dynamic initializer for 'fs_arbitraryZipSupport''
// EA  : 0x83394930
// RVA : 0x01394930
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_arbitraryZipSupport__()
{
  idCVar::idCVar(
    this: &fs_arbitraryZipSupport,
    name: "fs_arbitraryZipSupport",
    value: "1",
    flags: 1,
    description: "default = 1, 0 = will not load zip files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_arbitraryZipSupport__);
}


// ========================================================================
// `dynamic initializer for 'fs_readOnly''
// EA  : 0x83394988
// RVA : 0x01394988
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_readOnly__()
{
  idCVar::idCVar(
    this: &fs_readOnly,
    name: "fs_readOnly",
    value: "0",
    flags: 1,
    description: "default = 0, 1 = will set file system to read only",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_readOnly__);
}


// ========================================================================
// `dynamic initializer for 'fs_noCheckout''
// EA  : 0x833949E0
// RVA : 0x013949E0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_noCheckout__()
{
  idCVar::idCVar(
    this: &fs_noCheckout,
    name: "fs_noCheckout",
    value: "0",
    flags: 1,
    description: "1 = chmod local files for writing/deleting instead of checking out",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_noCheckout__);
}


// ========================================================================
// `dynamic initializer for 'fs_generatedPath''
// EA  : 0x83394A38
// RVA : 0x01394A38
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_generatedPath__()
{
  idCVar::idCVar(
    this: &fs_generatedPath,
    name: "fs_generatedPath",
    value: "generated",
    flags: 0,
    description: "Location of generated data",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_generatedPath__);
}


// ========================================================================
// `dynamic initializer for 'fs_cleanGenerated''
// EA  : 0x83394A90
// RVA : 0x01394A90
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_cleanGenerated__()
{
  idCVar::idCVar(
    this: &fs_cleanGenerated,
    name: "fs_cleanGenerated",
    value: "0",
    flags: 2,
    description: "Clean generated data on startup, 1 = clean everything but cloud, 2 = clean everything",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_cleanGenerated__);
}


// ========================================================================
// `dynamic initializer for 'fs_sourceControlEnable''
// EA  : 0x83394AE8
// RVA : 0x01394AE8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_sourceControlEnable__()
{
  idCVar::idCVar(
    this: &fs_sourceControlEnable,
    name: "fs_sourceControlEnable",
    value: "0",
    flags: 1,
    description: "enable automatic source control gets for missing files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_sourceControlEnable__);
}


// ========================================================================
// `dynamic initializer for 'fs_sourceControlWorkspace''
// EA  : 0x83394B40
// RVA : 0x01394B40
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_sourceControlWorkspace__()
{
  idCVar::idCVar(
    this: &fs_sourceControlWorkspace,
    name: "fs_sourceControlWorkspace",
    value: &byte_8200D768,
    flags: 0,
    description: "use an explicit workspace for source control operations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_sourceControlWorkspace__);
}


// ========================================================================
// `dynamic initializer for 'fs_sourceControlGetWholeFolders''
// EA  : 0x83394B98
// RVA : 0x01394B98
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_sourceControlGetWholeFolders__()
{
  idCVar::idCVar(
    this: &fs_sourceControlGetWholeFolders,
    name: "fs_sourceControlGetWholeFolders",
    value: "0",
    flags: 1,
    description: "update the entire folder on a source control get, only gets files with the same extension, currently excludes tgas",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_sourceControlGetWholeFolders__);
}


// ========================================================================
// `dynamic initializer for 'resource_outPath''
// EA  : 0x83394BF0
// RVA : 0x01394BF0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_outPath__()
{
  idCVar::idCVar(
    this: &resource_outPath,
    name: "resource_outPath",
    value: &byte_8200D768,
    flags: 0,
    description: "Optional output path for resource files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_outPath__);
}


// ========================================================================
// `dynamic initializer for 'fs_mtpWholeReadThreshold''
// EA  : 0x83394C48
// RVA : 0x01394C48
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_mtpWholeReadThreshold__()
{
  idCVar::idCVar(
    this: &fs_mtpWholeReadThreshold,
    name: "fs_mtpWholeReadThreshold",
    value: "524288",
    flags: 2,
    description: "if an mtp file size is less than this threshold, block read the entire thing and return a memory file",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_mtpWholeReadThreshold__);
}


// ========================================================================
// `dynamic initializer for 'fs_atomicFileWrite''
// EA  : 0x83394CA0
// RVA : 0x01394CA0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_atomicFileWrite__()
{
  idCVar::idCVar(
    this: &fs_atomicFileWrite,
    name: "fs_atomicFileWrite",
    value: "0",
    flags: 1,
    description: "Return idFile_AtomicWrite instead of idFile_Permanent on OpenFileWrite",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_atomicFileWrite__);
}


// ========================================================================
// `dynamic initializer for 'fs_caseSensitiveOS''
// EA  : 0x83394CF8
// RVA : 0x01394CF8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fs_caseSensitiveOS__()
{
  idCVar::idCVar(
    this: &fs_caseSensitiveOS,
    name: "fs_caseSensitiveOS",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fs_caseSensitiveOS__);
}


// ========================================================================
// `dynamic initializer for 'xen_currentDisc''
// EA  : 0x83394D50
// RVA : 0x01394D50
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__xen_currentDisc__()
{
  idCVar::idCVar(
    this: &xen_currentDisc,
    name: "xen_currentDisc",
    value: "-1",
    flags: 2,
    description: "xen disc #, -1 autodetects, can override with 1, 2, 3",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__xen_currentDisc__);
}


// ========================================================================
// `dynamic initializer for 'fileSystemLocal''
// EA  : 0x83394DA8
// RVA : 0x01394DA8
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fileSystemLocal__()
{
  idFileSystemLocal::idFileSystemLocal(this: &fileSystemLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fileSystemLocal__);
}


// ========================================================================
// `dynamic initializer for 'testCreateOSPath_v''
// EA  : 0x83394DE0
// RVA : 0x01394DE0
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testCreateOSPath_v__()
{
  return idCommandLink::idCommandLink(
           this: &testCreateOSPath_v,
           cmdName: "testCreateOSPath",
           function: testCreateOSPath_f,
           description: "tests idFileSystemLocal::CreateOSPath",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'renameFile_v''
// EA  : 0x83394E08
// RVA : 0x01394E08
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__renameFile_v__()
{
  return idCommandLink::idCommandLink(
           this: &renameFile_v,
           cmdName: "renameFile",
           function: renameFile_f,
           description: "Tests idFileSystemLocal::RenameFile(), mostly for delete-target and directory change semantics",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'benchmarkGameData_v''
// EA  : 0x83394E30
// RVA : 0x01394E30
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__benchmarkGameData_v__()
{
  return idCommandLink::idCommandLink(
           this: &benchmarkGameData_v,
           cmdName: "benchmarkGameData",
           function: benchmarkGameData_f,
           description: "Test seek and read of the gameresources file",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'testContent_v''
// EA  : 0x83394E58
// RVA : 0x01394E58
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testContent_v__()
{
  return idCommandLink::idCommandLink(
           this: &testContent_v,
           cmdName: "testContent",
           function: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
           description: "test",
           argCompletion: nullptr);
}

