
// ========================================================================
// ?FaceStrictlyInTravelDir@Orienter@bfx@@QAAXXZ
// EA  : 0x832B1080
// RVA : 0x012B1080
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::FaceStrictlyInTravelDir(bfx::Orienter *this)
{
  this->m_state = FACE_STRICTLY_IN_TRAVEL_DIR;
}


// ========================================================================
// ?FaceTarget@Orienter@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B1090
// RVA : 0x012B1090
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::FaceTarget(bfx::Orienter *this, const bfx::Vec3 *targetPos)
{
  this->m_state = FACE_TARGET;
  this->m_targetPos = *targetPos;
  this->m_accelMode = HIGH_ACCEL_MODE;
}


// ========================================================================
// ?FaceInDir@Orienter@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B10C0
// RVA : 0x012B10C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::FaceInDir(bfx::Orienter *this, const bfx::Vec3 *dir)
{
  this->m_state = FACE_IN_DIR;
  this->m_dir = *dir;
  this->m_accelMode = HIGH_ACCEL_MODE;
}


// ========================================================================
// ?GetForward@Orienter@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x832B10F0
// RVA : 0x012B10F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

bfx::Orienter *__fastcall bfx::Orienter::GetForward(bfx::Orienter *this, bfx::Vec3 *result, long double a3)
{
  double m_z; // fp31
  double m_x; // fp30
  double m_y; // fp29
  long double v8; // fp2
  double v9; // fp28
  double v10; // fp27
  double v11; // fp26
  double v12; // fp31
  double v13; // fp30
  double v14; // fp29
  long double v15; // fp2

  *(double *)&a3 = result[1].m_x;
  m_z = result[3].m_z;
  m_x = result[4].m_x;
  m_y = result[4].m_y;
  v8 = sin(x: a3);
  v9 = result[2].m_y;
  v10 = result[2].m_z;
  v11 = result[3].m_x;
  v12 = (float)((float)m_z * (float)*(double *)&v8);
  v13 = (float)((float)m_x * (float)*(double *)&v8);
  v14 = (float)((float)m_y * (float)*(double *)&v8);
  *(double *)&v8 = result[1].m_x;
  v15 = cos(x: v8);
  *(float *)&this->m_pSpace = (float)((float)v9 * (float)*(double *)&v15) + (float)v12;
  *(float *)&this->m_pTune = (float)((float)v10 * (float)*(double *)&v15) + (float)v13;
  *(float *)&this->m_state = (float)((float)v11 * (float)*(double *)&v15) + (float)v14;
  return this;
}


// ========================================================================
// ?CalcMat@Orienter@bfx@@QBAXABVVec3@2@AAVMatrix@2@@Z
// EA  : 0x832B1198
// RVA : 0x012B1198
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::CalcMat(bfx::Orienter *this, const bfx::Vec3 *pos, bfx::Matrix *mat)
{
  *mat = this->m_curRot;
  *(bfx::Vec3 *)&mat->m_data[12] = *pos;
}


// ========================================================================
// ?ShouldBeVertical@bfx@@YA_NABVVec3@1@_NPBUMoverTune@1@@Z
// EA  : 0x832B11F8
// RVA : 0x012B11F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

BOOL __fastcall bfx::ShouldBeVertical(const bfx::Vec3 *areaNormal, bool areaIsFull3D, const bfx::MoverTune *pTune)
{
  long double v6; // fp2
  long double v7; // fp2
  bfx::Vec3 v8; // [sp+50h] [-30h] BYREF

  if ( pTune->m_surfaceOrientTune.m_alwaysVerticalOnAutoGen && !areaIsFull3D )
    return true;
  bfx::GetUpVec(result: &v8);
  *(double *)&v6 = (float)(pTune->m_surfaceOrientTune.m_surfaceOrientThreshold * (float)0.017453292);
  v7 = cos(x: v6);
  return (float)((float)(areaNormal->m_x * v8.m_x)
               + (float)((float)(areaNormal->m_z * v8.m_z) + (float)(areaNormal->m_y * v8.m_y))) > (double)(float)*(double *)&v7;
}


// ========================================================================
// ?GetUpAxisForStandingOnArea@bfx@@YA?AVVec3@1@PBVArea@1@PBUMoverTune@1@@Z
// EA  : 0x832B12A0
// RVA : 0x012B12A0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetUpAxisForStandingOnArea(bfx::Vec3 *result, bfx::Vec3 *pArea, const bfx::MoverTune *pTune)
{
  unsigned int v5; // r28
  const bfx::Vec3 *v6; // r30
  bfx::Vec3 *v7; // r3
  bool v8; // zf
  bfx::Area v9; // [sp+50h] [-40h] BYREF

  v5 = LODWORD(pArea[4].m_x) >> 31;
  v6 = (const bfx::Vec3 *)bfx::Area::CalcNormal(this: &v9, result: pArea);
  v8 = !bfx::ShouldBeVertical(areaNormal: v6, areaIsFull3D: v5, pTune);
  v7 = result;
  if ( v8 )
  {
    result->m_x = v6->m_x;
    result->m_y = v6->m_y;
    result->m_z = v6->m_z;
  }
  else
  {
    bfx::GetUpVec(result);
    return result;
  }
  return v7;
}


// ========================================================================
// ?GetLocalUpAxis@Orienter@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x832B1318
// RVA : 0x012B1318
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

bfx::Orienter *__fastcall bfx::Orienter::GetLocalUpAxis(bfx::Orienter *this, bfx::Vec3 *result)
{
  double m_y; // fp13
  double m_z; // fp12
  float v5; // r5
  char v6; // r4
  bfx::Orienter *v7; // r3
  bool v8; // zf
  float v9; // r10
  float v10; // r9
  bfx::Vec3 v11; // [sp+50h] [-20h] BYREF

  m_y = result[5].m_y;
  m_z = result[5].m_z;
  v5 = result->m_y;
  v11.m_x = result[5].m_x;
  v6 = BYTE1(result[11].m_z);
  v11.m_y = m_y;
  v11.m_z = m_z;
  v8 = !bfx::ShouldBeVertical(areaNormal: &v11, areaIsFull3D: v6, pTune: (const bfx::MoverTune *)LODWORD(v5));
  v7 = this;
  if ( v8 )
  {
    v9 = v11.m_y;
    v10 = v11.m_z;
    this->m_pSpace = (bfx::Space *)LODWORD(v11.m_x);
    *(float *)&this->m_pTune = v9;
    *(float *)&this->m_state = v10;
  }
  else
  {
    bfx::GetUpVec(result: (bfx::Vec3 *)this);
    return this;
  }
  return v7;
}


// ========================================================================
// ?GetRotVel@Orienter@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x832B13B0
// RVA : 0x012B13B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

