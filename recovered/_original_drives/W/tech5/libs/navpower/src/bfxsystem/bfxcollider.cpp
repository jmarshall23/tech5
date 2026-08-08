
// ========================================================================
// ??3ProbeReq@bfx@@SAXPAX@Z
// EA  : 0x83255DA8
// RVA : 0x01255DA8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::ProbeReq::operator delete(bfx::Pool::Node *mem)
{
  bfx::Pool *m_pProbeRequestPool; // r9

  m_pProbeRequestPool = bfx::g_pCurInstance->m_pColliderManager->m_pProbeRequestPool;
  mem->m_pNext = m_pProbeRequestPool->m_data.m_pUnused;
  m_pProbeRequestPool->m_data.m_pUnused = mem;
}


// ========================================================================
// ?AreBatchProbeRequestsEnabled@bfx@@YA_NXZ
// EA  : 0x83255DC8
// RVA : 0x01255DC8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

BOOL __fastcall bfx::AreBatchProbeRequestsEnabled()
{
  return bfx::g_pCurInstance->m_pColliderManager->m_enableBatchProbeRequests;
}


// ========================================================================
// ?IsColliderSet@bfx@@YA_NXZ
// EA  : 0x83255DE0
// RVA : 0x01255DE0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::IsColliderSet()
{
  bfx::ColliderManager *m_pColliderManager; // r11
  int result; // r3

  m_pColliderManager = bfx::g_pCurInstance->m_pColliderManager;
  if ( m_pColliderManager->m_pCollider != nullptr )
    return 1;
  result = 0;
  if ( m_pColliderManager->m_pSpaceCollider != nullptr )
    return 1;
  return result;
}


// ========================================================================
// ?EnableBatchProbeProcessing@bfx@@YAX_N@Z
// EA  : 0x83255E18
// RVA : 0x01255E18
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::EnableBatchProbeProcessing(bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableBatchProbeProcessing(enable);
  bfx::g_pCurInstance->m_pColliderManager->m_enableBatchProbeRequests = enable;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$73481
// EA  : 0x83255E78
// RVA : 0x01255E78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_73481()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetClosestPtOnLineSeg@bfx@@YA?AVVec3@1@ABVLineSeg@1@ABV21@@Z
// EA  : 0x83255EA0
// RVA : 0x01255EA0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetClosestPtOnLineSeg(bfx::Vec3 *result, const bfx::LineSeg *seg, const bfx::Vec3 *pos)
{
  bfx::GetClosestPtOnLineSeg(result, start: &seg->m_v0, end: &seg->m_v1, pos);
  return result;
}


// ========================================================================
// ?GetDistPtToLineSeg@bfx@@YAMABVVec3@1@00@Z
// EA  : 0x83255ED8
// RVA : 0x01255ED8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

float __fastcall bfx::GetDistPtToLineSeg(const bfx::Vec3 *pos, const bfx::Vec3 *start, const bfx::Vec3 *end)
{
  double v4; // fp1
  bfx::Vec3 v6; // [sp+50h] [-20h] BYREF

  bfx::GetClosestPtOnLineSeg(result: &v6, start, end, pos);
  v4 = __fsqrts((float)((float)((float)(pos->m_y - v6.m_y) * (float)(pos->m_y - v6.m_y))
                      + (float)((float)((float)(pos->m_z - v6.m_z) * (float)(pos->m_z - v6.m_z))
                              + (float)((float)(pos->m_x - v6.m_x) * (float)(pos->m_x - v6.m_x)))));
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?GetDistPtToLineSeg@bfx@@YAMABVVec3@1@ABVLineSeg@1@@Z
// EA  : 0x83255F40
// RVA : 0x01255F40
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

float __fastcall bfx::GetDistPtToLineSeg(const bfx::Vec3 *pos, const bfx::LineSeg *seg)
{
  double v3; // fp1
  bfx::Vec3 v5; // [sp+50h] [-20h] BYREF

  bfx::GetClosestPtOnLineSeg(result: &v5, start: &seg->m_v0, end: &seg->m_v1, pos);
  v3 = __fsqrts((float)((float)((float)(pos->m_y - v5.m_y) * (float)(pos->m_y - v5.m_y))
                      + (float)((float)((float)(pos->m_z - v5.m_z) * (float)(pos->m_z - v5.m_z))
                              + (float)((float)(pos->m_x - v5.m_x) * (float)(pos->m_x - v5.m_x)))));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetDistSqPtToLineSeg@bfx@@YAMABVVec3@1@ABVLineSeg@1@@Z
// EA  : 0x83255FB0
// RVA : 0x01255FB0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

float __fastcall bfx::GetDistSqPtToLineSeg(const bfx::Vec3 *pos, const bfx::LineSeg *seg)
{
  double v3; // fp1
  bfx::Vec3 v5; // [sp+50h] [-20h] BYREF

  bfx::GetClosestPtOnLineSeg(result: &v5, start: &seg->m_v0, end: &seg->m_v1, pos);
  v3 = (float)((float)((float)(pos->m_y - v5.m_y) * (float)(pos->m_y - v5.m_y))
             + (float)((float)((float)(pos->m_x - v5.m_x) * (float)(pos->m_x - v5.m_x))
                     + (float)((float)(pos->m_z - v5.m_z) * (float)(pos->m_z - v5.m_z))));
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetClosestPtOnLineSegAToLineB@bfx@@YA?AVVec3@1@ABV21@000@Z
// EA  : 0x83256018
// RVA : 0x01256018
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetClosestPtOnLineSegAToLineB(
        bfx::Vec3 *result,
        const bfx::Vec3 *startA,
        const bfx::Vec3 *endA,
        const bfx::Vec3 *startB,
        const bfx::Vec3 *endB)
{
  double m_z; // fp10
  double v6; // fp7
  double v7; // fp13
  double m_y; // fp8
  double v9; // fp11
  double v10; // fp5
  double v11; // fp2
  double v12; // fp3
  double v13; // fp1
  double v16; // fp4
  double v17; // fp1
  double v18; // fp1
  double v19; // fp2
  double v20; // fp7
  float m_x; // r11
  float v22; // r10
  float v23; // r9

  m_z = startA->m_z;
  v7 = (float)(endA->m_z - startA->m_z);
  m_y = startA->m_y;
  v9 = (float)(endA->m_y - startA->m_y);
  v11 = (float)((float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                              - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                      * (float)(endB->m_x - startB->m_x))
              - (float)((float)(endB->m_z - startB->m_z)
                      * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                              - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))));
  v12 = (float)((float)((float)(endB->m_y - startB->m_y)
                      * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                              - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z))))
              - (float)((float)((float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_z - startA->m_z))
                              - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                      * (float)(endB->m_x - startB->m_x)));
  v13 = (float)((float)((float)((float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_z - startA->m_z))
                              - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                      * (float)(endB->m_z - startB->m_z))
              - (float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                              - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                      * (float)(endB->m_y - startB->m_y)));
  _FP4 = (float)((float)__fsqrts((float)((float)((float)v13 * (float)v13)
                                       + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))))
               - (float)1.0842022e-19);
  __asm { fsel      f30, f4, f30, f0 }
  v17 = (float)((float)((float)((float)((float)((float)(endB->m_y - startB->m_y)
                                              * (float)((float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_y - startA->m_y))
                                                      - (float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_z - startA->m_z))))
                                      - (float)((float)((float)((float)(endB->m_x - startB->m_x)
                                                              * (float)(endA->m_z - startA->m_z))
                                                      - (float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_x - startA->m_x)))
                                              * (float)(endB->m_x - startB->m_x)))
                              * (float)_FP30)
                      * (float)(endA->m_z - startA->m_z))
              + (float)((float)((float)((float)((float)((float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_x - startA->m_x))
                                                      - (float)((float)(endB->m_x - startB->m_x)
                                                              * (float)(endA->m_y - startA->m_y)))
                                              * (float)(endB->m_x - startB->m_x))
                                      - (float)((float)(endB->m_z - startB->m_z)
                                              * (float)((float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_y - startA->m_y))
                                                      - (float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_z - startA->m_z)))))
                              * (float)_FP30)
                      * (float)(endA->m_y - startA->m_y)));
  v18 = (float)((float)((float)((float)((float)((float)((float)((float)(endB->m_x - startB->m_x)
                                                              * (float)(endA->m_z - startA->m_z))
                                                      - (float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_x - startA->m_x)))
                                              * (float)(endB->m_z - startB->m_z))
                                      - (float)((float)((float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_x - startA->m_x))
                                                      - (float)((float)(endB->m_x - startB->m_x)
                                                              * (float)(endA->m_y - startA->m_y)))
                                              * (float)(endB->m_y - startB->m_y)))
                              * (float)_FP30)
                      * (float)(endA->m_x - startA->m_x))
              + (float)v17);
  if ( v18 == 0.0
    || (v6 = startB->m_y,
        v10 = startB->m_z,
        v16 = (float)((float)((float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                                            - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                                    * (float)(endB->m_x - startB->m_x))
                            - (float)((float)(endB->m_z - startB->m_z)
                                    * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                                            - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))))
                    * (float)_FP30),
        v19 = (float)((float)((float)(startB->m_x - startA->m_x)
                            * (float)((float)((float)((float)((float)((float)(endB->m_x - startB->m_x)
                                                                    * (float)(endA->m_z - startA->m_z))
                                                            - (float)((float)(endB->m_z - startB->m_z)
                                                                    * (float)(endA->m_x - startA->m_x)))
                                                    * (float)(endB->m_z - startB->m_z))
                                            - (float)((float)((float)((float)(endB->m_y - startB->m_y)
                                                                    * (float)(endA->m_x - startA->m_x))
                                                            - (float)((float)(endB->m_x - startB->m_x)
                                                                    * (float)(endA->m_y - startA->m_y)))
                                                    * (float)(endB->m_y - startB->m_y)))
                                    * (float)_FP30))
                    + (float)((float)((float)((float)v10 - startA->m_z)
                                    * (float)((float)((float)((float)(endB->m_y - startB->m_y)
                                                            * (float)((float)((float)(endB->m_z - startB->m_z)
                                                                            * (float)(endA->m_y - startA->m_y))
                                                                    - (float)((float)(endB->m_y - startB->m_y)
                                                                            * (float)(endA->m_z - startA->m_z))))
                                                    - (float)((float)((float)((float)(endB->m_x - startB->m_x)
                                                                            * (float)(endA->m_z - startA->m_z))
                                                                    - (float)((float)(endB->m_z - startB->m_z)
                                                                            * (float)(endA->m_x - startA->m_x)))
                                                            * (float)(endB->m_x - startB->m_x)))
                                            * (float)_FP30))
                            + (float)((float)((float)v6 - startA->m_y) * (float)v16))),
        (v20 = (float)((float)v19 / (float)v18)) < 0.0) )
  {
    v23 = startA->m_z;
    v22 = startA->m_y;
    m_x = startA->m_x;
  }
  else
  {
    if ( v20 <= 1.0 )
    {
      result->m_x = startA->m_x + (float)((float)(endA->m_x - startA->m_x) * (float)((float)v19 / (float)v18));
      result->m_y = (float)m_y + (float)((float)v9 * (float)((float)v19 / (float)v18));
      result->m_z = (float)m_z + (float)((float)v7 * (float)((float)v19 / (float)v18));
      return result;
    }
    m_x = endA->m_x;
    v22 = endA->m_y;
    v23 = endA->m_z;
  }
  result->m_x = m_x;
  result->m_y = v22;
  result->m_z = v23;
  return result;
}


// ========================================================================
// ?GetDistBetweenLineSegs@bfx@@YAMABVVec3@1@000@Z
// EA  : 0x83256198
// RVA : 0x01256198
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

