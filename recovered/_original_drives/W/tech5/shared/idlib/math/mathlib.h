
// ========================================================================
// ??$IsValid@M@@YA_NABM@Z
// EA  : 0x824E0000
// RVA : 0x004E0000
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

int __fastcall IsValid<float>(float *f)
{
  char v1; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  if ( *(int *)f == -4194304 )
    return 0;
  if ( (COERCE_UNSIGNED_INT(*f) & 0x7F800000) != 0 || (v1 = 1, (COERCE_UNSIGNED_INT(*f) & 0x7FFFFF) == 0) )
    v1 = 0;
  v3 = v1 == 0;
  v2 = 1;
  if ( !v3 )
    return 0;
  return v2;
}


// ========================================================================
// ?Ftob@idMath@@SAEM@Z
// EA  : 0x82560EF0
// RVA : 0x00560EF0
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

int __fastcall idMath::Ftob(double f)
{
  int result; // r3

  if ( (int)f < 0 )
    return 0;
  result = 255;
  if ( (int)f <= 255 )
    return (unsigned __int8)(int)f;
  return result;
}


// ========================================================================
// ?IsValid@idMath@@SA_NM@Z
// EA  : 0x826A8078
// RVA : 0x006A8078
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

int __fastcall idMath::IsValid(double f)
{
  char v1; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf
  float back_chaina; // [sp+0h] [-10h]
  float back_chain; // [sp+0h] [-10h]

  back_chaina = f;
  if ( back_chaina == NAN )
    return 0;
  back_chain = f;
  if ( (LODWORD(back_chain) & 0x7F800000) != 0 || (v1 = 1, (LODWORD(back_chain) & 0x7FFFFF) == 0) )
    v1 = 0;
  v3 = v1 == 0;
  v2 = 1;
  if ( !v3 )
    return 0;
  return v2;
}


// ========================================================================
// ?AngleNormalize360@idMath@@SAMM@Z
// EA  : 0x826E2878
// RVA : 0x006E2878
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idMath::AngleNormalize360(double angle)
{
  double v1; // fp31
  long double v2; // fp2
  long double v3; // fp2

  v1 = angle;
  if ( angle >= 360.0 || angle < 0.0 )
  {
    *(double *)&v2 = (float)((float)angle * (float)0.0027777778);
    v3 = floor(x: v2);
    angle = (float)-(float)((float)((float)*(double *)&v3 * (float)360.0) - (float)v1);
  }
  return *((float *)&angle + 1);
}


// ========================================================================
// ?ACos@idMath@@SAMM@Z
// EA  : 0x826EC758
// RVA : 0x006EC758
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

