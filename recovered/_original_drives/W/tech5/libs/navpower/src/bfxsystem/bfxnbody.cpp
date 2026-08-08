
// ========================================================================
// ?DrawBox@AABB@bfx@@QBAXPBVSpace@2@ABVColor@2@@Z
// EA  : 0x8329B450
// RVA : 0x0129B450
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

void __fastcall bfx::AABB::DrawBox(bfx::AABB *this, const bfx::Space *pSpace, const bfx::Color *color)
{
  bfx::EndPt *v3; // r11
  double m_val; // fp13
  double v5; // fp12
  double v6; // fp11
  double v7; // fp10
  bfx::Box v8; // [sp+60h] [-30h] BYREF
  bfx::Vec3 v9; // 0:^50.12

  m_val = this->m_endpts[1]->m_val;
  v5 = this->m_endpts[3]->m_val;
  v6 = this->m_endpts[5]->m_val;
  v7 = this->m_endpts[0]->m_val;
  v3 = this->m_endpts[2];
  v8.m_min.m_z = this->m_endpts[4]->m_val;
  v8.m_min.m_x = v7;
  v9.m_x = m_val;
  v9.m_y = v5;
  v9.m_z = v6;
  v8.m_min.m_y = v3->m_val;
  v8.m_max = v9;
  bfx::DrawBox(pSpace, mat: (bfx::Vec3 *)&bfx::IDENTITY, boxLCoord: &v8, color);
}


// ========================================================================
// ?DisjointOnAxis@bfx@@YA_NPAVAABB@1@0H@Z
// EA  : 0x8329B508
// RVA : 0x0129B508
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

int __fastcall bfx::DisjointOnAxis(bfx::AABB *pAABB1, bfx::AABB *pAABB2, int axis)
{
  bfx::EndPt *v3; // r11
  bfx::EndPt *v4; // r10
  double m_val; // fp0
  unsigned __int8 v6; // r11

  if ( axis == 0 )
  {
    if ( pAABB1->m_endpts[1]->m_val >= (double)pAABB2->m_endpts[0]->m_val )
    {
      v3 = pAABB1->m_endpts[0];
      v4 = pAABB2->m_endpts[1];
      goto LABEL_9;
    }
    return 1;
  }
  if ( axis == 1 )
  {
    if ( pAABB1->m_endpts[3]->m_val < (double)pAABB2->m_endpts[2]->m_val )
      return 1;
    v3 = pAABB1->m_endpts[2];
    v4 = pAABB2->m_endpts[3];
  }
  else
  {
    if ( pAABB1->m_endpts[5]->m_val < (double)pAABB2->m_endpts[4]->m_val )
      return 1;
    v3 = pAABB1->m_endpts[4];
    v4 = pAABB2->m_endpts[5];
  }
LABEL_9:
  m_val = v3->m_val;
  v6 = 0;
  if ( m_val > v4->m_val )
    return 1;
  return v6;
}


// ========================================================================
// ?DisjointOnOtherAxes@bfx@@YA_NPAVAABB@1@0H@Z
// EA  : 0x8329B5A0
// RVA : 0x0129B5A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

