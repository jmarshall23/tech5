
// ========================================================================
// ?CacheFilePreCallback@@YAPAVidFile@@QBD@Z
// EA  : 0x82697D58
// RVA : 0x00697D58
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Memory *__fastcall CacheFilePreCallback(const char *filename)
{
  return resourceManager->LoadCacheFile(this: resourceManager, a2: filename);
}


// ========================================================================
// ?StatCacheFilePreCallback@@YAPAVidFile@@QBD@Z
// EA  : 0x82697D78
// RVA : 0x00697D78
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Stat *__fastcall StatCacheFilePreCallback(const char *filename)
{
  return resourceManager->StatCacheFile(this: resourceManager, a2: filename);
}


// ========================================================================
// ?PatchFilePreCallback@@YAPAVidFile@@QBD@Z
// EA  : 0x82697D98
// RVA : 0x00697D98
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Memory *__fastcall PatchFilePreCallback(const char *filename)
{
  return resourceManager->LoadPatchFile(this: resourceManager, a2: filename);
}


// ========================================================================
// ?Shutdown@idResourceManagerLocal@@UAAXXZ
// EA  : 0x82697DB8
// RVA : 0x00697DB8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::Shutdown(idResourceManagerLocal *this)
{
  idBackgroundLoader::DestroyThreads(this: &bgl);
}


// ========================================================================
// ?CloseOpenFileHandles@idResourceManagerLocal@@UAAXXZ
// EA  : 0x82697DC8
// RVA : 0x00697DC8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::CloseOpenFileHandles(idResourceManagerLocal *this)
{
  idFile *resourceFile; // r3
  idFile *streamFile; // r3
  idFile *localizedStreamFile; // r3
  idFile *cachedStreamFile; // r3

  resourceFile = this->resourceFile;
  if ( resourceFile != nullptr )
    ((void (__fastcall *)(idFile *, int))resourceFile->dtr_idFile)(a1: resourceFile, a2: 1);
  streamFile = this->streamFile;
  this->resourceFile = nullptr;
  if ( streamFile != nullptr )
    ((void (__fastcall *)(idFile *, int))streamFile->dtr_idFile)(a1: streamFile, a2: 1);
  localizedStreamFile = this->localizedStreamFile;
  this->streamFile = nullptr;
  if ( localizedStreamFile != nullptr )
    ((void (__fastcall *)(idFile *, int))localizedStreamFile->dtr_idFile)(a1: localizedStreamFile, a2: 1);
  cachedStreamFile = this->cachedStreamFile;
  this->localizedStreamFile = nullptr;
  if ( cachedStreamFile != nullptr )
    ((void (__fastcall *)(idFile *, int))cachedStreamFile->dtr_idFile)(a1: cachedStreamFile, a2: 1);
  this->cachedStreamFile = nullptr;
}


// ========================================================================
// ?SetFileHook@idResourceManagerLocal@@UBAXXZ
// EA  : 0x82697E90
// RVA : 0x00697E90
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::SetFileHook(idResourceManagerLocal *this)
{
  fileSystem->SetFileCacheCallback(
    this: fileSystem,
    a2: (idFile *(__fastcall *)(const char *))CacheFilePreCallback,
    a3: (idFile *(__fastcall *)(const char *))StatCacheFilePreCallback);
}


// ========================================================================
// ?ReleaseFileHook@idResourceManagerLocal@@UBAXXZ
// EA  : 0x82697EB8
// RVA : 0x00697EB8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::ReleaseFileHook(idResourceManagerLocal *this)
{
  fileSystem->SetFileCacheCallback(this: fileSystem, a2: nullptr, a3: nullptr);
}


// ========================================================================
// ResourceLoadPreCallback
// EA  : 0x82697ED8
// RVA : 0x00697ED8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile *__fastcall ResourceLoadPreCallback(const char *filename)
{
  return idBackgroundLoader::GetFile(this: &bgl, filename);
}


// ========================================================================
// ?StartupComplete@idResourceManagerLocal@@UBAXXZ
// EA  : 0x82697EE8
// RVA : 0x00697EE8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::StartupComplete(idResourceManagerLocal *this)
{
  resourceLoadCallback = nullptr;
}


// ========================================================================
// ?IsResourceFile@idResourceManagerLocal@@UAA_NPAVidFile@@@Z
// EA  : 0x82698070
// RVA : 0x00698070
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::IsResourceFile(idResourceManagerLocal *this, idFile *file)
{
  int num; // r8
  int v4; // r10
  int i; // r11

  if ( file == this->resourceFile )
    return 1;
  num = this->patchFiles.num;
  v4 = 0;
  if ( num > 0 )
  {
    for ( i = 0; file != this->patchFiles.list[i]; ++i )
    {
      if ( ++v4 >= num )
        return 0;
    }
    return 1;
  }
  return 0;
}


// ========================================================================
// ?WaitForVideoOrBackgroundSwaps@idResourceManagerLocal@@AAAXXZ
// EA  : 0x826980C0
// RVA : 0x006980C0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::WaitForVideoOrBackgroundSwaps(idResourceManagerLocal *this)
{
  int i; // r31
  int v3; // r31
  float v4[6]; // [sp+50h] [-110h] BYREF
  char v5; // [sp+68h] [-F8h]
  bool v6; // [sp+69h] [-F7h]
  idSysLocal v7; // [sp+70h] [-F0h] BYREF
  int v8; // [sp+74h] [-ECh]
  int v9; // [sp+78h] [-E8h]
  idSysLocal v10; // [sp+90h] [-D0h] BYREF
  _BYTE v11[64]; // [sp+B0h] [-B0h] BYREF

  if ( renderSystem->BinkVideoIsLoaded(this: renderSystem) )
  {
    for ( i = 100; i != 0; --i )
      sys->GetEvent(this: &v10, result: (sysEvent_t *)sys);
    if ( renderSystem->BinkVideoIsPlaying(this: renderSystem) )
    {
      while ( !this->cancelToTerminate )
      {
        if ( allowAbortingWaitForVideoOrBackgroundSwaps )
        {
          v4[0] = 0.0;
          v4[1] = 1.0;
          v5 = 0;
          v4[2] = 1.0;
          v4[3] = joy_pitchSpeed.valueFloat;
          v3 = 0;
          v4[4] = joy_yawSpeed.valueFloat;
          v6 = in_invertLook.valueInteger != 0;
          v4[5] = m_sensitivity.valueFloat;
          do
            usercmdGen->GetUsercmd(
              this: (idUsercmdGen *)v11,
              result: (usercmd_t *)usercmdGen,
              a3: v3++,
              a4: (const inputSettings_t *)v4,
              a5: false,
              a6: 0);
          while ( v3 < 4 );
          sys->GenerateEvents(this: sys);
          sys->GetEvent(this: &v7, result: (sysEvent_t *)sys);
          if ( v7.__vftable == (idSysLocal_vtbl *)1 && v9 == 0 && (v8 == 1 || v8 == 257) )
          {
            sys->ClearEvents(this: sys);
            break;
          }
        }
        session->UpdateSignInManager(this: session);
        mgthread_sleep(ms: 10);
        if ( !renderSystem->BinkVideoIsPlaying(this: renderSystem) )
          break;
      }
    }
    renderSystem->FreeBinkVideo(this: renderSystem);
  }
}


// ========================================================================
// ?DefaultMissing@idResourceManagerLocal@@AAAXPBD@Z
// EA  : 0x826982D0
// RVA : 0x006982D0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::DefaultMissing(idResourceManagerLocal *this, const char *name)
{
  D3DXCore::CBuffer *BufferPointer; // r30
  unsigned __int8 *m_pbBuffer; // r28
  int i; // r29
  __int64 v6; // r10
  __int64 v7; // r8
  idResource *v8; // r3
  idResource *v9; // r31
  __int64 v10; // r6
  int v11; // [sp+8h] [-88h]
  int v12; // [sp+Ch] [-84h]
  int v13; // [sp+10h] [-80h]
  int v14; // [sp+14h] [-7Ch]
  int v15; // [sp+18h] [-78h]
  int v16; // [sp+1Ch] [-74h]

  BufferPointer = (D3DXCore::CBuffer *)listOfResourceLists;
  if ( listOfResourceLists != nullptr )
  {
    do
    {
      m_pbBuffer = BufferPointer->m_pbBuffer;
      for ( i = 0; i < (int)m_pbBuffer; ++i )
      {
        v8 = idResourceList::Index(this: (idResourceList *)BufferPointer, index: i);
        v9 = v8;
        if ( (*((_BYTE *)v8 + 32) & 8) != 0 )
        {
          HIDWORD(v10) = v8->name.str;
          LODWORD(v10) = name;
          LODWORD(v6) = *((_BYTE *)v8 + 32) & 8;
          idResource::SetResourceError(
            this: v8,
            fmt: "LoadNamedResourceBlock %s missing from %s but referenced",
            a3: v10,
            a4: v7,
            a5: v6,
            a6: v11,
            a7: v12,
            a8: v13,
            a9: v14,
            a10: v15,
            a11: v16);
          idResourceList::Load(
            this: (idResourceList *)BufferPointer,
            name: (char *)v9->name.str,
            makeDefault: true,
            skipStaleCheck: false);
        }
      }
      BufferPointer = (D3DXCore::CBuffer *)D3DXShader::CConstantTable::GetBufferPointer(this: BufferPointer);
    }
    while ( BufferPointer != nullptr );
  }
}


// ========================================================================
// ?ExcludeImage@idResourceManagerLocal@@UAA_NPBD@Z
// EA  : 0x82698860
// RVA : 0x00698860
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::ExcludeImage(idResourceManagerLocal *this, const char *name)
{
  int v3; // r5
  int v4; // r28
  int v5; // r26
  idStrStatic<16> *v6; // r3
  int v7; // r30
  const char **v8; // r28
  idStr v10; // [sp+50h] [-250h] BYREF
  _BYTE v11[16]; // [sp+70h] [-230h] BYREF
  idStr v12; // [sp+80h] [-220h] BYREF
  char v13; // [sp+A0h] [-200h] BYREF
  idStrStatic<16> v14; // [sp+120h] [-180h] BYREF
  idStrStatic<16> v15; // [sp+150h] [-150h] BYREF
  idStrStatic<16> v16; // [sp+180h] [-120h] BYREF
  idStrStatic<128> v17; // [sp+1B0h] [-F0h] BYREF

  if ( !this->denyFonts || idLib::production < PROD_PRODUCTION )
    return 0;
  v3 = 0;
  if ( *fontPrefix != 0 )
  {
    do
      ++v3;
    while ( fontPrefix[v3] != 0 );
  }
  if ( idStr::Icmpn(s1: name, s2: fontPrefix, n: v3) != 0 )
    return 0;
  v4 = 1;
  v5 = 13;
  if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: JAPANESE_LANG) == 0 )
  {
    v4 = 0;
    v5 = 3;
  }
  v10.baseBuffer[0] = 0;
  v11[0] = 0;
  v10.data = v11;
  v10.allocedAndFlag = -2147483632;
  idStrStatic<16>::idStrStatic<16>(this: &v15, text: &byte_8200D768);
  v10.len = v15.len;
  memcpy(Dst: v11, Src: v15.data, Size: v15.len + 1);
  idStr::FreeData(this: &v15);
  if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: POLISH_LANG) == 0
    || idStr::Icmp(s1: sys_lang.valueString.data, s2: CZECH_LANG) == 0 )
  {
    idStrStatic<16>::idStrStatic<16>(this: &v16, text: sys_lang.valueString.data);
    v10.len = v16.len;
    memcpy(Dst: v10.data, Src: v16.data, Size: v16.len + 1);
    v6 = &v16;
    goto LABEL_13;
  }
  if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: RUSSIAN_LANG) == 0 )
  {
    idStrStatic<16>::idStrStatic<16>(this: &v14, text: CYRILLIC_FONT);
    v10.len = v14.len;
    memcpy(Dst: v10.data, Src: v14.data, Size: v14.len + 1);
    v6 = &v14;
LABEL_13:
    idStr::FreeData(this: v6);
  }
  v7 = v4;
  if ( v4 < v5 )
  {
    v8 = &validFontNames[v4];
    while ( 1 )
    {
      v12.baseBuffer[0] = 0;
      v13 = 0;
      v12.data = &v13;
      v12.len = 0;
      v12.allocedAndFlag = -2147483520;
      idStrStatic<128>::idStrStatic<128>(this: &v17, text: fontPrefix);
      v12.len = v17.len;
      memcpy(Dst: v12.data, Src: v17.data, Size: v17.len + 1);
      idStr::FreeData(this: &v17);
      if ( v7 >= 3 )
        idStr::AppendPath(this: &v12, text: v10.data);
      idStr::AppendPath(this: &v12, text: *v8);
      if ( idStr::Icmpn(s1: v12.data, s2: name, n: v12.len) == 0 )
        break;
      idStr::FreeData(this: &v12);
      ++v7;
      ++v8;
      if ( v7 >= v5 )
        goto LABEL_22;
    }
    idStr::FreeData(this: &v12);
  }
LABEL_22:
  if ( v7 == v5 )
  {
    idStr::FreeData(this: &v10);
    return 1;
  }
  idStr::FreeData(this: &v10);
  return 0;
}


// ========================================================================
// __unwind$246827
// EA  : 0x82698ACC
// RVA : 0x00698ACC
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_246827()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 80));
}


// ========================================================================
// __unwind$246831
// EA  : 0x82698AF4
// RVA : 0x00698AF4
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_246831()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 128));
}


