
// ========================================================================
// ?UpdateTime@idPhysics_StaticMulti@@UAAXH@Z
// EA  : 0x825411C0
// RVA : 0x005411C0
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.h
// ========================================================================

void __fastcall idPhysics_StaticMulti::UpdateTime(bfx::BinaryReplayLogOut *this)
{
  ;
}


// ========================================================================
// ?GetInstigator@idAIEvent@@QBAPBVidEntity@@XZ
// EA  : 0x82558090
// RVA : 0x00558090
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.h
// ========================================================================

const idEntity *__fastcall idAIEvent::GetInstigator(idAIEvent *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->instigator.spawnId.value;
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
// ?GetOriginator@idAIEvent@@QBAPBVidEntity@@XZ
// EA  : 0x829FBD70
// RVA : 0x009FBD70
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.h
// ========================================================================

const idEntity *__fastcall idAIEvent::GetOriginator(idAIEvent *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->originator.spawnId.value;
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
// ?GetDeclInfo@idDeclAiEvent@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82A42CD0
// RVA : 0x00A42CD0
// PDB : w:\tech5\tungsten\game\ai\aievents\aievent.h
// ========================================================================

idDeclInfoTemplate<idDeclAiEvent> *__fastcall idDeclAiEvent::GetDeclInfo(idDeclAiEvent *this)
{
  return &idDeclAiEvent::resourceList;
}