int __fastcall bfx::DisjointOnOtherAxes(bfx::AABB *pAABB1, bfx::AABB *pAABB2, int axis)
{
  bfx::EndPt *v3; // r11
  bfx::EndPt *v4; // r10
  bfx::EndPt *v5; // r11
  bfx::EndPt *v6; // r10
  unsigned __int8 v7; // r11
  bool v8; // zf

  if ( axis != 0 )
  {
    v5 = pAABB1->m_endpts[1];
    v6 = pAABB2->m_endpts[0];
    if ( axis == 1 )
    {
      if ( v5 < v6 || pAABB1->m_endpts[0] > pAABB2->m_endpts[1] || pAABB1->m_endpts[5] < pAABB2->m_endpts[4] )
        return 1;
      v3 = pAABB1->m_endpts[4];
      v4 = pAABB2->m_endpts[5];
    }
    else
    {
      if ( v5 < v6 || pAABB1->m_endpts[0] > pAABB2->m_endpts[1] || pAABB1->m_endpts[3] < pAABB2->m_endpts[2] )
        return 1;
      v3 = pAABB1->m_endpts[2];
      v4 = pAABB2->m_endpts[3];
    }
  }
  else
  {
    if ( pAABB1->m_endpts[3] < pAABB2->m_endpts[2]
      || pAABB1->m_endpts[2] > pAABB2->m_endpts[3]
      || pAABB1->m_endpts[5] < pAABB2->m_endpts[4] )
    {
      return 1;
    }
    v3 = pAABB1->m_endpts[4];
    v4 = pAABB2->m_endpts[5];
  }
  v8 = v3 <= v4;
  v7 = 0;
  if ( !v8 )
    return 1;
  return v7;
}


// ========================================================================
// ?Draw@NBody@bfx@@QAAXPBVSpace@2@ABVColor@2@@Z
// EA  : 0x8329B670
// RVA : 0x0129B670
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

void __fastcall bfx::NBody::Draw(bfx::NBody *this, const bfx::Space *pSpace, const bfx::Color *color)
{
  int m_size; // r9
  int m_i; // r11
  bfx::NBody *m_nbody; // r10
  bfx::NBody::cursor v8; // [sp+50h] [-20h] BYREF

  m_size = this->m_endpts.m_x.m_size;
  m_i = 0;
  m_nbody = this;
  v8.m_nbody = this;
  v8.m_i = 0;
  if ( m_size > 0 )
  {
    do
    {
      bfx::AABB::DrawBox(this: m_nbody->m_endpts.m_x.m_data[m_i].m_pAABB, pSpace, color);
      bfx::NBody::cursor::operator++(this: &v8);
      m_nbody = (bfx::NBody *)v8.m_nbody;
      m_i = v8.m_i;
    }
    while ( v8.m_i < v8.m_nbody->m_endpts.m_x.m_size );
  }
}


// ========================================================================
// ?RemoveOverlap@AABB@bfx@@QAA_NPAV12@@Z
// EA  : 0x8329B700
// RVA : 0x0129B700
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

int __fastcall bfx::AABB::RemoveOverlap(bfx::AABB *this, bfx::AABB *pOtherAABB)
{
  bfx::Array<bfx::AABB *> *p_m_overlaps; // r31
  bfx::AABB **m_data; // r11
  bfx::AABB **v4; // r10
  int m_size; // r11
  int v7; // r30

  p_m_overlaps = &this->m_overlaps;
  m_data = this->m_overlaps.m_data;
  v4 = &m_data[this->m_overlaps.m_size];
  if ( m_data == v4 )
    return 0;
  while ( *m_data != pOtherAABB )
  {
    if ( ++m_data == v4 )
      return 0;
  }
  *m_data = *(v4 - 1);
  m_size = this->m_overlaps.m_size;
  v7 = m_size - 1;
  if ( m_size - 1 > m_size )
  {
    if ( v7 > this->m_overlaps.m_cap )
    {
      bfx::Array<bfx::Edge *>::expand_cap(
        this: (bfx::Array<bfx::SpaceComponent *> *)&this->m_overlaps,
        size: m_size - 1);
      p_m_overlaps->m_size = v7;
      return 1;
    }
  }
  else if ( m_size - 1 >= m_size )
  {
    return 1;
  }
  this->m_overlaps.m_size = v7;
  return 1;
}


// ========================================================================
// ?MoveEndPtDown@bfx@@YAXPAVEndPt@1@0@Z
// EA  : 0x8329B7B8
// RVA : 0x0129B7B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

