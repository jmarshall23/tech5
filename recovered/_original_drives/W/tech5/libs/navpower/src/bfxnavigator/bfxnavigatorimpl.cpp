
// ========================================================================
// ?SetPos@NavigatorImpl@bfx@@QAAXABVVec3@2@PAVArea@2@@Z
// EA  : 0x83261F18
// RVA : 0x01261F18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::SetPos(bfx::NavigatorImpl *this, const bfx::Vec3 *navigatorPos, bfx::Area *pArea)
{
  bfx::Vec3 *p_m_smartPath; // r30
  bfx::RepulsorImpl *m_pRepulsor; // r3
  char v6; // [sp+50h] [-30h] BYREF

  this->m_requestedPos = *navigatorPos;
  p_m_smartPath = (bfx::Vec3 *)&this->m_smartPath;
  bfx::SmartPath::SetStartData(this: &this->m_smartPath, startPos: navigatorPos, pStartArea: pArea);
  this->m_pos = *bfx::SmartPath::GetSnappedStartPos(this: (bfx::SmartPath *)&v6, result: p_m_smartPath);
  m_pRepulsor = this->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
    bfx::RepulsorImpl::SetPos(this: m_pRepulsor, pos: &this->m_pos);
}


// ========================================================================
// ?GetUnobstructedPos@NavigatorImpl@bfx@@QAA?AVVec3@2@XZ
// EA  : 0x83261FA8
// RVA : 0x01261FA8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

bfx::NavigatorImpl *__fastcall bfx::NavigatorImpl::GetUnobstructedPos(bfx::NavigatorImpl *this, bfx::Vec3 *result)
{
  bfx::SmartPath::GetSnappedStartPos((bfx::SmartPath *)this, result: result + 14);
  return this;
}


// ========================================================================
// ?GetArea@NavigatorImpl@bfx@@QAAPAVArea@2@XZ
// EA  : 0x83261FE0
// RVA : 0x01261FE0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

bfx::Area *__fastcall bfx::NavigatorImpl::GetArea(bfx::NavigatorImpl *this)
{
  return bfx::SmartPath::GetSnappedStartArea(this: &this->m_smartPath);
}


// ========================================================================
// ?SetGoalPos@NavigatorImpl@bfx@@QAAXABVVec3@2@PAVArea@2@@Z
// EA  : 0x83261FE8
// RVA : 0x01261FE8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::SetGoalPos(bfx::NavigatorImpl *this, const bfx::Vec3 *goalPos, bfx::Area *pArea)
{
  bfx::Vec3 *p_m_smartPath; // r30
  char v5; // [sp+50h] [-30h] BYREF

  this->m_requestedGoalPos = *goalPos;
  p_m_smartPath = (bfx::Vec3 *)&this->m_smartPath;
  bfx::SmartPath::SetGoalData(this: &this->m_smartPath, goalPos, pGoalArea: pArea);
  this->m_goalPos = *bfx::SmartPath::GetSnappedGoalPos(this: (bfx::SmartPath *)&v5, result: p_m_smartPath);
}


// ========================================================================
// ?GetRepulsorNormal@NavigatorImpl@bfx@@UAA_NAAVVec3@2@@Z
// EA  : 0x83262060
// RVA : 0x01262060
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

int __fastcall bfx::NavigatorImpl::GetRepulsorNormal(bfx::NavigatorImpl *this, bfx::Vec3 *normalOut)
{
  bfx::Vec3 *SnappedStartArea; // r4
  float *v4; // r3
  char v6; // [sp+50h] [-20h] BYREF

  SnappedStartArea = (bfx::Vec3 *)bfx::SmartPath::GetSnappedStartArea(this: &this->m_smartPath);
  if ( SnappedStartArea == nullptr )
    return 0;
  v4 = (float *)bfx::Area::CalcNormal(this: (bfx::Area *)&v6, result: SnappedStartArea);
  normalOut->m_x = *v4;
  normalOut->m_y = v4[1];
  normalOut->m_z = v4[2];
  return 1;
}


// ========================================================================
// ?EndOfFrameUpdate@NavigatorImpl@bfx@@QAAXM@Z
// EA  : 0x832620E0
// RVA : 0x012620E0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::EndOfFrameUpdate(bfx::NavigatorImpl *this, double simTime)
{
  bfx::Vec3 *v2; // r8
  bfx::RepulsorImpl *m_pRepulsor; // r10
  float back_chain[4]; // [sp+0h] [-10h] BYREF

  if ( simTime != 0.0 )
  {
    if ( simTime <= 1.0842022e-19 )
    {
      v2 = &bfx::ZERO_VEC;
    }
    else
    {
      v2 = (bfx::Vec3 *)back_chain;
      back_chain[2] = (float)((float)1.0 / (float)simTime) * (float)(this->m_pos.m_z - this->m_prevPos.m_z);
    }
    this->m_vel = *v2;
    this->m_prevPos = this->m_pos;
    m_pRepulsor = this->m_pRepulsor;
    if ( m_pRepulsor != nullptr )
      m_pRepulsor->m_vel = this->m_vel;
  }
}


// ========================================================================
// ?GetPosAlongPath@NavigatorImpl@bfx@@QAA_NAAVPosAlongPathSpecInternal@2@AAVPosAlongPathDataInternal@2@@Z
// EA  : 0x832621C0
// RVA : 0x012621C0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

BOOL __fastcall bfx::NavigatorImpl::GetPosAlongPath(
        bfx::NavigatorImpl *this,
        bfx::PosAlongPathSpecInternal *spec,
        bfx::PosAlongPathDataInternal *dataOut)
{
  return bfx::SmartPath::GetPosAlongPath(this: &this->m_smartPath, spec, dataOut);
}


// ========================================================================
// ?ClearCachedData@NavigatorImpl@bfx@@QAAXXZ
// EA  : 0x832621C8
// RVA : 0x012621C8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::ClearCachedData(bfx::NavigatorImpl *this)
{
  bfx::SmartPath::ClearCachedData(this: &this->m_smartPath);
}


// ========================================================================
// ?IsHeadingInside@NavWedge@bfx@@QAA_NM@Z
// EA  : 0x832621D0
// RVA : 0x012621D0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

int __fastcall bfx::NavWedge::IsHeadingInside(bfx::NavWedge *this, double headingInDegrees)
{
  double m_endAngle; // fp13
  int result; // r3
  double v4; // fp0
  double m_startAngle; // fp13

  m_endAngle = this->m_endAngle;
  if ( m_endAngle >= headingInDegrees && headingInDegrees >= this->m_startAngle )
    return 1;
  if ( m_endAngle <= 180.0 )
    return 0;
  v4 = (float)((float)headingInDegrees + (float)360.0);
  if ( m_endAngle < v4 )
    return 0;
  m_startAngle = this->m_startAngle;
  result = 1;
  if ( v4 < m_startAngle )
    return 0;
  return result;
}


// ========================================================================
// ?MakeWellFormed@bfx@@YAXAAVNavWedge@1@@Z
// EA  : 0x83262230
// RVA : 0x01262230
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::MakeWellFormed(bfx::NavWedge *wedge)
{
  double m_startAngle; // fp0
  double v2; // fp0
  double m_endAngle; // fp0
  double v4; // fp0

  m_startAngle = wedge->m_startAngle;
  if ( m_startAngle >= -180.0 )
  {
    if ( m_startAngle <= 180.0 )
      goto LABEL_6;
    v2 = (float)(wedge->m_startAngle - (float)360.0);
  }
  else
  {
    v2 = (float)(wedge->m_startAngle + (float)360.0);
  }
  wedge->m_startAngle = v2;
LABEL_6:
  m_endAngle = wedge->m_endAngle;
  if ( m_endAngle >= -180.0 )
  {
    if ( m_endAngle <= 180.0 )
      goto LABEL_11;
    v4 = (float)(wedge->m_endAngle - (float)360.0);
  }
  else
  {
    v4 = (float)(wedge->m_endAngle + (float)360.0);
  }
  wedge->m_endAngle = v4;
LABEL_11:
  if ( wedge->m_startAngle > (double)wedge->m_endAngle )
    wedge->m_endAngle = wedge->m_endAngle + (float)360.0;
}


// ========================================================================
// ?SetDebugName@NavigatorImpl@bfx@@QAAXPBD@Z
// EA  : 0x83262310
// RVA : 0x01262310
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::SetDebugName(bfx::NavigatorImpl *this, const char *name)
{
  bfx::String v3[2]; // [sp+50h] [-20h] BYREF

  bfx::String::String(this: v3, data: name);
  bfx::String::operator=(this: &this->m_debugName, rhs: v3);
  if ( v3[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3[0].m_data);
}


// ========================================================================
// __unwind$85166
// EA  : 0x83262374
// RVA : 0x01262374
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_85166()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(v0 - 112 + 80));
}