float __fastcall bfx::GetDistBetweenLineSegs(
        const bfx::Vec3 *startA,
        const bfx::Vec3 *endA,
        const bfx::Vec3 *startB,
        const bfx::Vec3 *endB)
{
  double m_z; // fp21
  double v5; // fp31
  double m_y; // fp20
  double v7; // fp30
  double v8; // fp18
  double v9; // fp28
  double m_x; // fp17
  double v11; // fp27
  double v13; // fp19
  double v14; // fp29
  double v16; // fp16
  double v17; // fp26
  double v19; // fp12
  double v21; // fp4
  double v22; // fp23
  double v23; // fp3
  double v24; // fp25
  double v25; // fp2
  double v28; // fp3
  double v29; // fp2
  double v30; // fp1
  double v31; // fp25
  double v32; // fp25
  double v33; // fp7
  double v34; // fp3
  double v35; // fp2
  double v38; // fp8
  double v39; // fp7
  double v40; // fp3
  double v41; // fp1
  double v42; // fp0
  double v43; // fp11
  double v44; // fp9
  double v45; // fp1
  double v46; // fp31
  double v47; // fp29
  double v48; // fp30
  bfx::Vec3 v56; // [sp+50h] [-E0h] BYREF
  bfx::Vec3 v57[14]; // [sp+60h] [-D0h] BYREF

  m_z = endA->m_z;
  v5 = startA->m_z;
  m_y = endB->m_y;
  v7 = startB->m_y;
  v8 = endA->m_y;
  v9 = startA->m_y;
  m_x = endB->m_x;
  v11 = startB->m_x;
  v13 = endA->m_x;
  v14 = startA->m_x;
  v16 = endB->m_z;
  v17 = startB->m_z;
  v21 = 3.4028235e38;
  v22 = 3.4028235e38;
  v23 = (float)((float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                              - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                      * (float)(endB->m_x - startB->m_x))
              - (float)((float)(endB->m_z - startB->m_z)
                      * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                              - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))));
  v24 = (float)((float)((float)((float)((float)(endA->m_z - startA->m_z) * (float)(endB->m_x - startB->m_x))
                              - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                      * (float)(endB->m_z - startB->m_z))
              - (float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                              - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                      * (float)(endB->m_y - startB->m_y)));
  v25 = (float)((float)((float)(endB->m_y - startB->m_y)
                      * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                              - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z))))
              - (float)((float)((float)((float)(endA->m_z - startA->m_z) * (float)(endB->m_x - startB->m_x))
                              - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                      * (float)(endB->m_x - startB->m_x)));
  _FP15 = (float)((float)__fsqrts((float)((float)((float)v24 * (float)v24)
                                        + (float)((float)((float)v25 * (float)v25) + (float)((float)v23 * (float)v23))))
                - (float)1.0842022e-19);
  __asm { fsel      f1, f15, f1, f5 }
  v28 = (float)((float)((float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                                      - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                              * (float)(endB->m_x - startB->m_x))
                      - (float)((float)(endB->m_z - startB->m_z)
                              * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                                      - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))))
              * (float)_FP1);
  v29 = (float)((float)((float)((float)(endB->m_y - startB->m_y)
                              * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                                      - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z))))
                      - (float)((float)((float)((float)(endA->m_z - startA->m_z) * (float)(endB->m_x - startB->m_x))
                                      - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                              * (float)(endB->m_x - startB->m_x)))
              * (float)_FP1);
  v31 = (float)((float)((float)((float)((float)((float)(endB->m_y - startB->m_y)
                                              * (float)((float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_y - startA->m_y))
                                                      - (float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_z - startA->m_z))))
                                      - (float)((float)((float)((float)(endA->m_z - startA->m_z)
                                                              * (float)(endB->m_x - startB->m_x))
                                                      - (float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_x - startA->m_x)))
                                              * (float)(endB->m_x - startB->m_x)))
                              * (float)_FP1)
                      * (float)(endA->m_z - startA->m_z))
              + (float)((float)((float)((float)((float)((float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_x - startA->m_x))
                                                      - (float)((float)(endB->m_x - startB->m_x)
                                                              * (float)(endA->m_y - startA->m_y)))
                                              * (float)(endB->m_x - startB->m_x))
                                      - (float)((float)(endB->m_z - startB->m_z)
                                              * (float)((float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_y - startA->m_y))
                                                      - (float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_z - startA->m_z)))))
                              * (float)_FP1)
                      * (float)(endA->m_y - startA->m_y)));
  v30 = (float)((float)((float)((float)((float)((float)(endA->m_z - startA->m_z) * (float)(endB->m_x - startB->m_x))
                                      - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                              * (float)(endB->m_z - startB->m_z))
                      - (float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                                      - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                              * (float)(endB->m_y - startB->m_y)))
              * (float)_FP1);
  v32 = (float)((float)((float)v30 * (float)(endA->m_x - startA->m_x)) + (float)v31);
  if ( v32 != 0.0 )
    v21 = (float)((float)((float)((float)(startB->m_x - startA->m_x) * (float)v30)
                        + (float)((float)((float)(startB->m_z - startA->m_z) * (float)v29)
                                + (float)((float)(startB->m_y - startA->m_y) * (float)v28)))
                / (float)v32);
  v34 = (float)((float)((float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                              - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))
                      * (float)(endA->m_y - startA->m_y))
              - (float)((float)((float)((float)(endA->m_z - startA->m_z) * (float)(endB->m_x - startB->m_x))
                              - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                      * (float)(endA->m_x - startA->m_x)));
  v35 = (float)((float)((float)((float)((float)(endA->m_z - startA->m_z) * (float)(endB->m_x - startB->m_x))
                              - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                      * (float)(endA->m_z - startA->m_z))
              - (float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                              - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                      * (float)(endA->m_y - startA->m_y)));
  v33 = (float)((float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                              - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                      * (float)(endA->m_x - startA->m_x))
              - (float)((float)(endA->m_z - startA->m_z)
                      * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                              - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))));
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v35 * (float)v35)
                                       + (float)((float)((float)v34 * (float)v34) + (float)((float)v33 * (float)v33))))
               - (float)1.0842022e-19);
  __asm { fsel      f1, f8, f6, f5 }
  v19 = (float)(endB->m_z - startB->m_z);
  v40 = (float)((float)((float)((float)((float)((float)((float)((float)(endA->m_z - startA->m_z)
                                                              * (float)(endB->m_x - startB->m_x))
                                                      - (float)((float)(endB->m_z - startB->m_z)
                                                              * (float)(endA->m_x - startA->m_x)))
                                              * (float)(endA->m_z - startA->m_z))
                                      - (float)((float)((float)((float)(endB->m_y - startB->m_y)
                                                              * (float)(endA->m_x - startA->m_x))
                                                      - (float)((float)(endB->m_x - startB->m_x)
                                                              * (float)(endA->m_y - startA->m_y)))
                                              * (float)(endA->m_y - startA->m_y)))
                              * (float)_FP1)
                      * (float)(endB->m_x - startB->m_x))
              + (float)((float)((float)((float)((float)((float)((float)((float)(endB->m_z - startB->m_z)
                                                                      * (float)(endA->m_y - startA->m_y))
                                                              - (float)((float)(endB->m_y - startB->m_y)
                                                                      * (float)(endA->m_z - startA->m_z)))
                                                      * (float)(endA->m_y - startA->m_y))
                                              - (float)((float)((float)((float)(endA->m_z - startA->m_z)
                                                                      * (float)(endB->m_x - startB->m_x))
                                                              - (float)((float)(endB->m_z - startB->m_z)
                                                                      * (float)(endA->m_x - startA->m_x)))
                                                      * (float)(endA->m_x - startA->m_x)))
                                      * (float)_FP1)
                              * (float)v19)
                      + (float)((float)((float)v33 * (float)_FP1) * (float)(endB->m_y - startB->m_y))));
  if ( v40 != 0.0 )
  {
    v38 = (float)((float)((float)((float)((float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_x - startA->m_x))
                                        - (float)((float)(endB->m_x - startB->m_x) * (float)(endA->m_y - startA->m_y)))
                                * (float)(endA->m_x - startA->m_x))
                        - (float)((float)(endA->m_z - startA->m_z)
                                * (float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                                        - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))))
                * (float)_FP1);
    v39 = (float)((float)((float)((float)((float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_y - startA->m_y))
                                        - (float)((float)(endB->m_y - startB->m_y) * (float)(endA->m_z - startA->m_z)))
                                * (float)(endA->m_y - startA->m_y))
                        - (float)((float)((float)((float)(endA->m_z - startA->m_z) * (float)(endB->m_x - startB->m_x))
                                        - (float)((float)(endB->m_z - startB->m_z) * (float)(endA->m_x - startA->m_x)))
                                * (float)(endA->m_x - startA->m_x)))
                * (float)_FP1);
    v22 = (float)((float)((float)((float)(startA->m_x - startB->m_x)
                                * (float)((float)((float)((float)((float)((float)(endA->m_z - startA->m_z)
                                                                        * (float)(endB->m_x - startB->m_x))
                                                                - (float)((float)(endB->m_z - startB->m_z)
                                                                        * (float)(endA->m_x - startA->m_x)))
                                                        * (float)(endA->m_z - startA->m_z))
                                                - (float)((float)((float)((float)(endB->m_y - startB->m_y)
                                                                        * (float)(endA->m_x - startA->m_x))
                                                                - (float)((float)(endB->m_x - startB->m_x)
                                                                        * (float)(endA->m_y - startA->m_y)))
                                                        * (float)(endA->m_y - startA->m_y)))
                                        * (float)_FP1))
                        + (float)((float)((float)(startA->m_z - startB->m_z) * (float)v39)
                                + (float)((float)(startA->m_y - startB->m_y) * (float)v38)))
                / (float)v40);
  }
  if ( v21 < 0.0 || v22 < 0.0 || v21 > 1.0 || v22 > 1.0 )
  {
    bfx::GetClosestPtOnLineSeg(result: &v56, start: startB, end: endB, pos: startA);
    v46 = (float)((float)((float)((float)v14 - v56.m_x) * (float)((float)v14 - v56.m_x))
                + (float)((float)((float)((float)v5 - v56.m_z) * (float)((float)v5 - v56.m_z))
                        + (float)((float)((float)v9 - v56.m_y) * (float)((float)v9 - v56.m_y))));
    bfx::GetClosestPtOnLineSeg(result: v57, start: startB, end: endB, pos: endA);
    v47 = (float)((float)((float)((float)v13 - v57[0].m_x) * (float)((float)v13 - v57[0].m_x))
                + (float)((float)((float)((float)m_z - v57[0].m_z) * (float)((float)m_z - v57[0].m_z))
                        + (float)((float)((float)v8 - v57[0].m_y) * (float)((float)v8 - v57[0].m_y))));
    bfx::GetClosestPtOnLineSeg(result: &v56, start: startA, end: endA, pos: startB);
    v48 = (float)((float)((float)((float)v11 - v56.m_x) * (float)((float)v11 - v56.m_x))
                + (float)((float)((float)((float)v17 - v56.m_z) * (float)((float)v17 - v56.m_z))
                        + (float)((float)((float)v7 - v56.m_y) * (float)((float)v7 - v56.m_y))));
    bfx::GetClosestPtOnLineSeg(result: v57, start: startA, end: endA, pos: endB);
    _FP4 = (float)((float)v46 - (float)v47);
    __asm { fsel      f3, f4, f29, f31 }
    _FP7 = (float)((float)v48
                 - (float)((float)((float)((float)m_x - v57[0].m_x) * (float)((float)m_x - v57[0].m_x))
                         + (float)((float)((float)((float)v16 - v57[0].m_z) * (float)((float)v16 - v57[0].m_z))
                                 + (float)((float)((float)m_y - v57[0].m_y) * (float)((float)m_y - v57[0].m_y)))));
    __asm { fsel      f6, f7, f8, f30 }
    _FP5 = (float)((float)_FP3 - (float)_FP6);
    __asm { fsel      f4, f5, f6, f3 }
    v45 = __fsqrts(_FP4);
  }
  else
  {
    v41 = (float)(startA->m_z + (float)((float)(endA->m_z - startA->m_z) * (float)v21));
    v43 = (float)((float)(startA->m_y + (float)((float)(endA->m_y - startA->m_y) * (float)v21))
                - (float)(startB->m_y + (float)((float)(endB->m_y - startB->m_y) * (float)v22)));
    v42 = (float)(startB->m_z + (float)((float)(endB->m_z - startB->m_z) * (float)v22));
    v44 = (float)((float)(startA->m_x + (float)((float)(endA->m_x - startA->m_x) * (float)v21))
                - (float)(startB->m_x + (float)((float)(endB->m_x - startB->m_x) * (float)v22)));
    v45 = __fsqrts((float)((float)((float)v44 * (float)v44)
                         + (float)((float)((float)((float)v41 - (float)v42) * (float)((float)v41 - (float)v42))
                                 + (float)((float)v43 * (float)v43))));
  }
  return *((float *)&v45 + 1);
}


// ========================================================================
// ?CollideLineAndCircle@bfx@@YAMABVVec2@1@00M@Z
// EA  : 0x832564A8
// RVA : 0x012564A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

float __fastcall bfx::CollideLineAndCircle(
        const bfx::Vec2 *lineStart,
        const bfx::Vec2 *normalizedLineDir,
        const bfx::Vec2 *circlePos,
        double radius)
{
  double v4; // fp11
  double v5; // fp10
  double v6; // fp13
  double v7; // fp1

  v4 = (float)((float)(lineStart->m_x
                     + (float)(normalizedLineDir->m_x
                             * (float)((float)(normalizedLineDir->m_x * (float)(circlePos->m_x - lineStart->m_x))
                                     + (float)(normalizedLineDir->m_y * (float)(circlePos->m_y - lineStart->m_y)))))
             - circlePos->m_x);
  v5 = (float)((float)(lineStart->m_y
                     + (float)(normalizedLineDir->m_y
                             * (float)((float)(normalizedLineDir->m_x * (float)(circlePos->m_x - lineStart->m_x))
                                     + (float)(normalizedLineDir->m_y * (float)(circlePos->m_y - lineStart->m_y)))))
             - circlePos->m_y);
  v6 = __fsqrts((float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4)));
  if ( v6 <= radius )
    v7 = (float)((float)((float)(normalizedLineDir->m_x * (float)(circlePos->m_x - lineStart->m_x))
                       + (float)(normalizedLineDir->m_y * (float)(circlePos->m_y - lineStart->m_y)))
               - (float)__fsqrts((float)((float)((float)radius * (float)radius) - (float)((float)v6 * (float)v6))));
  else
    v7 = 3.4028235e38;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?CollideLineAndSphere@bfx@@YAMABVVec3@1@00M@Z
// EA  : 0x83256520
// RVA : 0x01256520
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

