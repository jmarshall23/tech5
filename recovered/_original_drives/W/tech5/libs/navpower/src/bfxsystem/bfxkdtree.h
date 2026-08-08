
// ========================================================================
// ?TraverseToNextLeaf@PrimsInSphereCursor@KDTree@bfx@@AAAXXZ
// EA  : 0x832726E8
// RVA : 0x012726E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.h
// ========================================================================

void __fastcall bfx::KDTree::PrimsInSphereCursor::TraverseToNextLeaf(bfx::KDTree::PrimsInSphereCursor *this)
{
  bfx::KDNode **v1; // r10
  bfx::KDNode *v2; // r11
  int m_data; // r9
  int v4; // r9
  double m_radius; // fp0

  if ( this->m_pNextNode <= this->m_nodeStack )
  {
LABEL_8:
    this->m_atEnd = true;
  }
  else
  {
    while ( 1 )
    {
      v1 = this->m_pNextNode - 1;
      this->m_pNextNode = v1;
      v2 = *v1;
      m_data = (*v1)->m_data;
      if ( m_data < 0 )
        break;
      v4 = ((unsigned int)m_data >> 26) & 0x1C;
      m_radius = this->m_sphereLCoord.m_radius;
      if ( (float)(*(float *)((char *)&this->m_sphereLCoord.m_pos.m_x + v4) - v2->m_dLeft) < m_radius )
      {
        *v1 = v2 + 1;
        ++this->m_pNextNode;
      }
      if ( (float)(v2->m_dRight - *(float *)((char *)&this->m_sphereLCoord.m_pos.m_x + v4)) < m_radius )
        *this->m_pNextNode++ = (bfx::KDNode *)((char *)v2 + (v2->m_data & 0xFFFFFFF));
      if ( this->m_pNextNode <= this->m_nodeStack )
        goto LABEL_8;
    }
  }
}


// ========================================================================
// ??0PrimsInSphereCursor@KDTree@bfx@@QAA@ABVSphere@2@ABV12@@Z
// EA  : 0x832733B8
// RVA : 0x012733B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.h
// ========================================================================

bfx::KDTree::PrimsInSphereCursor *__fastcall bfx::KDTree::PrimsInSphereCursor::PrimsInSphereCursor(
        bfx::KDTree::PrimsInSphereCursor *this,
        const bfx::Sphere *sphere,
        const bfx::KDTree *kdtree)
{
  double m_radius; // fp31
  bfx::Matrix *v6; // r3
  float v7; // r6
  char v9; // [sp+50h] [-30h] BYREF

  m_radius = sphere->m_radius;
  v6 = bfx::Matrix::operator*(
         this: (bfx::Matrix *)&v9,
         result: (bfx::Vec3 *)&kdtree->m_worldToLocal,
         rhs: &sphere->m_pos);
  this->m_sphereLCoord.m_pos.m_x = v6->m_data[0];
  this->m_sphereLCoord.m_pos.m_y = v6->m_data[1];
  v7 = v6->m_data[2];
  this->m_sphereLCoord.m_radius = m_radius;
  this->m_sphereLCoord.m_pos.m_z = v7;
  this->m_atEnd = false;
  this->m_nodeStack[0] = kdtree->m_pRoot;
  this->m_pNextNode = &this->m_nodeStack[1];
  bfx::KDTree::PrimsInSphereCursor::TraverseToNextLeaf(this);
  return this;
}


// ========================================================================
// ??$CollideLineSegment@VAreaCollider@bfx@@@KDTree@bfx@@QAA_NABVVec3@1@0ABVAreaCollider@1@AAM@Z
// EA  : 0x83273EB8
// RVA : 0x01273EB8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.h
// ========================================================================