void __fastcall bfx::MoveEndPtDown(bfx::AABB **pEndPt, bfx::AABB **pFirstEndPt)
{
  bfx::AABB **v3; // r31
  bfx::EndPt *v4; // r28
  char *v5; // r27
  int v6; // r11
  bfx::AABB *v7; // r30
  int v8; // r26
  bfx::AABB *v9; // r29
  bfx::Array<bfx::Space *> *p_m_overlaps; // r3
  bfx::AABB *v11; // r5
  bfx::EndPtType v12; // r4
  float v13; // r11
  bfx::Space *v14[20]; // [sp+50h] [-50h] BYREF

  if ( pEndPt > pFirstEndPt )
  {
    v3 = pEndPt - 2;
    do
    {
      v4 = (bfx::EndPt *)(v3 + 2);
      v5 = (char *)(v3 - 1);
      if ( *((float *)v3 + 2) >= (double)*((float *)v3 - 1) )
        break;
      v6 = (int)v3[1];
      if ( (((unsigned int)v3[4] ^ v6) & 1) != 0 )
      {
        v7 = v3[3];
        v8 = v6 >> 1;
        v9 = *v3;
        if ( (unsigned __int8)bfx::DisjointOnOtherAxes(pAABB1: *v3, pAABB2: v7, axis: v6 >> 1) == 0 )
        {
          if ( (unsigned __int8)bfx::DisjointOnAxis(pAABB1: v9, pAABB2: v7, axis: v8) != 0 )
          {
            if ( (unsigned __int8)bfx::AABB::RemoveOverlap(this: v9, pOtherAABB: v7) != 0 )
              bfx::AABB::RemoveOverlap(this: v3[3], pOtherAABB: *v3);
          }
          else
          {
            v14[0] = (bfx::Space *)v7;
            bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&v9->m_overlaps, val: v14);
            p_m_overlaps = (bfx::Array<bfx::Space *> *)&v3[3]->m_overlaps;
            v14[0] = (bfx::Space *)*v3;
            bfx::Array<bfx::Portal *>::push_back(this: p_m_overlaps, val: v14);
          }
        }
      }
      (*v3)->m_endpts[(_DWORD)v3[1]] = v4;
      v3[3]->m_endpts[(_DWORD)v3[4]] = (bfx::EndPt *)v5;
      v3 -= 3;
      v11 = *((bfx::AABB **)v5 + 1);
      v12 = *((_DWORD *)v5 + 2);
      v13 = *(float *)v5;
      *(float *)v5 = v4->m_val;
      *((_DWORD *)v5 + 1) = v4->m_pAABB;
      *((_DWORD *)v5 + 2) = v4->m_type;
      v4->m_val = v13;
      v4->m_pAABB = v11;
      v4->m_type = v12;
    }
    while ( v3 + 2 > pFirstEndPt );
  }
}


// ========================================================================
// ?MoveEndPtUp@bfx@@YAXPAVEndPt@1@0@Z
// EA  : 0x8329B900
// RVA : 0x0129B900
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

