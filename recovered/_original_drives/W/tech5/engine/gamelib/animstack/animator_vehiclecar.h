
// ========================================================================
// ??0tireMark_t@idAnimWheel@@QAA@XZ
// EA  : 0x82561470
// RVA : 0x00561470
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.h
// ========================================================================

idAnimWheel::tireMark_t *__fastcall idAnimWheel::tireMark_t::tireMark_t(idAnimWheel::tireMark_t *this)
{
  this->markMode = SKIDMARK_NONE;
  this->lastMarkMode = SKIDMARK_NONE;
  this->lastOrigin = vec3_origin;
  this->corners[0] = vec3_origin;
  this->corners[1] = vec3_origin;
  this->corners[2] = vec3_origin;
  this->corners[3] = vec3_origin;
  this->left = vec3_origin;
  this->material = nullptr;
  this->yBias = 0.0;
  return this;
}


// ========================================================================
// ??0idAnimWheel@@QAA@XZ
// EA  : 0x825924A0
// RVA : 0x005924A0
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.h
// ========================================================================

idAnimWheel *__fastcall idAnimWheel::idAnimWheel(idAnimWheel *this)
{
  unsigned __int64 v1; // r30

  LODWORD(v1) = 0;
  this->suspensionLever.list = nullptr;
  this->suspensionLever.granularity = 0;
  this->suspensionLever.memTag = 5;
  this->suspensionLever.listStatic = 0;
  this->suspensionLever.size = 0;
  this->suspensionLever.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->wheelJointIndex.value = -1;
  this->clipModel = nullptr;
  this->localJointQuat = quat_identity;
  this->localJointOrigin.x = 0.0;
  this->localJointOrigin.y = 0.0;
  this->localJointOrigin.z = 0.0;
  this->localJointOrigin.w = 0.0;
  idAnimWheel::tireMark_t::tireMark_t(this: &this->skid);
  idAnimWheel::tireMark_t::tireMark_t(this: &this->track);
  this->hitgroundSpeed = 0.0;
  this->ongroundTime = 0;
  this->wobbleFrac = 0.0;
  this->dustTime = 0;
  this->collisionQuery.index = v1;
  this->traceSurfaceType = 0;
  this->traceFraction = 1.0;
  this->prevTraceFraction = 1.0;
  this->lastWorldOrigin.x = 0.0;
  this->lastWorldOrigin.y = 0.0;
  this->lastWorldOrigin.z = 0.0;
  this->wheelAngle = 0.0;
  this->wheelVelocity = 0.0;
  this->wheelHeight = 0.0;
  this->wheelSlip = 0.0;
  this->wheelSlipInfo.enabled = false;
  this->wheelSlipInfo.velocity = 0.0;
  this->wheelSlipInfo.slip = 0.0;
  this->lastDustPrtDropPos.z = 0.0;
  this->lastDustPrtDropPos.y = 0.0;
  this->lastDustPrtDropPos.x = 0.0;
  this->lastDustPrtDropPos2.z = 0.0;
  this->lastDustPrtDropPos2.y = 0.0;
  this->lastDustPrtDropPos2.x = 0.0;
  this->wheelSteeringAxis.mat[0] = 1.0;
  this->wheelSteeringAxis.mat[1] = 0.0;
  this->wheelSteeringAxis.mat[2] = 0.0;
  this->wheelSteeringAxis.mat[3] = 0.0;
  this->wheelSteeringAxis.mat[4] = 0.0;
  this->wheelSteeringAxis.mat[5] = 1.0;
  this->wheelSteeringAxis.mat[6] = 0.0;
  this->wheelSteeringAxis.mat[7] = 0.0;
  this->wheelSteeringAxis.mat[8] = 0.0;
  this->wheelSteeringAxis.mat[9] = 0.0;
  this->wheelSteeringAxis.mat[10] = 1.0;
  this->wheelSteeringAxis.mat[11] = 0.0;
  this->traceSurfaceColor[2] = -1;
  this->traceSurfaceColor[1] = -1;
  this->traceSurfaceColor[0] = -1;
  return this;
}

