
// ========================================================================
// ??0parametricPState_tMM@@QAA@XZ
// EA  : 0x827509B8
// RVA : 0x007509B8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.h
// ========================================================================

parametricPState_tMM *__fastcall parametricPState_tMM::parametricPState_tMM(parametricPState_tMM *this)
{
  idExtrapolate<float> *oscillationExtrapolation; // r11
  int v3; // r10
  double startValue; // fp9
  double x; // fp6
  double v6; // fp0
  double v7; // fp8

  this->linearExtrapolation.extrapolationType = EXTRAPOLATION_NONE;
  this->linearExtrapolation.duration = 0.0;
  this->linearExtrapolation.startTime = 0.0;
  this->linearExtrapolation.startValue.x = 0.0;
  this->linearExtrapolation.startValue.y = 0.0;
  this->linearExtrapolation.startValue.z = 0.0;
  this->linearExtrapolation.baseSpeed.x = 0.0;
  this->linearExtrapolation.baseSpeed.y = 0.0;
  this->linearExtrapolation.baseSpeed.z = 0.0;
  this->linearExtrapolation.speed.x = 0.0;
  this->linearExtrapolation.speed.y = 0.0;
  this->linearExtrapolation.speed.z = 0.0;
  this->linearExtrapolation.currentTime = -1.0;
  this->linearExtrapolation.currentValue = this->linearExtrapolation.startValue;
  this->angularExtrapolation.extrapolationType = EXTRAPOLATION_NONE;
  this->angularExtrapolation.duration = 0.0;
  this->angularExtrapolation.startTime = 0.0;
  this->angularExtrapolation.startValue = 0.0;
  this->angularExtrapolation.baseSpeed = 0.0;
  this->angularExtrapolation.speed = 0.0;
  this->angularExtrapolation.currentTime = -1.0;
  this->angularExtrapolation.currentValue = this->angularExtrapolation.startValue;
  idInterpolateAccelDecelSine<idVec3>::idInterpolateAccelDecelSine<idVec3>(this: (idInterpolateAccelDecelLinear<idAngles> *)&this->linearInterpolation);
  idInterpolateAccelDecelLinear<idQuat>::idInterpolateAccelDecelLinear<idQuat>(this: &this->angularInterpolation);
  this->splineInterpolate.extrapolate.duration = 0.0;
  this->splineInterpolate.extrapolate.startTime = 0.0;
  this->splineInterpolate.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->splineInterpolate.extrapolate.startValue = 0.0;
  this->splineInterpolate.extrapolate.baseSpeed = 0.0;
  this->splineInterpolate.extrapolate.speed = 0.0;
  this->splineInterpolate.extrapolate.currentTime = -1.0;
  oscillationExtrapolation = this->oscillationExtrapolation;
  v3 = 2;
  this->splineInterpolate.extrapolate.currentValue = this->splineInterpolate.extrapolate.startValue;
  this->splineInterpolate.duration = 0.0;
  this->splineInterpolate.startTime = 0.0;
  this->splineInterpolate.startValue = 0.0;
  startValue = this->splineInterpolate.startValue;
  this->splineInterpolate.endValue = this->splineInterpolate.startValue;
  this->splineInterpolate.startSpeed = startValue;
  this->splineInterpolate.endSpeed = startValue;
  this->splineAngleInterpolate.duration = 0.0;
  this->splineAngleInterpolate.startTime = 0.0;
  this->splineAngleInterpolate.currentTime = 0.0;
  this->splineAngleInterpolate.currentValue.x = 0.0;
  this->splineAngleInterpolate.currentValue.y = 0.0;
  this->splineAngleInterpolate.currentValue.z = 0.0;
  this->splineAngleInterpolate.currentValue.w = 0.0;
  x = this->splineAngleInterpolate.currentValue.x;
  this->splineAngleInterpolate.endValue = this->splineAngleInterpolate.currentValue;
  this->splineAngleInterpolate.startValue.x = x;
  this->splineAngleInterpolate.startValue.y = this->splineAngleInterpolate.endValue.y;
  this->splineAngleInterpolate.startValue.z = this->splineAngleInterpolate.endValue.z;
  this->splineAngleInterpolate.startValue.w = this->splineAngleInterpolate.endValue.w;
  do
  {
    oscillationExtrapolation->duration = 0.0;
    oscillationExtrapolation->extrapolationType = EXTRAPOLATION_NONE;
    oscillationExtrapolation->startTime = 0.0;
    oscillationExtrapolation->startValue = 0.0;
    oscillationExtrapolation->baseSpeed = 0.0;
    oscillationExtrapolation->speed = 0.0;
    oscillationExtrapolation->currentTime = -1.0;
    --v3;
    oscillationExtrapolation->currentValue = oscillationExtrapolation->startValue;
    ++oscillationExtrapolation;
  }
  while ( v3 >= 0 );
  this->localOffsetInterpolation.duration = 0.0;
  this->localOffsetInterpolation.startTime = 0.0;
  this->localOffsetInterpolation.currentTime = 0.0;
  this->localOffsetInterpolation.currentValue.x = 0.0;
  this->localOffsetInterpolation.currentValue.y = 0.0;
  this->localOffsetInterpolation.currentValue.z = 0.0;
  v6 = this->localOffsetInterpolation.currentValue.x;
  this->localOffsetInterpolation.endValue.x = this->localOffsetInterpolation.currentValue.x;
  this->localOffsetInterpolation.endValue.y = this->localOffsetInterpolation.currentValue.y;
  this->localOffsetInterpolation.endValue.z = this->localOffsetInterpolation.currentValue.z;
  this->localOffsetInterpolation.startValue.x = v6;
  this->localOffsetInterpolation.startValue.y = this->localOffsetInterpolation.endValue.y;
  this->localOffsetInterpolation.startValue.z = this->localOffsetInterpolation.endValue.z;
  this->splineMaster = nullptr;
  this->localOriginScaleInterpolation.duration = 0.0;
  this->localOriginScaleInterpolation.startTime = 0.0;
  this->localOriginScaleInterpolation.currentTime = 0.0;
  this->localOriginScaleInterpolation.currentValue.x = 0.0;
  this->localOriginScaleInterpolation.currentValue.y = 0.0;
  this->localOriginScaleInterpolation.currentValue.z = 0.0;
  v7 = this->localOriginScaleInterpolation.currentValue.x;
  this->localOriginScaleInterpolation.endValue.x = this->localOriginScaleInterpolation.currentValue.x;
  this->localOriginScaleInterpolation.endValue.y = this->localOriginScaleInterpolation.currentValue.y;
  this->localOriginScaleInterpolation.endValue.z = this->localOriginScaleInterpolation.currentValue.z;
  this->localOriginScaleInterpolation.startValue.x = v7;
  this->localOriginScaleInterpolation.startValue.y = this->localOriginScaleInterpolation.endValue.y;
  this->localOriginScaleInterpolation.startValue.z = this->localOriginScaleInterpolation.endValue.z;
  this->splineChilds.list = nullptr;
  this->splineChilds.granularity = 0;
  this->splineChilds.memTag = 5;
  this->splineChilds.listStatic = 0;
  this->splineChilds.size = 0;
  this->splineChilds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineChilds);
  this->splineDummy = false;
  return this;
}

