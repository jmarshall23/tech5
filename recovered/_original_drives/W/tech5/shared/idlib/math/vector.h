
// ========================================================================
// ?NormalizeFast@idVec3@@QAAMXZ
// EA  : 0x825AFD88
// RVA : 0x005AFD88
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

float __fastcall idVec3::NormalizeFast(idVec3 *this)
{
  double x; // fp9
  double z; // fp8
  double v3; // fp6
  double v6; // fp2
  double v7; // fp3
  double v8; // fp2
  double v9; // fp1

  x = this->x;
  z = this->z;
  v3 = (float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y)));
  _FP5 = (float)((float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v6 = __frsqrte(_FP3);
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6)
                                             * (float)((float)((float)(this->z * this->z)
                                                             + (float)((float)(this->x * this->x)
                                                                     + (float)(this->y * this->y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                             * (float)((float)((float)(this->z * this->z)
                                                                                             + (float)((float)(this->x * this->x) + (float)(this->y * this->y)))
                                                                                     * (float)0.5))
                                                                     * (float)v6)
                                                             - (float)1.5)
                                             * (float)v6))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(this->z * this->z)
                                                                     + (float)((float)(this->x * this->x)
                                                                             + (float)(this->y * this->y)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  v8 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                             * (float)((float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y))) * (float)0.5))
                                                                                     * (float)v6)
                                                                             - (float)1.5)
                                                             * (float)v6)
                                                     * (float)((float)((float)(this->z * this->z)
                                                                     + (float)((float)(this->x * this->x)
                                                                             + (float)(this->y * this->y)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v6
                                                             * (float)((float)((float)(this->z * this->z)
                                                                             + (float)((float)(this->x * this->x)
                                                                                     + (float)(this->y * this->y)))
                                                                     * (float)0.5))
                                                     * (float)v6)
                                             - (float)1.5)
                             * (float)v6))
             * (float)((float)((float)(this->z * this->z)
                             + (float)((float)(this->x * this->x) + (float)(this->y * this->y)))
                     * (float)0.5));
  this->y = this->y * (float)((float)-(float)((float)((float)v8 * (float)v7) - (float)1.5) * (float)v7);
  this->x = (float)x * (float)((float)-(float)((float)((float)v8 * (float)v7) - (float)1.5) * (float)v7);
  this->z = (float)z * (float)((float)-(float)((float)((float)v8 * (float)v7) - (float)1.5) * (float)v7);
  v9 = (float)((float)((float)-(float)((float)((float)v8 * (float)v7) - (float)1.5) * (float)v7) * (float)v3);
  return *((float *)&v9 + 1);
}


// ========================================================================
// ??0idQuantizedVec3@@QAA@ABVidVec3@@@Z
// EA  : 0x825AFE10
// RVA : 0x005AFE10
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

idQuantizedVec3 *__fastcall idQuantizedVec3::idQuantizedVec3(idQuantizedVec3 *this, const idVec3 *vec)
{
  float x; // r9
  float y; // r7
  double v6; // fp2
  double v7; // fp3
  double v8; // fp2
  __int16 v9; // r4
  float back_chain; // [sp+10h] [-10h]

  x = vec->x;
  y = vec->y;
  back_chain = vec->z;
  _FP5 = (float)((float)((float)(x * x) + (float)((float)(back_chain * back_chain) + (float)(y * y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v6 = __frsqrte(_FP3);
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(x * x) + (float)((float)(back_chain * back_chain) + (float)(y * y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6)
                                             * (float)((float)((float)(x * x)
                                                             + (float)((float)(back_chain * back_chain) + (float)(y * y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v6
                                                                             * (float)((float)((float)(x * x)
                                                                                             + (float)((float)(back_chain * back_chain) + (float)(y * y)))
                                                                                     * (float)0.5))
                                                                     * (float)v6)
                                                             - (float)1.5)
                                             * (float)v6))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v6
                                                     * (float)((float)((float)(x * x)
                                                                     + (float)((float)(back_chain * back_chain)
                                                                             + (float)(y * y)))
                                                             * (float)0.5))
                                             * (float)v6)
                                     - (float)1.5)
                     * (float)v6));
  v8 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                                             * (float)((float)((float)(x * x) + (float)((float)(back_chain * back_chain) + (float)(y * y))) * (float)0.5))
                                                                                     * (float)v6)
                                                                             - (float)1.5)
                                                             * (float)v6)
                                                     * (float)((float)((float)(x * x)
                                                                     + (float)((float)(back_chain * back_chain)
                                                                             + (float)(y * y)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v6
                                                                                     * (float)((float)((float)(x * x) + (float)((float)(back_chain * back_chain) + (float)(y * y)))
                                                                                             * (float)0.5))
                                                                             * (float)v6)
                                                                     - (float)1.5)
                                                     * (float)v6))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v6
                                                             * (float)((float)((float)(x * x)
                                                                             + (float)((float)(back_chain * back_chain)
                                                                                     + (float)(y * y)))
                                                                     * (float)0.5))
                                                     * (float)v6)
                                             - (float)1.5)
                             * (float)v6))
             * (float)((float)((float)(x * x) + (float)((float)(back_chain * back_chain) + (float)(y * y))) * (float)0.5));
  v9 = (int)(float)((float)((float)((float)-(float)((float)((float)v8 * (float)v7) - (float)1.5) * (float)v7) * vec->x)
                  * (float)32767.0);
  this->y = (int)(float)((float)((float)((float)-(float)((float)((float)v8 * (float)v7) - (float)1.5) * (float)v7) * y)
                       * (float)32767.0);
  this->x = v9;
  this->z = (int)(float)((float)((float)((float)-(float)((float)((float)v8 * (float)v7) - (float)1.5) * (float)v7)
                               * back_chain)
                       * (float)32767.0);
  return this;
}


