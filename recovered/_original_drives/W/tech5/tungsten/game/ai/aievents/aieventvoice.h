
// ========================================================================
// ?InternalIsTouching@idAIEvent_DelayedVO@@UBA_NPBVidEntity@@H@Z
// EA  : 0x825580D8
// RVA : 0x005580D8
// PDB : w:\tech5\tungsten\game\ai\aievents\aieventvoice.h
// ========================================================================

BOOL __fastcall idAIEvent_DelayedVO::InternalIsTouching(
        idAIEvent_DelayedVO *this,
        const idEntity *ent,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r3

  value = this->instigator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  return (_cntlzw((char *)v6 - (char *)ent) & 0x20) != 0;
}

