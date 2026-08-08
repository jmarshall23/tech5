
// ========================================================================
// OnReloadSound
// EA  : 0x82624400
// RVA : 0x00624400
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall OnReloadSound(const idDecl *decl)
{
  soundSystem->OnReloadSound(this: soundSystem, a2: decl);
}


// ========================================================================
// ?GetFileName@idDeclSource@@QBAPBDXZ
// EA  : 0x82624730
// RVA : 0x00624730
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

char *__fastcall idDeclSource::GetFileName(idDeclSource *this)
{
  idDeclFile *sourceFile; // r11

  sourceFile = this->sourceFile;
  if ( sourceFile != nullptr )
    return (char *)sourceFile->fileName.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetDeclType@idDeclManagerLocal@@UBAPAVidDeclInfo@@PBD@Z
// EA  : 0x82624750
// RVA : 0x00624750
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idDeclInfo *__fastcall idDeclManagerLocal::GetDeclType(idDeclManagerLocal *this, const char *typeName)
{
  int v4; // r29
  int i; // r31

  if ( typeName == nullptr )
    return nullptr;
  if ( *typeName == 0 )
    return nullptr;
  v4 = 0;
  if ( this->declTypes.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->declTypes.list[i]->name, s2: typeName) != 0; ++i )
  {
    if ( ++v4 >= this->declTypes.num )
      return nullptr;
  }
  return this->declTypes.list[v4];
}


// ========================================================================
// ?GetDeclTypeFromClassname@idDeclManagerLocal@@UBAPAVidDeclInfo@@PBD@Z
// EA  : 0x826247E0
// RVA : 0x006247E0
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idDeclInfo *__fastcall idDeclManagerLocal::GetDeclTypeFromClassname(idDeclManagerLocal *this, const char *className)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->declTypes.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->declTypes.list[i]->classname, s2: className) != 0; ++i )
  {
    if ( ++v4 >= this->declTypes.num )
      return nullptr;
  }
  return this->declTypes.list[v4];
}


// ========================================================================
// ?AddDependency@idDeclManagerLocal@@UAAXPAVidDecl@@PBV2@@Z
// EA  : 0x82624858
// RVA : 0x00624858
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::AddDependency(idDeclManagerLocal *this, idDecl *decl, const idDecl *dependency)
{
  idDeclSource *declSource; // r11
  idDeclFile *sourceFile; // r11

  if ( dependency != nullptr )
  {
    declSource = dependency->declSource;
    if ( declSource != nullptr )
    {
      sourceFile = declSource->sourceFile;
      if ( sourceFile != nullptr )
        this->AddDependency(this, a2: decl, a3: sourceFile->fileName.str);
    }
  }
}


// ========================================================================
// ?ListDecls_f@idDeclManagerLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82624890
// RVA : 0x00624890
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::ListDecls_f(const idCmdArgs *args)
{
  int v1; // r22
  int fileSize; // r21
  unsigned int v3; // r23
  int v4; // r25
  int v5; // r28
  idDeclInfo **list; // r11
  unsigned int v7; // r29
  int v8; // r30
  idDeclInfo *v9; // r27
  int num; // r31
  idResource *v11; // r3
  int v12; // r31
  int v13; // r30
  int v14; // r11
  idDeclFile **v15; // r10
  idDeclFile *v16; // r8

  v1 = 0;
  fileSize = 0;
  v3 = 0;
  v4 = 0;
  if ( declManagerLocal.declTypes.num > 0 )
  {
    v5 = 0;
    do
    {
      list = declManagerLocal.declTypes.list;
      v7 = 0;
      v8 = 0;
      v9 = declManagerLocal.declTypes.list[v5];
      num = v9->num;
      v1 += num;
      if ( num > 0 )
      {
        do
        {
          v11 = idResourceList::Index(this: v9, index: v8++);
          v7 += ((int (__fastcall *)(idResource *))v11->__vftable[2].LoadResource)(a1: v11);
        }
        while ( v8 < num );
        list = declManagerLocal.declTypes.list;
      }
      v3 += v7;
      idLib::Printf(fmt: "%4ik %4i %s\n", v7 >> 10, num, list[v5]->name);
      ++v4;
      ++v5;
    }
    while ( v4 < declManagerLocal.declTypes.num );
  }
  v12 = 0;
  v13 = 0;
  v14 = 0;
  if ( declManagerLocal.loadedFiles.num >= 2 )
  {
    v15 = declManagerLocal.loadedFiles.list - 1;
    do
    {
      v16 = v15[1];
      v14 += 2;
      v15 += 2;
      v12 += v16->fileSize;
      v13 += (*v15)->fileSize;
    }
    while ( v14 < declManagerLocal.loadedFiles.num - 1 );
  }
  if ( v14 < declManagerLocal.loadedFiles.num )
    fileSize = declManagerLocal.loadedFiles.list[v14]->fileSize;
  idLib::Printf(fmt: "%i total decls is %i decl files\n", v1, declManagerLocal.loadedFiles.num);
  idLib::Printf(fmt: "%iKB in text, %iKB in structures\n", (v13 + v12 + fileSize) >> 10, v3 >> 10);
}


// ========================================================================
// ?FindDeclSource@idDeclInfo@@QAAPAVidDeclSource@@PBD@Z
// EA  : 0x826249E8
// RVA : 0x006249E8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idDeclSource *__fastcall idDeclInfo::FindDeclSource(idDeclInfo *this, char *name)
{
  char *data; // r27
  unsigned __int8 v4; // r8
  int v5; // r11
  unsigned __int8 *v6; // r9
  int v7; // r30
  idDeclSource *v9; // r30
  idStr v10[3]; // [sp+50h] [-60h] BYREF

  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  data = name;
  v10[0].baseBuffer[0] = 0;
  if ( !idStr::IsNameCanonical(name) )
  {
    idStr::operator=(this: v10, text: data);
    idStr::MakeNameCanonical(this: v10);
    data = v10[0].data;
  }
  v4 = *data;
  v5 = 0;
  if ( *data != 0 )
  {
    v6 = (unsigned __int8 *)data;
    do
    {
      ++v6;
      v5 = 31 * v5 + v4;
      v4 = *v6;
    }
    while ( *v6 != 0 );
  }
  v7 = this->declSourceHash.hash[this->declSourceHash.hashMask & this->declSourceHash.lookupMask & v5];
  if ( v7 == -1 )
  {
LABEL_9:
    idStr::FreeData(this: v10);
    return nullptr;
  }
  else
  {
    while ( idStr::Cmp(s1: data, s2: this->declSources.list[v7]->name.str) != 0 )
    {
      v7 = this->declSourceHash.indexChain[this->declSourceHash.lookupMask & v7];
      if ( v7 == -1 )
        goto LABEL_9;
    }
    v9 = this->declSources.list[v7];
    idStr::FreeData(this: v10);
    return v9;
  }
}


// ========================================================================
// __unwind$223000
// EA  : 0x82624B14
// RVA : 0x00624B14
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_223000()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?FindWithInheritance@idDeclInfo@@QAAPBVidDecl@@PBD_N@Z
// EA  : 0x82624B48
// RVA : 0x00624B48
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

const idDecl *__fastcall idDeclInfo::FindWithInheritance(idDeclInfo *this, const char *name, bool makeDefault)
{
  const char *v4; // r23
  char *data; // r25
  bool v7; // r29
  char *v8; // r3
  idResource *Existing; // r30
  idDeclInfo *v11; // r22
  int v12; // r29
  idDeclInfo *v13; // r3
  idDeclInfo *v14; // r11
  char v15; // r11
  idDeclSource *DeclSource; // r27
  int v17; // r29
  idDeclInfo *v18; // r3
  idDeclInfo *v19; // r30
  idDeclInfo *v20; // r11
  char v21; // r11
  const char *ResourceTypeName; // r3
  bool v23; // r29
  int valueInteger; // r11
  const char *v25; // r3
  const char *v26; // r3
  idStr v27[4]; // [sp+60h] [-80h] BYREF

  v4 = name;
  if ( name == nullptr || *name == 0 )
  {
    if ( !makeDefault )
      return nullptr;
    v4 = "_emptyName";
  }
  v27[0].len = 0;
  v27[0].allocedAndFlag = 20;
  data = (char *)v4;
  v27[0].data = v27[0].baseBuffer;
  v27[0].baseBuffer[0] = 0;
  if ( !idStr::IsNameCanonical(name: v4) )
  {
    idStr::operator=(this: v27, text: v4);
    idStr::MakeNameCanonical(this: v27);
    data = v27[0].data;
  }
  v7 = false;
  v8 = strstr(str1: data, str2: ".decl");
  if ( v8 != nullptr )
    v7 = v8[5] == 0;
  if ( idLib::production == PROD_DEVELOPMENT
    && !makeDefault
    && v7
    && !fileSystem->FileExists(this: fileSystem, a2: data, a3: false) )
  {
    idStr::FreeData(this: v27);
    return nullptr;
  }
  Existing = idResourceList::FindExisting(this, name: data, skipStaleCheck: false);
  if ( Existing != nullptr )
    goto LABEL_52;
  v11 = this;
  if ( !v7 )
  {
    v12 = 0;
    if ( declManager->GetNumDeclTypes(this: declManager) > 0 )
    {
      do
      {
        v13 = declManager->GetDeclType_2(this: declManager, a2: v12);
        if ( v13 != this )
        {
          v14 = v13;
          if ( v13 != nullptr )
          {
            while ( v14 != this )
            {
              v14 = v14->parent;
              if ( v14 == nullptr )
                goto LABEL_22;
            }
            v15 = 1;
          }
          else
          {
LABEL_22:
            v15 = 0;
          }
          if ( v15 != 0 )
          {
            Existing = idResourceList::FindExisting(this: v13, name: data, skipStaleCheck: false);
            if ( Existing != nullptr )
              goto LABEL_52;
          }
        }
      }
      while ( ++v12 < declManager->GetNumDeclTypes(this: declManager) );
    }
    DeclSource = idDeclInfo::FindDeclSource(this, name: data);
    if ( DeclSource == nullptr )
    {
      v17 = 0;
      if ( declManager->GetNumDeclTypes(this: declManager) <= 0 )
        goto LABEL_42;
      while ( 1 )
      {
        v18 = declManager->GetDeclType_2(this: declManager, a2: v17);
        v19 = v18;
        if ( v18 != this )
        {
          v20 = v18;
          if ( v18 != nullptr )
          {
            while ( v20 != this )
            {
              v20 = v20->parent;
              if ( v20 == nullptr )
                goto LABEL_32;
            }
            v21 = 1;
          }
          else
          {
LABEL_32:
            v21 = 0;
          }
          if ( v21 != 0 )
          {
            DeclSource = idDeclInfo::FindDeclSource(this: v18, name: data);
            if ( DeclSource != nullptr )
              break;
          }
        }
        if ( ++v17 >= declManager->GetNumDeclTypes(this: declManager) )
          goto LABEL_41;
      }
      v11 = v19;
LABEL_41:
      if ( DeclSource == nullptr )
      {
LABEL_42:
        if ( !makeDefault )
        {
          idStr::FreeData(this: v27);
          return nullptr;
        }
      }
    }
  }
  ResourceTypeName = idResourceList::GetResourceTypeName(this);
  v23 = idLib::PushWarningInfo(type: ResourceTypeName, name: v4);
  if ( common->IsInGame(this: common) && !common->IsToolActive(this: common) )
  {
    valueInteger = resource_errorInGame.valueInteger;
    if ( resource_errorInGame.valueInteger == 2 )
    {
      v25 = idResourceList::GetResourceTypeName(this);
      idLib::FatalError(fmt: "resource_errorInGame enabled: Resource loaded in game: %s : %s", v25, v4);
    }
    if ( valueInteger == 1 )
    {
      v26 = idResourceList::GetResourceTypeName(this);
      idLib::Warning(fmt: "resource_errorInGame enabled: Resource loaded in game: %s : %s", v26, v4);
    }
  }
  Existing = idResourceList::Load(this: v11, name: data, makeDefault, skipStaleCheck: false);
  if ( v23 )
    idLib::PopWarningInfo();
LABEL_52:
  idStr::FreeData(this: v27);
  return (const idDecl *)Existing;
}


