
// ========================================================================
// ?GetHealthComponent@idExplodable@@UAAPAVidBaseHealth@@XZ
// EA  : 0x82C49F50
// RVA : 0x00C49F50
// PDB : w:\tech5\tungsten\game\entities\explodable.h
// ========================================================================

idSimpleHealth *__fastcall idExplodable::GetHealthComponent(idExplodable *this)
{
  return &this->explodableHealth;
}

