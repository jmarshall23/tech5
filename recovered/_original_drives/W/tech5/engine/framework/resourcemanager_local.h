
// ========================================================================
// ??1idResourceFileEntry@@QAA@XZ
// EA  : 0x82699D60
// RVA : 0x00699D60
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

void __fastcall idResourceFileEntry::~idResourceFileEntry(idResourceFileEntry *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stream);
  idStr::FreeData(this: &this->filename);
  idStr::FreeData(this: &this->resourceName);
  idStr::FreeData(this: &this->typeName);
}


// ========================================================================
// __unwind$248263
// EA  : 0x82699DB8
// RVA : 0x00699DB8
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

void _unwind_248263()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$248264
// EA  : 0x82699DE4
// RVA : 0x00699DE4
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

void _unwind_248264()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// __unwind$248265
// EA  : 0x82699E10
// RVA : 0x00699E10
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

void _unwind_248265()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 360));
}


// ========================================================================
// ??0idResourceFileEntry@@QAA@XZ
// EA  : 0x8269A1E0
// RVA : 0x0069A1E0
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

idResourceFileEntry *__fastcall idResourceFileEntry::idResourceFileEntry(idResourceFileEntry *this)
{
  this->typeName.allocedAndFlag = 20;
  this->typeName.baseBuffer[0] = 0;
  this->typeName.data = this->typeName.buffer;
  this->typeName.buffer[0] = 0;
  this->typeName.len = 0;
  this->typeName.allocedAndFlag = -2147483616;
  this->resourceName.allocedAndFlag = 20;
  this->resourceName.baseBuffer[0] = 0;
  this->resourceName.buffer[0] = 0;
  this->resourceName.data = this->resourceName.buffer;
  this->resourceName.len = 0;
  this->resourceName.allocedAndFlag = -2147483392;
  this->filename.allocedAndFlag = 20;
  this->filename.baseBuffer[0] = 0;
  this->filename.data = this->filename.buffer;
  this->filename.buffer[0] = 0;
  this->filename.len = 0;
  this->filename.allocedAndFlag = -2147483392;
  idStaticList<idPlatformStreamData,16>::idStaticList<idPlatformStreamData,16>(this: &this->stream);
  this->resourceList = nullptr;
  this->offset = 0;
  this->resourceIndex = -1;
  this->uncompressedLength = 0;
  this->compressedLength = 0;
  this->useBits = 0;
  this->lang[0] = 0;
  return this;
}


// ========================================================================
// ?Read@idResourceFileEntry@@QAAIPAVidFile@@@Z
// EA  : 0x8269A2B8
// RVA : 0x0069A2B8
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

unsigned int __fastcall idResourceFileEntry::Read(idResourceFileEntry *this, idFile *f)
{
  __int64 v3; // r30
  idResourceList *v4; // r3
  int v5; // r25
  unsigned int v6; // r26
  unsigned int v7; // r27
  unsigned int v8; // r30
  unsigned int v9; // r11
  int v10; // r28
  int i; // r27
  idFile_vtbl *v12; // r10
  int v13; // r27
  unsigned int v14; // r25
  unsigned int v15; // r3
  _DWORD v17[4]; // [sp+50h] [-70h] BYREF
  idPlatformStreamData v18[3]; // [sp+60h] [-60h] BYREF

  HIDWORD(v3) = this;
  LODWORD(v3) = f->Read(this: f, a2: this, a3: 4u);
  LODWORD(v3) = idFile::ReadString(this: f, string: (idStr *)(HIDWORD(v3) + 8)) + v3;
  v4 = idResourceList::ForTypeName(typeName: *(const char **)(HIDWORD(v3) + 12));
  *(_DWORD *)(HIDWORD(v3) + 4) = v4;
  if ( v4 == nullptr )
    idLib::FatalError(fmt: "Bad resource type name: %s", *(const char **)(HIDWORD(v3) + 12));
  LODWORD(v3) = idFile::ReadString(this: f, string: (idStr *)(HIDWORD(v3) + 72)) + v3;
  v5 = idFile::ReadString(this: f, string: (idStr *)(HIDWORD(v3) + 360)) + v3;
  v6 = f->Read(this: f, a2: (void *)(HIDWORD(v3) + 648), a3: 4u);
  v7 = f->Read(this: f, a2: (void *)(HIDWORD(v3) + 656), a3: 4u);
  v8 = f->Read(this: f, a2: (void *)(HIDWORD(v3) + 652), a3: 4u);
  v9 = f->Read(this: f, a2: v17, a3: 4u) + v8 + v7;
  LODWORD(v3) = 0;
  v10 = 0;
  for ( i = v9 + v6 + v5; v10 < v17[0]; ++v10 )
  {
    v12 = f->__vftable;
    *(_QWORD *)v18[0].lang = v3;
    *(_QWORD *)&v18[0].lang[8] = v3;
    v18[0].streamAlignment = 0;
    v18[0].streamLength = 0;
    v18[0].streamData = nullptr;
    v13 = v12->Read(this: f, a2: v18, a3: 16u) + i;
    v14 = f->Read(this: f, a2: &v18[0].streamAlignment, a3: 4u);
    v15 = f->Read(this: f, a2: &v18[0].streamLength, a3: 4u);
    v18[0].streamData = nullptr;
    i = v15 + v14 + v13;
    idList<idPlatformStreamData,5>::Append(this: (idList<idPlatformStreamData,5> *)(HIDWORD(v3) + 660), obj: v18);
  }
  LODWORD(v3) = f->Read(this: f, a2: (void *)(HIDWORD(v3) + 1124), a3: 16u) + i;
  return f->Read(this: f, a2: (void *)(HIDWORD(v3) + 1140), a3: 4u) + v3;
}


