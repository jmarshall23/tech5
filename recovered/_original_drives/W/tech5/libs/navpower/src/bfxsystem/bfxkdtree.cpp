
// ========================================================================
// ?EndianSwap@KDTreeData@bfx@@QAAXXZ
// EA  : 0x832C3190
// RVA : 0x012C3190
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::KDTreeData::EndianSwap(bfx::KDTreeData *this)
{
  char *p_m_treeBase; // r31
  char *v3; // r30

  bfx::EndianSwapBox(box: &this->m_bbox);
  bfx::EndianSwapLong(val: &this->m_size);
  p_m_treeBase = &this->m_treeBase;
  v3 = &this->m_treeBase + this->m_size;
  while ( p_m_treeBase < v3 )
  {
    bfx::EndianSwapLong(val: (unsigned int *)p_m_treeBase);
    if ( *(int *)p_m_treeBase >= 0 )
    {
      bfx::EndianSwapFloat(val: (float *)p_m_treeBase + 1);
      bfx::EndianSwapFloat(val: (float *)p_m_treeBase + 2);
      p_m_treeBase += 12;
    }
    else
    {
      p_m_treeBase += 4;
    }
  }
}


// ========================================================================
// ?Init@KDTree@bfx@@QAAXPAD_NABVMatrix@2@@Z
// EA  : 0x832C3220
// RVA : 0x012C3220
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::KDTree::Init(
        bfx::KDTree *this,
        char *pKDTreeData,
        bool freeDataInDtor,
        const bfx::Matrix *localToWorld)
{
  bfx::Matrix v5; // [sp+50h] [-50h] BYREF

  this->m_freeDataInDtor = freeDataInDtor;
  this->m_pKDTreeData = (bfx::KDTreeData *)pKDTreeData;
  this->m_pRoot = (bfx::KDNode *)(pKDTreeData + 28);
  v5 = *localToWorld;
  bfx::Matrix::OrthoInvert(this: &v5);
  this->m_worldToLocal = v5;
}


// ========================================================================
// ??1KDTree@bfx@@QAA@XZ
// EA  : 0x832C3280
// RVA : 0x012C3280
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::KDTree::~KDTree(bfx::KDTree *this)
{
  if ( this->m_freeDataInDtor )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_pKDTreeData);
  this->m_pKDTreeData = nullptr;
  this->m_pRoot = nullptr;
  this->m_freeDataInDtor = false;
}


// ========================================================================
// ??0DynKDTree@bfx@@QAA@XZ
// EA  : 0x832C32D8
// RVA : 0x012C32D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::DynKDTree *__fastcall bfx::DynKDTree::DynKDTree(bfx::DynKDTree *this)
{
  this->m_pRoot = nullptr;
  bfx::Pool::Pool(this: &this->m_nodePool, nodeSize: 0x28u, numNodes: 0x64u, tag: bfx::MEM_BFXSYSTEM);
  return this;
}


// ========================================================================
// ??1DynKDTree@bfx@@QAA@XZ
// EA  : 0x832C3328
// RVA : 0x012C3328
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::DynKDTree::~DynKDTree(bfx::DynKDTree *this)
{
  bfx::Pool::~Pool(this: &this->m_nodePool);
}


// ========================================================================
// ?TraverseToNextLeaf@PrimsInSphereCursor@DynKDTree@bfx@@AAAXXZ
// EA  : 0x832C3330
// RVA : 0x012C3330
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::DynKDTree::PrimsInSphereCursor::TraverseToNextLeaf(bfx::DynKDTree::PrimsInSphereCursor *this)
{
  bfx::DynKDNode **v1; // r7
  bfx::DynKDNode *v2; // r10
  int v3; // r11
  int v4; // r8
  bfx::DynKDNode *m_pLeft; // r9
  int v6; // r6
  double m_radius; // fp0
  bfx::DynKDNode *m_pRight; // r11

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
      v3 = *(_DWORD *)*v1;
      if ( v3 < 0 )
        break;
      v4 = ((unsigned int)v3 >> 28) & 7;
      m_pLeft = v2->m_pLeft;
      v6 = ((unsigned int)v3 >> 26) & 0x1C;
      m_radius = this->m_sphere.m_radius;
      if ( (float)(*(float *)((char *)&this->m_sphere.m_pos.m_x + v6) - *(&m_pLeft->m_bbox.m_max.m_x + v4)) < m_radius )
      {
        *v1 = m_pLeft;
        ++this->m_pNextNode;
      }
      m_pRight = v2->m_pRight;
      if ( (float)(*(&m_pRight->m_bbox.m_min.m_x + v4) - *(float *)((char *)&this->m_sphere.m_pos.m_x + v6)) < m_radius )
        *this->m_pNextNode++ = m_pRight;
      if ( this->m_pNextNode <= this->m_nodeStack )
        goto LABEL_8;
    }
  }
}