float __fastcall bfx::CollideLineAndSphere(
        const bfx::Vec3 *lineStart,
        const bfx::Vec3 *normalizedLineDir,
        const bfx::Vec3 *spherePos,
        double radius)
{
  double v4; // fp11
  double v5; // fp9
  double v6; // fp8
  double v7; // fp13
  double v8; // fp1

  v4 = (float)((float)(lineStart->m_y
                     + (float)(normalizedLineDir->m_y
                             * (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                                     + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                                             + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))))))
             - spherePos->m_y);
  v5 = (float)((float)(lineStart->m_z
                     + (float)(normalizedLineDir->m_z
                             * (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                                     + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                                             + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))))))
             - spherePos->m_z);
  v6 = (float)((float)(lineStart->m_x
                     + (float)(normalizedLineDir->m_x
                             * (float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                                     + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                                             + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))))))
             - spherePos->m_x);
  v7 = __fsqrts((float)((float)((float)v6 * (float)v6)
                      + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))));
  if ( v7 <= radius )
    v8 = (float)((float)((float)(normalizedLineDir->m_z * (float)(spherePos->m_z - lineStart->m_z))
                       + (float)((float)(normalizedLineDir->m_x * (float)(spherePos->m_x - lineStart->m_x))
                               + (float)(normalizedLineDir->m_y * (float)(spherePos->m_y - lineStart->m_y))))
               - (float)__fsqrts((float)((float)((float)radius * (float)radius) - (float)((float)v7 * (float)v7))));
  else
    v8 = 3.4028235e38;
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?CollideLineAndPlane@bfx@@YA_NABVVec3@1@0ABVPlane@1@AAV21@@Z
// EA  : 0x832565B8
// RVA : 0x012565B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::CollideLineAndPlane(
        const bfx::Vec3 *v0,
        const bfx::Vec3 *v1,
        const bfx::Plane *plane,
        bfx::Vec3 *intersectionPosOut)
{
  double m_y; // fp5
  double m_z; // fp4
  double v7; // fp12
  double v8; // fp11

  if ( __fabs((float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                            + (float)((float)(v1->m_x * plane->m_normal.m_x) + (float)(v1->m_y * plane->m_normal.m_y)))
                    - (float)((float)(plane->m_normal.m_z * v0->m_z)
                            + (float)((float)(plane->m_normal.m_x * v0->m_x) + (float)(plane->m_normal.m_y * v0->m_y))))) < 1.0842022e-19 )
    return 0;
  m_y = v0->m_y;
  m_z = v0->m_z;
  v7 = (float)((float)(v1->m_y - v0->m_y)
             * (float)((float)(plane->m_d
                             - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                     + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                             + (float)(plane->m_normal.m_y * v0->m_y))))
                     / (float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                                     + (float)((float)(v1->m_x * plane->m_normal.m_x)
                                             + (float)(v1->m_y * plane->m_normal.m_y)))
                             - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                     + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                             + (float)(plane->m_normal.m_y * v0->m_y))))));
  v8 = (float)((float)(v1->m_z - v0->m_z)
             * (float)((float)(plane->m_d
                             - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                     + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                             + (float)(plane->m_normal.m_y * v0->m_y))))
                     / (float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                                     + (float)((float)(v1->m_x * plane->m_normal.m_x)
                                             + (float)(v1->m_y * plane->m_normal.m_y)))
                             - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                     + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                             + (float)(plane->m_normal.m_y * v0->m_y))))));
  intersectionPosOut->m_x = v0->m_x
                          + (float)((float)(v1->m_x - v0->m_x)
                                  * (float)((float)(plane->m_d
                                                  - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                                          + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                                                  + (float)(plane->m_normal.m_y * v0->m_y))))
                                          / (float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                                                          + (float)((float)(v1->m_x * plane->m_normal.m_x)
                                                                  + (float)(v1->m_y * plane->m_normal.m_y)))
                                                  - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                                          + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                                                  + (float)(plane->m_normal.m_y * v0->m_y))))));
  intersectionPosOut->m_y = (float)m_y + (float)v7;
  intersectionPosOut->m_z = (float)m_z + (float)v8;
  return 1;
}


// ========================================================================
// ?IsPosInsideBox@bfx@@YA_NABVVec3@1@ABVBox@1@@Z
// EA  : 0x83256660
// RVA : 0x01256660
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::IsPosInsideBox(const bfx::Vec3 *pos, const bfx::Box *box)
{
  double m_x; // fp0
  double m_y; // fp0
  double m_z; // fp0
  int result; // r3

  m_x = pos->m_x;
  if ( m_x < box->m_min.m_x )
    return 0;
  if ( m_x > box->m_max.m_x )
    return 0;
  m_y = pos->m_y;
  if ( m_y < box->m_min.m_y )
    return 0;
  if ( m_y > box->m_max.m_y )
    return 0;
  m_z = pos->m_z;
  if ( m_z < box->m_min.m_z )
    return 0;
  result = 1;
  if ( m_z > box->m_max.m_z )
    return 0;
  return result;
}


// ========================================================================
// ?LineSegIntersectsClippingVolume@bfx@@YA_NABVVec3@1@0PBVPlane@1@HH@Z
// EA  : 0x832566C0
// RVA : 0x012566C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::LineSegIntersectsClippingVolume(
        const bfx::Vec3 *posA,
        const bfx::Vec3 *posB,
        const bfx::Plane *pClipPlanes,
        int numPlanes,
        int planeIndexToIgnore)
{
  int v5; // r10
  float *p_m_y; // r11
  double v9; // fp0

  v5 = 0;
  _FP12 = 1.0;
  _FP11 = 0.0;
  if ( numPlanes > 0 )
  {
    p_m_y = &pClipPlanes->m_normal.m_y;
    do
    {
      if ( v5 != planeIndexToIgnore )
      {
        v9 = (float)((float)((float)(posB->m_x * *(p_m_y - 1))
                           + (float)((float)(posB->m_z * p_m_y[1]) + (float)(posB->m_y * *p_m_y)))
                   - (float)((float)(posA->m_x * *(p_m_y - 1))
                           + (float)((float)(posA->m_z * p_m_y[1]) + (float)(posA->m_y * *p_m_y))));
        if ( __fabs(v9) <= 1.0842022e-19 )
        {
          if ( (float)((float)(posA->m_x * *(p_m_y - 1))
                     + (float)((float)(posA->m_z * p_m_y[1]) + (float)(posA->m_y * *p_m_y))) < (double)p_m_y[2] )
            return 0;
        }
        else
        {
          if ( v9 <= 0.0 )
          {
            _FP13 = (float)((float)_FP12
                          - (float)((float)(p_m_y[2]
                                          - (float)((float)(posA->m_x * *(p_m_y - 1))
                                                  + (float)((float)(posA->m_z * p_m_y[1]) + (float)(posA->m_y * *p_m_y))))
                                  / (float)((float)((float)(posB->m_x * *(p_m_y - 1))
                                                  + (float)((float)(posB->m_z * p_m_y[1]) + (float)(posB->m_y * *p_m_y)))
                                          - (float)((float)(posA->m_x * *(p_m_y - 1))
                                                  + (float)((float)(posA->m_z * p_m_y[1]) + (float)(posA->m_y * *p_m_y))))));
            __asm { fsel      f12, f13, f0, f12 }
          }
          else
          {
            _FP13 = (float)((float)_FP11
                          - (float)((float)(p_m_y[2]
                                          - (float)((float)(posA->m_x * *(p_m_y - 1))
                                                  + (float)((float)(posA->m_z * p_m_y[1]) + (float)(posA->m_y * *p_m_y))))
                                  / (float)((float)((float)(posB->m_x * *(p_m_y - 1))
                                                  + (float)((float)(posB->m_z * p_m_y[1]) + (float)(posB->m_y * *p_m_y)))
                                          - (float)((float)(posA->m_x * *(p_m_y - 1))
                                                  + (float)((float)(posA->m_z * p_m_y[1]) + (float)(posA->m_y * *p_m_y))))));
            __asm { fsel      f11, f13, f11, f0 }
          }
          if ( _FP11 > _FP12 )
            return 0;
        }
      }
      ++v5;
      p_m_y += 4;
    }
    while ( v5 < numPlanes );
  }
  return 1;
}


// ========================================================================
// ?LineSegIntersectsBox@bfx@@YA_NABVVec3@1@0ABVBox@1@@Z
// EA  : 0x832567A0
// RVA : 0x012567A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

BOOL __fastcall bfx::LineSegIntersectsBox(
        const bfx::Vec3 *posAWCoord,
        const bfx::Vec3 *posBWCoord,
        const bfx::Box *box)
{
  double v3; // fp12
  double v4; // fp11
  double v5; // fp13

  v3 = (float)(posBWCoord->m_x - posAWCoord->m_x);
  v4 = (float)(posBWCoord->m_y - posAWCoord->m_y);
  v5 = (float)(posBWCoord->m_z - posAWCoord->m_z);
  _FP0 = (float)((float)((float)((float)__fabs((float)((float)((float)(posBWCoord->m_x + posAWCoord->m_x) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_x + box->m_min.m_x) * (float)0.5)))
                               - (float)__fabs((float)((float)(posBWCoord->m_x - posAWCoord->m_x) * (float)0.5)))
                       - (float)((float)(box->m_max.m_x - box->m_min.m_x) * (float)0.5))
               - (float)((float)((float)__fabs((float)((float)((float)(posBWCoord->m_y + posAWCoord->m_y) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_y + box->m_min.m_y) * (float)0.5)))
                               - (float)__fabs((float)((float)(posBWCoord->m_y - posAWCoord->m_y) * (float)0.5)))
                       - (float)((float)(box->m_max.m_y - box->m_min.m_y) * (float)0.5)));
  __asm { fsel      f3, f0, f3, f2 }
  _FP2 = (float)((float)_FP3
               - (float)((float)((float)__fabs((float)((float)((float)(posBWCoord->m_z + posAWCoord->m_z) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_z + box->m_min.m_z) * (float)0.5)))
                               - (float)__fabs((float)((float)(posBWCoord->m_z - posAWCoord->m_z) * (float)0.5)))
                       - (float)((float)(box->m_max.m_z - box->m_min.m_z) * (float)0.5)));
  __asm { fsel      f1, f2, f3, f1 }
  return _FP1 <= 0.0
      && (float)((float)__fabs((float)((float)((float)(posBWCoord->m_z - posAWCoord->m_z)
                                             * (float)((float)((float)(posBWCoord->m_y + posAWCoord->m_y) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_y + box->m_min.m_y) * (float)0.5)))
                                     - (float)((float)(posBWCoord->m_y - posAWCoord->m_y)
                                             * (float)((float)((float)(posBWCoord->m_z + posAWCoord->m_z) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_z + box->m_min.m_z) * (float)0.5)))))
               - (float)((float)((float)__fabs(v4) * (float)((float)(box->m_max.m_z - box->m_min.m_z) * (float)0.5))
                       + (float)((float)__fabs(v5) * (float)((float)(box->m_max.m_y - box->m_min.m_y) * (float)0.5)))) <= 0.0
      && (float)((float)__fabs((float)((float)((float)((float)((float)(posBWCoord->m_z + posAWCoord->m_z) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_z + box->m_min.m_z) * (float)0.5))
                                             * (float)(posBWCoord->m_x - posAWCoord->m_x))
                                     - (float)((float)(posBWCoord->m_z - posAWCoord->m_z)
                                             * (float)((float)((float)(posBWCoord->m_x + posAWCoord->m_x) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_x + box->m_min.m_x) * (float)0.5)))))
               - (float)((float)((float)__fabs(v3) * (float)((float)(box->m_max.m_z - box->m_min.m_z) * (float)0.5))
                       + (float)((float)__fabs(v5) * (float)((float)(box->m_max.m_x - box->m_min.m_x) * (float)0.5)))) <= 0.0
      && (float)((float)__fabs((float)((float)((float)(posBWCoord->m_y - posAWCoord->m_y)
                                             * (float)((float)((float)(posBWCoord->m_x + posAWCoord->m_x) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_x + box->m_min.m_x) * (float)0.5)))
                                     - (float)((float)((float)((float)(posBWCoord->m_y + posAWCoord->m_y) * (float)0.5)
                                                     - (float)((float)(box->m_max.m_y + box->m_min.m_y) * (float)0.5))
                                             * (float)(posBWCoord->m_x - posAWCoord->m_x))))
               - (float)((float)((float)__fabs(v3) * (float)((float)(box->m_max.m_y - box->m_min.m_y) * (float)0.5))
                       + (float)((float)__fabs(v4) * (float)((float)(box->m_max.m_x - box->m_min.m_x) * (float)0.5)))) <= 0.0;
}


// ========================================================================
// ?ClipLineSegAgainstPlane@bfx@@YA_NABVPlane@1@ABVLineSeg@1@ABVVec3@1@AAM3@Z
// EA  : 0x83256950
// RVA : 0x01256950
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

BOOL __fastcall bfx::ClipLineSegAgainstPlane(
        const bfx::Plane *plane,
        const bfx::LineSeg *seg,
        const bfx::Vec3 *segVec,
        float *minS,
        float *maxS)
{
  double v5; // fp0

  v5 = (float)((float)(segVec->m_x * plane->m_normal.m_x)
             + (float)((float)(segVec->m_y * plane->m_normal.m_y) + (float)(segVec->m_z * plane->m_normal.m_z)));
  if ( v5 < -1.0842022e-19 )
  {
    _FP0 = (float)((float)((float)(plane->m_d
                                 - (float)((float)(seg->m_v0.m_x * plane->m_normal.m_x)
                                         + (float)((float)(seg->m_v0.m_y * plane->m_normal.m_y)
                                                 + (float)(seg->m_v0.m_z * plane->m_normal.m_z))))
                         / (float)((float)(segVec->m_x * plane->m_normal.m_x)
                                 + (float)((float)(segVec->m_y * plane->m_normal.m_y)
                                         + (float)(segVec->m_z * plane->m_normal.m_z))))
                 - *maxS);
    __asm { fsel      f13, f0, f5, f1 }
    *maxS = _FP13;
    return *minS <= (double)*maxS;
  }
  if ( v5 > 1.0842022e-19 )
  {
    _FP0 = (float)((float)((float)(plane->m_d
                                 - (float)((float)(seg->m_v0.m_x * plane->m_normal.m_x)
                                         + (float)((float)(seg->m_v0.m_y * plane->m_normal.m_y)
                                                 + (float)(seg->m_v0.m_z * plane->m_normal.m_z))))
                         / (float)((float)(segVec->m_x * plane->m_normal.m_x)
                                 + (float)((float)(segVec->m_y * plane->m_normal.m_y)
                                         + (float)(segVec->m_z * plane->m_normal.m_z))))
                 - *minS);
    __asm { fsel      f13, f0, f1, f5 }
    *minS = _FP13;
    return *minS <= (double)*maxS;
  }
  if ( (float)((float)(seg->m_v0.m_x * plane->m_normal.m_x)
             + (float)((float)(seg->m_v0.m_y * plane->m_normal.m_y) + (float)(seg->m_v0.m_z * plane->m_normal.m_z))) >= (double)plane->m_d )
    return *minS <= (double)*maxS;
  return false;
}


