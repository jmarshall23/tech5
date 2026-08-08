
// ========================================================================
// ??1idCrosshairInfo@@QAA@XZ
// EA  : 0x8261B700
// RVA : 0x0061B700
// PDB : w:\tech5\engine\decls\declflare.cpp
// ========================================================================

void __fastcall idCrosshairInfo::~idCrosshairInfo(idDeclFlare *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subflares);
}


// ========================================================================
// ??0idDeclFlare@@QAA@XZ
// EA  : 0x8261B710
// RVA : 0x0061B710
// PDB : w:\tech5\engine\decls\declflare.cpp
// ========================================================================

idDeclFlare *__fastcall idDeclFlare::idDeclFlare(idDeclFlare *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclFlare_vtbl *)&idDeclFlare::`vftable';
  this->subflares.list = nullptr;
  this->subflares.granularity = 0;
  this->subflares.memTag = 79;
  this->subflares.listStatic = 0;
  this->subflares.size = 0;
  this->subflares.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subflares);
  *((_BYTE *)this + 80) &= ~0x80u;
  this->viewAngleFade = 0.0;
  this->invViewAngleFade = 1.0;
  this->brightness = 1.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->subflares);
  return this;
}


// ========================================================================
// __unwind$219129
// EA  : 0x8261B7A4
// RVA : 0x0061B7A4
// PDB : w:\tech5\engine\decls\declflare.cpp
// ========================================================================

void _unwind_219129()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$219130
// EA  : 0x8261B7CC
// RVA : 0x0061B7CC
// PDB : w:\tech5\engine\decls\declflare.cpp
// ========================================================================

void _unwind_219130()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}

