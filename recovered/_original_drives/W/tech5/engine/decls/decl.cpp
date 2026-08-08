
// ========================================================================
// ??0idDecl@@QAA@XZ
// EA  : 0x8260AB70
// RVA : 0x0060AB70
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

idDecl *__fastcall idDecl::idDecl(idDecl *this)
{
  idResource::idResource(this);
  this->textSource = nullptr;
  this->__vftable = (idDecl_vtbl *)&idDecl::`vftable';
  this->textLength = 0;
  this->md5Checksum = 0;
  this->programaticallyDefined = false;
  this->declSource = nullptr;
  return this;
}


// ========================================================================
// ??1idDecl@@UAA@XZ
// EA  : 0x8260ABD0
// RVA : 0x0060ABD0
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::~idDecl(idDecl *this)
{
  char *textSource; // r4

  this->__vftable = (idDecl_vtbl *)&idDecl::`vftable';
  textSource = this->textSource;
  if ( textSource != nullptr )
  {
    idMem::Free(this: &mem, ptr: textSource, align: ALIGN_16);
    this->textSource = nullptr;
  }
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$220647
// EA  : 0x8260AC40
// RVA : 0x0060AC40
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_220647()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetLineNum@idDecl@@QBAHXZ
// EA  : 0x8260AC68
// RVA : 0x0060AC68
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

int __fastcall idDecl::GetLineNum(idDecl *this)
{
  idDeclSource *declSource; // r11
  int result; // r3

  declSource = this->declSource;
  result = 0;
  if ( declSource != nullptr )
    return declSource->sourceLine;
  return result;
}


// ========================================================================
// ?Size@idDecl@@UBAIXZ
// EA  : 0x8260AC80
// RVA : 0x0060AC80
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

int __fastcall idDecl::Size(idDecl *this)
{
  return this->textLength + 56;
}


// ========================================================================
// ?SourceFileExists@idDecl@@QBA_NXZ
// EA  : 0x8260AC90
// RVA : 0x0060AC90
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

int __fastcall idDecl::SourceFileExists(idDecl *this)
{
  idDeclSource *declSource; // r11
  idDeclFile *sourceFile; // r11
  int result; // r3

  declSource = this->declSource;
  if ( declSource == nullptr )
    return 0;
  sourceFile = declSource->sourceFile;
  if ( sourceFile == nullptr )
    return 0;
  result = 1;
  if ( sourceFile->fileSize <= 0 )
    return 0;
  return result;
}


// ========================================================================
// ?EverReloaded@idDecl@@QBA_NXZ
// EA  : 0x8260ACC0
// RVA : 0x0060ACC0
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

BOOL __fastcall idDecl::EverReloaded(idDecl *this)
{
  return this->declSource->sourceFile->everReloaded;
}


// ========================================================================
// ?IsImplicit@idDecl@@QBA_NXZ
// EA  : 0x8260ACF0
// RVA : 0x0060ACF0
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

BOOL __fastcall idDecl::IsImplicit(idDecl *this)
{
  return idLib::production < PROD_PRODUCTION
      && !this->programaticallyDefined
      && strstr(str1: this->name.str, str2: ".decl") == nullptr
      && (_cntlzw((unsigned int)this->declSource) & 0x20) != 0;
}


// ========================================================================
// ?GetFileName@idDecl@@QBAPBDXZ
// EA  : 0x8260AD70
// RVA : 0x0060AD70
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

const char *__fastcall idDecl::GetFileName(idDecl *this)
{
  idDeclSource *declSource; // r11
  idDeclFile *sourceFile; // r11

  declSource = this->declSource;
  if ( declSource != nullptr && (sourceFile = declSource->sourceFile) != nullptr )
    return sourceFile->fileName.str;
  else
    return this->name.str;
}


// ========================================================================
// ?SetText@idDecl@@QAAXPBDH@Z
// EA  : 0x8260AD98
// RVA : 0x0060AD98
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::SetText(idDecl *this, const char *text, int length)
{
  char *textSource; // r4
  int v7; // r11
  int textLength; // r8
  int v9; // r9
  int i; // r11
  int v11; // r10
  char *v12; // r3

  textSource = this->textSource;
  if ( textSource != nullptr )
    idMem::Free(this: &mem, ptr: textSource, align: ALIGN_16);
  if ( text != nullptr )
  {
    if ( length != 0 )
    {
      this->textLength = length;
    }
    else
    {
      v7 = 0;
      if ( *text != 0 )
      {
        do
          ++v7;
        while ( text[v7] != 0 );
      }
      this->textLength = v7;
    }
    textLength = this->textLength;
    v9 = 0;
    for ( i = textLength - 1; i >= 0; ++v9 )
    {
      v11 = text[i];
      if ( v11 != 10 && v11 != 13 && v11 != 32 )
        break;
      --i;
    }
    this->textLength = textLength - v9;
    v12 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\engine\\decls\\Decl.cpp(339) : TAG_DECLTEXT",
                    size: textLength - v9 + 1,
                    tag: TAG_DECLTEXT,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    this->textSource = v12;
    memcpy(Dst: v12, Src: text, Size: this->textLength);
    this->textSource[this->textLength] = 0;
    this->md5Checksum = MD5_BlockChecksum(data: text, length: this->textLength);
  }
  else
  {
    this->textSource = nullptr;
    this->textLength = 0;
    this->md5Checksum = 0;
  }
}


// ========================================================================
// ?MakeDefault@idDecl@@QAAXXZ
// EA  : 0x8260AEC8
// RVA : 0x0060AEC8
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::MakeDefault(idDecl *this)
{
  const char *str; // r29
  idDeclInfo *v3; // r3
  const char *v4; // r3
  int textLength; // r29
  idDeclInfo *v6; // r3
  idDecl *v7; // r3
  const char *v8; // r30
  idDeclInfo *(__fastcall *GetDeclInfo)(idDecl *); // ctr
  int v10; // r3
  idParser v11; // [sp+50h] [-2B0h] BYREF

  this->FreeData(this);
  str = this->name.str;
  v3 = this->GetDeclInfo(this);
  this->declSource = idDeclInfo::FindDeclSource(this: v3, name: str);
  v4 = this->DefaultDefinition(this);
  idDecl::SetText(this, text: v4, length: 0);
  idParser::idParser(this: &v11, flags: 0);
  textLength = this->textLength;
  if ( textLength == 0 )
    idDecl::Revert(this);
  idParser::LoadMemory(this: &v11, ptr: this->textSource, length: textLength, name: "_defaultFile");
  idParser::SetFlags(this: &v11, flags: 156216);
  idParser::SkipUntilString(this: &v11, string: "{");
  this->Parse(this, a2: &v11);
  if ( idParser::HadError(this: &v11) || idParser::HadWarning(this: &v11) )
  {
    v7 = this;
    GetDeclInfo = this->GetDeclInfo;
    v8 = this->name.str;
    v10 = (int)GetDeclInfo(this: v7);
    idLib::FatalError(fmt: "Parse of defaulted %s decl %s failed", *(const char **)(v10 + 1044), v8);
    _LN65();
  }
  else
  {
    if ( this->resourceError == nullptr )
    {
      v6 = this->GetDeclInfo(this);
      idResource::SetResourceError(this, fmt: "defaulted '%s'", v6->name);
    }
    idParser::~idParser(this: &v11);
  }
}


// ========================================================================
// $LN65
// EA  : 0x8260B044
// RVA : 0x0060B044
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _LN65()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 768 + 80));
}


