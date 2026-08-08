
// ========================================================================
// ?ProbeToFindGround_Internal@bfx@@YA_NPAVNavLayer@1@ABVCollideData@1@ABVVec3@1@2AAM@Z
// EA  : 0x832CAAF8
// RVA : 0x012CAAF8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

int __fastcall bfx::ProbeToFindGround_Internal(
        bfx::NavLayer *pNavLayer,
        const bfx::CollideData *data,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis,
        float *heightOut)
{
  double Scale; // fp31
  bfx::Space *m_pSpace; // r29
  double m_x; // fp13
  double m_y; // fp12
  double m_z; // fp10
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  double v18; // fp4
  double v19; // fp2
  double v21; // fp10
  double v22; // fp9
  double v23; // fp7
  double v24; // fp6
  double v25; // fp5
  double v26; // fp4
  double v27; // fp2
  bfx::Vec3 v28; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v29; // [sp+60h] [-70h] BYREF
  bfx::Vec3 v30; // [sp+70h] [-60h] BYREF
  bfx::Vec3 v31; // [sp+80h] [-50h] BYREF

  if ( !bfx::g_probeForGround )
    return 0;
  Scale = bfx::GetScale();
  if ( pNavLayer != nullptr )
  {
    Scale = pNavLayer->m_shapeDat.m_height;
    m_pSpace = pNavLayer->m_pSpace;
  }
  else
  {
    m_pSpace = nullptr;
  }
  m_x = localUpAxis->m_x;
  m_y = localUpAxis->m_y;
  m_z = localUpAxis->m_z;
  v15 = (float)(localUpAxis->m_z * (float)Scale);
  v16 = surferPos->m_x;
  v17 = surferPos->m_y;
  v18 = surferPos->m_z;
  v19 = (float)(surferPos->m_y - (float)(localUpAxis->m_y * (float)Scale));
  v28.m_x = surferPos->m_x - (float)(localUpAxis->m_x * (float)Scale);
  v28.m_y = v19;
  v28.m_z = (float)v18 - (float)v15;
  v31.m_x = (float)v16 + (float)((float)m_x * (float)((float)Scale * (float)0.75));
  v31.m_y = (float)v17 + (float)((float)m_y * (float)((float)Scale * (float)0.75));
  v31.m_z = (float)v18 + (float)((float)m_z * (float)((float)Scale * (float)0.75));
  if ( (unsigned __int8)bfx::CollideLineSegmentAndWorld(pSpace: m_pSpace, data, start: &v31, end: &v28) != 0 )
  {
    *heightOut = (float)(localUpAxis->m_x * (float)(v28.m_x - surferPos->m_x))
               + (float)((float)(localUpAxis->m_z * (float)(v28.m_z - surferPos->m_z))
                       + (float)(localUpAxis->m_y * (float)(v28.m_y - surferPos->m_y)));
    return 1;
  }
  v21 = surferPos->m_x;
  v22 = surferPos->m_y;
  v23 = surferPos->m_z;
  v24 = (float)(localUpAxis->m_x * (float)((float)Scale * (float)4.0));
  v25 = (float)(localUpAxis->m_y * (float)((float)Scale * (float)4.0));
  v26 = (float)(localUpAxis->m_z * (float)((float)Scale * (float)4.0));
  v27 = (float)(surferPos->m_y + (float)(localUpAxis->m_y * (float)((float)Scale * (float)4.0)));
  v30.m_x = surferPos->m_x + (float)(localUpAxis->m_x * (float)((float)Scale * (float)4.0));
  v30.m_y = v27;
  v30.m_z = (float)v23 + (float)v26;
  v29.m_x = (float)v21 - (float)v24;
  v29.m_y = (float)v22 - (float)v25;
  v29.m_z = (float)v23 - (float)v26;
  bfx::CollideLineSegmentAndWorld(pSpace: m_pSpace, data, start: surferPos, end: &v30);
  if ( (unsigned __int8)bfx::CollideLineSegmentAndWorld(pSpace: m_pSpace, data, start: &v30, end: &v29) == 0 )
    return 0;
  *heightOut = (float)(localUpAxis->m_x * (float)(v29.m_x - surferPos->m_x))
             + (float)((float)(localUpAxis->m_z * (float)(v29.m_z - surferPos->m_z))
                     + (float)(localUpAxis->m_y * (float)(v29.m_y - surferPos->m_y)));
  return 1;
}


