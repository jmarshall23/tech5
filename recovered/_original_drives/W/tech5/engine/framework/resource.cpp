
// ========================================================================
// ?GetResourceTypeName@idResource@@QBAPBDXZ
// EA  : 0x82693DD0
// RVA : 0x00693DD0
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

const char *__fastcall idResource::GetResourceTypeName(idResource *this)
{
  idResourceList *v1; // r3

  v1 = this->GetResourceList(this);
  return idResourceList::GetResourceTypeName(this: v1);
}


// ========================================================================
// ?IsTouching@idAIEvent@@QBA_NPBVidEntity@@H@Z
// EA  : 0x82693E00
// RVA : 0x00693E00
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __fastcall idAIEvent::IsTouching(idResource *this)
{
  this->Print(this);
}


// ========================================================================
// ?LoadResource@idResource@@UAAXXZ
// EA  : 0x82693E10
// RVA : 0x00693E10
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __fastcall idResource::LoadResource(idResource *this)
{
  idResourceList *v1; // r3
  const char *ResourceTypeName; // r3
  idResource *v3; // r3

  v1 = this->GetResourceList(this);
  ResourceTypeName = idResourceList::GetResourceTypeName(this: v1);
  idLib::FatalError(fmt: "idResource::Load() for %s not implemented.\n", ResourceTypeName);
  idResource::WriteResourceFile(this: v3);
}


// ========================================================================
// ?WriteResourceFile@idResource@@UBAXXZ
// EA  : 0x82693E40
// RVA : 0x00693E40
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __fastcall idResource::WriteResourceFile(idResource *this)
{
  idResourceList *v1; // r3
  const char *ResourceTypeName; // r3
  idResource *v3; // r3

  v1 = this->GetResourceList(this);
  ResourceTypeName = idResourceList::GetResourceTypeName(this: v1);
  idLib::FatalError(fmt: "resource type '%s' has not implemented WriteResourceFile()", ResourceTypeName);
  idResource::idResource(this: v3);
}


// ========================================================================
// ??0idResource@@QAA@XZ
// EA  : 0x82693E70
// RVA : 0x00693E70
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

idResource *__fastcall idResource::idResource(idResource *this)
{
  char v2; // r7

  this->trackedMemory = 0;
  this->__vftable = (idResource_vtbl *)&idResource::`vftable';
  idAtomicString::Set(this: &this->name, str_: "unnamed");
  v2 = *((_BYTE *)this + 32);
  this->nextOnHashChain = nullptr;
  this->resourceListPtr = nullptr;
  this->resourceError = nullptr;
  this->networkID = -1;
  this->staleCount = 0;
  *((_BYTE *)this + 32) = v2 & 7;
  return this;
}


// ========================================================================
// ??1idResource@@UAA@XZ
// EA  : 0x82693EF0
// RVA : 0x00693EF0
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __fastcall idResource::~idResource(idResource *this)
{
  int v2; // r8

  v2 = *((_BYTE *)this + 32) & 0x40;
  this->__vftable = (idResource_vtbl *)&idResource::`vftable';
  if ( v2 != 0 )
    idLib::FatalError(fmt: "Resource deleted with staticResource set: %s", this->name.str);
  if ( this->nextOnHashChain != nullptr )
    idResourceList::Remove(this: this->resourceListPtr, ptr: this);
  idResourceList::UnRegisterNetworkResource(resource: this);
}


// ========================================================================
// ?SetResourceError@idResource@@IAAXPBDZZ
// EA  : 0x82693F68
// RVA : 0x00693F68
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idResource::SetResourceError(
        idResource *this,
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
  const char *str; // r3
  idAtomicString v13; // [sp+50h] [-420h] BYREF
  char v14[1024]; // [sp+60h] [-410h] BYREF
  __int64 v15; // [sp+490h] [+20h] BYREF
  va_list va; // [sp+490h] [+20h]
  __int64 v17; // [sp+498h] [+28h]
  __int64 v18; // [sp+4A0h] [+30h]
  __int64 v19; // [sp+4A8h] [+38h]
  __int64 v20; // [sp+4B0h] [+40h]
  __int64 v21; // [sp+4B8h] [+48h]
  va_list va1; // [sp+4C0h] [+50h] BYREF

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
  if ( fmt != nullptr )
  {
    va_copy((va_list)v13.str, va);
    idStr::vsnPrintf(dest: v14, size: 1024, fmt, argptr: va);
    v14[1023] = 0;
    idAtomicString::Set(this: &v13, str_: v14);
    str = v13.str;
    this->resourceError = v13.str;
    idLib::Warning(fmt: str);
  }
  else
  {
    this->resourceError = nullptr;
  }
}


