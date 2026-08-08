
// ========================================================================
// ?WriteBool@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9BEA8
// RVA : 0x00F9BEA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteBool(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const bool *a28)
{
  idTypeInfoFile::WriteBool(this: file, b: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadBool@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9BEF8
// RVA : 0x00F9BEF8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadBool(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        bool *a27)
{
  idTypeInfoFile::ReadBool(this: file, b: a27, a3: (int)scope, a4: (int)varType, a5: varName);
}


// ========================================================================
// ?WriteChar@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9BF08
// RVA : 0x00F9BF08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteChar(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        char *a28)
{
  idTypeInfoFile::WriteChar(this: file, c: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?WriteUnsignedChar@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9BF58
// RVA : 0x00F9BF58
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteUnsignedChar(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned __int8 *a28)
{
  idTypeInfoFile::WriteUnsignedChar(this: file, c: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadUnsignedChar@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9BFA8
// RVA : 0x00F9BFA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadUnsignedChar(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        __int64 varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        unsigned __int8 *a26)
{
  idTypeInfoFile::ReadUnsignedChar(this: file, c: a26, a3: varType, a4: varName);
}


// ========================================================================
// ?WriteWChar@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9BFB8
// RVA : 0x00F9BFB8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteWChar(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        wchar_t *a28)
{
  idTypeInfoFile::WriteWChar(this: file, w: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadWChar@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C008
// RVA : 0x00F9C008
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadWChar(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        __int64 varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        unsigned __int16 *a26)
{
  idTypeInfoFile::ReadWChar(this: file, s: a26, a3: varType, a4: varName);
}


// ========================================================================
// ?WriteShort@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C018
// RVA : 0x00F9C018
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteShort(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        __int16 *a28)
{
  idTypeInfoFile::WriteShort(this: file, s: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?WriteUnsignedShort@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C068
// RVA : 0x00F9C068
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteUnsignedShort(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned __int16 *a28)
{
  idTypeInfoFile::WriteUnsignedShort(this: file, s: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?WriteUnsignedLong@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C0B8
// RVA : 0x00F9C0B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteUnsignedLong(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int *a28)
{
  idTypeInfoFile::WriteUnsignedLong(this: file, l: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadUnsignedLong@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C108
// RVA : 0x00F9C108
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadUnsignedLong(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        __int64 varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        unsigned int *a26)
{
  idTypeInfoFile::ReadUnsignedLong(this: file, l: a26, a3: varType, a4: varName);
}


// ========================================================================
// ?WriteInt@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C118
// RVA : 0x00F9C118
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteInt(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int *a28)
{
  idTypeInfoFile::WriteInt(this: file, l: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?WriteFloat@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C168
// RVA : 0x00F9C168
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteFloat(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        long double a9,
        void *varPtr,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        float *a29)
{
  *(double *)&a9 = *a29;
  idTypeInfoFile::WriteFloat(this: file, d: a9);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadFloat@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C1B8
// RVA : 0x00F9C1B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadFloat(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        __int64 varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        float *a26)
{
  idTypeInfoFile::ReadFloat(this: file, f: a26, a3: varType, a4: varName);
}


// ========================================================================
// ?WriteDouble@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C1C8
// RVA : 0x00F9C1C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteDouble(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        long double a9,
        void *varPtr,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        _QWORD *a29)
{
  *(_QWORD *)&a9 = *a29;
  idTypeInfoFile::WriteFloat(this: file, d: a9);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadDouble@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C218
// RVA : 0x00F9C218
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadDouble(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        __int64 varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        long double *a26)
{
  idTypeInfoFile::ReadDouble(this: file, d: a26, a3: varType, a4: varName);
}


// ========================================================================
// ?WriteVecX@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C228
// RVA : 0x00F9C228
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteVecX(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idVecX *a28)
{
  idTypeInfoFile::WriteVecX(this: file, v: a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadVecX@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C278
// RVA : 0x00F9C278
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadVecX(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        __int64 varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        idVecX *a26)
{
  idTypeInfoFile::ReadVecX(this: file, v: a26, a3: varType, a4: varName);
}


// ========================================================================
// ?WriteMatX@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C288
// RVA : 0x00F9C288
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteMatX(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const idMatX *a28)
{
  idTypeInfoFile::WriteMatX(this: file, m: a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadMatX@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C2D8
// RVA : 0x00F9C2D8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadMatX(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        __int64 varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        idMatX *a26)
{
  idTypeInfoFile::ReadMatX(this: file, m: a26, a3: varType, a4: varName);
}


// ========================================================================
// ?ReadStr@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C2E8
// RVA : 0x00F9C2E8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadStr(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        idStr *a27)
{
  idTypeInfoFile::ReadStr(this: file, s: a27, a3: (int)scope, a4: (int)varType, a5: varName);
}


// ========================================================================
// ?WriteStrId@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C2F8
// RVA : 0x00F9C2F8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteStrId(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        idStrId *a28)
{
  char *Key; // r3

  Key = idStrId::GetKey(this: a28);
  idTypeInfoFile::WriteStr(this: file, s: Key);
}


// ========================================================================
// ?IsUninitializedType@idTypeInfoTools@@SA_NPBD0@Z
// EA  : 0x82F9C338
// RVA : 0x00F9C338
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::IsUninitializedType(const char *type, const char *ops)
{
  int v4; // r31
  const char **v5; // r11

  if ( *ops == 42 )
    return 1;
  v4 = 0;
  if ( uninitializedTypes[0] != nullptr )
  {
    v5 = uninitializedTypes;
    while ( idStr::Cmp(s1: *v5, s2: type) != 0 )
    {
      v5 = &uninitializedTypes[++v4];
      if ( *v5 == nullptr )
        return 0;
    }
    return 1;
  }
  return 0;
}


// ========================================================================
// ?FindEnumValueInfo@idTypeInfoTools@@QBAPBUenumValueInfo_t@@PBUenumTypeInfo_t@@PBD_N@Z
// EA  : 0x82F9C3B8
// RVA : 0x00F9C3B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const enumValueInfo_t *__fastcall idTypeInfoTools::FindEnumValueInfo(
        idTypeInfoTools *this,
        const enumTypeInfo_t *enumInfo,
        const char *name,
        const bool defaultIfNotFound)
{
  const enumValueInfo_t *values; // r11
  int v8; // r30
  int v9; // r31
  unsigned int v10; // r3

  values = enumInfo->values;
  v8 = 0;
  if ( values->name == nullptr )
    return !defaultIfNotFound ? nullptr : values;
  v9 = 0;
  while ( 1 )
  {
    v10 = idStr::Cmp(s1: name, s2: values[v9].name);
    values = enumInfo->values;
    if ( v10 == 0 )
      break;
    v9 = ++v8;
    if ( values[v8].name == nullptr )
      return !defaultIfNotFound ? nullptr : values;
  }
  return &values[v9];
}


// ========================================================================
// ?FindEnumValueInfo@idTypeInfoTools@@QBAPBUenumValueInfo_t@@PBUenumTypeInfo_t@@H@Z
// EA  : 0x82F9C438
// RVA : 0x00F9C438
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const enumValueInfo_t *__fastcall idTypeInfoTools::FindEnumValueInfo(
        idTypeInfoTools *this,
        const enumTypeInfo_t *enumInfo,
        const int value)
{
  const enumValueInfo_t *values; // r9
  int v4; // r11
  const enumValueInfo_t *result; // r3

  values = enumInfo->values;
  v4 = 0;
  if ( values->name == nullptr )
    return nullptr;
  result = enumInfo->values;
  while ( result->value != value )
  {
    result = &values[++v4];
    if ( result->name == nullptr )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?FindClassVariableInfo@idTypeInfoTools@@QBAPBUclassVariableInfo_t@@PBUclassTypeInfo_t@@PBD@Z
// EA  : 0x82F9C480
// RVA : 0x00F9C480
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const classVariableInfo_t *__fastcall idTypeInfoTools::FindClassVariableInfo(
        idTypeInfoTools *this,
        const classTypeInfo_t *classInfo,
        const char *name)
{
  const classVariableInfo_t *variables; // r11
  int v6; // r31
  int v7; // r30
  unsigned int v8; // r3
  const classVariableInfo_t *v9; // r11
  const char *v10; // r8

  if ( classInfo == nullptr )
    return nullptr;
  variables = classInfo->variables;
  if ( variables == nullptr )
    return nullptr;
  v6 = 0;
  if ( variables->name == nullptr )
    return nullptr;
  v7 = 0;
  while ( 1 )
  {
    v8 = idStr::Cmp(s1: name, s2: variables->name);
    v9 = classInfo->variables;
    if ( v8 == 0 )
      break;
    v7 = ++v6;
    v10 = v9[v6].name;
    variables = &v9[v6];
    if ( v10 == nullptr )
      return nullptr;
  }
  return &v9[v7];
}


// ========================================================================
// ?FindTypeDefIndex@idTypeInfoTools@@QBAHPBD@Z
// EA  : 0x82F9C518
// RVA : 0x00F9C518
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::FindTypeDefIndex(idTypeInfoTools *this, const char *typeName)
{
  int v4; // r31
  typedefInfo_t *typedefs; // r11
  int v6; // r10

  v4 = 0;
  typedefs = this->typeInfo->typedefs;
  if ( typedefs->name == nullptr )
    return -1;
  v6 = 0;
  while ( idStr::Cmp(s1: typeName, s2: typedefs[v6].name) != 0 )
  {
    v6 = ++v4;
    typedefs = this->typeInfo->typedefs;
    if ( typedefs[v4].name == nullptr )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?WriteBitField@idTypeInfoTools@@ABAXPAVidTypeInfoFile@@PBD111H1PAXP6AH2@Z@Z
// EA  : 0x82F9C590
// RVA : 0x00F9C590
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::WriteBitField(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int (__fastcall *getVar)(void *),
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int (__fastcall *a30)(int))
{
  int v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  __int64 v36; // r6
  int v37; // r3
  int v38; // [sp+8h] [-68h]
  int v39; // [sp+Ch] [-64h]
  int v40; // [sp+10h] [-60h]
  int v41; // [sp+14h] [-5Ch]
  int v42; // [sp+18h] [-58h]
  int v43; // [sp+1Ch] [-54h]

  if ( idStr::Cmp(s1: varType, s2: "bool") != 0 )
  {
    if ( idStr::Cmp(s1: varType, s2: "int") != 0 && idStr::Cmp(s1: varType, s2: "unsigned int") != 0 )
    {
      idTypeInfoFile::Error(
        this: file,
        str: "bit field must be either 'bool' or 'int'",
        a3: v36,
        a4: v35,
        a5: v34,
        a6: v38,
        a7: v39,
        a8: v40,
        a9: v41,
        a10: v42,
        a11: v43);
    }
    else
    {
      v37 = a30(a1: a28);
      idTypeInfoFile::WriteInt(this: file, l: v37);
      idTypeInfoFile::WriteComment(this: file, comment);
    }
  }
  else
  {
    v33 = a30(a1: a28);
    idTypeInfoFile::WriteBool(this: file, b: v33 != 0);
    idTypeInfoFile::WriteComment(this: file, comment);
  }
}


// ========================================================================
// ?WriteClassVariables@idTypeInfoTools@@ABAXPAVidTypeInfoFile@@PBUclassTypeInfo_t@@PAX@Z
// EA  : 0x82F9C670
// RVA : 0x00F9C670
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::WriteClassVariables(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const classTypeInfo_t *classInfo,
        int varPtr)
{
  const classVariableInfo_t *variables; // r11
  int v9; // r25
  int v10; // r10
  const classVariableInfo_t *v11; // r31
  int flags; // r11
  int v13; // r10
  const char *type; // r4
  char *name; // r6
  const char *ops; // r5
  void *v17; // [sp+8h] [-A8h]
  int (__fastcall *v18)(void *); // [sp+Ch] [-A4h]
  int v19; // [sp+10h] [-A0h]
  int v20; // [sp+14h] [-9Ch]
  int v21; // [sp+18h] [-98h]
  int v22; // [sp+1Ch] [-94h]
  int v23; // [sp+20h] [-90h]
  int v24; // [sp+24h] [-8Ch]
  int v25; // [sp+28h] [-88h]
  int v26; // [sp+2Ch] [-84h]
  int v27; // [sp+30h] [-80h]
  int v28; // [sp+34h] [-7Ch]
  int v29; // [sp+38h] [-78h]
  int v30; // [sp+3Ch] [-74h]
  int v31; // [sp+40h] [-70h]
  int v32; // [sp+44h] [-6Ch]
  int v33; // [sp+48h] [-68h]
  int v34; // [sp+4Ch] [-64h]
  int v35; // [sp+50h] [-60h]
  int v36; // [sp+58h] [-58h]

  variables = classInfo->variables;
  v9 = 0;
  if ( variables->name != nullptr )
  {
    v10 = 0;
    do
    {
      v11 = &variables[v10];
      flags = variables[v10].flags;
      if ( (flags & 0x20000) == 0 )
      {
        if ( file->settings.writeModifier == WRITE_DEF_AND_EDIT_ONLY )
        {
          v13 = flags & 0x380000;
        }
        else
        {
          if ( file->settings.writeModifier != WRITE_EDIT_ONLY )
            goto LABEL_9;
          v13 = flags & 0x80000;
        }
        if ( v13 != 0 )
        {
LABEL_9:
          if ( (flags & 0x80000) != 0 )
            ++this->editDepth;
          if ( (v11->flags & 0x100000) != 0 )
            ++this->designDepth;
          if ( (v11->flags & 0x200000) != 0 )
            ++this->defDepth;
          type = v11->type;
          name = (char *)v11->name;
          ops = v11->ops;
          if ( v11->size >= 0 )
          {
            idTypeInfoFile::WriteType(this: file, type, ops, name);
            idTypeInfoTools::WriteType_r(
              this,
              file,
              scope: classInfo->name,
              varType: v11->type,
              varOps: v11->ops,
              varName: v11->name,
              varFlags: v11->flags,
              comment: v11->comment,
              varPtr: v17,
              allowSpecialCase: (bool)v18);
          }
          else
          {
            idTypeInfoFile::WriteType(this: file, type, ops, name);
            idTypeInfoTools::WriteBitField(
              this,
              file,
              scope: classInfo->name,
              varType: v11->type,
              varOps: v11->ops,
              varName: v11->name,
              varFlags: v11->flags,
              comment: v11->comment,
              varPtr: v17,
              getVar: v18,
              a11: v19,
              a12: v20,
              a13: v21,
              a14: v22,
              a15: v23,
              a16: v24,
              a17: v25,
              a18: v26,
              a19: v27,
              a20: v28,
              a21: v29,
              a22: v30,
              a23: v31,
              a24: v32,
              a25: v33,
              a26: v34,
              a27: v35,
              a28: varPtr,
              a29: v36,
              a30: (int (__fastcall *)(int))v11->get);
          }
          if ( (v11->flags & 0x80000) != 0 )
            --this->editDepth;
          if ( (v11->flags & 0x100000) != 0 )
            --this->designDepth;
          if ( (v11->flags & 0x200000) != 0 )
            --this->defDepth;
        }
      }
      ++v9;
      variables = classInfo->variables;
      v10 = v9;
    }
    while ( variables[v9].name != nullptr );
  }
}


// ========================================================================
// ?ReadBitField@idTypeInfoTools@@ABAXPAVidTypeInfoFile@@PBD111H1PAXP6AX2H@Z@Z
// EA  : 0x82F9C840
// RVA : 0x00F9C840
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::ReadBitField(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        void (__fastcall *setVar)(void *, int),
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        void (__fastcall *a30)(int, unsigned int))
{
  __int64 v32; // r8
  int v33; // r6
  int v34; // r5
  unsigned int v35; // r4
  __int64 v36; // r8
  __int64 v37; // r6
  __int64 v38; // r10
  int v39; // [sp+8h] [-68h]
  int v40; // [sp+Ch] [-64h]
  int v41; // [sp+10h] [-60h]
  int v42; // [sp+14h] [-5Ch]
  int v43; // [sp+18h] [-58h]
  int v44; // [sp+1Ch] [-54h]
  bool v45; // [sp+50h] [-20h] BYREF
  unsigned int v46; // [sp+54h] [-1Ch] BYREF

  if ( idStr::Cmp(s1: varType, s2: "bool") != 0 )
  {
    if ( idStr::Cmp(s1: varType, s2: "int") != 0 && idStr::Cmp(s1: varType, s2: "unsigned int") != 0 )
    {
      idTypeInfoFile::Error(
        this: file,
        str: "bit field must be either 'bool' or 'int'",
        a3: v37,
        a4: v36,
        a5: v38,
        a6: v39,
        a7: v40,
        a8: v41,
        a9: v42,
        a10: v43,
        a11: v44);
      return;
    }
    idTypeInfoFile::ReadUnsignedLong(this: file, l: &v46, a3: v37, a4: v36);
    v35 = v46;
  }
  else
  {
    idTypeInfoFile::ReadBool(this: file, b: &v45, a3: v34, a4: v33, a5: v32);
    v35 = v45;
  }
  a30(a1: a28, a2: v35);
}


// ========================================================================
// ?WriteStr@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C908
// RVA : 0x00F9C908
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteStr(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  idTypeInfoFile::WriteStr(this: file, s: *(const char **)(a28 + 4));
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadStrId@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C960
// RVA : 0x00F9C960
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadStrId(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        idStrId *a27)
{
  idStr v27; // [sp+50h] [-30h] BYREF

  v27.len = 0;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v27.baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: &v27, a3: (int)scope, a4: (int)varType, a5: varName);
  idStrId::Set(this: a27, key: v27.data);
  idStr::FreeData(this: &v27);
}


// ========================================================================
// __unwind$114209_0
// EA  : 0x82F9C9C4
// RVA : 0x00F9C9C4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_114209_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?WriteAtomicString@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9C9F0
// RVA : 0x00F9C9F0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall WriteAtomicString(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        const char **a28)
{
  idTypeInfoFile::WriteStr(this: file, s: *a28);
  idTypeInfoFile::WriteComment(this: file, comment);
}


// ========================================================================
// ?ReadAtomicString@@YAXPBVidTypeInfoTools@@PAVidTypeInfoFile@@PBD222H2PAX@Z
// EA  : 0x82F9CA48
// RVA : 0x00F9CA48
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall ReadAtomicString(
        const idTypeInfoTools *ti,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        idAtomicString *a27)
{
  idStr v27; // [sp+50h] [-30h] BYREF

  v27.len = 0;
  v27.allocedAndFlag = 20;
  v27.data = v27.baseBuffer;
  v27.baseBuffer[0] = 0;
  idTypeInfoFile::ReadStr(this: file, s: &v27, a3: (int)scope, a4: (int)varType, a5: varName);
  idAtomicString::Set(this: a27, str_: v27.data);
  idStr::FreeData(this: &v27);
}


// ========================================================================
// __unwind$114278
// EA  : 0x82F9CAAC
// RVA : 0x00F9CAAC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_114278()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 128 + 80));
}


// ========================================================================
// ?StripArraySize@idTypeInfoTools@@ABAHAAVidStr@@@Z
// EA  : 0x82F9CAD8
// RVA : 0x00F9CAD8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::StripArraySize(idTypeInfoTools *this, idStr *ops)
{
  int v3; // r29
  int v4; // r31
  int i; // r11
  char v6; // r9
  int v7; // r3

  v3 = 1;
  do
  {
    v4 = 0;
    for ( i = idStr::Last(this: ops, c: 91, index: -1) + 1; i < ops->len - 1; v4 = v6 + 10 * v4 - 48 )
      v6 = ops->data[i++];
    v3 *= v4;
    v7 = idStr::Last(this: ops, c: 91, index: -1);
    if ( ops->len > v7 && v7 >= 0 )
    {
      ops->data[v7] = 0;
      ops->len = v7;
    }
  }
  while ( ops->len != 0 && ops->data[ops->len - 1] == 93 );
  return v3;
}


// ========================================================================
// ?ReadFunctionPointer@idTypeInfoTools@@ABAHPAVidTypeInfoFile@@PBD111H1PAX@Z
// EA  : 0x82F9CBB8
// RVA : 0x00F9CBB8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::ReadFunctionPointer(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        __int64 varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        void **a27)
{
  int v27; // r30
  functionPointerInfo_t *functionPointers; // r11
  int v30; // r10
  functionPointerInfo_t *v31; // r11
  idStr v33[2]; // [sp+50h] [-40h] BYREF

  v27 = 0;
  v33[0].len = 0;
  v33[0].baseBuffer[0] = 0;
  v33[0].allocedAndFlag = 20;
  v33[0].data = v33[0].baseBuffer;
  idTypeInfoFile::ReadStr(this: file, s: v33, a3: (int)scope, a4: (int)varType, a5: varName);
  functionPointers = this->typeInfo->functionPointers;
  if ( functionPointers->name != nullptr )
  {
    v30 = 0;
    do
    {
      if ( idStr::Cmp(s1: v33[0].data, s2: functionPointers[v30].name) == 0 )
        break;
      v30 = ++v27;
      functionPointers = this->typeInfo->functionPointers;
    }
    while ( functionPointers[v27].name != nullptr );
  }
  v31 = &this->typeInfo->functionPointers[v27];
  if ( v31->name != nullptr )
    *a27 = v31->ptr;
  idStr::FreeData(this: v33);
  return 4;
}


// ========================================================================
// __unwind$114398
// EA  : 0x82F9CC78
// RVA : 0x00F9CC78
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_114398()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?FindEnumIndex@idTypeInfoTools@@QBAHPBD@Z
// EA  : 0x82F9CCA0
// RVA : 0x00F9CCA0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::FindEnumIndex(idTypeInfoTools *this, const char *typeName)
{
  idHashIndex *p_enumHash; // r30
  int v5; // r31

  p_enumHash = &this->enumHash;
  v5 = this->enumHash.hash[idHashIndex::GenerateKeyForString(
                             this: &this->enumHash,
                             string: typeName,
                             caseSensitive: true)
                         & this->enumHash.hashMask
                         & this->enumHash.lookupMask];
  if ( v5 == -1 )
    return -1;
  while ( idStr::Cmp(s1: typeName, s2: this->typeInfo->enums[v5].name) != 0 )
  {
    v5 = p_enumHash->indexChain[p_enumHash->lookupMask & v5];
    if ( v5 == -1 )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?FindEnumInfo@idTypeInfoTools@@QBAPBUenumTypeInfo_t@@PBD@Z
// EA  : 0x82F9CD48
// RVA : 0x00F9CD48
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const enumTypeInfo_t *__fastcall idTypeInfoTools::FindEnumInfo(idTypeInfoTools *this, const char *typeName)
{
  idHashIndex *p_enumHash; // r29
  int v5; // r31

  p_enumHash = &this->enumHash;
  v5 = this->enumHash.hash[idHashIndex::GenerateKeyForString(
                             this: &this->enumHash,
                             string: typeName,
                             caseSensitive: true)
                         & this->enumHash.hashMask
                         & this->enumHash.lookupMask];
  if ( v5 == -1 )
    return nullptr;
  while ( idStr::Cmp(s1: typeName, s2: this->typeInfo->enums[v5].name) != 0 )
  {
    v5 = p_enumHash->indexChain[p_enumHash->lookupMask & v5];
    if ( v5 == -1 )
      return nullptr;
  }
  return &this->typeInfo->enums[v5];
}


// ========================================================================
// ?FindEnumValueInfo@idTypeInfoTools@@QBAPBUenumValueInfo_t@@PBDH_N@Z
// EA  : 0x82F9CDF8
// RVA : 0x00F9CDF8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const enumValueInfo_t *__fastcall idTypeInfoTools::FindEnumValueInfo(
        idTypeInfoTools *this,
        const char *enumName,
        const int value,
        const bool defaultIfNotFound)
{
  const enumValueInfo_t *result; // r3
  const char *name; // r9
  int v8; // r11

  result = (const enumValueInfo_t *)idTypeInfoTools::FindEnumInfo(this, typeName: enumName);
  if ( result != nullptr )
  {
    name = result[1].name;
    v8 = 0;
    if ( *(_DWORD *)name == 0 )
      return !defaultIfNotFound ? nullptr : (const enumValueInfo_t *)name;
    result = (const enumValueInfo_t *)result[1].name;
    while ( result->value != value )
    {
      ++v8;
      result = (const enumValueInfo_t *)&name[8 * v8];
      if ( result->name == nullptr )
        return !defaultIfNotFound ? nullptr : (const enumValueInfo_t *)name;
    }
    if ( result == nullptr )
      return !defaultIfNotFound ? nullptr : (const enumValueInfo_t *)name;
  }
  return result;
}


// ========================================================================
// ?FindEnumValueName@idTypeInfoTools@@QBAPBDPBDH@Z
// EA  : 0x82F9CE90
// RVA : 0x00F9CE90
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const char *__fastcall idTypeInfoTools::FindEnumValueName(idTypeInfoTools *this, const char *enumTypeName, int value)
{
  const enumValueInfo_t *EnumValueInfo; // r3
  const char *result; // r3

  EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(this, enumName: enumTypeName, value, defaultIfNotFound: false);
  if ( EnumValueInfo == nullptr )
    return "unknown";
  result = EnumValueInfo->name;
  if ( result == nullptr )
    return "unknown";
  return result;
}


// ========================================================================
// ?FindEnumValue@idTypeInfoTools@@QBAHPBD0H@Z
// EA  : 0x82F9CED0
// RVA : 0x00F9CED0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::FindEnumValue(
        idTypeInfoTools *this,
        const char *enumTypeName,
        const char *name,
        const int defaultValue)
{
  const enumTypeInfo_t *EnumInfo; // r4
  const enumValueInfo_t *EnumValueInfo; // r3

  EnumInfo = idTypeInfoTools::FindEnumInfo(this, typeName: enumTypeName);
  if ( EnumInfo != nullptr
    && (EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(this, enumInfo: EnumInfo, name, defaultIfNotFound: false)) != nullptr )
  {
    return EnumValueInfo->value;
  }
  else
  {
    return defaultValue;
  }
}


// ========================================================================
// ?FindClassIndex@idTypeInfoTools@@QBAHPBD@Z
// EA  : 0x82F9CF28
// RVA : 0x00F9CF28
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::FindClassIndex(idTypeInfoTools *this, const char *typeName)
{
  idHashIndex *p_classHash; // r30
  int v5; // r31
  int v6; // r11

  p_classHash = &this->classHash;
  v5 = this->classHash.hash[idHashIndex::GenerateKeyForString(
                              this: &this->classHash,
                              string: typeName,
                              caseSensitive: true)
                          & this->classHash.hashMask
                          & this->classHash.lookupMask];
  if ( v5 == -1 )
    return -1;
  v6 = v5;
  while ( idStr::Cmp(s1: typeName, s2: this->typeInfo->classes[v6].name) != 0 )
  {
    v5 = p_classHash->indexChain[p_classHash->lookupMask & v5];
    v6 = v5;
    if ( v5 == -1 )
      return -1;
  }
  return v5;
}


// ========================================================================
// ?FindClassInfo@idTypeInfoTools@@QBAPBUclassTypeInfo_t@@PBD@Z
// EA  : 0x82F9CFC8
// RVA : 0x00F9CFC8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const classTypeInfo_t *__fastcall idTypeInfoTools::FindClassInfo(idTypeInfoTools *this, const char *typeName)
{
  idHashIndex *p_classHash; // r30
  int v5; // r31

  if ( typeName == nullptr )
    return nullptr;
  if ( *typeName == 0 )
    return nullptr;
  p_classHash = &this->classHash;
  v5 = this->classHash.hash[idHashIndex::GenerateKeyForString(
                              this: &this->classHash,
                              string: typeName,
                              caseSensitive: true)
                          & this->classHash.hashMask
                          & this->classHash.lookupMask];
  if ( v5 == -1 )
    return nullptr;
  while ( idStr::Cmp(s1: typeName, s2: this->typeInfo->classes[v5].name) != 0 )
  {
    v5 = p_classHash->indexChain[p_classHash->lookupMask & v5];
    if ( v5 == -1 )
      return nullptr;
  }
  return &this->typeInfo->classes[v5];
}


// ========================================================================
// ?SizeForType@idTypeInfoTools@@ABAHPBD0@Z
// EA  : 0x82F9D088
// RVA : 0x00F9D088
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::SizeForType(idTypeInfoTools *this, const char *varType, const char *varOps)
{
  int len; // r11
  char *data; // r10
  int v7; // r3
  int v8; // r29
  const classTypeInfo_t *ClassInfo; // r3
  int v10; // r30
  idStr v12[2]; // [sp+50h] [-50h] BYREF

  idStr::idStr(this: v12, text: varOps);
  len = v12[0].len;
  data = v12[0].data;
  if ( v12[0].len != 0 && v12[0].data[v12[0].len - 1] == 93 )
  {
    v7 = idTypeInfoTools::StripArraySize(this, ops: v12);
    data = v12[0].data;
    len = v12[0].len;
    v8 = v7;
  }
  else
  {
    v8 = 1;
  }
  if ( len != 0 )
  {
    if ( *data == 42 && data[1] == 0 )
    {
LABEL_9:
      idStr::FreeData(this: v12);
      return 4 * v8;
    }
  }
  else
  {
    ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: varType);
    if ( ClassInfo != nullptr )
    {
      v10 = ClassInfo->size * v8;
      idStr::FreeData(this: v12);
      return v10;
    }
    if ( idTypeInfoTools::FindEnumInfo(this, typeName: varType) != nullptr )
      goto LABEL_9;
  }
  idStr::FreeData(this: v12);
  return -1;
}


// ========================================================================
// __unwind$114878
// EA  : 0x82F9D188
// RVA : 0x00F9D188
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_114878()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?WriteArray@idTypeInfoTools@@QBAHPAVidTypeInfoFile@@PBD111H1PAXH@Z
// EA  : 0x82F9D1B0
// RVA : 0x00F9D1B0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::WriteArray(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int num,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30)
{
  int v37; // r26
  __int64 v38; // r10
  __int64 v39; // r8
  int v40; // r31
  __int64 v42; // r6
  void *v44; // [sp+8h] [-C8h]
  int v45; // [sp+Ch] [-C4h]
  int v46; // [sp+10h] [-C0h]
  int v47; // [sp+14h] [-BCh]
  int v48; // [sp+18h] [-B8h]
  int v49; // [sp+1Ch] [-B4h]

  v37 = idTypeInfoTools::SizeForType(this, varType, varOps);
  v40 = 0;
  if ( a30 > 0 )
  {
    while ( 1 )
    {
      HIDWORD(v39) = v40;
      idTypeInfoFile::WriteArrayElementType(this: file, type: varType, ops: varOps, name: varName, i: v39, a6: v38);
      if ( idTypeInfoTools::WriteType_r(
             this,
             file,
             scope,
             varType,
             varOps,
             varName,
             varFlags,
             comment: &byte_8200D768,
             varPtr: v44,
             allowSpecialCase: v45) != v37 )
        break;
      ++v40;
      a28 += v37;
      if ( v40 >= a30 )
        return v37 * a30;
    }
    HIDWORD(v42) = v40;
    idTypeInfoFile::Error(
      this: file,
      str: "couldn't read array element %d",
      a3: v42,
      a4: v39,
      a5: v38,
      a6: (int)v44,
      a7: v45,
      a8: v46,
      a9: v47,
      a10: v48,
      a11: v49);
  }
  return v37 * a30;
}


// ========================================================================
// ?WriteSuperClassVariables@idTypeInfoTools@@ABAXPAVidTypeInfoFile@@PBUclassTypeInfo_t@@PAX@Z
// EA  : 0x82F9D290
// RVA : 0x00F9D290
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::WriteSuperClassVariables(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const classTypeInfo_t *superInfo,
        void *varPtr)
{
  const char *superType; // r4
  const classTypeInfo_t *ClassInfo; // r3

  if ( superInfo != nullptr )
  {
    superType = superInfo->superType;
    if ( *superType != 0 )
    {
      ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: superType);
      idTypeInfoTools::WriteSuperClassVariables(this, file, superInfo: ClassInfo, varPtr);
    }
    idTypeInfoTools::WriteClassVariables(this, file, classInfo: superInfo, (int)varPtr);
  }
}


// ========================================================================
// ?ReadArray@idTypeInfoTools@@QBAHPAVidTypeInfoFile@@PBD111H1PAXH@Z
// EA  : 0x82F9D300
// RVA : 0x00F9D300
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::ReadArray(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        char *varType,
        char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int num,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30)
{
  int v37; // r25
  __int64 v38; // r8
  __int64 v39; // r6
  int v40; // r4
  __int64 v41; // r8
  __int64 v42; // r10
  __int64 v43; // r8
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r6
  int v48; // r4
  int Type_r; // r3
  __int64 v51; // r8
  __int64 v52; // r6
  int v53; // r4
  void *v54; // [sp+8h] [-138h]
  int v55; // [sp+Ch] [-134h]
  int v56; // [sp+10h] [-130h]
  int v57; // [sp+14h] [-12Ch]
  int v58; // [sp+18h] [-128h]
  int v59; // [sp+1Ch] [-124h]
  int v60; // [sp+60h] [-E0h] BYREF
  idStr v61; // [sp+70h] [-D0h] BYREF
  int v62; // [sp+A4h] [-9Ch]
  float v63; // [sp+A8h] [-98h]
  int v64; // [sp+ACh] [-94h]
  int v65; // [sp+B0h] [-90h]
  int v66; // [sp+B4h] [-8Ch]

  v63 = -3.4028235e38;
  v61.len = 0;
  v61.allocedAndFlag = 20;
  v61.data = v61.baseBuffer;
  v61.baseBuffer[0] = 0;
  v62 = 0;
  v64 = 0;
  v65 = 0;
  v66 = 0;
  v37 = idTypeInfoTools::SizeForType(this, varType, varOps);
  if ( !idTypeInfoFile::PeekClosingBrace(this: file, a2: v40, a3: v39, a4: v38) )
  {
    while ( !idTypeInfoFile::HadError(this: file) )
    {
      HIDWORD(v41) = &v60;
      idTypeInfoFile::ExpectArrayElementType(this: file, type: varType, ops: varOps, name: varName, index: v41);
      HIDWORD(v44) = v60;
      if ( v60 < 0 || v60 >= a30 )
      {
        idTypeInfoFile::Warning(
          this: file,
          str: "array element %d out of range",
          a3: v44,
          a4: v43,
          a5: v42,
          a6: (int)v54,
          a7: v55,
          a8: v56,
          a9: v57,
          a10: v58,
          a11: v59);
        idTypeInfoFile::ReadUnknown(this: file, a2: v53, a3: v52, a4: v51);
      }
      else
      {
        Type_r = idTypeInfoTools::ReadType_r(
                   this,
                   file,
                   scope,
                   varType,
                   varOps,
                   varName,
                   varFlags,
                   comment: &byte_8200D768,
                   varPtr: v54,
                   allowSpecialCase: v55);
        if ( Type_r == -1 )
        {
          HIDWORD(v47) = v60;
          idTypeInfoFile::Warning(
            this: file,
            str: "couldn't read unknown array element %d",
            a3: v47,
            a4: v46,
            a5: v45,
            a6: (int)v54,
            a7: v55,
            a8: v56,
            a9: v57,
            a10: v58,
            a11: v59);
        }
        else if ( Type_r != v37 )
        {
          HIDWORD(v47) = v60;
          idTypeInfoFile::Error(
            this: file,
            str: "couldn't read array element %d",
            a3: v47,
            a4: v46,
            a5: v45,
            a6: (int)v54,
            a7: v55,
            a8: v56,
            a9: v57,
            a10: v58,
            a11: v59);
          break;
        }
      }
      if ( idTypeInfoFile::PeekClosingBrace(this: file, a2: v48, a3: v47, a4: v46) )
        break;
    }
  }
  idStr::FreeData(this: &v61);
  return v37 * a30;
}


// ========================================================================
// __unwind$115053
// EA  : 0x82F9D49C
// RVA : 0x00F9D49C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_115053()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// ?ReadObject_r@idTypeInfoTools@@ABAHPAVidTypeInfoFile@@PBD111H1PAX_N@Z
// EA  : 0x82F9D4D0
// RVA : 0x00F9D4D0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::ReadObject_r(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        bool allowSpecialCase,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int *a28,
        int a29,
        char a30)
{
  __int64 v38; // r8
  __int64 v39; // r6
  int v40; // r4
  int ClassIndex; // r3
  int v42; // r30
  classTypeInfo_t *v43; // r27
  __int64 v44; // r8
  __int64 v45; // r6
  int v46; // r4
  void (__fastcall *v48)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *); // r11
  __int64 v49; // r8
  __int64 v50; // r6
  int v51; // r4
  __int64 v52; // r6
  const classVariableInfo_t *ClassVariableInfo; // r30
  __int64 v54; // r10
  __int64 v55; // r8
  const classTypeInfo_t *ClassInfo; // r29
  int flags; // r11
  __int64 v58; // r6
  const char *v59; // r10
  int v60; // r9
  const char *name; // r8
  const char *ops; // r7
  const char *type; // r6
  const char *v64; // r5
  __int64 v65; // r8
  __int64 v66; // r6
  int v67; // r4
  __int64 v68; // r8
  __int64 v69; // r6
  int v70; // r4
  int EnumIndex; // r30
  __int64 v72; // r8
  __int64 v73; // r6
  int v74; // r4
  enumTypeInfo_t *v75; // r27
  __int64 v76; // r8
  __int64 v77; // r6
  int v78; // r4
  void (__fastcall *Read)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *); // r11
  char *data; // r3
  char v81; // r9
  char *v82; // r29
  char v83; // r30
  int i; // r11
  __int64 v85; // r10
  __int64 v86; // r8
  const enumValueInfo_t *EnumValueInfo; // r3
  __int64 v88; // r10
  __int64 v89; // r8
  const enumValueInfo_t *v90; // r3
  int value; // r11
  const enumValueInfo_t *values; // r9
  int v93; // r30
  int v94; // r11
  const enumValueInfo_t *v95; // r10
  int v96; // r3
  int v97; // r3
  int v98; // r11
  void *v99; // [sp+8h] [-1A8h]
  void (__fastcall *v100)(void *, int); // [sp+Ch] [-1A4h]
  int v101; // [sp+10h] [-1A0h]
  int v102; // [sp+14h] [-19Ch]
  int v103; // [sp+18h] [-198h]
  int v104; // [sp+1Ch] [-194h]
  int v105; // [sp+20h] [-190h]
  int v106; // [sp+24h] [-18Ch]
  int v107; // [sp+28h] [-188h]
  int v108; // [sp+2Ch] [-184h]
  int v109; // [sp+30h] [-180h]
  int v110; // [sp+34h] [-17Ch]
  int v111; // [sp+38h] [-178h]
  int v112; // [sp+3Ch] [-174h]
  int v113; // [sp+40h] [-170h]
  int v114; // [sp+44h] [-16Ch]
  int v115; // [sp+48h] [-168h]
  int v116; // [sp+4Ch] [-164h]
  int v117; // [sp+50h] [-160h]
  int v118; // [sp+58h] [-158h]
  idStr v119; // [sp+70h] [-140h] BYREF
  idStr v120; // [sp+90h] [-120h] BYREF
  idStr v121; // [sp+B0h] [-100h] BYREF
  int v122; // [sp+E4h] [-CCh]
  float v123; // [sp+E8h] [-C8h]
  int v124; // [sp+ECh] [-C4h]
  int v125; // [sp+F0h] [-C0h]
  int v126; // [sp+F4h] [-BCh]
  idStr v127; // [sp+100h] [-B0h] BYREF
  idStr v128[4]; // [sp+120h] [-90h] BYREF

  ClassIndex = idTypeInfoTools::FindClassIndex(this, typeName: varType);
  v42 = ClassIndex;
  if ( ClassIndex == -1 )
  {
    EnumIndex = idTypeInfoTools::FindEnumIndex(this, typeName: varType);
    if ( EnumIndex == -1 )
    {
      idTypeInfoFile::ReadUnknown(this: file, a2: v74, a3: v73, a4: v72);
      return -1;
    }
    LODWORD(v72) = 3 * EnumIndex;
    v75 = &this->typeInfo->enums[EnumIndex];
    HIDWORD(v76) = idTypeInfoFile::CheckSkipObject(this: file, a2: v74, a3: v73, a4: v72);
    if ( HIDWORD(v76) != 0 && file->settings.skipMarkedObjects )
    {
      idTypeInfoFile::ReadUnknown(this: file, a2: v78, a3: v77, a4: v76);
      return 4;
    }
    if ( a30 != 0 )
    {
      Read = this->enumObject.list[EnumIndex].Read;
      if ( Read != nullptr )
      {
        ((void (__fastcall *)(idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *))Read)(
          a1: this,
          a2: file,
          a3: scope,
          a4: varType,
          a5: varOps,
          a6: varName,
          a7: varFlags,
          a8: comment);
        return 4;
      }
    }
    v121.len = 0;
    v121.allocedAndFlag = 20;
    v121.data = v121.baseBuffer;
    v123 = -3.4028235e38;
    v121.baseBuffer[0] = 0;
    v122 = 0;
    v124 = 0;
    v125 = 0;
    v126 = 0;
    idTypeInfoFile::ReadStr(this: file, s: &v121, a3: SHIDWORD(v77), a4: v77, a5: v76);
    data = v121.data;
    v81 = *v121.data;
    if ( *v121.data == 45 || v81 >= 48 && v81 <= 57 )
    {
      if ( (v75->flags & 0x400000) != 0 )
      {
        values = v75->values;
        v93 = 0;
        v94 = 0;
        if ( values->name != nullptr )
        {
          v95 = v75->values;
          do
          {
            ++v94;
            v93 |= v95->value;
            v95 = &values[v94];
          }
          while ( v95->name != nullptr );
        }
        v96 = atol(nptr: v121.data);
        if ( (v96 & ~v93) == 0 )
        {
          *a28 = v96;
LABEL_64:
          idStr::FreeData(this: &v121);
          return 4;
        }
      }
      else
      {
        v97 = atol(nptr: v121.data);
        HIDWORD(v88) = v75->values;
        v98 = 0;
        LODWORD(v88) = *(_DWORD *)HIDWORD(v88);
        if ( *(_DWORD *)HIDWORD(v88) != 0 )
        {
          LODWORD(v88) = v75->values;
          while ( 1 )
          {
            LODWORD(v89) = *(_DWORD *)(v88 + 4);
            if ( (_DWORD)v89 == v97 )
              break;
            ++v98;
            LODWORD(v88) = 8 * v98 + HIDWORD(v88);
            LODWORD(v89) = *(_DWORD *)v88;
            if ( *(_DWORD *)v88 == 0 )
              goto LABEL_61;
          }
          if ( (_DWORD)v88 != 0 )
          {
            value = *(_DWORD *)(v88 + 4);
            goto LABEL_63;
          }
        }
      }
    }
    else
    {
      if ( (v75->flags & 0x400000) != 0 )
      {
        v82 = v121.data;
        *a28 = 0;
        if ( *data != 0 )
        {
          do
          {
            v119.allocedAndFlag = 20;
            v119.len = 0;
            v119.data = v119.baseBuffer;
            v119.baseBuffer[0] = 0;
            v83 = *v82;
            for ( i = *v82; i == 32; i = *v82 )
              v83 = *++v82;
            if ( i != 0 )
            {
              do
              {
                if ( i == 32 )
                  break;
                idStr::EnsureAlloced(this: &v119, amount: v119.len + 2, keepold: true, geometricGrowth: true);
                v119.data[v119.len] = v83;
                v119.data[++v119.len] = 0;
                v83 = *++v82;
                i = *v82;
              }
              while ( *v82 != 0 );
            }
            EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                              this,
                              enumInfo: v75,
                              name: v119.data,
                              defaultIfNotFound: false);
            if ( EnumValueInfo != nullptr )
              *a28 |= EnumValueInfo->value;
            else
              idTypeInfoFile::Warning(
                this: file,
                str: "reading unknown value %s for enum %s",
                a3: __SPAIR64__((unsigned int)v119.data, (unsigned int)varType),
                a4: v86,
                a5: v85,
                a6: (int)v99,
                a7: (int)v100,
                a8: v101,
                a9: v102,
                a10: v103,
                a11: v104);
            idStr::FreeData(this: &v119);
          }
          while ( *v82 != 0 );
        }
        goto LABEL_64;
      }
      v90 = idTypeInfoTools::FindEnumValueInfo(this, enumInfo: v75, name: v121.data, defaultIfNotFound: false);
      if ( v90 != nullptr )
      {
        value = v90->value;
LABEL_63:
        *a28 = value;
        goto LABEL_64;
      }
    }
LABEL_61:
    idTypeInfoFile::Warning(
      this: file,
      str: "reading unknown value %s for enum %s",
      a3: __SPAIR64__((unsigned int)v121.data, (unsigned int)varType),
      a4: v89,
      a5: v88,
      a6: (int)v99,
      a7: (int)v100,
      a8: v101,
      a9: v102,
      a10: v103,
      a11: v104);
    goto LABEL_64;
  }
  v43 = &this->typeInfo->classes[ClassIndex];
  if ( idTypeInfoFile::CheckSkipObject(this: file, a2: v40, a3: v39, a4: v38) && file->settings.skipMarkedObjects )
  {
    idTypeInfoFile::ReadUnknown(this: file, a2: v46, a3: v45, a4: v44);
    return v43->size;
  }
  if ( a30 != 0 )
  {
    v48 = this->classObject.list[v42].Read;
    if ( v48 != nullptr )
    {
      ((void (__fastcall *)(idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *))v48)(
        a1: this,
        a2: file,
        a3: scope,
        a4: varType,
        a5: varOps,
        a6: varName,
        a7: varFlags,
        a8: comment);
      return v43->size;
    }
  }
  idTypeInfoFile::ReadOpeningBrace(this: file, a2: v46, a3: v45, a4: v44);
  if ( (unsigned __int8)idTypeInfoFile::CheckClosingBrace(this: file, a2: v51, a3: v50, a4: v49) == 0 )
  {
    while ( 1 )
    {
      if ( idTypeInfoFile::HadError(this: file) )
        return v43->size;
      v127.allocedAndFlag = 20;
      v127.len = 0;
      v127.data = v127.baseBuffer;
      v127.baseBuffer[0] = 0;
      v128[0].allocedAndFlag = 20;
      v128[0].data = v128[0].baseBuffer;
      v128[0].len = 0;
      v128[0].baseBuffer[0] = 0;
      v120.allocedAndFlag = 20;
      v120.data = v120.baseBuffer;
      v120.len = 0;
      v120.baseBuffer[0] = 0;
      LODWORD(v52) = &v120;
      HIDWORD(v52) = v128;
      idTypeInfoFile::ReadType(this: file, type: &v127, name: v52);
      ClassVariableInfo = idTypeInfoTools::FindClassVariableInfo(this, classInfo: v43, name: v120.data);
      if ( ClassVariableInfo != nullptr )
        goto LABEL_15;
      ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: v43->superType);
      if ( ClassInfo != nullptr )
        break;
LABEL_21:
      idTypeInfoFile::Warning(
        this: file,
        str: "skipping obsolete class variable in %s '%s'",
        a3: __SPAIR64__((unsigned int)varType, (unsigned int)v120.data),
        a4: v55,
        a5: v54,
        a6: (int)v99,
        a7: (int)v100,
        a8: v101,
        a9: v102,
        a10: v103,
        a11: v104);
      idTypeInfoFile::ReadUnknown(this: file, a2: v67, a3: v66, a4: v65);
LABEL_23:
      idStr::FreeData(this: &v120);
      idStr::FreeData(this: v128);
      idStr::FreeData(this: &v127);
      if ( (unsigned __int8)idTypeInfoFile::CheckClosingBrace(this: file, a2: v70, a3: v69, a4: v68) != 0 )
        return v43->size;
    }
    while ( ClassVariableInfo == nullptr )
    {
      ClassVariableInfo = idTypeInfoTools::FindClassVariableInfo(this, classInfo: ClassInfo, name: v120.data);
      ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: ClassInfo->superType);
      if ( ClassInfo == nullptr )
      {
        if ( ClassVariableInfo == nullptr )
          goto LABEL_21;
        break;
      }
    }
LABEL_15:
    flags = ClassVariableInfo->flags;
    if ( (flags & 0x80000) == 0 && (flags & 0x100000) == 0 && (flags & 0x200000) == 0 )
    {
      HIDWORD(v58) = v120.data;
      LODWORD(v58) = v43->name;
      LODWORD(v54) = flags & 0x100000;
      idTypeInfoFile::Warning(
        this: file,
        str: "variable '%s' in class '%s' defined but not set __def, __design or __edit'",
        a3: v58,
        a4: v55,
        a5: v54,
        a6: (int)v99,
        a7: (int)v100,
        a8: v101,
        a9: v102,
        a10: v103,
        a11: v104);
    }
    v59 = ClassVariableInfo->comment;
    v60 = ClassVariableInfo->flags;
    name = ClassVariableInfo->name;
    ops = ClassVariableInfo->ops;
    type = ClassVariableInfo->type;
    v64 = v43->name;
    if ( ClassVariableInfo->size >= 0 )
      idTypeInfoTools::ReadType_r(
        this,
        file,
        scope: v64,
        varType: type,
        varOps: ops,
        varName: name,
        varFlags: v60,
        comment: v59,
        varPtr: v99,
        allowSpecialCase: (bool)v100);
    else
      idTypeInfoTools::ReadBitField(
        this,
        file,
        scope: v64,
        varType: type,
        varOps: ops,
        varName: name,
        varFlags: v60,
        comment: v59,
        varPtr: v99,
        setVar: v100,
        a11: v101,
        a12: v102,
        a13: v103,
        a14: v104,
        a15: v105,
        a16: v106,
        a17: v107,
        a18: v108,
        a19: v109,
        a20: v110,
        a21: v111,
        a22: v112,
        a23: v113,
        a24: v114,
        a25: v115,
        a26: v116,
        a27: v117,
        (int)a28,
        a29: v118,
        a30: (void (__fastcall *)(int, unsigned int))ClassVariableInfo->set);
    goto LABEL_23;
  }
  return v43->size;
}


// ========================================================================
// __unwind$115410
// EA  : 0x82F9DB08
// RVA : 0x00F9DB08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_115410()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 256));
}


// ========================================================================
// __unwind$115411
// EA  : 0x82F9DB30
// RVA : 0x00F9DB30
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_115411()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 288));
}


// ========================================================================
// __unwind$115412
// EA  : 0x82F9DB58
// RVA : 0x00F9DB58
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_115412()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 144));
}


// ========================================================================
// __unwind$115413
// EA  : 0x82F9DB80
// RVA : 0x00F9DB80
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_115413()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 176));
}


// ========================================================================
// __unwind$115414
// EA  : 0x82F9DBA8
// RVA : 0x00F9DBA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_115414()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 432 + 112));
}


// ========================================================================
// ?ReadType_r@idTypeInfoTools@@QBAHPAVidTypeInfoFile@@PBD111H1PAX_N@Z
// EA  : 0x82F9DBD8
// RVA : 0x00F9DBD8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::ReadType_r(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        bool allowSpecialCase,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int *a28,
        int a29,
        char a30)
{
  char v38; // r25
  __int64 v39; // r8
  __int64 v40; // r6
  int v41; // r4
  __int64 v43; // r8
  __int64 v44; // r6
  int v45; // r4
  __int64 v46; // r8
  __int64 v47; // r6
  int v48; // r4
  int ClassIndex; // r3
  void (__fastcall *v50)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *); // r11
  int EnumIndex; // r3
  void (__fastcall *Read)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *); // r11
  int v53; // r11
  __int64 v54; // r10
  __int64 v55; // r8
  __int64 v56; // r6
  int v57; // r3
  int Object_r; // r30
  __int64 v59; // r8
  __int64 v60; // r6
  int v61; // r4
  __int64 v62; // r8
  __int64 v63; // r6
  int v64; // r4
  void *v65; // [sp+8h] [-138h]
  int v66; // [sp+Ch] [-134h]
  int v67; // [sp+10h] [-130h]
  int v68; // [sp+14h] [-12Ch]
  int v69; // [sp+18h] [-128h]
  int v70; // [sp+1Ch] [-124h]
  int v71; // [sp+20h] [-120h]
  int v72; // [sp+24h] [-11Ch]
  int v73; // [sp+28h] [-118h]
  int v74; // [sp+2Ch] [-114h]
  int v75; // [sp+30h] [-110h]
  int v76; // [sp+34h] [-10Ch]
  int v77; // [sp+38h] [-108h]
  int v78; // [sp+3Ch] [-104h]
  int v79; // [sp+40h] [-100h]
  int v80; // [sp+44h] [-FCh]
  int v81; // [sp+48h] [-F8h]
  int v82; // [sp+4Ch] [-F4h]
  int v83; // [sp+50h] [-F0h]
  int v84; // [sp+58h] [-E8h]
  idStr v85; // [sp+70h] [-D0h] BYREF
  idStr v86; // [sp+90h] [-B0h] BYREF
  int v87; // [sp+C4h] [-7Ch]
  float v88; // [sp+C8h] [-78h]
  int v89; // [sp+CCh] [-74h]
  int v90; // [sp+D0h] [-70h]
  int v91; // [sp+D4h] [-6Ch]

  v88 = -3.4028235e38;
  v86.len = 0;
  v86.allocedAndFlag = 20;
  v86.data = v86.baseBuffer;
  v86.baseBuffer[0] = 0;
  v87 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v38 = idLib::PushWarningInfo(type: "var", name: varName);
  if ( (unsigned __int8)idTypeInfoFile::CheckUnknown(this: file, a2: v41, a3: v40, a4: v39) != 0 )
  {
    if ( v38 != 0 )
      idLib::PopWarningInfo();
LABEL_4:
    idStr::FreeData(this: &v86);
    return -1;
  }
  if ( *varOps == 0 )
  {
    Object_r = idTypeInfoTools::ReadObject_r(
                 this,
                 file,
                 scope,
                 varType,
                 varOps,
                 varName,
                 varFlags,
                 comment,
                 varPtr: v65,
                 allowSpecialCase: v66,
                 a11: v67,
                 a12: v68,
                 a13: v69,
                 a14: v70,
                 a15: v71,
                 a16: v72,
                 a17: v73,
                 a18: v74,
                 a19: v75,
                 a20: v76,
                 a21: v77,
                 a22: v78,
                 a23: v79,
                 a24: v80,
                 a25: v81,
                 a26: v82,
                 a27: v83,
                 a28,
                 a29: v84,
                 a30);
    if ( v38 != 0 )
      idLib::PopWarningInfo();
    goto LABEL_50;
  }
  idStr::idStr(this: &v85, text: varOps);
  if ( *v85.data == 42 && v85.data[1] == 0 )
  {
    if ( (unsigned __int8)idTypeInfoFile::CheckNullPointer(this: file, a2: v45, a3: v44, a4: v43) != 0 )
    {
      *a28 = 0;
      idStr::FreeData(this: &v85);
      if ( v38 != 0 )
        idLib::PopWarningInfo();
LABEL_41:
      idStr::FreeData(this: &v86);
      return 4;
    }
    ClassIndex = idTypeInfoTools::FindClassIndex(this, typeName: varType);
    if ( ClassIndex == -1 )
    {
      EnumIndex = idTypeInfoTools::FindEnumIndex(this, typeName: varType);
      if ( EnumIndex != -1 && a30 != 0 )
      {
        Read = this->enumPointer.list[EnumIndex].Read;
        if ( Read != nullptr )
        {
          ((void (__fastcall *)(idTypeInfoTools *, idTypeInfoFile *, const char *, char *, char *, const char *, int, const char *))Read)(
            a1: this,
            a2: file,
            a3: scope,
            a4: varType,
            a5: v85.data,
            a6: varName,
            a7: varFlags,
            a8: comment);
          idStr::FreeData(this: &v85);
          if ( v38 != 0 )
            idLib::PopWarningInfo();
          goto LABEL_41;
        }
      }
    }
    else if ( a30 != 0 )
    {
      v50 = this->classPointer.list[ClassIndex].Read;
      if ( v50 != nullptr )
      {
        ((void (__fastcall *)(idTypeInfoTools *, idTypeInfoFile *, const char *, char *, char *, const char *, int, const char *))v50)(
          a1: this,
          a2: file,
          a3: scope,
          a4: varType,
          a5: v85.data,
          a6: varName,
          a7: varFlags,
          a8: comment);
        idStr::FreeData(this: &v85);
        if ( v38 != 0 )
          idLib::PopWarningInfo();
        goto LABEL_41;
      }
    }
    idTypeInfoFile::ReadUnknown(this: file, a2: v48, a3: v47, a4: v46);
    idStr::FreeData(this: &v85);
    if ( v38 != 0 )
      idLib::PopWarningInfo();
    goto LABEL_41;
  }
  v53 = v85.data[v85.len - 1];
  if ( v53 != 93 )
  {
    if ( v85.len <= 2 || v53 != 42 || v85.data[v85.len - 2] != 41 )
    {
      idTypeInfoFile::ReadUnknown(this: file, a2: v45, a3: v44, a4: v43);
      idStr::FreeData(this: &v85);
      if ( v38 != 0 )
        idLib::PopWarningInfo();
      goto LABEL_4;
    }
    if ( (unsigned __int8)idTypeInfoFile::CheckNullPointer(this: file, a2: v45, a3: v44, a4: v43) != 0 )
    {
      *a28 = 0;
      idStr::FreeData(this: &v85);
      if ( v38 != 0 )
        idLib::PopWarningInfo();
      goto LABEL_41;
    }
    Object_r = idTypeInfoTools::ReadFunctionPointer(
                 this,
                 file,
                 scope,
                 varType,
                 varName: __SPAIR64__((unsigned int)varOps, (unsigned int)varName),
                 varFlags,
                 comment,
                 varPtr: v65,
                 a9: v66,
                 a10: v67,
                 a11: v68,
                 a12: v69,
                 a13: v70,
                 a14: v71,
                 a15: v72,
                 a16: v73,
                 a17: v74,
                 a18: v75,
                 a19: v76,
                 a20: v77,
                 a21: v78,
                 a22: v79,
                 a23: v80,
                 a24: v81,
                 a25: v82,
                 a26: v83,
                 a27: (void **)a28);
    idStr::FreeData(this: &v85);
    if ( v38 != 0 )
      idLib::PopWarningInfo();
    goto LABEL_50;
  }
  if ( (unsigned __int8)idTypeInfoFile::CheckOpeningBrace(this: file, a2: v45, a3: v44, a4: v43) != 0 )
  {
    v57 = idTypeInfoTools::StripArraySize(this, ops: &v85);
    Object_r = idTypeInfoTools::ReadArray(
                 this,
                 file,
                 scope,
                 varType,
                 varOps: v85.data,
                 varName,
                 varFlags,
                 comment,
                 varPtr: v65,
                 num: v66,
                 a11: v67,
                 a12: v68,
                 a13: v69,
                 a14: v70,
                 a15: v71,
                 a16: v72,
                 a17: v73,
                 a18: v74,
                 a19: v75,
                 a20: v76,
                 a21: v77,
                 a22: v78,
                 a23: v79,
                 a24: v80,
                 a25: v81,
                 a26: v82,
                 a27: v83,
                 (int)a28,
                 a29: v84,
                 a30: v57);
    idTypeInfoFile::ReadClosingBrace(this: file, a2: v61, a3: v60, a4: v59);
    idStr::FreeData(this: &v85);
    if ( v38 != 0 )
      idLib::PopWarningInfo();
LABEL_50:
    idStr::FreeData(this: &v86);
    return Object_r;
  }
  HIDWORD(v56) = varName;
  idTypeInfoFile::Warning(
    this: file,
    str: "Expected { after array %s",
    a3: v56,
    a4: v55,
    a5: v54,
    a6: (int)v65,
    a7: v66,
    a8: v67,
    a9: v68,
    a10: v69,
    a11: v70);
  idTypeInfoFile::ReadUnknown(this: file, a2: v64, a3: v63, a4: v62);
  idStr::FreeData(this: &v85);
  if ( v38 != 0 )
    idLib::PopWarningInfo();
  idStr::FreeData(this: &v86);
  return 0;
}


// ========================================================================
// __unwind$116033
// EA  : 0x82F9E060
// RVA : 0x00F9E060
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116033()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 144));
}


