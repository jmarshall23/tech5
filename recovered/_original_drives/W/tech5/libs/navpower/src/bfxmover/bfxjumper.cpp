
// ========================================================================
// ?CalculateJumpDynamics@JumperImpl@bfx@@AAAXABVMatrix@2@0PBM@Z
// EA  : 0x832B5C30
// RVA : 0x012B5C30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::CalculateJumpDynamics(
        bfx::JumperImpl *this,
        const bfx::Matrix *startMat,
        const bfx::Matrix *endMat,
        const float *pInitialJumpSpeed)
{
  const bfx::JumperTune *m_pTune; // r10
  double m_initialSpeed; // fp9
  double v9; // fp12
  double v10; // fp13
  double v11; // fp0
  double v12; // fp11
  double m_x; // fp30
  double m_y; // fp29
  double m_z; // fp28
  double v16; // fp31
  double v17; // fp13
  double v18; // fp12
  double v19; // fp11
  double m_totalJumpTime; // fp1
  bfx::Vec3 v23; // [sp+50h] [-50h] BYREF

  if ( pInitialJumpSpeed != nullptr )
    this->m_initialSpeed = __fabs(*pInitialJumpSpeed);
  else
    this->m_initialSpeed = this->m_commonState->m_speedX * this->m_pTune->m_speed;
  m_pTune = this->m_pTune;
  m_initialSpeed = this->m_initialSpeed;
  this->m_jumpRescalingReference = this->m_commonState->m_speedX * m_pTune->m_speed;
  v9 = (float)(endMat->m_data[14] - startMat->m_data[14]);
  v10 = (float)(endMat->m_data[13] - startMat->m_data[13]);
  v11 = (float)(endMat->m_data[12] - startMat->m_data[12]);
  if ( m_initialSpeed <= 1.0842022e-19 )
  {
    this->m_totalJumpTime = 2139095039;
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
    goto LABEL_9;
  }
  v12 = __fsqrts((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)v9 * (float)v9) + (float)((float)v10 * (float)v10))));
  if ( v12 <= 1.0842022e-19 )
  {
    this->m_totalJumpTime = 0.001;
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
LABEL_9:
    m_x = bfx::ZERO_VEC.m_x;
    goto LABEL_10;
  }
  this->m_totalJumpTime = (float)v12 / (float)m_initialSpeed;
  m_x = (float)((float)((float)1.0 / (float)((float)v12 / (float)m_initialSpeed)) * (float)v11);
  m_y = (float)((float)((float)1.0 / (float)((float)v12 / (float)m_initialSpeed)) * (float)v10);
  m_z = (float)((float)((float)1.0 / (float)((float)v12 / (float)m_initialSpeed)) * (float)v9);
LABEL_10:
  v16 = (float)((float)(m_pTune->m_arcFraction * (float)m_initialSpeed) * (float)4.0);
  bfx::GetUpVec(result: &v23);
  v17 = v23.m_y;
  v18 = v23.m_z;
  v19 = v23.m_x;
  if ( (float)((float)(startMat->m_data[8] * v23.m_x)
             + (float)((float)(v23.m_z * startMat->m_data[10]) + (float)(v23.m_y * startMat->m_data[9]))) < -0.1
    && v16 > (float)((float)((float)((float)m_x * (float)-1.0) * v23.m_x)
                   + (float)((float)((float)((float)m_y * (float)-1.0) * v23.m_y)
                           + (float)((float)((float)m_z * (float)-1.0) * v23.m_z))) )
  {
    v16 = (float)((float)((float)((float)m_x * (float)-1.0) * v23.m_x)
                + (float)((float)((float)((float)m_y * (float)-1.0) * v23.m_y)
                        + (float)((float)((float)m_z * (float)-1.0) * v23.m_z)));
  }
  if ( (float)((float)(endMat->m_data[8] * v23.m_x)
             + (float)((float)(endMat->m_data[9] * v23.m_y) + (float)(endMat->m_data[10] * v23.m_z))) < -0.1
    && v16 > (float)((float)(v23.m_x * (float)m_x)
                   + (float)((float)(v23.m_z * (float)m_z) + (float)(v23.m_y * (float)m_y))) )
  {
    v16 = (float)((float)(v23.m_x * (float)m_x) + (float)((float)(v23.m_z * (float)m_z) + (float)(v23.m_y * (float)m_y)));
  }
  this->m_gravity = (float)((float)v16 * (float)-2.0) / this->m_totalJumpTime;
  this->m_vel.m_x = (float)((float)v19 * (float)v16) + (float)m_x;
  this->m_vel.m_y = (float)((float)v17 * (float)v16) + (float)m_y;
  this->m_vel.m_z = (float)((float)v18 * (float)v16) + (float)m_z;
  m_totalJumpTime = this->m_totalJumpTime;
  _FP12 = (float)((float)0.25 - (float)(this->m_totalJumpTime * (float)0.5));
  __asm { fsel      f11, f12, f13, f0 }
  this->m_initialJumpTime = _FP11;
  this->m_mainJumpTime = (float)m_totalJumpTime - (float)_FP11;
}


// ========================================================================
// ?GetName@JumperImpl@bfx@@UAAPBDXZ
// EA  : 0x832B5E78
// RVA : 0x012B5E78
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

const char *__fastcall bfx::JumperImpl::GetName(bfx::JumperImpl *this)
{
  if ( this->m_customLink )
    return "Jumping: custom";
  if ( this->IsFrozenAtStart(this) )
    return "Jumping: isWaiting";
  return "Jumping: DEFAULT";
}


