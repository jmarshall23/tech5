
// ========================================================================
// ??0?$Handle@VArea@bfx@@@bfx@@QAA@PAVArea@1@@Z
// EA  : 0x8323DF78
// RVA : 0x0123DF78
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::Handle<bfx::Area> *__fastcall bfx::Handle<bfx::Area>::Handle<bfx::Area>(
        bfx::Handle<bfx::Area> *this,
        bfx::Area *pArea)
{
  bfx::AreaProxy *m_pProxy; // r11
  bfx::AreaProxy *v5; // r3

  if ( pArea != nullptr )
  {
    m_pProxy = pArea->m_pProxy;
    if ( pArea->m_pProxy == nullptr )
    {
      v5 = (bfx::AreaProxy *)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 8u,
                               tag: bfx::MEM_BFXPLANNER);
      if ( v5 != nullptr )
      {
        v5->m_pArea = pArea;
        m_pProxy = v5;
        v5->m_refCount = 0;
        pArea->m_pProxy = v5;
      }
      else
      {
        m_pProxy = nullptr;
      }
    }
    this->m_pProxy = m_pProxy;
    ++m_pProxy->m_refCount;
  }
  else
  {
    this->m_pProxy = nullptr;
  }
  return this;
}


// ========================================================================
// ?IsUsableArea@bfx@@YA_NPAVArea@1@ABVPathSpec@1@@Z
// EA  : 0x8323E028
// RVA : 0x0123E028
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