// ========================================================================
// ?IsPosWithinConvexVolume@bfx@@YA_NABVVec3@1@PBVPlane@1@HM@Z
// EA  : 0x83256A48
// RVA : 0x01256A48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::IsPosWithinConvexVolume(
        const bfx::Vec3 *pos,
        const bfx::Plane *pPlanes,
        int numPlanes,
        double expandDist)
{
  int v4; // r10
  float *i; // r11

  v4 = 0;
  if ( numPlanes <= 0 )
    return 1;
  for ( i = &pPlanes->m_normal.m_y;
        (float)((float)((float)(i[1] * pos->m_z) + (float)((float)(*(i - 1) * pos->m_x) + (float)(*i * pos->m_y))) - i[2]) >= -expandDist;
        i += 4 )
  {
    if ( ++v4 >= numPlanes )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?CalcRadiusOfPolygon@bfx@@YAMQBVVec3@1@HABV21@@Z
// EA  : 0x83256AB0
// RVA : 0x01256AB0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

float __fastcall bfx::CalcRadiusOfPolygon(const bfx::Vec3 *vertArray, int numVerts, const bfx::Vec3 *centerPos)
{
  int v3; // r10
  float *p_m_z; // r11
  double v6; // fp9
  double v7; // fp3
  double v8; // fp7
  double v9; // fp4
  double v10; // fp1
  double v11; // fp6
  double v12; // fp5
  double v13; // fp8
  double v14; // fp30
  double v15; // fp2
  double v16; // fp31
  double v17; // fp9
  double v18; // fp8
  double v19; // fp7
  int v27; // ctr
  float *v28; // r11
  double v29; // fp9
  double v30; // fp8
  double v32; // fp1

  v3 = 0;
  _FP0 = 0.0;
  if ( numVerts >= 4 )
  {
    p_m_z = &vertArray[-1].m_z;
    do
    {
      v3 += 4;
      v6 = (float)(p_m_z[3] - centerPos->m_z);
      v7 = (float)(p_m_z[6] - centerPos->m_z);
      v8 = (float)(p_m_z[1] - centerPos->m_x);
      v9 = (float)(p_m_z[2] - centerPos->m_y);
      v10 = (float)(p_m_z[4] - centerPos->m_x);
      v11 = (float)(p_m_z[5] - centerPos->m_y);
      v12 = (float)(p_m_z[9] - centerPos->m_z);
      v13 = (float)(p_m_z[7] - centerPos->m_x);
      v14 = (float)(p_m_z[10] - centerPos->m_x);
      v15 = (float)(p_m_z[8] - centerPos->m_y);
      v16 = (float)(p_m_z[11] - centerPos->m_y);
      p_m_z += 12;
      v17 = (float)((float)((float)v8 * (float)v8) + (float)((float)v6 * (float)v6));
      v19 = (float)((float)((float)v15 * (float)v15)
                  + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)));
      v18 = (float)((float)((float)v11 * (float)v11)
                  + (float)((float)((float)v10 * (float)v10) + (float)((float)v7 * (float)v7)));
      _FP6 = (float)((float)((float)((float)v9 * (float)v9) + (float)v17) - (float)_FP0);
      __asm { fsel      f4, f6, f10, f0 }
      _FP3 = (float)((float)v18 - (float)_FP4);
      __asm { fsel      f2, f3, f8, f4 }
      _FP1 = (float)((float)v19 - (float)_FP2);
      __asm { fsel      f0, f1, f7, f2 }
      _FP10 = (float)((float)((float)((float)v16 * (float)v16)
                            + (float)((float)((float)v14 * (float)v14)
                                    + (float)((float)(*p_m_z - centerPos->m_z) * (float)(*p_m_z - centerPos->m_z))))
                    - (float)_FP0);
      __asm { fsel      f0, f10, f5, f0 }
    }
    while ( v3 < numVerts - 3 );
  }
  if ( v3 < numVerts )
  {
    v27 = numVerts - v3;
    v28 = &vertArray[v3 - 1].m_z;
    do
    {
      v29 = v28[2];
      v30 = (float)(v28[1] - centerPos->m_x);
      v28 += 3;
      _FP2 = (float)((float)((float)((float)((float)v29 - centerPos->m_y) * (float)((float)v29 - centerPos->m_y))
                           + (float)((float)((float)v30 * (float)v30)
                                   + (float)((float)(*v28 - centerPos->m_z) * (float)(*v28 - centerPos->m_z))))
                   - (float)_FP0);
      __asm { fsel      f0, f2, f3, f0 }
      --v27;
    }
    while ( v27 != 0 );
  }
  v32 = __fsqrts(_FP0);
  return *((float *)&v32 + 1);
}


// ========================================================================
// ?CalcBasisVert@bfx@@YAHQBVVec3@1@H@Z
// EA  : 0x83256C10
// RVA : 0x01256C10
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::CalcBasisVert(const bfx::Vec3 *vertArray, int numVerts)
{
  double v2; // fp13
  double m_x; // fp12
  double v4; // fp0
  double v6; // fp8
  int result; // r3
  int v8; // r11
  double v11; // fp11
  double v12; // fp10
  double v13; // fp9
  const bfx::Vec3 *v14; // r10
  float v15; // r6
  float v16; // r5
  double v17; // fp7
  double v18; // fp6
  double v19; // fp5
  double v20; // fp7
  double v21; // fp7
  double v22; // fp6
  double v23; // fp5
  double v24; // fp7
  double v25; // fp7
  double v26; // fp6
  double v27; // fp5
  double v28; // fp7
  double v29; // fp7
  double v30; // fp6
  double v31; // fp5
  double v32; // fp7
  int v33; // r9
  const bfx::Vec3 *v34; // r10
  float v35; // r7
  double v36; // fp7
  double v37; // fp6
  double v38; // fp5
  double v39; // fp7
  float v40; // [sp+0h] [-10h]
  float v41; // [sp+0h] [-10h]
  float m_y; // [sp+4h] [-Ch]
  float v43; // [sp+4h] [-Ch]
  float v44; // [sp+4h] [-Ch]
  float v45; // [sp+4h] [-Ch]
  float back_chain; // [sp+8h] [-8h]
  float back_chaina; // [sp+8h] [-8h]
  float back_chainb; // [sp+8h] [-8h]
  float back_chainc; // [sp+8h] [-8h]
  float back_chaind; // [sp+8h] [-8h]
  float back_chaine; // [sp+8h] [-8h]

  back_chain = vertArray->m_z;
  v2 = back_chain;
  m_x = vertArray->m_x;
  m_y = vertArray->m_y;
  v4 = m_y;
  v6 = -3.4028235e38;
  v8 = 2;
  _FP11 = (float)((float)__fsqrts((float)((float)((float)(vertArray[1].m_x - vertArray->m_x)
                                                * (float)(vertArray[1].m_x - vertArray->m_x))
                                        + (float)((float)((float)(vertArray[1].m_z - back_chain)
                                                        * (float)(vertArray[1].m_z - back_chain))
                                                + (float)((float)(vertArray[1].m_y - m_y)
                                                        * (float)(vertArray[1].m_y - m_y)))))
                - (float)1.0842022e-19);
  __asm { fsel      f9, f11, f10, f9 }
  v11 = (float)((float)_FP9 * (float)(vertArray[1].m_x - vertArray->m_x));
  v12 = (float)((float)(vertArray[1].m_y - m_y) * (float)_FP9);
  v13 = (float)((float)(vertArray[1].m_z - back_chain) * (float)_FP9);
  result = 0;
  if ( numVerts > 2 )
  {
    if ( numVerts - 2 >= 4 )
    {
      v14 = vertArray + 4;
      do
      {
        v15 = v14[-2].m_x;
        v16 = v14[-2].m_y;
        back_chaina = v14[-2].m_z;
        v17 = (float)(v16
                    - (float)((float)((float)v12
                                    * (float)((float)((float)(v15 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaina - (float)v2) * (float)v13)
                                                    + (float)((float)(v16 - (float)v4) * (float)v12))))
                            + (float)v4));
        v18 = (float)(back_chaina
                    - (float)((float)((float)v13
                                    * (float)((float)((float)(v15 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaina - (float)v2) * (float)v13)
                                                    + (float)((float)(v16 - (float)v4) * (float)v12))))
                            + (float)v2));
        v19 = (float)(v15
                    - (float)((float)((float)v11
                                    * (float)((float)((float)(v15 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaina - (float)v2) * (float)v13)
                                                    + (float)((float)(v16 - (float)v4) * (float)v12))))
                            + (float)m_x));
        v20 = (float)((float)((float)v19 * (float)v19)
                    + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
        if ( v20 > v6 )
        {
          v6 = v20;
          result = v8;
        }
        v43 = v14[-1].m_y;
        v40 = v14[-1].m_x;
        back_chainb = v14[-1].m_z;
        v21 = (float)(v43
                    - (float)((float)((float)v12
                                    * (float)((float)((float)(v40 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chainb - (float)v2) * (float)v13)
                                                    + (float)((float)(v43 - (float)v4) * (float)v12))))
                            + (float)v4));
        v22 = (float)(back_chainb
                    - (float)((float)((float)v13
                                    * (float)((float)((float)(v40 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chainb - (float)v2) * (float)v13)
                                                    + (float)((float)(v43 - (float)v4) * (float)v12))))
                            + (float)v2));
        v23 = (float)(v40
                    - (float)((float)((float)v11
                                    * (float)((float)((float)(v40 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chainb - (float)v2) * (float)v13)
                                                    + (float)((float)(v43 - (float)v4) * (float)v12))))
                            + (float)m_x));
        v24 = (float)((float)((float)v23 * (float)v23)
                    + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)));
        if ( v24 > v6 )
        {
          v6 = v24;
          result = v8 + 1;
        }
        v44 = v14->m_y;
        back_chainc = v14->m_z;
        v25 = (float)(v44
                    - (float)((float)((float)v12
                                    * (float)((float)((float)(v14->m_x - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chainc - (float)v2) * (float)v13)
                                                    + (float)((float)(v44 - (float)v4) * (float)v12))))
                            + (float)v4));
        v26 = (float)(back_chainc
                    - (float)((float)((float)v13
                                    * (float)((float)((float)(v14->m_x - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chainc - (float)v2) * (float)v13)
                                                    + (float)((float)(v44 - (float)v4) * (float)v12))))
                            + (float)v2));
        v27 = (float)(v14->m_x
                    - (float)((float)((float)v11
                                    * (float)((float)((float)(v14->m_x - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chainc - (float)v2) * (float)v13)
                                                    + (float)((float)(v44 - (float)v4) * (float)v12))))
                            + (float)m_x));
        v28 = (float)((float)((float)v27 * (float)v27)
                    + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)));
        if ( v28 > v6 )
        {
          v6 = v28;
          result = v8 + 2;
        }
        v45 = v14[1].m_y;
        v41 = v14[1].m_x;
        back_chaind = v14[1].m_z;
        v29 = (float)(v45
                    - (float)((float)((float)v12
                                    * (float)((float)((float)(v41 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaind - (float)v2) * (float)v13)
                                                    + (float)((float)(v45 - (float)v4) * (float)v12))))
                            + (float)v4));
        v30 = (float)(back_chaind
                    - (float)((float)((float)v13
                                    * (float)((float)((float)(v41 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaind - (float)v2) * (float)v13)
                                                    + (float)((float)(v45 - (float)v4) * (float)v12))))
                            + (float)v2));
        v31 = (float)(v41
                    - (float)((float)((float)v11
                                    * (float)((float)((float)(v41 - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaind - (float)v2) * (float)v13)
                                                    + (float)((float)(v45 - (float)v4) * (float)v12))))
                            + (float)m_x));
        v32 = (float)((float)((float)v31 * (float)v31)
                    + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29)));
        if ( v32 > v6 )
        {
          v6 = v32;
          result = v8 + 3;
        }
        v8 += 4;
        v14 += 4;
      }
      while ( v8 < numVerts - 3 );
    }
    if ( v8 < numVerts )
    {
      v33 = numVerts - v8;
      v34 = &vertArray[v8];
      do
      {
        v35 = v34->m_y;
        back_chaine = v34->m_z;
        v36 = (float)(v35
                    - (float)((float)((float)v12
                                    * (float)((float)((float)(v34->m_x - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaine - (float)v2) * (float)v13)
                                                    + (float)((float)(v35 - (float)v4) * (float)v12))))
                            + (float)v4));
        v37 = (float)(back_chaine
                    - (float)((float)((float)v13
                                    * (float)((float)((float)(v34->m_x - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaine - (float)v2) * (float)v13)
                                                    + (float)((float)(v35 - (float)v4) * (float)v12))))
                            + (float)v2));
        v38 = (float)(v34->m_x
                    - (float)((float)((float)v11
                                    * (float)((float)((float)(v34->m_x - (float)m_x) * (float)v11)
                                            + (float)((float)((float)(back_chaine - (float)v2) * (float)v13)
                                                    + (float)((float)(v35 - (float)v4) * (float)v12))))
                            + (float)m_x));
        v39 = (float)((float)((float)v38 * (float)v38)
                    + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)));
        if ( v39 > v6 )
        {
          v6 = v39;
          result = v8;
        }
        --v33;
        ++v8;
        ++v34;
      }
      while ( v33 != 0 );
    }
  }
  return result;
}