// ========================================================================
// ?CalcUpVector@NavigatorImpl@bfx@@QBA?AVVec3@2@PBVArea@2@@Z
// EA  : 0x832623A0
// RVA : 0x012623A0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

bfx::NavigatorImpl *__fastcall bfx::NavigatorImpl::CalcUpVector(
        bfx::NavigatorImpl *this,
        bfx::Vec3 *result,
        bfx::Vec3 *pMyArea)
{
  bfx::Vec3 *UpVec; // r3
  double m_y; // fp13
  double m_z; // fp12
  long double v8; // fp2
  long double v9; // fp2
  float v10; // r10
  float v11; // r9
  bfx::Vec3 v13; // [sp+50h] [-40h] BYREF
  bfx::Area var30; // [sp+60h] [-30h] BYREF

  if ( pMyArea != nullptr )
  {
    if ( pMyArea[4].m_x >= 0.0 && HIBYTE(result[13].m_x) != 0 )
    {
      UpVec = bfx::GetUpVec(result: (bfx::Vec3 *)&var30);
      m_y = UpVec->m_y;
      m_z = UpVec->m_z;
      v13.m_x = UpVec->m_x;
      v13.m_y = m_y;
      v13.m_z = m_z;
    }
    else
    {
      bfx::Area::CalcNormal(this: &var30, result: pMyArea);
      bfx::GetUpVec(result: &v13);
      *(double *)&v8 = (float)(result[12].m_z * (float)0.017453292);
      v9 = cos(x: v8);
      if ( (float)((float)(v13.m_x * *(float *)&var30.m_pProxy)
                 + (float)((float)(*(float *)&var30.m_dynAreaData.m_data * v13.m_y)
                         + (float)(*(float *)&var30.m_pFirstLink * v13.m_z))) <= (double)(float)*(double *)&v9 )
      {
        v13.m_x = *(float *)&var30.m_pProxy;
        v13.m_y = *(float *)&var30.m_dynAreaData.m_data;
        v13.m_z = *(float *)&var30.m_pFirstLink;
      }
    }
    v10 = v13.m_y;
    v11 = v13.m_z;
    this->__vftable = (bfx::NavigatorImpl_vtbl *)LODWORD(v13.m_x);
    *(float *)&this->m_creatorType = v10;
    *(float *)&this->m_pSpace = v11;
  }
  else
  {
    bfx::GetUpVec(result: (bfx::Vec3 *)this);
  }
  return this;
}


// ========================================================================
// ?CSGetInitialConstraint@NavigatorImpl@bfx@@SAXPAXAAVInitialConstraint@2@@Z
// EA  : 0x832624B8
// RVA : 0x012624B8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::CSGetInitialConstraint(void *pObject, bfx::InitialConstraint *ic)
{
  if ( pObject != nullptr )
    ic->m_constraintType = CONSTRAINT_NONE;
}


// ========================================================================
// ?CSMove@NavigatorImpl@bfx@@SAXPAXABVVec3@2@M@Z
// EA  : 0x832624D0
// RVA : 0x012624D0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::CSMove(char *pObject, const bfx::Vec3 *vel, double time)
{
  const bfx::Vec3 *v4; // r31
  double v5; // fp10
  double v6; // fp9
  double v7; // fp7
  double v8; // fp6
  bfx::RepulsorImpl *v9; // r3

  if ( pObject != nullptr )
  {
    v4 = (const bfx::Vec3 *)(pObject + 20);
    v5 = (float)(vel->m_y * (float)time);
    v6 = (float)(vel->m_z * (float)time);
    v7 = *((float *)pObject + 6);
    v8 = *((float *)pObject + 7);
    *((float *)pObject + 5) = (float)(vel->m_x * (float)time) + *((float *)pObject + 5);
    *((float *)pObject + 6) = (float)v5 + (float)v7;
    *((float *)pObject + 7) = (float)v6 + (float)v8;
    v9 = *((bfx::RepulsorImpl **)pObject + 41);
    if ( v9 != nullptr )
      bfx::RepulsorImpl::SetPos(this: v9, pos: v4);
    bfx::SmartPath::SetStartData(this: (bfx::SmartPath *)(pObject + 168), startPos: v4, pStartArea: nullptr);
  }
}


// ========================================================================
// ?CSGetPos@NavigatorImpl@bfx@@SA?BVVec3@2@PAX@Z
// EA  : 0x83262570
// RVA : 0x01262570
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

