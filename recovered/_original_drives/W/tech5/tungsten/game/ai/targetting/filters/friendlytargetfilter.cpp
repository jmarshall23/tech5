
// ========================================================================
// ?InternalFilter@idFriendlyTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B02058
// RVA : 0x00B02058
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\friendlytargetfilter.cpp
// ========================================================================

int __fastcall idFriendlyTargetFilter::InternalFilter(
        idFriendlyTargetFilter *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  idProjectile *Entity; // r31
  idActor *v5; // r3

  if ( ti->es == nullptr )
    return 0;
  Entity = (idProjectile *)idAIEntityState::GetEntity(this: (idAIEntityState *)ti->es);
  if ( idProjectile::CastTo(c: Entity) != nullptr )
    return 0;
  v5 = idActor::CastTo(c: (idActor *)Entity);
  if ( v5 == nullptr || v5->IsDead(this: v5) )
    return 0;
  else
    return ((ti->attitude >= 0) + ((unsigned int)ti->attitude <= 3)) & 1;
}


// ========================================================================
// ??0idFriendlyTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA  : 0x82B02100
// RVA : 0x00B02100
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\friendlytargetfilter.cpp
// ========================================================================

idFriendlyTargetFilter *__fastcall idFriendlyTargetFilter::idFriendlyTargetFilter(
        idFriendlyTargetFilter *this,
        aiAwareness_t minAwareness_)
{
  this->minAwareness = minAwareness_;
  this->__vftable = (idFriendlyTargetFilter_vtbl *)&idFriendlyTargetFilter::`vftable';
  return this;
}


// ========================================================================
// ??0idFriendlyDeadTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA  : 0x82B02118
// RVA : 0x00B02118
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\friendlytargetfilter.cpp
// ========================================================================

idFriendlyDeadTargetFilter *__fastcall idFriendlyDeadTargetFilter::idFriendlyDeadTargetFilter(
        idFriendlyDeadTargetFilter *this,
        aiAwareness_t minAwareness_)
{
  this->minAwareness = minAwareness_;
  this->__vftable = (idFriendlyDeadTargetFilter_vtbl *)&idFriendlyDeadTargetFilter::`vftable';
  return this;
}


// ========================================================================
// ?InternalFilter@idFriendlyDeadTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B02130
// RVA : 0x00B02130
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\friendlytargetfilter.cpp
// ========================================================================

int __fastcall idFriendlyDeadTargetFilter::InternalFilter(
        idFriendlyDeadTargetFilter *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  idAIEntityState *es; // r3
  int entityType; // r11
  int result; // r3
  bool IsDead; // zf

  es = (idAIEntityState *)ti->es;
  if ( ti->es == nullptr )
    return 0;
  entityType = es->entityType;
  if ( entityType == 3 || ti->attitude <= 3 || es->entityType != 0 && entityType != 1 )
    return 0;
  IsDead = idAIEntityState::IsDead(this: es);
  result = 1;
  if ( !IsDead )
    return 0;
  return result;
}

