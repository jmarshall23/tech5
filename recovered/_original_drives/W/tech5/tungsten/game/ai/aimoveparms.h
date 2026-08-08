
// ========================================================================
// ?GetGoalEntity@idAIMoveParms@@QBAPBVidEntity@@XZ
// EA  : 0x82A58348
// RVA : 0x00A58348
// PDB : w:\tech5\tungsten\game\ai\aimoveparms.h
// ========================================================================

const idEntity *__fastcall idAIMoveParms::GetGoalEntity(idAIMoveParms *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->goalEntity.spawnId.value;
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
// ?MovingToEntity@idAIMoveParms@@QBA_NXZ
// EA  : 0x82A58390
// RVA : 0x00A58390
// PDB : w:\tech5\tungsten\game\ai\aimoveparms.h
// ========================================================================

BOOL __fastcall idAIMoveParms::MovingToEntity(idAIMoveParms *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->goalEntity.spawnId.value;
  return gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idEntity::CastTo(c: v2) != nullptr;
}


// ========================================================================
// ?GetGoalScenePoint@idAIMoveParms@@QBAPBVidScenePoint@@XZ
// EA  : 0x82A596E0
// RVA : 0x00A596E0
// PDB : w:\tech5\tungsten\game\ai\aimoveparms.h
// ========================================================================

const idScenePoint *__fastcall idAIMoveParms::GetGoalScenePoint(idAIMoveParms *this)
{
  int value; // r10
  idScenePoint *v2; // r3

  value = this->goalScenePoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idScenePoint *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idScenePoint::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}