const bfx::Vec3 *__fastcall bfx::NavigatorImpl::CSGetPos(const bfx::Vec3 *result, float *pObject)
{
  float m_y; // r8
  float m_z; // r7
  float v4; // r10
  float v5; // r9

  if ( pObject != nullptr )
  {
    v4 = pObject[6];
    v5 = pObject[7];
    result->m_x = pObject[5];
    result->m_y = v4;
    result->m_z = v5;
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
// ?ApplyLimits_NavigatorTune@bfx@@YAXAAUNavigatorTune@1@@Z
// EA  : 0x832625B8
// RVA : 0x012625B8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::ApplyLimits_NavigatorTune(
        bfx::NavigatorTune *tune,
        int a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  double Scale; // fp1
  double v8; // fp1
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // r5
  int v12; // r4
  const char *v13; // r3
  double v14; // fp1
  __int64 v15; // r10
  __int64 v16; // r8
  int v17; // r5
  int v18; // r4
  const char *v19; // r3

  tune->m_bulk = bfx::ApplyLimits_Bulk(
                   bulk: tune->m_bulk,
                   pNameOfVariable: (const char *)tune,
                   a3: (int)"navigatorBulk",
                   a4: a3,
                   a5: a4,
                   a6: a5,
                   a7: a6);
  Scale = bfx::GetScale();
  if ( tune->m_radius < 0.0 )
    tune->m_radius = (float)Scale * (float)0.25;
  v8 = bfx::GetScale();
  LODWORD(v9) = &unk_82410000;
  tune->m_detectionCylinderTune.m_radius = bfx::LimitWarn(
                                             val: tune->m_detectionCylinderTune.m_radius,
                                             min: (float)((float)v8 * (float)0.0099999998),
                                             max: 3.4028235e38,
                                             name: v13,
                                             a5: v12,
                                             a6: v11,
                                             a7: (unsigned int)"NavigatorTune::DetectionCylinderTune::m_radius",
                                             a8: v10,
                                             a9: v9);
  v14 = bfx::GetScale();
  HIDWORD(v15) = &unk_82410000;
  tune->m_detectionCylinderTune.m_height = bfx::LimitWarn(
                                             val: tune->m_detectionCylinderTune.m_height,
                                             min: (float)((float)v14 * (float)0.0099999998),
                                             max: 3.4028235e38,
                                             name: v19,
                                             a5: v18,
                                             a6: v17,
                                             a7: (unsigned int)"NavigatorTune::DetectionCylinderTune::m_height",
                                             a8: v16,
                                             a9: v15);
}


// ========================================================================
// ?SetTune@NavigatorImpl@bfx@@QAAXPBUNavigatorTune@2@@Z
// EA  : 0x83262678
// RVA : 0x01262678
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::SetTune(bfx::NavigatorImpl *this, const bfx::NavigatorTune *pTune)
{
  bfx::NavigatorTune *p_m_tune; // r30
  unsigned int m_planLayer; // r29
  double m_radius; // fp31
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // r6
  int v9; // r5
  int v10; // r4
  bfx::RepulsorImpl *m_pRepulsor; // r11
  double v12; // fp13
  unsigned int v13; // r4
  bfx::RepulsorImpl *v14; // r11

  p_m_tune = &this->m_tune;
  m_planLayer = this->m_tune.m_planLayer;
  m_radius = this->m_tune.m_detectionCylinderTune.m_radius;
  memcpy(Dst: &this->m_tune, Src: pTune, Size: sizeof(this->m_tune));
  bfx::ApplyLimits_NavigatorTune(tune: p_m_tune, a2: v10, a3: v9, a4: v8, a5: v7, a6: v6);
  m_pRepulsor = this->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
  {
    v12 = p_m_tune->m_radius;
    m_pRepulsor->m_radiusData.m_radius = p_m_tune->m_radius;
    m_pRepulsor->m_radiusData.m_outerCushion = (float)v12 * (float)0.2;
    m_pRepulsor->m_radiusData.m_innerCushion = (float)v12 * (float)0.2;
    this->m_pRepulsor->m_bulk = this->m_tune.m_bulk;
    this->m_pRepulsor->m_blockageFlags = this->m_tune.m_repulsorBlockageFlags;
    this->m_pRepulsor->m_repulsorIdentityFlags = this->m_tune.m_repulsorIdentityFlags;
  }
  v13 = this->m_tune.m_planLayer;
  if ( v13 != m_planLayer )
    bfx::SmartPath::SetNavLayer(this: &this->m_smartPath, layer: v13);
  v14 = this->m_pRepulsor;
  if ( v14 != nullptr && this->m_tune.m_detectionCylinderTune.m_radius != m_radius )
    v14->m_origDetectRadius = this->m_tune.m_detectionCylinderTune.m_radius;
}


// ========================================================================
// ?EnableRepulsor@NavigatorImpl@bfx@@QAAX_N@Z
// EA  : 0x83262758
// RVA : 0x01262758
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::EnableRepulsor(bfx::NavigatorImpl *this, bool enable)
{
  double m_radius; // fp13
  double v4; // fp31
  unsigned int v5; // r8
  bfx::RepulsorImpl *v6; // r3
  bfx::RepulsorImpl *v7; // r3
  double m_bulk; // fp0
  bfx::RepulsorImpl *v9; // r11
  bfx::RepulsorImpl *m_pRepulsor; // r3
  int v11; // [sp+8h] [-B8h]
  int v12; // [sp+Ch] [-B4h]
  int v13; // [sp+10h] [-B0h]
  int v14; // [sp+14h] [-ACh]
  int v15; // [sp+18h] [-A8h]
  int v16; // [sp+1Ch] [-A4h]
  int v17; // [sp+20h] [-A0h]
  int v18; // [sp+24h] [-9Ch]
  int v19; // [sp+28h] [-98h]
  int v20; // [sp+2Ch] [-94h]
  int v21; // [sp+30h] [-90h]
  int v22; // [sp+34h] [-8Ch]
  int v23; // [sp+38h] [-88h]
  int v24; // [sp+3Ch] [-84h]
  int v25; // [sp+40h] [-80h]
  int v26; // [sp+44h] [-7Ch]
  int v27; // [sp+48h] [-78h]
  int v28; // [sp+4Ch] [-74h]
  int v29; // [sp+50h] [-70h]
  bfx::RadiusData v30; // [sp+68h] [-58h] BYREF
  void (__fastcall *v31)(void *, bfx::InitialConstraint *); // [sp+80h] [-40h]
  void (__fastcall *v32)(char *, const bfx::Vec3 *, double); // [sp+84h] [-3Ch]
  const bfx::Vec3 *(__fastcall *v33)(const bfx::Vec3 *, float *); // [sp+88h] [-38h]
  bfx::NavigatorImpl *v34; // [sp+8Ch] [-34h]

  if ( !enable || this->m_pRepulsor != nullptr )
  {
    if ( !enable )
    {
      m_pRepulsor = this->m_pRepulsor;
      if ( m_pRepulsor != nullptr )
      {
        ((void (__fastcall *)(bfx::RepulsorImpl *, int))m_pRepulsor->dtr_HandleTargetBase)(a1: m_pRepulsor, a2: 1);
        this->m_pRepulsor = nullptr;
      }
    }
  }
  else
  {
    m_radius = this->m_tune.m_radius;
    v30.m_radius = this->m_tune.m_radius;
    v4 = this->m_tune.m_detectionCylinderTune.m_radius;
    v30.m_outerCushion = (float)m_radius * (float)0.2;
    v30.m_innerCushion = v30.m_outerCushion;
    v6 = (bfx::RepulsorImpl *)bfx::MemoryManager::Malloc(
                                this: bfx::g_pCurInstance->m_pMemoryManager,
                                size: 0x74u,
                                tag: bfx::MEM_BFXNAVIGATOR);
    if ( v6 != nullptr )
      v7 = bfx::RepulsorImpl::RepulsorImpl(
             this: v6,
             pSpace: this->m_pSpace,
             pos: &this->m_pos,
             vel: &bfx::ZERO_VEC,
             radiusData: &v30,
             detectRadius: v4,
             blockageFlags: v5,
             repulsorIdentityFlags: this->m_tune.m_repulsorBlockageFlags,
             pOwner: (bfx::RepulsorOwner *)this->m_tune.m_repulsorIdentityFlags,
             a10: v11,
             a11: v12,
             a12: v13,
             a13: v14,
             a14: v15,
             a15: v16,
             a16: v17,
             a17: v18,
             a18: v19,
             a19: v20,
             a20: v21,
             a21: v22,
             a22: v23,
             a23: v24,
             a24: v25,
             a25: v26,
             a26: v27,
             a27: v28,
             a28: v29,
             a29: this);
    else
      v7 = nullptr;
    m_bulk = this->m_tune.m_bulk;
    this->m_pRepulsor = v7;
    v7->m_bulk = m_bulk;
    v34 = this;
    v31 = bfx::NavigatorImpl::CSGetInitialConstraint;
    v32 = bfx::NavigatorImpl::CSMove;
    v33 = bfx::NavigatorImpl::CSGetPos;
    v9 = this->m_pRepulsor;
    v9->m_solverData.m_pObject = this;
    v9->m_solverData.m_pGetInitialConstraintFunc = bfx::NavigatorImpl::CSGetInitialConstraint;
    v9->m_solverData.m_pMoveFunc = (void (__fastcall *)(void *, const bfx::Vec3 *, float))bfx::NavigatorImpl::CSMove;
    v9->m_solverData.m_pGetPosFunc = (const bfx::Vec3 *(__fastcall *)(const bfx::Vec3 *, void *))bfx::NavigatorImpl::CSGetPos;
  }
}


// ========================================================================
// __unwind$85534
// EA  : 0x832628BC
// RVA : 0x012628BC
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_85534()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 192 + 96), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?DrawNavigatorCone@NavigatorImpl@bfx@@QBAXMABVColor@2@@Z
// EA  : 0x832628E8
// RVA : 0x012628E8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::DrawNavigatorCone(
        bfx::NavigatorImpl *this,
        double sizeMultiplier,
        const bfx::Color *drawColor,
        const bfx::Color *a4)
{
  unsigned int m_planLayer; // r11
  double v8; // fp31
  int v9; // r30
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Vec3 *m_pArea; // r5
  const bfx::Color *v12; // r6
  int v13; // r5
  long double v14; // fp2
  bfx::Vec3 v15; // [sp+50h] [-80h] BYREF
  bfx::Matrix v16; // [sp+60h] [-70h] BYREF

  m_planLayer = this->m_tune.m_planLayer;
  v8 = (float)(this->m_tune.m_radius * (float)3.0);
  if ( m_planLayer >= 0x20 )
    v9 = 0;
  else
    v9 = *(_DWORD *)(*((_DWORD *)this->m_pSpace->m_components.m_data + 1) + 4 * (m_planLayer + 2));
  m_pProxy = this->m_smartPath.m_snappedStartArea.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = (bfx::Vec3 *)m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  if ( m_pArea != nullptr )
  {
    bfx::NavigatorImpl::CalcUpVector(this: (bfx::NavigatorImpl *)&v15, result: (bfx::Vec3 *)this, pMyArea: m_pArea);
    bfx::BuildMatAroundAxis(result: &v16, zaxis: &v15, pos: &this->m_pos);
    if ( v9 != 0 )
      v8 = *(float *)(v9 + 16);
    *((double *)&v14 + 1) = (float)((float)sizeMultiplier * this->m_tune.m_radius);
    *(double *)&v14 = (float)((float)v8 * (float)sizeMultiplier);
    bfx::DrawCone(a1: this->m_pSpace, a2: (bfx::Vec3 *)&v16, radius: v14, numSegs: v13, color: v12, a6: 6, a7: a4);
  }
}


// ========================================================================
// ??1NavigatorImpl@bfx@@UAA@XZ
// EA  : 0x83262A80
// RVA : 0x01262A80
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::~NavigatorImpl(bfx::NavigatorImpl *this)
{
  bfx::NavWedge *m_data; // r4
  char *v3; // r4

  this->__vftable = (bfx::NavigatorImpl_vtbl *)&bfx::NavigatorImpl::`vftable';
  bfx::NavigatorImpl::EnableRepulsor(this, enable: false);
  m_data = this->m_debugData.m_freeWedges.m_data;
  this->m_debugData.m_freeWedges.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_debugData.m_freeWedges.m_data = nullptr;
  }
  this->m_debugData.m_freeWedges.m_cap = 0;
  bfx::SmartPath::~SmartPath(this: &this->m_smartPath);
  v3 = this->m_debugName.m_data;
  if ( v3 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3);
  this->__vftable = (bfx::NavigatorImpl_vtbl *)&bfx::RepulsorOwner::`vftable';
}


// ========================================================================
// __unwind$85957
// EA  : 0x83262B14
// RVA : 0x01262B14
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_85957()
{
  int v0; // r12

  bfx::RepulsorOwner::~RepulsorOwner(this: *(bfx::RepulsorOwner **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$85958
// EA  : 0x83262B3C
// RVA : 0x01262B3C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_85958()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$85959
// EA  : 0x83262B68
// RVA : 0x01262B68
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_85959()
{
  int v0; // r12

  bfx::SmartPath::~SmartPath(this: (bfx::SmartPath *)(*(_DWORD *)(v0 - 128 + 148) + 168));
}


// ========================================================================
// __unwind$85960
// EA  : 0x83262B94
// RVA : 0x01262B94
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_85960()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 448));
}


