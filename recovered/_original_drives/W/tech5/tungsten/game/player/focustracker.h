
// ========================================================================
// ?GetFocusEntity@idFocusTracker@@QBAPAVidEntity@@XZ
// EA  : 0x82AD25C0
// RVA : 0x00AD25C0
// PDB : w:\tech5\tungsten\game\player\focustracker.h
// ========================================================================

idEntity *__fastcall idFocusTracker::GetFocusEntity(idFocusTracker *this)
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
// ?GetTraceDistance@idFocusTracker@@UBAMXZ
// EA  : 0x82B73E20
// RVA : 0x00B73E20
// PDB : w:\tech5\tungsten\game\player\focustracker.h
// ========================================================================

float __fastcall idFocusTracker::GetTraceDistance(idFocusTracker *this)
{
  double distance; // fp1

  distance = this->focusTrace.distance;
  return *((float *)&distance + 1);
}


// ========================================================================
// ?GetFocusUsable@idFocusTracker@@QBAPAVidEntity@@XZ
// EA  : 0x82CA2AF0
// RVA : 0x00CA2AF0
// PDB : w:\tech5\tungsten\game\player\focustracker.h
// ========================================================================

idEntity *__fastcall idFocusTracker::GetFocusUsable(idFocusTracker *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->focusUsable.spawnId.value;
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
// ?SetFocusUsable@idFocusTracker@@QAAXPAVidEntity@@@Z
// EA  : 0x82DFBA28
// RVA : 0x00DFBA28
// PDB : w:\tech5\tungsten\game\player\focustracker.h
// ========================================================================

void __fastcall idFocusTracker::SetFocusUsable(idFocusTracker *this, idEntity *ent)
{
  if ( ent != nullptr )
    this->focusUsable.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    this->focusUsable.spawnId.value = 0x1FFF;
  this->useButtonOverride = 4;
}


// ========================================================================
// ?GetFocusDistance@idFocusTracker@@MBAMPBVidPresentablePlayer@@PBVidEntity@@@Z
// EA  : 0x82DFBA90
// RVA : 0x00DFBA90
// PDB : w:\tech5\tungsten\game\player\focustracker.h
// ========================================================================

float __fastcall idFocusTracker::GetFocusDistance(
        idFocusTracker *this,
        const idPresentablePlayer *owner,
        const idEntity *ent)
{
  double v3; // fp1

  v3 = 2048.0;
  return *((float *)&v3 + 1);
}