float __fastcall idMath::ACos(long double a)
{
  double v1; // fp1
  long double v2; // fp2

  if ( *(double *)&a > -1.0 )
  {
    if ( *(double *)&a < 1.0 )
    {
      v2 = acos(x: a);
      v1 = (float)*(double *)&v2;
    }
    else
    {
      v1 = 0.0;
    }
  }
  else
  {
    v1 = 3.1415927;
  }
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?SinCos@idMath@@SAXMAAM0@Z
// EA  : 0x826EDDD8
// RVA : 0x006EDDD8
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

void __fastcall idMath::SinCos(long double a, float *s, float *c, float *a4)
{
  double v4; // fp31
  long double v7; // fp2
  long double v8; // fp2

  v4 = *(double *)&a;
  v7 = sin(x: a);
  *c = *(double *)&v7;
  *(double *)&v7 = v4;
  v8 = cos(x: v7);
  *a4 = *(double *)&v8;
}


// ========================================================================
// ?ACos16@idMath@@SAMM@Z
// EA  : 0x826EDE38
// RVA : 0x006EDE38
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

float __fastcall idMath::ACos16(double a)
{
  double v2; // fp1
  bool v3; // zf
  double v4; // fp9

  v3 = a >= 0.0;
  v2 = 0.0;
  if ( v3 )
  {
    if ( a < 1.0 )
      v2 = (float)((float)__fsqrts((float)((float)1.0 - (float)a))
                 * (float)((float)((float)((float)((float)-(float)((float)((float)a * (float)0.018729299)
                                                                 - (float)0.074261002)
                                                 * (float)a)
                                         - (float)0.21211439)
                                 * (float)a)
                         + (float)1.5707288));
  }
  else if ( a > -1.0 )
  {
    v4 = __fabs(a);
    v2 = (float)-(float)((float)((float)__fsqrts((float)((float)1.0 - (float)v4))
                               * (float)((float)((float)((float)((float)-(float)((float)((float)v4 * (float)0.018729299)
                                                                               - (float)0.074261002)
                                                               * (float)v4)
                                                       - (float)0.21211439)
                                               * (float)v4)
                                       + (float)1.5707288))
                       - (float)3.1415927);
  }
  else
  {
    v2 = 3.1415927;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?Sin16@idMath@@SAMM@Z
// EA  : 0x827D86D8
// RVA : 0x007D86D8
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idMath::Sin16(double a)
{
  double v1; // fp31
  double v2; // fp13
  long double v3; // fp2
  long double v4; // fp2
  double v5; // fp1

  v1 = a;
  if ( a < 0.0 || (v2 = idMath::TWO_PI, a >= idMath::TWO_PI) )
  {
    *(double *)&v3 = (float)(idMath::ONE_OVER_TWO_PI * (float)a);
    v4 = floor(x: v3);
    v2 = idMath::TWO_PI;
    v1 = (float)-(float)((float)(idMath::TWO_PI * (float)*(double *)&v4) - (float)v1);
  }
  if ( v1 >= 3.1415927 )
  {
    if ( v1 > (float)(idMath::HALF_PI + (float)3.1415927) )
    {
      v1 = (float)((float)v1 - (float)v2);
      goto LABEL_7;
    }
  }
  else if ( v1 <= idMath::HALF_PI )
  {
LABEL_7:
    v5 = (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)-(float)((float)((float)((float)v1 * (float)v1) * (float)0.0000000239)
                                                                                               - (float)0.0000027526)
                                                                               * (float)((float)v1 * (float)v1))
                                                                       - (float)0.000198409)
                                                               * (float)((float)v1 * (float)v1))
                                                       + (float)0.0083333319)
                                               * (float)((float)v1 * (float)v1))
                                       - (float)0.16666667)
                               * (float)((float)v1 * (float)v1))
                       + (float)1.0)
               * (float)v1);
    return *((float *)&v5 + 1);
  }
  v1 = (float)((float)3.1415927 - (float)v1);
  goto LABEL_7;
}


// ========================================================================
// ?SinCos16@idMath@@SAXMAAM0@Z
// EA  : 0x827D87D0
// RVA : 0x007D87D0
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMath::SinCos16(double a, float *s, float *c, float *a4)
{
  double v4; // fp31
  double v7; // fp13
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp8

  v4 = a;
  if ( a < 0.0 || (v7 = idMath::TWO_PI, a >= idMath::TWO_PI) )
  {
    *(double *)&v8 = (float)(idMath::ONE_OVER_TWO_PI * (float)a);
    v9 = floor(x: v8);
    v7 = idMath::TWO_PI;
    v4 = (float)-(float)((float)(idMath::TWO_PI * (float)*(double *)&v9) - (float)v4);
  }
  if ( v4 >= 3.1415927 )
  {
    if ( v4 > (float)(idMath::HALF_PI + (float)3.1415927) )
    {
      v4 = (float)((float)v4 - (float)v7);
      v10 = 1.0;
      goto LABEL_10;
    }
LABEL_9:
    v4 = (float)((float)3.1415927 - (float)v4);
    v10 = -1.0;
    goto LABEL_10;
  }
  if ( v4 > idMath::HALF_PI )
    goto LABEL_9;
  v10 = 1.0;
LABEL_10:
  *c = (float)((float)((float)((float)((float)((float)((float)((float)((float)-(float)((float)((float)((float)v4 * (float)v4)
                                                                                             * (float)0.0000000239)
                                                                                     - (float)0.0000027526)
                                                                     * (float)((float)v4 * (float)v4))
                                                             - (float)0.000198409)
                                                     * (float)((float)v4 * (float)v4))
                                             + (float)0.0083333319)
                                     * (float)((float)v4 * (float)v4))
                             - (float)0.16666667)
                     * (float)((float)v4 * (float)v4))
             + (float)1.0)
     * (float)v4;
  *a4 = (float)((float)((float)((float)((float)((float)((float)((float)((float)-(float)((float)((float)((float)v4 * (float)v4)
                                                                                              * (float)0.0000002605)
                                                                                      - (float)0.0000247609)
                                                                      * (float)((float)v4 * (float)v4))
                                                              - (float)0.0013888397)
                                                      * (float)((float)v4 * (float)v4))
                                              + (float)0.041666642)
                                      * (float)((float)v4 * (float)v4))
                              - (float)0.5)
                      * (float)((float)v4 * (float)v4))
              + (float)1.0)
      * (float)v10;
}


