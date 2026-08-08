
// ========================================================================
// ?RemRefToHandleProxy@HandleProxy@bfx@@AAAXXZ
// EA  : 0x8323D450
// RVA : 0x0123D450
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::HandleProxy::RemRefToHandleProxy(bfx::HandleProxy *this)
{
  int v2; // r10
  int v3; // r11

  v2 = __SPAIR64__((*((_DWORD *)this + 1) >> 8) - 1, *((_DWORD *)this + 1)) >> 24;
  *((_DWORD *)this + 1) = v2;
  if ( (v2 & 0xFFFFFF00) == 0 )
  {
    if ( (v2 & 0xC) == 4 )
    {
      v3 = (char)v2 >> 4;
      if ( v3 == 1 || v3 == 3 )
        bfx::SystemMCoreDeleteTaskForProxy(pProxy: this);
      if ( this->m_pTarget != nullptr )
        ((void (__fastcall *)(bfx::HandleTargetBase *, int))this->m_pTarget->dtr_HandleTargetBase)(
          a1: this->m_pTarget,
          a2: 1);
    }
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this);
  }
}


// ========================================================================
// ?GetNode@Pool@bfx@@QAAPAXXZ
// EA  : 0x8323D9E8
// RVA : 0x0123D9E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Pool::Node *__fastcall bfx::Pool::GetNode(bfx::Pool *this)
{
  bfx::Pool::Node *result; // r3
  bfx::Pool::BlockHeader *v3; // r11
  bfx::Pool::BlockHeader *m_pHead; // r9

  result = this->m_data.m_pUnused;
  if ( result != nullptr )
  {
    this->m_data.m_pUnused = result->m_pNext;
  }
  else
  {
    v3 = bfx::Pool::AllocBlock(
           nodeSize: this->m_data.m_nodeSize,
           numNodes: this->m_data.m_numNodesPerBlock,
           tag: (bfx::bfxMemTag)this->m_data.m_tag);
    m_pHead = this->m_data.m_pHead;
    ++this->m_data.m_numBlocksAllocated;
    v3->m_pNext = m_pHead;
    this->m_data.m_pUnused = (bfx::Pool::Node *)&v3[1];
    this->m_data.m_pHead = v3;
    this->m_data.m_pUnused = (bfx::Pool::Node *)v3[1].m_pNext;
    return (bfx::Pool::Node *)&v3[1];
  }
  return result;
}


// ========================================================================
// ?expand_cap@?$Array@VIslandConnection@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8323F158
// RVA : 0x0123F158
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::IslandConnection>::expand_cap(bfx::Array<bfx::EndPt> *this, int size)
{
  bfx::EndPt *v4; // r3
  bfx::EndPt *v5; // r29
  int v6; // r9
  int v7; // r10
  _DWORD *p_m_val; // r11
  bfx::EndPt *v9; // r7

  v4 = (bfx::EndPt *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 12 * size,
                       tag: (bfx::bfxMemTag)this->m_tag);
  v5 = v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    p_m_val = (_DWORD *)&v4->m_val;
    do
    {
      if ( p_m_val != nullptr )
      {
        v9 = &this->m_data[v7];
        *p_m_val = LODWORD(v9->m_val);
        p_m_val[1] = v9->m_pAABB;
        p_m_val[2] = v9->m_type;
      }
      ++v6;
      ++v7;
      p_m_val += 3;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?expand_cap@?$Array@UPath3DPoint@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8323F208
// RVA : 0x0123F208
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Path3DPoint>::expand_cap(bfx::Array<bfx::Path3DPoint> *this, int size)
{
  bfx::Path3DPoint *v4; // r3
  bfx::Path3DPoint *v5; // r29
  int v6; // r6
  int v7; // r7
  bfx::Path3DPoint *v8; // r8
  bool *p_m_posIsOnPortalPerimeter; // r9
  bool *v10; // r10
  int i; // ctr

  v4 = (bfx::Path3DPoint *)bfx::MemoryManager::Malloc(
                             this: bfx::g_pCurInstance->m_pMemoryManager,
                             size: 36 * size,
                             tag: (bfx::bfxMemTag)this->m_tag);
  v5 = v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != nullptr )
      {
        p_m_posIsOnPortalPerimeter = &v8[-1].m_posIsOnPortalPerimeter;
        v10 = &this->m_data[v7 - 1].m_posIsOnPortalPerimeter;
        for ( i = 9; i != 0; --i )
        {
          v10 += 4;
          p_m_posIsOnPortalPerimeter += 4;
          *(_DWORD *)p_m_posIsOnPortalPerimeter = *(_DWORD *)v10;
        }
      }
      ++v6;
      ++v7;
      ++v8;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$List@PAVArea@bfx@@@bfx@@QAAXABQAVArea@2@@Z
// EA  : 0x83241590
// RVA : 0x01241590
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::List<bfx::Area *>::push_back(
        bfx::List<bfx::NavProbeDisplayData *> *this,
        bfx::NavProbeDisplayData **val)
{
  bfx::List<bfx::NavProbeDisplayData *>::Node *m_pEnd; // r31
  bfx::Pool::Node *Node; // r3

  m_pEnd = this->m_pEnd;
  Node = bfx::Pool::GetNode(this: this->m_pPool);
  if ( Node != nullptr )
    Node->m_pNext = (bfx::Pool::Node *)*val;
  Node[1].m_pNext = (bfx::Pool::Node *)m_pEnd;
  Node[2].m_pNext = (bfx::Pool::Node *)m_pEnd->m_pPrev;
  m_pEnd->m_pPrev->m_pNext = (bfx::List<bfx::NavProbeDisplayData *>::Node *)Node;
  m_pEnd->m_pPrev = (bfx::List<bfx::NavProbeDisplayData *>::Node *)Node;
}


// ========================================================================
// ?push_back@?$Array@UFollowerBuddyData@bfx@@@bfx@@QAAXABUFollowerBuddyData@2@@Z
// EA  : 0x832415F8
// RVA : 0x012415F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::FollowerBuddyData>::push_back(bfx::Array<bfx::EndPt> *this, const bfx::EndPt *val)
{
  int m_cap; // r10
  int m_size; // r11
  float m_val; // r30
  bfx::AABB *m_pAABB; // r29
  bfx::EndPtType m_type; // r28
  int v8; // r4
  bfx::EndPt *v9; // r11
  bfx::EndPt *v10; // r11

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    m_val = val->m_val;
    m_pAABB = val->m_pAABB;
    m_type = val->m_type;
    v8 = 2 * m_cap;
    if ( m_cap == 0 )
      v8 = 1;
    bfx::Array<bfx::IslandConnection>::expand_cap(this, size: v8);
    v9 = &this->m_data[this->m_size];
    if ( v9 != nullptr )
    {
      v9->m_val = m_val;
      v9->m_pAABB = m_pAABB;
      v9->m_type = m_type;
      ++this->m_size;
      return;
    }
  }
  else
  {
    v10 = &this->m_data[m_size];
    if ( v10 != nullptr )
      *v10 = *val;
  }
  ++this->m_size;
}


// ========================================================================
// ?push_back@?$Array@UPath3DPoint@bfx@@@bfx@@QAAXABUPath3DPoint@2@@Z
// EA  : 0x832416B8
// RVA : 0x012416B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Path3DPoint>::push_back(
        bfx::Array<bfx::Path3DPoint> *this,
        const bfx::Path3DPoint *val)
{
  int m_cap; // r8
  int m_size; // r11
  char *v5; // r10
  bool *p_m_posIsOnPortalPerimeter; // r11
  int i; // ctr
  int v8; // r4
  bfx::Path3DPoint *v9; // r11
  bool *v10; // r10
  char *v11; // r11
  int j; // ctr
  bfx::Path3DPoint *v13; // r11
  bool *v14; // r10
  bool *v15; // r11
  int k; // ctr
  char v17; // [sp+4Ch] [-44h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = &v17;
    p_m_posIsOnPortalPerimeter = &val[-1].m_posIsOnPortalPerimeter;
    for ( i = 9; i != 0; --i )
    {
      p_m_posIsOnPortalPerimeter += 4;
      v5 += 4;
      *(_DWORD *)v5 = *(_DWORD *)p_m_posIsOnPortalPerimeter;
    }
    v8 = 2 * m_cap;
    if ( m_cap == 0 )
      v8 = 1;
    bfx::Array<bfx::Path3DPoint>::expand_cap(this, size: v8);
    v9 = &this->m_data[this->m_size];
    if ( v9 != nullptr )
    {
      v10 = &v9[-1].m_posIsOnPortalPerimeter;
      v11 = &v17;
      for ( j = 9; j != 0; --j )
      {
        v11 += 4;
        v10 += 4;
        *(_DWORD *)v10 = *(_DWORD *)v11;
      }
    }
  }
  else
  {
    v13 = &this->m_data[m_size];
    if ( v13 != nullptr )
    {
      v14 = &val[-1].m_posIsOnPortalPerimeter;
      v15 = &v13[-1].m_posIsOnPortalPerimeter;
      for ( k = 9; k != 0; --k )
      {
        v14 += 4;
        v15 += 4;
        *(_DWORD *)v15 = *(_DWORD *)v14;
      }
    }
  }
  ++this->m_size;
}


