
// ========================================================================
// ?PercolateDown@?$idBinaryHeap@HH$0?IAAAAAAA@@@AAAXH@Z
// EA  : 0x826D09D8
// RVA : 0x006D09D8
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

void __fastcall idBinaryHeap<int,int,-2147483648>::PercolateDown(idBinaryHeap<int,int,-2147483648> *this, int hole)
{
  int numNodes; // r10
  idBinaryHeap<int,int,-2147483648>::idHeapNode v3; // r6
  int v4; // r11
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v5; // r10
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v6; // r30

  numNodes = this->numNodes;
  v3 = this->nodes[hole];
  if ( 2 * hole <= numNodes )
  {
    do
    {
      v4 = 2 * hole;
      if ( 2 * hole != numNodes && this->nodes[2 * hole + 1].priority < this->nodes[2 * hole].priority )
        ++v4;
      v5 = &this->nodes[v4];
      if ( v5->priority >= v3.priority )
        break;
      v3.node = v5->node;
      v6 = &this->nodes[hole];
      hole = v4;
      v6->node = v5->node;
      v6->priority = v5->priority;
      numNodes = this->numNodes;
    }
    while ( 2 * v4 <= numNodes );
  }
  this->nodes[hole] = v3;
}


// ========================================================================
// ?SortHeap@?$idBinaryHeap@PAVnode_t@idBinaryHeapTest@@H$0?IAAAAAAA@@@AAAXXZ
// EA  : 0x826D0A90
// RVA : 0x006D0A90
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::SortHeap(
        idBinaryHeap<int,int,-2147483648> *this)
{
  int v1; // r7
  int v2; // r5
  int numNodes; // r9
  int v4; // r8
  int v5; // r11
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v6; // r10
  int v7; // r4
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v8; // r9

  v1 = this->numNodes >> 1;
  if ( v1 > 0 )
  {
    v2 = v1;
    do
    {
      numNodes = this->numNodes;
      v4 = v1;
      *(idBinaryHeap<int,int,-2147483648>::idHeapNode *)(&this - 1) = this->nodes[v2];
      if ( 2 * v1 <= numNodes )
      {
        do
        {
          v5 = 2 * v4;
          if ( 2 * v4 != this->numNodes && this->nodes[2 * v4 + 1].priority < this->nodes[2 * v4].priority )
            ++v5;
          v6 = &this->nodes[v5];
          if ( v6->priority >= v7 )
            break;
          v8 = &this->nodes[v4];
          v4 = v5;
          v8->node = v6->node;
          v8->priority = v6->priority;
        }
        while ( 2 * v5 <= this->numNodes );
      }
      --v1;
      --v2;
      this->nodes[v4] = *(idBinaryHeap<int,int,-2147483648>::idHeapNode *)(&this - 1);
    }
    while ( v1 > 0 );
  }
  this->ordered = true;
}


// ========================================================================
// ??1?$idBinaryHeap@PAVnode_t@idBinaryHeapTest@@H$0?IAAAAAAA@@@QAA@XZ
// EA  : 0x826D1110
// RVA : 0x006D1110
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

void __fastcall idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::~idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>(
        idBinaryHeap<int,int,-2147483648> *this)
{
  if ( this->externalBuffer || this->nodes == nullptr )
  {
    this->nodes = nullptr;
  }
  else
  {
    idMem::Free(this: &mem, ptr: this->nodes, align: ALIGN_16);
    this->nodes = nullptr;
  }
}


// ========================================================================
// ?Resize@?$idBinaryHeap@HH$0?IAAAAAAA@@@AAAXH@Z
// EA  : 0x826D1188
// RVA : 0x006D1188
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