// ========================================================================
// $LN94
// EA  : 0x82624F34
// RVA : 0x00624F34
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _LN94()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$223097
// EA  : 0x82624F5C
// RVA : 0x00624F5C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_223097()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 224 + 80));
}


// ========================================================================
// ?PrintMultiplayerDeclOverrides@idDeclManagerLocal@@UBAXXZ
// EA  : 0x82624F88
// RVA : 0x00624F88
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::PrintMultiplayerDeclOverrides(idDeclManagerLocal *this)
{
  int num; // r4
  int v3; // r31
  int v4; // r30

  if ( com_multiplayer.valueInteger != 0 )
  {
    idLib::Printf(fmt: "----- Multiplayer decl overrides -----\n");
    num = this->multiplayerDeclOverrides.num;
    v3 = 0;
    if ( num > 0 )
    {
      v4 = 0;
      do
      {
        idLib::Printf(fmt: "%s\n", this->multiplayerDeclOverrides.list[v4].data);
        num = this->multiplayerDeclOverrides.num;
        ++v3;
        ++v4;
      }
      while ( v3 < num );
    }
    idLib::Printf(fmt: "%d overrides\n", num);
    idLib::Printf(fmt: "--------------------------------------\n");
  }
}


// ========================================================================
// ?MarkStatic@idDeclManagerLocal@@UAAXXZ
// EA  : 0x82625020
// RVA : 0x00625020
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::MarkStatic(idDeclManagerLocal *this)
{
  int v1; // r10
  int v2; // r11
  idDeclInfo *v3; // r8
  int num; // r11
  int v5; // r10
  int v6; // r9
  int v7; // r11
  idDeclFile *v8; // r8

  v1 = 0;
  if ( this->declTypes.num > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = this->declTypes.list[v2++];
      v3->declSourceDynamicStartIndex = v3->declSources.num;
    }
    while ( v1 < this->declTypes.num );
  }
  num = this->loadedFiles.num;
  v5 = 0;
  v6 = this->declFileDependencies.num;
  this->loadedFilesDynamicStartIndex = num;
  this->dependenciesDynamicStartIndex = v6;
  if ( num > 0 )
  {
    v7 = 0;
    do
    {
      ++v5;
      v8 = this->loadedFiles.list[v7++];
      v8->dependenciesDynamicStartIndex = v8->dependencies.num;
    }
    while ( v5 < this->loadedFiles.num );
  }
}


// ========================================================================
// ?SourceFileChanged@idDeclFile@@QBA_N_N@Z
// EA  : 0x82625148
// RVA : 0x00625148
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

int __fastcall idDeclFile::SourceFileChanged(idDeclFile *this, const bool compareChecksums)
{
  idFile *v4; // r3
  char *buffer; // r29
  idFileLocal v7[2]; // [sp+50h] [-30h] BYREF
  idTempArray<char> v8; // [sp+58h] [-28h] BYREF

  v4 = fileSystem->OpenFileRead(this: fileSystem, a2: this->fileName.str, a3: 1, a4: 0);
  v7[0].file = v4;
  if ( v4 == nullptr || (int)v4->Length(this: v4) != this->fileSize )
    goto LABEL_6;
  if ( compareChecksums )
  {
    idTempArray<char>::idTempArray<char>(this: &v8, num: this->fileSize);
    buffer = v8.buffer;
    v7[0].file->Read(this: v7[0].file, a2: v8.buffer, a3: this->fileSize);
    if ( MD5_BlockChecksum(data: buffer, length: this->fileSize) != this->checksum )
    {
      if ( buffer != nullptr )
        idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
      goto LABEL_6;
    }
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
  else if ( v7[0].file->Timestamp(this: v7[0].file) != this->timestamp )
  {
LABEL_6:
    idFileLocal::~idFileLocal(this: v7);
    return 1;
  }
  idFileLocal::~idFileLocal(this: v7);
  return 0;
}


// ========================================================================
// __unwind$223928
// EA  : 0x826252B4
// RVA : 0x006252B4
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_223928()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$223929
// EA  : 0x826252DC
// RVA : 0x006252DC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_223929()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 128 + 88));
}


// ========================================================================
// ?TouchDecl_f@idDeclManagerLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82625308
// RVA : 0x00625308
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::TouchDecl_f(const idCmdArgs *args)
{
  int v2; // r31
  int v3; // r30
  const char *v4; // r4
  idDeclInfo *DeclType; // r3
  int argc; // r11
  idDeclInfo *v7; // r31
  const char *v8; // r4
  const char *v9; // r4
  const idDecl *v10; // r3
  idDecl *v11; // r31
  const char *v12; // r5
  int v13; // r29
  int v14; // r30
  const char *str; // r4
  idDecl *v16; // r3

  if ( args->argc >= 2 )
  {
    if ( args->argc <= 1 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[1];
    DeclType = idDeclManagerLocal::GetDeclType(this: &declManagerLocal, typeName: v4);
    argc = args->argc;
    v7 = DeclType;
    if ( DeclType != nullptr )
    {
      if ( argc == 3 )
      {
        v9 = args->argv[2];
        if ( v9 != nullptr
          && (v10 = idDeclInfo::FindWithInheritance(this: DeclType, name: v9, makeDefault: false),
              v11 = (idDecl *)v10,
              v10 != nullptr) )
        {
          idLib::Printf(fmt: "touched %s\n", v10->name.str);
          idDecl::ReParse(this: v11, fromDisk: true);
        }
        else
        {
          if ( args->argc <= 2 )
            v12 = &byte_8200D768;
          else
            v12 = args->argv[2];
          if ( args->argc <= 1 )
            idLib::Printf(fmt: "idDeclManagerLocal::TouchDecl_f %s '%s' not found\n", &byte_8200D768, v12);
          else
            idLib::Printf(fmt: "idDeclManagerLocal::TouchDecl_f %s '%s' not found\n", args->argv[1], v12);
        }
      }
      else
      {
        v13 = 0;
        if ( DeclType->declSources.num > 0 )
        {
          v14 = 0;
          do
          {
            str = v7->declSources.list[v14]->name.str;
            if ( str != nullptr )
            {
              v16 = (idDecl *)idDeclInfo::FindWithInheritance(this: v7, name: str, makeDefault: false);
              if ( v16 != nullptr )
                idDecl::ReParse(this: v16, fromDisk: true);
            }
            ++v13;
            ++v14;
          }
          while ( v13 < v7->declSources.num );
        }
      }
    }
    else
    {
      if ( argc <= 1 )
        v8 = &byte_8200D768;
      else
        v8 = args->argv[1];
      idLib::Printf(fmt: "idDeclManagerLocal::TouchDecl_f Unknown decl type '%s'\n", v8);
      idLib::Printf(fmt: "usage: touchDecl <type> [name]\n");
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: touchDecl <type> [name]\n");
    idLib::Printf(fmt: "valid types: ");
    v2 = 0;
    if ( declManagerLocal.declTypes.num > 0 )
    {
      v3 = 0;
      do
      {
        idLib::Printf(fmt: "%s\n", declManagerLocal.declTypes.list[v3]->name);
        ++v2;
        ++v3;
      }
      while ( v2 < declManagerLocal.declTypes.num );
    }
    idLib::Printf(fmt: "\n");
  }
}


// ========================================================================
// ?ReExportDecls_f@idDeclManagerLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82625508
// RVA : 0x00625508
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::ReExportDecls_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r31
  int v4; // r30
  const char *v5; // r4
  idDeclInfo *DeclType; // r3
  int v7; // r11
  idDeclInfo *v8; // r29
  const char *v9; // r4
  const idDecl *v10; // r3
  idDecl *v11; // r31
  int v12; // r28
  int v13; // r26
  int v14; // r27
  const char *str; // r4
  idDecl *v16; // r30
  int v17; // r31

  argc = args->argc;
  if ( args->argc == 2 || argc == 3 )
  {
    if ( argc <= 1 )
      v5 = &byte_8200D768;
    else
      v5 = args->argv[1];
    DeclType = idDeclManagerLocal::GetDeclType(this: &declManagerLocal, typeName: v5);
    v7 = args->argc;
    v8 = DeclType;
    if ( DeclType != nullptr )
    {
      if ( v7 == 3 )
      {
        v9 = args->argv[2];
        if ( v9 != nullptr
          && (v10 = idDeclInfo::FindWithInheritance(this: DeclType, name: v9, makeDefault: false),
              v11 = (idDecl *)v10,
              v10 != nullptr) )
        {
          idLib::Printf(fmt: "Re-exporting decl %s\n", v10->name.str);
          v11->RebuildTextSource(this: v11);
          idDecl::ReplaceSourceFileText(this: v11, useSourceControl: true);
        }
        else if ( args->argc <= 2 )
        {
          idLib::Printf(fmt: "Could not find decl %s\n", &byte_8200D768);
        }
        else
        {
          idLib::Printf(fmt: "Could not find decl %s\n", args->argv[2]);
        }
      }
      else
      {
        v12 = 0;
        v13 = 0;
        if ( DeclType->declSources.num > 0 )
        {
          v14 = 0;
          do
          {
            str = v8->declSources.list[v14]->name.str;
            if ( str != nullptr )
            {
              v16 = (idDecl *)idDeclInfo::FindWithInheritance(this: v8, name: str, makeDefault: false);
              if ( v16 != nullptr )
              {
                idLib::Printf(fmt: "Re-exporting decl %s\n", v16->name.str);
                v17 = Sys_Milliseconds();
                if ( v17 > v12 + 100 )
                {
                  common->UpdateConsoleDisplay(this: common, a2: true);
                  v12 = v17;
                }
                v16->RebuildTextSource(this: v16);
                idDecl::ReplaceSourceFileText(this: v16, useSourceControl: true);
              }
            }
            ++v13;
            ++v14;
          }
          while ( v13 < v8->declSources.num );
        }
      }
    }
    else if ( v7 <= 1 )
    {
      idLib::Printf(fmt: "idDeclManagerLocal::ReExportDecl_f Unknown decl type '%s'\n", &byte_8200D768);
    }
    else
    {
      idLib::Printf(fmt: "idDeclManagerLocal::ReExportDecl_f Unknown decl type '%s'\n", args->argv[1]);
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: reexportDecls type <name>\n");
    idLib::Printf(fmt: "valid types: ");
    v3 = 0;
    if ( declManagerLocal.declTypes.num > 0 )
    {
      v4 = 0;
      do
      {
        idLib::Printf(fmt: "%s\n", declManagerLocal.declTypes.list[v4]->name);
        ++v3;
        ++v4;
      }
      while ( v3 < declManagerLocal.declTypes.num );
    }
    idLib::Printf(fmt: "\n");
  }
}


// ========================================================================
// ?GetDeclTextHeader@idDeclManagerLocal@@CAXPAVidDeclInfo@@PBDAAVidStr@@@Z
// EA  : 0x82625780
// RVA : 0x00625780
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::GetDeclTextHeader(
        idDeclInfo *type,
        const char *canonicalName,
        idStr *header,
        int a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v7; // r6
  va *v8; // r3
  int v9; // [sp+8h] [-1058h]
  int v10; // [sp+Ch] [-1054h]
  int v11; // [sp+10h] [-1050h]
  int v12; // [sp+14h] [-104Ch]
  int v13; // [sp+18h] [-1048h]
  int v14; // [sp+1Ch] [-1044h]
  va v15; // [sp+50h] [-1010h] BYREF

  HIDWORD(v7) = type->name;
  LODWORD(v7) = canonicalName;
  v8 = va::va(
         this: &v15,
         fmt: "\n%s %s ",
         a3: v7,
         a4: a5,
         a5: a6,
         a6: v9,
         a7: v10,
         a8: v11,
         a9: v12,
         a10: v13,
         a11: v14);
  idStr::operator=(this: header, text: v8);
}


// ========================================================================
// ?ArgCompletion_DeclTypeName@idDeclManagerLocal@@UAAXAAVidAutoComplete@@@Z
// EA  : 0x826257D8
// RVA : 0x006257D8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::ArgCompletion_DeclTypeName(idDeclManagerLocal *this, idAutoComplete *autoComplete)
{
  int i; // r29
  idDeclInfo *v5; // r3
  idDeclInfo *v6; // r3
  idDeclInfo *v7; // r28
  int v8; // r29
  int v9; // r30
  idStr v10; // [sp+60h] [-70h] BYREF
  idStr v11[2]; // [sp+80h] [-50h] BYREF

  if ( autoComplete->args.argc == 2 )
  {
    for ( i = 0; i < this->GetNumDeclTypes(this); ++i )
    {
      v5 = this->GetDeclType_2(this, a2: i);
      idStr::idStr(this: &v10, text: v5->name);
      idAutoComplete::Append(this: autoComplete, suggestion: &v10, completingArg: -1);
      idStr::FreeData(this: &v10);
    }
  }
  if ( autoComplete->args.argc == 3 )
  {
    v6 = this->GetDeclType(this, a2: autoComplete->args.argv[1]);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = 0;
      if ( v6->declSources.num > 0 )
      {
        v9 = 0;
        do
        {
          idStr::idStr(this: v11, text: v7->declSources.list[v9]->name.str);
          idAutoComplete::Append(this: autoComplete, suggestion: v11, completingArg: -1);
          idStr::FreeData(this: v11);
          ++v8;
          ++v9;
        }
        while ( v8 < v7->declSources.num );
      }
    }
  }
}


// ========================================================================
// __unwind$224289
// EA  : 0x8262591C
// RVA : 0x0062591C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224289()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$224290
// EA  : 0x82625944
// RVA : 0x00625944
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224290()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?ArgCompletion_DeclName@idDeclManagerLocal@@UAAXAAVidAutoComplete@@PAVidDeclInfo@@@Z
// EA  : 0x82625978
// RVA : 0x00625978
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::ArgCompletion_DeclName(
        idDeclManagerLocal *this,
        idAutoComplete *autoComplete,
        idDeclInfo *parentType)
{
  int i; // r26
  idDeclInfo *v7; // r3
  idDeclInfo *v8; // r28
  idDeclInfo *v9; // r11
  char v10; // r11
  int num; // r30
  int v12; // r29
  idStr v13[3]; // [sp+50h] [-70h] BYREF

  for ( i = 0; i < this->GetNumDeclTypes(this); ++i )
  {
    v7 = this->GetDeclType_2(this, a2: i);
    v8 = v7;
    v9 = v7;
    if ( v7 != nullptr )
    {
      while ( v9 != parentType )
      {
        v9 = v9->parent;
        if ( v9 == nullptr )
          goto LABEL_5;
      }
      v10 = 1;
    }
    else
    {
LABEL_5:
      v10 = 0;
    }
    if ( v10 != 0 || v7 == parentType )
    {
      num = v7->declSources.num;
      if ( num > 0 )
      {
        v12 = 0;
        do
        {
          idStr::idStr(this: v13, text: v8->declSources.list[v12]->name.str);
          idAutoComplete::Append(this: autoComplete, suggestion: v13, completingArg: -1);
          idStr::FreeData(this: v13);
          --num;
          ++v12;
        }
        while ( num != 0 );
      }
    }
  }
}


// ========================================================================
// $M224440
// EA  : 0x82625A7C
// RVA : 0x00625A7C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _M224440()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?FreeDynamic@idDeclFile@@QAAXXZ
// EA  : 0x82625B68
// RVA : 0x00625B68
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclFile::FreeDynamic(idDeclFile *this)
{
  idDeclSource *firstDeclSourceInFile; // r4
  idDeclSource *v3; // r30
  idDeclSource *nextInFile; // r31
  unsigned int dependenciesDynamicStartIndex; // r10
  int v6; // r8
  int v7; // r31
  int size; // r11

  firstDeclSourceInFile = this->firstDeclSourceInFile;
  v3 = nullptr;
  if ( firstDeclSourceInFile != nullptr )
  {
    do
    {
      nextInFile = firstDeclSourceInFile->nextInFile;
      if ( firstDeclSourceInFile->isStatic )
      {
        v3 = firstDeclSourceInFile;
      }
      else
      {
        if ( v3 != nullptr )
          v3->nextInFile = nextInFile;
        else
          this->firstDeclSourceInFile = nextInFile;
        idMem::Free(this: &mem, ptr: firstDeclSourceInFile, align: ALIGN_16);
      }
      firstDeclSourceInFile = nextInFile;
    }
    while ( nextInFile != nullptr );
  }
  dependenciesDynamicStartIndex = this->dependenciesDynamicStartIndex;
  v6 = (dependenciesDynamicStartIndex >> 31) - 1;
  v7 = v6 & dependenciesDynamicStartIndex;
  if ( (signed int)(v6 & dependenciesDynamicStartIndex) <= this->dependencies.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->dependencies,
         newsize: v6 & dependenciesDynamicStartIndex) )
  {
    size = this->dependencies.size;
    if ( v7 < size )
      size = v7;
    this->dependencies.num = size;
  }
}


