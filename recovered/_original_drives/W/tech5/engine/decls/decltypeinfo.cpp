
// ========================================================================
// ??0idDeclTypeInfo@@QAA@XZ
// EA  : 0x8262ACF0
// RVA : 0x0062ACF0
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

idDeclTypeInfo *__fastcall idDeclTypeInfo::idDeclTypeInfo(idDeclTypeInfo *this)
{
  idDecl::idDecl(this);
  this->parent = nullptr;
  this->__vftable = (idDeclTypeInfo_vtbl *)&idDeclTypeInfo::`vftable';
  this->hasBeenParsedAtLeastOnce = false;
  return this;
}


// ========================================================================
// ??1idDeclTypeInfo@@UAA@XZ
// EA  : 0x8262AD38
// RVA : 0x0062AD38
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void __fastcall idDeclTypeInfo::~idDeclTypeInfo(idDeclTypeInfo *this)
{
  this->__vftable = (idDeclTypeInfo_vtbl *)&idDeclTypeInfo::`vftable';
  idDecl::~idDecl(this);
}


// ========================================================================
// ?Parse@idDeclTypeInfo@@UAAXAAVidParser@@@Z
// EA  : 0x8262ADC8
// RVA : 0x0062ADC8
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void __fastcall idDeclTypeInfo::Parse(idDeclTypeInfo *this, idParser *src)
{
  const char *v2; // r29
  int v3; // r24
  idParser *p_data; // r25
  char *data; // r28
  idDeclInfo *v7; // r3
  idDeclTypeInfo *v8; // r3
  const char *v9; // r23
  int *v10; // r26
  char *v11; // r28
  const char *v12; // r27
  idDeclTypeInfo *parent; // r3
  idDeclInfo *v14; // r3
  idDecl *v15; // r22
  int v16; // r3
  idArray<idResource *,32> *v17; // r27
  idResource *v18; // r3
  const char *str; // r28
  const char *ResourceTypeName; // r4
  const char *v21; // r3
  idDeclTypeInfo_vtbl *v22; // r11
  int v23; // r3
  idDeclInfo *v24; // r3
  idDeclInfo *v25; // r3
  idDeclInfo *v26; // r3
  idDeclInfo *v27; // r3
  idStr v28; // [sp+50h] [-220h] BYREF
  idDeclTypeInfo *v29; // [sp+70h] [-200h]
  idToken v30; // [sp+80h] [-1F0h] BYREF
  idTypeInfoFile v31; // [sp+D0h] [-1A0h] BYREF
  idTypeInfoFile v32; // [sp+170h] [-100h] BYREF

  v2 = nullptr;
  v3 = 20;
  v30.len = 0;
  v30.allocedAndFlag = 20;
  p_data = src;
  v30.floatvalue = -3.4028235e38;
  v30.data = v30.baseBuffer;
  this->parent = nullptr;
  v30.baseBuffer[0] = 0;
  v30.intvalue = 0;
  memset(&v30.whiteSpaceStart_p, 0, 12);
  if ( idParser::PeekTokenString(this: src, string: "inherit") != 0 )
  {
    idParser::ExpectTokenString(this: p_data, string: "inherit");
    idParser::ExpectTokenString(this: p_data, string: "=");
    idParser::ExpectTokenType(this: p_data, type: 1, subtype: 0, token: &v30);
    if ( v30.len != 0 )
    {
      data = v30.data;
      v7 = this->GetDeclInfo(this);
      v8 = (idDeclTypeInfo *)idResourceList::Load(this: v7, name: data, makeDefault: false, skipStaleCheck: false);
      this->parent = v8;
      declManager->AddDependency_2(this: declManager, a2: this, a3: v8);
    }
    idParser::ExpectTokenString(this: p_data, string: ";");
  }
  LOBYTE(v9) = 1;
  v10 = &joystick.joyAxis[0][2];
  v11 = &byte_8200D768;
  v12 = "edit";
  if ( this->parent != nullptr || this->hasBeenParsedAtLeastOnce )
  {
    idTypeInfoFile::idTypeInfoFile(this: &v31, indent_: 0);
    v31.settings.writeModifier = WRITE_DEF_AND_EDIT_ONLY;
    v31.settings.resolveEntityPointers = false;
    v31.settings.resolveModelPointers = false;
    idTypeInfoFile::WriteMemoryFile(this: &v31);
    parent = this->parent;
    if ( parent != nullptr )
    {
      if ( (*((_BYTE *)&parent->idResource + 32) & 0x20) != 0 )
      {
        p_data = (idParser *)&keyActions[3][4][214].binding.data;
        if ( idResourceList::loadResourceRecursionLevel > 0 )
        {
          v17 = &idResourceList::recursiveLoads;
          v10 = (int *)"%s::LoadResource( %s )\n";
          v3 = (int)"<unknown type>";
          v9 = "<null>";
          do
          {
            v18 = v17->ptr[0];
            if ( v17->ptr[0] != nullptr )
            {
              str = v18->name.str;
              ResourceTypeName = idResource::GetResourceTypeName(this: v18);
            }
            else
            {
              str = "<null>";
              ResourceTypeName = "<unknown type>";
            }
            idLib::Printf(fmt: "%s::LoadResource( %s )\n", ResourceTypeName, str);
            ++v2;
            v17 = (idArray<idResource *,32> *)((char *)v17 + 4);
          }
          while ( (int)v2 < idResourceList::loadResourceRecursionLevel );
        }
        v2 = this->name.str;
        v11 = (char *)this->parent->name.str;
        v12 = idResource::GetResourceTypeName(this);
        v21 = idResource::GetResourceTypeName(this: this->parent);
        idLib::Error(
          fmt: "Resource %s:%s is being used for parent inheritance for %s:%s before it is fully defined.",
          v21,
          v11,
          v12,
          v2);
      }
      v22 = parent->__vftable;
      v29 = parent;
      v23 = ((int (*)(void))v22->GetDeclInfo)();
      idTypeInfoTools::WriteObject(
        this: (idTypeInfoTools *)v10[5472],
        file: &v31,
        objectType: *(const char **)(v23 + 1048),
        objectOps: v11,
        objectName: v12,
        objectPtr: this->parent);
    }
    else
    {
      v14 = this->GetDeclInfo(this);
      v15 = v14->AllocDecl(this: v14);
      v16 = (int)v15->GetDeclInfo(this: v15);
      idTypeInfoTools::WriteObject(
        this: typeInfoTools,
        file: &v31,
        objectType: *(const char **)(v16 + 1048),
        objectOps: &byte_8200D768,
        objectName: "edit",
        objectPtr: v15);
      ((void (__fastcall *)(idDecl *, int))v15->dtr_idResource)(a1: v15, a2: 1);
    }
    idTypeInfoFile::ReadMemoryFile(this: &v31);
    v24 = this->GetDeclInfo(this);
    idTypeInfoTools::ReadObject(
      this: (idTypeInfoTools *)v10[5472],
      file: &v31,
      objectType: v24->classname,
      objectOps: v11,
      objectName: v12,
      objectPtr: this);
    idTypeInfoFile::~idTypeInfoFile(this: &v31);
  }
  v28.allocedAndFlag = v3;
  v28.len = (int)v2;
  v28.data = v28.baseBuffer;
  v28.baseBuffer[0] = (char)v2;
  idParser::ParseBracedSectionExact(this: p_data, out: &v28, parseFirstBrace: false);
  idTypeInfoFile::idTypeInfoFile(this: &v32, indent_: 0);
  idTypeInfoFile::ReadMemory(this: &v32, data: v28.data, length: v28.len, name: this->name.str, startLine: 0);
  v25 = this->GetDeclInfo(this);
  if ( idTypeInfoFile::CheckType(this: &v32, type: v25->classname, ops: v11, name: v12)
    || (v26 = this->GetDeclInfo(this),
        idTypeInfoFile::CheckType(this: &v32, type: v26->classname, ops: v11, name: "data")) )
  {
    v27 = this->GetDeclInfo(this);
    idTypeInfoTools::ReadObject(
      this: (idTypeInfoTools *)v10[5472],
      file: &v32,
      objectType: v27->classname,
      objectOps: v11,
      objectName: v12,
      objectPtr: this);
  }
  this->hasBeenParsedAtLeastOnce = (char)v9;
  idTypeInfoFile::~idTypeInfoFile(this: &v32);
  idStr::FreeData(this: &v28);
  idStr::FreeData(this: &v30);
}