// ========================================================================
// __unwind$116034
// EA  : 0x82F9E088
// RVA : 0x00F9E088
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116034()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$116035
// EA  : 0x82F9E0B0
// RVA : 0x00F9E0B0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116035()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 112));
}


// ========================================================================
// ?ReadObject@idTypeInfoTools@@QBAXAAVidTypeInfoFile@@PBD11PAX@Z
// EA  : 0x82F9E0D8
// RVA : 0x00F9E0D8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::ReadObject(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        char *objectType,
        const char *objectOps,
        const char *objectName,
        int *objectPtr)
{
  void *v6; // [sp+8h] [-68h]
  bool v7; // [sp+Fh] [-61h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]
  int v10; // [sp+18h] [-58h]
  int v11; // [sp+1Ch] [-54h]
  int v12; // [sp+20h] [-50h]
  int v13; // [sp+24h] [-4Ch]
  int v14; // [sp+28h] [-48h]
  int v15; // [sp+2Ch] [-44h]
  int v16; // [sp+30h] [-40h]
  int v17; // [sp+34h] [-3Ch]
  int v18; // [sp+38h] [-38h]
  int v19; // [sp+3Ch] [-34h]
  int v20; // [sp+40h] [-30h]
  int v21; // [sp+44h] [-2Ch]
  int v22; // [sp+48h] [-28h]
  int v23; // [sp+4Ch] [-24h]
  int v24; // [sp+50h] [-20h]
  int v25; // [sp+58h] [-18h]

  this->editDepth = 0;
  this->designDepth = 0;
  this->defDepth = 0;
  idTypeInfoTools::ReadType_r(
    this,
    file,
    scope: &byte_8200D768,
    varType: objectType,
    varOps: objectOps,
    varName: objectName,
    varFlags: 0,
    comment: &byte_8200D768,
    varPtr: v6,
    allowSpecialCase: v7,
    a11: v8,
    a12: v9,
    a13: v10,
    a14: v11,
    a15: v12,
    a16: v13,
    a17: v14,
    a18: v15,
    a19: v16,
    a20: v17,
    a21: v18,
    a22: v19,
    a23: v20,
    a24: v21,
    a25: v22,
    a26: v23,
    a27: v24,
    a28: objectPtr,
    a29: v25,
    a30: 1);
}


