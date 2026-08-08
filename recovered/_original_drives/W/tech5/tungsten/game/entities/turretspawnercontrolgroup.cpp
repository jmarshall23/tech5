
// ========================================================================
// ?Think@idTurretSpawnerControlGroup@@UAAXXZ
// EA  : 0x82D03018
// RVA : 0x00D03018
// PDB : w:\tech5\tungsten\game\entities\turretspawnercontrolgroup.cpp
// ========================================================================

// attributes: thunk
void __fastcall idTurretSpawnerControlGroup::Think(idTurretSpawnerControlGroup *this)
{
  idEntity::Think(this);
}


// ========================================================================
// ??0idTurretSpawnerControlGroup@@QAA@XZ
// EA  : 0x82D03020
// RVA : 0x00D03020
// PDB : w:\tech5\tungsten\game\entities\turretspawnercontrolgroup.cpp
// ========================================================================

idTurretSpawnerControlGroup *__fastcall idTurretSpawnerControlGroup::idTurretSpawnerControlGroup(
        idTurretSpawnerControlGroup *this)
{
  idAIHintGroup::idAIHintGroup(this);
  this->__vftable = (idTurretSpawnerControlGroup_vtbl *)&idTurretSpawnerControlGroup::`vftable';
  this->gunnerStartingHitPoints = 0.0;
  this->maxLivingMinions = 0;
  this->bonusDamageWhenTaunting = 0.0;
  this->startTurretSound = nullptr;
  this->damageScaleFromTank = 3.0;
  this->endTurretSound = nullptr;
  this->visibleSightTime = 0.0;
  this->minTriggerDownDuration = 0.0;
  this->maxTriggerDownDuration = 0.0;
  this->minFireInterval = 0.0;
  this->maxFireInterval = 0.0;
  this->minPostTauntWaitToFire = 0.0;
  this->maxPostTauntWaitToFire = 0.0;
  this->deathTrigger.spawnId.value = 0x1FFF;
  this->spawnerOn = 0;
  return this;
}


// ========================================================================
// ?SpawnNow@idTurretSpawnerControlGroup@@QAA_NH@Z
// EA  : 0x82D03118
// RVA : 0x00D03118
// PDB : w:\tech5\tungsten\game\entities\turretspawnercontrolgroup.cpp
// ========================================================================

int __fastcall idTurretSpawnerControlGroup::SpawnNow(idTurretSpawnerControlGroup *this, int hint)
{
  int spawnerOn; // r11
  int v4; // r11
  bool v5; // zf
  int value; // r9
  idEntity *v7; // r3
  idTarget_Spawn *v8; // r3
  idTarget_Spawn *v9; // r3

  if ( hint < 0 )
  {
    spawnerOn = this->spawnerOn;
    v5 = spawnerOn < this->targets.num - 1;
    v4 = spawnerOn + 1;
    if ( !v5 )
      v4 = 0;
    this->spawnerOn = v4;
    hint = v4;
  }
  if ( hint < this->targets.num
    && (value = this->targets.list[hint].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v7 = gameLocal->entities.ptr[this->targets.list[hint].spawnId.value & 0x1FFF]) != nullptr )
  {
    v8 = (idTarget_Spawn *)idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  if ( v8 != nullptr )
  {
    v9 = idTarget_Spawn::CastTo(c: v8);
    idEntity::Activate(this: v9, activator: this);
  }
  return 1;
}

