
// ========================================================================
// ?AddPoint@idBounds2D@@QAA_NABVidVec2@@@Z
// EA  : 0x82EF83E0
// RVA : 0x00EF83E0
// PDB : w:\tech5\shared\idlib\bv\bounds2d.cpp
// ========================================================================

int __fastcall idBounds2D::AddPoint(idBounds2D *this, const idVec2 *p)
{
  int result; // r3
  double x; // fp13

  x = this->bounds[0].x;
  result = 0;
  if ( p->x < x )
  {
    this->bounds[0].x = p->x;
    result = 1;
  }
  if ( p->x > (double)this->bounds[1].x )
  {
    this->bounds[1].x = p->x;
    result = 1;
  }
  if ( p->y < (double)this->bounds[0].y )
  {
    this->bounds[0].y = p->y;
    result = 1;
  }
  if ( p->y > (double)this->bounds[1].y )
  {
    this->bounds[1].y = p->y;
    return 1;
  }
  return result;
}


// ========================================================================
// ?ContainsPoint@idBounds2D@@QBA_NABVidVec2@@@Z
// EA  : 0x82EF8450
// RVA : 0x00EF8450
// PDB : w:\tech5\shared\idlib\bv\bounds2d.cpp
// ========================================================================

int __fastcall idBounds2D::ContainsPoint(idBounds2D *this, const idVec2 *point)
{
  const idVec2 *v2; // r11
  int v3; // r9
  int v4; // r8
  double x; // fp0

  v2 = point;
  v3 = 0;
  v4 = (char *)this - (char *)point;
  while ( 1 )
  {
    x = v2->x;
    if ( x < *(float *)((char *)&v2->x + v4) || x > *(float *)((char *)&v2[1].x + v4) )
      break;
    ++v3;
    v2 = (const idVec2 *)((char *)v2 + 4);
    if ( v3 >= 2 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?IntersectBounds@idBounds2D@@QBA_NABV1@@Z
// EA  : 0x82EF84A0
// RVA : 0x00EF84A0
// PDB : w:\tech5\shared\idlib\bv\bounds2d.cpp
// ========================================================================

int __fastcall idBounds2D::IntersectBounds(idBounds2D *this, const idBounds2D *other)
{
  idBounds2D *v2; // r10
  int result; // r3
  bool v4; // zf
  int v5; // r9
  idVec2 *v6; // r11
  int v7; // r8

  v2 = this;
  v4 = other != this;
  result = 1;
  if ( v4 )
  {
    v5 = 0;
    v6 = &other->bounds[1];
    v7 = (char *)v2 - (char *)other;
    do
    {
      if ( v5 >= 2 )
        break;
      if ( v6[-1].x > (double)*(float *)((char *)&v6->x + v7) || v6->x < (double)v2->bounds[0].x )
        result = 0;
      ++v5;
      v6 = (idVec2 *)((char *)v6 + 4);
      v2 = (idBounds2D *)((char *)v2 + 4);
    }
    while ( (_BYTE)result != 0 );
  }
  return result;
}

