
// ========================================================================
// ??0idDeclFaction@@QAA@XZ
// EA  : 0x82BD3D88
// RVA : 0x00BD3D88
// PDB : w:\tech5\tungsten\game\decls\declfaction.h
// ========================================================================

idDeclFaction *__fastcall idDeclFaction::idDeclFaction(idDeclFaction *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclFaction_vtbl *)&idDeclFaction::`vftable';
  this->factionNameId.len = 0;
  this->factionNameId.allocedAndFlag = 20;
  this->factionNameId.data = this->factionNameId.baseBuffer;
  this->factionNameId.baseBuffer[0] = 0;
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&this->relationships);
  this->parentFaction = nullptr;
  return this;
}


// ========================================================================
// __unwind$502025
// EA  : 0x82BD3DE8
// RVA : 0x00BD3DE8
// PDB : w:\tech5\tungsten\game\decls\declfaction.h
// ========================================================================

void _unwind_502025()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$502026
// EA  : 0x82BD3E10
// RVA : 0x00BD3E10
// PDB : w:\tech5\tungsten\game\decls\declfaction.h
// ========================================================================

void _unwind_502026()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// ?GetDeclInfo@idDeclFaction@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD3E40
// RVA : 0x00BD3E40
// PDB : w:\tech5\tungsten\game\decls\declfaction.h
// ========================================================================

idDeclInfoTemplate<idDeclFaction> *__fastcall idDeclFaction::GetDeclInfo(idDeclFaction *this)
{
  return &idDeclFaction::resourceList;
}

