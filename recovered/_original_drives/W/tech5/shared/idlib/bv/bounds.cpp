
// ========================================================================
// ?GetRadius@idBounds@@QBAMXZ
// EA  : 0x82EF6D20
// RVA : 0x00EF6D20
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

float __fastcall idBounds::GetRadius(idBounds *this)
{
  double v1; // fp0
  double v2; // fp13
  double v3; // fp12
  double v4; // fp0
  double v5; // fp13
  double v6; // fp12
  double v7; // fp0
  double v8; // fp13
  double v9; // fp0
  double v10; // fp1

  v1 = __fabs(this->b[0].x);
  v2 = __fabs(this->b[1].x);
  if ( v1 <= v2 )
    v3 = (float)((float)v2 * (float)v2);
  else
    v3 = (float)((float)v1 * (float)v1);
  v4 = __fabs(this->b[0].y);
  v5 = __fabs(this->b[1].y);
  if ( v4 <= v5 )
    v6 = (float)((float)((float)v5 * (float)v5) + (float)v3);
  else
    v6 = (float)((float)((float)v4 * (float)v4) + (float)v3);
  v7 = __fabs(this->b[0].z);
  v8 = __fabs(this->b[1].z);
  if ( v7 <= v8 )
    v9 = (float)((float)((float)v8 * (float)v8) + (float)v6);
  else
    v9 = (float)((float)((float)v7 * (float)v7) + (float)v6);
  v10 = __fsqrts(v9);
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?GetInternalRadiusXY@idBounds@@QBAMXZ
// EA  : 0x82EF6D98
// RVA : 0x00EF6D98
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

float __fastcall idBounds::GetInternalRadiusXY(idBounds *this)
{
  float result; // fp1

  _FP6 = (float)((float)((float)(this->b[1].x - this->b[0].x) * (float)0.5)
               - (float)((float)(this->b[1].y - this->b[0].y) * (float)0.5));
  __asm { fsel      f1, f6, f7, f8 }
  LODWORD(result) = _FP1;
  return result;
}


// ========================================================================
// ?GetRadiusXY@idBounds@@QBAMXZ
// EA  : 0x82EF6DD0
// RVA : 0x00EF6DD0
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

float __fastcall idBounds::GetRadiusXY(idBounds *this)
{
  double v1; // fp0
  double v2; // fp13
  double v3; // fp12
  double v4; // fp0
  double v5; // fp13
  double v6; // fp0
  double v7; // fp1

  v1 = __fabs(this->b[0].x);
  v2 = __fabs(this->b[1].x);
  if ( v1 <= v2 )
    v3 = (float)((float)v2 * (float)v2);
  else
    v3 = (float)((float)v1 * (float)v1);
  v4 = __fabs(this->b[0].y);
  v5 = __fabs(this->b[1].y);
  if ( v4 <= v5 )
    v6 = (float)((float)((float)v5 * (float)v5) + (float)v3);
  else
    v6 = (float)((float)((float)v4 * (float)v4) + (float)v3);
  v7 = __fsqrts(v6);
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetRadius@idBounds@@QBAMABVidVec3@@@Z
// EA  : 0x82EF6E28
// RVA : 0x00EF6E28
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

float __fastcall idBounds::GetRadius(idBounds *this, const idVec3 *center)
{
  double v2; // fp0
  double v3; // fp13
  double v4; // fp12
  double v5; // fp0
  double v6; // fp13
  double v7; // fp12
  double v8; // fp0
  double v9; // fp13
  double v10; // fp0
  double v11; // fp1

  v2 = __fabs((float)(center->x - this->b[0].x));
  v3 = __fabs((float)(this->b[1].x - center->x));
  if ( v2 <= v3 )
    v4 = (float)((float)v3 * (float)v3);
  else
    v4 = (float)((float)v2 * (float)v2);
  v5 = __fabs((float)(center->y - this->b[0].y));
  v6 = __fabs((float)(this->b[1].y - center->y));
  if ( v5 <= v6 )
    v7 = (float)((float)((float)v6 * (float)v6) + (float)v4);
  else
    v7 = (float)((float)((float)v5 * (float)v5) + (float)v4);
  v8 = __fabs((float)(center->z - this->b[0].z));
  v9 = __fabs((float)(this->b[1].z - center->z));
  if ( v8 <= v9 )
    v10 = (float)((float)((float)v9 * (float)v9) + (float)v7);
  else
    v10 = (float)((float)((float)v8 * (float)v8) + (float)v7);
  v11 = __fsqrts(v10);
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?PlaneSide@idBounds@@QBAHABVidPlane@@M@Z
// EA  : 0x82EF6EC8
// RVA : 0x00EF6EC8
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

int __fastcall idBounds::PlaneSide(idBounds *this, const idPlane *plane, double epsilon)
{
  double v3; // fp6
  double v4; // fp5
  double v5; // fp3
  int result; // r3
  double v7; // fp0

  v3 = __fabs((float)((float)(this->b[1].x - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5)) * plane->a));
  v4 = __fabs((float)((float)(this->b[1].y - (float)((float)(this->b[1].y + this->b[0].y) * (float)0.5)) * plane->b));
  v5 = __fabs((float)((float)(this->b[1].z - (float)((float)(this->b[1].z + this->b[0].z) * (float)0.5)) * plane->c));
  if ( (float)((float)((float)((float)(plane->a * (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))
                             + (float)((float)(plane->b * (float)((float)(this->b[1].y + this->b[0].y) * (float)0.5))
                                     + (float)(plane->c * (float)((float)(this->b[1].z + this->b[0].z) * (float)0.5))))
                     + plane->d)
             - (float)((float)((float)v4 + (float)v3) + (float)v5)) > epsilon )
    return 0;
  v7 = (float)((float)((float)((float)v4 + (float)v3) + (float)v5)
             + (float)((float)((float)(plane->a * (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))
                             + (float)((float)(plane->b * (float)((float)(this->b[1].y + this->b[0].y) * (float)0.5))
                                     + (float)(plane->c * (float)((float)(this->b[1].z + this->b[0].z) * (float)0.5))))
                     + plane->d));
  result = 1;
  if ( v7 >= -epsilon )
    return 3;
  return result;
}


// ========================================================================
// ?LineIntersection@idBounds@@QBA_NABVidVec3@@0@Z
// EA  : 0x82EF6F88
// RVA : 0x00EF6F88
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

BOOL __fastcall idBounds::LineIntersection(idBounds *this, const idVec3 *start, const idVec3 *end)
{
  double v3; // fp3
  double v5; // fp5
  double v6; // fp7

  v3 = __fabs((float)((float)(end->x - start->x) * (float)0.5));
  if ( __fabs((float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5))
                    - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))) > (float)((float)(this->b[1].x - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))
                                                                                           + (float)v3) )
    return false;
  v5 = __fabs((float)((float)(end->y - start->y) * (float)0.5));
  if ( __fabs((float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                    - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5))) > (float)((float)(this->b[1].y - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5))
                                                                                           + (float)v5) )
    return false;
  v6 = __fabs((float)((float)(end->z - start->z) * (float)0.5));
  return __fabs((float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                      - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5))) <= (float)((float)(this->b[1].z - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5))
                                                                                              + (float)v6)
      && __fabs((float)((float)((float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                                      - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5))
                              * (float)((float)(end->y - start->y) * (float)0.5))
                      - (float)((float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                      - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5))
                              * (float)((float)(end->z - start->z) * (float)0.5)))) <= (float)((float)((float)(this->b[1].y - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5)) * (float)v6)
                                                                                             + (float)((float)(this->b[1].z - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5)) * (float)v5))
      && __fabs((float)((float)((float)((float)(end->z - start->z) * (float)0.5)
                              * (float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5))
                                      - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5)))
                      - (float)((float)((float)(start->z + (float)((float)(end->z - start->z) * (float)0.5))
                                      - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5))
                              * (float)((float)(end->x - start->x) * (float)0.5)))) <= (float)((float)((float)(this->b[1].z - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5)) * (float)v3)
                                                                                             + (float)((float)(this->b[1].x - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5)) * (float)v6))
      && __fabs((float)((float)((float)((float)(start->y + (float)((float)(end->y - start->y) * (float)0.5))
                                      - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5))
                              * (float)((float)(end->x - start->x) * (float)0.5))
                      - (float)((float)((float)(end->y - start->y) * (float)0.5)
                              * (float)((float)(start->x + (float)((float)(end->x - start->x) * (float)0.5))
                                      - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5))))) <= (float)((float)((float)(this->b[1].y - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5)) * (float)v3) + (float)((float)(this->b[1].x - (float)((float)(this->b[1].x + this->b[0].x) * (float)0.5)) * (float)v5));
}