// ========================================================================
// ?Draw@NavigatorImpl@bfx@@QAAXXZ
// EA  : 0x83262BC0
// RVA : 0x01262BC0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __fastcall bfx::NavigatorImpl::Draw(bfx::NavigatorImpl *this, const bfx::Color *a2)
{
  bfx::InstanceComponent *v3; // r30
  double Scale; // fp1
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::Space *m_pSpace; // r3
  double v9; // fp9
  double v10; // fp1
  double v11; // fp4
  double v12; // fp3
  double v13; // fp2
  double v14; // fp1
  bfx::Space *v15; // r3
  double v16; // fp0
  double v17; // fp13
  char *m_data; // r30
  double v19; // fp31
  bfx::Vec3 *UpVec; // r3
  __int64 v21; // r10
  double v22; // fp11
  bfx::Vector3 *v23; // r3
  double v24; // fp3
  double v25; // fp2
  double v26; // fp1
  __int64 v27; // r8
  float v28; // r9
  float v29; // r8
  const bfx::Array<bfx::SmartPathCorner> *v30; // r3
  const bfx::Array<bfx::SmartPathCorner> *v31; // r28
  float *p_m_linkType; // r30
  double v33; // fp13
  double v34; // fp0
  double v35; // fp12
  bfx::Space *v36; // r3
  float *v37; // r29
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  float v41; // r11
  double v42; // fp31
  bfx::Vec3 *v43; // r3
  __int64 v44; // r10
  double v45; // fp12
  __int64 v46; // r6
  bfx::Vector3 *v47; // r3
  double v48; // fp4
  double v49; // fp3
  double v50; // fp2
  __int64 v51; // r8
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Vec3 *m_pArea; // r5
  double v54; // fp4
  double v55; // fp3
  double v56; // fp2
  double v59; // fp7
  bfx::NavWedge *v60; // r30
  double v61; // fp26
  double v62; // fp25
  double v63; // fp3
  long double v64; // fp2
  int v65; // r6
  const bfx::Color *v66; // r5
  const bfx::Matrix *v67; // r4
  int v68; // [sp+8h] [-1F8h]
  int v69; // [sp+Ch] [-1F4h]
  int v70; // [sp+10h] [-1F0h]
  int v71; // [sp+14h] [-1ECh]
  int v72; // [sp+18h] [-1E8h]
  int v73; // [sp+1Ch] [-1E4h]
  int v74; // [sp+20h] [-1E0h]
  int v75; // [sp+24h] [-1DCh]
  bfx::Vec3 v76; // [sp+50h] [-1B0h] BYREF
  bfx::CalcCornersSpec v77; // [sp+60h] [-1A0h] BYREF
  bfx::Vec3 v78; // [sp+70h] [-190h] BYREF
  bfx::Vec3 v79; // [sp+80h] [-180h] BYREF
  bfx::Vec3 v80; // [sp+90h] [-170h] BYREF
  bfx::Vec3 v81; // [sp+A0h] [-160h] BYREF
  bfx::Color v82; // [sp+B0h] [-150h] BYREF
  bfx::Box v83; // [sp+C0h] [-140h] BYREF
  bfx::Vec3 v84; // [sp+E0h] [-120h] BYREF
  float v85; // [sp+ECh] [-114h]
  float v86; // [sp+F0h] [-110h]
  float v87; // [sp+F4h] [-10Ch]
  bfx::Box v88; // [sp+100h] [-100h] BYREF
  bfx::Matrix v89[2]; // [sp+120h] [-E0h] BYREF

  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  if ( v3 != nullptr )
  {
    if ( v3[12].dtr_InstanceComponent != nullptr )
      bfx::NavigatorImpl::DrawNavigatorCone(this, sizeMultiplier: 1.0, drawColor: a2, a4: &ColorWhite_5);
    if ( BYTE1(v3[12].dtr_InstanceComponent) != 0 )
    {
      Scale = bfx::GetScale();
      m_x = this->m_goalPos.m_x;
      m_y = this->m_goalPos.m_y;
      m_z = this->m_goalPos.m_z;
      m_pSpace = this->m_pSpace;
      v9 = (float)(this->m_goalPos.m_y - (float)((float)Scale * (float)0.25));
      v83.m_min.m_x = this->m_goalPos.m_x - (float)((float)Scale * (float)0.25);
      v83.m_min.m_y = v9;
      v83.m_min.m_z = (float)m_z - (float)((float)Scale * (float)0.25);
      v83.m_max.m_x = (float)((float)Scale * (float)0.25) + (float)m_x;
      v83.m_max.m_y = (float)((float)Scale * (float)0.25) + (float)m_y;
      v83.m_max.m_z = (float)((float)Scale * (float)0.25) + (float)m_z;
      bfx::DrawBox(pSpace: m_pSpace, mat: (bfx::Vec3 *)&bfx::IDENTITY, boxLCoord: &v83, color: &ColorOrange_5);
      v10 = bfx::GetScale();
      v11 = (float)((float)v10 * (float)0.25);
      v12 = this->m_requestedGoalPos.m_x;
      v13 = this->m_requestedGoalPos.m_y;
      v15 = this->m_pSpace;
      v16 = (float)(this->m_requestedGoalPos.m_x - (float)((float)v10 * (float)0.25));
      v17 = (float)(this->m_requestedGoalPos.m_y - (float)((float)v10 * (float)0.25));
      v14 = this->m_requestedGoalPos.m_z;
      v88.m_min.m_x = v16;
      v88.m_min.m_y = v17;
      v88.m_min.m_z = (float)v14 - (float)v11;
      v88.m_max.m_x = (float)v12 + (float)v11;
      v88.m_max.m_y = (float)v13 + (float)v11;
      v88.m_max.m_z = (float)v14 + (float)v11;
      bfx::DrawBox(pSpace: v15, mat: (bfx::Vec3 *)&bfx::IDENTITY, boxLCoord: &v88, color: &ColorRed_5);
      bfx::DrawLine(pSpace: this->m_pSpace, v0: &this->m_pos, v1: &this->m_goalPos, color: &ColorRed_5);
    }
    if ( BYTE2(bfx::g_pCurInstance->m_pComponentManager->m_components[3][12].dtr_InstanceComponent) != 0 )
    {
      m_data = this->m_debugName.m_data;
      v19 = bfx::GetScale();
      UpVec = bfx::GetUpVec(result: &v76);
      LODWORD(v21) = &unk_821C0000;
      HIDWORD(v21) = &off_82230000;
      v22 = this->m_pos.m_z;
      v24 = (float)((float)(UpVec->m_y * (float)v19) * (float)0.85000002);
      v25 = (float)((float)(UpVec->m_z * (float)v19) * (float)0.85000002);
      v26 = (float)((float)((float)(UpVec->m_x * (float)v19) * (float)0.85000002) + this->m_pos.m_x);
      v23 = (bfx::Vector3 *)this->m_pSpace;
      v80.m_y = this->m_pos.m_y + (float)v24;
      v80.m_x = v26;
      v80.m_z = (float)v22 + (float)v25;
      bfx::DrawString(
        pSpace: v23,
        inputPos: &v80,
        fmt: __SPAIR64__("\n%s", (unsigned int)m_data),
        a4: v27,
        a5: v21,
        a6: v68,
        a7: v69,
        a8: v70,
        a9: v71,
        a10: v72,
        a11: v73,
        a12: v74,
        a13: v75);
    }
    if ( bfx::g_drawNavigatorCorners )
    {
      v77.m_maxPathDist = 3.4028235e38;
      v77.m_addCornerAtStartingPosition = false;
      v77.m_maxNumCorners = 100;
      v77.m_addCornersAtEveryAreaBoundary = false;
      v28 = this->m_pos.m_y;
      v29 = this->m_pos.m_z;
      v76.m_x = this->m_pos.m_x;
      v76.m_y = v28;
      v76.m_z = v29;
      v30 = bfx::SmartPath::CalcNextNCorners(this: &this->m_smartPath, calcCornersSpec: &v77);
      v31 = v30;
      if ( v30 != nullptr && v30->m_data != &v30->m_data[v30->m_size] )
      {
        p_m_linkType = (float *)&v30->m_data->m_linkType;
        v33 = v76.m_z;
        v34 = v76.m_y;
        v35 = v76.m_x;
        while ( 1 )
        {
          v84.m_x = v35;
          v84.m_y = v34;
          v84.m_z = v33;
          v36 = this->m_pSpace;
          v85 = *(p_m_linkType - 4);
          v37 = p_m_linkType - 4;
          v86 = *(p_m_linkType - 3);
          v87 = *(p_m_linkType - 2);
          bfx::DrawLineList(pSpace: v36, pVerts: &v84, numVerts: 2, color: &ColorCyan_5);
          if ( *((_BYTE *)p_m_linkType - 4) != 0 )
            break;
          v41 = *p_m_linkType;
          if ( *(_DWORD *)p_m_linkType == 0 )
          {
            HIDWORD(v40) = "Corner";
            goto LABEL_20;
          }
          if ( LODWORD(v41) == 1 )
          {
            HIDWORD(v40) = "LinkStart";
            goto LABEL_20;
          }
          if ( LODWORD(v41) == 2 )
          {
            HIDWORD(v40) = "LinkEnd";
            goto LABEL_20;
          }
LABEL_21:
          v34 = *(p_m_linkType - 3);
          v33 = *(p_m_linkType - 2);
          p_m_linkType += 7;
          v35 = *v37;
          if ( p_m_linkType - 4 == &v31->m_data[v31->m_size].m_pos.m_x )
            goto LABEL_22;
        }
        HIDWORD(v40) = "Goal";
LABEL_20:
        bfx::DrawString(
          pSpace: (bfx::Vector3 *)this->m_pSpace,
          inputPos: (const bfx::Vec3 *)(p_m_linkType - 4),
          fmt: v40,
          a4: v39,
          a5: v38,
          a6: v68,
          a7: v69,
          a8: v70,
          a9: v71,
          a10: v72,
          a11: v73,
          a12: v74,
          a13: v75);
        goto LABEL_21;
      }
    }
LABEL_22:
    if ( g_drawNavigatorIds )
    {
      v42 = bfx::GetScale();
      v43 = bfx::GetUpVec(result: &v76);
      LODWORD(v44) = &unk_82410000;
      v45 = this->m_pos.m_z;
      HIDWORD(v46) = "\nid %d";
      LODWORD(v46) = this->m_replayID;
      v48 = (float)((float)(v43->m_y * (float)v42) * (float)0.5);
      v49 = (float)((float)(v43->m_z * (float)v42) * (float)0.5);
      v50 = (float)((float)((float)((float)v42 * v43->m_x) * (float)0.5) + this->m_pos.m_x);
      v47 = (bfx::Vector3 *)this->m_pSpace;
      v81.m_y = this->m_pos.m_y + (float)v48;
      v81.m_x = v50;
      v81.m_z = (float)v45 + (float)v49;
      bfx::DrawString(
        pSpace: v47,
        inputPos: &v81,
        fmt: v46,
        a4: v51,
        a5: v44,
        a6: v68,
        a7: v69,
        a8: v70,
        a9: v71,
        a10: v72,
        a11: v73,
        a12: v74,
        a13: v75);
    }
    if ( bfx::g_drawNavigatorFreeWedges && this->m_debugData.m_freeWedges.m_size != 0 )
    {
      m_pProxy = this->m_smartPath.m_snappedStartArea.m_pProxy;
      if ( m_pProxy != nullptr )
        m_pArea = (bfx::Vec3 *)m_pProxy->m_pArea;
      else
        m_pArea = nullptr;
      if ( m_pArea != nullptr )
      {
        bfx::NavigatorImpl::CalcUpVector(this: (bfx::NavigatorImpl *)&v78, result: (bfx::Vec3 *)this, pMyArea: m_pArea);
        v54 = (float)((float)(v78.m_z * this->m_debugData.m_inPlaneForward.m_x)
                    - (float)(v78.m_x * this->m_debugData.m_inPlaneForward.m_z));
        v55 = (float)((float)(v78.m_x * this->m_debugData.m_inPlaneForward.m_y)
                    - (float)(v78.m_y * this->m_debugData.m_inPlaneForward.m_x));
        v56 = (float)((float)(v78.m_y * this->m_debugData.m_inPlaneForward.m_z)
                    - (float)(v78.m_z * this->m_debugData.m_inPlaneForward.m_y));
        _FP11 = (float)((float)__fsqrts((float)((float)((float)v56 * (float)v56)
                                              + (float)((float)((float)v55 * (float)v55)
                                                      + (float)((float)v54 * (float)v54))))
                      - 1.0842022e-19);
        __asm { fsel      f9, f11, f10, f30 }
        v59 = (float)((float)((float)(v78.m_z * this->m_debugData.m_inPlaneForward.m_x)
                            - (float)(v78.m_x * this->m_debugData.m_inPlaneForward.m_z))
                    * (float)_FP9);
        v79.m_x = (float)_FP9
                * (float)((float)(v78.m_y * this->m_debugData.m_inPlaneForward.m_z)
                        - (float)(v78.m_z * this->m_debugData.m_inPlaneForward.m_y));
        v79.m_y = v59;
        v79.m_z = (float)v55 * (float)_FP9;
        bfx::Matrix::Build(
          this: v89,
          xAxis: &this->m_debugData.m_inPlaneForward,
          yAxis: &v79,
          zAxis: &v78,
          trans: &this->m_pos);
        v60 = this->m_debugData.m_freeWedges.m_data;
        if ( v60 != &v60[this->m_debugData.m_freeWedges.m_size] )
        {
          do
          {
            v82.m_g = 1.0;
            v82.m_b = 0.0;
            v82.m_r = 1.0;
            v82.m_a = 0.5;
            v61 = (float)(v60->m_endAngle * (float)0.017453292);
            v62 = (float)(v60->m_startAngle * (float)0.017453292);
            v63 = (float)(bfx::GetScale() * (float)5.0);
            *((double *)&v64 + 1) = v61;
            *(double *)&v64 = v62;
            bfx::DrawArc(
              a1: (bfx::Vector3 *)this->m_pSpace,
              endAngleInRadians: v64,
              radius: v63,
              mat: v67,
              drawCol: v66,
              a6: v65,
              a7: (bfx::Vec3 *)v89,
              a8: &v82);
            ++v60;
          }
          while ( v60 != &this->m_debugData.m_freeWedges.m_data[this->m_debugData.m_freeWedges.m_size] );
        }
      }
    }
  }
}