void __fastcall bfx::MoveEndPtUp(bfx::EndPt *pEndPt, bfx::EndPt *pLastEndPt)
{
  float *p_m_pAABB; // r31
  char *v4; // r28
  char *v5; // r27
  int v6; // r11
  bfx::AABB *v7; // r30
  int v8; // r26
  int v9; // r29
  bfx::Array<bfx::Space *> *v10; // r3
  int v11; // r5
  int v12; // r4
  int v13; // r11
  bfx::Space *v14[20]; // [sp+50h] [-50h] BYREF

  if ( pEndPt < pLastEndPt )
  {
    p_m_pAABB = (float *)&pEndPt[1].m_pAABB;
    do
    {
      v4 = (char *)(p_m_pAABB - 4);
      v5 = (char *)(p_m_pAABB - 1);
      if ( *(p_m_pAABB - 4) <= (double)*(p_m_pAABB - 1) )
        break;
      v6 = *((_DWORD *)p_m_pAABB - 2);
      if ( ((*((_DWORD *)p_m_pAABB + 1) ^ v6) & 1) != 0 )
      {
        v7 = *(bfx::AABB **)p_m_pAABB;
        v8 = v6 >> 1;
        v9 = *((_DWORD *)p_m_pAABB - 3);
        if ( (unsigned __int8)bfx::DisjointOnOtherAxes(
                                pAABB1: (bfx::AABB *)v9,
                                pAABB2: *(bfx::AABB **)p_m_pAABB,
                                axis: v6 >> 1) == 0 )
        {
          if ( (unsigned __int8)bfx::DisjointOnAxis(pAABB1: (bfx::AABB *)v9, pAABB2: v7, axis: v8) != 0 )
          {
            if ( (unsigned __int8)bfx::AABB::RemoveOverlap(this: (bfx::AABB *)v9, pOtherAABB: v7) != 0 )
              bfx::AABB::RemoveOverlap(this: *(bfx::AABB **)p_m_pAABB, pOtherAABB: *((bfx::AABB **)p_m_pAABB - 3));
          }
          else
          {
            v14[0] = (bfx::Space *)v7;
            bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)(v9 + 24), val: v14);
            v10 = (bfx::Array<bfx::Space *> *)(*(_DWORD *)p_m_pAABB + 24);
            v14[0] = *((bfx::Space **)p_m_pAABB - 3);
            bfx::Array<bfx::Portal *>::push_back(this: v10, val: v14);
          }
        }
      }
      *(_DWORD *)(4 * *((_DWORD *)p_m_pAABB - 2) + *((_DWORD *)p_m_pAABB - 3)) = v5;
      *(_DWORD *)(4 * *((_DWORD *)p_m_pAABB + 1) + *(_DWORD *)p_m_pAABB) = v4;
      p_m_pAABB += 3;
      v11 = *((_DWORD *)v4 + 1);
      v12 = *((_DWORD *)v4 + 2);
      v13 = *(_DWORD *)v4;
      *(_DWORD *)v4 = *(_DWORD *)v5;
      *((_DWORD *)v4 + 1) = *((_DWORD *)v5 + 1);
      *((_DWORD *)v4 + 2) = *((_DWORD *)v5 + 2);
      *(_DWORD *)v5 = v13;
      *((_DWORD *)v5 + 1) = v11;
      *((_DWORD *)v5 + 2) = v12;
    }
    while ( p_m_pAABB - 4 < (float *)pLastEndPt );
  }
}


// ========================================================================
// ??1NBody@bfx@@QAA@XZ
// EA  : 0x8329BB38
// RVA : 0x0129BB38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

// attributes: thunk
void __fastcall bfx::NBody::~NBody(bfx::NBody *this)
{
  bfx::NBodyEndpts::~NBodyEndpts(this: &this->m_endpts);
}


// ========================================================================
// ?MoveAABB@NBody@bfx@@QAAXPAVAABB@2@ABVBox@2@@Z
// EA  : 0x8329BB40
// RVA : 0x0129BB40
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