// ========================================================================
// ?Print@idResource@@UBAXXZ
// EA  : 0x82694010
// RVA : 0x00694010
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __fastcall idResource::Print(idResource *this)
{
  const char *resourceError; // r31
  int (*GetResourceList)(void); // ctr
  const char *str; // r30
  idResourceList *v4; // r3
  const char *ResourceTypeName; // r3
  const char *v6; // r31
  idResourceList *v7; // r3
  const char *v8; // r3

  resourceError = this->resourceError;
  GetResourceList = (int (*)(void))this->GetResourceList;
  if ( resourceError != nullptr )
  {
    str = this->name.str;
    v4 = (idResourceList *)GetResourceList();
    ResourceTypeName = idResourceList::GetResourceTypeName(this: v4);
    idLib::Printf(fmt: "%s:%s:%s\n", ResourceTypeName, str, resourceError);
  }
  else
  {
    v6 = this->name.str;
    v7 = (idResourceList *)GetResourceList();
    v8 = idResourceList::GetResourceTypeName(this: v7);
    idLib::Printf(fmt: "%s:%s\n", v8, v6);
  }
}


// ========================================================================
// ?Load@idResource@@QAAXXZ
// EA  : 0x826940A0
// RVA : 0x006940A0
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __fastcall idResource::Load(idResource *this)
{
  idResourceList *v2; // r3
  idResourceList *v3; // r3

  v2 = this->GetResourceList(this);
  idResourceList::GetResourceTypeName(this: v2);
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  this->LoadResource(this);
  v3 = this->GetResourceList(this);
  idResourceList::GetResourceTypeName(this: v3);
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
}


// ========================================================================
// ?GetLocalizedName@idResource@@SAPBDPBD00PADH@Z
// EA  : 0x82694128
// RVA : 0x00694128
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

char *__fastcall idResource::GetLocalizedName(
        const char *sourceLanguage,
        const char *destLanguage,
        const char *inName,
        char *outName,
        int sizeOfOutName)
{
  int v9; // r3
  int v10; // r31
  int v11; // r10
  int v12; // r11
  int v13; // r26
  int v14; // r11
  int v15; // r28
  int v16; // r30

  v9 = idStr::Find(searchIn: inName, searchFor: sourceLanguage, casesensitive: true, start: 0, end: -1);
  v10 = v9;
  if ( v9 == -1 )
    return (char *)inName;
  if ( v9 == 0 )
    return (char *)inName;
  v11 = inName[v9 - 1];
  if ( v11 != 47 && v11 != 92 )
    return (char *)inName;
  v12 = inName[v9 + 7];
  if ( v12 != 47 && v12 != 92 )
    return (char *)inName;
  v13 = v9 + 7;
  v14 = 0;
  if ( *inName != 0 )
  {
    do
      ++v14;
    while ( inName[v14] != 0 );
  }
  v15 = v14 - v13;
  v16 = 0;
  if ( *destLanguage != 0 )
  {
    do
      ++v16;
    while ( destLanguage[v16] != 0 );
  }
  if ( v16 + v15 + v9 >= sizeOfOutName )
    return (char *)inName;
  idStr::CopyCountAndZero(dest: outName, destSize: sizeOfOutName, src: inName, count: v9);
  idStr::CopyCountAndZero(dest: &outName[v10], destSize: sizeOfOutName - v10, src: destLanguage, count: v16);
  idStr::CopyCountAndZero(dest: &outName[v16 + v10], destSize: sizeOfOutName - v16 - v10, src: &inName[v13], count: v15);
  if ( resource_showLocalized.valueInteger != 0 )
    idLib::Printf(fmt: "Localized: '%s'\n", outName);
  return outName;
}


// ========================================================================
// ?GetLocalizedName@idResource@@SAPBDPBDPADH@Z
// EA  : 0x82694280
// RVA : 0x00694280
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

char *__fastcall idResource::GetLocalizedName(const char *inName, char *outName, int sizeOfOutName)
{
  return idResource::GetLocalizedName(
           sourceLanguage: "english",
           destLanguage: sys_lang.valueString.data,
           inName,
           outName,
           sizeOfOutName);
}


// ========================================================================
// ?WriteBinaryHeader@idResource@@SA_NPAVidFile@@ABUresourceHeader_t@1@PBXIPBD3@Z
// EA  : 0x826942A8
// RVA : 0x006942A8
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

