
// ========================================================================
// ??0Quat@bfx@@QAA@ABVVec3@1@M@Z
// EA  : 0x8326E1A0
// RVA : 0x0126E1A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::Quat *__fastcall bfx::Quat::Quat(bfx::Quat *this, const bfx::Vec3 *axis, double angle)
{
  double v5; // fp31
  long double v6; // fp2
  long double v7; // fp2
  double v8; // fp30
  long double v9; // fp2

  v5 = (float)((float)angle * (float)0.5);
  *(double *)&v6 = v5;
  v7 = cos(x: v6);
  v8 = (float)*(double *)&v7;
  *(double *)&v7 = v5;
  v9 = sin(x: v7);
  this->m_w = v8;
  this->m_x = axis->m_x * (float)*(double *)&v9;
  this->m_y = axis->m_y * (float)*(double *)&v9;
  this->m_z = axis->m_z * (float)*(double *)&v9;
  return this;
}


// ========================================================================
// ?Normalize@Quat@bfx@@QAAXXZ
// EA  : 0x8326E238
// RVA : 0x0126E238
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Quat::Normalize(bfx::Quat *this)
{
  double m_x; // fp13
  double m_y; // fp12
  double m_z; // fp11
  double v4; // fp10
  double v5; // fp10

  m_x = this->m_x;
  m_y = this->m_y;
  m_z = this->m_z;
  v4 = __fsqrts((float)((float)(this->m_z * this->m_z)
                      + (float)((float)(this->m_y * this->m_y)
                              + (float)((float)(this->m_w * this->m_w) + (float)(this->m_x * this->m_x)))));
  if ( v4 <= 0.0 )
  {
    *this = bfx::IDENTITY_QUAT;
  }
  else
  {
    v5 = (float)((float)1.0 / (float)v4);
    this->m_w = (float)v5 * this->m_w;
    this->m_x = (float)v5 * (float)m_x;
    this->m_y = (float)v5 * (float)m_y;
    this->m_z = (float)v5 * (float)m_z;
  }
}


// ========================================================================
// ??DQuat@bfx@@QBA?AV01@ABV01@@Z
// EA  : 0x8326E2C8
// RVA : 0x0126E2C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Quat *__fastcall bfx::Quat::operator*(bfx::Quat *this, bfx::Quat *result, const bfx::Quat *rhs)
{
  double m_w; // fp11
  double v4; // fp10
  double v5; // fp9
  double v6; // fp7
  double v7; // fp3
  double v8; // fp0
  double v9; // fp13

  m_w = rhs->m_w;
  v4 = result->m_w;
  v5 = (float)((float)(rhs->m_z * result->m_w) + (float)(rhs->m_w * result->m_z));
  v6 = (float)((float)(result->m_w * rhs->m_x) + (float)(rhs->m_w * result->m_x));
  v7 = (float)((float)(rhs->m_z * result->m_y) - (float)(rhs->m_y * result->m_z));
  v8 = (float)((float)(rhs->m_y * result->m_x) - (float)(result->m_y * rhs->m_x));
  v9 = (float)((float)(rhs->m_x * result->m_x)
             + (float)((float)(rhs->m_y * result->m_y) + (float)(rhs->m_z * result->m_z)));
  this->m_y = (float)((float)(rhs->m_y * result->m_w) + (float)(result->m_y * rhs->m_w))
            + (float)((float)(rhs->m_x * result->m_z) - (float)(rhs->m_z * result->m_x));
  this->m_x = (float)v6 + (float)v7;
  this->m_z = (float)v5 + (float)v8;
  this->m_w = (float)((float)v4 * (float)m_w) - (float)v9;
  return this;
}