// ========================================================================
// ?FixDegenerateNormal@idVec3@@QAA_NXZ
// EA  : 0x825B9538
// RVA : 0x005B9538
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

int __fastcall idVec3::FixDegenerateNormal(idVec3 *this)
{
  double x; // fp12
  double v3; // fp0
  double y; // fp13
  double v5; // fp11
  double z; // fp13
  int result; // r3
  double v8; // fp0
  double v9; // fp13

  x = this->x;
  v3 = idMath::FLT_SMALLEST_NON_DENORMAL;
  y = this->y;
  v5 = __fabs(y);
  if ( __fabs(x) >= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    if ( v5 < v3 && __fabs(this->z) < v3 )
    {
      this->y = 0.0;
      this->z = 0.0;
      result = 1;
      if ( x <= 0.0 )
        this->x = -1.0;
      else
        this->x = 1.0;
      return result;
    }
  }
  else
  {
    if ( v5 < v3 )
    {
      z = this->z;
      this->x = 0.0;
      this->y = 0.0;
      if ( z > 0.0 )
      {
        this->z = 1.0;
        return 1;
      }
      goto LABEL_5;
    }
    if ( __fabs(this->z) < v3 )
    {
      this->x = 0.0;
      this->z = 0.0;
      result = 1;
      if ( y <= 0.0 )
        this->y = -1.0;
      else
        this->y = 1.0;
      return result;
    }
  }
  v8 = (float)((float)1.0 - (float)0.00000011920929);
  if ( __fabs(x) <= v8 )
  {
    if ( __fabs(y) <= v8 )
    {
      v9 = this->z;
      if ( __fabs(v9) <= v8 )
      {
        return 0;
      }
      else
      {
        this->x = 0.0;
        this->y = 0.0;
        if ( v9 <= 0.0 )
        {
LABEL_5:
          this->z = -1.0;
          return 1;
        }
        this->z = 1.0;
        return 1;
      }
    }
    else
    {
      this->x = 0.0;
      if ( y <= 0.0 )
      {
        this->z = 0.0;
        this->y = -1.0;
      }
      else
      {
        this->y = 1.0;
        this->z = 0.0;
      }
      return 1;
    }
  }
  else
  {
    if ( x <= 0.0 )
    {
      this->y = 0.0;
      this->z = 0.0;
      this->x = -1.0;
    }
    else
    {
      this->x = 1.0;
      this->y = 0.0;
      this->z = 0.0;
    }
    return 1;
  }
}


// ========================================================================
// ?FixDenormals@idVec3@@QAA_NXZ
// EA  : 0x825B97B0
// RVA : 0x005B97B0
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

int __fastcall idVec3::FixDenormals(idVec3 *this)
{
  double v1; // fp12
  int result; // r3
  double v4; // fp0

  v1 = __fabs(this->x);
  result = 0;
  v4 = idMath::FLT_SMALLEST_NON_DENORMAL;
  if ( v1 <= idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    this->x = 0.0;
    result = 1;
    v4 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->y) <= v4 )
  {
    this->y = 0.0;
    result = 1;
    v4 = idMath::FLT_SMALLEST_NON_DENORMAL;
  }
  if ( __fabs(this->z) <= v4 )
  {
    this->z = 0.0;
    return 1;
  }
  return result;
}