// ========================================================================
// ?ProbeToFindGround@Prober@bfx@@QAA_NPAVNavLayer@2@ABVVec3@2@1AAM@Z
// EA  : 0x832CAD20
// RVA : 0x012CAD20
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

BOOL __fastcall bfx::Prober::ProbeToFindGround(
        bfx::Prober *this,
        bfx::NavLayer *pNavLayer,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis,
        float *heightOut)
{
  int Ground_Internal; // r29
  BOOL result; // r3
  bfx::CollideData v12; // [sp+50h] [-50h] BYREF
  bfx::GroundProbeReplayData v13; // [sp+58h] [-48h] BYREF

  if ( bfx::IsReplayPlaybackEnabled() )
  {
    v13.m_replayID = 0;
    v13.m_collided = false;
    v13.m_height = 0.0;
    if ( (unsigned __int8)bfx::ProcessGroundProbeReplayEvent(groundProbeReplayData: &v13) != 0
      && v13.m_replayID == this->m_proberID )
    {
      result = v13.m_collided;
      *heightOut = v13.m_height;
    }
    else
    {
      return false;
    }
  }
  else
  {
    v12.m_probeUserData = this->m_probeUserData;
    Ground_Internal = bfx::ProbeToFindGround_Internal(pNavLayer, data: &v12, surferPos, localUpAxis, heightOut);
    bfx::LogMoverGroundProbe(replayID: this->m_proberID, collided: Ground_Internal, height: *heightOut);
    return Ground_Internal;
  }
  return result;
}


// ========================================================================
// ?RequestDownwardsProbe@Prober@bfx@@AAAXPAVNavLayer@2@ABVVec3@2@1@Z
// EA  : 0x832CADF0
// RVA : 0x012CADF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::Prober::RequestDownwardsProbe(
        bfx::Prober *this,
        bfx::NavLayer *pNavLayer,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis)
{
  unsigned __int64 v8; // r8 OVERLAPPED
  double Scale; // fp1
  double v10; // fp12
  double v11; // fp10
  double v12; // fp9
  double m_x; // fp8
  double m_y; // fp7
  double m_z; // fp6
  double v16; // fp4
  bfx::Space *m_pSpace; // r3
  bfx::Vec3 v18; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v19; // [sp+60h] [-40h] BYREF

  if ( this->m_pProbeReq == nullptr )
  {
    Scale = bfx::GetScale();
    if ( pNavLayer != nullptr )
      Scale = pNavLayer->m_shapeDat.m_height;
    v10 = (float)(localUpAxis->m_x * (float)Scale);
    v11 = (float)(localUpAxis->m_y * (float)Scale);
    v12 = (float)(localUpAxis->m_z * (float)Scale);
    m_x = surferPos->m_x;
    m_y = surferPos->m_y;
    m_z = surferPos->m_z;
    v16 = (float)(surferPos->m_y + (float)(localUpAxis->m_y * (float)Scale));
    v19.m_x = surferPos->m_x + (float)(localUpAxis->m_x * (float)Scale);
    v19.m_y = v16;
    v19.m_z = (float)m_z + (float)v12;
    v18.m_x = (float)m_x - (float)v10;
    v18.m_y = (float)m_y - (float)v11;
    v18.m_z = (float)m_z - (float)v12;
    if ( pNavLayer != nullptr )
      m_pSpace = pNavLayer->m_pSpace;
    else
      m_pSpace = nullptr;
    *(unsigned __int64 *)((char *)&v8 + 4) = this->m_probeUserData;
    this->m_pProbeReq = bfx::CreateProbeReq(
                          pSpace: m_pSpace,
                          startPos: &v19,
                          endPos: &v18,
                          referencePos: (const bfx::Vec3 *)HIDWORD(this->m_probeUserData),
                          probeUserData: v8);
  }
}


