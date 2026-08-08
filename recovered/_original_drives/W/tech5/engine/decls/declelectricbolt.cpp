
// ========================================================================
// ??0idDeclElectricBolt@@QAA@XZ
// EA  : 0x826185B8
// RVA : 0x006185B8
// PDB : w:\tech5\engine\decls\declelectricbolt.cpp
// ========================================================================

idDeclElectricBolt *__fastcall idDeclElectricBolt::idDeclElectricBolt(idDeclElectricBolt *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclElectricBolt_vtbl *)&idDeclElectricBolt::`vftable';
  this->maxDeviation = 50.0;
  this->startWidth = 10.0;
  this->endWidth = 10.0;
  this->material = nullptr;
  this->applyGradient = false;
  this->revealTime = 0;
  this->color.x = 1.0;
  this->color.y = 1.0;
  this->color.z = 1.0;
  this->color.w = 1.0;
  this->subdivisions = 1;
  this->brightness = 1.0;
  this->maxBranchLevels = 0;
  this->branchProbability = 0.2;
  this->branchStartWidth = 5.0;
  this->branchEndWidth = 5.0;
  this->branchLength.y = 20.0;
  this->branchLength.x = 10.0;
  this->branchSubdivisions = 2;
  this->jitterTable = nullptr;
  this->jitterFalloffTable = nullptr;
  this->maxBranchAngle = 10.0;
  this->maxBranchDeviation = 15.0;
  this->jitterDecay = 0.0;
  this->jitterSpeed = 0.0099999998;
  this->jitterLeftMag.x = 0.0;
  this->jitterLeftMag.y = 0.0;
  this->jitterUpMag.x = 0.0;
  this->jitterUpMag.y = 0.0;
  this->useBranchOverride = false;
  this->branchOverride.material = nullptr;
  this->branchOverride.frames = 1;
  this->branchOverride.width = 10;
  return this;
}