// ========================================================================
// ?ProjectOntoPlane@idVec3@@QAAXABV1@M@Z
// EA  : 0x825E34F8
// RVA : 0x005E34F8
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

void __fastcall idVec3::ProjectOntoPlane(idVec3 *this, const idVec3 *normal, double overBounce)
{
  double y; // fp13
  double v4; // fp9
  double z; // fp10
  double v6; // fp8
  double v7; // fp0

  y = normal->y;
  v4 = this->y;
  z = normal->z;
  v6 = this->z;
  v7 = (float)((float)(this->z * normal->z) + (float)((float)(this->x * normal->x) + (float)(this->y * normal->y)));
  if ( overBounce != 1.0 )
  {
    if ( v7 >= 0.0 )
      v7 = (float)((float)((float)(this->z * normal->z)
                         + (float)((float)(this->x * normal->x) + (float)(this->y * normal->y)))
                 / (float)overBounce);
    else
      v7 = (float)((float)((float)(this->z * normal->z)
                         + (float)((float)(this->x * normal->x) + (float)(this->y * normal->y)))
                 * (float)overBounce);
  }
  this->x = this->x - (float)(normal->x * (float)v7);
  this->y = (float)v4 - (float)((float)y * (float)v7);
  this->z = (float)v6 - (float)((float)z * (float)v7);
}


// ========================================================================
// ?NormalVectors@idVec3@@QBAXAAV1@0@Z
// EA  : 0x826AAFC8
// RVA : 0x006AAFC8
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

void __fastcall idVec3::NormalVectors(idVec3 *this, idVec3 *left, idVec3 *down)
{
  double v3; // fp13
  double v6; // fp6
  double v7; // fp2
  double v8; // fp13
  double v9; // fp8
  double v10; // fp11
  double y; // fp0
  double x; // fp8
  double z; // fp13
  double v14; // fp9
  double v15; // fp7

  v3 = (float)((float)(this->x * this->x) + (float)(this->y * this->y));
  if ( v3 == 0.0 )
  {
    left->y = 0.0;
    left->x = 1.0;
  }
  else
  {
    _FP9 = (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y)) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f9, f13, f12 }
    v6 = __frsqrte(_FP7);
    v7 = (float)((float)-(float)((float)((float)((float)v6
                                               * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y))
                                                       * (float)0.5))
                                       * (float)v6)
                               - (float)1.5)
               * (float)v6);
    v8 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v6
                                                                               * (float)((float)v3 * (float)0.5))
                                                                       * (float)v6)
                                                               - (float)1.5)
                                               * (float)v6)
                                       * (float)((float)v3 * (float)0.5))
                               * (float)((float)-(float)((float)((float)((float)v6 * (float)((float)v3 * (float)0.5))
                                                               * (float)v6)
                                                       - (float)1.5)
                                       * (float)v6))
                       - (float)1.5);
    v9 = (float)-(float)((float)((float)((float)((float)v8 * (float)v7)
                                       * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y))
                                               * (float)0.5))
                               * (float)((float)v8 * (float)v7))
                       - (float)1.5);
    left->x = -(float)((float)((float)-(float)((float)((float)((float)((float)v8 * (float)v7)
                                                             * (float)((float)((float)(this->x * this->x)
                                                                             + (float)(this->y * this->y))
                                                                     * (float)0.5))
                                                     * (float)((float)v8 * (float)v7))
                                             - (float)1.5)
                             * (float)((float)v8 * (float)v7))
                     * this->y);
    left->y = this->x * (float)((float)v9 * (float)((float)v8 * (float)v7));
  }
  left->z = 0.0;
  y = left->y;
  x = left->x;
  z = this->z;
  v14 = (float)(this->y * (float)0.0);
  v15 = (float)(left->y * this->x);
  v10 = this->y;
  down->y = (float)((float)0.0 * this->x) - (float)(left->x * this->z);
  down->x = (float)((float)z * (float)y) - (float)v14;
  down->z = (float)((float)x * (float)v10) - (float)v15;
}


// ========================================================================
// ?OrthogonalBasis@idVec3@@QBAXAAV1@0@Z
// EA  : 0x826AB0B0
// RVA : 0x006AB0B0
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

