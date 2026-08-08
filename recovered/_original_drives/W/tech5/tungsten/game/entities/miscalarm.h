
// ========================================================================
// ?GetHealthComponent@idAlarm@@UAAPAVidBaseHealth@@XZ
// EA  : 0x82C7C020
// RVA : 0x00C7C020
// PDB : w:\tech5\tungsten\game\entities\miscalarm.h
// ========================================================================

idSimpleHealth *__fastcall idAlarm::GetHealthComponent(idAlarm *this)
{
  return &this->alarmHealth;
}