// ========================================================================
// ?GetCurrentDiscNumber@idResourceManagerLocal@@UAAHXZ
// EA  : 0x82698B28
// RVA : 0x00698B28
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::GetCurrentDiscNumber(idResourceManagerLocal *this)
{
  int result; // r3
  const char *v2; // r3
  idStr v3; // [sp+50h] [-380h] BYREF
  _BYTE v4[256]; // [sp+70h] [-360h] BYREF
  idStr v5; // [sp+170h] [-260h] BYREF
  char v6; // [sp+190h] [-240h] BYREF
  idStrStatic<256> v7; // [sp+290h] [-140h] BYREF

  result = xen_currentDisc.valueInteger;
  if ( xen_currentDisc.valueInteger == -1 )
  {
    v5.baseBuffer[0] = 0;
    v6 = 0;
    v5.data = &v6;
    v5.len = 0;
    v5.allocedAndFlag = -2147483392;
    v3.baseBuffer[0] = 0;
    v4[0] = 0;
    v3.data = v4;
    v3.len = 0;
    v3.allocedAndFlag = -2147483392;
    v2 = fileSystem->GetBasePathStr(this: fileSystem, a2: 0);
    idStrStatic<256>::idStrStatic<256>(this: &v7, text: v2);
    v5.len = v7.len;
    memcpy(Dst: v5.data, Src: v7.data, Size: v7.len + 1);
    idStr::FreeData(this: &v7);
    v3.len = v5.len;
    memcpy(Dst: v4, Src: v5.data, Size: v5.len + 1);
    idStr::AppendPath(this: &v3, text: "virtualtextures/wellspring_coop.pages");
    if ( fileSystem->FileExists(this: fileSystem, a2: v3.data, a3: true) )
    {
      idStr::FreeData(this: &v3);
      idStr::FreeData(this: &v5);
      return 3;
    }
    else
    {
      v3.len = v5.len;
      memcpy(Dst: v3.data, Src: v5.data, Size: v5.len + 1);
      idStr::AppendPath(this: &v3, text: "virtualtextures/subway_town.pages");
      if ( fileSystem->FileExists(this: fileSystem, a2: v3.data, a3: true) )
      {
        idStr::FreeData(this: &v3);
        idStr::FreeData(this: &v5);
        return 2;
      }
      else
      {
        v3.len = v5.len;
        memcpy(Dst: v3.data, Src: v5.data, Size: v5.len + 1);
        idStr::AppendPath(this: &v3, text: "virtualtextures/wellspring.pages");
        if ( fileSystem->FileExists(this: fileSystem, a2: v3.data, a3: true) )
        {
          idStr::FreeData(this: &v3);
          idStr::FreeData(this: &v5);
          return 1;
        }
        else
        {
          idStr::FreeData(this: &v3);
          idStr::FreeData(this: &v5);
          return 0;
        }
      }
    }
  }
  return result;
}


// ========================================================================
// __unwind$247148
// EA  : 0x82698D3C
// RVA : 0x00698D3C
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247148()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 368));
}


// ========================================================================
// __unwind$247149
// EA  : 0x82698D64
// RVA : 0x00698D64
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247149()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 976 + 80));
}


// ========================================================================
// ?MiscellaneousFilePreCallback@@YAPAVidFile@@QBD@Z
// EA  : 0x82698D98
// RVA : 0x00698D98
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Memory *__fastcall MiscellaneousFilePreCallback(const char *filename)
{
  idFileResource *Existing; // r3
  idFile_Memory *Only; // r30
  idStr v5; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v5, text: filename);
  idStr::MakeNameCanonical(this: &v5);
  Existing = (idFileResource *)idResourceList::FindExisting(
                                 this: &idFileResource::resourceList,
                                 name: v5.data,
                                 skipStaleCheck: false);
  if ( Existing != nullptr )
  {
    Only = idFileResource::GetFileReadOnly(this: Existing);
  }
  else
  {
    idLib::Warning(fmt: "File '%s' wasn't preloaded, trying to slow load it from disc", v5.data);
    Only = resourceManager->LoadCacheFile(this: resourceManager, a2: filename);
  }
  idStr::FreeData(this: &v5);
  return Only;
}


// ========================================================================
// __unwind$247434
// EA  : 0x82698E44
// RVA : 0x00698E44
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247434()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetCacheFileInfo@idResourceManagerLocal@@UAA_NPBDAA_JAAI22_N@Z
// EA  : 0x82698E78
// RVA : 0x00698E78
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::GetCacheFileInfo(
        idResourceManagerLocal *this,
        const char *fileName,
        __int64 *offset,
        unsigned int *compressedSize,
        unsigned int *uncompressedSize,
        unsigned int *streamOffset,
        bool allowMiss)
{
  idResourceCacheEntry *v7; // r29
  __int64 v8; // r11
  int i; // r30
  __int64 v17; // r11
  idStrStatic<256> v19; // [sp+50h] [-180h] BYREF

  LODWORD(v8) = 0;
  *offset = v8;
  *uncompressedSize = 0;
  *compressedSize = 0;
  if ( this->resourceFile == nullptr )
  {
    if ( !allowMiss )
      idLib::FatalError(fmt: "GetCacheFileInfo: resourceFile not set");
    idLib::Printf(fmt: "no resource file for getcachefileinfo for %s\n", fileName);
    return 0;
  }
  idStrStatic<256>::idStrStatic<256>(this: &v19, text: fileName);
  idStr::MakeNameCanonical(this: &v19);
  for ( i = this->cacheHash.hash[this->cacheHash.hashMask
                               & this->cacheHash.lookupMask
                               & idHashIndex::GenerateKeyForString(
                                   this: &this->cacheHash,
                                   string: v19.data,
                                   caseSensitive: true)]; i != -1; i = this->cacheHash.indexChain[this->cacheHash.lookupMask & i] )
  {
    v7 = &this->cacheTable.list[i];
    if ( idStr::Icmp(s1: v7->filename.str, s2: v19.data) == 0 )
      goto _LN57_0;
  }
  if ( !allowMiss )
  {
    idLib::FatalError(fmt: "GetCacheFileInfo: %s not found", fileName);
_LN57_0:
    LODWORD(v17) = v7->offset;
    *offset = v17;
    *uncompressedSize = v7->uncompressedLength;
    *compressedSize = v7->compressedLength;
    *streamOffset = v7->streamOffset;
    idStr::FreeData(this: &v19);
    return 1;
  }
  idLib::Warning(fmt: "%s was not in the cache table", fileName);
  idStr::FreeData(this: &v19);
  return 0;
}


// ========================================================================
// $LN43
// EA  : 0x82698FEC
// RVA : 0x00698FEC
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _LN43()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// ?GetPatchFileInfo@idResourceManagerLocal@@UAA_NPBDAA_JAAI22AAH@Z
// EA  : 0x82699020
// RVA : 0x00699020
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::GetPatchFileInfo(
        idResourceManagerLocal *this,
        const char *fileName,
        __int64 *offset,
        unsigned int *compressedSize,
        unsigned int *uncompressedSize,
        unsigned int *streamOffset,
        int *fileIdx)
{
  __int64 v8; // r26
  int v13; // r29
  idResourceCacheEntry *v14; // r30
  __int64 v15; // r11
  idStrStatic<256> v17; // [sp+50h] [-180h] BYREF

  LODWORD(v8) = 0;
  *fileIdx = 0;
  HIDWORD(v8) = offset;
  *offset = v8;
  *uncompressedSize = 0;
  *compressedSize = 0;
  if ( this->patchTable.num == 0 )
    return 0;
  idStrStatic<256>::idStrStatic<256>(this: &v17, text: fileName);
  idStr::MakeNameCanonical(this: &v17);
  v13 = this->patchHash.hash[this->patchHash.hashMask
                           & this->patchHash.lookupMask
                           & idHashIndex::GenerateKeyForString(
                               this: &this->patchHash,
                               string: v17.data,
                               caseSensitive: true)];
  if ( v13 == -1 )
  {
LABEL_5:
    idStr::FreeData(this: &v17);
    return 0;
  }
  while ( 1 )
  {
    v14 = &this->patchTable.list[v13];
    if ( idStr::Icmp(s1: v14->filename.str, s2: v17.data) == 0 )
      break;
    v13 = this->patchHash.indexChain[this->patchHash.lookupMask & v13];
    if ( v13 == -1 )
      goto LABEL_5;
  }
  LODWORD(v15) = v14->offset;
  *(_QWORD *)HIDWORD(v8) = v15;
  *uncompressedSize = v14->uncompressedLength;
  *compressedSize = v14->compressedLength;
  *streamOffset = v14->streamOffset;
  *fileIdx = 0;
  idStr::FreeData(this: &v17);
  return 1;
}


// ========================================================================
// __unwind$247563
// EA  : 0x8269913C
// RVA : 0x0069913C
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247563()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 80));
}


// ========================================================================
// ?LoadCacheFile@idResourceManagerLocal@@UAAPAVidFile_Memory@@PBD@Z
// EA  : 0x82699170
// RVA : 0x00699170
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Memory *__fastcall idResourceManagerLocal::LoadCacheFile(idResourceManagerLocal *this, const char *fileName)
{
  idFile_Memory *v4; // r29
  char *v6; // r27
  char *v7; // r3
  int v8; // r8
  char *buffer; // r30
  int v10; // r8
  _QWORD *v11; // r10
  __int64 v12; // r9
  int i; // ctr
  void *v14; // [sp+50h] [-2E0h] BYREF
  void *v15; // [sp+54h] [-2DCh] BYREF
  idTempArray<char> v16; // [sp+58h] [-2D8h] BYREF
  idFile *v17[2]; // [sp+60h] [-2D0h] BYREF
  _BYTE v18[8]; // [sp+68h] [-2C8h] BYREF
  z_stream_s v19; // [sp+70h] [-2C0h] BYREF
  idStr v20; // [sp+B0h] [-280h] BYREF
  char v21[256]; // [sp+D0h] [-260h] BYREF
  idStrStatic<256> v22; // [sp+1D0h] [-160h] BYREF

  if ( this->cancelToTerminate )
    return nullptr;
  v20.baseBuffer[0] = 0;
  v21[0] = 0;
  v20.data = v21;
  v20.allocedAndFlag = -2147483392;
  idStrStatic<256>::idStrStatic<256>(this: &v22, text: fileName);
  v20.len = v22.len;
  memcpy(Dst: v21, Src: v22.data, Size: v22.len + 1);
  idStr::FreeData(this: &v22);
  if ( idStr::Find(searchIn: v21, searchFor: ".mapresources", casesensitive: false, start: 0, end: v20.len) == -1 )
  {
    v4 = this->LoadPatchFile(this, a2: fileName);
    if ( v4 != nullptr )
    {
      idLib::Printf(fmt: "PATCH OVERRIDE: %s\n", fileName);
      goto LABEL_26;
    }
  }
  if ( !resourceManager->GetCacheFileInfo(
          this: resourceManager,
          a2: fileName,
          a3: (__int64 *)v17,
          a4: (unsigned int *)&v15,
          a5: (unsigned int *)&v14,
          a6: (unsigned int *)v18,
          a7: true) )
  {
    idStr::FreeData(this: &v20);
    return nullptr;
  }
  v6 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\framework\\ResourceManager.cpp(869) : TAG_RESOURCE",
                 size: (unsigned int)v14,
                 tag: TAG_RESOURCE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v7 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                 size: 0x14Cu,
                 tag: TAG_RESOURCE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v16.buffer = v7;
  if ( v7 != nullptr )
    v4 = idFile_Memory::idFile_Memory(this: (idFile_Memory *)v7, name: fileName);
  else
    v4 = nullptr;
  idFile_Memory::SetReadOnlyData(this: v4, data: v6, length: (unsigned int)v14);
  v4->ownsData = true;
  if ( v14 != v15 )
  {
    idTempArray<char>::idTempArray<char>(this: &v16, num: (unsigned int)v15);
    buffer = v16.buffer;
    idStreamFileCache::UncachedScheduledRead(
      this: streamFileCache,
      file: v17[0],
      ofs: __SPAIR64__((unsigned int)v17[1], (unsigned int)v16.buffer),
      dest: v15,
      length: v10);
    v11 = v18;
    LODWORD(v12) = 0;
    for ( i = 7; i != 0; --i )
      *++v11 = v12;
    v19.zalloc = ZlibAlloc;
    v19.zfree = ZlibFree;
    if ( inflateInit2_(strm: &v19, windowBits: -15, version: "1.2.3", stream_size: 56) != 0 )
    {
      idLib::Warning(fmt: "zlib inflateInit2 error");
      if ( buffer != nullptr )
        idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    }
    else
    {
      v19.next_in = (unsigned __int8 *)buffer;
      v19.next_out = (unsigned __int8 *)v6;
      v19.avail_in = (unsigned int)v15;
      v19.avail_out = (unsigned int)v14;
      if ( inflate(strm: &v19, flush: 4) == 0 || (void *)v19.total_out == v14 )
      {
        inflateEnd(strm: &v19);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        goto LABEL_26;
      }
      idLib::Warning(fmt: "zlib inflate error");
      if ( buffer != nullptr )
        idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    }
    idStr::FreeData(this: &v20);
    return nullptr;
  }
  idStreamFileCache::UncachedScheduledRead(
    this: streamFileCache,
    file: v17[0],
    ofs: __SPAIR64__((unsigned int)v17[1], (unsigned int)v6),
    dest: v14,
    length: v8);
LABEL_26:
  idStr::FreeData(this: &v20);
  return v4;
}


// ========================================================================
// __unwind$247653
// EA  : 0x82699490
// RVA : 0x00699490
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247653()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 816 + 176));
}