// ========================================================================
// ??1?$AutoPtr@VPool@bfx@@@bfx@@QAA@XZ
// EA  : 0x832417A8
// RVA : 0x012417A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::AutoPtr<bfx::Pool>::~AutoPtr<bfx::Pool>(bfx::AutoPtr<bfx::Pool> *this)
{
  bfx::Pool *m_data; // r31

  m_data = this->m_data;
  if ( this->m_data != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_data);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// ??1?$List@PAVArea@bfx@@@bfx@@QAA@XZ
// EA  : 0x83243010
// RVA : 0x01243010
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::List<bfx::Area *>::~List<bfx::Area *>(bfx::List<bfx::Island3D *> *this)
{
  bfx::List<bfx::Island3D *>::Node *m_pEnd; // r11
  bfx::Pool *m_pPool; // r9
  bfx::List<bfx::Island3D *>::Node *m_pNext; // r10
  bfx::Pool *m_data; // r31

  if ( this->m_poolAutoPtr.m_data == nullptr )
  {
    this->m_pEnd->m_pPrev->m_pNext = nullptr;
    m_pEnd = this->m_pEnd;
    if ( m_pEnd != nullptr )
    {
      do
      {
        m_pPool = this->m_pPool;
        m_pNext = m_pEnd->m_pNext;
        m_pEnd->m_val = (bfx::Island3D *)this->m_pPool->m_data.m_pUnused;
        m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pEnd;
        m_pEnd = m_pNext;
      }
      while ( m_pNext != nullptr );
    }
  }
  m_data = this->m_poolAutoPtr.m_data;
  if ( m_data != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_poolAutoPtr.m_data);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// ??4?$Handle@VLinkReservation@bfx@@@bfx@@QAAAAV01@ABV01@@Z
// EA  : 0x832430A8
// RVA : 0x012430A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Handle<bfx::Space> *__fastcall bfx::Handle<bfx::LinkReservation>::operator=(
        bfx::Handle<bfx::Space> *this,
        const bfx::Handle<bfx::Space> *rhs)
{
  bfx::Handle<bfx::Space> *v2; // r31
  bfx::HandleProxy *m_pProxy; // r3
  bfx::HandleProxy *v5; // r11
  bool v6; // cr58

  v2 = this;
  if ( rhs != this )
  {
    m_pProxy = this->m_pProxy;
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    v5 = rhs->m_pProxy;
    this = v2;
    v6 = rhs->m_pProxy == nullptr;
    v2->m_pProxy = rhs->m_pProxy;
    if ( !v6 )
      *((_DWORD *)v5 + 1) = (unsigned __int8)*((_DWORD *)v5 + 1)
                          | ((*((_DWORD *)v5 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  }
  return this;
}


// ========================================================================
// ?expand_cap@?$Array@VMPathGoalData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83243F30
// RVA : 0x01243F30
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MPathGoalData>::expand_cap(bfx::Array<bfx::MPathGoalData> *this, int size)
{
  bfx::MPathGoalData *v4; // r25
  int i; // r27
  int v6; // r30
  bfx::MPathGoalData *v7; // r11
  bfx::MPathGoalData *v8; // r10
  bfx::MPathGoalData *v9; // r30
  bfx::Area **m_data; // r4

  v4 = (bfx::MPathGoalData *)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 44 * size,
                               tag: (bfx::bfxMemTag)this->m_tag);
  for ( i = 0; i < this->m_size; v9->m_areas.m_cap = 0 )
  {
    v6 = i;
    v7 = &v4[i];
    if ( v7 != nullptr )
    {
      v8 = &this->m_data[v6];
      v7->m_goalPos.m_x = v8->m_goalPos.m_x;
      v7->m_goalPos.m_y = v8->m_goalPos.m_y;
      v7->m_goalPos.m_z = v8->m_goalPos.m_z;
      v7->m_pArea = v8->m_pArea;
      v7->m_clientGoalIndex = v8->m_clientGoalIndex;
      v7->m_reached = v8->m_reached;
      v7->m_approxPathCost = v8->m_approxPathCost;
      bfx::Array<bfx::RepulsorImpl *>::Array<bfx::RepulsorImpl *>(this: &v7->m_areas, rhs: &v8->m_areas);
    }
    v9 = &this->m_data[v6];
    m_data = v9->m_areas.m_data;
    v9->m_areas.m_size = 0;
    if ( m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
      v9->m_areas.m_data = nullptr;
    }
    ++i;
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v4;
  this->m_cap = size;
}


// ========================================================================
// __unwind$103926
// EA  : 0x8324403C
// RVA : 0x0124403C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_103926()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// ?shrink@?$Array@VMPathGoalData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83244078
// RVA : 0x01244078
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MPathGoalData>::shrink(bfx::Array<bfx::MPathGoalData> *this, int size)
{
  int v4; // r11
  int v5; // r29
  int v6; // r28
  bfx::MPathGoalData *v7; // r31
  bfx::Area **m_data; // r4

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      v7 = &this->m_data[v5];
      m_data = v7->m_areas.m_data;
      v7->m_areas.m_size = 0;
      if ( m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
        v7->m_areas.m_data = nullptr;
      }
      --v6;
      v7->m_areas.m_cap = 0;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ??1?$Array@VMPathGoalData@bfx@@@bfx@@QAA@XZ
// EA  : 0x83245218
// RVA : 0x01245218
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MPathGoalData>::~Array<bfx::MPathGoalData>(bfx::Array<bfx::MPathGoalData> *this)
{
  bfx::Array<bfx::MPathGoalData>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VMPathGoalData@bfx@@@bfx@@QAAXABVMPathGoalData@2@@Z
// EA  : 0x83245280
// RVA : 0x01245280
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MPathGoalData>::push_back(
        bfx::Array<bfx::MPathGoalData> *this,
        const bfx::MPathGoalData *val)
{
  int m_size; // r11
  int m_cap; // r11
  int v5; // r4
  int v6; // r11
  bfx::MPathGoalData *v7; // r3
  bfx::MPathGoalData v8; // [sp+60h] [-50h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    bfx::MPathGoalData::MPathGoalData(this: &v8, __that: val);
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v5 = 2 * m_cap;
    else
      v5 = 1;
    bfx::Array<bfx::MPathGoalData>::expand_cap(this, size: v5);
    if ( &this->m_data[this->m_size] != nullptr )
      bfx::MPathGoalData::MPathGoalData(this: &this->m_data[this->m_size], __that: &v8);
    if ( v8.m_areas.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v8.m_areas.m_data);
  }
  else
  {
    v6 = m_size;
    v7 = &this->m_data[v6];
    if ( &this->m_data[v6] != nullptr )
      bfx::MPathGoalData::MPathGoalData(this: v7, __that: val);
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$105759
// EA  : 0x83245358
// RVA : 0x01245358
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_105759()
{
  int v0; // r12

  bfx::MPathGoalData::~MPathGoalData(this: (bfx::MPathGoalData *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$105760
// EA  : 0x83245380
// RVA : 0x01245380
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_105760()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$105761
// EA  : 0x832453C4
// RVA : 0x012453C4
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_105761()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 80));
}


// ========================================================================
// ?expand_cap@?$Array@VPathSegmentImpl@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83245660
// RVA : 0x01245660
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PathSegmentImpl>::expand_cap(bfx::Array<bfx::PathSegmentImpl> *this, int size)
{
  bfx::PathSegmentImpl *v4; // r27
  int i; // r28
  int v6; // r29
  bfx::HandleForAreaWithUsageCountTracking *v7; // r29
  bfx::HandleProxy *m_pProxy; // r3

  v4 = (bfx::PathSegmentImpl *)bfx::MemoryManager::Memalign(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 alignment: 8u,
                                 size: size << 6,
                                 tag: (bfx::bfxMemTag)this->m_tag);
  for ( i = 0; i < this->m_size; ++i )
  {
    v6 = i << 6;
    if ( &v4[i] != nullptr )
      bfx::PathSegmentImpl::PathSegmentImpl(
        this: &v4[i],
        __that: (const bfx::PathSegmentImpl *)((char *)this->m_data + v6));
    v7 = (bfx::HandleForAreaWithUsageCountTracking *)((char *)this->m_data + v6);
    m_pProxy = (bfx::HandleProxy *)v7[15].m_areaHandle.m_pProxy;
    if ( m_pProxy != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
      v7[15].m_areaHandle.m_pProxy = nullptr;
    }
    bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: v7 + 14);
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v4;
  this->m_cap = size;
}


// ========================================================================
// __unwind$106478
// EA  : 0x83245730
// RVA : 0x01245730
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_106478()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$106488
// EA  : 0x8324576C
// RVA : 0x0124576C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_106488()
{
  int v0; // r12

  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)(*(_DWORD *)(v0 - 176 + 88) + 56));
}


// ========================================================================
// ?shrink@?$Array@VPathSegmentImpl@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832457A0
// RVA : 0x012457A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PathSegmentImpl>::shrink(bfx::Array<bfx::PathSegmentImpl> *this, int size)
{
  int v4; // r11
  int v5; // r29
  int v6; // r28
  bfx::HandleForAreaWithUsageCountTracking *v7; // r30
  bfx::HandleProxy *m_pProxy; // r3

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4 << 6;
    v6 = this->m_size - size;
    do
    {
      v7 = (bfx::HandleForAreaWithUsageCountTracking *)((char *)this->m_data + v5);
      m_pProxy = (bfx::HandleProxy *)v7[15].m_areaHandle.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
        v7[15].m_areaHandle.m_pProxy = nullptr;
      }
      bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: v7 + 14);
      --v6;
      v5 -= 64;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// __unwind$106557
// EA  : 0x8324581C
// RVA : 0x0124581C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_106557()
{
  int v0; // r12

  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)(*(_DWORD *)(v0 - 160 + 80) + 56));
}


// ========================================================================
// ??1?$Array@VPathSegmentImpl@bfx@@@bfx@@QAA@XZ
// EA  : 0x83245F38
// RVA : 0x01245F38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PathSegmentImpl>::~Array<bfx::PathSegmentImpl>(bfx::Array<bfx::PathSegmentImpl> *this)
{
  bfx::Array<bfx::PathSegmentImpl>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VPathSegmentImpl@bfx@@@bfx@@QAAXABVPathSegmentImpl@2@@Z
// EA  : 0x83245FA0
// RVA : 0x01245FA0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PathSegmentImpl>::push_back(
        bfx::Array<bfx::PathSegmentImpl> *this,
        const bfx::PathSegmentImpl *val)
{
  int m_size; // r11
  int m_cap; // r11
  int v5; // r4
  int v6; // r11
  bfx::PathSegmentImpl *v7; // r3
  bfx::PathSegmentImpl v8; // [sp+60h] [-60h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    bfx::PathSegmentImpl::PathSegmentImpl(this: &v8, __that: val);
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v5 = 2 * m_cap;
    else
      v5 = 1;
    bfx::Array<bfx::PathSegmentImpl>::expand_cap(this, size: v5);
    if ( &this->m_data[this->m_size] != nullptr )
      bfx::PathSegmentImpl::PathSegmentImpl(this: &this->m_data[this->m_size], __that: &v8);
    bfx::PathSegmentImpl::~PathSegmentImpl(this: &v8);
  }
  else
  {
    v6 = m_size << 6;
    v7 = (bfx::PathSegmentImpl *)((char *)this->m_data + v6);
    if ( (bfx::PathSegmentImpl *)((char *)this->m_data + v6) != nullptr )
      bfx::PathSegmentImpl::PathSegmentImpl(this: v7, __that: val);
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$107322
// EA  : 0x83246064
// RVA : 0x01246064
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_107322()
{
  int v0; // r12

  bfx::PathSegmentImpl::~PathSegmentImpl(this: (bfx::PathSegmentImpl *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$107323
// EA  : 0x8324608C
// RVA : 0x0124608C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_107323()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$107324
// EA  : 0x832460D0
// RVA : 0x012460D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_107324()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 80));
}


// ========================================================================
// ?expand_cap@?$Array@VMultiPathGoalOutput@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83246270
// RVA : 0x01246270
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MultiPathGoalOutput>::expand_cap(bfx::Array<bfx::MultiPathGoalOutput> *this, int size)
{
  bfx::MultiPathGoalOutput *v4; // r3
  bfx::MultiPathGoalOutput *v5; // r22
  int v6; // r24
  char *p_m_goalArea; // r30
  int v8; // r25
  char *v9; // r29
  bfx::APICriticalSection *m_pGlobalCS; // r28
  int v11; // r11
  bfx::APICriticalSection *v12; // r28
  int v13; // r11
  char *v14; // [sp+50h] [-60h]

  v4 = (bfx::MultiPathGoalOutput *)bfx::MemoryManager::Memalign(
                                     this: bfx::g_pCurInstance->m_pMemoryManager,
                                     alignment: 8u,
                                     size: 48 * size,
                                     tag: (bfx::bfxMemTag)this->m_tag);
  v5 = v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    p_m_goalArea = (char *)&v4->m_goalArea;
    v8 = -12 - (_DWORD)v4;
    do
    {
      if ( p_m_goalArea != (char *)12 )
      {
        v9 = &p_m_goalArea[v8 + (unsigned int)this->m_data];
        *((_DWORD *)p_m_goalArea - 3) = *(_DWORD *)v9;
        *((_DWORD *)p_m_goalArea - 2) = *((_DWORD *)v9 + 1);
        *((_DWORD *)p_m_goalArea - 1) = *((_DWORD *)v9 + 2);
        m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
        if ( m_pGlobalCS != nullptr )
          RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
        if ( p_m_goalArea != nullptr )
        {
          v11 = *((_DWORD *)v9 + 3);
          *(_DWORD *)p_m_goalArea = v11;
          if ( v11 != 0 )
            ++*(_DWORD *)(v11 + 4);
        }
        *((_DWORD *)p_m_goalArea + 1) = *((_DWORD *)v9 + 4);
        if ( m_pGlobalCS != nullptr )
          RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
        *(_QWORD *)(p_m_goalArea + 12) = *((_QWORD *)v9 + 3);
        p_m_goalArea[20] = v9[32];
        *((float *)p_m_goalArea + 6) = *((float *)v9 + 9);
        v12 = bfx::g_pCurInstance->m_pGlobalCS;
        if ( v12 != nullptr )
          RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
        if ( p_m_goalArea != (char *)-28 )
        {
          v13 = *((_DWORD *)v9 + 10);
          *((_DWORD *)p_m_goalArea + 7) = v13;
          if ( v13 != 0 )
            *(_DWORD *)(v13 + 4) = (unsigned __int8)*(_DWORD *)(v13 + 4)
                                 | ((*(_DWORD *)(v13 + 4) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
        }
        if ( v12 != nullptr )
          RtlLeaveCriticalSection(CriticalSection: &v12->m_criticalSection);
      }
      v14 = &p_m_goalArea[v8 + (unsigned int)this->m_data];
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v14 + 10);
      bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(v14 + 12));
      ++v6;
      p_m_goalArea += 48;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// __unwind$107669
// EA  : 0x83246410
// RVA : 0x01246410
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_107669()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(*(_DWORD *)(v0 - 176 + 80) + 12));
}


// ========================================================================
// ?shrink@?$Array@VMultiPathGoalOutput@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83246448
// RVA : 0x01246448
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MultiPathGoalOutput>::shrink(bfx::Array<bfx::MultiPathGoalOutput> *this, int size)
{
  int v4; // r11
  int v5; // r30
  int v6; // r29
  bfx::MultiPathGoalOutput *v7; // [sp+50h] [-40h]

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = this->m_size - size;
    v6 = v4;
    do
    {
      v7 = &this->m_data[v6];
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v7->m_path);
      bfx::AreaHandle::~AreaHandle(this: &v7->m_goalArea);
      --v5;
      --v6;
    }
    while ( v5 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// __unwind$107700
// EA  : 0x832464B8
// RVA : 0x012464B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_107700()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(*(_DWORD *)(v0 - 144 + 80) + 12));
}


// ========================================================================
// ?resize@?$Array@VMultiPathGoalOutput@bfx@@@bfx@@QAAXH@Z
// EA  : 0x832476D8
// RVA : 0x012476D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MultiPathGoalOutput>::resize(bfx::Array<bfx::MultiPathGoalOutput> *this, int size)
{
  int m_size; // r11
  int v5; // r6
  unsigned __int64 v6; // r10
  int v7; // r7
  bfx::MultiPathGoalOutput *v8; // r11
  bfx::MultiPathGoalOutput *v9; // r11
  bfx::MultiPathGoalOutput *v10; // r11
  bfx::MultiPathGoalOutput *v11; // r11
  int v12; // r7
  int v13; // r8
  bfx::MultiPathGoalOutput *v14; // r11

  m_size = this->m_size;
  if ( size <= m_size )
  {
    if ( size < m_size )
      bfx::Array<bfx::MultiPathGoalOutput>::shrink(this, size);
  }
  else
  {
    if ( size > this->m_cap )
      bfx::Array<bfx::MultiPathGoalOutput>::expand_cap(this, size);
    v5 = this->m_size;
    if ( v5 < size )
    {
      LODWORD(v6) = 0;
      if ( size - v5 >= 4 )
      {
        v7 = v5;
        do
        {
          v8 = &this->m_data[v7];
          if ( v8 != nullptr )
          {
            v8->m_goalPos = ZERO_VECTOR_5;
            if ( v8 != (bfx::MultiPathGoalOutput *)-12 )
              v8->m_goalArea.m_handleImpl = nullptr;
            v8->m_goalArea.m_pSpace = nullptr;
            HIDWORD(v6) = &v8->m_path;
            v8->m_userData = v6;
            v8->m_goalReached = false;
            v8->m_approxPathCost = 3.4028235e38;
            if ( v8 != (bfx::MultiPathGoalOutput *)-40 )
              *(_DWORD *)HIDWORD(v6) = 0;
          }
          v9 = &this->m_data[v7 + 1];
          if ( &this->m_data[v7] != (bfx::MultiPathGoalOutput *)-48 )
          {
            v9->m_goalPos = ZERO_VECTOR_5;
            if ( v9 != (bfx::MultiPathGoalOutput *)-12 )
              v9->m_goalArea.m_handleImpl = nullptr;
            v9->m_goalArea.m_pSpace = nullptr;
            HIDWORD(v6) = &v9->m_path;
            v9->m_userData = v6;
            v9->m_goalReached = false;
            v9->m_approxPathCost = 3.4028235e38;
            if ( v9 != (bfx::MultiPathGoalOutput *)-40 )
              *(_DWORD *)HIDWORD(v6) = 0;
          }
          v10 = &this->m_data[v7 + 2];
          if ( &this->m_data[v7 + 3] != (bfx::MultiPathGoalOutput *)48 )
          {
            v10->m_goalPos = ZERO_VECTOR_5;
            if ( v10 != (bfx::MultiPathGoalOutput *)-12 )
              v10->m_goalArea.m_handleImpl = nullptr;
            v10->m_goalArea.m_pSpace = nullptr;
            HIDWORD(v6) = &v10->m_path;
            v10->m_userData = v6;
            v10->m_goalReached = false;
            v10->m_approxPathCost = 3.4028235e38;
            if ( v10 != (bfx::MultiPathGoalOutput *)-40 )
              *(_DWORD *)HIDWORD(v6) = 0;
          }
          v11 = &this->m_data[v7 + 3];
          if ( v11 != nullptr )
          {
            v11->m_goalPos = ZERO_VECTOR_5;
            if ( v11 != (bfx::MultiPathGoalOutput *)-12 )
              v11->m_goalArea.m_handleImpl = nullptr;
            v11->m_goalArea.m_pSpace = nullptr;
            HIDWORD(v6) = &v11->m_path;
            v11->m_userData = v6;
            v11->m_goalReached = false;
            v11->m_approxPathCost = 3.4028235e38;
            if ( v11 != (bfx::MultiPathGoalOutput *)-40 )
              *(_DWORD *)HIDWORD(v6) = 0;
          }
          v5 += 4;
          v7 += 4;
        }
        while ( v5 < size - 3 );
      }
      if ( v5 < size )
      {
        v12 = size - v5;
        v13 = v5;
        do
        {
          v14 = &this->m_data[v13];
          if ( v14 != nullptr )
          {
            v14->m_goalPos = ZERO_VECTOR_5;
            if ( v14 != (bfx::MultiPathGoalOutput *)-12 )
              v14->m_goalArea.m_handleImpl = nullptr;
            v14->m_goalArea.m_pSpace = nullptr;
            v14->m_approxPathCost = 3.4028235e38;
            HIDWORD(v6) = &v14->m_path;
            v14->m_userData = v6;
            v14->m_goalReached = false;
            if ( v14 != (bfx::MultiPathGoalOutput *)-40 )
              *(_DWORD *)HIDWORD(v6) = 0;
          }
          --v12;
          ++v13;
        }
        while ( v12 != 0 );
      }
    }
    this->m_size = size;
  }
}


// ========================================================================
// ??0String@bfx@@QAA@PBD@Z
// EA  : 0x83248628
// RVA : 0x01248628
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::String *__fastcall bfx::String::String(bfx::String *this, const char *data)
{
  const char *v4; // r11
  int v5; // r10
  char *v6; // r3
  const char *v7; // r11
  char *v8; // r10
  char v9; // r9

  if ( data != nullptr )
  {
    v4 = data;
    do
      v5 = *(unsigned __int8 *)v4++;
    while ( v5 != 0 );
    v6 = (char *)bfx::MemoryManager::Malloc(
                   this: bfx::g_pCurInstance->m_pMemoryManager,
                   size: v4 - data,
                   tag: bfx::MEM_STRING);
    v7 = data - 1;
    this->m_data = v6;
    v8 = v6 - 1;
    do
    {
      v9 = *++v7;
      *++v8 = *v7;
    }
    while ( v9 != 0 );
  }
  else
  {
    this->m_data = nullptr;
  }
  return this;
}


// ========================================================================
// ??0String@bfx@@QAA@ABV01@@Z
// EA  : 0x832486D0
// RVA : 0x012486D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::String *__fastcall bfx::String::String(bfx::String *this, const bfx::String *rhs)
{
  char *m_data; // r11
  int v5; // r9
  char *v6; // r3
  char *v7; // r10
  char *v8; // r11
  char v9; // r9

  if ( rhs->m_data != nullptr )
  {
    m_data = rhs->m_data;
    do
      v5 = (unsigned __int8)*m_data++;
    while ( v5 != 0 );
    v6 = (char *)bfx::MemoryManager::Malloc(
                   this: bfx::g_pCurInstance->m_pMemoryManager,
                   size: m_data - rhs->m_data,
                   tag: bfx::MEM_STRING);
    this->m_data = v6;
    v7 = v6 - 1;
    v8 = rhs->m_data - 1;
    do
    {
      v9 = *++v8;
      *++v7 = *v8;
    }
    while ( v9 != 0 );
  }
  else
  {
    this->m_data = nullptr;
  }
  return this;
}


// ========================================================================
// ??1String@bfx@@QAA@XZ
// EA  : 0x83248780
// RVA : 0x01248780
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::String::~String(bfx::String *this)
{
  if ( this->m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
}


// ========================================================================
// ?expand_cap@?$Array@VRVOEntityRecord@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83248D30
// RVA : 0x01248D30
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RVOEntityRecord>::expand_cap(bfx::Array<bfx::QueuedLine> *this, int size)
{
  bfx::QueuedLine *v4; // r3
  bfx::QueuedLine *v5; // r29
  int v6; // r6
  int v7; // r7
  bfx::QueuedLine *v8; // r8
  _DWORD *p_m_a; // r9
  float *v10; // r10
  int i; // ctr

  v4 = (bfx::QueuedLine *)bfx::MemoryManager::Malloc(
                            this: bfx::g_pCurInstance->m_pMemoryManager,
                            size: 40 * size,
                            tag: (bfx::bfxMemTag)this->m_tag);
  v5 = v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != nullptr )
      {
        p_m_a = (_DWORD *)&v8[-1].m_color.m_a;
        v10 = &this->m_data[v7 - 1].m_color.m_a;
        for ( i = 10; i != 0; --i )
          *++p_m_a = *(_DWORD *)++v10;
      }
      ++v6;
      ++v7;
      ++v8;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?expand_cap@?$Array@VQueuedTri@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83248DE8
// RVA : 0x01248DE8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedTri>::expand_cap(bfx::Array<bfx::QueuedTri> *this, int size)
{
  bfx::QueuedTri *v4; // r3
  bfx::QueuedTri *v5; // r27
  int v6; // r28
  int v7; // r29
  bfx::QueuedTri *v8; // r30

  v4 = (bfx::QueuedTri *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 52 * size,
                           tag: (bfx::bfxMemTag)this->m_tag);
  v5 = v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != nullptr )
        memcpy(Dst: v8, Src: &this->m_data[v7], Size: sizeof(bfx::QueuedTri));
      ++v6;
      ++v7;
      ++v8;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$Array@VQueuedLine@bfx@@@bfx@@QAAXABVQueuedLine@2@@Z
// EA  : 0x83248E88
// RVA : 0x01248E88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedLine>::push_back(bfx::Array<bfx::QueuedLine> *this, const bfx::QueuedLine *val)
{
  int m_cap; // r8
  int m_size; // r11
  char *v5; // r10
  _DWORD *p_m_a; // r11
  int i; // ctr
  int v8; // r4
  bfx::QueuedLine *v9; // r11
  _DWORD *v10; // r10
  char *v11; // r11
  int j; // ctr
  bfx::QueuedLine *v13; // r11
  _DWORD *v14; // r10
  _DWORD *v15; // r11
  int k; // ctr
  char v17; // [sp+4Ch] [-44h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = &v17;
    p_m_a = (_DWORD *)&val[-1].m_color.m_a;
    for ( i = 10; i != 0; --i )
    {
      ++p_m_a;
      v5 += 4;
      *(_DWORD *)v5 = *p_m_a;
    }
    v8 = 2 * m_cap;
    if ( m_cap == 0 )
      v8 = 1;
    bfx::Array<bfx::RVOEntityRecord>::expand_cap(this, size: v8);
    v9 = &this->m_data[this->m_size];
    if ( v9 != nullptr )
    {
      v10 = (_DWORD *)&v9[-1].m_color.m_a;
      v11 = &v17;
      for ( j = 10; j != 0; --j )
      {
        v11 += 4;
        *++v10 = *(_DWORD *)v11;
      }
    }
  }
  else
  {
    v13 = &this->m_data[m_size];
    if ( v13 != nullptr )
    {
      v14 = (_DWORD *)&val[-1].m_color.m_a;
      v15 = (_DWORD *)&v13[-1].m_color.m_a;
      for ( k = 10; k != 0; --k )
        *++v15 = *++v14;
    }
  }
  ++this->m_size;
}


// ========================================================================
// ?resize@?$Array@VQueuedLine@bfx@@@bfx@@QAAXH@Z
// EA  : 0x83248F78
// RVA : 0x01248F78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedLine>::resize(bfx::Array<bfx::QueuedLine> *this, int size)
{
  int m_size; // r11

  m_size = this->m_size;
  if ( size <= m_size )
  {
    if ( size >= m_size )
      return;
  }
  else if ( size > this->m_cap )
  {
    bfx::Array<bfx::RVOEntityRecord>::expand_cap(this, size);
  }
  this->m_size = size;
}


// ========================================================================
// ?push_back@?$Array@VQueuedTri@bfx@@@bfx@@QAAXABVQueuedTri@2@@Z
// EA  : 0x83248FD8
// RVA : 0x01248FD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedTri>::push_back(bfx::Array<bfx::QueuedTri> *this, const bfx::QueuedTri *val)
{
  int m_cap; // r30
  int m_size; // r11
  int v5; // r4
  bfx::QueuedTri *v6; // r3
  int v7; // r11
  bfx::QueuedTri v8; // [sp+50h] [-50h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v8 = *val;
    v5 = 2 * m_cap;
    if ( m_cap == 0 )
      v5 = 1;
    bfx::Array<bfx::QueuedTri>::expand_cap(this, size: v5);
    v6 = &this->m_data[this->m_size];
    if ( v6 != nullptr )
    {
      val = &v8;
LABEL_7:
      memcpy(Dst: v6, Src: val, Size: sizeof(bfx::QueuedTri));
    }
  }
  else
  {
    v7 = m_size;
    v6 = &this->m_data[v7];
    if ( &this->m_data[v7] != nullptr )
      goto LABEL_7;
  }
  ++this->m_size;
}


// ========================================================================
// ?resize@?$Array@VQueuedTri@bfx@@@bfx@@QAAXH@Z
// EA  : 0x83249080
// RVA : 0x01249080
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedTri>::resize(bfx::Array<bfx::QueuedTri> *this, int size)
{
  int m_size; // r11

  m_size = this->m_size;
  if ( size <= m_size )
  {
    if ( size >= m_size )
      return;
  }
  else if ( size > this->m_cap )
  {
    bfx::Array<bfx::QueuedTri>::expand_cap(this, size);
  }
  this->m_size = size;
}


// ========================================================================
// ?expand_cap@?$Array@VQueuedString@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832490E8
// RVA : 0x012490E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedString>::expand_cap(bfx::Array<bfx::QueuedString> *this, int size)
{
  int v4; // r28
  bfx::QueuedString *i; // r26
  int v6; // r29
  bfx::String *v7; // r11
  const bfx::String *v8; // r10
  char *m_data; // r4

  v4 = 0;
  for ( i = (bfx::QueuedString *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 16 * size,
                                   tag: (bfx::bfxMemTag)this->m_tag); v4 < this->m_size; ++v4 )
  {
    v6 = v4;
    v7 = (bfx::String *)&i[v4];
    if ( v7 != nullptr )
    {
      v8 = (const bfx::String *)&this->m_data[v6];
      v7->m_data = v8->m_data;
      v7[1].m_data = v8[1].m_data;
      v7[2].m_data = v8[2].m_data;
      bfx::String::String(this: v7 + 3, rhs: v8 + 3);
    }
    m_data = this->m_data[v6].m_string.m_data;
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = i;
  this->m_cap = size;
}


// ========================================================================
// __unwind$76465
// EA  : 0x832491C8
// RVA : 0x012491C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_76465()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 160 + 88));
}


// ========================================================================
// ?shrink@?$Array@VQueuedString@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83249208
// RVA : 0x01249208
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedString>::shrink(bfx::Array<bfx::QueuedString> *this, int size)
{
  int v4; // r11
  int v5; // r31
  int v6; // r29
  char *m_data; // r4

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      m_data = this->m_data[v5].m_string.m_data;
      if ( m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
      --v6;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ?push_back@?$Array@VQueuedString@bfx@@@bfx@@QAAXABVQueuedString@2@@Z
// EA  : 0x8324A950
// RVA : 0x0124A950
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::QueuedString>::push_back(
        bfx::Array<bfx::QueuedString> *this,
        const bfx::QueuedString *val)
{
  int m_size; // r10
  float m_y; // r9
  float m_z; // r8
  int m_cap; // r11
  int v7; // r4
  int v8; // r10
  bfx::QueuedString *v9; // r3
  bfx::QueuedString v10; // [sp+60h] [-30h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_y = val->m_v0.m_y;
    m_z = val->m_v0.m_z;
    v10.m_v0.m_x = val->m_v0.m_x;
    v10.m_v0.m_y = m_y;
    v10.m_v0.m_z = m_z;
    bfx::String::String(this: &v10.m_string, rhs: &val->m_string);
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v7 = 2 * m_cap;
    else
      v7 = 1;
    bfx::Array<bfx::QueuedString>::expand_cap(this, size: v7);
    if ( &this->m_data[this->m_size] != nullptr )
      bfx::QueuedString::QueuedString(this: &this->m_data[this->m_size], __that: &v10);
    if ( v10.m_string.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v10.m_string.m_data);
  }
  else
  {
    v8 = m_size;
    v9 = &this->m_data[v8];
    if ( &this->m_data[v8] != nullptr )
      bfx::QueuedString::QueuedString(this: v9, __that: val);
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$78106
// EA  : 0x8324AA4C
// RVA : 0x0124AA4C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_78106()
{
  int v0; // r12

  bfx::QueuedString::~QueuedString(this: (bfx::QueuedString *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$78107
// EA  : 0x8324AA74
// RVA : 0x0124AA74
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_78107()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$78108
// EA  : 0x8324AAB8
// RVA : 0x0124AAB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_78108()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 144 + 80));
}


// ========================================================================
// ??4String@bfx@@QAAXABV01@@Z
// EA  : 0x8324BDD8
// RVA : 0x0124BDD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::String::operator=(bfx::String *this, const bfx::String *rhs)
{
  char *m_data; // r10
  int v5; // r9
  char *v6; // r3
  char *v7; // r10
  char *v8; // r11
  char v9; // r9

  if ( rhs != this )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
    if ( rhs->m_data != nullptr )
    {
      m_data = rhs->m_data;
      do
        v5 = (unsigned __int8)*m_data++;
      while ( v5 != 0 );
      v6 = (char *)bfx::MemoryManager::Malloc(
                     this: bfx::g_pCurInstance->m_pMemoryManager,
                     size: m_data - rhs->m_data,
                     tag: MEM_DEFAULT);
      this->m_data = v6;
      v7 = v6 - 1;
      v8 = rhs->m_data - 1;
      do
      {
        v9 = *++v8;
        *++v7 = *v8;
      }
      while ( v9 != 0 );
    }
    else
    {
      this->m_data = nullptr;
    }
  }
}


// ========================================================================
// ?erase@?$Array@VTextLine@bfx@@@bfx@@QAAXPAVTextLine@2@@Z
// EA  : 0x8324C980
// RVA : 0x0124C980
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::TextLine>::erase(bfx::Array<bfx::TextLine> *this, bfx::TextLine *ptr)
{
  bfx::TextLine *v3; // r31
  bfx::TextLine *v4; // r29

  v3 = ptr;
  v4 = &this->m_data[this->m_size - 1];
  if ( ptr < v4 )
  {
    do
    {
      bfx::String::operator=(this: &v3->m_text, rhs: &v3[1].m_text);
      v3->m_startTime = v3[1].m_startTime;
      ++v3;
    }
    while ( v3 < v4 );
  }
  if ( v3->m_text.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3->m_text.m_data);
  --this->m_size;
}


// ========================================================================
// ?resize@?$Array@VNavWedge@bfx@@@bfx@@QAAXH@Z
// EA  : 0x8324E628
// RVA : 0x0124E628
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::NavWedge>::resize(bfx::Array<bfx::NavWedge> *this, int size)
{
  int m_size; // r11
  int v5; // r8
  int v6; // r11
  bfx::NavWedge *v7; // r10
  bfx::NavWedge *v8; // r10
  bfx::NavWedge *v9; // r9
  bfx::NavWedge *v10; // r10
  int v11; // r10
  int v12; // ctr
  bfx::NavWedge *v13; // r11

  m_size = this->m_size;
  if ( size <= m_size )
  {
    if ( size >= m_size )
      return;
  }
  else
  {
    if ( size > this->m_cap )
      bfx::Array<bfx::NavWedge>::expand_cap((bfx::Array<bfx::ReplayLogListenerEntry> *)this, size);
    v5 = this->m_size;
    if ( v5 < size )
    {
      if ( size - v5 >= 4 )
      {
        v6 = v5;
        do
        {
          v7 = &this->m_data[v6];
          if ( v7 != nullptr )
          {
            v7->m_startAngle = 0.0;
            v7->m_endAngle = 0.0;
          }
          v8 = &this->m_data[v6 + 1];
          if ( &this->m_data[v6] != (bfx::NavWedge *)-8 )
          {
            v8->m_startAngle = 0.0;
            v8->m_endAngle = 0.0;
          }
          v9 = &this->m_data[v6 + 2];
          if ( &this->m_data[v6 + 3] != (bfx::NavWedge *)8 )
          {
            v9->m_startAngle = 0.0;
            v9->m_endAngle = 0.0;
          }
          v10 = &this->m_data[v6 + 3];
          if ( v10 != nullptr )
          {
            v10->m_startAngle = 0.0;
            v10->m_endAngle = 0.0;
          }
          v5 += 4;
          v6 += 4;
        }
        while ( v5 < size - 3 );
      }
      if ( v5 < size )
      {
        v11 = v5;
        v12 = size - v5;
        do
        {
          v13 = &this->m_data[v11];
          if ( v13 != nullptr )
          {
            v13->m_startAngle = 0.0;
            v13->m_endAngle = 0.0;
          }
          ++v11;
          --v12;
        }
        while ( v12 != 0 );
      }
    }
  }
  this->m_size = size;
}


// ========================================================================
// ?expand_cap@?$Array@PAVEdge@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8324F1F0
// RVA : 0x0124F1F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Edge *>::expand_cap(bfx::Array<bfx::SpaceComponent *> *this, int size)
{
  bfx::SpaceComponent **v4; // r3
  bfx::SpaceComponent **v5; // r30
  int v6; // r9
  int v7; // r10
  bfx::SpaceComponent **v8; // r11

  v4 = (bfx::SpaceComponent **)bfx::MemoryManager::Malloc(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 size: 4 * size,
                                 tag: (bfx::bfxMemTag)this->m_tag);
  v5 = v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != nullptr )
        *v8 = this->m_data[v7];
      ++v6;
      ++v7;
      ++v8;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ??0?$Handle@VLinkBase@bfx@@@bfx@@QAA@PAVLinkBase@1@@Z
// EA  : 0x8324F700
// RVA : 0x0124F700
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Handle<bfx::Space> *__fastcall bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(
        bfx::Handle<bfx::Space> *this,
        bfx::Space *pTarget)
{
  bfx::HandleProxy *v4; // r3
  bfx::HandleProxy *v5; // r30
  char v6; // r11
  bfx::HandleProxy *m_pProxy; // [sp+50h] [-30h]

  if ( pTarget != nullptr )
  {
    m_pProxy = pTarget->m_pProxy;
    if ( m_pProxy != nullptr )
    {
      this->m_pProxy = m_pProxy;
    }
    else
    {
      v4 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 size: 8u,
                                 tag: bfx::MEM_BFXSYSTEM);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v6 = *((_BYTE *)v4 + 7);
        v4->m_pTarget = nullptr;
        *((_DWORD *)v4 + 1) = v6 & 3;
        bfx::HandleProxy::ConnectToTarget(this: v4, pTarget);
      }
      else
      {
        v5 = nullptr;
      }
      this->m_pProxy = v5;
    }
    *((_DWORD *)this->m_pProxy + 1) = (unsigned __int8)*((_DWORD *)this->m_pProxy + 1)
                                    | ((*((_DWORD *)this->m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  }
  else
  {
    this->m_pProxy = nullptr;
  }
  return this;
}


// ========================================================================
// __unwind$74366
// EA  : 0x8324F7BC
// RVA : 0x0124F7BC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_74366()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1LinkConnectionData@bfx@@QAA@XZ
// EA  : 0x8324FF50
// RVA : 0x0124FF50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::LinkConnectionData::~LinkConnectionData(bfx::Handle<bfx::Space> *this)
{
  bfx::HandleProxy *m_pProxy; // r3

  m_pProxy = this->m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_pProxy = nullptr;
  }
}


// ========================================================================
// ?expand_cap@?$Array@VVolumePathSegmentImpl@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83253720
// RVA : 0x01253720
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::VolumePathSegmentImpl>::expand_cap(
        bfx::Array<bfx::VolumePathSegmentImpl> *this,
        int size)
{
  char *v4; // r3
  bfx::VolumePathSegmentImpl *v5; // r26
  int v6; // r27
  _DWORD *v7; // r31
  int v8; // r28
  _DWORD *v9; // r11
  int v10; // r11
  char *v11; // r29
  bfx::HandleProxy *v12; // r3

  v4 = (char *)bfx::MemoryManager::Malloc(
                 this: bfx::g_pCurInstance->m_pMemoryManager,
                 size: 32 * size,
                 tag: (bfx::bfxMemTag)this->m_tag);
  v5 = (bfx::VolumePathSegmentImpl *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = v4 + 16;
    v8 = -16 - (_DWORD)v4;
    do
    {
      if ( v7 != (_DWORD *)16 )
      {
        v9 = (_DWORD *)((char *)v7 + v8 + (unsigned int)this->m_data);
        *(v7 - 4) = *v9;
        *(v7 - 3) = v9[1];
        *(v7 - 2) = v9[2];
        *(v7 - 1) = v9[3];
        *v7 = v9[4];
        v7[1] = v9[5];
        v7[2] = v9[6];
        v10 = v9[7];
        v7[3] = v10;
        if ( v10 != 0 )
          *(_DWORD *)(v10 + 4) = (unsigned __int8)*(_DWORD *)(v10 + 4)
                               | ((*(_DWORD *)(v10 + 4) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      }
      v11 = (char *)v7 + v8 + (unsigned int)this->m_data;
      v12 = *((bfx::HandleProxy **)v11 + 7);
      if ( v12 != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v12);
        *((_DWORD *)v11 + 7) = 0;
      }
      ++v6;
      v7 += 8;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?shrink@?$Array@VVolumePathSegmentImpl@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83253830
// RVA : 0x01253830
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::VolumePathSegmentImpl>::shrink(bfx::Array<bfx::VolumePathSegmentImpl> *this, int size)
{
  int v4; // r11
  int v5; // r30
  int v6; // r28
  bfx::VolumePathSegmentImpl *v7; // r31
  bfx::HandleProxy *m_pProxy; // r3

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      v7 = &this->m_data[v5];
      m_pProxy = v7->m_volume.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
        v7->m_volume.m_pProxy = nullptr;
      }
      --v6;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ??1?$Array@VVolumePathSegmentImpl@bfx@@@bfx@@QAA@XZ
// EA  : 0x83254028
// RVA : 0x01254028
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::VolumePathSegmentImpl>::~Array<bfx::VolumePathSegmentImpl>(
        bfx::Array<bfx::VolumePathSegmentImpl> *this)
{
  bfx::Array<bfx::VolumePathSegmentImpl>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VVolumePathSegmentImpl@bfx@@@bfx@@QAAXABVVolumePathSegmentImpl@2@@Z
// EA  : 0x83254090
// RVA : 0x01254090
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::VolumePathSegmentImpl>::push_back(
        bfx::Array<bfx::VolumePathSegmentImpl> *this,
        const bfx::VolumePathSegmentImpl *val)
{
  int m_size; // r11
  bfx::HandleProxy *m_pProxy; // r29
  bfx::Space *m_pSpace; // r11
  float m_x; // r10
  float m_y; // r9
  float m_z; // r8
  float v9; // r7
  float v10; // r6
  float v11; // r5
  int m_cap; // r11
  int v13; // r4
  bfx::VolumePathSegmentImpl *v14; // r3
  int v15; // r11
  bfx::VolumePathSegmentImpl *v16; // r3
  bfx::VolumePathSegmentImpl v17; // [sp+50h] [-40h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_pSpace = val->m_pSpace;
    m_x = val->m_startPos.m_x;
    m_y = val->m_startPos.m_y;
    m_z = val->m_startPos.m_z;
    v9 = val->m_endPos.m_x;
    v10 = val->m_endPos.m_y;
    v11 = val->m_endPos.m_z;
    v17.m_volume.m_pProxy = val->m_volume.m_pProxy;
    m_pProxy = v17.m_volume.m_pProxy;
    v17.m_pSpace = m_pSpace;
    v17.m_startPos.m_x = m_x;
    v17.m_startPos.m_y = m_y;
    v17.m_startPos.m_z = m_z;
    v17.m_endPos.m_x = v9;
    v17.m_endPos.m_y = v10;
    v17.m_endPos.m_z = v11;
    if ( v17.m_volume.m_pProxy != nullptr )
      *((_DWORD *)v17.m_volume.m_pProxy + 1) = (unsigned __int8)*((_DWORD *)v17.m_volume.m_pProxy + 1)
                                             | ((*((_DWORD *)v17.m_volume.m_pProxy + 1) & 0xFFFFFF00) + 256)
                                             & 0xFFFFFF00;
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v13 = 2 * m_cap;
    else
      v13 = 1;
    bfx::Array<bfx::VolumePathSegmentImpl>::expand_cap(this, size: v13);
    v14 = &this->m_data[this->m_size];
    if ( v14 != nullptr )
      bfx::VolumePathSegmentImpl::VolumePathSegmentImpl(this: v14, __that: &v17);
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    v15 = m_size;
    v16 = &this->m_data[v15];
    if ( &this->m_data[v15] != nullptr )
      bfx::VolumePathSegmentImpl::VolumePathSegmentImpl(this: v16, __that: val);
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$87094
// EA  : 0x8325418C
// RVA : 0x0125418C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_87094()
{
  int v0; // r12

  bfx::VolumePathSegmentImpl::~VolumePathSegmentImpl(this: (bfx::VolumePathSegmentImpl *)(v0 - 144 + 80));
}


// ========================================================================
// ?expand_cap@?$Array@M@bfx@@AAAXH@Z
// EA  : 0x83257640
// RVA : 0x01257640
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<float>::expand_cap(bfx::Array<float> *this, int size)
{
  float *v4; // r3
  float *v5; // r30
  int v6; // r9
  int v7; // r10
  float *v8; // r11

  v4 = (float *)bfx::MemoryManager::Malloc(
                  this: bfx::g_pCurInstance->m_pMemoryManager,
                  size: 4 * size,
                  tag: (bfx::bfxMemTag)this->m_tag);
  v5 = v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != nullptr )
        *v8 = this->m_data[v7];
      ++v6;
      ++v7;
      ++v8;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ??1?$Array@PAVVolume@bfx@@@bfx@@QAA@XZ
// EA  : 0x8325C128
// RVA : 0x0125C128
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(bfx::Array<bfx::SpaceComponent *> *this)
{
  bfx::SpaceComponent **m_data; // r4

  m_data = this->m_data;
  this->m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@M@bfx@@QAAXABM@Z
// EA  : 0x832696B8
// RVA : 0x012696B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<float>::push_back(bfx::Array<float> *this, float *val)
{
  int m_cap; // r10
  int m_size; // r11
  double v5; // fp31
  int v6; // r4
  float *v7; // r11

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = *val;
    v6 = 2 * m_cap;
    if ( m_cap == 0 )
      v6 = 1;
    bfx::Array<float>::expand_cap(this, size: v6);
    if ( &this->m_data[this->m_size] != nullptr )
      this->m_data[this->m_size] = v5;
  }
  else
  {
    v7 = &this->m_data[m_size];
    if ( v7 != nullptr )
      *v7 = *val;
  }
  ++this->m_size;
}


// ========================================================================
// ?expand_cap@?$Array@V?$Handle@VArea@bfx@@@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83272110
// RVA : 0x01272110
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Handle<bfx::Area>>::expand_cap(bfx::Array<bfx::Handle<bfx::Area> > *this, int size)
{
  bfx::Handle<bfx::Area> *v4; // r25
  int v5; // r27
  int v6; // r30
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Handle<bfx::Area> *m_data; // r29
  bfx::AreaProxy *v9; // r4
  int v10; // r11

  v4 = (bfx::Handle<bfx::Area> *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 4 * size,
                                   tag: this->m_tag);
  v5 = 0;
  if ( this->m_size > 0 )
  {
    v6 = 0;
    do
    {
      if ( &v4[v6] != nullptr )
      {
        m_pProxy = this->m_data[v6].m_pProxy;
        v4[v6].m_pProxy = m_pProxy;
        if ( m_pProxy != nullptr )
          ++m_pProxy->m_refCount;
      }
      m_data = this->m_data;
      v9 = this->m_data[v6].m_pProxy;
      if ( v9 != nullptr )
      {
        v10 = v9->m_refCount - 1;
        v9->m_refCount = v10;
        if ( v10 == 0 )
        {
          if ( v9->m_pArea != nullptr )
          {
            v9->m_pArea->m_pProxy = nullptr;
            v9->m_pArea = nullptr;
          }
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v9);
        }
        m_data[v6].m_pProxy = nullptr;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v4;
  this->m_cap = size;
}


// ========================================================================
// ?shrink@?$Array@V?$Handle@VArea@bfx@@@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832721F8
// RVA : 0x012721F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Handle<bfx::Area>>::shrink(bfx::Array<bfx::Handle<bfx::Area> > *this, int size)
{
  int v4; // r11
  int v5; // r31
  int v6; // r27
  bfx::Handle<bfx::Area> *m_data; // r30
  bfx::AreaProxy *m_pProxy; // r4
  int v9; // r11

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      m_data = this->m_data;
      m_pProxy = this->m_data[v5].m_pProxy;
      if ( m_pProxy != nullptr )
      {
        v9 = m_pProxy->m_refCount - 1;
        m_pProxy->m_refCount = v9;
        if ( v9 == 0 )
        {
          if ( m_pProxy->m_pArea != nullptr )
          {
            m_pProxy->m_pArea->m_pProxy = nullptr;
            m_pProxy->m_pArea = nullptr;
          }
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_pProxy);
        }
        m_data[v5].m_pProxy = nullptr;
      }
      --v6;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ??1?$Array@V?$Handle@VArea@bfx@@@bfx@@@bfx@@QAA@XZ
// EA  : 0x83272290
// RVA : 0x01272290
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Handle<bfx::Area>>::~Array<bfx::Handle<bfx::Area>>(
        bfx::Array<bfx::Handle<bfx::Area> > *this)
{
  bfx::Array<bfx::Handle<bfx::Area>>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@V?$Handle@VArea@bfx@@@bfx@@@bfx@@QAAXABV?$Handle@VArea@bfx@@@2@@Z
// EA  : 0x832722F8
// RVA : 0x012722F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Handle<bfx::Area>>::push_back(
        bfx::Array<bfx::Handle<bfx::Area> > *this,
        const bfx::Handle<bfx::Area> *val)
{
  int m_size; // r11
  bfx::AreaProxy *m_pProxy; // r29
  int m_cap; // r11
  int v6; // r4
  bfx::Handle<bfx::Area> *v7; // r10
  bfx::AreaProxy *v8; // r11
  bool v9; // cr58
  int m_refCount; // r10
  bfx::Handle<bfx::Area> v11; // [sp+50h] [-30h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_pProxy = val->m_pProxy;
    v11.m_pProxy = val->m_pProxy;
    if ( v11.m_pProxy != nullptr )
      ++m_pProxy->m_refCount;
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v6 = 2 * m_cap;
    else
      v6 = 1;
    bfx::Array<bfx::Handle<bfx::Area>>::expand_cap(this, size: v6);
    if ( &this->m_data[this->m_size] != nullptr )
    {
      this->m_data[this->m_size].m_pProxy = m_pProxy;
      if ( m_pProxy != nullptr )
        ++m_pProxy->m_refCount;
    }
    bfx::Handle<bfx::Area>::Release(this: &v11);
  }
  else
  {
    v7 = &this->m_data[m_size];
    if ( v7 != nullptr )
    {
      v8 = val->m_pProxy;
      v9 = val->m_pProxy == nullptr;
      v7->m_pProxy = val->m_pProxy;
      if ( !v9 )
      {
        m_refCount = v8->m_refCount;
        v11.m_pProxy = v8;
        v8->m_refCount = m_refCount + 1;
      }
    }
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$27677
// EA  : 0x832723D8
// RVA : 0x012723D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_27677()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 128 + 80));
}


// ========================================================================
// ?erase@?$Array@VPortalSubdivElem@bfx@@@bfx@@QAAXPAVPortalSubdivElem@2@@Z
// EA  : 0x832740B8
// RVA : 0x012740B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivElem>::erase(
        bfx::Array<bfx::PortalSubdivElem> *this,
        bfx::PortalSubdivElem *ptr)
{
  bfx::PortalSubdivElem *v2; // r10
  float *p_m_type; // r11
  int v4; // r9
  float *v5; // r11
  unsigned int v6; // ctr
  int v7; // r10

  v2 = &this->m_data[this->m_size - 1];
  if ( ptr < v2 )
  {
    if ( ((char *)v2 - (char *)ptr + 23) / 24 >= 4 )
    {
      p_m_type = (float *)&ptr[-1].m_type;
      do
      {
        ptr->m_subdivPos.m_x = p_m_type[7];
        ptr += 4;
        p_m_type[2] = p_m_type[8];
        p_m_type[3] = p_m_type[9];
        p_m_type[4] = p_m_type[10];
        p_m_type[5] = p_m_type[11];
        p_m_type[6] = p_m_type[12];
        p_m_type[7] = p_m_type[13];
        p_m_type[8] = p_m_type[14];
        p_m_type[9] = p_m_type[15];
        p_m_type[10] = p_m_type[16];
        p_m_type[11] = p_m_type[17];
        p_m_type[12] = p_m_type[18];
        p_m_type[13] = p_m_type[19];
        p_m_type[14] = p_m_type[20];
        p_m_type[15] = p_m_type[21];
        p_m_type[16] = p_m_type[22];
        p_m_type[17] = p_m_type[23];
        p_m_type[18] = p_m_type[24];
        p_m_type[19] = p_m_type[25];
        p_m_type[20] = p_m_type[26];
        p_m_type[21] = p_m_type[27];
        p_m_type[22] = p_m_type[28];
        p_m_type[23] = p_m_type[29];
        v4 = *((_DWORD *)p_m_type + 30);
        p_m_type += 24;
        *(_DWORD *)p_m_type = v4;
      }
      while ( (int)ptr < (int)&v2[-3] );
    }
    if ( ptr < v2 )
    {
      v5 = (float *)&ptr[-1].m_type;
      v6 = ((char *)v2 - (char *)ptr - 1) / 0x18u + 1;
      do
      {
        v5[1] = v5[7];
        v5[2] = v5[8];
        v5[3] = v5[9];
        v5[4] = v5[10];
        v5[5] = v5[11];
        v7 = *((_DWORD *)v5 + 12);
        v5 += 6;
        *(_DWORD *)v5 = v7;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
  --this->m_size;
}


// ========================================================================
// ??0?$Array@VPortalSubdivElem@bfx@@@bfx@@QAA@ABV01@@Z
// EA  : 0x83274230
// RVA : 0x01274230
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Array<bfx::PortalSubdivElem> *__fastcall bfx::Array<bfx::PortalSubdivElem>::Array<bfx::PortalSubdivElem>(
        bfx::Array<bfx::PortalSubdivElem> *this,
        const bfx::Array<bfx::PortalSubdivElem> *rhs)
{
  int v2; // r31
  int m_size; // r4
  int i; // r30

  v2 = 0;
  this->m_data = nullptr;
  this->m_size = 0;
  this->m_cap = 0;
  this->m_tag = rhs->m_tag;
  m_size = rhs->m_size;
  if ( m_size > 0 )
    bfx::Array<bfx::PortalSubdivElem>::expand_cap(
      (bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> *)this,
      size: m_size);
  for ( i = 0; i < rhs->m_size; ++v2 )
  {
    bfx::Array<bfx::Box>::push_back(
      (bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> *)this,
      val: (const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)&rhs->m_data[v2]);
    ++i;
  }
  return this;
}


// ========================================================================
// ??4?$Array@VPortalSubdivElem@bfx@@@bfx@@QAAXABV01@@Z
// EA  : 0x832742B0
// RVA : 0x012742B0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivElem>::operator=(
        bfx::Array<bfx::PortalSubdivElem> *this,
        const bfx::Array<bfx::PortalSubdivElem> *rhs)
{
  char *m_data; // r4
  int m_size; // r6
  int v6; // r7
  int v7; // r8
  bfx::PortalSubdivType *p_m_type; // r9
  bfx::PortalSubdivType *v9; // r10
  int i; // ctr

  if ( rhs != this )
  {
    m_data = (char *)this->m_data;
    this->m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_data = (bfx::PortalSubdivElem *)bfx::MemoryManager::Malloc(
                                              this: bfx::g_pCurInstance->m_pMemoryManager,
                                              size: 24 * rhs->m_size,
                                              tag: this->m_tag);
    m_size = rhs->m_size;
    v6 = 0;
    this->m_size = m_size;
    this->m_cap = m_size;
    if ( m_size > 0 )
    {
      v7 = 0;
      do
      {
        if ( &this->m_data[v7] != nullptr )
        {
          p_m_type = &this->m_data[v7 - 1].m_type;
          v9 = &rhs->m_data[v7 - 1].m_type;
          for ( i = 6; i != 0; --i )
            *++p_m_type = *++v9;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_size );
    }
  }
}


// ========================================================================
// ??0?$SmallestN@PAVArea@bfx@@@bfx@@QAA@H@Z
// EA  : 0x83277BC0
// RVA : 0x01277BC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::SmallestN<bfx::Volume *> *__fastcall bfx::SmallestN<bfx::Area *>::SmallestN<bfx::Area *>(
        bfx::SmallestN<bfx::Volume *> *this,
        int N)
{
  bfx::bfxMemTag v3; // r10

  v3 = bfx::MEM_BFXSYSTEM;
  this->m_data.m_data = nullptr;
  this->m_data.m_size = 0;
  this->m_data.m_cap = 0;
  this->m_data.m_tag = v3;
  this->m_N = N;
  this->m_pLargest = nullptr;
  if ( N > 0 )
    bfx::Array<bfx::NavWedge>::expand_cap((bfx::Array<bfx::ReplayLogListenerEntry> *)this, size: N);
  return this;
}


// ========================================================================
// __unwind$84226
// EA  : 0x83277C30
// RVA : 0x01277C30
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_84226()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 112 + 132));
}


// ========================================================================
// ?expand_cap@?$Array@VPortalSubdivData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83277C60
// RVA : 0x01277C60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivData>::expand_cap(bfx::Array<bfx::PortalSubdivData> *this, int size)
{
  bfx::PortalSubdivData *v4; // r25
  int i; // r27
  int v6; // r30
  bfx::PortalSubdivData *v7; // r10
  bfx::PortalSubdivData *v8; // r7
  bfx::PortalSubdivData *v9; // r11
  bfx::PortalSubdivData *v10; // r8
  int v11; // ctr
  bfx::PortalSubdivData *v12; // r30
  char *m_data; // r4

  v4 = (bfx::PortalSubdivData *)bfx::MemoryManager::Malloc(
                                  this: bfx::g_pCurInstance->m_pMemoryManager,
                                  size: 60 * size,
                                  tag: this->m_tag);
  for ( i = 0; i < this->m_size; ++i )
  {
    v6 = i;
    v7 = &v4[i];
    if ( v7 != nullptr )
    {
      v8 = &v4[i];
      v9 = &this->m_data[v6];
      v10 = v9;
      v11 = 6;
      v7->m_pPortalEdge = v9->m_pPortalEdge;
      do
      {
        v10 = (bfx::PortalSubdivData *)((char *)v10 + 4);
        v8 = (bfx::PortalSubdivData *)((char *)v8 + 4);
        v8->m_pPortalEdge = v10->m_pPortalEdge;
        --v11;
      }
      while ( v11 != 0 );
      v7->m_edgeLen = v9->m_edgeLen;
      v7->m_edgeUnitVec.m_x = v9->m_edgeUnitVec.m_x;
      v7->m_edgeUnitVec.m_y = v9->m_edgeUnitVec.m_y;
      v7->m_edgeUnitVec.m_z = v9->m_edgeUnitVec.m_z;
      bfx::Array<bfx::PortalSubdivElem>::Array<bfx::PortalSubdivElem>(this: &v7->m_subdivElems, rhs: &v9->m_subdivElems);
    }
    v12 = &this->m_data[v6];
    m_data = (char *)v12->m_subdivElems.m_data;
    v12->m_subdivElems.m_size = 0;
    if ( m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
      v12->m_subdivElems.m_data = nullptr;
    }
    v12->m_subdivElems.m_cap = 0;
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v4;
  this->m_cap = size;
}


// ========================================================================
// __unwind$44088
// EA  : 0x83277D78
// RVA : 0x01277D78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_44088()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// ?shrink@?$Array@VPortalSubdivData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83277DB8
// RVA : 0x01277DB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivData>::shrink(bfx::Array<bfx::PortalSubdivData> *this, int size)
{
  int v4; // r11
  int v5; // r29
  int v6; // r28
  bfx::PortalSubdivData *v7; // r31
  char *m_data; // r4

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      v7 = &this->m_data[v5];
      m_data = (char *)v7->m_subdivElems.m_data;
      v7->m_subdivElems.m_size = 0;
      if ( m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
        v7->m_subdivElems.m_data = nullptr;
      }
      --v6;
      v7->m_subdivElems.m_cap = 0;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ??1?$Array@VPortalSubdivData@bfx@@@bfx@@QAA@XZ
// EA  : 0x8327A468
// RVA : 0x0127A468
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivData>::~Array<bfx::PortalSubdivData>(
        bfx::Array<bfx::PortalSubdivData> *this)
{
  bfx::Array<bfx::PortalSubdivData>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VPortalSubdivData@bfx@@@bfx@@QAAXABVPortalSubdivData@2@@Z
// EA  : 0x8327A4D0
// RVA : 0x0127A4D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivData>::push_back(
        bfx::Array<bfx::PortalSubdivData> *this,
        const bfx::PortalSubdivData *val)
{
  int m_size; // r11
  int m_cap; // r11
  int v5; // r4
  int v6; // r11
  bfx::PortalSubdivData *v7; // r3
  bfx::PortalSubdivData v8; // [sp+60h] [-60h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    bfx::PortalSubdivData::PortalSubdivData(this: &v8, __that: val);
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v5 = 2 * m_cap;
    else
      v5 = 1;
    bfx::Array<bfx::PortalSubdivData>::expand_cap(this, size: v5);
    if ( &this->m_data[this->m_size] != nullptr )
      bfx::PortalSubdivData::PortalSubdivData(this: &this->m_data[this->m_size], __that: &v8);
    if ( v8.m_subdivElems.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v8.m_subdivElems.m_data);
  }
  else
  {
    v6 = m_size;
    v7 = &this->m_data[v6];
    if ( &this->m_data[v6] != nullptr )
      bfx::PortalSubdivData::PortalSubdivData(this: v7, __that: val);
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$49828
// EA  : 0x8327A5A8
// RVA : 0x0127A5A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_49828()
{
  int v0; // r12

  bfx::PortalSubdivData::~PortalSubdivData(this: (bfx::PortalSubdivData *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$49829
// EA  : 0x8327A5D0
// RVA : 0x0127A5D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_49829()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$49830
// EA  : 0x8327A614
// RVA : 0x0127A614
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_49830()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 192 + 80));
}


// ========================================================================
// ?erase@?$Array@VPortalSubdivData@bfx@@@bfx@@QAAXPAVPortalSubdivData@2@@Z
// EA  : 0x8327A658
// RVA : 0x0127A658
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivData>::erase(
        bfx::Array<bfx::PortalSubdivData> *this,
        bfx::PortalSubdivData *ptr)
{
  bfx::PortalSubdivData *v3; // r30
  bfx::PortalSubdivData *v4; // r29
  char *p_m_z; // r31
  char *m_data; // r4

  v3 = ptr;
  v4 = &this->m_data[this->m_size - 1];
  if ( ptr < v4 )
  {
    p_m_z = (char *)&ptr[1].m_edgeSeg.m_v1.m_z;
    do
    {
      v3->m_pPortalEdge = *((bfx::Edge **)p_m_z - 6);
      *((float *)p_m_z - 20) = *((float *)p_m_z - 5);
      *((float *)p_m_z - 19) = *((float *)p_m_z - 4);
      *((float *)p_m_z - 18) = *((float *)p_m_z - 3);
      *((float *)p_m_z - 17) = *((float *)p_m_z - 2);
      *((float *)p_m_z - 16) = *((float *)p_m_z - 1);
      *((float *)p_m_z - 15) = *(float *)p_m_z;
      *((float *)p_m_z - 14) = *((float *)p_m_z + 1);
      *((float *)p_m_z - 13) = *((float *)p_m_z + 2);
      *((float *)p_m_z - 12) = *((float *)p_m_z + 3);
      *((float *)p_m_z - 11) = *((float *)p_m_z + 4);
      bfx::Array<bfx::PortalSubdivElem>::operator=(
        this: (bfx::Array<bfx::PortalSubdivElem> *)(p_m_z - 40),
        rhs: (const bfx::Array<bfx::PortalSubdivElem> *)(p_m_z + 20));
      ++v3;
      p_m_z += 60;
    }
    while ( v3 < v4 );
  }
  m_data = (char *)v3->m_subdivElems.m_data;
  v3->m_subdivElems.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    v3->m_subdivElems.m_data = nullptr;
  }
  v3->m_subdivElems.m_cap = 0;
  --this->m_size;
}


// ========================================================================
// ?add_unique@?$FArray@H$03@bfx@@QAAXABH@Z
// EA  : 0x8327A740
// RVA : 0x0127A740
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::FArray<int,4>::add_unique(bfx::FArray<int,4> *this, int *val)
{
  bfx::FArray<int,4> *v2; // r11
  bfx::FArray<int,4> *v3; // r10
  char v4; // r11

  v2 = this;
  v3 = (bfx::FArray<int,4> *)((char *)this + 4 * this->m_size);
  if ( this == v3 )
  {
LABEL_4:
    v4 = 0;
  }
  else
  {
    while ( v2->m_data[0] != *val )
    {
      v2 = (bfx::FArray<int,4> *)((char *)v2 + 4);
      if ( v2 == v3 )
        goto LABEL_4;
    }
    v4 = 1;
  }
  if ( v4 == 0 )
  {
    if ( v3 != nullptr )
      v3->m_data[0] = *val;
    ++this->m_size;
  }
}


// ========================================================================
// ?add_unique@?$FArray@PAVNavGraph@bfx@@$03@bfx@@QAAXABQAVNavGraph@2@@Z
// EA  : 0x8327A7B0
// RVA : 0x0127A7B0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::FArray<bfx::NavGraph *,4>::add_unique(bfx::FArray<bfx::NavGraph *,4> *this, bfx::NavGraph **val)
{
  bfx::FArray<bfx::NavGraph *,4> *v2; // r11
  bfx::FArray<bfx::NavGraph *,4> *v3; // r10
  char v4; // r11

  v2 = this;
  v3 = (bfx::FArray<bfx::NavGraph *,4> *)((char *)this + 4 * this->m_size);
  if ( this == v3 )
  {
LABEL_4:
    v4 = 0;
  }
  else
  {
    while ( v2->m_data[0] != *val )
    {
      v2 = (bfx::FArray<bfx::NavGraph *,4> *)((char *)v2 + 4);
      if ( v2 == v3 )
        goto LABEL_4;
    }
    v4 = 1;
  }
  if ( v4 == 0 )
  {
    if ( v3 != nullptr )
      v3->m_data[0] = *val;
    ++this->m_size;
  }
}


// ========================================================================
// ?Add@?$SmallestN@PAVArea@bfx@@@bfx@@QAAXABQAVArea@2@M@Z
// EA  : 0x8327A820
// RVA : 0x0127A820
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::SmallestN<bfx::Area *>::Add(
        bfx::SmallestN<bfx::Volume *> *this,
        bfx::ReplayListener **data,
        double metric)
{
  int m_N; // r11
  bfx::MetricOb<bfx::Volume *> *m_pLargest; // r11
  bfx::ReplayLogListenerEntry v6; // [sp+50h] [-20h] BYREF

  m_N = this->m_N;
  if ( m_N > 0 )
  {
    if ( this->m_data.m_size >= m_N )
    {
      m_pLargest = this->m_pLargest;
      if ( metric >= m_pLargest->m_metric )
        return;
      m_pLargest->m_data = (bfx::Volume *)*data;
      this->m_pLargest->m_metric = metric;
    }
    else
    {
      v6.m_pListener = *data;
      *(float *)&v6.m_clientOwned = metric;
      bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
        (bfx::Array<bfx::ReplayLogListenerEntry> *)this,
        val: &v6);
      if ( this->m_data.m_size != this->m_N )
        return;
    }
    this->m_pLargest = bfx::SmallestN<bfx::XNode *>::GetLargest(this);
  }
}


// ========================================================================
// ??0?$List@PAVArea@bfx@@@bfx@@QAA@IW4bfxMemTag@1@@Z
// EA  : 0x8327F698
// RVA : 0x0127F698
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::List<bfx::Island3D *> *__fastcall bfx::List<bfx::Area *>::List<bfx::Area *>(
        bfx::List<bfx::Island3D *> *this,
        unsigned int numNodesPerPoolBlock,
        bfx::bfxMemTag memTag)
{
  bfx::AutoPtr<bfx::Pool> *p_m_poolAutoPtr; // r29
  bfx::Pool *v7; // r3
  bfx::Pool *v8; // r3
  bfx::List<bfx::Island3D *>::Node *Node; // r3

  p_m_poolAutoPtr = &this->m_poolAutoPtr;
  this->m_pPool = nullptr;
  this->m_poolAutoPtr.m_data = nullptr;
  this->m_pEnd = nullptr;
  v7 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v7 != nullptr )
    v8 = bfx::Pool::Pool(this: v7, nodeSize: 0xCu, numNodes: numNodesPerPoolBlock, tag: memTag);
  else
    v8 = nullptr;
  this->m_pPool = v8;
  p_m_poolAutoPtr->m_data = v8;
  Node = (bfx::List<bfx::Island3D *>::Node *)bfx::Pool::GetNode(this: this->m_pPool);
  this->m_pEnd = Node;
  Node->m_pNext = Node;
  this->m_pEnd->m_pPrev = this->m_pEnd;
  return this;
}


// ========================================================================
// __unwind$15620
// EA  : 0x8327F73C
// RVA : 0x0127F73C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_15620()
{
  int v0; // r12

  bfx::AutoPtr<bfx::Pool>::~AutoPtr<bfx::Pool>(this: (bfx::AutoPtr<bfx::Pool> *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$15621
// EA  : 0x8327F768
// RVA : 0x0127F768
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_15621()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?expand_cap@?$Array@V?$Pair@IVPolylinePathRCPtr@bfx@@@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83282BA0
// RVA : 0x01282BA0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::expand_cap(
        bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> > *this,
        int size)
{
  int v4; // r28
  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *i; // r27
  int v6; // r29
  bfx::SpaceHandle *v7; // r11
  const bfx::SpaceHandle *v8; // r10

  v4 = 0;
  for ( i = (bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *)bfx::MemoryManager::Malloc(
                                                                this: bfx::g_pCurInstance->m_pMemoryManager,
                                                                size: 8 * size,
                                                                tag: this->m_tag); v4 < this->m_size; ++v4 )
  {
    v6 = v4;
    v7 = (bfx::SpaceHandle *)&i[v4];
    if ( v7 != nullptr )
    {
      v8 = (const bfx::SpaceHandle *)&this->m_data[v6];
      v7->m_pProxy = v8->m_pProxy;
      bfx::MultiPathRCPtr::MultiPathRCPtr(this: v7 + 1, rhs: v8 + 1);
    }
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&this->m_data[v6].m_second);
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = i;
  this->m_cap = size;
}


// ========================================================================
// __unwind$23615
// EA  : 0x83282C5C
// RVA : 0x01282C5C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_23615()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 160 + 88));
}


// ========================================================================
// ?push_back@?$Array@V?$Pair@IVPolylinePathRCPtr@bfx@@@bfx@@@bfx@@QAAXABV?$Pair@IVPolylinePathRCPtr@bfx@@@2@@Z
// EA  : 0x832848C0
// RVA : 0x012848C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::push_back(
        bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> > *this,
        const bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *val)
{
  int m_size; // r11
  int m_cap; // r11
  int v5; // r4
  bfx::SpaceHandle *v6; // r11
  bfx::SpaceHandle *v7; // r11
  unsigned int m_first; // [sp+58h] [-28h]
  bfx::SpaceHandle v9[3]; // [sp+5Ch] [-24h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_first = val->m_first;
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: v9, rhs: (const bfx::SpaceHandle *)&val->m_second);
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v5 = 2 * m_cap;
    else
      v5 = 1;
    bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::expand_cap(this, size: v5);
    v6 = (bfx::SpaceHandle *)&this->m_data[this->m_size];
    if ( v6 != nullptr )
    {
      v6->m_pProxy = (void *)m_first;
      bfx::MultiPathRCPtr::MultiPathRCPtr(this: v6 + 1, rhs: v9);
    }
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v9);
  }
  else
  {
    v7 = (bfx::SpaceHandle *)&this->m_data[m_size];
    if ( v7 != nullptr )
    {
      v7->m_pProxy = (void *)val->m_first;
      bfx::MultiPathRCPtr::MultiPathRCPtr(this: v7 + 1, rhs: (const bfx::SpaceHandle *)&val->m_second);
    }
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$24665
// EA  : 0x832849AC
// RVA : 0x012849AC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_24665()
{
  int v0; // r12

  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>::~Pair<unsigned int,bfx::PolylinePathRCPtr>(this: (bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$24666
// EA  : 0x832849D4
// RVA : 0x012849D4
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_24666()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$24667
// EA  : 0x83284A18
// RVA : 0x01284A18
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_24667()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 80));
}


// ========================================================================
// ?erase@?$Array@V?$Pair@IVPolylinePathRCPtr@bfx@@@bfx@@@bfx@@QAAXPAV?$Pair@IVPolylinePathRCPtr@bfx@@@2@@Z
// EA  : 0x83284A60
// RVA : 0x01284A60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::erase(
        bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> > *this,
        bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *ptr)
{
  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *v3; // r11
  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *v4; // r30
  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *v5; // r31

  v3 = ptr;
  v4 = &this->m_data[this->m_size - 1];
  if ( ptr < v4 )
  {
    do
    {
      v5 = v3 + 1;
      v3->m_first = v3[1].m_first;
      bfx::ObstacleHandle::operator=(
        this: (bfx::SpaceHandle *)&v3->m_second,
        rhs: (const bfx::Handle<bfx::Space> *)&v3[1].m_second);
      v3 = v5;
    }
    while ( v5 < v4 );
  }
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v3->m_second);
  --this->m_size;
}


// ========================================================================
// ?shrink@?$Array@V?$Pair@IVPolylinePathRCPtr@bfx@@@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83284AD0
// RVA : 0x01284AD0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::shrink(
        bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> > *this,
        int size)
{
  int v4; // r11
  int v5; // r30
  int v6; // r31

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&this->m_data[v5].m_second);
      --v6;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ?add@?$ArrayMap@VPolylinePathRCPtr@bfx@@@bfx@@QAAXIVPolylinePathRCPtr@2@@Z
// EA  : 0x832854B0
// RVA : 0x012854B0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::ArrayMap<bfx::PolylinePathRCPtr>::add(
        bfx::ArrayMap<bfx::PolylinePathRCPtr> *this,
        unsigned int key,
        bfx::SpaceHandle *val)
{
  int v6; // r10
  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *m_data; // r8
  int v8; // r11
  bfx::SpaceHandle *v9; // r30
  bfx::SpaceHandle v10[2]; // [sp+50h] [-40h] BYREF
  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> v11[7]; // [sp+58h] [-38h] BYREF

  v6 = 0;
  v10[0] = (bfx::SpaceHandle)this->m_array.m_size;
  if ( (int)v10[0].m_pProxy <= 0 )
  {
LABEL_5:
    v9 = bfx::MultiPathRCPtr::MultiPathRCPtr(this: v10, rhs: val);
    v10[1].m_pProxy = v9;
    v11[0].m_first = key;
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: (bfx::SpaceHandle *)&v11[0].m_second, rhs: v9);
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)v9);
    bfx::Array<bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>>::push_back(this: &this->m_array, val: v11);
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v11[0].m_second);
  }
  else
  {
    m_data = this->m_array.m_data;
    v8 = 0;
    while ( m_data[v8].m_first != key )
    {
      ++v6;
      ++v8;
      if ( v6 >= (int)v10[0].m_pProxy )
        goto LABEL_5;
    }
    bfx::ObstacleHandle::operator=(
      this: (bfx::SpaceHandle *)&m_data[v6].m_second,
      rhs: (const bfx::Handle<bfx::Space> *)val);
  }
  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)val);
}


// ========================================================================
// $M25064_0
// EA  : 0x83285570
// RVA : 0x01285570
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _M25064_0()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v0 - 144 + 180));
}


// ========================================================================
// __unwind$25041
// EA  : 0x83285598
// RVA : 0x01285598
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25041()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$25008
// EA  : 0x832855C0
// RVA : 0x012855C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25008()
{
  int v0; // r12

  bfx::Pair<unsigned int,bfx::PolylinePathRCPtr>::~Pair<unsigned int,bfx::PolylinePathRCPtr>(this: (bfx::Pair<unsigned int,bfx::PolylinePathRCPtr> *)(v0 - 144 + 88));
}


// ========================================================================
// ?expand_cap@?$Array@VMultiPathGoal@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832855F0
// RVA : 0x012855F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MultiPathGoal>::expand_cap(bfx::Array<bfx::MultiPathGoal> *this, int size)
{
  int v4; // r27
  bfx::MultiPathGoal *i; // r25
  int v6; // r26
  bfx::MultiPathGoal *v7; // r30
  bfx::MultiPathGoal *v8; // r29

  v4 = 0;
  for ( i = (bfx::MultiPathGoal *)bfx::MemoryManager::Memalign(
                                    this: bfx::g_pCurInstance->m_pMemoryManager,
                                    alignment: 8u,
                                    size: 40 * size,
                                    tag: this->m_tag); v4 < this->m_size; ++v4 )
  {
    v6 = v4;
    v7 = &i[v4];
    if ( v7 != nullptr )
    {
      v8 = &this->m_data[v6];
      v7->m_goalPos.m_x = v8->m_goalPos.m_x;
      v7->m_goalPos.m_y = v8->m_goalPos.m_y;
      v7->m_goalPos.m_z = v8->m_goalPos.m_z;
      bfx::AreaHandle::AreaHandle(this: &v7->m_goalArea, rhs: &v8->m_goalArea);
      v7->m_userData = v8->m_userData;
      v7->m_skip = v8->m_skip;
    }
    bfx::AreaHandle::~AreaHandle(this: &this->m_data[v6].m_goalArea);
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = i;
  this->m_cap = size;
}


// ========================================================================
// __unwind$25154
// EA  : 0x832856E0
// RVA : 0x012856E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25154()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 176 + 88));
}


// ========================================================================
// ?shrink@?$Array@VMultiPathGoal@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83285720
// RVA : 0x01285720
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MultiPathGoal>::shrink(bfx::Array<bfx::MultiPathGoal> *this, int size)
{
  int v4; // r11
  int v5; // r31
  int v6; // r30

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = this->m_size - size;
    v6 = v4;
    do
    {
      bfx::AreaHandle::~AreaHandle(this: &this->m_data[v6].m_goalArea);
      --v5;
      --v6;
    }
    while ( v5 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ?find@?$ArrayMap@V?$Handle@VLinkBase@bfx@@@bfx@@@bfx@@QAA_NIAAV?$Handle@VLinkBase@bfx@@@2@@Z
// EA  : 0x83285D78
// RVA : 0x01285D78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

int __fastcall bfx::ArrayMap<bfx::Handle<bfx::LinkBase>>::find(
        bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *this,
        unsigned int key,
        bfx::Handle<bfx::LinkBase> *valOut)
{
  int m_size; // r8
  int v5; // r10
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *m_data; // r9
  int i; // r11
  bfx::Handle<bfx::LinkBase> *p_m_second; // r31
  bfx::HandleProxy *m_pProxy; // r11
  bool v11; // cr58

  m_size = this->m_array.m_size;
  v5 = 0;
  if ( m_size <= 0 )
    return 0;
  m_data = this->m_array.m_data;
  for ( i = 0; m_data[i].m_first != key; ++i )
  {
    if ( ++v5 >= m_size )
      return 0;
  }
  p_m_second = &m_data[v5].m_second;
  if ( p_m_second != valOut )
  {
    if ( valOut->m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: valOut->m_pProxy);
    m_pProxy = p_m_second->m_pProxy;
    v11 = p_m_second->m_pProxy == nullptr;
    valOut->m_pProxy = p_m_second->m_pProxy;
    if ( !v11 )
      *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  }
  return 1;
}


// ========================================================================
// ??1?$Array@VMultiPathGoal@bfx@@@bfx@@QAA@XZ
// EA  : 0x83285E30
// RVA : 0x01285E30
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MultiPathGoal>::~Array<bfx::MultiPathGoal>(bfx::Array<bfx::MultiPathGoal> *this)
{
  bfx::Array<bfx::MultiPathGoal>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?resize@?$Array@VMultiPathGoal@bfx@@@bfx@@QAAXH@Z
// EA  : 0x83285E98
// RVA : 0x01285E98
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::MultiPathGoal>::resize(bfx::Array<bfx::MultiPathGoal> *this, int size)
{
  int m_size; // r11
  int i; // r30

  m_size = this->m_size;
  if ( size <= m_size )
  {
    if ( size < m_size )
      bfx::Array<bfx::MultiPathGoal>::shrink(this, size);
  }
  else
  {
    if ( size > this->m_cap )
      bfx::Array<bfx::MultiPathGoal>::expand_cap(this, size);
    for ( i = this->m_size; i < size; ++i )
    {
      if ( &this->m_data[i] != nullptr )
        bfx::MultiPathGoal::MultiPathGoal(this: &this->m_data[i]);
    }
    this->m_size = size;
  }
}


// ========================================================================
// __unwind$25638
// EA  : 0x83285F34
// RVA : 0x01285F34
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25638()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?expand_cap@?$Array@V?$Pair@IV?$Handle@VObstacleImpl@bfx@@@bfx@@@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83285FB8
// RVA : 0x01285FB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::expand_cap(
        bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *this,
        int size)
{
  int v4; // r3
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v5; // r26
  int v6; // r27
  int v7; // r30
  unsigned int *v8; // r29
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v9; // r11
  bfx::HandleProxy *m_pProxy; // r11
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v11; // r28
  bfx::HandleProxy *v12; // r3

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8 * size, tag: this->m_tag);
  v5 = (bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = (unsigned int *)v4;
    do
    {
      if ( v8 != nullptr )
      {
        v9 = &this->m_data[v7];
        *v8 = v9->m_first;
        m_pProxy = v9->m_second.m_pProxy;
        v8[1] = (unsigned int)m_pProxy;
        if ( m_pProxy != nullptr )
          *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                    | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      }
      v11 = &this->m_data[v7];
      v12 = v11->m_second.m_pProxy;
      if ( v12 != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v12);
        v11->m_second.m_pProxy = nullptr;
      }
      ++v6;
      ++v7;
      v8 += 2;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$Array@V?$Pair@IV?$Handle@VLinkBase@bfx@@@bfx@@@bfx@@@bfx@@QAAXABV?$Pair@IV?$Handle@VLinkBase@bfx@@@bfx@@@2@@Z
// EA  : 0x83286938
// RVA : 0x01286938
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase>>>::push_back(
        bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *this,
        const bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *val)
{
  int m_size; // r11
  unsigned int m_first; // r28
  int m_cap; // r11
  int v6; // r4
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v7; // r11
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v8; // r11
  bfx::HandleProxy *v9; // r10
  bfx::HandleProxy *m_pProxy; // [sp+54h] [-2Ch]

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_first = val->m_first;
    m_pProxy = val->m_second.m_pProxy;
    if ( m_pProxy != nullptr )
      *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v6 = 2 * m_cap;
    else
      v6 = 1;
    bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::expand_cap(this, size: v6);
    v7 = &this->m_data[this->m_size];
    if ( v7 != nullptr )
    {
      v7->m_first = m_first;
      v7->m_second.m_pProxy = m_pProxy;
      if ( m_pProxy != nullptr )
        *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                  | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    }
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    v8 = &this->m_data[m_size];
    if ( v8 != nullptr )
    {
      v8->m_first = val->m_first;
      v9 = val->m_second.m_pProxy;
      v8->m_second.m_pProxy = v9;
      if ( v9 != nullptr )
        *((_DWORD *)v9 + 1) = (unsigned __int8)*((_DWORD *)v9 + 1)
                            | ((*((_DWORD *)v9 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    }
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$26889
// EA  : 0x83286A5C
// RVA : 0x01286A5C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_26889()
{
  int v0; // r12

  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase>>::~Pair<unsigned int,bfx::Handle<bfx::LinkBase>>(this: (bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *)(v0 - 128 + 80));
}


// ========================================================================
// ?erase@?$Array@V?$Pair@IV?$Handle@VObstacleImpl@bfx@@@bfx@@@bfx@@@bfx@@QAAXPAV?$Pair@IV?$Handle@VObstacleImpl@bfx@@@bfx@@@2@@Z
// EA  : 0x83286A88
// RVA : 0x01286A88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::erase(
        bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *this,
        bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *ptr)
{
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v3; // r30
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v4; // r28
  bfx::Handle<bfx::LinkBase> *p_m_second; // r31
  bfx::Handle<bfx::LinkBase> *v6; // r29
  bfx::HandleProxy *m_pProxy; // r11
  bool v8; // cr58
  bfx::HandleProxy *v9; // r3

  v3 = ptr;
  v4 = &this->m_data[this->m_size - 1];
  if ( ptr < v4 )
  {
    p_m_second = &ptr->m_second;
    do
    {
      v6 = p_m_second + 2;
      v3->m_first = (unsigned int)p_m_second[1].m_pProxy;
      if ( p_m_second->m_pProxy != nullptr )
        bfx::HandleProxy::RemRefToHandleProxy(this: p_m_second->m_pProxy);
      m_pProxy = v6->m_pProxy;
      v8 = v6->m_pProxy == nullptr;
      p_m_second->m_pProxy = v6->m_pProxy;
      if ( !v8 )
        *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                  | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      p_m_second += 2;
      ++v3;
    }
    while ( v3 < v4 );
  }
  v9 = v3->m_second.m_pProxy;
  if ( v9 != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: v9);
    v3->m_second.m_pProxy = nullptr;
  }
  --this->m_size;
}


// ========================================================================
// ?shrink@?$Array@V?$Pair@IV?$Handle@VObstacleImpl@bfx@@@bfx@@@bfx@@@bfx@@AAAXH@Z
// EA  : 0x83286B48
// RVA : 0x01286B48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::ObstacleImpl>>>::shrink(
        bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > > *this,
        int size)
{
  int v4; // r11
  int v5; // r30
  int v6; // r28
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *v7; // r31
  bfx::HandleProxy *m_pProxy; // r3

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      v7 = &this->m_data[v5];
      m_pProxy = v7->m_second.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
        v7->m_second.m_pProxy = nullptr;
      }
      --v6;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ?add@?$ArrayMap@V?$Handle@VObstacleImpl@bfx@@@bfx@@@bfx@@QAAXIV?$Handle@VObstacleImpl@bfx@@@2@@Z
// EA  : 0x83286BB8
// RVA : 0x01286BB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::ArrayMap<bfx::Handle<bfx::ObstacleImpl>>::add(
        bfx::ArrayMap<bfx::Handle<bfx::LinkBase> > *this,
        unsigned int key,
        bfx::Handle<bfx::LinkBase> *val)
{
  int v5; // r10
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *m_data; // r8
  int v7; // r11
  bfx::HandleProxy *m_pProxy; // r30
  unsigned int *p_m_second; // r30
  bfx::HandleProxy *v10; // r3
  bfx::HandleProxy *v11; // r11
  bool v12; // cr58
  unsigned int v13; // r8
  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > v14; // [sp+50h] [-40h] BYREF

  v5 = 0;
  v14.m_first = this->m_array.m_size;
  if ( (int)v14.m_first <= 0 )
  {
LABEL_5:
    m_pProxy = val->m_pProxy;
    if ( val->m_pProxy != nullptr )
      *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    v14.m_first = key;
    v14.m_second.m_pProxy = m_pProxy;
    if ( m_pProxy != nullptr )
    {
      *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    }
    bfx::Array<bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase>>>::push_back(this: &this->m_array, val: &v14);
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    m_data = this->m_array.m_data;
    v7 = 0;
    while ( m_data[v7].m_first != key )
    {
      ++v5;
      ++v7;
      if ( v5 >= (int)v14.m_first )
        goto LABEL_5;
    }
    p_m_second = (unsigned int *)&m_data[v5].m_second;
    if ( val != (bfx::Handle<bfx::LinkBase> *)p_m_second )
    {
      v10 = (bfx::HandleProxy *)*p_m_second;
      if ( *p_m_second != 0 )
      {
        v14.m_first = *p_m_second;
        bfx::HandleProxy::RemRefToHandleProxy(this: v10);
      }
      v11 = val->m_pProxy;
      v12 = val->m_pProxy == nullptr;
      *p_m_second = (unsigned int)val->m_pProxy;
      if ( !v12 )
      {
        v13 = (unsigned __int8)*((_DWORD *)v11 + 1) | ((*((_DWORD *)v11 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
        v14.m_first = (unsigned int)v11;
        *((_DWORD *)v11 + 1) = v13;
      }
    }
  }
  if ( val->m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: val->m_pProxy);
    val->m_pProxy = nullptr;
  }
}


// ========================================================================
// __unwind$27440
// EA  : 0x83286CE8
// RVA : 0x01286CE8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_27440()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: *(bfx::Handle<bfx::Space> **)(v0 - 144 + 180));
}


// ========================================================================
// __unwind$27442
// EA  : 0x83286D10
// RVA : 0x01286D10
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_27442()
{
  int v0; // r12

  bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase>>::~Pair<unsigned int,bfx::Handle<bfx::LinkBase>>(this: (bfx::Pair<unsigned int,bfx::Handle<bfx::LinkBase> > *)(v0 - 144 + 80));
}


// ========================================================================
// ?expand_cap@?$Array@UClosedNode3D@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832885D8
// RVA : 0x012885D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::ClosedNode3D>::expand_cap(
        bfx::Array<bfx::ResourceManager::Registration> *this,
        int size)
{
  int v4; // r3
  bfx::ResourceManager::Registration *v5; // r30
  int v6; // r9
  int v7; // r10
  unsigned int *v8; // r11
  bfx::ResourceManager::Registration *v9; // r7

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 16 * size, tag: this->m_tag);
  v5 = (bfx::ResourceManager::Registration *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = (unsigned int *)v4;
    do
    {
      if ( v8 != nullptr )
      {
        v9 = &this->m_data[v7];
        *v8 = v9->m_id;
        v8[1] = (unsigned int)v9->m_initCB;
        v8[2] = (unsigned int)v9->m_termCB;
        v8[3] = (unsigned int)v9->m_isUpToDateCB;
      }
      ++v6;
      ++v7;
      v8 += 4;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ??4?$Array@PAVArea@bfx@@@bfx@@QAAXABV01@@Z
// EA  : 0x832889E0
// RVA : 0x012889E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Area *>::operator=(bfx::Array<bfx::Area *> *this, const bfx::Array<bfx::Area *> *rhs)
{
  char *m_data; // r4
  int m_size; // r7
  int v6; // r9
  int v7; // r11

  if ( rhs != this )
  {
    m_data = (char *)this->m_data;
    this->m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_data = (bfx::Area **)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 4 * rhs->m_size,
                                   tag: this->m_tag);
    m_size = rhs->m_size;
    v6 = 0;
    this->m_size = m_size;
    this->m_cap = m_size;
    if ( m_size > 0 )
    {
      v7 = 0;
      do
      {
        if ( &this->m_data[v7] != nullptr )
          this->m_data[v7] = rhs->m_data[v7];
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_size );
    }
  }
}


// ========================================================================
// ?push_back@?$Array@VPlane@bfx@@@bfx@@QAAXABVPlane@2@@Z
// EA  : 0x83288A88
// RVA : 0x01288A88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Plane>::push_back(
        bfx::Array<bfx::ResourceManager::Registration> *this,
        const bfx::ResourceManager::Registration *val)
{
  int m_cap; // r10
  int m_size; // r11
  int v5; // r4
  bfx::ResourceManager::Registration *v6; // r11
  bfx::ResourceManager::Registration *v7; // r11
  bfx::ResourceManager::Registration v11; // 0:^50.16

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v11 = *val;
    v5 = 2 * m_cap;
    if ( m_cap == 0 )
      v5 = 1;
    bfx::Array<bfx::ClosedNode3D>::expand_cap(this, size: v5);
    v6 = &this->m_data[this->m_size];
    if ( v6 != nullptr )
      *v6 = v11;
  }
  else
  {
    v7 = &this->m_data[m_size];
    if ( v7 != nullptr )
      *v7 = *val;
  }
  ++this->m_size;
}


// ========================================================================
// ?reverse@?$Array@PAVArea@bfx@@@bfx@@QAAXXZ
// EA  : 0x8328AD10
// RVA : 0x0128AD10
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Area *>::reverse(bfx::Array<bfx::Area *> *this)
{
  int v1; // r11
  int v2; // r11
  int v3; // r10
  int v4; // ctr
  bfx::Area **m_data; // r9
  bfx::Area *v6; // r7

  v1 = (this->m_size - 2) / 2;
  if ( v1 >= 0 )
  {
    v3 = this->m_size - 1;
    v4 = v1 + 1;
    v2 = 0;
    do
    {
      m_data = this->m_data;
      v6 = this->m_data[v2];
      m_data[v2++] = this->m_data[v3];
      m_data[v3--] = v6;
      --v4;
    }
    while ( v4 != 0 );
  }
}


// ========================================================================
// ?expand_cap@?$Array@VGoalReachedData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328C638
// RVA : 0x0128C638
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::GoalReachedData>::expand_cap(bfx::Array<bfx::SPCorner> *this, int size)
{
  int v4; // r3
  bfx::SPCorner *v5; // r30
  int v6; // r6
  int v7; // r7
  int v8; // r8
  _DWORD *v9; // r9
  bfx::CornerFlavor *p_m_cornerFlavor; // r10
  int i; // ctr

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 32 * size, tag: this->m_tag);
  v5 = (bfx::SPCorner *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != 0 )
      {
        v9 = (_DWORD *)(v8 - 4);
        p_m_cornerFlavor = &this->m_data[v7 - 1].m_cornerFlavor;
        for ( i = 8; i != 0; --i )
          *++v9 = *++p_m_cornerFlavor;
      }
      ++v6;
      ++v7;
      v8 += 32;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?expand_cap@?$Array@VSmartPathCorner@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328C6E8
// RVA : 0x0128C6E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::SmartPathCorner>::expand_cap(bfx::Array<bfx::SmartPathCorner> *this, int size)
{
  int v4; // r3
  bfx::SmartPathCorner *v5; // r30
  int v6; // r6
  int v7; // r7
  int v8; // r8
  _DWORD *v9; // r9
  bfx::Area **p_m_pArea; // r10
  int i; // ctr

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 28 * size, tag: this->m_tag);
  v5 = (bfx::SmartPathCorner *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != 0 )
      {
        v9 = (_DWORD *)(v8 - 4);
        p_m_pArea = &this->m_data[v7 - 1].m_pArea;
        for ( i = 7; i != 0; --i )
          *++v9 = *++p_m_pArea;
      }
      ++v6;
      ++v7;
      v8 += 28;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$Array@VSPCorner@bfx@@@bfx@@QAAXABVSPCorner@2@@Z
// EA  : 0x8328D660
// RVA : 0x0128D660
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::SPCorner>::push_back(bfx::Array<bfx::SPCorner> *this, const bfx::SPCorner *val)
{
  int m_cap; // r8
  int m_size; // r11
  char *v5; // r10
  bfx::CornerFlavor *p_m_cornerFlavor; // r11
  int i; // ctr
  int v8; // r4
  bfx::CornerFlavor *v9; // r10
  char *v10; // r11
  int j; // ctr
  bfx::SPCorner *v12; // r11
  bfx::CornerFlavor *v13; // r10
  bfx::CornerFlavor *v14; // r11
  int k; // ctr
  char v16; // [sp+4Ch] [-34h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = &v16;
    p_m_cornerFlavor = &val[-1].m_cornerFlavor;
    for ( i = 8; i != 0; --i )
    {
      ++p_m_cornerFlavor;
      v5 += 4;
      *(bfx::CornerFlavor *)v5 = *p_m_cornerFlavor;
    }
    v8 = 2 * m_cap;
    if ( m_cap == 0 )
      v8 = 1;
    bfx::Array<bfx::GoalReachedData>::expand_cap(this, size: v8);
    if ( &this->m_data[this->m_size] != nullptr )
    {
      v9 = &this->m_data[this->m_size - 1].m_cornerFlavor;
      v10 = &v16;
      for ( j = 8; j != 0; --j )
      {
        v10 += 4;
        *++v9 = *(bfx::CornerFlavor *)v10;
      }
    }
  }
  else
  {
    v12 = &this->m_data[m_size];
    if ( v12 != nullptr )
    {
      v13 = &val[-1].m_cornerFlavor;
      v14 = &v12[-1].m_cornerFlavor;
      for ( k = 8; k != 0; --k )
        *++v14 = *++v13;
    }
  }
  ++this->m_size;
}


// ========================================================================
// ?push_back@?$Array@VSmartPathCorner@bfx@@@bfx@@QAAXABVSmartPathCorner@2@@Z
// EA  : 0x8328D740
// RVA : 0x0128D740
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::SmartPathCorner>::push_back(
        bfx::Array<bfx::SmartPathCorner> *this,
        const bfx::SmartPathCorner *val)
{
  int m_cap; // r8
  int m_size; // r11
  char *v5; // r10
  bfx::Area **p_m_pArea; // r11
  int i; // ctr
  int v8; // r4
  bfx::Area **v9; // r10
  char *v10; // r11
  int j; // ctr
  bfx::SmartPathCorner *v12; // r11
  bfx::Area **v13; // r10
  bfx::Area **v14; // r11
  int k; // ctr
  char v16; // [sp+4Ch] [-34h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = &v16;
    p_m_pArea = &val[-1].m_pArea;
    for ( i = 7; i != 0; --i )
    {
      ++p_m_pArea;
      v5 += 4;
      *(_DWORD *)v5 = *p_m_pArea;
    }
    v8 = 2 * m_cap;
    if ( m_cap == 0 )
      v8 = 1;
    bfx::Array<bfx::SmartPathCorner>::expand_cap(this, size: v8);
    if ( &this->m_data[this->m_size] != nullptr )
    {
      v9 = &this->m_data[this->m_size - 1].m_pArea;
      v10 = &v16;
      for ( j = 7; j != 0; --j )
      {
        v10 += 4;
        *++v9 = *(bfx::Area **)v10;
      }
    }
  }
  else
  {
    v12 = &this->m_data[m_size];
    if ( v12 != nullptr )
    {
      v13 = &val[-1].m_pArea;
      v14 = &v12[-1].m_pArea;
      for ( k = 7; k != 0; --k )
        *++v14 = *++v13;
    }
  }
  ++this->m_size;
}


// ========================================================================
// ?expand_cap@?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328F338
// RVA : 0x0128F338
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::expand_cap(
        bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *this,
        int size)
{
  int v4; // r28
  bfx::HandleForAreaWithUsageCountTracking *i; // r27
  int v6; // r29

  v4 = 0;
  for ( i = (bfx::HandleForAreaWithUsageCountTracking *)bfx::MemoryManager::Malloc(
                                                          this: bfx::g_pCurInstance->m_pMemoryManager,
                                                          size: 4 * size,
                                                          tag: this->m_tag); v4 < this->m_size; ++v4 )
  {
    v6 = v4;
    if ( &i[v4] != nullptr )
      bfx::HandleForAreaWithUsageCountTracking::HandleForAreaWithUsageCountTracking(
        this: &i[v4],
        rhs: &this->m_data[v6]);
    bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: &this->m_data[v6]);
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = i;
  this->m_cap = size;
}


// ========================================================================
// __unwind$30649
// EA  : 0x8328F3E0
// RVA : 0x0128F3E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_30649()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 160 + 88));
}


