
// ========================================================================
// ?GetVariableName@idTypeInfoObject@@ABAXPBDAAVidStr@@AAH@Z
// EA  : 0x82F9B4B8
// RVA : 0x00F9B4B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void __fastcall idTypeInfoObject::GetVariableName(idTypeInfoObject *this, char *path, idStr *name, int *arrayIndex)
{
  int v7; // r3
  int i; // r11
  int v9; // r10
  int v10; // r10
  int v11; // r3

  idStr::operator=(this: name, text: path);
  v7 = idStr::Last(this: name, c: 46, index: -1);
  idStr::operator=(this: name, text: &path[v7 + 1]);
  if ( name->len != 0 && name->data[name->len - 1] == 93 )
  {
    *arrayIndex = 0;
    for ( i = idStr::Last(this: name, c: 91, index: -1) + 1; i > 0; *arrayIndex = v10 - 48 )
    {
      if ( i >= name->len - 1 )
        break;
      v9 = 10 * *arrayIndex;
      *arrayIndex = v9;
      v10 = name->data[i++] + v9;
    }
    v11 = idStr::Last(this: name, c: 91, index: -1);
    if ( name->len > v11 && v11 >= 0 )
    {
      name->data[v11] = 0;
      name->len = v11;
    }
  }
  else
  {
    *arrayIndex = -1;
  }
}


// ========================================================================
// ?GetVariablePre@idTypeInfoObject@@ABA_NAAVidTypeInfoFile@@AAVidStr@@PBD22_N@Z
// EA  : 0x82F9B5C8
// RVA : 0x00F9B5C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

int __fastcall idTypeInfoObject::GetVariablePre(
        idTypeInfoObject *this,
        idTypeInfoFile *file,
        idStr *name,
        char *type,
        char *ops,
        char *path,
        bool resolvePtrs)
{
  __int64 v15; // r8
  char *data; // r6
  int v17[20]; // [sp+50h] [-50h] BYREF

  idTypeInfoObject::GetVariableName(this, path, name, arrayIndex: v17);
  file->settings.resolveEntityPointers = resolvePtrs;
  file->settings.resolveModelPointers = resolvePtrs;
  file->settings.writeModifier = WRITE_DEF_AND_EDIT_ONLY;
  file->settings.writeComments = false;
  idTypeInfoFile::WriteMemoryFile(this: file);
  if ( !idTypeInfoTools::WriteObjectVariable(
          this: (idTypeInfoTools *)this->ti,
          file,
          objectType: this->objectType.data,
          objectPtr: this->objectPtr,
          path) )
    return 0;
  idTypeInfoFile::ReadMemoryFile(this: file);
  data = name->data;
  if ( v17[0] < 0 )
  {
    idTypeInfoFile::ExpectType(this: file, type, ops, name: data);
  }
  else
  {
    HIDWORD(v15) = v17;
    idTypeInfoFile::ExpectArrayElementType(this: file, type, ops, name: data, index: v15);
  }
  return 1;
}


// ========================================================================
// ?GetBool@idTypeInfoObject@@QBA_NABVidTypeInfoVariable_bool@@AA_N@Z
// EA  : 0x82F9B6A0
// RVA : 0x00F9B6A0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetBool(idTypeInfoObject *this, const idTypeInfoVariable_bool *variable, bool *b)
{
  __int64 v6; // r8
  int v7; // r6
  int VariablePre; // r5
  BOOL v10; // r30
  idStr v11; // [sp+50h] [-F0h] BYREF
  idTypeInfoFile v12; // [sp+70h] [-D0h] BYREF

  v11.len = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  v11.baseBuffer[0] = 0;
  idTypeInfoFile::idTypeInfoFile(this: &v12, indent_: 0);
  VariablePre = (unsigned __int8)idTypeInfoObject::GetVariablePre(
                                   this,
                                   file: &v12,
                                   name: &v11,
                                   type: "bool",
                                   ops: &byte_8200D768,
                                   path: (char *)variable->path,
                                   resolvePtrs: true);
  if ( VariablePre != 0 )
  {
    idTypeInfoFile::ReadBool(this: &v12, b, a3: VariablePre, a4: v7, a5: v6);
    v10 = (_cntlzw(idTypeInfoFile::HadError(this: &v12)) & 0x20) != 0;
    idTypeInfoFile::~idTypeInfoFile(this: &v12);
    idStr::FreeData(this: &v11);
    return v10;
  }
  else
  {
    idTypeInfoFile::~idTypeInfoFile(this: &v12);
    idStr::FreeData(this: &v11);
    return false;
  }
}


// ========================================================================
// __unwind$114208
// EA  : 0x82F9B76C
// RVA : 0x00F9B76C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_114208()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 80));
}


