
// ========================================================================
// ??1idMD6BlockAlloc@@UAA@XZ
// EA  : 0x826F36C8
// RVA : 0x006F36C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void __fastcall idMD6BlockAlloc::~idMD6BlockAlloc(idMD6BlockAlloc *this)
{
  this->__vftable = (idMD6BlockAlloc_vtbl *)&idMD6BlockAlloc::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodesToDelete);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  idBlockAlloc<idMD6TagFilter,16,18>::Shutdown(this: &this->tagFilters);
  idBlockAlloc<idSWFSpriteInstance,16,72>::Shutdown(this: &this->bestLeaves);
  idBlockAlloc<idMD6FusionBranch,16,18>::Shutdown(this: &this->fusionBranches);
  idBlockAlloc<idSWFSpriteInstance,16,72>::Shutdown(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)&this->blendAdditiveBranches);
  idBlockAlloc<idMD6BlendBranch,16,18>::Shutdown(this: &this->blendBranches);
  idBlockAlloc<idMD6Branch,16,18>::Shutdown(this: &this->branches);
  idBlockAlloc<idMD6LeafPause,4,18>::Shutdown(this: &this->pauseLeaves);
  idBlockAlloc<idMD6LeafPlay,32,18>::Shutdown(this: &this->playLeaves);
  this->__vftable = (idMD6BlockAlloc_vtbl *)&idMD6Allocator::`vftable';
}


// ========================================================================
// __unwind$249795
// EA  : 0x826F3768
// RVA : 0x006F3768
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249795()
{
  int v0; // r12

  idMD6Allocator::~idMD6Allocator(this: *(idMD6Allocator **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$249796
// EA  : 0x826F3790
// RVA : 0x006F3790
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249796()
{
  int v0; // r12

  idBlockAlloc<idRecycledTraceModel,64,13>::~idBlockAlloc<idRecycledTraceModel,64,13>(this: (idBlockAlloc<idMD6LeafPlay,32,18> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$249797
// EA  : 0x826F37BC
// RVA : 0x006F37BC
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249797()
{
  int v0; // r12

  idBlockAlloc<idMD6LeafPause,4,18>::~idBlockAlloc<idMD6LeafPause,4,18>(this: (idBlockAlloc<idMD6LeafPause,4,18> *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// __unwind$249798
// EA  : 0x826F37E8
// RVA : 0x006F37E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249798()
{
  int v0; // r12

  idBlockAlloc<idMD6Branch,16,18>::~idBlockAlloc<idMD6Branch,16,18>(this: (idBlockAlloc<idMD6Branch,16,18> *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// __unwind$249799
// EA  : 0x826F3814
// RVA : 0x006F3814
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249799()
{
  int v0; // r12

  idBlockAlloc<idMD6BlendBranch,16,18>::~idBlockAlloc<idMD6BlendBranch,16,18>(this: (idBlockAlloc<idMD6BlendBranch,16,18> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$249800
// EA  : 0x826F3840
// RVA : 0x006F3840
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249800()
{
  int v0; // r12

  idBlockAlloc<idMD6BestLeaf,16,18>::~idBlockAlloc<idMD6BestLeaf,16,18>(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// __unwind$249801
// EA  : 0x826F386C
// RVA : 0x006F386C
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249801()
{
  int v0; // r12

  idBlockAlloc<idMD6FusionBranch,16,18>::~idBlockAlloc<idMD6FusionBranch,16,18>(this: (idBlockAlloc<idMD6FusionBranch,16,18> *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// __unwind$249802
// EA  : 0x826F3898
// RVA : 0x006F3898
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249802()
{
  int v0; // r12

  idBlockAlloc<idMD6BestLeaf,16,18>::~idBlockAlloc<idMD6BestLeaf,16,18>(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)(*(_DWORD *)(v0 - 112 + 132) + 124));
}


// ========================================================================
// __unwind$249803
// EA  : 0x826F38C4
// RVA : 0x006F38C4
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249803()
{
  int v0; // r12

  idBlockAlloc<idMD6TagFilter,16,18>::~idBlockAlloc<idMD6TagFilter,16,18>(this: (idBlockAlloc<idMD6TagFilter,16,18> *)(*(_DWORD *)(v0 - 112 + 132) + 144));
}


// ========================================================================
// __unwind$249804
// EA  : 0x826F38F0
// RVA : 0x006F38F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

void _unwind_249804()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// ?NodeForIndex@idMD6BlockAlloc@@UBAPBVidMD6Node@@H@Z
// EA  : 0x826F3920
// RVA : 0x006F3920
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// ========================================================================

idMD6Node *__fastcall idMD6BlockAlloc::NodeForIndex(idMD6BlockAlloc *this, const int index)
{
  return this->nodes.list[index];
}