// ========================================================================
// ?shrink@?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328F420
// RVA : 0x0128F420
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::shrink(
        bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *this,
        int size)
{
  int v4; // r11
  int v5; // r30
  int v6; // r31

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: &this->m_data[v5]);
      --v6;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ?pop_back@?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@bfx@@QAAXXZ
// EA  : 0x8328F658
// RVA : 0x0128F658
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::pop_back(
        bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *this)
{
  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: &this->m_data[this->m_size - 1]);
  --this->m_size;
}


// ========================================================================
// ??1?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@bfx@@QAA@XZ
// EA  : 0x8328F6A8
// RVA : 0x0128F6A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::~Array<bfx::HandleForAreaWithUsageCountTracking>(
        bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *this)
{
  bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@bfx@@QAAXABVHandleForAreaWithUsageCountTracking@2@@Z
// EA  : 0x8328F710
// RVA : 0x0128F710
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::push_back(
        bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *this,
        const bfx::HandleForAreaWithUsageCountTracking *val)
{
  int m_size; // r11
  int m_cap; // r11
  int v5; // r4
  bfx::HandleForAreaWithUsageCountTracking *v6; // r3
  int v7; // r11
  bfx::HandleForAreaWithUsageCountTracking *v8; // r3
  bool v9; // cr34
  bfx::HandleForAreaWithUsageCountTracking v10; // [sp+50h] [-20h] BYREF
  bfx::HandleForAreaWithUsageCountTracking *v11; // [sp+54h] [-1Ch]

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    bfx::HandleForAreaWithUsageCountTracking::HandleForAreaWithUsageCountTracking(this: &v10, rhs: val);
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v5 = 2 * m_cap;
    else
      v5 = 1;
    bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::expand_cap(this, size: v5);
    v6 = &this->m_data[this->m_size];
    v11 = v6;
    if ( v6 != nullptr )
      bfx::HandleForAreaWithUsageCountTracking::HandleForAreaWithUsageCountTracking(this: v6, rhs: &v10);
    bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: &v10);
  }
  else
  {
    v7 = m_size;
    v8 = &this->m_data[v7];
    v9 = &this->m_data[v7] == nullptr;
    v11 = v8;
    if ( !v9 )
      bfx::HandleForAreaWithUsageCountTracking::HandleForAreaWithUsageCountTracking(this: v8, rhs: val);
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$30999
// EA  : 0x8328F7D4
// RVA : 0x0128F7D4
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_30999()
{
  int v0; // r12

  bfx::HandleForAreaWithUsageCountTracking::~HandleForAreaWithUsageCountTracking(this: (bfx::HandleForAreaWithUsageCountTracking *)(v0 - 112 + 80));
}


// ========================================================================
// __unwind$31000
// EA  : 0x8328F7FC
// RVA : 0x0128F7FC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_31000()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 112 + 84));
}