// ========================================================================
// ??0Prober@bfx@@QAA@M_K@Z
// EA  : 0x832CAEB0
// RVA : 0x012CAEB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::Prober *__fastcall bfx::Prober::Prober(
        bfx::Prober *this,
        double probeInterval,
        int a3,
        unsigned __int64 probeUserData)
{
  bfx::InstanceComponent *v4; // r7
  unsigned int v5; // r11

  this->m_probeInterval = probeInterval;
  this->m_state = PROBE_WAITING_FOR_TIMER;
  this->m_probeTimer = 0.0;
  this->m_heightRate = 0.0;
  this->m_pos3DOffset.m_x = 0.0;
  this->m_pos3DOffset.m_y = 0.0;
  this->m_pos3DOffset.m_z = 0.0;
  this->m_pProbeReq = nullptr;
  this->m_probeUserData = *(unsigned __int64 *)((char *)&probeUserData + 4);
  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[4];
  v5 = (unsigned int)&v4[6].dtr_InstanceComponent + 1;
  v4[6].__vftable = (bfx::InstanceComponent_vtbl *)v5;
  this->m_proberID = v5;
  return this;
}


// ========================================================================
// ??1Prober@bfx@@QAA@XZ
// EA  : 0x832CAF08
// RVA : 0x012CAF08
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __fastcall bfx::Prober::~Prober(bfx::Prober *this)
{
  bfx::DestroyProbeReq(pProbeReq: this->m_pProbeReq);
  this->m_pProbeReq = nullptr;
}


// ========================================================================
// ?TeleportToArea@Prober@bfx@@QAAXPAVNavLayer@2@ABVVec3@2@1@Z
// EA  : 0x832CAF40
// RVA : 0x012CAF40
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __fastcall bfx::Prober::TeleportToArea(
        bfx::Prober *this,
        bfx::NavLayer *pNavLayer,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis)
{
  double m_y; // fp12
  double m_z; // fp11
  double v8; // fp0
  float v9[2]; // [sp+50h] [-20h] BYREF

  if ( pNavLayer != nullptr )
  {
    if ( bfx::Prober::ProbeToFindGround(this, pNavLayer, surferPos, localUpAxis, heightOut: v9) )
    {
      m_y = localUpAxis->m_y;
      m_z = localUpAxis->m_z;
      v8 = v9[0];
      this->m_pos3DOffset.m_x = localUpAxis->m_x * v9[0];
      this->m_pos3DOffset.m_y = (float)m_y * (float)v8;
      this->m_pos3DOffset.m_z = (float)m_z * (float)v8;
    }
    if ( this->m_state == PROBE_WAITING_FOR_DOWN_PROBE )
    {
      bfx::DestroyProbeReq(pProbeReq: this->m_pProbeReq);
      this->m_pProbeReq = nullptr;
      this->m_state = PROBE_WAITING_FOR_TIMER;
      this->m_probeTimer = 0.0;
    }
  }
}


// ========================================================================
// ?SetHeight@Prober@bfx@@QAAXABVVec3@2@00@Z
// EA  : 0x832CAFE8
// RVA : 0x012CAFE8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __fastcall bfx::Prober::SetHeight(
        bfx::Prober *this,
        const bfx::Vec3 *actualPos,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis)
{
  double m_x; // fp7
  double m_z; // fp3
  double v7; // fp0

  m_x = localUpAxis->m_x;
  m_z = localUpAxis->m_z;
  v7 = (float)((float)(localUpAxis->m_z * (float)(actualPos->m_z - surferPos->m_z))
             + (float)((float)(localUpAxis->m_x * (float)(actualPos->m_x - surferPos->m_x))
                     + (float)(localUpAxis->m_y * (float)(actualPos->m_y - surferPos->m_y))));
  this->m_pos3DOffset.m_y = localUpAxis->m_y
                          * (float)((float)(localUpAxis->m_z * (float)(actualPos->m_z - surferPos->m_z))
                                  + (float)((float)(localUpAxis->m_x * (float)(actualPos->m_x - surferPos->m_x))
                                          + (float)(localUpAxis->m_y * (float)(actualPos->m_y - surferPos->m_y))));
  this->m_pos3DOffset.m_x = (float)m_x * (float)v7;
  this->m_pos3DOffset.m_z = (float)m_z * (float)v7;
  if ( this->m_state == PROBE_WAITING_FOR_DOWN_PROBE )
  {
    bfx::DestroyProbeReq(pProbeReq: this->m_pProbeReq);
    this->m_pProbeReq = nullptr;
    this->m_state = PROBE_WAITING_FOR_TIMER;
    this->m_probeTimer = 0.0;
  }
}


