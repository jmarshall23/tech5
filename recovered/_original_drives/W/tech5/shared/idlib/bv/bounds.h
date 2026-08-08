
// ========================================================================
// ?AddBounds@idBounds@@QAAXABV1@@Z
// EA  : 0x825AFEE8
// RVA : 0x005AFEE8
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

void __fastcall idBounds::AddBounds(idBounds *this, const idBounds *a)
{
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v6; // fp8
  double v7; // fp7

  _FP12 = (float)(this->b[0].x - a->b[0].x);
  y = this->b[0].y;
  z = this->b[0].z;
  x = this->b[1].x;
  v6 = this->b[1].y;
  v7 = this->b[1].z;
  __asm { fsel      f6, f12, f0, f13 }
  this->b[0].x = _FP6;
  _FP4 = (float)((float)y - a->b[0].y);
  __asm { fsel      f3, f4, f5, f11 }
  this->b[0].y = _FP3;
  _FP1 = (float)((float)z - a->b[0].z);
  __asm { fsel      f0, f1, f2, f10 }
  this->b[0].z = _FP0;
  _FP12 = (float)(a->b[1].x - (float)x);
  __asm { fsel      f11, f12, f13, f9 }
  this->b[1].x = _FP11;
  _FP9 = (float)(a->b[1].y - (float)v6);
  __asm { fsel      f8, f9, f10, f8 }
  this->b[1].y = _FP8;
  _FP5 = (float)(a->b[1].z - (float)v7);
  __asm { fsel      f4, f5, f6, f7 }
  this->b[1].z = _FP4;
}


// ========================================================================
// ?AddPoint@idBounds@@QAAXABVidVec3@@@Z
// EA  : 0x825B9878
// RVA : 0x005B9878
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

void __fastcall idBounds::AddPoint(idBounds *this, const idVec3 *v)
{
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v6; // fp8
  double v7; // fp7

  _FP12 = (float)(this->b[0].x - v->x);
  y = this->b[0].y;
  z = this->b[0].z;
  x = this->b[1].x;
  v6 = this->b[1].y;
  v7 = this->b[1].z;
  __asm { fsel      f6, f12, f0, f13 }
  this->b[0].x = _FP6;
  _FP4 = (float)((float)y - v->y);
  __asm { fsel      f3, f4, f5, f11 }
  this->b[0].y = _FP3;
  _FP1 = (float)((float)z - v->z);
  __asm { fsel      f0, f1, f2, f10 }
  this->b[0].z = _FP0;
  _FP12 = (float)(v->x - (float)x);
  __asm { fsel      f11, f12, f13, f9 }
  this->b[1].x = _FP11;
  _FP9 = (float)(v->y - (float)v6);
  __asm { fsel      f8, f9, f10, f8 }
  this->b[1].y = _FP8;
  _FP5 = (float)(v->z - (float)v7);
  __asm { fsel      f4, f5, f6, f7 }
  this->b[1].z = _FP4;
}


// ========================================================================
// ?ContainsPoint@idBounds@@QBA_NABVidVec3@@@Z
// EA  : 0x825BD720
// RVA : 0x005BD720
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

int __fastcall idBounds::ContainsPoint(idBounds *this, const idVec3 *p)
{
  double x; // fp12
  double y; // fp13
  double z; // fp0
  double v5; // fp13
  int result; // r3

  x = p->x;
  if ( x < this->b[0].x )
    return 0;
  y = p->y;
  if ( y < this->b[0].y )
    return 0;
  z = p->z;
  if ( z < this->b[0].z )
    return 0;
  if ( x > this->b[1].x )
    return 0;
  if ( y > this->b[1].y )
    return 0;
  v5 = this->b[1].z;
  result = 1;
  if ( z > v5 )
    return 0;
  return result;
}


// ========================================================================
// ?IntersectsBounds@idBounds@@QBA_NABV1@@Z
// EA  : 0x825C3830
// RVA : 0x005C3830
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