int __fastcall bfx::KDTree::CollideLineSegment<bfx::AreaCollider>(
        bfx::KDTree *this,
        const bfx::Vec3 *startWCoord,
        const bfx::Vec3 *deltaWCoord,
        bfx::AreaCollider *primCollider,
        float *time)
{
  bfx::Vec3 *p_m_worldToLocal; // r31
  double v11; // fp9
  double v12; // fp8
  int v13; // r29
  float *v14; // r31
  double v15; // fp4
  float *v16; // r11
  int v17; // r10
  char v18; // r3
  double v19; // fp8
  double v20; // fp3
  int v21; // r9
  double v22; // fp12
  double v23; // fp11
  double v24; // fp0
  double v25; // fp13
  _DWORD *v26; // r11
  float v28; // [sp+50h] [-480h] BYREF
  float v29; // [sp+54h] [-47Ch]
  float v30; // [sp+58h] [-478h]
  bfx::Matrix v31[16]; // [sp+60h] [-470h] BYREF

  p_m_worldToLocal = (bfx::Vec3 *)&this->m_worldToLocal;
  bfx::Matrix::operator*(this: v31, result: (bfx::Vec3 *)&this->m_worldToLocal, rhs: startWCoord);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&v31[0].m_data[4], result: p_m_worldToLocal, rhs: deltaWCoord);
  v11 = (float)(v31[0].m_data[5] * *time);
  v12 = (float)(v31[0].m_data[6] * *time);
  v13 = 0;
  v14 = &v31[0].m_data[9];
  v15 = (float)(v31[0].m_data[0] + (float)(v31[0].m_data[4] * *time));
  LODWORD(v31[0].m_data[8]) = this->m_pRoot;
  v28 = v15;
  v29 = v31[0].m_data[1] + (float)v11;
  v30 = v31[0].m_data[2] + (float)v12;
  do
  {
    v16 = *(float **)--v14;
    v17 = **(_DWORD **)v14;
    if ( v17 >= 0 )
    {
      v21 = ((unsigned int)v17 >> 26) & 0x1C;
      v22 = v16[1];
      v23 = v16[2];
      v24 = (float)(v16[1] - *(float *)((char *)v31[0].m_data + v21));
      v25 = (float)(*(float *)((char *)v31[0].m_data + v21) - v16[2]);
      if ( v24 >= v25 )
      {
        if ( v25 >= 0.0 || *(float *)((char *)&v28 + v21) >= v23 )
          *(_DWORD *)v14++ = (char *)v16 + (v17 & 0xFFFFFFF);
        if ( v24 >= 0.0 || *(float *)((char *)&v28 + v21) <= v22 )
        {
          v26 = v16 + 3;
          goto LABEL_18;
        }
      }
      else
      {
        if ( v24 >= 0.0 || *(float *)((char *)&v28 + v21) <= v22 )
          *(_DWORD *)v14++ = v16 + 3;
        if ( v25 >= 0.0 || *(float *)((char *)&v28 + v21) >= v23 )
        {
          v26 = (_DWORD *)((char *)v16 + (v17 & 0xFFFFFFF));
LABEL_18:
          *(_DWORD *)v14++ = v26;
        }
      }
    }
    else
    {
      v18 = bfx::AreaCollider::CollideLineSegmentAndPrim(
              this: primCollider,
              start: startWCoord,
              dir: deltaWCoord,
              primOffset: v17 & 0x7FFFFFFF,
              collideDist: time);
      v13 = (unsigned __int8)(v13 | v18);
      if ( v18 != 0 )
      {
        v19 = (float)(v31[0].m_data[6] * *time);
        v20 = (float)((float)(v31[0].m_data[5] * *time) + v31[0].m_data[1]);
        v28 = (float)(v31[0].m_data[4] * *time) + v31[0].m_data[0];
        v29 = v20;
        v30 = (float)v19 + v31[0].m_data[2];
      }
    }
  }
  while ( v14 > &v31[0].m_data[8] );
  return v13;
}