int __fastcall bfx::IsUsableArea(bfx::Area *pArea, const bfx::PathSpec *pathSpec)
{
  unsigned int m_obstacleBlockageFlags; // r11
  int m_flags2_low; // r10
  bool v4; // r11
  char v5; // r11
  bool v6; // zf
  unsigned int m_usageFlags; // r11
  unsigned int v8; // r9
  char v9; // r11
  unsigned __int8 v10; // r11

  m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
  if ( (pArea->m_flags.m_flags1 & 0x20000000) == 0
    || ((m_flags2_low = LOWORD(pArea->m_flags.m_flags2), pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
      ? (v4 = (_cntlzw(m_obstacleBlockageFlags - (m_flags2_low & m_obstacleBlockageFlags)) & 0x20) != 0)
      : (v4 = (m_flags2_low & m_obstacleBlockageFlags) != 0),
        v6 = v4,
        v5 = 1,
        !v6) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
    return 0;
  m_usageFlags = pArea->m_usageFlags;
  if ( m_usageFlags == 0 || (v8 = pathSpec->m_areaUsageFlags & m_usageFlags, v9 = 1, v8 != 0) )
    v9 = 0;
  v6 = v9 == 0;
  v10 = 1;
  if ( !v6 )
    return 0;
  return v10;
}


// ========================================================================
// ?CalcNormal@Area@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x8323E0D0
// RVA : 0x0123E0D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::Area *__fastcall bfx::Area::CalcNormal(bfx::Area *this, bfx::Vec3 *result)
{
  float m_x; // r30
  double m_z; // fp9
  bfx::Vec3 *v4; // r11
  double v5; // fp10
  float v6; // r5
  double v7; // fp3
  double v8; // fp2
  double v9; // fp1
  float v13; // [sp+0h] [-60h]
  float v14; // [sp+4h] [-5Ch]
  float v15; // [sp+8h] [-58h]
  float m_y; // [sp+14h] [-4Ch]
  float v17; // [sp+24h] [-3Ch]
  float v18; // [sp+28h] [-38h]

  m_x = result[5].m_x;
  m_z = result[5].m_z;
  v4 = &result[2 * (HIBYTE(result[3].m_z) & 0x7F)];
  v5 = result[7].m_x;
  v6 = result[5].m_z;
  m_y = result[5].m_y;
  v17 = result[7].m_y;
  v18 = result[7].m_z;
  v15 = v4[5].m_z;
  v13 = v4[5].m_x;
  v14 = v4[5].m_y;
  v7 = (float)((float)((float)(v18 - v6) * (float)(v13 - m_x))
             - (float)((float)(v15 - v6) * (float)(result[7].m_x - m_x)));
  v8 = (float)((float)((float)(v14 - m_y) * (float)(result[7].m_x - m_x))
             - (float)((float)(v17 - m_y) * (float)(v13 - m_x)));
  v9 = (float)((float)((float)(v15 - v6) * (float)(v17 - m_y)) - (float)((float)(v14 - m_y) * (float)(v18 - v6)));
  _FP7 = (float)((float)__fsqrts((float)((float)((float)v9 * (float)v9)
                                       + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f7, f6, f12 }
  *(float *)&this->m_pProxy = (float)((float)((float)(v15 - v6) * (float)(v17 - m_y))
                                    - (float)((float)(v14 - m_y) * (float)(v18 - v6)))
                            * (float)_FP5;
  *(float *)&this->m_dynAreaData.m_data = (float)((float)((float)(v18 - v6) * (float)(v13 - m_x))
                                                - (float)((float)(v15 - (float)m_z) * (float)((float)v5 - m_x)))
                                        * (float)_FP5;
  *(float *)&this->m_pFirstLink = (float)((float)((float)(v14 - m_y) * (float)((float)v5 - m_x))
                                        - (float)((float)(v17 - m_y) * (float)(v13 - m_x)))
                                * (float)_FP5;
  return this;
}


// ========================================================================
// ??4?$Handle@VArea@bfx@@@bfx@@QAAAAV01@ABV01@@Z
// EA  : 0x832417F8
// RVA : 0x012417F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::Handle<bfx::Area> *__fastcall bfx::Handle<bfx::Area>::operator=(
        bfx::Handle<bfx::Area> *this,
        const bfx::Handle<bfx::Area> *rhs)
{
  bfx::Handle<bfx::Area> *v2; // r31
  bfx::AreaProxy *m_pProxy; // r4
  int v5; // r11
  bfx::AreaProxy *v6; // r11
  bool v7; // cr58

  v2 = this;
  if ( rhs != this )
  {
    m_pProxy = this->m_pProxy;
    if ( this->m_pProxy != nullptr )
    {
      v5 = m_pProxy->m_refCount - 1;
      m_pProxy->m_refCount = v5;
      if ( v5 == 0 )
      {
        if ( m_pProxy->m_pArea != nullptr )
        {
          m_pProxy->m_pArea->m_pProxy = nullptr;
          m_pProxy->m_pArea = nullptr;
        }
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pProxy);
      }
    }
    v6 = rhs->m_pProxy;
    this = v2;
    v7 = rhs->m_pProxy == nullptr;
    v2->m_pProxy = rhs->m_pProxy;
    if ( !v7 )
      ++v6->m_refCount;
  }
  return this;
}


// ========================================================================
// ??4?$Handle@VArea@bfx@@@bfx@@QAAAAV01@PAVArea@1@@Z
// EA  : 0x832418A0
// RVA : 0x012418A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::Handle<bfx::Area> *__fastcall bfx::Handle<bfx::Area>::operator=(bfx::Handle<bfx::Area> *this, bfx::Area *pArea)
{
  bfx::AreaProxy *m_pProxy; // r4
  int v5; // r11
  bfx::AreaProxy *v6; // r11
  bfx::AreaProxy *v7; // r3

  m_pProxy = this->m_pProxy;
  if ( this->m_pProxy != nullptr )
  {
    if ( m_pProxy->m_pArea == pArea )
      return this;
    v5 = m_pProxy->m_refCount - 1;
    m_pProxy->m_refCount = v5;
    if ( v5 == 0 )
    {
      if ( m_pProxy->m_pArea != nullptr )
      {
        m_pProxy->m_pArea->m_pProxy = nullptr;
        m_pProxy->m_pArea = nullptr;
      }
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pProxy);
    }
  }
  if ( pArea == nullptr )
  {
    this->m_pProxy = nullptr;
    return this;
  }
  v6 = pArea->m_pProxy;
  if ( pArea->m_pProxy == nullptr )
  {
    v7 = (bfx::AreaProxy *)bfx::MemoryManager::Malloc(
                             this: bfx::g_pCurInstance->m_pMemoryManager,
                             size: 8u,
                             tag: bfx::MEM_BFXPLANNER);
    if ( v7 != nullptr )
    {
      v7->m_pArea = pArea;
      v6 = v7;
      v7->m_refCount = 0;
      pArea->m_pProxy = v7;
    }
    else
    {
      v6 = nullptr;
    }
  }
  this->m_pProxy = v6;
  ++v6->m_refCount;
  return this;
}


// ========================================================================
// ?Release@?$Handle@VArea@bfx@@@bfx@@QAAXXZ
// EA  : 0x83241980
// RVA : 0x01241980
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

void __fastcall bfx::Handle<bfx::Area>::Release(bfx::Handle<bfx::Area> *this)
{
  bfx::AreaProxy *m_pProxy; // r4
  int v3; // r11

  m_pProxy = this->m_pProxy;
  if ( this->m_pProxy != nullptr )
  {
    v3 = m_pProxy->m_refCount - 1;
    m_pProxy->m_refCount = v3;
    if ( v3 == 0 )
    {
      if ( m_pProxy->m_pArea != nullptr )
      {
        m_pProxy->m_pArea->m_pProxy = nullptr;
        m_pProxy->m_pArea = nullptr;
      }
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pProxy);
    }
    this->m_pProxy = nullptr;
  }
}


