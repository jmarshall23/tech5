
// ========================================================================
// ??1idTypeInfoTree@@QAA@XZ
// EA  : 0x825CB488
// RVA : 0x005CB488
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.h
// ========================================================================

void __fastcall idTypeInfoTree::~idTypeInfoTree(idTypeInfoTree *this)
{
  idTypeInfoTree::Clear(this);
  idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this: &this->nodeBlockAlloc);
}


// ========================================================================
// __unwind$242485
// EA  : 0x825CB4CC
// RVA : 0x005CB4CC
// PDB : w:\tech5\shared\idlib\typeinfo\typeinfotree.h
// ========================================================================

void _unwind_242485()
{
  int v0; // r12

  idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(this: (idBlockAlloc<idTypeInfoNode,32,114> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}