// ========================================================================
// __unwind$31001
// EA  : 0x8328F840
// RVA : 0x0128F840
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_31001()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 112 + 84));
}


// ========================================================================
// ?resize@?$Array@VHandleForAreaWithUsageCountTracking@bfx@@@bfx@@QAAXH@Z
// EA  : 0x8328F888
// RVA : 0x0128F888
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::resize(
        bfx::Array<bfx::HandleForAreaWithUsageCountTracking> *this,
        int size)
{
  int m_size; // r11
  int v5; // r11
  int v6; // r10
  int v7; // ctr

  m_size = this->m_size;
  if ( size <= m_size )
  {
    if ( size < m_size )
      bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::shrink(this, size);
  }
  else
  {
    if ( size > this->m_cap )
      bfx::Array<bfx::HandleForAreaWithUsageCountTracking>::expand_cap(this, size);
    v5 = this->m_size;
    if ( v5 < size )
    {
      v6 = v5;
      v7 = size - v5;
      do
      {
        if ( &this->m_data[v6] != nullptr )
          this->m_data[v6].m_areaHandle.m_pProxy = nullptr;
        ++v6;
        --v7;
      }
      while ( v7 != 0 );
    }
    this->m_size = size;
  }
}


// ========================================================================
// ?expand_cap@?$Array@VAreaExitData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328F9F0
// RVA : 0x0128F9F0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::AreaExitData>::expand_cap(bfx::Array<bfx::AreaExitData> *this, int size)
{
  bfx::AreaExitData *v4; // r26
  int v5; // r28
  int v6; // r30
  bfx::AreaExitData *v7; // r29
  bfx::HandleProxy *m_pProxy; // r3

  v4 = (bfx::AreaExitData *)bfx::MemoryManager::Malloc(
                              this: bfx::g_pCurInstance->m_pMemoryManager,
                              size: 72 * size,
                              tag: this->m_tag);
  v5 = 0;
  if ( this->m_size > 0 )
  {
    v6 = 0;
    do
    {
      if ( &v4[v6] != nullptr )
        bfx::AreaExitData::AreaExitData(this: &v4[v6], __that: &this->m_data[v6]);
      v7 = &this->m_data[v6];
      m_pProxy = v7->m_exitLink.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
        v7->m_exitLink.m_pProxy = nullptr;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v4;
  this->m_cap = size;
}


// ========================================================================
// ?shrink@?$Array@VAreaExitData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328FAA8
// RVA : 0x0128FAA8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::AreaExitData>::shrink(bfx::Array<bfx::AreaExitData> *this, int size)
{
  int v4; // r11
  int v5; // r28
  int v6; // r30
  bfx::AreaExitData *v7; // r31
  bfx::HandleProxy *m_pProxy; // r3

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = this->m_size - size;
    v6 = v4;
    do
    {
      v7 = &this->m_data[v6];
      m_pProxy = v7->m_exitLink.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
        v7->m_exitLink.m_pProxy = nullptr;
      }
      --v5;
      --v6;
    }
    while ( v5 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ?expand_cap@?$Array@VLinkConnectionData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328FB18
// RVA : 0x0128FB18
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::LinkConnectionData>::expand_cap(bfx::Array<bfx::LinkConnectionData> *this, int size)
{
  int v4; // r3
  bfx::LinkConnectionData *v5; // r26
  int v6; // r27
  int v7; // r30
  bfx::HandleProxy **v8; // r28
  bfx::LinkConnectionData *v9; // r10
  bfx::HandleProxy *m_pProxy; // r11
  bool v11; // cr58
  bfx::LinkConnectionData *m_data; // r29
  bfx::HandleProxy *v13; // r3

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8 * size, tag: this->m_tag);
  v5 = (bfx::LinkConnectionData *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = (bfx::HandleProxy **)v4;
    do
    {
      if ( v8 != nullptr )
      {
        v9 = &this->m_data[v7];
        m_pProxy = v9->m_link.m_pProxy;
        v11 = v9->m_link.m_pProxy == nullptr;
        *v8 = v9->m_link.m_pProxy;
        if ( !v11 )
          *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                    | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
        v8[1] = (bfx::HandleProxy *)v9->m_startAreaIndex;
      }
      m_data = this->m_data;
      v13 = this->m_data[v7].m_link.m_pProxy;
      if ( v13 != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v13);
        m_data[v7].m_link.m_pProxy = nullptr;
      }
      ++v6;
      ++v7;
      v8 += 2;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?shrink@?$Array@VLinkConnectionData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8328FBF0
// RVA : 0x0128FBF0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::LinkConnectionData>::shrink(bfx::Array<bfx::LinkConnectionData> *this, int size)
{
  int v4; // r11
  int v5; // r31
  int v6; // r28
  bfx::LinkConnectionData *m_data; // r30
  bfx::HandleProxy *m_pProxy; // r3

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = v4;
    v6 = this->m_size - size;
    do
    {
      m_data = this->m_data;
      m_pProxy = this->m_data[v5].m_link.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
        m_data[v5].m_link.m_pProxy = nullptr;
      }
      --v6;
      --v5;
    }
    while ( v6 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ?pop_back@?$Array@VAreaExitData@bfx@@@bfx@@QAAXXZ
// EA  : 0x8328FDA8
// RVA : 0x0128FDA8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::AreaExitData>::pop_back(bfx::Array<bfx::AreaExitData> *this)
{
  bfx::AreaExitData *v2; // r30
  bfx::HandleProxy *m_pProxy; // r3

  v2 = &this->m_data[this->m_size];
  m_pProxy = v2[-1].m_exitLink.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    v2[-1].m_exitLink.m_pProxy = nullptr;
  }
  --this->m_size;
}


// ========================================================================
// ?pop_back@?$Array@VLinkConnectionData@bfx@@@bfx@@QAAXXZ
// EA  : 0x8328FE18
// RVA : 0x0128FE18
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::LinkConnectionData>::pop_back(bfx::Array<bfx::LinkConnectionData> *this)
{
  bfx::LinkConnectionData *v2; // r30
  bfx::HandleProxy *m_pProxy; // r3

  v2 = &this->m_data[this->m_size];
  m_pProxy = v2[-1].m_link.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    v2[-1].m_link.m_pProxy = nullptr;
  }
  --this->m_size;
}


// ========================================================================
// ??1?$Array@VAreaExitData@bfx@@@bfx@@QAA@XZ
// EA  : 0x8328FE80
// RVA : 0x0128FE80
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::AreaExitData>::~Array<bfx::AreaExitData>(bfx::Array<bfx::AreaExitData> *this)
{
  bfx::Array<bfx::AreaExitData>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VAreaExitData@bfx@@@bfx@@QAAXABVAreaExitData@2@@Z
// EA  : 0x8328FEE8
// RVA : 0x0128FEE8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::AreaExitData>::push_back(
        bfx::Array<bfx::AreaExitData> *this,
        const bfx::AreaExitData *val)
{
  int m_size; // r11
  int m_cap; // r11
  int v5; // r4
  bfx::AreaExitData *v6; // r3
  int v7; // r11
  bfx::AreaExitData *v8; // r3
  bfx::AreaExitData v9; // [sp+50h] [-60h] BYREF

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    bfx::AreaExitData::AreaExitData(this: &v9, __that: val);
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v5 = 2 * m_cap;
    else
      v5 = 1;
    bfx::Array<bfx::AreaExitData>::expand_cap(this, size: v5);
    v6 = &this->m_data[this->m_size];
    if ( v6 != nullptr )
      bfx::AreaExitData::AreaExitData(this: v6, __that: &v9);
    if ( v9.m_exitLink.m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: v9.m_exitLink.m_pProxy);
  }
  else
  {
    v7 = m_size;
    v8 = &this->m_data[v7];
    if ( &this->m_data[v7] != nullptr )
      bfx::AreaExitData::AreaExitData(this: v8, __that: val);
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$31734
// EA  : 0x8328FFB8
// RVA : 0x0128FFB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_31734()
{
  int v0; // r12

  bfx::AreaExitData::~AreaExitData(this: (bfx::AreaExitData *)(v0 - 176 + 80));
}


// ========================================================================
// ?push_back@?$Array@VLinkConnectionData@bfx@@@bfx@@QAAXABVLinkConnectionData@2@@Z
// EA  : 0x8328FFE8
// RVA : 0x0128FFE8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::LinkConnectionData>::push_back(
        bfx::Array<bfx::LinkConnectionData> *this,
        const bfx::LinkConnectionData *val)
{
  int m_size; // r11
  bfx::HandleProxy *m_pProxy; // r29
  int m_startAreaIndex; // r28
  int m_cap; // r11
  int v7; // r4
  bfx::LinkConnectionData *v8; // r11
  bfx::LinkConnectionData *v9; // r10
  bfx::HandleProxy *v10; // r11
  bool v11; // cr58

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_pProxy = val->m_link.m_pProxy;
    if ( val->m_link.m_pProxy != nullptr )
      *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    m_startAreaIndex = val->m_startAreaIndex;
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v7 = 2 * m_cap;
    else
      v7 = 1;
    bfx::Array<bfx::LinkConnectionData>::expand_cap(this, size: v7);
    v8 = &this->m_data[this->m_size];
    if ( v8 != nullptr )
    {
      v8->m_link.m_pProxy = m_pProxy;
      if ( m_pProxy != nullptr )
        *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                  | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      v8->m_startAreaIndex = m_startAreaIndex;
    }
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    v9 = &this->m_data[m_size];
    if ( v9 != nullptr )
    {
      v10 = val->m_link.m_pProxy;
      v11 = val->m_link.m_pProxy == nullptr;
      v9->m_link.m_pProxy = val->m_link.m_pProxy;
      if ( !v11 )
        *((_DWORD *)v10 + 1) = (unsigned __int8)*((_DWORD *)v10 + 1)
                             | ((*((_DWORD *)v10 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      v9->m_startAreaIndex = val->m_startAreaIndex;
    }
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$31810
// EA  : 0x832900FC
// RVA : 0x012900FC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_31810()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 128 + 80));
}


// ========================================================================
// ?expand_cap@?$Array@E@bfx@@AAAXH@Z
// EA  : 0x83293CD8
// RVA : 0x01293CD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<unsigned char>::expand_cap(bfx::Array<unsigned char> *this, unsigned int size)
{
  int v4; // r3
  unsigned __int8 *v5; // r30
  int i; // r11

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size, tag: this->m_tag);
  v5 = (unsigned __int8 *)v4;
  for ( i = 0; i < this->m_size; ++i )
  {
    if ( i + v4 != 0 )
      *(_BYTE *)(i + v4) = this->m_data[i];
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$Array@E@bfx@@QAAXABE@Z
// EA  : 0x83293E38
// RVA : 0x01293E38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<unsigned char>::push_back(bfx::Array<unsigned char> *this, unsigned __int8 *val)
{
  int m_cap; // r11
  int m_size; // r10
  unsigned __int8 v5; // r30
  unsigned int v6; // r4

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = *val;
    v6 = 2 * m_cap;
    if ( m_cap == 0 )
      v6 = 1;
    bfx::Array<unsigned char>::expand_cap(this, size: v6);
    if ( &this->m_data[this->m_size] != nullptr )
      this->m_data[this->m_size] = v5;
  }
  else if ( &this->m_data[m_size] != nullptr )
  {
    this->m_data[m_size] = *val;
  }
  ++this->m_size;
}


// ========================================================================
// ?expand_cap@?$Array@VOverlapData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832972C0
// RVA : 0x012972C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::OverlapData>::expand_cap(bfx::Array<bfx::ReplayPlayer::Registration> *this, int size)
{
  int v4; // r3
  bfx::ReplayPlayer::Registration *v5; // r29
  int v6; // r6
  int v7; // r7
  int v8; // r8
  _DWORD *v9; // r9
  float *p_m_priority; // r10
  int i; // ctr

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 20 * size, tag: this->m_tag);
  v5 = (bfx::ReplayPlayer::Registration *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != 0 )
      {
        v9 = (_DWORD *)(v8 - 4);
        p_m_priority = &this->m_data[v7 - 1].m_priority;
        for ( i = 5; i != 0; --i )
          *++v9 = *(_DWORD *)++p_m_priority;
      }
      ++v6;
      ++v7;
      v8 += 20;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$Array@VRegistration@ReplayPlayer@bfx@@@bfx@@QAAXABVRegistration@ReplayPlayer@2@@Z
// EA  : 0x83297378
// RVA : 0x01297378
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::ReplayPlayer::Registration>::push_back(
        bfx::Array<bfx::ReplayPlayer::Registration> *this,
        const bfx::ReplayPlayer::Registration *val)
{
  int m_cap; // r8
  int m_size; // r11
  char *v5; // r10
  _DWORD *p_m_priority; // r11
  int i; // ctr
  int v8; // r4
  bfx::ReplayPlayer::Registration *v9; // r11
  _DWORD *v10; // r10
  char *v11; // r11
  int j; // ctr
  bfx::ReplayPlayer::Registration *v13; // r11
  _DWORD *v14; // r10
  _DWORD *v15; // r11
  int k; // ctr
  char v17; // [sp+4Ch] [-34h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = &v17;
    p_m_priority = (_DWORD *)&val[-1].m_priority;
    for ( i = 5; i != 0; --i )
    {
      ++p_m_priority;
      v5 += 4;
      *(_DWORD *)v5 = *p_m_priority;
    }
    v8 = 2 * m_cap;
    if ( m_cap == 0 )
      v8 = 1;
    bfx::Array<bfx::OverlapData>::expand_cap(this, size: v8);
    v9 = &this->m_data[this->m_size];
    if ( v9 != nullptr )
    {
      v10 = (_DWORD *)&v9[-1].m_priority;
      v11 = &v17;
      for ( j = 5; j != 0; --j )
      {
        v11 += 4;
        *++v10 = *(_DWORD *)v11;
      }
    }
  }
  else
  {
    v13 = &this->m_data[m_size];
    if ( v13 != nullptr )
    {
      v14 = (_DWORD *)&val[-1].m_priority;
      v15 = (_DWORD *)&v13[-1].m_priority;
      for ( k = 5; k != 0; --k )
        *++v15 = *++v14;
    }
  }
  ++this->m_size;
}


// ========================================================================
// ?find@?$Array@VFilterEntry@bfx@@@bfx@@QBA_NABVFilterEntry@2@@Z
// EA  : 0x83297638
// RVA : 0x01297638
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

int __fastcall bfx::Array<bfx::FilterEntry>::find(bfx::Array<bfx::FilterEntry> *this, const bfx::FilterEntry *val)
{
  bfx::FilterEntry *m_data; // r11
  bfx::FilterEntry *v3; // r9
  char v4; // r10

  m_data = this->m_data;
  v3 = &this->m_data[this->m_size];
  if ( this->m_data == v3 )
    return 0;
  while ( 1 )
  {
    if ( m_data->m_componentID != val->m_componentID || (v4 = 1, m_data->m_eventID != val->m_eventID) )
      v4 = 0;
    if ( v4 != 0 )
      break;
    if ( ++m_data == v3 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?add@?$ArrayMap@PAVRepulsor3D@bfx@@@bfx@@QAAXIPAVRepulsor3D@2@@Z
// EA  : 0x8329A238
// RVA : 0x0129A238
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::ArrayMap<bfx::Repulsor3D *>::add(
        bfx::ArrayMap<bfx::VolumeGraph *> *this,
        bfx::ReplayListener *key,
        bfx::VolumeGraph *val)
{
  int m_size; // r8
  int v4; // r10
  bfx::Pair<unsigned int,bfx::VolumeGraph *> *m_data; // r9
  int v6; // r11
  bfx::ReplayLogListenerEntry v7; // [sp+50h] [-10h] BYREF

  m_size = this->m_array.m_size;
  v4 = 0;
  if ( m_size <= 0 )
  {
LABEL_5:
    v7.m_pListener = key;
    *(_DWORD *)&v7.m_clientOwned = val;
    bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
      (bfx::Array<bfx::ReplayLogListenerEntry> *)this,
      val: &v7);
  }
  else
  {
    m_data = this->m_array.m_data;
    v6 = 0;
    while ( (bfx::ReplayListener *)m_data[v6].m_first != key )
    {
      ++v4;
      ++v6;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
    m_data[v4].m_second = val;
  }
}


// ========================================================================
// ?remove@?$ArrayMap@PAVLinkReservation@bfx@@@bfx@@QAAXI@Z
// EA  : 0x8329A2B8
// RVA : 0x0129A2B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::ArrayMap<bfx::LinkReservation *>::remove(
        bfx::ArrayMap<bfx::VolumeGraph *> *this,
        unsigned int key)
{
  int m_size; // r9
  int v4; // r11
  bfx::Pair<unsigned int,bfx::VolumeGraph *> *m_data; // r7
  int i; // r10
  bfx::Pair<unsigned int,bfx::VolumeGraph *> *v7; // r3
  unsigned int v8; // r11

  m_size = this->m_array.m_size;
  v4 = 0;
  if ( m_size > 0 )
  {
    m_data = this->m_array.m_data;
    for ( i = 0; m_data[i].m_first != key; ++i )
    {
      if ( ++v4 >= this->m_array.m_size )
        return;
    }
    v7 = &this->m_array.m_data[v4];
    v8 = (unsigned int)&m_data[m_size - 1];
    if ( (unsigned int)v7 < v8 )
      blkmov(a1: v7, a2: &v7[1], a3: 8 * (((v8 - (unsigned int)v7 - 1) >> 3) + 1));
    --this->m_array.m_size;
  }
}


// ========================================================================
// ?expand_cap@?$Array@VCornerData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8329A380
// RVA : 0x0129A380
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::CornerData>::expand_cap(bfx::Array<bfx::CornerData> *this, int size)
{
  int v4; // r29
  bfx::CornerData *i; // r27
  int v6; // r28
  bfx::CornerData *v7; // [sp+58h] [-48h]

  v4 = 0;
  for ( i = (bfx::CornerData *)bfx::MemoryManager::Malloc(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 size: 36 * size,
                                 tag: this->m_tag); v4 < this->m_size; ++v4 )
  {
    v6 = v4;
    if ( &i[v4] != nullptr )
      bfx::CornerData::CornerData(this: &i[v4], __that: &this->m_data[v6]);
    v7 = &this->m_data[v6];
    bfx::AreaHandle::~AreaHandle(this: &v7->m_areaHandle);
    bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v7->m_linkHandle);
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = i;
  this->m_cap = size;
}


// ========================================================================
// __unwind$25185
// EA  : 0x8329A448
// RVA : 0x0129A448
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25185()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$25195
// EA  : 0x8329A484
// RVA : 0x0129A484
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25195()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(*(_DWORD *)(v0 - 160 + 88) + 20));
}


// ========================================================================
// ?shrink@?$Array@VCornerData@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8329A4B8
// RVA : 0x0129A4B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::CornerData>::shrink(bfx::Array<bfx::CornerData> *this, int size)
{
  int v4; // r11
  int v5; // r30
  int v6; // r29
  bfx::CornerData *v7; // [sp+50h] [-40h]

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = this->m_size - size;
    v6 = v4;
    do
    {
      v7 = &this->m_data[v6];
      bfx::AreaHandle::~AreaHandle(this: &v7->m_areaHandle);
      bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)&v7->m_linkHandle);
      --v5;
      --v6;
    }
    while ( v5 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// __unwind$25233
// EA  : 0x8329A528
// RVA : 0x0129A528
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25233()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(*(_DWORD *)(v0 - 144 + 80) + 20));
}


// ========================================================================
// ??1?$Array@VCornerData@bfx@@@bfx@@QAA@XZ
// EA  : 0x8329ACA0
// RVA : 0x0129ACA0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::CornerData>::~Array<bfx::CornerData>(bfx::Array<bfx::CornerData> *this)
{
  bfx::Array<bfx::CornerData>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?resize@?$Array@VCornerData@bfx@@@bfx@@QAAXH@Z
// EA  : 0x8329AD08
// RVA : 0x0129AD08
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::CornerData>::resize(bfx::Array<bfx::CornerData> *this, int size)
{
  int m_size; // r11
  int i; // r30

  m_size = this->m_size;
  if ( size <= m_size )
  {
    if ( size < m_size )
      bfx::Array<bfx::CornerData>::shrink(this, size);
  }
  else
  {
    if ( size > this->m_cap )
      bfx::Array<bfx::CornerData>::expand_cap(this, size);
    for ( i = this->m_size; i < size; ++i )
    {
      if ( &this->m_data[i] != nullptr )
        bfx::CornerData::CornerData(this: &this->m_data[i]);
    }
    this->m_size = size;
  }
}


// ========================================================================
// __unwind$25880
// EA  : 0x8329ADA4
// RVA : 0x0129ADA4
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_25880()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?push_back@?$Array@PAVPortal@bfx@@@bfx@@QAAXABQAVPortal@2@@Z
// EA  : 0x8329C508
// RVA : 0x0129C508
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Portal *>::push_back(bfx::Array<bfx::Space *> *this, bfx::Space **val)
{
  int m_cap; // r11
  int m_size; // r10
  bfx::Space *v5; // r30
  int v6; // r4

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = *val;
    v6 = 2 * m_cap;
    if ( m_cap == 0 )
      v6 = 1;
    bfx::Array<bfx::Edge *>::expand_cap((bfx::Array<bfx::SpaceComponent *> *)this, size: v6);
    if ( &this->m_data[this->m_size] != nullptr )
      this->m_data[this->m_size] = v5;
  }
  else if ( &this->m_data[m_size] != nullptr )
  {
    this->m_data[m_size] = *val;
  }
  ++this->m_size;
}


// ========================================================================
// ??0?$Array@UPath3DPoint@bfx@@@bfx@@QAA@ABV01@@Z
// EA  : 0x8329DC70
// RVA : 0x0129DC70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Array<bfx::Path3DPoint> *__fastcall bfx::Array<bfx::Path3DPoint>::Array<bfx::Path3DPoint>(
        bfx::Array<bfx::Path3DPoint> *this,
        const bfx::Array<bfx::Path3DPoint> *rhs)
{
  int v2; // r31
  int m_size; // r4
  int i; // r30

  v2 = 0;
  this->m_data = nullptr;
  this->m_size = 0;
  this->m_cap = 0;
  this->m_tag = rhs->m_tag;
  m_size = rhs->m_size;
  if ( m_size > 0 )
    bfx::Array<bfx::Path3DPoint>::expand_cap(this, size: m_size);
  for ( i = 0; i < rhs->m_size; ++v2 )
  {
    bfx::Array<bfx::Path3DPoint>::push_back(this, val: &rhs->m_data[v2]);
    ++i;
  }
  return this;
}


// ========================================================================
// ?remove@?$Array@PAVPath3D@bfx@@@bfx@@QAAXABQAVPath3D@2@@Z
// EA  : 0x8329DCF0
// RVA : 0x0129DCF0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Path3D *>::remove(bfx::Array<bfx::Space *> *this, bfx::Space **val)
{
  bfx::Space **m_data; // r31
  bfx::Space **v5; // r11

  m_data = this->m_data;
  while ( m_data != &this->m_data[this->m_size] )
  {
    if ( *m_data == *val )
    {
      v5 = &this->m_data[this->m_size - 1];
      if ( m_data < v5 )
        blkmov(a1: m_data, a2: m_data + 1, a3: 4 * (((unsigned int)((char *)v5 - (char *)m_data - 1) >> 2) + 1));
      --this->m_size;
    }
    else
    {
      ++m_data;
    }
  }
}


// ========================================================================
// ?expand_cap@?$Array@VNavWedge@bfx@@@bfx@@AAAXH@Z
// EA  : 0x8329E9F8
// RVA : 0x0129E9F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::NavWedge>::expand_cap(bfx::Array<bfx::ReplayLogListenerEntry> *this, int size)
{
  int v4; // r3
  bfx::ReplayLogListenerEntry *v5; // r30
  int v6; // r9
  int v7; // r10
  bfx::ReplayListener **v8; // r11
  bfx::ReplayLogListenerEntry *v9; // r7

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8 * size, tag: this->m_tag);
  v5 = (bfx::ReplayLogListenerEntry *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = (bfx::ReplayListener **)v4;
    do
    {
      if ( v8 != nullptr )
      {
        v9 = &this->m_data[v7];
        *v8 = v9->m_pListener;
        v8[1] = *(bfx::ReplayListener **)&v9->m_clientOwned;
      }
      ++v6;
      ++v7;
      v8 += 2;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$Array@V?$Pair@IPAVVolumeGraph@bfx@@@bfx@@@bfx@@QAAXABV?$Pair@IPAVVolumeGraph@bfx@@@2@@Z
// EA  : 0x8329EBD8
// RVA : 0x0129EBD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
        bfx::Array<bfx::ReplayLogListenerEntry> *this,
        const bfx::ReplayLogListenerEntry *val)
{
  int m_cap; // r11
  int m_size; // r10
  bfx::ReplayLogListenerEntry v5; // r30
  int v6; // r4
  bfx::ReplayLogListenerEntry *v7; // r11

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = *val;
    v6 = 2 * m_cap;
    if ( m_cap == 0 )
      v6 = 1;
    bfx::Array<bfx::NavWedge>::expand_cap(this, size: v6);
    if ( &this->m_data[this->m_size] != nullptr )
      this->m_data[this->m_size] = v5;
  }
  else
  {
    v7 = &this->m_data[m_size];
    if ( v7 != nullptr )
      *v7 = *val;
  }
  ++this->m_size;
}


// ========================================================================
// ?expand_cap@?$Array@VPortalSubdivElem@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832A1F50
// RVA : 0x012A1F50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::PortalSubdivElem>::expand_cap(
        bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> *this,
        int size)
{
  int v4; // r3
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v5; // r29
  int v6; // r6
  int v7; // r7
  int v8; // r8
  _DWORD *v9; // r9
  float *p_m_priority; // r10
  int i; // ctr

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 24 * size, tag: this->m_tag);
  v5 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != 0 )
      {
        v9 = (_DWORD *)(v8 - 4);
        p_m_priority = &this->m_data[v7 - 1].m_priority;
        for ( i = 6; i != 0; --i )
          *++v9 = *(_DWORD *)++p_m_priority;
      }
      ++v6;
      ++v7;
      v8 += 24;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?push_back@?$Array@VBox@bfx@@@bfx@@QAAXABVBox@2@@Z