// ========================================================================
// $LN114
// EA  : 0x8262B1E4
// RVA : 0x0062B1E4
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _LN114()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 128));
}


// ========================================================================
// __unwind$221031
// EA  : 0x8262B20C
// RVA : 0x0062B20C
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221031()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 624 + 208));
}


// ========================================================================
// __unwind$221032
// EA  : 0x8262B234
// RVA : 0x0062B234
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221032()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 624 + 80));
}


// ========================================================================
// __unwind$221033
// EA  : 0x8262B25C
// RVA : 0x0062B25C
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221033()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 624 + 368));
}


// ========================================================================
// ?SetState@idDeclTypeInfo@@QAAXPBV1@@Z
// EA  : 0x8262B290
// RVA : 0x0062B290
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void __fastcall idDeclTypeInfo::SetState(idDeclTypeInfo *this, idDeclTypeInfo *empty)
{
  idDeclTypeInfo *parent; // r27
  idDeclTypeInfo_vtbl *v4; // r11
  int v5; // r3
  idDeclInfo *v6; // r3
  idDeclInfo *v7; // r3
  idDeclInfo *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  idDeclTypeInfo *v12; // r11
  va *v13; // r3
  char *TypeInfoString; // r3
  int v15; // [sp+8h] [-12D8h]
  int v16; // [sp+Ch] [-12D4h]
  int v17; // [sp+10h] [-12D0h]
  int v18; // [sp+14h] [-12CCh]
  int v19; // [sp+18h] [-12C8h]
  int v20; // [sp+1Ch] [-12C4h]
  idTypeInfoTree v21; // [sp+50h] [-1290h] BYREF
  idTypeInfoTree v22; // [sp+70h] [-1270h] BYREF
  idStr v23; // [sp+90h] [-1250h] BYREF
  idTypeInfoFile v24; // [sp+B0h] [-1230h] BYREF
  idTypeInfoFile v25; // [sp+150h] [-1190h] BYREF
  idTypeInfoFile v26; // [sp+1F0h] [-10F0h] BYREF
  va v27; // [sp+290h] [-1050h] BYREF

  parent = this->parent;
  if ( parent == nullptr )
    parent = empty;
  idTypeInfoFile::idTypeInfoFile(this: &v24, indent_: 0);
  idTypeInfoFile::WriteMemoryFile(this: &v24);
  v4 = this->__vftable;
  v24.settings.resolveEntityPointers = false;
  v24.settings.writeModifier = WRITE_DEF_AND_EDIT_ONLY;
  v24.settings.resolveModelPointers = false;
  v24.settings.skipMarkedObjects = false;
  v24.settings.writeComments = false;
  v5 = (int)v4->GetDeclInfo(this);
  idTypeInfoFile::WriteType(this: &v24, type: *(const char **)(v5 + 1048), ops: &byte_8200D768, name: "edit");
  v6 = this->GetDeclInfo(this);
  idTypeInfoTools::WriteObject(
    this: typeInfoTools,
    file: &v24,
    objectType: v6->classname,
    objectOps: &byte_8200D768,
    objectName: "edit",
    objectPtr: parent);
  v22.nodeBlockAlloc.allowAllocs = true;
  v22.nodeBlockAlloc.clearAllocs = false;
  memset(&v22, 0, 20);
  idTypeInfoFile::ReadMemoryFile(this: &v24);
  idTypeInfoTree::Parse(this: &v22, file: &v24);
  idTypeInfoFile::idTypeInfoFile(this: &v25, indent_: 0);
  idTypeInfoFile::WriteMemoryFile(this: &v25);
  v25.settings.writeModifier = WRITE_DEF_AND_EDIT_ONLY;
  v25.settings.resolveEntityPointers = false;
  v25.settings.resolveModelPointers = false;
  v25.settings.skipMarkedObjects = false;
  v25.settings.writeComments = false;
  v7 = this->GetDeclInfo(this);
  idTypeInfoFile::WriteType(this: &v25, type: v7->classname, ops: &byte_8200D768, name: "edit");
  v8 = this->GetDeclInfo(this);
  idTypeInfoTools::WriteObject(
    this: typeInfoTools,
    file: &v25,
    objectType: v8->classname,
    objectOps: &byte_8200D768,
    objectName: "edit",
    objectPtr: this);
  v21.nodeBlockAlloc.allowAllocs = true;
  v21.nodeBlockAlloc.clearAllocs = false;
  memset(&v21, 0, 20);
  idTypeInfoFile::ReadMemoryFile(this: &v25);
  idTypeInfoTree::Parse(this: &v21, file: &v25);
  idTypeInfoTree::ExtendListsWithDefaultsBasedOn(
    this: &v22,
    referenceTree: &v21,
    settings: &v24.settings,
    tit: typeInfoTools);
  idTypeInfoTree::Diff(this: &v21, tree: &v22);
  idTypeInfoFile::idTypeInfoFile(this: &v26, indent_: 1);
  idTypeInfoFile::WriteMemoryFile(this: &v26);
  v26.settings.writeComments = true;
  v26.settings.resolveEntityPointers = false;
  v26.settings.resolveModelPointers = false;
  v26.settings.writeType = false;
  idTypeInfoTree::Write(this: &v21, file: &v26, onlyDiff: true);
  idStr::idStr(this: &v23, text: "{\n");
  v12 = this->parent;
  if ( v12 != nullptr )
  {
    LODWORD(v9) = &unk_821C0000;
    HIDWORD(v11) = v12->name.str;
    v13 = va::va(
            this: &v27,
            fmt: "\tinherit = \"%s\";\n",
            a3: v11,
            a4: v10,
            a5: v9,
            a6: v15,
            a7: v16,
            a8: v17,
            a9: v18,
            a10: v19,
            a11: v20);
    idStr::Append(this: &v23, text: v13);
  }
  TypeInfoString = (char *)idTypeInfoFile::GetTypeInfoString(this: &v26);
  idStr::Append(this: &v23, text: TypeInfoString);
  idStr::Append(this: &v23, text: "\n}");
  idDecl::SetText(this, text: v23.data, length: 0);
  idStr::FreeData(this: &v23);
  idTypeInfoFile::~idTypeInfoFile(this: &v26);
  idTypeInfoTree::~idTypeInfoTree(this: &v21);
  idTypeInfoFile::~idTypeInfoFile(this: &v25);
  idTypeInfoTree::~idTypeInfoTree(this: &v22);
  idTypeInfoFile::~idTypeInfoFile(this: &v24);
}