// ========================================================================
// ??0idDeclInfo@@QAA@PBD00@Z
// EA  : 0x82625C40
// RVA : 0x00625C40
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idDeclInfo *__fastcall idDeclInfo::idDeclInfo(
        idDeclInfo *this,
        const char *identifier,
        const char *classname,
        const char *fileExt)
{
  idResourceList::idResourceList(this, typeName: identifier);
  this->name = identifier;
  this->classname = classname;
  this->fileExtension = fileExt;
  this->__vftable = (idDeclInfo_vtbl *)&idDeclInfo::`vftable';
  this->nameExtension.str = &byte_8200D768;
  this->defaultFolder.str = &byte_8200D768;
  this->parent = nullptr;
  this->onReload = nullptr;
  this->declSources.list = nullptr;
  this->declSources.granularity = 0;
  this->declSources.memTag = 46;
  this->declSources.listStatic = 0;
  this->declSources.size = 0;
  this->declSources.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declSources);
  this->declSourceHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->declSourceHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->declSourceDynamicStartIndex = 0;
  return this;
}


// ========================================================================
// __unwind$224620
// EA  : 0x82625CFC
// RVA : 0x00625CFC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224620()
{
  int v0; // r12

  idResourceList::~idResourceList(this: *(idResourceList **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$224621
// EA  : 0x82625D24
// RVA : 0x00625D24
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224621()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 1072));
}


// ========================================================================
// ??1idDeclInfo@@UAA@XZ
// EA  : 0x82625D58
// RVA : 0x00625D58
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclInfo::~idDeclInfo(idDeclInfo *this)
{
  this->__vftable = (idDeclInfo_vtbl *)&idDeclInfo::`vftable';
  idHashIndex::Free(this: &this->declSourceHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declSources);
  this->__vftable = (idDeclInfo_vtbl *)&idResourceList::`vftable';
}


// ========================================================================
// __unwind$224660
// EA  : 0x82625DB8
// RVA : 0x00625DB8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224660()
{
  int v0; // r12

  idResourceList::~idResourceList(this: *(idResourceList **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$224661
// EA  : 0x82625DE0
// RVA : 0x00625DE0
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224661()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1072));
}


// ========================================================================
// ??0idDeclFile@@QAA@PBDPAVidDeclInfo@@@Z
// EA  : 0x826260A8
// RVA : 0x006260A8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idDeclFile *__fastcall idDeclFile::idDeclFile(idDeclFile *this, const char *_fileName, idDeclInfo *_defaultType)
{
  idAtomicString *p_fileName; // r28

  p_fileName = &this->fileName;
  this->fileName.str = &byte_8200D768;
  this->dependencies.list = nullptr;
  this->dependencies.granularity = 0;
  this->dependencies.memTag = 46;
  this->dependencies.listStatic = 0;
  this->dependencies.size = 0;
  this->dependencies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dependencies);
  this->includeFiles.granularity = 0;
  this->includeFiles.listStatic = 0;
  this->includeFiles.memTag = 5;
  this->includeFiles.list = nullptr;
  this->includeFiles.size = 0;
  this->includeFiles.num = 0;
  idAtomicString::Set(this: p_fileName, str_: _fileName);
  this->defaultType = _defaultType;
  this->timestamp = 0;
  this->checksum = 0;
  this->fileSize = 0;
  this->numLines = 0;
  this->everReloaded = false;
  this->firstDeclSourceInFile = nullptr;
  this->dependenciesDynamicStartIndex = -1;
  this->hadRedefinition = false;
  return this;
}


// ========================================================================
// __unwind$224911
// EA  : 0x8262616C
// RVA : 0x0062616C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224911()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 36));
}


// ========================================================================
// __unwind$224912
// EA  : 0x82626198
// RVA : 0x00626198
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224912()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// ??0idDeclManagerLocal@@QAA@XZ
// EA  : 0x826261D0
// RVA : 0x006261D0
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idDeclManagerLocal *__fastcall idDeclManagerLocal::idDeclManagerLocal(idDeclManagerLocal *this)
{
  this->__vftable = (idDeclManagerLocal_vtbl *)&idDeclManagerLocal::`vftable';
  this->declTypes.list = nullptr;
  this->declTypes.granularity = 0;
  this->declTypes.memTag = 46;
  this->declTypes.listStatic = 0;
  this->declTypes.size = 0;
  this->declTypes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declTypes);
  this->loadedFiles.list = nullptr;
  this->loadedFiles.granularity = 0;
  this->loadedFiles.memTag = 46;
  this->loadedFiles.listStatic = 0;
  this->loadedFiles.size = 0;
  this->loadedFiles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->loadedFiles);
  this->loadedFilesDynamicStartIndex = -1;
  this->declFileDependencies.list = nullptr;
  this->declFileDependencies.granularity = 0;
  this->declFileDependencies.memTag = 46;
  this->declFileDependencies.listStatic = 0;
  this->declFileDependencies.size = 0;
  this->declFileDependencies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declFileDependencies);
  this->dependenciesDynamicStartIndex = -1;
  this->checksum = 0;
  this->multiplayerDeclOverrides.granularity = 0;
  this->multiplayerDeclOverrides.memTag = 5;
  this->multiplayerDeclOverrides.listStatic = 0;
  this->multiplayerDeclOverrides.list = nullptr;
  this->multiplayerDeclOverrides.size = 0;
  this->multiplayerDeclOverrides.num = 0;
  this->registeredDeclLogTypes.granularity = 0;
  this->registeredDeclLogTypes.memTag = 5;
  this->registeredDeclLogTypes.listStatic = 0;
  this->registeredDeclLogTypes.list = nullptr;
  this->registeredDeclLogTypes.size = 0;
  this->registeredDeclLogTypes.num = 0;
  return this;
}


// ========================================================================
// __unwind$224960_0
// EA  : 0x826262BC
// RVA : 0x006262BC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224960_0()
{
  int v0; // r12

  idDeclManager::~idDeclManager(this: *(idDeclManager **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$224961_0
// EA  : 0x826262E4
// RVA : 0x006262E4
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224961_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$224962
// EA  : 0x82626310
// RVA : 0x00626310
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224962()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 20));
}


// ========================================================================
// __unwind$224963
// EA  : 0x8262633C
// RVA : 0x0062633C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224963()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 40));
}


