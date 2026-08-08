
// ========================================================================
// ?Side@idPlane@@QBA?AW4planeSide_t@@ABVidVec3@@M@Z
// EA  : 0x825B9820
// RVA : 0x005B9820
// PDB : w:\tech5\shared\idlib\math\plane.h
// ========================================================================

planeSide_t __fastcall idPlane::Side(idPlane *this, const idVec3 *v, double epsilon)
{
  double v3; // fp0
  planeSide_t result; // r3

  v3 = (float)((float)((float)(v->x * this->a) + (float)((float)(v->z * this->c) + (float)(v->y * this->b))) + this->d);
  if ( v3 > epsilon )
    return PLANESIDE_FRONT;
  result = PLANESIDE_BACK;
  if ( v3 >= -epsilon )
    return PLANESIDE_ON;
  return result;
}


// ========================================================================
// ?Normalize@idPlane@@QAAM_N@Z
// EA  : 0x825BABF0
// RVA : 0x005BABF0
// PDB : w:\tech5\shared\idlib\math\plane.h
// ========================================================================

float __fastcall idPlane::Normalize(idPlane *this, bool fixDegenerate)
{
  double a; // fp9
  double c; // fp8
  double v4; // fp6
  double v7; // fp2
  double v8; // fp3
  double v9; // fp2
  double v10; // fp31
  double v11; // fp1

  a = this->a;
  c = this->c;
  v4 = (float)((float)(this->c * this->c) + (float)((float)(this->a * this->a) + (float)(this->b * this->b)));
  _FP5 = (float)((float)((float)(this->c * this->c) + (float)((float)(this->a * this->a) + (float)(this->b * this->b)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v7 = __frsqrte(_FP3);
  v8 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                     * (float)((float)((float)(this->c * this->c) + (float)((float)(this->a * this->a) + (float)(this->b * this->b)))
                                                                                             * (float)0.5))
                                                                             * (float)v7)
                                                                     - (float)1.5)
                                                     * (float)v7)
                                             * (float)((float)((float)(this->c * this->c)
                                                             + (float)((float)(this->a * this->a)
                                                                     + (float)(this->b * this->b)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v7
                                                                             * (float)((float)((float)(this->c * this->c)
                                                                                             + (float)((float)(this->a * this->a) + (float)(this->b * this->b)))
                                                                                     * (float)0.5))
                                                                     * (float)v7)
                                                             - (float)1.5)
                                             * (float)v7))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v7
                                                     * (float)((float)((float)(this->c * this->c)
                                                                     + (float)((float)(this->a * this->a)
                                                                             + (float)(this->b * this->b)))
                                                             * (float)0.5))
                                             * (float)v7)
                                     - (float)1.5)
                     * (float)v7));
  v9 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                             * (float)((float)((float)(this->c * this->c) + (float)((float)(this->a * this->a) + (float)(this->b * this->b))) * (float)0.5))
                                                                                     * (float)v7)
                                                                             - (float)1.5)
                                                             * (float)v7)
                                                     * (float)((float)((float)(this->c * this->c)
                                                                     + (float)((float)(this->a * this->a)
                                                                             + (float)(this->b * this->b)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v7
                                                                                     * (float)((float)((float)(this->c * this->c) + (float)((float)(this->a * this->a) + (float)(this->b * this->b)))
                                                                                             * (float)0.5))
                                                                             * (float)v7)
                                                                     - (float)1.5)
                                                     * (float)v7))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v7
                                                             * (float)((float)((float)(this->c * this->c)
                                                                             + (float)((float)(this->a * this->a)
                                                                                     + (float)(this->b * this->b)))
                                                                     * (float)0.5))
                                                     * (float)v7)
                                             - (float)1.5)
                             * (float)v7))
             * (float)((float)((float)(this->c * this->c)
                             + (float)((float)(this->a * this->a) + (float)(this->b * this->b)))
                     * (float)0.5));
  this->b = this->b * (float)((float)-(float)((float)((float)v9 * (float)v8) - (float)1.5) * (float)v8);
  this->a = (float)a * (float)((float)-(float)((float)((float)v9 * (float)v8) - (float)1.5) * (float)v8);
  this->c = (float)c * (float)((float)-(float)((float)((float)v9 * (float)v8) - (float)1.5) * (float)v8);
  v10 = (float)((float)((float)-(float)((float)((float)v9 * (float)v8) - (float)1.5) * (float)v8) * (float)v4);
  if ( fixDegenerate )
    idVec3::FixDegenerateNormal((idVec3 *)this);
  v11 = v10;
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?FromVecs@idPlane@@QAA_NABVidVec3@@00_N@Z
// EA  : 0x825BACB0
// RVA : 0x005BACB0
// PDB : w:\tech5\shared\idlib\math\plane.h
// ========================================================================