// ========================================================================
// ??DPrimsInSphereCursor@DynKDTree@bfx@@QAAPAXXZ
// EA  : 0x832C33E8
// RVA : 0x012C33E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::DynKDNode *__fastcall bfx::DynKDTree::PrimsInSphereCursor::operator*(bfx::DynKDTree::PrimsInSphereCursor *this)
{
  return (*this->m_pNextNode)->m_pLeft;
}


// ========================================================================
// ??DClosestPrimsCursor@DynKDTree@bfx@@QAAPAXXZ
// EA  : 0x832C33F8
// RVA : 0x012C33F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::DynKDNode *__fastcall bfx::DynKDTree::ClosestPrimsCursor::operator*(bfx::DynKDTree::ClosestPrimsCursor *this)
{
  return this->m_pCurLeaf->m_pLeft;
}


// ========================================================================
// ?TraverseToNextLeaf@CollideLineSegmentCursor@DynKDTree@bfx@@AAAXXZ
// EA  : 0x832C3408
// RVA : 0x012C3408
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::DynKDTree::CollideLineSegmentCursor::TraverseToNextLeaf(
        bfx::DynKDTree::CollideLineSegmentCursor *this)
{
  bfx::DynKDNode **m_nodeStack; // r30
  bfx::DynKDNode **v3; // r8
  bfx::DynKDNode *v4; // r10
  int v5; // r9
  int v6; // r11
  bfx::DynKDNode *m_pRight; // r7
  int v8; // r9
  bfx::DynKDNode *m_pLeft; // r11
  int v10; // r3
  int v11; // r6
  int v12; // r5
  bfx::DynKDNode *v17; // r10

  m_nodeStack = this->m_nodeStack;
  while ( this->m_pNextNode > m_nodeStack )
  {
    v3 = this->m_pNextNode - 1;
    this->m_pNextNode = v3;
    v4 = *v3;
    v5 = *(_DWORD *)*v3;
    if ( v5 < 0 )
    {
      if ( bfx::LineSegIntersectsBox(posAWCoord: &this->m_startPos, posBWCoord: &this->m_endPos, box: &v4->m_bbox) )
        return;
      continue;
    }
    v6 = ((unsigned int)v5 >> 28) & 7;
    m_pRight = v4->m_pRight;
    v8 = ((unsigned int)v5 >> 26) & 0x1C;
    v10 = 4 * (v6 + 7);
    v11 = 4 * (v6 + 3);
    v12 = 4 * (v6 + 4);
    m_pLeft = v4->m_pLeft;
    _FP6 = (float)((float)(*(float *)((char *)m_pLeft + v10) - *(float *)((char *)&this->m_startPos.m_x + v8))
                 - (float)(*(float *)((char *)m_pLeft + v10) - *(float *)((char *)&this->m_startPos.m_x + v11)));
    _FP5 = (float)((float)(*(float *)((char *)&this->m_startPos.m_x + v8) - *(float *)((char *)m_pRight + v12))
                 - (float)(*(float *)((char *)&this->m_startPos.m_x + v11) - *(float *)((char *)m_pRight + v12)));
    __asm
    {
      fsel      f0, f6, f11, f9
      fsel      f13, f5, f8, f7
    }
    if ( (float)(*(float *)((char *)m_pLeft + v10) - *(float *)((char *)&this->m_startPos.m_x + v8)) >= (double)(float)(*(float *)((char *)&this->m_startPos.m_x + v8) - *(float *)((char *)m_pRight + v12)) )
    {
      if ( _FP13 >= 0.0 )
      {
        *v3 = m_pRight;
        ++this->m_pNextNode;
      }
      if ( _FP0 < 0.0 )
        continue;
      v17 = v4->m_pLeft;
    }
    else
    {
      if ( _FP0 >= 0.0 )
      {
        *v3 = m_pLeft;
        ++this->m_pNextNode;
      }
      if ( _FP13 < 0.0 )
        continue;
      v17 = v4->m_pRight;
    }
    *this->m_pNextNode++ = v17;
  }
  this->m_atEnd = true;
}