// ========================================================================
// ?CalcCentroidOfConvexPolygon@bfx@@YA?AVVec3@1@QBV21@H@Z
// EA  : 0x83256F68
// RVA : 0x01256F68
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::CalcCentroidOfConvexPolygon(bfx::Vec3 *result, const bfx::Vec3 *vertArray, int numVerts)
{
  float m_y; // r8
  float m_z; // r7
  double v5; // fp6
  double v6; // fp8
  double v7; // fp7
  double v8; // fp9
  float *p_m_z; // r11
  int v10; // ctr
  double v11; // fp3
  double v12; // fp30
  double v13; // fp31
  double v14; // fp4
  double v15; // fp27
  double v16; // fp1
  double v17; // fp2
  double v18; // fp28
  double v19; // fp29
  double v20; // fp22
  double v21; // fp13
  double v22; // fp2
  double v23; // fp31
  double v24; // fp13
  double v25; // fp13
  double v26; // fp0
  int v27; // r10
  double v28; // fp13
  double v29; // fp12
  float *v30; // r11
  double v31; // fp5
  int v32; // ctr
  float *v33; // r11
  const bfx::Vec3 v34; // [sp+0h] [-70h]

  if ( numVerts != 0 )
  {
    v34 = *vertArray;
    v5 = 0.0;
    v6 = 0.0;
    v7 = 0.0;
    v8 = 0.0;
    if ( numVerts - 1 <= 1 )
      goto LABEL_8;
    v10 = numVerts - 2;
    p_m_z = &vertArray[1].m_z;
    do
    {
      v11 = *(p_m_z - 1);
      v12 = p_m_z[1];
      v13 = (float)(*(p_m_z - 1) - v34.m_y);
      v14 = *(p_m_z - 2);
      v15 = (float)(p_m_z[1] - v34.m_x);
      v16 = *p_m_z;
      v17 = (float)(*(p_m_z - 2) - v34.m_x);
      v18 = p_m_z[2];
      v19 = (float)(*p_m_z - v34.m_z);
      p_m_z += 3;
      v20 = (float)((float)(*p_m_z - v34.m_z) * (float)v17);
      v21 = (float)((float)((float)((float)v18 - v34.m_y) * (float)v17) - (float)((float)v13 * (float)v15));
      v22 = (float)((float)((float)v13 * (float)(*p_m_z - v34.m_z)) - (float)((float)v19 * (float)((float)v18 - v34.m_y)));
      v23 = (float)((float)((float)v19 * (float)v15) - (float)v20);
      v24 = __fsqrts((float)((float)((float)v22 * (float)v22)
                           + (float)((float)((float)v21 * (float)v21) + (float)((float)v23 * (float)v23))));
      v8 = (float)((float)v24 + (float)v8);
      v6 = (float)((float)((float)((float)((float)v18 + (float)((float)v11 + v34.m_y)) * (float)0.33333334) * (float)v24)
                 + (float)v6);
      v7 = (float)((float)((float)((float)(*p_m_z + (float)((float)v16 + v34.m_z)) * (float)0.33333334) * (float)v24)
                 + (float)v7);
      v25 = (float)((float)((float)((float)((float)v12 + (float)((float)v14 + v34.m_x)) * (float)0.33333334) * (float)v24)
                  + (float)v5);
      v5 = v25;
      --v10;
    }
    while ( v10 != 0 );
    if ( v8 <= 1.0842022e-19 )
    {
LABEL_8:
      v26 = 0.0;
      v27 = 0;
      v28 = 0.0;
      v29 = 0.0;
      if ( numVerts >= 4 )
      {
        v30 = &vertArray[-1].m_z;
        do
        {
          v27 += 4;
          v31 = (float)(v30[9] + (float)(v30[6] + (float)(v30[3] + (float)v29)));
          v28 = (float)(v30[11] + (float)(v30[8] + (float)(v30[5] + (float)(v30[2] + (float)v28))));
          v26 = (float)(v30[10] + (float)(v30[7] + (float)(v30[4] + (float)(v30[1] + (float)v26))));
          v30 += 12;
          v29 = (float)(*v30 + (float)v31);
        }
        while ( v27 < numVerts - 3 );
      }
      if ( v27 < numVerts )
      {
        v32 = numVerts - v27;
        v33 = &vertArray[v27 - 1].m_z;
        do
        {
          v26 = (float)(v33[1] + (float)v26);
          v28 = (float)(v33[2] + (float)v28);
          v33 += 3;
          v29 = (float)(*v33 + (float)v29);
          --v32;
        }
        while ( v32 != 0 );
      }
      result->m_x = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, numVerts)) * (float)v26;
      result->m_y = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, numVerts)) * (float)v28;
      result->m_z = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, numVerts)) * (float)v29;
    }
    else
    {
      result->m_x = (float)((float)1.0 / (float)v8) * (float)v25;
      result->m_y = (float)((float)1.0 / (float)v8) * (float)v6;
      result->m_z = (float)((float)1.0 / (float)v8) * (float)v7;
    }
  }
  else
  {
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
    result->m_x = bfx::ZERO_VEC.m_x;
    result->m_y = m_y;
    result->m_z = m_z;
  }
  return result;
}


// ========================================================================
// ?CollideLineSegmentAndWorld@bfx@@YA_NPBVSpace@1@ABVCollideData@1@ABVVec3@1@AAV41@@Z
// EA  : 0x83257210
// RVA : 0x01257210
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::CollideLineSegmentAndWorld(
        const bfx::Space *pSpace,
        const bfx::CollideData *data,
        const bfx::Vec3 *start,
        bfx::Vec3 *end)
{
  bfx::Vec3 *p_m_matSpaceToWorld; // r31
  bfx::Vec3 *v8; // r3
  double m_z; // fp0
  double m_y; // fp13
  bfx::Vec3 *v11; // r3
  double v12; // fp0
  int v13; // r31
  double v14; // fp13
  bfx::ColliderManager *m_pColliderManager; // r11
  int (***m_pSpaceCollider)(void); // r9
  int v17; // r3
  double v18; // fp10
  double v20; // fp9
  float m_x; // [sp+50h] [-90h] BYREF
  float v22; // [sp+54h] [-8Ch]
  float v23; // [sp+58h] [-88h]
  float v24[4]; // [sp+60h] [-80h] BYREF
  bfx::Vec3 v25; // [sp+70h] [-70h] BYREF
  bfx::Matrix v26; // [sp+80h] [-60h] BYREF

  p_m_matSpaceToWorld = (bfx::Vec3 *)&pSpace->m_matSpaceToWorld;
  v8 = bfx::Matrix::operator*(
         this: (bfx::Matrix *)&v26.m_data[4],
         result: (bfx::Vec3 *)&pSpace->m_matSpaceToWorld,
         rhs: start);
  m_z = v8->m_z;
  m_y = v8->m_y;
  v24[0] = v8->m_x;
  v24[1] = m_y;
  v24[2] = m_z;
  v11 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v26.m_data[8], result: p_m_matSpaceToWorld, rhs: end);
  v12 = v11->m_z;
  v13 = 0;
  v14 = v11->m_y;
  m_x = v11->m_x;
  v22 = v14;
  v23 = v12;
  m_pColliderManager = bfx::g_pCurInstance->m_pColliderManager;
  m_pSpaceCollider = (int (***)(void))m_pColliderManager->m_pSpaceCollider;
  if ( m_pSpaceCollider != nullptr )
  {
    v17 = (**m_pSpaceCollider)();
LABEL_5:
    v13 = v17;
    goto LABEL_6;
  }
  if ( m_pColliderManager->m_pCollider != nullptr )
  {
    v17 = ((int (__fastcall *)(bfx::Collider *, const bfx::CollideData *, float *, float *))m_pColliderManager->m_pCollider->CollideLineSegmentAndWorld)(
            a1: m_pColliderManager->m_pCollider,
            a2: data,
            a3: v24,
            a4: &m_x);
    goto LABEL_5;
  }
LABEL_6:
  v25.m_x = m_x;
  v25.m_y = v22;
  v25.m_z = v23;
  bfx::Matrix::operator*(this: &v26, result: (bfx::Vec3 *)&pSpace->m_matWorldToSpace, rhs: &v25);
  v18 = v26.m_data[1];
  v20 = v26.m_data[2];
  end->m_x = v26.m_data[0];
  end->m_y = v18;
  end->m_z = v20;
  return v13;
}


// ========================================================================
// ?IntersectLineAndPlane@bfx@@YA_NABVLine@1@ABVPlane@1@AAVVec3@1@@Z
// EA  : 0x83257338
// RVA : 0x01257338
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::IntersectLineAndPlane(const bfx::Line *line, const bfx::Plane *plane, bfx::Vec3 *posOut)
{
  double m_y; // fp0
  double m_z; // fp10
  double v5; // fp8
  double v7; // fp7
  double v8; // fp4
  double v9; // fp13

  m_y = line->m_dir.m_y;
  m_z = line->m_dir.m_z;
  v5 = (float)((float)(line->m_dir.m_z * plane->m_normal.m_z)
             + (float)((float)(line->m_dir.m_x * plane->m_normal.m_x) + (float)(line->m_dir.m_y * plane->m_normal.m_y)));
  if ( __fabs(v5) < 1.0842022e-19 )
    return 0;
  v7 = line->m_pos.m_y;
  v8 = line->m_pos.m_z;
  v9 = (float)((float)((float)(line->m_pos.m_z * plane->m_normal.m_z)
                     + (float)((float)(line->m_pos.m_x * plane->m_normal.m_x)
                             + (float)(line->m_pos.m_y * plane->m_normal.m_y)))
             - plane->m_d);
  posOut->m_x = line->m_pos.m_x
              - (float)(line->m_dir.m_x
                      * (float)((float)((float)((float)(line->m_pos.m_z * plane->m_normal.m_z)
                                              + (float)((float)(line->m_pos.m_x * plane->m_normal.m_x)
                                                      + (float)(line->m_pos.m_y * plane->m_normal.m_y)))
                                      - plane->m_d)
                              / (float)((float)(line->m_dir.m_z * plane->m_normal.m_z)
                                      + (float)((float)(line->m_dir.m_x * plane->m_normal.m_x)
                                              + (float)(line->m_dir.m_y * plane->m_normal.m_y)))));
  posOut->m_y = (float)v7 - (float)((float)m_y * (float)((float)v9 / (float)v5));
  posOut->m_z = (float)v8 - (float)((float)m_z * (float)((float)v9 / (float)v5));
  return 1;
}


// ========================================================================
// ?IntersectTwoPlanes@bfx@@YA_NABVPlane@1@0AAVLine@1@@Z
// EA  : 0x832573D0
// RVA : 0x012573D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

BOOL __fastcall bfx::IntersectTwoPlanes(const bfx::Plane *plane1, const bfx::Plane *plane2, bfx::Line *lineOut)
{
  double v3; // fp2
  double v4; // fp1
  double v5; // fp11
  double v8; // fp3
  double v9; // fp13
  char v10; // r9
  double m_z; // fp0
  double m_y; // fp11
  double m_x; // fp8
  double v15; // fp10
  double v16; // fp3
  double m_d; // fp7
  float v18; // [sp+50h] [-30h]
  float v19; // [sp+54h] [-2Ch]
  bfx::Line v20; // [sp+60h] [-20h] BYREF

  v3 = (float)((float)(plane2->m_normal.m_x * plane1->m_normal.m_z)
             - (float)(plane1->m_normal.m_x * plane2->m_normal.m_z));
  v4 = (float)((float)(plane1->m_normal.m_x * plane2->m_normal.m_y)
             - (float)(plane2->m_normal.m_x * plane1->m_normal.m_y));
  v5 = (float)((float)(plane2->m_normal.m_z * plane1->m_normal.m_y)
             - (float)(plane2->m_normal.m_y * plane1->m_normal.m_z));
  _FP6 = (float)((float)__fsqrts((float)((float)((float)v5 * (float)v5)
                                       + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3))))
               - (float)1.0842022e-19);
  __asm { fsel      f4, f6, f5, f0 }
  v8 = (float)((float)((float)(plane2->m_normal.m_z * plane1->m_normal.m_y)
                     - (float)(plane2->m_normal.m_y * plane1->m_normal.m_z))
             * (float)_FP4);
  lineOut->m_dir.m_x = (float)((float)(plane2->m_normal.m_z * plane1->m_normal.m_y)
                             - (float)(plane2->m_normal.m_y * plane1->m_normal.m_z))
                     * (float)_FP4;
  lineOut->m_dir.m_y = (float)v3 * (float)_FP4;
  lineOut->m_dir.m_z = (float)v4 * (float)_FP4;
  v9 = v8;
  if ( v8 != 0.0 || lineOut->m_dir.m_y != 0.0 || (v10 = 1, lineOut->m_dir.m_z != 0.0) )
    v10 = 0;
  if ( v10 != 0 )
    return false;
  m_z = plane1->m_normal.m_z;
  m_y = lineOut->m_dir.m_y;
  m_x = plane1->m_normal.m_x;
  v15 = (float)((float)v8 * plane1->m_normal.m_y);
  m_d = plane1->m_d;
  v19 = plane1->m_normal.m_y * plane1->m_d;
  v18 = (float)(lineOut->m_dir.m_z * plane1->m_normal.m_y) - (float)(lineOut->m_dir.m_y * plane1->m_normal.m_z);
  v16 = (float)(lineOut->m_dir.m_z * plane1->m_normal.m_x);
  v20.m_pos.m_z = plane1->m_normal.m_z * plane1->m_d;
  v20.m_pos.m_x = (float)m_x * (float)m_d;
  v20.m_pos.m_y = v19;
  v20.m_dir.m_x = v18;
  v20.m_dir.m_z = (float)((float)m_y * (float)m_x) - (float)v15;
  v20.m_dir.m_y = (float)((float)v9 * (float)m_z) - (float)v16;
  return (unsigned __int8)bfx::IntersectLineAndPlane(line: &v20, plane: plane2, posOut: &lineOut->m_pos) != 0;
}


// ========================================================================
// ?ClipLineSegParameterizedAgainstPlane@bfx@@YA_NABVPlane@1@AAVLineSegParameterized@1@@Z
// EA  : 0x83257558
// RVA : 0x01257558
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::ClipLineSegParameterizedAgainstPlane(const bfx::Plane *plane, bfx::LineSegParameterized *seg)
{
  double v2; // fp0
  int result; // r3
  double m_maxS; // fp13
  double v5; // fp0
  bool v6; // zf

  v2 = (float)((float)(seg->m_dir.m_x * plane->m_normal.m_x)
             + (float)((float)(seg->m_dir.m_y * plane->m_normal.m_y) + (float)(seg->m_dir.m_z * plane->m_normal.m_z)));
  if ( __fabs(v2) < 1.0842022e-19 )
  {
    if ( (float)((float)((float)(plane->m_normal.m_x * seg->m_pos.m_x)
                       + (float)((float)(seg->m_pos.m_y * plane->m_normal.m_y)
                               + (float)(seg->m_pos.m_z * plane->m_normal.m_z)))
               - plane->m_d) < 0.0 )
    {
      seg->m_maxS = 0.0;
      seg->m_minS = 0.0;
      return 0;
    }
    return 1;
  }
  m_maxS = seg->m_maxS;
  v6 = v2 >= 0.0;
  v5 = (float)((float)((float)((float)(plane->m_normal.m_x * seg->m_pos.m_x)
                             + (float)((float)(seg->m_pos.m_y * plane->m_normal.m_y)
                                     + (float)(seg->m_pos.m_z * plane->m_normal.m_z)))
                     - plane->m_d)
             / (float)((float)((float)(seg->m_dir.m_x * plane->m_normal.m_x)
                             + (float)((float)(seg->m_dir.m_y * plane->m_normal.m_y)
                                     + (float)(seg->m_dir.m_z * plane->m_normal.m_z)))
                     * (float)-1.0));
  if ( !v6 )
  {
    if ( v5 <= m_maxS )
    {
      if ( v5 < seg->m_minS )
        return 0;
      seg->m_maxS = (float)((float)((float)(plane->m_normal.m_x * seg->m_pos.m_x)
                                  + (float)((float)(seg->m_pos.m_y * plane->m_normal.m_y)
                                          + (float)(seg->m_pos.m_z * plane->m_normal.m_z)))
                          - plane->m_d)
                  / (float)((float)((float)(seg->m_dir.m_x * plane->m_normal.m_x)
                                  + (float)((float)(seg->m_dir.m_y * plane->m_normal.m_y)
                                          + (float)(seg->m_dir.m_z * plane->m_normal.m_z)))
                          * (float)-1.0);
    }
    return 1;
  }
  if ( v5 > m_maxS )
    return 0;
  result = 1;
  if ( v5 >= seg->m_minS )
    seg->m_minS = v5;
  return result;
}


