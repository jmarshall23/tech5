
// ========================================================================
// ?ReserveIslandID@Island3DGraph@bfx@@AAAIXZ
// EA  : 0x8329C450
// RVA : 0x0129C450
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

unsigned int __fastcall bfx::Island3DGraph::ReserveIslandID(bfx::Island3DGraph *this)
{
  int v2; // r6
  unsigned int v3; // r9
  bfx::Island3DGraph *i; // r7
  int v5; // r10
  int v6; // r11
  unsigned int result; // r3

  v2 = 0;
  v3 = 0;
  for ( i = this; i->m_islandIDsInUse[0] == -1; i = (bfx::Island3DGraph *)((char *)i + 4) )
  {
LABEL_7:
    v3 += 32;
    ++v2;
    if ( v3 >= 0x400 )
      return 1023;
  }
  v5 = 1;
  v6 = 0;
  while ( 1 )
  {
    if ( (i->m_islandIDsInUse[0] & v5) == 0 )
    {
      result = v3 + v6;
      if ( v3 + v6 != 1023 )
        break;
    }
    ++v6;
    v5 *= 2;
    if ( v6 >= 32 )
      goto LABEL_7;
  }
  this->m_islandIDsInUse[v2] |= v5;
  return result;
}


// ========================================================================
// ??0VRT@bfx@@QAA@XZ
// EA  : 0x8329C4D0
// RVA : 0x0129C4D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

bfx::VRT *__fastcall bfx::VRT::VRT(bfx::VRT *this)
{
  memset(Dst: this, Val: 0, Size: sizeof(bfx::VRT));
  return this;
}


// ========================================================================
// ?AddConnectionPairIfNeeded@Island3D@bfx@@QAAAAVIsland3DConnection@2@PAV12@@Z
// EA  : 0x8329C5A0
// RVA : 0x0129C5A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

bfx::Space **__fastcall bfx::Island3D::AddConnectionPairIfNeeded(bfx::Island3D *this, bfx::Space *pAdjIsland)
{
  int m_size; // r8
  bfx::Array<bfx::Space *> *p_m_connections; // r31
  int v6; // r10
  bfx::Space **m_data; // r9
  int v8; // r11
  bfx::Space **result; // r3
  bfx::Space *v10[12]; // [sp+50h] [-30h] BYREF

  m_size = this->m_connections.m_size;
  p_m_connections = (bfx::Array<bfx::Space *> *)&this->m_connections;
  v6 = 0;
  if ( m_size <= 0 )
  {
LABEL_5:
    v10[0] = pAdjIsland;
    bfx::Array<bfx::Portal *>::push_back(this: p_m_connections, val: v10);
    v10[0] = (bfx::Space *)this;
    bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&pAdjIsland->m_pos, val: v10);
    return &p_m_connections->m_data[p_m_connections->m_size - 1];
  }
  else
  {
    m_data = p_m_connections->m_data;
    v8 = 0;
    while ( 1 )
    {
      result = &m_data[v8];
      if ( m_data[v8] == pAdjIsland )
        break;
      ++v6;
      ++v8;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
  }
  return result;
}


// ========================================================================
// ?RemoveConnection@Island3D@bfx@@QAAXPAV12@@Z
// EA  : 0x8329C630
// RVA : 0x0129C630
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void __fastcall bfx::Island3D::RemoveConnection(bfx::Island3D *this, bfx::Island3D *pAdjIsland)
{
  int m_size; // r9
  bfx::Array<bfx::Island3DConnection> *p_m_connections; // r31
  int v4; // r11
  bfx::Island3DConnection *m_data; // r7
  int i; // r10
  unsigned int v7; // r3
  unsigned int v8; // r11

  m_size = this->m_connections.m_size;
  p_m_connections = &this->m_connections;
  v4 = 0;
  if ( m_size > 0 )
  {
    m_data = p_m_connections->m_data;
    for ( i = 0; m_data[i].m_pAdjIsland != pAdjIsland; ++i )
    {
      if ( ++v4 >= this->m_connections.m_size )
        return;
    }
    v7 = (unsigned int)&p_m_connections->m_data[v4];
    v8 = (unsigned int)&m_data[m_size - 1];
    if ( v7 < v8 )
      blkmov(a1: v7, a2: v7 + 4, a3: 4 * (((v8 - v7 - 1) >> 2) + 1));
    --p_m_connections->m_size;
  }
}