// ========================================================================
// ??DCollideLineSegmentCursor@DynKDTree@bfx@@QAAPAXXZ
// EA  : 0x832C3570
// RVA : 0x012C3570
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::DynKDNode *__fastcall bfx::DynKDTree::CollideLineSegmentCursor::operator*(
        bfx::DynKDTree::CollideLineSegmentCursor *this)
{
  return (*this->m_pNextNode)->m_pLeft;
}


// ========================================================================
// ?UpdateTreeForNewLeafNodeBBox@DynKDTree@bfx@@QAAXPAVDynKDNode@2@ABVBox@2@@Z
// EA  : 0x832C3580
// RVA : 0x012C3580
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::DynKDTree::UpdateTreeForNewLeafNodeBBox(
        bfx::DynKDTree *this,
        bfx::DynKDNode *pLeafNode,
        const bfx::Box *newBBox)
{
  bfx::DynKDNode *i; // r9
  float *p_m_x; // r11
  char v5; // r10

  for ( i = pLeafNode; i != nullptr; p_m_x[5] = _FP6 )
  {
    p_m_x = &i->m_bbox.m_min.m_x;
    if ( newBBox->m_min.m_x >= (double)i->m_bbox.m_min.m_x
      && newBBox->m_min.m_y >= (double)i->m_bbox.m_min.m_y
      && newBBox->m_min.m_z >= (double)i->m_bbox.m_min.m_z
      && newBBox->m_max.m_x <= (double)i->m_bbox.m_max.m_x
      && newBBox->m_max.m_y <= (double)i->m_bbox.m_max.m_y )
    {
      v5 = 1;
      if ( newBBox->m_max.m_z <= (double)i->m_bbox.m_max.m_z )
        goto LABEL_9;
    }
    v5 = 0;
LABEL_9:
    if ( v5 != 0 )
      break;
    i = i->m_pParent;
    _FP9 = (float)(p_m_x[2] - newBBox->m_min.m_z);
    _FP7 = (float)(p_m_x[1] - newBBox->m_min.m_y);
    _FP6 = (float)(*p_m_x - newBBox->m_min.m_x);
    __asm { fsel      f5, f9, f13, f11 }
    p_m_x[2] = _FP5;
    __asm { fsel      f4, f7, f12, f10 }
    p_m_x[1] = _FP4;
    __asm { fsel      f3, f6, f0, f8 }
    *p_m_x = _FP3;
    _FP8 = (float)(p_m_x[3] - newBBox->m_max.m_x);
    _FP10 = (float)(p_m_x[4] - newBBox->m_max.m_y);
    _FP9 = (float)(p_m_x[5] - newBBox->m_max.m_z);
    __asm { fsel      f5, f8, f1, f2 }
    p_m_x[3] = _FP5;
    __asm { fsel      f7, f10, f11, f12 }
    p_m_x[4] = _FP7;
    __asm { fsel      f6, f9, f13, f0 }
  }
}


