
// ========================================================================
// ??0idTraceModelRecycler@@QAA@XZ
// EA  : 0x82B51948
// RVA : 0x00B51948
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.h
// ========================================================================

idTraceModelRecycler *__fastcall idTraceModelRecycler::idTraceModelRecycler(idTraceModelRecycler *this)
{
  this->allocator.blocks = nullptr;
  this->allocator.free = nullptr;
  this->allocator.total = 0;
  this->allocator.active = 0;
  this->allocator.allowAllocs = true;
  this->allocator.clearAllocs = false;
  this->allocated.list = nullptr;
  this->allocated.granularity = 0;
  this->allocated.memTag = 13;
  this->allocated.listStatic = 0;
  this->allocated.size = 0;
  this->allocated.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->allocated);
  `eh vector constructor iterator'(
    ptr: this->free,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idList<idRecycledTraceModel *,13>::idList<idRecycledTraceModel *,13>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  return this;
}


// ========================================================================
// __unwind$500980
// EA  : 0x82B519E8
// RVA : 0x00B519E8
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.h
// ========================================================================

void _unwind_500980()
{
  int v0; // r12

  idBlockAlloc<idRecycledTraceModel,64,13>::~idBlockAlloc<idRecycledTraceModel,64,13>(this: *(idBlockAlloc<idMD6LeafPlay,32,18> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$500981
// EA  : 0x82B51A10
// RVA : 0x00B51A10
// PDB : w:\tech5\engine\gamelib\physics\tracemodelrecycler.h
// ========================================================================

void _unwind_500981()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}