// EA  : 0x832A2090
// RVA : 0x012A2090
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Box>::push_back(
        bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> *this,
        const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *val)
{
  int m_cap; // r8
  int m_size; // r11
  char *v5; // r10
  const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v6; // r11
  int i; // ctr
  int v8; // r4
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v9; // r11
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v10; // r10
  const bfx::Portal **v11; // r11
  int j; // ctr
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v13; // r11
  const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v14; // r10
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v15; // r11
  int k; // ctr
  char v17; // [sp+4Ch] [-34h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v5 = &v17;
    v6 = (const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)val - 4);
    for ( i = 6; i != 0; --i )
    {
      v6 = (const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v6 + 4);
      v5 += 4;
      *(_DWORD *)v5 = v6->m_elem.m_pPortal;
    }
    v8 = 2 * m_cap;
    if ( m_cap == 0 )
      v8 = 1;
    bfx::Array<bfx::PortalSubdivElem>::expand_cap(this, size: v8);
    v9 = &this->m_data[this->m_size];
    if ( v9 != nullptr )
    {
      v10 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v9 - 4);
      v11 = (const bfx::Portal **)&v17;
      for ( j = 6; j != 0; --j )
      {
        ++v11;
        v10 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v10 + 4);
        v10->m_elem.m_pPortal = *v11;
      }
    }
  }
  else
  {
    v13 = &this->m_data[m_size];
    if ( v13 != nullptr )
    {
      v14 = (const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)val - 4);
      v15 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v13 - 4);
      for ( k = 6; k != 0; --k )
      {
        v14 = (const bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v14 + 4);
        v15 = (bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *)((char *)v15 + 4);
        v15->m_elem.m_pPortal = v14->m_elem.m_pPortal;
      }
    }
  }
  ++this->m_size;
}