// ========================================================================
// ??1?$Handle@VArea@bfx@@@bfx@@QAA@XZ
// EA  : 0x832431A0
// RVA : 0x012431A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

// attributes: thunk
void __fastcall bfx::Handle<bfx::Area>::~Handle<bfx::Area>(bfx::AreaHandleImpl *this)
{
  bfx::Handle<bfx::Area>::Release(this: &this->m_handle);
}


// ========================================================================
// ??0HandleForAreaWithUsageCountTracking@bfx@@QAA@PAVArea@1@@Z
// EA  : 0x832431B0
// RVA : 0x012431B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::HandleForAreaWithUsageCountTracking *__fastcall bfx::HandleForAreaWithUsageCountTracking::HandleForAreaWithUsageCountTracking(
        bfx::HandleForAreaWithUsageCountTracking *this,
        bfx::Area *pArea)
{
  bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: &this->m_areaHandle, pArea);
  if ( pArea != nullptr )
    bfx::AreaFlags::IncAreaUsageCount(this: &pArea->m_flags);
  return this;
}


// ========================================================================
// __unwind$102304
// EA  : 0x832431F0
// RVA : 0x012431F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

void _unwind_102304()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: *(bfx::AreaHandleImpl **)(v0 - 112 + 132));
}


// ========================================================================
// ??0HandleForAreaWithUsageCountTracking@bfx@@QAA@ABV01@@Z
// EA  : 0x83243220
// RVA : 0x01243220
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::HandleForAreaWithUsageCountTracking *__fastcall bfx::HandleForAreaWithUsageCountTracking::HandleForAreaWithUsageCountTracking(
        bfx::HandleForAreaWithUsageCountTracking *this,
        const bfx::HandleForAreaWithUsageCountTracking *rhs)
{
  bfx::AreaProxy *m_pProxy; // r11
  bfx::AreaProxy *v4; // r11

  m_pProxy = rhs->m_areaHandle.m_pProxy;
  this->m_areaHandle.m_pProxy = rhs->m_areaHandle.m_pProxy;
  if ( m_pProxy != nullptr )
    ++m_pProxy->m_refCount;
  v4 = this->m_areaHandle.m_pProxy;
  if ( this->m_areaHandle.m_pProxy != nullptr && v4->m_pArea != nullptr )
    bfx::AreaFlags::IncAreaUsageCount(this: &v4->m_pArea->m_flags);
  return this;
}


// ========================================================================
// __unwind$102325
// EA  : 0x832432B0
// RVA : 0x012432B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

void _unwind_102325()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: *(bfx::AreaHandleImpl **)(v0 - 112 + 132));
}


// ========================================================================
// ??1HandleForAreaWithUsageCountTracking@bfx@@QAA@XZ
// EA  : 0x832432E0
// RVA : 0x012432E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

void __fastcall bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(
        bfx::HandleForAreaWithUsageCountTracking *this)
{
  bfx::AreaProxy *m_pProxy; // r11

  m_pProxy = this->m_areaHandle.m_pProxy;
  if ( this->m_areaHandle.m_pProxy != nullptr && m_pProxy->m_pArea != nullptr )
    bfx::AreaFlags::DecAreaUsageCount(this: &m_pProxy->m_pArea->m_flags);
  bfx::Handle<bfx::Area>::Release(this: &this->m_areaHandle);
}