// ========================================================================
// ?CalculateCollisionFreeWedges@NavigatorImpl@bfx@@QAAHMABVVec3@2@HQAVNavWedge@2@_N@Z
// EA  : 0x83263110
// RVA : 0x01263110
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

int __fastcall bfx::NavigatorImpl::CalculateCollisionFreeWedges(
        bfx::NavigatorImpl *this,
        double speed,
        const bfx::Vec3 *dirOfZeroAngle,
        float *maxNumWedges,
        bfx::NavWedge *freeWedges,
        int ignoreGoalCampers,
        char a7)
{
  int v13; // r19
  bfx::Vec3 *SnappedStartArea; // r5
  double v15; // fp9
  double v16; // fp1
  double v17; // fp0
  double v18; // fp13
  double v21; // fp1
  double v22; // fp0
  double m_y; // fp13
  unsigned int m_replayID; // r5
  bfx::QueuedLine *m_data; // r20
  double v26; // fp11
  double m_x; // fp9
  double v28; // fp5
  double m_z; // fp8
  double v30; // fp6
  double v31; // fp29
  bfx::Array<bfx::AABB *> *m_pArray; // r11
  int m_i; // r25
  int v34; // r10
  bfx::RepulsorImpl *m_pUserData; // r29
  float v36; // r11
  float v37; // r9
  double v38; // fp0
  double v39; // fp13
  double v40; // fp12
  double v41; // fp11
  bfx::RepulsorOwner *m_pOwner; // r11
  char v43; // r3
  float v44; // r8
  float v45; // r7
  float v46; // r6
  float v47; // r10
  int m_repulsorID; // r5
  float v49; // r11
  double v50; // fp13
  float m_outerCushion; // r10
  float m_innerCushion; // r9
  int m_size; // r29
  bfx::Array<bfx::RVOWedge> *v54; // r7
  bfx::RepulsorsForRVO *v55; // r6
  float *p_m_z; // r11
  int v57; // r9
  float *v58; // r10
  int v59; // r3
  float *v60; // r4
  int v61; // r30
  double v62; // fp0
  int v63; // r7
  float *v64; // r5
  float *v65; // r6
  double v66; // fp0
  __int64 v67; // r9
  double v68; // fp10
  __int64 *v69; // r3
  _DWORD *v70; // r3
  double v71; // fp0
  double v72; // fp0
  double v73; // fp0
  double v74; // fp0
  float m_radius; // [sp+50h] [-1A0h]
  bfx::Array<bfx::RVODebugDrawInfo> v77; // [sp+60h] [-190h] BYREF
  bfx::Vec3 v78; // [sp+70h] [-180h] BYREF
  float *v79; // [sp+80h] [-170h]
  int v80; // [sp+84h] [-16Ch]
  int v81; // [sp+88h] [-168h]
  bfx::bfxMemTag v82; // [sp+8Ch] [-164h]
  float v83; // [sp+90h] [-160h]
  float v84; // [sp+94h] [-15Ch]
  float v85; // [sp+98h] [-158h]
  float v86; // [sp+A0h] [-150h]
  float v87; // [sp+A4h] [-14Ch]
  float v88; // [sp+A8h] [-148h]
  bfx::Array<bfx::QueuedLine> v89; // [sp+B0h] [-140h] BYREF
  float v90; // [sp+C0h] [-130h]
  float v91; // [sp+C4h] [-12Ch]
  float v92; // [sp+C8h] [-128h]
  bfx::NearbyRepulsorCursor v93; // [sp+D0h] [-120h] BYREF
  float v94; // [sp+E0h] [-110h]
  float v95; // [sp+E4h] [-10Ch]
  float v96; // [sp+E8h] [-108h]
  bfx::Vec3 v97; // [sp+F0h] [-100h] BYREF
  bfx::RVOEntityRecord v98; // [sp+100h] [-F0h] BYREF
  bfx::RVOEntityRecord v99; // [sp+130h] [-C0h] BYREF

  v13 = 0;
  if ( freeWedges == nullptr )
    return 0;
  if ( this->m_pRepulsor == nullptr )
    return 0;
  SnappedStartArea = (bfx::Vec3 *)bfx::SmartPath::GetSnappedStartArea(this: &this->m_smartPath);
  if ( SnappedStartArea == nullptr )
    return 0;
  bfx::NavigatorImpl::CalcUpVector(
    this: (bfx::NavigatorImpl *)&v78,
    result: (bfx::Vec3 *)this,
    pMyArea: SnappedStartArea);
  v15 = maxNumWedges[2];
  v16 = (float)(v78.m_z
              * (float)((float)(*maxNumWedges * v78.m_x)
                      + (float)((float)(maxNumWedges[1] * v78.m_y) + (float)(maxNumWedges[2] * v78.m_z))));
  v17 = (float)(maxNumWedges[1]
              - (float)(v78.m_y
                      * (float)((float)(*maxNumWedges * v78.m_x)
                              + (float)((float)(maxNumWedges[1] * v78.m_y) + (float)(maxNumWedges[2] * v78.m_z)))));
  v18 = (float)(*maxNumWedges
              - (float)((float)((float)(*maxNumWedges * v78.m_x)
                              + (float)((float)(maxNumWedges[1] * v78.m_y) + (float)(maxNumWedges[2] * v78.m_z)))
                      * v78.m_x));
  _FP5 = (float)((float)__fsqrts((float)((float)((float)(maxNumWedges[2] - (float)v16)
                                               * (float)(maxNumWedges[2] - (float)v16))
                                       + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))))
               - (float)1.0842022e-19);
  __asm { fsel      f3, f5, f4, f31 }
  this->m_debugData.m_inPlaneForward.m_x = (float)(*maxNumWedges
                                                 - (float)((float)((float)(*maxNumWedges * v78.m_x)
                                                                 + (float)((float)(maxNumWedges[1] * v78.m_y)
                                                                         + (float)(maxNumWedges[2] * v78.m_z)))
                                                         * v78.m_x))
                                         * (float)_FP3;
  v21 = (float)((float)_FP3 * (float)((float)v15 - (float)v16));
  this->m_debugData.m_inPlaneForward.m_z = v21;
  v22 = (float)((float)v17 * (float)_FP3);
  this->m_debugData.m_inPlaneForward.m_y = v22;
  v97.m_z = v21;
  v97.m_y = v22;
  v97.m_x = (float)v18 * (float)_FP3;
  bfx::RVOEntityRecord::RVOEntityRecord(this: &v99);
  m_radius = this->m_tune.m_radius;
  m_y = this->m_pos.m_y;
  m_replayID = this->m_replayID;
  m_data = nullptr;
  v26 = (float)(this->m_goalPos.m_y - this->m_pos.m_y);
  m_x = this->m_pos.m_x;
  v28 = (float)(this->m_goalPos.m_x - this->m_pos.m_x);
  m_z = this->m_pos.m_z;
  v30 = this->m_goalPos.m_z;
  v99.m_vel.m_x = speed;
  memset(&v89, 0, 12);
  v99.m_vel.m_y = 0.0;
  v99.m_vel.m_z = 0.0;
  v99.m_pos.m_y = m_y;
  v99.m_pos.m_x = m_x;
  v99.m_radiusDat.m_innerCushion = 0.0;
  v99.m_pos.m_z = m_z;
  v99.m_radiusDat.m_outerCushion = 0.0;
  v99.m_replayID = m_replayID;
  v99.m_radiusDat.m_radius = m_radius;
  v31 = (float)((float)((float)((float)v30 - (float)m_z) * (float)((float)v30 - (float)m_z))
              + (float)((float)((float)v28 * (float)v28) + (float)((float)v26 * (float)v26)));
  v89.m_tag = bfx::MEM_BFXNAVIGATOR;
  bfx::NearbyRepulsorCursor::NearbyRepulsorCursor(
    this: &v93,
    pRepulsor: this->m_pRepulsor,
    filterBasedOnBlockageFlags: true);
  m_pArray = v93.m_overlapCursor.m_pArray;
  m_i = v93.m_overlapCursor.m_i;
  if ( v93.m_overlapCursor.m_i < v93.m_overlapCursor.m_pArray->m_size )
  {
    v34 = v93.m_overlapCursor.m_i;
    do
    {
      m_pUserData = (bfx::RepulsorImpl *)m_pArray->m_data[v34]->m_pUserData;
      if ( m_pUserData != this->m_pRepulsor )
      {
        if ( a7 == 0 )
          goto LABEL_15;
        v36 = m_pUserData->m_pos.m_x;
        v37 = m_pUserData->m_pos.m_y;
        if ( (float)((float)((float)(this->m_pos.m_z - m_pUserData->m_pos.m_z)
                           * (float)(this->m_pos.m_z - m_pUserData->m_pos.m_z))
                   + (float)((float)((float)(this->m_pos.m_x - v36) * (float)(this->m_pos.m_x - v36))
                           + (float)((float)(this->m_pos.m_y - v37) * (float)(this->m_pos.m_y - v37)))) <= v31 )
        {
          v38 = this->m_goalPos.m_y;
          v39 = this->m_goalPos.m_x;
          v90 = m_pUserData->m_pos.m_x;
          v91 = v37;
          v40 = m_pUserData->m_radiusData.m_radius;
          v41 = this->m_goalPos.m_z;
          v92 = m_pUserData->m_pos.m_z;
          if ( (float)((float)((float)(v92 - (float)v41) * (float)(v92 - (float)v41))
                     + (float)((float)((float)(v36 - (float)v39) * (float)(v36 - (float)v39))
                             + (float)((float)(v37 - (float)v38) * (float)(v37 - (float)v38)))) > (double)(float)((float)((float)v40 * (float)0.5) * (float)((float)v40 * (float)0.5)) )
          {
LABEL_15:
            if ( !this->m_tune.m_ignoreUpsideDownNeighbors
              || ((m_pOwner = m_pUserData->m_pOwner) == nullptr
                ? (v43 = 0)
                : (v43 = ((int (*)(void))m_pOwner->GetRepulsorNormal)()),
                  v43 == 0
               || (float)((float)(v94 * v78.m_x) + (float)((float)(v96 * v78.m_z) + (float)(v95 * v78.m_y))) >= -0.70700002) )
            {
              bfx::RVOEntityRecord::RVOEntityRecord(this: &v98);
              v44 = m_pUserData->m_pos.m_z;
              v45 = m_pUserData->m_vel.m_x;
              v46 = m_pUserData->m_vel.m_y;
              v47 = m_pUserData->m_pos.m_x;
              v87 = m_pUserData->m_pos.m_y;
              v88 = v44;
              v83 = v45;
              v84 = v46;
              v86 = v47;
              m_repulsorID = m_pUserData->m_repulsorID;
              v85 = m_pUserData->m_vel.m_z;
              v98.m_vel.m_z = v85;
              v98.m_replayID = m_repulsorID;
              v49 = m_pUserData->m_radiusData.m_radius;
              v50 = v47;
              m_outerCushion = m_pUserData->m_radiusData.m_outerCushion;
              v98.m_vel.m_y = v46;
              m_innerCushion = m_pUserData->m_radiusData.m_innerCushion;
              v98.m_vel.m_x = v45;
              v98.m_pos.m_x = v50;
              v98.m_pos.m_y = v87;
              v98.m_pos.m_z = v44;
              v98.m_radiusDat.m_radius = v49;
              v98.m_radiusDat.m_outerCushion = m_outerCushion;
              v98.m_radiusDat.m_innerCushion = m_innerCushion;
              bfx::Array<bfx::QueuedLine>::push_back(this: &v89, val: (const bfx::QueuedLine *)&v98);
            }
          }
        }
      }
      v93.m_overlapCursor.m_i = m_i + 1;
      bfx::NearbyRepulsorCursor::AdvanceToNextRepulsorSatisfyingFilter(this: &v93);
      m_pArray = v93.m_overlapCursor.m_pArray;
      m_i = v93.m_overlapCursor.m_i;
      v34 = v93.m_overlapCursor.m_i;
    }
    while ( v93.m_overlapCursor.m_i < v93.m_overlapCursor.m_pArray->m_size );
    m_size = v89.m_size;
    if ( v89.m_size != 0 )
    {
      memset(&v77, 0, 12);
      bfx::RepulsorsForRVO::Reserve(this: (bfx::RepulsorsForRVO *)&v77, count: v89.m_size);
      m_data = v89.m_data;
      if ( m_size > 0 )
      {
        p_m_z = &v89.m_data->m_v1.m_z;
        v54 = (bfx::Array<bfx::RVOWedge> *)(-20 - (unsigned int)v89.m_data);
        v57 = m_size;
        do
        {
          --v57;
          v58 = (float *)((char *)&v77.m_data->m_yourID + (int)p_m_z + (_DWORD)v54);
          *v58 = *(p_m_z - 5);
          v58[1] = *(p_m_z - 4);
          v58[2] = *(p_m_z - 3);
          v58[3] = *(p_m_z - 2);
          v58[4] = *(p_m_z - 1);
          v58[5] = *p_m_z;
          v55 = *((bfx::RepulsorsForRVO **)p_m_z + 1);
          *((_DWORD *)v58 + 6) = v55;
          v58[7] = p_m_z[2];
          v58[8] = p_m_z[3];
          v59 = *((_DWORD *)p_m_z + 4);
          p_m_z += 10;
          *((_DWORD *)v58 + 9) = v59;
        }
        while ( v57 != 0 );
      }
      v77.m_size = m_size;
      v79 = nullptr;
      v80 = 0;
      v81 = 0;
      v82 = bfx::MEM_BFXNAVIGATOR;
      bfx::CalcRVOs(
        pMyRVORec: &v99,
        myNorm: &v78,
        myForward: &v97,
        radiusLimit: this->m_tune.m_detectionCylinderTune.m_radius,
        heightLimit: this->m_tune.m_detectionCylinderTune.m_height,
        repRecs: v55,
        wedges: v54,
        pRVODebugData: &v77);
      v60 = v79;
      v61 = v80;
      if ( v80 != 0 )
      {
        v62 = (float)(*v79 - v79[1]);
        if ( v80 != 1 )
          goto LABEL_27;
        if ( v62 >= 6.2822089 )
        {
          v13 = 0;
LABEL_47:
          v80 = 0;
          if ( v60 != nullptr )
          {
            bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v60);
            v79 = nullptr;
          }
          v81 = 0;
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v77.m_data);
          goto LABEL_52;
        }
        if ( v62 > 0.0009765625 )
        {
LABEL_27:
          v63 = 0;
          v64 = &v79[2 * v80];
          v65 = v79;
          v66 = *(v64 - 2);
          if ( v79 != v64 )
          {
            HIDWORD(v67) = 0;
            v68 = 57.295776;
            do
            {
              if ( v63 >= (int)freeWedges )
                break;
              *(float *)(HIDWORD(v67) + ignoreGoalCampers) = (float)v66 * (float)v68;
              *(float *)(HIDWORD(v67) + ignoreGoalCampers + 4) = v65[1] * (float)v68;
              if ( v13 == 1 )
              {
                bfx::MakeWellFormed(wedge: (bfx::NavWedge *)ignoreGoalCampers);
                bfx::MakeWellFormed(wedge: (bfx::NavWedge *)(ignoreGoalCampers + 8));
                if ( *(float *)v69 < (double)*(float *)ignoreGoalCampers )
                {
                  v67 = *v69;
                  --v63;
                  HIDWORD(v67) = *(_DWORD *)v69 - 8;
                  v70 = (_DWORD *)(8 * (v61 - 1) + ignoreGoalCampers);
                  *v70 = *(_DWORD *)ignoreGoalCampers;
                  v70[1] = *(_DWORD *)(ignoreGoalCampers + 4);
                  *(_QWORD *)ignoreGoalCampers = v67;
                }
              }
              v66 = *v65;
              v65 += 2;
              ++v63;
              HIDWORD(v67) += 8;
              ++v13;
            }
            while ( v65 != v64 );
          }
          v71 = *(float *)ignoreGoalCampers;
          if ( v71 >= -180.0 )
          {
            if ( v71 <= 180.0 )
              goto LABEL_39;
            v72 = (float)(*(float *)ignoreGoalCampers - (float)360.0);
          }
          else
          {
            v72 = (float)(*(float *)ignoreGoalCampers + (float)360.0);
          }
          *(float *)ignoreGoalCampers = v72;
LABEL_39:
          v73 = *(float *)(ignoreGoalCampers + 4);
          if ( v73 >= -180.0 )
          {
            if ( v73 <= 180.0 )
              goto LABEL_44;
            v74 = (float)(*(float *)(ignoreGoalCampers + 4) - (float)360.0);
          }
          else
          {
            v74 = (float)(*(float *)(ignoreGoalCampers + 4) + (float)360.0);
          }
          *(float *)(ignoreGoalCampers + 4) = v74;
LABEL_44:
          if ( *(float *)ignoreGoalCampers > (double)*(float *)(ignoreGoalCampers + 4) )
            *(float *)(ignoreGoalCampers + 4) = *(float *)(ignoreGoalCampers + 4) + (float)360.0;
          goto LABEL_47;
        }
      }
      v13 = 1;
      *(float *)(ignoreGoalCampers + 4) = 180.0;
      *(float *)ignoreGoalCampers = -180.0;
      goto LABEL_47;
    }
    m_data = v89.m_data;
  }
  v13 = 1;
  *(float *)ignoreGoalCampers = -180.0;
  *(float *)(ignoreGoalCampers + 4) = 180.0;
