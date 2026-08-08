
// ========================================================================
// ??1?$idBTree@V?$idDynamicBlock@D$0HH@@@H$03@@QAA@XZ
// EA  : 0x8287D4D0
// RVA : 0x0087D4D0
// PDB : w:\tech5\shared\idlib\containers\btree.h
// ========================================================================

void __fastcall idBTree<idDynamicBlock<char,119>,int,4>::~idBTree<idDynamicBlock<char,119>,int,4>(
        idBTree<idDynamicBlock<unsigned char,60>,int,4> *this)
{
  idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44> *p_nodeAllocator; // r29

  p_nodeAllocator = &this->nodeAllocator;
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: (idBlockAlloc<idAASClipLink,128,37> *)&this->nodeAllocator);
  this->root = nullptr;
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: (idBlockAlloc<idAASClipLink,128,37> *)p_nodeAllocator);
}


// ========================================================================
// __unwind$223860_0
// EA  : 0x8287D50C
// RVA : 0x0087D50C
// PDB : w:\tech5\shared\idlib\containers\btree.h
// ========================================================================

void _unwind_223860_0()
{
  int v0; // r12

  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::~idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>(this: (idBlockAlloc<idAASClipLink,128,37> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?FindSmallestLargerEqual@?$idBTree@V?$idDynamicBlock@D$0HH@@@H$03@@QBAPAV?$idDynamicBlock@D$0HH@@@H@Z
// EA  : 0x82EF4EE0
// RVA : 0x00EF4EE0
// PDB : w:\tech5\shared\idlib\containers\btree.h
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall idBTree<idDynamicBlock<char,119>,int,4>::FindSmallestLargerEqual(
        idBTree<idDynamicBlock<unsigned char,60>,int,4> *this,
        int key)
{
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *firstChild; // r11
  idDynamicBlock<unsigned char,60> *object; // r10

  if ( this->root == nullptr )
    return nullptr;
  firstChild = this->root->firstChild;
  if ( firstChild == nullptr )
    return nullptr;
  while ( 1 )
  {
    for ( ; firstChild->next != nullptr; firstChild = firstChild->next )
    {
      if ( firstChild->key >= key )
        break;
    }
    object = firstChild->object;
    if ( object != nullptr )
      break;
    firstChild = firstChild->firstChild;
    if ( firstChild == nullptr )
      return nullptr;
  }
  return __CFADD__(firstChild->key - key, key ^ 0x80000000) ? nullptr : object;
}


// ========================================================================
// ?MergeNodes@?$idBTree@V?$idDynamicBlock@E$05@@H$03@@AAAPAV?$idBTreeNode@V?$idDynamicBlock@E$05@@H@@PAV2@0@Z
// EA  : 0x82EF52C8
// RVA : 0x00EF52C8
// PDB : w:\tech5\shared\idlib\containers\btree.h
// ========================================================================

idBTreeNode<idDynamicBlock<unsigned char,60>,int> *__fastcall idBTree<idDynamicBlock<unsigned char,6>,int,4>::MergeNodes(
        idBTree<idDynamicBlock<unsigned char,60>,int,4> *this,
        idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *node1,
        idBTreeNode<idDynamicBlock<unsigned char,60>,int> *node2)
{
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *i; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v5; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *parent; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *result; // r3
  int v8; // r5

  for ( i = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node1->buffer[24]; i->next != nullptr; i = i->next )
    i->parent = node2;
  i->parent = node2;
  i->next = node2->firstChild;
  node2->firstChild->prev = i;
  node2->firstChild = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node1->buffer[24];
  node2->numChildren += *(_DWORD *)&node1->buffer[20];
  v5 = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node1->buffer[16];
  if ( v5 != nullptr )
    v5->next = node2;
  else
    *(_DWORD *)(*(_DWORD *)&node1->buffer[8] + 24) = node2;
  parent = node2->parent;
  result = node2;
  node2->prev = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node1->buffer[16];
  --parent->numChildren;
  node1->data = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)this->nodeAllocator.free;
  v8 = this->nodeAllocator.active - 1;
  this->nodeAllocator.free = node1;
  this->nodeAllocator.active = v8;
  return result;
}


// ========================================================================
// ?Add@?$idBTree@V?$idDynamicBlock@E$0FJ@@@H$03@@QAAPAV?$idBTreeNode@V?$idDynamicBlock@E$0FJ@@@H@@PAV?$idDynamicBlock@E$0FJ@@@H@Z
// EA  : 0x82F2D2C0
// RVA : 0x00F2D2C0
// PDB : w:\tech5\shared\idlib\containers\btree.h
// ========================================================================

idBTreeNode<idDynamicBlock<unsigned char,60>,int> *__fastcall idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
        idBTree<idDynamicBlock<unsigned char,60>,int,4> *this,
        idDynamicBlock<unsigned char,60> *object,
        idBTreeNode<idDynamicBlock<unsigned char,60>,int> *key)
{
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v6; // r3
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v7; // r30
  idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *v8; // r3
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v9; // r30
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *root; // r9
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *firstChild; // r31
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> **p_next; // r10
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *i; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *result; // r3
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *prev; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v16; // r11

  if ( this->root == nullptr )
  {
    v6 = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)idBlockAlloc<idBTreeNode<idDynamicBlock<char,119>,int>,128,44>::Alloc(this: &this->nodeAllocator);
    v6->key = 0;
    v6->parent = nullptr;
    v6->next = nullptr;
    v6->prev = nullptr;
    v6->numChildren = 0;
    v6->firstChild = nullptr;
    v6->lastChild = nullptr;
    v6->object = nullptr;
    this->root = v6;
  }
  if ( this->root->numChildren >= 4 )
  {
    v7 = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)idBlockAlloc<idBTreeNode<idDynamicBlock<char,119>,int>,128,44>::Alloc(this: &this->nodeAllocator);
    v7->key = 0;
    v7->numChildren = 0;
    v7->firstChild = nullptr;
    v7->lastChild = nullptr;
    v7->parent = nullptr;
    v7->next = nullptr;
    v7->prev = nullptr;
    v7->object = nullptr;
    v7->key = this->root->key;
    v7->firstChild = this->root;
    v7->lastChild = this->root;
    v7->numChildren = 1;
    this->root->parent = v7;
    idBTree<idDynamicBlock<unsigned char,60>,int,4>::SplitNode(this, node: this->root);
    this->root = v7;
  }
  v8 = idBlockAlloc<idBTreeNode<idDynamicBlock<char,119>,int>,128,44>::Alloc(this: &this->nodeAllocator);
  v8->data = key;
  *(_DWORD *)&v8->buffer[4] = object;
  v9 = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)v8;
  *(_DWORD *)&v8->buffer[12] = 0;
  *(_DWORD *)&v8->buffer[20] = 0;
  *(_DWORD *)&v8->buffer[24] = 0;
  *(_DWORD *)&v8->buffer[28] = 0;
  *(_DWORD *)&v8->buffer[16] = 0;
  *(_DWORD *)&v8->buffer[8] = 0;
  root = this->root;
  if ( this->root->firstChild != nullptr )
  {
    while ( 1 )
    {
      if ( (int)key > root->key )
        root->key = (int)key;
      firstChild = root->firstChild;
      p_next = &firstChild->next;
      for ( i = firstChild->next; i != nullptr; i = i->next )
      {
        if ( (int)key <= firstChild->key )
          break;
        p_next = &i->next;
        firstChild = i;
      }
      if ( firstChild->object != nullptr )
        break;
      if ( firstChild->numChildren >= 4 )
      {
        idBTree<idDynamicBlock<unsigned char,60>,int,4>::SplitNode(this, node: firstChild);
        if ( (int)key <= firstChild->prev->key )
          firstChild = firstChild->prev;
      }
      root = firstChild;
      if ( firstChild->firstChild == nullptr )
        goto LABEL_16;
    }
    if ( (int)key > firstChild->key )
    {
      if ( *p_next != nullptr )
        (*p_next)->prev = v9;
      else
        root->lastChild = v9;
      v9->prev = firstChild;
      v9->next = *p_next;
      *p_next = v9;
      v9->parent = root;
      ++root->numChildren;
      return v9;
    }
    else
    {
      prev = firstChild->prev;
      if ( prev != nullptr )
      {
        prev->next = v9;
        result = v9;
        v9->prev = firstChild->prev;
        v9->next = firstChild;
      }
      else
      {
        root->firstChild = v9;
        result = v9;
        v16 = firstChild->prev;
        v9->next = firstChild;
        v9->prev = v16;
      }
      firstChild->prev = v9;
      v9->parent = root;
      ++root->numChildren;
    }
  }
  else
  {
LABEL_16:
    v9->parent = this->root;
    this->root->key = (int)key;
    this->root->firstChild = v9;
    this->root->lastChild = v9;
    ++this->root->numChildren;
    return v9;
  }
  return result;
}


