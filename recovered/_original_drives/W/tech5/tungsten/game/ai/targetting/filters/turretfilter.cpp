
// ========================================================================
// ?InternalFilter@idTurretFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B021F8
// RVA : 0x00B021F8
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\turretfilter.cpp
// ========================================================================

BOOL __fastcall idTurretFilter::InternalFilter(idTurretFilter *this, const idEntity *owner, const idTargetInfo *ti)
{
  idProjectile *Entity; // r3
  idProp_WeaponStatic *v6; // r3

  Entity = (idProjectile *)idAIEntityState::GetEntity(this: (idAIEntityState *)ti->es);
  if ( idProjectile::CastTo(c: Entity) != nullptr )
    return false;
  v6 = (idProp_WeaponStatic *)idAIEntityState::GetEntity(this: (idAIEntityState *)ti->es);
  return idProp_WeaponStatic::CastTo(c: v6) != nullptr;
}


// ========================================================================
// ??0idTurretFilter@@QAA@XZ
// EA  : 0x82B02260
// RVA : 0x00B02260
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\turretfilter.cpp
// ========================================================================

idTurretFilter *__fastcall idTurretFilter::idTurretFilter(idTurretFilter *this)
{
  this->minAwareness = AIAWARE_CONFIRMED;
  this->__vftable = (idTurretFilter_vtbl *)&idTurretFilter::`vftable';
  return this;
}