LABEL_52:
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  return v13;
}


// ========================================================================
// __unwind$86505
// EA  : 0x8326380C
// RVA : 0x0126380C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_86505()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 496 + 176));
}


// ========================================================================
// __unwind$86506
// EA  : 0x83263834
// RVA : 0x01263834
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_86506()
{
  int v0; // r12

  bfx::RepulsorsForRVO::~RepulsorsForRVO(this: (bfx::RepulsorsForRVO *)(v0 - 496 + 96));
}


// ========================================================================
// __unwind$86507
// EA  : 0x8326385C
// RVA : 0x0126385C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_86507()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 496 + 128));
}


// ========================================================================
// ??0NavigatorImpl@bfx@@QAA@PAVSpace@1@ABVVec3@1@ABUNavigatorTune@1@@Z
// EA  : 0x832639C8
// RVA : 0x012639C8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

bfx::NavigatorImpl *__fastcall bfx::NavigatorImpl::NavigatorImpl(
        bfx::NavigatorImpl *this,
        bfx::Space *pSpace,
        const bfx::Vec3 *pos,
        const bfx::NavigatorTune *tune)
{
  float m_x; // r3
  bfx::Vec3 *p_m_prevPos; // r11
  bfx::NavigatorTune *p_m_tune; // r25
  __int64 v10; // r10
  bfx::bfxMemTag v11; // r11
  __int64 v12; // r8
  unsigned int v13; // r6
  int v14; // r5
  int v15; // r4
  bfx::Vec3 *SnappedStartPos; // r3
  bfx::RepulsorImpl *m_pRepulsor; // r3
  _DWORD v19[2]; // [sp+50h] [-70h] BYREF
  int v20; // [sp+58h] [-68h] BYREF

  this->m_creatorType = REPULSOR_CREATOR_NAVIGATOR;
  this->m_pSpace = pSpace;
  this->__vftable = (bfx::NavigatorImpl_vtbl *)&bfx::NavigatorImpl::`vftable';
  v19[0] = &this->m_debugName;
  this->m_debugName.m_data = nullptr;
  p_m_prevPos = &this->m_prevPos;
  p_m_tune = &this->m_tune;
  m_x = pos->m_x;
  v19[0] = p_m_prevPos;
  this->m_pos.m_x = m_x;
  this->m_pos.m_y = pos->m_y;
  this->m_pos.m_z = pos->m_z;
  this->m_requestedPos = *pos;
  this->m_goalPos = *pos;
  this->m_requestedGoalPos = *pos;
  this->m_prevPos.m_x = 0.0;
  this->m_prevPos.m_y = 0.0;
  v19[0] = &this->m_vel;
  this->m_prevPos.m_z = 0.0;
  this->m_vel.m_x = 0.0;
  this->m_vel.m_y = 0.0;
  this->m_vel.m_z = 0.0;
  memcpy(Dst: p_m_tune, Src: tune, Size: sizeof(bfx::NavigatorTune));
  this->m_pRepulsor = nullptr;
  bfx::SmartPath::SmartPath(
    this: &this->m_smartPath,
    pSpace,
    layer: tune->m_planLayer,
    pathSpec: &tune->m_pathSpec,
    options: &bfx::g_defaultPathCreationOptions);
  LODWORD(v10) = &this->m_debugData.m_inPlaneForward;
  v11 = bfx::MEM_BFXNAVIGATOR;
  this->m_debugData.m_freeWedges.m_data = nullptr;
  this->m_debugData.m_freeWedges.m_size = 0;
  this->m_debugData.m_freeWedges.m_cap = 0;
  v19[1] = &this->m_debugData.m_inPlaneForward;
  this->m_debugData.m_freeWedges.m_tag = v11;
  this->m_debugData.m_inPlaneForward.m_x = 0.0;
  this->m_debugData.m_inPlaneForward.m_y = 0.0;
  this->m_debugData.m_inPlaneForward.m_z = 0.0;
  HIDWORD(v10) = &_IMPORT_DESCRIPTOR_xam_xex_20500_0_1861;
  LODWORD(v12) = bfx::g_pCurInstance->m_pComponentManager;
  HIDWORD(v12) = *(_DWORD *)(v12 + 12);
  v13 = *(_DWORD *)(HIDWORD(v12) + 24);
  this->m_replayID = v13;
  v14 = *(_DWORD *)(HIDWORD(v12) + 24) + 1;
  *(_DWORD *)(HIDWORD(v12) + 24) = v14;
  bfx::ApplyLimits_NavigatorTune(tune: p_m_tune, a2: v15, a3: v14, a4: v13, a5: v12, a6: v10);
  HIWORD(v19[0]) = 257;
  bfx::SmartPath::SetPathCreationOptions(this: &this->m_smartPath, options: (const bfx::PathCreationOptions *)v19);
  bfx::NavigatorImpl::EnableRepulsor(this, enable: true);
  bfx::SmartPath::SetStartData(this: &this->m_smartPath, startPos: &this->m_pos, pStartArea: nullptr);
  SnappedStartPos = bfx::SmartPath::GetSnappedStartPos(
                      this: (bfx::SmartPath *)&v20,
                      result: (bfx::Vec3 *)&this->m_smartPath);
  this->m_pos.m_x = SnappedStartPos->m_x;
  v19[1] = &this->m_pos;
  this->m_pos.m_y = SnappedStartPos->m_y;
  this->m_pos.m_z = SnappedStartPos->m_z;
  m_pRepulsor = this->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
    bfx::RepulsorImpl::SetPos(this: m_pRepulsor, pos: &this->m_pos);
  return this;
}


// ========================================================================
// __unwind$87289
// EA  : 0x83263BC4
// RVA : 0x01263BC4
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_87289()
{
  int v0; // r12

  bfx::RepulsorOwner::~RepulsorOwner(this: *(bfx::RepulsorOwner **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$87290
// EA  : 0x83263BEC
// RVA : 0x01263BEC
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_87290()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(*(_DWORD *)(v0 - 192 + 212) + 16));
}


// ========================================================================
// __unwind$87291
// EA  : 0x83263C18
// RVA : 0x01263C18
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_87291()
{
  int v0; // r12

  bfx::SmartPath::~SmartPath(this: (bfx::SmartPath *)(*(_DWORD *)(v0 - 192 + 212) + 168));
}


// ========================================================================
// __unwind$87292
// EA  : 0x83263C44
// RVA : 0x01263C44
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_87292()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                             + 448));
}


// ========================================================================
// ?GetPosInDirection@NavigatorImpl@bfx@@QAA_NABVVec3@2@MAAV32@AA_NAAPAVArea@2@@Z
// EA  : 0x83263CD8
// RVA : 0x01263CD8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

int __fastcall bfx::NavigatorImpl::GetPosInDirection(
        bfx::NavigatorImpl *this,
        const bfx::Vec3 *direction,
        double distance,
        bfx::Vec3 *posOut,
        float *onEdgeOut,
        bfx::Area **pAreaOut,
        bfx::Area **a7)
{
  bfx::Area *m_pArea; // r30
  bfx::Area *SnappedStartArea; // r3
  double m_x; // fp11
  double m_y; // fp8
  bfx::AreaProxy *m_pProxy; // r11
  double v21; // fp10
  double m_z; // fp9
  char v23; // r7
  bfx::Vec3 v24; // [sp+50h] [-B0h] BYREF
  bfx::Surfer v25; // [sp+60h] [-A0h] BYREF

  m_pArea = nullptr;
  v25.m_areaNormal.m_x = 0.0;
  v25.m_areaNormal.m_y = 0.0;
  v25.m_areaNormal.m_z = 0.0;
  v25.m_area.m_pProxy = nullptr;
  v25.__vftable = (bfx::Surfer_vtbl *)&bfx::Surfer::`vftable';
  v25.m_edgeCursor.m_pArea = nullptr;
  v25.m_edgeCursor.m_i = -1;
  memset(&v25.m_state, 0, 16);
  v25.m_areasTraversed.m_tag = bfx::MEM_BFXNAVIGATOR;
  memset(&v25.m_edgesTraversed, 0, 12);
  v25.m_edgesTraversed.m_tag = bfx::MEM_BFXNAVIGATOR;
  SnappedStartArea = bfx::SmartPath::GetSnappedStartArea(this: &this->m_smartPath);
  bfx::Surfer::SetPosAndArea(this: &v25, pos: &this->m_pos, pArea: SnappedStartArea);
  if ( v25.m_area.m_pProxy != nullptr && v25.m_area.m_pProxy->m_pArea != nullptr )
  {
    m_x = direction->m_x;
    m_y = direction->m_y;
    _FP4 = (float)((float)__fsqrts((float)((float)(direction->m_z * direction->m_z)
                                         + (float)((float)(direction->m_x * direction->m_x)
                                                 + (float)(direction->m_y * direction->m_y))))
                 - (float)1.0842022e-19);
    __asm { fsel      f2, f4, f3, f31 }
    v24.m_z = direction->m_z * (float)_FP2;
    v24.m_y = (float)m_y * (float)_FP2;
    v24.m_x = (float)m_x * (float)_FP2;
    bfx::Surfer::Move(this: &v25, origVel: &v24, time: distance);
    m_pProxy = v25.m_area.m_pProxy;
    v21 = v25.m_pos.m_y;
    m_z = v25.m_pos.m_z;
    v23 = _cntlzw(v25.m_state - 1);
    *onEdgeOut = v25.m_pos.m_x;
    onEdgeOut[1] = v21;
    onEdgeOut[2] = m_z;
    *(_BYTE *)pAreaOut = (v23 & 0x20) != 0;
    if ( m_pProxy != nullptr )
      m_pArea = m_pProxy->m_pArea;
    *a7 = m_pArea;
    bfx::Surfer::~Surfer(this: &v25);
    return 1;
  }
  else
  {
    bfx::Surfer::~Surfer(this: &v25);
    return 0;
  }
}


