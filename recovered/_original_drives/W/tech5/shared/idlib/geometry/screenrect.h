
// ========================================================================
// ?Intersect@idScreenRect@@QAAXABV1@@Z
// EA  : 0x828D95D8
// RVA : 0x008D95D8
// PDB : w:\tech5\shared\idlib\geometry\screenrect.h
// ========================================================================

void __fastcall idScreenRect::Intersect(idScreenRect *this, const idScreenRect *rect)
{
  int x1; // r11
  int x2; // r10
  int v4; // r11
  int y1; // r11
  int y2; // r11
  int v7; // r10

  x1 = rect->x1;
  if ( this->x1 > rect->x1 )
    x1 = this->x1;
  x2 = this->x2;
  this->x1 = x1;
  v4 = rect->x2;
  if ( x2 < v4 )
    v4 = x2;
  this->x2 = v4;
  y1 = this->y1;
  if ( y1 <= rect->y1 )
    y1 = rect->y1;
  this->y1 = y1;
  y2 = this->y2;
  v7 = rect->y2;
  if ( y2 >= v7 )
    this->y2 = v7;
  else
    this->y2 = y2;
}


// ========================================================================
// ?Expand@idScreenRect@@QAAXXZ
// EA  : 0x828DFCD8
// RVA : 0x008DFCD8
// PDB : w:\tech5\shared\idlib\geometry\screenrect.h
// ========================================================================

void __fastcall idScreenRect::Expand(idScreenRect *this)
{
  int x1; // r10
  int v2; // r11
  int y1; // r10
  int v4; // r9
  int v5; // r9
  int x2; // r10
  int v7; // r9
  int y2; // r11
  int v9; // r10

  x1 = this->x1;
  if ( this->x1 >= 1 )
    x1 = 1;
  v2 = this->x1 - x1;
  y1 = this->y1;
  this->x1 = v2;
  v4 = y1;
  if ( y1 >= 1 )
    v4 = 1;
  v5 = y1 - v4;
  x2 = this->x2;
  this->y1 = v5;
  v7 = 65534 - x2;
  if ( 65534 - x2 >= 1 )
    v7 = 1;
  y2 = this->y2;
  this->x2 = x2 + v7;
  v9 = 65534 - y2;
  if ( 65534 - y2 >= 1 )
    v9 = 1;
  this->y2 = y2 + v9;
}

