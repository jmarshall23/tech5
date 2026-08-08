
// ========================================================================
// ??0idBinaryTreeTest@@QAA@XZ
// EA  : 0x82EFB0D0
// RVA : 0x00EFB0D0
// PDB : w:\tech5\shared\idlib\containers\btree.cpp
// ========================================================================

idBinaryTreeTest *__fastcall idBinaryTreeTest::idBinaryTreeTest(idBinaryTreeTest *this)
{
  idDynamicBlock<unsigned char,60> v3; // [sp+50h] [-80h] BYREF
  idDynamicBlock<unsigned char,60> v4; // [sp+60h] [-70h] BYREF
  idDynamicBlock<unsigned char,60> v5; // [sp+70h] [-60h] BYREF
  idDynamicBlock<unsigned char,60> v6; // [sp+80h] [-50h] BYREF
  idBTree<idDynamicBlock<unsigned char,60>,int,4> v7[2]; // [sp+90h] [-40h] BYREF

  *(_QWORD *)&v6.size = 0x500000003LL;
  *(_QWORD *)&v5.next = 0xD00000008LL;
  *(_QWORD *)&v5.size = 0x2200000015LL;
  *(_QWORD *)&v4.next = 0x5900000037LL;
  *(_QWORD *)&v4.size = 0xE900000090LL;
  *(_QWORD *)&v3.next = 0x26200000179LL;
  *(_QWORD *)&v3.size = 0x63D000003DBLL;
  v6.next = (idDynamicBlock<unsigned char,60> *)2584;
  v7[0].nodeAllocator.allowAllocs = true;
  v7[0].nodeAllocator.clearAllocs = false;
  memset(v7, 0, 20);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v6.next,
    key: 2584);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(this: v7, object: &v3, key: v3.size);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v3.prev,
    key: (int)v3.prev);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v3.next,
    key: (int)v3.next);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v3.node,
    key: (int)v3.node);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(this: v7, object: &v4, key: v4.size);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v4.prev,
    key: (int)v4.prev);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v4.next,
    key: (int)v4.next);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v4.node,
    key: (int)v4.node);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(this: v7, object: &v5, key: v5.size);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v5.prev,
    key: (int)v5.prev);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v5.next,
    key: (int)v5.next);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v5.node,
    key: (int)v5.node);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(this: v7, object: &v6, key: v6.size);
  idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
    this: v7,
    object: (idDynamicBlock<unsigned char,60> *)&v6.prev,
    key: (int)v6.prev);
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: (idBlockAlloc<idAASClipLink,128,37> *)&v7[0].nodeAllocator);
  v7[0].root = nullptr;
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: (idBlockAlloc<idAASClipLink,128,37> *)&v7[0].nodeAllocator);
  return this;
}


// ========================================================================
// __unwind$111583
// EA  : 0x82EFB290
// RVA : 0x00EFB290
// PDB : w:\tech5\shared\idlib\containers\btree.cpp
// ========================================================================

void _unwind_111583()
{
  int v0; // r12

  idBTree<idDynamicBlock<char,119>,int,4>::~idBTree<idDynamicBlock<char,119>,int,4>(this: (idBTree<idDynamicBlock<unsigned char,60>,int,4> *)(v0 - 208 + 144));
}


// ========================================================================
// __unwind$111639
// EA  : 0x82EFB2B8
// RVA : 0x00EFB2B8
// PDB : w:\tech5\shared\idlib\containers\btree.cpp
// ========================================================================

void _unwind_111639()
{
  int v0; // r12

  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::~idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>(this: (idBlockAlloc<idAASClipLink,128,37> *)(v0 - 208 + 148));
}


// ========================================================================
// ?testBinaryTree_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EFB2E8
// RVA : 0x00EFB2E8
// PDB : w:\tech5\shared\idlib\containers\btree.cpp
// ========================================================================

void __fastcall testBinaryTree_f(const idCmdArgs *args)
{
  idBinaryTreeTest v1; // [sp+50h] [-10h] BYREF

  idBinaryTreeTest::idBinaryTreeTest(this: &v1);
}


// ========================================================================
// `dynamic initializer for 'testBinaryTree_v''
// EA  : 0x83394280
// RVA : 0x01394280
// PDB : w:\tech5\shared\idlib\containers\btree.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testBinaryTree_v__()
{
  return idCommandLink::idCommandLink(
           this: &testBinaryTree_v,
           cmdName: "testBinaryTree",
           function: testBinaryTree_f,
           description: "Tests the binary tree impl",
           argCompletion: nullptr);
}