// ========================================================================
// ?Init@Slerper@bfx@@QAAXABVQuat@2@0@Z
// EA  : 0x8326E378
// RVA : 0x0126E378
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Slerper::Init(bfx::Slerper *this, const bfx::Quat *_q1, const bfx::Quat *_q2, long double _FP2)
{
  double m_w; // fp0
  double m_z; // fp9
  double m_y; // fp11
  double m_x; // fp10
  double v9; // fp12
  double v10; // fp0
  long double v14; // fp2
  long double v15; // fp2

  m_w = _q1->m_w;
  this->m_q1.m_w = _q1->m_w;
  this->m_q1.m_x = _q1->m_x;
  this->m_q1.m_y = _q1->m_y;
  m_z = _q1->m_z;
  this->m_q1.m_z = _q1->m_z;
  m_y = _q2->m_y;
  m_x = _q2->m_x;
  v9 = _q2->m_z;
  v10 = (float)((float)(_q2->m_x * this->m_q1.m_x)
              + (float)((float)(_q2->m_w * (float)m_w)
                      + (float)((float)(this->m_q1.m_y * _q2->m_y) + (float)(_q2->m_z * (float)m_z))));
  if ( v10 >= 0.0 )
  {
    this->m_q2 = *_q2;
  }
  else
  {
    this->m_q2.m_w = -_q2->m_w;
    this->m_q2.m_x = -m_x;
    this->m_q2.m_y = -m_y;
    this->m_q2.m_z = -v9;
    v10 = -v10;
  }
  _FP12 = (float)((float)-1.0 - (float)v10);
  _FP11 = (float)((float)1.0 - (float)v10);
  __asm { fsel      f10, f12, f13, f0 }
  __asm { fsel      f1, f11, f9, f31# x }
  v14 = acos(x: _FP2);
  *(double *)&v14 = (float)*(double *)&v14;
  this->m_omega = *(double *)&v14;
  v15 = sin(x: v14);
  this->m_bLinear = false;
  if ( (float)*(double *)&v15 <= 1.0842022e-19 )
    this->m_bLinear = true;
  else
    this->m_oosinom = (float)1.0 / (float)*(double *)&v15;
}


// ========================================================================
// ?Slerp@Slerper@bfx@@QBA?AVQuat@2@M@Z
// EA  : 0x8326E4B8
// RVA : 0x0126E4B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::Slerper::Slerp(bfx::Slerper *this, bfx::Quat *result, double t)
{
  double v6; // fp4
  double v7; // fp2
  double v8; // fp1
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double v12; // fp10
  long double v13; // fp2
  long double v14; // fp2
  double v15; // fp11
  double v16; // fp31
  long double v17; // fp2
  double v18; // fp0
  double v19; // fp12
  double v20; // fp6
  double v21; // fp5
  double v22; // fp3

  if ( HIBYTE(result[2].m_y) != 0 )
  {
    v6 = (float)(result[1].m_x * (float)t);
    v7 = (float)(result[1].m_y * (float)t);
    v9 = (float)(result->m_x * (float)((float)1.0 - (float)t));
    v10 = (float)(result->m_y * (float)((float)1.0 - (float)t));
    v11 = (float)(result->m_z * (float)((float)1.0 - (float)t));
    v12 = (float)((float)((float)((float)1.0 - (float)t) * result->m_w) + (float)(result[1].m_w * (float)t));
    v8 = (float)(result[1].m_z * (float)t);
    this->m_q1.m_w = v12;
    this->m_q1.m_x = (float)v9 + (float)v6;
    this->m_q1.m_y = (float)v10 + (float)v7;
    this->m_q1.m_z = (float)v11 + (float)v8;
  }
  else
  {
    *(double *)&v13 = (float)((float)((float)1.0 - (float)t) * result[2].m_w);
    v14 = sin(x: v13);
    v15 = (float)*(double *)&v14;
    *(double *)&v14 = (float)(result[2].m_w * (float)t);
    v16 = (float)((float)v15 * result[2].m_x);
    v17 = sin(x: v14);
    *((double *)&v17 + 1) = (float)(result->m_x * (float)v16);
    v18 = (float)(result->m_y * (float)v16);
    v19 = (float)(result->m_z * (float)v16);
    v20 = (float)(result[1].m_x * (float)((float)*(double *)&v17 * result[2].m_x));
    v21 = (float)(result[1].m_y * (float)((float)*(double *)&v17 * result[2].m_x));
    v22 = (float)(result[1].m_z * (float)((float)*(double *)&v17 * result[2].m_x));
    this->m_q1.m_w = (float)(result->m_w * (float)v16)
                   + (float)(result[1].m_w * (float)((float)*(double *)&v17 * result[2].m_x));
    this->m_q1.m_x = (float)*((double *)&v17 + 1) + (float)v20;
    this->m_q1.m_y = (float)v18 + (float)v21;
    this->m_q1.m_z = (float)v19 + (float)v22;
  }
  bfx::Quat::Normalize(this: &this->m_q1);
}


// ========================================================================
// ?Build@Matrix@bfx@@QAAXABVQuat@2@ABVVec3@2@@Z
// EA  : 0x8326E610
// RVA : 0x0126E610
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Matrix::Build(bfx::Matrix *this, const bfx::Quat *q, const bfx::Vec3 *pos)
{
  double m_x; // fp12
  double m_y; // fp11
  double m_z; // fp10
  double m_w; // fp9
  double v7; // fp8
  double v8; // fp7
  double v9; // fp3
  double v10; // fp12

  m_x = q->m_x;
  m_y = q->m_y;
  m_z = q->m_z;
  m_w = q->m_w;
  v7 = (float)(q->m_z * (float)2.0);
  v8 = (float)(q->m_y * (float)2.0);
  this->m_data[3] = 0.0;
  this->m_data[7] = 0.0;
  this->m_data[11] = 0.0;
  v9 = (float)((float)((float)m_x * (float)2.0) * (float)m_x);
  this->m_data[1] = (float)((float)v7 * (float)m_w) + (float)((float)v8 * (float)m_x);
  this->m_data[4] = (float)((float)v8 * (float)m_x) - (float)((float)v7 * (float)m_w);
  this->m_data[2] = (float)((float)v7 * (float)m_x) - (float)((float)v8 * (float)m_w);
  this->m_data[8] = (float)((float)v8 * (float)m_w) + (float)((float)v7 * (float)m_x);
  v10 = (float)((float)((float)m_x * (float)2.0) * (float)m_w);
  this->m_data[6] = (float)v10 + (float)((float)v7 * (float)m_y);
  this->m_data[9] = (float)((float)v7 * (float)m_y) - (float)v10;
  this->m_data[0] = (float)1.0 - (float)((float)((float)v7 * (float)m_z) + (float)((float)v8 * (float)m_y));
  this->m_data[10] = (float)1.0 - (float)((float)((float)v8 * (float)m_y) + (float)v9);
  this->m_data[5] = (float)1.0 - (float)((float)((float)v7 * (float)m_z) + (float)v9);
  *(bfx::Vec3 *)&this->m_data[12] = *pos;
  this->m_data[15] = 1.0;
}


// ========================================================================
// ?Build@Matrix@bfx@@QAAXABVVec3@2@000@Z
// EA  : 0x8326E6E8
// RVA : 0x0126E6E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Matrix::Build(
        bfx::Matrix *this,
        const bfx::Vec3 *xAxis,
        const bfx::Vec3 *yAxis,
        const bfx::Vec3 *zAxis,
        const bfx::Vec3 *trans)
{
  this->m_data[0] = xAxis->m_x;
  this->m_data[1] = xAxis->m_y;
  this->m_data[2] = xAxis->m_z;
  this->m_data[3] = 0.0;
  *(bfx::Vec3 *)&this->m_data[4] = *yAxis;
  this->m_data[7] = 0.0;
  *(bfx::Vec3 *)&this->m_data[8] = *zAxis;
  this->m_data[11] = 0.0;
  *(bfx::Vec3 *)&this->m_data[12] = *trans;
  this->m_data[15] = 1.0;
}


// ========================================================================
// ?Trans@Matrix@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x8326E770
// RVA : 0x0126E770
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Matrix::Trans(bfx::Matrix *this, const bfx::Vec3 *offset)
{
  double v2; // fp11
  double v3; // fp8

  v2 = this->m_data[13];
  this->m_data[12] = offset->m_x + this->m_data[12];
  v3 = this->m_data[14];
  this->m_data[13] = offset->m_y + (float)v2;
  this->m_data[14] = offset->m_z + (float)v3;
}


// ========================================================================
// ?PreTrans@Matrix@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x8326E7A8
// RVA : 0x0126E7A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Matrix::PreTrans(bfx::Matrix *this, const bfx::Vec3 *offset)
{
  double v2; // fp6
  double v3; // fp5
  double v4; // fp4
  double v5; // fp3
  double v6; // fp2
  double v7; // fp0
  double v8; // fp13
  double v9; // fp12
  double v10; // fp11
  double v11; // fp10
  double v12; // fp31
  double v13; // fp30

  v2 = this->m_data[9];
  v3 = this->m_data[1];
  v4 = this->m_data[5];
  v5 = this->m_data[13];
  v6 = this->m_data[10];
  v7 = this->m_data[2];
  v8 = this->m_data[6];
  v9 = this->m_data[14];
  v10 = this->m_data[11];
  v11 = this->m_data[3];
  v12 = this->m_data[7];
  v13 = this->m_data[15];
  this->m_data[12] = (float)((float)(offset->m_x * this->m_data[0])
                           + (float)((float)(this->m_data[8] * offset->m_z) + (float)(this->m_data[4] * offset->m_y)))
                   + this->m_data[12];
  this->m_data[13] = (float)((float)((float)v4 * offset->m_y)
                           + (float)((float)((float)v3 * offset->m_x) + (float)((float)v2 * offset->m_z)))
                   + (float)v5;
  this->m_data[14] = (float)((float)((float)v8 * offset->m_y)
                           + (float)((float)((float)v7 * offset->m_x) + (float)((float)v6 * offset->m_z)))
                   + (float)v9;
  this->m_data[15] = (float)((float)((float)v12 * offset->m_y)
                           + (float)((float)((float)v11 * offset->m_x) + (float)((float)v10 * offset->m_z)))
                   + (float)v13;
}