// ========================================================================
// __unwind$224964
// EA  : 0x82626368
// RVA : 0x00626368
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_224964()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// ?GetLogDeclsList@idDeclManagerLocal@@QAAXAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x826263F8
// RVA : 0x006263F8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::GetLogDeclsList(idDeclManagerLocal *this, idList<idStr,5> *declList)
{
  int v4; // r24
  int v5; // r27
  idStr *v6; // r28
  int granularity; // r4
  int size; // r11
  bool v9; // cr58
  signed int v10; // r10
  int v11; // r4
  int v12; // r11
  int num; // r11
  size_t len; // r30
  idStr *v15; // r31

  v4 = 0;
  if ( this->registeredDeclLogTypes.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->registeredDeclLogTypes.list[v5];
      if ( declList->list != nullptr )
        goto LABEL_7;
      granularity = declList->granularity;
      if ( granularity <= 0 )
        granularity = 1;
      if ( idList<idStr,3>::Resize(this: declList, newsize: granularity) )
      {
LABEL_7:
        size = declList->size;
        if ( declList->num != size )
          goto LABEL_18;
        if ( forceIdListsToReallocateEveryAppend )
        {
          v9 = !idList<idStr,3>::Resize(this: declList, newsize: size + 1);
        }
        else
        {
          v10 = declList->granularity;
          if ( declList->granularity != 0 )
          {
            v12 = size + v10;
            __twllei(v10, 0);
            __twlgei(v10 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
            v9 = !idList<idStr,3>::Resize(this: declList, newsize: v12 - v12 % v10);
          }
          else
          {
            v11 = 2 * size;
            if ( 2 * size >= size )
            {
              if ( v11 == 0 )
                v11 = 1;
              v9 = !idList<idStr,3>::Resize(this: declList, newsize: v11);
            }
            else
            {
              v9 = !idList<idStr,3>::Resize(this: declList, newsize: 0x7FFFFFFF);
            }
          }
        }
        if ( !v9 )
        {
LABEL_18:
          num = declList->num;
          if ( num < declList->size )
          {
            len = v6->len;
            v15 = &declList->list[num];
            idStr::EnsureAlloced(this: v15, amount: v6->len + 1, keepold: false, geometricGrowth: false);
            memcpy(Dst: v15->data, Src: v6->data, Size: len);
            v15->data[len] = 0;
            v15->len = len;
            ++declList->num;
          }
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->registeredDeclLogTypes.num );
  }
}


// ========================================================================
// ?FreeDynamic@idDeclInfo@@QAAXXZ
// EA  : 0x826265B0
// RVA : 0x006265B0
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclInfo::FreeDynamic(idDeclInfo *this)
{
  int v2; // r29
  int v3; // r30
  char *data; // r10
  int v5; // r4
  unsigned __int8 i; // r9
  idStr v7; // [sp+50h] [-290h] BYREF
  char v8; // [sp+70h] [-270h] BYREF
  idStrStatic<256> v9; // [sp+170h] [-170h] BYREF

  if ( this->declSources.num != this->declSourceDynamicStartIndex )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idList<idObstacleBuffers *,5>::SetNum(
      this: (idList<int,37> *)&this->declSources,
      newNum: (((unsigned int)this->declSourceDynamicStartIndex >> 31) - 1) & this->declSourceDynamicStartIndex);
    idHashIndex::Clear(this: &this->declSourceHash);
    v7.baseBuffer[0] = 0;
    v8 = 0;
    v7.len = 0;
    v7.data = &v8;
    v7.allocedAndFlag = -2147483392;
    v2 = 0;
    if ( this->declSources.num > 0 )
    {
      v3 = 0;
      do
      {
        idStrStatic<256>::idStrStatic<256>(this: &v9, text: this->declSources.list[v3]->name.str);
        v7.len = v9.len;
        memcpy(Dst: v7.data, Src: v9.data, Size: v9.len + 1);
        idStr::FreeData(this: &v9);
        idStr::MakeNameCanonical(this: &v7);
        data = v7.data;
        v5 = 0;
        for ( i = *v7.data; *data != 0; i = *data )
        {
          ++data;
          v5 = 31 * v5 + i;
        }
        idHashIndex::Add(this: &this->declSourceHash, key: v5, index: v2++);
        ++v3;
      }
      while ( v2 < this->declSources.num );
    }
    idStr::FreeData(this: &v7);
    idMem::PopHeap(this: &mem);
  }
}


// ========================================================================
// __unwind$225123
// EA  : 0x826266F4
// RVA : 0x006266F4
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225123()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 736 + 656));
}


// ========================================================================
// __unwind$225124
// EA  : 0x8262671C
// RVA : 0x0062671C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225124()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 736 + 80));
}


// ========================================================================
// ?AddDeclSource@idDeclInfo@@QAAXPAVidDeclSource@@@Z
// EA  : 0x82626750
// RVA : 0x00626750
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclInfo::AddDeclSource(
        idDeclInfo *this,
        idDeclSource *ds,
        int a3,
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
        idDeclSource *a14)
{
  const char *str; // r10
  int v17; // r30
  int v18; // r9
  int v19; // r3

  a14 = ds;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  str = ds->name.str;
  v18 = *(unsigned __int8 *)ds->name.str;
  v17 = 0;
  if ( v18 != 0 )
  {
    do
    {
      ++str;
      v17 = 31 * v17 + (unsigned __int8)v18;
      LOBYTE(v18) = *str;
    }
    while ( *str != 0 );
  }
  v19 = idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->declSources,
          obj: (const encounterGroupRole_t *)&a14);
  idHashIndex::Add(this: &this->declSourceHash, key: v17, index: v19);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$225281
// EA  : 0x826267E4
// RVA : 0x006267E4
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225281()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 128 + 80));
}


// ========================================================================
// ?MakeDeclTree_f@idDeclManagerLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82626818
// RVA : 0x00626818
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::MakeDeclTree_f(const idCmdArgs *args)
{
  const char *v1; // r28
  idSourceControl *v2; // r3
  int v3; // r29
  int v4; // r30
  int num; // r5
  int v6; // r10
  _DWORD *v7; // r20
  const char *v8; // r14
  int v9; // r17
  int v10; // r29
  int v11; // r26
  idFile *v12; // r25
  idFile *v13; // r30
  unsigned int v14; // r23
  char *v15; // r24
  int v16; // r28
  int v17; // r27
  int v18; // r27
  int v19; // r28
  int v20; // r8
  _DWORD *i; // r11
  int v22; // r10
  int v23; // r10
  int j; // r11
  int v25; // r10
  unsigned int v26; // r30
  int v27; // r11
  idDeclFile *v28; // r3
  idDeclFile *v29; // r3
  int v30; // r10
  int v31; // r10
  int v32; // r29
  int v33; // r30
  idDeclFile *v34; // r9
  idStr *list; // r29
  int size; // r30
  idStr *v37; // r28
  int v38; // [sp+50h] [-280h]
  idList<idStr,5> v39; // [sp+60h] [-270h] BYREF
  int v40; // [sp+70h] [-260h]
  int v41; // [sp+74h] [-25Ch]
  const char *v42; // [sp+78h] [-258h]
  idList<idStr,5> v43; // [sp+80h] [-250h] BYREF
  const char *v44; // [sp+90h] [-240h]
  char *v45; // [sp+94h] [-23Ch]
  const char *v46; // [sp+98h] [-238h]
  const char *v47; // [sp+9Ch] [-234h]
  idStr v48; // [sp+A0h] [-230h] BYREF
  idDeclFile *v49; // [sp+C0h] [-210h]
  char *v50; // [sp+C8h] [-208h]
  unsigned int v51; // [sp+CCh] [-204h]
  idStr v52; // [sp+D0h] [-200h] BYREF
  idStr v53; // [sp+F0h] [-1E0h] BYREF
  idStr v54; // [sp+110h] [-1C0h] BYREF
  char v55[416]; // [sp+130h] [-1A0h] BYREF

  v1 = "declTree";
  v2 = idLib::sourceControl;
  v47 = "declTree";
  if ( idLib::sourceControl != nullptr )
  {
    *(_WORD *)&v39.memTag = 1280;
    memset(&v39, 0, 14);
    v3 = 0;
    if ( declManagerLocal.loadedFiles.num > 0 )
    {
      v4 = 0;
      do
      {
        v42 = (const char *)&declManagerLocal.loadedFiles.list[v4];
        if ( idStr::Icmpn(s1: declManagerLocal.loadedFiles.list[v4]->fileName.str, s2: "declTree", n: 8) != 0 )
        {
          fileSystem->RelativePathToOSPath_2(
            this: fileSystem,
            a2: declManagerLocal.loadedFiles.list[v4]->fileName.str,
            a3: v55,
            a4: 256,
            a5: FSPATH_BASE);
          idStr::idStr(this: &v53, text: v55);
          idList<idStr,5>::Append(this: &v39, obj: &v53);
          idStr::FreeData(this: &v53);
        }
        ++v3;
        ++v4;
      }
      while ( v3 < declManagerLocal.loadedFiles.num );
      v2 = idLib::sourceControl;
    }
    v2->CheckOut(this: v2, a2: &v39);
    if ( v39.listStatic == 0 || v39.listStatic == 2 )
    {
      if ( v39.list != nullptr )
        idListArrayDelete<idStr>(ptr: v39.list, num: v39.size);
      v39.list = nullptr;
      v39.size = 0;
    }
    v2 = idLib::sourceControl;
    v39.num = 0;
  }
  num = declManagerLocal.declTypes.num;
  v40 = 0;
  if ( declManagerLocal.declTypes.num > 0 )
  {
    v38 = 0;
    v42 = "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP";
    v44 = "Couldn't open %s for write";
    v45 = ".decl";
    v46 = "Couldn't open %s for read/write";
    do
    {
      v6 = v38;
      v41 = 0;
      v7 = *(idDeclInfo **)((char *)declManagerLocal.declTypes.list + v38);
      v8 = (const char *)v7[261];
      if ( (int)v7[269] > 0 )
      {
        v9 = 0;
        do
        {
          v10 = *(_DWORD *)(v7[268] + v9);
          v11 = *(_DWORD *)(v10 + 4);
          if ( idStr::Icmpn(s1: *(const char **)(v11 + 4), s2: v1, n: 8) != 0 )
          {
            v12 = fileSystem->OpenFileReadWrite(this: fileSystem, a2: *(_DWORD *)(v11 + 4), a3: 0, a4: 0);
            if ( v12 != nullptr )
            {
              idStr::idStr(this: &v48, text: v1);
              idStr::AppendPath(this: &v48, text: v8);
              idStr::AppendPath(this: &v48, text: *(const char **)v10);
              idStr::Append(this: &v48, text: v45);
              v13 = fileSystem->OpenFileWrite(this: fileSystem, a2: v48.data, a3: 0);
              if ( v13 != nullptr )
              {
                v51 = *(_DWORD *)(v11 + 20);
                v14 = v51;
                v15 = (char *)idMem::AllocWithLocation(
                                this: &mem,
                                location: v42,
                                size: v51,
                                tag: TAG_TEMP,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
                v50 = v15;
                v12->Read(this: v12, a2: v15, a3: v14);
                v16 = 0;
                if ( *(int *)(v11 + 60) > 0 )
                {
                  v17 = 0;
                  do
                  {
                    idStr::idStr(this: &v52, text: *(const char **)(v11 + 4));
                    idStr::StripFilename(this: &v52);
                    idStr::AppendPath(this: &v52, text: *(const char **)(v17 + *(_DWORD *)(v11 + 56) + 4));
                    v13->Printf(this: v13, a2: "#include \"/%s\"\n", v52.data);
                    idStr::FreeData(this: &v52);
                    ++v16;
                    v17 += 32;
                  }
                  while ( v16 < *(_DWORD *)(v11 + 60) );
                }
                v18 = v13->Tell(this: v13);
                v13->Write(this: v13, a2: &v15[*(_DWORD *)(v10 + 20)], a3: *(_DWORD *)(v10 + 24));
                ((void (__fastcall *)(idFile *, int))v13->dtr_idFile)(a1: v13, a2: 1);
                v19 = 0;
                v20 = *(_DWORD *)(v10 + 24) + *(_DWORD *)(v10 + 20);
                if ( *(_DWORD *)(v11 + 32) == v10 )
                  *(_DWORD *)(v11 + 32) = *(_DWORD *)(v10 + 12);
                for ( i = *(_DWORD **)(v11 + 32); i != nullptr; i = (_DWORD *)i[3] )
                {
                  if ( i[3] == v10 )
                    i[3] = *(_DWORD *)(v10 + 12);
                  if ( i != (_DWORD *)v10 )
                  {
                    v22 = i[5];
                    if ( v22 < *(_DWORD *)(v10 + 20) )
                    {
                      v23 = i[6] + v22;
                      if ( v23 > v19 )
                        v19 = v23;
                    }
                  }
                }
                for ( j = *(_DWORD *)(v11 + 32); j != 0; j = *(_DWORD *)(j + 12) )
                {
                  v25 = *(_DWORD *)(j + 20);
                  if ( v25 > *(_DWORD *)(v10 + 20) )
                    *(_DWORD *)(j + 20) = v25 - v20 + v19;
                }
                v26 = v14 - v20;
                memmove(Dst: &v15[v19], Src: &v15[v20], Size: v14 - v20);
                v12->SetLength(this: v12, a2: 0);
                v12->Write(this: v12, a2: v15, a3: v26 + v19);
                ((void (__fastcall *)(idFile *, int))v12->dtr_idFile)(a1: v12, a2: 1);
                *(_DWORD *)(v10 + 12) = 0;
                v27 = *(_DWORD *)(v11 + 60);
                *(_DWORD *)(v10 + 20) = v18;
                *(_DWORD *)(v10 + 8) = v27;
                v28 = (idDeclFile *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x48u,
                                      tag: TAG_DECL,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
                v49 = v28;
                if ( v28 != nullptr )
                  v29 = idDeclFile::idDeclFile(this: v28, _fileName: v48.data, _defaultType: *(idDeclInfo **)(v11 + 8));
                else
                  v29 = nullptr;
                *(_DWORD *)(v10 + 4) = v29;
                v29->firstDeclSourceInFile = (idDeclSource *)v10;
                idList<idAnimWebBlendTree *,5>::Append(
                  this: (idList<enum encounterGroupRole_t,5> *)&declManagerLocal.loadedFiles,
                  obj: (const encounterGroupRole_t *)(v10 + 4));
                if ( v15 != nullptr )
                  idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
                idStr::FreeData(this: &v48);
                v1 = v47;
              }
              else
              {
                idLib::Warning(fmt: v44, v48.data);
                ((void (__fastcall *)(idFile *, int))v12->dtr_idFile)(a1: v12, a2: 1);
                idStr::FreeData(this: &v48);
              }
            }
            else
            {
              idLib::Warning(fmt: v46, *(_DWORD *)(v11 + 4));
            }
          }
          v9 += 4;
          v30 = v7[269];
          ++v41;
        }
        while ( v41 < v30 );
        num = declManagerLocal.declTypes.num;
        v6 = v38;
      }
      v38 = v6 + 4;
      ++v40;
    }
    while ( v40 < num );
    v2 = idLib::sourceControl;
  }
  if ( v2 != nullptr )
  {
    *(_WORD *)&v43.memTag = 1280;
    memset(&v43, 0, 14);
    v31 = declManagerLocal.loadedFiles.num;
    v32 = 0;
    if ( declManagerLocal.loadedFiles.num > 0 )
    {
      v33 = 0;
      do
      {
        v34 = declManagerLocal.loadedFiles.list[v33];
        if ( v34->firstDeclSourceInFile == nullptr )
        {
          fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v34->fileName.str, a3: v55, a4: 256, a5: FSPATH_BASE);
          idStr::idStr(this: &v54, text: v55);
          idList<idStr,5>::Append(this: &v43, obj: &v54);
          idStr::FreeData(this: &v54);
          v31 = declManagerLocal.loadedFiles.num;
        }
        ++v32;
        ++v33;
      }
      while ( v32 < v31 );
      v2 = idLib::sourceControl;
    }
    v2->Delete(this: v2, a2: &v43);
    if ( v43.listStatic == 0 || v43.listStatic == 2 )
    {
      list = v43.list;
      if ( v43.list != nullptr )
      {
        size = v43.size;
        v37 = v43.list;
        if ( v43.size > 0 )
        {
          do
          {
            idStr::FreeData(this: list);
            --size;
            ++list;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: v37, align: ALIGN_16);
      }
    }
  }
}


// ========================================================================
// __unwind$225379_1
// EA  : 0x82626EE4
// RVA : 0x00626EE4
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225379_1()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 720 + 96));
}


