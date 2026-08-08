
// ========================================================================
// ?InternalFilter@idTurretTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B02278
// RVA : 0x00B02278
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\turrettargetfilter.cpp
// ========================================================================

int __fastcall idTurretTargetFilter::InternalFilter(
        idTurretTargetFilter *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  idProjectile *Entity; // r31
  idActor *v6; // r3
  idVehicle *v7; // r31

  if ( ti->es == nullptr )
    return 0;
  Entity = (idProjectile *)idAIEntityState::GetEntity(this: (idAIEntityState *)ti->es);
  if ( idProjectile::CastTo(c: Entity) != nullptr )
    return 0;
  v6 = idActor::CastTo(c: (idActor *)Entity);
  v7 = (idVehicle *)v6;
  if ( v6 != nullptr && v6->IsDead(this: v6) && idVehicle::CastTo(c: v7) != nullptr )
    return 0;
  else
    return ((ti->attitude >= 0) + ((unsigned int)ti->attitude >= 2)) & 1;
}


// ========================================================================
// ??0idTurretTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA  : 0x82B02330
// RVA : 0x00B02330
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\turrettargetfilter.cpp
// ========================================================================

idTurretTargetFilter *__fastcall idTurretTargetFilter::idTurretTargetFilter(
        idTurretTargetFilter *this,
        aiAwareness_t minAwareness_)
{
  this->minAwareness = minAwareness_;
  this->__vftable = (idTurretTargetFilter_vtbl *)&idTurretTargetFilter::`vftable';
  return this;
}