// ========================================================================
// __unwind$221321
// EA  : 0x8262B534
// RVA : 0x0062B534
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221321()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 4832 + 176));
}


// ========================================================================
// __unwind$221322
// EA  : 0x8262B55C
// RVA : 0x0062B55C
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221322()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 4832 + 112));
}


// ========================================================================
// __unwind$221323
// EA  : 0x8262B584
// RVA : 0x0062B584
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221323()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 4832 + 336));
}


// ========================================================================
// __unwind$221324
// EA  : 0x8262B5AC
// RVA : 0x0062B5AC
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221324()
{
  int v0; // r12

  idTypeInfoTree::~idTypeInfoTree(this: (idTypeInfoTree *)(v0 - 4832 + 80));
}


// ========================================================================
// __unwind$221325
// EA  : 0x8262B5D4
// RVA : 0x0062B5D4
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221325()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 4832 + 496));
}


// ========================================================================
// __unwind$221326
// EA  : 0x8262B5FC
// RVA : 0x0062B5FC
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

void _unwind_221326()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4832 + 144));
}


// ========================================================================
// ?RebuildTextSource@idDeclTypeInfo@@UAA_NXZ
// EA  : 0x8262B628
// RVA : 0x0062B628
// PDB : w:\tech5\engine\decls\decltypeinfo.cpp
// ========================================================================

int __fastcall idDeclTypeInfo::RebuildTextSource(idDeclTypeInfo *this)
{
  idDeclTypeInfo *parent; // r31
  idDeclInfo *v3; // r3

  parent = this->parent;
  if ( parent == nullptr )
  {
    v3 = this->GetDeclInfo(this);
    parent = (idDeclTypeInfo *)v3->AllocDecl(this: v3);
  }
  idDeclTypeInfo::SetState(this, empty: parent);
  if ( parent != this->parent && parent != nullptr )
    ((void (__fastcall *)(idDeclTypeInfo *, int))parent->dtr_idResource)(a1: parent, a2: 1);
  return 1;
}

