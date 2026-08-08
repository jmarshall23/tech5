
// ========================================================================
// ?Think@idRoamSpawn@@UAAXXZ
// EA  : 0x82CAD8E0
// RVA : 0x00CAD8E0
// PDB : w:\tech5\tungsten\game\entities\roam.cpp
// ========================================================================

void __fastcall idRoamSpawn::Think(idRoamSpawn *this)
{
  idInfoRoam *v1; // r29
  idGameLocal *v3; // r11
  idEntity *v4; // r3
  signed int num; // r10
  unsigned int seed; // r9
  unsigned int v7; // r6
  int v8; // r5
  unsigned int v9; // r8
  int value; // r9
  idInfoRoam *v11; // r3
  idEntity *v12; // r31
  idPhysics *Physics; // r3
  const idVec3 *v14; // r3
  idPhysics *v15; // r3
  idEntity_vtbl *v16; // r29
  int v17; // r3
  idEntity *v18; // r3

  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->spawnedTracking.spawnId.value & 0x1FFF] == this->spawnedTracking.spawnId.value >> 13 )
  {
    v4 = gameLocal->entities.ptr[this->spawnedTracking.spawnId.value & 0x1FFF];
    if ( v4 != nullptr )
    {
      if ( idEntity::CastTo(c: v4) != nullptr )
        return;
      v3 = gameLocal;
    }
  }
  num = this->roamSpawns.num;
  if ( num != 0 )
  {
    seed = this->pickSpawn.seed;
    __twllei(num, 0);
    v7 = 1664525 * seed + 1013904223;
    v8 = (v7 >> 10) & 0x7FFF;
    this->pickSpawn.seed = v7;
    v3 = gameLocal;
    v9 = num & ~(__ROL4__(v8, 1) - 1);
    num = v8 % num;
    __twlgei(v9, 0xFFFFFFFF);
  }
  value = this->roamSpawns.list[num].spawnId.value;
  if ( v3->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v11 = (idInfoRoam *)v3->entities.ptr[this->roamSpawns.list[num].spawnId.value & 0x1FFF]) == nullptr
    || (v1 = idInfoRoam::CastTo(c: v11)) == nullptr )
  {
    idLib::Error(fmt: "idRoamSpawn: NULL pointer in roamSpawns list");
  }
  v12 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: this->spawnDecl, a3: -1, a4: -1, a5: -1);
  if ( v12 == nullptr )
    idLib::Error(fmt: "idRoamSpawn: failed to spawn entity");
  Physics = idEntity::GetPhysics(this: v1);
  v14 = Physics->GetOrigin(this: Physics, a2: 0);
  idEntity::SetOrigin(this: v12, org: v14);
  v15 = idEntity::GetPhysics(this: v1);
  v16 = v12->__vftable;
  v17 = (int)v15->GetAxis(this: v15, a2: 0);
  v16->SetAxis(this: v12, a2: (const idMat3 *)v17);
  if ( idEntityPtr<idEntity const>::operator->(this: &this->spawnTarget) != nullptr )
  {
    v18 = idEntityPtr<idEntity const>::operator->(this: &this->spawnTarget);
    idEntity::AddTarget(this: v12, target: v18);
    v12->ActivateTargets(this: v12, a2: v12);
  }
  this->spawnedTracking.spawnId.value = (gameLocal->spawnIds.ptr[v12->entityNumber] << 13) | v12->entityNumber;
}


// ========================================================================
// ?Spawn@idRoamSpawn@@QAAXXZ
// EA  : 0x82CADAE8
// RVA : 0x00CADAE8
// PDB : w:\tech5\tungsten\game\entities\roam.cpp
// ========================================================================

void __fastcall idRoamSpawn::Spawn(idRoamSpawn *this)
{
  int v2; // r28
  int v3; // r30
  int value; // r9
  idEntity *v5; // r3
  idInfoRoam *v6; // r3
  idInfoRoam *v7; // r3
  idEntityPtr<idEntity> v8; // [sp+50h] [-30h] BYREF

  if ( this->spawnDecl == nullptr )
    idLib::Error(fmt: "idRoamSpawn::Spawn: spawnDecl isn't set");
  v2 = 0;
  if ( this->targets.num > 0 )
  {
    v3 = 0;
    do
    {
      value = this->targets.list[v3].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = (idInfoRoam *)idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      v7 = idInfoRoam::CastTo(c: v6);
      if ( v7 != nullptr )
      {
        v8.spawnId.value = (gameLocal->spawnIds.ptr[v7->entityNumber] << 13) | v7->entityNumber;
        idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&this->roamSpawns, obj: &v8);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->targets.num );
  }
  idEntity::BecomeActive(this, flags: 1);
}

