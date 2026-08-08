
// ========================================================================
// ??0idDeclTrackingParms@@QAA@XZ
// EA  : 0x82BD3048
// RVA : 0x00BD3048
// PDB : w:\tech5\tungsten\game\decls\decltrackingparms.h
// ========================================================================

idDeclTrackingParms *__fastcall idDeclTrackingParms::idDeclTrackingParms(idDeclTrackingParms *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclTrackingParms_vtbl *)&idDeclTrackingParms::`vftable';
  this->parms.list = nullptr;
  this->parms.granularity = 0;
  this->parms.memTag = 5;
  this->parms.listStatic = 0;
  this->parms.size = 0;
  this->parms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parms);
  return this;
}


// ========================================================================
// __unwind$501230
// EA  : 0x82BD30BC
// RVA : 0x00BD30BC
// PDB : w:\tech5\tungsten\game\decls\decltrackingparms.h
// ========================================================================

void _unwind_501230()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclTrackingParms@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD30E8
// RVA : 0x00BD30E8
// PDB : w:\tech5\tungsten\game\decls\decltrackingparms.h
// ========================================================================

idDeclInfoTemplate<idDeclTrackingParms> *__fastcall idDeclTrackingParms::GetDeclInfo(idDeclTrackingParms *this)
{
  return &idDeclTrackingParms::resourceList;
}