int __fastcall idBounds::IntersectsBounds(idBounds *this, const idBounds *a)
{
  double z; // fp13
  int result; // r3

  if ( a->b[1].x < (double)this->b[0].x )
    return 0;
  if ( a->b[1].y < (double)this->b[0].y )
    return 0;
  if ( a->b[1].z < (double)this->b[0].z )
    return 0;
  if ( a->b[0].x > (double)this->b[1].x )
    return 0;
  if ( a->b[0].y > (double)this->b[1].y )
    return 0;
  z = this->b[1].z;
  result = 1;
  if ( a->b[0].z > z )
    return 0;
  return result;
}


// ========================================================================
// ??HidBounds@@QBA?AV0@ABV0@@Z
// EA  : 0x825C71B8
// RVA : 0x005C71B8
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

idBounds *__fastcall idBounds::operator+(idBounds *this, idBounds *result, const idBounds *a)
{
  double y; // fp8
  double z; // fp7
  double x; // fp3
  double v9; // fp13
  double v12; // fp9

  *this = *result;
  y = this->b[0].y;
  z = this->b[0].z;
  _FP4 = (float)(this->b[0].x - a->b[0].x);
  x = this->b[1].x;
  __asm { fsel      f2, f4, f6, f5 }
  this->b[0].x = _FP2;
  _FP0 = (float)((float)y - a->b[0].y);
  v9 = this->b[1].y;
  __asm { fsel      f12, f0, f1, f8 }
  this->b[0].y = _FP12;
  _FP10 = (float)((float)z - a->b[0].z);
  v12 = this->b[1].z;
  __asm { fsel      f8, f10, f11, f7 }
  this->b[0].z = _FP8;
  _FP6 = (float)(a->b[1].x - (float)x);
  __asm { fsel      f5, f6, f7, f3 }
  this->b[1].x = _FP5;
  _FP3 = (float)(a->b[1].y - (float)v9);
  __asm { fsel      f2, f3, f4, f13 }
  this->b[1].y = _FP2;
  _FP0 = (float)(a->b[1].z - (float)v12);
  __asm { fsel      f13, f0, f1, f9 }
  this->b[1].z = _FP13;
  return this;
}


// ========================================================================
// ?GetVolume@idBounds@@QBAMXZ
// EA  : 0x826C9488
// RVA : 0x006C9488
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