// ========================================================================
// ?List@idDecl@@UBAXXZ
// EA  : 0x8260B070
// RVA : 0x0060B070
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::List(idDecl *this)
{
  idDeclSource *declSource; // r11
  int sourceLine; // r6
  idDeclFile *sourceFile; // r11
  const char *str; // r5

  declSource = this->declSource;
  sourceLine = 0;
  if ( declSource != nullptr && (sourceLine = declSource->sourceLine, (sourceFile = declSource->sourceFile) != nullptr) )
    str = sourceFile->fileName.str;
  else
    str = this->name.str;
  idLib::Printf(fmt: "%s %s %i\n", this->name.str, str, sourceLine);
}


// ========================================================================
// ?Revert@idDecl@@QAAXXZ
// EA  : 0x8260B0B0
// RVA : 0x0060B0B0
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::Revert(idDecl *this)
{
  idDeclSource *declSource; // r10
  idDeclFile *sourceFile; // r3
  char *textSource; // r4

  declSource = this->declSource;
  if ( declSource != nullptr )
  {
    if ( idLib::production == PROD_DEVELOPMENT
      && (sourceFile = declSource->sourceFile) != nullptr
      && sourceFile->fileSize > 0
      && idDeclFile::SourceFileChanged(this: sourceFile, compareChecksums: false) )
    {
      declManager->Reload(this: declManager, a2: false);
    }
    else
    {
      textSource = this->textSource;
      if ( textSource != nullptr )
        idMem::Free(this: &mem, ptr: textSource, align: ALIGN_16);
      this->textSource = nullptr;
      this->textLength = 0;
      this->md5Checksum = 0;
      idDecl::ReParse(this, fromDisk: true);
    }
  }
  else
  {
    idDecl::MakeDefault(this);
  }
}


// ========================================================================
// ?DefineFromSource@idDecl@@AAAXPAVidDeclSource@@@Z
// EA  : 0x8260B190
// RVA : 0x0060B190
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::DefineFromSource(idDecl *this, idDeclSource *ds)
{
  char *textSource; // r4

  textSource = this->textSource;
  if ( textSource != nullptr )
    idMem::Free(this: &mem, ptr: textSource, align: ALIGN_16);
  this->declSource = ds;
  this->textSource = nullptr;
  this->textLength = 0;
  this->md5Checksum = 0;
}


