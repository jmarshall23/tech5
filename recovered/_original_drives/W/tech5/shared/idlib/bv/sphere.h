
// ========================================================================
// ?ContainsPoint@idSphere@@QBA_NABVidVec3@@@Z
// EA  : 0x827DAAE8
// RVA : 0x007DAAE8
// PDB : w:\tech5\shared\idlib\bv\sphere.h
// ========================================================================

BOOL __fastcall idSphere::ContainsPoint(idSphere *this, const idVec3 *p)
{
  double v2; // fp12
  double v3; // fp6

  v2 = (float)(p->y - this->origin.y);
  v3 = (float)(p->z - this->origin.z);
  return (float)((float)((float)v3 * (float)v3)
               + (float)((float)((float)(p->x - this->origin.x) * (float)(p->x - this->origin.x))
                       + (float)((float)v2 * (float)v2))) <= (double)(float)(this->radius * this->radius);
}

