
// ========================================================================
// ??1idScopedGlobalHeap@@QAA@XZ
// EA  : 0x824E0650
// RVA : 0x004E0650
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.h
// ========================================================================

void __fastcall idScopedGlobalHeap::~idScopedGlobalHeap(idScopedGlobalHeap *this)
{
  idMem::PopHeap(this: &mem);
}

