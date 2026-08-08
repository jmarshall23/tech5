
// ========================================================================
// ??1idBotTargetableEntityListFilter@@UAA@XZ
// EA  : 0x82B449E8
// RVA : 0x00B449E8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.h
// ========================================================================

void __fastcall idBotTargetableEntityListFilter::~idBotTargetableEntityListFilter(
        idBotTargetableEntityListFilter *this)
{
  this->__vftable = (idBotTargetableEntityListFilter_vtbl *)&idBotTargetableEntityListFilter::`vftable';
  idBotEntityListFilter::~idBotEntityListFilter(this);
}


// ========================================================================
// ?Clear@volatileData_t@idBotTargetRecord@@QAAXXZ
// EA  : 0x82B449F8
// RVA : 0x00B449F8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.h
// ========================================================================

void __fastcall idBotTargetRecord::volatileData_t::Clear(idBotTargetRecord::volatileData_t *this)
{
  *((_BYTE *)&this->visibleTracker + 12) &= ~0x80u;
  this->visibleTracker.value = 0.0;
  *((_BYTE *)&this->audibleTracker + 12) &= ~0x80u;
  this->targetFlags.flags = 0;
  this->audibleTracker.value = 0.0;
  this->timeLastVisible = 0;
  this->health = 0.0;
  this->timeLastAttackedBy = 0;
  this->distToTarget = 0.0;
  this->dotToTarget = 0.0;
  this->heightOfTarget = 0.0;
  this->lastAttackedLocation = vec3_origin;
  this->lastSeenLocation = vec3_origin;
  this->lastHeardLocation = vec3_origin;
  this->positionLastSawTarget = vec3_origin;
  this->positionLastAttackedByTarget = vec3_origin;
}


// ========================================================================
// ??0volatileData_t@idBotTargetRecord@@QAA@XZ
// EA  : 0x82B44CB8
// RVA : 0x00B44CB8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.h
// ========================================================================

idBotTargetRecord::volatileData_t *__fastcall idBotTargetRecord::volatileData_t::volatileData_t(
        idBotTargetRecord::volatileData_t *this)
{
  char v1; // r9
  char v2; // r7

  this->targetFlags.flags = 0;
  v1 = *((_BYTE *)&this->visibleTracker + 12);
  this->visibleTracker.lastUpdateMS = -1;
  this->visibleTracker.value = 0.0;
  *((_BYTE *)&this->visibleTracker + 12) = v1 & 0x7F;
  this->visibleTracker.decayRate = 0.0;
  v2 = *((_BYTE *)&this->audibleTracker + 12);
  this->audibleTracker.lastUpdateMS = -1;
  this->audibleTracker.value = 0.0;
  *((_BYTE *)&this->audibleTracker + 12) = v2 & 0x7F;
  this->audibleTracker.decayRate = 0.0;
  idBotTargetRecord::volatileData_t::Clear(this);
  return this;
}


// ========================================================================
// ?GetDebugName@idBotClosestVisibleTargetFilter@@UAAPBDXZ
// EA  : 0x82B46CA8
// RVA : 0x00B46CA8
// PDB : w:\tech5\tungsten\game\bot\bot_worldstate.h
// ========================================================================

const char *__fastcall idBotClosestVisibleTargetFilter::GetDebugName(idBotClosestVisibleTargetFilter *this)
{
  return "ClosestVisibleTarget";
}