// ========================================================================
// __unwind$247655
// EA  : 0x826994B8
// RVA : 0x006994B8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247655()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 816 + 88), tag: TAG_RESOURCE);
}


// ========================================================================
// __unwind$247656
// EA  : 0x826994E4
// RVA : 0x006994E4
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247656()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 816 + 88));
}


// ========================================================================
// ?StatCacheFile@idResourceManagerLocal@@UAAPAVidFile_Stat@@PBD@Z
// EA  : 0x82699518
// RVA : 0x00699518
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Stat *__fastcall idResourceManagerLocal::StatCacheFile(idResourceManagerLocal *this, const char *fileName)
{
  idFile_Stat *v4; // r29
  unsigned int v6; // r7
  idFile_Stat *v7; // r3
  __int64 v8; // r6
  idFile_Stat *v9; // r30
  _DWORD v10[2]; // [sp+50h] [-290h] BYREF
  int v11; // [sp+58h] [-288h] BYREF
  int v12; // [sp+5Ch] [-284h] BYREF
  int v13; // [sp+60h] [-280h] BYREF
  idStr v14; // [sp+70h] [-270h] BYREF
  char v15[256]; // [sp+90h] [-250h] BYREF
  idStrStatic<256> v16; // [sp+190h] [-150h] BYREF

  if ( this->cancelToTerminate )
    return nullptr;
  v14.baseBuffer[0] = 0;
  v15[0] = 0;
  v14.data = v15;
  v14.allocedAndFlag = -2147483392;
  idStrStatic<256>::idStrStatic<256>(this: &v16, text: fileName);
  v14.len = v16.len;
  memcpy(Dst: v15, Src: v16.data, Size: v16.len + 1);
  idStr::FreeData(this: &v16);
  if ( idStr::Find(searchIn: v15, searchFor: ".mapresources", casesensitive: false, start: 0, end: v14.len) == -1 )
  {
    v4 = this->StatPatchFile(this, a2: fileName);
    if ( v4 != nullptr )
    {
      idLib::Printf(fmt: "PATCH OVERRIDE: %s\n", fileName);
      idStr::FreeData(this: &v14);
      return v4;
    }
  }
  if ( !resourceManager->GetCacheFileInfo(
          this: resourceManager,
          a2: fileName,
          a3: (__int64 *)&v13,
          a4: (unsigned int *)&v11,
          a5: v10,
          a6: (unsigned int *)&v12,
          a7: true) )
  {
    idStr::FreeData(this: &v14);
    return nullptr;
  }
  v7 = (idFile_Stat *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x38u,
                        tag: TAG_RESOURCE,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v10[1] = v7;
  if ( v7 != nullptr )
  {
    LODWORD(v8) = 0;
    HIDWORD(v8) = v10[0];
    v9 = idFile_Stat::idFile_Stat(this: v7, name: fileName, size: v8, timeStamp: v6);
  }
  else
  {
    v9 = nullptr;
  }
  idStr::FreeData(this: &v14);
  return v9;
}


// ========================================================================
// __unwind$247860
// EA  : 0x826996A0
// RVA : 0x006996A0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247860()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 112));
}


// ========================================================================
// __unwind$247862
// EA  : 0x826996C8
// RVA : 0x006996C8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_247862()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 736 + 84), tag: TAG_RESOURCE);
}


// ========================================================================
// ?LoadPatchFile@idResourceManagerLocal@@UAAPAVidFile_Memory@@PBD@Z
// EA  : 0x82699700
// RVA : 0x00699700
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Memory *__fastcall idResourceManagerLocal::LoadPatchFile(idResourceManagerLocal *this, const char *fileName)
{
  char *v4; // r27
  char *v5; // r3
  idFile_Memory *v6; // r28
  char *buffer; // r30
  _QWORD *v9; // r10
  __int64 v10; // r9
  int i; // ctr
  void *v12; // [sp+50h] [-90h] BYREF
  int v13; // [sp+54h] [-8Ch] BYREF
  void *v14; // [sp+58h] [-88h] BYREF
  int v15; // [sp+5Ch] [-84h] BYREF
  idTempArray<char> v16; // [sp+60h] [-80h] BYREF
  _DWORD v17[2]; // [sp+68h] [-78h] BYREF
  z_stream_s v18[2]; // [sp+70h] [-70h] BYREF

  if ( this->cancelToTerminate
    || !resourceManager->GetPatchFileInfo(
          this: resourceManager,
          a2: fileName,
          a3: (__int64 *)v17,
          a4: (unsigned int *)&v14,
          a5: (unsigned int *)&v12,
          a6: (unsigned int *)&v15,
          a7: &v13) )
  {
    return nullptr;
  }
  if ( v13 < 0 || v13 >= this->patchFiles.num )
  {
    idLib::Warning(
      fmt: "GetPatchFileInfo: returned a patch file index out of range. There are %d patch files loaded and the request was %d",
      this->patchFiles.num,
      v13);
    return nullptr;
  }
  idLib::Printf(fmt: "PATCH: %s\n", fileName);
  v4 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\framework\\ResourceManager.cpp(983) : TAG_RESOURCE",
                 size: (unsigned int)v12,
                 tag: TAG_RESOURCE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v5 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                 size: 0x14Cu,
                 tag: TAG_RESOURCE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v16.buffer = v5;
  if ( v5 != nullptr )
    v6 = idFile_Memory::idFile_Memory(this: (idFile_Memory *)v5, name: fileName);
  else
    v6 = nullptr;
  idFile_Memory::SetReadOnlyData(this: v6, data: v4, length: (unsigned int)v12);
  v6->ownsData = true;
  if ( v12 == v14 )
  {
    idStreamFileCache::UncachedScheduledRead(
      this: streamFileCache,
      file: this->patchFiles.list[v13],
      ofs: __SPAIR64__(v17[1], (unsigned int)v4),
      dest: v12,
      length: 4 * v13);
    return v6;
  }
  idTempArray<char>::idTempArray<char>(this: &v16, num: (unsigned int)v14);
  buffer = v16.buffer;
  idStreamFileCache::UncachedScheduledRead(
    this: streamFileCache,
    file: this->patchFiles.list[v13],
    ofs: __SPAIR64__(v17[1], (unsigned int)v16.buffer),
    dest: v14,
    length: 4 * v13);
  v9 = v17;
  LODWORD(v10) = 0;
  for ( i = 7; i != 0; --i )
    *++v9 = v10;
  v18[0].zalloc = ZlibAlloc;
  v18[0].zfree = ZlibFree;
  if ( inflateInit2_(strm: v18, windowBits: -15, version: "1.2.3", stream_size: 56) != 0 )
  {
    idLib::Warning(fmt: "zlib inflateInit2 error");
    if ( buffer == nullptr )
      return nullptr;
LABEL_14:
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
    return nullptr;
  }
  v18[0].next_in = (unsigned __int8 *)buffer;
  v18[0].next_out = (unsigned __int8 *)v4;
  v18[0].avail_in = (unsigned int)v14;
  v18[0].avail_out = (unsigned int)v12;
  if ( inflate(strm: v18, flush: 4) != 0 && (void *)v18[0].total_out != v12 )
  {
    idLib::Warning(fmt: "zlib inflate error");
    if ( buffer == nullptr )
      return nullptr;
    goto LABEL_14;
  }
  inflateEnd(strm: v18);
  if ( buffer != nullptr )
    idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  return v6;
}


// ========================================================================
// __unwind$248001
// EA  : 0x826999A0
// RVA : 0x006999A0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_248001()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 96), tag: TAG_RESOURCE);
}


// ========================================================================
// __unwind$248002
// EA  : 0x826999CC
// RVA : 0x006999CC
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_248002()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 224 + 96));
}


// ========================================================================
// ?StatPatchFile@idResourceManagerLocal@@UAAPAVidFile_Stat@@PBD@Z
// EA  : 0x82699A00
// RVA : 0x00699A00
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idFile_Stat *__fastcall idResourceManagerLocal::StatPatchFile(idResourceManagerLocal *this, const char *fileName)
{
  unsigned int v4; // r7
  idFile_Stat *v5; // r3
  __int64 v6; // r6
  int v8; // [sp+50h] [-40h] BYREF
  int v9; // [sp+54h] [-3Ch] BYREF
  int v10; // [sp+58h] [-38h] BYREF
  _DWORD v11[3]; // [sp+5Ch] [-34h] BYREF
  int v12; // [sp+68h] [-28h] BYREF

  if ( this->cancelToTerminate
    || !resourceManager->GetPatchFileInfo(
          this: resourceManager,
          a2: fileName,
          a3: (__int64 *)&v12,
          a4: v11,
          a5: (unsigned int *)&v9,
          a6: (unsigned int *)&v10,
          a7: &v8) )
  {
    return nullptr;
  }
  if ( v8 < 0 || v8 >= this->patchFiles.num )
  {
    idLib::Warning(
      fmt: "GetPatchFileInfo: returned a patch file index out of range. There are %d patch files loaded and the request was %d",
      this->patchFiles.num,
      v8);
    return nullptr;
  }
  idLib::Printf(fmt: "PATCH: %s\n", fileName);
  v5 = (idFile_Stat *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x38u,
                        tag: TAG_RESOURCE,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v11[1] = v5;
  if ( v5 == nullptr )
    return nullptr;
  LODWORD(v6) = 0;
  HIDWORD(v6) = v9;
  return idFile_Stat::idFile_Stat(this: v5, name: fileName, size: v6, timeStamp: v4);
}


// ========================================================================
// __unwind$248072
// EA  : 0x82699AF0
// RVA : 0x00699AF0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_248072()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 96), tag: TAG_RESOURCE);
}


// ========================================================================
// ?GetNeededResourcesForMap@idResourceManagerLocal@@QAAHQBDQBV?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@1AAV?$idList@H$04@@AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x8269A4D0
// RVA : 0x0069A4D0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::GetNeededResourcesForMap(
        idResourceManagerLocal *this,
        const char *mapName_,
        const idStaticList<idStrStatic<128>,256> *const layersActive,
        const idStaticList<idStrStatic<128>,256> *const layersDeactive,
        idList<enum encounterGroupRole_t,5> *neededResources,
        idList<idStr,5> *neededMegatextures)
{
  int v6; // r29
  int v12; // r17
  idFile_Memory *v13; // r3
  idFile *v14; // r22
  _BYTE *v16; // r11
  int i; // ctr
  char v18; // r21
  _BYTE *v19; // r11
  int j; // ctr
  int k; // r27
  int v22; // r28
  int v23; // r30
  int v24; // r28
  int v25; // r30
  int m; // r28
  int listStatic; // r11
  int *list; // r4
  int n; // r30
  char *v30; // r11
  int ii; // ctr
  int v32; // r11
  char v33; // r11
  int v34; // r3
  int size; // r6
  int v36; // r4
  int v37; // r30
  bool v38; // r3
  int v39; // r11
  int v40; // r30
  int v41; // [sp+50h] [-220h] BYREF
  int *num; // [sp+54h] [-21Ch]
  int v43; // [sp+58h] [-218h] BYREF
  int v44; // [sp+5Ch] [-214h] BYREF
  int v45; // [sp+60h] [-210h] BYREF
  int v46; // [sp+64h] [-20Ch] BYREF
  int v47; // [sp+68h] [-208h] BYREF
  _BYTE v48[24]; // [sp+6Fh] [-201h] BYREF
  char v49; // [sp+87h] [-1E9h]
  idStr v50; // [sp+90h] [-1E0h] BYREF
  _BYTE v51[32]; // [sp+B0h] [-1C0h] BYREF
  idStr v52; // [sp+D0h] [-1A0h] BYREF
  char v53; // [sp+F0h] [-180h] BYREF

  v6 = 0;
  v52.baseBuffer[0] = 0;
  v53 = 0;
  v52.len = 0;
  v52.data = &v53;
  v52.allocedAndFlag = -2147483392;
  idStr::Format(this: &v52, fmt: "generated/buildGame/%s.mapResources", mapName_);
  v12 = 0;
  v13 = this->LoadCacheFile(this, a2: v52.data);
  v14 = v13;
  if ( v13 != nullptr )
  {
    v16 = v48;
    for ( i = 24; i != 0; --i )
      *++v16 = 0;
    v18 = 0;
    v13->Read(this: v13, a2: &v45, a3: 4u);
    if ( layersActive != nullptr && layersDeactive != nullptr )
    {
      num = (int *)layersActive->num;
      if ( num == nullptr || num == (int *)1 && layersActive->list->len == 0 )
      {
        num = (int *)layersDeactive->num;
        if ( num == nullptr || num == (int *)1 && layersDeactive->list->len == 0 )
          v18 = 1;
      }
    }
    else
    {
      v19 = v48;
      for ( j = 24; j != 0; --j )
        *++v19 = -1;
    }
    for ( k = 0; k < v45; ++k )
    {
      v50.allocedAndFlag = 20;
      v50.len = 0;
      v50.data = v50.baseBuffer;
      v50.baseBuffer[0] = 0;
      idFile::ReadString(this: v14, string: &v50);
      if ( resource_ignoreLayers.valueInteger == 0 && layersActive != nullptr && layersDeactive != nullptr )
      {
        v22 = 0;
        if ( layersActive->num > 0 )
        {
          v23 = 0;
          while ( idStr::Cmp(s1: layersActive->list[v23].data, s2: v50.data) != 0 )
          {
            ++v22;
            ++v23;
            if ( v22 >= layersActive->num )
              goto LABEL_26;
          }
          v48[k / 8 + 1] |= 1 << (k & 7);
        }
LABEL_26:
        v24 = 0;
        if ( layersDeactive->num > 0 )
        {
          v25 = 0;
          while ( idStr::Cmp(s1: layersDeactive->list[v25].data, s2: v50.data) != 0 )
          {
            ++v24;
            ++v25;
            if ( v24 >= layersDeactive->num )
              goto LABEL_32;
          }
          v48[k / 8 + 1] |= 1 << (k & 7);
        }
      }
LABEL_32:
      idStr::FreeData(this: &v50);
    }
    v14->Read(this: v14, a2: &v43, a3: 4u);
    for ( m = 0; m < v43; ++m )
    {
      v14->Read(this: v14, a2: &v47, a3: 4u);
      if ( v18 != 0 )
        v48[v47 / 8 + 1] |= 1 << (v47 & 7);
    }
    listStatic = neededResources->listStatic;
    v49 |= 0x80u;
    if ( listStatic == 0 || listStatic == 2 )
    {
      list = (int *)neededResources->list;
      if ( neededResources->list != nullptr )
      {
        num = (int *)neededResources->list;
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      }
      neededResources->list = nullptr;
      neededResources->size = 0;
    }
    neededResources->num = 0;
    v14->Read(this: v14, a2: &v44, a3: 4u);
    for ( n = 0; n < v44; ++n )
    {
      v30 = &v50.baseBuffer[19];
      for ( ii = 24; ii != 0; --ii )
        *++v30 = 0;
      v14->Read(this: v14, a2: &v46, a3: 4u);
      v14->Read(this: v14, a2: v51, a3: 24u);
      v32 = 0;
      while ( (v51[v32] & v48[v32 + 1]) == 0 )
      {
        if ( (unsigned int)++v32 >= 0x18 )
        {
          v33 = 0;
          goto LABEL_49;
        }
      }
      v33 = 1;
LABEL_49:
      if ( v33 != 0 )
        idList<idAnimWebBlendTree *,5>::Append(this: neededResources, obj: (const encounterGroupRole_t *)&v46);
      else
        ++v12;
    }
    v34 = v14->Read(this: v14, a2: &v41, a3: 4u);
    size = neededMegatextures->size;
    v36 = v34 == 0 ? 0 : v41;
    v37 = v36;
    v41 = v36;
    if ( v36 <= size || (v38 = idList<idStr,3>::Resize(this: neededMegatextures, newsize: v36), v36 = v41, v38) )
    {
      v39 = neededMegatextures->size;
      if ( v37 < v39 )
        v39 = v37;
      neededMegatextures->num = v39;
    }
    if ( v36 > 0 )
    {
      v40 = 0;
      do
      {
        idFile::ReadString(this: v14, string: &neededMegatextures->list[v40]);
        ++v6;
        ++v40;
      }
      while ( v6 < v41 );
    }
    ((void (__fastcall *)(idFile *, int))v14->dtr_idFile)(a1: v14, a2: 1);
    idStr::FreeData(this: &v52);
    return v12;
  }
  else
  {
    idLib::Printf(fmt: "Could not find %s in cache file\n", v52.data);
    idStr::FreeData(this: &v52);
    return -1;
  }
}