// ========================================================================
// ?CreateIsland@Island3DArray@bfx@@QAAPAVIsland3D@2@HI@Z
// EA  : 0x8329C6F0
// RVA : 0x0129C6F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

bfx::Island3D *__fastcall bfx::Island3DArray::CreateIsland(
        bfx::Island3DArray *this,
        int islandNum,
        unsigned int userData)
{
  int m_size; // r11
  int v8; // r3
  bfx::Island3D *v9; // r10
  bfx::bfxMemTag v10; // r11
  bfx::Space *v11; // [sp+50h] [-40h] BYREF

  if ( islandNum == 1023 )
    return nullptr;
  m_size = this->m_islands.m_size;
  if ( islandNum < m_size && this->m_islands.m_data[islandNum] != nullptr )
    return nullptr;
  if ( m_size <= islandNum )
  {
    v11 = nullptr;
    do
      bfx::Array<bfx::Portal *>::push_back((bfx::Array<bfx::Space *> *)this, val: &v11);
    while ( this->m_islands.m_size <= islandNum );
  }
  v8 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x1Cu, tag: bfx::MEM_BFXPLANNER3D);
  if ( v8 != 0 )
  {
    *(_DWORD *)v8 = islandNum;
    v9 = (bfx::Island3D *)v8;
    *(_DWORD *)(v8 + 4) = userData;
    *(_BYTE *)(v8 + 8) = 0;
    v10 = bfx::MEM_BFXPLANNER3D;
    *(_DWORD *)(v8 + 12) = 0;
    *(_DWORD *)(v8 + 16) = 0;
    *(_DWORD *)(v8 + 20) = 0;
    *(_DWORD *)(v8 + 24) = v10;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_islands.m_data[islandNum] = v9;
  return this->m_islands.m_data[islandNum];
}


// ========================================================================
// ?DestroyIsland@Island3DArray@bfx@@QAAXH@Z
// EA  : 0x8329C7D0
// RVA : 0x0129C7D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void __fastcall bfx::Island3DArray::DestroyIsland(bfx::Island3DArray *this, int islandNum)
{
  int v3; // r26
  bfx::Island3D *v4; // r10
  bfx::Island3D *v5; // r28
  bfx::Array<bfx::Island3DConnection> *p_m_connections; // r31
  int v7; // r30
  int v8; // r29
  char *m_data; // r4

  if ( islandNum != 1023 && islandNum < this->m_islands.m_size )
  {
    v3 = islandNum;
    v4 = this->m_islands.m_data[islandNum];
    if ( v4 != nullptr )
    {
      v5 = this->m_islands.m_data[islandNum];
      p_m_connections = &v4->m_connections;
      v7 = 0;
      if ( v4->m_connections.m_size > 0 )
      {
        v8 = 0;
        do
        {
          bfx::Island3D::RemoveConnection(this: p_m_connections->m_data[v8].m_pAdjIsland, pAdjIsland: v5);
          ++v7;
          ++v8;
        }
        while ( v7 < p_m_connections->m_size );
      }
      if ( v5 != nullptr )
      {
        m_data = (char *)p_m_connections->m_data;
        p_m_connections->m_size = 0;
        if ( m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
          p_m_connections->m_data = nullptr;
        }
        p_m_connections->m_cap = 0;
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v5);
      }
      this->m_islands.m_data[v3] = nullptr;
    }
  }
}


// ========================================================================
// ?CreateIsland@Island3DGraph@bfx@@QAA_NPAVVolume@2@@Z
// EA  : 0x8329C8A8
// RVA : 0x0129C8A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