// ========================================================================
// ?FromTransformedBounds@idBounds@@QAAXABV1@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82EF70D0
// RVA : 0x00EF70D0
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromTransformedBounds(
        idBounds *this,
        const idBounds *bounds,
        const idVec3 *origin,
        const idMat3 *axis)
{
  double v4; // fp9
  double v5; // fp6
  double v6; // fp3
  double v7; // fp2
  double v8; // fp1
  double v9; // fp12
  double v10; // fp13

  v4 = __fabs((float)(axis->mat[0].x
                    * (float)(bounds->b[1].x - (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))));
  v5 = (float)((float)__fabs((float)(axis->mat[1].x
                                   * (float)(bounds->b[1].y
                                           - (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5))))
             + (float)__fabs((float)(axis->mat[2].x
                                   * (float)(bounds->b[1].z
                                           - (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5)))));
  v8 = (float)(origin->z
             + (float)((float)(axis->mat[0].z * (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                     + (float)((float)(axis->mat[2].z * (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))
                             + (float)(axis->mat[1].z * (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5)))));
  v9 = (float)((float)((float)__fabs((float)(axis->mat[1].z
                                           * (float)(bounds->b[1].y
                                                   - (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5))))
                     + (float)__fabs((float)(axis->mat[2].z
                                           * (float)(bounds->b[1].z
                                                   - (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5)))))
             + (float)__fabs((float)(axis->mat[0].z
                                   * (float)(bounds->b[1].x
                                           - (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5)))));
  v7 = (float)(origin->y
             + (float)((float)(axis->mat[0].y * (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                     + (float)((float)(axis->mat[2].y * (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))
                             + (float)(axis->mat[1].y * (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5)))));
  v10 = (float)((float)((float)__fabs((float)(axis->mat[1].y
                                            * (float)(bounds->b[1].y
                                                    - (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5))))
                      + (float)__fabs((float)(axis->mat[2].y
                                            * (float)(bounds->b[1].z
                                                    - (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5)))))
              + (float)__fabs((float)(axis->mat[0].y
                                    * (float)(bounds->b[1].x
                                            - (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5)))));
  v6 = (float)(origin->x
             + (float)((float)(axis->mat[0].x * (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                     + (float)((float)(axis->mat[2].x * (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))
                             + (float)(axis->mat[1].x * (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5)))));
  this->b[0].x = (float)(origin->x
                       + (float)((float)(axis->mat[0].x * (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                               + (float)((float)(axis->mat[2].x
                                               * (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))
                                       + (float)(axis->mat[1].x
                                               * (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5)))))
               - (float)((float)v5 + (float)v4);
  this->b[0].z = (float)v8 - (float)v9;
  this->b[0].y = (float)v7 - (float)v10;
  this->b[1].x = (float)v6 + (float)((float)v5 + (float)v4);
  this->b[1].y = (float)v10 + (float)v7;
  this->b[1].z = (float)v9 + (float)v8;
}


// ========================================================================
// ?FromTransformedBounds@idBounds@@QAAXABV1@ABVidVec3@@ABVidMat3@@1@Z
// EA  : 0x82EF7228
// RVA : 0x00EF7228
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromTransformedBounds(
        idBounds *this,
        const idBounds *bounds,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *scale)
{
  double v5; // fp13
  double v6; // fp8
  double v7; // fp10
  double v8; // fp5
  double v9; // fp4
  double v10; // fp3
  double v11; // fp2
  double v12; // fp0

  v5 = __fabs((float)(axis->mat[2].x
                    * (float)((float)(scale->z * bounds->b[1].z)
                            - (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * scale->z) * (float)0.5))));
  v6 = (float)((float)__fabs((float)(axis->mat[1].x
                                   * (float)((float)(scale->y * bounds->b[1].y)
                                           - (float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * scale->y)
                                                   * (float)0.5))))
             + (float)__fabs((float)(axis->mat[0].x
                                   * (float)((float)(scale->x * bounds->b[1].x)
                                           - (float)((float)((float)(bounds->b[0].x + bounds->b[1].x) * scale->x)
                                                   * (float)0.5)))));
  v7 = __fabs((float)(axis->mat[1].z
                    * (float)((float)(scale->y * bounds->b[1].y)
                            - (float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * scale->y) * (float)0.5))));
  v8 = (float)((float)__fabs((float)(axis->mat[0].z
                                   * (float)((float)(scale->x * bounds->b[1].x)
                                           - (float)((float)((float)(bounds->b[0].x + bounds->b[1].x) * scale->x)
                                                   * (float)0.5))))
             + (float)__fabs((float)(axis->mat[2].z
                                   * (float)((float)(scale->z * bounds->b[1].z)
                                           - (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * scale->z)
                                                   * (float)0.5)))));
  v9 = (float)(origin->x
             + (float)((float)(axis->mat[0].x
                             * (float)((float)((float)(bounds->b[0].x + bounds->b[1].x) * scale->x) * (float)0.5))
                     + (float)((float)(axis->mat[1].x
                                     * (float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * scale->y) * (float)0.5))
                             + (float)(axis->mat[2].x
                                     * (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * scale->z) * (float)0.5)))));
  v10 = (float)(origin->y
              + (float)((float)(axis->mat[0].y
                              * (float)((float)((float)(bounds->b[0].x + bounds->b[1].x) * scale->x) * (float)0.5))
                      + (float)((float)(axis->mat[1].y
                                      * (float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * scale->y) * (float)0.5))
                              + (float)(axis->mat[2].y
                                      * (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * scale->z) * (float)0.5)))));
  v11 = (float)(origin->z
              + (float)((float)(axis->mat[0].z
                              * (float)((float)((float)(bounds->b[0].x + bounds->b[1].x) * scale->x) * (float)0.5))
                      + (float)((float)(axis->mat[1].z
                                      * (float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * scale->y) * (float)0.5))
                              + (float)(axis->mat[2].z
                                      * (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * scale->z) * (float)0.5)))));
  v12 = (float)((float)((float)__fabs((float)(axis->mat[1].y
                                            * (float)((float)(scale->y * bounds->b[1].y)
                                                    - (float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * scale->y)
                                                            * (float)0.5))))
                      + (float)__fabs((float)(axis->mat[0].y
                                            * (float)((float)(scale->x * bounds->b[1].x)
                                                    - (float)((float)((float)(bounds->b[0].x + bounds->b[1].x) * scale->x)
                                                            * (float)0.5)))))
              + (float)__fabs((float)(axis->mat[2].y
                                    * (float)((float)(scale->z * bounds->b[1].z)
                                            - (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * scale->z)
                                                    * (float)0.5)))));
  this->b[0].x = (float)(origin->x
                       + (float)((float)(axis->mat[0].x
                                       * (float)((float)((float)(bounds->b[0].x + bounds->b[1].x) * scale->x)
                                               * (float)0.5))
                               + (float)((float)(axis->mat[1].x
                                               * (float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * scale->y)
                                                       * (float)0.5))
                                       + (float)(axis->mat[2].x
                                               * (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * scale->z)
                                                       * (float)0.5)))))
               - (float)((float)v6 + (float)v5);
  this->b[0].z = (float)v11 - (float)((float)v8 + (float)v7);
  this->b[0].y = (float)v10 - (float)v12;
  this->b[1].x = (float)v9 + (float)((float)v6 + (float)v5);
  this->b[1].y = (float)v12 + (float)v10;
  this->b[1].z = (float)((float)v8 + (float)v7) + (float)v11;
}