// ========================================================================
// ?CancelToTerminate@idResourceManagerLocal@@UAAXXZ
// EA  : 0x8269C020
// RVA : 0x0069C020
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

void __fastcall idResourceManagerLocal::CancelToTerminate(idResourceManagerLocal *this)
{
  this->cancelToTerminate = true;
}


// ========================================================================
// ?GetStreamFile@idResourceManagerLocal@@UAAPAVidFile@@XZ
// EA  : 0x8269C030
// RVA : 0x0069C030
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

idFile *__fastcall idResourceManagerLocal::GetStreamFile(idResourceManagerLocal *this)
{
  if ( this->streamFile != nullptr )
    return this->streamFile;
  else
    return this->GetCacheFile(this);
}


// ========================================================================
// ?GetLocalizedStreamFile@idResourceManagerLocal@@UAAPAVidFile@@XZ
// EA  : 0x8269C058
// RVA : 0x0069C058
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

idFile *__fastcall idResourceManagerLocal::GetLocalizedStreamFile(idResourceManagerLocal *this)
{
  if ( this->localizedStreamFile != nullptr )
    return this->localizedStreamFile;
  else
    return this->GetStreamFile(this);
}


// ========================================================================
// ?SetResourceFilePlatform@idResourceManagerLocal@@UAAXI@Z
// EA  : 0x8269C080
// RVA : 0x0069C080
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

void __fastcall idResourceManagerLocal::SetResourceFilePlatform(
        idResourceManagerLocal *this,
        unsigned int platformFlags)
{
  this->filePlatformBits = platformFlags;
}


// ========================================================================
// ?GetBuildPlatforms@idResourceManagerLocal@@UAAIXZ
// EA  : 0x8269C088
// RVA : 0x0069C088
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

unsigned int __fastcall idResourceManagerLocal::GetBuildPlatforms(idResourceManagerLocal *this)
{
  return this->buildPlatforms;
}


// ========================================================================
// ?GetLanguages@idResourceManagerLocal@@UAAABV?$idList@VidStr@@$04@@XZ
// EA  : 0x8269C090
// RVA : 0x0069C090
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

const idList<idStr,5> *__fastcall idResourceManagerLocal::GetLanguages(idResourceManagerLocal *this)
{
  return &this->languages;
}


// ========================================================================
// ?GetPatchFile@idResourceManagerLocal@@UAAPAVidFile@@H@Z
// EA  : 0x8269C098
// RVA : 0x0069C098
// PDB : w:\tech5\engine\framework\resourcemanager_local.h
// ========================================================================

idFile *__fastcall idResourceManagerLocal::GetPatchFile(idResourceManagerLocal *this, const int fileIdx)
{
  if ( this->patchFiles.num != 0 )
    return this->patchFiles.list[fileIdx];
  else
    return nullptr;
}

