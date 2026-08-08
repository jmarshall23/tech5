
// ========================================================================
// ?GetInflictor@idAIDamageInfo@@QBAPAVidEntity@@XZ
// EA  : 0x829FBE18
// RVA : 0x009FBE18
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.h
// ========================================================================

idEntity *__fastcall idAIDamageInfo::GetInflictor(idAIDamageInfo *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->inflictor.spawnId.value;
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
// ?GetAttacker@idAIDamageInfo@@QBAPAVidEntity@@XZ
// EA  : 0x829FBE60
// RVA : 0x009FBE60
// PDB : w:\tech5\tungsten\game\ai\aidamageinfo.h
// ========================================================================

idEntity *__fastcall idAIDamageInfo::GetAttacker(idAIDamageInfo *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->attacker.spawnId.value;
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

