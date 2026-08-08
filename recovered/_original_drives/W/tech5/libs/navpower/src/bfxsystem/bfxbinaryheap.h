
// ========================================================================
// ?BubbleUp@?$BinaryHeap@PAVArea@bfx@@I@bfx@@AAAXI@Z
// EA  : 0x8328AD60
// RVA : 0x0128AD60
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(
        bfx::BinaryHeap<bfx::XNode *,unsigned int> *this,
        unsigned int child)
{
  unsigned int i; // r9
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v3; // r11
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v4; // r10
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node v5; // r7

  for ( i = child >> 1; i != 0; *v3 = v5 )
  {
    v3 = &this->m_data.m_data[i];
    v4 = &this->m_data.m_data[child];
    if ( v4->m_priority >= v3->m_priority )
      break;
    child = i;
    v5 = *v4;
    i >>= 1;
    v4->m_elem = v3->m_elem;
    v5.m_elem = (bfx::XNode *)v3->m_priority;
    v4->m_priority = (unsigned int)v5.m_elem;
  }
}


// ========================================================================
// ?BubbleDown@?$BinaryHeap@PAVArea@bfx@@I@bfx@@AAAXI@Z
// EA  : 0x8328ADC0
// RVA : 0x0128ADC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleDown(
        bfx::BinaryHeap<bfx::XNode *,unsigned int> *this,
        unsigned int parent)
{
  unsigned int m_size; // r10
  unsigned int v3; // r9
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v4; // r11
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *v5; // r10
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node v6; // r7

  while ( 1 )
  {
    m_size = this->m_data.m_size;
    v3 = 2 * parent + 1;
    if ( 2 * parent >= m_size )
      break;
    if ( v3 == m_size || this->m_data.m_data[2 * parent].m_priority < this->m_data.m_data[v3].m_priority )
      v3 = 2 * parent;
    if ( v3 == -1 )
      break;
    v4 = &this->m_data.m_data[v3];
    v5 = &this->m_data.m_data[parent];
    if ( v5->m_priority < v4->m_priority )
      break;
    parent = v3;
    v6 = *v5;
    v5->m_elem = v4->m_elem;
    v6.m_elem = (bfx::XNode *)v4->m_priority;
    v5->m_priority = (unsigned int)v6.m_elem;
    *v4 = v6;
  }
}


// ========================================================================
// ??0?$BinaryHeap@PAVArea@bfx@@I@bfx@@QAA@H@Z
// EA  : 0x8328AF50
// RVA : 0x0128AF50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

bfx::BinaryHeap<bfx::Area *,unsigned int> *__fastcall bfx::BinaryHeap<bfx::Area *,unsigned int>::BinaryHeap<bfx::Area *,unsigned int>(
        bfx::BinaryHeap<bfx::Area *,unsigned int> *this,
        int initialHeapSize)
{
  bfx::bfxMemTag v3; // r10
  bfx::ReplayLogListenerEntry v5; // [sp+50h] [-20h] BYREF

  v3 = bfx::MEM_BFXSYSTEM;
  this->m_data.m_data = nullptr;
  this->m_data.m_size = 0;
  this->m_data.m_cap = 0;
  this->m_data.m_tag = v3;
  if ( initialHeapSize > 0 )
    bfx::Array<bfx::NavWedge>::expand_cap((bfx::Array<bfx::ReplayLogListenerEntry> *)this, size: initialHeapSize);
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
    (bfx::Array<bfx::ReplayLogListenerEntry> *)this,
    val: &v5);
  return this;
}


// ========================================================================
// __unwind$20444
// EA  : 0x8328AFC0
// RVA : 0x0128AFC0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void _unwind_20444()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 112 + 132));
}