int __fastcall bfx::Island3DGraph::CreateIsland(
        bfx::Island3DGraph *this,
        bfx::Space *pStartVolume,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  int v19; // r3
  unsigned int v20; // r21
  __int64 v21; // r4
  bfx::Island3DArray *p_m_islandArray; // r25
  bfx::Island3D *Island; // r3
  unsigned int m_w_low; // r23
  bfx::Island3D *v26; // r20
  int m_size; // r11
  bfx::Space **v28; // r8
  int v29; // r26
  const bfx::Volume *v30; // r27
  int v31; // r28
  const bfx::Volume *OtherVolume; // r3
  unsigned int m_userData; // r10
  bfx::Space *v34; // r30
  int v35; // [sp+8h] [-D8h]
  int v36; // [sp+Ch] [-D4h]
  int v37; // [sp+10h] [-D0h]
  int v38; // [sp+14h] [-CCh]
  int m_islandID; // [sp+50h] [-90h] BYREF
  bfx::Array<bfx::Space *> v40[8]; // [sp+60h] [-80h] BYREF

  a14 = pStartVolume;
  v19 = bfx::Island3DGraph::ReserveIslandID(this);
  v20 = v19;
  if ( v19 == 1023 )
  {
    LODWORD(v21) = 1023;
    HIDWORD(v21) = "ran out of available island3ds (limit = %d)\n";
    bfx::InternalWarning(fmt: v21, a2: v18, a3: v17, a4: v16, a5: v35, a6: v36, a7: v37, a8: v38);
    return 0;
  }
  else
  {
    p_m_islandArray = &this->m_islandArray;
    Island = bfx::Island3DArray::CreateIsland(
               this: &this->m_islandArray,
               islandNum: v19,
               userData: LODWORD(pStartVolume->m_rotWorldToSpace.m_w));
    m_w_low = LODWORD(pStartVolume->m_rotWorldToSpace.m_w);
    v26 = Island;
    memset(v40, 0, 12);
    v40[0].m_tag = bfx::MEM_BFXPLANNER3D;
    LODWORD(pStartVolume->m_rotSpaceToWorld.m_z) = v20;
    bfx::Array<bfx::Portal *>::push_back(this: v40, val: &a14);
    m_size = v40[0].m_size;
    while ( m_size != 0 )
    {
      v28 = &v40[0].m_data[m_size--];
      v40[0].m_size = m_size;
      v29 = 0;
      v30 = (const bfx::Volume *)*(v28 - 1);
      if ( v30->m_portals.m_size > 0 )
      {
        v31 = 0;
        do
        {
          OtherVolume = bfx::Portal::GetOtherVolume(this: v30->m_portals.m_data[v31].m_pPortal, vol: v30);
          m_userData = OtherVolume->m_userData;
          m_islandID = (int)OtherVolume;
          if ( m_userData == m_w_low && OtherVolume->m_pParentGraph == (bfx::VolumeGraph *)pStartVolume->m_spaceID )
          {
            if ( OtherVolume->m_islandID == 1023 )
            {
              OtherVolume->m_islandID = v20;
              bfx::Array<bfx::Portal *>::push_back(this: v40, val: (bfx::Space **)&m_islandID);
            }
          }
          else
          {
            m_islandID = OtherVolume->m_islandID;
            if ( m_islandID != 1023 )
            {
              if ( m_islandID >= p_m_islandArray->m_islands.m_size )
                v34 = nullptr;
              else
                v34 = (bfx::Space *)p_m_islandArray->m_islands.m_data[m_islandID];
              bfx::Island3D::AddConnectionPairIfNeeded(this: v26, pAdjIsland: v34);
              bfx::Island3D::AddConnectionPairIfNeeded(this: (bfx::Island3D *)v34, pAdjIsland: (bfx::Space *)v26);
            }
          }
          ++v29;
          ++v31;
        }
        while ( v29 < v30->m_portals.m_size );
        m_size = v40[0].m_size;
      }
    }
    if ( v40[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v40[0].m_data);
    return 1;
  }
}


// ========================================================================
// __unwind$15187
// EA  : 0x8329CA50
// RVA : 0x0129CA50
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void _unwind_15187()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 96));
}


