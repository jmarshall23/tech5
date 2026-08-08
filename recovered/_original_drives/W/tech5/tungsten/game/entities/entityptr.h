
// ========================================================================
// ??B?$idEntityPtr@VidTarget_FakeEnemy@@@@QBAPAVidTarget_FakeEnemy@@XZ
// EA  : 0x829FB9B0
// RVA : 0x009FB9B0
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idTarget_FakeEnemy *__fastcall idEntityPtr<idTarget_FakeEnemy>::operator idTarget_FakeEnemy *(
        idEntityPtr<idTarget_FakeEnemy> *this)
{
  idTarget_FakeEnemy *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idTarget_FakeEnemy *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idTarget_FakeEnemy::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??B?$idEntityPtr@VidVolume_Restriction@@@@QBAPAVidVolume_Restriction@@XZ
// EA  : 0x829FBA48
// RVA : 0x009FBA48
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idVolume_Restriction *__fastcall idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(
        idEntityPtr<idVolume_Restriction> *this)
{
  idVolume_Restriction *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idVolume_Restriction *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idVolume_Restriction::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??B?$idEntityPtr@VidScenePoint@@@@QBAPAVidScenePoint@@XZ
// EA  : 0x82A53140
// RVA : 0x00A53140
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idScenePoint *__fastcall idEntityPtr<idScenePoint>::operator idScenePoint *(idEntityPtr<idScenePoint> *this)
{
  idScenePoint *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idScenePoint *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idScenePoint::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidInfoNavObstacle@@@@QBAPAVidInfoNavObstacle@@XZ
// EA  : 0x82A6E528
// RVA : 0x00A6E528
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idInfoNavObstacle *__fastcall idEntityPtr<idInfoNavObstacle>::operator->(idEntityPtr<idInfoNavObstacle> *this)
{
  idInfoNavObstacle *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idInfoNavObstacle *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idInfoNavObstacle::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidAIHintGroup@@@@QBAPAVidAIHintGroup@@XZ
// EA  : 0x82A940F8
// RVA : 0x00A940F8
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idAIHintGroup *__fastcall idEntityPtr<idAIHintGroup>::operator->(idEntityPtr<idAIHintGroup> *this)
{
  idAIHintGroup *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAIHintGroup *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAIHintGroup::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??B?$idEntityPtr@VidActor@@@@QBAPAVidActor@@XZ
// EA  : 0x82ACD638
// RVA : 0x00ACD638
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idActor *__fastcall idEntityPtr<idActor>::operator idActor *(idEntityPtr<idActor> *this)
{
  idActor *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idActor *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idActor::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??B?$idEntityPtr@VidAnimatedEntity@@@@QBAPAVidAnimatedEntity@@XZ
// EA  : 0x82BFA228
// RVA : 0x00BFA228
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idAnimatedEntity *__fastcall idEntityPtr<idAnimatedEntity>::operator idAnimatedEntity *(
        idEntityPtr<idAnimatedEntity> *this)
{
  idAnimatedEntity *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAnimatedEntity *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAnimatedEntity::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidAI2@@@@QBAPAVidAI2@@XZ
// EA  : 0x82C37230
// RVA : 0x00C37230
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idAI2 *__fastcall idEntityPtr<idAI2>::operator->(idEntityPtr<idAI2> *this)
{
  idAI2 *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAI2 *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAI2::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidMoverAttachment@@@@QBAPAVidMoverAttachment@@XZ
// EA  : 0x82C877D8
// RVA : 0x00C877D8
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idMoverAttachment *__fastcall idEntityPtr<idMoverAttachment>::operator->(idEntityPtr<idMoverAttachment> *this)
{
  idMoverAttachment *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idMoverAttachment *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idMoverAttachment::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidInfo@@@@QBAPAVidInfo@@XZ
// EA  : 0x82C952C8
// RVA : 0x00C952C8
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idInfo *__fastcall idEntityPtr<idInfo>::operator->(idEntityPtr<idInfo> *this)
{
  idInfo *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idInfo *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idInfo::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidProp_ExplosivePlunger@@@@QBAPAVidProp_ExplosivePlunger@@XZ
// EA  : 0x82CA2A18
// RVA : 0x00CA2A18
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idProp_ExplosivePlunger *__fastcall idEntityPtr<idProp_ExplosivePlunger>::operator->(
        idEntityPtr<idProp_ExplosivePlunger> *this)
{
  idProp_ExplosivePlunger *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idProp_ExplosivePlunger *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idProp_ExplosivePlunger::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidAnimatedSimple@@@@QBAPAVidAnimatedSimple@@XZ
// EA  : 0x82CA2A60
// RVA : 0x00CA2A60
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idAnimatedSimple *__fastcall idEntityPtr<idAnimatedSimple>::operator->(idEntityPtr<idAnimatedSimple> *this)
{
  idAnimatedSimple *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAnimatedSimple *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAnimatedSimple::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidFirstPersonEvent@@@@QBAPAVidFirstPersonEvent@@XZ
// EA  : 0x82CA2AA8
// RVA : 0x00CA2AA8
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idFirstPersonEvent *__fastcall idEntityPtr<idFirstPersonEvent>::operator->(idEntityPtr<idFirstPersonEvent> *this)
{
  idFirstPersonEvent *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idFirstPersonEvent *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idFirstPersonEvent::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidTownGarageManager@@@@QBAPAVidTownGarageManager@@XZ
// EA  : 0x82CD1780
// RVA : 0x00CD1780
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idTownGarageManager *__fastcall idEntityPtr<idTownGarageManager>::operator->(idEntityPtr<idTownGarageManager> *this)
{
  idTownGarageManager *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idTownGarageManager *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idTownGarageManager::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidProp_JobPosting@@@@QBAPAVidProp_JobPosting@@XZ
// EA  : 0x82CD17C8
// RVA : 0x00CD17C8
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idProp_JobPosting *__fastcall idEntityPtr<idProp_JobPosting>::operator->(idEntityPtr<idProp_JobPosting> *this)
{
  idProp_JobPosting *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idProp_JobPosting *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idProp_JobPosting::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??B?$idEntityPtr@VidAFEntity_Dummy@@@@QBAPAVidAFEntity_Dummy@@XZ
// EA  : 0x82CF6C00
// RVA : 0x00CF6C00
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idAFEntity_Dummy *__fastcall idEntityPtr<idAFEntity_Dummy>::operator idAFEntity_Dummy *(
        idEntityPtr<idAFEntity_Dummy> *this)
{
  idAFEntity_Dummy *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAFEntity_Dummy *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAFEntity_Dummy::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidAICombatHint@@@@QBAPAVidAICombatHint@@XZ
// EA  : 0x82D00598
// RVA : 0x00D00598
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idAICombatHint *__fastcall idEntityPtr<idAICombatHint>::operator->(idEntityPtr<idAICombatHint> *this)
{
  idAICombatHint *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAICombatHint *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAICombatHint::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidAICombatHint_SuppressionFirePoint@@@@QBAPAVidAICombatHint_SuppressionFirePoint@@XZ
// EA  : 0x82D005E0
// RVA : 0x00D005E0
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idAICombatHint_SuppressionFirePoint *__fastcall idEntityPtr<idAICombatHint_SuppressionFirePoint>::operator->(
        idEntityPtr<idAICombatHint_SuppressionFirePoint> *this)
{
  idAICombatHint_SuppressionFirePoint *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idAICombatHint_SuppressionFirePoint *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idAICombatHint_SuppressionFirePoint::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??B?$idEntityPtr@VidScenePoint_UserGroup@@@@QBAPAVidScenePoint_UserGroup@@XZ
// EA  : 0x82D483F0
// RVA : 0x00D483F0
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idScenePoint_UserGroup *__fastcall idEntityPtr<idScenePoint_UserGroup>::operator idScenePoint_UserGroup *(
        idEntityPtr<idScenePoint_UserGroup> *this)
{
  idScenePoint_UserGroup *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idScenePoint_UserGroup *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idScenePoint_UserGroup::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetEntity@?$idEntityPtr@VidProjectile@@@@QBAPAVidProjectile@@XZ
// EA  : 0x82E04340
// RVA : 0x00E04340
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idProjectile *__fastcall idEntityPtr<idProjectile>::GetEntity(idEntityPtr<idProjectile> *this)
{
  idProjectile *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idProjectile *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idProjectile::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidUseLedge@@@@QBAPAVidUseLedge@@XZ
// EA  : 0x82E42F50
// RVA : 0x00E42F50
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idUseLedge *__fastcall idEntityPtr<idUseLedge>::operator->(idEntityPtr<idUseLedge> *this)
{
  idUseLedge *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idUseLedge *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idUseLedge::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??C?$idEntityPtr@VidWallClimb@@@@QBAPAVidWallClimb@@XZ
// EA  : 0x82E4AD78
// RVA : 0x00E4AD78
// PDB : w:\tech5\tungsten\game\entities\entityptr.h
// ========================================================================

idWallClimb *__fastcall idEntityPtr<idWallClimb>::operator->(idEntityPtr<idWallClimb> *this)
{
  idWallClimb *v1; // r3

  if ( gameLocal->spawnIds.ptr[this->spawnId.value & 0x1FFF] == this->spawnId.value >> 13
    && (v1 = (idWallClimb *)gameLocal->entities.ptr[this->spawnId.value & 0x1FFF]) != nullptr )
  {
    return idWallClimb::CastTo(c: v1);
  }
  else
  {
    return nullptr;
  }
}

