
// ========================================================================
// ?GetHandsEntity@idFirstPersonEvent@@IAAPAVidAlignedEntity@@XZ
// EA  : 0x82C4C440
// RVA : 0x00C4C440
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.h
// ========================================================================

idAlignedEntity *__fastcall idFirstPersonEvent::GetHandsEntity(idFirstPersonEvent *this)
{
  int value; // r10
  idAlignedEntity *v2; // r3

  value = this->handsEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idAlignedEntity *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idAlignedEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetLegsEntity@idFirstPersonEvent@@IAAPAVidAlignedEntity@@XZ
// EA  : 0x82C4C488
// RVA : 0x00C4C488
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.h
// ========================================================================

idAlignedEntity *__fastcall idFirstPersonEvent::GetLegsEntity(idFirstPersonEvent *this)
{
  int value; // r10
  idAlignedEntity *v2; // r3

  value = this->legsEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idAlignedEntity *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idAlignedEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetPlayerActivator@idFirstPersonEvent@@IAAPAVidPlayer@@XZ
// EA  : 0x82C4C4D0
// RVA : 0x00C4C4D0
// PDB : w:\tech5\tungsten\game\entities\firstpersonevent.h
// ========================================================================

idPlayer *__fastcall idFirstPersonEvent::GetPlayerActivator(idFirstPersonEvent *this)
{
  int value; // r10
  idPlayer *v2; // r3

  value = this->playerActivator.spawnId.value;
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

