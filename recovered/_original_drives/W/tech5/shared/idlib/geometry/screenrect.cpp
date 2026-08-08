
// ========================================================================
// ?Clear@idScreenRect@@QAAXXZ
// EA  : 0x82F21710
// RVA : 0x00F21710
// PDB : w:\tech5\shared\idlib\geometry\screenrect.cpp
// ========================================================================

void __fastcall idScreenRect::Clear(idScreenRect *this)
{
  this->y1 = 32000;
  this->x1 = 32000;
  this->y2 = -32000;
  this->x2 = -32000;
}


// ========================================================================
// ?Zero@idScreenRect@@QAAXXZ
// EA  : 0x82F21730
// RVA : 0x00F21730
// PDB : w:\tech5\shared\idlib\geometry\screenrect.cpp
// ========================================================================

void __fastcall idScreenRect::Zero(idScreenRect *this)
{
  this->y1 = 0;
  this->x1 = 0;
  this->y2 = 0;
  this->x2 = 0;
}