void __fastcall idBinaryHeap<int,int,-2147483648>::Resize(idBinaryHeap<int,int,-2147483648> *this, int newSize)
{
  int v2; // r30
  unsigned int v5; // r5
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v6; // r3
  int *p_priority; // r11
  int v8; // ctr
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v9; // r30
  int v10; // r10
  int v11; // r11
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v12; // r8
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v13; // r7

  v2 = newSize + 1;
  v5 = 8 * (newSize + 1);
  if ( (unsigned int)(newSize + 1) > 0x1FFFFFFF )
    v5 = -1;
  v6 = (idBinaryHeap<int,int,-2147483648>::idHeapNode *)idMem::AllocWithLocation(
                                                          this: &mem,
                                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                                          size: v5,
                                                          tag: TAG_NEW,
                                                          zeroBuffer: false,
                                                          align: ALIGN_16,
                                                          heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
  {
    if ( v2 - 1 >= 0 )
    {
      v8 = v2;
      p_priority = &v6[-1].priority;
      do
      {
        p_priority += 2;
        *p_priority = 0x80000000;
        --v8;
      }
      while ( v8 != 0 );
    }
    v9 = v6;
  }
  else
  {
    v9 = nullptr;
  }
  v10 = 0;
  if ( this->numNodes + 1 > 0 )
  {
    v11 = 0;
    do
    {
      v12 = &v9[v11];
      ++v10;
      v13 = &this->nodes[v11++];
      v12->node = v13->node;
      v12->priority = v13->priority;
    }
    while ( v10 < this->numNodes + 1 );
  }
  idMem::Free(this: &mem, ptr: this->nodes, align: ALIGN_16);
  this->nodes = v9;
  this->curSize = newSize;
}


// ========================================================================
// ?InsertUnsorted@?$idBinaryHeap@PAVnode_t@idBinaryHeapTest@@H$0?IAAAAAAA@@@QAAXQAVnode_t@idBinaryHeapTest@@H@Z
// EA  : 0x826D37E0
// RVA : 0x006D37E0
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

void __fastcall idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(
        idBinaryHeap<int,int,-2147483648> *this,
        int node,
        int priority)
{
  int curSize; // r11
  idBinaryHeap<int,int,-2147483648>::idHeapNode *nodes; // r10
  int v8; // r11
  int numNodes; // r11

  curSize = this->curSize;
  if ( this->numNodes == curSize )
    idBinaryHeap<int,int,-2147483648>::Resize(this, newSize: 2 * curSize);
  nodes = this->nodes;
  v8 = this->numNodes + 1;
  this->numNodes = v8;
  nodes[v8].node = node;
  this->nodes[this->numNodes].priority = priority;
  numNodes = this->numNodes;
  if ( numNodes == 1 )
  {
    this->ordered = true;
  }
  else if ( priority < this->nodes[numNodes >> 1].priority )
  {
    this->ordered = false;
  }
}


// ========================================================================
// ?Insert@?$idBinaryHeap@PAVnode_t@idBinaryHeapTest@@H$0?IAAAAAAA@@@QAAXQAVnode_t@idBinaryHeapTest@@H@Z
// EA  : 0x826D4680
// RVA : 0x006D4680
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

void __fastcall idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
        idBinaryHeap<int,int,-2147483648> *this,
        int node,
        int priority)
{
  int curSize; // r11
  idBinaryHeap<int,int,-2147483648>::idHeapNode *nodes; // r9
  int v8; // r8
  int v9; // r11
  int v10; // r10
  int v11; // r7
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v12; // r6
  idBinaryHeap<int,int,-2147483648>::idHeapNode *v13; // r5

  if ( this->ordered )
  {
    curSize = this->curSize;
    if ( this->numNodes == curSize )
      idBinaryHeap<int,int,-2147483648>::Resize(this, newSize: 2 * curSize);
    nodes = this->nodes;
    v8 = this->numNodes + 1;
    v9 = v8 >> 1;
    this->numNodes = v8;
    v10 = v8 >> 1;
    if ( priority < nodes[v10].priority )
    {
      do
      {
        v11 = v8;
        v12 = &this->nodes[v10];
        v13 = &this->nodes[v8];
        v8 = v9;
        v9 >>= 1;
        v10 = v9;
        this->nodes[v11].node = v12->node;
        v13->priority = v12->priority;
      }
      while ( priority < this->nodes[v9].priority );
    }
    this->nodes[v8].node = node;
    this->nodes[v8].priority = priority;
  }
  else
  {
    idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(this, node, priority);
  }
}


