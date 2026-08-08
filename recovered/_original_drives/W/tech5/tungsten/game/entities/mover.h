
// ========================================================================
// ??0splineMoverModifierOscillation_t@splineMoverModifier_t@@QAA@XZ
// EA  : 0x82C7D710
// RVA : 0x00C7D710
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

splineMoverModifier_t::splineMoverModifierOscillation_t *__fastcall splineMoverModifier_t::splineMoverModifierOscillation_t::splineMoverModifierOscillation_t(
        splineMoverModifier_t::splineMoverModifierOscillation_t *this)
{
  float z; // r5

  this->setNewOscillation = false;
  this->zAxisPointsToLocalOrigin = false;
  this->range = vec3_origin;
  this->phaseShift = vec3_origin;
  this->period = vec3_origin;
  this->rangeRand = vec3_origin;
  this->periodRand = vec3_origin;
  this->phaseShiftRnd.x = vec3_origin.x;
  this->phaseShiftRnd.y = vec3_origin.y;
  z = vec3_origin.z;
  this->phaseShiftRndUni = 0.0;
  this->phaseShiftRnd.z = z;
  return this;
}


// ========================================================================
// ??0splineMoverModifierSound_t@splineMoverModifier_t@@QAA@XZ
// EA  : 0x82C8DF48
// RVA : 0x00C8DF48
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

splineMoverModifier_t::splineMoverModifierSound_t *__fastcall splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_t(
        splineMoverModifier_t::splineMoverModifierSound_t *this)
{
  this->newSounds.list = nullptr;
  this->newSounds.granularity = 0;
  this->newSounds.memTag = 5;
  this->newSounds.listStatic = 0;
  this->newSounds.size = 0;
  this->newSounds.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->stopSounds.list = nullptr;
  this->stopSounds.granularity = 0;
  this->stopSounds.memTag = 5;
  this->stopSounds.listStatic = 0;
  this->stopSounds.size = 0;
  this->stopSounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stopSounds);
  this->pitch.list = nullptr;
  this->pitch.granularity = 0;
  this->pitch.memTag = 5;
  this->pitch.listStatic = 0;
  this->pitch.size = 0;
  this->pitch.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pitch);
  this->volume.list = nullptr;
  this->volume.granularity = 0;
  this->volume.memTag = 5;
  this->volume.listStatic = 0;
  this->volume.size = 0;
  this->volume.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->volume);
  return this;
}


// ========================================================================
// __unwind$516991
// EA  : 0x82C8DFF0
// RVA : 0x00C8DFF0
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

void _unwind_516991()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$516992
// EA  : 0x82C8E018
// RVA : 0x00C8E018
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

void _unwind_516992()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$516993
// EA  : 0x82C8E044
// RVA : 0x00C8E044
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

void _unwind_516993()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 32));
}


// ========================================================================
// ??0splineMoverModifierSpawnEntity@splineMoverModifier_t@@QAA@XZ
// EA  : 0x82C8E070
// RVA : 0x00C8E070
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

splineMoverModifier_t::splineMoverModifierSpawnEntity *__fastcall splineMoverModifier_t::splineMoverModifierSpawnEntity::splineMoverModifierSpawnEntity(
        splineMoverModifier_t::splineMoverModifierSpawnEntity *this)
{
  this->spawnDef = nullptr;
  this->splines.list = nullptr;
  this->splines.granularity = 0;
  this->splines.memTag = 5;
  this->splines.listStatic = 0;
  this->splines.size = 0;
  this->splines.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splines);
  this->aiGoalEntity.spawnId.value = 0x1FFF;
  this->centerEntityOnSpline = false;
  this->reverseSwarm = false;
  return this;
}


// ========================================================================
// ?GetAnchorStart@idSplinePath@@QBAPAVidEntity@@XZ
// EA  : 0x82D5C008
// RVA : 0x00D5C008
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

idEntity *__fastcall idSplinePath::GetAnchorStart(idSplinePath *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->anchorStart.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetAnchorEnd@idSplinePath@@QBAPAVidEntity@@XZ
// EA  : 0x82D5C050
// RVA : 0x00D5C050
// PDB : w:\tech5\tungsten\game\entities\mover.h
// ========================================================================

idEntity *__fastcall idSplinePath::GetAnchorEnd(idSplinePath *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->anchorEnd.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}