void __fastcall bfx::NBody::MoveAABB(bfx::NBody *this, bfx::AABB *pAABB, const bfx::Box *box)
{
  int v6; // r23
  bfx::EndPt *v7; // r30
  bfx::EndPt *v8; // r28
  bfx::EndPt *v9; // r10
  char v10; // r11
  char v11; // r9
  char v12; // r11
  char v13; // r26
  char v14; // r11
  char v15; // r27
  char v16; // r11
  char v17; // r29

  v6 = 3;
  do
  {
    v7 = pAABB->m_endpts[0];
    v8 = pAABB->m_endpts[1];
    v9 = &this->m_endpts.m_x.m_data[this->m_endpts.m_x.m_size - 1];
    if ( pAABB->m_endpts[0] <= this->m_endpts.m_x.m_data || (v10 = 1, box->m_min.m_x >= (double)v7[-1].m_val) )
      v10 = 0;
    v11 = v10;
    if ( v7 >= v9 || (v12 = 1, box->m_min.m_x <= (double)v7[1].m_val) )
      v12 = 0;
    v13 = v12;
    if ( v8 <= this->m_endpts.m_x.m_data || (v14 = 1, box->m_max.m_x >= (double)v8[-1].m_val) )
      v14 = 0;
    v15 = v14;
    if ( v8 >= v9 || (v16 = 1, box->m_max.m_x <= (double)v8[1].m_val) )
      v16 = 0;
    v7->m_val = box->m_min.m_x;
    v17 = v16;
    v8->m_val = box->m_max.m_x;
    if ( v11 != 0 )
      bfx::MoveEndPtDown(pEndPt: (bfx::AABB **)v7, pFirstEndPt: (bfx::AABB **)this->m_endpts.m_x.m_data);
    if ( v17 != 0 )
      bfx::MoveEndPtUp(pEndPt: v8, pLastEndPt: &this->m_endpts.m_x.m_data[this->m_endpts.m_x.m_size - 1]);
    if ( v13 != 0 )
      bfx::MoveEndPtUp(pEndPt: v7, pLastEndPt: &this->m_endpts.m_x.m_data[this->m_endpts.m_x.m_size - 1]);
    if ( v15 != 0 )
      bfx::MoveEndPtDown(pEndPt: (bfx::AABB **)v8, pFirstEndPt: (bfx::AABB **)this->m_endpts.m_x.m_data);
    --v6;
    pAABB = (bfx::AABB *)((char *)pAABB + 8);
    box = (const bfx::Box *)((char *)box + 4);
    this = (bfx::NBody *)((char *)this + 16);
  }
  while ( v6 != 0 );
}


// ========================================================================
// ??0NBody@bfx@@QAA@XZ
// EA  : 0x8329BCD0
// RVA : 0x0129BCD0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

bfx::NBody *__fastcall bfx::NBody::NBody(bfx::NBody *this)
{
  bfx::bfxMemTag v1; // r10
  bfx::bfxMemTag v2; // r10
  bfx::bfxMemTag v3; // r10

  v1 = bfx::MEM_NBODY_ENDPTS;
  this->m_endpts.m_x.m_data = nullptr;
  this->m_endpts.m_x.m_size = 0;
  this->m_endpts.m_x.m_cap = 0;
  this->m_endpts.m_x.m_tag = v1;
  v2 = bfx::MEM_NBODY_ENDPTS;
  this->m_endpts.m_y.m_data = nullptr;
  this->m_endpts.m_y.m_size = 0;
  this->m_endpts.m_y.m_cap = 0;
  this->m_endpts.m_y.m_tag = v2;
  v3 = bfx::MEM_NBODY_ENDPTS;
  this->m_endpts.m_z.m_data = nullptr;
  this->m_endpts.m_z.m_size = 0;
  this->m_endpts.m_z.m_cap = 0;
  this->m_endpts.m_z.m_tag = v3;
  return this;
}


// ========================================================================
// ?CreateAABB@NBody@bfx@@QAAPAVAABB@2@ABVBox@2@PAX@Z
// EA  : 0x8329BD18
// RVA : 0x0129BD18
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

