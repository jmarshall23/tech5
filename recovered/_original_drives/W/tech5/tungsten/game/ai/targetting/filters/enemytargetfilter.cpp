
// ========================================================================
// ??0idEnemyTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA  : 0x82B01E00
// RVA : 0x00B01E00
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\enemytargetfilter.cpp
// ========================================================================

idEnemyTargetFilter *__fastcall idEnemyTargetFilter::idEnemyTargetFilter(
        idEnemyTargetFilter *this,
        aiAwareness_t minAwareness_)
{
  this->minAwareness = minAwareness_;
  this->__vftable = (idEnemyTargetFilter_vtbl *)&idEnemyTargetFilter::`vftable';
  return this;
}


// ========================================================================
// ?InternalFilter@idEnemyTargetFilter@@UBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B01E18
// RVA : 0x00B01E18
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\enemytargetfilter.cpp
// ========================================================================

int __fastcall idEnemyTargetFilter::InternalFilter(
        idEnemyTargetFilter *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  idAIEntityState *es; // r3
  int entityType; // r11

  es = (idAIEntityState *)ti->es;
  if ( ti->es == nullptr )
    return 0;
  entityType = es->entityType;
  if ( entityType == 3 )
    return 0;
  if ( es->entityType == 0 || entityType == 1 )
  {
    if ( idAIEntityState::IsDead(this: es) && !idAIEntityState::IsDying(this: (idAIEntityState *)ti->es) )
      return 0;
  }
  else if ( idAIEntityState::IsDead(this: es) || idAIEntityState::IsDying(this: (idAIEntityState *)ti->es) )
  {
    return 0;
  }
  return ((ti->attitude >= 0) + ((unsigned int)ti->attitude >= 2)) & 1;
}


// ========================================================================
// ??0idAvoidTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA  : 0x82B01EE8
// RVA : 0x00B01EE8
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\enemytargetfilter.cpp
// ========================================================================

idAvoidTargetFilter *__fastcall idAvoidTargetFilter::idAvoidTargetFilter(
        idAvoidTargetFilter *this,
        aiAwareness_t minAwareness_)
{
  this->minAwareness = minAwareness_;
  this->__vftable = (idAvoidTargetFilter_vtbl *)&idAvoidTargetFilter::`vftable';
  return this;
}


// ========================================================================
// ?InternalFilter@idAvoidTargetFilter@@UBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B01F00
// RVA : 0x00B01F00
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\enemytargetfilter.cpp
// ========================================================================

int __fastcall idAvoidTargetFilter::InternalFilter(
        idAvoidTargetFilter *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  idAIEntityState *es; // r3
  idAI2 *v6; // r3
  idAI2 *v7; // r31
  int GameMs; // r29

  es = (idAIEntityState *)ti->es;
  if ( ti->es == nullptr )
    return 0;
  if ( es->entityType == 0 || es->entityType == 1 )
  {
    if ( idAIEntityState::IsDead(this: es) )
    {
      if ( !idAIEntityState::IsDying(this: (idAIEntityState *)ti->es) )
        return 0;
      v6 = (idAI2 *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: ti->es->spawnId.value);
      v7 = idAI2::CastTo(c: v6);
      if ( v7 != nullptr )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        if ( GameMs - idAI2::GetAlertCycleFSM(this: v7)->lastTransitionTime > 2000 )
          return 0;
      }
    }
  }
  else if ( idAIEntityState::IsDead(this: es) )
  {
    return 0;
  }
  return ((ti->attitude >= 0) + ((unsigned int)ti->attitude >= 2)) & 1;
}

