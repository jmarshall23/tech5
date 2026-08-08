
// ========================================================================
// ??0idAimTracker@@QAA@XZ
// EA  : 0x82A9C278
// RVA : 0x00A9C278
// PDB : w:\tech5\tungsten\game\ai\rotationtracker.h
// ========================================================================

idAimTracker *__fastcall idAimTracker::idAimTracker(idAimTracker *this)
{
  idRotationTracker::idRotationTracker(this);
  this->__vftable = (idAimTracker_vtbl *)&idAimTracker::`vftable';
  this->curParms.kickScale = 0.0;
  this->curParms.rate.value = 0.0;
  this->curParms.acceleration.value = 1440.0;
  this->curParms.deceleration.value = 1440.0;
  this->curParms.springMass = 1.0;
  this->curParms.springTightness = 75.0;
  this->curParms.springDampen = 7.5;
  this->curParms.springMaxSpeed = 1000.0;
  this->curParms.springRestLength = 0.0;
  this->curParms.springMaxLength = 96.0;
  return this;
}