// ========================================================================
// __unwind$248866
// EA  : 0x8269A9F8
// RVA : 0x0069A9F8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_248866()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 208));
}


// ========================================================================
// __unwind$248867
// EA  : 0x8269AA20
// RVA : 0x0069AA20
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_248867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 144));
}


// ========================================================================
// ?Init@idResourceManagerLocal@@UAAXXZ
// EA  : 0x8269AC40
// RVA : 0x0069AC40
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::Init(idResourceManagerLocal *this)
{
  unsigned int tableLength; // r5
  idMem *v3; // r29
  void *v4; // r22
  int v5; // r9
  int v6; // r25
  idHashIndex *p_cacheHash; // r26
  int v8; // r21
  int v9; // r24
  int v10; // r11
  idResourceCacheEntry *v11; // r28
  int size; // r11
  int v13; // r27
  int v14; // r29
  int KeyForString; // r29
  int indexSize; // r11
  int v17; // r7
  int v18; // r17
  int v19; // r19
  void *v20; // r21
  int v21; // r4
  int v22; // r29
  char v23; // r3
  int v24; // r11
  int v25; // r25
  idHashIndex *p_patchHash; // r26
  int v27; // r23
  int v28; // r24
  idResourceCacheEntry *v29; // r27
  int v30; // r11
  int v31; // r11
  bool v32; // cr57
  int v33; // r28
  int v34; // r29
  int v35; // r29
  int v36; // r11
  int v37; // r7
  int v38; // [sp+50h] [-370h] BYREF
  int v39; // [sp+54h] [-36Ch] BYREF
  unsigned int v40; // [sp+58h] [-368h] BYREF
  int v41; // [sp+5Ch] [-364h]
  int v42; // [sp+60h] [-360h] BYREF
  idMem *v43; // [sp+64h] [-35Ch]
  int *v44; // [sp+68h] [-358h]
  const char *v45; // [sp+6Ch] [-354h]
  int v46; // [sp+70h] [-350h] BYREF
  int num; // [sp+74h] [-34Ch]
  int v48; // [sp+78h] [-348h] BYREF
  int v49; // [sp+7Ch] [-344h] BYREF
  idFile_Memory v50; // [sp+80h] [-340h] BYREF
  idFile_Memory v51; // [sp+1D0h] [-1F0h] BYREF

  this->buildPlatforms = 0;
  idBackgroundLoader::SpawnThreads(this: &bgl);
  idPhysicalMemoryBlock::Init(this: &physicalMemoryBlock, bytesToAlloc: mem_phyMemBlockSizeM.valueInteger << 20);
  this->denyFonts = false;
  idLib::Printf(fmt: "idLib::SetProduction( PROD_PRODUCTION )\n");
  idLib::production = PROD_PRODUCTION;
  if ( this->ReOpenFileHandles(this) )
  {
    this->resourceMagic = 0;
    this->resourceFile->Read(this: this->resourceFile, a2: &this->resourceMagic, a3: 4u);
    if ( this->resourceMagic != 580168653 )
      idLib::FatalError(fmt: "resourceFileMagic != RESOURCE_FILE_MAGIC");
    this->resourceFile->Read(this: this->resourceFile, a2: &this->tableOffset, a3: 4u);
    this->resourceFile->Read(this: this->resourceFile, a2: &this->tableLength, a3: 4u);
    tableLength = this->tableLength;
    v3 = &mem;
    v43 = &mem;
    v4 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\framework\\ResourceManager.cpp(181) : TAG_RESOURCE",
           size: tableLength,
           tag: TAG_RESOURCE,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    this->resourceFile->ReadOfs(this: this->resourceFile, a2: this->tableOffset, a3: v4, a4: this->tableLength);
    v45 = "resourceHeader";
    idFile_Memory::idFile_Memory(this: &v51, name: "resourceHeader");
    idFile_Memory::SetReadOnlyData(this: &v51, data: (const char *)v4, length: this->tableLength);
    v51.Read(this: &v51, a2: &v42, a3: 4u);
    idList<idResourceCacheEntry,99>::SetNum(this: &this->cacheTable, newNum: v42);
    v5 = -2089746432;
    v41 = -2089746432;
    v6 = 0;
    v44 = idHashIndex::INVALID_INDEX;
    if ( v42 > 0 )
    {
      p_cacheHash = &this->cacheHash;
      v8 = 0;
      v9 = 0;
      while ( 1 )
      {
        v10 = *(_DWORD *)(v5 + 29600);
        v11 = &this->cacheTable.list[v9];
        if ( (v10 & 1) == 0 )
        {
          *(_DWORD *)(v5 + 29600) = v10 | 1;
          idResourceFileEntry::idResourceFileEntry(this: &re_0);
          atexit(func: (void (__fastcall *)())_idResourceManagerLocal::Init_::_10_::_dynamic_atexit_destructor_for__re__);
        }
        size = re_0.stream.size;
        if ( re_0.stream.size < 0 )
        {
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&re_0.stream);
          size = re_0.stream.size;
        }
        re_0.stream.num = __CFADD__(-size, size ^ 0x80000000) ? 0 : size;
        idResourceFileEntry::Read(this: &re_0, f: &v51);
        idAtomicString::Set(this: &v11->filename, str_: re_0.filename.data);
        v11->offset = re_0.offset;
        v11->compressedLength = re_0.compressedLength;
        v11->uncompressedLength = re_0.uncompressedLength;
        if ( re_0.stream.num > 0 )
        {
          v11->streamOffset = re_0.stream.list->streamAlignment;
          if ( re_0.stream.num > 1 )
          {
            v13 = 0;
            if ( re_0.stream.num > 0 )
            {
              v14 = 0;
              while ( idStr::Icmp(s1: sys_lang.valueString.data, s2: re_0.stream.list[v14].lang) != 0 )
              {
                ++v13;
                ++v14;
                if ( v13 >= re_0.stream.num )
                  goto LABEL_19;
              }
              v11->streamOffset = re_0.stream.list[v13].streamAlignment;
            }
          }
        }
LABEL_19:
        KeyForString = idHashIndex::GenerateKeyForString(
                         this: &this->cacheHash,
                         string: v11->filename.str,
                         caseSensitive: false);
        indexSize = this->cacheHash.indexSize;
        if ( p_cacheHash->hash == v44 )
        {
          if ( v6 >= indexSize )
            indexSize = v6 + 1;
          idHashIndex::Allocate(this: &this->cacheHash, newHashSize: this->cacheHash.hashSize, newIndexSize: indexSize);
        }
        else if ( v6 >= indexSize )
        {
          idHashIndex::ResizeIndex(this: &this->cacheHash, newIndexSize: v6 + 1);
        }
        ++v9;
        v17 = KeyForString & this->cacheHash.hashMask;
        this->cacheHash.indexChain[v8++] = p_cacheHash->hash[v17];
        p_cacheHash->hash[v17] = v6++;
        if ( v6 >= v42 )
          break;
        v5 = v41;
      }
      v3 = v43;
    }
    idMem::Free(this: v3, ptr: v4, align: ALIGN_16);
    num = this->patchFiles.num;
    if ( num <= 0 )
    {
LABEL_68:
      idFile_Memory::~idFile_Memory(this: &v51);
    }
    else
    {
      v18 = 0;
      v19 = 0;
      while ( 1 )
      {
        v39 = 0;
        this->patchFiles.list[v19]->Read(this: this->patchFiles.list[v19], a2: &v39, a3: 4u);
        if ( v39 != 580168653 && v39 != 293862076 )
          break;
        this->patchFiles.list[v19]->Read(this: this->patchFiles.list[v19], a2: &v46, a3: 4u);
        this->patchFiles.list[v19]->Read(this: this->patchFiles.list[v19], a2: &v40, a3: 4u);
        if ( v39 == 293862076 )
        {
          this->patchFiles.list[v19]->Read(this: this->patchFiles.list[v19], a2: &v48, a3: 4u);
          this->patchFiles.list[v19]->Read(this: this->patchFiles.list[v19], a2: &v49, a3: 4u);
        }
        v20 = idMem::AllocWithLocation(
                this: v3,
                location: "w:\\tech5\\engine\\framework\\ResourceManager.cpp(245) : TAG_RESOURCE",
                size: v40,
                tag: TAG_RESOURCE,
                zeroBuffer: false,
                align: ALIGN_16,
                heap: HEAP_DEFAULTHEAP);
        this->patchFiles.list[v19]->ReadOfs(this: this->patchFiles.list[v19], a2: v46, a3: v20, a4: v40);
        idFile_Memory::idFile_Memory(this: &v50, name: v45);
        idFile_Memory::SetReadOnlyData(this: &v50, data: (const char *)v20, length: v40);
        v50.Read(this: &v50, a2: &v38, a3: 4u);
        v21 = v38;
        v22 = v38;
        if ( v38 <= this->patchTable.size
          || (v23 = idList<idResourceCacheEntry,99>::Resize(this: &this->patchTable, newsize: v38), v21 = v38, v23 != 0) )
        {
          v24 = this->patchTable.size;
          if ( v22 < v24 )
            v24 = v22;
          this->patchTable.num = v24;
        }
        v25 = 0;
        if ( v21 > 0 )
        {
          p_patchHash = &this->patchHash;
          v27 = 0;
          v28 = 0;
          while ( 1 )
          {
            v29 = &this->patchTable.list[v28];
            v30 = *(_DWORD *)(v41 + 29600);
            if ( (v30 & 2) == 0 )
            {
              *(_DWORD *)(v41 + 29600) = v30 | 2;
              idResourceFileEntry::idResourceFileEntry(this: &re);
              atexit(func: (void (__fastcall *)())_idResourceManagerLocal::Init_::_34_::_dynamic_atexit_destructor_for__re__);
            }
            v31 = re.stream.size;
            v32 = re.stream.size > 0;
            if ( re.stream.size >= 0 )
              goto LABEL_49;
            if ( re.stream.listStatic != 0 && re.stream.listStatic != 2 )
              break;
            if ( re.stream.list != nullptr )
              idMem::Free(this: v43, ptr: re.stream.list, align: ALIGN_16);
            re.stream.list = nullptr;
            v31 = 0;
            re.stream.size = 0;
LABEL_51:
            re.stream.num = v31;
            idResourceFileEntry::Read(this: &re, f: &v50);
            idAtomicString::Set(this: &v29->filename, str_: re.filename.data);
            v29->offset = re.offset;
            v29->compressedLength = re.compressedLength;
            v29->uncompressedLength = re.uncompressedLength;
            if ( re.stream.num > 0 )
            {
              v29->streamOffset = re.stream.list->streamAlignment;
              if ( re.stream.num > 1 )
              {
                v33 = 0;
                if ( re.stream.num > 0 )
                {
                  v34 = 0;
                  while ( idStr::Icmp(s1: sys_lang.valueString.data, s2: re.stream.list[v34].lang) != 0 )
                  {
                    ++v33;
                    ++v34;
                    if ( v33 >= re.stream.num )
                      goto LABEL_59;
                  }
                  v29->streamOffset = re.stream.list[v33].streamAlignment;
                }
              }
            }
LABEL_59:
            v35 = idHashIndex::GenerateKeyForString(
                    this: &this->patchHash,
                    string: re.filename.data,
                    caseSensitive: false);
            v36 = this->patchHash.indexSize;
            if ( p_patchHash->hash == v44 )
            {
              if ( v25 >= v36 )
                v36 = v25 + 1;
              idHashIndex::Allocate(this: &this->patchHash, newHashSize: this->patchHash.hashSize, newIndexSize: v36);
            }
            else if ( v25 >= v36 )
            {
              idHashIndex::ResizeIndex(this: &this->patchHash, newIndexSize: v25 + 1);
            }
            ++v28;
            v37 = v35 & this->patchHash.hashMask;
            this->patchHash.indexChain[v27++] = p_patchHash->hash[v37];
            p_patchHash->hash[v37] = v25++;
            if ( v25 >= v38 )
              goto LABEL_66;
          }
          v32 = re.stream.size > 0;
LABEL_49:
          if ( v32 )
            v31 = 0;
          goto LABEL_51;
        }
LABEL_66:
        v3 = v43;
        idMem::Free(this: v43, ptr: v20, align: ALIGN_16);
        idFile_Memory::~idFile_Memory(this: &v50);
        ++v18;
        ++v19;
        if ( v18 >= this->patchFiles.num )
        {
          fileSystem->SetFilePatchCallback(
            this: fileSystem,
            a2: (idFile *(__fastcall *)(const char *))PatchFilePreCallback);
          goto LABEL_68;
        }
      }
      idLib::FatalError(fmt: "resourceFileMagic != RESOURCE_FILE_MAGIC");
      _LN279();
    }
  }
}