// ========================================================================
// __unwind$225380_0
// EA  : 0x82626F0C
// RVA : 0x00626F0C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225380_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 240));
}


// ========================================================================
// __unwind$225381_0
// EA  : 0x82626F34
// RVA : 0x00626F34
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225381_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 160));
}


// ========================================================================
// __unwind$225382
// EA  : 0x82626F5C
// RVA : 0x00626F5C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225382()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 720 + 200));
}


// ========================================================================
// __unwind$225383
// EA  : 0x82626F84
// RVA : 0x00626F84
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225383()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 208));
}


// ========================================================================
// __unwind$225384
// EA  : 0x82626FAC
// RVA : 0x00626FAC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225384()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 720 + 192), tag: TAG_DECL);
}


// ========================================================================
// __unwind$225385
// EA  : 0x82626FD8
// RVA : 0x00626FD8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225385()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 720 + 128));
}


// ========================================================================
// __unwind$225386
// EA  : 0x82627000
// RVA : 0x00627000
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225386()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 720 + 272));
}


// ========================================================================
// ?ShowAvailableDeclLogs@@YAXAAVidAutoComplete@@@Z
// EA  : 0x826270F0
// RVA : 0x006270F0
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall ShowAvailableDeclLogs(idAutoComplete *autoComplete)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  int num; // r30
  idStr *list; // r26
  char **p_data; // r29
  va *v8; // r3
  int size; // r30
  idStr *v10; // r29
  int v11; // [sp+8h] [-10B8h]
  int v12; // [sp+Ch] [-10B4h]
  int v13; // [sp+10h] [-10B0h]
  int v14; // [sp+14h] [-10ACh]
  int v15; // [sp+18h] [-10A8h]
  int v16; // [sp+1Ch] [-10A4h]
  idList<idStr,5> v17; // [sp+50h] [-1070h] BYREF
  idStr v18; // [sp+60h] [-1060h] BYREF
  va v19; // [sp+80h] [-1040h] BYREF

  *(_WORD *)&v17.memTag = 1280;
  memset(&v17, 0, 14);
  idDeclManagerLocal::GetLogDeclsList(this: &declManagerLocal, declList: &v17);
  list = v17.list;
  num = v17.num;
  if ( v17.num > 0 )
  {
    p_data = &v17.list[-1].data;
    do
    {
      p_data += 8;
      HIDWORD(v4) = *p_data;
      v8 = va::va(this: &v19, fmt: "%s", a3: v4, a4: v3, a5: v2, a6: v11, a7: v12, a8: v13, a9: v14, a10: v15, a11: v16);
      idStr::idStr(this: &v18, text: v8);
      idAutoComplete::Append(this: autoComplete, suggestion: &v18, completingArg: -1);
      idStr::FreeData(this: &v18);
      --num;
    }
    while ( num != 0 );
  }
  if ( (v17.listStatic == 0 || v17.listStatic == 2) && list != nullptr )
  {
    size = v17.size;
    if ( v17.size > 0 )
    {
      v10 = list;
      do
      {
        idStr::FreeData(this: v10);
        --size;
        ++v10;
      }
      while ( size != 0 );
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$225886
// EA  : 0x826271EC
// RVA : 0x006271EC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225886()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4288 + 80));
}


// ========================================================================
// __unwind$225887
// EA  : 0x82627214
// RVA : 0x00627214
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_225887()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4288 + 96));
}


// ========================================================================
// ?AddDecl@idDeclFile@@IAAXPAVidDeclInfo@@PBDHHH@Z
// EA  : 0x82627248
// RVA : 0x00627248
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclFile::AddDecl(
        idDeclFile *this,
        idDeclInfo *declType,
        char *canonicalName,
        int sourceLine,
        int offset,
        int length)
{
  idDeclSource *DeclSource; // r3
  idDeclSource *v13; // r30
  idDeclFile **p_sourceFile; // r28
  const char *str; // r6
  idDeclSource *v16; // r3
  int v17; // r10
  int v18; // r9
  int v19; // r8
  int v20; // r7
  int v21; // r6
  int v22; // r5
  idDecl *Existing; // r3
  idDecl *v24; // r29
  int v25; // [sp+8h] [-A8h]
  int v26; // [sp+Ch] [-A4h]
  int v27; // [sp+10h] [-A0h]
  int v28; // [sp+14h] [-9Ch]
  int v29; // [sp+18h] [-98h]
  idDeclSource *v30; // [sp+1Ch] [-94h]

  DeclSource = idDeclInfo::FindDeclSource(this: declType, name: canonicalName);
  v13 = DeclSource;
  if ( DeclSource != nullptr )
  {
    p_sourceFile = &DeclSource->sourceFile;
    if ( DeclSource->sourceFile != this )
    {
      str = this->fileName.str;
      this->hadRedefinition = true;
      idLib::Warning(fmt: "Decl %s defined in files %s and %s.", canonicalName, (*p_sourceFile)->fileName.str, str);
      return;
    }
  }
  else
  {
    v16 = (idDeclSource *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x1Cu,
                            tag: TAG_DECL,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    if ( v16 != nullptr )
      v13 = idDeclSource::idDeclSource(this: v16, _isStatic: this->dependenciesDynamicStartIndex < 0);
    else
      v13 = nullptr;
    idAtomicString::Set(this: &v13->name, str_: canonicalName);
    v13->sourceFile = this;
    v13->nextInFile = this->firstDeclSourceInFile;
    this->firstDeclSourceInFile = v13;
    p_sourceFile = &v13->sourceFile;
    idDeclInfo::AddDeclSource(
      this: declType,
      ds: v13,
      a3: v22,
      a4: v21,
      a5: v20,
      a6: v19,
      a7: v18,
      a8: v17,
      a9: v25,
      a10: v26,
      a11: v27,
      a12: v28,
      a13: v29,
      a14: v30);
  }
  v13->sourceTextOffset = offset;
  v13->sourceTextLength = length;
  v13->sourceLine = sourceLine;
  *p_sourceFile = this;
  Existing = (idDecl *)idResourceList::FindExisting(this: declType, name: canonicalName, skipStaleCheck: false);
  v24 = Existing;
  if ( Existing != nullptr )
  {
    idDecl::DefineFromSource(this: Existing, ds: v13);
    idDecl::ReParse(this: v24, fromDisk: true);
  }
}


// ========================================================================
// __unwind$226019
// EA  : 0x82627380
// RVA : 0x00627380
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226019()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?LoadAndParse@idDeclFile@@QAAHXZ
// EA  : 0x826273B8
// RVA : 0x006273B8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

unsigned int __fastcall idDeclFile::LoadAndParse(idDeclFile *this)
{
  const char *str; // r11
  int v4; // r29
  int v5; // r3
  int v6; // r27
  idDeclInfo *v7; // r28
  idDeclInfo *DeclType; // r27
  int v9; // r29
  int line; // r26
  int v11; // r28
  void *v12; // [sp+50h] [-210h] BYREF
  idToken v13; // [sp+60h] [-200h] BYREF
  idStr v14; // [sp+B0h] [-1B0h] BYREF
  idStr v15; // [sp+D0h] [-190h] BYREF
  idLexer v16; // [sp+F0h] [-170h] BYREF
  idStr v17; // [sp+180h] [-E0h] BYREF
  idStr v18; // [sp+1A0h] [-C0h] BYREF

  str = this->fileName.str;
  v12 = nullptr;
  if ( *str == 0 )
    return 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dependencies);
  idList<idStr,99>::~idList<idStr,99>(this: &this->includeFiles);
  v4 = fileSystem->ReadFile(this: fileSystem, a2: this->fileName.str, a3: &v12, a4: &this->timestamp);
  if ( v4 == -1 )
    idLib::FatalError(fmt: "couldn't load %s", this->fileName.str);
  this->checksum = MD5_BlockChecksum(data: v12, length: v4);
  this->fileSize = v4;
  if ( idStr::Icmpn(s1: this->fileName.str, s2: "declTree/", n: 9) != 0 )
  {
    idLexer::idLexer(this: &v16, flags_: 156216);
    if ( !idLexer::LoadMemory(this: &v16, ptr: (const char *)v12, length_: v4, name: this->fileName.str) )
      idLib::Error(fmt: "Couldn't parse %s", this->fileName.str);
    v13.len = 0;
    v13.baseBuffer[0] = 0;
    v13.intvalue = 0;
    v13.allocedAndFlag = 20;
    v13.data = v13.baseBuffer;
    memset(&v13.whiteSpaceStart_p, 0, 12);
    v13.floatvalue = -3.4028235e38;
    while ( idLexer::ReadToken(this: &v16, token: &v13) )
    {
      if ( idStr::Cmp(s1: v13.data, s2: "$") == 0 )
      {
        idLexer::Error(this: &v16, str: "$ precompiled directives only allowed in decls bodies and include files");
        break;
      }
      if ( idStr::Cmp(s1: v13.data, s2: "#") != 0 )
      {
        DeclType = idDeclManagerLocal::GetDeclType(this: &declManagerLocal, typeName: v13.data);
        if ( DeclType != nullptr )
        {
          if ( !idLexer::ReadToken(this: &v16, token: &v13) )
          {
            idLexer::Error(this: &v16, str: "Could not read decl name after type");
            break;
          }
        }
        else
        {
          DeclType = this->defaultType;
          if ( DeclType == nullptr )
          {
            idLexer::Warning(this: &v16, str: "Unknown decl type %s", v13.data);
            break;
          }
        }
        if ( idStr::Icmp(s1: v13.data, s2: "{") != 0 )
        {
          if ( *DeclType->defaultFolder.str == 0 )
          {
            idStr::idStr(this: &v18, text: this->fileName.str);
            idStr::StripFilename(this: &v18);
            idAtomicString::Set(this: &DeclType->defaultFolder, str_: v18.data);
            idStr::FreeData(this: &v18);
          }
          idStr::idStr(this: &v15, text: &v13);
          idStr::MakeNameCanonical(this: &v15);
          idLexer::SkipWhiteSpace(this: &v16, currentLine: false);
          v9 = v16.script_p - v16.buffer;
          line = v16.line;
          if ( !idLexer::ExpectTokenString(this: &v16, string: "{") )
          {
            idStr::FreeData(this: &v15);
            break;
          }
          v11 = v16.line;
          if ( !idLexer::SkipBracedSection(this: &v16, parseFirstBrace: false) )
            idLib::Warning(
              fmt: "Mismatched braces in decl '%s' file '%s' at line %i",
              v15.data,
              this->fileName.str,
              v11);
          idDeclFile::AddDecl(
            this,
            declType: DeclType,
            canonicalName: v15.data,
            sourceLine: line,
            offset: v9,
            length: v16.script_p - v16.buffer - v9);
          idStr::FreeData(this: &v15);
        }
        else
        {
          idLexer::Error(this: &v16, str: "Missing decl name");
        }
      }
      else
      {
        if ( !idLexer::ExpectTokenString(this: &v16, string: "include") )
          break;
        if ( !idLexer::ReadToken(this: &v16, token: &v13) )
        {
          idLexer::Error(this: &v16, str: "Could not read token after include");
          break;
        }
        idList<idStr,5>::Append(this: &this->includeFiles, obj: &v13);
      }
      idStr::FreeData(this: &v13);
      v13.floatvalue = -3.4028235e38;
      v13.allocedAndFlag = 20;
      v13.data = v13.baseBuffer;
      v13.len = 0;
      v13.baseBuffer[0] = 0;
      v13.intvalue = 0;
      memset(&v13.whiteSpaceStart_p, 0, 12);
    }
    idStr::FreeData(this: &v13);
    idLexer::~idLexer(this: &v16);
  }
  else
  {
    v5 = idStr::Find(str: this->fileName.str, c: 47, start: 9, end: -1);
    v6 = v5;
    if ( v5 > 0 )
    {
      v14.len = 0;
      v14.baseBuffer[0] = 0;
      v14.allocedAndFlag = 20;
      v14.data = v14.baseBuffer;
      idStr::CopyRange(this: &v14, text: this->fileName.str, start: 9, end: v5);
      v7 = idDeclManagerLocal::GetDeclType(this: &declManagerLocal, typeName: v14.data);
      if ( v7 != nullptr )
      {
        idStr::idStr(this: &v17, text: &this->fileName.str[v6 + 1]);
        idStr::StripFileExtension(this: &v17);
        idStr::MakeNameCanonical(this: &v17);
        idDeclFile::AddDecl(this, declType: v7, canonicalName: v17.data, sourceLine: 0, offset: 0, length: v4);
        idStr::FreeData(this: &v17);
      }
      else
      {
        idLib::Warning(fmt: "Unknown decl type %s", v14.data);
      }
      idStr::FreeData(this: &v14);
    }
  }
  fileSystem->FreeFile(this: fileSystem, a2: v12);
  return this->checksum;
}