bfx::AABB *__fastcall bfx::NBody::CreateAABB(bfx::NBody *this, const bfx::Box *box, void *pUserData)
{
  bfx::EndPt *m_data; // r26
  bfx::EndPt *v4; // r22
  bfx::EndPt *v6; // r21
  bfx::Array<bfx::EndPt> *p_m_y; // r29
  bfx::Array<bfx::EndPt> *p_m_z; // r28
  bfx::AABB *v11; // r3
  bfx::AABB *v12; // r31
  bfx::bfxMemTag v13; // r11
  bfx::EndPtType v14; // r27
  int v15; // r9
  int v16; // r10
  bfx::EndPt *v17; // r11
  int v18; // r9
  int v19; // r10
  bfx::EndPt *v20; // r11
  int v21; // r9
  int v22; // r10
  bfx::EndPt *v23; // r11
  float *p_m_val; // r8
  bfx::EndPt *v25; // r7
  float *v26; // r6
  float *v27; // r7
  float *v28; // r11
  int m_size; // r9
  bfx::EndPt *v30; // r10
  float *v31; // r8
  float *v32; // r7
  bfx::EndPt v34; // [sp+50h] [-70h] BYREF

  m_data = this->m_endpts.m_x.m_data;
  v4 = this->m_endpts.m_y.m_data;
  v6 = this->m_endpts.m_z.m_data;
  p_m_y = &this->m_endpts.m_y;
  p_m_z = &this->m_endpts.m_z;
  v11 = (bfx::AABB *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 0x2Cu,
                       tag: bfx::MEM_NBODY);
  if ( v11 != nullptr )
  {
    v12 = v11;
    v13 = bfx::MEM_NBODY_PAIRS;
    v11->m_overlaps.m_data = nullptr;
    v11->m_overlaps.m_size = 0;
    v11->m_overlaps.m_cap = 0;
    v11->m_overlaps.m_tag = v13;
    v11->m_pUserData = pUserData;
  }
  else
  {
    v12 = nullptr;
  }
  v34.m_pAABB = v12;
  v14 = MIN_X_ENDPT;
  v34.m_val = 3.4028235e38;
  do
  {
    v34.m_type = v14;
    bfx::Array<bfx::FollowerBuddyData>::push_back(
      this: (bfx::Array<bfx::EndPt> *)((char *)&this->m_endpts.m_x + ((8 * v14++) & 0xFFFFFFF0)),
      val: &v34);
  }
  while ( v14 < NUM_ENDPT_TYPES );
  if ( this->m_endpts.m_x.m_data != m_data )
  {
    v15 = 0;
    if ( this->m_endpts.m_x.m_size > 0 )
    {
      v16 = 0;
      do
      {
        ++v15;
        v17 = &this->m_endpts.m_x.m_data[v16++];
        v17->m_pAABB->m_endpts[v17->m_type] = v17;
      }
      while ( v15 < this->m_endpts.m_x.m_size );
    }
  }
  if ( p_m_y->m_data != v4 )
  {
    v18 = 0;
    if ( p_m_y->m_size > 0 )
    {
      v19 = 0;
      do
      {
        ++v18;
        v20 = &p_m_y->m_data[v19++];
        v20->m_pAABB->m_endpts[v20->m_type] = v20;
      }
      while ( v18 < p_m_y->m_size );
    }
  }
  if ( p_m_z->m_data != v6 )
  {
    v21 = 0;
    if ( p_m_z->m_size > 0 )
    {
      v22 = 0;
      do
      {
        ++v21;
        v23 = &p_m_z->m_data[v22++];
        v23->m_pAABB->m_endpts[v23->m_type] = v23;
      }
      while ( v21 < p_m_z->m_size );
    }
  }
  v12->m_endpts[0] = &this->m_endpts.m_x.m_data[this->m_endpts.m_x.m_size - 2];
  p_m_val = &v12->m_endpts[0]->m_val;
  v25 = &this->m_endpts.m_x.m_data[this->m_endpts.m_x.m_size - 1];
  v12->m_endpts[1] = v25;
  v26 = &v25->m_val;
  v12->m_endpts[2] = &p_m_y->m_data[this->m_endpts.m_y.m_size - 2];
  v27 = &v12->m_endpts[2]->m_val;
  v28 = &p_m_y->m_data[this->m_endpts.m_y.m_size - 1].m_val;
  v12->m_endpts[3] = (bfx::EndPt *)v28;
  v12->m_endpts[4] = &p_m_z->m_data[this->m_endpts.m_z.m_size - 2];
  m_size = this->m_endpts.m_z.m_size;
  v30 = p_m_z->m_data;
  *p_m_val = 3.4028235e38;
  v31 = &v12->m_endpts[4]->m_val;
  *v26 = 3.4028235e38;
  *v27 = 3.4028235e38;
  *v28 = 3.4028235e38;
  *v31 = 3.4028235e38;
  v32 = &v30[m_size - 1].m_val;
  v12->m_endpts[5] = (bfx::EndPt *)v32;
  *v32 = 3.4028235e38;
  bfx::NBody::MoveAABB(this, pAABB: v12, box);
  return v12;
}