// ========================================================================
// ?reverse@?$Array@UPath3DPoint@bfx@@@bfx@@QAAXXZ
// EA  : 0x832A23D8
// RVA : 0x012A23D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::Path3DPoint>::reverse(bfx::Array<bfx::Path3DPoint> *this)
{
  int v1; // r27

  v1 = (this->m_size - 2) / 2;
  if ( v1 >= 0 )
  {
    if ( v1 + 1 >= 4 )
    {
      while ( 1 )
        ;
    }
    while ( 1 )
      ;
  }
}


// ========================================================================
// ??0?$List@UObstacleRequestData@MoverSpaceComponent@bfx@@@bfx@@QAA@IW4bfxMemTag@1@@Z
// EA  : 0x832A36A8
// RVA : 0x012A36A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::List<bfx::SolverPair> *__fastcall bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::List<bfx::MoverSpaceComponent::ObstacleRequestData>(
        bfx::List<bfx::SolverPair> *this,
        unsigned int numNodesPerPoolBlock,
        bfx::bfxMemTag memTag)
{
  bfx::AutoPtr<bfx::Pool> *p_m_poolAutoPtr; // r29
  bfx::Pool *v7; // r3
  bfx::Pool *v8; // r3
  bfx::List<bfx::SolverPair>::Node *Node; // r3

  p_m_poolAutoPtr = &this->m_poolAutoPtr;
  this->m_pPool = nullptr;
  this->m_poolAutoPtr.m_data = nullptr;
  this->m_pEnd = nullptr;
  v7 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v7 != nullptr )
    v8 = bfx::Pool::Pool(this: v7, nodeSize: 0x58u, numNodes: numNodesPerPoolBlock, tag: memTag);
  else
    v8 = nullptr;
  this->m_pPool = v8;
  p_m_poolAutoPtr->m_data = v8;
  Node = (bfx::List<bfx::SolverPair>::Node *)bfx::Pool::GetNode(this: this->m_pPool);
  this->m_pEnd = Node;
  Node->m_pNext = Node;
  this->m_pEnd->m_pPrev = this->m_pEnd;
  return this;
}