// ========================================================================
// ?GetEnumName@idTypeInfoTools@@QBAPBDPBDH0@Z
// EA  : 0x82F9E140
// RVA : 0x00F9E140
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

const char *__fastcall idTypeInfoTools::GetEnumName(
        idTypeInfoTools *this,
        const char *enumTypeName,
        const int enumValue,
        const char *defaultValue)
{
  const enumTypeInfo_t *EnumInfo; // r3
  const enumValueInfo_t *values; // r9
  int v8; // r10
  const enumValueInfo_t *v9; // r11

  EnumInfo = idTypeInfoTools::FindEnumInfo(this, typeName: enumTypeName);
  if ( EnumInfo == nullptr )
    return defaultValue;
  values = EnumInfo->values;
  v8 = 0;
  if ( values->name == nullptr )
    return defaultValue;
  v9 = EnumInfo->values;
  while ( v9->value != enumValue )
  {
    v9 = &values[++v8];
    if ( v9->name == nullptr )
      return defaultValue;
  }
  return v9->name;
}


// ========================================================================
// ?Shutdown@idTypeInfoTools@@QAAXXZ
// EA  : 0x82F9E1C8
// RVA : 0x00F9E1C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::Shutdown(idTypeInfoTools *this)
{
  idStr *list; // r3

  idHashIndex::Clear(this: &this->enumHash);
  idHashIndex::Clear(this: &this->classHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enumObject);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enumPointer);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->classObject);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->classPointer);
  if ( this->warnings.listStatic == 0 || this->warnings.listStatic == 2 )
  {
    list = this->warnings.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->warnings.size);
    this->warnings.list = nullptr;
    this->warnings.size = 0;
  }
  this->warnings.num = 0;
}