bfx::Orienter *__fastcall bfx::Orienter::GetRotVel(bfx::Orienter *this, bfx::Vec3 *result)
{
  double m_y; // fp31
  float *LocalUpAxis; // r3
  double v5; // fp10
  double v6; // fp9
  char v8; // [sp+50h] [-30h] BYREF

  m_y = result[1].m_y;
  LocalUpAxis = (float *)bfx::Orienter::GetLocalUpAxis(this: (bfx::Orienter *)&v8, result);
  v5 = (float)(LocalUpAxis[1] * (float)m_y);
  v6 = (float)(LocalUpAxis[2] * (float)m_y);
  *(float *)&this->m_pSpace = *LocalUpAxis * (float)m_y;
  *(float *)&this->m_pTune = v5;
  *(float *)&this->m_state = v6;
  return this;
}


// ========================================================================
// ?GetDesiredFacingVec@bfx@@YA?AVVec3@1@ABVOrientCmd@1@ABV21@1@Z
// EA  : 0x832B1418
// RVA : 0x012B1418
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetDesiredFacingVec(
        bfx::Vec3 *result,
        const bfx::OrientCmd *orientCmd,
        const bfx::Vec3 *pos,
        const bfx::Vec3 *nextCornerG)
{
  bfx::OrientMode m_mode; // r11
  double v5; // fp11
  double v6; // fp8
  double v7; // fp5
  double v10; // fp10
  double m_z; // fp7
  double m_y; // fp8
  float v15; // r8
  float v16; // r7

  m_mode = orientCmd->m_mode;
  if ( orientCmd->m_mode == ORIENT_IN_TRAVEL_DIR || m_mode == ORIENT_STRICTLY_IN_TRAVEL_DIR )
  {
    v5 = (float)(nextCornerG->m_y - pos->m_y);
    v6 = (float)(nextCornerG->m_z - pos->m_z);
    _FP0 = (float)((float)__fsqrts((float)((float)((float)(nextCornerG->m_x - pos->m_x)
                                                 * (float)(nextCornerG->m_x - pos->m_x))
                                         + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))))
                 - (float)1.0842022e-19);
    __asm { fsel      f12, f0, f13, f12 }
    v10 = (float)((float)(nextCornerG->m_x - pos->m_x) * (float)_FP12);
    goto LABEL_9;
  }
  if ( m_mode == ORIENT_TARGET )
  {
    v5 = (float)(orientCmd->m_vec.m_y - pos->m_y);
    v6 = (float)(orientCmd->m_vec.m_z - pos->m_z);
    v7 = (float)(orientCmd->m_vec.m_x - pos->m_x);
    _FP0 = (float)((float)__fsqrts((float)((float)((float)v7 * (float)v7)
                                         + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))))
                 - (float)1.0842022e-19);
    __asm { fsel      f12, f0, f13, f12 }
    v10 = (float)((float)_FP12 * (float)(orientCmd->m_vec.m_x - pos->m_x));
LABEL_9:
    result->m_z = (float)v6 * (float)_FP12;
    result->m_y = (float)v5 * (float)_FP12;
    result->m_x = v10;
    return result;
  }
  if ( m_mode == ORIENT_IN_DIR )
  {
    m_z = orientCmd->m_vec.m_z;
    m_y = orientCmd->m_vec.m_y;
    _FP3 = (float)((float)__fsqrts((float)((float)(orientCmd->m_vec.m_x * orientCmd->m_vec.m_x)
                                         + (float)((float)(orientCmd->m_vec.m_y * orientCmd->m_vec.m_y)
                                                 + (float)(orientCmd->m_vec.m_z * orientCmd->m_vec.m_z))))
                 - (float)1.0842022e-19);
    __asm { fsel      f1, f3, f2, f12 }
    result->m_x = orientCmd->m_vec.m_x * (float)_FP1;
    result->m_y = (float)_FP1 * (float)m_y;
    result->m_z = (float)_FP1 * (float)m_z;
  }
  else
  {
    v15 = bfx::ZERO_VEC.m_y;
    v16 = bfx::ZERO_VEC.m_z;
    result->m_x = bfx::ZERO_VEC.m_x;
    result->m_y = v15;
    result->m_z = v16;
  }
  return result;
}


// ========================================================================
// ?GetDesiredFacingVec@Orienter@bfx@@QBA?AVVec3@2@ABV32@00@Z
// EA  : 0x832B15A0
// RVA : 0x012B15A0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

