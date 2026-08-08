
// ========================================================================
// ??0idDeclOnlineVOCallout@@QAA@XZ
// EA  : 0x82BCA870
// RVA : 0x00BCA870
// PDB : w:\tech5\tungsten\game\decls\declonlinevocallout.cpp
// ========================================================================

idDeclOnlineVOCallout *__fastcall idDeclOnlineVOCallout::idDeclOnlineVOCallout(idDeclOnlineVOCallout *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclOnlineVOCallout_vtbl *)&idDeclOnlineVOCallout::`vftable';
  soundShaderParms_t::Clear(this: &this->parms);
  this->takenLead = nullptr;
  this->tiedLead = nullptr;
  this->lostLead = nullptr;
  this->impressive = nullptr;
  this->doubleKill = nullptr;
  this->tripleKill = nullptr;
  this->quadKill = nullptr;
  this->slaughter = nullptr;
  this->revenge = nullptr;
  this->airMail = nullptr;
  this->pull = nullptr;
  this->afterLife = nullptr;
  this->maxChain = nullptr;
  this->chainBreaker = nullptr;
  this->denial = nullptr;
  this->closeCall = nullptr;
  this->airRally = nullptr;
  return this;
}