// ========================================================================
// ??$ProcessClosestPrims@V?$ClosestAreasProcessor@VPathSpec@bfx@@@bfx@@@KDTree@bfx@@QAAXABVVec3@1@AAV?$ClosestAreasProcessor@VPathSpec@bfx@@@1@@Z
// EA  : 0x8327D798
// RVA : 0x0127D798
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.h
// ========================================================================

void __fastcall bfx::KDTree::ProcessClosestPrims<bfx::ClosestAreasProcessor<bfx::PathSpec>>(
        bfx::KDTree *this,
        const bfx::Vec3 *posWCoord,
        bfx::ClosestAreasProcessor<bfx::PathSpec> *primProcessor)
{
  bfx::Matrix *v6; // r8
  int v7; // r7
  int v8; // r6
  float *v9; // r31
  int v10; // r11
  double m_considerationDist; // fp11
  double v12; // fp12
  unsigned int v13; // r10
  int v14; // r9
  double v15; // fp0
  double v16; // fp13
  int v20; // r11
  bfx::Matrix v26[33]; // [sp+50h] [-840h] BYREF

  bfx::Matrix::operator*(this: v26, result: (bfx::Vec3 *)&this->m_worldToLocal, rhs: posWCoord);
  v9 = &v26[0].m_data[6];
  LODWORD(v26[0].m_data[4]) = this->m_pRoot;
  v26[0].m_data[5] = 0.0;
  do
  {
    v9 -= 2;
    v10 = *(_DWORD *)v9;
    m_considerationDist = primProcessor->m_considerationDist;
    v12 = v9[1];
    if ( v12 >= m_considerationDist )
      continue;
    v13 = *(_DWORD *)v10;
    if ( *(int *)v10 < 0 )
    {
      bfx::ClosestAreasProcessor<bfx::PathSpec>::ProcessPrim(
        this: primProcessor,
        primOffset: v13 & 0x7FFFFFFF,
        pos: posWCoord,
        a4: v8,
        a5: v7,
        a6: (int)v6,
        a7: *(_DWORD *)v10 >> 31,
        a8: v13);
      continue;
    }
    v14 = (v13 >> 26) & 0x1C;
    v6 = v26;
    v15 = (float)(*(float *)((char *)v26[0].m_data + v14) - *(float *)(v10 + 4));
    v16 = (float)(*(float *)(v10 + 8) - *(float *)((char *)v26[0].m_data + v14));
    if ( v15 <= v16 )
    {
      if ( v16 < m_considerationDist )
      {
        _FP10 = (float)(v9[1] - (float)(*(float *)(v10 + 8) - *(float *)((char *)v26[0].m_data + v14)));
        *(_DWORD *)v9 = (v13 & 0xFFFFFFF) + v10;
        __asm { fsel      f9, f10, f12, f13 }
        v9[1] = _FP9;
        v9 += 2;
      }
      if ( v15 < m_considerationDist )
      {
        _FP13 = (float)((float)v12 - (float)v15);
        v20 = v10 + 12;
        __asm { fsel      f12, f13, f12, f0 }
        v9[1] = _FP12;
        goto LABEL_14;
      }
    }
    else
    {
      if ( v15 < m_considerationDist )
      {
        _FP10 = (float)(v9[1] - (float)(*(float *)((char *)v26[0].m_data + v14) - *(float *)(v10 + 4)));
        *(_DWORD *)v9 = v10 + 12;
        __asm { fsel      f9, f10, f12, f0 }
        v9[1] = _FP9;
        v9 += 2;
      }
      if ( v16 < m_considerationDist )
      {
        _FP0 = (float)((float)v12 - (float)v16);
        v20 = (v13 & 0xFFFFFFF) + v10;
        __asm { fsel      f13, f0, f12, f13 }
        v9[1] = _FP13;
LABEL_14:
        *(_DWORD *)v9 = v20;
        v9 += 2;
      }
    }
  }
  while ( v9 > &v26[0].m_data[4] );
}


