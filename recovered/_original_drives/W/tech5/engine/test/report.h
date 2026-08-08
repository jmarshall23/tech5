
// ========================================================================
// ??1idReport@@UAA@XZ
// EA  : 0x829ECB88
// RVA : 0x009ECB88
// PDB : w:\tech5\engine\test\report.h
// ========================================================================

void __fastcall idReport::~idReport(idReport *this)
{
  this->__vftable = (idReport_vtbl *)&idReport::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->childResults);
  idStr::FreeData(this: &this->pathSuffix);
  idStr::FreeData(this: &this->reportPath);
}


// ========================================================================
// __unwind$222581
// EA  : 0x829ECBE4
// RVA : 0x009ECBE4
// PDB : w:\tech5\engine\test\report.h
// ========================================================================

void _unwind_222581()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$222582
// EA  : 0x829ECC10
// RVA : 0x009ECC10
// PDB : w:\tech5\engine\test\report.h
// ========================================================================

void _unwind_222582()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// ?AddType@idTestReport@@QAAXVidStr@@@Z
// EA  : 0x82D6C3E0
// RVA : 0x00D6C3E0
// PDB : w:\tech5\engine\test\report.h
// ========================================================================

void __fastcall idTestReport::AddType(idTestReport *this, idStr *type)
{
  idList<idStr,5>::Append(this: &this->types, obj: type);
  idStr::FreeData(this: type);
}


// ========================================================================
// __unwind$487633_0
// EA  : 0x82D6C428
// RVA : 0x00D6C428
// PDB : w:\tech5\engine\test\report.h
// ========================================================================

void _unwind_487633_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 140));
}


// ========================================================================
// ?AddInfo@idTestReport@@QAAXVidStr@@@Z
// EA  : 0x82D6C458
// RVA : 0x00D6C458
// PDB : w:\tech5\engine\test\report.h
// ========================================================================

void __fastcall idTestReport::AddInfo(idTestReport *this, idStr *info)
{
  idList<idStr,5>::Append(this: &this->infos, obj: info);
  idStr::FreeData(this: info);
}


// ========================================================================
// __unwind$487653
// EA  : 0x82D6C4A0
// RVA : 0x00D6C4A0
// PDB : w:\tech5\engine\test\report.h
// ========================================================================

void _unwind_487653()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 140));
}