// ========================================================================
// ?MovedOntoArea@Prober@bfx@@QAAXABVVec3@2@PAVArea@2@010@Z
// EA  : 0x832CB090
// RVA : 0x012CB090
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __fastcall bfx::Prober::MovedOntoArea(
        bfx::Prober *this,
        const bfx::Vec3 *oldPos,
        bfx::Area *__formal,
        const bfx::Vec3 *newPos,
        bfx::Area *a5,
        const bfx::Vec3 *a6)
{
  double v6; // fp8
  double v7; // fp6
  double m_y; // fp4
  double m_z; // fp3

  v6 = (float)(newPos->m_y - oldPos->m_y);
  v7 = (float)(newPos->m_z - oldPos->m_z);
  m_y = this->m_pos3DOffset.m_y;
  m_z = this->m_pos3DOffset.m_z;
  this->m_pos3DOffset.m_x = this->m_pos3DOffset.m_x - (float)(newPos->m_x - oldPos->m_x);
  this->m_pos3DOffset.m_y = (float)m_y - (float)v6;
  this->m_pos3DOffset.m_z = (float)m_z - (float)v7;
}


// ========================================================================
// ?ImmediateProbeUpdate@Prober@bfx@@AAAXPAVNavLayer@2@ABVVec3@2@1M@Z
// EA  : 0x832CB0E0
// RVA : 0x012CB0E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __fastcall bfx::Prober::ImmediateProbeUpdate(
        bfx::Prober *this,
        bfx::NavLayer *pNavLayer,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis,
        double simTime)
{
  double v5; // fp13
  double m_probeInterval; // fp12
  __int64 v10; // r9
  __int64 v11; // [sp+50h] [-30h] BYREF

  v5 = (float)(this->m_probeTimer - (float)simTime);
  this->m_probeTimer = this->m_probeTimer - (float)simTime;
  if ( v5 <= 0.0 )
  {
    m_probeInterval = this->m_probeInterval;
    HIDWORD(v10) = byte_821B0000;
    LODWORD(v10) = this->m_proberID % 0xA;
    v11 = v10;
    this->m_probeTimer = (float)((float)((float)((float)v10 * (float)0.1) * (float)m_probeInterval) * (float)0.2)
                       + (float)m_probeInterval;
    if ( bfx::Prober::ProbeToFindGround(this, pNavLayer, surferPos, localUpAxis, heightOut: (float *)&v11) )
      this->m_heightRate = (float)((float)(localUpAxis->m_x
                                         * (float)((float)(surferPos->m_x + (float)(localUpAxis->m_x * *(float *)&v11))
                                                 - (float)(this->m_pos3DOffset.m_x + surferPos->m_x)))
                                 + (float)((float)(localUpAxis->m_z
                                                 * (float)((float)(surferPos->m_z
                                                                 + (float)(localUpAxis->m_z * *(float *)&v11))
                                                         - (float)(this->m_pos3DOffset.m_z + surferPos->m_z)))
                                         + (float)(localUpAxis->m_y
                                                 * (float)((float)(surferPos->m_y
                                                                 + (float)(localUpAxis->m_y * *(float *)&v11))
                                                         - (float)(this->m_pos3DOffset.m_y + surferPos->m_y)))))
                         / this->m_probeTimer;
    else
      this->m_heightRate = (float)((float)(this->m_pos3DOffset.m_x * localUpAxis->m_x)
                                 + (float)((float)(this->m_pos3DOffset.m_z * localUpAxis->m_z)
                                         + (float)(this->m_pos3DOffset.m_y * localUpAxis->m_y)))
                         * (float)-0.1;
  }
}