// ========================================================================
// ?CalcBBoxForElems@bfx@@YA?AVBox@1@PAPAVKDBuildElem@1@H@Z
// EA  : 0x832C3690
// RVA : 0x012C3690
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::Box *__fastcall bfx::CalcBBoxForElems(bfx::Box *result, bfx::KDBuildElem **pElems, int numElems)
{
  bfx::KDBuildElem **v3; // r10
  bfx::KDBuildElem **v4; // r9
  bfx::Vec3 *p_m_max; // r11
  float *v6; // r8

  v3 = pElems;
  v4 = &pElems[numElems];
  p_m_max = &result->m_max;
  result->m_min.m_x = 3.4028235e38;
  result->m_min.m_y = 3.4028235e38;
  result->m_min.m_z = 3.4028235e38;
  result->m_max.m_x = -3.4028235e38;
  result->m_max.m_y = -3.4028235e38;
  result->m_max.m_z = -3.4028235e38;
  if ( pElems != v4 )
  {
    do
    {
      v6 = (float *)*v3;
      _FP9 = (float)(result->m_min.m_z - (*v3)->m_bbox.m_min.m_z);
      _FP7 = (float)(result->m_min.m_y - (*v3)->m_bbox.m_min.m_y);
      _FP6 = (float)(result->m_min.m_x - (*v3++)->m_bbox.m_min.m_x);
      __asm { fsel      f5, f9, f11, f0 }
      result->m_min.m_z = _FP5;
      __asm { fsel      f4, f7, f10, f13 }
      result->m_min.m_y = _FP4;
      __asm { fsel      f3, f6, f8, f12 }
      result->m_min.m_x = _FP3;
      _FP8 = (float)(p_m_max->m_x - v6[3]);
      _FP10 = (float)(result->m_max.m_y - v6[4]);
      _FP9 = (float)(result->m_max.m_z - v6[5]);
      __asm { fsel      f5, f8, f1, f2 }
      p_m_max->m_x = _FP5;
      __asm { fsel      f7, f10, f11, f12 }
      result->m_max.m_y = _FP7;
      __asm { fsel      f6, f9, f13, f0 }
      result->m_max.m_z = _FP6;
    }
    while ( v3 != v4 );
  }
  return result;
}


// ========================================================================
// bfx::CompareX
// EA  : 0x832C3760
// RVA : 0x012C3760
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

int __fastcall bfx::CompareX(float **a, float **b)
{
  double v2; // fp0
  double v3; // fp13
  int result; // r3

  v2 = **a;
  v3 = **b;
  if ( v2 > v3 )
    return 1;
  result = -1;
  if ( v2 >= v3 )
    return 0;
  return result;
}


// ========================================================================
// bfx::CompareY
// EA  : 0x832C3798
// RVA : 0x012C3798
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

int __fastcall bfx::CompareY(const void *a, const void *b)
{
  double v2; // fp0
  double v3; // fp13
  int result; // r3

  v2 = *(float *)(*(_DWORD *)a + 4);
  v3 = *(float *)(*(_DWORD *)b + 4);
  if ( v2 > v3 )
    return 1;
  result = -1;
  if ( v2 >= v3 )
    return 0;
  return result;
}


// ========================================================================
// bfx::CompareZ
// EA  : 0x832C37D0
// RVA : 0x012C37D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

int __fastcall bfx::CompareZ(const void *a, const void *b)
{
  double v2; // fp0
  double v3; // fp13
  int result; // r3

  v2 = *(float *)(*(_DWORD *)a + 8);
  v3 = *(float *)(*(_DWORD *)b + 8);
  if ( v2 > v3 )
    return 1;
  result = -1;
  if ( v2 >= v3 )
    return 0;
  return result;
}


// ========================================================================
// ?GetBBox@DynKDTree@bfx@@QBA?AVBox@2@XZ
// EA  : 0x832C3808
// RVA : 0x012C3808
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::DynKDTree *__fastcall bfx::DynKDTree::GetBBox(bfx::DynKDTree *this, bfx::Box *result)
{
  bfx::DynKDTree *v2; // r10
  bfx::DynKDNode **v3; // r11
  int i; // ctr

  v2 = (bfx::DynKDTree *)((char *)this - 4);
  v3 = (bfx::DynKDNode **)(LODWORD(result->m_min.m_x) + 12);
  for ( i = 6; i != 0; --i )
  {
    ++v3;
    v2 = (bfx::DynKDTree *)((char *)v2 + 4);
    v2->m_pRoot = *v3;
  }
  return this;
}