// ========================================================================
// ?DeleteUnusedText@idDecl@@AAAXXZ
// EA  : 0x8260B1F8
// RVA : 0x0060B1F8
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::DeleteUnusedText(idDecl *this)
{
  char *textSource; // r4

  if ( _RTDynamicCast(
         inptr: this,
         VfDelta: 0,
         SrcType: &idDecl `RTTI Type Descriptor',
         TargetType: (void *)&idDeclEntityDef `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    textSource = this->textSource;
    if ( textSource != nullptr )
      idMem::Free(this: &mem, ptr: textSource, align: ALIGN_16);
    this->textSource = nullptr;
    this->textLength = 0;
    this->md5Checksum = 0;
  }
}


// ========================================================================
// ProductionFilename
// EA  : 0x8260B278
// RVA : 0x0060B278
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

idStr *__fastcall ProductionFilename(idStr *result, idDecl *r)
{
  const char *str; // r29
  const char *ResourceTypeName; // r3

  result->data = result->baseBuffer;
  result->allocedAndFlag = 20;
  result->len = 0;
  result->baseBuffer[0] = 0;
  str = r->name.str;
  ResourceTypeName = idResource::GetResourceTypeName(this: r);
  idStr::Format(this: result, fmt: "generated/decls/%s/%s.decl", ResourceTypeName, str);
  return result;
}


// ========================================================================
// __unwind$221653
// EA  : 0x8260B2E8
// RVA : 0x0060B2E8
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_221653()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ?ReloadIfStale@idDecl@@UAA_NXZ
// EA  : 0x8260B330
// RVA : 0x0060B330
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

int __fastcall idDecl::ReloadIfStale(idDecl *this)
{
  idDeclSource *declSource; // r11
  idDeclFile *sourceFile; // r31
  void (__fastcall *onReload)(const idDecl *); // r11

  declSource = this->declSource;
  if ( declSource == nullptr )
    return 0;
  sourceFile = declSource->sourceFile;
  if ( sourceFile == nullptr )
    return 0;
  if ( idLib::production != PROD_DEVELOPMENT
    || sourceFile->fileSize <= 0
    || !idDeclFile::SourceFileChanged(this: sourceFile, compareChecksums: false) )
  {
    return 0;
  }
  idDeclFile::LoadAndParse(this: sourceFile);
  onReload = this->GetDeclInfo(this)->onReload;
  if ( onReload != nullptr )
    onReload(a1: this);
  return 1;
}


// ========================================================================
// ?GetDeclTimestamp@idDecl@@UBAIXZ
// EA  : 0x8260B400
// RVA : 0x0060B400
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

unsigned int __fastcall idDecl::GetDeclTimestamp(idDecl *this)
{
  idDeclSource *declSource; // r11
  idDeclFile *sourceFile; // r11
  const char *str; // r4

  if ( idDecl::IsImplicit(this) || idLib::production == PROD_PRODUCTION )
    return -1;
  declSource = this->declSource;
  if ( declSource != nullptr && (sourceFile = declSource->sourceFile) != nullptr )
    str = sourceFile->fileName.str;
  else
    str = this->name.str;
  return fileSystem->GetTimestamp(this: fileSystem, a2: str, a3: false);
}


// ========================================================================
// ?GetText@idDecl@@QAAPBDXZ
// EA  : 0x8260B4A0
// RVA : 0x0060B4A0
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

char *__fastcall idDecl::GetText(idDecl *this)
{
  if ( this->textLength == 0 )
    idDecl::Revert(this);
  return this->textSource;
}


// ========================================================================
// ?ReplaceSourceFileText@idDecl@@QAA_N_N@Z
// EA  : 0x8260B790
// RVA : 0x0060B790
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

int __fastcall idDecl::ReplaceSourceFileText(idDecl *this, bool useSourceControl)
{
  idFile *v4; // r29
  int textLength; // r28
  idDeclSource *declSource; // r11
  idDeclFile *sourceFile; // r11
  const char *str; // r10
  const char *v10; // r4
  idDeclSource *v11; // r11
  idDeclFile *v12; // r11
  const char *v13; // r4
  idDeclSource *v14; // r11
  idDeclFile *v15; // r26
  signed int fileSize; // r29
  signed int sourceTextOffset; // r6
  BOOL v18; // r24
  const char *v19; // r28
  idDeclInfo *v20; // r3
  int v21; // r11
  unsigned int v22; // r27
  unsigned int v23; // r4
  char *buffer; // r25
  idDeclSource *v25; // r11
  idDeclFile *v26; // r11
  const char *v27; // r4
  idFile *v28; // r3
  idFile *v29; // r28
  idDeclSource *v30; // r11
  idDeclFile *v31; // r11
  const char *v32; // r4
  idDeclSource *v33; // r11
  idDeclFile *v34; // r11
  const char *v35; // r4
  idDeclSource *v36; // r11
  idDeclFile *v37; // r11
  const char *v38; // r4
  idDeclSource *v39; // r11
  idDeclFile *v40; // r11
  const char *v41; // r4
  idDeclSource *v42; // r8
  idDeclSource *v43; // r11
  idDeclFile *v44; // r11
  const char *v45; // r4
  idFile *v46; // r3
  idFile *v47; // r29
  idDeclSource *v48; // r11
  idDeclFile *v49; // r11
  const char *v50; // r4
  idDeclSource *v51; // r11
  idDeclFile *v52; // r11
  const char *v53; // r4
  unsigned int v54; // r3
  idDeclSource *firstDeclSourceInFile; // r11
  idDeclSource *v56; // r9
  int v57; // r10
  idDeclSource *v58; // r11
  idDeclFile *v59; // r11
  const char *v60; // r4
  idStr v61; // [sp+50h] [-1F0h] BYREF
  idTempArray<char> v62; // [sp+70h] [-1D0h] BYREF
  idStr v63; // [sp+80h] [-1C0h] BYREF
  idStr v64; // [sp+A0h] [-1A0h] BYREF
  idStr v65; // [sp+C0h] [-180h] BYREF
  char v66[352]; // [sp+E0h] [-160h] BYREF

  if ( strstr(str1: this->name.str, str2: ".decl") == nullptr )
  {
    declSource = this->declSource;
    if ( declSource == nullptr )
    {
      idLib::Warning(fmt: "Can't save decl %s without a declSource.", this->name.str);
      return 0;
    }
    sourceFile = declSource->sourceFile;
    if ( sourceFile != nullptr )
      str = sourceFile->fileName.str;
    else
      str = this->name.str;
    if ( str == nullptr )
    {
      idLib::Warning(fmt: "Decl %s has an invalid sourceFile name.", this->name.str);
      return 0;
    }
    if ( sourceFile != nullptr )
      v10 = sourceFile->fileName.str;
    else
      v10 = this->name.str;
    idStr::idStr(this: &v63, text: v10);
    if ( idLib::sourceControl != nullptr && useSourceControl && v63.len != 0 )
    {
      v11 = this->declSource;
      if ( v11 != nullptr && (v12 = v11->sourceFile) != nullptr )
        v13 = v12->fileName.str;
      else
        v13 = this->name.str;
      fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v13, a3: v66, a4: 256, a5: FSPATH_BASE);
      idStr::idStr(this: &v65, text: v66);
      idSourceControl::CheckOut(this: idLib::sourceControl, file: &v65);
      idStr::FreeData(this: &v65);
    }
    v14 = this->declSource;
    v15 = v14->sourceFile;
    fileSize = v15->fileSize;
    v61.allocedAndFlag = 20;
    v61.data = v61.baseBuffer;
    v61.len = 0;
    v61.baseBuffer[0] = 0;
    sourceTextOffset = v14->sourceTextOffset;
    v18 = sourceTextOffset >= fileSize;
    if ( sourceTextOffset < fileSize )
    {
      v21 = this->textLength - v14->sourceTextLength;
    }
    else
    {
      v19 = this->name.str;
      v20 = (idDeclInfo *)((int (__fastcall *)(idDecl *, int))this->GetDeclInfo)(
                            a1: this,
                            a2: sourceTextOffset - fileSize);
      idDeclManagerLocal::GetDeclTextHeader(type: v20, canonicalName: v19, header: &v61);
      v21 = this->textLength + v61.len;
    }
    v22 = v21 + fileSize;
    v23 = v21 + fileSize;
    if ( v21 + fileSize <= fileSize )
      v23 = fileSize;
    idTempArray<char>::idTempArray<char>(this: &v62, num: v23);
    buffer = v62.buffer;
    memset(Dst: v62.buffer, Val: 0, Size: v62.num);
    if ( v15->fileSize != 0 )
    {
      v25 = this->declSource;
      if ( v25 != nullptr && (v26 = v25->sourceFile) != nullptr )
        v27 = v26->fileName.str;
      else
        v27 = this->name.str;
      v28 = fileSystem->OpenFileRead(this: fileSystem, a2: v27, a3: 1, a4: 0);
      v29 = v28;
      if ( v28 == nullptr )
      {
        v30 = this->declSource;
        if ( v30 != nullptr && (v31 = v30->sourceFile) != nullptr )
          v32 = v31->fileName.str;
        else
          v32 = this->name.str;
        idLib::Warning(fmt: "Couldn't open %s for reading.", v32);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        goto LABEL_81;
      }
      if ( (int)v28->Length(this: v28) != v15->fileSize )
      {
        v33 = this->declSource;
        if ( v33 != nullptr && (v34 = v33->sourceFile) != nullptr )
          v35 = v34->fileName.str;
        else
          v35 = this->name.str;
        idLib::Warning(fmt: "The file %s has been modified outside of the engine.", v35);
        ((void (__fastcall *)(idFile *, int))v29->dtr_idFile)(a1: v29, a2: 1);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        goto LABEL_81;
      }
      if ( v29->Timestamp(this: v29) != v15->timestamp )
      {
        v36 = this->declSource;
        if ( v36 != nullptr && (v37 = v36->sourceFile) != nullptr )
          v38 = v37->fileName.str;
        else
          v38 = this->name.str;
        idLib::Warning(fmt: "The file %s has been modified outside of the engine.", v38);
        ((void (__fastcall *)(idFile *, int))v29->dtr_idFile)(a1: v29, a2: 1);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        goto LABEL_81;
      }
      v29->Read(this: v29, a2: buffer, a3: fileSize);
      ((void (__fastcall *)(idFile *, int))v29->dtr_idFile)(a1: v29, a2: 1);
      if ( MD5_BlockChecksum(data: buffer, length: fileSize) != v15->checksum )
      {
        v39 = this->declSource;
        if ( v39 != nullptr && (v40 = v39->sourceFile) != nullptr )
          v41 = v40->fileName.str;
        else
          v41 = this->name.str;
        idLib::Warning(fmt: "The file %s has been modified outside of the engine.", v41);
        if ( buffer != nullptr )
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        goto LABEL_81;
      }
    }
    if ( v18 )
    {
      memcpy(Dst: &buffer[fileSize], Src: v61.data, Size: v61.len);
    }
    else
    {
      v42 = this->declSource;
      memmove(
        Dst: &buffer[this->textLength + v42->sourceTextOffset],
        Src: &buffer[v42->sourceTextLength + v42->sourceTextOffset],
        Size: fileSize - v42->sourceTextLength - v42->sourceTextOffset);
    }
    memcpy(Dst: &buffer[this->declSource->sourceTextOffset], Src: this->textSource, Size: this->textLength);
    v43 = this->declSource;
    if ( v43 != nullptr && (v44 = v43->sourceFile) != nullptr )
      v45 = v44->fileName.str;
    else
      v45 = this->name.str;
    v46 = fileSystem->OpenFileWrite(this: fileSystem, a2: v45, a3: 0);
    v47 = v46;
    if ( v46 != nullptr )
    {
      v46->Write(this: v46, a2: buffer, a3: v22);
      ((void (__fastcall *)(idFile *, int))v47->dtr_idFile)(a1: v47, a2: 1);
      v15->fileSize = v22;
      v15->checksum = MD5_BlockChecksum(data: buffer, length: v22);
      v51 = this->declSource;
      if ( v51 != nullptr && (v52 = v51->sourceFile) != nullptr )
        v53 = v52->fileName.str;
      else
        v53 = this->name.str;
      v54 = fileSystem->GetTimestamp(this: fileSystem, a2: v53, a3: false);
      firstDeclSourceInFile = v15->firstDeclSourceInFile;
      for ( v15->timestamp = v54;
            firstDeclSourceInFile != nullptr;
            firstDeclSourceInFile = firstDeclSourceInFile->nextInFile )
      {
        v56 = this->declSource;
        v57 = firstDeclSourceInFile->sourceTextOffset;
        if ( v57 > v56->sourceTextOffset )
        {
          if ( v18 )
            firstDeclSourceInFile->sourceTextOffset = v15->fileSize
                                                    - v56->sourceTextLength
                                                    - v56->sourceTextOffset
                                                    + v57;
          else
            firstDeclSourceInFile->sourceTextOffset = this->textLength - v56->sourceTextLength + v57;
        }
      }
      this->declSource->sourceTextLength = this->textLength;
      if ( resourceLoadCallback != nullptr )
        resourceLoadCallback(a1: this);
      if ( idLib::sourceControl != nullptr && useSourceControl && v63.len != 0 )
      {
        v58 = this->declSource;
        if ( v58 != nullptr && (v59 = v58->sourceFile) != nullptr )
          v60 = v59->fileName.str;
        else
          v60 = this->name.str;
        fileSystem->RelativePathToOSPath_2(this: fileSystem, a2: v60, a3: v66, a4: 256, a5: FSPATH_BASE);
        idStr::idStr(this: &v64, text: v66);
        idSourceControl::Import(
          this: idLib::sourceControl,
          file: &v64,
          bKeepCheckedOut: true,
          submit: false,
          fileType: SCT_NONE);
        idStr::FreeData(this: &v64);
      }
      if ( buffer != nullptr )
        idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
      idStr::FreeData(this: &v61);
      idStr::FreeData(this: &v63);
      return 1;
    }
    v48 = this->declSource;
    if ( v48 != nullptr && (v49 = v48->sourceFile) != nullptr )
      v50 = v49->fileName.str;
    else
      v50 = this->name.str;
    idLib::Warning(fmt: "Couldn't open %s for writing.", v50);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
LABEL_81:
    idStr::FreeData(this: &v61);
    idStr::FreeData(this: &v63);
    return 0;
  }
  v4 = fileSystem->OpenFileWritePermanent(this: fileSystem, a2: this->name.str, a3: 0);
  if ( v4 == nullptr )
    idLib::Error(fmt: "Failed to open %s\n", this->name.str);
  textLength = this->textLength;
  if ( textLength == 0 )
    idDecl::Revert(this);
  v4->Write(this: v4, a2: this->textSource, a3: textLength);
  ((void (__fastcall *)(idFile *, int))v4->dtr_idFile)(a1: v4, a2: 1);
  return 1;
}