// ========================================================================
// ?RemoveIsland@Island3DGraph@bfx@@QAAXPAVVolume@2@PAV?$Array@PAVVolume@bfx@@@2@@Z
// EA  : 0x8329CA80
// RVA : 0x0129CA80
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void __fastcall bfx::Island3DGraph::RemoveIsland(
        bfx::Island3DGraph *this,
        bfx::Space *pStartVolume,
        bfx::Array<bfx::Space *> *pVolumesTouchedOut,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  unsigned int m_z_low; // r21
  int m_size; // r28
  char *m_data; // r26
  int m_cap; // r22
  char *v20; // r11
  int v21; // r23
  const bfx::Volume *v22; // r24
  int v23; // r25
  const bfx::Volume *OtherVolume; // r3
  bfx::Volume *v25; // r29
  int v26; // r10
  int v27; // r11
  int v28; // r4
  bfx::Volume **v29; // r11
  bool v30; // cr34
  int v31; // r4
  bfx::Array<bfx::SpaceComponent *> v32[9]; // [sp+60h] [-90h] BYREF

  m_z_low = LODWORD(pStartVolume->m_rotSpaceToWorld.m_z);
  a14 = pStartVolume;
  memset(v32, 0, 12);
  v32[0].m_tag = bfx::MEM_BFXPLANNER3D;
  LODWORD(pStartVolume->m_rotSpaceToWorld.m_z) = 1023;
  if ( pVolumesTouchedOut != nullptr )
    bfx::Array<bfx::Portal *>::push_back(this: pVolumesTouchedOut, val: &a14);
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v32, val: &a14);
  m_size = v32[0].m_size;
  m_data = (char *)v32[0].m_data;
  if ( v32[0].m_size != 0 )
  {
    m_cap = v32[0].m_cap;
    do
    {
      v20 = &m_data[4 * m_size--];
      v32[0].m_size = m_size;
      v21 = 0;
      v22 = *((const bfx::Volume **)v20 - 1);
      if ( v22->m_portals.m_size > 0 )
      {
        v23 = 0;
        do
        {
          OtherVolume = bfx::Portal::GetOtherVolume(this: v22->m_portals.m_data[v23].m_pPortal, vol: v22);
          v25 = (bfx::Volume *)OtherVolume;
          if ( OtherVolume->m_islandID == m_z_low )
          {
            OtherVolume->m_islandID = 1023;
            if ( pVolumesTouchedOut != nullptr )
            {
              v26 = pVolumesTouchedOut->m_cap;
              v27 = pVolumesTouchedOut->m_size;
              if ( v26 == v27 )
              {
                v28 = 2 * v26;
                if ( v26 == 0 )
                  v28 = 1;
                bfx::Array<bfx::Edge *>::expand_cap(
                  this: (bfx::Array<bfx::SpaceComponent *> *)pVolumesTouchedOut,
                  size: v28);
                v29 = (bfx::Volume **)&pVolumesTouchedOut->m_data[pVolumesTouchedOut->m_size];
                v30 = v29 == nullptr;
              }
              else
              {
                v29 = (bfx::Volume **)&pVolumesTouchedOut->m_data[v27];
                v30 = v29 == nullptr;
              }
              if ( !v30 )
                *v29 = v25;
              ++pVolumesTouchedOut->m_size;
            }
            if ( m_cap == m_size )
            {
              v31 = 2 * m_cap;
              if ( m_cap == 0 )
                v31 = 1;
              bfx::Array<bfx::Edge *>::expand_cap(this: v32, size: v31);
              m_size = v32[0].m_size;
              m_data = (char *)v32[0].m_data;
              m_cap = v32[0].m_cap;
            }
            if ( &m_data[4 * m_size] != nullptr )
              *(_DWORD *)&m_data[4 * m_size] = v25;
            v32[0].m_size = ++m_size;
          }
          ++v21;
          ++v23;
        }
        while ( v21 < v22->m_portals.m_size );
      }
    }
    while ( m_size != 0 );
  }
  *(unsigned int *)((char *)this->m_islandIDsInUse + ((m_z_low >> 3) & 0x1FFFFFFC)) &= ~(1 << (m_z_low & 0x1F));
  bfx::Island3DArray::DestroyIsland(this: &this->m_islandArray, islandNum: m_z_low);
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$15373
// EA  : 0x8329CC60
// RVA : 0x0129CC60
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void _unwind_15373()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 96));
}


