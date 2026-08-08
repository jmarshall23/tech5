
// ========================================================================
// ?GetNavUpAxis@idAnimBaseFSM@@UBA?BVidVec3@@XZ
// EA  : 0x82536898
// RVA : 0x00536898
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

idAnimBaseFSM *__fastcall idAnimBaseFSM::GetNavUpAxis(idAnimBaseFSM *this, const idVec3 *result)
{
  float y; // r8
  float z; // r7

  y = vec3_up.y;
  z = vec3_up.z;
  this->idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimBaseFSM_vtbl *)LODWORD(vec3_up.x);
  *(float *)&this->listenerList = y;
  *(float *)&this->listeningToList = z;
  return this;
}


// ========================================================================
// ?GetNextPoint@idAnimBaseFSM@@UBAABVidVec3@@XZ
// EA  : 0x825368C0
// RVA : 0x005368C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

navLinkFlags_t *__fastcall idAnimBaseFSM::GetNextPoint(idAnimBaseFSM *this)
{
  return &this->cachedCorners.staticList[30].linkFlags;
}


// ========================================================================
// ?GetLastTravelTime@idAnimBaseFSM@@UBAHXZ
// EA  : 0x825368C8
// RVA : 0x005368C8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

int __fastcall idAnimBaseFSM::GetLastTravelTime(idAnimBaseFSM *this)
{
  return this->obstacleInfo.obstacleEntity.spawnId.value;
}


// ========================================================================
// ?SetTranslationDeltaScale@idAnimBaseFSM@@UAAXABVidVec3@@@Z
// EA  : 0x825368D0
// RVA : 0x005368D0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

void __fastcall idAnimBaseFSM::SetTranslationDeltaScale(idAnimBaseFSM *this, const idVec3 *scale)
{
  *(idVec3 *)&this->animDeltaCorrection.in.translationCorrectionPerFrameMax.z = *scale;
}


// ========================================================================
// ?GetObstacleInfo@idAnimBaseFSM@@UAAAAVidObstacleInfo@@XZ
// EA  : 0x825368F0
// RVA : 0x005368F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

animBlendVarPair_t *__fastcall idAnimBaseFSM::GetObstacleInfo(idAnimBaseFSM *this)
{
  return &this->animBlendVars.bodyLookYaw;
}


// ========================================================================
// ?GetMoveStatus@idAnimBaseFSM@@UBA?AW4aiMoveStatus_t@@XZ
// EA  : 0x825368F8
// RVA : 0x005368F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

aiMoveStatus_t __fastcall idAnimBaseFSM::GetMoveStatus(idAnimBaseFSM *this)
{
  return LODWORD(this->obstacleInfo.wallCorners[1].z);
}


// ========================================================================
// ??1idAnimFSM@@UAA@XZ
// EA  : 0x82536900
// RVA : 0x00536900
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

void __fastcall idAnimFSM::~idAnimFSM(idAnimFSM *this)
{
  this->idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSM_vtbl *)&idAnimFSM::`vftable'{for `idAIFSMLite'};
  this->idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSM::`vftable'{for `idAIMoveInterface'};
  idAnimBaseFSM::~idAnimBaseFSM(this);
}


// ========================================================================
// ??0deltaCorrectionGoalRotationParms_t@idAnimBaseFSM@@QAA@XZ
// EA  : 0x82A79948
// RVA : 0x00A79948
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// ========================================================================

idAnimBaseFSM::deltaCorrectionGoalRotationParms_t *__fastcall idAnimBaseFSM::deltaCorrectionGoalRotationParms_t::deltaCorrectionGoalRotationParms_t(
        idAnimBaseFSM::deltaCorrectionGoalRotationParms_t *this)
{
  int v1; // ctr
  float *p_z; // r7
  float *p_y; // r8
  float *v4; // r9
  float *v5; // r11
  int v6; // ctr

  v1 = 9;
  p_z = &this->sourcePosition.z;
  p_y = &mat2_identity.mat[1].y;
  this->sourcePosition = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v1;
  }
  while ( v1 != 0 );
  v4 = &this->worldSpaceAnimGoalOrigin.z;
  v6 = 9;
  this->worldSpaceAnimGoalOrigin = vec3_origin;
  v5 = &mat2_identity.mat[1].y;
  do
  {
    *++v4 = *++v5;
    --v6;
  }
  while ( v6 != 0 );
  this->debug = false;
  return this;
}