// ========================================================================
// ?RequestedProbeUpdate@Prober@bfx@@AAAXPAVNavLayer@2@ABVVec3@2@1M@Z
// EA  : 0x832CB240
// RVA : 0x012CB240
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __fastcall bfx::Prober::RequestedProbeUpdate(
        bfx::Prober *this,
        bfx::NavLayer *pNavLayer,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis,
        double simTime)
{
  double v6; // fp13
  bfx::ProbeState v7; // r11
  bfx::ProbeReq *m_pProbeReq; // r30
  __int64 v9; // r9
  double v10; // fp0
  double v11; // fp5

  if ( bfx::g_probeForGround )
  {
    if ( this->m_state == PROBE_WAITING_FOR_TIMER )
    {
      v6 = (float)(this->m_probeTimer - (float)simTime);
      this->m_probeTimer = this->m_probeTimer - (float)simTime;
      if ( v6 > 0.0 )
        return;
      bfx::Prober::RequestDownwardsProbe(this, pNavLayer, surferPos, localUpAxis);
      this->m_heightRate = 0.0;
      v7 = PROBE_WAITING_FOR_DOWN_PROBE;
      goto LABEL_12;
    }
    if ( this->m_state == PROBE_WAITING_FOR_DOWN_PROBE )
    {
      m_pProbeReq = this->m_pProbeReq;
      if ( m_pProbeReq != nullptr && m_pProbeReq->m_probeResultsValid )
      {
        HIDWORD(v9) = byte_821B0000;
        LODWORD(v9) = this->m_proberID % 0xA;
        v10 = (float)((float)((float)((float)((float)v9 * (float)0.1) * this->m_probeInterval) * (float)0.2)
                    + this->m_probeInterval);
        this->m_probeTimer = (float)((float)((float)((float)v9 * (float)0.1) * this->m_probeInterval) * (float)0.2)
                           + this->m_probeInterval;
        if ( m_pProbeReq->m_collided )
          v11 = (float)((float)((float)(localUpAxis->m_x
                                      * (float)(m_pProbeReq->m_collidePos.m_x
                                              - (float)(m_pProbeReq->m_referencePos.m_x + this->m_pos3DOffset.m_x)))
                              + (float)((float)(localUpAxis->m_z
                                              * (float)(m_pProbeReq->m_collidePos.m_z
                                                      - (float)(this->m_pos3DOffset.m_z + m_pProbeReq->m_referencePos.m_z)))
                                      + (float)(localUpAxis->m_y
                                              * (float)(m_pProbeReq->m_collidePos.m_y
                                                      - (float)(this->m_pos3DOffset.m_y + m_pProbeReq->m_referencePos.m_y)))))
                      / (float)v10);
        else
          v11 = (float)((float)((float)(localUpAxis->m_x * this->m_pos3DOffset.m_x)
                              + (float)((float)(this->m_pos3DOffset.m_z * localUpAxis->m_z)
                                      + (float)(this->m_pos3DOffset.m_y * localUpAxis->m_y)))
                      * (float)-0.1);
        this->m_heightRate = v11;
        bfx::ProbeReq::~ProbeReq(this: m_pProbeReq);
        bfx::ProbeReq::operator delete(mem: (bfx::Pool::Node *)m_pProbeReq);
        v7 = PROBE_WAITING_FOR_TIMER;
        this->m_pProbeReq = nullptr;
LABEL_12:
        this->m_state = v7;
      }
    }
  }
}