// ========================================================================
// ??$ProcessClosestPrims@V?$ClosestAreasProcessor@VIncrementalIRT@bfx@@@bfx@@@KDTree@bfx@@QAAXABVVec3@1@AAV?$ClosestAreasProcessor@VIncrementalIRT@bfx@@@1@@Z
// EA  : 0x8327D8D0
// RVA : 0x0127D8D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.h
// ========================================================================

void __fastcall bfx::KDTree::ProcessClosestPrims<bfx::ClosestAreasProcessor<bfx::IncrementalIRT>>(
        bfx::KDTree *this,
        const bfx::Vec3 *posWCoord,
        bfx::ClosestAreasProcessor<bfx::IncrementalIRT> *primProcessor)
{
  bfx::Matrix *v6; // r8
  int v7; // r7
  int v8; // r6
  float *v9; // r31
  int v10; // r11
  double m_considerationDist; // fp11
  double v12; // fp12
  unsigned int v13; // r10
  int v14; // r9
  double v15; // fp0
  double v16; // fp13
  int v20; // r11
  bfx::Matrix v26[33]; // [sp+50h] [-840h] BYREF

  bfx::Matrix::operator*(this: v26, result: (bfx::Vec3 *)&this->m_worldToLocal, rhs: posWCoord);
  v9 = &v26[0].m_data[6];
  LODWORD(v26[0].m_data[4]) = this->m_pRoot;
  v26[0].m_data[5] = 0.0;
  do
  {
    v9 -= 2;
    v10 = *(_DWORD *)v9;
    m_considerationDist = primProcessor->m_considerationDist;
    v12 = v9[1];
    if ( v12 >= m_considerationDist )
      continue;
    v13 = *(_DWORD *)v10;
    if ( *(int *)v10 < 0 )
    {
      bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ProcessPrim(
        this: primProcessor,
        primOffset: v13 & 0x7FFFFFFF,
        pos: posWCoord,
        a4: v8,
        a5: v7,
        a6: (int)v6,
        a7: *(_DWORD *)v10 >> 31,
        a8: v13);
      continue;
    }
    v14 = (v13 >> 26) & 0x1C;
    v6 = v26;
    v15 = (float)(*(float *)((char *)v26[0].m_data + v14) - *(float *)(v10 + 4));
    v16 = (float)(*(float *)(v10 + 8) - *(float *)((char *)v26[0].m_data + v14));
    if ( v15 <= v16 )
    {
      if ( v16 < m_considerationDist )
      {
        _FP10 = (float)(v9[1] - (float)(*(float *)(v10 + 8) - *(float *)((char *)v26[0].m_data + v14)));
        *(_DWORD *)v9 = (v13 & 0xFFFFFFF) + v10;
        __asm { fsel      f9, f10, f12, f13 }
        v9[1] = _FP9;
        v9 += 2;
      }
      if ( v15 < m_considerationDist )
      {
        _FP13 = (float)((float)v12 - (float)v15);
        v20 = v10 + 12;
        __asm { fsel      f12, f13, f12, f0 }
        v9[1] = _FP12;
        goto LABEL_14;
      }
    }
    else
    {
      if ( v15 < m_considerationDist )
      {
        _FP10 = (float)(v9[1] - (float)(*(float *)((char *)v26[0].m_data + v14) - *(float *)(v10 + 4)));
        *(_DWORD *)v9 = v10 + 12;
        __asm { fsel      f9, f10, f12, f0 }
        v9[1] = _FP9;
        v9 += 2;
      }
      if ( v16 < m_considerationDist )
      {
        _FP0 = (float)((float)v12 - (float)v16);
        v20 = (v13 & 0xFFFFFFF) + v10;
        __asm { fsel      f13, f0, f12, f13 }
        v9[1] = _FP13;
LABEL_14:
        *(_DWORD *)v9 = v20;
        v9 += 2;
      }
    }
  }
  while ( v9 > &v26[0].m_data[4] );
}