void __fastcall idVec3::OrthogonalBasis(idVec3 *this, idVec3 *left, idVec3 *up)
{
  double v3; // fp13
  double v4; // fp10
  double y; // fp9
  double v6; // fp8
  double v8; // fp5
  double v10; // fp3
  double v11; // fp9
  double v12; // fp5
  double v15; // fp3
  double v16; // fp6
  double v17; // fp3
  double v18; // fp1
  double v19; // fp12

  v3 = idMath::FLT_SMALLEST_NON_DENORMAL;
  if ( __fabs(this->z) <= 0.69999999 )
  {
    _FP6 = (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y)) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    v15 = __frsqrte(_FP4);
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y))
                                                                                                * 0.5))
                                                                                * (float)v15)
                                                                        - 1.5)
                                                        * (float)v15)
                                                * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y))
                                                        * 0.5))
                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                * (float)((float)((float)(this->x * this->x)
                                                                                                + (float)(this->y * this->y))
                                                                                        * 0.5))
                                                                        * (float)v15)
                                                                - 1.5)
                                                * (float)v15))
                                - 1.5)
                * (float)((float)-(float)((float)((float)((float)v15
                                                        * (float)((float)((float)(this->x * this->x)
                                                                        + (float)(this->y * this->y))
                                                                * 0.5))
                                                * (float)v15)
                                        - 1.5)
                        * (float)v15));
    v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y)) * 0.5)) * (float)v15) - 1.5)
                                                                                                * (float)v15)
                                                                                        * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y))
                                                                                                * 0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y)) * 0.5)) * (float)v15) - 1.5)
                                                                                        * (float)v15))
                                                                        - 1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                                * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y)) * 0.5))
                                                                                        * (float)v15)
                                                                                - 1.5)
                                                                * (float)v15))
                                                * (float)((float)((float)(this->x * this->x) + (float)(this->y * this->y))
                                                        * 0.5))
                                        * (float)v16)
                                - 1.5)
                * (float)v16);
    v18 = (float)((float)v17 * (float)((float)(this->x * this->x) + (float)(this->y * this->y)));
    left->x = -(float)(this->y * (float)v17);
    v19 = (float)(this->x * (float)v17);
    left->z = 0.0;
    left->y = v19;
    up->x = -(float)((float)v19 * this->z);
    up->y = left->x * this->z;
    up->z = v18;
  }
  else
  {
    v4 = (float)(this->z * this->z);
    y = this->y;
    up->x = 0;
    v6 = (float)((float)((float)y * (float)y) + (float)v4);
    _FP6 = (float)((float)((float)((float)y * (float)y) + (float)v4) - (float)v3);
    v8 = (float)((float)((float)((float)y * (float)y) + (float)v4) * (float)0.5);
    __asm { fsel      f4, f6, f8, f13 }
    v10 = __frsqrte(_FP4);
    v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                        * (float)((float)((float)((float)y * (float)y) + (float)v4)
                                                                                                * (float)0.5))
                                                                                * (float)v10)
                                                                        - (float)1.5)
                                                        * (float)v10)
                                                * (float)((float)((float)((float)y * (float)y) + (float)v4) * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v10
                                                                                * (float)((float)((float)((float)y * (float)y)
                                                                                                + (float)v4)
                                                                                        * (float)0.5))
                                                                        * (float)v10)
                                                                - (float)1.5)
                                                * (float)v10))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v10
                                                        * (float)((float)((float)((float)y * (float)y) + (float)v4)
                                                                * (float)0.5))
                                                * (float)v10)
                                        - (float)1.5)
                        * (float)v10));
    v12 = (float)-(float)((float)((float)((float)v11 * (float)v8) * (float)v11) - (float)1.5);
    up->y = (float)((float)v12 * (float)v11) * this->z;
    up->z = -(float)(this->y * (float)((float)v12 * (float)v11));
    left->x = (float)((float)v12 * (float)v11) * (float)v6;
    left->y = -(float)(up->z * this->x);
    left->z = this->x * up->y;
  }
}


// ========================================================================
// ?Truncate@idVec3@@QAAAAV1@M@Z
// EA  : 0x82747698
// RVA : 0x00747698
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

