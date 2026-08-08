
// ========================================================================
// ?Apply@Quat@bfx@@QBA?AVVec3@2@ABV32@@Z
// EA  : 0x83264CF0
// RVA : 0x01264CF0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.h
// ========================================================================

bfx::Quat *__fastcall bfx::Quat::Apply(bfx::Quat *this, bfx::Quat *result, const bfx::Vec3 *v)
{
  double v3; // fp12
  double m_x; // fp7
  double v5; // fp10
  double m_w; // fp9
  double v7; // fp8
  double m_y; // fp6
  double m_z; // fp5
  bfx::Quat *v11; // r3
  double v12; // fp3
  double v14; // fp2
  bfx::Quat v15; // [sp+50h] [-50h] BYREF
  bfx::Quat v16; // [sp+60h] [-40h] BYREF
  bfx::Quat v17; // [sp+70h] [-30h] BYREF
  bfx::Quat v18; // [sp+80h] [-20h] BYREF

  v3 = -result->m_x;
  m_x = v->m_x;
  v5 = -result->m_y;
  m_w = result->m_w;
  v7 = -result->m_z;
  m_y = v->m_y;
  m_z = v->m_z;
  v15.m_w = 0.0;
  v16.m_x = v3;
  v16.m_y = v5;
  v16.m_w = m_w;
  v16.m_z = v7;
  v15.m_x = m_x;
  v15.m_y = m_y;
  v15.m_z = m_z;
  v11 = bfx::Quat::operator*(this: &v18, result, rhs: &v15);
  bfx::Quat::operator*(this: &v17, result: v11, rhs: &v16);
  v12 = v17.m_y;
  v14 = v17.m_z;
  this->m_w = v17.m_x;
  this->m_x = v12;
  this->m_y = v14;
  return this;
}


// ========================================================================
// ?InvalidFloatValues@bfx@@YA_NABVVector3@1@@Z
// EA  : 0x83287C58
// RVA : 0x01287C58
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.h
// ========================================================================

int __fastcall bfx::InvalidFloatValues(const bfx::Vector3 *val, long double a2)
{
  long double v3; // fp2
  long double v4; // fp2
  long double v5; // fp2
  long double v6; // fp2
  long double v7; // fp2
  int v8; // r3
  unsigned __int8 v9; // r11

  *(double *)&a2 = val->m_x;
  if ( isnan(x: a2) != 0 )
    return 1;
  *(double *)&v3 = val->m_y;
  if ( isnan(x: v3) != 0 )
    return 1;
  *(double *)&v4 = val->m_z;
  if ( isnan(x: v4) != 0 )
    return 1;
  *(double *)&v5 = val->m_x;
  if ( finite(x: v5) == 0 )
    return 1;
  *(double *)&v6 = val->m_y;
  if ( finite(x: v6) == 0 )
    return 1;
  *(double *)&v7 = val->m_z;
  v8 = finite(x: v7);
  v9 = 0;
  if ( v8 == 0 )
    return 1;
  return v9;
}


// ========================================================================
// ?InvalidFloatValues@bfx@@YA_NABVQuat@1@@Z
// EA  : 0x83287CF0
// RVA : 0x01287CF0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.h
// ========================================================================

int __fastcall bfx::InvalidFloatValues(const bfx::Quat *val, long double a2)
{
  long double v3; // fp2
  long double v4; // fp2
  long double v5; // fp2
  long double v6; // fp2
  long double v7; // fp2
  long double v8; // fp2
  long double v9; // fp2
  int v10; // r3
  unsigned __int8 v11; // r11

  *(double *)&a2 = val->m_w;
  if ( isnan(x: a2) != 0 )
    return 1;
  *(double *)&v3 = val->m_x;
  if ( isnan(x: v3) != 0 )
    return 1;
  *(double *)&v4 = val->m_y;
  if ( isnan(x: v4) != 0 )
    return 1;
  *(double *)&v5 = val->m_z;
  if ( isnan(x: v5) != 0 )
    return 1;
  *(double *)&v6 = val->m_w;
  if ( finite(x: v6) == 0 )
    return 1;
  *(double *)&v7 = val->m_x;
  if ( finite(x: v7) == 0 )
    return 1;
  *(double *)&v8 = val->m_y;
  if ( finite(x: v8) == 0 )
    return 1;
  *(double *)&v9 = val->m_z;
  v10 = finite(x: v9);
  v11 = 0;
  if ( v10 == 0 )
    return 1;
  return v11;
}


// ========================================================================
// ?Limit180@bfx@@YAMM@Z
// EA  : 0x832B1020
// RVA : 0x012B1020
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall bfx::Limit180(double angle)
{
  double v1; // fp31
  long double v2; // fp2
  long double v3; // fp2
  float result; // fp1

  v1 = (float)((float)angle * (float)0.15915494);
  *(double *)&v2 = v1;
  v3 = floor(x: v2);
  _FP9 = (float)((float)3.1415927 - (float)((float)((float)v1 - (float)*(double *)&v3) * (float)6.2831855));
  __asm { fsel      f1, f9, f10, f8 }
  LODWORD(result) = _FP1;
  return result;
}


// ========================================================================
// ?UnitVec@Vec2@bfx@@QBA?AV12@XZ
// EA  : 0x832BD880
// RVA : 0x012BD880
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.h
// ========================================================================

bfx::Vec2 *__fastcall bfx::Vec2::UnitVec(bfx::Vec2 *this, bfx::Vec2 *result)
{
  double v2; // fp13
  double m_y; // fp11

  v2 = __fsqrts((float)((float)(result->m_x * result->m_x) + (float)(result->m_y * result->m_y)));
  if ( v2 >= 1.0842022e-19 )
  {
    m_y = result->m_y;
    this->m_x = (float)((float)1.0 / (float)v2) * result->m_x;
    this->m_y = (float)((float)1.0 / (float)v2) * (float)m_y;
  }
  else
  {
    this->m_x = 0.0;
    this->m_y = 0.0;
  }
  return this;
}


// ========================================================================
// ?LimitMag@bfx@@YA?AVVec3@1@V21@M@Z
// EA  : 0x832CB5B8
// RVA : 0x012CB5B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.h
// ========================================================================

bfx::Vec3 *__fastcall bfx::LimitMag(__int64 vec, double limit)
{
  double v2; // fp11
  double v3; // fp11

  v2 = __fsqrts((float)((float)(*((float *)&vec + 1) * *((float *)&vec + 1))
                      + (float)((float)(*((float *)&vec + 1) * *((float *)&vec + 1))
                              + (float)(*(float *)&vec * *(float *)&vec))));
  if ( v2 <= limit )
  {
    *(_QWORD *)HIDWORD(vec) = vec;
    *(_DWORD *)(HIDWORD(vec) + 8) = vec;
  }
  else
  {
    v3 = (float)((float)limit / (float)v2);
    *(float *)HIDWORD(vec) = (float)v3 * *(float *)&vec;
    *(float *)(HIDWORD(vec) + 4) = *((float *)&vec + 1) * (float)v3;
    *(float *)(HIDWORD(vec) + 8) = (float)v3 * *((float *)&vec + 1);
  }
  return (bfx::Vec3 *)HIDWORD(vec);
}