// ========================================================================
// __unwind$114209
// EA  : 0x82F9B794
// RVA : 0x00F9B794
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_114209()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 320 + 112));
}


// ========================================================================
// ?GetInt@idTypeInfoObject@@QBA_NABVidTypeInfoVariable_int@@AAH@Z
// EA  : 0x82F9B7C8
// RVA : 0x00F9B7C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetInt(
        idTypeInfoObject *this,
        const idTypeInfoVariable_int *variable,
        unsigned int *i)
{
  __int64 v6; // r8
  __int64 v7; // r6
  BOOL v9; // r30
  idStr v10; // [sp+50h] [-F0h] BYREF
  idTypeInfoFile v11; // [sp+70h] [-D0h] BYREF

  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  idTypeInfoFile::idTypeInfoFile(this: &v11, indent_: 0);
  HIDWORD(v7) = (unsigned __int8)idTypeInfoObject::GetVariablePre(
                                   this,
                                   file: &v11,
                                   name: &v10,
                                   type: "int",
                                   ops: &byte_8200D768,
                                   path: (char *)variable->path,
                                   resolvePtrs: true);
  if ( HIDWORD(v7) != 0 )
  {
    idTypeInfoFile::ReadUnsignedLong(this: &v11, l: i, a3: v7, a4: v6);
    v9 = (_cntlzw(idTypeInfoFile::HadError(this: &v11)) & 0x20) != 0;
    idTypeInfoFile::~idTypeInfoFile(this: &v11);
    idStr::FreeData(this: &v10);
    return v9;
  }
  else
  {
    idTypeInfoFile::~idTypeInfoFile(this: &v11);
    idStr::FreeData(this: &v10);
    return false;
  }
}


// ========================================================================
// __unwind$115072
// EA  : 0x82F9B894
// RVA : 0x00F9B894
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_115072()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 80));
}


// ========================================================================
// __unwind$115073
// EA  : 0x82F9B8BC
// RVA : 0x00F9B8BC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_115073()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 320 + 112));
}


// ========================================================================
// ?GetFloat@idTypeInfoObject@@QBA_NABVidTypeInfoVariable_float@@AAM@Z
// EA  : 0x82F9B8F0
// RVA : 0x00F9B8F0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetFloat(idTypeInfoObject *this, const idTypeInfoVariable_float *variable, float *f)
{
  __int64 v6; // r8
  __int64 v7; // r6
  BOOL v9; // r30
  idStr v10; // [sp+50h] [-F0h] BYREF
  idTypeInfoFile v11; // [sp+70h] [-D0h] BYREF

  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  idTypeInfoFile::idTypeInfoFile(this: &v11, indent_: 0);
  HIDWORD(v7) = (unsigned __int8)idTypeInfoObject::GetVariablePre(
                                   this,
                                   file: &v11,
                                   name: &v10,
                                   type: "float",
                                   ops: &byte_8200D768,
                                   path: (char *)variable->path,
                                   resolvePtrs: true);
  if ( HIDWORD(v7) != 0 )
  {
    idTypeInfoFile::ReadFloat(this: &v11, f, a3: v7, a4: v6);
    v9 = (_cntlzw(idTypeInfoFile::HadError(this: &v11)) & 0x20) != 0;
    idTypeInfoFile::~idTypeInfoFile(this: &v11);
    idStr::FreeData(this: &v10);
    return v9;
  }
  else
  {
    idTypeInfoFile::~idTypeInfoFile(this: &v11);
    idStr::FreeData(this: &v10);
    return false;
  }
}


// ========================================================================
// __unwind$115648
// EA  : 0x82F9B9BC
// RVA : 0x00F9B9BC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_115648()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 80));
}


// ========================================================================
// __unwind$115649
// EA  : 0x82F9B9E4
// RVA : 0x00F9B9E4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_115649()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 320 + 112));
}