// ========================================================================
// ??DMatrix@bfx@@QBA?AV01@ABV01@@Z
// EA  : 0x8326E880
// RVA : 0x0126E880
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Matrix *__fastcall bfx::Matrix::operator*(bfx::Matrix *this, bfx::Matrix *result, const bfx::Matrix *rhs)
{
  double v3; // fp12
  double v4; // fp11
  double v5; // fp9
  double v6; // fp5
  double v7; // fp7
  double v8; // fp27
  double v9; // fp24
  double v10; // fp25
  double v11; // fp21
  double v12; // fp2
  double v13; // fp20
  double v14; // fp13
  double v15; // fp19
  double v16; // fp18
  double v17; // fp15
  double v18; // fp8
  double v19; // fp6
  double v20; // fp3
  double v21; // fp14
  double v22; // fp4
  double v23; // fp29
  double v24; // fp1
  double v25; // fp30
  double v26; // fp31
  double v27; // fp17
  double v28; // fp0
  double v29; // fp23
  double v30; // fp28
  double v31; // fp16
  double v32; // fp26
  double v33; // fp8
  double v34; // fp10
  double v35; // fp4
  double v36; // fp6
  double v37; // fp3
  double v38; // fp12
  double v39; // fp4
  double v40; // fp7
  float v41; // [sp+0h] [-A0h]
  float v42; // [sp+4h] [-9Ch]

  v3 = result->m_data[4];
  v4 = result->m_data[5];
  v5 = result->m_data[6];
  v6 = result->m_data[7];
  v7 = rhs->m_data[9];
  v8 = result->m_data[2];
  v9 = result->m_data[3];
  v10 = rhs->m_data[8];
  v11 = result->m_data[8];
  v12 = result->m_data[9];
  v13 = result->m_data[10];
  v14 = result->m_data[11];
  v15 = rhs->m_data[10];
  v16 = rhs->m_data[3];
  v17 = result->m_data[12];
  v18 = (float)((float)(result->m_data[9] * rhs->m_data[2])
              + (float)((float)(result->m_data[1] * rhs->m_data[0]) + (float)(result->m_data[5] * rhs->m_data[1])));
  v42 = result->m_data[1];
  v19 = (float)((float)(result->m_data[10] * rhs->m_data[2])
              + (float)((float)(result->m_data[2] * rhs->m_data[0]) + (float)(result->m_data[6] * rhs->m_data[1])));
  v41 = result->m_data[0];
  v20 = (float)((float)(result->m_data[11] * rhs->m_data[2])
              + (float)((float)(result->m_data[3] * rhs->m_data[0]) + (float)(result->m_data[7] * rhs->m_data[1])));
  v21 = result->m_data[13];
  v22 = (float)((float)(rhs->m_data[6] * result->m_data[8])
              + (float)((float)(rhs->m_data[4] * v41) + (float)(rhs->m_data[5] * result->m_data[4])));
  v23 = result->m_data[14];
  v24 = (float)((float)(rhs->m_data[6] * result->m_data[9])
              + (float)((float)(rhs->m_data[4] * v42) + (float)(rhs->m_data[5] * result->m_data[5])));
  v25 = result->m_data[15];
  v26 = (float)((float)(rhs->m_data[6] * result->m_data[10])
              + (float)((float)(rhs->m_data[4] * result->m_data[2]) + (float)(rhs->m_data[5] * result->m_data[6])));
  v27 = rhs->m_data[7];
  v28 = (float)((float)(rhs->m_data[6] * result->m_data[11])
              + (float)((float)(rhs->m_data[4] * result->m_data[3]) + (float)(rhs->m_data[5] * result->m_data[7])));
  v29 = rhs->m_data[11];
  v30 = (float)((float)(rhs->m_data[10] * result->m_data[8])
              + (float)((float)(rhs->m_data[8] * v41) + (float)(rhs->m_data[9] * result->m_data[4])));
  v31 = (float)(rhs->m_data[9] * result->m_data[6]);
  v32 = (float)((float)(rhs->m_data[10] * result->m_data[9])
              + (float)((float)(rhs->m_data[8] * v42) + (float)(rhs->m_data[9] * result->m_data[5])));
  this->m_data[0] = (float)(rhs->m_data[3] * result->m_data[12])
                  + (float)((float)(rhs->m_data[2] * result->m_data[8])
                          + (float)((float)(v41 * rhs->m_data[0]) + (float)(result->m_data[4] * rhs->m_data[1])));
  this->m_data[1] = (float)((float)v21 * (float)v16) + (float)v18;
  this->m_data[2] = (float)((float)v23 * (float)v16) + (float)v19;
  this->m_data[3] = (float)((float)v25 * (float)v16) + (float)v20;
  this->m_data[4] = (float)((float)v27 * (float)v17) + (float)v22;
  this->m_data[5] = (float)((float)v27 * (float)v21) + (float)v24;
  this->m_data[6] = (float)((float)v27 * (float)v23) + (float)v26;
  this->m_data[7] = (float)((float)v27 * (float)v25) + (float)v28;
  this->m_data[8] = (float)((float)v29 * (float)v17) + (float)v30;
  v33 = (float)((float)v7 * (float)v6);
  v34 = rhs->m_data[13];
  v35 = (float)(rhs->m_data[13] * (float)v4);
  this->m_data[9] = (float)((float)v29 * (float)v21) + (float)v32;
  v36 = rhs->m_data[12];
  v37 = rhs->m_data[14];
  v39 = (float)((float)(rhs->m_data[12] * v42) + (float)v35);
  v40 = (float)((float)(rhs->m_data[12] * v41) + (float)((float)v34 * (float)v3));
  v38 = rhs->m_data[15];
  this->m_data[10] = (float)((float)v29 * (float)v23)
                   + (float)((float)((float)v15 * (float)v13) + (float)((float)((float)v10 * (float)v8) + (float)v31));
  this->m_data[11] = (float)((float)v29 * (float)v25)
                   + (float)((float)((float)v15 * (float)v14) + (float)((float)((float)v10 * (float)v9) + (float)v33));
  this->m_data[13] = (float)((float)v38 * (float)v21) + (float)((float)((float)v37 * (float)v12) + (float)v39);
  this->m_data[12] = (float)((float)v38 * (float)v17) + (float)((float)((float)v37 * (float)v11) + (float)v40);
  this->m_data[15] = (float)((float)v38 * (float)v25)
                   + (float)((float)((float)v37 * (float)v14)
                           + (float)((float)((float)v36 * (float)v9) + (float)((float)v34 * (float)v6)));
  this->m_data[14] = (float)((float)v38 * (float)v23)
                   + (float)((float)((float)v37 * (float)v13)
                           + (float)((float)((float)v36 * (float)v8) + (float)((float)v34 * (float)v5)));
  return this;
}