// ========================================================================
// ??$WrappedLerp@H@@YAHHHHHM@Z
// EA  : 0x8283EEF0
// RVA : 0x0083EEF0
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall WrappedLerp<int>(unsigned int rangeMin, unsigned int rangeMax, __int64 b, double f)
{
  __int64 v4; // r9 OVERLAPPED
  __int64 v5; // r11
  __int64 v6; // r10
  double v8; // fp0
  int v9; // r10
  double v10; // fp0
  int v11; // r10

  HIDWORD(v4) = abs32(b - HIDWORD(b));
  LODWORD(v5) = rangeMax - HIDWORD(v4) - rangeMin;
  if ( SHIDWORD(v4) > (int)v5 )
  {
    if ( (int)b < SHIDWORD(b) )
    {
      f = (float)((float)1.0 - (float)f);
      b = __PAIR64__(b, HIDWORD(b));
    }
    HIDWORD(v5) = HIDWORD(b) - rangeMin;
    LODWORD(v4) = HIDWORD(b) - rangeMin;
    v8 = (float)((float)v4 / (float)v5);
    if ( f > v8 )
    {
      v10 = (float)((float)1.0 - (float)((float)v4 / (float)v5));
      v11 = b;
      return (int)(float)((float)((float)((float)((float)*(__int64 *)((char *)&v4 - 4) - (float)__SPAIR64__(b, rangeMax))
                                        / (float)v10)
                                * (float)((float)1.0 - (float)f))
                        + (float)__SPAIR64__(b, rangeMax));
    }
    else
    {
      v9 = HIDWORD(b);
      return (int)(float)((float)((float)((float)((float)__SPAIR64__(HIDWORD(b), rangeMin)
                                                - (float)*(__int64 *)((char *)&v4 - 4))
                                        / (float)v8)
                                * (float)f)
                        + (float)*(__int64 *)((char *)&v4 - 4));
    }
  }
  else
  {
    LODWORD(v6) = HIDWORD(b);
    HIDWORD(v6) = (b - HIDWORD(b)) ^ (((int)b - HIDWORD(b)) >> 31);
    return (int)(float)((float)((float)((float)b - (float)v6) * (float)f) + (float)v6);
  }
}


// ========================================================================
// ?Exp16@idMath@@SAMM@Z
// EA  : 0x8288D138
// RVA : 0x0088D138
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

