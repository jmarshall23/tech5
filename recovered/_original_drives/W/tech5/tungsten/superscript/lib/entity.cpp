
// ========================================================================
// ??0ssEntity@@QAA@ABVssString@@@Z
// EA  : 0x82EE6E50
// RVA : 0x00EE6E50
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::ssEntity(ssEntity *this, const ssString *name)
{
  int v4; // r3
  const ssString *v5; // r3
  const ssString *v6; // r3
  ssString v8; // [sp+50h] [-40h] BYREF
  ssString v9[3]; // [sp+60h] [-30h] BYREF

  v4 = gameInterface->FindEntity(this: gameInterface, a2: name->data);
  this->spawnId = v4;
  if ( v4 == 0 )
  {
    v5 = operator+(result: v9, a: "entity '", b: name);
    v6 = operator+(result: &v8, a: v5, b: "' not found");
    Warning(msg: v6);
    ssString::Empty(this: &v8);
    ssString::Empty(this: v9);
  }
  return this;
}


// ========================================================================
// __unwind$18086
// EA  : 0x82EE6ED8
// RVA : 0x00EE6ED8
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

void _unwind_18086()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$18087
// EA  : 0x82EE6F00
// RVA : 0x00EE6F00
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

void _unwind_18087()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 144 + 80));
}


// ========================================================================
// ??0ssEntity@@QAA@PBD@Z
// EA  : 0x82EE6F30
// RVA : 0x00EE6F30
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

ssEntity *__fastcall ssEntity::ssEntity(ssEntity *this, const char *name)
{
  int v4; // r3
  const ssString *v5; // r3
  const ssString *v6; // r3
  ssString v8; // [sp+50h] [-50h] BYREF
  ssString v9; // [sp+60h] [-40h] BYREF
  ssString v10[3]; // [sp+70h] [-30h] BYREF

  v4 = ((int (__fastcall *)(idGameSuperInterface *))gameInterface->FindEntity)(a1: gameInterface);
  this->spawnId = v4;
  if ( v4 == 0 )
  {
    ssString::Init(this: &v8);
    ssString::operator=(this: &v8, text: name);
    v5 = operator+(result: v10, a: "entity '", b: &v8);
    v6 = operator+(result: &v9, a: v5, b: "' not found");
    Warning(msg: v6);
    ssString::Empty(this: &v9);
    ssString::Empty(this: v10);
    ssString::Empty(this: &v8);
  }
  return this;
}


// ========================================================================
// __unwind$18128
// EA  : 0x82EE6FD0
// RVA : 0x00EE6FD0
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

void _unwind_18128()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$18129
// EA  : 0x82EE6FF8
// RVA : 0x00EE6FF8
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

void _unwind_18129()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$18130
// EA  : 0x82EE7020
// RVA : 0x00EE7020
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

void _unwind_18130()
{
  int v0; // r12

  ssString::~ssString(this: (ssString *)(v0 - 160 + 96));
}


// ========================================================================
// ??0ssEntity@@QAA@ABV0@@Z
// EA  : 0x82EE7048
// RVA : 0x00EE7048
// PDB : w:\tech5\tungsten\superscript\lib\entity.cpp
// ========================================================================

void __fastcall ssEntity::ssEntity(ssEntity *this, const ssEntity *e)
{
  this->spawnId = e->spawnId;
}

