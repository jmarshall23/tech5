
// ========================================================================
// ?GetInventory@idVehicleMountedTurret@@UAAPAVidInventoryCollection@@XZ
// EA  : 0x82D31480
// RVA : 0x00D31480
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.h
// ========================================================================

const idInventoryCollection *__fastcall idVehicleMountedTurret::GetInventory(idVehicleMountedTurret *this)
{
  return &this->inventory;
}


// ========================================================================
// ?GetAttachments@idVehicleMountedTurret@@UAAPAVidAttachmentCollection@@XZ
// EA  : 0x82D31488
// RVA : 0x00D31488
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.h
// ========================================================================

const idAttachmentCollection *__fastcall idVehicleMountedTurret::GetAttachments(idVehicleMountedTurret *this)
{
  return &this->attachments;
}


// ========================================================================
// ?IsDead@idVehicleMountedTurret@@UBA_NXZ
// EA  : 0x82D31490
// RVA : 0x00D31490
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.h
// ========================================================================

BOOL __fastcall idVehicleMountedTurret::IsDead(idVehicleMountedTurret *this)
{
  int value; // r10
  idTurretGunner *v3; // r3
  int v5; // r9
  idTurretGunner *v6; // r3
  idTurretGunner *v7; // r3

  value = this->gunner.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return false;
  v3 = (idTurretGunner *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr || idTurretGunner::CastTo(c: v3) == nullptr )
    return false;
  v5 = this->gunner.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13
    && (v6 = (idTurretGunner *)gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
  {
    v7 = idTurretGunner::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  return v7->IsDead(this: v7);
}

