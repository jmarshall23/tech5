
// ========================================================================
// ??1idAIMoveState@@UAA@XZ
// EA  : 0x82A0C7D0
// RVA : 0x00A0C7D0
// PDB : w:\tech5\tungsten\game\ai\aimovestate.h
// ========================================================================

void __fastcall idAIMoveState::~idAIMoveState(idAIMoveState *this)
{
  this->__vftable = (idAIMoveState_vtbl *)&idAIMoveState::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->moveFailures);
  idObstacleAvoidance::~idObstacleAvoidance(this: &this->oa);
}


// ========================================================================
// __unwind$551129
// EA  : 0x82A0C824
// RVA : 0x00A0C824
// PDB : w:\tech5\tungsten\game\ai\aimovestate.h
// ========================================================================

void _unwind_551129()
{
  int v0; // r12

  idObstacleAvoidance::~idObstacleAvoidance(this: (idObstacleAvoidance *)(*(_DWORD *)(v0 - 112 + 132) + 852));
}


// ========================================================================
// ?GetFinalPoint@idAIMoveState@@UBAABVidVec3@@XZ
// EA  : 0x82A0C850
// RVA : 0x00A0C850
// PDB : w:\tech5\tungsten\game\ai\aimovestate.h
// ========================================================================

const idVec3 *__fastcall idAIMoveState::GetFinalPoint(idAIMoveState *this)
{
  return &this->finalPoint;
}


// ========================================================================
// ?GetNextPoint@idAIMoveState@@UBAABVidVec3@@XZ
// EA  : 0x82A0C858
// RVA : 0x00A0C858
// PDB : w:\tech5\tungsten\game\ai\aimovestate.h
// ========================================================================

const idVec3 *__fastcall idAIMoveState::GetNextPoint(idAIMoveState *this)
{
  return &this->nextPoint;
}


// ========================================================================
// ?GetLastTravelTime@idAIMoveState@@UBAHXZ
// EA  : 0x82A0C860
// RVA : 0x00A0C860
// PDB : w:\tech5\tungsten\game\ai\aimovestate.h
// ========================================================================

int __fastcall idAIMoveState::GetLastTravelTime(idAIMoveState *this)
{
  return this->lastTravelTime;
}


// ========================================================================
// ?Get_idAIMoveState_isPlayingTraversalAnim@@YAHPAX@Z
// EA  : 0x82A0C868
// RVA : 0x00A0C868
// PDB : w:\tech5\tungsten\game\ai\aimovestate.h
// ========================================================================

BOOL __fastcall Get_idAIMoveState_isPlayingTraversalAnim(_BYTE *ptr)
{
  return (ptr[352] & 0x10) != 0;
}


// ========================================================================
// ?SetTranslationDeltaScale@idAIMoveState@@UAAXABVidVec3@@@Z
// EA  : 0x82A0C878
// RVA : 0x00A0C878
// PDB : w:\tech5\tungsten\game\ai\aimovestate.h
// ========================================================================

void __fastcall idAIMoveState::SetTranslationDeltaScale(idAIMoveState *this, const idVec3 *scale)
{
  this->translationScale = *scale;
}

