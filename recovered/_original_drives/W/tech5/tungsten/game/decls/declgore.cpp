
// ========================================================================
// ??0idDeclGoreBehavior@@QAA@XZ
// EA  : 0x82BBE7A0
// RVA : 0x00BBE7A0
// PDB : w:\tech5\tungsten\game\decls\declgore.cpp
// ========================================================================

idDeclGoreBehavior *__fastcall idDeclGoreBehavior::idDeclGoreBehavior(idDeclGoreBehavior *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclGoreBehavior_vtbl *)&idDeclGoreBehavior::`vftable';
  this->bodyExplosion.maxPieces = 1;
  this->bodyExplosion.maxWounds = 1;
  this->bodyExplosion.chanceOfLimbloss = 0.5;
  this->bodyExplosion.chanceOfWound = 0.5;
  this->bodyExplosion.chanceOfHeadshot = 0.5;
  this->enableLimbloss = false;
  this->enableHeadShots = false;
  this->enableBodyWound = false;
  this->enableFullBodyExplosion = false;
  this->enableGoreWhenAlive = false;
  return this;
}