// ========================================================================
// ?ClearWarnings@idTypeInfoTools@@QBAXXZ
// EA  : 0x82F9E260
// RVA : 0x00F9E260
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::ClearWarnings(idTypeInfoTools *this)
{
  idStr *list; // r3

  if ( this->warnings.listStatic == 0 || this->warnings.listStatic == 2 )
  {
    list = this->warnings.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->warnings.size);
    this->warnings.list = nullptr;
    this->warnings.size = 0;
  }
  this->warnings.num = 0;
}


// ========================================================================
// ?IsSubclassOf@idTypeInfoTools@@QBA_NPBD0@Z
// EA  : 0x82F9E2C8
// RVA : 0x00F9E2C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::IsSubclassOf(idTypeInfoTools *this, const char *typeName, const char *superType)
{
  const char *v4; // r28
  int v6; // r31
  int v7; // r30

  v4 = typeName;
  if ( *typeName == 0 )
    return 0;
  while ( idStr::Cmp(s1: v4, s2: superType) != 0 )
  {
    if ( *v4 == 0 )
      return 0;
    v6 = this->classHash.hash[idHashIndex::GenerateKeyForString(this: &this->classHash, string: v4, caseSensitive: true)
                            & this->classHash.hashMask
                            & this->classHash.lookupMask];
    if ( v6 == -1 )
      return 0;
    while ( 1 )
    {
      v7 = v6;
      if ( idStr::Cmp(s1: v4, s2: this->typeInfo->classes[v6].name) == 0 )
        break;
      v6 = this->classHash.indexChain[this->classHash.lookupMask & v6];
      if ( v6 == -1 )
        return 0;
    }
    if ( &this->typeInfo->classes[v7] == nullptr )
      return 0;
    v4 = this->typeInfo->classes[v7].superType;
    if ( *v4 == 0 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetVariableFromOffset@idTypeInfoTools@@ABAXPBDHAAVidStr@@111@Z
// EA  : 0x82F9E3D0
// RVA : 0x00F9E3D0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::GetVariableFromOffset(
        idTypeInfoTools *this,
        char *typeName,
        int offset,
        idStr *varType,
        idStr *varOps,
        idStr *varPath,
        idStr *varTypedPath)
{
  char *superType; // r30
  const classTypeInfo_t *ClassInfo; // r29
  __int64 v15; // r8
  const enumTypeInfo_t *EnumInfo; // r30
  int v17; // r30
  __int64 v18; // r6
  int v19; // r9
  int variables; // r11
  int v21; // r10
  int v22; // r28
  int v23; // r10
  va *v24; // r3
  __int64 v25; // r6
  __int64 v26; // r10
  __int64 v27; // r8
  va *v28; // r3
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  __int64 v32; // r10
  va *v33; // r3
  va *v34; // r29
  size_t j; // r30
  unsigned int v36; // r11
  int v37; // r4
  int v38; // r11
  bool v39; // zf
  __int64 v40; // r6
  const classVariableInfo_t *v41; // r11
  int v42; // r27
  int len; // r11
  int v44; // r26
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r6
  int v48; // r3
  int i; // r30
  va *v50; // r3
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  va *v54; // r3
  bool v55; // r7
  unsigned int allocedAndFlag; // r11
  __int64 v57; // r10
  int v58; // r30
  int v59; // r4
  int v60; // r11
  __int64 v61; // r6
  int v62; // [sp+8h] [-10D8h]
  int v63; // [sp+8h] [-10D8h]
  int v64; // [sp+8h] [-10D8h]
  int v65; // [sp+8h] [-10D8h]
  int v66; // [sp+Ch] [-10D4h]
  int v67; // [sp+Ch] [-10D4h]
  int v68; // [sp+Ch] [-10D4h]
  int v69; // [sp+Ch] [-10D4h]
  int v70; // [sp+10h] [-10D0h]
  int v71; // [sp+10h] [-10D0h]
  int v72; // [sp+10h] [-10D0h]
  int v73; // [sp+10h] [-10D0h]
  int v74; // [sp+14h] [-10CCh]
  int v75; // [sp+14h] [-10CCh]
  int v76; // [sp+14h] [-10CCh]
  int v77; // [sp+14h] [-10CCh]
  int v78; // [sp+18h] [-10C8h]
  int v79; // [sp+18h] [-10C8h]
  int v80; // [sp+18h] [-10C8h]
  int v81; // [sp+18h] [-10C8h]
  int v82; // [sp+1Ch] [-10C4h]
  int v83; // [sp+1Ch] [-10C4h]
  int v84; // [sp+1Ch] [-10C4h]
  int v85; // [sp+1Ch] [-10C4h]
  idStr v86; // [sp+50h] [-1090h] BYREF
  va v87; // [sp+70h] [-1070h] BYREF

  superType = typeName;
  ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName);
  if ( ClassInfo != nullptr )
  {
    while ( 1 )
    {
      HIDWORD(v15) = ClassInfo->variables;
      if ( HIDWORD(v15) == 0 )
      {
        idStr::operator=(this: varType, text: (char *)ClassInfo->name);
        idStr::operator=(this: varOps, text: &byte_8200D768);
        return;
      }
      if ( *(_DWORD *)(HIDWORD(v15) + 8) != 0 && offset >= *(_DWORD *)(HIDWORD(v15) + 12) )
        break;
      superType = (char *)ClassInfo->superType;
      if ( *superType == 0 )
      {
        idStr::operator=(this: varType, text: "<unknown>");
        idStr::operator=(this: varOps, text: &byte_8200D768);
        return;
      }
      idStr::Append(this: varTypedPath, text: "::");
      idStr::Append(this: varTypedPath, text: superType);
      ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: superType);
      if ( ClassInfo == nullptr )
        goto LABEL_7;
    }
    v17 = 0;
    LODWORD(v18) = 0x7FFFFFFF;
    v19 = 0;
    if ( *(_DWORD *)(HIDWORD(v15) + 8) != 0 )
    {
      variables = (int)ClassInfo->variables;
      v21 = 0;
      do
      {
        LODWORD(v15) = *(_DWORD *)(variables + 12);
        if ( offset - (int)v15 >= 0 && offset - (int)v15 < (int)v18 )
        {
          LODWORD(v18) = offset - v15;
          v17 = v19;
        }
        if ( offset >= (int)v15 && offset < ClassInfo->variables[v21].size + ClassInfo->variables[v21].offset )
          break;
        v21 = ++v19;
        variables = 40 * v19 + HIDWORD(v15);
        LODWORD(v15) = *(_DWORD *)(variables + 8);
      }
      while ( (_DWORD)v15 != 0 );
    }
    v22 = v19;
    v23 = 40 * v19 + HIDWORD(v15);
    if ( *(_DWORD *)(v23 + 8) != 0 )
    {
      idStr::Append(this: varTypedPath, text: "::");
      idStr::Append(this: varTypedPath, text: (char *)ClassInfo->variables[v22].name);
      if ( varPath->len != 0 )
        idStr::Append(this: varPath, text: ".");
      idStr::Append(this: varPath, text: (char *)ClassInfo->variables[v22].name);
      v41 = &ClassInfo->variables[v22];
      v42 = offset - v41->offset;
      idStr::idStr(this: &v86, text: v41->ops);
      len = v86.len;
      if ( v86.len > 0 && v86.data[v86.len - 1] == 93 )
      {
        v44 = idTypeInfoTools::StripArraySize(this, ops: &v86);
        v48 = idTypeInfoTools::SizeForType(this, varType: ClassInfo->variables[v22].type, varOps: v86.data);
        for ( i = 0; i < v44; v42 -= v48 )
        {
          if ( v42 < v48 )
            break;
          ++i;
        }
        HIDWORD(v47) = i;
        v50 = va::va(
                this: &v87,
                fmt: "[%d]",
                a3: v47,
                a4: v46,
                a5: v45,
                a6: v62,
                a7: v66,
                a8: v70,
                a9: v74,
                a10: v78,
                a11: v82);
        idStr::Append(this: varTypedPath, text: v50);
        HIDWORD(v51) = i;
        v54 = va::va(
                this: &v87,
                fmt: "[%d]",
                a3: v51,
                a4: v53,
                a5: v52,
                a6: v65,
                a7: v69,
                a8: v73,
                a9: v77,
                a10: v81,
                a11: v85);
        idStr::Append(this: varPath, text: v54);
        len = v86.len;
      }
      if ( v42 != 0 || len == 0 )
      {
        idTypeInfoTools::GetVariableFromOffset(
          this,
          typeName: ClassInfo->variables[v22].type,
          offset: v42,
          varType,
          varOps,
          varPath,
          varTypedPath);
      }
      else
      {
        idStr::operator=(this: varType, text: (char *)ClassInfo->variables[v22].type);
        allocedAndFlag = varOps->allocedAndFlag;
        HIDWORD(v57) = allocedAndFlag >> 31;
        v58 = v86.len;
        v59 = v86.len + 1;
        v39 = allocedAndFlag >> 31 == 0;
        v60 = allocedAndFlag & 0x7FFFFFFF;
        if ( v39 )
        {
          if ( v59 > v60 )
            idStr::ReAllocate(this: varOps, amount: v59, keepold: false);
        }
        else if ( v59 > v60 )
        {
          LODWORD(v57) = 0x82000000;
          HIDWORD(v61) = "amount <= GetAlloced()";
          LODWORD(v61) = 1;
          if ( (unsigned __int8)AssertFailed(
                                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                                  expression: v61,
                                  inlineBreak: v55,
                                  a4: v57) != 0 )
            __trap();
        }
        memcpy(Dst: varOps->data, Src: v86.data, Size: v58);
        varOps->data[v58] = 0;
        varOps->len = v58;
      }
      idStr::FreeData(this: &v86);
    }
    else
    {
      HIDWORD(v18) = offset;
      v24 = va::va(
              this: &v87,
              fmt: "[%d]",
              a3: v18,
              a4: v15,
              a5: (unsigned int)v23,
              a6: v62,
              a7: v66,
              a8: v70,
              a9: v74,
              a10: v78,
              a11: v82);
      idStr::Append(this: varTypedPath, text: v24);
      HIDWORD(v25) = offset;
      v28 = va::va(
              this: &v87,
              fmt: "[%d]",
              a3: v25,
              a4: v27,
              a5: v26,
              a6: v63,
              a7: v67,
              a8: v71,
              a9: v75,
              a10: v79,
              a11: v83);
      idStr::Append(this: varPath, text: v28);
      HIDWORD(v29) = 5 * v17;
      LODWORD(v29) = 40 * v17;
      LODWORD(v30) = &ClassInfo->variables[v17];
      HIDWORD(v31) = *(_DWORD *)(v30 + 8);
      v33 = va::va(
              this: &v87,
              fmt: "<unknown-right-after-%s>",
              a3: v31,
              a4: v30,
              a5: v29,
              a6: v64,
              a7: v68,
              a8: v72,
              a9: v76,
              a10: v80,
              a11: v84);
      v34 = v33;
      for ( j = 0; v33->buffer[j] != 0; ++j )
        ;
      v36 = varType->allocedAndFlag;
      v37 = j + 1;
      v39 = v36 >> 31 == 0;
      v38 = v36 & 0x7FFFFFFF;
      if ( v39 )
      {
        if ( v37 > v38 )
          idStr::ReAllocate(this: varType, amount: v37, keepold: false);
      }
      else if ( v37 > v38 )
      {
        LODWORD(v32) = 0x82000000;
        HIDWORD(v40) = "amount <= GetAlloced()";
        LODWORD(v40) = 1;
        if ( (unsigned __int8)AssertFailed(
                                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                                expression: v40,
                                inlineBreak: v33->buffer[0],
                                a4: v32) != 0 )
          __trap();
      }
      memcpy(Dst: varType->data, Src: v34, Size: j);
      varType->data[j] = 0;
      varType->len = j;
      idStr::operator=(this: varOps, text: &byte_8200D768);
    }
  }
  else
  {
LABEL_7:
    EnumInfo = idTypeInfoTools::FindEnumInfo(this, typeName: superType);
    if ( EnumInfo != nullptr )
    {
      idStr::Append(this: varTypedPath, text: "::");
      idStr::Append(this: varTypedPath, text: (char *)EnumInfo->name);
      idStr::operator=(this: varType, text: (char *)EnumInfo->name);
    }
    else
    {
      idStr::Append(this: varTypedPath, text: "::<unknown>");
      idStr::operator=(this: varType, text: "<unknown>");
    }
    idStr::operator=(this: varOps, text: &byte_8200D768);
  }
}