// ========================================================================
// ??0PrimsInSphereCursor@DynKDTree@bfx@@QAA@ABVSphere@2@PBV12@@Z
// EA  : 0x832C3830
// RVA : 0x012C3830
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::DynKDTree::PrimsInSphereCursor::PrimsInSphereCursor(
        bfx::DynKDTree::PrimsInSphereCursor *this,
        const bfx::Sphere *sphere,
        const bfx::DynKDTree *pKDTree)
{
  this->m_sphere = *sphere;
  this->m_atEnd = false;
  if ( pKDTree->m_pRoot != nullptr )
  {
    this->m_nodeStack[0] = pKDTree->m_pRoot;
    this->m_pNextNode = &this->m_nodeStack[1];
    bfx::DynKDTree::PrimsInSphereCursor::TraverseToNextLeaf(this);
  }
  else
  {
    this->m_nodeStack[0] = nullptr;
    this->m_pNextNode = nullptr;
    this->m_atEnd = true;
  }
}


// ========================================================================
// ??0CollideLineSegmentCursor@DynKDTree@bfx@@QAA@ABVVec3@2@0PBV12@@Z
// EA  : 0x832C3888
// RVA : 0x012C3888
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::DynKDTree::CollideLineSegmentCursor *__fastcall bfx::DynKDTree::CollideLineSegmentCursor::CollideLineSegmentCursor(
        bfx::DynKDTree::CollideLineSegmentCursor *this,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *endPos,
        const bfx::DynKDTree *pKDTree)
{
  bfx::DynKDTree::CollideLineSegmentCursor *v4; // r31

  v4 = this;
  this->m_startPos = *startPos;
  this->m_endPos = *endPos;
  this->m_atEnd = false;
  if ( pKDTree->m_pRoot != nullptr )
  {
    this->m_nodeStack[0] = pKDTree->m_pRoot;
    this->m_pNextNode = &this->m_nodeStack[1];
    bfx::DynKDTree::CollideLineSegmentCursor::TraverseToNextLeaf(this);
    return v4;
  }
  else
  {
    this->m_nodeStack[0] = nullptr;
    this->m_pNextNode = nullptr;
    this->m_atEnd = true;
  }
  return this;
}