// ========================================================================
// ?Simulate@Prober@bfx@@QAAXPAVNavLayer@2@ABVVec3@2@1M@Z
// EA  : 0x832CB3F8
// RVA : 0x012CB3F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __fastcall bfx::Prober::Simulate(
        bfx::Prober *this,
        bfx::NavLayer *pNavLayer,
        const bfx::Vec3 *surferPos,
        const bfx::Vec3 *localUpAxis,
        double simTime)
{
  double m_heightRate; // fp9
  bfx::Vec3 *p_m_pos3DOffset; // r31
  double m_y; // fp4
  double m_z; // fp2
  double v20; // fp13
  double v21; // fp12
  double v22; // fp11
  double v23; // fp9
  double v24; // fp2
  double v25; // fp30
  double v26; // fp29
  double v27; // fp28
  double v28; // fp0
  double v29; // fp12
  double v30; // fp13
  double v31; // fp8
  double v32; // fp7

  if ( bfx::AreBatchProbeRequestsEnabled() )
    bfx::Prober::RequestedProbeUpdate(this, pNavLayer, surferPos, localUpAxis, simTime);
  else
    bfx::Prober::ImmediateProbeUpdate(this, pNavLayer, surferPos, localUpAxis, simTime);
  _FP10 = (float)((float)simTime - this->m_probeTimer);
  m_heightRate = this->m_heightRate;
  p_m_pos3DOffset = &this->m_pos3DOffset;
  m_y = p_m_pos3DOffset->m_y;
  __asm { fsel      f3, f10, f11, f31 }
  m_z = p_m_pos3DOffset->m_z;
  _FP1 = -_FP3;
  _FP0 = (float)((float)3.4028235e38 - (float)_FP3);
  __asm { fsel      f13, f1, f13, f3 }
  __asm { fsel      f10, f0, f11, f12 }
  v20 = (float)(localUpAxis->m_y * (float)((float)_FP10 * (float)m_heightRate));
  v21 = (float)((float)((float)_FP10 * (float)m_heightRate) * localUpAxis->m_z);
  v22 = (float)(p_m_pos3DOffset->m_x + (float)(localUpAxis->m_x * (float)((float)_FP10 * (float)m_heightRate)));
  p_m_pos3DOffset->m_x = p_m_pos3DOffset->m_x + (float)(localUpAxis->m_x * (float)((float)_FP10 * (float)m_heightRate));
  p_m_pos3DOffset->m_y = (float)m_y + (float)v20;
  v23 = (float)((float)m_z + (float)v21);
  p_m_pos3DOffset->m_z = (float)m_z + (float)v21;
  v24 = (float)((float)((float)m_z + (float)v21) * localUpAxis->m_z);
  v25 = (float)((float)v22
              - (float)(localUpAxis->m_x
                      * (float)((float)((float)v22 * localUpAxis->m_x)
                              + (float)((float)((float)((float)m_y + (float)v20) * localUpAxis->m_y) + (float)v24))));
  v26 = (float)((float)((float)m_y + (float)v20)
              - (float)(localUpAxis->m_y
                      * (float)((float)((float)v22 * localUpAxis->m_x)
                              + (float)((float)((float)((float)m_y + (float)v20) * localUpAxis->m_y) + (float)v24))));
  v27 = (float)((float)v23
              - (float)(localUpAxis->m_z
                      * (float)((float)((float)v22 * localUpAxis->m_x)
                              + (float)((float)((float)((float)m_y + (float)v20) * localUpAxis->m_y) + (float)v24))));
  v28 = (float)(bfx::GetScale() * (float)simTime);
  v29 = (float)((float)((float)v25 * (float)v25)
              + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26)));
  v30 = __fsqrts(v29);
  if ( v28 > v30 || (v30 = -v30, v28 < v30) )
    v28 = v30;
  v31 = p_m_pos3DOffset->m_y;
  v32 = p_m_pos3DOffset->m_z;
  _FP6 = (float)((float)__fsqrts(v29) - 1.0842022e-19);
  __asm { fsel      f3, f6, f5, f11 }
  p_m_pos3DOffset->m_x = p_m_pos3DOffset->m_x + (float)((float)((float)_FP3 * (float)v25) * (float)-v28);
  p_m_pos3DOffset->m_y = (float)v31 + (float)((float)((float)v26 * (float)_FP3) * (float)-v28);
  p_m_pos3DOffset->m_z = (float)v32 + (float)((float)((float)v27 * (float)_FP3) * (float)-v28);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_probeForGroundRestore''
// EA  : 0x833994A0
// RVA : 0x013994A0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_probeForGroundRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_probeForGroundRestore);
  bfx::g_probeForGroundRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_probeForGroundRestore.m_targetBool = &bfx::g_probeForGround;
  bfx::g_probeForGroundRestore.m_name = "probe_for_ground";
  bfx::g_probeForGroundRestore.m_defaultBool = bfx::g_probeForGround;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_probeForGroundRestore__);
}