bfx::Orienter *__fastcall bfx::Orienter::GetDesiredFacingVec(
        bfx::Orienter *this,
        bfx::Vec3 *result,
        const bfx::Vec3 *pos,
        const bfx::Vec3 *vel,
        const bfx::Vec3 *nextCornerG,
        long double a6,
        long double a7)
{
  float m_z; // r11
  bfx::Orienter *v8; // r29
  float m_y; // r11
  double v14; // fp28
  double v15; // fp24
  double v16; // fp23
  double v17; // fp22
  double m_x; // fp21
  double v19; // fp20
  double v20; // fp27
  double v21; // fp25
  double v22; // fp26
  long double v23; // fp2
  long double v24; // fp2
  double v25; // fp19
  double v26; // fp31
  long double v27; // fp4
  double v28; // fp30
  double v29; // fp29
  long double v30; // fp2
  double v31; // fp1
  double v32; // fp0
  double v33; // fp28
  char v34; // r11
  double v35; // fp6
  double v38; // fp28
  double v41; // fp8
  double v42; // fp6
  bool v43; // r31
  double v44; // fp4
  double v45; // fp3
  double v48; // fp31
  double v49; // fp30
  double v50; // fp29
  float v51; // r10
  float v52; // r9
  double v53; // fp0
  double v54; // fp10
  double v57; // fp11
  double v58; // fp8
  double v59; // fp5
  bfx::Space *v63; // [sp+50h] [-C0h] BYREF
  float v64; // [sp+54h] [-BCh]
  float v65; // [sp+58h] [-B8h]
  float v66; // [sp+60h] [-B0h]
  float v67; // [sp+64h] [-ACh]
  float v68; // [sp+68h] [-A8h]

  m_z = result->m_z;
  v8 = this;
  if ( m_z == 0.0 )
  {
    m_y = result->m_y;
    v14 = result[2].m_y;
    v15 = result[4].m_y;
    v16 = result[2].m_z;
    v17 = result[3].m_z;
    m_x = result[3].m_x;
    v19 = result[4].m_x;
    v20 = *(float *)LODWORD(m_y);
    v21 = *(float *)(LODWORD(m_y) + 240);
    v22 = *(float *)(LODWORD(m_y) + 56);
    *((double *)&v23 + 1) = (float)((float)(vel->m_z * result[3].m_x)
                                  + (float)((float)(vel->m_y * result[2].m_z) + (float)(vel->m_x * result[2].m_y)));
    *(double *)&v23 = (float)((float)(vel->m_y * result[4].m_x)
                            + (float)((float)(vel->m_x * result[3].m_z) + (float)(vel->m_z * result[4].m_y)));
    v24 = atan2(v: v23, u: a7);
    v25 = (float)*(double *)&v24;
    v26 = (float)(nextCornerG->m_y - pos->m_y);
    *((double *)&v27 + 1) = pos->m_z;
    v28 = (float)(nextCornerG->m_z - pos->m_z);
    *(double *)&v27 = nextCornerG->m_x;
    v29 = (float)(nextCornerG->m_x - pos->m_x);
    *((double *)&v24 + 1) = (float)((float)((float)(nextCornerG->m_x - pos->m_x) * (float)v14)
                                  + (float)((float)((float)(nextCornerG->m_z - pos->m_z) * (float)m_x)
                                          + (float)((float)(nextCornerG->m_y - pos->m_y) * (float)v16)));
    *(double *)&v24 = (float)((float)((float)(nextCornerG->m_x - pos->m_x) * (float)v17)
                            + (float)((float)((float)(nextCornerG->m_z - pos->m_z) * (float)v15)
                                    + (float)((float)(nextCornerG->m_y - pos->m_y) * (float)v19)));
    v30 = atan2(v: v24, u: v27);
    v31 = bfx::Limit180(angle: (float)((float)v25 - (float)*(double *)&v30));
    v32 = vel->m_x;
    v33 = __fsqrts((float)((float)((float)(vel->m_y * vel->m_y) + (float)(vel->m_z * vel->m_z))
                         + (float)(vel->m_x * vel->m_x)));
    if ( *(_BYTE *)(LODWORD(result->m_y) + 212) == 0 )
    {
      v34 = 1;
      if ( v33 < (float)((float)v20 * (float)0.0099999998) || v33 < 0.0009765625 )
        v34 = 0;
      if ( __fabs(v31) > 0.78539819 && v33 < (float)((float)v21 * (float)v20) )
        v34 = 0;
      if ( __fabs(v31) > 2.6179938 && v33 < (float)((float)v22 * (float)v20) )
        v34 = 0;
      if ( v34 != 0 )
      {
        v35 = vel->m_y;
        _FP2 = (float)((float)__fsqrts((float)((float)((float)(vel->m_y * vel->m_y) + (float)(vel->m_z * vel->m_z))
                                             + (float)(vel->m_x * vel->m_x)))
                     - 1.0842022e-19);
        __asm { fsel      f13, f2, f1, f10 }
        *(float *)&v8->m_state = vel->m_z * (float)_FP13;
        *(float *)&v8->m_pTune = (float)v35 * (float)_FP13;
        *(float *)&v8->m_pSpace = (float)v32 * (float)_FP13;
        return v8;
      }
      v38 = (float)((float)((float)v29 * (float)v29)
                  + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26)));
      *(double *)&a6 = bfx::GetScale();
      this = v8;
      if ( __fsqrts(v38) >= (float)((float)*(double *)&a6 * (float)0.050000001) )
      {
        _FP10 = (float)((float)__fsqrts(v38) - 1.0842022e-19);
        __asm { fsel      f8, f10, f9, f12 }
        *(float *)&v8->m_pSpace = (float)_FP8 * (float)v29;
        *(float *)&v8->m_pTune = (float)v26 * (float)_FP8;
        *(float *)&v8->m_state = (float)v28 * (float)_FP8;
        return this;
      }
LABEL_15:
      bfx::Orienter::GetForward(this, result, a3: a6);
      return v8;
    }
    v41 = vel->m_y;
    v42 = vel->m_z;
    v44 = (float)((float)((float)(vel->m_y * vel->m_y) + (float)(vel->m_z * vel->m_z)) + (float)(vel->m_x * vel->m_x));
    v43 = true;
    v45 = __fsqrts(v44);
    *((double *)&_FP2 + 1) = (float)((float)v45 - (float)1.0842022e-19);
    *(double *)&_FP2 = (float)((float)1.0 / (float)v45);
    __asm { fsel      f13, f2, f1, f10 }
    v48 = (float)((float)v32 * (float)_FP13);
    v66 = (float)v32 * (float)_FP13;
    v49 = (float)((float)v41 * (float)_FP13);
    v67 = (float)v41 * (float)_FP13;
    v50 = (float)((float)v42 * (float)_FP13);
    v68 = (float)v42 * (float)_FP13;
    bfx::Orienter::GetForward(this: (bfx::Orienter *)&v63, result, a3: _FP2);
    if ( (float)((float)((float)v48 * *(float *)&v63) + (float)((float)(v65 * (float)v50) + (float)(v64 * (float)v49))) <= 0.98479998 )
      v43 = v33 >= (float)((float)v21 * (float)v20);
    this = v8;
    if ( v43 )
    {
      v51 = v67;
      v52 = v68;
      *(float *)&v8->m_pSpace = v66;
    }
    else
    {
      v51 = v64;
      v52 = v65;
      v8->m_pSpace = v63;
    }
    *(float *)&v8->m_pTune = v51;
    *(float *)&v8->m_state = v52;
  }
  else
  {
    switch ( LODWORD(m_z) )
    {
      case 1:
        v53 = vel->m_x;
        v54 = vel->m_y;
        if ( (float)((float)((float)(vel->m_y * vel->m_y) + (float)(vel->m_z * vel->m_z)) + (float)(vel->m_x * vel->m_x)) >= 0.0009765625 )
        {
          _FP2 = (float)((float)__fsqrts((float)((float)((float)(vel->m_y * vel->m_y) + (float)(vel->m_z * vel->m_z))
                                               + (float)(vel->m_x * vel->m_x)))
                       - 1.0842022e-19);
          __asm { fsel      f13, f2, f1, f10 }
          *(float *)&this->m_state = vel->m_z * (float)_FP13;
          *(float *)&this->m_pTune = (float)v54 * (float)_FP13;
          *(float *)&this->m_pSpace = (float)v53 * (float)_FP13;
          return this;
        }
        goto LABEL_15;
      case 2:
        v57 = (float)(result[8].m_x - pos->m_y);
        v58 = (float)(result[8].m_y - pos->m_z);
        v59 = (float)(result[7].m_z - pos->m_x);
        _FP0 = (float)((float)__fsqrts((float)((float)((float)v59 * (float)v59)
                                             + (float)((float)((float)v58 * (float)v58)
                                                     + (float)((float)v57 * (float)v57))))
                     - (float)1.0842022e-19);
        __asm { fsel      f12, f0, f13, f12 }
        *(float *)&this->m_pSpace = (float)_FP12 * (float)(result[7].m_z - pos->m_x);
        *(float *)&this->m_pTune = (float)v57 * (float)_FP12;
        *(float *)&this->m_state = (float)v58 * (float)_FP12;
        break;
      case 3:
        this->m_pSpace = (bfx::Space *)LODWORD(result[8].m_z);
        this->m_pTune = (const bfx::MoverTune *)LODWORD(result[9].m_x);
        this->m_state = LODWORD(result[9].m_y);
        break;
      default:
        this->m_pSpace = (bfx::Space *)LODWORD(bfx::ZERO_VEC.m_x);
        this->m_pTune = (const bfx::MoverTune *)LODWORD(bfx::ZERO_VEC.m_y);
        this->m_state = LODWORD(bfx::ZERO_VEC.m_z);
        break;
    }
  }
  return this;
}


// ========================================================================
// ?GetVolumeAdjustment@idSoundEmitterLocal@@UBAMXZ
// EA  : 0x832B1AD8
// RVA : 0x012B1AD8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

