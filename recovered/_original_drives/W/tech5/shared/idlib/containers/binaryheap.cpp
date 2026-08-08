
// ========================================================================
// ??0idBinaryHeapTest@@QAA@XZ
// EA  : 0x82EFAD50
// RVA : 0x00EFAD50
// PDB : w:\tech5\shared\idlib\containers\binaryheap.cpp
// ========================================================================

idBinaryHeapTest *__fastcall idBinaryHeapTest::idBinaryHeapTest(idBinaryHeapTest *this)
{
  int v3; // [sp+50h] [-50h] BYREF
  int v4; // [sp+54h] [-4Ch] BYREF
  int v5; // [sp+58h] [-48h] BYREF
  int v6; // [sp+5Ch] [-44h] BYREF
  int v7; // [sp+60h] [-40h] BYREF
  int v8[3]; // [sp+64h] [-3Ch] BYREF
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648> v9; // [sp+70h] [-30h] BYREF

  v7 = 3;
  v6 = 5;
  v5 = 8;
  v4 = 13;
  v3 = 21;
  v8[0] = 34;
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>(
    this: &v9,
    initialSize_: 16);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v7,
    priority: 3);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v6,
    priority: 5);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v5,
    priority: 8);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v4,
    priority: 13);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v3,
    priority: 21);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v6,
    priority: v6);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v3,
    priority: v3);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v7,
    priority: v7);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v5,
    priority: v5);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::Insert(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v4,
    priority: v4);
  if ( !v9.ordered )
    idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::SortHeap(this: (idBinaryHeap<int,int,-2147483648> *)&v9);
  if ( !v9.ordered )
    idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::SortHeap(this: (idBinaryHeap<int,int,-2147483648> *)&v9);
  if ( !v9.ordered )
    idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::SortHeap(this: (idBinaryHeap<int,int,-2147483648> *)&v9);
  if ( !v9.ordered )
    idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::SortHeap(this: (idBinaryHeap<int,int,-2147483648> *)&v9);
  if ( !v9.ordered )
    idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::SortHeap(this: (idBinaryHeap<int,int,-2147483648> *)&v9);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v3,
    priority: v3);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v4,
    priority: v4);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v5,
    priority: v5);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v6,
    priority: v6);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)&v7,
    priority: v7);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::InsertUnsorted(
    this: (idBinaryHeap<int,int,-2147483648> *)&v9,
    node: (int)v8,
    priority: v8[0]);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::MakeEmpty(this: &v9);
  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::~idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>(this: (idBinaryHeap<int,int,-2147483648> *)&v9);
  return this;
}


// ========================================================================
// __unwind$111418
// EA  : 0x82EFAF38
// RVA : 0x00EFAF38
// PDB : w:\tech5\shared\idlib\containers\binaryheap.cpp
// ========================================================================

void _unwind_111418()
{
  int v0; // r12

  idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>::~idBinaryHeap<idBinaryHeapTest::node_t *,int,-2147483648>(this: (idBinaryHeap<int,int,-2147483648> *)(v0 - 160 + 112));
}


// ========================================================================
// ?testBinaryHeap_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFAF60
// RVA : 0x00EFAF60
// PDB : w:\tech5\shared\idlib\containers\binaryheap.cpp
// ========================================================================

void __fastcall testBinaryHeap_f(const idCmdArgs *args)
{
  idBinaryHeapTest v1; // [sp+50h] [-10h] BYREF

  idBinaryHeapTest::idBinaryHeapTest(this: &v1);
}


// ========================================================================
// `dynamic initializer for 'testBinaryHeap_v''
// EA  : 0x83394258
// RVA : 0x01394258
// PDB : w:\tech5\shared\idlib\containers\binaryheap.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testBinaryHeap_v__()
{
  return idCommandLink::idCommandLink(
           this: &testBinaryHeap_v,
           cmdName: "testBinaryHeap",
           function: testBinaryHeap_f,
           description: "Tests the binary heap impl",
           argCompletion: nullptr);
}