// ========================================================================
// __unwind$87386
// EA  : 0x83263E6C
// RVA : 0x01263E6C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void _unwind_87386()
{
  int v0; // r12

  bfx::Surfer::~Surfer(this: (bfx::Surfer *)(v0 - 256 + 96));
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawNavigatorFreeWedgesRestore''
// EA  : 0x83398430
// RVA : 0x01398430
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawNavigatorFreeWedgesRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawNavigatorFreeWedgesRestore);
  bfx::g_drawNavigatorFreeWedgesRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawNavigatorFreeWedgesRestore.m_targetBool = &bfx::g_drawNavigatorFreeWedges;
  bfx::g_drawNavigatorFreeWedgesRestore.m_name = "draw_navigator_free_wedges";
  bfx::g_drawNavigatorFreeWedgesRestore.m_defaultBool = bfx::g_drawNavigatorFreeWedges;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawNavigatorFreeWedgesRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawNavigatorCornersRestore''
// EA  : 0x833984A8
// RVA : 0x013984A8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawNavigatorCornersRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawNavigatorCornersRestore);
  bfx::g_drawNavigatorCornersRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawNavigatorCornersRestore.m_targetBool = &bfx::g_drawNavigatorCorners;
  bfx::g_drawNavigatorCornersRestore.m_name = "draw_navigator_corners";
  bfx::g_drawNavigatorCornersRestore.m_defaultBool = bfx::g_drawNavigatorCorners;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawNavigatorCornersRestore__);
}