idVec3 *__fastcall idVec3::Truncate(idVec3 *this, double length)
{
  double y; // fp10
  double z; // fp9
  double v5; // fp7
  double v7; // fp5
  double v8; // fp0

  if ( length == 0.0 )
  {
    this->z = 0.0;
    this->x = 0.0;
    this->y = 0.0;
  }
  else
  {
    y = this->y;
    z = this->z;
    if ( (float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y))) > (double)(float)((float)length * (float)length) )
    {
      _FP8 = (float)((float)((float)(this->z * this->z)
                           + (float)((float)(this->x * this->x) + (float)(this->y * this->y)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v5 = (float)((float)((float)(this->z * this->z) + (float)((float)(this->x * this->x) + (float)(this->y * this->y)))
                 * (float)0.5);
      __asm { fsel      f6, f8, f0, f12 }
      v7 = __frsqrte(_FP6);
      v8 = (float)((float)-(float)((float)((float)((float)v7
                                                 * (float)((float)((float)(this->z * this->z)
                                                                 + (float)((float)(this->x * this->x)
                                                                         + (float)(this->y * this->y)))
                                                         * (float)0.5))
                                         * (float)v7)
                                 - (float)1.5)
                 * (float)v7);
      this->x = this->x
              * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)v5)
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8)
                                                              * (float)v5)
                                                      * (float)((float)-(float)((float)((float)((float)v8 * (float)v5)
                                                                                      * (float)v8)
                                                                              - (float)1.5)
                                                              * (float)v8))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v8 * (float)v5) * (float)v8) - (float)1.5)
                                      * (float)v8))
                      * (float)length);
      this->y = (float)y
              * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)v5)
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8)
                                                              * (float)v5)
                                                      * (float)((float)-(float)((float)((float)((float)v8 * (float)v5)
                                                                                      * (float)v8)
                                                                              - (float)1.5)
                                                              * (float)v8))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v8 * (float)v5) * (float)v8) - (float)1.5)
                                      * (float)v8))
                      * (float)length);
      this->z = (float)z
              * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)v5)
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8)
                                                              * (float)v5)
                                                      * (float)((float)-(float)((float)((float)((float)v8 * (float)v5)
                                                                                      * (float)v8)
                                                                              - (float)1.5)
                                                              * (float)v8))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v8 * (float)v5) * (float)v8) - (float)1.5)
                                      * (float)v8))
                      * (float)length);
    }
  }
  return this;
}


// ========================================================================
// ?DistanceFast@idVec3@@QBAMABV1@@Z
// EA  : 0x829F5C80
// RVA : 0x009F5C80
// PDB : w:\tech5\shared\idlib\math\vector.h
// ========================================================================

float __fastcall idVec3::DistanceFast(idVec3 *this, const idVec3 *v)
{
  double v2; // fp11
  double v3; // fp5
  double v4; // fp2
  double v6; // fp12
  double v8; // fp10
  double v9; // fp1

  v2 = (float)(v->z - this->z);
  v3 = (float)(v->y - this->y);
  v4 = (float)((float)((float)v3 * (float)v3)
             + (float)((float)((float)(v->x - this->x) * (float)(v->x - this->x)) + (float)((float)v2 * (float)v2)));
  _FP1 = (float)((float)((float)((float)v3 * (float)v3)
                       + (float)((float)((float)(v->x - this->x) * (float)(v->x - this->x))
                               + (float)((float)v2 * (float)v2)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v6 = (float)((float)((float)((float)v3 * (float)v3)
                     + (float)((float)((float)(v->x - this->x) * (float)(v->x - this->x))
                             + (float)((float)v2 * (float)v2)))
             * (float)0.5);
  __asm { fsel      f11, f1, f2, f13 }
  v8 = __frsqrte(_FP11);
  v9 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)v6) * (float)v8) - (float)1.5) * (float)v8)
                                                                                             * (float)v6)
                                                                                     * (float)((float)-(float)((float)((float)((float)v8 * (float)v6) * (float)v8) - (float)1.5)
                                                                                             * (float)v8))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v8 * (float)v6)
                                                                                             * (float)v8)
                                                                                     - (float)1.5)
                                                                     * (float)v8))
                                                     * (float)v6)
                                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)v6) * (float)v8) - (float)1.5)
                                                                                             * (float)v8)
                                                                                     * (float)v6)
                                                                             * (float)((float)-(float)((float)((float)((float)v8 * (float)v6) * (float)v8) - (float)1.5)
                                                                                     * (float)v8))
                                                                     - (float)1.5)
                                                     * (float)((float)-(float)((float)((float)((float)v8 * (float)v6)
                                                                                     * (float)v8)
                                                                             - (float)1.5)
                                                             * (float)v8)))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)v6)
                                                                                             * (float)v8)
                                                                                     - (float)1.5)
                                                                     * (float)v8)
                                                             * (float)v6)
                                                     * (float)((float)-(float)((float)((float)((float)v8 * (float)v6)
                                                                                     * (float)v8)
                                                                             - (float)1.5)
                                                             * (float)v8))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)v8 * (float)v6) * (float)v8) - (float)1.5)
                                     * (float)v8)))
             * (float)v4);
  return *((float *)&v9 + 1);
}