// ========================================================================
// $LN279
// EA  : 0x8269B400
// RVA : 0x0069B400
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _LN279()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 960 + 464));
}


// ========================================================================
// __unwind$249589
// EA  : 0x8269B428
// RVA : 0x0069B428
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_249589()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 960 + 128));
}


// ========================================================================
// ?ReOpenFileHandles@idResourceManagerLocal@@UAA_NXZ
// EA  : 0x8269B458
// RVA : 0x0069B458
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::ReOpenFileHandles(idResourceManagerLocal *this)
{
  idFile *v2; // r3
  idFileList *v4; // r3
  idFileList *v5; // r26
  int v6; // r27
  int v7; // r28
  int v8; // r30
  idFile **list; // r25
  idFile *v10; // r3
  idFile *v11; // r3
  idFile *streamFile; // r11
  int num; // [sp+50h] [-C0h]
  idStr v14; // [sp+60h] [-B0h] BYREF
  char v15; // [sp+80h] [-90h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v2 = fileSystem->OpenFileRead(this: fileSystem, a2: RESOURCE_FILE_NAME, a3: 1, a4: 0);
  this->resourceFile = v2;
  if ( v2 != nullptr )
  {
    idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->patchFiles);
    v4 = fileSystem->ListFiles(this: fileSystem, a2: &byte_8200D768, a3: ".patch", a4: 1, a5: 0);
    v5 = v4;
    if ( v4 != nullptr )
    {
      num = v4->list.num;
      if ( num > 0 )
      {
        idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->patchFiles, newNum: num);
        v6 = 0;
        if ( v5->list.num > 0 )
        {
          v7 = 0;
          v8 = 0;
          do
          {
            list = this->patchFiles.list;
            ++v6;
            list[v7++] = fileSystem->OpenFileRead(this: fileSystem, a2: v5->list.list[v8++].data, a3: 1, a4: 0);
          }
          while ( v6 < v5->list.num );
        }
        idFileList::~idFileList(this: v5);
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
      }
    }
    v10 = fileSystem->OpenFileRead(this: fileSystem, a2: RESOURCE_STREAM_NAME, a3: 1, a4: 0);
    this->streamFile = v10;
    if ( v10 == nullptr )
    {
      idLib::Printf(fmt: "Found a valid resource file but unable to open a streamfile\n");
      this->streamFile = this->resourceFile;
    }
    v14.baseBuffer[0] = 0;
    v15 = 0;
    v14.len = 0;
    v14.data = &v15;
    v14.allocedAndFlag = -2147483616;
    idStr::Format(this: &v14, fmt: "%s.streamed", sys_lang.valueString.data);
    v11 = fileSystem->OpenFileRead(this: fileSystem, a2: v14.data, a3: 1, a4: 0);
    this->localizedStreamFile = v11;
    if ( v11 == nullptr || (int)v11->Length(this: v11) <= 0 )
    {
      if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: CZECH_LANG) == 0 )
        this->localizedStreamFile = fileSystem->OpenFileRead(this: fileSystem, a2: ENGLISH_STREAM, a3: 1, a4: 0);
      if ( this->localizedStreamFile == nullptr
        && fileSystem->FileExists(this: fileSystem, a2: JAPANESE_STREAM, a3: true) )
      {
        this->localizedStreamFile = fileSystem->OpenFileRead(this: fileSystem, a2: JAPANESE_STREAM, a3: 1, a4: 0);
        idCVar::SetString(this: &sys_lang, newValue: JAPANESE_LANG, force: true);
      }
      if ( this->localizedStreamFile == nullptr
        && fileSystem->FileExists(this: fileSystem, a2: RUSSIAN_STREAM, a3: true) )
      {
        this->localizedStreamFile = fileSystem->OpenFileRead(this: fileSystem, a2: RUSSIAN_STREAM, a3: 1, a4: 0);
        idCVar::SetString(this: &sys_lang, newValue: RUSSIAN_LANG, force: true);
      }
      if ( this->localizedStreamFile == nullptr
        && fileSystem->FileExists(this: fileSystem, a2: FRENCH_STREAM, a3: true)
        && !fileSystem->FileExists(this: fileSystem, a2: ENGLISH_STREAM, a3: true) )
      {
        this->localizedStreamFile = fileSystem->OpenFileRead(this: fileSystem, a2: FRENCH_STREAM, a3: 1, a4: 0);
        idCVar::SetString(this: &sys_lang, newValue: FRENCH_LANG, force: true);
      }
      if ( this->localizedStreamFile == nullptr )
      {
        this->localizedStreamFile = fileSystem->OpenFileRead(this: fileSystem, a2: ENGLISH_STREAM, a3: 1, a4: 0);
        idCVar::SetString(this: &sys_lang, newValue: ENGLISH_LANG, force: true);
      }
      if ( this->localizedStreamFile == nullptr )
      {
        idLib::Warning(fmt: "localized stream file not found, defaulting to resourceFile which will likely explode");
        streamFile = this->streamFile;
        if ( streamFile == nullptr )
          streamFile = this->resourceFile;
        this->localizedStreamFile = streamFile;
      }
    }
    idStr::FreeData(this: &v14);
    idMem::PopHeap(this: &mem);
    return 1;
  }
  else
  {
    idLib::Printf(fmt: "idLib::SetProduction( PROD_DEVELOPMENT )\n");
    idLib::production = PROD_DEVELOPMENT;
    resourceLoadCallback = (void (__fastcall *)(idResource *))idPhysics_StaticMulti::UpdateTime;
    idMem::PopHeap(this: &mem);
    return 0;
  }
}


// ========================================================================
// __unwind$250212
// EA  : 0x8269B8B4
// RVA : 0x0069B8B4
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250212()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$250213
// EA  : 0x8269B8DC
// RVA : 0x0069B8DC
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250213()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ??0idResourceManagerLocal@@QAA@XZ
// EA  : 0x8269BD58
// RVA : 0x0069BD58
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