// ========================================================================
// ??1Island3DArray@bfx@@QAA@XZ
// EA  : 0x8329CC90
// RVA : 0x0129CC90
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void __fastcall bfx::Island3DArray::~Island3DArray(bfx::Island3DArray *this)
{
  int v2; // r25
  int v3; // r27
  bfx::Island3D *v4; // r30
  char *m_data; // r4
  char *v6; // r4

  v2 = 0;
  if ( this->m_islands.m_size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->m_islands.m_data[v3];
      if ( v4 != nullptr )
      {
        m_data = (char *)v4->m_connections.m_data;
        v4->m_connections.m_size = 0;
        if ( m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
          v4->m_connections.m_data = nullptr;
        }
        v4->m_connections.m_cap = 0;
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v4);
      }
      ++v2;
      this->m_islands.m_data[v3++] = nullptr;
    }
    while ( v2 < this->m_islands.m_size );
  }
  v6 = (char *)this->m_islands.m_data;
  this->m_islands.m_size = 0;
  if ( v6 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6);
    this->m_islands.m_data = nullptr;
  }
  this->m_islands.m_cap = 0;
}


// ========================================================================
// __unwind$15732
// EA  : 0x8329CD50
// RVA : 0x0129CD50
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void _unwind_15732()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 144 + 164));
}


// ========================================================================
// ??0Island3DGraph@bfx@@QAA@XZ
// EA  : 0x8329CD78
// RVA : 0x0129CD78
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

bfx::Island3DGraph *__fastcall bfx::Island3DGraph::Island3DGraph(bfx::Island3DGraph *this)
{
  bfx::Island3DGraph *v1; // r10
  bfx::bfxMemTag v2; // r8
  int v3; // ctr

  v1 = (bfx::Island3DGraph *)((char *)this - 4);
  v2 = bfx::MEM_BFXPLANNER3D;
  this->m_islandArray.m_islands.m_data = nullptr;
  v3 = 32;
  this->m_islandArray.m_islands.m_size = 0;
  this->m_islandArray.m_islands.m_cap = 0;
  this->m_islandArray.m_islands.m_tag = v2;
  do
  {
    v1 = (bfx::Island3DGraph *)((char *)v1 + 4);
    v1->m_islandIDsInUse[0] = 0;
    --v3;
  }
  while ( v3 != 0 );
  return this;
}


// ========================================================================
// ??1Island3DGraph@bfx@@QAA@XZ
// EA  : 0x8329CDB0
// RVA : 0x0129CDB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void __fastcall bfx::Island3DGraph::~Island3DGraph(bfx::Island3DGraph *this)
{
  bfx::Island3DArray::~Island3DArray(this: &this->m_islandArray);
}


// ========================================================================
// ?Search@Island3DGraph@bfx@@ABA_NPAVIsland3D@2@0ABVPath3DSpec@2@PAVVRT@2@@Z
// EA  : 0x8329CDC0
// RVA : 0x0129CDC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

