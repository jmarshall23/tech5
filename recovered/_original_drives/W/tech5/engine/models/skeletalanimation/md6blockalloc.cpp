
// ========================================================================
// ?Size@idMD6BlockAlloc@@UBAIXZ
// EA  : 0x82842F30
// RVA : 0x00842F30
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

int __fastcall idMD6BlockAlloc::Size(idMD6BlockAlloc *this)
{
  return 40 * (2 * this->pauseLeaves.total + this->branches.total)
       + 172 * this->fusionBranches.total
       + 156 * this->blendBranches.total
       + 92 * this->bestLeaves.total
       + 84 * this->blendAdditiveBranches.total
       + 16 * this->tagFilters.total
       + 24 * this->playLeaves.total
       + 436;
}


// ========================================================================
// ??0idMD6BlockAlloc@@QAA@XZ
// EA  : 0x82843010
// RVA : 0x00843010
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

idMD6BlockAlloc *__fastcall idMD6BlockAlloc::idMD6BlockAlloc(idMD6BlockAlloc *this)
{
  this->__vftable = (idMD6BlockAlloc_vtbl *)&idMD6BlockAlloc::`vftable';
  this->playLeaves.blocks = nullptr;
  this->playLeaves.free = nullptr;
  this->playLeaves.total = 0;
  this->playLeaves.active = 0;
  this->playLeaves.allowAllocs = true;
  this->playLeaves.clearAllocs = false;
  this->pauseLeaves.blocks = nullptr;
  this->pauseLeaves.free = nullptr;
  this->pauseLeaves.total = 0;
  this->pauseLeaves.active = 0;
  this->pauseLeaves.allowAllocs = true;
  this->pauseLeaves.clearAllocs = false;
  this->branches.blocks = nullptr;
  this->branches.free = nullptr;
  this->branches.total = 0;
  this->branches.active = 0;
  this->branches.allowAllocs = true;
  this->branches.clearAllocs = false;
  this->blendBranches.blocks = nullptr;
  this->blendBranches.free = nullptr;
  this->blendBranches.total = 0;
  this->blendBranches.active = 0;
  this->blendBranches.allowAllocs = true;
  this->blendBranches.clearAllocs = false;
  this->blendAdditiveBranches.blocks = nullptr;
  this->blendAdditiveBranches.free = nullptr;
  this->blendAdditiveBranches.total = 0;
  this->blendAdditiveBranches.active = 0;
  this->blendAdditiveBranches.allowAllocs = true;
  this->blendAdditiveBranches.clearAllocs = false;
  this->fusionBranches.blocks = nullptr;
  this->fusionBranches.free = nullptr;
  this->fusionBranches.total = 0;
  this->fusionBranches.active = 0;
  this->fusionBranches.allowAllocs = true;
  this->fusionBranches.clearAllocs = false;
  this->bestLeaves.blocks = nullptr;
  this->bestLeaves.free = nullptr;
  this->bestLeaves.total = 0;
  this->bestLeaves.active = 0;
  this->bestLeaves.allowAllocs = true;
  this->bestLeaves.clearAllocs = false;
  this->tagFilters.blocks = nullptr;
  this->tagFilters.free = nullptr;
  this->tagFilters.total = 0;
  this->tagFilters.active = 0;
  this->tagFilters.allowAllocs = true;
  this->tagFilters.clearAllocs = false;
  this->nodes.list = nullptr;
  this->nodes.granularity = 0;
  this->nodes.memTag = 18;
  this->nodes.listStatic = 0;
  this->nodes.size = 0;
  this->nodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodes);
  this->nodesToDelete.list = nullptr;
  this->nodesToDelete.granularity = 0;
  this->nodesToDelete.memTag = 18;
  this->nodesToDelete.listStatic = 0;
  this->nodesToDelete.size = 0;
  this->nodesToDelete.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nodesToDelete);
  return this;
}


// ========================================================================
// __unwind$221088
// EA  : 0x8284318C
// RVA : 0x0084318C
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221088()
{
  int v0; // r12

  idMD6Allocator::~idMD6Allocator(this: *(idMD6Allocator **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$221089
// EA  : 0x828431B4
// RVA : 0x008431B4
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221089()
{
  int v0; // r12

  idBlockAlloc<idRecycledTraceModel,64,13>::~idBlockAlloc<idRecycledTraceModel,64,13>(this: (idBlockAlloc<idMD6LeafPlay,32,18> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$221090
// EA  : 0x828431E0
// RVA : 0x008431E0
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221090()
{
  int v0; // r12

  idBlockAlloc<idMD6LeafPause,4,18>::~idBlockAlloc<idMD6LeafPause,4,18>(this: (idBlockAlloc<idMD6LeafPause,4,18> *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// __unwind$221091
// EA  : 0x8284320C
// RVA : 0x0084320C
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221091()
{
  int v0; // r12

  idBlockAlloc<idMD6Branch,16,18>::~idBlockAlloc<idMD6Branch,16,18>(this: (idBlockAlloc<idMD6Branch,16,18> *)(*(_DWORD *)(v0 - 128 + 148) + 44));
}


// ========================================================================
// __unwind$221092
// EA  : 0x82843238
// RVA : 0x00843238
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221092()
{
  int v0; // r12

  idBlockAlloc<idMD6BlendBranch,16,18>::~idBlockAlloc<idMD6BlendBranch,16,18>(this: (idBlockAlloc<idMD6BlendBranch,16,18> *)(*(_DWORD *)(v0 - 128 + 148) + 64));
}


// ========================================================================
// __unwind$221093_0
// EA  : 0x82843264
// RVA : 0x00843264
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221093_0()
{
  int v0; // r12

  idBlockAlloc<idMD6BestLeaf,16,18>::~idBlockAlloc<idMD6BestLeaf,16,18>(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)(*(_DWORD *)(v0 - 128 + 148) + 84));
}


// ========================================================================
// __unwind$221094
// EA  : 0x82843290
// RVA : 0x00843290
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221094()
{
  int v0; // r12

  idBlockAlloc<idMD6FusionBranch,16,18>::~idBlockAlloc<idMD6FusionBranch,16,18>(this: (idBlockAlloc<idMD6FusionBranch,16,18> *)(*(_DWORD *)(v0 - 128 + 148) + 104));
}


// ========================================================================
// __unwind$221095
// EA  : 0x828432BC
// RVA : 0x008432BC
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221095()
{
  int v0; // r12

  idBlockAlloc<idMD6BestLeaf,16,18>::~idBlockAlloc<idMD6BestLeaf,16,18>(this: (idBlockAlloc<idMD6BestLeaf,16,18> *)(*(_DWORD *)(v0 - 128 + 148) + 124));
}


// ========================================================================
// __unwind$221096
// EA  : 0x828432E8
// RVA : 0x008432E8
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221096()
{
  int v0; // r12

  idBlockAlloc<idMD6TagFilter,16,18>::~idBlockAlloc<idMD6TagFilter,16,18>(this: (idBlockAlloc<idMD6TagFilter,16,18> *)(*(_DWORD *)(v0 - 128 + 148) + 144));
}


// ========================================================================
// __unwind$221097
// EA  : 0x82843314
// RVA : 0x00843314
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void _unwind_221097()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// ?Free@idMD6BlockAlloc@@UAAXPAVidMD6Node@@@Z
// EA  : 0x828433F0
// RVA : 0x008433F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void __fastcall idMD6BlockAlloc::Free(
        idMD6BlockAlloc *this,
        idMD6Node *node,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idMD6Node *a14)
{
  idList<idEntityPtr<idEntity>,58> *p_nodes; // r3
  int v16; // r10
  int num; // r9
  int v18; // r11
  bool i; // r3

  a14 = node;
  v16 = 0;
  num = this->nodes.num;
  p_nodes = (idList<idEntityPtr<idEntity>,58> *)&this->nodes;
  if ( num > 0 )
  {
    v18 = 0;
    do
    {
      if ( (idMD6Node *)p_nodes->list[v18].spawnId.value == node )
        goto _LN19;
      ++v16;
      ++v18;
    }
    while ( v16 < num );
  }
LABEL_5:
  for ( i = false; !i; i = idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_nodes, index: v16) )
  {
    idLib::FatalError(fmt: "idMD6BlockAlloc::Free: remove failed");
_LN19:
    if ( v16 < 0 )
      goto LABEL_5;
  }
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->nodesToDelete,
    obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?Condense@idMD6BlockAlloc@@UAAXXZ
// EA  : 0x82843490
// RVA : 0x00843490
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void __fastcall idMD6BlockAlloc::Condense(idMD6BlockAlloc *this)
{
  idList<idNavSpline *,5>::Resize(
    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->nodes,
    newsize: this->nodes.num);
}


// ========================================================================
// ?Alloc@idMD6BlockAlloc@@UAAPAVidMD6Node@@W4nodeType_t@2@@Z
// EA  : 0x82843910
// RVA : 0x00843910
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

idMD6Node *__fastcall idMD6BlockAlloc::Alloc(idMD6BlockAlloc *this, unsigned int type)
{
  void *v2; // r31
  void *v4; // r3
  void *v6; // [sp+50h] [-20h] BYREF

  v2 = nullptr;
  v6 = nullptr;
  if ( type <= 7 )
  {
    switch ( type )
    {
      case 1u:
        v4 = idBlockAlloc<idMD6LeafPause,4,18>::Alloc(this: &this->pauseLeaves);
        break;
      case 2u:
        v4 = idBlockAlloc<idMD6LeafPlay,32,18>::Alloc(this: &this->playLeaves);
        break;
      case 3u:
        v4 = idBlockAlloc<idMD6BlendBranch,16,18>::Alloc(this: &this->blendBranches);
        break;
      case 4u:
        v4 = idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::Alloc(this: &this->blendAdditiveBranches);
        break;
      case 5u:
        v4 = idBlockAlloc<idMD6FusionBranch,16,18>::Alloc(this: &this->fusionBranches);
        break;
      case 6u:
        v4 = idBlockAlloc<idMD6BestLeaf,16,18>::Alloc(this: &this->bestLeaves);
        break;
      default:
        if ( type != 0 )
          v4 = idBlockAlloc<idMD6TagFilter,16,18>::Alloc(this: &this->tagFilters);
        else
          v4 = idBlockAlloc<idMD6Branch,16,18>::Alloc(this: &this->branches);
        break;
    }
    v2 = v4;
    v6 = v4;
  }
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->nodes,
    obj: (const encounterGroupRole_t *)&v6);
  return (idMD6Node *)v2;
}


// ========================================================================
// ?DeferredFree@idMD6BlockAlloc@@QAAXXZ
// EA  : 0x82843AA8
// RVA : 0x00843AA8
// PDB : w:\tech5\engine\models\skeletalanimation\md6blockalloc.cpp
// ========================================================================

void __fastcall idMD6BlockAlloc::DeferredFree(idMD6BlockAlloc *this)
{
  int v2; // r30
  int num; // r29
  idMD6LeafPause *v4; // r4
  unsigned int type; // r11
  int v6; // r9
  int v7; // r9
  int v8; // r9
  idList<idMD6Node *,18> *p_nodesToDelete; // r31

  if ( this->nodesToDelete.num > 0 )
  {
    v2 = 0;
    num = this->nodesToDelete.num;
    do
    {
      v4 = (idMD6LeafPause *)this->nodesToDelete.list[v2];
      type = v4->type;
      if ( type <= 7 )
      {
        if ( type == 1 )
        {
          idBlockAlloc<idMD6LeafPause,4,18>::Free(this: &this->pauseLeaves, t: v4);
        }
        else if ( type == 2 )
        {
          *(_DWORD *)&v4->type = this->playLeaves.free;
          v7 = this->playLeaves.active - 1;
          this->playLeaves.free = (idBlockAlloc<idMD6LeafPlay,32,18>::element_t *)v4;
          this->playLeaves.active = v7;
        }
        else if ( type == 3 && v4->type != 0 )
        {
          idBlockAlloc<idMD6BlendBranch,16,18>::Free(this: &this->blendBranches, t: (idMD6BlendBranch *)v4);
        }
        else if ( type == 4 && v4->type != 0 )
        {
          idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::Free(this: &this->blendAdditiveBranches, t: (idSWFText *)v4);
        }
        else if ( type == 5 && v4->type != 0 )
        {
          idBlockAlloc<idMD6FusionBranch,16,18>::Free(this: &this->fusionBranches, t: (idMD6FusionBranch *)v4);
        }
        else if ( type == 6 && v4->type != 0 )
        {
          idBlockAlloc<idMD6BestLeaf,16,18>::Free(this: &this->bestLeaves, t: (idMD6BestLeaf *)v4);
        }
        else if ( v4->type != 0 )
        {
          *(_DWORD *)&v4->type = this->tagFilters.free;
          v8 = this->tagFilters.active - 1;
          this->tagFilters.free = (idBlockAlloc<idMD6TagFilter,16,18>::element_t *)v4;
          this->tagFilters.active = v8;
        }
        else
        {
          *(_DWORD *)&v4->type = this->branches.free;
          v6 = this->branches.active - 1;
          this->branches.free = (idBlockAlloc<idMD6Branch,16,18>::element_t *)v4;
          this->branches.active = v6;
        }
      }
      --num;
      ++v2;
    }
    while ( num != 0 );
  }
  p_nodesToDelete = &this->nodesToDelete;
  if ( p_nodesToDelete->size < 0 )
  {
    if ( p_nodesToDelete->listStatic == 0 || p_nodesToDelete->listStatic == 2 )
    {
      if ( p_nodesToDelete->list != nullptr )
        idMem::Free(this: &mem, ptr: p_nodesToDelete->list, align: ALIGN_16);
      p_nodesToDelete->list = nullptr;
      p_nodesToDelete->size = 0;
    }
    p_nodesToDelete->num = 0;
  }
  p_nodesToDelete->num = __CFADD__(-p_nodesToDelete->size, p_nodesToDelete->size ^ 0x80000000)
                       ? 0
                       : p_nodesToDelete->size;
}