// ========================================================================
// __unwind$116600
// EA  : 0x82F9E904
// RVA : 0x00F9E904
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116600()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 80));
}


// ========================================================================
// ?GetVariableNameFromOffset@idTypeInfoTools@@QBAPBDPBDH@Z
// EA  : 0x82F9E938
// RVA : 0x00F9E938
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

char *__fastcall idTypeInfoTools::GetVariableNameFromOffset(idTypeInfoTools *this, char *typeName, int offset)
{
  __int64 v3; // r6
  __int64 v4; // r10
  __int64 v5; // r8
  idStr v7; // [sp+50h] [-A0h] BYREF
  idStr v8; // [sp+70h] [-80h] BYREF
  idStr v9; // [sp+90h] [-60h] BYREF
  idStr v10; // [sp+B0h] [-40h] BYREF

  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  v9.len = 0;
  v9.baseBuffer[0] = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.len = 0;
  v7.baseBuffer[0] = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.len = 0;
  v8.baseBuffer[0] = 0;
  idTypeInfoTools::GetVariableFromOffset(
    this,
    typeName,
    offset,
    varType: &v10,
    varOps: &v9,
    varPath: &v7,
    varTypedPath: &v8);
  HIDWORD(v3) = 1024;
  idStr::Copynz(src: __SPAIR64__(varName, (unsigned int)v7.data), destsize: v3, a3: v5, a4: v4);
  idStr::FreeData(this: &v8);
  idStr::FreeData(this: &v7);
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: &v10);
  return varName;
}


// ========================================================================
// __unwind$116822
// EA  : 0x82F9EA10
// RVA : 0x00F9EA10
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116822()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 176));
}


// ========================================================================
// __unwind$116823
// EA  : 0x82F9EA38
// RVA : 0x00F9EA38
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116823()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$116824
// EA  : 0x82F9EA60
// RVA : 0x00F9EA60
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116824()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$116825
// EA  : 0x82F9EA88
// RVA : 0x00F9EA88
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116825()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?GetVariableTypeFromOffset@idTypeInfoTools@@QBAPBDPBDH@Z
// EA  : 0x82F9EAB8
// RVA : 0x00F9EAB8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

char *__fastcall idTypeInfoTools::GetVariableTypeFromOffset(idTypeInfoTools *this, char *typeName, int offset)
{
  __int64 v3; // r6
  __int64 v4; // r10
  __int64 v5; // r8
  idStr v7; // [sp+50h] [-A0h] BYREF
  idStr v8; // [sp+70h] [-80h] BYREF
  idStr v9; // [sp+90h] [-60h] BYREF
  idStr v10; // [sp+B0h] [-40h] BYREF

  v7.len = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.baseBuffer[0] = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.len = 0;
  v10.baseBuffer[0] = 0;
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  v9.len = 0;
  v9.baseBuffer[0] = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.len = 0;
  v8.baseBuffer[0] = 0;
  idTypeInfoTools::GetVariableFromOffset(
    this,
    typeName,
    offset,
    varType: &v7,
    varOps: &v10,
    varPath: &v9,
    varTypedPath: &v8);
  HIDWORD(v3) = 1024;
  idStr::Copynz(src: __SPAIR64__(varType, (unsigned int)v7.data), destsize: v3, a3: v5, a4: v4);
  idStr::FreeData(this: &v8);
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: &v10);
  idStr::FreeData(this: &v7);
  return varType;
}


// ========================================================================
// __unwind$116967
// EA  : 0x82F9EB90
// RVA : 0x00F9EB90
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116967()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$116968
// EA  : 0x82F9EBB8
// RVA : 0x00F9EBB8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116968()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 176));
}


// ========================================================================
// __unwind$116969
// EA  : 0x82F9EBE0
// RVA : 0x00F9EBE0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116969()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$116970
// EA  : 0x82F9EC08
// RVA : 0x00F9EC08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_116970()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?GetVariableOpsFromOffset@idTypeInfoTools@@QBAPBDPBDH@Z
// EA  : 0x82F9EC38
// RVA : 0x00F9EC38
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

char *__fastcall idTypeInfoTools::GetVariableOpsFromOffset(idTypeInfoTools *this, char *typeName, int offset)
{
  __int64 v3; // r6
  __int64 v4; // r10
  __int64 v5; // r8
  idStr v7; // [sp+50h] [-A0h] BYREF
  idStr v8; // [sp+70h] [-80h] BYREF
  idStr v9; // [sp+90h] [-60h] BYREF
  idStr v10; // [sp+B0h] [-40h] BYREF

  v10.len = 0;
  v10.allocedAndFlag = 20;
  v10.data = v10.baseBuffer;
  v10.baseBuffer[0] = 0;
  v7.allocedAndFlag = 20;
  v7.data = v7.baseBuffer;
  v7.len = 0;
  v7.baseBuffer[0] = 0;
  v9.allocedAndFlag = 20;
  v9.data = v9.baseBuffer;
  v9.len = 0;
  v9.baseBuffer[0] = 0;
  v8.allocedAndFlag = 20;
  v8.data = v8.baseBuffer;
  v8.len = 0;
  v8.baseBuffer[0] = 0;
  idTypeInfoTools::GetVariableFromOffset(
    this,
    typeName,
    offset,
    varType: &v10,
    varOps: &v7,
    varPath: &v9,
    varTypedPath: &v8);
  HIDWORD(v3) = 1024;
  idStr::Copynz(src: __SPAIR64__(varOps, (unsigned int)v7.data), destsize: v3, a3: v5, a4: v4);
  idStr::FreeData(this: &v8);
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: &v7);
  idStr::FreeData(this: &v10);
  return varOps;
}


// ========================================================================
// __unwind$117112
// EA  : 0x82F9ED10
// RVA : 0x00F9ED10
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117112()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 176));
}


// ========================================================================
// __unwind$117113
// EA  : 0x82F9ED38
// RVA : 0x00F9ED38
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117113()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$117114
// EA  : 0x82F9ED60
// RVA : 0x00F9ED60
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117114()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$117115
// EA  : 0x82F9ED88
// RVA : 0x00F9ED88
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117115()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?AddClass@idTypeInfoTools@@QAAXPBD_N11P6AXPBV1@PAVidTypeInfoFile@@0000H0PAX@Z5@Z
// EA  : 0x82F9EDB0
// RVA : 0x00F9EDB0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::AddClass(
        idTypeInfoTools *this,
        const char *typeName,
        bool isPointer,
        bool matchPrefix,
        bool includeDerivedClasses,
        void (__fastcall *writeFunc)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *),
        void (__fastcall *readFunc)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))
{
  idTypeInfoTools::readWrite_t *list; // r31
  int v12; // r28
  int v13; // r30
  classTypeInfo_t *classes; // r10
  int v15; // r11
  int v16; // r30
  const typeInfo_t *typeInfo; // r11
  classTypeInfo_t *v18; // r10
  int v19; // r11
  classTypeInfo_t *v20; // r11
  int v21; // r10
  idTypeInfoTools::readWrite_t *v22; // r11

  if ( isPointer )
    list = this->classPointer.list;
  else
    list = this->classObject.list;
  if ( matchPrefix )
  {
    v12 = 0;
    if ( *typeName != 0 )
    {
      do
        ++v12;
      while ( typeName[v12] != 0 );
    }
    v13 = 0;
    classes = this->typeInfo->classes;
    if ( classes->name != nullptr )
    {
      v15 = 0;
      do
      {
        if ( idStr::Cmpn(s1: typeName, s2: classes[v15].name, n: v12) == 0 )
        {
          list->Write = writeFunc;
          list->Read = readFunc;
        }
        ++v13;
        ++list;
        v15 = v13;
        classes = this->typeInfo->classes;
      }
      while ( classes[v13].name != nullptr );
    }
  }
  else
  {
    v16 = 0;
    typeInfo = this->typeInfo;
    if ( includeDerivedClasses )
    {
      v18 = typeInfo->classes;
      if ( v18->name != nullptr )
      {
        v19 = 0;
        do
        {
          if ( (unsigned __int8)idTypeInfoTools::IsSubclassOf(this, typeName: v18[v19].name, superType: typeName) != 0 )
          {
            list->Write = writeFunc;
            list->Read = readFunc;
          }
          ++v16;
          ++list;
          v19 = v16;
          v18 = this->typeInfo->classes;
        }
        while ( v18[v16].name != nullptr );
      }
    }
    else
    {
      v20 = typeInfo->classes;
      if ( v20->name != nullptr )
      {
        v21 = 0;
        while ( idStr::Cmp(s1: typeName, s2: v20[v21].name) != 0 )
        {
          v21 = ++v16;
          v20 = this->typeInfo->classes;
          if ( v20[v16].name == nullptr )
            return;
        }
        v22 = &list[v16];
        v22->Write = writeFunc;
        v22->Read = readFunc;
      }
    }
  }
}


// ========================================================================
// ?GetEnumBitFlags@idTypeInfoTools@@QBA_NHPBDAAVidStr@@0@Z
// EA  : 0x82F9EF50
// RVA : 0x00F9EF50
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::GetEnumBitFlags(
        idTypeInfoTools *this,
        int flags,
        const char *enumType,
        idStr *flagNames,
        const char *delimiter)
{
  __int64 v10; // r8
  const enumTypeInfo_t *EnumInfo; // r3
  const enumTypeInfo_t *v12; // r31
  const enumValueInfo_t *values; // r10
  int v14; // r30
  int v15; // r11
  __int64 v16; // r10
  __int64 v17; // r6
  va *v18; // r3
  int v20; // [sp+8h] [-1088h]
  int v21; // [sp+Ch] [-1084h]
  int v22; // [sp+10h] [-1080h]
  int v23; // [sp+14h] [-107Ch]
  int v24; // [sp+18h] [-1078h]
  int v25; // [sp+1Ch] [-1074h]
  va v26; // [sp+50h] [-1040h] BYREF

  idStr::operator=(this: flagNames, text: &byte_8200D768);
  EnumInfo = idTypeInfoTools::FindEnumInfo(this, typeName: enumType);
  v12 = EnumInfo;
  if ( EnumInfo != nullptr )
  {
    values = EnumInfo->values;
    v14 = 0;
    if ( values->name != nullptr )
    {
      v15 = 0;
      do
      {
        HIDWORD(v16) = &values[v15];
        if ( values[v15].value != 0 )
        {
          LODWORD(v16) = v12->values[v15].value;
          if ( ((unsigned int)v16 & flags) == (_DWORD)v16 )
          {
            HIDWORD(v17) = &byte_8200D768;
            if ( flagNames->len != 0 )
              HIDWORD(v17) = delimiter;
            LODWORD(v17) = *(_DWORD *)HIDWORD(v16);
            LODWORD(v10) = v16 & flags;
            v18 = va::va(
                    this: &v26,
                    fmt: "%s%s",
                    a3: v17,
                    a4: v10,
                    a5: v16,
                    a6: v20,
                    a7: v21,
                    a8: v22,
                    a9: v23,
                    a10: v24,
                    a11: v25);
            idStr::Append(this: flagNames, text: v18);
          }
        }
        ++v14;
        values = v12->values;
        v15 = v14;
      }
      while ( values[v14].name != nullptr );
    }
  }
  return 0;
}


// ========================================================================
// ??0idTypeInfoTools@@QAA@XZ
// EA  : 0x82F9F0E0
// RVA : 0x00F9F0E0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

idTypeInfoTools *__fastcall idTypeInfoTools::idTypeInfoTools(idTypeInfoTools *this)
{
  this->enumHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->enumHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->classHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->classHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->enumObject.list = nullptr;
  this->enumObject.granularity = 0;
  this->enumObject.memTag = 44;
  this->enumObject.listStatic = 0;
  this->enumObject.size = 0;
  this->enumObject.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enumObject);
  this->enumPointer.list = nullptr;
  this->enumPointer.granularity = 0;
  this->enumPointer.memTag = 44;
  this->enumPointer.listStatic = 0;
  this->enumPointer.size = 0;
  this->enumPointer.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enumPointer);
  this->classObject.list = nullptr;
  this->classObject.granularity = 0;
  this->classObject.memTag = 44;
  this->classObject.listStatic = 0;
  this->classObject.size = 0;
  this->classObject.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->classObject);
  this->classPointer.list = nullptr;
  this->classPointer.granularity = 0;
  this->classPointer.memTag = 44;
  this->classPointer.listStatic = 0;
  this->classPointer.size = 0;
  this->classPointer.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->classPointer);
  this->warnings.granularity = 0;
  this->warnings.memTag = 5;
  this->warnings.listStatic = 0;
  this->warnings.list = nullptr;
  this->warnings.size = 0;
  this->warnings.num = 0;
  this->typeInfo = nullptr;
  this->editDepth = 0;
  this->designDepth = 0;
  this->defDepth = 0;
  return this;
}


// ========================================================================
// __unwind$117512
// EA  : 0x82F9F1EC
// RVA : 0x00F9F1EC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117512()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$117513
// EA  : 0x82F9F218
// RVA : 0x00F9F218
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117513()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// __unwind$117514
// EA  : 0x82F9F244
// RVA : 0x00F9F244
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117514()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// __unwind$117515
// EA  : 0x82F9F270
// RVA : 0x00F9F270
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117515()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 84));
}


// ========================================================================
// __unwind$117516
// EA  : 0x82F9F29C
// RVA : 0x00F9F29C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117516()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 100));
}


// ========================================================================
// __unwind$117517
// EA  : 0x82F9F2C8
// RVA : 0x00F9F2C8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117517()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 116));
}


// ========================================================================
// ??1idTypeInfoTools@@QAA@XZ
// EA  : 0x82F9F300
// RVA : 0x00F9F300
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::~idTypeInfoTools(idTypeInfoTools *this)
{
  idStr *list; // r3

  this->typeInfo = nullptr;
  if ( this->warnings.listStatic == 0 || this->warnings.listStatic == 2 )
  {
    list = this->warnings.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->warnings.size);
    this->warnings.list = nullptr;
    this->warnings.size = 0;
  }
  this->warnings.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->classPointer);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->classObject);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enumPointer);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enumObject);
  idHashIndex::Free(this: &this->classHash);
  idHashIndex::Free(this: &this->enumHash);
}


// ========================================================================
// __unwind$117598
// EA  : 0x82F9F38C
// RVA : 0x00F9F38C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117598()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$117599
// EA  : 0x82F9F3B8
// RVA : 0x00F9F3B8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117599()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$117600
// EA  : 0x82F9F3E4
// RVA : 0x00F9F3E4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117600()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$117601
// EA  : 0x82F9F410
// RVA : 0x00F9F410
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117601()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// __unwind$117602
// EA  : 0x82F9F43C
// RVA : 0x00F9F43C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117602()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 100));
}