// ========================================================================
// ??DMatrix@bfx@@QBA?AVVec3@1@ABV21@@Z
// EA  : 0x8326EA78
// RVA : 0x0126EA78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Matrix *__fastcall bfx::Matrix::operator*(bfx::Matrix *this, bfx::Vec3 *result, const bfx::Vec3 *rhs)
{
  double m_y; // fp9
  double m_z; // fp5
  double v5; // fp2
  double v6; // fp1

  m_y = result[4].m_y;
  m_z = result[4].m_z;
  v5 = (float)((float)(result[3].m_x * rhs->m_z)
             + (float)((float)(result->m_y * rhs->m_x) + (float)(result[1].m_z * rhs->m_y)));
  v6 = (float)((float)(result[3].m_y * rhs->m_z)
             + (float)((float)(result->m_z * rhs->m_x) + (float)(result[2].m_x * rhs->m_y)));
  this->m_data[0] = (float)((float)(rhs->m_x * result->m_x)
                          + (float)((float)(result[1].m_y * rhs->m_y) + (float)(result[2].m_z * rhs->m_z)))
                  + result[4].m_x;
  this->m_data[1] = (float)v5 + (float)m_y;
  this->m_data[2] = (float)v6 + (float)m_z;
  return this;
}


// ========================================================================
// ?Rot@Matrix@bfx@@QBA?AVVec3@2@ABV32@@Z
// EA  : 0x8326EAF8
// RVA : 0x0126EAF8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Matrix *__fastcall bfx::Matrix::Rot(bfx::Matrix *this, bfx::Vec3 *result, const bfx::Vec3 *rhs)
{
  double m_z; // fp0
  double m_x; // fp1
  double m_y; // fp12
  double v6; // fp10
  double v7; // fp9

  m_z = rhs->m_z;
  m_x = result[3].m_x;
  m_y = result[3].m_y;
  v6 = (float)((float)(result->m_y * rhs->m_x) + (float)(result[1].m_z * rhs->m_y));
  v7 = (float)((float)(result->m_z * rhs->m_x) + (float)(result[2].m_x * rhs->m_y));
  this->m_data[0] = (float)(rhs->m_x * result->m_x)
                  + (float)((float)(result[1].m_y * rhs->m_y) + (float)(result[2].m_z * rhs->m_z));
  this->m_data[1] = (float)((float)m_x * (float)m_z) + (float)v6;
  this->m_data[2] = (float)((float)m_y * (float)m_z) + (float)v7;
  return this;
}


// ========================================================================
// ?GetDistPtToBoxSq@bfx@@YAMABVVec3@1@ABVBox@1@@Z
// EA  : 0x8326EB60
// RVA : 0x0126EB60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

float __fastcall bfx::GetDistPtToBoxSq(const bfx::Vec3 *pos, const bfx::Box *box)
{
  double v14; // fp4
  double v15; // fp3
  double v16; // fp1

  _FP12 = (float)(box->m_min.m_y - pos->m_y);
  _FP9 = (float)(box->m_min.m_z - pos->m_z);
  _FP5 = (float)(box->m_min.m_x - pos->m_x);
  __asm
  {
    fsel      f2, f12, f13, f0
    fsel      f1, f9, f10, f11
    fsel      f13, f5, f7, f8
  }
  _FP12 = (float)((float)_FP2 - box->m_max.m_y);
  _FP10 = (float)((float)_FP1 - box->m_max.m_z);
  _FP9 = (float)((float)_FP13 - box->m_max.m_x);
  __asm
  {
    fsel      f7, f12, f6, f2
    fsel      f6, f10, f4, f1
    fsel      f5, f9, f3, f13
  }
  v14 = (float)(pos->m_y - (float)_FP7);
  v15 = (float)(pos->m_z - (float)_FP6);
  v16 = (float)((float)((float)(pos->m_x - (float)_FP5) * (float)(pos->m_x - (float)_FP5))
              + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)));
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?GetDistPtToBox@bfx@@YAMABVVec3@1@ABVBox@1@@Z
// EA  : 0x8326EBD0
// RVA : 0x0126EBD0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

float __fastcall bfx::GetDistPtToBox(const bfx::Vec3 *pos, const bfx::Box *box)
{
  double v14; // fp4
  double v15; // fp3
  double v16; // fp1

  _FP12 = (float)(box->m_min.m_y - pos->m_y);
  _FP9 = (float)(box->m_min.m_z - pos->m_z);
  _FP5 = (float)(box->m_min.m_x - pos->m_x);
  __asm
  {
    fsel      f2, f12, f13, f0
    fsel      f1, f9, f10, f11
    fsel      f13, f5, f7, f8
  }
  _FP12 = (float)((float)_FP2 - box->m_max.m_y);
  _FP10 = (float)((float)_FP1 - box->m_max.m_z);
  _FP9 = (float)((float)_FP13 - box->m_max.m_x);
  __asm
  {
    fsel      f7, f12, f6, f2
    fsel      f6, f10, f4, f1
    fsel      f5, f9, f3, f13
  }
  v14 = (float)(pos->m_y - (float)_FP7);
  v15 = (float)(pos->m_z - (float)_FP6);
  v16 = __fsqrts((float)((float)((float)(pos->m_x - (float)_FP5) * (float)(pos->m_x - (float)_FP5))
                       + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))));
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?CalcRotTransBBox@bfx@@YA?AVBox@1@ABV21@ABVMatrix@1@@Z
// EA  : 0x8326EC48
// RVA : 0x0126EC48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Box *__fastcall bfx::CalcRotTransBBox(bfx::Box *result, const bfx::Box *boxIn, const bfx::Matrix *mat)
{
  unsigned int v3; // r9
  int v4; // ctr
  bfx::Vec3 *p_m_max; // r11
  const bfx::Box *v6; // r10
  double m_z; // fp13
  const bfx::Box *v8; // r10
  double m_y; // fp0
  const bfx::Box *v10; // r10
  double v11; // fp2
  double v12; // fp1
  double v13; // fp0
  double v14; // fp13
  double v15; // fp12
  double v16; // fp11

  v3 = 0;
  v4 = 8;
  p_m_max = &result->m_max;
  result->m_min = bfx::MAX_FLOAT_VEC;
  result->m_max = bfx::MIN_FLOAT_VEC;
  do
  {
    v6 = boxIn;
    if ( (v3 & 1) != 0 )
      v6 = (const bfx::Box *)&boxIn->m_max;
    m_z = v6->m_min.m_z;
    v8 = boxIn;
    if ( v3 >> 1 != 2 * (v3 >> 2) )
      v8 = (const bfx::Box *)&boxIn->m_max;
    m_y = v8->m_min.m_y;
    v10 = boxIn;
    if ( (v3 & 0xFFFFFFFC) != 0 )
      v10 = (const bfx::Box *)&boxIn->m_max;
    ++v3;
    v11 = (float)((float)(mat->m_data[0] * v10->m_min.m_x)
                + (float)((float)(mat->m_data[4] * (float)m_y) + (float)(mat->m_data[8] * (float)m_z)));
    v12 = (float)((float)((float)m_y * mat->m_data[5])
                + (float)((float)(mat->m_data[1] * v10->m_min.m_x) + (float)((float)m_z * mat->m_data[9])));
    v13 = (float)((float)(mat->m_data[6] * (float)m_y)
                + (float)((float)(mat->m_data[2] * v10->m_min.m_x) + (float)(mat->m_data[10] * (float)m_z)));
    v14 = (float)((float)v11 + mat->m_data[12]);
    v15 = (float)((float)v12 + mat->m_data[13]);
    v16 = (float)((float)v13 + mat->m_data[14]);
    _FP10 = (float)(result->m_min.m_x - (float)((float)v11 + mat->m_data[12]));
    _FP9 = (float)(result->m_min.m_y - (float)((float)v12 + mat->m_data[13]));
    _FP8 = (float)(result->m_min.m_z - (float)((float)v13 + mat->m_data[14]));
    __asm { fsel      f7, f10, f13, f3 }
    result->m_min.m_x = _FP7;
    __asm { fsel      f6, f9, f12, f4 }
    result->m_min.m_y = _FP6;
    __asm { fsel      f5, f8, f11, f5 }
    result->m_min.m_z = _FP5;
    _FP10 = (float)(p_m_max->m_x - (float)v14);
    _FP1 = (float)(result->m_max.m_y - (float)v15);
    _FP0 = (float)(result->m_max.m_z - (float)v16);
    __asm { fsel      f7, f10, f4, f13 }
    p_m_max->m_x = _FP7;
    __asm { fsel      f9, f1, f2, f12 }
    result->m_max.m_y = _FP9;
    __asm { fsel      f8, f0, f3, f11 }
    result->m_max.m_z = _FP8;
    --v4;
  }
  while ( v4 != 0 );
  return result;
}