// ========================================================================
// ?BuildClipPlanesForRotatedBox@bfx@@YAXABVBox@1@ABVMatrix@1@PAVPlane@1@@Z
// EA  : 0x832576D8
// RVA : 0x012576D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::BuildClipPlanesForRotatedBox(
        const bfx::Box *boxLCoord,
        bfx::Vec3 *mat,
        bfx::Plane *pClipPlanesOut)
{
  double m_x; // fp31
  double m_y; // fp30
  double m_z; // fp29
  bfx::Vec3 *v9; // r3
  double v10; // fp13
  double v11; // fp12
  double v12; // fp10
  double v13; // fp9
  double v14; // fp8
  double v15; // fp29
  double v16; // fp31
  double v17; // fp30
  bfx::Vec3 *v18; // r3
  double v19; // fp9
  double v20; // fp2
  double v21; // fp1
  double v22; // fp8
  double v23; // fp7
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  bfx::Vec3 *v27; // r3
  double v28; // fp3
  double v29; // fp2
  double v30; // fp0
  double v31; // fp13
  double v32; // fp12
  double v33; // fp29
  double v34; // fp31
  double v35; // fp30
  bfx::Vec3 *v36; // r3
  double v37; // fp5
  double v38; // fp4
  double v39; // fp12
  double v40; // fp3
  double v41; // fp2
  double v42; // fp31
  double v43; // fp30
  double v44; // fp29
  bfx::Vec3 *v45; // r3
  double v46; // fp7
  double v47; // fp6
  double v48; // fp4
  double v49; // fp3
  double v50; // fp2
  double v51; // fp29
  double v52; // fp31
  double v53; // fp30
  bfx::Vec3 *v54; // r3
  double v55; // fp3
  double v56; // fp2
  double v57; // fp8
  double v58; // fp6
  double v59; // fp1
  bfx::Matrix v60; // [sp+50h] [-60h] BYREF

  m_x = mat->m_x;
  m_y = mat->m_y;
  m_z = mat->m_z;
  v9 = bfx::Matrix::operator*(this: &v60, result: mat, rhs: &boxLCoord->m_min);
  v10 = mat->m_y;
  v11 = mat->m_z;
  v12 = (float)(v9->m_z * (float)m_z);
  v13 = v9->m_y;
  v14 = v9->m_x;
  pClipPlanesOut->m_normal.m_x = mat->m_x;
  pClipPlanesOut->m_normal.m_y = v10;
  pClipPlanesOut->m_normal.m_z = v11;
  pClipPlanesOut->m_d = (float)((float)v14 * (float)m_x) + (float)((float)((float)v13 * (float)m_y) + (float)v12);
  v15 = -mat->m_z;
  v16 = -mat->m_y;
  v17 = -mat->m_x;
  v18 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v60.m_data[4], result: mat, rhs: &boxLCoord->m_max);
  v19 = (float)(v18->m_y * (float)v16);
  v20 = mat->m_x;
  v21 = mat->m_y;
  v22 = v18->m_z;
  v23 = v18->m_x;
  pClipPlanesOut[1].m_normal.m_z = -mat->m_z;
  pClipPlanesOut[1].m_normal.m_x = -v20;
  pClipPlanesOut[1].m_normal.m_y = -v21;
  pClipPlanesOut[1].m_d = (float)((float)v23 * (float)v17) + (float)((float)((float)v22 * (float)v15) + (float)v19);
  v24 = mat[1].m_y;
  v25 = mat[1].m_z;
  v26 = mat[2].m_x;
  v27 = bfx::Matrix::operator*(this: &v60, result: mat, rhs: &boxLCoord->m_min);
  v28 = mat[1].m_z;
  v29 = mat[2].m_x;
  v30 = (float)(v27->m_y * (float)v25);
  v31 = v27->m_z;
  v32 = v27->m_x;
  pClipPlanesOut[2].m_normal.m_x = mat[1].m_y;
  pClipPlanesOut[2].m_normal.m_y = v28;
  pClipPlanesOut[2].m_normal.m_z = v29;
  pClipPlanesOut[2].m_d = (float)((float)v24 * (float)v32) + (float)((float)((float)v31 * (float)v26) + (float)v30);
  v33 = -mat[2].m_x;
  v34 = -mat[1].m_z;
  v35 = -mat[1].m_y;
  v36 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v60.m_data[4], result: mat, rhs: &boxLCoord->m_max);
  v37 = (float)(v36->m_y * (float)v34);
  v38 = v36->m_z;
  v39 = v36->m_x;
  v40 = mat[1].m_z;
  v41 = mat[1].m_y;
  pClipPlanesOut[3].m_normal.m_z = -mat[2].m_x;
  pClipPlanesOut[3].m_normal.m_y = -v40;
  pClipPlanesOut[3].m_normal.m_x = -v41;
  pClipPlanesOut[3].m_d = (float)((float)v39 * (float)v35) + (float)((float)((float)v38 * (float)v33) + (float)v37);
  v42 = mat[2].m_z;
  v43 = mat[3].m_x;
  v44 = mat[3].m_y;
  v45 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v60.m_data[4], result: mat, rhs: &boxLCoord->m_min);
  v46 = mat[3].m_x;
  v47 = mat[3].m_y;
  v48 = (float)(v45->m_y * (float)v43);
  v49 = v45->m_z;
  v50 = v45->m_x;
  pClipPlanesOut[4].m_normal.m_x = mat[2].m_z;
  pClipPlanesOut[4].m_normal.m_y = v46;
  pClipPlanesOut[4].m_normal.m_z = v47;
  pClipPlanesOut[4].m_d = (float)((float)v50 * (float)v42) + (float)((float)((float)v49 * (float)v44) + (float)v48);
  v51 = -mat[3].m_y;
  v52 = -mat[3].m_x;
  v53 = -mat[2].m_z;
  v54 = bfx::Matrix::operator*(this: &v60, result: mat, rhs: &boxLCoord->m_max);
  v55 = (float)(v54->m_y * (float)v52);
  v56 = v54->m_z;
  v57 = -mat[2].m_z;
  v58 = -mat[3].m_x;
  v59 = v54->m_x;
  pClipPlanesOut[5].m_normal.m_z = -mat[3].m_y;
  pClipPlanesOut[5].m_normal.m_x = v57;
  pClipPlanesOut[5].m_normal.m_y = v58;
  pClipPlanesOut[5].m_d = (float)((float)v59 * (float)v53) + (float)((float)((float)v56 * (float)v51) + (float)v55);
}


// ========================================================================
// ?ClipLineSegAgainstPlanes@bfx@@YA_NABV?$Array@VPlane@bfx@@@1@AAVLineSeg@1@@Z
// EA  : 0x83257948
// RVA : 0x01257948
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::ClipLineSegAgainstPlanes(const bfx::Array<bfx::Plane> *planes, bfx::LineSeg *seg)
{
  double m_x; // fp28
  int m_size; // r31
  double v4; // fp31
  double v5; // fp30
  bfx::Vec3 *p_m_v1; // r9
  double v7; // fp0
  double v8; // fp29
  double v9; // fp13
  bfx::Plane *m_data; // r30
  int v11; // r10
  int v12; // r10
  int v13; // r8
  float v14; // r8
  float m_y; // r11
  int result; // r3
  double m_z; // fp12
  float v18; // [sp+50h] [-50h] BYREF
  float v19; // [sp+54h] [-4Ch] BYREF
  bfx::Vec3 v20; // [sp+58h] [-48h] BYREF

  m_x = seg->m_v0.m_x;
  m_size = planes->m_size;
  v4 = (float)(seg->m_v1.m_x - seg->m_v0.m_x);
  v5 = (float)(seg->m_v1.m_y - seg->m_v0.m_y);
  p_m_v1 = &seg->m_v1;
  v7 = 0.0;
  v8 = (float)(seg->m_v1.m_z - seg->m_v0.m_z);
  v9 = 1.0;
  v20.m_x = seg->m_v1.m_x - seg->m_v0.m_x;
  v20.m_y = v5;
  v18 = 0.0;
  v19 = 1.0;
  v20.m_z = v8;
  if ( m_size <= 0 )
  {
LABEL_6:
    v14 = seg->m_v0.m_x;
    m_y = seg->m_v0.m_y;
    result = 1;
    v20.m_z = seg->m_v0.m_z;
    m_z = v20.m_z;
    v20.m_x = v14;
    v20.m_y = m_y;
    seg->m_v0.m_y = m_y + (float)((float)v5 * (float)v7);
    seg->m_v0.m_x = v14 + (float)((float)v4 * (float)v7);
    seg->m_v0.m_z = (float)m_z + (float)((float)v8 * (float)v7);
    p_m_v1->m_x = (float)((float)v4 * (float)v9) + v14;
    p_m_v1->m_y = (float)((float)v5 * (float)v9) + m_y;
    p_m_v1->m_z = (float)((float)v8 * (float)v9) + (float)m_z;
  }
  else
  {
    m_data = planes->m_data;
    v11 = 0;
    while ( bfx::ClipLineSegAgainstPlane(
              plane: (bfx::Plane *)((char *)m_data + v11),
              seg,
              segVec: &v20,
              minS: &v18,
              maxS: &v19) )
    {
      v11 = v12 + 16;
      if ( v13 + 1 >= m_size )
      {
        v7 = v18;
        v9 = v19;
        goto LABEL_6;
      }
    }
    p_m_v1->m_x = m_x;
    p_m_v1->m_y = seg->m_v0.m_y;
    p_m_v1->m_z = seg->m_v0.m_z;
    return 0;
  }
  return result;
}


// ========================================================================
// ?SupplyProbeResults@bfx@@YAXPAVProbeRequest@1@H@Z
// EA  : 0x83257AB8
// RVA : 0x01257AB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::SupplyProbeResults(bfx::ProbeRequest *pProbeRequestArray, int numRequests)
{
  int v4; // r27
  bfx::ColliderManager *m_pColliderManager; // r25
  float *p_m_x; // r29
  bool *p_m_collided; // r26
  int *p_m_requestID; // r28
  bfx::List<bfx::ProbeReq *>::Node *m_pEnd; // r10
  bfx::List<bfx::ProbeReq *>::Node *m_pNext; // r9
  bfx::ProbeReq *m_val; // r30
  bfx::HandleTargetBase *v12; // r11
  double v13; // fp0
  double v14; // fp13
  double v15; // fp12
  bfx::List<bfx::ProbeReq *> *m_pPendingRequests; // r10
  bfx::List<bfx::ProbeReq *>::Node *v17; // r9
  bfx::List<bfx::ProbeReq *> *v18; // r8
  bfx::Pool::Node *v19; // r6
  bfx::Pool *m_pPool; // r10
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-80h]
  bfx::Vec3 v22; // [sp+58h] [-78h] BYREF
  bfx::Matrix v23; // [sp+68h] [-68h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogSupplyProbeResults(pProbeRequestArray, numRequests);
  v4 = 0;
  m_pColliderManager = bfx::g_pCurInstance->m_pColliderManager;
  if ( numRequests > 0 )
  {
    p_m_x = &pProbeRequestArray[-1].m_collidePos.m_x;
    p_m_collided = &pProbeRequestArray[-1].m_collided;
    p_m_requestID = &pProbeRequestArray->m_requestID;
    do
    {
      m_pEnd = m_pColliderManager->m_pPendingRequests->m_pEnd;
      if ( m_pEnd->m_pNext == m_pEnd )
        break;
      m_pNext = m_pEnd->m_pNext;
      m_val = m_pNext->m_val;
      if ( m_pNext->m_val->m_requestID == *p_m_requestID )
      {
        v12 = m_val->m_space.m_pProxy != nullptr ? m_val->m_space.m_pProxy->m_pTarget : nullptr;
        m_val->m_probeResultsValid = true;
        p_m_collided += 56;
        m_val->m_collided = *p_m_collided;
        v13 = p_m_x[16];
        v14 = p_m_x[15];
        p_m_x += 14;
        v15 = *p_m_x;
        v22.m_z = v13;
        v22.m_y = v14;
        v22.m_x = v15;
        bfx::Matrix::operator*(this: &v23, result: (bfx::Vec3 *)&v12[15].m_pProxy, rhs: &v22);
        m_val->m_collidePos.m_x = v23.m_data[0];
        m_pPendingRequests = m_pColliderManager->m_pPendingRequests;
        m_val->m_collidePos.m_y = v23.m_data[1];
        v17 = m_pPendingRequests->m_pEnd;
        m_val->m_collidePos.m_z = v23.m_data[2];
        m_val->m_pendingRequestIter.m_pCur = v17;
        v18 = m_pColliderManager->m_pPendingRequests;
        v19 = (bfx::Pool::Node *)v18->m_pEnd->m_pNext;
        v19[2].m_pNext[1].m_pNext = v19[1].m_pNext;
        v19[1].m_pNext[2].m_pNext = v19[2].m_pNext;
        m_pPool = v18->m_pPool;
        v19->m_pNext = v18->m_pPool->m_data.m_pUnused;
        m_pPool->m_data.m_pUnused = v19;
      }
      else
      {
        p_m_collided += 56;
        p_m_x += 14;
      }
      ++v4;
      p_m_requestID += 14;
    }
    while ( v4 < numRequests );
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$76935
// EA  : 0x83257C38
// RVA : 0x01257C38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_76935()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 208 + 80));
}