// ========================================================================
// __unwind$20441
// EA  : 0x832A374C
// RVA : 0x012A374C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_20441()
{
  int v0; // r12

  bfx::AutoPtr<bfx::Pool>::~AutoPtr<bfx::Pool>(this: (bfx::AutoPtr<bfx::Pool> *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// __unwind$20442
// EA  : 0x832A3778
// RVA : 0x012A3778
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_20442()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1?$List@UObstacleRequestData@MoverSpaceComponent@bfx@@@bfx@@QAA@XZ
// EA  : 0x832A37A8
// RVA : 0x012A37A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::~List<bfx::MoverSpaceComponent::ObstacleRequestData>(
        bfx::List<bfx::SolverPair> *this)
{
  bfx::List<bfx::SolverPair>::Node *m_pEnd; // r11
  bfx::Pool *m_pPool; // r9
  bfx::List<bfx::SolverPair>::Node *m_pNext; // r10
  char *m_data; // r31

  if ( this->m_poolAutoPtr.m_data == nullptr )
  {
    this->m_pEnd->m_pPrev->m_pNext = nullptr;
    m_pEnd = this->m_pEnd;
    if ( m_pEnd != nullptr )
    {
      do
      {
        m_pPool = this->m_pPool;
        m_pNext = m_pEnd->m_pNext;
        m_pEnd->m_val.m_entityA.m_pRepulsor = (bfx::RepulsorImpl *)this->m_pPool->m_data.m_pUnused;
        m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pEnd;
        m_pEnd = m_pNext;
      }
      while ( m_pNext != nullptr );
    }
  }
  m_data = (char *)this->m_poolAutoPtr.m_data;
  if ( m_data != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_poolAutoPtr.m_data);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// ?GetData@?$SmallestN@PAVArea@bfx@@@bfx@@QAAXAAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x832A3840
// RVA : 0x012A3840
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::SmallestN<bfx::Area *>::GetData(
        bfx::SmallestN<bfx::Volume *> *this,
        bfx::Array<bfx::SpaceComponent *> *dataOut)
{
  int m_cap; // r11
  int m_size; // r4
  int v6; // r30
  int v7; // r31

  m_cap = dataOut->m_cap;
  m_size = this->m_data.m_size;
  if ( m_size > m_cap )
    bfx::Array<bfx::Edge *>::expand_cap(this: dataOut, size: m_size);
  v6 = 0;
  if ( this->m_data.m_size > 0 )
  {
    v7 = 0;
    do
    {
      bfx::Array<bfx::Portal *>::push_back(
        this: (bfx::Array<bfx::Space *> *)dataOut,
        val: (bfx::Space **)&this->m_data.m_data[v7]);
      ++v6;
      ++v7;
    }
    while ( v6 < this->m_data.m_size );
  }
}


// ========================================================================
// ??0?$Array@PAVRepulsorImpl@bfx@@@bfx@@QAA@ABV01@@Z
// EA  : 0x832B3C80
// RVA : 0x012B3C80
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Array<bfx::Area *> *__fastcall bfx::Array<bfx::RepulsorImpl *>::Array<bfx::RepulsorImpl *>(
        bfx::Array<bfx::Area *> *this,
        const bfx::Array<bfx::Area *> *rhs)
{
  int v2; // r31
  int m_size; // r4
  int i; // r30

  v2 = 0;
  this->m_data = nullptr;
  this->m_size = 0;
  this->m_cap = 0;
  this->m_tag = rhs->m_tag;
  m_size = rhs->m_size;
  if ( m_size > 0 )
    bfx::Array<bfx::Edge *>::expand_cap((bfx::Array<bfx::SpaceComponent *> *)this, size: m_size);
  for ( i = 0; i < rhs->m_size; ++v2 )
  {
    bfx::Array<bfx::Portal *>::push_back((bfx::Array<bfx::Space *> *)this, val: (bfx::Space **)&rhs->m_data[v2]);
    ++i;
  }
  return this;
}


// ========================================================================
// ??4?$Handle@VMoverImpl@bfx@@@bfx@@QAAAAV01@PAVMoverImpl@1@@Z
// EA  : 0x832B3D08
// RVA : 0x012B3D08
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Handle<bfx::LinkBase> *__fastcall bfx::Handle<bfx::MoverImpl>::operator=(
        bfx::Handle<bfx::LinkBase> *this,
        bfx::LinkBase *pTarget)
{
  bfx::HandleProxy *m_pProxy; // r3
  int v6; // r3
  bfx::HandleProxy *v7; // r30
  char v8; // r11
  bfx::HandleProxy *v9; // [sp+50h] [-30h]

  m_pProxy = this->m_pProxy;
  if ( m_pProxy != nullptr )
  {
    if ( m_pProxy->m_pTarget == pTarget )
      return this;
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  if ( pTarget != nullptr )
  {
    v9 = pTarget->m_pProxy;
    if ( v9 != nullptr )
    {
      this->m_pProxy = v9;
    }
    else
    {
      v6 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8u, tag: bfx::MEM_BFXSYSTEM);
      v7 = (bfx::HandleProxy *)v6;
      if ( v6 != 0 )
      {
        v8 = *(_BYTE *)(v6 + 7);
        *(_DWORD *)v6 = 0;
        *(_DWORD *)(v6 + 4) = v8 & 3;
        bfx::HandleProxy::ConnectToTarget(this: (bfx::HandleProxy *)v6, pTarget);
      }
      else
      {
        v7 = nullptr;
      }
      this->m_pProxy = v7;
    }
    *((_DWORD *)this->m_pProxy + 1) = (unsigned __int8)*((_DWORD *)this->m_pProxy + 1)
                                    | ((*((_DWORD *)this->m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  }
  else
  {
    this->m_pProxy = nullptr;
  }
  return this;
}


// ========================================================================
// __unwind$101951
// EA  : 0x832B3DF0
// RVA : 0x012B3DF0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_101951()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?expand_cap@?$Array@VDatabaseRecord@FollowerLeaderDatabase@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832B4BD8
// RVA : 0x012B4BD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::expand_cap(
        bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord> *this,
        int size)
{
  int v4; // r3
  bfx::FollowerLeaderDatabase::DatabaseRecord *v5; // r24
  int v6; // r26
  int v7; // r31
  int v8; // r27
  char *v9; // r10
  int v10; // r11
  bool v11; // cr58
  bfx::FollowerLeaderDatabase::DatabaseRecord *m_data; // r28
  bfx::HandleProxy *v13; // r3

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 24 * size, tag: this->m_tag);
  v5 = (bfx::FollowerLeaderDatabase::DatabaseRecord *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = v4 + 16;
    v8 = -16 - v4;
    do
    {
      if ( v7 != 16 )
      {
        v9 = (char *)this->m_data + v8 + v7;
        v10 = *(_DWORD *)v9;
        v11 = *(_DWORD *)v9 == 0;
        *(_DWORD *)(v7 - 16) = *(_DWORD *)v9;
        if ( !v11 )
          *(_DWORD *)(v10 + 4) = (unsigned __int8)*(_DWORD *)(v10 + 4)
                               | ((*(_DWORD *)(v10 + 4) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
        *(_DWORD *)(v7 - 12) = *((_DWORD *)v9 + 1);
        *(_DWORD *)(v7 - 8) = *((_DWORD *)v9 + 2);
        *(_DWORD *)(v7 - 4) = *((_DWORD *)v9 + 3);
        *(_DWORD *)v7 = *((_DWORD *)v9 + 4);
        *(float *)(v7 + 4) = *((float *)v9 + 5);
      }
      m_data = this->m_data;
      v13 = *(bfx::HandleProxy **)((char *)&this->m_data->m_mover.m_pProxy + v8 + v7);
      if ( v13 != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v13);
        *(bfx::HandleProxy **)((char *)&m_data->m_mover.m_pProxy + v8 + v7) = nullptr;
      }
      ++v6;
      v7 += 24;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?shrink@?$Array@VDatabaseRecord@FollowerLeaderDatabase@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832B4CE0
// RVA : 0x012B4CE0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::shrink(
        bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord> *this,
        int size)
{
  int v4; // r11
  int v5; // r29
  int v6; // r31
  bfx::FollowerLeaderDatabase::DatabaseRecord *m_data; // r30
  bfx::HandleProxy *m_pProxy; // r3

  v4 = this->m_size - 1;
  if ( v4 >= size )
  {
    v5 = this->m_size - size;
    v6 = v4;
    do
    {
      m_data = this->m_data;
      m_pProxy = this->m_data[v6].m_mover.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
        m_data[v6].m_mover.m_pProxy = nullptr;
      }
      --v5;
      --v6;
    }
    while ( v5 != 0 );
  }
  this->m_size = size;
}


// ========================================================================
// ??1?$Array@VDatabaseRecord@FollowerLeaderDatabase@bfx@@@bfx@@QAA@XZ
// EA  : 0x832B4D50
// RVA : 0x012B4D50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::~Array<bfx::FollowerLeaderDatabase::DatabaseRecord>(
        bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord> *this)
{
  bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VDatabaseRecord@FollowerLeaderDatabase@bfx@@@bfx@@QAAXABVDatabaseRecord@FollowerLeaderDatabase@2@@Z
// EA  : 0x832B4DB8
// RVA : 0x012B4DB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::push_back(
        bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord> *this,
        const bfx::FollowerLeaderDatabase::DatabaseRecord *val)
{
  int m_size; // r11
  bfx::HandleProxy *m_pProxy; // r25
  bfx::FollowerLeaderDatabase::FollowerStates m_state; // r29
  double m_countDown; // fp31
  float m_x; // r28
  float m_y; // r27
  float m_z; // r26
  int m_cap; // r11
  int v11; // r4
  bfx::FollowerLeaderDatabase::DatabaseRecord *v12; // r11
  bfx::FollowerLeaderDatabase::DatabaseRecord *v13; // r11
  bfx::HandleProxy *v14; // r10
  bool v15; // cr58

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_pProxy = val->m_mover.m_pProxy;
    if ( val->m_mover.m_pProxy != nullptr )
      *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    m_state = val->m_state;
    m_countDown = val->m_countDown;
    m_x = val->m_pos.m_x;
    m_y = val->m_pos.m_y;
    m_z = val->m_pos.m_z;
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v11 = 2 * m_cap;
    else
      v11 = 1;
    bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::expand_cap(this, size: v11);
    v12 = &this->m_data[this->m_size];
    if ( v12 != nullptr )
    {
      v12->m_mover.m_pProxy = m_pProxy;
      if ( m_pProxy != nullptr )
        *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                  | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      v12->m_countDown = m_countDown;
      v12->m_state = m_state;
      v12->m_pos.m_x = m_x;
      v12->m_pos.m_y = m_y;
      v12->m_pos.m_z = m_z;
    }
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    v13 = &this->m_data[m_size];
    if ( v13 != nullptr )
    {
      v14 = val->m_mover.m_pProxy;
      v15 = val->m_mover.m_pProxy == nullptr;
      v13->m_mover.m_pProxy = val->m_mover.m_pProxy;
      if ( !v15 )
        *((_DWORD *)v14 + 1) = (unsigned __int8)*((_DWORD *)v14 + 1)
                             | ((*((_DWORD *)v14 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      v13->m_pos = val->m_pos;
      v13->m_state = val->m_state;
      v13->m_countDown = val->m_countDown;
    }
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$32569
// EA  : 0x832B4F34
// RVA : 0x012B4F34
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_32569()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 192 + 96));
}


// ========================================================================
// ?erase@?$Array@VDatabaseRecord@FollowerLeaderDatabase@bfx@@@bfx@@QAAXPAVDatabaseRecord@FollowerLeaderDatabase@2@@Z
// EA  : 0x832B4F60
// RVA : 0x012B4F60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::erase(
        bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord> *this,
        bfx::FollowerLeaderDatabase::DatabaseRecord *ptr)
{
  bfx::FollowerLeaderDatabase::DatabaseRecord *v3; // r30
  bfx::FollowerLeaderDatabase::DatabaseRecord *v4; // r29
  char *p_m_z; // r31
  int v6; // r11

  v3 = ptr;
  v4 = &this->m_data[this->m_size - 1];
  if ( ptr < v4 )
  {
    p_m_z = (char *)&ptr[1].m_pos.m_z;
    do
    {
      if ( p_m_z - 12 != (char *)v3 )
      {
        if ( v3->m_mover.m_pProxy != nullptr )
          bfx::HandleProxy::RemRefToHandleProxy(this: v3->m_mover.m_pProxy);
        v6 = *((_DWORD *)p_m_z - 3);
        v3->m_mover.m_pProxy = (bfx::HandleProxy *)v6;
        if ( v6 != 0 )
          *(_DWORD *)(v6 + 4) = (unsigned __int8)*(_DWORD *)(v6 + 4)
                              | ((*(_DWORD *)(v6 + 4) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      }
      ++v3;
      *((float *)p_m_z - 8) = *((float *)p_m_z - 2);
      *((float *)p_m_z - 7) = *((float *)p_m_z - 1);
      *((float *)p_m_z - 6) = *(float *)p_m_z;
      *((_DWORD *)p_m_z - 5) = *((_DWORD *)p_m_z + 1);
      *((float *)p_m_z - 4) = *((float *)p_m_z + 2);
      p_m_z += 24;
    }
    while ( v3 < v4 );
  }
  if ( v3->m_mover.m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: v3->m_mover.m_pProxy);
    v3->m_mover.m_pProxy = nullptr;
  }
  --this->m_size;
}


// ========================================================================
// ??4?$Array@VSmartPathCorner@bfx@@@bfx@@QAAXABV01@@Z
// EA  : 0x832B8E48
// RVA : 0x012B8E48
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::SmartPathCorner>::operator=(
        bfx::Array<bfx::SmartPathCorner> *this,
        const bfx::Array<bfx::SmartPathCorner> *rhs)
{
  char *m_data; // r4
  int m_size; // r9
  int v6; // r7
  int v7; // r8
  bfx::Area **p_m_pArea; // r9
  bfx::Area **v9; // r10
  int i; // ctr

  if ( rhs != this )
  {
    m_data = (char *)this->m_data;
    this->m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_data = (bfx::SmartPathCorner *)bfx::MemoryManager::Malloc(
                                             this: bfx::g_pCurInstance->m_pMemoryManager,
                                             size: 28 * rhs->m_size,
                                             tag: this->m_tag);
    m_size = rhs->m_size;
    this->m_size = m_size;
    this->m_cap = m_size;
    v6 = 0;
    if ( m_size > 0 )
    {
      v7 = 0;
      do
      {
        if ( &this->m_data[v7] != nullptr )
        {
          p_m_pArea = &this->m_data[v7 - 1].m_pArea;
          v9 = &rhs->m_data[v7 - 1].m_pArea;
          for ( i = 7; i != 0; --i )
            *++p_m_pArea = *++v9;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_size );
    }
  }
}


// ========================================================================
// ?expand_cap@?$Array@URVODebugDrawInfo@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832BE470
// RVA : 0x012BE470
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RVODebugDrawInfo>::expand_cap(bfx::Array<bfx::RVODebugDrawInfo> *this, int size)
{
  int v4; // r3
  bfx::RVODebugDrawInfo *v5; // r27
  int v6; // r28
  int v7; // r29
  char *v8; // r30

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 116 * size, tag: this->m_tag);
  v5 = (bfx::RVODebugDrawInfo *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = (char *)v4;
    do
    {
      if ( v8 != nullptr )
        memcpy(Dst: v8, Src: &this->m_data[v7], Size: 0x74u);
      ++v6;
      ++v7;
      v8 += 116;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?expand_cap@?$Array@UHedgehogDebugDrawInfo@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832BE510
// RVA : 0x012BE510
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HedgehogDebugDrawInfo>::expand_cap(
        bfx::Array<bfx::HedgehogDebugDrawInfo> *this,
        int size)
{
  int v4; // r3
  bfx::HedgehogDebugDrawInfo *v5; // r26
  int v6; // r28
  int v7; // r29
  char *v8; // r30

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 48 * size, tag: this->m_tag);
  v5 = (bfx::HedgehogDebugDrawInfo *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = (char *)v4;
    do
    {
      if ( v8 != nullptr )
        memcpy(Dst: v8, Src: &this->m_data[v7], Size: 0x30u);
      ++v6;
      ++v7;
      v8 += 48;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ?erase_section@?$Array@VRVOWedge@bfx@@@bfx@@QAAXHH@Z
// EA  : 0x832BE5B8
// RVA : 0x012BE5B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RVOWedge>::erase_section(
        bfx::Array<bfx::RVOWedge> *this,
        int sectionStartIndex,
        int sectionEndIndex)
{
  int v3; // r9
  int v4; // r7
  int v5; // r11
  int v6; // r10
  bfx::RVOWedge *v7; // r6
  bfx::RVOWedge *v8; // r5

  v3 = sectionStartIndex;
  v4 = sectionEndIndex - sectionStartIndex + 1;
  if ( sectionStartIndex < this->m_size - v4 )
  {
    v5 = sectionStartIndex;
    v6 = sectionEndIndex + 1;
    do
    {
      ++v3;
      v7 = &this->m_data[v6];
      v8 = &this->m_data[v5++];
      ++v6;
      v8->m_leftAngle = v7->m_leftAngle;
      v8->m_rightAngle = v7->m_rightAngle;
    }
    while ( v3 < this->m_size - v4 );
  }
  this->m_size -= v4;
}


// ========================================================================
// ??4?$Array@VRVOWedge@bfx@@@bfx@@QAAXABV01@@Z
// EA  : 0x832BE628
// RVA : 0x012BE628
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RVOWedge>::operator=(
        bfx::Array<bfx::RVOWedge> *this,
        const bfx::Array<bfx::RVOWedge> *rhs)
{
  char *m_data; // r4
  int m_size; // r7
  int v6; // r8
  int v7; // r10
  bfx::RVOWedge *v8; // r11
  bfx::RVOWedge *v9; // r7

  if ( rhs != this )
  {
    m_data = (char *)this->m_data;
    this->m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_data = (bfx::RVOWedge *)bfx::MemoryManager::Malloc(
                                      this: bfx::g_pCurInstance->m_pMemoryManager,
                                      size: 8 * rhs->m_size,
                                      tag: this->m_tag);
    m_size = rhs->m_size;
    v6 = 0;
    this->m_size = m_size;
    this->m_cap = m_size;
    if ( m_size > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &this->m_data[v7];
        if ( v8 != nullptr )
        {
          v9 = &rhs->m_data[v7];
          v8->m_leftAngle = v9->m_leftAngle;
          v8->m_rightAngle = v9->m_rightAngle;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_size );
    }
  }
}


// ========================================================================
// ?insert@?$Array@VRVOWedge@bfx@@@bfx@@QAA?AViterator@12@ABV312@ABVRVOWedge@2@@Z
// EA  : 0x832BE6E0
// RVA : 0x012BE6E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::Array<bfx::RVOWedge> *__fastcall bfx::Array<bfx::RVOWedge>::insert(
        bfx::Array<bfx::RVOWedge> *this,
        bfx::Array<bfx::ReplayLogListenerEntry> *result,
        const bfx::Array<bfx::RVOWedge>::iterator *iter,
        const bfx::RVOWedge *val)
{
  int m_cap; // r11
  int m_size; // r10
  bfx::RVOWedge *m_data; // r9
  bfx::RVOWedge v9; // r29
  int v10; // r4
  int v11; // r30
  bfx::RVOWedge *v12; // r9
  bfx::RVOWedge *v13; // r10
  bfx::RVOWedge *v14; // r11
  bfx::RVOWedge *v15; // r9
  bfx::RVOWedge *v16; // r11
  bfx::RVOWedge *v17; // r11
  _QWORD *p_m_leftAngle; // r10

  m_cap = result->m_cap;
  m_size = result->m_size;
  m_data = (bfx::RVOWedge *)result->m_data;
  if ( m_cap == m_size )
  {
    v9 = *val;
    v10 = 2 * m_cap;
    v11 = iter->m_ptr - m_data;
    if ( m_cap == 0 )
      v10 = 1;
    bfx::Array<bfx::NavWedge>::expand_cap(this: result, size: v10);
    v12 = (bfx::RVOWedge *)(8 * result->m_size);
    v13 = (bfx::RVOWedge *)&result->m_data[v11];
    v14 = (bfx::RVOWedge *)((char *)v12 + (unsigned int)result->m_data);
    if ( v14 != v13 )
    {
      v15 = (bfx::RVOWedge *)((char *)v12 + (unsigned int)result->m_data);
      do
        *v14-- = *--v15;
      while ( v14 != v13 );
    }
    if ( v13 != nullptr )
      *v13 = v9;
    v16 = (bfx::RVOWedge *)result->m_size;
    *(_DWORD *)LODWORD(v9.m_leftAngle) = v13;
    result->m_size = (int)&v16->m_leftAngle + 1;
    return (bfx::Array<bfx::RVOWedge> *)LODWORD(v9.m_leftAngle);
  }
  else
  {
    v17 = &m_data[m_size];
    if ( v17 != iter->m_ptr )
    {
      p_m_leftAngle = (_QWORD *)&m_data[m_size].m_leftAngle;
      do
        *v17-- = *(bfx::RVOWedge *)--p_m_leftAngle;
      while ( v17 != iter->m_ptr );
    }
    ++result->m_size;
    if ( iter->m_ptr != nullptr )
      *iter->m_ptr = *val;
    this->m_data = iter->m_ptr;
  }
  return this;
}


// ========================================================================
// ?push_back@?$Array@URVODebugDrawInfo@bfx@@@bfx@@QAAXABURVODebugDrawInfo@2@@Z
// EA  : 0x832BE800
// RVA : 0x012BE800
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RVODebugDrawInfo>::push_back(
        bfx::Array<bfx::RVODebugDrawInfo> *this,
        const bfx::RVODebugDrawInfo *val)
{
  int m_cap; // r30
  int m_size; // r11
  int v5; // r4
  bfx::RVODebugDrawInfo *v6; // r3
  int v7; // r11
  bfx::RVODebugDrawInfo v8; // [sp+50h] [-90h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v8 = *val;
    v5 = 2 * m_cap;
    if ( m_cap == 0 )
      v5 = 1;
    bfx::Array<bfx::RVODebugDrawInfo>::expand_cap(this, size: v5);
    v6 = &this->m_data[this->m_size];
    if ( v6 != nullptr )
    {
      val = &v8;
LABEL_7:
      memcpy(Dst: v6, Src: val, Size: sizeof(bfx::RVODebugDrawInfo));
    }
  }
  else
  {
    v7 = m_size;
    v6 = &this->m_data[v7];
    if ( &this->m_data[v7] != nullptr )
      goto LABEL_7;
  }
  ++this->m_size;
}


// ========================================================================
// ?push_back@?$Array@UHedgehogDebugDrawInfo@bfx@@@bfx@@QAAXABUHedgehogDebugDrawInfo@2@@Z
// EA  : 0x832BE8A8
// RVA : 0x012BE8A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HedgehogDebugDrawInfo>::push_back(
        bfx::Array<bfx::HedgehogDebugDrawInfo> *this,
        const bfx::HedgehogDebugDrawInfo *val)
{
  int m_cap; // r30
  int m_size; // r11
  int v5; // r4
  bfx::HedgehogDebugDrawInfo *v6; // r3
  int v7; // r11
  bfx::HedgehogDebugDrawInfo v8; // [sp+50h] [-50h] BYREF

  m_cap = this->m_cap;
  m_size = this->m_size;
  if ( m_cap == m_size )
  {
    v8 = *val;
    v5 = 2 * m_cap;
    if ( m_cap == 0 )
      v5 = 1;
    bfx::Array<bfx::HedgehogDebugDrawInfo>::expand_cap(this, size: v5);
    v6 = &this->m_data[this->m_size];
    if ( v6 != nullptr )
    {
      val = &v8;
LABEL_7:
      memcpy(Dst: v6, Src: val, Size: sizeof(bfx::HedgehogDebugDrawInfo));
    }
  }
  else
  {
    v7 = m_size;
    v6 = &this->m_data[v7];
    if ( &this->m_data[v7] != nullptr )
      goto LABEL_7;
  }
  ++this->m_size;
}


// ========================================================================
// ??0?$FArray@VPlane@bfx@@$0M@@bfx@@QAA@ABV01@@Z
// EA  : 0x832C44E0
// RVA : 0x012C44E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::FArray<bfx::Plane,12> *__fastcall bfx::FArray<bfx::Plane,12>::FArray<bfx::Plane,12>(
        bfx::FArray<bfx::Plane,12> *this,
        const bfx::FArray<bfx::Plane,12> *rhs)
{
  int m_size; // r9
  bfx::FArray<bfx::Plane,12> *v3; // r11
  bfx::FArray<bfx::Plane,12> *v4; // r10
  int v5; // r9
  unsigned int v6; // r10

  m_size = rhs->m_size;
  v3 = this;
  v4 = (bfx::FArray<bfx::Plane,12> *)((char *)this + 16 * m_size);
  this->m_size = m_size;
  if ( this < v4 )
  {
    v5 = (char *)rhs - (char *)this;
    v6 = ((unsigned int)((char *)v4 - (char *)this - 1) >> 4) + 1;
    do
    {
      if ( v3 != nullptr )
      {
        v3->m_data[0].m_normal.m_x = *(float *)((char *)&v3->m_data[0].m_normal.m_x + v5);
        v3->m_data[0].m_normal.m_y = *(float *)((char *)&v3->m_data[0].m_normal.m_y + v5);
        v3->m_data[0].m_normal.m_z = *(float *)((char *)&v3->m_data[0].m_normal.m_z + v5);
        v3->m_data[0].m_d = *(float *)((char *)&v3->m_data[0].m_d + v5);
      }
      --v6;
      v3 = (bfx::FArray<bfx::Plane,12> *)((char *)v3 + 16);
    }
    while ( v6 != 0 );
  }
  return this;
}


// ========================================================================
// ?clear@?$Array@VHoleRecord@bfx@@@bfx@@QAAXXZ
// EA  : 0x832C4550
// RVA : 0x012C4550
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::HoleRecord>::clear(bfx::Array<bfx::QueuedTri> *this)
{
  char *m_data; // r4

  m_data = (char *)this->m_data;
  this->m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  this->m_data = nullptr;
  this->m_cap = 0;
}


// ========================================================================
// ?GetLargest@?$SmallestN@PAVXNode@bfx@@@bfx@@AAAPAV?$MetricOb@PAVXNode@bfx@@@2@XZ
// EA  : 0x832C7AF8
// RVA : 0x012C7AF8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

bfx::MetricOb<bfx::Volume *> *__fastcall bfx::SmallestN<bfx::XNode *>::GetLargest(bfx::SmallestN<bfx::Volume *> *this)
{
  bfx::MetricOb<bfx::Volume *> *v1; // r10
  bfx::MetricOb<bfx::Volume *> *v2; // r8
  bfx::MetricOb<bfx::Volume *> *result; // r3

  v1 = this->m_data.m_data + 1;
  v2 = &this->m_data.m_data[this->m_data.m_size];
  for ( result = this->m_data.m_data; v1 != v2; ++v1 )
  {
    if ( v1->m_metric > (double)result->m_metric )
      result = v1;
  }
  return result;
}


// ========================================================================
// ?expand_cap@?$Array@VRepulsorOverlap@bfx@@@bfx@@AAAXH@Z
// EA  : 0x832D8290
// RVA : 0x012D8290
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RepulsorOverlap>::expand_cap(bfx::Array<bfx::RepulsorOverlap> *this, int size)
{
  int v4; // r3
  bfx::RepulsorOverlap *v5; // r26
  int v6; // r27
  int v7; // r30
  int v8; // r28
  bfx::RepulsorOverlap *v9; // r10
  bfx::HandleProxy *m_pProxy; // r11
  bool v11; // cr58
  bfx::RepulsorOverlap *m_data; // r29
  bfx::HandleProxy *v13; // r3

  v4 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 8 * size, tag: this->m_tag);
  v5 = (bfx::RepulsorOverlap *)v4;
  v6 = 0;
  if ( this->m_size > 0 )
  {
    v7 = 0;
    v8 = v4;
    do
    {
      if ( v8 != 0 )
      {
        v9 = &this->m_data[v7];
        m_pProxy = v9->m_theirRepulsor.m_pProxy;
        v11 = v9->m_theirRepulsor.m_pProxy == nullptr;
        *(_DWORD *)v8 = v9->m_theirRepulsor.m_pProxy;
        if ( !v11 )
          *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                    | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
        *(float *)(v8 + 4) = v9->m_overlapDist;
      }
      m_data = this->m_data;
      v13 = this->m_data[v7].m_theirRepulsor.m_pProxy;
      if ( v13 != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v13);
        m_data[v7].m_theirRepulsor.m_pProxy = nullptr;
      }
      ++v6;
      ++v7;
      v8 += 8;
    }
    while ( v6 < this->m_size );
  }
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
  this->m_data = v5;
  this->m_cap = size;
}


// ========================================================================
// ??1?$Array@VLinkConnectionData@bfx@@@bfx@@QAA@XZ
// EA  : 0x832D8368
// RVA : 0x012D8368
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(
        bfx::Array<bfx::LinkConnectionData> *this)
{
  bfx::Array<bfx::LinkConnectionData>::shrink(this, size: 0);
  if ( this->m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_data);
    this->m_data = nullptr;
  }
  this->m_cap = 0;
}


// ========================================================================
// ?push_back@?$Array@VRepulsorOverlap@bfx@@@bfx@@QAAXABVRepulsorOverlap@2@@Z
// EA  : 0x832D83D0
// RVA : 0x012D83D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RepulsorOverlap>::push_back(
        bfx::Array<bfx::RepulsorOverlap> *this,
        const bfx::RepulsorOverlap *val)
{
  int m_size; // r11
  bfx::HandleProxy *m_pProxy; // r29
  double m_overlapDist; // fp31
  int m_cap; // r11
  int v7; // r4
  bfx::RepulsorOverlap *v8; // r11
  bfx::RepulsorOverlap *v9; // r10
  bfx::HandleProxy *v10; // r11
  bool v11; // cr58

  m_size = this->m_size;
  if ( this->m_cap == m_size )
  {
    m_pProxy = val->m_theirRepulsor.m_pProxy;
    if ( val->m_theirRepulsor.m_pProxy != nullptr )
      *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    m_overlapDist = val->m_overlapDist;
    m_cap = this->m_cap;
    if ( m_cap != 0 )
      v7 = 2 * m_cap;
    else
      v7 = 1;
    bfx::Array<bfx::RepulsorOverlap>::expand_cap(this, size: v7);
    v8 = &this->m_data[this->m_size];
    if ( v8 != nullptr )
    {
      v8->m_theirRepulsor.m_pProxy = m_pProxy;
      if ( m_pProxy != nullptr )
        *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                  | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      v8->m_overlapDist = m_overlapDist;
    }
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    v9 = &this->m_data[m_size];
    if ( v9 != nullptr )
    {
      v10 = val->m_theirRepulsor.m_pProxy;
      v11 = val->m_theirRepulsor.m_pProxy == nullptr;
      v9->m_theirRepulsor.m_pProxy = val->m_theirRepulsor.m_pProxy;
      if ( !v11 )
        *((_DWORD *)v10 + 1) = (unsigned __int8)*((_DWORD *)v10 + 1)
                             | ((*((_DWORD *)v10 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      v9->m_overlapDist = val->m_overlapDist;
    }
  }
  ++this->m_size;
}


// ========================================================================
// __unwind$29669
// EA  : 0x832D84EC
// RVA : 0x012D84EC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void _unwind_29669()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 128 + 80));
}


// ========================================================================
// ?erase@?$Array@VRepulsorOverlap@bfx@@@bfx@@QAAXPAVRepulsorOverlap@2@@Z
// EA  : 0x832D8518
// RVA : 0x012D8518
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsys.h
// ========================================================================

void __fastcall bfx::Array<bfx::RepulsorOverlap>::erase(
        bfx::Array<bfx::RepulsorOverlap> *this,
        bfx::RepulsorOverlap *ptr)
{
  bfx::RepulsorOverlap *v3; // r31
  bfx::RepulsorOverlap *v4; // r29
  bfx::RepulsorOverlap *v5; // r30
  bfx::HandleProxy *m_pProxy; // r11
  bool v7; // cr58

  v3 = ptr;
  v4 = &this->m_data[this->m_size - 1];
  if ( ptr < v4 )
  {
    do
    {
      v5 = v3 + 1;
      if ( v3->m_theirRepulsor.m_pProxy != nullptr )
        bfx::HandleProxy::RemRefToHandleProxy(this: v3->m_theirRepulsor.m_pProxy);
      m_pProxy = v5->m_theirRepulsor.m_pProxy;
      v7 = v5->m_theirRepulsor.m_pProxy == nullptr;
      v3->m_theirRepulsor.m_pProxy = v5->m_theirRepulsor.m_pProxy;
      if ( !v7 )
        *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                  | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      ++v3;
      v5[-1].m_overlapDist = v5->m_overlapDist;
    }
    while ( v5 < v4 );
  }
  if ( v3->m_theirRepulsor.m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: v3->m_theirRepulsor.m_pProxy);
    v3->m_theirRepulsor.m_pProxy = nullptr;
  }
  --this->m_size;
}