float __fastcall idSoundEmitterLocal::GetVolumeAdjustment(bfx::Orienter *this)
{
  double m_headingVel; // fp1

  m_headingVel = this->m_headingVel;
  return *((float *)&m_headingVel + 1);
}


// ========================================================================
// ?ApplyClientRotSpeed@Orienter@bfx@@QAAXM@Z
// EA  : 0x832B1AE0
// RVA : 0x012B1AE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::ApplyClientRotSpeed(bfx::Orienter *this, double rotSpeed)
{
  this->m_clientSpecifiedRotSpeed = rotSpeed;
}


// ========================================================================
// ?CalcHeadingFrameMatrix@bfx@@YAXPBVArea@1@AAVMatrix@1@@Z
// EA  : 0x832B1BA0
// RVA : 0x012B1BA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::CalcHeadingFrameMatrix(bfx::Vec3 *pArea, bfx::Matrix *mat)
{
  float *EdgeVec; // r3
  double v5; // fp10
  double v6; // fp8
  double v9; // fp30
  double v10; // fp29
  double v11; // fp28
  bfx::Area v12; // [sp+50h] [-90h] BYREF
  float v13; // [sp+88h] [-58h]
  bfx::Area v14; // [sp+90h] [-50h] BYREF

  EdgeVec = (float *)bfx::Area::GetEdgeVec(this: &v14, result: pArea, i: 0);
  v5 = EdgeVec[2];
  v6 = EdgeVec[1];
  _FP4 = (float)((float)__fsqrts((float)((float)(EdgeVec[2] * EdgeVec[2])
                                       + (float)((float)(*EdgeVec * *EdgeVec) + (float)(EdgeVec[1] * EdgeVec[1]))))
               - (float)1.0842022e-19);
  __asm { fsel      f2, f4, f3, f31 }
  v9 = (float)(*EdgeVec * (float)_FP2);
  v10 = (float)((float)_FP2 * EdgeVec[2]);
  *(float *)&v12.m_searchCost = *EdgeVec * (float)_FP2;
  *(float *)&v12.m_flags.m_flags1 = (float)_FP2 * (float)v5;
  v11 = (float)((float)_FP2 * (float)v6);
  *(float *)&v12.m_usageFlags = (float)_FP2 * (float)v6;
  bfx::Area::CalcNormal(this: &v12, result: pArea);
  v12.m_pos.m_x = 0.0;
  v12.m_pos.m_y = 0.0;
  v12.m_pos.m_z = 0.0;
  *(float *)&v12.m_flags.m_flags3 = (float)(*(float *)&v12.m_dynAreaData.m_data * (float)v10)
                                  - (float)((float)v11 * *(float *)&v12.m_pFirstLink);
  *(float *)&v12.m_flags.m_flags4 = (float)((float)v9 * *(float *)&v12.m_pFirstLink)
                                  - (float)(*(float *)&v12.m_pProxy * (float)v10);
  v13 = (float)(*(float *)&v12.m_pProxy * (float)v11) - (float)(*(float *)&v12.m_dynAreaData.m_data * (float)v9);
  bfx::Matrix::Build(
    this: mat,
    xAxis: (const bfx::Vec3 *)&v12.m_searchCost,
    yAxis: (const bfx::Vec3 *)&v12.m_flags.m_flags3,
    zAxis: (const bfx::Vec3 *)&v12,
    trans: &v12.m_pos);
}