// ========================================================================
// ?GetUpVec@bfx@@YA?AVVec3@1@W4UpAxis@1@@Z
// EA  : 0x8326EDC0
// RVA : 0x0126EDC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetUpVec(bfx::Vec3 *result, unsigned int upAxis)
{
  if ( upAxis > 5 )
    goto LABEL_12;
  switch ( upAxis )
  {
    case 1u:
      result->m_y = 1.0;
      result->m_z = 0.0;
      result->m_x = 0.0;
      return result;
    case 2u:
LABEL_12:
      result->m_z = 1.0;
      result->m_x = 0.0;
      result->m_y = 0.0;
      break;
    case 3u:
      result->m_x = -1.0;
      result->m_z = 0.0;
      result->m_y = 0.0;
      break;
    case 4u:
      result->m_x = 0.0;
      result->m_y = -1.0;
      result->m_z = 0.0;
      break;
    default:
      if ( upAxis != 0 )
      {
        result->m_y = 0.0;
        result->m_z = -1.0;
        result->m_x = 0.0;
      }
      else
      {
        result->m_x = 1.0;
        result->m_z = 0.0;
        result->m_y = 0.0;
      }
      break;
  }
  return result;
}


// ========================================================================
// ?GetUpComponent@bfx@@YAAAMAAVVec3@1@W4UpAxis@1@@Z
// EA  : 0x8326EEA8
// RVA : 0x0126EEA8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

float *__fastcall bfx::GetUpComponent(float *vec, unsigned int which)
{
  if ( which <= 4 )
  {
    if ( which == 0 )
      return vec;
    if ( which == 1 )
      return ++vec;
    if ( which != 2 )
    {
      if ( which == 3 )
        return vec;
      return ++vec;
    }
  }
  vec += 2;
  return vec;
}


// ========================================================================
// ?RandFloat@bfx@@YAMMM@Z
// EA  : 0x8326EED8
// RVA : 0x0126EED8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