// ========================================================================
// ??0?$idBinaryHeap@PAVnode_t@idBinaryHeapTest@@H$0?IAAAAAAA@@@QAA@H@Z
// EA  : 0x82EFABB8
// RVA : 0x00EFABB8
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648> *__fastcall idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>(
        idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648> *this,
        int initialSize_)
{
  int v2; // r29
  unsigned int v4; // r5
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idHeapNode *v5; // r3
  int *p_priority; // r11
  int v7; // ctr
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idHeapNode *v8; // r11
  int initialSize; // r10

  this->initialSize = initialSize_;
  v2 = initialSize_ + 1;
  this->nodes = nullptr;
  this->curSize = 0;
  this->numNodes = 0;
  this->ordered = true;
  this->externalBuffer = false;
  v4 = 8 * (initialSize_ + 1);
  if ( (unsigned int)(initialSize_ + 1) > 0x1FFFFFFF )
    v4 = -1;
  v5 = (idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idHeapNode *)idMem::AllocWithLocation(
                                                                                 this: &mem,
                                                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                                                                 size: v4,
                                                                                 tag: TAG_NEW,
                                                                                 zeroBuffer: false,
                                                                                 align: ALIGN_16,
                                                                                 heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
  {
    if ( v2 - 1 >= 0 )
    {
      v7 = v2;
      p_priority = &v5[-1].priority;
      do
      {
        p_priority += 2;
        *p_priority = 0x80000000;
        --v7;
      }
      while ( v7 != 0 );
    }
    v8 = v5;
  }
  else
  {
    v8 = nullptr;
  }
  initialSize = this->initialSize;
  this->nodes = v8;
  this->curSize = initialSize;
  v8->priority = 0x80000000;
  return this;
}


// ========================================================================
// ?MakeEmpty@?$idBinaryHeap@PAVnode_t@idBinaryHeapTest@@H$0?IAAAAAAA@@@QAAXXZ
// EA  : 0x82EFAC78
// RVA : 0x00EFAC78
// PDB : w:\tech5\shared\idlib\containers\binaryheap.h
// ========================================================================

void __fastcall idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::MakeEmpty(
        idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648> *this)
{
  unsigned int v2; // r29
  unsigned int v3; // r5
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idHeapNode *v4; // r3
  int *p_priority; // r11
  unsigned int v6; // ctr
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idHeapNode *v7; // r11
  int initialSize; // r10

  if ( this->curSize != this->initialSize )
  {
    idMem::Free(this: &mem, ptr: this->nodes, align: ALIGN_16);
    v2 = this->initialSize + 1;
    v3 = 8 * v2;
    if ( v2 > 0x1FFFFFFF )
      v3 = -1;
    v4 = (idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idHeapNode *)idMem::AllocWithLocation(
                                                                                   this: &mem,
                                                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                                                                   size: v3,
                                                                                   tag: TAG_NEW,
                                                                                   zeroBuffer: false,
                                                                                   align: ALIGN_16,
                                                                                   heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
    {
      if ( (int)(v2 - 1) >= 0 )
      {
        v6 = v2;
        p_priority = &v4[-1].priority;
        do
        {
          p_priority += 2;
          *p_priority = 0x80000000;
          --v6;
        }
        while ( v6 != 0 );
      }
      v7 = v4;
    }
    else
    {
      v7 = nullptr;
    }
    initialSize = this->initialSize;
    this->nodes = v7;
    this->curSize = initialSize;
  }
  this->nodes->priority = 0x80000000;
  this->numNodes = 0;
}