// ========================================================================
// $LN194
// EA  : 0x8262789C
// RVA : 0x0062789C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _LN194()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 176));
}


// ========================================================================
// __unwind$226065_0
// EA  : 0x826278C4
// RVA : 0x006278C4
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226065_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 384));
}


// ========================================================================
// __unwind$226066_0
// EA  : 0x826278EC
// RVA : 0x006278EC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226066_0()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 608 + 240));
}


// ========================================================================
// __unwind$226067_0
// EA  : 0x82627914
// RVA : 0x00627914
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226067_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 96));
}


// ========================================================================
// __unwind$226068
// EA  : 0x8262793C
// RVA : 0x0062793C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226068()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 416));
}


// ========================================================================
// __unwind$226069
// EA  : 0x82627964
// RVA : 0x00627964
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226069()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 208));
}


// ========================================================================
// ?Reload@idDeclManagerLocal@@UAAX_N@Z
// EA  : 0x82627990
// RVA : 0x00627990
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::Reload(idDeclManagerLocal *this, bool force)
{
  BOOL v4; // r19
  int num; // r9
  int v6; // r11
  int v7; // r10
  declFileDependency_t *v8; // r9
  char v9; // r29
  int v10; // r28
  int v11; // r30
  declFileDependency_t *v12; // r11
  unsigned int v13; // r3
  declFileDependency_t *list; // r11
  char v15; // r25
  int v16; // r23
  int v17; // r24
  int v18; // r26
  idDeclFile *v19; // r28
  int v20; // r27
  int v21; // r30
  int v22; // r29
  declFileDependency_t *v23; // r11
  int v24; // r28
  int v25; // r29
  idDeclFile *v26; // r30
  char v27; // r11
  bool v28; // r5
  int v29; // r6
  int v30; // r10

  v4 = force;
  soundSystem->SetMute(this: soundSystem, a2: true);
  if ( !force )
  {
    num = this->declFileDependencies.num;
    v6 = 0;
    if ( num > 0 )
    {
      v7 = 0;
      do
      {
        ++v6;
        v8 = &this->declFileDependencies.list[v7++];
        v8->dirty = false;
        num = this->declFileDependencies.num;
      }
      while ( v6 < num );
    }
    v9 = 0;
    v10 = 0;
    if ( num > 0 )
    {
      v11 = 0;
      while ( 1 )
      {
        v12 = &this->declFileDependencies.list[v11];
        if ( v12->timestamp == 0 )
          break;
        v13 = fileSystem->GetTimestamp(this: fileSystem, a2: v12->fileName.str, a3: false);
        list = this->declFileDependencies.list;
        if ( v13 != list[v11].timestamp )
        {
          list[v11].timestamp = v13;
          this->declFileDependencies.list[v11].dirty = true;
          goto LABEL_11;
        }
LABEL_12:
        ++v10;
        ++v11;
        if ( v10 >= this->declFileDependencies.num )
          goto LABEL_13;
      }
      v12->dirty = true;
LABEL_11:
      v9 = 1;
      goto LABEL_12;
    }
LABEL_13:
    if ( v9 != 0 )
    {
      do
      {
        v15 = 0;
        v16 = 0;
        if ( this->loadedFiles.num > 0 )
        {
          v17 = 0;
          do
          {
            v18 = 0;
            v19 = this->loadedFiles.list[v17];
            if ( v19->dependencies.num > 0 )
            {
              v20 = 0;
              do
              {
                if ( this->declFileDependencies.list[v19->dependencies.list[v20]].dirty )
                {
                  v21 = 0;
                  if ( this->declFileDependencies.num > 0 )
                  {
                    v22 = 0;
                    while ( 1 )
                    {
                      v23 = &this->declFileDependencies.list[v22];
                      if ( !v23->dirty && idStr::Icmp(s1: v23->fileName.str, s2: v19->fileName.str) == 0 )
                        break;
                      ++v21;
                      ++v22;
                      if ( v21 >= this->declFileDependencies.num )
                        goto LABEL_26;
                    }
                    v15 = 1;
                    this->declFileDependencies.list[v21].dirty = true;
                  }
                }
LABEL_26:
                ++v18;
                ++v20;
              }
              while ( v18 < v19->dependencies.num );
            }
            ++v16;
            ++v17;
          }
          while ( v16 < this->loadedFiles.num );
        }
      }
      while ( v15 != 0 );
    }
  }
  v24 = 0;
  if ( this->loadedFiles.num > 0 )
  {
    v25 = 0;
    do
    {
      v26 = this->loadedFiles.list[v25];
      if ( v4 || (v27 = 0, v26->timestamp == 0) )
        v27 = 1;
      v28 = v27;
      if ( v27 == 0 )
      {
        v28 = ((int (__fastcall *)(idFileSystem *, const char *))fileSystem->GetTimestamp)(
                a1: fileSystem,
                a2: v26->fileName.str) != v26->timestamp;
        if ( !v28 )
        {
          v29 = 0;
          if ( v26->dependencies.num > 0 )
          {
            v30 = 0;
            while ( !this->declFileDependencies.list[v26->dependencies.list[v30]].dirty )
            {
              ++v29;
              ++v30;
              if ( v29 >= v26->dependencies.num )
                goto LABEL_42;
            }
            v28 = true;
          }
        }
      }
LABEL_42:
      if ( v28 )
      {
        idLib::Printf(fmt: "...reloading '%s'\n", v26->fileName.str);
        v26->everReloaded = true;
        idDeclFile::LoadAndParse(this: v26);
      }
      ++v24;
      ++v25;
    }
    while ( v24 < this->loadedFiles.num );
  }
  soundSystem->SetMute(this: soundSystem, a2: false);
}


// ========================================================================
// ?RegisterDeclFolder@idDeclManagerLocal@@UAAXPBD0PAVidDeclInfo@@@Z
// EA  : 0x82627CE0
// RVA : 0x00627CE0
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::RegisterDeclFolder(
        idDeclManagerLocal *this,
        const char *folder,
        const char *extension,
        idDeclInfo *defaultType)
{
  idFileList *v6; // r29
  int v7; // r25
  int v8; // r28
  int v9; // r26
  int v10; // r30
  idDeclFile *v11; // r3
  idDeclFile *v12; // r30
  idDeclFile *v13; // [sp+50h] [-70h] BYREF

  if ( idLib::production != PROD_PRODUCTION )
  {
    v6 = (idFileList *)((int (__fastcall *)(idFileSystem *))fileSystem->ListFilesTree)(a1: fileSystem);
    v7 = 0;
    if ( v6->list.num <= 0 )
    {
LABEL_12:
      fileSystem->FreeFileList(this: fileSystem, a2: v6);
    }
    else
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = 0;
        if ( this->loadedFiles.num > 0 )
          break;
LABEL_8:
        v11 = (idDeclFile *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x48u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        v13 = v11;
        if ( v11 != nullptr )
          v12 = idDeclFile::idDeclFile(this: v11, _fileName: v6->list.list[v8].data, _defaultType: defaultType);
        else
          v12 = nullptr;
        v13 = v12;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->loadedFiles,
          obj: (const encounterGroupRole_t *)&v13);
        idDeclFile::LoadAndParse(this: v12);
        ++v7;
        ++v8;
        if ( v7 >= v6->list.num )
          goto LABEL_12;
      }
      v10 = 0;
      while ( idStr::IcmpPath(s1: this->loadedFiles.list[v10]->fileName.str, s2: v6->list.list[v8].data) != 0 )
      {
        ++v9;
        ++v10;
        if ( v9 >= this->loadedFiles.num )
          goto LABEL_8;
      }
      idLib::Error(
        fmt: "Decl file %s loaded twice, RegisterDeclFolder called twice on the same folder?",
        v6->list.list[v8].data);
      _LN68_0();
    }
  }
}