// ========================================================================
// ?SplitNode@?$idBTree@V?$idDynamicBlock@E$0DM@@@H$03@@AAAXPAV?$idBTreeNode@V?$idDynamicBlock@E$0DM@@@H@@@Z
// EA  : 0x82F41070
// RVA : 0x00F41070
// PDB : w:\tech5\shared\idlib\containers\btree.h
// ========================================================================

void __fastcall idBTree<idDynamicBlock<unsigned char,60>,int,4>::SplitNode(
        idBTree<idDynamicBlock<unsigned char,60>,int,4> *this,
        idBTreeNode<idDynamicBlock<unsigned char,60>,int> *node)
{
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v3; // r3
  int v4; // r9
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *firstChild; // r11
  int numChildren; // r8
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *prev; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v8; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *parent; // r11

  v3 = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)idBlockAlloc<idBTreeNode<idDynamicBlock<char,119>,int>,128,44>::Alloc(this: &this->nodeAllocator);
  v4 = 3;
  v3->parent = nullptr;
  v3->key = 0;
  v3->next = nullptr;
  v3->prev = nullptr;
  v3->numChildren = 0;
  v3->firstChild = nullptr;
  v3->lastChild = nullptr;
  v3->object = nullptr;
  v3->parent = node->parent;
  firstChild = node->firstChild;
  for ( firstChild->parent = v3; v4 < node->numChildren; firstChild->parent = v3 )
  {
    firstChild = firstChild->next;
    v4 += 2;
  }
  v3->key = firstChild->key;
  numChildren = node->numChildren;
  v3->numChildren = numChildren / 2;
  v3->firstChild = node->firstChild;
  v3->lastChild = firstChild;
  node->numChildren -= numChildren / 2;
  node->firstChild = firstChild->next;
  firstChild->next->prev = nullptr;
  firstChild->next = nullptr;
  prev = node->prev;
  if ( prev != nullptr )
    prev->next = v3;
  else
    node->parent->firstChild = v3;
  v8 = node->prev;
  v3->next = node;
  v3->prev = v8;
  parent = node->parent;
  node->prev = v3;
  ++parent->numChildren;
}