// ========================================================================
// __unwind$117603
// EA  : 0x82F9F468
// RVA : 0x00F9F468
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117603()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// ?Init@idTypeInfoTools@@QAAXPBUtypeInfo_t@@@Z
// EA  : 0x82F9F498
// RVA : 0x00F9F498
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::Init(idTypeInfoTools *this, const typeInfo_t *typeInfo_)
{
  int numEnums; // r4
  int v4; // r29
  idHashIndex *p_enumHash; // r31
  int v6; // r11
  int v7; // r28
  int KeyForString; // r27
  int indexSize; // r11
  int v10; // r7
  int v11; // r29
  idHashIndex *p_classHash; // r31
  int v13; // r11
  int v14; // r28
  int v15; // r27
  int v16; // r11
  int v17; // r7
  idTypeInfoTools::readWrite_t v18[10]; // [sp+50h] [-50h] BYREF

  this->typeInfo = typeInfo_;
  numEnums = typeInfo_->numEnums;
  v18[0].Read = nullptr;
  v18[0].Write = nullptr;
  idList<idTypeInfoTools::readWrite_t,44>::SetNum(this: &this->enumObject, newNum: numEnums, initValue: v18);
  idList<idTypeInfoTools::readWrite_t,44>::SetNum(
    this: &this->enumPointer,
    newNum: this->typeInfo->numEnums,
    initValue: v18);
  idList<idTypeInfoTools::readWrite_t,44>::SetNum(
    this: &this->classObject,
    newNum: this->typeInfo->numClasses,
    initValue: v18);
  idList<idTypeInfoTools::readWrite_t,44>::SetNum(
    this: &this->classPointer,
    newNum: this->typeInfo->numClasses,
    initValue: v18);
  v4 = 0;
  if ( this->typeInfo->enums->name != nullptr )
  {
    p_enumHash = &this->enumHash;
    v6 = 0;
    v7 = 0;
    do
    {
      KeyForString = idHashIndex::GenerateKeyForString(
                       this: &this->enumHash,
                       string: this->typeInfo->enums[v6].name,
                       caseSensitive: true);
      indexSize = this->enumHash.indexSize;
      if ( p_enumHash->hash == idHashIndex::INVALID_INDEX )
      {
        if ( v4 >= indexSize )
          indexSize = v4 + 1;
        idHashIndex::Allocate(this: &this->enumHash, newHashSize: this->enumHash.hashSize, newIndexSize: indexSize);
      }
      else if ( v4 >= indexSize )
      {
        idHashIndex::ResizeIndex(this: &this->enumHash, newIndexSize: v4 + 1);
      }
      v10 = KeyForString & this->enumHash.hashMask;
      this->enumHash.indexChain[v7++] = p_enumHash->hash[v10];
      p_enumHash->hash[v10] = v4++;
      v6 = v4;
    }
    while ( this->typeInfo->enums[v4].name != nullptr );
  }
  v11 = 0;
  if ( this->typeInfo->classes->name != nullptr )
  {
    p_classHash = &this->classHash;
    v13 = 0;
    v14 = 0;
    do
    {
      v15 = idHashIndex::GenerateKeyForString(
              this: &this->classHash,
              string: this->typeInfo->classes[v13].name,
              caseSensitive: true);
      v16 = this->classHash.indexSize;
      if ( p_classHash->hash == idHashIndex::INVALID_INDEX )
      {
        if ( v11 >= v16 )
          v16 = v11 + 1;
        idHashIndex::Allocate(this: &this->classHash, newHashSize: this->classHash.hashSize, newIndexSize: v16);
      }
      else if ( v11 >= v16 )
      {
        idHashIndex::ResizeIndex(this: &this->classHash, newIndexSize: v11 + 1);
      }
      v17 = this->classHash.hashMask & v15;
      this->classHash.indexChain[v14++] = p_classHash->hash[v17];
      p_classHash->hash[v17] = v11++;
      v13 = v11;
    }
    while ( this->typeInfo->classes[v11].name != nullptr );
  }
  idTypeInfoTools::AddClass(
    this,
    typeName: "bool",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteBool,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadBool);
  idTypeInfoTools::AddClass(
    this,
    typeName: "char",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteChar,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadUnsignedChar);
  idTypeInfoTools::AddClass(
    this,
    typeName: "unsigned char",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteUnsignedChar,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadUnsignedChar);
  idTypeInfoTools::AddClass(
    this,
    typeName: "wchar_t",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteWChar,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadWChar);
  idTypeInfoTools::AddClass(
    this,
    typeName: "short",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteShort,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadWChar);
  idTypeInfoTools::AddClass(
    this,
    typeName: "unsigned short",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteUnsignedShort,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadWChar);
  idTypeInfoTools::AddClass(
    this,
    typeName: "int",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteInt,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadUnsignedLong);
  idTypeInfoTools::AddClass(
    this,
    typeName: "unsigned int",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteUnsignedLong,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadUnsignedLong);
  idTypeInfoTools::AddClass(
    this,
    typeName: "long",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteInt,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadUnsignedLong);
  idTypeInfoTools::AddClass(
    this,
    typeName: "unsigned long",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteUnsignedLong,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadUnsignedLong);
  idTypeInfoTools::AddClass(
    this,
    typeName: "float",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteFloat,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadFloat);
  idTypeInfoTools::AddClass(
    this,
    typeName: "double",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteDouble,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadDouble);
  idTypeInfoTools::AddClass(
    this,
    typeName: "size_t",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteUnsignedLong,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadUnsignedLong);
  idTypeInfoTools::AddClass(
    this,
    typeName: "idVecX",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteVecX,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadVecX);
  idTypeInfoTools::AddClass(
    this,
    typeName: "idMatX",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: false,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteMatX,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadMatX);
  idTypeInfoTools::AddClass(
    this,
    typeName: "idStr",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: true,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteStr,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadStr);
  idTypeInfoTools::AddClass(
    this,
    typeName: "idStrId",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: true,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteStrId,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadStrId);
  idTypeInfoTools::AddClass(
    this,
    typeName: "idAtomicString",
    isPointer: false,
    matchPrefix: false,
    includeDerivedClasses: true,
    writeFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))WriteAtomicString,
    readFunc: (void (__fastcall *)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *))ReadAtomicString);
}


// ========================================================================
// ??0idPathTypeInfo@@QAA@XZ
// EA  : 0x82F9F9D0
// RVA : 0x00F9F9D0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

idPathTypeInfo *__fastcall idPathTypeInfo::idPathTypeInfo(idPathTypeInfo *this)
{
  this->type.len = 0;
  this->type.data = this->type.baseBuffer;
  this->type.allocedAndFlag = 20;
  this->type.baseBuffer[0] = 0;
  this->ops.allocedAndFlag = 20;
  this->ops.len = 0;
  this->ops.data = this->ops.baseBuffer;
  this->ops.baseBuffer[0] = 0;
  this->name.allocedAndFlag = 20;
  this->name.len = 0;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->metaData.granularity = 0;
  this->metaData.memTag = 5;
  this->metaData.listStatic = 0;
  this->metaData.list = nullptr;
  this->metaData.size = 0;
  this->metaData.num = 0;
  this->arrayIndex = -1;
  this->flags = 0;
  this->objectPtr = nullptr;
  this->size = 0;
  this->get = nullptr;
  this->set = nullptr;
  this->editDepth = 0;
  this->designDepth = 0;
  this->defDepth = 0;
  return this;
}


// ========================================================================
// __unwind$117716_0
// EA  : 0x82F9FA80
// RVA : 0x00F9FA80
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117716_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$117717_0
// EA  : 0x82F9FAA8
// RVA : 0x00F9FAA8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117717_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 32));
}


// ========================================================================
// __unwind$117718_0
// EA  : 0x82F9FAD4
// RVA : 0x00F9FAD4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117718_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 64));
}


// ========================================================================
// ?TypeInfoForPath@idTypeInfoTools@@ABA_NAAVidPathTypeInfo@@PBD@Z
// EA  : 0x82F9FB08
// RVA : 0x00F9FB08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::TypeInfoForPath(idTypeInfoTools *this, idPathTypeInfo *info, const char *path)
{
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // r11
  const classTypeInfo_t *v9; // r3
  __int64 v11; // r6
  __int64 v12; // r8
  const classTypeInfo_t *ClassInfo; // r29
  const classVariableInfo_t *ClassVariableInfo; // r26
  idStr *p_ops; // r25
  idList<idStr,5> *p_metaData; // r27
  const classTypeInfo_t *v17; // r28
  int i; // r29
  const char *metaData; // r4
  __int64 v20; // r8
  __int64 v21; // r6
  unsigned __int8 *objectPtr; // r11
  int flags; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  __int64 v26; // r8
  __int64 v27; // r6
  int v28; // r4
  __int64 v29; // r8
  __int64 v30; // r6
  int len; // r11
  char *data; // r10
  int v33; // r3
  int arrayIndex; // r11
  __int64 v35; // r8
  __int64 v36; // r6
  int v37; // r3
  unsigned __int8 *v38; // r11
  int v39; // r10
  int v40; // r10
  unsigned __int8 *v41; // r11
  int ClassIndex; // r3
  const char *v43; // r11
  classTypeInfo_t *v44; // r29
  int v45; // r5
  unsigned __int8 *v46; // r11
  int size; // r9
  int v48; // r10
  int v49; // r11
  int v50; // r10
  int v51; // r3
  unsigned __int8 *v52; // r11
  idStr v53; // [sp+60h] [-180h] BYREF
  int v54; // [sp+94h] [-14Ch]
  float v55; // [sp+98h] [-148h]
  int v56; // [sp+9Ch] [-144h]
  int v57; // [sp+A0h] [-140h]
  int v58; // [sp+A4h] [-13Ch]
  idLexer v59; // [sp+B0h] [-130h] BYREF
  idStr v60[5]; // [sp+140h] [-A0h] BYREF

  v53.len = 0;
  v53.baseBuffer[0] = 0;
  v55 = -3.4028235e38;
  v54 = 0;
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v53.allocedAndFlag = 20;
  v53.data = v53.baseBuffer;
  idLexer::idLexer(this: &v59, flags_: 0);
  v8 = 0;
  if ( *path != 0 )
  {
    do
      ++v8;
    while ( path[v8] != 0 );
    if ( v8 != 0 )
    {
      HIDWORD(v11) = 0;
      do
        ++HIDWORD(v11);
      while ( path[HIDWORD(v11)] != 0 );
      LODWORD(v11) = &byte_8200D768;
      LODWORD(v6) = (unsigned __int8)path[v8];
      LODWORD(v7) = *(unsigned __int8 *)path;
      idLexer::LoadMemory(this: &v59, ptr: path, name: v11, a4: v7, a5: v6);
      LODWORD(v12) = &unk_821D0000;
      HIDWORD(v12) = &unk_821D0000;
      while ( 1 )
      {
        idLexer::ExpectTokenType(this: &v59, type: 4, token: (unsigned int)&v53, a4: v12);
        ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: info->type.data);
        if ( ClassInfo == nullptr )
          goto LABEL_44;
        while ( 1 )
        {
          ClassVariableInfo = idTypeInfoTools::FindClassVariableInfo(this, classInfo: ClassInfo, name: v53.data);
          if ( ClassVariableInfo != nullptr )
            break;
          ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: ClassInfo->superType);
          if ( ClassInfo == nullptr )
            goto LABEL_44;
        }
        idStr::operator=(this: &info->type, text: (char *)ClassVariableInfo->type);
        p_ops = &info->ops;
        idStr::operator=(this: &info->ops, text: (char *)ClassVariableInfo->ops);
        idStr::operator=(this: &info->name, text: (char *)ClassVariableInfo->name);
        info->arrayIndex = -1;
        p_metaData = &info->metaData;
        info->flags = ClassVariableInfo->flags;
        info->size = ClassVariableInfo->size;
        info->get = ClassVariableInfo->get;
        info->set = ClassVariableInfo->set;
        if ( info->metaData.listStatic == 0 || info->metaData.listStatic == 2 )
        {
          if ( p_metaData->list != nullptr )
            idListArrayDelete<idStr>(ptr: p_metaData->list, num: info->metaData.size);
          p_metaData->list = nullptr;
          info->metaData.size = 0;
        }
        v17 = ClassInfo;
        info->metaData.num = 0;
        do
        {
          for ( i = 0; ; ++i )
          {
            metaData = v17->metaData[i].metaData;
            if ( metaData == nullptr )
              break;
            idStr::idStr(this: v60, text: metaData);
            idList<idStr,5>::Append(this: &info->metaData, obj: v60);
            idStr::FreeData(this: v60);
          }
          v17 = idTypeInfoTools::FindClassInfo(this, typeName: v17->superType);
        }
        while ( v17 != nullptr );
        objectPtr = info->objectPtr;
        if ( objectPtr != nullptr )
          info->objectPtr = &objectPtr[ClassVariableInfo->offset];
        flags = info->flags;
        if ( (flags & 0x80000) != 0 )
          ++info->editDepth;
        if ( (flags & 0x100000) != 0 )
          ++info->designDepth;
        if ( (flags & 0x200000) != 0 )
          ++info->defDepth;
        if ( *info->ops.data == 91
          && (unsigned __int8)idLexer::CheckTokenString(this: &v59, string: ".", a3: v21, a4: v20) != 0
          || (unsigned __int8)idLexer::CheckTokenString(this: &v59, string: "[", a3: v21, a4: v20) != 0 )
        {
          idLexer::CheckTokenString(this: &v59, string: info->name.data, a3: v21, a4: v20);
          idLexer::CheckTokenString(this: &v59, string: "[", a3: v25, a4: v24);
          info->arrayIndex = idLexer::ParseInt(this: &v59, a2: v28, a3: v27, a4: v26);
          idLexer::ExpectTokenString(this: &v59, string: "]", a3: v30, a4: v29);
          len = p_ops->len;
          if ( p_ops->len != 0 )
          {
            data = info->ops.data;
            if ( data[len - 1] == 93 )
            {
              v33 = idTypeInfoTools::StripArraySize(this, ops: &info->ops);
              arrayIndex = info->arrayIndex;
              if ( arrayIndex < 0 )
                goto LABEL_44;
              if ( arrayIndex >= v33 )
                goto LABEL_44;
              v37 = idTypeInfoTools::SizeForType(this, varType: info->type.data, varOps: info->ops.data);
              info->size = v37;
              if ( v37 == -1 )
                goto LABEL_44;
              v38 = info->objectPtr;
              if ( v38 != nullptr )
              {
                v39 = info->arrayIndex;
LABEL_41:
                info->objectPtr = &v38[v37 * v39];
              }
            }
            else
            {
              if ( data[len - 1] != 42 )
                goto LABEL_44;
              v40 = len - 1;
              if ( p_ops->len > len - 1 && v40 >= 0 )
              {
                info->ops.data[v40] = 0;
                p_ops->len = v40;
              }
              v37 = idTypeInfoTools::SizeForType(this, varType: info->type.data, varOps: info->ops.data);
              info->size = v37;
              if ( v37 == -1 )
                goto LABEL_44;
              v41 = info->objectPtr;
              if ( v41 != nullptr )
              {
                v39 = info->arrayIndex;
                v38 = *(unsigned __int8 **)v41;
                goto LABEL_41;
              }
            }
          }
          else
          {
            ClassIndex = idTypeInfoTools::FindClassIndex(this, typeName: info->type.data);
            if ( ClassIndex == -1 )
              goto LABEL_44;
            v43 = "idList";
            v44 = &this->typeInfo->classes[ClassIndex];
            v45 = 0;
            do
            {
              ++v43;
              ++v45;
            }
            while ( *v43 != 0 );
            if ( idStr::Cmpn(s1: v44->name, s2: "idList", n: v45) != 0 )
              goto LABEL_44;
            v46 = info->objectPtr;
            size = v44->templateParms->size;
            info->size = size;
            if ( v46 != nullptr )
            {
              v48 = info->arrayIndex;
              if ( v48 < 0 || v48 >= *((_DWORD *)v46 + 1) )
                goto LABEL_44;
              info->objectPtr = (unsigned __int8 *)(size * v48 + *(_DWORD *)v46);
            }
            idStr::operator=(this: &info->type, text: (char *)v44->templateParms->type);
            idStr::operator=(this: &info->ops, text: (char *)v44->templateParms->ops);
          }
LABEL_42:
          if ( (unsigned __int8)idLexer::CheckTokenString(this: &v59, string: ".", a3: v36, a4: v35) == 0 )
          {
            idLexer::~idLexer(this: &v59);
            idStr::FreeData(this: &v53);
            return 1;
          }
          if ( p_ops->len != 0 )
            goto LABEL_44;
        }
        else
        {
          if ( (unsigned __int8)idLexer::CheckTokenString(this: &v59, string: "->", a3: v21, a4: v20) == 0 )
            goto LABEL_42;
          v49 = p_ops->len;
          if ( p_ops->len == 0 || info->ops.data[v49 - 1] != 42 )
            goto LABEL_44;
          v50 = v49 - 1;
          if ( v49 > v49 - 1 && v50 >= 0 )
          {
            info->ops.data[v50] = 0;
            p_ops->len = v50;
          }
          v51 = idTypeInfoTools::SizeForType(this, varType: info->type.data, varOps: info->ops.data);
          info->size = v51;
          if ( v51 == -1 )
            goto LABEL_44;
          v52 = info->objectPtr;
          if ( v52 != nullptr )
            info->objectPtr = *(unsigned __int8 **)v52;
        }
      }
    }
  }
  v9 = idTypeInfoTools::FindClassInfo(this, typeName: info->type.data);
  if ( v9 != nullptr )
  {
    info->size = v9->size;
    idLexer::~idLexer(this: &v59);
    idStr::FreeData(this: &v53);
    return 1;
  }
  else
  {
LABEL_44:
    idLexer::~idLexer(this: &v59);
    idStr::FreeData(this: &v53);
    return 0;
  }
}


// ========================================================================
// __unwind$117839
// EA  : 0x82FA0148
// RVA : 0x00FA0148
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117839()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 96));
}


// ========================================================================
// __unwind$117840
// EA  : 0x82FA0170
// RVA : 0x00FA0170
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117840()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 480 + 176));
}


// ========================================================================
// __unwind$117841
// EA  : 0x82FA0198
// RVA : 0x00FA0198
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_117841()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 320));
}


// ========================================================================
// ?GetPointerForPath@idTypeInfoTools@@QBA_NPBD0AAPAX@Z
// EA  : 0x82FA02C0
// RVA : 0x00FA02C0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::GetPointerForPath(
        idTypeInfoTools *this,
        const char *typeName,
        const char *path,
        unsigned __int8 **objectPtr)
{
  char *v7; // r4
  idPathTypeInfo v9; // [sp+50h] [-C0h] BYREF

  idPathTypeInfo::idPathTypeInfo(this: &v9);
  idStr::operator=(this: &v9.type, text: v7);
  v9.objectPtr = *objectPtr;
  v9.flags = 0;
  if ( (unsigned __int8)idTypeInfoTools::TypeInfoForPath(this, info: &v9, path) != 0 && v9.size >= 0 )
  {
    *objectPtr = v9.objectPtr;
    idPathTypeInfo::~idPathTypeInfo(this: &v9);
    return 1;
  }
  else
  {
    idPathTypeInfo::~idPathTypeInfo(this: &v9);
    return 0;
  }
}


// ========================================================================
// __unwind$118347
// EA  : 0x82FA0360
// RVA : 0x00FA0360
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118347()
{
  int v0; // r12

  idPathTypeInfo::~idPathTypeInfo(this: (idPathTypeInfo *)(v0 - 272 + 80));
}


// ========================================================================
// ?FindClassVariablePathsForType_r@idTypeInfoTools@@ABAXPBDPBUclassTypeInfo_t@@00AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82FA0390
// RVA : 0x00FA0390
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::FindClassVariablePathsForType_r(
        idTypeInfoTools *this,
        const char *path,
        const classTypeInfo_t *classInfo,
        const char *typeName,
        const char *ops,
        idList<idStr,5> *variablePaths)
{
  const classVariableInfo_t *variables; // r11
  int v13; // r28
  int v14; // r30
  const classVariableInfo_t *v15; // r11
  const classTypeInfo_t *v16; // r3
  idStr v17[4]; // [sp+50h] [-80h] BYREF

  variables = classInfo->variables;
  v13 = 0;
  if ( variables->name != nullptr )
  {
    v14 = 0;
    do
    {
      if ( (variables->flags & 0x380000) != 0 )
      {
        idStr::idStr(this: v17, text: path);
        idStr::EnsureAlloced(this: v17, amount: v17[0].len + 2, keepold: true, geometricGrowth: true);
        v17[0].data[v17[0].len] = 46;
        v17[0].data[++v17[0].len] = 0;
        idStr::Append(this: v17, text: (char *)classInfo->variables[v14].name);
        if ( idStr::Cmp(s1: typeName, s2: classInfo->variables[v14].type) == 0
          && idStr::Cmp(s1: ops, s2: classInfo->variables[v14].ops) == 0 )
        {
          idList<idStr,5>::Append(this: variablePaths, obj: v17);
        }
        v15 = &classInfo->variables[v14];
        if ( *v15->ops != 42 )
        {
          v16 = idTypeInfoTools::FindClassInfo(this, typeName: v15->type);
          if ( v16 != nullptr && v16->variables != nullptr )
            idTypeInfoTools::FindClassVariablePathsForType_r(
              this,
              path: v17[0].data,
              classInfo: v16,
              typeName,
              ops,
              variablePaths);
        }
        idStr::FreeData(this: v17);
      }
      v14 = ++v13;
      variables = &classInfo->variables[v13];
    }
    while ( variables->name != nullptr );
  }
}


