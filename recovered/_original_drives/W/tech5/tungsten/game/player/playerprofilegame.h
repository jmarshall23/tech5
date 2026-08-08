
// ========================================================================
// ?GetSubtitleLanguageMask@idPlayerProfileGame@@UBAIXZ
// EA  : 0x82E4FF90
// RVA : 0x00E4FF90
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.h
// ========================================================================

unsigned int __fastcall idPlayerProfileGame::GetSubtitleLanguageMask(idPlayerProfileGame *this)
{
  return this->subtitleMask;
}


// ========================================================================
// ?SetChosenEmblem@idPlayerProfileGame@@UAAXH@Z
// EA  : 0x82E4FF98
// RVA : 0x00E4FF98
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.h
// ========================================================================

void __fastcall idPlayerProfileGame::SetChosenEmblem(idPlayerProfileGame *this, int emblemOrdinal)
{
  this->chosenEmblem = emblemOrdinal;
}


// ========================================================================
// ?GetChosenEmblem@idPlayerProfileGame@@UBAHXZ
// EA  : 0x82E4FFA0
// RVA : 0x00E4FFA0
// PDB : w:\tech5\tungsten\game\player\playerprofilegame.h
// ========================================================================

int __fastcall idPlayerProfileGame::GetChosenEmblem(idPlayerProfileGame *this)
{
  return this->chosenEmblem;
}