// ========================================================================
// ?Find@?$BinaryHeap@UOpenNode3D@bfx@@M@bfx@@QAAPAUNode@12@UOpenNode3D@2@@Z
// EA  : 0x832A2008
// RVA : 0x012A2008
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *__fastcall bfx::BinaryHeap<bfx::OpenNode3D,float>::Find(
        bfx::BinaryHeap<bfx::OpenNode3D,float> *this,
        bfx::OpenNode3D *elem)
{
  int m_size; // r10
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *result; // r3
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *v4; // r10
  char v5; // r11

  m_size = this->m_data.m_size;
  if ( m_size <= 1 )
    return nullptr;
  v4 = &this->m_data.m_data[m_size];
  result = this->m_data.m_data + 1;
  if ( result >= v4 )
    return nullptr;
  while ( 1 )
  {
    if ( (bfx::BinaryHeap<bfx::OpenNode3D,float> *)result->m_elem.m_pPortal != this
      || (v5 = 1, result->m_elem.m_pointID != HIBYTE(elem)) )
    {
      v5 = 0;
    }
    if ( v5 != 0 )
      break;
    if ( ++result >= v4 )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetSmallerChild@?$BinaryHeap@UOpenNode3D@bfx@@M@bfx@@AAAII@Z
// EA  : 0x832A2180
// RVA : 0x012A2180
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

unsigned int __fastcall bfx::BinaryHeap<bfx::OpenNode3D,float>::GetSmallerChild(
        bfx::BinaryHeap<bfx::OpenNode3D,float> *this,
        unsigned int parent)
{
  unsigned int m_size; // r10
  unsigned int v3; // r11
  unsigned int v4; // r9

  m_size = this->m_data.m_size;
  v3 = 2 * parent;
  v4 = 2 * parent + 1;
  if ( 2 * parent >= m_size )
    return -1;
  if ( v4 != m_size && this->m_data.m_data[2 * parent].m_priority >= (double)this->m_data.m_data[v4].m_priority )
    return 2 * parent + 1;
  return v3;
}


// ========================================================================
// ?BubbleUp@?$BinaryHeap@UOpenNode3D@bfx@@M@bfx@@AAAXI@Z
// EA  : 0x832A21F8
// RVA : 0x012A21F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::OpenNode3D,float>::BubbleUp(
        bfx::BinaryHeap<bfx::OpenNode3D,float> *this,
        unsigned int child)
{
  if ( child >> 1 != 0 && this->m_data.m_data[child].m_priority < (double)this->m_data.m_data[child >> 1].m_priority )
  {
    while ( 1 )
      ;
  }
}


// ========================================================================
// ?BubbleDown@?$BinaryHeap@UOpenNode3D@bfx@@M@bfx@@AAAXI@Z
// EA  : 0x832A22B8
// RVA : 0x012A22B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::OpenNode3D,float>::BubbleDown(
        bfx::BinaryHeap<bfx::OpenNode3D,float> *this,
        unsigned int parent)
{
  unsigned int m_size; // r10
  unsigned int v3; // r9

  m_size = this->m_data.m_size;
  v3 = 2 * parent + 1;
  if ( 2 * parent < m_size )
  {
    if ( v3 == m_size || this->m_data.m_data[2 * parent].m_priority < (double)this->m_data.m_data[v3].m_priority )
      v3 = 2 * parent;
    if ( v3 != -1 && this->m_data.m_data[parent].m_priority >= (double)this->m_data.m_data[v3].m_priority )
    {
      while ( 1 )
        ;
    }
  }
}


// ========================================================================
// ??0?$BinaryHeap@UOpenNode3D@bfx@@M@bfx@@QAA@H@Z
// EA  : 0x832A2860
// RVA : 0x012A2860
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

bfx::BinaryHeap<bfx::OpenNode3D,float> *__fastcall bfx::BinaryHeap<bfx::OpenNode3D,float>::BinaryHeap<bfx::OpenNode3D,float>(
        bfx::BinaryHeap<bfx::OpenNode3D,float> *this,
        int initialHeapSize)
{
  bfx::bfxMemTag v3; // r10
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node v5; // [sp+50h] [-30h] BYREF

  v3 = bfx::MEM_BFXSYSTEM;
  this->m_data.m_data = nullptr;
  this->m_data.m_size = 0;
  this->m_data.m_cap = 0;
  this->m_data.m_tag = v3;
  if ( initialHeapSize > 0 )
    bfx::Array<bfx::PortalSubdivElem>::expand_cap(this: &this->m_data, size: initialHeapSize);
  bfx::Array<bfx::Box>::push_back(this: &this->m_data, val: &v5);
  return this;
}


// ========================================================================
// __unwind$14176
// EA  : 0x832A28D0
// RVA : 0x012A28D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void _unwind_14176()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 128 + 148));
}


// ========================================================================
// ?Update@?$BinaryHeap@UOpenNode3D@bfx@@M@bfx@@QAAXAAUNode@12@M@Z
// EA  : 0x832A28F8
// RVA : 0x012A28F8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::OpenNode3D,float>::Update(
        bfx::BinaryHeap<bfx::OpenNode3D,float> *this,
        bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *node,
        double priority)
{
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node *m_data; // r30
  unsigned int v6; // r31
  unsigned int SmallerChild; // r3

  m_data = this->m_data.m_data;
  node->m_priority = priority;
  v6 = node - m_data;
  if ( v6 < 2 || *(&m_data->m_priority + 2 * (v6 >> 1) + 2 * (v6 & 0xFFFFFFFE)) <= priority )
  {
    SmallerChild = bfx::BinaryHeap<bfx::OpenNode3D,float>::GetSmallerChild(this, parent: node - m_data);
    if ( SmallerChild != -1 && m_data[SmallerChild].m_priority < priority )
      bfx::BinaryHeap<bfx::OpenNode3D,float>::BubbleDown(this, parent: v6);
  }
  else
  {
    bfx::BinaryHeap<bfx::OpenNode3D,float>::BubbleUp(this, child: node - m_data);
  }
}