idResourceManagerLocal *__fastcall idResourceManagerLocal::idResourceManagerLocal(idResourceManagerLocal *this)
{
  this->resourceFile = nullptr;
  this->__vftable = (idResourceManagerLocal_vtbl *)&idResourceManagerLocal::`vftable';
  this->streamFile = nullptr;
  this->localizedStreamFile = nullptr;
  this->cachedStreamFile = nullptr;
  this->patchFiles.size = 32;
  this->patchFiles.num = 0;
  this->patchFiles.granularity = 1;
  this->patchFiles.list = this->patchFiles.staticList;
  this->patchFiles.memTag = 5;
  this->patchFiles.listStatic = 1;
  this->tableOffset = 0;
  this->tableLength = 0;
  this->resourceMagic = 0;
  this->currentSortedResource = nullptr;
  this->currentResource = nullptr;
  this->writtenResourceTable.granularity = 0;
  this->writtenResourceTable.memTag = 99;
  this->writtenResourceTable.listStatic = 0;
  this->writtenResourceTable.list = nullptr;
  this->writtenResourceTable.size = 0;
  this->writtenResourceTable.num = 0;
  this->fileTable.granularity = 0;
  this->fileTable.memTag = 99;
  this->fileTable.listStatic = 0;
  this->fileTable.list = nullptr;
  this->fileTable.size = 0;
  this->fileTable.num = 0;
  this->fileTableResource = 0;
  this->cacheTable.list = nullptr;
  this->cacheTable.granularity = 0;
  this->cacheTable.memTag = 99;
  this->cacheTable.listStatic = 0;
  this->cacheTable.size = 0;
  this->cacheTable.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cacheTable);
  this->cacheHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->cacheHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->patchTable.list = nullptr;
  this->patchTable.granularity = 0;
  this->patchTable.memTag = 99;
  this->patchTable.listStatic = 0;
  this->patchTable.size = 0;
  this->patchTable.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->patchTable);
  this->patchHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->patchHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->filePlatformBits = 0;
  this->buildPlatforms = 0;
  this->lastUPacifierMsec = 0;
  this->languages.granularity = 0;
  this->languages.memTag = 5;
  this->languages.listStatic = 0;
  this->languages.list = nullptr;
  this->languages.size = 0;
  this->languages.num = 0;
  this->denyFonts = false;
  this->cancelToTerminate = false;
  return this;
}


// ========================================================================
// __unwind$250890
// EA  : 0x8269BEC4
// RVA : 0x0069BEC4
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250890()
{
  int v0; // r12

  idResourceManager::~idResourceManager(this: *(idResourceManager **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$250891
// EA  : 0x8269BEEC
// RVA : 0x0069BEEC
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250891()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 20));
}


// ========================================================================
// __unwind$250892
// EA  : 0x8269BF18
// RVA : 0x0069BF18
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250892()
{
  int v0; // r12

  idList<idResourceFileEntry,99>::~idList<idResourceFileEntry,99>(this: (idList<idResourceFileEntry,99> *)(*(_DWORD *)(v0 - 144 + 164) + 184));
}


// ========================================================================
// __unwind$250893
// EA  : 0x8269BF44
// RVA : 0x0069BF44
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250893()
{
  int v0; // r12

  idList<idResourceFileEntry,99>::~idList<idResourceFileEntry,99>(this: (idList<idResourceFileEntry,99> *)(*(_DWORD *)(v0 - 144 + 164) + 200));
}


// ========================================================================
// __unwind$250894
// EA  : 0x8269BF70
// RVA : 0x0069BF70
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250894()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 220));
}


// ========================================================================
// __unwind$250895
// EA  : 0x8269BF9C
// RVA : 0x0069BF9C
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250895()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 236));
}


// ========================================================================
// __unwind$250896
// EA  : 0x8269BFC8
// RVA : 0x0069BFC8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250896()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 268));
}


// ========================================================================
// __unwind$250897
// EA  : 0x8269BFF4
// RVA : 0x0069BFF4
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_250897()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 284));
}


// ========================================================================
// ?LoadNamedResourceBlock@idResourceManagerLocal@@AAA_NQBD0QBV?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@10W4videoFlags_t@@_N@Z
// EA  : 0x8269C128
// RVA : 0x0069C128
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

int __fastcall idResourceManagerLocal::LoadNamedResourceBlock(
        idResourceManagerLocal *this,
        const char *const resourceFileName,
        const char *_mapName,
        const idStaticList<idStrStatic<128>,256> *const layersActive,
        const idStaticList<idStrStatic<128>,256> *const layersDeactive,
        const char *videoFileName,
        videoFlags_t videoFlags,
        bool initHDC)
{
  char *data; // r20
  int v16; // r3
  bool v17; // r11
  bool v18; // r15
  idRenderSystem_vtbl *v19; // r29
  idRenderVideoOverlay *v20; // r25
  void *v21; // r3
  int v22; // r21
  idFile *streamFile; // r28
  const char *v24; // r3
  idVirtualTextureSystem *v25; // r3
  idFile_Permanent *v26; // r27
  void *v27; // r26
  int v28; // r30
  int v29; // r29
  int v30; // r3
  __int64 v31; // r8
  __int64 v32; // r3
  int v33; // r24
  unsigned int v34; // r14
  int v35; // r30
  int v36; // r3
  bool v37; // r6
  bool v38; // r4
  idMem *v39; // r26
  void *v40; // r15
  int v41; // r3
  unsigned int tableLength; // r6
  __int64 v43; // r11
  double v44; // r4
  int v45; // r28
  size_t v46; // r30
  void *v47; // r14
  int v48; // r10
  signed int j; // r11
  signed int i; // r11
  int NeededResourcesForMap; // r4
  int num; // ctr
  encounterGroupRole_t *v54; // r11
  int v55; // r19
  int v56; // r11
  int k; // ctr
  fsOrigin_t v58; // r7
  __int64 v59; // r6
  int v60; // r23
  int v61; // r22
  signed int m; // r30
  char *v63; // r3
  char v64; // r11
  idResource *v65; // r3
  idList<idResourceFileEntry,99> *p_fileTable; // r27
  int size; // r11
  int v68; // r11
  int v69; // r24
  int v70; // r26
  idResourceFileEntry *v71; // r29
  encounterGroupRole_t **p_stream; // r30
  encounterGroupRole_t *v73; // r4
  char *v74; // r3
  char v75; // r11
  idResource *v76; // r3
  idResource *v77; // r30
  const char *v78; // r18
  const char *v79; // r3
  int v80; // r30
  idMem *v81; // r24
  int v82; // r4
  int v83; // r6
  int v84; // r25
  int v85; // r30
  const char *v86; // r29
  const char *v87; // r3
  idResource *v88; // r29
  int v89; // r10
  int v90; // r11
  int v91; // r30
  unsigned int NetworkChecksum; // r30
  int NumNetworkResources; // r3
  idResourceFileEntry *v94; // r28
  int v95; // r30
  idResourceFileEntry *v96; // r29
  __int64 v97; // r8
  double v98; // r4
  idStr *v99; // r28
  int v100; // r30
  idStr *v101; // r29
  idStr *list; // r28
  int v103; // r30
  idStr *v104; // r29
  idStr *v105; // r28
  int v106; // r30
  idStr *v107; // r29
  signed int v108; // [sp+50h] [-900h] BYREF
  bool v109; // [sp+54h] [-8FCh]
  idMem *v110; // [sp+58h] [-8F8h]
  idList<idStr,5> v111; // [sp+60h] [-8F0h] BYREF
  int valueInteger; // [sp+70h] [-8E0h]
  int v113; // [sp+74h] [-8DCh]
  idVirtualTextureSystem *v114; // [sp+78h] [-8D8h]
  idList<enum encounterGroupRole_t,5> v115; // [sp+80h] [-8D0h] BYREF
  idPhysicalMemoryBlock *v116; // [sp+90h] [-8C0h]
  void *v117; // [sp+98h] [-8B8h]
  signed int v118; // [sp+9Ch] [-8B4h]
  idFile_Memory v119; // [sp+A0h] [-8B0h] BYREF
  idStrStatic<256> v120; // [sp+1F0h] [-760h] BYREF
  idStrStatic<256> v121; // [sp+310h] [-640h] BYREF
  idResourceFileEntry v122; // [sp+430h] [-520h] BYREF

  idStrStatic<256>::idStrStatic<256>(this: &v120, text: _mapName);
  idStr::StripFileExtension(this: &v120);
  data = v120.data;
  v113 = Sys_Milliseconds();
  v116 = &physicalMemoryBlock;
  valueInteger = resource_debugLevel.valueInteger;
  idPhysicalMemoryBlock::BeginResourceLoads(this: &physicalMemoryBlock);
  if ( idStr::Icmp(s1: data, s2: "init") == 0 || (v16 = idStr::Icmp(s1: data, s2: "common"), v17 = false, v16 == 0) )
    v17 = true;
  v18 = v17;
  v109 = v17;
  if ( videoFileName != nullptr && *videoFileName != 0 && r_useSMP.valueInteger != 0 )
  {
    v19 = renderSystem->__vftable;
    v20 = common->VideoOverlay(this: common);
    v21 = renderSystem->GetGameWindow(this: renderSystem);
    v19->BeginBinkVideo(this: renderSystem, a2: v21, a3: videoFileName, a4: videoFlags, a5: v20);
  }
  v110 = &mem;
  if ( initHDC )
  {
    idStreamFileCache::InitHDC(this: streamFileCache);
    v22 = Sys_Milliseconds();
    streamFile = this->streamFile;
    v24 = fileSystem->GetBasePathStr(this: fileSystem, a2: 1);
    idStrStatic<256>::idStrStatic<256>(this: &v121, text: v24);
    idStr::AppendPath(this: &v121, text: RESOURCE_STREAM_NAME);
    v25 = (idVirtualTextureSystem *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x68u,
                                      tag: TAG_FILE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
    v114 = v25;
    if ( v25 != nullptr )
      v26 = idFile_Permanent::idFile_Permanent(
              this: (idFile_Permanent *)v25,
              relativePath: RESOURCE_STREAM_NAME,
              osPath: v121.data,
              m: FS_WRITE,
              create: true);
    else
      v26 = nullptr;
    v27 = XMemAlloc(dwSize: 0x100000u, dwAllocAttributes: 0xAB060000);
    if ( idFile_Permanent::IsOpen(this: v26) && streamFile != nullptr && v27 != nullptr )
    {
      v28 = resource_streamedSizeInMB.valueInteger;
      v29 = 0;
      v30 = streamFile->Length(this: streamFile);
      LODWORD(v31) = v28 << 20;
      if ( v28 << 20 > v30 )
      {
        LODWORD(v32) = streamFile->Length(this: streamFile);
        LODWORD(v31) = ((unsigned __int64)(v32 >> 19) >> 44) + v32;
        v28 = v31 >> 20;
      }
      v33 = v28 << 20;
      if ( v28 << 20 > 0 )
      {
        do
        {
          v34 = idStreamFileCache::UncachedScheduledRead(
                  this: streamFileCache,
                  file: streamFile,
                  ofs: __SPAIR64__(v29, (unsigned int)v27),
                  dest: (void *const)0x100000,
                  length: v31);
          v35 = v26->WriteOfs(this: v26, a2: v29, a3: v27, a4: 0x100000u);
          if ( v35 != v34 )
            idLib::Warning(fmt: "failed to write streamed cached file bytes");
          v29 += v35;
          mgthread_sleep(ms: 16);
        }
        while ( v29 < v33 );
      }
    }
    XMemFree(pAddress: v27, dwAllocAttributes: 0xAB060000);
    if ( v26 != nullptr )
      ((void (__fastcall *)(idFile_Permanent *, int))v26->dtr_idFile)(a1: v26, a2: 1);
    v36 = Sys_Milliseconds();
    idLib::Printf(
      fmt: "%d seconds to precache %dMBs of streamed.resources\n",
      (v36 - v22) / 1000,
      resource_streamedSizeInMB.valueInteger);
    this->cachedStreamFile = fileSystem->OpenFileRead(this: fileSystem, a2: v121.data, a3: 1, a4: 0);
    idStr::FreeData(this: &v121);
  }
  v114 = &virtualTextureSystem;
  if ( !v18 )
  {
    idVirtualTextureSystem::EmptyCache(this: &virtualTextureSystem, skipVmtrCache: true);
    if ( idStr::Icmp(s1: data, s2: "game/wasteland1/wasteland1") != 0
      && idStr::Icmp(s1: data, s2: "game/wasteland2/wasteland2") != 0 )
    {
      v37 = false;
      v38 = true;
    }
    else
    {
      v38 = false;
      v37 = mem_UseTwoDiffusePools.valueInteger != 0;
    }
    idVirtualTextureSystem::CreatePhysicalImages(
      this: &virtualTextureSystem,
      mapHasSpecularPages_: v38,
      mapHasDiffuseOnlyPages_: true,
      mapHasDiffuseOnly2Pages_: v37);
  }
  v39 = v110;
  idMem::InitMapHeap(this: v110);
  v40 = idMem::AllocWithLocation(
          this: v39,
          location: "w:\\tech5\\engine\\framework\\ResourceManager.cpp(1358) : TAG_RESOURCE",
          size: this->tableLength,
          tag: TAG_RESOURCE,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  idMem::InitMapHeap(this: v39);
  this->resourceFile->ReadOfs(this: this->resourceFile, a2: this->tableOffset, a3: v40, a4: this->tableLength);
  v41 = Sys_Milliseconds();
  tableLength = this->tableLength;
  LODWORD(v43) = v41 - v113;
  *(_QWORD *)&v115.list = v43;
  v44 = (float)((float)v43 * (float)0.001);
  idLib::Printf(fmt: (const char *)HIDWORD(v44), LODWORD(v44), tableLength >> 10);
  idFile_Memory::idFile_Memory(this: &v119, name: "resourceHeader");
  idFile_Memory::SetReadOnlyData(this: &v119, data: (const char *)v40, length: this->tableLength);
  v119.Read(this: &v119, a2: &v108, a3: 4u);
  v45 = 0;
  *(_WORD *)&v111.memTag = 25344;
  memset(&v111, 0, 14);
  v118 = v108;
  v46 = v108;
  v47 = idMem::AllocWithLocation(
          this: v39,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
          size: v108,
          tag: TAG_TEMP,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v117 = v47;
  if ( idStr::Cmp(s1: data, s2: "all") != 0 )
  {
    if ( idStr::Cmp(s1: data, s2: "outro") != 0 )
    {
      idList<int,99>::idList<int,99>(this: (idList<int,99> *)&v115);
      NeededResourcesForMap = idResourceManagerLocal::GetNeededResourcesForMap(
                                this,
                                mapName_: _mapName,
                                layersActive,
                                layersDeactive,
                                neededResources: &v115,
                                neededMegatextures: &v111);
      if ( NeededResourcesForMap == -1 )
      {
        idLib::Warning(fmt: "The map isn't present in the resource file");
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v115);
        if ( v47 != nullptr )
          idMem::Free(this: v39, ptr: v47, align: ALIGN_16);
        idList<idStr,99>::~idList<idStr,99>(this: &v111);
        idFile_Memory::~idFile_Memory(this: &v119);
        idStr::FreeData(this: &v120);
        return 0;
      }
      idLib::Printf(fmt: "Resources skipped by layer tests: %i\n", NeededResourcesForMap);
      memset(Dst: v47, Val: 0, Size: v46);
      if ( v115.num > 0 )
      {
        num = v115.num;
        v54 = v115.list - 1;
        do
        {
          *((_BYTE *)v47 + *++v54) = 1;
          --num;
        }
        while ( num != 0 );
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v115);
      v48 = v108;
    }
    else
    {
      v48 = v108;
      for ( i = 0; i < v108; v48 = v108 )
        *((_BYTE *)v47 + i++) = 0;
    }
  }
  else
  {
    v48 = v108;
    for ( j = 0; j < v108; v48 = v108 )
      *((_BYTE *)v47 + j++) = 1;
  }
  v55 = 0;
  v56 = 0;
  if ( v48 > 0 )
  {
    for ( k = v48; k != 0; --k )
    {
      if ( *((_BYTE *)v47 + v56) != 0 )
        ++v55;
      ++v56;
    }
  }
  idFile_Memory::Tell(this: &v119);
  v60 = 0;
  v61 = 0;
  for ( m = 0; m < v108; ++m )
  {
    idResourceFileEntry::idResourceFileEntry(this: &v122);
    idResourceFileEntry::Read(this: &v122, f: &v119);
    if ( *((_BYTE *)v47 + v122.resourceIndex) != 0 )
    {
      if ( (v122.useBits & 8) != 0
        || strstr(str1: v122.filename.data, str2: ".sbcm") != nullptr
        || (v63 = strstr(str1: v122.filename.data, str2: ".tbcm"), v64 = 0, v63 != nullptr) )
      {
        v64 = 1;
      }
      if ( v64 != 0 )
      {
        ++v61;
      }
      else
      {
        v65 = idResourceList::Lookup(this: v122.resourceList, canonicalName: v122.resourceName.data);
        if ( v65 == nullptr || (*((_BYTE *)v65 + 32) & 8) != 0 )
          ++v60;
      }
    }
    idResourceFileEntry::~idResourceFileEntry(this: &v122);
  }
  HIDWORD(v59) = 2;
  idFile_Memory::Seek(this: &v119, offset: v59, origin: v58);
  idMem::PushHeap(this: v39, heapType: HEAP_MAPHEAP);
  p_fileTable = &this->fileTable;
  if ( v60 <= this->fileTable.size
    || (unsigned __int8)idList<idResourceFileEntry,99>::Resize(this: &this->fileTable, newsize: v60) != 0 )
  {
    size = this->fileTable.size;
    if ( v60 < size )
      size = v60;
    this->fileTable.num = size;
  }
  idMem::PopHeap(this: v39);
  v68 = v108;
  this->lastUPacifierMsec = 0;
  v69 = 0;
  if ( v68 > 0 )
  {
    v70 = 0;
    while ( v45 < v60 )
    {
      if ( this->cancelToTerminate )
      {
        if ( v47 != nullptr )
          idMem::Free(this: v110, ptr: v47, align: ALIGN_16);
        if ( v111.listStatic == 0 || v111.listStatic == 2 )
        {
          list = v111.list;
          if ( v111.list != nullptr )
          {
            v103 = v111.size;
            if ( v111.size > 0 )
            {
              v104 = v111.list;
              do
              {
                idStr::FreeData(this: v104);
                --v103;
                ++v104;
              }
              while ( v103 != 0 );
            }
            idMem::Free(this: v110, ptr: list, align: ALIGN_16);
          }
        }
        goto LABEL_129;
      }
      v71 = &p_fileTable->list[v70];
      p_stream = (encounterGroupRole_t **)&v71->stream;
      if ( v71->stream.size < 0 )
      {
        if ( v71->stream.listStatic != 0 && v71->stream.listStatic != 2 )
        {
          v71->stream.num = 0;
        }
        else
        {
          v73 = *p_stream;
          if ( *p_stream != nullptr )
          {
            v115.list = *p_stream;
            idMem::Free(this: v110, ptr: v73, align: ALIGN_16);
          }
          *p_stream = nullptr;
          v71->stream.size = 0;
          v71->stream.num = 0;
        }
      }
      v71->stream.num = __CFADD__(-v71->stream.size, v71->stream.size ^ 0x80000000) ? 0 : v71->stream.size;
      idResourceFileEntry::Read(this: v71, f: &v119);
      if ( *((_BYTE *)v47 + v71->resourceIndex) != 0 )
      {
        if ( (v71->useBits & 8) != 0
          || strstr(str1: v71->filename.data, str2: ".sbcm") != nullptr
          || (v74 = strstr(str1: v71->filename.data, str2: ".tbcm"), v75 = 0, v74 != nullptr) )
        {
          v75 = 1;
        }
        if ( v75 == 0 )
        {
          v76 = idResourceList::Lookup(this: v71->resourceList, canonicalName: v71->resourceName.data);
          v77 = v76;
          if ( v76 == nullptr || (*((_BYTE *)v76 + 32) & 8) != 0 )
          {
            ++v45;
            ++v70;
            if ( valueInteger != 0 )
            {
              v78 = v71->resourceName.data;
              idResourceList::GetResourceTypeName(this: v71->resourceList);
              idLib::Printf(fmt: "need to load %s : %s\n", v79, v78);
            }
            if ( v77 == nullptr )
            {
              v80 = (int)v71->resourceList->Alloc(this: v71->resourceList, a2: v71->resourceName.data);
              idResourceList::Add(this: v71->resourceList, ptr: (idResourceList_vtbl *)v80);
              *(_BYTE *)(v80 + 32) |= 8u;
            }
          }
        }
      }
      if ( ++v69 >= v108 )
        break;
    }
  }
  v81 = v110;
  idMem::InitMapHeap(this: v110);
  idMem::Free(this: v81, ptr: v40, align: ALIGN_16);
  idMem::InitMapHeap(this: v81);
  idLib::Printf(fmt: "Load %i resources using %i of %i total resource files, %i streamed\n", v55, v45, v108, v61);
  idBackgroundLoader::BeginBackgroundLoads(
    this: &bgl,
    resourceFile_: this->resourceFile,
    fileTable_: (const idList<idResourceFileEntry,101> *)&this->fileTable);
  fileSystem->SetFilePreCallback(this: fileSystem, a2: ResourceLoadPreCallback);
  idLib::production = PROD_PRODUCTION;
  v83 = this->fileTable.num;
  this->fileTableResource = 0;
  if ( v83 <= 0 )
  {
LABEL_102:
    NetworkChecksum = idResourceList::GetNetworkChecksum();
    NumNetworkResources = idResourceList::GetNumNetworkResources();
    idLib::Printf(
      fmt: "LoadNamedResourceBlock: Num network resources: %i, checksum: %i\n",
      NumNetworkResources,
      NetworkChecksum);
    fileSystem->SetFilePreCallback(this: fileSystem, a2: nullptr);
    idBackgroundLoader::EndBackgroundLoads(this: &bgl);
    if ( this->fileTable.listStatic == 0 || this->fileTable.listStatic == 2 )
    {
      v94 = p_fileTable->list;
      if ( p_fileTable->list != nullptr )
      {
        v95 = this->fileTable.size;
        if ( v95 > 0 )
        {
          v96 = p_fileTable->list;
          do
          {
            idResourceFileEntry::~idResourceFileEntry(this: v96);
            --v95;
            ++v96;
          }
          while ( v95 != 0 );
        }
        idMem::Free(this: v81, ptr: v94, align: ALIGN_16);
      }
      p_fileTable->list = nullptr;
      this->fileTable.size = 0;
    }
    this->fileTable.num = 0;
    idVirtualTextureSystem::SetupLoadedVirtualMaterials(this: v114);
    idPhysicalMemoryBlock::EndResourceLoads(this: v116, neverFreeAllocatedData: v109);
    LODWORD(v97) = Sys_Milliseconds() - v113;
    *(_QWORD *)&v115.list = v97;
    v98 = (float)((float)v97 * (float)0.001);
    idLib::Printf(fmt: (const char *)HIDWORD(v98), LODWORD(v98));
    if ( v47 != nullptr )
      idMem::Free(this: v81, ptr: v47, align: ALIGN_16);
    if ( v111.listStatic == 0 || v111.listStatic == 2 )
    {
      v99 = v111.list;
      if ( v111.list != nullptr )
      {
        v100 = v111.size;
        if ( v111.size > 0 )
        {
          v101 = v111.list;
          do
          {
            idStr::FreeData(this: v101);
            --v100;
            ++v101;
          }
          while ( v100 != 0 );
        }
        idMem::Free(this: v81, ptr: v99, align: ALIGN_16);
      }
    }
    idFile_Memory::~idFile_Memory(this: &v119);
    idStr::FreeData(this: &v120);
    return 1;
  }
  else
  {
    v84 = valueInteger;
    while ( !this->cancelToTerminate )
    {
      v85 = (int)&p_fileTable->list[this->fileTableResource];
      ((void (__fastcall *)(idCommon *, int, int, _DWORD, _DWORD, double))common->UpdateLevelLoadPacifier)(
        a1: common,
        a2: v82,
        a3: 1,
        a4: 0,
        a5: 0,
        a6: 0.0);
      if ( v84 != 0 )
      {
        v86 = *(const char **)(v85 + 76);
        idResourceList::GetResourceTypeName(this: *(idResourceList **)(v85 + 4));
        idLib::Printf(fmt: "loading %i:%s : %s\n", this->fileTableResource, v87, v86);
      }
      v88 = idResourceList::Load(
              this: *(idResourceList **)(v85 + 4),
              name: *(char **)(v85 + 76),
              makeDefault: true,
              skipStaleCheck: false);
      idResource::InitNetworkID(this: v88);
      idBackgroundLoader::SkipPastResource(this: &bgl, r: v88);
      do
      {
        v89 = this->fileTable.num;
        v90 = this->fileTableResource + 1;
        this->fileTableResource = v90;
        if ( v90 == v89 )
          break;
        v91 = (int)&p_fileTable->list[v90];
        if ( idStr::Cmp(s1: *(const char **)(v91 + 76), s2: v88->name.str) != 0 )
          break;
      }
      while ( *(idResourceList **)(v91 + 4) == v88->GetResourceList(this: v88) );
      if ( this->fileTableResource >= this->fileTable.num )
        goto LABEL_102;
    }
    if ( v47 != nullptr )
      idMem::Free(this: v81, ptr: v47, align: ALIGN_16);
    if ( v111.listStatic == 0 || v111.listStatic == 2 )
    {
      v105 = v111.list;
      if ( v111.list != nullptr )
      {
        v106 = v111.size;
        if ( v111.size > 0 )
        {
          v107 = v111.list;
          do
          {
            idStr::FreeData(this: v107);
            --v106;
            ++v107;
          }
          while ( v106 != 0 );
        }
        idMem::Free(this: v81, ptr: v105, align: ALIGN_16);
      }
    }
LABEL_129:
    idFile_Memory::~idFile_Memory(this: &v119);
    idStr::FreeData(this: &v120);
    return 0;
  }
}


// ========================================================================
// __unwind$251090
// EA  : 0x8269CF24
// RVA : 0x0069CF24
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251090()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2384 + 496));
}


// ========================================================================
// __unwind$251091
// EA  : 0x8269CF4C
// RVA : 0x0069CF4C
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251091()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2384 + 784));
}


// ========================================================================
// __unwind$251092
// EA  : 0x8269CF74
// RVA : 0x0069CF74
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251092()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2384 + 120), tag: TAG_FILE);
}


// ========================================================================
// __unwind$251093
// EA  : 0x8269CFA0
// RVA : 0x0069CFA0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251093()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 2384 + 160));
}


// ========================================================================
// __unwind$251094
// EA  : 0x8269CFC8
// RVA : 0x0069CFC8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251094()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 2384 + 96));
}


// ========================================================================
// __unwind$251095
// EA  : 0x8269CFF0
// RVA : 0x0069CFF0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251095()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 2384 + 152));
}


// ========================================================================
// __unwind$251096
// EA  : 0x8269D018
// RVA : 0x0069D018
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251096()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2384 + 128));
}


// ========================================================================
// __unwind$251097
// EA  : 0x8269D040
// RVA : 0x0069D040
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251097()
{
  int v0; // r12

  idResourceFileEntry::~idResourceFileEntry(this: (idResourceFileEntry *)(v0 - 2384 + 1072));
}


// ========================================================================
// ?AllocGameWithResourceFile@idResourceManagerLocal@@UAA_NAAPAVidGame@@ABVidGameSpawnInfo@@PAVidFile@@PBD@Z
// EA  : 0x8269D070
// RVA : 0x0069D070
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idResourceManagerLocal::AllocGameWithResourceFile(
        idResourceManagerLocal *this,
        idGame **game,
        const idGameSpawnInfo *mapSpawnInfo,
        idFile *saveGameFile,
        const char *videoFileName)
{
  __int64 v5; // r4
  idResourceManagerLocal *v6; // r18
  idGame **v7; // r23
  const idGameSpawnInfo *v8; // r5
  const idGameSpawnInfo *v9; // r29
  idFile *v10; // r6
  idFile *v11; // r22
  const char *v12; // r7
  const char *v13; // r30
  idRenderSystem_vtbl *v14; // r28
  idRenderVideoOverlay *v15; // r25
  void *v16; // r3
  bool v18; // r5
  int v19; // r21
  int v20; // r24
  const idGameSpawnInfo *v21; // r3
  int i; // r30
  idResource *v23; // r3
  int v24; // r3
  __int64 v25; // r8
  int v26; // r30
  double v27; // r4
  __int128 v28; // r5
  idStrStatic<1024> *p_spawnSpotOverride; // r11
  int v30; // r30
  int v31; // r4
  idStr v32; // [sp+60h] [-15160h] BYREF
  idGameSpawnInfo v33; // [sp+80h] [-15140h] BYREF

  v5 = ((__int64 (*)(void))RtlCheckStack12)();
  v6 = (idResourceManagerLocal *)HIDWORD(v5);
  resourceLoadCallback = nullptr;
  v7 = (idGame **)v5;
  v9 = v8;
  v11 = v10;
  v13 = v12;
  idCommonLocal::ResetMapHeap(this: &commonLocal);
  if ( idLib::production != PROD_DEVELOPMENT )
  {
    common->BeginTerminationThread(this: common);
    allowAbortingWaitForVideoOrBackgroundSwaps = idStr::Icmp(s1: v9->mapName.data, s2: "outro") != 0;
    if ( v13 == nullptr || (v18 = true, *v13 == 0) )
      v18 = false;
    idCommonLocal::StartLevelLoad(this: &commonLocal, mapName: &v9->mapName, useVideo: v18);
    v19 = Sys_Milliseconds();
    idStr::idStr(this: &v32, text: &v9->mapName);
    idStr::MakeNameCanonical(this: &v32);
    if ( (unsigned __int8)idResourceManagerLocal::LoadNamedResourceBlock(
                            this: v6,
                            resourceFileName: RESOURCE_FILE_NAME,
                            _mapName: v32.data,
                            layersActive: &v9->layersActive,
                            layersDeactive: &v9->layersDeactive,
                            videoFileName: v13,
                            videoFlags: VIDEO_EXIT,
                            initHDC: false) == 0 )
    {
      idResourceManagerLocal::WaitForVideoOrBackgroundSwaps(this: v6);
      common->EndTerminationThread(this: common);
      idStr::FreeData(this: &v32);
      return 0;
    }
    idResourceManagerLocal::DefaultMissing(this: v6, name: v32.data);
    v20 = Sys_Milliseconds();
    fileSystem->SetFilePreCallback(
      this: fileSystem,
      a2: (idFile *(__fastcall *)(const char *))MiscellaneousFilePreCallback);
    idLib::production = PROD_LOADED;
    if ( idStr::Icmp(s1: v9->mapName.data, s2: "outro") != 0 )
    {
      if ( resource_virtualTexturePreload.valueInteger != 0 )
        idVirtualTexturePreloader::BeginPreloading(this: &virtualTexturePreloader);
      if ( !gameSystem->AllocGame(this: gameSystem, a2: v7, a3: v9, a4: v11) )
      {
        idResourceManagerLocal::WaitForVideoOrBackgroundSwaps(this: v6);
        idVirtualTexturePreloader::EndPreloading(this: &virtualTexturePreloader);
        common->EndTerminationThread(this: common);
        fileSystem->SetFilePreCallback(this: fileSystem, a2: nullptr);
        idStr::FreeData(this: &v32);
        return 0;
      }
    }
    else
    {
      v21 = idGameSpawnInfo::idGameSpawnInfo(this: &v33, mapName_: &byte_8200D768, gameFlags_: 1);
      gameSystem->AllocGame(this: gameSystem, a2: v7, a3: v21, a4: nullptr);
      idGameSpawnInfo::~idGameSpawnInfo(this: &v33);
    }
    if ( v6->cancelToTerminate )
    {
      common->EndTerminationThread(this: common);
      fileSystem->SetFilePreCallback(this: fileSystem, a2: nullptr);
      idStr::FreeData(this: &v32);
      return 0;
    }
    soundSystem->InitStreamBuffers(this: soundSystem);
    fileSystem->SetFilePreCallback(this: fileSystem, a2: nullptr);
    for ( i = idFileResource::resourceList.num - 1; i >= 0; --i )
    {
      v23 = idResourceList::Index(this: &idFileResource::resourceList, index: i);
      if ( (*((_BYTE *)v23 + 32) & 0x40) == 0 )
        idFileResource::FreeData(this: (idFileResource *)v23);
    }
    v24 = Sys_Milliseconds();
    LODWORD(v25) = v24 - v20;
    v26 = v24;
    v27 = (float)((float)v25 * (float)0.001);
    idLib::Printf(fmt: (const char *)HIDWORD(v27), LODWORD(v27));
    LODWORD(v28) = v26 - v19;
    *(double *)((char *)&v28 + 4) = (float)((float)(__int64)v28 * (float)0.001);
    idLib::Printf(fmt: (const char *)DWORD1(v28), DWORD2(v28));
    idVirtualTexturePreloader::EndPreloading(this: &virtualTexturePreloader);
    p_spawnSpotOverride = &v9->spawnSpotOverride;
    if ( v9->spawnSpotOverride.len == 0 )
      p_spawnSpotOverride = &v9->spawnSpot;
    v30 = idVirtualTexturePreloader::PreloadVMTRsForMap(
            this: &virtualTexturePreloader,
            mapName: v9->mapName.data,
            layers: &v9->layersActive,
            spawnSpot: p_spawnSpotOverride->data);
    while ( !idVirtualTexturePreloader::MaterialPreloadIsDone(this: &virtualTexturePreloader, handle: v30) )
    {
      ((void (__fastcall *)(idCommon *, int, int, int, _DWORD, double))common->UpdateLevelLoadPacifier)(
        a1: common,
        a2: v31,
        a3: 18,
        a4: 1,
        a5: 0,
        a6: 1.0);
      mgthread_sleep(ms: 100);
    }
    idResourceManagerLocal::WaitForVideoOrBackgroundSwaps(this: v6);
    common->EndTerminationThread(this: common);
    idStr::FreeData(this: &v32);
  }
  else
  {
    if ( v13 != nullptr && r_useSMP.valueInteger != 0 )
    {
      v14 = renderSystem->__vftable;
      v15 = common->VideoOverlay(this: common);
      v16 = renderSystem->GetGameWindow(this: renderSystem);
      v14->BeginBinkVideo(this: renderSystem, a2: v16, a3: v13, a4: VIDEO_EXIT, a5: v15);
    }
    idCommonLocal::StartLevelLoad(this: &commonLocal, mapName: &v9->mapName, useVideo: v13 != nullptr);
    if ( !gameSystem->AllocGame(this: gameSystem, a2: v7, a3: v9, a4: v11) )
    {
      idResourceManagerLocal::WaitForVideoOrBackgroundSwaps(this: v6);
      return 0;
    }
    soundSystem->InitStreamBuffers(this: soundSystem);
    idResourceManagerLocal::WaitForVideoOrBackgroundSwaps(this: v6);
  }
  return 1;
}


// ========================================================================
// $M252112
// EA  : 0x8269D610
// RVA : 0x0069D610
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _M252112()
{
  int v0; // r12
  bool v1; // cr58
  idRenderSystem_vtbl *v2; // r11
  void (*EndAutomaticBackgroundSwaps)(void); // r10

  if ( *(_DWORD *)(v0 - 20928 + 86516) != 0 )
  {
    v1 = !renderSystem->BinkVideoIsLoaded(this: renderSystem);
    v2 = renderSystem->__vftable;
    if ( v1 )
      EndAutomaticBackgroundSwaps = (void (*)(void))v2->EndAutomaticBackgroundSwaps;
    else
      EndAutomaticBackgroundSwaps = (void (*)(void))v2->FreeBinkVideo;
    EndAutomaticBackgroundSwaps();
  }
  CxxThrowException(pExceptionObject: nullptr, pThrowInfo: nullptr);
}


// ========================================================================
// $LN113
// EA  : 0x8269D680
// RVA : 0x0069D680
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _LN113()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 20928 + 96));
}


// ========================================================================
// __unwind$251980
// EA  : 0x8269D6A8
// RVA : 0x0069D6A8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_251980()
{
  int v0; // r12

  idGameSpawnInfo::~idGameSpawnInfo(this: (idGameSpawnInfo *)(v0 - 20928 + 128));
}


// ========================================================================
// ?Init2@idResourceManagerLocal@@UAAX_N@Z
// EA  : 0x8269D6D8
// RVA : 0x0069D6D8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __fastcall idResourceManagerLocal::Init2(idResourceManagerLocal *this, const bool skipIntroVideo)
{
  idAutoRenderParms *v4; // r3
  idAutoRenderParms *v5; // r3
  const char *v6; // r30
  int v7; // r3
  idMaterial *v8; // r3
  idMaterial *v9; // r3
  idMaterial *v10; // r3
  idMaterial *v11; // r3
  idMaterial *v12; // r3
  idMaterial *v13; // r3
  idAutoRenderParms *v14; // r3
  idAutoRenderParms *v15; // r11

  idBaseCodeResource::AllocateCodeResources();
  if ( idLib::production == PROD_PRODUCTION )
  {
    common->BeginTerminationThread(this: common);
    idResourceList::deferAllResourceLoads = true;
    v4 = (idAutoRenderParms *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x1E0u,
                                tag: TAG_RENDERPARM,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
      v5 = idAutoRenderParms::idAutoRenderParms(this: v4);
    else
      v5 = nullptr;
    idResourceList::deferAllResourceLoads = false;
    rp = v5;
    if ( com_useMapHeap.valueInteger != 0 )
      idMem::InitMapHeap(this: &mem);
    this->denyFonts = true;
    if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: FRENCH_LANG) != 0 )
      v6 = "video/loadvideo.bik";
    else
      v6 = "video/loadvideo_french.bik";
    if ( skipIntroVideo )
      v6 = "video/nip.bik";
    idResourceManagerLocal::LoadNamedResourceBlock(
      this,
      resourceFileName: RESOURCE_FILE_NAME,
      _mapName: "init",
      layersActive: nullptr,
      layersDeactive: nullptr,
      videoFileName: nullptr,
      videoFlags: VIDEO_EXIT,
      initHDC: false);
    idParmState::Init(this: renderThreadParmState);
    v7 = Sys_Milliseconds();
    idLib::Printf(fmt: "Start time of bink logo video in ms: %d\n", v7);
    idResourceManagerLocal::LoadNamedResourceBlock(
      this,
      resourceFileName: RESOURCE_FILE_NAME,
      _mapName: "common",
      layersActive: nullptr,
      layersDeactive: nullptr,
      videoFileName: v6,
      videoFlags: VIDEO_EXIT,
      initHDC: true);
    resourceManager->SetFileHook(this: resourceManager);
    idResourceList::Load(
      this: &idDeclRenderProg::resourceList,
      name: "feedbackDownSample",
      makeDefault: true,
      skipStaleCheck: false);
    if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "polish") == 0 )
    {
      v8 = (idMaterial *)idResourceList::Load(
                           this: &idMaterial::resourceList,
                           name: "fonts/polish/idtactical_regular/48.tga",
                           makeDefault: false,
                           skipStaleCheck: false);
      if ( v8 != nullptr )
        idMaterial::ReloadImages(this: v8, force: true);
      v9 = (idMaterial *)idResourceList::Load(
                           this: &idMaterial::resourceList,
                           name: "fonts/polish/idsettler_regular/48.tga",
                           makeDefault: false,
                           skipStaleCheck: false);
      if ( v9 != nullptr )
        idMaterial::ReloadImages(this: v9, force: true);
      v10 = (idMaterial *)idResourceList::Load(
                            this: &idMaterial::resourceList,
                            name: "fonts/polish/idsettler_heavy/48.tga",
                            makeDefault: false,
                            skipStaleCheck: false);
      if ( v10 != nullptr )
        idMaterial::ReloadImages(this: v10, force: true);
      idResourceList::Load(
        this: &idFont::resourceList,
        name: "polish/idtactical_regular",
        makeDefault: false,
        skipStaleCheck: true);
      idResourceList::Load(
        this: &idFont::resourceList,
        name: "polish/idsettler_regular",
        makeDefault: false,
        skipStaleCheck: true);
      idResourceList::Load(
        this: &idFont::resourceList,
        name: "polish/idsettler_heavy",
        makeDefault: false,
        skipStaleCheck: true);
    }
    if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "czech") == 0 )
    {
      v11 = (idMaterial *)idResourceList::Load(
                            this: &idMaterial::resourceList,
                            name: "fonts/czech/idtactical_regular/48.tga",
                            makeDefault: false,
                            skipStaleCheck: false);
      if ( v11 != nullptr )
        idMaterial::ReloadImages(this: v11, force: true);
      v12 = (idMaterial *)idResourceList::Load(
                            this: &idMaterial::resourceList,
                            name: "fonts/czech/idsettler_regular/48.tga",
                            makeDefault: false,
                            skipStaleCheck: false);
      if ( v12 != nullptr )
        idMaterial::ReloadImages(this: v12, force: true);
      v13 = (idMaterial *)idResourceList::Load(
                            this: &idMaterial::resourceList,
                            name: "fonts/czech/idsettler_heavy/48.tga",
                            makeDefault: false,
                            skipStaleCheck: false);
      if ( v13 != nullptr )
        idMaterial::ReloadImages(this: v13, force: true);
      idResourceList::Load(
        this: &idFont::resourceList,
        name: "czech/idtactical_regular",
        makeDefault: false,
        skipStaleCheck: true);
      idResourceList::Load(
        this: &idFont::resourceList,
        name: "czech/idsettler_regular",
        makeDefault: false,
        skipStaleCheck: true);
      idResourceList::Load(
        this: &idFont::resourceList,
        name: "czech/idsettler_heavy",
        makeDefault: false,
        skipStaleCheck: true);
    }
    resourceManager->ReleaseFileHook(this: resourceManager);
    if ( skipIntroVideo )
      renderSystem->FreeBinkVideo(this: renderSystem);
    else
      idResourceManagerLocal::WaitForVideoOrBackgroundSwaps(this);
    common->EndTerminationThread(this: common);
  }
  else
  {
    idPhysicalMemoryBlock::RevertToDiscreteAllocations(this: &physicalMemoryBlock);
    idBaseCodeResource::LoadCodeResources(ofType: "renderParm");
    v14 = (idAutoRenderParms *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x1E0u,
                                 tag: TAG_RENDERPARM,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    if ( v14 != nullptr )
      v15 = idAutoRenderParms::idAutoRenderParms(this: v14);
    else
      v15 = nullptr;
    rp = v15;
    idBaseCodeResource::LoadCodeResources(ofType: nullptr);
    idStreamFileCache::InitHDC(this: streamFileCache);
  }
  idResourceManagerLocal::DefaultMissing(this, name: "idResourceManagerLocal::Init2");
}


// ========================================================================
// __unwind$252139
// EA  : 0x8269DB38
// RVA : 0x0069DB38
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_252139()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_RENDERPARM);
}


// ========================================================================
// __unwind$252140
// EA  : 0x8269DB64
// RVA : 0x0069DB64
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void _unwind_252140()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_RENDERPARM);
}


// ========================================================================
// `dynamic initializer for 'resource_debugLevel''
// EA  : 0x8333C4C8
// RVA : 0x0133C4C8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_debugLevel__()
{
  idCVar::idCVar(
    this: &resource_debugLevel,
    name: "resource_debugLevel",
    value: "0",
    flags: 2,
    description: "Set to 1 for huge console spew",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_debugLevel__);
}


// ========================================================================
// `dynamic initializer for 'resource_ignoreLayers''
// EA  : 0x8333C520
// RVA : 0x0133C520
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_ignoreLayers__()
{
  idCVar::idCVar(
    this: &resource_ignoreLayers,
    name: "resource_ignoreLayers",
    value: "0",
    flags: 1,
    description: "ignore layer bits and load all layers during map loads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_ignoreLayers__);
}


// ========================================================================
// `dynamic initializer for 'resource_virtualTexturePreload''
// EA  : 0x8333C578
// RVA : 0x0133C578
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_virtualTexturePreload__()
{
  idCVar::idCVar(
    this: &resource_virtualTexturePreload,
    name: "resource_virtualTexturePreload",
    value: "1",
    flags: 1,
    description: "run the virtual texture preloader in parallel with game init",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_virtualTexturePreload__);
}


// ========================================================================
// `dynamic initializer for 'resource_streamedSizeInMB''
// EA  : 0x8333C5D0
// RVA : 0x0133C5D0
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resource_streamedSizeInMB__()
{
  idCVar::idCVar(
    this: &resource_streamedSizeInMB,
    name: "resource_streamedSizeInMB",
    value: "30",
    flags: 2,
    description: "number of streamed.resources megabytes to copy to the cache partition on the 360",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resource_streamedSizeInMB__);
}


// ========================================================================
// `dynamic initializer for 'resourceManagerLocal''
// EA  : 0x8333C628
// RVA : 0x0133C628
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__resourceManagerLocal__()
{
  idResourceManagerLocal::idResourceManagerLocal(this: &resourceManagerLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__resourceManagerLocal__);
}


// ========================================================================
// `dynamic initializer for 'mem_phyMemBlockSizeM''
// EA  : 0x8333C660
// RVA : 0x0133C660
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_phyMemBlockSizeM__()
{
  idCVar::idCVar(
    this: &mem_phyMemBlockSizeM,
    name: "mem_phyMemBlockSizeM",
    value: "190",
    flags: 2,
    description: "Size (in MB) of the physical memory block",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_phyMemBlockSizeM__);
}


// ========================================================================
// `dynamic initializer for 'mem_UseTwoDiffusePools''
// EA  : 0x8333C6B8
// RVA : 0x0133C6B8
// PDB : w:\tech5\engine\framework\resourcemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mem_UseTwoDiffusePools__()
{
  idCVar::idCVar(
    this: &mem_UseTwoDiffusePools,
    name: "mem_UseTwoDiffusePools",
    value: "1",
    flags: 1,
    description: "Use two diffuse pools for the wastelands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mem_UseTwoDiffusePools__);
}

