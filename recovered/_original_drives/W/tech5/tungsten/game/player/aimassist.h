
// ========================================================================
// ??0idAimAssist@@QAA@XZ
// EA  : 0x824FA0B0
// RVA : 0x004FA0B0
// PDB : w:\tech5\tungsten\game\player\aimassist.h
// ========================================================================

idAimAssist *__fastcall idAimAssist::idAimAssist(idAimAssist *this)
{
  unsigned __int64 v1; // r11

  LODWORD(v1) = 0;
  this->__vftable = (idAimAssist_vtbl *)&idAimAssist::`vftable';
  this->player.spawnId = 0;
  this->angleCorrection = ang_zero;
  this->frictionScalar = 1.0;
  this->lastZoomSnap = false;
  this->desiredFrictionScalar = 0.0;
  this->allowZoomSnap = true;
  this->weaponTraceDistance = 0.0;
  this->zoomSnapThisFrame = false;
  this->zoomSnapAimPoint = vec3_origin;
  this->thisFrameEntity.spawnId = 0;
  this->lastFrameEntity.spawnId = 0;
  this->thisFrameHitLoc = vec3_origin;
  this->lastFrameHitLoc.x = vec3_origin.x;
  this->lastFrameHitLoc.y = vec3_origin.y;
  *(float *)&v1 = vec3_origin.z;
  this->lastFrameHitLoc.z = vec3_origin.z;
  this->savedYaw = 0;
  this->savedPitch = 0;
  this->currentYaw = 0;
  this->currentPitch = 0;
  this->deferredAimPoint.index = v1;
  this->deferredHeadPoint.index = v1;
  this->deferredAimPoint.index = v1;
  this->deferredHeadPoint.index = v1;
  this->savedAngle[2] = 0;
  this->savedAngle[1] = 0;
  this->savedAngle[0] = 0;
  this->currentAngle[2] = 0;
  this->currentAngle[1] = 0;
  this->currentAngle[0] = 0;
  return this;
}