float __fastcall bfx::RandFloat(double min, double max)
{
  double v2; // fp1

  v2 = (float)((float)((float)((float)__SPAIR64__(byte_821B0000, rand()) * (float)0.000030518509)
                     * (float)((float)max - (float)min))
             + (float)min);
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?CanStopInTime@bfx@@YA_NMMM@Z
// EA  : 0x8326EF38
// RVA : 0x0126EF38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

int __fastcall bfx::CanStopInTime(double x, double speed, double maxAccel)
{
  double v5; // fp13
  int result; // r3

  __asm { fsel      f12, f2, f0, f13 }
  __asm { fsel      f11, f1, f0, f13 }
  if ( (float)_FP12 == _FP11 && __fabs(speed) >= 1.0842022e-19 )
    return 0;
  v5 = __fabs(x);
  if ( v5 <= 1.0842022e-19 )
  {
    result = 0;
    if ( __fabs(speed) > 1.0842022e-19 )
      return result;
  }
  else if ( (float)((float)((float)speed * (float)speed) / (float)((float)v5 * (float)2.0)) >= maxAccel )
  {
    return 0;
  }
  return 1;
}


// ========================================================================
// ?CalcDecelViaBinarySearch@bfx@@YAMMMMMM@Z
// EA  : 0x8326EFC8
// RVA : 0x0126EFC8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

float __fastcall bfx::CalcDecelViaBinarySearch(
        double x,
        double speed,
        double maxAccel,
        double maxDecelThisFrame,
        double simTime)
{
  double v5; // fp11
  double v7; // fp13
  char v12; // r11
  double v13; // fp8
  char v18; // r11
  double v19; // fp8
  char v24; // r11
  double v25; // fp8
  double v26; // fp12
  char v31; // r11
  double v32; // fp13
  double v33; // fp1

  v5 = maxDecelThisFrame;
  __asm { fsel      f31, f1, f10, f9 }
  v7 = 0.0;
  _FP12 = (float)((float)((float)((float)((float)_FP31 * (float)maxDecelThisFrame) * (float)0.5) * (float)simTime)
                + (float)speed);
  _FP8 = (float)((float)((float)((float)((float)((float)((float)_FP31 * (float)maxDecelThisFrame) * (float)0.5)
                                       * (float)simTime)
                               + (float)speed)
                       * (float)simTime)
               + (float)x);
  __asm
  {
    fsel      f26, f12, f7, f6
    fsel      f25, f8, f10, f9
  }
  if ( (float)_FP26 == _FP25 && __fabs(_FP12) >= 1.0842022e-19 )
  {
    v12 = 0;
    goto LABEL_9;
  }
  v13 = __fabs(_FP8);
  if ( v13 <= 1.0842022e-19 )
  {
    v12 = 0;
    if ( __fabs(_FP12) > 1.0842022e-19 )
      goto LABEL_9;
  }
  else if ( (float)((float)((float)_FP12 * (float)_FP12) / (float)((float)v13 * (float)2.0)) >= (double)(float)((float)maxAccel * (float)0.80000001) )
  {
    v12 = 0;
    goto LABEL_9;
  }
  v12 = 1;
LABEL_9:
  if ( v12 != 0 )
    v5 = (float)((float)maxDecelThisFrame - (float)((float)maxDecelThisFrame * (float)0.5));
  else
    v7 = (float)((float)maxDecelThisFrame * (float)0.5);
  _FP12 = (float)((float)((float)((float)((float)((float)v7 + (float)v5) * (float)_FP31) * (float)0.5) * (float)simTime)
                + (float)speed);
  _FP8 = (float)((float)((float)((float)((float)((float)((float)((float)v7 + (float)v5) * (float)_FP31) * (float)0.5)
                                       * (float)simTime)
                               + (float)speed)
                       * (float)simTime)
               + (float)x);
  __asm
  {
    fsel      f30, f12, f7, f6
    fsel      f26, f8, f10, f9
  }
  if ( (float)_FP30 == _FP26 && __fabs(_FP12) >= 1.0842022e-19 )
  {
    v18 = 0;
    goto LABEL_20;
  }
  v19 = __fabs(_FP8);
  if ( v19 <= 1.0842022e-19 )
  {
    v18 = 0;
    if ( __fabs(_FP12) > 1.0842022e-19 )
      goto LABEL_20;
  }
  else if ( (float)((float)((float)_FP12 * (float)_FP12) / (float)((float)v19 * (float)2.0)) >= (double)(float)((float)maxAccel * (float)0.80000001) )
  {
    v18 = 0;
    goto LABEL_20;
  }
  v18 = 1;
LABEL_20:
  if ( v18 != 0 )
    v5 = (float)((float)v5 - (float)((float)((float)v5 - (float)v7) * (float)0.5));
  else
    v7 = (float)((float)((float)((float)v5 - (float)v7) * (float)0.5) + (float)v7);
  _FP12 = (float)((float)((float)((float)((float)((float)v7 + (float)v5) * (float)_FP31) * (float)0.5) * (float)simTime)
                + (float)speed);
  _FP8 = (float)((float)((float)((float)((float)((float)((float)((float)v7 + (float)v5) * (float)_FP31) * (float)0.5)
                                       * (float)simTime)
                               + (float)speed)
                       * (float)simTime)
               + (float)x);
  __asm
  {
    fsel      f30, f12, f7, f6
    fsel      f26, f8, f10, f9
  }
  if ( (float)_FP30 == _FP26 && __fabs(_FP12) >= 1.0842022e-19 )
  {
    v24 = 0;
    goto LABEL_31;
  }
  v25 = __fabs(_FP8);
  if ( v25 <= 1.0842022e-19 )
  {
    v24 = 0;
    if ( __fabs(_FP12) > 1.0842022e-19 )
      goto LABEL_31;
  }
  else if ( (float)((float)((float)_FP12 * (float)_FP12) / (float)((float)v25 * (float)2.0)) >= (double)(float)((float)maxAccel * (float)0.80000001) )
  {
    v24 = 0;
    goto LABEL_31;
  }
  v24 = 1;
LABEL_31:
  if ( v24 != 0 )
    v5 = (float)((float)v5 - (float)((float)((float)v5 - (float)v7) * (float)0.5));
  else
    v7 = (float)((float)((float)((float)v5 - (float)v7) * (float)0.5) + (float)v7);
  v26 = (float)((float)((float)v5 - (float)v7) * (float)0.5);
  _FP0 = (float)((float)((float)((float)((float)((float)v7 + (float)v5) * (float)_FP31) * (float)0.5) * (float)simTime)
               + (float)speed);
  __asm { fsel      f8, f0, f7, f6 }
  _FP13 = (float)((float)((float)((float)((float)((float)((float)((float)v7 + (float)v5) * (float)_FP31) * (float)0.5)
                                        * (float)simTime)
                                + (float)speed)
                        * (float)simTime)
                + (float)x);
  __asm { fsel      f7, f13, f10, f9 }
  if ( (float)_FP8 == _FP7 && __fabs(_FP0) >= 1.0842022e-19 )
  {
    v31 = 0;
    goto LABEL_42;
  }
  v32 = __fabs(_FP13);
  if ( v32 <= 1.0842022e-19 )
  {
    v31 = 0;
    if ( __fabs(_FP0) > 1.0842022e-19 )
      goto LABEL_42;
  }
  else if ( (float)((float)((float)_FP0 * (float)_FP0) / (float)((float)v32 * (float)2.0)) >= (double)(float)((float)maxAccel * (float)0.80000001) )
  {
    v31 = 0;
    goto LABEL_42;
  }
  v31 = 1;
LABEL_42:
  if ( v31 != 0 )
    v33 = (float)((float)_FP31 * (float)((float)v5 - (float)v26));
  else
    v33 = (float)((float)_FP31 * (float)v5);
  return *((float *)&v33 + 1);
}


// ========================================================================
// ?CalcAccel@bfx@@YAMMMMMM@Z
// EA  : 0x8326F2B8
// RVA : 0x0126F2B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

float __fastcall bfx::CalcAccel(double curX, double goalX, double speed, double maxAccel, double simTime)
{
  double v5; // fp9
  double v6; // fp8
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  float *v11; // r6
  double v12; // fp9
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  double v18; // fp7
  int v19; // r6
  double v20; // fp7
  double v21; // fp6
  double v23; // fp0
  double v25; // fp3
  double v27; // fp12

  if ( (unsigned __int8)bfx::CanStopInTime(
                          x: (float)((float)curX - (float)goalX),
                          speed,
                          maxAccel: (float)((float)maxAccel * (float)0.80000001)) != 0 )
  {
    if ( (unsigned __int8)bfx::CanStopInTime(
                            x: (float)((float)((float)v10 * (float)v7) + (float)v6),
                            speed: v10,
                            maxAccel: v9) != 0 )
    {
      __asm { fsel      f0, f8, f0, f13 }
      v18 = -(float)((float)_FP0 * (float)v15);
      while ( (unsigned __int8)bfx::CanStopInTime(
                                 x: (float)((float)((float)((float)((float)v18 * (float)v14) + (float)v12) * (float)v14)
                                       + (float)_FP8),
                                 speed: (float)((float)((float)v18 * (float)v14) + (float)v12),
                                 maxAccel: v16) == 0 )
      {
        v18 = (float)((float)v20 * (float)v21);
        if ( v19 + 1 >= 12 )
        {
          _FP1 = 0.0;
          return *((float *)&_FP1 + 1);
        }
      }
      _FP1 = v20;
    }
    else
    {
      if ( v14 <= v11[4] )
        v23 = *v11;
      else
        v23 = (float)((float)__fabs(v12) / (float)v14);
      _FP13 = (float)((float)v23 - (float)v15);
      v25 = v15;
      __asm { fsel      f4, f13, f4, f0# maxDecelThisFrame }
      _FP1 = bfx::CalcDecelViaBinarySearch(x: _FP8, speed: v12, maxAccel: v25, maxDecelThisFrame: _FP4, simTime: v14);
    }
  }
  else
  {
    v27 = -(float)((float)v5 / (float)v7);
    _FP11 = (float)((float)-v8 - (float)v27);
    _FP10 = (float)((float)v8 - (float)v27);
    __asm { fsel      f9, f11, f13, f12 }
    __asm { fsel      f1, f10, f8, f4 }
  }
  return *((float *)&_FP1 + 1);
}


// ========================================================================
// ?LimitDecelToPreventOvershoot@bfx@@YAMMMM@Z
// EA  : 0x8326F400
// RVA : 0x0126F400
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

float __fastcall bfx::LimitDecelToPreventOvershoot(double decel, double speed, double simTime)
{
  if ( simTime > 1.0842022e-19 && decel > (float)((float)speed / (float)simTime) )
    decel = (float)((float)speed / (float)simTime);
  return *((float *)&decel + 1);
}


// ========================================================================
// ??0Quat@bfx@@QAA@ABVMatrix@1@@Z
// EA  : 0x8326F428
// RVA : 0x0126F428
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Quat::Quat(bfx::Quat *this, const bfx::Matrix *m)
{
  double v2; // fp13
  double v3; // fp12
  double v4; // fp0
  double v5; // fp11
  double v6; // fp11
  double v7; // fp0
  double v8; // fp7
  double v9; // fp3
  double v10; // fp4
  double v11; // fp9
  double v12; // fp7

  v2 = m->m_data[5];
  v3 = m->m_data[10];
  v4 = (float)((float)(m->m_data[0] + m->m_data[5]) + m->m_data[10]);
  if ( v4 <= m->m_data[0] || v4 <= v2 || v4 <= v3 )
  {
    v6 = m->m_data[0];
    if ( v6 <= v2 || v6 <= v3 )
    {
      if ( v2 > v3 )
      {
        v11 = __fsqrts((float)((float)((float)(1.0 - (float)((float)(m->m_data[0] + m->m_data[5]) + m->m_data[10]))
                                     * 0.25)
                             + (float)(m->m_data[5] * (float)0.5)));
        this->m_y = v11;
        this->m_x = (float)(m->m_data[4] + m->m_data[1]) / (float)((float)v11 * (float)4.0);
        this->m_z = (float)(m->m_data[9] + m->m_data[6]) / (float)((float)v11 * (float)4.0);
        this->m_w = (float)(m->m_data[8] - m->m_data[2]) / (float)((float)v11 * (float)4.0);
        goto LABEL_12;
      }
      v7 = 4.0;
      v12 = __fsqrts((float)((float)((float)(1.0 - (float)((float)(m->m_data[0] + m->m_data[5]) + m->m_data[10])) * 0.25)
                           + (float)(m->m_data[10] * (float)0.5)));
      this->m_z = v12;
      v9 = v12;
      this->m_x = (float)(m->m_data[8] + m->m_data[2]) / (float)((float)v12 * (float)4.0);
      this->m_y = (float)(m->m_data[9] + m->m_data[6]) / (float)((float)v12 * (float)4.0);
      v10 = (float)(m->m_data[1] - m->m_data[4]);
    }
    else
    {
      v7 = 4.0;
      v8 = __fsqrts((float)((float)((float)((float)1.0 - (float)((float)(m->m_data[0] + m->m_data[5]) + m->m_data[10]))
                                  * (float)0.25)
                          + (float)(m->m_data[0] * (float)0.5)));
      this->m_x = v8;
      v9 = v8;
      this->m_y = (float)(m->m_data[4] + m->m_data[1]) / (float)((float)v8 * (float)4.0);
      this->m_z = (float)(m->m_data[8] + m->m_data[2]) / (float)((float)v8 * (float)4.0);
      v10 = (float)(m->m_data[6] - m->m_data[9]);
    }
    this->m_w = (float)v10 / (float)((float)v9 * (float)v7);
    goto LABEL_12;
  }
  v5 = __fsqrts((float)((float)((float)(m->m_data[0] + m->m_data[5]) + m->m_data[10]) + (float)1.0));
  this->m_w = (float)v5 * (float)0.5;
  this->m_x = (float)(m->m_data[6] - m->m_data[9]) / (float)((float)((float)v5 * (float)0.5) * (float)4.0);
  this->m_y = (float)(m->m_data[8] - m->m_data[2]) / (float)((float)((float)v5 * (float)0.5) * (float)4.0);
  this->m_z = (float)(m->m_data[1] - m->m_data[4]) / (float)((float)((float)v5 * (float)0.5) * (float)4.0);
LABEL_12:
  bfx::Quat::Normalize(this);
}


// ========================================================================
// ?OrthoInvert@Matrix@bfx@@QAAXXZ
// EA  : 0x8326F658
// RVA : 0x0126F658
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

void __fastcall bfx::Matrix::OrthoInvert(bfx::Matrix *this)
{
  double v1; // fp0
  double v2; // fp12
  double v3; // fp1
  double v4; // fp2
  double v5; // fp13
  double v6; // fp10
  double v7; // fp8

  v1 = this->m_data[1];
  this->m_data[1] = this->m_data[4];
  this->m_data[4] = v1;
  v2 = this->m_data[2];
  this->m_data[2] = this->m_data[8];
  this->m_data[8] = v2;
  v3 = this->m_data[6];
  this->m_data[6] = this->m_data[9];
  this->m_data[9] = v3;
  v4 = this->m_data[14];
  v5 = this->m_data[8];
  v6 = (float)-(float)((float)(this->m_data[13] * this->m_data[4]) - (float)-(float)(this->m_data[12] * this->m_data[0]));
  v7 = (float)-(float)((float)(this->m_data[5] * this->m_data[13]) - (float)-(float)(this->m_data[1] * this->m_data[12]));
  this->m_data[14] = -(float)((float)(this->m_data[10] * this->m_data[14])
                            - (float)-(float)((float)(this->m_data[6] * this->m_data[13])
                                            - (float)-(float)(this->m_data[2] * this->m_data[12])));
  this->m_data[12] = -(float)((float)((float)v5 * (float)v4) - (float)v6);
  this->m_data[13] = -(float)((float)((float)v4 * (float)v3) - (float)v7);
}


// ========================================================================
// ?GetUpMatrix@bfx@@YA?AVMatrix@1@W4UpAxis@1@@Z
// EA  : 0x8326F6F8
// RVA : 0x0126F6F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Matrix *__fastcall bfx::GetUpMatrix(bfx::Matrix *result, unsigned int upAxis)
{
  if ( upAxis > 5 )
  {
    *result = bfx::IDENTITY;
  }
  else
  {
    switch ( upAxis )
    {
      case 1u:
        result->m_data[0] = 0.0;
        result->m_data[1] = 0.0;
        result->m_data[2] = 1.0;
        result->m_data[3] = 0.0;
        result->m_data[4] = 1.0;
        result->m_data[5] = 0.0;
        result->m_data[6] = 0.0;
        result->m_data[7] = 0.0;
        result->m_data[8] = 0.0;
        result->m_data[9] = 1.0;
        result->m_data[10] = 0.0;
        result->m_data[11] = 0.0;
        result->m_data[12] = 0.0;
        result->m_data[13] = 0.0;
        result->m_data[14] = 0.0;
        result->m_data[15] = 1.0;
        break;
      case 2u:
        result->m_data[0] = 1.0;
        result->m_data[1] = 0.0;
        result->m_data[2] = 0.0;
        result->m_data[3] = 0.0;
        result->m_data[4] = 0.0;
        result->m_data[5] = 1.0;
        result->m_data[6] = 0.0;
        result->m_data[7] = 0.0;
        result->m_data[8] = 0.0;
        result->m_data[9] = 0.0;
        result->m_data[10] = 1.0;
        result->m_data[11] = 0.0;
        result->m_data[12] = 0.0;
        result->m_data[13] = 0.0;
        result->m_data[14] = 0.0;
        result->m_data[15] = 1.0;
        break;
      case 3u:
        result->m_data[0] = 0.0;
        result->m_data[1] = 0.0;
        result->m_data[2] = 1.0;
        result->m_data[3] = 0.0;
        result->m_data[4] = 0.0;
        result->m_data[5] = 1.0;
        result->m_data[6] = 0.0;
        result->m_data[7] = 0.0;
        result->m_data[8] = -1.0;
        result->m_data[9] = -0.0;
        result->m_data[10] = -0.0;
        result->m_data[11] = 0.0;
        result->m_data[12] = 0.0;
        result->m_data[13] = 0.0;
        result->m_data[14] = 0.0;
        result->m_data[15] = 1.0;
        break;
      case 4u:
        result->m_data[0] = 1.0;
        result->m_data[1] = 0.0;
        result->m_data[2] = 0.0;
        result->m_data[3] = 0.0;
        result->m_data[4] = 0.0;
        result->m_data[5] = 0.0;
        result->m_data[6] = 1.0;
        result->m_data[7] = 0.0;
        result->m_data[8] = -0.0;
        result->m_data[9] = -1.0;
        result->m_data[10] = -0.0;
        result->m_data[11] = 0.0;
        result->m_data[12] = 0.0;
        result->m_data[13] = 0.0;
        result->m_data[14] = 0.0;
        result->m_data[15] = 1.0;
        break;
      default:
        result->m_data[0] = 0.0;
        result->m_data[1] = 1.0;
        result->m_data[2] = 0.0;
        result->m_data[3] = 0.0;
        if ( upAxis != 0 )
        {
          result->m_data[4] = 1.0;
          result->m_data[5] = 0.0;
          result->m_data[6] = 0.0;
          result->m_data[7] = 0.0;
          result->m_data[8] = -0.0;
          result->m_data[9] = -0.0;
          result->m_data[10] = -1.0;
        }
        else
        {
          result->m_data[4] = 0.0;
          result->m_data[5] = 0.0;
          result->m_data[6] = 1.0;
          result->m_data[7] = 0.0;
          result->m_data[8] = 1.0;
          result->m_data[9] = 0.0;
          result->m_data[10] = 0.0;
        }
        result->m_data[11] = 0.0;
        result->m_data[12] = 0.0;
        result->m_data[13] = 0.0;
        result->m_data[14] = 0.0;
        result->m_data[15] = 1.0;
        break;
    }
  }
  return result;
}


// ========================================================================
// ?BuildMatAroundAxis@bfx@@YA?AVMatrix@1@ABVVec3@1@0@Z
// EA  : 0x8326F988
// RVA : 0x0126F988
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmath.cpp
// ========================================================================

bfx::Matrix *__fastcall bfx::BuildMatAroundAxis(bfx::Matrix *result, const bfx::Vec3 *zaxis, const bfx::Vec3 *pos)
{
  double v5; // fp13
  double v6; // fp12
  double v7; // fp11
  double v8; // fp9
  double v9; // fp8
  double v10; // fp6
  double v11; // fp5
  double v12; // fp4

  _FP3 = (float)((float)__fsqrts((float)((float)(zaxis->m_z * zaxis->m_z)
                                       + (float)((float)(zaxis->m_x * zaxis->m_x) + (float)(zaxis->m_y * zaxis->m_y))))
               - (float)1.0842022e-19);
  __asm { fsel      f1, f3, f2, f0 }
  v5 = (float)(zaxis->m_x * (float)_FP1);
  v6 = (float)((float)_FP1 * zaxis->m_y);
  v7 = (float)((float)_FP1 * zaxis->m_z);
  if ( __fabs(v5) <= __fabs(v6) )
  {
    v8 = 1.0;
    v9 = 0.0;
  }
  else
  {
    v8 = 0.0;
    v9 = 1.0;
  }
  *(bfx::Vec3 *)&result->m_data[12] = *pos;
  result->m_data[3] = 0.0;
  result->m_data[7] = 0.0;
  result->m_data[11] = 0.0;
  result->m_data[15] = 1.0;
  v10 = (float)((float)((float)v6 * (float)0.0) - (float)((float)v9 * (float)v7));
  result->m_data[8] = v5;
  v11 = (float)((float)((float)v9 * (float)v5) - (float)((float)v8 * (float)v6));
  result->m_data[9] = v6;
  v12 = (float)((float)((float)v7 * (float)v8) - (float)((float)v5 * (float)0.0));
  result->m_data[10] = v7;
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v12 * (float)v12)
                                       + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))))
               - (float)1.0842022e-19);
  __asm { fsel      f3, f8, f7, f0 }
  result->m_data[0] = (float)v10 * (float)_FP3;
  result->m_data[2] = (float)v11 * (float)_FP3;
  result->m_data[1] = (float)_FP3 * (float)((float)((float)v7 * (float)v8) - (float)((float)v5 * (float)0.0));
  result->m_data[6] = (float)((float)((float)_FP3
                                    * (float)((float)((float)v7 * (float)v8) - (float)((float)v5 * (float)0.0)))
                            * (float)v5)
                    - (float)((float)((float)v10 * (float)_FP3) * (float)v6);
  result->m_data[5] = (float)((float)((float)v10 * (float)_FP3) * (float)v7)
                    - (float)((float)((float)v11 * (float)_FP3) * (float)v5);
  result->m_data[4] = (float)((float)((float)v11 * (float)_FP3) * (float)v6)
                    - (float)((float)((float)_FP3
                                    * (float)((float)((float)v7 * (float)v8) - (float)((float)v5 * (float)0.0)))
                            * (float)v7);
  return result;
}