// ========================================================================
// $LN342
// EA  : 0x8260BFAC
// RVA : 0x0060BFAC
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _LN342()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 128));
}


// ========================================================================
// __unwind$221999
// EA  : 0x8260BFD4
// RVA : 0x0060BFD4
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_221999()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 192));
}


// ========================================================================
// __unwind$222000
// EA  : 0x8260BFFC
// RVA : 0x0060BFFC
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_222000()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 80));
}


// ========================================================================
// __unwind$222001
// EA  : 0x8260C024
// RVA : 0x0060C024
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_222001()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 576 + 112));
}


// ========================================================================
// __unwind$222002
// EA  : 0x8260C04C
// RVA : 0x0060C04C
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_222002()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 576 + 160));
}


// ========================================================================
// ?ReParse@idDecl@@QAAX_N@Z
// EA  : 0x8260C080
// RVA : 0x0060C080
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::ReParse(idDecl *this, bool fromDisk)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idDeclSource *declSource; // r11
  const char *v7; // r28
  idDeclFile *sourceFile; // r11
  const char *str; // r11
  int textLength; // r29
  idDeclSource *v11; // r11
  int sourceLine; // r9
  idLexer *scriptstack; // r11
  idDeclSource *v14; // r11
  idDeclFile *v15; // r25
  idFile *v17; // r29
  unsigned int num; // r27
  char *buffer; // r28
  char v20; // r27
  idDeclSource *v21; // r11
  const char *v22; // r28
  idDeclFile *v23; // r11
  const char *v24; // r11
  int v25; // r29
  idDeclSource *v26; // r11
  int v27; // r10
  idLexer *v28; // r9
  int v29; // r29
  int v30; // r28
  unsigned int v31; // r29
  int v32; // r3
  idDeclSource *v33; // r11
  const char *v34; // r28
  idDeclFile *v35; // r11
  const char *v36; // r11
  int v37; // r29
  int v38; // r28
  int v39; // r29
  char *v40; // r3
  idDecl *v41; // r30
  double v42; // fp1
  double v43; // fp2
  double v44; // fp3
  double v45; // fp4
  idStr *v46; // r29
  size_t len; // r30
  idStr *v48; // r30
  const char **v49; // r28
  idGame *v50; // r3
  idTypeInfoTools *v51; // r27
  const char *v52; // r3
  void *v53; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v55; // r30
  int v56; // r3
  __int64 totalTicks; // r11
  __int64 v58; // r9
  idTempArray<char> v59; // [sp+50h] [-6C0h] BYREF
  idPLogScope v60; // [sp+58h] [-6B8h] BYREF
  idStr v61; // [sp+60h] [-6B0h] BYREF
  idStr v62; // [sp+80h] [-690h] BYREF
  idStr v63; // [sp+A0h] [-670h] BYREF
  idStr v64; // [sp+C0h] [-650h] BYREF
  idStr v65; // [sp+E0h] [-630h] BYREF
  idStr v66; // [sp+100h] [-610h] BYREF
  idParmBlock v67; // [sp+120h] [-5F0h] BYREF
  idStr v68; // [sp+150h] [-5C0h] BYREF
  idParser v69; // [sp+170h] [-5A0h] BYREF
  idParser v70; // [sp+400h] [-310h] BYREF

  RD_EventBegin(name: "idDecl::ReParse");
  LODWORD(v4) = "idDecl::ReParse";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v60, pl: &::pLog, gMask: v4, label: v5);
  idResource::SetResourceError(this, fmt: nullptr);
  if ( this->programaticallyDefined )
  {
    this->FreeData(this);
    idParser::idParser(this: &v70, flags: 0);
    idParser::SetFlags(this: &v70, flags: 156216);
    declSource = this->declSource;
    if ( declSource != nullptr )
    {
      sourceFile = declSource->sourceFile;
      if ( sourceFile != nullptr )
        str = sourceFile->fileName.str;
      else
        str = this->name.str;
      v7 = str;
    }
    else
    {
      v7 = this->name.str;
    }
    textLength = this->textLength;
    if ( textLength == 0 )
      idDecl::Revert(this);
    idParser::LoadMemory(this: &v70, ptr: this->textSource, length: textLength, name: v7);
    v11 = this->declSource;
    sourceLine = 0;
    if ( v11 != nullptr )
      sourceLine = v11->sourceLine;
    scriptstack = v70.scriptstack;
    if ( v70.scriptstack != nullptr )
    {
      if ( sourceLine < 1 )
        sourceLine = 1;
      v70.scriptstack->line = sourceLine;
      scriptstack->lastline = sourceLine;
    }
    idParser::SkipUntilString(this: &v70, string: "{");
    this->Parse(this, a2: &v70);
    if ( idParser::HadError(this: &v70) || idParser::HadWarning(this: &v70) )
      idDecl::MakeDefault(this);
    idParser::~idParser(this: &v70);
    idPLogScope::~idPLogScope(this: &v60);
  }
  else
  {
    this->FreeData(this);
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 0);
    v14 = this->declSource;
    if ( v14 != nullptr )
    {
      v15 = v14->sourceFile;
      if ( v15 != nullptr && fromDisk )
      {
        if ( idLib::production == PROD_DEVELOPMENT
          && v15->fileSize > 0
          && idDeclFile::SourceFileChanged(this: v15, compareChecksums: false) )
        {
          declManager->Reload(this: declManager, a2: false);
        }
        v17 = fileSystem->OpenFileRead(this: fileSystem, a2: v15->fileName.str, a3: 1, a4: 0);
        if ( v17 != nullptr )
        {
          idTempArray<char>::idTempArray<char>(this: &v59, num: this->declSource->sourceTextLength);
          v17->Seek(this: v17, a2: this->declSource->sourceTextOffset, a3: FS_SEEK_SET);
          num = v59.num;
          buffer = v59.buffer;
          v17->Read(this: v17, a2: v59.buffer, a3: v59.num);
          ((void (__fastcall *)(idFile *, int))v17->dtr_idFile)(a1: v17, a2: 1);
          idDecl::SetText(this, text: buffer, length: num);
          if ( buffer != nullptr )
            idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
        }
      }
    }
    else
    {
      v15 = nullptr;
    }
    v20 = 0;
    if ( this->textSource == nullptr )
    {
      if ( !this->SetImplicitText(this) && this->textSource == nullptr )
      {
        idDecl::MakeDefault(this);
        resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
        idPLogScope::~idPLogScope(this: &v60);
        goto LABEL_94;
      }
      v20 = 1;
    }
    idParser::idParser(this: &v69, flags: 0);
    idParser::SetFlags(this: &v69, flags: 156216);
    v21 = this->declSource;
    if ( v21 != nullptr )
    {
      v23 = v21->sourceFile;
      if ( v23 != nullptr )
        v24 = v23->fileName.str;
      else
        v24 = this->name.str;
      v22 = v24;
    }
    else
    {
      v22 = this->name.str;
    }
    v25 = this->textLength;
    if ( v25 == 0 )
      idDecl::Revert(this);
    idParser::LoadMemory(this: &v69, ptr: this->textSource, length: v25, name: v22);
    v26 = this->declSource;
    v27 = 0;
    if ( v26 != nullptr )
      v27 = v26->sourceLine;
    v28 = v69.scriptstack;
    if ( v69.scriptstack != nullptr )
    {
      if ( v27 < 1 )
        v27 = 1;
      v69.scriptstack->line = v27;
      v28->lastline = v27;
    }
    if ( v15 != nullptr )
    {
      v29 = v15->includeFiles.num - 1;
      if ( v29 >= 0 )
      {
        v30 = v29;
        do
        {
          idParser::AddInclude(this: &v69, fileName: v15->includeFiles.list[v30].data);
          --v29;
          --v30;
        }
        while ( v29 >= 0 );
      }
    }
    if ( idLib::production == PROD_BUILDING && (v15 != nullptr || v20 != 0) )
    {
      resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
      ProductionFilename(result: &v66, r: this);
      if ( _RTDynamicCast(
             inptr: this,
             VfDelta: 0,
             SrcType: &idDecl `RTTI Type Descriptor',
             TargetType: (void *)&idDeclRenderProg `RTTI Type Descriptor',
             isReference: 0) != nullptr )
      {
        v31 = this->textLength;
        if ( v31 == 0 )
          idDecl::Revert(this);
        fileSystem->WriteFile(this: fileSystem, a2: v66.data, a3: this->textSource, a4: v31, a5: FSPATH_BASE);
      }
      else
      {
        v62.allocedAndFlag = 20;
        v62.len = 0;
        v62.data = v62.baseBuffer;
        v62.baseBuffer[0] = 0;
        resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 0);
        idParser::ParseBracedSectionExact(this: &v69, out: &v62, parseFirstBrace: true);
        resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
        fileSystem->WriteFile(this: fileSystem, a2: v66.data, a3: v62.data, a4: v62.len, a5: FSPATH_BASE);
        idStr::FreeData(this: &v62);
      }
      v59.buffer = nullptr;
      v32 = fileSystem->ReadFile(this: fileSystem, a2: v66.data, a3: (void **)&v59, a4: nullptr);
      idDecl::SetText(this, text: v59.buffer, length: v32);
      idParser::FreeSource(this: &v69);
      v33 = this->declSource;
      if ( v33 != nullptr )
      {
        v35 = v33->sourceFile;
        if ( v35 != nullptr )
          v36 = v35->fileName.str;
        else
          v36 = this->name.str;
        v34 = v36;
      }
      else
      {
        v34 = this->name.str;
      }
      v37 = this->textLength;
      if ( v37 == 0 )
        idDecl::Revert(this);
      idParser::LoadMemory(this: &v69, ptr: this->textSource, length: v37, name: v34);
      idStr::FreeData(this: &v66);
    }
    resourceManager->SetResourceFilePlatform(this: resourceManager, a2: 7u);
    idParser::SkipUntilString(this: &v69, string: "{");
    this->Parse(this, a2: &v69);
    v38 = 0;
    v39 = 0;
    while ( v38 < v69.dependencies.num )
    {
      idDeclManagerLocal::AddDependency(
        this: &declManagerLocal,
        decl: this,
        fileName: v69.dependencies.list[v39].fileName.data);
      ++v38;
      ++v39;
    }
    if ( idParser::HadError(this: &v69) || idParser::HadWarning(this: &v69) )
      idDecl::MakeDefault(this);
    if ( idLib::production == PROD_BUILDING )
    {
      ProductionFilename(result: &v65, r: this);
      if ( _RTDynamicCast(
             inptr: this,
             VfDelta: 0,
             SrcType: &idDecl `RTTI Type Descriptor',
             TargetType: (void *)&idMaterial `RTTI Type Descriptor',
             isReference: 0) != nullptr )
      {
        v40 = (char *)_RTDynamicCast(
                        inptr: this,
                        VfDelta: 0,
                        SrcType: &idDecl `RTTI Type Descriptor',
                        TargetType: (void *)&idMaterial `RTTI Type Descriptor',
                        isReference: 0);
        v41 = (idDecl *)v40;
        if ( *((_DWORD *)v40 + 60) != 0 )
        {
          v42 = *((float *)v40 + 62);
          v43 = *((float *)v40 + 63);
          v44 = *((float *)v40 + 64);
          v59.buffer = v40 + 248;
          v45 = *((float *)v40 + 65);
          v64.allocedAndFlag = 20;
          v64.data = v64.baseBuffer;
          v64.len = 0;
          v64.baseBuffer[0] = 0;
          idStr::Format(this: &v64, fmt: "\tvirtualMapping { %f, %f, %f, %f } \n}", v42, v43, v44, v45);
          if ( v41->textLength == 0 )
            idDecl::Revert(this: v41);
          idStr::idStr(this: &v61, text: v41->textSource);
          v46 = idStr::Left(this: &v68, result: &v61, len: v61.len - 1);
          len = v46->len;
          idStr::EnsureAlloced(this: &v61, amount: v46->len + 1, keepold: false, geometricGrowth: false);
          memcpy(Dst: v61.data, Src: v46->data, Size: len);
          v61.data[len] = 0;
          v61.len = len;
          idStr::FreeData(this: &v68);
          idStr::Append(this: &v61, text: &v64);
          fileSystem->WriteFile(this: fileSystem, a2: v65.data, a3: v61.data, a4: v61.len, a5: FSPATH_BASE);
          idStr::FreeData(this: &v61);
          idStr::FreeData(this: &v64);
        }
        else
        {
          idParmBlock::idParmBlock(this: &v67, other: (const idParmBlock *)(v40 + 84));
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v67);
          v48 = idParmBlock::WriteString(this: &v67);
          fileSystem->WriteFile(this: fileSystem, a2: v65.data, a3: v48->data, a4: v48->len, a5: FSPATH_BASE);
          idStr::FreeData(this: v48);
          idMem::Free(this: &mem, ptr: v48, align: ALIGN_16);
          idParmBlock::~idParmBlock(this: &v67);
        }
      }
      else
      {
        v49 = (const char **)_RTDynamicCast(
                               inptr: this,
                               VfDelta: 0,
                               SrcType: &idDecl `RTTI Type Descriptor',
                               TargetType: (void *)&idDeclEntityDef `RTTI Type Descriptor',
                               isReference: 0);
        if ( v49 != nullptr )
        {
          v50 = common->Game(this: common);
          v51 = (idTypeInfoTools *)v50->GetTypeInfoTools(this: v50);
          if ( com_useExpandedEntityDefs.valueInteger == 0
            || (v52 = (const char *)(*((int (__fastcall **)(const char **))*v49 + 19))(a1: v49),
                idTypeInfoTools::IsSubclassOf(this: v51, typeName: v52, superType: "idVehicle")) )
          {
            idLib::Printf(fmt: "Not expanding %s because it's a def for an idVehicle.\n", v49[2]);
          }
          else
          {
            v63.allocedAndFlag = 20;
            v63.len = 0;
            v63.data = v63.baseBuffer;
            v63.baseBuffer[0] = 0;
            v53 = _RTDynamicCast(
                    inptr: this,
                    VfDelta: 0,
                    SrcType: &idDecl `RTTI Type Descriptor',
                    TargetType: (void *)&idDeclEntityDef `RTTI Type Descriptor',
                    isReference: 0);
            (*(void (__fastcall **)(void *, idStr *, int))(*(_DWORD *)v53 + 128))(a1: v53, a2: &v63, a3: 1);
            fileSystem->WriteFile(this: fileSystem, a2: v65.data, a3: v63.data, a4: v63.len, a5: FSPATH_BASE);
            idStr::FreeData(this: &v63);
          }
        }
      }
      idStr::FreeData(this: &v65);
    }
    idParser::~idParser(this: &v69);
    if ( v60.logIndex >= 0 )
    {
      pLog = v60.pLog;
      v55 = &v60.pLog->logEntries.list[v60.logIndex];
      v56 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v55->totalTicks;
      HIDWORD(totalTicks) = v55->parent;
      LODWORD(v58) = v56 - totalTicks;
      v55->totalTicks = v58;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
LABEL_94:
  RD_EventEnd();
}