// ========================================================================
// ?FromModelMatrixBounds@idBounds@@QAAXABV1@ABVidRenderMatrix@@@Z
// EA  : 0x82EF7398
// RVA : 0x00EF7398
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromModelMatrixBounds(
        idBounds *this,
        const idBounds *bounds,
        const idRenderMatrix *modelMatrix)
{
  double v3; // fp6
  double v4; // fp0
  double v5; // fp7
  double v6; // fp5
  double v7; // fp3
  double v8; // fp2
  double v9; // fp1
  double v10; // fp10

  v3 = __fabs((float)((float)(bounds->b[1].y - (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5))
                    * modelMatrix->m[1]));
  v4 = __fabs((float)(modelMatrix->m[4]
                    * (float)(bounds->b[1].x - (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))));
  v5 = (float)((float)__fabs((float)(modelMatrix->m[0]
                                   * (float)(bounds->b[1].x
                                           - (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))))
             + (float)__fabs((float)((float)(bounds->b[1].z
                                           - (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))
                                   * modelMatrix->m[2])));
  v6 = (float)((float)__fabs((float)(modelMatrix->m[6]
                                   * (float)(bounds->b[1].z
                                           - (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))))
             + (float)__fabs((float)(modelMatrix->m[5]
                                   * (float)(bounds->b[1].y
                                           - (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5)))));
  v8 = (float)((float)((float)(modelMatrix->m[4] * (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                     + (float)((float)(modelMatrix->m[6] * (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))
                             + (float)(modelMatrix->m[5] * (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5))))
             + modelMatrix->m[7]);
  v9 = (float)((float)((float)((float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5) * modelMatrix->m[8])
                     + (float)((float)(modelMatrix->m[10]
                                     * (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))
                             + (float)(modelMatrix->m[9] * (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5))))
             + modelMatrix->m[11]);
  v10 = (float)((float)((float)__fabs((float)(modelMatrix->m[10]
                                            * (float)(bounds->b[1].z
                                                    - (float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5))))
                      + (float)__fabs((float)(modelMatrix->m[9]
                                            * (float)(bounds->b[1].y
                                                    - (float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5)))))
              + (float)__fabs((float)((float)(bounds->b[1].x
                                            - (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                                    * modelMatrix->m[8])));
  v7 = (float)((float)((float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5) * modelMatrix->m[1])
                     + (float)((float)(modelMatrix->m[0] * (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                             + (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5) * modelMatrix->m[2])))
             + modelMatrix->m[3]);
  this->b[0].x = (float)((float)((float)((float)((float)(bounds->b[0].y + bounds->b[1].y) * (float)0.5)
                                       * modelMatrix->m[1])
                               + (float)((float)(modelMatrix->m[0]
                                               * (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))
                                       + (float)((float)((float)(bounds->b[0].z + bounds->b[1].z) * (float)0.5)
                                               * modelMatrix->m[2])))
                       + modelMatrix->m[3])
               - (float)((float)v5 + (float)v3);
  this->b[0].y = (float)v8 - (float)((float)v6 + (float)v4);
  this->b[0].z = (float)v9 - (float)v10;
  this->b[1].x = (float)((float)v5 + (float)v3) + (float)v7;
  this->b[1].y = (float)v8 + (float)((float)v6 + (float)v4);
  this->b[1].z = (float)v9 + (float)v10;
}


// ========================================================================
// ?FromBoundsTranslation@idBounds@@QAAXABV1@ABVidVec3@@ABVidMat3@@1@Z
// EA  : 0x82EF7518
// RVA : 0x00EF7518
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromBoundsTranslation(
        idBounds *this,
        const idBounds *bounds,
        const idVec3 *boundsOrigin,
        const idMat3 *boundsAxis,
        const idVec3 *translation)
{
  char v5; // r11
  double v6; // fp8
  double v7; // fp6
  double y; // fp3
  double v9; // fp2
  double v10; // fp13

  if ( boundsAxis->mat[0].x != 1.0 || boundsAxis->mat[1].y != 1.0 || (v5 = 0, boundsAxis->mat[2].z != 1.0) )
    v5 = 1;
  if ( v5 != 0 )
  {
    idBounds::FromTransformedBounds(this, bounds, origin: boundsOrigin, axis: boundsAxis);
  }
  else
  {
    v6 = (float)(bounds->b[0].y + boundsOrigin->y);
    v7 = (float)(bounds->b[0].z + boundsOrigin->z);
    this->b[0].x = bounds->b[0].x + boundsOrigin->x;
    this->b[0].y = v6;
    this->b[0].z = v7;
    y = bounds->b[1].y;
    v9 = boundsOrigin->y;
    v10 = (float)(bounds->b[1].z + boundsOrigin->z);
    this->b[1].x = boundsOrigin->x + bounds->b[1].x;
    this->b[1].y = (float)y + (float)v9;
    this->b[1].z = v10;
  }
  if ( translation->x >= 0.0 )
    this->b[1].x = translation->x + this->b[1].x;
  else
    this->b[0].x = translation->x + this->b[0].x;
  if ( translation->y >= 0.0 )
    this->b[1].y = translation->y + this->b[1].y;
  else
    this->b[0].y = translation->y + this->b[0].y;
  if ( translation->z >= 0.0 )
    this->b[1].z = translation->z + this->b[1].z;
  else
    this->b[0].z = this->b[0].z + translation->z;
}


// ========================================================================
// ?FromPointRotation180@idBounds@@QAAXABVidVec3@@ABVidRotation@@@Z
// EA  : 0x82EF7668
// RVA : 0x00EF7668
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromPointRotation180(idBounds *this, const idVec3 *start, idRotation *rotation)
{
  double x; // fp5
  double v7; // fp8
  double v8; // fp0
  float z; // r9
  double y; // fp4
  float v11; // r8
  double v12; // fp3
  float v13; // r7
  double v14; // fp2
  float v15; // r6
  double v16; // fp1
  double v17; // fp6
  double v18; // fp9
  double v19; // fp11
  double v20; // fp10
  double v21; // fp2
  double v22; // fp30
  double v23; // fp31
  double v24; // fp29
  double v25; // fp1
  unsigned int v26; // r5
  unsigned int v27; // r4
  unsigned int v28; // r3
  BOOL v29; // r8
  double v30; // fp12
  double v31; // fp13
  double v32; // fp0
  BOOL v33; // r7
  BOOL v34; // r6
  double v35; // fp12
  double v36; // fp13
  double v37; // fp11
  idRotation v50; // [sp+60h] [-90h] BYREF

  idRotation::operator*(this: &v50, result: rotation, v: start);
  x = v50.origin.x;
  v7 = start->x;
  v8 = (float)(start->x + v50.origin.x);
  z = rotation->vec.z;
  y = v50.origin.y;
  v11 = rotation->origin.x;
  v12 = v50.origin.z;
  v13 = rotation->vec.y;
  v14 = start->z;
  v15 = rotation->vec.x;
  v50.origin.y = rotation->origin.y;
  v16 = start->y;
  v50.origin.x = v11;
  v17 = (float)((float)v8 * (float)0.5);
  v50.origin.z = rotation->origin.z;
  v18 = (float)((float)(z
                      * (float)((float)((float)((float)v7 - v11) * v15)
                              + (float)((float)(v13 * (float)((float)v16 - v50.origin.y))
                                      + (float)(z * (float)((float)v14 - v50.origin.z)))))
              + v50.origin.z);
  v19 = (float)((float)((float)((float)((float)((float)v7 - v11) * v15)
                              + (float)((float)(v13 * (float)((float)v16 - v50.origin.y))
                                      + (float)(z * (float)((float)v14 - v50.origin.z))))
                      * v15)
              + v11);
  v20 = (float)((float)(v13
                      * (float)((float)((float)((float)v7 - v11) * v15)
                              + (float)((float)(v13 * (float)((float)v16 - v50.origin.y))
                                      + (float)(z * (float)((float)v14 - v50.origin.z)))))
              + v50.origin.y);
  v22 = (float)((float)x
              - (float)((float)((float)((float)((float)((float)v7 - v11) * v15)
                                      + (float)((float)(v13 * (float)((float)v16 - v50.origin.y))
                                              + (float)(z * (float)((float)v14 - v50.origin.z))))
                              * v15)
                      + v11));
  v23 = (float)((float)v7
              - (float)((float)((float)((float)((float)((float)v7 - v11) * v15)
                                      + (float)((float)(v13 * (float)((float)v16 - v50.origin.y))
                                              + (float)(z * (float)((float)v14 - v50.origin.z))))
                              * v15)
                      + v11));
  v24 = (float)((float)y
              - (float)((float)(v13
                              * (float)((float)((float)((float)v7 - v11) * v15)
                                      + (float)((float)(v13 * (float)((float)v16 - v50.origin.y))
                                              + (float)(z * (float)((float)v14 - v50.origin.z)))))
                      + v50.origin.y));
  v21 = (float)((float)v14
              - (float)((float)(z
                              * (float)((float)((float)((float)v7 - v11) * v15)
                                      + (float)((float)(v13 * (float)((float)v16 - v50.origin.y))
                                              + (float)(z * (float)((float)v14 - v50.origin.z)))))
                      + v50.origin.z));
  v25 = (float)((float)v16 - (float)v20);
  v50.origin.z = (float)(v13 * (float)v22) - (float)((float)v24 * v15);
  v50.origin.y = (float)((float)v21 * v15) - (float)(z * (float)v23);
  v50.origin.x = (float)((float)v25 * z) - (float)((float)v21 * v13);
  v26 = (COERCE_UNSIGNED_INT((float)((float)v24 * z) - (float)((float)((float)v12 - (float)v18) * v13)) >> 31)
      ^ (LODWORD(v50.origin.x) >> 31);
  v27 = (COERCE_UNSIGNED_INT((float)((float)((float)v12 - (float)v18) * v15) - (float)(z * (float)v22)) >> 31)
      ^ (LODWORD(v50.origin.y) >> 31);
  v28 = (LODWORD(v50.origin.z) >> 31)
      ^ (COERCE_UNSIGNED_INT((float)(v13 * (float)v23) - (float)((float)v25 * v15)) >> 31);
  v50.origin.z = (float)(v13 * (float)v23) - (float)((float)v25 * v15);
  v29 = v17 < v19;
  v30 = __fsqrts((float)((float)__fabs((float)-(float)((float)(v15 * v15) - (float)1.0))
                       * (float)((float)((float)v25 * (float)v25)
                               + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))));
  v31 = __fsqrts((float)((float)__fabs((float)-(float)((float)(v13 * v13) - (float)1.0))
                       * (float)((float)((float)v25 * (float)v25)
                               + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))));
  v32 = __fsqrts((float)((float)__fabs((float)-(float)((float)(z * z) - (float)1.0))
                       * (float)((float)((float)v25 * (float)v25)
                               + (float)((float)((float)v23 * (float)v23) + (float)((float)v21 * (float)v21)))));
  if ( v17 < v19 )
    v30 = -v30;
  v33 = (float)((float)(start->y + (float)y) * (float)0.5) < v20;
  if ( (float)((float)(start->y + (float)y) * (float)0.5) < v20 )
    v31 = -v31;
  v34 = (float)((float)(start->z + (float)v12) * (float)0.5) < v18;
  if ( (float)((float)(start->z + (float)v12) * (float)0.5) < v18 )
    v32 = -v32;
  v35 = (float)((float)v19 + (float)v30);
  v36 = (float)((float)v20 + (float)v31);
  v37 = (float)((float)v18 + (float)v32);
  if ( (_BYTE)v26 != 0 && v29 )
  {
    _FP0 = v35;
  }
  else
  {
    _FP0 = (float)((float)v7 - (float)x);
    __asm { fsel      f0, f0, f5, f8 }
  }
  this->b[0].x = _FP0;
  if ( (_BYTE)v27 != 0 && v33 )
  {
    _FP0 = v36;
  }
  else
  {
    _FP10 = (float)(start->y - (float)y);
    __asm { fsel      f0, f10, f4, f0 }
  }
  this->b[0].y = _FP0;
  if ( (_BYTE)v28 != 0 && v34 )
  {
    _FP0 = v37;
  }
  else
  {
    _FP10 = (float)(start->z - (float)v12);
    __asm { fsel      f0, f10, f3, f0 }
  }
  this->b[0].z = _FP0;
  if ( (_BYTE)v26 == 0 || v29 )
  {
    _FP12 = (float)(start->x - (float)x);
    __asm { fsel      f0, f12, f0, f5 }
  }
  else
  {
    _FP0 = v35;
  }
  this->b[1].x = _FP0;
  if ( (_BYTE)v27 == 0 || v33 )
  {
    _FP13 = (float)(start->y - (float)y);
    __asm { fsel      f0, f13, f0, f4 }
  }
  else
  {
    _FP0 = v36;
  }
  this->b[1].y = _FP0;
  if ( (_BYTE)v28 == 0 || v34 )
  {
    _FP13 = (float)(start->z - (float)v12);
    __asm { fsel      f12, f13, f0, f3 }
    this->b[1].z = _FP12;
  }
  else
  {
    this->b[1].z = v37;
  }
}


// ========================================================================
// ?FromPointRotation@idBounds@@QAAXABVidVec3@@ABVidRotation@@@Z
// EA  : 0x82EF79D8
// RVA : 0x00EF79D8
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromPointRotation(idBounds *this, const idVec3 *point, idRotation *rotation)
{
  double y; // fp5
  double v4; // fp12
  double z; // fp4
  double v6; // fp6
  double v7; // fp0
  double v8; // fp9
  double v9; // fp7

  if ( __fabs(rotation->angle) >= 180.0 )
  {
    y = rotation->origin.y;
    v4 = (float)(point->y - rotation->origin.y);
    z = rotation->origin.z;
    v6 = (float)(point->z - rotation->origin.z);
    v7 = __fsqrts((float)((float)((float)v6 * (float)v6)
                        + (float)((float)((float)(point->x - rotation->origin.x) * (float)(point->x - rotation->origin.x))
                                + (float)((float)v4 * (float)v4))));
    this->b[0].x = rotation->origin.x - (float)v7;
    this->b[0].y = (float)y - (float)v7;
    this->b[0].z = (float)z - (float)v7;
    v8 = rotation->origin.y;
    v9 = (float)(rotation->origin.z + (float)v7);
    this->b[1].x = rotation->origin.x + (float)v7;
    this->b[1].y = (float)v7 + (float)v8;
    this->b[1].z = v9;
  }
  else
  {
    idBounds::FromPointRotation180(this, start: point, rotation);
  }
}


// ========================================================================
// ?FromBoundsRotation180@idBounds@@QAAXABV1@ABVidVec3@@ABVidMat3@@ABVidRotation@@@Z
// EA  : 0x82EF7A70
// RVA : 0x00EF7A70
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromBoundsRotation180(
        idBounds *this,
        const idBounds *bounds,
        const idVec3 *boundsOrigin,
        const idMat3 *boundsAxis,
        idRotation *rotation)
{
  _R29 = this;
  _R28 = bounds;
  _R27 = boundsOrigin;
  _R31 = boundsAxis;
  _R30 = rotation;
  _R3 = idRotation::ToMat3(this: rotation);
  _R11 = 16;
  __asm { lvlx128   v63, r0, r28 }
  _R10 = &_R28->b[1];
  __asm { lvlx128   v62, r0, r31 }
  __asm { lvlx128   v61, r0, r27 }
  _R8 = 32;
  __asm { lvlx128   v60, r0, r30 }
  _R7 = &vmx_float_zero_3;
  __asm
  {
    lvlx128   v45, r0, r3
    lvrx128   v59, r11, r28
  }
  _R9 = &_R31->mat[2];
  __asm
  {
    lvlx128   v58, r0, r10
    vor128    v57, v95, v59
    lvrx128   v56, r11, r10
  }
  _R10 = &_R31->mat[1];
  __asm
  {
    vor128    v55, v90, v56
    lvrx128   v54, r11, r31
    lvx128    v63, r7, r8
    vor128    v0, v94, v54
    lvrx128   v53, r11, r27
  }
  _R6 = 112;
  __asm
  {
    vor128    v11, v93, v53
    lvlx128   v52, r0, r9
    vaddfp128 v51, v89, v55
    lvlx128   v50, r0, r10
    lvrx128   v49, r11, r10
  }
  _R5 = 128;
  __asm
  {
    vor128    v13, v82, v49
    lvrx128   v48, r11, r9
    vor128    v12, v84, v48
    lvx128    v62, r7, r6
    lvrx128   v47, r11, r30
  }
  _R10 = &_R3->mat[1];
  __asm { vor128    v46, v92, v47 }
  _R9 = &_R3->mat[2];
  __asm
  {
    lvx128    v61, r7, r5
    vmulfp128 v44, v83, v63
    vspltw128 v10, v44, 0
    vsubfp128 v43, v87, v44
    vspltw128 v9, v44, 1
    vspltw128 v8, v44, 2
    vmaddfp   v11, v0, v11, v10
    vspltw128 v42, v43, 0
    vspltw128 v41, v43, 1
    vspltw128 v40, v43, 2
    vmaddfp   v11, v13, v11, v9
    vmulfp128 v39, v0, v42
    vmulfp128 v38, v13, v41
    vmulfp128 v37, v12, v40
    vmaddfp   v0, v12, v11, v8
    vspltw128 v36, v39, 0
    vspltw128 v13, v39, 1
    vspltw128 v2, v39, 2
    vspltw128 v35, v38, 0
    vxor128   v34, v68, v62
    vspltw128 v1, v38, 1
    vxor128   v33, v13, v62
    vspltw128 v31, v38, 2
    vxor128   v32, v2, v62
    vspltw128 v60, v37, 0
    vxor128   v59, v67, v61
    vspltw128 v11, v37, 1
    vxor128   v58, v1, v61
    vspltw128 v10, v37, 2
    vxor128   v57, v31, v61
    vspltw128 v56, v0, 0
    vspltw128 v55, v0, 1
    vspltw128 v54, v0, 2
    vaddfp128 v53, v88, v34
    vaddfp128 v52, v87, v33
    vaddfp128 v51, v86, v32
    vaddfp128 v50, v85, v59
    vaddfp128 v49, v84, v58
    vspltw128 v9, v46, 0
    lvrx128   v47, r11, r3
    vor128    v45, v77, v47
    vspltw128 v8, v46, 1
    lvlx128   v44, r0, r10
    vspltw128 v7, v46, 2
    lvrx128   v43, r11, r10
    vsubfp128 v42, v81, v11
    vsubfp128 v41, v88, v9
    vor128    v6, v76, v43
    vmulfp128 v12, v68, v45
    lvlx128   v40, r0, r9
    vmulfp128 v29, v67, v45
    lvrx128   v39, r11, r9
    vmulfp128 v28, v92, v45
    vor128    v5, v72, v39
    vsubfp128 v27, v87, v8
  }
  _R10 = &_R30->vec;
  __asm { vaddfp128 v38, v81, v11 }
  _R4 = 16;
  __asm { vaddfp128 v48, v83, v57 }
  _R3 = 96;
  __asm
  {
    vsubfp128 v25, v86, v7
    vsubfp128 v34, v82, v60
    lvlx128   v35, r0, r10
    vaddfp128 v32, v82, v60
    lvrx128   v33, r11, r10
    vor128    v4, v67, v33
    vmulfp128 v26, v73, v45
    vmaddfp   v30, v13, v12, v6
    vmaddfp   v1, v1, v29, v6
    vmaddfp   v11, v11, v28, v6
    vspltw    v0, v4, 0
    vspltw    v13, v4, 1
    vspltw    v12, v4, 2
    vsubfp128 v37, v80, v10
    vaddfp128 v36, v80, v10
    vsubfp128 v60, v66, v9
    vmaddfp   v6, v27, v26, v6
    vmaddfp   v2, v2, v30, v5
    vmaddfp   v1, v31, v1, v5
    vmaddfp   v11, v10, v11, v5
    vsubfp128 v30, v69, v7
    vmaddfp   v10, v25, v6, v5
    vmr128    v59, v2
    vsubfp128 v6, v74, v8
    vmr128    v58, v1
    vmulfp128 v5, v92, v0
    vmr128    v57, v11
    lvx128    v11, r7, r4
    vspltw128 v56, v59, 0
    vspltw128 v55, v59, 1
    vspltw128 v54, v59, 2
    vspltw128 v53, v58, 0
    vspltw128 v51, v58, 1
    vxor128   v52, v88, v62
    vspltw128 v49, v58, 2
    vxor128   v50, v87, v62
    vxor128   v48, v86, v62
    vspltw128 v47, v57, 0
    vaddfp128 v46, v10, v46
    vxor128   v45, v85, v61
    vxor128   v44, v83, v61
    vspltw128 v43, v57, 1
    vxor128   v41, v81, v61
    vspltw128 v40, v57, 2
    vnmsubfp  v10, v4, v11, v4
    vspltw128 v39, v46, 0
    vspltw128 v35, v46, 1
    vspltw128 v33, v46, 2
    vaddfp128 v62, v71, v52
    vaddfp128 v61, v67, v50
    vaddfp128 v59, v65, v48
    vaddfp128 v58, v94, v45
    vaddfp128 v57, v93, v44
    vaddfp128 v56, v91, v41
    vsubfp128 v55, v90, v47
    vsubfp128 v54, v89, v43
    vsubfp128 v53, v88, v40
    vaddfp128 v52, v66, v55
    vaddfp128 v51, v74, v54
    lvx128    v62, r7, r3
    vaddfp128 v49, v90, v47
    vand128   v45, v10, v62
    vmaddfp   v10, v6, v5, v13
    vaddfp128 v47, v88, v40
    lvx128    v61, r0, r7
    vaddfp128 v48, v89, v43
  }
  _R9 = 80;
  __asm { vaddfp128 v50, v69, v53 }
  _R8 = 144;
  __asm
  {
    vspltw128 v40, v45, 0
    vsubfp128 v46, v64, v9
    vmulfp128 v44, v84, v63
    vspltw128 v39, v45, 1
    vmulfp128 v43, v83, v63
    vspltw128 v35, v45, 2
  }
  _R11 = 64;
  __asm { lvx128    v60, r7, r9 }
  _R10 = 48;
  __asm
  {
    lvx128    v62, r7, r8
    vaddfp128 v17, v64, v49
    vmaddfp   v10, v30, v10, v12
    lvx128    v59, r7, r11
    vaddfp128 v15, v68, v47
    vaddfp128 v16, v70, v48
    vmulfp128 v41, v82, v63
    vmaddfp   v6, v10, v9, v0
    vmaddfp   v5, v10, v8, v13
    vmaddfp   v10, v10, v7, v12
    vmr128    v33, v6
    vmr128    v58, v5
    vmr128    v57, v10
    vsubfp128 v56, v66, v33
    vsubfp128 v10, v74, v58
    vsubfp128 v6, v69, v57
    vsubfp128 v28, v87, v33
    vsubfp128 v3, v86, v58
    vsubfp128 v30, v85, v57
    vcmpgtfp128 v50, v89, v41
    vcmpgtfp128 v52, v65, v44
    vcmpgtfp128 v51, v90, v43
    vmulfp128 v24, v88, v56
    vor128    v4, v88, v56
    vmulfp128 v18, v88, v13
    vmulfp128 v23, v10, v12
    vmulfp128 v22, v6, v0
    vmulfp128 v21, v28, v13
    vmulfp128 v19, v30, v0
    vmulfp128 v20, v3, v12
    vand128   v14, v82, v60
    vmaddfp   v24, v10, v24, v10
    vnmsubfp  v1, v10, v18, v0
    vnmsubfp  v23, v6, v23, v13
    vnmsubfp  v5, v4, v22, v12
    vnmsubfp  v4, v3, v21, v0
    vnmsubfp  v2, v28, v19, v12
    vnmsubfp  v3, v30, v20, v13
    vand128   v20, v83, v60
    vmulfp128 v28, v78, v0
    vand128   v46, v84, v60
    vsubfp128 v30, v70, v8
    vmaddfp   v10, v6, v24, v6
    vxor128   v45, v1, v4
    vxor128   v43, v5, v2
    vxor128   v44, v23, v3
    vsubfp128 v23, v68, v7
    vmaddfp   v30, v30, v28, v13
    vsraw128  v45, v77, v62
    vsraw128  v43, v75, v62
    vsraw128  v44, v76, v62
    vmr128    v41, v10
    lvx128    v10, r7, r10
    vmulfp128 v56, v73, v40
    vmulfp128 v22, v73, v39
    vmulfp128 v41, v73, v35
    vcmpeqfp128 v27, v88, v61
    vor128    v6, v88, v56
    vcmpeqfp128 v26, v22, v61
    vor128    v2, v73, v41
    vcmpeqfp128 v24, v73, v61
    vsel      v28, v6, v11, v27
    vsel      v27, v22, v11, v26
    vrsqrtefp v6, v28
    vsel      v4, v2, v11, v24
    vmaddfp   v2, v23, v30, v12
  }
  _R9 = 4;
  _R10 = 8;
  __asm
  {
    vrsqrtefp v5, v27
    vrsqrtefp v4, v4
    vmulfp128 v1, v88, v6
    vmaddfp   v9, v2, v9, v0
    vmulfp128 v27, v6, v59
    vmaddfp   v8, v2, v8, v13
    vmulfp128 v30, v22, v5
    vmulfp128 v28, v73, v4
    vmaddfp   v7, v2, v7, v12
    vmulfp128 v26, v5, v59
    vmulfp128 v25, v4, v59
    vmaddfp   v6, v1, v10, v6
    vmr128    v127, v9
    vmr128    v126, v8
    vmaddfp   v5, v30, v10, v5
    vmaddfp   v4, v28, v10, v4
    vsubfp128 v19, v64, v127
    vmr128    v125, v7
    vsubfp128 v9, v70, v126
    vsubfp128 v124, v80, v126
    vsubfp128 v28, v81, v127
    vsubfp128 v30, v79, v125
    vsubfp128 v8, v68, v125
    vmulfp128 v18, v27, v6
    vmulfp128 v6, v26, v5
    vmulfp128 v25, v25, v4
    vmulfp128 v7, v19, v19
    vmulfp128 v24, v9, v12
    vmulfp128 v23, v124, v12
    vmr128    v4, v124
    vmulfp128 v27, v28, v13
    vmr       v1, v30
    vmulfp128 v21, v30, v0
    vmr       v30, v28
    vmulfp128 v28, v19, v13
    vmulfp128 v56, v18, v56
    vmulfp128 v26, v8, v0
    vminfp128 v5, v64, v49
    vmulfp128 v22, v6, v22
    vmulfp128 v41, v25, v41
    vmaddfp   v25, v9, v7, v9
    vnmsubfp  v24, v8, v24, v13
    vnmsubfp  v23, v1, v23, v13
    vand128   v1, v76, v52
    vnmsubfp  v3, v4, v27, v0
    vminfp128 v6, v66, v55
    vxor128   v56, v88, v46
    vnmsubfp  v31, v19, v26, v12
    vand128   v19, v75, v51
    vxor128   v46, v22, v20
    vaddfp128 v33, v88, v33
    vxor128   v56, v73, v14
    vmulfp128 v41, v17, v63
    vmaddfp   v22, v8, v25, v8
    vand128   v20, v77, v50
    vnmsubfp  v8, v9, v28, v0
    vaddfp128 v58, v78, v58
    vxor128   v46, v24, v23
    vaddfp128 v57, v88, v57
    vnmsubfp  v25, v30, v21, v12
    vandc128  v21, v76, v52
    vmulfp128 v17, v16, v63
    vmulfp128 v63, v15, v63
    vsraw128  v46, v78, v62
    vminfp128 v30, v74, v54
    vor128    v13, v65, v33
    vmr128    v56, v22
    vandc128  v22, v75, v51
    vsel      v18, v6, v13, v1
    vminfp128 v1, v69, v53
    vxor128   v52, v8, v3
    vmaxfp128 v3, v66, v55
    vmulfp128 v51, v88, v40
    vmulfp128 v44, v88, v39
    vmulfp128 v43, v88, v35
    vcmpeqfp128 v4, v83, v61
    vor128    v9, v83, v51
    vcmpeqfp128 v6, v76, v61
    vor128    v13, v76, v44
    vcmpeqfp128 v8, v75, v61
    vor128    v0, v75, v43
    vsraw128  v35, v84, v62
    vcmpgtfp128 v41, v127, v41
    vcmpgtfp128 v39, v126, v17
    vxor128   v40, v31, v25
    vcmpgtfp128 v34, v125, v63
    vor128    v31, v90, v58
    vminfp128 v7, v68, v47
    vor128    v2, v89, v57
  }
  _R11 = &_R29->b[1];
  __asm
  {
    vsraw128  v63, v72, v62
    vsel      v19, v30, v31, v19
    vsel      v31, v1, v2, v20
    vsel      v4, v9, v11, v4
    vsel      v9, v13, v11, v6
    vmaxfp128 v6, v74, v54
    vsel      v12, v0, v11, v8
    vand128   v62, v73, v60
    vrsqrtefp v0, v4
    vand128   v61, v71, v60
    vrsqrtefp v13, v9
    vand128   v60, v66, v60
    vrsqrtefp v12, v12
    vor128    v4, v65, v33
    vand128   v24, v78, v41
    vandc128  v27, v78, v41
    vand128   v25, v95, v39
    vsel      v1, v3, v4, v21
    vand128   v26, v67, v34
    vandc128  v28, v95, v39
    vmulfp128 v8, v83, v0
    vmulfp128 v9, v76, v13
    vmulfp128 v11, v75, v12
    vmulfp128 v55, v13, v59
    vmulfp128 v56, v0, v59
    vmulfp128 v54, v12, v59
    vmaddfp   v29, v8, v10, v0
    vor128    v8, v90, v58
    vmaddfp   v23, v9, v10, v13
    vmaddfp   v0, v11, v10, v12
    vmaxfp128 v10, v69, v53
    vminfp128 v12, v70, v48
    vsel      v2, v6, v8, v22
    vmaxfp128 v11, v70, v48
    vmaxfp128 v13, v68, v47
    vmaxfp128 v9, v64, v49
    vmulfp128 v53, v88, v29
    vandc128  v29, v67, v34
    vmulfp128 v52, v87, v23
    vandc128  v23, v77, v50
    vmulfp128 v50, v86, v0
    vor128    v0, v89, v57
    vsel      v3, v10, v0, v23
    vmulfp128 v49, v85, v51
    vmulfp128 v48, v84, v44
    vmulfp128 v47, v82, v43
    vxor128   v46, v81, v62
    vxor128   v45, v80, v61
    vxor128   v44, v79, v60
    vaddfp128 v10, v78, v127
    vaddfp128 v43, v77, v126
    vaddfp128 v42, v76, v125
    vsel      v4, v5, v10, v24
    vor128    v0, v75, v43
    vor128    v8, v74, v42
    vminfp128 v41, v18, v4
    vsel      v5, v12, v0, v25
    vor128    v12, v75, v43
    vsel      v6, v7, v8, v26
    vsel      v8, v9, v10, v27
    vor128    v0, v74, v42
    vminfp128 v40, v19, v5
    vsel      v10, v11, v12, v28
    vminfp128 v39, v31, v6
    vmaxfp128 v38, v1, v8
    vsel      v12, v13, v0, v29
    vmaxfp128 v37, v2, v10
    vpermwi128 v35, v41, 0xB1
    vmaxfp128 v36, v3, v12
    vpermwi128 v34, v40, 0xB1
    vpermwi128 v33, v39, 0xB1
    vpermwi128 v63, v38, 0xB1
    vminfp128 v32, v73, v35
    vminfp128 v62, v72, v34
    vminfp128 v59, v71, v33
    vmaxfp128 v58, v70, v63
    vpermwi128 v61, v37, 0xB1
    vpermwi128 v60, v36, 0xB1
    vmaxfp128 v57, v69, v61
    vpermwi128 v55, v32, 0x4E # 'N'
    vmaxfp128 v56, v68, v60
    vpermwi128 v54, v62, 0x4E # 'N'
    vpermwi128 v53, v59, 0x4E # 'N'
    vpermwi128 v51, v58, 0x4E # 'N'
    vminfp128 v52, v64, v55
    vminfp128 v50, v94, v54
    vminfp128 v47, v91, v53
    vmaxfp128 v46, v90, v51
    vpermwi128 v49, v57, 0x4E # 'N'
    vpermwi128 v48, v56, 0x4E # 'N'
    vmaxfp128 v45, v89, v49
    stvewx128 v52, r0, r29
    vmaxfp128 v44, v88, v48
    stvewx128 v50, r29, r9
    stvewx128 v47, r29, r10
    stvewx128 v46, r0, r11
    stvewx128 v45, r11, r9
    stvewx128 v44, r11, r10
  }
}


// ========================================================================
// ?FromBoundsRotation@idBounds@@QAAXABV1@ABVidVec3@@ABVidMat3@@ABVidRotation@@@Z
// EA  : 0x82EF8168
// RVA : 0x00EF8168
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

void __fastcall idBounds::FromBoundsRotation(
        idBounds *this,
        const idBounds *bounds,
        const idVec3 *boundsOrigin,
        const idMat3 *boundsAxis,
        idRotation *rotation)
{
  double y; // fp24
  double z; // fp23
  double v7; // fp13
  double v8; // fp11
  double v9; // fp10
  double v10; // fp5
  double v11; // fp4
  double v12; // fp3
  double v13; // fp2
  double v14; // fp12
  double v15; // fp6
  double v16; // fp4

  if ( __fabs(rotation->angle) >= 180.0 )
  {
    y = rotation->origin.y;
    z = rotation->origin.z;
    v7 = (float)(bounds->b[1].y - (float)((float)(bounds->b[1].y - bounds->b[0].y) * (float)0.5));
    v8 = (float)(bounds->b[1].z - (float)((float)(bounds->b[1].z - bounds->b[0].z) * (float)0.5));
    v9 = (float)(bounds->b[1].x - (float)((float)(bounds->b[1].x - bounds->b[0].x) * (float)0.5));
    v10 = (float)((float)(boundsOrigin->y
                        + (float)((float)(boundsAxis->mat[0].y
                                        * (float)((float)(bounds->b[1].x - bounds->b[0].x) * (float)0.5))
                                + (float)((float)(boundsAxis->mat[2].y
                                                * (float)((float)(bounds->b[1].z - bounds->b[0].z) * (float)0.5))
                                        + (float)(boundsAxis->mat[1].y
                                                * (float)((float)(bounds->b[1].y - bounds->b[0].y) * (float)0.5)))))
                - rotation->origin.y);
    v11 = (float)((float)(boundsOrigin->z
                        + (float)((float)(boundsAxis->mat[0].z
                                        * (float)((float)(bounds->b[1].x - bounds->b[0].x) * (float)0.5))
                                + (float)((float)(boundsAxis->mat[2].z
                                                * (float)((float)(bounds->b[1].z - bounds->b[0].z) * (float)0.5))
                                        + (float)(boundsAxis->mat[1].z
                                                * (float)((float)(bounds->b[1].y - bounds->b[0].y) * (float)0.5)))))
                - rotation->origin.z);
    v12 = (float)((float)(boundsOrigin->x
                        + (float)((float)(boundsAxis->mat[0].x
                                        * (float)((float)(bounds->b[1].x - bounds->b[0].x) * (float)0.5))
                                + (float)((float)(boundsAxis->mat[2].x
                                                * (float)((float)(bounds->b[1].z - bounds->b[0].z) * (float)0.5))
                                        + (float)(boundsAxis->mat[1].x
                                                * (float)((float)(bounds->b[1].y - bounds->b[0].y) * (float)0.5)))))
                - rotation->origin.x);
    v13 = __fsqrts((float)((float)((float)v9 * (float)v9)
                         + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7))));
    v14 = __fsqrts((float)((float)((float)v12 * (float)v12)
                         + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))));
    this->b[0].x = rotation->origin.x - (float)((float)v13 + (float)v14);
    this->b[0].y = (float)y - (float)((float)v13 + (float)v14);
    this->b[0].z = (float)z - (float)((float)v13 + (float)v14);
    v15 = rotation->origin.y;
    v16 = (float)(rotation->origin.z + (float)((float)v13 + (float)v14));
    this->b[1].x = rotation->origin.x + (float)((float)v13 + (float)v14);
    this->b[1].y = (float)v15 + (float)((float)v13 + (float)v14);
    this->b[1].z = v16;
  }
  else
  {
    idBounds::FromBoundsRotation180(this, bounds, boundsOrigin, boundsAxis, rotation);
  }
}