// ========================================================================
// ?GetStrPtrType@idTypeInfoObject@@QBA_NABVidTypeInfoVariable_StrPtr@@AAVidStr@@_N@Z
// EA  : 0x82F9BA18
// RVA : 0x00F9BA18
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetStrPtrType(
        idTypeInfoObject *this,
        const idTypeInfoVariable_StrPtr *variable,
        idStr *s,
        bool resolvePtrs)
{
  __int64 v8; // r8
  __int64 v9; // r6
  int v10; // r4
  __int64 v12; // r8
  int v13; // r6
  int v14; // r5
  BOOL v15; // r30
  idStr v16; // [sp+50h] [-F0h] BYREF
  idTypeInfoFile v17; // [sp+70h] [-D0h] BYREF

  v16.len = 0;
  v16.allocedAndFlag = 20;
  v16.data = v16.baseBuffer;
  v16.baseBuffer[0] = 0;
  idTypeInfoFile::idTypeInfoFile(this: &v17, indent_: 0);
  LODWORD(v8) = (unsigned __int8)idTypeInfoObject::GetVariablePre(
                                   this,
                                   file: &v17,
                                   name: &v16,
                                   type: (char *)variable->type,
                                   ops: (char *)variable->ops,
                                   path: (char *)variable->path,
                                   resolvePtrs);
  if ( (_DWORD)v8 != 0 )
  {
    if ( (unsigned __int8)idTypeInfoFile::CheckNullPointer(this: &v17, a2: v10, a3: v9, a4: v8) != 0 )
      idStr::operator=(this: s, text: &byte_8200D768);
    else
      idTypeInfoFile::ReadStr(this: &v17, s, a3: v14, a4: v13, a5: v12);
    v15 = (_cntlzw(idTypeInfoFile::HadError(this: &v17)) & 0x20) != 0;
    idTypeInfoFile::~idTypeInfoFile(this: &v17);
    idStr::FreeData(this: &v16);
    return v15;
  }
  else
  {
    idTypeInfoFile::~idTypeInfoFile(this: &v17);
    idStr::FreeData(this: &v16);
    return false;
  }
}


// ========================================================================
// __unwind$117798
// EA  : 0x82F9BB08
// RVA : 0x00F9BB08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_117798()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 80));
}


// ========================================================================
// __unwind$117799
// EA  : 0x82F9BB30
// RVA : 0x00F9BB30
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_117799()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 320 + 112));
}


// ========================================================================
// ?GetTypeInfoObjectForListElement@idTypeInfoObject@@QBA_NABVidTypeInfoVariable_idList@@HAAV1@@Z
// EA  : 0x82F9BB58
// RVA : 0x00F9BB58
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetTypeInfoObjectForListElement(
        idTypeInfoObject *this,
        const idTypeInfoVariable_idList *variable,
        int index,
        idTypeInfoObject *object)
{
  __int64 v8; // r8
  __int64 v9; // r6
  unsigned int v10; // r10
  va *v11; // r3
  int v13; // [sp+8h] [-1078h]
  int v14; // [sp+Ch] [-1074h]
  int v15; // [sp+10h] [-1070h]
  int v16; // [sp+14h] [-106Ch]
  int v17; // [sp+18h] [-1068h]
  int v18; // [sp+1Ch] [-1064h]
  va v19; // [sp+50h] [-1030h] BYREF

  object->ti = this->ti;
  object->objectPtr = this->objectPtr;
  idStr::operator=(this: &object->objectType, text: (char *)variable->argType);
  LODWORD(v8) = &g_ThumbnailCaptureVS[702];
  object->modified = false;
  LODWORD(v9) = index;
  HIDWORD(v9) = variable->path;
  v11 = va::va(
          this: &v19,
          fmt: "%s[%d]",
          a3: v9,
          a4: v8,
          a5: v10,
          a6: v13,
          a7: v14,
          a8: v15,
          a9: v16,
          a10: v17,
          a11: v18);
  return idTypeInfoTools::GetPointerForPath(
           this: (idTypeInfoTools *)this->ti,
           typeName: this->objectType.data,
           path: v11->buffer,
           objectPtr: &object->objectPtr);
}


// ========================================================================
// ?GetStrType@idTypeInfoObject@@QBA_NPBD00AAVidStr@@_N@Z
// EA  : 0x82F9BBD8
// RVA : 0x00F9BBD8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetStrType(
        idTypeInfoObject *this,
        char *type,
        char *ops,
        char *path,
        idStr *s,
        bool resolvePtrs)
{
  __int64 v12; // r8
  int v13; // r6
  int v14; // r5
  BOOL v16; // r30
  idStr v17; // [sp+50h] [-100h] BYREF
  idTypeInfoFile v18; // [sp+70h] [-E0h] BYREF

  v17.len = 0;
  v17.allocedAndFlag = 20;
  v17.data = v17.baseBuffer;
  v17.baseBuffer[0] = 0;
  idTypeInfoFile::idTypeInfoFile(this: &v18, indent_: 0);
  LODWORD(v12) = (unsigned __int8)idTypeInfoObject::GetVariablePre(
                                    this,
                                    file: &v18,
                                    name: &v17,
                                    type,
                                    ops,
                                    path,
                                    resolvePtrs);
  if ( (_DWORD)v12 != 0 )
  {
    idTypeInfoFile::ReadStr(this: &v18, s, a3: v14, a4: v13, a5: v12);
    v16 = (_cntlzw(idTypeInfoFile::HadError(this: &v18)) & 0x20) != 0;
    idTypeInfoFile::~idTypeInfoFile(this: &v18);
    idStr::FreeData(this: &v17);
    return v16;
  }
  else
  {
    idTypeInfoFile::~idTypeInfoFile(this: &v18);
    idStr::FreeData(this: &v17);
    return false;
  }
}