// ========================================================================
// __unwind$223488
// EA  : 0x8260CAB4
// RVA : 0x0060CAB4
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223488()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1808 + 1680));
}


// ========================================================================
// __unwind$223489
// EA  : 0x8260CADC
// RVA : 0x0060CADC
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223489()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1808 + 88));
}


// ========================================================================
// __unwind$223490
// EA  : 0x8260CB04
// RVA : 0x0060CB04
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223490()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 1808 + 1024));
}


// ========================================================================
// __unwind$223491
// EA  : 0x8260CB2C
// RVA : 0x0060CB2C
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223491()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 1808 + 80));
}


// ========================================================================
// __unwind$223492
// EA  : 0x8260CB54
// RVA : 0x0060CB54
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223492()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 1808 + 368));
}


// ========================================================================
// __unwind$223493
// EA  : 0x8260CB7C
// RVA : 0x0060CB7C
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223493()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1808 + 256));
}


// ========================================================================
// __unwind$223494
// EA  : 0x8260CBA4
// RVA : 0x0060CBA4
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223494()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1808 + 128));
}


// ========================================================================
// __unwind$223495
// EA  : 0x8260CBCC
// RVA : 0x0060CBCC
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223495()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1808 + 224));
}


// ========================================================================
// __unwind$223496
// EA  : 0x8260CBF4
// RVA : 0x0060CBF4
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223496()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1808 + 192));
}


