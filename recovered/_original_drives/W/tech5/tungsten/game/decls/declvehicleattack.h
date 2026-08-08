
// ========================================================================
// ??0idDeclVehicleAttack@@QAA@XZ
// EA  : 0x82BCC878
// RVA : 0x00BCC878
// PDB : w:\tech5\tungsten\game\decls\declvehicleattack.h
// ========================================================================

idDeclVehicleAttack *__fastcall idDeclVehicleAttack::idDeclVehicleAttack(idDeclVehicleAttack *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclVehicleAttack_vtbl *)&idDeclVehicleAttack::`vftable';
  this->state = ATTACK_NONE;
  this->params.attempts = -1;
  this->params.range = -1.0;
  this->params.time = -1.0;
  this->params.minSpeed = -1.0;
  this->params.maxSpeed = -1.0;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleAttack@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCC8E0
// RVA : 0x00BCC8E0
// PDB : w:\tech5\tungsten\game\decls\declvehicleattack.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleAttack> *__fastcall idDeclVehicleAttack::GetDeclInfo(idDeclVehicleAttack *this)
{
  return &idDeclVehicleAttack::resourceList;
}