// ========================================================================
// ?BuildFromElems@DynKDTree@bfx@@QAAXAAV?$Array@VKDBuildElem@bfx@@@2@@Z
// EA  : 0x832C3A68
// RVA : 0x012C3A68
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::DynKDTree::BuildFromElems(bfx::DynKDTree *this, bfx::Array<bfx::KDBuildElem> *elems)
{
  int m_size; // r30
  char *m_data; // r22
  bfx::KDBuildElem *v6; // r10
  char *i; // r11
  char *v8; // r9
  bfx::Pool *p_m_nodePool; // r25
  bfx::DynKDNode *Node; // r3
  int v11; // r10
  int v12; // r11
  bfx::EndPt *v13; // r11
  signed int m_pAABB; // r28
  float m_val; // r27
  bfx::EndPtType m_type; // r30
  int v17; // r11
  int v18; // r5
  double m_x; // fp31
  double v20; // fp30
  double m_y; // fp29
  double v22; // fp0
  double v23; // fp28
  double v24; // fp13
  double m_z; // fp27
  double v26; // fp26
  double v27; // fp12
  int v28; // r26
  int (__fastcall *v29)(float **, float **); // r6
  bfx::Pool::Node *v30; // r21
  bfx::Pool::Node *v31; // r3
  bfx::EndPt v32; // [sp+58h] [-F8h] BYREF
  bfx::EndPt v33; // [sp+68h] [-E8h] BYREF
  bfx::Array<bfx::EndPt> v34; // [sp+80h] [-D0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v35; // [sp+90h] [-C0h] BYREF
  bfx::Box v36; // [sp+A0h] [-B0h] BYREF

  m_size = elems->m_size;
  if ( m_size != 0 )
  {
    m_data = nullptr;
    memset(&v35, 0, 12);
    v35.m_tag = bfx::MEM_BFXSYSTEM;
    if ( m_size > 0 )
    {
      bfx::Array<bfx::Edge *>::expand_cap(this: &v35, size: m_size);
      m_data = (char *)v35.m_data;
    }
    v35.m_size = m_size;
    v6 = elems->m_data;
    v8 = &m_data[4 * m_size];
    for ( i = m_data; i != v8; ++v6 )
    {
      *(_DWORD *)i = v6;
      i += 4;
    }
    memset(&v34, 0, 12);
    v34.m_tag = MEM_TEMP;
    p_m_nodePool = &this->m_nodePool;
    Node = (bfx::DynKDNode *)bfx::Pool::GetNode(this: &this->m_nodePool);
    this->m_pRoot = Node;
    LODWORD(v32.m_val) = m_data;
    v32.m_pAABB = (bfx::AABB *)m_size;
    Node->m_pParent = nullptr;
    v32.m_type = (bfx::EndPtType)this->m_pRoot;
    bfx::Array<bfx::FollowerBuddyData>::push_back(this: &v34, val: &v32);
    v11 = v34.m_size;
    while ( v11 != 0 )
    {
      v12 = v11--;
      v34.m_size = v11;
      v13 = &v34.m_data[v12];
      m_pAABB = (signed int)v13[-1].m_pAABB;
      m_val = v13[-1].m_val;
      m_type = v13[-1].m_type;
      if ( m_pAABB == 1 )
      {
        v17 = *(_DWORD *)LODWORD(m_val);
        v18 = *(_DWORD *)(*(_DWORD *)LODWORD(m_val) + 24);
        *(_DWORD *)m_type = *(_DWORD *)m_type & 0xFFFFFFF | 0xB0000000;
        *(_DWORD *)(m_type + 8) = 0;
        *(_DWORD *)(m_type + 4) = v18;
        *(float *)(m_type + 16) = *(float *)v17;
        *(float *)(m_type + 20) = *(float *)(v17 + 4);
        *(float *)(m_type + 24) = *(float *)(v17 + 8);
        *(float *)(m_type + 28) = *(float *)(v17 + 12);
        *(float *)(m_type + 32) = *(float *)(v17 + 16);
        *(float *)(m_type + 36) = *(float *)(v17 + 20);
        *(_DWORD *)(v17 + 28) = m_type;
      }
      else
      {
        bfx::CalcBBoxForElems(
          result: &v36,
          pElems: (bfx::KDBuildElem **)LODWORD(v13[-1].m_val),
          numElems: (int)v13[-1].m_pAABB);
        m_x = v36.m_max.m_x;
        v20 = v36.m_min.m_x;
        m_y = v36.m_max.m_y;
        v22 = (float)(v36.m_max.m_x - v36.m_min.m_x);
        v23 = v36.m_min.m_y;
        v24 = (float)(v36.m_max.m_y - v36.m_min.m_y);
        m_z = v36.m_max.m_z;
        v26 = v36.m_min.m_z;
        v27 = (float)(v36.m_max.m_z - v36.m_min.m_z);
        if ( v22 <= v24 || v22 <= v27 )
        {
          if ( v24 <= v27 )
          {
            v28 = 2;
            v29 = (int (__fastcall *)(float **, float **))bfx::CompareZ;
          }
          else
          {
            v28 = 1;
            v29 = (int (__fastcall *)(float **, float **))bfx::CompareY;
          }
        }
        else
        {
          v28 = 0;
          v29 = bfx::CompareX;
        }
        qsort(
          base: (void *)LODWORD(m_val),
          num: m_pAABB,
          width: 4u,
          comp: (int (__fastcall *)(const void *, const void *))v29);
        v30 = bfx::Pool::GetNode(this: p_m_nodePool);
        v31 = bfx::Pool::GetNode(this: p_m_nodePool);
        v30[3].m_pNext = (bfx::Pool::Node *)m_type;
        v31[3].m_pNext = (bfx::Pool::Node *)m_type;
        *(_DWORD *)(m_type + 8) = v31;
        *(_DWORD *)(m_type + 4) = v30;
        v32.m_type = (bfx::EndPtType)v31;
        v32.m_pAABB = (bfx::AABB *)(m_pAABB - m_pAABB / 2);
        LODWORD(v32.m_val) = 4 * (m_pAABB / 2) + LODWORD(m_val);
        v33.m_val = m_val;
        v33.m_pAABB = (bfx::AABB *)(m_pAABB / 2);
        v33.m_type = (bfx::EndPtType)v30;
        *(_DWORD *)m_type = (v28 << 28) & 0x70000000 | *(_DWORD *)m_type & 0xFFFFFFF;
        *(float *)(m_type + 16) = v20;
        *(float *)(m_type + 20) = v23;
        *(float *)(m_type + 24) = v26;
        *(float *)(m_type + 28) = m_x;
        *(float *)(m_type + 32) = m_y;
        *(float *)(m_type + 36) = m_z;
        bfx::Array<bfx::FollowerBuddyData>::push_back(this: &v34, val: &v32);
        bfx::Array<bfx::FollowerBuddyData>::push_back(this: &v34, val: &v33);
        v11 = v34.m_size;
      }
    }
    if ( v34.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v34.m_data);
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// __unwind$17626
// EA  : 0x832C3D70
// RVA : 0x012C3D70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void _unwind_17626()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$17627
// EA  : 0x832C3D98
// RVA : 0x012C3D98
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void _unwind_17627()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 336 + 128));
}