// ========================================================================
// ?DestroyAABB@NBody@bfx@@QAAXPAVAABB@2@@Z
// EA  : 0x8329BFC0
// RVA : 0x0129BFC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

void __fastcall bfx::NBody::DestroyAABB(bfx::NBody *this, bfx::AABB *pAABB)
{
  bfx::Array<bfx::AABB *> *p_m_overlaps; // r26
  int v5; // r31
  int v6; // r30
  int v7; // r30
  bfx::EndPt **v8; // r29
  _DWORD *v9; // r31
  unsigned int v10; // r11
  int *p_m_size; // r8
  int i; // ctr
  int v13; // r9
  int v14; // r10
  int v15; // r11
  char *m_data; // r4

  if ( pAABB != nullptr )
  {
    p_m_overlaps = &pAABB->m_overlaps;
    v5 = 0;
    if ( pAABB->m_overlaps.m_size > 0 )
    {
      v6 = 0;
      do
      {
        bfx::AABB::RemoveOverlap(this: p_m_overlaps->m_data[v6], pOtherAABB: pAABB);
        ++v5;
        ++v6;
      }
      while ( v5 < p_m_overlaps->m_size );
    }
    v7 = 5;
    v8 = &pAABB->m_endpts[5];
    do
    {
      v9 = (bfx::EndPt **)((char *)&this->m_endpts.m_x.m_data + ((8 * v7) & 0xFFFFFFF0));
      v10 = 12 * v9[1] + *v9 - 12;
      if ( (unsigned int)*v8 < v10 )
        blkmov(a1: *v8, a2: &(*v8)[1], a3: 12 * ((v10 - (unsigned int)*v8 - 1) / 0xC + 1));
      --v7;
      --v8;
      --v9[1];
    }
    while ( v7 >= 0 );
    p_m_size = &this->m_endpts.m_x.m_size;
    for ( i = 3; i != 0; --i )
    {
      v13 = 0;
      if ( *p_m_size > 0 )
      {
        v14 = 0;
        do
        {
          ++v13;
          v15 = *(p_m_size - 1) + v14;
          v14 += 12;
          *(_DWORD *)(4 * *(_DWORD *)(v15 + 8) + *(_DWORD *)(v15 + 4)) = v15;
        }
        while ( v13 < *p_m_size );
      }
      p_m_size += 4;
    }
    m_data = (char *)p_m_overlaps->m_data;
    p_m_overlaps->m_size = 0;
    if ( m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
      p_m_overlaps->m_data = nullptr;
    }
    p_m_overlaps->m_cap = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)pAABB);
  }
}


// ========================================================================
// bfx::`dynamic initializer for 'MEM_NBODY''
// EA  : 0x83399140
// RVA : 0x01399140
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_NBODY__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "NBody");
  bfx::MEM_NBODY = result;
  return result;
}


// ========================================================================
// bfx::`dynamic initializer for 'MEM_NBODY_ENDPTS''
// EA  : 0x83399170
// RVA : 0x01399170
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_NBODY_ENDPTS__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "NBody endpts");
  bfx::MEM_NBODY_ENDPTS = result;
  return result;
}


// ========================================================================
// bfx::`dynamic initializer for 'MEM_NBODY_PAIRS''
// EA  : 0x833991A0
// RVA : 0x013991A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxnbody.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_NBODY_PAIRS__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "NBody pairs");
  bfx::MEM_NBODY_PAIRS = result;
  return result;
}