// ========================================================================
// __unwind$102386
// EA  : 0x8324334C
// RVA : 0x0124334C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

void _unwind_102386()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: *(bfx::AreaHandleImpl **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetEdgeVec@EdgeCursor@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x832708E0
// RVA : 0x012708E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::EdgeCursor *__fastcall bfx::EdgeCursor::GetEdgeVec(bfx::EdgeCursor *this, bfx::Vec3 *result)
{
  float m_x; // r11
  float m_y; // r10
  int v4; // r8
  signed int v5; // r4
  float *v6; // r9
  int v7; // r10
  float v8; // r9
  unsigned int v9; // r4
  float v10; // r8
  float *v11; // r11
  float v12; // r7
  double v13; // fp11
  float v15; // [sp+0h] [-10h]

  m_x = result->m_x;
  m_y = result->m_y;
  v4 = __ROL4__(LODWORD(m_y) + 1, 1);
  v6 = (float *)(24 * LODWORD(m_y) + LODWORD(result->m_x));
  v5 = *(_DWORD *)(LODWORD(result->m_x) + 40) & 0x7F;
  __twllei(v5, 0);
  v7 = 24 * ((LODWORD(m_y) + 1) % v5);
  v9 = v5 & ~(v4 - 1);
  v10 = v6[15];
  v11 = (float *)(v7 + LODWORD(m_x));
  v12 = v6[16];
  v8 = v6[17];
  __twlgei(v9, 0xFFFFFFFF);
  v13 = v11[17];
  v15 = v11[15];
  *(float *)&this->m_i = v11[16] - v12;
  *(float *)&this->m_pArea = v15 - v10;
  *((float *)this + 2) = (float)v13 - v8;
  return this;
}


// ========================================================================
// ?IsObstacleAffected@bfx@@YA_NPAVArea@1@ABVPathSpec@1@@Z
// EA  : 0x83292468
// RVA : 0x01292468
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

BOOL __fastcall bfx::IsObstacleAffected(bfx::Area *pArea, const bfx::PathSpec *pathSpec)
{
  unsigned int m_obstacleBlockageFlags; // r11
  int m_flags2_low; // r10

  m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
  m_flags2_low = LOWORD(pArea->m_flags.m_flags2);
  if ( pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH )
    return (_cntlzw(m_obstacleBlockageFlags - (m_flags2_low & m_obstacleBlockageFlags)) & 0x20) != 0;
  else
    return (m_flags2_low & m_obstacleBlockageFlags) != 0;
}


// ========================================================================
// ?GetEdgeVec@Area@bfx@@QBA?AVVec3@2@H@Z
// EA  : 0x832B1AE8
// RVA : 0x012B1AE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.h
// ========================================================================

bfx::Area *__fastcall bfx::Area::GetEdgeVec(bfx::Area *this, bfx::Vec3 *result, int i)
{
  signed int v3; // r7
  bfx::Vec3 *v4; // r9
  int v5; // r10
  int v6; // r11
  float m_x; // r8
  float m_z; // r5
  bfx::Vec3 *v9; // r11
  float m_y; // r4
  float v11; // r6
  double v12; // fp11
  float back_chain; // [sp+0h] [-10h]

  v3 = LODWORD(result[3].m_y) & 0x7F;
  v4 = &result[2 * i];
  __twllei(v3, 0);
  v5 = __ROL4__(i + 1, 1);
  v6 = 2 * ((i + 1) % v3);
  m_x = v4[5].m_x;
  m_z = v4[5].m_z;
  v9 = &result[v6];
  m_y = v4[5].m_y;
  v11 = v9[5].m_y;
  __twlgei(v3 & ~(v5 - 1), 0xFFFFFFFF);
  v12 = v9[5].m_z;
  back_chain = v9[5].m_x;
  *(float *)&this->m_dynAreaData.m_data = v11 - m_y;
  *(float *)&this->m_pProxy = back_chain - m_x;
  *(float *)&this->m_pFirstLink = (float)v12 - m_z;
  return this;
}