// ========================================================================
// ?UpdateMatrix@Orienter@bfx@@AAAXXZ
// EA  : 0x832B1CB8
// RVA : 0x012B1CB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::UpdateMatrix(bfx::Orienter *this, long double a2)
{
  double v7; // fp29
  const bfx::Quat *v10; // r3
  long double v11; // fp2
  bfx::Orienter v14; // [sp+50h] [-110h] BYREF

  bfx::Orienter::GetForward(
    this: (bfx::Orienter *)&v14.m_headingFrameMatrix.m_data[9],
    result: (bfx::Vec3 *)this,
    a3: a2);
  bfx::Orienter::GetLocalUpAxis(this: &v14, result: (bfx::Vec3 *)this);
  _FP7 = (float)((float)__fsqrts((float)((float)((float)((float)(v14.m_headingFrameMatrix.m_data[11]
                                                               * *(float *)&v14.m_pTune)
                                                       - (float)(*(float *)&v14.m_state
                                                               * v14.m_headingFrameMatrix.m_data[10]))
                                               * (float)((float)(v14.m_headingFrameMatrix.m_data[11]
                                                               * *(float *)&v14.m_pTune)
                                                       - (float)(*(float *)&v14.m_state
                                                               * v14.m_headingFrameMatrix.m_data[10])))
                                       + (float)((float)((float)((float)(*(float *)&v14.m_state
                                                                       * v14.m_headingFrameMatrix.m_data[9])
                                                               - (float)(v14.m_headingFrameMatrix.m_data[11]
                                                                       * *(float *)&v14.m_pSpace))
                                                       * (float)((float)(*(float *)&v14.m_state
                                                                       * v14.m_headingFrameMatrix.m_data[9])
                                                               - (float)(v14.m_headingFrameMatrix.m_data[11]
                                                                       * *(float *)&v14.m_pSpace)))
                                               + (float)((float)((float)(*(float *)&v14.m_pSpace
                                                                       * v14.m_headingFrameMatrix.m_data[10])
                                                               - (float)(*(float *)&v14.m_pTune
                                                                       * v14.m_headingFrameMatrix.m_data[9]))
                                                       * (float)((float)(*(float *)&v14.m_pSpace
                                                                       * v14.m_headingFrameMatrix.m_data[10])
                                                               - (float)(*(float *)&v14.m_pTune
                                                                       * v14.m_headingFrameMatrix.m_data[9]))))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f7, f6, f31 }
  v14.m_headingFrameMatrix.m_data[5] = (float)((float)(v14.m_headingFrameMatrix.m_data[11] * *(float *)&v14.m_pTune)
                                             - (float)(*(float *)&v14.m_state * v14.m_headingFrameMatrix.m_data[10]))
                                     * (float)_FP5;
  v14.m_headingFrameMatrix.m_data[7] = (float)((float)(*(float *)&v14.m_pSpace * v14.m_headingFrameMatrix.m_data[10])
                                             - (float)(*(float *)&v14.m_pTune * v14.m_headingFrameMatrix.m_data[9]))
                                     * (float)_FP5;
  v14.m_headingFrameMatrix.m_data[6] = (float)((float)(*(float *)&v14.m_state * v14.m_headingFrameMatrix.m_data[9])
                                             - (float)(v14.m_headingFrameMatrix.m_data[11] * *(float *)&v14.m_pSpace))
                                     * (float)_FP5;
  _FP7 = (float)((float)__fsqrts((float)((float)((float)((float)(v14.m_headingFrameMatrix.m_data[6]
                                                               * *(float *)&v14.m_state)
                                                       - (float)(v14.m_headingFrameMatrix.m_data[7]
                                                               * *(float *)&v14.m_pTune))
                                               * (float)((float)(v14.m_headingFrameMatrix.m_data[6]
                                                               * *(float *)&v14.m_state)
                                                       - (float)(v14.m_headingFrameMatrix.m_data[7]
                                                               * *(float *)&v14.m_pTune)))
                                       + (float)((float)((float)((float)(*(float *)&v14.m_pTune
                                                                       * v14.m_headingFrameMatrix.m_data[5])
                                                               - (float)(v14.m_headingFrameMatrix.m_data[6]
                                                                       * *(float *)&v14.m_pSpace))
                                                       * (float)((float)(*(float *)&v14.m_pTune
                                                                       * v14.m_headingFrameMatrix.m_data[5])
                                                               - (float)(v14.m_headingFrameMatrix.m_data[6]
                                                                       * *(float *)&v14.m_pSpace)))
                                               + (float)((float)((float)(v14.m_headingFrameMatrix.m_data[7]
                                                                       * *(float *)&v14.m_pSpace)
                                                               - (float)(*(float *)&v14.m_state
                                                                       * v14.m_headingFrameMatrix.m_data[5]))
                                                       * (float)((float)(v14.m_headingFrameMatrix.m_data[7]
                                                                       * *(float *)&v14.m_pSpace)
                                                               - (float)(*(float *)&v14.m_state
                                                                       * v14.m_headingFrameMatrix.m_data[5]))))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f7, f6, f31 }
  v14.m_headingVel = (float)((float)(v14.m_headingFrameMatrix.m_data[6] * *(float *)&v14.m_state)
                           - (float)(v14.m_headingFrameMatrix.m_data[7] * *(float *)&v14.m_pTune))
                   * (float)_FP5;
  *(float *)&v14.m_accelMode = (float)((float)(v14.m_headingFrameMatrix.m_data[7] * *(float *)&v14.m_pSpace)
                                     - (float)(*(float *)&v14.m_state * v14.m_headingFrameMatrix.m_data[5]))
                             * (float)_FP5;
  v14.m_clientSpecifiedRotSpeed = (float)((float)(*(float *)&v14.m_pTune * v14.m_headingFrameMatrix.m_data[5])
                                        - (float)(v14.m_headingFrameMatrix.m_data[6] * *(float *)&v14.m_pSpace))
                                * (float)_FP5;
  bfx::Matrix::Build(
    this: &this->m_curRot,
    xAxis: (const bfx::Vec3 *)&v14.m_headingVel,
    yAxis: (const bfx::Vec3 *)&v14.m_headingFrameMatrix.m_data[5],
    zAxis: (const bfx::Vec3 *)&v14,
    trans: &bfx::ZERO_VEC);
  if ( this->m_slerping )
  {
    v7 = (float)(this->m_slerpTimer / this->m_slerpDuration);
    _FP12 = -v7;
    __asm { fsel      f28, f12, f0, f29 }
    bfx::Quat::Quat(this: (bfx::Quat *)&v14.m_headingFrameMatrix.m_data[9], m: &this->m_curRot);
    bfx::Slerper::Init(this: (bfx::Slerper *)&v14.m_targetPos.m_y, _q1: &this->m_slerpStartRot, _q2: v10, _FP2: v11);
    _FP11 = (float)((float)1.0 - (float)v7);
    __asm { fsel      f1, f11, f10, f30# t }
    bfx::Slerper::Slerp(
      this: (bfx::Slerper *)&v14.m_headingFrameMatrix.m_data[13],
      result: (bfx::Quat *)&v14.m_targetPos.m_y,
      t: _FP1);
    v14.m_headingFrameMatrix.m_data[1] = 0.0;
    v14.m_headingFrameMatrix.m_data[2] = 0.0;
    v14.m_headingFrameMatrix.m_data[3] = 0.0;
    bfx::Matrix::Build(
      this: &v14.m_curRot,
      q: (const bfx::Quat *)&v14.m_headingFrameMatrix.m_data[13],
      pos: (const bfx::Vec3 *)&v14.m_headingFrameMatrix.m_data[1]);
    this->m_curRot = v14.m_curRot;
  }
}


// ========================================================================
// ?CalcHeadingErrorFromDir@Orienter@bfx@@QBAMABVVec3@2@@Z
// EA  : 0x832B1E80
// RVA : 0x012B1E80
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

float __fastcall bfx::Orienter::CalcHeadingErrorFromDir(bfx::Orienter *this, const bfx::Vec3 *desiredFacingVec)
{
  double v4; // fp9
  double v5; // fp6
  double v6; // fp5
  double v9; // fp4
  double v10; // fp3
  double v11; // fp2
  long double v14; // fp4
  long double v15; // fp2
  long double v16; // fp2
  double v17; // fp31
  long double v18; // fp2
  float result; // fp1
  float v22; // [sp+50h] [-70h] BYREF
  float v23; // [sp+54h] [-6Ch]
  float v24; // [sp+58h] [-68h]

  bfx::Orienter::GetLocalUpAxis(this: (bfx::Orienter *)&v22, result: (bfx::Vec3 *)this);
  v4 = (float)((float)(desiredFacingVec->m_x * v24) - (float)(desiredFacingVec->m_z * v22));
  v5 = (float)((float)(desiredFacingVec->m_y * v22) - (float)(desiredFacingVec->m_x * v23));
  v6 = (float)((float)(desiredFacingVec->m_z * v23) - (float)(desiredFacingVec->m_y * v24));
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v6 * (float)v6)
                                       + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))))
               - (float)1.0842022e-19);
  __asm { fsel      f3, f8, f4, f12 }
  v9 = (float)((float)((float)((float)((float)(desiredFacingVec->m_y * v22) - (float)(desiredFacingVec->m_x * v23))
                             * (float)_FP3)
                     * this->m_headingFrameMatrix.m_data[8])
             - (float)(this->m_headingFrameMatrix.m_data[10]
                     * (float)((float)((float)(desiredFacingVec->m_z * v23) - (float)(desiredFacingVec->m_y * v24))
                             * (float)_FP3)));
  v11 = (float)((float)(this->m_headingFrameMatrix.m_data[10]
                      * (float)((float)((float)(desiredFacingVec->m_x * v24) - (float)(desiredFacingVec->m_z * v22))
                              * (float)_FP3))
              - (float)(this->m_headingFrameMatrix.m_data[9]
                      * (float)((float)((float)(desiredFacingVec->m_y * v22) - (float)(desiredFacingVec->m_x * v23))
                              * (float)_FP3)));
  v10 = (float)((float)(this->m_headingFrameMatrix.m_data[9]
                      * (float)((float)((float)(desiredFacingVec->m_z * v23) - (float)(desiredFacingVec->m_y * v24))
                              * (float)_FP3))
              - (float)((float)((float)((float)(desiredFacingVec->m_x * v24) - (float)(desiredFacingVec->m_z * v22))
                              * (float)_FP3)
                      * this->m_headingFrameMatrix.m_data[8]));
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v11 * (float)v11)
                                       + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f8, f6, f12 }
  *((double *)&v14 + 1) = (float)((float)v9 * (float)_FP5);
  *(double *)&v14 = (float)((float)v10 * (float)_FP5);
  *(double *)&v15 = (float)((float)(this->m_headingFrameMatrix.m_data[4] * (float)((float)v11 * (float)_FP5))
                          + (float)((float)(this->m_headingFrameMatrix.m_data[6] * (float)*(double *)&v14)
                                  + (float)(this->m_headingFrameMatrix.m_data[5] * (float)*((double *)&v14 + 1))));
  *((double *)&v15 + 1) = (float)((float)(this->m_headingFrameMatrix.m_data[0] * (float)((float)v11 * (float)_FP5))
                                + (float)((float)(this->m_headingFrameMatrix.m_data[2] * (float)*(double *)&v14)
                                        + (float)(this->m_headingFrameMatrix.m_data[1] * (float)*((double *)&v14 + 1))));
  v16 = atan2(v: v15, u: v14);
  v17 = (float)((float)(this->m_heading - (float)*(double *)&v16) * (float)0.15915494);
  *(double *)&v16 = v17;
  v18 = floor(x: v16);
  _FP4 = (float)(3.1415927 - (float)((float)((float)v17 - (float)*(double *)&v18) * 6.2831855));
  __asm { fsel      f1, f4, f5, f3 }
  LODWORD(result) = _FP1;
  return result;
}