BOOL __fastcall idResource::WriteBinaryHeader(
        idFile *file,
        const idResource::resourceHeader_t *header,
        const void *data,
        int dataLength,
        const char *uniqueIdName,
        unsigned __int64 sourceFileName)
{
  const void *v11; // r22
  int v12; // r11
  unsigned __int16 *p_sourceFileNameLen; // r26
  int v14; // r11
  int v15; // r11
  unsigned __int16 *p_uniqueIdNameLen; // r28
  unsigned __int64 *p_dataOffset; // r29
  unsigned int v18; // r24
  unsigned int v19; // r21
  unsigned int v20; // r21
  unsigned int v21; // r21
  unsigned int v22; // r21
  unsigned int v23; // r21
  unsigned int v24; // r21
  unsigned int v25; // r21
  unsigned int v26; // r3
  unsigned int v27; // r21
  unsigned int v28; // r21
  unsigned int v29; // r21
  unsigned __int64 v30; // r3
  unsigned int v31; // r27
  unsigned int v32; // r27
  unsigned __int64 v33; // r11
  unsigned int v35; // r30
  unsigned int v36; // r30

  v11 = (const void *)HIDWORD(sourceFileName);
  v12 = 0;
  if ( *(_BYTE *)HIDWORD(sourceFileName) != 0 )
  {
    do
      ++v12;
    while ( *(_BYTE *)(v12 + HIDWORD(sourceFileName)) != 0 );
  }
  LOWORD(sourceFileName) = v12;
  p_sourceFileNameLen = &header->sourceFileNameLen;
  header->sourceFileNameLen = v12;
  v14 = 0;
  if ( *uniqueIdName != 0 )
  {
    do
      ++v14;
    while ( uniqueIdName[v14] != 0 );
  }
  header->uniqueIdNameLen = v14;
  v15 = (unsigned __int16)v14 + (unsigned __int16)sourceFileName + 56;
  p_uniqueIdNameLen = &header->uniqueIdNameLen;
  LODWORD(sourceFileName) = (v15 + 15) & 0x7FFF0;
  p_dataOffset = &header->dataOffset;
  header->dataOffset = sourceFileName;
  v18 = sourceFileName - v15;
  v19 = file->Write(this: file, a2: header, a3: 2u);
  v20 = file->Write(this: file, a2: &header->headerVersionLo, a3: 2u) + v19;
  v21 = file->Write(this: file, a2: &header->resourceId, a3: 4u) + v20;
  v22 = file->Write(this: file, a2: &header->versionHi, a3: 2u) + v21;
  v23 = file->Write(this: file, a2: &header->versionLo, a3: 2u) + v22;
  v24 = file->Write(this: file, a2: &header->sourceTimestamp, a3: 4u) + v23;
  v25 = file->Write(this: file, a2: &header->sourceFileNameLen, a3: 2u) + v24;
  v26 = file->Write(this: file, a2: &header->uniqueIdNameLen, a3: 2u);
  header->platform = 1;
  v27 = file->Write(this: file, a2: &header->platform, a3: 1u) + v26 + v25;
  v28 = file->Write(this: file, a2: header->pad, a3: 3u) + v27;
  v29 = file->Write(this: file, a2: &header->uniqueId, a3: 8u) + v28;
  LODWORD(v30) = MurMur64_HashData(key: data, len: dataLength, seed: 0) >> 32;
  header->hash = v30;
  v31 = file->Write(this: file, a2: &header->hash, a3: 8u) + v29;
  v32 = file->Write(this: file, a2: &header->dataOffset, a3: 8u) + v31;
  LODWORD(v33) = LODWORD(header->dataOffset) + dataLength;
  header->totalSize = v33;
  if ( file->Write(this: file, a2: &header->totalSize, a3: 8u) + v32 != 56 )
    return false;
  v35 = file->Write(this: file, a2: v11, a3: *p_sourceFileNameLen) + 56;
  v36 = file->Write(this: file, a2: uniqueIdName, a3: *p_uniqueIdNameLen) + v35;
  return file->Write(this: file, a2: zeroBytes, a3: v18) + v36 == *((_DWORD *)p_dataOffset + 1);
}


// ========================================================================
// ?WriteBinary@idResource@@SA_NPBD00ABUresourceHeader_t@1@PBXI@Z
// EA  : 0x826945D8
// RVA : 0x006945D8
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

BOOL __fastcall idResource::WriteBinary(
        const char *uniqueIdName,
        const char *sourceFileName,
        const char *fileExtension,
        const idResource::resourceHeader_t *header,
        const void *data,
        unsigned int dataLen)
{
  unsigned __int64 v10; // r10
  BOOL v11; // r30
  idFile_Memory v13; // [sp+50h] [-290h] BYREF
  char v14; // [sp+1A0h] [-140h] BYREF

  ((void (__fastcall *)(idFileSystem *, const char *))fileSystem->FixLongFilename)(a1: fileSystem, a2: "generated");
  idFile_Memory::idFile_Memory(this: &v13);
  idResource::WriteBinaryHeader(file: &v13, header, data, dataLength: dataLen, uniqueIdName, sourceFileName: v10);
  idFile_Memory::Write(this: &v13, buffer: data, len: dataLen);
  v11 = idFile_Memory::AtomicWrite(this: &v13, relativePath: &v14, basePath: FSPATH_BASE);
  idFile_Memory::~idFile_Memory(this: &v13);
  return v11;
}