float __fastcall idMath::Exp16(double f)
{
  __int64 v1; // r9
  double v2; // fp0
  double v3; // fp10
  double v4; // fp1
  float back_chain; // [sp+0h] [-10h]

  LODWORD(v1) = ((int)(COERCE_UNSIGNED_INT((float)f * (float)1.442695) & 0x7FFFFF | 0x800000) >> (23
                                                                                                - ((COERCE_INT((float)f * (float)1.442695) >> 23)
                                                                                                 - 127)))
              & ~(((unsigned __int8)(COERCE_INT((float)f * (float)1.442695) >> 23) - 127) >> 31)
              ^ (COERCE_INT((float)f * (float)1.442695) >> 31);
  HIDWORD(v1) = v1 + 127;
  LODWORD(back_chain) = ((_DWORD)v1 + 127) << 23;
  v2 = (float)((float)((float)f * (float)1.442695) - (float)v1);
  if ( v2 < 0.5 )
  {
    v3 = back_chain;
  }
  else
  {
    v2 = (float)((float)((float)((float)f * (float)1.442695) - (float)v1) - (float)0.5);
    v3 = (float)(back_chain * (float)1.4142135);
  }
  v4 = (float)((float)((float)((float)((float)((float)v2 * (float)v2) + (float)20.818924)
                             + (float)((float)((float)((float)((float)v2 * (float)v2) * (float)0.057690073)
                                             + (float)7.2152891)
                                     * (float)v2))
                     * (float)v3)
             / (float)((float)((float)((float)v2 * (float)v2) + (float)20.818924)
                     - (float)((float)((float)((float)((float)v2 * (float)v2) * (float)0.057690073) + (float)7.2152891)
                             * (float)v2)));
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?Cos16@idMath@@SAMM@Z
// EA  : 0x8295E508
// RVA : 0x0095E508
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idMath::Cos16(double a)
{
  double v1; // fp31
  double v2; // fp13
  long double v3; // fp2
  long double v4; // fp2
  double v5; // fp0
  double v6; // fp1

  v1 = a;
  if ( a < 0.0 || (v2 = idMath::TWO_PI, a >= idMath::TWO_PI) )
  {
    *(double *)&v3 = (float)(idMath::ONE_OVER_TWO_PI * (float)a);
    v4 = floor(x: v3);
    v2 = idMath::TWO_PI;
    v1 = (float)-(float)((float)(idMath::TWO_PI * (float)*(double *)&v4) - (float)v1);
  }
  if ( v1 >= 3.1415927 )
  {
    if ( v1 > (float)(idMath::HALF_PI + (float)3.1415927) )
    {
      v1 = (float)((float)v1 - (float)v2);
      v5 = 1.0;
      goto LABEL_10;
    }
LABEL_9:
    v1 = (float)((float)3.1415927 - (float)v1);
    v5 = -1.0;
    goto LABEL_10;
  }
  if ( v1 > idMath::HALF_PI )
    goto LABEL_9;
  v5 = 1.0;
LABEL_10:
  v6 = (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)-(float)((float)((float)((float)v1 * (float)v1) * (float)0.0000002605)
                                                                                             - (float)0.0000247609)
                                                                             * (float)((float)v1 * (float)v1))
                                                                     - (float)0.0013888397)
                                                             * (float)((float)v1 * (float)v1))
                                                     + (float)0.041666642)
                                             * (float)((float)v1 * (float)v1))
                                     - (float)0.5)
                             * (float)((float)v1 * (float)v1))
                     + (float)1.0)
             * (float)v5);
  return *((float *)&v6 + 1);
}


// ========================================================================
// ??$IsValid@VidVec3@@@@YA_NABVidVec3@@@Z
// EA  : 0x82A6C528
// RVA : 0x00A6C528
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