// ========================================================================
// $LN68_0
// EA  : 0x82627E48
// RVA : 0x00627E48
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _LN68_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?CreateNewDecl@idDeclManagerLocal@@UAAPAVidDecl@@PAVidDeclInfo@@PBD11@Z
// EA  : 0x82627E80
// RVA : 0x00627E80
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idDecl *__fastcall idDeclManagerLocal::CreateNewDecl(
        idDeclManagerLocal *this,
        idDeclInfo *type,
        const char *name,
        const char *_fileName,
        const char *declText)
{
  idDecl *result; // r3
  idDeclFile *v11; // r28
  int v12; // r29
  int v13; // r30
  idDeclFile **list; // r11
  idFile *v15; // r3
  idDeclFile *v16; // r3
  idDecl *v17; // r27
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  va *v21; // r3
  const char *v22; // r3
  idDeclSource *v23; // r30
  int v24; // r29
  idDeclSource *i; // r11
  int v26; // r10
  idAtomicString *v27; // r3
  unsigned int v28; // r26
  int numLines; // r10
  int firstDeclSourceInFile; // r9
  int v31; // r8
  int v32; // r7
  int v33; // r6
  int v34; // r5
  int v35; // r11
  int v36; // [sp+8h] [-1148h]
  int v37; // [sp+8h] [-1148h]
  int v38; // [sp+Ch] [-1144h]
  int v39; // [sp+Ch] [-1144h]
  int v40; // [sp+10h] [-1140h]
  int v41; // [sp+10h] [-1140h]
  int v42; // [sp+14h] [-113Ch]
  int v43; // [sp+14h] [-113Ch]
  int v44; // [sp+18h] [-1138h]
  int v45; // [sp+18h] [-1138h]
  int v46; // [sp+1Ch] [-1134h]
  idDeclSource *v47; // [sp+1Ch] [-1134h]
  void *v48; // [sp+50h] [-1100h] BYREF
  idStr v49; // [sp+60h] [-10F0h] BYREF
  idStr v50; // [sp+80h] [-10D0h] BYREF
  idStr v51; // [sp+A0h] [-10B0h] BYREF
  idStr v52; // [sp+C0h] [-1090h] BYREF
  va v53; // [sp+E0h] [-1070h] BYREF

  if ( name == nullptr
    || (result = (idDecl *)idDeclInfo::FindWithInheritance(this: type, name, makeDefault: false)) == nullptr )
  {
    v11 = nullptr;
    if ( _fileName != nullptr && *_fileName != 0 )
    {
      idStr::idStr(this: &v50, text: _fileName);
      idStr::BackSlashesToSlashes(this: &v50);
      v12 = 0;
      if ( this->loadedFiles.num > 0 )
      {
        v13 = 0;
        do
        {
          if ( idStr::Icmp(s1: this->loadedFiles.list[v13]->fileName.str, s2: v50.data) == 0 )
            break;
          ++v12;
          ++v13;
        }
        while ( v12 < this->loadedFiles.num );
      }
      if ( v12 >= this->loadedFiles.num )
      {
        v16 = (idDeclFile *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x48u,
                              tag: TAG_DECL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        v48 = v16;
        if ( v16 != nullptr )
          v11 = idDeclFile::idDeclFile(this: v16, _fileName: v50.data, _defaultType: type);
        else
          v11 = nullptr;
        v48 = v11;
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->loadedFiles,
          obj: (const encounterGroupRole_t *)&v48);
        idMem::PopHeap(this: &mem);
      }
      else
      {
        list = this->loadedFiles.list;
        v11 = list[v12];
        if ( v11->timestamp != 0 )
        {
          if ( (unsigned __int8)idDeclFile::SourceFileChanged(this: list[v12], compareChecksums: true) != 0
            || (v15 = fileSystem->OpenFileReadWrite(this: fileSystem, a2: v50.data, a3: 0, a4: 0)) == nullptr )
          {
            idStr::FreeData(this: &v50);
            return nullptr;
          }
          ((void (__fastcall *)(idFile *, int))v15->dtr_idFile)(a1: v15, a2: 1);
        }
      }
      idStr::FreeData(this: &v50);
    }
    v17 = type->AllocDecl(this: type);
    idStr::idStr(this: &v52, text: name);
    idStr::MakeNameCanonical(this: &v52);
    HIDWORD(v18) = 20;
    LODWORD(v19) = v49.baseBuffer;
    v49.len = 0;
    v49.allocedAndFlag = 20;
    v49.data = v49.baseBuffer;
    v49.baseBuffer[0] = 0;
    HIDWORD(v19) = &unk_821C0000;
    HIDWORD(v20) = type->name;
    LODWORD(v20) = v52.data;
    v21 = va::va(
            this: &v53,
            fmt: "\n%s %s ",
            a3: v20,
            a4: v19,
            a5: v18,
            a6: v36,
            a7: v38,
            a8: v40,
            a9: v42,
            a10: v44,
            a11: v46);
    idStr::operator=(this: &v49, text: v21);
    idStr::idStr(this: &v51, text: declText);
    if ( v51.len == 0 )
    {
      v22 = v17->DefaultDefinition(this: v17);
      idStr::operator=(this: &v51, text: v22);
    }
    v23 = nullptr;
    if ( v11 != nullptr )
    {
      v24 = v11->fileSize + v49.len;
      for ( i = v11->firstDeclSourceInFile; i != nullptr; i = i->nextInFile )
      {
        v26 = i->sourceTextLength + i->sourceTextOffset;
        if ( v26 > v24 )
          v24 = v26 + v49.len;
      }
      v27 = (idAtomicString *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x1Cu,
                                tag: TAG_DECL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
      v23 = (idDeclSource *)v27;
      v48 = v27;
      if ( v27 != nullptr )
      {
        v28 = (unsigned int)this->dependenciesDynamicStartIndex >> 31;
        v27->str = &byte_8200D768;
        idAtomicString::Set(this: v27, str_: "emptyDeclSource");
        v23->isStatic = v28;
        v23->sourceFile = nullptr;
        v23->nextInFile = nullptr;
        v23->sourceTextOffset = 0;
        v23->sourceTextLength = 0;
        v23->sourceLine = 0;
      }
      else
      {
        v23 = nullptr;
      }
      idAtomicString::Set(this: &v23->name, str_: v52.data);
      v23->sourceFile = v11;
      v23->sourceTextOffset = v24;
      v23->sourceTextLength = v51.len;
      numLines = v11->numLines;
      v23->sourceLine = numLines;
      firstDeclSourceInFile = (int)v11->firstDeclSourceInFile;
      v23->nextInFile = (idDeclSource *)firstDeclSourceInFile;
      v11->firstDeclSourceInFile = v23;
      idDeclInfo::AddDeclSource(
        this: type,
        ds: v23,
        a3: v34,
        a4: v33,
        a5: v32,
        a6: v31,
        a7: firstDeclSourceInFile,
        a8: numLines,
        a9: v37,
        a10: v39,
        a11: v41,
        a12: v43,
        a13: v45,
        a14: v47);
    }
    idResource::SetName(this: v17, _name: v52.data);
    idDecl::SetText(this: v17, text: v51.data, length: 0);
    v17->declSource = v23;
    idDecl::ReParse(this: v17, fromDisk: false);
    if ( v51.data != nullptr )
    {
      v35 = 0;
      if ( *v51.data != 0 )
      {
        do
          ++v35;
        while ( v51.data[v35] != 0 );
        if ( v35 > 0 )
          v17->programaticallyDefined = true;
      }
    }
    idResourceList::Add(this: type, ptr: v17);
    idStr::FreeData(this: &v51);
    idStr::FreeData(this: &v49);
    idStr::FreeData(this: &v52);
    return v17;
  }
  return result;
}


// ========================================================================
// __unwind$226731
// EA  : 0x82628288
// RVA : 0x00628288
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226731()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 128));
}


// ========================================================================
// __unwind$226732
// EA  : 0x826282B0
// RVA : 0x006282B0
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226732()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4432 + 80), tag: TAG_DECL);
}


// ========================================================================
// __unwind$226733
// EA  : 0x826282DC
// RVA : 0x006282DC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226733()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 192));
}


// ========================================================================
// __unwind$226734
// EA  : 0x82628304
// RVA : 0x00628304
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226734()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 96));
}


// ========================================================================
// __unwind$226735
// EA  : 0x8262832C
// RVA : 0x0062832C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226735()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 160));
}


// ========================================================================
// __unwind$226736
// EA  : 0x82628354
// RVA : 0x00628354
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_226736()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4432 + 80), tag: TAG_DECL);
}


// ========================================================================
// ?ReloadDecls_f@idDeclManagerLocal@@SAXABVidCmdArgs@@@Z
// EA  : 0x82628380
// RVA : 0x00628380
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::ReloadDecls_f(const idCmdArgs *args)
{
  const char *v1; // r3
  bool v2; // r31
  idGame *v3; // r3

  if ( args->argc <= 1 )
    v1 = &byte_8200D768;
  else
    v1 = args->argv[1];
  if ( idStr::Icmp(s1: v1, s2: "all") != 0 )
  {
    v2 = false;
    idLib::Printf(fmt: "reloading changed decl files:\n");
  }
  else
  {
    v2 = true;
    idLib::Printf(fmt: "reloading all decl files:\n");
  }
  ++idResourceList::staleCount;
  idDeclManagerLocal::Reload(this: &declManagerLocal, force: v2);
  if ( common != nullptr && common->Game(this: common) != nullptr )
  {
    v3 = common->Game(this: common);
    v3->OnReloadDecls(this: v3);
  }
}


