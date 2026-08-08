
// ========================================================================
// ?HasFocus@idFocusInfo@@QBA_NXZ
// EA  : 0x829FC170
// RVA : 0x009FC170
// PDB : w:\tech5\tungsten\game\ai\focusinfo.h
// ========================================================================

int __fastcall idFocusInfo::HasFocus(idFocusInfo *this)
{
  int value; // r10
  idEntity *v3; // r3
  unsigned __int8 v4; // r11

  value = this->focusEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idEntity::CastTo(c: v3) != nullptr )
      return 1;
  }
  v4 = 0;
  if ( this->hasExplicitFocusPoint )
    return 1;
  return v4;
}