// ========================================================================
// ?TraverseToNextLeaf@ClosestPrimsCursor@DynKDTree@bfx@@AAAXXZ
// EA  : 0x832C3DC0
// RVA : 0x012C3DC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void __fastcall bfx::DynKDTree::ClosestPrimsCursor::TraverseToNextLeaf(bfx::DynKDTree::ClosestPrimsCursor *this)
{
  bfx::BinaryHeap<bfx::DynKDNode *,float> *p_m_closestNodesList; // r31
  bfx::BinaryHeap<bfx::DynKDNode *,float>::Node *m_data; // r11
  int v4; // r10
  bfx::DynKDNode *m_elem; // r30
  bfx::DynKDNode *m_pLeft; // r11
  double DistPtToBox; // fp1
  double v8; // fp1
  bfx::ReplayLogListenerEntry v9; // [sp+50h] [-30h] BYREF
  bfx::ReplayLogListenerEntry v10; // [sp+58h] [-28h] BYREF

  if ( this->m_closestNodesList.m_data.m_size > 1 )
  {
    p_m_closestNodesList = &this->m_closestNodesList;
    do
    {
      m_data = p_m_closestNodesList->m_data.m_data;
      v4 = (int)&p_m_closestNodesList->m_data.m_data[p_m_closestNodesList->m_data.m_size];
      m_elem = p_m_closestNodesList->m_data.m_data[1].m_elem;
      m_data[1].m_elem = *(bfx::DynKDNode **)(v4 - 8);
      m_data[1].m_priority = *(float *)(v4 - 4);
      --p_m_closestNodesList->m_data.m_size;
      bfx::BinaryHeap<bfx::DynKDNode *,float>::BubbleDown(this: p_m_closestNodesList, parent: 1u);
      if ( bfx::GetDistPtToBox(pos: &this->m_testPos, box: &m_elem->m_bbox) <= (double)this->m_considerationDist )
      {
        m_pLeft = m_elem->m_pLeft;
        if ( *(_DWORD *)m_elem >= 0 )
        {
          DistPtToBox = bfx::GetDistPtToBox(pos: &this->m_testPos, box: &m_pLeft->m_bbox);
          if ( DistPtToBox <= this->m_considerationDist )
          {
            v9.m_pListener = (bfx::ReplayListener *)m_elem->m_pLeft;
            *(float *)&v9.m_clientOwned = DistPtToBox;
            bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
              this: (bfx::Array<bfx::ReplayLogListenerEntry> *)p_m_closestNodesList,
              val: &v9);
            bfx::BinaryHeap<bfx::DynKDNode *,float>::BubbleUp(
              this: p_m_closestNodesList,
              child: p_m_closestNodesList->m_data.m_size - 1);
          }
          v8 = bfx::GetDistPtToBox(pos: &this->m_testPos, box: &m_elem->m_pRight->m_bbox);
          if ( v8 < this->m_considerationDist )
          {
            v10.m_pListener = (bfx::ReplayListener *)m_elem->m_pRight;
            *(float *)&v10.m_clientOwned = v8;
            bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
              this: (bfx::Array<bfx::ReplayLogListenerEntry> *)p_m_closestNodesList,
              val: &v10);
            bfx::BinaryHeap<bfx::DynKDNode *,float>::BubbleUp(
              this: p_m_closestNodesList,
              child: p_m_closestNodesList->m_data.m_size - 1);
          }
        }
        else if ( m_pLeft != nullptr )
        {
          this->m_pCurLeaf = m_elem;
          return;
        }
      }
    }
    while ( this->m_closestNodesList.m_data.m_size > 1 );
  }
  this->m_atEnd = true;
}