float __fastcall idBounds::GetVolume(idBounds *this)
{
  double v1; // fp1

  if ( this->b[0].x >= (double)this->b[1].x
    || this->b[0].y >= (double)this->b[1].y
    || this->b[0].z >= (double)this->b[1].z )
  {
    v1 = 0.0;
  }
  else
  {
    v1 = (float)((float)((float)(this->b[1].z - this->b[0].z) * (float)(this->b[1].y - this->b[0].y))
               * (float)(this->b[1].x - this->b[0].x));
  }
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?IntersectsBounds@idBounds@@QBA_NABV1@M@Z
// EA  : 0x826FA8F8
// RVA : 0x006FA8F8
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

int __fastcall idBounds::IntersectsBounds(idBounds *this, const idBounds *a, double epsilon)
{
  int result; // r3
  double v4; // fp13

  if ( a->b[1].x < (double)(float)(this->b[0].x - (float)epsilon) )
    return 0;
  if ( a->b[1].y < (double)(float)(this->b[0].y - (float)epsilon) )
    return 0;
  if ( a->b[1].z < (double)(float)(this->b[0].z - (float)epsilon) )
    return 0;
  if ( a->b[0].x > (double)(float)(this->b[1].x + (float)epsilon) )
    return 0;
  if ( a->b[0].y > (double)(float)(this->b[1].y + (float)epsilon) )
    return 0;
  v4 = (float)(this->b[1].z + (float)epsilon);
  result = 1;
  if ( a->b[0].z > v4 )
    return 0;
  return result;
}


// ========================================================================
// ?RayIntersection@idBounds@@QBA_NABVidVec3@@0AAM@Z
// EA  : 0x82718DA0
// RVA : 0x00718DA0
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

int __fastcall idBounds::RayIntersection(idBounds *this, const idVec3 *start, const idVec3 *dir, float *scale)
{
  int v4; // r9
  int v5; // r8
  double x; // fp13
  int v7; // r11
  double y; // fp0
  int v9; // r11
  double z; // fp0
  int v11; // r11
  double v12; // fp0
  int v13; // r7
  int v14; // r11
  double v15; // fp11
  double v16; // fp9
  double v17; // fp0
  double v18; // fp8
  double v19; // fp13
  unsigned __int8 v20; // r11
  float back_chain[4]; // [sp+0h] [-10h] BYREF

  v4 = -1;
  v5 = 0;
  *scale = 0.0;
  x = start->x;
  if ( x >= this->b[0].x )
  {
    if ( x <= this->b[1].x )
    {
      v5 = 1;
      goto LABEL_8;
    }
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  if ( dir->x != 0.0 )
  {
    v4 = 0;
    *scale = -(float)((float)(start->x - this->b[v7].x) / dir->x);
  }
LABEL_8:
  y = start->y;
  if ( y >= this->b[0].y )
  {
    if ( y <= this->b[1].y )
    {
      ++v5;
      goto LABEL_17;
    }
    v9 = 1;
  }
  else
  {
    v9 = 0;
  }
  if ( dir->y != 0.0 && (v4 < 0 || __fabs((float)(start->y - this->b[v9].y)) > __fabs((float)(dir->y * *scale))) )
  {
    v4 = 1;
    *scale = -(float)((float)(start->y - this->b[v9].y) / dir->y);
  }
LABEL_17:
  z = start->z;
  if ( z >= this->b[0].z )
  {
    if ( z <= this->b[1].z )
    {
      ++v5;
      goto LABEL_32;
    }
    v11 = 1;
  }
  else
  {
    v11 = 0;
  }
  if ( dir->z != 0.0 && (v4 < 0 || __fabs((float)(start->z - this->b[v11].z)) > __fabs((float)(dir->z * *scale))) )
  {
    v4 = 2;
    *scale = -(float)((float)(start->z - this->b[v11].z) / dir->z);
    goto LABEL_25;
  }
LABEL_32:
  if ( v4 < 0 )
  {
    *scale = 0.0;
    return (_cntlzw(v5 - 3) & 0x20) != 0;
  }
LABEL_25:
  v12 = *scale;
  v13 = (v4 + 2) % 3;
  v14 = 4 * ((v4 + 1) % 3);
  v15 = *(&dir->x + v13);
  v16 = *(&start->x + v13);
  back_chain[v14 / 4u] = (float)(*(float *)((char *)&dir->x + v14) * *scale) + *(float *)((char *)&start->x + v14);
  v17 = (float)((float)((float)v15 * (float)v12) + (float)v16);
  v18 = *(float *)((char *)&this->b[0].x + v14);
  back_chain[v13] = v17;
  v19 = back_chain[v14 / 4u];
  if ( v19 < v18 )
    return 0;
  if ( v19 > *(&this->b[1].x + (v4 + 1) % 3) )
    return 0;
  if ( v17 < *(&this->b[0].x + v13) )
    return 0;
  v20 = 1;
  if ( v17 > *(&this->b[1].x + v13) )
    return 0;
  return v20;
}


// ========================================================================
// ?AddTranslation@idBounds@@QAAXABVidVec3@@0@Z
// EA  : 0x8272BA00
// RVA : 0x0072BA00
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

void __fastcall idBounds::AddTranslation(idBounds *this, const idVec3 *start, const idVec3 *end)
{
  _FP12 = (float)(end->x - start->x);
  __asm
  {
    fsel      f10, f12, f0, f12
    fsel      f9, f12, f12, f0
  }
  this->b[0].x = (float)_FP10 + this->b[0].x;
  this->b[1].x = (float)_FP9 + this->b[1].x;
  _FP2 = (float)(end->y - start->y);
  __asm
  {
    fsel      f1, f2, f0, f2
    fsel      f13, f2, f2, f0
  }
  this->b[0].y = (float)_FP1 + this->b[0].y;
  this->b[1].y = (float)_FP13 + this->b[1].y;
  _FP6 = (float)(end->z - start->z);
  __asm
  {
    fsel      f5, f6, f0, f6
    fsel      f4, f6, f6, f0
  }
  this->b[0].z = (float)_FP5 + this->b[0].z;
  this->b[1].z = (float)_FP4 + this->b[1].z;
}


// ========================================================================
// ?IsZero@idBounds@@QBA_NXZ
// EA  : 0x827DDFA0
// RVA : 0x007DDFA0
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

int __fastcall idBounds::IsZero(idBounds *this)
{
  unsigned __int8 v1; // r11

  if ( this->b[0].x != 0.0 )
    return 0;
  if ( this->b[1].x != 0.0 )
    return 0;
  if ( this->b[0].y != 0.0 )
    return 0;
  if ( this->b[1].y != 0.0 )
    return 0;
  if ( this->b[0].z != 0.0 )
    return 0;
  v1 = 1;
  if ( this->b[1].z != 0.0 )
    return 0;
  return v1;
}


// ========================================================================
// ?Compare@idBounds@@QBA_NABV1@@Z
// EA  : 0x82844EE8
// RVA : 0x00844EE8
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

int __fastcall idBounds::Compare(idBounds *this, const idBounds *a)
{
  char v2; // r11
  char v3; // r11
  unsigned __int8 v4; // r11
  bool v5; // zf

  if ( this->b[0].x != a->b[0].x || this->b[0].y != a->b[0].y || (v2 = 1, this->b[0].z != a->b[0].z) )
    v2 = 0;
  if ( v2 == 0 )
    return 0;
  if ( this->b[1].x != a->b[1].x || this->b[1].y != a->b[1].y || (v3 = 1, this->b[1].z != a->b[1].z) )
    v3 = 0;
  v5 = v3 != 0;
  v4 = 1;
  if ( !v5 )
    return 0;
  return v4;
}


// ========================================================================
// ?AxisProjection@idBounds@@QBAXABVidVec3@@AAM1@Z
// EA  : 0x82A470A0
// RVA : 0x00A470A0
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

void __fastcall idBounds::AxisProjection(idBounds *this, const idVec3 *dir, float *min, float *max)
{
  double v4; // fp11
  double v5; // fp10
  double v6; // fp8
  double v7; // fp9

  v4 = __fabs((float)(dir->x * (float)(this->b[1].x - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))));
  v5 = __fabs((float)(dir->y * (float)(this->b[1].y - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5))));
  v6 = (float)((float)(dir->x * (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))
             + (float)((float)(dir->y * (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5))
                     + (float)(dir->z * (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5))));
  v7 = __fabs((float)(dir->z * (float)(this->b[1].z - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5))));
  *min = (float)((float)(dir->x * (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))
               + (float)((float)(dir->y * (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5))
                       + (float)(dir->z * (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5))))
       - (float)((float)((float)v5 + (float)v4) + (float)v7);
  *max = (float)((float)((float)v5 + (float)v4) + (float)v7) + (float)v6;
}


// ========================================================================
// ?AddPointExpanded@idBounds@@QAA_NABVidVec3@@@Z
// EA  : 0x82EF85A8
// RVA : 0x00EF85A8
// PDB : w:\tech5\shared\idlib\bv\bounds.h
// ========================================================================

int __fastcall idBounds::AddPointExpanded(idBounds *this, const idVec3 *v)
{
  int result; // r3
  double x; // fp13

  x = this->b[0].x;
  result = 0;
  if ( v->x < x )
  {
    this->b[0].x = v->x;
    result = 1;
  }
  if ( v->x > (double)this->b[1].x )
  {
    this->b[1].x = v->x;
    result = 1;
  }
  if ( v->y < (double)this->b[0].y )
  {
    this->b[0].y = v->y;
    result = 1;
  }
  if ( v->y > (double)this->b[1].y )
  {
    this->b[1].y = v->y;
    result = 1;
  }
  if ( v->z < (double)this->b[0].z )
  {
    this->b[0].z = v->z;
    result = 1;
  }
  if ( v->z > (double)this->b[1].z )
  {
    this->b[1].z = v->z;
    return 1;
  }
  return result;
}