// ========================================================================
// ?ClipPolygonAgainstPlane@bfx@@YAXABVPlane@1@ABV?$Array@VVec3@bfx@@@1@AAV31@@Z
// EA  : 0x83257C60
// RVA : 0x01257C60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::ClipPolygonAgainstPlane(
        const bfx::Plane *plane,
        const bfx::Array<bfx::Vec3> *ptsIn,
        bfx::Array<bfx::EndPt> *ptsOut)
{
  signed int m_size; // r30
  double v7; // fp13
  bool v8; // r22
  signed int v9; // r28
  bool v10; // r9
  int v11; // r27
  int i; // r25
  bfx::Vec3 *m_data; // r10
  bfx::Vec3 *v14; // r31
  double v15; // fp31
  bool v16; // r11
  bool v17; // r24
  double v18; // fp10
  double v19; // fp8
  double v20; // fp7
  float *v21; // r11
  double v22; // fp12
  double v23; // fp11
  const bfx::EndPt *v24; // r4
  double m_y; // fp10
  double m_z; // fp8
  double v27; // fp7
  float *p_m_x; // r11
  double v29; // fp12
  double v30; // fp11
  bfx::EndPt v31; // [sp+50h] [-80h] BYREF
  float v32[4]; // [sp+60h] [-70h] BYREF

  m_size = ptsIn->m_size;
  if ( m_size != 0 )
  {
    v7 = (float)((float)(plane->m_normal.m_x * ptsIn->m_data[m_size - 1].m_x)
               + (float)((float)(ptsIn->m_data[m_size - 1].m_z * plane->m_normal.m_z)
                       + (float)(ptsIn->m_data[m_size - 1].m_y * plane->m_normal.m_y)));
    v8 = v7 >= plane->m_d;
    v9 = 0;
    v10 = v8;
    if ( m_size > 0 )
    {
      v11 = m_size - 1;
      for ( i = 0; ; ++i )
      {
        m_data = ptsIn->m_data;
        v14 = &ptsIn->m_data[i];
        v15 = (float)((float)(v14->m_x * plane->m_normal.m_x)
                    + (float)((float)(v14->m_y * plane->m_normal.m_y) + (float)(v14->m_z * plane->m_normal.m_z)));
        v16 = v9 == v11 ? v8 : v15 >= plane->m_d;
        v17 = v16;
        if ( v16 )
          break;
        if ( v10 )
        {
          m_y = v14->m_y;
          m_z = v14->m_z;
          v27 = (float)((float)((float)v15 - plane->m_d) / (float)((float)v15 - (float)v7));
          __twllei(m_size, 0);
          v24 = (const bfx::EndPt *)v32;
          p_m_x = &m_data[(v11 + v9) % m_size].m_x;
          __twlgei(m_size & ~(__ROL4__(v11 + v9, 1) - 1), 0xFFFFFFFF);
          v29 = (float)((float)((float)m_y - p_m_x[1]) * (float)v27);
          v30 = (float)((float)((float)m_z - p_m_x[2]) * (float)v27);
          v32[0] = ptsIn->m_data[i].m_x - (float)((float)(ptsIn->m_data[i].m_x - *p_m_x) * (float)v27);
          v32[1] = (float)m_y - (float)v29;
          v32[2] = (float)m_z - (float)v30;
LABEL_13:
          bfx::Array<bfx::FollowerBuddyData>::push_back(this: ptsOut, val: v24);
        }
        ++v9;
        v7 = v15;
        v10 = v17;
        if ( v9 >= m_size )
          return;
      }
      if ( !v10 )
      {
        v18 = v14->m_y;
        v19 = v14->m_z;
        v20 = (float)((float)((float)v15 - plane->m_d) / (float)((float)v15 - (float)v7));
        v21 = &m_data[(v11 + v9) % m_size].m_x;
        __twllei(m_size, 0);
        __twlgei(m_size & ~(__ROL4__(v11 + v9, 1) - 1), 0xFFFFFFFF);
        v22 = (float)((float)((float)v18 - v21[1]) * (float)v20);
        v23 = (float)((float)((float)v19 - v21[2]) * (float)v20);
        v31.m_val = ptsIn->m_data[i].m_x - (float)((float)(ptsIn->m_data[i].m_x - *v21) * (float)v20);
        *(float *)&v31.m_pAABB = (float)v18 - (float)v22;
        *(float *)&v31.m_type = (float)v19 - (float)v23;
        bfx::Array<bfx::FollowerBuddyData>::push_back(this: ptsOut, val: &v31);
      }
      v24 = (const bfx::EndPt *)v14;
      goto LABEL_13;
    }
  }
}


// ========================================================================
// ?ClipPolygonAgainstVolume@bfx@@YAXABV?$Array@VPlane@bfx@@@1@AAV?$Array@VVec3@bfx@@@1@@Z
// EA  : 0x83257EC0
// RVA : 0x01257EC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::ClipPolygonAgainstVolume(const bfx::Array<bfx::Plane> *planes, bfx::Array<bfx::Vec3> *pts)
{
  int v4; // r4
  int v5; // r26
  int v6; // r28
  int m_size; // r10
  int m_cap; // r9
  bfx::EndPt *m_data; // r4
  int v10; // r11
  int v11; // r10
  int v12; // r8
  bfx::MemoryManager *m_pMemoryManager; // r3
  bfx::Array<bfx::EndPt> v14[5]; // [sp+50h] [-50h] BYREF

  memset(v14, 0, 12);
  v14[0].m_tag = MEM_TEMP;
  v4 = pts->m_size + planes->m_size;
  if ( v4 > 0 )
    bfx::Array<bfx::IslandConnection>::expand_cap(this: v14, size: v4);
  v5 = 0;
  if ( planes->m_size <= 0 )
  {
LABEL_12:
    m_data = v14[0].m_data;
    if ( v14[0].m_data == nullptr )
      return;
    m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
    goto LABEL_14;
  }
  v6 = 0;
  while ( 1 )
  {
    bfx::ClipPolygonAgainstPlane(plane: &planes->m_data[v6], ptsIn: pts, ptsOut: v14);
    m_size = v14[0].m_size;
    m_cap = v14[0].m_cap;
    m_data = (bfx::EndPt *)pts->m_data;
    pts->m_data = (bfx::Vec3 *)v14[0].m_data;
    v14[0].m_data = m_data;
    v10 = pts->m_size;
    pts->m_size = m_size;
    v11 = pts->m_cap;
    pts->m_cap = m_cap;
    v12 = pts->m_size;
    v14[0].m_size = v10;
    v14[0].m_cap = v11;
    if ( v12 == 0 )
      break;
    if ( v10 >= 0 )
    {
      v14[0].m_size = __CFADD__(-v10, v10 ^ 0x80000000) ? 0 : v10;
    }
    else
    {
      if ( v11 < 0 )
        bfx::Array<bfx::IslandConnection>::expand_cap(this: v14, size: 0);
      v14[0].m_size = 0;
    }
    ++v5;
    ++v6;
    if ( v5 >= planes->m_size )
      goto LABEL_12;
  }
  if ( m_data != nullptr )
  {
    m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
LABEL_14:
    bfx::MemoryManager::Free(this: m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// __unwind$77276
// EA  : 0x83257FF8
// RVA : 0x01257FF8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_77276()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 80));
}


// ========================================================================
// ?DoesPolygonIntersectVolume@bfx@@YA_NQBVVec3@1@HABV?$Array@VPlane@bfx@@@1@@Z
// EA  : 0x83258028
// RVA : 0x01258028
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::DoesPolygonIntersectVolume(
        const bfx::Vec3 *vertArray,
        int numVerts,
        const bfx::Array<bfx::Plane> *planes)
{
  int v4; // r29
  int v6; // r7
  bfx::Plane *m_data; // r9
  char v8; // r8
  int v9; // r10
  float *p_m_y; // r11
  int v11; // r28
  const bfx::Vec3 *v12; // r11
  bfx::Vec3 *m_x_low; // r9
  int m_y_low; // r10
  int m_z_low; // r11
  const bfx::Vec3 *v16; // r30
  bfx::Vec3 *v17; // r8
  float m_y; // r7
  float m_z; // r6
  double v20; // fp13
  double v21; // fp12
  const bfx::EndPt *v22; // r30
  int m_size; // [sp+50h] [-80h]
  bfx::Array<bfx::Vec3> v25; // [sp+60h] [-70h] BYREF
  bfx::LineSeg v26; // [sp+70h] [-60h] BYREF

  v4 = numVerts;
  v6 = 0;
  m_size = planes->m_size;
  if ( m_size > 0 )
  {
    m_data = planes->m_data;
    do
    {
      v8 = 1;
      v9 = 0;
      if ( numVerts > 0 )
      {
        p_m_y = &vertArray->m_y;
        while ( (float)((float)(p_m_y[1] * m_data->m_normal.m_z)
                      + (float)((float)(*p_m_y * m_data->m_normal.m_y) + (float)(*(p_m_y - 1) * m_data->m_normal.m_x))) < (double)m_data->m_d )
        {
          ++v9;
          p_m_y += 3;
          if ( v9 >= numVerts )
            goto LABEL_9;
        }
        v8 = 0;
      }
LABEL_9:
      if ( v8 != 0 )
        return 0;
      ++v6;
      ++m_data;
    }
    while ( v6 < m_size );
  }
  v11 = 0;
  v12 = &vertArray[numVerts];
  m_x_low = (bfx::Vec3 *)LODWORD(v12[-1].m_x);
  m_y_low = LODWORD(v12[-1].m_y);
  m_z_low = LODWORD(v12[-1].m_z);
  if ( numVerts > 0 )
  {
    v16 = vertArray;
    while ( 1 )
    {
      v17 = (bfx::Vec3 *)LODWORD(v16->m_x);
      m_y = v16->m_y;
      m_z = v16->m_z;
      LODWORD(v26.m_v1.m_x) = m_x_low;
      LODWORD(v26.m_v1.m_y) = m_y_low;
      LODWORD(v26.m_v0.m_x) = v17;
      v26.m_v0.m_y = m_y;
      v26.m_v0.m_z = m_z;
      LODWORD(v26.m_v1.m_z) = m_z_low;
      if ( (unsigned __int8)bfx::ClipLineSegAgainstPlanes(planes, seg: &v26) != 0 )
        return 1;
      ++v11;
      v20 = v16->m_y;
      v21 = v16->m_z;
      *(float *)&v25.m_data = v16->m_x;
      ++v16;
      *(float *)&v25.m_size = v20;
      *(float *)&v25.m_cap = v21;
      if ( v11 >= v4 )
        break;
      m_z_low = v25.m_cap;
      m_y_low = v25.m_size;
      m_x_low = v25.m_data;
    }
  }
  memset(&v25, 0, 12);
  v25.m_tag = MEM_TEMP;
  if ( v4 + 10 > 0 )
    bfx::Array<bfx::IslandConnection>::expand_cap(this: (bfx::Array<bfx::EndPt> *)&v25, size: v4 + 10);
  if ( v4 > 0 )
  {
    v22 = (const bfx::EndPt *)vertArray;
    do
    {
      bfx::Array<bfx::FollowerBuddyData>::push_back(this: (bfx::Array<bfx::EndPt> *)&v25, val: v22);
      --v4;
      ++v22;
    }
    while ( v4 != 0 );
  }
  bfx::ClipPolygonAgainstVolume(planes, pts: &v25);
  if ( v25.m_size != 0 )
  {
    if ( v25.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v25.m_data);
    return 1;
  }
  if ( v25.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v25.m_data);
  return 0;
}


// ========================================================================
// __unwind$77457
// EA  : 0x83258224
// RVA : 0x01258224
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_77457()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 208 + 96));
}


