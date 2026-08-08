
// ========================================================================
// ??0transitionQueryResult_t@idAnimWebTransitions@@QAA@XZ
// EA  : 0x82A63280
// RVA : 0x00A63280
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.h
// ========================================================================

idAnimWebTransitions::transitionQueryResult_t *__fastcall idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(
        idAnimWebTransitions::transitionQueryResult_t *this)
{
  float z; // r5

  idAnimWebState::idAnimWebState(this: &this->dst);
  idAnimWebState::idAnimWebState(this: &this->via);
  this->startOrigin = vec3_origin;
  this->destOrigin.x = vec3_origin.x;
  this->destOrigin.y = vec3_origin.y;
  z = vec3_origin.z;
  this->approximatePathDistance = 0.0;
  this->selectionIndex = -1;
  this->anim = nullptr;
  this->destOrigin.z = z;
  return this;
}


// ========================================================================
// ??0transitionQueryValidation_t@idAnimWebTransitions@@QAA@XZ
// EA  : 0x82A63310
// RVA : 0x00A63310
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.h
// ========================================================================

idAnimWebTransitions::transitionQueryValidation_t *__fastcall idAnimWebTransitions::transitionQueryValidation_t::transitionQueryValidation_t(
        idAnimWebTransitions::transitionQueryValidation_t *this)
{
  this->selectType = CHOOSE_ANGLE_DISTANCE_ERROR;
  this->requiredSourceAlignAngleDot = 0.86602539;
  this->usePathDirectionForMoveAlign = false;
  this->requiredMoveAlignAngleDot = 0.70710677;
  this->usePathDirectionForSourceAlign = false;
  this->allowedFlags = -24577;
  this->requiredFlags = 0;
  this->movementDistanceFudge = 0.0;
  this->suggestedFlags = 0;
  this->maxMoveDistanceMultiplier = 1.0;
  this->checkMaxMovementDistance = true;
  this->usePathDirectionForApexAlign = false;
  this->requiredApexAlignAngleDot = 0.70710677;
  this->checkAnimTooShort = true;
  *(_WORD *)&this->navProbeAnimTranslation = 1;
  *(_WORD *)&this->navProbeToPathPosition = 1;
  return this;
}


// ========================================================================
// ??0transitionCache_t@idAnimWebTransitions@@QAA@XZ
// EA  : 0x82A6F5F8
// RVA : 0x00A6F5F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.h
// ========================================================================

idAnimWebTransitions::transitionCache_t *__fastcall idAnimWebTransitions::transitionCache_t::transitionCache_t(
        idAnimWebTransitions::transitionCache_t *this)
{
  idAnimWebState::idAnimWebState(this: &this->srcState);
  idAnimWebState::idAnimWebState(this: &this->dstState);
  this->lastCheckFlags = 0;
  this->transitions.list = nullptr;
  this->transitions.granularity = 0;
  this->transitions.memTag = 5;
  this->transitions.listStatic = 0;
  this->transitions.size = 0;
  this->transitions.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->transitions);
  this->maximumDeltaOriginDistanceSqr = 0.0;
  this->maximumPathDistance = 0.0;
  this->minimumDeltaOriginDistanceSqr = 0.0;
  this->nodeIndex.value = -1;
  return this;
}


// ========================================================================
// ??0transitionQueryParms_t@idAnimWebTransitions@@QAA@XZ
// EA  : 0x82A6FD18
// RVA : 0x00A6FD18
// PDB : w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.h
// ========================================================================

idAnimWebTransitions::transitionQueryParms_t *__fastcall idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t(
        idAnimWebTransitions::transitionQueryParms_t *this)
{
  int v1; // ctr
  float *p_z; // r7
  float *p_y; // r8
  float *v4; // r9
  float *v5; // r10
  int i; // ctr
  float z; // r6

  v1 = 9;
  p_z = &this->sourceOrigin2.z;
  p_y = &mat2_identity.mat[1].y;
  this->sourceOrigin1 = vec3_origin;
  this->sourceOrigin2 = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v1;
  }
  while ( v1 != 0 );
  v4 = &this->destinationOrigin.z;
  v5 = &mat2_identity.mat[1].y;
  this->destinationOrigin = vec3_origin;
  for ( i = 9; i != 0; --i )
    *++v4 = *++v5;
  this->turnPoint.x = vec3_origin.x;
  this->turnPoint.y = vec3_origin.y;
  z = vec3_origin.z;
  this->totalPathDistance = 0.0;
  this->pathDistanceAlongAxis = 0.0;
  this->turnPoint.z = z;
  this->debugDrawTime = 1;
  this->cachedCorners.size = 31;
  this->cachedCorners.num = 0;
  this->cachedCorners.granularity = 1;
  this->cachedCorners.list = this->cachedCorners.staticList;
  this->cachedCorners.memTag = 5;
  this->cachedCorners.listStatic = 1;
  return this;
}