// ========================================================================
// ?Init@idDeclManagerLocal@@UAAXXZ
// EA  : 0x82628538
// RVA : 0x00628538
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::Init(idDeclManagerLocal *this)
{
  idResourceList *i; // r28
  void *v3; // r29
  int v4; // r3
  idDeclManagerLocal_vtbl *v5; // r5
  int v6; // r30
  int v7; // r27
  idDeclInfo **v8; // r28
  const char *v9; // r5
  idFileList *v10; // r27
  int v11; // r26
  int v12; // r28
  idDeclManagerLocal_vtbl *v13; // r22
  char *data; // r21
  idDeclInfo *v15; // r3
  int v16; // r28
  int v17; // r11
  int num; // r27
  idDeclInfo *v19; // r10
  int v20; // r3
  int v21; // r6
  int v22; // r5
  int v23; // r4
  int v24; // r3
  const char *v25; // [sp+50h] [-230h] BYREF
  int v26; // [sp+54h] [-22Ch]
  _DWORD v27[73]; // [sp+5Ch] [-224h] BYREF
  idStr v28; // [sp+180h] [-100h] BYREF
  idStr v29; // [sp+1A0h] [-E0h] BYREF
  idStr v30[6]; // [sp+1C0h] [-C0h] BYREF

  idLib::Printf(fmt: "----- Initializing Decls -----\n");
  this->checksum = 0;
  for ( i = listOfResourceLists; i != nullptr; i = i->nextResourceList )
  {
    v3 = _RTDynamicCast(
           inptr: i,
           VfDelta: 0,
           SrcType: &idResourceList `RTTI Type Descriptor',
           TargetType: &idDeclInfo `RTTI Type Descriptor',
           isReference: 0);
    v25 = (const char *)v3;
    if ( v3 != nullptr )
    {
      if ( this->GetDeclType(this, a2: *((_DWORD *)v3 + 261)) != nullptr )
      {
        idLib::Error(
          fmt: "idDeclManagerLocal::RegisterDeclType '%s' type already registered\n",
          *((const char **)v3 + 261));
        _LN106_0(a1: v24, a2: v23, a3: v22, a4: v21);
        return;
      }
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->declTypes,
        obj: (const encounterGroupRole_t *)&v25);
    }
  }
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listDecls",
    a3: idDeclManagerLocal::ListDecls_f,
    a4: "lists all decls",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "reloadDecls",
    a3: idDeclManagerLocal::ReloadDecls_f,
    a4: "reloads decl files that have changed",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "touchDecl",
    a3: idDeclManagerLocal::TouchDecl_f,
    a4: "reparses a decl",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "reexportDecls",
    a3: idDeclManagerLocal::ReExportDecls_f,
    a4: "reparses and saves decls of a specific type",
    a5: idDeclManager::ArgCompletion_DeclTypeAndName);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "buildRenderProgs",
    a3: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
    a4: &byte_8200D768,
    a5: nullptr);
  idAtomicString::Set(this: &idDeclMD6::resourceList.nameExtension, str_: ".md6");
  idSoundShader::resourceList.onReload = OnReloadSound;
  v4 = Sys_Milliseconds();
  v5 = this->__vftable;
  v26 = v4;
  v5->RegisterDeclFolder(this, a2: "generated/skins/m2", a3: ".m2", a4: nullptr);
  v27[2] = ".m2";
  v27[5] = ".m2";
  v27[1] = "m2";
  v27[4] = "m2_terrain";
  v27[7] = "renderprogs";
  v27[8] = ".mrpr";
  v27[3] = &idMaterial::resourceList;
  v27[6] = 0;
  v27[9] = 0;
  v25 = "animwebs";
  v27[10] = "skins";
  v6 = 0;
  v27[14] = ".md6merge";
  v27[11] = -2112105860;
  v27[13] = "md6def";
  v27[16] = "md6def";
  v27[15] = 0;
  v27[17] = ".md6def";
  v27[18] = 0;
  v27[19] = "af";
  v27[24] = 0;
  v27[12] = 0;
  v27[21] = 0;
  v27[30] = 0;
  v27[33] = 0;
  v27[22] = "ik";
  v27[20] = ".af";
  v27[35] = ".vo";
  v27[28] = "rollbones";
  v27[29] = ".rollbones";
  v27[34] = "voiceover";
  v27[25] = "reachik";
  v27[26] = ".reachik";
  v27[27] = 0;
  v27[23] = ".walkik";
  v27[31] = "sound";
  v27[32] = ".sndshd";
  v27[49] = "ribbons";
  v27[46] = "effects";
  v27[47] = ".break";
  v27[50] = ".ribbon";
  v27[36] = 0;
  v27[52] = "flares";
  v27[37] = "animwebs";
  v27[38] = ".aweb";
  v27[39] = 0;
  v27[40] = "visemes";
  v27[41] = ".vset";
  v27[42] = 0;
  v27[43] = "env";
  v27[44] = ".env";
  v27[45] = 0;
  v27[48] = 0;
  v27[53] = ".flare";
  v27[55] = "foliage";
  v27[51] = 0;
  v27[54] = 0;
  v27[56] = ".foliage";
  v27[57] = 0;
  v27[58] = "detail";
  v27[59] = ".detail";
  v27[60] = 0;
  v27[61] = "ebolts";
  v27[62] = ".ebolt";
  v27[63] = 0;
  v27[64] = "vehicleProps";
  v27[65] = ".vehicle";
  v27[66] = 0;
  v27[67] = "presentable";
  v27[68] = ".present";
  v27[69] = 0;
  v27[70] = "presentable";
  v27[71] = ".actor";
  v27[72] = 0;
  idStr::idStr(this: v30, text: "particle");
  idList<idStr,5>::Append(this: &this->registeredDeclLogTypes, obj: v30);
  idStr::FreeData(this: v30);
  v7 = 24;
  v8 = (idDeclInfo **)v27;
  do
  {
    v28.allocedAndFlag = 20;
    v28.len = 0;
    v28.data = v28.baseBuffer;
    v28.baseBuffer[0] = 0;
    idStr::Format(this: &v28, fmt: "decls/%s", (const char *)v8[1]);
    v9 = (const char *)v8[2];
    v8 += 3;
    this->RegisterDeclFolder(this, a2: v28.data, a3: v9, a4: *v8);
    idStr::FreeData(this: &v28);
    --v7;
  }
  while ( v7 != 0 );
  v10 = fileSystem->ListFiles(this: fileSystem, a2: "declTree", a3: "/", a4: 0, a5: 0);
  v11 = 0;
  if ( v10->list.num > 0 )
  {
    v12 = 0;
    do
    {
      idStr::idStr(this: &v29, text: "declTree/");
      idStr::AppendPath(this: &v29, text: v10->list.list[v12].data);
      v13 = this->__vftable;
      data = v29.data;
      v15 = this->GetDeclType(this, a2: v10->list.list[v12].data);
      v13->RegisterDeclFolder(this, a2: data, a3: "decl", a4: v15);
      idStr::FreeData(this: &v29);
      ++v11;
      ++v12;
    }
    while ( v11 < v10->list.num );
  }
  fileSystem->FreeFileList(this: fileSystem, a2: v10);
  v16 = 0;
  v17 = 0;
  num = this->declTypes.num;
  if ( num > 0 )
  {
    do
    {
      v19 = this->declTypes.list[v6];
      ++v17;
      ++v6;
      v16 += v19->declSources.num;
    }
    while ( v17 < num );
  }
  v25 = (const char *)this->declTypes.num;
  v20 = Sys_Milliseconds();
  idLib::Printf(fmt: "%i types, %i declSource in %d ms\n", num, v16, v20 - v26);
  idLib::Printf(fmt: "------------------------------\n");
}


// ========================================================================
// $LN106_0
// EA  : 0x82628BF4
// RVA : 0x00628BF4
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _LN106_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 448));
}


// ========================================================================
// __unwind$227051
// EA  : 0x82628C1C
// RVA : 0x00628C1C
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_227051()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 384));
}


// ========================================================================
// __unwind$227052
// EA  : 0x82628C44
// RVA : 0x00628C44
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_227052()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 640 + 416));
}


// ========================================================================
// ?FreeDynamic@idDeclManagerLocal@@UAAXXZ
// EA  : 0x82628C78
// RVA : 0x00628C78
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::FreeDynamic(idDeclManagerLocal *this)
{
  int v2; // r29
  int v3; // r30
  int v4; // r29
  int v5; // r30
  int loadedFilesDynamicStartIndex; // r23
  int v7; // r24
  idStr *list; // r27
  int size; // r29
  idStr *v10; // r28
  int *v11; // r4
  int num; // r10
  int i; // r11
  unsigned int v14; // r10
  int v15; // r8
  int v16; // r30
  int v17; // r11
  unsigned int dependenciesDynamicStartIndex; // r10
  int v19; // r8
  int v20; // r30
  int v21; // r11
  idDeclFile *v22; // [sp+50h] [-60h]

  v2 = 0;
  if ( this->loadedFiles.num > 0 )
  {
    v3 = 0;
    do
    {
      idDeclFile::FreeDynamic(this: this->loadedFiles.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->loadedFiles.num );
  }
  v4 = 0;
  if ( this->declTypes.num > 0 )
  {
    v5 = 0;
    do
    {
      idDeclInfo::FreeDynamic(this: this->declTypes.list[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < this->declTypes.num );
  }
  loadedFilesDynamicStartIndex = this->loadedFilesDynamicStartIndex;
  if ( loadedFilesDynamicStartIndex < this->loadedFiles.num )
  {
    v7 = loadedFilesDynamicStartIndex;
    do
    {
      v22 = this->loadedFiles.list[v7];
      if ( v22 != nullptr )
      {
        if ( v22->includeFiles.listStatic == 0 || v22->includeFiles.listStatic == 2 )
        {
          list = v22->includeFiles.list;
          if ( list != nullptr )
          {
            size = v22->includeFiles.size;
            if ( size > 0 )
            {
              v10 = v22->includeFiles.list;
              do
              {
                idStr::FreeData(this: v10);
                --size;
                ++v10;
              }
              while ( size != 0 );
            }
            idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
          }
          v22->includeFiles.list = nullptr;
          v22->includeFiles.size = 0;
        }
        v22->includeFiles.num = 0;
        if ( v22->dependencies.listStatic == 0 || v22->dependencies.listStatic == 2 )
        {
          v11 = v22->dependencies.list;
          if ( v11 != nullptr )
            idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
          v22->dependencies.list = nullptr;
          v22->dependencies.size = 0;
        }
        v22->dependencies.num = 0;
        idMem::Free(this: &mem, ptr: v22, align: ALIGN_16);
      }
      ++loadedFilesDynamicStartIndex;
      this->loadedFiles.list[v7++] = nullptr;
    }
    while ( loadedFilesDynamicStartIndex < this->loadedFiles.num );
  }
  num = this->declFileDependencies.num;
  for ( i = this->dependenciesDynamicStartIndex; i < num; ++i )
    ;
  v14 = this->loadedFilesDynamicStartIndex;
  v15 = (v14 >> 31) - 1;
  v16 = v15 & v14;
  if ( (signed int)(v15 & v14) <= this->loadedFiles.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->loadedFiles,
         newsize: v15 & v14) )
  {
    v17 = this->loadedFiles.size;
    if ( v16 < v17 )
      v17 = v16;
    this->loadedFiles.num = v17;
  }
  dependenciesDynamicStartIndex = this->dependenciesDynamicStartIndex;
  v19 = (dependenciesDynamicStartIndex >> 31) - 1;
  v20 = v19 & dependenciesDynamicStartIndex;
  if ( (signed int)(v19 & dependenciesDynamicStartIndex) <= this->declFileDependencies.size
    || (unsigned __int8)idList<declFileDependency_t,46>::Resize(
                          this: &this->declFileDependencies,
                          newsize: v19 & dependenciesDynamicStartIndex) != 0 )
  {
    v21 = this->declFileDependencies.size;
    if ( v20 < v21 )
      v21 = v20;
    this->declFileDependencies.num = v21;
  }
}


// ========================================================================
// __unwind$227258
// EA  : 0x82628EAC
// RVA : 0x00628EAC
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void _unwind_227258()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 80) + 36));
}


// ========================================================================
// ?AddDependency@idDeclManagerLocal@@UAAXPAVidDecl@@PBD@Z
// EA  : 0x82628F68
// RVA : 0x00628F68
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __fastcall idDeclManagerLocal::AddDependency(idDeclManagerLocal *this, idDecl *decl, const char *fileName)
{
  idDeclSource *declSource; // r11
  idDeclFile *sourceFile; // r27
  int v7; // r30
  int v8; // r31
  declFileDependency_t *v9; // r31
  int num; // [sp+50h] [-40h] BYREF

  if ( idLib::production != PROD_PRODUCTION && decl != nullptr )
  {
    declSource = decl->declSource;
    if ( declSource != nullptr )
    {
      sourceFile = declSource->sourceFile;
      if ( sourceFile != nullptr && idStr::Icmp(s1: sourceFile->fileName.str, s2: fileName) != 0 )
      {
        v7 = 0;
        if ( this->declFileDependencies.num <= 0 )
          goto LABEL_12;
        v8 = 0;
        while ( idStr::IcmpPath(s1: this->declFileDependencies.list[v8].fileName.str, s2: fileName) != 0 )
        {
          ++v7;
          ++v8;
          if ( v7 >= this->declFileDependencies.num )
            goto LABEL_12;
        }
        num = v7;
        if ( v7 == -1 )
        {
LABEL_12:
          num = this->declFileDependencies.num;
          v9 = idList<declFileDependency_t,46>::Alloc(this: &this->declFileDependencies);
          idAtomicString::Set(this: &v9->fileName, str_: fileName);
          v9->timestamp = fileSystem->GetTimestamp(this: fileSystem, a2: fileName, a3: false);
        }
        idList<int,46>::AddUnique(
          this: (idList<int,5> *)&sourceFile->dependencies,
          obj: (const encounterGroupRole_t *)&num);
      }
    }
  }
}


// ========================================================================
// `dynamic initializer for 'declManagerLocal''
// EA  : 0x83337228
// RVA : 0x01337228
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__declManagerLocal__()
{
  idDeclManagerLocal::idDeclManagerLocal(this: &declManagerLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__declManagerLocal__);
}


// ========================================================================
// `dynamic initializer for 'com_writeMissingDeclFiles''
// EA  : 0x83337260
// RVA : 0x01337260
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_writeMissingDeclFiles__()
{
  idCVar::idCVar(
    this: &com_writeMissingDeclFiles,
    name: "com_writeMissingDeclFiles",
    value: &byte_8200D768,
    flags: 0,
    description: "write out any missing decls for a specific decl type, using the default decl (hit tab to display supported decl types)",
    valueCompletion: (const char **)ShowAvailableDeclLogs);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_writeMissingDeclFiles__);
}


// ========================================================================
// `dynamic initializer for 'makeDeclTree''
// EA  : 0x833372B8
// RVA : 0x013372B8
// PDB : w:\tech5\engine\decls\declmanager.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__makeDeclTree__()
{
  return idCommandLink::idCommandLink(
           this: &makeDeclTree,
           cmdName: "makeDeclTree",
           function: idDeclManagerLocal::MakeDeclTree_f,
           description: "Generates declTree",
           argCompletion: nullptr);
}