// ========================================================================
// ?SortFaceVertsCCW@bfx@@YAXABVPlane@1@AAV?$Array@VVec3@bfx@@@1@@Z
// EA  : 0x83258258
// RVA : 0x01258258
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::SortFaceVertsCCW(const bfx::Plane *facePlane, bfx::Array<bfx::Vec3> *faceVerts)
{
  float *m_data; // r4
  int m_size; // r11
  unsigned int v6; // r28
  int v7; // r6
  unsigned int v8; // r30
  unsigned int v9; // r5
  int v10; // r26
  float *v11; // r3
  bfx::Vec3 *v12; // r11
  double v13; // fp5
  double v14; // fp2
  double v17; // fp0
  double v18; // fp13
  double v19; // fp12
  int v20; // r10
  float *v21; // r7
  unsigned int v22; // ctr
  float *v23; // r9
  bfx::Vec3 *v24; // r8
  double v25; // fp5
  double v26; // fp1
  unsigned int v29; // r8
  double v30; // fp0
  unsigned int v31; // r11
  unsigned int v32; // r10
  float *v33; // r9
  float *v34; // r10
  unsigned int v35; // ctr
  bfx::Vec3 *v36; // r11
  bfx::Vec3 *v37; // r10
  float m_x; // r8
  int m_y_low; // r7
  double v40; // fp13
  double v41; // fp0
  bfx::Array<float> v42; // [sp+60h] [-50h] BYREF

  memset(&v42, 0, 12);
  v42.m_tag = MEM_TEMP;
  m_size = faceVerts->m_size;
  m_data = nullptr;
  if ( m_size > 0 )
  {
    bfx::Array<float>::expand_cap(this: &v42, size: m_size);
    m_data = v42.m_data;
  }
  v6 = faceVerts->m_size;
  if ( v6 != 2 )
  {
    v7 = 0;
    v8 = v6 - 2;
    v9 = 2;
    v10 = v6 - 2;
    v11 = m_data + 1;
    do
    {
      *(v11 - 1) = 0.0;
      *v11 = 0.0;
      v12 = &faceVerts->m_data[v7];
      v13 = (float)(v12[1].m_y - v12->m_y);
      v14 = (float)(v12[1].m_z - v12->m_z);
      _FP12 = (float)((float)__fsqrts((float)((float)((float)v14 * (float)v14)
                                            + (float)((float)((float)(v12[1].m_x - v12->m_x)
                                                            * (float)(v12[1].m_x - v12->m_x))
                                                    + (float)((float)v13 * (float)v13))))
                    - (float)1.0842022e-19);
      __asm { fsel      f7, f12, f8, f11 }
      v17 = (float)((float)(v12[1].m_z - v12->m_z) * (float)_FP7);
      v18 = (float)((float)(v12[1].m_y - v12->m_y) * (float)_FP7);
      v19 = (float)((float)(v12[1].m_x - v12->m_x) * (float)_FP7);
      if ( v9 < v6 )
      {
        v20 = v7 * 12 + 24;
        v21 = v11;
        v22 = v6 - v9;
        do
        {
          v23 = (float *)((char *)&faceVerts->m_data->m_x + v20);
          v24 = &faceVerts->m_data[v7];
          v25 = (float)(v23[1] - v24->m_y);
          v26 = (float)(v23[2] - v24->m_z);
          _FP4 = (float)((float)__fsqrts((float)((float)((float)v26 * (float)v26)
                                               + (float)((float)((float)(*v23 - v24->m_x) * (float)(*v23 - v24->m_x))
                                                       + (float)((float)v25 * (float)v25))))
                       - (float)1.0842022e-19);
          __asm { fsel      f4, f4, f3, f11 }
          *++v21 = (float)((float)((float)((float)((float)(v23[1] - v24->m_y) * (float)_FP4) * (float)v19)
                                 - (float)((float)((float)(*v23 - v24->m_x) * (float)_FP4) * (float)v18))
                         * facePlane->m_normal.m_z)
                 + (float)((float)(facePlane->m_normal.m_x
                                 * (float)((float)((float)((float)(v23[2] - v24->m_z) * (float)_FP4) * (float)v18)
                                         - (float)((float)((float)(v23[1] - v24->m_y) * (float)_FP4) * (float)v17)))
                         + (float)(facePlane->m_normal.m_y
                                 * (float)((float)((float)((float)(*v23 - v24->m_x) * (float)_FP4) * (float)v17)
                                         - (float)((float)((float)(v23[2] - v24->m_z) * (float)_FP4) * (float)v19))));
          v20 += 12;
          --v22;
        }
        while ( v22 != 0 );
      }
      v29 = v9 - 1;
      v30 = 0.0;
      v31 = v9;
      if ( v9 < v6 )
      {
        if ( v10 >= 4 )
        {
          v32 = v29 + 3;
          v33 = v11 + 3;
          do
          {
            if ( *(v33 - 2) > v30 )
            {
              v30 = *(v33 - 2);
              v29 = v31;
            }
            if ( *(v33 - 1) > v30 )
            {
              v30 = *(v33 - 1);
              v29 = v32 - 1;
            }
            if ( *v33 > v30 )
            {
              v30 = *v33;
              v29 = v32;
            }
            if ( v33[1] > v30 )
            {
              v30 = v33[1];
              v29 = v32 + 1;
            }
            v31 += 4;
            v33 += 4;
            v32 += 4;
          }
          while ( v31 < v6 - 3 );
        }
        if ( v31 < v6 )
        {
          v34 = &m_data[v31];
          v35 = v6 - v31;
          do
          {
            if ( *v34 > v30 )
            {
              v30 = *v34;
              v29 = v31;
            }
            ++v31;
            ++v34;
            --v35;
          }
          while ( v35 != 0 );
        }
      }
      --v8;
      v36 = &faceVerts->m_data[v7];
      --v10;
      v37 = &faceVerts->m_data[v29];
      m_x = v36[1].m_x;
      ++v11;
      m_y_low = LODWORD(v36[1].m_y);
      ++v9;
      ++v7;
      v42.m_cap = LODWORD(v36[1].m_z);
      v40 = *(float *)&v42.m_cap;
      *(float *)&v42.m_data = m_x;
      v42.m_size = m_y_low;
      v36[1].m_x = v37->m_x;
      v36[1].m_y = v37->m_y;
      v41 = *(float *)&v42.m_size;
      v36[1].m_z = v37->m_z;
      v37->m_x = m_x;
      v37->m_y = v41;
      v37->m_z = v40;
    }
    while ( v8 != 0 );
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$77573
// EA  : 0x8325855C
// RVA : 0x0125855C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_77573()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// ?GetProbeRequests@bfx@@YAHPAVProbeRequest@1@H@Z
// EA  : 0x83258590
// RVA : 0x01258590
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

int __fastcall bfx::GetProbeRequests(bfx::ProbeRequest *pProbeRequestArray, int arraySize)
{
  int v4; // r27
  bfx::List<bfx::ProbeReq *> *m_pPendingRequests; // r23
  bfx::List<bfx::ProbeReq *>::Node *m_pEnd; // r10
  bfx::List<bfx::ProbeReq *>::Node *m_pNext; // r24
  bool *p_m_collided; // r30
  bfx::ProbeReq *m_val; // r29
  bfx::Vec3 **m_pProxy; // r10
  bfx::Vec3 *v11; // r11
  bfx::Vec3 *v12; // r28
  bfx::Vec3 *v13; // r3
  float m_z; // r7
  float m_x; // r6
  bfx::Vec3 *v16; // r3
  float v17; // r10
  float m_y; // r9
  double v19; // fp9
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-A0h]
  float v22; // [sp+70h] [-80h]
  bfx::Matrix v23; // [sp+78h] [-78h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogGetProbeRequests(arraySize);
  if ( pProbeRequestArray != nullptr && arraySize > 0 )
  {
    v4 = 0;
    m_pPendingRequests = bfx::g_pCurInstance->m_pColliderManager->m_pPendingRequests;
    m_pEnd = m_pPendingRequests->m_pEnd;
    m_pNext = m_pEnd->m_pNext;
    if ( m_pNext != m_pEnd )
    {
      p_m_collided = &pProbeRequestArray->m_collided;
      do
      {
        m_val = m_pNext->m_val;
        m_pProxy = (bfx::Vec3 **)m_pNext->m_val->m_space.m_pProxy;
        if ( m_pProxy != nullptr )
          v11 = *m_pProxy;
        else
          v11 = nullptr;
        v12 = v11 + 5;
        *((_QWORD *)p_m_collided - 4) = m_val->m_probeUserData;
        v13 = bfx::Matrix::operator*(this: &v23, result: v11 + 5, rhs: &m_val->m_startPos);
        m_z = v13->m_z;
        m_x = v13->m_x;
        *((float *)p_m_collided - 5) = v13->m_y;
        *((float *)p_m_collided - 6) = m_x;
        *((float *)p_m_collided - 4) = m_z;
        v16 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v23.m_data[4], result: v12, rhs: &m_val->m_endPos);
        ++v4;
        v17 = v16->m_x;
        m_y = v16->m_y;
        v19 = v16->m_z;
        *p_m_collided = false;
        v22 = v19;
        *((float *)p_m_collided - 1) = v22;
        *((float *)p_m_collided - 3) = v17;
        *((float *)p_m_collided - 2) = m_y;
        *((float *)p_m_collided + 1) = v17;
        *((float *)p_m_collided + 2) = m_y;
        *((float *)p_m_collided + 3) = v22;
        *((_DWORD *)p_m_collided + 4) = m_val->m_requestID;
        p_m_collided += 56;
        if ( v4 == arraySize )
          break;
        m_pNext = m_pNext->m_pNext;
      }
      while ( m_pNext != m_pPendingRequests->m_pEnd );
    }
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v4;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
}


// ========================================================================
// __unwind$77919
// EA  : 0x8325872C
// RVA : 0x0125872C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_77919()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 240 + 80));
}


// ========================================================================
// ??0ProbeReq@bfx@@QAA@PAVSpace@1@ABVVec3@1@11_K@Z
// EA  : 0x83258760
// RVA : 0x01258760
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

bfx::ProbeReq *__fastcall bfx::ProbeReq::ProbeReq(
        bfx::ProbeReq *this,
        bfx::Space *pSpace,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        const bfx::Vec3 *referencePos,
        int a6,
        unsigned __int64 probeUserData)
{
  unsigned __int64 v7; // r25
  bfx::List<bfx::ProbeReq *>::iterator *p_m_pendingRequestIter; // r29
  float m_z; // r8
  bfx::ColliderManager *m_pColliderManager; // r4
  bfx::List<bfx::ProbeReq *> *m_pPendingRequests; // r5
  bfx::Pool::Node *m_pEnd; // r28
  bfx::Pool::Node *Node; // r3

  LODWORD(v7) = a6;
  p_m_pendingRequestIter = &this->m_pendingRequestIter;
  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: &this->m_space, pTarget: pSpace);
  this->m_startPos = *startPos;
  this->m_endPos = *endPos;
  this->m_referencePos.m_x = referencePos->m_x;
  this->m_referencePos.m_y = referencePos->m_y;
  m_z = referencePos->m_z;
  this->m_probeResultsValid = false;
  this->m_collided = false;
  this->m_referencePos.m_z = m_z;
  this->m_probeUserData = v7;
  this->m_collidePos = *endPos;
  m_pColliderManager = bfx::g_pCurInstance->m_pColliderManager;
  this->m_requestID = m_pColliderManager->m_nextRequestID++;
  this->m_pendingRequestIter.m_pCur = bfx::g_pCurInstance->m_pColliderManager->m_pPendingRequests->m_pEnd;
  m_pPendingRequests = bfx::g_pCurInstance->m_pColliderManager->m_pPendingRequests;
  m_pEnd = (bfx::Pool::Node *)m_pPendingRequests->m_pEnd;
  Node = bfx::Pool::GetNode(this: m_pPendingRequests->m_pPool);
  if ( Node != nullptr )
    Node->m_pNext = (bfx::Pool::Node *)this;
  Node[1].m_pNext = m_pEnd;
  Node[2].m_pNext = m_pEnd[2].m_pNext;
  m_pEnd[2].m_pNext[1].m_pNext = Node;
  m_pEnd[2].m_pNext = Node;
  p_m_pendingRequestIter->m_pCur = p_m_pendingRequestIter->m_pCur->m_pPrev;
  return this;
}


// ========================================================================
// __unwind$78179
// EA  : 0x83258890
// RVA : 0x01258890
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_78179()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: *(bfx::Handle<bfx::Space> **)(v0 - 160 + 180));
}


// ========================================================================
// ??1ProbeReq@bfx@@QAA@XZ
// EA  : 0x832588B8
// RVA : 0x012588B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::ProbeReq::~ProbeReq(bfx::ProbeReq *this)
{
  bfx::List<bfx::ProbeReq *>::Node *m_pCur; // r11
  bfx::ColliderManager *m_pColliderManager; // r9
  bfx::List<bfx::ProbeReq *> *m_pPendingRequests; // r10
  bfx::Pool *m_pPool; // r4
  bfx::HandleProxy *m_pProxy; // r3
  bool v7; // cr58

  m_pCur = this->m_pendingRequestIter.m_pCur;
  m_pColliderManager = bfx::g_pCurInstance->m_pColliderManager;
  m_pPendingRequests = m_pColliderManager->m_pPendingRequests;
  if ( m_pCur != m_pPendingRequests->m_pEnd )
  {
    m_pCur->m_pPrev->m_pNext = m_pCur->m_pNext;
    m_pCur->m_pNext->m_pPrev = m_pCur->m_pPrev;
    m_pPool = m_pPendingRequests->m_pPool;
    m_pCur->m_val = (bfx::ProbeReq *)m_pPendingRequests->m_pPool->m_data.m_pUnused;
    m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pCur;
  }
  m_pProxy = this->m_space.m_pProxy;
  v7 = this->m_space.m_pProxy == nullptr;
  this->m_pendingRequestIter.m_pCur = m_pColliderManager->m_pPendingRequests->m_pEnd;
  if ( !v7 )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_space.m_pProxy = nullptr;
  }
}


// ========================================================================
// ?CreateProbeReq@bfx@@YAPAVProbeReq@1@PAVSpace@1@ABVVec3@1@11_K@Z
// EA  : 0x83258958
// RVA : 0x01258958
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

bfx::ProbeReq *__fastcall bfx::CreateProbeReq(
        bfx::Space *pSpace,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        const bfx::Vec3 *referencePos,
        unsigned __int64 probeUserData)
{
  int v9; // r26
  unsigned __int64 v10; // r10
  bfx::Pool::Node *Node; // r3

  v9 = HIDWORD(probeUserData);
  Node = bfx::Pool::GetNode(this: bfx::g_pCurInstance->m_pColliderManager->m_pProbeRequestPool);
  if ( Node != nullptr )
    return bfx::ProbeReq::ProbeReq(
             this: (bfx::ProbeReq *)Node,
             pSpace,
             startPos,
             endPos,
             referencePos,
             a6: v9,
             probeUserData: v10);
  else
    return nullptr;
}


// ========================================================================
// __unwind$78333
// EA  : 0x832589C4
// RVA : 0x012589C4
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void _unwind_78333()
{
  int v0; // r12

  bfx::ProbeReq::operator delete(mem: *(bfx::Pool::Node **)(v0 - 144 + 80));
}


// ========================================================================
// ?DestroyProbeReq@bfx@@YAXPAVProbeReq@1@@Z
// EA  : 0x832589F0
// RVA : 0x012589F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.cpp
// ========================================================================

void __fastcall bfx::DestroyProbeReq(bfx::ProbeReq *pProbeReq)
{
  bfx::Pool *m_pProbeRequestPool; // r9

  if ( pProbeReq != nullptr )
  {
    bfx::ProbeReq::~ProbeReq(this: pProbeReq);
    m_pProbeRequestPool = bfx::g_pCurInstance->m_pColliderManager->m_pProbeRequestPool;
    pProbeReq->m_space.m_pProxy = (bfx::HandleProxy *)m_pProbeRequestPool->m_data.m_pUnused;
    m_pProbeRequestPool->m_data.m_pUnused = (bfx::Pool::Node *)pProbeReq;
  }
}