// ========================================================================
// ??0JumperTune@bfx@@QAA@XZ
// EA  : 0x832B5F00
// RVA : 0x012B5F00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

bfx::JumperTune *__fastcall bfx::JumperTune::JumperTune(bfx::JumperTune *this)
{
  double Scale; // fp1
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  Scale = bfx::GetScale();
  this->m_keepSpeedWhenSwapToDefault = false;
  this->m_onlyJumpToEndPoint = false;
  this->m_speed = (float)Scale * (float)5.0;
  this->m_arcFraction = 0.25;
  this->m_turnBeforeJumpAngle = 45.0;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$84792
// EA  : 0x832B5F88
// RVA : 0x012B5F88
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_84792()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?Simulate@JumperImpl@bfx@@UAAXM@Z
// EA  : 0x832B5FB0
// RVA : 0x012B5FB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::Simulate(bfx::JumperImpl *this, double origSimTime)
{
  double v3; // fp13
  bfx::ProbeReq *m_pProbeReq; // r11
  double v5; // fp31
  bfx::ProbeReq *v6; // r8
  double v7; // fp10
  double v8; // fp4
  double v9; // fp7
  double m_y; // fp3
  double m_z; // fp2
  double v12; // fp12
  double v13; // fp6
  double v14; // fp11
  double v15; // fp1
  double v16; // fp29
  double m_x; // fp8
  double m_initialSpeed; // fp28
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r5
  bfx::JumperImpl::State m_state; // r11
  double v26; // fp0
  long double v27; // fp2
  float *v28; // r3
  bfx::JumperImpl::State v29; // r11
  float *v30; // r3
  double v31; // fp13
  double v32; // fp12
  double v33; // fp7
  double v34; // fp6
  double v35; // fp0
  double v36; // fp4
  double v37; // fp3
  double v38; // fp2
  double v39; // fp1
  double v40; // fp7
  double v41; // fp6
  double v42; // fp9
  double v43; // fp6
  double v44; // fp5
  double v45; // fp1
  double v46; // fp10
  double v47; // fp9
  double v48; // fp3
  double v49; // fp2
  double v50; // fp3
  double v51; // fp2
  double v52; // fp8
  double v53; // fp7
  double v54; // fp6
  double v55; // fp1
  double v56; // fp8
  double v57; // fp3
  double v58; // fp4
  double v59; // fp8
  double v60; // fp7
  double v61; // fp5
  double v62; // fp2
  double v63; // fp6
  double v64; // fp2
  double v65; // fp4
  double v66; // fp5
  double v67; // fp10
  double v68; // fp6
  double v69; // fp1
  double v70; // fp3
  double v71; // fp2
  double v72; // fp9
  double v73; // fp10
  double v74; // fp3
  double v75; // fp1
  double v76; // fp8
  double v77; // fp7
  double v78; // fp5
  double v79; // fp7
  double v80; // fp9
  double v81; // fp5
  double v82; // fp7
  double v83; // fp1
  double v84; // fp6
  double v85; // fp5
  double v86; // fp4
  double v87; // fp9
  double v88; // fp3
  double v89; // fp4
  double v90; // fp1
  double v91; // fp7
  double v92; // fp4
  double v93; // fp8
  double v94; // fp3
  double v95; // fp9
  double v96; // fp5
  double v97; // fp8
  double v98; // fp10
  double v99; // fp3
  double v100; // fp2
  double v101; // fp1
  double v102; // fp10
  double v103; // fp5
  double v104; // fp7
  double v105; // fp1
  double v106; // fp4
  double v107; // fp1
  double v108; // fp10
  double v109; // fp6
  double v110; // fp5
  double v111; // fp4
  double v112; // fp3
  float v113[2]; // [sp+50h] [-100h] BYREF
  bfx::Vec3 v114; // [sp+58h] [-F8h] BYREF
  bfx::Slerper v115; // [sp+70h] [-E0h] BYREF
  float v116; // [sp+B0h] [-A0h]
  float v117; // [sp+B4h] [-9Ch]
  float v118; // [sp+B8h] [-98h]
  bfx::Matrix v119; // [sp+C0h] [-90h] BYREF

  v3 = 1.0;
  if ( this->m_jumpRescalingReference > 1.0842022e-19 )
    v3 = (float)((float)(this->m_commonState->m_speedX * this->m_pTune->m_speed) / this->m_jumpRescalingReference);
  m_pProbeReq = this->m_pProbeReq;
  v5 = (float)((float)v3 * (float)origSimTime);
  if ( m_pProbeReq != nullptr && m_pProbeReq->m_probeResultsValid )
  {
    if ( m_pProbeReq->m_collided )
    {
      this->GetMatrix(this, a2: (bfx::Matrix *)&v115.m_q2);
      v6 = this->m_pProbeReq;
      v7 = (float)(this->m_endPos.m_y - v117);
      v8 = (float)(this->m_endPos.m_x - v116);
      v9 = (float)(this->m_endPos.m_z - v118);
      m_y = this->m_vel.m_y;
      m_z = this->m_vel.m_z;
      v12 = (float)(v6->m_collidePos.m_y - v6->m_referencePos.m_y);
      v13 = (float)((float)((float)(this->m_endPos.m_z - v118) * (float)(this->m_endPos.m_z - v118))
                  + (float)((float)(this->m_endPos.m_y - v117) * (float)(this->m_endPos.m_y - v117)));
      v14 = (float)(v6->m_collidePos.m_z - v6->m_referencePos.m_z);
      v15 = this->m_endPos.m_y;
      v16 = this->m_endPos.m_z;
      m_x = this->m_vel.m_x;
      m_initialSpeed = this->m_initialSpeed;
      this->m_endPos.m_x = this->m_endPos.m_x + (float)(v6->m_collidePos.m_x - v6->m_referencePos.m_x);
      this->m_endPos.m_y = (float)v15 + (float)v12;
      this->m_endPos.m_z = (float)v16 + (float)v14;
      _FP9 = (float)((float)__fsqrts((float)((float)((float)v8 * (float)v8) + (float)v13)) - (float)1.0842022e-19);
      __asm { fsel      f5, f9, f6, f13 }
      _FP9 = (float)((float)((float)((float)m_x * (float)((float)_FP5 * (float)v8))
                           + (float)((float)((float)m_z * (float)((float)v9 * (float)_FP5))
                                   + (float)((float)m_y * (float)((float)v7 * (float)_FP5))))
                   - (float)m_initialSpeed);
      __asm { fsel      f8, f9, f10, f28 }
      v113[0] = _FP8;
      bfx::Matrix::Build(this: &v119, q: &this->m_endQuat, pos: &this->m_endPos);
      bfx::JumperImpl::CalculateJumpDynamics(
        this,
        startMat: (const bfx::Matrix *)&v115.m_q2,
        endMat: &v119,
        pInitialJumpSpeed: v113);
      m_pProxy = this->m_endArea.m_pProxy;
      if ( m_pProxy != nullptr )
        m_pArea = m_pProxy->m_pArea;
      else
        m_pArea = nullptr;
      bfx::SmartPath::SetStartData(
        this: this->m_commonState->m_pSmartPath,
        startPos: &this->m_endPos,
        pStartArea: m_pArea);
    }
    bfx::DestroyProbeReq(pProbeReq: this->m_pProbeReq);
    this->m_pProbeReq = nullptr;
  }
  if ( !this->m_frozenAtStart )
  {
    if ( this->m_firstFrame )
    {
      this->m_firstFrame = false;
      return;
    }
    m_state = this->m_state;
    if ( m_state != FINISHED )
    {
      v26 = (float)(this->m_curTime + (float)v5);
      this->m_curTime = this->m_curTime + (float)v5;
      if ( m_state != INITIAL_JUMP )
      {
        if ( m_state != MAIN_JUMP )
          goto LABEL_22;
        bfx::Slerper::Slerp(
          this: &v115,
          result: &this->m_slerper.m_q1,
          t: (float)((float)((float)v26 - this->m_initialJumpTime) / this->m_mainJumpTime));
        this->m_rot.m_w = *v30;
        this->m_rot.m_x = v30[1];
        this->m_rot.m_y = v30[2];
        this->m_rot.m_z = v30[3];
        if ( this->m_curTime <= (double)this->m_totalJumpTime )
          goto LABEL_22;
        v29 = FINISHED;
        v5 = (float)((float)v5 - (float)(this->m_curTime - this->m_totalJumpTime));
      }
      else
      {
        bfx::Slerper::Slerp(
          this: &v115,
          result: &this->m_slerper.m_q1,
          t: (float)((float)v26 / this->m_initialJumpTime));
        this->m_rot.m_w = *v28;
        this->m_rot.m_x = v28[1];
        this->m_rot.m_y = v28[2];
        this->m_rot.m_z = v28[3];
        if ( this->m_curTime <= (double)this->m_initialJumpTime )
        {
LABEL_22:
          bfx::GetUpVec(result: &v114);
          v31 = v114.m_x;
          v32 = v114.m_y;
          v33 = this->m_vel.m_x;
          v34 = this->m_vel.m_y;
          v35 = v114.m_z;
          v36 = (float)(v114.m_x * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v37 = (float)(v114.m_y * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v38 = (float)((float)(v114.m_z * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))) + this->m_vel.m_z);
          this->m_vel.m_z = (float)(v114.m_z * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)))
                          + this->m_vel.m_z;
          v39 = (float)((float)v33 + (float)v36);
          this->m_vel.m_x = (float)v33 + (float)v36;
          this->m_vel.m_y = (float)v34 + (float)v37;
          v40 = this->m_pos.m_z;
          v42 = (float)(this->m_pos.m_y + (float)((float)((float)v34 + (float)v37) * (float)((float)v5 * (float)0.1)));
          v41 = this->m_pos.m_x;
          this->m_pos.m_y = v42;
          this->m_pos.m_z = (float)v40 + (float)((float)((float)v5 * (float)0.1) * (float)v38);
          this->m_pos.m_x = (float)v41 + (float)((float)v39 * (float)((float)v5 * (float)0.1));
          v43 = this->m_vel.m_y;
          v44 = this->m_vel.m_z;
          v45 = (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v46 = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v47 = (float)(this->m_vel.m_x
                      + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          this->m_vel.m_x = this->m_vel.m_x
                          + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          this->m_vel.m_y = (float)v43 + (float)v45;
          this->m_vel.m_z = (float)v46 + (float)v44;
          v48 = this->m_pos.m_y;
          v49 = this->m_pos.m_z;
          this->m_pos.m_x = this->m_pos.m_x + (float)((float)v47 * (float)((float)v5 * (float)0.1));
          this->m_pos.m_z = (float)v49 + (float)((float)((float)v5 * (float)0.1) * (float)((float)v46 + (float)v44));
          this->m_pos.m_y = (float)v48 + (float)((float)((float)v43 + (float)v45) * (float)((float)v5 * (float)0.1));
          v50 = this->m_vel.m_y;
          v51 = this->m_vel.m_z;
          v52 = (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v53 = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v54 = (float)(this->m_vel.m_x
                      + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          this->m_vel.m_x = this->m_vel.m_x
                          + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          this->m_vel.m_y = (float)v50 + (float)v52;
          this->m_vel.m_z = (float)v53 + (float)v51;
          v55 = this->m_pos.m_x;
          v57 = (float)(this->m_pos.m_y + (float)((float)((float)v50 + (float)v52) * (float)((float)v5 * (float)0.1)));
          v56 = this->m_pos.m_z;
          this->m_pos.m_y = v57;
          this->m_pos.m_x = (float)v55 + (float)((float)v54 * (float)((float)v5 * (float)0.1));
          this->m_pos.m_z = (float)v56 + (float)((float)((float)v5 * (float)0.1) * (float)((float)v53 + (float)v51));
          v58 = this->m_vel.m_z;
          v59 = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v60 = this->m_vel.m_y;
          v61 = (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v62 = (float)(this->m_vel.m_x
                      + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          this->m_vel.m_x = this->m_vel.m_x
                          + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          this->m_vel.m_z = (float)v59 + (float)v58;
          this->m_vel.m_y = (float)v60 + (float)v61;
          v63 = v62;
          v64 = (float)((float)((float)v60 + (float)v61) * (float)((float)v5 * (float)0.1));
          v66 = (float)(this->m_pos.m_z + (float)((float)((float)v5 * (float)0.1) * (float)((float)v59 + (float)v58)));
          v65 = this->m_pos.m_x;
          v67 = (float)(this->m_pos.m_y + (float)v64);
          this->m_pos.m_z = v66;
          this->m_pos.m_y = v67;
          this->m_pos.m_x = (float)v65 + (float)((float)v63 * (float)((float)v5 * (float)0.1));
          v68 = this->m_vel.m_z;
          v69 = this->m_vel.m_y;
          v70 = (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v71 = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v72 = (float)(this->m_vel.m_x
                      + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          this->m_vel.m_x = this->m_vel.m_x
                          + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v73 = (float)((float)v69 + (float)v70);
          this->m_vel.m_y = (float)v69 + (float)v70;
          this->m_vel.m_z = (float)v71 + (float)v68;
          v74 = this->m_pos.m_z;
          v75 = this->m_pos.m_x;
          this->m_pos.m_y = this->m_pos.m_y + (float)((float)v73 * (float)((float)v5 * (float)0.1));
          this->m_pos.m_z = (float)v74 + (float)((float)((float)v5 * (float)0.1) * (float)((float)v71 + (float)v68));
          this->m_pos.m_x = (float)v75 + (float)((float)v72 * (float)((float)v5 * (float)0.1));
          v76 = (float)(this->m_vel.m_y
                      + (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          v77 = (float)(this->m_vel.m_x
                      + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          v78 = (float)((float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)))
                      + this->m_vel.m_z);
          this->m_vel.m_z = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)))
                          + this->m_vel.m_z;
          this->m_vel.m_y = v76;
          this->m_vel.m_x = v77;
          v80 = (float)((float)((float)v5 * (float)0.1) * (float)v78);
          v81 = (float)(this->m_pos.m_x + (float)((float)v77 * (float)((float)v5 * (float)0.1)));
          v79 = this->m_pos.m_y;
          this->m_pos.m_x = v81;
          this->m_pos.m_z = this->m_pos.m_z + (float)v80;
          this->m_pos.m_y = (float)v79 + (float)((float)v76 * (float)((float)v5 * (float)0.1));
          v82 = this->m_vel.m_y;
          v83 = this->m_vel.m_z;
          v84 = (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v85 = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v86 = (float)(this->m_vel.m_x
                      + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          this->m_vel.m_x = this->m_vel.m_x
                          + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          this->m_vel.m_y = (float)v82 + (float)v84;
          this->m_vel.m_z = (float)v85 + (float)v83;
          v87 = (float)((float)v86 * (float)((float)v5 * (float)0.1));
          v88 = this->m_pos.m_y;
          v89 = (float)((float)((float)v5 * (float)0.1) * (float)((float)v85 + (float)v83));
          v90 = this->m_pos.m_x;
          this->m_pos.m_z = this->m_pos.m_z + (float)v89;
          this->m_pos.m_x = (float)v90 + (float)v87;
          this->m_pos.m_y = (float)v88 + (float)((float)((float)v82 + (float)v84) * (float)((float)v5 * (float)0.1));
          v91 = this->m_vel.m_x;
          v92 = (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v93 = this->m_vel.m_y;
          v94 = (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v95 = (float)((float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)))
                      + this->m_vel.m_z);
          this->m_vel.m_z = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)))
                          + this->m_vel.m_z;
          this->m_vel.m_y = (float)v93 + (float)v94;
          this->m_vel.m_x = (float)v91 + (float)v92;
          v96 = this->m_pos.m_x;
          v98 = (float)(this->m_pos.m_y + (float)((float)((float)v93 + (float)v94) * (float)((float)v5 * (float)0.1)));
          v97 = this->m_pos.m_z;
          this->m_pos.m_y = v98;
          this->m_pos.m_x = (float)v96 + (float)((float)((float)v91 + (float)v92) * (float)((float)v5 * (float)0.1));
          this->m_pos.m_z = (float)v97 + (float)((float)((float)v5 * (float)0.1) * (float)v95);
          v99 = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v100 = this->m_vel.m_z;
          v101 = (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v102 = this->m_vel.m_x;
          v103 = (float)(this->m_vel.m_y
                       + (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          this->m_vel.m_y = this->m_vel.m_y
                          + (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          this->m_vel.m_z = (float)v99 + (float)v100;
          this->m_vel.m_x = (float)v102 + (float)v101;
          v104 = this->m_pos.m_z;
          v106 = (float)(this->m_pos.m_x + (float)((float)((float)v102 + (float)v101) * (float)((float)v5 * (float)0.1)));
          v105 = this->m_pos.m_y;
          this->m_pos.m_x = v106;
          this->m_pos.m_z = (float)v104 + (float)((float)((float)v5 * (float)0.1) * (float)((float)v99 + (float)v100));
          this->m_pos.m_y = (float)v105 + (float)((float)v103 * (float)((float)v5 * (float)0.1));
          v107 = this->m_vel.m_y;
          v108 = this->m_vel.m_z;
          v109 = (float)((float)v32 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v110 = (float)((float)v35 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          v111 = (float)(this->m_vel.m_x
                       + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1))));
          this->m_vel.m_x = this->m_vel.m_x
                          + (float)((float)v31 * (float)(this->m_gravity * (float)((float)v5 * (float)0.1)));
          this->m_vel.m_y = (float)v107 + (float)v109;
          this->m_vel.m_z = (float)v110 + (float)v108;
          this->m_pos.m_y = this->m_pos.m_y
                          + (float)((float)((float)v107 + (float)v109) * (float)((float)v5 * (float)0.1));
          v112 = (float)(this->m_pos.m_z + (float)((float)((float)v5 * (float)0.1) * (float)((float)v110 + (float)v108)));
          this->m_pos.m_x = this->m_pos.m_x + (float)((float)v111 * (float)((float)v5 * (float)0.1));
          this->m_pos.m_z = v112;
          return;
        }
        bfx::Slerper::Init(this: &this->m_slerper, _q1: &this->m_rot, _q2: &this->m_endQuat, _FP2: v27);
        v29 = MAIN_JUMP;
      }
      this->m_state = v29;
      goto LABEL_22;
    }
  }
}


// ========================================================================
// ?SetPos@JumperImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832B6738
// RVA : 0x012B6738
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::SetPos(bfx::JumperImpl *this, const bfx::Vec3 *pos)
{
  this->m_pos = *pos;
}


// ========================================================================
// ?SetRot@JumperImpl@bfx@@UAAXABVQuat@2@@Z
// EA  : 0x832B6758
// RVA : 0x012B6758
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::SetRot(bfx::JumperImpl *this, const bfx::Quat *rot)
{
  this->m_rot = *rot;
}


// ========================================================================
// ?SwapToDefaultJump@JumperImpl@bfx@@UAAXPBM@Z
// EA  : 0x832B6780
// RVA : 0x012B6780
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::SwapToDefaultJump(bfx::JumperImpl *this, const float *pInitialSpeed)
{
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r8
  bfx::HandleProxy *v6; // r11
  bfx::LinkBase *m_pTarget; // r7
  const float *v8; // r9
  bfx::HandleProxy *v9; // r11
  bfx::Matrix v10; // [sp+50h] [-A0h] BYREF
  _BYTE v11[72]; // [sp+90h] [-60h] BYREF

  this->GetMatrix(this, a2: (bfx::Matrix *)v11);
  bfx::Matrix::Build(this: &v10, q: &this->m_endQuat, pos: &this->m_endPos);
  this->SetCustomLinkMode(this, a2: false);
  m_pProxy = this->m_endArea.m_pProxy;
  if ( pInitialSpeed != nullptr )
  {
    if ( m_pProxy != nullptr )
      m_pArea = m_pProxy->m_pArea;
    else
      m_pArea = nullptr;
    v6 = this->m_link.m_pProxy;
    if ( v6 != nullptr )
      m_pTarget = (bfx::LinkBase *)v6->m_pTarget;
    else
      m_pTarget = nullptr;
    v8 = pInitialSpeed;
  }
  else
  {
    if ( m_pProxy != nullptr )
      m_pArea = m_pProxy->m_pArea;
    else
      m_pArea = nullptr;
    v9 = this->m_link.m_pProxy;
    if ( v9 != nullptr )
      m_pTarget = (bfx::LinkBase *)v9->m_pTarget;
    else
      m_pTarget = nullptr;
    v8 = nullptr;
  }
  this->Initialize(
    this,
    a2: (const bfx::Matrix *)v11,
    a3: &v10,
    a4: false,
    a5: m_pTarget,
    a6: m_pArea,
    a7: v8,
    a8: false);
  this->m_state = INITIAL_JUMP;
  this->m_firstFrame = false;
  this->m_curTime = 0.0;
}


// ========================================================================
// ?Initialize@JumperImpl@bfx@@UAAXABVMatrix@2@0_NPAVLinkBase@2@PAVArea@2@PBM1@Z
// EA  : 0x832B68B0
// RVA : 0x012B68B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::JumperImpl::Initialize(
        bfx::JumperImpl *this,
        const bfx::Matrix *startMat,
        const bfx::Matrix *endMat,
        bool startJumpFrozen,
        bfx::LinkBase *pLinkBase,
        bfx::Area *pEndArea,
        const float *pInitialJumpSpeed,
        bool bNeedToProbeEndPos)
{
  double m_x; // fp13
  double m_y; // fp12
  double m_z; // fp11
  double v19; // fp31
  double v20; // fp30
  double v21; // fp29
  bfx::Quat *v22; // r3
  double v23; // fp6
  double v24; // fp5
  const bfx::MotionState *m_commonState; // r11
  bfx::SpaceComponent **m_data; // r8
  unsigned int m_planLayer; // r11
  bfx::SpaceComponent_vtbl *v28; // r25
  unsigned __int64 v29; // r8 OVERLAPPED
  double Scale; // fp1
  double v31; // fp13
  double v32; // fp11
  double v33; // fp9
  const bfx::MotionState *v34; // r11
  double v35; // fp8
  double v36; // fp0
  double v37; // fp4
  double v38; // fp2
  double v39; // fp1
  double v40; // fp10
  double v41; // fp5
  double v42; // fp3
  double v43; // fp4
  double v46; // fp13
  const bfx::Quat *v47; // r3
  long double v48; // fp2
  bfx::LinkReservation *m_pLinkReservation; // r6
  bfx::LinkReservation *v50; // r3
  bfx::LinkReservation *v51; // r3
  bfx::Quat v52; // [sp+60h] [-120h] BYREF
  bfx::Vec3 v53; // [sp+70h] [-110h] BYREF
  bfx::Vec3 v54; // [sp+80h] [-100h] BYREF
  bfx::Vec3 v55; // [sp+90h] [-F0h] BYREF
  bfx::Vec3 v56; // [sp+A0h] [-E0h] BYREF
  bfx::Vec3 v57; // [sp+B0h] [-D0h] BYREF
  bfx::Quat v58; // [sp+C0h] [-C0h] BYREF
  bfx::Matrix v59; // [sp+D0h] [-B0h] BYREF

  bfx::Handle<bfx::MoverImpl>::operator=(this: &this->m_link, pTarget: pLinkBase);
  bfx::Handle<bfx::Area>::operator=(this: &this->m_endArea, pArea: pEndArea);
  bfx::Quat::Quat(this: &v52, m: startMat);
  m_x = v52.m_x;
  m_y = v52.m_y;
  m_z = v52.m_z;
  v19 = endMat->m_data[10];
  v20 = endMat->m_data[9];
  v21 = endMat->m_data[8];
  this->m_rot.m_w = v52.m_w;
  this->m_rot.m_x = m_x;
  this->m_rot.m_y = m_y;
  this->m_rot.m_z = m_z;
  bfx::Quat::Quat(this: &v58, m: endMat);
  this->m_endQuat = *v22;
  v23 = endMat->m_data[12];
  v24 = endMat->m_data[14];
  this->m_endPos.m_y = endMat->m_data[13];
  this->m_endPos.m_z = v24;
  this->m_endPos.m_x = v23;
  if ( bNeedToProbeEndPos )
  {
    m_commonState = this->m_commonState;
    m_data = m_commonState->m_pSpace->m_components.m_data;
    m_planLayer = m_commonState->m_pTune->m_planLayer;
    if ( m_planLayer >= 0x20 )
      v28 = nullptr;
    else
      v28 = m_data[1][m_planLayer + 2].__vftable;
    Scale = bfx::GetScale();
    if ( v28 != nullptr )
      Scale = *(float *)&v28->GetSpace;
    v31 = this->m_endPos.m_z;
    v32 = this->m_endPos.m_y;
    v33 = this->m_endPos.m_x;
    v34 = this->m_commonState;
    v56.m_z = this->m_endPos.m_z + (float)((float)v19 * (float)Scale);
    v56.m_y = (float)v32 + (float)((float)v20 * (float)Scale);
    v55.m_z = (float)v31 - (float)((float)v19 * (float)Scale);
    v55.m_y = (float)v32 - (float)((float)v20 * (float)Scale);
    v56.m_x = (float)v33 + (float)((float)v21 * (float)Scale);
    v55.m_x = (float)v33 - (float)((float)v21 * (float)Scale);
    *(unsigned __int64 *)((char *)&v29 + 4) = v34->m_pTune->m_proberTune.m_probeUserData;
    this->m_pProbeReq = bfx::CreateProbeReq(
                          pSpace: v34->m_pSpace,
                          startPos: &v56,
                          endPos: &v55,
                          referencePos: (const bfx::Vec3 *)HIDWORD(v34->m_pTune->m_proberTune.m_probeUserData),
                          probeUserData: v29);
  }
  bfx::SmartPath::SetStartData(this: this->m_commonState->m_pSmartPath, startPos: &this->m_endPos, pStartArea: pEndArea);
  bfx::JumperImpl::CalculateJumpDynamics(this, startMat, endMat, pInitialJumpSpeed);
  v35 = (float)(endMat->m_data[14] - startMat->m_data[14]);
  v36 = startMat->m_data[8];
  v37 = (float)(endMat->m_data[12] - startMat->m_data[12]);
  v38 = (float)(endMat->m_data[13] - startMat->m_data[13]);
  v39 = startMat->m_data[10];
  v57.m_x = startMat->m_data[8];
  v57.m_z = v39;
  v40 = startMat->m_data[9];
  v41 = (float)((float)((float)v37 * (float)v39) - (float)((float)v36 * (float)v35));
  v42 = (float)((float)(startMat->m_data[9] * (float)v35) - (float)((float)v38 * (float)v39));
  v43 = (float)((float)((float)v36 * (float)v38) - (float)(startMat->m_data[9] * (float)v37));
  _FP6 = (float)((float)__fsqrts((float)((float)((float)v43 * (float)v43)
                                       + (float)((float)((float)v42 * (float)v42) + (float)((float)v41 * (float)v41))))
               - (float)1.0842022e-19);
  __asm { fsel      f12, f6, f2, f11 }
  v46 = (float)((float)((float)(startMat->m_data[9] * (float)v35) - (float)((float)v38 * (float)v39)) * (float)_FP12);
  v57.m_y = startMat->m_data[9];
  v53.m_x = (float)((float)((float)v40 * (float)v35) - (float)((float)v38 * (float)v39)) * (float)_FP12;
  v53.m_y = (float)v41 * (float)_FP12;
  v53.m_z = (float)v43 * (float)_FP12;
  v54.m_y = (float)(v53.m_z * (float)v36) - (float)(v53.m_x * (float)v39);
  v54.m_z = (float)((float)v46 * (float)v40) - (float)(v53.m_y * (float)v36);
  v54.m_x = (float)(v53.m_y * (float)v39) - (float)(v53.m_z * (float)v40);
  bfx::Matrix::Build(this: &v59, xAxis: &v54, yAxis: &v53, zAxis: &v57, trans: &bfx::ZERO_VEC);
  bfx::Quat::Quat(this: &v58, m: &v59);
  bfx::Slerper::Init(this: &this->m_slerper, _q1: &v52, _q2: v47, _FP2: v48);
  m_pLinkReservation = this->m_pLinkReservation;
  this->m_frozenAtStart = startJumpFrozen;
  if ( m_pLinkReservation == nullptr )
  {
    v50 = (bfx::LinkReservation *)bfx::MemoryManager::Malloc(
                                    this: bfx::g_pCurInstance->m_pMemoryManager,
                                    size: 0x14u,
                                    tag: bfx::MEM_BFXNAVIGATOR);
    if ( v50 != nullptr )
      v51 = bfx::LinkReservation::LinkReservation(this: v50, (bfx::Space *)pLinkBase, type: INTERNAL_LINK_RESERVATION);
    else
      v51 = nullptr;
    this->m_pLinkReservation = v51;
  }
}


// ========================================================================
// __unwind$85535
// EA  : 0x832B6BE8
// RVA : 0x012B6BE8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_85535()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 384 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??0JumperImpl@bfx@@QAA@ABVMatrix@1@ABVMotionState@1@@Z
// EA  : 0x832B6C20
// RVA : 0x012B6C20
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

bfx::JumperImpl *__fastcall bfx::JumperImpl::JumperImpl(
        bfx::JumperImpl *this,
        const bfx::Matrix *startMat,
        const bfx::MotionState *commonState)
{
  double m_x; // fp12
  double m_y; // fp11
  double m_z; // fp10
  double v8; // fp9
  double v9; // fp8
  bfx::Quat v11; // [sp+60h] [-40h] BYREF

  this->m_commonState = commonState;
  this->m_pLinkReservation = nullptr;
  this->__vftable = (bfx::JumperImpl_vtbl *)&bfx::JumperImpl::`vftable';
  this->m_link.m_pProxy = nullptr;
  this->m_endArea.m_pProxy = nullptr;
  this->m_pProbeReq = nullptr;
  this->m_pTune = &commonState->m_pTune->m_jumperTune;
  bfx::Quat::Quat(this: &v11, m: startMat);
  m_x = v11.m_x;
  m_y = v11.m_y;
  m_z = v11.m_z;
  this->m_rot.m_w = v11.m_w;
  this->m_rot.m_x = m_x;
  this->m_rot.m_y = m_y;
  this->m_rot.m_z = m_z;
  v8 = startMat->m_data[12];
  v9 = startMat->m_data[14];
  this->m_pos.m_y = startMat->m_data[13];
  this->m_pos.m_z = v9;
  this->m_pos.m_x = v8;
  this->m_state = INITIAL_JUMP;
  this->m_curTime = 0.0;
  this->m_firstFrame = true;
  this->m_customLink = false;
  return this;
}


// ========================================================================
// __unwind$85783
// EA  : 0x832B6CF4
// RVA : 0x012B6CF4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_85783()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$85784
// EA  : 0x832B6D1C
// RVA : 0x012B6D1C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_85784()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 160 + 180) + 164));
}


// ========================================================================
// __unwind$85785
// EA  : 0x832B6D48
// RVA : 0x012B6D48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_85785()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 160 + 180) + 168));
}


// ========================================================================
// ?ReachedGoal@JumperImpl@bfx@@UBA_NXZ
// EA  : 0x832B6D78
// RVA : 0x012B6D78
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

BOOL __fastcall bfx::JumperImpl::ReachedGoal(bfx::JumperImpl *this)
{
  return (_cntlzw(this->m_state - 2) & 0x20) != 0;
}


// ========================================================================
// ?GetJumpTimeRemaining@JumperImpl@bfx@@UBAMXZ
// EA  : 0x832B6D90
// RVA : 0x012B6D90
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

float __fastcall bfx::JumperImpl::GetJumpTimeRemaining(bfx::JumperImpl *this)
{
  double v1; // fp1

  v1 = (float)(this->m_totalJumpTime - this->m_curTime);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?IsFrozenAtStart@JumperImpl@bfx@@UAA_NXZ
// EA  : 0x832B6DA0
// RVA : 0x012B6DA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

BOOL __fastcall bfx::JumperImpl::IsFrozenAtStart(bfx::JumperImpl *this)
{
  return this->m_frozenAtStart;
}


// ========================================================================
// ?GetPos@JumperImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832B6DA8
// RVA : 0x012B6DA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

bfx::JumperImpl *__fastcall bfx::JumperImpl::GetPos(bfx::JumperImpl *this, bfx::Vec3 *result)
{
  float m_y; // r10
  float m_z; // r9

  m_y = result[8].m_y;
  m_z = result[8].m_z;
  this->__vftable = (bfx::JumperImpl_vtbl *)LODWORD(result[8].m_x);
  *(float *)&this->m_pTune = m_y;
  *(float *)&this->m_commonState = m_z;
  return this;
}


// ========================================================================
// ?GetMatrix@JumperImpl@bfx@@UBAXAAVMatrix@2@@Z
// EA  : 0x832B6DC8
// RVA : 0x012B6DC8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::GetMatrix(bfx::JumperImpl *this, bfx::Matrix *mat)
{
  bfx::Vec3 v4; // [sp+50h] [-70h] BYREF
  bfx::Matrix v5; // [sp+60h] [-60h] BYREF

  v4.m_x = 0.0;
  v4.m_y = 0.0;
  v4.m_z = 0.0;
  bfx::Matrix::Build(this: &v5, q: &this->m_rot, pos: &v4);
  *mat = v5;
  *(bfx::Vec3 *)&mat->m_data[12] = this->m_pos;
}


// ========================================================================
// ?GetDesiredVel@JumperImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832B6E48
// RVA : 0x012B6E48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

bfx::JumperImpl *__fastcall bfx::JumperImpl::GetDesiredVel(bfx::JumperImpl *this, bfx::Vec3 *result)
{
  float m_z; // r10
  float m_x; // r9

  m_z = result[11].m_z;
  m_x = result[12].m_x;
  this->__vftable = (bfx::JumperImpl_vtbl *)LODWORD(result[11].m_y);
  *(float *)&this->m_pTune = m_z;
  *(float *)&this->m_commonState = m_x;
  return this;
}


// ========================================================================
// ?SetCustomLinkMode@JumperImpl@bfx@@UAAX_N@Z
// EA  : 0x832B6E68
// RVA : 0x012B6E68
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::SetCustomLinkMode(bfx::JumperImpl *this, bool bCustom)
{
  this->m_customLink = bCustom;
  this->m_frozenAtStart = bCustom;
}


// ========================================================================
// ?IsCustomLinkMode@JumperImpl@bfx@@UAA_NXZ
// EA  : 0x832B6E78
// RVA : 0x012B6E78
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

BOOL __fastcall bfx::JumperImpl::IsCustomLinkMode(bfx::JumperImpl *this)
{
  return this->m_customLink;
}


// ========================================================================
// ??1JumperImpl@bfx@@UAA@XZ
// EA  : 0x832B6E88
// RVA : 0x012B6E88
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void __fastcall bfx::JumperImpl::~JumperImpl(bfx::JumperImpl *this)
{
  bfx::LinkReservation *m_pLinkReservation; // r3
  bfx::ProbeReq *m_pProbeReq; // r3
  bfx::HandleProxy *m_pProxy; // r3

  this->__vftable = (bfx::JumperImpl_vtbl *)&bfx::JumperImpl::`vftable';
  m_pLinkReservation = this->m_pLinkReservation;
  if ( m_pLinkReservation != nullptr )
    ((void (__fastcall *)(bfx::LinkReservation *, int))m_pLinkReservation->dtr_HandleTargetBase)(
      a1: m_pLinkReservation,
      a2: 1);
  m_pProbeReq = this->m_pProbeReq;
  this->m_pLinkReservation = nullptr;
  if ( m_pProbeReq != nullptr )
  {
    bfx::DestroyProbeReq(pProbeReq: m_pProbeReq);
    this->m_pProbeReq = nullptr;
  }
  bfx::Handle<bfx::Area>::Release(this: &this->m_endArea);
  m_pProxy = this->m_link.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_link.m_pProxy = nullptr;
  }
  this->__vftable = (bfx::JumperImpl_vtbl *)&bfx::MotionBase::`vftable';
}


// ========================================================================
// __unwind$85950
// EA  : 0x832B6F1C
// RVA : 0x012B6F1C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_85950()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$85951
// EA  : 0x832B6F44
// RVA : 0x012B6F44
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_85951()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$85952
// EA  : 0x832B6F70
// RVA : 0x012B6F70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_85952()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 128 + 148) + 168));
}


// ========================================================================
// ?CreateJumper@bfx@@YAPAVJumper@1@ABVMatrix@1@ABVMotionState@1@@Z
// EA  : 0x832B6FA8
// RVA : 0x012B6FA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

bfx::JumperImpl *__fastcall bfx::CreateJumper(const bfx::Matrix *startMat, const bfx::MotionState *commonState)
{
  bfx::JumperImpl *v4; // r3

  v4 = (bfx::JumperImpl *)bfx::MemoryManager::Malloc(
                            this: bfx::g_pCurInstance->m_pMemoryManager,
                            size: 0xB0u,
                            tag: bfx::MEM_BFXMOVER);
  if ( v4 != nullptr )
    return bfx::JumperImpl::JumperImpl(this: v4, startMat, commonState);
  else
    return nullptr;
}


// ========================================================================
// __unwind$86012
// EA  : 0x832B7004
// RVA : 0x012B7004
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxjumper.cpp
// ========================================================================

void _unwind_86012()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}

