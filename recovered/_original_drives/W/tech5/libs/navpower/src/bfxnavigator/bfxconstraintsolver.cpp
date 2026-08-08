
// ========================================================================
// ?KeepWithinRadius@SolverEntity@bfx@@QAAXM@Z
// EA  : 0x832A33B8
// RVA : 0x012A33B8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

void __fastcall bfx::SolverEntity::KeepWithinRadius(bfx::SolverEntity *this, double radius)
{
  double v4; // fp0
  double v5; // fp13
  double v6; // fp11
  double v7; // fp11
  bfx::RepulsorImpl *m_pRepulsor; // r3
  float v9; // [sp+50h] [-40h] BYREF
  float v10; // [sp+54h] [-3Ch]
  float v11; // [sp+58h] [-38h]
  bfx::Vec3 v12; // [sp+60h] [-30h] BYREF

  if ( this->m_pRepulsor != nullptr )
  {
    bfx::RepulsorImpl::GetSolverPos(this: (bfx::RepulsorImpl *)&v9, result: (bfx::Vec3 *)this->m_pRepulsor);
    v4 = (float)(this->m_origPos.m_y - v10);
    v5 = (float)(this->m_origPos.m_z - v11);
    v6 = (float)((float)((float)(this->m_origPos.m_x - v9) * (float)(this->m_origPos.m_x - v9))
               + (float)((float)((float)(this->m_origPos.m_z - v11) * (float)(this->m_origPos.m_z - v11))
                       + (float)((float)(this->m_origPos.m_y - v10) * (float)(this->m_origPos.m_y - v10))));
    if ( v6 > (float)((float)radius * (float)radius) )
    {
      v7 = __fsqrts(v6);
      m_pRepulsor = this->m_pRepulsor;
      v12.m_x = (float)(this->m_origPos.m_x - v9) * (float)((float)((float)v7 - (float)radius) / (float)v7);
      v12.m_y = (float)v4 * (float)((float)((float)v7 - (float)radius) / (float)v7);
      v12.m_z = (float)v5 * (float)((float)((float)v7 - (float)radius) / (float)v7);
      bfx::RepulsorImpl::Move(this: m_pRepulsor, vel: &v12, time: 1.0);
    }
  }
}


// ========================================================================
// ??0SolverPair@bfx@@QAA@PAVRepulsorImpl@1@0@Z
// EA  : 0x832A3478
// RVA : 0x012A3478
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

