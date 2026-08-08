
// ========================================================================
// ?GetType@idPresentableLaserGate@@UBA?AW4presentableType_t@@XZ
// EA  : 0x82B70428
// RVA : 0x00B70428
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.h
// ========================================================================

int __fastcall idPresentableLaserGate::GetType(idPresentableLaserGate *this)
{
  return 24;
}


// ========================================================================
// ??0idDeclLaserGate@@QAA@XZ
// EA  : 0x82BCCA18
// RVA : 0x00BCCA18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.h
// ========================================================================

idDeclLaserGate *__fastcall idDeclLaserGate::idDeclLaserGate(idDeclLaserGate *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->laserBeamMtr = nullptr;
  this->timeBetweenPoweringUpBeams = 1000;
  this->laserBeamHeight = 8.0;
  this->__vftable = (idDeclLaserGate_vtbl *)&idDeclLaserGate::`vftable';
  this->beamPowerUpTime = 1000;
  this->activationSound = nullptr;
  this->deactivationSound = nullptr;
  this->gatePassThroughSound = nullptr;
  this->fxDecl = nullptr;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclLaserGate@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BCCA88
// RVA : 0x00BCCA88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablelasergate.h
// ========================================================================

idDeclInfoTemplate<idDeclLaserGate> *__fastcall idDeclLaserGate::GetDeclInfo(idDeclLaserGate *this)
{
  return &idDeclLaserGate::resourceList;
}