// ========================================================================
// __unwind$219793
// EA  : 0x82694684
// RVA : 0x00694684
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void _unwind_219793()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 736 + 80));
}


// ========================================================================
// ?SetName@idResource@@QAAXPBD@Z
// EA  : 0x82694718
// RVA : 0x00694718
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __fastcall idResource::SetName(idResource *this, const char *_name)
{
  idAtomicString *p_name; // r30
  idStr v4; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v4, text: _name);
  idStr::MakeNameCanonical(this: &v4);
  p_name = &this->name;
  if ( idStr::Cmp(s1: v4.data, s2: p_name->str) != 0 )
    idAtomicString::Set(this: p_name, str_: v4.data);
  idStr::FreeData(this: &v4);
}


// ========================================================================
// __unwind$219887
// EA  : 0x82694788
// RVA : 0x00694788
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void _unwind_219887()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?ReadBinaryHeader@idResource@@SA?AW4resourceError_t@1@PAVidFile@@IGGAAUresourceHeader_t@1@QAD2@Z
// EA  : 0x826947B0
// RVA : 0x006947B0
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

int __fastcall idResource::ReadBinaryHeader(
        idFile *file,
        const unsigned int expectedResourceId,
        const unsigned __int16 expectedVersionHi,
        const unsigned __int16 expectedVersionLo,
        idResource::resourceHeader_t *header,
        char *sourceFileName,
        char *uniqueIdName)
{
  unsigned __int16 *p_sourceFileNameLen; // r28
  unsigned __int16 *p_uniqueIdNameLen; // r29
  char v17; // [sp+50h] [-50h] BYREF

  file->Read(this: file, a2: header, a3: 2u);
  if ( header->headerVersionHi != 1 )
    return 4;
  file->Read(this: file, a2: &header->headerVersionLo, a3: 2u);
  if ( header->headerVersionLo != 1 )
    return 4;
  file->Read(this: file, a2: &header->resourceId, a3: 4u);
  if ( header->resourceId != expectedResourceId )
    return 2;
  file->Read(this: file, a2: &header->versionHi, a3: 2u);
  if ( header->versionHi != expectedVersionHi )
    return 5;
  file->Read(this: file, a2: &header->versionLo, a3: 2u);
  if ( header->versionLo != expectedVersionLo )
    return 5;
  file->Read(this: file, a2: &header->sourceTimestamp, a3: 4u);
  p_sourceFileNameLen = &header->sourceFileNameLen;
  file->Read(this: file, a2: &header->sourceFileNameLen, a3: 2u);
  if ( header->sourceFileNameLen >= 0x100u )
    return 3;
  p_uniqueIdNameLen = &header->uniqueIdNameLen;
  file->Read(this: file, a2: &header->uniqueIdNameLen, a3: 2u);
  if ( header->uniqueIdNameLen >= 0x100u )
    return 3;
  file->Read(this: file, a2: &header->platform, a3: 1u);
  file->Read(this: file, a2: header->pad, a3: 3u);
  file->Read(this: file, a2: &header->uniqueId, a3: 8u);
  file->Read(this: file, a2: &header->hash, a3: 8u);
  file->Read(this: file, a2: &header->dataOffset, a3: 8u);
  file->Read(this: file, a2: &header->totalSize, a3: 8u);
  file->Read(this: file, a2: sourceFileName, a3: *p_sourceFileNameLen);
  sourceFileName[*p_sourceFileNameLen] = 0;
  file->Read(this: file, a2: uniqueIdName, a3: *p_uniqueIdNameLen);
  uniqueIdName[*p_uniqueIdNameLen] = 0;
  file->Read(this: file, a2: &v17, a3: LODWORD(header->dataOffset) - *p_sourceFileNameLen - *p_uniqueIdNameLen - 56);
  return 0;
}


// ========================================================================
// `dynamic initializer for 'resource_showLocalized''
// EA  : 0x8333C110
// RVA : 0x0133C110
// PDB : w:\tech5\engine\framework\resource.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_showLocalized__()
{
  idCVar::idCVar(
    this: &resource_showLocalized,
    name: "resource_showLocalized",
    value: "0",
    flags: 1,
    description: "1 = show all localized resource names",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_showLocalized__);
}