// ========================================================================
// __unwind$118387
// EA  : 0x82FA0510
// RVA : 0x00FA0510
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118387()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 80));
}


// ========================================================================
// ?FindClassVariablePathsForType@idTypeInfoTools@@QBAXPBUclassTypeInfo_t@@PBD1AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82FA0540
// RVA : 0x00FA0540
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::FindClassVariablePathsForType(
        idTypeInfoTools *this,
        const classTypeInfo_t *classInfo,
        const char *typeName,
        const char *ops,
        idList<idStr,5> *variablePaths)
{
  const classVariableInfo_t *variables; // r11
  int v11; // r28
  int v12; // r30
  const classVariableInfo_t *v13; // r11
  const classVariableInfo_t *v14; // r11
  const classTypeInfo_t *v15; // r3
  idStr v16[3]; // [sp+50h] [-70h] BYREF

  variables = classInfo->variables;
  v11 = 0;
  if ( variables->name != nullptr )
  {
    v12 = 0;
    do
    {
      v13 = &variables[v12];
      if ( (v13->flags & 0x380000) != 0 )
      {
        if ( idStr::Cmp(s1: typeName, s2: v13->type) == 0 && idStr::Cmp(s1: ops, s2: classInfo->variables[v12].ops) == 0 )
        {
          idStr::idStr(this: v16, text: classInfo->variables[v12].name);
          idList<idStr,5>::Append(this: variablePaths, obj: v16);
          idStr::FreeData(this: v16);
        }
        v14 = &classInfo->variables[v12];
        if ( *v14->ops != 42 )
        {
          v15 = idTypeInfoTools::FindClassInfo(this, typeName: v14->type);
          if ( v15 != nullptr && v15->variables != nullptr )
            idTypeInfoTools::FindClassVariablePathsForType_r(
              this,
              path: classInfo->variables[v12].name,
              classInfo: v15,
              typeName,
              ops,
              variablePaths);
        }
      }
      ++v11;
      variables = classInfo->variables;
      v12 = v11;
    }
    while ( variables[v11].name != nullptr );
  }
}


// ========================================================================
// __unwind$118432
// EA  : 0x82FA0670
// RVA : 0x00FA0670
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118432()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?FindClassVariablePathsForTemplateType_r@idTypeInfoTools@@ABAXPBDPBUclassTypeInfo_t@@0H0AAV?$idList@VidStr@@$04@@2@Z
// EA  : 0x82FA06A0
// RVA : 0x00FA06A0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::FindClassVariablePathsForTemplateType_r(
        idTypeInfoTools *this,
        const char *path,
        const classTypeInfo_t *classInfo,
        const char *templateTypeName,
        int typeNameLen,
        const char *ops,
        idList<idStr,5> *variablePaths,
        idList<idStr,5> *variableTypes)
{
  const classVariableInfo_t *variables; // r11
  int v17; // r25
  int v18; // r30
  int v19; // r28
  int v20; // r3
  const classVariableInfo_t *v21; // r11
  const classTypeInfo_t *v22; // r3
  idStr v23; // [sp+50h] [-C0h] BYREF
  idStr v24[5]; // [sp+70h] [-A0h] BYREF

  variables = classInfo->variables;
  v17 = 0;
  if ( variables->name != nullptr )
  {
    v18 = 0;
    do
    {
      if ( (variables->flags & 0x380000) != 0 )
      {
        idStr::idStr(this: &v23, text: path);
        idStr::EnsureAlloced(this: &v23, amount: v23.len + 2, keepold: true, geometricGrowth: true);
        v23.data[v23.len] = 46;
        v23.data[++v23.len] = 0;
        idStr::Append(this: &v23, text: (char *)classInfo->variables[v18].name);
        if ( idStr::Find(
               searchIn: classInfo->variables[v18].type,
               searchFor: templateTypeName,
               casesensitive: true,
               start: 0,
               end: -1) == 0
          && idStr::Cmp(s1: ops, s2: classInfo->variables[v18].ops) == 0 )
        {
          v19 = idStr::Find(str: &classInfo->variables[v18].type[typeNameLen], c: 60, start: 0, end: -1);
          v20 = idStr::Find(str: &classInfo->variables[v18].type[typeNameLen], c: 62, start: 0, end: -1);
          if ( v19 != -1 && v19 < v20 )
          {
            idList<idStr,5>::Append(this: variablePaths, obj: &v23);
            idStr::idStr(this: v24, text: classInfo->variables[v18].type);
            idList<idStr,5>::Append(this: variableTypes, obj: v24);
            idStr::FreeData(this: v24);
          }
        }
        v21 = &classInfo->variables[v18];
        if ( *v21->ops != 42 )
        {
          v22 = idTypeInfoTools::FindClassInfo(this, typeName: v21->type);
          if ( v22 != nullptr && v22->variables != nullptr )
            idTypeInfoTools::FindClassVariablePathsForTemplateType_r(
              this,
              path: v23.data,
              classInfo: v22,
              templateTypeName,
              typeNameLen,
              ops,
              variablePaths,
              variableTypes);
        }
        idStr::FreeData(this: &v23);
      }
      v18 = ++v17;
      variables = &classInfo->variables[v17];
    }
    while ( variables->name != nullptr );
  }
}


// ========================================================================
// __unwind$118456
// EA  : 0x82FA08AC
// RVA : 0x00FA08AC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118456()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$118457
// EA  : 0x82FA08D4
// RVA : 0x00FA08D4
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118457()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 112));
}


// ========================================================================
// ?FindClassVariablePathsForTemplateType@idTypeInfoTools@@QBAXPBUclassTypeInfo_t@@PBD1AAV?$idList@VidStr@@$04@@2@Z
// EA  : 0x82FA0908
// RVA : 0x00FA0908
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::FindClassVariablePathsForTemplateType(
        idTypeInfoTools *this,
        const classTypeInfo_t *classInfo,
        const char *templateTypeName,
        const char *ops,
        idList<idStr,5> *variablePaths,
        idList<idStr,5> *variableTypes)
{
  int v12; // r27
  const classVariableInfo_t *variables; // r11
  int v14; // r22
  int v15; // r30
  const classVariableInfo_t *v16; // r11
  int v17; // r28
  int v18; // r3
  const classVariableInfo_t *v19; // r11
  const classTypeInfo_t *v20; // r3
  idStr v21; // [sp+50h] [-A0h] BYREF
  idStr v22[4]; // [sp+70h] [-80h] BYREF

  v12 = 0;
  if ( *templateTypeName != 0 )
  {
    do
      ++v12;
    while ( templateTypeName[v12] != 0 );
  }
  variables = classInfo->variables;
  v14 = 0;
  if ( variables->name != nullptr )
  {
    v15 = 0;
    do
    {
      v16 = &variables[v15];
      if ( (v16->flags & 0x380000) != 0 )
      {
        if ( idStr::Find(searchIn: v16->type, searchFor: templateTypeName, casesensitive: true, start: 0, end: -1) == 0
          && idStr::Cmp(s1: ops, s2: classInfo->variables[v15].ops) == 0 )
        {
          v17 = idStr::Find(str: &classInfo->variables[v15].type[v12], c: 60, start: 0, end: -1);
          v18 = idStr::Find(str: &classInfo->variables[v15].type[v12], c: 62, start: 0, end: -1);
          if ( v17 != -1 && v17 < v18 )
          {
            idStr::idStr(this: &v21, text: classInfo->variables[v15].name);
            idList<idStr,5>::Append(this: variablePaths, obj: &v21);
            idStr::FreeData(this: &v21);
            idStr::idStr(this: v22, text: classInfo->variables[v15].type);
            idList<idStr,5>::Append(this: variableTypes, obj: v22);
            idStr::FreeData(this: v22);
          }
        }
        v19 = &classInfo->variables[v15];
        if ( *v19->ops != 42 )
        {
          v20 = idTypeInfoTools::FindClassInfo(this, typeName: v19->type);
          if ( v20 != nullptr && v20->variables != nullptr )
            idTypeInfoTools::FindClassVariablePathsForTemplateType_r(
              this,
              path: classInfo->variables[v15].name,
              classInfo: v20,
              templateTypeName,
              typeNameLen: v12,
              ops,
              variablePaths,
              variableTypes);
        }
      }
      ++v14;
      variables = classInfo->variables;
      v15 = v14;
    }
    while ( variables[v14].name != nullptr );
  }
}


// ========================================================================
// __unwind$118514
// EA  : 0x82FA0AE0
// RVA : 0x00FA0AE0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118514()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$118515
// EA  : 0x82FA0B08
// RVA : 0x00FA0B08
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118515()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ?FindClassVariablePathsForTypeIncludingInherited@idTypeInfoTools@@QBAXPBUclassTypeInfo_t@@PBD1AAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82FA0B30
// RVA : 0x00FA0B30
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::FindClassVariablePathsForTypeIncludingInherited(
        idTypeInfoTools *this,
        const classTypeInfo_t *classInfo,
        const char *templateTypeName,
        const char *ops,
        idList<idStr,5> *variablePaths)
{
  int v5; // r28
  const char *superType; // r4
  idStr *v12; // r3
  char v13; // r11
  char v14; // r30
  idStr v15[3]; // [sp+60h] [-60h] BYREF

  v5 = 0;
  while ( 1 )
  {
    idTypeInfoTools::FindClassVariablePathsForType(this, classInfo, typeName: templateTypeName, ops, variablePaths);
    if ( classInfo == nullptr
      || (superType = classInfo->superType) == nullptr
      || (v12 = idStr::idStr(this: v15, text: superType), v5 |= 1u, v13 = 1, v12->len == 0) )
    {
      v13 = 0;
    }
    v14 = v13;
    if ( (v5 & 1) != 0 )
    {
      v5 &= ~1u;
      idStr::FreeData(this: v15);
    }
    if ( v14 == 0 )
      break;
    classInfo = idTypeInfoTools::FindClassInfo(this, typeName: classInfo->superType);
  }
}


// ========================================================================
// ?FindClassVariablePathsForTemplateTypeIncludingInherited@idTypeInfoTools@@QBAXPBUclassTypeInfo_t@@PBD1AAV?$idList@VidStr@@$04@@2@Z
// EA  : 0x82FA0BE8
// RVA : 0x00FA0BE8
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::FindClassVariablePathsForTemplateTypeIncludingInherited(
        idTypeInfoTools *this,
        const classTypeInfo_t *classInfo,
        const char *templateTypeName,
        const char *ops,
        idList<idStr,5> *variablePaths,
        idList<idStr,5> *variableTypes)
{
  int v6; // r24
  const char *superType; // r4
  idStr *v14; // r3
  char v15; // r11
  char v16; // r29
  idStr v17[3]; // [sp+60h] [-70h] BYREF

  v6 = 0;
  while ( 1 )
  {
    idTypeInfoTools::FindClassVariablePathsForTemplateType(
      this,
      classInfo,
      templateTypeName,
      ops,
      variablePaths,
      variableTypes);
    if ( classInfo == nullptr
      || (superType = classInfo->superType) == nullptr
      || (v14 = idStr::idStr(this: v17, text: superType), v6 |= 1u, v15 = 1, v14->len == 0) )
    {
      v15 = 0;
    }
    v16 = v15;
    if ( (v6 & 1) != 0 )
    {
      v6 &= ~1u;
      idStr::FreeData(this: v17);
    }
    if ( v16 == 0 )
      break;
    classInfo = idTypeInfoTools::FindClassInfo(this, typeName: classInfo->superType);
  }
}


// ========================================================================
// ?AddWarning@idTypeInfoTools@@QBAXPBDZZ
// EA  : 0x82FA0CB0
// RVA : 0x00FA0CB0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idTypeInfoTools::AddWarning(
        idTypeInfoTools *this,
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
  idList<idStr,5> *p_warnings; // r30
  idStr v13; // [sp+60h] [-1040h] BYREF
  char v14[4104]; // [sp+80h] [-1020h] BYREF
  __int64 v15; // [sp+10C0h] [+20h] BYREF
  va_list va; // [sp+10C0h] [+20h]
  __int64 v17; // [sp+10C8h] [+28h]
  __int64 v18; // [sp+10D0h] [+30h]
  __int64 v19; // [sp+10D8h] [+38h]
  __int64 v20; // [sp+10E0h] [+40h]
  __int64 v21; // [sp+10E8h] [+48h]
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
  v15 = *(__int64 *)((char *)&a3 + 4);
  v17 = a3;
  v18 = *(__int64 *)((char *)&a4 + 4);
  v19 = a4;
  v20 = *(__int64 *)((char *)&a5 + 4);
  v21 = a5;
  idStr::vsnPrintf(dest: v14, size: 4096, fmt, argptr: va);
  v14[4095] = 0;
  idStr::idStr(this: &v13, text: v14);
  p_warnings = &this->warnings;
  if ( idList<idStr,5>::FindIndex(this: p_warnings, obj: &v13, startIndex: 0) < 0 )
    idList<idStr,5>::Append(this: p_warnings, obj: &v13);
  idStr::FreeData(this: &v13);
}


// ========================================================================
// __unwind$118768
// EA  : 0x82FA0D68
// RVA : 0x00FA0D68
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118768()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 96));
}


// ========================================================================
// ?GetTypeForPath@idTypeInfoTools@@QBA_NPBD0PADH1H@Z
// EA  : 0x82FA0D98
// RVA : 0x00FA0D98
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::GetTypeForPath(
        idTypeInfoTools *this,
        const char *typeName,
        const char *path,
        char *type,
        int maxTypeLen,
        char *ops,
        int maxOpsLen)
{
  char *v13; // r4
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  idPathTypeInfo v21; // [sp+50h] [-E0h] BYREF

  idPathTypeInfo::idPathTypeInfo(this: &v21);
  idStr::operator=(this: &v21.type, text: v13);
  v21.flags = 0;
  v21.objectPtr = nullptr;
  if ( (unsigned __int8)idTypeInfoTools::TypeInfoForPath(this, info: &v21, path) != 0 )
  {
    HIDWORD(v16) = maxTypeLen;
    idStr::Copynz(src: __SPAIR64__((unsigned int)type, (unsigned int)v21.type.data), destsize: v16, a3: v15, a4: v14);
    HIDWORD(v18) = maxOpsLen;
    idStr::Copynz(src: __SPAIR64__((unsigned int)ops, (unsigned int)v21.ops.data), destsize: v18, a3: v20, a4: v19);
    idPathTypeInfo::~idPathTypeInfo(this: &v21);
    return 1;
  }
  else
  {
    idPathTypeInfo::~idPathTypeInfo(this: &v21);
    return 0;
  }
}


// ========================================================================
// __unwind$118796
// EA  : 0x82FA0E3C
// RVA : 0x00FA0E3C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118796()
{
  int v0; // r12

  idPathTypeInfo::~idPathTypeInfo(this: (idPathTypeInfo *)(v0 - 304 + 80));
}


// ========================================================================
// ?WriteUnknownType@idTypeInfoTools@@ABAXPAVidTypeInfoFile@@PBD111H1@Z
// EA  : 0x82FA0E68
// RVA : 0x00FA0E68
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::WriteUnknownType(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment)
{
  __int64 v15; // r10
  int v16; // [sp+8h] [-C8h]
  int v17; // [sp+Ch] [-C4h]
  int v18; // [sp+10h] [-C0h]
  int v19; // [sp+14h] [-BCh]
  int v20; // [sp+18h] [-B8h]
  int v21; // [sp+1Ch] [-B4h]

  idTypeInfoFile::WriteUnknown(this: file);
  idTypeInfoFile::WriteComment(this: file, comment);
  idTypeInfoTools::AddWarning(
    this,
    fmt: "%s %s %s::%s = <unknown>;",
    a3: __SPAIR64__((unsigned int)varType, (unsigned int)varOps),
    a4: __SPAIR64__((unsigned int)scope, (unsigned int)varName),
    a5: v15,
    a6: v16,
    a7: v17,
    a8: v18,
    a9: v19,
    a10: v20,
    a11: v21);
}


// ========================================================================
// ?WriteFunctionPointer@idTypeInfoTools@@ABAHPAVidTypeInfoFile@@PBD111H1PAX@Z
// EA  : 0x82FA0ED0
// RVA : 0x00FA0ED0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::WriteFunctionPointer(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        void **a28)
{
  int v36; // r11
  functionPointerInfo_t *functionPointers; // r9
  functionPointerInfo_t *v38; // r10
  const char *name; // r4
  __int64 v41; // r10
  int v42; // [sp+8h] [-D8h]
  int v43; // [sp+Ch] [-D4h]
  int v44; // [sp+10h] [-D0h]
  int v45; // [sp+14h] [-CCh]
  int v46; // [sp+18h] [-C8h]
  int v47; // [sp+1Ch] [-C4h]

  if ( *a28 != nullptr )
  {
    v36 = 0;
    functionPointers = this->typeInfo->functionPointers;
    if ( functionPointers->name != nullptr )
    {
      v38 = this->typeInfo->functionPointers;
      do
      {
        if ( *a28 == v38->ptr )
          break;
        v38 = &functionPointers[++v36];
      }
      while ( v38->name != nullptr );
    }
    name = functionPointers[v36].name;
    if ( name != nullptr )
    {
      idTypeInfoFile::WriteStr(this: file, s: name);
      idTypeInfoFile::WriteComment(this: file, comment);
    }
    else
    {
      idTypeInfoFile::WriteUnknown(this: file);
      idTypeInfoFile::WriteComment(this: file, comment);
      idTypeInfoTools::AddWarning(
        this,
        fmt: "%s %s %s::%s = <unknown>;",
        a3: __SPAIR64__((unsigned int)varType, (unsigned int)varOps),
        a4: __SPAIR64__((unsigned int)scope, (unsigned int)varName),
        a5: v41,
        a6: v42,
        a7: v43,
        a8: v44,
        a9: v45,
        a10: v46,
        a11: v47);
    }
    return 4;
  }
  else
  {
    idTypeInfoFile::WriteNullPointer(this: file);
    idTypeInfoFile::WriteComment(this: file, comment);
    return 4;
  }
}