// ========================================================================
// __unwind$118991
// EA  : 0x82F9BCA8
// RVA : 0x00F9BCA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_118991()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$118992
// EA  : 0x82F9BCD0
// RVA : 0x00F9BCD0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_118992()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 336 + 112));
}


// ========================================================================
// ?GetValueText@idTypeInfoObject@@QBA_NPBDAAVidStr@@@Z
// EA  : 0x82F9BD00
// RVA : 0x00F9BD00
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

int __fastcall idTypeInfoObject::GetValueText(idTypeInfoObject *this, const char *path, idStr *text)
{
  char *TypeInfoString; // r3
  idTypeInfoFile v8; // [sp+50h] [-D0h] BYREF

  idTypeInfoFile::idTypeInfoFile(this: &v8, indent_: 0);
  v8.settings.resolveEntityPointers = false;
  v8.settings.writeModifier = WRITE_DEF_AND_EDIT_ONLY;
  v8.settings.resolveModelPointers = false;
  v8.settings.writeComments = false;
  idTypeInfoFile::WriteMemoryFile(this: &v8);
  if ( idTypeInfoTools::WriteObjectVariable(
         this: (idTypeInfoTools *)this->ti,
         file: &v8,
         objectType: this->objectType.data,
         objectPtr: this->objectPtr,
         path) )
  {
    TypeInfoString = idTypeInfoFile::GetTypeInfoString(this: &v8);
    idStr::operator=(this: text, text: TypeInfoString);
    idTypeInfoFile::~idTypeInfoFile(this: &v8);
    return 1;
  }
  else
  {
    idTypeInfoFile::~idTypeInfoFile(this: &v8);
    return 0;
  }
}


// ========================================================================
// __unwind$119092
// EA  : 0x82F9BDA4
// RVA : 0x00F9BDA4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_119092()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 288 + 80));
}


// ========================================================================
// ?GetStr@idTypeInfoObject@@QBA_NABVidTypeInfoVariable_idStr@@AAVidStr@@@Z
// EA  : 0x82F9BDD0
// RVA : 0x00F9BDD0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetStr(idTypeInfoObject *this, const idTypeInfoVariable_idStr *variable, idStr *s)
{
  return idTypeInfoObject::GetStrType(
           this,
           type: (char *)variable->type,
           ops: &byte_8200D768,
           path: (char *)variable->path,
           s,
           resolvePtrs: true);
}


// ========================================================================
// ?GetListNum@idTypeInfoObject@@QBA_NABVidTypeInfoVariable_idList@@AAH@Z
// EA  : 0x82F9BDF8
// RVA : 0x00F9BDF8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

BOOL __fastcall idTypeInfoObject::GetListNum(
        idTypeInfoObject *this,
        const idTypeInfoVariable_idList *variable,
        __int64 num,
        __int64 a4,
        __int64 a5)
{
  unsigned int *v5; // r29
  va *v7; // r3
  BOOL Int; // r30
  int v10; // [sp+8h] [-1098h]
  int v11; // [sp+Ch] [-1094h]
  int v12; // [sp+10h] [-1090h]
  int v13; // [sp+14h] [-108Ch]
  int v14; // [sp+18h] [-1088h]
  int v15; // [sp+1Ch] [-1084h]
  idTypeInfoVariable_int v16; // [sp+50h] [-1050h] BYREF
  idStr v17; // [sp+60h] [-1040h] BYREF
  va v18; // [sp+80h] [-1020h] BYREF

  v5 = (unsigned int *)HIDWORD(num);
  HIDWORD(num) = variable->path;
  v7 = va::va(this: &v18, fmt: "%s.num", a3: num, a4, a5, a6: v10, a7: v11, a8: v12, a9: v13, a10: v14, a11: v15);
  idStr::idStr(this: &v17, text: v7);
  v16.type = "int";
  v16.ops = &byte_8200D768;
  v16.path = v17.data;
  Int = idTypeInfoObject::GetInt(this, variable: &v16, i: v5);
  idStr::FreeData(this: &v17);
  return Int;
}


// ========================================================================
// __unwind$119756_0
// EA  : 0x82F9BE7C
// RVA : 0x00F9BE7C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfoobject.cpp
// ========================================================================

void _unwind_119756_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 96));
}