// ========================================================================
// __unwind$223497
// EA  : 0x8260CC1C
// RVA : 0x0060CC1C
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223497()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1808 + 96));
}


// ========================================================================
// __unwind$223498
// EA  : 0x8260CC44
// RVA : 0x0060CC44
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223498()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1808 + 336));
}


// ========================================================================
// __unwind$223499
// EA  : 0x8260CC6C
// RVA : 0x0060CC6C
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223499()
{
  int v0; // r12

  idParmBlock::~idParmBlock(this: (idParmBlock *)(v0 - 1808 + 288));
}


// ========================================================================
// __unwind$223500
// EA  : 0x8260CC94
// RVA : 0x0060CC94
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_223500()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1808 + 160));
}


// ========================================================================
// ?LoadResource@idDecl@@UAAXXZ
// EA  : 0x8260CCC8
// RVA : 0x0060CCC8
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void __fastcall idDecl::LoadResource(idDecl *this)
{
  const idStr *v2; // r3
  int v3; // r3
  int v4; // r30
  const char *str; // r4
  int v6; // r5
  idDeclInfo *v7; // r3
  idDeclSource *DeclSource; // r26
  int v9; // r30
  int v10; // r29
  idStr *list; // r11
  char *data; // r10
  char *v13; // r11
  int v14; // r9
  int v15; // r9
  bool v16; // zf
  void *v17[4]; // [sp+50h] [-330h] BYREF
  idList<idStr,5> v18; // [sp+60h] [-320h] BYREF
  idStr v19; // [sp+70h] [-310h] BYREF
  idStr v20; // [sp+90h] [-2F0h] BYREF
  idParser v21; // [sp+B0h] [-2D0h] BYREF

  if ( !this->programaticallyDefined )
  {
    idResource::SetResourceError(this, fmt: nullptr);
    if ( idLib::production < PROD_PRODUCTION )
    {
      if ( strstr(str1: this->name.str, str2: ".decl") != nullptr )
      {
        str = this->name.str;
        v17[0] = nullptr;
        v6 = fileSystem->ReadFile(this: fileSystem, a2: str, a3: v17, a4: nullptr);
        if ( v6 <= 0 )
        {
          if ( strstr(str1: this->name.str, str2: "automaterial") != nullptr )
          {
            idResource::SetResourceError(this, fmt: "Explicit decl file not found '%s'", this->name.str);
            idDecl::MakeDefault(this);
            return;
          }
          idLib::FatalError(fmt: "Missing decl %s - Is the file checked in? ", this->name.str);
        }
        idDecl::SetText(this, text: (const char *)v17[0], length: v6);
        if ( v17[0] != nullptr )
          ((void (__fastcall *)(idFileSystem *))fileSystem->FreeFile)(a1: fileSystem);
        this->declSource = nullptr;
      }
      else
      {
        v7 = this->GetDeclInfo(this);
        DeclSource = idDeclInfo::FindDeclSource(this: v7, name: this->name.str);
        if ( DeclSource == nullptr )
        {
          v9 = 0;
          *(_WORD *)&v18.memTag = 1280;
          memset(&v18, 0, 14);
          idDeclManagerLocal::GetLogDeclsList(this: &declManagerLocal, declList: &v18);
          v10 = 0;
          if ( v18.num > 0 )
          {
            list = v18.list;
            do
            {
              data = list->data;
              v13 = com_writeMissingDeclFiles.valueString.data;
              do
              {
                v14 = (unsigned __int8)*v13;
                v16 = v14 == 0;
                v15 = v14 - (unsigned __int8)*data;
                if ( v16 )
                  break;
                ++v13;
                ++data;
              }
              while ( v15 == 0 );
              if ( v15 == 0 )
                this->LogMissingDecl(this);
              ++v10;
              list = &v18.list[++v9];
            }
            while ( v10 < v18.num );
          }
          idList<idStr,99>::~idList<idStr,99>(this: &v18);
        }
        idDecl::DefineFromSource(this, ds: DeclSource);
      }
      idDecl::ReParse(this, fromDisk: true);
    }
    else
    {
      this->FreeData(this);
      v19.len = 0;
      v19.allocedAndFlag = 20;
      v19.data = v19.baseBuffer;
      v19.baseBuffer[0] = 0;
      if ( strstr(str1: this->name.str, str2: ".decl") != nullptr )
      {
        idStr::operator=(this: &v19, text: this->name.str);
      }
      else
      {
        v2 = ProductionFilename(result: &v20, r: this);
        idStr::operator=(this: &v19, text: v2);
        idStr::FreeData(this: &v20);
      }
      v17[0] = nullptr;
      v3 = fileSystem->ReadFile(this: fileSystem, a2: v19.data, a3: v17, a4: nullptr);
      v4 = v3;
      if ( v3 > 0 )
      {
        idDecl::SetText(this, text: (const char *)v17[0], length: v3);
        idParser::idParser(this: &v21, flags: 0);
        idParser::SetFlags(this: &v21, flags: 156216);
        idParser::LoadMemory(this: &v21, ptr: (const char *)v17[0], length: v4, name: v19.data);
        idParser::ExpectTokenString(this: &v21, string: "{");
        this->Parse(this, a2: &v21);
        idDecl::DeleteUnusedText(this);
        if ( idParser::HadError(this: &v21) || idParser::HadWarning(this: &v21) )
          idDecl::MakeDefault(this);
        idMem::Free(this: &mem, ptr: v17[0], align: ALIGN_16);
        idParser::~idParser(this: &v21);
        idStr::FreeData(this: &v19);
      }
      else
      {
        idResource::SetResourceError(this, fmt: "couldn't read production file for decl '%s'", v19.data);
        idDecl::MakeDefault(this);
        idStr::FreeData(this: &v19);
      }
    }
  }
}


// ========================================================================
// $LN106
// EA  : 0x8260D06C
// RVA : 0x0060D06C
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _LN106()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 112));
}


// ========================================================================
// __unwind$224268
// EA  : 0x8260D094
// RVA : 0x0060D094
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_224268()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 896 + 144));
}


// ========================================================================
// __unwind$224269
// EA  : 0x8260D0BC
// RVA : 0x0060D0BC
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_224269()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 896 + 176));
}


// ========================================================================
// __unwind$224270
// EA  : 0x8260D0E4
// RVA : 0x0060D0E4
// PDB : w:\tech5\engine\decls\decl.cpp
// ========================================================================

void _unwind_224270()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 896 + 96));
}