// ========================================================================
// ?Remove@?$idBTree@V?$idDynamicBlock@D$0HH@@@H$03@@QAAXPAV?$idBTreeNode@V?$idDynamicBlock@D$0HH@@@H@@@Z
// EA  : 0x82F411E0
// RVA : 0x00F411E0
// PDB : w:\tech5\shared\idlib\containers\btree.h
// ========================================================================

void __fastcall idBTree<idDynamicBlock<char,119>,int,4>::Remove(
        idBTree<idDynamicBlock<unsigned char,60>,int,4> *this,
        idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *node)
{
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v2; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v4; // r10
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v6; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *v7; // r10
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *i; // r31
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *next; // r5
  idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *prev; // r4
  int key; // r11
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *lastChild; // r11
  int v13; // r11
  int v14; // r9
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *root; // r10
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *firstChild; // r9

  v2 = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node->buffer[16];
  v4 = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node->buffer[12];
  if ( v2 != nullptr )
    v2->next = v4;
  else
    *(_DWORD *)(*(_DWORD *)&node->buffer[8] + 24) = v4;
  v6 = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node->buffer[12];
  v7 = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node->buffer[16];
  if ( v6 != nullptr )
    v6->prev = v7;
  else
    *(_DWORD *)(*(_DWORD *)&node->buffer[8] + 28) = v7;
  --*(_DWORD *)(*(_DWORD *)&node->buffer[8] + 20);
  for ( i = *(idBTreeNode<idDynamicBlock<unsigned char,60>,int> **)&node->buffer[8]; i != this->root; i = i->parent )
  {
    if ( i->numChildren > 1 )
      break;
    next = i->next;
    if ( next != nullptr )
    {
      prev = (idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *)i;
    }
    else
    {
      prev = (idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *)i->prev;
      if ( prev == nullptr )
        goto LABEL_14;
      next = i;
    }
    i = idBTree<idDynamicBlock<unsigned char,6>,int,4>::MergeNodes(this, node1: prev, node2: next);
LABEL_14:
    key = i->lastChild->key;
    if ( i->key > key )
      i->key = key;
    if ( i->numChildren > 4 )
    {
      idBTree<idDynamicBlock<unsigned char,60>,int,4>::SplitNode(this, node: i);
      break;
    }
  }
  while ( i != nullptr )
  {
    lastChild = i->lastChild;
    if ( lastChild == nullptr )
      break;
    v13 = lastChild->key;
    if ( i->key > v13 )
      i->key = v13;
    i = i->parent;
  }
  node->data = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)this->nodeAllocator.free;
  v14 = this->nodeAllocator.active - 1;
  this->nodeAllocator.free = node;
  this->nodeAllocator.active = v14;
  root = this->root;
  if ( this->root->numChildren == 1 )
  {
    firstChild = root->firstChild;
    if ( firstChild->object == nullptr )
    {
      firstChild->parent = nullptr;
      this->root = this->root->firstChild;
      if ( root != nullptr )
      {
        root->key = (int)this->nodeAllocator.free;
        this->nodeAllocator.free = (idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *)root;
        --this->nodeAllocator.active;
      }
    }
  }
}