int __fastcall IsValid<idVec3>(const idVec3 *v)
{
  int v1; // r10
  char v2; // r11

  v1 = 0;
  while ( SLODWORD(v->x) != -4194304 )
  {
    if ( (COERCE_UNSIGNED_INT(v->x) & 0x7F800000) != 0 || (v2 = 1, (COERCE_UNSIGNED_INT(v->x) & 0x7FFFFF) == 0) )
      v2 = 0;
    if ( v2 != 0 )
      break;
    ++v1;
    v = (const idVec3 *)((char *)v + 4);
    if ( v1 >= 3 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?ASin@idMath@@SAMM@Z
// EA  : 0x82C485F0
// RVA : 0x00C485F0
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

float __fastcall idMath::ASin(long double a)
{
  double v1; // fp1
  long double v2; // fp2

  if ( *(double *)&a > -1.0 )
  {
    if ( *(double *)&a < 1.0 )
    {
      v2 = asin(x: a);
      v1 = (float)*(double *)&v2;
    }
    else
    {
      v1 = idMath::HALF_PI;
    }
  }
  else
  {
    v1 = -idMath::HALF_PI;
  }
  return *((float *)&v1 + 1);
}


// ========================================================================
// ??$IsValid@VidColor@@@@YA_NABVidColor@@@Z
// EA  : 0x82EAC8D0
// RVA : 0x00EAC8D0
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

int __fastcall IsValid<idColor>(const idColor *v)
{
  int v1; // r10
  char v2; // r11

  v1 = 0;
  while ( SLODWORD(v->r) != -4194304 )
  {
    if ( (COERCE_UNSIGNED_INT(v->r) & 0x7F800000) != 0 || (v2 = 1, (COERCE_UNSIGNED_INT(v->r) & 0x7FFFFF) == 0) )
      v2 = 0;
    if ( v2 != 0 )
      break;
    ++v1;
    v = (const idColor *)((char *)v + 4);
    if ( v1 >= 4 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?Tan16@idMath@@SAMM@Z
// EA  : 0x82EB9EE0
// RVA : 0x00EB9EE0
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idMath::Tan16(double a)
{
  double v1; // fp31
  double v2; // fp13
  long double v3; // fp2
  long double v4; // fp2
  char v5; // r11
  double v6; // fp1

  v1 = a;
  if ( a < 0.0 || (v2 = 3.1415927, a >= 3.1415927) )
  {
    *(double *)&v3 = (float)(idMath::ONE_OVER_PI * (float)a);
    v4 = floor(x: v3);
    v2 = 3.1415927;
    v1 = (float)-(float)((float)(3.1415927 * (float)*(double *)&v4) - (float)v1);
  }
  if ( v1 >= idMath::HALF_PI )
  {
    if ( v1 > (float)(idMath::ONEFOURTH_PI + idMath::HALF_PI) )
    {
      v1 = (float)((float)v1 - (float)v2);
      v5 = 0;
      goto LABEL_10;
    }
  }
  else if ( v1 <= idMath::ONEFOURTH_PI )
  {
    v5 = 0;
    goto LABEL_10;
  }
  v5 = 1;
  v1 = (float)(idMath::HALF_PI - (float)v1);
LABEL_10:
  v6 = (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)v1 * (float)v1) * (float)0.0095168091) + (float)0.002900525)
                                                                                             * (float)((float)v1 * (float)v1))
                                                                                     + (float)0.024565089)
                                                                             * (float)((float)v1 * (float)v1))
                                                                     + (float)0.053374059)
                                                             * (float)((float)v1 * (float)v1))
                                                     + (float)0.13339239)
                                             * (float)((float)v1 * (float)v1))
                                     + (float)0.33333141)
                             * (float)((float)v1 * (float)v1))
                     + (float)1.0)
             * (float)v1);
  if ( v5 != 0 )
    v6 = (float)((float)1.0
               / (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)v1 * (float)v1) * (float)0.0095168091) + (float)0.002900525) * (float)((float)v1 * (float)v1))
                                                                                               + (float)0.024565089)
                                                                                       * (float)((float)v1 * (float)v1))
                                                                               + (float)0.053374059)
                                                                       * (float)((float)v1 * (float)v1))
                                                               + (float)0.13339239)
                                                       * (float)((float)v1 * (float)v1))
                                               + (float)0.33333141)
                                       * (float)((float)v1 * (float)v1))
                               + (float)1.0)
                       * (float)v1));
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?ATan16@idMath@@SAMMM@Z
// EA  : 0x82EBA000
// RVA : 0x00EBA000
// PDB : w:\tech5\shared\idlib\math\mathlib.h
// ========================================================================

float __fastcall idMath::ATan16(double y, double x)
{
  double v2; // fp3
  double v3; // fp0
  double v4; // fp1
  double v5; // fp4

  if ( __fabs(y) <= __fabs(x) )
  {
    v5 = (float)((float)((float)y / (float)x) * (float)((float)y / (float)x));
    v4 = (float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)y / (float)x) * (float)((float)y / (float)x)) * 0.0028662258) - 0.016165737) * (float)((float)((float)y / (float)x) * (float)((float)y / (float)x))) + 0.042909615) * (float)v5) - 0.075289637)
                                                                                               * (float)v5)
                                                                                       + 0.10656264)
                                                                               * (float)v5)
                                                                       - 0.14208899)
                                                               * (float)v5)
                                                       + 0.19993551)
                                               * (float)v5)
                                       - 0.33333147)
                               * (float)v5)
                       + 1.0)
               * (float)((float)y / (float)x));
  }
  else
  {
    v2 = (float)((float)((float)x / (float)y) * (float)((float)x / (float)y));
    v3 = -(float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)((float)x / (float)y) * (float)((float)x / (float)y)) * 0.0028662258) - 0.016165737) * (float)v2) + 0.042909615) * (float)v2) - 0.075289637)
                                                                                                * (float)v2)
                                                                                        + 0.10656264)
                                                                                * (float)v2)
                                                                        - 0.14208899)
                                                                * (float)v2)
                                                        + 0.19993551)
                                                * (float)v2)
                                        - 0.33333147)
                                * (float)v2)
                        + 1.0)
                * (float)((float)x / (float)y));
    if ( (float)((float)x / (float)y) >= 0.0 )
      v4 = (float)(idMath::HALF_PI + (float)v3);
    else
      v4 = (float)((float)v3 - idMath::HALF_PI);
  }
  return *((float *)&v4 + 1);
}

