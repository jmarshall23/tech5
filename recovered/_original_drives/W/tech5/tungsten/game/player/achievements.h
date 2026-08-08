
// ========================================================================
// ?IsFulfilled@idAchievement@@QBA_NXZ
// EA  : 0x82DEFD10
// RVA : 0x00DEFD10
// PDB : w:\tech5\tungsten\game\player\achievements.h
// ========================================================================

int __fastcall idAchievement::IsFulfilled(idAchievement *this)
{
  unsigned __int8 v1; // r11

  if ( !this->itemsFulfilled )
    return 0;
  if ( !this->jobsFulfilled )
    return 0;
  if ( !this->triggersFulfilled )
    return 0;
  if ( !this->achievementsFulfilled )
    return 0;
  if ( !this->eventsFulfilled )
    return 0;
  v1 = 1;
  if ( !this->racesFulfilled )
    return 0;
  return v1;
}