bfx::SolverPair *__fastcall bfx::SolverPair::SolverPair(
        bfx::SolverPair *this,
        bfx::RepulsorImpl *pRepulsorA,
        bfx::RepulsorImpl *pRepulsorB)
{
  bfx::InitialConstraint *p_m_initialConstraint; // r30
  bfx::RepulsorImpl *m_pRepulsor; // r11
  bfx::RepulsorImpl *v7; // r10
  bool v8; // r8
  bool v9; // r7
  double v11; // fp10

  this->m_entityA.m_pRepulsor = pRepulsorA;
  p_m_initialConstraint = &this->m_entityA.m_initialConstraint;
  this->m_entityA.m_radius = pRepulsorA->m_radiusData.m_radius;
  this->m_entityA.m_initialConstraint.m_constraintType = CONSTRAINT_NONE;
  bfx::RepulsorImpl::GetSolverPos(
    this: (bfx::RepulsorImpl *)&this->m_entityA.m_origPos,
    result: (bfx::Vec3 *)this->m_entityA.m_pRepulsor);
  bfx::RepulsorImpl::GetInitialConstraint(this: this->m_entityA.m_pRepulsor, initialConstraint: p_m_initialConstraint);
  this->m_entityA.m_effectFraction = 0.0;
  this->m_entityB.m_pRepulsor = pRepulsorB;
  this->m_entityB.m_radius = pRepulsorB->m_radiusData.m_radius;
  this->m_entityB.m_initialConstraint.m_constraintType = CONSTRAINT_NONE;
  bfx::RepulsorImpl::GetSolverPos(
    this: (bfx::RepulsorImpl *)&this->m_entityB.m_origPos,
    result: (bfx::Vec3 *)this->m_entityB.m_pRepulsor);
  bfx::RepulsorImpl::GetInitialConstraint(
    this: this->m_entityB.m_pRepulsor,
    initialConstraint: &this->m_entityB.m_initialConstraint);
  this->m_entityB.m_effectFraction = 0.0;
  m_pRepulsor = this->m_entityB.m_pRepulsor;
  v7 = this->m_entityA.m_pRepulsor;
  v8 = (m_pRepulsor->m_repulsorIdentityFlags & this->m_entityA.m_pRepulsor->m_blockageFlags) != 0;
  v9 = (m_pRepulsor->m_blockageFlags & this->m_entityA.m_pRepulsor->m_repulsorIdentityFlags) != 0;
  if ( this->m_entityA.m_initialConstraint.m_constraintType == CONSTRAINT_POINT )
  {
    if ( this->m_entityB.m_initialConstraint.m_constraintType != CONSTRAINT_POINT )
    {
      this->m_entityA.m_effectFraction = 0.0;
      this->m_entityB.m_effectFraction = 1.0;
      if ( !v9 )
      {
        this->m_entityB.m_effectFraction = 0.0;
        return this;
      }
      return this;
    }
LABEL_20:
    this->m_entityA.m_effectFraction = 0.0;
    this->m_entityB.m_effectFraction = 0.0;
    return this;
  }
  if ( this->m_entityB.m_initialConstraint.m_constraintType != CONSTRAINT_POINT )
  {
    if ( (m_pRepulsor->m_repulsorIdentityFlags & this->m_entityA.m_pRepulsor->m_blockageFlags) == 0 )
      goto LABEL_10;
    if ( (m_pRepulsor->m_blockageFlags & this->m_entityA.m_pRepulsor->m_repulsorIdentityFlags) != 0 )
    {
      v11 = (float)(m_pRepulsor->m_bulk / (float)(v7->m_bulk + m_pRepulsor->m_bulk));
      this->m_entityA.m_effectFraction = m_pRepulsor->m_bulk / (float)(v7->m_bulk + m_pRepulsor->m_bulk);
      this->m_entityB.m_effectFraction = (float)1.0 - (float)v11;
      return this;
    }
    if ( (m_pRepulsor->m_repulsorIdentityFlags & this->m_entityA.m_pRepulsor->m_blockageFlags) != 0 )
    {
      if ( (m_pRepulsor->m_blockageFlags & this->m_entityA.m_pRepulsor->m_repulsorIdentityFlags) == 0 )
      {
        this->m_entityB.m_effectFraction = 0.0;
        this->m_entityA.m_effectFraction = 1.0;
        return this;
      }
    }
    else
    {
LABEL_10:
      if ( (m_pRepulsor->m_blockageFlags & this->m_entityA.m_pRepulsor->m_repulsorIdentityFlags) != 0 )
      {
        this->m_entityA.m_effectFraction = 0.0;
        this->m_entityB.m_effectFraction = 1.0;
        return this;
      }
    }
    return this;
  }
  if ( this->m_entityB.m_initialConstraint.m_constraintType != CONSTRAINT_POINT )
    goto LABEL_20;
  this->m_entityB.m_effectFraction = 0.0;
  this->m_entityA.m_effectFraction = 1.0;
  if ( !v8 )
  {
    this->m_entityB.m_effectFraction = 0.0;
    return this;
  }
  return this;
}


// ========================================================================
// ?ResolveMoverOverlapConstraints@bfx@@YAXAAV?$Array@PAVRepulsorImpl@bfx@@@1@@Z
// EA  : 0x832A38B8
// RVA : 0x012A38B8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

