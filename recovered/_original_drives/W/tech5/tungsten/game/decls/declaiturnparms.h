
// ========================================================================
// ??0idDeclAITurnParms@@QAA@XZ
// EA  : 0x82BD23F8
// RVA : 0x00BD23F8
// PDB : w:\tech5\tungsten\game\decls\declaiturnparms.h
// ========================================================================

idDeclAITurnParms *__fastcall idDeclAITurnParms::idDeclAITurnParms(idDeclAITurnParms *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclAITurnParms_vtbl *)&idDeclAITurnParms::`vftable';
  idStr::idStr(this: &this->baseTurnName, text: "turn");
  this->allowTurns = true;
  this->turnDelay = 1000;
  this->allowCrouchedTurns = true;
  this->extraAngleScale = 0.0;
  this->allowSittingTurns = false;
  this->maxAngle = -1.0;
  this->predictTurns = true;
  this->turnToFocus = true;
  return this;
}


// ========================================================================
// __unwind$499481
// EA  : 0x82BD2490
// RVA : 0x00BD2490
// PDB : w:\tech5\tungsten\game\decls\declaiturnparms.h
// ========================================================================

void _unwind_499481()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetDeclInfo@idDeclAITurnParms@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD24B8
// RVA : 0x00BD24B8
// PDB : w:\tech5\tungsten\game\decls\declaiturnparms.h
// ========================================================================

idDeclInfoTemplate<idDeclAITurnParms> *__fastcall idDeclAITurnParms::GetDeclInfo(idDeclAITurnParms *this)
{
  return &idDeclAITurnParms::resourceList;
}

