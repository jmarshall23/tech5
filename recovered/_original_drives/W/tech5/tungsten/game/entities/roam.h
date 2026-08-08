
// ========================================================================
// ??0idRoamSpawn@@QAA@XZ
// EA  : 0x82558AA0
// RVA : 0x00558AA0
// PDB : w:\tech5\tungsten\game\entities\roam.h
// ========================================================================

idRoamSpawn *__fastcall idRoamSpawn::idRoamSpawn(idRoamSpawn *this)
{
  idEntity::idEntity(this);
  this->spawnDecl = nullptr;
  this->__vftable = (idRoamSpawn_vtbl *)&idRoamSpawn::`vftable';
  this->spawnTarget.spawnId.value = 0x1FFF;
  this->spawnedTracking.spawnId.value = 0x1FFF;
  this->roamSpawns.list = nullptr;
  this->roamSpawns.granularity = 0;
  this->roamSpawns.memTag = 5;
  this->roamSpawns.listStatic = 0;
  this->roamSpawns.size = 0;
  this->roamSpawns.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamSpawns);
  this->pickSpawn.seed = 0;
  return this;
}


// ========================================================================
// __unwind$568967
// EA  : 0x82558B28
// RVA : 0x00558B28
// PDB : w:\tech5\tungsten\game\entities\roam.h
// ========================================================================

void _unwind_568967()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}

