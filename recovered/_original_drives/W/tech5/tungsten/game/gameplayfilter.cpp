
// ========================================================================
// ?SetFlag@idGameplayFilterTarget@@QAAXH_N@Z
// EA  : 0x82D5F0B8
// RVA : 0x00D5F0B8
// PDB : w:\tech5\tungsten\game\gameplayfilter.cpp
// ========================================================================

void __fastcall idGameplayFilterTarget::SetFlag(idGameplayFilterTarget *this, char index, bool flagValue)
{
  this->bits = (flagValue ? 1 << index : 0) | this->bits & ~(1 << index);
}

