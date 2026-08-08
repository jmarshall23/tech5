
// ========================================================================
// ?Release@idSWFScriptObject@@QAAXXZ
// EA  : 0x8256F940
// RVA : 0x0056F940
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.h
// ========================================================================

void __fastcall idSWFScriptObject::Release(idSWFScriptObject *this)
{
  if ( this->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this);
    idMem::Free(this: &mem, ptr: this, align: ALIGN_16);
  }
}


// ========================================================================
// ?Alloc@idSWFScriptObject@@SAPAV1@XZ
// EA  : 0x82776388
// RVA : 0x00776388
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.h
// ========================================================================

idSWFScriptObject *__fastcall idSWFScriptObject::Alloc()
{
  idSWFScriptObject *v0; // r3

  v0 = (idSWFScriptObject *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x60u,
                              tag: TAG_SWF,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    return idSWFScriptObject::idSWFScriptObject(this: v0);
  else
    return nullptr;
}


// ========================================================================
// __unwind$224608
// EA  : 0x827763F0
// RVA : 0x007763F0
// PDB : w:\tech5\engine\guis\swf\swf_scriptobject.h
// ========================================================================

void _unwind_224608()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_SWF);
}