// ========================================================================
// ?SphereIntersection@idBounds@@QBA_NABVidSphere@@@Z
// EA  : 0x82EF82D8
// RVA : 0x00EF82D8
// PDB : w:\tech5\shared\idlib\bv\bounds.cpp
// ========================================================================

BOOL __fastcall idBounds::SphereIntersection(idBounds *this, const idSphere *s)
{
  double v2; // fp10
  double v3; // fp9
  double v4; // fp7
  double v5; // fp5
  double v6; // fp13
  double v7; // fp0
  double v8; // fp13

  v2 = (float)(s->origin.x - (float)((float)(this->b[0].x + this->b[1].x) * (float)0.5));
  v3 = (float)(s->origin.y - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5));
  v4 = (float)(s->origin.z - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5));
  if ( v2 >= (float)((float)(this->b[1].x - this->b[0].x) * (float)-0.5) )
  {
    if ( v2 <= (float)((float)(this->b[1].x - this->b[0].x) * (float)0.5) )
      v5 = (float)(s->origin.x - (float)((float)(this->b[0].x + this->b[1].x) * (float)0.5));
    else
      v5 = (float)((float)(this->b[1].x - this->b[0].x) * (float)0.5);
  }
  else
  {
    v5 = (float)((float)(this->b[1].x - this->b[0].x) * (float)-0.5);
  }
  v6 = (float)((float)(this->b[1].y - this->b[0].y) * (float)-0.5);
  if ( v3 >= v6 )
  {
    v6 = (float)((float)(this->b[1].y - this->b[0].y) * (float)0.5);
    if ( v3 <= v6 )
      v6 = (float)(s->origin.y - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5));
  }
  if ( v4 >= (float)((float)(this->b[1].z - this->b[0].z) * (float)-0.5) )
  {
    v7 = (float)((float)(this->b[1].z - this->b[0].z) * (float)0.5);
    if ( v4 <= v7 )
      v7 = (float)(s->origin.z - (float)((float)(this->b[0].z + this->b[1].z) * (float)0.5));
  }
  else
  {
    v7 = (float)((float)(this->b[1].x - this->b[0].x) * (float)-0.5);
  }
  v8 = (float)((float)(s->origin.y - (float)((float)(this->b[0].y + this->b[1].y) * (float)0.5)) - (float)v6);
  return (float)((float)((float)((float)v2 - (float)v5) * (float)((float)v2 - (float)v5))
               + (float)((float)((float)((float)v4 - (float)v7) * (float)((float)v4 - (float)v7))
                       + (float)((float)v8 * (float)v8))) < (double)(float)(s->radius * s->radius);
}