int __fastcall bfx::Island3DGraph::Search(
        bfx::Island3DGraph *this,
        bfx::Pool::Node *pStartingIsland,
        bfx::Island3D *pEndingIsland,
        const bfx::Path3DSpec *pathSpec,
        bfx::VRT *pVRTOut)
{
  char *m_data; // r27
  int m_size; // r28
  bfx::List<bfx::Island3D *>::Node *m_pEnd; // r30
  bfx::Pool::Node *Node; // r3
  bfx::List<bfx::Island3D *>::Node *v13; // r11
  int v14; // r20
  bfx::List<bfx::Island3D *>::Node *m_pNext; // r10
  bfx::Space *v16; // r9
  unsigned int m_spaceID; // r8
  bfx::HandleProxy *m_pProxy; // r7
  bfx::Space_vtbl *v19; // r30
  bfx::Pool *m_pPool; // r11
  bfx::Space_vtbl *v21; // r28
  int v22; // r25
  int v23; // r27
  bfx::Island3D *v24; // r30
  bfx::List<bfx::Island3D *>::Node *v25; // r29
  bfx::Pool::Node *v26; // r3
  char *v27; // r11
  int i; // ctr
  bfx::Space *v30; // [sp+50h] [-A0h] BYREF
  bfx::List<bfx::Island3D *> v31[2]; // [sp+58h] [-98h] BYREF
  bfx::Array<bfx::Space *> v32; // [sp+70h] [-80h] BYREF

  bfx::List<bfx::Area *>::List<bfx::Area *>(this: v31, numNodesPerPoolBlock: 0x64u, memTag: bfx::MEM_BFXPLANNER3D);
  m_data = nullptr;
  m_size = 0;
  memset(&v32, 0, 12);
  v32.m_tag = bfx::MEM_BFXPLANNER3D;
  m_pEnd = v31[0].m_pEnd;
  Node = bfx::Pool::GetNode(this: v31[0].m_pPool);
  if ( Node != nullptr )
    Node->m_pNext = pStartingIsland;
  Node[1].m_pNext = (bfx::Pool::Node *)m_pEnd;
  Node[2].m_pNext = (bfx::Pool::Node *)m_pEnd->m_pPrev;
  m_pEnd->m_pPrev->m_pNext = (bfx::List<bfx::Island3D *>::Node *)Node;
  m_pEnd->m_pPrev = (bfx::List<bfx::Island3D *>::Node *)Node;
  HIBYTE(pStartingIsland[2].m_pNext) = 1;
  if ( pVRTOut != nullptr )
    *(unsigned int *)((char *)pVRTOut->m_reachabilityBits + (((unsigned int)pStartingIsland->m_pNext >> 3) & 0x1FFFFFFC)) |= 1 << (HIBYTE(pStartingIsland->m_pNext) & 0x1F);
  v13 = v31[0].m_pEnd;
  v14 = 0;
  m_pNext = v31[0].m_pEnd->m_pNext;
  if ( m_pNext != v31[0].m_pEnd )
  {
    do
    {
      if ( (_BYTE)v14 != 0 )
        break;
      v16 = (bfx::Space *)v13->m_pNext;
      m_spaceID = v16->m_spaceID;
      m_pProxy = v16->m_pProxy;
      v19 = v16->__vftable;
      v30 = v16;
      *(_DWORD *)(m_spaceID + 4) = m_pProxy;
      v16->m_pProxy[1].m_pTarget = (bfx::HandleTargetBase *)v16->m_spaceID;
      m_pPool = v31[0].m_pPool;
      v16->__vftable = (bfx::Space_vtbl *)v31[0].m_pPool->m_data.m_pUnused;
      v30 = (bfx::Space *)v19;
      m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)v16;
      bfx::Array<bfx::Portal *>::push_back(this: &v32, val: &v30);
      v21 = v19 + 3;
      v22 = 0;
      if ( (int)v19[4].dtr_HandleTargetBase > 0 )
      {
        v23 = 0;
        while ( 1 )
        {
          v24 = *(bfx::Island3D **)((char *)v21->dtr_HandleTargetBase + v23);
          if ( !v24->m_searched && (v24->m_userData & pathSpec->m_customGeoMatchFlags) != 0 )
          {
            v24->m_searched = true;
            v25 = v31[0].m_pEnd;
            v26 = bfx::Pool::GetNode(this: v31[0].m_pPool);
            if ( v26 != nullptr )
              v26->m_pNext = (bfx::Pool::Node *)v24;
            v26[1].m_pNext = (bfx::Pool::Node *)v25;
            v26[2].m_pNext = (bfx::Pool::Node *)v25->m_pPrev;
            v25->m_pPrev->m_pNext = (bfx::List<bfx::Island3D *>::Node *)v26;
            v25->m_pPrev = (bfx::List<bfx::Island3D *>::Node *)v26;
            if ( pVRTOut != nullptr )
              *(unsigned int *)((char *)pVRTOut->m_reachabilityBits
                              + (((unsigned int)v24->m_islandNum >> 3) & 0x1FFFFFFC)) |= 1 << (HIBYTE(v24->m_islandNum)
                                                                                             & 0x1F);
            if ( pEndingIsland != nullptr && v24 == pEndingIsland )
              break;
          }
          ++v22;
          v23 += 4;
          if ( v22 >= (int)v21[1].dtr_HandleTargetBase )
            goto LABEL_20;
        }
        v14 = 1;
      }
LABEL_20:
      v13 = v31[0].m_pEnd;
      m_pNext = v31[0].m_pEnd->m_pNext;
    }
    while ( m_pNext != v31[0].m_pEnd );
    m_size = v32.m_size;
    m_data = (char *)v32.m_data;
    if ( m_pNext != v13 )
    {
      do
      {
        m_pNext->m_val->m_searched = false;
        m_pNext = m_pNext->m_pNext;
      }
      while ( m_pNext != v31[0].m_pEnd );
    }
  }
  if ( m_size > 0 )
  {
    v27 = m_data - 4;
    for ( i = m_size; i != 0; --i )
    {
      v27 += 4;
      *(_BYTE *)(*(_DWORD *)v27 + 8) = 0;
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: v31);
  return v14;
}


