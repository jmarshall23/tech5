
// ========================================================================
// ??0idCoverQuery@@QAA@PAVidAI2@@ABVidAICover@@H@Z
// EA  : 0x82A023B0
// RVA : 0x00A023B0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.h
// ========================================================================

idCoverQuery *__fastcall idCoverQuery::idCoverQuery(idCoverQuery *this, idAI2 *ai, const idAICover *exclude, int flags)
{
  this->ai = ai;
  this->__vftable = (idCoverQuery_vtbl *)&idCoverQuery::`vftable';
  idCoverQuery::coverTarget_t::coverTarget_t(this: &this->target);
  idAICover::idAICover(this: &this->excludeCover, other: exclude);
  this->queryFlags = flags;
  this->debugLevel = 0;
  this->minTravelTimeIndex = -1;
  this->maxTravelTimeIndex = -1;
  this->minTravelTime = 0.0;
  this->maxTravelTime = 0.0;
  this->travelTimeRange = 0.0;
  this->aiaiPos.valid = false;
  this->aiaiPos.areaNum = 0;
  this->aiaiPos.origin.x = 0.0;
  this->aiaiPos.origin.y = 0.0;
  this->aiaiPos.origin.z = 0.0;
  this->aiaiPos.validOrigin.x = 0.0;
  this->aiaiPos.validOrigin.y = 0.0;
  this->aiaiPos.validOrigin.z = 0.0;
  this->aiaiPos.aas = nullptr;
  this->aivcPos.valid = false;
  this->aivcPos.areaNum = 0;
  this->aivcPos.origin.x = 0.0;
  this->aivcPos.origin.y = 0.0;
  this->aivcPos.origin.z = 0.0;
  this->aivcPos.validOrigin.x = 0.0;
  this->aivcPos.validOrigin.y = 0.0;
  this->aivcPos.validOrigin.z = 0.0;
  this->aivcPos.aas = nullptr;
  this->relevantCover.list = nullptr;
  this->relevantCover.granularity = 0;
  this->relevantCover.memTag = 5;
  this->relevantCover.listStatic = 0;
  this->relevantCover.size = 0;
  this->relevantCover.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relevantCover);
  return this;
}


// ========================================================================
// __unwind$538037_0
// EA  : 0x82A024C0
// RVA : 0x00A024C0
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.h
// ========================================================================

void _unwind_538037_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// ??1idCoverQuery@@UAA@XZ
// EA  : 0x82A024F8
// RVA : 0x00A024F8
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.h
// ========================================================================

void __fastcall idCoverQuery::~idCoverQuery(idCoverQuery *this)
{
  this->__vftable = (idCoverQuery_vtbl *)&idCoverQuery::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->relevantCover);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->excludeCover);
}


// ========================================================================
// __unwind$538094
// EA  : 0x82A0254C
// RVA : 0x00A0254C
// PDB : w:\tech5\tungsten\game\ai\cover\coverquery.h
// ========================================================================

void _unwind_538094()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}