void __fastcall bfx::ResolveMoverOverlapConstraints(bfx::Array<bfx::RepulsorImpl *> *theList)
{
  double v2; // fp26
  char *v3; // r24
  int m_size; // r8
  int v5; // r21
  int v6; // r11
  bfx::RepulsorImpl *v7; // r25
  bool v8; // r23
  double m_radius; // fp31
  unsigned int m_blockageFlags; // r28
  unsigned int m_repulsorIdentityFlags; // r27
  int v12; // r29
  _DWORD *v13; // r26
  int v14; // r24
  int v15; // r30
  bool v16; // r8
  int v17; // r7
  double v18; // fp2
  bfx::SpaceComponent **m_data; // r26
  int v20; // r23
  bfx::SolverPair *v21; // r3
  bfx::List<bfx::SolverPair>::Node *m_pEnd; // r27
  bfx::SolverPair *v23; // r24
  bfx::Pool::Node **p_m_pUnused; // r29
  bfx::Pool *m_pPool; // r30
  bfx::Pool::Node *m_pUnused; // r28
  bfx::Pool::BlockHeader *v27; // r3
  bfx::Pool::BlockHeader *m_pHead; // r10
  int v29; // r11
  bool v30; // zf
  bfx::List<bfx::SolverPair>::Node *v31; // r11
  int i; // r25
  bfx::List<bfx::SolverPair>::Node *m_pNext; // r30
  char v34; // r28
  bfx::RepulsorImpl **p_m_pRepulsor; // r29
  double v36; // fp0
  double v37; // fp13
  double v38; // fp13
  double v39; // fp13
  double v40; // fp31
  double v41; // fp30
  double v42; // fp29
  double m_effectFraction; // fp12
  double v44; // fp0
  double v45; // fp13
  double v46; // fp12
  double m_z; // fp11
  double v48; // fp10
  double m_y; // fp9
  double m_x; // fp8
  double v51; // fp13
  double v52; // fp0
  double v53; // fp12
  double v54; // fp13
  double v55; // fp11
  double v56; // fp10
  double v57; // fp9
  double v58; // fp8
  __int64 v59; // [sp+50h] [-1F0h] BYREF
  bfx::Vec3 v60; // [sp+58h] [-1E8h] BYREF
  bfx::Vec3 v61; // [sp+68h] [-1D8h] BYREF
  bfx::Array<bfx::SpaceComponent *> v62; // [sp+80h] [-1C0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v63; // [sp+90h] [-1B0h] BYREF
  bfx::SmallestN<bfx::Volume *> v64; // [sp+A0h] [-1A0h] BYREF
  bfx::List<bfx::SolverPair> v65; // [sp+B8h] [-188h] BYREF
  __int64 v66; // [sp+C8h] [-178h]
  bfx::RepulsorImpl v67[2]; // [sp+D0h] [-170h] BYREF

  v2 = (float)(bfx::GetScale() * (float)0.25);
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::List<bfx::MoverSpaceComponent::ObstacleRequestData>(
    this: &v65,
    numNodesPerPoolBlock: 0x14u,
    memTag: bfx::MEM_BFXNAVIGATOR);
  memset(&v64, 0, 12);
  v64.m_data.m_tag = bfx::MEM_BFXSYSTEM;
  v64.m_pLargest = nullptr;
  v64.m_N = 5;
  bfx::Array<bfx::NavWedge>::expand_cap(this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&v64, size: 5);
  v3 = nullptr;
  memset(&v62, 0, 12);
  v62.m_tag = bfx::MEM_BFXNAVIGATOR;
  m_size = theList->m_size;
  v5 = 0;
  HIDWORD(v66) = theList;
  LODWORD(v66) = 0;
  if ( m_size > 0 )
  {
    v6 = 0;
    do
    {
      v7 = theList->m_data[v6];
      if ( v7 != nullptr )
      {
        v7->m_posModifiedBySolver = false;
        v67[0].m_repulsorIdentityFlags = 2;
        bfx::RepulsorImpl::GetInitialConstraint(
          this: v7,
          initialConstraint: (bfx::InitialConstraint *)&v67[0].m_repulsorIdentityFlags);
        v8 = (_cntlzw(v67[0].m_repulsorIdentityFlags) & 0x20) != 0;
        bfx::RepulsorImpl::GetSolverPos(this: (bfx::RepulsorImpl *)&v67[0].m_pos.m_y, result: (bfx::Vec3 *)v7);
        m_radius = v7->m_radiusData.m_radius;
        m_blockageFlags = v7->m_blockageFlags;
        m_repulsorIdentityFlags = v7->m_repulsorIdentityFlags;
        memset(&v63, 0, 12);
        v63.m_tag = bfx::MEM_BFXNAVIGATOR;
        bfx::Repulsor3DImpl::GetNearbyRepulsors(this: v7, nearbyRepulsors: &v63, filterBasedOnBlockageFlags: false);
        v12 = v5 + 1;
        v64.m_data.m_size = 0;
        v64.m_pLargest = nullptr;
        v59 = v66;
        v13 = (_DWORD *)HIDWORD(v66);
        if ( v5 + 1 < *(_DWORD *)(HIDWORD(v66) + 4) )
        {
          v14 = 4 * v12;
          do
          {
            HIDWORD(v59) = *(_DWORD *)(v14 + *v13);
            v15 = HIDWORD(v59);
            if ( HIDWORD(v59) != 0 )
            {
              v67[0].m_pAABB = (bfx::AABB *)2;
              bfx::RepulsorImpl::GetInitialConstraint(
                this: (bfx::RepulsorImpl *)HIDWORD(v59),
                initialConstraint: (bfx::InitialConstraint *)&v67[0].m_pAABB);
              v16 = (_cntlzw((unsigned int)v67[0].m_pAABB) & 0x20) != 0;
              if ( !v8 || !v16 )
              {
                v17 = *(_DWORD *)(v15 + 64) & m_blockageFlags;
                if ( (v17 != 0 || (*(_DWORD *)(v15 + 60) & m_repulsorIdentityFlags) != 0)
                  && (!v8 || (*(_DWORD *)(v15 + 60) & m_repulsorIdentityFlags) != 0)
                  && (!v16 || v17 != 0) )
                {
                  bfx::RepulsorImpl::GetSolverPos(this: (bfx::RepulsorImpl *)&v67[0].m_bulk, result: (bfx::Vec3 *)v15);
                  v18 = (float)((float)((float)v2 * (float)2.0) + (float)(*(float *)(v15 + 36) + (float)m_radius));
                  if ( (float)((float)((float)(v67[0].m_vel.m_x - v67[0].m_repulsionMultiplier)
                                     * (float)(v67[0].m_vel.m_x - v67[0].m_repulsionMultiplier))
                             + (float)((float)((float)(v67[0].m_pos.m_y - v67[0].m_bulk)
                                             * (float)(v67[0].m_pos.m_y - v67[0].m_bulk))
                                     + (float)((float)(v67[0].m_pos.m_z - *(float *)&v67[0].m_repulsorType)
                                             * (float)(v67[0].m_pos.m_z - *(float *)&v67[0].m_repulsorType)))) < (double)(float)((float)v18 * (float)v18) )
                    bfx::SmallestN<bfx::Area *>::Add(
                      this: &v64,
                      data: (bfx::ReplayListener **)&v59,
                      metric: (float)((float)((float)((float)(v67[0].m_vel.m_x - v67[0].m_repulsionMultiplier)
                                            * (float)(v67[0].m_vel.m_x - v67[0].m_repulsionMultiplier))
                                    + (float)((float)((float)(v67[0].m_pos.m_y - v67[0].m_bulk)
                                                    * (float)(v67[0].m_pos.m_y - v67[0].m_bulk))
                                            + (float)((float)(v67[0].m_pos.m_z - *(float *)&v67[0].m_repulsorType)
                                                    * (float)(v67[0].m_pos.m_z - *(float *)&v67[0].m_repulsorType))))
                            - (float)((float)v18 * (float)v18)));
                }
              }
            }
            ++v12;
            v14 += 4;
          }
          while ( v12 < v13[1] );
          if ( v64.m_data.m_size != 0 )
          {
            v62.m_size = 0;
            bfx::SmallestN<bfx::Area *>::GetData(this: &v64, dataOut: &v62);
            if ( v62.m_size > 0 )
            {
              m_data = v62.m_data;
              v20 = v62.m_size;
              do
              {
                v21 = bfx::SolverPair::SolverPair(
                        this: (bfx::SolverPair *)&v67[0].m_solverData.m_pMoveFunc,
                        pRepulsorA: v7,
                        pRepulsorB: (bfx::RepulsorImpl *)*m_data);
                m_pEnd = v65.m_pEnd;
                v23 = v21;
                p_m_pUnused = &v65.m_pPool->m_data.m_pUnused;
                m_pPool = v65.m_pPool;
                m_pUnused = v65.m_pPool->m_data.m_pUnused;
                if ( m_pUnused != nullptr )
                {
                  *p_m_pUnused = m_pUnused->m_pNext;
                }
                else
                {
                  v27 = bfx::Pool::AllocBlock(
                          nodeSize: v65.m_pPool->m_data.m_nodeSize,
                          numNodes: v65.m_pPool->m_data.m_numNodesPerBlock,
                          tag: (bfx::bfxMemTag)v65.m_pPool->m_data.m_tag);
                  m_pUnused = (bfx::Pool::Node *)&v27[1];
                  m_pHead = m_pPool->m_data.m_pHead;
                  ++m_pPool->m_data.m_numBlocksAllocated;
                  v27->m_pNext = m_pHead;
                  *p_m_pUnused = (bfx::Pool::Node *)&v27[1];
                  m_pPool->m_data.m_pHead = v27;
                  *p_m_pUnused = (bfx::Pool::Node *)v27[1].m_pNext;
                }
                HIDWORD(v59) = m_pUnused;
                if ( m_pUnused != nullptr )
                  memcpy(Dst: m_pUnused, Src: v23, Size: 0x50u);
                m_pUnused[20].m_pNext = (bfx::Pool::Node *)m_pEnd;
                --v20;
                ++m_data;
                m_pUnused[21].m_pNext = (bfx::Pool::Node *)m_pEnd->m_pPrev;
                m_pEnd->m_pPrev->m_pNext = (bfx::List<bfx::SolverPair>::Node *)m_pUnused;
                m_pEnd->m_pPrev = (bfx::List<bfx::SolverPair>::Node *)m_pUnused;
              }
              while ( v20 != 0 );
            }
          }
        }
        v63.m_size = 0;
        if ( v63.m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v63.m_data);
          v63.m_data = nullptr;
        }
        v63.m_cap = 0;
      }
      v29 = theList->m_size;
      LODWORD(v66) = ++v5;
      v30 = v5 < v29;
      v6 = v5;
    }
    while ( v30 );
    v3 = (char *)v62.m_data;
  }
  v31 = v65.m_pEnd;
  for ( i = 0; i < 5; ++i )
  {
    m_pNext = v31->m_pNext;
    v34 = 0;
    if ( m_pNext != v31 )
    {
      do
      {
        bfx::RepulsorImpl::GetSolverPos(this: v67, result: (bfx::Vec3 *)m_pNext->m_val.m_entityA.m_pRepulsor);
        p_m_pRepulsor = &m_pNext->m_val.m_entityB.m_pRepulsor;
        bfx::RepulsorImpl::GetSolverPos(
          this: (bfx::RepulsorImpl *)&v67[0].m_vel.m_z,
          result: (bfx::Vec3 *)m_pNext->m_val.m_entityB.m_pRepulsor);
        v36 = (float)(m_pNext->m_val.m_entityB.m_radius + m_pNext->m_val.m_entityA.m_radius);
        v37 = (float)((float)((float)(*(float *)&v67[0].m_pSpace - v67[0].m_radiusData.m_outerCushion)
                            * (float)(*(float *)&v67[0].m_pSpace - v67[0].m_radiusData.m_outerCushion))
                    + (float)((float)((float)(*(float *)&v67[0].__vftable - v67[0].m_vel.m_z)
                                    * (float)(*(float *)&v67[0].__vftable - v67[0].m_vel.m_z))
                            + (float)((float)(*(float *)&v67[0].m_pProxy - v67[0].m_radiusData.m_radius)
                                    * (float)(*(float *)&v67[0].m_pProxy - v67[0].m_radiusData.m_radius))));
        if ( v37 < (float)((float)v36 * (float)v36) )
        {
          v38 = __fsqrts(v37);
          v34 = 1;
          if ( v38 <= 1.0842022e-19 )
          {
            v40 = (float)((float)(m_pNext->m_val.m_entityB.m_radius + m_pNext->m_val.m_entityA.m_radius)
                        * (float)0.0099999998);
            *(float *)&v59 = m_pNext->m_val.m_entityB.m_radius + m_pNext->m_val.m_entityA.m_radius;
            v41 = (float)((float)v36 * (float)0.0099999998);
            v42 = v41;
          }
          else
          {
            v39 = (float)((float)((float)(m_pNext->m_val.m_entityB.m_radius + m_pNext->m_val.m_entityA.m_radius)
                                - (float)v38)
                        / (float)v38);
            v40 = (float)((float)(*(float *)&v67[0].m_pSpace - v67[0].m_radiusData.m_outerCushion)
                        * (float)((float)((float)(m_pNext->m_val.m_entityB.m_radius + m_pNext->m_val.m_entityA.m_radius)
                                        * (float)0.001)
                                + (float)v39));
            v41 = (float)((float)(*(float *)&v67[0].m_pProxy - v67[0].m_radiusData.m_radius)
                        * (float)((float)((float)(m_pNext->m_val.m_entityB.m_radius + m_pNext->m_val.m_entityA.m_radius)
                                        * (float)0.001)
                                + (float)v39));
            v42 = (float)((float)(*(float *)&v67[0].__vftable - v67[0].m_vel.m_z)
                        * (float)((float)((float)(m_pNext->m_val.m_entityB.m_radius + m_pNext->m_val.m_entityA.m_radius)
                                        * (float)0.001)
                                + (float)v39));
          }
          m_effectFraction = m_pNext->m_val.m_entityA.m_effectFraction;
          v44 = (float)((float)v42 * m_pNext->m_val.m_entityA.m_effectFraction);
          v45 = (float)((float)v41 * m_pNext->m_val.m_entityA.m_effectFraction);
          v61.m_x = (float)v42 * m_pNext->m_val.m_entityA.m_effectFraction;
          v61.m_y = (float)v41 * (float)m_effectFraction;
          v46 = (float)((float)v40 * (float)m_effectFraction);
          v61.m_z = v46;
          if ( m_pNext->m_val.m_entityA.m_initialConstraint.m_constraintType == CONSTRAINT_LINE )
          {
            m_z = m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_z;
            v48 = (float)(m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_z * (float)v46);
            m_y = m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_y;
            m_x = m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_x;
            v61.m_x = m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_x
                    * (float)((float)(m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_x * (float)v44)
                            + (float)((float)(m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_y * (float)v45)
                                    + (float)(m_pNext->m_val.m_entityA.m_initialConstraint.m_dir.m_z * (float)v46)));
            *(float *)&v59 = m_x;
            v61.m_y = (float)m_y
                    * (float)((float)((float)m_x * (float)v44) + (float)((float)((float)m_y * (float)v45) + (float)v48));
            v61.m_z = (float)m_z
                    * (float)((float)((float)m_x * (float)v44) + (float)((float)((float)m_y * (float)v45) + (float)v48));
          }
          bfx::RepulsorImpl::Move(this: m_pNext->m_val.m_entityA.m_pRepulsor, vel: &v61, time: 1.0);
          bfx::SolverEntity::KeepWithinRadius(this: &m_pNext->m_val.m_entityA, radius: v2);
          m_pNext->m_val.m_entityA.m_pRepulsor->m_posModifiedBySolver = true;
          if ( m_pNext->m_val.m_entityB.m_initialConstraint.m_constraintType != CONSTRAINT_POINT )
          {
            v51 = -m_pNext->m_val.m_entityB.m_effectFraction;
            v52 = (float)((float)v51 * (float)v42);
            v60.m_x = (float)v51 * (float)v42;
            v53 = (float)((float)v40 * (float)v51);
            v60.m_z = (float)v40 * (float)v51;
            v54 = (float)((float)v41 * (float)v51);
            v60.m_y = v54;
            if ( m_pNext->m_val.m_entityB.m_initialConstraint.m_constraintType == CONSTRAINT_LINE )
            {
              v55 = m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_z;
              v56 = (float)(m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_z * (float)v53);
              v57 = m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_y;
              v58 = m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_x;
              v60.m_x = m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_x
                      * (float)((float)(m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_x * (float)v52)
                              + (float)((float)(m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_y * (float)v54)
                                      + (float)(m_pNext->m_val.m_entityB.m_initialConstraint.m_dir.m_z * (float)v53)));
              *(float *)&v59 = v58;
              v60.m_y = (float)v57
                      * (float)((float)((float)v58 * (float)v52) + (float)((float)((float)v57 * (float)v54) + (float)v56));
              v60.m_z = (float)v55
                      * (float)((float)((float)v58 * (float)v52) + (float)((float)((float)v57 * (float)v54) + (float)v56));
            }
            bfx::RepulsorImpl::Move(this: *p_m_pRepulsor, vel: &v60, time: 1.0);
            bfx::SolverEntity::KeepWithinRadius(this: &m_pNext->m_val.m_entityB, radius: v2);
            (*p_m_pRepulsor)->m_posModifiedBySolver = true;
          }
        }
        m_pNext = m_pNext->m_pNext;
        v31 = v65.m_pEnd;
      }
      while ( m_pNext != v65.m_pEnd );
    }
    if ( v34 == 0 )
      break;
  }
  if ( v3 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3);
  if ( v64.m_data.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v64.m_data.m_data);
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::~List<bfx::MoverSpaceComponent::ObstacleRequestData>(this: &v65);
}


// ========================================================================
// __unwind$20670
// EA  : 0x832A3EB8
// RVA : 0x012A3EB8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

void _unwind_20670()
{
  int v0; // r12

  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::~List<bfx::MoverSpaceComponent::ObstacleRequestData>(this: (bfx::List<bfx::SolverPair> *)(v0 - 576 + 184));
}


// ========================================================================
// __unwind$20675
// EA  : 0x832A3EE0
// RVA : 0x012A3EE0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

void _unwind_20675()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 576 + 160));
}


// ========================================================================
// __unwind$20671
// EA  : 0x832A3F08
// RVA : 0x012A3F08
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

void _unwind_20671()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 576 + 160));
}


// ========================================================================
// __unwind$20672
// EA  : 0x832A3F30
// RVA : 0x012A3F30
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

void _unwind_20672()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 576 + 128));
}


// ========================================================================
// __unwind$20673
// EA  : 0x832A3F58
// RVA : 0x012A3F58
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxconstraintsolver.cpp
// ========================================================================

void _unwind_20673()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 576 + 144));
}