// ========================================================================
// __unwind$15876
// EA  : 0x8329D024
// RVA : 0x0129D024
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void _unwind_15876()
{
  int v0; // r12

  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: (bfx::List<bfx::Island3D *> *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$15877
// EA  : 0x8329D04C
// RVA : 0x0129D04C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void _unwind_15877()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 112));
}


// ========================================================================
// ?IsReachable@Island3DGraph@bfx@@QBA_NPBVVolume@2@0ABVPath3DSpec@2@@Z
// EA  : 0x8329D078
// RVA : 0x0129D078
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

int __fastcall bfx::Island3DGraph::IsReachable(
        bfx::Island3DGraph *this,
        const bfx::Volume *pStartVolume,
        const bfx::Volume *pEndVolume,
        const bfx::Path3DSpec *pathSpec)
{
  signed int m_islandID; // r11
  signed int v5; // r9
  int m_size; // r10
  bfx::Pool::Node *v8; // r4
  bfx::Island3D *v9; // r5

  m_islandID = pStartVolume->m_islandID;
  v5 = pEndVolume->m_islandID;
  if ( m_islandID == 1023 || v5 == 1023 )
    return 0;
  if ( m_islandID == v5 )
    return 1;
  m_size = this->m_islandArray.m_islands.m_size;
  v8 = m_islandID >= m_size ? nullptr : (bfx::Pool::Node *)this->m_islandArray.m_islands.m_data[m_islandID];
  v9 = v5 >= m_size ? nullptr : this->m_islandArray.m_islands.m_data[v5];
  if ( v8 == nullptr || v9 == nullptr )
    return 0;
  else
    return bfx::Island3DGraph::Search(this, pStartingIsland: v8, pEndingIsland: v9, pathSpec, pVRTOut: nullptr);
}


// ========================================================================
// ?BuildVRT@Island3DGraph@bfx@@QBAXPBVVolume@2@ABVPath3DSpec@2@AAVVRT@2@@Z
// EA  : 0x8329D100
// RVA : 0x0129D100
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxisland3d.cpp
// ========================================================================

void __fastcall bfx::Island3DGraph::BuildVRT(
        bfx::Island3DGraph *this,
        const bfx::Volume *pStartVolume,
        const bfx::Path3DSpec *pathSpec,
        bfx::VRT *vrtOut)
{
  signed int m_islandID; // r11
  bfx::Pool::Node *v5; // r4

  m_islandID = pStartVolume->m_islandID;
  if ( m_islandID != 1023 && m_islandID < this->m_islandArray.m_islands.m_size )
  {
    v5 = (bfx::Pool::Node *)this->m_islandArray.m_islands.m_data[m_islandID];
    if ( v5 != nullptr )
      bfx::Island3DGraph::Search(this, pStartingIsland: v5, pEndingIsland: nullptr, pathSpec, pVRTOut: vrtOut);
  }
}