// ========================================================================
// ?CalcHeadingError@Orienter@bfx@@QBAMABVVec3@2@00@Z
// EA  : 0x832B1FF0
// RVA : 0x012B1FF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

float __fastcall bfx::Orienter::CalcHeadingError(
        bfx::Orienter *this,
        const bfx::Vec3 *pos,
        const bfx::Vec3 *vel,
        const bfx::Vec3 *nextCornerG,
        long double a5,
        long double a6)
{
  double v7; // fp1
  bfx::Vec3 v9; // [sp+50h] [-20h] BYREF

  bfx::Orienter::GetDesiredFacingVec(
    this: (bfx::Orienter *)&v9,
    result: (bfx::Vec3 *)this,
    pos,
    vel,
    nextCornerG,
    a6: a5,
    a7: a6);
  v7 = bfx::Orienter::CalcHeadingErrorFromDir(this, desiredFacingVec: &v9);
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?IsClientMotionUsedThisUpdate@Orienter@bfx@@AAA_NM_N@Z
// EA  : 0x832B2040
// RVA : 0x012B2040
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

int __fastcall bfx::Orienter::IsClientMotionUsedThisUpdate(
        bfx::Orienter *this,
        double headingError,
        bool bForceUseClientMotion,
        char a4)
{
  int result; // r3
  int v5; // r8
  double v6; // fp0
  double v7; // fp13

  if ( !this->m_pTune->m_clientMotion )
    return 0;
  if ( a4 != 0 )
    return 1;
  v5 = *((_DWORD *)this->m_pSpace->m_components.m_data + 4);
  v6 = *(float *)(v5 + 24);
  if ( v6 >= 0.050000001 )
  {
    if ( v6 >= 0.1 )
      return 0;
    v7 = 0.2617994;
  }
  else
  {
    v7 = 0.087266468;
  }
  if ( __fabs(headingError) <= v7 )
    return 0;
  _FP10 = (float)((float)(this->m_clientSpecifiedRotSpeed * *(float *)(v5 + 24)) + (float)headingError);
  result = 1;
  __asm
  {
    fsel      f9, f1, f0, f13
    fsel      f8, f10, f12, f11
  }
  if ( (float)_FP8 != _FP9 )
    return 0;
  return result;
}


// ========================================================================
// ?Simulate@Orienter@bfx@@QAAXABVVec3@2@0M0_N@Z
// EA  : 0x832B2110
// RVA : 0x012B2110
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::Simulate(
        bfx::Orienter *this,
        const bfx::Vec3 *pos,
        const bfx::Vec3 *vel,
        long double simTime,
        const bfx::Vec3 *nextCornerG,
        const bfx::Vec3 *bForceUseClientMotion,
        char a7,
        long double a8)
{
  double v8; // fp30
  bool v11; // r4
  double v12; // fp1
  double v13; // fp29
  double v14; // fp13
  double m_slerpDuration; // fp12
  int IsClientMotionUsedThisUpdate; // r30
  double v17; // fp6
  double v18; // fp4
  double v19; // fp2
  double m_clientSpecifiedRotSpeed; // fp3
  long double v21; // fp2
  const bfx::MoverTune *m_pTune; // r10
  double v23; // fp0
  double v24; // fp13
  double v25; // fp12
  bfx::Orienter::AccelMode m_accelMode; // r11
  bfx::Vec3 v27[2]; // [sp+50h] [-50h] BYREF

  v8 = *(double *)&simTime;
  bfx::Orienter::GetDesiredFacingVec(
    this: (bfx::Orienter *)v27,
    result: (bfx::Vec3 *)this,
    pos,
    vel,
    nextCornerG: bForceUseClientMotion,
    a6: simTime,
    a7: a8);
  v12 = bfx::Orienter::CalcHeadingErrorFromDir(this, desiredFacingVec: v27);
  v13 = v12;
  if ( this->m_slerping )
  {
    v14 = (float)(this->m_slerpTimer + (float)v8);
    m_slerpDuration = this->m_slerpDuration;
    this->m_slerpTimer = this->m_slerpTimer + (float)v8;
    if ( v14 > m_slerpDuration )
      this->m_slerping = false;
  }
  IsClientMotionUsedThisUpdate = (unsigned __int8)bfx::Orienter::IsClientMotionUsedThisUpdate(
                                                    this,
                                                    headingError: v12,
                                                    bForceUseClientMotion: v11,
                                                    a4: a7);
  if ( IsClientMotionUsedThisUpdate != 0 )
    m_clientSpecifiedRotSpeed = this->m_clientSpecifiedRotSpeed;
  else
    m_clientSpecifiedRotSpeed = this->m_headingVel;
  *(double *)&v21 = bfx::CalcAccel(curX: v17, goalX: v19, speed: m_clientSpecifiedRotSpeed, maxAccel: v18, simTime: v8);
  m_pTune = this->m_pTune;
  if ( m_pTune->m_clientMotion && a7 != 0 )
    this->m_headingVel = this->m_clientSpecifiedRotSpeed;
  v23 = (float)((float)((float)*(double *)&v21 * (float)v8) + this->m_headingVel);
  this->m_headingVel = (float)((float)*(double *)&v21 * (float)v8) + this->m_headingVel;
  v24 = (float)(m_pTune->m_turnInPlace.m_speed * (float)0.017453292);
  if ( v23 > v24 || (v24 = -v24, v23 < v24) )
    v23 = v24;
  this->m_headingVel = v23;
  if ( IsClientMotionUsedThisUpdate != 0 )
    v25 = (float)((float)(this->m_clientSpecifiedRotSpeed * (float)v8) + this->m_heading);
  else
    v25 = (float)((float)((float)v23 * (float)v8) + this->m_heading);
  m_accelMode = this->m_accelMode;
  this->m_heading = v25;
  if ( m_accelMode == HIGH_ACCEL_MODE
    && this->m_state <= (unsigned int)FACE_STRICTLY_IN_TRAVEL_DIR
    && __fabs(v13) < 0.017453292
    && __fabs(this->m_headingVel) < (float)(m_pTune->m_turnInPlace.m_speed * (float)0.00017453294) )
  {
    this->m_accelMode = LOW_ACCEL_MODE;
  }
  bfx::Orienter::UpdateMatrix(this, a2: v21);
}


// ========================================================================
// ?TeleportToArea@Orienter@bfx@@QAAXPBVArea@2@@Z
// EA  : 0x832B2310
// RVA : 0x012B2310
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::TeleportToArea(bfx::Orienter *this, bfx::Vec3 *pArea, long double a3)
{
  long double v5; // fp2
  double v6; // fp31
  long double v7; // fp2
  double v8; // fp0
  double v9; // fp13
  double v10; // fp12
  long double v11; // fp4
  long double v12; // fp2
  long double v13; // fp2
  bfx::Vec3 v14; // [sp+50h] [-50h] BYREF
  bfx::Matrix v15; // [sp+60h] [-40h] BYREF

  if ( pArea != nullptr )
  {
    *(double *)&a3 = this->m_heading;
    v5 = sin(x: a3);
    v6 = (float)*(double *)&v5;
    *(double *)&v5 = this->m_heading;
    v7 = cos(x: v5);
    v14.m_x = *(double *)&v7;
    v14.m_y = v6;
    v14.m_z = 0.0;
    bfx::Matrix::operator*(this: &v15, result: (bfx::Vec3 *)&this->m_headingFrameMatrix, rhs: &v14);
    bfx::CalcHeadingFrameMatrix(pArea, mat: &this->m_headingFrameMatrix);
    v8 = v15.m_data[1];
    v9 = v15.m_data[2];
    v10 = v15.m_data[0];
    this->m_areaIsFull3D = pArea[4].m_x < 0.0;
    *((double *)&v11 + 1) = (float)((float)v8 * this->m_headingFrameMatrix.m_data[1]);
    *(double *)&v11 = (float)((float)(this->m_headingFrameMatrix.m_data[6] * (float)v9)
                            + (float)(this->m_headingFrameMatrix.m_data[5] * (float)v8));
    *((double *)&v12 + 1) = (float)((float)((float)v10 * this->m_headingFrameMatrix.m_data[0])
                                  + (float)((float)((float)v9 * this->m_headingFrameMatrix.m_data[2])
                                          + (float)((float)v8 * this->m_headingFrameMatrix.m_data[1])));
    *(double *)&v12 = (float)((float)(this->m_headingFrameMatrix.m_data[4] * (float)v10)
                            + (float)((float)(this->m_headingFrameMatrix.m_data[6] * (float)v9)
                                    + (float)(this->m_headingFrameMatrix.m_data[5] * (float)v8)));
    v13 = atan2(v: v12, u: v11);
    *(double *)&v13 = (float)*(double *)&v13;
    this->m_heading = *(double *)&v13;
    bfx::Orienter::UpdateMatrix(this, a2: v13);
  }
}


// ========================================================================
// ?MovedOntoArea@Orienter@bfx@@QAAXPAVArea@2@0ABVVec3@2@@Z
// EA  : 0x832B23E8
// RVA : 0x012B23E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::MovedOntoArea(
        bfx::Orienter *this,
        bfx::Vec3 *pOldArea,
        bfx::Vec3 *pNewArea,
        const bfx::Vec3 *edgeVec)
{
  long double v8; // fp2
  long double v9; // fp2
  double v10; // fp31
  long double v11; // fp2
  long double v12; // fp4
  long double v13; // fp2
  long double v14; // fp2
  double m_surfaceOrientSlerpTime; // fp30
  float *v16; // r3
  long double v20; // fp2
  double v21; // fp0
  double v22; // fp12
  float *v23; // r3
  bfx::Area v24; // [sp+50h] [-120h] BYREF
  float v25; // [sp+88h] [-E8h]
  _BYTE v26[80]; // [sp+90h] [-E0h] BYREF
  bfx::Area v27; // [sp+E0h] [-90h] BYREF
  unsigned int v28; // [sp+118h] [-58h]

  bfx::CalcHeadingFrameMatrix(pArea: pOldArea, mat: (bfx::Matrix *)&v27.m_pos);
  bfx::CalcHeadingFrameMatrix(pArea: pNewArea, mat: (bfx::Matrix *)&v26[16]);
  *(double *)&v8 = this->m_heading;
  this->m_areaIsFull3D = pNewArea[4].m_x < 0.0;
  v9 = sin(x: v8);
  v10 = (float)*(double *)&v9;
  *(double *)&v9 = this->m_heading;
  v11 = cos(x: v9);
  *(float *)&v24.m_flags.m_flags4 = v10;
  *(float *)&v24.m_flags.m_flags3 = *(double *)&v11;
  v25 = 0.0;
  bfx::Matrix::operator*(this: (bfx::Matrix *)v26, result: &v27.m_pos, rhs: (const bfx::Vec3 *)&v24.m_flags.m_flags3);
  v24.m_searchCost = v27.m_flags.m_flags3;
  v24.m_usageFlags = v27.m_flags.m_flags4;
  v24.m_flags.m_flags1 = v28;
  bfx::Area::CalcNormal(this: &v24, result: pNewArea);
  bfx::RotateVecIntoNewArea(
    result: &v24.m_pos,
    vec: (const bfx::Vec3 *)v26,
    edgeUnitVec: edgeVec,
    oldAreaNormal: (const bfx::Vec3 *)&v24.m_searchCost,
    newAreaNormal: (const bfx::Vec3 *)&v24);
  *((double *)&v12 + 1) = *(float *)&v26[36];
  *(double *)&v12 = *(float *)&v26[16];
  *((double *)&v13 + 1) = (float)((float)(v24.m_pos.m_x * *(float *)&v26[16])
                                + (float)((float)(v24.m_pos.m_y * *(float *)&v26[20])
                                        + (float)(v24.m_pos.m_z * *(float *)&v26[24])));
  *(double *)&v13 = (float)((float)(*(float *)&v26[32] * v24.m_pos.m_x)
                          + (float)((float)(*(float *)&v26[36] * v24.m_pos.m_y)
                                  + (float)(*(float *)&v26[40] * v24.m_pos.m_z)));
  v14 = atan2(v: v13, u: v12);
  this->m_heading = *(double *)&v14;
  memcpy(Dst: &this->m_headingFrameMatrix, Src: &v26[16], Size: sizeof(this->m_headingFrameMatrix));
  m_surfaceOrientSlerpTime = this->m_pTune->m_surfaceOrientTune.m_surfaceOrientSlerpTime;
  v16 = (float *)bfx::Area::CalcNormal(this: &v27, result: pOldArea);
  *((double *)&_FP2 + 1) = (float)((float)-1.0
                                 - (float)((float)(*v16 * *(float *)&v24.m_pProxy)
                                         + (float)((float)(v16[1] * *(float *)&v24.m_dynAreaData.m_data)
                                                 + (float)(v16[2] * *(float *)&v24.m_pFirstLink))));
  _FP1 = (float)((float)1.0
               - (float)((float)(*v16 * *(float *)&v24.m_pProxy)
                       + (float)((float)(v16[1] * *(float *)&v24.m_dynAreaData.m_data)
                               + (float)(v16[2] * *(float *)&v24.m_pFirstLink))));
  __asm { fsel      f13, f2, f13, f3 }
  __asm { fsel      f1, f1, f12, f0# x }
  v20 = acos(x: _FP2);
  v21 = (float)((float)((float)*(double *)&v20 * (float)0.31830987) * (float)m_surfaceOrientSlerpTime);
  if ( this->m_slerping )
    v22 = (float)(this->m_slerpDuration - this->m_slerpTimer);
  else
    v22 = 0.0;
  if ( this->m_slerping )
    goto LABEL_7;
  if ( v21 > 0.0099999998 )
  {
LABEL_8:
    this->m_slerpDuration = (float)((float)*(double *)&v20 * (float)0.31830987) * (float)m_surfaceOrientSlerpTime;
    bfx::Quat::Quat(this: (bfx::Quat *)&v27, m: &this->m_curRot);
    this->m_slerpStartRot.m_w = *v23;
    this->m_slerpStartRot.m_x = v23[1];
    this->m_slerpStartRot.m_y = v23[2];
    this->m_slerpStartRot.m_z = v23[3];
    this->m_slerping = true;
    this->m_slerpTimer = 0.0;
    goto LABEL_9;
  }
  if ( this->m_slerping )
  {
LABEL_7:
    if ( v21 > v22 )
      goto LABEL_8;
  }
LABEL_9:
  bfx::Orienter::UpdateMatrix(this, a2: v20);
}


// ========================================================================
// ?SetOrientation@Orienter@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B2620
// RVA : 0x012B2620
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::SetOrientation(bfx::Orienter *this, const bfx::Vec3 *forwardVecIn)
{
  float m_x; // r11
  double v3; // fp13
  float m_y; // r10
  double v5; // fp12
  float m_z; // r9
  bfx::Matrix *p_m_headingFrameMatrix; // r31
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  bfx::Vec3 *v13; // r3
  double v14; // fp0
  double v15; // fp31
  bfx::Vec3 *UpVec; // r3
  double v17; // fp6
  double v18; // fp5
  double v19; // fp4
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  long double v25; // fp4
  long double v26; // fp2
  long double v27; // fp2
  float v28; // [sp+50h] [-60h]
  float v29; // [sp+54h] [-5Ch]
  float v30; // [sp+58h] [-58h]
  bfx::Vec3 v31; // [sp+60h] [-50h] BYREF

  m_x = forwardVecIn->m_x;
  v3 = this->m_headingFrameMatrix.m_data[9];
  m_y = forwardVecIn->m_y;
  v5 = this->m_headingFrameMatrix.m_data[10];
  m_z = forwardVecIn->m_z;
  v31.m_x = this->m_headingFrameMatrix.m_data[8];
  v31.m_y = v3;
  p_m_headingFrameMatrix = &this->m_headingFrameMatrix;
  v31.m_z = v5;
  v28 = m_x;
  v29 = m_y;
  v30 = m_z;
  if ( bfx::ShouldBeVertical(areaNormal: &v31, areaIsFull3D: this->m_areaIsFull3D, pTune: this->m_pTune)
    && (v10 = p_m_headingFrameMatrix->m_data[8],
        v11 = p_m_headingFrameMatrix->m_data[9],
        v12 = p_m_headingFrameMatrix->m_data[10],
        v13 = bfx::GetUpVec(result: &v31),
        (v14 = (float)((float)(v13->m_x * (float)v10)
                     + (float)((float)(v13->m_z * (float)v12) + (float)(v13->m_y * (float)v11)))) < 0.99902344)
    && __fabs(v14) >= 1.0842022e-19 )
  {
    v15 = (float)((float)((float)(v28 * p_m_headingFrameMatrix->m_data[8])
                        + (float)((float)(v30 * p_m_headingFrameMatrix->m_data[10])
                                + (float)(v29 * p_m_headingFrameMatrix->m_data[9])))
                / (float)((float)(v13->m_x * (float)v10)
                        + (float)((float)(v13->m_z * (float)v12) + (float)(v13->m_y * (float)v11))));
    UpVec = bfx::GetUpVec(result: &v31);
    v17 = (float)(forwardVecIn->m_y - (float)(UpVec->m_y * (float)v15));
    v18 = (float)(forwardVecIn->m_z - (float)(UpVec->m_z * (float)v15));
    v19 = (float)(forwardVecIn->m_x - (float)((float)v15 * UpVec->m_x));
    _FP10 = (float)((float)__fsqrts((float)((float)((float)v19 * (float)v19)
                                          + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))))
                  - 1.0842022e-19);
    __asm { fsel      f8, f10, f9, f12 }
    v22 = (float)((float)(forwardVecIn->m_x - (float)((float)v15 * UpVec->m_x)) * (float)_FP8);
    v23 = (float)((float)(forwardVecIn->m_y - (float)(UpVec->m_y * (float)v15)) * (float)_FP8);
    v24 = (float)((float)(forwardVecIn->m_z - (float)(UpVec->m_z * (float)v15)) * (float)_FP8);
  }
  else
  {
    v24 = v30;
    v23 = v29;
    v22 = v28;
  }
  *((double *)&v25 + 1) = p_m_headingFrameMatrix->m_data[4];
  *(double *)&v25 = (float)((float)(p_m_headingFrameMatrix->m_data[1] * (float)v23)
                          + (float)(p_m_headingFrameMatrix->m_data[2] * (float)v24));
  *((double *)&v26 + 1) = (float)((float)(p_m_headingFrameMatrix->m_data[0] * (float)v22)
                                + (float)((float)(p_m_headingFrameMatrix->m_data[1] * (float)v23)
                                        + (float)(p_m_headingFrameMatrix->m_data[2] * (float)v24)));
  *(double *)&v26 = (float)((float)(p_m_headingFrameMatrix->m_data[4] * (float)v22)
                          + (float)((float)(p_m_headingFrameMatrix->m_data[5] * (float)v23)
                                  + (float)(p_m_headingFrameMatrix->m_data[6] * (float)v24)));
  v27 = atan2(v: v26, u: v25);
  this->m_heading = *(double *)&v27;
  bfx::Orienter::UpdateMatrix(this, a2: v27);
}


// ========================================================================
// ?SetOrientation@Orienter@bfx@@QAAXABVMatrix@2@@Z
// EA  : 0x832B27E8
// RVA : 0x012B27E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxorienter.cpp
// ========================================================================

void __fastcall bfx::Orienter::SetOrientation(bfx::Orienter *this, const bfx::Matrix *desiredRot)
{
  double v2; // fp12
  bfx::Vec3 v3; // [sp+50h] [-20h] BYREF

  v3.m_x = desiredRot->m_data[0];
  v2 = desiredRot->m_data[2];
  v3.m_y = desiredRot->m_data[1];
  v3.m_z = v2;
  bfx::Orienter::SetOrientation(this, forwardVecIn: &v3);
}

