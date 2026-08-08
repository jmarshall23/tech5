
// ========================================================================
// ?GetSpring@idAISenseState_Sight@@UAAPAV?$idSpring@VidVec3@@@@XZ
// EA  : 0x8253CBE8
// RVA : 0x0053CBE8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.h
// ========================================================================

const idSpring<idVec3> *__fastcall idAISenseState_Sight::GetSpring(idAISenseState_Sight *this)
{
  return &this->confirmedOriginSpring;
}