// ========================================================================
// ?WriteObject_r@idTypeInfoTools@@ABAHPAVidTypeInfoFile@@PBD111H1PAX_N@Z
// EA  : 0x82FA0FE0
// RVA : 0x00FA0FE0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::WriteObject_r(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        bool allowSpecialCase,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _DWORD *a28,
        int a29,
        char a30)
{
  int ClassIndex; // r3
  classTypeInfo_t *v39; // r28
  void (__fastcall *v40)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *); // r11
  const char *superType; // r4
  const classTypeInfo_t *ClassInfo; // r3
  __int64 v44; // r6
  int EnumIndex; // r3
  __int64 v46; // r8
  enumTypeInfo_t *v47; // r28
  void (__fastcall *Write)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *); // r11
  __int64 v49; // r10
  const enumValueInfo_t *v50; // r11
  va *v51; // r4
  int v52; // r29
  int v53; // r30
  const enumValueInfo_t *values; // r10
  int value; // r10
  int v56; // r11
  __int64 v57; // r10
  int v58; // [sp+8h] [-1118h]
  int v59; // [sp+Ch] [-1114h]
  int v60; // [sp+10h] [-1110h]
  int v61; // [sp+14h] [-110Ch]
  int v62; // [sp+18h] [-1108h]
  int v63; // [sp+1Ch] [-1104h]
  idStr v64; // [sp+A0h] [-1080h] BYREF
  va v65; // [sp+C0h] [-1060h] BYREF

  ClassIndex = idTypeInfoTools::FindClassIndex(this, typeName: varType);
  if ( ClassIndex == -1 )
  {
    EnumIndex = idTypeInfoTools::FindEnumIndex(this, typeName: varType);
    if ( EnumIndex == -1 )
    {
      idTypeInfoTools::FindTypeDefIndex(this, typeName: varType);
      idTypeInfoFile::WriteUnknown(this: file);
      idTypeInfoFile::WriteComment(this: file, comment);
      idTypeInfoTools::AddWarning(
        this,
        fmt: "%s %s %s::%s = <unknown>;",
        a3: __SPAIR64__((unsigned int)varType, (unsigned int)varOps),
        a4: __SPAIR64__((unsigned int)scope, (unsigned int)varName),
        a5: v57,
        a6: v58,
        a7: v59,
        a8: v60,
        a9: v61,
        a10: v62,
        a11: v63);
      return -1;
    }
    else
    {
      LODWORD(v46) = 3 * EnumIndex;
      v47 = &this->typeInfo->enums[EnumIndex];
      if ( a30 != 0 && (Write = this->enumObject.list[EnumIndex].Write) != nullptr )
      {
        ((void (__fastcall *)(idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *))Write)(
          a1: this,
          a2: file,
          a3: scope,
          a4: varType,
          a5: varOps,
          a6: varName,
          a7: varFlags,
          a8: comment);
        return 4;
      }
      else
      {
        LODWORD(v49) = v47->flags & 0x400000;
        if ( (_DWORD)v49 != 0 )
        {
          v52 = 0;
          v64.len = 0;
          v64.baseBuffer[0] = 0;
          v64.data = v64.baseBuffer;
          v64.allocedAndFlag = 20;
          if ( v47->values->name != nullptr )
          {
            v53 = 0;
            values = v47->values;
            do
            {
              value = values->value;
              if ( value != 0 )
              {
                v56 = v47->values[v53].value;
                if ( ((v56 - 1) & v56) == 0 && (value & *a28) != 0 )
                {
                  if ( v64.len != 0 )
                    idStr::operator+=(this: &v64, a: 32);
                  idStr::Append(this: &v64, text: (char *)v47->values[v53].name);
                }
              }
              v53 = ++v52;
              values = &v47->values[v52];
            }
            while ( values->name != nullptr );
          }
          idTypeInfoFile::WriteStr(this: file, s: v64.data);
          idTypeInfoFile::WriteComment(this: file, comment);
          idStr::FreeData(this: &v64);
          return 4;
        }
        else
        {
          HIDWORD(v49) = v47->values;
          HIDWORD(v46) = a28;
          if ( *(_DWORD *)HIDWORD(v49) != 0 )
          {
            LODWORD(v46) = *a28;
            v50 = v47->values;
            do
            {
              if ( (_DWORD)v46 == v50->value )
                break;
              LODWORD(v49) = v49 + 1;
              v50 = (const enumValueInfo_t *)(8 * v49 + HIDWORD(v49));
              LODWORD(v44) = v50->name;
            }
            while ( v50->name != nullptr );
          }
          v51 = *(va **)(8 * v49 + HIDWORD(v49));
          if ( v51 == nullptr )
          {
            HIDWORD(v44) = *a28;
            v51 = va::va(
                    this: &v65,
                    fmt: "%d",
                    a3: v44,
                    a4: v46,
                    a5: v49,
                    a6: v58,
                    a7: v59,
                    a8: v60,
                    a9: v61,
                    a10: v62,
                    a11: v63);
          }
          idTypeInfoFile::WriteStr(this: file, s: v51->buffer);
          idTypeInfoFile::WriteComment(this: file, comment);
          return 4;
        }
      }
    }
  }
  else
  {
    v39 = &this->typeInfo->classes[ClassIndex];
    if ( a30 != 0 && (v40 = this->classObject.list[ClassIndex].Write) != nullptr )
    {
      ((void (__fastcall *)(idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *))v40)(
        a1: this,
        a2: file,
        a3: scope,
        a4: varType,
        a5: varOps,
        a6: varName,
        a7: varFlags,
        a8: comment);
      return v39->size;
    }
    else
    {
      idTypeInfoFile::WriteOpeningBrace(this: file);
      idTypeInfoFile::WriteComment(this: file, comment);
      superType = v39->superType;
      if ( *superType != 0 )
      {
        ClassInfo = idTypeInfoTools::FindClassInfo(this, typeName: superType);
        idTypeInfoTools::WriteSuperClassVariables(this, file, superInfo: ClassInfo, varPtr: a28);
      }
      idTypeInfoTools::WriteClassVariables(this, file, classInfo: v39, varPtr: (int)a28);
      idTypeInfoFile::WriteClosingBrace(this: file);
      idTypeInfoFile::WriteComment(this: file, comment: &byte_8200D768);
      return v39->size;
    }
  }
}


// ========================================================================
// __unwind$118859
// EA  : 0x82FA1344
// RVA : 0x00FA1344
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118859()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 160));
}


// ========================================================================
// ?WriteType_r@idTypeInfoTools@@QBAHPAVidTypeInfoFile@@PBD111H1PAX_N@Z
// EA  : 0x82FA1378
// RVA : 0x00FA1378
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::WriteType_r(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *scope,
        const char *varType,
        const char *varOps,
        const char *varName,
        int varFlags,
        const char *comment,
        void *varPtr,
        bool allowSpecialCase,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        void **a28,
        int a29,
        char a30)
{
  int ClassIndex; // r3
  void (__fastcall *Write)(const idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, const char *, const char *, int, const char *, void *); // r11
  int EnumIndex; // r3
  int v42; // r11
  int v43; // r3
  int v44; // r30
  int v45; // r30
  void *v46; // [sp+8h] [-D8h]
  int v47; // [sp+Ch] [-D4h]
  int v48; // [sp+10h] [-D0h]
  int v49; // [sp+14h] [-CCh]
  int v50; // [sp+18h] [-C8h]
  int v51; // [sp+1Ch] [-C4h]
  int v52; // [sp+20h] [-C0h]
  int v53; // [sp+24h] [-BCh]
  int v54; // [sp+28h] [-B8h]
  int v55; // [sp+2Ch] [-B4h]
  int v56; // [sp+30h] [-B0h]
  int v57; // [sp+34h] [-ACh]
  int v58; // [sp+38h] [-A8h]
  int v59; // [sp+3Ch] [-A4h]
  int v60; // [sp+40h] [-A0h]
  int v61; // [sp+44h] [-9Ch]
  int v62; // [sp+48h] [-98h]
  int v63; // [sp+4Ch] [-94h]
  int v64; // [sp+50h] [-90h]
  int v65; // [sp+58h] [-88h]
  idStr v66[4]; // [sp+60h] [-80h] BYREF

  if ( *varOps == 0 )
    return idTypeInfoTools::WriteObject_r(
             this,
             file,
             scope,
             varType,
             varOps,
             varName,
             varFlags,
             comment,
             varPtr: v46,
             allowSpecialCase: v47,
             a11: v48,
             a12: v49,
             a13: v50,
             a14: v51,
             a15: v52,
             a16: v53,
             a17: v54,
             a18: v55,
             a19: v56,
             a20: v57,
             a21: v58,
             a22: v59,
             a23: v60,
             a24: v61,
             a25: v62,
             a26: v63,
             a27: v64,
             a28,
             a29: v65,
             a30);
  idStr::idStr(this: v66, text: varOps);
  if ( *v66[0].data != 42 || v66[0].data[1] != 0 )
  {
    v42 = v66[0].data[v66[0].len - 1];
    if ( v42 == 93 )
    {
      idTypeInfoFile::WriteOpeningBrace(this: file);
      idTypeInfoFile::WriteComment(this: file, comment);
      v43 = idTypeInfoTools::StripArraySize(this, ops: v66);
      v44 = idTypeInfoTools::WriteArray(
              this,
              file,
              scope,
              varType,
              varOps: v66[0].data,
              varName,
              varFlags,
              comment,
              varPtr: v46,
              num: v47,
              a11: v48,
              a12: v49,
              a13: v50,
              a14: v51,
              a15: v52,
              a16: v53,
              a17: v54,
              a18: v55,
              a19: v56,
              a20: v57,
              a21: v58,
              a22: v59,
              a23: v60,
              a24: v61,
              a25: v62,
              a26: v63,
              a27: v64,
              (int)a28,
              a29: v65,
              a30: v43);
      idTypeInfoFile::WriteClosingBrace(this: file);
      idStr::FreeData(this: v66);
      return v44;
    }
    else if ( v66[0].len > 2 && v42 == 42 && v66[0].data[v66[0].len - 2] == 41 )
    {
      v45 = idTypeInfoTools::WriteFunctionPointer(
              this,
              file,
              scope,
              varType,
              varOps,
              varName,
              varFlags,
              comment,
              varPtr: v46,
              a10: v47,
              a11: v48,
              a12: v49,
              a13: v50,
              a14: v51,
              a15: v52,
              a16: v53,
              a17: v54,
              a18: v55,
              a19: v56,
              a20: v57,
              a21: v58,
              a22: v59,
              a23: v60,
              a24: v61,
              a25: v62,
              a26: v63,
              a27: v64,
              a28);
      idStr::FreeData(this: v66);
      return v45;
    }
    else
    {
      idTypeInfoTools::WriteUnknownType(this, file, scope, varType, varOps, varName, varFlags, comment);
      idStr::FreeData(this: v66);
      return -1;
    }
  }
  else
  {
    if ( *a28 == nullptr )
    {
      idTypeInfoFile::WriteNullPointer(this: file);
      idTypeInfoFile::WriteComment(this: file, comment);
      idStr::FreeData(this: v66);
      return 4;
    }
    ClassIndex = idTypeInfoTools::FindClassIndex(this, typeName: varType);
    if ( ClassIndex == -1 )
    {
      EnumIndex = idTypeInfoTools::FindEnumIndex(this, typeName: varType);
      if ( EnumIndex != -1 && a30 != 0 )
      {
        Write = this->enumPointer.list[EnumIndex].Write;
        if ( Write != nullptr )
          goto LABEL_9;
      }
    }
    else if ( a30 != 0 )
    {
      Write = this->classPointer.list[ClassIndex].Write;
      if ( Write != nullptr )
      {
LABEL_9:
        ((void (__fastcall *)(idTypeInfoTools *, idTypeInfoFile *, const char *, const char *, char *, const char *, int, const char *))Write)(
          a1: this,
          a2: file,
          a3: scope,
          a4: varType,
          a5: v66[0].data,
          a6: varName,
          a7: varFlags,
          a8: comment);
        idStr::FreeData(this: v66);
        return 4;
      }
    }
    idTypeInfoTools::WriteUnknownType(this, file, scope, varType, varOps, varName, varFlags, comment);
    idStr::FreeData(this: v66);
    return 4;
  }
}


// ========================================================================
// __unwind$118948
// EA  : 0x82FA1674
// RVA : 0x00FA1674
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_118948()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?WriteObject@idTypeInfoTools@@QBAXAAVidTypeInfoFile@@PBD11PAX@Z
// EA  : 0x82FA16A0
// RVA : 0x00FA16A0
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void __fastcall idTypeInfoTools::WriteObject(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *objectType,
        const char *objectOps,
        const char *objectName,
        void **objectPtr)
{
  void *v6; // [sp+8h] [-68h]
  bool v7; // [sp+Fh] [-61h]
  int v8; // [sp+10h] [-60h]
  int v9; // [sp+14h] [-5Ch]
  int v10; // [sp+18h] [-58h]
  int v11; // [sp+1Ch] [-54h]
  int v12; // [sp+20h] [-50h]
  int v13; // [sp+24h] [-4Ch]
  int v14; // [sp+28h] [-48h]
  int v15; // [sp+2Ch] [-44h]
  int v16; // [sp+30h] [-40h]
  int v17; // [sp+34h] [-3Ch]
  int v18; // [sp+38h] [-38h]
  int v19; // [sp+3Ch] [-34h]
  int v20; // [sp+40h] [-30h]
  int v21; // [sp+44h] [-2Ch]
  int v22; // [sp+48h] [-28h]
  int v23; // [sp+4Ch] [-24h]
  int v24; // [sp+50h] [-20h]
  int v25; // [sp+58h] [-18h]

  this->editDepth = 0;
  this->designDepth = 0;
  this->defDepth = 0;
  idTypeInfoTools::WriteType_r(
    this,
    file,
    scope: &byte_8200D768,
    varType: objectType,
    varOps: objectOps,
    varName: objectName,
    varFlags: 0,
    comment: &byte_8200D768,
    varPtr: v6,
    allowSpecialCase: v7,
    a11: v8,
    a12: v9,
    a13: v10,
    a14: v11,
    a15: v12,
    a16: v13,
    a17: v14,
    a18: v15,
    a19: v16,
    a20: v17,
    a21: v18,
    a22: v19,
    a23: v20,
    a24: v21,
    a25: v22,
    a26: v23,
    a27: v24,
    a28: objectPtr,
    a29: v25,
    a30: 1);
}


// ========================================================================
// ?WriteObjectVariable@idTypeInfoTools@@QBA_NAAVidTypeInfoFile@@PBDPAX1@Z
// EA  : 0x82FA1710
// RVA : 0x00FA1710
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

int __fastcall idTypeInfoTools::WriteObjectVariable(
        idTypeInfoTools *this,
        idTypeInfoFile *file,
        const char *objectType,
        unsigned __int8 *objectPtr,
        const char *path)
{
  char *v9; // r5
  __int64 v10; // r8
  __int64 v11; // r10
  char *data; // r6
  char *v13; // r5
  char *v14; // r4
  void *v16; // [sp+8h] [-128h]
  int (__fastcall *v17)(void *); // [sp+Ch] [-124h]
  int v18; // [sp+10h] [-120h]
  int v19; // [sp+14h] [-11Ch]
  int v20; // [sp+18h] [-118h]
  int v21; // [sp+1Ch] [-114h]
  int v22; // [sp+20h] [-110h]
  int v23; // [sp+24h] [-10Ch]
  int v24; // [sp+28h] [-108h]
  int v25; // [sp+2Ch] [-104h]
  int v26; // [sp+30h] [-100h]
  int v27; // [sp+34h] [-FCh]
  int v28; // [sp+38h] [-F8h]
  int v29; // [sp+3Ch] [-F4h]
  int v30; // [sp+40h] [-F0h]
  int v31; // [sp+44h] [-ECh]
  int v32; // [sp+48h] [-E8h]
  int v33; // [sp+4Ch] [-E4h]
  int v34; // [sp+50h] [-E0h]
  int v35; // [sp+58h] [-D8h]
  idPathTypeInfo v36; // [sp+60h] [-D0h] BYREF

  idPathTypeInfo::idPathTypeInfo(this: &v36);
  idStr::operator=(this: &v36.type, text: v9);
  v36.objectPtr = objectPtr;
  v36.flags = 0;
  if ( (unsigned __int8)idTypeInfoTools::TypeInfoForPath(this, info: &v36, path) != 0 && v36.objectPtr != nullptr )
  {
    v11 = __PAIR64__(v36.defDepth, v36.designDepth);
    HIDWORD(v10) = v36.arrayIndex;
    data = v36.name.data;
    v13 = v36.ops.data;
    v14 = v36.type.data;
    *(_QWORD *)&this->editDepth = *(_QWORD *)&v36.editDepth;
    this->defDepth = HIDWORD(v11);
    if ( v10 < 0 )
      idTypeInfoFile::WriteType(this: file, type: v14, ops: v13, name: data);
    else
      idTypeInfoFile::WriteArrayElementType(this: file, type: v14, ops: v13, name: data, i: v10, a6: v11);
    if ( v36.size >= 0 )
      idTypeInfoTools::WriteType_r(
        this,
        file,
        scope: &byte_8200D768,
        varType: v36.type.data,
        varOps: v36.ops.data,
        varName: v36.name.data,
        varFlags: v36.flags,
        comment: &byte_8200D768,
        varPtr: v16,
        allowSpecialCase: (bool)v17,
        a11: v18,
        a12: v19,
        a13: v20,
        a14: v21,
        a15: v22,
        a16: v23,
        a17: v24,
        a18: v25,
        a19: v26,
        a20: v27,
        a21: v28,
        a22: v29,
        a23: v30,
        a24: v31,
        a25: v32,
        a26: v33,
        a27: v34,
        a28: (void **)v36.objectPtr,
        a29: v35,
        a30: 1);
    else
      idTypeInfoTools::WriteBitField(
        this,
        file,
        scope: &byte_8200D768,
        varType: v36.type.data,
        varOps: v36.ops.data,
        varName: v36.name.data,
        varFlags: v36.flags,
        comment: &byte_8200D768,
        varPtr: v16,
        getVar: v17,
        a11: v18,
        a12: v19,
        a13: v20,
        a14: v21,
        a15: v22,
        a16: v23,
        a17: v24,
        a18: v25,
        a19: v26,
        a20: v27,
        a21: v28,
        a22: v29,
        a23: v30,
        a24: v31,
        a25: v32,
        a26: v33,
        a27: v34,
        a28: (int)v36.objectPtr,
        a29: v35,
        a30: (int (__fastcall *)(int))v36.get);
    idPathTypeInfo::~idPathTypeInfo(this: &v36);
    return 1;
  }
  else
  {
    idPathTypeInfo::~idPathTypeInfo(this: &v36);
    return 0;
  }
}


// ========================================================================
// __unwind$119076
// EA  : 0x82FA183C
// RVA : 0x00FA183C
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotools.cpp
// ========================================================================

void _unwind_119076()
{
  int v0; // r12

  idPathTypeInfo::~idPathTypeInfo(this: (idPathTypeInfo *)(v0 - 304 + 96));
}

