
// ========================================================================
// ?GetType@mgTimelineKeyUtil@@SA?AW4tlKeyType_t@@W4tlKeyId_t@@@Z
// EA  : 0x8276B738
// RVA : 0x0076B738
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

tlKeyType_t __fastcall mgTimelineKeyUtil::GetType(tlKeyId_t key)
{
  return keyTypeMap[key];
}


// ========================================================================
// ?KeySize@mgTimelineKeyUtil@@SAHW4tlKeyType_t@@@Z
// EA  : 0x8276B750
// RVA : 0x0076B750
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

int __fastcall mgTimelineKeyUtil::KeySize(tlKeyType_t type)
{
  return keySizes[type];
}


// ========================================================================
// ?FromString@mgTimelineKeyUtil@@SA_NABVidStr@@PA_N@Z
// EA  : 0x8276B768
// RVA : 0x0076B768
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

int __fastcall mgTimelineKeyUtil::FromString(const idStr *valueStr, bool *val)
{
  *val = atol(nptr: valueStr->data) != 0;
  return 1;
}


// ========================================================================
// ?FromString@mgTimelineKeyUtil@@SA_NABVidStr@@PAH@Z
// EA  : 0x8276B7B0
// RVA : 0x0076B7B0
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

int __fastcall mgTimelineKeyUtil::FromString(const idStr *valueStr, int *val)
{
  *val = atol(nptr: valueStr->data);
  return 1;
}


// ========================================================================
// ?FromString@mgTimelineKeyUtil@@SA_NABVidStr@@PAM@Z
// EA  : 0x8276B7F0
// RVA : 0x0076B7F0
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

BOOL __fastcall mgTimelineKeyUtil::FromString(const idStr *valueStr, float *val)
{
  double v4; // fp1
  unsigned int v5; // r10
  BOOL v6; // r30
  bool v8; // [sp+50h] [-C0h] BYREF
  idLexer v9; // [sp+60h] [-B0h] BYREF

  idLexer::idLexer(this: &v9, flags_: 0);
  idLexer::LoadMemory(this: &v9, ptr: valueStr->data, length_: valueStr->len, name: nullptr);
  v4 = idLexer::ParseFloat(this: &v9, errorFlag: &v8);
  v5 = v8;
  *val = v4;
  v6 = (_cntlzw(v5) & 0x20) != 0;
  idLexer::~idLexer(this: &v9);
  return v6;
}


// ========================================================================
// __unwind$245654
// EA  : 0x8276B858
// RVA : 0x0076B858
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

void _unwind_245654()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 272 + 96));
}


// ========================================================================
// ?FromString@mgTimelineKeyUtil@@SA_NABVidStr@@PAVidVec3@@@Z
// EA  : 0x8276B888
// RVA : 0x0076B888
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

int __fastcall mgTimelineKeyUtil::FromString(const idStr *valueStr, idVec3 *val)
{
  double v4; // fp1
  BOOL v5; // r10
  unsigned __int8 v6; // r11
  int v7; // r30
  bool v9; // [sp+50h] [-C0h] BYREF
  bool v10; // [sp+51h] [-BFh] BYREF
  bool v11; // [sp+52h] [-BEh] BYREF
  idLexer v12; // [sp+60h] [-B0h] BYREF

  idLexer::idLexer(this: &v12, flags_: 0);
  idLexer::LoadMemory(this: &v12, ptr: valueStr->data, length_: valueStr->len, name: nullptr);
  val->x = idLexer::ParseFloat(this: &v12, errorFlag: &v11);
  val->y = idLexer::ParseFloat(this: &v12, errorFlag: &v9);
  v4 = idLexer::ParseFloat(this: &v12, errorFlag: &v10);
  v5 = v11;
  val->z = v4;
  if ( v5 || v9 || (v6 = 1, v10) )
    v6 = 0;
  v7 = v6;
  idLexer::~idLexer(this: &v12);
  return v7;
}


// ========================================================================
// __unwind$245692
// EA  : 0x8276B934
// RVA : 0x0076B934
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

void _unwind_245692()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 272 + 96));
}


// ========================================================================
// ?FromString@mgTimelineKeyUtil@@SA_NABVidStr@@PAVidVec4@@@Z
// EA  : 0x8276B968
// RVA : 0x0076B968
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

int __fastcall mgTimelineKeyUtil::FromString(const idStr *valueStr, idVec4 *val)
{
  double v4; // fp1
  BOOL v5; // r10
  unsigned __int8 v6; // r11
  int v7; // r30
  bool v9; // [sp+50h] [-C0h] BYREF
  bool v10; // [sp+51h] [-BFh] BYREF
  bool v11; // [sp+52h] [-BEh] BYREF
  bool v12; // [sp+53h] [-BDh] BYREF
  idLexer v13; // [sp+60h] [-B0h] BYREF

  idLexer::idLexer(this: &v13, flags_: 0);
  idLexer::LoadMemory(this: &v13, ptr: valueStr->data, length_: valueStr->len, name: nullptr);
  val->x = idLexer::ParseFloat(this: &v13, errorFlag: &v10);
  val->y = idLexer::ParseFloat(this: &v13, errorFlag: &v12);
  val->z = idLexer::ParseFloat(this: &v13, errorFlag: &v9);
  v4 = idLexer::ParseFloat(this: &v13, errorFlag: &v11);
  v5 = v10;
  val->w = v4;
  if ( v5 || v12 || v9 || (v6 = 1, v11) )
    v6 = 0;
  v7 = v6;
  idLexer::~idLexer(this: &v13);
  return v7;
}


// ========================================================================
// __unwind$245726
// EA  : 0x8276BA30
// RVA : 0x0076BA30
// PDB : w:\tech5\engine\gamelib\timeline\timelinekeytypes.cpp
// ========================================================================

void _unwind_245726()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 272 + 96));
}