// ========================================================================
// ??0ClosestPrimsCursor@DynKDTree@bfx@@QAA@ABVVec3@2@PBV12@M@Z
// EA  : 0x832C3F08
// RVA : 0x012C3F08
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

bfx::DynKDTree::ClosestPrimsCursor *__fastcall bfx::DynKDTree::ClosestPrimsCursor::ClosestPrimsCursor(
        bfx::DynKDTree::ClosestPrimsCursor *this,
        const bfx::Vec3 *testPos,
        const bfx::DynKDTree *pKDTree,
        double considerationDist)
{
  bfx::Array<bfx::ReplayLogListenerEntry> *p_m_closestNodesList; // r29
  bfx::bfxMemTag v9; // r11
  bfx::DynKDNode *m_pRoot; // r28
  double DistPtToBox; // fp1
  bfx::ReplayLogListenerEntry v13; // [sp+58h] [-48h] BYREF

  p_m_closestNodesList = (bfx::Array<bfx::ReplayLogListenerEntry> *)&this->m_closestNodesList;
  this->m_testPos = *testPos;
  v9 = bfx::MEM_BFXSYSTEM;
  this->m_closestNodesList.m_data.m_data = nullptr;
  this->m_closestNodesList.m_data.m_size = 0;
  this->m_closestNodesList.m_data.m_cap = 0;
  this->m_closestNodesList.m_data.m_tag = v9;
  bfx::Array<bfx::NavWedge>::expand_cap(
    this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&this->m_closestNodesList,
    size: 100);
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: p_m_closestNodesList, val: &v13);
  this->m_considerationDist = considerationDist;
  this->m_pCurLeaf = nullptr;
  this->m_atEnd = false;
  m_pRoot = pKDTree->m_pRoot;
  if ( pKDTree->m_pRoot != nullptr )
  {
    DistPtToBox = bfx::GetDistPtToBox(pos: testPos, box: &m_pRoot->m_bbox);
    if ( DistPtToBox > this->m_considerationDist )
    {
      this->m_atEnd = true;
    }
    else
    {
      *(float *)&v13.m_clientOwned = DistPtToBox;
      v13.m_pListener = (bfx::ReplayListener *)m_pRoot;
      bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: p_m_closestNodesList, val: &v13);
      bfx::BinaryHeap<bfx::DynKDNode *,float>::BubbleUp(
        this: (bfx::BinaryHeap<bfx::DynKDNode *,float> *)p_m_closestNodesList,
        child: p_m_closestNodesList->m_size - 1);
      bfx::DynKDTree::ClosestPrimsCursor::TraverseToNextLeaf(this);
    }
  }
  else
  {
    this->m_atEnd = true;
  }
  return this;
}


// ========================================================================
// __unwind$18080
// EA  : 0x832C400C
// RVA : 0x012C400C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void _unwind_18080()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$18077
// EA  : 0x832C4034
// RVA : 0x012C4034
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxkdtree.cpp
// ========================================================================

void _unwind_18077()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                             + 12));
}