// ========================================================================
// ?BubbleUp@?$BinaryHeap@PAVDynKDNode@bfx@@M@bfx@@AAAXI@Z
// EA  : 0x832C3930
// RVA : 0x012C3930
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::DynKDNode *,float>::BubbleUp(
        bfx::BinaryHeap<bfx::DynKDNode *,float> *this,
        unsigned int child)
{
  unsigned int i; // r9
  bfx::BinaryHeap<bfx::DynKDNode *,float>::Node *v3; // r10
  bfx::BinaryHeap<bfx::DynKDNode *,float>::Node *v4; // r11
  bfx::BinaryHeap<bfx::DynKDNode *,float>::Node v5; // r7

  for ( i = child >> 1; i != 0; *v4 = v5 )
  {
    v3 = &this->m_data.m_data[child];
    v4 = &this->m_data.m_data[i];
    if ( v3->m_priority >= (double)v4->m_priority )
      break;
    child = i;
    v5 = *v3;
    i >>= 1;
    v3->m_elem = v4->m_elem;
    v5.m_elem = (bfx::DynKDNode *)LODWORD(v4->m_priority);
    LODWORD(v3->m_priority) = v5.m_elem;
  }
}


// ========================================================================
// ?BubbleDown@?$BinaryHeap@PAVDynKDNode@bfx@@M@bfx@@AAAXI@Z
// EA  : 0x832C39A0
// RVA : 0x012C39A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::DynKDNode *,float>::BubbleDown(
        bfx::BinaryHeap<bfx::DynKDNode *,float> *this,
        unsigned int parent)
{
  unsigned int m_size; // r10
  unsigned int v3; // r8
  bfx::BinaryHeap<bfx::DynKDNode *,float>::Node *v4; // r10
  bfx::BinaryHeap<bfx::DynKDNode *,float>::Node *v5; // r11
  bfx::BinaryHeap<bfx::DynKDNode *,float>::Node v6; // r8

  while ( 1 )
  {
    m_size = this->m_data.m_size;
    v3 = 2 * parent + 1;
    if ( 2 * parent >= m_size )
      break;
    if ( v3 == m_size || this->m_data.m_data[2 * parent].m_priority < (double)this->m_data.m_data[v3].m_priority )
      v3 = 2 * parent;
    if ( v3 == -1 )
      break;
    v4 = &this->m_data.m_data[parent];
    v5 = &this->m_data.m_data[v3];
    if ( v4->m_priority < (double)v5->m_priority )
      break;
    parent = v3;
    v6 = *v4;
    v4->m_elem = v5->m_elem;
    v6.m_elem = (bfx::DynKDNode *)LODWORD(v5->m_priority);
    LODWORD(v4->m_priority) = v6.m_elem;
    *v5 = v6;
  }
}


// ========================================================================
// ?Update@?$BinaryHeap@PAVArea@bfx@@I@bfx@@QAAXAAUNode@12@I@Z
// EA  : 0x832C7B50
// RVA : 0x012C7B50
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryheap.h
// ========================================================================

void __fastcall bfx::BinaryHeap<bfx::Area *,unsigned int>::Update(
        bfx::BinaryHeap<bfx::XNode *,unsigned int> *this,
        bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *node,
        unsigned int priority)
{
  bfx::BinaryHeap<bfx::XNode *,unsigned int>::Node *m_data; // r8
  unsigned int v4; // r4
  unsigned int m_size; // r9
  int v6; // r11
  int v7; // r10

  node->m_priority = priority;
  m_data = this->m_data.m_data;
  v4 = node - this->m_data.m_data;
  if ( v4 < 2 || *(unsigned int *)((char *)&m_data->m_priority + ((4 * v4) & 0xFFFFFFF8)) <= priority )
  {
    m_size = this->m_data.m_size;
    v6 = 2 * v4;
    v7 = 2 * v4 + 1;
    if ( 2 * v4 < m_size )
    {
      if ( v7 != m_size && m_data[2 * v4].m_priority >= m_data[v7].m_priority )
        v6 = 2 * v4 + 1;
      if ( v6 != -1 && m_data[v6].m_priority < priority )
        bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleDown(this, parent: v4);
    }
  }
  else
  {
    bfx::BinaryHeap<bfx::Area *,unsigned int>::BubbleUp(this, child: v4);
  }
}