int __fastcall idPlane::FromVecs(
        idPlane *this,
        const idVec3 *dir1,
        const idVec3 *dir2,
        const idVec3 *p,
        bool fixDegenerate)
{
  double y; // fp0
  double z; // fp13
  double x; // fp10
  double v10; // fp12
  double v11; // fp9
  double v12; // fp6

  y = dir1->y;
  z = dir2->z;
  x = dir2->x;
  v10 = dir1->z;
  v11 = (float)(dir2->y * dir1->z);
  v12 = (float)(dir1->x * dir2->z);
  this->c = (float)(dir1->x * dir2->y) - (float)(dir2->x * dir1->y);
  this->a = (float)((float)z * (float)y) - (float)v11;
  this->b = (float)((float)x * (float)v10) - (float)v12;
  if ( idPlane::Normalize(this, fixDegenerate) == 0.0 )
    return 0;
  this->d = -(float)((float)(p->x * this->a) + (float)((float)(p->z * this->c) + (float)(p->y * this->b)));
  return 1;
}


// ========================================================================
// ?FixDegeneracies@idPlane@@QAA_NM@Z
// EA  : 0x825C3798
// RVA : 0x005C3798
// PDB : w:\tech5\shared\idlib\math\plane.h
// ========================================================================

int __fastcall idPlane::FixDegeneracies(idPlane *this, double distEpsilon)
{
  int fixed; // r30
  long double v5; // fp2
  long double v6; // fp2
  long double v7; // fp2

  fixed = idVec3::FixDegenerateNormal((idVec3 *)this);
  if ( (_BYTE)fixed != 0 )
  {
    *(double *)&v5 = (float)(this->d + (float)0.5);
    v6 = floor(x: v5);
    if ( __fabs((float)(this->d - (float)*(double *)&v6)) < distEpsilon )
    {
      *(double *)&v6 = (float)(this->d + (float)0.5);
      v7 = floor(x: v6);
      this->d = *(double *)&v7;
    }
  }
  return fixed;
}


// ========================================================================
// ?FromPoints@idPlane@@QAA_NABVidVec3@@00_N@Z
// EA  : 0x8279F638
// RVA : 0x0079F638
// PDB : w:\tech5\shared\idlib\math\plane.h
// ========================================================================

int __fastcall idPlane::FromPoints(
        idPlane *this,
        const idVec3 *p1,
        const idVec3 *p2,
        const idVec3 *p3,
        bool fixDegenerate)
{
  double v6; // fp5
  double v8; // fp3
  double v9; // fp7
  double v10; // fp1
  double v11; // fp12
  double v12; // fp11

  v6 = (float)(p3->z - p2->z);
  v8 = (float)(p1->x - p2->x);
  v9 = (float)(p3->y - p2->y);
  v10 = (float)(p1->y - p2->y);
  v11 = (float)((float)(p3->x - p2->x) * (float)(p1->y - p2->y));
  v12 = (float)((float)(p1->z - p2->z) * (float)(p3->y - p2->y));
  this->b = (float)((float)(p3->x - p2->x) * (float)(p1->z - p2->z))
          - (float)((float)(p1->x - p2->x) * (float)(p3->z - p2->z));
  this->c = (float)((float)v8 * (float)v9) - (float)v11;
  this->a = (float)((float)v10 * (float)v6) - (float)v12;
  if ( idPlane::Normalize(this, fixDegenerate) == 0.0 )
    return 0;
  this->d = -(float)((float)(p2->y * this->b) + (float)((float)(p2->z * this->c) + (float)(p2->x * this->a)));
  return 1;
}


// ========================================================================
// ?RayIntersection@idPlane@@QBA_NABVidVec3@@0AAM@Z
// EA  : 0x8288FE18
// RVA : 0x0088FE18
// PDB : w:\tech5\shared\idlib\math\plane.h
// ========================================================================

int __fastcall idPlane::RayIntersection(idPlane *this, const idVec3 *start, const idVec3 *dir, float *scale)
{
  if ( (float)((float)(dir->x * this->a) + (float)((float)(dir->y * this->b) + (float)(dir->z * this->c))) == 0.0 )
    return 0;
  *scale = -(float)((float)((float)((float)(start->x * this->a)
                                  + (float)((float)(start->y * this->b) + (float)(start->z * this->c)))
                          + this->d)
                  / (float)((float)(dir->x * this->a) + (float)((float)(dir->y * this->b) + (float)(dir->z * this->c))));
  return 1;
}

