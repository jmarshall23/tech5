
// ========================================================================
// ??0idAdvanceInfo@idNpNavigator@@QAA@XZ
// EA  : 0x82A69818
// RVA : 0x00A69818
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.h
// ========================================================================

idNpNavigator::idAdvanceInfo *__fastcall idNpNavigator::idAdvanceInfo::idAdvanceInfo(
        idNpNavigator::idAdvanceInfo *this)
{
  float z; // r6

  this->advancePosType = POS_SURFACE;
  this->advancePos.x = vec3_origin.x;
  this->advancePos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->advanceDistance = 0.0;
  this->advancePos.z = z;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->advanceArea);
  idNpLink::idNpLink(this: &this->advanceLink);
  idNpMover::idLinkUseParms::idLinkUseParms(this: &this->linkInfo);
  this->linkBackWards = false;
  return this;
}


// ========================================================================
// __unwind$494176
// EA  : 0x82A6988C
// RVA : 0x00A6988C
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.h
// ========================================================================

void _unwind_494176()
{
  int v0; // r12

  idNpAreaHandle::~idNpAreaHandle(this: (idNpAreaHandle *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// __unwind$494177
// EA  : 0x82A698B8
// RVA : 0x00A698B8
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.h
// ========================================================================

void _unwind_494177()
{
  int v0; // r12

  idNpLink::~idNpLink(this: (idNpLink *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// ??0idProbeResults@idNpMover@@QAA@XZ
// EA  : 0x82A7FB70
// RVA : 0x00A7FB70
// PDB : w:\tech5\tungsten\game\navpower\navpowermover.h
// ========================================================================

idNpMover::idProbeResults *__fastcall idNpMover::idProbeResults::idProbeResults(idNpMover::idProbeResults *this)
{
  float z; // r6

  this->endPos.x = vec3_origin.x;
  this->endPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->distTotal = 0.0;
  this->distFraction = 0.0;
  this->endPos.z = z;
  this->distTravelled = 0.0;
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->endArea);
  this->collisionEdge = 0;
  this->collided = false;
  return this;
}

