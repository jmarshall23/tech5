
// ========================================================================
// ?GetFriendlyBlocker@idAIMemory@@QAAPAVidEntity@@XZ
// EA  : 0x829FBEA8
// RVA : 0x009FBEA8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

idEntity *__fastcall idAIMemory::GetFriendlyBlocker(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->currentFriendlyBlocker.spawnId.value;
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
// ?GetLastAttacker@idAIMemory@@QBAPAVidEntity@@XZ
// EA  : 0x829FBEF0
// RVA : 0x009FBEF0
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

idEntity *__fastcall idAIMemory::GetLastAttacker(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->lastAttacker.spawnId.value;
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
// ?GetLastInflictor@idAIMemory@@QBAPAVidEntity@@XZ
// EA  : 0x829FBF38
// RVA : 0x009FBF38
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

idEntity *__fastcall idAIMemory::GetLastInflictor(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->lastInflictor.spawnId.value;
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
// ?IsIgnoringProjectile@idAIMemory@@QAA_NPBVidEntity@@@Z
// EA  : 0x829FBF80
// RVA : 0x009FBF80
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

BOOL __fastcall idAIMemory::IsIgnoringProjectile(idAIMemory *this, const idEntity *ent)
{
  int value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r3

  value = this->ignoredProjectile.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  return (_cntlzw((char *)ent - (char *)v5) & 0x20) != 0;
}


// ========================================================================
// ?GetAvoidEntity@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x829FC000
// RVA : 0x009FC000
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetAvoidEntity(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->avoidEntity.spawnId.value;
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
// ?GetInteractionEntity@idAIMemory@@QBAPAVidPlayer@@XZ
// EA  : 0x829FC048
// RVA : 0x009FC048
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

idPlayer *__fastcall idAIMemory::GetInteractionEntity(idAIMemory *this)
{
  int value; // r10
  idPlayer *v2; // r3

  value = this->interactionEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idPlayer::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetNeutral@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x829FC1F8
// RVA : 0x009FC1F8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetNeutral(idFocusInfo *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->focusEntity.spawnId.value;
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
// ?GetSpottedEnemyTrigger@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x82A02578
// RVA : 0x00A02578
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetSpottedEnemyTrigger(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->spottedEnemyTrigger.spawnId.value;
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
// ?GetDetectedEnemyTrigger@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x82A025C0
// RVA : 0x00A025C0
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetDetectedEnemyTrigger(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->detectedEnemyTrigger.spawnId.value;
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
// ?GetUsedProp@idAIMemory@@QBAPAVidEntity@@XZ
// EA  : 0x82A36AC0
// RVA : 0x00A36AC0
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

idEntity *__fastcall idAIMemory::GetUsedProp(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->usedProp.spawnId.value;
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
// ?GetFireBlocker@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x82A482A8
// RVA : 0x00A482A8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetFireBlocker(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->fireBlocker.spawnId.value;
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
// ??0idAIProjectileInfo@@QAA@XZ
// EA  : 0x82A531D8
// RVA : 0x00A531D8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

idAIProjectileInfo *__fastcall idAIProjectileInfo::idAIProjectileInfo(idAIProjectileInfo *this)
{
  this->itemDecl = nullptr;
  this->coverAction = COVERACTION_MAX;
  this->actualTargetPos.x = 0.0;
  this->actualTargetPos.y = 0.0;
  this->actualTargetPos.z = 0.0;
  this->actualTargetVel.x = 0.0;
  this->actualTargetVel.y = 0.0;
  this->actualTargetVel.z = 0.0;
  this->predictedTargetPos.x = 0.0;
  this->predictedTargetPos.y = 0.0;
  this->predictedTargetPos.z = 0.0;
  this->nodeIndex.value = -1;
  this->overrideAnim = ANIMOVERRIDE_NONE;
  this->jointIndex.value = -1;
  this->useMuzzleForLaunch = false;
  this->target.spawnId.value = 0x1FFF;
  this->linearParms.time = 0.0;
  this->linearParms.speed = 0.0;
  this->linearParms.gravity = 0.0;
  this->parabolicParms.time = 0.0;
  this->parabolicParms.speed = 0.0;
  this->parabolicParms.gravity = 0.0;
  this->parabolicParms.angle = 0.0;
  this->parabolicParms.maxHeight = 0.0;
  this->parabolicParms.horizSpeed = 0.0;
  this->parabolicParms.vertSpeed = 0.0;
  return this;
}


// ========================================================================
// ?GetActionEntity@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x82A58410
// RVA : 0x00A58410
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetActionEntity(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->actionEntity.spawnId.value;
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
// ?GetNextPath@idAIMemory@@QBAPBVidInfoPath@@XZ
// EA  : 0x82AA6AB8
// RVA : 0x00AA6AB8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idInfoPath *__fastcall idAIMemory::GetNextPath(idAIMemory *this)
{
  int value; // r10
  idInfoPath *v2; // r3

  value = this->nextPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idInfoPath::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetCurrentPath@idAIMemory@@QBAPAVidInfoPath@@XZ
// EA  : 0x82ABD1C8
// RVA : 0x00ABD1C8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

idInfoPath *__fastcall idAIMemory::GetCurrentPath(idAIMemory *this)
{
  int value; // r10
  idInfoPath *v2; // r3

  value = this->currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idInfoPath::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetIgnoreProjectile@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x82AC12A8
// RVA : 0x00AC12A8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetIgnoreProjectile(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->ignoredProjectile.spawnId.value;
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
// ?GetBackStandHint@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x82AC41E8
// RVA : 0x00AC41E8
// PDB : w:\tech5\tungsten\game\ai\aimemory.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetBackStandHint(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->backstandHint.spawnId.value;
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

